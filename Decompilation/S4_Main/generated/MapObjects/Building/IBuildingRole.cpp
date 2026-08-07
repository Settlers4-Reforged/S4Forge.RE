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
// Decompiled from void *__thiscall IBuildingRole::GetPileIdWithNeedForGood(IBuildingRole *this, const struct type_info *a2)
int  IBuildingRole::GetPileIdWithNeedForGood(int a2)const {
  
  return this->GetPileIdWithGood(this, a2);
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
  
  this->InhabitantFlee(this, this->m_uSettlerId);
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
  this->m_uLogicState = 0;
  this->m_iDelayTick = 0;
  this->m_iEntityId = 0;
  this->m_uSettlerId = 0;
  this->m_iLastTick = 0;
  this->m_iFoundSearch = 0;
  this->m_iFoundWorkAreaItemXY = 0;
  this->m_bInhabitants = 0;
  this->byte16D = 0;
  this->m_pBuildingInfo = 0;
  for ( i = 0;
        i < 0xA;
        ++i )
  {
    this->m_vPatchPairs[i].m_uJobId = 0;
    this->m_vPatchPairs[i].m_iJobFrame = 0;
  }
  IBuildingRole::WorkingAreaChanged(this);
  this->m_uEffectId = 0;
  this->m_pSearchFkt = 0;
  return this;
}


// address=[0x14fdfb0]
// Decompiled from void __thiscall IBuildingRole::Update(struct IBuildingRole *this, struct CBuilding *_pBuilding)
void  IBuildingRole::Update(class CBuilding * _pBuilding) {
  
  __int16 TickCounter; // si
  DWORD v3; // eax
  unsigned __int8 iNext; // al
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int BuildingJobFrameCount; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  int m_uSoundRandomness; // esi
  int v11; // eax
  int m_iEffectSoundRandomness; // esi
  int v13; // eax
  int v14; // [esp-Ch] [ebp-34h]
  int v15; // [esp-8h] [ebp-30h]
  int v16; // [esp-8h] [ebp-30h]
  unsigned int v17; // [esp-4h] [ebp-2Ch]
  unsigned int m_uJobId; // [esp-4h] [ebp-2Ch]
  unsigned int v19; // [esp-4h] [ebp-2Ch]
  unsigned int v20; // [esp-4h] [ebp-2Ch]
  signed int v21; // [esp+Ch] [ebp-1Ch]
  signed int v22; // [esp+10h] [ebp-18h]
  unsigned __int8 iType; // [esp+14h] [ebp-14h]
  int m_uTicks2; // [esp+18h] [ebp-10h]
  unsigned int i; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 v27; // [esp+26h] [ebp-2h]

  TickCounter = CGameData::GetTickCounter(g_pGameData);
  this->m_iLastTick = TickCounter - IAnimatedEntity::LastUpdateTick(_pBuilding);
  if ( !this->m_iLastTick )
  {
    return;
  }
  v3 = CGameData::GetTickCounter(g_pGameData);
  IAnimatedEntity::SetLastUpdateTick(_pBuilding, v3);
  for ( i = 0;
        i < 10;
        ++i )
  {
    if ( !this->m_vPatches[i].m_uU0 )
    {
      continue;
    }
    if ( !IEntity::Race(_pBuilding) || IEntity::Race(_pBuilding) == 1 )
    {
      iNext = this->m_vPatches[i].m_iTick + 1;
      this->m_vPatches[i].m_iTick = iNext;
      if ( iNext <= 2u )
      {
        continue;
      }
      this->m_vPatches[i].m_iTick = 0;
    }
    iType = this->m_vPatches[i].m_iType;
    if ( iType )
    {
      if ( iType == 1 )
      {
        if ( this->m_vPatches[i].m_uDuration )
        {
          m_uJobId = this->m_vPatchPairs[i].m_uJobId;
          v6 = IEntity::Race(_pBuilding);
          BuildingJobFrameCount = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v6, m_uJobId);
          if ( ++this->m_vPatchPairs[i].m_iJobFrame >= BuildingJobFrameCount )
          {
            this->m_vPatchPairs[i].m_iJobFrame = 0;
            if ( !this->m_vPatches[i].m_uTicks2 )
            {
              return;
            }
            m_uTicks2 = this->m_vPatches[i].m_uTicks2;
            this->m_vPatches[i].m_uTicks = m_uTicks2 + j__rand() % ((m_uTicks2 + 1) / 2);
            this->m_vPatches[i].m_uDuration = 0;
            return;
          }
        }
        else if ( this->m_vPatches[i].m_uTicks )
        {
          --this->m_vPatches[i].m_uTicks;
        }
        else
        {
          this->m_vPatches[i].m_uU0 = 1;
          v19 = this->m_vPatchPairs[i].m_uJobId;
          v8 = IEntity::Race(_pBuilding);
          this->m_vPatches[i].m_uDuration = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v8, v19);
          this->m_vPatchPairs[i].m_iJobFrame = 0;
        }
      }
      else if ( iType == 2 && this->m_vPatches[i].m_uDuration )
      {
        if ( ++this->m_vPatches[i].m_uTicks < (int)this->m_vPatches[i].m_uDuration )
        {
          v20 = this->m_vPatchPairs[i].m_uJobId;
          v9 = IEntity::Race(_pBuilding);
          v21 = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v9, v20);
          if ( v21 <= 0 )
          {
            v21 = 1;
          }
          this->m_vPatchPairs[i].m_iJobFrame = (this->m_vPatchPairs[i].m_iJobFrame + 1) % v21;
        }
        else
        {
          this->m_vPatches[i].m_uU0 = 0;
        }
      }
    }
    else
    {
      v17 = this->m_vPatchPairs[i].m_uJobId;
      v5 = IEntity::Race(_pBuilding);
      v22 = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v5, v17);
      if ( v22 <= 0 )
      {
        v22 = 1;
      }
      this->m_vPatchPairs[i].m_iJobFrame = (this->m_vPatchPairs[i].m_iJobFrame + 1) % v22;
    }
    if ( (int)this->m_vPatches[i].m_uSoundId > 0 && this->m_vPatches[i].m_uSoundFrame == this->m_vPatchPairs[i].m_iJobFrame )
    {
      if ( this->m_vPatches[i].m_uSoundRandomness == 100 || (m_uSoundRandomness = this->m_vPatches[i].m_uSoundRandomness, m_uSoundRandomness >= j__rand() % 100) )
      {
        v15 = IEntity::Y(_pBuilding);
        v14 = IEntity::X(_pBuilding);
        CSoundManager::PlayEnvironmentSound(g_pSoundManager, this->m_vPatches[i].m_uSoundId, v14, v15, 0);
      }
    }
  }
  if ( this->m_uEffectId )
  {
    v11 = IEntity::Type(_pBuilding);
    if ( !CBuildingMgr::IsMilitary(v11) )
    {
      v27 = this->m_uMilitaryTick + 1;
      this->m_uMilitaryTick = v27;
      if ( v27 >= (int)this->m_uEffectDuration )
      {
        if ( (this->m_uEffectSmoke & 1) != 0 )
        {
          this->m_uMilitaryTick = 0;
          this->m_iEffectFrame = 0;
          ++this->m_uEffectId;
          if ( (this->m_uEffectSmoke & 0x40) != 0 )
          {
            this->m_uEffectDuration = CGfxManager::GetEffectFrameCount(g_pGfxManager, this->m_uEffectId);
            this->m_uEffectSmoke = 0;
          }
          else
          {
            this->m_uEffectDuration = this->byte16D;
            this->m_uEffectSmoke |= 0x40u;
          }
        }
        else
        {
          this->m_uEffectId = 0;
        }
      }
      else
      {
        this->m_iEffectFrame = (this->m_iEffectFrame + 1) % (int)CGfxManager::GetEffectFrameCount(g_pGfxManager, this->m_uEffectId);
        if ( this->m_iEffectSoundId > 0 && this->m_iEffectSoundFrame == this->m_iEffectFrame )
        {
          if ( this->m_iEffectSoundRandomness == 100 || (m_iEffectSoundRandomness = this->m_iEffectSoundRandomness, m_iEffectSoundRandomness >= j__rand() % 100) )
          {
            v16 = IEntity::Y(_pBuilding);
            v13 = IEntity::X(_pBuilding);
            CSoundManager::PlayEnvironmentSound(g_pSoundManager, this->m_iEffectSoundId, v13, v16, 0);
          }
        }
      }
    }
  }
}


