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

#include <cpuid.h> /* __get_cpuid_max, __get_cpuid */
#include <mmintrin.h> /* MMX instrinsics  __m64 integer type  */
#include <xmmintrin.h> /* SSE  __m128  float */
#include <pmmintrin.h>

/* Floating point control */
#define __USE_GNU
#include <fenv.h>

#include <bzlib.h>

#include "cmdline.h"
#include "Bstorm.h"

/* Command line variable */
struct gengetopt_args_info bstorm_args;

/* Constant definitions */


/* signal noise properties */
const float pixmean = 4000;
const double pixstd = 3000;
const double rho = 0.002;
float thrA = 0.1 / (10 * 4000 * 4000);

const float pixthr = 40;

/* Sizes of the images */
const int smes = 8;
const int smes2 = 8 * 8;
const int sizex = 212 * 8;
const int sizey = 340 * 8;
const int size2 = 212 * 8 * 340 * 8;
const int sker = 8; /* has to be a multiple of 4 to use sse */
const int sker2 = 8 * 8;

const int nbmesx = 212;
const int nbmesy = 340;
const int nbmes2 = 212 * 340;

const int plot_no_rescale = 0;
const int plot_rescale = 1;


/* Properties of the psf */
const float sigpsf = 1.04 * 8; /* size of a pixel in unit of lambda */
const float numap = 1.0;

const int nbiter = 1;

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
            if (pred[x * sizey + y] > 20){
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
        printf("%i %i\n", i, j);
        BZ2_bzWrite ( &bzerror, b, buf, i);
        if (bzerror == BZ_IO_ERROR) { 
            BZ2_bzWriteClose(&bzerror, b, 0, NULL, NULL);
            exit(EXIT_FAILURE);
        }
        nbtot += i;
    }
    printf("%i\n", nbtot);

    BZ2_bzWriteClose(&bzerror, b, 0, NULL, NULL);
    if (bzerror == BZ_IO_ERROR) {
            exit(EXIT_FAILURE);
    }
    printf("Exit cleanly\n");
}


void fafcfunc(float * out, float sig2, float r)
{
    float pstd2 = pixstd * pixstd;

    float deltr = (r - pixmean) * (r - pixmean);
    float varr = sig2 + pstd2;

    float fra = sqrt(sig2 / varr);
    float fra1 = fra / varr;
    float fra2 = fra1 / varr;

    float exprgauss = exp(-r * r / 2 / sig2 + deltr / 2 / varr);

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

    //if (out[1] < 1e-4) out[1] = 1e-4;
    if (out[0] < 0) out[0] = 0;
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
                     int * pixactivity)
{
    const __m128 zero = _mm_set1_ps(0);

    for (int mu = 0; mu < nbmes2; mu += 4)
    {
        _mm_store_ps(vmu + mu, zero);
        _mm_store_ps(omegamu + mu, zero);
    }
    for (size_t i = 0; i < size2; ++i)
    {
        if (pixactivity[i]){
            float * cabeal = abeal + i * sker2;
            float * cvbeal = vbeal + i * sker2;


            int ci = (i % sizey) % smes;
            int li = (i / sizey) % smes;
            int ikeri = ci + li * smes;

            float * cker = ker + ikeri * sker2;
            float * cker2 = ker2 + ikeri * sker2;

            for (int mu = 0; mu < sker2; ++mu)
            {
                int dcmu = mu % sker - sker / 2;
                int dlmu = mu / sker - sker / 2;

                int cmu = (i % sizey) / smes + dcmu;
                int lmu = (i / sizey) / smes + dlmu;
                int imu = cmu + lmu * nbmesy;

                omegamu[imu] += cker[mu] * cabeal[mu];
                vmu[imu] += cker2[mu] * cvbeal[mu];
            }
        }
    }
    /*
     * Difficult to parallelize due to alignment problem...
    for (size_t i = 0; i < size2; ++i)
    {
        if (pixactivity[i]){
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

                __m128 o = _mm_mul_ps(ck, ca);
                __m128 v = _mm_mul_ps(ck2, cv);

                __m128 po =  _mm_load_ps(omegamu + imu);
                __m128 pv =  _mm_load_ps(omegamu + imu);

                o = _mm_add_ps(o, po);
                v = _mm_add_ps(o, po);

                _mm_store_ps(omegamu + imu, o);
                _mm_store_ps(vmu + imu, v);
            }
        }
    }
    */
}

