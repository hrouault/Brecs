Overview
========

*B-recs* is a software able to reconstruct superresolution images at
intermediate densities of active fluorophores. Active fluorophores must be
sparse but their response on the camera can overlap. The theoretical limit for
accurate reconstruction is one fluorophore per pixel on the camera, at higher
densities, the accuracy quickly drops.

It is programmed in C, accompanied by a *Image J / Fiji* plugin.

Installation
============

*B-recs* uses *cmake* for the build process. You can refer to the *cmake*
documentation for more details.

Required libraries
------------------

A few standard libraries are required:

* *libbz2*: each reconstructed image is stored as a raw image compressed with
  *Bzip2*.

* *libtiff*: input to *B-recs* are provided in the tiff format. Moreover,
  intermediate images can be produced in tiff format.

* *fftw3*: Fourier transforms are not used in the algorithms
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
cmake ..
make
make install
```

You should then be able to run `brecs-reconssparse --version`. For more
details, please refer to the documentation available
[here](http://rouaulth.bitbucket.org/brecs/).

License
=======

*B-recs* is distributed under a BSD license (see LICENSE file).
