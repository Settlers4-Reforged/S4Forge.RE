#ifndef CTILING_H
#define CTILING_H

#include "defines.h"

class CTiling : public ITiling, public CTilingWorld, public CTilesAndLinks {
public:
    // address=[0x15e7bb0]
    static void __cdecl BlockBorder(void);

    // address=[0x15e7cd0]
    static void __cdecl PrepareReCalculate(void);

    // address=[0x15e7d80]
    static void __cdecl CalcSquareComponents(void);

    // address=[0x15e81a0]
    static void __cdecl CalcSquareTiles(enum T_TILING_TYPE a1);

    // address=[0x15f3f30]
     CTiling(void);

    // address=[0x15f4600]
    static enum T_TILING_TYPE __cdecl GetTilingType(int a1);

    // address=[0x15f58b0]
    static void __cdecl SetTileId(enum T_TILING_TYPE a1, int a2, int a3);

    // address=[0x15f5940]
    static int __cdecl TileId(enum T_TILING_TYPE a1, int a2);

protected:
    // address=[0x15e83e0]
    static int __cdecl SearchForNearestTileElement(int a1, int a2, enum T_TILING_TYPE a3);

    // address=[0x15e85d0]
    static void __cdecl CalcAllTiles(void);

    // address=[0x15e8780]
    static void __cdecl CalcAllTileLinks(void);

    // address=[0x15e8aa0]
    static void __cdecl CalcSectorIds(bool a1);

    // address=[0x15e8ca0]
    static void __cdecl CalcNotifyAll(bool a1);

    // address=[0x15e8d50]
    static void __cdecl CalcTileLinks(int a1);

    // address=[0x15e8e20]
    static void __cdecl RecalcTileLinks(int a1);

    // address=[0x15e8f40]
    static void __cdecl ChangeTileIds(enum T_TILING_TYPE a1, int a2, int a3);

    // address=[0x15e9100]
    static int __cdecl SplitTile(enum T_TILING_TYPE a1, int a2);

    // address=[0x15e9180]
    static bool __cdecl CheckBorderLink(int a1, int a2);

    // address=[0x15e93e0]
    static void __cdecl NUpdateLinksAndCheckTileSpliting(void);

    // address=[0x15e95e0]
    static int __cdecl CalcIntLinkList(class CIntLinkList & a1, enum T_TILING_TYPE a2, int a3);

    // address=[0x15e98c0]
    static void __cdecl NCheckTileSplit(void);

    // address=[0x15e9a60]
    static void __cdecl NCheckSectorSplit(void);

    // address=[0x15e9c30]
    static void __cdecl NCalcNewTileId(int a1);

    // address=[0x15e9d80]
    static void __cdecl NCheckSectorMerge(int a1);

    // address=[0x15e9e00]
    static void __cdecl NCheckEcoSectorJoin(int a1);

    // address=[0x15e9f60]
    static void __cdecl NCheckSectorAndEcoSectorDelete(void);

    // address=[0x15ea0d0]
    static void __cdecl NRemoveElementFromTile(void);

    // address=[0x15ea1b0]
    static void __cdecl NCheckEcoSectorSplit(int a1);

    // address=[0x15ea530]
    static void __cdecl NCheckEcoSectorDelete(void);

    // address=[0x15ea600]
    static void __cdecl NCheckEcoSectorMerge(int a1, int a2);

    // address=[0x15ea7c0]
    static void __cdecl NCheckSectorJoin(void);

    // address=[0x15ea8c0]
    static void __cdecl NCheckTileMerge(void);

    // address=[0x15eabd0]
    static void __cdecl MergeTiles(int a1, int a2);

    // address=[0x15eade0]
    static void __cdecl MergeSectors(int a1, int a2);

    // address=[0x15eae40]
    static int __cdecl MergeEcoSectors(int a1, int a2);

    // address=[0x15eaf00]
    static void __cdecl WalkTileChangeTileId(int a1, int a2);

    // address=[0x15eb0e0]
    static void __cdecl WalkTileNotifyEcoSectorChange(int a1, int a2, int a3);

    // address=[0x15eb310]
    static void __cdecl WalkTilesSetVisited(int a1);

    // address=[0x15eb4b0]
    static void __cdecl WalkTilesChangeSector(int a1, int a2);

    // address=[0x15eb690]
    static void __cdecl WalkTilesSectorSetVisited(int a1);

    // address=[0x15eb840]
    static void __cdecl WalkTilesEcoSectorSetVisited(int a1);

    // address=[0x15eb9f0]
    static int __cdecl WalkTilesEcoSectorSetVisitedAndCountSize(int a1);

    // address=[0x15ebcb0]
    static void __cdecl WalkTilesChangeEcoSector(int a1, int a2);

    // address=[0x15ebea0]
    static void __cdecl WalkTilesChangeEcoSectorAndNotify(int a1, int a2);

    // address=[0x15ec0c0]
    static void __cdecl CalculateBorderstoneBit(int a1, int a2);

    // address=[0x15ec1c0]
    static void __cdecl CalculateBorderstoneBits7(int a1, int a2);

    // address=[0x15ec260]
    static void __cdecl ClearBorderstoneBits(void);

    // address=[0x15ec2b0]
    static void __cdecl CalculateBorderstoneBits(void);

    // address=[0x15ec3a0]
    static void __cdecl BlockedLandSurroundingCheck(int a1, int a2);

