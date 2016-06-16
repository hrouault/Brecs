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
#include "Brecs.h"


/* Constant definitions */
#include "error.h"
#include "inoutimg.h"

char * prog_name = "BRECS";


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

extern uint32_t nbconv;

static void fafcfunc(float * out, float sig2, float r, params_t * par);

static void update_omegavmu(float * omegamu, float * vmu,
                            float * ker, float * ker2,
                            float * abeal, float * vbeal,
                            uint32_t nbact, uint32_t * activepix,
                            veci3 * srec, params_t * par);

static void update_Palbe(afloat * mu_albe_A, afloat * mu_albe_B,
                         afloat * abeal, afloat * vbeal,
                         float * sum_mualbe_A, float * sum_mualbe_B,
                         afloat * omegamu, afloat * vmu,
                         afloat * ker, afloat * ker2,
                         afloat * imgnoise, afloat * imgmes,
                         uint32_t nbact, uint32_t * activepix,
                         veci3 * srec, params_t * par);

static void update_mualbe(float * mu_albe_A, float * mu_albe_B,
                          float * sum_mualbe_A, float * sum_mualbe_B,
                          float * abeal, float * vbeal,
                          float * omegamu, float * vmu,
                          float * ker, float * ker2,
                          float * imgnoise, float * imgmes,
                          uint32_t nbact, uint32_t * activepix,
                          veci3 * srec, params_t * par);

static void update_mubeal(float * vbeal, float * abeal,
                          float * mu_albe_A, float * mu_albe_B,
                          float * P_be_E, float * P_be_F,
                          float * sum_mualbe_A, float * sum_mualbe_B,
                          uint32_t nbact, params_t * par);

static float update_pbe(float * P_be_E, float * P_be_F,
                        float * P_albe_A, float * P_albe_B,
                        uint32_t nbact, params_t * par);

uint8_t on_border(uint32_t i, uint32_t* activepix, uint32_t nbact,
                  uint32_t sizex, uint32_t size2);

float * gausskerpar(uint32_t sx, uint32_t sy, uint32_t sz,
                    float radius, float radiusz);

float * gausskerpar2d(uint32_t sx, uint32_t sy, float radius);

float * recons_ccomp(float * imgmes, float * imgnoise, uint32_t nbmes3,
                     uint32_t * activepix, uint32_t nbact,
                     float * ker, float * ker2, veci3 * srec, params_t * par);

uint8_t * create_overlay(float * imgmes, float * imgrecons,
                         veci3 * srec, veci3 * smes, params_t * par);

lab_t * roundker(uint32_t diam, uint32_t diamz);

lab_t * roundker2d(uint32_t diam);

void maskpix(lab_t * img, uint32_t width, uint32_t height, lab_t * ker,
             uint32_t diam, uint32_t diamz,
             uint32_t x, uint32_t y, uint32_t z);
void maskpix2d(lab_t * img, uint32_t width, lab_t * ker,
        uint32_t diam, uint32_t x, uint32_t y);

lab_t neighb(lab_t * img, uint32_t width, uint32_t height,
             uint32_t x, uint32_t y, uint32_t z);
lab_t neighb2d(lab_t * img, uint32_t width, uint32_t x, uint32_t y);

lab_t * dilate(lab_t * img, uint32_t width, uint32_t height, uint32_t depth,
               lab_t * ker, uint32_t diam, uint32_t diamz);
lab_t * dilate2d(lab_t * img, uint32_t width, uint32_t height,
                 lab_t * ker, uint32_t diam);
void unionsets(lab_t * labs, uint16_t lastlab, uint16_t parentlab,
               uint16_t lab);

uint8_t * genrandomcolo(lab_t nbcol);
ccomp_dec aggregate(lab_t* img, lab_t* imgdil, veci3* size, params_t* par);
ccomp_dec aggregate2d(lab_t* img, lab_t* imgdil,
                      uint32_t width, uint32_t height, params_t* par);

static void updatetemp(float* imgnoise, params_t* par, uint32_t nbmes3)
{
    float c = powf(par->rho, par->beta);
    par->rho = c / (1 + c);

    for (unsigned int i = 0; i < nbmes3; ++i) {
        imgnoise[i] /= par->beta;
    }

    par->pixstd = par->pixstd / sqrtf(par->beta);
}

static void fafcfunc(float* out, float sig2, float r, params_t* par)
{
    float rho = par->rho;
    if (r > 5e4) r = 5e4;
    if (sig2 < 0) {
        sig2 = 1e6;
        r = 0;
    }
    float pstd2 = par->pixstd * par->pixstd;

    float deltr = (r - par->pixmean) * (r - par->pixmean);
    float varr = sig2 + pstd2;

    float fra = sqrtf(sig2 / varr);
    float fra1 = fra / varr;
    float fra2 = fra1 / varr;

    float argexp = -r * r / 2 / sig2 + deltr / 2 / varr;
    if (argexp > 25.0) {
        out[0] = 1e-10f;
        out[1] = 1e-3f;
        return;
    }
    float exprgauss = expf(argexp);

    float onemrho = 1 - par->rho;
    float onemrm1 = 1 / par->rho - 1;

    float sum1 = par->pixmean * sig2 + r * pstd2;
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

    if (out[0] < 1e-10) out[0] = 1e-10f;
    if (out[1] < 1e-3) out[1] = 1e-3f;
}

