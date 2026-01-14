#include "all_headers.h"

// Definitions for class CBuildingBits

// address=[0x14f1a80]
// Decompiled from int __thiscall CBuildingBits::PrintToTraceFile(CBuildingBits *this, int a2)
void  CBuildingBits::PrintToTraceFile(unsigned int) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-60h]
  int j; // [esp+Ch] [ebp-5Ch]
  char v6[84]; // [esp+10h] [ebp-58h] BYREF

  result = 1;
  v6[80] = 0;
  for ( i = 0; i < 80; ++i )
  {
    for ( j = 0; j < 80; ++j )
    {
      if ( *((_BYTE *)this + 80 * j + i) == 1 )
        v6[j] = 49;
      else
        v6[j] = 48;
    }
    BBSupportTracePrintF(a2, "%s", v6);
    result = i + 1;
  }
  return result;
}


// address=[0x14f3590]
// Decompiled from CBuildingBits *__thiscall CBuildingBits::CBuildingBits(CBuildingBits *this)
 CBuildingBits::CBuildingBits(void) {
  
  memset(this, 0, 0x1900u);
  return this;
}


