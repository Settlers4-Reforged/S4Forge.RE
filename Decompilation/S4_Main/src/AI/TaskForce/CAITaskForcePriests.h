#ifndef CAITASKFORCEPRIESTS_H
#define CAITASKFORCEPRIESTS_H

#include "defines.h"
#include "AI/CAITaskForceEx.h"

class CAITaskForcePriests : public CAITaskForceEx {
public:
    // address=[0x132b400]
    virtual bool NewCommand(int a2, int a3, int a4);

    // address=[0x132b480]
    CAITaskForcePriests(int iOwnerId, T_AI_TASK_FORCE_TYPE tType, int iFlags);

    // address=[0x132b4c0]
    virtual bool IsAddEntityOk(int a2);

    // address=[0x132b500]
    virtual void Execute(void);

    // address=[0x132b6f0]
    static class CAITaskForcePriests * __cdecl CreatePriestsTaskForce(int _iRace, int _iOwnerId, enum T_AI_TASK_FORCE_TYPE _tType, int _iFlags);

    // address=[0x132e610]
    virtual ~CAITaskForcePriests(void);

    virtual int ChooseMilitarySpell(struct SCountFightersResult const &a2, int a3) = 0;

    virtual int ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5) = 0;

protected:
    int __cdecl ChooseNextSpellType(int _iNumber1, int a2, int _iNumber2, int a4, int _iNumber3, int a6, int a7, int a8);

    // Type information members
public:
    int m_uNextSpellTick;
};


#endif // CAITASKFORCEPRIESTS_H
