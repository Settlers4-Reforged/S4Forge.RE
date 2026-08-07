#include "CDiggerRole.h"

// Definitions for class CDiggerRole

// address=[0x14004a0]
// Decompiled from int __cdecl CDiggerRole::New(int a1)
class CPersistence * __cdecl CDiggerRole::New(std::istream & a1) {
  
  if ( operator new(0x30u) )
  {
    return CDiggerRole::CDiggerRole(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x1568910]
// Decompiled from CWalkingNormal *__thiscall CDiggerRole::InitWalking(CDiggerRole *this, IEntity *a2)
class CWalking *  CDiggerRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  CWalkingNormal *v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = CWalking::Create(1, v2);
  v4->InitB(v4, -1, 0);
  return v4;
}


// address=[0x1568950]
// Decompiled from void __thiscall CDiggerRole::LogicUpdateJob(CDiggerRole *this, struct CSettler *a2)
void  CDiggerRole::LogicUpdateJob(class CSettler * a2) {
  
  CHAR m_iTask; // [esp+0h] [ebp-8h]

  m_iTask = this->m_iTask;
  if ( m_iTask == 6 )
  {
    IMovingEntity::SetDistance(a2, 0);
    this->Go(this, a2);
  }
  else if ( m_iTask == 16 )
  {
    this->m_uCycleFrames = IMovingEntity::GetActualTask(a2)->m_iFrameCount;
    if ( CDiggerRole::CheckDig(this, a2) )
    {
      IAnimatedEntity::RegisterForLogicUpdate(a2, this->m_uCycleFrames);
    }
  }
}


// address=[0x15689d0]
// Decompiled from int __stdcall CDiggerRole::PostLoadInit(CPropertySet *a1)
void  CDiggerRole::PostLoadInit(class CSettler * a1) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x15689f0]
// Decompiled from char __thiscall CDiggerRole::SetFree(CDiggerRole *this, CSettler *a2, int a3)
bool  CDiggerRole::SetFree(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int m_uHomeEntityId; // [esp-4h] [ebp-14h]
  CBuildingSiteRole *v7; // [esp+0h] [ebp-10h]
  CBuilding *v8; // [esp+4h] [ebp-Ch]
  IBuildingRole *v9; // [esp+8h] [ebp-8h]

  if ( this->m_uHomeEntityId )
  {
    if ( !IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED) && BBSupportDbgReport(2, "MapObjects\\Settler\\DiggerRole.cpp", 460, "_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
    {
      __debugbreak();
    }
    v8 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
    v9 = CBuilding::Role(v8);
    if ( !v9->GetBuildingRole(v9) )
    {
      v7 = (CBuildingSiteRole *)CBuilding::Role(v8);
      v3 = IEntity::ID(a2);
      CBuildingSiteRole::BuilderLeft(v7, v3);
    }
  }
  if ( debug && DEBUG_FLAGS[dword_41520A4] )
  {
    m_uHomeEntityId = this->m_uHomeEntityId;
    v4 = IEntity::ID(a2);
    BBSupportTracePrintF(0, "Digger nr %u - WorkIsDone at building %u", v4, m_uHomeEntityId);
  }
  this->m_uU1 = 0;
  return ISettlerRole::SetFree(this, a2, a3);
}


// address=[0x1568ae0]
// Decompiled from CDiggerRole *__thiscall CDiggerRole::CDiggerRole(CDiggerRole *this, struct std::istream *a2)
 CDiggerRole::CDiggerRole(std::istream & a2) {
  
  unsigned int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  this->__vftable = (ISettlerRole_vtbl *)&CDiggerRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDiggerRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned short>(a2, &this->m_uDigMapPos);
  operator^<unsigned char>(a2, &this->m_uU1);
  v6 = -1;
  return this;
}


// address=[0x1568bb0]
// Decompiled from void __thiscall CDiggerRole::Store(CDiggerRole *this, struct std::ostream *a1)
void  CDiggerRole::Store(std::ostream & a1) {
  
  unsigned int v2; // [esp+0h] [ebp-8h] BYREF
  CDiggerRole *v3; // [esp+4h] [ebp-4h]

  v3 = this;
  ISettlerRole::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<unsigned short>(a1, &v3->m_uDigMapPos);
  operator^<unsigned char>(a1, &v3->m_uU1);
}


// address=[0x1569d00]
// Decompiled from int __thiscall CDiggerRole::ClassID(CDiggerRole *this)
unsigned long  CDiggerRole::ClassID(void)const {
  
  return CDiggerRole::m_iClassID;
}


// address=[0x1569d20]
// Decompiled from int __thiscall CDiggerRole::GetSettlerRole(CDiggerRole *this)
int  CDiggerRole::GetSettlerRole(void)const {
  
  return 2;
}


// address=[0x1588500]
// Decompiled from int __cdecl CDiggerRole::Load(struct std::istream *a1)
class CDiggerRole * __cdecl CDiggerRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CDiggerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8beb0]
// [Decompilation failed for static unsigned long CDiggerRole::m_iClassID]

