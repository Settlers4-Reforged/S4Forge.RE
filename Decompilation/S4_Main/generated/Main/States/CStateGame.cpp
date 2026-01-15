#include "CStateGame.h"

// Definitions for class CStateGame

// address=[0x1303890]
// Decompiled from int __thiscall CStateGame::GetTickCounter(CStateGame *this)
unsigned int  CStateGame::GetTickCounter(void) {
  
  return *((_DWORD *)this + 19);
}


// address=[0x130f320]
// Decompiled from char *__thiscall CStateGame::Random16(CStateGame *this)
class CRandom16 &  CStateGame::Random16(void) {
  
  return (char *)this + 120;
}


// address=[0x1326f20]
// Decompiled from unsigned int __thiscall CStateGame::Rand(CStateGame *this)
unsigned int  CStateGame::Rand(void) {
  
  return CRandom16::Rand((CStateGame *)((char *)this + 120));
}


// address=[0x14606d0]
// Decompiled from int __thiscall CStateGame::IsMessage(CStateGame *this)
bool  CStateGame::IsMessage(void) {
  
  return (*(int (__thiscall **)(_DWORD, CStateGame *))(**((_DWORD **)this + 63) + 12))(*((_DWORD *)this + 63), this);
}


// address=[0x14607a0]
// Decompiled from int __thiscall CStateGame::PopMessage(_DWORD **this, int a2)
class CEvn_Logic  CStateGame::PopMessage(void) {
  
  struct boost::exception_detail::clone_base *v2; // eax

  v2 = (struct boost::exception_detail::clone_base *)(*(int (__thiscall **)(_DWORD *))(*this[63] + 8))(this[63]);
  CEvn_Logic::CEvn_Logic(v2);
  return a2;
}


// address=[0x1486df0]
// Decompiled from char *__thiscall CStateGame::GameData(CStateGame *this)
class CGameData &  CStateGame::GameData(void) {
  
  return (char *)this + 76;
}


// address=[0x14a52f0]
// Decompiled from CStateGame *__cdecl CStateGame::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateGame::DynamicCreateFunc(void *) {
  
  CStateGame *C; // [esp+Ch] [ebp-10h]

  C = (CStateGame *)operator new(0x2D4u);
  if ( C )
    return CStateGame::CStateGame(C, a1);
  else
    return 0;
}


// address=[0x14a5370]
// Decompiled from int __thiscall CStateGame::UpdateToGuiInfoStruct(CStateGame *this)
void  CStateGame::UpdateToGuiInfoStruct(void) {
  
  int LocalPlayerId; // eax
  const wchar_t *v2; // eax
  const wchar_t *v3; // eax
  int result; // eax
  size_t v5; // [esp-4h] [ebp-1ACh]
  void *v6; // [esp+4h] [ebp-1A4h]
  size_t v7; // [esp+8h] [ebp-1A0h]
  _Cnd_internal_imp_t *v8; // [esp+Ch] [ebp-19Ch]
  _Cnd_internal_imp_t *v9; // [esp+10h] [ebp-198h]
  int v10; // [esp+18h] [ebp-190h]
  int ChatMessageFilter; // [esp+1Ch] [ebp-18Ch]
  int v12; // [esp+34h] [ebp-174h]
  int i; // [esp+3Ch] [ebp-16Ch]
  _BYTE v15[28]; // [esp+44h] [ebp-164h] BYREF
  _BYTE v16[28]; // [esp+60h] [ebp-148h] BYREF
  char v17[28]; // [esp+7Ch] [ebp-12Ch] BYREF
  char Dest[256]; // [esp+98h] [ebp-110h] BYREF
  int v19; // [esp+1A4h] [ebp-4h]

  *((_BYTE *)this + 329) = 1;
  *((_BYTE *)this + 328) = 1;
  *((_BYTE *)this + 320) = 1;
  *((_BYTE *)this + 321) = 1;
  *((_DWORD *)this + 77) = 0;
  *((_DWORD *)this + 79) = CGameSettings::GetGfxTextureQuality();
  *((_DWORD *)this + 81) = (unsigned __int8)CGameSettings::GetGfxFiltering();
  *((_DWORD *)this + 78) = CGameSettings::GetGfxHighestResolution();
  *((_DWORD *)this + 94) = 3;
  *((_DWORD *)this + 96) = CGameSettings::GetMsgHistory();
  *((_DWORD *)this + 95) = CGameSettings::GetMsgLevelMask();
  *((_DWORD *)this + 83) = 1;
  *((_BYTE *)this + 353) = CGameSettings::GetSoundFxOn() != 0;
  *((_DWORD *)this + 84) = CGameSettings::GetSoundFXVolume();
  *((_BYTE *)this + 352) = CGameSettings::GetMusicOn() != 0;
  *((_DWORD *)this + 85) = CGameSettings::GetMusicVolume();
  *((_BYTE *)this + 354) = CGameSettings::GetVoiceChatOn() != 0;
  *((_DWORD *)this + 86) = CGameSettings::GetVoiceChatVolume();
  *((_DWORD *)this + 87) = CGameSettings::GetVoiceChatMicro();
  *((_BYTE *)this + 355) = CGameSettings::GetUserMP3() != 0;
  *((_DWORD *)this + 89) = 2;
  if ( CGameData::IsTutorial(g_pGameData) )
    *((_DWORD *)this + 90) = 1;
  else
    *((_DWORD *)this + 90) = CGameSettings::GetExtendedTooltip();
  *((_BYTE *)this + 364) = CGameSettings::GetBorderScrollEnabled();
  *((_DWORD *)this + 92) = CGameSettings::GetScrollStepValue();
  *((_BYTE *)this + 372) = CGameSettings::GetAlwaysUrgentMsg();
  *((_DWORD *)this + 97) = 4;
  *((_DWORD *)this + 99) = *(_DWORD *)(g_pGameType + 112);
  *((_DWORD *)this + 100) = CPlayerManager::GetLocalPlayerId() - 1;
  ChatMessageFilter = CGameSettings::GetChatMessageFilter();
  v12 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v10 = CAlliances::AllianceId(LocalPlayerId);
  for ( i = 1; i <= CPlayerManager::LastPlayerId(); ++i )
  {
    if ( CPlayerManager::IsAI(i) )
    {
      *((_BYTE *)this + 40 * i + 400) = 0;
      if ( CPlayerManager::GetPlayerControl(i) == 2 )
        *((_DWORD *)this + 10 * i + 99) = 3;
      else
        *((_DWORD *)this + 10 * i + 99) = 4;
    }
    else
    {
      *((_BYTE *)this + 40 * i + 400) = (ChatMessageFilter & (1 << (i - 1))) != 0;
      *((_DWORD *)this + 10 * i + 99) = 2;
    }
    *((_DWORD *)this + 10 * i + 98) = CPlayerManager::Color(i);
    *((_BYTE *)this + 40 * i + 401) = CAlliances::AllianceId(i) != v10;
    v9 = (_Cnd_internal_imp_t *)CPlayerManager::Name(v16, i);
    v19 = 0;
    v2 = (const wchar_t *)std::wstring::c_str(v9);
    v5 = j__wcslen(v2);
    v8 = (_Cnd_internal_imp_t *)CPlayerManager::Name(v17, i);
    v3 = (const wchar_t *)std::wstring::c_str(v8);
    v7 = j__wcstombs(Dest, v3, v5);
    std::wstring::~wstring(v17);
    v19 = -1;
    std::wstring::~wstring(v16);
    if ( v7 >= 0x100 )
      j____report_rangecheckfailure();
    Dest[v7] = 0;
    v6 = std::string::string(v15, Dest);
    std::string::operator=((char *)this + 40 * i + 364, v6);
    std::string::~string(v15);
    if ( *((_BYTE *)this + 40 * i + 400) )
      v12 |= 1 << (i - 1);
  }
  CGameSettings::SetChatMessageFilter(v12);
  result = CGameSettings::GetAIDifficulty();
  dword_4031CFC = result;
  return result;
}


// address=[0x14a5950]
// Decompiled from void __thiscall CStateGame::UpdateFromGuiInfoStruct(CStateGame *this)
void  CStateGame::UpdateFromGuiInfoStruct(void) {
  
  int v1; // [esp+0h] [ebp-18h]
  int v2; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]

  CGameSettings::SetGfxTextureQuality(*((_DWORD *)this + 79) != 0);
  CGameSettings::SetGfxFiltering(*((_DWORD *)this + 81) != 0);
  CGameSettings::SetMsgHistory(*((_DWORD *)this + 96));
  CGameSettings::SetMsgLevelMask(*((_DWORD *)this + 95));
  CGameSettings::SetSoundFXOn(*((unsigned __int8 *)this + 353));
  CGameSettings::SetSoundFXVolume(*((_DWORD *)this + 84));
  CGameSettings::SetMusicOn(*((unsigned __int8 *)this + 352));
  CGameSettings::SetMusicVolume(*((_DWORD *)this + 85));
  CGameSettings::SetVoiceChatOn(*((unsigned __int8 *)this + 354));
  CGameSettings::SetVoiceChatVolume(*((_DWORD *)this + 86));
  CGameSettings::SetVoiceChatMicro(*((_DWORD *)this + 87));
  CGameSettings::SetUserMP3(*((_BYTE *)this + 355) != 0);
  CGameSettings::SetExtendedTooltip(*((_DWORD *)this + 90));
  CGameSettings::SetBorderScrollEnabled(*((_BYTE *)this + 364));
  CGameSettings::SetScrollStepValue(*((_DWORD *)this + 92));
  CGameSettings::SetAlwaysUrgentMsg(*((_BYTE *)this + 372));
  IGuiEngine::EnableTooltipsExt((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 90) != 0);
  CGuiEventHandler::RecalcDialogPos((CGuiEventHandler *)g_pGuiMainEvents, 0);
  v2 = 0;
  for ( i = 1; i <= CPlayerManager::LastPlayerId(); ++i )
  {
    if ( CPlayerManager::IsAI(i) )
      *((_BYTE *)this + 40 * i + 400) = 0;
    if ( *((_BYTE *)this + 40 * i + 400) )
      v1 = 1 << (i - 1);
    else
      v1 = 0;
    v2 |= v1;
  }
  CGameSettings::SetChatMessageFilter(v2);
}


// address=[0x14a5b90]
// Decompiled from void __thiscall CStateGame::UpdateMusicSettings(CStateGame *this)
void  CStateGame::UpdateMusicSettings(void) {
  
  int LocalPlayerId; // eax
  void *v2; // eax
  wchar_t *v3; // eax
  int v4; // [esp+4h] [ebp-44h]
  _BYTE v6[28]; // [esp+1Ch] [ebp-2Ch] BYREF
  int v7; // [esp+44h] [ebp-4h]

  CTrace::Print(
    "StateGame: Applying new sound settings: Music %u, Sound %u, MicVol %u, PlbkVol %u",
    *((_DWORD *)this + 85),
    *((_DWORD *)this + 84),
    *((_DWORD *)this + 86),
    *((_DWORD *)this + 87));
  if ( *((_BYTE *)this + 352) )
    CSoundManager::SetMusicVolume((CSoundManager *)g_pSoundManager, *((_DWORD *)this + 85));
  else
    CSoundManager::SetMusicVolume((CSoundManager *)g_pSoundManager, 0);
  if ( *((_BYTE *)this + 353) )
    CSoundManager::SetSoundVolume((CSoundManager *)g_pSoundManager, *((_DWORD *)this + 84));
  else
    CSoundManager::SetSoundVolume((CSoundManager *)g_pSoundManager, 0);
  if ( *((_BYTE *)this + 354) )
    ISoundEngine::VCSetMicVolume((ISoundEngine *)g_pSoundEngine, *((_DWORD *)this + 86));
  else
    ISoundEngine::VCSetMicVolume((ISoundEngine *)g_pSoundEngine, 0);
  if ( *((_BYTE *)this + 354) )
    ISoundEngine::VCSetVolume((ISoundEngine *)g_pSoundEngine, *((_DWORD *)this + 87));
  else
    ISoundEngine::VCSetVolume((ISoundEngine *)g_pSoundEngine, 0);
  if ( *((_BYTE *)this + 355) )
  {
    CSoundManager::PlayDirectory((wchar_t *)L"Snd\\User");
  }
  else
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    v2 = (void *)CPlayerManager::PlayerInfo(LocalPlayerId);
    v4 = CPlayerInfo::Race(v2);
    std::wstring::wstring(v6);
    v7 = 0;
    if ( (*(unsigned __int8 (__thiscall **)(void *, _BYTE *, const wchar_t *, int))(*(_DWORD *)g_pCDDrive + 8))(
           g_pCDDrive,
           v6,
           L"Snd\\Romans*.mp3",
           196611) )
    {
      v3 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v6);
      CSoundManager::PlayBackgroundMusic(v4, 0, v3);
    }
    v7 = -1;
    std::wstring::~wstring(v6);
  }
}


// address=[0x14a5d70]
// Decompiled from char __thiscall CStateGame::IsInMinimap(CStateGame *this, struct tagPOINT *a2, struct tagPOINT *a3)
bool  CStateGame::IsInMinimap(struct tagPOINT *,struct tagPOINT *) {
  
  struct tagPOINT v4; // [esp+0h] [ebp-10h]

  v4.y = a2->y - 8;
  if ( v4.y > 160 )
    return 0;
  v4.x = a2->x - 15 - (160 - v4.y) / 2;
  if ( v4.x > 0xA0u )
    return 0;
  if ( v4.y < 0 )
    return 0;
  if ( a3 )
    *a3 = v4;
  return 1;
}


// address=[0x14a5e00]
// Decompiled from bool __thiscall CStateGame::RenderFrame(CStateGame *this)
bool  CStateGame::RenderFrame(void) {
  
  DWORD Time; // [esp+0h] [ebp-Ch]
  bool v4; // [esp+Bh] [ebp-1h]

  Time = timeGetTime();
  v4 = IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  CGameData::SetLastFrameRendered((CStateGame *)((char *)this + 76), 1);
  *((_DWORD *)this + 2) = timeGetTime() - Time;
  return v4;
}


// address=[0x14a5e50]
// Decompiled from void __stdcall CStateGame::PerformCommand(char a1, int a2, int a3, int a4, int a5, int a6, int a7)
void  CStateGame::PerformCommand(std::string) {
  
  int LocalPlayerId; // eax
  unsigned int v8; // eax
  CEvn_Event *v9; // [esp+10h] [ebp-58h]
  void *v10; // [esp+18h] [ebp-50h]
  _BYTE *v11; // [esp+1Ch] [ebp-4Ch]
  char v12; // [esp+23h] [ebp-45h]
  _BYTE v13[28]; // [esp+24h] [ebp-44h] BYREF
  CEvn_Event v14; // [esp+40h] [ebp-28h] BYREF
  int v15; // [esp+64h] [ebp-4h]

  v15 = 0;
  v10 = std::string::string(v13, "!win");
  v12 = std::operator==<char>(&a1, v10);
  std::string::~string(v13);
  if ( v12 )
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    v8 = CAlliances::AllianceId(LocalPlayerId);
    v9 = CEvn_Event::CEvn_Event(&v14, 0x37u, v8, 0, 0);
    LOBYTE(v15) = 1;
    IEventEngine::SendAMessage(g_pEvnEngine, v9);
    LOBYTE(v15) = 0;
    CEvn_Event::~CEvn_Event(&v14);
  }
  else
  {
    v11 = (_BYTE *)std::string::c_str(&a1);
    if ( v11 && *v11 )
    {
      CGameScriptManager::GetScriptEnv((CGameScriptManager *)g_pScriptMgr);
      CLua::ExecuteString(v11 + 1);
    }
  }
  v15 = -1;
  std::string::~string(&a1);
}


// address=[0x14a5f80]
// Decompiled from int __thiscall CStateGame::SetupGUI(CStateGame *this)
void  CStateGame::SetupGUI(void) {
  
  int LocalPlayerId; // eax
  size_t v2; // eax
  int v3; // eax
  int v5; // [esp+4h] [ebp-94h]
  int v7; // [esp+14h] [ebp-84h]
  _DWORD v8[26]; // [esp+1Ch] [ebp-7Ch] BYREF
  int v9; // [esp+84h] [ebp-14h] BYREF
  int v10; // [esp+94h] [ebp-4h]

  if ( g_pGUIEngine )
    CStateGame::ExitGUI(this);
  if ( g_pDialogData )
  {
    operator delete(g_pDialogData);
    g_pDialogData = 0;
  }
  CFileEx::CFileEx((CFileEx *)v8, 1);
  v10 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v7 = CPlayerManager::Race(LocalPlayerId);
  switch ( v7 )
  {
    case 1:
      CFileEx::Open(&v9, (wchar_t *)L"Menu\\GUISetVikings.DAT", 6, 0, UNUSED_ARG(), UNUSED_ARG());
      break;
    case 2:
      CFileEx::Open(&v9, (wchar_t *)L"Menu\\GUISetMayas.DAT", 6, 0, UNUSED_ARG(), UNUSED_ARG());
      break;
    case 4:
      CFileEx::Open(&v9, (wchar_t *)L"Menu\\GUISetTrojans.DAT", 6, 0, UNUSED_ARG(), UNUSED_ARG());
      break;
    default:
      CFileEx::Open(&v9, (wchar_t *)L"Menu\\GUISetRomans.DAT", 6, 0, UNUSED_ARG(), UNUSED_ARG());
      break;
  }
  v2 = CFileEx::Size(v8);
  g_pDialogData = operator new[](v2);
  v3 = CFileEx::Size(v8);
  v5 = CFileEx::Read(
         &v9,
         g_pDialogData,
         1,
         v3,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h",
         110);
  if ( v5 != CFileEx::Size(v8)
    && BBSupportDbgReport(2, "Main\\States\\StateGame.cpp", 1281, "iSize == file.Size()") == 1 )
  {
    __debugbreak();
  }
  CFileEx::Close((CFileEx *)&v9, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h", 146);
  if ( !CStateGame::InitGuiEngine(this, (char *)g_pDialogData) )
  {
    MessageBoxA(g_hWnd, "Error initializing User Interface!\nFehler beim Erstellen des User Interfaces!", "S4", 0x30u);
    j__exit(0);
  }
  IGuiEngine::EnableTooltipsExt((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 90) != 0);
  v10 = -1;
  return CFileEx::~CFileEx(v8);
}


// address=[0x14a61c0]
// Decompiled from bool __thiscall CStateGame::ExitGUI(CStateGame *this)
void  CStateGame::ExitGUI(void) {
  
  if ( g_pGuiMainEvents )
  {
    IEventEngine::UnRegisterHandle(g_pEvnEngine, (struct IEvn_Handle *)g_pGuiMainEvents);
    if ( g_pGuiMainEvents )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)g_pGuiMainEvents + 4))(g_pGuiMainEvents, 1);
    g_pGuiMainEvents = 0;
  }
  if ( g_pGUIEngine )
  {
    delete (IGuiEngine *)g_pGUIEngine;
    g_pGUIEngine = 0;
  }
  if ( !g_pDialogData )
    return IGuiEngine::EnableTooltipsExt((IGuiEngine *)g_pGUIEngine, 0);
  operator delete(g_pDialogData);
  g_pDialogData = 0;
  return IGuiEngine::EnableTooltipsExt((IGuiEngine *)g_pGUIEngine, 0);
}


