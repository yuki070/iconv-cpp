#include <iconv.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <stdexcept>

static const size_t OUT_BUF_SIZE = 1024;

class CharsetConvertor {
public:
    CharsetConvertor(const std::string &fromCharset, const std::string &toCharset) :
        conv((iconv_t)-1), fromCharset(fromCharset), toCharset(toCharset) {
        conv = iconv_open(toCharset.c_str(), fromCharset.c_str());
        if (conv == (iconv_t) -1) {
            throw std::runtime_error(strerror(errno));
        }
    }

    virtual ~CharsetConvertor() {
        iconv_close(conv);
    }

    std::string convert(const std::string &input) {
        const char *inStr = input.c_str();
        size_t inLen = input.length();

        char outStr[OUT_BUF_SIZE];
        memset(outStr, 0, OUT_BUF_SIZE);
        char *poutStr = outStr;
        size_t outLen = OUT_BUF_SIZE;

        size_t ret = iconv(conv, (char **)&inStr, &inLen, &poutStr, &outLen);
        if (ret == -1) {
            throw std::runtime_error(strerror(errno));
        }
        std::string output;
#ifndef _AIX
        if (toCharset.compare(CHARSET_UNICODE) == 0) {
            output = std::string(outStr + 2, outStr + (OUT_BUF_SIZE - outLen));
        }
#endif
        output = std::string(outStr, outStr + (OUT_BUF_SIZE - outLen));
        return output;
    }

    static const char *CHARSET_UNICODE;
    static const char *CHARSET_GBK;
private:

    iconv_t conv;
    std::string fromCharset;
    std::string toCharset;
};

const char *CharsetConvertor::CHARSET_UNICODE = "unicode";
const char *CharsetConvertor::CHARSET_GBK = "GBK";

