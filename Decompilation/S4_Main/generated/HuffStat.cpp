#include "all_headers.h"

// Definitions for class HuffStat

// address=[0x2f2a930]
// Decompiled from HuffStat *__thiscall HuffStat::HuffStat(HuffStat *this)
 HuffStat::HuffStat(void) {
  
  *(_DWORD *)this = operator new[](0x224u);
  memset(*(void **)this, 0, 0x224u);
  return this;
}


// address=[0x2f2a970]
// Decompiled from int __thiscall HuffStat::~HuffStat(void **this)
 HuffStat::~HuffStat(void) {
  
  return operator delete[](*this);
}


// address=[0x2f2a9a0]
// Decompiled from int __thiscall HuffStat::makeSortedTmp(HuffStat *this, struct HuffStatTmpStruct *a2)
int  HuffStat::makeSortedTmp(struct HuffStatTmpStruct *) {
  
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 274; ++i )
  {
    *((_WORD *)a2 + 2 * i) = i;
    *((_WORD *)a2 + 2 * i + 1) = *(_WORD *)(*(_DWORD *)this + 2 * i);
    v3 += *(__int16 *)(*(_DWORD *)this + 2 * i);
    *(__int16 *)(*(_DWORD *)this + 2 * i) >>= 1;
  }
  shellSort((struct HuffStatTmpStruct *)((char *)a2 - 4), 274);
  return v3;
}


