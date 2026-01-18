#ifndef CAICHAMBERS_H
#define CAICHAMBERS_H

#include "defines.h"

class CAIChambers {
public:
    // address=[0x1314700]
     CAIChambers(int a2);

    // address=[0x1314770]
    void  Push(int a2, int a3);

    // address=[0x1314880]
    void  PushTaskForce(class CAITaskForce & a2);

    // address=[0x13148e0]
    void  PushTaskForceEx(class CAITaskForce & a2, int a3);

    // address=[0x1314960]
    int  Next(void);

    // address=[0x1321b60]
    void  Clear(void);

    // address=[0x1321b90]
    int  Current(void);

    // address=[0x1321bd0]
    int  First(void);

};


#endif // CAICHAMBERS_H
