/* loads brecs parameters from a database */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "Brecs.h"

#include "sqlite3.h"

#define LOG(msg) printf("%s(%d): %s()\n\t%s\n",__FILE__,__LINE__,__FUNCTION__,msg)
#define LOG2(msg1,msg2) printf("%s(%d): %s()\n\t%s\n\t%s\n",__FILE__,__LINE__,__FUNCTION__,msg1,msg2)
#define HERE LOG("HERE");
#define SQLITE_ERR(e) do{ int ecode_=(e); if(ecode_!=SQLITE_OK){LOG2(sqlite3_errstr(ecode_),sqlite3_errmsg(db)); goto Error;}}while(0)
#define SQLITE_SILENT_ERR(e) do{if((e)!=SQLITE_OK){goto Error;}}while(0)
#define ERR(e)        do{ if(!(e)){LOG2("Expression evaluated as false.",#e); goto Error;}}while(0)

#if 0
#define DBG(...) printf(__VA_ARGS__)
#else
#define DBG(...)
#endif

#ifdef WIN32
#pragma warning (disable:4996)  /* use of snprintf causes a security warning */
#define snprintf _snprintf
#endif

#define countof(e) (sizeof(e)/sizeof(*(e)))

static struct column_mapping{
    const char *name; /* sql column name */
    const char *type; /* sql type used on table creation */
    const char *def;  /* string to use to set default value in table */
    unsigned    o;    /* byte offset of corresponding field in params struct */
    unsigned    read; /* a flag that marks the column as read: used for validation */
} column_mapping[] = {
      {"pixmean",      "REAL",   "500",  offsetof(struct params,pixmean),      0}
     ,{"pixstd",       "REAL",   "200",  offsetof(struct params,pixstd),       0}
     ,{"rho",          "REAL",   "0.001",offsetof(struct params,rho),          0}
     ,{"kersize",      "INTEGER","8",    offsetof(struct params,kersize),      0}
     ,{"kersizez",     "INTEGER","1",    offsetof(struct params,kersizez),     0}
     ,{"pixsdiv",      "INTEGER","8",    offsetof(struct params,pixsdiv),      0}
     ,{"pixsdivz",     "INTEGER","1",    offsetof(struct params,pixsdivz),     0}
     ,{"spixnm",       "REAL",   "133.0",offsetof(struct params,spixnm),       0}
     ,{"spixznm",      "REAL",   "300.0",offsetof(struct params,spixznm),      0}
     ,{"mesoffset",    "REAL",   "80",   offsetof(struct params,mesoffset),    0}
     ,{"mesampli",     "REAL",   "20",   offsetof(struct params,mesampli),     0}
     ,{"noiseoffset",  "REAL",   "1",    offsetof(struct params,noiseoffset),  0}
     ,{"nbiter",       "INTEGER","200",  offsetof(struct params,nbiter),       0}
     ,{"prefacradcc",  "REAL",   "1.0",  offsetof(struct params,prefacradcc),  0}
     ,{"convolpixthr", "REAL",   "40.0", offsetof(struct params,convolpixthr), 0}
     ,{"ainitpfact",   "REAL",   "1.0",  offsetof(struct params,ainitpfact),   0}
     ,{"meanback",     "REAL",   "0",    offsetof(struct params,meanback),     0}
     ,{"locaintensthr","REAL",   "1000", offsetof(struct params,locaintensthr),0}
     ,{"overlaymaxint","REAL",   "50.4", offsetof(struct params,overlaymaxint),0}
     ,{"overlayminint","REAL",   "0.1",  offsetof(struct params,overlayminint),0}
     ,{"relerrthr",    "REAL",   "0.001",offsetof(struct params,relerrthr),    0}
     ,{"nbinternloop", "REAL",   "1",    offsetof(struct params,nbinternloop), 0}
     ,{"damp1",        "REAL",   "0.05", offsetof(struct params,damp1),        0}
     ,{"damp2",        "REAL",   "0.1",  offsetof(struct params,damp2),        0}
};

static int findname(const char *key) {
    int i;
    for(i=0;i<countof(column_mapping);++i) {
        if(strcmp(key,column_mapping[i].name)==0)
            return i;
    }
    return -1;
}

static char* cat(char * dst,const char* src) {
    size_t n=strlen(src);
    memcpy(dst,src,n);
    return dst+n;
}

