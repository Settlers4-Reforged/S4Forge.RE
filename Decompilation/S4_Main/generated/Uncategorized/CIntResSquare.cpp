#include "all_headers.h"

// Definitions for class CIntResSquare

// address=[0x131b560]
// Decompiled from int __thiscall CIntResSquare::Value(_DWORD *this)
int  CIntResSquare::Value(void) {
  
  int v2; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( (int)this[i] > 0 )
      v2 += (int)sqrt<int>(this[i]) + 100;
  }
  return v2 + 10 * this[18];
}


// address=[0x131b5d0]
// Decompiled from _DWORD *__thiscall CIntResSquare::operator__(_DWORD *this, CAIResourceData *a2)
class CIntResSquare &  CIntResSquare::operator+=(class CAIResourceData const &) {
  
  int i; // [esp+0h] [ebp-8h]

  for ( i = 0; i < 8; ++i )
    this[i] += CAIResourceData::ResourceAmount1(a2, i);
  this[16] |= CAIResourceData::Flags1(a2);
  this[17] |= CAIResourceData::Flags9(a2);
  ++this[18];
  return this;
}


// address=[0x131b660]
// Decompiled from bool __thiscall CIntResSquare::operator___0(_DWORD *this, _DWORD *a2)
bool  CIntResSquare::operator>=(class CIntResSquare const &) {
  
  int i; // [esp+14h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    if ( this[i] < a2[i] )
      return 0;
  }
  return this[18] >= a2[18] && (a2[17] & this[17]) == a2[17] && (a2[16] & this[16]) == a2[16];
}


