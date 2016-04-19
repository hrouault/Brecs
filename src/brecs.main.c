#include <platform.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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

    if (cmdline_parser(argc, argv, &brecs_args) != 0)
        exit(EXIT_FAILURE);

    images_t images;
    params_t par;
    read_params_txt(brecs_args.conf_arg, &par);

    size_t insx;
    size_t insy;
    size_t insz;

    images.img = opentiff(brecs_args.filename_arg, &insx, &insy, &insz);

    if (brecs_args.background_arg) {
        size_t binsx;
        size_t binsy;
        size_t binsz;
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
    size_t sx, sy, sz;
    images.ker = opentiff_f(brecs_args.psf_arg, &sx, &sy, &sz);
    int kersize = sx;
    par.kersize = kersize;
    int kersizez = sy / kersize;
    par.kersizez = kersizez;
    int pixsdivz = par.pixsdivz;
    int pixsdiv = sqrt(sz / pixsdivz);
    par.pixsdiv = pixsdiv;
    int pixsdiv2 = pixsdiv * pixsdiv;
    int pixsdiv3 = pixsdivz * pixsdiv2;
    if (sz != pixsdiv3) {
        printf("invalid number of frames in the psf file: %ld\n", sx);
        printf("should be: %d\n", pixsdiv3);
        exit(EXIT_FAILURE);
    }
    par.prefacradcc = 1.0;
    par.ainitpfact = 1.0;
    par.Ainit = par.ainitpfact / (par.pixmean * par.pixmean);
    par.overlaymaxint = par.pixmean;
    par.overlayminint = 1.0;
    par.relerrthr = 0.001;
    par.nbinternloop = 1;

    brecs(&images, &par);

    if (brecs_args.output_arg) {
        writetiff_f(brecs_args.output_arg,
                    images.outsize.x, images.outsize.y, images.outsize.z,
                    images.reconspic);
    }

    return EXIT_SUCCESS;
}
