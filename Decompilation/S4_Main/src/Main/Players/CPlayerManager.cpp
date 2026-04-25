#include "CPlayerManager.h"

#include "CBB/CBBSupport.h"
#include "Debug/CTrace.h"
#include "Defines/Players.h"
#include "Info/CPlayerInfo.h"
#include "Logic/CPlayerGameData.h"

// Definitions for class CPlayerManager

// address=[0x130f2c0]
// Decompiled from DWORD __cdecl CPlayerManager::Race(int _iPlayerId)
int __cdecl CPlayerManager::Race(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerInfos[_iPlayerId].m_iRace;
}


// address=[0x130f490]
// Decompiled from bool __cdecl CPlayerManager::ValidUsedPlayerId(int a1)
bool __cdecl CPlayerManager::ValidUsedPlayerId(int a1) {
  return a1 - 1 < CPlayerManager::m_iNumberOfPlayer;
}


// address=[0x1314080]
// Decompiled from int CPlayerManager::LastPlayerId()
int __cdecl CPlayerManager::LastPlayerId(void) {
  return CPlayerManager::m_iNumberOfPlayer;
}


// address=[0x13736c0]
// Decompiled from int CPlayerManager::GetLocalPlayerId()
int __cdecl CPlayerManager::GetLocalPlayerId(void) {
  return CPlayerManager::m_iLocalPlayer;
}


// address=[0x13736d0]
// Decompiled from CPlayerInfo *__cdecl CPlayerManager::PlayerInfo(int a1)
class CPlayerInfo const & __cdecl CPlayerManager::PlayerInfo(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerInfos[_iPlayerId];
}


// address=[0x13919d0]
// Decompiled from DWORD __cdecl CPlayerManager::Color(int a1)
int __cdecl CPlayerManager::Color(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerInfos[_iPlayerId].m_iColor;
}


// address=[0x1391a30]
// Decompiled from int CPlayerManager::NumberOfPlayers()
int __cdecl CPlayerManager::NumberOfPlayers(void) {
  return CPlayerManager::m_iNumberOfPlayer;
}


// address=[0x14477c0]
// Decompiled from CPlayerGameData *__cdecl CPlayerManager::PlayerGameData(int _iPlayerId)
class CPlayerGameData & __cdecl CPlayerManager::PlayerGameData(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerGameData[_iPlayerId];
}


// address=[0x144fed0]
// Decompiled from std::wstring *__cdecl CPlayerManager::Name(std::wstring *a1, int a2)
std::wstring __cdecl CPlayerManager::Name(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerInfos[_iPlayerId].m_swName;
}


// address=[0x1460650]
// Decompiled from char __cdecl CPlayerManager::IsAlive(int a1)
bool __cdecl CPlayerManager::IsAlive(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerInfos[_iPlayerId].m_bAlive;
}


// address=[0x147a320]
// Decompiled from bool __cdecl CPlayerManager::IsAI(int a1)
bool __cdecl CPlayerManager::IsAI(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerInfos[_iPlayerId].m_iType == 2 || CPlayerManager::m_cPlayerInfos[_iPlayerId].m_iType == 3;
}


// address=[0x1486e90]
// Decompiled from DWORD __cdecl CPlayerManager::GetPlayerControl(int a1)
int __cdecl CPlayerManager::GetPlayerControl(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerInfos[_iPlayerId].m_iType;
}


// address=[0x14973a0]
// Decompiled from void __cdecl CPlayerManager::Init()
void __cdecl CPlayerManager::Init(void) {
  // [esp+0h] [ebp-4h]

  CPlayerManager::Done();
  CPlayerManager::m_lLocalIP = 0;
  CPlayerManager::m_iNumberOfPlayer = 0;
  CPlayerManager::m_iLocalPlayer = 0;
  for(int i = 0; i < 9; ++i) {
    CPlayerManager::m_cPlayerInfos[i].Clear();
    CPlayerManager::m_cPlayerGameData[i].Clear();
  }
  CPlayerManager::m_iInitialized = 1;
  CPlayerManager::m_iLocked = 0;
}


