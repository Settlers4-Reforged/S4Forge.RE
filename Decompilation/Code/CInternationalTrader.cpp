#include "CInternationalTrader.h"

// Definitions for class CInternationalTrader

// address=[0x1461e60]
// Decompiled from CInternationalTrader *__thiscall CInternationalTrader::CInternationalTrader(CInternationalTrader *this)

 CInternationalTrader::CInternationalTrader(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CInternationalTrader::_vftable_;
  *((_DWORD *)this + 2) = 1;
  CInternationalTrader::InitPlayerList();
  *((_DWORD *)this + 1) = -1;
  return this;
}


// address=[0x1461ea0]
// Decompiled from CInternationalTrader *__thiscall CInternationalTrader::~CInternationalTrader(CInternationalTrader *this)

 CInternationalTrader::~CInternationalTrader(void) {
  
  CInternationalTrader *result; // eax

  result = this;
  *(_DWORD *)this = CInternationalTrader::_vftable_;
  return result;
}


// address=[0x1461ec0]
// Decompiled from int __thiscall CInternationalTrader::Load(CInternationalTrader *this, struct IS4Chunk *a2)

void  CInternationalTrader::Load(class IS4Chunk &) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-2E0h] BYREF
  int v4; // [esp+8h] [ebp-2DCh] BYREF
  int v5; // [esp+Ch] [ebp-2D8h]
  int k; // [esp+10h] [ebp-2D4h]
  int j; // [esp+14h] [ebp-2D0h]
  int v8; // [esp+18h] [ebp-2CCh] BYREF
  int i; // [esp+1Ch] [ebp-2C8h]
  _BYTE v10[352]; // [esp+20h] [ebp-2C4h] BYREF
  _BYTE v11[352]; // [esp+180h] [ebp-164h] BYREF

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 762231707);
  result = (**(int (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v4, 4);
  if ( v4 != 1 )
    return result;
  result = (**(int (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v3, 4);
  for ( i = 0; i < v3; ++i )
  {
    v5 = *(_DWORD *)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](i);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, v5 + 28, 9);
    v8 = 0;
    (**(void (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v8, 4);
    for ( j = 0; j < v8; ++j )
    {
      CInternationalTrader::CTradeBuildingInfo::CTradeBuildingInfo((CInternationalTrader::CTradeBuildingInfo *)v11);
      (**(void (__thiscall ***)(struct IS4Chunk *, _BYTE *, int))a2)(a2, v11, 352);
      std::list<CInternationalTrader::CTradeBuildingInfo>::push_back(v11);
    }
    result = (**(int (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v8, 4);
    for ( k = 0; k < v8; ++k )
    {
      CInternationalTrader::CTradeBuildingInfo::CTradeBuildingInfo((CInternationalTrader::CTradeBuildingInfo *)v10);
      (**(void (__thiscall ***)(struct IS4Chunk *, _BYTE *, int))a2)(a2, v10, 352);
      result = std::list<CInternationalTrader::CTradeBuildingInfo>::push_back(v10);
    }
  }
  CInternationalTrader::m_bInit = 1;
  return result;
}


// address=[0x14620a0]
// Decompiled from int __thiscall CInternationalTrader::Save(CInternationalTrader *this, struct IS4Chunk *a2)

void  CInternationalTrader::Save(class IS4Chunk &) {
  
  int result; // eax
  _BYTE v3[12]; // [esp+4h] [ebp-88h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-7Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-70h] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-64h] BYREF
  _BYTE v7[12]; // [esp+34h] [ebp-58h] BYREF
  _BYTE v8[12]; // [esp+40h] [ebp-4Ch] BYREF
  int v9; // [esp+4Ch] [ebp-40h]
  std::_Iterator_base12 *v10; // [esp+50h] [ebp-3Ch]
  std::_Iterator_base12 *v11; // [esp+54h] [ebp-38h]
  int v12; // [esp+58h] [ebp-34h]
  std::_Iterator_base12 *v13; // [esp+5Ch] [ebp-30h]
  std::_Iterator_base12 *v14; // [esp+60h] [ebp-2Ch]
  _DWORD v15[2]; // [esp+64h] [ebp-28h] BYREF
  int v16; // [esp+6Ch] [ebp-20h] BYREF
  int v17; // [esp+70h] [ebp-1Ch] BYREF
  int i; // [esp+74h] [ebp-18h]
  int v19; // [esp+78h] [ebp-14h]
  char v20; // [esp+7Eh] [ebp-Eh]
  char v21; // [esp+7Fh] [ebp-Dh]
  int v22; // [esp+88h] [ebp-4h]

  v15[1] = this;
  v15[0] = *((_DWORD *)this + 2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 762231707);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD *, int))(*(_DWORD *)a2 + 16))(a2, v15, 4);
  v16 = std::vector<CInternationalTrader::CPlayerTradeInfo *>::size(&CInternationalTrader::m_sPlayerList);
  result = (*(int (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v16, 4);
  for ( i = 0; i < v16; ++i )
  {
    v19 = *(_DWORD *)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](i);
    (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, v19 + 28, 9);
    v17 = std::list<CInternationalTrader::CTradeBuildingInfo>::size(v19);
    (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v17, 4);
    std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v8);
    v22 = 0;
    while ( 1 )
    {
      v14 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v5);
      v13 = v14;
      LOBYTE(v22) = 1;
      v21 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v14);
      LOBYTE(v22) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v5);
      if ( !v21 )
        break;
      v12 = std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v8);
      (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, v12, 352);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
        v6,
        0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v6);
    }
    v22 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v8);
    v17 = std::list<CInternationalTrader::CTradeBuildingInfo>::size(v19 + 12);
    (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v17, 4);
    std::list<CInternationalTrader::CTradeBuildingInfo>::begin(v7);
    v22 = 2;
    while ( 1 )
    {
      v11 = (std::_Iterator_base12 *)std::list<CInternationalTrader::CTradeBuildingInfo>::end(v3);
      v10 = v11;
      LOBYTE(v22) = 3;
      v20 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator!=(v11);
      LOBYTE(v22) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v3);
      if ( !v20 )
        break;
      v9 = std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator*(v7);
      (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, v9, 352);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::operator++(
        v4,
        0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v4);
    }
    v22 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CInternationalTrader::CTradeBuildingInfo>>>(v7);
    result = i + 1;
  }
  return result;
}


