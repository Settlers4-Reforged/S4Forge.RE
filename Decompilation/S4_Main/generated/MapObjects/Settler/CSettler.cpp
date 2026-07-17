#if FALSE
#include "CSettler.h"

// Definitions for class CSettler

// address=[0x130f340]
// Decompiled from ISettlerRole *__thiscall CSettler::Role(CSettler *this)
class ISettlerRole &  CSettler::Role(void) {
  
  return (ISettlerRole *)std::auto_ptr<ISettlerRole>::operator*(&this->m_pBehavior);
}


// address=[0x1401bc0]
// Decompiled from CSettler *__cdecl CSettler::New(int a1)
class CPersistence * __cdecl CSettler::New(std::istream & a1) {
  
  CSettler *v3; // [esp+Ch] [ebp-10h]

  v3 = (CSettler *)CSettler::operator new(0x68u);
  if ( v3 )
    return CSettler::CSettler(v3, a1);
  else
    return 0;
}


// address=[0x1439aa0]
// Decompiled from int __thiscall CSettler::GetNextSettlerType(CSettler *this)
int  CSettler::GetNextSettlerType(void) {
  
  struct ISettlerRole *v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  return v1->GetNextSettlerType(v1, this, v1);
}


// address=[0x1439e70]
// Decompiled from int __thiscall CSettler::SetNextSettlerType(CSettler *this, int a2)
bool  CSettler::SetNextSettlerType(int a2) {
  
  struct ISettlerRole *v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  return v3->SetNextSettlerType(v3, a2);
}


// address=[0x1439f80]
// Decompiled from bool __thiscall CSettler::Strike(IEntity *this)
bool  CSettler::Strike(void)const {
  
  return IEntity::FlagBits(this, 0x1000) == 0;
}


// address=[0x15081e0]
// Decompiled from void __thiscall CSettler::SetFree(CSettler *this)
void  CSettler::SetFree(void) {
  
  struct ISettlerRole *v1; // [esp+0h] [ebp-8h]

  v1 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v1->SetFree(v1, this, -1);
}


// address=[0x1513ad0]
// Decompiled from void __thiscall CSettler::SetBuilding(CSettler *this, int a2)
void  CSettler::SetBuilding(int a2) {
  
  struct ISettlerRole *v2; // [esp+4h] [ebp-4h]

  v2 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v2->SetBuilding(v2, a2);
}


// address=[0x1513b30]
// Decompiled from void __thiscall CSettler::SetOffset(CSettler *this, float _fOffsetX, float _fOffsetY)
void  CSettler::SetOffset(float _fOffsetX, float _fOffsetY) {
  
  std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior)->m_fOffsetX = _fOffsetX;
  std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior)->m_fOffsetY = _fOffsetY;
}


// address=[0x157d1f0]
// Decompiled from void __thiscall CSettler::Delete(CSettler *this)
void  CSettler::Delete(void) {
  
  CWarMapNode *v1; // eax
  int v2; // eax
  unsigned int LastLogicUpdateTick; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-Ch] [ebp-2Ch]
  int v7; // [esp-8h] [ebp-28h]
  int v8; // [esp-4h] [ebp-24h]
  struct IEffects *v9; // [esp+0h] [ebp-20h]
  unsigned int v10; // [esp+4h] [ebp-1Ch]
  ISettlerRole *pRole; // [esp+Ch] [ebp-14h]
  struct ISettlerRole *v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch]
  bool v15; // [esp+1Fh] [ebp-1h]

  this->m_iFlags &= ~0x10000000u;
  if ( IEntity::Type(this) < SETTLER_MAX
    && IEntity::WarriorType(this) == AI_WARRIOR_TYPE_NONE
    && !IEntity::FlagBits(this, ENTITY_FLAG_OnBoard) )
  {
    this->m_iFlags |= 0x10000000u;
  }
  IEntity::RemoveFromMapObjectLayerIfNecessary(this);
  v1 = IEntity::WarMapNode(this);
  if ( CWarMapNode::IsInWarMap(v1) )
  {
    v2 = IEntity::EntityId(this);
    CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v2, 3, (const char *)&stru_37B13E0);
    CWarMap::RemoveEntity(this);
  }
  v8 = IEntity::ID(this);
  LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(this);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v8);
  v12 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v12->SetFree(v12, this, -1);
  if ( IEntity::Type(this) < SETTLER_MAX )
  {
    v15 = 1;
    if ( IEntity::WarriorType(this) == AI_WARRIOR_TYPE_NONE )
    {
      pRole = CSettler::Role(this);
      v15 = pRole->GetSettlerRole(pRole) == 0x12;
    }
    if ( v15 && (IEntity::Flags(this) & ENTITY_FLAG_Visible) != 0 )
    {
      v10 = CGameData::Rand(g_pGameData);
      if ( v10 >= CRandom16::PercentValue(0x21u) )
      {
        if ( v10 >= CRandom16::PercentValue(0x42u) )
          v13 = 3;
        else
          v13 = 2;
      }
      else
      {
        v13 = 1;
      }
      v9 = CLogic::Effects(g_pLogic);
      v7 = IEntity::OwnerId(this);
      v6 = IEntity::Y(this);
      v4 = IEntity::X(this);
      v9->AddAngel(v9, v13, 41, v4, v6, v7, 0);
    }
  }
  v5 = IEntity::EntityId(this);
  CSettlerMgr::CheckOutSettler(&g_cSettlerMgr, v5);
  this->m_iFlags &= ~0x10000000u;
}


// address=[0x157d3f0]
// Decompiled from void __thiscall CSettler::LogicUpdate(CSettler *this)
void  CSettler::LogicUpdate(void) {
  
  struct ISettlerRole *v1; // [esp+0h] [ebp-Ch]
  struct ISettlerRole *v2; // [esp+4h] [ebp-8h]

  if ( !IEntity::FlagBits(this, ENTITY_FLAG_Died) )
  {
    if ( !IEntity::FlagBits(this, (EntityFlag)128)
      || (IEntity::ClearFlagBits(this, (EntityFlag)128),
          v2 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior),
          !v2->ESChanged(v2, this)) )
    {
      if ( !IAnimatedEntity::ProcessAllEvents(this) )
      {
        v1 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
        v1->LogicUpdate(v1, this);
      }
      IEntity::FlagBits(this, ENTITY_FLAG_Registered);
    }
  }
}


// address=[0x157d4b0]
// Decompiled from struct SGfxObjectInfo *__thiscall CSettler::GetGfxInfos(CSettler *this)
struct SGfxObjectInfo *  CSettler::GetGfxInfos(void) {
  
