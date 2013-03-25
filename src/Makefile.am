bin_PROGRAMS = Brecs binary

Brecs_SOURCES = Brecs.c Brecs.h parameters.h cmdline.c cmdline.h
Brecs_CPPFLAGS = $(LIBPNG_CFLAGS) $(LIBTIFF_CFLAGS) $(FFTWF_CFLAGS)
Brecs_LDADD = $(LIBPNG_LIBS) $(LIBTIFF_LIBS) $(FFTWF_LIBS)

binary_SOURCES = binary.c
binary_CPPFLAGS = $(LIBPNG_CFLAGS)
binary_LDADD = $(LIBPNG_LIBS)
