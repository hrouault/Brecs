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

#include "cmdline.h"
#include "Brecs.h"

/* Command line variable */
struct gengetopt_args_info brecs_args;

/* Constant definitions */
#include "parameters.h"

/* signal noise properties */
const float pixmean = PIXMEAN;
double pixstd = PIXSTD;
double rho = RHO;

const float pixthr = PIXTHR;

/* Sizes of the images */

const int smes = SMES;
const int smes2 = SMES * SMES;
const int smes3 = SIZEZ * SMES * SMES;
const int sizex = (NBMESX + SKER) * SMES;
const int sizey = (NBMESY + SKER) * SMES;
const int sizez = SIZEZ;
const int size2 = (NBMESX + SKER) * SMES * (NBMESY + SKER) * SMES;
const int size3 = (NBMESX + SKER) * SMES * (NBMESY + SKER) * SMES * SIZEZ;
const int sker = SKER;
const int sker2 = SKER * SKER;

const float spix = SIZEPIX / SMES;

const int nbmesx = NBMESX + SKER;
const int nbmesy = NBMESY + SKER;
const int nbmes2 = (NBMESX + SKER) * (NBMESY + SKER);

const int nbintern = 1;
float damp = DAMP;
float noiseback = NOISEBACK;

/* Properties of the psf */
#if KERNEL == 1 || KERNEL == 3
const float sigpsf = SIGPSF * SMES * DEFOCUS;
#endif

const float Ainit = AINITPFACT / (PIXMEAN * PIXMEAN);
const int nbiter = NBITER;
const float meanback = MEANBACK;
const float thrpoint = THRPOINT;
const float beta = BETA;

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

int nbframe;

void updatetemp(double b, float * imgnoise)
{
    double c = pow(RHO, b);
    rho = c / (1 + c);

    for (unsigned int i = 0; i < nbmes2; ++i)
    {
        imgnoise[i] /= b;
    }

    pixstd = PIXSTD / sqrt(b);
}


#if KERNEL == 1
void gaussker(float * ker)
{
    for (int x = -sizex / 2; x < sizex / 2 ; ++x)
    {
        float dx2 = x * x;
        for (int y = -sizey / 2; y < sizey / 2; ++y)
        {
            float dy2 = y * y;
            float radius2 = dx2 + dy2;
            float val = exp(-radius2 / 2 / (sigpsf * sigpsf))
                        / (2 * M_PI * sigpsf * sigpsf);
            int line = x;
            int col = y;
            if (x < 0) line += sizex;
            if (y < 0) col += sizey;
            
            ker[col + line * sizey] = val;
        }
    }
}
#endif

