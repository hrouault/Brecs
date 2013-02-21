/* Copyright (c) , Herve Rouault
 * All rights reserved.
 * 
 * This file is part of Bstorm.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
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
#include <math.h>
#include <gsl/gsl_sf_bessel.h>
#include <png.h>
#include <tiffio.h>

#include <cpuid.h> /* __get_cpuid_max, __get_cpuid */
#include <mmintrin.h> /* MMX instrinsics  __m64 integer type  */
#include <xmmintrin.h> /* SSE  __m128  float */
#include <pmmintrin.h>

/* floating point exception on OS X uses SSE, but does not work... */
//_MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() & ~_MM_MASK_INVALID);

/* Floating point control */
//#define __USE_GNU
//#define _GNU_SOURCE
//#include <fenv.h>

#include <bzlib.h>

#include "cmdline.h"
#include "Bstorm.h"

/* Command line variable */
struct gengetopt_args_info bstorm_args;

/* Constant definitions */


// DATASET 1 (eye 2)
///* signal noise properties */
//const float pixmean = 4800;
//const double pixstd = 200;
//const double rho = 0.001;
//float thrA = 0.1 / (10 * 1000 * 1000);
//
//const float pixthr = 500;
//
///* Sizes of the images */
//const int smes = 8;
//const int smes2 = 8 * 8;
//const int sizex = 128 * 8;
//const int sizey = 256 * 8;
//const int size2 = 128 * 8 * 256 * 8;
//const int sker = 8; /* has to be a multiple of 4 to use sse */
//const int sker2 = 8 * 8;
//
//const float spix = 150.0 / 8;
//
//const int nbmesx = 128;
//const int nbmesy = 256;
//const int nbmes2 = 128 * 256;
//
//const int plot_no_rescale = 0;
//const int plot_rescale = 1;
//
//const int nbintern = 1;
//
//const float damp = 0.02;
//
//const int printres = 0;
//
//const float noiseback = 1200;
//
///* Properties of the psf */
//const float sigpsf = 0.732 * 8 * 1.14; /* the 1.14 is for defocus */
///* the 0.86 is due to defocus */
//const float numap = 1.0;
//
//const float Ainit = 10.0 / (4800 * 4800);
//
//const int nbiter = 500;
//
//const float meanback = 100;
//
//const int width = 256;
//const int height = 256;



//// DATASET 2 (snow)
///* signal noise properties */
//
//const float beta = 2.0;
//const float pixmean = 5000;
//float pixstd = 2000;
//float rho = 0.001;
//float thrA = 0.1 / (10 * 1000 * 1000);
//
//const float pixthr = 40;
//
//const float thrpoint = 800;
//
///* Sizes of the images */
//const int smes = 8;
//const int smes2 = 8 * 8;
//const int sizex = 128 * 8;
//const int sizey = 128 * 8;
//const int size2 = 128 * 8 * 128 * 8;
//const int sker = 12; /* has to be a multiple of 4 to use sse */
//const int sker2 = 12 * 12;
//
//const float spix = 100.0 / 8;
//
//const int width = 128;
//const int height = 128;
//
//const int nbmesx = 128;
//const int nbmesy = 128;
//const int nbmes2 = 128 * 128;
//
//const int plot_no_rescale = 0;
//const int plot_rescale = 1;
//
//const int nbintern = 1;
//
//const float damp = 0.01;
//
//const int printres = 1;
//
//float noiseback = 8 * 8;
//const float meanback = 20;
//
///* Properties of the psf */
//const float sigpsf = 1.0638 * 8 * 1.1; /* The 1.2 is for defocus */
////const float sigpsf = 1.376 * 8 * 1.5;
//const float numap = 1.0;
//
//const float Ainit = 10.0 / (4800 * 4800);
//
//const int nbiter = 6000;

// DATASET  contest 1 (HD1)
/* signal noise properties */

//#if DATASET == HD1
const float beta = 2.0;
const float pixmean = 5000;
float pixstd = 2000;
float rho = 0.001;
float thrA = 0.1 / (10 * 1000 * 1000);

const float pixthr = 70;

const float thrpoint = 300;

/* Sizes of the images */
const int smes = 8;
const int smes2 = 8 * 8;
const int sker = 8; /* has to be a multiple of 4 to use sse */
const int sker2 = 8 * 8;
const int sizex = (128 + 8) * 8;
const int sizey = (128 + 8) * 8;
const int size2 = (128 + 8) * 8 * (128 + 8) * 8;

const float spix = 100.0 / 8;

const int width = 128;
const int height = 128;

const int nbmesx = 128 + 8;
const int nbmesy = 128 + 8;
const int nbmes2 = (128 + 8) * (128 + 8);

const int plot_no_rescale = 0;
const int plot_rescale = 1;

const int nbintern = 1;

const float damp = 0.06;

const int printres = 1;

float noiseback = 5620;
const float meanback = 200;

/* Properties of the psf */
const float sigpsf = 0.9545 * 8 * 1.1; /* The 1.2 is for defocus */
const float numap = 1.0;

const float Ainit = 10.0 / (4800 * 4800);

const int nbiter = 600;

//#endif

int nbframe;

void updatetemp(double b)
{
    double c = pow(rho, b);
    rho = c / (1 + c);

    noiseback = noiseback / b;
    pixstd = pixstd / sqrt(b);
}


