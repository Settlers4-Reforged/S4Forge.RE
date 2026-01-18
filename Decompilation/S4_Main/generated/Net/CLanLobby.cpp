#include "CLanLobby.h"

// Definitions for class CLanLobby

// address=[0x15c9580]
// Decompiled from char __cdecl CLanLobby::ConnectPlayer(wchar_t *String, signed int a2)
bool __cdecl CLanLobby::ConnectPlayer(struct SConnectGameInfoFromClient & String, int a2) {
  
  int v3; // [esp+4h] [ebp-4Ch]
  signed int v5; // [esp+14h] [ebp-3Ch]
  signed int v6; // [esp+18h] [ebp-38h]
  bool v7; // [esp+1Fh] [ebp-31h]
  signed int i; // [esp+20h] [ebp-30h]
  _BYTE v9[28]; // [esp+24h] [ebp-2Ch] BYREF
  int v10; // [esp+4Ch] [ebp-4h]

  v6 = 0;
  v5 = *(_DWORD *)(g_pGameType + 852);
  if ( a2 != -1 )
  {
    v6 = a2;
    v5 = a2 + 1;
  }
  for ( i = v6; ; ++i )
  {
    if ( i >= v5 )
    {
      CTrace::Print("LanLobby: Player %s could not be connected", (const char *)String);
      return 0;
    }
    if ( *(_BYTE *)(i + g_pGameType + 440) && *(_DWORD *)(g_pGameType + 4 * i + 116)
      || (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType)
      && (*(_DWORD *)(g_pGameType + 4 * i + 116) == 2 || *(_DWORD *)(g_pGameType + 4 * i + 116) == 3) )
    {
      v7 = *(_DWORD *)((char *)String + 65) == -1;
      if ( (*(_DWORD *)((char *)String + 65) != -1 || *(_DWORD *)(g_pGameType + 4 * i + 116) != 1)
        && (*(_DWORD *)((char *)String + 65) == -1
         || *(_DWORD *)(g_pGameType + 4 * i + 116) == 1
         || (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType)) )
      {
        break;
      }
    }
  }
  *(_DWORD *)(g_pGameType + 4 * i + 224) = *(_DWORD *)((char *)String + 65);
  if ( v7 || *((_BYTE *)String + 94) )
  {
    *(_DWORD *)(g_pGameType + 4 * i + 452) = 6;
    if ( !v7 )
    {
      *(_DWORD *)(g_pGameType + 4 * i + 452) = 0;
      *(_DWORD *)(g_pGameType + 4 * i + 116) = 1;
    }
  }
  else
  {
    *(_DWORD *)(g_pGameType + 4 * i + 452) = 0;
  }
  v3 = std::wstring::wstring(v9, String);
  v10 = 0;
  CGameType::SetPlayerName(i, v3);
  v10 = -1;
  std::wstring::~wstring(v9);
  *(_BYTE *)(i + g_pGameType + 440) = 0;
  ++*(_DWORD *)(g_pGameType + 620);
  while ( !CGameHost::IsExclusiveColor((CGameHost *)CLanLobby::m_pGameHost, i) )
  {
    ++*(_DWORD *)(g_pGameType + 4 * i + 332);
    *(_DWORD *)(g_pGameType + 4 * i + 332) %= 8u;
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
  for ( i = v4; i < v3; ++i )
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
// Decompiled from _DWORD *CLanLobby::RedrawPlayerList()
void __cdecl CLanLobby::RedrawPlayerList(void) {
  
  void **CurrentState; // eax
  _DWORD *result; // eax

  CurrentState = (void **)CGameStateHandler::GetCurrentState();
  result = (_DWORD *)j____RTDynamicCast(
                       CurrentState,
                       0,
                       &CGameState__RTTI_Type_Descriptor_,
                       &CStateLobbyGameSettings__RTTI_Type_Descriptor_,
                       0);
  if ( result )
    result = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*result + 16))(result, 1);
  if ( !*(_BYTE *)(CLanLobby::m_pGameHost + 8) )
    return result;
  result = (_DWORD *)CLanLobby::m_pGameHost;
  if ( *(_DWORD *)(CLanLobby::m_pGameHost + 12) )
    return CFsm::GenerateEvent(1027, 0);
  return result;
}


