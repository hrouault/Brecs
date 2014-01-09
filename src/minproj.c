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
#include <errno.h>
#include <math.h>
#include <png.h>
#include <tiffio.h>
#include <fftw3.h>

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


#ifndef KER_SIZE
#define KER_SIZE 1.4
#endif

#ifdef MINPROJ_NBIMG
static int const nbimg = MINPROJ_NBIMG;
#else
static int const nbimg = 100;
#endif


/* Some sample C code for the quickselect algorithm, 
   taken from Numerical Recipes in C. */

#define SWAP(a,b) temp=(a);(a)=(b);(b)=temp;

float quickselect(float *arr, int n, int k)
{
    unsigned long i, ir, j, l, mid;
    float a, temp;

    l = 0;
    ir = n - 1;
    for(;;) {
        if (ir <= l + 1) { 
            if (ir == l + 1 && arr[ir] < arr[l]) {
                SWAP(arr[l], arr[ir]);
            }
            return arr[k];
        }
        else {
            mid = (l + ir) >> 1; 
            SWAP(arr[mid], arr[l + 1]);
            if (arr[l] > arr[ir]) {
                SWAP(arr[l], arr[ir]);
            }
            if (arr[l + 1] > arr[ir]) {
                SWAP(arr[l + 1],arr[ir]);
            }
            if (arr[l] > arr[l + 1]) {
                SWAP(arr[l], arr[l + 1]);
            }
            i = l + 1; 
            j = ir;
            a = arr[l + 1]; 
            for (;;) { 
                do i++; while (arr[i] < a); 
                do j--; while (arr[j] > a); 
                if (j < i) break; 
                SWAP(arr[i], arr[j]);
            } 
            arr[l + 1] = arr[j]; 
            arr[j] = a;
            if (j >= k) ir = j - 1; 
            if (j <= k) l = i;
        }
    }
}

float * gausskerpar(int sx, int sy, float radius)
{
    float * out;
    posix_memalign((void **)&out, ALIGNSIZE, sx * sy * sizeof(float));

    float sig2 = radius * radius;
    double sum = 0;
    for (int x = -sx / 2; x < sx / 2 ; ++x) {
        float dx2 = x * x;
        for (int y = -sy / 2; y < sy / 2; ++y) {
            float dy2 = y * y;
            float r2 = dx2 + dy2;
            float val = exp(-r2 / 2 / sig2);
            sum += val;
            int line = x;
            int col = y;
            if (x < 0) line += sx;
            if (y < 0) col += sy;

            out[col + line * sy] = val;
        }
    }
    for (unsigned int i = 0; i < sx * sy; ++i) {
        out[i] /= sum;
    }

    return out;
}


int nbconv;
int iimg_stack;

