#include "IAI_Module.h"

// Definitions for class IAI_Module

// address=[0x2f3ced0]
// Decompiled from IAI_Module *__thiscall IAI_Module::IAI_Module(IAI_Module *this)
 IAI_Module::IAI_Module(void) {
  
  CDynList *v2; // [esp+Ch] [ebp-20h]
  CDynList *v3; // [esp+10h] [ebp-1Ch]
  CDynList *v4; // [esp+14h] [ebp-18h]
  CDynList *C; // [esp+18h] [ebp-14h]

  *(_DWORD *)this = IAI_Module::_vftable_;
  C = (CDynList *)operator new(0xCu);
  if ( C )
    v4 = CDynList::CDynList(C);
  else
    v4 = 0;
  *((_DWORD *)this + 1) = v4;
  v3 = (CDynList *)operator new(0xCu);
  if ( v3 )
    v2 = CDynList::CDynList(v3);
  else
    v2 = 0;
  *((_DWORD *)this + 2) = v2;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 200;
  *((_DWORD *)this + 5) = 200;
  return this;
}


// address=[0x2f3cfc0]
// Decompiled from CDynList *__thiscall IAI_Module::~IAI_Module(CDynList **this)
 IAI_Module::~IAI_Module(void) {
  
  CDynList *result; // eax

  *this = (CDynList *)IAI_Module::_vftable_;
  if ( this[1] )
    delete this[1];
  this[1] = 0;
  result = this[2];
  if ( result )
    result = (CDynList *)delete this[2];
  this[2] = 0;
  return result;
}


// address=[0x2f3d040]
// Decompiled from int __thiscall IAI_Module::NewSolutionEdge(CDynList **this, int a2, int a3)
void  IAI_Module::NewSolutionEdge(int a2, int a3) {
  
  struct CDynListEntry *v5; // [esp+10h] [ebp-14h]
  CSolutionEdge *C; // [esp+14h] [ebp-10h]

  C = (CSolutionEdge *)operator new(0x14u);
  if ( C )
    v5 = CSolutionEdge::CSolutionEdge(C, a2, a3);
  else
    v5 = 0;
  return CDynList::addElement(this[1], v5);
}


// address=[0x2f3d0e0]
// Decompiled from struct CSolutionTree *__thiscall IAI_Module::Problem(IAI_Module *this, int a2, int a3, int a4, int a5, int a6)
class CSolutionTree *  IAI_Module::Problem(int a2, int a3, int a4, int a5, int a6) {
  
  struct CSolutionTree *v7; // [esp+1Ch] [ebp-34h]
  struct COptimizeOptions *v9; // [esp+30h] [ebp-20h]
  COptimizeOptions *v10; // [esp+34h] [ebp-1Ch]
  struct CParam *v11; // [esp+38h] [ebp-18h]
  CParam *C; // [esp+3Ch] [ebp-14h]

  C = (CParam *)operator new(0x1Cu);
  if ( C )
    v11 = CParam::CParam(C, a3, a4, a5, a6);
  else
    v11 = 0;
  v10 = (COptimizeOptions *)operator new(0x18u);
  if ( v10 )
    v9 = COptimizeOptions::COptimizeOptions(v10);
  else
    v9 = 0;
  *((_DWORD *)this + 3) = 0;
  v7 = IAI_Module::ProblemSolve(this, a2, v11, v9);
  if ( v11 )
    (**(void (__thiscall ***)(struct CParam *, int))v11)(v11, 1);
  if ( v9 )
    delete v9;
  return v7;
}


// address=[0x2f3d230]
// Decompiled from void __thiscall IAI_Module::Execute(IAI_Module *this, struct CSolutionTree *a2)
void  IAI_Module::Execute(class CSolutionTree * a2) {
  
  if ( a2 )
    IAI_Module::ExecuteSolution(this, a2);
}


// address=[0x2f3d250]
// Decompiled from char __thiscall IAI_Module::checkSolutionForRepeating(CDynList **this, int a2)
bool  IAI_Module::checkSolutionForRepeating(int a2) {
  
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[2]); ++i )
  {
    if ( a2 == *(_DWORD *)(CDynList::elementAt(this[2], i) + 12) )
      return 1;
  }
  return 0;
}


