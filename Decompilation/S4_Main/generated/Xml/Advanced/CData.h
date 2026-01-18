#ifndef ADVXMLPARSER_CDATA_H
#define ADVXMLPARSER_CDATA_H

#include "defines.h"

namespace AdvXMLParser {

class CData {
public:
    // address=[0x2f16c30]
     CData(std::string const & a2);

    // address=[0x2f16cd0]
     CData(class AdvXMLParser::NodeContainer & a2, std::string const & a3);

    // address=[0x2f16d70]
    class AdvXMLParser::CData *  Clone(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f16e50]
    virtual std::string  GetData(void a2)const;

    // address=[0x2f16e90]
    virtual std::string  GetValue(void a2)const;

    // address=[0x2f16ed0]
    virtual bool  IsKindOf(int a2)const;

    // address=[0x2f16f00]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f1cd00]
    virtual  ~CData(void);

    // address=[0x2f248a0]
    static class AdvXMLParser::CData * __cdecl Parse(class AdvXMLParser::Parser & a1, class AdvXMLParser::NodeContainer & a2);

    // address=[0x2f2d260]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext & a2)const;

    // address=[0x46856e8]
    static class AdvXMLParser::CData null;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_CDATA_H
