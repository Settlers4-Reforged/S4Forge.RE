#include "CReserveDatabase.h"

// Definitions for class CReserveDatabase

// address=[0x2f3bc30]
// Decompiled from int __thiscall CReserveDatabase::PackPosition(CReserveDatabase *this, int a2, int a3)
int  CReserveDatabase::PackPosition(int,int) {
  
  return a2 + (a3 << 16);
}


// address=[0x2f3bc50]
// Decompiled from int *__thiscall CReserveDatabase::UnpackPosition(CReserveDatabase *this, int a2, int *a3, int *a4)
void  CReserveDatabase::UnpackPosition(int,int &,int &) {
  
  int *result; // eax

  *a3 = (unsigned __int16)a2;
  result = a4;
  *a4 = a2 >> 16;
  return result;
}


// address=[0x2f40540]
// Decompiled from CReserveDatabase *__thiscall CReserveDatabase::CReserveDatabase(CReserveDatabase *this)
 CReserveDatabase::CReserveDatabase(void) {
  
  CDynList *v2; // [esp+10h] [ebp-28h]
  CDynList *v3; // [esp+14h] [ebp-24h]
  CDynList *v4; // [esp+18h] [ebp-20h]
  CDynList *v5; // [esp+1Ch] [ebp-1Ch]
  CDynList *v6; // [esp+20h] [ebp-18h]
  CDynList *C; // [esp+24h] [ebp-14h]

  *((_DWORD *)this + 3) = 0;
  C = (CDynList *)operator new(0xCu);
  if ( C )
    v6 = CDynList::CDynList(C);
  else
    v6 = 0;
  *(_DWORD *)this = v6;
  v5 = (CDynList *)operator new(0xCu);
  if ( v5 )
    v4 = CDynList::CDynList(v5);
  else
    v4 = 0;
  *((_DWORD *)this + 1) = v4;
  v3 = (CDynList *)operator new(0xCu);
  if ( v3 )
    v2 = CDynList::CDynList(v3);
  else
    v2 = 0;
  *((_DWORD *)this + 2) = v2;
  *((_DWORD *)this + 4) = 1;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  return this;
}


// address=[0x2f40670]
// Decompiled from CDynList **__thiscall CReserveDatabase::~CReserveDatabase(CDynList **this)
 CReserveDatabase::~CReserveDatabase(void) {
  
  CDynList **result; // eax

  if ( *this )
    delete *this;
  if ( this[1] )
    delete this[1];
  result = this;
  if ( this[2] )
    return (CDynList **)delete this[2];
  return result;
}


// address=[0x2f40700]
// Decompiled from int __thiscall CReserveDatabase::ReserveBuilding(int this, int a2, int a3, int a4, int a5, char a6, int a7, int a8)
int  CReserveDatabase::ReserveBuilding(enum BUILDING_TYPES,int,int,int,signed char,int,int) {
  
  struct CDynListEntry *v9; // [esp+14h] [ebp-38h]
  CRefGrpEntry *v10; // [esp+18h] [ebp-34h]
  int v11; // [esp+1Ch] [ebp-30h]
  int v12; // [esp+20h] [ebp-2Ch]
  void *v13; // [esp+24h] [ebp-28h]
  int v14; // [esp+28h] [ebp-24h]
  int v15; // [esp+2Ch] [ebp-20h]
  void *C; // [esp+30h] [ebp-1Ch]

  if ( a8 )
  {
    v13 = operator new(0x34u);
    if ( v13 )
      v12 = CGrpReserveEntry::CGrpReserveEntry(v13, a2, a3, a4, a8);
    else
      v12 = 0;
    v11 = *(_DWORD *)(this + 12) + 1;
    *(_DWORD *)(this + 12) = v11;
    *(_DWORD *)(v12 + 24) = v11;
    *(_DWORD *)(v12 + 32) = a5;
    *(_BYTE *)(v12 + 40) = a6;
    *(_DWORD *)(v12 + 28) = a7;
    CReserveDatabase::NewSubReserveEntry((CReserveDatabase *)this, (struct CGrpReserveEntry *)v12, a8);
    v10 = (CRefGrpEntry *)operator new(0x14u);
    if ( v10 )
      v9 = CRefGrpEntry::CRefGrpEntry(v10, *(_DWORD *)(v12 + 24), (struct CGrpReserveEntry *)v12);
    else
      v9 = 0;
    CDynList::addElement(*(CDynList **)(this + 8), v9);
    return *(_DWORD *)(v12 + 24);
  }
  else
  {
    C = operator new(0x2Cu);
    if ( C )
      v15 = CReserveEntry::CReserveEntry(C, a2, a3, a4);
    else
      v15 = 0;
    v14 = *(_DWORD *)(this + 12) + 1;
    *(_DWORD *)(this + 12) = v14;
    *(_DWORD *)(v15 + 24) = v14;
    CDynList::addElement(*(CDynList **)this, (struct CDynListEntry *)v15);
    *(_DWORD *)(v15 + 32) = a5;
    *(_BYTE *)(v15 + 40) = a6;
    *(_DWORD *)(v15 + 28) = a7;
    return *(_DWORD *)(v15 + 24);
  }
}


