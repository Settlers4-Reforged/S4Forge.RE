#include "CPlayerManager.h"

// Definitions for class CPlayerManager

// address=[0x130f2c0]
// Decompiled from int __cdecl CPlayerManager::Race(int a1)
static int __cdecl CPlayerManager::Race(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\PlayerManager.h",
         172,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return dword_402BDCC[16 * a1];
}


// address=[0x130f490]
// Decompiled from bool __cdecl CPlayerManager::ValidUsedPlayerId(int a1)
static bool __cdecl CPlayerManager::ValidUsedPlayerId(int) {
  
  return a1 - 1 < CPlayerManager::m_iNumberOfPlayer;
}


// address=[0x1314080]
// Decompiled from int CPlayerManager::LastPlayerId()
static int __cdecl CPlayerManager::LastPlayerId(void) {
  
  return CPlayerManager::m_iNumberOfPlayer;
}


// address=[0x13736c0]
// Decompiled from int sub_17736C0()
static int __cdecl CPlayerManager::GetLocalPlayerId(void) {
  
  return CPlayerManager::m_iLocalPlayer;
}


// address=[0x13736d0]
// Decompiled from char *__cdecl CPlayerManager::PlayerInfo(int a1)
static class CPlayerInfo const & __cdecl CPlayerManager::PlayerInfo(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\Playermanager.h",
         158,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return (char *)&CPlayerManager::m_cPlayerInfos + 64 * a1;
}


// address=[0x13919d0]
// Decompiled from int __cdecl CPlayerManager::Color(int a1)
static int __cdecl CPlayerManager::Color(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\PlayerManager.h",
         179,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return dword_402BDE0[16 * a1];
}


// address=[0x1391a30]
// Decompiled from int CPlayerManager::NumberOfPlayers()
static int __cdecl CPlayerManager::NumberOfPlayers(void) {
  
  return CPlayerManager::m_iNumberOfPlayer;
}


// address=[0x14477c0]
// Decompiled from char *__cdecl CPlayerManager::PlayerGameData(int a1)
static class CPlayerGameData & __cdecl CPlayerManager::PlayerGameData(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\States\\..\\..\\Main\\PlayerManager.h",
         165,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return (char *)&CPlayerManager::m_cPlayerGameData + 152 * a1;
}


// address=[0x144fed0]
// Decompiled from int __cdecl CPlayerManager::Name(int a1, int a2)
static std::wstring __cdecl CPlayerManager::Name(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a2)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\PlayerManager.h",
         200,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  std::wstring::wstring((int)&unk_402BDE4 + 64 * a2);
  return a1;
}


// address=[0x1460650]
// Decompiled from char __cdecl CPlayerManager::IsAlive(int a1)
static bool __cdecl CPlayerManager::IsAlive(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\States\\..\\..\\Main\\PlayerManager.h",
         236,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return byte_402BE04[64 * a1];
}


// address=[0x147a320]
// Decompiled from bool __cdecl CPlayerManager::IsAI(int a1)
static bool __cdecl CPlayerManager::IsAI(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\PlayerManager.h",
         230,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return dword_402BE00[16 * a1] == 2 || dword_402BE00[16 * a1] == 3;
}


// address=[0x1486e90]
// Decompiled from int __cdecl CPlayerManager::GetPlayerControl(int a1)
static int __cdecl CPlayerManager::GetPlayerControl(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\States\\..\\PlayerManager.h",
         207,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return dword_402BE00[16 * a1];
}


// address=[0x14973a0]
// Decompiled from int __thiscall CPlayerManager::Init(void *this)
static void __cdecl CPlayerManager::Init(void) {
  
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  result = CPlayerManager::Done(this);
  CPlayerManager::m_lLocalIP = 0;
  CPlayerManager::m_iNumberOfPlayer = 0;
  CPlayerManager::m_iLocalPlayer = 0;
  for ( i = 0; i < 9; ++i )
  {
    CPlayerInfo::Clear((CPlayerInfo *)((char *)&CPlayerManager::m_cPlayerInfos + 64 * i));
    CPlayerGameData::Clear((CPlayerGameData *)((char *)&CPlayerManager::m_cPlayerGameData + 152 * i));
    result = i + 1;
  }
  CPlayerManager::m_iInitialized = 1;
  CPlayerManager::m_iLocked = 0;
  return result;
}