// address=[0x14622f0]
// Decompiled from int CInternationalTrader::ReInit()

static void __cdecl CInternationalTrader::ReInit(void) {
  
  int result; // eax
  _DWORD v1[3]; // [esp-18h] [ebp-74h] BYREF
  char v2; // [esp-Ch] [ebp-68h] BYREF
  int v3; // [esp-8h] [ebp-64h]
  int v4; // [esp-4h] [ebp-60h]
  _BYTE v5[12]; // [esp+4h] [ebp-58h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-4Ch] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-40h] BYREF
  int v8; // [esp+28h] [ebp-34h]
  int v9; // [esp+2Ch] [ebp-30h]
  _DWORD *v10; // [esp+30h] [ebp-2Ch]
  int v11; // [esp+34h] [ebp-28h]
  char *v12; // [esp+38h] [ebp-24h]
  struct std::_Iterator_base12 *v13; // [esp+3Ch] [ebp-20h]
  struct std::_Iterator_base12 *v14; // [esp+40h] [ebp-1Ch]
  int v15; // [esp+44h] [ebp-18h]
  struct std::_Iterator_base12 *v16; // [esp+48h] [ebp-14h]
  struct std::_Iterator_base12 *v17; // [esp+4Ch] [ebp-10h]
  int v18; // [esp+58h] [ebp-4h]

  if ( !(unsigned __int8)std::vector<CInternationalTrader::CPlayerTradeInfo *>::empty(&CInternationalTrader::m_sPlayerList) )
  {
    v17 = (struct std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo *>::end(v5);
    v16 = v17;
    v18 = 0;
    v12 = &v2;
    v15 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>(v17);
    v11 = v15;
    LOBYTE(v18) = 1;
    v14 = (struct std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo *>::begin(v6);
    v13 = v14;
    LOBYTE(v18) = 2;
    v10 = v1;
    v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>(v14);
    LOBYTE(v18) = 3;
    v8 = std::vector<CInternationalTrader::CPlayerTradeInfo *>::erase(v7, v1[0], v1[1], v1[2], v2, v3, v4);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>(v7);
    LOBYTE(v18) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>(v6);
    v18 = -1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo *>>>(v5);
  }
  result = std::vector<CInternationalTrader::CPlayerTradeInfo *>::empty(&CInternationalTrader::m_sPlayerList);
  if ( !(_BYTE)result )
  {
    result = BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 312, "m_sPlayerList.empty()");
    if ( result == 1 )
      __debugbreak();
  }
  CInternationalTrader::m_bInit = 0;
  return result;
}


// address=[0x1462420]
// Decompiled from char __thiscall CInternationalTrader::Trade(CInternationalTrader *this, struct CBuilding *a2)

bool  CInternationalTrader::Trade(class CBuilding *) {
  
  int *v3; // eax
  int v4; // edx
  unsigned int v5; // eax
  unsigned int v6; // eax
  int PlayerID; // eax
  int v8; // eax
  unsigned int v9; // eax
  _BYTE v10[16]; // [esp+4h] [ebp-74h] BYREF
  _BYTE v11[12]; // [esp+14h] [ebp-64h] BYREF
  _BYTE v12[12]; // [esp+20h] [ebp-58h] BYREF
  _BYTE v13[12]; // [esp+2Ch] [ebp-4Ch] BYREF
  int v14; // [esp+38h] [ebp-40h]
  unsigned int v15; // [esp+3Ch] [ebp-3Ch]
  CTradingBuildingRole *v16; // [esp+40h] [ebp-38h]
  unsigned __int8 *BuildingPtr; // [esp+44h] [ebp-34h]
  std::_Iterator_base12 *v18; // [esp+48h] [ebp-30h]
  std::_Iterator_base12 *v19; // [esp+4Ch] [ebp-2Ch]
  CInternationalTrader::CPlayerTradeInfo *v20; // [esp+50h] [ebp-28h]
  CTradingBuildingRole *v21; // [esp+54h] [ebp-24h]
  unsigned int v22; // [esp+58h] [ebp-20h]
  CInternationalTrader *v23; // [esp+5Ch] [ebp-1Ch]
  CInternationalTrader::CPlayerTradeInfo *v24; // [esp+60h] [ebp-18h]
  unsigned int i; // [esp+64h] [ebp-14h]
  char v26; // [esp+69h] [ebp-Fh]
  char v27; // [esp+6Ah] [ebp-Eh]
  char v28; // [esp+6Bh] [ebp-Dh]
  int v29; // [esp+74h] [ebp-4h]

  v23 = this;
  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 19, "_pBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  if ( *((_DWORD *)v23 + 1) != IEntity::OwnerId((unsigned __int8 *)a2) )
    return 1;
  v21 = (CTradingBuildingRole *)CBuilding::Role(a2);
  v24 = *(CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](*((_DWORD *)v23 + 1));
  if ( !v24 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 31, "pCurrentPlayer!=NULL") == 1 )
    __debugbreak();
  if ( !v24 )
    return 0;
  CInternationalTrader::CPlayerTradeInfo::GetExportListForBuilding(v24, (int)v10, a2);
  v29 = 0;
  if ( !std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::size(v10) )
  {
    v28 = 1;
    v29 = -1;
    std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
    return v28;
  }
  if ( CInternationalTrader::TradeWithSomeone(v23, *((_DWORD *)v23 + 1)) )
  {
    std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::begin(v13);
    LOBYTE(v29) = 1;
    while ( 1 )
    {
      v19 = (std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::end(v11);
      v18 = v19;
      LOBYTE(v29) = 2;
      v27 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator!=(v19);
      LOBYTE(v29) = 1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v11);
      if ( !v27 )
        break;
      v3 = (int *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v13);
      v4 = *v3;
      v5 = v3[1];
      v14 = v4;
      v15 = v5;
      CTradingBuildingRole::RequestTradingGood(v21, v5);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator++(
        v12,
        0);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v12);
    }
    LOBYTE(v29) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v13);
  }
  v22 = 0;
  for ( i = 1; ; ++i )
  {
    v6 = std::vector<CInternationalTrader::CPlayerTradeInfo *>::size(&CInternationalTrader::m_sPlayerList);
    if ( i >= v6 || v22 )
      break;
    PlayerID = CInternationalTrader::CPlayerTradeInfo::GetPlayerID(v24);
    if ( i != PlayerID )
    {
      if ( CInternationalTrader::CPlayerTradeInfo::TradeWithPlayer(v24, i) )
      {
        v20 = *(CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](i);
        v8 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( CInternationalTrader::CPlayerTradeInfo::TradeWithPlayer(v20, v8) )
        {
          v22 = CInternationalTrader::CheckTrade(v23, v24, v20, a2);
          if ( v22 )
          {
            CTradingBuildingRole::SetTradingBuildingID(v21, v22);
            CTradingBuildingRole::RequestVehicle(v21, a2, 1);
            BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v22);
            v16 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
            v9 = IEntity::ID();
            CTradingBuildingRole::SetTradingBuildingID(v16, v9);
            v26 = 1;
            v29 = -1;
            std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
            return v26;
          }
        }
      }
    }
  }
  v29 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return 1;
}