double update_mualbe(float * mu_albe_A, float * mu_albe_B,
                     float * mu_beal_A, float * mu_beal_B,
                     float * P_albe_A, float * P_albe_B,
                     float * abeal, float * vbeal,
                     float * P_be_E, float * P_be_F,
                     float * omegamu, float * vmu,
                     float * ker, float * ker2,
                     float * imgnoise, float * imgmes,
                     int * pixactivity)
{
    float rat = ((float)sker2 - 1) / sker2;
    double relerr = 0;
    update_omegavmu(omegamu, vmu, ker, ker2, abeal, vbeal, pixactivity);
    /*
    printf("omegamu min, max: %f %f\n",                                            
           min(omegamu, nbmes2),                                               
           max(omegamu, nbmes2));
    printf("vmu min, max: %f %f\n",                                            
           min(vmu, nbmes2),                                               
           max(vmu, nbmes2));
    */

    for (size_t i = 0; i < size2; ++i)
    {
        if (pixactivity[i]){
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

            //const __m128 rPE = _mm_set1_ps(rat * P_be_E[i]);
            //const __m128 rPF = _mm_set1_ps(rat * P_be_F[i]);

            //const __m128 epserr = _mm_set1_ps(1e-6);

            for (int mu = 0; mu < sker2; ++mu)
            {

                int dcmu = mu % sker - sker / 2;
                int dlmu = mu / sker - sker / 2;

                int cmu = (i % sizey) / smes + dcmu;
                int lmu = (i / sizey) / smes + dlmu;
                int imu = cmu + lmu * nbmesy;

                float den;

                den = imgnoise[imu] + vmu[imu] - cker2[mu] * cvbeal[mu];

                float bnum;
                bnum = cker[mu] *
                    (imgmes[imu] - omegamu[imu] + cker[mu] * cabeal[mu]);

                float valA = cker2[mu] / den + rat * P_be_E[i] + cbA[mu];
                float errt = fabs((valA - cPA[mu]) / (valA + cPA[mu]));
                if (errt > relerr && valA > thrA * 10) relerr = errt;
                cPA[mu] = valA;

                float valB = bnum / den + rat * P_be_F[i] + cbB[mu];
                float denerr = fabs(valB + cPB[mu]);
                if (denerr < 1e-6) denerr = 1e-6;
                errt = fabs(valB - cPB[mu]) / denerr;
                if (errt > relerr && valB > 0) relerr = errt;
                cPB[mu] = valB;
                //if (cPA[mu] < thrA) cPA[mu] = thrA;
                if (cPB[mu] < 0) cPB[mu] = 0;
            }

            /*
            for (int mu = 0; mu < sker2; mu += 4)
            {
                int dcmu = mu % sker - sker / 2;
                int dlmu = mu / sker - sker / 2;

                int cmu = (i % sizey) / smes + dcmu;
                int lmu = (i / sizey) / smes + dlmu;
                int imu = cmu + lmu * nbmesy;

                __m128 den = _mm_load_ps(imgnoise + imu);
                __m128 v = _mm_load_ps(vmu + imu);
                __m128 k2 = _mm_load_ps(cker2 + mu);
                __m128 k = _mm_load_ps(cker + mu);
                __m128 vb = _mm_load_ps(cvbeal + mu);

                den = _mm_add_ps(den, v);
                vb = _mm_mul_ps(k2, vb);
                den = _mm_sub_ps(den, vb);

                //den = imgnoise[imu] + vmu[imu] - cker2[mu] * cvbeal[mu];

                __m128 bnum = _mm_load_ps(imgmes + imu);
                __m128 om = _mm_load_ps(omegamu + imu);

                __m128 ab = _mm_load_ps(cabeal + mu);

                k = _mm_mul_ps(k, ab);
                bnum = _mm_sub_ps(bnum, om);
                bnum = _mm_add_ps(bnum, k);

                //float bnum;
                //bnum = cker[mu] *
                //    (imgmes[imu] - omegamu[imu] + cker[mu] * cabeal[mu]);

                __m128 valA = _mm_div_ps(k2, den);
                valA = _mm_add_ps(valA, rPE);
                __m128 ibA = _mm_load_ps(cbA + mu);
                valA = _mm_add_ps(valA, ibA);

                //float valA = cker2[mu] / den + rat * P_be_E[i] + cbA[mu];

                __m128 c = _mm_load_ps(cPA + mu);
                __m128 n = _mm_sub_ps(valA, c);
                //__m128 n = valA - c;
                __m128 d = _mm_add_ps(valA, c);
                d = _mm_max_ps(epserr, d);
                __m128 errt = _mm_div_ps(n, d);

                //float errt = fabs((valA - cPA[mu]) / (valA + cPA[mu]));
                if (errt > relerr && valA > thrA * 10) relerr = errt;
                _mm_store_ps(cPA + mu, valA);
                //cPA[mu] = valA;

                __m128 valB = _mm_div_ps(bnum, den);
                valB = _mm_add_ps(valB, rPF);
                __m128 ibB = _mm_load_ps(cbB + mu);
                valB = _mm_add_ps(valB, ibB);
                //float valB = bnum / den + rat * P_be_F[i] + cbB[mu];
                float denerr = fabs(valB + cPB[mu]);
                if (denerr < 1e-2) denerr = 1e-2;
                errt = fabs(valB - cPB[mu]) / denerr;
                if (errt > relerr && valB > 0) relerr = errt;
                cPB[mu] = valB;
                //if (cPA[mu] < thrA) cPA[mu] = thrA;
                if (cPB[mu] < 0) cPB[mu] = 0;
            }
            */
        }
    }
    for (size_t i = 0; i < size2; ++i)
    {
        if (pixactivity[i]){
            const __m128 zero = _mm_set1_ps(0);
            const __m128 vthr = _mm_set1_ps(thrA);
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
                B = _mm_max_ps(zero, B);

                _mm_store_ps(caA + mu, A);
                _mm_store_ps(caB + mu, B);
            }
        }
    }
    /*
    for (size_t i = 0; i < size2; ++i)
    {
        if (pixactivity[i]){
            float P_al_A = 0;
            float P_al_B = 0;
            for (int mu = 0; mu < sker2; ++mu)
            {
                int indalbe = mu + i * sker2;
                P_al_A += P_albe_A[indalbe];
                P_al_B += P_albe_B[indalbe];
            }
            P_al_A /= sker2;
            P_al_B /= sker2;
            if (P_al_B < 0) P_al_B = 0;
            if (P_al_A < thrA) P_al_A = thrA;

            for (int mu = 0; mu < sker2; ++mu)
            {
                int indav = mu + sker2 * i;

                float vA = P_albe_A[indav] - P_al_A + init_E[i] - mu_beal_A[indav];
                float vB = P_albe_B[indav] - P_al_B + init_F[i] - mu_beal_B[indav];
                //mu_albe_A[indav] = 0.9 * mu_albe_A[indav] + 0.1 * vA;
                //mu_albe_B[indav] = 0.9 * mu_albe_B[indav] + 0.1 * vB;
                mu_albe_A[indav] = vA;
                mu_albe_B[indav] = vB;
                if (mu_albe_B[indav] < 0) mu_albe_B[indav] = 0;

            }
        }
    }
    */
    return relerr;
}

