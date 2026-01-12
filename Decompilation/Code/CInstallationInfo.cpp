#include "CInstallationInfo.h"

// Definitions for class CInstallationInfo

// address=[0x1494e20]
// Decompiled from unsigned int __thiscall CInstallationInfo::GetConfigChecksum(CInstallationInfo *this)
unsigned int  CInstallationInfo::GetConfigChecksum(void) {
  
  unsigned int ConfigFileCRC; // [esp+4h] [ebp-8h]
  wchar_t **i; // [esp+8h] [ebp-4h]

  ConfigFileCRC = 1;
  for ( i = &off_3700880; *i; i += 3 )
  {
    if ( *((_BYTE *)i + 4) )
      ConfigFileCRC = CInstallationInfo::GetConfigFileCRC(*i, ConfigFileCRC);
  }
  return ConfigFileCRC;
}


// address=[0x1494e80]
// Decompiled from int __thiscall CInstallationInfo::GetScriptChecksum(CInstallationInfo *this)
unsigned int  CInstallationInfo::GetScriptChecksum(void) {
  
  return CInstallationInfo::GetFileCRC((wchar_t *)L"Script\\Internal\\StartResources.txt", 1);
}


// address=[0x1494eb0]
// Decompiled from unsigned int __thiscall CInstallationInfo::GetGfxChecksum(CInstallationInfo *this)
unsigned int  CInstallationInfo::GetGfxChecksum(void) {
  
  double v1; // st7
  _BYTE v3[24]; // [esp+8h] [ebp-24h] BYREF
  CInstallationInfo *v4; // [esp+20h] [ebp-Ch]
  unsigned int GfxFileCRC; // [esp+24h] [ebp-8h]
  int *i; // [esp+28h] [ebp-4h]

  v4 = this;
  CPerformanceCounter::CPerformanceCounter((CPerformanceCounter *)v3);
  CPerformanceCounter::Start((CPerformanceCounter *)v3);
  GfxFileCRC = 1;
  for ( i = (int *)&unk_3700A60; *i >= 0; i += 3 )
  {
    if ( *((_BYTE *)i + 4) )
      GfxFileCRC = CInstallationInfo::GetGfxFileCRC(*i, GfxFileCRC);
  }
  CPerformanceCounter::Measure((CPerformanceCounter *)v3);
  v1 = CPerformanceCounter::TimeMs((CPerformanceCounter *)v3);
  BBSupportTracePrintF(0, "GetGfxChecksum(): %.0f ms", v1);
  return GfxFileCRC;
}


// address=[0x1494f40]
// Decompiled from bool __thiscall CInstallationInfo::CheckInstallation(CInstallationInfo *this, int a2)
bool  CInstallationInfo::CheckInstallation(int) {
  
  bool v2; // bl
  bool v3; // bl
  bool v6; // [esp+Fh] [ebp-1h]

  BBSupportTracePrintF(1, "Checking installation...");
  v2 = CInstallationInfo::CheckConfigFiles(a2);
  v3 = CInstallationInfo::CheckGfxFiles(a2) && v2;
  v6 = CInstallationInfo::CheckWithLuaScript(a2) && v3;
  if ( v6 )
    BBSupportTracePrintF(1, "Installation check: %s!", "Ok");
  else
    BBSupportTracePrintF(1, "Installation check: %s!", "Failed");
  CInstallationInfo::CheckTrojanVehicleGfx(this);
  return v6;
}


// address=[0x1494ff0]
// Decompiled from bool __stdcall CInstallationInfo::IsOptionalGameConfigFile(wchar_t *String2)
bool  CInstallationInfo::IsOptionalGameConfigFile(wchar_t const *) {
  
  wchar_t **i; // [esp+14h] [ebp-4h]

  for ( i = &off_3700880; ; i += 3 )
  {
    if ( i == &off_3700880 + 48 )
      j___wassert(L"false", L"main\\InstallationInfo.cpp", 0x271u);
    if ( !j__wcscmp(*i, String2) )
      break;
  }
  return ((unsigned int)i[2] & 0x40000) != 0;
}


