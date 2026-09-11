#include "CStateMDRandomMapParameters.h"

// Definitions for class CStateMDRandomMapParameters

// address=[0x14c80e0]
// Decompiled from CStateMDRandomMapParameters *__cdecl CStateMDRandomMapParameters::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateMDRandomMapParameters::DynamicCreateFunc(void * a1) {
  
  CStateMDRandomMapParameters *C; // [esp+Ch] [ebp-10h]

  C = (CStateMDRandomMapParameters *)operator new(0xCu);
  if ( C != 0 )
  {
    return CStateMDRandomMapParameters::CStateMDRandomMapParameters(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14c8180]
// Decompiled from CStateMDRandomMapParameters *__thiscall CStateMDRandomMapParameters::CStateMDRandomMapParameters(CStateMDRandomMapParameters *this, void *a2)
 CStateMDRandomMapParameters::CStateMDRandomMapParameters(void * a2) {
  
  __int64 v2; // kr00_8
  const char *v3; // eax
  const char *v4; // eax
  int v6; // [esp+Ch] [ebp-480h]
  _Cnd_internal_imp_t *PlayerName; // [esp+10h] [ebp-47Ch]
  CGameType *v8; // [esp+2Ch] [ebp-460h]
  CGameType *C; // [esp+30h] [ebp-45Ch]
  int i; // [esp+3Ch] [ebp-450h]
  std::wstring v12; // [esp+44h] [ebp-448h] BYREF
  char v13[28]; // [esp+60h] [ebp-42Ch] BYREF
  char Buffer[2]; // [esp+7Ch] [ebp-410h] BYREF
  __int16 v15; // [esp+BAh] [ebp-3D2h]
  wchar_t Dest[256]; // [esp+27Ch] [ebp-210h] BYREF
  int v17; // [esp+488h] [ebp-4h]

  CGuiGameState::CGuiGameState((CGuiGameState *)this);
  v17 = 0;
  *(_DWORD *)this = &CStateMDRandomMapParameters::_vftable_;
  *((_BYTE *)this + 4) = (_BYTE)a2;
  if ( *((_BYTE *)this + 4) != 0 )
  {
    dword_4031998 = 6;
  }
  else
  {
    dword_4031998 = 7;
  }
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  if ( g_pNetworkEngine != 0 )
  {
    (**(void (__thiscall ***)(INetworkEngine *, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
    g_pNetworkEngine = 0;
  }
  if ( g_pGameType != 0 )
  {
    delete g_pGameType;
    g_pGameType = 0;
  }
  CGuiGameState::SetupExtraGui((int)g_pMissionCD, 6, (int)GuiDlgMDRandomMapParametersProc);
  if ( g_pGameType != 0 )
  {
    CStateMDRandomMapParameters::SetupGUI(this);
  }
  else
  {
    C = (CGameType *)operator new(0x620u);
    LOBYTE(v17) = 1;
    if ( C != 0 )
    {
      v8 = CGameType::CGameType(C);
    }
    else
    {
      v8 = 0;
    }
    LOBYTE(v17) = 0;
    g_pGameType = v8;
    dword_4031938 = 0;
    dword_4031934 = 1;
    dword_4031928 = 2;
    dword_4031924 = 2;
    byte_403195A = 1;
    byte_403195B = 1;
    dword_4031930 = 2;
    memset(&g_sRMP, 0, 0xB8u);
    g_sRMP = 184;
    dword_4031F98 = 0;
    dword_4031F9C = 0;
    byte_4031FA5 = 0;
    dword_4031F94 = 0;
    dword_4031F8C = 70;
    dword_4031FA0 = 2;
    v2 = 0x7FFF * j__rand();
    dword_4031F84 = (j__rand() + v2) % 0xF4240uLL;
    byte_4031FA4 = 0;
    dword_4031F90 = 10;
    dword_4031F88 = 512;
    for ( i = 0;
          i < 9;
          ++i )
    {
      dword_4031FA8[4 * i] = 16;
      dword_4031FB4[4 * i] = 0;
      dword_4031FB0[4 * i] = 0;
      dword_4031FAC[4 * i] = -1;
    }
    CStateMDRandomMapParameters::SetupGUI(this);
    v3 = g_pStringEngine->GetString(g_pStringEngine, 789);
    j__mbstowcs(Dest, v3, 0x200u);
    if ( j__wcscmp(Dest, L"dummy") == 0 )
    {
      wcscpy(Dest, L"%s's Game");
    }
    PlayerName = (_Cnd_internal_imp_t *)CGameSettings::GetPlayerName((int)v13);
    v4 = (const char *)std::wstring::c_str((std::wstring *)PlayerName);
    j__swprintf(Buffer, 0x100u, v4);
    std::wstring::~wstring((std::wstring *)v13);
    v15 = 0;
    v6 = std::wstring::wstring(&v12, (wchar_t *)Buffer);
    ((void (__stdcall *)(int))std::wstring::operator=)(v6);
    std::wstring::~wstring(&v12);
  }
  return this;
}


// address=[0x14c85d0]
// Decompiled from void __thiscall CStateMDRandomMapParameters::~CStateMDRandomMapParameters(CGuiGameState *this)
 CStateMDRandomMapParameters::~CStateMDRandomMapParameters(void) {
  
  this->__vftable = (CGuiGameState_vtbl *)&CStateMDRandomMapParameters::_vftable_;
  IGuiEngine::CloseDialog(g_pGUIEngine, 9);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c8630]
// Decompiled from char __thiscall CStateMDRandomMapParameters::Perform(CStateMDRandomMapParameters *this)
bool  CStateMDRandomMapParameters::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_40320A0 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_40320A0);
    if ( dword_40320A0 == -1 )
    {
      dword_403209C = timeGetTime();
      j___Init_thread_footer(&dword_40320A0);
    }
  }
  v1 = dword_403209C + 30;
  if ( v1 < timeGetTime() )
  {
    dword_403209C = timeGetTime();
    IGuiEngine::RenderGui(g_pGUIEngine);
    IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame(g_pGfxEngine);
  }
  return 1;
}


// address=[0x14c86d0]
// Decompiled from char __thiscall CStateMDRandomMapParameters::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CStateMDRandomMapParameters::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  char *v3; // eax
  signed __int8 LocalSlot; // al
  int Instance; // eax
  __int64 v6; // kr00_8
  char v7; // [esp-40h] [ebp-158h] BYREF
  int v8; // [esp-3Ch] [ebp-154h]
  int v9; // [esp-38h] [ebp-150h]
  int v10; // [esp-34h] [ebp-14Ch]
  int v11; // [esp-30h] [ebp-148h]
  int v12; // [esp-2Ch] [ebp-144h]
  int v13; // [esp-28h] [ebp-140h]
  BOOL v14; // [esp-24h] [ebp-13Ch]
  char *LocalIP; // [esp-20h] [ebp-138h]
  int v16; // [esp-1Ch] [ebp-134h]
  int v17; // [esp-18h] [ebp-130h]
  int v18; // [esp-14h] [ebp-12Ch]
  int AIDifficulty; // [esp-10h] [ebp-128h]
  int v20; // [esp-Ch] [ebp-124h]
  __int64 v21; // [esp-8h] [ebp-120h]
  int v22; // [esp+Ch] [ebp-10Ch]
  char *v23; // [esp+10h] [ebp-108h]
  CEvn_Event *v24; // [esp+14h] [ebp-104h]
  CEvn_Event *v25; // [esp+1Ch] [ebp-FCh]
  unsigned int v26; // [esp+24h] [ebp-F4h]
  int v27; // [esp+2Ch] [ebp-ECh]
  void *v28; // [esp+30h] [ebp-E8h]
  int v29; // [esp+34h] [ebp-E4h]
  CGameType *v30; // [esp+38h] [ebp-E0h]
  INetworkEngine *v31; // [esp+40h] [ebp-D8h]
  int v32; // [esp+44h] [ebp-D4h]
  int v33; // [esp+48h] [ebp-D0h]
  void *v34; // [esp+4Ch] [ebp-CCh]
  int v35; // [esp+50h] [ebp-C8h]
  CEvn_Event *v36; // [esp+54h] [ebp-C4h]
  int v37; // [esp+58h] [ebp-C0h]
  INetworkEngine *v38; // [esp+5Ch] [ebp-BCh]
  void *C; // [esp+60h] [ebp-B8h]
  CGameType *v40; // [esp+68h] [ebp-B0h]
  CGameType *v41; // [esp+6Ch] [ebp-ACh]
  void *v42; // [esp+70h] [ebp-A8h]
  int v43; // [esp+74h] [ebp-A4h]
  INetworkEngine *v44; // [esp+78h] [ebp-A0h]
  bool v45; // [esp+7Eh] [ebp-9Ah]
  char v46; // [esp+7Fh] [ebp-99h]
  int v47; // [esp+80h] [ebp-98h]
  unsigned int j; // [esp+84h] [ebp-94h]
  unsigned int i; // [esp+88h] [ebp-90h]
  int v50; // [esp+8Ch] [ebp-8Ch]
  int k; // [esp+90h] [ebp-88h]
  char v52; // [esp+94h] [ebp-84h]
  char v53; // [esp+95h] [ebp-83h]
  char v54; // [esp+96h] [ebp-82h]
  char MapData; // [esp+97h] [ebp-81h]
  unsigned int event; // [esp+98h] [ebp-80h]
  CGuiGameState *v57; // [esp+9Ch] [ebp-7Ch]
  bool v58; // [esp+A1h] [ebp-77h]
  char v59; // [esp+A2h] [ebp-76h]
  char v60; // [esp+A3h] [ebp-75h]
  CEvn_Event v61; // [esp+A4h] [ebp-74h] BYREF
  CEvn_Event v62; // [esp+BCh] [ebp-5Ch] BYREF
  CEvn_Event v63; // [esp+D4h] [ebp-44h] BYREF
  std::wstring v64; // [esp+ECh] [ebp-2Ch] BYREF
  int v65; // [esp+114h] [ebp-4h]

  v57 = this;
  event = a2->m_iEventId;
  if ( event > 0x1B6A )
  {
    event -= 7019;
    switch ( event )
    {
      case 0u:
        IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 4u);
        if ( g_pNetworkEngine != 0 )
        {
          v33 = (int)g_pNetworkEngine;
          v44 = g_pNetworkEngine;
          v32 = (**(int (__thiscall ***)(INetworkEngine *, int))v44)(v44, 1);
          g_pNetworkEngine = 0;
        }
        C = operator new(0x18u);
        v65 = 2;
        if ( C != 0 )
        {
          v38 = INetworkEngine::INetworkEngine((INetworkEngine *)C, (bool)v57[1].__vftable);
        }
        else
        {
          v38 = 0;
        }
        v31 = v38;
        v65 = -1;
        g_pNetworkEngine = v38;
        v59 = INetworkEngine::Start(1, 0, 0, 0);
        if ( v59 != 0 || LOBYTE(v57[1].__vftable) == 0 )
        {
          std::wstring::wstring(&v64);
          v65 = 3;
          ((void (__thiscall *)(CRandomMaps *, std::wstring *, int *))g_pRandomMaps->j_?GenerateRandomMapFileName@CRandomMaps@@UAEXAAV?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@ABUSRandomMapParams@@@Z)(g_pRandomMaps, &v64, &g_sRMP);
          v58 = LOBYTE(v57[1].__vftable) == 0;
          v21 = 0;
          v20 = -1;
          AIDifficulty = CGameSettings::GetAIDifficulty();
          v18 = 0;
          v17 = 0;
          v16 = 0;
          LocalIP = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
          v14 = v58;
          v23 = &v7;
          v22 = ((int (__stdcall *)(int))std::wstring::wstring)((int)&v64);
          MapData = ((_DWORD (__stdcall *)(char, int, int, int, int, int, int, char, char *, char, char, int, int, int, char, char))CGameType::LoadMapData)(v7, v8, v9, v10, v11, v12, v13, v14, LocalIP, v16, v17, v18, AIDifficulty, v20, v21, SBYTE4(v21));
          v46 = MapData;
          g_pGameType->m_uiNumberAlliances = dword_4031928;
          g_pGameType->m_iActualPlayerCount = dword_4031924;
          g_pGameType->m_iMapMaxNumPlayers = dword_4031924;
          g_pGameType->m_iStartResources = dword_4031930;
          g_pGameType->m_iMode = dword_4031934;
          g_pGameType->m_iActualPlayerCount = dword_4031924;
          ((void (__stdcall *)(int))std::wstring::operator=)((int)&stru_4031960);
          if ( LOBYTE(v57[1].__vftable) != 0 )
          {
            v37 = 2;
          }
          else
          {
            v37 = 1;
          }
          g_pGameType->m_iGameType = v37;
          g_pGameType->m_iCampaignType = 0;
          LocalSlot = CPlayerManager::GetLocalSlot();
          CGameType::SetLocalSlot(g_pGameType, LocalSlot);
          g_pGameType->m_uExtraFlags = byte_403199C;
          CGameType::SetMCD2TextureSet(g_pGameType, byte_403199D);
          for ( i = 0;
                i < g_pGameType->m_iActualPlayerCount;
                ++i )
          {
            g_pGameType->m_sPlayerTeam[i] %= g_pGameType->m_uiNumberAlliances;
          }
          if ( dword_4031934 == 5 )
          {
            g_pGameType->m_bIsGameWon = 1;
            g_pGameType->m_iTeamWon = 1;
          }
          if ( dword_4031934 == 3 )
          {
            v26 = g_pGameType->m_iActualPlayerCount % 2u + (g_pGameType->m_iActualPlayerCount >> 1);
            for ( j = 0;
                  j < g_pGameType->m_uiNumberAlliances;
                  ++j )
            {
              g_pGameType->m_iAllianceSizes[j] = v26;
            }
          }
          CGameType::SetHost(g_pGameType, 1);
          IGuiEngine::CloseDialog(g_pGUIEngine, dword_4031998);
          if ( g_pMissionCD == 0 && BBSupportDbgReport(2, "main\\States\\StateMDRandomMapParameters.cpp", 339, "g_pMissionCD") == 1 )
          {
            __debugbreak();
          }
          ((void (__thiscall *)(CMissionCD *, _DWORD, char (__cdecl *)(int, int, int)))g_pMissionCD->j_?EnsureMainGUI@CExtraCD@@UAEXHP6A_NHHH@Z@Z)(g_pMissionCD, 0, GuiDlgMainscreenProc);
          CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLobbyGameSettings::DynamicCreateFunc, (void *)1);
          Instance = OnlineManager::GetInstance();
          if ( (unsigned __int8)OnlineManager::IsQuickMatchFlow(Instance) != 0 )
          {
            CLanLobby::Communicate(1059, 0);
          }
          else
          {
            CLanLobby::Communicate(1051, 0);
          }
          v54 = 1;
          v65 = -1;
          std::wstring::~wstring(&v64);
          result = v54;
        }
        else
        {
          byte_403206C = 1;
          CTrace::Print("GameHost: Unrecoverable network error while starting network for Creating Game!");
          v3 = g_pStringEngine->GetString(g_pStringEngine, 2402);
          std::string::operator=(&g_iMessageBoxStringID, v3);
          v59 = IGuiEngine::CloseDialog(g_pGUIEngine, dword_4031998);
          if ( v59 == 0 && BBSupportDbgReport(2, "main\\States\\StateMDRandomMapParameters.cpp", 276, "bRet") == 1 )
          {
            __debugbreak();
          }
          if ( g_pMissionCD == 0 && BBSupportDbgReport(2, "main\\States\\StateMDRandomMapParameters.cpp", 277, "g_pMissionCD") == 1 )
          {
            __debugbreak();
          }
          ((void (__thiscall *)(CMissionCD *, _DWORD, char (__cdecl *)(int, int, int)))g_pMissionCD->j_?EnsureMainGUI@CExtraCD@@UAEXHP6A_NHHH@Z@Z)(g_pMissionCD, 0, GuiDlgMainscreenProc);
          if ( IGuiEngine::OpenDialog(g_pGUIEngine, 20, (bool (__cdecl *)(int, int, int))GuiDlgMainMessageBoxProc) == 0 && BBSupportDbgReport(2, "main\\States\\StateMDRandomMapParameters.cpp", 280, "bRet") == 1 )
          {
            __debugbreak();
          }
          result = 1;
        }
        break;
      case 1u:
        IGuiEngine::CloseDialog(g_pGUIEngine, dword_4031998);
        if ( g_pMissionCD == 0 && BBSupportDbgReport(2, "main\\States\\StateMDRandomMapParameters.cpp", 362, "g_pMissionCD") == 1 )
        {
          __debugbreak();
        }
        ((void (__thiscall *)(CMissionCD *, _DWORD, char (__cdecl *)(int, int, int)))g_pMissionCD->j_?EnsureMainGUI@CExtraCD@@UAEXHP6A_NHHH@Z@Z)(g_pMissionCD, 0, GuiDlgMainscreenProc);
        dword_403191C = a2->m_wParam;
        CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLobbyMapSettings::DynamicCreateFunc, (void *)LOBYTE(v57[1].__vftable));
        result = 1;
        break;
      case 2u:
        if ( a2->m_wParam != 0 )
        {
          if ( dword_4031F88 < 1024 )
          {
            dword_4031F88 += 64;
          }
        }
        else if ( dword_4031F88 > 256 )
        {
          dword_4031F88 -= 64;
        }
        goto LABEL_134;
      case 3u:
        if ( a2->m_wParam != 0 )
        {
          if ( (dword_4031F94 & 3u) < 3 )
          {
            ++dword_4031F94;
          }
        }
        else if ( (dword_4031F94 & 3) != 0 )
        {
          --dword_4031F94;
        }
        goto LABEL_134;
      case 4u:
        if ( a2->m_wParam != 0 )
        {
          if ( dword_4031F8C < 90 )
          {
            dword_4031F8C += 10;
          }
        }
        else if ( dword_4031F8C > 10 )
        {
          dword_4031F8C -= 10;
        }
        goto LABEL_134;
      case 5u:
        if ( a2->m_wParam != 0 )
        {
          if ( dword_4031F90 < 15 )
          {
            dword_4031F90 += 5;
          }
        }
        else if ( dword_4031F90 > 5 )
        {
          dword_4031F90 -= 5;
        }
        goto LABEL_134;
      case 6u:
        v6 = 0x7FFF * j__rand();
        v21 = 1000000;
        dword_4031F84 = (j__rand() + v6) % 0xF4240uLL;
        byte_4031FA4 = 0;
        GuiDlgMDRandomMapParametersUpdate();
        result = 1;
        break;
      case 9u:
        v50 = ((int (__thiscall *)(CRandomMaps *))g_pRandomMaps->j_?GetRandomMapInfo@CRandomMaps@@UAEPBUSRandomMapInfo@@XZ)(g_pRandomMaps);
        if ( v50 != 0 )
        {
          v27 = (int)g_pGameType;
          v42 = operator new(0x620u);
          v65 = 4;
          if ( v42 != 0 )
          {
            v41 = CGameType::CGameType((CGameType *)v42);
          }
          else
          {
            v41 = 0;
          }
          v30 = v41;
          v65 = -1;
          g_pGameType = v41;
          for ( k = 0;
                k < *(_DWORD *)(v50 + 16);
                ++k )
          {
            g_pGameType->m_sPlayerStartX[k] = *(_DWORD *)(v50 + 4 * k + 24);
            g_pGameType->m_sPlayerStartY[k] = *(_DWORD *)(v50 + 4 * k + 60);
          }
          g_pGameType->m_iWidthHeight = *(_DWORD *)(v50 + 12);
          g_pGameType->m_iActualPlayerCount = *(_DWORD *)(v50 + 16);
          CStateMDRandomMapParameters::PaintMap((CStateMDRandomMapParameters *)v57);
          v29 = (int)g_pGameType;
          v40 = g_pGameType;
          if ( g_pGameType != 0 )
          {
            v28 = delete v40;
          }
          else
          {
            v28 = 0;
          }
          g_pGameType = (CGameType *)v27;
          IGuiEngine::SetImages(g_pGUIEngine, dword_4031998, 2006, 30, 30);
          result = 1;
        }
        else
        {
          result = 1;
        }
        break;
      default:
