#ifndef CWORLDMANAGER_H
#define CWORLDMANAGER_H

class CWorldManager {
public:
    // address=[0x12fd0f0]
    static unsigned int __cdecl FlagBits(int,unsigned int);

    // address=[0x12fd2d0]
    static bool __cdecl InWorld(int,int);

    // address=[0x12fd350]
    static int __cdecl Index(int,int);

    // address=[0x12fd440]
    static int __cdecl NormalTileId(int);

    // address=[0x12fd4a0]
    static int __cdecl ObjectId(int,int);

    // address=[0x12fd620]
    static int __cdecl SectorId(int);

    // address=[0x1306950]
    static int __cdecl SectorId(int,int);

    // address=[0x130eff0]
    static int __cdecl Ground(int);

    // address=[0x130f080]
    static bool __cdecl InWorldPackedXY(int);

    // address=[0x130f0b0]
    static bool __cdecl IsBlockedLand(int);

    // address=[0x130f1f0]
    static int __cdecl NeighborRelIndex(int);

    // address=[0x130f3c0]
    static int __cdecl SettlerId(int,int);

    // address=[0x130f540]
    static int __cdecl Width(void);

    // address=[0x131c950]
    static unsigned int __cdecl Flags(int);

    // address=[0x131c970]
    static int __cdecl GroundHeight(int);

    // address=[0x131c9b0]
    static int __cdecl Height(void);

    // address=[0x131c9c0]
    static int __cdecl Resource(int);

    // address=[0x1326db0]
    static int __cdecl EcoSectorId(int,int);

    // address=[0x1335f70]
    static unsigned int __cdecl FlagBits(int,int,unsigned int);

    // address=[0x13367c0]
    static int __cdecl ResourceAmount(int,int,int);

    // address=[0x1346600]
    static int __cdecl BuildingId(int,int);

    // address=[0x1346660]
    static int __cdecl EcoSectorId(int);

    // address=[0x1346760]
    static int __cdecl Ground(int,int);

    // address=[0x1351a40]
    static int __cdecl BuildingId(int);

    // address=[0x1351b70]
    static int __cdecl MapObjectId(int);

    // address=[0x1351b90]
    static int __cdecl MapObjectId(int,int);

    // address=[0x1351bc0]
    static int __cdecl MoveCostsBits(int);

    // address=[0x1351be0]
    static int __cdecl MoveCount(int);

    // address=[0x1351c90]
    static int __cdecl ObjectId(int);

    // address=[0x1351cb0]
    static int __cdecl OccupyingEntityId(int);

    // address=[0x1351d00]
    static int __cdecl OccupyingEntityId(int,int);

    // address=[0x141d7b0]
    static void __cdecl ClearFlagBits(int,int,unsigned int);

    // address=[0x141d830]
    static void __cdecl ClearFlagBits(int,unsigned int);

    // address=[0x141d8d0]
    static bool __cdecl InInnerWorld16(int,int);

    // address=[0x141d9d0]
    static bool __cdecl IsWater(int);

    // address=[0x141da40]
    static void __cdecl SetFlagBits(int,int,unsigned int);

    // address=[0x141dac0]
    static void __cdecl SetFlagBits(int,unsigned int);

    // address=[0x141dba0]
    static int __cdecl X(int);

    // address=[0x141dbc0]
    static int __cdecl Y(int);

    // address=[0x1439bd0]
    static int __cdecl Index(int);

    // address=[0x1447770]
    static int __cdecl PileId(int);

    // address=[0x1447860]
    static int __cdecl SettlerId(int);

    // address=[0x1452a70]
    static int __cdecl OwnerId(int,int);

    // address=[0x1460470]
    static void __cdecl ClearHelperObject(void);

    // address=[0x14605e0]
    static int __cdecl GetHelperObject(int,int);

    // address=[0x1460a20]
    static void __cdecl SetHelperObject(int,int,int);

    // address=[0x146aea0]
    static int __cdecl ResourceAmount(int,int);

    // address=[0x146aef0]
    static int __cdecl ResourceType(int);

    // address=[0x146af10]
    static void __cdecl SetObjectId(int,int);

    // address=[0x146af30]
    static void __cdecl SetResource(int,int,int);

    // address=[0x1470bb0]
    static int __cdecl PileId(int,int);

    // address=[0x1470e10]
    static int __cdecl SurroundingHexPointRelIndex(int);

    // address=[0x1486fb0]
    static int __cdecl GroundHeight(int,int);

    // address=[0x14aabe0]
    static unsigned short * __cdecl GetDecoObjectPtr(void);

    // address=[0x14aac20]
    static struct T_GFX_MAP_ELEMENT * __cdecl GetLandscapePtr(void);

    // address=[0x14aac30]
    static unsigned short * __cdecl GetMapObjectPtr(void);

    // address=[0x14d87f0]
    static void __cdecl SetMapObjectId(int,int);

    // address=[0x14d8870]
    static void __cdecl SetSettlerId(int,int);

    // address=[0x14dfef0]
    static bool __cdecl InWorld(int);

    // address=[0x14dff70]
    static bool __cdecl IsPositionFreeForSettler(int);

    // address=[0x14dffc0]
    static bool __cdecl IsPositionFreeForSettler(int,int);

    // address=[0x14e3040]
    static void __cdecl SetMapObjectId(int,int,int);

    // address=[0x14e3070]
    static void __cdecl SetSettlerId(int,int,int);

    // address=[0x14e6880]
    static void __cdecl SetMoveCostsBits(int,int);