// address=[0x1496860]
// Decompiled from CInstallationInfo *__thiscall CInstallationInfo::CInstallationInfo(CInstallationInfo *this)
 CInstallationInfo::CInstallationInfo(void) {
  
  IInstallationInfo::IInstallationInfo(this);
  *(_DWORD *)this = &CInstallationInfo::_vftable_;
  return this;
}


// address=[0x14968b0]
// Decompiled from void __thiscall CInstallationInfo::~CInstallationInfo(CInstallationInfo *this)
 CInstallationInfo::~CInstallationInfo(void) {
  
  IInstallationInfo::~IInstallationInfo(this);
}


// address=[0x1495090]
// Decompiled from char __cdecl CInstallationInfo::GetFileProperties(wchar_t *String, int *a2)
static bool __cdecl CInstallationInfo::GetFileProperties(wchar_t const *,struct SFileProperties &) {
  
  int v3; // [esp+0h] [ebp-98h] BYREF
  int v4; // [esp+10h] [ebp-88h]
  char DoesFileExistInLib; // [esp+15h] [ebp-83h]
  char v7; // [esp+17h] [ebp-81h]
  _DWORD v8[26]; // [esp+18h] [ebp-80h] BYREF
  _DWORD v9[3]; // [esp+80h] [ebp-18h] BYREF
  int v10; // [esp+94h] [ebp-4h]

  v9[2] = &v3;
  j__memset(a2, 0, 8u);
  v7 = 0;
  if ( !String || !*String )
    return v7;
  CFileEx::CFileEx((CFileEx *)v8, 1);
  v10 = 1;
  CFileEx::Open(v9, String, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  v4 = CFileEx::Size(v8);
  *a2 = v4;
  if ( CFileEx::InLibrary((CFileEx *)v8) )
  {
    *((_BYTE *)a2 + 4) = 0;
    *((_BYTE *)a2 + 5) = 1;
  }
  else
  {
    *((_BYTE *)a2 + 4) = 1;
    DoesFileExistInLib = CFileLibrary::DoesFileExistInLib(String);
    *((_BYTE *)a2 + 5) = DoesFileExistInLib;
  }
  v7 = 1;
  v10 = 0;
  CFileEx::Close((CFileEx *)v9, UNUSED_ARG(), UNUSED_ARG());
  v10 = -1;
  CFileEx::~CFileEx(v8);
  return v7;
}


// address=[0x14951f0]
// Decompiled from unsigned int __cdecl CInstallationInfo::GetFileCRC(wchar_t *FileName, unsigned int a2)
static unsigned int __cdecl CInstallationInfo::GetFileCRC(wchar_t const *,unsigned int) {
  
  int v3; // [esp+0h] [ebp-B0h] BYREF
  unsigned int v4; // [esp+10h] [ebp-A0h]
  void *C; // [esp+14h] [ebp-9Ch]
  void *v6; // [esp+18h] [ebp-98h]
  void *v7; // [esp+1Ch] [ebp-94h]
  size_t v8; // [esp+20h] [ebp-90h]
  void *Buffer; // [esp+24h] [ebp-8Ch]
  size_t ElementCount; // [esp+28h] [ebp-88h]
  char v11; // [esp+2Fh] [ebp-81h]
  _DWORD v12[26]; // [esp+30h] [ebp-80h] BYREF
  _DWORD v13[3]; // [esp+98h] [ebp-18h] BYREF
  int v14; // [esp+ACh] [ebp-4h]

  v13[2] = &v3;
  if ( !FileName || !*FileName )
    return a2;
  v11 = 1;
  ElementCount = 0;
  Buffer = 0;
  CFileEx::CFileEx((CFileEx *)v12, 1);
  v14 = 1;
  CFileEx::Open(v13, FileName, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  v8 = CFileEx::Size(v12);
  ElementCount = v8;
  if ( v8 )
  {
    v7 = operator new[](ElementCount + 8);
    v6 = v7;
    Buffer = v7;
    j__memset(v7, 0, ElementCount + 8);
    CFileEx::Read(
      v13,
      Buffer,
      1,
      ElementCount,
      "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h",
      110);
  }
  v14 = 0;
  CFileEx::Close((CFileEx *)v13, UNUSED_ARG(), UNUSED_ARG());
  if ( v11 )
  {
    if ( Buffer )
    {
      a2 = Adler32(Buffer, ElementCount, a2);
      C = Buffer;
      operator delete[](Buffer);
    }
  }
  v4 = a2;
  v14 = -1;
  CFileEx::~CFileEx(v12);
  return v4;
}


// address=[0x14953d0]
// Decompiled from int __cdecl CInstallationInfo::GetConfigFileCRC(wchar_t *String, int a2)
static unsigned int __cdecl CInstallationInfo::GetConfigFileCRC(wchar_t const *,unsigned int) {
  
  wchar_t *v3; // eax
  int FileCRC; // [esp+4h] [ebp-30h]
  int v5[7]; // [esp+8h] [ebp-2Ch] BYREF
  int v6; // [esp+30h] [ebp-4h]

  if ( !String || !*String )
    return a2;
  CGameSettings::GetConfigFilePath((int)v5, String, 1);
  v6 = 0;
  v3 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v5);
  FileCRC = CInstallationInfo::GetFileCRC(v3, a2);
  v6 = -1;
  std::wstring::~wstring(v5);
  return FileCRC;
}


// address=[0x1495480]
// Decompiled from int __cdecl CInstallationInfo::GetGfxFileCRC(int a1, int a2)
static unsigned int __cdecl CInstallationInfo::GetGfxFileCRC(int,unsigned int) {
  
  char Buffer[2]; // [esp+8h] [ebp-404h] BYREF
  __int16 v4; // [esp+406h] [ebp-6h]
  int FileCRC; // [esp+418h] [ebp+Ch]
  int v6; // [esp+418h] [ebp+Ch]
  int v7; // [esp+418h] [ebp+Ch]
  int v8; // [esp+418h] [ebp+Ch]
  int v9; // [esp+418h] [ebp+Ch]

  v4 = 0;
  j___snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.dil", a1);
  FileCRC = CInstallationInfo::GetFileCRC((wchar_t *)Buffer, a2);
  j___snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.gil", a1);
  v6 = CInstallationInfo::GetFileCRC((wchar_t *)Buffer, FileCRC);
  j___snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.jil", a1);
  v7 = CInstallationInfo::GetFileCRC((wchar_t *)Buffer, v6);
  j___snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.pi2", a1);
  v8 = CInstallationInfo::GetFileCRC((wchar_t *)Buffer, v7);
  j___snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.pi4", a1);
  v9 = CInstallationInfo::GetFileCRC((wchar_t *)Buffer, v8);
  j___snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.sil", a1);
  return CInstallationInfo::GetFileCRC((wchar_t *)Buffer, v9);
}


// address=[0x1495620]
// Decompiled from bool __cdecl CInstallationInfo::CheckFile(const wchar_t *a1, int a2)
static bool __cdecl CInstallationInfo::CheckFile(wchar_t const *,int) {
  
  int v3; // [esp+0h] [ebp-10h] BYREF
  unsigned __int8 v4; // [esp+4h] [ebp-Ch]
  unsigned __int8 v5; // [esp+5h] [ebp-Bh]
  BOOL v6; // [esp+8h] [ebp-8h]
  char FileProperties; // [esp+Fh] [ebp-1h]

  FileProperties = 1;
  FileProperties = CInstallationInfo::GetFileProperties((int)a1, &v3);
  if ( (a2 & 0x10000) != 0 )
  {
    if ( FileProperties )
      BBSupportTracePrintF(1, "File should not exist: %s!", (const char *)a1);
    v6 = FileProperties == 0;
    return FileProperties == 0;
  }
  else if ( FileProperties )
  {
    if ( !v3 )
    {
      FileProperties = 0;
      BBSupportTracePrintF(1, "File is empty: %s!", (const char *)a1);
    }
    if ( (v5 & v4) != 0 )
    {
      FileProperties = 0;
      BBSupportTracePrintF(1, "File exists inside and outside of file library: %s!", (const char *)a1);
    }
    if ( (a2 & 0x20000) != 0 && v5 )
    {
      FileProperties = 0;
      BBSupportTracePrintF(1, "File exists inside file library: %s!", (const char *)a1);
    }
  }
  else if ( (a2 & 0x40000) != 0 )
  {
    return 1;
  }
  else
  {
    BBSupportTracePrintF(1, "File not found: %s!", (const char *)a1);
  }
  return FileProperties;
}


// address=[0x1495730]
// Decompiled from bool __cdecl CInstallationInfo::CheckConfigFile(wchar_t *String, int a2)
static bool __cdecl CInstallationInfo::CheckConfigFile(wchar_t const *,int) {
  
  const wchar_t *v2; // eax
  bool v4; // [esp+7h] [ebp-2Dh]
  int v5[7]; // [esp+8h] [ebp-2Ch] BYREF
  int v6; // [esp+30h] [ebp-4h]

  CGameSettings::GetConfigFilePath((int)v5, String, 1);
  v6 = 0;
  v2 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v5);
  v4 = CInstallationInfo::CheckFile(v2, a2);
  v6 = -1;
  std::wstring::~wstring(v5);
  return v4;
}