float update_Palbe(float * mu_beal_A, float * mu_beal_B,
                    float * P_albe_A, float * P_albe_B,
                    float * abeal, float * vbeal,
                    float * P_be_E, float * P_be_F,
                    float * omegamu, float * vmu,
                    float * ker, float * ker2,
                    float * imgnoise, float * imgmes,
                    int * pixactivity)
{
    float rat = ((float)sker2 - 1) / sker2;
    float relerr = 0;
    update_omegavmu(omegamu, vmu, ker, ker2, abeal, vbeal, pixactivity);
    /*
    printf("omegamu min, max: %f %f\n",                                            
           min(omegamu, nbmes2),                                               
           max(omegamu, nbmes2));
    printf("vmu min, max: %f %f\n",                                            
           min(vmu, nbmes2),                                               
           max(vmu, nbmes2));
    */

    for (size_t i = 0; i < size2; ++i)
    {
        if (pixactivity[i]){
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

            for (int mu = 0; mu < sker2; ++mu)
            {
                int dcmu = mu % sker - sker / 2;
                int dlmu = mu / sker - sker / 2;

                int cmu = (i % sizey) / smes + dcmu;
                int lmu = (i / sizey) / smes + dlmu;
                int imu = cmu + lmu * nbmesy;

                float den;

                den = imgnoise[imu] + vmu[imu] - cker2[mu] * cvbeal[mu];

                float bnum;
                bnum = cker[mu] *
                    (imgmes[imu] - omegamu[imu] + cker[mu] * cabeal[mu]);

                float valA = cker2[mu] / den + rat * P_be_E[i] + cbA[mu];
                float errt = fabs((valA - cPA[mu]) / (valA + cPA[mu]));
                if (errt > relerr) relerr = errt;
                cPA[mu] = valA;

                float valB = bnum / den + rat * P_be_F[i] + cbB[mu];
                float denerr = fabs(valB + cPB[mu]);
                if (denerr < 1e-6) denerr = 1e-6;
                errt = fabs(valB - cPB[mu]) / denerr;
                if (errt > relerr && valB > 0) relerr = errt;
                cPB[mu] = valB;
                //if (cPA[mu] < thrA) cPA[mu] = thrA;
                if (cPB[mu] < 0) cPB[mu] = 0;
            }
        }
    }
    return relerr;
}

