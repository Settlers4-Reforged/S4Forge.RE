#if FALSE
#include "ISettlerRole.h"

// Definitions for class ISettlerRole

// address=[0x1351b50]
// Decompiled from int __thiscall ISettlerRole::GetTask(ISettlerRole *this)
int  ISettlerRole::GetTask(void)const {
  
  return this->m_iTask;
}


// address=[0x1563710]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::~ISettlerRole(ISettlerRole *this)
 ISettlerRole::~ISettlerRole(void) {
  
  ISettlerRole *result; // eax

  result = this;
  *(_DWORD *)this = &ISettlerRole::_vftable_;
  return result;
}


// address=[0x15637d0]
// Decompiled from void *__thiscall ISettlerRole::ClearGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int  ISettlerRole::ClearGroupFlagBits(int a2) {
  
  return 0;
}


// address=[0x15637f0]
// Decompiled from int __thiscall ISettlerRole::Decrease(ISettlerRole *this, int a2)
int  ISettlerRole::Decrease(int a2) {
  
  return a2;
}


// address=[0x1563810]
// Decompiled from int __thiscall ISettlerRole::GetGroupFlags(ISettlerRole *this)
int  ISettlerRole::GetGroupFlags(void)const {
  
  return 0;
}


// address=[0x1563840]
// Decompiled from int __thiscall ISettlerRole::GetWarriorBehavior(ISettlerRole *this)
class CWarriorBehavior *  ISettlerRole::GetWarriorBehavior(void) {
  
  return 0;
}


// address=[0x1563850]
// Decompiled from int __thiscall ISettlerRole::HomeEntityId(ISettlerRole *this)
int  ISettlerRole::HomeEntityId(void)const {
  
  return this->m_uHomeEntityId;
}


// address=[0x1563930]
// Decompiled from char __thiscall ISettlerRole::IsUnEmployed(ISettlerRole *this)
bool  ISettlerRole::IsUnEmployed(void)const {
  
  return 0;
}


// address=[0x1563940]
// Decompiled from void __thiscall ISettlerRole::SetBuilding(ISettlerRole *this, WORD a2)
void  ISettlerRole::SetBuilding(int a2) {
  
  this->m_uHomeEntityId = a2;
}


// address=[0x15639a0]
// Decompiled from void __thiscall ISettlerRole::SetEntity(ISettlerRole *this, WORD a2)
void  ISettlerRole::SetEntity(int a2) {
  
  this->m_uEntityId = a2;
}


// address=[0x15639e0]
// Decompiled from void *__thiscall ISettlerRole::SetGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int  ISettlerRole::SetGroupFlagBits(int a2) {
  
  return 0;
}


// address=[0x1563a00]
// Decompiled from void *__thiscall ISettlerRole::SetGroupFlags(std::_Ref_count_base *this, const struct type_info *a2)
int  ISettlerRole::SetGroupFlags(int a2) {
  
  return 0;
}


// address=[0x1563a20]
// Decompiled from void __thiscall ISettlerRole::UpdateJob(ISettlerRole *this, struct CSettler *a2)
void  ISettlerRole::UpdateJob(class CSettler * a2) {
  
  ;
}


// address=[0x15671a0]
// Decompiled from int __thiscall ISettlerRole::SourcePileId(ISettlerRole *this)
int  ISettlerRole::SourcePileId(void)const {
  
  return this->m_uSourcePileId;
}


// address=[0x15897e0]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::ISettlerRole(ISettlerRole *this)
 ISettlerRole::ISettlerRole(void) {
  
  CPersistence::CPersistence(this);
  this->__vftable = (ISettlerRole_vtbl *)&ISettlerRole::_vftable_;
  this->m_iTask = 0;
  this->m_uSettlerWalk = 0;
  this->m_iWalkspeed = 1;
  this->m_uCycleFrames = 1;
  this->m_uTick = 0;
  this->unk_0A = 1;
  this->unk_0B = 0;
  this->m_uToDoCount = 0;
  this->m_iDestinationOffsetX = 0;
  this->m_iDestinationOffsetY = 0;
  this->m_uAttachedSettlerId = 0;
  this->m_uSourcePileId = 0;
  this->m_iDestinationPosition = 0;
  this->m_iStartPosition = 0;
  this->m_uHomeEntityId = 0;
  this->m_uEntityId = 0;
  this->m_fOffsetX = 0.0;
  this->m_fOffsetY = 0.0;
  return this;
}