#if KERNEL == 3
void refinedker(float * ker)
{
    for (int x = -sizex / 2; x < sizex / 2 ; ++x)
    {
        float dx2 = x * x;
        for (int y = -sizey / 2; y < sizey / 2; ++y)
        {
            float dy2 = y * y;
            float radius2 = dx2 + dy2;
            float r2 = radius2 / 2 / (sigpsf * sigpsf);
            float val = (1.0 + KERC2 * r2 + KERC4 * r2 * r2
                         + KERC6 * r2 * r2 * r2 + KERC8 * r2 * r2 * r2 * r2
                         + KERC10 * r2 * r2 * r2 * r2 * r2)
                        * exp(-r2) / (2 * M_PI * sigpsf * sigpsf);
            int line = x;
            int col = y;
            if (x < 0) line += sizex;
            if (y < 0) col += sizey;
            
            ker[col + line * sizey] = val;
        }
    }
}
#endif

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
    if (flags == PLOT_RESCALE){
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

void plot_imagergb(int sx, int sy,
                   png_byte * img,
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

    png_set_IHDR(png_ptr, info_ptr, sy, sx,
                 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    png_bytep row_pointers[sx];
    for (size_t x = 0 ; x < sx ; x++) row_pointers[x] = img + 3 * x * sy;
    png_set_rows(png_ptr, info_ptr, row_pointers);

    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
}

#if KERNEL == 2
const int gibssize = GIBSSIZE;
const int gibssize2 = GIBSSIZE * GIBSSIZE;
const int gibsframe = GIBSFRAME;
void loadgibson(float * ker)
{
    float * img;

    float sum[SIZEZ];

    posix_memalign((void **)&img, ALIGNSIZE,
                   sizez * gibssize2 * sizeof(float));
    FILE * fimg = fopen("gibson.raw", "rb");
    if (!fimg) exit(EXIT_FAILURE);

    fseek(fimg, 0, SEEK_SET);
    fread(img, 4, gibssize2 * sizez, fimg);
    fclose(fimg);

    for (unsigned int z = 0; z < sizez; ++z) {
        sum[z] = 0;

        for (unsigned int i = 0; i < gibssize2; ++i) {
            sum[z] += img[i + gibssize2 * z];
        }
    }

    for (unsigned int i = 0; i < size3; ++i)
    {
        ker[i] = 0;
    }
    //plot_image(gibssize, gibssize, img, "imgfromstack.png", plot_rescale);

    for (unsigned int z = 0; z < sizez; ++z) {
        for (int x = 0; x < gibssize ; ++x)
        {
            for (int y = 0; y < gibssize; ++y)
            {
                float val = img[y + x * gibssize + z * gibssize2] / sum[z];
                int line = x - gibssize / 2;
                int col = y - gibssize / 2;
                if (line < 0) line += sizex;
                if (col < 0) col += sizey;

                ker[col + line * sizey + size2 * z] = val;
            }
        }
    }
    free(img);
}
#endif // KERNEL == 2


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
    float max2 = 0;
    float min2 = 0;
    for (i = 0 ; i < nbmes2 ; i++){
        if (max2 < mes[i]) max2 = mes[i];
        if (min2 > mes[i]) min2 = mes[i];
    }
    for (x = 0 ; x < sizex ; x++){
        for (y = 0 ; y < sizey ; y++){
            float val = pred[x * sizey + y];
            png_byte * cimgd = img_data + (x * sizey + y) * 3;
            if (val > OVERLAY_MIN_INT){
                if (val > OVERLAY_MAX_INT) val = OVERLAY_MAX_INT;
                cimgd[0] = 255 * log(val)
                           / log(OVERLAY_MAX_INT);
                cimgd[1] = 0;
                cimgd[2] = 0;
            } else {
                float val = 255 / (max2 - min2)
                    * (mes[(x / smes) * nbmesy + y / smes] - min2);
                cimgd[0] = val;
                cimgd[1] = val;
                cimgd[2] = val;
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
    if (r > 1e5) r = 1e5;
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

    if (out[0] < 0) out[0] = 0;
    if (out[1] < 1e-2) out[1] = 1e-2;
}

void init_kernels(float * ker, float * ker2,
                  float * psf)
{
    for (int i = 0; i < smes3; ++i) {
        int ci = (i % smes2) % smes;
        int li = (i % smes2) / smes;
        int z  = i / smes2;
        for (int j = 0; j < sker2; ++j) {
            int kerc = j % sker - sker / 2;
            int kerl = j / sker - sker / 2;
            float sum = 0;
            for (int k = 0; k < smes2; ++k) {
                int cli = -li + k / smes + smes * kerl;
                if (cli < 0) cli += sizex;
                int cci = -ci + k % smes + smes * kerc;
                if (cci < 0) cci += sizey;

                sum += psf[cci + sizey * cli + z * size2];
            }
            int cker = j % smes;
            int lker = j / smes;
            int indmu = cker + sker * lker;
            ker[indmu + i * sker2] = sum;
            ker2[indmu + i * sker2] = sum * sum;
        }
    }
}

void update_omegavmu(float * omegamu, float * vmu,
                     float * ker, float * ker2,
                     float * abeal, float * vbeal,
                     int nbact, int * activepix)
{
    const vecfloat zero = VFUNC(set1_ps) (0);

    for (int mu = 0; mu < nbmes2; mu += SHIFT)
    {
        VFUNC(store_ps) (vmu + mu, zero);
        VFUNC(store_ps) (omegamu + mu, zero);
    }
    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
        float * cabeal = abeal + k * sker2;
        float * cvbeal = vbeal + k * sker2;


        int z = i / size2;
        int ci = ((i % size2) % sizey) % smes;
        int li = ((i % size2) / sizey) % smes;
        int ikeri = ci + li * smes + z * smes2;

        int cmu0 = ((i % size2) % sizey) / smes;
        int lmu0 = ((i % size2) / sizey) / smes;

        float * cker = ker + ikeri * sker2;
        float * cker2 = ker2 + ikeri * sker2;

        for (int mu = 0; mu < sker2; mu += SHIFT)
        {
            int dcmu = mu % sker - sker / 2;
            int dlmu = mu / sker - sker / 2;

            int cmu = cmu0 + dcmu;
            int lmu = lmu0 + dlmu;
            int imu = cmu + lmu * nbmesy;

            vecfloat ck = VFUNC(load_ps) (cker + mu);
            vecfloat ck2 = VFUNC(load_ps) (cker2 + mu);

            vecfloat ca = VFUNC(load_ps) (cabeal + mu);
            vecfloat cv = VFUNC(load_ps) (cvbeal + mu);

            ca = VFUNC(mul_ps) (ck, ca);
            cv = VFUNC(mul_ps) (ck2, cv);

            vecfloat po =  VFUNC(loadu_ps) (omegamu + imu);
            vecfloat pv =  VFUNC(loadu_ps) (vmu + imu);

            ca = VFUNC(add_ps) (ca, po);
            cv = VFUNC(add_ps) (cv, pv);

            VFUNC(storeu_ps) (omegamu + imu, ca);
            VFUNC(storeu_ps) (vmu + imu, cv);
        }
    }
}

static inline vecfloat abs_ps(vecfloat x) {
    vecfloat sign_mask = VFUNC(set1_ps) (-0.f); // -0.f = 1 << 31
    return VFUNC(andnot_ps) (sign_mask, x);
}

static inline vecfloat sumh_ps(vecfloat x) {
#if __AVX__
    __m256 tmp = _mm256_permute2f128_ps(x, x, 1);
    tmp = _mm256_add_ps(tmp, x);
#else
    __m128 tmp = x;
#endif
    tmp = VFUNC(hadd_ps) (tmp, tmp);
    tmp = VFUNC(hadd_ps) (tmp, tmp);
    return tmp;
}

void update_Palbe(afloat * restrict mu_beal_A, afloat * restrict mu_beal_B,
                  afloat * restrict P_albe_A, afloat * restrict P_albe_B,
                  afloat * restrict abeal, afloat * restrict vbeal,
                  afloat * restrict omegamu, afloat * restrict vmu,
                  afloat * restrict ker, afloat * restrict ker2,
                  afloat * restrict imgnoise, afloat * restrict imgmes,
                  int nbact, int * activepix)
{
    const vecfloat zero = VFUNC(set1_ps) (0);
    const vecfloat one = VFUNC(set1_ps) (1.0);

    update_omegavmu(omegamu, vmu, ker, ker2, abeal, vbeal, nbact, activepix);

    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
        float * cbA = mu_beal_A + k * sker2;
        float * cbB = mu_beal_B + k * sker2;
        float * cabeal = abeal + k * sker2;
        float * cvbeal = vbeal + k * sker2;
        float * cPA = P_albe_A + k * sker2;
        float * cPB = P_albe_B + k * sker2;


        int z = i / size2;
        int ci = ((i % size2) % sizey) % smes;
        int li = ((i % size2) / sizey) % smes;
        int ikeri = ci + li * smes + z * smes2;

        int cmu0 = ((i % size2) % sizey) / smes;
        int lmu0 = ((i % size2) / sizey) / smes;

        float * cker = ker + ikeri * sker2;
        float * cker2 = ker2 + ikeri * sker2;

        for (int mu = 0; mu < sker2; mu += SHIFT)
        {
            int dcmu = mu % sker - sker / 2;
            int dlmu = mu / sker - sker / 2;

            int cmu = cmu0 + dcmu;
            int lmu = lmu0 + dlmu;
            int imu = cmu + lmu * nbmesy;

            vecfloat den = VFUNC(loadu_ps) (imgnoise + imu);
            vecfloat v = VFUNC(loadu_ps) (vmu + imu);
            vecfloat k2 = VFUNC(load_ps) (cker2 + mu);
            vecfloat k = VFUNC(load_ps) (cker + mu);
            vecfloat vb = VFUNC(load_ps) (cvbeal + mu);

            den = VFUNC(add_ps) (den, v);
            vb = VFUNC(mul_ps) (k2, vb);
            den = VFUNC(sub_ps) (den, vb);
            den = VFUNC(div_ps) (one, den);

            vecfloat bnum = VFUNC(loadu_ps) (imgmes + imu);
            vecfloat om = VFUNC(loadu_ps) (omegamu + imu);
            vecfloat ab = VFUNC(load_ps) (cabeal + mu);

            ab = VFUNC(mul_ps) (k, ab);
            bnum = VFUNC(sub_ps) (bnum, om);
            bnum = VFUNC(add_ps) (bnum, ab);
            bnum = VFUNC(mul_ps) (bnum, k);

            vecfloat valA = VFUNC(mul_ps) (k2, den);
            vecfloat ibA = VFUNC(load_ps) (cbA + mu);
            valA = VFUNC(add_ps) (valA, ibA);

            VFUNC(store_ps) (cPA + mu, valA);

            vecfloat valB = VFUNC(mul_ps) (bnum, den);
            vecfloat ibB = VFUNC(load_ps) (cbB + mu);
            valB = VFUNC(add_ps) (valB, ibB);

            VFUNC(store_ps) (cPB + mu, valB);
        }
    }
}

void update_mualbe(float * mu_albe_A, float * mu_albe_B,
                   float * mu_beal_A, float * mu_beal_B,
                   float * P_albe_A, float * P_albe_B,
                   float * abeal, float * vbeal,
                   float * omegamu, float * vmu,
                   float * ker, float * ker2,
                   float * imgnoise, float * imgmes,
                   int nbact, int * activepix)
{
    update_Palbe(mu_beal_A, mu_beal_B,
                 P_albe_A, P_albe_B,
                 abeal, vbeal,
                 omegamu, vmu,
                 ker, ker2,
                 imgnoise, imgmes,
                 nbact, activepix);

    const vecfloat zero = VFUNC(set1_ps) (0);
    const vecfloat thrB = VFUNC(set1_ps) (1e2);
    const vecfloat oneosk = VFUNC(set1_ps) (1.0f / sker2);
    for (unsigned int k = 0; k < nbact; ++k)
    {
        vecfloat PAt = VFUNC(set1_ps) (0);
        vecfloat PBt = VFUNC(set1_ps) (0);

        float * caA = mu_albe_A + k * sker2;
        float * caB = mu_albe_B + k * sker2;
        float * cPA = P_albe_A + k * sker2;
        float * cPB = P_albe_B + k * sker2;

        for (int mu = 0; mu < sker2; mu += SHIFT)
        {
            vecfloat v = VFUNC(load_ps) (cPA + mu);
            PAt = VFUNC(add_ps) (PAt, v);
            v = VFUNC(load_ps) (cPB + mu);
            PBt = VFUNC(add_ps) (PBt, v);
        }
        PAt = sumh_ps(PAt);
        PBt = sumh_ps(PBt);

        PAt = VFUNC(mul_ps ) (PAt, oneosk);
        PBt = VFUNC(mul_ps ) (PBt, oneosk);

        for (int mu = 0; mu < sker2; mu += SHIFT)
        {
            vecfloat A = VFUNC(load_ps) (cPA + mu);
            vecfloat B = VFUNC(load_ps) (cPB + mu);
            vecfloat maA = VFUNC(load_ps) (caA + mu);
            vecfloat maB = VFUNC(load_ps) (caB + mu);

            A = VFUNC(sub_ps) (A, PAt);
            B = VFUNC(sub_ps) (B, PBt);

            A = VFUNC(add_ps) (A, maA);
            B = VFUNC(add_ps) (B, maB);

            VFUNC(store_ps) (caA + mu, A);
            VFUNC(store_ps) (caB + mu, B);
        }
    }
}

void update_mubeal(float * vbeal, float * abeal,
                   float * mu_beal_A, float * mu_beal_B,
                   float * mu_albe_A, float * mu_albe_B,
                   float * P_be_E, float * P_be_F,
                   int nbact, int * activepix)
{
    float rat = ((float)sker2 - 1) / sker2;
    const vecfloat zero = VFUNC(set1_ps) (0);
    const vecfloat one = VFUNC(set1_ps) (1.0);
    const vecfloat oneosk = VFUNC(set1_ps) (1.0f / sker2);

    for (unsigned int k = 0; k < nbact; ++k)
    {
        float * caA = mu_albe_A + k * sker2;
        float * caB = mu_albe_B + k * sker2;
        float * cbA = mu_beal_A + k * sker2;
        float * cbB = mu_beal_B + k * sker2;
        float * cabeal = abeal + k * sker2;
        float * cvbeal = vbeal + k * sker2;

        /* Compute P_beta */
        vecfloat P_be_A = zero;
        vecfloat P_be_B = zero;
        for (size_t mu = 0; mu < sker2; mu += SHIFT) {
            vecfloat a = VFUNC(load_ps) (caA + mu);
            P_be_A = VFUNC(add_ps) (P_be_A, a);
            vecfloat b = VFUNC(load_ps) (caB + mu);
            P_be_B = VFUNC(add_ps) (P_be_B, b);
        }
        P_be_A = sumh_ps(P_be_A);
        P_be_B = sumh_ps(P_be_B);

        P_be_A = VFUNC(mul_ps ) (P_be_A, oneosk);
        P_be_B = VFUNC(mul_ps ) (P_be_B, oneosk);

        const vecfloat rPE = VFUNC(set1_ps) (rat * P_be_E[k]);
        const vecfloat rPF = VFUNC(set1_ps) (rat * P_be_F[k]);

        /* Compute mu_beal */
        for (size_t mu = 0; mu < sker2; mu += SHIFT) {
            vecfloat cC = VFUNC(load_ps) (caA + mu);
            cC = VFUNC(sub_ps) (P_be_A, cC);
            vecfloat cD = VFUNC(load_ps) (caB + mu);
            cD = VFUNC(sub_ps) (P_be_B, cD);

            VFUNC(store_ps) (cbA + mu, cC);
            VFUNC(store_ps) (cbB + mu, cD);

            cC = VFUNC(add_ps) (rPE, cC);
            cC = VFUNC(div_ps) (one, cC);

            cD = VFUNC(add_ps) (rPF, cD);
            cD = VFUNC(mul_ps) (cC, cD);

            VFUNC(store_ps) (cvbeal + mu, cC);
            VFUNC(store_ps) (cabeal + mu, cD);
        }
    }
}

float update_pbe(float * P_be_E, float * P_be_F,
                 float * P_albe_A, float * P_albe_B,
                 int nbact, int * activepix,
                 int iterpbe)
{
    /* The coefficient should be equal after convergence, we choose to take
     * the average of the coefficients here...
     * This is the logarithmic average instead of the normal average, this
     * should not make a difference at convergence.
     */
    float relerr = 0.0;
    int nberr = 0;
    float errmeantot = 0;
    float errvartot = 0;
    for (unsigned int k = 0; k < nbact; ++k)
    {
        float * cA = P_albe_A + k * sker2;
        float * cB = P_albe_B + k * sker2;

        vecfloat vPEt = VFUNC(set1_ps) (0);
        vecfloat vPFt = VFUNC(set1_ps) (0);
        for (size_t mu = 0; mu < sker2; mu += SHIFT)
        {
            vecfloat e = VFUNC(load_ps) (cA + mu);
            vPEt = VFUNC(add_ps) (vPEt, e);
            vecfloat f = VFUNC(load_ps) (cB + mu);
            vPFt = VFUNC(add_ps) (vPFt, f);
        }
        vPEt = sumh_ps(vPEt);
        vPFt = sumh_ps(vPFt);
        float tmp[SHIFT];
        VFUNC(storeu_ps) (tmp, vPEt);
        float PEt = tmp[0];
        VFUNC(storeu_ps) (tmp, vPFt);
        float PFt = tmp[0];

        if (PFt < 0) PFt = 0;

        if (P_be_E[k] < 1e-7) P_be_E[k] = 1e-7;
        float prevPbE = P_be_E[k];
        float prevPbF = P_be_F[k];

        float fafc[2];
        fafcfunc(fafc, 1 / PEt, PFt / PEt);

        //if (fafc[1] > 1 && fafc[1] * prevPbE > 1.2) fafc[1] = 1.2 / prevPbE;
        //if (fafc[1] > 1 && fafc[1] * prevPbE < 0.2) fafc[1] = 0.2 / prevPbE;
        //if (fafc[0] > 1 && fafc[0] * prevPbE / prevPbF > 1.2) fafc[0] = 1.2 * prevPbF / prevPbE;
        //if (fafc[0] > 1 && fafc[0] * prevPbE / prevPbF < 0.2) fafc[0] = 0.2 * prevPbF / prevPbE;

        damp = 0.05;
        float invE = (1 - damp) / P_be_E[k] + damp * fafc[1];
        P_be_E[k]= 1 / invE;
        damp = 0.15;
        P_be_F[k] = (1 - damp) * P_be_F[k] / invE / prevPbE
            + damp * fafc[0] / invE;

        float var = invE;
        float mean = P_be_F[k] * invE;
        float oldvar = 1 / prevPbE;
        float errvar = fabsf(fafc[1] - 1 / prevPbE) / (fafc[1] + 1 / prevPbE);
        float errmean = fabsf(fafc[0] - prevPbF / prevPbE) / (fafc[0] + prevPbF / prevPbE);
        if (errvar > relerr && fafc[1] > 10){
            relerr = errvar;
        }
        if (errmean > relerr && fafc[0] > 1){
            relerr = errmean;
        }
        if (errvar > errvartot && fafc[1] > 10){
            errvartot = errvar;
        }
        if (errmean > errmeantot && fafc[0] > 1){
            errmeantot = errmean;
        }
        if ((errvar > 0.05 && fafc[1] > 1) || (errmean > 0.05 && fafc[0] > 1)){
            nberr++;
        }
        //printf("%f %f %f\n", relerr, errmeantot, errvartot);
    }
    //if (relerr < 0.05) damp = 0.1;
    //else damp = DAMP;

#if PRINT_ERRS == 1
    printf("nberr, errmean, errvar: %i %f %f\n", nberr, errmeantot, errvartot);
#endif // PRINT_ERRS

    return relerr;
}

float * gausskerpar(int sx, int sy, float radius)
{
    float * out;
    posix_memalign((void **)&out, ALIGNSIZE, sx * sy * sizeof(float));

    float sig2 = radius * radius;
    for (int x = -sx / 2; x < sx / 2 ; ++x)
    {
        float dx2 = x * x;
        for (int y = -sy / 2; y < sy / 2; ++y)
        {
            float dy2 = y * y;
            float r2 = dx2 + dy2;
            float val = exp(-r2 / 2 / sig2)
                        / (2 * M_PI * sig2);
            int line = x;
            int col = y;
            if (x < 0) line += sx;
            if (y < 0) col += sy;
            
            out[col + line * sy] = val;
        }
    }
    return out;
}

int nbconv;

float * recons_ccomp(float * imgmes, float * imgnoise,
                     int * activepix, int nbact,
                     float * psf)
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


    float * ker;
    float * ker2;

    float * res;


    /* Memory allocation */
    posix_memalign((void **)&mu_albe_A, ALIGNSIZE,
                   nbact * sker2 * sizeof(float));
    posix_memalign((void **)&mu_albe_B, ALIGNSIZE,
                   nbact * sker2 * sizeof(float));
    posix_memalign((void **)&mu_beal_A, ALIGNSIZE,
                   nbact * sker2 * sizeof(float));
    posix_memalign((void **)&mu_beal_B, ALIGNSIZE,
                   nbact * sker2 * sizeof(float));
    posix_memalign((void **)&P_albe_A, ALIGNSIZE,
                   nbact * sker2 * sizeof(float));
    posix_memalign((void **)&P_albe_B, ALIGNSIZE,
                   nbact * sker2 * sizeof(float));
    posix_memalign((void **)&abeal, ALIGNSIZE, nbact * sker2 * sizeof(float));
    posix_memalign((void **)&vbeal, ALIGNSIZE, nbact * sker2 * sizeof(float));
    posix_memalign((void **)&P_be_E, ALIGNSIZE, nbact * sizeof(float));
    posix_memalign((void **)&P_be_F, ALIGNSIZE, nbact * sizeof(float));
    posix_memalign((void **)&omegamu, ALIGNSIZE, nbmes2 * sizeof(float));
    posix_memalign((void **)&vmu, ALIGNSIZE, nbmes2 * sizeof(float));

    posix_memalign((void **)&ker, ALIGNSIZE, smes3 * sker2 * sizeof(float));
    posix_memalign((void **)&ker2, ALIGNSIZE, smes3 * sker2 * sizeof(float));

    /* Initialize kernels */
    init_kernels(ker, ker2, psf);
    /*
    printf("Ker min, max: %f %f\n",                                            
           min(ker, smes2 * sker2),                                               
           max(ker, smes2 * sker2));
           */
#if DISPLAY_PLOTS == 1
    plot_image(smes * sker, smes * sker, ker, "kerint.png", PLOT_RESCALE);
#endif // DISPLAY_PLOTS == 1

    float Binit = rho * pixmean * Ainit;

    for (unsigned int i = 0; i < nbact * sker2; ++i) {
        mu_albe_A[i] = Ainit;
        mu_albe_B[i] = Binit;
        P_albe_A[i] = Ainit;
        P_albe_B[i] = Binit;
    }
    for (unsigned int i = 0; i < nbact; ++i)
    {
        P_be_E[i] = Ainit;
        P_be_F[i] = Binit;
    }

    /* Main loop */
    float relerr = 1.0;
    int iter = 0;
    //printf("nbiter: %i\n", nbiter);
    while (relerr > THRCONV && iter < nbiter)
    //for (int iter = 0; iter < nbiter; ++iter)
    {
        iter++;
        /* Internal loop */
        for (unsigned int j = 0; j < nbintern; ++j)
        {
            update_mubeal(vbeal, abeal,
                    mu_beal_A, mu_beal_B,
                    mu_albe_A, mu_albe_B,
                    P_be_E, P_be_F,
                    nbact, activepix);

            update_mualbe(mu_albe_A, mu_albe_B,
                    mu_beal_A, mu_beal_B,
                    P_albe_A, P_albe_B,
                    abeal, vbeal,
                    omegamu, vmu,
                    ker, ker2,
                    imgnoise, imgmes,
                    nbact, activepix);
            //printf("relerr: %f\n", relerr);
        }

        /* External loop */
        //printf("updatePbe\n");
        int iterpbe = 1;

        relerr = update_pbe(P_be_E, P_be_F,
                            P_albe_A, P_albe_B,
                            nbact, activepix,
                            iterpbe);

#if DISPLAY_OVERLAY_ITER == 1
        /* Build result */
        posix_memalign((void **)&res, ALIGNSIZE, size2 * sizeof(float));
        for (int i = 0; i < size2; ++i)
        {
            res[i] = 0;
        }
        for (int k = 0; k < nbact; ++k)
        {
            float val = P_be_F[k] / P_be_E[k];
            if (val < 0) val = 0;
            res[activepix[k] % size2] += val;
        }
        printf("res min, max: %f %f\n",                                            
                min(res, size2),                                               
                max(res, size2));
        plot_overlay(imgmes, res, "overlay.png");
        plot_image(sizex, sizey, res, "recons.png", PLOT_RESCALE);
        free(res);
#endif // DISPLAY_OVERLAY_ITER
        //printf("iteration, relerr: %i, %f\n", iter, relerr); 
    }
    if (relerr < 1.1 * THRCONV) nbconv++;

    posix_memalign((void **)&res, ALIGNSIZE, size2 * sizeof(float));

    for (int i = 0; i < size2; ++i) {
        res[i] = 0;
    }
    for (unsigned int k = 0; k < nbact; ++k)
    {
        int i = activepix[k];
        int ixy = activepix[k] % size2;
        int z = i / size2;

        float val = P_be_F[k] / P_be_E[k];
        res[ixy] += val;
    }
    int nbfluo = 1;
    for (int i = 0; i < size2; ++i)
    {
        int c = i % sizey;
        int l = i / sizey;
        if (res[i] > thrpoint){
            printf("%i %i %.2f %.2f %.2f %.2f\n",
                   nbfluo,
                   nbframe,
                   (c - sker / 2 * smes) * spix + spix / 2,
                   (l - sker / 2 * smes) * spix + spix / 2,
                   0.00,
                   res[i]);
            nbfluo++;
        }
    }
#if DISPLAY_OVERLAY == 1
    plot_overlay(imgmes, res, "overlay.png");
#endif // DISPLAY_OVERLAY
    /*
    printf("res min, max: %f %f\n",                                            
            min(res, size2),                                               
            max(res, size2));
            */

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

    free(ker);
    free(ker2);

    return res;
}

float * reconssparse(float * imgmes, float * imgnoise, float * psf)
{
    ccomp_dec ccdec = connectcomp_decomp(imgmes, smes);

    nbconv = 0;

    float * reconspic = malloc(size2 * sizeof(float));
    for (unsigned int i = 0; i < size2; ++i) {
        reconspic[i] = 0;
    }

    for (unsigned int i = 0; i < ccdec.nbcomp; ++i)
    {
        float * rectmp = recons_ccomp(imgmes, imgnoise,
                                      ccdec.activepixcomp[i], ccdec.nbact[i],
                                      psf);
        for (unsigned int i = 0; i < size2; ++i)
        {
            reconspic[i] += rectmp[i];
        }
        free(rectmp);
    }
    for (unsigned int i = 0; i < ccdec.nbcomp; ++i)
    {
        free(ccdec.activepixcomp[i]);
    }
    free(ccdec.nbact);
    free(ccdec.coordcomp);
    free(ccdec.imglab);

    if (brecs_args.output_given){
        FILE * fout = fopen(brecs_args.output_arg, "wb");
        if (!fout) {
            fprintf(stderr, "%s: Couldn't open file %s: %s\n",
                    prog_name, brecs_args.output_arg, strerror(errno));
            exit(EXIT_FAILURE);
        }
        fwrite(reconspic, sizeof(float), size2, fout);
        fclose(fout);
    }

    free(reconspic);
    //printf("Converged: %i / %i\n", nbconv, ccdec.nbcomp);

    return NULL;
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
        if (imagelength != sx){
            printf("%i %i\n", imagelength, sx);
            printf("incorrect image length\n");
            exit(EXIT_FAILURE);
        }
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

/* Decompose an image into connected components */

lab_t * roundker(int diam)
{
    int center = diam / 2;
    lab_t * ker = malloc(diam * diam * sizeof(lab_t));
    for (size_t i = 0; i < diam; i++) {
        for (size_t j = 0; j < diam; j++) {
            int x = j - diam / 2;
            int y = i - diam / 2;
            float rad2 = x * x + y * y;
            int ind = j + i * diam;
            if (rad2 < diam * diam / 4){
                ker[ind] = 1;
            } else {
                ker[ind] = 0;
            }
        }
    }
    return ker;
}

void maskpix(lab_t * img, int width, lab_t * ker, int diam, int x, int y){
    for (size_t i = 0; i < diam; i++) {
        for (size_t j = 0; j < diam; j++) {
            int ind = x + j - diam / 2 + (y + i - diam / 2) * width;
            img[ind] = img[ind] || ker[j + i * diam];
        }
    }
}

lab_t neighb(lab_t * img, int width, int x, int y)
{
    if (!img[x + (y - 1) * width - 1]
        || !img[x + (y - 1) * width]
        || !img[x + (y - 1) * width + 1]
        || !img[x + y * width - 1]
        || !img[x + y * width + 1]
        || !img[x + (y + 1) * width - 1]
        || !img[x + (y + 1) * width]
        || !img[x + (y + 1) * width + 1])
        return 1;
    return 0;
}

lab_t * dilate(lab_t * img, int width, int height, lab_t * ker, int diam)
{
    lab_t * res = malloc(width * height * sizeof(lab_t));
    for (size_t i = 0; i < width * height; ++i)
    {
        res[i] = img[i];
    }
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            if (img[j + i * width] && neighb(img, width, j, i)){
                maskpix(res, width, ker, diam, j, i);
            }
        }
    }
    return res;
}

