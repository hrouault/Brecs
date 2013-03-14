bin_PROGRAMS = Bstorm Bstorm3d

Bstorm_SOURCES = Bstorm.c Bstorm.h cmdline.c cmdline.h
Bstorm_CPPFLAGS = $(LIBPNG_CFLAGS) $(LIBTIFF_CFLAGS) $(FFTWF_CFLAGS)
Bstorm_CFLAGS = -msse3
Bstorm_LDADD = $(LIBPNG_LIBS) $(LIBTIFF_LIBS) $(FFTWF_LIBS)

Bstorm3d_SOURCES = Bstorm3d.c Bstorm.h cmdline.c cmdline.h
Bstorm3d_CPPFLAGS = $(LIBPNG_CFLAGS) $(LIBTIFF_CFLAGS) $(FFTWF_CFLAGS)
Bstorm3d_CFLAGS = -msse3
Bstorm3d_LDADD = $(LIBPNG_LIBS) $(LIBTIFF_LIBS) $(FFTWF_LIBS)