// address=[0x1568c10]
// Decompiled from CDiggerRole *__thiscall CDiggerRole::CDiggerRole(CDiggerRole *this)
 CDiggerRole::CDiggerRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  this->__vftable = (ISettlerRole_vtbl *)&CDiggerRole::_vftable_;
  this->m_uDigMapPos = 0;
  this->m_uU1 = 0;
  return this;
}


// address=[0x1568c40]
// Decompiled from void __thiscall CDiggerRole::~CDiggerRole(CDiggerRole *this)
 CDiggerRole::~CDiggerRole(void) {
  
  *(_DWORD *)this = &CDiggerRole::_vftable_;
  ISettlerRole::~ISettlerRole(this);
}


// address=[0x1568c60]
// Decompiled from void __thiscall CDiggerRole::GetNextJob(CDiggerRole *this, struct CSettler *a2)
void  CDiggerRole::GetNextJob(class CSettler * a2) {
  
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
  {
    IMovingEntity::ResetToDoList(a2);
  }
  this->TakeJob(this, a2);
}


// address=[0x1568ca0]
// Decompiled from void __thiscall CDiggerRole::TakeJob(CDiggerRole *this, struct CSettler *a2)
void  CDiggerRole::TakeJob(class CSettler * a2) {
  
  CBuilding *v2; // eax
  unsigned int v3; // eax
  std::list *v4; // eax
  CBuilding *v5; // eax
  CBuilding *v6; // eax
  CEntityTask *ActualTask; // [esp-4h] [ebp-2Ch]
  int v8; // [esp-4h] [ebp-2Ch]
  int v9; // [esp+0h] [ebp-28h]
  CBuildingSiteRole *v10; // [esp+8h] [ebp-20h]
  int v11; // [esp+Ch] [ebp-1Ch]
  int v12; // [esp+14h] [ebp-14h]
  int v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+20h] [ebp-8h]
  int v15; // [esp+20h] [ebp-8h]

  ActualTask = IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  switch ( this->m_iTask )
  {
    case 7:
    case 0xA:
      IAnimatedEntity::SetFrame(a2, 1u);
      IMovingEntity::WalkToXY(a2, this->m_iDestinationPosition, 0);
      this->m_iTask = 6;
      IMovingEntity::SetDisplacementCosts(a2, 5);
      this->Go(this, a2);
      break;
    case 0x10:
      this->m_uU1 = 1;
      v5 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
      v10 = (CBuildingSiteRole *)CBuilding::Role(v5);
      v6 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
      v14 = IEntity::WorldIdx(v6);
      v12 = CWorldManager::X(v14);
      v11 = CWorldManager::Y(v14);
      v15 = IEntity::WorldIdx(a2);
      v13 = CWorldManager::X(v15);
      v9 = CWorldManager::Y(v15) - v11 + 15;
      this->m_uDigMapPos = s_iDigMap[IEntity::OwnerId(a2)][v10->m_iDigMap].m_vCells[v13 - v12 + 15][v9];
      if ( CDiggerRole::CheckDig(this, a2) )
      {
        IMovingEntity::SetDisplacementCosts(a2, 10);
        IAnimatedEntity::RegisterForLogicUpdate(a2, this->m_iWalkspeed);
      }
      break;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(a2, 0);
      IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
      break;
    case 0x18:
      IMovingEntity::SetDisplacementCosts(a2, 10);
      v8 = IEntity::ID(a2);
      v2 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
      CBuilding::SettlerEnter(v2, v8);
      v3 = IEntity::Race(a2);
      v4 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v3, 0xA1u);
      a2->NewToDoList(a2, (int)v4, 161);
      break;
    default:
      return;
  }
}