  ISettlerRole *pRole; // eax MAPDST
  int iOwnerId; // eax MAPDST
  int iPackedXY; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v10; // eax
  int v11; // [esp-4h] [ebp-7Ch]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+8h] [ebp-70h]
  int v13; // [esp+Ch] [ebp-6Ch]
  int v14; // [esp+14h] [ebp-64h]
  int m_iFrame; // [esp+18h] [ebp-60h]
  unsigned int SettlerJobFrameCount; // [esp+20h] [ebp-58h]
  int iIdx; // [esp+24h] [ebp-54h]
  int iAllianceId; // [esp+28h] [ebp-50h]
  BYTE v19; // [esp+30h] [ebp-48h]
  int iLivePoints; // [esp+34h] [ebp-44h]
  ISettlerRole *v21; // [esp+3Ch] [ebp-3Ch]
  ISettlerRole *v22; // [esp+40h] [ebp-38h]
  int v23; // [esp+44h] [ebp-34h]
  unsigned int v24; // [esp+48h] [ebp-30h]
  int iMaxLivePoints; // [esp+4Ch] [ebp-2Ch]
  signed int v26; // [esp+50h] [ebp-28h]
  int iTileOwnerId; // [esp+54h] [ebp-24h]
  int LocalPlayerId; // [esp+58h] [ebp-20h]
  BYTE uColor; // [esp+60h] [ebp-18h]
  unsigned int iRace; // [esp+64h] [ebp-14h]
  signed int iFrame; // [esp+68h] [ebp-10h]
  unsigned int iJobPart; // [esp+6Ch] [ebp-Ch]

  if ( IEntity::FlagBits(this, ENTITY_FLAG_Died) )
    return 0;
  if ( !IEntity::IsVisible(this) )
    return 0;
  if ( CInputProcessor::IsBoxSelection(&g_cInputProcessor) )
    IAnimatedEntity::BoxSelection();
  pRole = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  ISettlerRole::Update(pRole, this);
  iRace = IEntity::Race(this);
  if ( IEntity::FlagBits(this, ENTITY_FLAG_Ownerless) )
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    iAllianceId = CAlliances::AllianceId(LocalPlayerId);
    iOwnerId = IEntity::OwnerId(this);
    if ( CAlliances::AllianceId(iOwnerId) == iAllianceId )
    {
      iOwnerId = IEntity::OwnerId(this);
      uColor = CPlayerManager::Color(iOwnerId);
      iJobPart = this->m_iJobPart;
      iFrame = this->m_iFrame;
    }
    else
    {
      iPackedXY = IEntity::PackedXY(this);
      iIdx = CWorldManager::Index(iPackedXY);
      iTileOwnerId = ITiling::OwnerId(iIdx);
      if ( iTileOwnerId )
      {
        uColor = CPlayerManager::Color(iTileOwnerId);
        iRace = CPlayerManager::Race(iTileOwnerId);
      }
      else
      {
        uColor = CPlayerManager::Color(LocalPlayerId);
        iRace = CPlayerManager::Race(LocalPlayerId);
      }
      if ( this->m_iJobPart == 0x12F || this->m_iJobPart == 304 )
      {
        if ( iTileOwnerId )
          v24 = 44;
        else
          v24 = 300;
        iJobPart = v24;
        m_iFrame = this->m_iFrame;
        SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount(g_pGfxManager, iRace, this->m_iJobPart, 2u);
        v26 = CGfxManager::GetSettlerJobFrameCount(g_pGfxManager, iRace, v24, 2u);
        iFrame = m_iFrame - (int)(SettlerJobFrameCount - v26) / 2;
        if ( iFrame >= 0 )
        {
          if ( iFrame >= v26 )
            iFrame = v26 - 1;
        }
        else
        {
          iFrame = 0;
        }
      }
      else
      {
        if ( iTileOwnerId )
          v23 = CSettler::Role(this)->unk_0B + 1;
        else
          v23 = 298;
        iJobPart = v23;
        iFrame = this->m_iFrame;
      }
    }
  }
  else
  {
    if ( IEntity::FlagBits(this, (EntityFlag)0x8000000)
      && ((v22 = CSettler::Role(this), v22->GetSettlerRole(v22) == 7)
       || (v21 = CSettler::Role(this), v21->GetSettlerRole(v21) == 23))
      && IEntity::Race(this) != 3 )
    {
      v14 = CPlayerManager::GetLocalPlayerId();
      v13 = CAlliances::PlayerAllyBits(v14);
      v6 = IEntity::OwnerId(this);
      if ( (v13 & CAlliances::PlayerAllyBits(v6)) == 0 )
        return 0;
      switch ( IEntity::Type(this) )
      {
        case 29:
        case 30:
        case 31:
          iJobPart = 229;
          break;
        case 32:
        case 33:
        case 34:
          iJobPart = 241;
          break;
        case 35:
        case 36:
        case 37:
          iJobPart = 257;
          break;
        case 38:
        case 39:
        case 40:
          iJobPart = 268;
          break;
        case 41:
        case 42:
        case 43:
          iJobPart = 277;
          break;
        case 44:
          iJobPart = 286;
          break;
        case 61:
        case 62:
        case 63:
          iJobPart = 343;
          break;
        default:
          iJobPart = this->m_iJobPart;
          break;
      }
    }
    else
    {
      iJobPart = this->m_iJobPart;
    }
    v7 = IEntity::OwnerId(this);
    uColor = CPlayerManager::Color(v7);
    iFrame = this->m_iFrame;
  }
  v8 = IEntity::EntityId(this);
  if ( v8 == IHJBMgr::GetHJBEntityId() && IHJBMgr::LocalIsHJBGfxLoaded() )
    iRace = 5;
  CGfxManager::GetSettlerGfxInfo(g_pGfxManager, &IEntity::m_sGfxInfo, iRace, iJobPart, iFrame, this->m_iDirection);
  if ( IEntity::FlagBits(this, (EntityFlag)0x800) )
  {
    IEntity::m_sGfxInfo.m_iDirection = -1;
    IEntity::m_sGfxInfo.m_iOffsetX = (int)std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior)->m_fOffsetX;
    IEntity::m_sGfxInfo.m_iOffsetY = (int)std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior)->m_fOffsetY;
  }
  else
  {
    IEntity::m_sGfxInfo.m_iDirection = this->m_iDirection;
    IEntity::m_sGfxInfo.m_iOffsetX = 0;
    IEntity::m_sGfxInfo.m_iOffsetY = 0;
  }
  IEntity::m_sGfxInfo.m_uFlags = 0;
  if ( IEntity::FlagBits(this, ENTITY_FLAG_Selected) )
  {
    pRole = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
    IEntity::m_sGfxInfo.m_uFlags = ((int (__thiscall *)(ISettlerRole *, CSettler *))pRole->GetKindOfSelection)(
                                     pRole,
                                     this);
    v11 = IEntity::Type(this);
    v10 = IEntity::Race(this);
    SettlerInfo = CSettlerMgr::GetSettlerInfo(v10, v11);
    iMaxLivePoints = SettlerInfo->m_iMaxLifePoints;
    if ( SettlerInfo->m_iMaxLifePoints )
    {
      iLivePoints = this->m_iLivePoints;
      if ( iLivePoints > iMaxLivePoints
        && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 1050, "iLivePoints <= iMaxLivePoints") == 1 )
      {
        __debugbreak();
      }
      IEntity::m_sGfxInfo.m_uDecorator = 9 - 7 * iLivePoints / iMaxLivePoints;
    }
  }
  else if ( IEntity::FlagBits(this, (EntityFlag)1024) )
  {
    if ( IEntity::FlagBits(this, (EntityFlag)1024) )
      v19 = 91;
    else
      v19 = 0;
    IEntity::m_sGfxInfo.m_uFlags = v19;
  }
  if ( IEntity::FlagBits(this, (EntityFlag)0xF00000) )
  {
    if ( IEntity::FlagBits(this, (EntityFlag)0x100000) )
    {
      IEntity::m_sGfxInfo.m_u0 = 32;
    }
    else if ( IEntity::FlagBits(this, (EntityFlag)0x200000) )
    {
      IEntity::m_sGfxInfo.m_u0 = 35;
    }
    else if ( IEntity::FlagBits(this, (EntityFlag)0x400000) )
    {
      IEntity::m_sGfxInfo.m_u0 = 33;
    }
    else
    {
      IEntity::m_sGfxInfo.m_u0 = 34;
    }
  }
  IEntity::m_sGfxInfo.m_iDistance = this->m_iDistance;
  IEntity::m_sGfxInfo.m_bIsVisible = IEntity::IsVisible(this);
  IEntity::m_sGfxInfo.m_iColor = uColor;
  IEntity::m_sGfxInfo.m_uObjType = this->m_uObjType;
  return &IEntity::m_sGfxInfo;
}


