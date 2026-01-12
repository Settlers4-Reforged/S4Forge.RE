#ifndef CTILING_H
#define CTILING_H

class CTiling : public ITiling, public CTilingWorld, public CTilesAndLinks {
public:
    // address=[0x15e7bb0]
    static void __cdecl BlockBorder(void);

    // address=[0x15e7cd0]
    static void __cdecl PrepareReCalculate(void);

    // address=[0x15e7d80]
    static void __cdecl CalcSquareComponents(void);

    // address=[0x15e81a0]
    static void __cdecl CalcSquareTiles(enum T_TILING_TYPE);

    // address=[0x15f3f30]
     CTiling(void);

    // address=[0x15f4600]
    static enum T_TILING_TYPE __cdecl GetTilingType(int);

    // address=[0x15f58b0]
    static void __cdecl SetTileId(enum T_TILING_TYPE,int,int);

    // address=[0x15f5940]
    static int __cdecl TileId(enum T_TILING_TYPE,int);

protected:
    // address=[0x15e83e0]
    static int __cdecl SearchForNearestTileElement(int,int,enum T_TILING_TYPE);

    // address=[0x15e85d0]
    static void __cdecl CalcAllTiles(void);

    // address=[0x15e8780]
    static void __cdecl CalcAllTileLinks(void);

    // address=[0x15e8aa0]
    static void __cdecl CalcSectorIds(bool);

    // address=[0x15e8ca0]
    static void __cdecl CalcNotifyAll(bool);

    // address=[0x15e8d50]
    static void __cdecl CalcTileLinks(int);

    // address=[0x15e8e20]
    static void __cdecl RecalcTileLinks(int);

    // address=[0x15e8f40]
    static void __cdecl ChangeTileIds(enum T_TILING_TYPE,int,int);

    // address=[0x15e9100]
    static int __cdecl SplitTile(enum T_TILING_TYPE,int);

    // address=[0x15e9180]
    static bool __cdecl CheckBorderLink(int,int);

    // address=[0x15e93e0]
    static void __cdecl NUpdateLinksAndCheckTileSpliting(void);

    // address=[0x15e95e0]
    static int __cdecl CalcIntLinkList(class CIntLinkList &,enum T_TILING_TYPE,int);

    // address=[0x15e98c0]
    static void __cdecl NCheckTileSplit(void);

    // address=[0x15e9a60]
    static void __cdecl NCheckSectorSplit(void);

    // address=[0x15e9c30]
    static void __cdecl NCalcNewTileId(int);

    // address=[0x15e9d80]
    static void __cdecl NCheckSectorMerge(int);

    // address=[0x15e9e00]
    static void __cdecl NCheckEcoSectorJoin(int);

    // address=[0x15e9f60]
    static void __cdecl NCheckSectorAndEcoSectorDelete(void);

    // address=[0x15ea0d0]
    static void __cdecl NRemoveElementFromTile(void);

    // address=[0x15ea1b0]
    static void __cdecl NCheckEcoSectorSplit(int);

    // address=[0x15ea530]
    static void __cdecl NCheckEcoSectorDelete(void);

    // address=[0x15ea600]
    static void __cdecl NCheckEcoSectorMerge(int,int);

    // address=[0x15ea7c0]
    static void __cdecl NCheckSectorJoin(void);

    // address=[0x15ea8c0]
    static void __cdecl NCheckTileMerge(void);

    // address=[0x15eabd0]
    static void __cdecl MergeTiles(int,int);

    // address=[0x15eade0]
    static void __cdecl MergeSectors(int,int);

    // address=[0x15eae40]
    static int __cdecl MergeEcoSectors(int,int);

    // address=[0x15eaf00]
    static void __cdecl WalkTileChangeTileId(int,int);

    // address=[0x15eb0e0]
    static void __cdecl WalkTileNotifyEcoSectorChange(int,int,int);

    // address=[0x15eb310]
    static void __cdecl WalkTilesSetVisited(int);

    // address=[0x15eb4b0]
    static void __cdecl WalkTilesChangeSector(int,int);

    // address=[0x15eb690]
    static void __cdecl WalkTilesSectorSetVisited(int);

    // address=[0x15eb840]
    static void __cdecl WalkTilesEcoSectorSetVisited(int);

    // address=[0x15eb9f0]
    static int __cdecl WalkTilesEcoSectorSetVisitedAndCountSize(int);

    // address=[0x15ebcb0]
    static void __cdecl WalkTilesChangeEcoSector(int,int);

    // address=[0x15ebea0]
    static void __cdecl WalkTilesChangeEcoSectorAndNotify(int,int);

    // address=[0x15ec0c0]
    static void __cdecl CalculateBorderstoneBit(int,int);

