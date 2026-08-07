#ifndef CLANDSCAPECOLORPROPERTIES_H
#define CLANDSCAPECOLORPROPERTIES_H

#include "defines.h"

class CLandscapeColorProperties {
public:
    // address=[0x2f8dcb0]
     CLandscapeColorProperties(void);

    // address=[0x2f8eab0]
    struct SColorEntry const &  CLandscapeColorProperties::ColorEntry(int a2)const;

    // address=[0x2fc5290]
    unsigned short  HiColValue(int a2)const;

    // Type information members
public:
    __int16[256] m_vHiColorEntry;
    CLandscapeColorProperties::SColorEntry[256] m_vColorEntries;

};


#endif // CLANDSCAPECOLORPROPERTIES_H
