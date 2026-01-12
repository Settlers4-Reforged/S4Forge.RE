#include "CDynListEntry.h"

// Definitions for class CDynListEntry

// address=[0x2f3b640]
// Decompiled from CDynListEntry *__thiscall CDynListEntry::~CDynListEntry(CDynListEntry *this)
 CDynListEntry::~CDynListEntry(void) {
  
  CDynListEntry *result; // eax

  result = this;
  *(_DWORD *)this = &CDynListEntry::_vftable_;
  return result;
}


// address=[0x2f3c790]
// Decompiled from CDynListEntry *__thiscall CDynListEntry::CDynListEntry(CDynListEntry *this)
 CDynListEntry::CDynListEntry(void) {
  
  *(_DWORD *)this = &CDynListEntry::_vftable_;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 1) = 0;
  return this;
}


// address=[0x2f3c7c0]
// Decompiled from double __thiscall CDynListEntry::SortValue(CDynListEntry *this, int a2)
float  CDynListEntry::SortValue(int) {
  
  return (float)*((int *)this + 2);
}


// address=[0x2f4c910]
// Decompiled from int __thiscall CDynListEntry::GetIndex(CDynListEntry *this)
int  CDynListEntry::GetIndex(void) {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2f4c9e0]
// Decompiled from int __thiscall CDynListEntry::Next(CDynListEntry *this)
class CDynListEntry *  CDynListEntry::Next(void) {
  
  return *((_DWORD *)this + 1);
}