// address=[0x15c99a0]
// Decompiled from int *__cdecl CLanLobby::ChangeData(int *Src)
void __cdecl CLanLobby::ChangeData(struct SLobbyChange * Src) {
  
  int *result; // eax

  if ( !Src )
    return result;
  result = Src;
  if ( *Src < 0 )
    return result;
  if ( *(_BYTE *)(CLanLobby::m_pGameHost + 8) )
    return (int *)CFsm::Control(*(CFsm **)(CLanLobby::m_pGameHost + 12), 1052, Src);
  else
    return (int *)CGameHost::SendToHost(1052, Src, 0xCu, 0, 0, 1);
  return result;
}


// address=[0x15c9a00]
// Decompiled from int *__cdecl CLanLobby::ChangeSlots(int *Src)
void __cdecl CLanLobby::ChangeSlots(struct SLobbyChange * Src) {
  
  int *result; // eax

  if ( !Src )
    return result;
  result = Src;
  if ( *Src < 0 )
    return result;
  if ( *(_BYTE *)(CLanLobby::m_pGameHost + 8) )
    return (int *)CFsm::Control(*(CFsm **)(CLanLobby::m_pGameHost + 12), 1056, Src);
  else
    return (int *)CGameHost::SendToHost(1056, Src, 0xCu, 0, 0, 1);
  return result;
}


// address=[0x15c9a60]
// Decompiled from int __cdecl CLanLobby::Communicate(int a1, void *a2)
void __cdecl CLanLobby::Communicate(int a1, void * a2) {
  
  int result; // eax

  if ( !CLanLobby::m_pGameHost && BBSupportDbgReport(2, "net\\LanLobby.cpp", 319, "m_pGameHost!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( CLanLobby::m_pGameHost )
    return CFsm::Control(*(CFsm **)(CLanLobby::m_pGameHost + 12), a1, a2);
  return result;
}


// address=[0x15c4dc0]
// Decompiled from void __cdecl CLanLobby::SetGameHost(struct CFrameWnd *a1)
void __cdecl CLanLobby::SetGameHost(class CGameHost * a1) {
  
  CLanLobby::m_pGameHost = (int)a1;
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
// Decompiled from int CLanLobby::RedrawGameList()
void __cdecl CLanLobby::RedrawGameList(void) {
  
  void **CurrentState; // eax
  int result; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  _BYTE v14[12]; // [esp+4h] [ebp-898h] BYREF
  _BYTE v15[12]; // [esp+10h] [ebp-88Ch] BYREF
  int v16; // [esp+1Ch] [ebp-880h]
  int v17; // [esp+20h] [ebp-87Ch]
  std::_Iterator_base12 *v18; // [esp+24h] [ebp-878h]
  std::_Iterator_base12 *v19; // [esp+28h] [ebp-874h]
  _BYTE v20[15]; // [esp+2Ch] [ebp-870h] BYREF
  char v21; // [esp+3Bh] [ebp-861h]
  int v22; // [esp+3Ch] [ebp-860h]
  int v23; // [esp+40h] [ebp-85Ch]
  _BYTE v24[28]; // [esp+44h] [ebp-858h] BYREF
  _BYTE v25[28]; // [esp+60h] [ebp-83Ch] BYREF
  wchar_t Dir[256]; // [esp+7Ch] [ebp-820h] BYREF
  wchar_t Ext[256]; // [esp+27Ch] [ebp-620h] BYREF
  wchar_t Destination[260]; // [esp+47Ch] [ebp-420h] BYREF
  wchar_t Filename[256]; // [esp+684h] [ebp-218h] BYREF
  wchar_t Drive[4]; // [esp+884h] [ebp-18h] BYREF
  int v31; // [esp+898h] [ebp-4h]

  CurrentState = (void **)CGameStateHandler::GetCurrentState();
  result = j____RTDynamicCast(
             CurrentState,
             0,
             &CGameState__RTTI_Type_Descriptor_,
             &CStateLobbyConnect__RTTI_Type_Descriptor_,
             0);
  v22 = result;
  if ( !result )
    return result;
  v23 = 0;
  std::list<SGameInfo>::begin(v20);
  v31 = 0;
  while ( 1 )
  {
    v19 = (std::_Iterator_base12 *)std::list<SGameInfo>::end(v15);
    v18 = v19;
    LOBYTE(v31) = 1;
    v21 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=(v19);
    LOBYTE(v31) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v15);
    if ( !v21 )
      break;
    *(_DWORD *)(v22 + 4 * v23 + 2804) = v22 + 140 * v23 + 4;
    v2 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    *(_BYTE *)(v22 + 140 * v23 + 100) = *(_BYTE *)(v2 + 612);
    v3 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    *(_DWORD *)(v22 + 140 * v23 + 88) = *(_DWORD *)(v3 + 608);
    v4 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    *(_DWORD *)(v22 + 140 * v23 + 92) = *(_DWORD *)(v4 + 604);
    *(_DWORD *)(v22 + 140 * v23 + 96) = 0;
    v5 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    *(_DWORD *)(v22 + 140 * v23 + 104) = *v5;
    v6 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    std::wstring::operator=((void *)(v22 + 140 * v23 + 60), (wchar_t *)(v6 + 80));
    v7 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    *(_BYTE *)(v22 + 140 * v23 + 110) = *(_BYTE *)(v7 + 632);
    v8 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    j__wcscpy(Destination, (const wchar_t *)(v8 + 80));
    j___wsplitpath(Destination, Drive, Dir, Filename, Ext);
    std::wstring::operator=((void *)(v22 + 140 * v23 + 32), Filename);
    v9 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    v17 = std::wstring::wstring(v25, (wchar_t *)(v9 + 16));
    std::wstring::operator=(v17);
    std::wstring::~wstring(v25);
    v10 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    *(_BYTE *)(v22 + 140 * v23 + 108) = *(_BYTE *)(v10 + 624);
    v11 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    *(_BYTE *)(v22 + 140 * v23 + 109) = *(_BYTE *)(v11 + 633);
    v12 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    v16 = std::wstring::wstring(v24, (wchar_t *)(v12 + 648));
    std::wstring::operator=(v16);
    std::wstring::~wstring(v24);
    v13 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v20);
    *(_DWORD *)(v22 + 140 * v23++ + 140) = *(_DWORD *)(v13 + 628);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator++(v14, 0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v14);
  }
  dword_4030714 = v23;
  dword_403071C = v22 + 2804;
  GuiDlgLanLobbyConnectUpdate();
  v31 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v20);
}


