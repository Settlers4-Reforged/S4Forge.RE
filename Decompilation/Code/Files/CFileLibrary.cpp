#include "CFileLibrary.h"

// Definitions for class CFileLibrary

// address=[0x2f099d0]
// Decompiled from int __stdcall CFileLibrary::FileSize(wchar_t *String)
unsigned int  CFileLibrary::FileSize(wchar_t const *) {
  
  int Directory; // [esp+0h] [ebp-420h]
  int File; // [esp+8h] [ebp-418h]
  wchar_t String1[260]; // [esp+Ch] [ebp-414h] BYREF
  wchar_t Destination[260]; // [esp+214h] [ebp-20Ch] BYREF

  if ( (unsigned __int8)CFileLibrary::pCutPathAndFilename(String, Destination, String1) )
  {
    File = 0;
    Directory = CFileLibrary::pFindDirectory(Destination);
    if ( Directory )
      File = CFileLibrary::pFindFile(String1, Directory);
    if ( File && *(__int16 *)(File + 20) != -4 )
    {
      if ( (*(_WORD *)(File + 4) & 1) != 0 )
        return *(_DWORD *)(File + 16);
      else
        return *(_DWORD *)(File + 12);
    }
    else
    {
      BBSupportTracePrintF(3, "CFileLibrary::FileSize\t:\tFailed to get find file %s ", (const char *)String);
      return -1;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::FileSize\t:\tFailed to get file handle, %s ", (const char *)String);
    return -1;
  }
}


// address=[0x2f09ae0]
// Decompiled from int __thiscall CFileLibrary::FileSize(CFileLibrary *this, unsigned int a2)
unsigned int  CFileLibrary::FileSize(unsigned int) {
  
  struct FLIntHandleStruct *IntHandlePtr; // [esp+4h] [ebp-4h]

  IntHandlePtr = CFileLibrary::pGetIntHandlePtr(this, a2);
  if ( IntHandlePtr )
  {
    if ( (*(_WORD *)(*((_DWORD *)IntHandlePtr + 5) + 4) & 1) != 0 )
      return *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 16);
    else
      return *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 12);
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::FileSize\t:\tFailed to get file handle");
    return -1;
  }
}


// address=[0x2f09b40]
// Decompiled from CFileLibrary *__thiscall CFileLibrary::UnmapFile(CFileLibrary *this, unsigned int a2)
void  CFileLibrary::UnmapFile(void *) {
  
  CFileLibrary *result; // eax
  unsigned int v3; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = (CFileLibrary *)i;
    if ( i >= *((_DWORD *)this + 10) )
      break;
    v3 = *(_DWORD *)(*((_DWORD *)this + 116) + 24 * i + 8);
    if ( a2 >= v3
      && a2 < *(_DWORD *)(*((_DWORD *)this + 116) + 24 * i + 20) + v3
      && !--*(_DWORD *)(*((_DWORD *)this + 116) + 24 * i + 16) )
    {
      UnmapViewOfFile(*(LPCVOID *)(*((_DWORD *)this + 116) + 24 * i + 8));
      *(_DWORD *)(*((_DWORD *)this + 116) + 24 * i + 8) = 0;
      CloseHandle(*(HANDLE *)(*((_DWORD *)this + 116) + 24 * i + 12));
      result = this;
      *(_DWORD *)(*((_DWORD *)this + 116) + 24 * i + 12) = 0;
      return result;
    }
  }
  return result;
}


// address=[0x2f09c70]
// Decompiled from bool __stdcall CFileLibrary::DoesFileExistInLib(wchar_t *String)
bool  CFileLibrary::DoesFileExistInLib(wchar_t const *) {
  
  int Directory; // [esp+0h] [ebp-420h]
  int File; // [esp+4h] [ebp-41Ch]
  wchar_t String1[260]; // [esp+Ch] [ebp-414h] BYREF
  wchar_t Destination[260]; // [esp+214h] [ebp-20Ch] BYREF

  if ( !(unsigned __int8)CFileLibrary::pCutPathAndFilename(String, Destination, String1) )
    return 0;
  File = 0;
  Directory = CFileLibrary::pFindDirectory(Destination);
  if ( Directory )
    File = CFileLibrary::pFindFile(String1, Directory);
  return File && *(__int16 *)(File + 20) != -4;
}


// address=[0x2f09d30]
// Decompiled from int __thiscall CFileLibrary::MapFile(CFileLibrary *this, unsigned int a2)
void *  CFileLibrary::MapFile(unsigned int) {
  
  DWORD LastError; // eax
  DWORD v4; // eax
  HANDLE hFile; // [esp+0h] [ebp-14h]
  HANDLE hFileMappingObject; // [esp+4h] [ebp-10h]
  LPVOID v7; // [esp+8h] [ebp-Ch]
  struct FLIntHandleStruct *IntHandlePtr; // [esp+Ch] [ebp-8h]

  IntHandlePtr = CFileLibrary::pGetIntHandlePtr(this, a2);
  if ( !IntHandlePtr )
    return 0;
  if ( *(_DWORD *)(*((_DWORD *)this + 116) + 24 * *(__int16 *)(*((_DWORD *)IntHandlePtr + 5) + 20) + 12) )
  {
    ++*(_DWORD *)(*((_DWORD *)this + 116) + 24 * *(__int16 *)(*((_DWORD *)IntHandlePtr + 5) + 20) + 16);
    return *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 8)
         + *(_DWORD *)(*((_DWORD *)this + 116) + 24 * *(__int16 *)(*((_DWORD *)IntHandlePtr + 5) + 20) + 8);
  }
  else
  {
    hFile = CFileLibrary::pGetFileLibraryHandle(this, *(__int16 *)(*((_DWORD *)IntHandlePtr + 5) + 20));
    hFileMappingObject = CreateFileMappingA(hFile, 0, 2u, 0, 0, 0);
    if ( hFileMappingObject == (HANDLE)-1 )
    {
      LastError = GetLastError();
      j__printf("Unable map file . LastError was: %d", LastError);
      CFileLibrary::FileClose(this, a2);
      return 0;
    }
    else
    {
      v7 = MapViewOfFile(hFileMappingObject, 4u, 0, 0, 0);
      if ( v7 )
      {
        *(_DWORD *)(*((_DWORD *)this + 116) + 24 * *(__int16 *)(*((_DWORD *)IntHandlePtr + 5) + 20) + 8) = v7;
        *(_DWORD *)(*((_DWORD *)this + 116) + 24 * *(__int16 *)(*((_DWORD *)IntHandlePtr + 5) + 20) + 12) = hFileMappingObject;
        *(_DWORD *)(*((_DWORD *)this + 116) + 24 * *(__int16 *)(*((_DWORD *)IntHandlePtr + 5) + 20) + 16) = 1;
        return (int)v7 + *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 8);
      }
      else
      {
        v4 = GetLastError();
        j__printf("Unable map view of file . LastError was: %d", v4);
        CloseHandle(hFileMappingObject);
        CFileLibrary::FileClose(this, a2);
        return 0;
      }
    }
  }
}


// address=[0x2f09ef0]
// Decompiled from unsigned int __thiscall CFileLibrary::FileOpen(_DWORD *this, wchar_t *String, int Size)
unsigned int  CFileLibrary::FileOpen(wchar_t const *,int) {
  
  FLIntHandleStruct *v4; // [esp+10h] [ebp-44Ch]
  FLIntHandleStruct *v5; // [esp+14h] [ebp-448h]
  FLIntHandleStruct *v6; // [esp+1Ch] [ebp-440h]
  FLIntHandleStruct *C; // [esp+20h] [ebp-43Ch]
  int v8; // [esp+24h] [ebp-438h]
  int Directory; // [esp+28h] [ebp-434h]
  int File; // [esp+2Ch] [ebp-430h]
  unsigned int v11; // [esp+30h] [ebp-42Ch]
  int i; // [esp+38h] [ebp-424h]
  FLIntHandleStruct *v14; // [esp+38h] [ebp-424h]
  wchar_t String1[260]; // [esp+3Ch] [ebp-420h] BYREF
  wchar_t Destination[260]; // [esp+244h] [ebp-218h] BYREF
  int v17; // [esp+458h] [ebp-4h]

  if ( !(unsigned __int8)CFileLibrary::pCutPathAndFilename(String, Destination, String1) )
    return -1;
  File = 0;
  Directory = CFileLibrary::pFindDirectory(Destination);
  if ( Directory )
    File = CFileLibrary::pFindFile(String1, Directory);
  if ( !File || *(__int16 *)(File + 20) == -4 )
    return -1;
  ++*this;
  v8 = 0;
  do
  {
    v11 = this[8];
    this[8] = v11 + 1;
    if ( v11 == -1 )
    {
      v11 = this[8];
      this[8] = v11 + 1;
    }
    for ( i = this[v11 % 0x64 + 14]; i && *(_DWORD *)(i + 16) != v11; i = *(_DWORD *)(i + 24) )
    {
      if ( !*(_DWORD *)(i + 24) )
      {
        v8 = 1;
        break;
      }
    }
  }
  while ( !v8 && i );
  if ( i )
  {
    v5 = (FLIntHandleStruct *)operator new(0x1Cu);
    v17 = 1;
    if ( v5 )
      v4 = FLIntHandleStruct::FLIntHandleStruct(v5);
    else
      v4 = 0;
    v17 = -1;
    *(_DWORD *)(i + 24) = v4;
    v14 = *(FLIntHandleStruct **)(i + 24);
  }
  else
  {
    C = (FLIntHandleStruct *)operator new(0x1Cu);
    v17 = 0;
    if ( C )
      v6 = FLIntHandleStruct::FLIntHandleStruct(C);
    else
      v6 = 0;
    v17 = -1;
    v14 = v6;
    this[v11 % 0x64 + 14] = v6;
  }
  if ( Size > 0 )
  {
    *((_DWORD *)v14 + 3) = operator new[](Size);
    *((_WORD *)v14 + 2) = Size;
  }
  else
  {
    *((_WORD *)v14 + 2) = 0;
  }
  *((_DWORD *)v14 + 5) = File;
  *((_DWORD *)v14 + 4) = v11;
  return v11;
}


