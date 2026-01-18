#ifndef CATTACKMSGFILTER_H
#define CATTACKMSGFILTER_H

#include "defines.h"

class CAttackMsgFilter {
private:
    // address=[0x140a760]
    bool  IsInRadius(int a2, int a3);

    // address=[0x140a7b0]
    bool  Activate(int a2, int a3, int a4);

    // address=[0x140a9a0]
     CAttackMsgFilter(void);

    // address=[0x140a9f0]
     ~CAttackMsgFilter(void);

    // address=[0x140aa60]
    void  Deactivate(void);

    // address=[0x140aa80]
    bool  IsActive(void);

    // address=[0x140aaa0]
    bool  IsOld(int a2);

};


#endif // CATTACKMSGFILTER_H