// address=[0x14fe560]
// Decompiled from void __thiscall IBuildingRole::Switch(IBuildingRole *this)
void  IBuildingRole::Switch(void) {
  
  CBuilding *v1; // eax
  CBuilding *v2; // eax
  CBuilding *v3; // eax
  CEntityEvent v4; // [esp+4h] [ebp-50h] BYREF
  CEntityEvent v5; // [esp+1Ch] [ebp-38h] BYREF
  CEntityEvent *v6; // [esp+34h] [ebp-20h]
  CEntityEvent *v7; // [esp+38h] [ebp-1Ch]
  CBuilding *v8; // [esp+3Ch] [ebp-18h]
  CBuilding *v9; // [esp+40h] [ebp-14h]
  int v11; // [esp+50h] [ebp-4h]

  v1 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  if ( IEntity::FlagBits(v1, (EntityFlag)4096) )
  {
    v2 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
    IEntity::ClearFlagBits(v2, (EntityFlag)4096);
    CEntityEvent::CEntityEvent(&v5, 7u, 0, this->m_iEntityId, 0, 0);
    v11 = 0;
    v7 = &v5;
    v9 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
    v9->Notify(v7);
    v11 = -1;
    CEntityEvent::~CEntityEvent(&v5);
  }
  else
  {
    v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
    IEntity::SetFlagBits(v3, (EntityFlag)4096);
    CEntityEvent::CEntityEvent(&v4, 8u, 0, this->m_iEntityId, 0, 0);
    v11 = 1;
    v6 = &v4;
    v8 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
    v8->Notify(v6);
    v11 = -1;
    CEntityEvent::~CEntityEvent(&v4);
  }
}


// address=[0x14fe6b0]
// Decompiled from void __thiscall IBuildingRole::InhabitantFlee(IBuildingRole *this, int _iSettlerId)
void  IBuildingRole::InhabitantFlee(int _iSettlerId) {
  
  CBuilding *v2; // eax

  if ( !this->m_uSettlerId && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1285, "m_uSettlerId") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uSettlerId != _iSettlerId && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1286, "m_uSettlerId == _iSettlerId") == 1 )
  {
    __debugbreak();
  }
  this->m_uLogicState = 1;
  this->m_iDelayTick = 0;
  this->m_uSettlerId = 0;
  v2 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  IAnimatedEntity::RegisterForLogicUpdate(v2, 1);
  this->m_bInhabitants = 0;
}


