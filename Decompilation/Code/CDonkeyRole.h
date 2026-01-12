#ifndef CDONKEYROLE_H
#define CDONKEYROLE_H

class CDonkeyRole : public ISettlerRole {
public:
    // address=[0x1400540]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x152bdb0]
    enum TIntTraderState  CDonkeyRole::GetTradingState(void);

    // address=[0x152be10]
    bool  IsNeutralTrader(void);

    // address=[0x152be70]
    void  MemHomePosition(void);

    // address=[0x1569d40]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x1569d80]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x156a0d0]
    virtual void  UpdateJob(class CSettler *);

    // address=[0x156a130]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x156a150]
    void  InitFlee(class CSettler *,int);

    // address=[0x156a160]
    virtual int  Decrease(int);

    // address=[0x156a1e0]
    void  NextStep(void);

    // address=[0x156a220]
    int  GetGoodAmount(int);

    // address=[0x156a280]
    int  AddGood(int,int);

    // address=[0x156a400]
    int  RemoveGood(int,int);

    // address=[0x156a520]
    bool  IsSpaceAvailable(int);

    // address=[0x156a590]
    int  GetAvailableSpace(int);

    // address=[0x156a600]
    int  GetAvailableSpace(void);

    // address=[0x156a650]
    bool  IsFull(void);

    // address=[0x156a700]
    bool  HasLoadedSomething(void);

    // address=[0x156a740]
    void  DropGoods(class CSettler *);

    // address=[0x156a7f0]
    bool  SetFree(void);

    // address=[0x156a870]
    bool  HasLoadGood(enum PILE_TYPES);

    // address=[0x156a8c0]
    void  SetTargetBuildingID(int);

    // address=[0x156a8e0]
    int  GetTargetBuildingID(void);

    // address=[0x156a900]
    void  TargetBuildingDestroyed(void);

    // address=[0x156aa30]
    void  SetDepartBuildingID(int);

    // address=[0x156aa50]
    int  GetDepartBuildingID(void);

    // address=[0x156aa70]
    void  DepartBuildingDestroyed(void);

    // address=[0x156ab10]
    void  DonkeyArrived(void);

    // address=[0x156ae00]
    void  MoveToTarget(int,int);

    // address=[0x156ae70]
    int  OwnerId(void);

    // address=[0x156aed0]
    void  UpdateCatapultPosition(int);

    // address=[0x156af40]
    void  ComeToBuildUpCart(int,int);

    // address=[0x156b000]
    void  SetJobType(int);

    // address=[0x156b080]
    int  GetJobType(void);

    // address=[0x156b0a0]
    void  SetGoToSource(bool);

    // address=[0x156b0c0]
    void  SetGoToTarget(bool);

    // address=[0x156b0e0]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x156b120]
    virtual void  FillDialog(bool);

    // address=[0x156b210]
    void  SetNeutralTraderStatus(bool);

    // address=[0x156b2d0]
    void  ClearNeutralTraderStatus(void);

    // address=[0x156b2f0]
    void  TryToGoHome(void);

    // address=[0x156b3c0]
    void  GoToHomeTradingBuilding(void);

    // address=[0x156b4b0]
     CDonkeyRole(std::istream &);

    // address=[0x156b770]
    virtual void  Store(std::ostream &);

    // address=[0x156cdf0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x156ce10]
    virtual int  GetSettlerRole(void)const;

    // address=[0x156ce30]
    virtual bool  IsUnEmployed(void)const;

    // address=[0x1588540]
    static class CDonkeyRole * __cdecl Load(std::istream &);

    // address=[0x3d8beb4]
    static unsigned long m_iClassID;

private:
    // address=[0x156b950]
     CDonkeyRole(void);

    // address=[0x156ba30]
    virtual  ~CDonkeyRole(void);

    // address=[0x156ba50]
    virtual void  TakeJob(class CSettler *);

    // address=[0x156bdd0]
    virtual void  Init(class CSettler *);

    // address=[0x156be90]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

};


#endif // CDONKEYROLE_H
