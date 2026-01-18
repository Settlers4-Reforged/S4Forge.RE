#ifndef CTOWERSOLDIER_H
#define CTOWERSOLDIER_H

#include "defines.h"

class CTowerSoldier : public ISettlerRole {
public:
    // address=[0x1402340]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15139d0]
    int  GetSlot(void)const;

    // address=[0x1588980]
    static class CTowerSoldier * __cdecl Load(std::istream & a1);

    // address=[0x15948d0]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1594910]
    virtual void  LogicUpdate(class CSettler * a2);

    // address=[0x1594ef0]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x1594f00]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x1594f50]
    void  SetTowerInfo(int a2, enum CTowerSoldier::T_TOWER_POSITION a3, int a4);

    // address=[0x1595000]
    virtual int  Decrease(int a2);

    // address=[0x1595030]
     CTowerSoldier(std::istream & a2);

    // address=[0x1595140]
    virtual void  Store(std::ostream & a2);

    // address=[0x15962c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15962e0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1596300]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x3d8bfac]
    static unsigned long m_iClassID;

protected:
    // address=[0x15951e0]
    static int __cdecl SearchDoorGuardTarget(int a1, int a2);

    // address=[0x15953a0]
    static int __cdecl SearchBowmanTarget(int a1, int a2);

private:
    // address=[0x15956a0]
     CTowerSoldier(void);

    // address=[0x15956f0]
    virtual  ~CTowerSoldier(void);

    // address=[0x1595710]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x1595750]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1595830]
    virtual void  Init(class CSettler * a2);

    // address=[0x15958d0]
    void  SearchEnemy(class CSettler * a2);

    // address=[0x1595920]
    bool  GetAttacker(class CSettler * a2, int a3);

    // address=[0x15959e0]
    void  WorkIsDone(class CSettler * a2);

    // address=[0x1595a20]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

};


#endif // CTOWERSOLDIER_H