// address=[0x15898a0]
// Decompiled from void __thiscall ISettlerRole::Go(ISettlerRole *this, CSettler *settler)
void  ISettlerRole::Go(class CSettler * settler) {
  
  int v2; // eax
  int v3; // eax
  int moveCosts; // [esp+4h] [ebp-8h]

  this->m_uSettlerWalk = CSettler::Walk(settler);
  if ( (this->m_uSettlerWalk & 0x20) != 0 )
  {
    this->GetNextJob(this, settler);
  }
  else if ( (this->m_uSettlerWalk & 0x40) != 0 )
  {
    this->SetFree(this, settler, -1);
  }
  else if ( (this->m_uSettlerWalk & 0xFu) >= 6 )
  {
    IAnimatedEntity::RegisterForLogicUpdate(settler, 1);
  }
  else
  {
    settler->m_iDistance = -1;
    this->m_iWalkspeed = 9;
    if ( IEntity::Type(settler) == SETTLER_CARRIER || IEntity::Type(settler) == SETTLER_DONKEY )
    {
      v2 = IEntity::PackedXY(settler);
      v3 = CWorldManager::Index(v2);
      moveCosts = CWorldManager::MoveCostsBits(v3);
      if ( moveCosts == 1 )
      {
        this->m_iWalkspeed = 8;
      }
      else if ( !moveCosts )
      {
        this->m_iWalkspeed = 7;
      }
    }
    IAnimatedEntity::RegisterForLogicUpdate(settler, this->m_iWalkspeed);
  }
}


// address=[0x15899a0]
// Decompiled from void __thiscall ISettlerRole::LogicUpdate(ISettlerRole *this, struct CSettler *pSettler)
void  ISettlerRole::LogicUpdate(class CSettler * pSettler) {
  
  int v2; // eax
  DWORD v3; // eax
  int v4; // [esp+10h] [ebp-10h]
  CWalking *v5; // [esp+14h] [ebp-Ch]
  CWalking *v6; // [esp+18h] [ebp-8h]

  if ( this->m_iTask != WAIT )
  {
    this->LogicUpdateJob(this, pSettler);
  }
  else
  {
    pSettler->m_iDistance = 0;
    this->m_uCycleFrames = 1;
    v6 = std::auto_ptr<CWalking>::operator->(&pSettler->m_pWalking);
    v6->InitB((CWalkingBase *)v6, -1, 0);
    v5 = std::auto_ptr<CWalking>::operator->(&pSettler->m_pWalking);
    v2 = v5->Walk(v5, pSettler->m_uPackedXY);
    this->m_uSettlerWalk = CSettler::WalkDir(pSettler, v2);
    if ( (this->m_uSettlerWalk & 0xFu) >= 6 )
    {
      pSettler->m_iFrame = 0;
      v3 = CStateGame::Rand(g_pGame);
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, v3 % 4 + 1);
    }
    else
    {
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(&pSettler->m_cCurrentToDoItemIter);
      this->m_uCycleFrames = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(&pSettler->m_cCurrentToDoItemIter)->m_iFrameCount;
      if ( !this->m_uCycleFrames
        && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 191, "m_iCycleFrames > 0") == 1 )
      {
        __debugbreak();
      }
      if ( this->m_uCycleFrames > 1u )
        v4 = this->m_uCycleFrames - 1;
      else
        v4 = 1;
      if ( v4 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 194, "iCycleFramesEx > 0") == 1 )
        __debugbreak();
      pSettler->m_iFrame = 0;
      pSettler->m_iDistance = -1;
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, v4);
    }
  }
}


