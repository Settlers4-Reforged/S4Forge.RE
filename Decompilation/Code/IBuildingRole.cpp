#include "IBuildingRole.h"

// Definitions for class IBuildingRole

// address=[0x130f040]
// Decompiled from char __thiscall IBuildingRole::HaveInhabitant(_BYTE *this)

bool  IBuildingRole::HaveInhabitant(void)const {
  
  return this[29];
}


// address=[0x14e66e0]
// Decompiled from IBuildingRole *__thiscall IBuildingRole::~IBuildingRole(IBuildingRole *this)

 IBuildingRole::~IBuildingRole(void) {
  
  IBuildingRole *result; // eax

  result = this;
  *(_DWORD *)this = &IBuildingRole::_vftable_;
  return result;
}


// address=[0x14e67d0]
// Decompiled from int __thiscall IBuildingRole::GetPileIdWithNeedForGood(IBuildingRole *this, int a2)

int  IBuildingRole::GetPileIdWithNeedForGood(int)const {
  
  return (*(int (__thiscall **)(IBuildingRole *, int))(*(_DWORD *)this + 56))(this, a2);
}


// address=[0x14e6800]
// Decompiled from char __stdcall IBuildingRole::HasShipAmmo(int a1)

bool  IBuildingRole::HasShipAmmo(int)const {
  
  return 0;
}


// address=[0x14e6820]
// Decompiled from void __thiscall IBuildingRole::LockPiles(IBuildingRole *this, struct CBuilding *a2, bool a3)

void  IBuildingRole::LockPiles(class CBuilding *,bool) {
  
  ;
}


// address=[0x14e6840]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IBuildingRole::NotifySelected(IBuildingRole *this)

void  IBuildingRole::NotifySelected(void) {
  
  ;
}


// address=[0x14e6850]
// Decompiled from int __thiscall IBuildingRole::OrderInhabitantCancelled(IBuildingRole *this, struct CBuilding *a2)

void  IBuildingRole::OrderInhabitantCancelled(class CBuilding *) {
  
  return (*(int (__thiscall **)(IBuildingRole *, _DWORD))(*(_DWORD *)this + 80))(this, *((unsigned __int16 *)this + 4));
}


// address=[0x14e68b0]
// Decompiled from char __thiscall IBuildingRole::SettlerEnter(IBuildingRole *this, struct CBuilding *a2, int a3)

bool  IBuildingRole::SettlerEnter(class CBuilding *,int) {
  
  (*(void (__thiscall **)(IBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 72))(this, a2, 0);
  return 1;
}


// address=[0x14e68e0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IBuildingRole::SwitchPriority(IBuildingRole *this)

void  IBuildingRole::SwitchPriority(void) {
  
  ;
}


// address=[0x14fdee0]
// Decompiled from IBuildingRole *__thiscall IBuildingRole::IBuildingRole(IBuildingRole *this)

 IBuildingRole::IBuildingRole(void) {
  
  unsigned int i; // [esp+0h] [ebp-8h]

  CPersistence::CPersistence(this);
  *(_DWORD *)this = &IBuildingRole::_vftable_;
  *((_BYTE *)this + 4) = 0;
  *((_BYTE *)this + 5) = 0;
  *((_WORD *)this + 3) = 0;
  *((_WORD *)this + 4) = 0;
  *((_WORD *)this + 5) = 0;
  *((_WORD *)this + 6) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 29) = 0;
  *((_BYTE *)this + 365) = 0;
  *((_DWORD *)this + 94) = 0;
  for ( i = 0; i < 0xA; ++i )
  {
    *((_DWORD *)this + 2 * i + 19) = 0;
    *((_DWORD *)this + 2 * i + 20) = 0;
  }
  IBuildingRole::WorkingAreaChanged(this);
  *((_BYTE *)this + 356) = 0;
  *((_DWORD *)this + 8) = 0;
  return this;
}


// address=[0x14fdfb0]
// Decompiled from struct IBuildingRole *__thiscall IBuildingRole::Update(struct IBuildingRole *this, struct CBuilding *a2)

