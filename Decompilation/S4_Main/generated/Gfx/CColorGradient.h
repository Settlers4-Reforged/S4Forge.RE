#ifndef CCOLORGRADIENT_H
#define CCOLORGRADIENT_H

#include "defines.h"

class CColorGradient {
public:
    // address=[0x2f6ff70]
    void  SetupGradients(int a2, struct SGfxColor a3, int a4);

    // address=[0x2f71c10]
     CColorGradient(void);

    // Type information members
public:
    char[8][64] m_vGradients;
    SGfxColor[64] m_vPlayerColors;

};


#endif // CCOLORGRADIENT_H
