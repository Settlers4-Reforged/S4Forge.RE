#ifndef CECOMANAGER_H
#define CECOMANAGER_H

#include "defines.h"

class CEcoManager : public IAIEcoManager {
public:
    // address=[0x133af00]
     CEcoManager(int a2, class IAISectorAI * a3, class IAIEventQueue * a4);

    // address=[0x133b010]
    virtual  ~CEcoManager(void);

    // address=[0x133b0c0]
    virtual int  InterfaceVersion(void);

    // address=[0x133b0d0]
    virtual int  GetEcoSectorID(void);

    // address=[0x133b0f0]
    virtual enum AI_ECOMANAGER_ERROR  Invoke(enum BUILDING_TYPES a2);

    // address=[0x133b240]
    virtual enum AI_ECOMANAGER_ERROR  Invoke(enum BUILDING_TYPES iBuildingType, int a3, int a4);

    // address=[0x133b4c0]
    virtual bool  Discard(enum BUILDING_TYPES a2);

    // address=[0x133b620]
    virtual bool  DiscardPosition(enum BUILDING_TYPES a2, struct SBUILDINFODATA * a3);

    // address=[0x133b6b0]
    virtual int  GetBuildPlace(enum IECONOMANAGERGRIDRESOLUTION a2, enum BUILDING_TYPES a3, class std::vector<struct SBUILDINFODATA,class std::allocator<struct SBUILDINFODATA> > & a4);

    // address=[0x133b820]
    virtual int  GetBuildPlace(enum BUILDING_TYPES a2, struct SBUILDINFODATA * a3, class std::vector<struct SBUILDINFODATA,class std::allocator<struct SBUILDINFODATA> > & a4, int a5);

    // address=[0x133b9c0]
    virtual struct SBUILDINFODATA  GetBuildPlace(enum IECONOMANAGERGRIDRESOLUTION a2, enum BUILDING_TYPES a3, int a4, int a5, int a6);

    // address=[0x133bf80]
    virtual bool  IsInside(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x133c050]
    virtual bool  AreBuildingsOverlapped(enum BUILDING_TYPES a2, int a3, enum BUILDING_TYPES a4, int a5);

    // address=[0x133c260]
    virtual int  CheckBuildingOverlappingWithinGrid(enum BUILDING_TYPES a2, int a3);

    // address=[0x133c370]
    virtual int  GetBuildingIndex(int a2, int a3);

    // address=[0x133c3d0]
    virtual bool  GetBuildingPosition(int a2, int & a3, int & a4);

    // address=[0x133c490]
    virtual int  GetPileAmount(int a2, enum PILE_TYPES a3);

    // address=[0x133c570]
    virtual int  GetCountOfGoodsForBuilding(enum BUILDING_TYPES a2, enum IECONEEDEDRESOURCE a3);

    // address=[0x133c630]
    virtual int  GetCountOfPendingGoodsForBuilding(int a2, enum IECONEEDEDRESOURCE a3);

    // address=[0x133c6f0]
    virtual int  BuildingProgress(int a2);

    // address=[0x133c780]
    virtual bool  IsActive(int a2);

    // address=[0x133c810]
    virtual bool  IsBuildingPlaceActive(int a2);

    // address=[0x133c890]
    virtual enum BUILDING_TYPES  GetBuildingType(int a2);

    // address=[0x133c900]
    virtual bool  HaveInhabitant(int a2);

    // address=[0x133c970]
    virtual int  GetNrOfSettlerComingOutOfResidence(enum BUILDING_TYPES a2);

    // address=[0x133c9b0]
    virtual int  GetRemainingNrOfSettlersComingOutOfResidence(int a2);

    // address=[0x133ca40]
    virtual int  GetBuildingEcoSectorID(int a2);

    // address=[0x133caa0]
    virtual enum AI_ECOMANAGER_ERROR  ConstructBuilding(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x133cbf0]
    virtual enum AI_ECOMANAGER_ERROR  DestroyBuilding(int a2);

    // address=[0x133ccf0]
    virtual int  GetContentOfWorkingArea(int a2);

    // address=[0x133cd90]
    virtual bool  ChangeWorkingAreaTo(int a2, int a3, int a4);