void  IBuildingRole::Update(class CBuilding *) {
  
  int TickCounter; // esi
  int v3; // esi
  struct IBuildingRole *result; // eax
  int v5; // eax
  unsigned __int8 v6; // al
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // esi
  int v16; // eax
  int v17; // et2
  int v18; // eax
  int v19; // [esp-8h] [ebp-30h]
  int v20; // [esp-8h] [ebp-30h]
  unsigned int v21; // [esp-4h] [ebp-2Ch]
  unsigned int v22; // [esp-4h] [ebp-2Ch]
  unsigned int v23; // [esp-4h] [ebp-2Ch]
  unsigned int v24; // [esp-4h] [ebp-2Ch]
  unsigned int BuildingJobFrameCount; // [esp+8h] [ebp-20h]
  int v26; // [esp+Ch] [ebp-1Ch]
  int v27; // [esp+10h] [ebp-18h]
  char v28; // [esp+14h] [ebp-14h]
  int v29; // [esp+18h] [ebp-10h]
  unsigned int i; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 v32; // [esp+26h] [ebp-2h]

  TickCounter = CGameData::GetTickCounter(g_pGameData);
  v3 = TickCounter - IAnimatedEntity::LastUpdateTick(a2);
  result = this;
  *((_WORD *)this + 5) = v3;
  if ( !*((_WORD *)this + 5) )
    return result;
  v5 = CGameData::GetTickCounter(g_pGameData);
  IAnimatedEntity::SetLastUpdateTick(a2, v5);
  for ( i = 0; i < 0xA; ++i )
  {
    if ( !*((_BYTE *)this + 20 * i + 156) )
      continue;
    if ( !IEntity::Race(a2) || IEntity::Race(a2) == 1 )
    {
      v6 = *((_BYTE *)this + 20 * i + 165) + 1;
      *((_BYTE *)this + 20 * i + 165) = v6;
      if ( v6 <= 2u )
        continue;
      *((_BYTE *)this + 20 * i + 165) = 0;
    }
    v28 = *((_BYTE *)this + 20 * i + 158);
    if ( v28 )
    {
      if ( v28 == 1 )
      {
        if ( *((_BYTE *)this + 20 * i + 164) )
        {
          v22 = *((_DWORD *)this + 2 * i + 19);
          v8 = IEntity::Race(a2);
          BuildingJobFrameCount = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v8, v22);
          if ( ++*((_DWORD *)this + 2 * i + 20) >= BuildingJobFrameCount )
          {
            *((_DWORD *)this + 2 * i + 20) = 0;
            result = (struct IBuildingRole *)(20 * i);
            if ( !*((_BYTE *)this + 20 * i + 159) )
              return result;
            v29 = *((unsigned __int8 *)this + 20 * i + 159);
            *((_BYTE *)this + 20 * i + 157) = v29 + j__rand() % ((v29 + 1) / 2);
            result = this;
            *((_BYTE *)this + 20 * i + 164) = 0;
            return result;
          }
        }
        else if ( *((_BYTE *)this + 20 * i + 157) )
        {
          --*((_BYTE *)this + 20 * i + 157);
        }
        else
        {
          *((_BYTE *)this + 20 * i + 156) = 1;
          v23 = *((_DWORD *)this + 2 * i + 19);
          v9 = IEntity::Race(a2);
          *((_BYTE *)this + 20 * i + 164) = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v9, v23);
          *((_DWORD *)this + 2 * i + 20) = 0;
        }
      }
      else if ( v28 == 2 && *((_BYTE *)this + 20 * i + 164) )
      {
        if ( (unsigned __int8)++*((_BYTE *)this + 20 * i + 157) < (int)*((unsigned __int8 *)this + 20 * i + 164) )
        {
          v24 = *((_DWORD *)this + 2 * i + 19);
          v10 = IEntity::Race(a2);
          v26 = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v10, v24);
          if ( v26 <= 0 )
            v26 = 1;
          *((_DWORD *)this + 2 * i + 20) = (*((_DWORD *)this + 2 * i + 20) + 1) % (unsigned int)v26;
        }
        else
        {
          *((_BYTE *)this + 20 * i + 156) = 0;
        }
      }
    }
    else
    {
      v21 = *((_DWORD *)this + 2 * i + 19);
      v7 = IEntity::Race(a2);
      v27 = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v7, v21);
      if ( v27 <= 0 )
        v27 = 1;
      *((_DWORD *)this + 2 * i + 20) = (*((_DWORD *)this + 2 * i + 20) + 1) % (unsigned int)v27;
    }
    if ( *((int *)this + 5 * i + 42) > 0 && *((unsigned __int8 *)this + 20 * i + 173) == *((_DWORD *)this + 2 * i + 20) )
    {
      if ( *((_BYTE *)this + 20 * i + 172) == 100
        || (v11 = *((unsigned __int8 *)this + 20 * i + 172), v11 >= j__rand() % 100) )
      {
        v19 = IEntity::Y(a2);
        v12 = IEntity::X(a2);
        CSoundManager::PlayEnvironmentSound(g_pSoundManager, *((_DWORD *)this + 5 * i + 42), v12, v19, 0);
      }
    }
  }
  result = (struct IBuildingRole *)*((unsigned __int8 *)this + 356);
  if ( !*((_BYTE *)this + 356) )
    return result;
  v13 = IEntity::Type((unsigned __int16 *)a2);
  result = (struct IBuildingRole *)CBuildingMgr::IsMilitary(v13);
  if ( (_BYTE)result )
    return result;
  v32 = *((_BYTE *)this + 358) + 1;
  *((_BYTE *)this + 358) = v32;
  if ( v32 >= (int)*((unsigned __int8 *)this + 357) )
  {
    if ( (*((_BYTE *)this + 364) & 1) != 0 )
    {
      *((_BYTE *)this + 358) = 0;
      *((_BYTE *)this + 359) = 0;
      ++*((_BYTE *)this + 356);
      if ( (*((_BYTE *)this + 364) & 0x40) != 0 )
      {
        result = (struct IBuildingRole *)CGfxManager::GetEffectFrameCount(
                                           (CGfxManager *)g_pGfxManager,
                                           *((unsigned __int8 *)this + 356));
        *((_BYTE *)this + 357) = (_BYTE)result;
        *((_BYTE *)this + 364) = 0;
      }
      else
      {
        *((_BYTE *)this + 357) = *((_BYTE *)this + 365);
        result = this;
        *((_BYTE *)this + 364) |= 0x40u;
      }
    }
    else
    {
      result = this;
      *((_BYTE *)this + 356) = 0;
    }
  }
  else
  {
    v14 = (*((unsigned __int8 *)this + 359) + 1)
        % (int)CGfxManager::GetEffectFrameCount((CGfxManager *)g_pGfxManager, *((unsigned __int8 *)this + 356));
    result = this;
    *((_BYTE *)this + 359) = v14;
    if ( *((int *)this + 92) > 0 )
    {
      result = (struct IBuildingRole *)*((unsigned __int8 *)this + 373);
      if ( result == (struct IBuildingRole *)*((unsigned __int8 *)this + 359) )
      {
        if ( *((_BYTE *)this + 372) == 100
          || (v15 = *((unsigned __int8 *)this + 372),
              v16 = j__rand(),
              v17 = v16 % 100,
              result = (struct IBuildingRole *)(v16 / 100),
              v15 >= v17) )
        {
          v20 = IEntity::Y(a2);
          v18 = IEntity::X(a2);
          return (struct IBuildingRole *)CSoundManager::PlayEnvironmentSound(
                                           g_pSoundManager,
                                           *((_DWORD *)this + 92),
                                           v18,
                                           v20,
                                           0);
        }
      }
    }
  }
  return result;
}


// address=[0x14fe560]
// Decompiled from int __thiscall IBuildingRole::Switch(unsigned __int16 *this)

