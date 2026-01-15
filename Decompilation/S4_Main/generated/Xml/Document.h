#ifndef ADVXMLPARSER_DOCUMENT_H
#define ADVXMLPARSER_DOCUMENT_H

namespace AdvXMLParser {

class Document {
public:
    // address=[0x14f3f30]
    class AdvXMLParser::Element &  GetRoot(void)const;

    // address=[0x2f16f20]
     Document(void);

    // address=[0x2f17000]
     Document(char const *);

    // address=[0x2f17160]
    class AdvXMLParser::Document *  Clone(void)const;

    // address=[0x2f17220]
    virtual std::string  GetData(void)const;

    // address=[0x2f17250]
    virtual std::string  GetValue(void)const;

    // address=[0x2f173a0]
    virtual bool  IsKindOf(int)const;

    // address=[0x2f173d0]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer &)const;

    // address=[0x2f1cd80]
    virtual  ~Document(void);

    // address=[0x2f25fc0]
    static class AdvXMLParser::Document * __cdecl Parse(class AdvXMLParser::Parser &);

    // address=[0x2f260c0]
    void  ParseProlog(class AdvXMLParser::Parser &);

    // address=[0x2f26110]
    bool  ParseXMLDecl(class AdvXMLParser::Parser &);

    // address=[0x2f261b0]
    bool  ParseVersionInfo(class AdvXMLParser::Parser &,std::string &);

    // address=[0x2f26240]
    bool  ParseVersionNum(class AdvXMLParser::Parser &,std::string &);

    // address=[0x2f26320]
    bool  ParseEncodingDecl(class AdvXMLParser::Parser &,std::string &);

    // address=[0x2f263b0]
    bool  ParseEncName(class AdvXMLParser::Parser &,std::string &);

    // address=[0x2f26460]
    bool  ParseSDDecl(class AdvXMLParser::Parser &,bool &);

    // address=[0x2f26520]
    bool  ParseMisc(class AdvXMLParser::Parser &);

    // address=[0x2f26640]
    void  ParseMiscs(class AdvXMLParser::Parser &);

    // address=[0x2f2d2b0]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext &)const;

private:
    // address=[0x2f26670]
    void  ParseRootElement(class AdvXMLParser::Parser &);

    // Type information members
private:
    struct DocumentVtbl * lpVtbl;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_DOCUMENT_H
