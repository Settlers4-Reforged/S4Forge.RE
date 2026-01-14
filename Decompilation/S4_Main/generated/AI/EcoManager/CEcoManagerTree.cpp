#include "all_headers.h"

// Definitions for class CEcoManagerTree

// address=[0x134bcd0]
// Decompiled from CEcoManagerTree *__thiscall CEcoManagerTree::CEcoManagerTree(CEcoManagerTree *this)
 CEcoManagerTree::CEcoManagerTree(void) {
  
  CEcoManagerTree::CEMTD::CEMTD(this);
  memset(this, 0, 0x10u);
  return this;
}


// address=[0x134bd00]
// Decompiled from void __thiscall CEcoManagerTree::~CEcoManagerTree(CEcoManagerTree *this)
 CEcoManagerTree::~CEcoManagerTree(void) {
  
  int i; // eax
  CEcoManagerLeaf *BaseLeaf; // [esp+Ch] [ebp-18h]
  int v4; // [esp+14h] [ebp-10h]

  v4 = 0;
  for ( i = CEcoManagerTree::GetNrBaseLeaves(this); v4 < i; i = CEcoManagerTree::GetNrBaseLeaves(this) )
  {
    BaseLeaf = CEcoManagerTree::GetBaseLeaf(this, v4);
    if ( BaseLeaf )
      CEcoManagerLeaf::`scalar deleting destructor'(BaseLeaf, 1u);
    ++v4;
  }
  std::vector<CEcoManagerLeaf *>::clear();
  CEcoManagerTree::CEMTD::~CEMTD(this);
}


// address=[0x134bda0]
// Decompiled from char __thiscall CEcoManagerTree::CreateBaseLeaf(CEcoManagerTree *this, int a2, int a3, int a4, int a5)
unsigned char  CEcoManagerTree::CreateBaseLeaf(enum BUILDING_TYPES,int,int,class std::vector<struct SPOSS_BUILD_PLACE,class std::allocator<struct SPOSS_BUILD_PLACE> > *) {
  
  int NrBaseLeaves; // eax
  int v7; // [esp+8h] [ebp-34h] BYREF
  int v8; // [esp+Ch] [ebp-30h] BYREF
  CEcoManagerLeaf::CEMLD *v9; // [esp+10h] [ebp-2Ch]
  void *C; // [esp+14h] [ebp-28h]
  int v11; // [esp+18h] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-20h]
  int v13; // [esp+20h] [ebp-1Ch]
  CEcoManagerTree *v14; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  _DWORD *BaseLeaf; // [esp+2Ch] [ebp-10h] BYREF
  int v17; // [esp+38h] [ebp-4h]

  v14 = this;
  BaseLeaf = 0;
  v11 = a3 >> 2;
  v12 = a4 >> 2;
  v13 = -1;
  for ( i = 0; ; ++i )
  {
    NrBaseLeaves = CEcoManagerTree::GetNrBaseLeaves(v14);
    if ( i >= NrBaseLeaves )
      break;
    BaseLeaf = CEcoManagerTree::GetBaseLeaf(v14, i);
    if ( BaseLeaf )
    {
      CEcoManagerLeaf::GetPosition((CEcoManagerLeaf *)BaseLeaf, &v8, &v7);
      if ( v8 == v11 && v7 == v12 )
      {
        v13 = i;
        break;
      }
    }
  }
  if ( v13 == -1 )
  {
    C = operator new(0x68u);
    v17 = 0;
    if ( C )
      v9 = CEcoManagerLeaf::CEcoManagerLeaf((CEcoManagerLeaf::CEMLD *)C, 64, a2, v11, v12);
    else
      v9 = 0;
    v17 = -1;
    BaseLeaf = v9;
    std::vector<CEcoManagerLeaf *>::push_back(&BaseLeaf);
    v13 = std::vector<CEcoManagerLeaf *>::size(v14) - 1;
  }
  CEcoManagerLeaf::AddPosition(BaseLeaf, a3, a4, a5);
  return v13;
}


// address=[0x134bee0]
// Decompiled from char __thiscall CEcoManagerTree::RemoveLeaf(CEcoManagerTree *this, int a2)
bool  CEcoManagerTree::RemoveLeaf(int) {
  
  int NrBaseLeaves; // eax
  _DWORD *v4; // esi
  CEcoManagerLeaf *BaseLeaf; // [esp+10h] [ebp-8h]

  BaseLeaf = CEcoManagerTree::GetBaseLeaf(this, a2);
  if ( !BaseLeaf )
    return 0;
  CEcoManagerLeaf::`scalar deleting destructor'(BaseLeaf, 1u);
  NrBaseLeaves = CEcoManagerTree::GetNrBaseLeaves(this);
  v4 = (_DWORD *)std::vector<CEcoManagerLeaf *>::operator[](NrBaseLeaves - 1);
  *(_DWORD *)std::vector<CEcoManagerLeaf *>::operator[](a2) = *v4;
  std::vector<CEcoManagerLeaf *>::pop_back(this);
  return 1;
}


// address=[0x134bf70]
// Decompiled from char __thiscall CEcoManagerTree::RemoveLeaf(CEcoManagerTree *this, struct SBUILDINFODATA *a2)
bool  CEcoManagerTree::RemoveLeaf(struct SBUILDINFODATA *) {
  
  struct CEcoManagerLeaf *BaseLeaf; // eax
  struct CEcoManagerLeaf *Leaf; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  Leaf = (struct CEcoManagerLeaf *)CEcoManagerTree::FindLeaf(
                                     this,
                                     *((_DWORD *)a2 + 3),
                                     *(_DWORD *)a2,
                                     *((_DWORD *)a2 + 1));
  for ( i = 0; i < CEcoManagerTree::GetNrBaseLeaves(this); ++i )
  {
    if ( CEcoManagerTree::GetBaseLeaf(this, i) == Leaf )
      return CEcoManagerTree::RemoveLeaf(this, i);
    BaseLeaf = CEcoManagerTree::GetBaseLeaf(this, i);
    if ( CEcoManagerTree::RemoveLeafRecursive(this, BaseLeaf, Leaf) )
      return 1;
  }
  return 0;
}


// address=[0x134c010]
// Decompiled from int __thiscall CEcoManagerTree::GetNrBaseLeaves(CEcoManagerTree *this)
int  CEcoManagerTree::GetNrBaseLeaves(void) {
  
  return std::vector<CEcoManagerLeaf *>::size(this);
}


// address=[0x134c030]
// Decompiled from int __thiscall CEcoManagerTree::GetBaseLeaf(CEcoManagerTree *this, int a2)
class CEcoManagerLeaf *  CEcoManagerTree::GetBaseLeaf(int) {
  
  if ( a2 < CEcoManagerTree::GetNrBaseLeaves(this) && a2 >= 0 )
    return *(_DWORD *)std::vector<CEcoManagerLeaf *>::operator[](a2);
  else
    return 0;
}


// address=[0x134c070]
// Decompiled from char __thiscall CEcoManagerTree::UpdateBaseLeaf(CEcoManagerTree *this, int a2)
bool  CEcoManagerTree::UpdateBaseLeaf(int) {
  
  struct CEcoManagerLeaf *BaseLeaf; // [esp+4h] [ebp-4h]

  BaseLeaf = CEcoManagerTree::GetBaseLeaf(this, a2);
  if ( BaseLeaf )
    return CEcoManagerLeaf::Update(BaseLeaf);
  else
    return 0;
}


// address=[0x134c0a0]
// Decompiled from int __thiscall CEcoManagerTree::GetNrValidOfAllBaseLeafes(CEcoManagerTree *this, int a2)
int  CEcoManagerTree::GetNrValidOfAllBaseLeafes(enum IECONOMANAGERGRIDRESOLUTION) {
  
  CEcoManagerLeaf *BaseLeaf; // eax
  CEcoManagerLeaf *v3; // eax
  int j; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  int NrBaseLeaves; // [esp+Ch] [ebp-4h]

  NrBaseLeaves = 0;
  if ( a2 == 64 )
    NrBaseLeaves = CEcoManagerTree::GetNrBaseLeaves(this);
  if ( a2 == 32 )
  {
    for ( i = 0; i < CEcoManagerTree::GetNrBaseLeaves(this); ++i )
    {
      BaseLeaf = CEcoManagerTree::GetBaseLeaf(this, i);
      NrBaseLeaves += CEcoManagerLeaf::GetNrValidChilds(BaseLeaf);
    }
  }
  if ( a2 == 16 )
  {
    for ( j = 0; j < CEcoManagerTree::GetNrBaseLeaves(this); ++j )
    {
      v3 = CEcoManagerTree::GetBaseLeaf(this, j);
      NrBaseLeaves += CEcoManagerLeaf::GetNrValidOfAllSubChilds(v3);
    }
  }
  return NrBaseLeaves;
}


// address=[0x134c150]
// Decompiled from struct CEcoManagerLeaf *__thiscall CEcoManagerTree::FindLeaf(CEcoManagerTree *this, int a2, int a3, int a4)
class CEcoManagerLeaf *  CEcoManagerTree::FindLeaf(enum IECONOMANAGERGRIDRESOLUTION,int,int) {
  
  int Child; // [esp+4h] [ebp-10h]
  int v6; // [esp+4h] [ebp-10h]
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-Ch]
  int v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+Ch] [ebp-8h]
  CEcoManagerLeaf *BaseLeaf; // [esp+10h] [ebp-4h]
  CEcoManagerLeaf *v12; // [esp+10h] [ebp-4h]

  v7 = a3;
  v9 = a4;
  if ( a2 < 64 )
  {
    v7 = a3 >> 1;
    v9 = a4 >> 1;
  }
  if ( a2 == 16 )
  {
    v7 >>= 1;
    v9 >>= 1;
  }
  BaseLeaf = CEcoManagerTree::GetBaseLeaf(this, v7, v9);
  if ( a2 == 64 || !BaseLeaf )
    return BaseLeaf;
  v8 = a3;
  v10 = a4;
  if ( a2 == 16 )
  {
    v8 = a3 >> 1;
    v10 = a4 >> 1;
  }
  Child = CEcoManagerLeaf::GetChild(BaseLeaf, v8, v10);
  if ( Child == -1 )
    return 0;
  v12 = CEcoManagerLeaf::GetChild(BaseLeaf, Child);
  if ( a2 == 32 || !v12 )
    return v12;
  v6 = CEcoManagerLeaf::GetChild(v12, a3, a4);
  if ( v6 == -1 )
    return 0;
  else
    return CEcoManagerLeaf::GetChild(v12, v6);
}


