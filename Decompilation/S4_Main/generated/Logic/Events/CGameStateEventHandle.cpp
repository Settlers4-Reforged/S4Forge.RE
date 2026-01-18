#include "CGameStateEventHandle.h"

// Definitions for class CGameStateEventHandle

// address=[0x1489f60]
// Decompiled from CGameStateEventHandle *__thiscall CGameStateEventHandle::CGameStateEventHandle(CGameStateEventHandle *this)
 CGameStateEventHandle::CGameStateEventHandle(void) {
  
  IEvn_Handle::IEvn_Handle(this);
  *(_DWORD *)this = &CGameStateEventHandle::_vftable_;
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
  const WCHAR *v4; // eax
  char v5; // [esp-38h] [ebp-400h] BYREF
  int v6; // [esp-34h] [ebp-3FCh]
  int v7; // [esp-30h] [ebp-3F8h]
  int v8; // [esp-2Ch] [ebp-3F4h]
  int v9; // [esp-28h] [ebp-3F0h]
  int v10; // [esp-24h] [ebp-3ECh]
  int v11; // [esp-20h] [ebp-3E8h]
  char v12; // [esp-1Ch] [ebp-3E4h] BYREF
  int v13; // [esp-18h] [ebp-3E0h]
  int v14; // [esp-Ch] [ebp-3D4h]
  const char *v15; // [esp-8h] [ebp-3D0h]
  BOOL v16; // [esp-4h] [ebp-3CCh]
  void *v17[19]; // [esp+0h] [ebp-3C8h] BYREF
  void *v18; // [esp+4Ch] [ebp-37Ch]
  int v19; // [esp+50h] [ebp-378h]
  void *v20; // [esp+54h] [ebp-374h]
  void *v21; // [esp+58h] [ebp-370h]
  void *v22; // [esp+5Ch] [ebp-36Ch]
  void *v23; // [esp+60h] [ebp-368h]
  int v24; // [esp+64h] [ebp-364h]
  void *v25; // [esp+68h] [ebp-360h]
  int v26; // [esp+6Ch] [ebp-35Ch]
  int BugReportMessageFilePath; // [esp+70h] [ebp-358h]
  void *v28; // [esp+74h] [ebp-354h]
  int v29; // [esp+78h] [ebp-350h]
  int v30; // [esp+7Ch] [ebp-34Ch]
  struct tagPOINT Point; // [esp+80h] [ebp-348h] BYREF
  INT_PTR v32; // [esp+88h] [ebp-340h]
  int v33; // [esp+8Ch] [ebp-33Ch]
  int v34; // [esp+90h] [ebp-338h]
  char v35; // [esp+97h] [ebp-331h]
  bool v36; // [esp+99h] [ebp-32Fh]
  bool v37; // [esp+9Ah] [ebp-32Eh]
  struct CEvn_Event *v38; // [esp+9Ch] [ebp-32Ch]
  _BYTE v39[72]; // [esp+A0h] [ebp-328h] BYREF
  _BYTE v40[28]; // [esp+E8h] [ebp-2E0h] BYREF
  _BYTE v41[28]; // [esp+104h] [ebp-2C4h] BYREF
  _BYTE v42[28]; // [esp+120h] [ebp-2A8h] BYREF
  _BYTE v43[28]; // [esp+13Ch] [ebp-28Ch] BYREF
  _BYTE v44[28]; // [esp+158h] [ebp-270h] BYREF
  _BYTE v45[28]; // [esp+174h] [ebp-254h] BYREF
  _BYTE v46[28]; // [esp+190h] [ebp-238h] BYREF
  WCHAR ExistingFileName[260]; // [esp+1ACh] [ebp-21Ch] BYREF
  void **v48; // [esp+3B8h] [ebp-10h]
  int v49; // [esp+3C4h] [ebp-4h]

  v48 = v17;
  v17[9] = this;
  v38 = a2;
  v33 = *((_DWORD *)a2 + 1);
  switch ( v33 )
  {
    case 0:
      v19 = (unsigned __int16)*((_DWORD *)v38 + 2);
      if ( v19 == 40009 )
        CGameStateHandler::LoadAllConfigFiles();
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case 2:
      Point.x = 0;
      Point.y = 0;
      ClientToScreen(*((HWND *)v38 + 6), &Point);
      if ( g_pGfxEngine )
        IGfxEngine::SetWindowPosition((IGfxEngine *)g_pGfxEngine, Point.x, Point.y);
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case 3:
      if ( g_pGfxEngine )
        CGameStateHandler::RebuildGfxEngine(0);
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case 4:
    case 118:
      PostQuitMessage(0);
      return 1;
    case 11:
      v34 = *((_DWORD *)v38 + 2);
      v34 -= 45;
      switch ( v34 )
      {
        case 0:
          if ( (*((_DWORD *)v38 + 3) & 4) == 0 || (*((_DWORD *)v38 + 3) & 8) == 0 )
            goto CGameStateEventHandle__OnEvent___def_188A00A;
          CGameStateHandler::m_bGrab = CGameStateHandler::m_bGrab == 0;
          result = 0;
          break;
        case 67:
          if ( (*((_DWORD *)v38 + 3) & 8) != 0 )
          {
            v32 = DialogBoxParamA(g_hInstance, (LPCSTR)0x79, g_hWnd, DlgProc, 0);
            if ( v32 )
            {
              if ( v32 == 2 )
              {
                IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
                v17[7] = &v12;
                v17[6] = (void *)((void *(__cdecl *)(char *))Bugreport::GetBugReportScreenshotPath)(&v12);
                CGrabber::DoGrab(v12, v13);
              }
              v49 = 1;
              v17[5] = CFile::CFile((CFile *)v39);
              LOBYTE(v49) = 2;
              BugReportMessageFilePath = Bugreport::GetBugReportMessageFilePath(v43, v17[0]);
              v26 = BugReportMessageFilePath;
              LOBYTE(v49) = 3;
              CFile::Open(
                BugReportMessageFilePath,
                9,
                "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h",
                0);
              LOBYTE(v49) = 2;
              std::wstring::~wstring(v43);
              v16 = 0;
              v15 = "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h";
              v14 = 1;
              v3 = j__strlen(g_szBugReportText);
              CFile::Write(
                g_szBugReportText,
                v3,
                1u,
                (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h",
                0);
              CFile::Close((CFile *)v39, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
              LOBYTE(v49) = 1;
              CFile::~CFile();
              v49 = -1;
              BBSupportGetTraceFilePath(ExistingFileName, 0x208u);
              std::wstring::wstring(v45, ExistingFileName);
              v49 = 5;
              Bugreport::BuildTraceFilePath(v46, v45);
              LOBYTE(v49) = 7;
              std::wstring::~wstring(v45);
              v16 = 0;
              v4 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v46);
              CopyFileW(ExistingFileName, v4, v16);
              v25 = (void *)Bugreport::BuildAutoReporterCmdLineArgsForUserReports(v42, v17[0]);
              v17[18] = v25;
              LOBYTE(v49) = 8;
              Bugreport::LaunchAutoreport(1, v25);
              LOBYTE(v49) = 7;
              std::wstring::~wstring(v42);
              v49 = -1;
              std::wstring::~wstring(v46);
              result = 1;
            }
            else
            {
              result = 1;
            }
          }
          else
          {
            v17[17] = &v12;
            v18 = std::string::string(&v12, (char *)&byte_36C34A3);
            v17[16] = v18;
            v49 = 9;
            v17[15] = &v5;
            v17[4] = (void *)CGameSettings::GetManualURL(&v5);
            v49 = -1;
            CGameStateHandler::ShowHTMLPage(v5, v6, v7, v8, v9, v10, v11, v12);
            result = 1;
          }
          break;
        case 68:
          if ( (*((_DWORD *)v38 + 3) & 4) == 0 )
            ChangeScreenSize(800, 600);
          goto CGameStateEventHandle__OnEvent___def_188A00A;
        case 69:
          ChangeScreenSize(1024, 768);
          goto CGameStateEventHandle__OnEvent___def_188A00A;
        case 70:
          ChangeScreenSize(1280, 1024);
          goto CGameStateEventHandle__OnEvent___def_188A00A;
        default:
          goto CGameStateEventHandle__OnEvent___def_188A00A;
      }
      return result;
    case 12:
      if ( *((_DWORD *)v38 + 2) == 13 && (*((_DWORD *)v38 + 3) & 0x10) != 0 )
      {
        v37 = CGameSettings::GetGfxFullscreenEnabled() == 0;
        CGameSettings::SetGfxFullscreenEnabled(v37);
        CGameStateHandler::RebuildGfxEngine(0);
      }
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case 13:
      v29 = *((_DWORD *)v38 + 2);
      if ( v29 != 63 )
        goto CGameStateEventHandle__OnEvent___def_188A00A;
      v17[12] = &v12;
      v28 = std::string::string(&v12, (char *)&byte_36C34A2);
      v17[11] = v28;
      v49 = 0;
      v17[10] = &v5;
      v17[8] = (void *)CGameSettings::GetManualURL(&v5);
      v49 = -1;
      CGameStateHandler::ShowHTMLPage(v5, v6, v7, v8, v9, v10, v11, v12);
      result = 1;
      break;
    case 17:
      CGameStateHandler::RebuildGfxEngine(0);
      return 1;
    case 20:
      v30 = *((_DWORD *)v38 + 2);
      if ( v30 != 44 )
        goto CGameStateEventHandle__OnEvent___def_188A00A;
      if ( (*((_DWORD *)v38 + 3) & 4) != 0 )
      {
        CGameStateHandler::m_bGrab = CGameStateHandler::m_bGrab == 0;
        result = 1;
      }
      else
      {
        v17[14] = &v12;
        v17[13] = (void *)std::wstring::wstring(&v12, (wchar_t *)&word_36C34A0);
        CGrabber::DoGrab(v12, v13);
        result = 0;
      }
      break;
    case 22:
      if ( *((_DWORD *)v38 + 2) )
      {
        CGameStateHandler::m_bAppActive = 1;
        if ( g_pGfxEngine && g_pGUIEngine )
          IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
      }
      else
      {
        CGameStateHandler::m_bAppActive = 0;
      }
      if ( g_pSoundManager )
      {
        v36 = CGameStateHandler::m_bAppActive == 0;
        CSoundManager::Mute((CSoundManager *)g_pSoundManager, CGameStateHandler::m_bAppActive == 0);
      }
      goto CGameStateEventHandle__OnEvent___def_188A00A;
    case 25:
      if ( !g_pGame
        && BBSupportDbgReportF(2, "Main\\GameStateEventHandle.cpp", 262, "Start tick receive when there's no game !!!!") == 1 )
      {
        __debugbreak();
      }
      if ( !g_pGame )
        return 1;
      CStateGame::ReadyToGo((CStateGame *)g_pGame);
      if ( !CGameSettings::GetWebHelpMode() )
        return 1;
      v20 = std::string::string(v41, "???");
      v23 = v20;
      v49 = 10;
      v21 = std::string::string(v40, "???");
      v22 = v21;
      LOBYTE(v49) = 11;
      v24 = ((int (__thiscall *)(CConfigManager *, _BYTE *, const char *, const char *, void *))g_pCfgMgr->GetStringValue)(
              g_pCfgMgr,
              v44,
              "COMMANDLINE",
              "netgame",
              v21);
      v35 = std::operator!=<char>(v24, v23);
      std::string::~string(v44);
      LOBYTE(v49) = 10;
      std::string::~string(v40);
      v49 = -1;
      std::string::~string(v41);
      if ( v35 )
        CGameSettings::SetWebHelpMode(0);
      return 1;
    case 108:
      CGameStateHandler::m_bQuitApplication = 1;
      return 1;
    default:
CGameStateEventHandle__OnEvent___def_188A00A:
      if ( CGameStateHandler::m_s_pCurrentState )
        result = (*(int (__thiscall **)(int, struct CEvn_Event *))(*(_DWORD *)CGameStateHandler::m_s_pCurrentState + 8))(
                   CGameStateHandler::m_s_pCurrentState,
                   a2);
      else
        result = 0;
      break;
  }
  return result;
}


