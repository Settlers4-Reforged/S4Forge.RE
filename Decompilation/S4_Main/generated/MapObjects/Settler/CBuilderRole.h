#ifndef CBUILDERROLE_H
#define CBUILDERROLE_H

#include "defines.h"

class CBuilderRole : public ISettlerRole {
public:
    // address=[0x13ffc80]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1562d90]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x1562dd0]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1562ec0]
    virtual void  PostLoadInit(class CSettler * a1);

    // address=[0x1562ee0]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x1562ff0]
     CBuilderRole(std::istream & a2);

    // address=[0x15630c0]
    virtual void  Store(std::ostream & a2);

    // address=[0x15637b0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1563820]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1563960]
    void  SetDir(char a2);

    // address=[0x1588440]
    static class CBuilderRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bea4]
    static unsigned long m_iClassID;

private:
    // address=[0x1563120]
     CBuilderRole(void);

    // address=[0x1563150]
    virtual  ~CBuilderRole(void);

    // address=[0x1563170]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x15631b0]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x15632c0]
    virtual void  Init(class CSettler * a2);

    // address=[0x1563340]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

};


#endif // CBUILDERROLE_H
