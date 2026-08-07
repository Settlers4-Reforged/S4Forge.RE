#if FALSE
#include "CInstallationInfo.h"

// Definitions for class CInstallationInfo

// address=[0x1494e20]
// Decompiled from int __thiscall CInstallationInfo::GetConfigChecksum(CInstallationInfo *this)
unsigned int  CInstallationInfo::GetConfigChecksum(void) {
  
  int ConfigFileCRC; // [esp+4h] [ebp-8h]
  SConfigFile *i; // [esp+8h] [ebp-4h]

  ConfigFileCRC = 1;
  for ( i = s_sConfigFiles;
        i->m_sName;
        ++i )
  {
    if ( LOBYTE(i->m_uId) )
    {
      ConfigFileCRC = CInstallationInfo::GetConfigFileCRC((wchar_t *)i->m_sName, ConfigFileCRC);
    }
  }
  return ConfigFileCRC;
}


// address=[0x1494e80]
// Decompiled from unsigned int __thiscall CInstallationInfo::GetScriptChecksum(CInstallationInfo *this)
unsigned int  CInstallationInfo::GetScriptChecksum(void) {
  
  return CInstallationInfo::GetFileCRC((wchar_t *)L"Script\\Internal\\StartResources.txt", 1u);
}


// address=[0x1494eb0]
// Decompiled from unsigned int __thiscall CInstallationInfo::GetGfxChecksum(CInstallationInfo *this)
unsigned int  CInstallationInfo::GetGfxChecksum(void) {
  
  double v1; // st7
  LARGE_INTEGER v3[3]; // [esp+8h] [ebp-24h] BYREF
  unsigned int GfxFileCRC; // [esp+24h] [ebp-8h]
  SGfxFile *i; // [esp+28h] [ebp-4h]

  CPerformanceCounter::CPerformanceCounter((CPerformanceCounter *)v3);
  CPerformanceCounter::Start(v3);
  GfxFileCRC = 1;
  for ( i = s_sGfxFiles;
        i->m_uId >= 0;
        ++i )
  {
    if ( LOBYTE(i->m_uU) )
    {
      GfxFileCRC = CInstallationInfo::GetGfxFileCRC(i->m_uId, GfxFileCRC);
    }
  }
  CPerformanceCounter::Measure(v3);
  v1 = CPerformanceCounter::TimeMs((CPerformanceCounter *)v3);
  BBSupportTracePrintF(0, "GetGfxChecksum(): %.0f ms", v1);
  return GfxFileCRC;
}


// address=[0x1494f40]
// Decompiled from bool __thiscall CInstallationInfo::CheckInstallation(CInstallationInfo *this, int a2)
bool  CInstallationInfo::CheckInstallation(int a2) {
  
  char v2; // bl
  char v3; // bl
  char v6; // [esp+Fh] [ebp-1h]

  BBSupportTracePrintF(1, "Checking installation...");
  v2 = CInstallationInfo::CheckConfigFiles(a2) & 1;
  v3 = CInstallationInfo::CheckGfxFiles(a2) & v2;
  v6 = CInstallationInfo::CheckWithLuaScript(a2) & v3;
  if ( v6 )
  {
    BBSupportTracePrintF(1, "Installation check: %s!", "Ok");
  }
  else
  {
    BBSupportTracePrintF(1, "Installation check: %s!", "Failed");
  }
  CInstallationInfo::CheckTrojanVehicleGfx(this);
  return v6;
}


// address=[0x1494ff0]
// Decompiled from bool __stdcall CInstallationInfo::IsOptionalGameConfigFile(wchar_t *String2)
bool  CInstallationInfo::IsOptionalGameConfigFile(wchar_t const * String2) {
  
  SConfigFile *i; // [esp+14h] [ebp-4h]

  for ( i = s_sConfigFiles;
        ;
        ++i )
  {
    if ( i == &s_sConfigFiles[16] )
    {
      j___wassert(L"false", L"main\\InstallationInfo.cpp", 0x271u);
    }
    if ( !j__wcscmp(i->m_sName, String2) )
    {
      break;
    }
  }
  return (i->m_uFlags & 0x40000) != 0;
}


