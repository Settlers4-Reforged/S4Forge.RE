#include "IBuildingRole.h"

// Definitions for class IBuildingRole

// address=[0x130f040]
// Decompiled from char __thiscall IBuildingRole::HaveInhabitant(IBuildingRole *this)
bool  IBuildingRole::HaveInhabitant(void)const {
  
  return this->m_bInhabitants;
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
int  IBuildingRole::GetPileIdWithNeedForGood(int a2)const {
  
  return (*(int (__thiscall **)(IBuildingRole *, int))(*(_DWORD *)this + 56))(this, a2);
}


// address=[0x14e6800]
// Decompiled from char __stdcall IBuildingRole::HasShipAmmo(int a1)
bool  IBuildingRole::HasShipAmmo(int a1)const {
  
  return 0;
}


// address=[0x14e6820]
// Decompiled from void __thiscall IBuildingRole::LockPiles(IBuildingRole *this, struct CBuilding *a2, bool a3)
void  IBuildingRole::LockPiles(class CBuilding * a2, bool a3) {
  
  ;
}


// address=[0x14e6840]
// Decompiled from void __thiscall IBuildingRole::NotifySelected(IBuildingRole *this)
void  IBuildingRole::NotifySelected(void) {
  
  ;
}


// address=[0x14e6850]
// Decompiled from void __thiscall IBuildingRole::OrderInhabitantCancelled(IBuildingRole *this, struct CBuilding *a2)
void  IBuildingRole::OrderInhabitantCancelled(class CBuilding * a2) {
  
  this->InhabitantFlee(this, (unsigned __int16)this->m_uSettlerId);
}


// address=[0x14e68b0]
// Decompiled from char __thiscall IBuildingRole::SettlerEnter(IBuildingRole *this, struct CBuilding *a2, int a3)
bool  IBuildingRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  this->LockPiles(this, a2, 0);
  return 1;
}


// address=[0x14e68e0]
// Decompiled from void __thiscall IBuildingRole::SwitchPriority(IBuildingRole *this)
void  IBuildingRole::SwitchPriority(void) {
  
  ;
}


// address=[0x14fdee0]
// Decompiled from IBuildingRole *__thiscall IBuildingRole::IBuildingRole(IBuildingRole *this)
 IBuildingRole::IBuildingRole(void) {
  
  unsigned int i; // [esp+0h] [ebp-8h]

  CPersistence::CPersistence(this);
  this->__vftable = (IBuildingRole_vtbl *)&IBuildingRole::_vftable_;
  this->byte4 = 0;
  this->byte5 = 0;
  this->m_iEntityId = 0;
  this->m_uSettlerId = 0;
  this->wordA = 0;
  this->wordC = 0;
  this->field_10 = 0;
  this->m_bInhabitants = 0;
  this->byte16D = 0;
  this->m_pBuildingInfo = 0;
  for ( i = 0; i < 0xA; ++i )
  {
    this->gap_4c[2 * i] = 0;
    this->gap_4c[2 * i + 1] = 0;
  }
  IBuildingRole::WorkingAreaChanged(this);
  this->byte164 = 0;
  this->m_pSearchFkt = 0;
  return this;
}


