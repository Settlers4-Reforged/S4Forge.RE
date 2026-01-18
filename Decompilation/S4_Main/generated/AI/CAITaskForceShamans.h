#ifndef CAITASKFORCESHAMANS_H
#define CAITASKFORCESHAMANS_H

#include "defines.h"

class CAITaskForceShamans : public CAITaskForceEx {
public:
    // address=[0x132a1c0]
     CAITaskForceShamans(int a2, int a3);

    // address=[0x132a2c0]
    virtual  ~CAITaskForceShamans(void);

    // address=[0x132cf70]
    virtual void  Execute(void);

    // address=[0x132d170]
    virtual bool  NewCommand(int a2, int a3, int a4);

};


#endif // CAITASKFORCESHAMANS_H
