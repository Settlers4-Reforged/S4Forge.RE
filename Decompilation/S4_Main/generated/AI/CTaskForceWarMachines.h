#ifndef CTASKFORCEWARMACHINES_H
#define CTASKFORCEWARMACHINES_H

class CTaskForceWarMachines : public CAITaskForceEx {
public:
    // address=[0x132a200]
     CTaskForceWarMachines(int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132a2e0]
    virtual  ~CTaskForceWarMachines(void);

    // address=[0x132c940]
    virtual bool  IsAddEntityOk(int);

    // address=[0x132c9a0]
    void  InitWarMachineWalk(bool);

    // address=[0x132ca20]
    int  CatapultSectorId(void)const;

    // address=[0x132caa0]
    int  CalculateBuildingDestination(int);

    // address=[0x132cb00]
    void  CheckBuildingDestination(void);

    // address=[0x132cbd0]
    virtual void  Execute(void);

};


#endif // CTASKFORCEWARMACHINES_H
