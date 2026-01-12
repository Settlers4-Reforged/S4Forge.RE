#include "CPlayerTradeInfo.h"

// Definitions for class CPlayerTradeInfo

// address=[0x1461000]
// Decompiled from char __thiscall CInternationalTrader::CPlayerTradeInfo::TradeWithSomeone(CInternationalTrader::CPlayerTradeInfo *this)
bool  CInternationalTrader::CPlayerTradeInfo::TradeWithSomeone(void) {
  
  int i; // [esp+4h] [ebp-8h]
  char v3; // [esp+Bh] [ebp-1h]

  v3 = 0;
  for ( i = 0; i < 9; ++i )
    v3 |= *((_BYTE *)this + i + 28);
  return v3;
}


// address=[0x1461050]
// Decompiled from int __thiscall CInternationalTrader::CPlayerTradeInfo::AddBuilding(  CInternationalTrader::CPlayerTradeInfo *this,  struct CBuilding *a2)
void  CInternationalTrader::CPlayerTradeInfo::AddBuilding(class CBuilding *) {
  
  int result; // eax
  _DWORD v4[88]; // [esp+4h] [ebp-2C4h] BYREF
  _DWORD v5[88]; // [esp+164h] [ebp-164h] BYREF

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 591, "pTradeBuilding!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a2 )
    return result;
  *((_DWORD *)this + 6) = IEntity::OwnerId((unsigned __int8 *)a2);
  if ( IEntity::Type((unsigned __int16 *)a2) == 32 )
  {
    CInternationalTrader::CTradeBuildingInfo::CTradeBuildingInfo((CInternationalTrader::CTradeBuildingInfo *)v5);
    v5[0] = IEntity::ID();
    v5[1] = 32;
    return std::list<CInternationalTrader::CTradeBuildingInfo>::push_back(v5);
  }
  else
  {
    result = IEntity::Type((unsigned __int16 *)a2);
    if ( result == 33 )
    {
      CInternationalTrader::CTradeBuildingInfo::CTradeBuildingInfo((CInternationalTrader::CTradeBuildingInfo *)v4);
      v4[0] = IEntity::ID();
      v4[1] = 33;
      return std::list<CInternationalTrader::CTradeBuildingInfo>::push_back(v4);
    }
  }
  return result;
}


// address=[0x1461150]
// Decompiled from int __thiscall CInternationalTrader::CPlayerTradeInfo::RemoveBuilding(  CInternationalTrader::CPlayerTradeInfo *this,  struct CBuilding *a2)
void  CInternationalTrader::CPlayerTradeInfo::RemoveBuilding(class CBuilding *) {
  
  int result; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // esi
  char v5; // [esp-Ch] [ebp-B0h] BYREF
  int v6; // [esp-8h] [ebp-ACh]
  int v7; // [esp-4h] [ebp-A8h]
  _BYTE v8[12]; // [esp+8h] [ebp-9Ch] BYREF
  _BYTE v9[12]; // [esp+14h] [ebp-90h] BYREF
  _BYTE v10[12]; // [esp+20h] [ebp-84h] BYREF
  _BYTE v11[12]; // [esp+2Ch] [ebp-78h] BYREF
  _BYTE v12[12]; // [esp+38h] [ebp-6Ch] BYREF
  _BYTE v13[12]; // [esp+44h] [ebp-60h] BYREF
  int v14; // [esp+50h] [ebp-54h]
  int v15; // [esp+54h] [ebp-50h]
  char *v16; // [esp+58h] [ebp-4Ch]
  int v17; // [esp+5Ch] [ebp-48h]
  int v18; // [esp+60h] [ebp-44h]
  char *v19; // [esp+64h] [ebp-40h]
  std::_Iterator_base12 *v20; // [esp+68h] [ebp-3Ch]
  std::_Iterator_base12 *v21; // [esp+6Ch] [ebp-38h]
  std::_Iterator_base12 *v22; // [esp+70h] [ebp-34h]
  std::_Iterator_base12 *v23; // [esp+74h] [ebp-30h]
  _BYTE v24[12]; // [esp+78h] [ebp-2Ch] BYREF
  _BYTE v25[12]; // [esp+84h] [ebp-20h] BYREF
  CInternationalTrader::CPlayerTradeInfo *v26; // [esp+90h] [ebp-14h]
  char v27; // [esp+96h] [ebp-Eh]
  char v28; // [esp+97h] [ebp-Dh]
  int v29; // [esp+A0h] [ebp-4h]

  v26 = this;
  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 616, "pBuilding!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a2 )
    return result;
  if ( IEntity::Type((unsigned __int16 *)a2) == 32 )
  {
    std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v25);
    v29 = 0;
    while ( 1 )
    {
      v23 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v12);
      v22 = v23;
      LOBYTE(v29) = 1;
      v28 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v23);
      LOBYTE(v29) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v12);
      if ( !v28 )
        break;
      v3 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v25);
      if ( *v3 == IEntity::ID() )
      {
        v19 = &v5;
        v18 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v25);
        v17 = std::list<CInternationalTrader::CTradeBuildingInfo>::erase(v11, v5, v6, v7);
        std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v11);
        v29 = -1;
        return std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v25);
      }
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
        v13,
        0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v13);
    }
    v29 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v25);
  }
  result = IEntity::Type((unsigned __int16 *)a2);
  if ( result != 33 )
    return result;
  std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v24);
  v29 = 2;
  while ( 1 )
  {
    v21 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v9);
    v20 = v21;
    LOBYTE(v29) = 3;
    v27 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v21);
    LOBYTE(v29) = 2;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v9);
    if ( !v27 )
      break;
    v4 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v24);
    if ( *v4 == IEntity::ID() )
    {
      v16 = &v5;
      v15 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v24);
      v14 = std::list<CInternationalTrader::CTradeBuildingInfo>::erase(v8, v5, v6, v7);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v8);
      v29 = -1;
      return std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v24);
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
      v10,
      0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v10);
  }
  v29 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v24);
}