void update_mubeal(float * vbeal, float * abeal,
                   float * mu_beal_A, float * mu_beal_B,
                   float * mu_albe_A, float * mu_albe_B,
                   float * P_be_E, float * P_be_F,
                   int * pixactivity)
{
    float rat = ((float)sker2 - 1) / sker2;
    for (size_t i = 0; i < size2; ++i)
    {
        if (pixactivity[i]){
            float * caA = mu_albe_A + i * sker2;
            float * caB = mu_albe_B + i * sker2;
            float * cbA = mu_beal_A + i * sker2;
            float * cbB = mu_beal_B + i * sker2;
            float * cabeal = abeal + i * sker2;
            float * cvbeal = vbeal + i * sker2;

            /* Compute P_beta */
            float P_be_A = 0;
            float P_be_B = 0;
            for (size_t mu = 0; mu < sker2; ++mu)
            {
                P_be_A += caA[mu];
                P_be_B += caB[mu];
            }
            P_be_A /= sker2;
            //if (P_be_A < thrA) P_be_A = thrA;
            P_be_B /= sker2;
            if (P_be_B < 0) P_be_B = 0;

            /* Compute mu_beal */
            for (size_t mu = 0; mu < sker2; ++mu)
            {
                float cC = P_be_A - caA[mu];
                float cD = P_be_B - caB[mu];
                //if (cC < thrA) cC = thrA;
                if (cD < 0) cD = 0;
                cbA[mu] = cC;
                cbB[mu] = cD;
                cvbeal[mu] = 1.0 / (cC + rat * P_be_E[i]);
                cabeal[mu] = (cD + rat * P_be_F[i]) * cvbeal[mu];
            }
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
                int * pixactivity,
                float damp, int iterpbe)
{
    /* The coefficient should be equal after convergence, we choose to take
     * the average of the coefficients here...
     * This is the logarithmic average instead of the normal average, this
     * should not make a difference at convergence.
     */
    float relerr = 1.0;
    //while (relerr > 5e-2)
    for (size_t iter = 0; iter < iterpbe; ++iter)
    {
        for (size_t i = 0; i < size2; ++i)
        {
            if (pixactivity[i]){
                float avA = 0;
                float avB = 0;
                float * cA = P_albe_A + i * sker2;
                float * cB = P_albe_B + i * sker2;
                for (size_t mu = 0; mu < sker2; ++mu)
                {
                    avA += cA[mu];
                    avB += cB[mu];
                }
                float PEt = avA  - (sker2 - 1) * P_be_E[i];
                float PFt = avB  - (sker2 - 1) * P_be_F[i];
                //if (PEt < thrA * 10) PEt = thrA * 10;
                if (PFt < 0) PFt = 0;

                float fafc[2];
                fafcfunc(fafc, 1 / PEt, PFt / PEt);

                float invE = (1 - damp) / P_be_E[i] + damp * fafc[1];
                //float invE = fafc[1];
                P_be_E[i]= 1/ invE;
                //P_be_E[i]= 1 / fafc[1];
                P_be_F[i] = (1 - damp) * P_be_F[i] + damp * fafc[0] / fafc[1];
                //P_be_F[i] = fafc[0] / fafc[1];
            }
        }
        relerr = update_Palbe(mu_beal_A, mu_beal_B,
                              P_albe_A, P_albe_B,
                              abeal, vbeal,
                              P_be_E, P_be_F,
                              omegamu, vmu,
                              ker, ker2,
                              imgnoise, imgmes,
                              pixactivity);
        printf("relerr: %f\n", relerr);
        printf("Palbevar min, max: %f %f\n",                                            
                1 / min(P_albe_A, size2 * sker2),
                1 / max(P_albe_A, size2 * sker2));
        printf("PalbeB min, max: %f %f\n",                                            
                min(P_albe_B, size2 * sker2),
                max(P_albe_B, size2 * sker2));
        printf("P_be_var min, max: %f %f\n",                                            
                1 / min(P_be_E, size2),
                1 / max(P_be_E, size2));
        printf("P_be_F min, max: %f %f\n",                                            
                min(P_be_F, size2),
                max(P_be_F, size2));
    }
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

    posix_memalign((void **)&ker, 16, smes2 * sker2 * sizeof(float));
    posix_memalign((void **)&ker2, 16, smes2 * sker2 * sizeof(float));

    posix_memalign((void **)&res, 16, size2 * sizeof(float));

    /* Initialize kernels */
    init_kernels(ker, ker2, psf);
    printf("Ker min, max: %f %f\n",                                            
           min(ker, smes2 * sker2),                                               
           max(ker, smes2 * sker2));
    printf("imgmes min, max: %f %f\n",                                            
           min(imgmes, nbmes2),                                               
           max(imgmes, nbmes2));
    printf("imgnoise min, max: %f %f\n",                                            
           min(imgnoise, nbmes2),                                               
           max(imgnoise, nbmes2));
    //plot_image(smes * sker, smes * sker, ker, "kerint.png", plot_rescale);

    //plot_image(sker, sker, ker + 32 * sker2, "kercent.png", plot_rescale);

    float Ainit = 300.0 / (pixmean * pixmean);
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
    printf("ABinit: %f %f\n", Ainit, Binit);

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
        }
    }

    int nbact = 0;
    for (int i = 0; i < size2; ++i)
    {
        if (pixactivity[i]) nbact++;
    }
    printf("nbact: %i\n", nbact);

    /* Main loop */
    for (int iter = 0; iter < nbiter; ++iter)
    {
        printf("iteration: %i\n", iter); 
        /* Internal loop */
        double relerr = 1;
        int nbinw = 0;
        //while (relerr > 1e-1 && nbinw < 10){
            update_mubeal(vbeal, abeal,
                          mu_beal_A, mu_beal_B,
                          mu_albe_A, mu_albe_B,
                          P_be_E, P_be_F,
                          pixactivity);
            /*
               printf("abeal min, max: %f %f\n",                                            
               min(abeal, size2 * sker2),                                               
               max(abeal, size2 * sker2));
               printf("vbeal min, max: %f %f\n",                                            
               min(vbeal, size2 * sker2),                                               
               max(vbeal, size2 * sker2));
               */

            relerr = update_mualbe(mu_albe_A, mu_albe_B,
                                   mu_beal_A, mu_beal_B,
                                   P_albe_A, P_albe_B,
                                   abeal, vbeal,
                                   P_be_E, P_be_F,
                                   omegamu, vmu,
                                   ker, ker2,
                                   imgnoise, imgmes,
                                   pixactivity);
            printf("relerr: %f\n", relerr);
            printf("Palbevar min, max: %f %f\n",                                            
                   1 / min(P_albe_A, size2 * sker2),
                   1 / max(P_albe_A, size2 * sker2));
            printf("PalbeB min, max: %f %f\n",                                            
                   min(P_albe_B, size2 * sker2),
                   max(P_albe_B, size2 * sker2));
            printf("PalbeBoA min, max: %f %f\n",                                            
                   minra(P_albe_B, P_albe_A, size2 * sker2),
                   maxra(P_albe_B, P_albe_A, size2 * sker2));
            nbinw++;
        //}

        /* External loop */
        printf("updatePbe\n");
        //float damp = 0.005;
        //int iterpbe = 20;
        float damp = 0.1;
        int iterpbe = 1;
        //if (iter < 5){
        //    damp = 0.02;
        //    iterpbe = 1;
        //}
        //if (iter < 30){
        //    damp = 0.1;
        //    iterpbe = 1;
        //}
        //if (iter < 20) damp = 0.002;
        //if (iter < 20) damp = 0.03;
        //if (iter < 100) damp = 0.05;

        update_pbe(P_be_E, P_be_F,
                P_albe_A, P_albe_B,
                abeal, vbeal,
                omegamu, vmu,
                mu_beal_A, mu_beal_B,
                ker, ker2,
                imgnoise, imgmes,
                pixactivity,
                damp, iterpbe);

        for (int i = 0; i < size2; ++i)
        {
            res[i] = P_be_F[i] / P_be_E[i];
        }
        plot_overlay(imgmes, res, "overlay.png");
    }


    /* Build result */
    for (int i = 0; i < size2; ++i)
    {
        res[i] = P_be_F[i] / P_be_E[i];
    }
    printf("F min, max: %f %f\n",                                            
            min(P_be_F, size2),                                               
            max(P_be_F, size2));
    printf("E min, max: %f %f\n",                                            
            min(P_be_E, size2),                                               
            max(P_be_E, size2));
    printf("res min, max: %f %f\n",                                            
            min(res, size2),                                               
            max(res, size2));

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

const int width = 329;
const int height = 199;

const float meanback = 110;

int main(int argc, char ** argv)
{
    FILE * fimg;
    uint16_t * img;
    float * imgmes;
    float * imgker;

    float * imgnoise;
    float * imgrecons;

    /* Command line parser */
    if (cmdline_parser(argc, argv, & bstorm_args) != 0)
        exit(EXIT_FAILURE);
    
    /* enable floating point exceptions */
    //feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW);

    img = malloc(width * height * sizeof(uint16_t));
    posix_memalign((void **)&imgmes, 16, nbmes2 * sizeof(float));
    posix_memalign((void **)&imgnoise, 16, nbmes2 * sizeof(float));

    imgker = malloc(size2 * sizeof(float));
    

    fimg = fopen(bstorm_args.file_arg, "rb");

    int offset = bstorm_args.picnb_arg;
    fseek(fimg, width * height * 2 * offset, SEEK_SET);
    fread(img, 2, width * height, fimg);
    //printf("%i\n", readb);

    //printf("%i %i\n", img[0], img[1]);

    for (unsigned int i = 0; i < nbmes2; ++i)
    {
        imgnoise[i] = 1e5;
        imgmes[i] = 0;
    }
    for (unsigned int i = 0; i < width / 3; ++i) {
        for (unsigned int j = 2 * height / 3; j < height; ++j){
            float val = (img[i + j * width] - 300) / 18.8;

            imgnoise[i + sker / 2 + (j + sker / 2) * nbmesy] = val;
            float pixmes = val - meanback;
            if (pixmes < 0) pixmes = 0;
            imgmes[i + sker / 2 + (j + sker / 2) * nbmesy] = pixmes;
        }
    }

    plot_image(height, width, imgmes, "imgtry.png", plot_rescale);

    gaussker(imgker);
    float sum = 0;
    for (unsigned int i = 0; i < size2; ++i)
    {
        sum += imgker[i];
    }
    printf("%f\n", sum);
    plot_image(sizex, sizey, imgker, "gaussker.png", plot_rescale);
    
    plot_image(nbmesx, nbmesy, imgmes, "imgmesfull.png", plot_rescale);

    imgrecons = reconssparse(imgmes, imgnoise, imgker);
    //imgrecons = recons(imgmes, imgnoise, imgker);

    plot_image(sizex, sizey, imgrecons, "recons.png", plot_rescale);
    plot_overlay(imgmes, imgrecons, "overlay.png");
    saveimage(imgrecons, size2, "output.dat.bz2");
    
    return EXIT_SUCCESS;
}
