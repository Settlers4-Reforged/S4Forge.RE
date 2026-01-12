#ifndef ADVXMLPARSER_TEXT_H
#define ADVXMLPARSER_TEXT_H

namespace AdvXMLParser {

class Text {
public:
    // address=[0x2f134b0]
     Text(std::string const &);

    // address=[0x2f13550]
     Text(class AdvXMLParser::NodeContainer &,std::string const &);

    // address=[0x2f135f0]
    class AdvXMLParser::Text *  Clone(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f13680]
    virtual std::string  GetData(void)const;

    // address=[0x2f136c0]
    virtual std::string  GetValue(void)const;

    // address=[0x2f13700]
    virtual bool  IsKindOf(int)const;

    // address=[0x2f13730]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f1ce60]
    virtual  ~Text(void);

    // address=[0x2f1e480]
    void  Concatenate(std::string const &);

    // address=[0x2f2cca0]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext &)const;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_TEXT_H
