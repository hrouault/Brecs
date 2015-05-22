/**
 * option parsing
 *
 * Scroll down to the SPEC and SPEC IMPLEMENTATION to specialize for your application.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/stat.h>
#include "cmdline.h"

#define MAXWIDTH (78)

#define countof(e)        (sizeof(e)/sizeof(*(e)))
#define PRINT(...)        printf(__VA_ARGS__)
#define LOG(...)          reporter(__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__)
#define REPORT(msg1,msg2) LOG("\t%s\n\t%s\n",msg1,msg2)
#define TRY(e)            do{if(!(e)){REPORT(#e,"Expression evaluated as false"); goto Error;}}while(0)

#ifdef _MSC_VER
  #include <malloc.h>
  #define alloca      _alloca
  #define snprintf    _snprintf
  #define PATHSEP    '\\'
  #define S_ISDIR(B) ((B)&_S_IFDIR)
  #undef max
#else
  #include <alloca.h>
  #define PATHSEP '/'
#endif

//-- TYPES --------------------------------------------------------------------- 
typedef int  (*validator_t)(const char* s);
typedef int  (*parse_t)    (struct gengetopt_args_info* ctx,const char* s);
typedef void (*callback_t) (struct gengetopt_args_info* ctx);

struct opt_state_t
{ int is_found;
  char buf[64];
};

typedef struct _opt_t
{ validator_t validate; // ensure string value passed for an option is valid
  parse_t     parse;    // assign value based on string
  callback_t  callback; // mostly used to set/respond to a flag
  int         is_flag;  // an option that takes no arguments
  const char* shortname;
  const char* longname;
  const char* def;      // default value, or NULL.
  const char* help;     // descriptive text
  struct opt_state_t state; // always set to {0}
} opt_t;

typedef struct _arg_t
{ validator_t validate;
  parse_t     parse;
  callback_t  callback;
  const char *name;
  const char *help;
  struct opt_state_t state;
} arg_t;

//-- SPEC ----------------------------------------------------------------------
static void help(struct gengetopt_args_info *opts);
static int  validate_path(const char* s);
static int  is_positive_int(const char* s);
static int  validate_optional_path(const char* s);

//static int  frame(struct gengetopt_args_info *ctx,const char *s);
static int  filename(struct gengetopt_args_info *ctx,const char *s);
static int  psf(struct gengetopt_args_info *ctx,const char *s);
static int  background(struct gengetopt_args_info *ctx,const char *s);
static int  output(struct gengetopt_args_info *ctx,const char *s);

static int    ARGC;
static char** ARGV;
static opt_t SPEC[]=
{ 
  {NULL,                  NULL,      help,1,"-h","--help",      NULL,"Display this help message.",{0}},
  {validate_path,         filename,  NULL,0,"-f","--filename",  NULL,"Filename of the image",{ 0 } },
  {validate_path,         psf,       NULL,0,"--psf","",         NULL,"PSF image in tiff format",{ 0 } },
  {validate_optional_path,background,NULL,0,"--background","",  NULL,"background image in raw format",{ 0 } },
  {validate_optional_path,output,    NULL,0,"-o","--output",    NULL,"Tiff output image",{ 0 } },

//{ is_positive_int,frame,NULL,"-n","--frame",0,"Picture number in the file (for raw images)",{ 0 } },

};

#ifdef USE_ARGS // define USE_ARGS if you want to use position based arguments.
static arg_t ARGS[]= // position based arguments
{0};
#endif

//-- SPEC IMPLEMENTATION -------------------------------------------------------

/** path must exist */
static int validate_path(const char *path)
{ struct stat s={0};
  if (!path) return 0;
  if(stat(path,&s)<0) return 0;
  return S_ISDIR(s.st_mode);
}

static int validate_optional_path(const char* s)
{ if(s) return validate_path(s);
  return 1; // NULL is ok
}

static int is_positive_int(const char* s)
{ char *end=0;
  long v=strtol(s,&end,10);
  if(*s!='\0' && *end=='\0' && v>=0 )
    return 1;
  return 0;
}

// static int  frame(struct gengetopt_args_info *ctx, const char *s)
static int  filename(struct gengetopt_args_info *ctx, const char *s) { ctx->filename_arg = (char*)s; return 1; }
static int  psf(struct gengetopt_args_info *ctx, const char *s) { ctx->psf_arg = (char*)s; return 1; }
static int  background(struct gengetopt_args_info *ctx, const char *s) { ctx->background_arg= (char*)s; return 1; }
static int  output(struct gengetopt_args_info *ctx, const char *s) { ctx->output_arg = (char*)s; return 1; }

