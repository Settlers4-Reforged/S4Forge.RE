#include "all_headers.h"

// Definitions for class CStateLobbyMapSettings

// address=[0x14bd6f0]
// Decompiled from CStateLobbyMapSettings *__cdecl CStateLobbyMapSettings::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateLobbyMapSettings::DynamicCreateFunc(void *) {
  
  CStateLobbyMapSettings *C; // [esp+Ch] [ebp-10h]

  C = (CStateLobbyMapSettings *)operator new(0x14u);
  if ( C )
    return CStateLobbyMapSettings::CStateLobbyMapSettings(C, a1);
  else
    return 0;
}


// address=[0x14bd770]
// Decompiled from CStateLobbyMapSettings *__thiscall CStateLobbyMapSettings::CStateLobbyMapSettings(  CStateLobbyMapSettings *this,  void *a2)
 CStateLobbyMapSettings::CStateLobbyMapSettings(void *) {
  
  const char *v2; // eax
  const char *v3; // eax
  int v5; // [esp+4h] [ebp-47Ch]
  _Cnd_internal_imp_t *PlayerName; // [esp+8h] [ebp-478h]
  CGameType *v7; // [esp+24h] [ebp-45Ch]
  CGameType *C; // [esp+28h] [ebp-458h]
  _BYTE v10[28]; // [esp+38h] [ebp-448h] BYREF
  char v11[28]; // [esp+54h] [ebp-42Ch] BYREF
  char Buffer[2]; // [esp+70h] [ebp-410h] BYREF
  __int16 v13; // [esp+AEh] [ebp-3D2h]
  wchar_t Dest[256]; // [esp+270h] [ebp-210h] BYREF
  int v15; // [esp+47Ch] [ebp-4h]

  CGuiGameState::CGuiGameState(this);
  v15 = 0;
  *(_DWORD *)this = &CStateLobbyMapSettings::_vftable_;
  byte_403190C = 0;
  *((_BYTE *)this + 4) = (_BYTE)a2;
  *((_BYTE *)this + 12) = 1;
  *((_DWORD *)this + 2) = 0;
  byte_4031914 = *((_BYTE *)this + 4);
  if ( g_pNetworkEngine )
  {
    (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
    g_pNetworkEngine = 0;
  }
  if ( g_pGameType )
  {
    CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
    g_pGameType = 0;
  }
  if ( g_pGameType )
  {
    CStateLobbyMapSettings::SetupGUI(this);
  }
  else
  {
    C = (CGameType *)operator new(0x620u);
    LOBYTE(v15) = 1;
    if ( C )
      v7 = CGameType::CGameType(C);
    else
      v7 = 0;
    LOBYTE(v15) = 0;
    g_pGameType = (int)v7;
    memset(&CStateLobbyMapSettings::m_stempMapPtr, 0, 0xFA0u);
    dword_4031938 = 0;
    CStateLobbyMapSettings::SetupGUI(this);
    dword_4031920 = (int)&CStateLobbyMapSettings::m_stempMapPtr;
    v2 = g_pStringEngine->GetString(g_pStringEngine, 789);
    j__mbstowcs(Dest, v2, 0x200u);
    if ( !j__wcscmp(Dest, L"dummy") )
      j__wcscpy(Dest, L"%s's Game");
    PlayerName = (_Cnd_internal_imp_t *)CGameSettings::GetPlayerName((int)v11);
    v3 = (const char *)std::wstring::c_str(PlayerName);
    j__swprintf(Buffer, 0x100u, v3);
    std::wstring::~wstring(v11);
    v13 = 0;
    v5 = std::wstring::wstring(v10, (wchar_t *)Buffer);
    std::wstring::operator=(v5);
    std::wstring::~wstring(v10);
    CStateLobbyMapSettings::RefreshMapList(this);
  }
  return this;
}


// address=[0x14bda80]
// Decompiled from void __thiscall CStateLobbyMapSettings::~CStateLobbyMapSettings(CStateLobbyMapSettings *this)
 CStateLobbyMapSettings::~CStateLobbyMapSettings(void) {
  
  *(_DWORD *)this = &CStateLobbyMapSettings::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 4))
    && BBSupportDbgReport(2, "main\\states\\StateLobbyMapSettings.cpp", 151, "bRet") == 1 )
  {
    __debugbreak();
  }
  CStateLobbyMapSettings::ClearMapList(this);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14bdb10]
// Decompiled from char __thiscall CStateLobbyMapSettings::Perform(CStateLobbyMapSettings *this)
bool  CStateLobbyMapSettings::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_4031CEC > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_4031CEC);
    if ( dword_4031CEC == -1 )
    {
      dword_4031CE8 = timeGetTime();
      j___Init_thread_footer(&dword_4031CEC);
    }
  }
  v1 = dword_4031CE8 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_4031CE8 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14bdbb0]