void  IBuildingRole::Switch(void) {
  
  _DWORD *v1; // eax
  _DWORD *v2; // eax
  _DWORD *v4; // eax
  _BYTE v5[24]; // [esp+4h] [ebp-50h] BYREF
  _BYTE v6[24]; // [esp+1Ch] [ebp-38h] BYREF
  _BYTE *v7; // [esp+34h] [ebp-20h]
  _BYTE *v8; // [esp+38h] [ebp-1Ch]
  int v9; // [esp+3Ch] [ebp-18h]
  int v10; // [esp+40h] [ebp-14h]
  unsigned __int16 *v11; // [esp+44h] [ebp-10h]
  int v12; // [esp+50h] [ebp-4h]

  v11 = this;
  v1 = (_DWORD *)CBuildingMgr::operator[](this[3]);
  if ( IEntity::FlagBits(v1, (EntityFlag)0x1000u) )
  {
    v2 = (_DWORD *)CBuildingMgr::operator[](v11[3]);
    IEntity::ClearFlagBits(v2, (EntityFlag)0x1000u);
    CEntityEvent::CEntityEvent((CEntityEvent *)v6, 7u, 0, v11[3], 0, 0);
    v12 = 0;
    v8 = v6;
    v10 = CBuildingMgr::operator[](v11[3]);
    (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v10 + 124))(v10, v8);
    v12 = -1;
    return CEntityEvent::~CEntityEvent(v6);
  }
  else
  {
    v4 = (_DWORD *)CBuildingMgr::operator[](v11[3]);
    IEntity::SetFlagBits(v4, (EntityFlag)0x1000u);
    CEntityEvent::CEntityEvent((CEntityEvent *)v5, 8u, 0, v11[3], 0, 0);
    v12 = 1;
    v7 = v5;
    v9 = CBuildingMgr::operator[](v11[3]);
    (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v9 + 124))(v9, v7);
    v12 = -1;
    return CEntityEvent::~CEntityEvent(v5);
  }
}


// address=[0x14fe6b0]
// Decompiled from IBuildingRole *__thiscall IBuildingRole::InhabitantFlee(IBuildingRole *this, int a2)

void  IBuildingRole::InhabitantFlee(int) {
  
  IBuildingRole *result; // eax

  if ( !*((_WORD *)this + 4)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1285, "m_uSettlerId") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int16 *)this + 4) != a2
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1286, "m_uSettlerId == _iSettlerId") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 4) = 1;
  *((_BYTE *)this + 5) = 0;
  *((_WORD *)this + 4) = 0;
  CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  IAnimatedEntity::RegisterForLogicUpdate(1);
  result = this;
  *((_BYTE *)this + 29) = 0;
  return result;
}


// address=[0x14fe750]
// Decompiled from int __thiscall IBuildingRole::ReturnBuildingMaterial(IBuildingRole *this, struct CBuilding *a2)

void  IBuildingRole::ReturnBuildingMaterial(class CBuilding *) {
  
  int v2; // eax
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-Ch] [ebp-20h]
  int v8; // [esp-Ch] [ebp-20h]
  int v9; // [esp-Ch] [ebp-20h]
  int v10; // [esp-4h] [ebp-18h]
  char *BuildingInfo; // [esp+4h] [ebp-10h]
  signed int v12; // [esp+8h] [ebp-Ch]
  signed int v13; // [esp+Ch] [ebp-8h]
  signed int v14; // [esp+10h] [ebp-4h]

  v10 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
  v2 = IEntity::Race(a2);
  BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v2, v10);
  v14 = BuildingInfo[3] / 2;
  v13 = BuildingInfo[2] / 2;
  result = BuildingInfo[4] / 2;
  v12 = result;
  while ( v14 )
  {
    v7 = IEntity::Y(a2);
    v4 = IEntity::X(a2);
    if ( v14 <= 8 )
    {
      result = CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v4, v7, 7u, v14);
      v14 = 0;
    }
    else
    {
      CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v4, v7, 7u, 8u);
      result = v14 - 8;
      v14 -= 8;
    }
  }
  while ( v13 )
  {
    v8 = IEntity::Y(a2);
    v5 = IEntity::X(a2);
    if ( v13 <= 8 )
    {
      result = CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v5, v8, 0x20u, v13);
      v13 = 0;
    }
    else
    {
      result = CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v5, v8, 0x20u, 8u);
      v13 -= 8;
    }
  }
  while ( v12 )
  {
    v9 = IEntity::Y(a2);
    v6 = IEntity::X(a2);
    if ( v12 <= 8 )
    {
      result = CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v6, v9, 0xEu, v12);
      v12 = 0;
    }
    else
    {
      result = CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v6, v9, 0xEu, 8u);
      v12 -= 8;
    }
  }
  return result;
}


// address=[0x14fe8d0]
// Decompiled from unsigned __int16 *__thiscall IBuildingRole::RemoveInhabitant(unsigned __int16 *this, _DWORD *a2)

void  IBuildingRole::RemoveInhabitant(class CBuilding *) {
  
  unsigned __int16 *result; // eax
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // [esp-4h] [ebp-30h]
  int v9; // [esp+4h] [ebp-28h]
  struct CEcoSector *v10; // [esp+8h] [ebp-24h]
  int v11; // [esp+Ch] [ebp-20h]
  struct CEcoSector *EcoSectorPtr; // [esp+10h] [ebp-1Ch]
  int v13; // [esp+14h] [ebp-18h]
  int v15; // [esp+1Ch] [ebp-10h] BYREF
  int v16; // [esp+20h] [ebp-Ch] BYREF
  unsigned __int8 *v17; // [esp+24h] [ebp-8h]
  char v18; // [esp+2Bh] [ebp-1h]

  result = this;
  if ( !this[4] )
    return result;
  v17 = (unsigned __int8 *)CSettlerMgr::operator[](this[4]);
  v13 = CBuildingMgr::operator[](this[3]);
  v3 = IEntity::PackedXY(v17);
  if ( v3 == IEntity::PackedXY(v13) )
  {
    if ( !IEntity::FlagBits(v17, OnBoard)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingRole.cpp",
           310,
           "rSettler.FlagBits(ENTITY_FLAG_ON_BOARD) != 0") == 1 )
    {
      __debugbreak();
    }
    v18 = 0;
    v15 = CBuilding::DoorX(v13);
    v16 = CBuilding::DoorY(v13);
    v11 = CWorldManager::EcoSectorId(v15, v16);
    EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, v11);
    if ( EcoSectorPtr )
    {
      v4 = CEcoSector::Owner(EcoSectorPtr);
      if ( v4 == IEntity::OwnerId(v17) )
        v18 = CSettlerMgr::SearchFreePositionInEcoSector((CSettlerMgr *)g_cSettlerMgr, &v15, &v16, v11);
    }
    if ( !v18 )
    {
      v8 = IEntity::Y(a2);
      v5 = IEntity::X(a2);
      v9 = CWorldManager::EcoSectorId(v5, v8);
      v10 = CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, v9);
      if ( v10 )
      {
        v6 = CEcoSector::Owner(v10);
        if ( v6 == IEntity::OwnerId(v17) )
          v18 = CSettlerMgr::SearchFreePositionInEcoSector((CSettlerMgr *)g_cSettlerMgr, &v15, &v16, v9);
      }
    }
    if ( !v18 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 336, "bPositionFound") == 1 )
      __debugbreak();
    v7 = Y16X16::PackXYFast(v15, v16);
    (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v17 + 52))(v17, v7);
  }
  else if ( IEntity::FlagBits(v17, OnBoard)
         && BBSupportDbgReport(
              2,
              "MapObjects\\Building\\BuildingRole.cpp",
              342,
              "rSettler.FlagBits(ENTITY_FLAG_ON_BOARD) == 0") == 1 )
  {
    __debugbreak();
  }
  IEntity::SetFlagBits(v17, Visible);
  IEntity::ClearFlagBits(v17, MagicInvisible);
  IEntity::ClearFlagBits(v17, OnBoard);
  result = this;
  this[4] = 0;
  return result;
}


