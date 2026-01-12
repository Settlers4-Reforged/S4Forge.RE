#include "CGameStateHandler.h"

// Definitions for class CGameStateHandler

// address=[0x148ac10]
// Decompiled from char CGameStateHandler::Init()

static bool __cdecl CGameStateHandler::Init(void) {
  
  int v1; // [esp+4h] [ebp-128h]
  int v2; // [esp+Ch] [ebp-120h]
  int v3; // [esp+1Ch] [ebp-110h]
  void *v4; // [esp+20h] [ebp-10Ch]
  void *v5; // [esp+28h] [ebp-104h]
  CGameType *v6; // [esp+38h] [ebp-F4h]
  INetworkEngine *v7; // [esp+3Ch] [ebp-F0h]
  INetworkEngine *v8; // [esp+40h] [ebp-ECh]
  CGameType *C; // [esp+44h] [ebp-E8h]
  struct IEvn_Handle *v10; // [esp+48h] [ebp-E4h]
  _AFX_OLE_STATE *v11; // [esp+4Ch] [ebp-E0h]
  char v12; // [esp+54h] [ebp-D8h]
  _BYTE v13[28]; // [esp+58h] [ebp-D4h] BYREF
  _BYTE v14[28]; // [esp+74h] [ebp-B8h] BYREF
  _BYTE v15[28]; // [esp+90h] [ebp-9Ch] BYREF
  _BYTE v16[28]; // [esp+ACh] [ebp-80h] BYREF
  _BYTE v17[28]; // [esp+C8h] [ebp-64h] BYREF
  _BYTE nettestDefault[28]; // [esp+E4h] [ebp-48h] BYREF
  _BYTE v19[28]; // [esp+100h] [ebp-2Ch] BYREF
  int v20; // [esp+128h] [ebp-4h]

  std::list<SStateCommand>::clear(&CGameStateHandler::m_listQueuedStates);
  CGameStateHandler::m_bWantSwitch = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Main\\GameStateHandler.cpp", 487, "g_pEvnEngine") == 1 )
    __debugbreak();
  CGameStateHandler::InitStringEngine();
  std::string::string(nettestDefault, "none");
  v20 = 0;
  v2 = ((int (__thiscall *)(CConfigManager *, _BYTE *, const char *, const char *, _BYTE *))g_pCfgMgr->GetStringValue)(
         g_pCfgMgr,
         v16,
         "COMMANDLINE",
         "nettest",
         nettestDefault);
  LOBYTE(v20) = 1;
  std::operator==<char>(v2, "host");
  LOBYTE(v20) = 0;
  std::string::~string(v16);
  v20 = -1;
  std::string::~string(nettestDefault);
  std::string::string(v19, "none");
  v20 = 2;
  v1 = ((int (__thiscall *)(CConfigManager *, _BYTE *, const char *, const char *, _BYTE *))g_pCfgMgr->GetStringValue)(
         g_pCfgMgr,
         v13,
         "COMMANDLINE",
         "nettest",
         v19);
  LOBYTE(v20) = 3;
  std::operator==<char>(v1, "client");
  LOBYTE(v20) = 2;
  std::string::~string(v13);
  v20 = -1;
  std::string::~string(v19);
  ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
    g_pCfgMgr,
    "COMMANDLINE",
    "videoplay",
    0);
  g_pMissionCD = IExtraCD::CreateMissionCDObject();
  g_pAddOn = IExtraCD::CreateAddOnCDObject();
  g_pMissionCD2 = IExtraCD::CreateMissionCD2Object();
  g_pMissionCD3 = IExtraCD::CreateMissionCD3Object();
  if ( (unsigned __int8)CGameStateHandler::InitGfxEngine() )
  {
    CTrace::Print("INIT GFX-ENGINE COMPLETE");
    CGameSettings::DetermineHighestResolution();
    if ( (unsigned __int8)CGameStateHandler::InitSoundEngine() )
      CTrace::Print("INIT SOUND-ENGINE COMPLETE");
    else
      CTrace::Print("INIT SOUND-ENGINE FAILED");
    if ( (unsigned __int8)CGameStateHandler::InitGfxManager() )
    {
      CTrace::Print("INIT GFX-MANAGER COMPLETE");
      if ( (unsigned __int8)CGameStateHandler::InitGfxCompiler() )
      {
        CTrace::Print("INIT GFX-RTCompiler COMPLETE");
        if ( (unsigned __int8)CGameStateHandler::InitSoundManager() )
          CTrace::Print("INIT SOUND-MANAGER COMPLETE");
        else
          CTrace::Print("INIT SOUND-MANAGER FAILED");
        v11 = (_AFX_OLE_STATE *)operator new(4u);
        v20 = 4;
        if ( v11 )
          v10 = CGameStateEventHandle::CGameStateEventHandle(v11);
        else
          v10 = 0;
        v20 = -1;
        dword_3F45674 = (int)v10;
        IEventEngine::RegisterHandle(g_pEvnEngine, v10);
        CStateLoadGame::InitSaveList();
        if ( ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
               g_pCfgMgr,
               "COMMANDLINE",
               "netgame",
               0) )
        {
          CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 5);
          return 1;
        }
        else
        {
          v5 = std::string::string(v17, "normal");
          v20 = 5;
          v4 = std::string::string(v15, "normal");
          LOBYTE(v20) = 6;
          v3 = ((int (__thiscall *)(CConfigManager *, _BYTE *, const char *, const char *, void *))g_pCfgMgr->GetStringValue)(
                 g_pCfgMgr,
                 v14,
                 "COMMANDLINE",
                 "gamemode",
                 v4);
          v12 = std::operator==<char>(v3, v5);
          std::string::~string(v14);
          LOBYTE(v20) = 5;
          std::string::~string(v15);
          v20 = -1;
          std::string::~string(v17);
          if ( v12 )
          {
            CGameStateHandler::Switch((int)CStateSlideshow::DynamicCreateFunc, 0);
            if ( (unsigned __int8)CGameSettings::GetShowVideos() )
            {
              CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 7);
              CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 1);
              CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 0);
            }
            CGameStateHandler::Queue((int)CStateMainMenu::DynamicCreateFunc, 19);
            return 1;
          }
          else
          {
            C = (CGameType *)operator new(0x620u);
            v20 = 7;
            if ( C )
              v6 = CGameType::CGameType(C);
            else
              v6 = 0;
            v20 = -1;
            g_pGameType = (int)v6;
            if ( (unsigned __int8)CGameStateHandler::StartDummyGame() )
            {
              v7 = (INetworkEngine *)operator new(0x18u);
              v20 = 8;
              if ( v7 )
                v8 = INetworkEngine::INetworkEngine(v7, 0);
              else
                v8 = 0;
              v20 = -1;
              g_pNetworkEngine = (int)v8;
              INetworkEngine::Start(1, 1, *(_DWORD *)(g_pGameType + 112), 0);
              CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
              timeBeginPeriod(1u);
              CTrace::Print(" MAIN INIT COMPLETE (CGameStateHandler::Init) ");
              return 1;
            }
            else
            {
              return 0;
            }
          }
        }
      }
      else
      {
        CTrace::Print("INIT GFX-RTCompiler FAILED");
        return 0;
      }
    }
    else
    {
      CTrace::Print("INIT GFX-MANAGER FAILED");
      return 0;
    }
  }
  else
  {
    CTrace::Print("INIT GFX-ENGINE FAILED");
    return 0;
  }
}


// address=[0x148b240]
// Decompiled from char CGameStateHandler::Perform()

