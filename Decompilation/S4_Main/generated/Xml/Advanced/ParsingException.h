#ifndef ADVXMLPARSER_PARSINGEXCEPTION_H
#define ADVXMLPARSER_PARSINGEXCEPTION_H

namespace AdvXMLParser {

class ParsingException {
public:
    // address=[0x14f37c0]
    virtual  ~ParsingException(void);

    // address=[0x14f3ef0]
    int  GetLine(void)const;

    // address=[0x2f27ef0]
     ParsingException(class AdvXMLParser::ParsingException const &);

    // address=[0x2f27f50]
     ParsingException(enum AdvXMLParser::PARSER_ERROR,int,int);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_PARSINGEXCEPTION_H
