#include "iconv.hpp"

const size_t CharsetConvertor::DEFAULT_BUFFER_SIZE = 1024;
const char*  CharsetConvertor::CHARSET_UNICODE = "unicode";
const char*  CharsetConvertor::CHARSET_GBK = "GBK";
const char*  CharsetConvertor::CHARSET_UTF8 = "UTF-8";

CharsetConvertor::CharsetConvertor(const std::string &fromCharset, const std::string &toCharset, size_t outputBufferSize):
    _sFromCharset(fromCharset),
    _sToCharset(toCharset),
    _nOutBufferSize(outputBufferSize) {
    _szOutStr = new char[_nOutBufferSize];
    _conv = iconv_open(_sToCharset.c_str(), _sFromCharset.c_str());
    if (_conv == (iconv_t) -1) {
        throw std::runtime_error(strerror(errno));
    }
}

CharsetConvertor::~CharsetConvertor() {
    if (_szOutStr) {
        delete []_szOutStr;
    }
    iconv_close(_conv);
}

void CharsetConvertor::setOutputBufferSize(size_t buffer) {
    _nOutBufferSize = buffer;
    if (_szOutStr) {
        delete []_szOutStr;
    }
    _szOutStr = new char[_nOutBufferSize];
}

size_t CharsetConvertor::getOutputBufferSize() const {
    return _nOutBufferSize;
}

std::string CharsetConvertor::convert(const std::string &input) {
    const char *inStr = input.c_str();
    char *pIn = const_cast<char *>(inStr);
    size_t inLen = input.length();

    memset(_szOutStr, 0, _nOutBufferSize);
    char *pOut = _szOutStr;
    size_t outLen = _nOutBufferSize;

    size_t ret = iconv(_conv, &pIn, &inLen, &pOut, &outLen);
    if (ret == -1) {
        throw std::runtime_error(strerror(errno));
    }
    std::string output;
#ifdef _AIX
    if (_sToCharset.compare(CHARSET_UNICODE) == 0) {
        output = std::string(_szOutStr + 2, _szOutStr + (_nOutBufferSize - outLen));
    }
#endif
    output = std::string(_szOutStr, _szOutStr + (_nOutBufferSize - outLen));
    return output;
}



std::map<std::string, CharsetConvertor *> FlyWeight::convertorMap;

CharsetConvertor *FlyWeight::getCharsetConvertor(const std::string &fromCharset, const std::string &toCharset) {
    std::ostringstream indexStream;
    indexStream << fromCharset << "_" << toCharset;
    if (convertorMap.find(indexStream.str()) == convertorMap.end()){
        convertorMap.insert(std::pair<std::string, CharsetConvertor *>(indexStream.str(), new CharsetConvertor(fromCharset, toCharset)));
    }
    return convertorMap[indexStream.str()];
}
