#ifndef CSPIRALOFFSETS_H
#define CSPIRALOFFSETS_H

#include "defines.h"

class CSpiralOffsets {
public:
    // address=[0x12fcfd0]
    static int __cdecl DeltaX(int a1);

    // address=[0x12fcff0]
    static int __cdecl DeltaY(int a1);

    // address=[0x1306680]
    static int __cdecl First(int a1);

    // address=[0x1306730]
    static int __cdecl Last(int a1);

    // address=[0x14fddb0]
    static int __cdecl Radius(int a1);

    // address=[0x1506400]
    static int __cdecl Direction(int a1);

    // address=[0x1568870]
    static int __cdecl PseudoDistanceSquareEx(int a1, int a2);

    // address=[0x16a74e0]
    static int __cdecl MaxGridDistance(int a1);

private:
    // address=[0x3e34770]
    static unsigned char * m_uMaxDists;

    // address=[0x3e394f0]
    static struct SRadiusFirstLast * CSpiralOffsets::m_sFirstLast;

    // address=[0x3e39620]
    static struct SSprialOffset * CSpiralOffsets::m_sOffsets;

};


#endif // CSPIRALOFFSETS_H
