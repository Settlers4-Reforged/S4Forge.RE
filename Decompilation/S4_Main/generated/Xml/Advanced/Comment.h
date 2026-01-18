#ifndef ADVXMLPARSER_COMMENT_H
#define ADVXMLPARSER_COMMENT_H

#include "defines.h"

namespace AdvXMLParser {

class Comment {
public:
    // address=[0x2f16690]
     Comment(std::string const & a2);

    // address=[0x2f16730]
     Comment(class AdvXMLParser::NodeContainer & a2, std::string const & a3);

    // address=[0x2f167d0]
    class AdvXMLParser::Comment *  Clone(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f168b0]
    virtual std::string  GetData(void a2)const;

    // address=[0x2f168f0]
    virtual std::string  GetValue(void a2)const;

    // address=[0x2f16930]
    virtual bool  IsKindOf(int a2)const;

    // address=[0x2f16960]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f1cd50]
    virtual  ~Comment(void);

    // address=[0x2f24560]
    static class AdvXMLParser::Comment * __cdecl Parse(class AdvXMLParser::Parser & a1, class AdvXMLParser::NodeContainer & a2);

    // address=[0x2f2d190]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext & a2)const;

    // address=[0x4685728]
    static class AdvXMLParser::Comment null;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_COMMENT_H
