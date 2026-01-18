#ifndef CSOLDIERROLE_H
#define CSOLDIERROLE_H

#include "defines.h"

class CSoldierRole : public ISelectableSettlerRole, public CWarriorBehavior {
public:
    // address=[0x1401f80]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1588900]
    static class CSoldierRole * __cdecl Load(std::istream & a1);

    // address=[0x158e510]
    virtual class CWalking *  InitWalking(class CSettler * a2);

    // address=[0x158e540]
    virtual void  LogicUpdateJob(class CSettler * a2);

    // address=[0x158ebc0]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x158ed00]
    virtual int  WarriorTaskWalkOneStep(class IMovingEntity & a2);

    // address=[0x158ed40]
    virtual void  WarriorTaskAttack(class IMovingEntity & a2, int a3, enum T_WARRIOR_ATTACK a4);

    // address=[0x158f1a0]
    virtual void  WarriorTaskFinished(class IMovingEntity & a2);

    // address=[0x158f1e0]
    virtual int  WarriorTaskIdleWalk(class IMovingEntity & a2);

    // address=[0x158f250]
    virtual bool  SetFree(class CSettler * a2, int a3);

    // address=[0x158f390]
    virtual void  PostLoadInit(class CSettler * a2);

    // address=[0x158f5c0]
    void  CheckToDoList(void);

    // address=[0x158f700]
    virtual class CWarriorBehavior *  GetWarriorBehavior(void);

    // address=[0x158f730]
    virtual int  GetKindOfSelection(class CSettler * a2)const;

    // address=[0x158f7e0]
     CSoldierRole(std::istream & a2);

    // address=[0x158fa60]
    virtual void  Store(std::ostream & a2);

    // address=[0x1592140]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15921e0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x15afa00]
    int  GetNumberOfHealings(void);

    // address=[0x3d8bfa0]
    static unsigned long m_iClassID;

protected:
    // address=[0x158fd10]
     CSoldierRole(void);

    // address=[0x158fdc0]
    virtual  ~CSoldierRole(void);

    // address=[0x158fe10]
    void  SoldierMagicIdleWalk(class CSettler * a2);

    // address=[0x158fed0]
    virtual void  GetNextJob(class CSettler * a2);

    // address=[0x1590040]
    virtual void  TakeJob(class CSettler * a2);

    // address=[0x1590680]
    virtual void  Init(class CSettler * a2);

    // address=[0x1590740]
    virtual void  ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3);

    // address=[0x1590f40]
    void  ComeToWork(class CSettler * a2, int a3);

    // address=[0x1591100]
    bool  NewDestinationEx(class CSettler * a2, int a3, int a4, int a5);

    // address=[0x1591450]
    void  EvaluateWalkAndRegister(class IMovingEntity & a2, int a3);

    // address=[0x1592280]
    void  SoldierWarriorLogicUpdate(class CSettler * a2);

    // address=[0x4158c98]
    static class CStaticConfigVarInt s_iMaxNumberOfHealings;

    // address=[0x4158ca4]
    static class CStaticConfigVarInt s_iTicksToRegeneration;

};


#endif // CSOLDIERROLE_H
