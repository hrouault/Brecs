#include <platform.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <tiffio.h>

#include "error.h"
#include "cmdline.h"
#include "inoutimg.h"
#include "Brecs.h"
#include "parameter.io.h"

/* Command line variable */
struct gengetopt_args_info brecs_args;

int main(int argc, char ** argv)
{
    images_t images;
    params_t * par = read_params("brecs_parameters.sqlite3", -1);
    int pixsdiv = par->pixsdiv;
    int pixsdivz = par->pixsdivz;
    int pixsdiv2 = pixsdiv * pixsdiv;
    int pixsdiv3 = pixsdivz * pixsdiv2;
    int kersize = par->kersize;
    int kersizez = par->kersizez;

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
    } else {
        images.imgback = NULL;
    }

    images.insize.x = insx;
    images.insize.y = insy;
    images.insize.z = insz;
    int sx, sy, sz;
    images.ker = opentiff_f(brecs_args.psf_arg, &sx, &sy, &sz);
    if (sx != kersize || sy != kersize * kersizez || sz != pixsdiv3) {
        printf("invalid psf size: %d %d %d\n",sx,sy,sz);
        printf("should be: %d %d %d\n",kersize,kersize * kersizez,
               pixsdiv3);
        exit(EXIT_FAILURE);
    }

    brecs(&images, par);

    if (brecs_args.output_arg) {
        writetiff_f(brecs_args.output_arg,
                    images.outsize.x, images.outsize.y, images.outsize.z,
                    images.reconspic);
    }

    return EXIT_SUCCESS;
}
