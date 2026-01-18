#ifndef CAITASKFORCEMANAKOPTERS_H
#define CAITASKFORCEMANAKOPTERS_H

#include "defines.h"

class CAITaskForceManakopters : public CAITaskForceEx {
public:
    // address=[0x132a180]
     CAITaskForceManakopters(int a2, int a3);

    // address=[0x132a2a0]
    virtual  ~CAITaskForceManakopters(void);

    // address=[0x132d290]
    virtual void  Execute(void);

    // address=[0x132d480]
    virtual bool  NewCommand(int a2, int a3, int a4);

};


#endif // CAITASKFORCEMANAKOPTERS_H