// address=[0x2f3d2b0]
// Decompiled from char __thiscall IAI_Module::checkSolutionForExactRepeating(CDynList **this, int a2, CParam *a3)
bool  IAI_Module::checkSolutionForExactRepeating(int a2, class CParam * a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[2]); ++i )
  {
    v4 = CDynList::elementAt(this[2], i);
    if ( a2 == *(_DWORD *)(v4 + 12) && CParam::ParamAreEqual(a3, *(struct CParam **)(v4 + 16)) )
      return 1;
  }
  return 0;
}


// address=[0x2f3d320]
// Decompiled from char __thiscall IAI_Module::checkSolutionForSpecialRepeating(  CDynList **this,  int a2,  _DWORD *a3,  int a4,  int a5,  int a6,  int a7)
bool  IAI_Module::checkSolutionForSpecialRepeating(int a2, class CParam * a3, int a4, int a5, int a6, int a7) {
  
  int i; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[2]); ++i )
  {
    v10 = CDynList::elementAt(this[2], i);
    if ( a2 == *(_DWORD *)(v10 + 12)
      && (*(_DWORD *)(*(_DWORD *)(v10 + 16) + 12) == a3[3] || !a4)
      && (*(_DWORD *)(*(_DWORD *)(v10 + 16) + 16) == a3[4] || !a5)
      && (*(_DWORD *)(*(_DWORD *)(v10 + 16) + 20) == a3[5] || !a6)
      && (*(_DWORD *)(*(_DWORD *)(v10 + 16) + 24) == a3[6] || !a7) )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x2f3d3e0]
// Decompiled from int __stdcall IAI_Module::SetOptimierung(int a1, int a2, int a3)
void  IAI_Module::SetOptimierung(class COptimizeOptions * a1, int a2, int a3) {
  
  int result; // eax

  *(_DWORD *)(a1 + 4) = a2;
  result = a3;
  *(_DWORD *)(a1 + 8) = a3;
  return result;
}


// address=[0x2f3d400]
// Decompiled from _DWORD *__thiscall IAI_Module::SetHorizont(_DWORD *this, int a2, int a3)
void  IAI_Module::SetHorizont(class COptimizeOptions * a2, int a3) {
  
  _DWORD *result; // eax

  result = this;
  this[5] = this[3] + a3;
  return result;
}


// address=[0x2f3d420]
// Decompiled from _DWORD *__stdcall IAI_Module::SetPrioritaet(_DWORD *a1, int a2)
void  IAI_Module::SetPrioritaet(class COptimizeOptions * a1, int a2) {
  
  _DWORD *result; // eax

  result = a1;
  *a1 = a2;
  return result;
}


// address=[0x2f3d440]
// Decompiled from struct COptimizeOptions *__thiscall IAI_Module::SetMaxSolution(IAI_Module *this, struct COptimizeOptions *a2, int a3)
void  IAI_Module::SetMaxSolution(class COptimizeOptions * a2, int a3) {
  
  struct COptimizeOptions *result; // eax

  result = a2;
  *((_DWORD *)a2 + 5) = a3;
  return result;
}


// address=[0x2f3d460]
// Decompiled from struct CSolutionTree *__thiscall IAI_Module::ProblemSolve(  IAI_Module *this,  int a2,  struct CParam *a3,  struct COptimizeOptions *a4)
class CSolutionTree *  IAI_Module::ProblemSolve(int a2, class CParam * a3, class COptimizeOptions * a4) {
  
  struct CParam *v5; // [esp+64h] [ebp-80h]
  int v6; // [esp+74h] [ebp-70h]
  CSolutionTree *v7; // [esp+78h] [ebp-6Ch]
  CSolutionTree *v8; // [esp+7Ch] [ebp-68h]
  CDynList **v9; // [esp+80h] [ebp-64h]
  CSolutionSet *C; // [esp+84h] [ebp-60h]
  int v11; // [esp+98h] [ebp-4Ch]
  int v12; // [esp+ACh] [ebp-38h]
  int j; // [esp+B0h] [ebp-34h]
  struct CSolutionTree *v14; // [esp+B4h] [ebp-30h]
  struct CSolutionTree *BestSolution; // [esp+B8h] [ebp-2Ch]
  CConditionSet *v16; // [esp+BCh] [ebp-28h]
  CParameterSet *v17; // [esp+C0h] [ebp-24h]
  struct CCondition *v18; // [esp+C4h] [ebp-20h]
  int i; // [esp+C8h] [ebp-1Ch]
  int k; // [esp+C8h] [ebp-1Ch]
  int v21; // [esp+CCh] [ebp-18h]