// Decompiled from char __thiscall CStateLobbyMapSettings::OnEvent(CStateLobbyMapSettings *this, struct CEvn_Event *a2)
bool  CStateLobbyMapSettings::OnEvent(class CEvn_Event &) {
  
  char result; // al
  char *v3; // eax
  int v4; // edx
  signed __int8 LocalSlot; // al
  char v6; // al
  int Instance; // eax
  char v8; // [esp-40h] [ebp-154h] BYREF
  int v9; // [esp-3Ch] [ebp-150h]
  int v10; // [esp-38h] [ebp-14Ch]
  int v11; // [esp-34h] [ebp-148h]
  int v12; // [esp-30h] [ebp-144h]
  int v13; // [esp-2Ch] [ebp-140h]
  int v14; // [esp-28h] [ebp-13Ch]
  BOOL v15; // [esp-24h] [ebp-138h]
  char *LocalIP; // [esp-20h] [ebp-134h]
  int v17; // [esp-1Ch] [ebp-130h]
  int v18; // [esp-18h] [ebp-12Ch]
  int v19; // [esp-14h] [ebp-128h]
  int AIDifficulty; // [esp-10h] [ebp-124h]
  int v21; // [esp-Ch] [ebp-120h]
  int v22; // [esp-8h] [ebp-11Ch]
  int v23; // [esp-4h] [ebp-118h]
  char *v24; // [esp+8h] [ebp-10Ch]
  int v25; // [esp+Ch] [ebp-108h]
  CEvn_Event *v26; // [esp+14h] [ebp-100h]
  int PlayerName; // [esp+1Ch] [ebp-F8h]
  CEvn_Event *v28; // [esp+20h] [ebp-F4h]
  unsigned int v29; // [esp+28h] [ebp-ECh]
  int v30; // [esp+2Ch] [ebp-E8h]
  INetworkEngine *v31; // [esp+34h] [ebp-E0h]
  int v32; // [esp+38h] [ebp-DCh]
  int v33; // [esp+3Ch] [ebp-D8h]
  void *v34; // [esp+40h] [ebp-D4h]
  int v35; // [esp+44h] [ebp-D0h]
  CEvn_Event *v36; // [esp+48h] [ebp-CCh]
  int v37; // [esp+4Ch] [ebp-C8h]
  INetworkEngine *v38; // [esp+50h] [ebp-C4h]
  void *C; // [esp+54h] [ebp-C0h]
  int wparam; // [esp+5Ch] [ebp-B8h]
  BOOL v41; // [esp+64h] [ebp-B0h]
  BOOL v42; // [esp+68h] [ebp-ACh]
  BOOL v43; // [esp+6Ch] [ebp-A8h]
  BOOL v44; // [esp+70h] [ebp-A4h]
  BOOL v45; // [esp+74h] [ebp-A0h]
  BOOL v46; // [esp+78h] [ebp-9Ch]
  int (__thiscall ***v47)(_DWORD, int); // [esp+7Ch] [ebp-98h]
  bool v48; // [esp+83h] [ebp-91h]
  unsigned int j; // [esp+84h] [ebp-90h]
  int v50; // [esp+88h] [ebp-8Ch]
  unsigned int i; // [esp+8Ch] [ebp-88h]
  unsigned int event; // [esp+90h] [ebp-84h]
  char v53; // [esp+94h] [ebp-80h]
  char v54; // [esp+95h] [ebp-7Fh]
  bool v55; // [esp+96h] [ebp-7Eh]
  CGuiGameState *v56; // [esp+98h] [ebp-7Ch]
  char v57; // [esp+9Fh] [ebp-75h]
  _BYTE v58[28]; // [esp+A0h] [ebp-74h] BYREF
  CEvn_Event v59; // [esp+BCh] [ebp-58h] BYREF
  CEvn_Event v60; // [esp+D4h] [ebp-40h] BYREF
  CEvn_Event v61; // [esp+ECh] [ebp-28h] BYREF
  int v62; // [esp+110h] [ebp-4h]

  v56 = this;
  event = a2->event;
  if ( event > 0x1B69 )
    return CGuiGameState::OnEvent(v56, a2);
  if ( event == 7017 )
  {
    CGameStateHandler::Switch((int)CStateMDRandomMapParameters::DynamicCreateFunc, *((unsigned __int8 *)v56 + 4));
    return CGuiGameState::OnEvent(v56, a2);
  }
  event -= 13;
  switch ( event )
  {
    case 0u:
      if ( a2->wparam != 27 )
        return 1;
      if ( byte_403190C )
      {
        v26 = CEvn_Event::CEvn_Event(&v61, 0x72u, 0, 0, 0);
        v62 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v26);
        v62 = -1;
        CEvn_Event::~CEvn_Event(&v61);
      }
      else
      {
        v36 = CEvn_Event::CEvn_Event(&v60, 0x3Fu, 0, 0, 0);
        v62 = 1;
        IEventEngine::SendAMessage(g_pEvnEngine, v36);
        v62 = -1;
        CEvn_Event::~CEvn_Event(&v60);
      }
      return 1;
    case 0x32u:
      if ( *((_BYTE *)v56 + 4) )
        CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 1);
      else
        CGameStateHandler::Switch((int)CStateLocalType::DynamicCreateFunc, 1);
      if ( !g_pGameType )
        return 1;
      v35 = g_pGameType;
      v34 = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
      g_pGameType = 0;
      return 1;
    case 0x33u:
      IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
      if ( g_pNetworkEngine )
      {
        v33 = g_pNetworkEngine;
        v47 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
        v32 = (**v47)(v47, 1);
        g_pNetworkEngine = 0;
      }
      C = operator new(0x18u);
      v62 = 2;
      if ( C )
        v38 = INetworkEngine::INetworkEngine((INetworkEngine *)C, *((_BYTE *)v56 + 4));
      else
        v38 = 0;
      v31 = v38;
      v62 = -1;
      g_pNetworkEngine = (int)v38;
      v54 = INetworkEngine::Start(1, 0, 0, 0);
      if ( v54 || !*((_BYTE *)v56 + 4) )
      {
        v55 = *((_BYTE *)v56 + 4) == 0;
        v23 = 0;
        v22 = 0;
        v21 = -1;
        AIDifficulty = CGameSettings::GetAIDifficulty();
        v19 = 0;
        v18 = 1;
        v17 = 1;
        LocalIP = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
        v15 = v55;
        v4 = CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 28;
        v24 = &v8;
        v25 = std::wstring::wstring(v4);
        CGameType::LoadMapData(
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          LocalIP,
          v17,
          v18,
          v19,
          AIDifficulty,
          v21,
          v22,
          v23);
        *(_DWORD *)(g_pGameType + 72) = dword_4031928;
        *(_DWORD *)(g_pGameType + 112) = dword_4031924;
        *(_DWORD *)(g_pGameType + 852) = dword_4031924;
        *(_DWORD *)(g_pGameType + 64) = dword_4031930;
        *(_DWORD *)(g_pGameType + 864) = dword_4031934;
        *(_DWORD *)(g_pGameType + 112) = dword_4031924;
        std::wstring::operator=((int)&unk_4031960);
        if ( *((_BYTE *)v56 + 4) )
          v37 = 2;
        else
          v37 = 1;
        *(_DWORD *)(g_pGameType + 692) = v37;
        *(_DWORD *)(g_pGameType + 740) = 0;
        LocalSlot = CPlayerManager::GetLocalSlot();
        CGameType::SetLocalSlot((CGameType *)g_pGameType, LocalSlot);
        PlayerName = CGameSettings::GetPlayerName((int)v58);
        v30 = PlayerName;
        v62 = 3;
        v23 = PlayerName;
        v6 = CPlayerManager::GetLocalSlot();
        CGameType::SetPlayerName(v6, v23);
        v62 = -1;
        std::wstring::~wstring(v58);
        *(_BYTE *)(g_pGameType + 560) = byte_403199C;
        for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
          *(_DWORD *)(g_pGameType + 4 * i + 152) %= *(_DWORD *)(g_pGameType + 72);
        if ( dword_4031934 == 5 )
        {
          *(_BYTE *)(g_pGameType + 748) = 1;
          *(_DWORD *)(g_pGameType + 752) = 1;
        }
        if ( dword_4031934 == 3 )
        {
          v29 = *(_DWORD *)(g_pGameType + 112) % 2u + (*(_DWORD *)(g_pGameType + 112) >> 1);
          for ( j = 0; j < *(_DWORD *)(g_pGameType + 72); ++j )
            *(_DWORD *)(g_pGameType + 4 * j + 76) = v29;
        }
        CGameType::SetHost((CGameType *)g_pGameType, 1);
        CGameStateHandler::Switch((int)CStateLobbyGameSettings::DynamicCreateFunc, 1);
        Instance = OnlineManager::GetInstance();
        if ( (unsigned __int8)OnlineManager::IsQuickMatchFlow(Instance) )
          CLanLobby::Communicate(1059, 0);
        else
          CLanLobby::Communicate(1051, 0);
        return 1;
      }
      else
      {
        byte_403190C = 1;
        CTrace::Print("GameHost: Unrecoverable network error while starting network for Creating Game!");
        v3 = g_pStringEngine->GetString(g_pStringEngine, 2402);
        std::string::operator=(&g_iMessageBoxStringID, v3);
        IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)v56 + 4));
        if ( !IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc)
          && BBSupportDbgReport(2, "main\\states\\StateLobbyMapSettings.cpp", 458, "bRet") == 1 )
        {
          __debugbreak();
        }
        return 1;
      }
    case 0x34u:
      dword_4031938 = 0;
      dword_403191C = a2->wparam;
      dword_4031918 = CStateLobbyMapSettings::RefreshMapList(v56);
      return 1;
    case 0x35u:
      if ( a2->wparam )
      {
        if ( dword_4031938 == *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 88) - 1 )
          dword_4031938 = 0;
        else
          ++dword_4031938;
      }
      else if ( dword_4031938 )
      {
        --dword_4031938;
      }
      else
      {
        dword_4031938 = *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 88) - 1;
      }
      CStateLobbyMapSettings::ApplyMapData(v56, dword_403192C);
      return 1;
    case 0x36u:
      if ( a2->wparam )
      {
        if ( dword_4031928 == dword_4031924 )
          return 1;
        if ( dword_4031934 == 3 && dword_4031928 < 2 || dword_4031934 != 3 )
          ++dword_4031928;
      }
      else
      {
        if ( dword_4031928 == 1 || dword_4031934 != 5 && dword_4031928 <= 2 )
          return 1;
        --dword_4031928;
      }
      goto LABEL_110;
    case 0x37u:
      if ( a2->wparam )
      {
        if ( dword_4031924 == *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 56) )
          return 1;
        ++dword_4031924;
      }
      else
      {
        if ( dword_4031924 <= 2 )
          return 1;
        if ( dword_4031928 > --dword_4031924 )
          --dword_4031928;
      }
      goto LABEL_110;
    case 0x38u:
      v57 = 0;
      do
      {
        if ( a2->wparam )
        {
          if ( ++dword_4031934 > 6 )
            dword_4031934 = 1;
        }
        else if ( !--dword_4031934 )
        {
          dword_4031934 = 5;
        }
        v50 = dword_4031934 - 1;
        switch ( dword_4031934 )
        {
          case 1:
            if ( *(_BYTE *)(*(_DWORD *)(dword_4031920 + 4 * dword_403192C) + 72) )
            {
              v57 = 1;
              v46 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 79) == 0;
              byte_403195A = v46;
              v45 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 80) == 0;
              byte_403195B = v45;
              dword_4031928 = *(_DWORD *)(g_pGameType + 852);
              dword_4031924 = *(_DWORD *)(g_pGameType + 852);
            }
            break;
          case 2:
            if ( *(_BYTE *)(*(_DWORD *)(dword_4031920 + 4 * dword_403192C) + 76) )
            {
              v57 = 1;
              v44 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 79) == 0;
              byte_403195A = v44;
              v43 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 80) == 0;
              byte_403195B = v43;
              dword_4031928 = *(_DWORD *)(g_pGameType + 852);
              dword_4031924 = *(_DWORD *)(g_pGameType + 852);
            }
            break;
          case 3:
            if ( *(_BYTE *)(*(_DWORD *)(dword_4031920 + 4 * dword_403192C) + 74) )
            {
              v57 = 1;
              v42 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 79) == 0;
              byte_403195A = v42;
              v41 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[dword_403192C] + 80) == 0;
              byte_403195B = v41;
              dword_4031928 = 2;
              dword_4031924 = *(_DWORD *)(g_pGameType + 852);
            }
            break;
          case 5:
            if ( *(_BYTE *)(*(_DWORD *)(dword_4031920 + 4 * dword_403192C) + 73) )
            {
              v57 = 1;
              byte_403195A = 0;
              byte_403195B = 0;
              dword_4031928 = 1;
              dword_4031924 = 1;
            }
            break;
          default:
            v57 = 0;
            break;
        }
      }
      while ( !v57 );
      goto LABEL_110;
    case 0x39u:
      if ( a2->wparam )
      {
        if ( dword_4031930 == 3 )
          return 1;
        ++dword_4031930;
      }
      else
      {
        if ( dword_4031930 == 1 )
          return 1;
        --dword_4031930;
      }
