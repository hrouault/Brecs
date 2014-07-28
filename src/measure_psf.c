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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <tiffio.h>
#include <errno.h>

#include "inoutimg.h"

#ifdef MESPSF_NBITER
static int const nb_iter = MESPSF_NBITER;
#else
static int const nb_iter = 15;
#endif

#ifdef MESPSF_OVERSAMP
static int const oversamp = MESPSF_OVERSAMP;
#else
#define MESPSF_OVERSAMP 2
static int const oversamp = 2;
#endif

static int const oversamp2 = MESPSF_OVERSAMP * MESPSF_OVERSAMP;

#ifdef MESPSF_NBEXPL
static int const nbexpl = MESPSF_NBEXPL;
#else
static int const nbexpl = 5;
#endif

char * prog_name;

float err2(float * img, int * simg, int * pos, float * psf, int * spsf)
{
    float err = 0;
    float sumimg2 = 0;
    float psfiimgi = 0;
    float psf2 = 0;
    int ipsf = pos[0] % oversamp + (pos[1] % oversamp) * oversamp;
    float * psfsl = psf + (spsf[0] * spsf[1] * spsf[2] / oversamp2) * ipsf;
    //for (size_t i = 0; i < spsf[0] * spsf[1] * spsf[2] / oversamp2; ++i) {
    for (size_t i = 0; i < spsf[0] * spsf[1]; ++i) {
        int ixy = i % (spsf[0] * spsf[1]);
        //int iz = i / (spsf[0] * spsf[1]);
        int iz = spsf[2] / oversamp2 / 2;
        int px = pos[0] / oversamp - spsf[0] / 2 + ixy % spsf[0];
        int py = pos[1] / oversamp - spsf[1] / 2 + ixy / spsf[0];
        int pz = pos[2] - (spsf[2] / oversamp2) / 2 + iz;
        int posimg = px + py * simg[0] + pz * simg[0] * simg[1];
        //printf("%d %d %d\n", px, py, pz);

        float vimg = img[posimg];
        float vpsf = psfsl[i];
        //printf("vimg, vpsf: %d %f\n", vimg, vpsf);
        sumimg2 += vimg * vimg;
        psfiimgi += vimg * vpsf;
        psf2 += vpsf * vpsf;
    }
    //printf("err2 output, psf2: %f %f %f %f\n", sumimg2 - psfiimgi * psfiimgi / psf2, psf2, sumimg2, psfiimgi);

    return sumimg2 - psfiimgi * psfiimgi / psf2;
}

