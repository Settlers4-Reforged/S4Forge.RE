#include "CGrpReserveEntry.h"

// Definitions for class CGrpReserveEntry

// address=[0x2f41730]
// Decompiled from _DWORD *__thiscall CGrpReserveEntry::CGrpReserveEntry(_DWORD *this, int a2, int a3, int a4, int a5)

 CGrpReserveEntry::CGrpReserveEntry(enum BUILDING_TYPES,int,int,int) {
  
  CDynList *v6; // [esp+8h] [ebp-18h]
  CDynList *C; // [esp+Ch] [ebp-14h]

  CReserveEntry::CReserveEntry(this);
  *this = &CGrpReserveEntry::_vftable_;
  this[3] = a2;
  this[4] = a3;
  this[5] = a4;
  this[11] = a5;
  C = (CDynList *)operator new(0xCu);
  if ( C )
    v6 = CDynList::CDynList(C);
  else
    v6 = 0;
  this[12] = v6;
  return this;
}


// address=[0x2f417f0]
// Decompiled from void __thiscall CGrpReserveEntry::~CGrpReserveEntry(CDynList **this)

 CGrpReserveEntry::~CGrpReserveEntry(void) {
  
  *this = (CDynList *)&CGrpReserveEntry::_vftable_;
  if ( this[12] )
    CDynList::`scalar deleting destructor'(this[12], 1u);
  CReserveEntry::~CReserveEntry(this);
}