// address=[0x14fe750]
// Decompiled from void __thiscall IBuildingRole::ReturnBuildingMaterial(IBuildingRole *this, struct CBuilding *a2)
void  IBuildingRole::ReturnBuildingMaterial(class CBuilding * a2) {
  
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-Ch] [ebp-20h]
  unsigned int v7; // [esp-Ch] [ebp-20h]
  unsigned int v8; // [esp-Ch] [ebp-20h]
  int v9; // [esp-4h] [ebp-18h]
  CBuildingInfoMgr::SBuildingInfos *BuildingInfo; // [esp+4h] [ebp-10h]
  signed int v11; // [esp+8h] [ebp-Ch]
  signed int v12; // [esp+Ch] [ebp-8h]
  signed int v13; // [esp+10h] [ebp-4h]

  v9 = CBuilding::BuildingTypeEx(a2);
  v2 = IEntity::Race(a2);
  BuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v2, v9);
  v13 = BuildingInfo->m_iBoards / 2;
  v12 = BuildingInfo->m_iStone / 2;
  v11 = BuildingInfo->m_iGold / 2;
  while ( v13 )
  {
    v6 = IEntity::Y(a2);
    v3 = IEntity::X(a2);
    if ( v13 <= 8 )
    {
      CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v3, v6, 7u, v13);
      v13 = 0;
    }
    else
    {
      CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v3, v6, 7u, 8u);
      v13 -= 8;
    }
  }
  while ( v12 )
  {
    v7 = IEntity::Y(a2);
    v4 = IEntity::X(a2);
    if ( v12 <= 8 )
    {
      CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v4, v7, 0x20u, v12);
      v12 = 0;
    }
    else
    {
      CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v4, v7, 0x20u, 8u);
      v12 -= 8;
    }
  }
  while ( v11 )
  {
    v8 = IEntity::Y(a2);
    v5 = IEntity::X(a2);
    if ( v11 <= 8 )
    {
      CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v5, v8, 0xEu, v11);
      v11 = 0;
    }
    else
    {
      CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v5, v8, 0xEu, 8u);
      v11 -= 8;
    }
  }
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
  CBuilding *rBuilding; // [esp+14h] [ebp-18h]
  int v14; // [esp+1Ch] [ebp-10h] BYREF
  int v15; // [esp+20h] [ebp-Ch] BYREF
  CSettler *rSettler; // [esp+24h] [ebp-8h]
  char bPositionFound; // [esp+2Bh] [ebp-1h]

  if ( this->m_uSettlerId )
  {
    rSettler = CSettlerMgr::operator[](this->m_uSettlerId);
    rBuilding = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
    v2 = IEntity::PackedXY(rSettler);
    if ( v2 == IEntity::PackedXY(rBuilding) )
    {
      if ( !IEntity::FlagBits(rSettler, ENTITY_FLAG_ON_BOARD) && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 310, "rSettler.FlagBits(ENTITY_FLAG_ON_BOARD) != 0") == 1 )
      {
        __debugbreak();
      }
      bPositionFound = 0;
      v14 = CBuilding::DoorX(rBuilding);
      v15 = CBuilding::DoorY(rBuilding);
      v10 = CWorldManager::EcoSectorId(v14, v15);
      EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, v10);
      if ( EcoSectorPtr )
      {
        v3 = CEcoSector::Owner(EcoSectorPtr);
        if ( v3 == IEntity::OwnerId(rSettler) )
        {
          bPositionFound = CSettlerMgr::SearchFreePositionInEcoSector(&g_cSettlerMgr, &v14, &v15, v10);
        }
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
          if ( v5 == IEntity::OwnerId(rSettler) )
          {
            bPositionFound = CSettlerMgr::SearchFreePositionInEcoSector(&g_cSettlerMgr, &v14, &v15, v8);
          }
        }
      }
      if ( !bPositionFound && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 336, "bPositionFound") == 1 )
      {
        __debugbreak();
      }
      v6 = Y16X16::PackXYFast(v14, v15);
      rSettler->PlaceInMapObjectLayer(rSettler, v6);
    }
    else if ( IEntity::FlagBits(rSettler, ENTITY_FLAG_ON_BOARD) && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 342, "rSettler.FlagBits(ENTITY_FLAG_ON_BOARD) == 0") == 1 )
    {
      __debugbreak();
    }
    IEntity::SetFlagBits(rSettler, ENTITY_FLAG_Visible);
    IEntity::ClearFlagBits(rSettler, ENTITY_FLAG_MagicInvisible);
    IEntity::ClearFlagBits(rSettler, ENTITY_FLAG_ON_BOARD);
    this->m_uSettlerId = 0;
  }
}


