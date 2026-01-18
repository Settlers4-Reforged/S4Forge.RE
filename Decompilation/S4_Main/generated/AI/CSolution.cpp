#include "CSolution.h"

// Definitions for class CSolution

// address=[0x2f3f3f0]
// Decompiled from CSolution *__thiscall CSolution::CSolution(CSolution *this, int a2, struct CParam *a3)
 CSolution::CSolution(int a2, class CParam * a3) {
  
  CParam *v4; // [esp+8h] [ebp-18h]
  CParam *C; // [esp+Ch] [ebp-14h]

  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CSolution::_vftable_;
  *((_DWORD *)this + 3) = a2;
  C = (CParam *)operator new(0x1Cu);
  if ( C )
    v4 = CParam::CParam(C, *((_DWORD *)a3 + 3), *((_DWORD *)a3 + 4), *((_DWORD *)a3 + 5), *((_DWORD *)a3 + 6));
  else
    v4 = 0;
  *((_DWORD *)this + 4) = v4;
  return this;
}


// address=[0x2f3f4b0]
// Decompiled from void __thiscall CSolution::~CSolution(CSolution *this)
 CSolution::~CSolution(void) {
  
  *(_DWORD *)this = &CSolution::_vftable_;
  if ( *((_DWORD *)this + 4) )
    (***((void (__thiscall ****)(_DWORD, int))this + 4))(*((_DWORD *)this + 4), 1);
  CDynListEntry::~CDynListEntry(this);
}


