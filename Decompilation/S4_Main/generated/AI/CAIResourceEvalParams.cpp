#include "all_headers.h"

// Definitions for class CAIResourceEvalParams

// address=[0x131a800]
// Decompiled from int __thiscall CAIResourceEvalParams::Evalute9(CAIResourceEvalParams *this, const struct CAIResourceData *a2)
int  CAIResourceEvalParams::Evalute9(class CAIResourceData const &)const {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+Ch] [ebp-10h]
  int i; // [esp+18h] [ebp-4h]

  v5 = 0;
  v4 = 0;
  for ( i = 0; i < 8; ++i )
  {
    v2 = CAIResourceData::ResourceAmount9(a2, i);
    v5 += v2 * *((_DWORD *)this + 4 * i + 1) + *((_DWORD *)this + 4 * i) + v2 * v2 * *((_DWORD *)this + 4 * i + 2);
    v4 += v2 >= *((_DWORD *)this + 4 * i + 4);
  }
  return v5;
}


