#include "CStateBriefing.h"

// Definitions for class CStateBriefing

// address=[0x14a1d50]
// Decompiled from CStateBriefing *__cdecl CStateBriefing::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateBriefing::DynamicCreateFunc(void * a1) {
  
  CStateBriefing *C; // [esp+Ch] [ebp-10h]

  C = (CStateBriefing *)operator new(0x10u);
  if ( C )
    return CStateBriefing::CStateBriefing(C, a1);
  else
    return 0;
}


// address=[0x14a1eb0]
// Decompiled from CStateBriefing *__thiscall CStateBriefing::CStateBriefing(CStateBriefing *this, void *a2)
 CStateBriefing::CStateBriefing(void * a2) {
  
  const char *v2; // eax
  char *v3; // eax
  const wchar_t *v4; // eax
  const char *v5; // eax
  int v7; // [esp-4h] [ebp-244h]
  const wchar_t *v8; // [esp+Ch] [ebp-234h]
  char v10[28]; // [esp+14h] [ebp-22Ch] BYREF
  char Buffer[512]; // [esp+30h] [ebp-210h] BYREF
  int v12; // [esp+23Ch] [ebp-4h]

  CGuiGameState::CGuiGameState(this);
  v12 = 0;
  *(_DWORD *)this = &CStateBriefing::_vftable_;
  CSoundManager::StopMusic(g_pSoundManager);
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  *((_DWORD *)this + 1) = (unsigned __int16)a2;
  *((_DWORD *)this + 2) = HIWORD(a2);
  *((_BYTE *)this + 12) = 0;
  if ( *((int *)this + 1) >= 25
    && BBSupportDbgReport(2, "main\\states\\StateBriefing.cpp", 208, "m_iCampaignType < CAMPAIGN_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 1) == 4 )
  {
    if ( *((int *)this + 2) >= 12
      && BBSupportDbgReport(2, "main\\states\\StateBriefing.cpp", 211, "m_iLevel < CAMPAIGN_DC_COUNT") == 1 )
    {
      __debugbreak();
    }
    byte_402C9F4 = 1;
  }
  else if ( *((_DWORD *)this + 1) )
  {
    if ( *((int *)this + 2) >= 3
      && BBSupportDbgReport(2, "main\\states\\StateBriefing.cpp", 216, "m_iLevel < CAMPAIGN_3C_COUNT") == 1 )
    {
      __debugbreak();
    }
    byte_402C9F4 = 1;
  }
  else
  {
    byte_402C9F4 = 0;
  }
  byte_402C9F5 = 0;
  if ( byte_402C9F4 )
  {
    CStateBriefing::InitBriefingTexts(*((_DWORD *)this + 1), *((_DWORD *)this + 2));
  }
  else
  {
    std::string::operator=(g_pGameType + 884);
    std::string::operator=(g_pGameType + 912);
    std::string::operator=(g_pGameType + 940);
    std::string::operator=(g_pGameType + 968);
  }
  CGuiGameState::SetupGui(this, L"Menu\\GUISetStartscreens.dat", 10, GuiDlgMainBriefingProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  if ( !*((_DWORD *)this + 1) )
    return this;
  if ( CGameSettings::GetLanguage() == 1 )
    v8 = (const wchar_t *)&unk_373C58C;
  else
    v8 = L"EN";
  v7 = *((_DWORD *)this + 2) + 1;
  v2 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)((char *)&unk_402CAA0 + 28 * *((_DWORD *)this + 1) - 28));
  j___snwprintf(Buffer, 0xFFu, v2, v8, v7);
  std::wstring::wstring(v10);
  LOBYTE(v12) = 1;
  if ( (*(unsigned __int8 (__thiscall **)(void *, char *, char *, int))(*(_DWORD *)g_pCDDrive + 8))(
         g_pCDDrive,
         v10,
         Buffer,
         3145732) )
  {
    v4 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v10);
    if ( !CSoundManager::PlaySoundFile((CSoundManager *)g_pSoundManager, v4, 100, 64) )
    {
      v5 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v10);
      BBSupportTracePrintF(0, "Unable to play briefing file %s", v5);
    }
    LOBYTE(v12) = 0;
    std::wstring::~wstring(v10);
  }
  else
  {
    v3 = g_pStringEngine->GetString(g_pStringEngine, 2394);
    std::string::operator=(&g_iMessageBoxStringID, v3);
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 10);
    IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
    LOBYTE(v12) = 0;
    std::wstring::~wstring(v10);
  }
  return this;
}