// address=[0x14a62a0]
// Decompiled from char __thiscall CStateGame::InitGuiEngine(CStateGame *this, char *a2)
bool  CStateGame::InitGuiEngine(char *) {
  
  int Language; // eax
  CEvn_Event *v4; // [esp+4h] [ebp-60h]
  struct IEvn_Handle *v5; // [esp+14h] [ebp-50h]
  CGuiEventHandler *v6; // [esp+18h] [ebp-4Ch]
  IGuiEngine *v8; // [esp+20h] [ebp-44h]
  IGuiEngine *C; // [esp+24h] [ebp-40h]
  bool IsTutorial; // [esp+2Bh] [ebp-39h]
  _DWORD v11[6]; // [esp+2Ch] [ebp-38h] BYREF
  struct tagRECT Rect; // [esp+44h] [ebp-20h] BYREF
  int v13; // [esp+60h] [ebp-4h]

  if ( g_pGUIEngine )
    CStateGame::ExitGUI(this);
  C = (IGuiEngine *)operator new(0x10u);
  v13 = 0;
  if ( C )
    v8 = IGuiEngine::IGuiEngine(C);
  else
    v8 = 0;
  g_pGUIEngine = (int)v8;
  Language = CGameSettings::GetLanguage();
  IGuiEngine::Init(
    (IGuiEngine *)g_pGUIEngine,
    (struct IGfxEngine *)g_pGfxEngine,
    (struct CGfxManager *)g_pGfxManager,
    (int)a2,
    0,
    GuiDlgMinimapProc,
    Language);
  IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
  IsTutorial = CGameData::IsTutorial((CStateGame *)((char *)this + 76));
  v6 = (CGuiEventHandler *)operator new(0x44u);
  v13 = 1;
  if ( v6 )
    v5 = CGuiEventHandler::CGuiEventHandler(v6, IsTutorial);
  else
    v5 = 0;
  v13 = -1;
  g_pGuiMainEvents = (int)v5;
  IEventEngine::RegisterHandle(g_pEvnEngine, v5);
  GetClientRect(g_hWnd, &Rect);
  v4 = CEvn_Event::CEvn_Event((CEvn_Event *)v11, 0x272u, (unsigned int)&Rect, 0, 0);
  v13 = 2;
  IEventEngine::SendAMessage(g_pEvnEngine, v4);
  v13 = -1;
  CEvn_Event::~CEvn_Event(v11);
  return 1;
}


// address=[0x14a6430]
// Decompiled from int __thiscall CStateGame::EndGame(CStateGame *this)
void  CStateGame::EndGame(void) {
  
  void *v1; // esp
  char LocalPlayerId; // al
  void *Instance; // eax
  unsigned int v4; // esi
  int v5; // eax
  int v7; // [esp-9A70h] [ebp-9AD4h] BYREF
  unsigned int v8; // [esp-8h] [ebp-6Ch]
  int v9; // [esp-4h] [ebp-68h]
  int *v10; // [esp+8h] [ebp-5Ch]
  int CampaignStatus; // [esp+Ch] [ebp-58h]
  struct CEvn_Logic *v12; // [esp+10h] [ebp-54h]
  struct CEvn_Logic *v13; // [esp+14h] [ebp-50h]
  int v14; // [esp+18h] [ebp-4Ch]
  BOOL v15; // [esp+1Ch] [ebp-48h]
  CStateGame *v16; // [esp+20h] [ebp-44h]
  int v17; // [esp+24h] [ebp-40h]
  int v18; // [esp+28h] [ebp-3Ch]
  int v19; // [esp+2Ch] [ebp-38h]
  bool v20; // [esp+33h] [ebp-31h]
  _BYTE v21[32]; // [esp+34h] [ebp-30h] BYREF
  int v22; // [esp+60h] [ebp-4h]

  v16 = this;
  CEndStatistic::Init((CEndStatistic *)&g_cEndStatistic);
  v1 = alloca(39536);
  v10 = &v7;
  CStatistic::CStatistic((struct boost::exception_detail::clone_base *)&g_cStatistic);
  CEndStatistic::Update(&g_cEndStatistic);
  if ( !CGameData::IsTutorial(g_pGameData) )
  {
    if ( CGameData::GetMode(g_pGameData) == 3 )
      CGameStateHandler::Queue((int)CStateEcoStatistic::DynamicCreateFunc, 0);
    else
      CGameStateHandler::Queue((int)CStateEndStatistic::DynamicCreateFunc, 0);
  }
  v9 = 0;
  v8 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v13 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v21, 0xFA2u, 0, 0, LocalPlayerId, v8, v9);
  v12 = v13;
  v22 = 0;
  INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, v13);
  v22 = -1;
  CEvn_Logic::~CEvn_Logic(v21);
  *((_BYTE *)v16 + 295) = 0;
  INetworkEngine::EndTick((INetworkEngine *)g_pNetworkEngine);
  Instance = (void *)OnlineManager::GetInstance();
  OnlineManager::LeaveSession(Instance);
  v4 = CGameData::TeamWon((CStateGame *)((char *)v16 + 76));
  v5 = CPlayerManager::GetLocalPlayerId();
  v15 = v4 == CAlliances::AllianceId(v5);
  v20 = v15;
  if ( CGameData::IsTutorial((CStateGame *)((char *)v16 + 76)) )
  {
    v19 = 3;
  }
  else if ( *(_DWORD *)(g_pGameType + 692) == 3 )
  {
    if ( v20 )
    {
      CampaignStatus = CGameSettings::GetCampaignStatus(*(_DWORD *)(g_pGameType + 740));
      v14 = *(_DWORD *)(g_pGameType + 744) + 1;
      if ( v14 > CampaignStatus )
        CGameSettings::SetCampaignStatus(*(_DWORD *)(g_pGameType + 740), v14);
    }
    if ( *(_DWORD *)(g_pGameType + 740) == 4 && v20 && *(_DWORD *)(g_pGameType + 744) == 11 )
    {
      if ( (unsigned __int8)CGameSettings::GetShowVideos() )
        CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 6);
      v19 = 0;
    }
    else if ( *(_DWORD *)(g_pGameType + 740) == 15 && v20 )
    {
      if ( *(_DWORD *)(g_pGameType + 744) == 4 )
      {
        if ( (unsigned __int8)CGameSettings::GetShowVideos() )
          CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 9);
        v19 = 14;
      }
      if ( *(_DWORD *)(g_pGameType + 744) == 11 )
      {
        if ( (unsigned __int8)CGameSettings::GetShowVideos() )
          CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 10);
        v19 = 0;
      }
      v18 = *(_DWORD *)(g_pGameType + 744) + 1;
      v18 -= 2;
      switch ( v18 )
      {
        case 0:
        case 2:
        case 5:
        case 7:
        case 8:
          CGameStateHandler::Queue((int)CStateAOSplash::DynamicCreateFunc, *(_DWORD *)(g_pGameType + 744));
          break;
        default:
          break;
      }
      v19 = 14;
    }
    else if ( *(_DWORD *)(g_pGameType + 740) == 12 && v20 )
    {
      if ( *(_DWORD *)(g_pGameType + 744) == 1 )
        CGameStateHandler::Queue((int)CStateAOSplash::DynamicCreateFunc, -1);
      v19 = 13;
    }
    else if ( *(_DWORD *)(g_pGameType + 744) == 2
           && v20
           && (*(_DWORD *)(g_pGameType + 740) == 1
            || *(_DWORD *)(g_pGameType + 740) == 2
            || *(_DWORD *)(g_pGameType + 740) == 3) )
    {
      CGameStateHandler::Queue((int)CStateVictoryScreen::DynamicCreateFunc, *(_DWORD *)(g_pGameType + 740));
      v19 = 0;
    }
    else
    {
      v17 = *(_DWORD *)(g_pGameType + 740);
      switch ( --v17 )
      {
        case 0:
        case 1:
        case 2:
          v19 = 2;
          break;
        case 3:
          v19 = 1;
          break;
        case 4:
          v19 = 6;
          break;
        case 5:
          v19 = 8;
          break;
        case 6:
          v19 = 7;
          break;
        case 7:
        case 8:
          v19 = 9;
          break;
        case 10:
          v19 = 11;
          break;
        case 11:
          v19 = 13;
          break;
        case 12:
          v19 = 12;
          break;
        case 13:
          v19 = 15;
          break;
        case 14:
          v19 = 14;
          break;
        case 16:
        case 17:
        case 18:
        case 19:
          v19 = 16;
          break;
        case 20:
        case 21:
        case 22:
        case 23:
          v19 = 17;
          break;
        default:
          v19 = 0;
          break;
      }
    }
  }
  else
  {
    v19 = 0;
  }
  return CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, v19);
}


// address=[0x14a6900]
// Decompiled from char __thiscall CStateGame::SwitchPause(CStateGame *this)
bool  CStateGame::SwitchPause(void) {
  
  if ( CGameData::IsNetworkGame((CStateGame *)((char *)this + 76)) )
    return *((_BYTE *)this + 71);
  *((_BYTE *)this + 71) = *((_BYTE *)this + 71) == 0;
  *((_BYTE *)this + 116) = *((_BYTE *)this + 116) == 0;
  if ( *((_BYTE *)this + 71) )
  {
    dword_402F35C = IGfxEngine::GetCursorShape(g_pGfxEngine);
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 31);
    IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
  }
  else
  {
    IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 1);
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, dword_402F35C);
  }
  return *((_BYTE *)this + 71);
}


// address=[0x14a69e0]
// Decompiled from void __thiscall CStateGame::SendLogicMessage(  CStateGame *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  unsigned int a5,  unsigned int a6,  unsigned int a7)
void  CStateGame::SendLogicMessage(unsigned int,unsigned int,long,unsigned int,unsigned int,unsigned int) {
  
  _BYTE v8[32]; // [esp+8h] [ebp-30h] BYREF
  int v9; // [esp+34h] [ebp-4h]

  if ( !*((_BYTE *)this + 71) )
  {
    if ( a6 && !a7 && BBSupportDbgReportF(2, "Main\\States\\StateGame.cpp", 1395, "iSize != 0: Message: %u", a2) == 1 )
      __debugbreak();
    if ( a7 && !a6 && BBSupportDbgReportF(2, "Main\\States\\StateGame.cpp", 1399, "iSize != NULL: Message: %u", a2) == 1 )
      __debugbreak();
    if ( CPlayerManager::IsAlive(a5) )
    {
      CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, a2, a3, a4, a5, a6, a7);
      v9 = 0;
      if ( !(*(unsigned __int8 (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)this + 63) + 4))(
              *((_DWORD *)this + 63),
              v8)
        && BBSupportDbgReportF(2, "Main\\States\\StateGame.cpp", 1410, "Unable to write to Logic Message Queue ") == 1 )
      {
        __debugbreak();
      }
      v9 = -1;
      CEvn_Logic::~CEvn_Logic(v8);
    }
  }
}


// address=[0x14a6b40]
// Decompiled from bool __thiscall CStateGame::IsCursorChangeAllowed(CStateGame *this)
bool  CStateGame::IsCursorChangeAllowed(void) {
  
  return !*((_BYTE *)this + 246) && !*((_BYTE *)this + 71);
}


// address=[0x14a6b70]
// Decompiled from int __thiscall CStateGame::GetModifierState(CStateGame *this)
int  CStateGame::GetModifierState(void) {
  
  __int16 v2; // [esp+4h] [ebp-10h]
  __int16 v3; // [esp+8h] [ebp-Ch]
  __int16 v4; // [esp+Ch] [ebp-8h]
  unsigned __int16 v5; // [esp+10h] [ebp-4h]

  if ( GetAsyncKeyState(18) )
    v4 = 16;
  else
    v4 = 0;
  if ( GetAsyncKeyState(16) )
    v3 = 4;
  else
    v3 = 0;
  if ( GetAsyncKeyState(17) )
    v2 = 8;
  else
    v2 = 0;
  v5 = v2 | v3 | v4;
  if ( v5 == 24 )
    return 16;
  return v5;
}


// address=[0x14a6c20]
// Decompiled from CStateGame *__thiscall CStateGame::CStateGame(CStateGame *this, void *a2)
 CStateGame::CStateGame(void *) {
  
  bool IsMCD2TextureSet; // al
  int VirtualTick; // esi
  int ValidTick; // esi
  int LocalPlayerId; // eax
  float v6; // xmm0_4
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int PlayerId; // eax
  unsigned int v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // esi
  unsigned int v20; // [esp-4h] [ebp-2C8h]
  void *TypeString; // [esp+14h] [ebp-2B0h]
  int v22; // [esp+1Ch] [ebp-2A8h]
  int v23; // [esp+24h] [ebp-2A0h]
  void *v24; // [esp+30h] [ebp-294h]
  int v25; // [esp+34h] [ebp-290h]
  int v26; // [esp+3Ch] [ebp-288h]
  CEvn_Event *v27; // [esp+4Ch] [ebp-278h]
  CEvn_Event *v28; // [esp+50h] [ebp-274h]
  CEvn_Event *v29; // [esp+58h] [ebp-26Ch]
  void *ModeString; // [esp+60h] [ebp-264h]
  int v31; // [esp+68h] [ebp-25Ch]
  int Instance; // [esp+6Ch] [ebp-258h]
  int i; // [esp+7Ch] [ebp-248h]
  bool v34; // [esp+81h] [ebp-243h]
  char v36[88]; // [esp+88h] [ebp-23Ch] BYREF
  char v37[88]; // [esp+E0h] [ebp-1E4h] BYREF
  _BYTE v38[28]; // [esp+138h] [ebp-18Ch] BYREF
  _BYTE v39[28]; // [esp+154h] [ebp-170h] BYREF
  _BYTE v40[28]; // [esp+170h] [ebp-154h] BYREF
  _BYTE v41[28]; // [esp+18Ch] [ebp-138h] BYREF
  _BYTE v42[28]; // [esp+1A8h] [ebp-11Ch] BYREF
  _BYTE v43[28]; // [esp+1C4h] [ebp-100h] BYREF
  _DWORD v44[6]; // [esp+1E0h] [ebp-E4h] BYREF
  _DWORD v45[6]; // [esp+1F8h] [ebp-CCh] BYREF
  _DWORD v46[6]; // [esp+210h] [ebp-B4h] BYREF
  _BYTE v47[28]; // [esp+228h] [ebp-9Ch] BYREF
  _BYTE v48[28]; // [esp+244h] [ebp-80h] BYREF
  _BYTE v49[28]; // [esp+260h] [ebp-64h] BYREF
  _BYTE v50[28]; // [esp+27Ch] [ebp-48h] BYREF
  _BYTE v51[28]; // [esp+298h] [ebp-2Ch] BYREF
  int v52; // [esp+2C0h] [ebp-4h]

  CGameState::CGameState(this);
  v52 = 0;
  *(_DWORD *)this = &CStateGame::_vftable_;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  std::vector<CStateGame::CRC_HistoryEntry>::vector<CStateGame::CRC_HistoryEntry>();
  std::vector<CStateGame::Random_HistoryEntry>::vector<CStateGame::Random_HistoryEntry>();
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_BYTE *)this + 68) = 0;
  *((_BYTE *)this + 69) = 0;
  *((_BYTE *)this + 70) = 0;
  *((_BYTE *)this + 71) = 0;
  *((_BYTE *)this + 72) = 0;
  CGameData::CGameData((CStateGame *)((char *)this + 76));
  *((_BYTE *)this + 244) = 0;
  *((_BYTE *)this + 245) = 0;
  *((_BYTE *)this + 246) = 0;
  *((_BYTE *)this + 247) = 0;
  *((_BYTE *)this + 248) = 0;
  *((_DWORD *)this + 63) = 0;
  *((_DWORD *)this + 64) = 0;
  *((_DWORD *)this + 65) = 0;
  *((_DWORD *)this + 70) = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 72) = 0;
  *((_BYTE *)this + 292) = 0;
  *((_BYTE *)this + 293) = 0;
  *((_BYTE *)this + 294) = 0;
  *((_BYTE *)this + 295) = 0;
  *((_DWORD *)this + 74) = 0;
  *((_BYTE *)this + 300) = 0;
  *((_DWORD *)this + 76) = 0;
  CChatInfo::CChatInfo((CStateGame *)((char *)this + 388));
  LOBYTE(v52) = 4;
  if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
  {
    Instance = UPlay::UPlayManager::GetInstance();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)Instance + 52))(Instance, 3);
  }
  else
  {
    v31 = UPlay::UPlayManager::GetInstance();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v31 + 52))(v31, 4);
  }
  IsMCD2TextureSet = CGameType::IsMCD2TextureSet((CGameType *)g_pGameType);
  CGfxManager::EnableMCD2Textures((CGfxManager *)g_pGfxManager, IsMCD2TextureSet);
  g_uDbgTickCounter = 0;
  g_iGameSpeed = 1;
  if ( g_pGfxEngine )
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_BYTE *)this + 68) = 0;
  std::string::string(v51, "none");
  LOBYTE(v52) = 5;
  v22 = g_pCfgMgr->GetStringValue((int)v38, "COMMANDLINE", "events", (int)v51);
  LOBYTE(v52) = 6;
  std::operator==<char>(v22, "record");
  LOBYTE(v52) = 5;
  std::string::~string(v38);
  LOBYTE(v52) = 4;
  std::string::~string(v51);
  std::string::string(v47, "none");
  LOBYTE(v52) = 7;
  v23 = g_pCfgMgr->GetStringValue((int)v43, "COMMANDLINE", "events", (int)v47);
  LOBYTE(v52) = 8;
  v34 = std::operator==<char>(v23, "play");
  LOBYTE(v52) = 7;
  std::string::~string(v43);
  LOBYTE(v52) = 4;
  std::string::~string(v47);
  v25 = g_pCfgMgr->GetIntValue("COMMANDLINE", "stopevent", 0);
  if ( v34 )
  {
    std::string::string(v48, "slot0.rec");
    LOBYTE(v52) = 10;
    v26 = g_pCfgMgr->GetStringValue((int)v40, "COMMANDLINE", "eventfile", (int)v48);
    LOBYTE(v52) = 11;
    IEventEngine::PlayEvents(v26, v25);
    LOBYTE(v52) = 10;
    std::string::~string(v40);
    LOBYTE(v52) = 4;
    std::string::~string(v48);
  }
  else
  {
    v24 = std::string::string(v39, "slot0.rec");
    LOBYTE(v52) = 9;
    IEventEngine::RecordEvents(g_pEvnEngine, v24);
    LOBYTE(v52) = 4;
    std::string::~string(v39);
  }
  g_pGame = (int)this;
  g_pGameData = (CStateGame *)((char *)this + 76);
  if ( a2 && BBSupportDbgReport(2, "Main\\States\\StateGame.cpp", 246, "!_pvParam") == 1 )
    __debugbreak();
  *((_DWORD *)this + 72) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 70) = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 74) = INetworkEngine::GetValidTick((INetworkEngine *)g_pNetworkEngine);
  *((_BYTE *)this + 300) = 0;
  *((_DWORD *)this + 76) = 2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_BYTE *)this + 248) = 0;
  *((_BYTE *)this + 244) = 0;
  *((_BYTE *)this + 245) = 0;
  *((_BYTE *)this + 246) = 0;
  *((_BYTE *)this + 247) = 0;
  *((_BYTE *)this + 293) = 0;
  *((_BYTE *)this + 69) = 0;
  *((_BYTE *)this + 70) = 0;
  *((_BYTE *)this + 71) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_BYTE *)this + 292) = 0;
  *((_BYTE *)this + 295) = 0;
  *((_BYTE *)this + 294) = 0;
  *((_BYTE *)this + 294) = 1;
  *((_BYTE *)this + 72) = 1;
  VirtualTick = INetworkEngine::GetVirtualTick((INetworkEngine *)g_pNetworkEngine);
  *((_DWORD *)CStateGame::GameData((CStateGame *)g_pGame) + 1) = VirtualTick;
  ValidTick = INetworkEngine::GetValidTick((INetworkEngine *)g_pNetworkEngine);
  *(_DWORD *)CStateGame::GameData((CStateGame *)g_pGame) = ValidTick;
  IGfxEngine::SetTickCounterAdress((IGfxEngine *)g_pGfxEngine, (unsigned int *)this + 20);
  IEventEngine::SetTickPointer(g_pEvnEngine, (CStateGame *)((char *)this + 80));
  CTextMsgHandler::Init();
  *((_DWORD *)this + 22) = *(_DWORD *)(g_pGameType + 56);
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 21) = *(_DWORD *)(g_pGameType + 56);
  RegisterClasses();
  if ( (unsigned __int8)CGameRun::Init() )
  {
    CMinimapHandler::Init();
    CGameStateHandler::RebuildGfxEngine(1);
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
    CGameSettings::SetChatMessageFilter(-1);
    CStateGame::UpdateToGuiInfoStruct(this);
    CStateGame::UpdateMusicSettings(this);
    CStateGame::SetupGUI(this);
    if ( CGameData::IsTutorial((CStateGame *)((char *)this + 76)) )
      CTutorial::Init((CTutorial *)&g_cTutorial);
    CStateGame::NotifyGfxEngine(this);
    CStateGame::UpdateClientSize(this);
    CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
    CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF);
    if ( !*(_BYTE *)(g_pGame + 117) )
    {
      v20 = *(_DWORD *)(g_pGameType + 4 * CPlayerManager::GetLocalPlayerId() + 292);
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      CStateGame::SetViewPos(this, *(_DWORD *)(g_pGameType + 4 * LocalPlayerId + 256), v20);
    }
    v6 = (float)(unsigned int)(*((_DWORD *)this + 26) - 917504);
    v27 = CEvn_Event::CEvn_Event((CEvn_Event *)v44, 0x25Du, 0, (int)(float)((float)(v6 * 100.0) / 3801088.0), 0);
    LOBYTE(v52) = 12;
    IEventEngine::SendAMessage(g_pEvnEngine, v27);
    LOBYTE(v52) = 4;
    CEvn_Event::~CEvn_Event(v44);
    CStateGame::EnableOrDisableDebugString(this, 0);
    BBSupportTracePrintF(1, "GameInfo:");
    BBSupportTracePrintF(1, "--------------------------------------------------");
    BBSupportTracePrintF(1, (char *)&byte_373E2D7);
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v37);
    LOBYTE(v52) = 13;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
      v49,
      g_pGameType + 28);
    LOBYTE(v52) = 14;
    v7 = (const char *)std::string::c_str(v49);
    BBSupportTracePrintF(1, "MapName:        %s", v7);
    LOBYTE(v52) = 13;
    std::string::~string(v49);
    LOBYTE(v52) = 4;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v37);
    TypeString = (void *)CGameData::GetTypeString(v41);
    LOBYTE(v52) = 15;
    v8 = (const char *)std::string::c_str(TypeString);
    BBSupportTracePrintF(1, "GameType:       %s", v8);
    LOBYTE(v52) = 4;
    std::string::~string(v41);
    ModeString = (void *)CGameData::GetModeString(v42);
    LOBYTE(v52) = 16;
    v9 = (const char *)std::string::c_str(ModeString);
    BBSupportTracePrintF(1, "GameMode:       %s", v9);
    LOBYTE(v52) = 4;
    std::string::~string(v42);
    if ( *(_BYTE *)(g_pGameType + 696) )
      BBSupportTracePrintF(1, "Saved Game:     %s", "Yes");
    else
      BBSupportTracePrintF(1, "Saved Game:     %s", "No");
    if ( *(_BYTE *)(g_pGameType + 696) )
    {
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v36);
      LOBYTE(v52) = 17;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
        v50,
        g_pGameType + 704);
      LOBYTE(v52) = 18;
      v10 = (const char *)std::string::c_str(v50);
      BBSupportTracePrintF(1, "Save File:     %s", v10);
      LOBYTE(v52) = 17;
      std::string::~string(v50);
      LOBYTE(v52) = 4;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v36);
    }
    BBSupportTracePrintF(1, "Starting Tick:  %d", *(_DWORD *)(g_pGameType + 700));
    BBSupportTracePrintF(1, "Time Delay:\t    %d ms", *(_DWORD *)(g_pGameType + 660));
    PlayerId = CPlayerManager::LastPlayerId();
    BBSupportTracePrintF(1, "Playercount:    %d", PlayerId);
    if ( INetworkEngine::IsHost((INetworkEngine *)g_pNetworkEngine) )
      BBSupportTracePrintF(1, "Network:\t\t   %s", "Host");
    else
      BBSupportTracePrintF(1, "Network:\t\t   %s", "Client");
    BBSupportTracePrintF(1, "--------------------------------------------------");
    if ( CGameData::IsGameWon((CStateGame *)((char *)this + 76))
      && CGameData::GetMode((CStateGame *)((char *)this + 76)) != 5 )
    {
      v12 = CGameData::TeamWon((CStateGame *)((char *)this + 76));
      v13 = CPlayerManager::GetLocalPlayerId();
      if ( v12 == CAlliances::AllianceId(v13) )
      {
        v29 = CEvn_Event::CEvn_Event((CEvn_Event *)v45, 0x261u, 1u, 0, 0);
        LOBYTE(v52) = 19;
        IEventEngine::SendAMessage(g_pEvnEngine, v29);
        LOBYTE(v52) = 4;
        CEvn_Event::~CEvn_Event(v45);
        v14 = CPlayerManager::GetLocalPlayerId();
        v15 = CPlayerManager::Color(v14);
        CTextMsgHandler::AddTextMsg(2255, v15, 1);
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pFogging + 40))(g_pFogging, 1);
      }
      else
      {
        if ( CGameData::IsNetworkGame((CStateGame *)((char *)this + 76)) )
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pFogging + 40))(g_pFogging, 1);
        v28 = CEvn_Event::CEvn_Event((CEvn_Event *)v46, 0x261u, 0, 0, 0);
        LOBYTE(v52) = 20;
        IEventEngine::SendAMessage(g_pEvnEngine, v28);
        LOBYTE(v52) = 4;
        CEvn_Event::~CEvn_Event(v46);
        v16 = CPlayerManager::GetLocalPlayerId();
        v17 = CPlayerManager::Color(v16);
        CTextMsgHandler::AddTextMsg(2254, v17, 1);
        for ( i = 1; i < CPlayerManager::LastPlayerId(); ++i )
        {
          v18 = CAlliances::AllianceId(i);
          if ( v18 != CGameData::TeamWon((CStateGame *)((char *)this + 76)) )
            CPlayerManager::PlayerDied(i);
        }
      }
    }
  }
  else
  {
    CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2400);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
  }
  return this;
}


