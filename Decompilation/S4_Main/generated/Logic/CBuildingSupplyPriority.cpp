#include "all_headers.h"

// Definitions for class CBuildingSupplyPriority

// address=[0x13fff00]
// Decompiled from int __cdecl CBuildingSupplyPriority::New(int a1)
static class CPersistence * __cdecl CBuildingSupplyPriority::New(std::istream &) {
  
  if ( operator new(0x10u) )
    return CBuildingSupplyPriority::CBuildingSupplyPriority(a1);
  else
    return 0;
}


// address=[0x140aae0]
// Decompiled from _DWORD *__thiscall CBuildingSupplyPriority::CBuildingSupplyPriority(_DWORD *this, int a2)
 CBuildingSupplyPriority::CBuildingSupplyPriority(std::istream &) {
  
  _DWORD *v2; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v5[4]; // [esp+10h] [ebp-3Ch] BYREF
  int v6; // [esp+14h] [ebp-38h]
  int v7; // [esp+18h] [ebp-34h] BYREF
  int pExceptionObject; // [esp+1Ch] [ebp-30h] BYREF
  int v9; // [esp+20h] [ebp-2Ch] BYREF
  int v10; // [esp+24h] [ebp-28h] BYREF
  int v11; // [esp+28h] [ebp-24h] BYREF
  int v12; // [esp+2Ch] [ebp-20h] BYREF
  int v13; // [esp+30h] [ebp-1Ch] BYREF
  int j; // [esp+34h] [ebp-18h]
  int i; // [esp+38h] [ebp-14h]
  _DWORD *v16; // [esp+3Ch] [ebp-10h]
  int v17; // [esp+48h] [ebp-4h]

  v16 = this;
  CPersistence::CPersistence(this);
  *v16 = &CBuildingSupplyPriority::_vftable_;
  std::map<int,std::map<int,int>>::map<int,std::map<int,int>>(v16 + 1);
  v17 = 0;
  operator^<unsigned long>(a2, v5);
  operator^<unsigned int>(a2, &v7);
  v6 = v7;
  if ( v7 != 1 )
  {
    BBSupportTracePrintF(3, "Unknown fileFormatVersion for CGoodTransportPriority");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v13 = 0;
  operator^<int>(a2, (int)&v13);
  for ( i = 0; i < v13; ++i )
  {
    v9 = 0;
    operator^<int>(a2, (int)&v9);
    v12 = 0;
    operator^<int>(a2, (int)&v12);
    std::map<int,int>::map<int,int>(v4);
    LOBYTE(v17) = 1;
    for ( j = 0; j < v12; ++j )
    {
      v11 = 0;
      operator^<int>(a2, (int)&v11);
      v10 = 0;
      operator^<int>(a2, (int)&v10);
      v2 = (_DWORD *)std::map<int,int>::operator[](&v11);
      *v2 = v10;
    }
    std::map<int,std::map<int,int>>::operator[](&v9);
    std::map<int,int>::operator=(v4);
    LOBYTE(v17) = 0;
    std::map<int,int>::~map<int,int>(v4);
  }
  v17 = -1;
  return v16;
}


// address=[0x140aca0]
// Decompiled from int __thiscall CBuildingSupplyPriority::Store(struct CPersistence *this, struct std::ostream *a2)
void  CBuildingSupplyPriority::Store(std::ostream &) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-88h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-7Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-70h] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-64h] BYREF
  _BYTE v7[12]; // [esp+34h] [ebp-58h] BYREF
  _BYTE v8[12]; // [esp+40h] [ebp-4Ch] BYREF
  int v9; // [esp+4Ch] [ebp-40h] BYREF
  int v10[2]; // [esp+50h] [ebp-3Ch] BYREF
  std::_Iterator_base12 *v11; // [esp+58h] [ebp-34h]
  int v12; // [esp+5Ch] [ebp-30h] BYREF
  int v13[2]; // [esp+60h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v14; // [esp+68h] [ebp-24h]
  int v15; // [esp+6Ch] [ebp-20h] BYREF
  int v16; // [esp+70h] [ebp-1Ch] BYREF
  int v17; // [esp+74h] [ebp-18h]
  struct CPersistence *v18; // [esp+78h] [ebp-14h]
  char v19; // [esp+7Eh] [ebp-Eh]
  char v20; // [esp+7Fh] [ebp-Dh]
  int v21; // [esp+88h] [ebp-4h]

  v18 = this;
  CPersistence::Store(this, a2);
  v16 = 1;
  operator^<unsigned int>(a2, &v16);
  v15 = std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::size((char *)v18 + 4);
  operator^<int>((int)a2, &v15);
  std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::begin(v7);
  v21 = 0;
  while ( 1 )
  {
    v14 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::end(v5);
    v13[1] = (int)v14;
    LOBYTE(v21) = 1;
    v20 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator!=(v14);
    LOBYTE(v21) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v5);
    if ( !v20 )
      break;
    v13[0] = *(_DWORD *)std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator*(v7);
    operator^<int>((int)a2, v13);
    v17 = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator*(v7)
        + 4;
    v12 = std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::size(v17);
    operator^<int>((int)a2, &v12);
    std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::begin(v8);
    LOBYTE(v21) = 2;
    while ( 1 )
    {
      v11 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::end(v3);
      v10[1] = (int)v11;
      LOBYTE(v21) = 3;
      v19 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::operator!=(v11);
      LOBYTE(v21) = 2;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v3);
      if ( !v19 )
        break;
      v10[0] = *(_DWORD *)std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::operator*(v8);
      operator^<int>((int)a2, v10);
      v9 = *(_DWORD *)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::operator*(v8)
                     + 4);
      operator^<int>((int)a2, &v9);
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::operator++(v4, 0);
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v4);
    }
    LOBYTE(v21) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v8);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator++(
      v6,
      0);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v6);
  }
  v21 = -1;
  return std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v7);
}


// address=[0x140aea0]
// Decompiled from CBuildingSupplyPriority *__thiscall CBuildingSupplyPriority::CBuildingSupplyPriority(  CBuildingSupplyPriority *this,  int a2)
 CBuildingSupplyPriority::CBuildingSupplyPriority(int) {
  
  CPersistence::CPersistence(this);
  *(_DWORD *)this = &CBuildingSupplyPriority::_vftable_;
  std::map<int,std::map<int,int>>::map<int,std::map<int,int>>((char *)this + 4);
  switch ( a2 )
  {
    case 0:
      CBuildingSupplyPriority::CreateRomanPriorities(this);
      break;
    case 1:
      CBuildingSupplyPriority::CreateVikingPriorities(this);
      break;
    case 2:
      CBuildingSupplyPriority::CreateMayaPriorities(this);
      break;
    case 4:
      CBuildingSupplyPriority::CreateTrojanPriorities(this);
      break;
    default:
      return this;
  }
  return this;
}


