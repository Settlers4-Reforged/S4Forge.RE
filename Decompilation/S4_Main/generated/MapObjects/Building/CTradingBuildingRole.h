#ifndef CTRADINGBUILDINGROLE_H
#define CTRADINGBUILDINGROLE_H

#include "defines.h"

class CTradingBuildingRole : public IBuildingRole, public CAStarCallback {
public:
    // address=[0x1402480]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fdcb0]
    static class CTradingBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x151fb00]
     CTradingBuildingRole(void);

    // address=[0x151fca0]
    virtual  ~CTradingBuildingRole(void);

    // address=[0x151fd80]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x151ff10]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x1520000]
    virtual void  Init(class CBuilding * a2);

    // address=[0x15203b0]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x1520430]
    virtual void  Switch(void);

    // address=[0x15204c0]
    virtual void  NotifySelected(void);

    // address=[0x1520540]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x1520630]
    int  GetNumberOfFreePiles(void);

    // address=[0x15206b0]
    virtual void  GoodArrive(int a2);

    // address=[0x1520740]
    void  GoodLeft(int a2);

    // address=[0x1520750]
    void  ReservePileForGood(int a2, int a3);

    // address=[0x1520880]
    int  GetGoodSpaceAmount(int a2);

    // address=[0x15209e0]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x1520a10]
    void  VehicleArrived(int a2, int a3);

    // address=[0x1520a60]
    void  VehicleArrivedAtTarget(int a2, int a3);

    // address=[0x1520ab0]
    void  VehicleArriveCancel(int a2, int a3);

    // address=[0x1520b00]
    bool  IsPossibleTradeTarget(int a2);

    // address=[0x1520c90]
    void  SetTradeTarget(int a2);

    // address=[0x1520e10]
    int  GetTradeTargetID(void);

    // address=[0x1520e30]
    void  TransportGood(int a2, int a3);

    // address=[0x1521050]
    void  TradeWith(int a2);

    // address=[0x1521100]
    void  TradeGood(int a2);

    // address=[0x15212b0]
    void  ShowTradeRoute(void);

    // address=[0x1521500]
    void  ClearExpectedAmounts(int a2);

    // address=[0x15215c0]
    bool  IsRegisteredAsIncomingTrader(int a2, int a3);

    // address=[0x1521680]
    bool  RegisterIncomingTrader(int a2, int a3, bool a4);

    // address=[0x15216d0]
    bool  UnregisterIncomingTrader(int a2, int a3);

    // address=[0x15217d0]
    int  GetNrRegisteredIncomingTraders(int a2, bool a3);

    // address=[0x1521860]
    int  GetNextFreePile(void);

    // address=[0x15218f0]
    void  ExecuteUnforseenGoodTypeChange(int a2, int a3, int a4);

    // address=[0x1521990]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x1521d80]
    void  FillTradeSideBar(class CPortGoodsTradeBarInfo * a2, bool a3);

    // address=[0x1521f70]
    void  FillGoodsOutSideBar(class CPortGoodsOutBarInfo * a2, bool a3);

    // address=[0x15220a0]
    void  ChangeTradeStatus(int a2, bool a3);

    // address=[0x1522180]
    static void __cdecl PathCallback(int a1, int a2);

    // address=[0x15221c0]
     CTradingBuildingRole(std::istream & a2);

    // address=[0x1522660]
    virtual void  Store(std::ostream & a2);

    // address=[0x152bcc0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x152bd70]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x152bd90]
    virtual int  GetBuildingRole(void);

    // address=[0x3d8b7a4]
    static unsigned long m_iClassID;

