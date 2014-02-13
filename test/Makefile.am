if IS_AIX
ICONV_LIB = -liconv
else
ICONV_LIB =
endif

GTEST_FILES = gtest/gtest-all.cc \
gtest/gtest.h \
gtest/gtest_main.cc

LIBS = -lpthread 

noinst_LIBRARIES = libgtest.a
libgtest_a_SOURCES = $(GTEST_FILES)


noinst_PROGRAMS = test
TESTS = $(noinst_PROGRAMS)

test_SOURCES = test.cpp
test_CPPFLAGS = -I$(top_srcdir)/include -I$(BIPROG_ROOT)/include
test_LDFLAGS = -L$(BIPROG_ROOT)/lib
test_LDADD = libgtest.a $(ICONV_LIB)
