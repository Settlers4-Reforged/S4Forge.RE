#include "CSurroundingHexPointsIndices.h"

// Definitions for class CSurroundingHexPointsIndices

// address=[0x1470630]
// Decompiled from int __thiscall CSurroundingHexPointsIndices::operator[](_DWORD *this, int a2)
int  CSurroundingHexPointsIndices::operator[](int)const {
  
  return this[a2];
}


// address=[0x15dc440]
// Decompiled from void __thiscall CSurroundingHexPointsIndices::Init(CSurroundingHexPointsIndices *this, int a2)
void  CSurroundingHexPointsIndices::Init(int) {
  
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 721; ++i )
  {
    v3 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    *((_DWORD *)this + i) = v3 + a2 * SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
  }
}