static bool __cdecl CGameStateHandler::Perform(void) {
  
  OnlineManager *v1; // eax
  StormManager *v2; // eax
  char v3; // [esp-1Ch] [ebp-88h] BYREF
  int v4; // [esp-18h] [ebp-84h]
  int v5; // [esp+0h] [ebp-6Ch]
  _DWORD v6[5]; // [esp+4h] [ebp-68h] BYREF
  struct tagPOINT Point; // [esp+18h] [ebp-54h] BYREF
  int v8; // [esp+20h] [ebp-4Ch]
  int v9; // [esp+24h] [ebp-48h]
  int v10; // [esp+28h] [ebp-44h]
  int v11; // [esp+2Ch] [ebp-40h]
  int v12; // [esp+30h] [ebp-3Ch]
  int Instance; // [esp+34h] [ebp-38h]
  int v14; // [esp+38h] [ebp-34h]
  int (__thiscall ***v15)(_DWORD, int); // [esp+3Ch] [ebp-30h]
  DWORD Time; // [esp+40h] [ebp-2Ch]
  CEvn_Event v17; // [esp+44h] [ebp-28h] BYREF
  int v18; // [esp+68h] [ebp-4h]

  if ( CGameStateHandler::m_bGrab )
  {
    v6[4] = &v3;
    v6[3] = std::wstring::wstring(&v3, (wchar_t *)&word_36EB218);
    CGrabber::DoGrab(v3, v4);
  }
  if ( CGameStateHandler::m_uiLastTime )
  {
    Time = timeGetTime();
    if ( Time - CGameStateHandler::m_uiLastTime >= 0x64 )
    {
      GetCursorPos(&Point);
      ScreenToClient(g_hWnd, &Point);
      CEvn_Event::CEvn_Event(&v17, 0x15u, 0, Point.x + (Point.y << 16), 0);
      v18 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, &v17);
      if ( Time - CGameStateHandler::m_uiLastTime - 100 >= 0xA )
        CGameStateHandler::m_uiLastTime = Time - 10;
      else
        CGameStateHandler::m_uiLastTime += 100;
      v18 = -1;
      CEvn_Event::~CEvn_Event(&v17);
    }
  }
  else
  {
    CGameStateHandler::m_uiLastTime = timeGetTime();
  }
  if ( CGameStateHandler::m_bWantSwitch )
  {
    CGameStateHandler::m_bWantSwitch = 0;
    IEventEngine::LockEventEngine(g_pEvnEngine, 1);
    if ( CGameStateHandler::m_s_pCurrentState )
    {
      v11 = CGameStateHandler::m_s_pCurrentState;
      v15 = (int (__thiscall ***)(_DWORD, int))CGameStateHandler::m_s_pCurrentState;
      v10 = (**v15)(v15, 1);
      CGameStateHandler::m_s_pCurrentState = 0;
    }
    if ( !std::list<SStateCommand>::size(&CGameStateHandler::m_listQueuedStates) )
      return 0;
    v9 = std::list<SStateCommand>::begin(v6);
    v8 = v9;
    v18 = 1;
    v14 = std::_List_iterator<std::_List_val<std::_List_simple_types<SStateCommand>>>::operator*(v9);
    v18 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SStateCommand>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SStateCommand>>>(v6);
    CGameStateHandler::m_s_pCurrentState = (*(int (__cdecl **)(_DWORD))v14)(*(_DWORD *)(v14 + 4));
    std::list<SStateCommand>::pop_front(v5, v6[0]);
    if ( !CGameStateHandler::m_s_pCurrentState )
      return 0;
    IEventEngine::LockEventEngine(g_pEvnEngine, 0);
  }
  if ( !IEventEngine::DispatchSystemMessages(g_pEvnEngine) )
    return 0;
  Instance = UPlay::UPlayManager::GetInstance();
  (*(void (__thiscall **)(int))(*(_DWORD *)Instance + 4))(Instance);
  v12 = UPlay::UPlayManager::GetInstance();
  if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v12 + 32))(v12) )
  {
    v1 = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::Update(v1);
    v2 = (StormManager *)StormManager::GetInstance();
    StormManager::Update(v2);
  }
  if ( CGameStateHandler::m_bQuitApplication )
    return 0;
  if ( g_pSoundEngine )
    ISoundEngine::Perform((ISoundEngine *)g_pSoundEngine);
  if ( !CGameStateHandler::m_s_pCurrentState )
    return 1;
  if ( g_pGfxEngine && g_pGUIEngine && IGfxEngine::IsGfxEngineRebuilded((IGfxEngine *)g_pGfxEngine) )
    IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
  return (*(int (__thiscall **)(int))(*(_DWORD *)CGameStateHandler::m_s_pCurrentState + 4))(CGameStateHandler::m_s_pCurrentState);
}


// address=[0x148b530]
// Decompiled from char CGameStateHandler::CanProcessInvites()

static bool __cdecl CGameStateHandler::CanProcessInvites(void) {
  
  if ( CGameStateHandler::m_s_pCurrentState )
    return (*(int (__thiscall **)(int))(*(_DWORD *)CGameStateHandler::m_s_pCurrentState + 12))(CGameStateHandler::m_s_pCurrentState);
  else
    return 0;
}


// address=[0x148b560]
// Decompiled from MMRESULT CGameStateHandler::Kill()

static void __cdecl CGameStateHandler::Kill(void) {
  
  CDestructionManager *v0; // eax
  _BYTE v2[28]; // [esp+74h] [ebp-48h] BYREF
  _BYTE v3[28]; // [esp+90h] [ebp-2Ch] BYREF
  int v4; // [esp+B8h] [ebp-4h]

  if ( g_pSoundEngine )
  {
    (**(void (__thiscall ***)(int, int))g_pSoundEngine)(g_pSoundEngine, 1);
    g_pSoundEngine = 0;
  }
  if ( g_pEvnEngine )
  {
    std::string::string(v3, (char *)&byte_36C362D);
    v4 = 0;
    IEventEngine::RecordEvents(g_pEvnEngine, v3);
    v4 = -1;
    std::string::~string(v3);
    std::string::string(v2, (char *)&byte_36C362E);
    v4 = 1;
    IEventEngine::PlayEvents(v2, 0);
    v4 = -1;
    std::string::~string(v2);
    IEventEngine::LockEventEngine(g_pEvnEngine, 1);
  }
  if ( dword_3F45674 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_3F45674 + 4))(dword_3F45674, 1);
    dword_3F45674 = 0;
  }
  if ( g_pNetworkEngine )
  {
    (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
    g_pNetworkEngine = 0;
  }
  if ( CGameStateHandler::m_s_pCurrentState )
  {
    (**(void (__thiscall ***)(int, int))CGameStateHandler::m_s_pCurrentState)(CGameStateHandler::m_s_pCurrentState, 1);
    CGameStateHandler::m_s_pCurrentState = 0;
  }
  if ( g_pGUIEngine )
  {
    IGuiEngine::`scalar deleting destructor'((IGuiEngine *)g_pGUIEngine, 1u);
    g_pGUIEngine = 0;
  }
  if ( g_pGfxEngine )
  {
    IGfxEngine::`scalar deleting destructor'((IGfxEngine *)g_pGfxEngine, 1u);
    g_pGfxEngine = 0;
  }
  if ( g_pGfxManager )
  {
    CGfxManager::`scalar deleting destructor'((CGfxManager *)g_pGfxManager, 1u);
    g_pGfxManager = 0;
  }
  if ( g_pSoundManager )
  {
    CSoundManager::`scalar deleting destructor'((CSoundManager *)g_pSoundManager, 1u);
    g_pSoundManager = 0;
  }
  if ( g_pStringEngine )
  {
    ((void (__thiscall *)(CStringEngineEx *, int))g_pStringEngine->j_??_GCStringEngineEx@@UAEPAXI@Z)(g_pStringEngine, 1);
    g_pStringEngine = 0;
  }
  v0 = (CDestructionManager *)CDestructionManager::Instance();
  CDestructionManager::DestroyObjects(v0);
  if ( g_pDialogData )
  {
    operator delete(g_pDialogData);
    g_pDialogData = 0;
  }
  CStateLoadGame::DestroySaveList();
  ExitWSAFunctions();
  return timeEndPeriod(1u);
}