// address=[0x1589b30]
// Decompiled from void __thiscall ISettlerRole::Update(ISettlerRole *this, CSettler *_pSettler)
void  ISettlerRole::Update(class CSettler * _pSettler) {
  
  __int16 TickCounter; // si
  DWORD v3; // eax
  int m_iRandom; // esi
  int v5; // eax
  int v6; // eax
  int v7; // [esp-8h] [ebp-34h]
  int v8; // [esp-4h] [ebp-30h]
  struct SJobSoundInfo sJobSoundInfo; // [esp+4h] [ebp-28h] BYREF
  T_AI_WARRIOR_TYPE v10; // [esp+Ch] [ebp-20h]
  int v11; // [esp+10h] [ebp-1Ch]
  unsigned int m_iCycleFrames; // [esp+14h] [ebp-18h]
  int v13; // [esp+18h] [ebp-14h]
  unsigned int v14; // [esp+1Ch] [ebp-10h]
  unsigned int m_iFrame; // [esp+20h] [ebp-Ch]
  int v16; // [esp+24h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  this->m_uTick = TickCounter - IAnimatedEntity::LastUpdateTick(_pSettler);
  if ( this->m_uTick )
  {
    v3 = CStateGame::GetTickCounter(g_pGame);
    IAnimatedEntity::SetLastUpdateTick(_pSettler, v3);
    v16 = this->m_iTask - 1;
    switch ( v16 )
    {
      case 0:
      case 2:
      case 12:
      case 15:
      case 24:
      case 27:
      case 28:
      case 29:
      case 30:
        if ( this->unk_0A )
        {
          _pSettler->m_iFrame = (this->m_uTick + IAnimatedEntity::Frame(_pSettler))
                              % (unsigned __int8)this->m_uCycleFrames;
        }
        else
        {
          m_iCycleFrames = (unsigned __int8)this->m_uCycleFrames;
          m_iFrame = _pSettler->m_iFrame;
          v14 = this->m_uTick % m_iCycleFrames;
          if ( m_iFrame < v14 )
            _pSettler->m_iFrame = (m_iCycleFrames + m_iFrame - v14) % (unsigned __int8)this->m_uCycleFrames;
          else
            _pSettler->m_iFrame = m_iFrame - v14;
        }
        CEntityToDoListMgr::GetJobSoundInfo(_pSettler->m_iJobPart, &sJobSoundInfo);
        if ( sJobSoundInfo.m_iId > 0 && sJobSoundInfo.m_iFrame == _pSettler->m_iFrame )
        {
          if ( sJobSoundInfo.m_iRandom == 100 || (m_iRandom = sJobSoundInfo.m_iRandom, m_iRandom >= j__rand() % 100) )
          {
            v8 = IEntity::Y(_pSettler);
            v5 = IEntity::X(_pSettler);
            if ( g_pFogging->IsPositionVisible(g_pFogging, v5, v8) )
            {
              v7 = IEntity::Y(_pSettler);
              v6 = IEntity::X(_pSettler);
              CSoundManager::PlayEnvironmentSound(g_pSoundManager, sJobSoundInfo.m_iId, v6, v7, 0);
            }
          }
        }
        v10 = IEntity::WarriorType(_pSettler);
        if ( ((1 << v10) & 0x3C) != 0 )
          CLogic::SetWarAction(g_pLogic);
        break;
      case 5:
        if ( (this->m_uSettlerWalk & 8) != 0 )
        {
          _pSettler->m_iFrame = 0;
        }
        else
        {
          _pSettler->m_iFrame = (this->m_uTick + _pSettler->m_iFrame) % (unsigned __int8)this->m_uCycleFrames;
          if ( !_pSettler->m_iFrame )
            _pSettler->m_iFrame = 1;
          IMovingEntity::DecDistance(_pSettler, (this->m_uTick << 8) / this->m_iWalkspeed);
        }
        break;
      case 16:
        if ( (this->m_uSettlerWalk & 8) != 0 )
        {
          _pSettler->m_iFrame = 0;
        }
        else
        {
          _pSettler->m_iFrame = (this->m_uTick + _pSettler->m_iFrame) % (unsigned __int8)this->m_uCycleFrames;
          if ( !_pSettler->m_iFrame )
            _pSettler->m_iFrame = 1;
          if ( (unsigned __int8)this->m_uCycleFrames > 1u )
            v13 = (unsigned __int8)this->m_uCycleFrames - 1;
          else
            v13 = 1;
          v11 = v13;
          IMovingEntity::DecDistance(_pSettler, (this->m_uTick << 8) / v13);
        }
        break;
      default:
        this->UpdateJob(this, _pSettler);
        break;
    }
  }
}


// address=[0x1589e30]
// Decompiled from void __thiscall ISettlerRole::NewDestination(ISettlerRole *this, IEntity *a2, DWORD a3, int a4)
void  ISettlerRole::NewDestination(class CSettler * a2, int a3, int a4) {
  
  this->m_iStartPosition = IEntity::PackedXY(a2);
  this->m_iDestinationPosition = a3;
}


// address=[0x1589e60]
// Decompiled from void __thiscall ISettlerRole::NewDestination(ISettlerRole *this, IEntity *a2, int a3, int a4, int a5)
void  ISettlerRole::NewDestination(class CSettler * a2, int a3, int a4, int a5) {
  
  this->m_iStartPosition = IEntity::PackedXY(a2);
  this->m_iDestinationPosition = Y16X16::PackXYFast(a3, a4);
}