// address=[0x14a7a50]
// Decompiled from void __thiscall CStateGame::~CStateGame(CStateGame *this)
 CStateGame::~CStateGame(void) {
  
  *(_DWORD *)this = &CStateGame::_vftable_;
  g_pGameData = 0;
  *((_BYTE *)this + 70) = 0;
  CGameRun::Exit();
  if ( CGameData::IsTutorial((CStateGame *)((char *)this + 76)) )
    CTutorial::Kill((CTutorial *)&g_cTutorial);
  CStateGame::ExitGUI(this);
  CTextMsgHandler::Kill();
  IGfxEngine::SetTickCounterAdress((IGfxEngine *)g_pGfxEngine, 0);
  IEventEngine::SetTickPointer(g_pEvnEngine, 0);
  g_pGame = 0;
  if ( g_pNetworkEngine )
  {
    (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
    g_pNetworkEngine = 0;
  }
  if ( g_pGameType )
  {
    delete (CGameType *)g_pGameType;
    g_pGameType = 0;
  }
  CSoundManager::StopMusic(g_pSoundManager);
  CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
  CChatInfo::~CChatInfo((CStateGame *)((char *)this + 388));
  CGameData::~CGameData((CStateGame *)((char *)this + 76));
  std::vector<CStateGame::Random_HistoryEntry>::~vector<CStateGame::Random_HistoryEntry>();
  std::vector<CStateGame::CRC_HistoryEntry>::~vector<CStateGame::CRC_HistoryEntry>();
  CGameState::~CGameState(this);
}


// address=[0x14a7bc0]
// Decompiled from char __thiscall CStateGame::Perform(CStateGame *this)
bool  CStateGame::Perform(void) {
  
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  unsigned int BytesPerSecond; // eax
  DWORD v8; // eax
  unsigned int v9; // eax
  int VirtualTick; // esi
  struct CGameData *v11; // eax
  char LocalPlayerId; // al
  char v13; // al
  struct CGameData *v14; // eax
  char v15; // al
  LARGE_INTEGER PerformanceCount; // [esp+50h] [ebp-150h] BYREF
  _DWORD v17[2]; // [esp+58h] [ebp-148h] BYREF
  _DWORD v18[2]; // [esp+60h] [ebp-140h] BYREF
  CEvn_Event *v19; // [esp+68h] [ebp-138h]
  CEvn_Event *v20; // [esp+6Ch] [ebp-134h]
  DWORD v21; // [esp+70h] [ebp-130h]
  float v22; // [esp+74h] [ebp-12Ch]
  float v23; // [esp+78h] [ebp-128h]
  float v24; // [esp+7Ch] [ebp-124h]
  struct CEvn_Logic *v25; // [esp+80h] [ebp-120h]
  struct CEvn_Logic *v26; // [esp+84h] [ebp-11Ch]
  struct CEvn_Logic *v27; // [esp+88h] [ebp-118h]
  struct CEvn_Logic *v28; // [esp+8Ch] [ebp-114h]
  int v29; // [esp+90h] [ebp-110h]
  DWORD Time; // [esp+94h] [ebp-10Ch]
  float v31; // [esp+98h] [ebp-108h]
  float v32; // [esp+9Ch] [ebp-104h]
  CEvn_Event *v33; // [esp+A0h] [ebp-100h]
  CEvn_Event *v34; // [esp+A4h] [ebp-FCh]
  CEvn_Event *v35; // [esp+A8h] [ebp-F8h]
  CEvn_Event *v36; // [esp+ACh] [ebp-F4h]
  int Number; // [esp+B0h] [ebp-F0h]
  float v38; // [esp+B4h] [ebp-ECh]
  int v39; // [esp+B8h] [ebp-E8h]
  int v40; // [esp+BCh] [ebp-E4h]
  int v41; // [esp+C0h] [ebp-E0h]
  int v42; // [esp+C4h] [ebp-DCh]
  int v43; // [esp+C8h] [ebp-D8h]
  int v44; // [esp+CCh] [ebp-D4h]
  const char *v45; // [esp+D0h] [ebp-D0h]
  int v46; // [esp+D4h] [ebp-CCh]
  unsigned int ValidTick; // [esp+D8h] [ebp-C8h]
  unsigned int v48; // [esp+DCh] [ebp-C4h]
  char v49; // [esp+E3h] [ebp-BDh]
  CStateGame *v50; // [esp+E4h] [ebp-BCh]
  _BYTE v51[32]; // [esp+E8h] [ebp-B8h] BYREF
  _BYTE v52[32]; // [esp+108h] [ebp-98h] BYREF
  _DWORD v53[6]; // [esp+128h] [ebp-78h] BYREF
  _DWORD v54[6]; // [esp+140h] [ebp-60h] BYREF
  _DWORD v55[6]; // [esp+158h] [ebp-48h] BYREF
  _BYTE v56[24]; // [esp+170h] [ebp-30h] BYREF
  _DWORD *v57; // [esp+188h] [ebp-18h]
  __int16 v58; // [esp+18Ch] [ebp-14h]
  int v59; // [esp+19Ch] [ebp-4h]

  v50 = this;
  v49 = 0;
  CGameData::SetLastFrameRendered((CStateGame *)((char *)this + 76), 0);
  switch ( g_iGameSpeed )
  {
    case 0:
      return 1;
    case 99:
      v48 = 71;
      g_iGameSpeed = 0;
      CStateGame::RenderFrame(v50);
      IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
      break;
    case 1:
      v48 = 71;
      break;
    case 2:
      v48 = 47;
      break;
    default:
      v48 = 0x47u / (g_iGameSpeed - 1);
      break;
  }
  if ( (unsigned __int8)CGameSettings::GetBorderScrollEnabled() && CGameSettings::GetGfxFullscreenEnabled() )
    CStateGame::HandleBorderScroll(v50);
  if ( !*((_BYTE *)v50 + 293) )
  {
    v36 = CEvn_Event::CEvn_Event((CEvn_Event *)v54, 0x27u, 0, 0, 0);
    v35 = v36;
    v59 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v36);
    v59 = -1;
    CEvn_Event::~CEvn_Event(v54);
    v34 = CEvn_Event::CEvn_Event((CEvn_Event *)v55, 0x26Fu, 7u, 0, 0);
    v33 = v34;
    v59 = 1;
    IEventEngine::SendAMessage(g_pEvnEngine, v34);
    v59 = -1;
    CEvn_Event::~CEvn_Event(v55);
    v19 = CEvn_Event::CEvn_Event((CEvn_Event *)v53, 0x6Au, 7u, 0, 0);
    v20 = v19;
    v59 = 2;
    IEventEngine::SendAMessage(g_pEvnEngine, v19);
    v59 = -1;
    CEvn_Event::~CEvn_Event(v53);
    CTextMsgHandler::SendAllMessages(0, 1, 1);
    if ( CGameData::GetMode((CStateGame *)((char *)v50 + 76)) == 3 )
    {
      IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 611, 1);
      IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 8, 929, 1);
    }
  }
  if ( !IEventEngine::DispatchSystemMessages(g_pEvnEngine) )
    return 0;
  INetworkEngine::DeliverNetMessages((INetworkEngine *)g_pNetworkEngine);
  if ( *((_BYTE *)v50 + 70) )
  {
    if ( dword_402F350 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402F350);
      if ( dword_402F350 == -1 )
      {
        dword_402F34C = QueryPerformanceFrequency(&g_lFrequency);
        j___Init_thread_footer(&dword_402F350);
      }
    }
    if ( dword_402F358 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402F358);
      if ( dword_402F358 == -1 )
      {
        dword_402F354 = g_lFrequency.QuadPart / 1000;
        j___Init_thread_footer(&dword_402F358);
      }
    }
    v46 = dword_402F354 * v48;
    QueryPerformanceCounter(&PerformanceCount);
    v21 = PerformanceCount.LowPart - ::PerformanceCount.LowPart;
    v38 = (float)((float)(PerformanceCount.LowPart - ::PerformanceCount.LowPart) * 100.0) / (float)v46;
    if ( v38 != 0.0 )
    {
      v43 = g_iAITicks;
      v2 = (float)(unsigned int)g_iAITicks;
      v32 = (float)(v2 * 100.0) / (float)v46;
      v42 = g_iLogicTicks;
      v3 = (float)(unsigned int)g_iLogicTicks;
      v31 = (float)(v3 * 100.0) / (float)v46;
      v41 = g_iTilingTicks;
      v4 = (float)(unsigned int)g_iTilingTicks;
      v23 = (float)(v4 * 100.0) / (float)v46;
      v40 = g_iScriptingTicks;
      v5 = (float)(unsigned int)g_iScriptingTicks;
      v24 = (float)(v5 * 100.0) / (float)v46;
      v39 = g_iAnimalTicks;
      v6 = (float)(unsigned int)g_iAnimalTicks;
      v22 = (float)(v6 * 100.0) / (float)v46;
      BytesPerSecond = INetworkEngine::GetBytesPerSecond((INetworkEngine *)g_pNetworkEngine);
      CDebugFkt::SetFrameCounter(0.0, v38, v31, v32, v23, v24, v22, BytesPerSecond);
    }
    if ( !*((_DWORD *)v50 + 1) )
      *((_DWORD *)v50 + 1) = timeGetTime();
    Time = timeGetTime();
    v29 = Time - *((_DWORD *)v50 + 1);
    if ( (unsigned __int8)CGameStateHandler::IsGrabbing() )
    {
      CStateGame::RenderFrame(v50);
      IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    }
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    *((_DWORD *)v50 + 3) >>= 1;
    if ( v29 >= 0 )
    {
      v9 = CStaticConfigVarInt::operator int(&unk_402ECA8);
      if ( *((_DWORD *)v50 + 3) >= v9 )
      {
        v49 = 1;
      }
      else
      {
        CStateGame::RenderFrame(v50);
        *((_DWORD *)v50 + 3) |= 0x80000000;
      }
    }
    else
    {
      CStateGame::RenderFrame(v50);
      *((_DWORD *)v50 + 3) |= 0x80000000;
      while ( *((_DWORD *)v50 + 2) + timeGetTime() < *((_DWORD *)v50 + 1) )
      {
        IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
        if ( !IEventEngine::DispatchSystemMessages(g_pEvnEngine) )
          return 0;
        IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
        CStateGame::RenderFrame(v50);
      }
      Number = timeGetTime() - *((_DWORD *)v50 + 1);
      if ( Number < 0 )
      {
        v8 = j__abs(Number);
        Sleep(v8);
      }
    }
    QueryPerformanceCounter(&::PerformanceCount);
    if ( !*((_BYTE *)v50 + 71) )
    {
      v44 = 0;
      do
      {
        VirtualTick = INetworkEngine::GetVirtualTick((INetworkEngine *)g_pNetworkEngine);
        *((_DWORD *)CStateGame::GameData((CStateGame *)g_pGame) + 1) = VirtualTick;
        if ( !IEventEngine::DispatchSystemMessages(g_pEvnEngine) )
          return 0;
        INetworkEngine::DeliverNetMessages((INetworkEngine *)g_pNetworkEngine);
        if ( INetworkEngine::StartNewTick((INetworkEngine *)g_pNetworkEngine, 0) )
        {
          INetworkEngine::StartNewTick((INetworkEngine *)g_pNetworkEngine, 1);
          ValidTick = INetworkEngine::GetValidTick((INetworkEngine *)g_pNetworkEngine);
          v11 = CStateGame::GameData((CStateGame *)g_pGame);
          *(_DWORD *)v11 = ValidTick;
          g_uDbgTickCounter = ValidTick;
          if ( !*(_DWORD *)CStateGame::GameData((CStateGame *)g_pGame)
            && BBSupportDbgReport(2, "Main\\States\\StateGame.cpp", 682, "g_pGame->GameData().m_uTickCounter != 0") == 1 )
          {
            __debugbreak();
          }
          if ( *((_BYTE *)v50 + 295) )
          {
            CStateGame::EndGame(v50);
            return 1;
          }
          CStateGame::CheckAutosaveTimer(v50);
          if ( *((_BYTE *)v50 + 300) )
          {
            LocalPlayerId = CPlayerManager::GetLocalPlayerId();
            CEvn_Logic::CEvn_Logic((CEvn_Logic *)v56, 0xFA8u, *((_DWORD *)v50 + 76), 0, LocalPlayerId, 0, 0);
            v59 = 3;
            if ( std::wstring::length(&unk_403037C) )
            {
              v57 = std::wstring::c_str((_Cnd_internal_imp_t *)&unk_403037C);
              v58 = 2 * std::wstring::size(&unk_403037C);
            }
            INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v56);
            *((_DWORD *)v50 + 74) = ValidTick;
            *((_BYTE *)v50 + 300) = 0;
            v59 = -1;
            CEvn_Logic::~CEvn_Logic(v56);
          }
          if ( CGameData::IsNetworkGame((CStateGame *)((char *)v50 + 76)) )
          {
            if ( (COMMUNICATION_TICK_VALUE & IEventEngine::GetCurrentTickCounter(g_pEvnEngine)) == 0 )
            {
              v45 = CGameData::Rand(g_pGameData);
              v18[1] = v45;
              v18[0] = ValidTick;
              std::vector<CStateGame::Random_HistoryEntry>::push_back(v18);
              v13 = CPlayerManager::GetLocalPlayerId();
              v28 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v51, 0xFA3u, (unsigned int)v45, ValidTick, v13, 0, 0);
              v27 = v28;
              v59 = 4;
              INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, v28);
              v59 = -1;
              CEvn_Logic::~CEvn_Logic(v51);
              v14 = CStateGame::GameData((CStateGame *)g_pGame);
              *((_DWORD *)v50 + 4) = *(_DWORD *)v14;
            }
            if ( (COMMUNICATION_TICK_VALUE & IEventEngine::GetCurrentTickCounter(g_pEvnEngine)) == 0 )
            {
              v45 = (const char *)CMapObjectMgr::CRCLogicUpdate();
              v17[1] = v45;
              v17[0] = ValidTick;
              std::vector<CStateGame::CRC_HistoryEntry>::push_back(v17);
              v15 = CPlayerManager::GetLocalPlayerId();
              v26 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v52, 0xFA6u, (unsigned int)v45, ValidTick, v15, 0, 0);
              v25 = v26;
              v59 = 5;
              INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, v26);
              v59 = -1;
              CEvn_Logic::~CEvn_Logic(v52);
            }
          }
          CGameRun::Run();
          if ( !(unsigned __int8)CGameType::IsHost(g_pGameType) )
            Sleep(0xDCu);
          INetworkEngine::EndTick((INetworkEngine *)g_pNetworkEngine);
          ++v44;
        }
      }
      while ( *((_BYTE *)v50 + 69) && v44 < 840 && !CGameData::IsNetworkGame((CStateGame *)((char *)v50 + 76)) );
      if ( *((_BYTE *)v50 + 69) )
      {
        if ( !v49 )
          IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
        IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 1, 0);
        v49 = 0;
        *((_DWORD *)v50 + 1) = v48 + timeGetTime();
        *((_BYTE *)v50 + 69) = 0;
      }
    }
    if ( !v49 )
      IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    *((_DWORD *)v50 + 1) += v48;
    if ( !CGameData::IsNetworkGame((CStateGame *)((char *)v50 + 76)) && v48 == 71 )
      *((_DWORD *)v50 + 1) = timeGetTime() + 71;
  }
  else
  {
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    CStateGame::RenderFrame(v50);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  }
  if ( *((_BYTE *)v50 + 293) )
    return 1;
  INetworkEngine::GameInitalized((INetworkEngine *)g_pNetworkEngine);
  *((_BYTE *)v50 + 293) = 1;
  return 1;
}


