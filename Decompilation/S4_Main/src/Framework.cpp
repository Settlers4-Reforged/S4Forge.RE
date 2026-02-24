#include "Framework.h"

#include "defines.h"
#include "CBB/CBBSupport.h"
#include "CBB/Bugreport.h"
#include "Debug/CTrace.h"
#include "Main/CGameStateHandler.h"
#include "Logic/Events/IEventEngine.h"
#include "File/CFile.h"
#include "File/CFileEx.h"
#include "File/FilePaths.h"

#include <direct.h>
#include <time.h>
#include <locale>
#include <codecvt>

// Note:
// Technically Framework.cpp and main.cpp are the same, as they share symbols not included in the linker library - meaning they are not linked but rather are one compilation unit.
// For now this separation is kept for organizational purposes

// address=[0x03ECDADC]
unsigned int g_iFileVersionMS;

// address=[0x03ECDB44]
unsigned int g_iFileVersionLS;

// address=[0x3ecda58]
unsigned int g_iApplicationVersionMajor;

// address=[0x3ecda5c]
unsigned int g_iApplicationVersionMinor;

// address=[0x3ecda60]
unsigned int g_iApplicationVersionBuild;

// address=[0x3ecda64]
unsigned int g_iScriptVersion;

// address=[0x3ecda68]
unsigned int g_iConfigVersion;

// address=[0x3ecda6c]
unsigned int g_iGfxVersion;

// address=[0x3ecda70]
HWND g_hWnd;

// address=[0x3ecda74]
HINSTANCE *g_hInstance;

// address=[0x3ecda78]
char *g_strTitleEx;

// address=[0x3ecdae0]
char *g_strSerial;

// address=[0x3ECDB4C]
int g_iArgc;

// address=[0x3ECDB48]
char **g_pArgv;

// address=[0x3ECDB50]
HANDLE hObject;

