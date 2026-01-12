#include "CGrabber.h"

// Definitions for class CGrabber

// address=[0x14944f0]
// Decompiled from void __cdecl CGrabber::DoGrab(char a1)
static void __cdecl CGrabber::DoGrab(std::wstring) {
  
  const WCHAR *v1; // eax
  int v2; // [esp+18h] [ebp-D8h]
  int v3; // [esp+1Ch] [ebp-D4h]
  void *UserDirectoryPath; // [esp+20h] [ebp-D0h]
  DWORD nNumberOfBytesToWrite; // [esp+28h] [ebp-C8h]
  int v6; // [esp+2Ch] [ebp-C4h] BYREF
  int v7; // [esp+30h] [ebp-C0h] BYREF
  LPCVOID lpBuffer; // [esp+34h] [ebp-BCh]
  DWORD NumberOfBytesWritten; // [esp+38h] [ebp-B8h] BYREF
  HANDLE hFile; // [esp+3Ch] [ebp-B4h]
  int v11[11]; // [esp+40h] [ebp-B0h] BYREF
  _BYTE v12[28]; // [esp+6Ch] [ebp-84h] BYREF
  _BYTE v13[28]; // [esp+88h] [ebp-68h] BYREF
  int v14[7]; // [esp+A4h] [ebp-4Ch] BYREF
  __int16 Buffer; // [esp+C0h] [ebp-30h] BYREF
  DWORD v16; // [esp+C2h] [ebp-2Eh]
  int v17; // [esp+CAh] [ebp-26h]
  _WORD v18[7]; // [esp+D0h] [ebp-20h] BYREF
  int v19; // [esp+ECh] [ebp-4h]

  v19 = 0;
  if ( (unsigned __int8)std::wstring::empty(&a1) )
  {
    UserDirectoryPath = FilePaths::GetUserDirectoryPath(v13);
    LOBYTE(v19) = 1;
    v3 = std::operator+<wchar_t>((int)v14, (int)UserDirectoryPath, (wchar_t *)L"Grab\\frame%6d.bmp");
    std::wstring::operator=(v3);
    std::wstring::~wstring(v14);
    LOBYTE(v19) = 0;
    std::wstring::~wstring(v13);
  }
  v2 = sub_1494C50(v12, &a1);
  std::wstring::operator=(v2);
  std::wstring::~wstring(v12);
  FilePaths::EnsurePathExists(&a1);
  j__memset(v18, 0, sizeof(v18));
  j__memset(v11, 0, sizeof(v11));
  lpBuffer = (LPCVOID)CGrabber::GetScreenBits(0, (int)v11, (int)&v6, (int)&v7, 16, 0);
  v18[0] = 19778;
  *(_DWORD *)&v18[1] = v7 * 2 * v6 + 54;
  v18[3] = 0;
  v18[4] = 0;
  *(_DWORD *)&v18[5] = 54;
  v1 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)&a1);
  hFile = CreateFileW(v1, 0x40000000u, 0, 0, 2u, 0x80u, 0);
  nNumberOfBytesToWrite = sub_1494AB0(v6, v7, 16);
  v17 = 54;
  v16 = nNumberOfBytesToWrite + 54;
  Buffer = 19778;
  NumberOfBytesWritten = 0;
  WriteFile(hFile, &Buffer, 0xEu, &NumberOfBytesWritten, 0);
  WriteFile(hFile, v11, 0x28u, &NumberOfBytesWritten, 0);
  WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0);
  CloseHandle(hFile);
  if ( lpBuffer )
    operator delete[]((void *)lpBuffer);
  v19 = -1;
  std::wstring::~wstring(&a1);
}


