iconv-cpp
=========

Encapsulate the 'iconv' with cpp

### INSTALL
#### linux:
> ./configure
>
> make check
>
> make install

#### aix64:
> export OBJECT_MODE=64
>
> ./configure CXX="xlC_r -qchars=signed -qcompact" LDFLAGS="-q64 -brtl -bhalt:5" CXXFLAGS="-O2"
>
> make check
>
> make install

### EXAMPLE
    #include <iconv.hpp>
    #include <string>
    
    int main () {
        CharsetConvertor convt(CharsetConvertor::CHARSET_GBK, CharsetConvertor::CHARSET_UNICODE);
        std::string uniStr = convt1.convert("今天,天气号晴朗!");
    }
