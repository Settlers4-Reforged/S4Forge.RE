#include "CCDDrive.h"

// Definitions for class CCDDrive

// address=[0x147e9f0]
// Decompiled from CCDDrive *__thiscall CCDDrive::CCDDrive(CCDDrive *this)
 CCDDrive::CCDDrive(void) {
  
  ICDDrive::ICDDrive(this);
  *(_DWORD *)this = &CCDDrive::_vftable_;
  *((_DWORD *)this + 1) = 0;
  j__memset((char *)this + 8, 0, 9u);
  return this;
}


// address=[0x147eb30]
// Decompiled from int __thiscall CCDDrive::GetCDType(CCDDrive *this, char a2)
enum T_S4_CDROM_TYPE  CCDDrive::GetCDType(char) {
  
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
// Decompiled from char __thiscall CCDDrive::GetCDDrive(_BYTE *this, int a2)
char  CCDDrive::GetCDDrive(enum T_S4_CDROM_TYPE) {
  
  int v3; // eax
  int v4; // eax
  char v6; // [esp+5h] [ebp-3h]
  char v7; // [esp+6h] [ebp-2h]
  char i; // [esp+7h] [ebp-1h]

  if ( a2 <= 0 || a2 >= 9 )
    return 0;
  v7 = 0;
  v6 = this[a2 + 8];
  v3 = (**(int (__thiscall ***)(void *, _DWORD))this)(this, (unsigned __int8)v6);
  if ( (unsigned __int8)CCDDrive::AreCDTypesMatching(v3) )
  {
    v7 = v6;
  }
  else
  {
    for ( i = 65; i <= 90; ++i )
    {
      if ( i != v6 )
      {
        v4 = (**(int (__thiscall ***)(void *, _DWORD))this)(this, (unsigned __int8)i);
        if ( (unsigned __int8)CCDDrive::AreCDTypesMatching(v4) )
        {
          v7 = i;
          break;
        }
      }
    }
  }
  this[a2 + 8] = v7;
  return v7;
}


// address=[0x147ed00]
// Decompiled from char __thiscall CCDDrive::GetCDPath(void *this, void *a2, LPCWSTR lpFileName, int a4)
bool  CCDDrive::GetCDPath(std::wstring &,wchar_t const *,int) {
  
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
    lpFileName = (LPCWSTR)&unk_36BB364;
  v9 = 0;
  if ( (a4 & 1) != 0 && (unsigned __int8)CCDDrive::FindFile(lpFileName) )
    v9 = 64;
  if ( !v9 )
  {
    if ( (a4 & 0x400000) != 0 )
    {
      j__memset(Source, 0, sizeof(Source));
      j__memset(v12, 0, sizeof(v12));
      for ( i = 1; i < 9; ++i )
      {
        v8 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 4))(this, i);
        if ( v8 )
        {
          if ( !v12[v8] )
          {
            v12[v8] = 1;
            _wsprintfW(Source, L"%c:\\%s\\%s", v8, L"S4", lpFileName);
            BBSupportTracePrint(1, Source);
            if ( (unsigned __int8)CCDDrive::FindFile(Source) )
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
      v9 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 4))(this, 1);
    }
    else
    {
      for ( j = 1; j < 9; ++j )
      {
        if ( (a4 & (1 << j)) != 0 )
        {
          v9 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 4))(this, j);
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
static bool __cdecl CCDDrive::FindFile(wchar_t const *) {
  
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
// Decompiled from UINT __thiscall CCDDrive::GetDriveTypeA(CCDDrive *this, CHAR a2)
unsigned int  CCDDrive::GetDriveTypeA(char) {
  
  CHAR RootPathName[4]; // [esp+8h] [ebp-Ch] BYREF
  int v4; // [esp+Ch] [ebp-8h]

  if ( !*((_DWORD *)this + 1) )
    *((_DWORD *)this + 1) = CCDDrive::DriveTypeExCheck(this);
  *(_DWORD *)RootPathName = (char *)&dword_589680[59632] + 3;
  v4 = 0;
  RootPathName[0] = a2;
  return GetDriveTypeA(RootPathName);
}


// address=[0x147f1f0]
// Decompiled from bool __cdecl CCDDrive::AreCDTypesMatching(int a1, int a2)
static bool __cdecl CCDDrive::AreCDTypesMatching(enum T_S4_CDROM_TYPE,enum T_S4_CDROM_TYPE) {
  
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