// address=[0x14613a0]
// Decompiled from struct CInternationalTrader::CTradeBuildingInfo *__thiscall CInternationalTrader::CPlayerTradeInfo::SetGoodStatus(  CInternationalTrader::CPlayerTradeInfo *this,  struct CBuilding *a2,  int a3,  int a4)
void  CInternationalTrader::CPlayerTradeInfo::SetGoodStatus(class CBuilding *,enum PILE_TYPES,enum TGOOD_STATUS) {
  
  struct CInternationalTrader::CTradeBuildingInfo *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 650, "_pAtBuilding!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a2 )
    return result;
  result = CInternationalTrader::CPlayerTradeInfo::GetBuildingInfo(this, a2);
  if ( !result )
    return result;
  *((_DWORD *)result + 2 * a3 + 2) = a3;
  *((_DWORD *)result + 2 * a3 + 3) = a4;
  return result;
}


// address=[0x1461410]
// Decompiled from int __thiscall CInternationalTrader::CPlayerTradeInfo::GetGoodStatus(  CInternationalTrader::CPlayerTradeInfo *this,  struct CBuilding *a2,  int a3)
enum TGOOD_STATUS  CInternationalTrader::CPlayerTradeInfo::GetGoodStatus(class CBuilding *,enum PILE_TYPES) {
  
  struct CInternationalTrader::CTradeBuildingInfo *BuildingInfo; // [esp+4h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 663, "_pBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  BuildingInfo = CInternationalTrader::CPlayerTradeInfo::GetBuildingInfo(this, a2);
  if ( !BuildingInfo && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 667, "pBuildingInfo!=NULL") == 1 )
    __debugbreak();
  if ( BuildingInfo )
    return *((_DWORD *)BuildingInfo + 2 * a3 + 3);
  else
    return 0;
}


// address=[0x14614a0]
// Decompiled from int __thiscall CInternationalTrader::CPlayerTradeInfo::GetBuildingInfo(  CInternationalTrader::CPlayerTradeInfo *this,  struct CBuilding *a2)
class CInternationalTrader::CTradeBuildingInfo *  CInternationalTrader::CPlayerTradeInfo::GetBuildingInfo(class CBuilding *) {
  
