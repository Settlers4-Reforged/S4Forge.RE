#ifndef CSPIRALOFFSETS_H
#define CSPIRALOFFSETS_H

class CSpiralOffsets {
public:
    // address=[0x12fcfd0]
    static int __cdecl DeltaX(int);

    // address=[0x12fcff0]
    static int __cdecl DeltaY(int);

    // address=[0x1306680]
    static int __cdecl First(int);

    // address=[0x1306730]
    static int __cdecl Last(int);

    // address=[0x14fddb0]
    static int __cdecl Radius(int);

    // address=[0x1506400]
    static int __cdecl Direction(int);

    // address=[0x1568870]
    static int __cdecl PseudoDistanceSquareEx(int,int);

    // address=[0x16a74e0]
    static int __cdecl MaxGridDistance(int);

private:
    // address=[0x3e34770]
    static unsigned char * m_uMaxDists;

    // address=[0x3e394f0]
    static struct SRadiusFirstLast * CSpiralOffsets::m_sFirstLast;

    // address=[0x3e39620]
    static struct SSprialOffset * CSpiralOffsets::m_sOffsets;

};


#endif // CSPIRALOFFSETS_H