void gaussker(float * ker)
{
    for (int x = -(int)sizex / 2; x < (int)sizex / 2 ; ++x)
    {
        for (int y = -(int)sizey / 2; y < (int)sizey / 2; ++y)
        {
            float dx2 = x * x;
            float dy2 = y * y;
            float radius2 = dx2 + dy2;
            float val = exp(-radius2 / 2 / (sigpsf * sigpsf)) / (2 * M_PI * sigpsf * sigpsf);
            int line = x;
            int col = y;
            if (x < 0) line += sizex;
            if (y < 0) col += sizey;
            
            ker[col + line * sizey] = val;
        }
    }
}

void plot_image(int sx, int sy,
                float * img,
                const char * filen,
                int flags)
{
    FILE * fp = fopen(filen, "wb");
    if (!fp) exit(EXIT_FAILURE);

    png_structp png_ptr = png_create_write_struct (PNG_LIBPNG_VER_STRING,
                                                   NULL, NULL, NULL);
    if (!png_ptr) exit(EXIT_FAILURE);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
        exit(EXIT_FAILURE);
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    png_init_io(png_ptr, fp);

    png_set_IHDR(png_ptr, info_ptr, sy, sx,
                 8, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    /*
     * At this point, we have to rewrite the image to convert it to ints
     * Then the image date array is passed to the info struct
     */
    int i, x;
    png_byte * img_data = malloc(sx * sy * sizeof(png_byte));
    float max = 0;
    float min = 0;
    if (flags == plot_rescale){
        for (i = 0 ; i < sx * sy ; i++){
            if (max < img[i]) max = img[i];
            if (min > img[i]) min = img[i];
        }
        for (x = 0 ; x < sx * sy ; x++){
            img_data[x] = 255 / (max - min) * (img[x] - min);
        }
    } else {
        for (x = 0 ; x < sx * sy ; x++){
            img_data[x] = img[x];
        }
    }
    png_bytep row_pointers[sx];
    for (x = 0 ; x < sx ; x++) row_pointers[x] = img_data + x * sy;
    png_set_rows(png_ptr, info_ptr, row_pointers);

    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    free(img_data);
}

void plot_overlay(float * mes,
                  float * pred,
                  const char * filen)
{
    FILE * fp = fopen(filen, "wb");
    if (!fp) exit(EXIT_FAILURE);

    png_structp png_ptr = png_create_write_struct (PNG_LIBPNG_VER_STRING,
                                                   NULL, NULL, NULL);
    if (!png_ptr) exit(EXIT_FAILURE);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
        exit(EXIT_FAILURE);
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    png_init_io(png_ptr, fp);

    png_set_IHDR(png_ptr, info_ptr, sizey, sizex,
                 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    /*
     * At this point, we have to rewrite the image to convert it to ints
     * Then the image date array is passed to the info struct
     */
    int i, x, y;
    png_byte * img_data = malloc(size2 * 3 * sizeof(png_byte));
    float max1 = 0;
    float min1 = 0;
    float max2 = 0;
    float min2 = 0;
    for (i = 0 ; i < size2 ; i++){
        if (max1 < pred[i]) max1 = pred[i];
        if (min1 > pred[i]) min1 = pred[i];
    }
    for (i = 0 ; i < nbmes2 ; i++){
        if (max2 < mes[i]) max2 = mes[i];
        if (min2 > mes[i]) min2 = mes[i];
    }
    for (x = 0 ; x < sizex ; x++){
        for (y = 0 ; y < sizey ; y++){
            if (pred[x * sizey + y] > 10){
                img_data[(x * sizey + y) * 3] = 255 / (max1 - min1)
                         * (pred[x * sizey + y] - min1);;
                img_data[1 + (x * sizey + y) * 3] = 0;
                img_data[2 + (x * sizey + y) * 3] = 0;
            } else {
                float val = 255 / (max2 - min2)
                    * (mes[(x / smes) * nbmesy + y / smes] - min2);
                img_data[(x * sizey + y) * 3] = val;
                img_data[1 + (x * sizey + y) * 3] = val;
                img_data[2 + (x * sizey + y) * 3] = val;
            }
        }
    }
    png_bytep row_pointers[sizex];
    for (x = 0 ; x < sizex ; x++) row_pointers[x] = img_data + x * sizey * 3;
    png_set_rows(png_ptr, info_ptr, row_pointers);

    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    free(img_data);
}

void saveimage(float * img, int size, const char * fname)
{
    FILE * fout = fopen(fname, "wb");
    if (!fout) exit(EXIT_FAILURE);

    BZFILE* b;
    int nBuf = 256 * 1024;
    char buf[nBuf];
    int bzerror;
    int j = 0;

    b = BZ2_bzWriteOpen( &bzerror, fout, 9, 0, 30 );
    if (bzerror != BZ_OK) {
        BZ2_bzWriteClose (&bzerror, b, 0, NULL, NULL);
        exit(EXIT_FAILURE);
    }
    int nbtot = 0;

    while (j < size) {
        /* get data to write into buf, and set nBuf appropriately */
        size_t i;
        for (i = 0; i < nBuf && j < size; i += 2)
        {
            *(uint16_t *)(buf + i) = (uint16_t)(img[j]);
            j++;
        }
        BZ2_bzWrite ( &bzerror, b, buf, i);
        if (bzerror == BZ_IO_ERROR) { 
            BZ2_bzWriteClose(&bzerror, b, 0, NULL, NULL);
            exit(EXIT_FAILURE);
        }
        nbtot += i;
    }

    BZ2_bzWriteClose(&bzerror, b, 0, NULL, NULL);
    if (bzerror == BZ_IO_ERROR) {
            exit(EXIT_FAILURE);
    }
}


void fafcfunc(float * out, float sig2, float r)
{
    float pstd2 = pixstd * pixstd;

    float deltr = (r - pixmean) * (r - pixmean);
    float varr = sig2 + pstd2;

    float fra = sqrt(sig2 / varr);
    float fra1 = fra / varr;
    float fra2 = fra1 / varr;

    float argexp = -r * r / 2 / sig2 + deltr / 2 / varr;
    if (argexp > 15.0){
        out[0] = 0;
        out[1] = 1e-6;
        return;
    }
    float exprgauss = exp(argexp);

    float onemrho = 1 - rho;
    float onemrm1 = 1 / rho - 1;

    float sum1 = pixmean * sig2 + r * pstd2;
    float num1 = sum1;
    float den1 = onemrm1 * exprgauss / fra1 + varr;

    float rho2 = rho * rho;
    float sum2 = pstd2 * sig2 * varr + sum1 * sum1;
    float fra4 = pstd2 * sig2 * sig2 / varr / varr;
    float num2 = rho * onemrho * exprgauss * fra2 * sum2
                  + rho2 * fra4;
    float den2 = onemrho * exprgauss + rho * fra;
    den2 = den2 * den2;

    out[0] = num1 / den1;
    out[1] = num2 / den2;

    //if (out[1] < 1) out[1] = 1;
    if (out[0] < 0) out[0] = 0;
    //if (out[0] > 1500) out[0] = 1500;
    if (out[0] > 665000){
        printf("%f %f %f %f %f %f %f\n", sig2, r, exprgauss, den1, num1, den2, num2);
    }
}

void init_kernels(float * ker, float * ker2,
                  float * psf)
{
    for (int k = 0; k < sker2 * smes2; ++k) {
        ker[k] = 0;
        ker2[k] = 0;
    }

    for (int i = 0; i < smes; i++) {
        for (int j = 0; j < smes; j++) {
            for (int x = -sker / 2; x < sker / 2; ++x) {
                for (int y = -sker / 2; y < sker / 2; ++y) {
                    float sum = 0;
                    for (int k = 0; k < smes; k++) {
                        for (int l = 0; l < smes; l++) {
                            int li = -i + k + smes * x;
                            if (li < 0) li += sizex;
                            int c = -j + l + smes * y;
                            if (c < 0) c += sizey;

                            sum += psf[c + sizey * li];
                        }
                    }
                    int cker = y + sker / 2;
                    int lker = x + sker / 2;
                    int indi = j + smes * i;
                    int indmu = cker + sker * lker;
                    ker[indmu + indi * sker2] = sum;
                    ker2[indmu + indi * sker2] = sum * sum;
                }
            }
        }
    }
}

void update_omegavmu(float * omegamu, float * vmu,
                     float * ker, float * ker2,
                     float * abeal, float * vbeal,
                     int nbact, int * activepix)
{
#ifdef __AVX__
    const __m256 zero = _mm256_set1_ps(0);

    for (int mu = 0; mu < nbmes2; mu += 8)
    {
        _mm256_store_ps(vmu + mu, zero);
        _mm256_store_ps(omegamu + mu, zero);
    }
    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
        float * cabeal = abeal + i * sker2;
        float * cvbeal = vbeal + i * sker2;


        int ci = (i % sizey) % smes;
        int li = (i / sizey) % smes;
        int ikeri = ci + li * smes;

        float * cker = ker + ikeri * sker2;
        float * cker2 = ker2 + ikeri * sker2;

        for (int mu = 0; mu < sker2; mu += 8)
        {
            int dcmu = mu % sker - sker / 2;
            int dlmu = mu / sker - sker / 2;

            int cmu = (i % sizey) / smes + dcmu;
            int lmu = (i / sizey) / smes + dlmu;
            int imu = cmu + lmu * nbmesy;

            __m256 ck = _mm256_load_ps(cker + mu);
            __m256 ck2 = _mm256_load_ps(cker2 + mu);

            __m256 ca = _mm256_load_ps(cabeal + mu);
            __m256 cv = _mm256_load_ps(cvbeal + mu);

            ca = _mm256_mul_ps(ck, ca);
            cv = _mm256_mul_ps(ck2, cv);

            __m256 po =  _mm256_loadu_ps(omegamu + imu);
            __m256 pv =  _mm256_loadu_ps(vmu + imu);

            ca = _mm256_add_ps(ca, po);
            cv = _mm256_add_ps(cv, pv);

            _mm256_storeu_ps(omegamu + imu, ca);
            _mm256_storeu_ps(vmu + imu, cv);
        }
    }

#else

    const __m128 zero = _mm_set1_ps(0);

    for (int mu = 0; mu < nbmes2; mu += 4)
    {
        _mm_store_ps(vmu + mu, zero);
        _mm_store_ps(omegamu + mu, zero);
    }
    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
        float * cabeal = abeal + i * sker2;
        float * cvbeal = vbeal + i * sker2;


        int ci = (i % sizey) % smes;
        int li = (i / sizey) % smes;
        int ikeri = ci + li * smes;

        float * cker = ker + ikeri * sker2;
        float * cker2 = ker2 + ikeri * sker2;

        for (int mu = 0; mu < sker2; mu += 4)
        {
            int dcmu = mu % sker - sker / 2;
            int dlmu = mu / sker - sker / 2;

            int cmu = (i % sizey) / smes + dcmu;
            int lmu = (i / sizey) / smes + dlmu;
            int imu = cmu + lmu * nbmesy;

            __m128 ck = _mm_load_ps(cker + mu);
            __m128 ck2 = _mm_load_ps(cker2 + mu);

            __m128 ca = _mm_load_ps(cabeal + mu);
            __m128 cv = _mm_load_ps(cvbeal + mu);

            ca = _mm_mul_ps(ck, ca);
            cv = _mm_mul_ps(ck2, cv);

            __m128 po =  _mm_loadu_ps(omegamu + imu);
            __m128 pv =  _mm_loadu_ps(vmu + imu);

            ca = _mm_add_ps(ca, po);
            cv = _mm_add_ps(cv, pv);

            _mm_storeu_ps(omegamu + imu, ca);
            _mm_storeu_ps(vmu + imu, cv);
        }
    }
#endif
}

