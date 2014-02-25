#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#AC_PREREQ([2.68])
AC_INIT([iconv-cpp], [1.0.1], [jianqiang070@foxmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([include/iconv.hpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([memset strerror])
AM_CONDITIONAL(IS_AIX, test `uname -s` = "AIX")

AC_CONFIG_FILES([Makefile
                 example/Makefile
                 include/Makefile
                 src/Makefile])
AC_OUTPUT