// address=[0x1496860]
// Decompiled from CInstallationInfo *__thiscall CInstallationInfo::CInstallationInfo(CInstallationInfo *this)
 CInstallationInfo::CInstallationInfo(void) {
  
  IInstallationInfo::IInstallationInfo((IInstallationInfo *)this);
  this->__vftable = (CInstallationInfo_vtbl *)&CInstallationInfo::_vftable_;
  return this;
}


// address=[0x14968b0]
// Decompiled from void __thiscall CInstallationInfo::~CInstallationInfo(CInstallationInfo *this)
 CInstallationInfo::~CInstallationInfo(void) {
  
  IInstallationInfo::~IInstallationInfo(this);
}


// address=[0x1495090]
// Decompiled from char __cdecl CInstallationInfo::GetFileProperties(wchar_t *String, SFileProperties *a2)
bool __cdecl CInstallationInfo::GetFileProperties(wchar_t const * String, struct SFileProperties & a2) {
  
  int v3; // [esp+0h] [ebp-98h] BYREF
  int v4; // [esp+10h] [ebp-88h]
  char DoesFileExistInLib; // [esp+15h] [ebp-83h]
  char v7; // [esp+17h] [ebp-81h]
  CFileEx v8; // [esp+18h] [ebp-80h] BYREF
  int *v9; // [esp+88h] [ebp-10h]
  int v10; // [esp+94h] [ebp-4h]

  v9 = &v3;
  memset(a2, 0, sizeof(SFileProperties));
  v7 = 0;
  if ( !String || !*String )
  {
    return v7;
  }
  CFileEx::CFileEx(&v8, UNUSED_ARG());
  v10 = 1;
  CFileEx::Open(&v8.IFileEx, String, CFile_BINARY|CFile_READ, 0, UNUSED_ARG(), UNUSED_ARG());
  v4 = CFileEx::Size(&v8);
  a2->m_uSize = v4;
  if ( CFileEx::InLibrary(&v8) )
  {
    a2->m_bOutsideLibrary = 0;
    a2->m_bInLib = 1;
  }
  else
  {
    a2->m_bOutsideLibrary = 1;
    DoesFileExistInLib = CFileLibrary::DoesFileExistInLib(String);
    a2->m_bInLib = DoesFileExistInLib;
  }
  v7 = 1;
  v10 = 0;
  CFileEx::Close(&v8.IFileEx, UNUSED_ARG(), UNUSED_ARG());
  v10 = -1;
  CFileEx::~CFileEx(&v8);
  return v7;
}


