#ifndef CAITASKFORCECLASSWALK_H
#define CAITASKFORCECLASSWALK_H

#include "defines.h"
#include "Defines/AI.h"

class CAITaskForceClassWalk {
public:
    // address=[0x12fcfb0]
    class CAITaskForce *CurrentTaskForce(void) const;

    // address=[0x12fd3a0]
    bool NextTaskForce(T_AI_TASK_FORCE_CMD a2);

    // address=[0x12fd3e0]
    bool NextTaskForce(T_AI_TASK_FORCE_TYPE a2);

    // address=[0x1328da0]
    CAITaskForceClassWalk(class CAITaskForceGroup &a2, T_AI_TASK_FORCE_CLASS a3);

    // address=[0x1328dd0]
    bool NextTaskForce(void);

    // Type information members
public:
    CAITaskForce *m_pCurrentTaskForce;
    CAITaskForce *m_pNextTaskForce;
};


#endif // CAITASKFORCECLASSWALK_H