// address=[0x14feaf0]
// Decompiled from bool __thiscall IBuildingRole::SearchInWorkingArea(IBuildingRole *this, CBuilding *_pBuilding, unsigned int a3)
bool  IBuildingRole::SearchInWorkingArea(class CBuilding * _pBuilding, int a3) {
  
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
  int iWACenterY; // [esp+14h] [ebp-64h]
  int iWACenterX; // [esp+18h] [ebp-60h]
  int v19; // [esp+20h] [ebp-58h]
  int v20; // [esp+24h] [ebp-54h]
  int iES; // [esp+28h] [ebp-50h]
  int iIterMaxSpiralOfset; // [esp+2Ch] [ebp-4Ch]
  int iOffsetY; // [esp+34h] [ebp-44h]
  int iOffsetX; // [esp+38h] [ebp-40h]
  int v25; // [esp+3Ch] [ebp-3Ch]
  int iPrevSpiralOffset; // [esp+40h] [ebp-38h]
  int v27; // [esp+44h] [ebp-34h]
  int iMsgTextId; // [esp+48h] [ebp-30h]
  int iLastSpiralOffset; // [esp+50h] [ebp-28h]
  int iFoundIdx; // [esp+54h] [ebp-24h]
  int v31; // [esp+58h] [ebp-20h]
  int j; // [esp+5Ch] [ebp-1Ch]
  bool bNothingFoundInArea; // [esp+62h] [ebp-16h]
  int i; // [esp+64h] [ebp-14h]
  unsigned int iX; // [esp+68h] [ebp-10h]
  int v36; // [esp+68h] [ebp-10h]
  unsigned int iY; // [esp+6Ch] [ebp-Ch]
  int v38; // [esp+6Ch] [ebp-Ch]

  v19 = IEntity::OwnerId(_pBuilding);
  IAIDifficultyLevels::GetDifficultyLevel(v19);
  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(_pBuilding);
  iWACenterX = Y16X16::UnpackXFast(WorkingAreaPackedXY);
  v4 = CBuilding::GetWorkingAreaPackedXY(_pBuilding);
  iWACenterY = Y16X16::UnpackYFast(v4);
  v31 = -1;
  iFoundIdx = -1;
  m_iBuildingInhabitant = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
  v5 = IEntity::Race(_pBuilding);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v5, m_iBuildingInhabitant);
  iOffsetX = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, a3)->m_iOffsetX;
  v14 = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
  v7 = IEntity::Race(_pBuilding);
  v8 = CSettlerMgr::GetSettlerInfo(v7, v14);
  iOffsetY = std::vector<CSettlerMgr::SSearchInfos>::operator[](&v8->m_vSearches, a3)->m_iOffsetY;
  iLastSpiralOffset = CSpiralOffsets::Last(this->m_pBuildingInfo->m_iWorkingAreaRadius);
  v9 = CBuilding::EnsignWorldIdx(_pBuilding);
  iES = CWorldManager::EcoSectorId(v9);
  if ( this->m_pSearchFkt )
  {
    if ( this->m_vWorkingArea[2 * a3 + 1] < this->m_vWorkingArea[2 * a3] + 75 )
    {
      this->m_vWorkingArea[2 * a3 + 1] = this->m_vWorkingArea[2 * a3] + 75;
    }
    for ( i = 0;
          i < 2;
          ++i )
    {
      if ( i )
      {
        iIterMaxSpiralOfset = 50;
      }
      else
      {
        iIterMaxSpiralOfset = 75;
      }
      v27 = iIterMaxSpiralOfset;
      iPrevSpiralOffset = this->m_vWorkingArea[2 * a3 + i];
      if ( iIterMaxSpiralOfset + iPrevSpiralOffset >= iLastSpiralOffset )
      {
        v27 = iLastSpiralOffset - iPrevSpiralOffset;
      }
      for ( j = 0;
            j < v27;
            ++j )
      {
        iX = iWACenterX + CSpiralOffsets::DeltaX(j + iPrevSpiralOffset);
        iY = iWACenterY + CSpiralOffsets::DeltaY(j + iPrevSpiralOffset);
        if ( CWorldManager::InWorld(iX, iY) && CWorldManager::EcoSectorId(iOffsetX + iX, iOffsetY + iY) == iES )
        {
          v25 = this->m_pSearchFkt(iX, iY, 0);
          if ( v25 > 0 )
          {
            this->m_iFoundWorkAreaItemXY = Y16X16::PackXYFast(iOffsetX + iX, iOffsetY + iY);
            this->m_iFoundSearch = v25;
            v31 = i;
            iFoundIdx = j + iPrevSpiralOffset;
            break;
          }
          if ( v25 < 0 )
          {
            v36 = iOffsetX + iX;
            v38 = iOffsetY + iY;
            if ( CWorldManager::EcoSectorId(v36, v38) == iES )
            {
              this->m_iFoundWorkAreaItemXY = Y16X16::PackXYFast(v36, v38);
              this->m_iFoundSearch = 0;
              v31 = i;
              iFoundIdx = j + iPrevSpiralOffset;
              break;
            }
          }
        }
      }
      this->m_vWorkingArea[2 * a3 + i] += j;
      if ( v31 >= 0 )
      {
        break;
      }
    }
  }
  if ( this->m_pBuildingInfo->m_iWorkingAreaRadius < 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 618, "m_pBuildingInfo->workingAreaRadius >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_pBuildingInfo->m_iWorkingAreaRadius >= 75 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 619, "m_pBuildingInfo->workingAreaRadius < SPIRAL_RADIUS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( v31 < 0 )
  {
    bNothingFoundInArea = this->m_vWorkingArea[0] >= iLastSpiralOffset;
    if ( this->m_vWorkingArea[2 * a3] < iLastSpiralOffset )
    {
      if ( this->m_vWorkingArea[2 * a3 + 1] >= iLastSpiralOffset )
      {
        this->m_vWorkingArea[2 * a3 + 1] = 0;
      }
    }
    else
    {
      this->m_vWorkingArea[2 * a3] = 0;
      this->m_vWorkingArea[2 * a3 + 1] = 0;
    }
    if ( bNothingFoundInArea )
    {
      if ( this->m_bHasWarnedAboutEmptyWA )
      {
        this->m_bHasWarnedAboutEmptyWA = 0;
        iMsgTextId = 3837;
        v20 = IEntity::Type(_pBuilding);
        if ( v20 == BUILDING_WOODCUTTERHUT )
        {
          iMsgTextId = 2554;
        }
        else if ( v20 == BUILDING_STONECUTTERHUT )
        {
          iMsgTextId = 2543;
        }
        if ( iMsgTextId != 3837 )
        {
          v10 = IEntity::OwnerId(_pBuilding);
          if ( v10 == CPlayerManager::GetLocalPlayerId() )
          {
            v16 = IEntity::Y(_pBuilding);
            v15 = IEntity::X(_pBuilding);
            v11 = IEntity::OwnerId(_pBuilding);
            CTextMsgHandler::AddWarningMsg(iMsgTextId, v11, v15, v16);
          }
        }
      }
      else
      {
        this->m_bHasWarnedAboutEmptyWA = 1;
      }
    }
  }
  else
  {
    if ( iFoundIdx < 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 625, "iFoundIdx >= 0") == 1 )
    {
      __debugbreak();
    }
    this->m_bHasWarnedAboutEmptyWA = 0;
    if ( !v31 || iFoundIdx <= 150 || this->m_vWorkingArea[2 * a3] >= 150u )
    {
      this->m_vWorkingArea[2 * a3] = 0;
    }
    else
    {
      this->m_vWorkingArea[2 * a3 + 1] = iFoundIdx;
    }
    if ( a3 == 1 )
    {
      this->m_vWorkingArea[0] = 0;
      this->m_vWorkingArea[1] = 0;
    }
  }
  return v31 >= 0;
}