// address=[0x1497420]
// Decompiled from int __cdecl CPlayerManager::AddPlayer(  int a1,  int a2,  int a3,  int a4,  int a5,  int a6,  char a7,  int a8,  int a9,  int a10,  int a11,  int a12,  int a13,  int a14)
static int __cdecl CPlayerManager::AddPlayer(int,int,int,int,int,int,std::wstring,int) {
  
  OnlineManager *Instance; // eax
  const wchar_t *v16; // eax
  size_t v17; // [esp+18h] [ebp-11Ch]
  int v18; // [esp+1Ch] [ebp-118h]
  char *v19; // [esp+20h] [ebp-114h]
  char Dest[256]; // [esp+24h] [ebp-110h] BYREF
  int v21; // [esp+130h] [ebp-4h]

  v21 = 0;
  if ( !CPlayerManager::m_iInitialized )
  {
    if ( "AddPlayer(): Not initialized!" )
    {
      if ( BBSupportDbgReport(2, "Main\\PlayerManager.cpp", 112, "!\"AddPlayer(): Not initialized!\"") == 1 )
        __debugbreak();
    }
LABEL_15:
    v21 = -1;
    std::wstring::~wstring(&a7);
    return 0;
  }
  if ( CPlayerManager::m_iLocked )
  {
    if ( "AddPlayer(): Already locked!"
      && BBSupportDbgReport(2, "Main\\PlayerManager.cpp", 118, "!\"AddPlayer(): Already locked!\"") == 1 )
    {
      __debugbreak();
    }
    goto LABEL_15;
  }
  if ( CPlayerManager::LastPlayerId() >= 8 )
  {
    if ( "AddPlayer(): Player limit reached!"
      && BBSupportDbgReport(2, "Main\\PlayerManager.cpp", 124, "!\"AddPlayer(): Player limit reached!\"") == 1 )
    {
      __debugbreak();
    }
    goto LABEL_15;
  }
  v18 = ++CPlayerManager::m_iNumberOfPlayer;
  v19 = (char *)&CPlayerManager::m_cPlayerInfos + 64 * CPlayerManager::m_iNumberOfPlayer;
  *((_DWORD *)v19 + 1) = a1;
  *((_DWORD *)v19 + 2) = a2;
  *((_DWORD *)v19 + 3) = a3;
  *((_DWORD *)v19 + 6) = a4;
  *((_DWORD *)v19 + 4) = a5;
  *((_DWORD *)v19 + 5) = a6;
  std::wstring::operator=((int)&a7);
  *((_DWORD *)v19 + 14) = a14;
  v19[60] = 1;
  Instance = (OnlineManager *)OnlineManager::GetInstance();
  if ( OnlineManager::IsLocalPeerId(Instance, a6) )
  {
    CPlayerManager::m_iLocalPlayer = v18;
    CTrace::Print("Created local Player with id#%d", v18);
  }
  v16 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)&a7);
  v17 = j__wcstombs(Dest, v16, 0x100u);
  if ( v17 >= 0x100 )
    j____report_rangecheckfailure();
  Dest[v17] = 0;
  CTrace::Print(
    "PlayerManager.cpp: Adding player %s at %d/%d, with race %d, color %d, IP %d!",
    Dest,
    a2,
    a3,
    a1,
    a4,
    a5);
  v21 = -1;
  std::wstring::~wstring(&a7);
  return v18;
}


