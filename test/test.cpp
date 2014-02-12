#include <iostream>
#include <iconv.hpp>

int main () {
    std::string out1;
    std::string out2;
    CharsetConvertor convt1(CharsetConvertor::CHARSET_GBK, CharsetConvertor::CHARSET_UNICODE);
    CharsetConvertor convt2(CharsetConvertor::CHARSET_UNICODE, CharsetConvertor::CHARSET_GBK);
    out1 = convt1.convert("中国1勃起");
    out2 = convt1.convert("毛mao邓deng三san");
    std::cout << out1 << "(" << out1.length() << ");" << out2 << "(" << out2.length() << ")" << std::endl;
    out1 = convt2.convert(out1);
    out2 = convt2.convert(out2);
    std::cout << out1 << "(" << out1.length() << ");" << out2 << "(" << out2.length() << ")" << std::endl;
}
