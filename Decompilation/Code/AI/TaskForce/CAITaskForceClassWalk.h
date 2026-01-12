#ifndef CAITASKFORCECLASSWALK_H
#define CAITASKFORCECLASSWALK_H

class CAITaskForceClassWalk {
public:
    // address=[0x12fcfb0]
    class CAITaskForce *  CurrentTaskForce(void)const;

    // address=[0x12fd3a0]
    bool  NextTaskForce(enum T_AI_TASK_FORCE_CMD);

    // address=[0x12fd3e0]
    bool  NextTaskForce(enum T_AI_TASK_FORCE_TYPE);

    // address=[0x1328da0]
     CAITaskForceClassWalk(class CAITaskForceGroup &,enum T_AI_TASK_FORCE_CLASS);

    // address=[0x1328dd0]
    bool  NextTaskForce(void);

};


#endif // CAITASKFORCECLASSWALK_H
