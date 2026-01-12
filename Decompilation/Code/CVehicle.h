#ifndef CVEHICLE_H
#define CVEHICLE_H

class CVehicle : public IMovingEntity {
public:
    // address=[0x1351ab0]
    int  CurrentTask(void)const;

    // address=[0x153a430]
    virtual void  CountCargo(class ICargoCounter &);

    // address=[0x153fda0]
    virtual void  DeleteSelectable(void);

    // address=[0x153fe70]
    virtual void  SetSelectable(void);

    // address=[0x159e900]
    virtual int const  GetMeetingPointXY(enum OBJ_TYPE,int);

    // address=[0x15a3c70]
    int  Loading(void)const;

    // address=[0x15a3c80]
    virtual void  PostLoadInit(void);

    // address=[0x15a3ce0]
    virtual void  AddToWarMap(void);

    // address=[0x15a3d10]
    virtual void  GoodIsComming(int,int);

    // address=[0x15a3d20]
    virtual void  EntityOrderCanceled(int);

    // address=[0x15a3d30]
    virtual void  EntityEnter(int);

    // address=[0x15a3d40]
    virtual void  GoodArrived(int,int);

    // address=[0x15a3d50]
    virtual void  SupplyCanceled(int,int);

    // address=[0x15a3d60]
    virtual void  Delete(void);

    // address=[0x15a3e80]
    void  FireMissile(int,int);

    // address=[0x15a4130]
    void  Update(void);

    // address=[0x15a4340]
    virtual void  LogicUpdate(void);

    // address=[0x15a4400]
    virtual void  VehicleLogicUpdate(void);

    // address=[0x15a44b0]
    virtual bool  IsUnEmployed(void)const;

    // address=[0x15a4500]
    virtual void  IncreaseAmmo(int);

    // address=[0x15a4560]
    int  BuildingProgress(void);

    // address=[0x15a4610]
    void  InitBuildingSite(void);

    // address=[0x15a4730]
    virtual void  OnBuildReady(void);

    // address=[0x15a4a20]
    bool  NeedForBuildingMaterial(int);

    // address=[0x15a4a70]
    void  AddBuildingMaterial(int);

    // address=[0x15a4b30]
    virtual void  Attach(int);

    // address=[0x15a4b60]
    virtual void  Detach(int);

    // address=[0x15a4b90]
    virtual void  Notify(class CEntityEvent const &)const;

    // address=[0x15a4bb0]
    virtual void  Decrease(int);

    // address=[0x15a4c80]
    virtual int  GetGroupFlags(void)const;

    // address=[0x15a4ca0]
    virtual int  SetGroupFlagBits(int);

    // address=[0x15a4d00]
    virtual int  ClearGroupFlagBits(int);

    // address=[0x15a7a40]
    virtual void  FillDialog(bool);

protected:
    // address=[0x153a460]
    class CEntityTask *  GetCurrentTaskPtr(void);

    // address=[0x153a530]
    bool  IsTurning(void)const;

    // address=[0x153a620]
    unsigned int  TurnDirEx(void)const;

    // address=[0x153fe00]
    bool  ReadyToFire(unsigned int)const;

    // address=[0x153fe40]
    void  RegisterNewTask(unsigned int,unsigned int);

    // address=[0x153fe90]
    unsigned int  TurnCounter(void)const;

    // address=[0x15a4d60]
     CVehicle(int,int,int,int,int,int,bool);

    // address=[0x15a5160]
    virtual  ~CVehicle(void);

    // address=[0x15a51a0]
     CVehicle(std::istream &);

    // address=[0x15a54a0]
    virtual void  Store(std::ostream &);

    // address=[0x15a57a0]
    virtual void  GetTurnGfxInfo(void);

    // address=[0x15a5850]
    unsigned int  InitTurn(int);

    // address=[0x15a5960]
    unsigned int  TurnVehicle(unsigned int);

    // address=[0x15a5a00]
    void  TakeJobPart(unsigned int);

    // address=[0x15a5a80]
    bool  NewDestination(int,int,int);

    // address=[0x15a5dc0]
    void  GetNextJob(void);

    // address=[0x15a5e30]
    void  DetachWithoutNotify(int);

    // address=[0x15a5e50]
    void  SetReadyToFireTick(unsigned int);

    // address=[0x15a5e70]
    virtual bool  EnoughAmmo(void)const;

    // address=[0x15a5ea0]
    virtual unsigned int  AmmoAmount(void)const;

    // address=[0x15a5ec0]
    virtual void  DecreaseAmmo(void);

    // address=[0x15a5ef0]
    void  AttackTarget(int);

    // address=[0x15a6040]
    void  WalkDirAndRegister(int,bool);

    // address=[0x15a61a0]
    void  InitCommonTaskValues(class CEntityTask const *);

    // address=[0x15a6250]
    virtual void  ConvertEventIntoGoal(class CEntityEvent *);

    // address=[0x15a6300]
    void  MoveTo(int,int,int);

    // address=[0x15a7a20]
    static bool __cdecl CallTakeJob(void);

    // address=[0x15a7a30]
    static void __cdecl ClearCallTakeJob(void);

    // address=[0x15a7ae0]
    bool  IsMoving(void)const;

    // address=[0x15a7b20]
    static void __cdecl NotifyCallTakeJob(bool);

    // address=[0x15a7b40]
    void  RegisterNewTaskAndTakeJobPartIfNecessary(unsigned int,unsigned int,unsigned int);

    // address=[0x15a7be0]
    void  TakeJobPartIfNecessary(unsigned int);

    // address=[0x4158cfe]
    static bool m_bCallTakeJob;

private:
    // address=[0x153a570]
    virtual void  NotifyDetach(int);

};


#endif // CVEHICLE_H