// address=[0x1568ee0]
// Decompiled from void __thiscall CDiggerRole::Init(CDiggerRole *this, IEntity *a1)
void  CDiggerRole::Init(class CSettler * a1) {
  
  if ( IEntity::FlagBits(a1, ENTITY_FLAG_ATTACHED) && BBSupportDbgReport(2, "MapObjects\\Settler\\DiggerRole.cpp", 138, "!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uHomeEntityId && BBSupportDbgReport(2, "MapObjects\\Settler\\DiggerRole.cpp", 139, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  CWarMap::AddEntity(a1);
  this->m_uHomeEntityId = 0;
  this->m_uU1 = 0;
}


// address=[0x1568f70]
// Decompiled from void __thiscall CDiggerRole::ConvertEventIntoGoal(CDiggerRole *this, CSettler *_pSettler, struct CEntityEvent *a3)
void  CDiggerRole::ConvertEventIntoGoal(class CSettler * _pSettler, class CEntityEvent * a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned int v5; // eax
  std::list *v6; // eax
  int v7; // eax
  DWORD v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]
  int m_iDataA; // [esp-4h] [ebp-10h]
  int m_uHomeEntityId; // [esp-4h] [ebp-10h]
  CBuilding *v12; // [esp+0h] [ebp-Ch]
  int m_iEvent; // [esp+4h] [ebp-8h]

  m_iEvent = a3->m_iEvent;
  if ( m_iEvent == 1 )
  {
    this->m_uU1 = 0;
    v12 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, a3->m_iDataA);
    if ( IEntity::FlagBits(v12, (EntityFlag)4096) )
    {
      if ( debug && DEBUG_FLAGS[dword_41520A4] )
      {
        m_iDataA = a3->m_iDataA;
        v4 = IEntity::ID(_pSettler);
        BBSupportTracePrintF(0, "Digger %u was orderd to buildingsite %u", v4, m_iDataA);
      }
      v8 = IEntity::PackedXY(v12);
      ISettlerRole::NewDestination(this, _pSettler, v8, 0);
      v5 = IEntity::Race(_pSettler);
      v6 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v5, 0x44u);
      _pSettler->NewToDoList(_pSettler, (int)v6, 68);
      if ( debug && DEBUG_FLAGS[dword_41520A4] )
      {
        m_uHomeEntityId = this->m_uHomeEntityId;
        v7 = IEntity::ID(_pSettler);
        BBSupportTracePrintF(0, "Digger CONV COME_TO_WORK - Attach settler %u to building %u", v7, m_uHomeEntityId);
      }
    }
  }
  else if ( m_iEvent == 7 || m_iEvent == 9 )
  {
    if ( debug )
    {
      if ( DEBUG_FLAGS[dword_41520A4] )
      {
        v9 = this->m_uHomeEntityId;
        v3 = IEntity::ID(_pSettler);
        BBSupportTracePrintF(0, "Digger %u cancel order of building %u", v3, v9);
      }
    }
    this->SetFree(this, _pSettler, a3->m_iDataC);
  }
  else if ( !IEntity::FlagBits(_pSettler, ENTITY_FLAG_Registered) )
  {
    if ( debug && DEBUG_FLAGS[dword_41520A4] )
    {
      BBSupportTracePrintF(0, "ConvertEventIntoGoal DiggerRole - unknown event %u", a3->m_iEvent);
    }
    IAnimatedEntity::RegisterForLogicUpdate(_pSettler, 1);
  }
}