// address=[0x14feaf0]
// Decompiled from bool __thiscall IBuildingRole::SearchInWorkingArea(int this, unsigned __int8 *a2, int a3)

bool  IBuildingRole::SearchInWorkingArea(class CBuilding *,int) {
  
  int WorkingAreaPackedXY; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v11; // [esp-8h] [ebp-80h]
  int v12; // [esp-8h] [ebp-80h]
  int v13; // [esp-8h] [ebp-80h]
  int v14; // [esp-4h] [ebp-7Ch]
  int v15; // [esp+14h] [ebp-64h]
  int v16; // [esp+18h] [ebp-60h]
  int v17; // [esp+20h] [ebp-58h]
  int v18; // [esp+24h] [ebp-54h]
  int v19; // [esp+28h] [ebp-50h]
  int v20; // [esp+2Ch] [ebp-4Ch]
  int v21; // [esp+34h] [ebp-44h]
  int v22; // [esp+38h] [ebp-40h]
  int v23; // [esp+3Ch] [ebp-3Ch]
  int v24; // [esp+40h] [ebp-38h]
  int v25; // [esp+44h] [ebp-34h]
  int v26; // [esp+48h] [ebp-30h]
  int v27; // [esp+50h] [ebp-28h]
  int v28; // [esp+54h] [ebp-24h]
  int v29; // [esp+58h] [ebp-20h]
  int j; // [esp+5Ch] [ebp-1Ch]
  bool v31; // [esp+62h] [ebp-16h]
  int i; // [esp+64h] [ebp-14h]
  int v33; // [esp+68h] [ebp-10h]
  int v34; // [esp+68h] [ebp-10h]
  int v35; // [esp+6Ch] [ebp-Ch]
  int v36; // [esp+6Ch] [ebp-Ch]

  v17 = IEntity::OwnerId(a2);
  IAIDifficultyLevels::GetDifficultyLevel(v17);
  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(a2);
  v16 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
  v4 = CBuilding::GetWorkingAreaPackedXY(a2);
  v15 = Y16X16::UnpackYFast(v4);
  v29 = -1;
  v28 = -1;
  v11 = *(char *)(*(_DWORD *)(this + 376) + 478);
  v5 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v5, v11);
  v22 = *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](a3) + 5);
  v12 = *(char *)(*(_DWORD *)(this + 376) + 478);
  v6 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v6, v12);
  v21 = *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](a3) + 6);
  v27 = CSpiralOffsets::Last(*(_DWORD *)(*(_DWORD *)(this + 376) + 492));
  v7 = CBuilding::EnsignWorldIdx(a2);
  v19 = CWorldManager::EcoSectorId(v7);
  if ( *(_DWORD *)(this + 32) )
  {
    if ( *(unsigned __int16 *)(this + 4 * a3 + 22) < *(unsigned __int16 *)(this + 4 * a3 + 20) + 75 )
      *(_WORD *)(this + 4 * a3 + 22) = *(_WORD *)(this + 4 * a3 + 20) + 75;
    for ( i = 0; i < 2; ++i )
    {
      if ( i )
        v20 = 50;
      else
        v20 = 75;
      v25 = v20;
      v24 = *(unsigned __int16 *)(this + 4 * a3 + 20 + 2 * i);
      if ( v20 + v24 >= v27 )
        v25 = v27 - v24;
      for ( j = 0; j < v25; ++j )
      {
        v33 = v16 + CSpiralOffsets::DeltaX(j + v24);
        v35 = v15 + CSpiralOffsets::DeltaY(j + v24);
        if ( (unsigned __int8)CWorldManager::InWorld(v33, v35)
          && CWorldManager::EcoSectorId(v22 + v33, v21 + v35) == v19 )
        {
          v23 = (*(int (__cdecl **)(int, int, _DWORD))(this + 32))(v33, v35, 0);
          if ( v23 > 0 )
          {
            *(_DWORD *)(this + 16) = Y16X16::PackXYFast(v22 + v33, v21 + v35);
            *(_WORD *)(this + 12) = v23;
            v29 = i;
            v28 = j + v24;
            break;
          }
          if ( v23 < 0 )
          {
            v34 = v22 + v33;
            v36 = v21 + v35;
            if ( CWorldManager::EcoSectorId(v34, v36) == v19 )
            {
              *(_DWORD *)(this + 16) = Y16X16::PackXYFast(v34, v36);
              *(_WORD *)(this + 12) = 0;
              v29 = i;
              v28 = j + v24;
              break;
            }
          }
        }
      }
      *(_WORD *)(this + 4 * a3 + 20 + 2 * i) += j;
      if ( v29 >= 0 )
        break;
    }
  }
  if ( *(int *)(*(_DWORD *)(this + 376) + 492) < 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 618, "m_pBuildingInfo->workingAreaRadius >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( *(int *)(*(_DWORD *)(this + 376) + 492) >= 75
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingRole.cpp",
         619,
         "m_pBuildingInfo->workingAreaRadius < SPIRAL_RADIUS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( v29 < 0 )
  {
    v31 = *(unsigned __int16 *)(this + 20) >= v27;
    if ( *(unsigned __int16 *)(this + 4 * a3 + 20) < v27 )
    {
      if ( *(unsigned __int16 *)(this + 4 * a3 + 22) >= v27 )
        *(_WORD *)(this + 4 * a3 + 22) = 0;
    }
    else
    {
      *(_WORD *)(this + 4 * a3 + 20) = 0;
      *(_WORD *)(this + 4 * a3 + 22) = 0;
    }
    if ( v31 )
    {
      if ( *(_BYTE *)(this + 28) )
      {
        *(_BYTE *)(this + 28) = 0;
        v26 = 3837;
        v18 = IEntity::Type((unsigned __int16 *)a2);
        if ( v18 == 1 )
        {
          v26 = 2554;
        }
        else if ( v18 == 4 )
        {
          v26 = 2543;
        }
        if ( v26 != 3837 )
        {
          v8 = IEntity::OwnerId(a2);
          if ( v8 == CPlayerManager::GetLocalPlayerId() )
          {
            v14 = IEntity::Y(a2);
            v13 = IEntity::X(a2);
            v9 = IEntity::OwnerId(a2);
            CTextMsgHandler::AddWarningMsg(v26, v9, v13, v14);
          }
        }
      }
      else
      {
        *(_BYTE *)(this + 28) = 1;
      }
    }
  }
  else
  {
    if ( v28 < 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 625, "iFoundIdx >= 0") == 1 )
      __debugbreak();
    *(_BYTE *)(this + 28) = 0;
    if ( !v29 || v28 <= 150 || *(unsigned __int16 *)(this + 4 * a3 + 20) >= 0x96u )
      *(_WORD *)(this + 4 * a3 + 20) = 0;
    else
      *(_WORD *)(this + 4 * a3 + 22) = v28;
    if ( a3 == 1 )
    {
      *(_WORD *)(this + 20) = 0;
      *(_WORD *)(this + 22) = 0;
    }
  }
  return v29 >= 0;
}


