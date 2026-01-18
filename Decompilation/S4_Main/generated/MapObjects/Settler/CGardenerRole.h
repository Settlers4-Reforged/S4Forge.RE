#ifndef CGARDENERROLE_H
#define CGARDENERROLE_H

#include "defines.h"

class CGardenerRole : public ISelectableSettlerRole {
public:
    // address=[0x1400b80]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1570050]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1570090]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1570280]
    virtual void  PostLoadInit(class CSettler * a2);

    // address=[0x15702f0]
     CGardenerRole(std::istream & a2);

    // address=[0x1570480]
    virtual void  Store(std::ostream & a2);

    // address=[0x1572060]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1572080]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588640]
    static class CGardenerRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bec4]
    static unsigned long m_iClassID;

private:
    // address=[0x1570700]
     CGardenerRole(void);

    // address=[0x1570770]
    virtual  ~CGardenerRole(void);

    // address=[0x1570820]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x1570860]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1570e50]
    virtual void  Init(class CSettler * a2);

    // address=[0x1570ed0]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x1571440]
    void  WorkIsDone(class CSettler * a2);

    // address=[0x1571490]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x1571520]
    bool  CheckPosition(int a2, int a3, int a4, bool a5);

    // address=[0x1571710]
    bool  SearchPosition(class CSettler * a2, int a3);

};


#endif // CGARDENERROLE_H