// address=[0x14951f0]
// Decompiled from unsigned int __cdecl CInstallationInfo::GetFileCRC(wchar_t *FileName, unsigned int a2)
unsigned int __cdecl CInstallationInfo::GetFileCRC(wchar_t const * FileName, unsigned int a2) {
  
  int v3; // [esp+0h] [ebp-B0h] BYREF
  unsigned int v4; // [esp+10h] [ebp-A0h]
  void *C; // [esp+14h] [ebp-9Ch]
  void *v6; // [esp+18h] [ebp-98h]
  void *v7; // [esp+1Ch] [ebp-94h]
  size_t v8; // [esp+20h] [ebp-90h]
  void *Buffer; // [esp+24h] [ebp-8Ch]
  size_t ElementCount; // [esp+28h] [ebp-88h]
  char v11; // [esp+2Fh] [ebp-81h]
  CFileEx v12; // [esp+30h] [ebp-80h] BYREF
  int *v13; // [esp+A0h] [ebp-10h]
  int v14; // [esp+ACh] [ebp-4h]

  v13 = &v3;
  if ( !FileName || !*FileName )
  {
    return a2;
  }
  v11 = 1;
  ElementCount = 0;
  Buffer = 0;
  CFileEx::CFileEx(&v12, UNUSED_ARG());
  v14 = 1;
  CFileEx::Open(&v12.IFileEx, FileName, CFile_BINARY|CFile_READ, 0, UNUSED_ARG(), UNUSED_ARG());
  v8 = CFileEx::Size(&v12);
  ElementCount = v8;
  if ( v8 )
  {
    v7 = operator new[](ElementCount + 8);
    v6 = v7;
    Buffer = v7;
    memset(v7, 0, ElementCount + 8);
    CFileEx::Read(&v12.IFileEx.__vftable, Buffer, 1, ElementCount, UNUSED_ARG(), UNUSED_ARG());
  }
  v14 = 0;
  CFileEx::Close(&v12.IFileEx, UNUSED_ARG(), UNUSED_ARG());
  if ( v11 )
  {
    if ( Buffer )
    {
      a2 = Adler32((unsigned __int8 *)Buffer, ElementCount, a2);
      C = Buffer;
      operator delete[](Buffer);
    }
  }
  v4 = a2;
  v14 = -1;
  CFileEx::~CFileEx(&v12);
  return v4;
}


// address=[0x14953d0]
// Decompiled from unsigned int __cdecl CInstallationInfo::GetConfigFileCRC(wchar_t *String, unsigned int a2)
unsigned int __cdecl CInstallationInfo::GetConfigFileCRC(wchar_t const * String, unsigned int a2) {
  
  wchar_t *v3; // eax
  unsigned int FileCRC; // [esp+4h] [ebp-30h]
  std::wstring ret; // [esp+8h] [ebp-2Ch] BYREF
  int v6; // [esp+30h] [ebp-4h]

  if ( !String || !*String )
  {
    return a2;
  }
  CGameSettings::GetConfigFilePath(&ret, String, 1);
  v6 = 0;
  v3 = std::wstring::c_str(&ret);
  FileCRC = CInstallationInfo::GetFileCRC(v3, a2);
  v6 = -1;
  std::wstring::~wstring(&ret);
  return FileCRC;
}


// address=[0x1495480]
// Decompiled from unsigned int __cdecl CInstallationInfo::GetGfxFileCRC(int a1, unsigned int a2)
unsigned int __cdecl CInstallationInfo::GetGfxFileCRC(int a1, unsigned int a2) {
  
  wchar_t Buffer[511]; // [esp+8h] [ebp-404h] BYREF
  __int16 v4; // [esp+406h] [ebp-6h]
  int FileCRC; // [esp+418h] [ebp+Ch]
  int v6; // [esp+418h] [ebp+Ch]
  int v7; // [esp+418h] [ebp+Ch]
  int v8; // [esp+418h] [ebp+Ch]
  int v9; // [esp+418h] [ebp+Ch]

  v4 = 0;
  snwprintf((char *const)Buffer, 0x1FFu, L"Gfx\\%i.dil", a1);
  FileCRC = CInstallationInfo::GetFileCRC(Buffer, a2);
  snwprintf((char *const)Buffer, 0x1FFu, L"Gfx\\%i.gil", a1);
  v6 = CInstallationInfo::GetFileCRC(Buffer, FileCRC);
  snwprintf((char *const)Buffer, 0x1FFu, L"Gfx\\%i.jil", a1);
  v7 = CInstallationInfo::GetFileCRC(Buffer, v6);
  snwprintf((char *const)Buffer, 0x1FFu, L"Gfx\\%i.pi2", a1);
  v8 = CInstallationInfo::GetFileCRC(Buffer, v7);
  snwprintf((char *const)Buffer, 0x1FFu, L"Gfx\\%i.pi4", a1);
  v9 = CInstallationInfo::GetFileCRC(Buffer, v8);
  snwprintf((char *const)Buffer, 0x1FFu, L"Gfx\\%i.sil", a1);
  return CInstallationInfo::GetFileCRC(Buffer, v9);
}


