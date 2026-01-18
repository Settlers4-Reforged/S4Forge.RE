#ifndef CPIONEERROLE_H
#define CPIONEERROLE_H

#include "defines.h"

class CPioneerRole : public ISelectableSettlerRole {
public:
    // address=[0x1401620]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15796d0]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1579710]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1579880]
    virtual void  PostLoadInit(class CSettler * a2);

    // address=[0x15798f0]
     CPioneerRole(std::istream & a2);

    // address=[0x1579a50]
    virtual void  Store(std::ostream & a2);

    // address=[0x157b220]
    virtual unsigned long  ClassID(void)const;

    // address=[0x157b240]
    virtual int  GetSettlerRole(void)const;

    // address=[0x15887c0]
    static class CPioneerRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bef0]
    static unsigned long m_iClassID;

private:
    // address=[0x1579cb0]
     CPioneerRole(void);

    // address=[0x1579d50]
    virtual  ~CPioneerRole(void);

    // address=[0x1579e70]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x1579eb0]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x157a330]
    virtual void  Init(class CSettler * a2);

    // address=[0x157a3c0]
    void  WorkIsDone(class CSettler * a2);

    // address=[0x157a410]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x157a8b0]
    bool  SearchPosition(class CSettler * a2);

    // address=[0x157aaa0]
    bool  CheckLand(int a2, int a3, class CSettler * a4, bool a5);

    // address=[0x157abe0]
    void  TakeLand(class CSettler * a2);

};


#endif // CPIONEERROLE_H
