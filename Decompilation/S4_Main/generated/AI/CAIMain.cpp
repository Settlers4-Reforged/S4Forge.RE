#include "CAIMain.h"

// Definitions for class CAIMain

// address=[0x1311f30]
// Decompiled from int __thiscall CAIMain::InitScripting(CAIMain *this)
void  CAIMain::InitScripting(void) {
  
  return (**(int (__thiscall ***)(void *, CAIMain *))off_3D7A560)(off_3D7A560, this);
}


// address=[0x1311f50]
// Decompiled from void __thiscall CAIMain::Init(CAIMain *this)
void  CAIMain::Init(void) {
  
  (*(void (__thiscall **)(CAIMain *))(*(_DWORD *)this + 20))(this);
  memset((char *)this + 12, 0, 0x24u);
  CAIPlayerEvaluations::Clear((CAIPlayerEvaluations *)&g_cAIPlayerEvaluations);
  CAIRegions::ClearAllRegions((CAIRegions *)&g_cAIRegions);
  CAIPlayersScriptVars::Init((CAIPlayersScriptVars *)g_cAIPlayersScriptVars);
  IAIEnvironment::Init();
  CAIResourceMap::Init();
  CAITaskForces::Init();
  CAIAgentEvaluation::Init((CAIMain *)((char *)this + 92));
  *((_BYTE *)this + 4) = 1;
  IAIEnvironment::DbgEnableAITraceEx();
}


// address=[0x1311fc0]
// Decompiled from char __thiscall CAIMain::IsInitialised(CAIMain *this)
bool  CAIMain::IsInitialised(void) {
  
  return *((_BYTE *)this + 4);
}


// address=[0x1311fe0]
// Decompiled from int __thiscall CAIMain::Done(CAIMain *this)
void  CAIMain::Done(void) {
  
  int result; // eax

  if ( *((_BYTE *)this + 4) )
  {
    (*(void (__thiscall **)(CAIMain *))(*(_DWORD *)this + 36))(this);
    CAITaskForces::Done();
    CAIResourceMap::Done();
    IAIEnvironment::Done();
    *((_BYTE *)this + 4) = 0;
  }
  if ( *((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 186, "m_bInitialized == false") == 1 )
    __debugbreak();
  result = 0;
  if ( !*((_DWORD *)this + 2) )
    return result;
  result = BBSupportDbgReport(2, "AI\\AI_Main.cpp", 187, "m_uActiveAIsMask == 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x1312070]
// Decompiled from int __thiscall CAIMain::Load(CAIMain *this, struct IS4Chunk *a2)
void  CAIMain::Load(class IS4Chunk & a2) {
  
  struct CFrameWnd *v2; // eax
  int v4; // [esp+0h] [ebp-18h]
  int pExceptionObject; // [esp+4h] [ebp-14h] BYREF
  int v6; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  CAIMain *v8; // [esp+10h] [ebp-8h]
  int PlayerId; // [esp+14h] [ebp-4h]

  v8 = this;
  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 654, "m_bInitialized") == 1 )
    __debugbreak();
  (*(void (__thiscall **)(CAIMain *))(*(_DWORD *)v8 + 12))(v8);
  CAIPlayerEvaluations::EvaluateAllPlayers((CAIPlayerEvaluations *)&g_cAIPlayerEvaluations);
  v6 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  v4 = 0;
  if ( v6 != -1517285376 )
  {
    if ( v6 != -1517285374 )
    {
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v4 = (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  }
  if ( v4 )
  {
    v2 = (struct CFrameWnd *)(*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    IAIEnvironment::SetGlobalEcoAIFlags(v2);
  }
  CAIRegions::Load((CAIRegions *)&g_cAIRegions, a2);
  CAIPlayersScriptVars::Load((CAIPlayersScriptVars *)g_cAIPlayersScriptVars, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517285328);
  PlayerId = IAIEnvironment::AlliancesLastPlayerId();
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, PlayerId, PlayerId);
  for ( i = (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, PlayerId + 1);
        i <= PlayerId;
        i = (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, i + 1, PlayerId + 1) )
  {
    CAIMain::CreatePlayerAI(v8, i, a2);
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517285375);
}


// address=[0x13121f0]
// Decompiled from int __thiscall CAIMain::Save(CAIMain *this, struct IS4Chunk *a2)
void  CAIMain::Save(class IS4Chunk & a2) {
  
  int v2; // eax
  int PlayerId; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 716, "m_bInitialized") == 1 )
    __debugbreak();
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517285374);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  v2 = IAIEnvironment::GlobalEcoAIFlags();
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v2);
  CAIRegions::Save((CAIRegions *)&g_cAIRegions, a2);
  CAIPlayersScriptVars::Save((CAIPlayersScriptVars *)g_cAIPlayersScriptVars, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517285328);
  PlayerId = IAIEnvironment::AlliancesLastPlayerId();
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, PlayerId);
  for ( i = 1; i <= PlayerId; ++i )
  {
    if ( *((_DWORD *)this + i + 3) )
    {
      (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, i);
      (*(void (__thiscall **)(int, struct IS4Chunk *))(*(_DWORD *)(*((_DWORD *)this + i + 3) + 4) + 4))(
        *((_DWORD *)this + i + 3) + 4,
        a2);
    }
  }
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, PlayerId + 1);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517285375);
}


