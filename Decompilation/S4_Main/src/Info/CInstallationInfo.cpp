#include "CInstallationInfo.h"

#include <assert.h>
#include <codecvt>

#include "Debug/CPerformanceCounter.h"
#include "CBB/CBBSupport.h"
#include "../File/CFileEx.h"
#include "../File/CFileLibrary.h"
#include "Main/CGameSettings.h"
#include "Script/CLua.h"

#include "lua/lua.h"

// Definitions for class CInstallationInfo

struct SConfigFile
{
  const wchar_t *m_sName;
  bool m_bRequired;
  int m_uFlags;
};
struct SGfxFile
{
  int m_uId;
  bool m_bCheck;
  int m_uFlags;
};
struct SGFXFileCheckpoint
{
  int m_uAtOffset;
  int m_uExpectedData[4];
};

SConfigFile s_sConfigFiles[16] = {
    {L"AINames", 1, 0},
    {L"Animals", 1, 0},
    {L"Balancing", 1, 0},
    {L"Magic", 1, 0},
    {L"MainConfig", 1, 0},
    {L"Network", 1, 0},
    {L"SoundFX", 1, 0},
    {L"Soundtracks", 1, 0},
    {L"Transport", 1, 0},
    {L"WarningTypes", 1, 0},
    {L"Web", 1, 0},
    {L"GameSettings", 0, 0x60000},
    {L"MiscData2", 0, 0x60000},
    {L"Video", 0, 0x60000},
    {L"MiscData1", 0, 0x60000},
};

// address=[0x1494e20]
// Decompiled from int __thiscall CInstallationInfo::GetConfigChecksum(CInstallationInfo *this)
unsigned int CInstallationInfo::GetConfigChecksum(void)
{

  int ConfigFileCRC; // [esp+4h] [ebp-8h]
  SConfigFile *i;    // [esp+8h] [ebp-4h]

  ConfigFileCRC = 1;
  for (i = s_sConfigFiles; i->m_sName; ++i)
  {
    if (i->m_bRequired)
      ConfigFileCRC = CInstallationInfo::GetConfigFileCRC((wchar_t *)i->m_sName, ConfigFileCRC);
  }
  return ConfigFileCRC;
}

// address=[0x1494e80]
// Decompiled from unsigned int __thiscall CInstallationInfo::GetScriptChecksum(CInstallationInfo *this)
unsigned int CInstallationInfo::GetScriptChecksum(void)
{

  return CInstallationInfo::GetFileCRC((wchar_t *)L"Script\\Internal\\StartResources.txt", 1u);
}

SGfxFile s_sGfxFiles[21] = {
    {0, 1, 0},
    {3, 1, 0},
    {4, 1, 0},
    {5, 1, 0},
    {6, 1, 0},
    {7, 1, 0},
    {8, 1, 0},
    {9, 1, 0},
    {10, 1, 0},
    {11, 1, 0},
    {12, 1, 0},
    {13, 1, 0},
    {19, 1, 0},
    {20, 1, 0},
    {21, 1, 0},
    {22, 1, 0},
    {23, 1, 0},
    {29, 1, 0},
    {30, 1, 0},
    {31, 1, 0},
    {-1, 0, 0},
};

// address=[0x1494eb0]
// Decompiled from unsigned int __thiscall CInstallationInfo::GetGfxChecksum(CInstallationInfo *this)
unsigned int CInstallationInfo::GetGfxChecksum(void)
{

  double v1;               // st7
  unsigned int GfxFileCRC; // [esp+24h] [ebp-8h]
  SGfxFile *i;             // [esp+28h] [ebp-4h]

  CPerformanceCounter sCounter{};
  sCounter.Start();
  GfxFileCRC = 1;
  for (i = s_sGfxFiles; i->m_uId >= 0; ++i)
  {
    if (i->m_bCheck)
      GfxFileCRC = CInstallationInfo::GetGfxFileCRC(i->m_uId, GfxFileCRC);
  }
  sCounter.Measure();
  v1 = sCounter.TimeMs();
  BBSupportTracePrintF(0, "GetGfxChecksum(): %.0f ms", v1);
  return GfxFileCRC;
}