// address=[0x2f0a220]
// Decompiled from CFileLibrary *__thiscall CFileLibrary::FileClose(CFileLibrary *this, unsigned int a2)
void  CFileLibrary::FileClose(unsigned int) {
  
  CFileLibrary *result; // eax
  FLIntHandleStruct *v3; // [esp+10h] [ebp-Ch]
  FLIntHandleStruct *v4; // [esp+18h] [ebp-4h]

  ++*((_DWORD *)this + 1);
  result = this;
  v4 = (FLIntHandleStruct *)*((_DWORD *)this + a2 % 0x64 + 14);
  if ( !v4 )
    return result;
  v3 = 0;
  while ( v4 )
  {
    if ( *((_DWORD *)v4 + 4) == a2 )
    {
      if ( v3 )
        *((_DWORD *)v3 + 6) = *((_DWORD *)v4 + 6);
      else
        *((_DWORD *)this + a2 % 0x64 + 14) = *((_DWORD *)v4 + 6);
      return (CFileLibrary *)FLIntHandleStruct::`scalar deleting destructor'(v4, 1u);
    }
    result = v4;
    v3 = v4;
    v4 = (FLIntHandleStruct *)*((_DWORD *)v4 + 6);
  }
  return result;
}


// address=[0x2f0a2e0]
// Decompiled from int __thiscall CFileLibrary::FileSeek(CFileLibrary *this, unsigned int a2, int a3, int a4)
unsigned int  CFileLibrary::FileSeek(unsigned int,long,int) {
  
  int v5; // [esp+10h] [ebp-Ch]
  int v6; // [esp+14h] [ebp-8h]
  int *v7; // [esp+18h] [ebp-4h]

  ++*((_DWORD *)this + 2);
  v7 = (int *)*((_DWORD *)this + a2 % 0x64 + 14);
  if ( v7 )
  {
    while ( 1 )
    {
      if ( !v7 )
      {
        BBSupportTracePrintF(3, "CFileLibrary::FileSeek\t:\tFailed to seek in %s", (const char *)*MEMORY[0x14]);
        return -1;
      }
      if ( v7[4] == a2 )
        break;
      v7 = (int *)v7[6];
    }
    v6 = *v7;
    if ( (*(_WORD *)(v7[5] + 4) & 1) != 0 )
      v5 = *(_DWORD *)(v7[5] + 16);
    else
      v5 = *(_DWORD *)(v7[5] + 12);
    if ( a4 )
    {
      if ( a4 == 1 )
      {
        v6 += a3;
      }
      else if ( a4 == 2 )
      {
        v6 = a3 + v5;
      }
    }
    else
    {
      v6 = a3;
    }
    if ( v6 < 0 )
      v6 = 0;
    if ( v6 > v5 )
      v6 = v5;
    *v7 = v6;
    return v6;
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::FileSeek\t:\tFailed to get file handle");
    return -1;
  }
}


// address=[0x2f0a420]
// Decompiled from size_t __thiscall CFileLibrary::FileRead(_DWORD *this, int a2, char *lpBuffer, size_t Size)
unsigned int  CFileLibrary::FileRead(unsigned int,void *,unsigned int) {
  
  DWORD v5; // [esp+4h] [ebp-48h] BYREF
  LONG lDistanceToMove; // [esp+8h] [ebp-44h]
  unsigned int v7; // [esp+Ch] [ebp-40h]
  void *v8; // [esp+10h] [ebp-3Ch]
  size_t v9; // [esp+14h] [ebp-38h]
  char *v10; // [esp+18h] [ebp-34h]
  signed int v11; // [esp+1Ch] [ebp-30h]
  int v12; // [esp+20h] [ebp-2Ch]
  DWORD NumberOfBytesRead; // [esp+24h] [ebp-28h] BYREF
  DWORD v14; // [esp+28h] [ebp-24h]
  size_t v15; // [esp+2Ch] [ebp-20h]
  unsigned int v16; // [esp+30h] [ebp-1Ch]
  DWORD v17; // [esp+34h] [ebp-18h] BYREF
  _DWORD *v18; // [esp+38h] [ebp-14h]
  HANDLE hFile; // [esp+3Ch] [ebp-10h]
  int v20; // [esp+40h] [ebp-Ch]
  DWORD nNumberOfBytesToRead; // [esp+44h] [ebp-8h]
  int IntHandlePtr; // [esp+48h] [ebp-4h]

  v18 = this;
  v10 = lpBuffer;
  ++this[3];
  v18[4] += Size;
  IntHandlePtr = CFileLibrary::pGetIntHandlePtr(a2);
  if ( !IntHandlePtr )
    return -1;
  hFile = (HANDLE)CFileLibrary::pGetFileLibraryHandle(*(__int16 *)(*(_DWORD *)(IntHandlePtr + 20) + 20));
  if ( hFile == (HANDLE)-1 )
  {
    BBSupportTracePrintF(3, "CFileLibrary::FileRead\t:\tfailed to get lib handle");
    return -1;
  }
  if ( (*(_WORD *)(*(_DWORD *)(IntHandlePtr + 20) + 4) & 1) != 0 )
  {
    nNumberOfBytesToRead = *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 16) - *(_DWORD *)IntHandlePtr;
    if ( nNumberOfBytesToRead )
    {
      if ( nNumberOfBytesToRead >= Size )
      {
        if ( *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 28)
          || (v9 = *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 16),
              v8 = operator new[](v9),
              *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 28) = v8,
              CFileLibrary::LoadEntireFile(
                a2,
                *(LPVOID *)(*(_DWORD *)(IntHandlePtr + 20) + 28),
                *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 24),
                0) != -1) )
        {
          j__memcpy(
            lpBuffer,
            (const void *)(*(_DWORD *)IntHandlePtr + *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 28)),
            Size);
          *(_DWORD *)IntHandlePtr += Size;
          return Size;
        }
        else
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tUnable to load entire file %s ",
            **(const char ***)(IntHandlePtr + 20));
          return -1;
        }
      }
      else
      {
        BBSupportTracePrintF(3, "CFileLibrary::FileRead\t:\tnot enough data");
        return -1;
      }
    }
    else
    {
      BBSupportTracePrintF(3, "CFileLibrary::FileRead\t:\tEOF");
      return -2;
    }
  }
  else
  {
    nNumberOfBytesToRead = *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 12) - *(_DWORD *)IntHandlePtr;
    if ( nNumberOfBytesToRead > Size )
      nNumberOfBytesToRead = Size;
    if ( !nNumberOfBytesToRead )
      return -2;
    if ( *(_WORD *)(IntHandlePtr + 4) )
    {
      v20 = 0;
      v16 = *(_DWORD *)IntHandlePtr / (unsigned int)*(unsigned __int16 *)(IntHandlePtr + 4);
      v7 = *(_DWORD *)IntHandlePtr % (unsigned int)*(unsigned __int16 *)(IntHandlePtr + 4);
      if ( v16 != *(_DWORD *)(IntHandlePtr + 8) && v7 )
      {
        lDistanceToMove = *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 8)
                        + v16 * *(unsigned __int16 *)(IntHandlePtr + 4);
        v14 = SetFilePointer(hFile, lDistanceToMove, 0, 0);
        if ( v14 == -1 )
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tfailed set file pointer on FILE_BEGIN, %s ",
            **(const char ***)(IntHandlePtr + 20));
          return -1;
        }
        ReadFile(hFile, *(LPVOID *)(IntHandlePtr + 12), *(unsigned __int16 *)(IntHandlePtr + 4), &v5, 0);
        if ( v5 != *(unsigned __int16 *)(IntHandlePtr + 4) )
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tfailed to read file%s ",
            **(const char ***)(IntHandlePtr + 20));
          return -1;
        }
        *(_DWORD *)(IntHandlePtr + 8) = v16;
      }
      if ( v16 == *(_DWORD *)(IntHandlePtr + 8) )
      {
        v12 = *(_DWORD *)IntHandlePtr - v16 * *(unsigned __int16 *)(IntHandlePtr + 4);
        v15 = *(unsigned __int16 *)(IntHandlePtr + 4) - v12;
        if ( v15 >= nNumberOfBytesToRead )
        {
          j__memmove(lpBuffer, (const void *)(v12 + *(_DWORD *)(IntHandlePtr + 12)), nNumberOfBytesToRead);
          *(_DWORD *)IntHandlePtr += nNumberOfBytesToRead;
          return nNumberOfBytesToRead;
        }
        if ( (int)v15 > 0 )
        {
          j__memmove(lpBuffer, (const void *)(v12 + *(_DWORD *)(IntHandlePtr + 12)), v15);
          v20 += v15;
          nNumberOfBytesToRead -= v15;
        }
      }
      v11 = nNumberOfBytesToRead / *(unsigned __int16 *)(IntHandlePtr + 4);
      v14 = SetFilePointer(hFile, *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 8) + v20 + *(_DWORD *)IntHandlePtr, 0, 0);
      if ( v14 == -1 )
      {
        BBSupportTracePrintF(
          3,
          "CFileLibrary::FileRead\t:\tfailed set file pointer on FILE_BEGIN, %s ",
          **(const char ***)(IntHandlePtr + 20));
        return -1;
      }
      if ( v11 > 0 )
      {
        ReadFile(hFile, &v10[v20], v11 * *(unsigned __int16 *)(IntHandlePtr + 4), &v17, 0);
        if ( v17 != v11 * *(unsigned __int16 *)(IntHandlePtr + 4) )
          return -1;
        nNumberOfBytesToRead -= v17;
        v20 += v17;
      }
      v16 = (v20 + *(_DWORD *)IntHandlePtr) / (unsigned int)*(unsigned __int16 *)(IntHandlePtr + 4);
      ReadFile(hFile, *(LPVOID *)(IntHandlePtr + 12), *(unsigned __int16 *)(IntHandlePtr + 4), &v17, 0);
      if ( v17 == *(unsigned __int16 *)(IntHandlePtr + 4) )
      {
        ReadFile(hFile, *(LPVOID *)(IntHandlePtr + 12), *(unsigned __int16 *)(IntHandlePtr + 4), &v17, 0);
        if ( v17 == *(unsigned __int16 *)(IntHandlePtr + 4) )
        {
          j__memmove(&v10[v20], *(const void **)(IntHandlePtr + 12), nNumberOfBytesToRead);
          v20 += nNumberOfBytesToRead;
          *(_DWORD *)(IntHandlePtr + 8) = v16;
          *(_DWORD *)IntHandlePtr += v20;
          return v20;
        }
        else
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tfailed to read file%s ",
            **(const char ***)(IntHandlePtr + 20));
          return -1;
        }
      }
      else
      {
        BBSupportTracePrintF(
          3,
          "CFileLibrary::FileRead\t:\tfailed to read file%s ",
          **(const char ***)(IntHandlePtr + 20));
        return -1;
      }
    }
    else
    {
      v14 = SetFilePointer(hFile, *(_DWORD *)IntHandlePtr + *(_DWORD *)(*(_DWORD *)(IntHandlePtr + 20) + 8), 0, 0);
      if ( v14 == -1 )
      {
        BBSupportTracePrintF(
          3,
          "CFileLibrary::FileRead\t:\tfailed set file pointer on FILE_BEGIN, %s ",
          **(const char ***)(IntHandlePtr + 20));
        return -1;
      }
      else
      {
        ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
        if ( nNumberOfBytesToRead == NumberOfBytesRead )
        {
          *(_DWORD *)IntHandlePtr += NumberOfBytesRead;
          return NumberOfBytesRead;
        }
        else
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tfailed to read file%s ",
            **(const char ***)(IntHandlePtr + 20));
          return -1;
        }
      }
    }
  }
}


// address=[0x2f0a9d0]
// Decompiled from int __thiscall CFileLibrary::AddFileLibrary(CFileLibrary *this, LPCWSTR lpFileName, int a3)
int  CFileLibrary::AddFileLibrary(wchar_t const *,int) {
  
  size_t v4; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  wchar_t *v7; // eax
  int v8; // eax
  int v9; // [esp-Ch] [ebp-294h]
  int v10; // [esp-Ch] [ebp-294h]
  __int16 v11; // [esp-8h] [ebp-290h]
  __int16 v12; // [esp-8h] [ebp-290h]
  int v13; // [esp-4h] [ebp-28Ch]
  int v14; // [esp-4h] [ebp-28Ch]
  char v15[8]; // [esp+8h] [ebp-280h] BYREF
  wchar_t *v16; // [esp+10h] [ebp-278h]
  void *v17; // [esp+14h] [ebp-274h]
  void *v18; // [esp+18h] [ebp-270h]
  void *v19; // [esp+1Ch] [ebp-26Ch]
  void *C; // [esp+20h] [ebp-268h]
  wchar_t *v21; // [esp+24h] [ebp-264h]
  int v22; // [esp+28h] [ebp-260h]
  void *v23; // [esp+2Ch] [ebp-25Ch]
  void *v24; // [esp+30h] [ebp-258h]
  void *v25; // [esp+34h] [ebp-254h]
  void *v26; // [esp+38h] [ebp-250h]
  void *v27; // [esp+3Ch] [ebp-24Ch]
  void *v28; // [esp+40h] [ebp-248h]
  LONG Buffer; // [esp+44h] [ebp-244h] BYREF
  wchar_t *String; // [esp+48h] [ebp-240h]
  wchar_t *v31; // [esp+4Ch] [ebp-23Ch]
  _DWORD *v32; // [esp+50h] [ebp-238h]
  _DWORD *v33; // [esp+54h] [ebp-234h]
  void *v34; // [esp+58h] [ebp-230h]
  void *v35; // [esp+5Ch] [ebp-22Ch]
  void *v36; // [esp+60h] [ebp-228h]
  void *v37; // [esp+64h] [ebp-224h]
  void *v38; // [esp+68h] [ebp-220h]
  void *v39; // [esp+6Ch] [ebp-21Ch]
  void *v40; // [esp+70h] [ebp-218h]
  void *v41; // [esp+74h] [ebp-214h]
  void *v42; // [esp+78h] [ebp-210h]
  unsigned int v43; // [esp+7Ch] [ebp-20Ch]
  void *v44; // [esp+80h] [ebp-208h]
  wchar_t **v45; // [esp+84h] [ebp-204h]
  void *v46; // [esp+88h] [ebp-200h]
  unsigned int v47; // [esp+8Ch] [ebp-1FCh]
  char v48[4]; // [esp+90h] [ebp-1F8h] BYREF
  int v49; // [esp+94h] [ebp-1F4h]
  size_t Size; // [esp+98h] [ebp-1F0h]
  signed int v51; // [esp+9Ch] [ebp-1ECh]
  size_t v52; // [esp+A0h] [ebp-1E8h]
  signed int v53; // [esp+A4h] [ebp-1E4h]
  void *v54; // [esp+A8h] [ebp-1E0h]
  DWORD v55; // [esp+ACh] [ebp-1DCh]
  void *v56; // [esp+B0h] [ebp-1D8h]
  void *v57; // [esp+B4h] [ebp-1D4h]
  _DWORD *v58; // [esp+B8h] [ebp-1D0h]
  __int16 v59[2]; // [esp+BCh] [ebp-1CCh] BYREF
  int v60; // [esp+C0h] [ebp-1C8h]
  int v61; // [esp+C4h] [ebp-1C4h]
  signed int j; // [esp+C8h] [ebp-1C0h]
  int v63; // [esp+CCh] [ebp-1BCh]
  LPVOID v64; // [esp+D0h] [ebp-1B8h]
  LPVOID lpBuffer; // [esp+D4h] [ebp-1B4h]
  _DWORD *v66; // [esp+D8h] [ebp-1B0h]
  LPVOID v67; // [esp+DCh] [ebp-1ACh]
  DWORD NumberOfBytesRead; // [esp+E0h] [ebp-1A8h] BYREF
  DWORD nNumberOfBytesToRead; // [esp+E4h] [ebp-1A4h]
  BOOL v70; // [esp+E8h] [ebp-1A0h]
  _BYTE *v71; // [esp+ECh] [ebp-19Ch]
  HANDLE hFile; // [esp+F0h] [ebp-198h]
  signed int i; // [esp+F4h] [ebp-194h]
  CFileLibrary *v74; // [esp+F8h] [ebp-190h]
  char v75[88]; // [esp+FCh] [ebp-18Ch] BYREF
  char v76[88]; // [esp+154h] [ebp-134h] BYREF
  char v77[88]; // [esp+1ACh] [ebp-DCh] BYREF
  _BYTE v78[32]; // [esp+204h] [ebp-84h] BYREF
  int v79[7]; // [esp+224h] [ebp-64h] BYREF
  int v80[7]; // [esp+240h] [ebp-48h] BYREF
  int v81[7]; // [esp+25Ch] [ebp-2Ch] BYREF
  int v82; // [esp+284h] [ebp-4h]

  v74 = this;
  hFile = CreateFileW(lpFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
  if ( hFile == (HANDLE)-1 )
  {
    BBSupportTracePrintF(3, "CFileLibrary::AddFileLibrary\t:\tFailed to add %s to library.", (const char *)lpFileName);
    return 6;
  }
  else
  {
    if ( *((_DWORD *)v74 + 10) == *((_DWORD *)v74 + 11) )
    {
      v47 = *((_DWORD *)v74 + 11) + 8;
      v57 = operator new[](24 * v47);
      v82 = 0;
      if ( v57 )
      {
        `vector constructor iterator'(
          v57,
          0x18u,
          v47,
          (void *(__thiscall *)(void *))FLLibraryFileStruct::FLLibraryFileStruct);
        v46 = v57;
      }
      else
      {
        v46 = 0;
      }
      v19 = v46;
      v82 = -1;
      v56 = v46;
      j__memset(v46, 0, 24 * (*((_DWORD *)v74 + 11) + 8));
      if ( *((int *)v74 + 11) > 0 )
      {
        j__memmove(v56, *((const void **)v74 + 116), 24 * *((_DWORD *)v74 + 11));
        C = (void *)*((_DWORD *)v74 + 116);
        operator delete[](C);
      }
      *((_DWORD *)v74 + 11) += 8;
      *((_DWORD *)v74 + 116) = v56;
    }
    v45 = (wchar_t **)(*((_DWORD *)v74 + 116) + 24 * (*((_DWORD *)v74 + 10))++);
    v4 = j__wcslen(lpFileName);
    v21 = (wchar_t *)operator new[](2 * (v4 + 1));
    *v45 = v21;
    j__wcscpy(*v45, lpFileName);
    v22 = 4;
    v55 = SetFilePointer(hFile, -4, 0, 2u);
    if ( v55 == -1 )
    {
      CloseHandle(hFile);
      BBSupportTracePrintF(
        3,
        "CFileLibrary::AddFileLibrary\t:\tFailed to set file ptr on FILE_END, %s",
        (const char *)lpFileName);
      return 6;
    }
    else
    {
      v70 = ReadFile(hFile, &Buffer, 4u, &NumberOfBytesRead, 0);
      if ( v70 )
      {
        v55 = SetFilePointer(hFile, Buffer, 0, 0);
        if ( v55 == -1 )
        {
          CloseHandle(hFile);
          BBSupportTracePrintF(
            3,
            "CFileLibrary::AddFileLibrary\t:\tFailed to set file ptr on FILE_BEGIN, %s",
            (const char *)lpFileName);
          return 6;
        }
        else
        {
          FLHeaderStruct::FLHeaderStruct((FLHeaderStruct *)v48);
          v70 = ReadFile(hFile, v48, 0x18u, &NumberOfBytesRead, 0);
          if ( v70 )
          {
            if ( v49 == 4097 || v49 == 256 )
            {
              v23 = operator new[](Size);
              lpBuffer = v23;
              v18 = operator new[](v52);
              v64 = v18;
              v43 = v53;
              v54 = operator new[](24 * v53);
              v82 = 1;
              if ( v54 )
              {
                `vector constructor iterator'(
                  v54,
                  0x18u,
                  v43,
                  (void *(__thiscall *)(void *))FLHeaderFileStruct::FLHeaderFileStruct);
                v44 = v54;
              }
              else
              {
                v44 = 0;
              }
              v17 = v44;
              v82 = -1;
              v67 = v44;
              nNumberOfBytesToRead = Size;
              v70 = ReadFile(hFile, lpBuffer, Size, &NumberOfBytesRead, 0);
              if ( v70 && NumberOfBytesRead == nNumberOfBytesToRead )
              {
                nNumberOfBytesToRead = v52;
                v70 = ReadFile(hFile, v64, v52, &NumberOfBytesRead, 0);
                if ( v70 && NumberOfBytesRead == nNumberOfBytesToRead )
                {
                  nNumberOfBytesToRead = 24 * v53;
                  v70 = ReadFile(hFile, v67, 24 * v53, &NumberOfBytesRead, 0);
                  if ( v70 && NumberOfBytesRead == nNumberOfBytesToRead )
                  {
                    *(_DWORD *)v59 = *((_DWORD *)v74 + 10) - 1;
                    v33 = operator new[](4 * v51);
                    v58 = v33;
                    v71 = lpBuffer;
                    for ( i = 0; i < v51; ++i )
                    {
                      v58[i] = v71;
                      while ( *v71 )
                        ++v71;
                      ++v71;
                    }
                    v32 = operator new[](4 * v53);
                    v66 = v32;
                    v71 = v64;
                    for ( i = 0; i < v53; ++i )
                    {
                      v66[i] = v71;
                      while ( *v71 )
                        ++v71;
                      ++v71;
                    }
                    v61 = CFileLibrary::pAddDirectory(0);
                    v63 = (int)v67;
                    for ( i = 0; i < v53; ++i )
                    {
                      if ( *(__int16 *)(v63 + 12) == -1 )
                      {
                        if ( v49 == 256 )
                        {
                          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v75);
                          v82 = 2;
                          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                            (int)v80,
                            (char *)v66[i]);
                          LOBYTE(v82) = 3;
                          v13 = a3;
                          v11 = v59[0];
                          v9 = v63;
                          v5 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v80);
                          CFileLibrary::pAddFile(v61, v5, v9, v11, v13);
                          LOBYTE(v82) = 2;
                          std::wstring::~wstring(v80);
                          v82 = -1;
                          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v75);
                        }
                        else
                        {
                          v31 = (wchar_t *)v66[i];
                          CFileLibrary::pAddFile(v61, v31, v63, v59[0], a3);
                        }
                      }
                      v63 += 24;
                    }
                    for ( i = 0; i < v51; ++i )
                    {
                      if ( v49 == 256 )
                      {
                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v76);
                        v82 = 4;
                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                          (int)v81,
                          (char *)v58[i]);
                        LOBYTE(v82) = 5;
                        v6 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v81);
                        CFileLibrary::pAddDirectory(v6);
                        LOBYTE(v82) = 4;
                        std::wstring::~wstring(v81);
                        v82 = -1;
                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v76);
                      }
                      else
                      {
                        String = (wchar_t *)v58[i];
                        v61 = CFileLibrary::pAddDirectory(String);
                      }
                      v60 = (int)v67;
                      for ( j = 0; j < v53; ++j )
                      {
                        if ( *(__int16 *)(v60 + 12) == i )
                        {
                          if ( v49 == 256 )
                          {
                            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v77);
                            v82 = 6;
                            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                              (int)v79,
                              (char *)v66[j]);
                            LOBYTE(v82) = 7;
                            v14 = a3;
                            v12 = v59[0];
                            v10 = v60;
                            v7 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v79);
                            CFileLibrary::pAddFile(v61, v7, v10, v12, v14);
                            LOBYTE(v82) = 6;
                            std::wstring::~wstring(v79);
                            v82 = -1;
                            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v77);
                          }
                          else
                          {
                            v16 = (wchar_t *)v66[j];
                            CFileLibrary::pAddFile(v61, v16, v60, v59[0], a3);
                          }
                        }
                        v60 += 24;
                      }
                    }
                    v8 = std::make_pair<wchar_t const * &,int &>(v15, &lpFileName, v59);
                    std::pair<std::wstring,int>::pair<std::wstring,int>(v8);
                    v82 = 8;
                    std::vector<std::pair<std::wstring,int>>::push_back(v78);
                    v82 = -1;
                    std::pair<std::wstring,int>::~pair<std::wstring,int>(v78);
                    v28 = v66;
                    operator delete[](v66);
                    v27 = v58;
                    operator delete[](v58);
                    v26 = lpBuffer;
                    operator delete[](lpBuffer);
                    v25 = v64;
                    operator delete[](v64);
                    v24 = v67;
                    operator delete[](v67);
                    CloseHandle(hFile);
                    CFileLibrary::pOptimize(v74);
                    return 1;
                  }
                  else
                  {
                    CloseHandle(hFile);
                    v36 = lpBuffer;
                    operator delete[](lpBuffer);
                    v35 = v64;
                    operator delete[](v64);
                    v34 = v67;
                    operator delete[](v67);
                    BBSupportTracePrintF(
                      3,
                      "CFileLibrary::AddFileLibrary\t:\tFailed to read file info, %s",
                      (const char *)lpFileName);
                    return 6;
                  }
                }
                else
                {
                  CloseHandle(hFile);
                  v39 = lpBuffer;
                  operator delete[](lpBuffer);
                  v38 = v64;
                  operator delete[](v64);
                  v37 = v67;
                  operator delete[](v67);
                  BBSupportTracePrintF(
                    3,
                    "CFileLibrary::AddFileLibrary\t:\tFailed to read file names, %s",
                    (const char *)lpFileName);
                  return 6;
                }
              }
              else
              {
                CloseHandle(hFile);
                v42 = lpBuffer;
                operator delete[](lpBuffer);
                v41 = v64;
                operator delete[](v64);
                v40 = v67;
                operator delete[](v67);
                BBSupportTracePrintF(
                  3,
                  "CFileLibrary::AddFileLibrary\t:\tFailed to read directory names, %s",
                  (const char *)lpFileName);
                return 6;
              }
            }
            else
            {
              CloseHandle(hFile);
              BBSupportTracePrintF(3, "CFileLibrary::AddFileLibrary\t:\tWrong version, %s", (const char *)lpFileName);
              return 7;
            }
          }
          else
          {
            CloseHandle(hFile);
            BBSupportTracePrintF(
              3,
              "CFileLibrary::AddFileLibrary\t:\tFailed to read file data, %s",
              (const char *)lpFileName);
            return 6;
          }
        }
      }
      else
      {
        CloseHandle(hFile);
        BBSupportTracePrintF(
          3,
          "CFileLibrary::AddFileLibrary\t:\tFailed to read file data, %s",
          (const char *)lpFileName);
        return 6;
      }
    }
  }
}


// address=[0x2f0b6c0]
// Decompiled from int __thiscall CFileLibrary::ListFilesInLib(_DWORD *this, int a2, char a3)
class std::vector<struct std::pair<std::wstring,std::wstring >,class std::allocator<struct std::pair<std::wstring,std::wstring > > >  CFileLibrary::ListFilesInLib(wchar_t const *) {
  
  char v4; // [esp-1Ch] [ebp-94h] BYREF
  int v5; // [esp-18h] [ebp-90h]
  int v6; // [esp-14h] [ebp-8Ch]
  _DWORD v7[3]; // [esp-10h] [ebp-88h] BYREF
  int v8; // [esp-4h] [ebp-7Ch]
  int v9; // [esp+0h] [ebp-78h]
  int v10[4]; // [esp+4h] [ebp-74h] BYREF
  _BYTE v11[12]; // [esp+14h] [ebp-64h] BYREF
  _BYTE v12[12]; // [esp+20h] [ebp-58h] BYREF
  int v13; // [esp+2Ch] [ebp-4Ch]
  int v14; // [esp+30h] [ebp-48h]
  char *v15; // [esp+34h] [ebp-44h]
  int v16; // [esp+38h] [ebp-40h]
  _DWORD *v17; // [esp+3Ch] [ebp-3Ch]
  int v18; // [esp+44h] [ebp-34h]
  std::_Iterator_base12 *v19; // [esp+48h] [ebp-30h]
  std::_Iterator_base12 *v20; // [esp+4Ch] [ebp-2Ch]
  int j; // [esp+50h] [ebp-28h]
  int i; // [esp+54h] [ebp-24h]
  int v23; // [esp+58h] [ebp-20h]
  int v24; // [esp+5Ch] [ebp-1Ch]
  _DWORD *v25; // [esp+60h] [ebp-18h]
  int v26; // [esp+64h] [ebp-14h]
  char v27; // [esp+6Bh] [ebp-Dh]
  int v28; // [esp+74h] [ebp-4h]

  v25 = this;
  v23 = 0;
  BBSupportTracePrintF(1, "Starting listing");
  v8 = *(_DWORD *)std::_Iterator_base12::operator=(&a3);
  v17 = v7;
  v16 = std::vector<std::pair<std::wstring,int>>::end(v7);
  v15 = &v4;
  v14 = std::vector<std::pair<std::wstring,int>>::begin(&v4);
  v13 = std::find_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>,_lambda_2ccfe65c9d4fa599f75d5b3f0ed0c104_>(
          v12,
          v4,
          v5,
          v6,
          v7[0],
          v7[1],
          v7[2],
          v8);
  v28 = 0;
  v20 = (std::_Iterator_base12 *)std::vector<std::pair<std::wstring,int>>::end(v11);
  v19 = v20;
  LOBYTE(v28) = 1;
  v27 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::operator==(v20);
  LOBYTE(v28) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>(v11);
  if ( v27 )
  {
    std::vector<std::pair<std::wstring,std::wstring>>::vector<std::pair<std::wstring,std::wstring>>(v9, v10[0]);
    v23 |= 1u;
    v28 = -1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>(v12);
    return a2;
  }
  else
  {
    v18 = *(_DWORD *)(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::operator->(v12)
                    + 28);
    v26 = v25[117];
    std::vector<std::pair<std::wstring,std::wstring>>::vector<std::pair<std::wstring,std::wstring>>(v9, v10[0]);
    LOBYTE(v28) = 2;
    for ( i = 0; i < v25[13]; ++i )
    {
      v24 = *(_DWORD *)(v26 + 12);
      for ( j = 0; j < *(__int16 *)(v26 + 6); ++j )
      {
        if ( *(__int16 *)(v24 + 20) == v18 )
        {
          std::vector<std::pair<std::wstring,std::wstring>>::emplace_back<wchar_t * &,wchar_t * &>(v26, v24);
          BBSupportTracePrintF(1, "File: %s\\%s", *(const char **)v26, *(const char **)v24);
        }
        v24 += 32;
      }
      v26 += 16;
    }
    std::vector<std::pair<std::wstring,std::wstring>>::vector<std::pair<std::wstring,std::wstring>>(v10);
    v23 |= 1u;
    LOBYTE(v28) = 0;
    std::vector<std::pair<std::wstring,std::wstring>>::~vector<std::pair<std::wstring,std::wstring>>(v9, v10[0]);
    v28 = -1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>(v12);
    return a2;
  }
}


// address=[0x2f0b8c0]
// Decompiled from int __thiscall CFileLibrary::DumpFilesInLib(CFileLibrary *this, const wchar_t *a2, wchar_t *String)
void  CFileLibrary::DumpFilesInLib(wchar_t const *,wchar_t const *) {
  
  wchar_t *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  wchar_t *v7; // eax
  const char *v8; // eax
  _Cnd_internal_imp_t *v9; // [esp-4h] [ebp-18Ch]
  _Cnd_internal_imp_t *v10; // [esp-4h] [ebp-18Ch]
  _Cnd_internal_imp_t *v11; // [esp-4h] [ebp-18Ch]
  _BYTE v12[12]; // [esp+4h] [ebp-184h] BYREF
  _BYTE v13[16]; // [esp+10h] [ebp-178h] BYREF
  _BYTE v14[12]; // [esp+20h] [ebp-168h] BYREF
  void *C; // [esp+2Ch] [ebp-15Ch]
  signed int v16; // [esp+30h] [ebp-158h]
  void *v17; // [esp+34h] [ebp-154h]
  void *v18; // [esp+38h] [ebp-150h]
  int v19; // [esp+3Ch] [ebp-14Ch]
  void *v20; // [esp+40h] [ebp-148h]
  void *v21; // [esp+44h] [ebp-144h]
  void *v22; // [esp+48h] [ebp-140h]
  void *v23; // [esp+4Ch] [ebp-13Ch]
  void *v24; // [esp+50h] [ebp-138h]
  CFileLibrary *v25; // [esp+54h] [ebp-134h]
  _BYTE *v26; // [esp+58h] [ebp-130h]
  int v27; // [esp+5Ch] [ebp-12Ch]
  void *Buffer; // [esp+60h] [ebp-128h]
  int v29; // [esp+64h] [ebp-124h]
  size_t Size; // [esp+68h] [ebp-120h]
  _BYTE v31[72]; // [esp+6Ch] [ebp-11Ch] BYREF
  int v32[7]; // [esp+B4h] [ebp-D4h] BYREF
  int v33[7]; // [esp+D0h] [ebp-B8h] BYREF
  int v34[7]; // [esp+ECh] [ebp-9Ch] BYREF
  _BYTE v35[28]; // [esp+108h] [ebp-80h] BYREF
  int v36[7]; // [esp+124h] [ebp-64h] BYREF
  int v37[7]; // [esp+140h] [ebp-48h] BYREF
  _BYTE v38[28]; // [esp+15Ch] [ebp-2Ch] BYREF
  int v39; // [esp+184h] [ebp-4h]

  v25 = this;
  CFileLibrary::ListFilesInLib(this, (int)v13, (char)a2);
  v39 = 0;
  if ( (unsigned __int8)std::vector<std::pair<std::wstring,std::wstring>>::empty(v13) )
  {
    v39 = -1;
    return std::vector<std::pair<std::wstring,std::wstring>>::~vector<std::pair<std::wstring,std::wstring>>();
  }
  else
  {
    std::wstring::wstring(v36, String);
    LOBYTE(v39) = 1;
    if ( !(unsigned __int8)sub_2F0D990(v36) )
      sub_2F0D9D0(v36);
    v26 = v13;
    std::vector<std::pair<std::wstring,std::wstring>>::begin(v14);
    LOBYTE(v39) = 2;
    std::vector<std::pair<std::wstring,std::wstring>>::end(v12);
    LOBYTE(v39) = 3;
    while ( (unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::operator!=((std::_Iterator_base12 *)v12) )
    {
      v29 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::operator*(v14);
      v9 = (_Cnd_internal_imp_t *)v29;
      v24 = (void *)std::operator+<wchar_t>((int)v34, (int)v36, (wchar_t *)L"\\");
      v23 = v24;
      LOBYTE(v39) = 4;
      std::operator+<wchar_t>(v37, v24, v9);
      LOBYTE(v39) = 6;
      std::wstring::~wstring(v34);
      if ( !(unsigned __int8)sub_2F0D990(v37) )
        sub_2F0D9D0(v37);
      v10 = (_Cnd_internal_imp_t *)(v29 + 28);
      v22 = (void *)std::operator+<wchar_t>((int)v33, v29, (wchar_t *)L"\\");
      v21 = v22;
      LOBYTE(v39) = 7;
      std::operator+<wchar_t>(v38, v22, v10);
      LOBYTE(v39) = 9;
      std::wstring::~wstring(v33);
      v4 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v38);
      v27 = CFileLibrary::FileOpen(v4, 0);
      Size = 0;
      if ( v27 == -1 )
      {
        v5 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v38);
        BBSupportTracePrintF(1, "can't open file `%s'", v5);
      }
      else
      {
        Size = CFileLibrary::FileSize((CFileLibrary *)&g_cFileLibrary, v27);
      }
      v20 = operator new[](Size);
      Buffer = v20;
      j__memset(v20, 0, Size);
      v19 = CFileLibrary::FileRead(v27, Buffer, Size);
      if ( v19 == -1 )
      {
        v6 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v38);
        BBSupportTracePrintF(1, "cannot read `%s'", v6);
      }
      else
      {
        v11 = (_Cnd_internal_imp_t *)(v29 + 28);
        v18 = (void *)std::operator+<wchar_t>((int)v32, (int)v37, (wchar_t *)asc_3AB56DC);
        v17 = v18;
        LOBYTE(v39) = 10;
        std::operator+<wchar_t>(v35, v18, v11);
        LOBYTE(v39) = 12;
        std::wstring::~wstring(v32);
        CFile::CFile((CFile *)v31);
        LOBYTE(v39) = 13;
        v7 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v35);
        CFile::Open(v7, 10, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
        v16 = CFile::Write(
                Buffer,
                1u,
                Size,
                (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h",
                0);
        if ( v16 < (int)Size )
        {
          v8 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v35);
          BBSupportTracePrintF(1, "short write `%s'", v8);
        }
        CFile::Close((CFile *)v31, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
        LOBYTE(v39) = 12;
        CFile::~CFile();
        LOBYTE(v39) = 9;
        std::wstring::~wstring(v35);
      }
      C = Buffer;
      operator delete[](Buffer);
      CFileLibrary::FileClose((CFileLibrary *)&g_cFileLibrary, v27);
      LOBYTE(v39) = 6;
      std::wstring::~wstring(v38);
      LOBYTE(v39) = 3;
      std::wstring::~wstring(v37);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::operator++(v14);
    }
    LOBYTE(v39) = 2;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>(v12);
    LOBYTE(v39) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>(v14);
    LOBYTE(v39) = 0;
    std::wstring::~wstring(v36);
    v39 = -1;
    return std::vector<std::pair<std::wstring,std::wstring>>::~vector<std::pair<std::wstring,std::wstring>>();
  }
}


// address=[0x2f0bd30]
// Decompiled from void __thiscall CFileLibrary::InitFileLibraries(CFileLibrary *this)
void  CFileLibrary::InitFileLibraries(void) {
  
  CFileLibrary::pFreeFLData(this);
}


// address=[0x2f0bd50]
// Decompiled from void __thiscall CFileLibrary::C_Init(CFileLibrary *this)
void  CFileLibrary::C_Init(void) {
  
  CFileLibrary::pFreeFLCreationData(this);
}


// address=[0x2f0bd70]
// Decompiled from wchar_t *__thiscall CFileLibrary::C_AddPath(_DWORD *this, wchar_t *String, int a3, wchar_t *Source, wchar_t *a5)
void  CFileLibrary::C_AddPath(wchar_t const *,int,wchar_t const *,wchar_t const *) {
  
  wchar_t *result; // eax
  size_t v6; // eax
  size_t v7; // eax
  FLPathListStruct *v8; // [esp+1Ch] [ebp-24h]
  FLPathListStruct *C; // [esp+20h] [ebp-20h]
  int i; // [esp+28h] [ebp-18h]
  size_t Count; // [esp+2Ch] [ebp-14h]

  C = (FLPathListStruct *)operator new(0x14u);
  if ( C )
    v8 = FLPathListStruct::FLPathListStruct(C);
  else
    v8 = 0;
  Count = j__wcslen(String);
  if ( !Count )
    return (wchar_t *)BBSupportTracePrintF(3, "CFileLibrary::C_AddPath : No path specified.");
  if ( String[Count - 1] == 92 )
  {
    *(_DWORD *)v8 = operator new[](2 * Count);
    j__wcsncpy(*(wchar_t **)v8, String, Count);
    *(_WORD *)(*(_DWORD *)v8 + 2 * Count - 2) = 0;
  }
  else
  {
    *(_DWORD *)v8 = operator new[](2 * (Count + 1));
    j__wcscpy(*(wchar_t **)v8, String);
  }
  if ( Source )
  {
    v6 = j__wcslen(Source);
    *((_DWORD *)v8 + 1) = operator new[](2 * (v6 + 1));
    j__wcscpy(*((wchar_t **)v8 + 1), Source);
  }
  else
  {
    *((_DWORD *)v8 + 1) = operator new[](4u);
    j__wcscpy(*((wchar_t **)v8 + 1), asc_3AB57EC);
  }
  result = (wchar_t *)v8;
  *((_DWORD *)v8 + 3) = a3;
  if ( a5 )
  {
    v7 = j__wcslen(a5);
    *((_DWORD *)v8 + 2) = operator new[](2 * (v7 + 1));
    result = j__wcscpy(*((wchar_t **)v8 + 2), a5);
  }
  if ( this[5] )
  {
    for ( i = this[5]; *(_DWORD *)(i + 16); i = *(_DWORD *)(i + 16) )
      ;
    result = (wchar_t *)v8;
    *(_DWORD *)(i + 16) = v8;
  }
  else
  {
    this[5] = v8;
  }
  return result;
}


// address=[0x2f0bfc0]
// Decompiled from int __thiscall CFileLibrary::C_CreateFileLibrary(  _DWORD *this,  LPCWSTR lpFileName,  CHAR *a3,  char a4,  DWORD nNumberOfBytesToRead)
int  CFileLibrary::C_CreateFileLibrary(wchar_t const *,char *,int,int) {
  
  size_t v6; // eax
  size_t v7; // eax
  size_t v8; // eax
  size_t v9; // eax
  const char *v10; // eax
  size_t v11; // eax
  size_t v12; // eax
  size_t v13; // eax
  size_t v14; // eax
  const char *v15; // eax
  const char *v16; // [esp-Ch] [ebp-2D48h]
  const char *v17; // [esp-8h] [ebp-2D44h]
  const char *v18; // [esp-4h] [ebp-2D40h]
  FLDirListStruct *v19; // [esp+18h] [ebp-2D24h]
  DWORD NumberOfBytesRead; // [esp+24h] [ebp-2D18h] BYREF
  void *v21; // [esp+28h] [ebp-2D14h]
  FLDirListStruct *v22; // [esp+2Ch] [ebp-2D10h]
  FLDirListStruct *v23; // [esp+30h] [ebp-2D0Ch]
  FLDirListStruct *v24; // [esp+34h] [ebp-2D08h]
  BOOL NextFileW; // [esp+38h] [ebp-2D04h]
  void *v26; // [esp+3Ch] [ebp-2D00h]
  FLFileListStruct *v27; // [esp+40h] [ebp-2CFCh]
  int v28; // [esp+44h] [ebp-2CF8h]
  void *v29; // [esp+48h] [ebp-2CF4h]
  FLDirListStruct *v30; // [esp+4Ch] [ebp-2CF0h]
  void *v31; // [esp+50h] [ebp-2CECh]
  FLDirListStruct *v32; // [esp+54h] [ebp-2CE8h]
  FLDirListStruct *v33; // [esp+58h] [ebp-2CE4h]
  FLDirListStruct *v34; // [esp+5Ch] [ebp-2CE0h]
  int v35; // [esp+60h] [ebp-2CDCh]
  unsigned int v36; // [esp+64h] [ebp-2CD8h]
  FLDirListStruct *v37; // [esp+68h] [ebp-2CD4h]
  FLDirListStruct *v38; // [esp+6Ch] [ebp-2CD0h]
  FLDirListStruct *v39; // [esp+70h] [ebp-2CCCh]
  _DWORD *v40; // [esp+74h] [ebp-2CC8h]
  FLDirListStruct *v41; // [esp+78h] [ebp-2CC4h]
  signed int v42; // [esp+7Ch] [ebp-2CC0h]
  FLDirListStruct *v43; // [esp+80h] [ebp-2CBCh]
  FLDirListStruct *v44; // [esp+84h] [ebp-2CB8h]
  BOOL v45; // [esp+88h] [ebp-2CB4h]
  int v46; // [esp+8Ch] [ebp-2CB0h]
  FLDirListStruct *v47; // [esp+90h] [ebp-2CACh]
  FLDirListStruct *v48; // [esp+94h] [ebp-2CA8h]
  const void *v49; // [esp+98h] [ebp-2CA4h]
  unsigned int v50; // [esp+9Ch] [ebp-2CA0h]
  DWORD v51; // [esp+A0h] [ebp-2C9Ch]
  CHAR *v52; // [esp+A4h] [ebp-2C98h]
  int v53; // [esp+A8h] [ebp-2C94h]
  FLDirListStruct *v54; // [esp+ACh] [ebp-2C90h]
  FLFileListStruct *v55; // [esp+B0h] [ebp-2C8Ch]
  FLFileListStruct *v56; // [esp+B4h] [ebp-2C88h]
  _DWORD v57[3]; // [esp+B8h] [ebp-2C84h] BYREF
  int v58; // [esp+C4h] [ebp-2C78h]
  int v59; // [esp+C8h] [ebp-2C74h]
  int v60; // [esp+CCh] [ebp-2C70h]
  int v61; // [esp+D0h] [ebp-2C6Ch]
  void *v62; // [esp+D4h] [ebp-2C68h]
  LPCVOID lpBuffer; // [esp+D8h] [ebp-2C64h]
  int v64; // [esp+DCh] [ebp-2C60h]
  HANDLE hFile; // [esp+E0h] [ebp-2C5Ch]
  HANDLE hFindFile; // [esp+E4h] [ebp-2C58h]
  FLFileListStruct *v67; // [esp+E8h] [ebp-2C54h]
  FLDirListStruct *v68; // [esp+ECh] [ebp-2C50h]
  signed int v69; // [esp+F0h] [ebp-2C4Ch]
  size_t v70; // [esp+F4h] [ebp-2C48h] BYREF
  char *Str; // [esp+F8h] [ebp-2C44h]
  int v72; // [esp+FCh] [ebp-2C40h]
  int v73; // [esp+100h] [ebp-2C3Ch]
  int v74; // [esp+104h] [ebp-2C38h]
  wchar_t *Source; // [esp+108h] [ebp-2C34h]
  DWORD NumberOfBytesWritten; // [esp+10Ch] [ebp-2C30h] BYREF
  int v77; // [esp+110h] [ebp-2C2Ch]
  int v78; // [esp+114h] [ebp-2C28h]
  BOOL v79; // [esp+118h] [ebp-2C24h]
  int v80; // [esp+11Ch] [ebp-2C20h]
  int v81; // [esp+120h] [ebp-2C1Ch]
  int i; // [esp+124h] [ebp-2C18h]
  int v83; // [esp+128h] [ebp-2C14h]
  FLDirListStruct *v84; // [esp+12Ch] [ebp-2C10h]
  _WORD *v85; // [esp+130h] [ebp-2C0Ch]
  FLDirListStruct *j; // [esp+134h] [ebp-2C08h]
  HANDLE hObject; // [esp+138h] [ebp-2C04h]
  int m; // [esp+13Ch] [ebp-2C00h]
  _DWORD *v89; // [esp+140h] [ebp-2BFCh]
  FLDirListStruct *v90; // [esp+144h] [ebp-2BF8h]
  int v91; // [esp+148h] [ebp-2BF4h]
  FLDirListStruct *v92; // [esp+14Ch] [ebp-2BF0h]
  FLFileListStruct *k; // [esp+150h] [ebp-2BECh]
  int n; // [esp+154h] [ebp-2BE8h]
  char v95; // [esp+15Bh] [ebp-2BE1h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+15Ch] [ebp-2BE0h] BYREF
  char v97[88]; // [esp+3ACh] [ebp-2990h] BYREF
  char v98[88]; // [esp+404h] [ebp-2938h] BYREF
  _BYTE v99[28]; // [esp+45Ch] [ebp-28E0h] BYREF
  _BYTE v100[28]; // [esp+478h] [ebp-28C4h] BYREF
  _BYTE v101[28]; // [esp+494h] [ebp-28A8h] BYREF
  _BYTE v102[28]; // [esp+4B0h] [ebp-288Ch] BYREF
  _BYTE v103[28]; // [esp+4CCh] [ebp-2870h] BYREF
  int v104[7]; // [esp+4E8h] [ebp-2854h] BYREF
  int v105; // [esp+504h] [ebp-2838h]
  int v106; // [esp+508h] [ebp-2834h]
  CHAR Text[2048]; // [esp+50Ch] [ebp-2830h] BYREF
  CHAR v108[1024]; // [esp+D0Ch] [ebp-2030h] BYREF
  CHAR v109[1024]; // [esp+110Ch] [ebp-1C30h] BYREF
  char v110[4096]; // [esp+150Ch] [ebp-1830h] BYREF
  WCHAR FileName[260]; // [esp+250Ch] [ebp-830h] BYREF
  WCHAR Buffer[260]; // [esp+2714h] [ebp-628h] BYREF
  wchar_t Destination[260]; // [esp+291Ch] [ebp-420h] BYREF
  wchar_t String[260]; // [esp+2B24h] [ebp-218h] BYREF
  int v115; // [esp+2D38h] [ebp-4h]

  v89 = this;
  if ( !this[5] )
    return 1;
  v91 = v89[5];
  v68 = 0;
  v84 = 0;
  v67 = 0;
  v74 = 0;
  v83 = 0;
  v95 = 0;
  while ( v91 && !v95 )
  {
    v47 = (FLDirListStruct *)operator new(0x10u);
    v115 = 0;
    if ( v47 )
      v34 = FLDirListStruct::FLDirListStruct(v47);
    else
      v34 = 0;
    v33 = v34;
    v115 = -1;
    v92 = v34;
    v77 = *(_DWORD *)(v91 + 12);
    while ( v92 )
    {
      v35 = 0;
      Destination[0] = 0;
      if ( *(_DWORD *)(v91 + 8) )
      {
        Source = *(wchar_t **)(v91 + 8);
        if ( *Source == 92 )
          ++Source;
        j__wcscpy(Destination, Source);
        v69 = j__wcslen(Destination) - 1;
        if ( v69 > 0 && Destination[v69] == 92 )
        {
          v36 = 2 * v69;
          if ( (unsigned int)(2 * v69) >= 0x208 )
            j____report_rangecheckfailure();
          Destination[v36 / 2] = 0;
        }
      }
      for ( i = 0; i < 2; ++i )
      {
        if ( !v95 )
        {
          v78 = -1;
          v46 = i;
          if ( i )
          {
            if ( v46 == 1 )
            {
              if ( *(_DWORD *)v92 )
              {
                swprintf((char *)Buffer, (char *)L"%s\\%s\\%s", *(_DWORD *)v91);
                v81 = 0;
              }
              else
              {
                swprintf((char *)Buffer, (char *)L"%s\\%s", *(_DWORD *)v91);
                v81 = 1;
              }
            }
          }
          else if ( *(_DWORD *)v92 )
          {
            swprintf((char *)Buffer, (char *)L"%s\\%s\\*", *(_DWORD *)v91);
            v81 = 0;
          }
          else
          {
            swprintf((char *)Buffer, (char *)L"%s\\*", *(_DWORD *)v91);
            v81 = 1;
          }
          if ( Destination[0] )
            v81 = 0;
          hFindFile = FindFirstFileW(Buffer, &FindFileData);
          if ( hFindFile != (HANDLE)-1 )
          {
            if ( *(_DWORD *)v92 )
              swprintf((char *)String, (char *)L"%s\\%s", *(_DWORD *)v91);
            else
              swprintf((char *)String, (char *)L"%s", *(_DWORD *)v91);
            v37 = (FLDirListStruct *)operator new(0x10u);
            v115 = 1;
            if ( v37 )
              v38 = FLDirListStruct::FLDirListStruct(v37);
            else
              v38 = 0;
            v115 = -1;
            v90 = v38;
            v6 = j__wcslen(String);
            *(_DWORD *)v38 = operator new[](2 * (v6 + 1));
            j__wcscpy(*(wchar_t **)v90, String);
            if ( *(_DWORD *)v92 )
              swprintf((char *)String, (char *)L"Root: \"%s\"\n  Directory: \"\\%s\\%s\"", *(_DWORD *)v91);
            else
              swprintf((char *)String, (char *)L"Root: \"%s\"\n  Directory: \"\\%s\\\"", *(_DWORD *)v91);
            v7 = j__wcslen(String);
            *((_DWORD *)v90 + 1) = operator new[](2 * (v7 + 1));
            j__wcscpy(*((wchar_t **)v90 + 1), String);
            *((_DWORD *)v90 + 3) = v84;
            v84 = v90;
            if ( !v81 )
            {
              v80 = v89[6];
              if ( *(_DWORD *)v92 )
              {
                if ( Destination[0] )
                  swprintf((char *)String, (char *)L"%s\\%s", (char)Destination);
                else
                  swprintf((char *)String, (char *)L"%s", *(_DWORD *)v92);
              }
              else
              {
                swprintf((char *)String, (char *)L"%s", (char)Destination);
              }
              while ( v80 )
              {
                if ( !j___wcsicmp(String, *(const wchar_t **)v80) )
                {
                  v78 = *(_DWORD *)(v80 + 8);
                  break;
                }
                v80 = *(_DWORD *)(v80 + 12);
              }
              if ( v78 == -1 )
              {
                v39 = (FLDirListStruct *)operator new(0x10u);
                v115 = 2;
                if ( v39 )
                  v41 = FLDirListStruct::FLDirListStruct(v39);
                else
                  v41 = 0;
                v30 = v41;
                v115 = -1;
                v90 = v41;
                v8 = j__wcslen(String);
                v21 = operator new[](2 * (v8 + 1));
                *(_DWORD *)v41 = v21;
                *((_DWORD *)v90 + 2) = v74;
                j__wcscpy(*(wchar_t **)v90, String);
                if ( v68 )
                  *((_DWORD *)v68 + 3) = v90;
                else
                  v89[6] = v90;
                v68 = v90;
                v78 = v74++;
              }
            }
            do
            {
              if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
              {
                if ( !i )
                {
                  v79 = (v77 & 1) != 0;
                  if ( (v77 & 2) != 0 && FindFileData.cFileName[0] == 33 )
                    v79 = 1;
                  v42 = j__wcslen(FindFileData.cFileName);
                  if ( v42 >= 6 && !j___wcsicmp((const wchar_t *)&FindFileData.nFileSizeLow + v42 + 1, L".work") )
                    v79 = 1;
                  if ( !j__wcscmp(FindFileData.cFileName, L".") || !j__wcscmp(FindFileData.cFileName, L"..") )
                    v79 = 1;
                  if ( !v79 )
                  {
                    for ( j = v92; *((_DWORD *)j + 3); j = (FLDirListStruct *)*((_DWORD *)j + 3) )
                      ;
                    if ( *(_DWORD *)v92 )
                      swprintf((char *)String, (char *)L"%s\\%s", *(_DWORD *)v92);
                    else
                      swprintf((char *)String, (char *)L"%s", (char)FindFileData.cFileName);
                    v43 = (FLDirListStruct *)operator new(0x10u);
                    v115 = 3;
                    if ( v43 )
                      v44 = FLDirListStruct::FLDirListStruct(v43);
                    else
                      v44 = 0;
                    v22 = v44;
                    v115 = -1;
                    *((_DWORD *)j + 3) = v44;
                    j = (FLDirListStruct *)*((_DWORD *)j + 3);
                    v9 = j__wcslen(String);
                    v29 = operator new[](2 * (v9 + 1));
                    *(_DWORD *)j = v29;
                    j__wcscpy(*(wchar_t **)j, String);
                  }
                }
              }
              else if ( i == 1 )
              {
                v45 = 0;
                if ( (v77 & 2) != 0 )
                  v45 = FindFileData.cFileName[0] == 33;
                if ( !v45 )
                {
                  for ( k = (FLFileListStruct *)v89[7]; k; k = (FLFileListStruct *)*((_DWORD *)k + 5) )
                  {
                    if ( !j___wcsicmp(*(const wchar_t **)k, FindFileData.cFileName) && *((_DWORD *)k + 1) == v78 )
                    {
                      v83 = 4;
                      v40 = (_DWORD *)*((_DWORD *)k + 4);
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v98);
                      v115 = 4;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v101,
                        v40[1]);
                      LOBYTE(v115) = 5;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v100,
                        *v40);
                      LOBYTE(v115) = 6;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v103,
                        *((_DWORD *)v84 + 1));
                      LOBYTE(v115) = 7;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v102,
                        FindFileData.cFileName);
                      v18 = (const char *)std::string::c_str(v102);
                      v17 = (const char *)std::string::c_str(v103);
                      v16 = (const char *)std::string::c_str(v100);
                      v10 = (const char *)std::string::c_str(v101);
                      j__sprintf(
                        Text,
                        "The same file names were found:\n\n%s\n  File: \"%s\"\n\n%s\n  File: \"%s\"\n",
                        v10,
                        v16,
                        v17,
                        v18);
                      v28 = MessageBoxA(0, Text, "Error Creating File Library", 0x31u);
                      if ( v28 == 2 )
                        v95 = 1;
                      std::string::~string(v102);
                      LOBYTE(v115) = 6;
                      std::string::~string(v103);
                      LOBYTE(v115) = 5;
                      std::string::~string(v100);
                      LOBYTE(v115) = 4;
                      std::string::~string(v101);
                      v115 = -1;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v98);
                      break;
                    }
                  }
                  v56 = (FLFileListStruct *)operator new(0x18u);
                  v115 = 8;
                  if ( v56 )
                    v55 = FLFileListStruct::FLFileListStruct(v56);
                  else
                    v55 = 0;
                  v27 = v55;
                  v115 = -1;
                  k = v55;
                  v11 = j__wcslen(FindFileData.cFileName);
                  v26 = operator new[](2 * (v11 + 1));
                  *(_DWORD *)v55 = v26;
                  j__wcscpy(*(wchar_t **)k, FindFileData.cFileName);
                  *((_DWORD *)k + 1) = v78;
                  *((_DWORD *)k + 3) = FindFileData.nFileSizeLow;
                  if ( (v77 & 4) != 0 )
                    *((_DWORD *)k + 2) = 1;
                  if ( (v77 & 8) != 0 )
                    *((_DWORD *)k + 2) |= 2u;
                  *((_DWORD *)k + 4) = v84;
                  if ( v67 )
                    *((_DWORD *)v67 + 5) = k;
                  else
                    v89[7] = k;
                  v67 = k;
                }
              }
              NextFileW = FindNextFileW(hFindFile, &FindFileData);
            }
            while ( NextFileW && !v95 );
            FindClose(hFindFile);
          }
        }
      }
      v24 = v92;
      v92 = (FLDirListStruct *)*((_DWORD *)v92 + 3);
      v23 = v24;
      v54 = v24;
      if ( v24 )
        FLDirListStruct::`scalar deleting destructor'(v54, 1u);
    }
    v91 = *(_DWORD *)(v91 + 16);
  }
  if ( !v83 && !v95 )
  {
    hObject = CreateFileW(lpFileName, 0xC0000000, 0, 0, 2u, 0x80u, 0);
    if ( hObject == (HANDLE)-1 )
    {
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v97);
      v115 = 10;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
        v99,
        lpFileName);
      v15 = (const char *)std::string::c_str(v99);
      j__sprintf(v109, "Error Creating File Library file: \"%s\"", v15);
      MessageBoxA(0, v109, "Error Creating File Library", 0x10u);
      v83 = 3;
      std::string::~string(v99);
      v115 = -1;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v97);
    }
    else
    {
      FLHeaderStruct::FLHeaderStruct((FLHeaderStruct *)v57);
      v57[1] = 4097;
      v53 = 0;
      v110[0] = 0;
      if ( a3 )
        v52 = a3;
      else
        v52 = v110;
      Str = v52;
      if ( (a4 & 1) != 0 )
      {
        Str = v110;
        hFile = CreateFileA(a3, 0x80000000, 0, 0, 3u, 0x80u, 0);
        if ( hFile == (HANDLE)-1 )
        {
          j__strcpy_0(v110, "\n\nComment File Not Found !!!!\n\n");
        }
        else
        {
          ReadFile(hFile, v110, 0xFFFu, &NumberOfBytesRead, 0);
          v51 = NumberOfBytesRead;
          if ( NumberOfBytesRead >= 0x1000 )
            j____report_rangecheckfailure();
          v110[v51] = 0;
          CloseHandle(hFile);
        }
      }
      v72 = 0;
      v58 = 0;
      for ( m = v89[6]; m; m = *(_DWORD *)(m + 12) )
      {
        ++v58;
        v72 += j__wcslen(*(const wchar_t **)m) + 1;
      }
      v73 = 0;
      v60 = 0;
      for ( n = v89[7]; n; n = *(_DWORD *)(n + 20) )
      {
        ++v60;
        v73 += j__wcslen(*(const wchar_t **)n) + 1;
      }
      v64 = 0;
      for ( n = v89[7]; n; n = *(_DWORD *)(n + 20) )
        v64 += *(_DWORD *)(n + 12);
      v57[0] = v73 + v72 + 24;
      v57[0] += 24 * v60;
      v59 = v73;
      v57[2] = v72;
      v104[3] = v64;
      v104[2] = 0;
      v104[5] = v60;
      v104[4] = 0;
      v12 = j__strlen(Str);
      WriteFile(hObject, Str, v12 + 1, &NumberOfBytesWritten, 0);
      v70 = j__strlen(Str) + 1;
      n = v89[7];
      v50 = v60;
      v62 = operator new[](24 * v60);
      v115 = 9;
      if ( v62 )
      {
        `vector constructor iterator'(
          v62,
          0x18u,
          v50,
          (void *(__thiscall *)(void *))FLHeaderFileStruct::FLHeaderFileStruct);
        v49 = v62;
      }
      else
      {
        v49 = 0;
      }
      v115 = -1;
      lpBuffer = v49;
      v85 = v49;
      while ( n )
      {
        *(_DWORD *)v85 = v70;
        v85[6] = *(_WORD *)(n + 4);
        *((_DWORD *)v85 + 4) = *(_DWORD *)(n + 8);
        swprintf((char *)FileName, (char *)L"%s\\%s", **(_DWORD **)(n + 16));
        v104[1] = *(_DWORD *)(n + 12);
        v104[6] = *(_DWORD *)(n + 8);
        v61 = CFileLibrary::pC_CopyFile(FileName, (int)hObject, nNumberOfBytesToRead, (int)v104);
        if ( v61 )
        {
          if ( v61 == 5 )
          {
            j__sprintf(v108, "Error copying file data into a file library.\nThere is not enough space on the disk !!!!");
            MessageBoxA(0, v108, "Error Creating File Library", 0x10u);
          }
          v83 = v61;
          break;
        }
        *((_DWORD *)v85 + 2) = *(_DWORD *)(n + 12);
        *((_DWORD *)v85 + 1) = v105;
        *((_DWORD *)v85 + 5) = v106;
        v70 += v105;
        n = *(_DWORD *)(n + 20);
        v85 += 12;
      }
      WriteFile(hObject, v57, 0x18u, &NumberOfBytesWritten, 0);
      for ( m = v89[6]; m; m = *(_DWORD *)(m + 12) )
      {
        v13 = j__wcslen(*(const wchar_t **)m);
        WriteFile(hObject, *(LPCVOID *)m, v13 + 1, &NumberOfBytesWritten, 0);
      }
      for ( n = v89[7]; n; n = *(_DWORD *)(n + 20) )
      {
        v14 = j__wcslen(*(const wchar_t **)n);
        WriteFile(hObject, *(LPCVOID *)n, v14 + 1, &NumberOfBytesWritten, 0);
      }
      WriteFile(hObject, lpBuffer, 24 * v60, &NumberOfBytesWritten, 0);
      operator delete[]((void *)lpBuffer);
      WriteFile(hObject, &v70, 4u, &NumberOfBytesWritten, 0);
      CloseHandle(hObject);
    }
  }
  while ( v84 )
  {
    v19 = v84;
    v84 = (FLDirListStruct *)*((_DWORD *)v84 + 3);
    v32 = v19;
    v48 = v19;
    v31 = FLDirListStruct::`scalar deleting destructor'(v19, 1u);
  }
  if ( v95 )
  {
    BBSupportTracePrintF(3, "CFileLibrary::C_CreateFileLibrary\t:\tFailed to create lib %s", (const char *)lpFileName);
    return 2;
  }
  else if ( v83 )
  {
    BBSupportTracePrintF(
      3,
      "CFileLibrary::C_CreateFileLibrary\t:\tFailed to create lib %s, %i",
      (const char *)lpFileName,
      v83);
    return v83;
  }
  else
  {
    return 0;
  }
}


// address=[0x2f0d650]
// Decompiled from CFileLibrary *__thiscall CFileLibrary::CFileLibrary(CFileLibrary *this, int a2)
 CFileLibrary::CFileLibrary(int) {
  
  FLFHandleStruct *v3; // [esp+Ch] [ebp-28h]
  FLFHandleStruct *v4; // [esp+10h] [ebp-24h]
  FLFHandleStruct *v5; // [esp+14h] [ebp-20h]
  FLFHandleStruct *C; // [esp+18h] [ebp-1Ch]
  int v7; // [esp+1Ch] [ebp-18h]
  int i; // [esp+1Ch] [ebp-18h]
  int v9; // [esp+20h] [ebp-14h]

  std::vector<std::pair<std::wstring,int>>::vector<std::pair<std::wstring,int>>();
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 116) = 0;
  *((_DWORD *)this + 117) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 118) = 0;
  *((_DWORD *)this + 8) = 0;
  if ( a2 >= 2 )
    *((_DWORD *)this + 9) = a2;
  else
    *((_DWORD *)this + 9) = 4;
  v7 = a2;
  v9 = 0;
  while ( v7 )
  {
    if ( v9 )
    {
      v4 = (FLFHandleStruct *)operator new(0xCu);
      if ( v4 )
        v3 = FLFHandleStruct::FLFHandleStruct(v4);
      else
        v3 = 0;
      *(_DWORD *)(v9 + 8) = v3;
      *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4) = v9;
      v9 = *(_DWORD *)(v9 + 8);
    }
    else
    {
      C = (FLFHandleStruct *)operator new(0xCu);
      if ( C )
        v5 = FLFHandleStruct::FLFHandleStruct(C);
      else
        v5 = 0;
      *((_DWORD *)this + 115) = v5;
      v9 = *((_DWORD *)this + 115);
    }
    --v7;
  }
  *((_DWORD *)this + 114) = v9;
  for ( i = 0; i < 100; ++i )
    *((_DWORD *)this + i + 14) = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  CFileLibrary::InitFileLibraries(this);
  return this;
}


// address=[0x2f0d880]
// Decompiled from int __thiscall CFileLibrary::~CFileLibrary(CFileLibrary *this)
 CFileLibrary::~CFileLibrary(void) {
  
  _DWORD *v2; // [esp+8h] [ebp-18h]
  int i; // [esp+Ch] [ebp-14h]

  for ( i = 0; i < *((_DWORD *)this + 10); ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 116) + 24 * i + 8) )
    {
      UnmapViewOfFile(*(LPCVOID *)(*((_DWORD *)this + 116) + 24 * i + 8));
      CloseHandle(*(HANDLE *)(*((_DWORD *)this + 116) + 24 * i + 12));
      *(_DWORD *)(*((_DWORD *)this + 116) + 24 * i + 8) = 0;
    }
  }
  CFileLibrary::pFreeFLCreationData(this);
  CFileLibrary::pFreeFLData(this);
  while ( *((_DWORD *)this + 115) )
  {
    v2 = (_DWORD *)*((_DWORD *)this + 115);
    *((_DWORD *)this + 115) = v2[2];
    operator delete(v2);
  }
  return std::vector<std::pair<std::wstring,int>>::~vector<std::pair<std::wstring,int>>();
}


// address=[0x2f08050]
// Decompiled from char __stdcall CFileLibrary::pCutPathAndFilename(wchar_t *String, wchar_t *Destination, wchar_t *a3)
bool  CFileLibrary::pCutPathAndFilename(wchar_t const *,wchar_t *,wchar_t *) {
  
  int v4; // [esp+8h] [ebp-8h]
  signed int i; // [esp+Ch] [ebp-4h]
  int v6; // [esp+Ch] [ebp-4h]

  j__wcslen(String);
  if ( *String == 92 )
    j__wcscpy(Destination, String + 1);
  else
    j__wcscpy(Destination, String);
  v4 = 0;
  for ( i = j__wcslen(Destination) - 1; i >= 0 && Destination[i] != 92; --i )
    ++v4;
  if ( v4 )
  {
    v6 = j__wcslen(Destination) - v4;
    if ( v6 > 1 )
    {
      j__memmove(a3, &Destination[v6], v4 + 1);
      Destination[v6 - 1] = 0;
    }
    else
    {
      j__wcscpy(a3, Destination);
      *Destination = 0;
    }
    return 1;
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::pCutPathAndFilename\t:\tcouldn't get file name, %s", (const char *)String);
    return 0;
  }
}


// address=[0x2f08230]
// Decompiled from int __thiscall CFileLibrary::pGetFileLibraryHandle(CFileLibrary *this, int a2)
void *  CFileLibrary::pGetFileLibraryHandle(int) {
  
  struct FLFHandleStruct *j; // [esp+4h] [ebp-10h]
  int *i; // [esp+8h] [ebp-Ch]
  int hFile; // [esp+Ch] [ebp-8h]
  HANDLE hFilea; // [esp+Ch] [ebp-8h]
  HANDLE hFileb; // [esp+Ch] [ebp-8h]

  if ( a2 < 0 || a2 >= *((_DWORD *)this + 10) )
    return -1;
  if ( *(_DWORD *)(*((_DWORD *)this + 116) + 24 * a2 + 4) )
    hFile = *(_DWORD *)(*((_DWORD *)this + 116) + 24 * a2 + 4);
  else
    hFile = -1;
  if ( hFile == -1 )
  {
    if ( *((_DWORD *)this + 9) )
    {
      for ( i = (int *)*((_DWORD *)this + 115); i && *i != -1; i = (int *)i[2] )
        ;
      if ( *i == -1 )
      {
        hFilea = CreateFileW(*(LPCWSTR *)(*((_DWORD *)this + 116) + 24 * a2), 0x80000000, 1u, 0, 3u, 0x80u, 0);
        if ( hFilea == (HANDLE)-1 )
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::pGetFileLibraryHandle\t:\tFailed to open lib file %s ",
            *(const char **)(*((_DWORD *)this + 116) + 24 * a2));
          return -1;
        }
        else
        {
          *(_DWORD *)(*((_DWORD *)this + 116) + 24 * a2 + 4) = hFilea;
          *(_DWORD *)(*((_DWORD *)this + 116) + 24 * a2 + 20) = GetFileSize(hFilea, 0);
          *i = a2;
          --*((_DWORD *)this + 9);
          CFileLibrary::pMoveHandleToBeginning(this, (struct FLFHandleStruct *)i);
          return (int)hFilea;
        }
      }
      else
      {
        return -1;
      }
    }
    else
    {
      hFileb = CreateFileW(*(LPCWSTR *)(*((_DWORD *)this + 116) + 24 * a2), 0x80000000, 1u, 0, 3u, 0x80u, 0);
      if ( hFileb == (HANDLE)-1 )
      {
        BBSupportTracePrintF(
          3,
          "CFileLibrary::pGetFileLibraryHandle\t:\tFailed to open lib file %s ",
          *(const char **)(*((_DWORD *)this + 116) + 24 * a2));
        return -1;
      }
      else
      {
        CloseHandle(*(HANDLE *)(*((_DWORD *)this + 116) + 24 * **((_DWORD **)this + 114) + 4));
        **((_DWORD **)this + 114) = a2;
        *(_DWORD *)(*((_DWORD *)this + 116) + 24 * a2 + 4) = hFileb;
        CFileLibrary::pMoveHandleToBeginning(this, *((struct FLFHandleStruct **)this + 114));
        return (int)hFileb;
      }
    }
  }
  else
  {
    for ( j = (struct FLFHandleStruct *)*((_DWORD *)this + 115);
          j && *(_DWORD *)j != a2;
          j = (struct FLFHandleStruct *)*((_DWORD *)j + 2) )
    {
      ;
    }
    CFileLibrary::pMoveHandleToBeginning(this, j);
    return hFile;
  }
}


// address=[0x2f08480]
// Decompiled from int __stdcall CFileLibrary::pC_CopyFile(LPCWSTR lpFileName, HANDLE a2, signed int nNumberOfBytesToRead, DWORD *a4)
int  CFileLibrary::pC_CopyFile(wchar_t const *,void *,int,struct FLCopyProgressStruct *) {
  
  DWORD NumberOfBytesRead; // [esp+14h] [ebp-14h] BYREF
  int v6; // [esp+18h] [ebp-10h]
  LPVOID lpBuffer; // [esp+1Ch] [ebp-Ch]
  HANDLE hFile; // [esp+20h] [ebp-8h]
  DWORD NumberOfBytesWritten; // [esp+24h] [ebp-4h] BYREF

  hFile = CreateFileW(lpFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
  if ( hFile == (HANDLE)-1 )
  {
    BBSupportTracePrintF(3, "CFileLibrary::pC_CopyFile\t:\tFile not found %s", (const char *)lpFileName);
    return 6;
  }
  v6 = 6;
  if ( (a4[6] & 1) != 0 )
  {
    if ( (a4[6] & 2) != 0 )
      NumberOfBytesWritten = CFileLibrary::pC_PackFile(a2, hFile, (int)(a4 + 8), 1);
    else
      NumberOfBytesWritten = CFileLibrary::pC_PackFile(a2, hFile, (int)(a4 + 8), 0);
    if ( !NumberOfBytesWritten )
      return 6;
    a4[7] = NumberOfBytesWritten;
    *a4 = NumberOfBytesWritten;
    a4[2] += NumberOfBytesWritten;
    ++a4[4];
    v6 = 0;
  }
  else
  {
    if ( nNumberOfBytesToRead >= 0x4000 )
      lpBuffer = operator new[](nNumberOfBytesToRead);
    else
      lpBuffer = operator new[](0x4000u);
    *a4 = 0;
    a4[7] = 0;
    while ( ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0) )
    {
      if ( !NumberOfBytesRead )
      {
        ++a4[4];
        v6 = 0;
        break;
      }
      WriteFile(a2, lpBuffer, NumberOfBytesRead, &NumberOfBytesWritten, 0);
      if ( NumberOfBytesWritten < NumberOfBytesRead )
      {
        v6 = 5;
        break;
      }
      a4[7] += NumberOfBytesWritten;
      *a4 += NumberOfBytesWritten;
      a4[2] += NumberOfBytesWritten;
    }
    a4[8] = 0;
    operator delete[](lpBuffer);
  }
  CloseHandle(hFile);
  return v6;
}


// address=[0x2f08690]
// Decompiled from DWORD __thiscall CFileLibrary::pC_PackFile(CFileLibrary *this, HANDLE a2, HANDLE hFile, _DWORD *a4, char a5)
int  CFileLibrary::pC_PackFile(void *,void *,unsigned int *,bool) {
  
  DWORD NumberOfBytesWritten; // [esp+8h] [ebp-2Ch] BYREF
  CFileLibrary *v7; // [esp+Ch] [ebp-28h]
  void *v8; // [esp+10h] [ebp-24h]
  size_t Size; // [esp+14h] [ebp-20h]
  LPVOID v10; // [esp+18h] [ebp-1Ch]
  int v11; // [esp+1Ch] [ebp-18h]
  DWORD NumberOfBytesRead; // [esp+20h] [ebp-14h] BYREF
  LPVOID lpBuffer; // [esp+24h] [ebp-10h]
  DWORD nNumberOfBytesToRead; // [esp+28h] [ebp-Ch]
  LPCVOID v15; // [esp+2Ch] [ebp-8h]
  DWORD nNumberOfBytesToWrite; // [esp+30h] [ebp-4h]

  v7 = this;
  v11 = j__LZHLCreateCompressor(this);
  nNumberOfBytesToWrite = 0;
  nNumberOfBytesToRead = GetFileSize(hFile, 0);
  Size = j__LZHLCompressorCalcMaxBuf(nNumberOfBytesToRead);
  v10 = operator new[](nNumberOfBytesToRead);
  lpBuffer = v10;
  v8 = operator new[](Size);
  v15 = v8;
  ReadFile(hFile, v10, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
  if ( NumberOfBytesRead == nNumberOfBytesToRead )
  {
    nNumberOfBytesToWrite = 0;
    nNumberOfBytesToWrite = j__LZHLCompress(v11, v15, lpBuffer, NumberOfBytesRead);
    if ( a5 )
      CFileLibrary::DataCryptor((void *)v15, nNumberOfBytesToWrite);
    *a4 = CFileLibrary::CRC(v7, (void *)v15, nNumberOfBytesToWrite);
    WriteFile(a2, v15, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0);
    if ( NumberOfBytesWritten == nNumberOfBytesToWrite )
    {
      j__LZHLDestroyCompressor(v11);
      operator delete[](lpBuffer);
      operator delete[]((void *)v15);
      return nNumberOfBytesToWrite;
    }
    else
    {
      BBSupportTracePrintF(3, "CFileLibrary::pC_PackFile : Could't write complete file.");
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::pC_PackFile : Could't read complete file.");
    return 0;
  }
}


// address=[0x2f087f0]
// Decompiled from int __thiscall CFileLibrary::UnpackData(CFileLibrary *this, char *a2, int a3, char *a4, int a5, bool a6)
int  CFileLibrary::UnpackData(char *,int,char *,int,bool) {
  
  _DWORD v7[5]; // [esp+0h] [ebp-38h] BYREF
  int v8; // [esp+14h] [ebp-24h]
  int v9; // [esp+1Ch] [ebp-1Ch] BYREF
  int v10; // [esp+20h] [ebp-18h] BYREF
  int v11; // [esp+24h] [ebp-14h]
  _DWORD *v12; // [esp+28h] [ebp-10h]
  int v13; // [esp+34h] [ebp-4h]

  v12 = v7;
  v7[4] = this;
  if ( a6 )
    CFileLibrary::DataCryptor(a4, a5);
  v10 = a5;
  v9 = a3;
  v11 = j__LZHLCreateDecompressor(v7[0], v7[1]);
  v13 = 0;
  v8 = j__LZHLDecompress(v11, a2, &v9, a4, &v10);
  v13 = -1;
  j__LZHLDestroyDecompressor(v11);
  if ( v8 )
    return a3;
  BBSupportTracePrintF(3, "CStringEngine::ImportFile : Error during decompressing text file. No strings loaded. ");
  return 0;
}


// address=[0x2f08fb0]
// Decompiled from CFileLibrary *__thiscall CFileLibrary::pFreeFLCreationData(CFileLibrary *this)
void  CFileLibrary::pFreeFLCreationData(void) {
  
  CFileLibrary *result; // eax
  FLFileListStruct *v2; // [esp+8h] [ebp-2Ch]
  FLDirListStruct *v3; // [esp+14h] [ebp-20h]
  FLPathListStruct *v4; // [esp+20h] [ebp-14h]

  while ( *((_DWORD *)this + 5) )
  {
    v4 = (FLPathListStruct *)*((_DWORD *)this + 5);
    *((_DWORD *)this + 5) = *((_DWORD *)v4 + 4);
    if ( v4 )
      FLPathListStruct::`scalar deleting destructor'(v4, 1u);
  }
  while ( *((_DWORD *)this + 6) )
  {
    v3 = (FLDirListStruct *)*((_DWORD *)this + 6);
    *((_DWORD *)this + 6) = *((_DWORD *)v3 + 3);
    if ( v3 )
      FLDirListStruct::`scalar deleting destructor'(v3, 1u);
  }
  while ( 1 )
  {
    result = this;
    if ( !*((_DWORD *)this + 7) )
      break;
    v2 = (FLFileListStruct *)*((_DWORD *)this + 7);
    *((_DWORD *)this + 7) = *((_DWORD *)v2 + 5);
    if ( v2 )
      FLFileListStruct::`scalar deleting destructor'(v2, 1u);
  }
  return result;
}


