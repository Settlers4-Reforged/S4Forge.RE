#include "CStateGame.h"

// Definitions for class CStateGame

// address=[0x1303890]
// Decompiled from int __thiscall CStateGame::GetTickCounter(CStateGame *this)
unsigned int  CStateGame::GetTickCounter(void) {
  
  return this->m_sGameData.m_uTickCounter;
}


// address=[0x130f320]
// Decompiled from char *__thiscall CStateGame::Random16(CStateGame *this)
class CRandom16 &  CStateGame::Random16(void) {
  
  return (char *)&this->m_sGameData.m_sRandom;
}


// address=[0x1326f20]
// Decompiled from DWORD __thiscall CStateGame::Rand(CStateGame *this)
unsigned int  CStateGame::Rand(void) {
  
  return CRandom16::Rand(&this->m_sGameData.m_sRandom);
}


// address=[0x14606d0]
// Decompiled from bool __thiscall CStateGame::IsMessage(CStateGame *this)
bool  CStateGame::IsMessage(void) {
  
  return ((int (__thiscall *)(CLogicRingBuffer *, CStateGame *))this->m_sLogicRingBuffer->Check)(
           this->m_sLogicRingBuffer,
           this);
}


// address=[0x14607a0]
// Decompiled from CEvn_Logic *__thiscall CStateGame::PopMessage(CStateGame *this, CEvn_Logic *__return_ptr retstr)
class CEvn_Logic  CStateGame::PopMessage(void retstr) {
  
  CEvn_Logic *v2; // eax

  v2 = (CEvn_Logic *)((int (__thiscall *)(CLogicRingBuffer *))this->m_sLogicRingBuffer->Read)(this->m_sLogicRingBuffer);
  CEvn_Logic::CEvn_Logic(retstr, v2);
  return retstr;
}


// address=[0x1486df0]
// Decompiled from CGameData *__thiscall CStateGame::GameData(CStateGame *this)
class CGameData &  CStateGame::GameData(void) {
  
  return &this->m_sGameData;
}


// address=[0x14a52f0]
// Decompiled from CStateGame *__cdecl CStateGame::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateGame::DynamicCreateFunc(void * a1) {
  
  CStateGame *C; // [esp+Ch] [ebp-10h]

  C = (CStateGame *)operator new(0x2D4u);
  if ( C )
    return CStateGame::CStateGame(C, a1);
  else
    return 0;
}


// address=[0x14a5370]
// Decompiled from void __thiscall CStateGame::UpdateToGuiInfoStruct(CStateGame *this)
void  CStateGame::UpdateToGuiInfoStruct(void) {
  
  int LocalPlayerId; // eax
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  size_t v4; // [esp-4h] [ebp-1ACh]
  struct std::string *v5; // [esp+4h] [ebp-1A4h]
  size_t v6; // [esp+8h] [ebp-1A0h]
  std::wstring *v7; // [esp+Ch] [ebp-19Ch]
  std::wstring *v8; // [esp+10h] [ebp-198h]
  int uLocalAliance; // [esp+18h] [ebp-190h]
  int ChatMessageFilter; // [esp+1Ch] [ebp-18Ch]
  int v11; // [esp+34h] [ebp-174h]
  int i; // [esp+3Ch] [ebp-16Ch]
  std::string v14; // [esp+44h] [ebp-164h] BYREF
  std::wstring v15; // [esp+60h] [ebp-148h] BYREF
  std::wstring v16; // [esp+7Ch] [ebp-12Ch] BYREF
  char Dest[256]; // [esp+98h] [ebp-110h] BYREF
  int v18; // [esp+1A4h] [ebp-4h]

  this->field_149 = 1;
  this->field_148 = 1;
  this->field_140 = 1;
  this->field_141 = 1;
  this->field_134 = 0;
  this->m_uGfxTextureQuality = CGameSettings::GetGfxTextureQuality();
  this->m_uGfxFiltering = CGameSettings::GetGfxFiltering();
  this->m_uGfxHighestResolution = CGameSettings::GetGfxHighestResolution();
  this->field_178 = 3;
  this->m_uMsgHistory = CGameSettings::GetMsgHistory();
  this->m_uMsgLevelMask = CGameSettings::GetMsgLevelMask();
  this->field_14C = 1;
  this->m_bSoundFxOn = CGameSettings::GetSoundFxOn() != 0;
  this->m_uSoundFXVolume = CGameSettings::GetSoundFXVolume();
  this->m_bMusicOn = CGameSettings::GetMusicOn() != 0;
  this->m_uMusicVolume = CGameSettings::GetMusicVolume();
  this->m_bVoiceChatOn = CGameSettings::GetVoiceChatOn() != 0;
  this->m_uVoiceChatVolume = CGameSettings::GetVoiceChatVolume();
  this->m_uVoiceChatMicro = CGameSettings::GetVoiceChatMicro();
  this->m_bUserMP3 = CGameSettings::GetUserMP3() != 0;
  this->field_164 = 2;
  if ( CGameData::IsTutorial(g_pGameData) )
    this->m_bExtendedTooltip = 1;
  else
    this->m_bExtendedTooltip = CGameSettings::GetExtendedTooltip();
  this->m_bBorderScrollEnabled = CGameSettings::GetBorderScrollEnabled();
  this->m_uScrollStepValue = CGameSettings::GetScrollStepValue();
  this->m_bAlwaysUrgentMsg = CGameSettings::GetAlwaysUrgentMsg();
  this->m_sChatInfo.m_sChatInfo = 4;
  this->m_sChatInfo.m_iActualPlayerCount = g_pGameType->m_iActualPlayerCount;
  this->m_sChatInfo.m_uLocalPlayerId = CPlayerManager::GetLocalPlayerId() - 1;
  ChatMessageFilter = CGameSettings::GetChatMessageFilter();
  v11 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  uLocalAliance = CAlliances::AllianceId(LocalPlayerId);
  for ( i = 1; i <= CPlayerManager::LastPlayerId(); ++i )
  {
    if ( CPlayerManager::IsAI(i) )
    {
      this->m_sChatInfo.m_asPlayerInfo[i - 1].m_bFilterMessages = 0;
      if ( CPlayerManager::GetPlayerControl(i) == 2 )
        *(&this->m_sChatInfo.m_iActualPlayerCount + 0xA * i) = 3;// m_uType
      else
        *(&this->m_sChatInfo.m_iActualPlayerCount + 10 * i) = 4;// m_uType
    }
    else
    {
      this->m_sChatInfo.m_asPlayerInfo[i - 1].m_bFilterMessages = (ChatMessageFilter & (1 << (i - 1))) != 0;
      *(&this->m_sChatInfo.m_iActualPlayerCount + 0xA * i) = 2;// m_uType
    }
    *(&this->m_sChatInfo.field_188 + 10 * i) = CPlayerManager::Color(i);// m_uColor
    this->m_sChatInfo.m_asPlayerInfo[i - 1].m_bIsAlliedToPlayer = CAlliances::AllianceId(i) != uLocalAliance;
    v8 = (std::wstring *)CPlayerManager::Name((int)&v15, i);
    v18 = 0;
    v2 = std::wstring::c_str(v8);
    v4 = wcslen(v2);
    v7 = (std::wstring *)CPlayerManager::Name((int)&v16, i);
    v3 = std::wstring::c_str(v7);
    v6 = j__wcstombs(Dest, v3, v4);
    std::wstring::~wstring(&v16);
    v18 = -1;
    std::wstring::~wstring(&v15);
    if ( v6 >= 0x100 )
      report_rangecheckfailure();
    Dest[v6] = 0;
    v5 = std::string::string(&v14, Dest);
    std::string::operator=(&this->m_bBorderScrollEnabled + 0x28 * i, v5);// m_sName
    std::string::~string(&v14);
    if ( this->m_sChatInfo.m_asPlayerInfo[i - 1].m_bFilterMessages )
      v11 |= 1 << (i - 1);
  }
  CGameSettings::SetChatMessageFilter(v11);
  s_uAIDifficulty = CGameSettings::GetAIDifficulty();
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
  CPlayerInfo *v2; // eax
  wchar_t *v3; // eax
  DWORD v4; // [esp+4h] [ebp-44h]
  std::wstring v6; // [esp+1Ch] [ebp-2Ch] BYREF
  int v7; // [esp+44h] [ebp-4h]

  CTrace::Print(
    "StateGame: Applying new sound settings: Music %u, Sound %u, MicVol %u, PlbkVol %u",
    this->m_uMusicVolume,
    this->m_uSoundFXVolume,
    this->m_uVoiceChatVolume,
    this->m_uVoiceChatMicro);
  if ( this->m_bMusicOn )
    CSoundManager::SetMusicVolume(g_pSoundManager, this->m_uMusicVolume);
  else
    CSoundManager::SetMusicVolume(g_pSoundManager, 0);
  if ( this->m_bSoundFxOn )
    CSoundManager::SetSoundVolume(g_pSoundManager, this->m_uSoundFXVolume);
  else
    CSoundManager::SetSoundVolume(g_pSoundManager, 0);
  if ( this->m_bVoiceChatOn )
    ISoundEngine::VCSetMicVolume(g_pSoundEngine, this->m_uVoiceChatVolume);
  else
    ISoundEngine::VCSetMicVolume(g_pSoundEngine, 0);
  if ( this->m_bVoiceChatOn )
    ISoundEngine::VCSetVolume(g_pSoundEngine, this->m_uVoiceChatMicro);
  else
    ISoundEngine::VCSetVolume(g_pSoundEngine, 0);
  if ( this->m_bUserMP3 )
  {
    CSoundManager::PlayDirectory((wchar_t *)L"Snd\\User");
  }
  else
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    v2 = CPlayerManager::PlayerInfo(LocalPlayerId);
    v4 = CPlayerInfo::Race(v2);
    std::wstring::wstring(&v6);
    v7 = 0;
    if ( g_pCDDrive->GetCDPath(g_pCDDrive, (char *)&v6, (char *)L"Snd\\Romans*.mp3", 196611) )
    {
      v3 = std::wstring::c_str(&v6);
      CSoundManager::PlayBackgroundMusic(v4, 0, v3);
    }
    v7 = -1;
    std::wstring::~wstring(&v6);
  }
}


// address=[0x14a5d70]
// Decompiled from char __thiscall CStateGame::IsInMinimap(CStateGame *this, struct tagPOINT *a2, struct tagPOINT *a3)
bool  CStateGame::IsInMinimap(struct tagPOINT * a2, struct tagPOINT * a3) {
  
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
  v4 = IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
  CGameData::SetLastFrameRendered(&this->m_sGameData, 1);
  this->m_uLastRenderTime = timeGetTime() - Time;
  return v4;
}


// address=[0x14a5e50]
// Decompiled from void __stdcall CStateGame::PerformCommand(char a1, int a2, int a3, int a4, int a5, int a6, int a7)
void  CStateGame::PerformCommand(std::string a1) {
  
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
  CFileEx v8; // [esp+1Ch] [ebp-7Ch] BYREF
  int v9; // [esp+94h] [ebp-4h]

  if ( g_pGUIEngine )
    CStateGame::ExitGUI(this);
  if ( g_pDialogData )
  {
    operator delete(g_pDialogData);
    g_pDialogData = 0;
  }
  CFileEx::CFileEx(&v8, UNUSED_ARG());
  v9 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v7 = CPlayerManager::Race(LocalPlayerId);
  switch ( v7 )
  {
    case 1:
      CFileEx::Open(
        &v8.IFileEx,
        (wchar_t *)L"Menu\\GUISetVikings.DAT",
        CFile_BINARY|CFile_READ,
        0,
        UNUSED_ARG(),
        UNUSED_ARG());
      break;
    case 2:
      CFileEx::Open(
        &v8.IFileEx,
        (wchar_t *)L"Menu\\GUISetMayas.DAT",
        CFile_BINARY|CFile_READ,
        0,
        UNUSED_ARG(),
        UNUSED_ARG());
      break;
    case 4:
      CFileEx::Open(
        &v8.IFileEx,
        (wchar_t *)L"Menu\\GUISetTrojans.DAT",
        CFile_BINARY|CFile_READ,
        0,
        UNUSED_ARG(),
        UNUSED_ARG());
      break;
    default:
      CFileEx::Open(
        &v8.IFileEx,
        (wchar_t *)L"Menu\\GUISetRomans.DAT",
        CFile_BINARY|CFile_READ,
        0,
        UNUSED_ARG(),
        UNUSED_ARG());
      break;
  }
  v2 = CFileEx::Size(&v8);
  g_pDialogData = operator new[](v2);
  v3 = CFileEx::Size(&v8);
  v5 = CFileEx::Read(&v8.IFileEx.__vftable, g_pDialogData, 1, v3, UNUSED_ARG(), UNUSED_ARG());
  if ( v5 != CFileEx::Size(&v8)
    && BBSupportDbgReport(2, "Main\\States\\StateGame.cpp", 1281, "iSize == file.Size()") == 1 )
  {
    __debugbreak();
  }
  CFileEx::Close(&v8.IFileEx, UNUSED_ARG(), UNUSED_ARG());
  if ( !CStateGame::InitGuiEngine(this, (char *)g_pDialogData) )
  {
    MessageBoxA(g_hWnd, "Error initializing User Interface!\nFehler beim Erstellen des User Interfaces!", "S4", 0x30u);
    j__exit(0);
  }
  IGuiEngine::EnableTooltipsExt(g_pGUIEngine, this->m_bExtendedTooltip != 0);
  v9 = -1;
  return CFileEx::~CFileEx(&v8);
}


// address=[0x14a61c0]
// Decompiled from char __thiscall CStateGame::ExitGUI(CStateGame *this)
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
    delete g_pGUIEngine;
    g_pGUIEngine = 0;
  }
  if ( !g_pDialogData )
    return IGuiEngine::EnableTooltipsExt(g_pGUIEngine, 0);
  operator delete(g_pDialogData);
  g_pDialogData = 0;
  return IGuiEngine::EnableTooltipsExt(g_pGUIEngine, 0);
}


// address=[0x14a62a0]
// Decompiled from char __thiscall CStateGame::InitGuiEngine(CStateGame *this, char *a2)
bool  CStateGame::InitGuiEngine(char * a2) {
  
  int Language; // eax
  CEvn_Event *v4; // [esp+4h] [ebp-60h]
  struct IEvn_Handle *v5; // [esp+14h] [ebp-50h]
  CGuiEventHandler *v6; // [esp+18h] [ebp-4Ch]
  struct IGuiEngine *v8; // [esp+20h] [ebp-44h]
  IGuiEngine *C; // [esp+24h] [ebp-40h]
  bool IsTutorial; // [esp+2Bh] [ebp-39h]
  CEvn_Event v11; // [esp+2Ch] [ebp-38h] BYREF
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
  g_pGUIEngine = v8;
  Language = CGameSettings::GetLanguage();
  IGuiEngine::Init(
    g_pGUIEngine,
    g_pGfxEngine,
    g_pGfxManager,
    (int)a2,
    0,
    (bool (__cdecl *)(int, int, int))GuiDlgMinimapProc,
    Language);
  IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
  IsTutorial = CGameData::IsTutorial(&this->m_sGameData);
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
  v4 = CEvn_Event::CEvn_Event(&v11, 0x272u, (unsigned int)&Rect, 0, 0);
  v13 = 2;
  IEventEngine::SendAMessage(g_pEvnEngine, v4);
  v13 = -1;
  CEvn_Event::~CEvn_Event(&v11);
  return 1;
}


