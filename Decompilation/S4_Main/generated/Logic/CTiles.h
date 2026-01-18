#ifndef CTILES_H
#define CTILES_H

#include "defines.h"

class CTiles {
public:
    // address=[0x15e7130]
    static bool __cdecl IsValidRealTile(int a1);

    // address=[0x15f4960]
    static bool __cdecl IsValidPseudoTile(int a1);

    // address=[0x15f4990]
    static bool __cdecl IsValidTileId(int a1);

protected:
    // address=[0x15e7450]
    static struct SFirstLast & __cdecl CTiles::SquareFirstLastXY(int a1, int a2);

    // address=[0x15e7490]
    static class CTile & __cdecl TileEx(int a1);

    // address=[0x4192600]
    static class CTile * m_cTiles;

    // address=[0x4232600]
    static struct SFirstLast (* CTiles::m_sSquareFirstLastTiles)[64];

};


#endif // CTILES_H