// address=[0x14fdfb0]
// Decompiled from void __thiscall IBuildingRole::Update(struct IBuildingRole *this, struct CBuilding *a2)
void  IBuildingRole::Update(class CBuilding * a2) {
  
  __int16 TickCounter; // si
  DWORD v3; // eax
  unsigned __int8 v4; // al
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int BuildingJobFrameCount; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // [esp-Ch] [ebp-34h]
  int v15; // [esp-8h] [ebp-30h]
  int v16; // [esp-8h] [ebp-30h]
  int v17; // [esp-4h] [ebp-2Ch]
  int v18; // [esp-4h] [ebp-2Ch]
  int v19; // [esp-4h] [ebp-2Ch]
  int v20; // [esp-4h] [ebp-2Ch]
  signed int v21; // [esp+Ch] [ebp-1Ch]
  signed int v22; // [esp+10h] [ebp-18h]
  char v23; // [esp+14h] [ebp-14h]
  int v24; // [esp+18h] [ebp-10h]
  unsigned int i; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 v27; // [esp+26h] [ebp-2h]

  TickCounter = CGameData::GetTickCounter(g_pGameData);
  this->wordA = TickCounter - IAnimatedEntity::LastUpdateTick(a2);
  if ( !this->wordA )
    return;
  v3 = CGameData::GetTickCounter(g_pGameData);
  IAnimatedEntity::SetLastUpdateTick((IAnimatedEntity *)a2, v3);
  for ( i = 0; i < 0xA; ++i )
  {
    if ( !LOBYTE(this->gap_4c[5 * i + 20]) )
      continue;
    if ( !IEntity::Race(a2) || IEntity::Race(a2) == 1 )
    {
      v4 = BYTE1(this->gap_4c[5 * i + 22]) + 1;
      BYTE1(this->gap_4c[5 * i + 22]) = v4;
      if ( v4 <= 2u )
        continue;
      BYTE1(this->gap_4c[5 * i + 22]) = 0;
    }
    v23 = BYTE2(this->gap_4c[5 * i + 20]);
    if ( v23 )
    {
      if ( v23 == 1 )
      {
        if ( LOBYTE(this->gap_4c[5 * i + 22]) )
        {
          v18 = this->gap_4c[2 * i];
          v6 = IEntity::Race(a2);
          BuildingJobFrameCount = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v6, v18);
          if ( ++this->gap_4c[2 * i + 1] >= BuildingJobFrameCount )
          {
            this->gap_4c[2 * i + 1] = 0;
            if ( !HIBYTE(this->gap_4c[5 * i + 20]) )
              return;
            v24 = HIBYTE(this->gap_4c[5 * i + 20]);
            BYTE1(this->gap_4c[5 * i + 20]) = v24 + j__rand() % ((v24 + 1) / 2);
            LOBYTE(this->gap_4c[5 * i + 22]) = 0;
            return;
          }
        }
        else if ( BYTE1(this->gap_4c[5 * i + 20]) )
        {
          --BYTE1(this->gap_4c[5 * i + 20]);
        }
        else
        {
          LOBYTE(this->gap_4c[5 * i + 20]) = 1;
          v19 = this->gap_4c[2 * i];
          v8 = IEntity::Race(a2);
          LOBYTE(this->gap_4c[5 * i + 22]) = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v8, v19);
          this->gap_4c[2 * i + 1] = 0;
        }
      }
      else if ( v23 == 2 && LOBYTE(this->gap_4c[5 * i + 22]) )
      {
        if ( (unsigned __int8)++BYTE1(this->gap_4c[5 * i + 20]) < (int)LOBYTE(this->gap_4c[5 * i + 22]) )
        {
          v20 = this->gap_4c[2 * i];
          v9 = IEntity::Race(a2);
          v21 = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v9, v20);
          if ( v21 <= 0 )
            v21 = 1;
          this->gap_4c[2 * i + 1] = (this->gap_4c[2 * i + 1] + 1) % v21;
        }
        else
        {
          LOBYTE(this->gap_4c[5 * i + 20]) = 0;
        }
      }
    }
    else
    {
      v17 = this->gap_4c[2 * i];
      v5 = IEntity::Race(a2);
      v22 = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v5, v17);
      if ( v22 <= 0 )
        v22 = 1;
      this->gap_4c[2 * i + 1] = (this->gap_4c[2 * i + 1] + 1) % v22;
    }
    if ( (int)this->gap_4c[5 * i + 23] > 0 && BYTE1(this->gap_4c[5 * i + 24]) == this->gap_4c[2 * i + 1] )
    {
      if ( LOBYTE(this->gap_4c[5 * i + 24]) == 100 || (v10 = LOBYTE(this->gap_4c[5 * i + 24]), v10 >= j__rand() % 100) )
      {
        v15 = IEntity::Y(a2);
        v14 = IEntity::X(a2);
        CSoundManager::PlayEnvironmentSound(g_pSoundManager, this->gap_4c[5 * i + 23], v14, v15, 0);
      }
    }
  }
  if ( this->byte164 )
  {
    v11 = IEntity::Type((IEntity *)a2);
    if ( !(unsigned __int8)CBuildingMgr::IsMilitary(v11) )
    {
      v27 = this->gap165[1] + 1;
      this->gap165[1] = v27;
      if ( v27 >= (int)(unsigned __int8)this->gap165[0] )
      {
        if ( (this->gap165[7] & 1) != 0 )
        {
          this->gap165[1] = 0;
          this->gap165[2] = 0;
          ++this->byte164;
          if ( (this->gap165[7] & 0x40) != 0 )
          {
            this->gap165[0] = CGfxManager::GetEffectFrameCount(g_pGfxManager, (unsigned __int8)this->byte164);
            this->gap165[7] = 0;
          }
          else
          {
            this->gap165[0] = this->byte16D;
            this->gap165[7] |= 0x40u;
          }
        }
        else
        {
          this->byte164 = 0;
        }
      }
      else
      {
        this->gap165[2] = ((unsigned __int8)this->gap165[2] + 1)
                        % (int)CGfxManager::GetEffectFrameCount(g_pGfxManager, (unsigned __int8)this->byte164);
        if ( (int)this->field_170 > 0 && BYTE1(this->field_174) == (unsigned __int8)this->gap165[2] )
        {
          if ( LOBYTE(this->field_174) == 100 || (v12 = LOBYTE(this->field_174), v12 >= j__rand() % 100) )
          {
            v16 = IEntity::Y(a2);
            v13 = IEntity::X(a2);
            CSoundManager::PlayEnvironmentSound(g_pSoundManager, this->field_170, v13, v16, 0);
          }
        }
      }
    }
  }
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
// Decompiled from void __thiscall IBuildingRole::InhabitantFlee(IBuildingRole *this, int _iSettlerId)
void  IBuildingRole::InhabitantFlee(int _iSettlerId) {
  
  CBuilding *v2; // eax

  if ( !this->m_uSettlerId && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1285, "m_uSettlerId") == 1 )
    __debugbreak();
  if ( (unsigned __int16)this->m_uSettlerId != _iSettlerId
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1286, "m_uSettlerId == _iSettlerId") == 1 )
  {
    __debugbreak();
  }
  this->byte4 = 1;
  this->byte5 = 0;
  this->m_uSettlerId = 0;
  v2 = CBuildingMgr::operator[]((unsigned __int16)this->m_iEntityId);
  IAnimatedEntity::RegisterForLogicUpdate((IAnimatedEntity *)v2, 1);
  this->m_bInhabitants = 0;
}