void unionsets(lab_t * labs, int lastlab, int parentlab, int lab)
{
    if (lab != parentlab){
        for (int i = lab - 1; i < lastlab; ++i)
        {
            if (labs[i] == lab){
                labs[i] = parentlab;
            }
        }
    }
}

png_byte * genrandomcolo(lab_t nbcol) {
    png_byte * cols = malloc(3 * nbcol * sizeof(png_byte));
    png_byte mix[3] = {240, 240, 240};
    for (unsigned int i = 0; i < nbcol; ++i) {
        png_byte red = drand48() * 256;
        png_byte green = drand48() * 256;
        png_byte blue = drand48() * 256;

        cols[i * 3] = (red + mix[0]) / 2;
        cols[1 + i * 3] = (green + mix[1]) / 2;
        cols[2 + i * 3] = (blue + mix[2]) / 2;
    }

    return cols;
}

ccomp_dec aggregate(lab_t * img, lab_t * imgdil, int width, int height)
{
    ccomp_dec ccdec;
    lab_t labs[MAX_LABEL];
    lab_t neighblab[4];

    lab_t * imglabs = malloc(width * height * sizeof(lab_t));
    
    for (int i = 0; i < width * height; i++) {
        imglabs[i] = 0;
    }

    lab_t lastlab = 0;
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int ind = j + i * width;
            if (imgdil[ind]){
                lab_t lab4[4] = {0, 0, 0, 0};
                lab_t lab4p[4] = {0, 0, 0, 0};
                size_t nlab = 0;
                lab4[0] = imglabs[ind - width - 1];
                lab4[1] = imglabs[ind - width];
                lab4[2] = imglabs[ind - width + 1];
                lab4[3] = imglabs[ind - 1];
                lab_t minlab = MAX_LABEL;
                if (lab4[0]){
                    minlab = lab4[0];
                    lab4p[0] = lab4[0];
                    nlab++;
                }
                if (lab4[1]){
                    if (lab4[1] < minlab) minlab = lab4[1];
                    lab4p[nlab] = lab4[1];
                    nlab++;
                }
                if (lab4[2]){
                    if (lab4[2] < minlab) minlab = lab4[2];
                    lab4p[nlab] = lab4[2];
                    nlab++;
                }
                if (lab4[3]){
                    if (lab4[3] < minlab) minlab = lab4[3];
                    lab4p[nlab] = lab4[3];
                    nlab++;
                }
                if (nlab > 2){
                    for (int k = 0; k < nlab; ++k)
                    {
                        unionsets(labs, lastlab, minlab, lab4p[k]);
                    }
                }
                if (!nlab){
                    lastlab++;
                    labs[lastlab - 1] = lastlab;
                    imglabs[ind] = lastlab;
                } else {
                    imglabs[ind] = minlab;
                }
            }
        }
    }
    int clab = 0;
    int clab2 = 0;
    for (unsigned int i = 0; i < lastlab; ++i) {
        if (labs[i] > clab2){
            clab2 = labs[i];
            labs[i] = clab;
            clab++;
        } else {
            labs[i] = labs[labs[i] - 1];
        }
    }
    ccdec.nbcomp = clab;
    ccdec.coordcomp = malloc(clab * 4 * sizeof(int));
    ccdec.nbact = malloc(clab * sizeof(int));
    ccdec.activepixcomp = malloc(clab * sizeof(int *));
    for (unsigned int i = 0; i < clab; ++i)
    {
        ccdec.coordcomp[4 * i] = sizey;
        ccdec.coordcomp[4 * i + 1] = 0;
        ccdec.coordcomp[4 * i + 2] = sizex;
        ccdec.coordcomp[4 * i + 3] = 0;
        ccdec.nbact[i] = 0;
    }
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int ind = j + i * width;

            if (img[ind]){
                lab_t lab = labs[imglabs[ind] - 1];
                int * coord = ccdec.coordcomp + 4 * lab;
                if (j < coord[0]) coord[0] = j;
                if (j > coord[1]) coord[1] = j;
                if (i < coord[2]) coord[2] = i;
                if (i > coord[3]) coord[3] = i;
                imglabs[ind] = lab;
                ccdec.nbact[lab]++;
            }
        }
    }
    for (unsigned int i = 0; i < clab; ++i) {
        ccdec.activepixcomp[i] = malloc(ccdec.nbact[i] * sizeof(int));
        ccdec.nbact[i] = 0;
    }
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int ind = j + i * width;

            if (img[ind]){
                lab_t lab = imglabs[ind];
                ccdec.activepixcomp[lab][ccdec.nbact[lab]] = j + i * sizey;
                ccdec.nbact[lab]++;
            }
        }
    }
