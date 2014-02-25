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

    // get handler from FlyWeight to reuse the handler;
    CharsetConvertor *conv1 = FlyWeight::getCharsetConvertor(CharsetConvertor::CHARSET_GBK, CharsetConvertor::CHARSET_UTF8);
    CharsetConvertor *conv2 = FlyWeight::getCharsetConvertor(CharsetConvertor::CHARSET_UTF8, CharsetConvertor::CHARSET_GBK);
    std::string str1 = conv1->convert("中华人民共和国");
    std::string str2 = conv2->convert(str1);
    if (str2.compare("中华人民共和国") != 0) {
        std::cerr << "ERROR in line:" << __LINE__ << std::endl;
        std::cout << "str1 " << str1 << std::endl;
        std::cout << "str2 " << str2 << std::endl;
        return 1;
    } else {
        std::cout << "EXPECT EQUAL [PASS]" << std::endl;
    }
    return 0;
}