    // address=[0x14eb2e0]
    static void __cdecl ClearBlockedPosition(int,int);

    // address=[0x14eb6f0]
    static void __cdecl SetBlockedPosition(int,int);

    // address=[0x14eb720]
    static void __cdecl SetMoveCount(int,int);

    // address=[0x14eb750]
    static void __cdecl SetOwnerId(int,int,int);

    // address=[0x14fd2d0]
    static void __cdecl DecreaseGroundHeight(int,int);

    // address=[0x14fd770]
    static void __cdecl IncreaseGroundHeight(int,int);

    // address=[0x14fd7c0]
    static bool __cdecl IsWater(int,int);

    // address=[0x14fdd70]
    static int __cdecl OwnerId(int);

    // address=[0x1506770]
    static void __cdecl SetObjectId(int,int,int);

    // address=[0x1516110]
    static void __cdecl SetResource(int,int,int,int);

    // address=[0x151aa50]
    static bool __cdecl InInnerWorld2(int,int);

    // address=[0x151ab00]
    static int __cdecl ResourceType(int,int);

    // address=[0x151ab30]
    static int __cdecl ShadingGradient(int);

    // address=[0x1575b60]
    static int __cdecl CatapultTileId(int,int);

    // address=[0x15a7a50]
    static bool __cdecl InInnerWorld1(int,int);

    // address=[0x15d6110]
    static int __cdecl CatapultTileId(int);

    // address=[0x15fe660]
    static bool __cdecl IsBlockedWater(int);

    // address=[0x16a2580]
     CWorldManager(void);

    // address=[0x16a25c0]
    virtual  ~CWorldManager(void);

    // address=[0x16a2610]
    static void __cdecl Destruct(void);

    // address=[0x16a26d0]
    static bool __cdecl LoadMap(class S4::CMapFile &,int);

    // address=[0x16a28b0]
    static bool __cdecl SaveMap(class S4::CMapFile &);

    // address=[0x16a2a20]
    static void __cdecl LoadGfxData(class S4::CMapFile &,int,int);

    // address=[0x16a2d60]
    static void __cdecl IncreaseWalkCount(int);

    // address=[0x16a2e90]
    static void __cdecl DecreaseWalkCount(int);

    // address=[0x16a2fc0]
    static void __cdecl SetPileId(int,int);

    // address=[0x16a3020]
    static int __cdecl CheckBlockable(int,int);

    // address=[0x16a30e0]
    static void __cdecl SetGround(int,int,int);

    // address=[0x16a3170]
    static void __cdecl SetOwner(int,int);

    // address=[0x16a4060]
    static void __cdecl SetTowerBits(int,int,int,int);

    // address=[0x16a4170]
    static void __cdecl TraceLine(int,int,int,int);

    // address=[0x16a4380]
    static struct SGfxColor * __cdecl GetMiniMapColor(unsigned int);

    // address=[0x16a4480]
    static void __cdecl WorldSetNumberOfNextLine(int);

    // address=[0x16a44a0]
    static unsigned char __cdecl WorldGetIconObjectByX(int);

    // address=[0x16a44c0]
    static int __cdecl WorldOwnerId(int);

    // address=[0x16a44f0]
    static int __cdecl WorldOwnerIdColor(int);

protected:
    // address=[0x16a4520]
    static void __cdecl Construct(int);

    // address=[0x16a46f0]
    static void __cdecl SetGroundInit(int,int);

    // address=[0x16a4790]
    static void __cdecl GetBuildingInfluenceInfo(int,int &,int &);

    // address=[0x16a4800]
    static int __cdecl CheckSettlerId(int);

    // address=[0x16a4840]
    static int __cdecl CheckBuildingId(int);

    // address=[0x16a4880]
    static int __cdecl CheckPileId(int);

    // address=[0x16a6b40]
    static void __cdecl ClearBlockedLandEx(int);

    // address=[0x16a7880]
    static void __cdecl SetBlockedLandEx(int);

    // address=[0x16a78a0]
    static void __cdecl SetGroundTypeOnly(int,int);

    // address=[0x16a78e0]
    static void __cdecl StartUpOwner(int,int);

    // address=[0x462bcd8]
    static int m_iWidthHeight;

    // address=[0x462bcdc]
    static int m_iWorldIdxMax;

    // address=[0x462bce0]
    static class CNeighborRelIndices m_cNeighborRelIndices;

    // address=[0x462bd10]
    static class CSurroundingHexPointsIndices m_cSurroundingHexPointsIndices;

    // address=[0x462c854]
    static class TSparseMap<unsigned char> * m_pHelpObjectMap;

    // address=[0x462c85c]
    static class TMap<unsigned short> m_cNormalTileIdMap;

    // address=[0x462c960]
    static class TMap<unsigned short> m_cCatapultTileIdMap;

    // address=[0x462c964]
    static class TMap<struct T_GFX_MAP_ELEMENT> m_cRenderMap;

    // address=[0x462c968]
    static class TMap<unsigned char> m_cFlagMap;

    // address=[0x462c96c]
    static class TMap<unsigned short> m_cMapObjectMap;

    // address=[0x462c970]
    static class TMap<unsigned short> m_cDecoObjectMap;

    // address=[0x462c974]
    static class TMap<unsigned char> m_cResourceMap;

    // address=[0x462c978]
    static class TMap<unsigned char> m_cWalkCount5MoveCost3Map;

    // address=[0x462c97c]
    static class TMap<unsigned char> m_cFogMap;

};


#endif // CWORLDMANAGER_H