// address=[0x14a87c0]
// Decompiled from double __thiscall CStateGame::GetZoomFactor(CStateGame *this)
float  CStateGame::GetZoomFactor(void) {
  
  float v1; // xmm0_4

  v1 = (float)(unsigned int)(*((_DWORD *)this + 26) - 917504);
  return (float)((float)(v1 * 100.0) / 3801088.0);
}


// address=[0x14a8820]
// Decompiled from int __thiscall CStateGame::NotifyGfxEngine(CStateGame *this)
void  CStateGame::NotifyGfxEngine(void) {
  
  int v1; // ecx
  int v2; // eax
  unsigned __int16 *MapObjectPtr; // eax
  struct T_GFX_MAP_ELEMENT *LandscapePtr; // [esp-4h] [ebp-8h]
  unsigned __int16 *DecoObjectPtr; // [esp-4h] [ebp-8h]

  LandscapePtr = (struct T_GFX_MAP_ELEMENT *)CWorldManager::GetLandscapePtr();
  v2 = CWorldManager::Width(v1);
  IGfxEngine::SetGfxLayerAccess((IGfxEngine *)g_pGfxEngine, v2, LandscapePtr);
  DecoObjectPtr = (unsigned __int16 *)CWorldManager::GetDecoObjectPtr();
  MapObjectPtr = CWorldManager::GetMapObjectPtr();
  IGfxEngine::SetObjectLayerAccess((IGfxEngine *)g_pGfxEngine, MapObjectGetGfxInfo, MapObjectPtr, DecoObjectPtr);
  IGfxEngine::SetMiniMapColorCallback(
    (IGfxEngine *)g_pGfxEngine,
    (struct SGfxColor *(__cdecl *)(unsigned int))CWorldManager::GetMiniMapColor);
  IGfxEngine::SetIconCallbacks(
    (IGfxEngine *)g_pGfxEngine,
    (void (__cdecl *)(int))CWorldManager::WorldSetNumberOfNextLine,
    (unsigned __int8 (__cdecl *)(int))CWorldManager::WorldGetIconObjectByX);
  IGfxEngine::EnableIconLayer((IGfxEngine *)g_pGfxEngine, 0);
  return (*(int (__thiscall **)(void *, CStateGame *))(*(_DWORD *)g_pFogging + 16))(g_pFogging, this);
}


// address=[0x14a88b0]
// Decompiled from char __thiscall CStateGame::EnableOrDisableDebugString(CStateGame *this, bool a2)
bool  CStateGame::EnableOrDisableDebugString(bool) {
  
  char v4; // [esp+7h] [ebp-1h]

  v4 = *((_BYTE *)this + 68);
  if ( a2 )
    IGfxEngine::EnableDebugStringCallback((IGfxEngine *)g_pGfxEngine, (char *(__cdecl *)())CDebugFkt::DebugString);
  else
    IGfxEngine::EnableDebugStringCallback((IGfxEngine *)g_pGfxEngine, 0);
  *((_BYTE *)this + 68) = a2;
  return v4;
}


// address=[0x14a8900]
// Decompiled from bool __thiscall CStateGame::CanSave(CStateGame *this)
bool  CStateGame::CanSave(void) {
  
  return !*((_BYTE *)this + 71)
      && !CGameData::IsTutorial((CStateGame *)((char *)this + 76))
      && (!CGameData::IsNetworkGame((CStateGame *)((char *)this + 76))
       || (unsigned int)(CGameData::GetTickCounter((char *)this + 76) - *((_DWORD *)this + 74)) > 0x348)
      && !CGameData::IsLadder((CStateGame *)((char *)this + 76));
}


// address=[0x14a8980]
// Decompiled from _DWORD *__thiscall CStateGame::SaveGame(int this, unsigned int a2)
void  CStateGame::SaveGame(enum SaveType) {
  
  _DWORD *result; // eax
  CEvn_Event v4; // [esp+8h] [ebp-28h] BYREF
  int v5; // [esp+2Ch] [ebp-4h]

  if ( CGameData::IsNetworkGame((CGameData *)(this + 76)) )
  {
    *(_BYTE *)(this + 300) = 1;
    result = (_DWORD *)a2;
    *(_DWORD *)(this + 304) = a2;
  }
  else
  {
    CEvn_Event::CEvn_Event(&v4, 0x29u, a2, 0, 0);
    v5 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, &v4);
    v5 = -1;
    return CEvn_Event::~CEvn_Event(&v4);
  }
  return result;
}


// address=[0x14ac920]
// Decompiled from void __thiscall CStateGame::ZoomIn(CStateGame *this, int a2)
void  CStateGame::ZoomIn(int) {
  
  int *v2; // [esp+0h] [ebp-Ch]

  if ( *((_DWORD *)this + 26) + 20000 * a2 <= (unsigned int)&dword_420320[98104] )
    v2 = (int *)(*((_DWORD *)this + 26) + 20000 * a2);
  else
    v2 = &dword_420320[98104];
  CStateGame::UpdateTriangleSizePreservingWorldPosition(this, v2);
  CStateGame::UpdateZoomFactor(this);
}


// address=[0x14ac980]
// Decompiled from void __thiscall CStateGame::ZoomOut(CStateGame *this, int a2)
void  CStateGame::ZoomOut(int) {
  
  int v2; // [esp+0h] [ebp-Ch]

  if ( *((_DWORD *)this + 26) - 20000 * a2 >= 917504 )
    v2 = *((_DWORD *)this + 26) - 20000 * a2;
  else
    v2 = 917504;
  CStateGame::UpdateTriangleSizePreservingWorldPosition(this, v2);
  CStateGame::UpdateZoomFactor(this);
}


// address=[0x14ac9e0]
// Decompiled from CStateGame *__thiscall CStateGame::UpdateTriangleSizePreservingWorldPosition(CStateGame *this, int a2)
void  CStateGame::UpdateTriangleSizePreservingWorldPosition(int) {
  
  CStateGame *result; // eax
  double v3; // [esp+0h] [ebp-Ch]

  v3 = (double)a2 / (double)*((int *)this + 26);
  *((_DWORD *)this + 24) = (int)((double)*((int *)this + 24) * v3);
  result = this;
  *((_DWORD *)this + 25) = (int)((double)*((int *)this + 25) * v3);
  *((_DWORD *)this + 26) = a2;
  return result;
}


// address=[0x14aca40]
// Decompiled from _DWORD *__thiscall CStateGame::UpdateZoomFactor(CStateGame *this)
void  CStateGame::UpdateZoomFactor(void) {
  
  CEvn_Event v3; // [esp+18h] [ebp-28h] BYREF
  int v4; // [esp+3Ch] [ebp-4h]

  CStateGame::VerifyWorldOffset(this);
  CEvn_Event::CEvn_Event(
    &v3,
    0x25Du,
    0,
    (int)((double)(unsigned int)(*((_DWORD *)this + 26) - 917504) * 100.0 / 3801088.0),
    0);
  v4 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v3);
  v4 = -1;
  return CEvn_Event::~CEvn_Event(&v3);
}


// address=[0x14acb10]
// Decompiled from void __thiscall CStateGame::VerifyWorldOffset(CStateGame *this)
void  CStateGame::VerifyWorldOffset(void) {
  
  int v1; // [esp+Ch] [ebp-3Ch]
  int v2; // [esp+10h] [ebp-38h]
  float v3; // [esp+28h] [ebp-20h]
  float v4; // [esp+30h] [ebp-18h]
  int OutputHeight; // [esp+34h] [ebp-14h]
  int OutputWidth; // [esp+38h] [ebp-10h]
  int v7; // [esp+3Ch] [ebp-Ch]

  if ( *((_DWORD *)this + 25) >= *((_DWORD *)this + 23) * (*((int *)this + 26) >> 16) )
  {
    if ( *((_DWORD *)this + 25) > *((_DWORD *)this + 22) * (*((int *)this + 26) >> 16) / 2 )
      *((_DWORD *)this + 25) = *((_DWORD *)this + 22) * (*((int *)this + 26) >> 16) / 2;
  }
  else
  {
    *((_DWORD *)this + 25) = *((_DWORD *)this + 23) * (*((int *)this + 26) >> 16);
  }
  v7 = *((_DWORD *)this + 25);
  if ( *((_DWORD *)this + 24) >= *((_DWORD *)this + 23) * (*((int *)this + 26) >> 16) - v7 )
  {
    if ( *((_DWORD *)this + 24) > *((_DWORD *)this + 22) * (*((int *)this + 26) >> 16) - v7 )
      *((_DWORD *)this + 24) = *((_DWORD *)this + 22) * (*((int *)this + 26) >> 16) - v7;
  }
  else
  {
    *((_DWORD *)this + 24) = *((_DWORD *)this + 23) * (*((int *)this + 26) >> 16) - v7;
  }
  OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  v4 = ((double (__stdcall *)(_DWORD, _DWORD, _DWORD))sub_14B4620)(
         (float)OutputWidth,
         LODWORD(FLOAT_800_0),
         LODWORD(FLOAT_2560_0));
  v3 = ((double (__stdcall *)(_DWORD, _DWORD, _DWORD))sub_14B4620)(
         (float)OutputHeight,
         LODWORD(FLOAT_600_0),
         LODWORD(FLOAT_1440_0));
  v1 = *((_DWORD *)this + 24) - (int)(float)((float)(OutputWidth + 100) + (float)(v4 * 40.0)) / 2;
  v2 = *((_DWORD *)this + 25) - (int)(float)((float)(OutputHeight + 300) + (float)(v3 * 60.0)) / 2;
  IGfxEngine::SetTriangleSize((IGfxEngine *)g_pGfxEngine, *((_DWORD *)this + 26));
  IGfxEngine::SetScrollOffsets((IGfxEngine *)g_pGfxEngine, v1, v2);
}


// address=[0x14acd30]
// Decompiled from void __thiscall CStateGame::HandleBorderScroll(CStateGame *this)
void  CStateGame::HandleBorderScroll(void) {
  
  if ( *((_DWORD *)this + 64) )
    CStateGame::ScrollHorizontal(this, *((_DWORD *)this + 64) == 2);
  if ( *((_DWORD *)this + 65) )
    CStateGame::ScrollVertical(this, *((_DWORD *)this + 65) == 4);
  CStateGame::VerifyWorldOffset(this);
}


// address=[0x14acdb0]
// Decompiled from void __thiscall CStateGame::ReadyToGo(CStateGame *this)
void  CStateGame::ReadyToGo(void) {
  
  *((_BYTE *)this + 70) = 1;
  *((_DWORD *)this + 72) = timeGetTime();
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
}


// address=[0x14acde0]
// Decompiled from void __thiscall CStateGame::SetViewPos(CStateGame *this, unsigned int a2, unsigned int a3)
void  CStateGame::SetViewPos(unsigned int,unsigned int) {
  
  signed int v3; // kr00_4

  v3 = a3 * (*((int *)this + 26) >> 16);
  *((_DWORD *)this + 24) = a2 * (*((int *)this + 26) >> 16) - v3 / 2;
  *((_DWORD *)this + 25) = v3 / 2;
  CStateGame::VerifyWorldOffset(this);
}


// address=[0x14ace40]
// Decompiled from int __thiscall CStateGame::UpdateClientSize(CStateGame *this)
void  CStateGame::UpdateClientSize(void) {
  
  int result; // eax

  *((_DWORD *)this + 66) = 210;
  *((_DWORD *)this + 67) = 0;
  *((_DWORD *)this + 68) = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  result = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  *((_DWORD *)this + 69) = result;
  if ( g_pGUIEngine )
    result = IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
  *((_DWORD *)this + 66) = 210;
  return result;
}


