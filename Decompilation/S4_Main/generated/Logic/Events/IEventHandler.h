#ifndef IEVENTHANDLER_H
#define IEVENTHANDLER_H

#include "defines.h"

class IEventHandler {
public:
    // address=[0x1460060]
     IEventHandler(int a2);

    // address=[0x1460140]
    virtual  ~IEventHandler(void);

};


#endif // IEVENTHANDLER_H
