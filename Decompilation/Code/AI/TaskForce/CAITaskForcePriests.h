#ifndef CAITASKFORCEPRIESTS_H
#define CAITASKFORCEPRIESTS_H

class CAITaskForcePriests : public CAITaskForceEx {
public:
    // address=[0x132b400]
    virtual bool  NewCommand(int,int,int);

    // address=[0x132b480]
     CAITaskForcePriests(int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132b4c0]
    virtual bool  IsAddEntityOk(int);

    // address=[0x132b500]
    virtual void  Execute(void);

    // address=[0x132b6f0]
    static class CAITaskForcePriests * __cdecl CreatePriestsTaskForce(int,int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132e610]
    virtual  ~CAITaskForcePriests(void);

};


#endif // CAITASKFORCEPRIESTS_H
