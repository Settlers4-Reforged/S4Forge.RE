#include "CReserveEntry.h"

// Definitions for class CReserveEntry

// address=[0x2f416b0]
// Decompiled from CReserveEntry *__thiscall CReserveEntry::CReserveEntry(CReserveEntry *this)
 CReserveEntry::CReserveEntry(void) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CReserveEntry::_vftable_;
  return this;
}


// address=[0x2f416d0]
// Decompiled from CDynListEntry *__thiscall CReserveEntry::CReserveEntry(CDynListEntry *this, int a2, int a3, int a4)
 CReserveEntry::CReserveEntry(enum BUILDING_TYPES,int,int) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CReserveEntry::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 5) = a4;
  return this;
}


// address=[0x2f41710]
// Decompiled from void __thiscall CReserveEntry::~CReserveEntry(CReserveEntry *this)
 CReserveEntry::~CReserveEntry(void) {
  
  *(_DWORD *)this = &CReserveEntry::_vftable_;
  CDynListEntry::~CDynListEntry(this);
}