// address=[0x157dae0]
// Decompiled from void __thiscall CSettler::GetPatchGfx(CSettler *this, struct SGfxPatchObject *a2)
void  CSettler::GetPatchGfx(struct SGfxPatchObject & a2) {
  
  ISettlerRole *v2; // eax
  unsigned int iType; // eax
  unsigned int wJobPart; // [esp-Ch] [ebp-10h]
  unsigned int cFrame; // [esp-8h] [ebp-Ch]
  unsigned int iDirection; // [esp-4h] [ebp-8h]

  v2 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  ISettlerRole::Update(v2, this);
  if ( IEntity::FlagBits(this, ENTITY_FLAG_Visible) )
  {
    iDirection = this->m_iDirection;
    cFrame = this->m_iFrame;
    wJobPart = this->m_iJobPart;
    iType = IEntity::Race(this);
    CGfxManager::GetPatchSettlerGfxInfo(g_pGfxManager, a2, iType, wJobPart, cFrame, iDirection);
    a2->m_iOffsetX = (int)std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior)->m_fOffsetX;
    a2->m_iOffsetY = (int)std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior)->m_fOffsetY;
  }
}


// address=[0x157db70]
// Decompiled from void __thiscall CSettler::NewRole(CSettler *this, auto_ptr_ISettlerRole a2)
void  CSettler::NewRole(class std::auto_ptr<class ISettlerRole> a2) {
  
  int v2; // eax
  int v3; // [esp+4h] [ebp-1Ch] BYREF
  struct ISettlerRole *v4; // [esp+8h] [ebp-18h]
  struct ISettlerRole *v5; // [esp+Ch] [ebp-14h]
  int v7; // [esp+1Ch] [ebp-4h]

  v7 = 0;
  if ( IEntity::FlagBits(this, ENTITY_FLAG_Died) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
    v7 = -1;
    std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
  }
  else
  {
    if ( !std::auto_ptr<ISettlerRole>::get(&this->m_pBehavior)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 549, "m_pBehavior.get()!=NULL") == 1 )
    {
      __debugbreak();
    }
    IEntity::RemoveFromAllGroups();
    std::auto_ptr<ISettlerRole>::operator=(&a2);
    v5 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
    v5->Init(v5, this);
    v4 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
    v2 = v4->InitWalking(v4, this);
    std::auto_ptr<CWalking>::auto_ptr<CWalking>(&v3, v2);
    std::auto_ptr<CWalking>::operator=(&v3);
    std::auto_ptr<CWalking>::~auto_ptr<CWalking>(&v3);
    v7 = -1;
    std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
  }
}


// address=[0x157dca0]
// Decompiled from void __thiscall CSettler::NewToDoList(CSettler *this, int a2, __int16 a3)
void  CSettler::NewToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > * a2, int a3) {
  
  unsigned int v3; // eax
  unsigned int v4; // [esp-4h] [ebp-30h]
  _BYTE v5[12]; // [esp+4h] [ebp-28h] BYREF
  int v6; // [esp+10h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-18h]
  struct ISettlerRole *pSettlerRole; // [esp+18h] [ebp-14h]
  int v10; // [esp+28h] [ebp-4h]

  if ( IEntity::FlagBits(this, ENTITY_FLAG_Died) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
  }
  else if ( a2 )
  {
    this->m_iToDoSize = a3;
    this->m_pToDoList = (std::list *)a2;
    v7 = std::list<CEntityTask>::begin(this->m_pToDoList);
    v6 = v7;
    v10 = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(
      &this->m_cCurrentToDoItemIter,
      v7);
    v10 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v5);
    pSettlerRole = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
    pSettlerRole->TakeJob(pSettlerRole, this);
  }
  else
  {
    v4 = IEntity::Type(this);
    v3 = IEntity::Race(this);
    if ( CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v3, v4) )
      CSettler::TakeWaitList(this);
  }
}


// address=[0x157dda0]
// Decompiled from void __thiscall CSettler::TakeWaitList(CSettler *this)
void  CSettler::TakeWaitList(void) {
  
  unsigned int v1; // eax
  std::list *v2; // eax
  unsigned int v3; // [esp-8h] [ebp-Ch]
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type(this);
  v3 = IEntity::Type(this);
  v1 = IEntity::Race(this);
  v2 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v1, v3);
  this->NewToDoList(this, (int)v2, v4);
}


// address=[0x157dde0]
// Decompiled from void __thiscall CSettler::TakeAnimList(CSettler *this, int _iAnimListIndex)
void  CSettler::TakeAnimList(int _iAnimListIndex) {
  
  int v2; // eax
  unsigned int v3; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-18h]
  int v6; // [esp-4h] [ebp-18h]
  int iNumberOfAnimLists; // [esp+0h] [ebp-14h]
  int pWorkList; // [esp+4h] [ebp-10h]
  unsigned int v9; // [esp+8h] [ebp-Ch]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+Ch] [ebp-8h]

  v5 = IEntity::Type(this);
  v2 = IEntity::Race(this);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v2, v5);
  iNumberOfAnimLists = std::vector<unsigned short>::size(SettlerInfo->g_vAnimLists);
  if ( (_iAnimListIndex < 0 || _iAnimListIndex >= iNumberOfAnimLists)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\Settler.cpp",
         804,
         "(_iAnimListIndex >= 0) && (_iAnimListIndex < iNumberOfAnimLists)") == 1 )
  {
    __debugbreak();
  }
  v9 = *std::vector<unsigned short>::operator[](_iAnimListIndex);
  v3 = IEntity::Race(this);
  pWorkList = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v3, v9);
  if ( !pWorkList )
  {
    v6 = IEntity::Type(this);
    v4 = IEntity::Race(this);
    if ( BBSupportDbgReportF(
           2,
           "MapObjects\\Settler\\Settler.cpp",
           810,
           "No work list -> Data Wizard! Race %d, SettlerType %d",
           v4,
           v6) == 1 )
      __debugbreak();
  }
  this->NewToDoList(this, pWorkList, v9);
}