// address=[0x14fe750]
// Decompiled from int __thiscall IBuildingRole::ReturnBuildingMaterial(IBuildingRole *this, struct CBuilding *a2)
void  IBuildingRole::ReturnBuildingMaterial(class CBuilding * a2) {
  
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
// Decompiled from void __thiscall IBuildingRole::RemoveInhabitant(IBuildingRole *this, _DWORD *a2)
void  IBuildingRole::RemoveInhabitant(class CBuilding * a2) {
  
  int v2; // esi
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // [esp-4h] [ebp-30h]
  int v8; // [esp+4h] [ebp-28h]
  int v9; // [esp+8h] [ebp-24h]
  int v10; // [esp+Ch] [ebp-20h]
  int EcoSectorPtr; // [esp+10h] [ebp-1Ch]
  IEntity *v12; // [esp+14h] [ebp-18h]
  int v14; // [esp+1Ch] [ebp-10h] BYREF
  int v15; // [esp+20h] [ebp-Ch] BYREF
  IEntity *v16; // [esp+24h] [ebp-8h]
  char bPositionFound; // [esp+2Bh] [ebp-1h]

  if ( this->m_uSettlerId )
  {
    v16 = CSettlerMgr::operator[]((unsigned __int16)this->m_uSettlerId);
    v12 = (IEntity *)CBuildingMgr::operator[]((unsigned __int16)this->m_iEntityId);
    v2 = IEntity::PackedXY(v16);
    if ( v2 == IEntity::PackedXY(v12) )
    {
      if ( !IEntity::FlagBits(v16, ENTITY_FLAG_OnBoard)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\BuildingRole.cpp",
             310,
             "rSettler.FlagBits(ENTITY_FLAG_ON_BOARD) != 0") == 1 )
      {
        __debugbreak();
      }
      bPositionFound = 0;
      v14 = CBuilding::DoorX(v12);
      v15 = CBuilding::DoorY(v12);
      v10 = CWorldManager::EcoSectorId(v14, v15);
      EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, v10);
      if ( EcoSectorPtr )
      {
        v3 = CEcoSector::Owner(EcoSectorPtr);
        if ( v3 == IEntity::OwnerId(v16) )
          bPositionFound = CSettlerMgr::SearchFreePositionInEcoSector((CSettlerMgr *)g_cSettlerMgr, &v14, &v15, v10);
      }
      if ( !bPositionFound )
      {
        v7 = IEntity::Y(a2);
        v4 = IEntity::X(a2);
        v8 = CWorldManager::EcoSectorId(v4, v7);
        v9 = CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, v8);
        if ( v9 )
        {
          v5 = CEcoSector::Owner(v9);
          if ( v5 == IEntity::OwnerId(v16) )
            bPositionFound = CSettlerMgr::SearchFreePositionInEcoSector((CSettlerMgr *)g_cSettlerMgr, &v14, &v15, v8);
        }
      }
      if ( !bPositionFound
        && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 336, "bPositionFound") == 1 )
      {
        __debugbreak();
      }
      v6 = Y16X16::PackXYFast(v14, v15);
      ((void (__thiscall *)(IEntity *, int))v16->j_?PlaceInMapObjectLayer@IEntity@@UAEXH@Z)(v16, v6);
    }
    else if ( IEntity::FlagBits(v16, ENTITY_FLAG_OnBoard)
           && BBSupportDbgReport(
                2,
                "MapObjects\\Building\\BuildingRole.cpp",
                342,
                "rSettler.FlagBits(ENTITY_FLAG_ON_BOARD) == 0") == 1 )
    {
      __debugbreak();
    }
    IEntity::SetFlagBits(v16, ENTITY_FLAG_Visible);
    IEntity::ClearFlagBits(v16, ENTITY_FLAG_MagicInvisible);
    IEntity::ClearFlagBits(v16, ENTITY_FLAG_OnBoard);
    this->m_uSettlerId = 0;
  }
}


