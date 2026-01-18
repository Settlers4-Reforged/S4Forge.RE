#ifndef CDOORROLE_H
#define CDOORROLE_H

#include "defines.h"

class CDoorRole : public ISettlerRole {
public:
    // address=[0x14005e0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x156ce70]
    virtual void  LogicUpdate(class CSettler * a2);

    // address=[0x156cef0]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x156cf40]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x156cfd0]
    virtual int  Decrease(int a2);

    // address=[0x156d020]
     CDoorRole(std::istream & a2);

    // address=[0x156d0d0]
    virtual void  Store(std::ostream & a2);

    // address=[0x156d2b0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x156d2d0]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x156d2f0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x156d310]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x156d330]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1588580]
    static class CDoorRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8beb8]
    static unsigned long m_iClassID;

private:
    // address=[0x156d110]
    virtual void  Init(class CSettler * a2);

    // address=[0x156d240]
    virtual  ~CDoorRole(void);

    // address=[0x156d2e0]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x156d360]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1587a50]
     CDoorRole(void);

};


#endif // CDOORROLE_H
