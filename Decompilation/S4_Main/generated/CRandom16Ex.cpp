#include "all_headers.h"

// Definitions for class CRandom16Ex

// address=[0x13613e0]
// Decompiled from CRandom16Ex *__thiscall CRandom16Ex::CRandom16Ex(CRandom16Ex *this, unsigned int a2)
 CRandom16Ex::CRandom16Ex(unsigned int) {
  
  CRandom16::CRandom16(this, 0);
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  return this;
}


// address=[0x1361420]
// Decompiled from unsigned int __thiscall CRandom16Ex::Init(CRandom16Ex *this, unsigned int a2, unsigned int a3)
void  CRandom16Ex::Init(unsigned int,unsigned int) {
  
  unsigned int result; // eax

  *(_DWORD *)this = a2;
  result = a3;
  *((_DWORD *)this + 1) = a3;
  return result;
}


