#ifndef CCATAPULT_H
#define CCATAPULT_H

class CCatapult : public CWheeler, public CWarriorBehavior {
public:
    // address=[0x153d480]
    virtual void  Delete(void);

    // address=[0x153d4a0]
    virtual void  VehicleLogicUpdate(void);

    // address=[0x153d590]
    virtual void  ConvertEventIntoGoal(class CEntityEvent *);

    // address=[0x153d840]
    virtual int  WarriorTaskWalkOneStep(class IMovingEntity &);

    // address=[0x153d8a0]
    virtual void  WarriorTaskAttack(class IMovingEntity &,int,enum T_WARRIOR_ATTACK);

    // address=[0x153d900]
    virtual void  WarriorTaskFinished(class IMovingEntity &);

    // address=[0x153da20]
    virtual int  WarriorTaskIdleWalk(class IMovingEntity &);

    // address=[0x153dae0]
    virtual void  EntityOrderCanceled(int);

    // address=[0x153db30]
    virtual void  GoodArrived(int,int);

    // address=[0x153dba0]
     CCatapult(std::istream &);

    // address=[0x153dcb0]
    virtual void  Store(std::ostream &);

    // address=[0x153dd30]
    void  RequestAmmoDonkey(void);

    // address=[0x153dd70]
    virtual int const  GetMeetingPointXY(enum OBJ_TYPE,int);

    // address=[0x153de60]
    virtual void  SupplyCanceled(int,int);

    // address=[0x153de80]
    virtual void  PostLoadInit(void);

protected:
    // address=[0x153dee0]
    virtual void  OnComeToFerry(int);

    // address=[0x153e000]
     CCatapult(int,int,int,int,int,int,bool);

    // address=[0x153e110]
    virtual  ~CCatapult(void);

    // address=[0x153e140]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x153e190]
    virtual void  TakeJob(void);

private:
    // address=[0x153e320]
    void  TakeAmmo(void);

    // address=[0x153e420]
    int  SearchForAmmo(void);

    // address=[0x153e530]
    int  GetAmmoDisplayID(void);

    // address=[0x153e700]
    int  GetHealthDisplayID(void);

    // address=[0x153e800]
    bool  AttackTargetAt(int,int);

    // address=[0x153e920]
    int  RequestDonkey(void);

    // address=[0x153fce0]
    virtual int const  AmmoPerPile(void);

    // address=[0x379bc1c]
    static int const AMMO_SCAN_RANGE;

    // address=[0x379bc64]
    static int const MAX_AMMO_FOR_VIKINKS;

};


#endif // CCATAPULT_H
