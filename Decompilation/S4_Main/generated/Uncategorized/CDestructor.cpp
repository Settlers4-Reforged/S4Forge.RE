#include "all_headers.h"

// Definitions for class CDestructor

// address=[0x1425d80]
// Decompiled from int __thiscall CDestructor::CDestructor(int this, int a2)
 CDestructor::CDestructor(class CDestructionPhase) {
  
  CDestructionManager *v2; // eax

  *(_DWORD *)this = &CDestructor::_vftable_;
  *(_DWORD *)(this + 4) = a2;
  v2 = (CDestructionManager *)CDestructionManager::Instance();
  CDestructionManager::RegisterDestructor(v2, (struct CDestructor *)this);
  return this;
}


// address=[0x2f055a0]
// Decompiled from bool __thiscall CDestructor::operator>(_DWORD *this, int a2)
bool  CDestructor::operator>(class CDestructor const &)const {
  
  return CDestructionPhase::operator>(this + 1, (_DWORD *)(a2 + 4));
}


