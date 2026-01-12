#include "CStateLobbyMultiplayerType.h"

// Definitions for class CStateLobbyMultiplayerType

// address=[0x14c0800]
// Decompiled from CStateLobbyMultiplayerType *__cdecl CStateLobbyMultiplayerType::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateLobbyMultiplayerType::DynamicCreateFunc(void *) {
  
  CStateLobbyMultiplayerType *C; // [esp+Ch] [ebp-10h]

  C = (CStateLobbyMultiplayerType *)operator new(4u);
  if ( C )
    return CStateLobbyMultiplayerType::CStateLobbyMultiplayerType(C, a1);
  else
    return 0;
}


// address=[0x14c0a50]
// Decompiled from CStateLobbyMultiplayerType *__thiscall CStateLobbyMultiplayerType::CStateLobbyMultiplayerType(  CStateLobbyMultiplayerType *this,  void *a2)
 CStateLobbyMultiplayerType::CStateLobbyMultiplayerType(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateLobbyMultiplayerType::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::OpenDialog(this, 1, GuiDlgMultiplayerTypeMenuProc);
  return this;
}


// address=[0x14c0ac0]
// Decompiled from void __thiscall CStateLobbyMultiplayerType::~CStateLobbyMultiplayerType(CStateLobbyMultiplayerType *this)
 CStateLobbyMultiplayerType::~CStateLobbyMultiplayerType(void) {
  
  *(_DWORD *)this = &CStateLobbyMultiplayerType::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 1)
    && BBSupportDbgReport(2, "main\\states\\StateLobbyMultiplayerType.cpp", 68, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c0b40]
// Decompiled from char __thiscall CStateLobbyMultiplayerType::Perform(CStateLobbyMultiplayerType *this)
bool  CStateLobbyMultiplayerType::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_4031CF4 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_4031CF4);
    if ( dword_4031CF4 == -1 )
    {
      dword_4031CF0 = timeGetTime();
      j___Init_thread_footer(&dword_4031CF4);
    }
  }
  v1 = dword_4031CF0 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_4031CF0 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14c0be0]
// Decompiled from char __thiscall CStateLobbyMultiplayerType::OnEvent(CStateLobbyMultiplayerType *this, struct CEvn_Event *a2)
bool  CStateLobbyMultiplayerType::OnEvent(class CEvn_Event &) {
  
  char result; // al
  char v3; // [esp-1Ch] [ebp-84h] BYREF
  int v4; // [esp-18h] [ebp-80h]
  int v5; // [esp-14h] [ebp-7Ch]
  int v6; // [esp-10h] [ebp-78h]
  int v7; // [esp-Ch] [ebp-74h]
  int v8; // [esp-8h] [ebp-70h]
  int v9; // [esp-4h] [ebp-6Ch]
  int NormURLenglish; // [esp+4h] [ebp-64h]
  char *v11; // [esp+8h] [ebp-60h]
  int NormURLgerman; // [esp+Ch] [ebp-5Ch]
  char *v13; // [esp+10h] [ebp-58h]
  int HelpURLenglish; // [esp+14h] [ebp-54h]
  char *v15; // [esp+18h] [ebp-50h]
  int HelpURLgerman; // [esp+1Ch] [ebp-4Ch]
  char *v17; // [esp+20h] [ebp-48h]
  CEvn_Event *v18; // [esp+24h] [ebp-44h]
  int v19; // [esp+30h] [ebp-38h]
  CGuiGameState *v20; // [esp+34h] [ebp-34h]
  char v21; // [esp+3Bh] [ebp-2Dh]
  char v22; // [esp+3Ch] [ebp-2Ch]
  char v23; // [esp+3Dh] [ebp-2Bh]
  char v24; // [esp+3Eh] [ebp-2Ah]
  char v25; // [esp+3Fh] [ebp-29h]
  CEvn_Event v26; // [esp+40h] [ebp-28h] BYREF
  int v27; // [esp+64h] [ebp-4h]

  v20 = this;
  v19 = a2->event - 11;
  switch ( v19 )
  {
    case 0:
      if ( (unsigned __int16)a2->wparam != 27 )
        goto CStateLobbyMultiplayerType__OnEvent___def_18C0C31;
      v18 = CEvn_Event::CEvn_Event(&v26, 0x36u, 0, 0, 0);
      v27 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v18);
      v27 = -1;
      CEvn_Event::~CEvn_Event(&v26);
      result = 1;
      break;
    case 41:
      IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
      v25 = 0;
      if ( CGameSettings::GetWebHelpMode() )
      {
        if ( CGameSettings::GetLanguage() == 1 )
        {
          v17 = &v3;
          HelpURLgerman = CGameSettings::GetHelpURLgerman((int)&v3);
          v24 = CStateLobbyMultiplayerType::LaunchWebLobby(v3, v4, v5, v6, v7, v8, v9);
          v25 = v24;
        }
        else
        {
          v15 = &v3;
          HelpURLenglish = CGameSettings::GetHelpURLenglish((int)&v3);
          v23 = CStateLobbyMultiplayerType::LaunchWebLobby(v3, v4, v5, v6, v7, v8, v9);
          v25 = v23;
        }
      }
      else if ( CGameSettings::GetLanguage() == 1 )
      {
        v13 = &v3;
        NormURLgerman = CGameSettings::GetNormURLgerman((int)&v3);
        v22 = CStateLobbyMultiplayerType::LaunchWebLobby(v3, v4, v5, v6, v7, v8, v9);
        v25 = v22;
      }
      else
      {
        v11 = &v3;
        NormURLenglish = CGameSettings::GetNormURLenglish((int)&v3);
        v21 = CStateLobbyMultiplayerType::LaunchWebLobby(v3, v4, v5, v6, v7, v8, v9);
        v25 = v21;
      }
      if ( v25 )
        PostQuitMessage(0);
      IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
      result = 1;
      break;
    case 42:
      IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
      CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 1);
      result = 1;
      break;
    case 43:
      CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
      result = 1;
      break;
    default:
