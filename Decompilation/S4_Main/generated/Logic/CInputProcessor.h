#ifndef CINPUTPROCESSOR_H
#define CINPUTPROCESSOR_H

#include "defines.h"

class CInputProcessor : public IEventHandler {
public:
    // address=[0x1439c90]
    static class std::vector<unsigned short,class std::allocator<unsigned short> > const & __cdecl Selection(void);

    // address=[0x1454f10]
     CInputProcessor(void);

    // address=[0x1454fd0]
    virtual  ~CInputProcessor(void);

    // address=[0x1455040]
    void  Reset(void);

    // address=[0x14550e0]
    void  Process(void);

    // address=[0x1455280]
    void  DeSelectAllEx(void);

    // address=[0x14552b0]
    void  DeSelectEntity(int a2);

    // address=[0x1455440]
    void  AddToSelection(int a1);

    // address=[0x14554d0]
    int  GetSelectionTypeOfCurrentSelection(void)const;

    // address=[0x1455520]
    static int __cdecl GetEntitySelectionType(int a1, int a2, int a3);

    // address=[0x14555b0]
    static int __cdecl GetEntitySelectionType(class IEntity const * a1);

    // address=[0x1455600]
    static int __cdecl GetEntitySelectionType(int a1);

    // address=[0x146ad70]
    bool  IsChooseSecondPatrolPosState(void);

    // address=[0x146adb0]
    bool  IsTryBuildState(void);

    // address=[0x146ae00]
    bool  IsWorkingAreaState(void);

    // address=[0x146ae40]
    bool  IsZoomAreaState(void);

    // address=[0x14e4ac0]
    bool  BoxSelectAllSettler(void)const;

    // address=[0x14e4bd0]
    int  StrictSelection(void)const;

    // address=[0x14eb4b0]
    bool  IsBoxSelection(void)const;

    // address=[0x3f1f6b4]
    static class std::vector<unsigned short,class std::allocator<unsigned short> > m_vSelection;

protected:
    // address=[0x1455640]
    void  InitFSM(void);

    // address=[0x14563d0]
    virtual void  FillHandlersArray(void);

    // address=[0x1456ac0]
    bool  HandleInternalError(class CEvn_Logic * a2);

    // address=[0x1456ae0]
    bool  Default(class CEvn_Logic * a2);

    // address=[0x1456c10]
    bool  NewDialogClear(class CEvn_Logic * a2);

    // address=[0x1456c50]
    bool  ClearDialog(class CEvn_Logic * a2);

    // address=[0x1456c70]
    bool  TryBuild(class CEvn_Logic * a2);

    // address=[0x1456ce0]
    bool  Build(class CEvn_Logic * a2);

    // address=[0x1456e30]
    bool  ShowWorkingArea(class CEvn_Logic * a2);

    // address=[0x1456ed0]
    bool  SetWorkingArea(class CEvn_Logic * a2);

    // address=[0x1457020]
    bool  TryCrushBuilding(class CEvn_Logic * a2);

    // address=[0x14570a0]
    bool  CrushBuilding(class CEvn_Logic * a2);

    // address=[0x14571a0]
    bool  SwitchBuilding(class CEvn_Logic * a2);

    // address=[0x1457270]
    bool  PrioBuildingSite(class CEvn_Logic * a2);

    // address=[0x1457340]
    bool  SelectNextBuilding(class CEvn_Logic * a2);

    // address=[0x1457550]
    bool  SelectBuilding(class CEvn_Logic * a2);

    // address=[0x1457760]
    bool  MarkNextBuilding(class CEvn_Logic * a2);

    // address=[0x1457850]
    bool  InitExtraMenu(class CEvn_Logic * a2);

    // address=[0x1457890]
    bool  SelectNextVehicle(class CEvn_Logic * a2);

    // address=[0x1457b80]
    bool  BuildingAmount(class CEvn_Logic * a2);

    // address=[0x1457bf0]
    bool  DestroyBuildupVehicle(class CEvn_Logic * a2);

    // address=[0x1457d40]
    bool  FillTower(class CEvn_Logic * a2);

    // address=[0x1457e20]
    bool  EmptyTower(class CEvn_Logic * a2);

