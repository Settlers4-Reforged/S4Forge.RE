#ifndef CCHECKLAYER_H
#define CCHECKLAYER_H

#include "defines.h"

class CCheckLayer {
public:
    // address=[0x2fc85d0]
     CCheckLayer(int a2);

    // address=[0x2fc8630]
     ~CCheckLayer(void);

    // address=[0x2fc8660]
    unsigned short  getPoint(int a2, int a3);

    // address=[0x2fc8740]
    void  setPoint(int a2, int a3, unsigned short a4);

    // address=[0x2fc8820]
    void  clear(void);

};


#endif // CCHECKLAYER_H