    // address=[0x15ec1c0]
    static void __cdecl CalculateBorderstoneBits7(int,int);

    // address=[0x15ec260]
    static void __cdecl ClearBorderstoneBits(void);

    // address=[0x15ec2b0]
    static void __cdecl CalculateBorderstoneBits(void);

    // address=[0x15ec3a0]
    static void __cdecl BlockedLandSurroundingCheck(int,int);

    // address=[0x15ecb50]
    virtual void  Init(int,struct T_GFX_MAP_ELEMENT *,unsigned char *,unsigned short *,unsigned short *,unsigned char *,bool);

    // address=[0x15ece80]
    virtual void  Done(void);

    // address=[0x15ecfe0]
    virtual void  Update(void);

    // address=[0x15ed050]
    virtual void  SetBlockedLand(int,int);

    // address=[0x15ed210]
    virtual void  SetBlockedWater(int,int);

    // address=[0x15ed320]
    virtual void  ClearBlockedLand(int,int);

    // address=[0x15ed510]
    virtual void  ClearBlockedWater(int,int);

    // address=[0x15ed660]
    virtual void  ChangeOwner(int,int,int);

    // address=[0x15eda70]
    void  SetBlockingEx(enum T_TILING_TYPE,int,int);

    // address=[0x15edcf0]
    void  ClearBlockingEx(enum T_TILING_TYPE,int,int);

    // address=[0x15eded0]
    virtual int  SectorSize(int)const;

    // address=[0x15edf50]
    virtual int  EcoSectorSize(int)const;

    // address=[0x15edff0]
    virtual int  EcoSectorPackedPosition(int)const;

    // address=[0x15ee310]
    virtual int  NumberOfWorldElements(void)const;

    // address=[0x15ee340]
    virtual int  NumberOfLandElements(void)const;

    // address=[0x15ee360]
    virtual int  NumberOfWaterElements(void)const;

    // address=[0x15ee370]
    virtual int  NumberOfOwnedLandElements(int)const;

    // address=[0x15ee3a0]
    virtual bool  AreNeighborSquaresConnectedViaLand(int,int,int,int);

    // address=[0x15ee4e0]
    virtual bool  CheckFlagBits(int,int,unsigned int,unsigned int const *,unsigned int);

    // address=[0x15ee720]
    static int __cdecl DbgCheckTileLinkList(int,int);

    // address=[0x15eec10]
    static bool __cdecl DbgCheckTileLink(int,int);

    // address=[0x15eec90]
    virtual void  DbgPrintTilingInfo(int);

    // address=[0x15eeca0]
    virtual int  DbgCheckTiling(int);

    // address=[0x15efc00]
    virtual void  DbgReCalculate(int);

    // address=[0x15efcc0]
    virtual void  DbgCheckBlocking(int);

    // address=[0x15f00e0]
    static void __cdecl DbgPrintLinkList(class CLinkList const &);

    // address=[0x15f0220]
    static int __cdecl DbgCheckSectors(int);

    // address=[0x15f0520]
    static int __cdecl DbgCheckEcoSectors(int);

    // address=[0x15f0870]
    static int __cdecl DbgCheckTileSizes(int);

    // address=[0x15f41e0]
    static void __cdecl CalcSquarePrepareCatapult(int,int);

    // address=[0x15f4200]
    static void __cdecl CalcSquarePrepareNormal(int,int);

    // address=[0x15f4390]
    static int __cdecl EcoSectorSizeEx(int);

    // address=[0x15f4930]
    static bool __cdecl IsValidOwnerId(int);

    // address=[0x15f4a90]
    static void __cdecl NotifyChangeEcoSector(int,int,int,bool);

    // address=[0x15f4ce0]
    static int __cdecl NotifyCreateCatapultSector(void);

    // address=[0x15f4d00]
    static int __cdecl NotifyCreateEcoSector(int,bool);

    // address=[0x15f4e10]
    static int __cdecl NotifyCreateSector(void);

    // address=[0x15f4e30]
    static void __cdecl NotifyDeleteEcoSector(int);

    // address=[0x15f4f00]
    static void __cdecl NotifyDeleteSector(int);

    // address=[0x15f4f20]
    static void __cdecl NotifyEcoSectorMerge(int,int);

    // address=[0x15f4f40]
    static void __cdecl NotifyEcoSectorSplit(int,int);

    // address=[0x15f5080]
    static void __cdecl NotifyEcoSectorsMerged(int,int);

    // address=[0x15f51c0]
    static void __cdecl NotifyInitEcoSectors(bool);

    // address=[0x15f57f0]
    static void __cdecl SetNormalTileId(int,int);

    // address=[0x15f5980]
    static int __cdecl TileType(int,int,int,int);

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
