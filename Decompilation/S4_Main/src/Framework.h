#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <windows.h>

// address=[0x03ECDADC]
extern unsigned int g_iFileVersionMS;

// address=[0x03ECDB44]
extern unsigned int g_iFileVersionLS;

// address=[0x3ecda58]
extern unsigned int g_iApplicationVersionMajor;

// address=[0x3ecda5c]
extern unsigned int g_iApplicationVersionMinor;

// address=[0x3ecda60]
extern unsigned int g_iApplicationVersionBuild;

// address=[0x3ecda64]
extern unsigned int g_iScriptVersion;

// address=[0x3ecda68]
extern unsigned int g_iConfigVersion;

// address=[0x3ecda6c]
extern unsigned int g_iGfxVersion;

// address=[0x3ecda70]
extern HWND g_hWnd;

// address=[0x3ecda74]
extern HINSTANCE *g_hInstance;

// address=[0x3ecda78]
extern char * g_strTitleEx;

// address=[0x3ecdae0]
extern char * g_strSerial;

// address=[0x13589F0]
extern bool __cdecl DoesDirectoryExist(LPCWSTR lpFileName);

// address=[0x13587C0]
extern void SetRootCWD();

// address=[0x13598A0]
extern void ReadSerial();

// address=[0x01358EC0]
bool __fastcall GetFileVersion(const WCHAR *_spFilePath, _DWORD *a2, _DWORD *a3);

// address=[0x01358760]
extern BOOL __stdcall KillGame(HWND hWnd);

// address=[0x01359BE0]
extern void __cdecl ShowFingerprint(void);

// address=[0x01358A50]
void __cdecl GetInstanceTimestamp(char *Buffer, size_t Size, void *a3);

#endif // FRAMEWORK_H