// address=[0x14aceb0]
// Decompiled from char __thiscall CStateGame::OnEvent(CStateGame *this, struct CEvn_Event *a2)
bool  CStateGame::OnEvent(class CEvn_Event &) {
  
  char result; // al
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  const wchar_t *v13; // eax
  const wchar_t *v14; // eax
  int v15; // eax
  int v16; // eax
  const wchar_t *v17; // eax
  const wchar_t *v18; // eax
  int v19; // eax
  int Instance; // eax
  const char *v21; // eax
  unsigned int v22; // eax
  int LocalPlayerId; // eax
  int *v24; // eax
  int v25; // edx
  int v26; // eax
  int *v27; // eax
  int v28; // edx
  unsigned int v29; // eax
  unsigned __int16 v30; // ax
  unsigned int v31; // eax
  int v32; // eax
  int v33; // eax
  unsigned int v34; // eax
  int v35; // eax
  int v36; // eax
  unsigned int v37; // eax
  const char *v38; // eax
  int v39; // eax
  int v40; // eax
  int RealPlayerName; // eax
  CGameData *v42; // eax
  unsigned int v43; // eax
  CGameData *v44; // eax
  const char *v45; // eax
  char v46; // al
  char ChatMessageFilter; // si
  char v48; // al
  const wchar_t *v49; // eax
  int v50; // eax
  int v51; // eax
  char v52; // al
  CPlayerInfo *v53; // eax
  pairNode *v54; // eax
  unsigned int v55; // eax
  CPlayerInfo *v56; // eax
  pairNode *v57; // eax
  unsigned int v58; // eax
  char v59; // al
  char v60; // al
  char v61; // al
  char v62; // [esp-1Ch] [ebp-C30h] BYREF
  int v63; // [esp-18h] [ebp-C2Ch]
  int v64; // [esp-14h] [ebp-C28h]
  int v65; // [esp-10h] [ebp-C24h] BYREF
  int v66; // [esp-Ch] [ebp-C20h] BYREF
  int v67; // [esp-8h] [ebp-C1Ch]
  size_t v68; // [esp-4h] [ebp-C18h]
  const char *v69; // [esp+0h] [ebp-C14h]
  void *v70; // [esp+4h] [ebp-C10h]
  struct tagPOINT v71; // [esp+8h] [ebp-C0Ch] BYREF
  _BYTE v72[12]; // [esp+10h] [ebp-C04h] BYREF
  _BYTE v73[12]; // [esp+1Ch] [ebp-BF8h] BYREF
  _BYTE v74[12]; // [esp+28h] [ebp-BECh] BYREF
  _BYTE v75[12]; // [esp+34h] [ebp-BE0h] BYREF
  _BYTE v76[12]; // [esp+40h] [ebp-BD4h] BYREF
  _BYTE v77[12]; // [esp+4Ch] [ebp-BC8h] BYREF
  int v78; // [esp+58h] [ebp-BBCh]
  char *v79; // [esp+5Ch] [ebp-BB8h]
  int v80; // [esp+60h] [ebp-BB4h]
  int *v81; // [esp+64h] [ebp-BB0h]
  int v82; // [esp+6Ch] [ebp-BA8h]
  int v83; // [esp+70h] [ebp-BA4h]
  double v84; // [esp+74h] [ebp-BA0h]
  int *v85; // [esp+80h] [ebp-B94h]
  int v86; // [esp+84h] [ebp-B90h]
  int v87; // [esp+88h] [ebp-B8Ch]
  int v88; // [esp+8Ch] [ebp-B88h]
  int *v89; // [esp+90h] [ebp-B84h]
  int v90; // [esp+94h] [ebp-B80h]
  int v91; // [esp+98h] [ebp-B7Ch]
  char *v92; // [esp+9Ch] [ebp-B78h]
  int v93; // [esp+A0h] [ebp-B74h]
  int *v94; // [esp+A4h] [ebp-B70h]
  int v95; // [esp+A8h] [ebp-B6Ch]
  char *v96; // [esp+ACh] [ebp-B68h]
  int v97; // [esp+B0h] [ebp-B64h]
  _BYTE v98[12]; // [esp+B4h] [ebp-B60h] BYREF
  struct tagPOINT v99; // [esp+C0h] [ebp-B54h] BYREF
  struct tagPOINT v100; // [esp+C8h] [ebp-B4Ch] BYREF
  struct tagPOINT v101; // [esp+D0h] [ebp-B44h] BYREF
  int v102; // [esp+D8h] [ebp-B3Ch]
  int v103; // [esp+DCh] [ebp-B38h]
  int v104; // [esp+E0h] [ebp-B34h]
  int v105; // [esp+E4h] [ebp-B30h]
  double v106; // [esp+E8h] [ebp-B2Ch]
  _BYTE v107[12]; // [esp+F0h] [ebp-B24h] BYREF
  CEvn_Event *v108; // [esp+FCh] [ebp-B18h]
  _Cnd_internal_imp_t *v109; // [esp+100h] [ebp-B14h]
  _Cnd_internal_imp_t *v110; // [esp+104h] [ebp-B10h]
  _Cnd_internal_imp_t *v111; // [esp+108h] [ebp-B0Ch]
  size_t v112; // [esp+10Ch] [ebp-B08h]
  int FirstBuildingId; // [esp+110h] [ebp-B04h]
  _Cnd_internal_imp_t *v114; // [esp+114h] [ebp-B00h]
  _Cnd_internal_imp_t *v115; // [esp+118h] [ebp-AFCh]
  _Cnd_internal_imp_t *v116; // [esp+11Ch] [ebp-AF8h]
  size_t v117; // [esp+120h] [ebp-AF4h]
  void *v118; // [esp+124h] [ebp-AF0h]
  void *v119; // [esp+128h] [ebp-AECh]
  struct CEvn_Event *v120; // [esp+12Ch] [ebp-AE8h]
  int lparam; // [esp+130h] [ebp-AE4h] BYREF
  int v122; // [esp+134h] [ebp-AE0h]
  std::_Iterator_base12 *v123; // [esp+138h] [ebp-ADCh]
  std::_Iterator_base12 *v124; // [esp+13Ch] [ebp-AD8h]
  struct std::_Iterator_base12 *v125; // [esp+140h] [ebp-AD4h]
  struct std::_Iterator_base12 *v126; // [esp+144h] [ebp-AD0h]
  int v127; // [esp+148h] [ebp-ACCh] BYREF
  int v128; // [esp+14Ch] [ebp-AC8h]
  std::_Iterator_base12 *v129; // [esp+150h] [ebp-AC4h]
  std::_Iterator_base12 *v130; // [esp+154h] [ebp-AC0h]
  struct std::_Iterator_base12 *v131; // [esp+158h] [ebp-ABCh]
  int v132; // [esp+15Ch] [ebp-AB8h]
  unsigned int v133; // [esp+160h] [ebp-AB4h]
  int v134; // [esp+164h] [ebp-AB0h] BYREF
  int v135; // [esp+168h] [ebp-AACh] BYREF
  int Number; // [esp+16Ch] [ebp-AA8h]
  int v137; // [esp+170h] [ebp-AA4h]
  int ClosestMapPoint; // [esp+174h] [ebp-AA0h]
  int v139; // [esp+178h] [ebp-A9Ch]
  int v140; // [esp+180h] [ebp-A94h]
  int v141; // [esp+184h] [ebp-A90h]
  unsigned int v142; // [esp+188h] [ebp-A8Ch]
  unsigned int v143; // [esp+18Ch] [ebp-A88h]
  unsigned int v144; // [esp+190h] [ebp-A84h]
  int v145; // [esp+194h] [ebp-A80h]
  struct std::_Iterator_base12 *v146; // [esp+198h] [ebp-A7Ch]
  struct tagPOINT Point; // [esp+19Ch] [ebp-A78h] BYREF
  CEvn_Event *v148; // [esp+1A4h] [ebp-A70h]
  CEvn_Event *v149; // [esp+1A8h] [ebp-A6Ch]
  CEvn_Event *v150; // [esp+1ACh] [ebp-A68h]
  void **v151; // [esp+1B0h] [ebp-A64h]
  void **v152; // [esp+1B4h] [ebp-A60h]
  unsigned int v153; // [esp+1B8h] [ebp-A5Ch]
  int v154; // [esp+1BCh] [ebp-A58h]
  CEvn_Event *v155; // [esp+1C0h] [ebp-A54h]
  void *v156; // [esp+1C8h] [ebp-A4Ch]
  CEvn_Logic *v157; // [esp+1CCh] [ebp-A48h]
  unsigned int v158; // [esp+1D4h] [ebp-A40h]
  CEvn_Logic *v159; // [esp+1D8h] [ebp-A3Ch]
  CEvn_Logic *v160; // [esp+1E0h] [ebp-A34h]
  void *v161; // [esp+1E8h] [ebp-A2Ch]
  void *v162; // [esp+1F0h] [ebp-A24h]
  CEvn_Event *v163; // [esp+1F8h] [ebp-A1Ch]
  CEvn_Event *v164; // [esp+200h] [ebp-A14h]
  CEvn_Event *v165; // [esp+208h] [ebp-A0Ch]
  unsigned int v166; // [esp+210h] [ebp-A04h]
  unsigned int v167; // [esp+214h] [ebp-A00h]
  CEvn_Event *v168; // [esp+218h] [ebp-9FCh]
  _Cnd_internal_imp_t *v169; // [esp+220h] [ebp-9F4h]
  int v170; // [esp+224h] [ebp-9F0h]
  CEvn_Event *v171; // [esp+228h] [ebp-9ECh]
  CEvn_Event *v172; // [esp+230h] [ebp-9E4h]
  CEvn_Event *v173; // [esp+238h] [ebp-9DCh]
  CEvn_Event *v174; // [esp+240h] [ebp-9D4h]
  CEvn_Event *v175; // [esp+248h] [ebp-9CCh]
  CEvn_Event *v176; // [esp+250h] [ebp-9C4h]
  CEvn_Event *v177; // [esp+258h] [ebp-9BCh]
  CEvn_Event *v178; // [esp+260h] [ebp-9B4h]
  CEvn_Event *v179; // [esp+268h] [ebp-9ACh]
  int CursorShape; // [esp+270h] [ebp-9A4h]
  CEvn_Event *v181; // [esp+274h] [ebp-9A0h]
  int v182; // [esp+27Ch] [ebp-998h]
  int v183; // [esp+280h] [ebp-994h]
  wchar_t *S2; // [esp+284h] [ebp-990h]
  CEvn_Event *v185; // [esp+288h] [ebp-98Ch]
  struct tagPOINT v186; // [esp+28Ch] [ebp-988h] BYREF
  LONG OutputWidth; // [esp+294h] [ebp-980h]
  LONG OutputHeight; // [esp+298h] [ebp-97Ch]
  size_t v189; // [esp+29Ch] [ebp-978h]
  size_t v190; // [esp+2A0h] [ebp-974h]
  int v191; // [esp+2A4h] [ebp-970h]
  int v192; // [esp+2ACh] [ebp-968h]
  int v193; // [esp+2B0h] [ebp-964h]
  unsigned int v194; // [esp+2B4h] [ebp-960h]
  int (__cdecl *v195)(int, int); // [esp+2B8h] [ebp-95Ch]
  void *v196; // [esp+2BCh] [ebp-958h]
  BOOL v197; // [esp+2C0h] [ebp-954h]
  BOOL v198; // [esp+2C4h] [ebp-950h]
  int v199; // [esp+2C8h] [ebp-94Ch]
  size_t v200; // [esp+2CCh] [ebp-948h]
  int v201; // [esp+2D0h] [ebp-944h]
  int v202; // [esp+2D4h] [ebp-940h]
  int v203; // [esp+2D8h] [ebp-93Ch]
  int v204; // [esp+2DCh] [ebp-938h]
  int v205; // [esp+2E0h] [ebp-934h]
  int v206; // [esp+2E4h] [ebp-930h]
  struct CEvn_Event *v207; // [esp+2E8h] [ebp-92Ch]
  int v208; // [esp+2ECh] [ebp-928h]
  void *v209; // [esp+2F0h] [ebp-924h]
  int v210; // [esp+2F4h] [ebp-920h]
  int v211; // [esp+2F8h] [ebp-91Ch]
  int v212; // [esp+2FCh] [ebp-918h]
  unsigned int v213; // [esp+300h] [ebp-914h]
  int v214; // [esp+304h] [ebp-910h]
  int x; // [esp+308h] [ebp-90Ch]
  unsigned int v216; // [esp+30Ch] [ebp-908h]
  int v217; // [esp+310h] [ebp-904h]
  int v218; // [esp+314h] [ebp-900h]
  unsigned int v219; // [esp+318h] [ebp-8FCh]
  void *v220; // [esp+31Ch] [ebp-8F8h]
  void *v221; // [esp+320h] [ebp-8F4h]
  struct tagPOINT v222; // [esp+324h] [ebp-8F0h] BYREF
  int v223; // [esp+32Ch] [ebp-8E8h]
  void **v224; // [esp+330h] [ebp-8E4h]
  char *Source; // [esp+334h] [ebp-8E0h]
  int v226; // [esp+338h] [ebp-8DCh]
  int v227; // [esp+33Ch] [ebp-8D8h] BYREF
  int v228; // [esp+340h] [ebp-8D4h] BYREF
  int v229; // [esp+344h] [ebp-8D0h] BYREF
  int v230; // [esp+348h] [ebp-8CCh] BYREF
  int v231; // [esp+34Ch] [ebp-8C8h]
  struct CEvn_Event *v232; // [esp+350h] [ebp-8C4h]
  struct CEvn_Event *v233; // [esp+354h] [ebp-8C0h]
  void *v234; // [esp+358h] [ebp-8BCh]
  struct tagPOINT v235; // [esp+35Ch] [ebp-8B8h] BYREF
  char *v236; // [esp+364h] [ebp-8B0h]
  void *v237; // [esp+36Ch] [ebp-8A8h]
  unsigned int v238; // [esp+370h] [ebp-8A4h]
  unsigned int v239; // [esp+374h] [ebp-8A0h]
  unsigned int v240; // [esp+378h] [ebp-89Ch]
  int v241; // [esp+37Ch] [ebp-898h]
  unsigned int v242; // [esp+380h] [ebp-894h]
  struct CBuilding *n; // [esp+384h] [ebp-890h]
  signed int v244; // [esp+388h] [ebp-88Ch]
  signed int v245; // [esp+38Ch] [ebp-888h]
  unsigned int v246; // [esp+390h] [ebp-884h]
  int k; // [esp+394h] [ebp-880h]
  int wparam; // [esp+398h] [ebp-87Ch]
  void **v249; // [esp+39Ch] [ebp-878h]
  int v250; // [esp+3A0h] [ebp-874h]
  bool v251; // [esp+3A4h] [ebp-870h]
  bool v252; // [esp+3A5h] [ebp-86Fh]
  bool v253; // [esp+3A6h] [ebp-86Eh]
  char v254; // [esp+3A7h] [ebp-86Dh]
  int m; // [esp+3A8h] [ebp-86Ch]
  int j; // [esp+3ACh] [ebp-868h]
  char v257; // [esp+3B1h] [ebp-863h]
  char v258; // [esp+3B4h] [ebp-860h]
  char v259; // [esp+3B5h] [ebp-85Fh]
  char v260; // [esp+3B6h] [ebp-85Eh]
  char v261; // [esp+3B7h] [ebp-85Dh]
  int v262; // [esp+3B8h] [ebp-85Ch]
  int i; // [esp+3BCh] [ebp-858h]
  char *v264; // [esp+3C0h] [ebp-854h]
  void *v265; // [esp+3C4h] [ebp-850h]
  signed int v266; // [esp+3C8h] [ebp-84Ch]
  bool v267; // [esp+3CFh] [ebp-845h]
  bool v268; // [esp+3D0h] [ebp-844h]
  bool v269; // [esp+3D1h] [ebp-843h]
  bool v270; // [esp+3D3h] [ebp-841h]
  void **v271; // [esp+3D4h] [ebp-840h]
  void **v272; // [esp+3D8h] [ebp-83Ch]
  _BYTE *v273; // [esp+3DCh] [ebp-838h]
  bool v274; // [esp+3E3h] [ebp-831h]
  struct tagPOINT v275; // [esp+3E4h] [ebp-830h] BYREF
  size_t v276; // [esp+3ECh] [ebp-828h]
  void **v277; // [esp+3F0h] [ebp-824h]
  char *v278; // [esp+3F4h] [ebp-820h]
  _BYTE v279[32]; // [esp+3F8h] [ebp-81Ch] BYREF
  _BYTE v280[32]; // [esp+418h] [ebp-7FCh] BYREF
  struct tagRECT Rect; // [esp+438h] [ebp-7DCh] BYREF
  _BYTE v282[32]; // [esp+448h] [ebp-7CCh] BYREF
  _BYTE v283[28]; // [esp+468h] [ebp-7ACh] BYREF
  _BYTE v284[28]; // [esp+484h] [ebp-790h] BYREF
  _BYTE v285[28]; // [esp+4A0h] [ebp-774h] BYREF
  _BYTE v286[28]; // [esp+4BCh] [ebp-758h] BYREF
  _BYTE v287[28]; // [esp+4D8h] [ebp-73Ch] BYREF
  int v288[7]; // [esp+4F4h] [ebp-720h] BYREF
  _BYTE v289[28]; // [esp+510h] [ebp-704h] BYREF
  _BYTE v290[28]; // [esp+52Ch] [ebp-6E8h] BYREF
  _BYTE v291[28]; // [esp+548h] [ebp-6CCh] BYREF
  _BYTE v292[28]; // [esp+564h] [ebp-6B0h] BYREF
  CEvn_Event v293; // [esp+580h] [ebp-694h] BYREF
  CEvn_Event v294; // [esp+598h] [ebp-67Ch] BYREF
  CEvn_Event v295; // [esp+5B0h] [ebp-664h] BYREF
  CEvn_Event v296; // [esp+5C8h] [ebp-64Ch] BYREF
  CEvn_Event v297; // [esp+5E0h] [ebp-634h] BYREF
  CEvn_Event v298; // [esp+5F8h] [ebp-61Ch] BYREF
  CEvn_Event v299; // [esp+610h] [ebp-604h] BYREF
  CEvn_Event v300; // [esp+628h] [ebp-5ECh] BYREF
  CEvn_Event v301; // [esp+640h] [ebp-5D4h] BYREF
  CEvn_Event v302; // [esp+658h] [ebp-5BCh] BYREF
  CEvn_Event v303; // [esp+670h] [ebp-5A4h] BYREF
  CEvn_Event v304; // [esp+688h] [ebp-58Ch] BYREF
  CEvn_Event v305; // [esp+6A0h] [ebp-574h] BYREF
  CEvn_Event v306; // [esp+6B8h] [ebp-55Ch] BYREF
  CEvn_Event v307; // [esp+6D0h] [ebp-544h] BYREF
  CEvn_Event v308; // [esp+6E8h] [ebp-52Ch] BYREF
  CEvn_Event v309; // [esp+700h] [ebp-514h] BYREF
  CEvn_Event v310; // [esp+718h] [ebp-4FCh] BYREF
  _BYTE v311[28]; // [esp+730h] [ebp-4E4h] BYREF
  _BYTE v312[28]; // [esp+74Ch] [ebp-4C8h] BYREF
  _BYTE v313[32]; // [esp+768h] [ebp-4ACh] BYREF
  CEvn_Event v314; // [esp+788h] [ebp-48Ch] BYREF
  char v315[28]; // [esp+7A0h] [ebp-474h] BYREF
  char Destination[512]; // [esp+7BCh] [ebp-458h] BYREF
  char Str[2]; // [esp+9BCh] [ebp-258h] BYREF
  char v318; // [esp+9BEh] [ebp-256h]
  char v319; // [esp+9BFh] [ebp-255h]
  char v320[508]; // [esp+9C0h] [ebp-254h] BYREF
  char v321[36]; // [esp+BBCh] [ebp-58h] BYREF
  char Dest[36]; // [esp+BE0h] [ebp-34h] BYREF
  int v323; // [esp+C10h] [ebp-4h]

  v278 = (char *)this;
  v277 = (void **)&a2->__vftable;
  if ( a2->event <= 0x190u || (unsigned int)v277[1] >= 0x1E9 )
  {
    if ( (unsigned int)v277[1] <= 0x1388 || (unsigned int)v277[1] >= 0x13BD )
    {
      v264 = (char *)v277[1];
      if ( (unsigned int)v264 > 0xFA2 )
      {
        v264 -= 4003;
        switch ( (unsigned int)v264 )
        {
          case 0u:
            v233 = a2;
            if ( CPlayerManager::IsAlive(BYTE2(a2[1].event))
              && (LocalPlayerId = CPlayerManager::GetLocalPlayerId(), CPlayerManager::IsAlive(LocalPlayerId)) )
            {
              lparam = v233->lparam;
              v68 = *(_DWORD *)std::_Iterator_base12::operator=((int)&lparam);
              v94 = &v65;
              v122 = std::end<std::vector<CStateGame::Random_HistoryEntry>>((int)&v65, (int)(v278 + 36));
              v93 = v122;
              v323 = 5;
              v92 = &v62;
              v91 = std::begin<std::vector<CStateGame::Random_HistoryEntry>>((int)&v62, (int)(v278 + 36));
              v323 = -1;
              v90 = std::find_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>,_lambda_03817ffcf3c1f43769e18417d11e255d_>(
                      (int)v107,
                      v62,
                      v63,
                      v64,
                      v65,
                      v66,
                      v67,
                      v68);
              v323 = 6;
              v123 = (std::_Iterator_base12 *)std::vector<CStateGame::Random_HistoryEntry>::end((int)v75);
              v124 = v123;
              LOBYTE(v323) = 7;
              v261 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::operator==(v123);
              LOBYTE(v323) = 6;
              std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v75);
              if ( v261 )
                CTextMsgHandler::AddTextMsg("DESYNC: Rand History search failed!", 0, 0, 0, 1);
              v24 = (int *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::operator*(v107);
              v25 = v24[1];
              v102 = *v24;
              v103 = v25;
              if ( v233->wparam != v25 )
              {
                dword_402F3C8 = timeGetTime();
                CTextMsgHandler::AddTextMsg("DESYNC: Game not synchronized anymore(Rand)!", 0, 0, 0, 1);
                BBSupportTracePrintF(3, "DESYNC: Game not synchronized anymore (random check failed)!");
                v260 = 1;
                IMessageTracer::PrintMessages(g_pMsgTracer, 0x80000001, 0);
                IMessageTracer::PrintMessages(g_pMsgTracer2, 0x80000001, 0);
                IMessageTracer::Done(g_pMsgTracer);
                IMessageTracer::Done(g_pMsgTracer2);
                CMapObjectMgr::DbgPrintAllEntities(g_pMapObjectMgr, 0x80000003);
                if ( BBSupportDbgReport(
                       1,
                       "Main\\States\\StateGameII.cpp",
                       641,
                       "DESYNC: Game not synchronized anymore!") == 1 )
                  __debugbreak();
              }
              if ( (unsigned int)std::vector<CStateGame::Random_HistoryEntry>::size(v278 + 36) > 0x14 )
              {
                v125 = (struct std::_Iterator_base12 *)std::begin<std::vector<CStateGame::Random_HistoryEntry>>(
                                                         (int)v73,
                                                         (int)(v278 + 36));
                v126 = v125;
                LOBYTE(v323) = 8;
                v89 = &v66;
                v88 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v125);
                v83 = std::vector<CStateGame::Random_HistoryEntry>::erase((int)v74, v66, v67, v68);
                std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v74);
                LOBYTE(v323) = 6;
                std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v73);
              }
              v254 = 1;
              v323 = -1;
              std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v107);
              result = v254;
            }
            else
            {
              result = 1;
            }
            break;
          case 2u:
            v249 = v277;
            v276 = 0;
            v170 = CAlliances::AllianceId(*((unsigned __int8 *)v277 + 30));
            Str[0] = 91;
            Str[1] = v170 + 48;
            v318 = 93;
            v319 = 32;
            v276 = 4;
            v68 = 160;
            v169 = (_Cnd_internal_imp_t *)CPlayerManager::Name((int)v290, *((unsigned __int8 *)v277 + 30));
            v49 = (const wchar_t *)std::wstring::c_str(v169);
            v276 = j__wcstombs(v320, v49, 0xA0u) + 4;
            std::wstring::~wstring(v290);
            if ( v276 == -1 )
            {
              v68 = 0;
              v67 = 0;
              v66 = 0;
              v50 = CPlayerManager::Color(*((unsigned __int8 *)v249 + 30));
              CTextMsgHandler::AddTextMsg((char *)v249[6], v50, 0, 0, 0);
            }
            Str[v276++] = 58;
            Str[v276++] = 32;
            v200 = 512 - j__strlen(Str);
            Source = (char *)v249[6];
            if ( j__strlen(Source) > v200 )
              Source[v200] = 0;
            j__strcpy_0(&Str[v276], Source);
            v51 = CPlayerManager::Color(*((unsigned __int8 *)v249 + 30));
            CTextMsgHandler::AddChatMsg(Str, v51);
            result = 1;
            break;
          case 3u:
            v232 = a2;
            if ( CPlayerManager::IsAlive(BYTE2(a2[1].event))
              && (v26 = CPlayerManager::GetLocalPlayerId(), CPlayerManager::IsAlive(v26)) )
            {
              if ( CGameData::IsNetworkGame((CGameData *)(v278 + 76)) )
              {
                v127 = v232->lparam;
                v68 = *(_DWORD *)std::_Iterator_base12::operator=((int)&v127);
                v81 = &v65;
                v128 = std::end<std::vector<CStateGame::CRC_HistoryEntry>>((int)&v65, (int)(v278 + 20));
                v80 = v128;
                v323 = 9;
                v79 = &v62;
                v87 = std::begin<std::vector<CStateGame::CRC_HistoryEntry>>((int)&v62, (int)(v278 + 20));
                v323 = -1;
                v86 = std::find_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>,_lambda_9d6ec2be6c5ed87acf2c2ca5fd2e9b85_>(
                        (int)v98,
                        v62,
                        v63,
                        v64,
                        v65,
                        v66,
                        v67,
                        v68);
                v323 = 10;
                v129 = (std::_Iterator_base12 *)std::vector<CStateGame::CRC_HistoryEntry>::end((int)v72);
                v130 = v129;
                LOBYTE(v323) = 11;
                v259 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::operator==(v129);
                LOBYTE(v323) = 10;
                std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v72);
                if ( v259 )
                  CTextMsgHandler::AddTextMsg("DESYNC: CRC History search failed!", 0, 0, 0, 1);
                v27 = (int *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::operator*(v98);
                v28 = v27[1];
                v104 = *v27;
                v105 = v28;
                if ( v232->wparam != v28 )
                {
                  dword_402F3CC = timeGetTime();
                  CTextMsgHandler::AddTextMsg("DESYNC: Game not synchronized anymore(CRC)!", 0, 0, 0, 1);
                  BBSupportTracePrintF(3, "DESYNC: Game not synchronized anymore (update check failed)!");
                  v258 = 1;
                  IMessageTracer::PrintMessages(g_pMsgTracer, -2147483647, 0);
                  IMessageTracer::PrintMessages(g_pMsgTracer2, -2147483647, 0);
                  IMessageTracer::Done(g_pMsgTracer);
                  IMessageTracer::Done(g_pMsgTracer2);
                  CMapObjectMgr::DbgPrintAllEntities(g_pMapObjectMgr, -2147483645);
                  if ( BBSupportDbgReport(
                         1,
                         "Main\\States\\StateGameII.cpp",
                         714,
                         "DESYNC: Game not synchronized anymore!") == 1 )
                    __debugbreak();
                }
                if ( (unsigned int)std::vector<CStateGame::CRC_HistoryEntry>::size(v278 + 20) > 0x14 )
                {
                  v146 = (struct std::_Iterator_base12 *)std::begin<std::vector<CStateGame::CRC_HistoryEntry>>(
                                                           (int)v76,
                                                           (int)(v278 + 20));
                  v131 = v146;
                  LOBYTE(v323) = 12;
                  v85 = &v66;
                  v78 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v146);
                  v82 = std::vector<CStateGame::CRC_HistoryEntry>::erase((int)v77, v66, v67, v68);
                  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v77);
                  LOBYTE(v323) = 10;
                  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v76);
                }
                v323 = -1;
                std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v98);
              }
              result = 1;
            }
            else
            {
              result = 1;
            }
            break;
          case 4u:
            *((_DWORD *)v278 + 1) += v277[2];
            CTrace::Print("StateGame: Time adjusted from network! %d", v277[2]);
            result = 1;
            break;
          case 5u:
            if ( (unsigned __int8)CGameType::IsHost(g_pGameType) )
            {
              v207 = a2;
              S2 = (wchar_t *)a2[1].__vftable;
              std::wstring::wstring(S2, LOWORD(a2[1].event) >> 1);
              v323 = 14;
              std::wstring::operator=((int)v312);
              v323 = -1;
              std::wstring::~wstring(v312);
LABEL_269:
              CursorShape = IGfxEngine::GetCursorShape(g_pGfxEngine);
              IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
              std::wstring::wstring(v315);
              v323 = 15;
              wparam = a2->wparam;
              if ( wparam )
              {
                if ( CGameData::IsNetworkGame((CGameData *)(v278 + 76)) )
                {
                  v182 = sub_14B19A0((int)v291, wparam);
                  std::wstring::operator=(v182);
                  std::wstring::~wstring(v291);
                }
                else if ( wparam == 1 )
                {
                  std::wstring::operator=(v315, (wchar_t *)L"QuickSave.sav");
                }
                else if ( wparam == 2 )
                {
                  std::wstring::operator=(v315, (wchar_t *)L"AutoSave.sav");
                }
              }
              else
              {
                v183 = std::operator+<wchar_t>((int)v288, (int)&unk_403037C, (wchar_t *)L".sav");
                std::wstring::operator=(v183);
                std::wstring::~wstring(v288);
              }
              if ( wparam != 2 )
              {
                IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 611, 1);
                IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 8, 928, 1);
              }
              v38 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v315);
              CTrace::Print("StateGameII: Saving %s", v38);
              if ( (unsigned __int8)CGameRun::SaveGame((int)v315, (int)v69) )
              {
                *((_DWORD *)v278 + 74) = CGameData::GetTickCounter(g_pGameData);
                v270 = 1;
                if ( wparam == 2 )
                  v270 = CTextMsgHandler::AddTextMsg(445, 0, 1, 1);
                if ( v270 )
                  CTextMsgHandler::AddTextMsg(1957, 0, 1);
              }
              else
              {
                CTextMsgHandler::AddTextMsg(2532, 0, 1);
              }
              CStateLoadGame::BuildSaveList(*(_DWORD *)(g_pGameType + 692), *(_DWORD *)(g_pGameType + 740));
              v181 = CEvn_Event::CEvn_Event(&v301, 0x26Bu, 0, (unsigned int)&g_cSaveGameContext, 0);
              LOBYTE(v323) = 16;
              IEventEngine::SendAMessage(g_pEvnEngine, v181);
              LOBYTE(v323) = 15;
              CEvn_Event::~CEvn_Event(&v301);
              IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, CursorShape);
              *((_DWORD *)v278 + 1) = timeGetTime() + 71;
              v323 = -1;
              std::wstring::~wstring(v315);
              result = 1;
            }
            else
            {
              result = 1;
            }
            break;
          case 6u:
            v234 = v277[2];
            v221 = v277[3];
            if ( *(_DWORD *)(g_pGameType + 4 * (_DWORD)v234 + 524) == -1 )
            {
              *(_DWORD *)(g_pGameType + 4 * (_DWORD)v234 + 524) = v221;
            }
            else if ( *(void **)(g_pGameType + 4 * (_DWORD)v234 + 524) != v221 )
            {
              for ( i = 0; i < 8; ++i )
              {
                if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 1 )
                {
                  Instance = StormManager::GetInstance();
                  if ( *(_DWORD *)(g_pGameType + 4 * i + 224) != StormManager::GetLocalPeerId(Instance) )
                  {
                    v118 = (void *)INetworkEngine::ConvertIPAddress((int)v292, *(_DWORD *)(g_pGameType + 4 * i + 188));
                    v119 = v118;
                    v323 = 4;
                    v21 = (const char *)std::string::c_str(v118);
                    CTrace::Print("Connectionloss: Removing Player index%i, with ip %s", i, v21);
                    v323 = -1;
                    std::string::~string(v292);
                    v253 = INetworkEngine::KickPlayerPeerId(
                             (INetworkEngine *)g_pNetworkEngine,
                             *(_DWORD *)(g_pGameType + 4 * i + 224));
                    if ( !v253
                      && BBSupportDbgReportF(
                           2,
                           "Main\\States\\StateGameII.cpp",
                           549,
                           "Connectionloss: Player could not be removed! Tracefile -> Thomas") == 1 )
                    {
                      __debugbreak();
                    }
                  }
                }
              }
            }
            result = 1;
            break;
          default:
