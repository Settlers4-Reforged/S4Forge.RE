#ifndef ADVXMLPARSER_CHARREF_H
#define ADVXMLPARSER_CHARREF_H

namespace AdvXMLParser {

class CharRef {
public:
    // address=[0x2f14c20]
     CharRef(int);

    // address=[0x2f14cc0]
     CharRef(class AdvXMLParser::NodeContainer &,int);

    // address=[0x2f14d50]
    class AdvXMLParser::CharRef *  Clone(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f14de0]
    virtual std::string  GetData(void)const;

    // address=[0x2f14e20]
    virtual std::string  GetValue(void)const;

    // address=[0x2f14e60]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f1cd30]
    virtual  ~CharRef(void);

    // address=[0x2f23a10]
    static class AdvXMLParser::CharRef * __cdecl Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &);

    // address=[0x2f2cf80]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext &)const;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_CHARREF_H