  _DWORD *v3; // esi
  _DWORD *v4; // esi
  _BYTE v5[12]; // [esp+8h] [ebp-78h] BYREF
  _BYTE v6[12]; // [esp+14h] [ebp-6Ch] BYREF
  _BYTE v7[12]; // [esp+20h] [ebp-60h] BYREF
  _BYTE v8[12]; // [esp+2Ch] [ebp-54h] BYREF
  _BYTE v9[12]; // [esp+38h] [ebp-48h] BYREF
  _BYTE v10[12]; // [esp+44h] [ebp-3Ch] BYREF
  int v11; // [esp+50h] [ebp-30h]
  std::_Iterator_base12 *v12; // [esp+54h] [ebp-2Ch]
  std::_Iterator_base12 *v13; // [esp+58h] [ebp-28h]
  int v14; // [esp+5Ch] [ebp-24h]
  std::_Iterator_base12 *v15; // [esp+60h] [ebp-20h]
  std::_Iterator_base12 *v16; // [esp+64h] [ebp-1Ch]
  int v17; // [esp+68h] [ebp-18h]
  CInternationalTrader::CPlayerTradeInfo *v18; // [esp+6Ch] [ebp-14h]
  char v19; // [esp+72h] [ebp-Eh]
  char v20; // [esp+73h] [ebp-Dh]
  int v21; // [esp+7Ch] [ebp-4h]

  v18 = this;
  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 678, "_pBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  v17 = IEntity::Type((unsigned __int16 *)a2);
  if ( v17 == 32 )
  {
    std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v10);
    v21 = 0;
    while ( 1 )
    {
      v16 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v7);
      v15 = v16;
      LOBYTE(v21) = 1;
      v20 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v16);
      LOBYTE(v21) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v7);
      if ( !v20 )
        break;
      v3 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v10);
      if ( *v3 == IEntity::ID() )
      {
        v14 = std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v10);
        v21 = -1;
        std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v10);
        return v14;
      }
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
        v8,
        0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v8);
    }
    v21 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v10);
  }
  if ( v17 != 33 )
    return 0;
  std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v9);
  v21 = 2;
  while ( 1 )
  {
    v13 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v5);
    v12 = v13;
    LOBYTE(v21) = 3;
    v19 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v13);
    LOBYTE(v21) = 2;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v5);
    if ( !v19 )
      break;
    v4 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v9);
    if ( *v4 == IEntity::ID() )
    {
      v11 = std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v9);
      v21 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v9);
      return v11;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
      v6,
      0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v6);
  }
  v21 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v9);
  return 0;
}


// address=[0x14616a0]
// Decompiled from int __thiscall CInternationalTrader::CPlayerTradeInfo::GetExportListForBuilding(  CInternationalTrader::CPlayerTradeInfo *this,  int a2,  struct CBuilding *a3)
class std::vector<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo,class std::allocator<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo> >  CInternationalTrader::CPlayerTradeInfo::GetExportListForBuilding(class CBuilding *) {
  
  _BYTE v4[16]; // [esp+4h] [ebp-34h] BYREF
  _DWORD v5[2]; // [esp+14h] [ebp-24h] BYREF
  CInternationalTrader::CPlayerTradeInfo *v6; // [esp+1Ch] [ebp-1Ch]
  int v7; // [esp+20h] [ebp-18h]
  struct CInternationalTrader::CTradeBuildingInfo *BuildingInfo; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  int v10; // [esp+34h] [ebp-4h]

  v6 = this;
  v7 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  v10 = 0;
  BuildingInfo = CInternationalTrader::CPlayerTradeInfo::GetBuildingInfo(v6, a3);
  if ( !BuildingInfo && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 715, "pBuildingInfo!= NULL") == 1 )
    __debugbreak();
  if ( BuildingInfo )
  {
    for ( i = 0; i < 43; ++i )
    {
      if ( *((_DWORD *)BuildingInfo + 2 * i + 3) == 8 )
      {
        v5[1] = *((_DWORD *)BuildingInfo + 2 * i + 2);
        v5[0] = *(_DWORD *)BuildingInfo;
        std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::push_back(v5);
      }
    }
  }
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>(v4);
  v7 |= 1u;
  v10 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return a2;
}


// address=[0x14617d0]
// Decompiled from int __thiscall CInternationalTrader::CPlayerTradeInfo::GetExportList(void *this, int a2, int a3)
class std::vector<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo,class std::allocator<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo> >  CInternationalTrader::CPlayerTradeInfo::GetExportList(enum BUILDING_TYPES) {
  
