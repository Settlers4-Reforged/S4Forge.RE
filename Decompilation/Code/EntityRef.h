#ifndef ADVXMLPARSER_ENTITYREF_H
#define ADVXMLPARSER_ENTITYREF_H

namespace AdvXMLParser {

class EntityRef {
public:
    // address=[0x2f14e80]
     EntityRef(std::string const &);

    // address=[0x2f14f30]
     EntityRef(class AdvXMLParser::NodeContainer &,std::string const &);

    // address=[0x2f14fa0]
    class AdvXMLParser::EntityRef *  Clone(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f15050]
    virtual std::string  GetData(void)const;

    // address=[0x2f15090]
    virtual std::string  GetValue(void)const;

    // address=[0x2f150d0]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f1cdc0]
    virtual  ~EntityRef(void);

    // address=[0x2f23b40]
    static class AdvXMLParser::EntityRef * __cdecl Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &);

    // address=[0x2f2cfe0]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext &)const;

private:
    // address=[0x2f150f0]
    bool  MapReferenceName(void);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_ENTITYREF_H