    // address=[0x133cf00]
    virtual bool  GetPositionWorkingArea(int a2, int & a3, int & a4);

    // address=[0x133cfa0]
    virtual int  GetContentOfWorkingArea(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x133d2a0]
    virtual int  GetWorkingAreaSize(enum BUILDING_TYPES a2);

    // address=[0x133d310]
    virtual int  GetPlayerId(void);

    // address=[0x133d340]
    virtual int  GetRace(void);

    // address=[0x133d370]
    virtual int  GetRangeOfTower(enum BUILDING_TYPES a2);

    // address=[0x133d3e0]
    virtual int  GetGoodAmount(enum PILE_TYPES a2);

    // address=[0x133d440]
    virtual int  WorkerDeltaAmount(int a2);

    // address=[0x133d470]
    virtual int  GetSettlerAmount(enum SETTLER_TYPES a2);

    // address=[0x133d4d0]
    virtual int  GetBuildingAmount(enum BUILDING_TYPES a2);

    // address=[0x133d590]
    virtual int  GetBuildingIDs(enum BUILDING_TYPES a2, class std::vector<int,class std::allocator<int> > & a3);

    // address=[0x133d680]
    virtual int  GetResourceAmountAt(int a2, int a3, int a4);

    // address=[0x133d6e0]
    virtual int  GetResourceAmountAtAndAround(int a2, int a3, int a4);

    // address=[0x133d740]
    virtual bool  GetResourceCenterXY(int a2, int a3, int a4, int & a5, int & a6);

    // address=[0x133d8f0]
    virtual int  GetSingleResourceConcentrationAt(int a2, int a3, int a4);

    // address=[0x133da60]
    virtual int  GetSingleResourceConcentrationInside(int a2, class std::vector<struct SRESOURCECONCENTRATIONDATA,class std::allocator<struct SRESOURCECONCENTRATIONDATA> > & a3);

    // address=[0x133dbf0]
    virtual int  GetAroundResourceConcentrationInside(int a2, class std::vector<struct SRESOURCECONCENTRATIONDATA,class std::allocator<struct SRESOURCECONCENTRATIONDATA> > & a3);

    // address=[0x133dd70]
    virtual int  GetSingleResourceConcentrationOutside(int a2, class std::vector<struct SRESOURCECONCENTRATIONDATA,class std::allocator<struct SRESOURCECONCENTRATIONDATA> > & a3);

    // address=[0x133dee0]
    virtual int  GetAroundResourceConcentrationOutside(int a2, class std::vector<struct SRESOURCECONCENTRATIONDATA,class std::allocator<struct SRESOURCECONCENTRATIONDATA> > & a3);

    // address=[0x133e050]
    virtual bool  IsMyEcoSector(int a2, int a3);

    // address=[0x133e0b0]
    virtual bool  IsBorderElement(int a2, int a3);

    // address=[0x133e150]
    virtual bool  IsResourceAround(int a2, int a3, int a4, int a5);

    // address=[0x133e300]
    virtual bool  IsLandscapeAround(int a2, int a3, int a4, int a5);

    // address=[0x133e480]
    virtual bool  HasLand(int a2, int a3);

    // address=[0x133e4d0]
    virtual bool  HasLandAround(int a2, int a3);

    // address=[0x133e520]
    virtual bool  HasWater(int a2, int a3);

    // address=[0x133e570]
    virtual bool  HasWaterAround(int a2, int a3);

    // address=[0x133e5c0]
    virtual bool  HasRiver(int a2, int a3);

    // address=[0x133e610]
    virtual bool  HasRiverAround(int a2, int a3);

    // address=[0x133e660]
    virtual int  GetResourceAmountXY(int a2, int a3, int a4);

    // address=[0x133e6a0]
    virtual bool  HasLandscapeType(enum AI_ECO_LANDSCAPE_TYPE a1, int a2, int a3);

    // address=[0x133e790]
    virtual int  GetLandscapeAmount(int a2, int a3, int a4);

    // address=[0x133e7e0]
    virtual int  GetLandscapeConcentrationInside(int a2, class std::vector<struct SUNDERGROUNDCONCENTRATIONDATA,class std::allocator<struct SUNDERGROUNDCONCENTRATIONDATA> > & a3);

