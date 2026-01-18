#ifndef CAIDARKTRIBE_H
#define CAIDARKTRIBE_H

#include "defines.h"

class CAIDarkTribe : public IAIDarkTribeEcoAI {
public:
    // address=[0x132fad0]
     CAIDarkTribe(int a2);

    // address=[0x132fba0]
     ~CAIDarkTribe(void);

    // address=[0x132fc00]
    static class CAIDarkTribe * __cdecl CreateInstance(int);

    // address=[0x132fc80]
    virtual void  Release(void);

    // address=[0x132fcc0]
    virtual void  Execute(void);

    // address=[0x132fcf0]
    virtual int  GetNearGardenerWorkPosition(int a2);

    // address=[0x1330090]
    virtual int  GetNextGardenerWorkPosition(void);

    // address=[0x13300e0]
    virtual bool  IsBuildingPositionAvailable(enum BUILDING_TYPES a2);

    // address=[0x1330120]
    virtual bool  InvokeBuilding(enum BUILDING_TYPES a2);

    // address=[0x13301f0]
    virtual void  UpdateLandChangement(int a2, int a3, bool a4);

    // address=[0x1330350]
    int  IsGardenerPosition(int a2, int a3);

    // address=[0x1330360]
    int  IsBuildedPosition(int a2, int a3);

    // address=[0x1330420]
    int  IsBuildingPosition(int a2, int a3);

    // address=[0x1330490]
    int  IsOccupiedPosition(int a2, int a3);

    // address=[0x1330500]
    int  IsBorderPosition(int a2, int a3);

    // address=[0x1330570]
    int  IsReservedMushroomPosition(int a2, int a3);

private:
    // address=[0x1330620]
    void  InitDarkTribeElements(void);

    // address=[0x1330940]
    void  UnInitDarkTribeElements(void);

    // address=[0x13309a0]
    void  UpdateDarkTribeElement(int a2, bool a3);

    // address=[0x1330d60]
    void  AddToElementList(int a2);

    // address=[0x13310b0]
    void  PushNewOccupiedElement(struct SAIDTOCCUPIEDELEMENT const & a2);

    // address=[0x1331200]
    bool  ReplaceOccupiedElement(int a2, struct SAIDTOCCUPIEDELEMENT const & a3);

    // address=[0x1331380]
    void  RemoveOccupiedElement(int a2);

    // address=[0x1331470]
    bool  IsInOccupiedElementList(int a2);

    // address=[0x13314a0]
    int  GetOccupiedElementListIndex(int a2);

    // address=[0x1331520]
    void  RemoveBorderElement(int a2);

    // address=[0x1331600]
    int  GetBorderElementListIndex(int a2)const;

    // address=[0x1331650]
    void  RemoveBorderElementInWork(int a2);

    // address=[0x13316c0]
    int  GetBorderElementInWorkListIndex(int a2)const;

    // address=[0x1331710]
    int  GetLandConversionPosition(int a2)const;

    // address=[0x1331810]
    int  GetLandConversionPositionIndex(int a2)const;

    // address=[0x1331860]
    void  CleanLandConversionPositionsOfGrid(int a2);

    // address=[0x1331920]
    void  CheckSendGardenerPositions(void);

    // address=[0x1331b10]
    int  GetNextCurrentUsedInWorkElementIndex(void);

    // address=[0x1331c90]
    bool  GetWorkingPosition(int a2, int a3, class CAIResourceData const & a4, class std::vector<int,class std::allocator<int> > & a5);

    // address=[0x1331e60]
    int  GetNextBuildingPosition(void);

    // address=[0x1332170]
    bool  CheckBuildingGrids(void);

    // address=[0x13323c0]
    bool  CheckOtherBuildingPositions(int a2, int a3);

    // address=[0x13325c0]
    bool  IsPureDarkLandAround(int a2, int a3);

    // address=[0x1332670]
    bool  HasChangeableLand(class CAIResourceData const &);

    // address=[0x13326d0]
    int  GetChangeableLandAmount(class CAIResourceData const & a2);

    // address=[0x1332710]
    int  CountAdjacentDarkLand(int a2, int a3);

    // address=[0x13327a0]
    bool  IsAdjacent(int a2, int a3, int a4, int a5);

    // address=[0x1332800]
    void  CheckManakopterHallExists(void);

    // address=[0x1335fa0]
    int  GetBorderElement(int a2)const;

    // address=[0x1335ff0]
    int  GetBorderElementInWork(int a2)const;

    // address=[0x1336040]
    int  GetBuildingGrid(int a2)const;

    // address=[0x1336070]
    int  GetBuildingGridIndex(int a2)const;

    // address=[0x13360a0]
    int  GetNrBorderElements(void)const;

    // address=[0x13360c0]
    int  GetNrBorderElementsInWork(void)const;

    // address=[0x13360e0]
    int  GetNrBuildingGrids(void)const;

    // address=[0x1336100]
    int  GetNrLandConversionPositions(void)const;

    // address=[0x1336120]
    int  GetNrOccupiedElements(void)const;

    // address=[0x1336140]
    struct SAIDTOCCUPIEDELEMENT  GetOccupiedElement(int a2)const;

    // address=[0x13361f0]
    void  IncreaseNextCurrentUsedInWorkElementIndex(void);

    // address=[0x13362e0]
    bool  IsInBorderElementInWorkList(int a2)const;

    // address=[0x1336320]
    bool  IsInBorderElementList(int a2)const;

    // address=[0x1336360]
    bool  IsInBuildingGridList(int a2)const;

    // address=[0x13363a0]
    bool  IsInLandConversionPositionsList(int a2)const;

    // address=[0x1336750]
    void  RemoveBuildingGrid(int a2);

    // address=[0x1336780]
    void  RemoveLandConversionPosition(int a2);

};


#endif // CAIDARKTRIBE_H
