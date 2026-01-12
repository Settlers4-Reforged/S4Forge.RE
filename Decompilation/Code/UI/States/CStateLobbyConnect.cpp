#include "CStateLobbyConnect.h"

// Definitions for class CStateLobbyConnect

// address=[0x14b6970]
// Decompiled from int __cdecl sub_18B6970(int a1)
static class CGameState * __cdecl CStateLobbyConnect::DynamicCreateFunc(void *) {
  
  if ( operator new(0xB48u) )
    return CStateLobbyConnect::CStateLobbyConnect(a1);
  else
    return 0;
}


// address=[0x14b69f0]
// Decompiled from CStateLobbyConnect *__thiscall CStateLobbyConnect::CStateLobbyConnect(CStateLobbyConnect *this, int a2)
 CStateLobbyConnect::CStateLobbyConnect(void *) {
  
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
  `eh vector constructor iterator'(
    (char *)this + 4,
    0x8Cu,
    0x14u,
    CLanLobbyConnect::SGameEntry::SGameEntry,
    CLanLobbyConnect::SGameEntry::~SGameEntry);
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
      v8 = CGameType::CGameType(C);
    else
      v8 = 0;
    LOBYTE(v13) = 1;
    g_pGameType = (int)v8;
  }
  g_cLobbyConnectInfo = 11;
  dword_4030714 = 0;
  dword_403071C = (int)this + 2804;
  v5 = std::string::string(v11, (char *)&byte_3743BDB);
  std::string::operator=(&unk_403073C, v5);
  std::string::~string(v11);
  v7 = UPlay::UPlayManager::GetInstance();
  Source = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 16))(v7);
  if ( Source )
  {
    j__mbstowcs(Dest, Source, 0x100u);
    Dest[31] = 0;
  }
  std::wstring::operator=(&unk_4030720, Dest);
  CGuiGameState::OpenDialog(this, 2, (bool (__cdecl *)(int, int, int))GuiDlgLanLobbyConnectMenuProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14b6ca0]
// Decompiled from void __thiscall CStateLobbyConnect::~CStateLobbyConnect(CStateLobbyConnect *this)
 CStateLobbyConnect::~CStateLobbyConnect(void) {
  
  *(_DWORD *)this = &CStateLobbyConnect::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 2)
    && BBSupportDbgReport(2, "main\\states\\StateLobbyConnect.cpp", 142, "bRet") == 1 )
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
      (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
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
          (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
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
    INetworkEngine::CheckForMsg((INetworkEngine *)g_pNetworkEngine);
  return 1;
}


// address=[0x14b70b0]
// Decompiled from char __thiscall CStateLobbyConnect::OnEvent(CStateLobbyConnect *this, struct CEvn_Event *a2)
bool  CStateLobbyConnect::OnEvent(class CEvn_Event &) {
  
  char result; // al
  OnlineManager *Instance; // eax
  char *v4; // eax
  char v5; // [esp-40h] [ebp-158h] BYREF
  int v6; // [esp-3Ch] [ebp-154h]
  int v7; // [esp-38h] [ebp-150h]
  int v8; // [esp-34h] [ebp-14Ch]
  int v9; // [esp-30h] [ebp-148h]
  int v10; // [esp-2Ch] [ebp-144h]
  int v11; // [esp-28h] [ebp-140h]
  int v12; // [esp-24h] [ebp-13Ch]
  int v13; // [esp-20h] [ebp-138h]
  int v14; // [esp-1Ch] [ebp-134h] BYREF
  int v15; // [esp-18h] [ebp-130h]
  int v16; // [esp-14h] [ebp-12Ch]
  int v17; // [esp-10h] [ebp-128h]
  int v18; // [esp-Ch] [ebp-124h]
  int v19; // [esp-8h] [ebp-120h]
  int v20; // [esp-4h] [ebp-11Ch]
  char *v21; // [esp+4h] [ebp-114h]
  int *v22; // [esp+8h] [ebp-110h]
  int v23; // [esp+Ch] [ebp-10Ch]
  int v24; // [esp+10h] [ebp-108h]
  int *v25; // [esp+14h] [ebp-104h]
  int v26; // [esp+18h] [ebp-100h]
  int *v27; // [esp+1Ch] [ebp-FCh]
  int v28; // [esp+20h] [ebp-F8h]
  CEvn_Event *v29; // [esp+24h] [ebp-F4h]
  CEvn_Event *v30; // [esp+30h] [ebp-E8h]
  int v31; // [esp+38h] [ebp-E0h]
  int v32; // [esp+3Ch] [ebp-DCh]
  void *v33; // [esp+40h] [ebp-D8h]
  int v34; // [esp+44h] [ebp-D4h]
  CGameType *v35; // [esp+48h] [ebp-D0h]
  void *v36; // [esp+4Ch] [ebp-CCh]
  int v37; // [esp+50h] [ebp-C8h]
  INetworkEngine *v38; // [esp+54h] [ebp-C4h]
  int v39; // [esp+58h] [ebp-C0h]
  int v40; // [esp+5Ch] [ebp-BCh]
  void *v41; // [esp+60h] [ebp-B8h]
  int v42; // [esp+64h] [ebp-B4h]
  void *v43; // [esp+68h] [ebp-B0h]
  int v44; // [esp+6Ch] [ebp-ACh]
  int v45; // [esp+70h] [ebp-A8h]
  int v46; // [esp+74h] [ebp-A4h]
  CEvn_Event *v47; // [esp+78h] [ebp-A0h]
  int v48; // [esp+80h] [ebp-98h]
  CGameType *v49; // [esp+84h] [ebp-94h]
  void *v50; // [esp+88h] [ebp-90h]
  CGameType *v51; // [esp+8Ch] [ebp-8Ch]
  INetworkEngine *v52; // [esp+90h] [ebp-88h]
  void *C; // [esp+94h] [ebp-84h]
  int v54; // [esp+98h] [ebp-80h]
  int (__thiscall ***v55)(_DWORD, int); // [esp+A0h] [ebp-78h]
  int (__thiscall ***v56)(_DWORD, int); // [esp+A4h] [ebp-74h]
  bool v57; // [esp+AFh] [ebp-69h]
  int v58; // [esp+B0h] [ebp-68h]
  CGuiGameState *v60; // [esp+B8h] [ebp-60h]
  char v61; // [esp+BFh] [ebp-59h]
  CEvn_Event v62; // [esp+C0h] [ebp-58h] BYREF
  CEvn_Event v63; // [esp+D8h] [ebp-40h] BYREF
  CEvn_Event v64; // [esp+F0h] [ebp-28h] BYREF
  int v65; // [esp+114h] [ebp-4h]

  v60 = this;
  v58 = a2->event - 13;
  switch ( v58 )
  {
    case 0:
      if ( a2->wparam == 27 )
      {
        if ( byte_4030758 )
        {
          v29 = CEvn_Event::CEvn_Event(&v63, 0x72u, 0, 0, 0);
          v65 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v29);
          v65 = -1;
          CEvn_Event::~CEvn_Event(&v63);
        }
        else
        {
          v47 = CEvn_Event::CEvn_Event(&v62, 0x3Au, 0, 0, 0);
          v65 = 1;
          IEventEngine::SendAMessage(g_pEvnEngine, v47);
          v65 = -1;
          CEvn_Event::~CEvn_Event(&v62);
        }
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 45:
      CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
      if ( g_pNetworkEngine )
      {
        v46 = g_pNetworkEngine;
        v45 = (**(int (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
        g_pNetworkEngine = 0;
      }
      if ( g_pGameType )
      {
        v44 = g_pGameType;
        v43 = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
        g_pGameType = 0;
      }
      result = 1;
      break;
    case 47:
      v22 = &v14;
      v28 = std::wstring::wstring((int)&unk_4030720);
      CGameSettings::SetPlayerName(v14, v15);
      if ( g_pNetworkEngine
        || ((C = operator new(0x18u), v65 = 2, !C)
          ? (v52 = 0)
          : (v52 = INetworkEngine::INetworkEngine((INetworkEngine *)C, 1)),
            v38 = v52,
            v65 = -1,
            g_pNetworkEngine = (int)v52,
            (unsigned __int8)INetworkEngine::Start(0, 0, 0, 0)) )
      {
        v20 = 0;
        v19 = 0;
        v18 = -1;
        v17 = -1;
        v16 = 0;
        v15 = 1;
        v14 = 1;
        v13 = *((_DWORD *)v60 + 35 * dword_4030718 + 26);
        v12 = 0;
        v21 = &v5;
        v26 = std::wstring::wstring((int)v60 + 140 * dword_4030718 + 60);
        if ( !(unsigned __int8)CGameType::LoadMapData(
                                 v5,
                                 v6,
                                 v7,
                                 v8,
                                 v9,
                                 v10,
                                 v11,
                                 v12,
                                 v13,
                                 v14,
                                 v15,
                                 v16,
                                 v17,
                                 v18,
                                 v19,
                                 v20) )
        {
          v37 = g_pGameType;
          v51 = (CGameType *)g_pGameType;
          if ( g_pGameType )
            v36 = CGameType::`scalar deleting destructor'(v51, 1u);
          else
            v36 = 0;
          v50 = operator new(0x620u);
          v65 = 3;
          if ( v50 )
            v49 = CGameType::CGameType((CGameType *)v50);
          else
            v49 = 0;
          v35 = v49;
          v65 = -1;
          g_pGameType = (int)v49;
          std::wstring::operator=((int)v60 + 140 * dword_4030718 + 60);
          *(_BYTE *)(g_pGameType + 732) = 0;
        }
        std::wstring::operator=((int)v60 + 140 * dword_4030718 + 4);
        *(_DWORD *)(g_pGameType + 692) = 2;
        *(_DWORD *)(g_pGameType + 740) = 0;
        *(_DWORD *)(g_pGameType + 112) = *((_DWORD *)v60 + 35 * dword_4030718 + 23);
        *(_BYTE *)(g_pGameType + 696) = *((_BYTE *)v60 + 140 * dword_4030718 + 108);
        *(_BYTE *)(g_pGameType + 697) = *((_BYTE *)v60 + 140 * dword_4030718 + 109);
        *(_DWORD *)(g_pGameType + 700) = *((_DWORD *)v60 + 35 * dword_4030718 + 35);
        if ( *(_BYTE *)(g_pGameType + 696) )
        {
          std::wstring::operator=((int)v60 + 140 * dword_4030718 + 112);
          if ( *(_BYTE *)(g_pGameType + 697) )
            std::wstring::operator+=((void *)(g_pGameType + 704), (wchar_t *)L"_autoSave");
          std::wstring::operator+=((void *)(g_pGameType + 704), (wchar_t *)L".sav");
        }
        CLanLobby::Communicate(1024, (void *)dword_4030718);
        result = 1;
      }
      else
      {
        byte_4030758 = 1;
        v4 = g_pStringEngine->GetString(g_pStringEngine, 2402);
        std::string::operator=(&g_iMessageBoxStringID, v4);
        v61 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 2);
        v61 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
        if ( !v61 && BBSupportDbgReport(2, "main\\states\\StateLobbyConnect.cpp", 349, "bRet") == 1 )
          __debugbreak();
        CTrace::Print("GameHost: Unrecoverable network error while starting network for Game Join!");
        result = 1;
      }
      break;
    case 48:
      if ( g_pGameType )
      {
        v34 = g_pGameType;
        v48 = g_pGameType;
        v33 = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
        g_pGameType = 0;
      }
      v25 = &v14;
      v24 = std::wstring::wstring((int)&unk_4030720);
      CGameSettings::SetPlayerName(v14, v15);
      if ( g_pNetworkEngine )
      {
        v32 = g_pNetworkEngine;
        v55 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
        v31 = (**v55)(v55, 1);
        g_pNetworkEngine = 0;
      }
      dword_403191C = 1;
      CGameStateHandler::Switch((int)CStateLobbyMapSettings::DynamicCreateFunc, 1);
      result = 1;
      break;
    case 49:
      if ( g_pGameType )
      {
        v42 = g_pGameType;
        v54 = g_pGameType;
        v41 = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
        g_pGameType = 0;
      }
      v27 = &v14;
      v23 = std::wstring::wstring((int)&unk_4030720);
      CGameSettings::SetPlayerName(v14, v15);
      if ( g_pNetworkEngine )
      {
        v40 = g_pNetworkEngine;
        v56 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
        v39 = (**v56)(v56, 1);
        g_pNetworkEngine = 0;
      }
      v20 = 1;
      Instance = (OnlineManager *)OnlineManager::GetInstance();
      OnlineManager::SetQuickMatchFlow(Instance, v20);
      dword_403191C = 1;
      CGameStateHandler::Switch((int)CStateLobbyMapSettings::DynamicCreateFunc, 1);
      result = 1;
      break;
    case 101:
      byte_4030758 = 0;
      v57 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
      CGuiGameState::OpenDialog(v60, 2, (bool (__cdecl *)(int, int, int))GuiDlgLanLobbyConnectMenuProc);
      v30 = CEvn_Event::CEvn_Event(&v64, 0x3Au, 0, 0, 0);
      v65 = 4;
      IEventEngine::SendAMessage(g_pEvnEngine, v30);
      v65 = -1;
      CEvn_Event::~CEvn_Event(&v64);
      result = 1;
      break;
    default:
      result = CGuiGameState::OnEvent(v60, a2);
      break;
  }
  return result;
}


// address=[0x40306d8]
// [Decompilation failed for static unsigned int CStateLobbyConnect::m_uiSearchIP]

