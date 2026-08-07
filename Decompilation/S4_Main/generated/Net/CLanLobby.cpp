#include "CLanLobby.h"

// Definitions for class CLanLobby

// address=[0x15c9580]
// Decompiled from char __cdecl CLanLobby::ConnectPlayer(CGameHost::SJoinMessage *_rMsg, signed int a2)
bool __cdecl CLanLobby::ConnectPlayer(struct SConnectGameInfoFromClient & _rMsg, int a2) {
  
  std::wstring *v3; // [esp+4h] [ebp-4Ch]
  int iMapMaxNumPlayers; // [esp+14h] [ebp-3Ch]
  signed int v6; // [esp+18h] [ebp-38h]
  bool iPeerId; // [esp+1Fh] [ebp-31h]
  signed int i; // [esp+20h] [ebp-30h]
  std::wstring v9; // [esp+24h] [ebp-2Ch] BYREF
  int v10; // [esp+4Ch] [ebp-4h]

  v6 = 0;
  iMapMaxNumPlayers = g_pGameType->m_iMapMaxNumPlayers;
  if ( a2 != -1 )
  {
    v6 = a2;
    iMapMaxNumPlayers = a2 + 1;
  }
  for ( i = v6;
        ;
        ++i )
  {
    if ( i >= iMapMaxNumPlayers )
    {
      CTrace::Print("LanLobby: Player %s could not be connected", (const char *)_rMsg);
      return 0;
    }
    if ( g_pGameType->m_sPlayerExclusiveColor[i] && g_pGameType->m_sPlayerType[i] || CGameType::IsSaveGame(g_pGameType) && (g_pGameType->m_sPlayerType[i] == 2 || g_pGameType->m_sPlayerType[i] == 3) )
    {
      iPeerId = _rMsg->m_iPeerId == -1;
      if ( (_rMsg->m_iPeerId != -1 || g_pGameType->m_sPlayerType[i] != 1) && (_rMsg->m_iPeerId == -1 || g_pGameType->m_sPlayerType[i] == 1 || CGameType::IsSaveGame(g_pGameType)) )
      {
        break;
      }
    }
  }
  g_pGameType->m_sPlayerPeerId[i] = _rMsg->m_iPeerId;
  if ( iPeerId || _rMsg->m_bDownloadMap )
  {
    g_pGameType->m_sPlayerMapUploadStarted[i] = 6;
    if ( !iPeerId )
    {
      g_pGameType->m_sPlayerMapUploadStarted[i] = 0;
      g_pGameType->m_sPlayerType[i] = 1;
    }
  }
  else
  {
    g_pGameType->m_sPlayerMapUploadStarted[i] = 0;
  }
  v3 = (std::wstring *)std::wstring::wstring(&v9, _rMsg->m_swPlayerName);
  v10 = 0;
  CGameType::SetPlayerName(g_pGameType, i, v3);
  v10 = -1;
  std::wstring::~wstring(&v9);
  g_pGameType->m_sPlayerExclusiveColor[i] = 0;
  ++g_pGameType->m_iHumanPlayers;
  while ( !CGameHost::IsExclusiveColor(CLanLobby::m_pGameHost, i) )
  {
    ++g_pGameType->m_sPlayerColor[i];
    g_pGameType->m_sPlayerColor[i] %= 8u;
  }
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15c9860]
// Decompiled from char __cdecl CLanLobby::DisconnectPlayerPeerId(unsigned int a1, int a2)
bool __cdecl CLanLobby::DisconnectPlayerPeerId(unsigned int a1, int a2) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v4 = 0;
  v3 = *(_DWORD *)(g_pGameType + 852);
  if ( a2 != -1 )
  {
    v4 = a2;
    v3 = a2 + 1;
  }
  for ( i = v4;
        i < v3;
        ++i )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * i + 224) == a1 )
    {
      *(_BYTE *)(i + g_pGameType + 440) = 1;
      --*(_DWORD *)(g_pGameType + 620);
      *(_DWORD *)(g_pGameType + 4 * i + 452) = 6;
      *(_DWORD *)(g_pGameType + 4 * i + 116) = 1;
      *(_BYTE *)(i + g_pGameType + 998) = 1;
      return 1;
    }
  }
  return 1;
}


// address=[0x15c9930]
// Decompiled from void CLanLobby::RedrawPlayerList()
void __cdecl CLanLobby::RedrawPlayerList(void) {
  
  CGameState *CurrentState; // eax
  CStateLobbyGameSettings *v1; // [esp+0h] [ebp-4h]

  CurrentState = CGameStateHandler::GetCurrentState();
  v1 = (CStateLobbyGameSettings *)j____RTDynamicCast((void **)&CurrentState->__vftable, 0, &CGameState__RTTI_Type_Descriptor_, &CStateLobbyGameSettings__RTTI_Type_Descriptor_, 0);
  if ( v1 )
  {
    (*(void (__thiscall **)(CStateLobbyGameSettings *, int))(*(_DWORD *)v1 + 16))(v1, 1);
  }
  if ( CLanLobby::m_pGameHost->m_bHost )
  {
    if ( CLanLobby::m_pGameHost->m_pFSM )
    {
      CFsm::GenerateEvent(CLanLobby::m_pGameHost->m_pFSM, 1027, 0);
    }
  }
}


