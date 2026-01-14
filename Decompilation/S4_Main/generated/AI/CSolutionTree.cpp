#include "all_headers.h"

// Definitions for class CSolutionTree

// address=[0x2f3eac0]
// Decompiled from CDynListEntry *__thiscall CSolutionTree::CSolutionTree(CDynListEntry *this)
 CSolutionTree::CSolutionTree(void) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CSolutionTree::_vftable_;
  return this;
}


// address=[0x2f3eae0]
// Decompiled from void __thiscall CSolutionTree::~CSolutionTree(CDynList **this)
 CSolutionTree::~CSolutionTree(void) {
  
  *this = (CDynList *)&CSolutionTree::_vftable_;
  if ( this[5] )
    CDynList::`scalar deleting destructor'(this[5], 1u);
  if ( this[3] )
    (**(void (__thiscall ***)(CDynList *, int))this[3])(this[3], 1);
  CDynListEntry::~CDynListEntry((CDynListEntry *)this);
}


// address=[0x2f3eb60]
// Decompiled from CSolutionTree *__thiscall CSolutionTree::CSolutionTree(CSolutionTree *this, int a2, struct CParam *a3)
 CSolutionTree::CSolutionTree(int,class CParam *) {
  
  CDynList *v4; // [esp+Ch] [ebp-20h]
  CDynList *v5; // [esp+10h] [ebp-1Ch]
  CParam *v6; // [esp+14h] [ebp-18h]
  CParam *C; // [esp+18h] [ebp-14h]

  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CSolutionTree::_vftable_;
  C = (CParam *)operator new(0x1Cu);
  if ( C )
    v6 = CParam::CParam(C, a3);
  else
    v6 = 0;
  *((_DWORD *)this + 3) = v6;
  *((_DWORD *)this + 4) = a2;
  v5 = (CDynList *)operator new(0xCu);
  if ( v5 )
    v4 = CDynList::CDynList(v5);
  else
    v4 = 0;
  *((_DWORD *)this + 5) = v4;
  return this;
}


// address=[0x2f3ec50]
// Decompiled from int __thiscall CSolutionTree::NewSubSolution(CDynList **this, int a2, struct CParam *a3)
void  CSolutionTree::NewSubSolution(int,class CParam *) {
  
  struct CDynListEntry *v5; // [esp+Ch] [ebp-14h]
  CSolutionTree *C; // [esp+10h] [ebp-10h]

  C = (CSolutionTree *)operator new(0x18u);
  if ( C )
    v5 = CSolutionTree::CSolutionTree(C, a2, a3);
  else
    v5 = 0;
  return CDynList::addElement(this[5], v5);
}


// address=[0x2f3ece0]
// Decompiled from int __thiscall CSolutionTree::NewSubSolution(CDynList **this, struct CSolutionTree *a2)
void  CSolutionTree::NewSubSolution(class CSolutionTree *) {
  
  return CDynList::addElement(this[5], a2);
}