// address=[0x1497420]
// Decompiled from int __cdecl CPlayerManager::AddPlayer(  DWORD _iPlayerRace,  DWORD _iPlayerX,  DWORD _iPlayerY,  DWORD _iPlayerColor,  DWORD _iPlayerIP,  DWORD _iPeerId,  std::wstring _swPlayerName,  DWORD _iType)
int __cdecl CPlayerManager::AddPlayer(int _iPlayerRace, int _iPlayerX, int _iPlayerY, int _iPlayerColor, int _iPlayerIP, int _iPeerId, std::wstring _swPlayerName, int _iType) {
  //OnlineManager *Instance; // eax
  wchar_t *v10; // eax
  // [esp+18h] [ebp-11Ch]
  // [esp+1Ch] [ebp-118h]
  // [esp+20h] [ebp-114h]
  char _spPlayerName[256]; // [esp+24h] [ebp-110h] BYREF
  // [esp+130h] [ebp-4h]

  int v15 = 0;
  if(!CPlayerManager::m_iInitialized) {
    BB_REPORT("AddPlayer(): Not initialized!")
    return 0;
  }
  if(CPlayerManager::m_iLocked) {
    BB_REPORT("AddPlayer(): Already locked!")
    return 0;
  }
  if(CPlayerManager::LastPlayerId() >= MAX_PLAYER) {
    BB_REPORT("AddPlayer(): Player limit reached!")
    return 0;
  }
  int          v12 = ++CPlayerManager::m_iNumberOfPlayer;
  CPlayerInfo *v13 = &CPlayerManager::m_cPlayerInfos[CPlayerManager::m_iNumberOfPlayer];
  v13->m_iRace = _iPlayerRace;
  v13->m_iStartX = _iPlayerX;
  v13->m_iStartY = _iPlayerY;
  v13->m_iColor = _iPlayerColor;
  v13->m_iIp = _iPlayerIP;
  v13->m_iPeerId = _iPeerId;
  v13->m_swName = _swPlayerName;
  v13->m_iType = _iType;
  v13->m_bAlive = 1;

  if(OnlineManager::GetInstance()->IsLocalPeerId(_iPeerId)) {
    CPlayerManager::m_iLocalPlayer = v12;
    CTrace::Print("Created local Player with id#%d", v12);
  }
  size_t v11 = wcstombs(_spPlayerName, _swPlayerName.c_str(), 0x100u);
  if(v11 >= 0x100)
    throw;
  _spPlayerName[v11] = 0;
  CTrace::Print(
    "PlayerManager.cpp: Adding player %s at %d/%d, with race %d, color %d, IP %d!",
    _spPlayerName,
    _iPlayerX,
    _iPlayerY,
    _iPlayerRace,
    _iPlayerColor,
    _iPlayerIP);

  return v12;
}


// address=[0x14976e0]
// Decompiled from char CPlayerManager::Lock()
bool __cdecl CPlayerManager::Lock(void) {
  if(!CPlayerManager::m_iInitialized) {
    BB_REPORT("Lock(): Not initialized!")
    return 0;
  }

  if(CPlayerManager::m_iLocked) {
    BB_REPORT("Lock(): Already locked!")
    return 0;
  }

  if(!CPlayerManager::m_iLocalPlayer) {
    BB_REPORT("No local Player!")
    return 0;
  }

  CPlayerManager::m_iLocked = 1;
  return 1;
}


// address=[0x1497790]
// Decompiled from void CPlayerManager::Done()
void __cdecl CPlayerManager::Done(void) {
  CPlayerManager::m_iInitialized = 0;
  CPlayerManager::m_iLocked = 0;
}


// address=[0x14977b0]
// Decompiled from void __thiscall CPlayerManager::Load(CPlayerManager *this, struct IS4Chunk *a2)
void CPlayerManager::Load(class IS4Chunk &a2) {
  // [esp+4h] [ebp-4h]
  // [esp+4h] [ebp-4h]

  CPlayerManager::m_iNumberOfPlayer = a2.LoadUnsigned32(0, 12);
  CPlayerManager::m_iLocalPlayer = a2.LoadUnsigned32();
  for(int i = 1; i <= CPlayerManager::LastPlayerId(); ++i) {
    CPlayerManager::m_cPlayerGameData[i].Load(a2);
    CPlayerManager::m_cPlayerGameData[i].PostLoadInit(i);
  }
  for(int j = 1; j <= CPlayerManager::LastPlayerId(); ++j)
    CPlayerManager::m_cPlayerInfos[j].Load(a2);
}


// address=[0x1497870]
// Decompiled from int __thiscall CPlayerManager::Save(CPlayerManager *this, struct IS4Chunk *a2)
void CPlayerManager::Save(class IS4Chunk &a2) {
  // eax
  // [esp+4h] [ebp-8h]
  // [esp+8h] [ebp-4h]
  // [esp+8h] [ebp-4h]

  int iPlayerId = CPlayerManager::LastPlayerId();
  a2.SaveUnsigned32(iPlayerId);
  a2.SaveUnsigned32(CPlayerManager::m_iLocalPlayer);
  for(int i = 1; i <= CPlayerManager::LastPlayerId(); ++i)
    CPlayerManager::m_cPlayerGameData[i].Save(a2);
  for(int j = 1; ; ++j) {
    if(j > CPlayerManager::LastPlayerId())
      break;
    CPlayerManager::m_cPlayerInfos[j].Save(a2);
  }
}