#ifdef __AVX__
inline __m128 abs_ps(__m128 x) {
    __m128 sign_mask = _mm_set1_ps(-0.f); // -0.f = 1 << 31
    return _mm_andnot_ps(sign_mask, x);
}
#else
inline __m128 abs_ps(__m128 x) {
    __m128 sign_mask = _mm_set1_ps(-0.f); // -0.f = 1 << 31
    return _mm_andnot_ps(sign_mask, x);
}
#endif

float update_Palbe(float * mu_beal_A, float * mu_beal_B,
                   float * P_albe_A, float * P_albe_B,
                   float * abeal, float * vbeal,
                   float * P_be_E, float * P_be_F,
                   float * omegamu, float * vmu,
                   float * ker, float * ker2,
                   float * imgnoise, float * imgmes,
                   int nbact, int * activepix)
{
    float rat = ((float)sker2 - 1) / sker2;
    const __m128 zero = _mm_set1_ps(0);
    const __m128 one = _mm_set1_ps(1.0);
    __m128 relerr = zero;

    update_omegavmu(omegamu, vmu, ker, ker2, abeal, vbeal, nbact, activepix);

    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
            float * cbA = mu_beal_A + i * sker2;
            float * cbB = mu_beal_B + i * sker2;
            float * cabeal = abeal + i * sker2;
            float * cvbeal = vbeal + i * sker2;
            float * cPA = P_albe_A + i * sker2;
            float * cPB = P_albe_B + i * sker2;


            int ci = (i % sizey) % smes;
            int li = (i / sizey) % smes;
            int ikeri = ci + li * smes;

            float * cker = ker + ikeri * sker2;
            float * cker2 = ker2 + ikeri * sker2;

            const __m128 rPE = _mm_set1_ps(rat * P_be_E[i]);
            const __m128 rPF = _mm_set1_ps(rat * P_be_F[i]);

            const __m128 epserr = _mm_set1_ps(1e-6);

            for (int mu = 0; mu < sker2; mu += 4)
            {
                int dcmu = mu % sker - sker / 2;
                int dlmu = mu / sker - sker / 2;

                int cmu = (i % sizey) / smes + dcmu;
                int lmu = (i / sizey) / smes + dlmu;
                int imu = cmu + lmu * nbmesy;

                __m128 den = _mm_loadu_ps(imgnoise + imu);
                __m128 v = _mm_loadu_ps(vmu + imu);
                __m128 k2 = _mm_load_ps(cker2 + mu);
                __m128 k = _mm_load_ps(cker + mu);
                __m128 vb = _mm_load_ps(cvbeal + mu);

                den = _mm_add_ps(den, v);
                vb = _mm_mul_ps(k2, vb);
                den = _mm_sub_ps(den, vb);
                den = _mm_div_ps(one, den);

                __m128 bnum = _mm_loadu_ps(imgmes + imu);
                __m128 om = _mm_loadu_ps(omegamu + imu);
                __m128 ab = _mm_load_ps(cabeal + mu);

                ab = _mm_mul_ps(k, ab);
                bnum = _mm_sub_ps(bnum, om);
                bnum = _mm_add_ps(bnum, ab);
                bnum = _mm_mul_ps(bnum, k);

                __m128 valA = _mm_mul_ps(k2, den);
                valA = _mm_add_ps(valA, rPE);
                __m128 ibA = _mm_load_ps(cbA + mu);
                valA = _mm_add_ps(valA, ibA);

                /*
                __m128 c = _mm_load_ps(cPA + mu);
                __m128 n = _mm_sub_ps(valA, c);
                __m128 d = _mm_add_ps(valA, c);
                n = _mm_div_ps(n, d);
                __m128 errt = abs_ps(n);
                relerr = _mm_max_ps(relerr, errt);
                */

                _mm_store_ps(cPA + mu, valA);

                __m128 valB = _mm_mul_ps(bnum, den);
                valB = _mm_add_ps(valB, rPF);
                __m128 ibB = _mm_load_ps(cbB + mu);
                valB = _mm_add_ps(valB, ibB);

                /*
                c = _mm_load_ps(cPB + mu);
                d = _mm_add_ps(valB, c);
                d = _mm_max_ps(epserr, n);
                n = _mm_sub_ps(valB, c);
                errt = _mm_div_ps(n, d);
                errt = abs_ps(errt);
                relerr = _mm_max_ps(relerr, errt);
                */

                valB = _mm_max_ps(zero, valB);

                _mm_store_ps(cPB + mu, valB);
            }
        }
    //}
    float relerrf4[4] __attribute__ ((aligned (16)));
    _mm_store_ps(relerrf4, relerr);
    if (relerrf4[1] > relerrf4[0]) relerrf4[0] = relerrf4[1];
    if (relerrf4[2] > relerrf4[0]) relerrf4[0] = relerrf4[2];
    if (relerrf4[3] > relerrf4[0]) relerrf4[0] = relerrf4[3];

    return relerrf4[0];
}

