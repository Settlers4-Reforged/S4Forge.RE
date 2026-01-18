#ifndef CG24CLOSED1PARENT16_H
#define CG24CLOSED1PARENT16_H

#include "defines.h"

class CG24Closed1Parent16 {
public:
    // address=[0x15d61b0]
    int  Closed(void)const;

    // address=[0x15d6560]
    int  G(void)const;

    // address=[0x15d67e0]
    int  Parent(void)const;

    // address=[0x15d6cb0]
    void  Set(int a2, int a3, bool a4, int a5);

    // address=[0x15d6d90]
    void  SetClosedFlag(void);

    // address=[0x15d6e50]
    int  State(void)const;

};


#endif // CG24CLOSED1PARENT16_H