  v16 = 0;
  v6 = 0;
  if ( ++*((_DWORD *)this + 3) > *((_DWORD *)this + 4) )
  {
    --*((_DWORD *)this + 3);
    return 0;
  }
  if ( *((_DWORD *)this + 3) > *((_DWORD *)this + 5) && *((_DWORD *)this + 5) )
  {
    --*((_DWORD *)this + 3);
    return 0;
  }
  C = (CSolutionSet *)operator new(0x10u);
  if ( C )
    v9 = (CDynList **)CSolutionSet::CSolutionSet(C);
  else
    v9 = 0;
  for ( i = 0; i < CDynList::size(*((CDynList **)this + 1)); ++i )
  {
    v12 = CDynList::elementAt(*((CDynList **)this + 1), i);
    if ( *(_DWORD *)(v12 + 16) == a2 )
    {
      v17 = (CParameterSet *)(*(int (__thiscall **)(IAI_Module *, _DWORD, struct CParam *))(*(_DWORD *)this + 12))(
                               this,
                               *(_DWORD *)(v12 + 12),
                               a3);
      if ( v17 )
      {
        if ( CParameterSet::size(v17) )
        {
          for ( j = 0; j < CParameterSet::size(v17); ++j )
          {
            v5 = CParameterSet::elementAt(v17, j);
            CSolutionSet::NewSolution((CSolutionSet *)v9, *(_DWORD *)(v12 + 12), v5);
          }
        }
        (**(void (__thiscall ***)(CParameterSet *, int))v17)(v17, 1);
      }
      else
      {
        CSolutionSet::NewSolution((CSolutionSet *)v9, *(_DWORD *)(v12 + 12), a3);
      }
    }
  }
  if ( !CSolutionSet::size((CSolutionSet *)v9) )
  {
    --*((_DWORD *)this + 3);
    if ( v9 )
      (*(void (__thiscall **)(CDynList **, int))*v9)(v9, 1);
    return 0;
  }
  if ( (int)CSolutionSet::size((CSolutionSet *)v9) > 1 )
  {
    BestSolution = IAI_Module::GetBestSolution(this, (struct CSolutionSet *)v9, a4);
    if ( !BestSolution )
    {
      --*((_DWORD *)this + 3);
      if ( v9 )
        (*(void (__thiscall **)(CDynList **, int))*v9)(v9, 1);
      return 0;
    }
    goto LABEL_63;
  }
  v21 = CDynList::elementAt(v9[3], 0);
  if ( IAI_Module::checkSolutionForRepeating((CDynList **)this, *(_DWORD *)(v21 + 12)) )
  {
    v11 = (*(int (__thiscall **)(IAI_Module *, _DWORD, _DWORD))(*(_DWORD *)this + 8))(
            this,
            *(_DWORD *)(v21 + 12),
            *(_DWORD *)(v21 + 16));
    if ( !v11 )
    {
      --*((_DWORD *)this + 3);
      if ( v9 )
        (*(void (__thiscall **)(CDynList **, int))*v9)(v9, 1);
      return 0;
    }
    if ( v11 == 2 )
    {
      --*((_DWORD *)this + 3);
      if ( v9 )
        (*(void (__thiscall **)(CDynList **, int))*v9)(v9, 1);
      *((_DWORD *)a4 + 4) = 0;
      return 0;
    }
  }
  v8 = (CSolutionTree *)operator new(0x18u);
  if ( v8 )
    v7 = CSolutionTree::CSolutionTree(v8, *(_DWORD *)(v21 + 12), *(struct CParam **)(v21 + 16));
  else
    v7 = 0;
  BestSolution = v7;
  (*(void (__thiscall **)(IAI_Module *, _DWORD, _DWORD))(*(_DWORD *)this + 16))(
    this,
    *(_DWORD *)(v21 + 12),
    *(_DWORD *)(v21 + 16));
  v16 = (CConditionSet *)(**(int (__thiscall ***)(IAI_Module *, _DWORD, _DWORD))this)(
                           this,
                           *(_DWORD *)(v21 + 12),
                           *(_DWORD *)(v21 + 16));
  if ( (int)CConditionSet::size(v16) <= 0 )
  {
LABEL_63:
    --*((_DWORD *)this + 3);
    if ( v16 )
      delete v16;
    if ( v9 )
      (*(void (__thiscall **)(CDynList **, int))*v9)(v9, 1);
    return BestSolution;
  }
  for ( k = 0; k < CConditionSet::size(v16); ++k )
  {
    v18 = CConditionSet::elementAt(v16, k);
    v6 = *((_DWORD *)this + 5);
    if ( *(_DWORD *)(*((_DWORD *)v18 + 5) + 12)
      && (*(_DWORD *)(*((_DWORD *)v18 + 5) + 12) < *((_DWORD *)this + 5) || !*((_DWORD *)this + 5)) )
    {
      *((_DWORD *)this + 5) = *(_DWORD *)(*((_DWORD *)v18 + 5) + 12);
    }
  }
  v14 = IAI_Module::TryImportSolution(this, *((_DWORD *)v18 + 3), *((struct CParam **)v18 + 4));
  if ( !v14 )
    v14 = IAI_Module::ProblemSolve(
            this,
            *((_DWORD *)v18 + 3),
            *((struct CParam **)v18 + 4),
            *((struct COptimizeOptions **)v18 + 5));
  *((_DWORD *)this + 5) = v6;
  if ( v14 )
  {
    CSolutionTree::NewSubSolution(v7, v14);
    goto LABEL_63;
  }
  if ( *(_DWORD *)(*((_DWORD *)v18 + 5) + 16) != 1 )
    goto LABEL_63;
  --*((_DWORD *)this + 3);
  if ( v9 )
    (*(void (__thiscall **)(CDynList **, int))*v9)(v9, 1);
  if ( v16 )
    delete v16;
  if ( v7 )
    (**(void (__thiscall ***)(CSolutionTree *, int))v7)(v7, 1);
  return 0;
}