// address=[0x14947b0]
// Decompiled from LPVOID __cdecl CGrabber::GetScreenBits(LPVOID lpvBits, struct tagBITMAPINFO *a2, LONG *a3, UINT *a4, int a5, char a6)
static void * __cdecl CGrabber::GetScreenBits(void *,void *,int *,int *,int,bool) {
  
  _BYTE pv[4]; // [esp+0h] [ebp-94h] BYREF
  LONG v8; // [esp+4h] [ebp-90h]
  UINT v9; // [esp+8h] [ebp-8Ch]
  DWORD LastError; // [esp+18h] [ebp-7Ch]
  void *C; // [esp+1Ch] [ebp-78h]
  void *v12; // [esp+20h] [ebp-74h]
  size_t Size; // [esp+24h] [ebp-70h]
  UINT v14; // [esp+28h] [ebp-6Ch]
  LONG v15; // [esp+2Ch] [ebp-68h]
  struct tagBITMAPINFO *v16; // [esp+30h] [ebp-64h]
  int v17; // [esp+34h] [ebp-60h]
  int cy; // [esp+38h] [ebp-5Ch]
  HGDIOBJ v19; // [esp+3Ch] [ebp-58h]
  UINT cLines; // [esp+40h] [ebp-54h]
  HGDIOBJ h; // [esp+44h] [ebp-50h]
  HDC hdc; // [esp+48h] [ebp-4Ch]
  HDC CompatibleDC; // [esp+4Ch] [ebp-48h]
  LPBITMAPINFO lpbmi; // [esp+50h] [ebp-44h]
  char v25; // [esp+54h] [ebp-40h] BYREF
  struct tagRECT Rect; // [esp+80h] [ebp-14h] BYREF

  v16 = a2;
  hdc = GetDC(g_hWnd);
  if ( !hdc )
    return 0;
  GetClientRect(g_hWnd, &Rect);
  v17 = Rect.right - Rect.left;
  cy = Rect.bottom - Rect.top;
  CompatibleDC = CreateCompatibleDC(hdc);
  if ( !CompatibleDC )
    return 0;
  h = CreateCompatibleBitmap(hdc, v17, cy);
  if ( h )
  {
    v19 = SelectObject(CompatibleDC, h);
    if ( BitBlt(CompatibleDC, 0, 0, v17, cy, hdc, 0, 0, (DWORD)&dword_C20408[163590]) )
    {
      GetObjectA(h, 24, pv);
      v15 = v8;
      cLines = v9;
      if ( a3 )
        *a3 = v15;
      if ( a4 )
        *a4 = cLines;
      Size = sub_1494AB0(v8, v9, a5);
      if ( !lpvBits )
      {
        v12 = operator new[](Size);
        lpvBits = v12;
      }
      if ( v16 )
        lpbmi = v16;
      else
        lpbmi = (LPBITMAPINFO)&v25;
      j__memset(lpbmi, 0, sizeof(struct tagBITMAPINFO));
      lpbmi->bmiHeader.biSize = 40;
      lpbmi->bmiHeader.biWidth = v15;
      if ( a6 )
        v14 = -cLines;
      else
        v14 = cLines;
      lpbmi->bmiHeader.biHeight = v14;
      lpbmi->bmiHeader.biPlanes = 1;
      lpbmi->bmiHeader.biBitCount = a5;
      lpbmi->bmiHeader.biCompression = 0;
      lpbmi->bmiHeader.biSizeImage = 0;
      lpbmi->bmiHeader.biXPelsPerMeter = 0;
      lpbmi->bmiHeader.biYPelsPerMeter = 0;
      lpbmi->bmiHeader.biClrUsed = 0;
      lpbmi->bmiHeader.biClrImportant = 0;
      if ( !lpvBits || GetDIBits(hdc, (HBITMAP)h, 0, cLines, lpvBits, lpbmi, 0) )
      {
        SelectObject(CompatibleDC, v19);
        ReleaseDC(g_hWnd, hdc);
        DeleteDC(CompatibleDC);
        DeleteObject(h);
        return lpvBits;
      }
      else
      {
        LastError = GetLastError();
        SelectObject(CompatibleDC, v19);
        ReleaseDC(g_hWnd, hdc);
        DeleteDC(CompatibleDC);
        DeleteObject(h);
        C = lpvBits;
        operator delete[](lpvBits);
        return 0;
      }
    }
    else
    {
      SelectObject(CompatibleDC, v19);
      ReleaseDC(g_hWnd, hdc);
      DeleteDC(CompatibleDC);
      DeleteObject(h);
      return 0;
    }
  }
  else
  {
    DeleteDC(CompatibleDC);
    return 0;
  }
}