double update_mualbe(float * mu_albe_A, float * mu_albe_B,
                     float * mu_beal_A, float * mu_beal_B,
                     float * P_albe_A, float * P_albe_B,
                     float * abeal, float * vbeal,
                     float * P_be_E, float * P_be_F,
                     float * omegamu, float * vmu,
                     float * ker, float * ker2,
                     float * imgnoise, float * imgmes,
                     int nbact, int * activepix)
{
    float relerr = update_Palbe(mu_beal_A, mu_beal_B,
                                P_albe_A, P_albe_B,
                                abeal, vbeal,
                                P_be_E, P_be_F,
                                omegamu, vmu,
                                ker, ker2,
                                imgnoise, imgmes,
                                nbact, activepix);

    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
        const __m128 zero = _mm_set1_ps(0);
        const __m128 vthr = _mm_set1_ps(thrA);
        const __m128 vthr2 = _mm_set1_ps(1e2);
        const __m128 oneosk = _mm_set1_ps(1.0f / sker2);
        __m128 PAt = _mm_set1_ps(0);
        __m128 PBt = _mm_set1_ps(0);

        float * caA = mu_albe_A + i * sker2;
        float * caB = mu_albe_B + i * sker2;
        float * cbA = mu_beal_A + i * sker2;
        float * cbB = mu_beal_B + i * sker2;
        float * cPA = P_albe_A + i * sker2;
        float * cPB = P_albe_B + i * sker2;

        for (int mu = 0; mu < sker2; mu += 4)
        {
            __m128 v = _mm_load_ps(cPA + mu);
            PAt = _mm_add_ps(PAt, v);
            v = _mm_load_ps(cPB + mu);
            PBt = _mm_add_ps(PBt, v);
        }
        PAt = _mm_hadd_ps(PAt, PAt);
        PAt = _mm_hadd_ps(PAt, PAt);

        PBt = _mm_hadd_ps(PBt, PBt);
        PBt = _mm_hadd_ps(PBt, PBt);

        PAt = _mm_mul_ps (PAt, oneosk);
        PBt = _mm_mul_ps (PBt, oneosk);

        PBt = _mm_max_ps(zero, PBt);

        for (int mu = 0; mu < sker2; mu += 4)
        {
            __m128 A = _mm_load_ps(cPA + mu);
            __m128 B = _mm_load_ps(cPB + mu);
            __m128 maA = _mm_load_ps(caA + mu);
            __m128 maB = _mm_load_ps(caB + mu);

            A = _mm_sub_ps(A, PAt);
            B = _mm_sub_ps(B, PBt);

            A = _mm_add_ps(A, maA);
            B = _mm_add_ps(B, maB);

            B = _mm_max_ps(vthr, A);
            B = _mm_min_ps(vthr2, A);
            B = _mm_max_ps(zero, B);

            _mm_store_ps(caA + mu, A);
            _mm_store_ps(caB + mu, B);
        }
    }

    return relerr;
}

