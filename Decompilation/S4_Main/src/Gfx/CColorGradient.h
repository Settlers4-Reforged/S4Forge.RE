#ifndef CCOLORGRADIENT_H
#define CCOLORGRADIENT_H

#include "SGfxColor.h"
#include "defines.h"

extern class CColorGradient g_cColorGradient;

class CColorGradient {
  public:
    // address=[0x2f6ff70]
    void SetupGradients(int a2, SGfxColor a3, int a6);

    // address=[0x2f71c10]
    CColorGradient(void);

    // Type information members
  public:
    unsigned __int16 m_vGradients[8][32];
    SGfxColor m_vPlayerColors[9];
};

#endif // CCOLORGRADIENT_H