void measure_psf(char * fnpsf, char * fnimg, char * fnpos_list)
{
    /* input an approximate psf */
    int spsf[3];
    float * psf = opentiff_f(fnpsf, spsf, spsf + 1, spsf + 2);
    int spsf3 = spsf[0] * spsf[1] * spsf[2];

    /* Retrieve list of initial guess on position */
    int nbpoints = 0;
    FILE * pos_list = fopen(fnpos_list, "r");
    char * buffer;
    if (pos_list) {
        fseek(pos_list, 0, SEEK_END);
        int length = ftell(pos_list);
        fseek(pos_list, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer) {
            fread(buffer, 1, length, pos_list);
        }
        fclose(pos_list);
    } else {
        fprintf(stderr, "%s: cannot open file %s: %s\n",
                prog_name, fnpos_list, strerror(errno));
        exit(EXIT_FAILURE);
    }
    int * poss = malloc(3 * 1024 * sizeof(int));
    int nbpos = 0;
    char * tok = strtok(buffer, " \n");
    while (tok != NULL) {
        poss[nbpos] = atoi(tok);
        tok = strtok(NULL, " \n");
        nbpos++;
    }
    if (nbpos % 3 != 0) {
        fprintf(stderr, "%s: wrong number of float in %s\n", prog_name, fnpsf);
        exit(EXIT_FAILURE);
    }
    nbpos /= 3;
    printf("nb of positions: %d\n", nbpos);
    for (size_t i = 0; i < nbpos; ++i) {
        poss[3 * i] *= oversamp;
        poss[3 * i + 1] *= oversamp;
        //printf("%d %d %d\n", poss[3 * i], poss[3 * i + 1], poss[3 * i + 2]);
    }

    /* Open image to fit */
    printf("Opening image to fit\n");
    int simg[3];
    uint16_t * intimg = opentiff(fnimg, simg, simg + 1, simg + 2);
    int simg3 = simg[0] * simg[1] * simg[2];
    float * img = malloc(simg3 * sizeof(float));
    double sumpix = 0;
    for (size_t i = 0; i < simg3; ++i) {
        img[i] = intimg[i];
        sumpix += img[i];
    }
    sumpix /= simg3;
    for (size_t i = 0; i < simg3; ++i) {
        img[i] -= sumpix;
    }


    /* do the actual fit */
    printf("Computing the psf\n");
    int converged = 0;
    for (size_t j = 0; j < nbpos; ++j) {
        for (size_t i = 0; i < nb_iter; ++i) {
            float curerr = 1e15;
            int curpos[3] = {0, 0, 0};
            for (size_t ex3 = 0; ex3 < nbexpl * nbexpl; ++ex3) {
                int pos[3];
                pos[0] = poss[3 * j] - nbexpl / 2 + ex3 % nbexpl;
                pos[1] = poss[3 * j + 1] - nbexpl / 2 + ex3 / nbexpl;
                pos[2] = poss[3 * j + 2];
                //printf("%d %d %d\n", pos[0], pos[1], pos[2]);
                float intens;
                float err = err2(img, simg, pos, psf, spsf);
                if (err < curerr) {
                    curerr = err;
                    curpos[0] = pos[0];
                    curpos[1] = pos[1];
                }
            }
            //printf("Error, position: %f %d %d\n",
            //       curerr, curpos[0], curpos[1]);
            poss[3 * j] = curpos[0];
            poss[3 * j + 1] = curpos[1];
        }
    }

    /* Output a nice psf */
    float * outpsf = malloc(spsf3 * sizeof(float));
    for (size_t i = 0; i < spsf3; ++i) {
        outpsf[i] = 0;
    }
    for (size_t j = 0; j < nbpos; ++j) {
        int offipsf = (poss[3 * j] % oversamp
                       + oversamp * (poss[3 * j + 1] % oversamp))
                      * spsf3 / oversamp2;
        for (size_t i = 0; i < spsf3 / oversamp2; ++i) {
            int ixy = i % (spsf[0] * spsf[1]);
            int iz = i / (spsf[0] * spsf[1]);
            int px = poss[3 * j] / oversamp - spsf[0] / 2 + ixy % spsf[0];
            int py = poss[3 * j + 1] / oversamp - spsf[1] / 2 + ixy / spsf[0];
            int pz = poss[3 * j + 2] - spsf[2] / oversamp2 / 2 + iz;
            int posimg = px + py * simg[0] + pz * simg[0] * simg[1];
            //printf("pos: %d %d %d %d\n", poss[3 * j], poss[3 * j + 1], poss[3 * j + 2], posimg);

            float vimg = img[posimg];
            outpsf[i + offipsf] += vimg;
            //outpsf[i] += vimg;
        }
    }
    writetiff_f("outpsf.tif", spsf[0], spsf[1], spsf[2], outpsf);



    free(outpsf);
    free(poss);
    free(img);
    free(psf);
}


int main(int argc, char ** argv)
{
    /* Remove libtiff warnings */
    TIFFSetWarningHandler(NULL);

    /* Command line parser */
    char * arg0 = argv[0];
    arg0 = strrchr(arg0, '/');
    if (arg0)
        prog_name = arg0 + 1;
    else
        prog_name = argv[0];

    if (argc != 4) {
        fprintf(stderr,
                "%s: usage: measure_psf psf.tif img.tif positions.dat\n",
                prog_name);
        exit(EXIT_FAILURE);
    } else {
        measure_psf(argv[1], argv[2], argv[3]);
    }

    return EXIT_SUCCESS;
}
