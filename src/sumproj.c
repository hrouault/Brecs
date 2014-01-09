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

float * opentiff_f(const char * fname, int * sx, int * sy, int * sz)
{
    TIFF * tif = TIFFOpen(fname, "r");
    float * img;
    if (!tif) exit(EXIT_FAILURE);

    uint32 imagelength;
    tsize_t scanline;
    tdata_t buf;
    uint32 row;
    uint32 col;

    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imagelength);
    *sy = imagelength;
    scanline = TIFFScanlineSize(tif);
    *sx = scanline / 4;
    int dircount = 0;
    do {
        dircount++;
    } while (TIFFReadDirectory(tif));
    TIFFSetDirectory(tif, 0);
    *sz = dircount;
    posix_memalign((void **)&img, 32,
            *sx * *sy * *sz * sizeof(float));

    buf = _TIFFmalloc(scanline);
    for (size_t z = 0; z < dircount; ++z) {
        for (row = 0; row < imagelength; row++) {
            TIFFReadScanline(tif, buf, row, 0);
            for (col = 0; col < scanline / 4; col++)
                img[col + row * scanline / 4 + z * *sx * *sy]
                    = ((float *)buf)[col];
        }
        TIFFReadDirectory(tif);
    }
    _TIFFfree(buf);
    TIFFClose(tif);

    return img;
}


void sumproj(const char * fname)
{
    int simg = 275 * 285;
    float * img;
    float * imgsum = malloc(simg * sizeof(float));

    int imgwidth, imgheight, imgdepth;
    for (size_t j = 0; j < simg; ++j) {
        imgsum[j] = 0;
    }
    for (size_t i = 0; i < 10000; ++i) {
        printf("treating img: %ld\n", i);
        char fname[100];
        snprintf(fname, 100, "imgmes-%05ld.tif", i);
        img = opentiff_f(fname, &imgwidth, &imgheight, &imgdepth);

        for (size_t j = 0; j < simg; ++j) {
            if (img[j] > imgsum[j]) {
                imgsum[j] = img[j];
            }
            //imgsum[j] += img[j];
        }
        free(img);
    }
    writetiff_f("imgsum.tif", imgwidth, imgheight, imgsum);
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
        fprintf(stderr, "%s: usage: sumproj stack_file.tif\n",
                prog_name);
        exit(EXIT_FAILURE);
    } else {
        sumproj(argv[1]);
    }

    return EXIT_SUCCESS;
}
