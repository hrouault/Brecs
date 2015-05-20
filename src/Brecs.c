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

#include <platform.h>
#define M_PIf ((float)M_PI)

#include <stdio.h>
#include <stdlib.h>
#undef min
#undef max
#include <string.h>
#include <math.h>

#include <fftw3.h>

#include "error.h"
#include "cmdline.h"
#include "inoutimg.h"
#include "Brecs.h"
#include "parser.h"


/* Command line variable */
struct gengetopt_args_info brecs_args;

/* Constant definitions */
#include "parameters.h"

/* signal noise properties */
#ifdef BRECS_PIXMEAN
static float const pixmean = BRECS_PIXMEAN;
#else
#define BRECS_PIXMEAN 500
static float const pixmean = 500.0f;
#endif

#ifdef BRECS_PIXSTD
static float const pixstd = BRECS_PIXSTD;
#else
static float const pixstd = 200.0f;
#endif

#ifdef BRECS_RHO
static float const rho = BRECS_RHO;
#else
static float const rho = 0.001f;
#endif

/* Sizes of the images */

#ifdef BRECS_KERSIZE
static int const kersize = BRECS_KERSIZE;
#else
#define BRECS_KERSIZE 8
static int const kersize = 8;
#endif

#ifdef BRECS_KERSIZEZ
static int const kersizez = BRECS_KERSIZEZ;
#else
#define BRECS_KERSIZEZ 1
static int const kersizez = 1;
#endif

#ifdef BRECS_PIXSDIV
static int const pixsdiv = BRECS_PIXSDIV;
#else
#define BRECS_PIXSDIV 8
static int const pixsdiv = 8;
#endif

#ifdef BRECS_PIXSDIVZ
static int const pixsdivz = BRECS_PIXSDIVZ;
#else
#define BRECS_PIXSDIVZ 1
static int const pixsdivz = 1;
#endif

static unsigned const kersize2 = BRECS_KERSIZE * BRECS_KERSIZE;
static unsigned const kersize3 = BRECS_KERSIZE * BRECS_KERSIZE * BRECS_KERSIZEZ;

static unsigned const pixsdiv2 = BRECS_PIXSDIV * BRECS_PIXSDIV;
static unsigned const pixsdiv3 = BRECS_PIXSDIV * BRECS_PIXSDIV * BRECS_PIXSDIVZ;

#ifdef BRECS_SPIXNM
static float const spixnm = BRECS_SPIXNM;
#else
static float const spixnm = 133.0;
#endif

#ifdef BRECS_SPIXZNM
static float const spixznm = BRECS_SPIXZNM;
#else
static float const spixznm = 300.0;
#endif

#ifdef BRECS_MESOFFSET
static float const mesoffset = BRECS_MESOFFSET;
#else
static float const mesoffset = 80;
#endif

#ifdef BRECS_MESAMPLI
static float const mesampli = BRECS_MESAMPLI;
#else
static float const mesampli = 20;
#endif

#ifdef BRECS_NOISEOFFSET
static float const noiseoffset = BRECS_NOISEOFFSET;
#else
static float const noiseoffset = 1;
#endif

#ifdef BRECS_NBITER
static int const nbiter = BRECS_NBITER;
#else
static int const nbiter = 200;
#endif

#ifdef BRECS_PREFACRADCC
static float const prefacradcc = BRECS_PREFACRADCC;
#else
static float const prefacradcc = 1.0;
#endif

#ifdef BRECS_CONVOLPIXTHR
static float const convolpixthr = BRECS_CONVOLPIXTHR;
#else
static float const convolpixthr = 40.0;
#endif


#ifdef BRECS_AINITPFACT
static float const Ainit = BRECS_AINITPFACT / (BRECS_PIXMEAN * BRECS_PIXMEAN);
#else
static float const Ainit = 1.0 / (BRECS_PIXMEAN * BRECS_PIXMEAN);
#endif

#ifdef BRECS_MEANBACK
const float meanback = BRECS_MEANBACK;
#else
const float meanback = 0;
#endif

#ifdef BRECS_LOCAINTENSTHR
const float locaintensthr = BRECS_LOCAINTENSTHR;
#else
const float locaintensthr = 1000;
#endif

#ifdef BRECS_OVERLAYMAXINT
const float overlaymaxint = BRECS_OVERLAYMAXINT;
#else
const float overlaymaxint = 50.4;
#endif

#ifdef BRECS_OVERLAYMININT
const float overlayminint = BRECS_OVERLAYMININT;
#else
const float overlayminint = 0.1;
#endif

#ifdef BRECS_RELERRTHR
const float relerrthr = BRECS_RELERRTHR;
#else
const float relerrthr = 1e-3;
#endif

#ifdef BRECS_NBINTERNLOOP
const float nbinternloop = BRECS_NBINTERNLOOP;
#else
const float nbinternloop = 1;
#endif


#ifdef BRECS_DAMP1
const float damp1 = BRECS_DAMP1;
#else
const float damp1 = 0.05;
#endif

#ifdef BRECS_DAMP2
const float damp2 = BRECS_DAMP2;
#else
const float damp2 = 0.1;
#endif

