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
 
typedef unsigned short int lab_t;

typedef struct {
    unsigned nbcomp;
    lab_t * imglab;
    int * coordcomp;
    int * nbact;
    int ** activepixcomp;
} ccomp_dec;

struct params {
    int isok; /* valid? */

    /* signal noise properties */
    float    pixmean;      /*= BRECS_PIXMEAN; */
    float    pixstd;       /*= BRECS_PIXSTD; */
    float    rho;          /*= BRECS_RHO; */
    /* Sizes of the images */
    int      kersize;      /* = BRECS_KERSIZE; */
    int      kersizez;     /* = BRECS_KERSIZEZ; */
    int      pixsdiv;      /* = BRECS_PIXSDIV; */
    int      pixsdivz;     /* = BRECS_PIXSDIVZ; */
    unsigned kersize2;     /* = BRECS_KERSIZE * BRECS_KERSIZE; */
    unsigned kersize3;     /* = BRECS_KERSIZE * BRECS_KERSIZE * BRECS_KERSIZEZ; */
    unsigned pixsdiv2;     /* = BRECS_PIXSDIV * BRECS_PIXSDIV; */
    unsigned pixsdiv3;     /* = BRECS_PIXSDIV * BRECS_PIXSDIV * BRECS_PIXSDIVZ; */
    float    spixnm;       /* = BRECS_SPIXNM; */
    float    spixznm;      /* = BRECS_SPIXZNM; */
    float    mesoffset;    /* = BRECS_MESOFFSET; */
    float    mesampli;     /* = BRECS_MESAMPLI; */
    float    noiseoffset;  /* = BRECS_NOISEOFFSET; */
    int      nbiter;       /* = BRECS_NBITER; */
    float    prefacradcc;  /* = BRECS_PREFACRADCC; */
    float    convolpixthr; /* = BRECS_CONVOLPIXTHR; */
    float    ainitpfact;
    float    Ainit;        /* = BRECS_AINITPFACT / (BRECS_PIXMEAN * BRECS_PIXMEAN); */
    float    meanback;     /* = BRECS_MEANBACK; */
    float    locaintensthr;/* = BRECS_LOCAINTENSTHR; */
    float    overlaymaxint;/* = BRECS_OVERLAYMAXINT; */
    float    overlayminint;/* = BRECS_OVERLAYMININT; */
    float    relerrthr;    /* = BRECS_RELERRTHR; */
    float    nbinternloop; /* = BRECS_NBINTERNLOOP; */

    float damp1;           /* = BRECS_DAMP1; */
    float damp2;           /* = BRECS_DAMP2; */
};

struct images {
    uint16_t * img;
    float * imgback;
    struct size {int x,y,z;} insz;
};

ccomp_dec connectcomp_decomp3d(float * img,
                               int nbmesx, int nbmesy, int nbmesz);
ccomp_dec connectcomp_decomp2d(float * img,
                               int nbmesx, int nbmesy);

extern char * prog_name;

// float min(float * img, int size); //? used
// float max(float * img, int size);
float maxra(float * num, float * den, int size);
float minra(float * num, float * den, int size);

#define PLOT_NO_RESCALE 0
#define PLOT_RESCALE 1

#define MAX_LABEL 65355


#endif /* end of include guard: BRECS_H_GWC5RGBI */