// address=[0x1497920]
// Decompiled from int CPlayerManager::PrintStats()
void __cdecl CPlayerManager::PrintStats(void) {
  char *      v0; // eax
  const char *v2; // [esp+4h] [ebp-38h]
  // [esp+8h] [ebp-34h]
  // [esp+Ch] [ebp-30h]
  std::string v5; // [esp+10h] [ebp-2Ch] BYREF
  // [esp+38h] [ebp-4h]

  CTrace::Print("----------------------------------------------------------------------------------");
  CTrace::Print("Player Stats:");
  for(int i = 1; i <= CPlayerManager::LastPlayerId(); ++i) {
    DWORD PlayerControl = CPlayerManager::GetPlayerControl(i);
    v5 = "Undefined";

    if(PlayerControl == 2)
      v5 = "AI Level 1";
    if(PlayerControl == 3)
      v5 = "AI Level 2";
    if(PlayerControl == 1)
      v5 = "Human";
    if(CPlayerManager::IsAlive(i))
      v2 = "Yes";
    else
      v2 = "No";

    CTrace::Print("CPlayerManager: Player: %d, Control: %s, Alive: %s.", i, v5.c_str(), v2);
  }
  return CTrace::Print("----------------------------------------------------------------------------------");
}


// address=[0x1497a60]
// Decompiled from char CPlayerManager::GetLocalSlot()
signed char __cdecl CPlayerManager::GetLocalSlot(void) {
  // eax
  // eax
  // [esp+0h] [ebp-4h]

  BB_ASSERT(g_pNetworkEngine != NULL)
  BB_ASSERT(g_pGameType != NULL)

  if(!g_pNetworkEngine || !g_pGameType)
    return -1;
  BB_ASSERT(g_pGameType->m_iMapMaxNumPlayers <= MAX_PLAYER)

  if(g_pGameType->m_iMapMaxNumPlayers > 8)
    return -1;
  for(int i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i) {
    throw;
    // OnlineManager *Instance = (OnlineManager *) OnlineManager::GetInstance();
    // if(OnlineManager::IsInSession(Instance)) {
    //   int v2 = StormManager::GetInstance();
    //   if(StormManager::GetLocalPeerId(v2) == g_pGameType->m_sPlayerPeerId[i])
    //     return i;
    // }
  }
  return 0;
}


// address=[0x1498150]
// Decompiled from CPlayerManager *__thiscall CPlayerManager::CPlayerManager(CPlayerManager *this)
CPlayerManager::CPlayerManager(void) : IS4ChunkObject() {}


// address=[0x14aae50]
// Decompiled from void __cdecl CPlayerManager::PlayerDied(int a1)
void __cdecl CPlayerManager::PlayerDied(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  CPlayerManager::m_cPlayerInfos[_iPlayerId].m_bAlive = 0; // Removed LOBYTE write accessor!
  CPlayerManager::PrintStats();
}


// address=[0x14b4800]
// Decompiled from DWORD __cdecl CPlayerManager::PeerId(int a1)
int __cdecl CPlayerManager::PeerId(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))

  return CPlayerManager::m_cPlayerInfos[_iPlayerId].m_iPeerId;
}


// address=[0x14b4930]
// Decompiled from void __cdecl CPlayerManager::SetLocalPlayerId(int a1)
void __cdecl CPlayerManager::SetLocalPlayerId(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))

  CPlayerManager::m_iLocalPlayer = _iPlayerId;
}


// address=[0x14b4980]
// Decompiled from void __cdecl CPlayerManager::SetPlayerControl(int a1, DWORD arg4)
void __cdecl CPlayerManager::SetPlayerControl(int _iPlayerId, int _iControlType) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))

  CPlayerManager::m_cPlayerInfos[_iPlayerId].m_iType = _iControlType;
  if(_iControlType == 2 || _iControlType == 3) {
    CPlayerManager::m_cPlayerInfos[_iPlayerId].m_swName = L"(AI) " + CPlayerManager::m_cPlayerInfos[_iPlayerId].m_swName;
  }
  CPlayerManager::PrintStats();
}


// address=[0x15c4d00]
// Decompiled from DWORD __cdecl CPlayerManager::IP(int a1)
int __cdecl CPlayerManager::IP(int _iPlayerId) {
  BB_ASSERT(ValidUsedPlayerId(_iPlayerId))
  return CPlayerManager::m_cPlayerInfos[_iPlayerId].m_iIp;
}


// address=[0x402bd70]
// [Decompilation failed for static int CPlayerManager::m_iInitialized]

// address=[0x402bd74]
// [Decompilation failed for static int CPlayerManager::m_iLocked]

// address=[0x402bd78]
// [Decompilation failed for static long CPlayerManager::m_lLocalIP]

// address=[0x402bd7c]
// [Decompilation failed for static int CPlayerManager::m_iNumberOfPlayer]

// address=[0x402bd80]
// [Decompilation failed for static int CPlayerManager::m_iLocalPlayer]

// address=[0x402bdc8]
// [Decompilation failed for static class CPlayerInfo * CPlayerManager::m_cPlayerInfos]

// address=[0x402c008]
// [Decompilation failed for static class CPlayerGameData * CPlayerManager::m_cPlayerGameData]

