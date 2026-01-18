#ifndef STRING_H
#define STRING_H

#include "defines.h"

class String {
public:
    // address=[0x13512a0]
     String(std::string const & a2);

    // address=[0x13512d0]
     String(char const * Str, unsigned int Size);

    // address=[0x1351470]
     ~String(void);

    // address=[0x13516d0]
    class String &  operator=(class String const & a2);

    // address=[0x1351700]
    class String &  operator=(char const * Str);

    // address=[0x1352200]
    char const *  c_str(void)const;

    // address=[0x1369f20]
     String(class String const & a2, unsigned int a3, unsigned int Size);

    // address=[0x1369f50]
     String(void);

    // address=[0x136a1b0]
    class String &  operator+=(char const * Str);

};


#endif // STRING_H