// address=[0x14957c0]
// Decompiled from bool __cdecl CInstallationInfo::CheckGfxFile(int a1, int a2)
static bool __cdecl CInstallationInfo::CheckGfxFile(int,int) {
  
  char Buffer[2]; // [esp+10h] [ebp-404h] BYREF
  __int16 v4; // [esp+40Eh] [ebp-6h]

  v4 = 0;
  j___snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.gfx", a1);
  return CInstallationInfo::CheckFile((const wchar_t *)Buffer, a2);
}


// address=[0x1495870]
// Decompiled from char __cdecl CInstallationInfo::CheckConfigFiles(int a1)
static bool __cdecl CInstallationInfo::CheckConfigFiles(int) {
  
  wchar_t **i; // [esp+4h] [ebp-8h]
  char v3; // [esp+Bh] [ebp-1h]

  v3 = 1;
  for ( i = &off_3700880; *i; i += 3 )
    v3 &= CInstallationInfo::CheckConfigFile(*i, (unsigned int)i[2] | a1);
  return v3;
}


// address=[0x14958d0]
// Decompiled from char __cdecl CInstallationInfo::CheckGfxFiles(int a1)
static bool __cdecl CInstallationInfo::CheckGfxFiles(int) {
  
  int *i; // [esp+4h] [ebp-8h]
  char v3; // [esp+Bh] [ebp-1h]

  v3 = 1;
  for ( i = (int *)&unk_3700A60; *i >= 0; i += 3 )
    v3 &= CInstallationInfo::CheckGfxFile(*i, i[2] | a1);
  return v3;
}


