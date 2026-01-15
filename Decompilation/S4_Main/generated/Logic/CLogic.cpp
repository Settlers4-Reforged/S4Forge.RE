#include "CLogic.h"

// Definitions for class CLogic

// address=[0x141d890]
// Decompiled from int __thiscall CLogic::Effects(DWORD *this)
class IEffects &  CLogic::Effects(void) {
  
  return this[12];
}


// address=[0x14609a0]
// Decompiled from struct CInfoExchange *__thiscall CLogic::SetFillDialogInfos(  CLogic *this,  void (__cdecl *a2)(struct CInfoExchange *, bool, bool),  struct CInfoExchange *a3,  bool a4)
void  CLogic::SetFillDialogInfos(void (__cdecl*)(class CInfoExchange *,bool,bool),class CInfoExchange *,bool) {
  
  struct CInfoExchange *result; // eax

  *((_DWORD *)this + 4) = a2;
  result = a3;
  *((_DWORD *)this + 5) = a3;
  *((_BYTE *)this + 24) = a4;
  return result;
}


// address=[0x14609e0]
// Decompiled from struct CInfoExchange *__thiscall CLogic::SetFillSideBarInfos(  CLogic *this,  void (__cdecl *a2)(struct CInfoExchange *, bool, int),  struct CInfoExchange *a3,  int a4)
void  CLogic::SetFillSideBarInfos(void (__cdecl*)(class CInfoExchange *,bool,int),class CInfoExchange *,int) {
  
  struct CInfoExchange *result; // eax

  *((_DWORD *)this + 7) = a2;
  result = a3;
  *((_DWORD *)this + 8) = a3;
  *((_DWORD *)this + 9) = a4;
  return result;
}


// address=[0x1460a50]
// Decompiled from CLogic *__thiscall CLogic::SetLocalGlobalSwitch(CLogic *this, bool a2)
void  CLogic::SetLocalGlobalSwitch(bool) {
  
  CLogic *result; // eax

  result = this;
  *((_BYTE *)this + 24) = a2;
  return result;
}


// address=[0x1460a70]
// Decompiled from CLogic *__thiscall CLogic::SwitchExtraInfoMenu(CLogic *this, bool a2)
void  CLogic::SwitchExtraInfoMenu(bool) {
  
  CLogic *result; // eax

  result = this;
  *((_BYTE *)this + 40) = a2;
  return result;
}


// address=[0x1469c90]
// Decompiled from CLogic *__thiscall CLogic::CLogic(CLogic *this)
 CLogic::CLogic(void) {
  
  CBBObject::CBBObject(this, (int)"CLogic", 1);
  *(_DWORD *)this = &CLogic::_vftable_;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_BYTE *)this + 40) = 0;
  *((_DWORD *)this + 11) = IFutureEvents::CreateFutureEvents();
  *((_DWORD *)this + 12) = IEffects::CreateEffects();
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 15) = 0;
  CPerformanceCounter::Start((CPerformanceCounter *)&cTimer);
  lastTime = 0LL;
  return this;
}


// address=[0x1469d90]
// Decompiled from void __thiscall CLogic::~CLogic(CLogic *this)
 CLogic::~CLogic(void) {
  
  *(_DWORD *)this = &CLogic::_vftable_;
  CAnimalMgr::Clear((CAnimalMgr *)&g_cAnimalMgr);
  CDecoObjMgr::Clear((CDecoObjMgr *)&g_cDecoObjMgr);
  CPileMgr::Clear((CPileMgr *)&g_cPileMgr);
  CBuildingMgr::Clear((CBuildingMgr *)g_cBuildingMgr);
  CSettlerMgr::Clear((CSettlerMgr *)g_cSettlerMgr);
  CVehicleMgr::Clear((CVehicleMgr *)&g_cVehicleMgr);
  CEcoSectorMgr::Clear((CEcoSectorMgr *)g_cESMgr);
  CStatistic::Clear((CStatistic *)&g_cStatistic);
  CFlyingMgr::Clear((CFlyingMgr *)g_cFlyingMgr);
  if ( *((_DWORD *)this + 11) )
  {
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 11) + 8))(*((_DWORD *)this + 11));
    *((_DWORD *)this + 11) = 0;
  }
  if ( *((_DWORD *)this + 12) )
  {
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 12))(*((_DWORD *)this + 12));
    *((_DWORD *)this + 12) = 0;
  }
  CBBObject::~CBBObject(this);
}


