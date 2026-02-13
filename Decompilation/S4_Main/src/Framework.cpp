#include "Framework.h"

#include "defines.h"
#include "CBB/CBBSupport.h"
#include "Debug/CTrace.h"
#include "Main/CGameStateHandler.h"
#include "Logic/Events/IEventEngine.h"
#include "File/CFile.h"

#include <direct.h>
#include <time.h>

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

void __cdecl ShowFingerprint()
{
    int v0;           // [esp+0h] [ebp-F8h] BYREF
    int v1;           // [esp+10h] [ebp-E8h]
    signed int iSize; // [esp+14h] [ebp-E4h] MAPDST

    CHAR Text[128];     // [esp+64h] [ebp-94h] BYREF
    int *v6;            // [esp+E8h] [ebp-10h]
    int exceptionBlock; // [esp+F4h] [ebp-4h]

    v6 = &v0;
    CFile sVersionFile = CFile();
    // exceptionBlock = 1;
    sVersionFile.Open((wchar_t *)L"Version.txt", 5, "", 0);
    iSize = sVersionFile.Size();
    if (iSize >= 128)
    {
        v1 = BBSupportDbgReport(2, "FrameWork.cpp", 770, "iSize < MAX_FINGERPRINT_LENGTH");
        if (v1 == 1)
            __debugbreak();
    }
    memset(Text, 0, sizeof(Text));
    sVersionFile.Read(Text, iSize, 1u, "", 0);
    sVersionFile.Close("", 0);
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