// address=[0x14a2240]
// Decompiled from void __thiscall CStateBriefing::~CStateBriefing(CStateBriefing *this)
 CStateBriefing::~CStateBriefing(void) {
  
  *(_DWORD *)this = &CStateBriefing::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 10)
    && BBSupportDbgReport(2, "main\\states\\StateBriefing.cpp", 281, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a22c0]
// Decompiled from char __thiscall CStateBriefing::Perform(CStateBriefing *this)
bool  CStateBriefing::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_402CBB4 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_402CBB4);
    if ( dword_402CBB4 == -1 )
    {
      dword_402CBB0 = timeGetTime();
      j___Init_thread_footer(&dword_402CBB4);
    }
  }
  if ( !byte_402C9F4 && !*((_BYTE *)this + 12) )
  {
    CStateBriefing::PaintMap(this, 1);
    *((_BYTE *)this + 12) = 1;
  }
  v1 = dword_402CBB0 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_402CBB0 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14a2390]
// Decompiled from char __thiscall CStateBriefing::OnEvent(CStateBriefing *this, struct CEvn_Event *a2)
bool  CStateBriefing::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  const char *v3; // eax
  char *v4; // eax
  OnlineManager *Instance; // eax
  char v6; // [esp-40h] [ebp-330h] BYREF
  int v7; // [esp-3Ch] [ebp-32Ch]
  int v8; // [esp-38h] [ebp-328h]
  int v9; // [esp-34h] [ebp-324h]
  int v10; // [esp-30h] [ebp-320h]
  int v11; // [esp-2Ch] [ebp-31Ch]
  int v12; // [esp-28h] [ebp-318h]
  int v13; // [esp-24h] [ebp-314h]
  int v14; // [esp-20h] [ebp-310h]
  int v15; // [esp-1Ch] [ebp-30Ch]
  int v16; // [esp-18h] [ebp-308h]
  int v17; // [esp-14h] [ebp-304h]
  int v18; // [esp-10h] [ebp-300h]
  int v19; // [esp-Ch] [ebp-2FCh]
  int v20; // [esp-8h] [ebp-2F8h]
  int v21; // [esp-4h] [ebp-2F4h]
  char *v22; // [esp+4h] [ebp-2ECh]
  int v23; // [esp+8h] [ebp-2E8h]
  int v24; // [esp+Ch] [ebp-2E4h]
  int v25; // [esp+10h] [ebp-2E0h]
  CEvn_Event *v26; // [esp+14h] [ebp-2DCh]
  int v27; // [esp+1Ch] [ebp-2D4h]
  int v28; // [esp+20h] [ebp-2D0h]
  int PlayerName; // [esp+24h] [ebp-2CCh]
  INetworkEngine *v30; // [esp+28h] [ebp-2C8h]
  int v31; // [esp+30h] [ebp-2C0h]
  void *v32; // [esp+34h] [ebp-2BCh]
  int v33; // [esp+38h] [ebp-2B8h]
  CGameType *v34; // [esp+3Ch] [ebp-2B4h]
  void *v35; // [esp+40h] [ebp-2B0h]
  int v36; // [esp+44h] [ebp-2ACh]
  INetworkEngine *v37; // [esp+48h] [ebp-2A8h]
  int v38; // [esp+4Ch] [ebp-2A4h]
  INetworkEngine *v39; // [esp+50h] [ebp-2A0h]
  void *v40; // [esp+54h] [ebp-29Ch]
  int v41; // [esp+58h] [ebp-298h]
  CGameType *v42; // [esp+5Ch] [ebp-294h]
  void *v43; // [esp+60h] [ebp-290h]
  int v44; // [esp+64h] [ebp-28Ch]
  INetworkEngine *v45; // [esp+68h] [ebp-288h]
  void *C; // [esp+6Ch] [ebp-284h]
  int (__thiscall ***v47)(_DWORD, int); // [esp+70h] [ebp-280h]
  bool v48; // [esp+7Bh] [ebp-275h]
  int i; // [esp+7Ch] [ebp-274h]
  int v50; // [esp+80h] [ebp-270h]
  char v51; // [esp+85h] [ebp-26Bh]
  char v52; // [esp+86h] [ebp-26Ah]
  char MapData; // [esp+87h] [ebp-269h]
  CGuiGameState *v54; // [esp+88h] [ebp-268h]
  char v55; // [esp+8Eh] [ebp-262h]
  char v56; // [esp+8Fh] [ebp-261h]
  _BYTE v57[28]; // [esp+90h] [ebp-260h] BYREF
  CEvn_Event v58; // [esp+ACh] [ebp-244h] BYREF
  char v59[28]; // [esp+C4h] [ebp-22Ch] BYREF
  char Buffer[512]; // [esp+E0h] [ebp-210h] BYREF
  int v61; // [esp+2ECh] [ebp-4h]

  v54 = this;
  v50 = a2->event - 11;
  switch ( v50 )
  {
    case 0:
      if ( (unsigned __int16)a2->wparam != 27 )
        goto CStateBriefing__OnEvent___def_18A23F6;
      v26 = CEvn_Event::CEvn_Event(&v58, 0x70u, 0, 0, 0);
      v61 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v26);
      v61 = -1;
      CEvn_Event::~CEvn_Event(&v58);
      result = 1;
      break;
    case 101:
      CSoundManager::StopMusic(g_pSoundManager);
      CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
      if ( byte_402C9F4 )
      {
        if ( g_pGameType )
        {
          v36 = g_pGameType;
          v44 = g_pGameType;
          v35 = delete (CGameType *)g_pGameType;
          g_pGameType = 0;
        }
        if ( *((_DWORD *)v54 + 1) == 4 )
          CGameStateHandler::Switch((int)CStateCampaignDark::DynamicCreateFunc, 0);
        else
          CGameStateHandler::Switch((int)CStateCampaign3X3::DynamicCreateFunc, 0);
        result = 1;
      }
      else
      {
        if ( g_pNetworkEngine )
        {
          v25 = g_pNetworkEngine;
          v38 = (**(int (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
          g_pNetworkEngine = 0;
        }
        C = operator new(0x18u);
        v61 = 1;
        if ( C )
          v45 = INetworkEngine::INetworkEngine((INetworkEngine *)C, 0);
        else
          v45 = 0;
        v37 = v45;
        v61 = -1;
        g_pNetworkEngine = (int)v45;
        INetworkEngine::Start(1, 0, 0, 0);
        CGameStateHandler::Switch((int)CStateLobbyGameSettings::DynamicCreateFunc, 1);
        CLanLobby::Communicate(1051, 0);
        result = 1;
      }
      break;
    case 102:
      CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
      IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
      if ( byte_402C9F4 )
      {
        CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
        if ( (unsigned __int8)CStateLobbyGameSettings::CopyDefaultUserFlags() )
        {
          CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF);
          v43 = operator new(0x620u);
          v61 = 2;
          if ( v43 )
            v42 = CGameType::CGameType((CGameType *)v43);
          else
            v42 = 0;
          v34 = v42;
          v61 = -1;
          g_pGameType = (int)v42;
          v56 = 0;
          v23 = 256;
          v21 = *((_DWORD *)v54 + 2) + 1;
          v3 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)((char *)&unk_402C9F8
                                                                       + 28 * *((_DWORD *)v54 + 1)
                                                                       - 28));
          j___snwprintf(Buffer, 0xFFu, v3, v21);
          std::wstring::wstring(v59);
          v61 = 3;
          if ( (*(unsigned __int8 (__thiscall **)(void *, char *, char *, int))(*(_DWORD *)g_pCDDrive + 8))(
                 g_pCDDrive,
                 v59,
                 Buffer,
                 3145732) )
          {
            v21 = 0;
            v20 = 0;
            v19 = -1;
            v18 = dword_4031CFC;
            v17 = 0;
            v16 = 1;
            v15 = 0;
            v14 = 0;
            v13 = 1;
            v22 = &v6;
            v24 = std::wstring::wstring((int)v59);
            MapData = CGameType::LoadMapData(v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21);
            v56 = MapData;
          }
          if ( v56 )
          {
            IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
            if ( g_pNetworkEngine )
            {
              v31 = g_pNetworkEngine;
              v47 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
              v27 = (**v47)(v47, 1);
              g_pNetworkEngine = 0;
            }
            v40 = operator new(0x18u);
            LOBYTE(v61) = 4;
            if ( v40 )
              v39 = INetworkEngine::INetworkEngine((INetworkEngine *)v40, 0);
            else
              v39 = 0;
            v30 = v39;
            LOBYTE(v61) = 3;
            g_pNetworkEngine = (int)v39;
            *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(g_pGameType + 852);
            *(_DWORD *)(g_pGameType + 188) = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
            Instance = (OnlineManager *)OnlineManager::GetInstance();
            *(_DWORD *)(g_pGameType + 224) = OnlineManager::GetLocalPeerId(Instance);
            PlayerName = CGameSettings::GetPlayerName((int)v57);
            v28 = PlayerName;
            LOBYTE(v61) = 5;
            CGameType::SetPlayerName(0, PlayerName);
            LOBYTE(v61) = 3;
            std::wstring::~wstring(v57);
            *(_DWORD *)(g_pGameType + 740) = *((_DWORD *)v54 + 1);
            *(_DWORD *)(g_pGameType + 744) = *((_DWORD *)v54 + 2);
            *(_DWORD *)(g_pGameType + 692) = 3;
            for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
              *(_BYTE *)(i + g_pGameType + 440) = 0;
            INetworkEngine::Start(1, 1, *(_DWORD *)(g_pGameType + 852), 0);
            CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
            v51 = 1;
            v61 = -1;
            std::wstring::~wstring(v59);
            result = v51;
          }
          else
          {
            v4 = g_pStringEngine->GetString(g_pStringEngine, 2394);
            std::string::operator=(&g_iMessageBoxStringID, v4);
            v55 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 10);
            v55 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
            if ( !v55 && BBSupportDbgReport(2, "main\\states\\StateBriefing.cpp", 405, "bRet") == 1 )
              __debugbreak();
            BBSupportTracePrintF(3, "Campaign map '%s' not found!", Buffer);
            IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
            if ( g_pGameType )
            {
              v33 = g_pGameType;
              v41 = g_pGameType;
              v32 = delete (CGameType *)g_pGameType;
              g_pGameType = 0;
            }
            v52 = 1;
            v61 = -1;
            std::wstring::~wstring(v59);
            result = v52;
          }
        }
        else
        {
          CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
          result = 1;
        }
      }
      else
      {
        CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
        result = 1;
      }
      break;
    case 103:
      v48 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
      CGuiGameState::SetupGui(v54, L"Menu\\GUISetStartscreens.dat", 10, GuiDlgMainBriefingProc);
      result = 1;
      break;
    case 109:
      *((_BYTE *)v54 + 12) = 0;
      result = 1;
      break;
    default:
