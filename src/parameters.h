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

/* General parameters for display */
#define DISPLAY_OVERLAY_ITER 0
#define DISPLAY_OVERLAY 1
#define DISPLAY_PLOTS 1
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
#  define PIXMEAN 2000
#  define PIXSTD 500
#  define RHO 0.001
#  define SKER 20 /* has to be a multiple of 4 to use sse */
#  define SMES 2
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
#  define PIXTHR 5
#  define THRCONV 1e-3
#  define KERNEL 2
#  define SMOOTHEN 1
#  define SMOOTHEN_RAD 25
#  define SMOOTHEN_THR 40
#  define SIZESMOOTH 100
#  define GIBSSIZE 129
#  define GIBSFRAME 0
#  define SIZEZ 6
#  define PREFAC_RAD_CC 1.5
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
// DATASET 11 (microtubule 3d)
#elif DATASET == 11
#  define PIXMEAN 3000
#  define PIXSTD 1000
#  define RHO 0.001
#  define SKER 8 /* has to be a multiple of 4 to use sse */
#  define SMES 6
#  define NBMESX 128
#  define NBMESY 128
#  define NBMESXINI 210
#  define NBMESYINI 416
#  define OFFXINI 0
#  define OFFYINI 0
#  define SIZEPIX 133.0
#  define SIZEPIXZ 333.0
#  define DAMP1 0.05
#  define DAMP2 0.1
#  define NOISEBACK 80.0
#  define MEANBACK 85.0
#  define AINITPFACT 1.0
#  define NBITER 1500
#  define THRPOINT 500
#  define BETA 1 /* inverse temperature for inference */
#  define PIXTHR 50
#  define THRCONV 1e-3
#  define KERNEL 1
#  define SIGPSF 1.04
#  define DEFOCUS 1.0 /* the 1.1 is for defocus */
#  define SIZESMOOTH 0
#  define SIZEZ 1
#  define RESCALEINPUT
#  define RESCALEOFFSET 300
#  define RESCALESLOPE 19.23
#  define PREFAC_RAD_CC 1.0
// DATASET 101 (tubulin 002 on the MFM)
#elif DATASET == 101
#  define BRECS_PIXMEAN 200
#  define BRECS_PIXSTD 80
#  define BRECS_RHO 0.001
#  define BRECS_DAMP1 0.05
#  define BRECS_DAMP2 0.1
#  define BRECS_NBITER 400
#  define BRECS_MESAMPLI 16.69
#  define BRECS_MESOFFSET 100
#  define BRECS_MEANBACK 0.0
#  define BRECS_NOISEOFFSET 0.0
#  define BRECS_CONVOLPIXTHR 8.0
#  define BRECS_LOCAINTENSTHR 100
#  define BRECS_OVERLAYMAXINT 100
#  define BRECS_OVERLAYMININT 0.1
// DATASET 110 (PolII Eos dataset)
#elif DATASET == 110
#  define BRECS_PIXMEAN 50
#  define BRECS_PIXSTD 20
#  define BRECS_KERSIZEZ 1
#  define BRECS_PIXSDIVZ 1
#  define BRECS_MESOFFSET 100
#  define BRECS_MESAMPLI 61.22
#  define BRECS_NBITER 500
#  define BRECS_CONVOLPIXTHR 1.8
#  define BRECS_LOCAINTENSTHR 10
#  define BRECS_OVERLAYMAXINT 3
#  define BRECS_OVERLAYMININT 0.1
#elif DATASET == 111
#  define BRECS_PIXMEAN 50
#  define BRECS_PIXSTD 20
#  define BRECS_KERSIZEZ 1
#  define BRECS_PIXSDIVZ 1
#  define BRECS_MESOFFSET 100
#  define BRECS_MESAMPLI 61.22
#  define BRECS_NBITER 500
#  define BRECS_CONVOLPIXTHR 2.4
#  define BRECS_LOCAINTENSTHR 10
#  define BRECS_OVERLAYMAXINT 3
#  define BRECS_OVERLAYMININT 0.1
#elif DATASET == 120 // Wes dataset (astigm psf)
#  define BRECS_PIXMEAN 50
#  define BRECS_PIXSTD 20
#  define BRECS_KERSIZE 16
#  define BRECS_PIXSDIV 4
#  define BRECS_KERSIZEZ 1
#  define BRECS_PIXSDIVZ 11
#  define BRECS_MESOFFSET 100
#  define BRECS_MESAMPLI 61.22
#  define BRECS_NBITER 500
#  define BRECS_CONVOLPIXTHR 0.4
#  define BRECS_LOCAINTENSTHR 10
#  define BRECS_OVERLAYMAXINT 3
#  define BRECS_OVERLAYMININT 0.1
#elif DATASET == 200 // Tim's FISH
#  define BRECS_PIXMEAN 2000
#  define BRECS_PIXSTD 1000
#  define BRECS_KERSIZE 16
#  define BRECS_PIXSDIV 2
#  define BRECS_KERSIZEZ 10
#  define BRECS_PIXSDIVZ 1
#  define BRECS_MESOFFSET 100
#  define BRECS_NOISEOFFSET 150
#  define BRECS_MEANBACK 10
#  define BRECS_MESAMPLI 10.00
#  define BRECS_NBITER 10
#  define BRECS_DAMP1 0.005
#  define BRECS_DAMP2 0.01
#  define BRECS_CONVOLPIXTHR 7.0
#  define BRECS_LOCAINTENSTHR 10
#  define BRECS_OVERLAYMAXINT 2000
#  define BRECS_OVERLAYMININT 5
#elif DATASET == 201 // Tim's FISH S2 cells
#  define BRECS_PIXMEAN 1000
#  define BRECS_PIXSTD 500
#  define BRECS_KERSIZE 16
#  define BRECS_PIXSDIV 2
#  define BRECS_KERSIZEZ 10
#  define BRECS_PIXSDIVZ 1
#  define BRECS_MESOFFSET 100
#  define BRECS_NOISEOFFSET 1000
#  define BRECS_MEANBACK 25
#  define BRECS_MESAMPLI 40.00
#  define BRECS_NBITER 580
#  define BRECS_DAMP1 0.01
#  define BRECS_DAMP2 0.02
#  define BRECS_CONVOLPIXTHR 10.0
#  define BRECS_LOCAINTENSTHR 10
#  define BRECS_OVERLAYMAXINT 2000
#  define BRECS_OVERLAYMININT 5.0
#elif DATASET == 202 // Salina's FISH S2 cells
#  define BRECS_PIXMEAN 1000
#  define BRECS_PIXSTD 500
#  define BRECS_KERSIZE 16
#  define BRECS_PIXSDIV 2
#  define BRECS_KERSIZEZ 10
#  define BRECS_PIXSDIVZ 1
#  define BRECS_MESOFFSET 0
#  define BRECS_NOISEOFFSET 1000
#  define BRECS_MEANBACK 60
#  define BRECS_MESAMPLI 5.00
#  define BRECS_NBITER 800
#  define BRECS_DAMP1 0.02
#  define BRECS_DAMP2 0.04
#  define BRECS_CONVOLPIXTHR 8.0
#  define BRECS_LOCAINTENSTHR 10
#  define BRECS_OVERLAYMAXINT 2000
#  define BRECS_OVERLAYMININT 40.0
#elif DATASET == 400 // Test for brecs port
#  define BRECS_PIXMEAN 5000
#  define BRECS_PIXSTD 500
#  define BRECS_KERSIZE 16
#  define BRECS_PIXSDIV 8
#  define BRECS_MESOFFSET 0
#  define BRECS_NOISEOFFSET 1000
#  define BRECS_MEANBACK 200
#  define BRECS_MESAMPLI 1.00
#  define BRECS_NBITER 1000
#  define BRECS_DAMP1 0.01
#  define BRECS_DAMP2 0.02
#  define BRECS_CONVOLPIXTHR 200.0
#  define BRECS_LOCAINTENSTHR 100
#  define BRECS_OVERLAYMAXINT 2000
#  define BRECS_OVERLAYMININT 40.0
#  endif

/* Parameters for the generation of the artificial datasets */
#define GENDAT_SIZEX 64
#define GENDAT_SIZEY 64
#define GENDAT_SIZEZ 16
#define GENDAT_NBPOINTS 100

#endif /* end of include guard: PARAMETERS_H */