// address=[0x1494f40]
// Decompiled from bool __thiscall CInstallationInfo::CheckInstallation(CInstallationInfo *this, int a2)
bool CInstallationInfo::CheckInstallation(int a2)
{

  char v2; // bl
  char v3; // bl
  char v6; // [esp+Fh] [ebp-1h]

  BBSupportTracePrintF(1, "Checking installation...");
  v2 = CInstallationInfo::CheckConfigFiles(a2) & 1;
  v3 = CInstallationInfo::CheckGfxFiles(a2) & v2;
  v6 = CInstallationInfo::CheckWithLuaScript(a2) & v3;
  if (v6)
    BBSupportTracePrintF(1, "Installation check: %s!", "Ok");
  else
    BBSupportTracePrintF(1, "Installation check: %s!", "Failed");
  CInstallationInfo::CheckTrojanVehicleGfx();
  return v6;
}

// address=[0x1494ff0]
// Decompiled from bool __stdcall CInstallationInfo::IsOptionalGameConfigFile(wchar_t *String2)
bool CInstallationInfo::IsOptionalGameConfigFile(wchar_t const *String2)
{

  SConfigFile *i; // [esp+14h] [ebp-4h]

  for (i = s_sConfigFiles;; ++i)
  {
    if (i == &s_sConfigFiles[16])
      _wassert(L"false", L"main\\InstallationInfo.cpp", 0x271u);
    if (!wcscmp(i->m_sName, String2))
      break;
  }
  return (i->m_uFlags & 0x40000) != 0;
}

// address=[0x1496860]
// Decompiled from CInstallationInfo *__thiscall CInstallationInfo::CInstallationInfo(CInstallationInfo *this)
CInstallationInfo::CInstallationInfo(void) = default;

// address=[0x14968b0]
// Decompiled from void __thiscall CInstallationInfo::~CInstallationInfo(CInstallationInfo *this)
CInstallationInfo::~CInstallationInfo(void) = default;

// address=[0x1495090]
// Decompiled from char __cdecl CInstallationInfo::GetFileProperties(wchar_t *String, SFileProperties *a2)
bool __cdecl CInstallationInfo::GetFileProperties(wchar_t const *String, struct SFileProperties &a2)
{

  int v3;                  // [esp+0h] [ebp-98h] BYREF
  int v4;                  // [esp+10h] [ebp-88h]
  char DoesFileExistInLib; // [esp+15h] [ebp-83h]
  char v7;                 // [esp+17h] [ebp-81h]
                           // [esp+18h] [ebp-80h] BYREF
  int *v9;                 // [esp+88h] [ebp-10h]
  int v10;                 // [esp+94h] [ebp-4h]

  memset(&a2, 0, sizeof(SFileProperties));
  v7 = 0;
  if (!String || !*String)
    return v7;
  CFileEx v8{};
  v10 = 1;
  v8.Open(String, CFile::CFile_BINARY | CFile::CFile_READ, 0, CFileLog);
  v4 = v8.Size();
  a2.m_uSize = v4;
  if (v8.InLibrary())
  {
    a2.m_bOutsideLibrary = 0;
    a2.m_bInLib = 1;
  }
  else
  {
    a2.m_bOutsideLibrary = 1;
    a2.m_bInLib = g_cFileLibrary->DoesFileExistInLib(String);
  }
  v7 = 1;

  v8.Close(CFileLog);
  return v7;
}

