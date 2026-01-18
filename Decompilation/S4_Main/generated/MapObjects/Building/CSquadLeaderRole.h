#ifndef CSQUADLEADERROLE_H
#define CSQUADLEADERROLE_H

#include "defines.h"

class CSquadLeaderRole : public CSoldierRole {
public:
    // address=[0x1402020]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1575bb0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1575bf0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1575c20]
    virtual bool  IsHJB(void);

    // address=[0x1592380]
    virtual void  Init(class CSettler * a2);

    // address=[0x15923d0]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x1592420]
    virtual void  WarriorInit(class IMovingEntity & a2, int a3, int a4);

    // address=[0x15929d0]
     CSquadLeaderRole(std::istream & a2);

    // address=[0x1592ac0]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8bfa4]
    static unsigned long m_iClassID;

protected:
    // address=[0x1575ab0]
    virtual  ~CSquadLeaderRole(void);

    // address=[0x1592470]
    virtual int  WarriorTaskWalkOneStep(class IMovingEntity & a2);

    // address=[0x15925a0]
    virtual int  WarriorTaskIdleWalk(class IMovingEntity & a2);

    // address=[0x15925d0]
    virtual void  WarriorTaskAttack(class IMovingEntity & a2, int a3, enum T_WARRIOR_ATTACK a4);

    // address=[0x1592600]
    virtual void  WarriorTaskFinished(class IMovingEntity & a2);

    // address=[0x1592b50]
     CSquadLeaderRole(void);

private:
    // address=[0x1592620]
    void  CommandGroupMembers(class IMovingEntity & a2);

    // address=[0x1592b20]
    static class CSquadLeaderRole * __cdecl Load_HACK_VERSION(std::istream & a1);

};


#endif // CSQUADLEADERROLE_H