// address=[0x14976e0]
// Decompiled from char CPlayerManager::Lock()
static bool __cdecl CPlayerManager::Lock(void) {
  
  if ( CPlayerManager::m_iInitialized )
  {
    if ( CPlayerManager::m_iLocked )
    {
      if ( "Lock(): Already locked!"
        && BBSupportDbgReport(2, "Main\\PlayerManager.cpp", 177, "!\"Lock(): Already locked!\"") == 1 )
      {
        __debugbreak();
      }
      return 0;
    }
    else if ( CPlayerManager::m_iLocalPlayer )
    {
      CPlayerManager::m_iLocked = 1;
      return 1;
    }
    else
    {
      if ( BBSupportDbgReport(1, "Main\\PlayerManager.cpp", 183, "No local Player!") == 1 )
        __debugbreak();
      return 0;
    }
  }
  else
  {
    if ( !"Lock(): Not initialized!" )
      return 0;
    if ( BBSupportDbgReport(2, "Main\\PlayerManager.cpp", 171, "!\"Lock(): Not initialized!\"") == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x1497790]
// Decompiled from void CPlayerManager::Done()
static void __cdecl CPlayerManager::Done(void) {
  
  CPlayerManager::m_iInitialized = 0;
  CPlayerManager::m_iLocked = 0;
}


// address=[0x14977b0]
// Decompiled from int __thiscall CPlayerManager::Load(CPlayerManager *this, struct IS4Chunk *a2)
void  CPlayerManager::Load(class IS4Chunk &) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  CPlayerManager::m_iNumberOfPlayer = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(
                                        a2,
                                        0,
                                        12);
  CPlayerManager::m_iLocalPlayer = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  for ( i = 1; i <= CPlayerManager::LastPlayerId(); ++i )
  {
    CPlayerGameData::Load((CPlayerGameData *)((char *)&CPlayerManager::m_cPlayerGameData + 152 * i), a2);
    CPlayerGameData::PostLoadInit((CPlayerGameData *)((char *)&CPlayerManager::m_cPlayerGameData + 152 * i), i);
  }
  for ( j = 1; ; ++j )
  {
    result = CPlayerManager::LastPlayerId();
    if ( j > result )
      break;
    CPlayerInfo::Load((CPlayerInfo *)((char *)&CPlayerManager::m_cPlayerInfos + 64 * j), a2);
  }
  return result;
}


// address=[0x1497870]
// Decompiled from int __thiscall CPlayerManager::Save(CPlayerManager *this, struct IS4Chunk *a2)
void  CPlayerManager::Save(class IS4Chunk &) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int PlayerId; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]

  PlayerId = CPlayerManager::LastPlayerId(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, PlayerId);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, CPlayerManager::m_iLocalPlayer);
  for ( i = 1; i <= CPlayerManager::LastPlayerId(v3); ++i )
    CPlayerGameData::Save((CPlayerGameData *)((char *)&CPlayerManager::m_cPlayerGameData + 152 * i), a2);
  for ( j = 1; ; ++j )
  {
    result = CPlayerManager::LastPlayerId(v3);
    if ( j > result )
      break;
    CPlayerInfo::Save((CPlayerInfo *)((char *)&CPlayerManager::m_cPlayerInfos + 64 * j), a2);
  }
  return result;
}


// address=[0x1497920]
// Decompiled from int CPlayerManager::PrintStats()
static void __cdecl CPlayerManager::PrintStats(void) {
  
  const char *v0; // eax
  int v2; // [esp+0h] [ebp-3Ch]
  const char *v3; // [esp+4h] [ebp-38h]
  int PlayerControl; // [esp+8h] [ebp-34h]
  int i; // [esp+Ch] [ebp-30h]
  _BYTE v6[28]; // [esp+10h] [ebp-2Ch] BYREF
  int v7; // [esp+38h] [ebp-4h]

  CTrace::Print("----------------------------------------------------------------------------------");
  CTrace::Print("Player Stats:");
  for ( i = 1; i <= CPlayerManager::LastPlayerId(v2); ++i )
  {
    PlayerControl = CPlayerManager::GetPlayerControl(i);
    std::string::string(v6, "Undefined");
    v7 = 0;
    if ( PlayerControl == 2 )
      std::string::operator=(v6, "AI Level 1");
    if ( PlayerControl == 3 )
      std::string::operator=(v6, "AI Level 2");
    if ( PlayerControl == 1 )
      std::string::operator=(v6, "Human");
    if ( CPlayerManager::IsAlive(i) )
      v3 = "Yes";
    else
      v3 = "No";
    v0 = (const char *)std::string::c_str(v6);
    CTrace::Print("CPlayerManager: Player: %d, Control: %s, Alive: %s.", i, v0, v3);
    v7 = -1;
    std::string::~string(v6);
  }
  return CTrace::Print("----------------------------------------------------------------------------------");
}