// address=[0x14951f0]
// Decompiled from unsigned int __cdecl CInstallationInfo::GetFileCRC(wchar_t *FileName, unsigned int a2)
unsigned int __cdecl CInstallationInfo::GetFileCRC(wchar_t const *FileName, unsigned int a2)
{

  int v3;              // [esp+0h] [ebp-B0h] BYREF
  unsigned int v4;     // [esp+10h] [ebp-A0h]
  void *C;             // [esp+14h] [ebp-9Ch]
  void *v6;            // [esp+18h] [ebp-98h]
  void *v7;            // [esp+1Ch] [ebp-94h]
  void *Buffer;        // [esp+24h] [ebp-8Ch]
  size_t ElementCount; // [esp+28h] [ebp-88h]
  char v11;            // [esp+2Fh] [ebp-81h]
                       // [esp+30h] [ebp-80h] BYREF
  int *v13;            // [esp+A0h] [ebp-10h]
  int v14;             // [esp+ACh] [ebp-4h]

  v13 = &v3;
  if (!FileName || !*FileName)
    return a2;
  v11 = 1;
  ElementCount = 0;
  Buffer = 0;
  CFileEx v12{};

  v12.Open(FileName, CFile::CFile_BINARY | CFile::CFile_READ, 0, CFileLog);
  ElementCount = v12.Size();
  if (ElementCount)
  {
    v7 = operator new[](ElementCount + 8);
    v6 = v7;
    Buffer = v7;
    memset(v7, 0, ElementCount + 8);
    v12.Read(Buffer, 1, ElementCount, CFileLog);
  }

  v12.Close(CFileLog);
  if (v11)
  {
    if (Buffer)
    {
      a2 = Adler32((unsigned __int8 *)Buffer, ElementCount, a2);
      C = Buffer;
      operator delete[](Buffer);
    }
  }
  v4 = a2;

  return v4;
}

// address=[0x14953d0]
// Decompiled from unsigned int __cdecl CInstallationInfo::GetConfigFileCRC(wchar_t *String, unsigned int a2)
unsigned int __cdecl CInstallationInfo::GetConfigFileCRC(wchar_t const *String, unsigned int a2)
{
  if (!String || !*String)
    return a2;
  return CInstallationInfo::GetFileCRC(CGameSettings::GetConfigFilePath(String, 1).c_str(), a2);
}

// address=[0x1495480]
// Decompiled from unsigned int __cdecl CInstallationInfo::GetGfxFileCRC(int a1, unsigned int a2)
unsigned int __cdecl CInstallationInfo::GetGfxFileCRC(int a1, unsigned int a2)
{

  wchar_t Buffer[511]; // [esp+8h] [ebp-404h] BYREF
  __int16 v4;          // [esp+406h] [ebp-6h]
  int FileCRC;         // [esp+418h] [ebp+Ch]
  int v6;              // [esp+418h] [ebp+Ch]
  int v7;              // [esp+418h] [ebp+Ch]
  int v8;              // [esp+418h] [ebp+Ch]
  int v9;              // [esp+418h] [ebp+Ch]

  v4 = 0;
  _snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.dil", a1);
  FileCRC = CInstallationInfo::GetFileCRC(Buffer, a2);
  _snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.gil", a1);
  FileCRC = CInstallationInfo::GetFileCRC(Buffer, FileCRC);
  _snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.jil", a1);
  FileCRC = CInstallationInfo::GetFileCRC(Buffer, FileCRC);
  _snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.pi2", a1);
  FileCRC = CInstallationInfo::GetFileCRC(Buffer, FileCRC);
  _snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.pi4", a1);
  FileCRC = CInstallationInfo::GetFileCRC(Buffer, FileCRC);
  _snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.sil", a1);
  return CInstallationInfo::GetFileCRC(Buffer, FileCRC);
}

