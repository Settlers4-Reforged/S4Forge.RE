#ifndef ADVXMLPARSER_DOCUMENT_H
#define ADVXMLPARSER_DOCUMENT_H

#include "defines.h"

namespace AdvXMLParser {

class Document {
public:
    // address=[0x14f3f30]
    class AdvXMLParser::Element &  GetRoot(void)const;

    // address=[0x2f16f20]
     Document(void);

    // address=[0x2f17000]
     Document(char const * Str);

    // address=[0x2f17160]
    class AdvXMLParser::Document *  Clone(void)const;

    // address=[0x2f17220]
    virtual std::string  GetData(void a1)const;

    // address=[0x2f17250]
    virtual std::string  GetValue(void a2)const;

    // address=[0x2f173a0]
    virtual bool  IsKindOf(int a2)const;

    // address=[0x2f173d0]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f1cd80]
    virtual  ~Document(void);

    // address=[0x2f25fc0]
    static class AdvXMLParser::Document * __cdecl Parse(class AdvXMLParser::Parser & a1);

    // address=[0x2f260c0]
    void  ParseProlog(class AdvXMLParser::Parser & a2);

    // address=[0x2f26110]
    bool  ParseXMLDecl(class AdvXMLParser::Parser & a2);

    // address=[0x2f261b0]
    bool  ParseVersionInfo(class AdvXMLParser::Parser & a2, std::string & a3);

    // address=[0x2f26240]
    bool  ParseVersionNum(class AdvXMLParser::Parser & a2, std::string & a3);

    // address=[0x2f26320]
    bool  ParseEncodingDecl(class AdvXMLParser::Parser & a2, std::string & a3);

    // address=[0x2f263b0]
    bool  ParseEncName(class AdvXMLParser::Parser & a2, std::string & a3);

    // address=[0x2f26460]
    bool  ParseSDDecl(class AdvXMLParser::Parser & a2, bool & a3);

    // address=[0x2f26520]
    bool  ParseMisc(class AdvXMLParser::Parser & a2);

    // address=[0x2f26640]
    void  ParseMiscs(class AdvXMLParser::Parser & a2);

    // address=[0x2f2d2b0]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext & a2)const;

private:
    // address=[0x2f26670]
    void  ParseRootElement(class AdvXMLParser::Parser & a2);

    // Type information members
private:
    struct DocumentVtbl * lpVtbl;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_DOCUMENT_H
