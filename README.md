Overview
========

**Brecs** is a software able to reconstruct superresolution images at
intermediate densities of active fluorophores. Active fluorophores must be
sparse but their response on the camera can overlap. The theoretical limit for
accurate reconstruction is one fluorophore per pixel on the camera, at higher
densities, the acuracy quickly drops.

It is programmed in C, accompanied by a bunch of scripts in `/tools`.

Installation
============

You can refer to the INSTALL file for detailled installation instructions. It
basically follows the usual unix installation process (i.e. `configure`,
`make`, `make install`).

Required libraries
------------------

A few standard libraries are required:
* `libbz2`: each reconstructed image is stored as a raw image compressed with
  *Bzip2*.
* `libpng`: intermediate images can be produced in png format. This
  is mainly for debugging purpose.  `libtiff`: *Brecs* accepts input in tiff or
  raw format.
* `fftw3`: Fourier transforms are not used in the algorithms
  itself but is used in the case of strong autofluorescence to have a local
  estimate of the noise and background level.

SIMD support
------------

In its present state, the program requires a modern cpu and compiler. More
specifically, it uses SSE3 or AVX intrinsics. It means that the compiler should
be able to understand them and the cpu support these instructions. I might
implement a non-SIMD version at some point but I don't plan to do it yet.

Quick install
-------------

```sh
mkdir build
cd build
CPPFLAGS="-DDATASET=nbdata"; CFLAGS="-O3 -mtune=native"; ../configure
make
make install
```

You should then be able to run `Brecs --version`. You can also adapt the place
where the program is install by adjusting the prefix (`../configure --prefix
/rep/install`.


Parameters
==========

Parameters are hard-coded for efficiency purpose. They are present in the file
`src/parameters.h`. As soon as you want to use *Brecs* with a new
dataset/exprimental conditions, this file should be modified and the program
recompiled with the right DATASET number.


Prior
-----
For the moment the prior on the intensity distribution of a fluorophore is
gaussian:
Psi(I) = (1 - RHO) delta(I) + RHO * Gauss(PIXMEAN, PIXSTD)
where:
RHO: density of fluorophores
PIXMEAN: mean number of photons emitted by a fluorophore
PIXSTD: standard deviation of this number of photons

Pixel sizes
-----------
In general, I call pixel, a physical pixel measured by the camera and
superpixel, a unit pixel on the superresolved image computed by the program.
A florophore emits photons on a localized region of size SKER * SKER on the
camera.
The program builds an image with a pixel size smaller than the pixelsize of
the camera. Specifically, for one pixel on the camera, the program extracts
SMES * SMES superpixels.
The input images have size NBMESX * NBMESY pixels.
The physical size of a pixel is SIZEPIX.
When MODE3D is defined, the program will also try to extract the position in
z, the length separating two slices of the extracted stack is SIZEPIXZ.

Internals of the program
------------------------
The help the algorithm to converge, the update of positions is dampended.
This is the "dirty" side of the algorithm and has to be adjusted by trial
and error.
DAMP is the amount of the relative intensity change (I usually use 0.1, but
it should be lowered when the program fails to converge).

Usually the program do not converge fully because of numerical errors. I them
usually limit the total number of iteration (NBITER) which should be around
500. Otherwise it converges when the maximal relative change falls below
THRCONV between two iterations.

The variance of on the intensity of each superpixel is initialized high to that
the program is aware that a high intensity stat exists. This variance is
adjusted through AINITFACT.

The vary the estimator of the superpixel intensity, one can vary the
*temperature* of the Boltzmann weights BETA (1 / T).


Statistics of the background
----------------------------
The noise of the pixel can be adjusted in several ways, then simplest is to
assume uniform noise of variance NOISEBACK and uniform background level
MEANBACK.

When the noise in non-uniform, it is estimated locally when specifying
SMOOTHEN=1 in which case the noise is averaged on a zone of radius SIZESMOOTH.

In order to speed up the algorithm and optimized the amount of required memory,
only the superpixels on top of a pixel of sufficient intensity PIXTHR are
considered.

PSF
---
The PSF can be chosen gaussian with KERNEL=1 or arbitrary with KERNEL=2 for
a supplied PSF image file (see Brecs options) with each plan of size GIBSSIZE
* GIBSSIZE. In 2d mode, the plane of the PSF used for the kernel is GIBSFRAME.

In 3d mode, SIZEZ planes are considered in the PSF file.

Fluorophore localization mode
-----------------------------
When the output is a list of localization of fluorophore, THRPOINT is the
minimal intensity of a fluorophore to be considered.

License
=======
*Brecs* is distributed under a BSD license (see COPYING file).
