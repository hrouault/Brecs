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

#include "Brecs.h"
#include "genpsf.h"
#include "javainterf.h"

void brecs_initin(imagessimp_t * images,
                  uint16_t * pixels, float * pixelsback,
                  unsigned int width, unsigned int height)
{
    images->img = malloc(sizeof(uint16img_t));
    images->img->img = malloc(width * height * sizeof(uint16_t));
    images->img->size.sx = width;
    images->img->size.sy = height;
    images->img->size.sz = 1;
    for (size_t i = 0; i < width * height; ++i) {
        images->img->img[i] = pixels[i];
    }
    if (pixelsback != (float *)pixels && pixels) {
        images->img_back = malloc(sizeof(fimg_t));
        images->img_back->img = malloc(width * height * sizeof(float));
        images->img_back->size.sx = width;
        images->img_back->size.sy = height;
        images->img_back->size.sz = 1;
        for (size_t i = 0; i < width * height; ++i) {
            images->img_back->img[i] = pixelsback[i];
        }
    } else {
        images->img_back = NULL;
    }
}

void brecs_initpsf(imagessimp_t * images, paramssimp_t * par)
{
    images->ker = malloc(sizeof(fimg_t));
    images->ker->img = malloc(par->oversamp * par->oversamp
                              * par->kersize * par->kersize * sizeof(float));
    images->ker->size.sx = par->oversamp;
    images->ker->size.sy = par->oversamp * par->kersize * par->kersize;
    images->ker->size.sz = 1;
}

void brecs_addpsfslice(imagessimp_t * images, paramssimp_t * par,
                       float * psfsl, int islice)
{
    size_t ker2 = par->kersize * par->kersize;
    for (size_t i = 0; i < ker2; ++i) {
        images->ker->img[i + islice * ker2] = psfsl[i];
    }
}

void brecs_reconstruction(imagessimp_t * images, paramssimp_t * params)
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
    par->pixsdiv = params->oversamp;
    par->pixsdivz = 1;

    imgs->insize.x = images->img->size.sx;
    imgs->insize.y = images->img->size.sy;
    imgs->insize.z = 1;
    printf("image size: %ld %ld %ld\n", imgs->insize.x,
                                        imgs->insize.y,
                                        imgs->insize.z);
    par->mesoffset = 0;
    par->convolpixthr = params->convolthr;
    par->damp1 = params->damp;
    par->damp2 = params->damp * 2.0;
    par->prefacradcc = 1.0;
    par->rho = params->rho;
    par->spixnm = 1.0;
    par->spixznm = 1.0;
    par->ainitpfact = 1.0;
    par->Ainit = par->ainitpfact / (par->pixmean * par->pixmean);
    printf("ainitpfact ainit %f %e\n", par->ainitpfact, par->Ainit);
    par->locaintensthr = params->locathr;
    par->overlaymaxint = params->pixmean * 0.5;
    par->overlayminint = 0.1;
    par->relerrthr = 0.001;
    par->nbinternloop = 1;

    if (images->img_back) {
        imgs->imgback = images->img_back->img;
    } else {
        imgs->imgback = NULL;
    }
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
    images->imgmes->size.sx = imgs->imgmessize.x;
    images->imgmes->size.sy = imgs->imgmessize.y;
    images->imgmes->size.sz = imgs->imgmessize.z;
    images->imgmes->img = imgs->imgmes;

    int nbmesx = images->imgmes->size.sx;
    int nbmesy = images->imgmes->size.sy;
    int nbmesz = images->imgmes->size.sz;
    printf("image size: %d %d %d\n", nbmesx, nbmesy, nbmesz);
    veci3 smes;
    smes.x = nbmesx;
    smes.y = nbmesy;
    smes.z = nbmesz;
    ccomp_dec ccdec = connectcomp_decomp2d(imgs->imgmes, &smes, par);

    images->ccomp = malloc(sizeof(rgbimg_t));
    images->ccomp->size.sx = nbmesx * par->pixsdiv;
    images->ccomp->size.sy = nbmesy * par->pixsdiv;
    images->ccomp->size.sz = 1;
    images->ccomp->img = ccdec.rgbimg;
    printf("%ld %ld\n", images->ccomp->size.sx, images->ccomp->size.sy);

    reconssparse(imgs->imgmes, imgs->imgnoise, &smes, imgs, par);
    images->recons = malloc(sizeof(fimg_t));
    images->recons->size.sx = imgs->outsize.x;
    images->recons->size.sy = imgs->outsize.y;
    images->recons->size.sz = 1;
    images->recons->img = imgs->reconspic;
    printf("Reconstruction done\n");

    images->overlay = malloc(sizeof(rgbimg_t));
    images->overlay->size.sx = imgs->outsize.x;
    images->overlay->size.sy = imgs->outsize.y;
    images->overlay->size.sz = 1;
    images->overlay->img = (uint32_t *)imgs->overlay;

    //free(imgs->ker);
    //free(imgs);
    //free(par);
}

