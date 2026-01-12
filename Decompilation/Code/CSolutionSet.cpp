#include "CSolutionSet.h"

// Definitions for class CSolutionSet

// address=[0x2f3f250]
// Decompiled from CSolutionSet *__thiscall CSolutionSet::CSolutionSet(CSolutionSet *this)

 CSolutionSet::CSolutionSet(void) {
  
  CDynList *v2; // [esp+8h] [ebp-18h]
  CDynList *C; // [esp+Ch] [ebp-14h]

  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CSolutionSet::_vftable_;
  C = (CDynList *)operator new(0xCu);
  if ( C )
    v2 = CDynList::CDynList(C);
  else
    v2 = 0;
  *((_DWORD *)this + 3) = v2;
  return this;
}


// address=[0x2f3f2f0]
// Decompiled from void __thiscall CSolutionSet::~CSolutionSet(CDynList **this)

 CSolutionSet::~CSolutionSet(void) {
  
  *this = (CDynList *)&CSolutionSet::_vftable_;
  if ( this[3] )
    CDynList::`scalar deleting destructor'(this[3], 1u);
  CDynListEntry::~CDynListEntry((CDynListEntry *)this);
}


// address=[0x2f3f340]
// Decompiled from int __thiscall CSolutionSet::size(CDynList **this)

int  CSolutionSet::size(void) {
  
  return CDynList::size(this[3]);
}


// address=[0x2f3f360]
// Decompiled from int __thiscall CSolutionSet::NewSolution(CDynList **this, int a2, struct CParam *a3)

void  CSolutionSet::NewSolution(int,class CParam *) {
  
  struct CDynListEntry *v5; // [esp+Ch] [ebp-14h]
  CSolution *C; // [esp+10h] [ebp-10h]

  C = (CSolution *)operator new(0x14u);
  if ( C )
    v5 = CSolution::CSolution(C, a2, a3);
  else
    v5 = 0;
  return CDynList::addElement(this[3], v5);
}