// address=[0x1469e80]
// Decompiled from BOOL __thiscall CLogic::PostLoadMap(CLogic *this, struct CGameType *a2)
void  CLogic::PostLoadMap(class CGameType &) {
  
  BOOL result; // eax
  int v3; // [esp+8h] [ebp-Ch]
  int v4; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  result = CGameType::IsEmptyMap(a2);
  if ( result )
  {
    for ( i = 0; ; ++i )
    {
      result = i;
      if ( i >= *((_DWORD *)a2 + 28) )
        break;
      v4 = *((_DWORD *)a2 + i + 29);
      if ( v4 )
      {
        if ( v4 == 1 )
          v3 = 0;
        else
          v3 = v4 - 1;
        CGameScriptManager::CreateStartResources(
          (void ***)g_pScriptMgr,
          *((_DWORD *)a2 + 16),
          *((_DWORD *)a2 + i + 65),
          *((_DWORD *)a2 + i + 74),
          i + 1,
          v3);
      }
    }
  }
  return result;
}


// address=[0x1469f30]
// Decompiled from void __thiscall CLogic::LogicUpdate(CLogic *this)
void  CLogic::LogicUpdate(void) {
  
  int LocalPlayerId; // eax
  int v2; // eax
  int v3; // [esp+8h] [ebp-8h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(15, 14);
  if ( !CPlayerManager::IsAlive(LocalPlayerId) )
  {
    v2 = CInputProcessor::Selection();
    if ( std::vector<unsigned short>::size(v2) )
      CInputProcessor::DeSelectAllEx((CInputProcessor *)&g_cInputProcessor);
  }
  CInputProcessor::Process((CInputProcessor *)&g_cInputProcessor);
  CMapObjectMgr::LogicUpdate(g_pMapObjectMgr);
  v3 = CStateGame::GetTickCounter(g_pGame) & 0xF;
  if ( v3 == 14 )
  {
    if ( *((_DWORD *)this + 4) )
      (*((void (__cdecl **)(_DWORD, int, _DWORD))this + 4))(*((_DWORD *)this + 5), 1, *((unsigned __int8 *)this + 24));
    if ( *((_DWORD *)this + 7) )
      (*((void (__cdecl **)(_DWORD, int, _DWORD))this + 7))(*((_DWORD *)this + 8), 1, *((_DWORD *)this + 9));
    if ( *((_BYTE *)this + 40) == 1 )
      CStatistic::FillExtraInfo((CStatistic *)&g_cStatistic);
  }
  if ( v3 == 15 )
  {
    CEcoSectorMgr::InitTransport((CEcoSectorMgr *)g_cESMgr);
    CEcoSectorMgr::RecruiteSpecialist((CEcoSectorMgr *)g_cESMgr);
    CEcoSectorMgr::RecruiteWorker((CEcoSectorMgr *)g_cESMgr);
  }
  if ( !(CStateGame::GetTickCounter(g_pGame) % 0x348u) || CStateGame::GetTickCounter(g_pGame) == 1 )
    CStatisticArchive::TriggerStatistic((CStatisticArchive *)&g_cStatisticArchive);
  CLogic::ChangeWorldPosition(this);
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 11) + 16))(*((_DWORD *)this + 11));
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 96))(*((_DWORD *)this + 12));
  CLogic::HandleCursor(this);
  if ( !CGameSettings::GetUserMP3() )
    CLogic::HandleSoundtracks(this);
}