// address=[0x1497a60]
// Decompiled from char CPlayerManager::GetLocalSlot()
static signed char __cdecl CPlayerManager::GetLocalSlot(void) {
  
  OnlineManager *Instance; // eax
  int v2; // eax
  int i; // [esp+0h] [ebp-4h]

  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Main\\PlayerManager.cpp", 277, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( !g_pGameType && BBSupportDbgReport(2, "Main\\PlayerManager.cpp", 278, "g_pGameType != NULL") == 1 )
    __debugbreak();
  if ( !g_pNetworkEngine || !g_pGameType )
    return -1;
  if ( *(int *)(g_pGameType + 852) > 8
    && BBSupportDbgReport(2, "Main\\PlayerManager.cpp", 284, "g_pGameType->m_iMapMaxNumPlayers <= MAX_PLAYER") == 1 )
  {
    __debugbreak();
  }
  if ( *(int *)(g_pGameType + 852) > 8 )
    return -1;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    Instance = (OnlineManager *)OnlineManager::GetInstance();
    if ( OnlineManager::IsInSession(Instance) )
    {
      v2 = StormManager::GetInstance();
      if ( StormManager::GetLocalPeerId(v2) == *(_DWORD *)(g_pGameType + 4 * i + 224) )
        return i;
    }
  }
  return 0;
}


// address=[0x1498150]
// Decompiled from CPlayerManager *__thiscall CPlayerManager::CPlayerManager(CPlayerManager *this)
 CPlayerManager::CPlayerManager(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CPlayerManager::_vftable_;
  return this;
}


// address=[0x14aae50]
// Decompiled from int __cdecl CPlayerManager::PlayerDied(int a1)
static void __cdecl CPlayerManager::PlayerDied(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\states\\..\\PlayerManager.h",
         242,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  byte_402BE04[64 * a1] = 0;
  return CPlayerManager::PrintStats();
}


// address=[0x14b4800]
// Decompiled from int __cdecl CPlayerManager::PeerId(int a1)
static int __cdecl CPlayerManager::PeerId(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\states\\..\\PlayerManager.h",
         193,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return dword_402BDDC[16 * a1];
}


// address=[0x14b4930]
// Decompiled from int __cdecl CPlayerManager::SetLocalPlayerId(int a1)
static void __cdecl CPlayerManager::SetLocalPlayerId(int) {
  
  int result; // eax

  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\states\\..\\PlayerManager.h",
         149,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  result = a1;
  CPlayerManager::m_iLocalPlayer = a1;
  return result;
}


// address=[0x14b4980]
// Decompiled from int __cdecl CPlayerManager::SetPlayerControl(int a1, int a2)
static void __cdecl CPlayerManager::SetPlayerControl(int,int) {
  
  int v3; // [esp+0h] [ebp-24h]
  int v4[7]; // [esp+4h] [ebp-20h] BYREF

  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\states\\..\\PlayerManager.h",
         214,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  dword_402BE00[16 * a1] = a2;
  if ( a2 != 2 && a2 != 3 )
    return CPlayerManager::PrintStats();
  v3 = std::operator+<wchar_t>((int)v4, (wchar_t *)L"(AI) ", (int)&unk_402BDE4 + 64 * a1);
  std::wstring::operator=(v3);
  std::wstring::~wstring(v4);
  return CPlayerManager::PrintStats();
}


// address=[0x15c4d00]
// Decompiled from int __cdecl CPlayerManager::IP(int a1)
static int __cdecl CPlayerManager::IP(int) {
  
  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\net\\..\\main\\PlayerManager.h",
         186,
         "ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  return dword_402BDD8[16 * a1];
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

