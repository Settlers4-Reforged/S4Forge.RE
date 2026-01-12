#ifndef CTRANSPORTSHIP_H
#define CTRANSPORTSHIP_H

class CTransportShip : public CShip {
public:
    // address=[0x1402520]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x152bdd0]
    enum TIntTraderState  CTransportShip::GetTradingState(void);

    // address=[0x152be30]
    bool  IsNeutralTrader(void);

    // address=[0x152beb0]
    void  MemHomePosition(void);

    // address=[0x159e950]
    virtual void  FillDialog(bool);

    // address=[0x159ea50]
    int  GetGoodAmount(int);

    // address=[0x159eab0]
    int  AddGood(int,int);

    // address=[0x159ec10]
    int  RemoveGood(int,int);

    // address=[0x159ed00]
    bool  IsSpaceAvailable(int);

    // address=[0x159ed70]
    int  GetAvailableSpace(int);

    // address=[0x159edf0]
    int  GetAvailableSpace(void);

    // address=[0x159ee40]
    bool  IsFull(void);

    // address=[0x159ef20]
    bool  HasLoadedSomething(void);

    // address=[0x159ef70]
    bool  HasLoadGood(enum PILE_TYPES);

    // address=[0x159efd0]
    void  SetTargetHarbourID(int);

    // address=[0x159eff0]
    int  GetTargetHarbourID(void);

    // address=[0x159f010]
    void  TargetHarbourDestroyed(void);

    // address=[0x159f120]
    void  SetDepartHarbourID(int);

    // address=[0x159f140]
    int  GetDepartHarbourID(void);

    // address=[0x159f160]
    void  DepartHarbourDestroyed(void);

    // address=[0x159f1e0]
    void  DestroyShip(void);

    // address=[0x159f1f0]
    void  ShipArrived(void);

    // address=[0x159f340]
    void  MoveToTarget(void);

    // address=[0x159f3e0]
    void  SetFree(void);

    // address=[0x159f410]
    void  DropGoods(void);

    // address=[0x159f470]
    void  TryToGoHome(void);

    // address=[0x159f4f0]
    void  GoToHomeTradingBuilding(void);

    // address=[0x159f5e0]
    void  SetHomeID(int);

    // address=[0x159f6a0]
    void  SetJobType(int);

    // address=[0x159f6c0]
    int  GetJobType(void);

    // address=[0x159f6e0]
    void  SetGoToSource(bool);

    // address=[0x159f700]
    void  SetGoToTarget(bool);

    // address=[0x159f720]
    virtual void  VehicleLogicUpdate(void);

    // address=[0x159f8b0]
    virtual void  ConvertEventIntoGoal(class CEntityEvent *);

    // address=[0x159f910]
    virtual void  TakeJob(void);

    // address=[0x159f940]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x159f980]
    void  SetNeutralTraderStatus(bool);

    // address=[0x159fa30]
    void  ClearNeutralTraderStatus(void);

    // address=[0x159fa60]
    static void * __cdecl operator new(unsigned int);

    // address=[0x159fa80]
    static void __cdecl operator delete(void *);

    // address=[0x159fac0]
     CTransportShip(std::istream &);

    // address=[0x15a0060]
    virtual void  Store(std::ostream &);

    // address=[0x15a09c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bfdc]
    static unsigned long m_iClassID;

protected:
    // address=[0x15a01e0]
     CTransportShip(int,int,int,int,int,int,bool);

    // address=[0x15a02d0]
    virtual  ~CTransportShip(void);

};


#endif // CTRANSPORTSHIP_H