// address=[0x14a6430]
// Decompiled from void __thiscall CStateGame::EndGame(CStateGame *this)
void  CStateGame::EndGame(void) {
  
  void *v1; // esp
  uchar LocalPlayerId; // al
  void *Instance; // eax
  unsigned int v4; // esi
  int v5; // eax
  int v6; // [esp-9A70h] [ebp-9AD4h] BYREF
  uint v7; // [esp-8h] [ebp-6Ch]
  int v8; // [esp-4h] [ebp-68h]
  int *v9; // [esp+8h] [ebp-5Ch]
  int CampaignStatus; // [esp+Ch] [ebp-58h]
  struct CEvn_Logic *v11; // [esp+10h] [ebp-54h]
  struct CEvn_Logic *v12; // [esp+14h] [ebp-50h]
  int v13; // [esp+18h] [ebp-4Ch]
  BOOL v14; // [esp+1Ch] [ebp-48h]
  CStateGame *v15; // [esp+20h] [ebp-44h]
  int m_iCampaignType; // [esp+24h] [ebp-40h]
  int v17; // [esp+28h] [ebp-3Ch]
  int v18; // [esp+2Ch] [ebp-38h]
  bool v19; // [esp+33h] [ebp-31h]
  CEvn_Logic v20; // [esp+34h] [ebp-30h] BYREF
  int v21; // [esp+60h] [ebp-4h]

  v15 = this;
  CEndStatistic::Init((CEndStatistic *)&g_cEndStatistic);
  v1 = alloca(39536);
  v9 = &v6;
  CStatistic::CStatistic((struct boost::exception_detail::clone_base *)&g_cStatistic);
  CEndStatistic::Update(&g_cEndStatistic);
  if ( !CGameData::IsTutorial(g_pGameData) )
  {
    if ( CGameData::GetMode(g_pGameData) == 3 )
      CGameStateHandler::Queue(CStateEcoStatistic::DynamicCreateFunc, 0);
    else
      CGameStateHandler::Queue(CStateEndStatistic::DynamicCreateFunc, 0);
  }
  v8 = 0;
  v7 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v12 = CEvn_Logic::CEvn_Logic(&v20, 0xFA2u, 0, 0, LocalPlayerId, v7, v8);
  v11 = v12;
  v21 = 0;
  INetworkEngine::SendNetMessage(g_pNetworkEngine, v12);
  v21 = -1;
  CEvn_Logic::~CEvn_Logic(&v20);
  v15->byte127 = 0;
  INetworkEngine::EndTick(g_pNetworkEngine);
  Instance = (void *)OnlineManager::GetInstance();
  OnlineManager::LeaveSession(Instance);
  v4 = CGameData::TeamWon(&v15->m_sGameData);
  v5 = CPlayerManager::GetLocalPlayerId();
  v14 = v4 == CAlliances::AllianceId(v5);
  v19 = v14;
  if ( CGameData::IsTutorial(&v15->m_sGameData) )
  {
    v18 = 3;
  }
  else if ( g_pGameType->m_iGameType == 3 )
  {
    if ( v19 )
    {
      CampaignStatus = CGameSettings::GetCampaignStatus(g_pGameType->m_iCampaignType);
      v13 = g_pGameType->m_iMissionId + 1;
      if ( v13 > CampaignStatus )
        CGameSettings::SetCampaignStatus(g_pGameType->m_iCampaignType, v13);
    }
    if ( g_pGameType->m_iCampaignType == 4 && v19 && g_pGameType->m_iMissionId == 11 )
    {
      if ( (unsigned __int8)CGameSettings::GetShowVideos() )
        CGameStateHandler::Queue((CStateMessageBox *(__cdecl *)(int))CStateVideo::DynamicCreateFunc, (void *)6);
      v18 = 0;
    }
    else if ( g_pGameType->m_iCampaignType == 15 && v19 )
    {
      if ( g_pGameType->m_iMissionId == 4 )
      {
        if ( (unsigned __int8)CGameSettings::GetShowVideos() )
          CGameStateHandler::Queue((CStateMessageBox *(__cdecl *)(int))CStateVideo::DynamicCreateFunc, (void *)9);
        v18 = 14;
      }
      if ( g_pGameType->m_iMissionId == 11 )
      {
        if ( (unsigned __int8)CGameSettings::GetShowVideos() )
          CGameStateHandler::Queue((CStateMessageBox *(__cdecl *)(int))CStateVideo::DynamicCreateFunc, (void *)10);
        v18 = 0;
      }
      v17 = g_pGameType->m_iMissionId + 1;
      v17 -= 2;
      switch ( v17 )
      {
        case 0:
        case 2:
        case 5:
        case 7:
        case 8:
          CGameStateHandler::Queue(CStateAOSplash::DynamicCreateFunc, (void *)g_pGameType->m_iMissionId);
          break;
        default:
          break;
      }
      v18 = 14;
    }
    else if ( g_pGameType->m_iCampaignType == 12 && v19 )
    {
      if ( g_pGameType->m_iMissionId == 1 )
        CGameStateHandler::Queue(CStateAOSplash::DynamicCreateFunc, (void *)0xFFFFFFFF);
      v18 = 13;
    }
    else if ( g_pGameType->m_iMissionId == 2
           && v19
           && (g_pGameType->m_iCampaignType == 1
            || g_pGameType->m_iCampaignType == 2
            || g_pGameType->m_iCampaignType == 3) )
    {
      CGameStateHandler::Queue(CStateVictoryScreen::DynamicCreateFunc, (void *)g_pGameType->m_iCampaignType);
      v18 = 0;
    }
    else
    {
      m_iCampaignType = g_pGameType->m_iCampaignType;
      switch ( --m_iCampaignType )
      {
        case 0:
        case 1:
        case 2:
          v18 = 2;
          break;
        case 3:
          v18 = 1;
          break;
        case 4:
          v18 = 6;
          break;
        case 5:
          v18 = 8;
          break;
        case 6:
          v18 = 7;
          break;
        case 7:
        case 8:
          v18 = 9;
          break;
        case 10:
          v18 = 11;
          break;
        case 11:
          v18 = 13;
          break;
        case 12:
          v18 = 12;
          break;
        case 13:
          v18 = 15;
          break;
        case 14:
          v18 = 14;
          break;
        case 16:
        case 17:
        case 18:
        case 19:
          v18 = 16;
          break;
        case 20:
        case 21:
        case 22:
        case 23:
          v18 = 17;
          break;
        default:
          v18 = 0;
          break;
      }
    }
  }
  else
  {
    v18 = 0;
  }
  CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, (void *)v18);
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
// Decompiled from void __thiscall CStateGame::SendLogicMessage(  CStateGame *this,  uint a2,  uint a3,  uint a4,  int a5,  uint a6,  unsigned int a7)
void  CStateGame::SendLogicMessage(unsigned int a2, unsigned int a3, long a4, unsigned int a5, unsigned int a6, unsigned int a7) {
  
  CEvn_Logic v8; // [esp+8h] [ebp-30h] BYREF
  int v9; // [esp+34h] [ebp-4h]

  if ( !this->byte47 )
  {
    if ( a6 && !a7 && BBSupportDbgReportF(2, "Main\\States\\StateGame.cpp", 1395, "iSize != 0: Message: %u", a2) == 1 )
      __debugbreak();
    if ( a7 && !a6 && BBSupportDbgReportF(2, "Main\\States\\StateGame.cpp", 1399, "iSize != NULL: Message: %u", a2) == 1 )
      __debugbreak();
    if ( CPlayerManager::IsAlive(a5) )
    {
      CEvn_Logic::CEvn_Logic(&v8, a2, a3, a4, a5, a6, a7);
      v9 = 0;
      if ( !((unsigned __int8 (__thiscall *)(CLogicRingBuffer *, CEvn_Logic *))this->m_sLogicRingBuffer->Write)(
              this->m_sLogicRingBuffer,
              &v8)
        && BBSupportDbgReportF(2, "Main\\States\\StateGame.cpp", 1410, "Unable to write to Logic Message Queue ") == 1 )
      {
        __debugbreak();
      }
      v9 = -1;
      CEvn_Logic::~CEvn_Logic(&v8);
    }
  }
}


