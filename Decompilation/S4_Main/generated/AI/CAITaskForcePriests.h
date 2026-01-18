#ifndef CAITASKFORCEPRIESTS_H
#define CAITASKFORCEPRIESTS_H

#include "defines.h"

class CAITaskForcePriests : public CAITaskForceEx {
public:
    // address=[0x132b400]
    virtual bool  NewCommand(int a2, int a3, int a4);

    // address=[0x132b480]
     CAITaskForcePriests(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132b4c0]
    virtual bool  IsAddEntityOk(int a2);

    // address=[0x132b500]
    virtual void  Execute(void);

    // address=[0x132b6f0]
    static class CAITaskForcePriests * __cdecl CreatePriestsTaskForce(int a1, int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132e610]
    virtual  ~CAITaskForcePriests(void);

};


#endif // CAITASKFORCEPRIESTS_H
