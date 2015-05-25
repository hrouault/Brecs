#include <platform.h>
#include "error.h"
#include "cmdline.h"
#include "inoutimg.h"
#include "Brecs.h"
#include "parameter.io.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Alias parameters */
#define  kersize       (params.kersize)
#define  kersizez      (params.kersizez)
#define  pixsdiv3      (params.pixsdiv3)

/* Command line variable */
struct gengetopt_args_info brecs_args;

int main(int argc, char ** argv)
{
    struct images images={0};
    params=read_params("brecs_parameters.sqlite3",-1);

#ifdef __DEBUG__
    _MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() & ~_MM_MASK_INVALID
            & ~_MM_MASK_OVERFLOW & ~_MM_MASK_DIV_ZERO);
#endif

    /* Remove libtiff warnings */
    TIFFSetWarningHandler(NULL);

    /* Command line parser */
    char * arg0 = argv[0];
    arg0 = strrchr(arg0, '/');
    if (arg0)
        prog_name = arg0 + 1;
    else
        prog_name = argv[0];

    if (cmdline_parser(argc, argv, & brecs_args) != 0)
        exit(EXIT_FAILURE);

    int insx;
    int insy;
    int insz;

    images.img = opentiff(brecs_args.filename_arg, &insx, &insy, &insz);

    if (brecs_args.background_arg) {
        int binsx;
        int binsy;
        int binsz;
        images.imgback = opentiff_f(brecs_args.background_arg,
                             &binsx,
                             &binsy,
                             &binsz);
        if (binsx != insx || binsy != insy || binsz != insz) {
            brecs_error("img and background size do not match",
                        0,
                        prog_name);
        }
    }

    int sx,sy,sz;
    images.ker=opentiff_f(brecs_args.psf_arg,&sx,&sy,&sz);
    if(sx!=kersize||sy!=kersize * kersizez||sz!=pixsdiv3) {
        printf("invalid psf size: %d %d %d\n",sx,sy,sz);
        printf("should be: %d %d %d\n",kersize,kersize * kersizez,
               pixsdiv3);
        exit(EXIT_FAILURE);
    }

    brecs(images);

    if(brecs_args.output_arg) {
        writetiff_f(brecs_args.output_arg,
                    images.outsz.x,images.outsz.y,images.outsz.z,
                    images.reconspic);
    }
    
    return EXIT_SUCCESS;
}

