/* Copyright (c) , Herve Rouault <rouaulth@janelia.hhmi.org>,
 * Howard Hughes Medical Institute.
 * All rights reserved.
 * 
 * This file is part of Brecs.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Howard Hughes Medical Institute nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#define _XOPEN_SOURCE 600

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <tiffio.h>

#include <cpuid.h> /* __get_cpuid_max, __get_cpuid */
#include <mmintrin.h> /* MMX instrinsics  __m64 integer type  */
#include <xmmintrin.h> /* SSE  __m128  float */
#include <pmmintrin.h>
#include <immintrin.h>

#include <bzlib.h>

#include "config.h"

#ifdef __AVX__
#  define SHIFT 8
#  define ALIGNSIZE 32
#  define VFUNC(name) _mm256_ ## name
typedef __m256 vecfloat;
typedef float afloat __attribute__ ((__aligned__(32)));
#else
#  define SHIFT 4
#  define ALIGNSIZE 16
#  define VFUNC(name) _mm_ ## name
typedef __m128 vecfloat;
typedef float afloat __attribute__ ((__aligned__(16)));
#endif


/* Constant definitions */
#include "parameters.h"

const int GENDAT_SIZE2 = GENDAT_SIZEX * GENDAT_SIZEY;

void
create_3d_dataset()
{
    float * img0;
    float * img1;
    float * img2;

    posix_memalign((void **)&img0, ALIGNSIZE, GENDAT_SIZE2 * sizeof(float));
    posix_memalign((void **)&img1, ALIGNSIZE, GENDAT_SIZE2 * sizeof(float));
    posix_memalign((void **)&img2, ALIGNSIZE, GENDAT_SIZE2 * sizeof(float));

    for (unsigned int i = 0; i < GENDAT_SIZE2; ++i) {
        img0[i] = 0;
        img1[i] = 0;
        img2[i] = 0;
    }

    for (unsigned int i = 0; i < GENDAT_NBPOINTS; ++i) {
        int pos = drand48() * GENDAT_SIZEX * GENDAT_SIZEY * GENDAT_SIZEZ;
        int posz = pos / (GENDAT_SIZEX * GENDAT_SIZEY);
        int posxy = pos % (GENDAT_SIZEX * GENDAT_SIZEY);
        printf("%d %d\n", posz, posxy);

        double phase = posz / (double)GENDAT_SIZEZ;
        double img0_coef = 0.5 + 0.5 * cos(2 * M_PI * phase);
        double img1_coef = 0.5 + 0.5 * cos(2 * M_PI * (phase + 1.0 / 3));
        double img2_coef = 0.5 + 0.5 * cos(2 * M_PI * (phase + 2.0 / 3));

        float intens = 4000 + 1000 * drand48();

        img0[posxy] += intens * img0_coef / 20;
        img1[posxy] += intens * img1_coef / 20;
        img2[posxy] += intens * img2_coef / 20;
        printf("%f %f %f\n", img0[posxy], img1[posxy], img2[posxy]);
    }

    unsigned char * imgstack;
    posix_memalign((void **)&imgstack,
                   ALIGNSIZE,
                   GENDAT_SIZE2 * 3 * sizeof(unsigned char));

    for (unsigned int i = 0; i < GENDAT_SIZE2; ++i) {
        imgstack[3 * i] = img0[i];
        imgstack[3 * i + 1] = img1[i];
        imgstack[3 * i + 2] = img2[i];
    }

    TIFF * outf = TIFFOpen("origin3d.tif", "w");
    TIFFSetField(outf, TIFFTAG_IMAGEWIDTH, GENDAT_SIZEX);
    TIFFSetField(outf, TIFFTAG_IMAGELENGTH, GENDAT_SIZEY);
    TIFFSetField(outf, TIFFTAG_SAMPLESPERPIXEL, 3);
    TIFFSetField(outf, TIFFTAG_BITSPERSAMPLE, 8);
    TIFFSetField(outf, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    TIFFSetField(outf, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
    TIFFSetField(outf, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);

    TIFFSetField(outf,
                 TIFFTAG_ROWSPERSTRIP,
                 TIFFDefaultStripSize(outf, 3 * GENDAT_SIZEX));

    for (uint32 row = 0; row < GENDAT_SIZEY; row++) {
        if (TIFFWriteScanline(outf, imgstack + 3 * GENDAT_SIZEX * row, row, 0) < 0)
            break;
    }
    TIFFClose(outf);

    free(img0);
    free(img1);
    free(img2);
}

char * prog_name;

int main(int argc, char ** argv)
{
    uint16_t * img;
    float * imgmes;
    float * imgker;

    float * imgnoise;
    float * imgrecons;

#ifdef __DEBUG__
    _MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() & ~_MM_MASK_INVALID
            & ~_MM_MASK_OVERFLOW & ~_MM_MASK_DIV_ZERO);
#endif

    /* Command line parser */
    char * arg0 = argv[0];
    arg0 = strrchr(arg0, '/');
    if (arg0)
        prog_name = arg0 + 1;
    else
        prog_name = argv[0];

    //if (cmdline_parser(argc, argv, & brecs_args) != 0)
    //    exit(EXIT_FAILURE);

    create_3d_dataset();

    return EXIT_SUCCESS;
}