// address=[0x1312330]
// Decompiled from CAIMain *__thiscall CAIMain::Execute(CAIMain *this)
void  CAIMain::Execute(void) {
  
  CAIMain *result; // eax
  CAIMain *v2; // [esp+4h] [ebp-10h]
  int v3; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 233, "m_bInitialized") == 1 )
    __debugbreak();
  IAIEnvironment::UpdateTickCounter();
  CAIResourceMap::Update();
  result = this;
  if ( !*((_DWORD *)this + 2) )
    return result;
  v3 = IAIEnvironment::TickCounter();
  CAITaskForces::Execute();
  (*(void (__thiscall **)(char *, int, int))(*((_DWORD *)this + 12) + 4))((char *)this + 48, v3, 511);
  result = (CAIMain *)CPlayerManager::LastPlayerId();
  v2 = result;
  for ( i = 1; i <= (int)v2; ++i )
  {
    if ( *((_DWORD *)this + i + 3) )
    {
      if ( (*((_DWORD *)this + 2) & (1 << i)) == 0
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 255, "(m_uActiveAIsMask & (1 << iPlayerId)) != 0") == 1 )
      {
        __debugbreak();
      }
      (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + i + 3) + 4))(*((_DWORD *)this + i + 3));
    }
    else if ( (*((_DWORD *)this + 2) & (1 << i)) != 0
           && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 261, "(m_uActiveAIsMask & (1 << iPlayerId)) == 0") == 1 )
    {
      __debugbreak();
    }
    result = (CAIMain *)(i + 1);
  }
  return result;
}


// address=[0x1312470]
// Decompiled from void __thiscall CAIMain::ActivatePlayerAI(CAIMain *this, unsigned int a2)
void  CAIMain::ActivatePlayerAI(int a2) {
  
  if ( *((_BYTE *)this + 4) )
  {
    if ( CAIMain::IsRealPlayerId(a2) )
    {
      if ( *((_DWORD *)this + a2 + 3) )
      {
        BBSupportTracePrintF(3, "AI: %s AI for player %i is already active.", "CAIMain::ActivatePlayerAI():", a2);
      }
      else
      {
        BBSupportTracePrintF(3, "AI: %s Activating AI for player %i...", "CAIMain::ActivatePlayerAI():", a2);
        CAIMain::CreatePlayerAI(this, a2, 0);
      }
    }
    else
    {
      BBSupportTracePrintF(3, "AI: %s Invalid player id %i!", "CAIMain::ActivatePlayerAI():", a2);
    }
  }
  else
  {
    BBSupportTracePrintF(3, "AI: %s Not initialized!", "CAIMain::ActivatePlayerAI():");
  }
}


// address=[0x1312520]
// Decompiled from int __thiscall CAIMain::DeactivatePlayerAI(CAIMain *this, unsigned int a2)
void  CAIMain::DeactivatePlayerAI(int a2) {
  
  int result; // eax

  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 303, "m_bInitialized") == 1 )
    __debugbreak();
  if ( !CAIMain::IsRealPlayerId(a2) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 304, "IsRealPlayerId(_iPlayerId)") == 1 )
    __debugbreak();
  if ( *((_BYTE *)this + 4) )
  {
    if ( CAIMain::IsRealPlayerId(a2) )
    {
      if ( *((_DWORD *)this + a2 + 3) )
      {
        BBSupportTracePrintF(3, "AI: %s Deactivating AI for player %i...", "CAIMain::DeactivatePlayerAI():", a2);
        (***((void (__thiscall ****)(_DWORD))this + a2 + 3))(*((_DWORD *)this + a2 + 3));
        *((_DWORD *)this + a2 + 3) = 0;
        *((_DWORD *)this + 2) &= ~(1 << a2);
      }
      else
      {
        BBSupportTracePrintF(3, "AI: %s AI for player %i is not active.", "CAIMain::DeactivatePlayerAI():", a2);
      }
    }
    else
    {
      BBSupportTracePrintF(3, "AI: %s Invalid player id %i!", "CAIMain::DeactivatePlayerAI():", a2);
    }
  }
  else
  {
    BBSupportTracePrintF(3, "AI: %s Not initialized!", "CAIMain::DeactivatePlayerAI():");
  }
  if ( (*((_DWORD *)this + 2) & (1 << a2)) != 0
    && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 329, "(m_uActiveAIsMask & (1 << _iPlayerId)) == 0") == 1 )
  {
    __debugbreak();
  }
  result = a2;
  if ( !*((_DWORD *)this + a2 + 3) )
    return result;
  result = BBSupportDbgReport(2, "AI\\AI_Main.cpp", 330, "m_pPlayerAIs[_iPlayerId] == 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x13126c0]
// Decompiled from int __thiscall CAIMain::DeactivateAllPlayerAIs(CAIMain *this)
void  CAIMain::DeactivateAllPlayerAIs(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 1; i <= 8; ++i )
  {
    (*(void (__thiscall **)(CAIMain *, int))(*(_DWORD *)this + 32))(this, i);
    result = i + 1;
  }
  return result;
}