// address=[0x14feaf0]
// Decompiled from bool __thiscall IBuildingRole::SearchInWorkingArea(IBuildingRole *this, IEntity *a2, unsigned int a3)
bool  IBuildingRole::SearchInWorkingArea(class CBuilding * a2, int a3) {
  
  int WorkingAreaPackedXY; // eax
  int v4; // eax
  int v5; // eax
  CSettlerMgr::SSettlerInfos *SettlerInfo; // eax
  int v7; // eax
  CSettlerMgr::SSettlerInfos *v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int m_iBuildingInhabitant; // [esp-8h] [ebp-80h]
  int v14; // [esp-8h] [ebp-80h]
  int v15; // [esp-8h] [ebp-80h]
  int v16; // [esp-4h] [ebp-7Ch]
  int v17; // [esp+14h] [ebp-64h]
  int v18; // [esp+18h] [ebp-60h]
  int v19; // [esp+20h] [ebp-58h]
  int v20; // [esp+24h] [ebp-54h]
  int v21; // [esp+28h] [ebp-50h]
  int v22; // [esp+2Ch] [ebp-4Ch]
  int m_iU7; // [esp+34h] [ebp-44h]
  int m_iU6; // [esp+38h] [ebp-40h]
  int v25; // [esp+3Ch] [ebp-3Ch]
  int v26; // [esp+40h] [ebp-38h]
  int v27; // [esp+44h] [ebp-34h]
  int v28; // [esp+48h] [ebp-30h]
  int v29; // [esp+50h] [ebp-28h]
  int iFoundIdx; // [esp+54h] [ebp-24h]
  int v31; // [esp+58h] [ebp-20h]
  int j; // [esp+5Ch] [ebp-1Ch]
  bool v33; // [esp+62h] [ebp-16h]
  int i; // [esp+64h] [ebp-14h]
  unsigned int v35; // [esp+68h] [ebp-10h]
  int v36; // [esp+68h] [ebp-10h]
  unsigned int v37; // [esp+6Ch] [ebp-Ch]
  int v38; // [esp+6Ch] [ebp-Ch]

  v19 = IEntity::OwnerId(a2);
  IAIDifficultyLevels::GetDifficultyLevel(v19);
  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(a2);
  v18 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
  v4 = CBuilding::GetWorkingAreaPackedXY(a2);
  v17 = Y16X16::UnpackYFast(v4);
  v31 = -1;
  iFoundIdx = -1;
  m_iBuildingInhabitant = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
  v5 = IEntity::Race(a2);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v5, m_iBuildingInhabitant);
  m_iU6 = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, a3)->m_iOffsetX;
  v14 = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
  v7 = IEntity::Race(a2);
  v8 = CSettlerMgr::GetSettlerInfo(v7, v14);
  m_iU7 = std::vector<CSettlerMgr::SSearchInfos>::operator[](&v8->m_vSearches, a3)->m_iOffsetY;
  v29 = CSpiralOffsets::Last(this->m_pBuildingInfo->m_iWorkingAreaRadius);
  v9 = CBuilding::EnsignWorldIdx((CBuilding *)a2);
  v21 = CWorldManager::EcoSectorId(v9);
  if ( this->m_pSearchFkt )
  {
    if ( *(unsigned __int16 *)&this->gap_14[4 * a3 + 2] < *(unsigned __int16 *)&this->gap_14[4 * a3] + 75 )
      *(_WORD *)&this->gap_14[4 * a3 + 2] = *(_WORD *)&this->gap_14[4 * a3] + 75;
    for ( i = 0; i < 2; ++i )
    {
      if ( i )
        v22 = 50;
      else
        v22 = 75;
      v27 = v22;
      v26 = *(unsigned __int16 *)&this->gap_14[4 * a3 + 2 * i];
      if ( v22 + v26 >= v29 )
        v27 = v29 - v26;
      for ( j = 0; j < v27; ++j )
      {
        v35 = v18 + CSpiralOffsets::DeltaX(j + v26);
        v37 = v17 + CSpiralOffsets::DeltaY(j + v26);
        if ( CWorldManager::InWorld(v35, v37) && CWorldManager::EcoSectorId(m_iU6 + v35, m_iU7 + v37) == v21 )
        {
          v25 = ((int (__cdecl *)(unsigned int, unsigned int, _DWORD))this->m_pSearchFkt)(v35, v37, 0);
          if ( v25 > 0 )
          {
            this->field_10 = Y16X16::PackXYFast(m_iU6 + v35, m_iU7 + v37);
            this->wordC = v25;
            v31 = i;
            iFoundIdx = j + v26;
            break;
          }
          if ( v25 < 0 )
          {
            v36 = m_iU6 + v35;
            v38 = m_iU7 + v37;
            if ( CWorldManager::EcoSectorId(v36, v38) == v21 )
            {
              this->field_10 = Y16X16::PackXYFast(v36, v38);
              this->wordC = 0;
              v31 = i;
              iFoundIdx = j + v26;
              break;
            }
          }
        }
      }
      *(_WORD *)&this->gap_14[4 * a3 + 2 * i] += j;
      if ( v31 >= 0 )
        break;
    }
  }
  if ( (int)this->m_pBuildingInfo->m_iWorkingAreaRadius < 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 618, "m_pBuildingInfo->workingAreaRadius >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( (int)this->m_pBuildingInfo->m_iWorkingAreaRadius >= 75
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingRole.cpp",
         619,
         "m_pBuildingInfo->workingAreaRadius < SPIRAL_RADIUS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( v31 < 0 )
  {
    v33 = *(unsigned __int16 *)this->gap_14 >= v29;
    if ( *(unsigned __int16 *)&this->gap_14[4 * a3] < v29 )
    {
      if ( *(unsigned __int16 *)&this->gap_14[4 * a3 + 2] >= v29 )
        *(_WORD *)&this->gap_14[4 * a3 + 2] = 0;
    }
    else
    {
      *(_WORD *)&this->gap_14[4 * a3] = 0;
      *(_WORD *)&this->gap_14[4 * a3 + 2] = 0;
    }
    if ( v33 )
    {
      if ( this->field_1C )
      {
        this->field_1C = 0;
        v28 = 3837;
        v20 = IEntity::Type(a2);
        if ( v20 == 1 )
        {
          v28 = 2554;
        }
        else if ( v20 == 4 )
        {
          v28 = 2543;
        }
        if ( v28 != 3837 )
        {
          v10 = IEntity::OwnerId(a2);
          if ( v10 == CPlayerManager::GetLocalPlayerId() )
          {
            v16 = IEntity::Y(a2);
            v15 = IEntity::X(a2);
            v11 = IEntity::OwnerId(a2);
            CTextMsgHandler::AddWarningMsg(v28, v11, v15, v16);
          }
        }
      }
      else
      {
        this->field_1C = 1;
      }
    }
  }
  else
  {
    if ( iFoundIdx < 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 625, "iFoundIdx >= 0") == 1 )
      __debugbreak();
    this->field_1C = 0;
    if ( !v31 || iFoundIdx <= 150 || *(unsigned __int16 *)&this->gap_14[4 * a3] >= 0x96u )
      *(_WORD *)&this->gap_14[4 * a3] = 0;
    else
      *(_WORD *)&this->gap_14[4 * a3 + 2] = iFoundIdx;
    if ( a3 == 1 )
    {
      *(_WORD *)this->gap_14 = 0;
      *(_WORD *)&this->gap_14[2] = 0;
    }
  }
  return v31 >= 0;
}


