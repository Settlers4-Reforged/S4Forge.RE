#include "all_headers.h"

// Definitions for class CSettlerStatus

// address=[0x1554910]
// Decompiled from CManakopter::CSettlerStatus *__thiscall CManakopter::CSettlerStatus::CSettlerStatus(  CManakopter::CSettlerStatus *this,  const struct CManakopter::CSettlerStatus *a2)
 CManakopter::CSettlerStatus::CSettlerStatus(class CManakopter::CSettlerStatus const &) {
  
  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  return this;
}


// address=[0x1554950]
// Decompiled from _DWORD *__thiscall CManakopter::CSettlerStatus::CSettlerStatus(_DWORD *this, int a2, int a3, int a4)
 CManakopter::CSettlerStatus::CSettlerStatus(int,enum SETTLER_TYPES,int) {
  
  *this = a4;
  this[1] = a2;
  this[2] = a3;
  return this;
}


// address=[0x1554990]
// Decompiled from CManakopter::CSettlerStatus *__thiscall CManakopter::CSettlerStatus::CSettlerStatus(CManakopter::CSettlerStatus *this)
 CManakopter::CSettlerStatus::CSettlerStatus(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  return this;
}


// address=[0x1554b60]
// Decompiled from void __thiscall CManakopter::CSettlerStatus::~CSettlerStatus(CManakopter::CSettlerStatus *this)
 CManakopter::CSettlerStatus::~CSettlerStatus(void) {
  
  ;
}


