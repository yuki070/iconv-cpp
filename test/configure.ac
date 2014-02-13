#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#AC_PREREQ([2.68])
AC_INIT([test], [1.0.0], [])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([test.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.
AC_CHECK_LIB([pthread], [main])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h limits.h netdb.h stddef.h stdlib.h string.h strings.h sys/time.h sys/timeb.h unistd.h wchar.h wctype.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_PID_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_STRERROR_R
AC_CHECK_FUNCS([dup2 getcwd getpagesize gettimeofday isascii memset mkdir munmap regcomp rmdir socket strcasecmp strchr strdup strerror strrchr strstr strtol strtoull])
AM_CONDITIONAL(IS_AIX, test `uname -s` = "AIX")

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
