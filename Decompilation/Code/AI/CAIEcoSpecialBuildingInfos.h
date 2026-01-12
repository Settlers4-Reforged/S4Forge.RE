#ifndef CAIECOSPECIALBUILDINGINFOS_H
#define CAIECOSPECIALBUILDINGINFOS_H

class CAIEcoSpecialBuildingInfos {
public:
    // address=[0x133a1d0]
     CAIEcoSpecialBuildingInfos(void);

    // address=[0x133a230]
     ~CAIEcoSpecialBuildingInfos(void);

    // address=[0x133a250]
    static class CAIEcoSpecialBuildingInfos * __cdecl TheObject(void);

    // address=[0x133a2d0]
    struct SAIESBIBoundingInfos const *  GetBoundingBoxInfo(int,enum BUILDING_TYPES);

    // address=[0x133a300]
    int  GetBlockingBitAmount(int,enum BUILDING_TYPES);

    // address=[0x133a330]
    int  GetNrNeededBoards(int,enum BUILDING_TYPES);

    // address=[0x133a360]
    int  GetNrNeededStones(int,enum BUILDING_TYPES);

    // address=[0x133a390]
    int  GetNrNeededGold(int,enum BUILDING_TYPES);

private:
    // address=[0x133a3c0]
    void  InitBoundingBoxes(void);

    // address=[0x133a4a0]
    void  InitBlockingBitCount(void);

    // address=[0x133a640]
    void  InitBuildResources(void);

    // address=[0x3ecd4b4]
    static class CAIEcoSpecialBuildingInfos * pSingleInstance;

};


#endif // CAIECOSPECIALBUILDINGINFOS_H
