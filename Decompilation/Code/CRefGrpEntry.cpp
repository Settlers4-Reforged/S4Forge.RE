#include "CRefGrpEntry.h"

// Definitions for class CRefGrpEntry

// address=[0x2f41840]
// Decompiled from CRefGrpEntry *__thiscall CRefGrpEntry::CRefGrpEntry(CRefGrpEntry *this, int a2, struct CGrpReserveEntry *a3)

 CRefGrpEntry::CRefGrpEntry(int,class CGrpReserveEntry *) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CRefGrpEntry::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a3;
  return this;
}


// address=[0x2f41880]
// Decompiled from void __thiscall CRefGrpEntry::~CRefGrpEntry(CRefGrpEntry *this)

 CRefGrpEntry::~CRefGrpEntry(void) {
  
  *(_DWORD *)this = &CRefGrpEntry::_vftable_;
  CDynListEntry::~CDynListEntry(this);
}


