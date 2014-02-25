if IS_AIX
ICONV_LIB = -liconv
else
ICONV_LIB =
endif

noinst_PROGRAMS = test
TESTS = test

test_SOURCES = test.cpp
test_CPPFLAGS = -I$(top_srcdir)/include
test_LDADD = $(top_srcdir)/src/libiconvx.a $(ICONV_LIB)
