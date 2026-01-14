#include "all_headers.h"

// Definitions for class COneSettlerTypeIterator

// address=[0x13037c0]
// Decompiled from COneSettlerTypeIterator *__thiscall COneSettlerTypeIterator::COneSettlerTypeIterator(  COneSettlerTypeIterator *this,  int a2,  int a3)
 COneSettlerTypeIterator::COneSettlerTypeIterator(int,int) {
  
  COneSettlerTypeIterator::Init(this, a2, a3);
  return this;
}


// address=[0x13150d0]
// Decompiled from int __thiscall COneSettlerTypeIterator::Init(COneSettlerTypeIterator *this, int a2, int a3)
void  COneSettlerTypeIterator::Init(int,int) {
  
  int result; // eax

  CSettlerIteratorBase::Init(this, a3);
  *((_DWORD *)this + 2) = a2;
  return result;
}


// address=[0x1315100]
// Decompiled from int __thiscall COneSettlerTypeIterator::FirstSettler(COneSettlerTypeIterator *this)
int  COneSettlerTypeIterator::FirstSettler(void) {
  
  *((_DWORD *)this + 1) = CSettlerMgr::GetFirstSettlerId(
                            (CSettlerMgr *)g_cSettlerMgr,
                            *((_DWORD *)this + 2),
                            *(_DWORD *)this);
  return COneSettlerTypeIterator::NextSettlerIfCurrentIsNotValid(this);
}


// address=[0x1315130]
// Decompiled from int __thiscall COneSettlerTypeIterator::NextSettler(COneSettlerTypeIterator *this)
int  COneSettlerTypeIterator::NextSettler(void) {
  
  int v1; // eax
  int v4; // [esp+4h] [ebp-4h]

  v4 = *((_DWORD *)this + 1);
  do
  {
    v1 = CSettlerMgr::operator[](v4);
    v4 = IAnimatedEntity::Next(v1);
  }
  while ( !CSettlerIteratorBase::SettlerValid(this, v4) );
  *((_DWORD *)this + 1) = v4;
  return v4;
}


// address=[0x1315180]
// Decompiled from int __thiscall COneSettlerTypeIterator::NextSettlerIfCurrentIsNotValid(COneSettlerTypeIterator *this)
int  COneSettlerTypeIterator::NextSettlerIfCurrentIsNotValid(void) {
  
  if ( CSettlerIteratorBase::SettlerValid(this, *((_DWORD *)this + 1)) )
    return *((_DWORD *)this + 1);
  else
    return COneSettlerTypeIterator::NextSettler(this);
}


// address=[0x1317270]
// Decompiled from COneSettlerTypeIterator *__thiscall COneSettlerTypeIterator::COneSettlerTypeIterator(COneSettlerTypeIterator *this)
 COneSettlerTypeIterator::COneSettlerTypeIterator(void) {
  
  return this;
}


