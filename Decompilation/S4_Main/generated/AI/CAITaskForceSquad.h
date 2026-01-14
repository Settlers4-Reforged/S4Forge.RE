#ifndef CAITASKFORCESQUAD_H
#define CAITASKFORCESQUAD_H

class CAITaskForceSquad : public CAITaskForceEx {
public:
    // address=[0x13192f0]
    virtual  ~CAITaskForceSquad(void);

    // address=[0x132bfc0]
     CAITaskForceSquad(int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132c020]
    virtual void  Execute(void);

    // address=[0x132c3c0]
    virtual bool  NewCommand(int,int,int);

    // address=[0x132c580]
    virtual enum CAITaskForce::T_RESULT  AddEntity(class CAIEntityInfo *,enum CAITaskForce::T_POSITION);

    // address=[0x132c660]
    virtual enum CAITaskForce::T_RESULT  RemoveEntity(class CAIEntityInfo *);

    // address=[0x132c7f0]
    virtual void  RemoveAllEntities(void);

    // address=[0x132c830]
    virtual int  NumberOfEntities(enum T_AI_WARRIOR_TYPE)const;

};


#endif // CAITASKFORCESQUAD_H
