#include <iconv.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <map>
#include <stdexcept>
#include <sstream>

class CharsetConvertor {
public:
    CharsetConvertor(const std::string &fromCharset, const std::string &toCharset, size_t outputBufferSize = DEFAULT_BUFFER_SIZE);
    virtual ~CharsetConvertor();

    void setOutputBufferSize(size_t buffer);
    size_t getOutputBufferSize() const;

    std::string convert(const std::string &input);

    static const size_t DEFAULT_BUFFER_SIZE;
    static const char*  CHARSET_UNICODE;
    static const char*  CHARSET_GBK;
    static const char*  CHARSET_UTF8;
private:
    CharsetConvertor(const CharsetConvertor&);
    CharsetConvertor &operator =(const CharsetConvertor&);

    iconv_t     _conv;
    size_t      _nOutBufferSize;
    std::string _sFromCharset;
    std::string _sToCharset;
    char*       _szOutStr;
};


class FlyWeight {
public:
    static CharsetConvertor *getCharsetConvertor(const std::string &fromCharset, const std::string &toCharset);
private:
    static std::map<std::string, CharsetConvertor *> convertorMap;
};