// address=[0x2f3db10]
// Decompiled from struct CSolutionTree *__thiscall IAI_Module::GetBestSolution(  CDynList **this,  CDynList **a2,  struct COptimizeOptions *a3)
class CSolutionTree *  IAI_Module::GetBestSolution(class CSolutionSet * a2, class COptimizeOptions * a3) {
  
  double v4; // [esp+3Ch] [ebp-74h]
  double v5; // [esp+44h] [ebp-6Ch]
  CSolutionTree *v6; // [esp+50h] [ebp-60h]
  CSolutionTree *v7; // [esp+54h] [ebp-5Ch]
  CDynList *v8; // [esp+58h] [ebp-58h]
  CSolutionTree *v9; // [esp+5Ch] [ebp-54h]
  CSolutionTree *v10; // [esp+60h] [ebp-50h]
  CSolutionTree *v11; // [esp+64h] [ebp-4Ch]
  CSolutionTree *C; // [esp+68h] [ebp-48h]
  int v13; // [esp+6Ch] [ebp-44h]
  int v14; // [esp+7Ch] [ebp-34h]
  CConditionSet *v15; // [esp+80h] [ebp-30h]
  int j; // [esp+84h] [ebp-2Ch]
  int i; // [esp+88h] [ebp-28h]
  struct CSolutionTree *v18; // [esp+8Ch] [ebp-24h]
  struct CSolutionTree *v19; // [esp+90h] [ebp-20h]
  struct CCondition *v20; // [esp+94h] [ebp-1Ch]
  struct CSolutionTree *v21; // [esp+98h] [ebp-18h]
  int v22; // [esp+9Ch] [ebp-14h]