// address=[0x14a6b40]
// Decompiled from bool __thiscall CStateGame::IsCursorChangeAllowed(CStateGame *this)
bool  CStateGame::IsCursorChangeAllowed(void) {
  
  return !this->byteF6 && !this->byte47;
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
 CStateGame::CStateGame(void * a2) {
  
  char IsMCD2TextureSet; // al
  int VirtualTick; // esi
  int ValidTick; // esi
  int LocalPlayerId; // eax
  float v6; // xmm0_4
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  int PlayerId; // eax
  unsigned int v12; // esi
  int v13; // eax
  int v14; // eax
  DWORD v15; // eax
  int v16; // eax
  DWORD v17; // eax
  int v18; // esi
  unsigned int v20; // [esp-4h] [ebp-2C8h]
  std::string *TypeString; // [esp+14h] [ebp-2B0h]
  int v22; // [esp+1Ch] [ebp-2A8h]
  int v23; // [esp+24h] [ebp-2A0h]
  struct std::string *v24; // [esp+30h] [ebp-294h]
  int v25; // [esp+34h] [ebp-290h]
  std::string *v26; // [esp+3Ch] [ebp-288h]
  struct CEvn_Event *v27; // [esp+4Ch] [ebp-278h]
  struct CEvn_Event *v28; // [esp+50h] [ebp-274h]
  struct CEvn_Event *v29; // [esp+58h] [ebp-26Ch]
  std::string *ModeString; // [esp+60h] [ebp-264h]
  int v31; // [esp+68h] [ebp-25Ch]
  int Instance; // [esp+6Ch] [ebp-258h]
  int i; // [esp+7Ch] [ebp-248h]
  bool v34; // [esp+81h] [ebp-243h]
  char v36[88]; // [esp+88h] [ebp-23Ch] BYREF
  char v37[88]; // [esp+E0h] [ebp-1E4h] BYREF
  std::string v38; // [esp+138h] [ebp-18Ch] BYREF
  struct std::string v39; // [esp+154h] [ebp-170h] BYREF
  std::string v40; // [esp+170h] [ebp-154h] BYREF
  std::string v41; // [esp+18Ch] [ebp-138h] BYREF
  std::string v42; // [esp+1A8h] [ebp-11Ch] BYREF
  std::string v43; // [esp+1C4h] [ebp-100h] BYREF
  CEvn_Event v44; // [esp+1E0h] [ebp-E4h] BYREF
  CEvn_Event v45; // [esp+1F8h] [ebp-CCh] BYREF
  CEvn_Event v46; // [esp+210h] [ebp-B4h] BYREF
  struct std::string v47; // [esp+228h] [ebp-9Ch] BYREF
  struct std::string v48; // [esp+244h] [ebp-80h] BYREF
  std::string v49; // [esp+260h] [ebp-64h] BYREF
  std::string v50; // [esp+27Ch] [ebp-48h] BYREF
  struct std::string v51; // [esp+298h] [ebp-2Ch] BYREF
  int exceptionBlock; // [esp+2C0h] [ebp-4h]

  CGameState::CGameState(this);
  exceptionBlock = 0;
  this->__vftable = (CGameState_vtbl *)&CStateGame::_vftable_;
  this->dword4 = 0;
  this->m_uLastRenderTime = 0;
  this->dwordC = 0;
  this->dword10 = 0;
  std::vector<CStateGame::CRC_HistoryEntry>::vector<CStateGame::CRC_HistoryEntry>(&this->m_vCRCHistory);
  std::vector<CStateGame::Random_HistoryEntry>::vector<CStateGame::Random_HistoryEntry>(&this->m_vRandomHistory);
  this->dword34 = 0;
  this->dword38 = 0;
  this->dword3C = 0;
  this->dword40 = 0;
  this->m_bAllowDebugString = 0;
  this->byte45 = 0;
  this->byte46 = 0;
  this->byte47 = 0;
  this->byte48 = 0;
  CGameData::CGameData(&this->m_sGameData);
  this->byteF4 = 0;
  this->byteF5 = 0;
  this->byteF6 = 0;
  this->byteF7 = 0;
  this->byteF8 = 0;
  this->m_sLogicRingBuffer = 0;
  this->dword100 = 0;
  this->dword104 = 0;
  this->dword118 = 0;
  this->dword11C = 0;
  this->dword120 = 0;
  this->byte124 = 0;
  this->byte125 = 0;
  this->byte126 = 0;
  this->byte127 = 0;
  this->m_uValidTick = 0;
  this->byte12C = 0;
  this->dword130 = 0;
  CChatInfo::CChatInfo(&this->m_sChatInfo);
  LOBYTE(exceptionBlock) = 4;
  if ( CGameType::IsMultiplayerGame(g_pGameType) )
  {
    Instance = UPlay::UPlayManager::GetInstance();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)Instance + 52))(Instance, 3);
  }
  else
  {
    v31 = UPlay::UPlayManager::GetInstance();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v31 + 52))(v31, 4);
  }
  IsMCD2TextureSet = CGameType::IsMCD2TextureSet(g_pGameType);
  CGfxManager::EnableMCD2Textures(g_pGfxManager, IsMCD2TextureSet);
  g_uDbgTickCounter = 0;
  g_iGameSpeed = 1;
  if ( g_pGfxEngine )
    IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 4u);
  this->dword4 = 0;
  this->m_uLastRenderTime = 0;
  this->dwordC = 0;
  this->dword10 = 0;
  this->dword34 = 0;
  this->dword38 = 0;
  this->dword3C = 0;
  this->dword40 = 0;
  this->m_bAllowDebugString = 0;
  std::string::string(&v51, "none");
  LOBYTE(exceptionBlock) = 5;
  v22 = g_pCfgMgr->GetStringValue(g_pCfgMgr, &v38, "COMMANDLINE", "events", &v51);
  LOBYTE(exceptionBlock) = 6;
  std::operator==<char>(v22, "record");
  LOBYTE(exceptionBlock) = 5;
  std::string::~string(&v38);
  LOBYTE(exceptionBlock) = 4;
  std::string::~string(&v51);
  std::string::string(&v47, "none");
  LOBYTE(exceptionBlock) = 7;
  v23 = g_pCfgMgr->GetStringValue(g_pCfgMgr, &v43, "COMMANDLINE", "events", &v47);
  LOBYTE(exceptionBlock) = 8;
  v34 = std::operator==<char>(v23, "play");
  LOBYTE(exceptionBlock) = 7;
  std::string::~string(&v43);
  LOBYTE(exceptionBlock) = 4;
  std::string::~string(&v47);
  v25 = g_pCfgMgr->GetIntValue(g_pCfgMgr, "COMMANDLINE", "stopevent", 0);
  if ( v34 )
  {
    std::string::string(&v48, "slot0.rec");
    LOBYTE(exceptionBlock) = 10;
    v26 = (std::string *)g_pCfgMgr->GetStringValue(g_pCfgMgr, &v40, "COMMANDLINE", "eventfile", &v48);
    LOBYTE(exceptionBlock) = 11;
    IEventEngine::PlayEvents(g_pEvnEngine, v26, v25);
    LOBYTE(exceptionBlock) = 10;
    std::string::~string(&v40);
    LOBYTE(exceptionBlock) = 4;
    std::string::~string(&v48);
  }
  else
  {
    v24 = std::string::string(&v39, "slot0.rec");
    LOBYTE(exceptionBlock) = 9;
    IEventEngine::RecordEvents(g_pEvnEngine, v24);
    LOBYTE(exceptionBlock) = 4;
    std::string::~string(&v39);
  }
  g_pGame = this;
  g_pGameData = &this->m_sGameData;
  if ( a2 && BBSupportDbgReport(2, "Main\\States\\StateGame.cpp", 246, "!_pvParam") == 1 )
    __debugbreak();
  this->dword120 = 0;
  this->dword10 = 0;
  this->dword118 = 0;
  this->dword11C = 0;
  this->m_uValidTick = INetworkEngine::GetValidTick(g_pNetworkEngine);
  this->byte12C = 0;
  this->dword130 = 2;
  this->dword4 = 0;
  this->m_uLastRenderTime = 0;
  this->dword40 = 0;
  this->dword34 = 0;
  this->dword38 = 0;
  this->byteF8 = 0;
  this->byteF4 = 0;
  this->byteF5 = 0;
  this->byteF6 = 0;
  this->byteF7 = 0;
  this->byte125 = 0;
  this->byte45 = 0;
  this->byte46 = 0;
  this->byte47 = 0;
  this->dwordC = 0;
  this->byte124 = 0;
  this->byte127 = 0;
  this->byte126 = 0;
  this->byte126 = 1;
  this->byte48 = 1;
  VirtualTick = INetworkEngine::GetVirtualTick(g_pNetworkEngine);
  CStateGame::GameData(g_pGame)->m_uVirtualTick = VirtualTick;
  ValidTick = INetworkEngine::GetValidTick(g_pNetworkEngine);
  CStateGame::GameData(g_pGame)->m_uTickCounter = ValidTick;
  IGfxEngine::SetTickCounterAdress(g_pGfxEngine, &this->m_sGameData.m_uVirtualTick);
  IEventEngine::SetTickPointer(g_pEvnEngine, &this->m_sGameData.m_uVirtualTick);
  CTextMsgHandler::Init();
  this->m_sGameData.m_iWidth = g_pGameType->m_iWidthHeight;
  this->m_sGameData.m_uUnknown = 0;
  this->m_sGameData.m_iHeight = g_pGameType->m_iWidthHeight;
  RegisterClasses();
  if ( CGameRun::Init() )
  {
    CMinimapHandler::Init();
    CGameStateHandler::RebuildGfxEngine(1);
    IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 4u);
    CGameSettings::SetChatMessageFilter(-1);
    CStateGame::UpdateToGuiInfoStruct(this);
    CStateGame::UpdateMusicSettings(this);
    CStateGame::SetupGUI(this);
    if ( CGameData::IsTutorial(&this->m_sGameData) )
      CTutorial::Init((CTutorial *)&g_cTutorial);
    CStateGame::NotifyGfxEngine(this);
    CStateGame::UpdateClientSize(this);
    CGfxManager::DisableGfxFile(g_pGfxManager, 1);
    CGfxManager::EnableGfxFile(g_pGfxManager, 1u, 8, 1u, -1);
    if ( !g_pGame->m_sGameData.m_bFixedStartCamera )
    {
      v20 = g_pGameType->m_sPlayerStartX[CPlayerManager::GetLocalPlayerId() + 8];
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      CStateGame::SetViewPos(this, g_pGameType->m_sPlayerPeerId[LocalPlayerId + 8], v20);
    }
    v6 = (float)(unsigned int)(this->m_sGameData.m_uZoom - 917504);
    v27 = CEvn_Event::CEvn_Event(&v44, 0x25Du, 0, (int)(float)((float)(v6 * 100.0) / 3801088.0), 0);
    LOBYTE(exceptionBlock) = 12;
    IEventEngine::SendAMessage(g_pEvnEngine, v27);
    LOBYTE(exceptionBlock) = 4;
    CEvn_Event::~CEvn_Event(&v44);
    CStateGame::EnableOrDisableDebugString(this, 0);
    BBSupportTracePrintF(1, "GameInfo:");
    BBSupportTracePrintF(1, "--------------------------------------------------");
    BBSupportTracePrintF(1, (char *)&byte_373E2D7);
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v37);
    LOBYTE(exceptionBlock) = 13;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
      &v49,
      &g_pGameType->m_swMapName);
    LOBYTE(exceptionBlock) = 14;
    v7 = std::string::c_str(&v49);
    BBSupportTracePrintF(1, "MapName:        %s", v7);
    LOBYTE(exceptionBlock) = 13;
    std::string::~string(&v49);
    LOBYTE(exceptionBlock) = 4;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v37);
    TypeString = CGameData::GetTypeString(&this->m_sGameData, &v41);
    LOBYTE(exceptionBlock) = 15;
    v8 = std::string::c_str(TypeString);
    BBSupportTracePrintF(1, "GameType:       %s", v8);
    LOBYTE(exceptionBlock) = 4;
    std::string::~string(&v41);
    ModeString = CGameData::GetModeString(&this->m_sGameData, &v42);
    LOBYTE(exceptionBlock) = 16;
    v9 = std::string::c_str(ModeString);
    BBSupportTracePrintF(1, "GameMode:       %s", v9);
    LOBYTE(exceptionBlock) = 4;
    std::string::~string(&v42);
    if ( g_pGameType->m_bIsSaveGame )
      BBSupportTracePrintF(1, "Saved Game:     %s", "Yes");
    else
      BBSupportTracePrintF(1, "Saved Game:     %s", "No");
    if ( g_pGameType->m_bIsSaveGame )
    {
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v36);
      LOBYTE(exceptionBlock) = 17;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
        &v50,
        &g_pGameType->m_swSaveFile);
      LOBYTE(exceptionBlock) = 18;
      v10 = std::string::c_str(&v50);
      BBSupportTracePrintF(1, "Save File:     %s", v10);
      LOBYTE(exceptionBlock) = 17;
      std::string::~string(&v50);
      LOBYTE(exceptionBlock) = 4;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v36);
    }
    BBSupportTracePrintF(1, "Starting Tick:  %d", g_pGameType->m_uiTickCounter);
    BBSupportTracePrintF(1, "Time Delay:\t    %d ms", g_pGameType->m_iNetworkTimeDelta);
    PlayerId = CPlayerManager::LastPlayerId();
    BBSupportTracePrintF(1, "Playercount:    %d", PlayerId);
    if ( INetworkEngine::IsHost(g_pNetworkEngine) )
      BBSupportTracePrintF(1, "Network:\t\t   %s", "Host");
    else
      BBSupportTracePrintF(1, "Network:\t\t   %s", "Client");
    BBSupportTracePrintF(1, "--------------------------------------------------");
    if ( CGameData::IsGameWon(&this->m_sGameData) && CGameData::GetMode(&this->m_sGameData) != 5 )
    {
      v12 = CGameData::TeamWon(&this->m_sGameData);
      v13 = CPlayerManager::GetLocalPlayerId();
      if ( v12 == CAlliances::AllianceId(v13) )
      {
        v29 = CEvn_Event::CEvn_Event(&v45, 0x261u, 1u, 0, 0);
        LOBYTE(exceptionBlock) = 19;
        IEventEngine::SendAMessage(g_pEvnEngine, v29);
        LOBYTE(exceptionBlock) = 4;
        CEvn_Event::~CEvn_Event(&v45);
        v14 = CPlayerManager::GetLocalPlayerId();
        v15 = CPlayerManager::Color(v14);
        CTextMsgHandler::AddTextMsg(2255, v15, 1);
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pFogging + 40))(g_pFogging, 1);
      }
      else
      {
        if ( CGameData::IsNetworkGame(&this->m_sGameData) )
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pFogging + 40))(g_pFogging, 1);
        v28 = CEvn_Event::CEvn_Event(&v46, 0x261u, 0, 0, 0);
        LOBYTE(exceptionBlock) = 20;
        IEventEngine::SendAMessage(g_pEvnEngine, v28);
        LOBYTE(exceptionBlock) = 4;
        CEvn_Event::~CEvn_Event(&v46);
        v16 = CPlayerManager::GetLocalPlayerId();
        v17 = CPlayerManager::Color(v16);
        CTextMsgHandler::AddTextMsg(2254, v17, 1);
        for ( i = 1; i < CPlayerManager::LastPlayerId(); ++i )
        {
          v18 = CAlliances::AllianceId(i);
          if ( v18 != CGameData::TeamWon(&this->m_sGameData) )
            CPlayerManager::PlayerDied(i);
        }
      }
    }
  }
  else
  {
    CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, (void *)0x960);
    CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
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
  CGameData *v11; // eax
  uchar LocalPlayerId; // al
  uchar v13; // al
  CGameData *v14; // eax
  uchar v15; // al
  LARGE_INTEGER PerformanceCount; // [esp+50h] [ebp-150h] BYREF
  _DWORD v17[2]; // [esp+58h] [ebp-148h] BYREF
  _DWORD v18[2]; // [esp+60h] [ebp-140h] BYREF
  CEvn_Event *v19; // [esp+68h] [ebp-138h]
  _DWORD *v20; // [esp+6Ch] [ebp-134h]
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
  _DWORD *v33; // [esp+A0h] [ebp-100h]
  CEvn_Event *v34; // [esp+A4h] [ebp-FCh]
  _DWORD *v35; // [esp+A8h] [ebp-F8h]
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
  uint ValidTick; // [esp+D8h] [ebp-C8h]
  unsigned int v48; // [esp+DCh] [ebp-C4h]
  char v49; // [esp+E3h] [ebp-BDh]
  CStateGame *v50; // [esp+E4h] [ebp-BCh]
  CEvn_Logic v51; // [esp+E8h] [ebp-B8h] BYREF
  CEvn_Logic v52; // [esp+108h] [ebp-98h] BYREF
  CEvn_Event v53; // [esp+128h] [ebp-78h] BYREF
  CEvn_Event v54; // [esp+140h] [ebp-60h] BYREF
  CEvn_Event v55; // [esp+158h] [ebp-48h] BYREF
  CEvn_Logic v56; // [esp+170h] [ebp-30h] BYREF
  int v57; // [esp+19Ch] [ebp-4h]

  v50 = this;
  v49 = 0;
  CGameData::SetLastFrameRendered(&this->m_sGameData, 0);
  switch ( g_iGameSpeed )
  {
    case 0:
      return 1;
    case 99:
      v48 = 71;
      g_iGameSpeed = 0;
      CStateGame::RenderFrame(v50);
      IGfxEngine::ShowFrame(g_pGfxEngine);
      break;
    case 1:
      v48 = 71;
      break;
    case 2:
      v48 = 47;
      break;
    default:
      v48 = 71u / (g_iGameSpeed - 1);
      break;
  }
  if ( (unsigned __int8)CGameSettings::GetBorderScrollEnabled() && CGameSettings::GetGfxFullscreenEnabled() )
    CStateGame::HandleBorderScroll(v50);
  if ( !v50->byte125 )
  {
    v36 = CEvn_Event::CEvn_Event(&v54, 0x27u, 0, 0, 0);
    v35 = &v36->__vftable;
    v57 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v36);
    v57 = -1;
    CEvn_Event::~CEvn_Event(&v54);
    v34 = CEvn_Event::CEvn_Event(&v55, 0x26Fu, 7u, 0, 0);
    v33 = &v34->__vftable;
    v57 = 1;
    IEventEngine::SendAMessage(g_pEvnEngine, v34);
    v57 = -1;
    CEvn_Event::~CEvn_Event(&v55);
    v19 = CEvn_Event::CEvn_Event(&v53, 0x6Au, 7u, 0, 0);
    v20 = &v19->__vftable;
    v57 = 2;
    IEventEngine::SendAMessage(g_pEvnEngine, v19);
    v57 = -1;
    CEvn_Event::~CEvn_Event(&v53);
    CTextMsgHandler::SendAllMessages(0, 1, 1);
    if ( CGameData::GetMode(&v50->m_sGameData) == 3 )
    {
      IGuiEngine::SelectControl(g_pGUIEngine, 0, 611, 1);
      IGuiEngine::SelectControl(g_pGUIEngine, 8, 929, 1);
    }
  }
  if ( !IEventEngine::DispatchSystemMessages(g_pEvnEngine) )
    return 0;
  INetworkEngine::DeliverNetMessages(g_pNetworkEngine);
  if ( v50->byte46 )
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
      BytesPerSecond = INetworkEngine::GetBytesPerSecond((CGameHost **)g_pNetworkEngine);
      CDebugFkt::SetFrameCounter(0.0, v38, v31, v32, v23, v24, v22, BytesPerSecond);
    }
    if ( !v50->dword4 )
      v50->dword4 = timeGetTime();
    Time = timeGetTime();
    v29 = Time - v50->dword4;
    if ( (unsigned __int8)CGameStateHandler::IsGrabbing() )
    {
      CStateGame::RenderFrame(v50);
      IGfxEngine::ShowFrame(g_pGfxEngine);
    }
    IGuiEngine::RenderGui(g_pGUIEngine);
    v50->dwordC >>= 1;
    if ( v29 >= 0 )
    {
      v9 = CStaticConfigVarInt::operator int(&g_iRenderSlice);
      if ( v50->dwordC >= v9 )
      {
        v49 = 1;
      }
      else
      {
        CStateGame::RenderFrame(v50);
        v50->dwordC |= 0x80000000;
      }
    }
    else
    {
      CStateGame::RenderFrame(v50);
      v50->dwordC |= 0x80000000;
      while ( v50->m_uLastRenderTime + timeGetTime() < v50->dword4 )
      {
        IGfxEngine::ShowFrame(g_pGfxEngine);
        if ( !IEventEngine::DispatchSystemMessages(g_pEvnEngine) )
          return 0;
        IGuiEngine::RenderGui(g_pGUIEngine);
        CStateGame::RenderFrame(v50);
      }
      Number = timeGetTime() - v50->dword4;
      if ( Number < 0 )
      {
        v8 = j__abs(Number);
        Sleep(v8);
      }
    }
    QueryPerformanceCounter(&::PerformanceCount);
    if ( !v50->byte47 )
    {
      v44 = 0;
      do
      {
        VirtualTick = INetworkEngine::GetVirtualTick(g_pNetworkEngine);
        CStateGame::GameData(g_pGame)->m_uVirtualTick = VirtualTick;
        if ( !IEventEngine::DispatchSystemMessages(g_pEvnEngine) )
          return 0;
        INetworkEngine::DeliverNetMessages(g_pNetworkEngine);
        if ( INetworkEngine::StartNewTick((CGameHost **)g_pNetworkEngine, 0) )
        {
          INetworkEngine::StartNewTick((CGameHost **)g_pNetworkEngine, 1);
          ValidTick = INetworkEngine::GetValidTick(g_pNetworkEngine);
          v11 = CStateGame::GameData(g_pGame);
          v11->m_uTickCounter = ValidTick;
          g_uDbgTickCounter = ValidTick;
          if ( !CStateGame::GameData(g_pGame)->m_uTickCounter
            && BBSupportDbgReport(2, "Main\\States\\StateGame.cpp", 682, "g_pGame->GameData().m_uTickCounter != 0") == 1 )
          {
            __debugbreak();
          }
          if ( v50->byte127 )
          {
            CStateGame::EndGame(v50);
            return 1;
          }
          CStateGame::CheckAutosaveTimer(v50);
          if ( v50->byte12C )
          {
            LocalPlayerId = CPlayerManager::GetLocalPlayerId();
            CEvn_Logic::CEvn_Logic(&v56, 0xFA8u, v50->dword130, 0, LocalPlayerId, 0, 0);
            v57 = 3;
            if ( std::wstring::length(&stru_403037C) )
            {
              v56.m_iData = (BYTE *)std::wstring::c_str(&stru_403037C);
              v56.m_iDataSize = 2 * std::wstring::size(&stru_403037C);
            }
            INetworkEngine::SendNetMessage(g_pNetworkEngine, &v56);
            v50->m_uValidTick = ValidTick;
            v50->byte12C = 0;
            v57 = -1;
            CEvn_Logic::~CEvn_Logic(&v56);
          }
          if ( CGameData::IsNetworkGame(&v50->m_sGameData) )
          {
            if ( (COMMUNICATION_TICK_VALUE & IEventEngine::GetCurrentTickCounter(g_pEvnEngine)) == 0 )
            {
              v45 = (const char *)CGameData::Rand(g_pGameData);
              v18[1] = v45;
              v18[0] = ValidTick;
              std::vector<CStateGame::Random_HistoryEntry>::push_back((int)v18);
              v13 = CPlayerManager::GetLocalPlayerId();
              v28 = CEvn_Logic::CEvn_Logic(&v51, 0xFA3u, (uint)v45, ValidTick, v13, 0, 0);
              v27 = v28;
              v57 = 4;
              INetworkEngine::SendNetMessage(g_pNetworkEngine, v28);
              v57 = -1;
              CEvn_Logic::~CEvn_Logic(&v51);
              v14 = CStateGame::GameData(g_pGame);
              v50->dword10 = v14->m_uTickCounter;
            }
            if ( (COMMUNICATION_TICK_VALUE & IEventEngine::GetCurrentTickCounter(g_pEvnEngine)) == 0 )
            {
              v45 = (const char *)CMapObjectMgr::CRCLogicUpdate();
              v17[1] = v45;
              v17[0] = ValidTick;
              std::vector<CStateGame::CRC_HistoryEntry>::push_back((int)v17);
              v15 = CPlayerManager::GetLocalPlayerId();
              v26 = CEvn_Logic::CEvn_Logic(&v52, 0xFA6u, (uint)v45, ValidTick, v15, 0, 0);
              v25 = v26;
              v57 = 5;
              INetworkEngine::SendNetMessage(g_pNetworkEngine, v26);
              v57 = -1;
              CEvn_Logic::~CEvn_Logic(&v52);
            }
          }
          CGameRun::Run();
          if ( !CGameType::IsHost(g_pGameType) )
            Sleep(0xDCu);
          INetworkEngine::EndTick(g_pNetworkEngine);
          ++v44;
        }
      }
      while ( v50->byte45 && v44 < 840 && !CGameData::IsNetworkGame(&v50->m_sGameData) );
      if ( v50->byte45 )
      {
        if ( !v49 )
          IGfxEngine::ShowFrame(g_pGfxEngine);
        IGfxEngine::RenderFrame(g_pGfxEngine, 1, 0);
        v49 = 0;
        v50->dword4 = v48 + timeGetTime();
        v50->byte45 = 0;
      }
    }
    if ( !v49 )
      IGfxEngine::ShowFrame(g_pGfxEngine);
    v50->dword4 += v48;
    if ( !CGameData::IsNetworkGame(&v50->m_sGameData) && v48 == 71 )
      v50->dword4 = timeGetTime() + 71;
  }
  else
  {
    IGuiEngine::RenderGui(g_pGUIEngine);
    CStateGame::RenderFrame(v50);
    IGfxEngine::ShowFrame(g_pGfxEngine);
  }
  if ( v50->byte125 )
    return 1;
  INetworkEngine::GameInitalized((CGameHost **)g_pNetworkEngine);
  v50->byte125 = 1;
  return 1;
}


// address=[0x14a87c0]
// Decompiled from double __thiscall CStateGame::GetZoomFactor(CStateGame *this)
float  CStateGame::GetZoomFactor(void) {
  
  float v1; // xmm0_4

  v1 = (float)(unsigned int)(this->m_sGameData.m_uZoom - 917504);
  return (float)((float)(v1 * 100.0) / 3801088.0);
}


// address=[0x14a8820]
// Decompiled from void __thiscall CStateGame::NotifyGfxEngine(CStateGame *this)
void  CStateGame::NotifyGfxEngine(void) {
  
  size_t v1; // eax
  unsigned __int16 *MapObjectPtr; // eax
  struct T_GFX_MAP_ELEMENT *LandscapePtr; // [esp-4h] [ebp-8h]
  unsigned __int8 *DecoObjectPtr; // [esp-4h] [ebp-8h]

  LandscapePtr = CWorldManager::GetLandscapePtr();
  v1 = CWorldManager::Width();
  IGfxEngine::SetGfxLayerAccess(g_pGfxEngine, v1, LandscapePtr);
  DecoObjectPtr = CWorldManager::GetDecoObjectPtr();
  MapObjectPtr = CWorldManager::GetMapObjectPtr();
  IGfxEngine::SetObjectLayerAccess(g_pGfxEngine, MapObjectGetGfxInfo, MapObjectPtr, (unsigned __int16 *)DecoObjectPtr);
  IGfxEngine::SetMiniMapColorCallback(g_pGfxEngine, CWorldManager::GetMiniMapColor);
  IGfxEngine::SetIconCallbacks(
    g_pGfxEngine,
    CWorldManager::WorldSetNumberOfNextLine,
    CWorldManager::WorldGetIconObjectByX);
  IGfxEngine::EnableIconLayer(g_pGfxEngine, 0);
  (*(void (__thiscall **)(void *, CStateGame *))(*(_DWORD *)g_pFogging + 16))(g_pFogging, this);
}


// address=[0x14a88b0]
// Decompiled from char __thiscall CStateGame::EnableOrDisableDebugString(CStateGame *this, bool a2)
bool  CStateGame::EnableOrDisableDebugString(bool a2) {
  
  char byte44; // [esp+7h] [ebp-1h]

  byte44 = this->m_bAllowDebugString;
  if ( a2 )
    IGfxEngine::EnableDebugStringCallback(g_pGfxEngine, (char *(__cdecl *)())CDebugFkt::DebugString);
  else
    IGfxEngine::EnableDebugStringCallback(g_pGfxEngine, 0);
  this->m_bAllowDebugString = a2;
  return byte44;
}


// address=[0x14a8900]
// Decompiled from bool __thiscall CStateGame::CanSave(CStateGame *this)
bool  CStateGame::CanSave(void) {
  
  return !this->byte47
      && !CGameData::IsTutorial(&this->m_sGameData)
      && (!CGameData::IsNetworkGame(&this->m_sGameData)
       || (unsigned int)(CGameData::GetTickCounter(&this->m_sGameData) - this->m_uValidTick) > 0x348)
      && !CGameData::IsLadder(&this->m_sGameData);
}


// address=[0x14a8980]
// Decompiled from _DWORD *__thiscall CStateGame::SaveGame(int this, unsigned int a2)
void  CStateGame::SaveGame(enum SaveType a2) {
  
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
void  CStateGame::ZoomIn(int a2) {
  
  int v2; // [esp+0h] [ebp-Ch]

  if ( (unsigned int)(this->m_sGameData.m_uZoom + 20000 * a2) <= 0x480000 )
    v2 = this->m_sGameData.m_uZoom + 20000 * a2;
  else
    v2 = 4718592;
  CStateGame::UpdateTriangleSizePreservingWorldPosition(this, v2);
  CStateGame::UpdateZoomFactor(this);
}


// address=[0x14ac980]
// Decompiled from void __thiscall CStateGame::ZoomOut(CStateGame *this, int a2)
void  CStateGame::ZoomOut(int a2) {
  
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
void  CStateGame::UpdateTriangleSizePreservingWorldPosition(int a2) {
  
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
    (int)((double)(unsigned int)(this->m_sGameData.m_uZoom - 0xE0000) * 100.0 / 3801088.0),
    0);
  v4 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v3);
  v4 = -1;
  return CEvn_Event::~CEvn_Event(&v3);
}


