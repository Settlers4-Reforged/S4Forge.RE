#ifndef ADVXMLPARSER_REFERENCE_H
#define ADVXMLPARSER_REFERENCE_H

namespace AdvXMLParser {

class Reference {
public:
    // address=[0x2f14bc0]
     Reference(class AdvXMLParser::NodeContainer &,std::string const &);

    // address=[0x2f14bf0]
    virtual bool  IsKindOf(int)const;

    // address=[0x2f1ce40]
    virtual  ~Reference(void);

    // address=[0x2f23940]
    static class AdvXMLParser::Reference * __cdecl Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_REFERENCE_H