    // address=[0x1457f10]
    bool  ChooseTradeDest(class CEvn_Logic * a2);

    // address=[0x1457f60]
    bool  SelectTradeDest(class CEvn_Logic * a2);

    // address=[0x1458160]
    bool  TransportGoods(class CEvn_Logic * a2);

    // address=[0x1458250]
    bool  TradeWith(class CEvn_Logic * a2);

    // address=[0x1458340]
    bool  TradeGoods(class CEvn_Logic * a2);

    // address=[0x1458420]
    bool  SetTradePlayerStatus(class CEvn_Logic * a2);

    // address=[0x1458540]
    bool  ChooseSpellDest(class CEvn_Logic * a2);

    // address=[0x1458560]
    bool  SelectSpellDest(class CEvn_Logic * a2);

    // address=[0x1458770]
    bool  InitSettlerAmount(class CEvn_Logic * a2);

    // address=[0x14587c0]
    bool  InitFreeCarrier(class CEvn_Logic * a2);

    // address=[0x1458810]
    bool  InitSettlerProduction(class CEvn_Logic * a2);

    // address=[0x1458860]
    bool  InitSettlerSearch(class CEvn_Logic * a2);

    // address=[0x1458920]
    bool  InitGoodAmount(class CEvn_Logic * a2);

    // address=[0x1458970]
    bool  InitTransportPrio(class CEvn_Logic * a2);

    // address=[0x14589c0]
    bool  InitGoodDistribution(class CEvn_Logic * a2);

    // address=[0x1458a10]
    bool  GoodDeliveringChanged(class CEvn_Logic * a2);

    // address=[0x1458d90]
    bool  TransportPrioChanged(class CEvn_Logic * a2);

    // address=[0x1458ec0]
    bool  UnitProduction(class CEvn_Logic * a2);

    // address=[0x1458fb0]
    bool  UrgentProduction(class CEvn_Logic * a2);

    // address=[0x14590a0]
    bool  WeaponPercent(class CEvn_Logic * a2);

    // address=[0x1459180]
    bool  WeaponAutoproduction(class CEvn_Logic * a2);

    // address=[0x1459260]
    bool  StorageGoodSwitch(class CEvn_Logic * a2);

    // address=[0x1459350]
    bool  VehicleProduction(class CEvn_Logic * a2);

    // address=[0x1459440]
    bool  GotoVehicleGroupMenu(class CEvn_Logic * a2);

    // address=[0x1459540]
    bool  SwitchLocalGlobal(class CEvn_Logic * a2);

    // address=[0x1459590]
    bool  SpecialistProduction(class CEvn_Logic * a2);

    // address=[0x1459690]
    bool  PrepareBoxSelection(class CEvn_Logic * a2);

    // address=[0x1459860]
    bool  DotSelection(class CEvn_Logic * a2);

    // address=[0x1459b70]
    bool  SelectTypeInSurrounding(class CEvn_Logic * a2);

    // address=[0x1459c50]
    bool  SelectGroup(class CEvn_Logic * a2);

    // address=[0x1459df0]
    bool  GroupToSelection(class CEvn_Logic * a1);

    // address=[0x1459e00]
    bool  DefineGroup(class CEvn_Logic * a2);

    // address=[0x1459fd0]
    bool  FocusGroup(class CEvn_Logic * a2);

    // address=[0x145a1a0]
    bool  SendTo(class CEvn_Logic * a2);

    // address=[0x145a410]
    bool  ForceGoto(class CEvn_Logic * a2);

    // address=[0x145a420]
    bool  StandGround(class CEvn_Logic * a2);

    // address=[0x145a450]
    bool  ChooseSecondPatrolPos(class CEvn_Logic * a2);

    // address=[0x145a480]
    bool  SelectSecondPatrolPos(class CEvn_Logic * a2);

    // address=[0x145a4e0]
    bool  InjuredOut(class CEvn_Logic * a2);

    // address=[0x145a6e0]
    bool  MorphToCarrier(class CEvn_Logic * a2);

    // address=[0x145a860]
    bool  SearchUnit(class CEvn_Logic * a2);

    // address=[0x145af70]
    bool  UnitReservation(class CEvn_Logic * a2);