// address=[0x1495930]
// Decompiled from char *__thiscall CInstallationInfo::CheckTrojanVehicleGfx(CInstallationInfo *this)
void  CInstallationInfo::CheckTrojanVehicleGfx(void) {
  
  char *result; // eax
  int v2; // [esp+10h] [ebp-28h]
  int j; // [esp+14h] [ebp-24h]
  int i; // [esp+18h] [ebp-20h]
  DWORD dwFileAttributes; // [esp+1Ch] [ebp-1Ch]
  int k; // [esp+20h] [ebp-18h]
  int m; // [esp+20h] [ebp-18h]
  char *hFile; // [esp+24h] [ebp-14h]
  DWORD NumberOfBytesRead; // [esp+28h] [ebp-10h] BYREF
  __int16 v10; // [esp+2Ch] [ebp-Ch] BYREF
  _WORD v11[3]; // [esp+30h] [ebp-8h] BYREF
  char v12; // [esp+36h] [ebp-2h]
  unsigned __int8 Buffer; // [esp+37h] [ebp-1h] BYREF

  CInstallationInfo::GetFileCRC((wchar_t *)L"Gfx\\34.gil", 1);
  result = (char *)CInstallationInfo::GetFileCRC((wchar_t *)L"Gfx\\34.gil", 1);
  if ( result != (char *)1304412675 )
    return result;
  dwFileAttributes = GetFileAttributesW(L"Gfx\\34.gfx");
  if ( (dwFileAttributes & 1) != 0 )
    SetFileAttributesW(L"Gfx\\34.gfx", dwFileAttributes ^ 1);
  result = (char *)CreateFileW(L"Gfx\\34.gfx", 0xC0000000, 0, 0, 3u, 0x80u, 0);
  hFile = result;
  if ( !result )
    return result;
  result = (char *)GetFileSize(result, 0);
  if ( result != (_BYTE *)&dword_300000[104443] + 2 )
    return result;
  for ( i = 0; i < 1; ++i )
  {
    for ( j = 0; j < 1; ++j )
    {
      NumberOfBytesRead = 0;
      for ( k = 0; dword_3701170[5 * k]; ++k )
      {
        SetFilePointer(hFile, dword_3701170[5 * k], 0, 0);
        ReadFile(hFile, v11, 2u, &NumberOfBytesRead, 0);
        ReadFile(hFile, &v10, 2u, &NumberOfBytesRead, 0);
        if ( v11[0] != dword_3701170[5 * k + 3] || v10 != dword_3701170[5 * k + 4] )
          return (char *)CloseHandle(hFile);
      }
      v2 = 0;
      SetFilePointer(hFile, 0, 0, 0);
      v12 = 0;
      ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
      if ( !NumberOfBytesRead )
        v12 = 1;
      while ( !v12 )
      {
        if ( Buffer == 161 )
        {
          ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
          if ( NumberOfBytesRead )
          {
            if ( !Buffer )
            {
              ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
              if ( NumberOfBytesRead )
              {
                if ( Buffer == 30 )
                {
                  ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                  if ( NumberOfBytesRead )
                  {
                    if ( !Buffer )
                    {
                      ++v2;
                      ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                      if ( !NumberOfBytesRead )
                        v12 = 1;
                    }
                  }
                  else
                  {
                    v12 = 1;
                  }
                }
              }
              else
              {
                v12 = 1;
              }
            }
          }
          else
          {
            v12 = 1;
          }
        }
        else
        {
          ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
          if ( !NumberOfBytesRead )
            v12 = 1;
        }
      }
      if ( v2 != 96 )
        return (char *)CloseHandle(hFile);
      for ( m = 0; dword_3701170[5 * m]; ++m )
      {
        SetFilePointer(hFile, dword_3701170[5 * m], 0, 0);
        v11[0] = dword_3701170[5 * m + 1];
        v10 = dword_3701170[5 * m + 2];
        WriteFile(hFile, v11, 2u, &NumberOfBytesRead, 0);
        NumberOfBytesRead = 0;
        WriteFile(hFile, &v10, 2u, &NumberOfBytesRead, 0);
      }
      Buffer = 0;
      SetFilePointer(hFile, 0, 0, 0);
      v12 = 0;
      ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
      if ( !NumberOfBytesRead )
        v12 = 1;
      v11[0] = 120;
      v10 = 59;
      while ( !v12 )
      {
        if ( Buffer == 161 )
        {
          ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
          if ( NumberOfBytesRead )
          {
            if ( !Buffer )
            {
              ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
              if ( NumberOfBytesRead )
              {
                if ( Buffer == 30 )
                {
                  ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                  if ( NumberOfBytesRead )
                  {
                    if ( !Buffer )
                    {
                      SetFilePointer(hFile, -4, 0, 1u);
                      NumberOfBytesRead = 0;
                      WriteFile(hFile, v11, 2u, &NumberOfBytesRead, 0);
                      NumberOfBytesRead = 0;
                      WriteFile(hFile, &v10, 2u, &NumberOfBytesRead, 0);
                      ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                      if ( !NumberOfBytesRead )
                        v12 = 1;
                    }
                  }
                  else
                  {
                    v12 = 1;
                  }
                }
              }
              else
              {
                v12 = 1;
              }
            }
          }
          else
          {
            v12 = 1;
          }
        }
        else
        {
          ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
          if ( !NumberOfBytesRead )
            v12 = 1;
        }
      }
    }
  }
  return (char *)CloseHandle(hFile);
}