// address=[0x1569130]
// Decompiled from void __thiscall CDiggerRole::SearchDig(CDiggerRole *this, CSettler *_pSettler)
void  CDiggerRole::SearchDig(class CSettler * _pSettler) {
  
  CBuilding *v2; // eax
  CBuilding *v3; // eax
  CBuilding *v4; // eax
  int iOwner; // eax
  int v6; // eax
  int v7; // eax
  int m_uHomeEntityId; // [esp-4h] [ebp-38h]
  int v9; // [esp+0h] [ebp-34h]
  int v10; // [esp+4h] [ebp-30h]
  int v11; // [esp+8h] [ebp-2Ch]
  int v12; // [esp+Ch] [ebp-28h]
  int v13; // [esp+10h] [ebp-24h]
  CBuildingSiteRole *v14; // [esp+14h] [ebp-20h]
  unsigned int iMapY; // [esp+18h] [ebp-1Ch]
  signed int iMapX; // [esp+1Ch] [ebp-18h]
  int v17; // [esp+24h] [ebp-10h]
  int v19; // [esp+2Ch] [ebp-8h]
  int v20; // [esp+30h] [ebp-4h]

  iMapX = (31 * CGameData::Rand(g_pGameData)) >> 16;
  iMapY = (31 * CGameData::Rand(g_pGameData)) >> 16;
  v12 = 0;
  v11 = 0;
  v19 = 0;
  v20 = 0;
  v2 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
  v14 = (CBuildingSiteRole *)CBuilding::Role(v2);
  v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
  v10 = IEntity::X(v3);
  v4 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
  v9 = IEntity::Y(v4);
  do
  {
    ++v12;
    iMapX += 13;
    if ( iMapX >= 31 )
    {
      iMapX -= 31;
      if ( (int)++iMapY >= 31 )
      {
        iMapY = 0;
      }
    }
    iOwner = IEntity::OwnerId(_pSettler);
    v13 = s_iDigMap[iOwner][v14->m_iDigMap].m_vCells[iMapX][iMapY];
    if ( s_iDigMap[iOwner][v14->m_iDigMap].m_vCells[iMapX][iMapY] )
    {
      v19 = iMapX + v10 - 15;
      v20 = iMapY + v9 - 15;
      v17 = CWorldManager::GroundHeight(v19, v20);
      if ( v13 != v17 && !CWorldManager::FlagBits(v19, v20, 0x20u) )
      {
        if ( v13 >= v17 )
        {
          if ( CWorldManager::GroundHeight(iMapX + v10 - 16, iMapY + v9 - 16) != v17 - 5 && CWorldManager::GroundHeight(v19, iMapY + v9 - 16) != v17 - 5 && CWorldManager::GroundHeight(v19, v20 + 1) != v17 - 7 && CWorldManager::GroundHeight(v19 + 1, v20 + 1) != v17 - 7 )
          {
            v11 = 1;
          }
        }
        else if ( CWorldManager::GroundHeight(iMapX + v10 - 16, iMapY + v9 - 16) != v17 + 7 && CWorldManager::GroundHeight(v19, iMapY + v9 - 16) != v17 + 7 && CWorldManager::GroundHeight(v19, v20 + 1) != v17 + 5 && CWorldManager::GroundHeight(v19 + 1, v20 + 1) != v17 + 5 )
        {
          v11 = 1;
        }
      }
    }
  }
  while ( !v11 && v12 <= 961 );
  if ( v12 <= 961 )
  {
    CWorldManager::SetFlagBits(v19, v20, 32);
    if ( CWorldManager::FlagBits(v19, v20, 1u) )
    {
      BBSupportTracePrintF(0, "Digger trouble %u %u", this->m_uHomeEntityId, v14->m_iDigMap);
    }
    ISettlerRole::NewDestination(this, _pSettler, v19, v20, 0);
    this->m_uDigMapPos = s_iDigMap[IEntity::OwnerId(_pSettler)][v14->m_iDigMap].m_vCells[iMapX][iMapY];
    this->GetNextJob(this, _pSettler);
  }
  else
  {
    if ( debug && DEBUG_FLAGS[dword_41520A4] )
    {
      m_uHomeEntityId = this->m_uHomeEntityId;
      v6 = IEntity::ID(_pSettler);
      BBSupportTracePrintF(0, "Digger done %u at building %u", v6, m_uHomeEntityId);
    }
    if ( v14->m_uDiggerAct == 1 )
    {
      if ( debug )
      {
        if ( DEBUG_FLAGS[dword_41520A4] )
        {
          BBSupportTracePrintF(0, "Building digging is done %u", this->m_uHomeEntityId);
        }
      }
      v7 = IEntity::OwnerId(_pSettler);
      CBuildingSiteRole::DiggingIsReady(v14, v7);
    }
    this->SetFree(this, _pSettler, -1);
  }
}