// address=[0x1312700]
// Decompiled from bool __thiscall CAIMain::IsPlayerAIActive(CAIMain *this, unsigned int a2)
bool  CAIMain::IsPlayerAIActive(int a2) {
  
  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, aAiAiMainC, 353, "m_bInitialized") == 1 )
    __debugbreak();
  return *((_BYTE *)this + 4) && CAIMain::IsRealPlayerId(a2) && *((_DWORD *)this + a2 + 3);
}


// address=[0x1312780]
// Decompiled from void __thiscall CAIMain::PostAIEvent(CAIPlayerAI **this, int a2, int a3, int a4, int a5)
void  CAIMain::PostAIEvent(int a2, int a3, int a4, int a5) {
  
  int v5; // [esp+C8h] [ebp-48h]
  int v6; // [esp+CCh] [ebp-44h]
  int i; // [esp+104h] [ebp-Ch]
  signed int v9; // [esp+10Ch] [ebp-4h]

  IMessageTracer::PushFormatedInts(g_pMsgTracer, "CAIMain::PostAIEvent(): type %i, data %i, %i, %i", a2, a3, a4, a5);
  if ( a2 <= 0 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 369, "_iType > AI_EVENT_NONE") == 1 )
    __debugbreak();
  if ( a2 >= 32 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 370, "_iType < AI_EVENT_MAX") == 1 )
    __debugbreak();
  v9 = 9;
  switch ( a2 )
  {
    case 0:
      if ( BBSupportDbgReport(1, "AI\\AI_Main.cpp", 380, "CAIMain::PostAIEvent(): EventType == AI_EVENT_NONE!") == 1 )
        __debugbreak();
      v9 = 0;
      break;
    case 1:
      v9 = 0;
      break;
    case 2:
      v5 = IAIEnvironment::UnpackXFast(a3);
      v6 = IAIEnvironment::UnpackYFast(a3);
      if ( !IAIEnvironment::WorldInWorld(v5, v6)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 399, "g_pAIEnv->WorldInWorld(iX, iY)") == 1 )
      {
        __debugbreak();
      }
      CAIResourceMap::NotifyResourceChange(v5, v6, a4, a5);
      v9 = 0;
      break;
    case 3:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 414, "(iNewOwnerId >= PLAYER_FIRST) & (iNewOwnerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( (a5 > 8 || a5 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 415, "(iOldOwnerId >= PLAYER_FIRST) & (iOldOwnerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( !CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a4)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 416, "g_cBuildingMgr.GetBuildingPtr(iBuildingId) != 0") == 1 )
      {
        __debugbreak();
      }
      goto LABEL_25;
    case 4:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 432, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( !CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a4)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 433, "g_cBuildingMgr.GetBuildingPtr(iBuildingId) != 0") == 1 )
      {
        __debugbreak();
      }
      goto LABEL_89;
    case 5:
    case 6:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 448, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( !CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a4)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 449, "g_cBuildingMgr.GetBuildingPtr(iBuildingId) != 0") == 1 )
      {
        __debugbreak();
      }
      goto LABEL_89;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 467, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( !CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a4)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 468, "g_cBuildingMgr.GetBuildingPtr(iBuildingId) != 0") == 1 )
      {
        __debugbreak();
      }
      v9 = a3;
      break;
    case 12:
      v9 = 0;
      break;
    case 13:
    case 14:
    case 15:
    case 16:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 491, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      v9 = a3;
      break;
    case 17:
    case 18:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 504, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 505, "iSettlerId > 0") == 1 )
        __debugbreak();
      goto LABEL_89;
    case 19:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 520, "(iNewOwnerId >= PLAYER_FIRST) & (iNewOwnerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( (a5 > 8 || a5 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 521, "(iOldOwnerId >= PLAYER_FIRST) & (iOldOwnerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 522, "iSettlerId > 0") == 1 )
        __debugbreak();