// address=[0x2f408f0]
// Decompiled from char __thiscall CReserveDatabase::RemoveBuilding(CDynList **this, int a2, int a3)
bool  CReserveDatabase::RemoveBuilding(int,int) {
  
  struct CDynListEntry *v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  if ( !a3 )
  {
    for ( i = 0; i < CDynList::size(*this); ++i )
    {
      v4 = (struct CDynListEntry *)CDynList::elementAt(*this, i);
      if ( *((_DWORD *)v4 + 6) == a2 )
      {
        CDynList::delElement(*this, v4);
        return 1;
      }
    }
  }
  return 0;
}


// address=[0x2f40960]
// Decompiled from int __thiscall CReserveDatabase::RemoveGrpEntry(CDynList **this, int a2, CDynList **a3)
void  CReserveDatabase::RemoveGrpEntry(int,class CGrpReserveEntry *) {
  
  int result; // eax
  int v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]
  int i; // [esp+8h] [ebp-4h]

  if ( a3 )
  {
    for ( i = 0; ; ++i )
    {
      result = CDynList::size(a3[12]);
      if ( i >= result )
        break;
      v6 = CDynList::elementAt(a3[12], i);
      if ( !a2 || CReserveDatabase::InSameGroup((CReserveDatabase *)this, *(_DWORD *)(v6 + 44), a2) )
      {
        if ( CDynList::size(*(CDynList **)(v6 + 48)) > 0 )
          CReserveDatabase::RemoveGrpEntry((CReserveDatabase *)this, a2, (struct CGrpReserveEntry *)v6);
        CDynList::delElement(a3[12], i--);
      }
    }
  }
  else
  {
    for ( j = 0; ; ++j )
    {
      result = CDynList::size(this[1]);
      if ( j >= result )
        break;
      v5 = CDynList::elementAt(this[1], j);
      if ( !a2 || CReserveDatabase::InSameGroup((CReserveDatabase *)this, *(_DWORD *)(v5 + 44), a2) )
      {
        if ( CDynList::size(*(CDynList **)(v5 + 48)) > 0 )
          CReserveDatabase::RemoveGrpEntry((CReserveDatabase *)this, a2, (struct CGrpReserveEntry *)v5);
        CDynList::delElement(this[1], j--);
      }
    }
  }
  return result;
}


// address=[0x2f40ab0]
// Decompiled from char __thiscall CReserveDatabase::GetResPosition(CReserveDatabase *this, int a2, int *a3, int *a4)
bool  CReserveDatabase::GetResPosition(int,int &,int &) {
  
  struct CGrpReserveEntry *GrpResBuilding; // [esp+4h] [ebp-4h]

  GrpResBuilding = CReserveDatabase::GetGrpResBuilding(this, a2);
  if ( GrpResBuilding )
  {
    *a3 = *((_DWORD *)GrpResBuilding + 4);
    *a4 = *((_DWORD *)GrpResBuilding + 5);
    return 1;
  }
  else
  {
    *a3 = 0;
    *a4 = 0;
    return 0;
  }
}


// address=[0x2f40b10]
// Decompiled from int __thiscall CReserveDatabase::GetReserveBuilding(void *this, int a2, int a3)
int  CReserveDatabase::GetReserveBuilding(int,enum BUILDING_TYPES) {
  
  _DWORD *v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 0;
  if ( (unsigned __int8)CReserveDatabase::GetSubReserveEntry(this, a2, &v4, a3) == 1
    && v4
    && v4[11] == a2
    && (v4[3] == a3 || !a3) )
  {
    return v4[6];
  }
  else
  {
    return 0;
  }
}