// address=[0x1462700]
// Decompiled from CInternationalTrader::CPlayerTradeInfo **__thiscall CInternationalTrader::AddBuilding(
        CInternationalTrader *this,
        struct CBuilding *a2)

void  CInternationalTrader::AddBuilding(class CBuilding *) {
  
  CInternationalTrader::CPlayerTradeInfo **result; // eax
  CInternationalTrader::CPlayerTradeInfo *v4; // [esp+4h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 438, "_pOwnerBuilding!= NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a2 )
    return result;
  *((_DWORD *)this + 1) = IEntity::OwnerId((unsigned __int8 *)a2);
  result = (CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](*((_DWORD *)this + 1));
  v4 = *result;
  if ( !*result )
  {
    result = (CInternationalTrader::CPlayerTradeInfo **)BBSupportDbgReport(
                                                          2,
                                                          "Logic\\InternationalTrader.cpp",
                                                          443,
                                                          "pPlayerInfo!=NULL");
    if ( result == (CInternationalTrader::CPlayerTradeInfo **)1 )
      __debugbreak();
  }
  if ( v4 )
    return (CInternationalTrader::CPlayerTradeInfo **)CInternationalTrader::CPlayerTradeInfo::AddBuilding(v4, a2);
  return result;
}


// address=[0x14627a0]
// Decompiled from int __thiscall CInternationalTrader::RemoveBuilding(CInternationalTrader *this, struct CBuilding *a2)

void  CInternationalTrader::RemoveBuilding(class CBuilding *) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-8h]
  CInternationalTrader::CPlayerTradeInfo *v4; // [esp+8h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 452, "pBuilding!= NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a2 )
    return result;
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = *(CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](v3);
  if ( !v4 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 457, "pPlayerInfo!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( v4 )
    return CInternationalTrader::CPlayerTradeInfo::RemoveBuilding(v4, a2);
  return result;
}