// address=[0x134c250]
// Decompiled from int __thiscall CEcoManagerTree::FindNearLeaf(void *this, int a2, int a3, int a4, int a5)
class CEcoManagerLeaf *  CEcoManagerTree::FindNearLeaf(enum IECONOMANAGERGRIDRESOLUTION,int,int,int) {
  
  int i; // [esp+4h] [ebp-Ch]
  int j; // [esp+8h] [ebp-8h]
  int Leaf; // [esp+Ch] [ebp-4h]
  int v10; // [esp+Ch] [ebp-4h]

  Leaf = CEcoManagerTree::FindLeaf(this, a2, a3, a4);
  if ( Leaf )
    return Leaf;
  for ( i = a3 - a5; i < a5 + a3; ++i )
  {
    for ( j = a4 - a5; j < a5 + a4; ++j )
    {
      v10 = CEcoManagerTree::FindLeaf(this, a2, i, j);
      if ( v10 )
        return v10;
    }
  }
  return 0;
}


// address=[0x134c2f0]
// Decompiled from struct CEcoManagerLeaf *__thiscall CEcoManagerTree::GetBaseLeaf(CEcoManagerTree *this, int a2, int a3)
class CEcoManagerLeaf *  CEcoManagerTree::GetBaseLeaf(int,int) {
  