  _BYTE v4[12]; // [esp+4h] [ebp-A0h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-94h] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-88h] BYREF
  _BYTE v7[12]; // [esp+28h] [ebp-7Ch] BYREF
  _BYTE v8[16]; // [esp+34h] [ebp-70h] BYREF
  _DWORD v9[2]; // [esp+44h] [ebp-60h] BYREF
  _DWORD v10[2]; // [esp+4Ch] [ebp-58h] BYREF
  _BYTE v11[12]; // [esp+54h] [ebp-50h] BYREF
  _BYTE v12[12]; // [esp+60h] [ebp-44h] BYREF
  std::_Iterator_base12 *v13; // [esp+6Ch] [ebp-38h]
  std::_Iterator_base12 *v14; // [esp+70h] [ebp-34h]
  std::_Iterator_base12 *v15; // [esp+74h] [ebp-30h]
  std::_Iterator_base12 *v16; // [esp+78h] [ebp-2Ch]
  int v17; // [esp+7Ch] [ebp-28h]
  _DWORD *v18; // [esp+80h] [ebp-24h]
  _DWORD *v19; // [esp+84h] [ebp-20h]
  void *v20; // [esp+88h] [ebp-1Ch]
  int j; // [esp+8Ch] [ebp-18h]
  int i; // [esp+90h] [ebp-14h]
  char v23; // [esp+96h] [ebp-Eh]
  char v24; // [esp+97h] [ebp-Dh]
  int v25; // [esp+A0h] [ebp-4h]

  v20 = this;
  v17 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  v25 = 0;
  if ( a3 == 32 )
  {
    std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v12);
    LOBYTE(v25) = 1;
    while ( 1 )
    {
      v16 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v6);
      v15 = v16;
      LOBYTE(v25) = 2;
      v24 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v16);
      LOBYTE(v25) = 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v6);
      if ( !v24 )
        break;
      v19 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v12);
      for ( i = 0; i < 43; ++i )
      {
        if ( v19[2 * i + 3] == 8 )
        {
          v10[1] = i;
          v10[0] = *v19;
          std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::push_back(v10);
        }
      }
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
        v7,
        0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v7);
    }
    LOBYTE(v25) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v12);
  }
  if ( a3 == 33 )
  {
    std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v11);
    LOBYTE(v25) = 3;
    while ( 1 )
    {
      v14 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v4);
      v13 = v14;
      LOBYTE(v25) = 4;
      v23 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v14);
      LOBYTE(v25) = 3;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v4);
      if ( !v23 )
        break;
      v18 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v11);
      for ( j = 0; j < 43; ++j )
      {
        if ( v18[2 * j + 3] == 8 )
        {
          v9[1] = j;
          v9[0] = *v18;
          std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::push_back(v9);
        }
      }
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
        v5,
        0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v5);
    }
    LOBYTE(v25) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v11);
  }
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>(v8);
  v17 |= 1u;
  v25 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return a2;
}


// address=[0x1461a00]
// Decompiled from int __thiscall CInternationalTrader::CPlayerTradeInfo::GetImportList(void *this, int a2, int a3)
class std::vector<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo,class std::allocator<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo> >  CInternationalTrader::CPlayerTradeInfo::GetImportList(enum BUILDING_TYPES) {
  
  _BYTE v4[12]; // [esp+4h] [ebp-A0h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-94h] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-88h] BYREF
  _BYTE v7[12]; // [esp+28h] [ebp-7Ch] BYREF
  _BYTE v8[16]; // [esp+34h] [ebp-70h] BYREF
  _DWORD v9[2]; // [esp+44h] [ebp-60h] BYREF
  _DWORD v10[2]; // [esp+4Ch] [ebp-58h] BYREF
  _BYTE v11[12]; // [esp+54h] [ebp-50h] BYREF
  _BYTE v12[12]; // [esp+60h] [ebp-44h] BYREF
  std::_Iterator_base12 *v13; // [esp+6Ch] [ebp-38h]
  std::_Iterator_base12 *v14; // [esp+70h] [ebp-34h]
  std::_Iterator_base12 *v15; // [esp+74h] [ebp-30h]
  std::_Iterator_base12 *v16; // [esp+78h] [ebp-2Ch]
  int v17; // [esp+7Ch] [ebp-28h]
  _DWORD *v18; // [esp+80h] [ebp-24h]
  _DWORD *v19; // [esp+84h] [ebp-20h]
  void *v20; // [esp+88h] [ebp-1Ch]
  int j; // [esp+8Ch] [ebp-18h]
  int i; // [esp+90h] [ebp-14h]
  char v23; // [esp+96h] [ebp-Eh]
  char v24; // [esp+97h] [ebp-Dh]
  int v25; // [esp+A0h] [ebp-4h]

