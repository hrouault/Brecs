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

/* General parameters for display */
#define DISPLAY_OVERLAY_ITER 0
#define DISPLAY_OVERLAY 0
#define DISPLAY_PLOTS 0
#define PRINT_ERRS 0
#define OVERLAY_MAX_INT 10000.0
#define OVERLAY_MIN_INT 10.0

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
#  define PREFAC_RAD_CC 1.0
// DATASET 2 (HD_1 in ISBI contest)
#elif DATASET == 2
#  define PIXMEAN 5300
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 12 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define SIZEZ 1
#  define NBMESX 128
#  define NBMESY 128
#  define SIZEPIX 100.0
#  define DAMP1 0.01
#  define DAMP2 0.02
#  define NOISEBACK 3000
#  define MEANBACK 180
#  define SIGPSF 0.9545
#  define DEFOCUS 1.15 /* the 1.1 is for defocus */
#  define AINITPFACT 10.0
#  define NBITER 5000
#  define THRPOINT 2000
#  define BETA 3.0 /* inverse temperature for inference */
#  define PIXTHR 150
#  define THRCONV 1e-3
#  define KERNEL 1
#  define SMOOTHEN 1
#  define SMOOTHEN_RAD 8
#  define SMOOTHEN_THR 250
#  define SIZESMOOTH 0
#  define SIZEPIXZ 333.0
#  define PREFAC_RAD_CC 1.0
// DATASET 3 (HD_2 in ISBI contest)
#elif DATASET == 3
#  define PIXMEAN 5000
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 16 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define SIZEZ 1
#  define NBMESX 128
#  define NBMESY 128
#  define SIZEPIX 150.0
#  define DAMP1 0.01
#  define DAMP2 0.02
#  define NOISEBACK 2000
#  define MEANBACK 150.0
#  define AINITPFACT 2.0
#  define NBITER 5000
#  define THRPOINT 1000
#  define BETA 2.5 /* inverse temperature for inference */
#  define PIXTHR 150
#  define THRCONV 1e-3
#  define GIBSSIZE 257
#  define KERNEL 2
#  define SIZEPIXZ 333.0
#  define PREFAC_RAD_CC 1.0
// DATASET 4 (HD_3 in ISBI contest)
#elif DATASET == 4
#  define PIXMEAN 1500
#  define PIXSTD 200
#  define RHO 0.001
#  define SKER 20 /* has to be a multiple of 4 to use sse */
#  define SMES 4
#  define NBMESX 200
#  define NBMESY 200
#  define SIZEPIX 100.0
#  define SIZEPIXZ 333.0
#  define DAMP1 0.01
#  define DAMP2 0.02
#  define NOISEBACK 22.0
#  define MEANBACK 108.0
#  define AINITPFACT 10.0
#  define NBITER 4000
#  define THRPOINT 450
#  define BETA 3.0 /* inverse temperature for inference */
#  define PIXTHR 12
#  define THRCONV 1e-3
#  define KERNEL 2
#  define SMOOTHEN 1
#  define SMOOTHEN_RAD 18
#  define SMOOTHEN_THR 15
#  define SIZESMOOTH 0
#  define GIBSSIZE 129
#  define GIBSFRAME 0
#  define SIZEZ 4
#  define PREFAC_RAD_CC 2.0
// DATASET 5 (LS_1 in ISBI contest)
#elif DATASET == 5
#  define PIXMEAN 5000
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 12 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define NBMESX 128
#  define NBMESY 128
#  define SIZEPIX 100.0
#  define SIZEZ 1
#  define DAMP1 0.01
#  define DAMP2 0.02
#  define NOISEBACK 3400
#  define MEANBACK 180
#  define SIGPSF 0.9545
#  define DEFOCUS 1.15 /* the 1.1 is for defocus */
#  define AINITPFACT 10.0
#  define NBITER 3000
#  define THRPOINT 2000
#  define BETA 2.2 /* inverse temperature for inference */
#  define PIXTHR 150
#  define THRCONV 1e-3
#  define KERNEL 1
#  define SMOOTHEN 1
#  define SMOOTHEN_RAD 8
#  define SMOOTHEN_THR 250
#  define SIZESMOOTH 0
#  define SIZEPIXZ 333.0
#  define PREFAC_RAD_CC 1.0
// DATASET 6 (LS_2 in ISBI contest)
#elif DATASET == 6
#  define PIXMEAN 5400
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 12 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define NBMESX 128
#  define NBMESY 128
#  define SIZEPIX 150.0
#  define SIZEZ 1
#  define DAMP1 0.01
#  define DAMP2 0.02
#  define NOISEBACK 4000
#  define MEANBACK 140
#  define AINITPFACT 10.0
#  define NBITER 5000
#  define THRPOINT 1000
#  define BETA 2.5 /* inverse temperature for inference */
#  define PIXTHR 150
#  define THRCONV 1e-3
#  define KERNEL 2
#  define SMOOTHEN 1
#  define SIZESMOOTH 0
#  define SMOOTHEN_RAD 8
#  define SMOOTHEN_THR 400
#  define GIBSSIZE 257
#  define SIZEPIXZ 333.0
#  define PREFAC_RAD_CC 1.0
// DATASET 7 (LS_3 in ISBI contest)
#elif DATASET == 7
#  define PIXMEAN 1600
#  define PIXSTD 200
#  define RHO 0.001
#  define SKER 20 /* has to be a multiple of 4 to use sse */
#  define SMES 4
#  define NBMESX 200
#  define NBMESY 200
#  define SIZEPIX 100.0
#  define SIZEPIXZ 333.0
#  define DAMP1 0.01
#  define DAMP2 0.02
#  define NOISEBACK 22.0
#  define MEANBACK 108.0
#  define AINITPFACT 10.0
#  define NBITER 4000
#  define THRPOINT 450
#  define BETA 3.5 /* inverse temperature for inference */
#  define PIXTHR 9
#  define THRCONV 1e-3
#  define KERNEL 2
#  define SMOOTHEN 1
#  define SMOOTHEN_RAD 18
#  define SMOOTHEN_THR 40
#  define SIZESMOOTH 0
#  define GIBSSIZE 129
#  define GIBSFRAME 0
#  define SIZEZ 4
#  define PREFAC_RAD_CC 2.0
// DATASET 10 (Clathrin coated pits)
#elif DATASET == 10
#  define PIXMEAN 3000
#  define PIXSTD 1000
#  define RHO 0.001
#  define SKER 8 /* has to be a multiple of 4 to use sse */
#  define SMES 8
#  define NBMESX 199
#  define NBMESY 329
#  define SIZEPIX 133.0
#  define SIZEPIXZ 333.0
#  define DAMP 0.1
#  define NOISEBACK 80.0
#  define MEANBACK 85.0
#  define AINITPFACT 1.0
#  define NBITER 5000
#  define THRPOINT 1000
#  define BETA 1 /* inverse temperature for inference */
#  define PIXTHR 50
#  define THRCONV 1e-3
#  define KERNEL 3
#  define SIGPSF 1.04
#  define KERC2 -1.146e-01
#  define KERC4 -1.502e-02
#  define KERC6 1.417e-02
#  define KERC8 4.033e-03
#  define KERC10 -7.628e-04
#  define DEFOCUS 1.0 /* the 1.1 is for defocus */
#  define SIZESMOOTH 0
#  define SIZEZ 1
#  define RESCALEINPUT
#  define RESCALEOFFSET 300
#  define RESCALESLOPE 18.8
#  endif

#endif /* end of include guard: PARAMETERS_H */