// address=[0x15c99a0]
// Decompiled from int *__cdecl CLanLobby::ChangeData(int *Src)
void __cdecl CLanLobby::ChangeData(struct SLobbyChange * Src) {
  
  int *result; // eax

  if ( !Src )
  {
    return result;
  }
  result = Src;
  if ( *Src < 0 )
  {
    return result;
  }
  if ( CLanLobby::m_pGameHost->m_bHost )
  {
    return (int *)CFsm::Control(CLanLobby::m_pGameHost->m_pFSM, 1052, Src);
  }
  else
  {
    return (int *)CGameHost::SendToHost(1052, Src, 0xCu, 0, 0, 1);
  }
  return result;
}


// address=[0x15c9a00]
// Decompiled from int *__cdecl CLanLobby::ChangeSlots(int *Src)
void __cdecl CLanLobby::ChangeSlots(struct SLobbyChange * Src) {
  
  int *result; // eax

  if ( !Src )
  {
    return result;
  }
  result = Src;
  if ( *Src < 0 )
  {
    return result;
  }
  if ( *(_BYTE *)(CLanLobby::m_pGameHost + 8) )
  {
    return (int *)CFsm::Control(*(CFsm **)(CLanLobby::m_pGameHost + 12), 1056, Src);
  }
  else
  {
    return (int *)CGameHost::SendToHost(1056, Src, 0xCu, 0, 0, 1);
  }
  return result;
}