void update_mubeal(float * vbeal, float * abeal,
                   float * mu_beal_A, float * mu_beal_B,
                   float * mu_albe_A, float * mu_albe_B,
                   float * P_be_E, float * P_be_F,
                   int nbact, int * activepix)
{
    float rat = ((float)sker2 - 1) / sker2;
    const __m128 zero = _mm_set1_ps(0);
    const __m128 one = _mm_set1_ps(1.0);
    const __m128 oneosk = _mm_set1_ps(1.0f / sker2);

    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
        float * caA = mu_albe_A + i * sker2;
        float * caB = mu_albe_B + i * sker2;
        float * cbA = mu_beal_A + i * sker2;
        float * cbB = mu_beal_B + i * sker2;
        float * cabeal = abeal + i * sker2;
        float * cvbeal = vbeal + i * sker2;

        /* Compute P_beta */
        __m128 P_be_A = zero;
        __m128 P_be_B = zero;
        for (size_t mu = 0; mu < sker2; mu += 4)
        {
            __m128 a = _mm_load_ps(caA + mu);
            P_be_A = _mm_add_ps(P_be_A, a);
            __m128 b = _mm_load_ps(caB + mu);
            P_be_B = _mm_add_ps(P_be_B, b);
        }
        P_be_A = _mm_hadd_ps(P_be_A, P_be_A);
        P_be_A = _mm_hadd_ps(P_be_A, P_be_A);

        P_be_B = _mm_hadd_ps(P_be_B, P_be_B);
        P_be_B = _mm_hadd_ps(P_be_B, P_be_B);

        P_be_A = _mm_mul_ps (P_be_A, oneosk);
        P_be_B = _mm_mul_ps (P_be_B, oneosk);

        P_be_B = _mm_max_ps (P_be_B, zero);

        const __m128 rPE = _mm_set1_ps(rat * P_be_E[i]);
        const __m128 rPF = _mm_set1_ps(rat * P_be_F[i]);

        /* Compute mu_beal */
        for (size_t mu = 0; mu < sker2; mu += 4)
        {
            __m128 cC = _mm_load_ps(caA + mu);
            cC = _mm_sub_ps(P_be_A, cC);
            __m128 cD = _mm_load_ps(caB + mu);
            cD = _mm_sub_ps(P_be_B, cD);

            cD = _mm_max_ps(zero, cD);

            _mm_store_ps(cbA + mu, cC);
            _mm_store_ps(cbB + mu, cD);

            __m128 maA = _mm_load_ps(caA + mu);
            __m128 maB = _mm_load_ps(caB + mu);

            cC = _mm_add_ps(rPE, cC);
            cC = _mm_div_ps(one, cC);

            cD = _mm_add_ps(rPF, cD);
            cD = _mm_mul_ps(cC, cD);

            _mm_store_ps(cvbeal + mu, cC);
            _mm_store_ps(cabeal + mu, cD);
        }
    }
}