// address=[0x1470980]
// Decompiled from int __thiscall CLogic::FutureEvents(_DWORD *this)
class IFutureEvents &  CLogic::FutureEvents(void) {
  
  return this[11];
}


// address=[0x158b9a0]
// Decompiled from CLogic *__thiscall CLogic::SetWarAction(CLogic *this)
void  CLogic::SetWarAction(void) {
  
  CLogic *result; // eax

  result = this;
  *((_DWORD *)this + 16) = 1;
  return result;
}


// address=[0x146a0b0]
// Decompiled from int __thiscall CLogic::ChangeWorldPosition(CLogic *this)
void  CLogic::ChangeWorldPosition(void) {
  
  unsigned __int8 v1; // al
  int v2; // ecx
  int v3; // edx
  int v4; // ecx
  int result; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp+0h] [ebp-30h]
  const char *v9; // [esp+Ch] [ebp-24h]
  int v10; // [esp+10h] [ebp-20h]
  int v11; // [esp+14h] [ebp-1Ch]
  int v12; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  int v14; // [esp+20h] [ebp-10h]
  int v15; // [esp+24h] [ebp-Ch]
  int v16; // [esp+28h] [ebp-8h]

  v1 = CWorldManager::InWorld(*((_DWORD *)this + 13), *((_DWORD *)this + 14));
  v2 = v1;
  if ( !v1 && BBSupportDbgReport(2, "Logic\\Logic.cpp", 507, "g_cWorld.InWorld(m_iTimeX, m_iTimeY)") == 1 )
    __debugbreak();
  v8 = 13;
  v15 = CWorldManager::Width(v2);
  if ( v15 != CWorldManager::Height(v4, v3)
    && BBSupportDbgReport(2, "Logic\\Logic.cpp", 513, "iWidthHeight == g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v15 * v15 / 2000 )
      break;
    *((_DWORD *)this + 13) += 13;
    if ( *((_DWORD *)this + 13) >= v15 )
    {
      *((_DWORD *)this + 13) -= v15;
      if ( ++*((_DWORD *)this + 14) >= v15 )
        *((_DWORD *)this + 14) -= v15;
    }
    if ( !(unsigned __int8)CWorldManager::InWorld(*((_DWORD *)this + 13), *((_DWORD *)this + 14))
      && BBSupportDbgReport(2, "Logic\\Logic.cpp", 533, "g_cWorld.InWorld(m_iTimeX, m_iTimeY)") == 1 )
    {
      __debugbreak();
    }
    v16 = CWorldManager::Index(*((_DWORD *)this + 13), *((_DWORD *)this + 14));
    CWorldManager::DecreaseWalkCount(v16);
    if ( !CWorldManager::ResourceType(v16) && CWorldManager::ResourceAmount(v16, 0) > 0 )
    {
      v12 = sub_146A900(v8);
      v10 = sub_146A880(*((_DWORD *)this + 13), v12);
      v11 = sub_146A8C0(*((_DWORD *)this + 14), v12);
      v14 = CWorldManager::Index(v10, v11);
      if ( (unsigned __int8)CWorldManager::InWorld(v10, v11) )
      {
        if ( CWorldManager::IsWater(v14)
          && !CWorldManager::ResourceType(v14)
          && CWorldManager::ResourceAmount(v14, 0) > 0 )
        {
          v6 = CWorldManager::ResourceAmount(v14, 0);
          CWorldManager::SetResource(v14, 0, v6 + 1);
          v7 = CWorldManager::ResourceAmount(v16, 0);
          CWorldManager::SetResource(v16, 0, v7 - 1);
        }
      }
    }
    v9 = CGameData::Rand(g_pGameData);
    if ( (unsigned int)v9 < CRandom16::PercentValue(7u)
      && CDecoObjMgr::IsGeologistSign((CDecoObjMgr *)&g_cDecoObjMgr, v16) )
    {
      CWorldManager::SetObjectId(v16, 0);
    }
    if ( (unsigned int)v9 < CRandom16::PercentValue(0xCu) )
      CDecoObjMgr::Rod((CDecoObjMgr *)&g_cDecoObjMgr, v16, 0);
  }
  return result;
}