private:
    // address=[0x15229a0]
    bool  CheckTransport(class CBuilding * a2, int a3);

    // address=[0x1522fe0]
    int  GetCurrentAmount(int a2);

    // address=[0x15230e0]
    int  GetRequestedAmount(int a2, bool a3);

    // address=[0x1523220]
    int  GetExpectedAmount(int a2, bool a3);

    // address=[0x1523330]
    int  GetExpectedAmountForAllPikes(int a2);

    // address=[0x1523400]
    int  GetGoodAmount(int a2);

    // address=[0x15234e0]
    int  GetExportGoodAmount(int a2);

    // address=[0x15235f0]
    int  GetExportResGoodAmount(int a2);

    // address=[0x1523700]
    void  CheckTradingStatus(void);

    // address=[0x1523780]
    void  CheckPiles(void);

    // address=[0x1523930]
    void  SetNewTraderTarget(int a2);

    // address=[0x1523b20]
    int  GetTargetBuildingAvailableSpace(int a2, int a3);

    // address=[0x1523b70]
    bool  RequestVehicle(class CBuilding * a2, bool a3);

    // address=[0x1523d60]
    bool  IsVehicleRequested(class CBuilding *,bool);

    // address=[0x1523e90]
    bool  IsVehicleAtBuilding(class CBuilding * a2);

    // address=[0x1523f50]
    void  LoadVehicle(void);

    // address=[0x1523fa0]
    bool  IsLoadingFinished(void);

    // address=[0x1524470]
    void  SendVehicle(void);

    // address=[0x15244c0]
    void  UnloadVehicle(void);

    // address=[0x1524510]
    void  TransportHandling(class CBuilding * a2);

    // address=[0x1524690]
    void  CancelIncomingChargeTraders(void);

    // address=[0x15248b0]
    void  CancelIncomingDeliverTraders(void);

    // address=[0x1524a20]
    void  CancelLoadingVehicle(void);

    // address=[0x1524b40]
    int  GetVehicleAtBuildingFreeSpaceGood(int a2);

    // address=[0x1524c00]
    int  GetVehicleAtBuildingFreeSpace(void);

    // address=[0x1524cb0]
    void  ClearRegisterTargetBuildings(void);

    // address=[0x1524d40]
    void  DeteachTradingBuilding(int a2);

    // address=[0x1524da0]
    void  SetTradingBuildingID(int a2);

    // address=[0x1524ea0]
    bool  RequestTradeShip(class CBuilding * a2, class CBuilding * a3, bool a4);

    // address=[0x15250e0]
    int  GetShipIDInHarbour(class CBuilding * a2);

    // address=[0x15251e0]
    bool  IsShipInHarbour(class CBuilding * a2);

    // address=[0x15252d0]
    bool  IsTradeShipInHarbour(class CBuilding *);

    // address=[0x15253a0]
    bool  IsShip(int a2);

    // address=[0x15253d0]
    void  StartLoadingShip(int a2);

    // address=[0x1525410]
    void  StartUnloadingShip(int a2);

    // address=[0x1525450]
    void  LoadShip(void);

    // address=[0x15258e0]
    void  SendShip(void);

    // address=[0x15259d0]
    void  UnloadShip(void);

    // address=[0x1525cc0]
    void  ShipArrived(int a2);

    // address=[0x1525d90]
    void  ShipArrivedAtTarget(int a2);

    // address=[0x1525da0]
    void  ShipArriveCancel(int a2);

    // address=[0x1525dc0]
    bool  IsShipRequested(void);

    // address=[0x1525df0]
    bool  RequestDonkey(class CBuilding * a2, class CBuilding * a3, bool a4);

    // address=[0x1525ff0]
    bool  IsDonkeyAtBuilding(class CBuilding *);

    // address=[0x15260d0]
    int  GetDonkeyIDAtBuilding(class CBuilding * a2);

    // address=[0x15261b0]
    void  StartLoadingDonkey(int a2);

    // address=[0x1526230]
    void  StartUnloadingDonkey(int a2);

    // address=[0x15262b0]
    void  LoadDonkey(void);

    // address=[0x1526730]
    void  SendDonkey(void);

    // address=[0x1526800]
    void  UnloadDonkey(void);

    // address=[0x1526b20]
    void  DonkeyArrived(int a2);

    // address=[0x1526c10]
    void  DonkeyArrivedAtTarget(int a2);

    // address=[0x1526c20]
    void  DonkeyArriveCancel(int a2);

    // address=[0x1526c60]
    bool  RequestCart(class CBuilding * a2, class CBuilding * a3, bool a4);

    // address=[0x1526f10]
    bool  IsCartAtBuilding(class CBuilding *);

    // address=[0x1526f40]
    int  GetCartIDAtBuilding(class CBuilding * a2);

    // address=[0x1527040]
    void  StartLoadingCart(int a2);

    // address=[0x1527080]
    void  StartUnloadingCart(int a2);

    // address=[0x15270c0]
    void  LoadCart(void);

    // address=[0x15272e0]
    void  SendCart(void);

    // address=[0x15274c0]
    void  UnloadCart(void);

    // address=[0x1527720]
    void  CartArrived(int a2);

    // address=[0x15277c0]
    void  CartArrivedAtTarget(int a2);

    // address=[0x15277d0]
    void  CartArriveCancel(int a2);

    // address=[0x15277f0]
    int  AddGood(int a2, int a3, bool a4);

    // address=[0x1527be0]
    int  GetNrDeliveryPilesOfGood(int a2);

    // address=[0x1527cc0]
    int  CalcNrExportGoods(bool a2);

    // address=[0x1527df0]
    int  GetPileIDWithGoodToTransport(void);

    // address=[0x1527ec0]
    int  CalcNrAvaibleGood(bool a2);

    // address=[0x1527f20]
    virtual bool  CrushBuilding(void);

    // address=[0x1527fd0]
    virtual void  ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3);

    // address=[0x1528020]
    int  DetermineTransportType(void);

    // address=[0x1528150]
    int  GetTargetBuildingID(bool a2);

    // address=[0x1528180]
    void  StartLoadIntTraderDonkey(int a2);

    // address=[0x1528300]
    void  StartLoadIntTraderShip(int a2);

    // address=[0x15283d0]
    void  ReserveExportPile(int a2, int a3, int a4);

    // address=[0x15284b0]
    void  ReserveImportPile(int a2);

    // address=[0x1528560]
    int  CalcExportedGoods(void);

    // address=[0x15285f0]
    int  GetTotalExportedGoodAmount(class CBuilding * a2);

    // address=[0x15287e0]
    void  DisableTranding(void);

    // address=[0x15289e0]
    int const  GetMaxTradingGoodAmount(void);

    // address=[0x15289f0]
    void  RequestTradingGood(enum PILE_TYPES a2);

    // address=[0x1528ab0]
    bool  CheckTradingTransport(class CBuilding * a2, int a3);

    // address=[0x1528d00]
    void  ClearTradingPiles(int a2, enum TGOOD_STATUS a3);

    // address=[0x1528e30]
    void  SetGoodState(int a2, enum TGOOD_STATUS a3);

    // address=[0x1528e70]
    void  ClearGoodState(int a2, enum TGOOD_STATUS a3);

    // address=[0x1528ea0]
    bool  HasGoodState(int a2, enum TGOOD_STATUS a3);

    // address=[0x1528ee0]
    enum TGOOD_STATUS  GetTradingStatus(int a1);

    // address=[0x152bd30]
    int  GetBuildingID(void);

    // address=[0x152bed0]
    virtual bool  TryCrushBuilding(void);

    // address=[0x40f22bc]
    static int m_iLastX;

    // address=[0x40f22c0]
    static int m_iLastY;

};


#endif // CTRADINGBUILDINGROLE_H