// address=[0x14acb10]
// Decompiled from char __thiscall CStateGame::VerifyWorldOffset(CStateGame *this)
void  CStateGame::VerifyWorldOffset(void) {
  
  int v2; // [esp+Ch] [ebp-3Ch]
  int v3; // [esp+10h] [ebp-38h]
  float v4; // [esp+28h] [ebp-20h]
  float v5; // [esp+30h] [ebp-18h]
  int OutputHeight; // [esp+34h] [ebp-14h]
  int OutputWidth; // [esp+38h] [ebp-10h]
  int dword18; // [esp+3Ch] [ebp-Ch]

  if ( this->m_sGameData.m_uCamY >= this->m_sGameData.m_uUnknown * ((int)this->m_sGameData.m_uZoom >> 16) )
  {
    if ( this->m_sGameData.m_uCamY > this->m_sGameData.m_iWidth * ((int)this->m_sGameData.m_uZoom >> 16) / 2 )
      this->m_sGameData.m_uCamY = this->m_sGameData.m_iWidth * ((int)this->m_sGameData.m_uZoom >> 16) / 2;
  }
  else
  {
    this->m_sGameData.m_uCamY = this->m_sGameData.m_uUnknown * ((int)this->m_sGameData.m_uZoom >> 16);
  }
  dword18 = this->m_sGameData.m_uCamY;
  if ( this->m_sGameData.m_uCamX >= this->m_sGameData.m_uUnknown * ((int)this->m_sGameData.m_uZoom >> 16) - dword18 )
  {
    if ( this->m_sGameData.m_uCamX > this->m_sGameData.m_iWidth * ((int)this->m_sGameData.m_uZoom >> 16) - dword18 )
      this->m_sGameData.m_uCamX = this->m_sGameData.m_iWidth * ((int)this->m_sGameData.m_uZoom >> 16) - dword18;
  }
  else
  {
    this->m_sGameData.m_uCamX = this->m_sGameData.m_uUnknown * ((int)this->m_sGameData.m_uZoom >> 16) - dword18;
  }
  OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
  OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
  v5 = sub_14B4620((float)OutputWidth, 800.0, 2560.0);
  v4 = sub_14B4620((float)OutputHeight, 600.0, 1440.0);
  v2 = this->m_sGameData.m_uCamX - (int)(float)((float)(OutputWidth + 100) + (float)(v5 * 40.0)) / 2;
  v3 = this->m_sGameData.m_uCamY - (int)(float)((float)(OutputHeight + 300) + (float)(v4 * 60.0)) / 2;
  IGfxEngine::SetTriangleSize(g_pGfxEngine, this->m_sGameData.m_uZoom);
  return IGfxEngine::SetScrollOffsets(g_pGfxEngine, v2, v3);
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
// Decompiled from char __thiscall CStateGame::SetViewPos(CStateGame *this, unsigned int a2, unsigned int a3)
void  CStateGame::SetViewPos(unsigned int a2, unsigned int a3) {
  
  signed int v3; // kr00_4

  v3 = a3 * ((int)this->m_sGameData.m_uZoom >> 16);
  this->m_sGameData.m_uCamX = a2 * ((int)this->m_sGameData.m_uZoom >> 16) - v3 / 2;
  this->m_sGameData.m_uCamY = v3 / 2;
  return CStateGame::VerifyWorldOffset(this);
}


// address=[0x14ace40]
// Decompiled from void __thiscall CStateGame::UpdateClientSize(CStateGame *this)
void  CStateGame::UpdateClientSize(void) {
  
  this->m_uClientSizeRelated210 = 210;
  this->m_uClientSizeRelated = 0;
  this->m_uClientWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
  this->m_uClientHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
  if ( g_pGUIEngine )
    IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
  this->m_uClientSizeRelated210 = 210;
}


// address=[0x14aceb0]
// Decompiled from char __thiscall CStateGame::OnEvent(CStateGame *this, struct CEvn_Logic *_sEvent)
bool  CStateGame::OnEvent(class CEvn_Event & _sEvent) {
  
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
  wchar_t *v13; // eax
  wchar_t *v14; // eax
  int v15; // eax
  int v16; // eax
  wchar_t *v17; // eax
  wchar_t *v18; // eax
  int v19; // eax
  int Instance; // eax
  char *v21; // eax
  unsigned int v22; // eax
  int LocalPlayerId; // eax
  int *v24; // eax
  int v25; // edx
  int v26; // eax
  int *v27; // eax
  int v28; // edx
  int v29; // eax
  __int16 v30; // ax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  wchar_t *v38; // eax
  int v39; // eax
  int v40; // eax
  std::wstring *RealPlayerName; // eax
  CGameData *v42; // eax
  int v43; // eax
  CGameData *v44; // eax
  char *v45; // eax
  uchar v46; // al
  char ChatMessageFilter; // si
  char v48; // al
  wchar_t *v49; // eax
  int v50; // eax
  int v51; // eax
  char v52; // al
  CPlayerInfo *v53; // eax
  pairNode *v54; // eax
  unsigned int v55; // eax
  CPlayerInfo *v56; // eax
  pairNode *v57; // eax
  unsigned int v58; // eax
  uchar v59; // al
  uchar v60; // al
  uchar v61; // al
  std::string v62; // [esp-1Ch] [ebp-C30h] BYREF
  const char *v63; // [esp+0h] [ebp-C14h]
  void *v64; // [esp+4h] [ebp-C10h]
  struct tagPOINT v65; // [esp+8h] [ebp-C0Ch] BYREF
  _BYTE v66[12]; // [esp+10h] [ebp-C04h] BYREF
  _BYTE v67[12]; // [esp+1Ch] [ebp-BF8h] BYREF
  _BYTE v68[12]; // [esp+28h] [ebp-BECh] BYREF
  _BYTE v69[12]; // [esp+34h] [ebp-BE0h] BYREF
  _BYTE v70[12]; // [esp+40h] [ebp-BD4h] BYREF
  _BYTE v71[12]; // [esp+4Ch] [ebp-BC8h] BYREF
  int v72; // [esp+58h] [ebp-BBCh]
  std::string *v73; // [esp+5Ch] [ebp-BB8h]
  int v74; // [esp+60h] [ebp-BB4h]
  int *v75; // [esp+64h] [ebp-BB0h]
  int v76; // [esp+6Ch] [ebp-BA8h]
  int v77; // [esp+70h] [ebp-BA4h]
  double v78; // [esp+74h] [ebp-BA0h]
  int *v79; // [esp+80h] [ebp-B94h]
  int v80; // [esp+84h] [ebp-B90h]
  int v81; // [esp+88h] [ebp-B8Ch]
  int v82; // [esp+8Ch] [ebp-B88h]
  int *p_m_uU14; // [esp+90h] [ebp-B84h]
  int v84; // [esp+94h] [ebp-B80h]
  int v85; // [esp+98h] [ebp-B7Ch]
  std::string *v86; // [esp+9Ch] [ebp-B78h]
  int v87; // [esp+A0h] [ebp-B74h]
  int *p_m_uU10; // [esp+A4h] [ebp-B70h]
  std::string *v89; // [esp+A8h] [ebp-B6Ch]
  std::string *v90; // [esp+ACh] [ebp-B68h]
  int v91; // [esp+B0h] [ebp-B64h]
  _BYTE v92[12]; // [esp+B4h] [ebp-B60h] BYREF
  struct tagPOINT v93; // [esp+C0h] [ebp-B54h] BYREF
  struct tagPOINT v94; // [esp+C8h] [ebp-B4Ch] BYREF
  struct tagPOINT v95; // [esp+D0h] [ebp-B44h] BYREF
  int v96; // [esp+D8h] [ebp-B3Ch]
  int v97; // [esp+DCh] [ebp-B38h]
  int v98; // [esp+E0h] [ebp-B34h]
  int v99; // [esp+E4h] [ebp-B30h]
  double v100; // [esp+E8h] [ebp-B2Ch]
  _BYTE v101[12]; // [esp+F0h] [ebp-B24h] BYREF
  _DWORD *v102; // [esp+FCh] [ebp-B18h]
  std::wstring *v103; // [esp+100h] [ebp-B14h]
  std::wstring *v104; // [esp+104h] [ebp-B10h]
  std::wstring *v105; // [esp+108h] [ebp-B0Ch]
  size_t v106; // [esp+10Ch] [ebp-B08h]
  int FirstBuildingId; // [esp+110h] [ebp-B04h]
  std::wstring *v108; // [esp+114h] [ebp-B00h]
  std::wstring *v109; // [esp+118h] [ebp-AFCh]
  std::wstring *v110; // [esp+11Ch] [ebp-AF8h]
  size_t v111; // [esp+120h] [ebp-AF4h]
  std::string *v112; // [esp+124h] [ebp-AF0h]
  std::string *v113; // [esp+128h] [ebp-AECh]
  struct CEvn_Logic *v114; // [esp+12Ch] [ebp-AE8h]
  int m_lParam; // [esp+130h] [ebp-AE4h] BYREF
  int v116; // [esp+134h] [ebp-AE0h]
  std::_Iterator_base12 *v117; // [esp+138h] [ebp-ADCh]
  std::_Iterator_base12 *v118; // [esp+13Ch] [ebp-AD8h]
  struct std::_Iterator_base12 *v119; // [esp+140h] [ebp-AD4h]
  struct std::_Iterator_base12 *v120; // [esp+144h] [ebp-AD0h]
  int v121; // [esp+148h] [ebp-ACCh] BYREF
  int v122; // [esp+14Ch] [ebp-AC8h]
  std::_Iterator_base12 *v123; // [esp+150h] [ebp-AC4h]
  std::_Iterator_base12 *v124; // [esp+154h] [ebp-AC0h]
  struct std::_Iterator_base12 *v125; // [esp+158h] [ebp-ABCh]
  int v126; // [esp+15Ch] [ebp-AB8h]
  unsigned int v127; // [esp+160h] [ebp-AB4h]
  int v128; // [esp+164h] [ebp-AB0h] BYREF
  int v129; // [esp+168h] [ebp-AACh] BYREF
  int Number; // [esp+16Ch] [ebp-AA8h]
  int v131; // [esp+170h] [ebp-AA4h]
  int ClosestMapPoint; // [esp+174h] [ebp-AA0h]
  int v133; // [esp+178h] [ebp-A9Ch]
  int v134; // [esp+180h] [ebp-A94h]
  int v135; // [esp+184h] [ebp-A90h]
  unsigned int v136; // [esp+188h] [ebp-A8Ch]
  unsigned int v137; // [esp+18Ch] [ebp-A88h]
  uint v138; // [esp+190h] [ebp-A84h]
  int v139; // [esp+194h] [ebp-A80h]
  struct std::_Iterator_base12 *v140; // [esp+198h] [ebp-A7Ch]
  struct tagPOINT Point; // [esp+19Ch] [ebp-A78h] BYREF
  CEvn_Event *v142; // [esp+1A4h] [ebp-A70h]
  _DWORD *v143; // [esp+1A8h] [ebp-A6Ch]
  CEvn_Event *v144; // [esp+1ACh] [ebp-A68h]
  struct CEvn_Logic *v145; // [esp+1B0h] [ebp-A64h]
  struct CEvn_Logic *v146; // [esp+1B4h] [ebp-A60h]
  uint v147; // [esp+1B8h] [ebp-A5Ch]
  unsigned int v148; // [esp+1BCh] [ebp-A58h]
  CEvn_Event *v149; // [esp+1C0h] [ebp-A54h]
  int v150; // [esp+1C8h] [ebp-A4Ch]
  CEvn_Logic *v151; // [esp+1CCh] [ebp-A48h]
  uint v152; // [esp+1D4h] [ebp-A40h]
  CEvn_Logic *v153; // [esp+1D8h] [ebp-A3Ch]
  CEvn_Logic *v154; // [esp+1E0h] [ebp-A34h]
  struct std::string *v155; // [esp+1E8h] [ebp-A2Ch]
  struct std::string *v156; // [esp+1F0h] [ebp-A24h]
  CEvn_Event *v157; // [esp+1F8h] [ebp-A1Ch]
  CEvn_Event *v158; // [esp+200h] [ebp-A14h]
  CEvn_Event *v159; // [esp+208h] [ebp-A0Ch]
  unsigned int v160; // [esp+210h] [ebp-A04h]
  int v161; // [esp+214h] [ebp-A00h]
  CEvn_Event *v162; // [esp+218h] [ebp-9FCh]
  std::wstring *v163; // [esp+220h] [ebp-9F4h]
  int v164; // [esp+224h] [ebp-9F0h]
  CEvn_Event *v165; // [esp+228h] [ebp-9ECh]
  CEvn_Event *v166; // [esp+230h] [ebp-9E4h]
  CEvn_Event *v167; // [esp+238h] [ebp-9DCh]
  CEvn_Event *v168; // [esp+240h] [ebp-9D4h]
  CEvn_Event *v169; // [esp+248h] [ebp-9CCh]
  CEvn_Event *v170; // [esp+250h] [ebp-9C4h]
  CEvn_Event *v171; // [esp+258h] [ebp-9BCh]
  CEvn_Event *v172; // [esp+260h] [ebp-9B4h]
  CEvn_Event *v173; // [esp+268h] [ebp-9ACh]
  unsigned int CursorShape; // [esp+270h] [ebp-9A4h]
  CEvn_Event *v175; // [esp+274h] [ebp-9A0h]
  std::wstring *v176; // [esp+27Ch] [ebp-998h]
  int v177; // [esp+280h] [ebp-994h]
  wchar_t *S2; // [esp+284h] [ebp-990h]
  CEvn_Event *v179; // [esp+288h] [ebp-98Ch]
  struct tagPOINT v180; // [esp+28Ch] [ebp-988h] BYREF
  LONG OutputWidth; // [esp+294h] [ebp-980h]
  LONG OutputHeight; // [esp+298h] [ebp-97Ch]
  size_t v183; // [esp+29Ch] [ebp-978h]
  size_t v184; // [esp+2A0h] [ebp-974h]
  int v185; // [esp+2A4h] [ebp-970h]
  uint v186; // [esp+2ACh] [ebp-968h]
  int v187; // [esp+2B0h] [ebp-964h]
  unsigned int v188; // [esp+2B4h] [ebp-960h]
  int (__cdecl *v189)(int, int); // [esp+2B8h] [ebp-95Ch]
  int v190; // [esp+2BCh] [ebp-958h]
  BOOL v191; // [esp+2C0h] [ebp-954h]
  BOOL v192; // [esp+2C4h] [ebp-950h]
  int v193; // [esp+2C8h] [ebp-94Ch]
  size_t v194; // [esp+2CCh] [ebp-948h]
  char *v195; // [esp+2D0h] [ebp-944h]
  int v196; // [esp+2D4h] [ebp-940h]
  int v197; // [esp+2D8h] [ebp-93Ch]
  int v198; // [esp+2DCh] [ebp-938h]
  int v199; // [esp+2E0h] [ebp-934h]
  int v200; // [esp+2E4h] [ebp-930h]
  struct CEvn_Logic *v201; // [esp+2E8h] [ebp-92Ch]
  uint v202; // [esp+2ECh] [ebp-928h]
  uint v203; // [esp+2F0h] [ebp-924h]
  uint v204; // [esp+2F4h] [ebp-920h]
  int v205; // [esp+2F8h] [ebp-91Ch]
  int v206; // [esp+2FCh] [ebp-918h]
  uint v207; // [esp+300h] [ebp-914h]
  uint v208; // [esp+304h] [ebp-910h]
  int x; // [esp+308h] [ebp-90Ch]
  unsigned int v210; // [esp+30Ch] [ebp-908h]
  int v211; // [esp+310h] [ebp-904h]
  int v212; // [esp+314h] [ebp-900h]
  unsigned int v213; // [esp+318h] [ebp-8FCh]
  int v214; // [esp+31Ch] [ebp-8F8h]
  int v215; // [esp+320h] [ebp-8F4h]
  struct tagPOINT v216; // [esp+324h] [ebp-8F0h] BYREF
  int v217; // [esp+32Ch] [ebp-8E8h]
  struct CEvn_Logic *v218; // [esp+330h] [ebp-8E4h]
  char *Source; // [esp+334h] [ebp-8E0h]
  int v220; // [esp+338h] [ebp-8DCh]
  int v221; // [esp+33Ch] [ebp-8D8h] BYREF
  int v222; // [esp+340h] [ebp-8D4h] BYREF
  int v223; // [esp+344h] [ebp-8D0h] BYREF
  int v224; // [esp+348h] [ebp-8CCh] BYREF
  uint v225; // [esp+34Ch] [ebp-8C8h]
  struct CEvn_Logic *v226; // [esp+350h] [ebp-8C4h]
  int v228; // [esp+358h] [ebp-8BCh]
  struct tagPOINT v229; // [esp+35Ch] [ebp-8B8h] BYREF
  int v230; // [esp+364h] [ebp-8B0h]
  int v231; // [esp+36Ch] [ebp-8A8h]
  uint v232; // [esp+370h] [ebp-8A4h]
  uint v233; // [esp+374h] [ebp-8A0h]
  unsigned int v234; // [esp+378h] [ebp-89Ch]
  int v235; // [esp+37Ch] [ebp-898h]
  unsigned int m_lParam_high; // [esp+380h] [ebp-894h]
  IEntity *n; // [esp+384h] [ebp-890h]
  signed int v238; // [esp+388h] [ebp-88Ch]
  signed int v239; // [esp+38Ch] [ebp-888h]
  uint v240; // [esp+390h] [ebp-884h]
  int k; // [esp+394h] [ebp-880h]
  int m_wParam; // [esp+398h] [ebp-87Ch]
  struct CEvn_Logic *v243; // [esp+39Ch] [ebp-878h]
  int v244; // [esp+3A0h] [ebp-874h]
  bool v245; // [esp+3A4h] [ebp-870h]
  bool v246; // [esp+3A5h] [ebp-86Fh]
  char v247; // [esp+3A6h] [ebp-86Eh]
  char v248; // [esp+3A7h] [ebp-86Dh]
  int m; // [esp+3A8h] [ebp-86Ch]
  int j; // [esp+3ACh] [ebp-868h]
  char v251; // [esp+3B1h] [ebp-863h]
  char v252; // [esp+3B4h] [ebp-860h]
  char v253; // [esp+3B5h] [ebp-85Fh]
  char v254; // [esp+3B6h] [ebp-85Eh]
  char v255; // [esp+3B7h] [ebp-85Dh]
  int v256; // [esp+3B8h] [ebp-85Ch]
  int i; // [esp+3BCh] [ebp-858h]
  unsigned int m_iEventId; // [esp+3C0h] [ebp-854h]
  uint v259; // [esp+3C4h] [ebp-850h]
  signed int m_wParam_high; // [esp+3C8h] [ebp-84Ch]
  bool v261; // [esp+3CFh] [ebp-845h]
  bool v262; // [esp+3D0h] [ebp-844h]
  bool v263; // [esp+3D1h] [ebp-843h]
  char v264; // [esp+3D3h] [ebp-841h]
  struct CEvn_Logic *v265; // [esp+3D4h] [ebp-840h]
  struct CEvn_Logic *v266; // [esp+3D8h] [ebp-83Ch]
  char *v267; // [esp+3DCh] [ebp-838h]
  bool v268; // [esp+3E3h] [ebp-831h]
  struct tagPOINT v269; // [esp+3E4h] [ebp-830h] BYREF
  size_t v270; // [esp+3ECh] [ebp-828h]
  CEvn_Logic v273; // [esp+3F8h] [ebp-81Ch] BYREF
  CEvn_Logic v274; // [esp+418h] [ebp-7FCh] BYREF
  struct tagRECT Rect; // [esp+438h] [ebp-7DCh] BYREF
  CEvn_Logic v276; // [esp+448h] [ebp-7CCh] BYREF
  std::string v277; // [esp+468h] [ebp-7ACh] BYREF
  std::wstring v278; // [esp+484h] [ebp-790h] BYREF
  std::wstring v279; // [esp+4A0h] [ebp-774h] BYREF
  std::wstring v280; // [esp+4BCh] [ebp-758h] BYREF
  std::wstring v281; // [esp+4D8h] [ebp-73Ch] BYREF
  std::wstring v282; // [esp+4F4h] [ebp-720h] BYREF
  std::string v283; // [esp+510h] [ebp-704h] BYREF
  std::wstring v284; // [esp+52Ch] [ebp-6E8h] BYREF
  std::wstring v285; // [esp+548h] [ebp-6CCh] BYREF
  _BYTE v286[28]; // [esp+564h] [ebp-6B0h] BYREF
  CEvn_Event v287; // [esp+580h] [ebp-694h] BYREF
  CEvn_Event v288; // [esp+598h] [ebp-67Ch] BYREF
  CEvn_Event v289; // [esp+5B0h] [ebp-664h] BYREF
  CEvn_Event v290; // [esp+5C8h] [ebp-64Ch] BYREF
  CEvn_Event v291; // [esp+5E0h] [ebp-634h] BYREF
  CEvn_Event v292; // [esp+5F8h] [ebp-61Ch] BYREF
  CEvn_Event v293; // [esp+610h] [ebp-604h] BYREF
  CEvn_Event v294; // [esp+628h] [ebp-5ECh] BYREF
  CEvn_Event v295; // [esp+640h] [ebp-5D4h] BYREF
  CEvn_Event v296; // [esp+658h] [ebp-5BCh] BYREF
  CEvn_Event v297; // [esp+670h] [ebp-5A4h] BYREF
  CEvn_Event v298; // [esp+688h] [ebp-58Ch] BYREF
  CEvn_Event v299; // [esp+6A0h] [ebp-574h] BYREF
  CEvn_Event v300; // [esp+6B8h] [ebp-55Ch] BYREF
  CEvn_Event v301; // [esp+6D0h] [ebp-544h] BYREF
  CEvn_Event v302; // [esp+6E8h] [ebp-52Ch] BYREF
  CEvn_Event v303; // [esp+700h] [ebp-514h] BYREF
  CEvn_Event v304; // [esp+718h] [ebp-4FCh] BYREF
  _BYTE v305[28]; // [esp+730h] [ebp-4E4h] BYREF
  std::wstring a2; // [esp+74Ch] [ebp-4C8h] BYREF
  CEvn_Logic v307; // [esp+768h] [ebp-4ACh] BYREF
  CEvn_Event v308; // [esp+788h] [ebp-48Ch] BYREF
  std::wstring v309; // [esp+7A0h] [ebp-474h] BYREF
  char Destination[512]; // [esp+7BCh] [ebp-458h] BYREF
  char Str[2]; // [esp+9BCh] [ebp-258h] BYREF
  char v312; // [esp+9BEh] [ebp-256h]
  char v313; // [esp+9BFh] [ebp-255h]
  char v314[508]; // [esp+9C0h] [ebp-254h] BYREF
  char v315[36]; // [esp+BBCh] [ebp-58h] BYREF
  char Dest[36]; // [esp+BE0h] [ebp-34h] BYREF
  int v317; // [esp+C10h] [ebp-4h]

  if ( _sEvent->m_iEventId <= 0x190u || _sEvent->m_iEventId >= 0x1E9u )
  {
    if ( _sEvent->m_iEventId <= 0x1388u || _sEvent->m_iEventId >= 0x13BDu )
    {
      m_iEventId = _sEvent->m_iEventId;
      if ( m_iEventId > 0xFA2 )
      {
        m_iEventId -= 4003;
        switch ( m_iEventId )
        {
          case 0u:
            if ( CPlayerManager::IsAlive(_sEvent->m_iOwner)
              && (LocalPlayerId = CPlayerManager::GetLocalPlayerId(), CPlayerManager::IsAlive(LocalPlayerId)) )
            {
              m_lParam = _sEvent->m_lParam;
              v62.m_uU1C = *(_DWORD *)std::_Iterator_base12::operator=((int)&m_lParam);
              p_m_uU10 = &v62.m_uU10;
              v116 = std::end<std::vector<CStateGame::Random_HistoryEntry>>(
                       (int)&v62.m_uU10,
                       (int)&this->m_vRandomHistory);
              v87 = v116;
              v317 = 5;
              v86 = &v62;
              v85 = std::begin<std::vector<CStateGame::Random_HistoryEntry>>((int)&v62, (int)&this->m_vRandomHistory);
              v317 = -1;
              v84 = std::find_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>,_lambda_03817ffcf3c1f43769e18417d11e255d_>(
                      (int)v101,
                      v62.m_uU4,
                      v62.m_uU8,
                      v62.m_uUC,
                      v62.m_uU10,
                      v62.m_uU14,
                      v62.m_uU18,
                      v62.m_uU1C);
              v317 = 6;
              v117 = (std::_Iterator_base12 *)std::vector<CStateGame::Random_HistoryEntry>::end((int)v69);
              v118 = v117;
              LOBYTE(v317) = 7;
              v255 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::operator==(v117);
              LOBYTE(v317) = 6;
              std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v69);
              if ( v255 )
                CTextMsgHandler::AddTextMsg("DESYNC: Rand History search failed!", 0, 0, 0, 1);
              v24 = (int *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::operator*(v101);
              v25 = v24[1];
              v96 = *v24;
              v97 = v25;
              if ( _sEvent->m_wParam != v25 )
              {
                dword_402F3C8 = timeGetTime();
                CTextMsgHandler::AddTextMsg("DESYNC: Game not synchronized anymore(Rand)!", 0, 0, 0, 1);
                BBSupportTracePrintF(3, "DESYNC: Game not synchronized anymore (random check failed)!");
                v254 = 1;
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
              if ( (unsigned int)std::vector<CStateGame::Random_HistoryEntry>::size(&this->m_vRandomHistory) > 0x14 )
              {
                v119 = (struct std::_Iterator_base12 *)std::begin<std::vector<CStateGame::Random_HistoryEntry>>(
                                                         (int)v67,
                                                         (int)&this->m_vRandomHistory);
                v120 = v119;
                LOBYTE(v317) = 8;
                p_m_uU14 = &v62.m_uU14;
                v82 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v119);
                v77 = std::vector<CStateGame::Random_HistoryEntry>::erase((int)v68, v62.m_uU14, v62.m_uU18, v62.m_uU1C);
                std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v68);
                LOBYTE(v317) = 6;
                std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v67);
              }
              v248 = 1;
              v317 = -1;
              std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::Random_HistoryEntry>>>(v101);
              result = v248;
            }
            else
            {
              result = 1;
            }
            break;
          case 2u:
            v243 = _sEvent;
            v270 = 0;
            v164 = CAlliances::AllianceId(_sEvent->m_iOwner);
            Str[0] = 91;
            Str[1] = v164 + 48;
            v312 = 93;
            v313 = 32;
            v270 = 4;
            v62.m_uU1C = 160;
            v163 = CPlayerManager::Name(&v284, _sEvent->m_iOwner);
            v49 = std::wstring::c_str(v163);
            v270 = j__wcstombs(v314, v49, 0xA0u) + 4;
            std::wstring::~wstring(&v284);
            if ( v270 == -1 )
            {
              memset(&v62.m_uU14, 0, 12);
              v50 = CPlayerManager::Color(v243->m_iOwner);
              CTextMsgHandler::AddTextMsg((char *)v243->m_iData, v50, 0, 0, 0);
            }
            Str[v270++] = 58;
            Str[v270++] = 32;
            v194 = 512 - strlen(Str);
            Source = (char *)v243->m_iData;
            if ( strlen(Source) > v194 )
              Source[v194] = 0;
            j__strcpy_0(&Str[v270], Source);
            v51 = CPlayerManager::Color(v243->m_iOwner);
            CTextMsgHandler::AddChatMsg(Str, v51);
            result = 1;
            break;
          case 3u:
            v226 = _sEvent;
            if ( CPlayerManager::IsAlive(_sEvent->m_iOwner)
              && (v26 = CPlayerManager::GetLocalPlayerId(), CPlayerManager::IsAlive(v26)) )
            {
              if ( CGameData::IsNetworkGame(&this->m_sGameData) )
              {
                v121 = v226->m_lParam;
                v62.m_uU1C = *(_DWORD *)std::_Iterator_base12::operator=((int)&v121);
                v75 = &v62.m_uU10;
                v122 = std::end<std::vector<CStateGame::CRC_HistoryEntry>>((int)&v62.m_uU10, (int)&this->m_vCRCHistory);
                v74 = v122;
                v317 = 9;
                v73 = &v62;
                v81 = std::begin<std::vector<CStateGame::CRC_HistoryEntry>>((int)&v62, (int)&this->m_vCRCHistory);
                v317 = -1;
                v80 = std::find_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>,_lambda_9d6ec2be6c5ed87acf2c2ca5fd2e9b85_>(
                        (int)v92,
                        v62.m_uU4,
                        v62.m_uU8,
                        v62.m_uUC,
                        v62.m_uU10,
                        v62.m_uU14,
                        v62.m_uU18,
                        v62.m_uU1C);
                v317 = 10;
                v123 = (std::_Iterator_base12 *)std::vector<CStateGame::CRC_HistoryEntry>::end((int)v66);
                v124 = v123;
                LOBYTE(v317) = 11;
                v253 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::operator==(v123);
                LOBYTE(v317) = 10;
                std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v66);
                if ( v253 )
                  CTextMsgHandler::AddTextMsg("DESYNC: CRC History search failed!", 0, 0, 0, 1);
                v27 = (int *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::operator*(v92);
                v28 = v27[1];
                v98 = *v27;
                v99 = v28;
                if ( v226->m_wParam != v28 )
                {
                  dword_402F3CC = timeGetTime();
                  CTextMsgHandler::AddTextMsg("DESYNC: Game not synchronized anymore(CRC)!", 0, 0, 0, 1);
                  BBSupportTracePrintF(3, "DESYNC: Game not synchronized anymore (update check failed)!");
                  v252 = 1;
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
                if ( (unsigned int)std::vector<CStateGame::CRC_HistoryEntry>::size(&this->m_vCRCHistory) > 0x14 )
                {
                  v140 = (struct std::_Iterator_base12 *)std::begin<std::vector<CStateGame::CRC_HistoryEntry>>(
                                                           (int)v70,
                                                           (int)&this->m_vCRCHistory);
                  v125 = v140;
                  LOBYTE(v317) = 12;
                  v79 = &v62.m_uU14;
                  v72 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v140);
                  v76 = std::vector<CStateGame::CRC_HistoryEntry>::erase((int)v71, v62.m_uU14, v62.m_uU18, v62.m_uU1C);
                  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v71);
                  LOBYTE(v317) = 10;
                  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v70);
                }
                v317 = -1;
                std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CStateGame::CRC_HistoryEntry>>>(v92);
              }
              result = 1;
            }
            else
            {
              result = 1;
            }
            break;
          case 4u:
            this->dword4 += _sEvent->m_wParam;
            CTrace::Print("StateGame: Time adjusted from network! %d", _sEvent->m_wParam);
            result = 1;
            break;
          case 5u:
            if ( CGameType::IsHost(g_pGameType) )
            {
              v201 = _sEvent;
              S2 = (wchar_t *)_sEvent->m_iData;
              std::wstring::wstring(S2, _sEvent->m_iDataSize >> 1);
              v317 = 14;
              std::wstring::operator=(&stru_403037C, &a2);
              v317 = -1;
              std::wstring::~wstring(&a2);
LABEL_269:
              CursorShape = IGfxEngine::GetCursorShape(g_pGfxEngine);
              IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 4u);
              std::wstring::wstring(&v309);
              v317 = 15;
              m_wParam = _sEvent->m_wParam;
              if ( m_wParam )
              {
                if ( CGameData::IsNetworkGame(&this->m_sGameData) )
                {
                  v176 = (std::wstring *)sub_14B19A0((int)&v285, m_wParam);
                  ((void (__stdcall *)(std::wstring *))std::wstring::operator=)(v176);
                  std::wstring::~wstring(&v285);
                }
                else if ( m_wParam == 1 )
                {
                  std::wstring::operator=(&v309, (wchar_t *)L"QuickSave.sav");
                }
                else if ( m_wParam == 2 )
                {
                  std::wstring::operator=(&v309, (wchar_t *)L"AutoSave.sav");
                }
              }
              else
              {
                v177 = std::operator+<wchar_t>((int)&v282, (int)&stru_403037C, (wchar_t *)L".sav");
                ((void (__stdcall *)(int))std::wstring::operator=)(v177);
                std::wstring::~wstring(&v282);
              }
              if ( m_wParam != 2 )
              {
                IGuiEngine::SelectControl(g_pGUIEngine, 0, 611, 1);
                IGuiEngine::SelectControl(g_pGUIEngine, 8, 928, 1);
              }
              v38 = std::wstring::c_str(&v309);
              CTrace::Print("StateGameII: Saving %s", (const char *)v38);
              if ( CGameRun::SaveGame((_Cnd_internal_imp_t *)&v309) )
              {
                this->m_uValidTick = CGameData::GetTickCounter(g_pGameData);
                v264 = 1;
                if ( m_wParam == 2 )
                  v264 = CTextMsgHandler::AddTextMsg(445, 0, 1, 1);
                if ( v264 )
                  CTextMsgHandler::AddTextMsg(1957, 0, 1);
              }
              else
              {
                CTextMsgHandler::AddTextMsg(2532, 0, 1);
              }
              CStateLoadGame::BuildSaveList(g_pGameType->m_iGameType, g_pGameType->m_iCampaignType);
              v175 = CEvn_Event::CEvn_Event(&v295, 0x26Bu, 0, (unsigned int)&g_cSaveGameContext, 0);
              LOBYTE(v317) = 16;
              IEventEngine::SendAMessage(g_pEvnEngine, v175);
              LOBYTE(v317) = 15;
              CEvn_Event::~CEvn_Event(&v295);
              IGfxEngine::SetCursorShape(g_pGfxEngine, 1, CursorShape);
              this->dword4 = timeGetTime() + 71;
              v317 = -1;
              std::wstring::~wstring(&v309);
              result = 1;
            }
            else
            {
              result = 1;
            }
            break;
          case 6u:
            v228 = _sEvent->m_wParam;
            v215 = _sEvent->m_lParam;
            if ( g_pGameType->m_sPlayerValidTicks[v228] == -1 )
            {
              g_pGameType->m_sPlayerValidTicks[v228] = v215;
            }
            else if ( g_pGameType->m_sPlayerValidTicks[v228] != v215 )
            {
              for ( i = 0; i < 8; ++i )
              {
                if ( g_pGameType->m_sPlayerType[i] == 1 )
                {
                  Instance = StormManager::GetInstance();
                  if ( g_pGameType->m_sPlayerPeerId[i] != StormManager::GetLocalPeerId(Instance) )
                  {
                    v112 = (std::string *)INetworkEngine::ConvertIPAddress(
                                            (_DWORD ***)g_pNetworkEngine,
                                            v286,
                                            g_pGameType->m_uiIPPlayer[i]);
                    v113 = v112;
                    v317 = 4;
                    v21 = std::string::c_str(v112);
                    CTrace::Print("Connectionloss: Removing Player index%i, with ip %s", i, v21);
                    v317 = -1;
                    std::string::~string(v286);
                    v247 = INetworkEngine::KickPlayerPeerId(
                             (CGameHost **)g_pNetworkEngine,
                             g_pGameType->m_sPlayerPeerId[i]);
                    if ( !v247
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
      else if ( m_iEventId == 4002 )
      {
        v114 = _sEvent;
        v22 = CPlayerManager::PeerId(_sEvent->m_iOwner);
        INetworkEngine::RemovePlayerPeerId((CGameHost **)g_pNetworkEngine, v22);
        return 1;
      }
      else
      {
        m_iEventId -= 3;
        switch ( m_iEventId )
        {
          case 0u:
            CStateGame::VerifyWorldOffset(this);
            CStateGame::UpdateClientSize(this);
            return 0;
          case 2u:
            v269.x = (unsigned __int16)_sEvent->m_lParam;
            v269.y = HIWORD(_sEvent->m_lParam);
            v269.x = LOWORD(v269.x);
            if ( SLOWORD(v269.y) < 0 )
              v269.y = 0;
            if ( SLOWORD(v269.x) < 0 )
              v269.x = 0;
            this->m_sGameData.m_iScreenMouseX = v269.x;
            this->m_sGameData.m_iScreenMouseY = v269.y;
            if ( this->byteF8 )
            {
              CStateGame::IsInMinimap(this, &v269, &v65);
              return 1;
            }
            if ( this->byteF7 )
            {
              Point.x = 0;
              Point.y = v269.y;
              ClientToScreen(g_hWnd, &Point);
              v244 = Point.y - *(_DWORD *)&this->gapD4[20];
              if ( v244 > 0 )
                CStateGame::ZoomOut(this, v244 / 4);
              if ( v244 < 0 )
                CStateGame::ZoomIn(this, -v244 / 4);
              if ( (unsigned __int8)_ThemeHelper::GetProc(v63, v64) && v244 )
                SetCursorPos(*(_DWORD *)&this->gapD4[16], *(_DWORD *)&this->gapD4[20]);
              return 1;
            }
            else if ( this->byteF4 )
            {
              Number = v269.x - *(_DWORD *)this->gapD4;
              v131 = v269.y - *(_DWORD *)&this->gapD4[4];
              if ( (unsigned int)j__abs(Number) <= 4 && (unsigned int)j__abs(v131) <= 4 )
                return 1;
              if ( v269.x >= this->m_uClientSizeRelated210 )
                x = v269.x;
              else
                x = this->m_uClientSizeRelated210;
              v269.x = x;
              dword_402F3B4 = *(_DWORD *)this->gapD4;
              dword_402F3B8 = *(_DWORD *)&this->gapD4[4];
              dword_402F3BC = x;
              dword_402F3C0 = v269.y;
              if ( IGfxEngine::GetCursorShape(g_pGfxEngine) != 3
                && IGfxEngine::GetCursorShape(g_pGfxEngine) != 6
                && IGfxEngine::GetCursorShape(g_pGfxEngine) != 7
                && IGfxEngine::GetCursorShape(g_pGfxEngine) != 4 )
              {
                v30 = IGfxEngine::ConvertRgbToHicol(255, 255, 255);
                IGfxEngine::DrawRectangle(g_pGfxEngine, (struct tagRECT *)&dword_402F3B4, v30);
              }
              v208 = 0;
              v207 = 0;
              v133 = 479;
              IGfxEngine::GetClosestMapPoint(
                g_pGfxEngine,
                *(_DWORD *)this->gapD4,
                *(_DWORD *)&this->gapD4[4],
                &v224,
                &v223);
              v208 = ((unsigned __int16)v223 << 16) | (unsigned __int16)v224;
              ClosestMapPoint = IGfxEngine::GetClosestMapPoint(g_pGfxEngine, v269.x, v269.y, &v224, &v223);
              v207 = ((unsigned __int16)v223 << 16) | (unsigned __int16)v224;
              v31 = CPlayerManager::GetLocalPlayerId();
              CStateGame::SendLogicMessage(this, 0x1DFu, v207, v208, v31, 0, 0);
              return 1;
            }
            else if ( this->byteF5 )
            {
              if ( this->byteF6 )
              {
                v206 = v269.x - *(_DWORD *)&this->gapD4[16];
                v205 = v269.y - *(_DWORD *)&this->gapD4[20];
                OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
                OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
                if ( (unsigned __int8)_ThemeHelper::GetProc(v63, v64) )
                {
                  if ( v269.x > OutputWidth || v269.y > OutputHeight )
                  {
                    SetCursorPos(OutputWidth / 2, OutputHeight / 2);
                    return 1;
                  }
                  this->m_sGameData.m_uCamX += v206;
                  this->m_sGameData.m_uCamY += v205;
                }
                else
                {
                  this->m_sGameData.m_uCamX = *(_DWORD *)&this->gapD4[24] - v206;
                  this->m_sGameData.m_uCamY = *(_DWORD *)&this->gapD4[28] - v205;
                }
                CStateGame::VerifyWorldOffset(this);
                if ( !(unsigned __int8)_ThemeHelper::GetProc(v63, v64)
                  || v269.x == *(_DWORD *)&this->gapD4[16] && v269.y == *(_DWORD *)&this->gapD4[20] )
                {
                  return 1;
                }
                v269 = *(struct tagPOINT *)&this->gapD4[16];
                ClientToScreen(g_hWnd, &v269);
                SetCursorPos(v269.x, v269.y);
                return 1;
              }
              else if ( (unsigned __int8)_ThemeHelper::GetProc(v63, v64) )
              {
                v134 = v269.x - *(_DWORD *)&this->gapD4[8];
                v135 = v269.y - *(_DWORD *)&this->gapD4[12];
                if ( (unsigned int)j__abs(v134) <= 4 && (unsigned int)j__abs(v135) <= 4 )
                {
                  return 1;
                }
                else
                {
                  this->byteF6 = 1;
                  IGfxEngine::FixCursor(g_pGfxEngine, 1, 0);
                  GetCursorPos(&v229);
                  ScreenToClient(g_hWnd, &v229);
                  *(_DWORD *)&this->gapD4[8] = v229.x;
                  *(_DWORD *)&this->gapD4[12] = v229.y;
                  v32 = IGfxEngine::GetOutputWidth(g_pGfxEngine);
                  *(_DWORD *)&this->gapD4[16] = v32 / 2;
                  v33 = IGfxEngine::GetOutputHeight(g_pGfxEngine);
                  *(_DWORD *)&this->gapD4[20] = v33 / 2;
                  v229 = *(struct tagPOINT *)&this->gapD4[16];
                  ClientToScreen(g_hWnd, &v229);
                  SetCursorPos(v229.x, v229.y);
                  return 1;
                }
              }
              else
              {
                v136 = abs(v269.x - *(_DWORD *)&this->gapD4[16]);
                v137 = abs(v269.y - *(_DWORD *)&this->gapD4[20]);
                if ( v136 > 4 || v137 > 4 )
                  this->byteF6 = 1;
                return 1;
              }
            }
            else
            {
              this->dword100 = 0;
              this->dword104 = 0;
              if ( v269.x )
              {
                if ( v269.x == this->m_uClientWidth - 1 )
                  this->dword100 = 2;
              }
              else
              {
                this->dword100 = 1;
              }
              if ( v269.y )
              {
                if ( v269.y == this->m_uClientHeight - 1 )
                  this->dword104 = 4;
              }
              else
              {
                this->dword104 = 3;
              }
              return 1;
            }
          case 4u:
            this->byteF4 = 1;
            if ( this->byteF5 )
            {
              if ( this->byteF6 )
              {
                _sEvent->m_lParam = *(_DWORD *)&this->gapD4[8] | (*(_DWORD *)&this->gapD4[12] << 16);
                if ( (unsigned __int8)_ThemeHelper::GetProc(v63, v64) )
                {
                  IGfxEngine::FixCursor(g_pGfxEngine, 0, 0);
                  ClientToScreen(g_hWnd, (LPPOINT)&this->gapD4[8]);
                  SetCursorPos(*(_DWORD *)&this->gapD4[8], *(_DWORD *)&this->gapD4[12]);
                }
                this->byteF6 = 0;
              }
              IGfxEngine::FixCursor(g_pGfxEngine, 1, 1);
              *(_DWORD *)this->gapD4 = (unsigned __int16)_sEvent->m_lParam;
              *(_DWORD *)&this->gapD4[4] = HIWORD(_sEvent->m_lParam);
              *(_DWORD *)&this->gapD4[16] = IGfxEngine::GetOutputWidth(g_pGfxEngine) / 2;
              *(_DWORD *)&this->gapD4[20] = IGfxEngine::GetOutputHeight(g_pGfxEngine) / 2;
              if ( (unsigned __int8)_ThemeHelper::GetProc(v63, v64) )
              {
                ClientToScreen(g_hWnd, (LPPOINT)&this->gapD4[16]);
                SetCursorPos(*(_DWORD *)&this->gapD4[16], *(_DWORD *)&this->gapD4[20]);
              }
              this->byteF7 = 1;
              return 1;
            }
            else
            {
              v180.x = (unsigned __int16)_sEvent->m_lParam;
              v180.y = HIWORD(_sEvent->m_lParam);
              if ( CStateGame::IsInMinimap(this, &v180, &v95) )
              {
                if ( this->byte48 )
                {
                  IGuiEngine::EnableEventInput(g_pGUIEngine, 0);
                  this->byte48 = 0;
                }
                this->byteF8 = 1;
                this->m_sGameData.m_uCamX = ((int)this->m_sGameData.m_uZoom >> 16)
                                          * this->m_sGameData.m_iHeight
                                          * v95.x
                                          / 0xA0u;
                this->m_sGameData.m_uCamY = this->m_sGameData.m_iHeight
                                          * v95.y
                                          * ((int)this->m_sGameData.m_uZoom >> 16)
                                          / 0xA0u;
                this->m_sGameData.m_uCamX -= this->m_sGameData.m_uCamY / 2;
                this->m_sGameData.m_uCamY /= 2;
                CStateGame::VerifyWorldOffset(this);
                this->byteF4 = 0;
              }
              else
              {
                *(_DWORD *)this->gapD4 = v180.x;
                SetCapture(g_hWnd);
                if ( this->byte48 )
                {
                  IGuiEngine::EnableEventInput(g_pGUIEngine, 0);
                  this->byte48 = 0;
                }
                *(_DWORD *)&this->gapD4[4] = v180.y;
                IGfxEngine::DrawRectangle(g_pGfxEngine, 0, 0);
              }
              return 1;
            }
          case 5u:
            this->byteF8 = 0;
            this->byteF5 = 0;
            this->byteF4 = 0;
            if ( this->byteF7 )
            {
              this->byteF7 = 0;
              IGfxEngine::FixCursor(g_pGfxEngine, 0, 0);
              if ( (unsigned __int8)_ThemeHelper::GetProc(v63, v64) )
              {
                ClientToScreen(g_hWnd, (LPPOINT)this->gapD4);
                SetCursorPos(*(_DWORD *)this->gapD4, *(_DWORD *)&this->gapD4[4]);
              }
              goto LABEL_148;
            }
            ReleaseCapture();
            if ( !this->byte48 )
            {
              IGuiEngine::EnableEventInput(g_pGUIEngine, 1);
              this->byte48 = 1;
            }
            this->byteF4 = 0;
            v235 = (unsigned __int16)_sEvent->m_lParam;
            m_lParam_high = HIWORD(_sEvent->m_lParam);
            if ( v235 >= this->m_uClientSizeRelated210 )
              v212 = v235;
            else
              v212 = this->m_uClientSizeRelated210;
            v235 = v212;
            v225 = 0;
            v240 = 0;
            v233 = 477;
            if ( (unsigned int)abs(v212 - *(_DWORD *)this->gapD4) <= 4
              && (unsigned int)abs(m_lParam_high - *(_DWORD *)&this->gapD4[4]) <= 4 )
            {
              v233 = 477;
              v91 = IGfxEngine::GetClosestMapPoint(
                      g_pGfxEngine,
                      *(_DWORD *)this->gapD4,
                      *(_DWORD *)&this->gapD4[4],
                      &v128,
                      &v129);
              v225 = ((unsigned __int16)v129 << 16) | (unsigned __int16)v128;
              v240 = _sEvent->m_wParam;
            }
            else
            {
              IGfxEngine::DrawRectangle(g_pGfxEngine, 0, 0);
              v225 = ((unsigned __int16)*(_DWORD *)&this->gapD4[4] << 16) | (unsigned __int16)*(_DWORD *)this->gapD4;
              if ( v235 < 0 )
                v211 = 0;
              else
                v211 = v235;
              v126 = v211;
              v210 = m_lParam_high;
              v127 = m_lParam_high;
              v240 = ((unsigned __int16)m_lParam_high << 16) | (unsigned __int16)v211;
              if ( (_sEvent->m_wParam & 8) != 0 )
                v240 |= 0x80000000;
              v233 = 478;
            }
            if ( !(dword_402F3B8 + dword_402F3BC + dword_402F3C0 + dword_402F3B4) && v233 == 478 )
              return 1;
            v29 = CPlayerManager::GetLocalPlayerId();
            CStateGame::SendLogicMessage(this, v233, v240, v225, v29, 0, 0);
            dword_402F3B8 = 0;
            dword_402F3BC = 0;
            dword_402F3C0 = 0;
            dword_402F3B4 = 0;
            return 1;
          case 6u:
            v216.x = (unsigned __int16)_sEvent->m_lParam;
            v216.y = HIWORD(_sEvent->m_lParam);
            if ( CStateGame::IsInMinimap(this, &v216, &v94) )
            {
              v239 = this->m_sGameData.m_iHeight * v94.x * ((int)this->m_sGameData.m_uZoom >> 16) / 0xA0u;
              v238 = ((int)this->m_sGameData.m_uZoom >> 16) * this->m_sGameData.m_iHeight * v94.y / 0xA0u;
              v239 /= (int)this->m_sGameData.m_uZoom >> 16;
              v238 /= (int)this->m_sGameData.m_uZoom >> 16;
              if ( v239 <= 0 || v238 <= 0 )
              {
                v239 = 0;
                v238 = 0;
              }
              v203 = 0;
              v138 = 480;
              v204 = ((unsigned __int16)v238 << 16) | (unsigned __int16)v239;
              v203 = _sEvent->m_wParam;
              v34 = CPlayerManager::GetLocalPlayerId();
              CStateGame::SendLogicMessage(this, v138, v203, v204, v34, 0, 0);
              goto CStateGame__OnEvent___def_18AD2EB;
            }
            if ( !(unsigned __int8)_ThemeHelper::GetProc(v63, v64) && !this->byteF5 )
            {
              *(_DWORD *)&this->gapD4[16] = v216.x;
              *(_DWORD *)&this->gapD4[20] = v216.y;
              *(_DWORD *)&this->gapD4[24] = this->m_sGameData.m_uCamX;
              *(_DWORD *)&this->gapD4[28] = this->m_sGameData.m_uCamY;
              IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 1u);
              IGfxEngine::LockCursorShape(g_pGfxEngine, 1);
            }
            this->byteF5 = 1;
            if ( this->byteF4 )
            {
              dword_402F3B8 = 0;
              dword_402F3BC = 0;
              dword_402F3C0 = 0;
              dword_402F3B4 = 0;
              IGfxEngine::FixCursor(g_pGfxEngine, 1, 1);
              *(_DWORD *)this->gapD4 = v216.x;
              *(_DWORD *)&this->gapD4[4] = v216.y;
              v35 = IGfxEngine::GetOutputWidth(g_pGfxEngine);
              *(_DWORD *)&this->gapD4[16] = v35 / 2;
              v36 = IGfxEngine::GetOutputHeight(g_pGfxEngine);
              *(_DWORD *)&this->gapD4[20] = v36 / 2;
              if ( (unsigned __int8)_ThemeHelper::GetProc(v63, v64) )
              {
                ClientToScreen(g_hWnd, (LPPOINT)&this->gapD4[16]);
                SetCursorPos(*(_DWORD *)&this->gapD4[16], *(_DWORD *)&this->gapD4[20]);
              }
              this->byteF7 = 1;
              return 1;
            }
            else
            {
              SetCapture(g_hWnd);
              if ( this->byte48 )
              {
                IGuiEngine::EnableEventInput(g_pGUIEngine, 0);
                this->byte48 = 0;
              }
              *(_DWORD *)&this->gapD4[8] = (unsigned __int16)_sEvent->m_lParam;
              *(_DWORD *)&this->gapD4[12] = HIWORD(_sEvent->m_lParam);
              return 1;
            }
          case 7u:
            if ( !this->byteF5 )
              return 1;
            IGfxEngine::LockCursorShape(g_pGfxEngine, 0);
            this->byteF5 = 0;
            this->byteF4 = 0;
            if ( this->byteF7 )
            {
              this->byteF7 = 0;
              IGfxEngine::FixCursor(g_pGfxEngine, 0, 0);
              if ( (unsigned __int8)_ThemeHelper::GetProc(v63, v64) )
              {
                ClientToScreen(g_hWnd, (LPPOINT)this->gapD4);
                SetCursorPos(*(_DWORD *)this->gapD4, *(_DWORD *)&this->gapD4[4]);
              }
LABEL_148:
              ReleaseCapture();
              return 1;
            }
            else
            {
              ReleaseCapture();
              if ( !this->byte48 )
              {
                IGuiEngine::EnableEventInput(g_pGUIEngine, 1);
                this->byte48 = 1;
              }
              if ( this->byteF6 )
              {
                this->byteF6 = 0;
                IGfxEngine::FixCursor(g_pGfxEngine, 0, 0);
                if ( !(unsigned __int8)_ThemeHelper::GetProc(v63, v64) )
                  return 1;
                ClientToScreen(g_hWnd, (LPPOINT)&this->gapD4[8]);
                SetCursorPos(*(_DWORD *)&this->gapD4[8], *(_DWORD *)&this->gapD4[12]);
                return 1;
              }
              else
              {
                v202 = 0;
                v232 = 0;
                v147 = 480;
                v139 = IGfxEngine::GetClosestMapPoint(
                         g_pGfxEngine,
                         *(_DWORD *)&this->gapD4[8],
                         *(_DWORD *)&this->gapD4[12],
                         &v222,
                         &v221);
                if ( v139 < 0 || v222 <= 0 || v221 <= 0 )
                {
                  v222 = 0;
                  v221 = 0;
                }
                v202 = ((unsigned __int16)v221 << 16) | (unsigned __int16)v222;
                v232 = _sEvent->m_wParam;
                if ( v232 == 24 )
                  v232 = 16;
                v37 = CPlayerManager::GetLocalPlayerId();
                CStateGame::SendLogicMessage(this, v147, v232, v202, v37, 0, 0);
                return 1;
              }
            }
          case 8u:
            v190 = _sEvent->m_lParam;
            if ( !this->byte126 )
              goto LABEL_381;
            if ( (v190 & 8) == 0 )
              goto LABEL_381;
            v256 = _sEvent->m_wParam;
            if ( v256 == 'S' )
              goto LABEL_381;
            v192 = v256 >= 65;
            v191 = v256 <= 90;
            if ( !v191 || !v192 )
              goto LABEL_381;
            if ( (v190 & 4) == 0 )
              v256 += 32;
            if ( v256 == 'q' )
            {
              CStateGame::EnableOrDisableDebugString(this, this->m_bAllowDebugString == 0);
              return 0;
            }
            else if ( v256 == 'z' )
            {
              String::String((char *)&byte_3740A8A, -1);
              v317 = 28;
              CDebugFkt::SetDebugString((const struct String *)v305);
              v317 = -1;
              String::~String((String *)v305);
              IGfxEngine::EnableDebugValueCallback(g_pGfxEngine, 0);
              if ( !this->m_bAllowDebugString )
                CStateGame::EnableOrDisableDebugString(this, 1);
              return 0;
            }
            else
            {
              v189 = (int (__cdecl *)(int, int))CDebugFkt::SelectDebugFunc(v256);
              if ( v189 )
              {
                if ( !this->m_bAllowDebugString )
                  CStateGame::EnableOrDisableDebugString(this, 1);
                IGfxEngine::EnableDebugValueCallback(g_pGfxEngine, v189);
                return 0;
              }
              else
              {
LABEL_381:
                v230 = _sEvent->m_wParam - 8;
                switch ( v230 )
                {
                  case 0:
                    v263 = (_sEvent->m_lParam & 4) != 0;
                    v245 = v263;
                    v188 = v263;
                    v160 = v188;
                    v161 = CPlayerManager::GetLocalPlayerId();
                    CStateGame::SendLogicMessage(this, 0x19Fu, v188, 0, v161, 0, 0);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 1:
                    if ( _sEvent->m_lParam )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    v157 = CEvn_Event::CEvn_Event(&v298, 0x6Bu, 1u, 0, 0);
                    v317 = 32;
                    IEventEngine::SendAMessage(g_pEvnEngine, v157);
                    v317 = -1;
                    CEvn_Event::~CEvn_Event(&v298);
                    result = 1;
                    break;
                  case 11:
                    goto LABEL_363;
                  case 25:
                  case 101:
                    CStateGame::ZoomIn(this, 5);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 26:
                  case 99:
                    CStateGame::ZoomOut(this, 5);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 28:
                    v187 = CPlayerManager::GetLocalPlayerId();
                    v56 = CPlayerManager::PlayerInfo(v187);
                    v62.m_uU18 = CPlayerInfo::StartX(v56);
                    v57 = (pairNode *)CPlayerManager::PlayerInfo(v187);
                    v58 = CPlayerInfo::StartY(v57);
                    v158 = CEvn_Event::CEvn_Event(&v296, 0x13u, v58, v62.m_uU18, 0);
                    v317 = 31;
                    IEventEngine::SendAMessage(g_pEvnEngine, v158);
                    v317 = -1;
                    CEvn_Event::~CEvn_Event(&v296);
                    result = 1;
                    break;
                  case 29:
                    CStateGame::ScrollHorizontal(this, 0);
                    CStateGame::ScrollHorizontal(this, 0);
                    CStateGame::ScrollHorizontal(this, 0);
                    CStateGame::ScrollHorizontal(this, 0);
                    CStateGame::ScrollHorizontal(this, 0);
                    CStateGame::ScrollHorizontal(this, 0);
                    CStateGame::VerifyWorldOffset(this);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 30:
                    CStateGame::ScrollVertical(this, 0);
                    CStateGame::ScrollVertical(this, 0);
                    CStateGame::ScrollVertical(this, 0);
                    CStateGame::ScrollVertical(this, 0);
                    CStateGame::ScrollVertical(this, 0);
                    CStateGame::ScrollVertical(this, 0);
                    CStateGame::VerifyWorldOffset(this);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 31:
                    CStateGame::ScrollHorizontal(this, 1);
                    CStateGame::ScrollHorizontal(this, 1);
                    CStateGame::ScrollHorizontal(this, 1);
                    CStateGame::ScrollHorizontal(this, 1);
                    CStateGame::ScrollHorizontal(this, 1);
                    CStateGame::ScrollHorizontal(this, 1);
                    CStateGame::VerifyWorldOffset(this);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 32:
                    CStateGame::ScrollVertical(this, 1);
                    CStateGame::ScrollVertical(this, 1);
                    CStateGame::ScrollVertical(this, 1);
                    CStateGame::ScrollVertical(this, 1);
                    CStateGame::ScrollVertical(this, 1);
                    CStateGame::ScrollVertical(this, 1);
                    CStateGame::VerifyWorldOffset(this);
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 38:
                    if ( !this->byte126 )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    if ( (_sEvent->m_lParam & 8) != 0 )
                    {
                      v159 = CEvn_Event::CEvn_Event(&v294, 0x17u, 0, 0, 0);
                      v317 = 30;
                      IEventEngine::SendAMessage(g_pEvnEngine, v159);
                      v317 = -1;
                      CEvn_Event::~CEvn_Event(&v294);
                    }
                    result = 1;
                    break;
                  case 40:
                  case 41:
                  case 42:
                  case 43:
                  case 44:
                  case 45:
                  case 46:
                  case 47:
                  case 48:
                  case 49:
                    if ( this->byte124 )
                    {
                      result = 0;
                    }
                    else
                    {
                      v259 = _sEvent->m_wParam;
                      if ( v259 == 48 )
                        v186 = 58;
                      else
                        v186 = v259;
                      v259 = v186 - 48;
                      if ( (_sEvent->m_lParam & 8) != 0 )
                      {
                        v59 = CPlayerManager::GetLocalPlayerId();
                        v154 = CEvn_Logic::CEvn_Logic(&v276, 0x1D6u, v259, 0, v59, 0, 0);
                        v317 = 35;
                        IEventEngine::SendAMessage(g_pEvnEngine, v154);
                        v317 = -1;
                        CEvn_Logic::~CEvn_Logic(&v276);
                        result = 1;
                      }
                      else
                      {
                        v261 = (_sEvent->m_lParam & 0x1C) == 0;
                        v246 = v261;
                        if ( v261
                          && this->dword118 == v259
                          && this->dword11C > INetworkEngine::GetVirtualTick(g_pNetworkEngine) - 6 )
                        {
                          v60 = CPlayerManager::GetLocalPlayerId();
                          v153 = CEvn_Logic::CEvn_Logic(&v273, 0x1D9u, v259, 0, v60, 0, 0);
                          v317 = 36;
                          IEventEngine::SendAMessage(g_pEvnEngine, v153);
                          v317 = -1;
                          CEvn_Logic::~CEvn_Logic(&v273);
                        }
                        else
                        {
                          v152 = (_sEvent->m_lParam & 4) != 0;
                          v61 = CPlayerManager::GetLocalPlayerId();
                          v151 = CEvn_Logic::CEvn_Logic(&v274, 0x1D8u, v259, v152, v61, 0, 0);
                          v317 = 37;
                          IEventEngine::SendAMessage(g_pEvnEngine, v151);
                          v317 = -1;
                          CEvn_Logic::~CEvn_Logic(&v274);
                          this->dword118 = v259;
                          this->dword11C = INetworkEngine::GetVirtualTick(g_pNetworkEngine);
                        }
                        result = 1;
                      }
                    }
                    break;
                  case 74:
                    if ( (_sEvent->m_lParam & 8) == 0 )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    if ( !IEventEngine::IsEventPlaying(g_pEvnEngine) )
                    {
                      if ( IEventEngine::IsEventRecording(g_pEvnEngine) )
                      {
                        v155 = std::string::string(&v277, (char *)&byte_3740A8B);
                        v317 = 34;
                        IEventEngine::RecordEvents(g_pEvnEngine, v155);
                        v317 = -1;
                        std::string::~string(&v277);
                        CTextMsgHandler::AddTextMsg("Event Recording stopped!", 0, 0, 0, 0);
                      }
                      else
                      {
                        v156 = std::string::string(&v283, "Events.rec");
                        v317 = 33;
                        IEventEngine::RecordEvents(g_pEvnEngine, v156);
                        v317 = -1;
                        std::string::~string(&v283);
                        CTextMsgHandler::AddTextMsg("Event Recording started to file \"Events.rec\"!", 0, 0, 0, 0);
                      }
                    }
                    result = 1;
                    break;
                  case 75:
                    if ( !g_pGame || !CStateGame::CanSave(g_pGame) || (_sEvent->m_lParam & 8) == 0 )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    CStateGame::SaveGame(this, 1);
                    result = 1;
                    break;
                  case 88:
                  case 89:
                  case 90:
                  case 91:
                  case 92:
                  case 93:
                  case 94:
                  case 95:
                  case 96:
                  case 97:
                    if ( !this->byte126 )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    if ( (_sEvent->m_lParam & 8) != 0 )
                    {
                      v217 = _sEvent->m_wParam - 96;
                      if ( v217 <= CPlayerManager::LastPlayerId() && v217 >= 1 )
                      {
                        CInputProcessor::DeSelectAllEx(&g_cInputProcessor);
                        CPlayerManager::SetLocalPlayerId(v217);
                      }
                      result = 1;
                    }
                    else
                    {
                      if ( _sEvent->m_wParam == 105 )
                        g_iGameSpeed = 20;
                      else
                        g_iGameSpeed = _sEvent->m_wParam - 96;
                      result = 1;
                    }
                    break;
                  case 102:
                    if ( this->byte126 )
                      g_iGameSpeed = 99;
                    goto CStateGame__OnEvent___def_18B0CD2;
                  case 111:
                    if ( !this->byte126 || (_sEvent->m_lParam & 8) == 0 || !this->byte126 )
                      goto CStateGame__OnEvent___def_18B0CD2;
                    v262 = (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)g_pFogging + 36))(g_pFogging) == 0;
                    (*(void (__thiscall **)(void *, bool))(*(_DWORD *)g_pFogging + 40))(g_pFogging, v262);
                    result = 1;
                    break;
                  case 112:
                    if ( !this->byte47 && (!g_pGameType || !CGameType::IsMultiplayerGame(g_pGameType)) )
                      this->byte45 = 1;
                    result = 1;
                    break;
                  case 114:
                    if ( this->byte126 )
                    {
                      CEvn_Event::CEvn_Event(&v308, 0x11u, 0, 0, 1u);
                      v317 = 29;
                      IEventEngine::SendAMessage(g_pEvnEngine, &v308);
                      v93.x = 0;
                      v93.y = 0;
                      ClientToScreen(g_hWnd, &v93);
                      GetClientRect(g_hWnd, &Rect);
                      v317 = -1;
                      CEvn_Event::~CEvn_Event(&v308);
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
            switch ( _sEvent->m_wParam )
            {
              case ' ':
                CTextMsgHandler::ExecuteLastMsg();
                result = 1;
                break;
              case 'H':
              case 'h':
                v193 = CPlayerManager::GetLocalPlayerId();
                v53 = CPlayerManager::PlayerInfo(v193);
                v62.m_uU18 = CPlayerInfo::StartX(v53);
                v54 = (pairNode *)CPlayerManager::PlayerInfo(v193);
                v55 = CPlayerInfo::StartY(v54);
                v162 = CEvn_Event::CEvn_Event(&v299, 0x13u, v55, v62.m_uU18, 0);
                v317 = 27;
                IEventEngine::SendAMessage(g_pEvnEngine, v162);
                v317 = -1;
                CEvn_Event::~CEvn_Event(&v299);
                result = 1;
                break;
              case 'P':
              case 'p':
LABEL_363:
                CStateGame::SwitchPause(this);
                result = 1;
                break;
              default:
                goto CStateGame__OnEvent___def_18AD2EB;
            }
            return result;
          case 0xBu:
            m_wParam_high = HIWORD(_sEvent->m_wParam);
            if ( (__int16)m_wParam_high <= 0 )
              CStateGame::ZoomOut(this, 5 * (-(__int16)m_wParam_high / 120));
            else
              CStateGame::ZoomIn(this, 5 * (m_wParam_high / 120));
            return 1;
          case 0xFu:
            v214 = _sEvent->m_lParam;
            v78 = (double)(unsigned int)v214;
            v234 = (unsigned int)(3801088.0 * (double)(unsigned int)v214 / 100.0) + 917504;
            v213 = v234;
            v100 = (double)v234 / (double)(int)this->m_sGameData.m_uZoom;
            this->m_sGameData.m_uCamX = (int)((double)(int)this->m_sGameData.m_uCamX * v100);
            this->m_sGameData.m_uCamY = (int)((double)(int)this->m_sGameData.m_uCamY * v100);
            this->m_sGameData.m_uZoom = v234;
            CStateGame::VerifyWorldOffset(this);
            return 1;
          case 0x10u:
            CStateGame::SetViewPos(this, _sEvent->m_lParam, _sEvent->m_wParam);
            return 1;
          case 0x11u:
CStateGame__OnEvent___def_18B0CD2:
            v150 = _sEvent->m_wParam;
            if ( v150 != 9 || _sEvent->m_lParam )
              goto CStateGame__OnEvent___def_18AD2EB;
            v149 = CEvn_Event::CEvn_Event(&v293, 0x6Bu, 0, 0, 0);
            v317 = 38;
            IEventEngine::SendAMessage(g_pEvnEngine, v149);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v293);
            return 1;
          case 0x14u:
            this->byte127 = 1;
            return 1;
          case 0x17u:
            CStateGame::UpdateToGuiInfoStruct(this);
            v173 = CEvn_Event::CEvn_Event(&v297, 0x26Cu, 0, (unsigned int)&this->field_134, 0);
            v317 = 17;
            IEventEngine::SendAMessage(g_pEvnEngine, v173);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v297);
            return 1;
          case 0x18u:
            v169 = CEvn_Event::CEvn_Event(&v288, 0x26Cu, 0, (unsigned int)&this->field_14C, 0);
            v317 = 21;
            IEventEngine::SendAMessage(g_pEvnEngine, v169);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v288);
            return 1;
          case 0x19u:
            v168 = CEvn_Event::CEvn_Event(&v289, 0x26Cu, 0, (unsigned int)&this->field_164, 0);
            v317 = 22;
            IEventEngine::SendAMessage(g_pEvnEngine, v168);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v289);
            return 1;
          case 0x1Au:
            v170 = CEvn_Event::CEvn_Event(&v287, 0x26Cu, 0, (unsigned int)&this->field_178, 0);
            v317 = 20;
            IEventEngine::SendAMessage(g_pEvnEngine, v170);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v287);
            return 1;
          case 0x1Bu:
            v167 = CEvn_Event::CEvn_Event(&v290, 0x26Cu, 0, (unsigned int)&this->m_sChatInfo, 0);
            v317 = 23;
            IEventEngine::SendAMessage(g_pEvnEngine, v167);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v290);
            return 1;
          case 0x1Cu:
            v200 = _sEvent->m_wParam;
            if ( v200 )
            {
              if ( v200 == 1 )
              {
                this->m_uGfxFiltering = _sEvent->m_lParam;
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
              this->m_uGfxTextureQuality = _sEvent->m_lParam;
            }
            CStateGame::UpdateFromGuiInfoStruct(this);
            v172 = CEvn_Event::CEvn_Event(&v303, 0x11u, 0, 0, 0);
            v317 = 18;
            IEventEngine::SendAMessage(g_pEvnEngine, v172);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v303);
            CStateGame::UpdateToGuiInfoStruct(this);
            v171 = CEvn_Event::CEvn_Event(&v304, 0x26Bu, 0, (unsigned int)&this->field_134, 0);
            v317 = 19;
            IEventEngine::SendAMessage(g_pEvnEngine, v171);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v304);
            return 1;
          case 0x1Du:
            CStateGame::UpdateFromGuiInfoStruct(this);
            CStateGame::UpdateMusicSettings(this);
            return 1;
          case 0x1Eu:
            CStateGame::UpdateFromGuiInfoStruct(this);
            return 1;
          case 0x1Fu:
            CStateGame::UpdateFromGuiInfoStruct(this);
            CTextMsgHandler::SetMaxMsgCount(this->m_uMsgHistory);
            CTextMsgHandler::RefreshList(v63);
            return 1;
          case 0x20u:
            CStateGame::UpdateFromGuiInfoStruct(this);
            CStateGame::UpdateToGuiInfoStruct(this);
            v166 = CEvn_Event::CEvn_Event(&v291, 0x26Bu, 0, (unsigned int)&this->m_sChatInfo, 0);
            v317 = 24;
            IEventEngine::SendAMessage(g_pEvnEngine, v166);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v291);
            return 1;
          case 0x21u:
            v220 = 0;
            v39 = CPlayerManager::GetLocalPlayerId();
            v197 = CAlliances::AllianceId(v39);
            for ( j = 1; j <= CPlayerManager::LastPlayerId(); ++j )
            {
              if ( CPlayerManager::GetLocalPlayerId() != j && !CPlayerManager::IsAI(j) )
              {
                v268 = 0;
                v198 = CAlliances::AllianceId(j);
                v199 = _sEvent->m_wParam;
                if ( v199 == 1 )
                  v268 = v198 == v197;
                else
                  v268 = v199 != 2 || v198 != v197;
                if ( v268 )
                  v196 = 1 << (j - 1);
                else
                  v196 = 0;
                v220 |= v196;
              }
            }
            CGameSettings::SetChatMessageFilter(v220);
            CStateGame::UpdateToGuiInfoStruct(this);
            v165 = CEvn_Event::CEvn_Event(&v292, 0x26Bu, 0, (unsigned int)&this->m_sChatInfo, 0);
            v317 = 25;
            IEventEngine::SendAMessage(g_pEvnEngine, v165);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v292);
            return 1;
          case 0x22u:
            v218 = _sEvent;
            _sEvent->m_iOwner = CPlayerManager::GetLocalPlayerId();
            v218->m_iEventId = 4004;
            v52 = CPlayerManager::GetLocalPlayerId();
            v251 = 1 << (v52 - 1);
            INetworkEngine::SendAsyncNetMessage(g_pNetworkEngine, v218, ~(1 << (v52 - 1)));
            return 1;
          case 0x23u:
            v231 = _sEvent->m_wParam;
            if ( v231 && std::string::length(v231) )
              v195 = std::string::c_str((std::string *)v231);
            else
              v195 = 0;
            v267 = v195;
            if ( !v195 || *v267 != 33 )
              goto LABEL_354;
            if ( (*(unsigned __int8 (__thiscall **)(void *, char *))(*(_DWORD *)g_pHJBMgr + 4))(g_pHJBMgr, v267) )
            {
              if ( (unsigned __int8)IHJBMgr::LocalIsHJBAllowed()
                && (v40 = CPlayerManager::GetLocalPlayerId(),
                    RealPlayerName = CGameType::GetRealPlayerName(g_pGameType, v40 - 1),
                    (*(unsigned __int8 (__thiscall **)(void *, std::wstring *))(*(_DWORD *)g_pHJBMgr + 8))(
                      g_pHJBMgr,
                      RealPlayerName))
                && (v42 = CStateGame::GameData(this), !CGameData::IsLadder(v42)) )
              {
                v43 = CPlayerManager::GetLocalPlayerId();
                CStateGame::SendLogicMessage(this, 0x1E8u, 0, 0, v43, 0, 0);
              }
              else
              {
                this->byte126 = 0;
                CTextMsgHandler::AddTextMsg("Cheats deactivated!", 9, 0, 0, 0);
              }
              return 1;
            }
            else
            {
              v44 = CStateGame::GameData(this);
              if ( CGameData::IsNetworkGame(v44) )
              {
LABEL_354:
                v45 = std::string::c_str((std::string *)_sEvent->m_wParam);
                j__strcpy_0(Destination, v45);
                LOWORD(v62.m_uU1C) = strlen(Destination) + 1;
                v46 = CPlayerManager::GetLocalPlayerId();
                CEvn_Logic::CEvn_Logic(&v307, 0xFA5u, 0, 0, v46, (uint)Destination, v62.m_uU1C);
                v317 = 26;
                ChatMessageFilter = CGameSettings::GetChatMessageFilter();
                v48 = CPlayerManager::GetLocalPlayerId();
                INetworkEngine::SendAsyncNetMessage(g_pNetworkEngine, &v307, (1 << (v48 - 1)) | ChatMessageFilter);
                v317 = -1;
                CEvn_Logic::~CEvn_Logic(&v307);
                return 1;
              }
              else
              {
                if ( v267[1] == 'i'
                  && v267[2] == 'n'
                  && v267[3] == 'c'
                  && v267[4] == 'u'
                  && v267[5] == 'b'
                  && v267[6] == 'a'
                  && v267[7] == 't'
                  && v267[8] == 'i'
                  && v267[9] == 'o'
                  && v267[10] == 'n'
                  && v267[11] == '2'
                  && !v267[12] )
                {
                  if ( this->byte126 )
                  {
                    this->byte126 = 0;
                    CTextMsgHandler::AddTextMsg("Cheats deactivated!", 9, 0, 0, 0);
                  }
                  else
                  {
                    this->byte126 = 1;
                    CTextMsgHandler::AddTextMsg("Cheats activated!", 9, 0, 0, 0);
                  }
                }
                else if ( this->byte126 )
                {
                  v90 = &v62;
                  v89 = std::string::string(&v62, v231);
                  CStateGame::PerformCommand(
                    v62.m_uU4,
                    v62.m_uU8,
                    v62.m_uUC,
                    v62.m_uU10,
                    v62.m_uU14,
                    v62.m_uU18,
                    v62.m_uU1C);
                }
                return 1;
              }
            }
          case 0x25u:
            v148 = IGfxEngine::GetCursorShape(g_pGfxEngine);
            IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 4u);
            CStateLoadGame::BuildSaveList(g_pGameType->m_iGameType, g_pGameType->m_iCampaignType);
            IGfxEngine::SetCursorShape(g_pGfxEngine, 1, v148);
            v179 = CEvn_Event::CEvn_Event(&v302, 0x26Cu, 0, (unsigned int)&g_cSaveGameContext, 0);
            v317 = 13;
            IEventEngine::SendAMessage(g_pEvnEngine, v179);
            v317 = -1;
            CEvn_Event::~CEvn_Event(&v302);
            return 1;
          case 0x26u:
            goto LABEL_269;
          case 0x27u:
            return 1;
          case 0x34u:
            if ( CGameData::GetMode(&this->m_sGameData) == 5 )
              return 1;
            if ( !CGameData::IsGameWon(&this->m_sGameData) )
            {
              CGameData::TeamWon(&this->m_sGameData, _sEvent->m_wParam);
              if ( CGameData::IsTutorial(&this->m_sGameData) )
                return 1;
              IGuiEngine::SelectControl(g_pGUIEngine, 0, 611, 1);
              IGuiEngine::SelectControl(g_pGUIEngine, 8, 930, 1);
              v3 = CPlayerManager::GetLocalPlayerId();
              if ( CAlliances::AllianceId(v3) == _sEvent->m_wParam )
              {
                (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pFogging + 40))(g_pFogging, 1);
                v144 = CEvn_Event::CEvn_Event(&v300, 0x261u, 1u, 0, 0);
                v143 = &v144->__vftable;
                v317 = 0;
                IEventEngine::SendAMessage(g_pEvnEngine, v144);
                v317 = -1;
                CEvn_Event::~CEvn_Event(&v300);
                if ( _sEvent->m_lParam )
                {
                  v4 = CPlayerManager::GetLocalPlayerId();
                  v5 = CPlayerManager::Color(v4);
                  CTextMsgHandler::AddTextMsg((unsigned __int16)_sEvent->m_lParam, v5, 1);
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
                if ( CGameData::IsNetworkGame(&this->m_sGameData) )
                  (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pFogging + 40))(g_pFogging, 1);
                v142 = CEvn_Event::CEvn_Event(&v301, 0x261u, 0, 0, 0);
                v102 = &v142->__vftable;
                v317 = 1;
                IEventEngine::SendAMessage(g_pEvnEngine, v142);
                v317 = -1;
                CEvn_Event::~CEvn_Event(&v301);
                if ( _sEvent->m_lParam )
                {
                  v8 = CPlayerManager::GetLocalPlayerId();
                  v9 = CPlayerManager::Color(v8);
                  CTextMsgHandler::AddTextMsg(HIWORD(_sEvent->m_lParam), v9, 1);
                }
                else
                {
                  v10 = CPlayerManager::GetLocalPlayerId();
                  v11 = CPlayerManager::Color(v10);
                  CTextMsgHandler::AddTextMsg(1934, v11, 1);
                }
              }
              v185 = 0;
              for ( k = 0; ; ++k )
              {
                if ( k >= CPlayerManager::LastPlayerId() )
                  goto LABEL_61;
                if ( g_pGameType->m_sPlayerTeam[k] == CGameData::TeamWon(&this->m_sGameData) - 1 )
                  break;
              }
              v185 = g_pGameType->m_sPlayerPeerId[k];
