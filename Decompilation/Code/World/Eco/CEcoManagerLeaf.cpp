#include "CEcoManagerLeaf.h"

// Definitions for class CEcoManagerLeaf

// address=[0x134b270]
// Decompiled from CEcoManagerLeaf::CEMLD *__thiscall CEcoManagerLeaf::CEcoManagerLeaf(  CEcoManagerLeaf::CEMLD *this,  int a2,  int a3,  int a4,  int a5)
 CEcoManagerLeaf::CEcoManagerLeaf(enum IECONOMANAGERGRIDRESOLUTION,enum BUILDING_TYPES,int,int) {
  
  CEcoManagerLeaf::CEMLD::CEMLD(this);
  j__memset(this, 0, 0x68u);
  *((_DWORD *)this + 3) = a2;
  *(_DWORD *)this = a4;
  *((_DWORD *)this + 1) = a5;
  *((_DWORD *)this + 2) = a3;
  return this;
}


// address=[0x134b2c0]
// Decompiled from void __thiscall CEcoManagerLeaf::~CEcoManagerLeaf(CEcoManagerLeaf *this)
 CEcoManagerLeaf::~CEcoManagerLeaf(void) {
  
  int i; // eax
  int v3; // [esp+8h] [ebp-10h]

  v3 = 0;
  for ( i = CEcoManagerLeaf::GetNrChilds(this); v3 < i; i = CEcoManagerLeaf::GetNrChilds(this) )
  {
    if ( CEcoManagerLeaf::GetChild(this, v3) )
      CEcoManagerLeaf::RemoveChild(this, v3);
    ++v3;
  }
  CEcoManagerLeaf::CEMLD::~CEMLD(this);
}


// address=[0x134b340]
// Decompiled from int *__thiscall CEcoManagerLeaf::GetPosition(CEcoManagerLeaf *this, int *a2, int *a3)
void  CEcoManagerLeaf::GetPosition(int &,int &) {
  
  int *result; // eax

  *a2 = *(_DWORD *)this;
  result = a3;
  *a3 = *((_DWORD *)this + 1);
  return result;
}


// address=[0x134b370]
// Decompiled from struct Concurrency::details::stl_condition_variable_win7 *__thiscall CEcoManagerLeaf::GetBuildInfo(  _Cnd_internal_imp_t *this)
struct SBUILDINFODATA const *  CEcoManagerLeaf::GetBuildInfo(void) {
  
  return this;
}


// address=[0x134b380]
// Decompiled from char __thiscall CEcoManagerLeaf::Update(CEcoManagerLeaf *this)
bool  CEcoManagerLeaf::Update(void) {
  
  int i; // eax
  struct CEcoManagerLeaf *Child; // [esp+8h] [ebp-4Ch]
  CEcoManagerLeaf *v4; // [esp+Ch] [ebp-48h]
  int v5; // [esp+10h] [ebp-44h]
  int m; // [esp+14h] [ebp-40h]
  int ii; // [esp+18h] [ebp-3Ch]
  int v9; // [esp+20h] [ebp-34h]
  int j; // [esp+20h] [ebp-34h]
  int k; // [esp+20h] [ebp-34h]
  int n; // [esp+20h] [ebp-34h]
  _BYTE v13[44]; // [esp+24h] [ebp-30h] BYREF

  v9 = 0;
  for ( i = CEcoManagerLeaf::GetNrChilds(this); v9 < i; i = CEcoManagerLeaf::GetNrChilds(this) )
  {
    Child = CEcoManagerLeaf::GetChild(this, v9);
    if ( Child )
      CEcoManagerLeaf::Update(Child);
    ++v9;
  }
  *((_DWORD *)this + 23) = 0;
  v5 = *((_DWORD *)this + 3);
  if ( v5 == 16 )
  {
    qmemcpy(v13, CAIResourceMap::ResourceDataVW(*(_DWORD *)this, *((_DWORD *)this + 1)), 0x2Au);
    for ( j = 0; j < 8; ++j )
      *((_WORD *)this + j + 22) = CAIResourceData::ResourceAmount1((CAIResourceData *)v13, j);
    for ( k = 0; k < 7; ++k )
      *((_DWORD *)this + k + 4) = CAIResourceData::GroundInfo1((CAIResourceData *)v13, k);
  }
  else if ( v5 == 32 || v5 == 64 )
  {
    for ( m = 0; m < 8; ++m )
      *((_WORD *)this + m + 22) = 0;
    if ( *((_DWORD *)this + 3) == 32 )
      *((_DWORD *)this + 23) = CEcoManagerLeaf::GetNrValidChilds(this);
    for ( n = 0; n < CEcoManagerLeaf::GetNrChilds(this); ++n )
    {
      v4 = CEcoManagerLeaf::GetChild(this, n);
      if ( v4 )
      {
        for ( ii = 0; ii < 8; ++ii )
          *((_WORD *)this + ii + 22) += CEcoManagerLeaf::GetResourceAmount(v4, ii);
        if ( *((_DWORD *)this + 3) == 64 )
          *((_DWORD *)this + 23) += CEcoManagerLeaf::GetNrValidOfAllSubChilds(v4);
      }
    }
  }
  return 1;
}


