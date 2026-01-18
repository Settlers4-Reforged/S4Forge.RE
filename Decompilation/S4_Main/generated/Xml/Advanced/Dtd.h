#ifndef ADVXMLPARSER_DTD_H
#define ADVXMLPARSER_DTD_H

#include "defines.h"

namespace AdvXMLParser {

class Dtd {
public:
    // address=[0x2f249c0]
     Dtd(class AdvXMLParser::Document & a2);

    // address=[0x2f249e0]
    bool  ParseDoctypedecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f24b50]
    bool  ParsePEReference(class AdvXMLParser::Parser & a2);

    // address=[0x2f24c00]
    bool  ParseSystemLiteral(class AdvXMLParser::Parser & a2);

    // address=[0x2f24c90]
    bool  ParsePubidLiteral(class AdvXMLParser::Parser & a2);

    // address=[0x2f24d20]
    bool  ParseMarkupdecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f24d90]
    bool  ParseElementDecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f24e90]
    bool  ParseContentspec(class AdvXMLParser::Parser & a2);

    // address=[0x2f24f00]
    bool  ParseMixed(class AdvXMLParser::Parser & a2);

    // address=[0x2f25050]
    bool  ParseChildren(class AdvXMLParser::Parser & a2);

    // address=[0x2f250b0]
    bool  ParseChoiceSeq(class AdvXMLParser::Parser & a2, bool & a3);

    // address=[0x2f251b0]
    bool  ParseCp(class AdvXMLParser::Parser & a2);

    // address=[0x2f25290]
    bool  ParseAttlistDecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f25380]
    bool  ParseAttDef(class AdvXMLParser::Parser & a2);

    // address=[0x2f25490]
    bool  ParseAttType(class AdvXMLParser::Parser & a2);

    // address=[0x2f25580]
    bool  ParseNotationType(class AdvXMLParser::Parser & a2);

    // address=[0x2f256d0]
    bool  ParseEnumeration(class AdvXMLParser::Parser & a2);

    // address=[0x2f25800]
    bool  ParseDefaultDecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f25920]
    bool  ParseEntityDecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f25aa0]
    bool  ParseEntityDef(class AdvXMLParser::Parser & a2);

    // address=[0x2f25af0]
    bool  ParseNDataDecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f25bd0]
    bool  ParsePEDef(class AdvXMLParser::Parser & a2);

    // address=[0x2f25c20]
    bool  ParseEntityValue(class AdvXMLParser::Parser & a2);

    // address=[0x2f25d80]
    bool  ParseNotationDecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f25ea0]
    bool  ParseExternalID(class AdvXMLParser::Parser & a2);

    // address=[0x2f25f60]
    bool  ParsePublicID(class AdvXMLParser::Parser & a2);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_DTD_H
