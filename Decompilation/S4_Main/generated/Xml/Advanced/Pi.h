#ifndef ADVXMLPARSER_PI_H
#define ADVXMLPARSER_PI_H

#include "defines.h"

namespace AdvXMLParser {

class Pi {
public:
    // address=[0x2f16980]
     Pi(std::string const & a2, std::string const & a3);

    // address=[0x2f16a00]
     Pi(class AdvXMLParser::NodeContainer & a2, std::string const & a3, std::string const & a4);

    // address=[0x2f16a70]
    class AdvXMLParser::Pi *  Clone(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f16b60]
    virtual std::string  GetData(void a2)const;

    // address=[0x2f16ba0]
    virtual std::string  GetValue(void a2)const;

    // address=[0x2f16be0]
    virtual bool  IsKindOf(int a2)const;

    // address=[0x2f16c10]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f1ce10]
    virtual  ~Pi(void);

    // address=[0x2f246a0]
    static class AdvXMLParser::Pi * __cdecl Parse(class AdvXMLParser::Parser & a1, class AdvXMLParser::NodeContainer & a2);

    // address=[0x2f2d1e0]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext & a2)const;

    // address=[0x4685618]
    static class AdvXMLParser::Pi null;

private:
    // address=[0x2f24800]
    static bool __cdecl ParsePITarget(class AdvXMLParser::Parser & a1, std::string & a2);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_PI_H