// address=[0x1589ea0]
// Decompiled from char __thiscall ISettlerRole::SearchPosition(ISettlerRole *this, CSettler *a2, unsigned int a3)
bool  ISettlerRole::SearchPosition(class CSettler * a2, int a3) {
  
  int v3; // eax
  CSettlerMgr::SSettlerInfos *SettlerInfo; // eax
  int v5; // eax
  CSettlerMgr::SSettlerInfos *v6; // eax
  int v7; // eax
  CSettlerMgr::SSettlerInfos *v8; // eax
  int v10; // [esp-8h] [ebp-4Ch]
  int v11; // [esp-8h] [ebp-4Ch]
  int v12; // [esp-8h] [ebp-4Ch]
  int v13; // [esp+14h] [ebp-30h]
  int v14; // [esp+18h] [ebp-2Ch]
  int m_iOffsetX; // [esp+20h] [ebp-24h]
  int m_iOffsetY; // [esp+24h] [ebp-20h]
  int (__cdecl *pSearchFkt)(unsigned int, unsigned int, _DWORD); // [esp+28h] [ebp-1Ch]
  int v18; // [esp+2Ch] [ebp-18h]
  int v20; // [esp+34h] [ebp-10h]
  unsigned int v21; // [esp+38h] [ebp-Ch]
  unsigned int v22; // [esp+3Ch] [ebp-8h]
  char v23; // [esp+43h] [ebp-1h]

  v23 = 0;
  v20 = 0;
  v14 = IEntity::X(a2);
  v13 = IEntity::Y(a2);
  v10 = IEntity::Type(a2);
  v3 = IEntity::Race(a2);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v3, v10);
  m_iOffsetX = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, a3)->m_iOffsetX;
  v11 = IEntity::Type(a2);
  v5 = IEntity::Race(a2);
  v6 = CSettlerMgr::GetSettlerInfo(v5, v11);
  m_iOffsetY = std::vector<CSettlerMgr::SSearchInfos>::operator[](&v6->m_vSearches, a3)->m_iOffsetY;
  v12 = IEntity::Type(a2);
  v7 = IEntity::Race(a2);
  v8 = CSettlerMgr::GetSettlerInfo(v7, v12);
  pSearchFkt = std::vector<CSettlerMgr::SSearchInfos>::operator[](&v8->m_vSearches, a3)->m_pSearchFkt;
  if ( !pSearchFkt && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 594, "pSearchFkt != 0") == 1 )
    __debugbreak();
  while ( v20 < 500 )
  {
    v21 = v14 + CSpiralOffsets::DeltaX(v20);
    v22 = v13 + CSpiralOffsets::DeltaY(v20);
    if ( CWorldManager::InWorld(v21, v22) )
    {
      v18 = pSearchFkt(v21, v22, 0);
      if ( v18 > 0 )
      {
        this->m_iDestinationPosition = Y16X16::PackXYFast(m_iOffsetX + v21, m_iOffsetY + v22);
        this->m_uEntityId = v18;
        return 1;
      }
      if ( v18 < 0 )
      {
        this->m_iDestinationPosition = Y16X16::PackXYFast(m_iOffsetX + v21, m_iOffsetY + v22);
        this->m_uEntityId = 0;
        return 1;
      }
    }
    ++v20;
  }
  return v23;
}


// address=[0x158a0a0]
// Decompiled from char __thiscall ISettlerRole::ESChanged(ISettlerRole *this, CSettler *_pSettler)
bool  ISettlerRole::ESChanged(class CSettler * _pSettler) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v6; // [esp-4h] [ebp-24h]
  int v7; // [esp+4h] [ebp-1Ch]
  CEcoSector *v8; // [esp+Ch] [ebp-14h]
  ISettlerRole *pDbgRoleAfterFree; // [esp+14h] [ebp-Ch]
  bool v12; // [esp+1Fh] [ebp-1h]

  if ( this != CSettler::Role(_pSettler)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 998, "pDbgOrgThis == pDbgOrgRole") == 1 )
  {
    __debugbreak();
  }
  if ( this->GetSettlerRole(this) == FLEE_ROLE
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 999, "pDbgOrgThis->GetSettlerRole() != FLEE_ROLE") == 1 )
  {
    __debugbreak();
  }
  v12 = this->SetFree(this, _pSettler, -1);
  pDbgRoleAfterFree = CSettler::Role(_pSettler);
  if ( v12 )
  {
    if ( pDbgRoleAfterFree == this
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 1009, "pDbgRoleAfterFree != pDbgOrgThis") == 1 )
    {
      __debugbreak();
    }
    if ( pDbgRoleAfterFree->GetSettlerRole(pDbgRoleAfterFree) != 18
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerRole.cpp",
           1010,
           "pDbgRoleAfterFree->GetSettlerRole() == FLEE_ROLE") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    if ( pDbgRoleAfterFree != this
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 1014, "pDbgRoleAfterFree == pDbgOrgThis") == 1 )
    {
      __debugbreak();
    }
    v6 = IEntity::Y(_pSettler);
    v2 = IEntity::X(_pSettler);
    v7 = CWorldManager::EcoSectorId(v2, v6);
    v8 = CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, v7);
    if ( v8 )
    {
      v3 = CEcoSector::Owner(v8);
      if ( v3 == IEntity::OwnerId(_pSettler) )
      {
        v4 = IEntity::Type(_pSettler);
        CEcoSector::ChangeNrOfSettler(v8, v4, 1);
      }
    }
  }
  return 0;
}


