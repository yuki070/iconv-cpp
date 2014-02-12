#include <iconv.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <stdexcept>

class CharsetConvertor {
public:
    CharsetConvertor(const std::string &fromCharset, const std::string &toCharset) {
        this->fromCharset = fromCharset;
        this->toCharset = toCharset;
        outputBufferSize = DEFAULT_BUFFER_SIZE;
        conv = iconv_open(toCharset.c_str(), fromCharset.c_str());
        if (conv == (iconv_t) -1) {
            throw std::runtime_error(strerror(errno));
        }
    }

    virtual ~CharsetConvertor() {
        iconv_close(conv);
    }

    void setOutputBufferSize(size_t buffer) {
        this->outputBufferSize = buffer;
    }

    size_t getOutputBufferSize() const {
        return this->outputBufferSize;
    }

    std::string convert(const std::string &input) {
        const char *inStr = input.c_str();
        char *pIn = const_cast<char *>(inStr);
        size_t inLen = input.length();

        char *outStr = new char[outputBufferSize];
        memset(outStr, 0, outputBufferSize);
        char *pOut = outStr;
        size_t outLen = outputBufferSize;

        size_t ret = iconv(conv, &pIn, &inLen, &pOut, &outLen);
        if (ret == -1) {
            throw std::runtime_error(strerror(errno));
        }
        std::string output;
#ifndef _AIX
        if (toCharset.compare(CHARSET_UNICODE) == 0) {
            output = std::string(outStr + 2, outStr + (outputBufferSize - outLen));
        }
#endif
        output = std::string(outStr, outStr + (outputBufferSize - outLen));
        delete []outStr;
        return output;
    }

    static const size_t DEFAULT_BUFFER_SIZE;
    static const char *CHARSET_UNICODE;
    static const char *CHARSET_GBK;
    static const char *CHARSET_UTF8;
private:
    iconv_t conv;
    size_t outputBufferSize;
    std::string fromCharset;
    std::string toCharset;
};

const size_t CharsetConvertor::DEFAULT_BUFFER_SIZE = 1024;
const char *CharsetConvertor::CHARSET_UNICODE = "unicode";
const char *CharsetConvertor::CHARSET_GBK = "GBK";
const char *CharsetConvertor::CHARSET_UTF8 = "UTF-8";