#if DISPLAY_PLOTS == 1
    png_byte * cols = genrandomcolo(clab);
    png_byte * imgccmprgb = malloc(sizex * sizey * 3 * sizeof(png_byte));

    for (unsigned int i = 0; i < size2; ++i)
    {
        if (img[i]){
            imgccmprgb[3 * i] = cols[3 * imglabs[i] - 3];
            imgccmprgb[1 + 3 * i] = cols[1 + 3 * imglabs[i] - 3];
            imgccmprgb[2 + 3 * i] = cols[2 + 3 * imglabs[i] - 3];
        } else {
            imgccmprgb[3 * i] = 0;
            imgccmprgb[1 + 3 * i] = 0;
            imgccmprgb[2 + 3 * i] = 0;
        }
    }
    free(cols);
    plot_imagergb(sizey, sizex, imgccmprgb, "connected_comp.png");
    free(imgccmprgb);
#endif // DISPLAY_PLOTS == 1

    ccdec.imglab = imglabs;
    return ccdec;
}

ccomp_dec connectcomp_decomp(float * imgmes, float radius)
{
    damp = DAMP;
    int sxfft = pow(2, (int)log2(sizex) + 1);
    int syfft = pow(2, (int)log2(sizey) + 1);

    float * imgsmoo = fftwf_alloc_real(sxfft * syfft);
    for (unsigned int i = 0; i < nbmes2; ++i)
    {
        float val = imgmes[i];
        int ci = i % nbmesy;
        int li = i / nbmesy;
        for (unsigned int j = 0; j < smes2; ++j)
        {
            int ind = ci * smes + j % smes + syfft * (li * smes + j / smes);
            imgsmoo[ind] = val;
            
        }
    }
    fftwf_complex * out1, * out2;
    fftwf_plan pforw1, pforw2, pbackw;

    float * imgker = gausskerpar(sxfft, syfft, smes);
#if DISPLAY_PLOTS == 1
    plot_image(sxfft, syfft, imgker, "kersmoo.png", PLOT_RESCALE);
#endif // DISPLAY_PLOTS == 1

    out1 = fftwf_alloc_complex(sxfft * (syfft / 2 + 1));
    out2 = fftwf_alloc_complex(sxfft * (syfft / 2 + 1));

    pforw1 = fftwf_plan_dft_r2c_2d(sxfft, syfft,
                                   imgsmoo, out1,
                                   FFTW_ESTIMATE);
    pforw2 = fftwf_plan_dft_r2c_2d(sxfft, syfft,
                                   imgker, out2,
                                   FFTW_ESTIMATE);

    pbackw = fftwf_plan_dft_c2r_2d(sxfft, syfft,
                                   out1, imgsmoo,
                                   FFTW_ESTIMATE);

    fftwf_execute(pforw1);
    fftwf_execute(pforw2);
    fftwf_free(imgker);

    for (unsigned int i = 0; i < sxfft * (syfft / 2 + 1); ++i)
    {
        fftwf_complex c1, c2;
        c1[0] = out1[i][0];
        c1[1] = out1[i][1];
        c2[0] = out2[i][0];
        c2[1] = out2[i][1];

        out1[i][0] = (c1[0] * c2[0] - c1[1] * c2[1]) / (sxfft * syfft);
        out1[i][1] = (c1[0] * c2[1] + c1[1] * c2[0]) / (sxfft * syfft);
    }

    fftwf_execute(pbackw);

#if DISPLAY_PLOTS == 1
    plot_image(sxfft, syfft, imgsmoo, "smoothimg.png", PLOT_RESCALE);
#endif // DISPLAY_PLOTS == 1

    lab_t * imgccmp = malloc(size2 * sizeof(lab_t));
    float * imgccmpf = malloc(size2 * sizeof(float));
    for (unsigned int i = 0; i < sizex; ++i)
    {
        for (unsigned int j = 0; j < sizey; ++j)
        {
            if (imgsmoo[j + i * syfft] > pixthr){
                imgccmp[j + i * sizey] = 1;
                imgccmpf[j + i * sizey] = 1;
            } else {
                imgccmp[j + i * sizey] = 0;
            }
        }
    }
    plot_image(sizex, sizey, imgccmpf, "sep1.png", PLOT_RESCALE);

    lab_t * rker = roundker(smes * sker / 2);
    lab_t * imgdil = dilate(imgccmp, sizey, sizex, rker, smes * sker / 2);
    free(rker);
    ccomp_dec ccdec = aggregate(imgccmp, imgdil, sizey, sizex);

    free(imgdil);
    fftwf_free(out1);
    fftwf_free(out2);
    fftwf_free(imgsmoo);

    return ccdec;
}


