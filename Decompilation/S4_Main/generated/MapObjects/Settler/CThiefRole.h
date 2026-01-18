#ifndef CTHIEFROLE_H
#define CTHIEFROLE_H

#include "defines.h"

class CThiefRole : public ISelectableSettlerRole {
public:
    // address=[0x14022a0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1588940]
    static class CThiefRole * __cdecl Load(std::istream & a1);

    // address=[0x1592e30]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1592e70]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1593050]
    virtual void  LogicUpdate(class CSettler * a2);

    // address=[0x15930a0]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x1593160]
    virtual void  PostLoadInit(class CSettler * a2);

    // address=[0x15931e0]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x1593240]
     CThiefRole(std::istream & a2);

    // address=[0x1593370]
    virtual void  Store(std::ostream & a2);

    // address=[0x1594890]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15948b0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x3d8bfa8]
    static unsigned long m_iClassID;

private:
    // address=[0x1593590]
     CThiefRole(void);

    // address=[0x1593610]
    virtual  ~CThiefRole(void);

    // address=[0x1593640]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x1593680]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1593b40]
    virtual void  Init(class CSettler * a2);

    // address=[0x1593c00]
    bool  CheckGoodInSurrounding(class CSettler * a2);

    // address=[0x1593da0]
    bool  IsAllyOwner(class CSettler * a2, int a3);

    // address=[0x1593e10]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

};


#endif // CTHIEFROLE_H
