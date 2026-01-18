#ifndef CMUSHROOMFARMERROLE_H
#define CMUSHROOMFARMERROLE_H

#include "defines.h"

class CMushroomFarmerRole : public ISettlerRole {
public:
    // address=[0x14014e0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15787f0]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1578830]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1578a30]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x1578b00]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x1578b20]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x1578ba0]
    virtual bool  ESChanged(class CSettler * a2);

    // address=[0x1578bb0]
     CMushroomFarmerRole(std::istream & a2);

    // address=[0x1578c80]
    virtual void  Store(std::ostream & a2);

    // address=[0x1579690]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15796b0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588780]
    static class CMushroomFarmerRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8beec]
    static unsigned long m_iClassID;

private:
    // address=[0x1578cd0]
     CMushroomFarmerRole(void);

    // address=[0x1578d00]
    virtual  ~CMushroomFarmerRole(void);

    // address=[0x1578d20]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x1578d60]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1579050]
    virtual void  Init(class CSettler * a1);

    // address=[0x1579070]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

};


#endif // CMUSHROOMFARMERROLE_H
