AC_INIT([Bstorm],
        m4_esyscmd([tools/git-version-gen .tarball-version]),
        [rouaulth@janelia.hhmi.org])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CC_C99
AM_PROG_CC_C_O

# Checks for libraries with pkg-config
PKG_CHECK_MODULES(LIBPNG, libpng, [], [AC_MSG_ERROR([libpng library required.])])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
                 Makefile
                 src/Makefile
                 ])
AC_OUTPUT
