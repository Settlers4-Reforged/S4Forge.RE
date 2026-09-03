#ifndef SSURROUNDINGPOINT8_H
#define SSURROUNDINGPOINT8_H

#include "defines.h"

extern struct SSurroundingPoint8 const *const g_sSurroundingHexPoints8;

// address=[0x132f920]
// Decompiled from int __cdecl SurroundingHexPointsCount(int a1)
int __cdecl SurroundingHexPointsCount(int a1);

class SSurroundingPoint8 {
  public:
    // address=[0x132ee80]
    int X(void) const;

    // address=[0x132eea0]
    int Y(void) const;

    // address=[0x15ddca0]
    struct SPoint8 const &Point(void) const;

    // address=[0x15ddcc0]
    int Radius(void) const;

    // Type information members
  public:
    char m_iX;
    char m_iY;
    char m_iRadius;
    unsigned char m_uPadding;
};

#endif // SSURROUNDINGPOINT8_H
