#include <platform.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <tiffio.h>

#include "error.h"
#include "cmdline.h"
#include "inoutimg.h"
#include "Brecs.h"
#include "parameter.io.h"

extern struct gengetopt_args_info brecs_args;

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

    uint32_t insx;
    uint32_t insy;
    uint32_t insz;

    images.img = opentiff(brecs_args.filename_arg, &insx, &insy, &insz);

    if (brecs_args.background_arg) {
        uint32_t binsx;
        uint32_t binsy;
        uint32_t binsz;
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
    uint32_t sx, sy, sz;
    images.ker = opentiff_f(brecs_args.psf_arg, &sx, &sy, &sz);
    uint16_t kersize = (uint16_t)sx;
    par.kersize = kersize;
    uint16_t kersizez = (uint16_t)(sy / kersize);
    par.kersizez = kersizez;
    uint16_t pixsdivz = par.pixsdivz;
    uint16_t pixsdiv = (uint16_t)sqrtf(sz / pixsdivz);
    par.pixsdiv = pixsdiv;
    uint16_t pixsdiv2 = pixsdiv * pixsdiv;
    uint32_t pixsdiv3 = pixsdivz * pixsdiv2;
    if (sz != pixsdiv3) {
        printf("invalid number of frames in the psf file: %d\n", sx);
        printf("should be: %d\n", pixsdiv3);
        exit(EXIT_FAILURE);
    }
    par.prefacradcc = 1.0f;
    par.ainitpfact = 1.0f;
    par.Ainit = par.ainitpfact / (par.pixmean * par.pixmean);
    par.overlaymaxint = par.pixmean;
    par.overlayminint = 1.0f;
    par.relerrthr = 0.001f;
    par.nbinternloop = 1.0f;

    FILE* floca = NULL;
    if (brecs_args.localizations_arg) {
        floca = fopen(brecs_args.localizations_arg, "w");
        if (floca == NULL) {
            fprintf(stderr, "Cannot open file %s: %s\n",
                    brecs_args.localizations_arg, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    brecs(&images, &par, floca);

    if (brecs_args.localizations_arg) {
        fclose(floca);
    }

    if (brecs_args.output_arg) {
        writetiff_f(brecs_args.output_arg,
                    images.outsize.x, images.outsize.y, images.outsize.z,
                    images.reconspic);
    }

    return EXIT_SUCCESS;
}
