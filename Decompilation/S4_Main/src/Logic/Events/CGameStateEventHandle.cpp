#include "CGameStateEventHandle.h"

#include "CEvn_Event.h"
#include "CEvn_Window.h"
#include "Framework.h"
#include "CBB/Bugreport.h"
#include "CBB/CBBSupport.h"
#include "CConfigManager/IConfigManager.h"
#include "Defines/Events.h"
#include "File/CFile.h"
#include "Main/CGameState.h"
#include "Main/CGameSettings.h"
#include "Main/CGameStateHandler.h"

// Definitions for class CGameStateEventHandle

// address=[0x1489f60]
// Decompiled from CGameStateEventHandle *__thiscall CGameStateEventHandle::CGameStateEventHandle(CGameStateEventHandle *this)
CGameStateEventHandle::CGameStateEventHandle(void) : IEvn_Handle() {}


// address=[0x1489f80]
// Decompiled from void __thiscall CGameStateEventHandle::~CGameStateEventHandle(_AFX_OLE_STATE *this)
CGameStateEventHandle::~CGameStateEventHandle(void) = default;

BOOL __cdecl ChangeScreenSize(int _iX, int _iY) {
  int dwNewLong; // [esp+0h] [ebp-4h]

  dwNewLong = GetWindowLongA(g_hWnd, GWL_STYLE) | WS_OVERLAPPEDWINDOW;
  SetWindowLongA(g_hWnd, -16, dwNewLong);
  return SetWindowPos(g_hWnd, 0, 0, 0, _iX, _iY, WM_MDITILE);
}

