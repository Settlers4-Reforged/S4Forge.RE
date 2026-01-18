#ifndef CCART_H
#define CCART_H

#include "defines.h"

class CCart : public CWheeler {
public:
    // address=[0x1400040]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x152bdf0]
    bool  IsNeutralTrader(void);

    // address=[0x152be50]
    void  MemHomePosition(void);

    // address=[0x1530b60]
    virtual void  Delete(void);

    // address=[0x1530c20]
    virtual bool  IsUnEmployed(void)const;

    // address=[0x1530c60]
    virtual void  Detach(int a2);

    // address=[0x1530c90]
    virtual int const  GetMeetingPointXY(enum OBJ_TYPE a2, int a3);

    // address=[0x1530d90]
    virtual int const  GetFrontMeetingPointXY(enum OBJ_TYPE a2, int a3);

    // address=[0x1530e80]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x1531040]
    virtual void  FillDialog(bool a2);

    // address=[0x1531270]
    virtual void  VehicleLogicUpdate(void);

    // address=[0x15313e0]
    virtual void  EntityEnter(int a2);

    // address=[0x1531620]
    virtual void  EntityOrderCanceled(int a2);

    // address=[0x1531810]
    virtual void  GoodIsComming(int a2, int a3);

    // address=[0x15318b0]
    virtual void  GoodArrived(int a2, int a3);

    // address=[0x15319c0]
    virtual void  SupplyCanceled(int a2, int a3);

    // address=[0x1531ac0]
    bool  CreateFoundationCart(void);

    // address=[0x1531ed0]
    bool  CreateNormalCart(void);

    // address=[0x1531fe0]
    bool  CreateSettlement(void);

    // address=[0x1532030]
    virtual void  ConvertEventIntoGoal(class CEntityEvent *);

    // address=[0x15320b0]
    virtual void  Decrease(int a2);

    // address=[0x1532120]
    int  GetGoodAmount(int a2);

    // address=[0x1532180]
    int  AddGood(int a2, int a3);

    // address=[0x1532340]
    int  RemoveGood(int a2, int a3);

    // address=[0x1532450]
    bool  IsSpaceAvailable(int a2);

    // address=[0x15324c0]
    int  GetAvailableSpace(int a2);

    // address=[0x1532540]
    int  GetAvailableSpace(void);

    // address=[0x1532590]
    bool  IsFull(void);

    // address=[0x15325f0]
    bool  HasLoadedSomething(void);

    // address=[0x15326f0]
    void  SetTargetBuildingID(int a2);

    // address=[0x1532710]
    int  GetTargetBuildingID(void);

    // address=[0x1532730]
    void  TargetBuildingDestroyed(void);

    // address=[0x1532860]
    void  SetDepartBuildingID(int a2);

    // address=[0x1532880]
    int  GetDepartBuildingID(void);

    // address=[0x15328a0]
    void  DepartBuildingDestroyed(void);

    // address=[0x1532920]
    void  CartArrived(void);

    // address=[0x1532a30]
    void  MoveToTarget(void);

    // address=[0x1532ad0]
    void  TryToGoHome(void);

    // address=[0x1532bb0]
    void  SetJobType(int a2);

    // address=[0x1532bf0]
    int  GetJobType(void);

    // address=[0x1532c10]
    void  SetGoToSource(bool a2);

    // address=[0x1532c30]
    void  SetGoToTarget(bool a2);

    // address=[0x1532c50]
    void  SetNeutralTraderStatus(bool a2);

    // address=[0x1532c70]
    void  ClearNeutralTraderStatus(void);

    // address=[0x1532c90]
    virtual void  OnBuildReady(void);

    // address=[0x1532e30]
    void  DonkeyArrived(int a2);

    // address=[0x1532f10]
    virtual void  SetSelectable(void);

    // address=[0x1533030]
    virtual void  DeleteSelectable(void);

    // address=[0x15335c0]
     CCart(std::istream & a2);

    // address=[0x1533af0]
    virtual void  Store(std::ostream & a2);

    // address=[0x153a410]
    virtual unsigned long  ClassID(void)const;

    // address=[0x153a650]
    virtual void  UnloadToPosition(int a2);

    // address=[0x3d8b834]
    static unsigned long m_iClassID;

protected:
    // address=[0x1533070]
     CCart(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

    // address=[0x1533280]
    virtual  ~CCart(void);

    // address=[0x15332e0]
    virtual void  TakeJob(void);

    // address=[0x15333a0]
    void  SetFree(void);

    // address=[0x15333d0]
    void  DropGoods(void);

    // address=[0x1533490]
    virtual void  GetTurnGfxInfo(void);

    // address=[0x1533560]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x1533580]
    static void __cdecl operator delete(void * a1);

private:
    // address=[0x1533f10]
    void  ChangeToFoundationCart(void);

    // address=[0x15342f0]
    bool  OnRequestSettlers(void);

    // address=[0x1534640]
    bool  OnRequestCargo(void);

    // address=[0x1534720]
    bool  OnUnload(void);

    // address=[0x1534740]
    bool  UnLoadSettler(void);

    // address=[0x15349d0]
    bool  UnLoadCargo(void);

    // address=[0x1534ad0]
    bool  CanTakeLand(void);

    // address=[0x1534bb0]
    void  TakeLand(void);

    // address=[0x1534c70]
    bool  OnDestroyFoundationCart(void);

    // address=[0x1534cd0]
    bool  HasEnoughGoodToCreateFoundationCart(void);

    // address=[0x1534d80]
    bool  WeAreWaitFor(int a2);

    // address=[0x1534e50]
    bool  IsPioner(int a2);

    // address=[0x1534ec0]
    bool  IsCarrier(int a2);

    // address=[0x1534f30]
    bool  CanWalk(void);

    // address=[0x1534fa0]
    void  KillAllLoadedSettlers(void);

    // address=[0x153a4b0]
    bool  IsOnOwnEcoSector(void);

    // address=[0x40f22c8]
    static class CStaticConfigVarInt m_iAmountOfPioneers;

    // address=[0x40f22d4]
    static class CStaticConfigVarInt m_iAmountOfCarrier;

    // address=[0x40f22e0]
    static class CStaticConfigVarInt m_iAmountOfBoard;

    // address=[0x40f22ec]
    static class CStaticConfigVarInt m_iAmountOfStone;

    // address=[0x40f22f8]
    static class CStaticConfigVarInt m_iAmountOfHammer;

    // address=[0x40f2304]
    static class CStaticConfigVarInt m_iAmountOfRecycledBoard;

};


#endif // CCART_H
