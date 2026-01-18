#ifndef ADVXMLPARSER_BOOKMARK_H
#define ADVXMLPARSER_BOOKMARK_H

#include "defines.h"

namespace AdvXMLParser {

class Bookmark {
public:
    // address=[0x2f1e530]
    void  GetSubString(std::string & a2, int a3);

    // address=[0x2f1e5f0]
    void  Reset(void);

    // address=[0x2f27ea0]
     Bookmark(class AdvXMLParser::Parser & a2);

    // address=[0x2f286d0]
    void  Restore(void);

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_BOOKMARK_H
