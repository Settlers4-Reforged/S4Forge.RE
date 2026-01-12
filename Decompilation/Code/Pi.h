#ifndef ADVXMLPARSER_PI_H
#define ADVXMLPARSER_PI_H

namespace AdvXMLParser {

class Pi {
public:
    // address=[0x2f16980]
     Pi(std::string const &,std::string const &);

    // address=[0x2f16a00]
     Pi(class AdvXMLParser::NodeContainer &,std::string const &,std::string const &);

    // address=[0x2f16a70]
    class AdvXMLParser::Pi *  Clone(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f16b60]
    virtual std::string  GetData(void)const;

    // address=[0x2f16ba0]
    virtual std::string  GetValue(void)const;

    // address=[0x2f16be0]
    virtual bool  IsKindOf(int)const;

    // address=[0x2f16c10]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f1ce10]
    virtual  ~Pi(void);

    // address=[0x2f246a0]
    static class AdvXMLParser::Pi * __cdecl Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &);

    // address=[0x2f2d1e0]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext &)const;

    // address=[0x4685618]
    static class AdvXMLParser::Pi null;

private:
    // address=[0x2f24800]
    static bool __cdecl ParsePITarget(class AdvXMLParser::Parser &,std::string &);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_PI_H
