#include <windows.h>

#include "defines.h"
#include "Framework.h"
#include "File/FilePaths.h"
#include "CBB/CBBObject.h"
#include "CBB/CBBSupport.h"
#include "Debug/CDebugInfo.h"
#include "Main/UI/CStringEngine.h"
#include "Main/UI/CStringEngineEx.h"
#include "Main/CGameStateHandler.h"
#include "Net/OnlineManager.h"
#include "Logic/Events/IEventEngine.h"
#include "Main/CGameSettings.h"
#include "Debug/CTrace.h"
#include "Info/CInstallationInfo.h"


// address=[0x01357310]
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    _DWORD *v5;                             // eax
    DWORD Time;                             // eax
    wchar_t *v7;                            // eax
    wchar_t *v8;                            // eax
    const char *v9;                         // eax
    wchar_t *spCrashlogFilename;            // eax
    int v11;                                // [esp-8h] [ebp-2DFCh] BYREF
    _DWORD v14[7];                          // [esp+10h] [ebp-2DE4h] BYREF
    int SystemLanguageId;                   // [esp+2Ch] [ebp-2DC8h]
    int v16;                                // [esp+30h] [ebp-2DC4h]
    int v17;                                // [esp+34h] [ebp-2DC0h]
    int *v18;                               // [esp+38h] [ebp-2DBCh]
    int v19;                                // [esp+3Ch] [ebp-2DB8h]
    unsigned long Type;                     // [esp+40h] [ebp-2DB4h] BYREF
    int v21;                                // [esp+44h] [ebp-2DB0h]
    int v22;                                // [esp+48h] [ebp-2DACh]
    int v23;                                // [esp+4Ch] [ebp-2DA8h]
    CStringEngineEx *StringEngine;          // [esp+54h] [ebp-2DA0h] MAPDST
    int SystemLanguage;                     // [esp+5Ch] [ebp-2D98h] MAPDST
    int v28;                                // [esp+60h] [ebp-2D94h]
    int v29;                                // [esp+64h] [ebp-2D90h]
    int v30;                                // [esp+68h] [ebp-2D8Ch]
    unsigned long nSize;                    // [esp+6Ch] [ebp-2D88h] BYREF
    int DbgHelpDll;                         // [esp+70h] [ebp-2D84h]
    std::wstring UserDirectoryPath;         // [esp+78h] [ebp-2D7Ch] MAPDST
    std::wstring UserConfigDirectory;       // [esp+80h] [ebp-2D74h] MAPDST
    int v37;                                // [esp+84h] [ebp-2D70h]
    HKEY hS4RegKey;                         // [esp+90h] [ebp-2D64h] BYREF
    unsigned long uRegPathSize;             // [esp+94h] [ebp-2D60h] BYREF
    int(__thiscall * v42)(OnlineManager *); // [esp+98h] [ebp-2D5Ch] BYREF
    int v43;                                // [esp+9Ch] [ebp-2D58h] BYREF
    int v44;                                // [esp+A0h] [ebp-2D54h]
    int v45;                                // [esp+C8h] [ebp-2D2Ch]
    // storm::RefCountedObject **v46;                    // [esp+CCh] [ebp-2D28h]
    int v47;                                          // [esp+D0h] [ebp-2D24h]
    int v48;                                          // [esp+D4h] [ebp-2D20h]
    DWORD dwStyle;                                    // [esp+D8h] [ebp-2D1Ch]
    int X;                                            // [esp+DCh] [ebp-2D18h]
    int Y;                                            // [esp+E0h] [ebp-2D14h]
    int nWidth;                                       // [esp+E4h] [ebp-2D10h]
    int nHeight;                                      // [esp+E8h] [ebp-2D0Ch]
    int UbiservicesController;                        // [esp+F4h] [ebp-2D00h]
    int v57;                                          // [esp+F8h] [ebp-2CFCh]
    int v58;                                          // [esp+FCh] [ebp-2CF8h]
    int v59;                                          // [esp+100h] [ebp-2CF4h]
    int v60;                                          // [esp+104h] [ebp-2CF0h]
    int v61;                                          // [esp+108h] [ebp-2CECh]
    int Language;                                     // [esp+10Ch] [ebp-2CE8h] MAPDST
    int iGfxChecksum;                                 // [esp+110h] [ebp-2CE4h]
    int iScriptChecksum;                              // [esp+114h] [ebp-2CE0h]
    int iConfigChecksum;                              // [esp+118h] [ebp-2CDCh]
    int v66;                                          // [esp+11Ch] [ebp-2CD8h]
    int *v67;                                         // [esp+120h] [ebp-2CD4h]
    int v68;                                          // [esp+124h] [ebp-2CD0h]
    LPCSTR lpWindowName;                              // [esp+128h] [ebp-2CCCh]
    unsigned __int8(__thiscall * **Instance)(_DWORD); // [esp+134h] [ebp-2CC0h]
    int v71;                                          // [esp+138h] [ebp-2CBCh]
    const char *spBuildVersion;                       // [esp+13Ch] [ebp-2CB8h]
    wchar_t *sBuildMode;                              // [esp+140h] [ebp-2CB4h] MAPDST
    int v74;                                          // [esp+144h] [ebp-2CB0h]
    // CBBObject sTrace;                                 // [esp+148h] [ebp-2CACh] BYREF
    HWND hWnd;                        // [esp+164h] [ebp-2C90h] MAPDST BYREF
    char v85;                         // [esp+16Fh] [ebp-2C85h] BYREF
    _BYTE v86[28];                    // [esp+170h] [ebp-2C84h] BYREF
    _BYTE v87[28];                    // [esp+18Ch] [ebp-2C68h] BYREF
    _BYTE v88[28];                    // [esp+1A8h] [ebp-2C4Ch] BYREF
    _BYTE v89[40];                    // [esp+1C4h] [ebp-2C30h] BYREF
    _BYTE v90[28];                    // [esp+1ECh] [ebp-2C08h] BYREF
    _BYTE v91[28];                    // [esp+208h] [ebp-2BECh] BYREF
    std::wstring v92;                 // [esp+224h] [ebp-2BD0h] BYREF
    std::wstring sCrashlogFilename;   // [esp+240h] [ebp-2BB4h] BYREF
    std::wstring v94;                 // [esp+25Ch] [ebp-2B98h] BYREF
    std::wstring v95;                 // [esp+278h] [ebp-2B7Ch] BYREF
    wchar_t Ext[260];                 // [esp+294h] [ebp-2B60h] BYREF
    WCHAR ExeCurrentDirectory[1024];  // [esp+49Ch] [ebp-2958h] BYREF
    WCHAR RootCurrentDirectory[1024]; // [esp+14ACh] [ebp-1948h] BYREF
    wchar_t Drive[260];               // [esp+1CACh] [ebp-1148h] BYREF
    wchar_t Dir[260];                 // [esp+1EB4h] [ebp-F40h] BYREF
    WCHAR Filename[260];              // [esp+20BCh] [ebp-D38h] BYREF
    wchar_t PathName[260];            // [esp+22C4h] [ebp-B30h] BYREF
    char swpRegPath[260];             // [esp+24CCh] [ebp-928h] BYREF
    CHAR sComputerName[16];           // [esp+2DD0h] [ebp-24h] BYREF

    // EALSetup::EalInterfaceInitializer::EalInterfaceInitializer(&v85);
    //  EXCEPTION HANDLING

    // /*UPlAY*/UPlay::UPlayManager::Create();
    // /*UPlAY*/ Instance = (unsigned __int8(__thiscall ***)(_DWORD))UPlay::UPlayManager::GetInstance();
    if (true) //((**Instance)(Instance))
    {
        OnlineManager::Create();
        // /*UPlAY*/v43 = OnlineManager::GetInstance();
        // /*UPlAY*/v42 = OnlineManager::OnAcceptInvite;

        // /*UPlAY*/std::bind<void (__thiscall OnlineManager::*)(void), OnlineManager *>((int)&v11, (int)&v42, (int)&v43);
        // /*UPlAY*/std::function<void __cdecl(void)>::function<void __cdecl(void)>((std::mutex *)v89, v11, (int)sBuildMode);
        // EXCEPTION HANDLING
        // /*UPlAY*/v71 = UPlay::UPlayManager::GetInstance();
        // /*UPlAY*/(*(void(__thiscall **)(int, _BYTE *))(*(_DWORD *)v71 + 48))(v71, v89);
        // EXCEPTION HANDLING
        // /*UPlAY*/std::function<void __cdecl(void)>::~function<void __cdecl(void)>(v89);
        // /*UPlAY*/StormManager::CreateInstance();
        // /*UPlAY*/v5 = (_DWORD *)StormManager::GetInstance();
        // /*UPlAY*/StormManager::Initialize(v5);
        // controlfp(0xA031Fu, 0x30F031Fu);
        Time = timeGetTime();
        srand(Time);
        g_hInstance = &hInstance;
        GetModuleFileNameW(hInstance, Filename, 0x104u);
        GetFileVersion(Filename, &g_iFileVersionMS, &g_iFileVersionLS);
        g_iApplicationVersionMajor = HIWORD(g_iFileVersionMS);
        g_iApplicationVersionMinor = (unsigned __int16)g_iFileVersionMS;
        g_iApplicationVersionBuild = HIWORD(g_iFileVersionLS);
        v16 = 1024;
        memset(ExeCurrentDirectory, 0, sizeof(ExeCurrentDirectory));
        memset(RootCurrentDirectory, 0, sizeof(RootCurrentDirectory));
        if (!DoesDirectoryExist(L"Gfx"))
        {
            _wsplitpath(Filename, Drive, Dir, PathName, Ext);
            sBuildMode = Dir;
            swprintf(PathName, L"%s%s", Drive, Dir);
            SetCurrentDirectoryW(PathName);
        }
        GetCurrentDirectoryW(0x3FFu, ExeCurrentDirectory);
        SetRootCWD();
        GetCurrentDirectoryW(0x3FFu, RootCurrentDirectory);
        if (!DoesDirectoryExist(L"Gfx") && !RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\BlueByte\\Settlers4\\", 0, 0x20019u, &hS4RegKey))
        {
            uRegPathSize = 260;
            if (!RegQueryValueExA(hS4RegKey, "Path", 0, &Type, (LPBYTE)swpRegPath, &uRegPathSize))
            {
                SetCurrentDirectoryA(swpRegPath);
                GetCurrentDirectoryW(0x7FFu, ExeCurrentDirectory);
                SetRootCWD();
                GetCurrentDirectoryW(0x7FFu, RootCurrentDirectory);
            }
        }
        if (DoesDirectoryExist(L"Gfx"))
        {
            UserConfigDirectory = CGameSettings::GetUserConfigDirectory();
            // EXCEPTION HANDLING
            FilePaths::EnsurePathExists(UserConfigDirectory);
            // EXCEPTION HANDLING
            // std::wstring::~wstring(v87);
            if (!DoesDirectoryExist(L"Config"))
                CreateDirectoryW(L"Config", 0);
            ShowFingerprint();
            BBSupportSetErrorHandlingMode(0);
            UserDirectoryPath = FilePaths::GetUserDirectoryPath();
            // EXCEPTION HANDLING
            // std::operator+ <wchar_t>(v95, UserDirectoryPath, (wchar_t *)L"Log\\");
            // EXCEPTION HANDLING
            // std::wstring::~wstring(v88);

            std::wstring sLogDirectoryPath = UserDirectoryPath + L"Log\\";
            FilePaths::EnsurePathExists(sLogDirectoryPath);
            BBSupportSmartOpenTraceFile(sLogDirectoryPath.c_str(), nullptr);
            DbgHelpDll = BBSupportLoadDbgHelpDll(1);
            BBSupportActivateUnhandledExceptionFilter();
            BBSupportActivateNewHandler();
            BBSupportActivateDbgReportHook();
            char sInstanceTimestamp[16]; // Was originally a "global" variable at 0x3ECDB94, but only used here
            GetInstanceTimestamp(sInstanceTimestamp, 0x10u, hInstance);
            if (sInstanceTimestamp[0])
                spBuildVersion = " "; // Seems to be, when timestamp is available, no version is set in file
            else
                spBuildVersion = "";
            snprintf(
                g_strTitleEx,
                0x64u,
                "%s V%u.%02u.%04u (%s build%s%s)",
                "The Settlers IV",
                g_iApplicationVersionMajor,
                g_iApplicationVersionMinor,
                g_iApplicationVersionBuild,
                "Debug",
                spBuildVersion,
                sInstanceTimestamp);
            BBSupportTracePrint(1, "");
            BBSupportTracePrint(1, g_strTitleEx);
            BBSupportTracePrint(1, "");
            BBSupportTraceDumpModules();
            if (BBSupportIsDevelopmentMachine())
                sBuildMode = (wchar_t *)"d";
            else
                sBuildMode = (wchar_t *)"e";
            v9 = BBSupportDllVersionString();
            BBSupportTracePrintF(1, "BB_Support version %s%s.", v9, (const char *)sBuildMode);
            BBSupportTracePrintF(1, "LoadDbgHelpDll() returned %i.", DbgHelpDll);
            BBSupportTracePrintF(1, "UploadDir: %s", g_strSerial);
            memset(sComputerName, 0, sizeof(sComputerName));
            sComputerName[0] = '?';
            nSize = 16;
            GetComputerNameA(sComputerName, &nSize);
            BBSupportTracePrintF(
                0,
                "Current directory is: \"\\\\%s\\%s\".",
                sComputerName,
                (const char *)RootCurrentDirectory);
            CBBObject sTrace = CBBObject("Trace", 1);
            // EXCEPTION HANDLING
            ReadSerial();
            PrintCommandline(0);
            if (CDebugInfo::CheckEnvironment(1))
            {
                if (CDebugInfo::IsMMX())
                {
                    PreloadGfx();
                    // EXCEPTION HANDLING
                    IEventEngine::Init();
                    if (g_pEvnEngine)
                    {
                        SystemLanguage = GetSystemLanguage();
                        CGameStateHandler::InitFileLibrary();

                        // This seems to just test the string engine...
                        // Real g_pStringEngine is in CGameStateHandler::Init()
                        g_pStringEngine = CStringEngine::CreateStringEngine(SystemLanguage);
                        if (g_pStringEngine)
                            delete g_pStringEngine;
                        g_pStringEngine = nullptr;

                        if (RegisterWindowClass(hInstance))
                        {
                            if (ExistsExtractCommand())
                            {
                                KillGame(hWnd);
                                return 0;
                            }
                            else
                            {
                                if (!g_pInstallationInfo->CheckInstallation(0))
                                    MessageBoxA(0, "Installation check failed! Check the trace file.", "S4", 0x30u);
                                iConfigChecksum = g_pInstallationInfo->GetConfigChecksum();
                                g_iConfigVersion = iConfigChecksum;
                                iScriptChecksum = g_pInstallationInfo->GetScriptChecksum();
                                g_iScriptVersion = iScriptChecksum;
                                iGfxChecksum = g_pInstallationInfo->GetGfxChecksum();
                                g_iGfxVersion = iGfxChecksum;
                                CGameStateHandler::InitConfigManager();
                                CGameSettings::LoadCommandLineValues();
                                CGameSettings::Validate();
                                Language = CGameSettings::GetLanguage();
                                /* UPLAY */
                                // if (Language)
                                // {
                                //     if (Language == 1)
                                //     {
                                //         v17 = std::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>("de-DE");
                                //         // EXCEPTION HANDLING
                                //         v57 = StormManager::GetInstance();
                                //         UbiservicesController = StormManager::GetUbiservicesController(v57);
                                //         v68 = UbiservicesController;
                                //         (*(void(__thiscall **)(int, wstring *))(*(_DWORD *)UbiservicesController + 136))(
                                //             UbiservicesController,
                                //             v92);
                                //         // EXCEPTION HANDLING
                                //         std::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>::~basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>(v92);
                                //     }
                                //     else if (Language == 2)
                                //     {
                                //         SystemLanguageId = std::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>("fr-FR");
                                //         // EXCEPTION HANDLING
                                //         v59 = StormManager::GetInstance();
                                //         v58 = StormManager::GetUbiservicesController(v59);
                                //         v66 = v58;
                                //         (*(void(__thiscall **)(int, _BYTE *))(*(_DWORD *)v58 + 136))(v58, v90);
                                //         // EXCEPTION HANDLING
                                //         std::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>::~basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>(v90);
                                //     }
                                // }
                                // else
                                // {
                                //     v19 = std::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>("en-UK");
                                //     // EXCEPTION HANDLING
                                //     v61 = StormManager::GetInstance();
                                //     v60 = StormManager::GetUbiservicesController(v61);
                                //     v74 = v60;
                                //     (*(void(__thiscall **)(int, _BYTE *))(*(_DWORD *)v60 + 136))(v60, v91);
                                //     // EXCEPTION HANDLING
                                //     std::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>::~basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>(v91);
                                // }

                                if (!BBSupportIsDevelopmentMachine())
                                {
                                    CheckForCrashlog();
                                    AppendTracefileToCrashlog();
                                }
                                if (CGameSettings::GetGfxFullscreenEnabled())
                                    dwStyle = WS_OVERLAPPED;
                                else
                                    dwStyle = WS_OVERLAPPEDWINDOW;
                                Language = CGameSettings::GetLanguage();
                                if (Language == 1)
                                    lpWindowName = "Die Siedler IV";
                                else
                                    lpWindowName = "The Settlers IV";
                                nHeight = CGameSettings::GetGfxHeight();
                                nWidth = CGameSettings::GetGfxWidth();
                                Y = CGameSettings::GetWindowsPosY();
                                X = CGameSettings::GetWindowsPosX();
                                hWnd = CreateWindowExA(0, "S4", lpWindowName, dwStyle, X, Y, nWidth, nHeight, 0, 0, hInstance, 0);
                                if (hWnd)
                                {
                                    g_hWnd = hWnd;
                                    ShowWindow(hWnd, 1);
                                    CGameStateHandler::SetCorrectWindowSize();
                                    if (CGameStateHandler::Init())
                                    {
                                        g_pEvnEngine->SetOSParam1(g_hWnd);
                                        memset(v14, 0, sizeof(v14));
                                        while (CGameStateHandler::Perform())
                                            ;
                                        CGameStateHandler::Kill();
                                        // /*UPlAY*/v46 = StormManager::GetInstance();
                                        // /*UPlAY*/StormManager::Shutdown(v46);
                                        // /*UPlAY*/StormManager::DestroyInstance();
                                        OnlineManager::Destroy();
                                        // /*UPlAY*/UPlay::UPlayManager::Release();
                                        CleanupArgs();
                                        DeleteFileW(GetCrashlogFilename().c_str());
                                        if (hObject)
                                            CloseHandle(hObject);
                                        return 0;
                                    }
                                    else
                                    {
                                        CTrace::Print("*** CGameStateHandler::Init() failed! ***");
                                        KillGame(hWnd);
                                        return 0;
                                    }
                                }
                                else
                                {
                                    KillGame(hWnd);
                                    return 0;
                                }
                            }
                        }
                        else
                        {
                            KillGame(hWnd);
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    MessageBoxA(0, "The Settlers IV needs a CPU with MMX instruction set! Die Siedler IV benötigt einen MMX-kompatiblen Hauptprozessor!", "S4", MB_ICONEXCLAMATION);
                    KillGame(hWnd);
                    return 0;
                }
            }
            else
            {
                KillGame(hWnd);
                return 0;
            }
        }
        else
        {
            BBSupportSetErrorHandlingMode(1u);
            UserDirectoryPath = FilePaths::GetUserDirectoryPath();
            // EXCEPTION HANDLING
            std::wstring sTraceFilePath = UserDirectoryPath + L"Trace.txt";
            // EXCEPTION HANDLING
            BBSupportOpenTraceFile(1, sTraceFilePath.c_str());
            BBSupportTracePrint(3, "FATAL ERROR: Can't find data directory!");
            BBSupportTracePrint(3, "");
            BBSupportTracePrintF(3, "Current directory at start: %s", (const char *)ExeCurrentDirectory);
            BBSupportTracePrintF(3, "Current directory now:      %s", (const char *)RootCurrentDirectory);
            MessageBoxA(0, "Can't find data directory!    \n", "The Settlers IV - Fatal error", 0x10u);
            return 0;
        }
    }
    else
    {
        return -1;
    }
}