// address=[0x158a230]
// Decompiled from char __thiscall ISettlerRole::SetFree(ISettlerRole *this, CSettler *settler, int a3)
bool  ISettlerRole::SetFree(class CSettler * settler, int a3) {
  
  IEntity *homeEntity; // eax
  CBuilding *building; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  unsigned __int16 *v11; // eax
  int v12; // ecx
  int v14; // [esp-8h] [ebp-44h]
  int settlerId; // [esp-4h] [ebp-40h] MAPDST BYREF
  auto_ptr_ISettlerRole *v16; // [esp+8h] [ebp-34h]
  int *p_settlerId; // [esp+Ch] [ebp-30h]
  CFleeRole *v18; // [esp+10h] [ebp-2Ch]
  int v19; // [esp+14h] [ebp-28h]
  auto_ptr_ISettlerRole a2; // [esp+18h] [ebp-24h] BYREF
  CFleeRole *v21; // [esp+1Ch] [ebp-20h]
  CFleeRole *v22; // [esp+20h] [ebp-1Ch]
  struct IEntity *homeEntityId; // [esp+24h] [ebp-18h]
  char v25; // [esp+2Fh] [ebp-Dh]
  int v26; // [esp+38h] [ebp-4h]

  ISettlerRole::DetachFromPile(this, settler, 1, 0);
  ISettlerRole::DetachFromPile(this, settler, 2, 0);
  ISettlerRole::DetachFromPile(this, settler, 3, 0);
  ISettlerRole::DetachFromPile(this, settler, 4, 0);
  if ( this->m_uHomeEntityId )
  {
    if ( !IEntity::FlagBits(settler, ENTITY_FLAG_ATTACHED)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerRole.cpp",
           798,
           "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED )") == 1 )
    {
      __debugbreak();
    }
    homeEntity = CMapObjectMgr::Entity(this->m_uHomeEntityId);
    if ( IEntity::ObjType(homeEntity) == BUILDING_OBJ )
    {
      settlerId = IEntity::ID(settler);
      building = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
      CBuilding::InhabitantFlee(building, settlerId);
    }
    homeEntityId = CMapObjectMgr::Entity(this->m_uHomeEntityId);
    settlerId = IEntity::ID(settler);
    ((void (__thiscall *)(struct IEntity *, int))homeEntityId->Detach)(homeEntityId, settlerId);
    this->m_uHomeEntityId = 0;
  }
  if ( IEntity::FlagBits(settler, ENTITY_FLAG_ATTACHED)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerRole.cpp",
         808,
         "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED ) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iDestinationPosition )
  {
    settlerId = 32;
    v6 = CWorldManager::Index(this->m_iDestinationPosition);
    CWorldManager::ClearFlagBits(v6, 32);
  }
  v7 = IEntity::WorldIdx(settler);
  CWorldManager::EcoSectorId(v7);
  if ( IEntity::WarriorType(settler) )
    goto LABEL_22;
  v8 = IEntity::WorldIdx(settler);
  v9 = CWorldManager::OwnerId(v8);
  if ( v9 == IEntity::OwnerId(settler) )
  {
    v10 = IEntity::WorldIdx(settler);
    v19 = CWorldManager::EcoSectorId(v10);
    if ( !IEntity::FlagBits(settler, ENTITY_FLAG_Offered) )
    {
      settlerId = IEntity::ID(settler);
      v14 = IEntity::Type(settler);
      v11 = (unsigned __int16 *)CEcoSectorMgr::operator[](g_cESMgr, v19);
      CEcoSector::SetSettlerOffer(v11, v14, settlerId);
    }
LABEL_22:
    CSettler::TakeWaitList(settler);
    return 0;
  }
  v22 = (CFleeRole *)operator new(0x2Cu);
  v26 = 0;
  if ( v22 )
    v21 = CFleeRole::CFleeRole(v22);
  else
    v21 = 0;
  v18 = v21;
  v26 = -1;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&a2, v21);
  v26 = 1;
  settlerId = v12;
  p_settlerId = &settlerId;
  v16 = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&settlerId, &a2);
  CSettler::NewRole(settler, (auto_ptr_ISettlerRole)settlerId);
  v25 = 1;
  v26 = -1;
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
  return v25;
}


