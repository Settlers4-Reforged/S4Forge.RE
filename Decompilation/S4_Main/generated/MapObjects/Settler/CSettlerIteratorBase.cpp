#include "CSettlerIteratorBase.h"

// Definitions for class CSettlerIteratorBase

// address=[0x1317460]
// Decompiled from int __thiscall CSettlerIteratorBase::SettlerId(CSettlerIteratorBase *this)
int  CSettlerIteratorBase::SettlerId(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1317480]
// Decompiled from int __thiscall CSettlerIteratorBase::SettlerType(CSettlerIteratorBase *this)
int  CSettlerIteratorBase::SettlerType(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x13173d0]
// Decompiled from CSettlerIteratorBase *__thiscall CSettlerIteratorBase::Init(CSettlerIteratorBase *this, int a2)
void  CSettlerIteratorBase::Init(int) {
  
  CSettlerIteratorBase *result; // eax

  result = this;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  return result;
}


// address=[0x13174a0]
// Decompiled from bool __thiscall CSettlerIteratorBase::SettlerValid(CSettlerIteratorBase *this, int a2)
bool  CSettlerIteratorBase::SettlerValid(int) {
  
  struct IEntity *v2; // eax
  bool v4; // [esp+4h] [ebp-4h]

  v4 = 1;
  if ( !a2 )
    return v4;
  v2 = CMapObjectMgr::Entity(a2);
  if ( ((unsigned int)&loc_3000000 & IEntity::Flags(v2)) == 0 )
    return 0;
  return v4;
}