CStateGame__OnEvent___def_18AD2EB:
            result = 0;
            break;
        }
      }
      else if ( v264 == (char *)4002 )
      {
        v120 = a2;
        v22 = CPlayerManager::PeerId(BYTE2(a2[1].event));
        INetworkEngine::RemovePlayerPeerId((INetworkEngine *)g_pNetworkEngine, v22);
        return 1;
      }
      else
      {
        v264 -= 3;
        switch ( (unsigned int)v264 )
        {
          case 0u:
            CStateGame::VerifyWorldOffset((CStateGame *)v278);
            CStateGame::UpdateClientSize((CStateGame *)v278);
            return 0;
          case 2u:
            v275.x = (unsigned __int16)v277[3];
            v275.y = (unsigned int)v277[3] >> 16;
            v275.x = LOWORD(v275.x);
            if ( SLOWORD(v275.y) < 0 )
              v275.y = 0;
            if ( SLOWORD(v275.x) < 0 )
              v275.x = 0;
            *((_DWORD *)v278 + 27) = v275.x;
            *((_DWORD *)v278 + 28) = v275.y;
            if ( v278[248] )
            {
              CStateGame::IsInMinimap((CStateGame *)v278, &v275, &v71);
              return 1;
            }
            if ( v278[247] )
            {
              Point.x = 0;
              Point.y = v275.y;
              ClientToScreen(g_hWnd, &Point);
              v250 = Point.y - *((_DWORD *)v278 + 58);
              if ( v250 > 0 )
                CStateGame::ZoomOut((CStateGame *)v278, v250 / 4);
              if ( v250 < 0 )
                CStateGame::ZoomIn((CStateGame *)v278, -v250 / 4);
              if ( (unsigned __int8)_ThemeHelper::GetProc(v69, v70) && v250 )
                SetCursorPos(*((_DWORD *)v278 + 57), *((_DWORD *)v278 + 58));
              return 1;
            }
            else if ( v278[244] )
            {
              Number = v275.x - *((_DWORD *)v278 + 53);
              v137 = v275.y - *((_DWORD *)v278 + 54);
              if ( (unsigned int)j__abs(Number) <= 4 && (unsigned int)j__abs(v137) <= 4 )
                return 1;
              if ( v275.x >= *((_DWORD *)v278 + 66) )
                x = v275.x;
              else
                x = *((_DWORD *)v278 + 66);
              v275.x = x;
              dword_402F3B4 = *((_DWORD *)v278 + 53);
              dword_402F3B8 = *((_DWORD *)v278 + 54);
              dword_402F3BC = x;
              dword_402F3C0 = v275.y;
              if ( IGfxEngine::GetCursorShape(g_pGfxEngine) != 3
                && IGfxEngine::GetCursorShape(g_pGfxEngine) != 6
                && IGfxEngine::GetCursorShape(g_pGfxEngine) != 7
                && IGfxEngine::GetCursorShape(g_pGfxEngine) != 4 )
              {
                v30 = IGfxEngine::ConvertRgbToHicol(255, 255, 255);
                IGfxEngine::DrawRectangle((IGfxEngine *)g_pGfxEngine, (struct tagRECT *)&dword_402F3B4, v30);
              }
              v214 = 0;
              v213 = 0;
              v139 = 479;
              IGfxEngine::GetClosestMapPoint(
                (IGfxEngine *)g_pGfxEngine,
                *((_DWORD *)v278 + 53),
                *((_DWORD *)v278 + 54),
                &v230,
                &v229);
              v214 = ((unsigned __int16)v229 << 16) | (unsigned __int16)v230;
              ClosestMapPoint = IGfxEngine::GetClosestMapPoint((IGfxEngine *)g_pGfxEngine, v275.x, v275.y, &v230, &v229);
              v213 = ((unsigned __int16)v229 << 16) | (unsigned __int16)v230;
              v31 = CPlayerManager::GetLocalPlayerId();
              CStateGame::SendLogicMessage((CStateGame *)v278, 0x1DFu, v213, v214, v31, 0, 0);
              return 1;
            }
            else if ( v278[245] )
            {
              if ( v278[246] )
              {
                v212 = v275.x - *((_DWORD *)v278 + 57);
                v211 = v275.y - *((_DWORD *)v278 + 58);
                OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
                OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
                if ( (unsigned __int8)_ThemeHelper::GetProc(v69, v70) )
                {
                  if ( v275.x > OutputWidth || v275.y > OutputHeight )
                  {
                    SetCursorPos(OutputWidth / 2, OutputHeight / 2);
                    return 1;
                  }
                  *((_DWORD *)v278 + 24) += v212;
                  *((_DWORD *)v278 + 25) += v211;
                }
                else
                {
                  *((_DWORD *)v278 + 24) = *((_DWORD *)v278 + 59) - v212;
                  *((_DWORD *)v278 + 25) = *((_DWORD *)v278 + 60) - v211;
                }
                CStateGame::VerifyWorldOffset((CStateGame *)v278);
                if ( !(unsigned __int8)_ThemeHelper::GetProc(v69, v70)
                  || v275.x == *((_DWORD *)v278 + 57) && v275.y == *((_DWORD *)v278 + 58) )
                {
                  return 1;
                }
                v275 = *(struct tagPOINT *)(v278 + 228);
                ClientToScreen(g_hWnd, &v275);
                SetCursorPos(v275.x, v275.y);
                return 1;
              }
              else if ( (unsigned __int8)_ThemeHelper::GetProc(v69, v70) )
              {
                v140 = v275.x - *((_DWORD *)v278 + 55);
                v141 = v275.y - *((_DWORD *)v278 + 56);
                if ( (unsigned int)j__abs(v140) <= 4 && (unsigned int)j__abs(v141) <= 4 )
                {
                  return 1;
                }
                else
                {
                  v278[246] = 1;
                  IGfxEngine::FixCursor((IGfxEngine *)g_pGfxEngine, 1, 0);
                  GetCursorPos(&v235);
                  ScreenToClient(g_hWnd, &v235);
                  *((_DWORD *)v278 + 55) = v235.x;
                  *((_DWORD *)v278 + 56) = v235.y;
                  v32 = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
                  *((_DWORD *)v278 + 57) = v32 / 2;
                  v33 = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
                  *((_DWORD *)v278 + 58) = v33 / 2;
                  v235 = *(struct tagPOINT *)(v278 + 228);
                  ClientToScreen(g_hWnd, &v235);
                  SetCursorPos(v235.x, v235.y);
                  return 1;
                }
              }
              else
              {
                v142 = abs(v275.x - *((_DWORD *)v278 + 57));
                v143 = abs(v275.y - *((_DWORD *)v278 + 58));
                if ( v142 > 4 || v143 > 4 )
                  v278[246] = 1;
                return 1;
              }
            }
            else
            {
              *((_DWORD *)v278 + 64) = 0;
              *((_DWORD *)v278 + 65) = 0;
              if ( v275.x )
              {
                if ( v275.x == *((_DWORD *)v278 + 68) - 1 )
                  *((_DWORD *)v278 + 64) = 2;
              }
              else
              {
                *((_DWORD *)v278 + 64) = 1;
              }
              if ( v275.y )
              {
                if ( v275.y == *((_DWORD *)v278 + 69) - 1 )
                  *((_DWORD *)v278 + 65) = 4;
              }
              else
              {
                *((_DWORD *)v278 + 65) = 3;
              }
              return 1;
            }
          case 4u:
            v278[244] = 1;
            if ( v278[245] )
            {
              if ( v278[246] )
              {
                v277[3] = (void *)(*((_DWORD *)v278 + 55) | (*((_DWORD *)v278 + 56) << 16));
                if ( (unsigned __int8)_ThemeHelper::GetProc(v69, v70) )
                {
                  IGfxEngine::FixCursor((IGfxEngine *)g_pGfxEngine, 0, 0);
                  ClientToScreen(g_hWnd, (LPPOINT)(v278 + 220));
                  SetCursorPos(*((_DWORD *)v278 + 55), *((_DWORD *)v278 + 56));
                }
                v278[246] = 0;
              }
              IGfxEngine::FixCursor((IGfxEngine *)g_pGfxEngine, 1, 1);
              *((_DWORD *)v278 + 53) = (unsigned __int16)v277[3];
              *((_DWORD *)v278 + 54) = (unsigned int)v277[3] >> 16;
              *((_DWORD *)v278 + 57) = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine) / 2;
              *((_DWORD *)v278 + 58) = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine) / 2;
              if ( (unsigned __int8)_ThemeHelper::GetProc(v69, v70) )
              {
                ClientToScreen(g_hWnd, (LPPOINT)(v278 + 228));
                SetCursorPos(*((_DWORD *)v278 + 57), *((_DWORD *)v278 + 58));
              }
              v278[247] = 1;
              return 1;
            }
            else
            {
              v186.x = (unsigned __int16)v277[3];
              v186.y = (unsigned int)v277[3] >> 16;
              if ( CStateGame::IsInMinimap((CStateGame *)v278, &v186, &v101) )
              {
                if ( v278[72] )
                {
                  IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
                  v278[72] = 0;
                }
                v278[248] = 1;
                *((_DWORD *)v278 + 24) = (*((int *)v278 + 26) >> 16) * *((_DWORD *)v278 + 21) * v101.x / 0xA0u;
                *((_DWORD *)v278 + 25) = *((_DWORD *)v278 + 21) * v101.y * (*((int *)v278 + 26) >> 16) / 0xA0u;
                *((_DWORD *)v278 + 24) -= *((_DWORD *)v278 + 25) / 2;
                *((int *)v278 + 25) /= 2;
                CStateGame::VerifyWorldOffset((CStateGame *)v278);
                v278[244] = 0;
              }
              else
              {
                *((_DWORD *)v278 + 53) = v186.x;
                SetCapture(g_hWnd);
                if ( v278[72] )
                {
                  IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
                  v278[72] = 0;
                }
                *((_DWORD *)v278 + 54) = v186.y;
                IGfxEngine::DrawRectangle((IGfxEngine *)g_pGfxEngine, 0, 0);
              }
              return 1;
            }
          case 5u:
            v278[248] = 0;
            v278[245] = 0;
            v278[244] = 0;
            if ( v278[247] )
            {
              v278[247] = 0;
              IGfxEngine::FixCursor((IGfxEngine *)g_pGfxEngine, 0, 0);
              if ( (unsigned __int8)_ThemeHelper::GetProc(v69, v70) )
              {
                ClientToScreen(g_hWnd, (LPPOINT)(v278 + 212));
                SetCursorPos(*((_DWORD *)v278 + 53), *((_DWORD *)v278 + 54));
              }
              goto LABEL_148;
            }
            ReleaseCapture();
            if ( !v278[72] )
            {
              IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 1);
              v278[72] = 1;
            }
            v278[244] = 0;
            v241 = (unsigned __int16)v277[3];
            v242 = (unsigned int)v277[3] >> 16;
            if ( v241 >= *((_DWORD *)v278 + 66) )
              v218 = v241;
            else
              v218 = *((_DWORD *)v278 + 66);
            v241 = v218;
            v231 = 0;
            v246 = 0;
            v239 = 477;
            if ( (unsigned int)abs(v218 - *((_DWORD *)v278 + 53)) <= 4
              && (unsigned int)abs(v242 - *((_DWORD *)v278 + 54)) <= 4 )
            {
              v239 = 477;
              v97 = IGfxEngine::GetClosestMapPoint(
                      (IGfxEngine *)g_pGfxEngine,
                      *((_DWORD *)v278 + 53),
                      *((_DWORD *)v278 + 54),
                      &v134,
                      &v135);
              v231 = ((unsigned __int16)v135 << 16) | (unsigned __int16)v134;
              v246 = (unsigned int)v277[2];
            }
            else
            {
              IGfxEngine::DrawRectangle((IGfxEngine *)g_pGfxEngine, 0, 0);
              v231 = ((unsigned __int16)*((_DWORD *)v278 + 54) << 16) | (unsigned __int16)*((_DWORD *)v278 + 53);
              if ( v241 < 0 )
                v217 = 0;
              else
                v217 = v241;
              v132 = v217;
              v216 = v242;
              v133 = v242;
              v246 = ((unsigned __int16)v242 << 16) | (unsigned __int16)v217;
              if ( ((unsigned int)v277[2] & 8) != 0 )
                v246 |= 0x80000000;
              v239 = 478;
            }
            if ( !(dword_402F3B8 + dword_402F3BC + dword_402F3C0 + dword_402F3B4) && v239 == 478 )
              return 1;
            v29 = CPlayerManager::GetLocalPlayerId();
            CStateGame::SendLogicMessage((CStateGame *)v278, v239, v246, v231, v29, 0, 0);
            dword_402F3B8 = 0;
            dword_402F3BC = 0;
            dword_402F3C0 = 0;
            dword_402F3B4 = 0;
            return 1;
          case 6u:
            v222.x = (unsigned __int16)v277[3];
            v222.y = (unsigned int)v277[3] >> 16;
            if ( CStateGame::IsInMinimap((CStateGame *)v278, &v222, &v100) )
            {
              v245 = *((_DWORD *)v278 + 21) * v100.x * (*((int *)v278 + 26) >> 16) / 0xA0u;
              v244 = (*((int *)v278 + 26) >> 16) * *((_DWORD *)v278 + 21) * v100.y / 0xA0u;
              v245 /= *((int *)v278 + 26) >> 16;
              v244 /= *((int *)v278 + 26) >> 16;
              if ( v245 <= 0 || v244 <= 0 )
              {
                v245 = 0;
                v244 = 0;
              }
              v209 = 0;
              v144 = 480;
              v210 = ((unsigned __int16)v244 << 16) | (unsigned __int16)v245;
              v209 = v277[2];
              v34 = CPlayerManager::GetLocalPlayerId();
              CStateGame::SendLogicMessage((CStateGame *)v278, v144, (unsigned int)v209, v210, v34, 0, 0);
              goto CStateGame__OnEvent___def_18AD2EB;
            }
            if ( !(unsigned __int8)_ThemeHelper::GetProc(v69, v70) && !v278[245] )
            {
              *((_DWORD *)v278 + 57) = v222.x;
              *((_DWORD *)v278 + 58) = v222.y;
              *((_DWORD *)v278 + 59) = *((_DWORD *)v278 + 24);
              *((_DWORD *)v278 + 60) = *((_DWORD *)v278 + 25);
              IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 1);
              IGfxEngine::LockCursorShape((IGfxEngine *)g_pGfxEngine, 1);
            }
            v278[245] = 1;
            if ( v278[244] )
            {
              dword_402F3B8 = 0;
              dword_402F3BC = 0;
              dword_402F3C0 = 0;
              dword_402F3B4 = 0;
              IGfxEngine::FixCursor((IGfxEngine *)g_pGfxEngine, 1, 1);
              *((_DWORD *)v278 + 53) = v222.x;
              *((_DWORD *)v278 + 54) = v222.y;
              v35 = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
              *((_DWORD *)v278 + 57) = v35 / 2;
              v36 = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
              *((_DWORD *)v278 + 58) = v36 / 2;
              if ( (unsigned __int8)_ThemeHelper::GetProc(v69, v70) )
              {
                ClientToScreen(g_hWnd, (LPPOINT)(v278 + 228));
                SetCursorPos(*((_DWORD *)v278 + 57), *((_DWORD *)v278 + 58));
              }
              v278[247] = 1;
              return 1;
            }
            else
            {
              SetCapture(g_hWnd);
              if ( v278[72] )
              {
                IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
                v278[72] = 0;
              }
              *((_DWORD *)v278 + 55) = (unsigned __int16)v277[3];
              *((_DWORD *)v278 + 56) = (unsigned int)v277[3] >> 16;
              return 1;
            }
          case 7u:
            if ( !v278[245] )
              return 1;
            IGfxEngine::LockCursorShape((IGfxEngine *)g_pGfxEngine, 0);
            v278[245] = 0;
            v278[244] = 0;
            if ( v278[247] )
            {
              v278[247] = 0;
              IGfxEngine::FixCursor((IGfxEngine *)g_pGfxEngine, 0, 0);
              if ( (unsigned __int8)_ThemeHelper::GetProc(v69, v70) )
              {
                ClientToScreen(g_hWnd, (LPPOINT)(v278 + 212));
                SetCursorPos(*((_DWORD *)v278 + 53), *((_DWORD *)v278 + 54));
              }
LABEL_148:
              ReleaseCapture();
              return 1;
            }
            else
            {
              ReleaseCapture();
              if ( !v278[72] )
              {
                IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 1);
                v278[72] = 1;
              }
              if ( v278[246] )
              {
                v278[246] = 0;
                IGfxEngine::FixCursor((IGfxEngine *)g_pGfxEngine, 0, 0);
                if ( !(unsigned __int8)_ThemeHelper::GetProc(v69, v70) )
                  return 1;
                ClientToScreen(g_hWnd, (LPPOINT)(v278 + 220));
                SetCursorPos(*((_DWORD *)v278 + 55), *((_DWORD *)v278 + 56));
                return 1;
              }
              else
              {
                v208 = 0;
                v238 = 0;
                v153 = 480;
                v145 = IGfxEngine::GetClosestMapPoint(
                         (IGfxEngine *)g_pGfxEngine,
                         *((_DWORD *)v278 + 55),
                         *((_DWORD *)v278 + 56),
                         &v228,
                         &v227);
                if ( v145 < 0 || v228 <= 0 || v227 <= 0 )
                {
                  v228 = 0;
                  v227 = 0;
                }
                v208 = ((unsigned __int16)v227 << 16) | (unsigned __int16)v228;
                v238 = (unsigned int)v277[2];
                if ( v238 == 24 )
                  v238 = 16;
                v37 = CPlayerManager::GetLocalPlayerId();
                CStateGame::SendLogicMessage((CStateGame *)v278, v153, v238, v208, v37, 0, 0);
                return 1;
              }
            }
          case 8u:
            v196 = v277[3];
            if ( !v278[294] )
              goto LABEL_381;
            if ( ((unsigned __int8)v196 & 8) == 0 )
              goto LABEL_381;
            v262 = (int)v277[2];
            if ( v262 == 'S' )
              goto LABEL_381;
            v198 = v262 >= 65;
            v197 = v262 <= 90;
            if ( !v197 || !v198 )
              goto LABEL_381;
            if ( ((unsigned __int8)v196 & 4) == 0 )
              v262 += 32;
            if ( v262 == 'q' )
            {
              CStateGame::EnableOrDisableDebugString((CStateGame *)v278, v278[68] == 0);
              return 0;
            }
            else if ( v262 == 'z' )
            {
              String::String((char *)&byte_3740A8A, -1);
              v323 = 28;
              CDebugFkt::SetDebugString((const struct String *)v311);
              v323 = -1;
              String::~String((String *)v311);
              IGfxEngine::EnableDebugValueCallback((IGfxEngine *)g_pGfxEngine, 0);
              if ( !v278[68] )
                CStateGame::EnableOrDisableDebugString((CStateGame *)v278, 1);
              return 0;
            }
            else
            {
              v195 = (int (__cdecl *)(int, int))CDebugFkt::SelectDebugFunc(v262);
              if ( v195 )
              {
                if ( !v278[68] )
                  CStateGame::EnableOrDisableDebugString((CStateGame *)v278, 1);
                IGfxEngine::EnableDebugValueCallback((IGfxEngine *)g_pGfxEngine, v195);
                return 0;
              }
              else
              {
LABEL_381:
                v236 = (char *)v277[2] - 8;
                switch ( (unsigned int)v236 )
                {
                  case 0u:
                    v269 = ((unsigned int)v277[3] & 4) != 0;
                    v251 = v269;
                    v194 = v269;
                    v166 = v194;
                    v167 = CPlayerManager::GetLocalPlayerId();
                    CStateGame::SendLogicMessage((CStateGame *)v278, 0x19Fu, v194, 0, v167, 0, 0);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 1u:
                    if ( v277[3] )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    v163 = CEvn_Event::CEvn_Event(&v304, 0x6Bu, 1u, 0, 0);
                    v323 = 32;
                    IEventEngine::SendAMessage(g_pEvnEngine, v163);
                    v323 = -1;
                    CEvn_Event::~CEvn_Event(&v304);
                    result = 1;
                    break;
                  case 0xBu:
                    goto LABEL_363;
                  case 0x19u:
                  case 0x65u:
                    CStateGame::ZoomIn((CStateGame *)v278, 5);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 0x1Au:
                  case 0x63u:
                    CStateGame::ZoomOut((CStateGame *)v278, 5);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 0x1Cu:
                    v193 = CPlayerManager::GetLocalPlayerId();
                    v56 = (CPlayerInfo *)CPlayerManager::PlayerInfo(v193);
                    v67 = CPlayerInfo::StartX(v56);
                    v57 = (pairNode *)CPlayerManager::PlayerInfo(v193);
                    v58 = CPlayerInfo::StartY(v57);
                    v164 = CEvn_Event::CEvn_Event(&v302, 0x13u, v58, v67, 0);
                    v323 = 31;
                    IEventEngine::SendAMessage(g_pEvnEngine, v164);
                    v323 = -1;
                    CEvn_Event::~CEvn_Event(&v302);
                    result = 1;
                    break;
                  case 0x1Du:
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 0);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 0);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 0);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 0);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 0);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 0);
                    CStateGame::VerifyWorldOffset((CStateGame *)v278);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 0x1Eu:
                    CStateGame::ScrollVertical((CStateGame *)v278, 0);
                    CStateGame::ScrollVertical((CStateGame *)v278, 0);
                    CStateGame::ScrollVertical((CStateGame *)v278, 0);
                    CStateGame::ScrollVertical((CStateGame *)v278, 0);
                    CStateGame::ScrollVertical((CStateGame *)v278, 0);
                    CStateGame::ScrollVertical((CStateGame *)v278, 0);
                    CStateGame::VerifyWorldOffset((CStateGame *)v278);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 0x1Fu:
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 1);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 1);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 1);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 1);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 1);
                    CStateGame::ScrollHorizontal((CStateGame *)v278, 1);
                    CStateGame::VerifyWorldOffset((CStateGame *)v278);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 0x20u:
                    CStateGame::ScrollVertical((CStateGame *)v278, 1);
                    CStateGame::ScrollVertical((CStateGame *)v278, 1);
                    CStateGame::ScrollVertical((CStateGame *)v278, 1);
                    CStateGame::ScrollVertical((CStateGame *)v278, 1);
                    CStateGame::ScrollVertical((CStateGame *)v278, 1);
                    CStateGame::ScrollVertical((CStateGame *)v278, 1);
                    CStateGame::VerifyWorldOffset((CStateGame *)v278);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 0x26u:
                    if ( !v278[294] )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    if ( ((unsigned int)v277[3] & 8) != 0 )
                    {
                      v165 = CEvn_Event::CEvn_Event(&v300, 0x17u, 0, 0, 0);
                      v323 = 30;
                      IEventEngine::SendAMessage(g_pEvnEngine, v165);
                      v323 = -1;
                      CEvn_Event::~CEvn_Event(&v300);
                    }
                    result = 1;
                    break;
                  case 0x28u:
                  case 0x29u:
                  case 0x2Au:
                  case 0x2Bu:
                  case 0x2Cu:
                  case 0x2Du:
                  case 0x2Eu:
                  case 0x2Fu:
                  case 0x30u:
                  case 0x31u:
                    if ( v278[292] )
                    {
                      result = 0;
                    }
                    else
                    {
                      v265 = v277[2];
                      if ( v265 == (void *)48 )
                        v192 = 58;
                      else
                        v192 = (int)v265;
                      v265 = (void *)(v192 - 48);
                      if ( ((unsigned int)v277[3] & 8) != 0 )
                      {
                        v59 = CPlayerManager::GetLocalPlayerId();
                        v160 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v282, 0x1D6u, (unsigned int)v265, 0, v59, 0, 0);
                        v323 = 35;
                        IEventEngine::SendAMessage(g_pEvnEngine, v160);
                        v323 = -1;
                        CEvn_Logic::~CEvn_Logic(v282);
                        result = 1;
                      }
                      else
                      {
                        v267 = ((unsigned int)v277[3] & 0x1C) == 0;
                        v252 = v267;
                        if ( v267
                          && *((void **)v278 + 70) == v265
                          && *((_DWORD *)v278 + 71) > INetworkEngine::GetVirtualTick((INetworkEngine *)g_pNetworkEngine)
                                                    - 6 )
                        {
                          v60 = CPlayerManager::GetLocalPlayerId();
                          v159 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v279, 0x1D9u, (unsigned int)v265, 0, v60, 0, 0);
                          v323 = 36;
                          IEventEngine::SendAMessage(g_pEvnEngine, v159);
                          v323 = -1;
                          CEvn_Logic::~CEvn_Logic(v279);
                        }
                        else
                        {
                          v158 = ((unsigned int)v277[3] & 4) != 0;
                          v61 = CPlayerManager::GetLocalPlayerId();
                          v157 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v280, 0x1D8u, (unsigned int)v265, v158, v61, 0, 0);
                          v323 = 37;
                          IEventEngine::SendAMessage(g_pEvnEngine, v157);
                          v323 = -1;
                          CEvn_Logic::~CEvn_Logic(v280);
                          *((_DWORD *)v278 + 70) = v265;
                          *((_DWORD *)v278 + 71) = INetworkEngine::GetVirtualTick((INetworkEngine *)g_pNetworkEngine);
                        }
                        result = 1;
                      }
                    }
                    break;
                  case 0x4Au:
                    if ( ((unsigned int)v277[3] & 8) == 0 )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    if ( !IEventEngine::IsEventPlaying(g_pEvnEngine) )
                    {
                      if ( IEventEngine::IsEventRecording(g_pEvnEngine) )
                      {
                        v161 = std::string::string(v283, (char *)&byte_3740A8B);
                        v323 = 34;
                        IEventEngine::RecordEvents(g_pEvnEngine, v161);
                        v323 = -1;
                        std::string::~string(v283);
                        CTextMsgHandler::AddTextMsg("Event Recording stopped!", 0, 0, 0, 0);
                      }
                      else
                      {
                        v162 = std::string::string(v289, "Events.rec");
                        v323 = 33;
                        IEventEngine::RecordEvents(g_pEvnEngine, v162);
                        v323 = -1;
                        std::string::~string(v289);
                        CTextMsgHandler::AddTextMsg("Event Recording started to file \"Events.rec\"!", 0, 0, 0, 0);
                      }
                    }
                    result = 1;
                    break;
                  case 0x4Bu:
                    if ( !g_pGame || !CStateGame::CanSave((CStateGame *)g_pGame) || ((unsigned int)v277[3] & 8) == 0 )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    CStateGame::SaveGame(v278, 1);
                    result = 1;
                    break;
                  case 0x58u:
                  case 0x59u:
                  case 0x5Au:
                  case 0x5Bu:
                  case 0x5Cu:
                  case 0x5Du:
                  case 0x5Eu:
                  case 0x5Fu:
                  case 0x60u:
                  case 0x61u:
                    if ( !v278[294] )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    if ( ((unsigned int)v277[3] & 8) != 0 )
                    {
                      v223 = (int)v277[2] - 96;
                      if ( v223 <= CPlayerManager::LastPlayerId() && v223 >= 1 )
                      {
                        CInputProcessor::DeSelectAllEx((CInputProcessor *)&g_cInputProcessor);
                        CPlayerManager::SetLocalPlayerId(v223);
                      }
                      result = 1;
                    }
                    else
                    {
                      if ( v277[2] == (void *)105 )
                        g_iGameSpeed = 20;
                      else
                        g_iGameSpeed = (int)v277[2] - 96;
                      result = 1;
                    }
                    break;
                  case 0x66u:
                    if ( v278[294] )
                      g_iGameSpeed = 99;
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 0x6Fu:
                    if ( !v278[294] || ((unsigned int)v277[3] & 8) == 0 || !v278[294] )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    v268 = (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)g_pFogging + 36))(g_pFogging) == 0;
                    (*(void (__thiscall **)(void *, bool))(*(_DWORD *)g_pFogging + 40))(g_pFogging, v268);
                    result = 1;
                    break;
                  case 0x70u:
                    if ( !v278[71] && (!g_pGameType || !(unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType)) )
                      v278[69] = 1;
                    result = 1;
                    break;
                  case 0x72u:
                    if ( v278[294] )
                    {
                      CEvn_Event::CEvn_Event(&v314, 0x11u, 0, 0, 1u);
                      v323 = 29;
                      IEventEngine::SendAMessage(g_pEvnEngine, &v314);
                      v99.x = 0;
                      v99.y = 0;
                      ClientToScreen(g_hWnd, &v99);
                      GetClientRect(g_hWnd, &Rect);
                      v323 = -1;
                      CEvn_Event::~CEvn_Event(&v314);
                    }
                    result = 1;
                    break;
                  default:
                    goto CStateGame__OnEvent___def_18B0CD2;
                }
              }
            }
            return result;
          case 0xAu:
            switch ( (unsigned int)v277[2] )
            {
              case ' ':
                CTextMsgHandler::ExecuteLastMsg();
                result = 1;
                break;
              case 'H':
              case 'h':
                v199 = CPlayerManager::GetLocalPlayerId();
                v53 = (CPlayerInfo *)CPlayerManager::PlayerInfo(v199);
                v67 = CPlayerInfo::StartX(v53);
                v54 = (pairNode *)CPlayerManager::PlayerInfo(v199);
                v55 = CPlayerInfo::StartY(v54);
                v168 = CEvn_Event::CEvn_Event(&v305, 0x13u, v55, v67, 0);
                v323 = 27;
                IEventEngine::SendAMessage(g_pEvnEngine, v168);
                v323 = -1;
                CEvn_Event::~CEvn_Event(&v305);
                result = 1;
                break;
              case 'P':
              case 'p':
LABEL_363:
                CStateGame::SwitchPause((CStateGame *)v278);
                result = 1;
                break;
              default:
                goto CStateGame__OnEvent___def_18AD2EB;
            }
            return result;
          case 0xBu:
            v266 = (unsigned int)v277[2] >> 16;
            if ( (__int16)v266 <= 0 )
              CStateGame::ZoomOut((CStateGame *)v278, 5 * (-(__int16)v266 / 120));
            else
              CStateGame::ZoomIn((CStateGame *)v278, 5 * (v266 / 120));
            return 1;
          case 0xFu:
            v220 = v277[3];
            v84 = (double)(unsigned int)v220;
            v240 = (unsigned int)(3801088.0 * (double)(unsigned int)v220 / 100.0) + 917504;
            v219 = v240;
            v106 = (double)v240 / (double)*((int *)v278 + 26);
            *((_DWORD *)v278 + 24) = (int)((double)*((int *)v278 + 24) * v106);
            *((_DWORD *)v278 + 25) = (int)((double)*((int *)v278 + 25) * v106);
            *((_DWORD *)v278 + 26) = v240;
            CStateGame::VerifyWorldOffset((CStateGame *)v278);
            return 1;
          case 0x10u:
            CStateGame::SetViewPos((CStateGame *)v278, a2->lparam, a2->wparam);
            return 1;
          case 0x11u:
