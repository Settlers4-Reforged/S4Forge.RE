#include "all_headers.h"

// Definitions for class CDestructionPhase

// address=[0x1425d60]
// Decompiled from CDestructionPhase *__thiscall CDestructionPhase::CDestructionPhase(CDestructionPhase *this, int a2)
 CDestructionPhase::CDestructionPhase(int) {
  
  *(_DWORD *)this = a2;
  return this;
}


// address=[0x2f05560]
// Decompiled from bool __thiscall CDestructionPhase::operator>(_DWORD *this, _DWORD *a2)
bool  CDestructionPhase::operator>(class CDestructionPhase const &)const {
  
  return *this > *a2;
}