static inline vecfloat abs_ps(vecfloat x) {
    vecfloat sign_mask = VFUNC(set1_ps) (-0.f);  // -0.f = 1 << 31
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


void fafcfunc(float * out, float sig2, float r)
{
    if (r > 5e4) r = 5e4;
    if (sig2 < 0) {
        sig2 = 1e6;
        r = 0;
    }
    float pstd2 = pixstd * pixstd;

    float deltr = (r - pixmean) * (r - pixmean);
    float varr = sig2 + pstd2;

    float fra = sqrtf(sig2 / varr);
    float fra1 = fra / varr;
    float fra2 = fra1 / varr;

    float argexp = -r * r / 2 / sig2 + deltr / 2 / varr;
    if (argexp > 25.0) {
        out[0] = 1e-10;
        out[1] = 1e-3;
        return;
    }
    float exprgauss = expf(argexp);

    const float onemrho = 1.0f - rho;
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

    if (out[0] < 1e-10) out[0] = 1e-10;
    if (out[1] < 1e-3) out[1] = 1e-3;
}

void update_omegavmu(float * omegamu, float * vmu,
                     float * ker, float * ker2,
                     float * abeal, float * vbeal,
                     unsigned nbact, int * activepix,
                     int sizex, int sizey, int sizez)
{
    const vecfloat zero = VFUNC(set1_ps) (0);

    int nbmesx = sizex / pixsdiv + kersize;
    int nbmesy = sizey / pixsdiv + kersize;
    int nbmesz = sizez / pixsdivz + kersizez - kersizez % 2;
    int nbmes2 = nbmesx * nbmesy; 
    int nbmes3 = nbmes2 * nbmesz; 

    int size2 = sizex * sizey;


    for (int mu = 0; mu < nbmes3; mu += shift) {
        VFUNC(store_ps) (vmu + mu, zero);
        VFUNC(store_ps) (omegamu + mu, zero);
    }

    for (unsigned int k = 0; k < nbact; ++k) {
        int i = activepix[k];
        float * cabeal = abeal + k * kersize3;
        float * cvbeal = vbeal + k * kersize3;

        int ci = ((i % size2) % sizex) % pixsdiv;
        int li = ((i % size2) / sizex) % pixsdiv;
        int zi = (i / size2) % pixsdivz;
        int ikeri = ci + li * pixsdiv + zi * pixsdiv2;

        int cmu0 = ((i % size2) % sizex) / pixsdiv + kersize / 2;
        int lmu0 = ((i % size2) / sizex) / pixsdiv + kersize / 2;
        int zmu0 = (i / size2) / pixsdivz + kersizez / 2;

        float * cker = ker + ikeri * kersize3;
        float * cker2 = ker2 + ikeri * kersize3;

        for (unsigned mu = 0; mu < kersize3; mu += shift) {
            int dcmu = (mu % kersize2) % kersize - kersize / 2;
            int dlmu = (mu % kersize2) / kersize - kersize / 2;
            int dzmu = (mu / kersize2) - kersizez / 2;

            int cmu = cmu0 + dcmu;
            int lmu = lmu0 + dlmu;
            int zmu = zmu0 + dzmu;
            int imu = cmu + lmu * nbmesx + zmu * nbmes2;

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
#if BRECS_DISPLAYPLOTS
    writetiff_f("omegavmu.tif", nbmesx, nbmesy, nbmesz, omegamu);
#endif
}

void update_Palbe(afloat * mu_albe_A, afloat * mu_albe_B,
                  afloat * abeal, afloat * vbeal,
                  float * sum_mualbe_A, float * sum_mualbe_B,
                  afloat * omegamu, afloat * vmu,
                  afloat * ker, afloat * ker2,
                  afloat * imgnoise, afloat * imgmes,
                  unsigned nbact, int * activepix,
                  int sizex, int sizey, int sizez)
{
    const vecfloat zero = VFUNC(set1_ps) (0);
    const vecfloat one = VFUNC(set1_ps) (1.0);
    const vecfloat oneosk = VFUNC(set1_ps) (1.0f / kersize3);
    const vecfloat lowv = VFUNC(set1_ps) (1e8);

    int nbmesx = sizex / pixsdiv + kersize;
    int nbmesy = sizey / pixsdiv + kersize;
    int nbmes2 = nbmesx * nbmesy; 
    int nbmes3 = nbmes2 * (sizez / pixsdivz + kersizez - kersizez % 2); 

    int size2 = sizex * sizey;

    update_omegavmu(omegamu, vmu, ker, ker2, abeal, vbeal, nbact, activepix,
                    sizex, sizey, sizez);

    for (unsigned int k = 0; k < nbact; ++k) {
        int i = activepix[k];
        float * caA = mu_albe_A + k * kersize3;
        float * caB = mu_albe_B + k * kersize3;
        float * cabeal = abeal + k * kersize3;
        float * cvbeal = vbeal + k * kersize3;

        int ci = ((i % size2) % sizex) % pixsdiv;
        int li = ((i % size2) / sizex) % pixsdiv;
        int zi = (i / size2) % pixsdivz;
        int ikeri = ci + li * pixsdiv + zi * pixsdiv2;

        int cmu0 = ((i % size2) % sizex) / pixsdiv + kersize / 2;
        int lmu0 = ((i % size2) / sizex) / pixsdiv + kersize / 2;
        int zmu0 = (i / size2) / pixsdivz + kersizez / 2;

        float * cker = ker + ikeri * kersize3;
        float * cker2 = ker2 + ikeri * kersize3;

        vecfloat sumvmualA = VFUNC(load_ps) (sum_mualbe_A + k * shift);
        vecfloat sumvmualB = VFUNC(load_ps) (sum_mualbe_B + k * shift);

        vecfloat sumA = zero;
        vecfloat sumB = zero;

        for (unsigned mu = 0; mu < kersize3; mu += shift) {
            int dcmu = (mu % kersize2) % kersize - kersize / 2;
            int dlmu = (mu % kersize2) / kersize - kersize / 2;
            int dzmu = (mu / kersize2) - kersizez / 2;

            int cmu = cmu0 + dcmu;
            int lmu = lmu0 + dlmu;
            int zmu = zmu0 + dzmu;
            int imu = cmu + lmu * nbmesx + zmu * nbmes2;

            vecfloat den = VFUNC(loadu_ps) (imgnoise + imu);
            vecfloat v = VFUNC(loadu_ps) (vmu + imu);
            v = VFUNC(min_ps) (v, lowv);
            vecfloat k2 = VFUNC(load_ps) (cker2 + mu);
            vecfloat ke = VFUNC(load_ps) (cker + mu);
            vecfloat vb = VFUNC(load_ps) (cvbeal + mu);

            den = VFUNC(add_ps) (den, v);
            vb = VFUNC(mul_ps) (k2, vb);
            den = VFUNC(sub_ps) (den, vb);
            den = VFUNC(div_ps) (one, den);

            vecfloat bnum = VFUNC(loadu_ps) (imgmes + imu);
            vecfloat om = VFUNC(loadu_ps) (omegamu + imu);
            vecfloat ab = VFUNC(load_ps) (cabeal + mu);

            ab = VFUNC(mul_ps) (ke, ab);
            bnum = VFUNC(sub_ps) (bnum, om);
            bnum = VFUNC(add_ps) (bnum, ab);
            bnum = VFUNC(mul_ps) (bnum, ke);

            vecfloat valA = VFUNC(mul_ps) (k2, den);
            vecfloat ibA = VFUNC(load_ps) (caA + mu);
            ibA = VFUNC(sub_ps) (sumvmualA, ibA);
            valA = VFUNC(add_ps) (valA, ibA);

            sumA = VFUNC(add_ps) (sumA, valA);
            VFUNC(store_ps) (cvbeal + mu, valA);

            vecfloat valB = VFUNC(mul_ps) (bnum, den);
            vecfloat ibB = VFUNC(load_ps) (caB + mu);
            ibB = VFUNC(sub_ps) (sumvmualB, ibB);
            valB = VFUNC(add_ps) (valB, ibB);

            sumB = VFUNC(add_ps) (sumB, valB);
            VFUNC(store_ps) (cabeal + mu, valB);
        }
        sumA = sumh_ps(sumA);
        sumB = sumh_ps(sumB);
        sumA = VFUNC(mul_ps) (sumA, oneosk);
        sumB = VFUNC(mul_ps) (sumB, oneosk);

        VFUNC(store_ps) (sum_mualbe_A + k * shift, sumA);
        VFUNC(store_ps) (sum_mualbe_B + k * shift, sumB);
    }
}

void update_mualbe(float * mu_albe_A, float * mu_albe_B,
                   float * sum_mualbe_A, float * sum_mualbe_B,
                   float * abeal, float * vbeal,
                   float * omegamu, float * vmu,
                   float * ker, float * ker2,
                   float * imgnoise, float * imgmes,
                   unsigned nbact, int * activepix,
                   int sizex, int sizey, int sizez)
{
    update_Palbe(mu_albe_A, mu_albe_B,
                 abeal, vbeal,
                 sum_mualbe_A, sum_mualbe_B,
                 omegamu, vmu,
                 ker, ker2,
                 imgnoise, imgmes,
                 nbact, activepix,
                 sizex, sizey, sizez);

    const vecfloat zero = VFUNC(set1_ps) (0);
    const vecfloat oneosk = VFUNC(set1_ps) (1.0f / kersize3);
    for (unsigned int k = 0; k < nbact; ++k) {
        float * caA = mu_albe_A + k * kersize3;
        float * caB = mu_albe_B + k * kersize3;
        float * cPA = vbeal + k * kersize3;
        float * cPB = abeal + k * kersize3;

        vecfloat PAt = VFUNC(load_ps) (sum_mualbe_A + k * shift);
        vecfloat PBt = VFUNC(load_ps) (sum_mualbe_B + k * shift);

        vecfloat sumA = zero;
        vecfloat sumB = zero;
        for (unsigned mu = 0; mu < kersize3; mu += shift) {
            vecfloat A = VFUNC(load_ps) (cPA + mu);
            vecfloat B = VFUNC(load_ps) (cPB + mu);
            vecfloat maA = VFUNC(load_ps) (caA + mu);
            vecfloat maB = VFUNC(load_ps) (caB + mu);

            A = VFUNC(sub_ps) (A, PAt);
            B = VFUNC(sub_ps) (B, PBt);

            A = VFUNC(add_ps) (A, maA);
            B = VFUNC(add_ps) (B, maB);

            sumA = VFUNC(add_ps) (sumA, A);
            sumB = VFUNC(add_ps) (sumB, B);

            VFUNC(store_ps) (caA + mu, A);
            VFUNC(store_ps) (caB + mu, B);
        }
        sumA = sumh_ps(sumA);
        sumB = sumh_ps(sumB);
        sumA = VFUNC(mul_ps) (sumA, oneosk);
        sumB = VFUNC(mul_ps) (sumB, oneosk);

        VFUNC(store_ps) (sum_mualbe_A + k * shift, sumA);
        VFUNC(store_ps) (sum_mualbe_B + k * shift, sumB);
    }
}

void update_mubeal(float * vbeal, float * abeal,
                   float * mu_albe_A, float * mu_albe_B,
                   float * P_be_E, float * P_be_F,
                   float * sum_mualbe_A, float * sum_mualbe_B,
                   unsigned nbact, int * activepix)
{
    const float rat = ((float)kersize3 - 1) / kersize3;
    const vecfloat one = VFUNC(set1_ps) (1.0);
    const vecfloat thrmin = VFUNC(set1_ps) (1e10);
    const vecfloat thrmax = VFUNC(set1_ps) (1e-5);

    for (unsigned int k = 0; k < nbact; ++k) {
        float * caA = mu_albe_A + k * kersize3;
        float * caB = mu_albe_B + k * kersize3;
        float * cabeal = abeal + k * kersize3;
        float * cvbeal = vbeal + k * kersize3;

        /* Compute P_beta */
        vecfloat P_be_A = VFUNC(load_ps) (sum_mualbe_A + k * shift);
        vecfloat P_be_B = VFUNC(load_ps) (sum_mualbe_B + k * shift);

        const vecfloat rPE = VFUNC(set1_ps) (rat * P_be_E[k]);
        const vecfloat rPF = VFUNC(set1_ps) (rat * P_be_F[k]);

        /* Compute mu_beal */
        for (size_t mu = 0; mu < kersize3; mu += shift) {
            vecfloat cC = VFUNC(load_ps) (caA + mu);
            cC = VFUNC(sub_ps) (P_be_A, cC);
            vecfloat cD = VFUNC(load_ps) (caB + mu);
            cD = VFUNC(sub_ps) (P_be_B, cD);
            cD = VFUNC(min_ps) (cD, thrmin);

            cC = VFUNC(add_ps) (rPE, cC);
            cC = VFUNC(div_ps) (one, cC);
            cC = VFUNC(max_ps) (cC, thrmax);
            cC = VFUNC(min_ps) (cC, thrmin);

            cD = VFUNC(add_ps) (rPF, cD);
            cD = VFUNC(mul_ps) (cC, cD);

            VFUNC(store_ps) (cvbeal + mu, cC);
            VFUNC(store_ps) (cabeal + mu, cD);
        }
    }
}

float update_pbe(float * P_be_E, float * P_be_F,
                 float * P_albe_A, float * P_albe_B,
                 unsigned nbact, int * activepix,
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
    for (unsigned int k = 0; k < nbact; ++k) {
        float * cA = P_albe_A + k * kersize3;
        float * cB = P_albe_B + k * kersize3;

        vecfloat vPEt = VFUNC(set1_ps) (0);
        vecfloat vPFt = VFUNC(set1_ps) (0);
        for (size_t mu = 0; mu < kersize3; mu += shift) {
            vecfloat e = VFUNC(load_ps) (cA + mu);
            vPEt = VFUNC(add_ps) (vPEt, e);
            vecfloat f = VFUNC(load_ps) (cB + mu);
            vPFt = VFUNC(add_ps) (vPFt, f);
        }
        vPEt = sumh_ps(vPEt);
        vPFt = sumh_ps(vPFt);
        float tmp[shift];
        VFUNC(storeu_ps) (tmp, vPEt);
        float PEt = tmp[0];
        VFUNC(storeu_ps) (tmp, vPFt);
        float PFt = tmp[0];

        if (PFt < 0) PFt = 0;

        if (P_be_E[k] < 1e-7) P_be_E[k] = 1e-7;
        float prevPbE = P_be_E[k];
        float prevPbF = P_be_F[k];

        if (PFt > 1e12) PFt = 1e12;
        float fafc[2];
        fafcfunc(fafc, 1 / PEt, PFt / PEt);

        float invE = (1 - damp1) / P_be_E[k] + damp1 * fafc[1];
        P_be_E[k]= 1 / invE;
        P_be_F[k] = (1 - damp2) * P_be_F[k] / invE / prevPbE
            + damp2 * fafc[0] / invE;

        float errvar = fabsf(fafc[1] - 1 / prevPbE) / (fafc[1] + 1 / prevPbE);
        float errmean = fabsf(fafc[0] - prevPbF / prevPbE)
                        / (fafc[0] + prevPbF / prevPbE);
        if (errvar > relerr) {  // && fafc[1] > 10){
            relerr = errvar;
        }
        if (errmean > relerr) {  // && fafc[0] > 1){
            relerr = errmean;
        }
        if (errvar > errvartot && fafc[1] > 10) {
            errvartot = errvar;
        }
        if (errmean > errmeantot && fafc[0] > 1) {
            errmeantot = errmean;
        }
        if ((errvar > 0.05 && fafc[1] > 1)
                || (errmean > 0.05 && fafc[0] > 1)) {
            nberr++;
        }
        // printf("%f %f %f\n", relerr, errmeantot, errvartot);
    }

#if PRINT_ERRS == 1
    printf("nberr, errmean, errvar: %i %f %f\n", nberr, errmeantot, errvartot);
#endif  // PRINT_ERRS

    return relerr;
}

int on_border(int i, int * activepix, int nbact, int sizex, int size2)
{
    int p1 = i - sizex;
    int p2 = i - 1;
    int p3 = i + 1;
    int p4 = i + sizex;
    int p5 = i - size2;
    int p6 = i + size2;

    int count = 0;
    for (size_t k = 0; k < nbact; ++k) {
        int j = activepix[k];
        if (j == p1 || j == p2 || j == p3 || j == p4 || j == p5 || j == p6) {
            count += 1;
            if (count == 6) return 0;
        }
    }
    return 1;
}

int nbconv;

float * gausskerpar(int sx, int sy, int sz, float radius, float radiusz)
{
    float * out;
    int errnopos = brecs_memalign((void **)&out,
                                 sx * sy * sz * sizeof(float));
    if (!out) brecs_error("Failed to allocate memory for gaussker: ",
                          strerror(errnopos), prog_name);

    float sig2 = radius * radius;
    float sig2z = radiusz * radiusz;
    for (int z = -sz / 2; z < sz / 2 ; ++z) {
        float dz2 = (float)(z * z);
        for (int y = -sy / 2; y < sy / 2 ; ++y) {
            float dy2 = (float)(y * y);
            for (int x = -sx / 2; x < sx / 2; ++x) {
                float dx2 = (float)(x * x);
                float r2 = dx2 + dy2;
                float val = expf(-r2 / 2.0f / sig2 - dz2 / 2.0f / sig2z)
                            / (2.0f * M_PIf * sig2) / sqrtf(2.0f * M_PIf * sig2z);
                int col = x;
                int line = y;
                int dep = z;
                if (x < 0) col += sx;
                if (y < 0) line += sy;
                if (z < 0) dep += sz;

                out[col + line * sx + dep * sx * sy] = val;
            }
        }
    }
    return out;
}

float * gausskerpar2d(int sx, int sy, float radius)
{
    float * out;
    int errnopos = brecs_memalign((void **)&out,
                                sx * sy * sizeof(float));
    if (!out) brecs_error("Failed to allocate memory for gaussker: ",
                          strerror(errnopos), prog_name);

    float sig2 = radius * radius;
    for (int y = -sy / 2; y < sy / 2 ; ++y) {
        float dy2 = (float)(y * y);
        for (int x = -sx / 2; x < sx / 2; ++x) {
            float dx2 = (float)(x * x);
            float r2 = dx2 + dy2;
            float val = expf(-r2 / 2.0f / sig2) / (2.0f * M_PIf * sig2);
            int col = x;
            int line = y;
            if (x < 0) col += sx;
            if (y < 0) line += sy;

            out[col + line * sx] = val;
        }
    }
    return out;
}

float * recons_ccomp(float * imgmes, float * imgnoise, int nbmes3,
                     int * activepix, unsigned nbact,
                     float * ker, float * ker2,
                     int sizex, int sizey, int sizez)
{
    float * imgnoisecp;
    float * mu_albe_A;
    float * mu_albe_B;
    float * mu_beal_A;
    float * mu_beal_B;
    float * sum_mualbe_A;
    float * sum_mualbe_B;
    float * abeal;
    float * vbeal;
    float * P_be_E;
    float * P_be_F;
    float * omegamu;
    float * vmu;

    int size2 = sizex * sizey;
    int size3 = size2 * sizez;


    float * res;

    int errnopos = brecs_memalign((void **)&imgnoisecp,nbmes3 * sizeof(float));
    if (!imgnoisecp) brecs_error("Failed to allocate memory for imgnoisecp: ",
                                 strerror(errnopos), prog_name);

    for (int i = 0; i < nbmes3; ++i) {
        imgnoisecp[i] = imgnoise[i];
    }

    /* Memory allocation */
    errnopos = brecs_memalign((void **)&mu_albe_A,
                              nbact * kersize3 * sizeof(float));
    if (!mu_albe_A) brecs_error("Failed to allocate memory for mu_albe_A: ",
                                strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&mu_albe_B,
                              nbact * kersize3 * sizeof(float));
    if (!mu_albe_B) brecs_error("Failed to allocate memory for mu_albe_B: ",
                                strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&mu_beal_A,
                              nbact * kersize3 * sizeof(float));
    if (!mu_beal_A) brecs_error("Failed to allocate memory for mu_beal_A: ",
                                strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&mu_beal_B,
                              nbact * kersize3 * sizeof(float));
    if (!mu_beal_B) brecs_error("Failed to allocate memory for mu_beal_B: ",
                                strerror(errnopos), prog_name);
    vbeal = mu_beal_A;
    abeal = mu_beal_B;

    errnopos = brecs_memalign((void **)&P_be_E,
                              nbact * sizeof(float));
    if (!P_be_E) brecs_error("Failed to allocate memory for P_be_E: ",
                             strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&P_be_F,
                             nbact * sizeof(float));
    if (!P_be_F) brecs_error("Failed to allocate memory for P_be_F: ",
                             strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&sum_mualbe_A,
                             nbact * shift * sizeof(float));
    if (!sum_mualbe_A)
        brecs_error("Failed to allocate memory for sum_mualbe_A: ",
                    strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&sum_mualbe_B,
                             nbact * shift * sizeof(float));
    if (!sum_mualbe_B)
        brecs_error("Failed to allocate memory for sum_mualbe_B: ",
                    strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&omegamu,
                              nbmes3 * sizeof(float));
    if (!omegamu) brecs_error("Failed to allocate memory for omegamu ",
                              strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&vmu,
                              nbmes3 * sizeof(float));
    if (!vmu) brecs_error("Failed to allocate memory for vmu ",
                          strerror(errnopos), prog_name);

    float Binit = rho * pixmean * Ainit;

    for (unsigned i = 0; i < nbact * kersize3; ++i) {
        mu_albe_A[i] = Ainit;
        mu_albe_B[i] = Binit;
        vbeal[i] = Ainit;
        abeal[i] = Binit;
    }
    vecfloat vAinit = VFUNC(set1_ps) (Ainit);
    vecfloat vBinit = VFUNC(set1_ps) (Binit);
    for (unsigned i = 0; i < nbact; ++i) {
        P_be_E[i] = Ainit;
        P_be_F[i] = Binit;

        VFUNC(store_ps) (sum_mualbe_A + i * shift, vAinit);
        VFUNC(store_ps) (sum_mualbe_B + i * shift, vBinit);
    }

    /* Main loop */
    float relerr = 1.0;
    int iter = 0;
    // printf("nbiter: %i\n", nbiter);
    while (relerr > relerrthr && iter < nbiter) {
    // for (int iter = 0; iter < nbiter; ++iter) {
        iter++;
        /* Internal loop */
        for (unsigned int j = 0; j < nbinternloop; ++j) {
            update_mubeal(vbeal, abeal,
                    mu_albe_A, mu_albe_B,
                    P_be_E, P_be_F,
                    sum_mualbe_A, sum_mualbe_B,
                    nbact, activepix);

            update_mualbe(mu_albe_A, mu_albe_B,
                    sum_mualbe_A, sum_mualbe_B,
                    abeal, vbeal,
                    omegamu, vmu,
                    ker, ker2,
                    imgnoisecp, imgmes,
                    nbact, activepix,
                    sizex, sizey, sizez);
            // printf("relerr: %f\n", relerr);
        }

        /* External loop */
        int iterpbe = 1;

        relerr = update_pbe(P_be_E, P_be_F,
                            vbeal, abeal,
                            nbact, activepix,
                            iterpbe);
        if (iter < 200) relerr = 1.0;

        // printf("iteration, relerr: %i, %f\n", iter, relerr);
    }

    if (relerr < 1.01 * relerrthr) nbconv++;

    errnopos = brecs_memalign((void **)&res, size3 * sizeof(float));
    if (!res) brecs_error("Failed to allocate memory for res ",
                          strerror(errnopos), prog_name);

    for (int i = 0; i < size3; ++i) {
        res[i] = 0;
    }
    // if (relerr < 1.1 * relerrthr){
        for (unsigned int k = 0; k < nbact; ++k) {
            float val = P_be_F[k] / P_be_E[k];
            res[activepix[k]] += val;
            //res[activepix[k]] = 100;
        }
        static int nbfluo = 1;
        for (int i = 0; i < size3; ++i) {
            int c = (i % size2) % sizex;
            int l = (i % size2) / sizex;
            int z = i / size2;
            if (res[i] > locaintensthr
                && !on_border(i, activepix, nbact, sizex, size2)) {
                printf("%d %s %.2f %.2f %.2f %.2f\n",
                        nbfluo,
                        brecs_args.filename_arg,
                        (c - kersize / 2 * pixsdiv) * spixnm + spixnm / 2,
                        (l - kersize / 2 * pixsdiv) * spixnm + spixnm / 2,
                        z * spixznm,
                        res[i]);
                nbfluo++;
            }
        }

    brecs_free(mu_albe_A);
    brecs_free(mu_albe_B);
    brecs_free(mu_beal_A);
    brecs_free(mu_beal_B);
    brecs_free(P_be_E);
    brecs_free(P_be_F);
    brecs_free(sum_mualbe_A);
    brecs_free(sum_mualbe_B);
    brecs_free(omegamu);
    brecs_free(vmu);
    brecs_free(imgnoisecp);

    return res;
}

void plot_overlay(float * imgmes, float * imgrecons,
                  unsigned int sx, unsigned int sy, unsigned int sz,
                  unsigned int mx, unsigned int my, unsigned int mz,
                  const char * fname)
{
    unsigned i;

    unsigned int long size2 = sx * sy;
    unsigned int long size3 = sx * sy * sz;

    unsigned int long nbmes2 = mx * my;
    unsigned int long nbmes3 = mx * my * mz;

    uint8_t * img_data = brecs_alloc(3 * size3 * sizeof(uint8_t));
    float maxrc = 0;
    for (i = 0 ; i < size3 ; i++) {
        if (maxrc < imgrecons[i]) maxrc = imgrecons[i];
    }
    printf("Maxrecons : %f\n", maxrc);

    float max2 = 0;
    float min2 = 0;
    for (i = 0 ; i < nbmes3 ; i++) {
        if (max2 < imgmes[i]) max2 = imgmes[i];
        if (min2 > imgmes[i]) min2 = imgmes[i];
    }

    for (unsigned i = 0; i < size3; ++i) {
        int x = i % sx;
        int y = (i % size2) / sx;
        int z = i / size2;
        float val = imgrecons[i];
        uint8_t * cimgd = img_data + i * 3;
        if (val > overlayminint) {
            if (val > overlaymaxint) val = overlaymaxint;
            cimgd[0] = (uint8_t)(255.0 * (log(val) - log(overlayminint))
                / (log(overlaymaxint) - log(overlayminint)));
            cimgd[1] = 0;
            cimgd[2] = 0;
        } else {
            uint8_t val = (uint8_t)( 255 / (max2 - min2)
                * (imgmes[(y / pixsdiv + kersize / 2) * mx + x / pixsdiv + kersize / 2
                          + (z / pixsdivz + kersizez / 2) * nbmes2] - min2));
            cimgd[0] = val;
            cimgd[1] = val;
            cimgd[2] = val;
        }
    }
    writetiff_rgb(fname, sx, sy, sz, img_data);
    // (ngc) FIXME? img_data leaked
}



float * reconssparse(float * imgmes, float * imgnoise,
                     int nbmesx, int nbmesy, int nbmesz)
{
    printf("Extracting connected components\n");
    ccomp_dec ccdec;
    if (nbmesz == 1) {
        ccdec = connectcomp_decomp2d(imgmes, nbmesx, nbmesy);
    } else {
        ccdec = connectcomp_decomp3d(imgmes, nbmesx, nbmesy, nbmesz);
    }


    float * ker;
    float * ker2;
    int errnopos = brecs_memalign((void **)&ker2,
                   pixsdiv3 * kersize3 * sizeof(float));
    if (!ker2) brecs_error("Failed to allocate memory for ker2 ",
                           strerror(errnopos), prog_name);

    /* Initialize kernels */
    printf("Initializing kernel\n");
    int sx, sy, sz;
    ker = opentiff_f(brecs_args.psf_arg, &sx, &sy, &sz);
    if (sx != kersize || sy != kersize * kersizez || sz != pixsdiv3) {
        printf("invalid psf size: %d %d %d\n", sx, sy, sz);
        printf("should be: %d %d %d\n", kersize, kersize * kersizez,
                                        pixsdiv3);
        exit(EXIT_FAILURE);
    }
    for (unsigned int i = 0; i < pixsdiv3 * kersize3; ++i) {
        ker2[i] = ker[i] * ker[i];
    }

    nbconv = 0;

    unsigned sizex = pixsdiv * (nbmesx - kersize);
    unsigned sizey = pixsdiv * (nbmesy - kersize);
    unsigned size2 = sizex * sizey;
    unsigned sizez = pixsdivz * (nbmesz - kersizez + kersizez % 2);
    unsigned size3 = sizex * sizey * sizez;

    float * reconspic = brecs_alloc(size3 * sizeof(float));
    for (unsigned int i = 0; i < size3; ++i) {
        reconspic[i] = 0;
    }

    printf("recons first comp\n");
    for (unsigned int i = 0; i < ccdec.nbcomp; ++i) {
    //for (unsigned int i = 0; i < 2; ++i) {
        printf("Processing connected component %40d / %d\r",
               i + 1, ccdec.nbcomp);
        fflush(stdout);
        float * rectmp = recons_ccomp(imgmes, imgnoise, nbmesx * nbmesy * nbmesz,
                                      ccdec.activepixcomp[i], ccdec.nbact[i],
                                      ker, ker2,
                                      sizex, sizey, sizez);
        for (unsigned int i = 0; i < size3; ++i) {
            reconspic[i] += rectmp[i];
        }
        brecs_free(rectmp);
    }
    printf("\n");
    for (unsigned int i = 0; i < ccdec.nbcomp; ++i) {
        brecs_free(ccdec.activepixcomp[i]);
    }
    brecs_free(ccdec.nbact);
    brecs_free(ccdec.coordcomp);
    brecs_free(ccdec.activepixcomp);
    brecs_free(ccdec.imglab);

#if BRECS_DISPLAYPLOTS
    plot_overlay(imgmes, reconspic,
                 sizex, sizey, sizez, nbmesx, nbmesy, nbmesz,
                 "overlay.tif");
#endif

    if (brecs_args.output_arg){
        writetiff_f(brecs_args.output_arg, sizex, sizey, sizez, reconspic);
    }

    brecs_free(reconspic);
    printf("Converged: %i / %i\n", nbconv, ccdec.nbcomp);

    return NULL;
}

/* Decompose an image into connected components */

lab_t * roundker(int diam, int diamz)
{
    int center = diam / 2;
    int centerz = diamz / 2;
    lab_t * ker = brecs_alloc(diam * diam * diamz * sizeof(lab_t));
    for (size_t k = 0; k < diamz; k++) {
        for (size_t j = 0; j < diam; j++) {
            for (size_t i = 0; i < diam; i++) {
                size_t x = i - center;
                size_t y = j - center;
                size_t z = k - centerz;
                float rad2 = (float)(x * x + y * y);
                float rad2z = (float)(z * z);
                size_t ind = i + j * diam + k * diam * diam;
                if (rad2 / (center * center) + rad2z / (centerz * centerz) < 1.0) {
                    ker[ind] = 1;
                } else {
                    ker[ind] = 0;
                }
            }
        }
    }
    return ker;
}

lab_t * roundker2d(int diam)
{
    int center = diam / 2;
    lab_t * ker = brecs_alloc(diam * diam * sizeof(lab_t));
    for (size_t j = 0; j < diam; j++) {
        for (size_t i = 0; i < diam; i++) {
            size_t x = i - center;
            size_t y = j - center;
            float rad2 = (float)(x * x + y * y);
            size_t ind = i + j * diam;
            if (rad2 < center * center) {
                ker[ind] = 1;
            } else {
                ker[ind] = 0;
            }
        }
    }
    return ker;
}

void maskpix(lab_t * img, int width, int height, lab_t * ker,
             int diam, int diamz, int x, int y, int z) {
    for (size_t k = 0; k < diamz; k++) {
        for (size_t j = 0; j < diam; j++) {
            for (size_t i = 0; i < diam; i++) {
                size_t ind = x + i - diam / 2
                          + (y + j - diam / 2) * width
                          + (z + k - diamz / 2) * width * height;
                img[ind] = img[ind] || ker[i + j * diam + k * diam * diam];
            }
        }
    }
}

void maskpix2d(lab_t * img, int width, int height, lab_t * ker,
        int diam, int x, int y) {
    for (size_t j = 0; j < diam; j++) {
        for (size_t i = 0; i < diam; i++) {
            size_t ind = x + i - diam / 2 + (y + j - diam / 2) * width;
            img[ind] = img[ind] || ker[i + j * diam];
        }
    }
}

lab_t neighb(lab_t * img, int width, int height, int x, int y, int z)
{
    int plane = width * height;
    if (!img[x - 1 + (y - 1) * width + z * plane]
        || !img[x + (y - 1) * width + z * plane]
        || !img[x + 1 + (y - 1) * width + z * plane]
        || !img[x - 1 + y * width + z * plane]
        || !img[x + 1 + y * width + z * plane]
        || !img[x - 1 + (y + 1) * width + z * plane]
        || !img[x + (y + 1) * width + z * plane]
        || !img[x + 1 + (y + 1) * width + z * plane]

        || !img[x - 1 + (y - 1) * width + (z - 1) * plane]
        || !img[x + (y - 1) * width + (z - 1) * plane]
        || !img[x + 1 + (y - 1) * width + (z - 1) * plane]
        || !img[x - 1 + y * width + (z - 1) * plane]
        || !img[x + 1 + y * width + (z - 1) * plane]
        || !img[x + y * width + (z - 1) * plane]
        || !img[x - 1 + (y + 1) * width + (z - 1) * plane]
        || !img[x + (y + 1) * width + (z - 1) * plane]
        || !img[x + 1 + (y + 1) * width + (z - 1) * plane]

        || !img[x - 1 + (y - 1) * width + (z + 1) * plane]
        || !img[x + (y - 1) * width + (z + 1) * plane]
        || !img[x + 1 + (y - 1) * width + (z + 1) * plane]
        || !img[x - 1 + y * width + (z + 1) * plane]
        || !img[x + 1 + y * width + (z + 1) * plane]
        || !img[x + y * width + (z + 1) * plane]
        || !img[x - 1 + (y + 1) * width + (z + 1) * plane]
        || !img[x + (y + 1) * width + (z + 1) * plane]
        || !img[x + 1 + (y + 1) * width + (z + 1) * plane])
        return 1;
    return 0;
}

lab_t neighb2d(lab_t * img, int width, int height, int x, int y)
{
    int plane = width * height;
    if (!img[x - 1 + (y - 1) * width]
        || !img[x + (y - 1) * width]
        || !img[x + 1 + (y - 1) * width]
        || !img[x - 1 + y * width]
        || !img[x + 1 + y * width]
        || !img[x - 1 + (y + 1) * width]
        || !img[x + (y + 1) * width]
        || !img[x + 1 + (y + 1) * width])
        return 1;
    return 0;
}

lab_t * dilate(lab_t * img, int width, int height, int depth,
               lab_t * ker, int diam, int diamz)
{
    lab_t * res = brecs_alloc(width * height * depth * sizeof(lab_t));
    for (size_t i = 0; i < width * height * depth; ++i) {
        res[i] = img[i];
    }
    for (size_t k = 0; k < depth; k++) {
        for (size_t j = 0; j < height; j++) {
            for (size_t i = 0; i < width; i++) {
                if (img[i + j * width + k * width * height]
                        && neighb(img, width, height, (int)i, (int)j, (int)k)) {
                    maskpix(res, width, height, ker, diam, diamz, (int)i, (int)j, (int)k);
                }
            }
        }
    }
    return res;
}

lab_t * dilate2d(lab_t * img, int width, int height, lab_t * ker, int diam)
{
    lab_t * res = brecs_alloc(width * height * sizeof(lab_t));
    for (size_t i = 0; i < width * height; ++i) {
        res[i] = img[i];
    }
    for (size_t j = 0; j < height; j++) {
        for (size_t i = 0; i < width; i++) {
            if (img[i + j * width]
                    && neighb2d(img, width, height, (int)i, (int)j)) {
                maskpix2d(res, width, height, ker, diam, (int)i, (int)j);
            }
        }
    }
    return res;
}

void unionsets(lab_t * labs, int lastlab, int parentlab, int lab)
{
    if (lab != parentlab) {
        for (int i = lab - 1; i < lastlab; ++i) {
            if (labs[i] == lab) {
                labs[i] = parentlab;
            }
        }
    }
}

uint8_t * genrandomcolo(lab_t nbcol) {
    uint8_t * cols = brecs_alloc(3 * nbcol * sizeof(uint8_t));
    uint8_t mix[3] = {240, 240, 240};
    for (unsigned int i = 0; i < nbcol; ++i) {
        uint8_t red   = (uint8_t)(drand48() * 256); 
        uint8_t green = (uint8_t)(drand48() * 256);
        uint8_t blue  = (uint8_t)(drand48() * 256);

        cols[i * 3] = (red + mix[0]) / 2;
        cols[1 + i * 3] = (green + mix[1]) / 2;
        cols[2 + i * 3] = (blue + mix[2]) / 2;
    }

    return cols;
}

ccomp_dec aggregate(lab_t * img, lab_t * imgdil,
                    int width, int height, int depth)
{
    ccomp_dec ccdec;
    lab_t labs[MAX_LABEL];

    lab_t * imglabs = brecs_alloc(width * height * depth * sizeof(lab_t));

    for (int i = 0; i < width * height * depth; i++) {
        imglabs[i] = 0;
    }

    uint32_t plane = width * height;

    lab_t lastlab = 0;
    for (int k = 1; k < depth - 1; k++) {
        for (int j = 1; j < height - 1; j++) {
            for (int i = 1; i < width - 1; i++) {
                int ind = i + j * width + k * width * height;
                if (imgdil[ind]) {
                    lab_t lab4[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    lab_t lab4p[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    size_t nlab = 0;
                    lab4[0] = imglabs[ind - width - 1 - plane];
                    lab4[1] = imglabs[ind - width - plane];
                    lab4[2] = imglabs[ind - width + 1 - plane];
                    lab4[3] = imglabs[ind - 1 - plane];
                    lab4[4] = imglabs[ind - plane];
                    lab4[5] = imglabs[ind + 1 - plane];
                    lab4[6] = imglabs[ind + width - 1 - plane];
                    lab4[7] = imglabs[ind + width - plane];
                    lab4[8] = imglabs[ind + width + 1 - plane];

                    lab4[9] = imglabs[ind - width - 1];
                    lab4[10] = imglabs[ind - width];
                    lab4[11] = imglabs[ind - width + 1];
                    lab4[12] = imglabs[ind - 1];
                    lab_t minlab = MAX_LABEL;
                    if (lab4[0]) {
                        minlab = lab4[0];
                        lab4p[0] = minlab;
                        nlab++;
                    }
                    for (size_t i = 1; i < 13; ++i) {
                        if (lab4[i]) {
                            if (lab4[i] < minlab) minlab = lab4[i];
                            lab4p[nlab] = lab4[i];
                            nlab++;
                        }
                    }

                    if (nlab > 2) {
                        for (int k = 0; k < nlab; ++k) {
                            unionsets(labs, lastlab, minlab, lab4p[k]);
                        }
                    }
                    if (!nlab) {
                        lastlab++;
                        labs[lastlab - 1] = lastlab;
                        imglabs[ind] = lastlab;
                    } else {
                        imglabs[ind] = minlab;
                    }
                }
            }
        }
    }
    int clab = 0;
    int clab2 = 0;
    for (unsigned int i = 0; i < lastlab; ++i) {
        if (labs[i] > clab2) {
            clab2 = labs[i];
            clab++;
            labs[i] = clab;
        } else {
            labs[i] = labs[labs[i] - 1];
        }
    }
    ccdec.nbcomp = clab;
    ccdec.coordcomp = brecs_alloc(clab * 4 * sizeof(int));
    ccdec.nbact = brecs_alloc(clab * sizeof(int));
    ccdec.activepixcomp = brecs_alloc(clab * sizeof(int *));
    for (int i = 0; i < clab; ++i) {
        ccdec.coordcomp[4 * i] = width;
        ccdec.coordcomp[4 * i + 1] = 0;
        ccdec.coordcomp[4 * i + 2] = height;
        ccdec.coordcomp[4 * i + 3] = 0;
        ccdec.nbact[i] = 0;
    }
    for (int k = 0; k < depth; k++) {
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                int ind = i + j * width + k * width * height;

                if (img[ind]) {
                    lab_t lab = labs[imglabs[ind] - 1];
                    int * coord = ccdec.coordcomp + 4 * (lab - 1);
                    if (j < coord[0]) coord[0] = j;
                    if (j > coord[1]) coord[1] = j;
                    if (i < coord[2]) coord[2] = i;
                    if (i > coord[3]) coord[3] = i;
                    imglabs[ind] = lab;
                    ccdec.nbact[lab - 1] += 1;
                }
            }
        }
    }
    for (int i = 0; i < clab; ++i) {
        ccdec.activepixcomp[i] = brecs_alloc(ccdec.nbact[i] * sizeof(int));
        ccdec.nbact[i] = 0;
    }
    int offset = pixsdiv * kersize / 2;
    int offsetz = pixsdivz * (kersizez / 2);
    int widthdef = width - pixsdiv * kersize;
    int heightdef = height - pixsdiv * kersize;
    for (int k = 0; k < depth; k++) {
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                int ind = i + j * width + k * width * height;

                if (img[ind]) {
                    lab_t lab = imglabs[ind];
                    ccdec.activepixcomp[lab - 1][ccdec.nbact[lab - 1]] =
                        i - offset + (j - offset) * widthdef
                        + (k - offsetz) * widthdef * heightdef;
                    ccdec.nbact[lab - 1] += 1;
                }
            }
        }
    }

#if BRECS_DISPLAYPLOTS
    uint8_t * cols = genrandomcolo(clab);
    uint8_t * imgccmprgb = brecs_alloc(plane * depth * 3 * sizeof(uint8_t));

    for (unsigned int i = 0; i < plane * depth; ++i) {
        if (img[i]) {
            imgccmprgb[3 * i] = cols[3 * imglabs[i] - 3];
            imgccmprgb[1 + 3 * i] = cols[1 + 3 * imglabs[i] - 3];
            imgccmprgb[2 + 3 * i] = cols[2 + 3 * imglabs[i] - 3];
        } else {
            imgccmprgb[3 * i] = 0;
            imgccmprgb[1 + 3 * i] = 0;
            imgccmprgb[2 + 3 * i] = 0;
        }
    }
    brecs_free(cols);
    writetiff_rgb("connected_comp.tif", width, height, depth, imgccmprgb);
    brecs_free(imgccmprgb);
#endif

    ccdec.imglab = imglabs;
    return ccdec;
}

ccomp_dec aggregate2d(lab_t * img, lab_t * imgdil,
                      int width, int height)
{
    ccomp_dec ccdec;
    lab_t labs[MAX_LABEL];

    lab_t * imglabs = brecs_alloc(width * height * sizeof(lab_t));

    for (int i = 0; i < width * height; i++) {
        imglabs[i] = 0;
    }

    uint32_t plane = width * height * pixsdivz;

    lab_t lastlab = 0;
    for (int j = 1; j < height - 1; j++) {
        for (int i = 1; i < width - 1; i++) {
            int ind = i + j * width;
            if (imgdil[ind]) {
                lab_t lab4[4] = {0, 0, 0, 0};
                lab_t lab4p[4] = {0, 0, 0, 0};
                size_t nlab = 0;
                lab4[0] = imglabs[ind - width - 1];
                lab4[1] = imglabs[ind - width];
                lab4[2] = imglabs[ind - width + 1];
                lab4[3] = imglabs[ind - 1];
                lab_t minlab = MAX_LABEL;
                if (lab4[0]) {
                    minlab = lab4[0];
                    lab4p[0] = minlab;
                    nlab++;
                }
                for (size_t i = 1; i < 4; ++i) {
                    if (lab4[i]) {
                        if (lab4[i] < minlab) minlab = lab4[i];
                        lab4p[nlab] = lab4[i];
                        nlab++;
                    }
                }

                if (nlab > 2) {
                    for (int k = 0; k < nlab; ++k) {
                        unionsets(labs, lastlab, minlab, lab4p[k]);
                    }
                }
                if (!nlab) {
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
        if (labs[i] > clab2) {
            clab2 = labs[i];
            clab++;
            labs[i] = clab;
        } else {
            labs[i] = labs[labs[i] - 1];
        }
    }
    ccdec.nbcomp = clab;
    ccdec.coordcomp = brecs_alloc(clab * 4 * sizeof(int));
    ccdec.nbact = brecs_alloc(clab * pixsdivz * sizeof(int));
    ccdec.activepixcomp = brecs_alloc(clab * sizeof(int *));
    for (int i = 0; i < clab; ++i) {
        ccdec.coordcomp[4 * i] = width;
        ccdec.coordcomp[4 * i + 1] = 0;
        ccdec.coordcomp[4 * i + 2] = height;
        ccdec.coordcomp[4 * i + 3] = 0;
        ccdec.nbact[i] = 0;
    }
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int ind = i + j * width;

            if (img[ind]) {
                lab_t lab = labs[imglabs[ind] - 1];
                int * coord = ccdec.coordcomp + 4 * (lab - 1);
                if (j < coord[0]) coord[0] = j;
                if (j > coord[1]) coord[1] = j;
                if (i < coord[2]) coord[2] = i;
                if (i > coord[3]) coord[3] = i;
                imglabs[ind] = lab;
                ccdec.nbact[lab - 1] += pixsdivz;
            }
        }
    }
    for (int i = 0; i < clab; ++i) {
        ccdec.activepixcomp[i] = brecs_alloc(ccdec.nbact[i] * sizeof(int));
        ccdec.nbact[i] = 0;
    }
    int offset = pixsdiv * kersize / 2;
    int widthdef = width - pixsdiv * kersize;
    int heightdef = height - pixsdiv * kersize;
    for (size_t k = 0; k < pixsdivz; ++k) {
        for (size_t j = 0; j < height; j++) {
            for (size_t i = 0; i < width; i++) {
                size_t ind = i + j * width;

                if (img[ind]) {
                    lab_t lab = imglabs[ind];
                    ccdec.activepixcomp[lab - 1][ccdec.nbact[lab - 1]] = (int)(
                        i - offset + (j - offset) * widthdef
                        + k * widthdef * heightdef);
                    ccdec.nbact[lab - 1] += 1;
                }
            }
        }
    }

#if BRECS_DISPLAYPLOTS
    uint8_t * cols = genrandomcolo(clab);
    uint8_t * imgccmprgb = brecs_alloc(plane * 3 * sizeof(uint8_t));

    for (unsigned int i = 0; i < plane; ++i) {
        if (img[i]) {
            imgccmprgb[3 * i] = cols[3 * imglabs[i] - 3];
            imgccmprgb[1 + 3 * i] = cols[1 + 3 * imglabs[i] - 3];
            imgccmprgb[2 + 3 * i] = cols[2 + 3 * imglabs[i] - 3];
        } else {
            imgccmprgb[3 * i] = 0;
            imgccmprgb[1 + 3 * i] = 0;
            imgccmprgb[2 + 3 * i] = 0;
        }
    }
    brecs_free(cols);
    writetiff_rgb("connected_comp.tif", width, height, pixsdivz, imgccmprgb);
    brecs_free(imgccmprgb);
#endif

    ccdec.imglab = imglabs;
    return ccdec;
}

ccomp_dec connectcomp_decomp3d(float * imgmes,
                               int nbmesx, int nbmesy, int nbmesz)
{
    unsigned long int sizex = nbmesx * pixsdiv;
    unsigned long int sizey = nbmesy * pixsdiv;
    unsigned long int sizez = nbmesz * pixsdivz;
    unsigned long int size2 = sizex * sizey;
    unsigned long int size3 = size2 * sizez;

    unsigned long int nbmes2 = nbmesx * nbmesy;
    unsigned long int nbmes3 = nbmesx * nbmesy * nbmesz;

    unsigned long int sxfft = (unsigned)(pow(2, (int)log2(sizex) + 1));
    unsigned long int syfft = (unsigned)(pow(2, (int)log2(sizey) + 1));
    unsigned long int sfft2 = (unsigned)(sxfft * syfft);
    unsigned long int szfft = (unsigned)(pow(2, (int)log2(sizez) + 1));

    printf("Smoothing\n");

    float * imgsmoo = fftwf_alloc_real(sxfft * syfft * szfft);
    if (!imgsmoo) exit(EXIT_FAILURE);
    for (unsigned int i = 0; i < sxfft * syfft * szfft; ++i) {
        imgsmoo[i] = 0;
    }
    unsigned long int max = 0;
    for (unsigned int i = 0; i < nbmes3; ++i) {
        float val = imgmes[i];
        unsigned long int ci = (i % nbmes2) % nbmesx;
        unsigned long int li = (i % nbmes2) / nbmesx;
        unsigned long int zi = i / nbmes2;
        for (unsigned int j = 0; j < pixsdiv3; ++j) {
            unsigned long int ind = ci * pixsdiv + j % pixsdiv
                      + sxfft * (li * pixsdiv + (j % pixsdiv2) / pixsdiv)
                      + sfft2 * (zi * pixsdivz + (j / pixsdiv2) % pixsdivz);
            imgsmoo[ind] = val;
        }
    }
    fftwf_complex * out1, * out2;
    fftwf_plan pforw1, pforw2, pbackw;

#if BRECS_DISPLAYPLOTS
    writetiff_f("befsmoothedimg.tif", sxfft, syfft, szfft, imgsmoo);
#endif

    float * imgker = gausskerpar(sxfft, syfft, szfft,
                                 prefacradcc * pixsdiv,
                                 prefacradcc * pixsdivz);

    out1 = fftwf_alloc_complex(szfft * syfft * (sxfft / 2 + 1));
    out2 = fftwf_alloc_complex(szfft * syfft * (sxfft / 2 + 1));

    pforw1 = fftwf_plan_dft_r2c_3d(szfft, syfft, sxfft,
                                   imgsmoo, out1,
                                   FFTW_ESTIMATE);
    pforw2 = fftwf_plan_dft_r2c_3d(szfft, syfft, sxfft,
                                   imgker, out2,
                                   FFTW_ESTIMATE);

    pbackw = fftwf_plan_dft_c2r_3d(szfft, syfft, sxfft,
                                   out1, imgsmoo,
                                   FFTW_ESTIMATE);

    fftwf_execute(pforw1);
    fftwf_execute(pforw2);
    fftwf_free(imgker);

    for (unsigned int i = 0; i < szfft * syfft * (sxfft / 2 + 1); ++i) {
        fftwf_complex c1, c2;
        c1[0] = out1[i][0];
        c1[1] = out1[i][1];
        c2[0] = out2[i][0];
        c2[1] = out2[i][1];

        out1[i][0] = (c1[0] * c2[0] - c1[1] * c2[1]) / (sxfft * syfft * szfft);
        out1[i][1] = (c1[0] * c2[1] + c1[1] * c2[0]) / (sxfft * syfft * szfft);
    }

    fftwf_execute(pbackw);

    fftwf_destroy_plan(pforw1);
    fftwf_destroy_plan(pforw2);
    fftwf_destroy_plan(pbackw);

#if BRECS_DISPLAYPLOTS
    writetiff_f("smoothedimg.tif", sxfft, syfft, szfft, imgsmoo);
#endif

    lab_t * imgccmp = brecs_alloc(size3 * sizeof(lab_t));
    for (unsigned int i = 0; i < size3; ++i) {
        imgccmp[i] = 0;
    }
    for (unsigned int k = pixsdivz * (kersizez / 2);
            k < sizez - pixsdivz * (kersizez / 2); ++k) {
        for (unsigned int j = pixsdiv * kersize / 2;
                j < sizey - pixsdiv * kersize / 2; ++j) {
            for (unsigned int i = pixsdiv * kersize / 2;
                    i < sizex - pixsdiv * kersize / 2; ++i) {
                if (imgsmoo[i + j * sxfft + k * sfft2] > convolpixthr) {
                    imgccmp[i + j * sizex + k * size2] = 1;
                }
            }
        }
    }

    uint8_t * imgthrrgb = brecs_alloc(3 * size3 * sizeof(uint8_t));
    for (unsigned int k = 0; k < sizez; ++k) {
        for (unsigned int j = 0; j < sizey; ++j) {
            for (unsigned int i = 0; i < sizex; ++i) {
                int ind = i + j * sizex + k * sizex * sizey;
                if (imgccmp[ind]) {
                    imgthrrgb[3 * ind] = 255;
                    imgthrrgb[1 + 3 * ind] = 255;
                    imgthrrgb[2 + 3 * ind] = 255;
                } else {
                    imgthrrgb[3 * ind] = 0;
                    imgthrrgb[1 + 3 * ind] = 0;
                    imgthrrgb[2 + 3 * ind] = 0;
                }
            }
        }
    }
    writetiff_rgb("imgthrrgb.tif", sizex, sizey, sizez, imgthrrgb);

    printf("thresholding over\n");

    lab_t * rker = roundker(pixsdiv * kersize / 2, pixsdivz * (kersizez / 2));
    printf("ker gen over\n");
    lab_t * imgdil = dilate(imgccmp, sizex, sizey, sizez,
                            rker,
                            pixsdiv * kersize / 2, pixsdivz * (kersizez / 2));

    printf("dilation over\n");

#if BRECS_DISPLAYPLOTS
    uint8_t * imgdilrgb = brecs_alloc(3 * size3 * sizeof(uint8_t));
    for (unsigned int k = 0; k < sizez; ++k) {
        for (unsigned int j = 0; j < sizey; ++j) {
            for (unsigned int i = 0; i < sizex; ++i) {
                int ind = i + j * sizex + k * sizex * sizey;
                if (imgdil[ind]) {
                    imgdilrgb[3 * ind] = 255;
                    imgdilrgb[1 + 3 * ind] = 255;
                    imgdilrgb[2 + 3 * ind] = 255;
                } else {
                    imgdilrgb[3 * ind] = 0;
                    imgdilrgb[1 + 3 * ind] = 0;
                    imgdilrgb[2 + 3 * ind] = 0;
                }
            }
        }
    }
    writetiff_rgb("imgdilrgb.tif", sizex, sizey, sizez, imgdilrgb);
    brecs_free(imgdilrgb);
#endif

    brecs_free(rker);
    ccomp_dec ccdec = aggregate(imgccmp, imgdil, sizex, sizey, sizez);

    brecs_free(imgdil);
    brecs_free(imgccmp);
    fftwf_free(out1);
    fftwf_free(out2);
    fftwf_free(imgsmoo);

    fftwf_cleanup();

    return ccdec;
}

ccomp_dec connectcomp_decomp2d(float * imgmes, int nbmesx, int nbmesy)
{
    unsigned long int sizex = nbmesx * pixsdiv;
    unsigned long int sizey = nbmesy * pixsdiv;
    unsigned long int size2 = sizex * sizey;

    unsigned long int nbmes2 = nbmesx * nbmesy;

    unsigned long int sxfft = (unsigned)(pow(2, (int)log2(sizex) + 1));
    unsigned long int syfft = (unsigned)(pow(2, (int)log2(sizey) + 1));
    unsigned long int sfft2 = (unsigned)(sxfft * syfft);

    float * imgsmoo = fftwf_alloc_real(sxfft * syfft);
    if (!imgsmoo) exit(EXIT_FAILURE);
    for (unsigned int i = 0; i < sxfft * syfft; ++i) {
        imgsmoo[i] = 0;
    }
    unsigned long int max = 0;
    for (unsigned int i = 0; i < nbmes2; ++i) {
        float val = imgmes[i];
        unsigned long int ci = i % nbmesx;
        unsigned long int li = i / nbmesx;
        for (unsigned int j = 0; j < pixsdiv2; ++j) {
            unsigned long int ind = ci * pixsdiv + j % pixsdiv
                      + sxfft * (li * pixsdiv + j / pixsdiv);
            imgsmoo[ind] = val;
        }
    }
    fftwf_complex * out1, * out2;
    fftwf_plan pforw1, pforw2, pbackw;

#if BRECS_DISPLAYPLOTS
    writetiff_f("befsmoothedimg.tif", sxfft, syfft, 1, imgsmoo);
#endif

    float * imgker = gausskerpar2d(sxfft, syfft, prefacradcc * pixsdiv);

    out1 = fftwf_alloc_complex(syfft * (sxfft / 2 + 1));
    out2 = fftwf_alloc_complex(syfft * (sxfft / 2 + 1));

    pforw1 = fftwf_plan_dft_r2c_2d(syfft, sxfft,
                                   imgsmoo, out1,
                                   FFTW_ESTIMATE);
    pforw2 = fftwf_plan_dft_r2c_2d(syfft, sxfft,
                                   imgker, out2,
                                   FFTW_ESTIMATE);

    pbackw = fftwf_plan_dft_c2r_2d(syfft, sxfft,
                                   out1, imgsmoo,
                                   FFTW_ESTIMATE);

    fftwf_execute(pforw1);
    fftwf_execute(pforw2);
    fftwf_free(imgker);

    for (unsigned int i = 0; i < syfft * (sxfft / 2 + 1); ++i) {
        fftwf_complex c1, c2;
        c1[0] = out1[i][0];
        c1[1] = out1[i][1];
        c2[0] = out2[i][0];
        c2[1] = out2[i][1];

        out1[i][0] = (c1[0] * c2[0] - c1[1] * c2[1]) / (sxfft * syfft);
        out1[i][1] = (c1[0] * c2[1] + c1[1] * c2[0]) / (sxfft * syfft);
    }

    fftwf_execute(pbackw);

    fftwf_destroy_plan(pforw1);
    fftwf_destroy_plan(pforw2);
    fftwf_destroy_plan(pbackw);

#if BRECS_DISPLAYPLOTS
    writetiff_f("smoothedimg.tif", sxfft, syfft, 1, imgsmoo);
#endif

    lab_t * imgccmp = brecs_alloc(size2 * sizeof(lab_t));
    for (unsigned int i = 0; i < size2; ++i) {
        imgccmp[i] = 0;
    }
    for (unsigned int j = pixsdiv * kersize / 2;
            j < sizey - pixsdiv * kersize / 2; ++j) {
        for (unsigned int i = pixsdiv * kersize / 2;
                i < sizex - pixsdiv * kersize / 2; ++i) {
            if (imgsmoo[i + j * sxfft] > convolpixthr) {
                imgccmp[i + j * sizex] = 1;
            }
        }
    }

#if BRECS_DISPLAYPLOTS
    uint8_t * imgthrrgb = brecs_alloc(3 * size2 * sizeof(uint8_t));
    for (unsigned int j = 0; j < sizey; ++j) {
        for (unsigned int i = 0; i < sizex; ++i) {
            int ind = i + j * sizex;
            if (imgccmp[ind]) {
                imgthrrgb[3 * ind] = 255;
                imgthrrgb[1 + 3 * ind] = 255;
                imgthrrgb[2 + 3 * ind] = 255;
            } else {
                imgthrrgb[3 * ind] = 0;
                imgthrrgb[1 + 3 * ind] = 0;
                imgthrrgb[2 + 3 * ind] = 0;
            }
        }
    }
    writetiff_rgb("imgthrrgb.tif", sizex, sizey, 1, imgthrrgb);
#endif

    lab_t * rker = roundker2d(pixsdiv * kersize / 2);
    lab_t * imgdil = dilate2d(imgccmp, sizex, sizey,
                              rker,
                              pixsdiv * kersize / 2);

#if BRECS_DISPLAYPLOTS
    uint8_t * imgdilrgb = brecs_alloc(3 * size2 * sizeof(uint8_t));
    for (unsigned int j = 0; j < sizey; ++j) {
        for (unsigned int i = 0; i < sizex; ++i) {
            int ind = i + j * sizex;
            if (imgdil[ind]) {
                imgdilrgb[3 * ind] = 255;
                imgdilrgb[1 + 3 * ind] = 255;
                imgdilrgb[2 + 3 * ind] = 255;
            } else {
                imgdilrgb[3 * ind] = 0;
                imgdilrgb[1 + 3 * ind] = 0;
                imgdilrgb[2 + 3 * ind] = 0;
            }
        }
    }
    writetiff_rgb("imgdilrgb.tif", sizex, sizey, 1, imgdilrgb);
    brecs_free(imgdilrgb);
#endif

    brecs_free(rker);
    ccomp_dec ccdec = aggregate2d(imgccmp, imgdil, sizex, sizey);

    brecs_free(imgdil);
    brecs_free(imgccmp);
    fftwf_free(out1);
    fftwf_free(out2);
    fftwf_free(imgsmoo);

    fftwf_cleanup();

    return ccdec;
}

/* Notes: calls exit on error. */
void brecs(struct images images,struct params params) {
    float * imgmes;
    float * imgker;
    float * imgnoise;
    float * imgrecons;

    const int insx=images.insz.x;
    const int insy=images.insz.y;
    const int insz=images.insz.z;

    const unsigned long int nbmesx = insx + kersize;
    const unsigned long int nbmesy = insy + kersize;
    const unsigned long int nbmesz = insz + kersizez - kersizez % 2;
    const unsigned long int nbmes2 = nbmesx * nbmesy;
    const unsigned long int nbmes3 = nbmes2 * nbmesz;
    const unsigned long int sizex = insx * pixsdiv;
    const unsigned long int sizey = insy * pixsdiv;
    const unsigned long int sizez = insz * pixsdivz;
    const unsigned long int size2 = sizex * sizey;
    const unsigned long int size3 = size2 * sizez;

    int errnopos = brecs_memalign((void **)&imgmes,
                                 nbmes3 * sizeof(float));
    if (!imgmes) brecs_error("Failed to allocate memory for imgmes: ",
                             strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&imgnoise,
                          nbmes3 * sizeof(float));
    if (!imgnoise) brecs_error("Failed to allocate memory for imgnoise: ",
                               strerror(errnopos), prog_name);

    errnopos = brecs_memalign((void **)&imgker,
                   kersize3 * pixsdiv3 * sizeof(float));
    if (!imgker) brecs_error("Failed to allocate memory for imgker: ",
                             strerror(errnopos), prog_name);

    for (unsigned int i = 0; i < nbmes3; ++i) {
        imgnoise[i] = 1e8;
        imgmes[i] = 0;
    }
    for (unsigned int k = 0; k < (unsigned)insz; ++k) {
        for (unsigned int j = 0; j < (unsigned)insy; ++j) {
            for (unsigned int i = 0; i < (unsigned)insx; ++i) {
                float val = images.img[i + j * insx + k * insx * insy];
                val = (val - mesoffset) / mesampli;

                float pixmes;
                if (brecs_args.background_arg) {
                    float valback = images.imgback[i + j * insx + k * insx * insy];
                    valback = (valback - mesoffset) / mesampli;
                    pixmes = val - valback;
                } else {
                    pixmes = val - meanback;
                }
                int ind = i + kersize / 2 + (j + kersize / 2) * nbmesx
                          + (k + kersizez / 2) * nbmesx * nbmesy;
                imgmes[ind] = pixmes;
                imgnoise[ind] = noiseoffset + 1.0f * val;
            }
        }
    }
    brecs_free(images.img);

#if BRECS_DISPLAYPLOTS
    writetiff_f("imgmes.tif", nbmesx, nbmesy, nbmesz, imgmes);
    writetiff_f("imgnoise.tif", nbmesx, nbmesy, nbmesz, imgnoise);
#endif

    imgrecons = reconssparse(imgmes, imgnoise,
                             nbmesx, nbmesy, nbmesz);

    brecs_free(imgker);
    brecs_free(imgmes);
    brecs_free(imgnoise);
    brecs_free(imgrecons);
}

char * prog_name;

int main(int argc, char ** argv)
{
    struct images images;
    struct params params=read_params("parameters.sqlite3");

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

    brecs(images,params);
    return EXIT_SUCCESS;
}