// address=[0x134b580]
// Decompiled from int __thiscall CEcoManagerLeaf::GetResourceAmount(CEcoManagerLeaf *this, int a2)
int  CEcoManagerLeaf::GetResourceAmount(int) {
  
  return *((unsigned __int16 *)this + (a2 >> 4) + 22);
}


// address=[0x134b5a0]
// Decompiled from int __thiscall CEcoManagerLeaf::GetUndergroundAmount(_DWORD *this, int a2)
int  CEcoManagerLeaf::GetUndergroundAmount(int) {
  
  return this[a2 + 4];
}


// address=[0x134b5c0]
// Decompiled from char __thiscall CEcoManagerLeaf::AddPosition(CEcoManagerLeaf *this, int a2, int a3, int a4)
bool  CEcoManagerLeaf::AddPosition(int,int,class std::vector<struct SPOSS_BUILD_PLACE,class std::allocator<struct SPOSS_BUILD_PLACE> > *) {
  
  int v4; // eax
  int Child; // eax
  struct CEcoManagerLeaf *v7; // eax
  struct CEcoManagerLeaf *v8; // eax
  CEcoManagerLeaf::CEMLD *v9; // [esp+8h] [ebp-40h]
  CEcoManagerLeaf::CEMLD *C; // [esp+Ch] [ebp-3Ch]
  int v11; // [esp+14h] [ebp-34h]
  int v12; // [esp+18h] [ebp-30h]
  int v13; // [esp+1Ch] [ebp-2Ch]
  int v14; // [esp+20h] [ebp-28h]
  int FreeChildPos; // [esp+24h] [ebp-24h]
  int v16; // [esp+28h] [ebp-20h]
  int v17; // [esp+2Ch] [ebp-1Ch]
  unsigned int i; // [esp+30h] [ebp-18h]
  char v20; // [esp+3Bh] [ebp-Dh]

  if ( *((_DWORD *)this + 3) == 16 )
  {
    if ( (unsigned int)std::vector<SPOSS_BUILD_PLACE>::size() > 0x100
      && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManagerLeaf.cpp", 194, "_pvasPossibleBuildPlaces->size() <= 256") == 1 )
    {
      __debugbreak();
    }
    for ( i = 0; i < std::vector<SPOSS_BUILD_PLACE>::size(); ++i )
    {
      v4 = std::vector<SPOSS_BUILD_PLACE>::at(i);
      std::vector<SPOSS_BUILD_PLACE>::push_back(v4);
    }
    if ( (unsigned int)std::vector<SPOSS_BUILD_PLACE>::size() > 0x100
      && BBSupportDbgReport(
           2,
           "AI\\EcoManager\\CEcoManagerLeaf.cpp",
           198,
           "m_Vars.sBuildInfoData.vasPossibleBuildPositions.size() <= 256") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
  else
  {
    v14 = *((_DWORD *)this + 3);
    if ( v14 == 32 )
    {
      v13 = a2 >> 1;
      v12 = a3 >> 1;
    }
    else if ( v14 == 64 )
    {
      v13 = a2 >> 2;
      v12 = a3 >> 2;
    }
    if ( v13 == *(_DWORD *)this || v12 == *((_DWORD *)this + 1) )
    {
      v11 = *((_DWORD *)this + 3);
      if ( v11 == 32 )
      {
        v16 = a2;
        v17 = a3;
        Child = CEcoManagerLeaf::GetChild(this, a2, a3);
      }
      else
      {
        if ( v11 == 64 )
        {
          v16 = a2 >> 1;
          v17 = a3 >> 1;
        }
        Child = CEcoManagerLeaf::GetChild(this, v16, v17);
      }
      if ( Child == -1 )
      {
        FreeChildPos = CEcoManagerLeaf::GetFreeChildPos(this);
        if ( FreeChildPos == -1 )
        {
          return 0;
        }
        else
        {
          C = (CEcoManagerLeaf::CEMLD *)operator new(0x68u);
          if ( C )
            v9 = CEcoManagerLeaf::CEcoManagerLeaf(C, *((int *)this + 3) >> 1, *((_DWORD *)this + 2), v16, v17);
          else
            v9 = 0;
          *((_DWORD *)this + FreeChildPos + 19) = v9;
          v8 = CEcoManagerLeaf::GetChild(this, FreeChildPos);
          CEcoManagerLeaf::AddPosition(v8, a2, a3, a4);
          CEcoManagerLeaf::Update(this);
          return 1;
        }
      }
      else
      {
        v7 = CEcoManagerLeaf::GetChild(this, Child);
        v20 = CEcoManagerLeaf::AddPosition(v7, a2, a3, a4);
        CEcoManagerLeaf::Update(this);
        return v20;
      }
    }
    else
    {
      return 0;
    }
  }
}


// address=[0x134b820]
// Decompiled from int __thiscall CEcoManagerLeaf::GetNrChilds(CEcoManagerLeaf *this)
int  CEcoManagerLeaf::GetNrChilds(void) {
  
  return 4;
}


// address=[0x134b830]
// Decompiled from int __thiscall CEcoManagerLeaf::GetNrValidChilds(CEcoManagerLeaf *this)
int  CEcoManagerLeaf::GetNrValidChilds(void) {
  
  int i; // eax
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v4 = 0;
  v5 = 0;
  for ( i = CEcoManagerLeaf::GetNrChilds(this); v5 < i; i = CEcoManagerLeaf::GetNrChilds(this) )
  {
    if ( CEcoManagerLeaf::GetChild(this, v5) )
      ++v4;
    ++v5;
  }
  return v4;
}


// address=[0x134b890]
// Decompiled from int __thiscall CEcoManagerLeaf::GetNrValidOfAllSubChilds(CEcoManagerLeaf *this)
int  CEcoManagerLeaf::GetNrValidOfAllSubChilds(void) {
  
  return *((_DWORD *)this + 23);
}


// address=[0x134b8b0]
// Decompiled from int __thiscall CEcoManagerLeaf::GetChild(CEcoManagerLeaf *this, int a2)
class CEcoManagerLeaf *  CEcoManagerLeaf::GetChild(int) {
  
  if ( a2 < CEcoManagerLeaf::GetNrChilds(this) && a2 >= 0 )
    return *((_DWORD *)this + a2 + 19);
  else
    return 0;
}


// address=[0x134b8e0]
// Decompiled from int __thiscall CEcoManagerLeaf::GetChild(CEcoManagerLeaf *this, int a2, int a3)
int  CEcoManagerLeaf::GetChild(int,int) {
  
  int NrChilds; // eax
  int v5; // [esp+0h] [ebp-14h] BYREF
  int v6; // [esp+4h] [ebp-10h] BYREF
  CEcoManagerLeaf *Child; // [esp+8h] [ebp-Ch]
  CEcoManagerLeaf *v8; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v8 = this;
  for ( i = 0; ; ++i )
  {
    NrChilds = CEcoManagerLeaf::GetNrChilds(v8);
    if ( i >= NrChilds )
      break;
    Child = CEcoManagerLeaf::GetChild(v8, i);
    if ( Child )
    {
      CEcoManagerLeaf::GetPosition(Child, &v6, &v5);
      if ( v6 == a2 && v5 == a3 )
        return i;
    }
  }
  return -1;
}


// address=[0x134b950]
// Decompiled from char __thiscall CEcoManagerLeaf::RemoveChild(CEcoManagerLeaf *this, int a2)
bool  CEcoManagerLeaf::RemoveChild(int) {
  
  if ( !CEcoManagerLeaf::GetChild(this, a2) )
    return 0;
  if ( *((_DWORD *)this + a2 + 19) )
    CEcoManagerLeaf::`scalar deleting destructor'(*((CEcoManagerLeaf **)this + a2 + 19), 1u);
  *((_DWORD *)this + a2 + 19) = 0;
  return 1;
}


// address=[0x134b9c0]
// Decompiled from int __thiscall CEcoManagerLeaf::GetFreeChildPos(CEcoManagerLeaf *this)
int  CEcoManagerLeaf::GetFreeChildPos(void) {
  
  int i; // eax
  int v4; // [esp+4h] [ebp-4h]

  v4 = 0;
  for ( i = CEcoManagerLeaf::GetNrChilds(this); v4 < i; i = CEcoManagerLeaf::GetNrChilds(this) )
  {
    if ( !CEcoManagerLeaf::GetChild(this, v4) )
      return v4;
    ++v4;
  }
  return -1;
}