LABEL_110:
      CStateLobbyMapSettings::UpdateData(v56);
      result = 1;
      break;
    case 0x3Au:
      dword_4031938 = 0;
      dword_403192C = a2->wparam;
      CStateLobbyMapSettings::ApplyMapData(v56, dword_403192C);
      return 1;
    case 0x3Bu:
      wparam = a2->wparam;
      if ( wparam == *((_DWORD *)v56 + 2) )
      {
        *((_BYTE *)v56 + 12) = *((_BYTE *)v56 + 12) == 0;
      }
      else
      {
        *((_DWORD *)v56 + 2) = wparam;
        *((_BYTE *)v56 + 12) = 1;
      }
      goto LABEL_110;
    case 0x3Eu:
      if ( a2->wparam )
        byte_403199C |= 1u;
      else
        byte_403199C &= ~1u;
      v53 = byte_403199C;
      return 1;
    case 0x65u:
      byte_403190C = 0;
      v48 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
      CStateLobbyMapSettings::SetupGUI(v56);
      v28 = CEvn_Event::CEvn_Event(&v59, 0x3Fu, 0, 0, 0);
      v62 = 4;
      IEventEngine::SendAMessage(g_pEvnEngine, v28);
      v62 = -1;
      CEvn_Event::~CEvn_Event(&v59);
      return 1;
    default:
      return CGuiGameState::OnEvent(v56, a2);
  }
  return result;
}