// address=[0x2f40b70]
// Decompiled from int __thiscall CReserveDatabase::GetResGrpNr(CReserveDatabase *this, int a2)
int  CReserveDatabase::GetResGrpNr(int) {
  
  struct CGrpReserveEntry *GrpResBuilding; // [esp+4h] [ebp-4h]

  GrpResBuilding = CReserveDatabase::GetGrpResBuilding(this, a2);
  if ( GrpResBuilding )
    return *((_DWORD *)GrpResBuilding + 11);
  else
    return 0;
}


// address=[0x2f40ba0]
// Decompiled from int __thiscall CReserveDatabase::CreateGrpNumber(CReserveDatabase *this, int a2, int a3)
int  CReserveDatabase::CreateGrpNumber(int,int) {
  
  return a3 + 10 * a2;
}


// address=[0x2f40bc0]
// Decompiled from char __thiscall CReserveDatabase::NewSubReserveEntry(CDynList **this, struct CGrpReserveEntry *a2, int a3)
bool  CReserveDatabase::NewSubReserveEntry(class CGrpReserveEntry *,int) {
  
  int v5; // [esp+4h] [ebp-4h] BYREF

  v5 = 0;
  if ( (unsigned __int8)CReserveDatabase::GetSubReserveEntry(this, a3, &v5, 0) == 1 )
    return 0;
  if ( v5 )
    CDynList::addElement(*(CDynList **)(v5 + 48), a2);
  else
    CDynList::addElement(this[1], a2);
  return 1;
}


// address=[0x2f40c20]
// Decompiled from char __thiscall CReserveDatabase::GetSubReserveEntry(CDynList **this, int a2, int *a3, int a4)
bool  CReserveDatabase::GetSubReserveEntry(int,class CGrpReserveEntry * &,enum BUILDING_TYPES) {
  
  int i; // [esp+4h] [ebp-10h]
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v7 = 0;
  for ( i = 0; ; ++i )
  {
    if ( i >= CDynList::size(this[1]) )
    {
      *a3 = 0;
      return 0;
    }
    v9 = CDynList::elementAt(this[1], i);
    if ( *(_DWORD *)(v9 + 44) == a2 && (*(_DWORD *)(v9 + 12) == a4 || !a4) )
    {
      *a3 = v9;
      return 1;
    }
    if ( CReserveDatabase::InSameGroup((CReserveDatabase *)this, *(_DWORD *)(v9 + 44), a2) )
      break;
  }
  *a3 = v9;
  while ( v7 < CDynList::size(*(CDynList **)(v9 + 48)) )
  {
    v8 = CDynList::elementAt(*(CDynList **)(v9 + 48), v7);
    if ( *(_DWORD *)(v8 + 44) == a2 && (*(_DWORD *)(v8 + 12) == a4 || !a4) )
    {
      *a3 = v8;
      return 1;
    }
    if ( CReserveDatabase::InSameGroup((CReserveDatabase *)this, *(_DWORD *)(v8 + 44), a2) )
    {
      *a3 = v8;
      v9 = v8;
      v7 = 0;
    }
    else
    {
      ++v7;
    }
  }
  return 0;
}