// address=[0x157ded0]
// Decompiled from void __thiscall CSettler::AttachToBuilding(CSettler *this, int a1)
void  CSettler::AttachToBuilding(int a1) {
  
  int v2; // eax
  CBuilding *v3; // [esp+0h] [ebp-8h]

  if ( std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior)->m_uHomeEntityId
    && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 1388, "m_pBehavior->m_uHomeEntityId == 0") == 1 )
  {
    __debugbreak();
  }
  v3 = CBuildingMgr::operator[](a1);
  v2 = IEntity::EntityId(this);
  (*(void (__thiscall **)(CBuilding *, int))(*(_DWORD *)v3 + 116))(v3, v2);
  if ( !IEntity::FlagBits(this, ENTITY_FLAG_ATTACHED)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 1397, "FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x157df70]
// Decompiled from void __thiscall CSettler::CheckFlee(CSettler *this, int a2)
void  CSettler::CheckFlee(int a2) {
  
  IEntity::WarriorType(this);
}


// address=[0x157df90]
// Decompiled from void __thiscall CSettler::ChangeType(CSettler *this, unsigned int _iNewSettlerType, char a3, char a4)
void  CSettler::ChangeType(int _iNewSettlerType, bool a3, bool a4) {
  
  int worldIdx; // eax
  int sectorOwner; // esi MAPDST
  int v8; // eax
  int owner; // eax
  int HJBPlayerId; // esi
  struct CFrameWnd *v12; // eax
  unsigned int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int race; // eax MAPDST
  CSettlerMgr::SSettlerInfos *settlerInfo; // eax MAPDST
  int v20; // eax
  int v21; // [esp-Ch] [ebp-60h]
  int v22; // [esp-8h] [ebp-5Ch]
  int type; // [esp-4h] [ebp-58h] MAPDST BYREF
  int aiEvent; // [esp-4h] [ebp-58h] SPLIT
  auto_ptr_ISettlerRole *v25; // [esp+8h] [ebp-4Ch]
  int *p_type; // [esp+Ch] [ebp-48h]
  unsigned int v27; // [esp+10h] [ebp-44h]
  ISettlerRole *v28; // [esp+14h] [ebp-40h]
  int v29; // [esp+18h] [ebp-3Ch]
  auto_ptr_ISettlerRole a2; // [esp+20h] [ebp-34h] BYREF
  ISettlerRole *v32; // [esp+24h] [ebp-30h]
  void *C; // [esp+28h] [ebp-2Ch]
  unsigned int m_uTool; // [esp+30h] [ebp-24h]
  ISettlerRole *role; // [esp+34h] [ebp-20h] MAPDST
  ISettlerRole *SettlerRole; // [esp+38h] [ebp-1Ch]
  int iESId; // [esp+3Ch] [ebp-18h]
  unsigned __int16 *rEcoSector; // [esp+40h] [ebp-14h]
  int v41; // [esp+50h] [ebp-4h]

  if ( IEntity::FlagBits(this, ENTITY_FLAG_Died) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
  }
  else
  {
    if ( IEntity::Type(this) == _iNewSettlerType
      && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 577, "Type() != _iNewSettlerType") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::FlagBits(this, ENTITY_FLAG_Offered)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 579, "!FlagBits(ENTITY_FLAG_OFFERED)") == 1 )
    {
      __debugbreak();
    }
    role = CSettler::Role(this);
    if ( role->GetSettlerRole(role) == 18
      && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 580, "Role().GetSettlerRole() != FLEE_ROLE") == 1 )
    {
      __debugbreak();
    }
    worldIdx = IEntity::WorldIdx();
    iESId = CWorldManager::EcoSectorId(worldIdx);
    if ( !iESId && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 583, "iESId != 0") == 1 )
      __debugbreak();
    if ( iESId )
    {
      rEcoSector = (unsigned __int16 *)CEcoSectorMgr::operator[](g_cESMgr, iESId);
      sectorOwner = CEcoSector::Owner(rEcoSector);
      if ( sectorOwner != IEntity::OwnerId(this)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 587, "rEcoSector.Owner() == OwnerId()") == 1 )
      {
        __debugbreak();
      }
      sectorOwner = CEcoSector::Owner(rEcoSector);
      if ( sectorOwner == IEntity::OwnerId(this) )
      {
        if ( _iNewSettlerType == 1 )
        {
          type = IEntity::Type(this);
          race = IEntity::Race(this);
          settlerInfo = CSettlerMgr::GetSettlerInfo(race, type);
          m_uTool = settlerInfo->m_uTool;
          if ( m_uTool )
          {
            v21 = IEntity::Y(this);
            v8 = IEntity::X(this);
            CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v8, v21, m_uTool, 1u);
          }
          if ( IEntity::WarriorType(this) )
            CSettlerMgr::DetachSettler(&g_cSettlerMgr, this);
        }
        type = IEntity::Type(this);
        owner = IEntity::OwnerId(this);
        CSettlerMgr::DecNumberOfSettler(&g_cSettlerMgr, owner, (S4_SETTLER_ENUM)type);
        if ( IEntity::WarriorType(this) == AI_WARRIOR_TYPE_NONE )
        {
          type = IEntity::Type(this);
          CEcoSector::ChangeNrOfSettler((CEcoSector *)rEcoSector, type, -1);
        }
        role = CSettler::Role(this);
        if ( role->GetSettlerRole(role) == 19 )
          CSettler::SetFree(this);
        v27 = IEntity::Type(this);
        CWarMap::RemoveEntity(this);
        this->m_nType = _iNewSettlerType;
        v29 = CSettlerMgr::SettlerWarriorType(this->m_nType);
        this->m_iFlags &= 0xFFFFFFF0;
        this->m_iFlags |= v29;
        this->m_iFlags &= ~0x10000000u;
        CWarMap::AddEntity(this);
        SettlerRole = 0;
        if ( IHJBMgr::GetHJBPlayerId()
          && (HJBPlayerId = IHJBMgr::GetHJBPlayerId(), HJBPlayerId == IEntity::OwnerId(this))
          && !IHJBMgr::GetHJBEntityId()
          && _iNewSettlerType == 44 )
        {
          v12 = (struct CFrameWnd *)IEntity::EntityId(this);
          IHJBMgr::SetHJBEntityId(v12);
          C = operator new(0x80u);
          v41 = 0;
          if ( C )
            v32 = (ISettlerRole *)CHJBRole::CHJBRole(C);
          else
            v32 = 0;
          v28 = v32;
          v41 = -1;
          SettlerRole = v32;
        }
        else
        {
          v13 = IEntity::Race(this);
          SettlerRole = CSettlerMgr::CreateSettlerRole(&g_cSettlerMgr, v13, _iNewSettlerType);
        }
        std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&a2, SettlerRole);
        v41 = 1;
        type = v14;
        p_type = &type;
        v25 = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&type, &a2);
        CSettler::NewRole(this, (auto_ptr_ISettlerRole)type);
        if ( a3 )
          CSettler::TakeWaitList(this);
        type = IEntity::Type(this);
        v15 = IEntity::OwnerId(this);
        CSettlerMgr::IncNumberOfSettler(&g_cSettlerMgr, v15, (S4_SETTLER_ENUM)type);
        if ( IEntity::WarriorType(this) )
        {
          CSettlerMgr::AttachSettler(&g_cSettlerMgr, this);
          if ( IEntity::FlagBits(this, (EntityFlag)1024) )
          {
            IEntity::ClearFlagBits(this, (EntityFlag)1024);
            IEntity::SetFlagBits(this, ENTITY_FLAG_Selected);
          }
        }
        else
        {
          type = 1;
          v16 = IEntity::Type(this);
          CEcoSector::ChangeNrOfSettler((CEcoSector *)rEcoSector, v16, type);
          if ( a4 )
          {
            type = IEntity::EntityId(this);
            v17 = IEntity::Type(this);
            CEcoSector::SetSettlerOffer(rEcoSector, v17, type);
          }
        }
        type = IEntity::Type(this);
        race = IEntity::Race(this);
        settlerInfo = CSettlerMgr::GetSettlerInfo(race, type);
        this->m_iLivePoints = settlerInfo->m_iMaxLifePoints;
        aiEvent = CAIEvent::Pack(v27, _iNewSettlerType);
        v22 = IEntity::ID(this);
        v20 = IEntity::OwnerId(this);
        g_pAI->PostAIEvent(g_pAI, 22, v20, v22, aiEvent);
        v41 = -1;
        std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
      }
    }
  }
}