#ifdef SMOOTHEN
void shiftimg(float * img, float * img2)
{
    for (unsigned int i = 0; i < nbmesx * nbmesy; ++i)
    {
        img2[i] = 0;
    }
    for (unsigned int i = 0; i < nbmesx; ++i)
    {
        for (unsigned int j = 0; j < nbmesy; ++j)
        {
            int ind = j + SIZESMOOTH / 2
                      + (i + SIZESMOOTH / 2) * (nbmesy + SIZESMOOTH);
            float val = img[j + i * nbmesy];
            if (val > SMOOTHEN_THR) val = 0.0;
            img2[ind] = val;
        }
    }
}

void smoothen_noise(float * img)
{
    fftwf_complex * out1, * out2;
    fftwf_plan pforw1, pforw2, pbackw;

    int sxsmoo = nbmesx + SIZESMOOTH;
    int sysmoo = nbmesy + SIZESMOOTH;

    float * img2 = fftwf_alloc_real(sxsmoo * sysmoo);
    float * img3 = fftwf_alloc_real(sxsmoo * sysmoo);
    float * imgmean = fftwf_alloc_real(sxsmoo * sysmoo);
    float * imgker;

    out1 = fftwf_alloc_complex(sxsmoo * (sysmoo / 2 + 1));
    out2 = fftwf_alloc_complex(sxsmoo * (sysmoo / 2 + 1));

    imgker = gausskerpar(sxsmoo, sysmoo, SMOOTHEN_RAD);

    pforw1 = fftwf_plan_dft_r2c_2d(sxsmoo, sysmoo,
                                  img2, out1,
                                  FFTW_ESTIMATE);
    pforw2 = fftwf_plan_dft_r2c_2d(sxsmoo, sysmoo,
                                  imgker, out2,
                                  FFTW_ESTIMATE);

    pbackw = fftwf_plan_dft_c2r_2d(sxsmoo, sysmoo,
                                  out1, img2,
                                  FFTW_ESTIMATE);

    //plot_image(nbmesx, nbmesy, img, "imgmes.png", plot_rescale);
    shiftimg(img, img2);

#if DISPLAY_PLOTS == 1
    plot_image(sxsmoo, sysmoo, img2, "bsmooth.png", PLOT_RESCALE);

    plot_image(sxsmoo, sysmoo, imgker, "gausssmooth.png", PLOT_RESCALE);
#endif // DISPLAY_PLOTS == 1

    fftwf_execute(pforw1);
    fftwf_execute(pforw2);

    for (unsigned int i = 0; i < sxsmoo * (sysmoo / 2 + 1); ++i)
    {
        fftwf_complex c1, c2;
        c1[0] = out1[i][0];
        c1[1] = out1[i][1];
        c2[0] = out2[i][0];
        c2[1] = out2[i][1];

        out1[i][0] = (c1[0] * c2[0] - c1[1] * c2[1]) / (sxsmoo * sysmoo);
        out1[i][1] = (c1[0] * c2[1] + c1[1] * c2[0]) / (sxsmoo * sysmoo);
    }

    fftwf_execute(pbackw);

#if DISPLAY_PLOTS == 1
    plot_image(sxsmoo, sysmoo, img2, "asmooth.png", PLOT_RESCALE);
#endif // DISPLAY_PLOTS == 1

    for (unsigned int i = 0; i < sysmoo * sxsmoo; ++i)
    {
        imgmean[i] = img[i] - img2[i];
    }
#if DISPLAY_PLOTS == 1
    plot_image(sxsmoo, sysmoo, imgmean, "remmean.png", PLOT_RESCALE);
#endif // DISPLAY_PLOTS == 1

    fftwf_free(out1);
    fftwf_free(out2);
    fftwf_free(img2);
    fftwf_free(img3);
    fftwf_free(imgmean);
    fftwf_free(imgker);

    for (unsigned int i = 0; i < NBMESY; ++i) {
        for (unsigned int j = 0; j < NBMESX; ++j){
            int ind = i + sker / 2 + (j + sker / 2) * nbmesy;
            img[ind] = imgmean[ind];
        }
    }
}
#endif // SMOOTHEN