// address=[0x1462840]
// Decompiled from struct CInternationalTrader::CTradeBuildingInfo *__stdcall CInternationalTrader::SetGoodStatus(
        int a1,
        struct CBuilding *a2,
        int a3,
        int a4)

void  CInternationalTrader::SetGoodStatus(int,class CBuilding *,enum PILE_TYPES,enum TGOOD_STATUS) {
  
  struct CInternationalTrader::CTradeBuildingInfo *result; // eax
  CInternationalTrader::CPlayerTradeInfo *v5; // [esp+4h] [ebp-4h]

  if ( (a1 <= 0 || a1 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         471,
         "_iPlayerID > 0 && _iPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( !a2 )
  {
    result = (struct CInternationalTrader::CTradeBuildingInfo *)BBSupportDbgReport(
                                                                  2,
                                                                  "Logic\\InternationalTrader.cpp",
                                                                  472,
                                                                  "_pOwnerBuilding!=NULL");
    if ( result == (struct CInternationalTrader::CTradeBuildingInfo *)1 )
      __debugbreak();
  }
  if ( a4 != 4 && a4 != 8 )
  {
    if ( a4 )
    {
      result = (struct CInternationalTrader::CTradeBuildingInfo *)BBSupportDbgReport(
                                                                    2,
                                                                    "Logic\\InternationalTrader.cpp",
                                                                    473,
                                                                    "_Status == TRADING_IMPORT || _Status == TRADING_EXPO"
                                                                    "RT || _Status==0");
      if ( result == (struct CInternationalTrader::CTradeBuildingInfo *)1 )
        __debugbreak();
    }
  }
  if ( !a2 )
    return result;
  v5 = *(CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](a1);
  if ( !v5 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 481, "pPlayerInfo!=NULL") == 1 )
    __debugbreak();
  return CInternationalTrader::CPlayerTradeInfo::SetGoodStatus(v5, a2, a3, a4);
}


// address=[0x1462930]
// Decompiled from // public: void __thiscall CInternationalTrader::SwitchToNextGoodStatus(int,class CBuilding *,enum PILE_TYPES)
int __thiscall CInternationalTrader::SwitchToNextGoodStatus(void *this, int a2, int a3, int a4)

void  CInternationalTrader::SwitchToNextGoodStatus(int,class CBuilding *,enum PILE_TYPES) {
  
  int result; // eax
  int v5; // [esp+0h] [ebp-10h]

  if ( (a2 <= 0 || a2 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         490,
         "_iPlayerID > 0 && _iPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( !a3 )
  {
    result = BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 491, "_pAtBuilding!=NULL");
    if ( result == 1 )
      __debugbreak();
  }
  if ( !a3 )
    return result;
  v5 = (CInternationalTrader::GetGoodStatus(this, a2, a3, a4) + 1) % 3;
  return CInternationalTrader::SetGoodStatus(this, a2, a3, a4, v5);
}


// address=[0x14629f0]
// Decompiled from bool __thiscall CInternationalTrader::SwitchPlayerTradeStatus(CInternationalTrader *this, int a2, int a3)

void  CInternationalTrader::SwitchPlayerTradeStatus(int,int) {
  
  CInternationalTrader::CPlayerTradeInfo **v3; // eax

  if ( (a3 < 0 || a3 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         415,
         "_iPlayerID>=0 && _iPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  if ( (a2 < 0 || a2 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         416,
         "_iForPlayerID>=0 && _iForPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  v3 = (CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](a2);
  return CInternationalTrader::CPlayerTradeInfo::SwitchPlayerTradeStatus(*v3, a3);
}


// address=[0x1462a80]
// Decompiled from char *__thiscall CInternationalTrader::SetPlayerTradeStatus(CInternationalTrader *this, int a2, int a3, bool a4)

void  CInternationalTrader::SetPlayerTradeStatus(int,int,bool) {
  
  CInternationalTrader::CPlayerTradeInfo **v4; // eax

  if ( (a3 < 0 || a3 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         404,
         "_iWithPlayerID>=0 && _iWithPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  if ( (a2 < 0 || a2 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         405,
         "iForPlayerID>=0 && iForPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  if ( a2 == a3 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 406, "iForPlayerID!= _iWithPlayerID") == 1 )
    __debugbreak();
  v4 = (CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](a2);
  return CInternationalTrader::CPlayerTradeInfo::SetPlayerTradeStatus(*v4, a3, a4);
}


// address=[0x1462b40]
// Decompiled from char __thiscall CInternationalTrader::GetPlayerTradeStatus(CInternationalTrader *this, int a2, int a3)

bool  CInternationalTrader::GetPlayerTradeStatus(int,int) {
  
  CInternationalTrader::CPlayerTradeInfo **v3; // eax

  if ( (a2 < 0 || a2 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         423,
         "_iPlayerID>=0 && _iPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 < 0 || a3 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         424,
         "_OtherPlayerID>=0 && _OtherPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  v3 = (CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](a2);
  return CInternationalTrader::CPlayerTradeInfo::GetPlayerTradeStatus(*v3, a3);
}


// address=[0x1462bd0]
// Decompiled from char __thiscall CInternationalTrader::TradeWithSomeone(CInternationalTrader *this, int a2)

bool  CInternationalTrader::TradeWithSomeone(int) {
  
  CInternationalTrader::CPlayerTradeInfo **v2; // eax

  if ( (a2 < 0 || a2 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         431,
         "_iPlayerID>=0 && _iPlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  v2 = (CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](a2);
  return CInternationalTrader::CPlayerTradeInfo::TradeWithSomeone(*v2);
}


// address=[0x1462c30]
// Decompiled from char __thiscall CInternationalTrader::CheckGoodMatch(CInternationalTrader *this, int a2, int a3)

bool  CInternationalTrader::CheckGoodMatch(int,int) {
  
  int v4; // eax
  _BYTE v5[16]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v6[12]; // [esp+14h] [ebp-58h] BYREF
  _BYTE v7[12]; // [esp+20h] [ebp-4Ch] BYREF
  _BYTE v8[12]; // [esp+2Ch] [ebp-40h] BYREF
  int v9; // [esp+38h] [ebp-34h]
  void *v10; // [esp+3Ch] [ebp-30h]
  int v11; // [esp+40h] [ebp-2Ch]
  int v12; // [esp+44h] [ebp-28h]
  std::_Iterator_base12 *v13; // [esp+48h] [ebp-24h]
  std::_Iterator_base12 *v14; // [esp+4Ch] [ebp-20h]
  CInternationalTrader *v15; // [esp+50h] [ebp-1Ch]
  unsigned __int8 *v16; // [esp+54h] [ebp-18h]
  unsigned __int8 *BuildingPtr; // [esp+58h] [ebp-14h]
  char v18; // [esp+5Dh] [ebp-Fh]
  char v19; // [esp+5Eh] [ebp-Eh]
  char v20; // [esp+5Fh] [ebp-Dh]
  int v21; // [esp+68h] [ebp-4h]

  v15 = this;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  v16 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a3);
  if ( !BuildingPtr && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 222, "pAtBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !BuildingPtr )
    return 0;
  if ( !v16 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 223, "pWithBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !v16 )
    return 0;
  v9 = IEntity::OwnerId(BuildingPtr);
  v12 = IEntity::OwnerId(v16);
  CInternationalTrader::GetExportGoodList(v5, BuildingPtr);
  v21 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::begin(v8);
  LOBYTE(v21) = 1;
  while ( 1 )
  {
    v14 = (std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::end(v6);
    v13 = v14;
    LOBYTE(v21) = 2;
    v20 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator!=(v14);
    LOBYTE(v21) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v6);
    if ( !v20 )
      break;
    v11 = *(_DWORD *)(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v8)
                    + 4);
    v10 = *(void **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](v12);
    v4 = IEntity::Type((unsigned __int16 *)BuildingPtr);
    if ( CInternationalTrader::CPlayerTradeInfo::ImportGood(v10, v11, v4) )
    {
      v19 = 1;
      LOBYTE(v21) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v8);
      v21 = -1;
      std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
      return v19;
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator++(
      v7,
      0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v7);
  }
  LOBYTE(v21) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v8);
  v18 = 0;
  v21 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return v18;
}


// address=[0x1462e10]
// Decompiled from char __thiscall CInternationalTrader::CheckGoodMatch(void *this, int a2, int a3, int a4)

bool  CInternationalTrader::CheckGoodMatch(int,int,enum PILE_TYPES) {
  
  int v5; // eax
  _BYTE v6[16]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v7[12]; // [esp+14h] [ebp-58h] BYREF
  _BYTE v8[12]; // [esp+20h] [ebp-4Ch] BYREF
  _BYTE v9[12]; // [esp+2Ch] [ebp-40h] BYREF
  int v10; // [esp+38h] [ebp-34h]
  void *v11; // [esp+3Ch] [ebp-30h]
  int v12; // [esp+40h] [ebp-2Ch]
  std::_Iterator_base12 *v13; // [esp+44h] [ebp-28h]
  std::_Iterator_base12 *v14; // [esp+48h] [ebp-24h]
  void *v15; // [esp+4Ch] [ebp-20h]
  int v16; // [esp+50h] [ebp-1Ch]
  unsigned __int8 *v17; // [esp+54h] [ebp-18h]
  unsigned __int8 *BuildingPtr; // [esp+58h] [ebp-14h]
  char v19; // [esp+5Dh] [ebp-Fh]
  char v20; // [esp+5Eh] [ebp-Eh]
  char v21; // [esp+5Fh] [ebp-Dh]
  int v22; // [esp+68h] [ebp-4h]

  v15 = this;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  v17 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a3);
  if ( !BuildingPtr && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 250, "pAtBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !BuildingPtr )
    return 0;
  if ( !v17 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 251, "pWithBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !v17 )
    return 0;
  v10 = IEntity::OwnerId(BuildingPtr);
  v12 = IEntity::OwnerId(v17);
  CInternationalTrader::GetExportGoodList(v6, BuildingPtr);
  v22 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::begin(v9);
  LOBYTE(v22) = 1;
  while ( 1 )
  {
    v14 = (std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::end(v7);
    v13 = v14;
    LOBYTE(v22) = 2;
    v21 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator!=(v14);
    LOBYTE(v22) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v7);
    if ( !v21 )
      break;
    v16 = *(_DWORD *)(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v9)
                    + 4);
    if ( v16 == a4 )
    {
      v11 = *(void **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](v12);
      v5 = IEntity::Type((unsigned __int16 *)BuildingPtr);
      if ( CInternationalTrader::CPlayerTradeInfo::ImportGood(v11, v16, v5) )
      {
        v20 = 1;
        LOBYTE(v22) = 0;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v9);
        v22 = -1;
        std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
        return v20;
      }
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator++(
      v8,
      0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v8);
  }
  LOBYTE(v22) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v9);
  v19 = 0;
  v22 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return v19;
}


// address=[0x1463000]
// Decompiled from int __stdcall CInternationalTrader::GetGoodStatus(int a1, struct CBuilding *a2, int a3)

enum TGOOD_STATUS  CInternationalTrader::GetGoodStatus(int,class CBuilding *,enum PILE_TYPES) {
  
  CInternationalTrader::CPlayerTradeInfo *v4; // [esp+4h] [ebp-4h]

  if ( (a1 <= 0 || a1 > CPlayerManager::NumberOfPlayers())
    && BBSupportDbgReport(
         2,
         "Logic\\InternationalTrader.cpp",
         506,
         "_PlayerID > 0 && _PlayerID<=g_cPlayerMgr.NumberOfPlayers()") == 1 )
  {
    __debugbreak();
  }
  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 507, "_pBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  v4 = *(CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](a1);
  if ( !v4 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 511, "pPlayerInfo!=NULL") == 1 )
    __debugbreak();
  return CInternationalTrader::CPlayerTradeInfo::GetGoodStatus(v4, a2, a3);
}


// address=[0x14630c0]
// Decompiled from int __stdcall CInternationalTrader::GetExportGoodList(int a1, unsigned __int8 *a2)

class std::vector<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo,class std::allocator<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo> >  CInternationalTrader::GetExportGoodList(class CBuilding *) {
  
  int v2; // eax
  CInternationalTrader::CPlayerTradeInfo **v3; // eax

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 100, "_pBuilding!=NULL") == 1 )
    __debugbreak();
  v2 = IEntity::OwnerId(a2);
  v3 = (CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](v2);
  CInternationalTrader::CPlayerTradeInfo::GetExportListForBuilding(*v3, a1, (struct CBuilding *)a2);
  return a1;
}


// address=[0x1463130]
// Decompiled from bool __thiscall CInternationalTrader::CanWalk(CInternationalTrader *this, int a2, int a3)

bool  CInternationalTrader::CanWalk(int,int) {
  
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // [esp-4h] [ebp-34h]
  int v10; // [esp-4h] [ebp-34h]
  int v11; // [esp-4h] [ebp-34h]
  int v12; // [esp-4h] [ebp-34h]
  int v13; // [esp+Ch] [ebp-24h]
  int v14; // [esp+14h] [ebp-1Ch]
  unsigned __int8 *v15; // [esp+20h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+24h] [ebp-Ch]
  int v17; // [esp+28h] [ebp-8h]
  int v18; // [esp+28h] [ebp-8h]
  int WorkingAreaPackedXY; // [esp+2Ch] [ebp-4h]
  int v20; // [esp+2Ch] [ebp-4h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  v15 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a3);
  if ( !BuildingPtr || !v15 )
    return 0;
  v4 = IEntity::Type((unsigned __int16 *)BuildingPtr);
  if ( v4 != IEntity::Type((unsigned __int16 *)v15) )
    return 0;
  if ( IEntity::Type((unsigned __int16 *)BuildingPtr) == 32 )
  {
    WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(BuildingPtr);
    v17 = CBuilding::GetWorkingAreaPackedXY(v15);
    v9 = Y16X16::UnpackYFast(WorkingAreaPackedXY);
    v5 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
    v14 = CWorldManager::SectorId(v5, v9);
    v10 = Y16X16::UnpackYFast(v17);
    v6 = Y16X16::UnpackXFast(v17);
    return v14 == CWorldManager::SectorId(v6, v10);
  }
  else
  {
    v20 = CBuilding::EnsignPackedXY(BuildingPtr);
    v18 = CBuilding::EnsignPackedXY(v15);
    v11 = Y16X16::UnpackYFast(v20);
    v7 = Y16X16::UnpackXFast(v20);
    v13 = CWorldManager::SectorId(v7, v11);
    v12 = Y16X16::UnpackYFast(v18);
    v8 = Y16X16::UnpackXFast(v18);
    return v13 == CWorldManager::SectorId(v8, v12);
  }
}


// address=[0x3f1f7b4]
// [Decompilation failed for static bool CInternationalTrader::m_bInit]

// address=[0x3f1f7b8]
// [Decompilation failed for static class std::vector<class CInternationalTrader::CPlayerTradeInfo *,class std::allocator<class CInternationalTrader::CPlayerTradeInfo *> > CInternationalTrader::m_sPlayerList]

// address=[0x14632c0]
// Decompiled from int CInternationalTrader::InitPlayerList()

static void __cdecl CInternationalTrader::InitPlayerList(void) {
  
  int result; // eax
  int v1; // eax
  CInternationalTrader::CPlayerTradeInfo **v2; // eax
  CInternationalTrader::CPlayerTradeInfo *v3; // [esp+8h] [ebp-1Ch]
  CInternationalTrader::CPlayerTradeInfo *C; // [esp+Ch] [ebp-18h]
  int i; // [esp+14h] [ebp-10h]

  result = (unsigned __int8)CInternationalTrader::m_bInit;
  if ( CInternationalTrader::m_bInit )
    return result;
  v1 = CPlayerManager::NumberOfPlayers();
  std::vector<CInternationalTrader::CPlayerTradeInfo *>::resize(v1 + 1);
  for ( i = 0; ; ++i )
  {
    result = CPlayerManager::NumberOfPlayers();
    if ( i > result )
      break;
    C = (CInternationalTrader::CPlayerTradeInfo *)operator new(0x28u);
    if ( C )
      v3 = CInternationalTrader::CPlayerTradeInfo::CPlayerTradeInfo(C);
    else
      v3 = 0;
    *(_DWORD *)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](i) = v3;
    v2 = (CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](i);
    CInternationalTrader::CPlayerTradeInfo::SetPlayerID(*v2, i);
  }
  CInternationalTrader::m_bInit = 1;
  return result;
}


// address=[0x14633b0]
// Decompiled from int __thiscall CInternationalTrader::CheckTrade(
        CInternationalTrader *this,
        struct CInternationalTrader::CPlayerTradeInfo *a2,
        struct CInternationalTrader::CPlayerTradeInfo *a3,
        struct CBuilding *a4)

int  CInternationalTrader::CheckTrade(class CInternationalTrader::CPlayerTradeInfo *,class CInternationalTrader::CPlayerTradeInfo *,class CBuilding *) {
  
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp-4h] [ebp-D0h]
  int v11; // [esp-4h] [ebp-D0h]
  _BYTE v12[12]; // [esp+4h] [ebp-C8h] BYREF
  _BYTE v13[12]; // [esp+10h] [ebp-BCh] BYREF
  _BYTE v14[12]; // [esp+1Ch] [ebp-B0h] BYREF
  _BYTE v15[12]; // [esp+28h] [ebp-A4h] BYREF
  int v16; // [esp+34h] [ebp-98h]
  _BYTE v17[16]; // [esp+38h] [ebp-94h] BYREF
  _BYTE v18[16]; // [esp+48h] [ebp-84h] BYREF
  int v19; // [esp+58h] [ebp-74h]
  int v20; // [esp+5Ch] [ebp-70h]
  int v21; // [esp+60h] [ebp-6Ch]
  int NumberOfFreePiles; // [esp+64h] [ebp-68h]
  int v23; // [esp+68h] [ebp-64h]
  int v24; // [esp+6Ch] [ebp-60h]
  CInternationalTrader *v25; // [esp+70h] [ebp-5Ch]
  std::_Iterator_base12 *v26; // [esp+74h] [ebp-58h]
  std::_Iterator_base12 *v27; // [esp+78h] [ebp-54h]
  std::_Iterator_base12 *v28; // [esp+7Ch] [ebp-50h]
  std::_Iterator_base12 *v29; // [esp+80h] [ebp-4Ch]
  _BYTE v30[12]; // [esp+84h] [ebp-48h] BYREF
  int CurrentAmount; // [esp+90h] [ebp-3Ch]
  CTradingBuildingRole *v32; // [esp+94h] [ebp-38h]
  CTradingBuildingRole *v33; // [esp+98h] [ebp-34h]
  unsigned __int8 *v34; // [esp+9Ch] [ebp-30h]
  unsigned __int8 *BuildingPtr; // [esp+A0h] [ebp-2Ch]
  _BYTE v36[12]; // [esp+A4h] [ebp-28h] BYREF
  int v37; // [esp+B0h] [ebp-1Ch]
  int v38; // [esp+B4h] [ebp-18h]
  int v39; // [esp+B8h] [ebp-14h] BYREF
  char v40; // [esp+BCh] [ebp-10h]
  char v41; // [esp+BDh] [ebp-Fh]
  char v42; // [esp+BEh] [ebp-Eh]
  char v43; // [esp+BFh] [ebp-Dh]
  int v44; // [esp+C8h] [ebp-4h]

  v25 = this;
  if ( !a2 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 110, "pCurrentPlayer!=NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  if ( !a3 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 111, "pOtherPlayer!=NULL") == 1 )
    __debugbreak();
  if ( !a3 )
    return 0;
  if ( !a4 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 112, "_pAtBuilding!=NULL") == 1 )
    __debugbreak();
  if ( !a4 )
    return 0;
  v41 = 0;
  v40 = 0;
  CInternationalTrader::CPlayerTradeInfo::GetExportListForBuilding(a2, (int)v17, a4);
  v44 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::begin(v36);
  LOBYTE(v44) = 1;
  while ( 1 )
  {
    v29 = (std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::end(v14);
    v28 = v29;
    LOBYTE(v44) = 2;
    v43 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator!=(v29);
    LOBYTE(v44) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v14);
    if ( !v43 )
    {
      LOBYTE(v44) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v36);
      v19 = 0;
      v44 = -1;
      std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
      return v19;
    }
    v10 = IEntity::Type((unsigned __int16 *)a4);
    v5 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v36);
    if ( CInternationalTrader::CPlayerTradeInfo::ImportGood(a3, *(_DWORD *)(v5 + 4), v10) )
      break;
LABEL_39:
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator++(
      v15,
      0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v15);
  }
  v6 = IEntity::Type((unsigned __int16 *)a4);
  CInternationalTrader::CPlayerTradeInfo::GetExportList(a3, (int)v18, v6);
  LOBYTE(v44) = 3;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::begin(v30);
  LOBYTE(v44) = 4;
  while ( 1 )
  {
    v27 = (std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::end(v12);
    v26 = v27;
    LOBYTE(v44) = 5;
    v42 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator!=(v27);
    LOBYTE(v44) = 4;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v12);
    if ( !v42 )
    {
      LOBYTE(v44) = 3;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v30);
      LOBYTE(v44) = 1;
      std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
      goto LABEL_39;
    }
    v39 = -1;
    v11 = IEntity::Type((unsigned __int16 *)a4);
    v7 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v36);
    if ( CInternationalTrader::CPlayerTradeInfo::ImportGoodAtBuilding(a3, &v39, *(_DWORD *)(v7 + 4), v11) )
    {
      if ( v39 == IEntity::ID()
        && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 145, "ImportBuildingID!= _pAtBuilding->ID()") == 1 )
      {
        __debugbreak();
      }
      v41 = 1;
      v38 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v36);
      if ( v38 != IEntity::ID()
        && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 149, "ExportBuildingID == _pAtBuilding->ID()") == 1 )
      {
        __debugbreak();
      }
      if ( CInternationalTrader::CanWalk(v25, v38, v39) )
      {
        v40 = 1;
        BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v39);
        v34 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v38);
        if ( v34 )
        {
          if ( BuildingPtr )
          {
            v33 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
            v32 = (CTradingBuildingRole *)CBuilding::Role(v34);
            v8 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v30);
            CurrentAmount = CTradingBuildingRole::GetCurrentAmount(v33, *(_DWORD *)(v8 + 4));
            v9 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v36);
            v37 = CTradingBuildingRole::GetCurrentAmount(v32, *(_DWORD *)(v9 + 4));
            NumberOfFreePiles = CTradingBuildingRole::GetNumberOfFreePiles(v33);
            v23 = CTradingBuildingRole::GetNumberOfFreePiles(v32);
            v16 = 8;
            v24 = 16;
            if ( v37 >= 16 && CurrentAmount >= v37 )
              break;
          }
        }
      }
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator++(
      v13,
      0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v13);
  }
  if ( 8 * v23 < v37 || 8 * NumberOfFreePiles < CurrentAmount )
  {
    v20 = 0;
    LOBYTE(v44) = 3;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v30);
    LOBYTE(v44) = 1;
    std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
    LOBYTE(v44) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v36);
    v44 = -1;
    std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
    return v20;
  }
  else
  {
    v21 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v30);
    LOBYTE(v44) = 3;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v30);
    LOBYTE(v44) = 1;
    std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
    LOBYTE(v44) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v36);
    v44 = -1;
    std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
    return v21;
  }
}