  v18 = 0;
  v4 = DOUBLE_N100000_0;
  v13 = 0;
  if ( !*((_DWORD *)a3 + 1) )
    v4 = DOUBLE_100000_0;
  for ( i = 0; ; ++i )
  {
    if ( i >= CSolutionSet::size((CSolutionSet *)a2) )
      return v18;
    v22 = CDynList::elementAt(a2[3], i);
    if ( IAI_Module::checkSolutionForRepeating(this, *(_DWORD *)(v22 + 12)) )
    {
      v14 = (*((int (__thiscall **)(CDynList **, _DWORD, _DWORD))*this + 2))(
              this,
              *(_DWORD *)(v22 + 12),
              *(_DWORD *)(v22 + 16));
      if ( !v14 )
        continue;
      if ( v14 == 2 )
        break;
    }
    (*((void (__thiscall **)(CDynList **, _DWORD, _DWORD))*this + 4))(
      this,
      *(_DWORD *)(v22 + 12),
      *(_DWORD *)(v22 + 16));
    v15 = (CConditionSet *)(*(int (__thiscall **)(CDynList **, _DWORD, _DWORD))*this)(
                             this,
                             *(_DWORD *)(v22 + 12),
                             *(_DWORD *)(v22 + 16));
    if ( (int)CConditionSet::size(v15) <= 0 )
    {
      v7 = (CSolutionTree *)operator new(0x18u);
      if ( v7 )
        v6 = CSolutionTree::CSolutionTree(v7, *(_DWORD *)(v22 + 12), *(struct CParam **)(v22 + 16));
      else
        v6 = 0;
      v21 = v6;
    }
    else
    {
      v10 = (CSolutionTree *)operator new(0x18u);
      if ( v10 )
        v9 = CSolutionTree::CSolutionTree(v10, *(_DWORD *)(v22 + 12), *(struct CParam **)(v22 + 16));
      else
        v9 = 0;
      v21 = v9;
      for ( j = 0; j < CConditionSet::size(v15); ++j )
      {
        v20 = CConditionSet::elementAt(v15, j);
        v8 = this[5];
        if ( *(_DWORD *)(*((_DWORD *)v20 + 5) + 12)
          && (*(_DWORD *)(*((_DWORD *)v20 + 5) + 12) < (int)this[5] || !this[5]) )
        {
          this[5] = *(CDynList **)(*((_DWORD *)v20 + 5) + 12);
        }
        v19 = IAI_Module::TryImportSolution((IAI_Module *)this, *((_DWORD *)v20 + 3), *((struct CParam **)v20 + 4));
        if ( !v19 )
          v19 = IAI_Module::ProblemSolve(
                  (IAI_Module *)this,
                  *((_DWORD *)v20 + 3),
                  *((struct CParam **)v20 + 4),
                  *((struct COptimizeOptions **)v20 + 5));
        this[5] = v8;
        if ( !v19 )
        {
          if ( v9 )
            (**(void (__thiscall ***)(CSolutionTree *, int))v9)(v9, 1);
          v21 = 0;
          break;
        }
        CSolutionTree::NewSubSolution(v9, v19);
      }
    }
    if ( v15 )
      delete v15;
    if ( v21 )
    {
      if ( ((++v13,
             v5 = IAI_Module::ValuationSubSolution((IAI_Module *)this, v21, *((_DWORD *)a3 + 1), *((_DWORD *)a3 + 2)),
             v5 < v4)
         || *((_DWORD *)a3 + 1) != 1)
        && (v4 <= v5 || *((_DWORD *)a3 + 1)) )
      {
        (**(void (__thiscall ***)(struct CSolutionTree *, int))v21)(v21, 1);
      }
      else
      {
        v4 = v5;
        v18 = v21;
      }
      if ( v13 == *((_DWORD *)a3 + 5) && *((_DWORD *)a3 + 5) )
        return v18;
    }
  }
  C = (CSolutionTree *)operator new(0x18u);
  if ( C )
    v11 = CSolutionTree::CSolutionTree(C, *(_DWORD *)(v22 + 12), *(struct CParam **)(v22 + 16));
  else
    v11 = 0;
  *((_DWORD *)a3 + 4) = 0;
  if ( v11 )
    (**(void (__thiscall ***)(CSolutionTree *, int))v11)(v11, 1);
  return 0;
}


// address=[0x2f3dfd0]
// Decompiled from int __thiscall IAI_Module::TryImportSolution(IAI_Module *this, int a2, struct CParam *a3)
class CSolutionTree *  IAI_Module::TryImportSolution(int a2, class CParam * a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]

  v4 = (*(int (__thiscall **)(IAI_Module *, int, struct CParam *))(*(_DWORD *)this + 36))(this, a2, a3);
  if ( v4 == 1 )
    return (*(int (__thiscall **)(IAI_Module *, int, struct CParam *))(*(_DWORD *)this + 40))(this, a2, a3);
  if ( v4 != 2 )
    return 0;
  v5 = (*(int (__thiscall **)(IAI_Module *, int, struct CParam *))(*(_DWORD *)this + 40))(this, a2, a3);
  if ( v5 )
    return v5;
  return 0;
}


// address=[0x2f3e050]
// Decompiled from CDynList *__thiscall IAI_Module::DeleteHistory(CDynList **this)
void  IAI_Module::DeleteHistory(void) {
  
  CDynList *result; // eax
  CDynList *v3; // [esp+14h] [ebp-18h]
  CDynList *C; // [esp+18h] [ebp-14h]

  if ( this[2] )
    delete this[2];
  C = (CDynList *)operator new(0xCu);
  if ( C )
    v3 = CDynList::CDynList(C);
  else
    v3 = 0;
  result = v3;
  this[2] = v3;
  return result;
}


