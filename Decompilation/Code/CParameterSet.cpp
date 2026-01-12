#include "CParameterSet.h"

// Definitions for class CParameterSet

// address=[0x2f3f500]
// Decompiled from CParameterSet *__thiscall CParameterSet::CParameterSet(CParameterSet *this)

 CParameterSet::CParameterSet(void) {
  
  CDynList *v2; // [esp+8h] [ebp-18h]
  CDynList *C; // [esp+Ch] [ebp-14h]

  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CParameterSet::_vftable_;
  C = (CDynList *)operator new(0xCu);
  if ( C )
    v2 = CDynList::CDynList(C);
  else
    v2 = 0;
  *((_DWORD *)this + 3) = v2;
  return this;
}


// address=[0x2f3f5a0]
// Decompiled from void __thiscall CParameterSet::~CParameterSet(CDynList **this)

 CParameterSet::~CParameterSet(void) {
  
  *this = (CDynList *)&CParameterSet::_vftable_;
  if ( this[3] )
    CDynList::`scalar deleting destructor'(this[3], 1u);
  CDynListEntry::~CDynListEntry((CDynListEntry *)this);
}


// address=[0x2f3f5f0]
// Decompiled from int __thiscall CParameterSet::size(CDynList **this)

int  CParameterSet::size(void) {
  
  return CDynList::size(this[3]);
}


// address=[0x2f3f610]
// Decompiled from int __thiscall CParameterSet::elementAt(CDynList **this, int a2)

class CParam *  CParameterSet::elementAt(int) {
  
  return CDynList::elementAt(this[3], a2);
}


// address=[0x2f3f630]
// Decompiled from int __thiscall CParameterSet::NewParameterSet(CDynList **this, struct CParam *a2)

void  CParameterSet::NewParameterSet(class CParam *) {
  
  return CDynList::addElement(this[3], a2);
}


// address=[0x2f3f650]
// Decompiled from int __thiscall CParameterSet::Ausgabe(CDynList **this)

void  CParameterSet::Ausgabe(void) {
  
  int result; // eax
  CParam *C; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]

  C = (CParam *)operator new(0x1Cu);
  if ( C )
    CParam::CParam(C);
  for ( i = 0; ; ++i )
  {
    result = CDynList::size(this[3]);
    if ( i >= result )
      break;
    CDynList::elementAt(this[3], i);
  }
  return result;
}


