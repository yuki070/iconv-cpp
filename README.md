iconv-cpp
=========

Encapsulate the 'iconv' with cpp

#### linux:
> ./configure
>
> make
>
> make install

#### aix64:
> export OBJECT_MODE=64
>
> ./configure CXX="xlC_r -qchars=signed -qcompact" LDFLAGS="-q64 -brtl -bhalt:5" CXXFLAGS="-O2"
>
> make
>
> make install