// address=[0x2f3e100]
// Decompiled from int __thiscall IAI_Module::NewSolutionInHistory(CDynList **this, int a2, struct CParam *a3)
void  IAI_Module::NewSolutionInHistory(int a2, class CParam * a3) {
  
  struct CDynListEntry *v5; // [esp+Ch] [ebp-14h]
  CHistorySolution *C; // [esp+10h] [ebp-10h]

  C = (CHistorySolution *)operator new(0x14u);
  if ( C )
    v5 = CHistorySolution::CHistorySolution(C, a2, a3);
  else
    v5 = 0;
  return CDynList::addElement(this[2], v5);
}


// address=[0x2f3e190]
// Decompiled from int __thiscall IAI_Module::NewSolutionInHistory(CDynList **this, struct CSolutionTree *a2)
void  IAI_Module::NewSolutionInHistory(class CSolutionTree * a2) {
  
  struct CSolutionTree *v3; // [esp+8h] [ebp-2Ch]
  struct CDynListEntry *v4; // [esp+10h] [ebp-24h]
  CHistorySolution *v5; // [esp+14h] [ebp-20h]
  struct CDynListEntry *v6; // [esp+18h] [ebp-1Ch]
  CHistorySolution *C; // [esp+1Ch] [ebp-18h]
  int i; // [esp+24h] [ebp-10h]

  if ( CDynList::isEmpty(*((CDynList **)a2 + 5)) )
  {
    C = (CHistorySolution *)operator new(0x14u);
    if ( C )
      v6 = CHistorySolution::CHistorySolution(C, *((_DWORD *)a2 + 4), *((struct CParam **)a2 + 3));
    else
      v6 = 0;
    return CDynList::addElement(this[2], v6);
  }
  else
  {
    for ( i = 0; i < CDynList::size(*((CDynList **)a2 + 5)); ++i )
    {
      v3 = (struct CSolutionTree *)CDynList::elementAt(*((CDynList **)a2 + 5), i);
      IAI_Module::NewSolutionInHistory((IAI_Module *)this, v3);
    }
    v5 = (CHistorySolution *)operator new(0x14u);
    if ( v5 )
      v4 = CHistorySolution::CHistorySolution(v5, *((_DWORD *)a2 + 4), *((struct CParam **)a2 + 3));
    else
      v4 = 0;
    return CDynList::addElement(this[2], v4);
  }
}


// address=[0x2f3e2d0]
// Decompiled from CDynList *__thiscall IAI_Module::CloneHistorie(IAI_Module *this, struct CDynList *a2)
class CDynList *  IAI_Module::CloneHistorie(class CDynList *) {
  
  struct CDynListEntry *v3; // [esp+14h] [ebp-24h]
  CHistorySolution *v4; // [esp+18h] [ebp-20h]
  CDynList *v5; // [esp+1Ch] [ebp-1Ch]
  CDynList *C; // [esp+20h] [ebp-18h]
  int v7; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]

  C = (CDynList *)operator new(0xCu);
  if ( C )
    v5 = CDynList::CDynList(C);
  else
    v5 = 0;
  for ( i = 0; i < CDynList::size(a2); ++i )
  {
    v7 = CDynList::elementAt(a2, i);
    v4 = (CHistorySolution *)operator new(0x14u);
    if ( v4 )
      v3 = CHistorySolution::CHistorySolution(v4, *(_DWORD *)(v7 + 12), *(struct CParam **)(v7 + 16));
    else
      v3 = 0;
    CDynList::addElement(v5, v3);
  }
  return v5;
}


