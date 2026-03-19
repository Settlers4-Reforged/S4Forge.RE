#ifndef CAITASKFORCEPRIESTS_H
#define CAITASKFORCEPRIESTS_H

#include "defines.h"

class CAITaskForcePriests : public CAITaskForceEx {
public:
    // address=[0x132b400]
    virtual bool  NewCommand(int a2, int a3, int a4);

    // address=[0x132b480]
     CAITaskForcePriests(int iOwnerId, enum T_AI_TASK_FORCE_TYPE tType, int iFlags);

    // address=[0x132b4c0]
    virtual bool  IsAddEntityOk(int a2);

    // address=[0x132b500]
    virtual void  Execute(void);

    // address=[0x132b6f0]
    static class CAITaskForcePriests * __cdecl CreatePriestsTaskForce(int iRace, int iOwnerId, enum T_AI_TASK_FORCE_TYPE tType, int iFlags);

    // address=[0x132e610]
    virtual  ~CAITaskForcePriests(void);

    // Type information members
public:
    int m_uNextSpellTick;

};


#endif // CAITASKFORCEPRIESTS_H
