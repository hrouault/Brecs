AC_INIT([Brecs],
        m4_esyscmd([tools/git-version-gen .tarball-version]),
        [rouaulth@janelia.hhmi.org])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_MACRO_DIR([m4])
m4_include([m4/m4_ax_ext.m4])

AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CC_STDC

AS_IF([test x"$ac_cv_prog_cc_c99" = xno],
      AC_MSG_ERROR([C99 compliant compiler required.]))
#if test "x$ac_cv_prog_cc_c99" = xno ; then
#      AC_MSG_ERROR([C99 compliant compiler required.])
#fi


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
