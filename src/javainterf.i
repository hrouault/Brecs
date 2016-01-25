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

%include "arrays_java.i"
%typemap(out) float[] {
    $result = SWIG_JavaArrayOutFloat(jenv, (float *)$1,
                   (arg1)->size.sx * (arg1)->size.sy * (arg1)->size.sz);
}
%typemap(out) short[] {
    $result = SWIG_JavaArrayOutShort(jenv, (int16_t *)$1,
                   (arg1)->size.sx * (arg1)->size.sy * (arg1)->size.sz);
}
%typemap(out) int[] {
    $result = SWIG_JavaArrayOutInt(jenv, (int32_t *)$1,
                   (arg1)->size.sx * (arg1)->size.sy * (arg1)->size.sz);
}

%apply float[] {float *};
%apply short[] {uint16_t *};
%apply int[] {uint32_t *};

%module Brecs
%{
#include <stdint.h>

typedef struct {
    size_t sx;
    size_t sy;
    size_t sz;
} sizeimg_t;

typedef struct {
    sizeimg_t size;
    float * img;
} fimg_t;

typedef struct {
    sizeimg_t size;
    uint16_t * img;
} uint16img_t;

typedef struct {
    sizeimg_t size;
    uint32_t * img;
} rgbimg_t;


typedef struct {
    /* signal noise properties */
    float pixmean;
    float pixstd;

    float rho;
    float mesampli;
    float noiseoffset;
    float convolthr;
    unsigned int nbiter;
    float meanback;
    float damp;
    float locathr;

    unsigned int oversamp;
    unsigned int kersize;
} paramssimp_t;

typedef struct {
    float psfwidth;
    unsigned int imagewidth;
    unsigned int oversampling;
    float pixsize;
    float * img;
} psf_params_t;

typedef struct {
    uint16img_t * img;
    fimg_t * ker;
    fimg_t * img_back;
    fimg_t * imgmes;
    fimg_t * recons;
    rgbimg_t * ccomp;
    rgbimg_t * overlay;
} imagessimp_t;

void brecs_allocin(imagessimp_t * images,
                  uint16_t * pixels, float * pixelsback,
                  unsigned int width, unsigned int height);
void brecs_initin(imagessimp_t * images,
                  uint16_t * pixels, float * pixelsback,
                  unsigned int width, unsigned int height);
void brecs_initpsf(imagessimp_t * images, paramssimp_t * par);
void brecs_reconstruction(imagessimp_t * images, paramssimp_t * params);
void brecs_reconstruction_nocheck(imagessimp_t * images,
                                  paramssimp_t * params);
void brecs_addpsfslice(imagessimp_t * images, paramssimp_t * par,
                       float * psfsl, int islice);
void brecs_psfgen(psf_params_t * psfpar);
void recopy(imagessimp_t * image,
            uint32_t * ccomp_redisp, float * recons_redisp,
            uint32_t * over_redisp);
void recopy_recons(imagessimp_t * image, float * recons_redisp);
void freepsf(psf_params_t * psf_par);
void recopypsf(psf_params_t * psf_par, float * psfdata);

%}

typedef struct {
    size_t sx;
    size_t sy;
    size_t sz;
} sizeimg_t;

typedef struct {
    sizeimg_t size;
    float * img;
} fimg_t;

typedef struct {
    sizeimg_t size;
    uint16_t * img;
} uint16img_t;

typedef struct {
    sizeimg_t size;
    uint32_t * img;
} rgbimg_t;


typedef struct {
    /* signal noise properties */
    float pixmean;
    float pixstd;

    float rho;
    float mesampli;
    float noiseoffset;
    float convolthr;
    unsigned int nbiter;
    float meanback;
    float damp;
    float locathr;

    unsigned int oversamp;
    unsigned int kersize;
} paramssimp_t;

typedef struct {
    float psfwidth;
    unsigned int imagewidth;
    unsigned int oversampling;
    float pixsize;
} psf_params_t;

typedef struct {
    uint16img_t * img;
    fimg_t * ker;
    fimg_t * img_back;
    fimg_t * imgmes;
    fimg_t * recons;
    rgbimg_t * ccomp;
    rgbimg_t * overlay;
} imagessimp_t;

void brecs_allocin(imagessimp_t * images,
                  uint16_t * pixels, float * pixelsback,
                  unsigned int width, unsigned int height);
void brecs_initin(imagessimp_t * images,
                  uint16_t * pixels, float * pixelsback,
                  unsigned int width, unsigned int height);
void brecs_initpsf(imagessimp_t * images, paramssimp_t * par);
void brecs_reconstruction(imagessimp_t * images, paramssimp_t * params);
void brecs_reconstruction_nocheck(imagessimp_t * images,
                                  paramssimp_t * params);
void brecs_addpsfslice(imagessimp_t * images, paramssimp_t * par,
                       float * psfsl, int islice);
void brecs_psfgen(psf_params_t * psfpar);
void recopy(imagessimp_t * image,
            uint32_t * ccomp_redisp, float * recons_redisp,
            uint32_t * over_redisp);
void recopy_recons(imagessimp_t * image, float * recons_redisp);
void freepsf(psf_params_t * psf_par);
void recopypsf(psf_params_t * psf_par, float * psfdata);
