#include "helper.h"

// address=[0x1306b00]
int __cdecl Squares::XYToVW(int xy)
{
    return xy / 16;
}

// address=[0x130f4d0]
bool __cdecl Squares::ValidVW(int vw)
{
    return vw < 0x40;
}

// address=[0x131ca50]
int __cdecl Squares::VWToXY(int vw)
{
    return 16 * vw;
}

// address=[0x131ca60]
bool __cdecl Squares::ValidVW(int a1, int a2)
{
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  if ( a1 < 0x40 )
    v4 = -1;
  else
    v4 = 0;
  if ( a2 < 0x40 )
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}