CStateMDRandomMapParameters__OnEvent___def_18C873C:
        result = CGuiGameState::OnEvent(v57, a2);
        break;
    }
  }
  else if ( event == 7018 )
  {
    g_pRandomMaps->CleanUp(g_pRandomMaps);
    IGuiEngine::CloseDialog(g_pGUIEngine, dword_4031998);
    if ( g_pMissionCD == 0 && BBSupportDbgReport(2, "main\\States\\StateMDRandomMapParameters.cpp", 236, "g_pMissionCD") == 1 )
    {
      __debugbreak();
    }
    ((void (__thiscall *)(CMissionCD *, _DWORD, char (__cdecl *)(int, int, int)))g_pMissionCD->j_?EnsureMainGUI@CExtraCD@@UAEXHP6A_NHHH@Z@Z)(g_pMissionCD, 0, GuiDlgMainscreenProc);
    if ( LOBYTE(v57[1].__vftable) != 0 )
    {
      CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, (void *)1);
    }
    else
    {
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLocalType::DynamicCreateFunc, (void *)1);
    }
    if ( g_pGameType != 0 )
    {
      v35 = (int)g_pGameType;
      v34 = delete g_pGameType;
      g_pGameType = 0;
    }
    return 1;
  }
  else
  {
    event -= 11;
    switch ( event )
    {
      case 0u:
        if ( (unsigned __int16)a2->m_wParam != 27 )
        {
          goto CStateMDRandomMapParameters__OnEvent___def_18C873C;
        }
        if ( byte_403206C != 0 )
        {
          v25 = CEvn_Event::CEvn_Event(&v63, 0x72u, 0, 0, 0);
          v65 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v25);
          v65 = -1;
          CEvn_Event::~CEvn_Event(&v63);
        }
        else
        {
          v36 = CEvn_Event::CEvn_Event(&v62, 0x1B6Au, 0, 0, 0);
          v65 = 1;
          IEventEngine::SendAMessage(g_pEvnEngine, v36);
          v65 = -1;
          CEvn_Event::~CEvn_Event(&v62);
        }
        return 1;
      case 0x38u:
        if ( a2->m_wParam != 0 )
        {
          if ( dword_4031928 == dword_4031924 )
          {
            return 1;
          }
          v43 = dword_4031934;
          if ( dword_4031934 == 1 )
          {
            if ( dword_4031928 < 8 )
            {
              ++dword_4031928;
            }
          }
          else if ( v43 == 3 && dword_4031928 < 2 )
          {
            ++dword_4031928;
          }
        }
        else
        {
          if ( dword_4031928 == 2 )
          {
            return 1;
          }
          --dword_4031928;
        }
        break;
      case 0x39u:
        if ( a2->m_wParam != 0 )
        {
          if ( dword_4031924 < 8 )
          {
            ++dword_4031924;
          }
        }
        else if ( dword_4031924 > 2 && dword_4031928 > --dword_4031924 )
        {
          --dword_4031928;
        }
        break;
      case 0x3Au:
        v60 = 0;
        do
        {
          if ( a2->m_wParam != 0 )
          {
            if ( ++dword_4031934 > 6 )
            {
              dword_4031934 = 1;
            }
          }
          else if ( --dword_4031934 == 0 )
          {
            dword_4031934 = 5;
          }
          v47 = dword_4031934 - 1;
          switch ( dword_4031934 )
          {
            case 1:
              v60 = 1;
              byte_403195A = 1;
              byte_403195B = 1;
              dword_4031928 = 2;
              dword_4031924 = 2;
              break;
            case 2:
              v60 = 0;
              break;
            case 3:
              v60 = 1;
              byte_403195A = 1;
              byte_403195B = 0;
              dword_4031928 = 2;
              dword_4031924 = 2;
              break;
            case 5:
              if ( LOBYTE(v57[1].__vftable) != 0 )
              {
                v60 = 0;
              }
              else
              {
                v60 = 1;
                byte_403195A = 0;
                byte_403195B = 0;
                dword_4031928 = 1;
                dword_4031924 = 1;
              }
              break;
            default:
              v60 = 0;
              break;
          }
        }
        while ( v60 == 0 );
        break;
      case 0x3Bu:
        if ( a2->m_wParam != 0 )
        {
          if ( dword_4031930 == 3 )
          {
            return 1;
          }
          ++dword_4031930;
        }
        else
        {
          if ( dword_4031930 == 1 )
          {
            return 1;
          }
          --dword_4031930;
        }
        break;
      case 0x40u:
        if ( a2->m_wParam != 0 )
        {
          byte_403199C |= 1u;
        }
        else
        {
          byte_403199C &= ~1u;
        }
        v53 = byte_403199C;
        return 1;
      case 0x41u:
        if ( a2->m_wParam != 0 )
        {
          byte_403199D = 1;
          v52 = 1;
        }
        else
        {
          byte_403199D = 0;
          v52 = 0;
        }
        return 1;
      case 0x67u:
        byte_403206C = 0;
        v45 = IGuiEngine::CloseDialog(g_pGUIEngine, 20);
        CGuiGameState::SetupExtraGui((int)g_pMissionCD, dword_4031998, (int)GuiDlgMDRandomMapParametersProc);
        CStateMDRandomMapParameters::SetupGUI((CStateMDRandomMapParameters *)v57);
        v24 = CEvn_Event::CEvn_Event(&v61, 0x1B6Au, 0, 0, 0);
        v65 = 5;
        IEventEngine::SendAMessage(g_pEvnEngine, v24);
        v65 = -1;
        CEvn_Event::~CEvn_Event(&v61);
        return 1;
      default:
        goto CStateMDRandomMapParameters__OnEvent___def_18C873C;
    }