  int NrBaseLeaves; // eax
  CEcoManagerLeaf *BaseLeaf; // eax
  int v6; // [esp+0h] [ebp-10h] BYREF
  int v7; // [esp+4h] [ebp-Ch] BYREF
  CEcoManagerTree *v8; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v8 = this;
  for ( i = 0; ; ++i )
  {
    NrBaseLeaves = CEcoManagerTree::GetNrBaseLeaves(v8);
    if ( i >= NrBaseLeaves )
      break;
    BaseLeaf = CEcoManagerTree::GetBaseLeaf(v8, i);
    CEcoManagerLeaf::GetPosition(BaseLeaf, &v7, &v6);
    if ( v7 == a2 && v6 == a3 )
      return CEcoManagerTree::GetBaseLeaf(v8, i);
  }
  return 0;
}


// address=[0x134c360]
// Decompiled from char __thiscall CEcoManagerTree::RemoveLeafRecursive(  CEcoManagerTree *this,  struct CEcoManagerLeaf *a2,  struct CEcoManagerLeaf *a3)
bool  CEcoManagerTree::RemoveLeafRecursive(class CEcoManagerLeaf *,class CEcoManagerLeaf *) {
  
  struct CEcoManagerLeaf *Child; // eax
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  for ( i = 0; i < CEcoManagerLeaf::GetNrChilds(a2); ++i )
  {
    if ( CEcoManagerLeaf::GetChild(a2, i) && CEcoManagerLeaf::GetChild(a2, i) == a3 )
    {
      CEcoManagerLeaf::RemoveChild(a2, i);
      return 1;
    }
  }
  for ( j = 0; j < CEcoManagerLeaf::GetNrChilds(a2); ++j )
  {
    if ( CEcoManagerLeaf::GetChild(a2, j) )
    {
      Child = CEcoManagerLeaf::GetChild(a2, j);
      if ( CEcoManagerTree::RemoveLeafRecursive(this, Child, a3) )
        return 1;
    }
  }
  return 0;
}


