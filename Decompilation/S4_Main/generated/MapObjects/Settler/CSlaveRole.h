#ifndef CSLAVEROLE_H
#define CSLAVEROLE_H

#include "defines.h"

class CSlaveRole : public ISettlerRole {
public:
    // address=[0x1401e40]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15888c0]
    static class CSlaveRole * __cdecl Load(std::istream & a1);

    // address=[0x158caa0]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x158cae0]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x158cbd0]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x158ccf0]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x158cd10]
    void  InitFlee(class CSettler * a2, int a3);

    // address=[0x158cd20]
    virtual bool  IsUnEmployed(void)const;

    // address=[0x158cd60]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x158ce30]
    virtual bool  ESChanged(class CSettler * a2);

    // address=[0x158ce40]
     CSlaveRole(std::istream & a2);

    // address=[0x158cf30]
    virtual void  Store(std::ostream & a2);

    // address=[0x158e470]
    virtual unsigned long  ClassID(void)const;

    // address=[0x158e4b0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x3d8bf9c]
    static unsigned long m_iClassID;

private:
    // address=[0x158cfa0]
     CSlaveRole(void);

    // address=[0x158cfe0]
    virtual  ~CSlaveRole(void);

    // address=[0x158d000]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x158d040]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x158d3f0]
    virtual void  Init(class CSettler * a2);

    // address=[0x158d430]
    virtual bool  SearchPosition(class CSettler * a2);

    // address=[0x158d700]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x158dca0]
    void  SetWorkPositionAndFlag(int a2, int a3);

    // address=[0x158dd90]
    void  ClearWorkPositionAndFlagIfNecessary(void);

    // address=[0x158deb0]
    void  FreeServant(class CSettler * a2);

    // address=[0x158e4d0]
    bool  WorkPositionValid(void);

};


#endif // CSLAVEROLE_H
