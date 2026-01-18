#ifndef CTILESEX_H
#define CTILESEX_H

#include "defines.h"

class CTilesEx {
public:
    // address=[0x15e3040]
    static void __cdecl InitTiles(class CLinkList & a1);

    // address=[0x15e31c0]
    static void __cdecl DeactivateTilesPushBackMode(void);

    // address=[0x15e3250]
    static void __cdecl CalculateOwnerBits(void);

    // address=[0x15e3260]
    static void __cdecl InsertTileIntoSquareList(int a1);

    // address=[0x15e34f0]
    static void __cdecl DeleteTileFromSquareList(int a1);

    // address=[0x15e36f0]
    static void __cdecl CalculateListOfFreeTiles(void);

    // address=[0x15e3810]
    static void __cdecl CalculateSquareTileLists(void);

    // address=[0x15e3880]
    static int __cdecl PushTileUndef(void);

    // address=[0x15e3a10]
    static int __cdecl PushTilesBackUndef(int a1);

    // address=[0x15e3ac0]
    static int __cdecl PushTile(int a1, int a2);

    // address=[0x15e3b30]
    static int __cdecl DuplicateTile(int a1);

    // address=[0x15e3bb0]
    static void __cdecl DeleteTile(int a1);

    // address=[0x15e7050]
    static bool __cdecl IsUsedRealTile(int a1);

    // address=[0x15e71c0]
    static bool __cdecl IsValidUsedTile(int a1);

    // address=[0x15e7220]
    static int __cdecl LastUsedTileId(void);

    // address=[0x15f5230]
    static int __cdecl NumberOfUsedTiles(void);

protected:
    // address=[0x4237888]
    static int m_iNumberOfUsedTiles;

    // address=[0x423788c]
    static int m_iLastUsedTileId;

    // address=[0x4237890]
    static int m_iMaxUsedTiles;

    // address=[0x4237894]
    static int m_iTilesPushBackMode;

    // address=[0x4237898]
    static int m_iCalcFreeListCounter;

};


#endif // CTILESEX_H