// address=[0x1495620]
// Decompiled from bool __cdecl CInstallationInfo::CheckFile(wchar_t *a1, int a2)
bool __cdecl CInstallationInfo::CheckFile(wchar_t const *a1, int a2)
{

  SFileProperties v3;  // [esp+0h] [ebp-10h] BYREF
  BOOL v4;             // [esp+8h] [ebp-8h]
  char FileProperties; // [esp+Fh] [ebp-1h]

  FileProperties = CInstallationInfo::GetFileProperties(a1, v3);
  if ((a2 & 0x10000) != 0)
  {
    if (FileProperties)
      BBSupportTracePrintF(1, "File should not exist: %s!", (const char *)a1);
    v4 = FileProperties == 0;
    return FileProperties == 0;
  }
  else if (FileProperties)
  {
    if (!v3.m_uSize)
    {
      FileProperties = 0;
      BBSupportTracePrintF(1, "File is empty: %s!", (const char *)a1);
    }
    if ((v3.m_bInLib & v3.m_bOutsideLibrary) != 0)
    {
      FileProperties = 0;
      BBSupportTracePrintF(1, "File exists inside and outside of file library: %s!", (const char *)a1);
    }
    if ((a2 & 0x20000) != 0 && v3.m_bInLib)
    {
      FileProperties = 0;
      BBSupportTracePrintF(1, "File exists inside file library: %s!", (const char *)a1);
    }
  }
  else if ((a2 & 0x40000) != 0)
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
bool __cdecl CInstallationInfo::CheckConfigFile(wchar_t const *String, int a2)
{
  return CInstallationInfo::CheckFile(CGameSettings::GetConfigFilePath(String, 1).c_str(), a2);
}

// address=[0x14957c0]
// Decompiled from bool __cdecl CInstallationInfo::CheckGfxFile(int a1, int a2)
bool __cdecl CInstallationInfo::CheckGfxFile(int a1, int a2)
{

  wchar_t Buffer[511]; // [esp+10h] [ebp-404h] BYREF
  __int16 v4;          // [esp+40Eh] [ebp-6h]

  v4 = 0;
  _snwprintf(Buffer, 0x1FFu, L"Gfx\\%i.gfx", a1);
  return CInstallationInfo::CheckFile(Buffer, a2);
}

// address=[0x1495870]
// Decompiled from char __cdecl CInstallationInfo::CheckConfigFiles(int a1)
bool __cdecl CInstallationInfo::CheckConfigFiles(int a1)
{

  SConfigFile *i; // [esp+4h] [ebp-8h]
  char v3;        // [esp+Bh] [ebp-1h]

  v3 = 1;
  for (i = s_sConfigFiles; i->m_sName; ++i)
    v3 &= CInstallationInfo::CheckConfigFile((wchar_t *)i->m_sName, i->m_uFlags | a1);
  return v3;
}

// address=[0x14958d0]
// Decompiled from char __cdecl CInstallationInfo::CheckGfxFiles(int a1)
bool __cdecl CInstallationInfo::CheckGfxFiles(int a1)
{

  SGfxFile *i; // [esp+4h] [ebp-8h]
  char v3;     // [esp+Bh] [ebp-1h]

  v3 = 1;
  for (i = s_sGfxFiles; i->m_uId >= 0; ++i)
    v3 &= CInstallationInfo::CheckGfxFile(i->m_uId, i->m_uFlags | a1);
  return v3;
}

SGFXFileCheckpoint s_cTrojanVehicleGfxCheckpoints[17] = {
    {0x0C2205, {0x7B, 0x0AA, 0x9F, 0x8E}},
    {0x0C70C3, {0x7B, 0x0AA, 0x9F, 0x8E}},
    {0x0CBC1C, {0x7B, 0x0AA, 0x9F, 0x8E}},
    {0x0D0886, {0x7B, 0x0AA, 0x9F, 0x8E}},
    {0x0D5607, {0x7B, 0x0AA, 0x9F, 0x8E}},
    {0x0D98C1, {0x7B, 0x0AA, 0x9F, 0x8E}},
    {0x0DE502, {0x73, 0x8C, 0x97, 0x70}},
    {0x0E346F, {0x74, 0x7C, 0x98, 0x60}},
    {0x0E7EC2, {0x57, 0x85, 0x7B, 0x69}},
    {0x0EBCDC, {0x57, 0x85, 0x7B, 0x69}},
    {0x0EFFA2, {0x57, 0x85, 0x7B, 0x69}},
    {0x0F4849, {0x70, 0x97, 0x94, 0x7B}},
    {0x0F9684, {0x65, 0x0A7, 0x89, 0x8B}},
    {0x0FE228, {0x58, 0x0AA, 0x7C, 0x8E}},
    {0x102D4B, {0x58, 0x0AA, 0x7C, 0x8E}},
    {0x107636, {0x58, 0x0AA, 0x7C, 0x8E}},
    {0, {0, 0, 0, 0}},
};

// address=[0x1495930]
// Decompiled from void __thiscall CInstallationInfo::CheckTrojanVehicleGfx(CInstallationInfo *this)
void CInstallationInfo::CheckTrojanVehicleGfx(void)
{

  int v1;                  // [esp+10h] [ebp-28h]
  int j;                   // [esp+14h] [ebp-24h]
  int i;                   // [esp+18h] [ebp-20h]
  DWORD dwFileAttributes;  // [esp+1Ch] [ebp-1Ch]
  int k;                   // [esp+20h] [ebp-18h]
  int m;                   // [esp+20h] [ebp-18h]
  HANDLE hFile;            // [esp+24h] [ebp-14h]
  DWORD NumberOfBytesRead; // [esp+28h] [ebp-10h] BYREF
  __int16 v9;              // [esp+2Ch] [ebp-Ch] BYREF
  __int16 v10;             // [esp+30h] [ebp-8h] BYREF
  char v11;                // [esp+36h] [ebp-2h]
  unsigned __int8 Buffer;  // [esp+37h] [ebp-1h] BYREF

  CInstallationInfo::GetFileCRC((wchar_t *)L"Gfx\\34.gil", 1u);
  if (CInstallationInfo::GetFileCRC((wchar_t *)L"Gfx\\34.gil", 1u) == 0x4DBFC203)
  {
    dwFileAttributes = GetFileAttributesW(L"Gfx\\34.gfx");
    if ((dwFileAttributes & 1) != 0)
      SetFileAttributesW(L"Gfx\\34.gfx", dwFileAttributes ^ 1);
    hFile = CreateFileW(L"Gfx\\34.gfx", 0xC0000000, 0, 0, 3u, 0x80u, 0);
    if (hFile)
    {
      if (GetFileSize(hFile, 0) == 3563502)
      {
        for (i = 0; i < 1; ++i)
        {
          for (j = 0; j < 1; ++j)
          {
            NumberOfBytesRead = 0;
            for (k = 0; s_cTrojanVehicleGfxCheckpoints[k].m_uAtOffset; ++k)
            {
              SetFilePointer(hFile, s_cTrojanVehicleGfxCheckpoints[k].m_uAtOffset, 0, FILE_BEGIN);
              ReadFile(hFile, &v10, 2u, &NumberOfBytesRead, 0);
              ReadFile(hFile, &v9, 2u, &NumberOfBytesRead, 0);
              if (v10 != s_cTrojanVehicleGfxCheckpoints[k].m_uExpectedData[2] || v9 != s_cTrojanVehicleGfxCheckpoints[k].m_uExpectedData[3])
              {
                goto LABEL_61;
              }
            }
            v1 = 0;
            SetFilePointer(hFile, 0, 0, FILE_BEGIN);
            v11 = 0;
            ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
            if (!NumberOfBytesRead)
              v11 = 1;
            while (!v11)
            {
              if (Buffer == 161)
              {
                ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                if (NumberOfBytesRead)
                {
                  if (!Buffer)
                  {
                    ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                    if (NumberOfBytesRead)
                    {
                      if (Buffer == 30)
                      {
                        ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                        if (NumberOfBytesRead)
                        {
                          if (!Buffer)
                          {
                            ++v1;
                            ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                            if (!NumberOfBytesRead)
                              v11 = 1;
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
                if (!NumberOfBytesRead)
                  v11 = 1;
              }
            }
            if (v1 != 96)
              goto LABEL_61;
            for (m = 0; s_cTrojanVehicleGfxCheckpoints[m].m_uAtOffset; ++m)
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
            if (!NumberOfBytesRead)
              v11 = 1;
            v10 = 'x';
            v9 = ';';
            while (!v11)
            {
              if (Buffer == 0xA1)
              {
                ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                if (NumberOfBytesRead)
                {
                  if (!Buffer)
                  {
                    ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                    if (NumberOfBytesRead)
                    {
                      if (Buffer == 30)
                      {
                        ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                        if (NumberOfBytesRead)
                        {
                          if (!Buffer)
                          {
                            SetFilePointer(hFile, -4, 0, FILE_CURRENT);
                            NumberOfBytesRead = 0;
                            WriteFile(hFile, &v10, 2u, &NumberOfBytesRead, 0);
                            NumberOfBytesRead = 0;
                            WriteFile(hFile, &v9, 2u, &NumberOfBytesRead, 0);
                            ReadFile(hFile, &Buffer, 1u, &NumberOfBytesRead, 0);
                            if (!NumberOfBytesRead)
                              v11 = 1;
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
                if (!NumberOfBytesRead)
                  v11 = 1;
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
bool __cdecl CInstallationInfo::CheckWithLuaScript(int a1)
{
  char v3; // [esp+13h] [ebp-Dh]
  int v4;  // [esp+1Ch] [ebp-4h]

  CInstallationInfo::m_iLuaCheckFlags = a1;
  CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile(
      (wchar_t *)L"Script\\Internal\\CheckInstallation.txt",
      a1);
  if (!CInstallationInfo::m_bLuaCheckOk)
    return CInstallationInfo::m_bLuaCheckOk;
  CLua v2{};
  v4 = 0;
  v2.ExportGlobalVar("MUST_NOT_EXIST", 65536.0f);
  v2.ExportGlobalVar("NOT_INTERNAL", 131072.0f);
  v2.ExportGlobalVar("OPTIONAL", 262144.0f);
  v2.ExportGlobalVar("PROD_NOT_EXTERNAL", 524288.0f);
  v2.ExportFunction(CInstallationInfo::LuaCheckFile, "CheckFile");
  v2.ExportFunction(CInstallationInfo::LuaCheckFiles, "CheckFiles");
  v3 = v2.ExecuteScript((wchar_t *)L"Script\\Internal\\CheckInstallation.txt");
  if (!v3)
    BBSupportTracePrintF(1, "Failed to execute script!");
  CInstallationInfo::m_bLuaCheckOk &= v3;

  return CInstallationInfo::m_bLuaCheckOk;
}

// address=[0x1495fd0]
// Decompiled from int CInstallationInfo::LuaCheckFile()
void __cdecl CInstallationInfo::LuaCheckFile(void)
{

  unsigned int v0;           // eax
  unsigned int v1;           // eax
  char v3;                   // bl
  wchar_t *v4;               // eax
  int v5;                    // [esp-4h] [ebp-98h]
  int IntegerZeroIfNoObject; // [esp+8h] [ebp-8Ch]
  char *Str;                 // [esp+Ch] [ebp-88h]
  char v8[88];               // [esp+10h] [ebp-84h] BYREF
  std::wstring v9;           // [esp+68h] [ebp-2Ch] BYREF
  int v10;                   // [esp+90h] [ebp-4h]

  v0 = lua_lua2C(1);
  Str = (char *)CInstallationInfo::LuaGetString(v0);
  v1 = lua_lua2C(2);
  IntegerZeroIfNoObject = CInstallationInfo::LuaGetIntegerZeroIfNoObject(v1);
  if (Str && *Str && IntegerZeroIfNoObject >= 0)
  {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv{};
    CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile(conv.from_bytes(Str).c_str(), IntegerZeroIfNoObject | CInstallationInfo::m_iLuaCheckFlags) & CInstallationInfo::m_bLuaCheckOk;
  }
  else
  {
    CInstallationInfo::m_bLuaCheckOk = 0;
    BBSupportTracePrintF(1, "LuaCheckFile(): Invalid parameter!");
  }
}

// address=[0x1496110]
// Decompiled from int CInstallationInfo::LuaCheckFiles()
void __cdecl CInstallationInfo::LuaCheckFiles(void)
{
  unsigned int v0;           // eax
  unsigned int v1;           // eax
  unsigned int v2;           // eax
  unsigned int v3;           // eax
  char v4;                   // bl
  wchar_t *v5;               // eax
  int v6;                    // [esp-4h] [ebp-2A8h]
  int IntegerZeroIfNoObject; // [esp+8h] [ebp-29Ch]
  int v8;                    // [esp+Ch] [ebp-298h]
  int Integer;               // [esp+10h] [ebp-294h]
  char *Format;              // [esp+18h] [ebp-28Ch]
  int i;                     // [esp+1Ch] [ebp-288h]
  char v12[88];              // [esp+20h] [ebp-284h] BYREF
  std::wstring v13;          // [esp+78h] [ebp-22Ch] BYREF
  char Str[512];             // [esp+94h] [ebp-210h] BYREF
  int v15;                   // [esp+2A0h] [ebp-4h]

  v0 = lua_lua2C(1);
  Format = (char *)CInstallationInfo::LuaGetString(v0);
  v1 = lua_lua2C(2);
  Integer = CInstallationInfo::LuaGetInteger(v1);
  v2 = lua_lua2C(3);
  v8 = CInstallationInfo::LuaGetInteger(v2);
  v3 = lua_lua2C(4);
  IntegerZeroIfNoObject = CInstallationInfo::LuaGetIntegerZeroIfNoObject(v3);
  if (Format && *Format && Integer >= 0 && v8 >= 0 && IntegerZeroIfNoObject >= 0)
  {
    Str[511] = 0;
    for (i = Integer; i <= v8; ++i)
    {
      snprintf(Str, 0x1FFu, Format, i);
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv{};
      CInstallationInfo::m_bLuaCheckOk = CInstallationInfo::CheckFile(conv.from_bytes(Str).c_str(), IntegerZeroIfNoObject | CInstallationInfo::m_iLuaCheckFlags) & CInstallationInfo::m_bLuaCheckOk;
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
int __cdecl CInstallationInfo::LuaGetInteger(unsigned int a1)
{

  if (lua_isnumber(a1))
    return (int)lua_getnumber(a1);
  else
    return -1;
}

// address=[0x14969d0]
// Decompiled from int __cdecl CInstallationInfo::LuaGetIntegerZeroIfNoObject(unsigned int a1)
int __cdecl CInstallationInfo::LuaGetIntegerZeroIfNoObject(unsigned int a1)
{

  if (a1)
    return CInstallationInfo::LuaGetInteger(a1);
  else
    return 0;
}

// address=[0x1496a10]
// Decompiled from int __cdecl CInstallationInfo::LuaGetString(unsigned int a1)
char const *__cdecl CInstallationInfo::LuaGetString(unsigned int a1)
{

  if (lua_isstring(a1))
    return lua_getstring(a1);
  else
    return 0;
}

// address=[0x3f456d8]
// [Decompilation failed for static int CInstallationInfo::m_iLuaCheckFlags]

// address=[0x3f456dc]
// [Decompilation failed for static bool CInstallationInfo::m_bLuaCheckOk]
