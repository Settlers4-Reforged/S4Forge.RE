#include "CHistorySolution.h"

// Definitions for class CHistorySolution

// address=[0x2f3f700]
// Decompiled from CHistorySolution *__thiscall CHistorySolution::CHistorySolution(CHistorySolution *this, int a2, struct CParam *a3)

 CHistorySolution::CHistorySolution(int,class CParam *) {
  
  CParam *v4; // [esp+8h] [ebp-18h]
  CParam *C; // [esp+Ch] [ebp-14h]

  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CHistorySolution::_vftable_;
  *((_DWORD *)this + 3) = a2;
  C = (CParam *)operator new(0x1Cu);
  if ( C )
    v4 = CParam::CParam(C, *((_DWORD *)a3 + 3), *((_DWORD *)a3 + 4), *((_DWORD *)a3 + 5), *((_DWORD *)a3 + 6));
  else
    v4 = 0;
  *((_DWORD *)this + 4) = v4;
  return this;
}


// address=[0x2f3f7c0]
// Decompiled from void __thiscall CHistorySolution::~CHistorySolution(CHistorySolution *this)

 CHistorySolution::~CHistorySolution(void) {
  
  *(_DWORD *)this = &CHistorySolution::_vftable_;
  if ( *((_DWORD *)this + 4) )
    (***((void (__thiscall ****)(_DWORD, int))this + 4))(*((_DWORD *)this + 4), 1);
  CDynListEntry::~CDynListEntry(this);
}