// address=[0x146a380]
// Decompiled from int __thiscall CLogic::HandleCursor(void *this)
void  CLogic::HandleCursor(void) {
  
  int result; // eax
  unsigned __int16 *v2; // eax
  int v3; // eax
  int v4; // [esp+8h] [ebp-18h]
  _DWORD *VehiclePtr; // [esp+10h] [ebp-10h]
  char ModifierState; // [esp+14h] [ebp-Ch]
  unsigned __int16 *v7; // [esp+18h] [ebp-8h]
  int v8; // [esp+1Ch] [ebp-4h]
  int v9; // [esp+1Ch] [ebp-4h]

  result = (unsigned __int8)CStateGame::IsCursorChangeAllowed(g_pGame, this);
  if ( !(_BYTE)result )
    return result;
  result = CInputProcessor::IsTryBuildState(&g_cInputProcessor);
  if ( (_BYTE)result )
    return result;
  if ( (unsigned __int8)CInputProcessor::IsWorkingAreaState(&g_cInputProcessor) )
  {
    result = IGfxEngine::GetCursorShape(g_pGfxEngine);
    if ( result != 9 )
      return IGfxEngine::SetCursorShape(1, 9);
  }
  else if ( (unsigned __int8)CInputProcessor::IsChooseSecondPatrolPosState(&g_cInputProcessor) )
  {
    result = IGfxEngine::GetCursorShape(g_pGfxEngine);
    if ( result != 19 )
      return IGfxEngine::SetCursorShape(1, 19);
  }
  else if ( (unsigned __int8)CInputProcessor::IsZoomAreaState(&g_cInputProcessor) )
  {
    result = IGfxEngine::GetCursorShape(g_pGfxEngine);
    if ( result != 34 )
      return IGfxEngine::SetCursorShape(1, 34);
  }
  else
  {
    v4 = CInputProcessor::Selection();
    if ( std::vector<unsigned short>::size(v4) )
    {
      v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](0);
      v7 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(*v2);
      if ( v7 )
      {
        v8 = 0;
        ModifierState = CStateGame::GetModifierState(g_pGame);
        if ( IEntity::ObjType((unsigned __int8 *)v7) != 1 || IEntity::ObjType((unsigned __int8 *)v7) == 60 )
        {
          v3 = IEntity::ID();
          VehiclePtr = (_DWORD *)CVehicleMgr::GetVehiclePtr(v3);
          if ( VehiclePtr )
          {
            result = IEntity::FlagBits(VehiclePtr, (EntityFlag)0x4000u);
            if ( result )
              return result;
            if ( IEntity::WarriorType() == 8 || IEntity::WarriorType() == 10 || IEntity::WarriorType() == 11 )
            {
              if ( (ModifierState & 0x10) != 0 )
                v8 = 10;
              else
                v8 = 17;
            }
            else if ( (ModifierState & 0x10) != 0 )
            {
              v8 = 10;
            }
            else
            {
              v8 = 32;
            }
          }
          result = IGfxEngine::GetCursorShape(g_pGfxEngine);
          if ( result != 6 && result != 7 )
          {
            result = IGfxEngine::GetCursorShape(g_pGfxEngine);
            if ( result != v8 )
              return IGfxEngine::SetCursorShape(1, v8);
          }
        }
        else
        {
          if ( IEntity::Type(v7) == 47 )
          {
            if ( (ModifierState & 0x10) != 0 )
              v9 = 10;
            else
              v9 = 21;
          }
          else if ( IEntity::Type(v7) == 49 )
          {
            if ( (ModifierState & 0x10) != 0 )
              v9 = 10;
            else
              v9 = 13;
          }
          else if ( IEntity::Type(v7) == 48 )
          {
            if ( (ModifierState & 0x10) != 0 )
              v9 = 10;
            else
              v9 = 27;
          }
          else if ( IEntity::Type(v7) == 45 )
          {
            if ( (ModifierState & 0x10) != 0 )
              v9 = 10;
            else
              v9 = 15;
          }
          else if ( IEntity::Type(v7) == 46 )
          {
            if ( (ModifierState & 0x10) != 0 )
              v9 = 10;
            else
              v9 = 24;
          }
          else if ( IEntity::Type(v7) == 50 )
          {
            if ( (ModifierState & 0x10) != 0 )
              v9 = 10;
            else
              v9 = 11;
          }
          else if ( IEntity::Type(v7) == 60 || IEntity::Type(v7) == 1 )
          {
            v9 = 0;
          }
          else if ( (ModifierState & 0x10) != 0 )
          {
            v9 = 10;
          }
          else if ( (ModifierState & 4) != 0 )
          {
            v9 = 7;
          }
          else if ( (ModifierState & 8) != 0 )
          {
            v9 = 19;
          }
          else
          {
            v9 = 17;
          }
          result = IGfxEngine::GetCursorShape(g_pGfxEngine);
          if ( result != v9 )
            return IGfxEngine::SetCursorShape(1, v9);
        }
      }
      else
      {
        result = IGfxEngine::GetCursorShape(g_pGfxEngine);
        if ( result )
          return IGfxEngine::SetCursorShape(1, 0);
      }
    }
    else
    {
      result = IGfxEngine::GetCursorShape(g_pGfxEngine);
      if ( result != 6 && result != 7 )
      {
        result = IGfxEngine::GetCursorShape(g_pGfxEngine);
        if ( result )
          return IGfxEngine::SetCursorShape(1, 0);
      }
    }
  }
  return result;
}


