#ifndef ADVXMLPARSER_GENERATECONTEXT_H
#define ADVXMLPARSER_GENERATECONTEXT_H

namespace AdvXMLParser {

class GenerateContext {
public:
    // address=[0x2f2c9d0]
     GenerateContext(std::string &,char const *,unsigned long);

    // address=[0x2f2ca30]
     GenerateContext(class AdvXMLParser::GenerateContext const &);

    // address=[0x2f2ca90]
    void  operator=(class AdvXMLParser::GenerateContext const &);

    // address=[0x2f2caf0]
    void  GenerateStartTagIndentation(void);

    // address=[0x2f2cb30]
    void  GenerateEndTagIndentation(void);

    // address=[0x2f2cba0]
    void  EndTag(void);

    // address=[0x2f2cbf0]
    void  GenerateNewLine(void);

    // address=[0x2f2d730]
    void  operator+=(std::string const &);

    // address=[0x2f2d760]
    void  operator+=(char);

    // address=[0x2f2d790]
    void  operator+=(char const *);

    // address=[0x2f2d860]
    bool  MustPreserve(void)const;

private:
    // address=[0x2f2cc30]
    void  GenerateIndentation(void);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_GENERATECONTEXT_H