LABEL_25:
      CAITaskForces::RemoveEntityFromTaskForce(a4);
      v9 = 9;
      break;
    case 20:
    case 21:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 537, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 538, "iSettlerId > 0") == 1 )
        __debugbreak();
      v9 = a3;
      break;
    case 22:
      CAIEvent::UnpackA(a5);
      CAIEvent::UnpackB(a5);
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 552, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 553, "iSettlerId > 0") == 1 )
        __debugbreak();
      goto LABEL_89;
    case 23:
    case 24:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 568, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 569, "iVehicleId > 0") == 1 )
        __debugbreak();
LABEL_89:
      CAITaskForces::RemoveEntityFromTaskForce(a4);
      v9 = a3;
      break;
    case 25:
    case 26:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 584, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 585, "iVehicleId > 0") == 1 )
        __debugbreak();
      v9 = a3;
      break;
    case 27:
    case 28:
      if ( (a3 > 8 || a3 < 1)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 597, "(iPlayerId >= PLAYER_FIRST) & (iPlayerId <= PLAYER_LAST)") == 1 )
      {
        __debugbreak();
      }
      v9 = a3;
      break;
    case 29:
      if ( !IAIEnvironment::WorldInWorld(a3, a4)
        && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 610, "g_pAIEnv->WorldInWorld(iX, iY)") == 1 )
      {
        __debugbreak();
      }
      if ( (unsigned int)a5 >= 2 && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 611, "(iDark == 0) || (iDark == 1)") == 1 )
        __debugbreak();
      CAIResourceMap::NotifyDarkLandChange(a3, a4, a5 != 0);
      v9 = 9;
      break;
    default:
      if ( BBSupportDbgReportF(
             1,
             "AI\\AI_Main.cpp",
             622,
             "CAIMain::PostAIEvent(): Invalid / unsupported event type %i!",
             a2) == 1 )
        __debugbreak();
      break;
  }
  if ( v9 == 9 )
  {
    for ( i = 1; i <= CPlayerManager::LastPlayerId(); ++i )
    {
      if ( this[i + 3] )
        CAIPlayerAI::PostAIEvent(this[i + 3], a2, a3, a4, a5);
    }
  }
  else
  {
    if ( v9
      && (v9 > 8 || v9 < 1)
      && BBSupportDbgReport(
           2,
           "AI\\AI_Main.cpp",
           638,
           "(iPostEventPlayerId == PLAYER_NO_PLAYER) || ((iPostEventPlayerId >= PLAYER_FIRST) & (iPostEventPlayerId <= PLAYER_LAST))") == 1 )
    {
      __debugbreak();
    }
    if ( CAIMain::IsRealPlayerId(v9) && this[v9 + 3] )
      CAIPlayerAI::PostAIEvent(this[v9 + 3], a2, a3, a4, a5);
  }
}


// address=[0x1313410]
// Decompiled from void __thiscall CAIMain::DarkTribeIncreaseManaForNewManaSphere(CAIMain *this, int a2)
void  CAIMain::DarkTribeIncreaseManaForNewManaSphere(int a2) {
  
  int Value; // [esp+4h] [ebp-4h]

  if ( !IAIEnvironment::AlliancesIsValidUsedPlayerId(a2)
    && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 761, "g_pAIEnv->AlliancesIsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( IAIEnvironment::PlayerRace(a2) != 3
    && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 762, "g_pAIEnv->PlayerRace(_iPlayerId) == RACE_DARK") == 1 )
  {
    __debugbreak();
  }
  Value = CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, a2, 11);
  IAIEnvironment::MagicIncreaseMana(a2, Value);
}


// address=[0x13134b0]
// Decompiled from void *__thiscall CAIMain::DarkTribeGetProductionCostConfigVar(CAIMain *this, int a2)
class CStaticConfigVarInt const *  CAIMain::DarkTribeGetProductionCostConfigVar(int a2)const {
  
  void *result; // eax