// address=[0x140af60]
// Decompiled from int __thiscall CBuildingSupplyPriority::GetPriority(void *this, int a2, int a3)
int  CBuildingSupplyPriority::GetPriority(enum BUILDING_TYPES,enum PILE_TYPES) {
  
  _BYTE v4[12]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-50h] BYREF
  int v7; // [esp+28h] [ebp-44h]
  int v8; // [esp+2Ch] [ebp-40h]
  int v9; // [esp+30h] [ebp-3Ch]
  int v10; // [esp+34h] [ebp-38h] BYREF
  _DWORD v11[2]; // [esp+38h] [ebp-34h] BYREF
  std::_Iterator_base12 *v12; // [esp+40h] [ebp-2Ch]
  std::_Iterator_base12 *v13; // [esp+44h] [ebp-28h]
  std::_Iterator_base12 *v14; // [esp+48h] [ebp-24h]
  int v15; // [esp+4Ch] [ebp-20h] BYREF
  BOOL v16; // [esp+50h] [ebp-1Ch]
  void *v17; // [esp+54h] [ebp-18h]
  int v18; // [esp+58h] [ebp-14h]
  char v19; // [esp+5Eh] [ebp-Eh]
  bool v20; // [esp+5Fh] [ebp-Dh]
  int v21; // [esp+68h] [ebp-4h]

  v17 = this;
  v18 = 0;
  v15 = a2;
  std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::find(
    v6,
    &v15);
  v21 = 0;
  v14 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::end(v5);
  v13 = v14;
  LOBYTE(v21) = 1;
  v18 |= 1u;
  v16 = !(unsigned __int8)std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator!=(v14)
     && BBSupportDbgReport(2, "Logic\\BuildingSupplyPriority.cpp", 152, "findAt!=m_cBuildingList.end()") == 1;
  v20 = v16;
  v21 = 0;
  if ( (v18 & 1) != 0 )
  {
    v18 &= ~1u;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v5);
  }
  if ( v20 )
    __debugbreak();
  v12 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::end(v4);
  v11[1] = v12;
  LOBYTE(v21) = 2;
  v19 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator!=(v12);
  LOBYTE(v21) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v4);
  if ( v19 )
  {
    v11[0] = a2;
    v9 = std::map<int,std::map<int,int>>::operator[](v11);
    v10 = a3;
    v8 = *(_DWORD *)std::map<int,int>::operator[](&v10);
    v21 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v6);
    return v8;
  }
  else
  {
    v7 = 0;
    v21 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v6);
    return v7;
  }
}


// address=[0x140b0f0]
// Decompiled from int __thiscall CBuildingSupplyPriority::GetNumberOfSupplyBuildings(void *this, int a2, int a3)
int  CBuildingSupplyPriority::GetNumberOfSupplyBuildings(enum PILE_TYPES,struct SDistributionInfo * const) {
  
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  std::_Iterator_base12 *v6; // [esp-4h] [ebp-84h]
  _BYTE v7[12]; // [esp+4h] [ebp-7Ch] BYREF
  _BYTE v8[12]; // [esp+10h] [ebp-70h] BYREF
  _BYTE v9[12]; // [esp+1Ch] [ebp-64h] BYREF
  _BYTE v10[12]; // [esp+28h] [ebp-58h] BYREF
  _BYTE v11[12]; // [esp+34h] [ebp-4Ch] BYREF
  int v12; // [esp+40h] [ebp-40h]
  _DWORD v13[2]; // [esp+44h] [ebp-3Ch] BYREF
  int v14; // [esp+4Ch] [ebp-34h]
  _DWORD v15[2]; // [esp+50h] [ebp-30h] BYREF
  std::_Iterator_base12 *v16; // [esp+58h] [ebp-28h]
  std::_Iterator_base12 *v17; // [esp+5Ch] [ebp-24h]
  std::_Iterator_base12 *v18; // [esp+60h] [ebp-20h]
  void *v19; // [esp+64h] [ebp-1Ch]
  int v20; // [esp+68h] [ebp-18h]
  int v21; // [esp+6Ch] [ebp-14h]
  char v22; // [esp+72h] [ebp-Eh]
  char v23; // [esp+73h] [ebp-Dh]
  int v24; // [esp+7Ch] [ebp-4h]

  v19 = this;
  v21 = 0;
  std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::begin(v11);
  v24 = 0;
  while ( 1 )
  {
    v18 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::end(v9);
    v17 = v18;
    LOBYTE(v24) = 1;
    v23 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator!=(v18);
    LOBYTE(v24) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v9);
    if ( !v23 )
      break;
    v20 = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator*(v11)
        + 4;
    v15[0] = a2;
    v16 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::end(v7);
    v15[1] = v16;
    LOBYTE(v24) = 2;
    v6 = v16;
    v14 = std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::find(
            v8,
            v15);
    v13[1] = v14;
    LOBYTE(v24) = 3;
    v22 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::operator!=(v6);
    LOBYTE(v24) = 2;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v8);
    LOBYTE(v24) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v7);
    if ( v22 )
    {
      v3 = (_DWORD *)std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator*(v11);
      *(_DWORD *)(a3 + 8 * v21) = *v3;
      v13[0] = a2;
      v4 = (_DWORD *)std::map<int,int>::operator[](v13);
      *(_DWORD *)(a3 + 8 * v21++ + 4) = *v4;
    }
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator++(
      v10,
      0);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v10);
  }
  v12 = v21;
  v24 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v11);
  return v12;
}


// address=[0x140b280]
// Decompiled from int __thiscall CBuildingSupplyPriority::GetNumberOfSupplyBuildings(void *this, int a2)
int  CBuildingSupplyPriority::GetNumberOfSupplyBuildings(enum PILE_TYPES) {
  
  std::_Iterator_base12 *v3; // [esp-4h] [ebp-80h]
  _BYTE v4[12]; // [esp+4h] [ebp-78h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-6Ch] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-60h] BYREF
  _BYTE v7[12]; // [esp+28h] [ebp-54h] BYREF
  _BYTE v8[12]; // [esp+34h] [ebp-48h] BYREF
  int v9; // [esp+40h] [ebp-3Ch]
  int v10; // [esp+44h] [ebp-38h]
  int v11; // [esp+48h] [ebp-34h]
  _DWORD v12[2]; // [esp+4Ch] [ebp-30h] BYREF
  std::_Iterator_base12 *v13; // [esp+54h] [ebp-28h]
  std::_Iterator_base12 *v14; // [esp+58h] [ebp-24h]
  std::_Iterator_base12 *v15; // [esp+5Ch] [ebp-20h]
  int v16; // [esp+60h] [ebp-1Ch]
  void *v17; // [esp+64h] [ebp-18h]
  int v18; // [esp+68h] [ebp-14h]
  char v19; // [esp+6Eh] [ebp-Eh]
  char v20; // [esp+6Fh] [ebp-Dh]
  int v21; // [esp+78h] [ebp-4h]

  v17 = this;
  v18 = 0;
  std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::begin(v8);
  v21 = 0;
  while ( 1 )
  {
    v15 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::end(v6);
    v14 = v15;
    LOBYTE(v21) = 1;
    v20 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator!=(v15);
    LOBYTE(v21) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v6);
    if ( !v20 )
      break;
    v16 = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator*(v8)
        + 4;
    v12[0] = a2;
    v13 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::end(v4);
    v12[1] = v13;
    LOBYTE(v21) = 2;
    v3 = v13;
    v11 = std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::find(
            v5,
            v12);
    v10 = v11;
    LOBYTE(v21) = 3;
    v19 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::operator!=(v3);
    LOBYTE(v21) = 2;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v5);
    LOBYTE(v21) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v4);
    if ( v19 )
      ++v18;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator++(
      v7,
      0);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v7);
  }
  v9 = v18;
  v21 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v8);
  return v9;
}