// address=[0x1495e70]
// Decompiled from char __cdecl CInstallationInfo::CheckWithLuaScript(int a1)
static bool __cdecl CInstallationInfo::CheckWithLuaScript(int) {
  
  void *v2; // [esp+Ch] [ebp-14h] BYREF
  char v3; // [esp+13h] [ebp-Dh]
  int v4; // [esp+1Ch] [ebp-4h]

  CInstallationInfo::m_iLuaCheckFlags = a1;
  CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile(L"Script\\Internal\\CheckInstallation.txt", a1);
  if ( !CInstallationInfo::m_bLuaCheckOk )
    return CInstallationInfo::m_bLuaCheckOk;
  CLua::CLua((CLua *)&v2);
  v4 = 0;
  CLua::ExportGlobalVar("MUST_NOT_EXIST", DOUBLE_65536_0);
  CLua::ExportGlobalVar("NOT_INTERNAL", DOUBLE_131072_0);
  CLua::ExportGlobalVar("OPTIONAL", DOUBLE_262144_0);
  CLua::ExportGlobalVar("PROD_NOT_EXTERNAL", DOUBLE_524288_0);
  CLua::ExportFunction((int)CInstallationInfo::LuaCheckFile, "CheckFile");
  CLua::ExportFunction((int)CInstallationInfo::LuaCheckFiles, "CheckFiles");
  v3 = CLua::ExecuteScript((wchar_t *)L"Script\\Internal\\CheckInstallation.txt");
  if ( !v3 )
    BBSupportTracePrintF(1, "Failed to execute script!");
  CInstallationInfo::m_bLuaCheckOk &= v3;
  v4 = -1;
  CLua::~CLua(&v2);
  return CInstallationInfo::m_bLuaCheckOk;
}


