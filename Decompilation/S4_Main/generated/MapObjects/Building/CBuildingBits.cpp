#if FALSE
#include "CBuildingBits.h"

// Definitions for class CBuildingBits

// address=[0x14f1a80]
// Decompiled from void __thiscall CBuildingBits::PrintToTraceFile(CBuildingBits *this, int a2)
void  CBuildingBits::PrintToTraceFile(unsigned int a2) {
  
  int i; // [esp+8h] [ebp-60h]
  int j; // [esp+Ch] [ebp-5Ch]
  char v5[84]; // [esp+10h] [ebp-58h] BYREF

  v5[80] = 0;
  for ( i = 0; i < 80; ++i )
  {
    for ( j = 0; j < 80; ++j )
    {
      if ( this->m_iBits[j][i] == 1 )
        v5[j] = '1';
      else
        v5[j] = '0';
    }
    BBSupportTracePrintF(a2, "%s", v5);
  }
}


// address=[0x14f3590]
// Decompiled from CBuildingBits *__thiscall CBuildingBits::CBuildingBits(CBuildingBits *this)
 CBuildingBits::CBuildingBits(void) {
  
  memset(this, 0, sizeof(CBuildingBits));
  return this;
}


#endif // Already implemented