// address=[0x15c94f0]
// Decompiled from void *CLanLobby::RedrawMap()
void __cdecl CLanLobby::RedrawMap(void) {
  
  void **CurrentState; // eax
  void *result; // eax

  CurrentState = (void **)CGameStateHandler::GetCurrentState();
  result = (void *)j____RTDynamicCast(
                     CurrentState,
                     0,
                     &CGameState__RTTI_Type_Descriptor_,
                     &CStateLobbyGameSettings__RTTI_Type_Descriptor_,
                     0);
  if ( result )
    return (void *)CStateLobbyGameSettings::PaintMap(result);
  return result;
}


// address=[0x15c9530]
// Decompiled from int __cdecl sub_19C9530(wchar_t *String, wchar_t *Source)
void __cdecl CLanLobby::PrintChatLine(unsigned short const * String, unsigned short const * Source) {
  
  void **v2; // eax
  int v4; // [esp+0h] [ebp-4h]

  v2 = (void **)CGameStateHandler::GetCurrentState();
  v4 = j____RTDynamicCast(v2, 0, &CGameState__RTTI_Type_Descriptor_, &CStateLobbyGameSettings__RTTI_Type_Descriptor_, 0);
  if ( v4 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 16))(v4, 1);
  return CStateLobbyGameSettings::PrintChatLine(String, Source);
}


// address=[0x415b8f8]
// [Decompilation failed for static class CGameHost * CLanLobby::m_pGameHost]

// address=[0x415b8fc]
// [Decompilation failed for static bool CLanLobby::m_bHost]