LABEL_61:
              INetworkEngine::EndGame((CGameHost **)g_pNetworkEngine, v185);
              CStatistic::FreezeEcoStatistic((CStatistic *)&g_cStatistic);
              return 1;
            }
            if ( CGameData::TeamWon(&this->m_sGameData) != _sEvent->m_wParam
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
            if ( _sEvent->m_wParam == CPlayerManager::GetLocalPlayerId() )
            {
              v62.m_uU1C = 1;
              v12 = CPlayerManager::Color(_sEvent->m_wParam);
              CTextMsgHandler::AddTextMsg(2254, v12, 1);
            }
            else
            {
              v103 = CPlayerManager::Name(&v279, _sEvent->m_wParam);
              v104 = v103;
              v317 = 2;
              v13 = std::wstring::c_str(v103);
              v62.m_uU1C = wcslen(v13);
              v105 = CPlayerManager::Name(&v281, _sEvent->m_wParam);
              v14 = std::wstring::c_str(v105);
              v106 = j__wcstombs(Dest, v14, v62.m_uU1C);
              std::wstring::~wstring(&v281);
              v317 = -1;
              std::wstring::~wstring(&v279);
              v184 = v106;
              if ( v106 >= 0x21 )
                report_rangecheckfailure();
              Dest[v184] = 0;
              v62.m_uU1C = (int)Dest;
              v62.m_uU18 = 1;
              v62.m_uU14 = 0;
              v15 = CPlayerManager::Color(_sEvent->m_wParam);
              CTextMsgHandler::AddTextMsg(2257, v15, 0, 1, Dest);
            }
            CPlayerManager::PlayerDied(_sEvent->m_wParam);
            if ( CPlayerManager::IsAI(_sEvent->m_wParam) )
              g_pAI->DeactivatePlayerAI(g_pAI, _sEvent->m_wParam);
            CStatistic::FreezeEcoStatistic((CStatistic *)&g_cStatistic);
            for ( m = 1; m < 83; ++m )
            {
              if ( m != 46 && m != 47 && m != 48 )
              {
                FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, _sEvent->m_wParam, m);
                for ( n = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, FirstBuildingId);
                      n;
                      n = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v16) )
                {
                  if ( IEntity::FlagBits(n, EntityFlag_NotStriking) )
                    CBuilding::Switch();
                  v16 = IAnimatedEntity::Next(n);
                }
              }
            }
            return 1;
          case 0x36u:
            v108 = CPlayerManager::Name(&v278, _sEvent->m_wParam);
            v109 = v108;
            v317 = 3;
            v17 = std::wstring::c_str(v108);
            v62.m_uU1C = wcslen(v17);
            v110 = CPlayerManager::Name(&v280, _sEvent->m_wParam);
            v18 = std::wstring::c_str(v110);
            v111 = j__wcstombs(v315, v18, v62.m_uU1C);
            std::wstring::~wstring(&v280);
            v317 = -1;
            std::wstring::~wstring(&v278);
            v183 = v111;
            if ( v111 >= 0x21 )
              report_rangecheckfailure();
            v315[v183] = 0;
            CPlayerManager::SetPlayerControl(_sEvent->m_wParam, 2);
            v62.m_uU1C = (int)v315;
            v62.m_uU18 = 1;
            v62.m_uU14 = 0;
            v19 = CPlayerManager::Color(_sEvent->m_wParam);
            CTextMsgHandler::AddTextMsg(2258, v19, 0, 1, v315);
            CStateGame::UpdateToGuiInfoStruct(this);
            if ( CPlayerManager::IsAlive(_sEvent->m_wParam) )
              ((void (__thiscall *)(CAIMain *, int))g_pAI->j_?ActivatePlayerAI@CAIMain@@UAEXH@Z)(
                g_pAI,
                _sEvent->m_wParam);
            return 1;
          case 0x67u:
            CMinimapHandler::FilterKeyPressed(_sEvent->m_wParam);
            return 1;
          case 0x6Bu:
            if ( !_sEvent->m_wParam )
              CTextMsgHandler::AddTextMsg(2252, 0, 1, 1);
            return 1;
          default:
            goto CStateGame__OnEvent___def_18AD2EB;
        }
      }
    }
    else
    {
      if ( !j____RTDynamicCast(
              (void **)&_sEvent->__vftable,
              0,
              &CEvn_Event__RTTI_Type_Descriptor_,
              &CEvn_Logic__RTTI_Type_Descriptor_,
              0)
        && BBSupportDbgReportF(
             2,
             "Main\\States\\StateGameII.cpp",
             328,
             "Message != NET_LOGIC_MSG: m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
             _sEvent->m_lParam,
             _sEvent->m_iEventId,
             _sEvent->m_wParam,
             v63) == 1 )
      {
        __debugbreak();
      }
      v266 = _sEvent;
      if ( _sEvent->m_iDataSize
        && !v266->m_iData
        && BBSupportDbgReportF(
             2,
             "Main\\States\\StateGameII.cpp",
             333,
             "m_iData != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
             v266->m_iOwner,
             v266->m_lParam,
             v266->m_iEventId,
             v266->m_wParam,
             v266->m_iDataSize) == 1 )
      {
        __debugbreak();
      }
      if ( v266->m_iData
        && !v266->m_iDataSize
        && BBSupportDbgReportF(
             2,
             "Main\\States\\StateGameII.cpp",
             337,
             "m_iDataSize != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
             v266->m_iOwner,
             v266->m_lParam,
             v266->m_iEventId,
             v266->m_wParam,
             v266->m_iDataSize) == 1 )
      {
        __debugbreak();
      }
      v145 = _sEvent;
      if ( !((unsigned __int8 (__thiscall *)(CLogicRingBuffer *, struct CEvn_Logic *))this->m_sLogicRingBuffer->Write)(
              this->m_sLogicRingBuffer,
              _sEvent)
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
    if ( !j____RTDynamicCast(
            (void **)&_sEvent->__vftable,
            0,
            &CEvn_Event__RTTI_Type_Descriptor_,
            &CEvn_Logic__RTTI_Type_Descriptor_,
            0)
      && BBSupportDbgReportF(
           2,
           "Main\\States\\StateGameII.cpp",
           303,
           "Message != LOGIC_MSG: m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
           _sEvent->m_lParam,
           _sEvent->m_iEventId,
           _sEvent->m_wParam,
           v63) == 1 )
    {
      __debugbreak();
    }
    v265 = _sEvent;
    if ( _sEvent->m_iDataSize
      && !v265->m_iData
      && BBSupportDbgReportF(
           2,
           "Main\\States\\StateGameII.cpp",
           308,
           "m_iData != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
           v265->m_iOwner,
           v265->m_lParam,
           v265->m_iEventId,
           v265->m_wParam,
           v265->m_iDataSize) == 1 )
    {
      __debugbreak();
    }
    if ( v265->m_iData
      && !v265->m_iDataSize
      && BBSupportDbgReportF(
           2,
           "Main\\States\\StateGameII.cpp",
           312,
           "m_iDataSize != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
           v265->m_iOwner,
           v265->m_lParam,
           v265->m_iEventId,
           v265->m_wParam,
           v265->m_iDataSize) == 1 )
    {
      __debugbreak();
    }
    v146 = _sEvent;
    if ( !((unsigned __int8 (__thiscall *)(CLogicRingBuffer *, struct CEvn_Logic *))this->m_sLogicRingBuffer->Write)(
            this->m_sLogicRingBuffer,
            _sEvent)
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
void  CStateGame::GetCenterWorldCoordinate(int & a2, int & a3) {
  
  int result; // eax

  *a2 = *((_DWORD *)this + 24) / (*((int *)this + 26) >> 16);
  *a3 = *((_DWORD *)this + 25) / (*((int *)this + 26) >> 17);
  result = *a2 + *a3 / 2;
  *a2 = result;
  return result;
}


// address=[0x14b4890]
// Decompiled from CStateGame *__thiscall CStateGame::ScrollHorizontal(CStateGame *this, bool a2)
void  CStateGame::ScrollHorizontal(bool a2) {
  
  CStateGame *result; // eax
  int ScrollStepValue; // [esp+4h] [ebp-4h]

  if ( a2 )
    ScrollStepValue = CGameSettings::GetScrollStepValue();
  else
    ScrollStepValue = -CGameSettings::GetScrollStepValue();
  result = this;
  this->m_sGameData.m_uCamX += ScrollStepValue;
  return result;
}


// address=[0x14b48e0]
// Decompiled from CStateGame *__thiscall CStateGame::ScrollVertical(CStateGame *this, bool a2)
void  CStateGame::ScrollVertical(bool a2) {
  
  CStateGame *result; // eax
  int ScrollStepValue; // [esp+4h] [ebp-4h]

  if ( a2 )
    ScrollStepValue = CGameSettings::GetScrollStepValue();
  else
    ScrollStepValue = -CGameSettings::GetScrollStepValue();
  result = this;
  this->m_sGameData.m_uCamY += ScrollStepValue;
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
  LOBYTE(TickCounter) = CGameData::IsGameWon(&this->m_sGameData);
  if ( (_BYTE)TickCounter )
    return TickCounter;
  LOBYTE(TickCounter) = CStateGame::CanSave(this);
  if ( !(_BYTE)TickCounter )
    return TickCounter;
  v4 = CGameData::GetTickCounter(&this->m_sGameData) - this->m_uValidTick;
  v3 = sub_14A8B60(v4);
  if ( v7 < 60 )
    v7 = 60;
  LOBYTE(TickCounter) = v3;
  if ( v3 <= v7 )
    return TickCounter;
  v5 = CGameData::IsNetworkGame(&this->m_sGameData) && !CGameType::IsHost(g_pGameType);
  LOBYTE(TickCounter) = v5;
  if ( v5 )
    return TickCounter;
  CStateGame::SaveGame(this, 2);
  TickCounter = CGameData::GetTickCounter(&this->m_sGameData);
  this->m_uValidTick = TickCounter;
  return TickCounter;
}


