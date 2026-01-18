#ifndef ADVXMLPARSER_ELEMENT_H
#define ADVXMLPARSER_ELEMENT_H

#include "defines.h"

namespace AdvXMLParser {

class Element {
public:
    // address=[0x14f3890]
    class AdvXMLParser::Attribute const &  operator[](char const * a2)const;

    // address=[0x14f3c30]
    class AdvXMLParser::Element const &  operator()(char const * a2, int a3)const;

    // address=[0x14f3e90]
    class AdvXMLParser::Element const &  GetElement(char const * a2, int a3)const;

    // address=[0x2f15200]
     Element(std::string const & a2);

    // address=[0x2f15240]
     Element(class AdvXMLParser::NodeContainer & a2, std::string const & a3);

    // address=[0x2f15280]
    virtual  ~Element(void);

    // address=[0x2f15360]
    class AdvXMLParser::Element *  Clone(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f15430]
    static void __cdecl Normalize(std::string & a1);

    // address=[0x2f15450]
    class AdvXMLParser::Element &  CreateElement(char const * Str, int a3);

    // address=[0x2f15570]
    class AdvXMLParser::Element &  AddElementInto(char const * Str);

    // address=[0x2f15670]
    class AdvXMLParser::Element &  AppendElement(char const * Str);

    // address=[0x2f157a0]
    class AdvXMLParser::Element &  InsertElementAfter(char const * Str);

    // address=[0x2f158d0]
    class AdvXMLParser::Element &  InsertElementBefore(char const * Str);

    // address=[0x2f15a00]
    bool  DeleteChildElement(char const * a2, int a3);

    // address=[0x2f15ad0]
    class AdvXMLParser::Attribute const &  GetAttribute(char const * Str)const;

    // address=[0x2f15bd0]
    class AdvXMLParser::Attribute const &  GetAttribute(int a2)const;

    // address=[0x2f15c10]
    class AdvXMLParser::Attribute &  GetAttribute(char const * Str);

    // address=[0x2f15d30]
    class AdvXMLParser::Attribute &  GetAttribute(int a2);

    // address=[0x2f15d70]
    class AdvXMLParser::Attribute &  CreateAttribute(char const * Str);

    // address=[0x2f15ec0]
    class AdvXMLParser::Comment const &  GetComment(int a2)const;

    // address=[0x2f15f80]
    class AdvXMLParser::Comment &  GetComment(int a2);

    // address=[0x2f16040]
    class AdvXMLParser::CData const &  GetCData(int a2)const;

    // address=[0x2f16100]
    class AdvXMLParser::CData &  GetCData(int a2);

    // address=[0x2f161c0]
    class AdvXMLParser::Pi const &  GetPi(char const * a2, int a3)const;

    // address=[0x2f16280]
    class AdvXMLParser::Pi const &  GetPi(int a2)const;

    // address=[0x2f16340]
    class AdvXMLParser::Pi &  GetPi(char const * a2, int a3);

    // address=[0x2f16400]
    class AdvXMLParser::Pi &  GetPi(int a2);

    // address=[0x2f164c0]
    virtual std::string  GetData(void a1)const;

    // address=[0x2f164f0]
    virtual std::string  GetValue(void a2)const;

    // address=[0x2f16640]
    virtual bool  IsKindOf(int a2)const;

    // address=[0x2f16670]
    virtual class AdvXMLParser::Node *  CloneNode(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f1e4b0]
    class AdvXMLParser::Element &  GetElement(char const * a2, int a3);

    // address=[0x2f23c70]
    static class AdvXMLParser::Element * __cdecl Parse(class AdvXMLParser::Parser & a1, class AdvXMLParser::NodeContainer & a2);

    // address=[0x2f2d020]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext & a2)const;

    // address=[0x4685658]
    static class AdvXMLParser::Element null;

private:
    // address=[0x2f23d50]
    static class AdvXMLParser::Element * __cdecl ParseTagBegining(class AdvXMLParser::Parser & a1, bool & a2, class AdvXMLParser::NodeContainer & a3);

    // address=[0x2f23f60]
    bool  ParseETag(class AdvXMLParser::Parser & a2);

    // address=[0x2f24050]
    void  ParseContentETag(class AdvXMLParser::Parser & a2);

    // address=[0x2f241d0]
    void  ParseReference(class AdvXMLParser::Parser & a2);

    // address=[0x2f24260]
    bool  ParseMarkup(class AdvXMLParser::Parser & a2);

    // address=[0x2f244a0]
    void  HandleSpecialAttributes(class AdvXMLParser::Attribute const *);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_ELEMENT_H
