#if FALSE
#include "CCDDrive.h"

// Definitions for class CCDDrive

// address=[0x147e9f0]
// Decompiled from CCDDrive *__thiscall CCDDrive::CCDDrive(CCDDrive *this)
 CCDDrive::CCDDrive(void) {
  
  ICDDrive::ICDDrive((ICDDrive *)this);
  this->__vftable = (CCDDrive_vtbl *)&CCDDrive::_vftable_;
  this->m_uDriveType = 0;
  memset(this->m_aU2, 0, sizeof(this->m_aU2));
  return this;
}


// address=[0x147eb30]
// Decompiled from int __thiscall CCDDrive::GetCDType(CCDDrive *this, CHAR a2)
enum T_S4_CDROM_TYPE  CCDDrive::GetCDType(char a2) {
  
  int v3; // [esp+8h] [ebp-80Ch]
  int i; // [esp+Ch] [ebp-808h]
  WCHAR FileName[1024]; // [esp+10h] [ebp-804h] BYREF

  if ( a2 >= 97 && a2 <= 122 )
    a2 -= 32;
  if ( a2 >= 65 && a2 <= 90 && CCDDrive::GetDriveTypeA(this, a2) == 5 )
  {
    for ( i = 0; i < 9; ++i )
    {
      v3 = dword_36BB280[i];
      if ( v3 )
      {
        _wsprintfW(FileName, L"%c:\\%s", a2, v3);
        if ( (unsigned __int8)CCDDrive::FindFile(FileName) )
          return i;
      }
    }
  }
  return 0;
}


// address=[0x147ec40]
// Decompiled from char __thiscall CCDDrive::GetCDDrive(CCDDrive *this, int a2)
char  CCDDrive::GetCDDrive(enum T_S4_CDROM_TYPE a2) {
  
  int v3; // eax
  int v4; // eax
  BYTE v6; // [esp+5h] [ebp-3h]
  char v7; // [esp+6h] [ebp-2h]
  char i; // [esp+7h] [ebp-1h]

  if ( a2 <= 0 || a2 >= 9 )
    return 0;
  v7 = 0;
  v6 = this->m_aU2[a2];
  v3 = ((int (__thiscall *)(CCDDrive *, _DWORD))this->GetCDType)(this, v6);
  if ( CCDDrive::AreCDTypesMatching(v3, a2) )
  {
    v7 = v6;
  }
  else
  {
    for ( i = 65; i <= 90; ++i )
    {
      if ( i != (char)v6 )
      {
        v4 = ((int (__thiscall *)(CCDDrive *, _DWORD))this->GetCDType)(this, (unsigned __int8)i);
        if ( CCDDrive::AreCDTypesMatching(v4, a2) )
        {
          v7 = i;
          break;
        }
      }
    }
  }
  this->m_aU2[a2] = v7;
  return v7;
}