void update_pbe(float * P_be_E, float * P_be_F,
                float * P_albe_A, float * P_albe_B,
                float * abeal, float * vbeal,
                float * omegamu, float * vmu,
                float * mu_beal_A, float * mu_beal_B,
                float * ker, float * ker2,
                float * imgnoise, float * imgmes,
                int nbact, int * activepix,
                int iterpbe)
{
    /* The coefficient should be equal after convergence, we choose to take
     * the average of the coefficients here...
     * This is the logarithmic average instead of the normal average, this
     * should not make a difference at convergence.
     */
    float relerr = 1.0;
    //while (relerr > 5e-2)
    //for (size_t iter = 0; iter < iterpbe; ++iter)
    //{
    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
        float avA = 0;
        float avB = 0;
        float * cA = P_albe_A + i * sker2;
        float * cB = P_albe_B + i * sker2;
        for (size_t mu = 0; mu < sker2; ++mu)
        {
            avA += cA[mu];
            avB += cB[mu];
        }
        //if (avA < 1e-6) avA = 1e-6;
        //avA /= sker2;
        //avB /= sker2;

        float PEt = avA  - (sker2 - 1) * P_be_E[i];
        float PFt = avB  - (sker2 - 1) * P_be_F[i];
        if (PEt < 1e-8){
            PFt = PFt * 1e-8 / PEt;
            PEt = 1e-8;
            if (PFt / PEt > 1e4) PFt = 1e4 * PEt;
        }
        if (PFt < 0) PFt = 0;

        float prevPbE = P_be_E[i];
        float prevPbF = P_be_F[i];

        if (PEt / prevPbE < 1e-3){
        //    printf("bigchange!\n");
            PEt = prevPbE * 1e-2;
        }

        float fafc[2];
        fafcfunc(fafc, 1 / PEt, PFt / PEt);


        float invE = (1 - damp) / P_be_E[i] + damp * fafc[1];
        //float invE = fafc[1];
        P_be_E[i]= 1/ invE;
        //P_be_E[i]= 1 / fafc[1];
        P_be_F[i] = (1 - damp) * P_be_F[i] / invE / prevPbE
            + damp * fafc[0] / invE;
        //P_be_F[i] = fafc[0] / fafc[1];
        /*
        if (P_be_F[i] / P_be_E[i] > 45){
            printf("PbF PbE: %f %f %f\n", P_be_F[i], P_be_E[i], P_be_F[i] / P_be_E[i]);
            printf("fafc: %f %f\n", fafc[0], fafc[1]);
            printf("avB avA: %f %f %f\n", avB, avA, avB / avA);
            printf("PFt PEt: %f %f %f\n", PFt, PEt, PFt / PEt);
            printf("prevPbF prevPbE: %f %f %f\n", prevPbF, prevPbE, prevPbF / prevPbE);
            exit(EXIT_FAILURE);
        }
        */
    }
        //}
        /*
        relerr = update_Palbe(mu_beal_A, mu_beal_B,
                              P_albe_A, P_albe_B,
                              abeal, vbeal,
                              P_be_E, P_be_F,
                              omegamu, vmu,
                              ker, ker2,
                              imgnoise, imgmes,
                              nbact, activepix);
                              */
        //printf("relerr: %f\n", relerr);
    //}
}

