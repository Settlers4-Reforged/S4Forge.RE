#ifndef CCOMMANDQUEUE_H
#define CCOMMANDQUEUE_H

#include "defines.h"

class CCommandQueue {
public:
    // address=[0x153fec0]
    void  CheckCommand(class CEntityEvent * a2);

    // address=[0x153ff10]
    void  Push(class CEntityEvent * a2);

    // address=[0x153ff40]
    class CEntityEvent  Pop(void a2);

};


#endif // CCOMMANDQUEUE_H