void writetiff(const char * fname, int sx, int sy, uint16_t * img)
{
    TIFF * outf = TIFFOpen(fname, "w");
    TIFFSetField(outf, TIFFTAG_IMAGEWIDTH, sx);
    TIFFSetField(outf, TIFFTAG_IMAGELENGTH, sy);
    TIFFSetField(outf, TIFFTAG_SAMPLESPERPIXEL, 1);
    TIFFSetField(outf, TIFFTAG_BITSPERSAMPLE, 16);
    TIFFSetField(outf, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    TIFFSetField(outf, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
    TIFFSetField(outf, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);
    TIFFSetField(outf, TIFFTAG_COMPRESSION, COMPRESSION_LZW);

    TIFFSetField(outf,
                 TIFFTAG_ROWSPERSTRIP,
                 TIFFDefaultStripSize(outf, 2 * sx));

    for (uint32 row = 0; row < sy; row++) {
        if (TIFFWriteScanline(outf, img + sx * row, row, 0) < 0)
            break;
    }
    TIFFClose(outf);
}

void writetiff_f(const char * fname, int sx, int sy, float * img)
{
    TIFF * outf = TIFFOpen(fname, "w");
    TIFFSetField(outf, TIFFTAG_IMAGEWIDTH, sx);
    TIFFSetField(outf, TIFFTAG_IMAGELENGTH, sy);
    TIFFSetField(outf, TIFFTAG_SAMPLESPERPIXEL, 1);
    TIFFSetField(outf, TIFFTAG_BITSPERSAMPLE, 32);
    TIFFSetField(outf, TIFFTAG_SAMPLEFORMAT, SAMPLEFORMAT_IEEEFP);
    TIFFSetField(outf, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    TIFFSetField(outf, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
    TIFFSetField(outf, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);
    TIFFSetField(outf, TIFFTAG_COMPRESSION, COMPRESSION_LZW);

    TIFFSetField(outf,
                 TIFFTAG_ROWSPERSTRIP,
                 TIFFDefaultStripSize(outf, 2 * sx));

    for (uint32 row = 0; row < sy; row++) {
        if (TIFFWriteScanline(outf, img + sx * row, row, 0) < 0)
            break;
    }
    TIFFClose(outf);
}


void minproj(const char * fname)
{
    TIFF * tif = TIFFOpen(fname, "r");
    if (!tif) exit(EXIT_FAILURE);
    int slice = 0;

    uint32_t imgheight, imgwidth;
    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imgheight);
    tsize_t scanline;
    scanline = TIFFScanlineSize(tif);
    imgwidth = scanline / 2;
    tdata_t buf;
    buf = _TIFFmalloc(scanline);

    printf("image size %d %d\n", imgheight, imgwidth);

    float * img = malloc(imgheight * imgwidth * sizeof(float));
    uint16_t * imgtmp = malloc(imgheight * imgwidth * sizeof(uint16_t));
    float * imgstack = malloc(imgheight * imgwidth * nbimg * sizeof(float));

    size_t dircount = 0;
    do {

        for (size_t row = 0; row < imgheight; row++) {
            TIFFReadScanline(tif, buf, row, 0);
            for (size_t col = 0; col < imgwidth; col++) {
                imgstack[dircount % nbimg + col * nbimg + nbimg * row * imgwidth]
                    = ((uint16_t *)buf)[col];
                imgtmp[col + row * imgwidth] = ((uint16_t *)buf)[col];
            }
        }
        char fnametmp[100];
        snprintf(fnametmp, 100, "img-%05ld.tif", dircount);
        writetiff(fnametmp, imgwidth, imgheight, imgtmp);
        
        if (dircount % nbimg == nbimg - 1) {
            for (unsigned int i = 0; i < imgheight; ++i) {
                for (unsigned int j = 0; j < imgwidth; ++j) {
                    img[j + i * imgwidth] = quickselect(imgstack
                                                        + j * nbimg
                                                        + i * imgwidth * nbimg,
                                                        nbimg, nbimg / 2);
                }
            }
            char fname[100];
            snprintf(fname, 100, "smoothen-%04ld.tif", dircount / nbimg);
            writetiff_f(fname, imgwidth, imgheight, img);
        }
        dircount++;
    } while (TIFFReadDirectory(tif));

    //uint16_t * img = malloc(imgheight * imgwidth * sizeof(uint16_t));
    //float * minimg = malloc(imgheight * imgwidth * sizeof(float));

    /* convolution variables */
    /*
    int sxfft = pow(2, (int)log2(imgheight) + 1);
    int syfft = pow(2, (int)log2(imgwidth) + 1);
    float * imgker = gausskerpar(sxfft, syfft, KER_SIZE);
    */

    /*
    float * imgsmoo = fftwf_malloc(sizeof(float) * sxfft * syfft);
    fftwf_complex * out1, * out2;
    fftwf_plan pforw1, pforw2, pbackw;

    out1 = fftwf_malloc(sizeof(fftwf_complex) * sxfft * (syfft / 2 + 1));
    out2 = fftwf_malloc(sizeof(fftwf_complex) * sxfft * (syfft / 2 + 1));

    pforw1 = fftwf_plan_dft_r2c_2d(sxfft, syfft,
                                   imgsmoo, out1,
                                   FFTW_ESTIMATE);
    pforw2 = fftwf_plan_dft_r2c_2d(sxfft, syfft,
                                   imgker, out2,
                                   FFTW_ESTIMATE);

    pbackw = fftwf_plan_dft_c2r_2d(sxfft, syfft,
                                   out1, imgsmoo,
                                   FFTW_ESTIMATE);
                                   

    fftwf_execute(pforw2);
    */

//    for (unsigned int i = 0; i < imgheight * imgwidth; ++i) {
//        minimg[i] = 1e8;
//    }
//
//    do {
//        //TIFFPrintDirectory(tif, stdout, 0);
//        //printf("Treating file %d\n", slice);
//        /* opening image */
//        for (unsigned int i = 0; i < syfft * sxfft; ++i) {
//            imgsmoo[i] = 0;
//        }
//        for (unsigned int row = 0; row < imgheight; row++) {
//            TIFFReadScanline(tif, buf, row, 0);
//            for (unsigned int col = 0; col < imgwidth; col++)
//                imgsmoo[col + row * syfft] = ((uint16 *)buf)[col];
//        }
//
//        writetiff_f("opened.tif", sxfft, syfft, imgsmoo);
//
//        /* Convolving image */
//        /*
//        fftwf_execute(pforw1);
//        for (unsigned int i = 0; i < sxfft * (syfft / 2 + 1); ++i) {
//            fftwf_complex c1, c2;
//            c1[0] = out1[i][0];
//            c1[1] = out1[i][1];
//            c2[0] = out2[i][0];
//            c2[1] = out2[i][1];
//
//            out1[i][0] = (c1[0] * c2[0] - c1[1] * c2[1]) / (sxfft * syfft);
//            out1[i][1] = (c1[0] * c2[1] + c1[1] * c2[0]) / (sxfft * syfft);
//        }
//
//        fftwf_execute(pbackw);
//        */
//
//        //writetiff_f("smoothened.tif", sxfft, syfft, imgsmoo);
//
//        for (unsigned int i = 0; i < imgheight; ++i) {
//            for (unsigned int j = 0; j < imgwidth; ++j) {
//                float val = imgsmoo[j + i * syfft];
//                if (val < minimg[j + i * imgwidth])
//                    minimg[j + i * imgwidth] = val;
//            }
//        }
//
//        /* saving min image */
//        if (slice % 100 == 99) {
//            char fname[100];
//            snprintf(fname, 100, "smoothen-%04d.tif", slice / 100);
//            writetiff_f(fname, imgheight, imgwidth, minimg);
//            /* reset minimum */
//            for (unsigned int i = 0; i < imgheight * imgwidth; ++i) {
//                minimg[i] = 1e8;
//            }
//        }
//        slice++;
//    } while (TIFFReadDirectory(tif));
//
//    fftwf_free(imgker);
//    fftwf_destroy_plan(pforw1);
//    fftwf_destroy_plan(pforw2);
//    fftwf_destroy_plan(pbackw);
//
//
//    _TIFFfree(buf);
//    TIFFClose(tif);
//
//    fftwf_cleanup();
}

char * prog_name;

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

    /* Remove libtiff warnings */
    TIFFSetWarningHandler(NULL);

    if (argc != 2) {
        fprintf(stderr, "%s: usage: minproj stack_file.tif\n",
                prog_name);
        exit(EXIT_FAILURE);
    } else {
        minproj(argv[1]);
    }

    return EXIT_SUCCESS;
}