static int initdb(sqlite3 *db) {
    char *emsg=0;
    char sql[4096]={0},*c; /* make bigger as necessary */
    int isok=0;
    int i;
    /* transaction will only go through if parameters table doesn't exist yet. */
    c=cat(sql,"create table `parameters` (\n");
    c=cat(c,"\t`dataset` INTEGER not null primary key autoincrement unique,\n");
    for(i=0;i<countof(column_mapping);++i){
        char buf[256]={0};
        const struct column_mapping *co=&column_mapping[i];
        snprintf(buf,sizeof(buf),"\t`%s` %s default %s,\n",co->name,co->type,co->def);
        c=cat(c,buf);
    }    
    c-=2; /* erase the last comma and new line by backing up over them */
    c=cat(c,");\n");
    c=cat(c,"insert into `parameters` default values;\n");
    c=cat(c,"create table `datasets` (`dataset` INTEGER primary key autoincrement unique,`description` TEXT);");
    c=cat(c,"insert into `datasets` values (1,\"Default values\");\n");
    SQLITE_SILENT_ERR(sqlite3_exec(db,sql,0,0,&emsg));
    isok=1;
Finalize:
    return 1;
Error:
    isok=0;
    sqlite3_free(emsg);
    goto Finalize;
}

int initialize_params_file(const char* filename) {
    int isok=0;
    sqlite3 *db=0;
    SQLITE_ERR(sqlite3_open(filename,&db));
    isok=initdb(db);
    sqlite3_close(db);
    return isok;
Error:
    sqlite3_close(db);
    return 0;
}

struct params read_params(const char* filename,int dataset){
    struct params params={0};
    sqlite3 *db=0;
    sqlite3_stmt *stmt=0;
    int ecode=0;
    int i;

    DBG("###############\n");
    SQLITE_ERR(sqlite3_open(filename,&db));
    initdb(db);
    if(dataset>=0){
        char sql[1024]={0};
        snprintf(sql,sizeof(sql),"select * from parameters where dataset=%d limit 1",dataset);
        SQLITE_ERR(sqlite3_prepare_v2(db,"select * from parameters limit 1;",-1,&stmt,0));
    } else
        SQLITE_ERR(sqlite3_prepare_v2(db,"select * from parameters limit 1;",-1,&stmt,0));
    while((ecode=sqlite3_step(stmt))==SQLITE_ROW) {
        for(i=1;i<sqlite3_column_count(stmt);++i) { /* assume the first column is the primary key, and skip it */
            int j;
            const char *name=sqlite3_column_name(stmt,i);
            ERR((j=findname(name))>=0);
            column_mapping[j].read=1;
            switch(sqlite3_column_type(stmt,i)) {
                case SQLITE_INTEGER:
                    *(int*)(((char*)&params)+column_mapping[j].o)=sqlite3_column_int(stmt,i);
                    break;
                case SQLITE_FLOAT:
                    *(float*)(((char*)&params)+column_mapping[j].o)=(float)sqlite3_column_double(stmt,i);
                    break;
                default:
                    LOG("Unexpected column type.\n"); 
                    goto Error;
            }
            DBG("%s is %f\n",sqlite3_column_name(stmt,i),sqlite3_column_double(stmt,i));
        }
    }
    if(ecode!=SQLITE_DONE)
        SQLITE_ERR(ecode);

    /* compute dependant parameters */
    params.kersize2 = params.kersize * params.kersize;
    params.kersize3 = params.kersize * params.kersize * params.kersizez;
    params.pixsdiv2 = params.pixsdiv * params.pixsdiv;
    params.pixsdiv3 = params.pixsdiv * params.pixsdiv * params.pixsdivz;

    params.Ainit = params.ainitpfact / (params.pixmean * params.pixmean);

    /* check that all required parameters were found */    
    params.isok=1;
    for(i=0;i<countof(column_mapping);++i) if(column_mapping[i].read==0)
        params.isok=0;
    
Finalize:
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    DBG("###############\n");
    return params;
Error:
    params.isok=0;
    goto Finalize;
}

/* NOTES

 - Evolving parameter schemes

   To maintain backwards compatibility as the application evolves, it might be neccessary to support
   multiple types of parameter sets in the database at the same time.  If that happens, I'd recommend
   adding a table for each parameter set schema (parameters_v0,parameters_v1, etc...) and then use the
   datasets table to record which parameter table to use.
*/