// address=[0x14ff140]
// Decompiled from int __thiscall IBuildingRole::Decrease(IBuildingRole *this, int a2)

int  IBuildingRole::Decrease(int) {
  
  int v3; // [esp+Ch] [ebp+8h]

  if ( a2 <= 0 )
    return 0;
  v3 = (a2 - 5) / 2;
  if ( v3 <= 0 )
    return 1;
  return v3;
}


// address=[0x14ff180]
// Decompiled from int __thiscall IBuildingRole::TakeJobTrigger(IBuildingRole *this, int a2)

void  IBuildingRole::TakeJobTrigger(int) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  unsigned int v5; // eax
  int result; // eax
  int v7; // [esp-8h] [ebp-34h]
  unsigned int v8; // [esp-4h] [ebp-30h]
  int v9; // [esp+Ch] [ebp-20h]
  _BYTE *v10; // [esp+14h] [ebp-18h]
  char BuildingJobFrameCount; // [esp+1Ch] [ebp-10h]
  const struct CBuildingInfoMgr::STriggerInfos *TriggerInfo; // [esp+20h] [ebp-Ch]
  int v13; // [esp+24h] [ebp-8h]

  v10 = (_BYTE *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v2 = IEntity::Race(v10);
  TriggerInfo = CBuildingInfoMgr::GetTriggerInfo(v2, a2);
  if ( *(int *)TriggerInfo <= 0 )
  {
    result = a2 - 17;
    switch ( a2 )
    {
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
        *((_DWORD *)this + 2 * a2 - 15) = *((_DWORD *)this + 5 * a2 - 45);
        result = (int)this;
        *((_BYTE *)this + 20 * a2 - 184) = 1;
        break;
      case 27:
      case 28:
      case 29:
      case 30:
      case 31:
      case 32:
      case 33:
      case 34:
      case 35:
      case 36:
        result = (int)this;
        *((_BYTE *)this + 20 * a2 - 384) = 0;
        break;
      case 37:
      case 38:
      case 39:
      case 40:
      case 41:
      case 42:
      case 43:
      case 44:
      case 45:
      case 46:
        v9 = a2 - 37;
        *((_DWORD *)this + 2 * a2 - 55) = 0;
        *((_DWORD *)this + 2 * v9 + 20) = 0;
        *((_BYTE *)this + 20 * v9 + 156) = 0;
        result = (int)this;
        *((_BYTE *)this + 20 * v9 + 157) = 0;
        break;
      default:
        break;
    }
  }
  else
  {
    v13 = *((unsigned __int8 *)TriggerInfo + 4);
    *((_DWORD *)this + 2 * v13 + 19) = *(_DWORD *)TriggerInfo;
    *((_DWORD *)this + 2 * v13 + 20) = 0;
    *((_DWORD *)this + 5 * v13 + 40) = *(_DWORD *)TriggerInfo;
    *((_BYTE *)this + 20 * v13 + 158) = 2;
    *((_DWORD *)this + 5 * v13 + 42) = *((_DWORD *)TriggerInfo + 2);
    *((_BYTE *)this + 20 * v13 + 173) = *((_BYTE *)TriggerInfo + 13);
    *((_BYTE *)this + 20 * v13 + 172) = *((_BYTE *)TriggerInfo + 12);
    if ( *((int *)this + 5 * v13 + 42) < 0 && *((int *)this + 5 * v13 + 42) >= 109 )
    {
      BBSupportTracePrintF(0, "Wrong sound id!!!");
      *((_DWORD *)this + 5 * v13 + 42) = 0;
    }
    if ( *((int *)this + 5 * v13 + 42) > 0
      && *((unsigned __int8 *)this + 20 * v13 + 173) == *((_DWORD *)this + 2 * v13 + 20) )
    {
      if ( *((_BYTE *)this + 20 * v13 + 172) == 100
        || (v3 = *((unsigned __int8 *)this + 20 * v13 + 172), v3 >= j__rand() % 100) )
      {
        v7 = IEntity::Y(v10);
        v4 = IEntity::X(v10);
        CSoundManager::PlayEnvironmentSound(g_pSoundManager, *((_DWORD *)this + 5 * v13 + 42), v4, v7, 0);
      }
    }
    BuildingJobFrameCount = *((_BYTE *)TriggerInfo + 6);
    if ( !BuildingJobFrameCount )
    {
      v8 = *((_DWORD *)this + 2 * v13 + 19);
      v5 = IEntity::Race(v10);
      BuildingJobFrameCount = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v5, v8);
    }
    *((_BYTE *)this + 20 * v13 + 164) = BuildingJobFrameCount;
    *((_BYTE *)this + 20 * v13 + 157) = 0;
    result = 20 * v13;
    *((_BYTE *)this + 20 * v13 + 156) = 1;
  }
  if ( *((int *)TriggerInfo + 4) <= 0 )
    return result;
  *((_BYTE *)this + 356) = *((_BYTE *)TriggerInfo + 16);
  *((_BYTE *)this + 357) = *((_BYTE *)TriggerInfo + 24);
  *((_BYTE *)this + 359) = 0;
  *((_BYTE *)this + 358) = 0;
  *((_WORD *)this + 180) = *((_WORD *)TriggerInfo + 10);
  *((_WORD *)this + 181) = *((_WORD *)TriggerInfo + 11);
  *((_BYTE *)this + 364) = *((_BYTE *)TriggerInfo + 25);
  if ( *((_BYTE *)this + 364) )
  {
    --*((_BYTE *)this + 356);
    *((_BYTE *)this + 365) = *((_BYTE *)this + 357);
    *((_BYTE *)this + 357) = CGfxManager::GetEffectFrameCount(
                               (CGfxManager *)g_pGfxManager,
                               *((unsigned __int8 *)this + 356));
  }
  *((_DWORD *)this + 92) = *((_DWORD *)TriggerInfo + 7);
  *((_BYTE *)this + 373) = *((_BYTE *)TriggerInfo + 33);
  result = (int)this;
  *((_BYTE *)this + 372) = *((_BYTE *)TriggerInfo + 32);
  return result;
}