int loadimg(uint16_t ** img)
{
    char * fname = brecs_args.filename_arg;
    char * dot = strrchr(fname, '/');
    dot = strrchr(fname, '.');
    if (!dot || dot == fname || !strcmp(dot,".dat")){
        /* Assume a raw image file */
        if (!brecs_args.frame_given){
            fprintf(stderr, "%s: Frame number not provided for a raw image.\n",
                    prog_name);
            exit(EXIT_FAILURE);
        }
        long int offset = brecs_args.frame_arg;

        errno = 0;
        FILE * fimg = fopen(fname, "rb");
        if (!fimg) {
            fprintf(stderr, "%s: Couldn't open file %s: %s\n",
                    prog_name, fname, strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (fseek(fimg, NBMESY * NBMESX * 2 * offset, SEEK_SET) == -1){
            fprintf(stderr, "%s: Error reading input file: %s\n",
                    prog_name, strerror(errno));
            exit(EXIT_FAILURE);
        }
        *img = malloc(NBMESX * NBMESY * sizeof(uint16_t));
        if (fread(*img, 2, NBMESX * NBMESY, fimg) == -1){
            fprintf(stderr, "%s: Error reading input file: %s\n",
                    prog_name, strerror(errno));
            exit(EXIT_FAILURE);
        }
        fclose(fimg);
    } else if (!strcmp(dot,".tif") || !strcmp(dot,".tiff")){
        *img = opentiff(fname, NBMESX, NBMESY);
    } else {
        fprintf(stderr, "%s: File format not supported\n",
                prog_name);
        exit(EXIT_FAILURE);
    }

    return 0;
}


void refinedkerfit(float * ker0, float * ker2, float * ker4, float * ker6,
                   float * ker8, float * ker10)
{
    for (int x = -sizex / 2; x < sizex / 2 ; ++x)
    {
        float dx2 = x * x;
        for (int y = -sizey / 2; y < sizey / 2; ++y)
        {
            float dy2 = y * y;
            float radius2 = dx2 + dy2;
            float r2 = radius2 / 2 / (sigpsf * sigpsf);
            float val0 = exp(-r2)
                         / (2 * M_PI * sigpsf * sigpsf);
            float val2 = r2 * exp(-r2)
                         / (2 * M_PI * sigpsf * sigpsf);
            float val4 = r2 * r2 * exp(-r2)
                         / (2 * M_PI * sigpsf * sigpsf);
            float val6 = r2 * r2 * r2 * exp(-r2)
                         / (2 * M_PI * sigpsf * sigpsf);
            float val8 = r2 * r2 * r2 * r2 * exp(-r2)
                         / (2 * M_PI * sigpsf * sigpsf);
            float val10 = r2 * r2 * r2 * r2 * r2 * exp(-r2)
                         / (2 * M_PI * sigpsf * sigpsf);
            int line = x;
            int col = y;
            if (x < 0) line += sizex;
            if (y < 0) col += sizey;
            
            ker0[col + line * sizey] = val0;
            ker2[col + line * sizey] = val2;
            ker4[col + line * sizey] = val4;
            ker6[col + line * sizey] = val6;
            ker8[col + line * sizey] = val8;
            ker10[col + line * sizey] = val10;
        }
    }
}

void init_refinedkersfit(float * pix0, float * pix2, float * pix4,
                         float * pix6, float * pix8, float * pix10,
                         float * ker0, float * ker2, float * ker4,
                         float * ker6, float * ker8, float * ker10)
{
    for (int i = 0; i < smes2; ++i) {
        int ci = (i % smes2) % smes;
        int li = (i % smes2) / smes;
        int z  = i / smes2;
        for (int j = 0; j < sker2; ++j) {
            int kerc = j % sker - sker / 2;
            int kerl = j / sker - sker / 2;
            float sum0 = 0;
            float sum2 = 0;
            float sum4 = 0;
            float sum6 = 0;
            float sum8 = 0;
            float sum10 = 0;
            for (int k = 0; k < smes2; ++k) {
                int cli = -li + k / smes + smes * kerl;
                if (cli < 0) cli += sizex;
                int cci = -ci + k % smes + smes * kerc;
                if (cci < 0) cci += sizey;

                sum0 += ker0[cci + sizey * cli + z * size2];
                sum2 += ker2[cci + sizey * cli + z * size2];
                sum4 += ker4[cci + sizey * cli + z * size2];
                sum6 += ker6[cci + sizey * cli + z * size2];
                sum8 += ker8[cci + sizey * cli + z * size2];
                sum10 += ker10[cci + sizey * cli + z * size2];
            }
            int cker = j % smes;
            int lker = j / smes;
            int indmu = cker + sker * lker;
            pix0[indmu + i * sker2] = sum0;
            pix2[indmu + i * sker2] = sum2;
            pix4[indmu + i * sker2] = sum4;
            pix6[indmu + i * sker2] = sum6;
            pix8[indmu + i * sker2] = sum8;
            pix10[indmu + i * sker2] = sum10;
        }
    }
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
    _MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() & ~_MM_MASK_INVALID);
#endif

    /* Command line parser */
    char * arg0 = argv[0];
    arg0 = strrchr (arg0, '/');
    if (arg0)
        prog_name = arg0 + 1;
    else
        prog_name = argv[0];

    if (cmdline_parser(argc, argv, & brecs_args) != 0)
        exit(EXIT_FAILURE);

    loadimg(&img);

    posix_memalign((void **)&imgmes, ALIGNSIZE, nbmes2 * sizeof(float));
    posix_memalign((void **)&imgnoise, ALIGNSIZE, nbmes2 * sizeof(float));

    posix_memalign((void **)&imgker, ALIGNSIZE, size3 * sizeof(float));
    
    for (unsigned int i = 0; i < nbmes2; ++i)
    {
        imgnoise[i] = 1e8;
        imgmes[i] = 0;
    }
    for (unsigned int i = 0; i < NBMESY; ++i) {
        for (unsigned int j = 0; j < NBMESX; ++j){

            /*
            if (
                    (i > 3500 / 12 && i < 3700 / 12
                     && j < NBMESX - 750 / 12 && j > NBMESX - 950 / 12)
                || (i > 3350 / 12 && i < 3550 / 12
                    && j < NBMESX - 980 / 12 && j > NBMESX - 1180 / 12)
                || (i > 3550 / 12 && i < 3750 / 12
                    && j < NBMESX - 1350 / 12 && j > NBMESX - 1550 / 12)
                || (i > 1500 / 12 && i < 1700 / 12
                    && j < NBMESX - 1470 / 12 && j > NBMESX - 1670 / 12)
                || (i > 1600 / 12 && i < 1800 / 12
                    && j < NBMESX - 1650 / 12 && j > NBMESX - 1850 / 12)){
                    */

                float val = (img[i + j * NBMESY]);

#ifdef RESCALEINPUT
                val = (val - RESCALEOFFSET) / RESCALESLOPE;
#endif // RESCALEINPUT

                float pixmes = val - meanback;
                int ind = i + sker / 2 + (j + sker / 2) * nbmesy;
                imgmes[ind] = pixmes;
                imgnoise[ind] = noiseback + 1.0 * val;
                //printf("%f\n", val);
//            }
        }
    }
    free(img);
    updatetemp(beta, imgnoise);

#if DISPLAY_PLOTS == 1
    plot_image(nbmesx, nbmesy, imgmes, "imgsource.png", PLOT_RESCALE);
#endif // DISPLAY_PLOTS == 1

#ifdef SMOOTHEN
    smoothen_noise(imgmes);
#endif // SMOOTHEN

#if KERNEL == 1
    gaussker(imgker);
    //plot_image(sizex, sizey, imgker, "kernel.png", plot_rescale);
#elif KERNEL == 2
    loadgibson(imgker);
#elif KERNEL == 3
    refinedker(imgker);
#else
    exit(EXIT_FAILURE);
#endif

    imgrecons = reconssparse(imgmes, imgnoise, imgker);

    /*
    float * ker0;
    float * ker2;
    float * ker4;
    float * ker6;
    float * ker8;
    float * ker10;
    float * pix0;
    float * pix2;
    float * pix4;
    float * pix6;
    float * pix8;
    float * pix10;
    posix_memalign((void **)&ker0, 32, size3 * sizeof(float));
    posix_memalign((void **)&ker2, 32, size3 * sizeof(float));
    posix_memalign((void **)&ker4, 32, size3 * sizeof(float));
    posix_memalign((void **)&ker6, 32, size3 * sizeof(float));
    posix_memalign((void **)&ker8, 32, size3 * sizeof(float));
    posix_memalign((void **)&ker10, 32, size3 * sizeof(float));

    refinedker(ker0, ker2, ker4, ker6, ker8, ker10);

    posix_memalign((void **)&pix0, 32, smes3 * sker2 * sizeof(float));
    posix_memalign((void **)&pix2, 32, smes3 * sker2 * sizeof(float));
    posix_memalign((void **)&pix4, 32, smes3 * sker2 * sizeof(float));
    posix_memalign((void **)&pix6, 32, smes3 * sker2 * sizeof(float));
    posix_memalign((void **)&pix8, 32, smes3 * sker2 * sizeof(float));
    posix_memalign((void **)&pix10, 32, smes3 * sker2 * sizeof(float));

    init_refinedkers(pix0, pix2, pix4, pix6, pix8, pix10,
                     ker0, ker2, ker4, ker6, ker8, ker10);

    plot_image(sizex, sizey, ker0, "ker0.png", plot_rescale);
    plot_image(sizex, sizey, ker2, "ker2.png", plot_rescale);
    plot_image(sizex, sizey, ker4, "ker4.png", plot_rescale);
    plot_image(sizex, sizey, ker6, "ker6.png", plot_rescale);
    plot_image(sizex, sizey, ker8, "ker6.png", plot_rescale);
    plot_image(sizex, sizey, ker10, "ker6.png", plot_rescale);

    free(ker0);
    free(ker2);
    free(ker4);
    free(ker6);
    free(ker8);
    free(ker10);


    for (unsigned int i = 0; i < size2; ++i)
    {
        if (imgrecons[i] > thrpoint){
            int ci = (i % sizey) % smes;
            int li = (i / sizey) % smes;
            int ikeri = ci + li * smes;

            for (unsigned int j = 0; j < sker2; ++j) {
                int dcmu = j % sker - sker / 2;
                int dlmu = j / sker - sker / 2;

                int cmu = (i % sizey) / smes + dcmu;
                int lmu = (i / sizey) / smes + dlmu;
                int imu = cmu + lmu * nbmesy;

                printf("%f ", imgmes[imu]);
            }
            for (unsigned int j = 0; j < sker2; ++j) {
                printf("%f ", pix0[j + ikeri * sker2]);
            }
            for (unsigned int j = 0; j < sker2; ++j) {
                printf("%f ", pix2[j + ikeri * sker2]);
            }
            for (unsigned int j = 0; j < sker2; ++j) {
                printf("%f ", pix4[j + ikeri * sker2]);
            }
            for (unsigned int j = 0; j < sker2; ++j) {
                printf("%f ", pix6[j + ikeri * sker2]);
            }
            for (unsigned int j = 0; j < sker2; ++j) {
                printf("%f ", pix8[j + ikeri * sker2]);
            }
            for (unsigned int j = 0; j < sker2; ++j) {
                printf("%f ", pix10[j + ikeri * sker2]);
            }
            printf("\n");
        }
    }

    //plot_image(sizex, sizey, imgrecons, "recons.png", plot_rescale);
    //plot_overlay(imgmes, imgrecons, "overlay.png");
    
    //char fname[100];
    //snprintf(fname, 100, "img-%li.dat.bz2", offset);
    //saveimage(imgrecons, size2, fname);
    */


    free(imgker);
    free(imgmes);
    free(imgnoise);
    free(imgrecons);
    
    return EXIT_SUCCESS;
}
