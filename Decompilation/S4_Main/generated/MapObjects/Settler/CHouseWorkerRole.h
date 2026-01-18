#ifndef CHOUSEWORKERROLE_H
#define CHOUSEWORKERROLE_H

#include "defines.h"

class CHouseWorkerRole : public ISettlerRole {
public:
    // address=[0x1400ea0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1575c50]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1575c90]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x15762a0]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x1576430]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x1576450]
     CHouseWorkerRole(std::istream & a2);

    // address=[0x1576520]
    virtual void  Store(std::ostream & a2);

    // address=[0x1577220]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1577260]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588700]
    static class CHouseWorkerRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bee4]
    static unsigned long m_iClassID;

private:
    // address=[0x1576580]
    virtual  ~CHouseWorkerRole(void);

    // address=[0x15765a0]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x15765e0]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1576b00]
    virtual void  Init(class CSettler * a2);

    // address=[0x1576b30]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x1587a80]
     CHouseWorkerRole(void);

};


#endif // CHOUSEWORKERROLE_H