// address=[0x1495620]
// Decompiled from bool __cdecl CInstallationInfo::CheckFile(wchar_t *a1, int a2)
bool __cdecl CInstallationInfo::CheckFile(wchar_t const * a1, int a2) {
  
  SFileProperties v3; // [esp+0h] [ebp-10h] BYREF
  BOOL v4; // [esp+8h] [ebp-8h]
  char FileProperties; // [esp+Fh] [ebp-1h]

  FileProperties = 1;
  FileProperties = CInstallationInfo::GetFileProperties(a1, &v3);
  if ( (a2 & 0x10000) != 0 )
  {
    if ( FileProperties )
    {
      BBSupportTracePrintF(1, "File should not exist: %s!", (const char *)a1);
    }
    v4 = FileProperties == 0;
    return FileProperties == 0;
  }
  else if ( FileProperties )
  {
    if ( !v3.m_uSize )
    {
      FileProperties = 0;
      BBSupportTracePrintF(1, "File is empty: %s!", (const char *)a1);
    }
    if ( (v3.m_bInLib & v3.m_bOutsideLibrary) != 0 )
    {
      FileProperties = 0;
      BBSupportTracePrintF(1, "File exists inside and outside of file library: %s!", (const char *)a1);
    }
    if ( (a2 & 0x20000) != 0 && v3.m_bInLib )
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
bool __cdecl CInstallationInfo::CheckConfigFile(wchar_t const * String, int a2) {
  
  wchar_t *v2; // eax
  bool v4; // [esp+7h] [ebp-2Dh]
  std::wstring ret; // [esp+8h] [ebp-2Ch] BYREF
  int v6; // [esp+30h] [ebp-4h]

  CGameSettings::GetConfigFilePath(&ret, String, 1);
  v6 = 0;
  v2 = std::wstring::c_str(&ret);
  v4 = CInstallationInfo::CheckFile(v2, a2);
  v6 = -1;
  std::wstring::~wstring(&ret);
  return v4;
}


// address=[0x14957c0]
// Decompiled from bool __cdecl CInstallationInfo::CheckGfxFile(int a1, int a2)
bool __cdecl CInstallationInfo::CheckGfxFile(int a1, int a2) {
  
  char Buffer[2]; // [esp+10h] [ebp-404h] BYREF
  __int16 v4; // [esp+40Eh] [ebp-6h]

  v4 = 0;
  snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.gfx", a1);
  return CInstallationInfo::CheckFile((wchar_t *)Buffer, a2);
}


// address=[0x1495870]
// Decompiled from char __cdecl CInstallationInfo::CheckConfigFiles(int a1)
bool __cdecl CInstallationInfo::CheckConfigFiles(int a1) {
  
  SConfigFile *i; // [esp+4h] [ebp-8h]
  char v3; // [esp+Bh] [ebp-1h]

  v3 = 1;
  for ( i = s_sConfigFiles;
        i->m_sName;
        ++i )
  {
    v3 &= CInstallationInfo::CheckConfigFile((wchar_t *)i->m_sName, i->m_uFlags | a1);
  }
  return v3;
}


// address=[0x14958d0]
// Decompiled from char __cdecl CInstallationInfo::CheckGfxFiles(int a1)
bool __cdecl CInstallationInfo::CheckGfxFiles(int a1) {
  
  SGfxFile *i; // [esp+4h] [ebp-8h]
  char v3; // [esp+Bh] [ebp-1h]

  v3 = 1;
  for ( i = s_sGfxFiles;
        i->m_uId >= 0;
        ++i )
  {
    v3 &= CInstallationInfo::CheckGfxFile(i->m_uId, i->m_uFlags | a1);
  }
  return v3;
}


// address=[0x1495930]
// Decompiled from void __thiscall CInstallationInfo::CheckTrojanVehicleGfx(CInstallationInfo *this)
void  CInstallationInfo::CheckTrojanVehicleGfx(void) {
  
  int v1; // [esp+10h] [ebp-28h]
  int j; // [esp+14h] [ebp-24h]
  int i; // [esp+18h] [ebp-20h]
  DWORD dwFileAttributes; // [esp+1Ch] [ebp-1Ch]
  int k; // [esp+20h] [ebp-18h]
  int m; // [esp+20h] [ebp-18h]
  HANDLE hFile; // [esp+24h] [ebp-14h]
  DWORD NumberOfBytesRead; // [esp+28h] [ebp-10h] BYREF
  __int16 v9; // [esp+2Ch] [ebp-Ch] BYREF
  __int16 v10; // [esp+30h] [ebp-8h] BYREF
  char v11; // [esp+36h] [ebp-2h]
  unsigned __int8 Buffer; // [esp+37h] [ebp-1h] BYREF

  CInstallationInfo::GetFileCRC((wchar_t *)L"Gfx\\34.gil", 1u);
  if ( CInstallationInfo::GetFileCRC((wchar_t *)L"Gfx\\34.gil", 1u) == 0x4DBFC203 )
  {
    dwFileAttributes = GetFileAttributesW(L"Gfx\\34.gfx");
    if ( (dwFileAttributes & 1) != 0 )
    {
      SetFileAttributesW(L"Gfx\\34.gfx", dwFileAttributes ^ 1);
    }
    hFile = CreateFileW(L"Gfx\\34.gfx", 0xC0000000, 0, 0, 3u, 0x80u, 0);
    if ( hFile )
    {
      if ( GetFileSize(hFile, 0) == 0x365FEE )
      {
        for ( i = 0;
              i < 1;
              ++i )
        {
          for ( j = 0;
                j < 1;
                ++j )
          {
            NumberOfBytesRead = 0;
            for ( k = 0;
                  s_cTrojanVehicleGfxCheckpoints[k].m_uAtOffset;
                  ++k )
            {
              SetFilePointer(hFile, s_cTrojanVehicleGfxCheckpoints[k].m_uAtOffset, 0, FILE_BEGIN);
              ReadFile(hFile, &v10, 2u, &NumberOfBytesRead, 0);
              ReadFile(hFile, &v9, 2u, &NumberOfBytesRead, 0);
              if ( v10 != s_cTrojanVehicleGfxCheckpoints[k].m_uExpectedData[2] || v9 != s_cTrojanVehicleGfxCheckpoints[k].m_uExpectedData[3] )
              {
                goto LABEL_61;
              }
            }
            v1 = 0;
            SetFilePointer(hFile, 0, 0, FILE_BEGIN);
            v11 = 0;
            ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
            if ( !NumberOfBytesRead )
            {
              v11 = 1;
            }
            while ( !v11 )
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
                            ++v1;
                            ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                            if ( !NumberOfBytesRead )
                            {
                              v11 = 1;
                            }
                          }
                        }
                        else
                        {
                          v11 = 1;
                        }
                      }
                    }
                    else
                    {
                      v11 = 1;
                    }
                  }
                }
                else
                {
                  v11 = 1;
                }
              }
              else
              {
                ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                if ( !NumberOfBytesRead )
                {
                  v11 = 1;
                }
              }
            }
            if ( v1 != 96 )
            {
              goto LABEL_61;
            }
            for ( m = 0;
                  s_cTrojanVehicleGfxCheckpoints[m].m_uAtOffset;
                  ++m )
            {
              SetFilePointer(hFile, s_cTrojanVehicleGfxCheckpoints[m].m_uAtOffset, 0, FILE_BEGIN);
              v10 = s_cTrojanVehicleGfxCheckpoints[m].m_uExpectedData[0];
              v9 = s_cTrojanVehicleGfxCheckpoints[m].m_uExpectedData[1];
              WriteFile(hFile, &v10, 2u, &NumberOfBytesRead, 0);
              NumberOfBytesRead = 0;
              WriteFile(hFile, &v9, 2u, &NumberOfBytesRead, 0);
            }
            Buffer = 0;
            SetFilePointer(hFile, 0, 0, FILE_BEGIN);
            v11 = 0;
            ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
            if ( !NumberOfBytesRead )
            {
              v11 = 1;
            }
            v10 = 'x';
            v9 = ';';
            while ( !v11 )
            {
              if ( Buffer == 0xA1 )
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
                            SetFilePointer(hFile, -4, 0, FILE_CURRENT);
                            NumberOfBytesRead = 0;
                            WriteFile(hFile, &v10, 2u, &NumberOfBytesRead, 0);
                            NumberOfBytesRead = 0;
                            WriteFile(hFile, &v9, 2u, &NumberOfBytesRead, 0);
                            ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                            if ( !NumberOfBytesRead )
                            {
                              v11 = 1;
                            }
                          }
                        }
                        else
                        {
                          v11 = 1;
                        }
                      }
                    }
                    else
                    {
                      v11 = 1;
                    }
                  }
                }
                else
                {
                  v11 = 1;
                }
              }
              else
              {
                ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                if ( !NumberOfBytesRead )
                {
                  v11 = 1;
                }
              }
            }
          }
        }