// address=[0x14be980]
// Decompiled from void __thiscall CStateLobbyMapSettings::AddMapList(  _BYTE *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  char a9,  int a10,  int a11,  int a12,  int a13,  int a14,  int a15)
void  CStateLobbyMapSettings::AddMapList(std::wstring,std::wstring) {
  
  const wchar_t *v15; // eax
  char v16; // [esp-40h] [ebp-570h] BYREF
  int v17; // [esp-3Ch] [ebp-56Ch]
  int v18; // [esp-38h] [ebp-568h]
  int v19; // [esp-34h] [ebp-564h]
  int v20; // [esp-30h] [ebp-560h]
  int v21; // [esp-2Ch] [ebp-55Ch]
  int v22; // [esp-28h] [ebp-558h]
  BOOL v23; // [esp-24h] [ebp-554h]
  char *v24; // [esp-20h] [ebp-550h]
  int v25; // [esp-1Ch] [ebp-54Ch]
  int v26; // [esp-18h] [ebp-548h]
  int v27; // [esp-14h] [ebp-544h]
  int v28; // [esp-10h] [ebp-540h]
  int v29; // [esp-Ch] [ebp-53Ch]
  int v30; // [esp-8h] [ebp-538h]
  int v31; // [esp-4h] [ebp-534h]
  int v32; // [esp+4h] [ebp-52Ch]
  char *v33; // [esp+8h] [ebp-528h]
  void *v34; // [esp+Ch] [ebp-524h]
  CLanLobbyMapSettings::SMapEntry *v35; // [esp+10h] [ebp-520h]
  void *v36; // [esp+14h] [ebp-51Ch]
  _WORD *v37; // [esp+18h] [ebp-518h]
  _BYTE *v38; // [esp+1Ch] [ebp-514h]
  CLanLobbyMapSettings::SMapEntry *v39; // [esp+20h] [ebp-510h]
  BOOL v40; // [esp+24h] [ebp-50Ch]
  BOOL v41; // [esp+28h] [ebp-508h]
  BOOL v42; // [esp+2Ch] [ebp-504h]
  int v43; // [esp+30h] [ebp-500h]
  BOOL v44; // [esp+34h] [ebp-4FCh]
  BOOL v45; // [esp+38h] [ebp-4F8h]
  BOOL v46; // [esp+3Ch] [ebp-4F4h]
  int v47; // [esp+40h] [ebp-4F0h]
  void *v48; // [esp+44h] [ebp-4ECh]
  intptr_t FindHandle; // [esp+48h] [ebp-4E8h]
  char MapData; // [esp+4Eh] [ebp-4E2h]
  bool v51; // [esp+4Fh] [ebp-4E1h]
  int *v52; // [esp+50h] [ebp-4E0h]
  bool v53; // [esp+57h] [ebp-4D9h]
  struct _wfinddata64i32_t FindData; // [esp+58h] [ebp-4D8h] BYREF
  char v55[88]; // [esp+288h] [ebp-2A8h] BYREF
  _BYTE v56[28]; // [esp+2E0h] [ebp-250h] BYREF
  int v57[7]; // [esp+2FCh] [ebp-234h] BYREF
  wchar_t String[260]; // [esp+318h] [ebp-218h] BYREF
  int v59; // [esp+52Ch] [ebp-4h]

  v38 = this;
  v59 = 1;
  v52 = &dword_4031918;
  v15 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)&a9);
  FindHandle = j___wfindfirst64i32(v15, &FindData);
  if ( FindHandle != -1 )
  {
    do
    {
      v48 = operator new(0x7Cu);
      if ( v48 )
      {
        memset(v48, 0, 0x7Cu);
        v47 = CLanLobbyMapSettings::SMapEntry::SMapEntry((CLanLobbyMapSettings::SMapEntry *)v48);
      }
      else
      {
        v47 = 0;
      }
      CStateLobbyMapSettings::m_stempMapPtr[*v52] = v47;
      std::operator+<wchar_t>((int)v57, (int)&a2, FindData.name);
      LOBYTE(v59) = 2;
      v51 = v38[4] == 0;
      v31 = 0;
      v30 = 0;
      v29 = -1;
      v28 = -1;
      v27 = 0;
      v26 = 0;
      v25 = 0;
      v24 = (char *)&dword_F29144[220110] + 3;
      v23 = v51;
      v33 = &v16;
      v32 = std::wstring::wstring((int)v57);
      MapData = CGameType::LoadMapData(v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31);
      v53 = MapData;
      v46 = MapData
         && (!CGameType::IsAddOnMap((CGameType *)g_pGameType)
          || !CGameType::IsBlueByteAddOnMap((CGameType *)g_pGameType)
          || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pAddOn + 4))(g_pAddOn));
      v53 = v46;
      v45 = v46
         && (!CGameType::IsAddOnMap((CGameType *)g_pGameType)
          || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pAddOn + 4))(g_pAddOn)
          || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pMissionCD2 + 4))(g_pMissionCD2));
      v53 = v45;
      v44 = v45
         && (!CGameType::IsMCD2TextureSet((CGameType *)g_pGameType)
          && !CGameType::IsBlueByteMCD2Map((CGameType *)g_pGameType)
          || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pMissionCD2 + 4))(g_pMissionCD2));
      v53 = v44;
      if ( !v44 )
      {
        v35 = (CLanLobbyMapSettings::SMapEntry *)CStateLobbyMapSettings::m_stempMapPtr[*v52];
        v39 = v35;
        if ( v35 )
          v34 = CLanLobbyMapSettings::SMapEntry::`scalar deleting destructor'(v39, 1u);
        else
          v34 = 0;
        CStateLobbyMapSettings::m_stempMapPtr[*v52] = 0;
        goto LABEL_41;
      }
      if ( byte_4031914 )
      {
        if ( *(_BYTE *)(g_pGameType + 860) )
          goto LABEL_29;
      }
      else if ( *(_BYTE *)(g_pGameType + 861) )
      {
LABEL_29:
        *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 60) = *(_DWORD *)(g_pGameType + 56);
        *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 64) = *(_DWORD *)(g_pGameType + 852);
        *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 56) = *(_DWORD *)(g_pGameType + 852);
        std::wstring::operator=((int)v57);
        *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 68) = *(_DWORD *)(g_pGameType + 864);
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 78) = *(_BYTE *)(g_pGameType + 860);
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 72) = *(_BYTE *)(g_pGameType + 871);
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 74) = *(_BYTE *)(g_pGameType + 868);
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 75) = *(_BYTE *)(g_pGameType + 869);
        if ( byte_4031914 )
          v43 = 0;
        else
          v43 = *(unsigned __int8 *)(g_pGameType + 870);
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 73) = v43;
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 76) = *(_BYTE *)(g_pGameType + 872);
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 77) = 0;
        *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 84) = 0;
        *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 92) = *(_DWORD *)(g_pGameType + 64);
        v42 = !*(_BYTE *)(g_pGameType + 876) || !*(_BYTE *)(g_pGameType + 875);
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 79) = v42;
        v41 = *(_BYTE *)(g_pGameType + 875) == 0;
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 80) = v41;
        v40 = *(_BYTE *)(g_pGameType + 874) == 0;
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 81) = v40;
        *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[*v52] + 88) = *(_DWORD *)(g_pGameType + 880);
        std::string::operator=(g_pGameType + 756);
        j__wcscpy(String, FindData.name);
        j__wcsupr(String);
        v37 = (_WORD *)wcsstr(String, MAP_FILE_EXTENSION);
        j__wcscpy(String, FindData.name);
        *v37 = 0;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v55);
        LOBYTE(v59) = 3;
        v36 = (void *)std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v56,
                        String);
        std::string::operator=((void *)CStateLobbyMapSettings::m_stempMapPtr[*v52], v36);
        std::string::~string(v56);
        ++*v52;
        LOBYTE(v59) = 2;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v55);
      }
LABEL_41:
      LOBYTE(v59) = 1;
      std::wstring::~wstring(v57);
    }
    while ( j___wfindnext64i32(FindHandle, &FindData) != -1 );
  }
  if ( FindHandle != -1 )
    j___findclose(FindHandle);
  LOBYTE(v59) = 0;
  std::wstring::~wstring(&a2);
  v59 = -1;
  std::wstring::~wstring(&a9);
}


// address=[0x14bf100]
// Decompiled from int __thiscall CStateLobbyMapSettings::RefreshMapList(CStateLobbyMapSettings *this)
int  CStateLobbyMapSettings::RefreshMapList(void) {
  
  int v2; // [esp-38h] [ebp-F4h] BYREF
  int v3; // [esp-34h] [ebp-F0h]
  int v4; // [esp-30h] [ebp-ECh]
  int v5; // [esp-2Ch] [ebp-E8h]
  int v6; // [esp-28h] [ebp-E4h]
  int v7; // [esp-24h] [ebp-E0h]
  int v8; // [esp-20h] [ebp-DCh]
  char v9; // [esp-1Ch] [ebp-D8h] BYREF
  int v10; // [esp-18h] [ebp-D4h]
  int v11; // [esp-14h] [ebp-D0h]
  int v12; // [esp-10h] [ebp-CCh]
  int v13; // [esp-Ch] [ebp-C8h]
  int v14; // [esp-8h] [ebp-C4h]
  int v15; // [esp-4h] [ebp-C0h]
  int v16; // [esp+4h] [ebp-B8h]
  int *v17; // [esp+8h] [ebp-B4h]
  int v18; // [esp+Ch] [ebp-B0h]
  void *v19; // [esp+10h] [ebp-ACh]
  int v20; // [esp+14h] [ebp-A8h]
  int *v21; // [esp+18h] [ebp-A4h]
  int v22; // [esp+1Ch] [ebp-A0h]
  void *v23; // [esp+20h] [ebp-9Ch]
  int v24; // [esp+24h] [ebp-98h]
  int v25; // [esp+28h] [ebp-94h]
  int MapFilePatternOfDirectory; // [esp+2Ch] [ebp-90h]
  int MapDirectoryPath; // [esp+30h] [ebp-8Ch]
  int v28; // [esp+34h] [ebp-88h]
  CStateLobbyMapSettings *v29; // [esp+38h] [ebp-84h]
  _BYTE v30[28]; // [esp+3Ch] [ebp-80h] BYREF
  _BYTE v31[28]; // [esp+58h] [ebp-64h] BYREF
  _BYTE v32[28]; // [esp+74h] [ebp-48h] BYREF
  _BYTE v33[28]; // [esp+90h] [ebp-2Ch] BYREF
  int v34; // [esp+B8h] [ebp-4h]

  v29 = this;
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
  IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
  CStateLobbyMapSettings::ClearMapList(v29);
  dword_4031918 = 0;
  MapFilePaths::GetMapDirectoryPath(v32, dword_403191C);
  v34 = 0;
  MapFilePaths::GetMapFilePatternOfDirectory(v33, dword_403191C);
  LOBYTE(v34) = 1;
  v23 = &v9;
  v28 = std::wstring::wstring((int)v33);
  v22 = v28;
  LOBYTE(v34) = 2;
  v21 = &v2;
  v20 = std::wstring::wstring((int)v32);
  LOBYTE(v34) = 1;
  CStateLobbyMapSettings::AddMapList(v29, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( dword_403191C == 2 )
  {
    MapDirectoryPath = MapFilePaths::GetMapDirectoryPath(v31, 3);
    std::wstring::operator=(MapDirectoryPath);
    std::wstring::~wstring(v31);
    MapFilePatternOfDirectory = MapFilePaths::GetMapFilePatternOfDirectory(v30, dword_403191C + 1);
    std::wstring::operator=(MapFilePatternOfDirectory);
    std::wstring::~wstring(v30);
    v19 = &v9;
    v25 = std::wstring::wstring((int)v33);
    v18 = v25;
    LOBYTE(v34) = 3;
    v17 = &v2;
    v16 = std::wstring::wstring((int)v32);
    LOBYTE(v34) = 1;
    CStateLobbyMapSettings::AddMapList(v29, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);
  }
  dword_4031920 = (int)CStateLobbyMapSettings::m_stempMapPtr;
  CStateLobbyMapSettings::Sort(v29);
  if ( dword_4031918 )
    dword_403192C = 0;
  else
    dword_403192C = -1;
  CStateLobbyMapSettings::ApplyMapData(v29, dword_403192C);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 1);
  v24 = dword_4031918;
  LOBYTE(v34) = 0;
  std::wstring::~wstring(v33);
  v34 = -1;
  std::wstring::~wstring(v32);
  return v24;
}


// address=[0x14bf350]
// Decompiled from void __thiscall CStateLobbyMapSettings::ClearMapList(CStateLobbyMapSettings *this)
void  CStateLobbyMapSettings::ClearMapList(void) {
  
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 1000; ++i )
  {
    if ( CStateLobbyMapSettings::m_stempMapPtr[i] )
    {
      CLanLobbyMapSettings::SMapEntry::`scalar deleting destructor'(
        (CLanLobbyMapSettings::SMapEntry *)CStateLobbyMapSettings::m_stempMapPtr[i],
        1u);
      CStateLobbyMapSettings::m_stempMapPtr[i] = 0;
    }
  }
  dword_4031920 = 0;
  dword_4031918 = 0;
}