// address=[0x140b3d0]
// Decompiled from int __thiscall CBuildingSupplyPriority::ChangePriority(void *this, int a2, int a3)
void  CBuildingSupplyPriority::ChangePriority(enum PILE_TYPES,struct SDistributionInfo * const) {
  
  int v3; // eax
  std::_Iterator_base12 *v5; // [esp-4h] [ebp-94h]
  _BYTE v6[12]; // [esp+4h] [ebp-8Ch] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-80h] BYREF
  _BYTE v8[12]; // [esp+1Ch] [ebp-74h] BYREF
  _BYTE v9[12]; // [esp+28h] [ebp-68h] BYREF
  _BYTE v10[12]; // [esp+34h] [ebp-5Ch] BYREF
  _BYTE v11[12]; // [esp+40h] [ebp-50h] BYREF
  int v12; // [esp+4Ch] [ebp-44h]
  int v13; // [esp+50h] [ebp-40h]
  _DWORD v14[2]; // [esp+54h] [ebp-3Ch] BYREF
  int v15; // [esp+5Ch] [ebp-34h]
  _DWORD v16[2]; // [esp+60h] [ebp-30h] BYREF
  std::_Iterator_base12 *v17; // [esp+68h] [ebp-28h]
  std::_Iterator_base12 *v18; // [esp+6Ch] [ebp-24h]
  std::_Iterator_base12 *v19; // [esp+70h] [ebp-20h]
  void *v20; // [esp+74h] [ebp-1Ch]
  int v21; // [esp+78h] [ebp-18h]
  int v22; // [esp+7Ch] [ebp-14h]
  char v23; // [esp+82h] [ebp-Eh]
  char v24; // [esp+83h] [ebp-Dh]
  int v25; // [esp+8Ch] [ebp-4h]

  v20 = this;
  v22 = 0;
  std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::begin(v11);
  v25 = 0;
  while ( 1 )
  {
    v19 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::end(v9);
    v18 = v19;
    LOBYTE(v25) = 1;
    v24 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator!=(v19);
    LOBYTE(v25) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v9);
    if ( !v24 )
      break;
    v21 = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator*(v11)
        + 4;
    v16[0] = a2;
    v17 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::end(v7);
    v16[1] = v17;
    LOBYTE(v25) = 2;
    v5 = v17;
    v15 = std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::find(
            v8,
            v16);
    v14[1] = v15;
    LOBYTE(v25) = 3;
    v23 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::operator!=(v5);
    LOBYTE(v25) = 2;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v8);
    LOBYTE(v25) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v7);
    if ( v23 )
    {
      v14[0] = a2;
      v13 = std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::find(
              v6,
              v14);
      v12 = v13;
      LOBYTE(v25) = 4;
      v3 = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::operator*(v13);
      *(_DWORD *)(v3 + 4) = *(_DWORD *)(a3 + 8 * v22 + 4);
      LOBYTE(v25) = 0;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,int>>>>(v6);
      BBSupportTracePrintF(1, " Change Good %d Priotity to %d", a2, *(_DWORD *)(a3 + 8 * v22++ + 4));
    }
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator++(
      v10,
      0);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v10);
  }
  v25 = -1;
  return std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v11);
}


// address=[0x140b590]
// Decompiled from int __thiscall CBuildingSupplyPriority::ChangePriority(void *this, int a2, int a3, int a4)
void  CBuildingSupplyPriority::ChangePriority(enum PILE_TYPES,enum BUILDING_TYPES,int) {
  
  int *v4; // eax
  _BYTE v6[12]; // [esp+4h] [ebp-6Ch] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-60h] BYREF
  _BYTE v8[12]; // [esp+1Ch] [ebp-54h] BYREF
  int v9; // [esp+28h] [ebp-48h] BYREF
  int v10; // [esp+2Ch] [ebp-44h]
  int v11; // [esp+30h] [ebp-40h] BYREF
  _DWORD v12[2]; // [esp+34h] [ebp-3Ch] BYREF
  std::_Iterator_base12 *v13; // [esp+3Ch] [ebp-34h]
  std::_Iterator_base12 *v14; // [esp+40h] [ebp-30h]
  std::_Iterator_base12 *v15; // [esp+44h] [ebp-2Ch]
  _DWORD v16[2]; // [esp+48h] [ebp-28h] BYREF
  BOOL v17; // [esp+50h] [ebp-20h]
  void *v18; // [esp+54h] [ebp-1Ch]
  int v19; // [esp+58h] [ebp-18h]
  int v20; // [esp+5Ch] [ebp-14h]
  char v21; // [esp+62h] [ebp-Eh]
  bool v22; // [esp+63h] [ebp-Dh]
  int v23; // [esp+6Ch] [ebp-4h]

  v18 = this;
  v20 = 0;
  v16[0] = a3;
  std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::find(
    v8,
    v16);
  v23 = 0;
  v15 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::end(v7);
  v14 = v15;
  LOBYTE(v23) = 1;
  v20 |= 1u;
  v17 = !(unsigned __int8)std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator!=(v15)
     && BBSupportDbgReport(2, "Logic\\BuildingSupplyPriority.cpp", 218, "findAt!=m_cBuildingList.end()") == 1;
  v22 = v17;
  v23 = 0;
  if ( (v20 & 1) != 0 )
  {
    v20 &= ~1u;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v7);
  }
  if ( v22 )
    __debugbreak();
  v13 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<int,std::map<int,int>,std::less<int>,std::allocator<std::pair<int const,std::map<int,int>>>,0>>::end(v6);
  v12[1] = v13;
  LOBYTE(v23) = 2;
  v21 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::operator!=(v13);
  LOBYTE(v23) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v6);
  if ( v21 )
  {
    v12[0] = a3;
    v16[1] = std::map<int,std::map<int,int>>::operator[](v12);
    v11 = a2;
    v10 = *(_DWORD *)std::map<int,int>::operator[](&v11);
    v19 = a4 + v10;
    if ( a4 + v10 >= 0 )
    {
      if ( v19 > 100 )
        v19 = 100;
    }
    else
    {
      v19 = 0;
    }
    v9 = a2;
    v4 = (int *)std::map<int,int>::operator[](&v9);
    *v4 = v19;
  }
  v23 = -1;
  return std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const,std::map<int,int>>>>>(v8);
}


// address=[0x1417110]
// Decompiled from int __thiscall CBuildingSupplyPriority::ClassID(CBuildingSupplyPriority *this)
unsigned long  CBuildingSupplyPriority::ClassID(void)const {
  
  return CBuildingSupplyPriority::m_iClassID;
}


// address=[0x14380c0]
// Decompiled from void __thiscall CBuildingSupplyPriority::~CBuildingSupplyPriority(CDaoIndexFieldInfo *this)
 CBuildingSupplyPriority::~CBuildingSupplyPriority(void) {
  
  std::map<int,std::map<int,int>>::~map<int,std::map<int,int>>((char *)this + 4, this);
}


// address=[0x3d8948c]
// [Decompilation failed for static unsigned long CBuildingSupplyPriority::m_iClassID]

