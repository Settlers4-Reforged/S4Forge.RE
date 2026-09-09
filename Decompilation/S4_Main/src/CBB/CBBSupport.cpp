#include "CBBSupport.h"

// address=[0x2f2d8c0]
// Decompiled from int __stdcall BBSupportDbgReport(int a1, const char *a2, int a3, const char *a4)
int __stdcall BBSupportDbgReport(int a1, char const *a2, unsigned int a3, char const *a4) {
    return 0;
    //
    //   bool v4; // sf
    //   const WCHAR *v6; // eax
    //   UINT v7; // [esp+18h] [ebp-2ED0h]
    //   const char *v8; // [esp+1Ch] [ebp-2ECCh]
    //   const char *v10; // [esp+34h] [ebp-2EB4h]
    //   int v11; // [esp+3Ch] [ebp-2EACh]
    //   HWND LastActivePopup; // [esp+40h] [ebp-2EA8h]
    //   const char *v13; // [esp+44h] [ebp-2EA4h]
    //   const char *v14; // [esp+50h] [ebp-2E98h]
    //   HWND hWnd; // [esp+54h] [ebp-2E94h]
    //   bool v16; // [esp+5Ah] [ebp-2E8Eh]
    //   bool v17; // [esp+5Bh] [ebp-2E8Dh]
    //   char v18[88]; // [esp+5Ch] [ebp-2E8Ch] BYREF
    //   int v19[7]; // [esp+B4h] [ebp-2E34h] BYREF
    //   char Str[4096]; // [esp+D0h] [ebp-2E18h] BYREF
    //   char Source[2048]; // [esp+10D0h] [ebp-1E18h] BYREF
    //   WCHAR Caption[1024]; // [esp+18D0h] [ebp-1618h] BYREF
    //   CHAR OutputString[1024]; // [esp+20D0h] [ebp-E18h] BYREF
    //   CHAR v24[1024]; // [esp+24D0h] [ebp-A18h] BYREF
    //   CHAR v25[1024]; // [esp+28D0h] [ebp-618h] BYREF
    //   _WORD v26[260]; // [esp+2CD0h] [ebp-218h] BYREF
    //   int v27; // [esp+2EE4h] [ebp-4h]
    //   signed int v28; // [esp+2EF0h] [ebp+8h]
    //
    //   v16 = (a1 & 0x40000000) != 0;
    //   v4 = a1 < 0;
    //   v28 = a1 & 0xBFFFFFFF;
    //   if ( v4 || v28 > 3 )
    //   {
    //     return -1;
    //   }
    //   memset(v24, 0, sizeof(v24));
    //   memset(v25, 0, sizeof(v25));
    //   if ( a2 )
    //   {
    //     _wsprintfA(v24, "File %s, line %u.", a2, a3);
    //     _wsprintfA(v25, "%s (%u)", a2, a3);
    //   }
    //   if ( _InterlockedIncrement(&dword_3E2E224) <= 0 )
    //   {
    //     if ( a4 )
    //     {
    //       v13 = a4;
    //     }
    //     else
    //     {
    //       v13 = (const char *)&unk_3AB990E;
    //     }
    //     if ( a2 )
    //     {
    //       v8 = ": ";
    //     }
    //     else
    //     {
    //       v8 = (const char *)&unk_3AB990F;
    //     }
    //     if ( v16 )
    //     {
    //       snprintf(Source, 0x7FFu, "%s%s%s%s: %s", "CRT ", off_3AB9960[v28], v8, v25, v13);
    //     }
    //     else
    //     {
    //       snprintf(Source, 0x7FFu, "%s%s%s%s: %s", (const char *)&unk_3AB9921, off_3AB9960[v28], v8, v25, v13);
    //     }
    //     Source[2047] = 0;
    //     BBSupportTracePrint(dword_3AB98E0[v28], Source);
    //     BBSupportTracePrint(dword_3AB98E0[v28], v24);
    //     if ( v28 == 3 || !v28 && (v16 || !byte_4686D4A) )
    //     {
    //       BBSupportLib::BBSTraceStackDump();
    //       _InterlockedDecrement(&dword_3E2E224);
    //       return 0;
    //     }
    //     else
    //     {
    //       if ( v28 )
    //       {
    //         BBSupportLib::BBSTraceStackDump();
    //       }
    //       if ( BBSupportLib::g_iBBSErrorhandlingMode == 3 )
    //       {
    //         _InterlockedDecrement(&dword_3E2E224);
    //         j__raise(22);
    //         j___exit(3);
    //       }
    //       BBSupportLib::BBSCopyTextToClipboard(Source);
    //       memset(Caption, 0, sizeof(Caption));
    //       memset(v26, 0, sizeof(v26));
    //       BBSupportLib::BBSGetModuleFileName(0, v26, 0x208u);
    //       if ( v26[0] )
    //       {
    //         _wsprintfW(Caption, L"%s%s%s", v26, L" - ", off_3AB98F0[v28]);
    //       }
    //       else
    //       {
    //         _wsprintfW(Caption, L"%s%s%s", v26, &unk_3AB99F4, off_3AB98F0[v28]);
    //       }
    //       v17 = BBSupportLib::g_iBBSDeveloperErrorHandling != 0;
    //       v14 = "(Press Retry to debug the application.)\t\t";
    //       if ( !BBSupportLib::g_iBBSDeveloperErrorHandling )
    //       {
    //         if ( v28 )
    //         {
    //           v10 = "Application will be terminated.\t\t";
    //         }
    //         else
    //         {
    //           v10 = "Press Ok to continue.\t\t\t";
    //         }
    //         v14 = v10;
    //       }
    //       memset(Str, 0, sizeof(Str));
    //       if ( v16 )
    //       {
    //         snprintf(Str, 0xFFFu, "%s\n%s\n", v13, v14);
    //       }
    //       else if ( a2 )
    //       {
    //         snprintf(Str, 0xFFFu, "%s: %s%s%s\n\n%s\n", off_3AB98F0[v28], v13, "\nLocation: ", v25, v14);
    //       }
    //       else
    //       {
    //         snprintf(Str, 0xFFFu, "%s: %s%s%s\n\n%s\n", off_3AB98F0[v28], v13, byte_3AB9922, v25, v14);
    //       }
    //       LastActivePopup = 0;
    //       hWnd = GetActiveWindow();
    //       if ( hWnd )
    //       {
    //         LastActivePopup = GetLastActivePopup(hWnd);
    //         if ( (unsigned __int8)BBSupportLib::BBSIsFullscreenWindow(hWnd) )
    //         {
    //           ShowWindow(hWnd, 6);
    //         }
    //       }
    //       if ( v17 )
    //       {
    //         v7 = 73746;
    //       }
    //       else
    //       {
    //         v7 = 73744;
    //       }
    //       std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v18);
    //       v27 = 0;
    //       std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes((int)v19, Str);
    //       v6 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v19);
    //       v11 = MessageBoxW(LastActivePopup, v6, Caption, v7);
    //       _InterlockedDecrement(&dword_3E2E224);
    //       if ( !v28 )
    //       {
    //         goto LABEL_54;
    //       }
    //       if ( !v17 || v11 == 3 )
    //       {
    //         j__raise(22);
    //         j___exit(3);
    //       }
    //       if ( v11 == 4 )
    //       {
    //         std::wstring::~wstring(v19);
    //         v27 = -1;
    //         std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v18);
    //         return 1;
    //       }
    //       else
    //       {
    // LABEL_54:
    //         std::wstring::~wstring(v19);
    //         v27 = -1;
    //         std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v18);
    //         return 0;
    //       }
    //     }
    //   }
    //   else
    //   {
    //     memset(OutputString, 0, sizeof(OutputString));
    //     _wsprintfA(OutputString, "Second chance %s: File %s, Line %d\n", off_3AB9930[v28], a2, a3);
    //     OutputDebugStringA(OutputString);
    //     _InterlockedDecrement(&dword_3E2E224);
    //     __debugbreak();
    //     return -1;
    //   }
}

// address=[0x2f2df30]
// Decompiled from int BBSupportDbgReportF(int a1, const char *a2, int a3, char *Format, ...)
int __cdecl BBSupportDbgReportF(int a1, char const *a2, unsigned int a3, char const *Format, ...) {
    return 0;
    //
    // char Buffer[3072]; // [esp+4h] [ebp-C04h] BYREF
    // va_list va; // [esp+C20h] [ebp+18h] BYREF
    //
    // va_start(va, Format);
    // if ( !Format )
    // {
    //   return BBSupportDbgReport(a1, a2, a3, 0);
    // }
    // memset(Buffer, 0, sizeof(Buffer));
    // __vcrt_va_start_verify_argument_type<char const *>();
    // j___vsnprintf(Buffer, 0xBFFu, Format, va);
    // return BBSupportDbgReport(a1, a2, a3, Buffer);
}