// address=[0x148b900]
// Decompiled from char CGameStateHandler::InitGfxEngine()

static bool __cdecl CGameStateHandler::InitGfxEngine(void) {
  
  IGfxEngine *v1; // [esp+14h] [ebp-14h]
  IGfxEngine *C; // [esp+18h] [ebp-10h]

  if ( GetGfxInterfaceVersion() != 229 )
  {
    MessageBoxA(g_hWnd, "Wrong version of gfx engine!", "Error:", 0x30u);
    CTrace::Print("Wrong version of gfx engine!");
    return 1;
  }
  j__memset(&CGameStateHandler::m_sRenderCfg, 0, 0x24u);
  C = (IGfxEngine *)operator new(0x28u);
  if ( C )
    v1 = IGfxEngine::IGfxEngine(C);
  else
    v1 = 0;
  g_pGfxEngine = (int)v1;
  j___controlfp(0xA031Fu, (unsigned int)&loc_30F031E + 1);
  IGfxEngine::SetTriangleSize((IGfxEngine *)g_pGfxEngine, 1572864);
  IGfxEngine::SetCameraMode((IGfxEngine *)g_pGfxEngine, 1);
  IGfxEngine::SetScrollOffsets((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::EnableMiniMap((IGfxEngine *)g_pGfxEngine, 1, 15, 8, 0);
  if ( CGameStateHandler::BuildInitRenderCfg(0, 1) )
    return 1;
  if ( g_pGfxEngine )
    IGfxEngine::`scalar deleting destructor'((IGfxEngine *)g_pGfxEngine, 1u);
  g_pGfxEngine = 0;
  return 0;
}


// address=[0x148ba60]
// Decompiled from bool CGameStateHandler::InitSoundEngine()

static bool __cdecl CGameStateHandler::InitSoundEngine(void) {
  
  ISoundEngine *v1; // [esp+14h] [ebp-18h]
  ISoundEngine *C; // [esp+18h] [ebp-14h]

  if ( g_pSoundEngine && BBSupportDbgReport(2, "Main\\GameStateHandler.cpp", 1322, "g_pSoundEngine == NULL") == 1 )
    __debugbreak();
  if ( GetSoundInterfaceVersion() == 151 )
  {
    C = (ISoundEngine *)operator new(4u);
    if ( C )
      v1 = ISoundEngine::ISoundEngine(C);
    else
      v1 = 0;
    g_pSoundEngine = (int)v1;
    if ( v1 )
    {
      if ( ISoundEngine::Init((ISoundEngine *)g_pSoundEngine, word_36D5788, 22050, 1, 16, 28, 4) )
      {
        if ( ISoundEngine::VCStart((ISoundEngine *)g_pSoundEngine, g_pEvnEngine, 1) )
          CTrace::Print("INIT VOICE-CHAT COMPLETE");
        else
          CTrace::Print("INIT VOICE-CHAT FAILED");
        ISoundEngine::SetTimerInterval((ISoundEngine *)g_pSoundEngine, 71);
      }
      else
      {
        if ( g_pSoundEngine )
          (**(void (__thiscall ***)(int, int))g_pSoundEngine)(g_pSoundEngine, 1);
        g_pSoundEngine = 0;
      }
    }
  }
  else
  {
    MessageBoxA(g_hWnd, "Wrong version of sound engine!", "Error:", 0x30u);
    CTrace::Print("Wrong version of sound engine!");
  }
  return g_pSoundEngine != 0;
}


// address=[0x148bc10]
// Decompiled from char CGameStateHandler::InitGfxManager()

static bool __cdecl CGameStateHandler::InitGfxManager(void) {
  
  char v1; // al
  CGfxManager *v2; // [esp+14h] [ebp-1Ch]
  CGfxManager *C; // [esp+18h] [ebp-18h]
  int GfxMode; // [esp+1Ch] [ebp-14h]
  bool v5; // [esp+23h] [ebp-Dh]

  if ( !g_pGfxEngine && BBSupportDbgReport(2, "Main\\GameStateHandler.cpp", 1385, "g_pGfxEngine") == 1 )
    __debugbreak();
  GfxMode = IGfxEngine::GetGfxMode((IGfxEngine *)g_pGfxEngine);
  if ( GfxMode )
  {
    C = (CGfxManager *)operator new(0xCC0u);
    if ( C )
    {
      v5 = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pMissionCD2 + 4))(g_pMissionCD2)
        || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pMissionCD3 + 4))(g_pMissionCD3);
      v1 = (*(int (__thiscall **)(int))(*(_DWORD *)g_pAddOn + 4))(g_pAddOn);
      v2 = CGfxManager::CGfxManager(C, GfxMode == 2, v1, v5);
    }
    else
    {
      v2 = 0;
    }
    g_pGfxManager = (int)v2;
    if ( (unsigned __int8)CGfxManager::OpenGFXFiles(v2) )
    {
      if ( g_pGame )
      {
        CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF);
        CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 9u, 9, 1, 0xFFFFFFFF);
      }
      else
      {
        CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 0, 9, 1, 0xFFFFFFFF);
      }
      IGfxEngine::SetReloadCallback((IGfxEngine *)g_pGfxEngine, CGfxManager::Reload);
      IGfxEngine::SetOwnerIDCallback((IGfxEngine *)g_pGfxEngine, CWorldManager::WorldOwnerIdColor);
      return 1;
    }
    else
    {
      if ( g_pGfxManager )
        CGfxManager::`scalar deleting destructor'((CGfxManager *)g_pGfxManager, 1u);
      g_pGfxManager = 0;
      return 0;
    }
  }
  else
  {
    CTrace::Print("Error getting BIT MODE from Graphic Engine!");
    return 0;
  }
}


// address=[0x148be00]
// Decompiled from bool CGameStateHandler::InitSoundManager()

static bool __cdecl CGameStateHandler::InitSoundManager(void) {
  
  CSoundManager *v1; // [esp+8h] [ebp-14h]
  CSoundManager *C; // [esp+Ch] [ebp-10h]

  C = (CSoundManager *)operator new(0x1E4u);
  if ( C )
    v1 = CSoundManager::CSoundManager(C);
  else
    v1 = 0;
  g_pSoundManager = (int)v1;
  return CSoundManager::OpenSoundFiles(v1);
}


// address=[0x148bea0]
// Decompiled from char CGameStateHandler::InitConfigManager()

static bool __cdecl CGameStateHandler::InitConfigManager(void) {
  
  g_pCfgMgr = CConfigManagerPtr::GetInstance();
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36E65B0, 379);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36C6610, 291);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36F31A8, 96);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36C8268, 18);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36EEA90, 43);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36ECFB0, 86);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36F0A18, 434);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36D2128, 6);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &asWarningTypeStrings, 14);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36D3EB8, 109);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36E32A0, 66);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36D6370, 134);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36D8690, 3837);
  ((void (__thiscall *)(CConfigManager *, void *, int))g_pCfgMgr->AddDefines)(g_pCfgMgr, &unk_36D5DE0, 17);
  CGameStateHandler::LoadAllConfigFiles();
  ((void (__thiscall *)(CConfigManager *, const char *, int, int))g_pCfgMgr->AddCommandLine)(
    g_pCfgMgr,
    "COMMANDLINE",
    g_iArgc,
    g_pArgv);
  return 1;
}