// address=[0x14ff140]
// Decompiled from int __thiscall IBuildingRole::Decrease(IBuildingRole *this, int a2)
int  IBuildingRole::Decrease(int a2) {
  
  int v3; // [esp+Ch] [ebp+8h]

  if ( a2 <= 0 )
  {
    return 0;
  }
  v3 = (a2 - 5) / 2;
  if ( v3 <= 0 )
  {
    return 1;
  }
  return v3;
}


// address=[0x14ff180]
// Decompiled from void __thiscall IBuildingRole::TakeJobTrigger(IBuildingRole *this, int a2)
void  IBuildingRole::TakeJobTrigger(int a2) {
  
  int v2; // eax
  int m_uSoundRandomness; // esi
  unsigned int v4; // eax
  int v5; // [esp-Ch] [ebp-38h]
  int v6; // [esp-8h] [ebp-34h]
  unsigned int m_uJobId; // [esp-4h] [ebp-30h]
  int v8; // [esp+Ch] [ebp-20h]
  CBuilding *v9; // [esp+14h] [ebp-18h]
  unsigned __int8 m_iDuration; // [esp+1Ch] [ebp-10h]
  CBuildingInfoMgr::STriggerInfos *TriggerInfo; // [esp+20h] [ebp-Ch]
  int m_iSlot; // [esp+24h] [ebp-8h]

  v9 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  v2 = IEntity::Race(v9);
  TriggerInfo = CBuildingInfoMgr::GetTriggerInfo(v2, a2);
  if ( TriggerInfo->m_iPatchDefine <= 0 )
  {
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
        this->m_vPatchPairs[a2 - 17].m_uJobId = this->m_vPatches[a2 - 17].m_uJob;
        this->m_vPatches[a2 - 17].m_uU0 = 1;
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
        *((_BYTE *)&this[-1] + 20 * a2 - 4) = 0;
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
        v8 = a2 - 37;
        this->m_vPatchPairs[a2 - 37].m_uJobId = 0;
        this->m_vPatchPairs[v8].m_iJobFrame = 0;
        this->m_vPatches[v8].m_uU0 = 0;
        this->m_vPatches[v8].m_uTicks = 0;
        break;
      default:
        break;
    }
  }
  else
  {
    m_iSlot = TriggerInfo->m_iSlot;
    this->m_vPatchPairs[m_iSlot].m_uJobId = TriggerInfo->m_iPatchDefine;
    this->m_vPatchPairs[m_iSlot].m_iJobFrame = 0;
    this->m_vPatches[m_iSlot].m_uJob = TriggerInfo->m_iPatchDefine;
    this->m_vPatches[m_iSlot].m_iType = 2;
    this->m_vPatches[m_iSlot].m_uSoundId = TriggerInfo->m_iPatchSoundId;
    this->m_vPatches[m_iSlot].m_uSoundFrame = TriggerInfo->m_iPatchSoundFrame;
    this->m_vPatches[m_iSlot].m_uSoundRandomness = TriggerInfo->m_iPatchSoundRandomness;
    if ( (this->m_vPatches[m_iSlot].m_uSoundId & 0x80000000) != 0 && (int)this->m_vPatches[m_iSlot].m_uSoundId >= 109 )
    {
      BBSupportTracePrintF(0, "Wrong sound id!!!");
      this->m_vPatches[m_iSlot].m_uSoundId = 0;
    }
    if ( (int)this->m_vPatches[m_iSlot].m_uSoundId > 0 && this->m_vPatches[m_iSlot].m_uSoundFrame == this->m_vPatchPairs[m_iSlot].m_iJobFrame )
    {
      if ( this->m_vPatches[m_iSlot].m_uSoundRandomness == 100 || (m_uSoundRandomness = this->m_vPatches[m_iSlot].m_uSoundRandomness, m_uSoundRandomness >= j__rand() % 100) )
      {
        v6 = IEntity::Y(v9);
        v5 = IEntity::X(v9);
        CSoundManager::PlayEnvironmentSound(g_pSoundManager, this->m_vPatches[m_iSlot].m_uSoundId, v5, v6, 0);
      }
    }
    m_iDuration = TriggerInfo->m_iDuration;
    if ( !m_iDuration )
    {
      m_uJobId = this->m_vPatchPairs[m_iSlot].m_uJobId;
      v4 = IEntity::Race(v9);
      m_iDuration = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v4, m_uJobId);
    }
    this->m_vPatches[m_iSlot].m_uDuration = m_iDuration;
    this->m_vPatches[m_iSlot].m_uTicks = 0;
    this->m_vPatches[m_iSlot].m_uU0 = 1;
  }
  if ( (int)TriggerInfo->m_iEffectId > 0 )
  {
    this->m_uEffectId = TriggerInfo->m_iEffectId;
    this->m_uEffectDuration = TriggerInfo->m_iEffectDuration;
    this->m_iEffectFrame = 0;
    this->m_uMilitaryTick = 0;
    this->m_uEffectX = TriggerInfo->m_iEffectX;
    this->m_uEffectY = TriggerInfo->m_iEffectY;
    this->m_uEffectSmoke = TriggerInfo->m_bEffectSmoke;
    if ( this->m_uEffectSmoke )
    {
      --this->m_uEffectId;
      this->byte16D = this->m_uEffectDuration;
      this->m_uEffectDuration = CGfxManager::GetEffectFrameCount(g_pGfxManager, this->m_uEffectId);
    }
    this->m_iEffectSoundId = TriggerInfo->m_iEffectSoundId;
    this->m_iEffectSoundFrame = TriggerInfo->m_iEffectUnknown;
    this->m_iEffectSoundRandomness = TriggerInfo->m_iEffectSoundRandomness;
  }
}


