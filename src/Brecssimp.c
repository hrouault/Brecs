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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "Brecssimp.h"
#include "Brecs.h"

void brecs_initin(imagessimp_t * images,
                  uint16_t * pixels, unsigned int width, unsigned int height)
{
    images->img = malloc(sizeof(uint16img_t));
    images->img->img = malloc(width * height * sizeof(uint16_t));
    images->img->size.sx = width;
    images->img->size.sy = height;
    images->img->size.sz = 1;
    for (size_t i = 0; i < width * height; ++i) {
        images->img->img[i] = pixels[i];
    }
}

void brecs_initpsf(imagessimp_t * images, paramssimp_t * par,
                   unsigned int kersize, unsigned int pixsdiv)
{
    par->kersize = kersize;
    par->pixsdiv = pixsdiv;
    images->ker = malloc(sizeof(fimg_t));
    images->ker->img = malloc(pixsdiv * pixsdiv
                              * kersize * kersize * sizeof(float));
    images->ker->size.sx = kersize;
    images->ker->size.sy = kersize;
    images->ker->size.sz = pixsdiv * pixsdiv;
}

void brecs_addpsfslice(imagessimp_t * images, paramssimp_t * par,
                       float * psfsl, int islice)
{
    size_t ker2 = par->kersize * par->kersize;
    for (size_t i = 0; i < ker2; ++i) {
        images->ker->img[i + islice * ker2] = psfsl[i];
    }
}

void brecs_initimgmessimp(imagessimp_t * images, paramssimp_t * params)
{
    printf("mean: %f, std:%f\n", params->pixmean, params->pixstd);
    printf("image values: %d %d %d\n", images->img->img[0],
                                       images->img->img[1],
                                       images->img->img[20]);
    images_t * imgs = malloc(sizeof(images_t));
    params_t * par = malloc(sizeof(params_t));
    par->pixmean = params->pixmean;
    par->pixstd = params->pixstd;
    par->mesampli = params->mesampli;
    par->noiseoffset = params->noiseoffset;
    par->nbiter = params->nbiter;
    par->meanback = params->meanback;

    par->kersize = params->kersize;
    par->kersizez = 1;
    par->pixsdiv = params->pixsdiv;
    par->pixsdivz = 1;

    imgs->insize.sx = images->img->size.sx;
    imgs->insize.sy = images->img->size.sy;
    imgs->insize.sz = 1;
    printf("image size: %ld %ld %ld\n", imgs->insize.sx,
                                        imgs->insize.sy,
                                        imgs->insize.sz);
    par->mesoffset = 0;
    par->convolpixthr = 200.0;
    par->damp1 = 0.01;
    par->damp2 = 0.02;
    par->prefacradcc = 1.0;
    par->rho = 0.001;
    par->spixnm = 133;
    par->spixznm = 133;
    par->ainitpfact = 1.0;
    par->Ainit = par->ainitpfact / (par->pixmean * par->pixmean);
    printf("ainit %f\n", par->Ainit);
    par->locaintensthr = 1000.0;
    par->overlaymaxint = 50.0;
    par->overlayminint = 0.1;
    par->relerrthr = 0.001;
    par->nbinternloop = 1;

    imgs->imgback = NULL;
    imgs->img = images->img->img;

    int kersize = par->kersize;
    int pixsdiv = par->pixsdiv;
    size_t nbel = kersize * kersize * pixsdiv * pixsdiv;
    imgs->ker = malloc(nbel * sizeof(float));
    for (size_t i = 0; i < nbel; ++i) {
        imgs->ker[i] = images->ker->img[i];
    }

    brecs_initimgmes(imgs, par);

    printf("init done...\n");
    images->imgmes = malloc(sizeof(fimg_t));
    images->imgmes->size.sx = imgs->imgmessize.sx;
    images->imgmes->size.sy = imgs->imgmessize.sy;
    images->imgmes->size.sz = imgs->imgmessize.sz;
    images->imgmes->img = imgs->imgmes;

    int nbmesx = images->imgmes->size.sx;
    int nbmesy = images->imgmes->size.sy;
    int nbmesz = images->imgmes->size.sz;
    printf("image size: %d %d %d\n", nbmesx, nbmesy, nbmesz);
    ccomp_dec ccdec = connectcomp_decomp2d(imgs->imgmes, nbmesx, nbmesy, par);

    images->ccomp = malloc(sizeof(rgbimg_t));
    images->ccomp->size.sx = nbmesx * par->pixsdiv;
    images->ccomp->size.sy = nbmesy * par->pixsdiv;
    images->ccomp->size.sz = 1;
    images->ccomp->img = ccdec.rgbimg;
    printf("%ld %ld\n", images->ccomp->size.sx, images->ccomp->size.sy);

    reconssparse(imgs->imgmes, imgs->imgnoise,
                 nbmesx, nbmesy, nbmesz, imgs, par);
    images->recons = malloc(sizeof(fimg_t));
    images->recons->size.sx = nbmesx * par->pixsdiv;
    images->recons->size.sy = nbmesy * par->pixsdiv;
    images->recons->size.sz = 1;
    images->recons->img = imgs->reconspic;
    printf("Reconstruction done\n");
    //free(imgs);
}