CStateBriefing__OnEvent___def_18A23F6:
      result = CGuiGameState::OnEvent(v54, a2);
      break;
  }
  return result;
}


// address=[0x14a2c20]
// Decompiled from void *__cdecl CStateBriefing::InitBriefingTexts(int a1, int a2)
void __cdecl CStateBriefing::InitBriefingTexts(int a1, int a2) {
  
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  void *result; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax

  if ( (!a1 || a1 >= 25)
    && BBSupportDbgReport(2, "main\\states\\StateBriefing.cpp", 568, "iCampaignType && iCampaignType < CAMPAIGN_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a1 == 4 )
  {
    if ( a2 >= 12 && BBSupportDbgReport(2, "main\\states\\StateBriefing.cpp", 571, "iLevel < CAMPAIGN_DC_COUNT") == 1 )
      __debugbreak();
  }
  else if ( a2 >= 3 && BBSupportDbgReport(2, "main\\states\\StateBriefing.cpp", 575, "iLevel < CAMPAIGN_3C_COUNT") == 1 )
  {
    __debugbreak();
  }
  dword_402C9F0 = a2;
  dword_402C9EC = a1;
  switch ( a1 )
  {
    case 1:
      v2 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89EF0[a2]);
      std::string::operator=(&unk_402C9B4, v2);
      v3 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89EFC[a2]);
      std::string::operator=(&unk_402C998, v3);
      v4 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F08[a2]);
      std::string::operator=(&unk_402C9D0, v4);
      v5 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F14[a2]);
      result = std::string::operator=(&unk_402C97C, v5);
      break;
    case 2:
      v7 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F20[a2]);
      std::string::operator=(&unk_402C9B4, v7);
      v8 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F2C[a2]);
      std::string::operator=(&unk_402C998, v8);
      v9 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F38[a2]);
      std::string::operator=(&unk_402C9D0, v9);
      v10 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F44[a2]);
      result = std::string::operator=(&unk_402C97C, v10);
      break;
    case 3:
      v11 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F50[a2]);
      std::string::operator=(&unk_402C9B4, v11);
      v12 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F5C[a2]);
      std::string::operator=(&unk_402C998, v12);
      v13 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F68[a2]);
      std::string::operator=(&unk_402C9D0, v13);
      v14 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F74[a2]);
      result = std::string::operator=(&unk_402C97C, v14);
      break;
    case 4:
      v15 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89F80[a2]);
      std::string::operator=(&unk_402C9B4, v15);
      v16 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89FB0[a2]);
      std::string::operator=(&unk_402C998, v16);
      v17 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89FE0[a2]);
      std::string::operator=(&unk_402C9D0, v17);
      v18 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A010[a2]);
      result = std::string::operator=(&unk_402C97C, v18);
      break;
    default:
      result = (void *)BBSupportDbgReportF(
                         2,
                         "main\\states\\StateBriefing.cpp",
                         615,
                         "Invalid Race during CStateBriefing::InitBriefingTexts init!");
      if ( result == (void *)1 )
        __debugbreak();
      break;
  }
  return result;
}


