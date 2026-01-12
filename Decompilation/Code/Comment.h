#ifndef ADVXMLPARSER_COMMENT_H
#define ADVXMLPARSER_COMMENT_H

namespace AdvXMLParser {

class Comment {
public:
    // address=[0x2f16690]
     Comment(std::string const &);

    // address=[0x2f16730]
     Comment(class AdvXMLParser::NodeContainer &,std::string const &);

    // address=[0x2f167d0]
    class AdvXMLParser::Comment *  Clone(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f168b0]
    virtual std::string  GetData(void)const;

    // address=[0x2f168f0]
    virtual std::string  GetValue(void)const;

    // address=[0x2f16930]
    virtual bool  IsKindOf(int)const;

    // address=[0x2f16960]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f1cd50]
    virtual  ~Comment(void);

    // address=[0x2f24560]
    static class AdvXMLParser::Comment * __cdecl Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &);

    // address=[0x2f2d190]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext &)const;

    // address=[0x4685728]
    static class AdvXMLParser::Comment null;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_COMMENT_H
