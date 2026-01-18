#ifndef CHJBROLE_H
#define CHJBROLE_H

#include "defines.h"

class CHJBRole : public CSquadLeaderRole {
public:
    // address=[0x1400e00]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1574e20]
     CHJBRole(std::istream & a2);

    // address=[0x1574f10]
    virtual void  Store(std::ostream & a2);

    // address=[0x1575030]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1575310]
    virtual int  Decrease(int a2);

    // address=[0x1575b90]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1575c10]
    virtual bool  IsHJB(void);

    // address=[0x15886c0]
    static class CHJBRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bee0]
    static unsigned long m_iClassID;

protected:
    // address=[0x1574dd0]
     CHJBRole(void);

    // address=[0x1574f70]
    virtual void  PostLoadInit(class CSettler * a2);

    // address=[0x15753b0]
    int  FindNewHJBPosition(class CSettler * a2);

    // address=[0x15755d0]
    int  FindNearFreePositionInSector(int a2, int a3, int a4);

    // address=[0x15756a0]
    void  ExecuteAttackSpell(class CSettler * a2, int a3, int a4);

    // address=[0x1575a80]
    virtual  ~CHJBRole(void);

};


#endif // CHJBROLE_H
