#ifndef CCARRIERROLE_H
#define CCARRIERROLE_H

#include "defines.h"

class CCarrierRole : public ISettlerRole {
public:
    // address=[0x13fffa0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1563a30]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1563a70]
    virtual void  LogicUpdate(class CSettler * a2);

    // address=[0x1563b90]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1564340]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x1564420]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x1564440]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET a2, int a3);

    // address=[0x15644e0]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET a2);

    // address=[0x1564550]
    void  UpdateCatapultPosition(int a2);

    // address=[0x15645c0]
     CCarrierRole(std::istream & a2);

    // address=[0x15647e0]
    virtual void  Store(std::ostream & a2);

    // address=[0x1567060]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15670c0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588480]
    static class CCarrierRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bea8]
    static unsigned long m_iClassID;

private:
    // address=[0x15648b0]
    virtual int  GetNextSettlerType(void);

    // address=[0x15648d0]
    virtual bool  SetNextSettlerType(int a2);

    // address=[0x15648f0]
    void  ChangeToNextType(class CSettler * a2, bool a3, bool a4);

    // address=[0x15649c0]
     CCarrierRole(void);

    // address=[0x1564a80]
    virtual  ~CCarrierRole(void);

    // address=[0x1564aa0]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x1564af0]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1565510]
    virtual void  Init(class CSettler * a2);

    // address=[0x1565660]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x1566220]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x15664c0]
    void  TryToGoHome(class CSettler * a2);

    // address=[0x1567080]
    int  DestinationPileId(void)const;

    // address=[0x1567120]
    int  NextSettlerType(void);

    // address=[0x1567160]
    int  SourcePileId2(void)const;

    // address=[0x1567180]
    int  SourcePileId3(void)const;

};


#endif // CCARRIERROLE_H
