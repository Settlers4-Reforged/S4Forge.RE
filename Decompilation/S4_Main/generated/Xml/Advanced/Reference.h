#ifndef ADVXMLPARSER_REFERENCE_H
#define ADVXMLPARSER_REFERENCE_H

#include "defines.h"

namespace AdvXMLParser {

class Reference {
public:
    // address=[0x2f14bc0]
     Reference(class AdvXMLParser::NodeContainer & a2, std::string const & a3);

    // address=[0x2f14bf0]
    virtual bool  IsKindOf(int a2)const;

    // address=[0x2f1ce40]
    virtual  ~Reference(void);

    // address=[0x2f23940]
    static class AdvXMLParser::Reference * __cdecl Parse(class AdvXMLParser::Parser & a1, class AdvXMLParser::NodeContainer & a2);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_REFERENCE_H
