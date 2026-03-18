#ifndef CAITASKFORCESQUAD_H
#define CAITASKFORCESQUAD_H

#include "defines.h"

class CAITaskForceSquad : public CAITaskForceEx {
public:
    // address=[0x13192f0]
    virtual  ~CAITaskForceSquad(void);

    // address=[0x132bfc0]
     CAITaskForceSquad(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132c020]
    virtual void  Execute(void);

    // address=[0x132c3c0]
    virtual bool  NewCommand(int a2, int a3, int a4);

    // address=[0x132c580]
    virtual enum CAITaskForce::T_RESULT  AddEntity(class CAIEntityInfo * a2, enum CAITaskForce::T_POSITION a3);

    // address=[0x132c660]
    virtual enum CAITaskForce::T_RESULT  RemoveEntity(class CAIEntityInfo * a2);

    // address=[0x132c7f0]
    virtual void  RemoveAllEntities(void);

    // address=[0x132c830]
    virtual int  NumberOfEntities(enum T_AI_WARRIOR_TYPE a2)const;

};


#endif // CAITASKFORCESQUAD_H
