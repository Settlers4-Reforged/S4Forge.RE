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

};


#endif // CLANDSCAPECOLORPROPERTIES_H
