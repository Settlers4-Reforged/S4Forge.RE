#ifndef CFREEWORKERROLE_H
#define CFREEWORKERROLE_H

#include "defines.h"

class CFreeWorkerRole : public ISettlerRole {
public:
    // address=[0x1400ae0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x156dc10]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x156dc50]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x156e4c0]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x156e690]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x156e6b0]
     CFreeWorkerRole(std::istream & a2);

    // address=[0x156e7f0]
    virtual void  Store(std::ostream & a2);

    // address=[0x156ffc0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x156ffe0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588600]
    static class CFreeWorkerRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bec0]
    static unsigned long m_iClassID;

private:
    // address=[0x156e890]
     CFreeWorkerRole(void);

    // address=[0x156e8e0]
    virtual  ~CFreeWorkerRole(void);

    // address=[0x156e900]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x156e940]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x156f1e0]
    virtual void  Init(class CSettler * a2);

    // address=[0x156f220]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x156f520]
    int  CheckResource(class CSettler * a2, int a3);

    // address=[0x156f5b0]
    int  CheckSpaceForPlant(class CSettler * a1);

    // address=[0x156f670]
    virtual bool  SetFree(class CSettler * a2, int a3);

};


#endif // CFREEWORKERROLE_H