// address=[0x2f40d70]
// Decompiled from char __thiscall CReserveDatabase::GetResBuildingInGroup(CDynList **this, int a2, struct CReserveEntry *a3)
bool  CReserveDatabase::GetResBuildingInGroup(int,class CReserveEntry *) {
  
  int i; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h]
  _DWORD *v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]
  char v10; // [esp+1Bh] [ebp-1h]

  v6 = 0;
  v9 = 0;
  v10 = 0;
  while ( *((_DWORD *)a3 + 11 * v9 + 3) )
    ++v9;
  for ( i = 0; i < CDynList::size(this[1]); ++i )
  {
    v8 = CDynList::elementAt(this[1], i);
    if ( CReserveDatabase::InSameGroup((CReserveDatabase *)this, *(_DWORD *)(v8 + 44), a2) )
    {
      *((_DWORD *)a3 + 11 * v9 + 6) = *(_DWORD *)(v8 + 24);
      *((_DWORD *)a3 + 11 * v9 + 4) = *(_DWORD *)(v8 + 16);
      *((_DWORD *)a3 + 11 * v9 + 5) = *(_DWORD *)(v8 + 20);
      *((_DWORD *)a3 + 11 * v9 + 3) = *(_DWORD *)(v8 + 12);
      *((_DWORD *)a3 + 11 * v9++ + 8) = *(_DWORD *)(v8 + 32);
      v10 = 1;
      if ( *(_DWORD *)(v8 + 44) == a2 )
        return 1;
      while ( v6 < CDynList::size(*(CDynList **)(v8 + 48)) )
      {
        v7 = (_DWORD *)CDynList::elementAt(*(CDynList **)(v8 + 48), v6);
        if ( CReserveDatabase::InSameGroup((CReserveDatabase *)this, v7[11], a2) )
        {
          *((_DWORD *)a3 + 11 * v9 + 6) = v7[6];
          *((_DWORD *)a3 + 11 * v9 + 4) = v7[4];
          *((_DWORD *)a3 + 11 * v9 + 5) = v7[5];
          *((_DWORD *)a3 + 11 * v9 + 3) = v7[3];
          *((_DWORD *)a3 + 11 * v9++ + 8) = v7[8];
          v10 = 1;
          if ( v7[11] == a2 )
          {
            v10 = 1;
            ++v6;
          }
          else
          {
            v8 = (int)v7;
            v6 = 0;
          }
        }
        else
        {
          ++v6;
        }
      }
    }
  }
  return v10;
}


// address=[0x2f40f70]
// Decompiled from int __thiscall CReserveDatabase::GetResBuildingType(CReserveDatabase *this, int a2)
enum BUILDING_TYPES  CReserveDatabase::GetResBuildingType(int) {
  
  struct CGrpReserveEntry *GrpResBuilding; // [esp+4h] [ebp-Ch]

  GrpResBuilding = CReserveDatabase::GetGrpResBuilding(this, a2);
  if ( GrpResBuilding )
    return *((_DWORD *)GrpResBuilding + 3);
  else
    return 0;
}


// address=[0x2f40ff0]
// Decompiled from int __thiscall CReserveDatabase::GetGrpResBuilding(CReserveDatabase *this, int a2)
class CGrpReserveEntry *  CReserveDatabase::GetGrpResBuilding(int) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-4h]

  v5 = a2 - *((_DWORD *)this + 4);
  if ( CDynList::size(*((CDynList **)this + 2)) <= v5 && CDynList::size(*((CDynList **)this + 2)) > 0 )
    v5 = CDynList::size(*((CDynList **)this + 2)) - 1;
  v3 = CDynList::elementAt(*((CDynList **)this + 2), v5);
  if ( !v3 )
    return 0;
  while ( *(_DWORD *)(v3 + 12) != a2 && v5 > 0 )
    v3 = CDynList::elementAt(*((CDynList **)this + 2), --v5);
  if ( *(_DWORD *)(v3 + 12) == a2 )
    return *(_DWORD *)(v3 + 16);
  else
    return 0;
}


// address=[0x2f410a0]
// Decompiled from struct CGrpReserveEntry *__thiscall CReserveDatabase::GetGrpResBuilding(  CDynList **this,  int a2,  struct CGrpReserveEntry *a3)
class CGrpReserveEntry *  CReserveDatabase::GetGrpResBuilding(int,class CGrpReserveEntry *) {
  
  struct CGrpReserveEntry *v4; // [esp+0h] [ebp-10h]
  struct CGrpReserveEntry *v5; // [esp+0h] [ebp-10h]
  struct CGrpReserveEntry *v7; // [esp+8h] [ebp-8h]
  struct CGrpReserveEntry *GrpResBuilding; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]
  int i; // [esp+Ch] [ebp-4h]

  if ( a3 && *((_DWORD *)a3 + 6) == a2 )
    return a3;
  if ( a3 )
  {
    for ( i = 0; i < CDynList::size(*((CDynList **)a3 + 12)); ++i )
    {
      v5 = (struct CGrpReserveEntry *)CDynList::elementAt(*((CDynList **)a3 + 12), i);
      GrpResBuilding = CReserveDatabase::GetGrpResBuilding((CReserveDatabase *)this, a2, v5);
      if ( GrpResBuilding )
        return GrpResBuilding;
    }
  }
  else
  {
    for ( j = 0; j < CDynList::size(this[1]); ++j )
    {
      v4 = (struct CGrpReserveEntry *)CDynList::elementAt(this[1], j);
      v7 = CReserveDatabase::GetGrpResBuilding((CReserveDatabase *)this, a2, v4);
      if ( v7 )
        return v7;
    }
  }
  return 0;
}


