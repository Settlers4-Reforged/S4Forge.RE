#ifndef CAITASKFORCEGROUP_H
#define CAITASKFORCEGROUP_H

#include "defines.h"

class CAITaskForceGroup {
public:
    // address=[0x12fd0d0]
    class CAITaskForce *FirstTaskForce(enum T_AI_TASK_FORCE_CLASS a2) const;

    // address=[0x13015c0]
    int NumberOfTaskForcesOfType(enum T_AI_TASK_FORCE_TYPE a2) const;

    // address=[0x1303970]
    int NumberOfTaskForcesOfClass(enum T_AI_TASK_FORCE_CLASS a2) const;

    // address=[0x1328380]
    CAITaskForceGroup(int a2);

    // address=[0x13283c0]
    ~CAITaskForceGroup(void);

    // address=[0x1328410]
    class CAITaskForce *CreateTaskForce(enum T_AI_TASK_FORCE_TYPE a2);

    // address=[0x1328450]
    void DeleteAllTaskForces(void);

    // address=[0x1328510]
    virtual void Load(class IS4Chunk &a2);

    // address=[0x13286f0]
    virtual void Save(class IS4Chunk &a2);

    // address=[0x132a500]
    int PlayerId(void);

protected:
    // address=[0x1328970]
    void AddTaskForce(class CAITaskForce *_pTaskForce);

    // address=[0x1328b20]
    void RemoveTaskForce(class CAITaskForce *_pTaskForce);

    friend class CAITaskForce;

    // Type information members
public:
    void *vftable;

    struct SAITaskForceGroupData {
        int           m_iPlayerId;
        int           m_iTotalNumberOfTaskForces;
        int           m_iNumberOfTaskForcesOfClass[9];
        int           m_iNumberOfTaskForcesOfType[9];
        BYTE          gap_50[20];
        CAITaskForce *m_pTaskForces[9];
    } m_sData;
};


#endif // CAITASKFORCEGROUP_H
