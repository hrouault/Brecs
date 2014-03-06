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
#include <gsl/gsl_fit.h>

#include "inoutimg.h"

#ifdef MESPSF_NBITER
static int const nb_iter = MESPSF_NBITER;
#else
static int const nb_iter = 2;
#endif

#ifdef MESPSF_OVERSAMP
static int const oversamp = MESPSF_OVERSAMP;
#else
static int const oversamp = 2;
#endif


char * prog_name;

void measure_psf(char * fnpsf, char * fnimg, char * fnpos_list)
{
    /* input an approximate psf */
    int sxpsf, sypsf, szpsf;
    float * psf = opentiff_f(fnpsf, &sxpsf, &sypsf, &szpsf);

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
        poss[nbpos] = 3 * atoi(tok);
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
        printf("%d %d %d\n", poss[3 * i], poss[3 * i + 1], poss[3 * i + 2]);
    }

    /* Open image to fit */
    int sx, sy, sz;
    float * img = opentiff_f(fnimg, &sx, &sy, &sz);


    /* do the actual fit */
    /*
    for current point positions
        for all the positions around it
            minimize the square error with the intensity parameter
    */

    for (size_t i = 0; i < nb_iter; ++i) {
        for (size_t j = 0; j < nbpos; ++j) {
            float cur_err = 1e10;
            int cur_pos[3] = {0, 0, 0};
            for (size_t ex3 = 0; ex3 < nb_explore; ++ex2) {
                float intens;
                float err = minimizese(img, pts, psf, &intens);
                if (err < cur_err) {
                    cur_err = err;
                    cur_pos[0] = px;
                    cur_pos[1] = py;
                    cur_pos[2] = pz;
                }
            }
        }
    }

    /* Output a nice psf */

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