// address=[0x2f41190]
// Decompiled from char __thiscall CReserveDatabase::IsBuildingPlaceAvailable(CReserveDatabase *this, int a2, int a3, int a4, int a5)
bool  CReserveDatabase::IsBuildingPlaceAvailable(class IAIEcoManager *,enum BUILDING_TYPES,int,class CReserveEntry *) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; *(_DWORD *)(a5 + 44 * i + 12); ++i )
  {
    if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)a2 + 40))(
           a2,
           *(_DWORD *)(a5 + 44 * i + 12),
           *(_DWORD *)(a5 + 44 * i + 32),
           a3,
           a4) )
    {
      return 0;
    }
    if ( *(_DWORD *)(a5 + 44 * i + 36) && CReserveDatabase::InSameGrid8(this, a4, *(_DWORD *)(a5 + 44 * i + 36)) )
      return 0;
  }
  return 1;
}


// address=[0x2f41240]
// Decompiled from char __thiscall CReserveDatabase::IsBuildingTypeInGrp(CReserveDatabase *this, int a2, int a3)
bool  CReserveDatabase::IsBuildingTypeInGrp(enum BUILDING_TYPES,int) {
  
  int i; // [esp+Ch] [ebp-11Ch]
  int j; // [esp+Ch] [ebp-11Ch]
  _DWORD v7[66]; // [esp+10h] [ebp-118h] BYREF
  int v8; // [esp+124h] [ebp-4h]

  _vec_ctor(v7, 0x2Cu, 6u, CReserveEntry::CReserveEntry, CReserveEntry::~CReserveEntry);
  v8 = 0;
  for ( i = 0; i < 6; ++i )
    memset(&v7[11 * i], 0, 0x2Cu);
  if ( CReserveDatabase::GetResBuildingInGroup(this, a3, (struct CReserveEntry *)v7) )
  {
    for ( j = 0; v7[11 * j + 3]; ++j )
    {
      if ( v7[11 * j + 3] == a2 )
      {
        v8 = -1;
        `eh vector destructor iterator'(v7, 0x2Cu, 6u, CReserveEntry::~CReserveEntry);
        return 1;
      }
    }
  }
  v8 = -1;
  `eh vector destructor iterator'(v7, 0x2Cu, 6u, CReserveEntry::~CReserveEntry);
  return 0;
}


// address=[0x2f413b0]
// Decompiled from bool __thiscall CReserveDatabase::InSameGroup(CReserveDatabase *this, int a2, int a3)
bool  CReserveDatabase::InSameGroup(int,int) {
  
  int v4; // [esp+4h] [ebp-4h]
  int v5; // [esp+4h] [ebp-4h]

  if ( a2 < a3 )
  {
    v4 = a3;
    while ( v4 / 10 )
    {
      v4 /= 10;
      if ( v4 == a2 )
        return 1;
    }
  }
  if ( a2 <= a3 )
    return a2 == a3;
  v5 = a2;
  while ( v5 / 10 )
  {
    v5 /= 10;
    if ( v5 == a3 )
      return 1;
  }
  return a2 == a3;
}


// address=[0x2f41440]
// Decompiled from char __thiscall CReserveDatabase::UnLockReserveDatabase(CReserveDatabase *this, int a2)
bool  CReserveDatabase::UnLockReserveDatabase(int) {
  
  if ( *((_DWORD *)this + 5) != a2 )
    return 0;
  *((_DWORD *)this + 5) = 0;
  CReserveDatabase::RemoveGrpEntry(this, 0, 0);
  CDynList::ClearDynList(*((CDynList **)this + 2));
  *((_DWORD *)this + 4) = 1;
  *((_DWORD *)this + 3) = 0;
  return 1;
}


// address=[0x2f414a0]
// Decompiled from int __thiscall CReserveDatabase::GetLockedSchedNr(CReserveDatabase *this)
int  CReserveDatabase::GetLockedSchedNr(void) {
  
  return *((_DWORD *)this + 5);
}


// address=[0x2f414c0]
// Decompiled from char __thiscall CReserveDatabase::LockReserveDatabase(CReserveDatabase *this, int a2)
bool  CReserveDatabase::LockReserveDatabase(int) {
  
  if ( *((_DWORD *)this + 5) )
    return 0;
  if ( *((_DWORD *)this + 6) && *((_DWORD *)this + 6) != a2 )
    return 0;
  *((_DWORD *)this + 5) = a2;
  *((_DWORD *)this + 6) = 0;
  return 1;
}


// address=[0x2f41510]
// Decompiled from char __thiscall CReserveDatabase::ReserveLock(_DWORD *this, int a2)
bool  CReserveDatabase::ReserveLock(int) {
  
  if ( this[6] )
    return 0;
  this[6] = a2;
  return 1;
}


// address=[0x2f41540]
// Decompiled from void *__thiscall CReserveDatabase::UpdateReservedBuildingPlaces(std::_Ref_count_base *this, const struct type_info *a2)
int  CReserveDatabase::UpdateReservedBuildingPlaces(enum BUILDING_TYPES) {
  
  return 0;
}


// address=[0x2f41550]
// Decompiled from struct CGrpReserveEntry *__thiscall CReserveDatabase::SetScoringData(CReserveDatabase *this, int a2, int a3)
void  CReserveDatabase::SetScoringData(int,int) {
  
  struct CGrpReserveEntry *result; // eax

  result = CReserveDatabase::GetGrpResBuilding(this, a2);
  if ( result )
    *((_DWORD *)result + 7) = a3;
  return result;
}


// address=[0x2f41580]
// Decompiled from int __thiscall CReserveDatabase::GetScoringData(CReserveDatabase *this, int a2)
int  CReserveDatabase::GetScoringData(int) {
  
  struct CGrpReserveEntry *GrpResBuilding; // [esp+4h] [ebp-4h]

  GrpResBuilding = CReserveDatabase::GetGrpResBuilding(this, a2);
  if ( GrpResBuilding )
    return *((_DWORD *)GrpResBuilding + 7);
  else
    return 0;
}


// address=[0x2f415b0]
// Decompiled from int __thiscall CReserveDatabase::GetPackWorldPosition(CReserveDatabase *this, int a2)
int  CReserveDatabase::GetPackWorldPosition(int) {
  
  struct CGrpReserveEntry *GrpResBuilding; // [esp+4h] [ebp-4h]

  GrpResBuilding = CReserveDatabase::GetGrpResBuilding(this, a2);
  if ( GrpResBuilding )
    return *((_DWORD *)GrpResBuilding + 8);
  else
    return 0;
}


// address=[0x2f415e0]
// Decompiled from int __thiscall CReserveDatabase::GetPackWorldPosition_0(CReserveDatabase *this, int a2, int *a3, int *a4)
int  CReserveDatabase::GetPackWorldPosition(int,int &,int &) {
  
  struct CGrpReserveEntry *GrpResBuilding; // [esp+4h] [ebp-4h]

  GrpResBuilding = CReserveDatabase::GetGrpResBuilding(this, a2);
  if ( !GrpResBuilding )
    return 0;
  CReserveDatabase::UnpackPosition(this, *((_DWORD *)GrpResBuilding + 8), a3, a4);
  return *((_DWORD *)GrpResBuilding + 8);
}


// address=[0x2f41630]
// Decompiled from bool __thiscall CReserveDatabase::InSameGrid8(CReserveDatabase *this, int a2, int a3)
bool  CReserveDatabase::InSameGrid8(int,int) {
  
  int v4; // [esp+0h] [ebp-14h] BYREF
  int v5; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+8h] [ebp-Ch] BYREF
  int v7; // [esp+Ch] [ebp-8h] BYREF
  CReserveDatabase *v8; // [esp+10h] [ebp-4h]

  v8 = this;
  CReserveDatabase::UnpackPosition(this, a2, &v7, &v5);
  CReserveDatabase::UnpackPosition(v8, a3, &v6, &v4);
  return v7 / 8 == v6 / 8 && v5 / 8 == v4 / 8;
}


