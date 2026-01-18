#include "CNeighborRelIndices.h"

// Definitions for class CNeighborRelIndices

// address=[0x15dc3e0]
// Decompiled from int __thiscall CNeighborRelIndices::Init(CNeighborRelIndices *this, int a2)
void  CNeighborRelIndices::Init(int a2) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    v3 = g_sNeighborPoints[2 * i] + a2 * dword_37D8C0C[2 * i];
    *((_DWORD *)this + i) = v3;
    *((_DWORD *)this + i + 6) = v3;
    result = i + 1;
  }
  return result;
}


