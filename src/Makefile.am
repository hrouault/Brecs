# Copyright (c) , Herve Rouault <rouaulth@janelia.hhmi.org>,
# Howard Hughes Medical Institute.
# All rights reserved.
# 
# This file is part of Brecs.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Howard Hughes Medical Institute nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

dist_noinst_DATA = cmdline.ggo

cmdline.c: cmdline.ggo
	  gengetopt --input=$<

bin_PROGRAMS = Brecs gendat minproj genpsf measure_psf

Brecs_SOURCES = cmdline.c cmdline.h Brecs.c Brecs.h inoutimg.c inoutimg.h \
                parameters.h error.c error.h
Brecs_CPPFLAGS = $(LIBPNG_CFLAGS) $(LIBTIFF_CFLAGS) $(FFTWF_CFLAGS)
Brecs_LDADD = $(LIBPNG_LIBS) $(LIBTIFF_LIBS) $(FFTWF_LIBS)

gendat_SOURCES = gendat.c gendat.h parameters.h
gendat_CPPFLAGS = $(LIBTIFF_CFLAGS)
gendat_LDADD = $(LIBTIFF_LIBS)

minproj_SOURCES = minproj.c inoutimg.c inoutimg.h
minproj_CPPFLAGS = $(LIBPNG_CFLAGS) $(LIBTIFF_CFLAGS)
minproj_LDADD = $(LIBPNG_LIBS) $(LIBTIFF_LIBS)

genpsf_SOURCES = genpsf.c inoutimg.c inoutimg.h
genpsf_CPPFLAGS = $(LIBPNG_CFLAGS) $(LIBTIFF_CFLAGS)
genpsf_LDADD = $(LIBPNG_LIBS) $(LIBTIFF_LIBS)

measure_psf_SOURCES = measure_psf.c inoutimg.c inoutimg.h
measure_psf_CPPFLAGS = $(LIBPNG_CFLAGS) $(LIBTIFF_CFLAGS)
measure_psf_LDADD = $(LIBPNG_LIBS) $(LIBTIFF_LIBS)
