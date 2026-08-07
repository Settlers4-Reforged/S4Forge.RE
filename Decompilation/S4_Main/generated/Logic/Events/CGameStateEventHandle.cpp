#if FALSE
#include "CGameStateEventHandle.h"

// Definitions for class CGameStateEventHandle

// address=[0x1489f60]
// Decompiled from CGameStateEventHandle *__thiscall CGameStateEventHandle::CGameStateEventHandle(CGameStateEventHandle *this)
 CGameStateEventHandle::CGameStateEventHandle(void) {
  
  IEvn_Handle::IEvn_Handle((IEvn_Handle *)this);
  this->__vftable = (CGameStateEventHandle_vtbl *)&CGameStateEventHandle::_vftable_;
  return this;
}


// address=[0x1489f80]
// Decompiled from void __thiscall CGameStateEventHandle::~CGameStateEventHandle(_AFX_OLE_STATE *this)
 CGameStateEventHandle::~CGameStateEventHandle(void) {
  
  *(_DWORD *)this = &CGameStateEventHandle::_vftable_;
}


// address=[0x1489fa0]
// Decompiled from char __thiscall CGameStateEventHandle::OnEvent(CGameStateEventHandle *this, struct CEvn_Event *a2)
bool  CGameStateEventHandle::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  size_t v3; // eax
  wchar_t *v4; // eax
  std::string v5; // [esp-38h] [ebp-400h] BYREF
  std::string v6; // [esp-1Ch] [ebp-3E4h] BYREF
  int v7; // [esp+0h] [ebp-3C8h] BYREF
  std::string *ManualURL; // [esp+10h] [ebp-3B8h]
  CFile *v9; // [esp+14h] [ebp-3B4h]
  std::wstring *BugReportScreenshotPath; // [esp+18h] [ebp-3B0h]
  std::string *v11; // [esp+1Ch] [ebp-3ACh]
  std::string *v12; // [esp+20h] [ebp-3A8h]
  std::string *v14; // [esp+28h] [ebp-3A0h]
  struct std::string *v15; // [esp+2Ch] [ebp-39Ch]
  void *v16; // [esp+30h] [ebp-398h]
  int v17; // [esp+34h] [ebp-394h]
  std::string *v18; // [esp+38h] [ebp-390h]
  std::string *v19; // [esp+3Ch] [ebp-38Ch]
  struct std::string *v20; // [esp+40h] [ebp-388h]
  void *v21; // [esp+44h] [ebp-384h]
  std::wstring *v22; // [esp+48h] [ebp-380h]
  struct std::string *v23; // [esp+4Ch] [ebp-37Ch]
  int m_wParam; // [esp+50h] [ebp-378h]
  struct std::string *v25; // [esp+54h] [ebp-374h]
  std::string *v26; // [esp+58h] [ebp-370h]
  std::string *v27; // [esp+5Ch] [ebp-36Ch]
  struct std::string *v28; // [esp+60h] [ebp-368h]
  int v29; // [esp+64h] [ebp-364h]
  std::wstring *v30; // [esp+68h] [ebp-360h]
  std::wstring *a1; // [esp+6Ch] [ebp-35Ch]
  std::wstring *BugReportMessageFilePath; // [esp+70h] [ebp-358h]
  struct std::string *v33; // [esp+74h] [ebp-354h]
  int v34; // [esp+78h] [ebp-350h]
  int v35; // [esp+7Ch] [ebp-34Ch]
  struct tagPOINT Point; // [esp+80h] [ebp-348h] BYREF
  INT_PTR v37; // [esp+88h] [ebp-340h]
  int iEventId; // [esp+8Ch] [ebp-33Ch]
  int v39; // [esp+90h] [ebp-338h]
  char v40; // [esp+97h] [ebp-331h]
  bool v41; // [esp+99h] [ebp-32Fh]
  bool v42; // [esp+9Ah] [ebp-32Eh]
  struct CEvn_Event *v43; // [esp+9Ch] [ebp-32Ch]
  CFile v44; // [esp+A0h] [ebp-328h] BYREF
  std::string v45; // [esp+E8h] [ebp-2E0h] BYREF
  std::string v46; // [esp+104h] [ebp-2C4h] BYREF
  std::wstring v47; // [esp+120h] [ebp-2A8h] BYREF
  std::wstring v48; // [esp+13Ch] [ebp-28Ch] BYREF
  _BYTE v49[28]; // [esp+158h] [ebp-270h] BYREF
  std::wstring v50; // [esp+174h] [ebp-254h] BYREF
  std::wstring v51; // [esp+190h] [ebp-238h] BYREF
  WCHAR ExistingFileName[260]; // [esp+1ACh] [ebp-21Ch] BYREF
  int *v53; // [esp+3B8h] [ebp-10h]
  int v54; // [esp+3C4h] [ebp-4h]

  v53 = &v7;
  v43 = a2;
  iEventId = a2->m_iEventId;
  switch ( iEventId )
  {
    case GENERIC_EVENT_LOAD_CONFIG:
      m_wParam = (unsigned __int16)v43->m_wParam;
      if ( m_wParam == 0x9C49 )
      {
        CGameStateHandler::LoadAllConfigFiles();
      }
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case GENERIC_EVENT_UPDATE_WINDOW_POS:
      Point.x = 0;
      Point.y = 0;
      ClientToScreen((HWND)v43[1].__vftable, &Point);
      if ( g_pGfxEngine )
      {
        IGfxEngine::SetWindowPosition(g_pGfxEngine, Point.x, Point.y);
      }
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case GENERIC_EVENT_REBUILD_GFX:
      if ( g_pGfxEngine )
      {
        CGameStateHandler::RebuildGfxEngine(0);
      }
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case GENERIC_EVENT_QUIT_1:
    case GENERIC_EVENT_QUIT_2:
      PostQuitMessage(0);
      return 1;
    case GENERIC_EVENT_KEY_PRESS:
      v39 = v43->m_wParam;
      v39 -= 0x2D;
      switch ( v39 )
      {
        case 0:                                 // PrintScreen
          if ( (v43->m_lParam & 4) == 0 || (v43->m_lParam & 8) == 0 )
          {
            goto CGameStateEventHandle__OnEvent___def_188A00A;
          }
          CGameStateHandler::m_bGrab = CGameStateHandler::m_bGrab == 0;
          result = 0;
          break;
        case 67:                                // F1
          if ( (v43->m_lParam & 8) != 0 )       // CTRL held down
          {
            v37 = DialogBoxParamA(g_hInstance, (LPCSTR)0x79, g_hWnd, DlgProc, 0);
            if ( v37 )
            {
              if ( v37 == 2 )
              {
                IGfxEngine::ShowFrame(g_pGfxEngine);
                v11 = &v6;
                BugReportScreenshotPath = Bugreport::GetBugReportScreenshotPath((std::wstring *)&v6);
                CGrabber::DoGrab((std::wstring)v6);
              }
              v54 = 1;
              v9 = CFile::CFile(&v44);
              LOBYTE(v54) = 2;
              BugReportMessageFilePath = Bugreport::GetBugReportMessageFilePath(&v48);
              a1 = BugReportMessageFilePath;
              LOBYTE(v54) = 3;
              CFile::Open(&v44, BugReportMessageFilePath, CFile_TEXT|CFile_WRITE, UNUSED_ARG(), UNUSED_ARG());
              LOBYTE(v54) = 2;
              std::wstring::~wstring(&v48);
              v6.m_uU1C = 0;
              v6.m_uU18 = (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h";
              v6.m_uU14 = 1;
              v3 = strlen(g_szBugReportText);
              CFile::Write(&v44, g_szBugReportText, v3, 1, UNUSED_ARG(), UNUSED_ARG());
              CFile::Close(&v44, UNUSED_ARG(), UNUSED_ARG());
              LOBYTE(v54) = 1;
              CFile::~CFile(&v44);
              v54 = -1;
              BBSupportGetTraceFilePath(ExistingFileName, 520);
              std::wstring::wstring(&v50, ExistingFileName);
              v54 = 5;
              Bugreport::BuildTraceFilePath(&v51, &v50);
              LOBYTE(v54) = 7;
              std::wstring::~wstring(&v50);
              v6.m_uU1C = 0;
              v4 = std::wstring::c_str(&v51);
              CopyFileW(ExistingFileName, v4, v6.m_uU1C);
              v30 = Bugreport::BuildAutoReporterCmdLineArgsForUserReports(&v47);
              v22 = v30;
              LOBYTE(v54) = 8;
              Bugreport::LaunchAutoreport(1, v30);
              LOBYTE(v54) = 7;
              std::wstring::~wstring(&v47);
              v54 = -1;
              std::wstring::~wstring(&v51);
              result = 1;
            }
            else
            {
              result = 1;
            }
          }
          else
          {
            v21 = &v6;
            v23 = std::string::string(&v6, (char *)&byte_36C34A3);
            v20 = v23;
            v54 = 9;
            v19 = &v5;
            ManualURL = CGameSettings::GetManualURL(&v5);
            v54 = -1;
            CGameStateHandler::ShowHTMLPage(v5, v6);
            result = 1;
          }
          break;
        case 68:                                // F2
          if ( (v43->m_lParam & 4) == 0 )       // Shift held
          {
            ChangeScreenSize(800, 600);
          }
          goto CGameStateEventHandle__OnEvent___def_188A00A;
        case 69:                                // F3
          ChangeScreenSize(1024, 768);
          goto CGameStateEventHandle__OnEvent___def_188A00A;
        case 70:                                // F4
          ChangeScreenSize(1280, 1024);
          goto CGameStateEventHandle__OnEvent___def_188A00A;
        default:
          goto CGameStateEventHandle__OnEvent___def_188A00A;
      }
      return result;
    case GENERIC_EVENT_TOGGLE_FULLSCREEN:
      if ( v43->m_wParam == 13 && (v43->m_lParam & 0x10) != 0 )
      {
        v42 = CGameSettings::GetGfxFullscreenEnabled() == 0;
        CGameSettings::SetGfxFullscreenEnabled(v42);
        CGameStateHandler::RebuildGfxEngine(0);
      }
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case GENERIC_EVENT_SHOW_MANUAL:
      v34 = v43->m_wParam;
      if ( v34 != 63 )
      {
        goto CGameStateEventHandle__OnEvent___def_188A00A;
      }
      v16 = &v6;
      v33 = std::string::string(&v6, (char *)&byte_36C34A2);
      v15 = v33;
      v54 = 0;
      v14 = &v5;
      v12 = CGameSettings::GetManualURL(&v5);
      v54 = -1;
      CGameStateHandler::ShowHTMLPage(v5, v6);
      result = 1;
      break;
    case GENERIC_EVENT_REBUILD_GFX_2:
      CGameStateHandler::RebuildGfxEngine(0);
      return 1;
    case GENERIC_EVENT_KEY_UP:
      v35 = v43->m_wParam;
      if ( v35 != 0x2C )
      {
        goto CGameStateEventHandle__OnEvent___def_188A00A;
      }
      if ( (v43->m_lParam & 4) != 0 )
      {
        CGameStateHandler::m_bGrab = CGameStateHandler::m_bGrab == 0;
        result = 1;
      }
      else
      {
        v18 = &v6;
        v17 = std::wstring::wstring((std::wstring *)&v6, (wchar_t *)&word_36C34A0);
        CGrabber::DoGrab((std::wstring)v6);
        result = 0;
      }
      break;
    case GENERIC_EVENT_FOCUS:
      if ( v43->m_wParam )                      // Gained Focus
      {
        CGameStateHandler::m_bAppActive = 1;
        if ( g_pGfxEngine && g_pGUIEngine )
        {
          IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
        }
      }
      else                                      // Lost it...
      {
        CGameStateHandler::m_bAppActive = 0;
      }
      if ( g_pSoundManager )
      {
        v41 = CGameStateHandler::m_bAppActive == 0;
        CSoundManager::Mute(g_pSoundManager, CGameStateHandler::m_bAppActive == 0);
      }
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case GENERIC_EVENT_START_TICK:
      if ( !g_pGame && BBSupportDbgReportF(2, "Main\\GameStateEventHandle.cpp", 262, "Start tick receive when there's no game !!!!") == 1 )
      {
        __debugbreak();
      }
      if ( !g_pGame )
      {
        return 1;
      }
      CStateGame::ReadyToGo(g_pGame);
      if ( !CGameSettings::GetWebHelpMode() )
      {
        return 1;
      }
      v25 = std::string::string(&v46, "???");
      v28 = v25;
      v54 = 10;
      v26 = std::string::string(&v45, "???");
      v27 = v26;
      LOBYTE(v54) = 11;
      v29 = g_pCfgMgr->GetStringValue(g_pCfgMgr, (std::string *)v49, "COMMANDLINE", "netgame", v26);
      v40 = std::operator!=<char>(v29, v28);
      std::string::~string(v49);
      LOBYTE(v54) = 10;
      std::string::~string(&v45);
      v54 = -1;
      std::string::~string(&v46);
      if ( v40 )
      {
        CGameSettings::SetWebHelpMode(0);
      }
      return 1;
    case GENERIC_EVENT_REQUEST_QUIT:
      CGameStateHandler::m_bQuitApplication = 1;
      return 1;
    default:
CGameStateEventHandle__OnEvent___def_188A00A:
      if ( CGameStateHandler::m_s_pCurrentState )
      {
        result = CGameStateHandler::m_s_pCurrentState->OnEvent(CGameStateHandler::m_s_pCurrentState, a2);
      }
      else
      {
        result = 0;
      }
      break;
  }
  return result;
}


#endif // Already implemented