// address=[0x14bf3e0]
// Decompiled from int __thiscall CStateLobbyMapSettings::SetupGUI(CStateLobbyMapSettings *this)
void  CStateLobbyMapSettings::SetupGUI(void) {
  
  int result; // eax

  if ( *((_BYTE *)this + 4) )
    *((_DWORD *)this + 4) = 3;
  else
    *((_DWORD *)this + 4) = 18;
  dword_4031998 = *((_DWORD *)this + 4);
  LOBYTE(result) = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 4), GuiDlgMainMapSettingsProc);
  if ( (_BYTE)result )
    return result;
  result = BBSupportDbgReport(2, "main\\states\\StateLobbyMapSettings.cpp", 813, "bRet");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x14bf470]
// Decompiled from void __thiscall CStateLobbyMapSettings::UpdateData(CStateLobbyMapSettings *this)
void  CStateLobbyMapSettings::UpdateData(void) {
  
  CStateLobbyMapSettings::Sort(this);
  GuiDlgMapSettingsUpdate();
}


// address=[0x14bf490]
// Decompiled from void __thiscall CStateLobbyMapSettings::ApplyMapData(CStateLobbyMapSettings *this, int a2)
void  CStateLobbyMapSettings::ApplyMapData(int) {
  
  int v2; // ecx
  char v3; // [esp-40h] [ebp-A0h] BYREF
  int v4; // [esp-3Ch] [ebp-9Ch]
  int v5; // [esp-38h] [ebp-98h]
  int v6; // [esp-34h] [ebp-94h]
  int v7; // [esp-30h] [ebp-90h]
  int v8; // [esp-2Ch] [ebp-8Ch]
  int v9; // [esp-28h] [ebp-88h]
  int v10; // [esp-24h] [ebp-84h]
  int v11; // [esp-20h] [ebp-80h]
  int v12; // [esp-1Ch] [ebp-7Ch]
  int v13; // [esp-18h] [ebp-78h]
  int v14; // [esp-14h] [ebp-74h]
  int v15; // [esp-10h] [ebp-70h]
  int v16; // [esp-Ch] [ebp-6Ch]
  int v17; // [esp-8h] [ebp-68h]
  int v18; // [esp-4h] [ebp-64h]
  int v19; // [esp+0h] [ebp-60h]
  char *v20; // [esp+4h] [ebp-5Ch]
  int v21; // [esp+8h] [ebp-58h]
  void *v22; // [esp+Ch] [ebp-54h]
  unsigned int v23[2]; // [esp+10h] [ebp-50h] BYREF
  BOOL v24; // [esp+18h] [ebp-48h]
  BOOL v25; // [esp+1Ch] [ebp-44h]
  BOOL v26; // [esp+20h] [ebp-40h]
  unsigned __int16 *v27; // [esp+24h] [ebp-3Ch] BYREF
  CStateLobbyMapSettings *v28; // [esp+28h] [ebp-38h]
  bool v29; // [esp+2Fh] [ebp-31h]
  _BYTE v30[16]; // [esp+30h] [ebp-30h] BYREF
  _BYTE v31[28]; // [esp+40h] [ebp-20h] BYREF

  v28 = this;
  if ( a2 == -1 )
  {
    byte_403195A = 0;
    byte_4031959 = 0;
    byte_403195B = 0;
    byte_403195C = 0;
    dword_4031924 = 0;
    dword_4031928 = 0;
    dword_4031930 = 0;
    dword_4031938 = 0;
    v22 = std::string::string(v31, (char *)&byte_374A50B);
    std::string::operator=(&unk_403193C, v22);
    std::string::~string(v31);
    dword_4031934 = 0;
    byte_403199C = 0;
    byte_403199D = 0;
    CStateLobbyMapSettings::UpdateData(v28);
  }
  else
  {
    if ( CStateLobbyMapSettings::m_stempMapPtr[a2] )
    {
      v26 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 79) == 0;
      byte_403195A = v26;
      v25 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 81) == 0;
      byte_4031959 = v25;
      v24 = *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 80) == 0;
      byte_403195B = v24;
      v18 = 0;
      v17 = 0;
      v16 = -1;
      v15 = -1;
      v14 = dword_4031938;
      v13 = 0;
      v12 = 1;
      v11 = 0;
      v10 = 1;
      v2 = CStateLobbyMapSettings::m_stempMapPtr[a2] + 28;
      v20 = &v3;
      v19 = std::wstring::wstring(v2);
      CGameType::LoadMapData(v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18);
      if ( CGameType::IsAddOnMap((CGameType *)g_pGameType) )
      {
        IGuiEngine::EnableControl((IGuiEngine *)g_pGUIEngine, dword_4031998, 2508, 1);
        IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, dword_4031998, 2508, 1);
        IGuiEngine::EnableControl((IGuiEngine *)g_pGUIEngine, dword_4031998, 2508, 0);
      }
      else if ( CGameType::IsEmptyMap((CGameType *)g_pGameType) )
      {
        IGuiEngine::EnableControl((IGuiEngine *)g_pGUIEngine, dword_4031998, 2508, 1);
      }
      else
      {
        IGuiEngine::EnableControl((IGuiEngine *)g_pGUIEngine, dword_4031998, 2508, 1);
        IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, dword_4031998, 2508, 0);
        IGuiEngine::EnableControl((IGuiEngine *)g_pGUIEngine, dword_4031998, 2508, 0);
      }
      dword_4031924 = *(_DWORD *)(g_pGameType + 852);
      dword_4031928 = *(_DWORD *)(g_pGameType + 72);
      v29 = *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 88) != 1;
      byte_403195C = v29;
      dword_4031930 = *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 92);
      dword_4031934 = *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 68);
      std::string::operator=(g_pGameType + 756);
      if ( byte_4031914 )
        *(_BYTE *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 73) = 0;
      v21 = *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 72)
          + *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 73)
          + *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 74)
          + *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 75);
      v23[1] = v21 > 1;
      byte_4031958 = v21 > 1;
      if ( g_pGameType )
      {
        IGuiEngine::EraseOwnerImage((IGuiEngine *)g_pGUIEngine, *((_DWORD *)v28 + 4), 2495);
        if ( *(_DWORD *)(g_pGameType + 1016) )
        {
          v27 = 0;
          v23[0] = 0;
          IGuiEngine::LockOwnerImage(
            (IGuiEngine *)g_pGUIEngine,
            *((_DWORD *)v28 + 4),
            2495,
            (struct SGuiRect *)v30,
            &v27,
            v23);
          if ( v27 )
          {
            CStateLobbyGameSettings::DrawMap(
              *(unsigned __int16 **)(g_pGameType + 1016),
              v27,
              v23[0],
              *(_DWORD *)(g_pGameType + 1020),
              *(_DWORD *)(g_pGameType + 1024));
            IGuiEngine::UnlockOwnerImage((IGuiEngine *)g_pGUIEngine, *((_DWORD *)v28 + 4), 2495);
          }
        }
      }
    }
    CStateLobbyMapSettings::UpdateData(v28);
  }
}