CStateGame__OnEvent___def_18B0CD2:
            v156 = v277[2];
            if ( v156 != (void *)9 || v277[3] )
              goto CStateGame__OnEvent___def_18AD2EB;
            v155 = CEvn_Event::CEvn_Event(&v299, 0x6Bu, 0, 0, 0);
            v323 = 38;
            IEventEngine::SendAMessage(g_pEvnEngine, v155);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v299);
            return 1;
          case 0x14u:
            v278[295] = 1;
            return 1;
          case 0x17u:
            CStateGame::UpdateToGuiInfoStruct((CStateGame *)v278);
            v179 = CEvn_Event::CEvn_Event(&v303, 0x26Cu, 0, (unsigned int)(v278 + 308), 0);
            v323 = 17;
            IEventEngine::SendAMessage(g_pEvnEngine, v179);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v303);
            return 1;
          case 0x18u:
            v175 = CEvn_Event::CEvn_Event(&v294, 0x26Cu, 0, (unsigned int)(v278 + 332), 0);
            v323 = 21;
            IEventEngine::SendAMessage(g_pEvnEngine, v175);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v294);
            return 1;
          case 0x19u:
            v174 = CEvn_Event::CEvn_Event(&v295, 0x26Cu, 0, (unsigned int)(v278 + 356), 0);
            v323 = 22;
            IEventEngine::SendAMessage(g_pEvnEngine, v174);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v295);
            return 1;
          case 0x1Au:
            v176 = CEvn_Event::CEvn_Event(&v293, 0x26Cu, 0, (unsigned int)(v278 + 376), 0);
            v323 = 20;
            IEventEngine::SendAMessage(g_pEvnEngine, v176);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v293);
            return 1;
          case 0x1Bu:
            v173 = CEvn_Event::CEvn_Event(&v296, 0x26Cu, 0, (unsigned int)(v278 + 388), 0);
            v323 = 23;
            IEventEngine::SendAMessage(g_pEvnEngine, v173);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v296);
            return 1;
          case 0x1Cu:
            v206 = a2->wparam;
            if ( v206 )
            {
              if ( v206 == 1 )
              {
                *((_DWORD *)v278 + 81) = a2->lparam;
              }
              else if ( BBSupportDbgReportF(
                          2,
                          "Main\\States\\StateGameII.cpp",
                          1650,
                          "StateGameII: Invalid setting item identifier!") == 1 )
              {
                __debugbreak();
              }
            }
            else
            {
              *((_DWORD *)v278 + 79) = a2->lparam;
            }
            CStateGame::UpdateFromGuiInfoStruct((CStateGame *)v278);
            v178 = CEvn_Event::CEvn_Event(&v309, 0x11u, 0, 0, 0);
            v323 = 18;
            IEventEngine::SendAMessage(g_pEvnEngine, v178);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v309);
            CStateGame::UpdateToGuiInfoStruct((CStateGame *)v278);
            v177 = CEvn_Event::CEvn_Event(&v310, 0x26Bu, 0, (unsigned int)(v278 + 308), 0);
            v323 = 19;
            IEventEngine::SendAMessage(g_pEvnEngine, v177);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v310);
            return 1;
          case 0x1Du:
            CStateGame::UpdateFromGuiInfoStruct((CStateGame *)v278);
            CStateGame::UpdateMusicSettings((CStateGame *)v278);
            return 1;
          case 0x1Eu:
            CStateGame::UpdateFromGuiInfoStruct((CStateGame *)v278);
            return 1;
          case 0x1Fu:
            CStateGame::UpdateFromGuiInfoStruct((CStateGame *)v278);
            CTextMsgHandler::SetMaxMsgCount(*((_DWORD *)v278 + 96));
            CTextMsgHandler::RefreshList();
            return 1;
          case 0x20u:
            CStateGame::UpdateFromGuiInfoStruct((CStateGame *)v278);
            CStateGame::UpdateToGuiInfoStruct((CStateGame *)v278);
            v172 = CEvn_Event::CEvn_Event(&v297, 0x26Bu, 0, (unsigned int)(v278 + 388), 0);
            v323 = 24;
            IEventEngine::SendAMessage(g_pEvnEngine, v172);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v297);
            return 1;
          case 0x21u:
            v226 = 0;
            v39 = CPlayerManager::GetLocalPlayerId();
            v203 = CAlliances::AllianceId(v39);
            for ( j = 1; j <= CPlayerManager::LastPlayerId(); ++j )
            {
              if ( CPlayerManager::GetLocalPlayerId() != j && !CPlayerManager::IsAI(j) )
              {
                v274 = 0;
                v204 = CAlliances::AllianceId(j);
                v205 = a2->wparam;
                if ( v205 == 1 )
                  v274 = v204 == v203;
                else
                  v274 = v205 != 2 || v204 != v203;
                if ( v274 )
                  v202 = 1 << (j - 1);
                else
                  v202 = 0;
                v226 |= v202;
              }
            }
            CGameSettings::SetChatMessageFilter(v226);
            CStateGame::UpdateToGuiInfoStruct((CStateGame *)v278);
            v171 = CEvn_Event::CEvn_Event(&v298, 0x26Bu, 0, (unsigned int)(v278 + 388), 0);
            v323 = 25;
            IEventEngine::SendAMessage(g_pEvnEngine, v171);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v298);
            return 1;
          case 0x22u:
            v224 = v277;
            *((_BYTE *)v277 + 30) = CPlayerManager::GetLocalPlayerId();
            v224[1] = (void *)4004;
            v52 = CPlayerManager::GetLocalPlayerId();
            v257 = 1 << (v52 - 1);
            INetworkEngine::SendAsyncNetMessage(
              (INetworkEngine *)g_pNetworkEngine,
              (struct CEvn_Logic *)v224,
              ~(1 << (v52 - 1)));
            return 1;
          case 0x23u:
            v237 = v277[2];
            if ( v237 && std::string::length(v237) )
              v201 = std::string::c_str(v237);
            else
              v201 = 0;
            v273 = (_BYTE *)v201;
            if ( !v201 || *v273 != 33 )
              goto LABEL_354;
            if ( (*(unsigned __int8 (__thiscall **)(void *, _BYTE *))(*(_DWORD *)g_pHJBMgr + 4))(g_pHJBMgr, v273) )
            {
              if ( (unsigned __int8)IHJBMgr::LocalIsHJBAllowed()
                && (v40 = CPlayerManager::GetLocalPlayerId(),
                    RealPlayerName = CGameType::GetRealPlayerName(v40 - 1),
                    (*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)g_pHJBMgr + 8))(
                      g_pHJBMgr,
                      RealPlayerName))
                && (v42 = CStateGame::GameData((CStateGame *)v278), !CGameData::IsLadder(v42)) )
              {
                v43 = CPlayerManager::GetLocalPlayerId();
                CStateGame::SendLogicMessage((CStateGame *)v278, 0x1E8u, 0, 0, v43, 0, 0);
              }
              else
              {
                v278[294] = 0;
                CTextMsgHandler::AddTextMsg("Cheats deactivated!", 9, 0, 0, 0);
              }
              return 1;
            }
            else
            {
              v44 = CStateGame::GameData((CStateGame *)v278);
              if ( CGameData::IsNetworkGame(v44) )
              {
LABEL_354:
                v45 = (const char *)std::string::c_str(v277[2]);
                j__strcpy_0(Destination, v45);
                LOWORD(v68) = j__strlen(Destination) + 1;
                v46 = CPlayerManager::GetLocalPlayerId();
                CEvn_Logic::CEvn_Logic((CEvn_Logic *)v313, 0xFA5u, 0, 0, v46, (unsigned int)Destination, v68);
                v323 = 26;
                ChatMessageFilter = CGameSettings::GetChatMessageFilter();
                v48 = CPlayerManager::GetLocalPlayerId();
                INetworkEngine::SendAsyncNetMessage(
                  (INetworkEngine *)g_pNetworkEngine,
                  (struct CEvn_Logic *)v313,
                  (1 << (v48 - 1)) | ChatMessageFilter);
                v323 = -1;
                CEvn_Logic::~CEvn_Logic(v313);
                return 1;
              }
              else
              {
                if ( v273[1] == 'i'
                  && v273[2] == 'n'
                  && v273[3] == 'c'
                  && v273[4] == 'u'
                  && v273[5] == 'b'
                  && v273[6] == 'a'
                  && v273[7] == 't'
                  && v273[8] == 'i'
                  && v273[9] == 'o'
                  && v273[10] == 'n'
                  && v273[11] == '2'
                  && !v273[12] )
                {
                  if ( v278[294] )
                  {
                    v278[294] = 0;
                    CTextMsgHandler::AddTextMsg("Cheats deactivated!", 9, 0, 0, 0);
                  }
                  else
                  {
                    v278[294] = 1;
                    CTextMsgHandler::AddTextMsg("Cheats activated!", 9, 0, 0, 0);
                  }
                }
                else if ( v278[294] )
                {
                  v96 = &v62;
                  v95 = std::string::string((int)v237);
                  CStateGame::PerformCommand(v62, v63, v64, v65, v66, v67, v68);
                }
                return 1;
              }
            }
          case 0x25u:
            v154 = IGfxEngine::GetCursorShape(g_pGfxEngine);
            IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
            CStateLoadGame::BuildSaveList(*(_DWORD *)(g_pGameType + 692), *(_DWORD *)(g_pGameType + 740));
            IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, v154);
            v185 = CEvn_Event::CEvn_Event(&v308, 0x26Cu, 0, (unsigned int)&g_cSaveGameContext, 0);
            v323 = 13;
            IEventEngine::SendAMessage(g_pEvnEngine, v185);
            v323 = -1;
            CEvn_Event::~CEvn_Event(&v308);
            return 1;
          case 0x26u:
            goto LABEL_269;
          case 0x27u:
            return 1;
          case 0x34u:
            if ( CGameData::GetMode((CGameData *)(v278 + 76)) == 5 )
              return 1;
            if ( !CGameData::IsGameWon((CGameData *)(v278 + 76)) )
            {
              CGameData::TeamWon((CGameData *)(v278 + 76), a2->wparam);
              if ( CGameData::IsTutorial((CGameData *)(v278 + 76)) )
                return 1;
              IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 611, 1);
              IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 8, 930, 1);
              v3 = CPlayerManager::GetLocalPlayerId();
              if ( CAlliances::AllianceId(v3) == a2->wparam )
              {
                (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pFogging + 40))(g_pFogging, 1);
                v150 = CEvn_Event::CEvn_Event(&v306, 0x261u, 1u, 0, 0);
                v149 = v150;
                v323 = 0;
                IEventEngine::SendAMessage(g_pEvnEngine, v150);
                v323 = -1;
                CEvn_Event::~CEvn_Event(&v306);
                if ( v277[3] )
                {
                  v4 = CPlayerManager::GetLocalPlayerId();
                  v5 = CPlayerManager::Color(v4);
                  CTextMsgHandler::AddTextMsg((unsigned __int16)v277[3], v5, 1);
                }
                else
                {
                  v6 = CPlayerManager::GetLocalPlayerId();
                  v7 = CPlayerManager::Color(v6);
                  CTextMsgHandler::AddTextMsg(2255, v7, 1);
                }
              }
              else
              {
                if ( CGameData::IsNetworkGame((CGameData *)(v278 + 76)) )
                  (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pFogging + 40))(g_pFogging, 1);
                v148 = CEvn_Event::CEvn_Event(&v307, 0x261u, 0, 0, 0);
                v108 = v148;
                v323 = 1;
                IEventEngine::SendAMessage(g_pEvnEngine, v148);
                v323 = -1;
                CEvn_Event::~CEvn_Event(&v307);
                if ( v277[3] )
                {
                  v8 = CPlayerManager::GetLocalPlayerId();
                  v9 = CPlayerManager::Color(v8);
                  CTextMsgHandler::AddTextMsg((unsigned int)v277[3] >> 16, v9, 1);
                }
                else
                {
                  v10 = CPlayerManager::GetLocalPlayerId();
                  v11 = CPlayerManager::Color(v10);
                  CTextMsgHandler::AddTextMsg(1934, v11, 1);
                }
              }
              v191 = 0;
              for ( k = 0; ; ++k )
              {
                if ( k >= CPlayerManager::LastPlayerId() )
                  goto LABEL_61;
                if ( *(_DWORD *)(g_pGameType + 4 * k + 152) == CGameData::TeamWon((CUserToolsManager *)(v278 + 76)) - 1 )
                  break;
              }
              v191 = *(_DWORD *)(g_pGameType + 4 * k + 224);