// address=[0x14ff580]
// Decompiled from void __thiscall IBuildingRole::PostLoadSetWaterFlags(IBuildingRole *this, IEntity *a2)
void  IBuildingRole::PostLoadSetWaterFlags(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // [esp-10h] [ebp-30h]
  int m_iHotSpotX; // [esp-Ch] [ebp-2Ch]
  int m_iHotSpotY; // [esp-8h] [ebp-28h]
  std::vector *p_m_vWaterRepealingPosLines; // [esp-4h] [ebp-24h]
  int v8; // [esp-4h] [ebp-24h]
  CBuildingFlagsWalk v9; // [esp+0h] [ebp-20h] BYREF

  if ( !IEntity::FlagBits(a2, ENTITY_FLAG_Died) && this->m_pBuildingInfo && this->m_pBuildingInfo->m_bIsPort )
  {
    p_m_vWaterRepealingPosLines = &this->m_pBuildingInfo->m_vWaterRepealingPosLines;
    m_iHotSpotY = this->m_pBuildingInfo->m_iHotSpotY;
    m_iHotSpotX = this->m_pBuildingInfo->m_iHotSpotX;
    v4 = IEntity::Y(a2);
    v2 = IEntity::X(a2);
    CBuildingFlagsWalk::CBuildingFlagsWalk(&v9, v2, v4, m_iHotSpotX, m_iHotSpotY, p_m_vWaterRepealingPosLines);
    while ( CBuildingFlagsWalk::NextPosition(&v9) )
    {
      v8 = CBuildingFlagsWalk::CurrentY(&v9);
      v3 = CBuildingFlagsWalk::CurrentX(&v9);
      g_pTiling->SetBlockedWater(v3, v8);
    }
  }
}


// address=[0x14ff650]
// Decompiled from IBuildingRole *__thiscall IBuildingRole::IBuildingRole(IBuildingRole *this, struct std::istream *a1)
 IBuildingRole::IBuildingRole(std::istream & a2) {
  
  int v3; // [esp+4h] [ebp-14h] BYREF
  int pExceptionObject; // [esp+8h] [ebp-10h] BYREF
  int a2; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int i; // [esp+10h] [ebp-8h]

  CPersistence::CPersistence(this);
  this->__vftable = (IBuildingRole_vtbl *)&IBuildingRole::_vftable_;
  operator^<unsigned int>(a1, &v3);
  if ( v3 != 4 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a1, &this->m_uLogicState);
  operator^<unsigned char>(a1, &this->m_iDelayTick);
  operator^<unsigned short>(a1, &this->m_iEntityId);
  operator^<unsigned short>(a1, &this->m_uSettlerId);
  operator^<short>(a1, &this->m_iLastTick);
  operator^<unsigned short>(a1, &this->m_iFoundSearch);
  operator^<int>(a1, &this->m_iFoundWorkAreaItemXY);
  operator^<unsigned short>(a1, this->m_vWorkingArea);
  operator^<unsigned short>(a1, &this->m_vWorkingArea[1]);
  operator^<unsigned short>(a1, &this->m_vWorkingArea[2]);
  operator^<unsigned short>(a1, &this->m_vWorkingArea[3]);
  operator^<bool>(a1, &this->m_bHasWarnedAboutEmptyWA);
  operator^<bool>(a1, &this->m_bInhabitants);
  operator^<unsigned char>(a1, &this->m_uEffectId);
  operator^<unsigned char>(a1, &this->m_uEffectDuration);
  operator^<unsigned char>(a1, &this->m_uMilitaryTick);
  operator^<unsigned char>(a1, &this->m_iEffectFrame);
  operator^<short>(a1, &this->m_uEffectX);
  operator^<short>(a1, &this->m_uEffectY);
  operator^<unsigned char>(a1, &this->m_uEffectSmoke);
  operator^<unsigned char>(a1, &this->byte16D);
  a2 = 0;
  operator^<int>(a1, &a2);
  this->m_iEffectSoundId = a2;
  operator^<unsigned char>(a1, &this->m_iEffectSoundRandomness);
  operator^<unsigned char>(a1, &this->m_iEffectSoundFrame);
  for ( i = 0;
        i < 0xA;
        ++i )
  {
    operator^<unsigned int>(a1, &this->m_vPatchPairs[i]);
    operator^<unsigned int>(a1, &this->m_vPatchPairs[i].m_iJobFrame);
  }
  for ( i = 0;
        i < 0xA;
        ++i )
  {
    operator^<unsigned char>(a1, &this->m_vPatches[i].m_uTicks);
    operator^<unsigned char>(a1, &this->m_vPatches[i].m_iType);
    operator^<unsigned char>(a1, &this->m_vPatches[i].m_uTicks2);
    operator^<unsigned int>(a1, &this->m_vPatches[i].m_uJob);
    operator^<unsigned char>(a1, &this->m_vPatches[i].m_uDuration);
    operator^<unsigned char>(a1, &this->m_vPatches[i].m_iTick);
    operator^<unsigned char>(a1, &this->m_vPatches[i].m_uU0);
    a2 = 0;
    operator^<int>(a1, &a2);
    this->m_vPatches[i].m_uSoundId = a2;
    operator^<unsigned char>(a1, &this->m_vPatches[i].m_uSoundRandomness);
    operator^<unsigned char>(a1, &this->m_vPatches[i].m_uSoundFrame);
  }
  this->m_pBuildingInfo = 0;
  IBuildingRole::m_iLastMiniFlagUpdateTick = 0;
  return this;
}