// address=[0x158a4d0]
// Decompiled from void __thiscall ISettlerRole::SetObserverTarget(ISettlerRole *this, int observerTargetType, WORD target)
void  ISettlerRole::SetObserverTarget(enum T_OBSERVER_TARGET observerTargetType, int target) {
  
  if ( observerTargetType )
  {
    if ( observerTargetType == 2 )
    {
      this->m_uSourcePileId = target;
    }
    else if ( BBSupportDbgReport(
                1,
                "MapObjects\\Settler\\SettlerRole.cpp",
                749,
                "ISettlerRole::SetObserverTarget(): Invalid target type!") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    this->m_uHomeEntityId = target;
  }
}


// address=[0x158a530]
// Decompiled from int __thiscall ISettlerRole::GetObserverTarget(ISettlerRole *this, int a2)
int  ISettlerRole::GetObserverTarget(enum T_OBSERVER_TARGET a2) {
  
  if ( !a2 )
    return this->m_uHomeEntityId;
  if ( a2 == 2 )
    return this->m_uSourcePileId;
  return 0;
}


// address=[0x158a570]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::ISettlerRole(ISettlerRole *this, struct std::istream *a1)
 ISettlerRole::ISettlerRole(std::istream & a2) {
  
  int pExceptionObject; // [esp+0h] [ebp-Ch] BYREF
  unsigned int v4; // [esp+4h] [ebp-8h] BYREF

  CPersistence::CPersistence(this);
  this->__vftable = (ISettlerRole_vtbl *)&ISettlerRole::_vftable_;
  operator^<unsigned int>(a1, &v4);
  if ( v4 )
  {
    operator^<signed char>(a1, &this->m_iTask);
    operator^<unsigned char>(a1, &this->m_uSettlerWalk);
    operator^<signed char>(a1, &this->m_iWalkspeed);
    operator^<unsigned char>(a1, &this->m_uCycleFrames);
    operator^<unsigned short>(a1, &this->m_uTick);
    operator^<unsigned char>(a1, &this->unk_0A);
    operator^<unsigned char>(a1, &this->unk_0B);
    operator^<short>(a1, &this->m_iDestinationOffsetX);
    operator^<short>(a1, &this->m_iDestinationOffsetY);
    operator^<unsigned short>(a1, &this->m_uAttachedSettlerId);
    operator^<int>(a1, &this->m_iDestinationPosition);
    operator^<int>(a1, &this->m_iStartPosition);
    operator^<unsigned short>(a1, &this->m_uHomeEntityId);
    operator^<unsigned short>(a1, &this->m_uEntityId);
    operator^<float>(a1, &this->m_fOffsetX);
    operator^<float>(a1, &this->m_fOffsetY);
  }
  if ( v4 >= 2 )
  {
    operator^<unsigned short>(a1, &this->m_uSourcePileId);
    operator^<unsigned char>(a1, &this->m_uToDoCount);
  }
  if ( v4 && v4 < 3 )
    return this;
  BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for ISettlerRole");
  pExceptionObject = 0;
  CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  return this;
}


// address=[0x158a740]
// Decompiled from void __thiscall ISettlerRole::Store(ISettlerRole *this, struct std::ostream *_rStream)
void  ISettlerRole::Store(std::ostream & _rStream) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF

  CPersistence::Store(this, _rStream);
  v2 = 2;
  operator^<unsigned int>(_rStream, &v2);
  operator^<signed char>(_rStream, &this->m_iTask);
  operator^<unsigned char>(_rStream, &this->m_uSettlerWalk);
  operator^<signed char>(_rStream, &this->m_iWalkspeed);
  operator^<unsigned char>(_rStream, &this->m_uCycleFrames);
  operator^<unsigned short>(_rStream, &this->m_uTick);
  operator^<unsigned char>(_rStream, &this->unk_0A);
  operator^<unsigned char>(_rStream, &this->unk_0B);
  operator^<short>(_rStream, &this->m_iDestinationOffsetX);
  operator^<short>(_rStream, &this->m_iDestinationOffsetY);
  operator^<unsigned short>(_rStream, &this->m_uAttachedSettlerId);
  operator^<int>(_rStream, &this->m_iDestinationPosition);
  operator^<int>(_rStream, &this->m_iStartPosition);
  operator^<unsigned short>(_rStream, &this->m_uHomeEntityId);
  operator^<unsigned short>(_rStream, &this->m_uEntityId);
  operator^<float>((int)_rStream, &this->m_fOffsetX);
  operator^<float>((int)_rStream, &this->m_fOffsetY);
  operator^<unsigned short>(_rStream, &this->m_uSourcePileId);
  operator^<unsigned char>(_rStream, &this->m_uToDoCount);
}


// address=[0x158a8d0]
// Decompiled from int __thiscall ISettlerRole::GetKindOfSelection(ISettlerRole *this, struct CSettler *a2)
int  ISettlerRole::GetKindOfSelection(class CSettler * a2)const {
  
  return 1;
}


// address=[0x158a8f0]
// Decompiled from void __thiscall ISettlerRole::MarkPileAsUnused(ISettlerRole *this, int a2)
void  ISettlerRole::MarkPileAsUnused(enum T_OBSERVER_TARGET a2) {
  
  if ( a2 )
  {
    if ( this->GetObserverTarget(this, a2)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 923, "GetObserverTarget(_tObserverTarget) == 0") == 1 )
    {
      __debugbreak();
    }
    this->SetObserverTarget(this, a2, 0xFFFF);
    if ( this->GetObserverTarget(this, a2) != 0xFFFF
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerRole.cpp",
           927,
           "GetObserverTarget(_tObserverTarget) == ENTITY_ID_UNUSED") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( BBSupportDbgReportF(
              1,
              "MapObjects\\Settler\\SettlerRole.cpp",
              931,
              "ISettlerRole::MarkPileAsUnused(): Invalid type %i!",
              0) == 1 )
  {
    __debugbreak();
  }
}


