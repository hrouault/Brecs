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

#ifndef BRECS_H_GWC5RGBI
#define BRECS_H_GWC5RGBI

#include <stdint.h>
#include <stdlib.h>
#include <platform.h>

typedef uint16_t lab_t;

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} veci3;

typedef struct {
    unsigned nbcomp;
    lab_t * imglab;
    uint32_t * rgbimg;
    int * coordcomp;
    int * nbact;
    int ** activepixcomp;
} ccomp_dec;

typedef struct {
    /* signal noise properties */
    float    pixmean;
    float    pixstd;
    float    rho;
    /* Sizes of the images */
    int      kersize;
    int      kersizez;
    int      pixsdiv;
    int      pixsdivz;

    float    spixnm;
    float    spixznm;

    float    mesoffset;
    float    mesampli;
    float    noiseoffset;
    int      nbiter;
    float    prefacradcc;
    float    convolpixthr;
    float    ainitpfact;
    float    Ainit;
    float    meanback;
    float    locaintensthr;
    float    overlaymaxint;
    float    overlayminint;
    float    relerrthr;
    float    nbinternloop;

    float damp1;
    float damp2;
} params_t;

typedef struct {
    uint16_t * img;
    float * imgmes;
    float * imgnoise;
    float * imgback;
    float * ker;
    float * reconspic;
    veci3 insize;
    veci3 outsize;
    veci3 imgmessize;
} images_t;

typedef struct {
    afloat * mu_albe_A;
    afloat * mu_albe_B;
    afloat * abeal;
    afloat * vbeal;
    float * sum_mualbe_A;
    float * sum_mualbe_B;
    afloat * omegamu;
    afloat * vmu;
    afloat * ker;
    afloat * ker2;
    afloat * imgnoise;
    afloat * imgmes;
    unsigned int nbact;
    int * activepix;
} simdarrays_t;

ccomp_dec connectcomp_decomp3d(float * img,
                               int nbmesx, int nbmesy, int nbmesz,
                               params_t * par);
ccomp_dec connectcomp_decomp2d(float * img,
                               int nbmesx, int nbmesy,
                               params_t * par);

uint8_t * imgrgb_ccomp(ccomp_dec * ccomp, int nbmesx, int nbmesy,
                       params_t * par);

float * reconssparse(float * imgmes,float * imgnoise,
                     int nbmesx, int nbmesy, int nbmesz,
                     images_t * images, params_t * par);

void brecs_initimgmes(images_t * images, params_t * par);
void brecs(images_t * images, params_t * par);

extern char * prog_name;

float maxra(float * num, float * den, int size);
float minra(float * num, float * den, int size);

#endif /* end of include guard: BRECS_H_GWC5RGBI */