// address=[0x157e450]
// Decompiled from void __thiscall CSettler::ChangeTypeComeToBuilding(CSettler *this, unsigned int a2, int a3)
void  CSettler::ChangeTypeComeToBuilding(int a2, int a3) {
  
  CEntityEvent v3; // [esp+4h] [ebp-30h] BYREF
  struct CEntityEvent *v4; // [esp+1Ch] [ebp-18h]
  struct CEntityEvent *v5; // [esp+20h] [ebp-14h]
  int v7; // [esp+30h] [ebp-4h]

  if ( !IEntity::FlagBits(this, ENTITY_FLAG_Died) )
  {
    CSettler::ChangeType(this, a2, 1, 0);
    CSettler::SetBuilding(this, a3);
    v5 = CEntityEvent::CEntityEvent(&v3, 1u, 0, a3, 0, 0);
    v4 = v5;
    v7 = 0;
    this->SetEvent(this, v5);
    v7 = -1;
    CEntityEvent::~CEntityEvent(&v3);
  }
}


// address=[0x157e500]
// Decompiled from uint __cdecl CSettler::operator new(uint a1)
void * __cdecl CSettler::operator new(unsigned int a1) {
  
  return CSettlerMgr::Alloc(&g_cSettlerMgr, a1);
}


// address=[0x157e520]
// Decompiled from void __cdecl CSettler::operator delete(_DWORD *a1)
void __cdecl CSettler::operator delete(void * a1) {
  
  CSettlerMgr::Dealloc(&g_cSettlerMgr, a1);
}


// address=[0x157e560]
// Decompiled from void __thiscall CSettler::SetObserverTarget(CSettler *this, int a2, int a3)
void  CSettler::SetObserverTarget(enum T_OBSERVER_TARGET a2, int a3) {
  
  struct ISettlerRole *v3; // eax
  int v4; // ecx

  v3 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v3->SetObserverTarget(v3, a2, a3);
  if ( !a2 )
  {
    if ( a3 <= 0 )
      v4 = this->m_iFlags & 0xFFFFFFDF;
    else
      v4 = this->m_iFlags | 0x20;
    this->m_iFlags = v4;
  }
}


// address=[0x157e5c0]
// Decompiled from int __thiscall CSettler::GetObserverTarget(CSettler *this, int a2)
int  CSettler::GetObserverTarget(enum T_OBSERVER_TARGET a2) {
  
  struct ISettlerRole *v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  return v3->GetObserverTarget(v3, a2);
}


// address=[0x157e5f0]
// Decompiled from int __thiscall CSettler::Increase(IEntity *this, int a2)
int  CSettler::Increase(int a2) {
  
  int v3; // [esp+8h] [ebp-14h]
  int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+10h] [ebp-Ch]
  int m_iMaxLifePoints; // [esp+14h] [ebp-8h]

  v3 = IEntity::Race(this);
  v4 = IEntity::Type(this);
  m_iMaxLifePoints = CSettlerMgr::GetSettlerInfo(v3, v4)->m_iMaxLifePoints;
  if ( a2 >= 0 )
  {
    v5 = a2 + this->m_iLivePoints;
    if ( v5 > m_iMaxLifePoints )
      this->m_iLivePoints = m_iMaxLifePoints;
    else
      this->m_iLivePoints = v5;
  }
  else
  {
    this->m_iLivePoints = m_iMaxLifePoints;
  }
  return this->m_iLivePoints;
}


// address=[0x157e680]
// Decompiled from void __thiscall CSettler::MarkSourcePile2AsUnused(CSettler *this)
void  CSettler::MarkSourcePile2AsUnused(void) {
  
  struct ISettlerRole *v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  ISettlerRole::MarkPileAsUnused(v1, 3);
}


// address=[0x157e6a0]
// Decompiled from void __thiscall CSettler::MarkSourcePile3AsUnused(CSettler *this)
void  CSettler::MarkSourcePile3AsUnused(void) {
  
  struct ISettlerRole *v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  ISettlerRole::MarkPileAsUnused(v1, 4);
}


// address=[0x157e6c0]
// Decompiled from int __thiscall CSettler::MaxHitpoints(CSettler *this)
int  CSettler::MaxHitpoints(void)const {
  
  int race; // [esp+4h] [ebp-Ch]
  int type; // [esp+8h] [ebp-8h]

  race = IEntity::Race(this);
  type = IEntity::Type(this);
  return CSettlerMgr::GetSettlerInfo(race, type)->m_iMaxLifePoints;
}