float * reconssparse(float * imgmes, float * imgnoise, float * psf)
{
    float * mu_albe_A;
    float * mu_albe_B;
    float * mu_beal_A;
    float * mu_beal_B;
    float * P_albe_A;
    float * P_albe_B;
    float * abeal;
    float * vbeal;
    float * P_be_E;
    float * P_be_F;
    float * omegamu;
    float * vmu;
    int * pixactivity;
    int * activepix;


    float * ker;
    float * ker2;

    float * res;

    /* Memory allocation */
    posix_memalign((void **)&mu_albe_A, 16, size2 * sker2 * sizeof(float));
    posix_memalign((void **)&mu_albe_B, 16, size2 * sker2 * sizeof(float));
    posix_memalign((void **)&mu_beal_A, 16, size2 * sker2 * sizeof(float));
    posix_memalign((void **)&mu_beal_B, 16, size2 * sker2 * sizeof(float));
    posix_memalign((void **)&P_albe_A, 16, size2 * sker2 * sizeof(float));
    posix_memalign((void **)&P_albe_B, 16, size2 * sker2 * sizeof(float));
    posix_memalign((void **)&abeal, 16, size2 * sker2 * sizeof(float));
    posix_memalign((void **)&vbeal, 16, size2 * sker2 * sizeof(float));
    posix_memalign((void **)&P_be_E, 16, size2 * sizeof(float));
    posix_memalign((void **)&P_be_F, 16, size2 * sizeof(float));
    posix_memalign((void **)&omegamu, 16, nbmes2 * sizeof(float));
    posix_memalign((void **)&vmu, 16, nbmes2 * sizeof(float));
    posix_memalign((void **)&pixactivity, 16, size2 * sizeof(int));
    posix_memalign((void **)&activepix, 16, size2 * sizeof(int));

    posix_memalign((void **)&ker, 16, smes2 * sker2 * sizeof(float));
    posix_memalign((void **)&ker2, 16, smes2 * sker2 * sizeof(float));

    posix_memalign((void **)&res, 16, size2 * sizeof(float));

    /* Initialize kernels */
    init_kernels(ker, ker2, psf);
    /*
    printf("Ker min, max: %f %f\n",                                            
           min(ker, smes2 * sker2),                                               
           max(ker, smes2 * sker2));
    */
    plot_image(smes * sker, smes * sker, ker, "kerint.png", plot_rescale);
    printf("imgmes min, max: %f %f\n",                                            
           min(imgmes, nbmes2),                                               
           max(imgmes, nbmes2));
    printf("imgnoise min, max: %f %f\n",                                            
           min(imgnoise, nbmes2),                                               
           max(imgnoise, nbmes2));

    //plot_image(sker, sker, ker + 32 * sker2, "kercent.png", plot_rescale);

    float Binit = rho * pixmean * Ainit;
    for (int i = 0; i < size2 * sker2; ++i) {
        mu_albe_A[i] = Ainit;
        mu_albe_B[i] = Binit;
        P_albe_B[i] = Binit;
        P_albe_A[i] = Ainit;
    }
    for (int i = 0; i < size2; ++i) {
        P_be_E[i] = Ainit;
        P_be_F[i] = Binit;
    }
    //printf("ABinit: %f %f\n", Ainit, Binit);

    int nbact = 0;
    for (int i = 0; i < size2; ++i)
    {
        int ci = (i % sizey) / smes;
        int li = (i / sizey) / smes;
        float valpix = imgmes[ci + li * nbmesy];
        //printf("%f\n", valpix);
        if (valpix < pixthr){
            pixactivity[i] = 0;
            for (size_t mu = 0; mu < sker2; ++mu)
            {
                int ind = mu + i * sker2;
                mu_albe_A[ind] = 1e2;
                mu_albe_B[ind] = 0;
                mu_beal_A[ind] = 1e2;
                mu_beal_B[ind] = 0;
                P_albe_A[ind] = 1e2;
                P_albe_B[ind] = 0;
                abeal[ind] = 0;
                vbeal[ind] = 1e-2;
            }
            P_be_E[i] = 1e2;
            P_be_F[i] = 0;
        } else {
            pixactivity[i] = 1;
            activepix[nbact] = i;
            nbact++;
        }
    }

    //printf("nbact: %i\n", nbact);

    /* Main loop */
    for (int iter = 0; iter < nbiter; ++iter)
    {
        //printf("iteration: %i\n", iter); 
        /* Internal loop */
        for (unsigned int j = 0; j < nbintern; ++j)
        {
            double relerr = 1;
            update_mubeal(vbeal, abeal,
                    mu_beal_A, mu_beal_B,
                    mu_albe_A, mu_albe_B,
                    P_be_E, P_be_F,
                    nbact, activepix);

            relerr = update_mualbe(mu_albe_A, mu_albe_B,
                    mu_beal_A, mu_beal_B,
                    P_albe_A, P_albe_B,
                    abeal, vbeal,
                    P_be_E, P_be_F,
                    omegamu, vmu,
                    ker, ker2,
                    imgnoise, imgmes,
                    nbact, activepix);
            //printf("relerr: %f\n", relerr);
        }

        /* External loop */
        //printf("updatePbe\n");
        int iterpbe = 1;

        update_pbe(P_be_E, P_be_F,
                P_albe_A, P_albe_B,
                abeal, vbeal,
                omegamu, vmu,
                mu_beal_A, mu_beal_B,
                ker, ker2,
                imgnoise, imgmes,
                nbact, activepix,
                iterpbe);

        /* Build result */
        if (printres){
            for (int i = 0; i < size2; ++i)
            {
                res[i] = P_be_F[i] / P_be_E[i];
                //if (res[i] > 45){
                //    printf("%f %f\n", P_be_F[i], P_be_E[i]);
                //}
            }
            printf("res min, max: %f %f\n",                                            
                    min(res, size2),                                               
                    max(res, size2));
            //plot_overlay(imgmes, res, "overlay.png");
        }
    }

    /* Build result */
    //for (int i = 0; i < size2; ++i)
    //{
    //    res[i] = 1 / P_be_E[i];
    //}
    //printf("var min, max: %f %f\n",                                            
    //        min(res, size2),                                               
    //        max(res, size2));
    //plot_image(sizex, sizey, res, "var.png", plot_rescale);
    //printf("Brecs, frame, xnano, ynano, znano, intensity\n");
    int nbfluo = 1;
    for (int i = 0; i < size2; ++i)
    {
        int c = i % sizey;
        int l = i / sizey;
        res[i] = P_be_F[i] / P_be_E[i];
        if (res[i] > thrpoint){
            printf("%i %i %.2f %.2f %.2f %.2f\n",
                   nbfluo,
                   nbframe,
                   c * spix + spix / 2,
                   //l * spix + 64 * 8 * spix + spix / 2,
                   l * spix + spix / 2,
                   0.00,
                   res[i]);
            nbfluo++;
        }
    }
    //printf("res min, max: %f %f\n",                                            
    //        min(res, size2),                                               
    //        max(res, size2));

    free(mu_albe_A);
    free(mu_albe_B);
    free(mu_beal_A);
    free(mu_beal_B);
    free(P_albe_A);
    free(P_albe_B);
    free(abeal);
    free(vbeal);
    free(P_be_E);
    free(P_be_F);
    free(omegamu);
    free(vmu);
    free(pixactivity);

    free(ker);
    free(ker2);

    return res;
}

float max(float * img, int size)
{
    float max = img[0];
    for (int i = 1; i < size; ++i)
    {
        if (img[i] > max) max = img[i];
    }

    return max;
}

float min(float * img, int size)
{
    float min = img[0];
    for (int i = 1; i < size; ++i)
    {
        if (img[i] < min) min = img[i];
    }

    return min;
}