//-- HANDLING ------------------------------------------------------------------
// Given SPEC and ARGS, handling is pretty general.  Could split out to an API


static char *basename(char* argv0)
{ char *r = strrchr(argv0,PATHSEP);
  return r?(r+1):argv0;
}

static void reporter(const char *file,int line,const char* function,const char*fmt,...)
{ va_list ap;
  fprintf(stdout,"At %s(%d) - %s()\n",file,line,function);
  va_start(ap,fmt);
  vfprintf(stdout,fmt,ap);
  va_end(ap);
}

/** Prints a two column output where the help string is wrapped in the second
    column. 
*/
static void writehelp(int maxwidth,const char* lhs,int width,const char* help)
{ 
  char helpbuf[1024]={0};
  int n,r=(int)strlen(help); // remainder of help text to write
  char t, // temp
      *s, // the line split point: last space in the current range or a newline
      *h=helpbuf; // current pos in help string
  memcpy(h,help,r);
  memset(h+r,0,countof(helpbuf)-r);

  n=maxwidth-width+4;
  t=h[n];
  s=h+r;
  if((h+n)<(helpbuf+r))    // test if the line needs to wrap
  { h[n]='\0';             // null the wrap point
    if((s=strchr(h,'\n'))||(s=strrchr(h,' '))) // split the help string at first newline or the last space
    { *s='\0';
      if(n<r) h[n]=t;
      t=' ';
    } else
    { s=h+n;
    }
  }
  PRINT("%-*s    %s\n",width,lhs,h);
  h=s;
  *s=t;
  while(*h==' ' && (h-helpbuf)<r) ++h; // advance through white space

  while((h-helpbuf)<r)
  {
    t=h[n];
    s=h+r;
    if((h+n)<(helpbuf+r))
    { h[n]='\0';
      if((s=strchr(h,'\n'))||(s=strrchr(h,' '))) // split the help string at first newline or the last space
      { *s='\0';
        if(n<r) h[n]=t;
        t=' ';
      } else
      { s=h+n;
      }
    }
    PRINT("%-*s    %s\n",width,"",h);
    h=s;
    *s=t;
    while(*h==' ' && (h-helpbuf)<r) ++h; // advance through white space
  }
}

static void usage()
{ int i,width=0;
  PRINT("Usage: %s [options]",basename(ARGV[0]));
#ifdef USE_ARGS
  for(i=0;i<countof(ARGS);++i)
    PRINT(" <%s>",ARGS[i].name);
  
  for(i=0;i<countof(ARGS);++i)
  { int c=0;
#define WRITE(...) c+=snprintf(ARGS[i].state.buf+c,sizeof(ARGS[i].state.buf)-c,__VA_ARGS__)
    WRITE("    %s",ARGS[i].name);
#undef WRITE
  }
#endif
  
  // left column of help text
  for(i=0;i<countof(SPEC);++i)
  { int c=0;
#define WRITE(...) c+=snprintf(SPEC[i].state.buf+c,sizeof(SPEC[i].state.buf)-c,__VA_ARGS__)
    WRITE("    %s",SPEC[i].shortname);
    if(SPEC[i].longname && strlen(SPEC[i].longname))
      WRITE(" [%s]",SPEC[i].longname);
    if(!SPEC[i].is_flag)
    { WRITE(" arg");
      if(SPEC[i].def)
        WRITE(" (=%s)",SPEC[i].def);
    }
#undef WRITE
  }
  // width of left column
#ifdef USE_ARGS
  for(i=0;i<countof(ARGS);++i)
  { int n=(int)strlen(ARGS[i].state.buf);
    width=(n>width)?n:width;
  }
#endif
  for(i=0;i<countof(SPEC);++i)
  { int n=(int)strlen(SPEC[i].state.buf);
    width=(n>width)?n:width;
  }

#ifdef USE_ARGS
  PRINT("\nArguments:\n");
  for(i=0;i<countof(ARGS);++i)
    writehelp(MAXWIDTH,ARGS[i].state.buf,width,ARGS[i].help);
#endif

  PRINT("\nOptions:\n");
  for(i=0;i<countof(SPEC);++i)
    writehelp(MAXWIDTH,SPEC[i].state.buf,width,SPEC[i].help);
  
  printf("\n");
}