// address=[0x148c0f0]
// Decompiled from char CGameStateHandler::InitStringEngine()

static bool __cdecl CGameStateHandler::InitStringEngine(void) {
  
  int v0; // eax

  v0 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
         g_pCfgMgr,
         "GAMESETTINGS",
         "Language",
         0);
  g_pStringEngine = (CStringEngineEx *)CStringEngine::CreateStringEngine(v0);
  return 1;
}


// address=[0x148c130]
// Decompiled from char CGameStateHandler::InitFileLibrary()

static bool __cdecl CGameStateHandler::InitFileLibrary(void) {
  
  return 1;
}


// address=[0x148c140]
// Decompiled from char CGameStateHandler::InitGfxCompiler()

static bool __cdecl CGameStateHandler::InitGfxCompiler(void) {
  
  j___controlfp(0xA031Fu, (unsigned int)&loc_30F031E + 1);
  if ( GetLibVersion() == _crt_argv_unexpanded_arguments )
  {
    g_pRTComp = GetLibInstance();
    if ( g_pRTComp )
    {
      return 1;
    }
    else
    {
      BBSupportTracePrintF(3, "RTComp: Could not get instance!");
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "RTComp: Wrong Version! ");
    return 0;
  }
}


// address=[0x148c1b0]
// Decompiled from void CGameStateHandler::DietmarsGameSettingsDefaults()

static void __cdecl CGameStateHandler::DietmarsGameSettingsDefaults(void) {
  
  int v0; // [esp+0h] [ebp-Ch]
  int v1; // [esp+4h] [ebp-8h]
  int v2; // [esp+8h] [ebp-4h]

  if ( g_pCfgMgr )
  {
    v2 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "GAMESETTINGS", "Fullscreen");
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 32))(v2, 0);
    v1 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "GAMESETTINGS", "MusicEnabled");
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 32))(v1, 0);
    v0 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "ADVGAMESETTINGS", "ShowVideos");
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v0 + 32))(v0, 0);
  }
}


// address=[0x148c260]
// Decompiled from void CGameStateHandler::LoadAllConfigFiles()