float maxra(float * num, float * den, int size)
{
    float max = num[0] / den[0];
    for (int i = 1; i < size; ++i)
    {
        if (num[i] / den[i] > max) max = num[i] / den[i];
    }

    return max;
}

float minra(float * num, float * den, int size)
{
    float min = num[0] / den[0];
    for (int i = 1; i < size; ++i)
    {
        if (num[i] / den[i] < min) min = num[i] / den[i];
    }

    return min;
}

uint16_t * opentiff(const char * fname, int sx, int sy)
{
    uint16_t * img = malloc(sx * sy * sizeof(uint16_t));

    TIFF * tif = TIFFOpen(fname, "r");
    if (tif) {
        uint32 imagelength;
        tsize_t scanline;
        tdata_t buf;
        uint32 row;
        uint32 col;

        TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imagelength);
        if (imagelength != sx) exit(EXIT_FAILURE);
        scanline = TIFFScanlineSize(tif);
        if (scanline / 2 != sy) exit(EXIT_FAILURE);
        //printf("image length: %i\n", imagelength);
        //printf("scanline: %li\n", scanline);
        buf = _TIFFmalloc(scanline);
        for (row = 0; row < imagelength; row++)
        {
            TIFFReadScanline(tif, buf, row, 0);
            for (col = 0; col < scanline / 2; col++)
                img[col + row * scanline / 2] = ((uint16 *)buf)[col];
        }
        _TIFFfree(buf);
        TIFFClose(tif);
    } else {
        exit(EXIT_FAILURE);
    }

    return img;
}

float valuearound(float * img, int sx, int sy, int x, int y , float rad2)
{
    float sum = 0;
    for (unsigned int i = 0; i < sx; ++i)
    {
        for (unsigned int j = 0; j < sy; ++j)
        {
            float r2 = (i - x) * (i - x) + (j - y) * (j - y);
            if (r2 < rad2) sum += img[j + i * sy];
        }
    }

    return sum;
}

int main(int argc, char ** argv)
{
    //FILE * fimg;
    uint16_t * img;
    float * imgmes;
    float * imgker;

    float * imgnoise;
    float * imgrecons;

    _MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() & ~_MM_MASK_INVALID);

    /* Command line parser */
    if (cmdline_parser(argc, argv, & bstorm_args) != 0)
        exit(EXIT_FAILURE);

    updatetemp(beta);

    nbframe = bstorm_args.frame_arg;
    char fname[100];
    snprintf(fname, 100, "%05i.tif", nbframe);
    //printf("%s\n", fname);

    img = opentiff(fname,
                   bstorm_args.size_arg, bstorm_args.size_arg);
    
    /* enable floating point exceptions */
    //feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW);

    //img = malloc(width * height * sizeof(uint16_t));
    posix_memalign((void **)&imgmes, 16, nbmes2 * sizeof(float));
    posix_memalign((void **)&imgnoise, 16, nbmes2 * sizeof(float));

    imgker = malloc(size2 * sizeof(float));
    
    //fimg = fopen(fname, "rb");

    long int offset = bstorm_args.picnb_arg;
    //fseek(fimg, width * height * 2 * offset, SEEK_SET);
    //fread(img, 2, width * height, fimg);
    //fclose(fimg);

    for (unsigned int i = 0; i < nbmes2; ++i)
    {
        //imgnoise[i] = 990;
        imgnoise[i] = noiseback;
        imgmes[i] = 0;
    }
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j){
            float val = (img[i + j * width]);

            //imgnoise[i + j * nbmesy] = val + 2;
            float pixmes = val - meanback;
            //if (pixmes < 0) pixmes = 0;
            imgmes[i + sker / 2 - 1 + (j + sker / 2 - 1) * nbmesy] = pixmes;
            //printf("%f\n", pixmes);
        }
    }

    //plot_image(height, width, imgmes, "imgtry.png", plot_rescale);

    //printf("valuearound: %f\n", valuearound(imgmes, nbmesx, nbmesy, 130, 31 , 10));
    //printf("valuearound: %f\n", valuearound(imgmes, nbmesx, nbmesy, 154, 61 , 10));
    //printf("valuearound: %f\n", valuearound(imgmes, nbmesx, nbmesy, 168, 106 , 10));
    //printf("valuearound: %f\n", valuearound(imgmes, nbmesx, nbmesy, 170, 120 , 10));
    //printf("valuearound: %f\n", valuearound(imgmes, nbmesx, nbmesy, 50, 50 , 10));
    //printf("valuearound: %f\n", valuearound(imgmes, nbmesx, nbmesy, 200, 200 , 10));
    //printf("valuearound: %f\n", valuearound(imgmes, nbmesx, nbmesy, 100, 100 , 10));

    gaussker(imgker);
    /*
    float sum = 0;
    for (unsigned int i = 0; i < size2; ++i)
    {
        sum += imgker[i];
    }
    printf("%f\n", sum);
    */
    //plot_image(sizex, sizey, imgker, "gaussker.png", plot_rescale);
    
    plot_image(nbmesx, nbmesy, imgmes, "imgmesfull.png", plot_rescale);

    imgrecons = reconssparse(imgmes, imgnoise, imgker);
    //imgrecons = recons(imgmes, imgnoise, imgker);

    plot_image(sizex, sizey, imgrecons, "recons.png", plot_rescale);
    plot_overlay(imgmes, imgrecons, "overlay.png");
    
    //char fname[100];
    //snprintf(fname, 100, "img-%li.dat.bz2", offset);
    //saveimage(imgrecons, size2, fname);

    free(img);
    free(imgker);
    free(imgmes);
    free(imgnoise);
    
    return EXIT_SUCCESS;
}
