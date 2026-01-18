#include "CGenericSettlerIterator.h"

// Definitions for class CGenericSettlerIterator

// address=[0x1315360]
// Decompiled from char __thiscall CGenericSettlerIterator::Init(CGenericSettlerIterator *this, int a2, int a3, int a4)
bool  CGenericSettlerIterator::Init(int a2, int a3, int a4) {
  
  CSettlerIteratorBase::Init((CGenericSettlerIterator *)((char *)this + 20), 0);
  if ( CPlayerIterator::Init(this, a2) )
  {
    if ( !a4 )
      a4 = a3;
    *((_DWORD *)this + 7) = a3;
    *((_DWORD *)this + 8) = a4;
    return 1;
  }
  else
  {
    *((_DWORD *)this + 7) = 0;
    *((_DWORD *)this + 8) = 0;
    return 0;
  }
}


// address=[0x13153d0]
// Decompiled from int __thiscall CGenericSettlerIterator::FirstSettler(CGenericSettlerIterator *this)
int  CGenericSettlerIterator::FirstSettler(void) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  if ( CPlayerIterator::FirstPlayer(this) )
  {
    *((_DWORD *)this + 5) = *((_DWORD *)this + 7);
    v3 = CSettlerIteratorBase::SettlerType((CGenericSettlerIterator *)((char *)this + 20));
    v2 = CPlayerIterator::PlayerId(this);
    *((_DWORD *)this + 6) = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v2, v3);
    if ( *((_DWORD *)this + 6) )
      return *((_DWORD *)this + 6);
    else
      return CGenericSettlerIterator::NextSettler(this);
  }
  else
  {
    *((_DWORD *)this + 5) = 0;
    *((_DWORD *)this + 6) = 0;
    return 0;
  }
}


// address=[0x1315450]
// Decompiled from int __thiscall CGenericSettlerIterator::NextSettler(CGenericSettlerIterator *this)
int  CGenericSettlerIterator::NextSettler(void) {
  
  int v1; // eax
  int v3; // eax
  _DWORD *v4; // eax
  int v5; // [esp-4h] [ebp-8h]

  do
  {
    v1 = CSettlerMgr::operator[](*((_DWORD *)this + 6));
    for ( *((_DWORD *)this + 6) = IAnimatedEntity::Next(v1);
          !*((_DWORD *)this + 6);
          *((_DWORD *)this + 6) = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v3, v5) )
    {
      if ( ++*((_DWORD *)this + 5) > *((_DWORD *)this + 8) )
      {
        if ( !CPlayerIterator::NextPlayer(this) )
          return 0;
        *((_DWORD *)this + 5) = *((_DWORD *)this + 7);
      }
      v5 = CSettlerIteratorBase::SettlerType((CGenericSettlerIterator *)((char *)this + 20));
      v3 = CPlayerIterator::PlayerId(this);
    }
    v4 = (_DWORD *)CSettlerMgr::operator[](*((_DWORD *)this + 6));
  }
  while ( ((unsigned int)&unk_4000000 & IEntity::Flags(v4)) != 0 );
  return *((_DWORD *)this + 6);
}


// address=[0x1315520]
// Decompiled from int __thiscall CGenericSettlerIterator::NextSettlerIfCurrentIsNotValid(_DWORD *this)
int  CGenericSettlerIterator::NextSettlerIfCurrentIsNotValid(void) {
  
  if ( CSettlerIteratorBase::SettlerValid((CSettlerIteratorBase *)(this + 5), this[6]) )
    return this[6];
  else
    return CGenericSettlerIterator::NextSettler((CGenericSettlerIterator *)this);
}


// address=[0x1315560]
// Decompiled from int __thiscall CGenericSettlerIterator::NextSettlerOrFirstIfCurrentIsEndOfList(CGenericSettlerIterator *this)
int  CGenericSettlerIterator::NextSettlerOrFirstIfCurrentIsEndOfList(void) {
  
  if ( *((_DWORD *)this + 6) )
    return CGenericSettlerIterator::NextSettler(this);
  else
    return CGenericSettlerIterator::FirstSettler(this);
}


// address=[0x13171b0]
// Decompiled from CGenericSettlerIterator *__thiscall CGenericSettlerIterator::CGenericSettlerIterator(CGenericSettlerIterator *this)
 CGenericSettlerIterator::CGenericSettlerIterator(void) {
  
  CPlayerIterator::CPlayerIterator(this);
  return this;
}


