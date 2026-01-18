#ifndef ADVXMLPARSER_PARSER_H
#define ADVXMLPARSER_PARSER_H

#include "defines.h"

namespace AdvXMLParser {

class Parser {
public:
    // address=[0x2f26710]
     Parser(void);

    // address=[0x2f26750]
    virtual  ~Parser(void);

    // address=[0x2f26770]
    static char * __cdecl OpenXMLFile(wchar_t * FileName, long & a2);

    // address=[0x2f26860]
    class AdvXMLParser::Document *  Parse(char const * a2, int a3);

    // address=[0x2f268e0]
    void  SyntaxError(enum AdvXMLParser::PARSER_ERROR a2);

    // address=[0x2f26920]
    char  NextChar(void);

    // address=[0x2f269f0]
    void  PreviousChar(void);

    // address=[0x2f26af0]
    bool  ParseChar(char a2);

    // address=[0x2f26b20]
    bool  ParseString(char const * a2);

    // address=[0x2f26b80]
    bool  ParseStringNoCase(char const * a2);

    // address=[0x2f26c00]
    bool  ParseNumber(int & a2);

    // address=[0x2f26c80]
    bool  ParseHexNumber(int & a2);

    // address=[0x2f26d10]
    bool  ParseDeclBegining(char const * a2);

    // address=[0x2f26d80]
    bool  ParseSpaces(void);

    // address=[0x2f26df0]
    bool  ParseEq(void);

    // address=[0x2f26e40]
    bool  ParseName(std::string & a2);

    // address=[0x2f26ee0]
    bool  ParseNmtoken(std::string & a2);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_PARSER_H