// address=[0x1495fd0]
// Decompiled from int CInstallationInfo::LuaCheckFile()
static void __cdecl CInstallationInfo::LuaCheckFile(void) {
  
  unsigned int v0; // eax
  unsigned int v1; // eax
  char v3; // bl
  const wchar_t *v4; // eax
  int v5; // [esp-4h] [ebp-98h]
  int IntegerZeroIfNoObject; // [esp+8h] [ebp-8Ch]
  char *Str; // [esp+Ch] [ebp-88h]
  char v8[88]; // [esp+10h] [ebp-84h] BYREF
  int v9[7]; // [esp+68h] [ebp-2Ch] BYREF
  int v10; // [esp+90h] [ebp-4h]

  v0 = j__lua_lua2C(1);
  Str = (char *)CInstallationInfo::LuaGetString(v0);
  v1 = j__lua_lua2C(2);
  IntegerZeroIfNoObject = CInstallationInfo::LuaGetIntegerZeroIfNoObject(v1);
  if ( Str && *Str && IntegerZeroIfNoObject >= 0 )
  {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v8);
    v10 = 0;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
      (int)v9,
      Str);
    LOBYTE(v10) = 1;
    v3 = CInstallationInfo::m_bLuaCheckOk;
    v5 = IntegerZeroIfNoObject | CInstallationInfo::m_iLuaCheckFlags;
    v4 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v9);
    CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile(v4, v5) & v3;
    LOBYTE(v10) = 0;
    std::wstring::~wstring(v9);
    v10 = -1;
    return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v8);
  }
  else
  {
    CInstallationInfo::m_bLuaCheckOk = 0;
    return BBSupportTracePrintF(1, "LuaCheckFile(): Invalid parameter!");
  }
}