LABEL_61:
        CloseHandle(hFile);
      }
    }
  }
}


// address=[0x1495e70]
// Decompiled from char __cdecl CInstallationInfo::CheckWithLuaScript(int a1)
bool __cdecl CInstallationInfo::CheckWithLuaScript(int a1) {
  
  void *v2; // [esp+Ch] [ebp-14h] BYREF
  char v3; // [esp+13h] [ebp-Dh]
  int v4; // [esp+1Ch] [ebp-4h]

  CInstallationInfo::m_iLuaCheckFlags = a1;
  CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile((wchar_t *)L"Script\\Internal\\CheckInstallation.txt", a1);
  if ( !CInstallationInfo::m_bLuaCheckOk )
  {
    return CInstallationInfo::m_bLuaCheckOk;
  }
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
  {
    BBSupportTracePrintF(1, "Failed to execute script!");
  }
  CInstallationInfo::m_bLuaCheckOk &= v3;
  v4 = -1;
  CLua::~CLua(&v2);
  return CInstallationInfo::m_bLuaCheckOk;
}


// address=[0x1495fd0]
// Decompiled from int CInstallationInfo::LuaCheckFile()
void __cdecl CInstallationInfo::LuaCheckFile(void) {
  
  unsigned int v0; // eax
  unsigned int v1; // eax
  char v3; // bl
  wchar_t *v4; // eax
  int v5; // [esp-4h] [ebp-98h]
  int IntegerZeroIfNoObject; // [esp+8h] [ebp-8Ch]
  char *Str; // [esp+Ch] [ebp-88h]
  char v8[88]; // [esp+10h] [ebp-84h] BYREF
  std::wstring v9; // [esp+68h] [ebp-2Ch] BYREF
  int v10; // [esp+90h] [ebp-4h]

  v0 = j__lua_lua2C(1);
  Str = (char *)CInstallationInfo::LuaGetString(v0);
  v1 = j__lua_lua2C(2);
  IntegerZeroIfNoObject = CInstallationInfo::LuaGetIntegerZeroIfNoObject(v1);
  if ( Str && *Str && IntegerZeroIfNoObject >= 0 )
  {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v8);
    v10 = 0;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes((int)&v9, Str);
    LOBYTE(v10) = 1;
    v3 = CInstallationInfo::m_bLuaCheckOk;
    v5 = IntegerZeroIfNoObject | CInstallationInfo::m_iLuaCheckFlags;
    v4 = std::wstring::c_str(&v9);
    CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile(v4, v5) & v3;
    LOBYTE(v10) = 0;
    std::wstring::~wstring(&v9);
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
// Decompiled from void CInstallationInfo::LuaCheckFiles()
void __cdecl CInstallationInfo::LuaCheckFiles(void) {
  
  unsigned int v0; // eax
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  char v4; // bl
  wchar_t *v5; // eax
  int v6; // [esp-4h] [ebp-2A8h]
  int IntegerZeroIfNoObject; // [esp+8h] [ebp-29Ch]
  int v8; // [esp+Ch] [ebp-298h]
  int Integer; // [esp+10h] [ebp-294h]
  char *Format; // [esp+18h] [ebp-28Ch]
  int i; // [esp+1Ch] [ebp-288h]
  char v12[88]; // [esp+20h] [ebp-284h] BYREF
  std::wstring v13; // [esp+78h] [ebp-22Ch] BYREF
  char Str[512]; // [esp+94h] [ebp-210h] BYREF
  int v15; // [esp+2A0h] [ebp-4h]

  v0 = j__lua_lua2C(1);
  Format = (char *)CInstallationInfo::LuaGetString(v0);
  v1 = j__lua_lua2C(2);
  Integer = CInstallationInfo::LuaGetInteger(v1);
  v2 = j__lua_lua2C(3);
  v8 = CInstallationInfo::LuaGetInteger(v2);
  v3 = j__lua_lua2C(4);
  IntegerZeroIfNoObject = CInstallationInfo::LuaGetIntegerZeroIfNoObject(v3);
  if ( Format && *Format && Integer >= 0 && v8 >= 0 && IntegerZeroIfNoObject >= 0 )
  {
    Str[511] = 0;
    for ( i = Integer;
          i <= v8;
          ++i )
    {
      snprintf(Str, 0x1FFu, Format, i);
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v12);
      v15 = 0;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes((int)&v13, Str);
      LOBYTE(v15) = 1;
      v4 = CInstallationInfo::m_bLuaCheckOk;
      v6 = IntegerZeroIfNoObject | CInstallationInfo::m_iLuaCheckFlags;
      v5 = std::wstring::c_str(&v13);
      CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile(v5, v6) & v4;
      LOBYTE(v15) = 0;
      std::wstring::~wstring(&v13);
      v15 = -1;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v12);
    }
  }
  else
  {
    CInstallationInfo::m_bLuaCheckOk = 0;
    BBSupportTracePrintF(1, "LuaCheckFiles(): Invalid parameter!");
  }
}


// address=[0x1496980]
// Decompiled from int __cdecl CInstallationInfo::LuaGetInteger(unsigned int a1)
int __cdecl CInstallationInfo::LuaGetInteger(unsigned int a1) {
  
  if ( j__lua_isnumber(a1) )
  {
    return (int)j__lua_getnumber(a1);
  }
  else
  {
    return -1;
  }
}


// address=[0x14969d0]
// Decompiled from int __cdecl CInstallationInfo::LuaGetIntegerZeroIfNoObject(unsigned int a1)
int __cdecl CInstallationInfo::LuaGetIntegerZeroIfNoObject(unsigned int a1) {
  
  if ( a1 )
  {
    return CInstallationInfo::LuaGetInteger(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x1496a10]
// Decompiled from int __cdecl CInstallationInfo::LuaGetString(unsigned int a1)
char const * __cdecl CInstallationInfo::LuaGetString(unsigned int a1) {
  
  if ( j__lua_isstring(a1) )
  {
    return j__lua_getstring(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x3f456d8]
// [Decompilation failed for static int CInstallationInfo::m_iLuaCheckFlags]

// address=[0x3f456dc]
// [Decompilation failed for static bool CInstallationInfo::m_bLuaCheckOk]

#endif // Already implemented