// address=[0x14bf8c0]
// Decompiled from void __thiscall CStateLobbyMapSettings::Sort(CStateLobbyMapSettings *this)
void  CStateLobbyMapSettings::Sort(void) {
  
  int v1; // [esp+0h] [ebp-14h]
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]

  for ( i = 0; i < dword_4031918 - 1; ++i )
  {
    for ( j = 0; j < dword_4031918 - 1; ++j )
    {
      if ( (int)CStateLobbyMapSettings::Compare(this, j, j + 1) < 0 )
      {
        v1 = dword_403093C[j];
        dword_403093C[j] = CStateLobbyMapSettings::m_stempMapPtr[j];
        CStateLobbyMapSettings::m_stempMapPtr[j] = v1;
      }
    }
  }
}


// address=[0x14bf970]
// Decompiled from int __thiscall CStateLobbyMapSettings::Compare(CStateLobbyMapSettings *this, int a2, int a3)
int  CStateLobbyMapSettings::Compare(int,int) {
  
  const char *v3; // eax
  int result; // eax
  const char *v5; // [esp-4h] [ebp-44h]
  int v6; // [esp+0h] [ebp-40h]
  int v7; // [esp+4h] [ebp-3Ch]
  int v8; // [esp+8h] [ebp-38h]
  int v9; // [esp+Ch] [ebp-34h]
  int v10; // [esp+10h] [ebp-30h]
  int v11; // [esp+14h] [ebp-2Ch]
  int v12; // [esp+18h] [ebp-28h]
  int v13; // [esp+1Ch] [ebp-24h]
  int v14; // [esp+20h] [ebp-20h]
  int v15; // [esp+24h] [ebp-1Ch]
  int v16; // [esp+28h] [ebp-18h]
  int v17; // [esp+30h] [ebp-10h]
  int v18; // [esp+34h] [ebp-Ch]
  int v19; // [esp+38h] [ebp-8h]

  v19 = *((_DWORD *)this + 2);
  v17 = 0;
  while ( 2 )
  {
    switch ( v19 )
    {
      case 0:
        v5 = (const char *)std::string::c_str((void *)CStateLobbyMapSettings::m_stempMapPtr[a3]);
        v3 = (const char *)std::string::c_str((void *)CStateLobbyMapSettings::m_stempMapPtr[a2]);
        v18 = j___stricmp(v3, v5);
        if ( !v18 )
          goto CStateLobbyMapSettings__Compare___def_18BF9AD;
        if ( *((_BYTE *)this + 12) )
          v16 = -1;
        else
          v16 = 0;
        result = v16 ^ v18;
        break;
      case 1:
        if ( *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 60) == *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a3]
                                                                                      + 60) )
          goto CStateLobbyMapSettings__Compare___def_18BF9AD;
        if ( *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 60) <= *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a3]
                                                                                      + 60) )
          v15 = -1;
        else
          v15 = 1;
        if ( *((_BYTE *)this + 12) )
          v14 = -1;
        else
          v14 = 0;
        result = v14 ^ v15;
        break;
      case 2:
        if ( *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 56) == *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a3]
                                                                                      + 56) )
          goto CStateLobbyMapSettings__Compare___def_18BF9AD;
        if ( *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 56) <= *(_DWORD *)(CStateLobbyMapSettings::m_stempMapPtr[a3]
                                                                                      + 56) )
          v13 = -1;
        else
          v13 = 1;
        if ( *((_BYTE *)this + 12) )
          v12 = -1;
        else
          v12 = 0;
        result = v12 ^ v13;
        break;
      case 3:
        if ( *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 72) == *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a3] + 72) )
          goto CStateLobbyMapSettings__Compare___def_18BF9AD;
        if ( *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 72) >= (int)*(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a3] + 72) )
          v11 = -1;
        else
          v11 = 1;
        if ( *((_BYTE *)this + 12) )
          v10 = -1;
        else
          v10 = 0;
        result = v10 ^ v11;
        break;
      case 4:
        if ( byte_4031914 )
        {
          if ( *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 75) == *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a3] + 75) )
            goto CStateLobbyMapSettings__Compare___def_18BF9AD;
          if ( *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 75) >= (int)*(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a3] + 75) )
            v9 = -1;
          else
            v9 = 1;
          if ( *((_BYTE *)this + 12) )
            v8 = -1;
          else
            v8 = 0;
          result = v8 ^ v9;
        }
        else
        {
          if ( *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 73) == *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a3] + 73) )
            goto CStateLobbyMapSettings__Compare___def_18BF9AD;
          if ( *(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a2] + 73) >= (int)*(unsigned __int8 *)(CStateLobbyMapSettings::m_stempMapPtr[a3] + 73) )
            v7 = -1;
          else
            v7 = 1;
          if ( *((_BYTE *)this + 12) )
            v6 = -1;
          else
            v6 = 0;
          result = v6 ^ v7;
        }
        break;
      default:
CStateLobbyMapSettings__Compare___def_18BF9AD:
        if ( ++v19 == 6 )
          v19 = 0;
        if ( ++v17 != 6 )
          continue;
        result = 0;
        break;
    }
    return result;
  }
}


// address=[0x4030938]
// [Decompilation failed for static struct CLanLobbyMapSettings::SMapEntry * * CStateLobbyMapSettings::m_stempMapPtr]

