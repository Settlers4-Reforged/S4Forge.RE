#include "CStateLoadGame.h"

// Definitions for class CStateLoadGame

// address=[0x148fe10]
// Decompiled from void *CStateLoadGame::InitSaveList()
void __cdecl CStateLoadGame::InitSaveList(void) {
  
  void *result; // eax

  result = memset(&CStateLoadGame::m_stempSavePtr, 0, 0xFA0u);
  g_cSaveGameContext = 5;
  return result;
}


// address=[0x14b52b0]
// Decompiled from CStateLoadGame *__cdecl CStateLoadGame::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateLoadGame::DynamicCreateFunc(void * a1) {
  
  CStateLoadGame *C; // [esp+Ch] [ebp-10h]

  C = (CStateLoadGame *)operator new(0xCu);
  if ( C )
    return CStateLoadGame::CStateLoadGame(C, a1);
  else
    return 0;
}


// address=[0x14b5680]
// Decompiled from CStateLoadGame *__thiscall CStateLoadGame::CStateLoadGame(CStateLoadGame *this, void *a2)
 CStateLoadGame::CStateLoadGame(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateLoadGame::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
  memset(&CStateLoadGame::m_stempSavePtr, 0, 0xFA0u);
  if ( !(_BYTE)a2 )
  {
    *((_DWORD *)this + 1) = 3;
    *((_DWORD *)this + 2) = 4;
  }
  if ( (char)a2 == 1 )
  {
    *((_DWORD *)this + 1) = 3;
    *((_DWORD *)this + 2) = 1;
  }
  if ( (char)a2 == 2 )
  {
    *((_DWORD *)this + 1) = 1;
    *((_DWORD *)this + 2) = 0;
  }
  if ( (char)a2 == 3 )
  {
    *((_DWORD *)this + 1) = 2;
    *((_DWORD *)this + 2) = 0;
  }
  CStateLoadGame::BuildSaveList(*((_DWORD *)this + 1), *((_DWORD *)this + 2));
  CGuiGameState::OpenDialog(this, 6, GuiDlgMainLoadProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14b57c0]
// Decompiled from void __thiscall CStateLoadGame::~CStateLoadGame(CStateLoadGame *this)
 CStateLoadGame::~CStateLoadGame(void) {
  
  *(_DWORD *)this = &CStateLoadGame::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 6)
    && BBSupportDbgReport(2, "main\\states\\StateLoadGame.cpp", 104, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14b5840]
// Decompiled from char __thiscall CStateLoadGame::Perform(CStateLoadGame *this)
bool  CStateLoadGame::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_40306C8 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_40306C8);
    if ( dword_40306C8 == -1 )
    {
      dword_40306C4 = timeGetTime();
      j___Init_thread_footer(&dword_40306C8);
    }
  }
  v1 = dword_40306C4 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_40306C4 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14b58e0]
// Decompiled from char __thiscall CStateLoadGame::OnEvent(CStateLoadGame *this, struct CEvn_Event *a2)
bool  CStateLoadGame::OnEvent(class CEvn_Event & a2) {
  
  char v3; // [esp-1Ch] [ebp-68h] BYREF
  int v4; // [esp-18h] [ebp-64h]
  int v5; // [esp+4h] [ebp-48h]
  char *v6; // [esp+8h] [ebp-44h]
  CGuiGameState *v7; // [esp+Ch] [ebp-40h]
  CEvn_Event *v8; // [esp+10h] [ebp-3Ch]
  int event; // [esp+1Ch] [ebp-30h]
  CEvn_Event v11; // [esp+24h] [ebp-28h] BYREF
  int v12; // [esp+48h] [ebp-4h]

  v7 = this;
  event = a2->event;
  switch ( event )
  {
    case 13:
      if ( a2->wparam != 27 )
        return 1;
      v8 = CEvn_Event::CEvn_Event(&v11, 0x5Eu, 0, 0, 0);
      v12 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v8);
      v12 = -1;
      CEvn_Event::~CEvn_Event(&v11);
      return 1;
    case 94:
      CGameStateHandler::Switch((int)CStateLoadType::DynamicCreateFunc, 0);
      return 1;
    case 95:
      IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
      v6 = &v3;
      v5 = std::wstring::wstring((int)&unk_403037C);
      if ( (unsigned __int8)CStateMainMenu::PreLoadGame(v3, v4) )
        return 1;
      CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2400);
      CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
      return 1;
    default:
      return CGuiGameState::OnEvent(v7, a2);
  }
}