// address=[0x140b740]
// Decompiled from int __thiscall CBuildingSupplyPriority::CreateRomanPriorities(CBuildingSupplyPriority *this)
void  CBuildingSupplyPriority::CreateRomanPriorities(void) {
  
  int IntArray; // esi
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  _BYTE v14[12]; // [esp+Ch] [ebp-C0h] BYREF
  _BYTE v15[12]; // [esp+18h] [ebp-B4h] BYREF
  _BYTE v16[12]; // [esp+24h] [ebp-A8h] BYREF
  _BYTE v17[12]; // [esp+30h] [ebp-9Ch] BYREF
  _BYTE v18[12]; // [esp+3Ch] [ebp-90h] BYREF
  _BYTE v19[12]; // [esp+48h] [ebp-84h] BYREF
  _BYTE v20[12]; // [esp+54h] [ebp-78h] BYREF
  _BYTE v21[12]; // [esp+60h] [ebp-6Ch] BYREF
  int v22; // [esp+6Ch] [ebp-60h] BYREF
  int v23; // [esp+70h] [ebp-5Ch] BYREF
  int v24; // [esp+74h] [ebp-58h] BYREF
  int v25; // [esp+78h] [ebp-54h] BYREF
  int v26; // [esp+7Ch] [ebp-50h] BYREF
  int v27; // [esp+80h] [ebp-4Ch] BYREF
  int v28; // [esp+84h] [ebp-48h] BYREF
  int v29; // [esp+88h] [ebp-44h] BYREF
  int v30; // [esp+8Ch] [ebp-40h] BYREF
  int v31; // [esp+90h] [ebp-3Ch] BYREF
  int v32; // [esp+94h] [ebp-38h] BYREF
  int v33; // [esp+98h] [ebp-34h] BYREF
  int v34; // [esp+9Ch] [ebp-30h] BYREF
  int v35; // [esp+A0h] [ebp-2Ch] BYREF
  int v36; // [esp+A4h] [ebp-28h] BYREF
  int v37; // [esp+A8h] [ebp-24h] BYREF
  int v38; // [esp+ACh] [ebp-20h] BYREF
  int v39; // [esp+B0h] [ebp-1Ch] BYREF
  int v40; // [esp+B4h] [ebp-18h] BYREF
  _DWORD v41[2]; // [esp+B8h] [ebp-14h] BYREF
  int v42; // [esp+C8h] [ebp-4h]

  v41[1] = this;
  CBuildingSupplyPriority::CreateAllRacesPriorities(this);
  std::map<int,int>::map<int,int>(v17);
  v42 = 0;
  v41[0] = 20;
  IntArray = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_SHIPYARD);
  *(_DWORD *)std::map<int,int>::operator[](v41) = *(_DWORD *)(IntArray + 4);
  v40 = 31;
  std::map<int,std::map<int,int>>::operator[](&v40);
  std::map<int,int>::operator=(v17);
  v42 = -1;
  std::map<int,int>::~map<int,int>(v17);
  std::map<int,int>::map<int,int>(v16);
  v42 = 1;
  v39 = 10;
  v2 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_GOLDMELT);
  *(_DWORD *)std::map<int,int>::operator[](&v39) = *(_DWORD *)(v2 + 4);
  v38 = 19;
  std::map<int,std::map<int,int>>::operator[](&v38);
  std::map<int,int>::operator=(v16);
  v42 = -1;
  std::map<int,int>::~map<int,int>(v16);
  std::map<int,int>::map<int,int>(v15);
  v42 = 2;
  v37 = 10;
  v3 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_IRONMELT);
  *(_DWORD *)std::map<int,int>::operator[](&v37) = *(_DWORD *)(v3 + 4);
  v36 = 20;
  std::map<int,std::map<int,int>>::operator[](&v36);
  std::map<int,int>::operator=(v15);
  v42 = -1;
  std::map<int,int>::~map<int,int>(v15);
  std::map<int,int>::map<int,int>(v21);
  v42 = 3;
  v35 = 10;
  v4 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_TOOLSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v35) = *(_DWORD *)(v4 + 4);
  v34 = 20;
  v5 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_TOOLSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v34) = *(_DWORD *)(v5 + 4);
  v33 = 21;
  std::map<int,std::map<int,int>>::operator[](&v33);
  std::map<int,int>::operator=(v21);
  v42 = -1;
  std::map<int,int>::~map<int,int>(v21);
  std::map<int,int>::map<int,int>(v20);
  v42 = 4;
  v32 = 10;
  v6 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_WEAPONSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v32) = *(_DWORD *)(v6 + 4);
  v31 = 20;
  v7 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_WEAPONSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v31) = *(_DWORD *)(v7 + 4);
  v30 = 22;
  std::map<int,std::map<int,int>>::operator[](&v30);
  std::map<int,int>::operator=(v20);
  v42 = -1;
  std::map<int,int>::~map<int,int>(v20);
  std::map<int,int>::map<int,int>(v14);
  v42 = 5;
  v29 = 36;
  v8 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_BAKERY);
  *(_DWORD *)std::map<int,int>::operator[](&v29) = *(_DWORD *)(v8 + 4);
  v28 = 10;
  std::map<int,std::map<int,int>>::operator[](&v28);
  std::map<int,int>::operator=(v14);
  v42 = -1;
  std::map<int,int>::~map<int,int>(v14);
  std::map<int,int>::map<int,int>(v19);
  v42 = 6;
  v27 = 36;
  v9 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_ANIMALFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v27) = *(_DWORD *)(v9 + 4);
  v26 = 16;
  v10 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_ANIMALRANCH);
  *(_DWORD *)std::map<int,int>::operator[](&v26) = *(_DWORD *)(v10 + 4);
  v25 = 12;
  std::map<int,std::map<int,int>>::operator[](&v25);
  std::map<int,int>::operator=(v19);
  v42 = -1;
  std::map<int,int>::~map<int,int>(v19);
  std::map<int,int>::map<int,int>(v18);
  v42 = 7;
  v24 = 36;
  v11 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_DONKEYFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v24) = *(_DWORD *)(v11 + 4);
  v23 = 16;
  v12 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_DONKEYFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v23) = *(_DWORD *)(v12 + 4);
  v22 = 13;
  std::map<int,std::map<int,int>>::operator[](&v22);
  std::map<int,int>::operator=(v18);
  v42 = -1;
  return std::map<int,int>::~map<int,int>(v18);
}