    // address=[0x15ecb50]
    virtual void  Init(int a2, struct T_GFX_MAP_ELEMENT * a3, unsigned char * a4, unsigned short * a5, unsigned short * a6, unsigned char * a7, bool a8);

    // address=[0x15ece80]
    virtual void  Done(void);

    // address=[0x15ecfe0]
    virtual void  Update(void);

    // address=[0x15ed050]
    virtual void  SetBlockedLand(int a2, int a3);

    // address=[0x15ed210]
    virtual void  SetBlockedWater(int a2, int a3);

    // address=[0x15ed320]
    virtual void  ClearBlockedLand(int a2, int a3);

    // address=[0x15ed510]
    virtual void  ClearBlockedWater(int a2, int a3);

    // address=[0x15ed660]
    virtual void  ChangeOwner(int a2, int a3, int a4);

    // address=[0x15eda70]
    void  SetBlockingEx(enum T_TILING_TYPE a2, int a3, int a4);

    // address=[0x15edcf0]
    void  ClearBlockingEx(enum T_TILING_TYPE a2, int a3, int a4);

    // address=[0x15eded0]
    virtual int  SectorSize(int a2)const;

    // address=[0x15edf50]
    virtual int  EcoSectorSize(int a2)const;

    // address=[0x15edff0]
    virtual int  EcoSectorPackedPosition(int a2)const;

    // address=[0x15ee310]
    virtual int  NumberOfWorldElements(void)const;

    // address=[0x15ee340]
    virtual int  NumberOfLandElements(void)const;

    // address=[0x15ee360]
    virtual int  NumberOfWaterElements(void)const;

    // address=[0x15ee370]
    virtual int  NumberOfOwnedLandElements(int a2)const;

    // address=[0x15ee3a0]
    virtual bool  AreNeighborSquaresConnectedViaLand(int a2, int a3, int a4, int a5);

    // address=[0x15ee4e0]
    virtual bool  CheckFlagBits(int a2, int a3, unsigned int a4, unsigned int const * a5, unsigned int a6);

    // address=[0x15ee720]
    static int __cdecl DbgCheckTileLinkList(int a1, int a2);

    // address=[0x15eec10]
    static bool __cdecl DbgCheckTileLink(int a1, int a2);

    // address=[0x15eec90]
    virtual void  DbgPrintTilingInfo(int a2);

    // address=[0x15eeca0]
    virtual int  DbgCheckTiling(int a2);

    // address=[0x15efc00]
    virtual void  DbgReCalculate(int a2);

    // address=[0x15efcc0]
    virtual void  DbgCheckBlocking(int a2);

    // address=[0x15f00e0]
    static void __cdecl DbgPrintLinkList(class CLinkList const & a1);

    // address=[0x15f0220]
    static int __cdecl DbgCheckSectors(int);

    // address=[0x15f0520]
    static int __cdecl DbgCheckEcoSectors(int);

    // address=[0x15f0870]
    static int __cdecl DbgCheckTileSizes(int);

    // address=[0x15f41e0]
    static void __cdecl CalcSquarePrepareCatapult(int a1, int a2);

    // address=[0x15f4200]
    static void __cdecl CalcSquarePrepareNormal(int a1, int a2);

    // address=[0x15f4390]
    static int __cdecl EcoSectorSizeEx(int a1);

    // address=[0x15f4930]
    static bool __cdecl IsValidOwnerId(int a1);

    // address=[0x15f4a90]
    static void __cdecl NotifyChangeEcoSector(int a1, int a2, int a3, bool a4);

    // address=[0x15f4ce0]
    static int __cdecl NotifyCreateCatapultSector(void);

    // address=[0x15f4d00]
    static int __cdecl NotifyCreateEcoSector(int a1, bool a2);

    // address=[0x15f4e10]
    static int __cdecl NotifyCreateSector(void);

    // address=[0x15f4e30]
    static void __cdecl NotifyDeleteEcoSector(int a1);

    // address=[0x15f4f00]
    static void __cdecl NotifyDeleteSector(int a1);

    // address=[0x15f4f20]
    static void __cdecl NotifyEcoSectorMerge(int a1, int a2);

    // address=[0x15f4f40]
    static void __cdecl NotifyEcoSectorSplit(int a1, int a2);

    // address=[0x15f5080]
    static void __cdecl NotifyEcoSectorsMerged(int a1, int a2);

    // address=[0x15f51c0]
    static void __cdecl NotifyInitEcoSectors(bool);

    // address=[0x15f57f0]
    static void __cdecl SetNormalTileId(int a1, int a2);

    // address=[0x15f5980]
    static int __cdecl TileType(int a1, int a2, int a3, int a4);

    // address=[0x423789c]
    static int m_iInitialized;

    // address=[0x42378a0]
    static int m_iInitLastEcoSectorId;

    // address=[0x42378a4]
    static int m_iNumberOfWaterElements;

    // address=[0x42378a8]
    static int * m_iNumberOfOwnedElements;

    // address=[0x42378cc]
    static int m_iEcoSectorTileIdIterator;

    // address=[0x42378d0]
    static int * m_iEcoSectorSizes;

    // address=[0x42478d0]
    static unsigned short * m_uEcoSectorAnyTileIds;

    // address=[0x42cf9a8]
    static class CSectors m_cSectors;

};


#endif // CTILING_H