static void __cdecl CGameStateHandler::LoadAllConfigFiles(void) {
  
  _DWORD *v0; // eax
  _BYTE v1[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v2; // [esp+30h] [ebp-4h]

  if ( (BBSupportDevelopmentMachineId() & 1) != 0 )
    CGameStateHandler::DietmarsGameSettingsDefaults();
  CGameStateHandler::LoadConfigFile(L"AINames", 0);
  CGameStateHandler::LoadConfigFile(L"Animals", 0);
  CGameStateHandler::LoadConfigFile(L"Balancing", 0);
  CGameStateHandler::LoadConfigFile(L"Magic", 0);
  CGameStateHandler::LoadConfigFile(L"MainConfig", 0);
  CGameStateHandler::LoadConfigFile(L"Network", 0);
  CGameStateHandler::LoadConfigFile(L"SoundFX", 0);
  CGameStateHandler::LoadConfigFile(L"Soundtracks", 0);
  CGameStateHandler::LoadConfigFile(L"Transport", 0);
  CGameStateHandler::LoadConfigFile(L"WarningTypes", 0);
  CGameStateHandler::LoadConfigFile(L"Web", 0);
  CGameStateHandler::LoadConfigFile(L"GameSettings", "GAMESETTINGS");
  CGameStateHandler::LoadConfigFile(L"MiscData2", "MISCDATA2");
  CGameStateHandler::LoadConfigFile(L"Video", "ADVGAMESETTINGS");
  std::wstring::wstring(v1);
  v2 = 0;
  if ( (*(unsigned __int8 (__thiscall **)(void *, _BYTE *, const wchar_t *, int))(*(_DWORD *)g_pCDDrive + 8))(
         g_pCDDrive,
         v1,
         L"Config\\MiscData1.cfg",
         1048578) )
  {
    v0 = std::wstring::c_str((_Cnd_internal_imp_t *)v1);
    ((void (__thiscall *)(CConfigManager *, _DWORD *, const char *))g_pCfgMgr->j_?AddConfigFileEx@CConfigManager@@UAE_NPB_WPBD@Z)(
      g_pCfgMgr,
      v0,
      "MISCDATA1");
  }
  v2 = -1;
  std::wstring::~wstring(v1);
}


// address=[0x148c400]
// Decompiled from char __cdecl CGameStateHandler::RebuildGfxEngine(char a1)

static bool __cdecl CGameStateHandler::RebuildGfxEngine(bool) {
  
  int v2; // esi
  int *v3; // eax
  _BYTE v4[36]; // [esp+Ch] [ebp-8Ch] BYREF
  _BYTE v5[16]; // [esp+30h] [ebp-68h] BYREF
  int v6; // [esp+40h] [ebp-58h]
  int v7; // [esp+44h] [ebp-54h]
  BOOL v8; // [esp+48h] [ebp-50h]
  char v10; // [esp+4Fh] [ebp-49h]
  _BYTE v11[24]; // [esp+50h] [ebp-48h] BYREF
  _DWORD v12[4]; // [esp+68h] [ebp-30h] BYREF
  int v13; // [esp+78h] [ebp-20h]
  int v14; // [esp+7Ch] [ebp-1Ch]
  int v15; // [esp+80h] [ebp-18h]
  int v16; // [esp+84h] [ebp-14h]
  int v17; // [esp+94h] [ebp-4h]

  v8 = g_pGame == 0;
  v10 = g_pGame == 0;
  qmemcpy(v4, &CGameStateHandler::m_sRenderCfg, sizeof(v4));
  if ( (unsigned __int8)CGameStateHandler::BuildInitRenderCfg(1, v8) )
  {
    v2 = (unsigned __int8)SGfxRenderConfiguration::IsHardwareObjectEngine(v4);
    if ( v2 != (unsigned __int8)SGfxRenderConfiguration::IsHardwareObjectEngine(&CGameStateHandler::m_sRenderCfg) )
    {
      CGfxManager::DisableGfxFile(-1);
      CGfxManager::OpenGFXFiles(g_pGfxManager);
    }
    if ( a1 )
      sub_148DA20(v10);
    if ( !g_pGUIEngine )
      return 1;
    IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
    v3 = (int *)sub_148D860(v5);
    v13 = *v3;
    v14 = v3[1];
    v15 = v3[2];
    v16 = v3[3];
    v12[0] = v13;
    v12[1] = v14;
    v12[2] = v15;
    v12[3] = v16;
    v7 = CEvn_Event::CEvn_Event(626, v12, 0, 0);
    v6 = v7;
    v17 = 0;
    IEventEngine::SendAMessage(v7);
    v17 = -1;
    CEvn_Event::~CEvn_Event(v11);
    return 1;
  }
  else
  {
    CTrace::Print("GameStateHandler: Error rebuilding Gfx Engine!");
    return 0;
  }
}


// address=[0x148c590]
// Decompiled from // public: static bool __cdecl CGameStateHandler::CheckGfxRenderQuality(unsigned int)
char __cdecl CGameStateHandler::CheckGfxRenderQuality(int a1)

static bool __cdecl CGameStateHandler::CheckGfxRenderQuality(unsigned int) {
  
  int v2[9]; // [esp-24h] [ebp-50h] BYREF
  _DWORD v3[9]; // [esp+8h] [ebp-24h] BYREF

  qmemcpy(v3, &CGameStateHandler::m_sRenderCfg, sizeof(v3));
  v3[1] = a1;
  qmemcpy(v2, v3, sizeof(v2));
  return IGfxEngine::CheckRenderConfiguration(
           (_BYTE *)g_pGfxEngine,
           v2[0],
           v2[1],
           v2[2],
           v2[3],
           v2[4],
           v2[5],
           v2[6],
           v2[7],
           v2[8]);
}


// address=[0x148c5d0]
// Decompiled from // public: static bool __cdecl CGameStateHandler::CheckGfxHardwareMode(unsigned int)
char __cdecl CGameStateHandler::CheckGfxHardwareMode(int a1)

static bool __cdecl CGameStateHandler::CheckGfxHardwareMode(unsigned int) {
  
  int v2[9]; // [esp-24h] [ebp-54h] BYREF
  _BYTE v3[40]; // [esp+8h] [ebp-28h] BYREF

  qmemcpy(v3, &CGameStateHandler::m_sRenderCfg, 0x24u);
  v3[39] = a1 != 0;
  v3[0] = a1 != 0;
  qmemcpy(v2, v3, sizeof(v2));
  return IGfxEngine::CheckRenderConfiguration(
           (_BYTE *)g_pGfxEngine,
           v2[0],
           v2[1],
           v2[2],
           v2[3],
           v2[4],
           v2[5],
           v2[6],
           v2[7],
           v2[8]);
}


// address=[0x148c620]
// Decompiled from char __cdecl CGameStateHandler::ShowHTMLPage(char a1, int a2, int a3, int a4, int a5, int a6, int a7, char a8)

static bool __cdecl CGameStateHandler::ShowHTMLPage(std::string,std::string) {
  
  const CHAR *v8; // eax
  const char *v9; // eax
  const CHAR *v10; // eax
  const char *v11; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  int v16; // [esp-10h] [ebp-6Ch]
  const CHAR *v17; // [esp-Ch] [ebp-68h]
  const char *v18; // [esp-Ch] [ebp-68h]
  int v19; // [esp-8h] [ebp-64h]
  int v20; // [esp-8h] [ebp-64h]
  HINSTANCE v21; // [esp+Ch] [ebp-50h]
  _BYTE v22[28]; // [esp+14h] [ebp-48h] BYREF
  _BYTE v23[28]; // [esp+30h] [ebp-2Ch] BYREF
  int v24; // [esp+58h] [ebp-4h]

  v24 = 1;
  std::string::string(v23, (char *)&byte_36C362F);
  LOBYTE(v24) = 2;
  std::string::operator+=((int)&a1);
  std::string::c_str(&a8);
  if ( std::string::length(&a8) )
  {
    v17 = (const CHAR *)std::string::c_str(&a8);
    v8 = (const CHAR *)std::string::c_str(v23);
    v21 = ShellExecuteA(g_hWnd, "open", v8, v17, 0, 5);
    v19 = std::string::length(&a8);
    v18 = (const char *)std::string::c_str(&a8);
    v16 = std::string::length(v23);
    v9 = (const char *)std::string::c_str(v23);
    BBSupportTracePrintF(1, "ShowHtml: <%s, %u>, <%s, %u> : Shellexecute returned %u!", v9, v16, v18, v19, v21);
  }
  else
  {
    v10 = (const CHAR *)std::string::c_str(v23);
    v21 = ShellExecuteA(g_hWnd, "open", v10, 0, 0, 5);
    v20 = std::string::length(v23);
    v11 = (const char *)std::string::c_str(v23);
    BBSupportTracePrintF(1, "ShowHtml: <%s, %u> : Shellexecute returned %u!", v11, v20, v21);
  }
  if ( (int)v21 > 32 )
  {
    LOBYTE(v24) = 1;
    std::string::~string(v23);
    LOBYTE(v24) = 0;
    std::string::~string(&a1);
    v24 = -1;
    std::string::~string(&a8);
    return 1;
  }
  std::string::string();
  LOBYTE(v24) = 3;
  if ( (int)v21 < 2 )
    goto LABEL_11;
  if ( (int)v21 <= 3 )
  {
    std::string::operator=(v22, "File not found!");
    v14 = g_pStringEngine->GetString(g_pStringEngine, 2392);
    std::string::operator=(&g_iMessageBoxStringID, v14);
    goto LABEL_12;
  }
  if ( v21 != (HINSTANCE)31 )
  {
LABEL_11:
    std::string::operator=(v22, "No Memory!");
    v15 = g_pStringEngine->GetString(g_pStringEngine, 2390);
    std::string::operator=(&g_iMessageBoxStringID, v15);
    goto LABEL_12;
  }
  std::string::operator=(v22, "No assocation with given filetype!");
  v13 = g_pStringEngine->GetString(g_pStringEngine, 2386);
  std::string::operator=(&g_iMessageBoxStringID, v13);
LABEL_12:
  LOBYTE(v24) = 2;
  std::string::~string(v22);
  LOBYTE(v24) = 1;
  std::string::~string(v23);
  LOBYTE(v24) = 0;
  std::string::~string(&a1);
  v24 = -1;
  std::string::~string(&a8);
  return 0;
}


// address=[0x148c880]
// Decompiled from int CGameStateHandler::SetCorrectWindowSize()

static void __cdecl CGameStateHandler::SetCorrectWindowSize(void) {
  
  int v0; // eax
  unsigned __int64 v2; // [esp+0h] [ebp-48h] BYREF
  __int64 v3; // [esp+8h] [ebp-40h] BYREF
  int v4; // [esp+10h] [ebp-38h]
  int v5; // [esp+14h] [ebp-34h]
  unsigned __int64 v6; // [esp+18h] [ebp-30h]
  __int64 v7; // [esp+20h] [ebp-28h]
  int X; // [esp+28h] [ebp-20h]
  int Y; // [esp+2Ch] [ebp-1Ch]
  int *v10; // [esp+30h] [ebp-18h]
  int v11; // [esp+34h] [ebp-14h]
  int cy; // [esp+38h] [ebp-10h]
  int *v13; // [esp+3Ch] [ebp-Ch]
  UINT uFlags; // [esp+40h] [ebp-8h]
  MACRO_WS dwNewLong; // [esp+44h] [ebp-4h]

  if ( CGameSettings::GetGfxFullscreenEnabled(v2, HIDWORD(v2), v3, HIDWORD(v3)) )
  {
    v7 = sub_148D980();
    v3 = v7;
    v13 = (int *)&v3;
  }
  else
  {
    v6 = sub_148D9F0();
    v2 = v6;
    v13 = (int *)&v2;
  }
  v10 = v13;
  v0 = v13[1];
  v4 = *v13;
  v5 = v0;
  v11 = v4;
  cy = v0;
  uFlags = 0;
  dwNewLong = GetWindowLongA(g_hWnd, -16);
  X = 0;
  Y = 0;
  if ( CGameSettings::GetGfxFullscreenEnabled(v2, HIDWORD(v2), v3, HIDWORD(v3)) )
  {
    dwNewLong &= 0xFF30FFFF;
    uFlags = WM_MDINEXT;
  }
  else
  {
    dwNewLong |= WS_OVERLAPPEDWINDOW;
    uFlags = WM_MDITILE;
  }
  SetWindowLongA(g_hWnd, -16, dwNewLong);
  SetWindowPos(g_hWnd, 0, X, Y, v11, cy, uFlags);
  return CTrace::Print("GameStateHandler.cpp: New window size. Width %d, Height %d!", v11, cy);
}


// address=[0x148fef0]
// Decompiled from int __cdecl sub_188FEF0(int a1, int a2)

static void __cdecl CGameStateHandler::Queue(class CGameState * (__cdecl*)(void *),void *) {
  
  _DWORD v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[0] = a1;
  v3[1] = a2;
  return std::list<SStateCommand>::push_back(v3);
}


// address=[0x1490010]
// Decompiled from int __cdecl sub_1890010(int a1, int a2)

static void __cdecl CGameStateHandler::Switch(class CGameState * (__cdecl*)(void *),void *) {
  
  int result; // eax

  result = CGameStateHandler::Queue(a1, a2);
  CGameStateHandler::m_bWantSwitch = 1;
  return result;
}


// address=[0x14a1d40]
// Decompiled from void CGameStateHandler::Next()

static void __cdecl CGameStateHandler::Next(void) {
  
  CGameStateHandler::m_bWantSwitch = 1;
}


// address=[0x14aae20]
// Decompiled from char CGameStateHandler::IsGrabbing()

static bool __cdecl CGameStateHandler::IsGrabbing(void) {
  
  return CGameStateHandler::m_bGrab;
}


// address=[0x15c4a10]
// Decompiled from int CGameStateHandler::GetCurrentState()

static class CGameState * __cdecl CGameStateHandler::GetCurrentState(void) {
  
  return CGameStateHandler::m_s_pCurrentState;
}


// address=[0x148c9a0]
// Decompiled from void __cdecl CGameStateHandler::LoadConfigFile(wchar_t *String, const char *a2)

static void __cdecl CGameStateHandler::LoadConfigFile(wchar_t const *,char const *) {
  
  _DWORD *v2; // eax
  const char *v3; // eax
  _DWORD *v4; // eax
  int ConfigFilePath; // [esp+4h] [ebp-50h]
  int v6[7]; // [esp+Ch] [ebp-48h] BYREF
  int v7[7]; // [esp+28h] [ebp-2Ch] BYREF
  int v8; // [esp+50h] [ebp-4h]

  CGameSettings::GetConfigFilePath((int)v7, String, 0);
  v8 = 0;
  v2 = std::wstring::c_str((_Cnd_internal_imp_t *)v7);
  if ( !((unsigned __int8 (__thiscall *)(CConfigManager *, _DWORD *, const char *))g_pCfgMgr->j_?AddConfigFileEx@CConfigManager@@UAE_NPB_WPBD@Z)(
          g_pCfgMgr,
          v2,
          a2) )
  {
    v3 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v7);
    BBSupportTracePrintF(0, "Couldn't find '%s'", v3);
  }
  if ( (*(unsigned __int8 (__thiscall **)(void *, wchar_t *))(*(_DWORD *)g_pInstallationInfo + 20))(
         g_pInstallationInfo,
         String) )
  {
    ConfigFilePath = CGameSettings::GetConfigFilePath((int)v6, String, 1);
    std::wstring::operator=(ConfigFilePath);
    std::wstring::~wstring(v6);
    v4 = std::wstring::c_str((_Cnd_internal_imp_t *)v7);
    ((void (__thiscall *)(CConfigManager *, _DWORD *, const char *))g_pCfgMgr->j_?AddConfigFileEx@CConfigManager@@UAE_NPB_WPBD@Z)(
      g_pCfgMgr,
      v4,
      a2);
  }
  v8 = -1;
  std::wstring::~wstring(v7);
}


