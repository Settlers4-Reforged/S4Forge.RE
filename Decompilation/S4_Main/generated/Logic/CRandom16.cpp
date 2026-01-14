#include "all_headers.h"

// Definitions for class CRandom16

// address=[0x12fd540]
// Decompiled from int __thiscall CRandom16::Rand(CRandom16 *this)
unsigned int  CRandom16::Rand(void) {
  
  ++*((_DWORD *)this + 1);
  *(_DWORD *)this = 1812433253 * *(_DWORD *)this + 1;
  return HIWORD(*(_DWORD *)this);
}


// address=[0x1301600]
// Decompiled from unsigned int __cdecl CRandom16::PercentValue(unsigned int a1)
static unsigned int __cdecl CRandom16::PercentValue(unsigned int) {
  
  return (a1 << 16) / 0x64;
}


// address=[0x130a490]
// Decompiled from int __thiscall CRandom16::GetNumberOfRandCalls(CRandom16 *this)
unsigned int  CRandom16::GetNumberOfRandCalls(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1311d70]
// Decompiled from int __thiscall CRandom16::GetSeed(CRandom16 *this)
unsigned int  CRandom16::GetSeed(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x13613b0]
// Decompiled from CRandom16 *__thiscall CRandom16::CRandom16(CRandom16 *this, unsigned int a2)
 CRandom16::CRandom16(unsigned int) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  return this;
}