// address=[0x14ffaa0]
// Decompiled from void __thiscall IBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *_rStream)
void  IBuildingRole::Store(std::ostream & _rStream) {
  
  unsigned int iFileVersion; // [esp+0h] [ebp-10h] BYREF
  int m_iEffectSoundId; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h]

  CPersistence::Store(this, _rStream);
  iFileVersion = 4;
  operator^<unsigned int>(_rStream, &iFileVersion);
  operator^<unsigned char>(_rStream, &this->m_uLogicState);
  operator^<unsigned char>(_rStream, &this->m_iDelayTick);
  operator^<unsigned short>(_rStream, &this->m_iEntityId);
  operator^<unsigned short>(_rStream, &this->m_uSettlerId);
  operator^<short>(_rStream, &this->m_iLastTick);
  operator^<unsigned short>(_rStream, &this->m_iFoundSearch);
  operator^<int>(_rStream, &this->m_iFoundWorkAreaItemXY);
  operator^<unsigned short>(_rStream, this->m_vWorkingArea);
  operator^<unsigned short>(_rStream, &this->m_vWorkingArea[1]);
  operator^<unsigned short>(_rStream, &this->m_vWorkingArea[2]);
  operator^<unsigned short>(_rStream, &this->m_vWorkingArea[3]);
  operator^<bool>(_rStream, &this->m_bHasWarnedAboutEmptyWA);
  operator^<bool>(_rStream, &this->m_bInhabitants);
  operator^<unsigned char>(_rStream, &this->m_uEffectId);
  operator^<unsigned char>(_rStream, &this->m_uEffectDuration);
  operator^<unsigned char>(_rStream, &this->m_uMilitaryTick);
  operator^<unsigned char>(_rStream, &this->m_iEffectFrame);
  operator^<short>(_rStream, &this->m_uEffectX);
  operator^<short>(_rStream, &this->m_uEffectY);
  operator^<unsigned char>(_rStream, &this->m_uEffectSmoke);
  operator^<unsigned char>(_rStream, &this->byte16D);
  m_iEffectSoundId = this->m_iEffectSoundId;
  operator^<int>(_rStream, &m_iEffectSoundId);
  operator^<unsigned char>(_rStream, &this->m_iEffectSoundRandomness);
  operator^<unsigned char>(_rStream, &this->m_iEffectSoundFrame);
  for ( i = 0;
        i < 10;
        ++i )
  {
    operator^<unsigned int>(_rStream, &this->m_vPatchPairs[i].m_uJobId);
    operator^<unsigned int>(_rStream, &this->m_vPatchPairs[i].m_iJobFrame);
  }
  for ( i = 0;
        i < 0xA;
        ++i )
  {
    operator^<unsigned char>(_rStream, &this->m_vPatches[i].m_uTicks);
    operator^<unsigned char>(_rStream, &this->m_vPatches[i].m_iType);
    operator^<unsigned char>(_rStream, &this->m_vPatches[i].m_uTicks2);
    operator^<unsigned int>(_rStream, &this->m_vPatches[i].m_uJob);
    operator^<unsigned char>(_rStream, &this->m_vPatches[i].m_uDuration);
    operator^<unsigned char>(_rStream, &this->m_vPatches[i].m_iTick);
    operator^<unsigned char>(_rStream, &this->m_vPatches[i].m_uU0);
    m_iEffectSoundId = this->m_vPatches[i].m_uSoundId;
    operator^<int>(_rStream, &m_iEffectSoundId);
    operator^<unsigned char>(_rStream, &this->m_vPatches[i].m_uSoundRandomness);
    operator^<unsigned char>(_rStream, &this->m_vPatches[i].m_uSoundFrame);
  }
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
  this->m_iDelayTick = 0;
  IBuildingRole::WorkingAreaChanged(this);
  IEntity::ClearFlagBits(a2, ENTITY_FLAG_Birth);
  IEntity::SetFlagBits(a2, ENTITY_FLAG_Ready);
  v5 = IEntity::ID(a2);
  v4 = IEntity::Y(a2);
  v2 = IEntity::X(a2);
  CWorldManager::SetMapObjectId(v2, v4, v5);
  v6 = CBuilding::BuildingTypeEx((struct CBuilding *)a2);
  v3 = IEntity::Race(a2);
  this->m_pBuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v3, v6);
  this->m_iEntityId = IEntity::ID(a2);
  a2->Increase(a2, this->m_pBuildingInfo->m_iHealth);
  IBuildingRole::InitHousePatches((int)this);
}


// address=[0x14fff70]
// Decompiled from void __thiscall IBuildingRole::InitHousePatches(IBuildingRole *this)
void  IBuildingRole::InitHousePatches(void) {
  
  CBuilding *v1; // eax
  unsigned int v2; // eax
  unsigned int m_uJob; // [esp-4h] [ebp-1Ch]
  BYTE iType; // [esp+4h] [ebp-14h]
  unsigned __int8 m_iTicks; // [esp+8h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-Ch]
  int m_iSlot; // [esp+10h] [ebp-8h]

  if ( !this->m_pBuildingInfo && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1008, "m_pBuildingInfo != 0") == 1 )
  {
    __debugbreak();
  }
  memset(this->m_vPatches, 0, sizeof(this->m_vPatches));
  for ( i = 0;
        i < 0xA;
        ++i )
  {
    if ( this->m_pBuildingInfo->m_vPatches[i].m_iJob )
    {
      m_iSlot = this->m_pBuildingInfo->m_vPatches[i].m_iSlot;
      this->m_vPatches[m_iSlot].m_uJob = this->m_pBuildingInfo->m_vPatches[i].m_iJob;
      this->m_vPatches[m_iSlot].m_iType = this->m_pBuildingInfo->m_vPatches[i].m_iType;
      this->m_vPatches[m_iSlot].m_uSoundId = this->m_pBuildingInfo->m_vPatches[i].m_iSound;
      this->m_vPatches[m_iSlot].m_uSoundFrame = this->m_pBuildingInfo->m_vPatches[i].m_iSoundFrame;
      this->m_vPatches[m_iSlot].m_uSoundRandomness = this->m_pBuildingInfo->m_vPatches[i].m_iSoundRandomness;
      if ( (this->m_vPatches[m_iSlot].m_uSoundId & 0x80000000) != 0 && (int)this->m_vPatches[m_iSlot].m_uSoundId >= 109 )
      {
        if ( BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 1035, "0") == 1 )
        {
          __debugbreak();
        }
        this->m_vPatches[m_iSlot].m_uSoundId = 0;
      }
      this->m_vPatches[m_iSlot].m_iTick = 0;
      iType = this->m_pBuildingInfo->m_vPatches[i].m_iType;
      if ( iType )
      {
        if ( iType == 1 )
        {
          this->m_vPatchPairs[m_iSlot].m_uJobId = this->m_pBuildingInfo->m_vPatches[i].m_iJob;
          this->m_vPatchPairs[m_iSlot].m_iJobFrame = 0;
          this->m_vPatches[m_iSlot].m_uTicks = this->m_pBuildingInfo->m_vPatches[i].m_iTicks;
          this->m_vPatches[m_iSlot].m_uTicks2 = this->m_pBuildingInfo->m_vPatches[i].m_iTicks;
          this->m_vPatches[m_iSlot].m_uDuration = 0;
          this->m_vPatches[m_iSlot].m_uU0 = 1;
        }
        else if ( iType == 2 )
        {
          m_iTicks = this->m_pBuildingInfo->m_vPatches[i].m_iTicks;
          if ( !m_iTicks )
          {
            m_uJob = this->m_vPatches[m_iSlot].m_uJob;
            v1 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
            v2 = IEntity::Race(v1);
            m_iTicks = CGfxManager::GetBuildingJobFrameCount(g_pGfxManager, v2, m_uJob);
          }
          this->m_vPatches[m_iSlot].m_uDuration = m_iTicks;
          this->m_vPatches[m_iSlot].m_uTicks = 0;
          this->m_vPatches[m_iSlot].m_uU0 = 0;
        }
      }
      else
      {
        this->m_vPatchPairs[m_iSlot].m_uJobId = this->m_pBuildingInfo->m_vPatches[i].m_iJob;
        this->m_vPatchPairs[m_iSlot].m_iJobFrame = 0;
        if ( this->m_pBuildingInfo->m_vPatches[i].m_iTicks )
        {
          this->m_vPatches[m_iSlot].m_uU0 = 1;
        }
        else
        {
          this->m_vPatches[m_iSlot].m_uU0 = 0;
        }
      }
    }
  }
}


