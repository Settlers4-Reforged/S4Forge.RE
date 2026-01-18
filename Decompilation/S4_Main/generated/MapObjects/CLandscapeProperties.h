#ifndef CLANDSCAPEPROPERTIES_H
#define CLANDSCAPEPROPERTIES_H

#include "defines.h"

class CLandscapeProperties {
public:
    // address=[0x141d960]
    bool  IsBlockedLand(int a2);

    // address=[0x141d9a0]
    static bool __cdecl IsWater(int a1);

    // address=[0x15f5960]
    unsigned int  TileType(int a2);

    // address=[0x16a5e60]
     CLandscapeProperties(void);

    // address=[0x16a7200]
    bool  IsSlowType(int a2);

};


#endif // CLANDSCAPEPROPERTIES_H
