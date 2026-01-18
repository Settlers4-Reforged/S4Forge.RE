#ifndef ITILING_H
#define ITILING_H

#include "defines.h"

class ITiling {
public:
    // address=[0x12fcea0]
    static int __cdecl CatapultSectorId(int a1);

    // address=[0x12fced0]
    static int __cdecl CatapultTileId(int a1);

    // address=[0x12fd780]
    static class CTile const & __cdecl Tile(int a1);

    // address=[0x13066a0]
    static int __cdecl FirstTileOfSquareVW(int a1, int a2);

    // address=[0x130eb10]
    static int __cdecl EcoSectorId(int a1);

    // address=[0x130f210]
    static int __cdecl NormalTileId(int a1);

    // address=[0x130f270]
    static int __cdecl OwnerId(int a1);

    // address=[0x130f360]
    static int __cdecl SectorId(int a1);

    // address=[0x1351c50]
    static int __cdecl NumberOfWaterElementsDiv2XY(int a1, int a2);

    // address=[0x14e0060]
    static int __cdecl NumberOfWaterElementsDiv2VW(int a1, int a2);

    // address=[0x15f3f60]
     ITiling(void);

    // address=[0x15f5240]
    static int __cdecl OwnerPseudoTileId(int a1);

protected:
    // address=[0x4236800]
    static unsigned short * * m_pTileIds;

    // address=[0x4236808]
    static unsigned char (* m_uSquareNumberOfWaterElementsDiv2)[64];

};


#endif // ITILING_H
