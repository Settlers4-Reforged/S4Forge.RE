#include "CConditionSet.h"

// Definitions for class CConditionSet

// address=[0x2f3ee40]
// Decompiled from CConditionSet *__thiscall CConditionSet::CConditionSet(CConditionSet *this)
 CConditionSet::CConditionSet(void) {
  
  CDynList *v3; // [esp+Ch] [ebp-14h]
  CDynList *C; // [esp+10h] [ebp-10h]

  C = (CDynList *)operator new(0xCu);
  if ( C )
    v3 = CDynList::CDynList(C);
  else
    v3 = 0;
  *(_DWORD *)this = v3;
  return this;
}


// address=[0x2f3eec0]
// Decompiled from CDynList **__thiscall CConditionSet::~CConditionSet(CDynList **this)
 CConditionSet::~CConditionSet(void) {
  
  CDynList **result; // eax

  result = this;
  if ( *this )
    return (CDynList **)CDynList::`scalar deleting destructor'(*this, 1u);
  return result;
}


// address=[0x2f3ef00]
// Decompiled from int __thiscall CConditionSet::size(CDynList **this)
int  CConditionSet::size(void) {
  
  return CDynList::size(*this);
}


// address=[0x2f3ef20]
// Decompiled from int __thiscall CConditionSet::elementAt(CDynList **this, int a2)
class CCondition *  CConditionSet::elementAt(int) {
  
  return CDynList::elementAt(*this, a2);
}


// address=[0x2f3ef40]
// Decompiled from void __thiscall CConditionSet::NewMayProblem(CConditionSet *this, int a2, struct CParam *a3)
void  CConditionSet::NewMayProblem(int,class CParam *) {
  
  COptimizeOptions *v4; // [esp+10h] [ebp-14h]
  COptimizeOptions *C; // [esp+14h] [ebp-10h]

  C = (COptimizeOptions *)operator new(0x18u);
  if ( C )
    v4 = COptimizeOptions::COptimizeOptions(C);
  else
    v4 = 0;
  *((_DWORD *)v4 + 4) = 0;
  CConditionSet::NewProblem(this, a2, a3, v4);
}


// address=[0x2f3efe0]
// Decompiled from void __thiscall CConditionSet::NewMayProblem_0(  CConditionSet *this,  int a2,  struct CParam *a3,  struct COptimizeOptions *a4)
void  CConditionSet::NewMayProblem(int,class CParam *,class COptimizeOptions *) {
  
  *((_DWORD *)a4 + 4) = 0;
  CConditionSet::NewProblem(this, a2, a3, a4);
}


// address=[0x2f3f010]
// Decompiled from void __thiscall CConditionSet::NewProblem(CConditionSet *this, int a2, struct CParam *a3)
void  CConditionSet::NewProblem(int,class CParam *) {
  
  struct COptimizeOptions *v4; // [esp+10h] [ebp-14h]
  COptimizeOptions *C; // [esp+14h] [ebp-10h]

  C = (COptimizeOptions *)operator new(0x18u);
  if ( C )
    v4 = COptimizeOptions::COptimizeOptions(C);
  else
    v4 = 0;
  CConditionSet::NewProblem(this, a2, a3, v4);
}


// address=[0x2f3f0a0]
// Decompiled from int __thiscall CConditionSet::NewProblem(CDynList **this, int a2, struct CParam *a3, struct COptimizeOptions *a4)
void  CConditionSet::NewProblem(int,class CParam *,class COptimizeOptions *) {
  
  struct CDynListEntry *v5; // [esp+10h] [ebp-24h]
  CCondition *v6; // [esp+14h] [ebp-20h]
  struct CDynListEntry *v7; // [esp+18h] [ebp-1Ch]
  CCondition *C; // [esp+1Ch] [ebp-18h]
  int i; // [esp+24h] [ebp-10h]

  if ( CDynList::size(*this) <= 0 )
  {
    v6 = (CCondition *)operator new(0x18u);
    if ( v6 )
      v5 = CCondition::CCondition(v6, a2, a3, a4);
    else
      v5 = 0;
    return CDynList::addElement(*this, v5);
  }
  else
  {
    for ( i = 0; i < CDynList::size(*this) && *(_DWORD *)a4 <= **(_DWORD **)(CDynList::elementAt(*this, i) + 20); ++i )
      ;
    C = (CCondition *)operator new(0x18u);
    if ( C )
      v7 = CCondition::CCondition(C, a2, a3, a4);
    else
      v7 = 0;
    return CDynList::insertElementAt(*this, v7, i);
  }
}


// address=[0x2f3f1e0]
// Decompiled from int __thiscall CConditionSet::Ausgabe(CDynList **this)
void  CConditionSet::Ausgabe(void) {
  
  int result; // eax
  int v2; // eax
  int v3; // [esp-8h] [ebp-14h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = CDynList::size(*this);
    if ( i >= result )
      break;
    v3 = *(_DWORD *)(CDynList::elementAt(*this, i) + 12);
    std::operator<<<std::char_traits<char>>((int)&std::cout, "pSolutionSet ermittelt ! ");
    v2 = std::ostream::operator<<(v3);
    std::operator<<<std::char_traits<char>>(v2, " \n");
  }
  return result;
}