// address=[0x2f3e3e0]
// Decompiled from double __thiscall IAI_Module::ValuationSubSolution(IAI_Module *this, struct CSolutionTree *a2, int a3, int a4)
double  IAI_Module::ValuationSubSolution(class CSolutionTree * a2, int a3, int a4) {
  
  double v5; // [esp+20h] [ebp-14h]
  struct CSolutionTree *v7; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]

  if ( a4 == 1 )
    v5 = DOUBLE_1_0;
  else
    v5 = 0.0;
  if ( CDynList::isEmpty(*((CDynList **)a2 + 5)) )
    return ((double (__thiscall *)(IAI_Module *, _DWORD, _DWORD, int, int))*(_DWORD *)(*(_DWORD *)this + 4))(
             this,
             *((_DWORD *)a2 + 4),
             *((_DWORD *)a2 + 3),
             a3,
             a4);
  for ( i = 0; i < CDynList::size(*((CDynList **)a2 + 5)); ++i )
  {
    v7 = (struct CSolutionTree *)CDynList::elementAt(*((CDynList **)a2 + 5), i);
    if ( a4 == 1 )
      v5 = IAI_Module::ValuationSubSolution(this, v7, a3, 1) * v5;
    else
      v5 = IAI_Module::ValuationSubSolution(this, v7, a3, a4) + v5;
  }
  if ( a4 == 1 )
    return ((double (__thiscall *)(IAI_Module *, _DWORD, _DWORD, int, int))*(_DWORD *)(*(_DWORD *)this + 4))(
             this,
             *((_DWORD *)a2 + 4),
             *((_DWORD *)a2 + 3),
             a3,
             1)
         * v5;
  else
    return ((double (__thiscall *)(IAI_Module *, _DWORD, _DWORD, int, int))*(_DWORD *)(*(_DWORD *)this + 4))(
             this,
             *((_DWORD *)a2 + 4),
             *((_DWORD *)a2 + 3),
             a3,
             a4)
         + v5;
}


// address=[0x2f3e550]
// Decompiled from int __thiscall IAI_Module::Netzplan_ausgeben(CDynList **this)
void  IAI_Module::Netzplan_ausgeben(void) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = CDynList::size(this[1]);
    if ( i >= result )
      break;
    CDynList::elementAt(this[1], i);
  }
  return result;
}


// address=[0x2f3e5a0]
// Decompiled from int __thiscall IAI_Module::gleiche_loesung_suchen(CDynList **this, int a2, int a3)
class CHistorySolution *  IAI_Module::gleiche_loesung_suchen(int a2, class CParam * a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[2]); ++i )
  {
    v4 = CDynList::elementAt(this[2], i);
    if ( a2 == *(_DWORD *)(v4 + 12) )
      return v4;
  }
  return 0;
}


// address=[0x2f3e600]
// Decompiled from int __thiscall IAI_Module::PreExecuteSolution(IAI_Module *this, CDynList **a2)
void  IAI_Module::PreExecuteSolution(class CSolutionTree * a2) {
  
  struct CSolutionTree *v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  if ( !CDynList::isEmpty(a2[5]) )
  {
    for ( i = 0; i < CDynList::size(a2[5]); ++i )
    {
      v3 = (struct CSolutionTree *)CDynList::elementAt(a2[5], i);
      ++*((_DWORD *)this + 3);
      IAI_Module::PreExecuteSolution(this, v3);
      --*((_DWORD *)this + 3);
    }
  }
  return (*(int (__thiscall **)(IAI_Module *, CDynList *, CDynList *))(*(_DWORD *)this + 32))(this, a2[4], a2[3]);
}


// address=[0x2f3e6c0]
// Decompiled from int __thiscall IAI_Module::ExecuteSolution(IAI_Module *this, CDynList **a2)
void  IAI_Module::ExecuteSolution(class CSolutionTree * a2) {
  
  struct CSolutionTree *v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  if ( !CDynList::isEmpty(a2[5]) )
  {
    for ( i = 0; i < CDynList::size(a2[5]); ++i )
    {
      v3 = (struct CSolutionTree *)CDynList::elementAt(a2[5], i);
      ++*((_DWORD *)this + 3);
      IAI_Module::ExecuteSolution(this, v3);
      --*((_DWORD *)this + 3);
    }
  }
  return (*(int (__thiscall **)(IAI_Module *, CDynList *, CDynList *))(*(_DWORD *)this + 28))(this, a2[4], a2[3]);
}


// address=[0x2f3e780]
// Decompiled from int __thiscall IAI_Module::t(IAI_Module *this, int a2)
void  IAI_Module::t(int a2) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < a2 + 1; ++i )
  {
    std::operator<<<std::char_traits<char>>((int)&std::cout, "  ");
    result = i + 1;
  }
  return result;
}


// address=[0x2f3e7c0]
// Decompiled from int __thiscall IAI_Module::t_0(int *this)
void  IAI_Module::t(void) {
  
  return IAI_Module::t((IAI_Module *)this, this[3]);
}