CStateLobbyMultiplayerType__OnEvent___def_18C0C31:
      result = CGuiGameState::OnEvent(v20, a2);
      break;
  }
  return result;
}


// address=[0x14c0880]
// Decompiled from char __thiscall CStateLobbyMultiplayerType::LaunchWebLobby(  void *this,  char a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8)
bool  CStateLobbyMultiplayerType::LaunchWebLobby(std::string) {
  
  char v9; // [esp-38h] [ebp-190h] BYREF
  int v10; // [esp-34h] [ebp-18Ch]
  int v11; // [esp-30h] [ebp-188h]
  int v12; // [esp-2Ch] [ebp-184h]
  int v13; // [esp-28h] [ebp-180h]
  int v14; // [esp-24h] [ebp-17Ch]
  int v15; // [esp-20h] [ebp-178h]
  char v16[32]; // [esp-1Ch] [ebp-174h] BYREF
  int v17; // [esp+4h] [ebp-154h]
  char *v18; // [esp+8h] [ebp-150h]
  void *v19; // [esp+Ch] [ebp-14Ch]
  void *v20; // [esp+10h] [ebp-148h]
  void *v21; // [esp+14h] [ebp-144h]
  char *v22; // [esp+18h] [ebp-140h]
  void *v23; // [esp+1Ch] [ebp-13Ch]
  void *v24; // [esp+20h] [ebp-138h]
  DWORD Type[2]; // [esp+24h] [ebp-134h] BYREF
  void *v26; // [esp+2Ch] [ebp-12Ch]
  void *v27; // [esp+30h] [ebp-128h]
  HKEY phkResult; // [esp+34h] [ebp-124h] BYREF
  DWORD cbData; // [esp+38h] [ebp-120h] BYREF
  LSTATUS v30; // [esp+3Ch] [ebp-11Ch]
  char v31; // [esp+40h] [ebp-118h]
  char v32; // [esp+41h] [ebp-117h]
  char v33; // [esp+42h] [ebp-116h]
  BYTE Data[260]; // [esp+44h] [ebp-114h] BYREF
  int v36; // [esp+154h] [ebp-4h]

  Type[1] = (DWORD)this;
  v36 = 0;
  v30 = RegCreateKeyExA(HKEY_LOCAL_MACHINE, aSoftwareMicros, 0, 0, 0, 0x20019u, 0, &phkResult, 0);
  if ( v30 )
    goto LABEL_5;
  cbData = 260;
  v30 = RegQueryValueExA(phkResult, 0, 0, Type, Data, &cbData);
  if ( v30 )
    goto LABEL_5;
  v24 = v16;
  v27 = std::string::string(v16, aLobbys4Ini);
  v23 = v27;
  LOBYTE(v36) = 1;
  v22 = &v9;
  v21 = std::string::string(&v9, (char *)Data);
  LOBYTE(v36) = 0;
  if ( !CGameStateHandler::ShowHTMLPage(v9, v10, v11, v12, v13, v14, v15, v16[0]) )
  {
LABEL_5:
    v20 = v16;
    v26 = std::string::string(v16, (char *)byte_374C4CD);
    v19 = v26;
    LOBYTE(v36) = 2;
    v18 = &v9;
    v17 = std::string::string(&a2);
    LOBYTE(v36) = 0;
    v32 = CGameStateHandler::ShowHTMLPage(v9, v10, v11, v12, v13, v14, v15, v16[0]);
    v31 = v32;
    v36 = -1;
    std::string::~string(&a2);
    return v31;
  }
  else
  {
    v33 = 1;
    v36 = -1;
    std::string::~string(&a2);
    return v33;
  }
}