LABEL_134:
    GuiDlgMDRandomMapParametersUpdate();
    return 1;
  }
  return result;
}


// address=[0x14c96a0]
// Decompiled from int __cdecl CStateMDRandomMapParameters::DrawMap(unsigned __int16 *a1, unsigned __int16 *a2, unsigned int a3, int a4, int a5)
void __cdecl CStateMDRandomMapParameters::DrawMap(unsigned short * a1, unsigned short * a2, unsigned int a3, int a4, int a5) {
  
  int result; // eax
  int v6; // [esp+1Ch] [ebp-31Ch]
  int v7; // [esp+20h] [ebp-318h]
  int v8; // [esp+24h] [ebp-314h]
  int v9; // [esp+28h] [ebp-310h]
  int v10; // [esp+2Ch] [ebp-30Ch]
  float v11; // [esp+30h] [ebp-308h]
  float v12; // [esp+34h] [ebp-304h]
  float v13; // [esp+34h] [ebp-304h]
  unsigned __int16 v14; // [esp+38h] [ebp-300h]
  int i; // [esp+3Ch] [ebp-2FCh]
  bool v16; // [esp+43h] [ebp-2F5h]
  unsigned __int8 *v17; // [esp+44h] [ebp-2F4h]
  unsigned __int16 v18; // [esp+48h] [ebp-2F0h]
  unsigned __int16 *v19; // [esp+50h] [ebp-2E8h]
  int m; // [esp+54h] [ebp-2E4h]
  int j; // [esp+58h] [ebp-2E0h]
  int k; // [esp+58h] [ebp-2E0h]
  int n; // [esp+5Ch] [ebp-2DCh]
  unsigned __int8 v24; // [esp+63h] [ebp-2D5h]
  _DWORD v25[180]; // [esp+64h] [ebp-2D4h] BYREF

  v16 = IGfxEngine::GetGfxMode(g_pGfxEngine) == 1;
  for ( i = 3;
        i < 157;
        ++i )
  {
    for ( j = 3;
          j < 157;
          ++j )
    {
      v11 = (float)a5 / 160.0;
      v12 = (float)a4 / 160.0;
      if ( v16 )
      {
        v14 = a1[a4 * (int)(float)((float)i * v11) + (int)(float)((float)j * v12)];
      }
      else
      {
        v18 = a1[a4 * (int)(float)((float)i * v11) + (int)(float)((float)j * v12)];
        v14 = v18 & 0xF | ((((int)v18 >> 5) & 0xF) << 6) | ((((int)v18 >> 10) & 0xF) << 11);
      }
      a2[((a3 * i) >> 1) + j + (160 - i) / 2] = v14;
    }
  }
  v13 = 160.0 / (float)g_pGameType->m_iWidthHeight;
  if ( g_pGameType->m_iActualPlayerCount != 0 )
  {
    v7 = g_pGameType->m_iActualPlayerCount;
  }
  else
  {
    v7 = g_pGameType->m_iMapMaxNumPlayers;
  }
  for ( k = 0;
        ;
        ++k )
  {
    result = k;
    if ( k >= v7 )
    {
      break;
    }
    v6 = (int)(float)((float)g_pGameType->m_sPlayerStartY[k] * v13);
    v8 = (int)(float)((float)g_pGameType->m_sPlayerStartX[k] * v13) + (160 - v6) / 2;
    CGfxManager::GetAccessoryGfxInfo(g_pGfxManager, (struct SGfxObjectInfo *)v25, k + 52);
    v19 = (unsigned __int16 *)v25[0];
    v17 = (unsigned __int8 *)(v25[0] + 12);
    for ( m = 0;
          m < v19[1];
          ++m )
    {
      for ( n = 0;
            n < *v19;
            ++n )
      {
        v24 = *v17++;
        if ( v24 != 0 )
        {
          if ( v24 == 1 )
          {
            v9 = *v17++;
            if ( v9 == 0 )
            {
              break;
            }
            m += (v9 - 1) / *v19;
            n += (v9 - 1) % *v19;
            if ( n >= *v19 )
            {
              ++m;
              n -= *v19;
            }
          }
          else
          {
            a2[((a3 * (m + v6 - (__int16)v19[3])) >> 1) + v8 - (__int16)v19[2] + n] = *(_WORD *)(v25[1] + 2 * v24);
          }
        }
        else
        {
          v10 = *v17++;
          if ( v10 == 0 )
          {
            break;
          }
          m += (v10 - 1) / *v19;
          n += (v10 - 1) % *v19;
          if ( n >= *v19 )
          {
            ++m;
            n -= *v19;
          }
        }
      }
    }
  }
  return result;
}