// address=[0x14ff580]
// Decompiled from int __thiscall IBuildingRole::PostLoadSetWaterFlags(IBuildingRole *this, struct CBuilding *a2)

void  IBuildingRole::PostLoadSetWaterFlags(class CBuilding *) {
  
  int result; // eax
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // [esp-10h] [ebp-30h]
  int v7; // [esp-Ch] [ebp-2Ch]
  int v8; // [esp-8h] [ebp-28h]
  int v9; // [esp-4h] [ebp-24h]
  int v10; // [esp-4h] [ebp-24h]
  _DWORD v11[7]; // [esp+0h] [ebp-20h] BYREF
  IBuildingRole *v12; // [esp+1Ch] [ebp-4h]

  v12 = this;
  result = IEntity::FlagBits(a2, (EntityFlag)&unk_4000000);
  if ( result )
    return result;
  result = (int)v12;
  if ( !*((_DWORD *)v12 + 94) )
    return result;
  v3 = *((_DWORD *)v12 + 94);
  result = *(unsigned __int8 *)(v3 + 6);
  if ( !*(_BYTE *)(v3 + 6) )
    return result;
  v9 = *((_DWORD *)v12 + 94) + 816;
  v8 = *(char *)(*((_DWORD *)v12 + 94) + 1);
  v7 = **((char **)v12 + 94);
  v6 = IEntity::Y(a2);
  v4 = IEntity::X(a2);
  CBuildingFlagsWalk::CBuildingFlagsWalk(v4, v6, v7, v8, v9);
  while ( 1 )
  {
    result = (unsigned __int8)CBuildingFlagsWalk::NextPosition(v11);
    if ( !(_BYTE)result )
      break;
    v10 = CBuildingFlagsWalk::CurrentY(v11);
    v5 = CBuildingFlagsWalk::CurrentX(v11);
    (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 16))(g_pTiling, v5, v10);
  }
  return result;
}


// address=[0x14ff650]
// Decompiled from char *__thiscall IBuildingRole::IBuildingRole(char *this, int a2)

 IBuildingRole::IBuildingRole(std::istream &) {
  
  int v3; // [esp+4h] [ebp-14h] BYREF
  int pExceptionObject; // [esp+8h] [ebp-10h] BYREF
  int v5; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int i; // [esp+10h] [ebp-8h]
  char *v7; // [esp+14h] [ebp-4h]

  v7 = this;
  CPersistence::CPersistence(this);
  *(_DWORD *)v7 = &IBuildingRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 4 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v7 + 4);
  operator^<unsigned char>(a2, v7 + 5);
  operator^<unsigned short>(a2, v7 + 6);
  operator^<unsigned short>(a2, v7 + 8);
  operator^<short>(a2, v7 + 10);
  operator^<unsigned short>(a2, v7 + 12);
  operator^<int>(a2, (int)(v7 + 16));
  operator^<unsigned short>(a2, v7 + 20);
  operator^<unsigned short>(a2, v7 + 22);
  operator^<unsigned short>(a2, v7 + 24);
  operator^<unsigned short>(a2, v7 + 26);
  operator^<bool>(a2, v7 + 28);
  operator^<bool>(a2, v7 + 29);
  operator^<unsigned char>(a2, v7 + 356);
  operator^<unsigned char>(a2, v7 + 357);
  operator^<unsigned char>(a2, v7 + 358);
  operator^<unsigned char>(a2, v7 + 359);
  operator^<short>(a2, v7 + 360);
  operator^<short>(a2, v7 + 362);
  operator^<unsigned char>(a2, v7 + 364);
  operator^<unsigned char>(a2, v7 + 365);
  v5 = 0;
  operator^<int>(a2, (int)&v5);
  *((_DWORD *)v7 + 92) = v5;
  operator^<unsigned char>(a2, v7 + 372);
  operator^<unsigned char>(a2, v7 + 373);
  for ( i = 0; i < 0xA; ++i )
  {
    operator^<unsigned int>(a2, &v7[8 * i + 76]);
    operator^<unsigned int>(a2, &v7[8 * i + 80]);
  }
  for ( i = 0; i < 0xA; ++i )
  {
    operator^<unsigned char>(a2, &v7[20 * i + 157]);
    operator^<unsigned char>(a2, &v7[20 * i + 158]);
    operator^<unsigned char>(a2, &v7[20 * i + 159]);
    operator^<unsigned int>(a2, &v7[20 * i + 160]);
    operator^<unsigned char>(a2, &v7[20 * i + 164]);
    operator^<unsigned char>(a2, &v7[20 * i + 165]);
    operator^<unsigned char>(a2, &v7[20 * i + 156]);
    v5 = 0;
    operator^<int>(a2, (int)&v5);
    *(_DWORD *)&v7[20 * i + 168] = v5;
    operator^<unsigned char>(a2, &v7[20 * i + 172]);
    operator^<unsigned char>(a2, &v7[20 * i + 173]);
  }
  *((_DWORD *)v7 + 94) = 0;
  IBuildingRole::m_iLastMiniFlagUpdateTick = 0;
  return v7;
}


