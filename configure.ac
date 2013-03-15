AC_INIT([Brecs],
        m4_esyscmd([tools/git-version-gen .tarball-version]),
        [rouaulth@janelia.hhmi.org])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CC_C99

AC_CHECK_LIB([m],[cos])
AC_CHECK_LIB([bz2],[BZ2_bzWriteOpen])

# Checks for libraries with pkg-config
PKG_CHECK_MODULES(LIBPNG, libpng, [], [AC_MSG_ERROR([libpng library required.])])
PKG_CHECK_MODULES(LIBTIFF, libtiff-4, [], [AC_MSG_ERROR([libtiff library required.])])
PKG_CHECK_MODULES(FFTWF, fftw3f, [], [AC_MSG_ERROR([fftw3f library required.])])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
                 Makefile
                 src/Makefile
                 ])
AC_OUTPUT
