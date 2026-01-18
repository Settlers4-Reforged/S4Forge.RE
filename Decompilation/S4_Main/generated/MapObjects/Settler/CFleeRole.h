#ifndef CFLEEROLE_H
#define CFLEEROLE_H

#include "defines.h"

class CFleeRole : public ISettlerRole {
public:
    // address=[0x1400a40]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x156d370]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x156d3b0]
    virtual void  LogicUpdate(class CSettler * a2);

    // address=[0x156d730]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x156d740]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x156d760]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x156d770]
    virtual bool  ESChanged(class CSettler * a2);

    // address=[0x156d780]
     CFleeRole(std::istream & a2);

    // address=[0x156d830]
    virtual void  Store(std::ostream & a2);

    // address=[0x156dbc0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x156dbe0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x156dc00]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x15885c0]
    static class CFleeRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bebc]
    static unsigned long m_iClassID;

private:
    // address=[0x156d870]
     CFleeRole(void);

    // address=[0x156d890]
    virtual  ~CFleeRole(void);

    // address=[0x156d8b0]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x156d8d0]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x156d910]
    virtual void  Init(class CSettler * a2);

    // address=[0x156d9b0]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

};


#endif // CFLEEROLE_H
