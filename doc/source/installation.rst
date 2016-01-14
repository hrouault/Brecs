Installation
============

Again, two options are offered. One can first download a compiled version of
the *Fiji* plugin and try out *B-recs* in a minute. In that case, you simply
need to put the provided ``.jar`` file in the `Plugin` folder of your
*Fiji / Image J* package. The second option is to compile yourself *B-recs*.
This is a more difficult task although scripts are provided to ease the
process. The major advantage of the second option is that you can then run
*B-recs* from the command line and the code is optimized for your system: it
allows optimal performances (see also code implementation)..

Requirements
------------

A few standard libraries are required:

* `cmake`: Building tool for the package

* `libbz2`: each reconstructed image is stored as a raw image compressed with
  *Bzip2* (when asked on the command line).

* `libtiff`: *Brecs* accepts input in tiff or raw format. All the results are
  output in the tiff format.

* `fftw3`: Fourier transforms are not used in the algorithms
  itself but only in the preprocessing of the datasets, in order to define
  regions of interests whereby the algorithm is applied.

* `JNI`: This is used in order to compile the java plugin.

* `Sphinx`: this is the format of the present documentation. You need this
  library to generate the documentation


Quick install
-------------

.. code-block:: sh

    mkdir build
    cd build
    cmake .. -DCMAKE_C_FLAGS_RELEASE="-O3 -march=native -mtune=native"
    make
    make install

You should then be able to run ``brecs-reconssparse --version``. You can also
adapt the place where the program is install by adjusting the prefix:

.. code-block:: sh

   cmake -DCMAKE_INSTALL_PREFIX:PATH=/install/folder ..

Mac OS X
--------

A homebrew formula is provided in order to ease the process. Start by
installing Homebrew_. Place the file ``packages/brecs.rb`` from the *B-recs*
repository in the Formula folder, usually ``/usr/local/Library/Formula``
Then, simply execute ``brew install brecs``.
You should then be able to run the command line version of *B-recs*
``brecs-reconssparse``.

Development version
-------------------

If you use the development version available on bitbucket, the install process
is very similar. Refer to the `cmake` documentation for more details.

.. _Homebrew : http://brew.sh/