    // address=[0x133e960]
    virtual int  GetLandscapeConcentrationOutside(int a2, class std::vector<struct SUNDERGROUNDCONCENTRATIONDATA,class std::allocator<struct SUNDERGROUNDCONCENTRATIONDATA> > & a3);

    // address=[0x133eab0]
    virtual int  GetBorderElements(class std::vector<int,class std::allocator<int> > & a2);

    // address=[0x133ec00]
    virtual int  GetFirstRiverPos(int a2, int a3);

    // address=[0x133eca0]
    virtual int  ConvertTo(enum BUILDING_TYPES a2, enum IECONOMANAGERGRIDRESOLUTION a3, struct SBUILDINFODATA * a4, struct SBUILDINFODATA * a5);

    // address=[0x133eef0]
    virtual enum AI_ECOMANAGER_ERROR  SendProduceOrder(int a2, enum PILE_TYPES a3, int a4);

    // address=[0x133efd0]
    virtual enum AI_ECOMANAGER_ERROR  RecruteSpecialist(int a2, enum SETTLER_TYPES a3, int a4);

    // address=[0x133f0b0]
    virtual enum AI_ECOMANAGER_ERROR  SwitchBuildingStatus(int a2);

    // address=[0x133f1b0]
    virtual enum AI_ECOMANAGER_ERROR  SendNetMessage(int a2, int a3, int a4, int a5, int a6);

    // address=[0x133f310]
    virtual int  GetResidenceNeed(void);

    // address=[0x133f340]
    virtual int  GetResidenceSpace(void);

    // address=[0x133f370]
    virtual unsigned int  GetTickCount(void);

    // address=[0x133f390]
    virtual int  GetLastSpiralIndex(int a2);

    // address=[0x133f3b0]
    virtual void  GetSpiralDeltaOffset(int a2, int & a3, int & a4);

    // address=[0x133f3e0]
    virtual int  GetStoragePlace(int a2, int a3);

    // address=[0x133f470]
    virtual bool  CheckBuildingId(unsigned int a2);

    // address=[0x133f510]
    virtual int  GetMinimumCarrier(void);

    // address=[0x133f540]
    virtual void  SetMinimumCarrier(int a2);

    // address=[0x133f590]
    virtual int  GetMinimumCarrierForRecruitment(void);

    // address=[0x133f5c0]
    virtual void  SetMinimumCarrierForRecruitment(int a2);

    // address=[0x133f610]
    virtual class IConfigManager *  GetConfigManager(void);

    // address=[0x133f620]
    virtual class IAISectorAI *  GetSectorAI(void);

    // address=[0x133f640]
    virtual class IAIEventQueue *  GetEventQueue(void);

private:
    // address=[0x133f660]
    static int __cdecl AddRef(void);

    // address=[0x133f680]
    static int __cdecl Release(void);

    // address=[0x133f6a0]
    enum AI_ECOMANAGER_ERROR  CreateTree(enum BUILDING_TYPES a2, class CEcoManagerTree * & a3);

    // address=[0x133fea0]
    bool  WorkOnTile(enum BUILDING_TYPES a2, int a3, int a4, class CEcoManagerTree * a5);

    // address=[0x1340480]
    bool  IsMyTile(int SquareTile);

    // address=[0x13404e0]
    int  GetResourceAmountFast(int a1, int a2, int a3);

    // address=[0x1340510]
    int  GetDefaultUndergroundByRace(void);

    // address=[0x1340580]
    int  GetBuildingEcoSectorID(class CBuilding * a2);

    // address=[0x13405a0]
    bool  CanBeReachedByFisher(int a2, int a3);

    // address=[0x1340660]
    bool  CopyData(class CEcoManagerLeaf * a1, struct SBUILDINFODATA * a2);

    // address=[0x13467d0]
    bool  IsChecked(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x13468b0]
    void  ResetCheckField(enum BUILDING_TYPES a2);

    // address=[0x13468f0]
    void  SetChecked(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x3ecd4b8]
    static int m_iRefCounter;

};


#endif // CECOMANAGER_H