// address=[0x14ff140]
// Decompiled from int __thiscall IBuildingRole::Decrease(IBuildingRole *this, int a2)
int  IBuildingRole::Decrease(int a2) {
  
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
void  IBuildingRole::TakeJobTrigger(int a2) {
  
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
void  IBuildingRole::PostLoadSetWaterFlags(class CBuilding * a2) {
  
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
  result = IEntity::FlagBits(a2, (EntityFlag)&MEMORY[0x4000000]);
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
 IBuildingRole::IBuildingRole(std::istream & a2) {
  
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
// Decompiled from struct std::ostream *__thiscall IBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  IBuildingRole::Store(std::ostream & a2) {
  
  struct std::ostream *result; // eax
  int v3; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h]
  struct IBuildingRole *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  CPersistence::Store(this, a2);
  v3 = 4;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned char>(a2, (BYTE *)&v6[1]);
  operator^<unsigned char>(a2, (BYTE *)&v6[1].__vftable + 1);
  operator^<unsigned short>(a2, (WORD *)&v6[1].__vftable + 1);
  operator^<unsigned short>(a2, (WORD *)&v6[2]);
  operator^<short>(a2, (__int16 *)&v6[2].__vftable + 1);
  operator^<unsigned short>(a2, (WORD *)&v6[3]);
  operator^<int>(a2, (int *)&v6[4]);
  operator^<unsigned short>(a2, (WORD *)&v6[5]);
  operator^<unsigned short>(a2, (WORD *)&v6[5].__vftable + 1);
  operator^<unsigned short>(a2, (WORD *)&v6[6]);
  operator^<unsigned short>(a2, (WORD *)&v6[6].__vftable + 1);
  operator^<bool>(a2, (char *)&v6[7]);
  operator^<bool>(a2, (char *)&v6[7].__vftable + 1);
  operator^<unsigned char>(a2, (BYTE *)&v6[89]);
  operator^<unsigned char>(a2, (BYTE *)&v6[89].__vftable + 1);
  operator^<unsigned char>(a2, (BYTE *)&v6[89].__vftable + 2);
  operator^<unsigned char>(a2, (BYTE *)&v6[89].__vftable + 3);
  operator^<short>(a2, (__int16 *)&v6[90]);
  operator^<short>(a2, (__int16 *)&v6[90].__vftable + 1);
  operator^<unsigned char>(a2, (BYTE *)&v6[91]);
  operator^<unsigned char>(a2, (BYTE *)&v6[91].__vftable + 1);
  v4 = (int)v6[92].__vftable;
  operator^<int>(a2, &v4);
  operator^<unsigned char>(a2, (BYTE *)&v6[93]);
  result = operator^<unsigned char>(a2, (BYTE *)&v6[93].__vftable + 1);
  for ( i = 0; i < 0xA; ++i )
  {
    operator^<unsigned int>(a2, (int *)&v6[2 * i + 19]);
    operator^<unsigned int>(a2, (int *)&v6[2 * i + 20]);
    result = (struct std::ostream *)(i + 1);
  }
  for ( i = 0; i < 0xA; ++i )
  {
    operator^<unsigned char>(a2, (BYTE *)&v6[5 * i + 39].__vftable + 1);
    operator^<unsigned char>(a2, (BYTE *)&v6[5 * i + 39].__vftable + 2);
    operator^<unsigned char>(a2, (BYTE *)&v6[5 * i + 39].__vftable + 3);
    operator^<unsigned int>(a2, (int *)&v6[5 * i + 40]);
    operator^<unsigned char>(a2, (BYTE *)&v6[5 * i + 41]);
    operator^<unsigned char>(a2, (BYTE *)&v6[5 * i + 41].__vftable + 1);
    operator^<unsigned char>(a2, (BYTE *)&v6[5 * i + 39]);
    v4 = (int)v6[5 * i + 42].__vftable;
    operator^<int>(a2, &v4);
    operator^<unsigned char>(a2, (BYTE *)&v6[5 * i + 43]);
    operator^<unsigned char>(a2, (BYTE *)&v6[5 * i + 43].__vftable + 1);
    result = (struct std::ostream *)(i + 1);
  }
  return result;
}


// address=[0x14ffe90]
// Decompiled from void __thiscall IBuildingRole::KillInhabitant(IBuildingRole *this, struct CBuilding *a2)
void  IBuildingRole::KillInhabitant(class CBuilding * a2) {
  
  ;
}


// address=[0x14ffea0]
// Decompiled from void __thiscall IBuildingRole::InitCommon(IBuildingRole *this, IEntity *a2)
void  IBuildingRole::InitCommon(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-Ch]
  __int16 v5; // [esp-4h] [ebp-8h]
  int v6; // [esp-4h] [ebp-8h]

  this->m_uSettlerId = 0;
  this->m_bInhabitants = 0;
  this->byte5 = 0;
  IBuildingRole::WorkingAreaChanged(this);
  IEntity::ClearFlagBits(a2, ENTITY_FLAG_Birth);
  IEntity::SetFlagBits(a2, ENTITY_FLAG_Ready);
  v5 = IEntity::ID(a2);
  v4 = IEntity::Y(a2);
  v2 = IEntity::X(a2);
  CWorldManager::SetMapObjectId(v2, v4, v5);
  v6 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
  v3 = IEntity::Race(a2);
  this->m_pBuildingInfo = (const struct CBuildingInfoMgr::SBuildingInfos *)CBuildingInfoMgr::GetBuildingInfo(v3, v6);
  this->m_iEntityId = IEntity::ID(a2);
  a2->Increase(a2, *((unsigned __int8 *)this->m_pBuildingInfo + 500));
  IBuildingRole::InitHousePatches((int)this);
}


// address=[0x14fff70]
// Decompiled from void *__thiscall IBuildingRole::InitHousePatches(IBuildingRole *this)
void  IBuildingRole::InitHousePatches(void) {
  
  void *result; // eax
  CBuilding *v2; // eax
  unsigned int v3; // eax
  int v4; // [esp-4h] [ebp-1Ch]
  char v5; // [esp+4h] [ebp-14h]
  char BuildingJobFrameCount; // [esp+8h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]

  if ( !this->m_pBuildingInfo
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1008, "m_pBuildingInfo != 0") == 1 )
  {
    __debugbreak();
  }
  result = memset(&this->gap_4c[20], 0, 0xC8u);
  for ( i = 0; i < 0xA; ++i )
  {
    if ( *((_DWORD *)this->m_pBuildingInfo + 4 * i + 126) )
    {
      v8 = *((unsigned __int8 *)this->m_pBuildingInfo + 16 * i + 508);
      this->gap_4c[5 * v8 + 21] = *((_DWORD *)this->m_pBuildingInfo + 4 * i + 126);
      BYTE2(this->gap_4c[5 * v8 + 20]) = *((_BYTE *)this->m_pBuildingInfo + 16 * i + 509);
      this->gap_4c[5 * v8 + 23] = *((_DWORD *)this->m_pBuildingInfo + 4 * i + 128);
      BYTE1(this->gap_4c[5 * v8 + 24]) = *((_BYTE *)this->m_pBuildingInfo + 16 * i + 517);
      LOBYTE(this->gap_4c[5 * v8 + 24]) = *((_BYTE *)this->m_pBuildingInfo + 16 * i + 516);
      if ( (this->gap_4c[5 * v8 + 23] & 0x80000000) != 0 && (int)this->gap_4c[5 * v8 + 23] >= 109 )
      {
        if ( BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1035, "0") == 1 )
          __debugbreak();
        this->gap_4c[5 * v8 + 23] = 0;
      }
      BYTE1(this->gap_4c[5 * v8 + 22]) = 0;
      v5 = *((_BYTE *)this->m_pBuildingInfo + 16 * i + 509);
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          this->gap_4c[2 * v8] = *((_DWORD *)this->m_pBuildingInfo + 4 * i + 126);
          this->gap_4c[2 * v8 + 1] = 0;
          BYTE1(this->gap_4c[5 * v8 + 20]) = *((_BYTE *)this->m_pBuildingInfo + 16 * i + 510);
          HIBYTE(this->gap_4c[5 * v8 + 20]) = *((_BYTE *)this->m_pBuildingInfo + 16 * i + 510);
          LOBYTE(this->gap_4c[5 * v8 + 22]) = 0;
          LOBYTE(this->gap_4c[5 * v8 + 20]) = 1;
        }
        else if ( v5 == 2 )
        {
          BuildingJobFrameCount = *((_BYTE *)this->m_pBuildingInfo + 16 * i + 510);
          if ( !BuildingJobFrameCount )
          {
            v4 = this->gap_4c[5 * v8 + 21];
            v2 = CBuildingMgr::operator[]((unsigned __int16)this->m_iEntityId);
            v3 = IEntity::Race(v2);
            BuildingJobFrameCount = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v3, v4);
          }
          LOBYTE(this->gap_4c[5 * v8 + 22]) = BuildingJobFrameCount;
          BYTE1(this->gap_4c[5 * v8 + 20]) = 0;
          LOBYTE(this->gap_4c[5 * v8 + 20]) = 0;
        }
      }
      else
      {
        this->gap_4c[2 * v8] = *((_DWORD *)this->m_pBuildingInfo + 4 * i + 126);
        this->gap_4c[2 * v8 + 1] = 0;
        if ( *((_BYTE *)this->m_pBuildingInfo + 16 * i + 510) )
          LOBYTE(this->gap_4c[5 * v8 + 20]) = 1;
        else
          LOBYTE(this->gap_4c[5 * v8 + 20]) = 0;
      }
    }
    result = (void *)(i + 1);
  }
  return result;
}


