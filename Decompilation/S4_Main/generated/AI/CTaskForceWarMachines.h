#ifndef CTASKFORCEWARMACHINES_H
#define CTASKFORCEWARMACHINES_H

#include "defines.h"

class CTaskForceWarMachines : public CAITaskForceEx {
public:
    // address=[0x132a200]
     CTaskForceWarMachines(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132a2e0]
    virtual  ~CTaskForceWarMachines(void);

    // address=[0x132c940]
    virtual bool  IsAddEntityOk(int a2);

    // address=[0x132c9a0]
    void  InitWarMachineWalk(bool a2);

    // address=[0x132ca20]
    int  CatapultSectorId(void)const;

    // address=[0x132caa0]
    int  CalculateBuildingDestination(int a2);

    // address=[0x132cb00]
    void  CheckBuildingDestination(void);

    // address=[0x132cbd0]
    virtual void  Execute(void);

};


#endif // CTASKFORCEWARMACHINES_H