// address=[0x14ffaa0]
// Decompiled from int __thiscall IBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)

void  IBuildingRole::Store(std::ostream &) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h]
  struct IBuildingRole *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  CPersistence::Store(this, a2);
  v3 = 4;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned char>(a2, (int)v6 + 4);
  operator^<unsigned char>(a2, (int)v6 + 5);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 3);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 4);
  operator^<short>((int)a2, (__int16 *)v6 + 5);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 6);
  operator^<int>((int)a2, (int *)v6 + 4);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 10);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 11);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 12);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 13);
  operator^<bool>((int)a2, (int)v6 + 28);
  operator^<bool>((int)a2, (int)v6 + 29);
  operator^<unsigned char>(a2, (int)v6 + 356);
  operator^<unsigned char>(a2, (int)v6 + 357);
  operator^<unsigned char>(a2, (int)v6 + 358);
  operator^<unsigned char>(a2, (int)v6 + 359);
  operator^<short>((int)a2, (__int16 *)v6 + 180);
  operator^<short>((int)a2, (__int16 *)v6 + 181);
  operator^<unsigned char>(a2, (int)v6 + 364);
  operator^<unsigned char>(a2, (int)v6 + 365);
  v4 = *((_DWORD *)v6 + 92);
  operator^<int>((int)a2, &v4);
  operator^<unsigned char>(a2, (int)v6 + 372);
  result = operator^<unsigned char>(a2, (int)v6 + 373);
  for ( i = 0; i < 0xA; ++i )
  {
    operator^<unsigned int>(a2, (int *)v6 + 2 * i + 19);
    operator^<unsigned int>(a2, (int *)v6 + 2 * i + 20);
    result = i + 1;
  }
  for ( i = 0; i < 0xA; ++i )
  {
    operator^<unsigned char>(a2, (int)v6 + 20 * i + 157);
    operator^<unsigned char>(a2, (int)v6 + 20 * i + 158);
    operator^<unsigned char>(a2, (int)v6 + 20 * i + 159);
    operator^<unsigned int>(a2, (int *)v6 + 5 * i + 40);
    operator^<unsigned char>(a2, (int)v6 + 20 * i + 164);
    operator^<unsigned char>(a2, (int)v6 + 20 * i + 165);
    operator^<unsigned char>(a2, (int)v6 + 20 * i + 156);
    v4 = *((_DWORD *)v6 + 5 * i + 42);
    operator^<int>((int)a2, &v4);
    operator^<unsigned char>(a2, (int)v6 + 20 * i + 172);
    operator^<unsigned char>(a2, (int)v6 + 20 * i + 173);
    result = i + 1;
  }
  return result;
}


// address=[0x14ffe90]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IBuildingRole::KillInhabitant(IBuildingRole *this, struct CBuilding *a2)

void  IBuildingRole::KillInhabitant(class CBuilding *) {
  
  ;
}


// address=[0x14ffea0]
// Decompiled from int __thiscall IBuildingRole::InitCommon(int this, _BYTE *a2)

void  IBuildingRole::InitCommon(class CBuilding *) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp-8h] [ebp-Ch]
  __int16 v6; // [esp-4h] [ebp-8h]
  int v7; // [esp-4h] [ebp-8h]

  *(_WORD *)(this + 8) = 0;
  *(_BYTE *)(this + 29) = 0;
  *(_BYTE *)(this + 5) = 0;
  IBuildingRole::WorkingAreaChanged(this);
  IEntity::ClearFlagBits(a2, Birth);
  IEntity::SetFlagBits(a2, Ready);
  v6 = IEntity::ID();
  v5 = IEntity::Y(a2);
  v2 = IEntity::X(a2);
  CWorldManager::SetMapObjectId(v2, v5, v6);
  v7 = CBuilding::BuildingTypeEx(a2);
  v3 = IEntity::Race(a2);
  *(_DWORD *)(this + 376) = CBuildingInfoMgr::GetBuildingInfo(v3, v7);
  *(_WORD *)(this + 6) = IEntity::ID();
  (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)a2 + 24))(
    a2,
    *(unsigned __int8 *)(*(_DWORD *)(this + 376) + 500));
  return IBuildingRole::InitHousePatches((void *)this);
}


// address=[0x14fff70]
// Decompiled from void *__thiscall IBuildingRole::InitHousePatches(int this)

void  IBuildingRole::InitHousePatches(void) {
  
  void *result; // eax
  _BYTE *v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // [esp-4h] [ebp-1Ch]
  char v5; // [esp+4h] [ebp-14h]
  char BuildingJobFrameCount; // [esp+8h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]

  if ( !*(_DWORD *)(this + 376)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1008, "m_pBuildingInfo != 0") == 1 )
  {
    __debugbreak();
  }
  result = j__memset((void *)(this + 156), 0, 0xC8u);
  for ( i = 0; i < 0xA; ++i )
  {
    if ( *(_DWORD *)(*(_DWORD *)(this + 376) + 16 * i + 504) )
    {
      v8 = *(unsigned __int8 *)(*(_DWORD *)(this + 376) + 16 * i + 508);
      *(_DWORD *)(this + 20 * v8 + 160) = *(_DWORD *)(*(_DWORD *)(this + 376) + 16 * i + 504);
      *(_BYTE *)(this + 20 * v8 + 158) = *(_BYTE *)(*(_DWORD *)(this + 376) + 16 * i + 509);
      *(_DWORD *)(this + 20 * v8 + 168) = *(_DWORD *)(*(_DWORD *)(this + 376) + 16 * i + 512);
      *(_BYTE *)(this + 20 * v8 + 173) = *(_BYTE *)(*(_DWORD *)(this + 376) + 16 * i + 517);
      *(_BYTE *)(this + 20 * v8 + 172) = *(_BYTE *)(*(_DWORD *)(this + 376) + 16 * i + 516);
      if ( *(int *)(this + 20 * v8 + 168) < 0 && *(int *)(this + 20 * v8 + 168) >= 109 )
      {
        if ( BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1035, "0") == 1 )
          __debugbreak();
        *(_DWORD *)(this + 20 * v8 + 168) = 0;
      }
      *(_BYTE *)(this + 20 * v8 + 165) = 0;
      v5 = *(_BYTE *)(*(_DWORD *)(this + 376) + 16 * i + 509);
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          *(_DWORD *)(this + 8 * v8 + 76) = *(_DWORD *)(*(_DWORD *)(this + 376) + 16 * i + 504);
          *(_DWORD *)(this + 8 * v8 + 80) = 0;
          *(_BYTE *)(this + 20 * v8 + 157) = *(_BYTE *)(*(_DWORD *)(this + 376) + 16 * i + 510);
          *(_BYTE *)(this + 20 * v8 + 159) = *(_BYTE *)(*(_DWORD *)(this + 376) + 16 * i + 510);
          *(_BYTE *)(this + 20 * v8 + 164) = 0;
          *(_BYTE *)(this + 20 * v8 + 156) = 1;
        }
        else if ( v5 == 2 )
        {
          BuildingJobFrameCount = *(_BYTE *)(*(_DWORD *)(this + 376) + 16 * i + 510);
          if ( !BuildingJobFrameCount )
          {
            v4 = *(_DWORD *)(this + 20 * v8 + 160);
            v2 = (_BYTE *)CBuildingMgr::operator[](*(unsigned __int16 *)(this + 6));
            v3 = IEntity::Race(v2);
            BuildingJobFrameCount = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v3, v4);
          }
          *(_BYTE *)(this + 20 * v8 + 164) = BuildingJobFrameCount;
          *(_BYTE *)(this + 20 * v8 + 157) = 0;
          *(_BYTE *)(this + 20 * v8 + 156) = 0;
        }
      }
      else
      {
        *(_DWORD *)(this + 8 * v8 + 76) = *(_DWORD *)(*(_DWORD *)(this + 376) + 16 * i + 504);
        *(_DWORD *)(this + 8 * v8 + 80) = 0;
        if ( *(_BYTE *)(*(_DWORD *)(this + 376) + 16 * i + 510) )
          *(_BYTE *)(this + 20 * v8 + 156) = 1;
        else
          *(_BYTE *)(this + 20 * v8 + 156) = 0;
      }
    }
    result = (void *)(i + 1);
  }
  return result;
}