static void help(struct gengetopt_args_info *opts)
{ usage(); exit(0); 
}

#define CALLBACK(iopt,opts)      if(SPEC[iopt].callback) SPEC[iopt].callback(opts)
#define VALIDATE(iopt,str)       (SPEC[iopt].validate==NULL || SPEC[iopt].validate(str))
#define PARSE(iopt,opts,str)     (SPEC[iopt].parse==NULL || SPEC[iopt].parse(opts,str))

#define SAME(a,b) ((b!=0)&&strcmp(a,b)==0)

int cmdline_parser(int argc, char** argv, struct gengetopt_args_info* opts)
{ int iarg,iopt,isok=0;
  unsigned char *hit=0;  // flags to indicate an argv was used in option processing
  TRY(argc && argv && opts);
  memset(opts, 0, sizeof(*opts));
  TRY(hit=(unsigned char*)alloca(argc));
  memset(hit,0,argc);
  ARGV=(char**)argv;
  ARGC=argc;
  for(iarg=1;iarg<argc;++iarg)
  { for(iopt=0;iopt<countof(SPEC);++iopt)
    { if( SAME(argv[iarg],SPEC[iopt].shortname)
        ||SAME(argv[iarg],SPEC[iopt].longname ))
      { CALLBACK(iopt,opts);
        hit[iarg]=1;
        if(!SPEC[iopt].is_flag)
        { if(iarg>=(argc-1))
          { LOG("\tAn argument was found but the value was not.\n\tOption \"%s\".\n",argv[iarg]);
            goto Error;
          }
          if(!VALIDATE(iopt,argv[iarg+1]))
          { LOG("\tArgument validation error.\n\tOption \"%s\" got \"%s\".\n",argv[iarg],argv[iarg+1]);
            goto Error;
          }
          if(!PARSE(iopt,opts,argv[iarg+1]))
          { LOG("\tArgument parse error.\n\tOption \"%s\" got \"%s\".\n",argv[iarg],argv[iarg+1]);
            goto Error;
          }
          SPEC[iopt].state.is_found=1;
          iarg++; // consumes an argument
          hit[iarg]=1;
        }
      }
    }
  }
  // apply default value for missing arguments
  for(iopt=0;iopt<countof(SPEC);++iopt)
  { if(!SPEC[iopt].is_flag && !SPEC[iopt].state.is_found)
    { if(!VALIDATE(iopt,SPEC[iopt].def))
      { LOG("\tDefault argument failed to validate.\n\tOption \"%s\" got \"%s\".\n",SPEC[iopt].shortname,SPEC[iopt].def);
        goto Error;
      }
      if(!PARSE(iopt,opts,SPEC[iopt].def))
      { LOG("\tDefault argument failed to parse.\n\tOption \"%s\" got \"%s\".\n",SPEC[iopt].shortname,SPEC[iopt].def);
        goto Error;
      }
    }
  }
  // fixed place argument handling and sections
#undef CALLBACK
#undef VALIDATE
#undef PARSE  
#define CALLBACK(iopt,opts)      if(ARGS[iopt].callback) ARGS[iopt].callback(&opts)
#define VALIDATE(iopt,str)       (ARGS[iopt].validate==NULL || ARGS[iopt].validate(str))
#define PARSE(iopt,opts,str)     (ARGS[iopt].parse==NULL || ARGS[iopt].parse(&opts,str))
#ifdef USE_ARGS
  for(iarg=1,iopt=0;(iarg<argc)&&(iopt<countof(ARGS));++iarg)
  { if(hit[iarg]) continue;
    if(!VALIDATE(iopt,argv[iarg]))
    { LOG("\tPositional argument validation error.\n\tOption <%s> got \"%s\".\n",ARGS[iopt].name,argv[iarg]);
      goto Error;
    }
    if(!PARSE(iopt,opts,argv[iarg]))
    { LOG("\tPositional argument parse error.\n\tOption <%s> got \"%s\".\n",ARGS[iopt].name,argv[iarg]);
      goto Error;
    }
    ARGS[iopt++].state.is_found=1;
  }

  // The specified fixed place args must be found
  // Not too worried about extra args
  for(iopt=0;iopt<countof(ARGS);++iopt)
  { if(!ARGS[iopt].state.is_found)
    { LOG("\tMissing required positional argument <%s>.\n",ARGS[iopt].name);
      goto Error;
    }
  }
#endif
  isok=1;
  return !isok;
Error:
  isok=0;
  usage();
  return !isok;
}