    // address=[0x145b070]
    bool  InitEconomyGameMenu(class CEvn_Logic * a2);

    // address=[0x145b0b0]
    bool  InitMagicSideBar(class CEvn_Logic * a2);

    // address=[0x145b100]
    bool  InitGroupSideBar(class CEvn_Logic * a2);

    // address=[0x145b140]
    bool  InitAddSoldierSideBar(class CEvn_Logic * a2);

    // address=[0x145b1a0]
    bool  InitToolSideBar(class CEvn_Logic * a2);

    // address=[0x145b200]
    bool  InitWeaponSideBar(class CEvn_Logic * a2);

    // address=[0x145b260]
    bool  InitGoodsOutSideBar(class CEvn_Logic * a2);

    // address=[0x145b2c0]
    bool  InitTradeSideBar(class CEvn_Logic * a2);

    // address=[0x145b320]
    bool  InitStorageSideBar(class CEvn_Logic * a2);

    // address=[0x145b380]
    bool  InitEyeCatcherSideBar(class CEvn_Logic * a2);

    // address=[0x145b3c0]
    bool  InitAddVehicleSideBar(class CEvn_Logic * a2);

    // address=[0x145b420]
    bool  CloseSideBar(class CEvn_Logic * a1);

    // address=[0x145b440]
    bool  Morph2FoundationCart(class CEvn_Logic * a2);

    // address=[0x145b540]
    bool  CreateSettlement(class CEvn_Logic * a2);

    // address=[0x145b630]
    bool  Morph2Cart(class CEvn_Logic * a2);

    // address=[0x145b740]
    bool  VehicleUnload(class CEvn_Logic * a2);

    // address=[0x145b8f0]
    bool  CatapultLoad(class CEvn_Logic * a2);

    // address=[0x145baa0]
    bool  DestroyWarMachine(class CEvn_Logic * a2);

    // address=[0x145bbb0]
    bool  ZoomAreaState(class CEvn_Logic * a2);

    // address=[0x145bbd0]
    bool  CamSelection(class CEvn_Logic * a2);

    // address=[0x145be00]
    void  TraceStates(class CEvn_Logic const & a2);

    // address=[0x145be70]
    void  BoxSelection(void);

    // address=[0x145c080]
    int  SelectOne(int x, int y);

    // address=[0x145c390]
    int  GetTheBestEntity(class std::vector<unsigned short,class std::allocator<unsigned short> > & a1, int a2, int a3);

    // address=[0x145c590]
    int  SelectAllInSurrounding(int a2, int a3);

    // address=[0x145c790]
    bool  SelectAtSector(enum SETTLER_TYPES a1, int a2);

    // address=[0x145c8e0]
    int  GetUserESInMiddleOfTheScreen(void);

    // address=[0x145c9d0]
    void  RemoveActiveSettler(int a2, int a3);

    // address=[0x145c9e0]
    void  ActivateSpecialist(int a1, int a2);

    // address=[0x145ca50]
    void  WorkOnBuildingSites(void);

    // address=[0x145cb30]
    bool  GetPossibleBuildingSites(int a2, int a3, bool a4);

    // address=[0x145cdd0]
    bool  UpdateScreenPossibleBuildingSites(int a2, int a3, int a4);

    // address=[0x145d060]
    void  ShowPossibleBuildingType(void);

    // address=[0x145d3f0]
    void  DeSelectAll(void);

    // address=[0x145d4b0]
    void  RequestDialog(void);

    // address=[0x145d880]
    bool  Clear(void);

    // address=[0x145d950]
    void  TidyUp(void);

    // address=[0x145da20]
    void  CloseSidebarAndShowDefaultMenu(void);

    // address=[0x145dad0]
    void  SelectAllVisible(void);

    // address=[0x14604b0]
    bool  EmptyFunct(class CEvn_Logic * a2);

    // address=[0x14e4b00]
    int  GetSelectionType(void)const;

    // address=[0x14e4b60]
    void  NewCandidate(int a2);

    // address=[0x14e4bb0]
    void  SetSelectionType(int a2);

    // address=[0x3f1f328]
    static struct SGfxObject m_sGfxObj;

};


#endif // CINPUTPROCESSOR_H