// address=[0x1500310]
// Decompiled from char __thiscall IBuildingRole::OrderInhabitant(IBuildingRole *this, struct CBuilding *a2)

bool  IBuildingRole::OrderInhabitant(class CBuilding *) {
  
  int v2; // eax
  CEcoSector *v4; // eax
  int v5; // [esp-8h] [ebp-10h]
  int v6; // [esp-4h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-8h]

  if ( *((_WORD *)this + 4) )
    return 1;
  v2 = CBuilding::EnsignWorldIdx(a2);
  v7 = CWorldManager::EcoSectorId(v2);
  if ( !v7 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 255, "m_iESId != 0") == 1 )
    __debugbreak();
  if ( !v7 )
    return 0;
  v6 = *(char *)(*((_DWORD *)this + 94) + 478);
  v5 = IEntity::ID();
  v4 = (CEcoSector *)CEcoSectorMgr::operator[](v7);
  *((_WORD *)this + 4) = CEcoSector::OrderWorker(v4, v5, v6);
  if ( *((_WORD *)this + 4) )
    return 1;
  IAnimatedEntity::RegisterForLogicUpdate(31);
  return 0;
}


// address=[0x15003d0]
// Decompiled from IBuildingRole *__thiscall IBuildingRole::MiniFlag(IBuildingRole *this, struct SGfxObjectInfo *a2, int a3)

void  IBuildingRole::MiniFlag(struct SGfxObjectInfo &,int) {
  
  IBuildingRole *result; // eax
  _DWORD *v4; // eax
  int v5; // eax
  int v6; // [esp-8h] [ebp-2F8h]
  int v7; // [esp+8h] [ebp-2E8h]
  _DWORD v9[184]; // [esp+10h] [ebp-2E0h] BYREF

  result = this;
  if ( !*((_BYTE *)this + 29) )
    return result;
  if ( dword_40F21B0 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_40F21B0);
    if ( dword_40F21B0 == -1 )
    {
      dword_40F21AC = CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, 0x220u);
      v9[183] = -1;
      j___Init_thread_footer(&dword_40F21B0);
    }
  }
  if ( CGameData::GetTickCounter(g_pGameData) - IBuildingRole::m_iLastMiniFlagUpdateTick > 0 )
  {
    IBuildingRole::m_iLastMiniFlagUpdateTick = CGameData::GetTickCounter(g_pGameData);
    ++dword_40F21A8;
    dword_40F21A8 %= dword_40F21AC;
  }
  v4 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  if ( IEntity::FlagBits(v4, (EntityFlag)0x1000u) )
    v7 = 1;
  else
    v7 = 2;
  v6 = dword_40F21A8;
  v5 = CPlayerManager::Color(a3);
  CGfxManager::GetObjectGfxInfo((int)v9, v5 + 544, v6, v7);
  *((_DWORD *)a2 + 20) = v9[0];
  *((_DWORD *)a2 + 21) = v9[1];
  *((_DWORD *)a2 + 6) = *(_DWORD *)(*((_DWORD *)this + 94) + 44);
  result = *(IBuildingRole **)(*((_DWORD *)this + 94) + 48);
  *((_DWORD *)a2 + 7) = result;
  return result;
}


// address=[0x1500590]
// Decompiled from int __thiscall IBuildingRole::WorkingAreaChanged(IBuildingRole *this)

void  IBuildingRole::WorkingAreaChanged(void) {
  
  int result; // eax

  *((_WORD *)this + 10) = 0;
  *((_WORD *)this + 11) = 0;
  *((_WORD *)this + 12) = 0;
  result = 2;
  *((_WORD *)this + 13) = 0;
  *((_BYTE *)this + 28) = 0;
  return result;
}


// address=[0x1500620]
// Decompiled from void __thiscall IBuildingRole::DetachWithoutNotify(IBuildingRole *this, struct CBuilding *a2, int a3)

void  IBuildingRole::DetachWithoutNotify(class CBuilding *,int) {
  
  CBuilding::DetachWithoutNotify(a2, a3);
}


// address=[0x40f21a4]
// [Decompilation failed for static int IBuildingRole::m_iLastMiniFlagUpdateTick]

// address=[0x14e6830]
// Decompiled from void __thiscall IBuildingRole::NotifyDetach(IBuildingRole *this, struct CBuilding *a2, int a3)

void  IBuildingRole::NotifyDetach(class CBuilding *,int) {
  
  ;
}