// address=[0x140bbe0]
// Decompiled from int __thiscall CBuildingSupplyPriority::CreateVikingPriorities(CBuildingSupplyPriority *this)
void  CBuildingSupplyPriority::CreateVikingPriorities(void) {
  
  int IntArray; // esi
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // esi
  _BYTE v17[12]; // [esp+Ch] [ebp-FCh] BYREF
  _BYTE v18[12]; // [esp+18h] [ebp-F0h] BYREF
  _BYTE v19[12]; // [esp+24h] [ebp-E4h] BYREF
  _BYTE v20[12]; // [esp+30h] [ebp-D8h] BYREF
  _BYTE v21[12]; // [esp+3Ch] [ebp-CCh] BYREF
  _BYTE v22[12]; // [esp+48h] [ebp-C0h] BYREF
  _BYTE v23[12]; // [esp+54h] [ebp-B4h] BYREF
  _BYTE v24[12]; // [esp+60h] [ebp-A8h] BYREF
  _BYTE v25[12]; // [esp+6Ch] [ebp-9Ch] BYREF
  _BYTE v26[12]; // [esp+78h] [ebp-90h] BYREF
  _BYTE v27[12]; // [esp+84h] [ebp-84h] BYREF
  int v28; // [esp+90h] [ebp-78h] BYREF
  int v29; // [esp+94h] [ebp-74h] BYREF
  int v30; // [esp+98h] [ebp-70h] BYREF
  int v31; // [esp+9Ch] [ebp-6Ch] BYREF
  int v32; // [esp+A0h] [ebp-68h] BYREF
  int v33; // [esp+A4h] [ebp-64h] BYREF
  int v34; // [esp+A8h] [ebp-60h] BYREF
  int v35; // [esp+ACh] [ebp-5Ch] BYREF
  int v36; // [esp+B0h] [ebp-58h] BYREF
  int v37; // [esp+B4h] [ebp-54h] BYREF
  int v38; // [esp+B8h] [ebp-50h] BYREF
  int v39; // [esp+BCh] [ebp-4Ch] BYREF
  int v40; // [esp+C0h] [ebp-48h] BYREF
  int v41; // [esp+C4h] [ebp-44h] BYREF
  int v42; // [esp+C8h] [ebp-40h] BYREF
  int v43; // [esp+CCh] [ebp-3Ch] BYREF
  int v44; // [esp+D0h] [ebp-38h] BYREF
  int v45; // [esp+D4h] [ebp-34h] BYREF
  int v46; // [esp+D8h] [ebp-30h] BYREF
  int v47; // [esp+DCh] [ebp-2Ch] BYREF
  int v48; // [esp+E0h] [ebp-28h] BYREF
  int v49; // [esp+E4h] [ebp-24h] BYREF
  int v50; // [esp+E8h] [ebp-20h] BYREF
  int v51; // [esp+ECh] [ebp-1Ch] BYREF
  int v52; // [esp+F0h] [ebp-18h] BYREF
  _DWORD v53[2]; // [esp+F4h] [ebp-14h] BYREF
  int v54; // [esp+104h] [ebp-4h]

  v53[1] = this;
  CBuildingSupplyPriority::CreateAllRacesPriorities(this);
  std::map<int,int>::map<int,int>(v23);
  v54 = 0;
  v53[0] = 36;
  IntArray = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_MEADMAKERHUT);
  *(_DWORD *)std::map<int,int>::operator[](v53) = *(_DWORD *)(IntArray + 8);
  v52 = 39;
  std::map<int,std::map<int,int>>::operator[](&v52);
  std::map<int,int>::operator=(v23);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v23);
  std::map<int,int>::map<int,int>(v22);
  v54 = 1;
  v51 = 20;
  v2 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_SHIPYARD);
  *(_DWORD *)std::map<int,int>::operator[](&v51) = *(_DWORD *)(v2 + 8);
  v50 = 31;
  std::map<int,std::map<int,int>>::operator[](&v50);
  std::map<int,int>::operator=(v22);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v22);
  std::map<int,int>::map<int,int>(v21);
  v54 = 2;
  v49 = 22;
  v3 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_LOG_CHARCOALMAKER);
  *(_DWORD *)std::map<int,int>::operator[](&v49) = *(_DWORD *)(v3 + 8);
  v48 = 25;
  std::map<int,std::map<int,int>>::operator[](&v48);
  std::map<int,int>::operator=(v21);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v21);
  std::map<int,int>::map<int,int>(v20);
  v54 = 3;
  v47 = 22;
  v4 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_LOG_SAWMILL);
  *(_DWORD *)std::map<int,int>::operator[](&v47) = *(_DWORD *)(v4 + 8);
  v46 = 3;
  std::map<int,std::map<int,int>>::operator[](&v46);
  std::map<int,int>::operator=(v20);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v20);
  std::map<int,int>::map<int,int>(v19);
  v54 = 4;
  v45 = 10;
  v5 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_GOLDMELT);
  *(_DWORD *)std::map<int,int>::operator[](&v45) = *(_DWORD *)(v5 + 8);
  v44 = 19;
  std::map<int,std::map<int,int>>::operator[](&v44);
  std::map<int,int>::operator=(v19);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v19);
  std::map<int,int>::map<int,int>(v18);
  v54 = 5;
  v43 = 10;
  v6 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_IRONMELT);
  *(_DWORD *)std::map<int,int>::operator[](&v43) = *(_DWORD *)(v6 + 8);
  v42 = 20;
  std::map<int,std::map<int,int>>::operator[](&v42);
  std::map<int,int>::operator=(v18);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v18);
  std::map<int,int>::map<int,int>(v27);
  v54 = 6;
  v41 = 10;
  v7 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_TOOLSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v41) = *(_DWORD *)(v7 + 8);
  v40 = 20;
  v8 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_TOOLSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v40) = *(_DWORD *)(v8 + 8);
  v39 = 21;
  std::map<int,std::map<int,int>>::operator[](&v39);
  std::map<int,int>::operator=(v27);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v27);
  std::map<int,int>::map<int,int>(v26);
  v54 = 7;
  v38 = 10;
  v9 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_WEAPONSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v38) = *(_DWORD *)(v9 + 8);
  v37 = 20;
  v10 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_WEAPONSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v37) = *(_DWORD *)(v10 + 8);
  v36 = 22;
  std::map<int,std::map<int,int>>::operator[](&v36);
  std::map<int,int>::operator=(v26);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v26);
  std::map<int,int>::map<int,int>(v17);
  v54 = 8;
  v35 = 36;
  v11 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_BAKERY);
  *(_DWORD *)std::map<int,int>::operator[](&v35) = *(_DWORD *)(v11 + 8);
  v34 = 10;
  std::map<int,std::map<int,int>>::operator[](&v34);
  std::map<int,int>::operator=(v17);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v17);
  std::map<int,int>::map<int,int>(v25);
  v54 = 9;
  v33 = 36;
  v12 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_ANIMALFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v33) = *(_DWORD *)(v12 + 8);
  v32 = 16;
  v13 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_ANIMALRANCH);
  *(_DWORD *)std::map<int,int>::operator[](&v32) = *(_DWORD *)(v13 + 8);
  v31 = 12;
  std::map<int,std::map<int,int>>::operator[](&v31);
  std::map<int,int>::operator=(v25);
  v54 = -1;
  std::map<int,int>::~map<int,int>(v25);
  std::map<int,int>::map<int,int>(v24);
  v54 = 10;
  v30 = 36;
  v14 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_DONKEYFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v30) = *(_DWORD *)(v14 + 8);
  v29 = 16;
  v15 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_DONKEYFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v29) = *(_DWORD *)(v15 + 8);
  v28 = 13;
  std::map<int,std::map<int,int>>::operator[](&v28);
  std::map<int,int>::operator=(v24);
  v54 = -1;
  return std::map<int,int>::~map<int,int>(v24);
}


