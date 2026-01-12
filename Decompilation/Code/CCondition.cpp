#include "CCondition.h"

// Definitions for class CCondition

// address=[0x2f3ed60]
// Decompiled from // public: __thiscall CCondition::CCondition(void)
CCondition *__thiscall CCondition::CCondition(CCondition *this)

 CCondition::CCondition(void) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CCondition::_vftable_;
  return this;
}


// address=[0x2f3ed80]
// Decompiled from void __thiscall CCondition::~CCondition(CCondition *this)

 CCondition::~CCondition(void) {
  
  *(_DWORD *)this = &CCondition::_vftable_;
  if ( *((_DWORD *)this + 4) )
    (***((void (__thiscall ****)(_DWORD, int))this + 4))(*((_DWORD *)this + 4), 1);
  if ( *((_DWORD *)this + 5) )
    COptimizeOptions::`scalar deleting destructor'(*((COptimizeOptions **)this + 5), 1u);
  CDynListEntry::~CDynListEntry(this);
}


// address=[0x2f3ee00]
// Decompiled from CCondition *__thiscall CCondition::CCondition(CCondition *this, int a2, struct CParam *a3, struct COptimizeOptions *a4)

 CCondition::CCondition(int,class CParam *,class COptimizeOptions *) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CCondition::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 5) = a4;
  return this;
}


