#include "Replicator.h"

// Definitions for class Replicator

// address=[0x30811e0]
// Decompiled from Replicator *__thiscall Replicator::Replicator(Replicator *this)
 Replicator::Replicator(void) {
  
  *(_DWORD *)this = -1;
  return this;
}


// address=[0x30819c0]
// Decompiled from DName *__thiscall Replicator::operator[](_DWORD *this, DName *a2, unsigned int a3)
class DName  Replicator::operator[](int)const {
  
  if ( a3 < 0xA )
  {
    if ( *this == -1 || (signed int)a3 > *this )
    {
      DName::DName(a2, 2);
      return a2;
    }
    else
    {
      DName::DName(a2, (const struct DName *)this[a3 + 1]);
      return a2;
    }
  }
  else
  {
    DName::DName(a2, 3);
    return a2;
  }
}


// address=[0x3082320]
// Decompiled from Replicator *__thiscall Replicator::operator+=(Replicator *this, DName *a2)
class Replicator &  Replicator::operator+=(class DName const &) {
  
  int v3; // [esp+4h] [ebp-10h]
  DName *v4; // [esp+8h] [ebp-Ch]
  DName *v5; // [esp+Ch] [ebp-8h]

  if ( Replicator::isFull(this) || DName::isEmpty(a2) )
    return this;
  v5 = (DName *)operator new(8u, (struct _HeapManager *)&unk_4731E94, 0);
  if ( v5 )
    v4 = DName::DName(v5, a2);
  else
    v4 = 0;
  if ( !v4 )
    return this;
  v3 = *(_DWORD *)this + 1;
  *(_DWORD *)this = v3;
  *((_DWORD *)this + v3 + 1) = v4;
  return this;
}


// address=[0x308cd80]
// Decompiled from BOOL __thiscall Replicator::isFull(Replicator *this)
int  Replicator::isFull(void)const {
  
  return *(_DWORD *)this == 9;
}