// address=[0x148cac0]
// Decompiled from char CGameStateHandler::StartDummyGame()

static bool __cdecl CGameStateHandler::StartDummyGame(void) {
  
  const CHAR *v0; // eax
  const CHAR *v2; // eax
  int v3; // [esp-4h] [ebp-B94h]
  int v4; // [esp+8h] [ebp-B88h] BYREF
  _BYTE v5[4]; // [esp+Ch] [ebp-B84h] BYREF
  _BYTE v6[4]; // [esp+10h] [ebp-B80h] BYREF
  int v7; // [esp+14h] [ebp-B7Ch] BYREF
  void *PlayerName; // [esp+18h] [ebp-B78h]
  int v9; // [esp+1Ch] [ebp-B74h]
  int v10; // [esp+20h] [ebp-B70h] BYREF
  int v11; // [esp+24h] [ebp-B6Ch]
  int v12; // [esp+28h] [ebp-B68h]
  BSTR bstrString; // [esp+2Ch] [ebp-B64h] BYREF
  int v14; // [esp+30h] [ebp-B60h]
  int v15; // [esp+34h] [ebp-B5Ch]
  int v16; // [esp+38h] [ebp-B58h]
  int v17; // [esp+3Ch] [ebp-B54h]
  char *v18; // [esp+40h] [ebp-B50h]
  HANDLE hFile; // [esp+44h] [ebp-B4Ch]
  char v20[4]; // [esp+48h] [ebp-B48h]
  int v21; // [esp+4Ch] [ebp-B44h] BYREF
  int v22; // [esp+50h] [ebp-B40h]
  BSTR String; // [esp+54h] [ebp-B3Ch] BYREF
  signed int v24; // [esp+58h] [ebp-B38h] BYREF
  char v25; // [esp+5Dh] [ebp-B33h]
  char v26; // [esp+5Eh] [ebp-B32h]
  char v27; // [esp+5Fh] [ebp-B31h]
  unsigned int i; // [esp+60h] [ebp-B30h]
  char v29[88]; // [esp+64h] [ebp-B2Ch] BYREF
  _BYTE v30[28]; // [esp+BCh] [ebp-AD4h] BYREF
  _BYTE v31[28]; // [esp+D8h] [ebp-AB8h] BYREF
  _BYTE v32[28]; // [esp+F4h] [ebp-A9Ch] BYREF
  _BYTE v33[28]; // [esp+110h] [ebp-A80h] BYREF
  _BYTE v34[28]; // [esp+12Ch] [ebp-A64h] BYREF
  _BYTE v35[28]; // [esp+148h] [ebp-A48h] BYREF
  _BYTE v36[28]; // [esp+164h] [ebp-A2Ch] BYREF
  WCHAR WideCharStr[1024]; // [esp+180h] [ebp-A10h] BYREF
  wchar_t Buffer[256]; // [esp+980h] [ebp-210h] BYREF
  int v39; // [esp+B8Ch] [ebp-4h]

  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v29);
  v39 = 0;
  std::string::string(v35, "NewMapTest.edm");
  LOBYTE(v39) = 1;
  ((void (__thiscall *)(CConfigManager *, _BYTE *, const char *, const char *, _BYTE *))g_pCfgMgr->GetStringValue)(
    g_pCfgMgr,
    v36,
    "COMMANDLINE",
    "map",
    v35);
  LOBYTE(v39) = 3;
  std::string::~string(v35);
  v9 = std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
         v30,
         v36);
  std::wstring::operator=(v9);
  std::wstring::~wstring(v30);
  v0 = (const CHAR *)std::string::c_str(v36);
  MultiByteToWideChar(0, 1u, v0, -1, WideCharStr, 1024);
  MA_OpenMapFile(WideCharStr, (int)&v7, (int)&v21, 0);
  if ( v21 )
  {
    CTrace::Print("GameStateHandler.cpp: Unable to open Map via Mapreader. Reported error %d", v21);
    MessageBoxA(g_hWnd, "Unable to open map file!", "S4", 0x30u);
    v25 = 0;
    LOBYTE(v39) = 0;
    std::string::~string(v36);
    v39 = -1;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v29);
    return v25;
  }
  else
  {
    MA_GetMapData(g_pGameType + 56, (int)v5, (int)v6, g_pGameType + 64, g_pGameType + 60);
    MA_GetNumberOfPlayers((int)&v24);
    *(_DWORD *)(g_pGameType + 852) = v24;
    v22 = 0;
    for ( i = 0; (int)i < v24; ++i )
    {
      MA_GetPlayerData(
        i + 1,
        0,
        (int *)(g_pGameType + 4 * i + 404),
        (int *)(g_pGameType + 4 * i + 260),
        (int *)(g_pGameType + 4 * i + 296),
        &String,
        &bstrString,
        &v10,
        &v4,
        (int *)(g_pGameType + 4 * i + 152));
      if ( *(_DWORD *)(g_pGameType + 4 * i + 404) == 255 )
        *(_DWORD *)(g_pGameType + 4 * i + 404) = 5;
      if ( *(_DWORD *)(g_pGameType + 4 * i + 152) > v22 )
        v22 = *(_DWORD *)(g_pGameType + 4 * i + 152);
      if ( v10 == 2 )
      {
        v11 = std::wstring::wstring(v31, String);
        v12 = v11;
        LOBYTE(v39) = 4;
        CGameType::SetPlayerName(i, v11);
        LOBYTE(v39) = 3;
        std::wstring::~wstring(v31);
      }
      *(_DWORD *)(g_pGameType + 4 * i + 116) = 1;
      *(_BYTE *)(i + g_pGameType + 440) = 0;
      SysFreeString(bstrString);
      SysFreeString(String);
    }
    *(_BYTE *)(g_pGameType + 732) = 1;
    *(_DWORD *)(g_pGameType + 68) = (char *)&dword_F29144[220110] + 3;
    *(_DWORD *)(g_pGameType + 736) = 0;
    *(_DWORD *)(g_pGameType + 72) = v22 + 1;
    *(_DWORD *)(g_pGameType + 864) = 1;
    *(_DWORD *)(g_pGameType + 692) = 1;
    CGameType::SetMCD2TextureSet((CGameType *)g_pGameType, 1);
    for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
      ++*(_DWORD *)(g_pGameType + 4 * *(_DWORD *)(g_pGameType + 4 * i + 152) + 76);
    *(_DWORD *)(g_pGameType + 112) = v24;
    if ( *(_DWORD *)(g_pGameType + 112) > (unsigned int)v24 )
    {
      MessageBoxA(g_hWnd, "Too many players given for map.\nPlayercount reduced!!", "S4", 0x30u);
      *(_DWORD *)(g_pGameType + 112) = v24;
    }
    for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
    {
      v14 = std::wstring::wstring(v33, (wchar_t *)&word_36D068C);
      v15 = v14;
      LOBYTE(v39) = 5;
      v3 = v14;
      PlayerName = CGameType::GetPlayerName((void *)g_pGameType, v32, i);
      v27 = std::operator==<wchar_t>(PlayerName, v3);
      std::wstring::~wstring(v32);
      LOBYTE(v39) = 3;
      std::wstring::~wstring(v33);
      if ( v27 )
        break;
      if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 1 )
        *(_DWORD *)v20 = "HUMAN";
      else
        *(_DWORD *)v20 = "AI";
      swprintf((char *)Buffer, "[%s] Player ID %d", v20[0]);
      v17 = std::wstring::wstring(v34, Buffer);
      v16 = v17;
      LOBYTE(v39) = 6;
      CGameType::SetPlayerName(i, v17);
      LOBYTE(v39) = 3;
      std::wstring::~wstring(v34);
    }
    for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
    {
      if ( i )
        v18 = 0;
      else
        v18 = (char *)&dword_F29144[220110] + 3;
      *(_DWORD *)(g_pGameType + 4 * i + 188) = v18;
    }
    for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
      *(_DWORD *)(g_pGameType + 4 * i + 332) = i;
    for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
      *(_DWORD *)(g_pGameType + 4 * i + 368) = 0;
    MA_CloseMapFile();
    v2 = (const CHAR *)std::string::c_str(v36);
    hFile = CreateFileA(v2, 0x80000000, 0, 0, 3u, 0, 0);
    *(_DWORD *)(g_pGameType + 856) = GetFileSize(hFile, 0);
    CloseHandle(hFile);
    v26 = 1;
    LOBYTE(v39) = 0;
    std::string::~string(v36);
    v39 = -1;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v29);
    return v26;
  }
}


