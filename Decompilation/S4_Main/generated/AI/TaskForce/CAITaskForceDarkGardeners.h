#ifndef CAITASKFORCEDARKGARDENERS_H
#define CAITASKFORCEDARKGARDENERS_H

#include "defines.h"

class CAITaskForceDarkGardeners : public CAITaskForceEx {
public:
    // address=[0x132a100]
     CAITaskForceDarkGardeners(int a2, int a3);

    // address=[0x132a280]
    virtual  ~CAITaskForceDarkGardeners(void);

    // address=[0x132ce70]
    virtual void  Execute(void);

    // address=[0x132cee0]
    virtual bool  NewCommand(int a2, int a3, int a4);

};


#endif // CAITASKFORCEDARKGARDENERS_H
