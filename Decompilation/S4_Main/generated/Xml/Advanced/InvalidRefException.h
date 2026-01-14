#ifndef ADVXMLPARSER_INVALIDREFEXCEPTION_H
#define ADVXMLPARSER_INVALIDREFEXCEPTION_H

namespace AdvXMLParser {

class InvalidRefException {
public:
    // address=[0x2f17460]
     InvalidRefException(std::string const &);

    // address=[0x2f1c6d0]
     InvalidRefException(class AdvXMLParser::InvalidRefException const &);

    // address=[0x2f1cde0]
    virtual  ~InvalidRefException(void);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_INVALIDREFEXCEPTION_H
