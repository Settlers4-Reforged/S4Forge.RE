#ifndef CCENTER_H
#define CCENTER_H

#include "defines.h"

class CCenter {
public:
    // address=[0x15f4100]
    void  Add(int a2, int a3);

    // address=[0x15f4340]
    int  Count(void)const;

    // address=[0x15f60b0]
    int  X(void)const;

    // address=[0x15f60d0]
    int  Y(void)const;

};


#endif // CCENTER_H