// address=[0x15c9a60]
// Decompiled from void __cdecl CLanLobby::Communicate(int a1, void *a2)
void __cdecl CLanLobby::Communicate(int a1, void * a2) {
  
  if ( !CLanLobby::m_pGameHost && BBSupportDbgReport(2, "net\\LanLobby.cpp", 319, "m_pGameHost!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( CLanLobby::m_pGameHost )
  {
    CFsm::Control(CLanLobby::m_pGameHost->m_pFSM, a1, a2);
  }
}


// address=[0x15c4dc0]
// Decompiled from void __cdecl CLanLobby::SetGameHost(CGameHost *a1)
void __cdecl CLanLobby::SetGameHost(class CGameHost * a1) {
  
  CLanLobby::m_pGameHost = a1;
}


// address=[0x15c90d0]
// Decompiled from char CLanLobby::StartWaitGameDlg()
bool __cdecl CLanLobby::StartWaitGameDlg(bool) {
  
  return 1;
}


// address=[0x15c90e0]
// Decompiled from char CLanLobby::EndWaitGameDlg()
bool __cdecl CLanLobby::EndWaitGameDlg(void) {
  
  return 1;
}


// address=[0x15c90f0]
// Decompiled from void CLanLobby::RedrawGameList()
void __cdecl CLanLobby::RedrawGameList(void) {
  
  struct CGameState *CurrentState; // eax
  SGameInfo *v1; // eax
  SGameInfo *v2; // eax
  SGameInfo *v3; // eax
  SGameInfo *v4; // eax
  SGameInfo *v5; // eax
  SGameInfo *v6; // eax
  SGameInfo *v7; // eax
  SGameInfo *v8; // eax
  SGameInfo *v9; // eax
  SGameInfo *v10; // eax
  SGameInfo *v11; // eax
  SGameInfo *v12; // eax
  _BYTE v13[12]; // [esp+4h] [ebp-898h] BYREF
  _BYTE v14[12]; // [esp+10h] [ebp-88Ch] BYREF
  std::wstring *v15; // [esp+1Ch] [ebp-880h]
  std::wstring *a2; // [esp+20h] [ebp-87Ch]
  std::_Iterator_base12 *v17; // [esp+24h] [ebp-878h]
  std::_Iterator_base12 *v18; // [esp+28h] [ebp-874h]
  _DWORD v19[3]; // [esp+2Ch] [ebp-870h] BYREF
  char v20; // [esp+3Bh] [ebp-861h]
  CStateLobbyConnect *v21; // [esp+3Ch] [ebp-860h]
  int v22; // [esp+40h] [ebp-85Ch]
  std::wstring v23; // [esp+44h] [ebp-858h] BYREF
  std::wstring v24; // [esp+60h] [ebp-83Ch] BYREF
  wchar_t Dir[256]; // [esp+7Ch] [ebp-820h] BYREF
  wchar_t Ext[256]; // [esp+27Ch] [ebp-620h] BYREF
  wchar_t Destination[260]; // [esp+47Ch] [ebp-420h] BYREF
  wchar_t Filename[256]; // [esp+684h] [ebp-218h] BYREF
  wchar_t Drive[4]; // [esp+884h] [ebp-18h] BYREF
  int v30; // [esp+898h] [ebp-4h]

  CurrentState = CGameStateHandler::GetCurrentState();
  v21 = (CStateLobbyConnect *)j____RTDynamicCast((void **)&CurrentState->__vftable, 0, &CGameState__RTTI_Type_Descriptor_, &CStateLobbyConnect__RTTI_Type_Descriptor_, 0);
  if ( v21 )
  {
    v22 = 0;
    std::list<SGameInfo>::begin(&CLanLobby::m_pGameHost->m_vGameInfos, (int)v19);
    v30 = 0;
    while ( 1 )
    {
      v18 = (std::_Iterator_base12 *)std::list<SGameInfo>::end(v14);
      v17 = v18;
      LOBYTE(v30) = 1;
      v20 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=(v18);
      LOBYTE(v30) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v14);
      if ( !v20 )
      {
        break;
      }
      *((_DWORD *)v21 + v22 + 701) = (char *)v21 + 140 * v22 + 4;
      v1 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      *((_BYTE *)v21 + 140 * v22 + 100) = v1->m_iU0;
      v2 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      *((_DWORD *)v21 + 35 * v22 + 22) = v2->m_iMaxPlayerCount;
      v3 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      *((_DWORD *)v21 + 35 * v22 + 23) = v3->m_iPlayerCount;
      *((_DWORD *)v21 + 35 * v22 + 24) = 0;
      v4 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      *((_DWORD *)v21 + 35 * v22 + 26) = v4->m_iHostAddress;
      v5 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      std::wstring::operator=((char *)v21 + 140 * v22 + 60, v5->m_swpMapName);
      v6 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      *((_BYTE *)v21 + 140 * v22 + 110) = v6->m_bU3;
      v7 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      wcscpy(Destination, v7->m_swpMapName);
      j___wsplitpath(Destination, Drive, Dir, Filename, Ext);
      std::wstring::operator=((char *)v21 + 140 * v22 + 32, Filename);
      v8 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      a2 = (std::wstring *)std::wstring::wstring(&v24, v8->m_swpGameName);
      std::wstring::operator=((std::wstring *)((char *)v21 + 140 * v22 + 4), a2);
      std::wstring::~wstring(&v24);
      v9 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      *((_BYTE *)v21 + 140 * v22 + 108) = v9->m_iIsSaveGame;
      v10 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      *((_BYTE *)v21 + 140 * v22 + 109) = v10->m_bIsAutosave;
      v11 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      v15 = (std::wstring *)std::wstring::wstring(&v23, (wchar_t *)v11->m_swpRandomMapFileName);
      std::wstring::operator=((std::wstring *)v21 + 5 * v22 + 4, v15);
      std::wstring::~wstring(&v23);
      v12 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v19);
      *((_DWORD *)v21 + 35 * v22++ + 35) = v12->m_uTickCounter;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator++(v13, 0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v13);
    }
    dword_4030714 = v22;
    dword_403071C = (int)v21 + 2804;
    GuiDlgLanLobbyConnectUpdate();
    v30 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v19);
  }
}


// address=[0x15c94f0]
// Decompiled from void CLanLobby::RedrawMap()
void __cdecl CLanLobby::RedrawMap(void) {
  
  void **CurrentState; // eax
  _DWORD *v1; // [esp+0h] [ebp-4h]

  CurrentState = (void **)CGameStateHandler::GetCurrentState();
  v1 = (_DWORD *)j____RTDynamicCast(CurrentState, 0, &CGameState__RTTI_Type_Descriptor_, &CStateLobbyGameSettings__RTTI_Type_Descriptor_, 0);
  if ( v1 )
  {
    CStateLobbyGameSettings::PaintMap(v1);
  }
}


// address=[0x15c9530]
// Decompiled from int __cdecl CLanLobby::PrintChatLine(wchar_t *String, wchar_t *Source)
void __cdecl CLanLobby::PrintChatLine(unsigned short const * String, unsigned short const * Source) {
  
  struct CGameState *CurrentState; // eax
  int v4; // [esp+0h] [ebp-4h]

  CurrentState = CGameStateHandler::GetCurrentState();
  v4 = j____RTDynamicCast((void **)&CurrentState->__vftable, 0, &CGameState__RTTI_Type_Descriptor_, &CStateLobbyGameSettings__RTTI_Type_Descriptor_, 0);
  if ( v4 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 16))(v4, 1);
  }
  return CStateLobbyGameSettings::PrintChatLine(String, Source);
}


// address=[0x415b8f8]
// [Decompilation failed for static class CGameHost * CLanLobby::m_pGameHost]

// address=[0x415b8fc]
// [Decompilation failed for static bool CLanLobby::m_bHost]