// address=[0x140c1f0]
// Decompiled from int __thiscall CBuildingSupplyPriority::CreateMayaPriorities(CBuildingSupplyPriority *this)
void  CBuildingSupplyPriority::CreateMayaPriorities(void) {
  
  int IntArray; // esi
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  _BYTE v16[12]; // [esp+Ch] [ebp-E8h] BYREF
  _BYTE v17[12]; // [esp+18h] [ebp-DCh] BYREF
  _BYTE v18[12]; // [esp+24h] [ebp-D0h] BYREF
  _BYTE v19[12]; // [esp+30h] [ebp-C4h] BYREF
  _BYTE v20[12]; // [esp+3Ch] [ebp-B8h] BYREF
  _BYTE v21[12]; // [esp+48h] [ebp-ACh] BYREF
  _BYTE v22[12]; // [esp+54h] [ebp-A0h] BYREF
  _BYTE v23[12]; // [esp+60h] [ebp-94h] BYREF
  _BYTE v24[12]; // [esp+6Ch] [ebp-88h] BYREF
  _BYTE v25[12]; // [esp+78h] [ebp-7Ch] BYREF
  int v26; // [esp+84h] [ebp-70h] BYREF
  int v27; // [esp+88h] [ebp-6Ch] BYREF
  int v28; // [esp+8Ch] [ebp-68h] BYREF
  int v29; // [esp+90h] [ebp-64h] BYREF
  int v30; // [esp+94h] [ebp-60h] BYREF
  int v31; // [esp+98h] [ebp-5Ch] BYREF
  int v32; // [esp+9Ch] [ebp-58h] BYREF
  int v33; // [esp+A0h] [ebp-54h] BYREF
  int v34; // [esp+A4h] [ebp-50h] BYREF
  int v35; // [esp+A8h] [ebp-4Ch] BYREF
  int v36; // [esp+ACh] [ebp-48h] BYREF
  int v37; // [esp+B0h] [ebp-44h] BYREF
  int v38; // [esp+B4h] [ebp-40h] BYREF
  int v39; // [esp+B8h] [ebp-3Ch] BYREF
  int v40; // [esp+BCh] [ebp-38h] BYREF
  int v41; // [esp+C0h] [ebp-34h] BYREF
  int v42; // [esp+C4h] [ebp-30h] BYREF
  int v43; // [esp+C8h] [ebp-2Ch] BYREF
  int v44; // [esp+CCh] [ebp-28h] BYREF
  int v45; // [esp+D0h] [ebp-24h] BYREF
  int v46; // [esp+D4h] [ebp-20h] BYREF
  int v47; // [esp+D8h] [ebp-1Ch] BYREF
  int v48; // [esp+DCh] [ebp-18h] BYREF
  _DWORD v49[2]; // [esp+E0h] [ebp-14h] BYREF
  int v50; // [esp+F0h] [ebp-4h]

  v49[1] = this;
  CBuildingSupplyPriority::CreateAllRacesPriorities(this);
  std::map<int,int>::map<int,int>(v21);
  v50 = 0;
  v49[0] = 10;
  IntArray = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_AMMOMAKERHUT);
  *(_DWORD *)std::map<int,int>::operator[](v49) = *(_DWORD *)(IntArray + 12);
  v48 = 28;
  std::map<int,std::map<int,int>>::operator[](&v48);
  std::map<int,int>::operator=(v21);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v21);
  std::map<int,int>::map<int,int>(v20);
  v50 = 1;
  v47 = 20;
  v2 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_SHIPYARD);
  *(_DWORD *)std::map<int,int>::operator[](&v47) = *(_DWORD *)(v2 + 12);
  v46 = 31;
  std::map<int,std::map<int,int>>::operator[](&v46);
  std::map<int,int>::operator=(v20);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v20);
  std::map<int,int>::map<int,int>(v19);
  v50 = 2;
  v45 = 10;
  v3 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_GOLDMELT);
  *(_DWORD *)std::map<int,int>::operator[](&v45) = *(_DWORD *)(v3 + 12);
  v44 = 19;
  std::map<int,std::map<int,int>>::operator[](&v44);
  std::map<int,int>::operator=(v19);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v19);
  std::map<int,int>::map<int,int>(v18);
  v50 = 3;
  v43 = 10;
  v4 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_IRONMELT);
  *(_DWORD *)std::map<int,int>::operator[](&v43) = *(_DWORD *)(v4 + 12);
  v42 = 20;
  std::map<int,std::map<int,int>>::operator[](&v42);
  std::map<int,int>::operator=(v18);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v18);
  std::map<int,int>::map<int,int>(v25);
  v50 = 4;
  v41 = 10;
  v5 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_TOOLSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v41) = *(_DWORD *)(v5 + 12);
  v40 = 20;
  v6 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_TOOLSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v40) = *(_DWORD *)(v6 + 12);
  v39 = 21;
  std::map<int,std::map<int,int>>::operator[](&v39);
  std::map<int,int>::operator=(v25);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v25);
  std::map<int,int>::map<int,int>(v24);
  v50 = 5;
  v38 = 10;
  v7 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_WEAPONSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v38) = *(_DWORD *)(v7 + 12);
  v37 = 20;
  v8 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_WEAPONSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v37) = *(_DWORD *)(v8 + 12);
  v36 = 22;
  std::map<int,std::map<int,int>>::operator[](&v36);
  std::map<int,int>::operator=(v24);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v24);
  std::map<int,int>::map<int,int>(v17);
  v50 = 6;
  v35 = 36;
  v9 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_BAKERY);
  *(_DWORD *)std::map<int,int>::operator[](&v35) = *(_DWORD *)(v9 + 12);
  v34 = 10;
  std::map<int,std::map<int,int>>::operator[](&v34);
  std::map<int,int>::operator=(v17);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v17);
  std::map<int,int>::map<int,int>(v23);
  v50 = 7;
  v33 = 36;
  v10 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_ANIMALFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v33) = *(_DWORD *)(v10 + 12);
  v32 = 16;
  v11 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_ANIMALRANCH);
  *(_DWORD *)std::map<int,int>::operator[](&v32) = *(_DWORD *)(v11 + 12);
  v31 = 12;
  std::map<int,std::map<int,int>>::operator[](&v31);
  std::map<int,int>::operator=(v23);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v23);
  std::map<int,int>::map<int,int>(v22);
  v50 = 8;
  v30 = 36;
  v12 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_DONKEYFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v30) = *(_DWORD *)(v12 + 12);
  v29 = 16;
  v13 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_DONKEYFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v29) = *(_DWORD *)(v13 + 12);
  v28 = 13;
  std::map<int,std::map<int,int>>::operator[](&v28);
  std::map<int,int>::operator=(v22);
  v50 = -1;
  std::map<int,int>::~map<int,int>(v22);
  std::map<int,int>::map<int,int>(v16);
  v50 = 9;
  v27 = 36;
  v14 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_TEQUILAMAKERHUT);
  *(_DWORD *)std::map<int,int>::operator[](&v27) = *(_DWORD *)(v14 + 12);
  v26 = 37;
  std::map<int,std::map<int,int>>::operator[](&v26);
  std::map<int,int>::operator=(v16);
  v50 = -1;
  return std::map<int,int>::~map<int,int>(v16);
}


