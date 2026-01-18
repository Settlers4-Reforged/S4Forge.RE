#ifndef CWARSHIP_H
#define CWARSHIP_H

#include "defines.h"

class CWarShip : public CShip, public CWarriorBehavior {
public:
    // address=[0x14028e0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15a09e0]
    virtual int  WarriorTaskWalkOneStep(class IMovingEntity & a2);

    // address=[0x15a0a40]
    virtual void  WarriorTaskAttack(class IMovingEntity & a2, int a3, enum T_WARRIOR_ATTACK a4);

    // address=[0x15a0aa0]
    virtual void  WarriorTaskFinished(class IMovingEntity & a2);

    // address=[0x15a0ac0]
    virtual int  WarriorTaskIdleWalk(class IMovingEntity & a2);

    // address=[0x15a0b20]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x15a0b40]
    static void __cdecl operator delete(void * a1);

    // address=[0x15a0b80]
    virtual void  ConvertEventIntoGoal(class CEntityEvent * a2);

    // address=[0x15a0c30]
     CWarShip(std::istream & a2);

    // address=[0x15a0d60]
    virtual void  Store(std::ostream & a2);

    // address=[0x15a2720]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bfe0]
    static unsigned long m_iClassID;

protected:
    // address=[0x15a0df0]
     CWarShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

    // address=[0x15a0ed0]
    virtual  ~CWarShip(void);

    // address=[0x15a0f00]
    virtual void  VehicleLogicUpdate(void);

    // address=[0x15a0fe0]
    virtual void  TakeJob(void);

    // address=[0x15a1240]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

private:
    // address=[0x15a1290]
    int  GetAmmoDisplayID(void);

    // address=[0x15a1450]
    bool  AttackTargetAt(int a2, int a3);

    // address=[0x15a1570]
    void  TakeAmmo(void);

    // address=[0x15a1650]
    int  SearchForAmmo(void);

    // address=[0x15a2680]
    virtual int const  AmmoPerPile(void);

    // address=[0x37bdf08]
    static int const AMMO_SCAN_RANGE;

};


#endif // CWARSHIP_H