// address=[0x1496110]
// Decompiled from int CInstallationInfo::LuaCheckFiles()
static void __cdecl CInstallationInfo::LuaCheckFiles(void) {
  
  unsigned int v0; // eax
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  int result; // eax
  char v5; // bl
  const wchar_t *v6; // eax
  int v7; // [esp-4h] [ebp-2A8h]
  int IntegerZeroIfNoObject; // [esp+8h] [ebp-29Ch]
  int v9; // [esp+Ch] [ebp-298h]
  int Integer; // [esp+10h] [ebp-294h]
  char *Format; // [esp+18h] [ebp-28Ch]
  int i; // [esp+1Ch] [ebp-288h]
  char v13[88]; // [esp+20h] [ebp-284h] BYREF
  int v14[7]; // [esp+78h] [ebp-22Ch] BYREF
  char Str[512]; // [esp+94h] [ebp-210h] BYREF
  int v16; // [esp+2A0h] [ebp-4h]

  v0 = j__lua_lua2C(1);
  Format = (char *)CInstallationInfo::LuaGetString(v0);
  v1 = j__lua_lua2C(2);
  Integer = CInstallationInfo::LuaGetInteger(v1);
  v2 = j__lua_lua2C(3);
  v9 = CInstallationInfo::LuaGetInteger(v2);
  v3 = j__lua_lua2C(4);
  IntegerZeroIfNoObject = CInstallationInfo::LuaGetIntegerZeroIfNoObject(v3);
  if ( Format && *Format && Integer >= 0 && v9 >= 0 && IntegerZeroIfNoObject >= 0 )
  {
    Str[511] = 0;
    for ( i = Integer; ; ++i )
    {
      result = i;
      if ( i > v9 )
        break;
      j___snprintf(Str, 0x1FFu, Format, i);
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v13);
      v16 = 0;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
        (int)v14,
        Str);
      LOBYTE(v16) = 1;
      v5 = CInstallationInfo::m_bLuaCheckOk;
      v7 = IntegerZeroIfNoObject | CInstallationInfo::m_iLuaCheckFlags;
      v6 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v14);
      CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile(v6, v7) & v5;
      LOBYTE(v16) = 0;
      std::wstring::~wstring(v14);
      v16 = -1;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v13);
    }
  }
  else
  {
    CInstallationInfo::m_bLuaCheckOk = 0;
    return BBSupportTracePrintF(1, "LuaCheckFiles(): Invalid parameter!");
  }
  return result;
}


// address=[0x1496980]
// Decompiled from int __cdecl CInstallationInfo::LuaGetInteger(unsigned int a1)
static int __cdecl CInstallationInfo::LuaGetInteger(unsigned int) {
  
  if ( j__lua_isnumber(a1) )
    return (int)j__lua_getnumber(a1);
  else
    return -1;
}


// address=[0x14969d0]
// Decompiled from int __cdecl CInstallationInfo::LuaGetIntegerZeroIfNoObject(unsigned int a1)
static int __cdecl CInstallationInfo::LuaGetIntegerZeroIfNoObject(unsigned int) {
  
  if ( a1 )
    return CInstallationInfo::LuaGetInteger(a1);
  else
    return 0;
}


// address=[0x1496a10]
// Decompiled from int __cdecl CInstallationInfo::LuaGetString(unsigned int a1)
static char const * __cdecl CInstallationInfo::LuaGetString(unsigned int) {
  
  if ( j__lua_isstring(a1) )
    return j__lua_getstring(a1);
  else
    return 0;
}


// address=[0x3f456d8]
// [Decompilation failed for static int CInstallationInfo::m_iLuaCheckFlags]

// address=[0x3f456dc]
// [Decompilation failed for static bool CInstallationInfo::m_bLuaCheckOk]

