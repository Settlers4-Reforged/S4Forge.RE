#include "CStateLobbyConnect.h"

// Definitions for class CStateLobbyConnect

// address=[0x14b6970]
// Decompiled from struct CGameState *__cdecl CStateLobbyConnect::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateLobbyConnect::DynamicCreateFunc(void * a1) {
  
  if ( operator new(0xB48u) )
  {
    return (struct CGameState *)CStateLobbyConnect::CStateLobbyConnect((int)a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14b69f0]
// Decompiled from CStateLobbyConnect *__thiscall CStateLobbyConnect::CStateLobbyConnect(CStateLobbyConnect *this, int a2)
 CStateLobbyConnect::CStateLobbyConnect(void * a2) {
  
  OnlineManager *Instance; // eax
  OnlineManager *v3; // eax
  void *v5; // [esp+8h] [ebp-258h]
  char *Source; // [esp+1Ch] [ebp-244h]
  int v7; // [esp+20h] [ebp-240h]
  CGameType *v8; // [esp+24h] [ebp-23Ch]
  CGameType *C; // [esp+28h] [ebp-238h]
  _BYTE v11[28]; // [esp+34h] [ebp-22Ch] BYREF
  wchar_t Dest[256]; // [esp+50h] [ebp-210h] BYREF
  int v13; // [esp+25Ch] [ebp-4h]

  CGuiGameState::CGuiGameState(this);
  v13 = 0;
  *(_DWORD *)this = &CStateLobbyConnect::_vftable_;
  _vec_ctor((char *)this + 4, 0x8Cu, 0x14u, CLanLobbyConnect::SGameEntry::SGameEntry, CLanLobbyConnect::SGameEntry::~SGameEntry);
  LOBYTE(v13) = 1;
  *((_BYTE *)this + 2884) = 0;
  Instance = (OnlineManager *)OnlineManager::GetInstance();
  OnlineManager::SetQuickMatchFlow(Instance, 0);
  v3 = (OnlineManager *)OnlineManager::GetInstance();
  OnlineManager::SetInviteFlow(v3, 0);
  if ( g_pNetworkEngine )
  {
    (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
    g_pNetworkEngine = 0;
  }
  byte_4030758 = 0;
  CStateLobbyConnect::m_uiSearchIP = 0;
  if ( !g_pGameType )
  {
    C = (CGameType *)operator new(0x620u);
    LOBYTE(v13) = 2;
    if ( C )
    {
      v8 = CGameType::CGameType(C);
    }
    else
    {
      v8 = 0;
    }
    LOBYTE(v13) = 1;
    g_pGameType = (int)v8;
  }
  g_cLobbyConnectInfo = 11;
  dword_4030714 = 0;
  dword_403071C = (int)this + 2804;
  v5 = std::string::string(v11, (char *)&byte_3743BDB);
  std::string::operator=(&stru_403073C, v5);
  std::string::~string(v11);
  v7 = UPlay::UPlayManager::GetInstance();
  Source = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 16))(v7);
  if ( Source )
  {
    j__mbstowcs(Dest, Source, 0x100u);
    Dest[31] = 0;
  }
  std::wstring::operator=(&g_swPlayerName, Dest);
  CGuiGameState::OpenDialog(this, 2, (bool (__cdecl *)(int, int, int))GuiDlgLanLobbyConnectMenuProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14b6ca0]
// Decompiled from void __thiscall CStateLobbyConnect::~CStateLobbyConnect(CStateLobbyConnect *this)
 CStateLobbyConnect::~CStateLobbyConnect(void) {
  
  *(_DWORD *)this = &CStateLobbyConnect::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 2) && BBSupportDbgReport(2, "main\\states\\StateLobbyConnect.cpp", 142, "bRet") == 1 )
  {
    __debugbreak();
  }
  `eh vector destructor iterator'((char *)this + 4, 0x8Cu, 0x14u, CLanLobbyConnect::SGameEntry::~SGameEntry);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14b6d40]
// Decompiled from char __thiscall CStateLobbyConnect::Perform(CStateLobbyConnect *this)
bool  CStateLobbyConnect::Perform(void) {
  
  OnlineManager *Instance; // eax
  OnlineManager *v2; // eax
  char *v3; // eax
  DWORD v5; // esi
  int v6; // eax
  DWORD v7; // esi
  void *v8; // [esp+8h] [ebp-44h]
  int v9; // [esp+28h] [ebp-24h]
  INetworkEngine *v10; // [esp+2Ch] [ebp-20h]
  INetworkEngine *C; // [esp+30h] [ebp-1Ch]

  Instance = (OnlineManager *)OnlineManager::GetInstance();
  if ( OnlineManager::IsNATReady(Instance) && !*((_BYTE *)this + 2884) )
  {
    *((_BYTE *)this + 2884) = 1;
    IGuiEngine::EnableControl((IGuiEngine *)g_pGUIEngine, 2, 2276, 1);
    IGuiEngine::EnableControl((IGuiEngine *)g_pGUIEngine, 2, 2311, 1);
  }
  v2 = (OnlineManager *)OnlineManager::GetInstance();
  if ( OnlineManager::GetAndClearOnlineError(v2) )
  {
    v3 = g_pStringEngine->GetString(g_pStringEngine, 2503);
    CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, (int)v3);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    if ( g_pNetworkEngine )
    {
      (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
    }
    g_pNetworkEngine = 0;
    return 1;
  }
  if ( dword_4030778 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_4030778);
    if ( dword_4030778 == -1 )
    {
      dword_4030774 = timeGetTime();
      j___Init_thread_footer(&dword_4030778);
    }
  }
  if ( dword_4030780 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_4030780);
    if ( dword_4030780 == -1 )
    {
      dword_403077C = timeGetTime() - 6000;
      j___Init_thread_footer(&dword_4030780);
    }
  }
  v5 = dword_403077C + 3000;
  if ( v5 < timeGetTime() )
  {
    dword_403077C = timeGetTime();
    if ( !g_pNetworkEngine )
    {
      C = (INetworkEngine *)operator new(0x18u);
      v10 = C ? INetworkEngine::INetworkEngine(C, 1) : 0;
      g_pNetworkEngine = (int)v10;
      if ( !(unsigned __int8)INetworkEngine::Start(0, 0, 0, 0) )
      {
        if ( g_pNetworkEngine )
        {
          (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
        }
        g_pNetworkEngine = 0;
        byte_4030758 = 1;
        CTrace::Print("GameHost: Unrecoverable network error while starting network for Game Search!");
        CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2402);
        CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
        return 1;
      }
    }
    v9 = UPlay::UPlayManager::GetInstance();
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 36))(v9) )
    {
      v6 = UPlay::UPlayManager::GetInstance();
      v8 = (void *)(*(unsigned int (__thiscall **)(int))(*(_DWORD *)v6 + 40))(v6);
      CLanLobby::Communicate(1060, v8);
      return 1;
    }
    CLanLobby::Communicate(1046, (void *)CStateLobbyConnect::m_uiSearchIP);
  }
  v7 = dword_4030774 + 30;
  if ( v7 < timeGetTime() )
  {
    dword_4030774 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  }
  if ( g_pNetworkEngine )
  {
    INetworkEngine::CheckForMsg((INetworkEngine *)g_pNetworkEngine);
  }
  return 1;
}


// address=[0x14b70b0]
// Decompiled from char __thiscall CStateLobbyConnect::OnEvent(std::wstring *this, struct CEvn_Event *a2)
bool  CStateLobbyConnect::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  OnlineManager *Instance; // eax
  char *v4; // eax
  std::wstring v5; // [esp-40h] [ebp-158h] BYREF
  BOOL v6; // [esp-24h] [ebp-13Ch]
  int v7; // [esp-20h] [ebp-138h]
  std::wstring v8; // [esp-1Ch] [ebp-134h] BYREF
  std::wstring *v9; // [esp+4h] [ebp-114h]
  std::wstring *v10; // [esp+8h] [ebp-110h]
  void *v11; // [esp+Ch] [ebp-10Ch]
  void *v12; // [esp+10h] [ebp-108h]
  std::wstring *v13; // [esp+14h] [ebp-104h]
  void *v14; // [esp+18h] [ebp-100h]
  std::wstring *v15; // [esp+1Ch] [ebp-FCh]
  void *v16; // [esp+20h] [ebp-F8h]
  struct CEvn_Event *v17; // [esp+24h] [ebp-F4h]
  struct CEvn_Event *v18; // [esp+30h] [ebp-E8h]
  int v19; // [esp+38h] [ebp-E0h]
  INetworkEngine *v20; // [esp+3Ch] [ebp-DCh]
  void *v21; // [esp+40h] [ebp-D8h]
  CGameType *v22; // [esp+44h] [ebp-D4h]
  CGameType *v23; // [esp+48h] [ebp-D0h]
  void *v24; // [esp+4Ch] [ebp-CCh]
  CGameType *v25; // [esp+50h] [ebp-C8h]
  INetworkEngine *v26; // [esp+54h] [ebp-C4h]
  int v27; // [esp+58h] [ebp-C0h]
  INetworkEngine *v28; // [esp+5Ch] [ebp-BCh]
  void *v29; // [esp+60h] [ebp-B8h]
  CGameType *v30; // [esp+64h] [ebp-B4h]
  void *v31; // [esp+68h] [ebp-B0h]
  CGameType *v32; // [esp+6Ch] [ebp-ACh]
  int v33; // [esp+70h] [ebp-A8h]
  INetworkEngine *v34; // [esp+74h] [ebp-A4h]
  struct CEvn_Event *v35; // [esp+78h] [ebp-A0h]
  CGameType *v36; // [esp+80h] [ebp-98h]
  CGameType *v37; // [esp+84h] [ebp-94h]
  void *v38; // [esp+88h] [ebp-90h]
  CGameType *v39; // [esp+8Ch] [ebp-8Ch]
  INetworkEngine *v40; // [esp+90h] [ebp-88h]
  void *C; // [esp+94h] [ebp-84h]
  CGameType *v42; // [esp+98h] [ebp-80h]
  INetworkEngine *v43; // [esp+A0h] [ebp-78h]
  INetworkEngine *v44; // [esp+A4h] [ebp-74h]
  char v45; // [esp+AFh] [ebp-69h]
  int v46; // [esp+B0h] [ebp-68h]
  std::wstring *v48; // [esp+B8h] [ebp-60h]
  char v49; // [esp+BFh] [ebp-59h]
  CEvn_Event v50; // [esp+C0h] [ebp-58h] BYREF
  CEvn_Event v51; // [esp+D8h] [ebp-40h] BYREF
  CEvn_Event v52; // [esp+F0h] [ebp-28h] BYREF
  int v53; // [esp+114h] [ebp-4h]

  v48 = this;
  v46 = a2->m_iEventId - 13;
  switch ( v46 )
  {
    case 0:
      if ( a2->m_wParam == 27 )
      {
        if ( byte_4030758 )
        {
          v17 = CEvn_Event::CEvn_Event(&v51, 0x72u, 0, 0, 0);
          v53 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v17);
          v53 = -1;
          CEvn_Event::~CEvn_Event(&v51);
        }
        else
        {
          v35 = CEvn_Event::CEvn_Event(&v50, 0x3Au, 0, 0, 0);
          v53 = 1;
          IEventEngine::SendAMessage(g_pEvnEngine, v35);
          v53 = -1;
          CEvn_Event::~CEvn_Event(&v50);
        }
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 45:
      CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
      if ( g_pNetworkEngine )
      {
        v34 = g_pNetworkEngine;
        v33 = (**(int (__thiscall ***)(INetworkEngine *, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
        g_pNetworkEngine = 0;
      }
      if ( g_pGameType )
      {
        v32 = g_pGameType;
        v31 = delete g_pGameType;
        g_pGameType = 0;
      }
      result = 1;
      break;
    case 47:
      v10 = &v8;
      v16 = std::wstring::wstring(&v8, &g_swPlayerName);
      CGameSettings::SetPlayerName(v8);
      if ( g_pNetworkEngine || ((C = operator new(0x18u), v53 = 2, !C) ? (v40 = 0) : (v40 = INetworkEngine::INetworkEngine((INetworkEngine *)C, 1)), v26 = v40, v53 = -1, g_pNetworkEngine = v40, (unsigned __int8)INetworkEngine::Start(0, 0, 0, 0)) )
      {
        v8.m_u[6] = 0;
        v8.m_u[5] = 0;
        v8.m_u[4] = -1;
        v8.m_u[3] = -1;
        v8.m_u[2] = 0;
        v8.m_u[1] = 1;
        v8.m_u[0] = 1;
        v7 = v48[5 * g_iLanLobbyNr + 3].m_u[5];
        v6 = 0;
        v9 = &v5;
        v14 = std::wstring::wstring(&v5, &v48[5 * g_iLanLobbyNr + 2].m_u[1]);
        if ( !CGameType::LoadMapData(g_pGameType, v5, v6, v7, v8.m_u[0], v8.m_u[1], v8.m_u[2], v8.m_u[3], v8.m_u[4], v8.m_u[5], v8.m_u[6]) )
        {
          v25 = g_pGameType;
          v39 = g_pGameType;
          if ( g_pGameType )
          {
            v24 = delete v39;
          }
          else
          {
            v24 = 0;
          }
          v38 = operator new(0x620u);
          v53 = 3;
          if ( v38 )
          {
            v37 = CGameType::CGameType((CGameType *)v38);
          }
          else
          {
            v37 = 0;
          }
          v23 = v37;
          v53 = -1;
          g_pGameType = v37;
          std::wstring::operator=(&v37->m_swMapName, (std::wstring *)&v48[5 * g_iLanLobbyNr + 2].m_u[1]);
          g_pGameType->m_bAIActive = 0;
        }
        std::wstring::operator=(&g_pGameType->m_swGameName, (std::wstring *)&v48[5 * g_iLanLobbyNr].m_u[1]);
        g_pGameType->m_iGameType = 2;
        g_pGameType->m_iCampaignType = 0;
        g_pGameType->m_iActualPlayerCount = v48[5 * g_iLanLobbyNr + 3].m_u[2];
        g_pGameType->m_bIsSaveGame = v48[5 * g_iLanLobbyNr + 3].m_u[6];
        g_pGameType->bIsAutosave = BYTE1(v48[5 * g_iLanLobbyNr + 3].m_u[6]);
        g_pGameType->m_uiTickCounter = v48[5 * g_iLanLobbyNr + 5].m_u[0];
        if ( g_pGameType->m_bIsSaveGame )
        {
          std::wstring::operator=(&g_pGameType->m_swSaveFile, &v48[5 * g_iLanLobbyNr + 4]);
          if ( g_pGameType->bIsAutosave )
          {
            std::wstring::operator+=(&g_pGameType->m_swSaveFile, (wchar_t *)L"_autoSave");
          }
          std::wstring::operator+=(&g_pGameType->m_swSaveFile, (wchar_t *)L".sav");
        }
        CLanLobby::Communicate(1024, (void *)g_iLanLobbyNr);
        result = 1;
      }
      else
      {
        byte_4030758 = 1;
        v4 = g_pStringEngine->GetString(g_pStringEngine, 2402);
        std::string::operator=(&g_iMessageBoxStringID, v4);
        v49 = IGuiEngine::CloseDialog(g_pGUIEngine, 2);
        v49 = IGuiEngine::OpenDialog(g_pGUIEngine, 20, (bool (__cdecl *)(int, int, int))GuiDlgMainMessageBoxProc);
        if ( !v49 && BBSupportDbgReport(2, "main\\states\\StateLobbyConnect.cpp", 349, "bRet") == 1 )
        {
          __debugbreak();
        }
        CTrace::Print("GameHost: Unrecoverable network error while starting network for Game Join!");
        result = 1;
      }
      break;
    case 48:
      if ( g_pGameType )
      {
        v22 = g_pGameType;
        v36 = g_pGameType;
        v21 = delete g_pGameType;
        g_pGameType = 0;
      }
      v13 = &v8;
      v12 = std::wstring::wstring(&v8, &g_swPlayerName);
      CGameSettings::SetPlayerName(v8);
      if ( g_pNetworkEngine )
      {
        v20 = g_pNetworkEngine;
        v43 = g_pNetworkEngine;
        v19 = (**(int (__thiscall ***)(INetworkEngine *, int))v43)(v43, 1);
        g_pNetworkEngine = 0;
      }
      dword_403191C = 1;
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLobbyMapSettings::DynamicCreateFunc, (void *)1);
      result = 1;
      break;
    case 49:
      if ( g_pGameType )
      {
        v30 = g_pGameType;
        v42 = g_pGameType;
        v29 = delete g_pGameType;
        g_pGameType = 0;
      }
      v15 = &v8;
      v11 = std::wstring::wstring(&v8, &g_swPlayerName);
      CGameSettings::SetPlayerName(v8);
      if ( g_pNetworkEngine )
      {
        v28 = g_pNetworkEngine;
        v44 = g_pNetworkEngine;
        v27 = (**(int (__thiscall ***)(INetworkEngine *, int))v44)(v44, 1);
        g_pNetworkEngine = 0;
      }
      v8.m_u[6] = 1;
      Instance = (OnlineManager *)OnlineManager::GetInstance();
      OnlineManager::SetQuickMatchFlow(Instance, v8.m_u[6]);
      dword_403191C = 1;
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLobbyMapSettings::DynamicCreateFunc, (void *)1);
      result = 1;
      break;
    case 101:
      byte_4030758 = 0;
      v45 = IGuiEngine::CloseDialog(g_pGUIEngine, 20);
      CGuiGameState::OpenDialog((CGuiGameState *)v48, 2, (bool (__cdecl *)(int, int, int))GuiDlgLanLobbyConnectMenuProc);
      v18 = CEvn_Event::CEvn_Event(&v52, 0x3Au, 0, 0, 0);
      v53 = 4;
      IEventEngine::SendAMessage(g_pEvnEngine, v18);
      v53 = -1;
      CEvn_Event::~CEvn_Event(&v52);
      result = 1;
      break;
    default:
      result = CGuiGameState::OnEvent((CGuiGameState *)v48, a2);
      break;
  }
  return result;
}


// address=[0x40306d8]
// [Decompilation failed for static unsigned int CStateLobbyConnect::m_uiSearchIP]

