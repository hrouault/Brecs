#ifndef PARAMETERS_H
#define PARAMETERS_H

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

/* This file contains the parameters necessary for the different datasets
 * analyzed by Brecs. For tha moment, the parameters are hardcoded for
 * efficiency but this could change in the future.
 *
 * Here are the different parameters:
 *
 * ** Prior **
 * For the moment the prior on the intensity distribution of a fluorophore is
 * gaussian:
 * Psi(I) = (1 - RHO) delta(I) + RHO * Gauss(PIXMEAN, PIXSTD)
 * where:
 * RHO: density of fluorophores
 * PIXMEAN: mean number of photons emitted by a fluorophore
 * PIXSTD: standard deviation of this number of photons
 *
 * ** Pixel sizes **
 * In general, I call pixel, a physical pixel measured by the camera and
 * superpixel, a unit pixel on the superresolved image computed by the program.
 * A florophore emits photons on a localized region of size SKER * SKER on the
 * camera.
 * The program builds an image with a pixel size smaller than the pixelsize of
 * the camera. Specifically, for one pixel on the camera, the program extracts
 * SMES * SMES superpixels.
 * The input images have size NBMESX * NBMESY pixels.
 * The physical size of a pixel is SIZEPIX.
 * When MODE3D is defined, the program will also try to extract the position in
 * z, the length separating two slices of the extracted stack is SIZEPIXZ.
 *
 * ** Internals of the program **
 * The help the algorithm to converge, the update of positions is dampended.
 * This is the "dirty" side of the algorithm and has to be adjusted by trial
 * and error.
 * DAMP is the amount of the relative intensity change (I usually use 0.1, but
 * it should be lowered when the program fails to converge).
 *
 * ** Statistics of the background **
 */

