#ifndef ITILING_H
#define ITILING_H

#include "defines.h"

// address=[0x37de3ac]
extern class ITiling *g_pTiling;

class ITiling {
public:
    // address=[0x12fcea0]
    static int __cdecl CatapultSectorId(int a1);

    // address=[0x12fced0]
    static int __cdecl CatapultTileId(int a1);

    // address=[0x12fd780]
    static class CTile const & __cdecl Tile(int a1);

    // address=[0x13066a0]
    static int __cdecl FirstTileOfSquareVW(int _uV, int _uW);

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
    friend class CWalkingBase;
    friend class CDecoObjMgr;

    // address=[0x4236800]
    static unsigned short **m_pTileIds;
    // address=[0x4236804]
    static unsigned short **m_pCatapultTileIds;

    // address=[0x4236808]
    static unsigned char (*m_uSquareNumberOfWaterElementsDiv2)[64];


    virtual void Init(int iWorldWidthHeight, struct T_GFX_MAP_ELEMENT *pGfxMapElements, unsigned char *pFlagBitsLayer, unsigned short *_pNormalTileIds, unsigned short *_pCatapultTileIds, unsigned char *pFogLayer, bool a8) = 0;

    virtual void Done(void) = 0;

    virtual void Update(void) = 0;

    virtual void SetBlockedLand(int a2, int a3) = 0;

    virtual void SetBlockedWater(int a2, int a3) = 0;

    virtual void ClearBlockedLand(int a2, int a3) = 0;

    virtual void ClearBlockedWater(int a2, int a3) = 0;

    virtual void ChangeOwner(int a2, int a3, int a4) = 0;

    virtual int SectorSize(int a2) const = 0;

    virtual int EcoSectorSize(int a2) const = 0;

    virtual int EcoSectorPackedPosition(int a2) const = 0;

    virtual int NumberOfWorldElements(void) const = 0;

    virtual int NumberOfLandElements(void) const = 0;

    virtual int NumberOfWaterElements(void) const = 0;

    virtual int NumberOfOwnedLandElements(int a2) const = 0;

    virtual bool AreNeighborSquaresConnectedViaLand(int a2, int a3, int a4, int a5) = 0;

    virtual bool CheckFlagBits(int a2, int a3, unsigned int a4, unsigned int const *a5, unsigned int a6) = 0;

    virtual void DbgPrintTilingInfo(int a2) = 0;

    virtual int DbgCheckTiling(int a2) = 0;

    virtual void DbgReCalculate(int a2) = 0;

    virtual void DbgCheckBlocking(int a2) = 0;
};


#endif // ITILING_H