// address=[0x157e700]
// Decompiled from CSettler *__thiscall CSettler::CSettler(CSettler *this, struct std::istream *stream)
 CSettler::CSettler(std::istream & stream) {
  
  unsigned int v2; // eax
  std::list *v3; // eax
  int v4; // eax
  int v5; // eax
  __int16 v6; // ax
  unsigned int v7; // eax
  std::list *v8; // eax
  __int16 v9; // ax
  unsigned int v10; // eax
  std::list *v11; // eax
  int v13; // [esp-8h] [ebp-78h]
  unsigned int v14; // [esp-4h] [ebp-74h]
  int v15; // [esp-4h] [ebp-74h]
  int v16; // [esp-4h] [ebp-74h]
  unsigned int v17; // [esp-4h] [ebp-74h]
  unsigned int v18; // [esp-4h] [ebp-74h]
  _BYTE v19[12]; // [esp+4h] [ebp-6Ch] BYREF
  _BYTE v20[12]; // [esp+10h] [ebp-60h] BYREF
  _BYTE v21[12]; // [esp+1Ch] [ebp-54h] BYREF
  int v22; // [esp+28h] [ebp-48h]
  int v23; // [esp+2Ch] [ebp-44h]
  int v24; // [esp+30h] [ebp-40h]
  int v25; // [esp+34h] [ebp-3Ch]
  int v26; // [esp+38h] [ebp-38h]
  int v27; // [esp+3Ch] [ebp-34h]
  ISettlerRole *pSettlerRole; // [esp+40h] [ebp-30h]
  int fileFormatVersion; // [esp+48h] [ebp-28h] MAPDST BYREF
  auto_ptr_ISettlerRole v31; // [esp+4Ch] [ebp-24h] BYREF
  struct ISettlerRole *v32; // [esp+50h] [ebp-20h]
  int pExceptionObject; // [esp+54h] [ebp-1Ch] BYREF
  __int16 iTodoSize; // [esp+5Ch] [ebp-14h] BYREF
  unsigned __int8 iSettlerRole; // [esp+62h] [ebp-Eh] BYREF
  unsigned __int8 iEntityTaskCount; // [esp+63h] [ebp-Dh] BYREF
  int exceptionBlock; // [esp+6Ch] [ebp-4h]

  IMovingEntity::IMovingEntity(this, (int)stream);
  exceptionBlock = 0;
  this->__vftable = (CSettler_vtbl *)&CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&this->m_pBehavior, 0);
  LOBYTE(exceptionBlock) = 1;
  iEntityTaskCount = 0;
  operator^<unsigned int>(stream, &fileFormatVersion);
  if ( fileFormatVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSettler");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<short>(stream, &iTodoSize);
  if ( iTodoSize != -1 )
    operator^<unsigned char>(stream, &iEntityTaskCount);
  operator^<unsigned char>(stream, &iSettlerRole);
  pSettlerRole = CSettlerMgr::LoadSettlerRole(stream, iSettlerRole);
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&v31, pSettlerRole);
  LOBYTE(exceptionBlock) = 2;
  std::auto_ptr<ISettlerRole>::operator=(&this->m_pBehavior, (int *)&v31);
  if ( iTodoSize == -1 )
  {
    v9 = IEntity::Type(this);
    this->m_iToDoSize = v9;
    v18 = IEntity::Type(this);
    v10 = IEntity::Race(this);
    v11 = (std::list *)CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v10, v18);
    this->m_pToDoList = v11;
    v23 = std::list<CEntityTask>::begin(this->m_pToDoList);
    v22 = v23;
    LOBYTE(exceptionBlock) = 5;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(
      &this->m_cCurrentToDoItemIter,
      v23);
    LOBYTE(exceptionBlock) = 2;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v19);
  }
  else
  {
    this->m_iToDoSize = iTodoSize;
    v14 = iTodoSize;
    v2 = IEntity::Race(this);
    v3 = (std::list *)CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v2, v14);
    this->m_pToDoList = v3;
    if ( !this->m_pToDoList )
    {
      v15 = IEntity::Type(this);
      v4 = IEntity::Race(this);
      if ( BBSupportDbgReportF(
             2,
             "MapObjects\\Settler\\Settler.cpp",
             348,
             "No ToDoList -> Outdated Savegame? Race:%u, Type:%u",
             v4,
             v15) == 1 )
        __debugbreak();
    }
    if ( this->m_pToDoList )
    {
      v27 = std::list<CEntityTask>::begin(this->m_pToDoList);
      v26 = v27;
      LOBYTE(exceptionBlock) = 3;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(
        &this->m_cCurrentToDoItemIter,
        v27);
      LOBYTE(exceptionBlock) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v21);
      while ( iEntityTaskCount )
      {
        std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(&this->m_cCurrentToDoItemIter);
        --iEntityTaskCount;
      }
    }
    else
    {
      v16 = IEntity::ID(this);
      v13 = iTodoSize;
      v5 = IEntity::Race(this);
      BBSupportTracePrintF(3, "Can't find doDoList for race=%d,id=%d, for EntityID = %d", v5, v13, v16);
      v6 = IEntity::Type(this);
      this->m_iToDoSize = v6;
      v17 = IEntity::Type(this);
      v7 = IEntity::Race(this);
      v8 = (std::list *)CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v7, v17);
      this->m_pToDoList = v8;
      v25 = std::list<CEntityTask>::begin(this->m_pToDoList);
      v24 = v25;
      LOBYTE(exceptionBlock) = 4;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(
        &this->m_cCurrentToDoItemIter,
        v25);
      LOBYTE(exceptionBlock) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v20);
    }
  }
  v32 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v32->PostLoadInit(v32, this);
  if ( !std::list<CEntityTask>::size(this->m_pToDoList)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 377, "m_toDoList->size()>0") == 1 )
  {
    __debugbreak();
  }
  LOBYTE(exceptionBlock) = 1;
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&v31);
  return this;
}


// address=[0x157ea60]
// Decompiled from void __thiscall CSettler::Store(CSettler *this, struct std::ostream *a1)
void  CSettler::Store(std::ostream & a1) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-44h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-38h] BYREF
  std::_Iterator_base12 *v4; // [esp+1Ch] [ebp-2Ch]
  std::_Iterator_base12 *v5; // [esp+20h] [ebp-28h]
  int v6; // [esp+24h] [ebp-24h] BYREF
  struct ISettlerRole *v7; // [esp+28h] [ebp-20h]
  struct ISettlerRole *v8; // [esp+2Ch] [ebp-1Ch]
  struct ISettlerRole *v9; // [esp+30h] [ebp-18h]
  char v11; // [esp+39h] [ebp-Fh]
  byte iRole; // [esp+3Ah] [ebp-Eh] BYREF
  unsigned __int8 a2; // [esp+3Bh] [ebp-Dh] BYREF
  int v14; // [esp+44h] [ebp-4h]

  IMovingEntity::Store(this, a1);
  v6 = 1;
  operator^<unsigned int>(a1, &v6);
  operator^<short>(a1, &this->m_iToDoSize);
  if ( this->m_iToDoSize != -1 )
  {
    a2 = 0;
    std::list<CEntityTask>::begin(this->m_pToDoList);
    v14 = 0;
    while ( 1 )
    {
      v5 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(this->m_pToDoList);
      v4 = v5;
      LOBYTE(v14) = 1;
      v11 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v5);
      LOBYTE(v14) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
      if ( !v11
        || std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(
             (std::_Iterator_base12 *)v3,
             (std::_Iterator_base12 *)&this->m_cCurrentToDoItemIter) )
      {
        break;
      }
      ++a2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v3);
    }
    v14 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
    operator^<unsigned char>(a1, &a2);
  }
  v9 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  iRole = v9->GetSettlerRole(v9);
  if ( iRole == 23 )                            // Squad Leader Role
  {
    v8 = std::auto_ptr<ISettlerRole>::get(&this->m_pBehavior);
    if ( ((unsigned __int8 (__thiscall *)(struct ISettlerRole *))v8->__vftable[1].ClassID)(v8) )// IsHJB
      iRole = 24;
  }
  operator^<unsigned char>(a1, &iRole);
  v7 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v7->Store(a1);
}


// address=[0x157ff80]
// Decompiled from int __thiscall CSettler::ClassID(CSettler *this)
unsigned long  CSettler::ClassID(void)const {
  
  return CSettler::m_iClassID;
}


// address=[0x157ffa0]
// Decompiled from int __thiscall CSettler::ClearGroupFlagBits(CSettler *this, int a2)
int  CSettler::ClearGroupFlagBits(int a2) {
  
  struct ISettlerRole *v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  return v3->ClearGroupFlagBits(v3, a2);
}