// address=[0x158a9c0]
// Decompiled from void __thiscall ISettlerRole::DetachFromPile(  ISettlerRole *this,  CSettler *_pSettler,  int _tTarget,  char _bChangeAmount)
void  ISettlerRole::DetachFromPile(class CSettler * _pSettler, enum T_OBSERVER_TARGET _tTarget, bool _bChangeAmount) {
  
  CPile *v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  if ( !_pSettler && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 943, "_pSettler != 0") == 1 )
    __debugbreak();
  if ( _tTarget )
  {
    v6 = this->GetObserverTarget(this, _tTarget);
    if ( v6 )
    {
      if ( v6 != 0xFFFF )
      {
        v5 = IEntity::EntityId(_pSettler);
        if ( v5 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 955, "iSettlerId > 0") == 1 )
          __debugbreak();
        v4 = (CPile *)CPileMgr::operator[](v6);
        if ( _bChangeAmount )
          CPile::ChangeAmountAndDetach(v4, v5);
        else
          (*(void (__thiscall **)(CPile *, int))(*(_DWORD *)v4 + 64))(v4, v5);
        if ( this->GetObserverTarget(this, _tTarget) )
        {
          if ( BBSupportDbgReport(
                 2,
                 "MapObjects\\Settler\\SettlerRole.cpp",
                 968,
                 "GetObserverTarget(_tObserverTarget) == 0") == 1 )
            __debugbreak();
        }
      }
      this->SetObserverTarget(this, _tTarget, 0);
    }
    else if ( _bChangeAmount
           && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 975, "!_bChangeAmount") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( BBSupportDbgReportF(
              1,
              "MapObjects\\Settler\\SettlerRole.cpp",
              980,
              "ISettlerRole::DetachFromPile(): Invalid type %i!",
              0) == 1 )
  {
    __debugbreak();
  }
}


// address=[0x158ab30]
// Decompiled from int __thiscall ISettlerRole::GetNextSettlerType(ISettlerRole *this)
int  ISettlerRole::GetNextSettlerType(void) {
  
  return 0;
}


// address=[0x158ab40]
// Decompiled from char __thiscall ISettlerRole::SetNextSettlerType(ISettlerRole *this, int a2)
bool  ISettlerRole::SetNextSettlerType(int a2) {
  
  return 0;
}


// address=[0x158ab50]
// Decompiled from int __thiscall ISettlerRole::SettlerWalk(ISettlerRole *this, struct CSettler *a2)
int  ISettlerRole::SettlerWalk(class CSettler * a2) {
  
  return CSettler::Walk(a2);
}


// address=[0x158ab70]
// Decompiled from char __thiscall ISettlerRole::SearchRestingPlace(ISettlerRole *this, struct CSettler *a2, int a3)
bool  ISettlerRole::SearchRestingPlace(class CSettler * a2, int a3) {
  
  int v3; // esi
  int v6; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  if ( a3 <= 1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 858, "_iDistance > 1") == 1 )
    __debugbreak();
  v7 = CSpiralOffsets::Last(a3);
  v6 = CSpiralOffsets::First(a3 - 1);
  v8 = IEntity::X(a2);
  v9 = IEntity::Y(a2);
  for ( i = v7; i >= v6; --i )
  {
    v10 = v8 + CSpiralOffsets::DeltaX(i);
    v11 = v9 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v10, v11) )
    {
      v3 = CWorldManager::EcoSectorId(v8, v9);
      if ( v3 == CWorldManager::EcoSectorId(v10, v11) && !CWorldManager::FlagBits(v10, v11, 0x77u) )
      {
        *((_DWORD *)this + 7) = Y16X16::PackXYFast(v10, v11);
        return 1;
      }
    }
  }
  return 0;
}


// address=[0x158aca0]
// Decompiled from char __thiscall ISettlerRole::CheckHome(ISettlerRole *this, struct CSettler *a2)
bool  ISettlerRole::CheckHome(class CSettler * a2) {
  
  if ( this->m_uHomeEntityId )
    return 1;
  this->SetFree(this, a2, -1);
  return 0;
}