// address=[0x14b5a30]
// Decompiled from void __cdecl CStateLoadGame::BuildSaveList(int a1, int a2)
void __cdecl CStateLoadGame::BuildSaveList(enum TGAME_TYPE a1, enum CAMPAIGN_TYPE a2) {
  
  int v2; // eax
  const wchar_t *v3; // eax
  wchar_t *v4; // eax
  int v5; // [esp+4h] [ebp-52Ch]
  int v6; // [esp+8h] [ebp-528h]
  intptr_t FindHandle; // [esp+Ch] [ebp-524h]
  _WORD *v8; // [esp+10h] [ebp-520h]
  SSaveEntry *v9; // [esp+14h] [ebp-51Ch]
  void *v10; // [esp+18h] [ebp-518h]
  int N; // [esp+1Ch] [ebp-514h]
  int v12; // [esp+20h] [ebp-510h]
  _wfinddata64i32_t FindData; // [esp+24h] [ebp-50Ch] BYREF
  int v14[7]; // [esp+254h] [ebp-2DCh] BYREF
  int v15[7]; // [esp+270h] [ebp-2C0h] BYREF
  _BYTE v16[28]; // [esp+28Ch] [ebp-2A4h] BYREF
  _BYTE v17[28]; // [esp+2A8h] [ebp-288h] BYREF
  _BYTE v18[28]; // [esp+2C4h] [ebp-26Ch] BYREF
  _BYTE v19[28]; // [esp+2E0h] [ebp-250h] BYREF
  _BYTE v20[28]; // [esp+2FCh] [ebp-234h] BYREF
  wchar_t Destination[260]; // [esp+318h] [ebp-218h] BYREF
  int v22; // [esp+52Ch] [ebp-4h]

  CStateLoadGame::DestroySaveList();
  if ( g_pGameType )
  {
    byte_4030398 = CGameType::IsMultiplayerGame(g_pGameType);
    if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
    {
      std::wstring::wstring(g_pGameType + 28);
      v22 = 0;
      v2 = std::wstring::rfind((wchar_t *)asc_3743A6C, -1);
      v6 = std::wstring::substr((int)v15, v2 + 1, 0xFFFFFFFF);
      std::wstring::operator=(v6);
      std::wstring::~wstring(v15);
      N = std::wstring::rfind((wchar_t *)L".map", -1);
      v5 = std::wstring::substr((int)v14, 0, N);
      std::wstring::operator=(v5);
      std::wstring::~wstring(v14);
      std::wstring::operator=((int)v20);
      v22 = -1;
      std::wstring::~wstring(v20);
    }
  }
  v12 = 0;
  SaveFilePath::GetSaveFileMapPattern(v16);
  v22 = 1;
  v3 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v16);
  FindHandle = j___wfindfirst64i32(v3, &FindData);
  if ( FindHandle != -1 )
  {
    do
    {
      std::wstring::wstring(v18, FindData.name);
      LOBYTE(v22) = 2;
      SaveFilePath::BuildSaveFilePath(v17, (int)v18);
      LOBYTE(v22) = 4;
      std::wstring::~wstring(v18);
      std::string::string();
      LOBYTE(v22) = 5;
      v4 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v17);
      if ( (unsigned __int8)CStateLoadGame::FileMatch(v4, a1, a2, v19) )
      {
        v10 = operator new(0x54u);
        if ( v10 )
        {
          memset(v10, 0, 0x54u);
          v9 = SSaveEntry::SSaveEntry((SSaveEntry *)v10);
        }
        else
        {
          v9 = 0;
        }
        CStateLoadGame::m_stempSavePtr[v12] = (int)v9;
        std::wstring::operator=((void *)CStateLoadGame::m_stempSavePtr[v12], FindData.name);
        j__wcscpy(Destination, FindData.name);
        v8 = (_WORD *)wcsstr(Destination, (wchar_t *)L".sav");
        if ( v8 )
          *v8 = 0;
        std::wstring::operator=((void *)(CStateLoadGame::m_stempSavePtr[v12] + 28), Destination);
        std::string::operator=((int)v19);
        ++v12;
      }
      LOBYTE(v22) = 4;
      std::string::~string(v19);
      LOBYTE(v22) = 1;
      std::wstring::~wstring(v17);
    }
    while ( j___wfindnext64i32(FindHandle, &FindData) != -1 );
  }
  dword_4030378 = v12;
  dword_4030374 = (int)CStateLoadGame::m_stempSavePtr;
  v22 = -1;
  std::wstring::~wstring(v16);
}


