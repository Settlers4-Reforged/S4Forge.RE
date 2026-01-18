#include "CAttackMsgFilter.h"

// Definitions for class CAttackMsgFilter

// address=[0x140a760]
// Decompiled from bool __thiscall CAttackMsgFilter::IsInRadius(Grid **this, int a2, int a3)
bool  CAttackMsgFilter::IsInRadius(int a2, int a3) {
  
  return Grid::Distance(this[1], this[2], a2, a3) <= 25;
}


// address=[0x140a7b0]
// Decompiled from char __thiscall CAttackMsgFilter::Activate(CAttackMsgFilter *this, int a2, int a3, int a4)
bool  CAttackMsgFilter::Activate(int a2, int a3, int a4) {
  
  if ( *(_BYTE *)this )
    return 0;
  *(_BYTE *)this = 1;
  *((_DWORD *)this + 3) = a2 + 420;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  return 1;
}


// address=[0x140a9a0]
// Decompiled from CAttackMsgFilter *__thiscall CAttackMsgFilter::CAttackMsgFilter(CAttackMsgFilter *this)
 CAttackMsgFilter::CAttackMsgFilter(void) {
  
  *(_BYTE *)this = 0;
  return this;
}


// address=[0x140a9f0]
// Decompiled from void __thiscall CAttackMsgFilter::~CAttackMsgFilter(CAttackMsgFilter *this)
 CAttackMsgFilter::~CAttackMsgFilter(void) {
  
  ;
}


// address=[0x140aa60]
// Decompiled from CAttackMsgFilter *__thiscall CAttackMsgFilter::Deactivate(CAttackMsgFilter *this)
void  CAttackMsgFilter::Deactivate(void) {
  
  CAttackMsgFilter *result; // eax

  result = this;
  *(_BYTE *)this = 0;
  return result;
}


// address=[0x140aa80]
// Decompiled from char __thiscall CAttackMsgFilter::IsActive(CAttackMsgFilter *this)
bool  CAttackMsgFilter::IsActive(void) {
  
  return *(_BYTE *)this;
}


// address=[0x140aaa0]
// Decompiled from bool __thiscall CAttackMsgFilter::IsOld(CAttackMsgFilter *this, int a2)
bool  CAttackMsgFilter::IsOld(int a2) {
  
  return a2 > *((_DWORD *)this + 3);
}