// address=[0x1500310]
// Decompiled from char __thiscall IBuildingRole::OrderInhabitant(IBuildingRole *this, IEntity *a2)
bool  IBuildingRole::OrderInhabitant(class CBuilding * a2) {
  
  int v2; // eax
  CEcoSector *v4; // eax
  int v5; // [esp-8h] [ebp-10h]
  int v6; // [esp-4h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-8h]

  if ( this->m_uSettlerId )
    return 1;
  v2 = CBuilding::EnsignWorldIdx((CBuilding *)a2);
  v7 = CWorldManager::EcoSectorId(v2);
  if ( !v7 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 255, "m_iESId != 0") == 1 )
    __debugbreak();
  if ( !v7 )
    return 0;
  v6 = *((char *)this->m_pBuildingInfo + 478);
  v5 = IEntity::ID(a2);
  v4 = (CEcoSector *)CEcoSectorMgr::operator[](g_cESMgr, v7);
  this->m_uSettlerId = CEcoSector::OrderWorker(v4, v5, v6);
  if ( this->m_uSettlerId )
    return 1;
  IAnimatedEntity::RegisterForLogicUpdate((IAnimatedEntity *)a2, 31);
  return 0;
}


// address=[0x15003d0]
// Decompiled from void __thiscall IBuildingRole::MiniFlag(IBuildingRole *this, struct SGfxObjectInfo *arg0, int a3)
void  IBuildingRole::MiniFlag(struct SGfxObjectInfo & arg0, int a3) {
  
  CBuilding *v3; // eax
  DWORD v4; // eax
  unsigned int v5; // [esp-8h] [ebp-2F8h]
  int iAmount; // [esp+8h] [ebp-2E8h]
  struct SGfxObjectInfo a2; // [esp+10h] [ebp-2E0h] BYREF
  int v9; // [esp+2ECh] [ebp-4h]

  if ( this->m_bInhabitants )
  {
    if ( dword_40F21B0 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_40F21B0);
      if ( dword_40F21B0 == -1 )
      {
        dword_40F21AC = CGfxManager::GetObjectFrameCount(g_pGfxManager, 544);
        v9 = -1;
        j___Init_thread_footer(&dword_40F21B0);
      }
    }
    if ( CGameData::GetTickCounter(g_pGameData) - IBuildingRole::m_iLastMiniFlagUpdateTick > 0 )
    {
      IBuildingRole::m_iLastMiniFlagUpdateTick = CGameData::GetTickCounter(g_pGameData);
      ++dword_40F21A8;
      dword_40F21A8 = (int)dword_40F21A8 % dword_40F21AC;
    }
    v3 = CBuildingMgr::operator[]((unsigned __int16)this->m_iEntityId);
    if ( IEntity::FlagBits((IEntity *)v3, 0x1000) )
      iAmount = 1;
    else
      iAmount = 2;
    v5 = dword_40F21A8;
    v4 = CPlayerManager::Color(a3);
    CGfxManager::GetObjectGfxInfo(g_pGfxManager, &a2, v4 + 544, v5, iAmount);
    arg0->m_pMiniFlagGfxData = a2.m_pGfxData;
    arg0->m_pMiniFlagPalData = a2.m_pPalData;
    arg0->m_iOffsetX = this->m_pBuildingInfo->m_iMiniFlagXOffset;
    arg0->m_iOffsetY = this->m_pBuildingInfo->m_iMiniFlagYOffset;
  }
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
void  IBuildingRole::DetachWithoutNotify(class CBuilding * a2, int a3) {
  
  CBuilding::DetachWithoutNotify(a2, a3);
}


// address=[0x40f21a4]
// [Decompilation failed for static int IBuildingRole::m_iLastMiniFlagUpdateTick]

// address=[0x14e6830]
// Decompiled from void __thiscall IBuildingRole::NotifyDetach(IBuildingRole *this, struct CBuilding *a2, int a3)
void  IBuildingRole::NotifyDetach(class CBuilding * a2, int a3) {
  
  ;
}