// address=[0x1580040]
// Decompiled from int __thiscall CSettler::GetGroupFlags(CSettler *this)
int  CSettler::GetGroupFlags(void)const {
  
  struct ISettlerRole *v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  return v1->GetGroupFlags(v1, this, v1);
}


// address=[0x1580080]
// Decompiled from int __thiscall CSettler::GetWarriorBehavior(_DWORD *this)
class CWarriorBehavior *  CSettler::GetWarriorBehavior(void)const {
  
  struct ISettlerRole *v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->(this + 25);
  return v1->GetWarriorBehavior(v1, this, v1);
}


// address=[0x15800c0]
// Decompiled from int __thiscall CSettler::IsUnEmployed(CSettler *this)
bool  CSettler::IsUnEmployed(void)const {
  
  struct ISettlerRole *v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  return v1->IsUnEmployed(v1, this, v1);
}


// address=[0x1580130]
// Decompiled from int __thiscall CSettler::SetGroupFlagBits(CSettler *this, int a2)
int  CSettler::SetGroupFlagBits(int a2) {
  
  struct ISettlerRole *v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  return v3->SetGroupFlagBits(v3, a2);
}


// address=[0x1580170]
// Decompiled from int __thiscall CSettler::SetGroupFlags(CSettler *this, int a2)
int  CSettler::SetGroupFlags(int a2) {
  
  struct ISettlerRole *v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  return v3->SetGroupFlags(v3, a2);
}


// address=[0x3d8befc]
// [Decompilation failed for static unsigned long CSettler::m_iClassID]

// address=[0x157ec10]
// Decompiled from CSettler *__thiscall CSettler::CSettler(  CSettler *this,  int _iX,  int _iY,  int _iSettlerType,  int _iPlayer,  struct ISettlerRole *_pSettlerRole,  int _iId)
 CSettler::CSettler(int _iX, int _iY, int _iSettlerType, int _iPlayer, class std::auto_ptr<class ISettlerRole> _pSettlerRole, int _iId) {
  
  CPlayerInfo *playerInfo; // eax
  unsigned __int8 race; // al
  int race2; // eax
  int worldIdx; // eax
  int v11; // eax
  int v13; // [esp+Ch] [ebp-24h] BYREF
  struct ISettlerRole *v14; // [esp+10h] [ebp-20h]
  int ecoSectorId; // [esp+18h] [ebp-18h]
  unsigned __int16 *ecoSector; // [esp+1Ch] [ebp-14h]
  int v19; // [esp+2Ch] [ebp-4h]

  v19 = 0;
  IMovingEntity::IMovingEntity(this, _iId);
  this->__vftable = (CSettler_vtbl *)&CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(
    (auto_ptr_ISettlerRole *)&this->m_pBehavior,
    (auto_ptr_ISettlerRole *)&_pSettlerRole);
  LOBYTE(v19) = 2;
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CSettler::CSettler(): entity id %u, player %u, settler type %u, position (%i, %i)",
    _iId,
    _iPlayer,
    _iSettlerType,
    _iX,
    _iY);
  this->m_iDistance = 0;
  IEntity::SetPosition(this, _iX, _iY);
  this->m_uObjType = Settler;
  this->m_nType = _iSettlerType;
  this->m_iDirection = CGameData::Rand(g_pGameData) % 6;
  IEntity::SetOwnerId(this, _iPlayer);
  playerInfo = CPlayerManager::PlayerInfo(_iPlayer);
  race = CPlayerInfo::Race(playerInfo);
  IEntity::SetRace(this, race);
  race2 = IEntity::Race(this);
  this->m_iLivePoints = CSettlerMgr::GetSettlerInfo(race2, _iSettlerType)->m_iMaxLifePoints;
  IEntity::ClearFlagBits(this, (EntityFlag)10240);
  IEntity::SetFlagBits(this, ENTITY_FLAG_Ready|ENTITY_FLAG_Visible|0x1000);
  this->m_iFlags |= CSettlerMgr::SettlerWarriorType(_iSettlerType);
  if ( IEntity::WarriorType(this) == AI_WARRIOR_TYPE_NONE )
  {
    worldIdx = IEntity::WorldIdx();
    ecoSectorId = CWorldManager::EcoSectorId(worldIdx);
    if ( ecoSectorId )
    {
      ecoSector = (unsigned __int16 *)CEcoSectorMgr::operator[](g_cESMgr, ecoSectorId);
      if ( CEcoSector::Owner(ecoSector) == _iPlayer )
      {
        CEcoSector::ChangeNrOfSettler((CEcoSector *)ecoSector, this->m_nType, 1);
        if ( IEntity::Type(this) != 1 )
          CEcoSector::SetSettlerOffer(ecoSector, this->m_nType, this->m_nEntityId);
      }
    }
  }
  if ( CWorldManager::MapObjectId(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 112, "g_cWorld.MapObjectId(_iX, _iY) == 0") == 1 )
  {
    __debugbreak();
  }
  CWorldManager::SetSettlerId(_iX, _iY, this->m_nEntityId);
  IMovingEntity::SetDisplacementCosts(this, 0);
  _pSettlerRole = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v11 = _pSettlerRole->InitWalking(_pSettlerRole, this);
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(&v13, v11);
  LOBYTE(v19) = 3;
  std::auto_ptr<CWalking>::operator=(&v13);
  v14 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v14->Init(v14, this);
  CSettler::TakeWaitList(this);
  LOBYTE(v19) = 2;
  std::auto_ptr<CWalking>::~auto_ptr<CWalking>(&v13);
  v19 = -1;
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&_pSettlerRole);
  return this;
}


// address=[0x157eec0]
// Decompiled from CSettler *__thiscall CSettler::CSettler(CSettler *this, WORD type, int id)
 CSettler::CSettler(int type, int id) {
  
  IMovingEntity::IMovingEntity(this, id);
  this->__vftable = (CSettler_vtbl *)&CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&this->m_pBehavior, 0);
  this->m_iDistance = 0;
  this->m_uObjType = 0;
  this->m_nType = type;
  IEntity::ClearFlagBits(this, ENTITY_FLAG_VulnerableMask|ENTITY_FLAG_Selectable|ENTITY_FLAG_Visible|0x800);
  this->m_iFlags = this->m_iFlags;
  this->m_iDisplacementCosts = 5;
  return this;
}


// address=[0x157ef70]
// Decompiled from CSettler *__thiscall CSettler::CSettler(CSettler *this, int arg0, int a3, int a4, auto_ptr_ISettlerRole a2, int a6)
 CSettler::CSettler(int arg0, int a3, int a4, class std::auto_ptr<class ISettlerRole> a5, int a6) {
  
  CPlayerInfo *v6; // eax
  unsigned __int8 v7; // al
  struct ISettlerRole *v8; // eax
  unsigned int v9; // eax
  int v10; // eax

  IMovingEntity::IMovingEntity(this, a6);
  this->__vftable = (CSettler_vtbl *)&CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&this->m_pBehavior, &a2);
  this->m_iDistance = 0;
  IEntity::SetPosition(this, arg0, a3);
  CWorldManager::SetSettlerId(arg0, a3, a6);
  this->m_uObjType = Settler;
  this->m_nType = 69;
  IEntity::SetOwnerId(this, a4);
  v6 = CPlayerManager::PlayerInfo(a4);
  v7 = CPlayerInfo::Race(v6);
  IEntity::SetRace(this, v7);
  IEntity::ClearFlagBits(this, (EntityFlag)141568);
  IEntity::SetFlagBits(this, (EntityFlag)((char *)&loc_200FFFD + 3));
  this->m_iFlags |= 0xDu;
  this->m_iDisplacementCosts = 10;
  CWarMap::AddEntity(this);
  v8 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v8->Init(v8, this);
  v9 = IEntity::Race(this);
  v10 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v9, 1u);
  CSettler::NewToDoList(v10, 1);
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
  return this;
}


