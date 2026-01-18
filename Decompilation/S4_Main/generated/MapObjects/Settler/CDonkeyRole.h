#ifndef CDONKEYROLE_H
#define CDONKEYROLE_H

#include "defines.h"

class CDonkeyRole : public ISettlerRole {
public:
    // address=[0x1400540]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x152bdb0]
    enum TIntTraderState  CDonkeyRole::GetTradingState(void);

    // address=[0x152be10]
    bool  IsNeutralTrader(void);

    // address=[0x152be70]
    void  MemHomePosition(void);

    // address=[0x1569d40]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1569d80]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x156a0d0]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x156a130]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x156a150]
    void  InitFlee(class CSettler * a2, int a3);

    // address=[0x156a160]
    virtual int  Decrease(int a2);

    // address=[0x156a1e0]
    void  NextStep(void);

    // address=[0x156a220]
    int  GetGoodAmount(int a2);

    // address=[0x156a280]
    int  AddGood(int a2, int a3);

    // address=[0x156a400]
    int  RemoveGood(int a2, int a3);

    // address=[0x156a520]
    bool  IsSpaceAvailable(int a2);

    // address=[0x156a590]
    int  GetAvailableSpace(int a2);

    // address=[0x156a600]
    int  GetAvailableSpace(void);

    // address=[0x156a650]
    bool  IsFull(void);

    // address=[0x156a700]
    bool  HasLoadedSomething(void);

    // address=[0x156a740]
    void  DropGoods(class CSettler * a2);

    // address=[0x156a7f0]
    bool  SetFree(void);

    // address=[0x156a870]
    bool  HasLoadGood(enum PILE_TYPES a2);

    // address=[0x156a8c0]
    void  SetTargetBuildingID(int a2);

    // address=[0x156a8e0]
    int  GetTargetBuildingID(void);

    // address=[0x156a900]
    void  TargetBuildingDestroyed(void);

    // address=[0x156aa30]
    void  SetDepartBuildingID(int a2);

    // address=[0x156aa50]
    int  GetDepartBuildingID(void);

    // address=[0x156aa70]
    void  DepartBuildingDestroyed(void);

    // address=[0x156ab10]
    void  DonkeyArrived(void);

    // address=[0x156ae00]
    void  MoveToTarget(int a2, int a3);

    // address=[0x156ae70]
    int  OwnerId(void);

    // address=[0x156aed0]
    void  UpdateCatapultPosition(int a2);

    // address=[0x156af40]
    void  ComeToBuildUpCart(int a2, int a3);

    // address=[0x156b000]
    void  SetJobType(int a2);

    // address=[0x156b080]
    int  GetJobType(void);

    // address=[0x156b0a0]
    void  SetGoToSource(bool a2);

    // address=[0x156b0c0]
    void  SetGoToTarget(bool a2);

    // address=[0x156b0e0]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x156b120]
    virtual void  FillDialog(bool a2);

    // address=[0x156b210]
    void  SetNeutralTraderStatus(bool a2);

    // address=[0x156b2d0]
    void  ClearNeutralTraderStatus(void);

    // address=[0x156b2f0]
    void  TryToGoHome(void);

    // address=[0x156b3c0]
    void  GoToHomeTradingBuilding(void);

    // address=[0x156b4b0]
     CDonkeyRole(std::istream & a2);

    // address=[0x156b770]
    virtual void  Store(std::ostream & a2);

    // address=[0x156cdf0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x156ce10]
    virtual int  GetSettlerRole(void)const;

    // address=[0x156ce30]
    virtual bool  IsUnEmployed(void)const;

    // address=[0x1588540]
    static class CDonkeyRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8beb4]
    static unsigned long m_iClassID;

private:
    // address=[0x156b950]
     CDonkeyRole(void);

    // address=[0x156ba30]
    virtual  ~CDonkeyRole(void);

    // address=[0x156ba50]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x156bdd0]
    virtual void  Init(class CSettler * a2);

    // address=[0x156be90]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

};


#endif // CDONKEYROLE_H
