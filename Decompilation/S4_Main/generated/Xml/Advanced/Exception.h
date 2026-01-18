#ifndef ADVXMLPARSER_EXCEPTION_H
#define ADVXMLPARSER_EXCEPTION_H

#include "defines.h"

namespace AdvXMLParser {

class Exception {
public:
    // address=[0x2f17420]
     Exception(void);

    // address=[0x2f17440]
    virtual  ~Exception(void);

    // address=[0x2f1c6b0]
     Exception(class AdvXMLParser::Exception const & a2);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_EXCEPTION_H