// address=[0x157f0e0]
// Decompiled from int __thiscall CSettler::~CSettler(CSettler *this)
 CSettler::~CSettler(void) {
  
  this->__vftable = (CSettler_vtbl *)&CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&this->m_pBehavior);
  return IMovingEntity::~IMovingEntity(this);
}


// address=[0x157f110]
// Decompiled from unsigned int __thiscall CSettler::Walk(CSettler *this)
int  CSettler::Walk(void) {
  
  int v2; // eax
  int v3; // eax
  CWalking *v4; // [esp+0h] [ebp-8h]

  if ( IEntity::FlagBits(this, ENTITY_FLAG_Died) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
    return -1;
  }
  else if ( std::auto_ptr<CWalking>::get(&this->m_pWalking) )
  {
    v4 = std::auto_ptr<CWalking>::operator->(&this->m_pWalking);
    v2 = IEntity::PackedXY(this);
    v3 = v4->Walk(v4, v2);
    return CSettler::WalkDir(this, v3);
  }
  else
  {
    return 72;
  }
}


// address=[0x157f190]
// Decompiled from unsigned int __thiscall CSettler::WalkDir(CSettler *this, int a2)
int  CSettler::WalkDir(int a2) {
  
  int v3; // esi
  int v4; // eax
  CWalking *v5; // eax
  int v6; // eax
  CWalking *v7; // eax
  int v8; // [esp-4h] [ebp-60h]
  int v9; // [esp-4h] [ebp-60h]
  int v10; // [esp+8h] [ebp-54h]
  __int16 v11; // [esp+Ch] [ebp-50h]
  int TickCounter; // [esp+10h] [ebp-4Ch]
  int v13; // [esp+14h] [ebp-48h]
  int v14; // [esp+18h] [ebp-44h]
  int v15; // [esp+1Ch] [ebp-40h]
  int v16; // [esp+20h] [ebp-3Ch]
  int v17; // [esp+24h] [ebp-38h]
  int v18; // [esp+30h] [ebp-2Ch]
  int v19; // [esp+38h] [ebp-24h]
  int iWorldId; // [esp+3Ch] [ebp-20h]
  int iEntityId; // [esp+40h] [ebp-1Ch]
  int v22; // [esp+44h] [ebp-18h]
  int v23; // [esp+48h] [ebp-14h]
  unsigned int v24; // [esp+4Ch] [ebp-10h]
  int v25; // [esp+50h] [ebp-Ch]

  if ( IEntity::FlagBits(this, ENTITY_FLAG_Died) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
    return -1;
  }
  else
  {
    v24 = a2 & 0xF;
    if ( v24 < 6 )
    {
      v22 = IEntity::PackedXY(this);
      v23 = CWorldManager::Index(v22);
      v3 = IEntity::PackedXY(this);
      v18 = Y16X16::NeighborModifier(v24) + v3;
      v19 = CWorldManager::Index(v18);
      TickCounter = CGameData::GetTickCounter(g_pGameData);
      iEntityId = IEntity::ID(this);
      v13 = IEntity::X(this);
      v14 = IEntity::Y(this);
      IEntity::WorldIdx(this);
      v15 = IEntity::OwnerId(this);
      v16 = IEntity::Race(this);
      iWorldId = CWorldManager::MapObjectId(v23);
      if ( iEntityId != iWorldId )
      {
        BBSupportTracePrintF(
          3,
          "CSettler::WalkDir(): Invalid world map object id: Tick %i, settler %i @ (%i, %i), world id %i, owner %i, race %i",
          TickCounter,
          iEntityId,
          v13,
          v14,
          iWorldId,
          v15,
          v16);
        CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, iEntityId, 0, 0);
        CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, iWorldId, 0, 0);
        if ( BBSupportDbgReport(
               1,
               "MapObjects\\Settler\\Settler.cpp",
               1254,
               "Invalid world map object id! Dietmar: I need the trace file.") == 1 )
          __debugbreak();
      }
      v25 = -1;
      if ( IMovingEntity::IsFree(this, v19) )
      {
        v25 = a2 & 0xF;
      }
      else
      {
        v4 = Grid::TurnLeft(v24);
        v8 = v23 + CWorldManager::NeighborRelIndex(v4);
        v5 = IMovingEntity::Walking(this);
        if ( CWalking::IsFree(v5, v8) )
        {
          v25 = -1;
        }
        else
        {
          v6 = Grid::TurnRight(v24);
          v9 = v23 + CWorldManager::NeighborRelIndex(v6);
          v7 = IMovingEntity::Walking(this);
          if ( CWalking::IsFree(v7, v9) )
            v25 = -1;
        }
      }
      if ( v25 < 0 )
      {
        return a2 | 0x88;
      }
      else
      {
        v11 = IEntity::EntityId(this);
        v17 = v23 + CWorldManager::NeighborRelIndex(v25);
        CWorldManager::SetSettlerId(v23, 0);
        CWorldManager::SetSettlerId(v17, v11);
        v10 = v22 + Y16X16::NeighborModifier(v25);
        IMovingEntity::SetPositionAndDir(this, v10, v25);
        CWarMap::NotifyMove(this, v22);
        this->m_iDistance = -1;
        if ( IEntity::Type(this) == 1 && (a2 & 0x10) == 0 )
          CWorldManager::IncreaseWalkCount(v17);
        return v25 | a2 & 0xFFFFFFF0;
      }
    }
    else
    {
      return a2;
    }
  }
}


// address=[0x157f570]
// Decompiled from void __thiscall CSettler::Decrease(IEntity *this, int a2)
void  CSettler::Decrease(int a2) {
  
  int v2; // eax
  struct ISettlerRole *v4; // [esp+4h] [ebp-4h]

  v4 = std::auto_ptr<ISettlerRole>::operator->(&this[2].m_warMapNode.m_uNextPrev);
  v2 = v4->Decrease(v4, a2);
  IEntity::Decrease(this, v2);
}


// address=[0x157ffe0]
// Decompiled from void __thiscall CSettler::ConvertEventIntoGoal(CSettler *this, struct CEntityEvent *a2)
void  CSettler::ConvertEventIntoGoal(class CEntityEvent * a2) {
  
  struct ISettlerRole *v2; // eax

  v2 = std::auto_ptr<ISettlerRole>::operator->(&this->m_pBehavior);
  v2->ConvertEventIntoGoal(v2, this, a2);
}


#endif // Already implemented