LABEL_61:
              INetworkEngine::EndGame((INetworkEngine *)g_pNetworkEngine, v191);
              CStatistic::FreezeEcoStatistic((CStatistic *)&g_cStatistic);
              return 1;
            }
            if ( CGameData::TeamWon((CUserToolsManager *)(v278 + 76)) != a2->wparam
              && BBSupportDbgReport(
                   2,
                   "Main\\States\\StateGameII.cpp",
                   365,
                   "m_cGameData.TeamWon() == _rEvent.m_wParam") == 1 )
            {
              __debugbreak();
            }
            result = 1;
            break;
          case 0x35u:
            if ( a2->wparam == CPlayerManager::GetLocalPlayerId() )
            {
              v68 = 1;
              v12 = CPlayerManager::Color(a2->wparam);
              CTextMsgHandler::AddTextMsg(2254, v12, 1);
            }
            else
            {
              v109 = (_Cnd_internal_imp_t *)CPlayerManager::Name((int)v285, a2->wparam);
              v110 = v109;
              v323 = 2;
              v13 = (const wchar_t *)std::wstring::c_str(v109);
              v68 = j__wcslen(v13);
              v111 = (_Cnd_internal_imp_t *)CPlayerManager::Name((int)v287, a2->wparam);
              v14 = (const wchar_t *)std::wstring::c_str(v111);
              v112 = j__wcstombs(Dest, v14, v68);
              std::wstring::~wstring(v287);
              v323 = -1;
              std::wstring::~wstring(v285);
              v190 = v112;
              if ( v112 >= 0x21 )
                j____report_rangecheckfailure();
              Dest[v190] = 0;
              v68 = (size_t)Dest;
              v67 = 1;
              v66 = 0;
              v15 = CPlayerManager::Color(a2->wparam);
              CTextMsgHandler::AddTextMsg(2257, v15, 0, 1, Dest);
            }
            CPlayerManager::PlayerDied(a2->wparam);
            if ( CPlayerManager::IsAI(a2->wparam) )
              (*(void (__thiscall **)(void *, int))(*(_DWORD *)off_3D7A3D8 + 32))(off_3D7A3D8, a2->wparam);
            CStatistic::FreezeEcoStatistic((CStatistic *)&g_cStatistic);
            for ( m = 1; m < 83; ++m )
            {
              if ( m != 46 && m != 47 && m != 48 )
              {
                FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, a2->wparam, m);
                for ( n = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, FirstBuildingId);
                      n;
                      n = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v16) )
                {
                  if ( IEntity::FlagBits(n, (EntityFlag)0x1000u) )
                    CBuilding::Switch();
                  v16 = IAnimatedEntity::Next(n);
                }
              }
            }
            return 1;
          case 0x36u:
            v114 = (_Cnd_internal_imp_t *)CPlayerManager::Name((int)v284, (int)v277[2]);
            v115 = v114;
            v323 = 3;
            v17 = (const wchar_t *)std::wstring::c_str(v114);
            v68 = j__wcslen(v17);
            v116 = (_Cnd_internal_imp_t *)CPlayerManager::Name((int)v286, (int)v277[2]);
            v18 = (const wchar_t *)std::wstring::c_str(v116);
            v117 = j__wcstombs(v321, v18, v68);
            std::wstring::~wstring(v286);
            v323 = -1;
            std::wstring::~wstring(v284);
            v189 = v117;
            if ( v117 >= 0x21 )
              j____report_rangecheckfailure();
            v321[v189] = 0;
            CPlayerManager::SetPlayerControl((int)v277[2], 2);
            v68 = (size_t)v321;
            v67 = 1;
            v66 = 0;
            v19 = CPlayerManager::Color((int)v277[2]);
            CTextMsgHandler::AddTextMsg(2258, v19, 0, 1, v321);
            CStateGame::UpdateToGuiInfoStruct((CStateGame *)v278);
            if ( CPlayerManager::IsAlive((int)v277[2]) )
              (*(void (__thiscall **)(void *, void *))(*(_DWORD *)off_3D7A3D8 + 28))(off_3D7A3D8, v277[2]);
            return 1;
          case 0x67u:
            CMinimapHandler::FilterKeyPressed((int)v277[2]);
            return 1;
          case 0x6Bu:
            if ( !a2->wparam )
              CTextMsgHandler::AddTextMsg(2252, 0, 1, 1);
            return 1;
          default:
            goto CStateGame__OnEvent___def_18AD2EB;
        }
      }
    }
    else
    {
      if ( !j____RTDynamicCast(v277, 0, &CEvn_Event__RTTI_Type_Descriptor_, &CEvn_Logic__RTTI_Type_Descriptor_, 0)
        && BBSupportDbgReportF(
             2,
             "Main\\States\\StateGameII.cpp",
             328,
             "Message != NET_LOGIC_MSG: m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
             v277[3],
             v277[1],
             v277[2],
             v69) == 1 )
      {
        __debugbreak();
      }
      v272 = v277;
      if ( *((_WORD *)v277 + 14)
        && !v272[6]
        && BBSupportDbgReportF(
             2,
             "Main\\States\\StateGameII.cpp",
             333,
             "m_iData != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
             *((unsigned __int8 *)v272 + 30),
             v272[3],
             v272[1],
             v272[2],
             *((unsigned __int16 *)v272 + 14)) == 1 )
      {
        __debugbreak();
      }
      if ( v272[6]
        && !*((_WORD *)v272 + 14)
        && BBSupportDbgReportF(
             2,
             "Main\\States\\StateGameII.cpp",
             337,
             "m_iDataSize != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
             *((unsigned __int8 *)v272 + 30),
             v272[3],
             v272[1],
             v272[2],
             *((unsigned __int16 *)v272 + 14)) == 1 )
      {
        __debugbreak();
      }
      v151 = v277;
      if ( !(*(unsigned __int8 (__thiscall **)(_DWORD, void **))(**((_DWORD **)v278 + 63) + 4))(
              *((_DWORD *)v278 + 63),
              v277)
        && BBSupportDbgReport(
             1,
             "Main\\States\\StateGameII.cpp",
             344,
             "Internal error (L2)- aborting!\nInterner Fehler (L2) aufgetreten! Programm wird abgebrochen!") == 1 )
      {
        __debugbreak();
      }
      return 1;
    }
  }
  else
  {
    if ( !j____RTDynamicCast(v277, 0, &CEvn_Event__RTTI_Type_Descriptor_, &CEvn_Logic__RTTI_Type_Descriptor_, 0)
      && BBSupportDbgReportF(
           2,
           "Main\\States\\StateGameII.cpp",
           303,
           "Message != LOGIC_MSG: m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
           v277[3],
           v277[1],
           v277[2],
           v69) == 1 )
    {
      __debugbreak();
    }
    v271 = v277;
    if ( *((_WORD *)v277 + 14)
      && !v271[6]
      && BBSupportDbgReportF(
           2,
           "Main\\States\\StateGameII.cpp",
           308,
           "m_iData != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
           *((unsigned __int8 *)v271 + 30),
           v271[3],
           v271[1],
           v271[2],
           *((unsigned __int16 *)v271 + 14)) == 1 )
    {
      __debugbreak();
    }
    if ( v271[6]
      && !*((_WORD *)v271 + 14)
      && BBSupportDbgReportF(
           2,
           "Main\\States\\StateGameII.cpp",
           312,
           "m_iDataSize != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
           *((unsigned __int8 *)v271 + 30),
           v271[3],
           v271[1],
           v271[2],
           *((unsigned __int16 *)v271 + 14)) == 1 )
    {
      __debugbreak();
    }
    v152 = v277;
    if ( !(*(unsigned __int8 (__thiscall **)(_DWORD, void **))(**((_DWORD **)v278 + 63) + 4))(
            *((_DWORD *)v278 + 63),
            v277)
      && BBSupportDbgReport(
           1,
           "Main\\States\\StateGameII.cpp",
           319,
           "Internal error (L1)- aborting!\nInterner Fehler (L1) aufgetreten! Programm wird abgebrochen!") == 1 )
    {
      __debugbreak();
    }
    return 1;
  }
  return result;
}


// address=[0x14b1950]
// Decompiled from int __thiscall CStateGame::GetCenterWorldCoordinate(CStateGame *this, int *a2, int *a3)
void  CStateGame::GetCenterWorldCoordinate(int &,int &) {
  
  int result; // eax

  *a2 = *((_DWORD *)this + 24) / (*((int *)this + 26) >> 16);
  *a3 = *((_DWORD *)this + 25) / (*((int *)this + 26) >> 17);
  result = *a2 + *a3 / 2;
  *a2 = result;
  return result;
}


// address=[0x14b4890]
// Decompiled from CStateGame *__thiscall CStateGame::ScrollHorizontal(CStateGame *this, bool a2)
void  CStateGame::ScrollHorizontal(bool) {
  
  CStateGame *result; // eax
  int ScrollStepValue; // [esp+4h] [ebp-4h]

  if ( a2 )
    ScrollStepValue = CGameSettings::GetScrollStepValue();
  else
    ScrollStepValue = -CGameSettings::GetScrollStepValue();
  result = this;
  *((_DWORD *)this + 24) += ScrollStepValue;
  return result;
}


// address=[0x14b48e0]
// Decompiled from CStateGame *__thiscall CStateGame::ScrollVertical(CStateGame *this, bool a2)
void  CStateGame::ScrollVertical(bool) {
  
  CStateGame *result; // eax
  int ScrollStepValue; // [esp+4h] [ebp-4h]

  if ( a2 )
    ScrollStepValue = CGameSettings::GetScrollStepValue();
  else
    ScrollStepValue = -CGameSettings::GetScrollStepValue();
  result = this;
  *((_DWORD *)this + 25) += ScrollStepValue;
  return result;
}


// address=[0x14a8a30]
// Decompiled from char __thiscall CStateGame::CheckAutosaveTimer(CStateGame *this)
void  CStateGame::CheckAutosaveTimer(void) {
  
  int TickCounter; // eax
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  bool v5; // [esp+8h] [ebp-14h]
  CConfigManager *Instance; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]

  Instance = CConfigManagerPtr::GetInstance();
  TickCounter = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))Instance->GetIntValueNoAdd)(
                  Instance,
                  "GAMESETTINGS",
                  "IsAutosaveEnabled",
                  1);
  if ( !TickCounter )
    return TickCounter;
  TickCounter = 60 * CGameSettings::GetAutosaveInterval();
  v7 = TickCounter;
  if ( TickCounter <= 0 )
    return TickCounter;
  LOBYTE(TickCounter) = CGameData::IsGameWon((CStateGame *)((char *)this + 76));
  if ( (_BYTE)TickCounter )
    return TickCounter;
  LOBYTE(TickCounter) = CStateGame::CanSave(this);
  if ( !(_BYTE)TickCounter )
    return TickCounter;
  v4 = CGameData::GetTickCounter((char *)this + 76) - *((_DWORD *)this + 74);
  v3 = sub_14A8B60(v4);
  if ( v7 < 60 )
    v7 = 60;
  LOBYTE(TickCounter) = v3;
  if ( v3 <= v7 )
    return TickCounter;
  v5 = CGameData::IsNetworkGame((CStateGame *)((char *)this + 76)) && !(unsigned __int8)CGameType::IsHost(g_pGameType);
  LOBYTE(TickCounter) = v5;
  if ( v5 )
    return TickCounter;
  CStateGame::SaveGame(this, 2);
  TickCounter = CGameData::GetTickCounter((char *)this + 76);
  *((_DWORD *)this + 74) = TickCounter;
  return TickCounter;
}