// address=[0x14a1dd0]
// Decompiled from char __thiscall CStateBriefing::PaintMap(CStateBriefing *this, char a2)
void  CStateBriefing::PaintMap(bool a2) {
  
  char result; // al
  unsigned int v3; // [esp+4h] [ebp-1Ch] BYREF
  unsigned __int16 *v4; // [esp+8h] [ebp-18h] BYREF
  _BYTE v5[16]; // [esp+Ch] [ebp-14h] BYREF

  result = a2;
  if ( !a2 )
    return IGuiEngine::EraseOwnerImage((IGuiEngine *)g_pGUIEngine, 10, 2075);
  if ( !g_pGameType || !*(_DWORD *)(g_pGameType + 1016) )
    return result;
  v4 = 0;
  v3 = 0;
  result = IGuiEngine::LockOwnerImage((IGuiEngine *)g_pGUIEngine, 10, 2075, (struct SGuiRect *)v5, &v4, &v3);
  if ( !v4 )
    return result;
  CStateLobbyGameSettings::DrawMap(
    *(unsigned __int16 **)(g_pGameType + 1016),
    v4,
    v3,
    *(_DWORD *)(g_pGameType + 1020),
    *(_DWORD *)(g_pGameType + 1024));
  return IGuiEngine::UnlockOwnerImage((IGuiEngine *)g_pGUIEngine, 10, 2075);
}


