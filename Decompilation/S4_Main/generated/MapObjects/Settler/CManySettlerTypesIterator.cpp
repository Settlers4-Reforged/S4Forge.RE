#include "CManySettlerTypesIterator.h"

// Definitions for class CManySettlerTypesIterator

// address=[0x13151c0]
// Decompiled from int __thiscall CManySettlerTypesIterator::Init(CManySettlerTypesIterator *this, int a2, int a3, int a4)
void  CManySettlerTypesIterator::Init(int a2, int a3, int a4) {
  
  int result; // eax

  if ( !a4 )
    a4 = a3;
  CSettlerIteratorBase::Init(this, 0);
  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 3) = a3;
  result = a4;
  *((_DWORD *)this + 4) = a4;
  return result;
}


// address=[0x1315200]
// Decompiled from int __thiscall CManySettlerTypesIterator::FirstSettler(CManySettlerTypesIterator *this)
int  CManySettlerTypesIterator::FirstSettler(void) {
  
  bool v2; // [esp+0h] [ebp-8h]

  *(_DWORD *)this = *((_DWORD *)this + 3);
  *((_DWORD *)this + 1) = CSettlerMgr::GetFirstSettlerId(
                            (CSettlerMgr *)g_cSettlerMgr,
                            *((_DWORD *)this + 2),
                            *((_DWORD *)this + 3));
  v2 = *((_DWORD *)this + 1) != 0;
  if ( (v2 & CSettlerIteratorBase::SettlerValid(this, *((_DWORD *)this + 1))) != 0 )
    return *((_DWORD *)this + 1);
  else
    return CManySettlerTypesIterator::NextSettler(this);
}


// address=[0x1315280]
// Decompiled from int __thiscall CManySettlerTypesIterator::NextSettler(CManySettlerTypesIterator *this)
int  CManySettlerTypesIterator::NextSettler(void) {
  
  int v1; // eax
  int i; // [esp+0h] [ebp-8h]

  i = *((_DWORD *)this + 1);
  do
  {
    v1 = CSettlerMgr::operator[](i);
    for ( i = IAnimatedEntity::Next(v1);
          !i;
          i = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, *((_DWORD *)this + 2), *(_DWORD *)this) )
    {
      if ( ++*(_DWORD *)this > *((_DWORD *)this + 4) )
      {
        *((_DWORD *)this + 1) = 0;
        return 0;
      }
    }
  }
  while ( !CSettlerIteratorBase::SettlerValid(this, i) );
  *((_DWORD *)this + 1) = i;
  return i;
}


// address=[0x1315320]
// Decompiled from int __thiscall CManySettlerTypesIterator::NextSettlerIfCurrentIsNotValid(CManySettlerTypesIterator *this)
int  CManySettlerTypesIterator::NextSettlerIfCurrentIsNotValid(void) {
  
  if ( CSettlerIteratorBase::SettlerValid(this, *((_DWORD *)this + 1)) )
    return *((_DWORD *)this + 1);
  else
    return CManySettlerTypesIterator::NextSettler(this);
}


// address=[0x1317210]
// Decompiled from CManySettlerTypesIterator *__thiscall CManySettlerTypesIterator::CManySettlerTypesIterator(  CManySettlerTypesIterator *this)
 CManySettlerTypesIterator::CManySettlerTypesIterator(void) {
  
  return this;
}