// address=[0x148d250]
// Decompiled from unsigned __int8 __fastcall CGameStateHandler::PerformPendingFullScreenEnterOrExit(__int16 a1)

static void __cdecl CGameStateHandler::PerformPendingFullScreenEnterOrExit(void) {
  
  unsigned __int8 result; // al
  int v2; // [esp-2h] [ebp-4h]

  LOWORD(v2) = a1;
  HIBYTE(v2) = CGameSettings::GetGfxFullscreenEnabled() != 0;
  BYTE2(v2) = HIBYTE(v2);
  result = sub_148D790();
  if ( result != HIBYTE(v2) )
    return CGameStateHandler::SetCorrectWindowSize(v2);
  return result;
}


// address=[0x148d290]
// Decompiled from char __cdecl CGameStateHandler::BuildInitRenderCfg(bool a1, bool a2)

static bool __cdecl CGameStateHandler::BuildInitRenderCfg(bool,bool) {
  
  int *v2; // eax
  char GfxFiltering; // al
  char GfxLandscapeHardware; // al
  char GfxObjectHardware; // al
  const CHAR *v6; // eax
  bool IsFiltering; // al
  bool IsHQTextureSet; // al
  int v10[16]; // [esp-34h] [ebp-FCh] BYREF
  char v11[16]; // [esp+Ch] [ebp-BCh] BYREF
  CEvn_Event *v12; // [esp+1Ch] [ebp-ACh]
  CEvn_Event *v13; // [esp+20h] [ebp-A8h]
  CEvn_Event *v14; // [esp+24h] [ebp-A4h]
  CEvn_Event *v15; // [esp+28h] [ebp-A0h]
  int v16; // [esp+2Ch] [ebp-9Ch] BYREF
  BOOL v17; // [esp+30h] [ebp-98h]
  int v18; // [esp+34h] [ebp-94h]
  int v19; // [esp+38h] [ebp-90h]
  int v20; // [esp+3Ch] [ebp-8Ch] BYREF
  int v21; // [esp+40h] [ebp-88h] BYREF
  bool v22; // [esp+48h] [ebp-80h]
  bool v23; // [esp+49h] [ebp-7Fh]
  bool v24; // [esp+4Ah] [ebp-7Eh]
  char inited; // [esp+4Bh] [ebp-7Dh]
  _DWORD v26[6]; // [esp+4Ch] [ebp-7Ch] BYREF
  _DWORD v27[6]; // [esp+64h] [ebp-64h] BYREF
  char v28[28]; // [esp+7Ch] [ebp-4Ch] BYREF
  int v29; // [esp+98h] [ebp-30h]
  int v30; // [esp+9Ch] [ebp-2Ch]
  int v31; // [esp+A0h] [ebp-28h]
  int v32; // [esp+A4h] [ebp-24h]
  int v33; // [esp+A8h] [ebp-20h]
  int v34; // [esp+ACh] [ebp-1Ch]
  int v35; // [esp+B0h] [ebp-18h]
  int v36; // [esp+B4h] [ebp-14h]
  int v37; // [esp+C4h] [ebp-4h]

  v17 = a2 && !g_pGame;
  byte_3F45605 = v17;
  CGameStateHandler::PerformPendingFullScreenEnterOrExit();
  v2 = (int *)sub_148D8B0(v11);
  v29 = *v2;
  v30 = v2[1];
  v31 = v2[2];
  v32 = v2[3];
  v33 = v29;
  v34 = v30;
  v35 = v31;
  v36 = v32;
  byte_3F45606 = CDebugInfo::IsWindowsNT40();
  dword_3F4560C = (int)g_hWnd;
  dword_3F45610 = v35 - v33;
  dword_3F45614 = v36 - v34;
  dword_3F45618 = v33;
  dword_3F4561C = v34;
  GfxFiltering = CGameSettings::GetGfxFiltering();
  SGfxRenderConfiguration::EnableFiltering((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg, GfxFiltering);
  GfxLandscapeHardware = CGameSettings::GetGfxLandscapeHardware();
  SGfxRenderConfiguration::EnableHardwareLandscapeEngine(
    (SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg,
    GfxLandscapeHardware);
  GfxObjectHardware = CGameSettings::GetGfxObjectHardware();
  SGfxRenderConfiguration::EnableHardwareObjectEngine(
    (SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg,
    GfxObjectHardware);
  v24 = CGameSettings::GetGfxTextureQuality() != 0;
  SGfxRenderConfiguration::EnableHQTextureSet((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg, v24);
  v23 = CGameSettings::GetGfxPureSoftwareMode() != 0;
  SGfxRenderConfiguration::SetPureSoftwareMode((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg, v23);
  v22 = CGameSettings::GetGfxForceBlit() != 0;
  SGfxRenderConfiguration::ForceBlit((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg, v22);
  v20 = 0;
  v21 = 0;
  v16 = 0;
  if ( a1 )
  {
    qmemcpy(&v10[4], &CGameStateHandler::m_sRenderCfg, 0x24u);
    inited = IGfxEngine::RebuildRenderEnvironment(
               g_pGfxEngine,
               v10[4],
               v10[5],
               v10[6],
               v10[7],
               v10[8],
               v10[9],
               v10[10],
               v10[11],
               v10[12]);
  }
  else
  {
    LOBYTE(v10[9]) = CDebugInfo::IsMMX();
    qmemcpy(v10, &CGameStateHandler::m_sRenderCfg, 0x24u);
    inited = IGfxEngine::InitEngine(
               g_pGfxEngine,
               v10[0],
               v10[1],
               v10[2],
               v10[3],
               v10[4],
               v10[5],
               v10[6],
               v10[7],
               v10[8],
               v10[9],
               &v20,
               &v21,
               &v16);
    if ( v16 == 27 )
    {
      CTrace::Print("GameStateHandler: HARDWARE OBJECTS IS DISABLED!");
      CGameSettings::SetAlwaysHardwareObjectImpossible(1);
    }
    if ( v21 )
    {
      CTrace::Print("GameStateHandler: HARDWARE IS COMPLETELY DISABLED!");
      CGameSettings::SetAlwaysHardwareImpossible(1);
      CGameSettings::SetAlwaysHardwareObjectImpossible(1);
    }
  }
  if ( !inited )
  {
    if ( v21 == 26 )
    {
      v15 = CEvn_Event::CEvn_Event((CEvn_Event *)v27, 0x6Eu, 1u, 0, 0);
      v14 = v15;
      v37 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v15);
      v37 = -1;
      CEvn_Event::~CEvn_Event(v27);
    }
    else
    {
      v13 = CEvn_Event::CEvn_Event((CEvn_Event *)v26, 0x6Eu, 0, 0, 0);
      v12 = v13;
      v37 = 1;
      IEventEngine::SendAMessage(g_pEvnEngine, v13);
      v37 = -1;
      CEvn_Event::~CEvn_Event(v26);
    }
    CTrace::Print("CGameStateHandler.cpp: Gamesettings reduced to default. Stored gfx settings won't work !!");
    SGfxRenderConfiguration::EnableFiltering((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg, 0);
    SGfxRenderConfiguration::EnableHardwareLandscapeEngine(
      (SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg,
      0);
    SGfxRenderConfiguration::EnableHardwareObjectEngine((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg, 0);
    SGfxRenderConfiguration::EnableHQTextureSet((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg, 1);
    dword_3F45610 = *(&g_pResolutions + 2);
    dword_3F45614 = *(&dword_3D7AAE8 + 2);
    qmemcpy(&v10[4], &CGameStateHandler::m_sRenderCfg, 0x24u);
    inited = IGfxEngine::RebuildRenderEnvironment(
               g_pGfxEngine,
               v10[4],
               v10[5],
               v10[6],
               v10[7],
               v10[8],
               v10[9],
               v10[10],
               v10[11],
               v10[12]);
  }
  if ( !inited && !a1 )
  {
    std::string::string();
    v37 = 2;
    CTrace::Print("ERROR: GfxEngine could not be initialized: SWError %d, HWError %d!", v20, v21);
    v19 = v20;
    if ( v20 > 0 && (v19 <= 4 || v19 == 6) )
      std::string::operator+=("Software 3D: The Settlers IV needs at least DirectX7.0 for Windows 95/98/2000 or DirectX3."
                              "0 for Windows NT4.0\n"
                              "Software 3D: Die Siedler IV ben?tigt mindestens DirectX7.0 unter Windows 95/98/2000 und Di"
                              "rectX3.0 unter Windows NT 4.0!");
    else
      std::string::operator+=("Software 3D: Error initializing Graphic Interface!\n"
                              "Software 3D: Fehler beim Starten der Grafikausgabe!");
    std::string::operator+=("\n\n");
    v18 = v21;
    if ( v21 > 0 && (v18 <= 4 || v18 == 6) )
      std::string::operator+=("Hardware 3D: The Settlers IV needs at least DirectX7.0 for Windows 95/98/2000 or DirectX3."
                              "0 for Windows NT4.0\n"
                              "Hardware 3D: Die Siedler IV ben?tigt mindestens DirectX7.0 unter Windows 95/98/2000 und Di"
                              "rectX3.0 unter Windows NT 4.0!");
    else
      std::string::operator+=("Hardware 3D: Error initializing Graphic Interface!\n"
                              "Hardware 3D: Fehler beim Starten der Grafikausgabe!");
    v10[12] = 48;
    v10[11] = (int)"S4";
    v6 = (const CHAR *)std::string::c_str(v28);
    MessageBoxA(g_hWnd, v6, (LPCSTR)v10[11], v10[12]);
    j__exit(0);
  }
  if ( g_pGUIEngine )
    IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
  IsFiltering = SGfxRenderConfiguration::IsFiltering((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg);
  CGameSettings::SetGfxFiltering(IsFiltering);
  IsHQTextureSet = SGfxRenderConfiguration::IsHQTextureSet((SGfxRenderConfiguration *)&CGameStateHandler::m_sRenderCfg);
  CGameSettings::SetGfxTextureQuality(IsHQTextureSet);
  return 1;
}


// address=[0x3d89b2c]
// [Decompilation failed for static bool CGameStateHandler::m_bAppActive]

// address=[0x3f455f8]
// [Decompilation failed for static class CGameState * CGameStateHandler::m_s_pCurrentState]

// address=[0x3f455fc]
// [Decompilation failed for static unsigned int CGameStateHandler::m_uiLastTime]

// address=[0x3f45600]
// [Decompilation failed for static bool CGameStateHandler::m_bWantSwitch]

// address=[0x3f45601]
// [Decompilation failed for static bool CGameStateHandler::m_bQuitApplication]

// address=[0x3f45602]
// [Decompilation failed for static bool CGameStateHandler::m_bShowLogo]

// address=[0x3f45603]
// [Decompilation failed for static bool CGameStateHandler::m_bGrab]

// address=[0x3f45604]
// [Decompilation failed for static struct SGfxRenderConfiguration CGameStateHandler::m_sRenderCfg]

// address=[0x3f45668]
// [Decompilation failed for static class std::list<struct SStateCommand,class std::allocator<struct SStateCommand> > CGameStateHandler::m_listQueuedStates]

