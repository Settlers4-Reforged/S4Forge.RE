#ifndef CHUNTERROLE_H
#define CHUNTERROLE_H

#include "defines.h"

class CHunterRole : public ISettlerRole {
public:
    // address=[0x1400f40]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1577280]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x15772c0]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x15777f0]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x1577860]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x1577880]
     CHunterRole(std::istream & a2);

    // address=[0x1577940]
    virtual void  Store(std::ostream & a2);

    // address=[0x1578790]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15787d0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588740]
    static class CHunterRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bee8]
    static unsigned long m_iClassID;

private:
    // address=[0x1577990]
    virtual  ~CHunterRole(void);

    // address=[0x15779b0]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x15779f0]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1577e00]
    virtual void  Init(class CSettler * a2);

    // address=[0x1577e20]
    void  GoHomeEmpty(class CSettler * a2);

    // address=[0x1577eb0]
    void  HarvestDeadAnimal(class CSettler * a2);

    // address=[0x1577f80]
    bool  AreWeChasing(class CSettler *);

    // address=[0x1578010]
    int  GetVictimPosition(void);

    // address=[0x1578080]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x15782d0]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x1587ad0]
     CHunterRole(void);

};


#endif // CHUNTERROLE_H