// address=[0x2f090a0]
// Decompiled from CFileLibrary *__thiscall CFileLibrary::pFreeFLData(CFileLibrary *this)
void  CFileLibrary::pFreeFLData(void) {
  
  CFileLibrary *result; // eax
  FLIntHandleStruct *v2; // [esp+8h] [ebp-48h]
  HANDLE hObject; // [esp+2Ch] [ebp-24h]
  int k; // [esp+30h] [ebp-20h]
  FLIntHandleStruct *v5; // [esp+34h] [ebp-1Ch]
  _DWORD *m; // [esp+38h] [ebp-18h]
  void **v7; // [esp+3Ch] [ebp-14h]
  int v8; // [esp+40h] [ebp-10h]
  int v9; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  int j; // [esp+48h] [ebp-8h]
  int n; // [esp+48h] [ebp-8h]

  v9 = *((_DWORD *)this + 116);
  for ( i = 0; i < *((_DWORD *)this + 10); ++i )
  {
    if ( *(_DWORD *)v9 )
      operator delete(*(void **)v9);
    *(_DWORD *)v9 = 0;
    if ( *(_DWORD *)(v9 + 4) )
    {
      hObject = *(HANDLE *)(v9 + 4);
      if ( hObject != (HANDLE)-1 )
        CloseHandle(hObject);
      *(_DWORD *)(v9 + 4) = -1;
    }
    v9 += 24;
  }
  if ( *((_DWORD *)this + 116) )
    operator delete[](*((void **)this + 116));
  *((_DWORD *)this + 116) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 10) = 0;
  v8 = *((_DWORD *)this + 117);
  for ( j = 0; j < *((_DWORD *)this + 13); ++j )
  {
    if ( *(_DWORD *)v8 )
      operator delete[](*(void **)v8);
    v7 = *(void ***)(v8 + 12);
    for ( k = 0; k < *(__int16 *)(v8 + 6); ++k )
    {
      if ( *v7 )
        operator delete[](*v7);
      if ( v7[7] )
      {
        operator delete[](v7[7]);
        v7[7] = 0;
      }
      v7 += 8;
    }
    if ( *(_DWORD *)(v8 + 12) )
      operator delete[](*(void **)(v8 + 12));
    v8 += 16;
  }
  if ( *((_DWORD *)this + 117) )
    operator delete[](*((void **)this + 117));
  *((_DWORD *)this + 117) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 12) = 0;
  for ( m = (_DWORD *)*((_DWORD *)this + 115); m; m = (_DWORD *)m[2] )
    *m = -1;
  for ( n = 0; n < 100; ++n )
  {
    v5 = (FLIntHandleStruct *)*((_DWORD *)this + n + 14);
    while ( v5 )
    {
      v2 = v5;
      v5 = (FLIntHandleStruct *)*((_DWORD *)v5 + 6);
      FLIntHandleStruct::`scalar deleting destructor'(v2, 1u);
    }
    *((_DWORD *)this + n + 14) = 0;
  }
  result = this;
  *((_DWORD *)this + 8) = 0;
  return result;
}


// address=[0x2f09350]
// Decompiled from CFileLibrary *__thiscall CFileLibrary::pOptimize(CFileLibrary *this)
void  CFileLibrary::pOptimize(void) {
  
  CFileLibrary *result; // eax
  void *v2; // [esp+20h] [ebp-34h]
  unsigned int v3; // [esp+24h] [ebp-30h]
  void *v4; // [esp+2Ch] [ebp-28h]
  unsigned int v5; // [esp+30h] [ebp-24h]
  void *v6; // [esp+34h] [ebp-20h]
  int i; // [esp+38h] [ebp-1Ch]
  void *v8; // [esp+3Ch] [ebp-18h]
  int v9; // [esp+40h] [ebp-14h]

  result = this;
  if ( !*((_DWORD *)this + 117) )
    return result;
  if ( *((_DWORD *)this + 13) != *((_DWORD *)this + 12) )
  {
    v5 = *((_DWORD *)this + 13);
    v8 = operator new[](16 * v5);
    if ( v8 )
    {
      `vector constructor iterator'(v8, 0x10u, v5, (void *(__thiscall *)(void *))FLMemDirStruct::FLMemDirStruct);
      v4 = v8;
    }
    else
    {
      v4 = 0;
    }
    j__memmove(v4, *((const void **)this + 117), 16 * *((_DWORD *)this + 13));
    operator delete[](*((void **)this + 117));
    *((_DWORD *)this + 117) = v4;
    *((_DWORD *)this + 12) = *((_DWORD *)this + 13);
  }
  j__qsort(*((void **)this + 117), *((_DWORD *)this + 13), 0x10u, CFileLibrary::sDirCompare_qsort);
  result = this;
  *((_DWORD *)this + 118) |= 1u;
  v9 = *((_DWORD *)this + 117);
  for ( i = 0; i < *((_DWORD *)this + 13); ++i )
  {
    if ( *(_DWORD *)(v9 + 12) )
    {
      if ( *(__int16 *)(v9 + 8) != *(__int16 *)(v9 + 6) )
      {
        v3 = *(__int16 *)(v9 + 6);
        v6 = operator new[](32 * v3);
        if ( v6 )
        {
          `vector constructor iterator'(v6, 0x20u, v3, (void *(__thiscall *)(void *))FLMemFileStruct::FLMemFileStruct);
          v2 = v6;
        }
        else
        {
          v2 = 0;
        }
        j__memmove(v2, *(const void **)(v9 + 12), 32 * *(__int16 *)(v9 + 6));
        operator delete[](*(void **)(v9 + 12));
        *(_DWORD *)(v9 + 12) = v2;
        *(_WORD *)(v9 + 8) = *(_WORD *)(v9 + 6);
      }
      j__qsort(*(void **)(v9 + 12), *(__int16 *)(v9 + 6), 0x20u, CFileLibrary::sFileCompare_qsort);
      *(_WORD *)(v9 + 4) |= 1u;
    }
    v9 += 16;
    result = (CFileLibrary *)(i + 1);
  }
  return result;
}


// address=[0x2f095f0]
// Decompiled from DWORD __thiscall CFileLibrary::LoadEntireFile(CFileLibrary *this, unsigned int a2, char *a3, int a4, char a5)
int  CFileLibrary::LoadEntireFile(unsigned int,void *,unsigned int,int) {
  
  __int16 v6; // [esp+14h] [ebp-1Ch]
  HANDLE hFile; // [esp+18h] [ebp-18h]
  int v8; // [esp+1Ch] [ebp-14h]
  DWORD NumberOfBytesRead; // [esp+20h] [ebp-10h] BYREF
  LPVOID lpBuffer; // [esp+24h] [ebp-Ch]
  CFileLibrary *v11; // [esp+28h] [ebp-8h]
  struct FLIntHandleStruct *IntHandlePtr; // [esp+2Ch] [ebp-4h]

  v11 = this;
  ++*(_DWORD *)this;
  ++*((_DWORD *)v11 + 1);
  IntHandlePtr = CFileLibrary::pGetIntHandlePtr(v11, a2);
  if ( IntHandlePtr )
  {
    hFile = CFileLibrary::pGetFileLibraryHandle(v11, *(__int16 *)(*((_DWORD *)IntHandlePtr + 5) + 20));
    if ( hFile == (HANDLE)-1 )
    {
      BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tInvalid lib file handle");
      return -1;
    }
    else if ( SetFilePointer(hFile, *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 8), 0, 0) == -1 )
    {
      BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tfailed to set file ptr");
      return -1;
    }
    else
    {
      v6 = *(_WORD *)(*((_DWORD *)IntHandlePtr + 5) + 4);
      if ( (a5 & 1) != 0 )
        LOBYTE(v6) = 0;
      if ( (v6 & 1) != 0 )
      {
        lpBuffer = operator new[](*(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 12));
        ReadFile(hFile, lpBuffer, *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 12), &NumberOfBytesRead, 0);
        if ( *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 12) == NumberOfBytesRead )
        {
          if ( CFileLibrary::CRC(v11, lpBuffer, *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 12)) == a4 )
          {
            if ( (v6 & 2) != 0 )
              v8 = CFileLibrary::UnpackData(
                     v11,
                     a3,
                     *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 16),
                     (char *)lpBuffer,
                     NumberOfBytesRead,
                     1);
            else
              v8 = CFileLibrary::UnpackData(
                     v11,
                     a3,
                     *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 16),
                     (char *)lpBuffer,
                     NumberOfBytesRead,
                     0);
            operator delete[](lpBuffer);
            if ( v8 )
            {
              *((_DWORD *)v11 + 4) += v8;
              return v8;
            }
            else
            {
              BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tFailed to unpack data");
              return -1;
            }
          }
          else
          {
            operator delete[](lpBuffer);
            BBSupportTracePrintF(
              3,
              "CFileLibrary::LoadEntireFile\t:\tCRC error in %s",
              **((const char ***)IntHandlePtr + 5));
            return -1;
          }
        }
        else
        {
          operator delete[](lpBuffer);
          BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tFailed to read file for decompressing");
          return -1;
        }
      }
      else
      {
        ReadFile(hFile, a3, *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 12), &NumberOfBytesRead, 0);
        if ( (v6 & 2) != 0 )
          CFileLibrary::DataCryptor(a3, *(_DWORD *)(*((_DWORD *)IntHandlePtr + 5) + 12));
        *((_DWORD *)v11 + 4) += NumberOfBytesRead;
        return NumberOfBytesRead;
      }
    }
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tNo file with this handle");
    return -1;
  }
}


// address=[0x2f09890]
// Decompiled from void __cdecl CFileLibrary::DataCryptor(unsigned __int8 *a1, int a2)
static void __cdecl CFileLibrary::DataCryptor(void *,int) {
  
  int i; // [esp+8h] [ebp-7Ch]
  _BYTE v3[76]; // [esp+Ch] [ebp-78h] BYREF
  _BYTE v4[28]; // [esp+58h] [ebp-2Ch] BYREF
  int v5; // [esp+80h] [ebp-4h]

  Cryptor::Cryptor((Cryptor *)v3);
  v5 = 0;
  std::string::string(v4, "01234567890123456789");
  LOBYTE(v5) = 1;
  Cryptor::Set_Key(v4);
  for ( i = 0; i < a2; ++i )
    Cryptor::Transform_Char((Cryptor *)v3, &a1[i]);
  LOBYTE(v5) = 0;
  std::string::~string(v4);
  v5 = -1;
  Cryptor::~Cryptor((Cryptor *)v3);
}


// address=[0x2f09950]
// Decompiled from unsigned int __thiscall CFileLibrary::CRC(CFileLibrary *this, _BYTE *a2, int a3)
unsigned int  CFileLibrary::CRC(void *,int) {
  
  unsigned int NormalCRC; // [esp+Ch] [ebp-Ch]
  _BYTE v5[4]; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(v5);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Reset((std::_Basic_container_proxy_ptr12 *)v5);
  for ( i = 0; i < a3; ++i )
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(a2[i]);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(v5);
  return NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(v5));
}


