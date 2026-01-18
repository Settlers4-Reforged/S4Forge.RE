#ifndef ADVXMLPARSER_INVALIDREFEXCEPTION_H
#define ADVXMLPARSER_INVALIDREFEXCEPTION_H

#include "defines.h"

namespace AdvXMLParser {

class InvalidRefException {
public:
    // address=[0x2f17460]
     InvalidRefException(std::string const & a2);

    // address=[0x2f1c6d0]
     InvalidRefException(class AdvXMLParser::InvalidRefException const & a2);

    // address=[0x2f1cde0]
    virtual  ~InvalidRefException(void);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_INVALIDREFEXCEPTION_H