  v20 = this;
  v17 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  v25 = 0;
  if ( a3 == 32 )
  {
    std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v12);
    LOBYTE(v25) = 1;
    while ( 1 )
    {
      v16 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v6);
      v15 = v16;
      LOBYTE(v25) = 2;
      v24 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v16);
      LOBYTE(v25) = 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v6);
      if ( !v24 )
        break;
      v19 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v12);
      for ( i = 0; i < 43; ++i )
      {
        if ( v19[2 * i + 3] == 4 )
        {
          v10[1] = i;
          v10[0] = *v19;
          std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::push_back(v10);
        }
      }
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
        v7,
        0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v7);
    }
    LOBYTE(v25) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v12);
  }
  if ( a3 == 33 )
  {
    std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v11);
    LOBYTE(v25) = 3;
    while ( 1 )
    {
      v14 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v4);
      v13 = v14;
      LOBYTE(v25) = 4;
      v23 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v14);
      LOBYTE(v25) = 3;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v4);
      if ( !v23 )
        break;
      v18 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v11);
      for ( j = 0; j < 43; ++j )
      {
        if ( v18[2 * j + 3] == 4 )
        {
          v9[1] = j;
          v9[0] = *v18;
          std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::push_back(v9);
        }
      }
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
        v5,
        0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v5);
    }
    LOBYTE(v25) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v11);
  }
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>(v8);
  v17 |= 1u;
  v25 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return a2;
}


// address=[0x1461c30]
// Decompiled from char __thiscall CInternationalTrader::CPlayerTradeInfo::ImportGood(void *this, int a2, int a3)
bool  CInternationalTrader::CPlayerTradeInfo::ImportGood(enum PILE_TYPES,enum BUILDING_TYPES) {
  
  _BYTE v4[16]; // [esp+4h] [ebp-50h] BYREF
  _BYTE v5[12]; // [esp+14h] [ebp-40h] BYREF
  _BYTE v6[12]; // [esp+20h] [ebp-34h] BYREF
  _BYTE v7[12]; // [esp+2Ch] [ebp-28h] BYREF
  std::_Iterator_base12 *v8; // [esp+38h] [ebp-1Ch]
  std::_Iterator_base12 *v9; // [esp+3Ch] [ebp-18h]
  void *v10; // [esp+40h] [ebp-14h]
  char v11; // [esp+45h] [ebp-Fh]
  char v12; // [esp+46h] [ebp-Eh]
  char v13; // [esp+47h] [ebp-Dh]
  int v14; // [esp+50h] [ebp-4h]

  v10 = this;
  CInternationalTrader::CPlayerTradeInfo::GetImportList(this, (int)v4, a3);
  v14 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::begin(v7);
  LOBYTE(v14) = 1;
  while ( 1 )
  {
    v9 = (std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::end(v5);
    v8 = v9;
    LOBYTE(v14) = 2;
    v13 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator!=(v9);
    LOBYTE(v14) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v5);
    if ( !v13 )
      break;
    if ( *(_DWORD *)(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v7)
                   + 4) == a2 )
    {
      v12 = 1;
      LOBYTE(v14) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v7);
      v14 = -1;
      std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
      return v12;
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator++(
      v6,
      0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v6);
  }
  LOBYTE(v14) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v7);
  v11 = 0;
  v14 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return v11;
}


// address=[0x1461d40]
// Decompiled from char __thiscall CInternationalTrader::CPlayerTradeInfo::ImportGoodAtBuilding(void *this, _DWORD *a2, int a3, int a4)
bool  CInternationalTrader::CPlayerTradeInfo::ImportGoodAtBuilding(int &,enum PILE_TYPES,enum BUILDING_TYPES) {
  
  _BYTE v5[16]; // [esp+4h] [ebp-50h] BYREF
  _BYTE v6[12]; // [esp+14h] [ebp-40h] BYREF
  _BYTE v7[12]; // [esp+20h] [ebp-34h] BYREF
  _BYTE v8[12]; // [esp+2Ch] [ebp-28h] BYREF
  std::_Iterator_base12 *v9; // [esp+38h] [ebp-1Ch]
  std::_Iterator_base12 *v10; // [esp+3Ch] [ebp-18h]
  void *v11; // [esp+40h] [ebp-14h]
  char v12; // [esp+45h] [ebp-Fh]
  char v13; // [esp+46h] [ebp-Eh]
  char v14; // [esp+47h] [ebp-Dh]
  int v15; // [esp+50h] [ebp-4h]

  v11 = this;
  CInternationalTrader::CPlayerTradeInfo::GetImportList(this, (int)v5, a4);
  v15 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::begin(v8);
  LOBYTE(v15) = 1;
  while ( 1 )
  {
    v10 = (std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::end(v6);
    v9 = v10;
    LOBYTE(v15) = 2;
    v14 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator!=(v10);
    LOBYTE(v15) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v6);
    if ( !v14 )
      break;
    if ( *(_DWORD *)(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v8)
                   + 4) == a3 )
    {
      *a2 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v8);
      v13 = 1;
      LOBYTE(v15) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v8);
      v15 = -1;
      std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
      return v13;
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator++(
      v7,
      0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v7);
  }
  LOBYTE(v15) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v8);
  v12 = 0;
  v15 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return v12;
}