// address=[0x140c790]
// Decompiled from int __thiscall CBuildingSupplyPriority::CreateTrojanPriorities(CBuildingSupplyPriority *this)
void  CBuildingSupplyPriority::CreateTrojanPriorities(void) {
  
  int IntArray; // esi
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // esi
  _BYTE v17[12]; // [esp+Ch] [ebp-ECh] BYREF
  _BYTE v18[12]; // [esp+18h] [ebp-E0h] BYREF
  _BYTE v19[12]; // [esp+24h] [ebp-D4h] BYREF
  _BYTE v20[12]; // [esp+30h] [ebp-C8h] BYREF
  _BYTE v21[12]; // [esp+3Ch] [ebp-BCh] BYREF
  _BYTE v22[12]; // [esp+48h] [ebp-B0h] BYREF
  _BYTE v23[12]; // [esp+54h] [ebp-A4h] BYREF
  _BYTE v24[12]; // [esp+60h] [ebp-98h] BYREF
  _BYTE v25[12]; // [esp+6Ch] [ebp-8Ch] BYREF
  _BYTE v26[12]; // [esp+78h] [ebp-80h] BYREF
  int v27; // [esp+84h] [ebp-74h] BYREF
  int v28; // [esp+88h] [ebp-70h] BYREF
  int v29; // [esp+8Ch] [ebp-6Ch] BYREF
  int v30; // [esp+90h] [ebp-68h] BYREF
  int v31; // [esp+94h] [ebp-64h] BYREF
  int v32; // [esp+98h] [ebp-60h] BYREF
  int v33; // [esp+9Ch] [ebp-5Ch] BYREF
  int v34; // [esp+A0h] [ebp-58h] BYREF
  int v35; // [esp+A4h] [ebp-54h] BYREF
  int v36; // [esp+A8h] [ebp-50h] BYREF
  int v37; // [esp+ACh] [ebp-4Ch] BYREF
  int v38; // [esp+B0h] [ebp-48h] BYREF
  int v39; // [esp+B4h] [ebp-44h] BYREF
  int v40; // [esp+B8h] [ebp-40h] BYREF
  int v41; // [esp+BCh] [ebp-3Ch] BYREF
  int v42; // [esp+C0h] [ebp-38h] BYREF
  int v43; // [esp+C4h] [ebp-34h] BYREF
  int v44; // [esp+C8h] [ebp-30h] BYREF
  int v45; // [esp+CCh] [ebp-2Ch] BYREF
  int v46; // [esp+D0h] [ebp-28h] BYREF
  int v47; // [esp+D4h] [ebp-24h] BYREF
  int v48; // [esp+D8h] [ebp-20h] BYREF
  int v49; // [esp+DCh] [ebp-1Ch] BYREF
  int v50; // [esp+E0h] [ebp-18h] BYREF
  _DWORD v51[2]; // [esp+E4h] [ebp-14h] BYREF
  int v52; // [esp+F4h] [ebp-4h]

  v51[1] = this;
  CBuildingSupplyPriority::CreateAllRacesPriorities(this);
  std::map<int,int>::map<int,int>(v26);
  v52 = 0;
  v51[0] = 22;
  IntArray = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_LOG_AMMOMAKERHUT);
  *(_DWORD *)std::map<int,int>::operator[](v51) = *(_DWORD *)(IntArray + 20);
  v50 = 10;
  v2 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_AMMOMAKERHUT);
  *(_DWORD *)std::map<int,int>::operator[](&v50) = *(_DWORD *)(v2 + 20);
  v49 = 28;
  std::map<int,std::map<int,int>>::operator[](&v49);
  std::map<int,int>::operator=(v26);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v26);
  std::map<int,int>::map<int,int>(v21);
  v52 = 1;
  v48 = 22;
  v3 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_LOG_SAWMILL);
  *(_DWORD *)std::map<int,int>::operator[](&v48) = *(_DWORD *)(v3 + 20);
  v47 = 3;
  std::map<int,std::map<int,int>>::operator[](&v47);
  std::map<int,int>::operator=(v21);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v21);
  std::map<int,int>::map<int,int>(v20);
  v52 = 2;
  v46 = 20;
  v4 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_SHIPYARD);
  *(_DWORD *)std::map<int,int>::operator[](&v46) = *(_DWORD *)(v4 + 20);
  v45 = 31;
  std::map<int,std::map<int,int>>::operator[](&v45);
  std::map<int,int>::operator=(v20);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v20);
  std::map<int,int>::map<int,int>(v19);
  v52 = 3;
  v44 = 10;
  v5 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_GOLDMELT);
  *(_DWORD *)std::map<int,int>::operator[](&v44) = *(_DWORD *)(v5 + 20);
  v43 = 19;
  std::map<int,std::map<int,int>>::operator[](&v43);
  std::map<int,int>::operator=(v19);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v19);
  std::map<int,int>::map<int,int>(v18);
  v52 = 4;
  v42 = 10;
  v6 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_IRONMELT);
  *(_DWORD *)std::map<int,int>::operator[](&v42) = *(_DWORD *)(v6 + 20);
  v41 = 20;
  std::map<int,std::map<int,int>>::operator[](&v41);
  std::map<int,int>::operator=(v18);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v18);
  std::map<int,int>::map<int,int>(v25);
  v52 = 5;
  v40 = 10;
  v7 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_TOOLSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v40) = *(_DWORD *)(v7 + 20);
  v39 = 20;
  v8 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_TOOLSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v39) = *(_DWORD *)(v8 + 20);
  v38 = 21;
  std::map<int,std::map<int,int>>::operator[](&v38);
  std::map<int,int>::operator=(v25);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v25);
  std::map<int,int>::map<int,int>(v24);
  v52 = 6;
  v37 = 10;
  v9 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_COAL_WEAPONSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v37) = *(_DWORD *)(v9 + 20);
  v36 = 20;
  v10 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_WEAPONSMITH);
  *(_DWORD *)std::map<int,int>::operator[](&v36) = *(_DWORD *)(v10 + 20);
  v35 = 22;
  std::map<int,std::map<int,int>>::operator[](&v35);
  std::map<int,int>::operator=(v24);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v24);
  std::map<int,int>::map<int,int>(v17);
  v52 = 7;
  v34 = 36;
  v11 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_BAKERY);
  *(_DWORD *)std::map<int,int>::operator[](&v34) = *(_DWORD *)(v11 + 20);
  v33 = 10;
  std::map<int,std::map<int,int>>::operator[](&v33);
  std::map<int,int>::operator=(v17);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v17);
  std::map<int,int>::map<int,int>(v23);
  v52 = 8;
  v32 = 36;
  v12 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_ANIMALFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v32) = *(_DWORD *)(v12 + 20);
  v31 = 16;
  v13 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_ANIMALRANCH);
  *(_DWORD *)std::map<int,int>::operator[](&v31) = *(_DWORD *)(v13 + 20);
  v30 = 12;
  std::map<int,std::map<int,int>>::operator[](&v30);
  std::map<int,int>::operator=(v23);
  v52 = -1;
  std::map<int,int>::~map<int,int>(v23);
  std::map<int,int>::map<int,int>(v22);
  v52 = 9;
  v29 = 36;
  v14 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_WATER_DONKEYFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v29) = *(_DWORD *)(v14 + 20);
  v28 = 16;
  v15 = TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_DONKEYFARM);
  *(_DWORD *)std::map<int,int>::operator[](&v28) = *(_DWORD *)(v15 + 20);
  v27 = 13;
  std::map<int,std::map<int,int>>::operator[](&v27);
  std::map<int,int>::operator=(v22);
  v52 = -1;
  return std::map<int,int>::~map<int,int>(v22);
}