// address=[0x1489fa0]
// Decompiled from char __thiscall CGameStateEventHandle::OnEvent(CGameStateEventHandle *this, struct CEvn_Event *a2)
bool CGameStateEventHandle::OnEvent(CEvn_Event &a2) {
  char         result; // al
  std::string  v5; // [esp-38h] [ebp-400h] BYREF
  std::string  v6; // [esp-1Ch] [ebp-3E4h] BYREF
  int          v7; // [esp+0h] [ebp-3C8h] BYREF
  int          v34; // [esp+78h] [ebp-350h]
  int          v35; // [esp+7Ch] [ebp-34Ch]
  INT_PTR      v37; // [esp+88h] [ebp-340h]
  bool         v42; // [esp+9Ah] [ebp-32Eh]
  std::string  v45; // [esp+E8h] [ebp-2E0h] BYREF
  std::string  v46; // [esp+104h] [ebp-2C4h] BYREF
  std::wstring v47; // [esp+120h] [ebp-2A8h] BYREF
  std::wstring v48; // [esp+13Ch] [ebp-28Ch] BYREF
  std::wstring v50; // [esp+174h] [ebp-254h] BYREF
  std::wstring v51; // [esp+190h] [ebp-238h] BYREF
  WCHAR        ExistingFileName[260]; // [esp+1ACh] [ebp-21Ch] BYREF
  switch(a2.m_iEventId) {
    case GENERIC_EVENT_LOAD_CONFIG:
      if(a2.m_wParam == 0x9C49)
        CGameStateHandler::LoadAllConfigFiles();
      break;
    case GENERIC_EVENT_UPDATE_WINDOW_POS: {
      auto *pWndEvent = dynamic_cast<CEvn_Window *>(&a2);
      BB_ASSERT(pWndEvent);

      POINT Point{0, 0};
      ClientToScreen(pWndEvent->m_hWnd, &Point);
      if(g_pGfxEngine)
        g_pGfxEngine->SetWindowPosition(Point.x, Point.y);
      break;
    }
    case GENERIC_EVENT_REBUILD_GFX:
      if(g_pGfxEngine)
        CGameStateHandler::RebuildGfxEngine(false);
      break;
    case GENERIC_EVENT_QUIT_1:
    case GENERIC_EVENT_QUIT_2:
      PostQuitMessage(0);
      return true;
    case GENERIC_EVENT_KEY_PRESS:
      switch(a2.m_wParam - 0x2D) {
        case 0: // PrintScreen
          if((a2.m_lParam & 4) == 0 || (a2.m_lParam & 8) == 0)
            break;
          CGameStateHandler::m_bGrab = CGameStateHandler::m_bGrab == 0;
          return false;
        case 67: // F1
        {
          if((a2.m_lParam & 8) != 0) // CTRL held down
          {
            v37 = DialogBoxParamA(g_hInstance, (LPCSTR) 0x79, g_hWnd, DlgProc, 0);
            if(v37) {
              if(v37 == 2) {
                g_pGfxEngine->ShowFrame();
                CGrabber::DoGrab(Bugreport::GetBugReportScreenshotPath());
              }
              CFile cBugReportFile = CFile();

              cBugReportFile.Open(Bugreport::GetBugReportMessageFilePath(), CFile::CFile_TEXT | CFile::CFile_WRITE, CFileLog);
              cBugReportFile.Write(g_szBugReportText, strlen(g_szBugReportText), 1,CFileLog);
              cBugReportFile.Close(CFileLog);
              BBSupportGetTraceFilePath(ExistingFileName, 520);
              CopyFileW(ExistingFileName, Bugreport::BuildTraceFilePath(ExistingFileName).c_str(), 0);
              Bugreport::LaunchAutoreport(true, Bugreport::BuildAutoReporterCmdLineArgsForUserReports());
              return true;
            }
            return true;
          }
          CGameStateHandler::ShowHTMLPage(CGameSettings::GetManualURL(), "");
        }
        break;
        case 68: // F2
          if((a2.m_lParam & 4) == 0)       // Shift held
            ChangeScreenSize(800, 600);
          break;
        case 69: // F3
          ChangeScreenSize(1024, 768);
          break;
        case 70: // F4
          ChangeScreenSize(1280, 1024);
          break;
        default:
          break;
      }
      return result;
    case GENERIC_EVENT_TOGGLE_FULLSCREEN:
      if(a2.m_wParam == 13 && (a2.m_lParam & 0x10) != 0) {
        v42 = CGameSettings::GetGfxFullscreenEnabled() == 0;
        CGameSettings::SetGfxFullscreenEnabled(v42);
        CGameStateHandler::RebuildGfxEngine(false);
      }
      break;
    case GENERIC_EVENT_SHOW_MANUAL:
      v34 = a2.m_wParam;
      if(v34 != 63)
        break;

      CGameStateHandler::ShowHTMLPage(CGameSettings::GetManualURL(), "");
      return true;
    case GENERIC_EVENT_REBUILD_GFX_2:
      CGameStateHandler::RebuildGfxEngine(false);
      return true;
    case GENERIC_EVENT_KEY_UP:
      v35 = a2.m_wParam;
      if(v35 != 0x2C)
        break;
      if((a2.m_lParam & 4) != 0) {
        CGameStateHandler::m_bGrab = CGameStateHandler::m_bGrab == 0;
        return true;
      }
      CGrabber::DoGrab("");
      return false;
    case GENERIC_EVENT_FOCUS:
      if(a2.m_wParam) { // Gained Focus
        CGameStateHandler::m_bAppActive = true;
        if(g_pGfxEngine && g_pGUIEngine)
          g_pGUIEngine->RefreshAllSurfaces();
      } else { // Lost it...
        CGameStateHandler::m_bAppActive = false;
      }
      if(g_pSoundManager) {
        g_pSoundManager->Mute(CGameStateHandler::m_bAppActive == 0);
      }
      break;
    case GENERIC_EVENT_START_TICK: {
      if(!g_pGame)
        BB_REPORT("Start tick receive when there's no game !!!!");
      if(!g_pGame)
        return true;
      g_pGame->ReadyToGo();
      if(!CGameSettings::GetWebHelpMode())
        return true;

      std::string sNetGameArg = g_pCfgMgr->GetStringValue("COMMANDLINE", "netgame", "???");
      if(sNetGameArg != "???")
        CGameSettings::SetWebHelpMode(0);
      return true;
    }
    case GENERIC_EVENT_REQUEST_QUIT:
      CGameStateHandler::m_bQuitApplication = true;
      return true;
    default:
      break;
  }
  if(CGameStateHandler::m_s_pCurrentState)
    return CGameStateHandler::m_s_pCurrentState->OnEvent(a2);

  return false;
}


