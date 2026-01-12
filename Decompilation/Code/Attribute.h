#ifndef ADVXMLPARSER_ATTRIBUTE_H
#define ADVXMLPARSER_ATTRIBUTE_H

namespace AdvXMLParser {

class Attribute {
public:
    // address=[0x2f148f0]
     Attribute(class AdvXMLParser::NodeContainer &,std::string const &);

    // address=[0x2f14920]
    class AdvXMLParser::Attribute *  Clone(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f149f0]
    virtual std::string  GetData(void)const;

    // address=[0x2f14a30]
    virtual std::string  GetValue(void)const;

    // address=[0x2f14b70]
    virtual bool  IsKindOf(int)const;

    // address=[0x2f14ba0]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f1cce0]
    virtual  ~Attribute(void);

    // address=[0x2f23650]
    static class AdvXMLParser::Attribute * __cdecl Parse(class AdvXMLParser::Parser &,class AdvXMLParser::Element &);

    // address=[0x2f23790]
    bool  ParseAttValue(class AdvXMLParser::Parser &);

    // address=[0x2f2cf30]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext &)const;

    // address=[0x46856a4]
    static class AdvXMLParser::Attribute null;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_ATTRIBUTE_H