// address=[0x13589F0]
bool __cdecl DoesDirectoryExist(LPCWSTR lpFileName)
{
    int FileAttributesW; // [esp+4h] [ebp-8h]
    char v4;             // [esp+Bh] [ebp-1h]

    v4 = 0;
    if (!lpFileName || !*lpFileName)
        return v4;
    FileAttributesW = GetFileAttributesW(lpFileName);
    return FileAttributesW != (unsigned int)INVALID_FILE_ATTRIBUTES && (FileAttributesW & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

// address=[0x13587C0]
void SetRootCWD()
{
    char v0[4];       // [esp+0h] [ebp-410h] BYREF
    char v1[4];       // [esp+4h] [ebp-40Ch] BYREF
    DWORD uCwdLength; // [esp+8h] [ebp-408h] BYREF
    char swCwd[1023]; // [esp+Ch] [ebp-404h] BYREF
    char v4;          // [esp+40Bh] [ebp-5h]

    if (getcwd(swCwd, 1023))
    {
        uCwdLength = strlen(swCwd);
        if ((int)uCwdLength >= 11)
        {
            if (!stricmp("\\exe", &swCwd[uCwdLength - 4]))
            {
                chdir("..");
            }
            else
            {
                if (!stricmp("\\_debug", &swCwd[uCwdLength - 7]) || !stricmp("\\_debugfast", &swCwd[uCwdLength - 11]) || !stricmp("\\_demo", &swCwd[uCwdLength - 6]) || !stricmp("\\_openbeta", &swCwd[uCwdLength - 10]) || !stricmp("\\_release", &swCwd[uCwdLength - 9]) || !stricmp("\\_production", &swCwd[uCwdLength - 12]))
                {
                    chdir("..");
                }
                if (getcwd(swCwd, 1023))
                {
                    uCwdLength = strlen(swCwd);
                    if (uCwdLength >= 11 && !stricmp("\\s4_main", &swCwd[uCwdLength - 8]))
                        chdir("..\\s4_data");
                }
            }
        }
    }
}

void ReadSerial()
{
    unsigned long Type;   // [esp+0h] [ebp-18h] BYREF
    unsigned long cbData; // [esp+4h] [ebp-14h] BYREF
    int v2;               // [esp+8h] [ebp-10h]
    HKEY phkResult;       // [esp+Ch] [ebp-Ch] BYREF
    LSTATUS success;      // [esp+10h] [ebp-8h]
    const char *v5;       // [esp+14h] [ebp-4h]

    v2 = KEY_READ;
    v5 = "reading";
    CTrace::Print("Opening registry key '%s' in %s mode", "SOFTWARE\\BlueByte\\Settlers4\\", "reading");
    success = RegCreateKeyExA(
        HKEY_LOCAL_MACHINE,
        "SOFTWARE\\BlueByte\\Settlers4\\",
        0,
        0,
        0,
        KEY_ALL_ACCESS,
        0,
        &phkResult,
        0);
    if (!success)
    {
        cbData = 100;
        success = RegQueryValueExA(phkResult, "SerialNumber", 0, &Type, (LPBYTE)g_strSerial, &cbData);
        RegCloseKey(phkResult);
    }
}

// address=[0x01358760]
BOOL __stdcall KillGame(HWND hWnd)
{
    CGameStateHandler::Kill();
    delete g_pEvnEngine;
    g_pEvnEngine = nullptr;
    return DestroyWindow(g_hWnd);
}

// address=[0x01358EC0]
bool __fastcall GetFileVersion(const WCHAR *_spFilePath, _DWORD *a2, _DWORD *a3)
{
    unsigned int puLen;     // [esp+0h] [ebp-20h] BYREF
    unsigned long dwHandle; // [esp+4h] [ebp-1Ch] BYREF
    LPVOID lpBuffer;        // [esp+8h] [ebp-18h] BYREF
    LPVOID lpData;          // [esp+14h] [ebp-Ch]
    unsigned long dwLen;    // [esp+18h] [ebp-8h]
    char v11;               // [esp+1Fh] [ebp-1h]

    dwLen = GetFileVersionInfoSizeW(_spFilePath, &dwHandle);
    if (!dwLen)
        return false;
    lpData = malloc(dwLen);
    if (GetFileVersionInfoW(_spFilePath, dwHandle, dwLen, lpData) && VerQueryValueW(lpData, L"\\", &lpBuffer, &puLen))
    {
        if (a2)
            *a2 = *((_DWORD *)lpBuffer + 2);
        if (a3)
            *a3 = *((_DWORD *)lpBuffer + 3);
    }
    free(lpData);
    return true;
}

// address=[0x01359BE0]
void __cdecl ShowFingerprint()
{
    int v0;           // [esp+0h] [ebp-F8h] BYREF
    int v1;           // [esp+10h] [ebp-E8h]
    signed int iSize; // [esp+14h] [ebp-E4h] MAPDST

    CHAR Text[128]; // [esp+64h] [ebp-94h] BYREF
    int *v6;        // [esp+E8h] [ebp-10h]
    // int exceptionBlock; // [esp+F4h] [ebp-4h]

    v6 = &v0;
    CFile sVersionFile = CFile();
    // exceptionBlock = 1;
    sVersionFile.Open((wchar_t *)L"Version.txt", 5, CFileLog);
    iSize = sVersionFile.Size();
    if (iSize >= 128)
    {
        v1 = BBSupportDbgReport(2, "FrameWork.cpp", 770, "iSize < MAX_FINGERPRINT_LENGTH");
        if (v1 == 1)
            __debugbreak();
    }
    memset(Text, 0, sizeof(Text));
    sVersionFile.Read(Text, iSize, 1u, CFileLog);
    sVersionFile.Close(CFileLog);
    MessageBoxA(g_hWnd, Text, "S4", MB_ICONEXCLAMATION);
    // exceptionBlock = -1;
}

void __cdecl GetInstanceTimestamp(char *Buffer, size_t Size, void *a3)
{
    struct tm *v3;                    // eax
    __time64_t Time;                  // [esp+0h] [ebp-34h] BYREF
    unsigned int ModuleTimeDateStamp; // [esp+8h] [ebp-2Ch]
    _DWORD v6[9];                     // [esp+Ch] [ebp-28h] BYREF

    if (Buffer)
    {
        memset(Buffer, 0, Size);
        ModuleTimeDateStamp = BBSupportGetModuleTimeDateStamp(a3);
        if (ModuleTimeDateStamp)
        {
            Time = ModuleTimeDateStamp;
            memset(v6, 0, sizeof(v6));
            v3 = _gmtime64(&Time);
            memcpy(v6, v3, sizeof(v6));
            snprintf(Buffer, Size, "%02i%02i%02i%02i", v6[4] + 1, v6[3], v6[2], v6[1]);
        }
    }
}

// address=[0x013591E0]
int __cdecl CountArguments(char *spQuotedString)
{
    int uCount;     // [esp+4h] [ebp-Ch]
    size_t i;       // [esp+8h] [ebp-8h]
    bool bInQuotes; // [esp+Fh] [ebp-1h]

    bInQuotes = FALSE;
    uCount = 0;
    for (i = 0; i < strlen(spQuotedString); ++i)
    {
        if (spQuotedString[i] == '"')
        {
            bInQuotes = !bInQuotes;
        }
        else if (spQuotedString[i] == ' ' && !bInQuotes)
        {
            ++uCount;
            while (spQuotedString[i] == ' ' && i < strlen(spQuotedString)) // Skip repeating spaces
                ++i;
        }
    }
    if (bInQuotes)
        CTrace::Print("Framework.cpp: Quote error parsing commandline. Continued anyway...!");
    return uCount + 1;
}

// address=[0x1358F70]
void __cdecl PrintCommandline(bool _bKeepFirstArg)
{
    signed int uCommandLineLength; // [esp+4h] [ebp-30h]
    int iArgc;                     // [esp+18h] [ebp-1Ch]
    signed int uArgumentLength;    // [esp+1Ch] [ebp-18h]
    signed int k;                  // [esp+20h] [ebp-14h]
    int i;                         // [esp+24h] [ebp-10h]
    char *spCommandLine;           // [esp+28h] [ebp-Ch]
    signed int j;                  // [esp+2Ch] [ebp-8h]
    bool bSkipArg;                 // [esp+32h] [ebp-2h]
    bool bInQuotes;                // [esp+33h] [ebp-1h]

    spCommandLine = GetCommandLineA();
    BBSupportTracePrintF(1, "Commandline: '%s'", spCommandLine);
    uCommandLineLength = strlen(spCommandLine);
    iArgc = CountArguments(spCommandLine) - !_bKeepFirstArg;
    g_iArgc = iArgc;
    g_pArgv = (char **)operator new[](4 * iArgc);
    uArgumentLength = 0;
    bInQuotes = 0;
    bSkipArg = !_bKeepFirstArg;
    for (i = 0; i < iArgc; ++i)
    {
        for (j = uArgumentLength; j < uCommandLineLength; ++j)
        {
            if (spCommandLine[j] == '"')
            {
                bInQuotes = !bInQuotes;
            }
            else if (spCommandLine[j] == ' ' && !bInQuotes)
            {
                break;
            }
        }
        if (bSkipArg)
        {
            bSkipArg = 0;
            --i;
        }
        else
        {
            g_pArgv[i] = (char *)operator new[](j - uArgumentLength + 1);
            for (k = uArgumentLength; k < j; ++k)
                g_pArgv[i][k - uArgumentLength] = spCommandLine[k];
            g_pArgv[i][k - uArgumentLength] = 0;
        }
        if (spCommandLine[j] == ' ' && !bInQuotes)
        {
            while (spCommandLine[j] == ' ' && j < strlen(spCommandLine))
                ++j;
        }
        uArgumentLength = j;
    }
}

// address=[0x013592B0]
void __cdecl PrepareFilesForReading(const wchar_t *_swpFolder, const wchar_t *_swpFileSearch)
{
    HANDLE hFindFile;                       // [esp+0h] [ebp-1268h]
    struct _WIN32_FIND_DATAW pFindFileData; // [esp+4h] [ebp-1264h] BYREF
    WCHAR swpFoundFilePath[1028];           // [esp+254h] [ebp-1014h] BYREF
    WCHAR swpSearchPathWildcard[1028];      // [esp+A5Ch] [ebp-80Ch] BYREF

    memset(swpSearchPathWildcard, 0, sizeof(swpSearchPathWildcard));
    memset(swpFoundFilePath, 0, sizeof(swpFoundFilePath));
    if (_swpFolder)
    {
        if (_swpFileSearch)
        {
            if (*_swpFileSearch)
            {
                wsprintfW(swpSearchPathWildcard, L"%s%s", _swpFolder, _swpFileSearch);
                memset(&pFindFileData, 0, sizeof(pFindFileData));
                hFindFile = FindFirstFileW(swpSearchPathWildcard, &pFindFileData);
                if (hFindFile != (HANDLE)-1)
                {
                    do
                    {
                        wsprintfW(swpFoundFilePath, L"%s%s", _swpFolder, pFindFileData.cFileName);
                        SetFileAttributesW(swpFoundFilePath, FILE_ATTRIBUTE_NORMAL);
                    } while (FindNextFileW(hFindFile, &pFindFileData));
                    FindClose(hFindFile);
                }
            }
        }
    }
}

// address=[0x013593E0]
void __cdecl PreloadGfx()
{
    PrepareFilesForReading(L"Gfx\\", L"1.*");
    PrepareFilesForReading(L"Gfx\\", L"35.*");
}

// address=[0x013591E0]
unsigned long __cdecl GetSystemLanguage(void)
{
    unsigned int i; // [esp+8h] [ebp-4D8h]
    struct SLanguagePair
    {
        const char *m_spName;
        int m_iId;
    } sAvailableLanguages[26]; // [esp+Ch] [ebp-4D4h]
    CHAR LCData[1024];         // [esp+DCh] [ebp-404h] BYREF

    sAvailableLanguages[0].m_spName = "DE";
    sAvailableLanguages[0].m_iId = 1;
    sAvailableLanguages[1].m_spName = "GE";
    sAvailableLanguages[1].m_iId = 1;
    sAvailableLanguages[2].m_spName = "EN";
    sAvailableLanguages[2].m_iId = 0;
    sAvailableLanguages[3].m_spName = "CH";
    sAvailableLanguages[3].m_iId = 7;
    sAvailableLanguages[4].m_spName = "ZH";
    sAvailableLanguages[4].m_iId = 7;
    sAvailableLanguages[5].m_spName = "CZ";
    sAvailableLanguages[5].m_iId = 13;
    sAvailableLanguages[6].m_spName = "CE";
    sAvailableLanguages[6].m_iId = 13;
    sAvailableLanguages[7].m_spName = "CS";
    sAvailableLanguages[7].m_iId = 13;
    sAvailableLanguages[8].m_spName = "DA";
    sAvailableLanguages[8].m_iId = 9;
    sAvailableLanguages[9].m_spName = "FI";
    sAvailableLanguages[9].m_iId = 14;
    sAvailableLanguages[10].m_spName = "FR";
    sAvailableLanguages[10].m_iId = 2;
    sAvailableLanguages[11].m_spName = "HE";
    sAvailableLanguages[11].m_iId = 12;
    sAvailableLanguages[12].m_spName = "HU";
    sAvailableLanguages[12].m_iId = 11;
    sAvailableLanguages[13].m_spName = "IT";
    sAvailableLanguages[13].m_iId = 4;
    sAvailableLanguages[14].m_spName = "JP";
    sAvailableLanguages[14].m_iId = 18;
    sAvailableLanguages[15].m_spName = "JA";
    sAvailableLanguages[15].m_iId = 18;
    sAvailableLanguages[16].m_spName = "KO";
    sAvailableLanguages[16].m_iId = 6;
    sAvailableLanguages[17].m_spName = "NO";
    sAvailableLanguages[17].m_iId = 10;
    sAvailableLanguages[18].m_spName = "PO";
    sAvailableLanguages[18].m_iId = 5;
    sAvailableLanguages[19].m_spName = "PL";
    sAvailableLanguages[19].m_iId = 5;
    sAvailableLanguages[20].m_spName = "RU";
    sAvailableLanguages[20].m_iId = 16;
    sAvailableLanguages[21].m_spName = "SP";
    sAvailableLanguages[21].m_iId = 3;
    sAvailableLanguages[22].m_spName = "ES";
    sAvailableLanguages[22].m_iId = 3;
    sAvailableLanguages[23].m_spName = "SW";
    sAvailableLanguages[23].m_iId = 8;
    sAvailableLanguages[24].m_spName = "SV";
    sAvailableLanguages[24].m_iId = 8;
    sAvailableLanguages[25].m_spName = "TH";
    sAvailableLanguages[25].m_iId = 17;
    GetLocaleInfoA(LOCALE_SYSTEM_DEFAULT, 3u, LCData, 1024);
    LCData[2] = 0;
    for (i = 0; i < 26; ++i)
    {
        if (!strcmp(sAvailableLanguages[i].m_spName, LCData))
            return sAvailableLanguages[i].m_iId;
    }
    return 0;
}

// address=[0x1359410]
// Decompiled from ATOM __cdecl RegisterWindowClass(HINSTANCE hInstance)
unsigned short __cdecl RegisterWindowClass(HINSTANCE hInstance)
{

    if (!g_pEvnEngine && BBSupportDbgReport(2, "FrameWork.cpp", 300, "g_pEvnEngine != NULL") == 1)
        __debugbreak();
    if (!g_pEvnEngine)
        return -1;

    WNDCLASSEXA sWindowsClass{};
    sWindowsClass.cbSize = 48;
    sWindowsClass.style = 3;
    sWindowsClass.lpfnWndProc = (WNDPROC)g_pEvnEngine->GetEventFunction();
    sWindowsClass.cbClsExtra = 0;
    sWindowsClass.cbWndExtra = 0;
    sWindowsClass.hInstance = hInstance;
    // TODO: Add cursor and icon resources!!
    sWindowsClass.hIcon = LoadIconA(hInstance, (LPCSTR)0x72);
    sWindowsClass.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
    sWindowsClass.hbrBackground = CreateSolidBrush(0);
    sWindowsClass.lpszMenuName = 0;
    sWindowsClass.lpszClassName = "S4";
    sWindowsClass.hIconSm = 0;
    return RegisterClassExA(&sWindowsClass);
}

// address=[0x13594d0]
bool __cdecl ExistsExtractCommand(void)
{
    wchar_t *v1;             // eax
    size_t v2;               // eax
    _DWORD v3[7];            // [esp+0h] [ebp-228h] BYREF
    void *v4;                // [esp+1Ch] [ebp-20Ch]
    size_t v5;               // [esp+20h] [ebp-208h]
    size_t v6;               // [esp+24h] [ebp-204h]
    void *Buffer;            // [esp+28h] [ebp-200h]
    size_t uExtractFileSize; // [esp+2Ch] [ebp-1FCh]
    char v9;                 // [esp+31h] [ebp-1F7h]
    char v10;                // [esp+32h] [ebp-1F6h]
    char v11;                // [esp+33h] [ebp-1F5h]
    char v12[88];            // [esp+34h] [ebp-1F4h] BYREF

    int v14;     // [esp+F4h] [ebp-134h] BYREF
    _DWORD *v17; // [esp+218h] [ebp-10h]
    int v18;     // [esp+224h] [ebp-4h]

    if (!g_iArgc)
        return 0;

    wchar_t swpAllArguments[128];
    memset(swpAllArguments, 0, sizeof(swpAllArguments));
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> conv{};
    wcsncpy(swpAllArguments, conv.from_bytes(*g_pArgv).c_str(), 127);
    wcsupr(swpAllArguments);

    if (wcsstr(swpAllArguments, L"EXTRACT:\""))
    {
        memcpy(swpAllArguments, &swpAllArguments[9], wcslen(swpAllArguments) - 9);
        v6 = 2 * wcslen(swpAllArguments) - 20;
        if (v6 >= 0x100)
            throw std::length_error("Extract command too long!");
        *(wchar_t *)((char *)swpAllArguments + v6) = 0;
        CFileEx pExtractFile{};

        pExtractFile.Open(swpAllArguments, 6, 0, CFileLog);

        uExtractFileSize = 0;
        uExtractFileSize = pExtractFile.Size();
        if (uExtractFileSize)
        {
            Buffer = new char[uExtractFileSize + 8];
            memset(Buffer, 0, uExtractFileSize + 8);
            pExtractFile.Read(Buffer, 1, uExtractFileSize, CFileLog);
        }
        v18 = 2;
        pExtractFile.Close(CFileLog);
        if (Buffer)
        {
            pExtractFile.Open(L"Extract", 8, 0, CFileLog);
            pExtractFile.Write(Buffer, 1u, uExtractFileSize, CFileLog);
            pExtractFile.Close(CFileLog);
            MessageBoxA(0, "File successfully extracted!", "", 0);
            delete[] Buffer;
        }
        else
        {
            MessageBoxA(0, "Error while reading file!", "", 0);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

// address=[0x013585F0]
std::wstring GetCrashlogFilename()
{
    return FilePaths::GetUserDirectoryPath() + L"Crashinfo.txt";
}

// address=[0x01358B00]
int CheckForCrashlog()
{
    size_t uCrashlogBytesRead;   // [esp+20h] [ebp-2E0h] MAPDST
    size_t uCrashlogSize;        // [esp+24h] [ebp-2DCh]
    unsigned int v8;             // [esp+28h] [ebp-2D8h]
    WCHAR ExistingFileName[260]; // [esp+E4h] [ebp-21Ch] BYREF

    CTrace::Print("Framework.cpp: Checking for file 'Crashlog.txt'");
    CFile pCrashlogFile{};
    pCrashlogFile.Open(GetCrashlogFilename(), 5, CFileLog);
    uCrashlogSize = pCrashlogFile.Size();
    uCrashlogBytesRead = pCrashlogFile.Read(ExistingFileName, 1u, uCrashlogSize, CFileLog);

    v8 = 2 * uCrashlogBytesRead;
    if (2 * uCrashlogBytesRead >= 520)
        throw std::length_error("Crashlog filename too long!");

    ExistingFileName[v8 / 2] = 0;
    pCrashlogFile.Close(CFileLog);

    CTrace::Print("Framework.cpp: 'Crashlog.txt' found! ");
    std::wstring sTraceFilePath(Bugreport::BuildTraceFilePath(ExistingFileName));

    if (!sTraceFilePath.empty())
    {
        FilePaths::EnsurePathExists(sTraceFilePath);
        CopyFileW(ExistingFileName, sTraceFilePath.c_str(), 0);
        Bugreport::LaunchAutoreport(0, Bugreport::BuildAutoReporterCmdLineArgsForDebugReports());
    }
}

void CleanupArgs()
{
    unsigned int i; // [esp+8h] [ebp-4h]

    for (i = 0; i < g_iArgc; ++i)
        delete[] g_pArgv[i];
    delete[] g_pArgv;
}