  switch ( a2 )
  {
    case 29:
      result = &g_cAIDarkTribeCostSwordsman;
      break;
    case 32:
      result = &g_cAIDarkTribeCostBowman;
      break;
    case 52:
      result = &g_cAIDarkTribeCostDarkGardener;
      break;
    case 53:
      result = &g_cAIDarkTribeCostMushroomFarmer;
      break;
    case 54:
      result = &g_cAIDarkTribeCostShaman;
      break;
    default:
      if ( BBSupportDbgReportF(
             1,
             "AI\\AI_Main.cpp",
             805,
             "CAIMain::DarkTribeGetProductionCostConfigVar(): Invalid settler type %i!",
             a2) == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


// address=[0x1313570]
// Decompiled from char __thiscall CAIMain::DbgPrint(CAIMain *this, unsigned int a2)
void  CAIMain::DbgPrint(int a2) {
  
  int PlayerId; // eax
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 819, "m_bInitialized") == 1 )
    __debugbreak();
  if ( a2 )
  {
    LOBYTE(PlayerId) = CAIMain::IsRealPlayerId(a2);
    if ( (_BYTE)PlayerId )
    {
      LOBYTE(PlayerId) = (_BYTE)this;
      if ( *((_DWORD *)this + a2 + 3) )
        LOBYTE(PlayerId) = CAIPlayerAI::DbgPrint(*((CAIPlayerAI **)this + a2 + 3));
    }
  }
  else
  {
    PlayerId = CPlayerManager::LastPlayerId();
    v4 = PlayerId;
    for ( i = 1; i <= v4; ++i )
    {
      if ( *((_DWORD *)this + i + 3) )
        CAIPlayerAI::DbgPrint(*((CAIPlayerAI **)this + i + 3));
      LOBYTE(PlayerId) = i + 1;
    }
  }
  return PlayerId;
}


// address=[0x1313630]
// Decompiled from CAIMain *__thiscall CAIMain::CAIMain(CAIMain *this)
 CAIMain::CAIMain(void) {
  
  IAIMain::IAIMain(this);
  *(_DWORD *)this = CAIMain::_vftable_;
  CAIScheduler::CAIScheduler((CAIMain *)((char *)this + 48));
  CAIAgentEvaluation::CAIAgentEvaluation(
    (CAIMain *)((char *)this + 92),
    (struct CAIPlayerEvaluations *)&g_cAIPlayerEvaluations);
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 2) = 0;
  CAIScheduler::AddAgent((CAIMain *)((char *)this + 48), (CAIMain *)((char *)this + 92), 0xFu, 0x100u, 8u);
  return this;
}


// address=[0x13136e0]
// Decompiled from int __thiscall CAIMain::PrepareAI(CAIMain *this)
void  CAIMain::PrepareAI(void) {
  
  return CAIPlayerEvaluations::EvaluateAllPlayers((CAIPlayerEvaluations *)&g_cAIPlayerEvaluations);
}


// address=[0x1313700]
// Decompiled from int __thiscall CAIMain::CreatePlayerAI(CAIMain *this, unsigned int a2, struct IS4Chunk *a3)
void  CAIMain::CreatePlayerAI(int a2, class IS4Chunk * a3) {
  
  int result; // eax

  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 207, "m_bInitialized") == 1 )
    __debugbreak();
  if ( !CAIMain::IsRealPlayerId(a2) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 208, "IsRealPlayerId(_iPlayerId)") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + a2 + 3) && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 209, "m_pPlayerAIs[_iPlayerId] == 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 2) )
    CAIMain::PrepareAI(this);
  *((_DWORD *)this + a2 + 3) = CAIPlayerAI::CreatePlayerAI(a2, a3);
  *((_DWORD *)this + 2) |= 1 << a2;
  if ( (*((_DWORD *)this + 2) & (1 << a2)) == 0
    && BBSupportDbgReport(2, "AI\\AI_Main.cpp", 222, "(m_uActiveAIsMask & (1 << _iPlayerId)) != 0") == 1 )
  {
    __debugbreak();
  }
  result = a2;
  if ( *((_DWORD *)this + a2 + 3) )
    return result;
  result = BBSupportDbgReport(2, "AI\\AI_Main.cpp", 223, "m_pPlayerAIs[_iPlayerId] != 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x1313f50]
// Decompiled from void __thiscall CAIMain::~CAIMain(CAIMain *this)
 CAIMain::~CAIMain(void) {
  
  CAIAgentEvaluation::~CAIAgentEvaluation((CAIMain *)((char *)this + 92));
  CAIScheduler::~CAIScheduler((CAIMain *)((char *)this + 48));
}


// address=[0x1314050]
// Decompiled from bool __cdecl CAIMain::IsRealPlayerId(unsigned int a1)
bool __cdecl CAIMain::IsRealPlayerId(unsigned int) {
  
  return a1 - 1 <= 7;
}