// DATASET 1 (eye 2 in ISBI contest)
#if DATASET == 1
#  define PIXMEAN 4800
#  define PIXSTD 400
#  define RHO 0.001
#  define SKER 8 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define NBMESX 256
#  define NBMESY 256
#  define SIZEPIX 150.0
#  define DAMP 0.2
#  define NOISEBACK 2000
#  define MEANBACK 100
#  define SIGPSF 0.732
#  define DEFOCUS 1.0 /* the 1.1 is for defocus */
#  define AINITPFACT 10.0
#  define NBITER 200
#  define THRPOINT 2000
#  define BETA 2 /* inverse temperature for inference */
#  define PIXTHR 500
#  define THRCONV 1e-3
// DATASET 2 (HD_1 in ISBI contest)
#elif DATASET == 2
#  define PIXMEAN 5500
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 8 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define NBMESX 128
#  define NBMESY 128
#  define SIZEPIX 100.0
#  define DAMP 0.1
#  define NOISEBACK 5620
#  define MEANBACK 200
#  define SIGPSF 0.9545
#  define DEFOCUS 1.0 /* the 1.1 is for defocus */
#  define AINITPFACT 10.0
#  define NBITER 600
#  define THRPOINT 2000
#  define BETA 2 /* inverse temperature for inference */
#  define PIXTHR 70
#  define THRCONV 1e-3
#  define KERNEL 1
// DATASET 3 (HD_2 in ISBI contest)
#elif DATASET == 3
#  define PIXMEAN 5000
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 12 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define NBMESX 128
#  define NBMESY 128
#  define SIZEPIX 150.0
#  define DAMP 0.1
#  define NOISEBACK 5000
#  define MEANBACK 200.0
#  define AINITPFACT 10.0
#  define NBITER 600
#  define THRPOINT 1000
#  define BETA 2 /* inverse temperature for inference */
#  define PIXTHR 300
#  define THRCONV 1e-3
#  define KERNEL 2
// DATASET 4 (HD_3 in ISBI contest)
#elif DATASET == 4
#  define PIXMEAN 4000
#  define PIXSTD 400
#  define RHO 0.001
#  define SKER 16 /* has to be a multiple of 4 to use sse */
#  define SMES 4
#  define NBMESX 200
#  define NBMESY 200
#  define SIZEPIX 100.0
#  define DAMP 0.05
#  define NOISEBACK 300 // should be 160
#  define MEANBACK 114
#  define AINITPFACT 10.0
#  define NBITER 600
#  define THRPOINT 1000
#  define BETA 2 /* inverse temperature for inference */
#  define PIXTHR 40
#  define THRCONV 1e-3
#  define KERNEL 2
#  define SMOOTHEN 0
#  define SIZESMOOTH 0
#  define GIBSSIZE 129
#  define GIBSFRAME 6
#  define SIZEZ 4
// DATASET 5 (LS_1 in ISBI contest)
#elif DATASET == 5
#  define PIXMEAN 5200
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 8 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define NBMESX 128
#  define NBMESY 128
#  define SIZEPIX 100.0
#  define DAMP 0.1
#  define NOISEBACK 5000
#  define MEANBACK 0
#  define SIGPSF 0.9545
#  define DEFOCUS 1.0 /* the 1.1 is for defocus */
#  define AINITPFACT 10.0
#  define NBITER 200
#  define THRPOINT 2000
#  define BETA 2 /* inverse temperature for inference */
#  define PIXTHR 120
#  define THRCONV 1e-3
#  define KERNEL 1
#  define SMOOTHEN 1
#  define SIZESMOOTH 0
// DATASET 6 (LS_2 in ISBI contest)
#elif DATASET == 6
#  define PIXMEAN 5000
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 12 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define NBMESX 128
#  define NBMESY 128
#  define SIZEPIX 150.0
#  define DAMP 0.1
#  define NOISEBACK 7000
#  define MEANBACK 0.0
#  define AINITPFACT 10.0
#  define NBITER 300
#  define THRPOINT 1000
#  define BETA 2 /* inverse temperature for inference */
#  define PIXTHR 300
#  define THRCONV 1e-3
#  define KERNEL 2
#  define SMOOTHEN 1
#  define SIZESMOOTH 0
#  define GIBSSIZE 129
#  define GIBSFRAME 6
#  define SIZEZ 4
// DATASET 7 (LS_3 in ISBI contest)
#elif DATASET == 7
#  define PIXMEAN 3500
#  define PIXSTD 250
#  define RHO 0.001
#  define SKER 16 /* has to be a multiple of 4 to use sse */
#  define SMES 4
#  define NBMESX 200
#  define NBMESY 200
#  define SIZEPIX 100.0
#  define SIZEPIXZ 333.0
#  define DAMP 0.05
#  define NOISEBACK 200
#  define MEANBACK 109.0
#  define AINITPFACT 10.0
#  define NBITER 300
#  define THRPOINT 1000
#  define BETA 2 /* inverse temperature for inference */
#  define PIXTHR 20
#  define THRCONV 1e-3
#  define KERNEL 2
#  define SMOOTHEN 0
#  define SIZESMOOTH 0
#  define GIBSSIZE 129
#  define GIBSFRAME 6
#  define SIZEZ 4
// DATASET 10 (Clathrin coated pits)
#elif DATASET == 10
#  define PIXMEAN 4500
#  define PIXSTD 1000
#  define RHO 0.001
#  define SKER 12 /* has to be a multiple of 4 to use sse */
#  define SMES 12
#  define NBMESX 199
#  define NBMESY 329
#  define SIZEPIX 133.0
#  define SIZEPIXZ 333.0
#  define DAMP 0.05
#  define NOISEBACK 100.0
#  define MEANBACK 85.0
#  define AINITPFACT 10.0
#  define NBITER 600
#  define THRPOINT 1000
#  define BETA 2 /* inverse temperature for inference */
#  define PIXTHR 100
#  define THRCONV 1e-3
#  define KERNEL 1
#  define SIGPSF 1.04
#  define DEFOCUS 1.0 /* the 1.1 is for defocus */
#  define SMOOTHEN 0
#  define SIZESMOOTH 0
#  define GIBSSIZE 129
#  define GIBSFRAME 6
#  define SIZEZ 1
#  define RESCALEINPUT
#  define RESCALEOFFSET 300
#  define RESCALESLOPE 18.8
#  endif

#endif /* end of include guard: PARAMETERS_H */
