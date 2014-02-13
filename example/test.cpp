#include <iostream>
#include <string>
#include <iconv.hpp>

int main () {
    CharsetConvertor gbk2uni(CharsetConvertor::CHARSET_GBK, CharsetConvertor::CHARSET_UNICODE);
    CharsetConvertor uni2gbk(CharsetConvertor::CHARSET_UNICODE, CharsetConvertor::CHARSET_GBK);
    std::string uni = gbk2uni.convert("中华人民共和国");
    std::string gbk = uni2gbk.convert(uni);
    if (gbk.compare("中华人民共和国") != 0) {
        std::cerr << "ERROR in line:" << __LINE__ << std::endl;
        return 1;
    } else {
        std::cout << "EXPECT EQUAL [PASS]" << std::endl;
    }

    try {
        gbk2uni.setOutputBufferSize(4);
        gbk2uni.convert("hello");   // overflow
    } catch (...) {
        std::cout << "EXPECT THROW [PASS]" << std::endl;
    }
    return 0;
}
