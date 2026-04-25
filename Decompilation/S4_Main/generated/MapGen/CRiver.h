#ifndef CRIVER_H
#define CRIVER_H

#include "defines.h"

class CRiver {
public:
    // address=[0x2fcb5a0]
     CRiver(int a2, int a3);

    // address=[0x2fcb760]
     CRiver(int a2, int a3, int a4);

    // address=[0x2fcbbf0]
     ~CRiver(void);

    // address=[0x2fcbc30]
    void  drawRiver(void);

protected:
    // address=[0x2fcbca0]
    void  drawRiverPart(int a2, int a3, int a4, int a4);

    // address=[0x2fcc380]
    int  findBorder(int a2, int a3);

};


#endif // CRIVER_H