// address=[0x147ed00]
// Decompiled from bool __thiscall CCDDrive::GetCDPath(CCDDrive *this, void *a2, LPCWSTR lpFileName, int a4)
bool  CCDDrive::GetCDPath(std::wstring & a2, wchar_t const * lpFileName, int a4) {
  
  int i; // [esp+0h] [ebp-1114h]
  int j; // [esp+4h] [ebp-1110h]
  char v8; // [esp+Eh] [ebp-1106h]
  char v9; // [esp+Fh] [ebp-1105h]
  WCHAR Source[1024]; // [esp+10h] [ebp-1104h] BYREF
  WCHAR String[1024]; // [esp+810h] [ebp-904h] BYREF
  _BYTE v12[256]; // [esp+1010h] [ebp-104h] BYREF

  if ( (a4 & 0x100000) != 0 )
    a4 |= 1u;
  if ( (a4 & 0x200000) != 0 )
    a4 |= 0x10000u;
  if ( !lpFileName )
    lpFileName = (LPCWSTR)&word_36BB364;
  v9 = 0;
  if ( (a4 & 1) != 0 && CCDDrive::FindFile(lpFileName) )
    v9 = 64;
  if ( !v9 )
  {
    if ( (a4 & 0x400000) != 0 )
    {
      memset(Source, 0, sizeof(Source));
      memset(v12, 0, sizeof(v12));
      for ( i = 1; i < 9; ++i )
      {
        v8 = this->GetCDDrive(this, i);
        if ( v8 )
        {
          if ( !v12[v8] )
          {
            v12[v8] = 1;
            _wsprintfW(Source, L"%c:\\%s\\%s", v8, L"S4", lpFileName);
            BBSupportTracePrint(1, Source);
            if ( CCDDrive::FindFile(Source) )
            {
              v9 = v8;
              break;
            }
          }
        }
      }
    }
    else if ( (a4 & 2) != 0 )
    {
      v9 = this->GetCDDrive(this, 1);
    }
    else
    {
      for ( j = 1; j < 9; ++j )
      {
        if ( (a4 & (1 << j)) != 0 )
        {
          v9 = this->GetCDDrive(this, j);
          if ( v9 )
            break;
        }
      }
    }
  }
  if ( !v9 && (a4 & 0x10000) != 0 )
    v9 = 64;
  if ( v9 )
  {
    if ( v9 == 64 )
    {
      if ( (a4 & 0x20000) != 0 )
        _wsprintfW(String, L".\\");
      else
        _wsprintfW(String, L".\\%s", lpFileName);
    }
    else if ( (a4 & 0x20000) != 0 )
    {
      _wsprintfW(String, L"%c:\\%s\\", v9, L"S4");
    }
    else
    {
      _wsprintfW(String, L"%c:\\%s\\%s", v9, L"S4", lpFileName);
    }
    BBSupportTracePrint(1, String);
    std::wstring::operator=(a2, String);
    return 1;
  }
  else
  {
    std::wstring::operator=(a2, (wchar_t *)&word_36BB37C);
    return 0;
  }
}


// address=[0x147ea30]
// Decompiled from char __cdecl CCDDrive::FindFile(LPCWSTR lpFileName)
bool __cdecl CCDDrive::FindFile(wchar_t const * lpFileName) {
  
  HANDLE hFindFile; // [esp+0h] [ebp-258h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+4h] [ebp-254h] BYREF

  if ( !lpFileName || !*lpFileName )
    return 0;
  hFindFile = FindFirstFileW(lpFileName, &FindFileData);
  if ( hFindFile == (HANDLE)-1 )
    return 0;
  FindClose(hFindFile);
  return 1;
}


// address=[0x147eab0]
// Decompiled from UINT __thiscall CCDDrive::GetDriveTypeA(CCDDrive *this, CHAR _cDrive)
unsigned int  CCDDrive::GetDriveTypeA(char _cDrive) {
  
  CHAR RootPathName[4]; // [esp+8h] [ebp-Ch] BYREF
  int v4; // [esp+Ch] [ebp-8h]

  if ( !this->m_uDriveType )
    this->m_uDriveType = CCDDrive::DriveTypeExCheck(this);
  strcpy(RootPathName, "C:\\");
  v4 = 0;
  RootPathName[0] = _cDrive;
  return GetDriveTypeA(RootPathName);
}


// address=[0x147f1f0]
// Decompiled from bool __cdecl CCDDrive::AreCDTypesMatching(int a1, int a2)
bool __cdecl CCDDrive::AreCDTypesMatching(enum T_S4_CDROM_TYPE a1, enum T_S4_CDROM_TYPE a2) {
  
  bool v4; // [esp+6h] [ebp-2h]
  bool v5; // [esp+7h] [ebp-1h]

  v5 = a1 == 2 || a1 == 3 || a1 == 4;
  v4 = a2 == 2 || a2 == 3 || a2 == 4;
  return a1
      && a2
      && (a1 == a2
       || a1 == 1
       || a2 == 1
       || a1 == 5 && v4
       || a2 == 5 && v5
       || a1 == 7 && (v4 || a2 == 6)
       || a2 == 7 && (v5 || a1 == 6));
}


// address=[0x147eb20]
// Decompiled from int __thiscall CCDDrive::DriveTypeExCheck(CCDDrive *this)
int  CCDDrive::DriveTypeExCheck(void) {
  
  return -1;
}


#endif // Already implemented