static void update_omegavmu(float * omegamu, float * vmu,
                            float * ker, float * ker2,
                            float * abeal, float * vbeal,
                            uint32_t nbact, uint32_t * activepix,
                            veci3 * srec, params_t * par)
{
    const vecfloat zero = VFUNC(set1_ps) (0);

    uint16_t pixsdiv = par->pixsdiv;
    uint16_t pixsdivz = par->pixsdivz;
    uint16_t pixsdiv2 = pixsdiv * pixsdiv;
    uint16_t kersize = par->kersize;
    uint32_t kersize2 = kersize * kersize;
    uint16_t kersizez = par->kersizez;
    uint32_t kersize3 = kersize2 * kersizez;

    uint32_t nbmesx = srec->x / pixsdiv + kersize;
    uint32_t nbmesy = srec->y / pixsdiv + kersize;
    uint32_t nbmesz = srec->z / pixsdivz + kersizez - kersizez % 2;
    uint32_t nbmes2 = nbmesx * nbmesy;
    uint32_t nbmes3 = nbmes2 * nbmesz;

    uint32_t size2 = srec->x * srec->y;

    for (uint32_t mu = 0; mu < nbmes3; mu += shift) {
        VFUNC(store_ps) (vmu + mu, zero);
        VFUNC(store_ps) (omegamu + mu, zero);
    }

    for (uint32_t k = 0; k < nbact; ++k) {
        uint32_t i = activepix[k];
        float * cabeal = abeal + k * kersize3;
        float * cvbeal = vbeal + k * kersize3;

        uint32_t ci = ((i % size2) % srec->x) % pixsdiv;
        uint32_t li = ((i % size2) / srec->x) % pixsdiv;
        uint32_t zi = (i / size2) % pixsdivz;
        uint32_t ikeri = ci + li * pixsdiv + zi * pixsdiv2;

        uint32_t cmu0 = ((i % size2) % srec->x) / pixsdiv + kersize / 2;
        uint32_t lmu0 = ((i % size2) / srec->x) / pixsdiv + kersize / 2;
        uint32_t zmu0 = (i / size2) / pixsdivz + kersizez / 2;

        float * cker = ker + ikeri * kersize3;
        float * cker2 = ker2 + ikeri * kersize3;

        for (uint32_t mu = 0; mu < kersize3; mu += shift) {
            uint32_t cmu = cmu0 + (mu % kersize2) % kersize;
            cmu -= kersize / 2;
            uint32_t lmu = lmu0 + (mu % kersize2) / kersize;
            lmu -= kersize / 2;
            uint32_t zmu = zmu0 + (mu / kersize2);
            zmu -= kersizez / 2;
            uint32_t imu = cmu + lmu * nbmesx + zmu * nbmes2;

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
#ifdef BRECS_DISPLAYPLOTS
    writetiff_f("omegavmu.tif", nbmesx, nbmesy, nbmesz, omegamu);
#endif
}

static void update_Palbe(afloat * mu_albe_A, afloat * mu_albe_B,
                         afloat * abeal, afloat * vbeal,
                         float * sum_mualbe_A, float * sum_mualbe_B,
                         afloat * omegamu, afloat * vmu,
                         afloat * ker, afloat * ker2,
                         afloat * imgnoise, afloat * imgmes,
                         uint32_t nbact, uint32_t * activepix,
                         veci3 * srec, params_t * par)
{
    uint32_t pixsdiv = par->pixsdiv;
    uint32_t pixsdivz = par->pixsdivz;
    uint32_t pixsdiv2 = pixsdiv * pixsdiv;
    uint32_t kersize = par->kersize;
    uint32_t kersize2 = kersize * kersize;
    uint32_t kersizez = par->kersizez;
    uint32_t kersize3 = kersize2 * kersizez;

    const vecfloat zero = VFUNC(set1_ps) (0.0f);
    const vecfloat one = VFUNC(set1_ps) (1.0f);
    const vecfloat oneosk = VFUNC(set1_ps) (1.0f / kersize3);
    const vecfloat lowv = VFUNC(set1_ps) (1e8f);

    uint32_t nbmesx = srec->x / pixsdiv + kersize;
    uint32_t nbmesy = srec->y / pixsdiv + kersize;
    uint32_t nbmes2 = nbmesx * nbmesy;

    uint32_t size2 = srec->x * srec->y;

    update_omegavmu(omegamu, vmu, ker, ker2, abeal, vbeal, nbact, activepix,
                    srec, par);

    for (uint32_t k = 0; k < nbact; ++k) {
        uint32_t i = activepix[k];
        float * caA = mu_albe_A + k * kersize3;
        float * caB = mu_albe_B + k * kersize3;
        float * cabeal = abeal + k * kersize3;
        float * cvbeal = vbeal + k * kersize3;

        uint32_t ci = ((i % size2) % srec->x) % pixsdiv;
        uint32_t li = ((i % size2) / srec->x) % pixsdiv;
        uint32_t zi = (i / size2) % pixsdivz;
        uint32_t ikeri = ci + li * pixsdiv + zi * pixsdiv2;

        uint32_t cmu0 = ((i % size2) % srec->x) / pixsdiv + kersize / 2;
        uint32_t lmu0 = ((i % size2) / srec->x) / pixsdiv + kersize / 2;
        uint32_t zmu0 = (i / size2) / pixsdivz + kersizez / 2;

        float * cker = ker + ikeri * kersize3;
        float * cker2 = ker2 + ikeri * kersize3;

        vecfloat sumvmualA = VFUNC(load_ps) (sum_mualbe_A + k * shift);
        vecfloat sumvmualB = VFUNC(load_ps) (sum_mualbe_B + k * shift);

        vecfloat sumA = zero;
        vecfloat sumB = zero;

        for (uint32_t mu = 0; mu < kersize3; mu += shift) {
            uint32_t cmu = cmu0 + (mu % kersize2) % kersize;
            cmu -= kersize / 2;
            uint32_t lmu = lmu0 + (mu % kersize2) / kersize;
            lmu -= kersize / 2;
            uint32_t zmu = zmu0 + (mu / kersize2);
            zmu -= kersizez / 2;
            uint32_t imu = cmu + lmu * nbmesx + zmu * nbmes2;

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

static void update_mualbe(float * mu_albe_A, float * mu_albe_B,
                          float * sum_mualbe_A, float * sum_mualbe_B,
                          float * abeal, float * vbeal,
                          float * omegamu, float * vmu,
                          float * ker, float * ker2,
                          float * imgnoise, float * imgmes,
                          uint32_t nbact, uint32_t * activepix,
                          veci3 * srec, params_t * par)
{
    uint32_t kersize = par->kersize;
    uint32_t kersize2 = kersize * kersize;
    uint32_t kersizez = par->kersizez;
    uint32_t kersize3 = kersize2 * kersizez;

    update_Palbe(mu_albe_A, mu_albe_B,
                 abeal, vbeal,
                 sum_mualbe_A, sum_mualbe_B,
                 omegamu, vmu,
                 ker, ker2,
                 imgnoise, imgmes,
                 nbact, activepix,
                 srec, par);

    const vecfloat zero = VFUNC(set1_ps) (0);
    const vecfloat oneosk = VFUNC(set1_ps) (1.0f / kersize3);
    for (uint32_t k = 0; k < nbact; ++k) {
        float * caA = mu_albe_A + k * kersize3;
        float * caB = mu_albe_B + k * kersize3;
        float * cPA = vbeal + k * kersize3;
        float * cPB = abeal + k * kersize3;

        vecfloat PAt = VFUNC(load_ps) (sum_mualbe_A + k * shift);
        vecfloat PBt = VFUNC(load_ps) (sum_mualbe_B + k * shift);

        vecfloat sumA = zero;
        vecfloat sumB = zero;
        for (uint32_t mu = 0; mu < kersize3; mu += shift) {
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

static void update_mubeal(float * vbeal, float * abeal,
                          float * mu_albe_A, float * mu_albe_B,
                          float * P_be_E, float * P_be_F,
                          float * sum_mualbe_A, float * sum_mualbe_B,
                          uint32_t nbact, params_t * par)
{
    uint32_t kersize = par->kersize;
    uint32_t kersize2 = kersize * kersize;
    uint32_t kersizez = par->kersizez;
    uint32_t kersize3 = kersize2 * kersizez;

    const float rat = ((float)kersize3 - 1) / kersize3;
    const vecfloat one = VFUNC(set1_ps) (1.0);
    const vecfloat thrmin = VFUNC(set1_ps) (1e10f);
    const vecfloat thrmax = VFUNC(set1_ps) (1e-5f);

    for (uint32_t k = 0; k < nbact; ++k) {
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
        for (uint32_t mu = 0; mu < kersize3; mu += shift) {
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

static float update_pbe(float * P_be_E, float * P_be_F,
                        float * P_albe_A, float * P_albe_B,
                        uint32_t nbact, params_t * par)
{
    uint32_t kersize = par->kersize;
    uint32_t kersize2 = kersize * kersize;
    uint32_t kersizez = par->kersizez;
    uint32_t kersize3 = kersize2 * kersizez;
    float damp1 = par->damp1;
    float damp2 = par->damp2;

    /* The coefficient should be equal after convergence, we choose to take
     * the average of the coefficients here...
     * This is the logarithmic average instead of the normal average, this
     * should not make a difference at convergence.
     */
    float relerr = 0.0;
    uint8_t nberr = 0;
    float errmeantot = 0;
    float errvartot = 0;
    for (uint32_t k = 0; k < nbact; ++k) {
        float * cA = P_albe_A + k * kersize3;
        float * cB = P_albe_B + k * kersize3;

        vecfloat vPEt = VFUNC(set1_ps) (0);
        vecfloat vPFt = VFUNC(set1_ps) (0);
        for (uint32_t mu = 0; mu < kersize3; mu += shift) {
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

        if (P_be_E[k] < 1e-7f) P_be_E[k] = 1e-7f;
        float prevPbE = P_be_E[k];
        float prevPbF = P_be_F[k];

        if (PFt > 1e12f) PFt = 1e12f;
        float fafc[2];
        fafcfunc(fafc, 1 / PEt, PFt / PEt, par);

        float invE = (1 - damp1) / P_be_E[k] + damp1 * fafc[1];
        P_be_E[k]= 1 / invE;
        P_be_F[k] = (1 - damp2) * P_be_F[k] / invE / prevPbE
            + damp2 * fafc[0] / invE;

        float errvar = fabsf(fafc[1] - 1 / prevPbE) / (fafc[1] + 1 / prevPbE);
        float errmean = fabsf(fafc[0] - prevPbF / prevPbE)
                        / (fafc[0] + prevPbF / prevPbE);
        if (errvar > relerr) {
            relerr = errvar;
        }
        if (errmean > relerr) {
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
    }
    return relerr;
}

uint8_t on_border(uint32_t i, uint32_t* activepix, uint32_t nbact,
              uint32_t sizex, uint32_t size2)
{
    uint32_t p1 = i - sizex;
    uint32_t p2 = i - 1;
    uint32_t p3 = i + 1;
    uint32_t p4 = i + sizex;
    uint32_t p5 = i - size2;
    uint32_t p6 = i + size2;

    uint32_t count = 0;
    for (uint32_t k = 0; k < nbact; ++k) {
        uint32_t j = activepix[k];
        if (j == p1 || j == p2 || j == p3 || j == p4 || j == p5 || j == p6) {
            count += 1;
            if (count == 6) return 0;
        }
    }
    return 1;
}

uint32_t nbconv;

float * gausskerpar(uint32_t sx, uint32_t sy, uint32_t sz,
                    float radius, float radiusz)
{
    float * out;
    int errnopos = brecs_memalign((void **)&out,
                                  sx * sy * sz * sizeof(float));
    if (!out) brecs_error("Failed to allocate memory for gaussker: ",
                          strerror(errnopos), prog_name);

    float sig2 = radius * radius;
    float sig2z = radiusz * radiusz;
    for (int32_t z = -(int32_t)sz / 2; z < (int32_t)sz / 2 ; ++z) {
        float dz2 = z * z;
        for (int32_t y = -(int32_t)sy / 2; y < (int32_t)sy / 2 ; ++y) {
            float dy2 = y * y;
            for (int32_t x = -(int32_t)sx / 2; x < (int32_t)sx / 2; ++x) {
                float dx2 = x * x;
                float r2 = dx2 + dy2;
                float val = expf(-0.5f * r2 / sig2 - 0.5f * dz2 / sig2z)
                            / (2.0f * M_PIf * sig2) / sqrtf(2.0f * M_PIf * sig2z);
                uint32_t col = (x < 0) ? (uint32_t)(x + (int32_t)sx) : (uint32_t)x;
                uint32_t line = (y < 0) ? (uint32_t)(y + (int32_t)sy) : (uint32_t)y;
                uint32_t dep = (z < 0) ? (uint32_t)(z + (int32_t)sz) : (uint32_t)z;

                out[col + line * sx + dep * sx * sy] = val;
            }
        }
    }
    return out;
}

float * gausskerpar2d(uint32_t sx, uint32_t sy, float radius)
{
    float * out;
    int errnopos = brecs_memalign((void **)&out, sx * sy * sizeof(float));
    if (!out) brecs_error("Failed to allocate memory for gaussker: ",
                          strerror(errnopos), prog_name);

    float sig2 = radius * radius;
    for (int32_t y = -(int32_t)sy / 2; y < (int32_t)sy / 2 ; ++y) {
        float dy2 = y * y;
        for (int32_t x = -(int32_t)sx / 2; x < (int32_t)sx / 2; ++x) {
            float dx2 = x * x;
            float r2 = dx2 + dy2;
            float val = expf(-0.5f * r2 / sig2) / (2.0f * M_PIf * sig2);
            uint32_t col = (x < 0) ? (uint32_t)(x + (int32_t)sx) : (uint32_t)x;
            uint32_t line = (y < 0) ? (uint32_t)(y + (int32_t)sy) : (uint32_t)y;

            out[col + line * sx] = val;
        }
    }
    return out;
}

float * recons_ccomp(float * imgmes, float * imgnoise, uint32_t nbmes3,
                     uint32_t * activepix, uint32_t nbact,
                     float * ker, float * ker2, veci3 * srec, params_t * par)
{
    uint32_t kersize = par->kersize;
    uint32_t kersize2 = kersize * kersize;
    uint32_t kersizez = par->kersizez;
    uint32_t kersize3 = kersize2 * kersizez;
    float rho = par->rho;
    float pixmean = par->pixmean;
    float Ainit = par->Ainit;
    float relerrthr = par->relerrthr;
    uint32_t nbiter = par->nbiter;
    uint32_t nbinternloop = par->nbinternloop;

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

    float * res;

    int errnopos = brecs_memalign((void **)&imgnoisecp, nbmes3 * sizeof(float));
    if (!imgnoisecp) brecs_error("Failed to allocate memory for imgnoisecp: ",
                                 strerror(errnopos), prog_name);

    for (uint32_t i = 0; i < nbmes3; ++i) {
        imgnoisecp[i] = imgnoise[i];
    }

    /* Memory allocation */
    static const size_t sifl = sizeof(float);
    errnopos = brecs_memalign((void **)&mu_albe_A, nbact * kersize3 * sifl);
    if (!mu_albe_A) brecs_error("Failed to allocate memory for mu_albe_A: ",
                                strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&mu_albe_B, nbact * kersize3 * sifl);
    if (!mu_albe_B) brecs_error("Failed to allocate memory for mu_albe_B: ",
                                strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&mu_beal_A, nbact * kersize3 * sifl);
    if (!mu_beal_A) brecs_error("Failed to allocate memory for mu_beal_A: ",
                                strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&mu_beal_B, nbact * kersize3 * sifl);
    if (!mu_beal_B) brecs_error("Failed to allocate memory for mu_beal_B: ",
                                strerror(errnopos), prog_name);
    vbeal = mu_beal_A;
    abeal = mu_beal_B;

    errnopos = brecs_memalign((void **)&P_be_E, nbact * sifl);
    if (!P_be_E) brecs_error("Failed to allocate memory for P_be_E: ",
                             strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&P_be_F, nbact * sifl);
    if (!P_be_F) brecs_error("Failed to allocate memory for P_be_F: ",
                             strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&sum_mualbe_A, nbact * shift * sifl);
    if (!sum_mualbe_A)
        brecs_error("Failed to allocate memory for sum_mualbe_A: ",
                    strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&sum_mualbe_B, nbact * shift * sifl);
    if (!sum_mualbe_B)
        brecs_error("Failed to allocate memory for sum_mualbe_B: ",
                    strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&omegamu, nbmes3 * sifl);
    if (!omegamu) brecs_error("Failed to allocate memory for omegamu ",
                              strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&vmu, nbmes3 * sifl);
    if (!vmu) brecs_error("Failed to allocate memory for vmu ",
                          strerror(errnopos), prog_name);

    float Binit = rho * pixmean * Ainit;

    for (uint32_t i = 0; i < nbact * kersize3; ++i) {
        mu_albe_A[i] = Ainit;
        mu_albe_B[i] = Binit;
        vbeal[i] = Ainit;
        abeal[i] = Binit;
    }
    vecfloat vAinit = VFUNC(set1_ps) (Ainit);
    vecfloat vBinit = VFUNC(set1_ps) (Binit);

    for (uint32_t i = 0; i < nbact; ++i) {
        P_be_E[i] = Ainit;
        P_be_F[i] = Binit;

        VFUNC(store_ps) (sum_mualbe_A + i * shift, vAinit);
        VFUNC(store_ps) (sum_mualbe_B + i * shift, vBinit);
    }

    /* Main loop */
    float relerr = 1.0;
    uint32_t iter = 0;
    while (relerr > relerrthr && iter < nbiter) {
        iter++;
        /* Internal loop */
        for (uint32_t j = 0; j < nbinternloop; ++j) {
            update_mubeal(vbeal, abeal,
                    mu_albe_A, mu_albe_B,
                    P_be_E, P_be_F,
                    sum_mualbe_A, sum_mualbe_B,
                    nbact, par);

            update_mualbe(mu_albe_A, mu_albe_B,
                    sum_mualbe_A, sum_mualbe_B,
                    abeal, vbeal,
                    omegamu, vmu,
                    ker, ker2,
                    imgnoisecp, imgmes,
                    nbact, activepix,
                    srec, par);
        }

        relerr = update_pbe(P_be_E, P_be_F,
                            vbeal, abeal,
                            nbact,
                            par);
        if (iter < 200) relerr = 1.0;
    }

    if (relerr < 1.01 * relerrthr) nbconv++;

    errnopos = brecs_memalign((void **)&res, nbact * sizeof(float));
    if (!res) brecs_error("Failed to allocate memory for res ",
                          strerror(errnopos), prog_name);

    // if (relerr < 1.1 * relerrthr){
        for (uint32_t k = 0; k < nbact; ++k) {
            float val = P_be_F[k] / P_be_E[k];
            res[k] = val;
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

uint8_t * create_overlay(float * imgmes, float * imgrecons,
                         veci3 * srec, veci3 * smes, params_t * par)
{
    float overlaymaxint = par->overlaymaxint;
    float overlayminint = par->overlayminint;
    uint32_t pixsdiv = par->pixsdiv;
    uint32_t pixsdivz = par->pixsdivz;
    uint32_t kersize = par->kersize;
    uint32_t kersizez = par->kersizez;

    uint32_t size2 = srec->x * srec->y;
    uint32_t size3 = srec->x * srec->y * srec->z;

    uint32_t nbmes2 = smes->x * smes->y;
    uint32_t nbmes3 = nbmes2 * smes->z;

    uint8_t * img_data = brecs_alloc(4 * size3 * sizeof(uint8_t));
    float maxrc = 0;
    for (uint32_t i = 0 ; i < size3 ; i++) {
        if (maxrc < imgrecons[i]) maxrc = imgrecons[i];
    }

    float max2 = 0;
    float min2 = 0;
    for (uint32_t i = 0 ; i < nbmes3 ; i++) {
        if (max2 < imgmes[i]) max2 = imgmes[i];
        if (min2 > imgmes[i]) min2 = imgmes[i];
    }

    for (uint32_t i = 0; i < size3; ++i) {
        float val = imgrecons[i];
        uint8_t * cimgd = img_data + i * 4;
        if (val > overlayminint) {
            if (val > overlaymaxint) val = overlaymaxint;
            cimgd[0] = (uint8_t)(255.0f * (logf(val) - logf(overlayminint))
                       / (logf(overlaymaxint) - logf(overlayminint)));
            cimgd[1] = 0;
            cimgd[2] = 0;
            cimgd[3] = 255;
        } else {
            uint32_t x = i % srec->x;
            uint32_t y = (i % size2) / srec->x;
            uint32_t z = i / size2;
            if (x >= pixsdiv / 2 && y >= pixsdiv / 2 && z >= pixsdivz / 2) {
                x -= pixsdiv / 2;
                y -= pixsdiv / 2;
                z -= pixsdivz / 2;
                uint32_t ind = (y / pixsdiv + kersize / 2) * smes->x
                    + x / pixsdiv + kersize / 2
                    + (z / pixsdivz + kersizez / 2) * nbmes2;
                uint8_t valp = (uint8_t)(255
                               / (max2 - min2) * (imgmes[ind] - min2));
                cimgd[0] = valp;
                cimgd[1] = valp;
                cimgd[2] = valp;
                cimgd[3] = 255;
            }
        }
    }
    return img_data;
}

#ifdef BRECS_DISPLAYPLOTS
/* void plot_overlay(imgmes, reconspic, */
/*                   sizex, sizey, sizez, nbmesx, nbmesy, nbmesz, */
/*                   "overlay.tif") */
/* { */
/*     uint8_t = create_overlay */
/* } */
#endif

float * reconssparse(float* imgmes,float* imgnoise, veci3* smes,
                     images_t* images, params_t* par)
{
    uint32_t pixsdiv = par->pixsdiv;
    uint32_t pixsdivz = par->pixsdivz;
    uint32_t pixsdiv2 = pixsdiv * pixsdiv;
    uint32_t pixsdiv3 = pixsdivz * pixsdiv2;
    uint32_t kersize = par->kersize;
    uint32_t kersize2 = kersize * kersize;
    uint32_t kersizez = par->kersizez;
    uint32_t kersize3 = kersize2 * kersizez;

    uint32_t nbmesx = smes->x;
    uint32_t nbmesy = smes->y;
    uint32_t nbmesz = smes->z;

    ccomp_dec ccdec;
    if (nbmesz == 1) {
        ccdec = connectcomp_decomp2d(imgmes, smes, par);
    } else {
        ccdec = connectcomp_decomp3d(imgmes, smes, par);
    }

    float * ker = images->ker;
    float * ker2;
    int errnopos = brecs_memalign((void **)&ker2,
                   pixsdiv3 * kersize3 * sizeof(float));
    if (!ker2) brecs_error("Failed to allocate memory for ker2 ",
                           strerror(errnopos), prog_name);

    /* Initialize kernels */
    printf("Initializing kernel\n");

    for (uint32_t i = 0; i < pixsdiv3 * kersize3; ++i) {
        ker2[i] = ker[i] * ker[i];
    }

    nbconv = 0;

    uint32_t sizex = pixsdiv * (nbmesx - kersize);
    uint32_t sizey = pixsdiv * (nbmesy - kersize);
    uint32_t sizez = pixsdivz * (nbmesz - kersizez + kersizez % 2);
    uint32_t size3 = sizex * sizey * sizez;

    float * reconspic = brecs_alloc(size3 * sizeof(float));
    for (uint32_t i = 0; i < size3; ++i) {
        reconspic[i] = 0;
    }

    veci3 srec;
    srec.x = sizex;
    srec.y = sizey;
    srec.z = sizez;

    /* uint32_t nbfluo = 1; */
    for (uint32_t i = 0; i < ccdec.nbcomp; ++i) {
        printf("Processing connected component %40d / %d\r",
               i + 1, ccdec.nbcomp);
        fflush(stdout);
        float * rectmp = recons_ccomp(imgmes, imgnoise, nbmesx * nbmesy * nbmesz,
                                      ccdec.activepixcomp[i], ccdec.nbact[i],
                                      ker, ker2, &srec, par);
        for (uint32_t j = 0; j < ccdec.nbact[i]; ++j) {
            reconspic[ccdec.activepixcomp[i][j]] += rectmp[j];
        }
        /* for (uint32_t j = 0; j < size3; ++j) { */
        /*     uint32_t c = (j % size2) % srec->x; */
        /*     uint32_t l = (j % size2) / srec->x; */
        /*     uint32_t z = j / size2; */
        /*     if (res[j] > locaintensthr */
        /*         && !on_border(j, activepix, nbact, srec->x, size2)) { */
        /*         printf("%d %.2f %.2f %.2f %.2f\n", */
        /*                nbfluo, */
        /*                (c - kersize / 2 * pixsdiv) * spixnm + spixnm / 2, */
        /*                (l - kersize / 2 * pixsdiv) * spixnm + spixnm / 2, */
        /*                z * spixznm, */
        /*                res[i]); */
        /*         nbfluo++; */
        /*     } */
        /* } */
        brecs_free(rectmp);
    }
    printf("\n");
    for (uint32_t i = 0; i < ccdec.nbcomp; ++i) {
        brecs_free(ccdec.activepixcomp[i]);
    }
    brecs_free(ccdec.nbact);
    brecs_free(ccdec.coordcomp);
    brecs_free(ccdec.activepixcomp);
    brecs_free(ccdec.imglab);

    uint8_t * overlay = create_overlay(imgmes, reconspic, &srec, smes, par);

#ifdef BRECS_DISPLAYPLOTS
    writetiff_rgb("overlay.tif", sizex, sizey, sizez, overlay);
#endif

    images->reconspic = reconspic;
    images->overlay = overlay;
    images->outsize = srec;

    printf("Converged: %d / %d\n", nbconv, ccdec.nbcomp);

    return reconspic;
}

/* Decompose an image into connected components */
lab_t * roundker(uint32_t diam, uint32_t diamz)
{
    int32_t center = diam / 2;
    int32_t center2 = center * center;
    int32_t centerz = diamz / 2;
    int32_t centerz2 = centerz * centerz;
    lab_t * ker = brecs_alloc(diam * diam * diamz * sizeof(lab_t));
    for (int32_t k = 0; k < (int32_t)diamz; k++) {
        for (int32_t j = 0; j < (int32_t)diam; j++) {
            for (int32_t i = 0; i < (int32_t)diam; i++) {
                int32_t x = i - center;
                int32_t y = j - center;
                int32_t z = k - centerz;
                float rad2 = x * x + y * y;
                float rad2z = z * z;
                uint32_t ind = (uint32_t)(i + j * (int32_t)diam
                                          + k * (int32_t)diam * (int32_t)diam);
                if (rad2 / center2 + rad2z / centerz2 < 1.0f) {
                    ker[ind] = 1;
                } else {
                    ker[ind] = 0;
                }
            }
        }
    }
    return ker;
}

lab_t * roundker2d(uint32_t diam)
{
    int32_t center = diam / 2;
    lab_t * ker = brecs_alloc(diam * diam * sizeof(lab_t));
    for (int32_t j = 0; j < (int32_t)diam; j++) {
        for (int32_t i = 0; i < (int32_t)diam; i++) {
            int32_t x = i - center;
            int32_t y = j - center;
            float rad2 = x * x + y * y;
            uint32_t ind = (uint32_t)(i + j * (int32_t)diam);
            if (rad2 < center * center) {
                ker[ind] = 1;
            } else {
                ker[ind] = 0;
            }
        }
    }
    return ker;
}

void maskpix(lab_t * img, uint32_t width, uint32_t height, lab_t * ker,
             uint32_t diam, uint32_t diamz, uint32_t x, uint32_t y, uint32_t z)
{
    for (int32_t k = 0; k < (int32_t)diamz; k++) {
        for (int32_t j = 0; j < (int32_t)diam; j++) {
            for (int32_t i = 0; i < (int32_t)diam; i++) {
                uint32_t ind = (uint32_t)((int32_t)x + i - (int32_t)diam / 2
                          + ((int32_t)y + j - (int32_t)diam / 2) * (int32_t)width
                          + ((int32_t)z + k - (int32_t)diamz / 2) * (int32_t)width * (int32_t)height);
                img[ind] = img[ind] || ker[i + j * (int32_t)diam + k * (int32_t)diam * (int32_t)diam];
            }
        }
    }
}

void maskpix2d(lab_t * img, uint32_t width, lab_t * ker,
        uint32_t diam, uint32_t x, uint32_t y)
{
    for (int32_t j = 0; j < (int32_t)diam; j++) {
        for (int32_t i = 0; i < (int32_t)diam; i++) {
            uint32_t ind = (uint32_t)((int32_t)x + i - (int32_t)diam / 2 + ((int32_t)y + j - (int32_t)diam / 2) * (int32_t)width);
            img[ind] = img[ind] || ker[i + j * (int32_t)diam];
        }
    }
}

lab_t neighb(lab_t * img, uint32_t width, uint32_t height,
             uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t plane = width * height;
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

lab_t neighb2d(lab_t * img, uint32_t width, uint32_t x, uint32_t y)
{
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

lab_t * dilate(lab_t * img, uint32_t width, uint32_t height, uint32_t depth,
               lab_t * ker, uint32_t diam, uint32_t diamz)
{
    lab_t * res = brecs_alloc(width * height * depth * sizeof(lab_t));
    for (uint32_t i = 0; i < width * height * depth; ++i) {
        res[i] = img[i];
    }
    for (uint32_t k = 0; k < depth; k++) {
        for (uint32_t j = 0; j < height; j++) {
            for (uint32_t i = 0; i < width; i++) {
                if (img[i + j * width + k * width * height]
                        && neighb(img, width, height, i, j, k)) {
                    maskpix(res, width, height, ker, diam, diamz, i, j, k);
                }
            }
        }
    }
    return res;
}

lab_t * dilate2d(lab_t * img, uint32_t width, uint32_t height,
                 lab_t * ker, uint32_t diam)
{
    lab_t * res = brecs_alloc(width * height * sizeof(lab_t));
    for (uint32_t i = 0; i < width * height; ++i) {
        res[i] = img[i];
    }
    for (uint32_t j = 0; j < height; j++) {
        for (uint32_t i = 0; i < width; i++) {
            if (img[i + j * width]
                    && neighb2d(img, width, i, j)) {
                maskpix2d(res, width, ker, diam, i, j);
            }
        }
    }
    return res;
}

void unionsets(lab_t * labs, uint16_t lastlab, uint16_t parentlab, uint16_t lab)
{
    if (lab != parentlab) {
        for (int i = lab - 1; i < lastlab; ++i) {
            if (labs[i] == lab) {
                labs[i] = parentlab;
            }
        }
    }
}

uint8_t * genrandomcolo(lab_t nbcol)
{
    uint8_t * cols = brecs_alloc(3 * nbcol * sizeof(uint8_t));
    uint8_t mix[3] = {240, 240, 240};
    for (uint32_t i = 0; i < nbcol; ++i) {
        uint8_t red   = (uint8_t)(drand48() * 256);
        uint8_t green = (uint8_t)(drand48() * 256);
        uint8_t blue  = (uint8_t)(drand48() * 256);

        cols[i * 3] = (red + mix[0]) / 2;
        cols[1 + i * 3] = (green + mix[1]) / 2;
        cols[2 + i * 3] = (blue + mix[2]) / 2;
    }

    return cols;
}

ccomp_dec aggregate(lab_t * img, lab_t * imgdil, veci3 * size, params_t * par)
{
    uint16_t pixsdiv = par->pixsdiv;
    uint16_t pixsdivz = par->pixsdivz;
    uint16_t kersize = par->kersize;
    uint16_t kersizez = par->kersizez;

    uint32_t width = size->x;
    uint32_t height = size->y;
    uint32_t depth = size->z;

    ccomp_dec ccdec;
    lab_t labs[UINT16_MAX];

    lab_t * imglabs = brecs_alloc(width * height * depth * sizeof(lab_t));

    for (uint32_t i = 0; i < width * height * depth; i++) {
        imglabs[i] = 0;
    }

    uint32_t plane = width * height;

    lab_t lastlab = 0;
    for (uint32_t k = 1; k < depth - 1; k++) {
        for (uint32_t j = 1; j < height - 1; j++) {
            for (uint32_t i = 1; i < width - 1; i++) {
                uint32_t ind = i + j * width + k * width * height;
                if (imgdil[ind]) {
                    lab_t lab4[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    lab_t lab4p[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    uint32_t nlab = 0;
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
                    lab_t minlab = UINT16_MAX;
                    if (lab4[0]) {
                        minlab = lab4[0];
                        lab4p[0] = minlab;
                        nlab++;
                    }
                    for (uint32_t l = 1; l < 13; ++l) {
                        if (lab4[l]) {
                            if (lab4[l] < minlab) minlab = lab4[l];
                            lab4p[nlab] = lab4[l];
                            nlab++;
                        }
                    }

                    if (nlab > 2) {
                        for (uint32_t l = 0; l < nlab; ++l) {
                            unionsets(labs, lastlab, minlab, lab4p[l]);
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
    uint16_t clab = 0;
    uint16_t clab2 = 0;
    for (uint32_t i = 0; i < lastlab; ++i) {
        if (labs[i] > clab2) {
            clab2 = labs[i];
            clab++;
            labs[i] = clab;
        } else {
            labs[i] = labs[labs[i] - 1];
        }
    }
    ccdec.nbcomp = clab;
    ccdec.coordcomp = brecs_alloc(clab * 4 * sizeof(uint32_t));
    ccdec.nbact = brecs_alloc(clab * sizeof(uint32_t));
    ccdec.activepixcomp = brecs_alloc(clab * sizeof(uint32_t *));
    for (uint32_t i = 0; i < clab; ++i) {
        ccdec.coordcomp[4 * i] = width;
        ccdec.coordcomp[4 * i + 1] = 0;
        ccdec.coordcomp[4 * i + 2] = height;
        ccdec.coordcomp[4 * i + 3] = 0;
        ccdec.nbact[i] = 0;
    }
    for (uint32_t k = 0; k < depth; k++) {
        for (uint32_t j = 0; j < height; j++) {
            for (uint32_t i = 0; i < width; i++) {
                uint32_t ind = i + j * width + k * width * height;

                if (img[ind]) {
                    lab_t lab = labs[imglabs[ind] - 1];
                    uint32_t* coord = ccdec.coordcomp + 4 * (lab - 1);
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
    for (uint32_t i = 0; i < clab; ++i) {
        ccdec.activepixcomp[i] = brecs_alloc(ccdec.nbact[i] * sizeof(uint32_t));
        ccdec.nbact[i] = 0;
    }
    int32_t offset = pixsdiv * kersize / 2;
    int32_t offsetz = pixsdivz * (kersizez / 2);
    int32_t widthdef = (int32_t)(width - pixsdiv * kersize);
    int32_t heightdef = (int32_t)(height - pixsdiv * kersize);
    for (int32_t k = 0; k < (int32_t)depth; k++) {
        for (int32_t j = 0; j < (int32_t)height; j++) {
            for (int32_t i = 0; i < (int32_t)width; i++) {
                uint32_t ind = (uint32_t)(i + j *(int32_t) width + k * (int32_t)(width * height));
                if (img[ind]) {
                    lab_t lab = imglabs[ind];
                    int32_t ind2 = i - offset + (j - offset) * widthdef
                        + (k - offsetz) * widthdef * heightdef;
                    uint32_t act = ccdec.nbact[lab - 1];
                    if (ind2 >= 0) {
                        ccdec.activepixcomp[lab - 1][act] = (uint32_t)ind2;
                        ccdec.nbact[lab - 1] += 1;
                    }
                }
            }
        }
    }

#ifdef BRECS_DISPLAYPLOTS
    uint8_t * cols = genrandomcolo(clab);
    uint8_t * imgccmprgb = brecs_alloc(plane * depth * 4 * sizeof(uint8_t));

    for (uint32_t i = 0; i < plane * depth; ++i) {
        if (img[i]) {
            imgccmprgb[4 * i] = cols[3 * imglabs[i] - 3];
            imgccmprgb[1 + 4 * i] = cols[1 + 3 * imglabs[i] - 3];
            imgccmprgb[2 + 4 * i] = cols[2 + 3 * imglabs[i] - 3];
            imgccmprgb[3 + 4 * i] = 255;
        } else {
            imgccmprgb[4 * i] = 0;
            imgccmprgb[1 + 4 * i] = 0;
            imgccmprgb[2 + 4 * i] = 0;
            imgccmprgb[3 + 4 * i] = 255;
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
                      uint32_t width, uint32_t height, params_t * par)
{
    uint32_t pixsdiv = par->pixsdiv;
    uint32_t pixsdivz = par->pixsdivz;
    uint32_t kersize = par->kersize;

    ccomp_dec ccdec;
    lab_t labs[UINT16_MAX];

    lab_t * imglabs = brecs_alloc(width * height * sizeof(lab_t));

    for (uint32_t i = 0; i < width * height; i++) {
        imglabs[i] = 0;
    }

    uint32_t plane = width * height * pixsdivz;

    lab_t lastlab = 0;
    for (uint32_t j = 1; j < height - 1; j++) {
        for (uint32_t i = 1; i < width - 1; i++) {
            uint32_t ind = i + j * width;
            if (imgdil[ind]) {
                lab_t lab4[4] = {0, 0, 0, 0};
                lab_t lab4p[4] = {0, 0, 0, 0};
                uint32_t nlab = 0;
                lab4[0] = imglabs[ind - width - 1];
                lab4[1] = imglabs[ind - width];
                lab4[2] = imglabs[ind - width + 1];
                lab4[3] = imglabs[ind - 1];
                lab_t minlab = UINT16_MAX;
                if (lab4[0]) {
                    minlab = lab4[0];
                    lab4p[0] = minlab;
                    nlab++;
                }
                for (uint32_t k = 1; k < 4; ++k) {
                    if (lab4[k]) {
                        if (lab4[k] < minlab) minlab = lab4[k];
                        lab4p[nlab] = lab4[k];
                        nlab++;
                    }
                }

                if (nlab > 2) {
                    for (uint32_t k = 0; k < nlab; ++k) {
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
    uint16_t clab = 0;
    uint16_t clab2 = 0;
    for (uint32_t i = 0; i < lastlab; ++i) {
        if (labs[i] > clab2) {
            clab2 = labs[i];
            clab++;
            labs[i] = clab;
        } else {
            labs[i] = labs[labs[i] - 1];
        }
    }
    ccdec.nbcomp = clab;
    ccdec.coordcomp = brecs_alloc(clab * 4 * sizeof(uint32_t));
    ccdec.nbact = brecs_alloc(clab * pixsdivz * sizeof(uint32_t));
    ccdec.activepixcomp = brecs_alloc(clab * sizeof(uint32_t *));
    for (uint32_t i = 0; i < clab; ++i) {
        ccdec.coordcomp[4 * i] = width;
        ccdec.coordcomp[4 * i + 1] = 0;
        ccdec.coordcomp[4 * i + 2] = height;
        ccdec.coordcomp[4 * i + 3] = 0;
        ccdec.nbact[i] = 0;
    }
    for (uint32_t j = 0; j < height; j++) {
        for (uint32_t i = 0; i < width; i++) {
            uint32_t ind = i + j * width;

            if (img[ind]) {
                lab_t lab = labs[imglabs[ind] - 1];
                uint32_t* coord = ccdec.coordcomp + 4 * (lab - 1);
                if (j < coord[0]) coord[0] = j;
                if (j > coord[1]) coord[1] = j;
                if (i < coord[2]) coord[2] = i;
                if (i > coord[3]) coord[3] = i;
                imglabs[ind] = lab;
                ccdec.nbact[lab - 1] += pixsdivz;
            }
        }
    }
    for (uint32_t i = 0; i < clab; ++i) {
        ccdec.activepixcomp[i] = brecs_alloc(ccdec.nbact[i] * sizeof(uint32_t));
        ccdec.nbact[i] = 0;
    }
    int32_t offset = pixsdiv * kersize / 2;
    int32_t widthdef = (int32_t)(width - pixsdiv * kersize);
    int32_t heightdef = (int32_t)(height - pixsdiv * kersize);
    for (int32_t k = 0; k < (int32_t)pixsdivz; ++k) {
        for (int32_t j = 0; j < (int32_t)height; j++) {
            for (int32_t i = 0; i < (int32_t)width; i++) {
                int32_t ind = i + j * (int32_t)width;
                if (img[ind]) {
                    lab_t lab = imglabs[ind];
                    int32_t ind2 = i - offset + (j - offset) * widthdef
                        + k * widthdef * heightdef;
                    uint32_t act = ccdec.nbact[lab - 1];
                    if (ind2 >= 0) {
                        ccdec.activepixcomp[lab - 1][act] = (uint32_t)ind2;
                        ccdec.nbact[lab - 1] += 1;
                    }
                }
            }
        }
    }

    printf("Number of connected components: %d\n", clab);
    uint8_t * cols = genrandomcolo(clab);
    uint8_t * imgccmprgb = brecs_alloc(plane * 4 * sizeof(uint8_t));

    for (uint32_t i = 0; i < plane; ++i) {
        if (img[i]) {
            imgccmprgb[4 * i] = cols[3 * imglabs[i] - 3];
            imgccmprgb[1 + 4 * i] = cols[1 + 3 * imglabs[i] - 3];
            imgccmprgb[2 + 4 * i] = cols[2 + 3 * imglabs[i] - 3];
            imgccmprgb[3 + 4 * i] = 255;
        } else {
            imgccmprgb[4 * i] = 0;
            imgccmprgb[1 + 4 * i] = 0;
            imgccmprgb[2 + 4 * i] = 0;
            imgccmprgb[3 + 4 * i] = 255;
        }
    }
    brecs_free(cols);
#ifdef BRECS_DISPLAYPLOTS
    writetiff_rgb("connected_comp.tif", width, height, pixsdivz, imgccmprgb);
    //brecs_free(imgccmprgb);
#endif

    ccdec.imglab = imglabs;
    ccdec.rgbimg = (uint8_t *)imgccmprgb;
    return ccdec;
}

ccomp_dec connectcomp_decomp3d(float * img, veci3 * smes, params_t * par)
{
    uint16_t pixsdiv = par->pixsdiv;
    uint16_t pixsdivz = par->pixsdivz;
    uint16_t pixsdiv2 = pixsdiv * pixsdiv;
    uint16_t pixsdiv3 = pixsdivz * pixsdiv2;
    uint16_t kersize = par->kersize;
    uint16_t kersizez = par->kersizez;
    float prefacradcc = par->prefacradcc;
    float convolpixthr = par->convolpixthr;

    uint32_t nbmesx = smes->x;
    uint32_t nbmesy = smes->y;
    uint32_t nbmesz = smes->z;

    uint32_t sizex = nbmesx * pixsdiv;
    uint32_t sizey = nbmesy * pixsdiv;
    uint32_t sizez = nbmesz * pixsdivz;
    uint32_t size2 = sizex * sizey;
    uint32_t size3 = size2 * sizez;

    veci3 srec;
    srec.x = sizex;
    srec.y = sizey;
    srec.z = sizez;

    uint32_t nbmes2 = nbmesx * nbmesy;
    uint32_t nbmes3 = nbmesx * nbmesy * nbmesz;

    uint32_t sxfft = 1 << (uint32_t)ceilf(log2f(sizex));
    uint32_t syfft = 1 << (uint32_t)ceilf(log2f(sizey));
    uint32_t sfft2 = sxfft * syfft;
    uint32_t szfft = 1 << (uint32_t)ceilf(log2f(sizez));
    uint32_t s3fft = sxfft * syfft * szfft;

    float * imgsmoo = (float *)fftwf_malloc(s3fft * sizeof(float));
    if (!imgsmoo) exit(EXIT_FAILURE);
    for (uint32_t i = 0; i < sxfft * syfft * szfft; ++i) {
        imgsmoo[i] = 0;
    }
    for (uint32_t i = 0; i < nbmes3; ++i) {
        float val = img[i];
        uint32_t ci = (i % nbmes2) % nbmesx;
        uint32_t li = (i % nbmes2) / nbmesx;
        uint32_t zi = i / nbmes2;
        for (uint32_t j = 0; j < pixsdiv3; ++j) {
            uint32_t ind = ci * pixsdiv + j % pixsdiv
                      + sxfft * (li * pixsdiv + (j % pixsdiv2) / pixsdiv)
                      + sfft2 * (zi * pixsdivz + (j / pixsdiv2) % pixsdivz);
            imgsmoo[ind] = val;
        }
    }
    fftwf_complex * out1, * out2;
    fftwf_plan pforw1, pforw2, pbackw;

#ifdef BRECS_DISPLAYPLOTS
    writetiff_f("befsmoothedimg.tif", sxfft, syfft, szfft, imgsmoo);
#endif

    float * imgker = gausskerpar(sxfft, syfft, szfft,
                                 prefacradcc * pixsdiv,
                                 prefacradcc * pixsdivz);

    s3fft = szfft * syfft * (sxfft / 2 + 1);
    out1 = (fftwf_complex *)fftwf_malloc(s3fft * sizeof(fftwf_complex));
    out2 = (fftwf_complex *)fftwf_malloc(s3fft * sizeof(fftwf_complex));

    pforw1 = fftwf_plan_dft_r2c_3d((int32_t)szfft, (int32_t)syfft, (int32_t)sxfft,
                                   imgsmoo, out1,
                                   FFTW_ESTIMATE);
    pforw2 = fftwf_plan_dft_r2c_3d((int32_t)szfft, (int32_t)syfft, (int32_t)sxfft,
                                   imgker, out2,
                                   FFTW_ESTIMATE);

    pbackw = fftwf_plan_dft_c2r_3d((int32_t)szfft, (int32_t)syfft, (int32_t)sxfft,
                                   out1, imgsmoo,
                                   FFTW_ESTIMATE);

    fftwf_execute(pforw1);
    fftwf_execute(pforw2);
    fftwf_free(imgker);

    for (uint32_t i = 0; i < szfft * syfft * (sxfft / 2 + 1); ++i) {
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

#ifdef BRECS_DISPLAYPLOTS
    writetiff_f("smoothedimg.tif", sxfft, syfft, szfft, imgsmoo);
#endif

    lab_t * imgccmp = brecs_alloc(size3 * sizeof(lab_t));
    for (uint32_t i = 0; i < size3; ++i) {
        imgccmp[i] = 0;
    }
    for (uint32_t k = pixsdivz * (kersizez / 2);
            k < sizez - pixsdivz * (kersizez / 2); ++k) {
        for (uint32_t j = pixsdiv * kersize / 2;
                j < sizey - pixsdiv * kersize / 2; ++j) {
            for (uint32_t i = pixsdiv * kersize / 2;
                    i < sizex - pixsdiv * kersize / 2; ++i) {
                if (imgsmoo[i + j * sxfft + k * sfft2] > convolpixthr) {
                    imgccmp[i + j * sizex + k * size2] = 1;
                }
            }
        }
    }

    uint8_t * imgthrrgb = brecs_alloc(4 * size3 * sizeof(uint8_t));
    for (uint32_t k = 0; k < sizez; ++k) {
        for (uint32_t j = 0; j < sizey; ++j) {
            for (uint32_t i = 0; i < sizex; ++i) {
                uint32_t ind = i + j * sizex + k * sizex * sizey;
                if (imgccmp[ind]) {
                    imgthrrgb[4 * ind] = 255;
                    imgthrrgb[1 + 4 * ind] = 255;
                    imgthrrgb[2 + 4 * ind] = 255;
                    imgthrrgb[3 + 4 * ind] = 255;
                } else {
                    imgthrrgb[4 * ind] = 0;
                    imgthrrgb[1 + 4 * ind] = 0;
                    imgthrrgb[2 + 4 * ind] = 0;
                    imgthrrgb[3 + 4 * ind] = 255;
                }
            }
        }
    }
#ifdef BRECS_DISPLAYPLOTS
    writetiff_rgb("imgthrrgb.tif", sizex, sizey, sizez, imgthrrgb);
#endif

    printf("thresholding over\n");

    lab_t * rker = roundker(pixsdiv * kersize / 2, pixsdivz * (kersizez / 2));
    printf("ker gen over\n");
    lab_t * imgdil = dilate(imgccmp, sizex, sizey, sizez,
                            rker,
                            pixsdiv * kersize / 2, pixsdivz * (kersizez / 2));

    printf("dilation over\n");

#ifdef BRECS_DISPLAYPLOTS
    uint8_t * imgdilrgb = brecs_alloc(4 * size3 * sizeof(uint8_t));
    for (uint32_t k = 0; k < sizez; ++k) {
        for (uint32_t j = 0; j < sizey; ++j) {
            for (uint32_t i = 0; i < sizex; ++i) {
                uint32_t ind = i + j * sizex + k * sizex * sizey;
                if (imgdil[ind]) {
                    imgdilrgb[4 * ind] = 255;
                    imgdilrgb[1 + 4 * ind] = 255;
                    imgdilrgb[2 + 4 * ind] = 255;
                    imgdilrgb[3 + 4 * ind] = 255;
                } else {
                    imgdilrgb[4 * ind] = 0;
                    imgdilrgb[1 + 4 * ind] = 0;
                    imgdilrgb[2 + 4 * ind] = 0;
                    imgdilrgb[3 + 4 * ind] = 255;
                }
            }
        }
    }
    writetiff_rgb("imgdilrgb.tif", sizex, sizey, sizez, imgdilrgb);
    brecs_free(imgdilrgb);
#endif

    brecs_free(rker);
    ccomp_dec ccdec = aggregate(imgccmp, imgdil, &srec, par);

    brecs_free(imgdil);
    brecs_free(imgccmp);
    fftwf_free(out1);
    fftwf_free(out2);
    fftwf_free(imgsmoo);

    fftwf_cleanup();

    return ccdec;
}

uint8_t * imgrgb_ccomp(ccomp_dec * ccomp, uint32_t nbmesx, uint32_t nbmesy,
                       params_t * par)
{
    uint16_t pixsdiv = par->pixsdiv;

    uint32_t sizex = nbmesx * pixsdiv;
    uint32_t sizey = nbmesy * pixsdiv;
    uint32_t size2 = sizex * sizey;

    uint8_t * imgthrrgb = brecs_alloc(4 * size2 * sizeof(uint8_t));
    for (uint32_t j = 0; j < sizey; ++j) {
        for (uint32_t i = 0; i < sizex; ++i) {
            uint32_t ind = i + j * sizex;
            if (ccomp->imglab[ind]) {
                imgthrrgb[4 * ind] = 255;
                imgthrrgb[1 + 4 * ind] = 255;
                imgthrrgb[2 + 4 * ind] = 255;
                imgthrrgb[3 + 4 * ind] = 255;
            } else {
                imgthrrgb[4 * ind] = 0;
                imgthrrgb[1 + 4 * ind] = 0;
                imgthrrgb[2 + 4 * ind] = 0;
                imgthrrgb[3 + 4 * ind] = 255;
            }
        }
    }

    return imgthrrgb;
}

ccomp_dec connectcomp_decomp2d(float * img, veci3 * smes, params_t * par)
{
    uint16_t pixsdiv = par->pixsdiv;
    uint16_t pixsdiv2 = pixsdiv * pixsdiv;
    uint16_t kersize = par->kersize;
    float prefacradcc = par->prefacradcc;
    float convolpixthr = par->convolpixthr;

    uint32_t nbmesx = smes->x;
    uint32_t nbmesy = smes->y;

    uint32_t sizex = nbmesx * pixsdiv;
    uint32_t sizey = nbmesy * pixsdiv;
    uint32_t size2 = sizex * sizey;

    uint32_t nbmes2 = nbmesx * nbmesy;

    uint32_t sxfft = (uint32_t)floorf(powf(2, floorf(log2f(sizex) + 1)));
    uint32_t syfft = (uint32_t)floorf(powf(2, floorf(log2f(sizey) + 1)));

    uint32_t s2fft = sxfft * syfft;
    float * imgsmoo = (float *)fftwf_malloc(s2fft * sizeof(float));
    if (!imgsmoo) exit(EXIT_FAILURE);
    for (uint32_t i = 0; i < sxfft * syfft; ++i) {
        imgsmoo[i] = 0;
    }
    for (uint32_t i = 0; i < nbmes2; ++i) {
        float val = img[i];
        uint32_t ci = i % nbmesx;
        uint32_t li = i / nbmesx;
        for (uint16_t j = 0; j < pixsdiv2; ++j) {
            uint32_t ind = ci * pixsdiv + j % pixsdiv
                      + sxfft * (li * pixsdiv + j / pixsdiv);
            imgsmoo[ind] = val;
        }
    }
    fftwf_complex * out1, * out2;
    fftwf_plan pforw1, pforw2, pbackw;

#ifdef BRECS_DISPLAYPLOTS
    writetiff_f("befsmoothedimg.tif", sxfft, syfft, 1, imgsmoo);
#endif

    float * imgker = gausskerpar2d(sxfft, syfft, prefacradcc * pixsdiv);

    s2fft = syfft * (sxfft / 2 + 1);
    out1 = (fftwf_complex *)fftwf_malloc(s2fft * sizeof(fftwf_complex));
    out2 = (fftwf_complex *)fftwf_malloc(s2fft * sizeof(fftwf_complex));

    pforw1 = fftwf_plan_dft_r2c_2d((int32_t)syfft, (int32_t)sxfft,
                                   imgsmoo, out1,
                                   FFTW_ESTIMATE);
    pforw2 = fftwf_plan_dft_r2c_2d((int32_t)syfft, (int32_t)sxfft,
                                   imgker, out2,
                                   FFTW_ESTIMATE);

    pbackw = fftwf_plan_dft_c2r_2d((int32_t)syfft, (int32_t)sxfft,
                                   out1, imgsmoo,
                                   FFTW_ESTIMATE);

    fftwf_execute(pforw1);
    fftwf_execute(pforw2);
    fftwf_free(imgker);

    for (uint32_t i = 0; i < syfft * (sxfft / 2 + 1); ++i) {
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

#ifdef BRECS_DISPLAYPLOTS
    writetiff_f("smoothedimg.tif", sxfft, syfft, 1, imgsmoo);
#endif

    lab_t * imgccmp;
    int errnopos = brecs_memalign((void **)&imgccmp, size2 * sizeof(lab_t));
    if (!imgccmp) brecs_error("Failed to allocate memory for imgccmp: ",
                              strerror(errnopos), prog_name);
    for (uint32_t i = 0; i < size2; ++i) {
        imgccmp[i] = 0;
    }
    for (uint32_t j = pixsdiv * kersize / 2;
            j < sizey - pixsdiv * kersize / 2; ++j) {
        for (uint32_t i = pixsdiv * kersize / 2;
                i < sizex - pixsdiv * kersize / 2; ++i) {
            if (imgsmoo[i + j * sxfft] > convolpixthr) {
                imgccmp[i + j * sizex] = 1;
            }
        }
    }

#ifdef BRECS_DISPLAYPLOTS
    uint8_t * imgthrrgb = brecs_alloc(4 * size2 * sizeof(uint8_t));
    for (uint32_t j = 0; j < sizey; ++j) {
        for (uint32_t i = 0; i < sizex; ++i) {
            uint32_t ind = i + j * sizex;
            if (imgccmp[ind]) {
                imgthrrgb[4 * ind] = 255;
                imgthrrgb[1 + 4 * ind] = 255;
                imgthrrgb[2 + 4 * ind] = 255;
                imgthrrgb[3 + 4 * ind] = 255;
            } else {
                imgthrrgb[4 * ind] = 0;
                imgthrrgb[1 + 4 * ind] = 0;
                imgthrrgb[2 + 4 * ind] = 0;
                imgthrrgb[3 + 4 * ind] = 255;
            }
        }
    }
    writetiff_rgb("imgthrrgb.tif", sizex, sizey, 1, imgthrrgb);
#endif

    lab_t * rker = roundker2d(pixsdiv * kersize / 2);
    lab_t * imgdil = dilate2d(imgccmp, sizex, sizey,
                              rker,
                              pixsdiv * kersize / 2);

#ifdef BRECS_DISPLAYPLOTS
    uint8_t * imgdilrgb = brecs_alloc(4 * size2 * sizeof(uint8_t));
    for (uint32_t j = 0; j < sizey; ++j) {
        for (uint32_t i = 0; i < sizex; ++i) {
            uint32_t ind = i + j * sizex;
            if (imgdil[ind]) {
                imgdilrgb[4 * ind] = 255;
                imgdilrgb[1 + 4 * ind] = 255;
                imgdilrgb[2 + 4 * ind] = 255;
                imgdilrgb[3 + 4 * ind] = 255;
            } else {
                imgdilrgb[4 * ind] = 0;
                imgdilrgb[1 + 4 * ind] = 0;
                imgdilrgb[2 + 4 * ind] = 0;
                imgdilrgb[3 + 4 * ind] = 255;
            }
        }
    }
    writetiff_rgb("imgdilrgb.tif", sizex, sizey, 1, imgdilrgb);
    brecs_free(imgdilrgb);
#endif

    brecs_free(rker);
    ccomp_dec ccdec = aggregate2d(imgccmp, imgdil, sizex, sizey, par);

    brecs_free(imgdil);
    brecs_free(imgccmp);
    fftwf_free(out1);
    fftwf_free(out2);
    fftwf_free(imgsmoo);

    fftwf_cleanup();

    return ccdec;
}

void brecs_initimgmes(images_t * images, params_t * par) {
    uint32_t kersize = par->kersize;
    uint32_t kersizez = par->kersizez;
    float mesoffset = par->mesoffset;
    float mesampli = par->mesampli;
    float meanback = par->meanback;
    float noiseoffset = par->noiseoffset;

    float * imgmes;
    float * imgnoise;

    uint32_t insx = images->insize.x;
    uint32_t insy = images->insize.y;
    uint32_t insz = images->insize.z;

    const uint32_t nbmesx = insx + kersize;
    const uint32_t nbmesy = insy + kersize;
    const uint32_t nbmesz = insz + kersizez - kersizez % 2;
    const uint32_t nbmes2 = nbmesx * nbmesy;
    const uint32_t nbmes3 = nbmes2 * nbmesz;

    int errnopos = brecs_memalign((void **)&imgmes,
                                 nbmes3 * sizeof(float));
    if (!imgmes) brecs_error("Failed to allocate memory for imgmes: ",
                             strerror(errnopos), prog_name);
    errnopos = brecs_memalign((void **)&imgnoise,
                          nbmes3 * sizeof(float));
    if (!imgnoise) brecs_error("Failed to allocate memory for imgnoise: ",
                               strerror(errnopos), prog_name);

    for (uint32_t i = 0; i < nbmes3; ++i) {
        imgnoise[i] = 1e8;
        imgmes[i] = 0;
    }
    for (uint32_t k = 0; k < insz; ++k) {
        for (uint32_t j = 0; j < insy; ++j) {
            for (uint32_t i = 0; i < insx; ++i) {
                float val = images->img[i + j * insx + k * insx * insy];
                val = (val - mesoffset) / mesampli;

                float pixmes;
                if (images->imgback) {
                    float valback = images->imgback[i + j * insx + k * insx * insy];
                    valback = (valback - mesoffset) / mesampli;
                    pixmes = val - valback;
                } else {
                    pixmes = val - (meanback - mesoffset) / mesampli;
                }
                uint32_t ind = i + kersize / 2 + (j + kersize / 2) * nbmesx
                          + (k + kersizez / 2) * nbmesx * nbmesy;
                imgmes[ind] = pixmes;
                imgnoise[ind] = noiseoffset + 1.0f * val;
            }
        }
    }
    images->imgmes = imgmes;
    images->imgmessize.x = nbmesx;
    images->imgmessize.y = nbmesy;
    images->imgmessize.z = nbmesz;

    images->imgnoise = imgnoise;

    //brecs_free(images->img);
}

/* Notes: calls exit on error. */
void brecs(images_t * images, params_t * par) {
    uint32_t pixsdiv = par->pixsdiv;
    uint32_t pixsdivz = par->pixsdivz;
    uint32_t pixsdiv2 = pixsdiv * pixsdiv;
    uint32_t pixsdiv3 = pixsdivz * pixsdiv2;
    uint32_t kersize = par->kersize;
    uint32_t kersize2 = kersize * kersize;
    uint32_t kersizez = par->kersizez;
    uint32_t kersize3 = kersize2 * kersizez;
    float mesoffset = par->mesoffset;
    float mesampli = par->mesampli;
    float meanback = par->meanback;
    float noiseoffset = par->noiseoffset;

    float * imgmes;
    float * imgker;
    float * imgnoise;
    float * imgrecons;

    const uint32_t insx = images->insize.x;
    const uint32_t insy = images->insize.y;
    const uint32_t insz = images->insize.z;

    const uint32_t nbmesx = insx + kersize;
    const uint32_t nbmesy = insy + kersize;
    const uint32_t nbmesz = insz + kersizez - kersizez % 2;
    const uint32_t nbmes2 = nbmesx * nbmesy;
    const uint32_t nbmes3 = nbmes2 * nbmesz;

    veci3 smes;
    smes.x = nbmesx;
    smes.y = nbmesy;
    smes.z = nbmesz;

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
    for (uint32_t i = 0; i < nbmes3; ++i) {
        imgnoise[i] = 1e8f;
        imgmes[i] = 0.0f;
    }
    for (uint32_t k = 0; k < insz; ++k) {
        for (uint32_t j = 0; j < insy; ++j) {
            for (uint32_t i = 0; i < insx; ++i) {
                float val = images->img[i + j * insx + k * insx * insy];
                val = (val - mesoffset) / mesampli;

                float pixmes;
                if (images->imgback) {
                    uint32_t ind = i + j * insx + k * insx * insy;
                    float valback = images->imgback[ind];
                    valback = (valback - mesoffset) / mesampli;
                    pixmes = val - valback;
                } else {
                    pixmes = val - (meanback - mesoffset) / mesampli;
                }
                uint32_t ind = i + kersize / 2 + (j + kersize / 2) * nbmesx
                          + (k + kersizez / 2) * nbmesx * nbmesy;
                imgmes[ind] = pixmes;
                imgnoise[ind] = noiseoffset + 1.0f * val;
            }
        }
    }
    brecs_free(images->img);

#ifdef BRECS_DISPLAYPLOTS
    writetiff_f("imgmes.tif", nbmesx, nbmesy, nbmesz, imgmes);
    writetiff_f("imgnoise.tif", nbmesx, nbmesy, nbmesz, imgnoise);
#endif

    imgrecons = reconssparse(imgmes, imgnoise, &smes, images, par);

    brecs_free(imgker);
    brecs_free(imgmes);
    brecs_free(imgnoise);
    /* brecs_free(imgrecons); */
}