// address=[0x158ace0]
// Decompiled from void __thiscall ISettlerRole::InitCommonTaskValues(  ISettlerRole *this,  struct CSettler *a2,  const struct CEntityTask *a3)
void  ISettlerRole::InitCommonTaskValues(class CSettler * a2, class CEntityTask const & a3) {
  
  int v3; // eax
  const char *v4; // [esp-4h] [ebp-10h]
  IBuildingRole *v5; // [esp+0h] [ebp-Ch]
  struct CBuilding *BuildingPtr; // [esp+4h] [ebp-8h]

  if ( !a3->m_iTask
    || a3->m_iTask == 1
    || a3->m_iTask == 29
    || a3->m_iTask == 2
    || a3->m_iTask == 5
    || a3->m_iTask == 4
    || a3->m_iTask == 30 )
  {
    IEntity::SetFlagBits(a2, (EntityFlag)2048);
    a2->m_iDistance = 0;
    this->m_iDestinationOffsetX = a3->m_iX;
    this->m_iDestinationOffsetY = a3->m_iY;
  }
  else
  {
    IEntity::ClearFlagBits(a2, (EntityFlag)2048);
    a2->m_iDistance = 0;
    this->m_iDestinationOffsetX = a3->m_iX;
    this->m_iDestinationOffsetY = a3->m_iY;
  }
  if ( a3->m_iDir >= 0 )
    a2->m_iDirection = a3->m_iDir;
  if ( a3->m_bVisible )
    IEntity::SetFlagBits(a2, ENTITY_FLAG_Visible);
  else
    IEntity::ClearFlagBits(a2, ENTITY_FLAG_Visible);
  if ( a3->m_iTrigger )
  {
    if ( !this->m_uHomeEntityId
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 493, "m_uHomeEntityId != 0") == 1 )
    {
      __debugbreak();
    }
    if ( this->m_uHomeEntityId )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
      if ( !BuildingPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 498, "pBuilding != NULL") == 1 )
        __debugbreak();
      if ( BuildingPtr )
      {
        v5 = (IBuildingRole *)CBuilding::Role(BuildingPtr);
        IBuildingRole::TakeJobTrigger(v5, a3->m_iTrigger);
      }
    }
  }
  this->m_uSettlerWalk = 72;
  this->m_iTask = a3->m_iTask;
  this->m_iWalkspeed = a3->m_iDuration;
  this->m_uCycleFrames = a3->m_iFrameCount;
  if ( this->m_uCycleFrames <= 1u )
  {
    v4 = (&off_37B8064)[2 * a3->m_iJobNr];
    v3 = IEntity::Type(a2);
    BBSupportTracePrintF(
      3,
      "ISettlerRole::InitCommonTaskValues(): Invalid number of frames (%i) for settler type %s, job %s!",
      this->m_uCycleFrames,
      (&off_37B7E4C)[2 * v3],
      v4);
  }
  if ( !this->m_uCycleFrames
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 526, "m_iCycleFrames >= 1") == 1 )
  {
    __debugbreak();
  }
  if ( a3->m_uData9 )
    this->m_uEntityId = a3->m_uData9;
  if ( a3->m_iEntity )
    this->unk_0B = a3->m_iEntity;
  a2->m_iFrame = 0;
  a2->m_iJobPart = a3->m_iJobNr;
  this->unk_0A = a3->m_bForward;
  if ( this->unk_0A )
    IAnimatedEntity::SetFrame(a2, 0);
  else
    IAnimatedEntity::SetFrame(a2, this->m_uCycleFrames - 1);
}


// address=[0x158afa0]
// Decompiled from void __thiscall ISettlerRole::NewDestinationEx(  ISettlerRole *this,  CSettler *pSettler,  void *a3,  int a4,  int a5,  char a6)
void  ISettlerRole::NewDestinationEx(class CSettler * pSettler, class std::list<class CEntityTask,class std::allocator<class CEntityTask> > & a3, int a4, int a5, int a6) {
  
  int v6; // eax
  unsigned int v7; // eax
  CEntityTask *v8; // eax
  CEntityTask *v9; // eax
  int v10; // [esp-4h] [ebp-50h]
  CEntityTask v11; // [esp+0h] [ebp-4Ch] BYREF
  CEntityTask v12; // [esp+18h] [ebp-34h] BYREF
  int v13; // [esp+30h] [ebp-1Ch]
  CEntityTask *ActualTask; // [esp+34h] [ebp-18h]
  unsigned int SettlerJobFrameCount; // [esp+3Ch] [ebp-10h]
  BOOL v17; // [esp+40h] [ebp-Ch]
  int SettlerFirstJob; // [esp+44h] [ebp-8h]
  bool v19; // [esp+4Bh] [ebp-1h]

  if ( std::list<CEntityTask>::size(a3) )
  {
    ActualTask = IMovingEntity::GetActualTask(pSettler);
    v17 = ActualTask->m_iTask == 17;
    v19 = v17;
    if ( !v17 && (a6 & 2) != 0 )
    {
      v13 = std::list<CEntityTask>::back();
      if ( *(_BYTE *)(v13 + 4) == 17 )
        std::list<CEntityTask>::pop_back();
    }
    else
    {
      std::list<CEntityTask>::clear();
    }
  }
  v10 = IEntity::Type(pSettler);
  v6 = IEntity::Race(pSettler);
  SettlerFirstJob = CGfxManager::GetSettlerFirstJob(v6, v10);
  v7 = IEntity::Race(pSettler);
  SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount(g_pGfxManager, v7, SettlerFirstJob, 2u);
  v8 = CEntityTask::CEntityTask(&v12, 7, SettlerFirstJob, a4, a5, -1, SettlerJobFrameCount, -1, 1, 1, 0, 0, 0, 0);
  std::list<CEntityTask>::push_back((int)v8);
  v9 = CEntityTask::CEntityTask(&v11, 17, SettlerFirstJob, a6 & 1, 0, -1, SettlerJobFrameCount, -1, 1, 1, 0, 0, 0, 0);
  std::list<CEntityTask>::push_back((int)v9);
  IMovingEntity::SetToDoList(pSettler, (DWORD)a3);
  if ( std::list<CEntityTask>::size(a3) == 2 )
  {
    IMovingEntity::ResetToDoList(pSettler);
    this->TakeJob(this, pSettler);
  }
}


#endif // Already implemented
