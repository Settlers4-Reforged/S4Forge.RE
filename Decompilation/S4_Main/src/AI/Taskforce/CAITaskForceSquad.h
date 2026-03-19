#ifndef CAITASKFORCESQUAD_H
#define CAITASKFORCESQUAD_H

#include "defines.h"
#include "AI/CAITaskForceEx.h"

class CAITaskForceSquad : public CAITaskForceEx {
public:
    // address=[0x13192f0]
    virtual ~CAITaskForceSquad(void);

    // address=[0x132bfc0]
    CAITaskForceSquad(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132c020]
    virtual void Execute(void);

    // address=[0x132c3c0]
    virtual bool NewCommand(int a2, int _iEntityIdOrPackedXY, int a4);

    // address=[0x132c580]
    virtual T_RESULT AddEntity(class CAIEntityInfo *_pEntityInfo, enum CAITaskForce::T_POSITION a3);

    // address=[0x132c660]
    virtual T_RESULT RemoveEntity(class CAIEntityInfo *_pEntityInfo);

    // address=[0x132c7f0]
    virtual void RemoveAllEntities(void);

    // address=[0x132c830]
    virtual int NumberOfEntities(enum T_AI_WARRIOR_TYPE a2) const;

    // Type information members
public:
    int m_iNumberOfSwordsmen;
    int m_iNumberOfBowmen;
    int m_iNumberOfUniqueFighters;
    int m_iNumberOfSquadleaders;
};


#endif // CAITASKFORCESQUAD_H