// address=[0x1465d20]
// Decompiled from CInternationalTrader::CPlayerTradeInfo *__thiscall CInternationalTrader::CPlayerTradeInfo::CPlayerTradeInfo(  CInternationalTrader::CPlayerTradeInfo *this)
 CInternationalTrader::CPlayerTradeInfo::CPlayerTradeInfo(void) {
  
  std::list<CInternationalTrader::CTradeBuildingInfo>::list<CInternationalTrader::CTradeBuildingInfo>(this);
  std::list<CInternationalTrader::CTradeBuildingInfo>::list<CInternationalTrader::CTradeBuildingInfo>((char *)this + 12);
  *((_DWORD *)this + 6) = -1;
  memset((char *)this + 28, 0, 9u);
  return this;
}


// address=[0x1466c10]
// Decompiled from int __thiscall CInternationalTrader::CPlayerTradeInfo::GetPlayerID(CInternationalTrader::CPlayerTradeInfo *this)
int  CInternationalTrader::CPlayerTradeInfo::GetPlayerID(void) {
  
  return *((_DWORD *)this + 6);
}


// address=[0x1466c30]
// Decompiled from char __thiscall CInternationalTrader::CPlayerTradeInfo::GetPlayerTradeStatus(  CInternationalTrader::CPlayerTradeInfo *this,  int a2)
bool  CInternationalTrader::CPlayerTradeInfo::GetPlayerTradeStatus(int) {
  
  return *((_BYTE *)this + a2 + 28);
}


// address=[0x1466c50]
// Decompiled from CInternationalTrader::CPlayerTradeInfo *__thiscall CInternationalTrader::CPlayerTradeInfo::SetPlayerID(  CInternationalTrader::CPlayerTradeInfo *this,  int a2)
void  CInternationalTrader::CPlayerTradeInfo::SetPlayerID(int) {
  
  CInternationalTrader::CPlayerTradeInfo *result; // eax

  if ( (a2 < 0 || a2 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\InternationalTrader.h",
         105,
         "_iPlayerID>=0 && _iPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 6) != -1
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\InternationalTrader.h",
         106,
         "m_iPlayerID== -1") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_DWORD *)this + 6) = a2;
  return result;
}


// address=[0x1466ce0]
// Decompiled from char *__thiscall CInternationalTrader::CPlayerTradeInfo::SetPlayerTradeStatus(  CInternationalTrader::CPlayerTradeInfo *this,  int a2,  bool a3)
void  CInternationalTrader::CPlayerTradeInfo::SetPlayerTradeStatus(int,bool) {
  
  char *result; // eax

  result = (char *)this + a2;
  *((_BYTE *)this + a2 + 28) = a3;
  return result;
}


// address=[0x1466d00]
// Decompiled from bool __thiscall CInternationalTrader::CPlayerTradeInfo::SwitchPlayerTradeStatus(  CInternationalTrader::CPlayerTradeInfo *this,  int a2)
void  CInternationalTrader::CPlayerTradeInfo::SwitchPlayerTradeStatus(int) {
  
  bool result; // al

  result = *((_BYTE *)this + a2 + 28) == 0;
  *((_BYTE *)this + a2 + 28) = result;
  return result;
}


// address=[0x1466d50]
// Decompiled from char __thiscall CInternationalTrader::CPlayerTradeInfo::TradeWithPlayer(  CInternationalTrader::CPlayerTradeInfo *this,  int a2)
bool  CInternationalTrader::CPlayerTradeInfo::TradeWithPlayer(int) {
  
  return *((_BYTE *)this + a2 + 28);
}