// address=[0x146a770]
// Decompiled from int __thiscall CLogic::HandleSoundtracks(CLogic *this)
void  CLogic::HandleSoundtracks(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-Ch] BYREF
  int v3; // [esp+4h] [ebp-8h] BYREF
  CLogic *v4; // [esp+8h] [ebp-4h]

  v4 = this;
  if ( *((_DWORD *)this + 16) )
  {
    result = (int)v4;
    if ( (int)++*((_DWORD *)v4 + 16) <= 32 )
    {
      if ( *((_DWORD *)v4 + 17) != 1 )
      {
        result = CSoundManager::ChangeMusicStyle(g_pSoundManager, 1);
        *((_DWORD *)v4 + 17) = 1;
      }
    }
    else
    {
      CSoundManager::ChangeMusicStyle(g_pSoundManager, 0);
      *((_DWORD *)v4 + 17) = 0;
      result = (int)v4;
      *((_DWORD *)v4 + 16) = 0;
    }
  }
  else
  {
    CStateGame::GetCenterWorldCoordinate((CStateGame *)g_pGame, &v2, &v3);
    result = CWorldManager::InWorld(v2, v3);
    if ( (_BYTE)result )
    {
      result = CWorldManager::FlagBits(v2, v3, 4u);
      if ( result )
      {
        if ( *((_DWORD *)v4 + 17) != 3 )
        {
          *((_DWORD *)v4 + 17) = 3;
          return CSoundManager::ChangeMusicStyle(g_pSoundManager, 3);
        }
      }
      else
      {
        result = (int)v4;
        if ( *((_DWORD *)v4 + 17) )
        {
          *((_DWORD *)v4 + 17) = 0;
          return CSoundManager::ChangeMusicStyle(g_pSoundManager, 0);
        }
      }
    }
  }
  return result;
}


