#include "Bugreport.h"

#include "File/FilePaths.h"
#include "Framework.h"
#include <windows.h>
#include <assert.h>

// address=[0x134dbe0]
// Decompiled from std::wstring *__cdecl Bugreport::GetBugReportsDirectoryPath(std::wstring *a1)
std::wstring __cdecl Bugreport::GetBugReportsDirectoryPath()
{
    return FilePaths::GetUserDirectoryPath() + L"Bugreport\\";
}

// address=[0x134dc80]
// Decompiled from std::wstring *__cdecl Bugreport::GetBugReportScreenshotPath(std::wstring *a1)
std::wstring __cdecl Bugreport::GetBugReportScreenshotPath()
{

    return FilePaths::GetUserDirectoryPath() + L"Bugreport\\screenshot%2d.bmp";
}

// address=[0x134dd20]
// Decompiled from std::wstring *__cdecl Bugreport::GetBugReportMessageFilePath(std::wstring *a1)
std::wstring __cdecl Bugreport::GetBugReportMessageFilePath()
{
    return FilePaths::GetUserDirectoryPath() + L"Bugreport\\Message.txt";
}

// address=[0x134ddc0]
// Decompiled from std::wstring *__cdecl Bugreport::BuildAutoReporterCmdLineArgsForDebugReports(std::wstring *a1)
std::wstring __cdecl Bugreport::BuildAutoReporterCmdLineArgsForDebugReports()
{
    return FilePaths::GetUserDirectoryPath() + L" Settlers4,Bugreport,Message.txt,0";
}

// address=[0x134de90]
// Decompiled from std::wstring *__cdecl Bugreport::BuildAutoReporterCmdLineArgsForUserReports(std::wstring *a1)
std::wstring __cdecl Bugreport::BuildAutoReporterCmdLineArgsForUserReports()
{
    return FilePaths::GetUserDirectoryPath() + L" Settlers4,Bugreport,Message.txt,1,0";
}

// address=[0x134df60]
// Decompiled from std::wstring *__cdecl Bugreport::BuildTraceFilePath(std::wstring *a1, std::wstring *a2)
std::wstring __cdecl Bugreport::BuildTraceFilePath(std::wstring const &a2)
{
    std::wstring BugReportsDirectoryPath; // [esp+4h] [ebp-84h]
    std::wstring v5;                      // [esp+5Ch] [ebp-2Ch] BYREF
    int v6;                               // [esp+84h] [ebp-4h]

    if (a2.empty())
    {
        return L"";
    }

    FilePaths::PathSplitResult sPathSplits = FilePaths::SplitPath(a2);
    return Bugreport::GetBugReportsDirectoryPath() + sPathSplits.m_swpDirectoryName;
}

// address=[0x134e050]
// Decompiled from int __cdecl Bugreport::LaunchAutoreport(char a1, std::wstring *a2)
void __cdecl Bugreport::LaunchAutoreport(bool a1, std::wstring const &a2)
{
    int result;                             // eax
    STARTUPINFOW StartupInfo;               // [esp+0h] [ebp-264h] BYREF
    PROCESS_INFORMATION ProcessInformation; // [esp+44h] [ebp-220h] BYREF
    DWORD ExitCode;                         // [esp+54h] [ebp-210h] BYREF
    WCHAR CommandLine[260];                 // [esp+58h] [ebp-20Ch] BYREF

    memset(&StartupInfo, 0, sizeof(StartupInfo));
    StartupInfo.cb = 68;
    memset(&ProcessInformation, 0, sizeof(ProcessInformation));
    if (a2.size() >= 0x104)
        _wassert(L"commandLineArgs.size() < MAX_PATH", L"Bugreport.cpp", 0x41u);

    _snwprintf(CommandLine, 0x104u, L"%s", a2.c_str());
    result = CreateProcessW(L"Exe\\Autoreport.exe", CommandLine, 0, 0, 0, 0, 0, 0, &StartupInfo, &ProcessInformation);
    if (result)
    {
        // for (ExitCode = 259; ExitCode == 259; result = GetExitCodeProcess(ProcessInformation.hProcess, &ExitCode))
        //     ;
        WaitForSingleObject(ProcessInformation.hProcess, INFINITE);
    }
    else if (a1)
    {
        MessageBoxA(g_hWnd, "Unable to launch Autoreport.exe!", "S4", 0x30u);
    }
}