// address=[0x14c9c20]
// Decompiled from char __thiscall CStateMDRandomMapParameters::PaintMap(CStateMDRandomMapParameters *this)
void  CStateMDRandomMapParameters::PaintMap(void) {
  
  char result; // al
  unsigned __int16 *v2; // [esp+4h] [ebp-28h]
  unsigned int v3; // [esp+10h] [ebp-1Ch] BYREF
  unsigned __int16 *v4; // [esp+14h] [ebp-18h] BYREF
  _BYTE v5[16]; // [esp+18h] [ebp-14h] BYREF

  v2 = (unsigned __int16 *)((int (__thiscall *)(CRandomMaps *, CStateMDRandomMapParameters *))g_pRandomMaps->j_?GetPreviewData@CRandomMaps@@UAEPBGXZ)(g_pRandomMaps, this);
  v4 = 0;
  v3 = 0;
  result = IGuiEngine::LockOwnerImage(g_pGUIEngine, dword_4031998, 2022, (struct SGuiRect *)v5, &v4, &v3);
  if ( v4 != 0 )
  {
    CStateMDRandomMapParameters::DrawMap(v2, v4, v3, 160, 160);
    return IGuiEngine::UnlockOwnerImage(g_pGUIEngine, dword_4031998, GUI_S4S_GS_MASIZE_TT);
  }
  return result;
}


// address=[0x14c8160]
// Decompiled from char __thiscall CStateMDRandomMapParameters::SetupGUI(CGuiGameState *this)
void  CStateMDRandomMapParameters::SetupGUI(void) {
  
  return CGuiGameState::OpenDialog(this, dword_4031998, (bool (__cdecl *)(int, int, int))GuiDlgMDRandomMapParametersProc);
}