// address=[0x1569540]
// Decompiled from char __thiscall CDiggerRole::CheckDig(CDiggerRole *this, CSettler *_pSettler)
bool  CDiggerRole::CheckDig(class CSettler * _pSettler) {
  
  CBuilding *v2; // eax
  CBuilding *v4; // eax
  CBuilding *v5; // eax
  int v6; // [esp+4h] [ebp-20h]
  int v7; // [esp+8h] [ebp-1Ch]
  int m_uDigMapPos; // [esp+Ch] [ebp-18h]
  CBuildingSiteRole *v9; // [esp+10h] [ebp-14h]
  int v11; // [esp+18h] [ebp-Ch]
  __int64 v12; // [esp+1Ch] [ebp-8h]

  LODWORD(v12) = IEntity::X(_pSettler);
  HIDWORD(v12) = IEntity::Y(_pSettler);
  v11 = CWorldManager::GroundHeight(v12, SHIDWORD(v12));
  m_uDigMapPos = this->m_uDigMapPos;
  v2 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
  v9 = (CBuildingSiteRole *)CBuilding::Role(v2);
  if ( v11 == m_uDigMapPos || !m_uDigMapPos )
  {
    v4 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
    v7 = v12 + 15 - IEntity::X(v4);
    v5 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
    v6 = HIDWORD(v12) + 15 - IEntity::Y(v5);
    s_iDigMap[IEntity::OwnerId(_pSettler)][v9->m_iDigMap].m_vCells[v7][v6] = 0;
    CWorldManager::ClearFlagBits(v12, SHIDWORD(v12), 16);
    CWorldManager::ClearFlagBits(v12, SHIDWORD(v12), 32);
    CDiggerRole::SearchDig(this, _pSettler);
    return 0;
  }
  if ( v11 > m_uDigMapPos )
  {
    if ( CWorldManager::GroundHeight(v12 - 1, HIDWORD(v12) - 1) != v11 + 7 && CWorldManager::GroundHeight(v12, (unsigned __int64)(v12 - 0x100000000LL) >> 32) != v11 + 7 && CWorldManager::GroundHeight(v12, (unsigned __int64)(v12 + 0x100000000LL) >> 32) != v11 + 5 && CWorldManager::GroundHeight(v12 + 1, HIDWORD(v12) + 1) != v11 + 5 )
    {
      CWorldManager::DecreaseGroundHeight(v12, SHIDWORD(v12));
      IGfxEngine::UpdateWorldPosition(g_pGfxEngine, v12, SHIDWORD(v12));
      --v9->m_iDiggingNeeded;
      if ( !IGfxEngine::CanChangeGround(g_pGfxEngine, v12, SHIDWORD(v12), 28) )
      {
        return 1;
      }
      CWorldManager::SetGround(v12, SHIDWORD(v12), 28);
      IGfxEngine::UpdateWorldPosition(g_pGfxEngine, v12, SHIDWORD(v12));
      return 1;
    }
    goto LABEL_19;
  }
  if ( CWorldManager::GroundHeight(v12 - 1, HIDWORD(v12) - 1) == v11 - 5 || CWorldManager::GroundHeight(v12, (unsigned __int64)(v12 - 0x100000000LL) >> 32) == v11 - 5 || CWorldManager::GroundHeight(v12, (unsigned __int64)(v12 + 0x100000000LL) >> 32) == v11 - 7 || CWorldManager::GroundHeight(v12 + 1, HIDWORD(v12) + 1) == v11 - 7 )
  {
LABEL_19:
    CWorldManager::ClearFlagBits(v12, SHIDWORD(v12), 32);
    CDiggerRole::SearchDig(this, _pSettler);
    return 0;
  }
  CWorldManager::IncreaseGroundHeight(v12, SHIDWORD(v12));
  IGfxEngine::UpdateWorldPosition(g_pGfxEngine, v12, SHIDWORD(v12));
  --v9->m_iDiggingNeeded;
  if ( !IGfxEngine::CanChangeGround(g_pGfxEngine, v12, SHIDWORD(v12), 28) )
  {
    return 1;
  }
  CWorldManager::SetGround(v12, SHIDWORD(v12), 28);
  IGfxEngine::UpdateWorldPosition(g_pGfxEngine, v12, SHIDWORD(v12));
  return 1;
}