void brecs_reconstruction_nocheck(imagessimp_t * images, paramssimp_t * params)
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
    par->pixsdiv = params->oversamp;
    par->pixsdivz = 1;

    imgs->insize.x = images->img->size.sx;
    imgs->insize.y = images->img->size.sy;
    imgs->insize.z = 1;
    printf("image size: %ld %ld %ld\n", imgs->insize.x,
                                        imgs->insize.y,
                                        imgs->insize.z);
    par->mesoffset = 0;
    par->convolpixthr = params->convolthr;
    par->damp1 = params->damp;
    par->damp2 = params->damp * 2.0;
    par->prefacradcc = 1.0;
    par->rho = params->rho;
    par->spixnm = 1.0;
    par->spixznm = 1.0;
    par->ainitpfact = 1.0;
    par->Ainit = par->ainitpfact / (par->pixmean * par->pixmean);
    printf("ainitpfact ainit %f %e\n", par->ainitpfact, par->Ainit);
    par->locaintensthr = params->locathr;
    par->overlaymaxint = params->pixmean * 0.5;
    par->overlayminint = 0.1;
    par->relerrthr = 0.001;
    par->nbinternloop = 1;

    if (images->img_back) {
        imgs->imgback = images->img_back->img;
    } else {
        imgs->imgback = NULL;
    }
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
    images->imgmes->size.sx = imgs->imgmessize.x;
    images->imgmes->size.sy = imgs->imgmessize.y;
    images->imgmes->size.sz = imgs->imgmessize.z;
    images->imgmes->img = imgs->imgmes;

    int nbmesx = images->imgmes->size.sx;
    int nbmesy = images->imgmes->size.sy;
    int nbmesz = images->imgmes->size.sz;
    printf("image size: %d %d %d\n", nbmesx, nbmesy, nbmesz);
    veci3 smes;
    smes.x = nbmesx;
    smes.y = nbmesy;
    smes.z = nbmesz;
    ccomp_dec ccdec = connectcomp_decomp2d(imgs->imgmes, &smes, par);

    reconssparse(imgs->imgmes, imgs->imgnoise, &smes, imgs, par);
    images->recons = malloc(sizeof(fimg_t));
    images->recons->size.sx = imgs->outsize.x;
    images->recons->size.sy = imgs->outsize.y;
    images->recons->size.sz = 1;
    images->recons->img = imgs->reconspic;
    printf("Reconstruction done\n");

    free(ccdec.rgbimg);
    free(imgs->overlay);
    //free(imgs->ker);
    //free(imgs);
    //free(par);
}

void brecs_psfgen(psf_params_t * psfpar)
{
    printf("sigma: %f, img width:%u\n", psfpar->psfwidth, psfpar->imagewidth);
    float * pic;
    pic = gaussker2d(psfpar->psfwidth / psfpar->pixsize,
                     psfpar->oversampling, psfpar->imagewidth, 10);
    psfpar->img = pic;
}

void recopy(imagessimp_t* image,
            uint32_t* ccomp_redisp, float* recons_redisp,
            uint32_t* over_redisp)
{
    size_t wccomp = image->ccomp->size.sx;
    size_t hccomp = image->ccomp->size.sy;
    for (size_t i = 0; i < wccomp * hccomp; ++i) {
        ccomp_redisp[i] = image->ccomp->img[i];
    }
    size_t wres = image->recons->size.sx;
    size_t hres = image->recons->size.sy;
    for (size_t i = 0; i < wres * hres; ++i) {
        recons_redisp[i] = image->recons->img[i];
        over_redisp[i] = image->overlay->img[i];
    }
    free(image->overlay->img);
    free(image->overlay);
    free(image->imgmes->img);
    free(image->imgmes);
    free(image->recons->img);
    free(image->recons);
    free(image->ccomp->img);
    free(image->ccomp);
    free(image->img_back->img);
    free(image->img_back);
    free(image->ker->img);
    free(image->ker);
    free(image->img->img);
    free(image->img);
}
void recopy_recons(imagessimp_t * image, float * recons_redisp)
{
    size_t wres = image->recons->size.sx;
    size_t hres = image->recons->size.sy;
    for (size_t i = 0; i < wres * hres; ++i) {
        recons_redisp[i] += image->recons->img[i];
    }
}

void recopypsf(psf_params_t * psf_par, float * psfdata)
{
    size_t size = psf_par->imagewidth * psf_par->imagewidth
                  * psf_par->oversampling * psf_par->oversampling;
    for (size_t i = 0; i < size; ++i) {
        psfdata[i] = psf_par->img[i];
    }
    free(psf_par->img);
}