// address=[0x14b5dd0]
// Decompiled from void CStateLoadGame::DestroySaveList()
void __cdecl CStateLoadGame::DestroySaveList(void) {
  
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < dword_4030378; ++i )
  {
    if ( CStateLoadGame::m_stempSavePtr[i] )
    {
      delete (__ExceptionPtr *)CStateLoadGame::m_stempSavePtr[i];
      CStateLoadGame::m_stempSavePtr[i] = 0;
    }
  }
}


// address=[0x402f3d0]
// [Decompilation failed for static struct SSaveEntry * * CStateLoadGame::m_stempSavePtr]

// address=[0x14b5330]
// Decompiled from bool __cdecl CStateLoadGame::FileMatch(wchar_t *String, int a2, int a3, void *a4)
bool __cdecl CStateLoadGame::FileMatch(wchar_t const * String, enum TGAME_TYPE a2, enum CAMPAIGN_TYPE a3, std::string & a4) {
  
  bool result; // al
  _DWORD v5[5]; // [esp+0h] [ebp-E60h] BYREF
  int v6; // [esp+14h] [ebp-E4Ch]
  BOOL v7; // [esp+18h] [ebp-E48h]
  BOOL v8; // [esp+1Ch] [ebp-E44h]
  BOOL v9; // [esp+20h] [ebp-E40h]
  int v10; // [esp+24h] [ebp-E3Ch]
  char v11; // [esp+29h] [ebp-E37h]
  bool v12; // [esp+2Ah] [ebp-E36h]
  bool v13; // [esp+2Bh] [ebp-E35h]
  bool v14; // [esp+2Ch] [ebp-E34h]
  char v15; // [esp+2Dh] [ebp-E33h]
  bool v16; // [esp+2Eh] [ebp-E32h]
  _BYTE v18[8]; // [esp+30h] [ebp-E30h] BYREF
  int v19; // [esp+38h] [ebp-E28h]
  int v20; // [esp+40h] [ebp-E20h]
  char Str[1796]; // [esp+294h] [ebp-BCCh] BYREF
  _BYTE v22[1176]; // [esp+998h] [ebp-4C8h] BYREF
  _BYTE v23[28]; // [esp+E30h] [ebp-30h] BYREF
  _DWORD *v24; // [esp+E50h] [ebp-10h]
  int v25; // [esp+E5Ch] [ebp-4h]

  v24 = v5;
  if ( !String && BBSupportDbgReport(2, "main\\states\\StateLoadGame.cpp", 287, "_pName!= NULL") == 1 )
    __debugbreak();
  if ( !String )
    return 0;
  S4::CMapFile::CMapFile((CHandleMap *)v22, 0);
  v25 = 1;
  v5[4] = std::wstring::wstring(v23, String);
  LOBYTE(v25) = 2;
  S4::CMapFile::Open((S4::CMapFile *)v22, (int)v23, 1, 0);
  LOBYTE(v25) = 1;
  std::wstring::~wstring(v23);
  CGameChunkGeneral::CGameChunkGeneral(v18);
  if ( CGameRun::LoadGeneralInfo((struct S4::CMapFile *)v22, (struct CGameChunkGeneral *)v18) )
  {
    S4::CMapFile::Close((S4::CMapFile *)v22);
    std::string::operator=(a4, Str);
    v10 = a2 - 1;
    switch ( a2 )
    {
      case 1:
      case 2:
      case 4:
        v9 = a2 == v20 && !v19;
        v16 = v9;
        v25 = -1;
        S4::CMapFile::~CMapFile((CHandleMap *)v22);
        result = v16;
        break;
      case 3:
        if ( v19 < 5 || v19 >= 11 )
        {
          v7 = v20 == a2;
          v13 = v20 == a2;
          v25 = -1;
          S4::CMapFile::~CMapFile((CHandleMap *)v22);
          result = v13;
        }
        else
        {
          v8 = v20 == a2 && (v15 = (*(int (__thiscall **)(int))(*(_DWORD *)g_pMissionCD + 4))(g_pMissionCD)) != 0;
          v14 = v8;
          v25 = -1;
          S4::CMapFile::~CMapFile((CHandleMap *)v22);
          result = v14;
        }
        break;
      default:
        v6 = BBSupportDbgReportF(2, "main\\states\\StateLoadGame.cpp", 338, "Invalid save game type %u", a2);
        if ( v6 == 1 )
          __debugbreak();
        v12 = 0;
        v25 = -1;
        S4::CMapFile::~CMapFile((CHandleMap *)v22);
        result = v12;
        break;
    }
  }
  else
  {
    S4::CMapFile::Close((S4::CMapFile *)v22);
    v11 = 0;
    v25 = -1;
    S4::CMapFile::~CMapFile((CHandleMap *)v22);
    return v11;
  }
  return result;
}