// address=[0x140cd60]
// Decompiled from int __thiscall CBuildingSupplyPriority::CreateAllRacesPriorities(CBuildingSupplyPriority *this)
void  CBuildingSupplyPriority::CreateAllRacesPriorities(void) {
  
  _DWORD *IntArray; // esi
  _DWORD *v2; // esi
  _DWORD *v3; // esi
  _DWORD *v4; // esi
  _DWORD *v5; // esi
  _DWORD *v6; // esi
  _DWORD *v7; // esi
  _DWORD *v8; // esi
  _DWORD *v9; // esi
  _DWORD *v10; // esi
  _DWORD *v11; // esi
  _DWORD *v12; // esi
  _DWORD *v13; // esi
  _DWORD *v14; // esi
  _DWORD *v15; // esi
  _DWORD *v16; // esi
  _DWORD *v17; // esi
  _BYTE v19[12]; // [esp+10h] [ebp-118h] BYREF
  _BYTE v20[12]; // [esp+1Ch] [ebp-10Ch] BYREF
  int v21; // [esp+28h] [ebp-100h] BYREF
  _BYTE v22[12]; // [esp+2Ch] [ebp-FCh] BYREF
  _BYTE v23[12]; // [esp+38h] [ebp-F0h] BYREF
  _BYTE v24[12]; // [esp+44h] [ebp-E4h] BYREF
  _BYTE v25[12]; // [esp+50h] [ebp-D8h] BYREF
  _BYTE v26[12]; // [esp+5Ch] [ebp-CCh] BYREF
  int NumberOfSupplyBuildings; // [esp+68h] [ebp-C0h]
  int v28; // [esp+6Ch] [ebp-BCh] BYREF
  int v29; // [esp+70h] [ebp-B8h] BYREF
  int v30; // [esp+74h] [ebp-B4h] BYREF
  int v31; // [esp+78h] [ebp-B0h] BYREF
  int v32; // [esp+7Ch] [ebp-ACh] BYREF
  int v33; // [esp+80h] [ebp-A8h] BYREF
  int v34; // [esp+84h] [ebp-A4h] BYREF
  int v35; // [esp+88h] [ebp-A0h] BYREF
  int v36; // [esp+8Ch] [ebp-9Ch] BYREF
  int v37; // [esp+90h] [ebp-98h] BYREF
  int v38; // [esp+94h] [ebp-94h] BYREF
  int v39; // [esp+98h] [ebp-90h] BYREF
  int v40; // [esp+9Ch] [ebp-8Ch] BYREF
  int v41; // [esp+A0h] [ebp-88h] BYREF
  int v42; // [esp+A4h] [ebp-84h] BYREF
  int v43; // [esp+A8h] [ebp-80h] BYREF
  int v44; // [esp+ACh] [ebp-7Ch] BYREF
  int v45; // [esp+B0h] [ebp-78h] BYREF
  int v46; // [esp+B4h] [ebp-74h] BYREF
  int v47; // [esp+B8h] [ebp-70h] BYREF
  int v48; // [esp+BCh] [ebp-6Ch] BYREF
  int v49; // [esp+C0h] [ebp-68h] BYREF
  int v50; // [esp+C4h] [ebp-64h] BYREF
  int v51; // [esp+C8h] [ebp-60h]
  int i; // [esp+CCh] [ebp-5Ch]
  CBuildingSupplyPriority *v53; // [esp+D0h] [ebp-58h]
  _BYTE v54[16]; // [esp+D4h] [ebp-54h] BYREF
  _BYTE v55[52]; // [esp+E4h] [ebp-44h] BYREF
  int v56; // [esp+124h] [ebp-4h]

  v53 = this;
  std::map<int,int>::map<int,int>(v26);
  v56 = 0;
  v50 = 9;
  IntArray = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_BREAD_COALMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v50) = *IntArray;
  v49 = 24;
  v2 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_MEAT_COALMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v49) = *v2;
  v48 = 11;
  v3 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_FISH_COALMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v48) = *v3;
  v47 = 17;
  std::map<int,std::map<int,int>>::operator[](&v47);
  std::map<int,int>::operator=(v26);
  v56 = -1;
  std::map<int,int>::~map<int,int>(v26);
  std::map<int,int>::map<int,int>(v25);
  v56 = 1;
  v46 = 9;
  v4 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_BREAD_IRONMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v46) = *v4;
  v45 = 24;
  v5 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_MEAT_IRONMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v45) = *v5;
  v44 = 11;
  v6 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_FISH_IRONMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v44) = *v6;
  v43 = 15;
  std::map<int,std::map<int,int>>::operator[](&v43);
  std::map<int,int>::operator=(v25);
  v56 = -1;
  std::map<int,int>::~map<int,int>(v25);
  std::map<int,int>::map<int,int>(v24);
  v56 = 2;
  v42 = 9;
  v7 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_BREAD_GOLDMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v42) = *v7;
  v41 = 24;
  v8 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_MEAT_GOLDMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v41) = *v8;
  v40 = 11;
  v9 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_FISH_GOLDMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v40) = *v9;
  v39 = 16;
  std::map<int,std::map<int,int>>::operator[](&v39);
  std::map<int,int>::operator=(v24);
  v56 = -1;
  std::map<int,int>::~map<int,int>(v24);
  std::map<int,int>::map<int,int>(v23);
  v56 = 3;
  v38 = 9;
  v10 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_BREAD_STONEMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v38) = *v10;
  v37 = 24;
  v11 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_MEAT_STONEMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v37) = *v11;
  v36 = 11;
  v12 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_FISH_STONEMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v36) = *v12;
  v21 = 14;
  std::map<int,std::map<int,int>>::operator[](&v21);
  std::map<int,int>::operator=(v23);
  v56 = -1;
  std::map<int,int>::~map<int,int>(v23);
  std::map<int,int>::map<int,int>(v22);
  v56 = 4;
  v35 = 9;
  v13 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_BREAD_SULFURMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v35) = *v13;
  v34 = 24;
  v14 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_MEAT_SULFURMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v34) = *v14;
  v33 = 11;
  v15 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_FISH_SULFURMINE);
  *(_DWORD *)std::map<int,int>::operator[](&v33) = *v15;
  v32 = 18;
  std::map<int,std::map<int,int>>::operator[](&v32);
  std::map<int,int>::operator=(v22);
  v56 = -1;
  std::map<int,int>::~map<int,int>(v22);
  std::map<int,int>::map<int,int>(v20);
  v56 = 5;
  v31 = 16;
  v16 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_GRAIN_MILL);
  *(_DWORD *)std::map<int,int>::operator[](&v31) = *v16;
  v30 = 9;
  std::map<int,std::map<int,int>>::operator[](&v30);
  std::map<int,int>::operator=(v20);
  v56 = -1;
  std::map<int,int>::~map<int,int>(v20);
  std::map<int,int>::map<int,int>(v19);
  v56 = 6;
  v29 = 20;
  v17 = (_DWORD *)TStaticConfigIntArrayBase<6>::GetIntArray(&CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_VEHICLEHALL);
  *(_DWORD *)std::map<int,int>::operator[](&v29) = *v17;
  v28 = 23;
  std::map<int,std::map<int,int>>::operator[](&v28);
  std::map<int,int>::operator=(v19);
  v56 = -1;
  std::map<int,int>::~map<int,int>(v19);
  CGoodDistributionInfo::CGoodDistributionInfo((CGoodDistributionInfo *)v54);
  NumberOfSupplyBuildings = CBuildingSupplyPriority::GetNumberOfSupplyBuildings(v53, 9, v55);
  v51 = 0;
  for ( i = 0; i < NumberOfSupplyBuildings; ++i )
    v51 += *(_DWORD *)&v55[8 * i + 4];
  if ( v51 != 100 && BBSupportDbgReport(2, "Logic\\BuildingSupplyPriority.cpp", 299, "Result == 100") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x3efe5e0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_COAL_WEAPONSMITH]

// address=[0x3efe600]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_COAL_TOOLSMITH]

// address=[0x3efe620]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_COAL_IRONMELT]

// address=[0x3efe640]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_COAL_GOLDMELT]

// address=[0x3efe660]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_COAL_AMMOMAKERHUT]

// address=[0x3efe680]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_WEAPONSMITH]

// address=[0x3efe6a0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_TOOLSMITH]

// address=[0x3efe6c0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_SHIPYARD]

// address=[0x3efe6e0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_IRONBAR_VEHICLEHALL]

// address=[0x3efe700]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_LOG_AMMOMAKERHUT]

// address=[0x3efe720]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_LOG_CHARCOALMAKER]

// address=[0x3efe740]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_LOG_SAWMILL]

// address=[0x3efe760]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_GRAIN_ANIMALRANCH]

// address=[0x3efe780]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_GRAIN_DONKEYFARM]

// address=[0x3efe7a0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_GRAIN_MILL]

// address=[0x3efe7c0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_WATER_BAKERY]

// address=[0x3efe7e0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_WATER_ANIMALFARM]

// address=[0x3efe800]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_WATER_DONKEYFARM]

// address=[0x3efe820]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_WATER_MEADMAKERHUT]

// address=[0x3efe840]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_WATER_TEQUILAMAKERHUT]

// address=[0x3efe860]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_BREAD_COALMINE]

// address=[0x3efe880]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_BREAD_GOLDMINE]

// address=[0x3efe8a0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_BREAD_IRONMINE]

// address=[0x3efe8c0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_BREAD_SULFURMINE]

// address=[0x3efe8e0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_BREAD_STONEMINE]

// address=[0x3efe900]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_MEAT_COALMINE]

// address=[0x3efe920]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_MEAT_GOLDMINE]

// address=[0x3efe940]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_MEAT_IRONMINE]

// address=[0x3efe960]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_MEAT_SULFURMINE]

// address=[0x3efe980]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_MEAT_STONEMINE]

// address=[0x3efe9a0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_FISH_COALMINE]

// address=[0x3efe9c0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_FISH_GOLDMINE]

// address=[0x3efe9e0]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_FISH_IRONMINE]

// address=[0x3efea00]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_FISH_SULFURMINE]

// address=[0x3efea20]
// [Decompilation failed for static class TStaticConfigIntArray<6> CBuildingSupplyPriority::m_iDefault_SP_FISH_STONEMINE]