// address=[0x1463850]
// Decompiled from // private: void __thiscall CInternationalTrader::DisableTrading(class CBuilding *,int,int)
void __stdcall CInternationalTrader::DisableTrading(_DWORD *a1, int a2, int a3)

void  CInternationalTrader::DisableTrading(class CBuilding *,int,int) {
  
  CTradingBuildingRole *v3; // [esp+4h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 211, "_pBuilding!=NULL") == 1 )
    __debugbreak();
  if ( a1 )
  {
    v3 = (CTradingBuildingRole *)CBuilding::Role(a1);
    CTradingBuildingRole::DisableTranding(v3);
  }
}


// address=[0x14638a0]
// Decompiled from // private: bool __thiscall CInternationalTrader::IsBuildingAnPort(class CBuilding *)
bool __stdcall CInternationalTrader::IsBuildingAnPort(unsigned __int8 *a1)

bool  CInternationalTrader::IsBuildingAnPort(class CBuilding *) {
  
  int v1; // eax
  struct CInternationalTrader::CTradeBuildingInfo *BuildingInfo; // [esp+8h] [ebp-8h]
  CInternationalTrader::CPlayerTradeInfo *v4; // [esp+Ch] [ebp-4h]

  v1 = IEntity::OwnerId(a1);
  v4 = *(CInternationalTrader::CPlayerTradeInfo **)std::vector<CInternationalTrader::CPlayerTradeInfo *>::operator[](v1);
  if ( !v4 && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 278, "pPlayerInfo!=NULL") == 1 )
    __debugbreak();
  BuildingInfo = CInternationalTrader::CPlayerTradeInfo::GetBuildingInfo(v4, (struct CBuilding *)a1);
  if ( !BuildingInfo && BBSupportDbgReport(2, "Logic\\InternationalTrader.cpp", 280, "pBuldingInfo!=NULL") == 1 )
    __debugbreak();
  return *((_DWORD *)BuildingInfo + 1) == 32;
}