// address=[0x1500310]
// Decompiled from char __thiscall IBuildingRole::OrderInhabitant(IBuildingRole *this, CBuilding *a2)
bool  IBuildingRole::OrderInhabitant(class CBuilding * a2) {
  
  int v2; // eax
  CEcoSector *v4; // eax
  int v5; // [esp-8h] [ebp-10h]
  int m_iBuildingInhabitant; // [esp-4h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-8h]

  if ( this->m_uSettlerId )
  {
    return 1;
  }
  v2 = CBuilding::EnsignWorldIdx(a2);
  v7 = CWorldManager::EcoSectorId(v2);
  if ( !v7 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingRole.cpp", 255, "m_iESId != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !v7 )
  {
    return 0;
  }
  m_iBuildingInhabitant = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
  v5 = IEntity::ID(a2);
  v4 = CEcoSectorMgr::operator[](g_cESMgr, v7);
  this->m_uSettlerId = CEcoSector::OrderWorker(v4, v5, m_iBuildingInhabitant);
  if ( this->m_uSettlerId )
  {
    return 1;
  }
  IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
  return 0;
}


// address=[0x15003d0]
// Decompiled from void __thiscall IBuildingRole::MiniFlag(IBuildingRole *this, struct SGfxObjectInfo *_rGfxInfo, int _iPlayer)
void  IBuildingRole::MiniFlag(struct SGfxObjectInfo & _rGfxInfo, int _iPlayer) {
  
  CBuilding *v3; // eax
  DWORD v4; // eax
  unsigned int iFrame; // [esp-8h] [ebp-2F8h]
  int iAmount; // [esp+8h] [ebp-2E8h]
  struct SGfxObjectInfo a2; // [esp+10h] [ebp-2E0h] BYREF
  int v9; // [esp+2ECh] [ebp-4h]

  if ( this->m_bInhabitants )
  {
    if ( dword_40F21B0 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )// Static variable
    {
      j___Init_thread_header(&dword_40F21B0);
      if ( dword_40F21B0 == -1 )
      {
        s_iFlagFrameCount = CGfxManager::GetObjectFrameCount(g_pGfxManager, OBJECT_FLAG01_OBJECT);
        v9 = -1;
        j___Init_thread_footer(&dword_40F21B0);
      }
    }
    if ( CGameData::GetTickCounter(g_pGameData) - IBuildingRole::m_iLastMiniFlagUpdateTick > 0 )
    {
      IBuildingRole::m_iLastMiniFlagUpdateTick = CGameData::GetTickCounter(g_pGameData);
      ++s_iMiniFlagFrameCount;
      s_iMiniFlagFrameCount = (int)s_iMiniFlagFrameCount % s_iFlagFrameCount;
    }
    v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
    if ( IEntity::FlagBits(v3, (EntityFlag)4096) )
    {
      iAmount = 1;
    }
    else
    {
      iAmount = 2;
    }
    iFrame = s_iMiniFlagFrameCount;
    v4 = CPlayerManager::Color(_iPlayer);
    CGfxManager::GetObjectGfxInfo(g_pGfxManager, &a2, v4 + 544, iFrame, iAmount);
    _rGfxInfo->m_pMiniFlagGfxData = a2.m_pGfxData;
    _rGfxInfo->m_pMiniFlagPalData = a2.m_pPalData;
    _rGfxInfo->m_iOffsetX = this->m_pBuildingInfo->m_iMiniFlagXOffset;
    _rGfxInfo->m_iOffsetY = this->m_pBuildingInfo->m_iMiniFlagYOffset;
  }
}


// address=[0x1500590]
// Decompiled from void __thiscall IBuildingRole::WorkingAreaChanged(IBuildingRole *this)
void  IBuildingRole::WorkingAreaChanged(void) {
  
  this->m_vWorkingArea[0] = 0;
  this->m_vWorkingArea[1] = 0;
  this->m_vWorkingArea[2] = 0;
  this->m_vWorkingArea[3] = 0;
  this->m_bHasWarnedAboutEmptyWA = 0;
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


