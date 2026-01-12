#include "CBBSupportLogFile.h"

// Definitions for class CBBSupportLogFile

// address=[0x2f2fa50]
// Decompiled from bool __stdcall CBBSupportLogFile::IsOpen(CBBSupportLogFile *this)
bool __stdcall CBBSupportLogFile::IsOpen(void) {
  
  return *((_DWORD *)this + 4) != 0;
}


// address=[0x2f33df0]
// Decompiled from CBBSupportLogFile *__thiscall CBBSupportLogFile::CBBSupportLogFile(CBBSupportLogFile *this)
 CBBSupportLogFile::CBBSupportLogFile(void) {
  
  *(_DWORD *)this = &CBBSupportLogFile::_vftable_;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  j__memset((char *)this + 20, 0, 0x228u);
  return this;
}


// address=[0x2f33e50]
// Decompiled from void __thiscall CBBSupportLogFile::~CBBSupportLogFile(CBBSupportLogFile *this)
 CBBSupportLogFile::~CBBSupportLogFile(void) {
  
  *(_DWORD *)this = &CBBSupportLogFile::_vftable_;
  CBBSupportLogFile::Close(this);
}


// address=[0x2f33ea0]
// Decompiled from CBBSupportLogFile *__stdcall CBBSupportLogFile::SetFileMode(CBBSupportLogFile *this, unsigned int a2)
void __stdcall CBBSupportLogFile::SetFileMode(int) {
  
  CBBSupportLogFile *result; // eax

  result = this;
  if ( *((_DWORD *)this + 2) )
    return result;
  if ( a2 >= 4 )
    a2 = 0;
  *((_DWORD *)this + 1) = a2;
  return result;
}


// address=[0x2f33ee0]
// Decompiled from CBBSupportLogFile *__stdcall CBBSupportLogFile::SetFilePath(CBBSupportLogFile *this, wchar_t *a2)
void __stdcall CBBSupportLogFile::SetFilePath(wchar_t const *) {
  
  CBBSupportLogFile *result; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  result = this;
  if ( *((_DWORD *)this + 2) )
    return result;
  result = (CBBSupportLogFile *)j__memset((char *)this + 20, 0, 0x228u);
  if ( a2 )
  {
    for ( i = 0; i < 0x227; ++i )
    {
      result = (CBBSupportLogFile *)a2;
      if ( !a2[i] )
        break;
      result = this;
      *((_WORD *)this + i + 10) = a2[i];
    }
  }
  return result;
}


// address=[0x2f33f50]
// Decompiled from int __thiscall CBBSupportLogFile::SetFileModePathAndCreateOrDeleteIfDesired(  void *ecx0,  CBBSupportLogFile *this,  int a3,  const wchar_t *a4)
void __stdcall CBBSupportLogFile::SetFileModePathAndCreateOrDeleteIfDesired(int,wchar_t const *) {
  
  int result; // eax
  int v5; // [esp+0h] [ebp-4h]

  (*(void (__stdcall **)(CBBSupportLogFile *, int, void *))(*(_DWORD *)this + 4))(this, a3, ecx0);
  result = (*(int (__stdcall **)(CBBSupportLogFile *, const wchar_t *))(*(_DWORD *)this + 8))(this, a4);
  v5 = *((_DWORD *)this + 1);
  if ( v5 == 1 )
    return (*(int (__stdcall **)(CBBSupportLogFile *))(*(_DWORD *)this + 36))(this);
  if ( v5 == 2 )
    return (*(int (__stdcall **)(CBBSupportLogFile *))(*(_DWORD *)this + 40))(this);
  if ( v5 != 3 )
    return result;
  return (*(int (__stdcall **)(CBBSupportLogFile *))(*(_DWORD *)this + 36))(this);
}


// address=[0x2f33fc0]
// Decompiled from void __stdcall CBBSupportLogFile::Write(int a1, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite)
void __stdcall CBBSupportLogFile::Write(void const *,unsigned int) {
  
  DWORD dwErrCode; // [esp+0h] [ebp-10h]
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-Ch] BYREF
  BOOL v5; // [esp+8h] [ebp-8h]
  BOOL v6; // [esp+Ch] [ebp-4h]

  v6 = lpBuffer != 0;
  v5 = nNumberOfBytesToWrite != 0;
  if ( v5 && v6 && CBBSupportLogFile::OpenIfNecessary((CBBSupportLogFile *)a1) )
  {
    *(_DWORD *)(a1 + 12) = 0;
    dwErrCode = GetLastError();
    NumberOfBytesWritten = 0;
    WriteFile(*(HANDLE *)(a1 + 16), lpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0);
    SetLastError(dwErrCode);
  }
}


// address=[0x2f34050]
// Decompiled from int __stdcall CBBSupportLogFile::Print(CBBSupportLogFile *this, const char *a2)
void __stdcall CBBSupportLogFile::Print(char const *) {
  
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  if ( !a2 )
    return result;
  for ( i = 0; a2[i]; ++i )
    ;
  return (*(int (__thiscall **)(CBBSupportLogFile *, CBBSupportLogFile *, const char *, int))(*(_DWORD *)this + 16))(
           this,
           this,
           a2,
           i);
}


// address=[0x2f340a0]
// Decompiled from void CBBSupportLogFile::PrintF(int a1, LPCSTR a2, ...)
void __cdecl CBBSupportLogFile::PrintF(char const *,...) {
  
  DWORD dwErrCode; // [esp+0h] [ebp-414h]
  int i; // [esp+Ch] [ebp-408h]
  CHAR v4[1024]; // [esp+10h] [ebp-404h] BYREF
  va_list va; // [esp+424h] [ebp+10h] BYREF

  va_start(va, a2);
  if ( a2 )
  {
    dwErrCode = GetLastError();
    __vcrt_va_start_verify_argument_type<char const *>();
    wvsprintfA(v4, a2, va);
    v4[1023] = 0;
    for ( i = 0; v4[i]; ++i )
      ;
    (*(void (__stdcall **)(int, CHAR *, int))(*(_DWORD *)a1 + 16))(a1, v4, i);
    SetLastError(dwErrCode);
  }
}


// address=[0x2f34190]
// Decompiled from CBBSupportLogFile *__cdecl CBBSupportLogFile::PrintNewLine(CBBSupportLogFile *this)
void __cdecl CBBSupportLogFile::PrintNewLine(void) {
  
  CBBSupportLogFile *result; // eax

  result = this;
  if ( *((_DWORD *)this + 3) )
    return result;
  result = (CBBSupportLogFile *)(*(int (__stdcall **)(CBBSupportLogFile *, void *, int))(*(_DWORD *)this + 16))(
                                  this,
                                  &unk_3ABA9BC,
                                  2);
  *((_DWORD *)this + 3) = 1;
  return result;
}


// address=[0x2f341c0]
// Decompiled from void __stdcall CBBSupportLogFile::Flush(HANDLE *this)
void __stdcall CBBSupportLogFile::Flush(void) {
  
  DWORD dwErrCode; // [esp+0h] [ebp-4h]

  if ( CBBSupportLogFile::IsOpen((CBBSupportLogFile *)this) )
  {
    dwErrCode = GetLastError();
    FlushFileBuffers(this[4]);
    SetLastError(dwErrCode);
  }
}


// address=[0x2f34200]
// Decompiled from void __stdcall CBBSupportLogFile::Open(CBBSupportLogFile *this)
void __stdcall CBBSupportLogFile::Open(void) {
  
  HANDLE FileW; // eax
  BBSupportLib *dwErrCodea; // [esp+0h] [ebp-18h]
  DWORD dwErrCode; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  char v5; // [esp+Ch] [ebp-Ch]
  DWORD dwFlagsAndAttributes; // [esp+10h] [ebp-8h]

  if ( *((_DWORD *)this + 1) && !*((_DWORD *)this + 2) && !*((_DWORD *)this + 4) && *((_WORD *)this + 10) )
  {
    dwErrCodea = (BBSupportLib *)GetLastError();
    SetLastError(0);
    dwFlagsAndAttributes = 128;
    v5 = BBSupportLib::BBSGetSupportFlags(dwErrCodea);
    if ( (v5 & 2) == 0 && (v5 & 1) != 0 )
      dwFlagsAndAttributes = -2147483520;
    if ( *((_DWORD *)this + 1) == 3 )
      FileW = CreateFileW((LPCWSTR)this + 10, 0x40000000u, 1u, 0, 4u, dwFlagsAndAttributes, 0);
    else
      FileW = CreateFileW((LPCWSTR)this + 10, 0x40000000u, 1u, 0, 2u, dwFlagsAndAttributes, 0);
    *((_DWORD *)this + 4) = FileW;
    if ( *((_DWORD *)this + 4) == -1 )
    {
      *((_DWORD *)this + 4) = 0;
    }
    else if ( *((_DWORD *)this + 1) == 3 )
    {
      SetFilePointer(*((HANDLE *)this + 4), 0, 0, 2u);
    }
    if ( *((_DWORD *)this + 4) )
      v4 = 1;
    else
      v4 = -1;
    *((_DWORD *)this + 2) = v4;
    SetLastError(dwErrCode);
  }
}


// address=[0x2f34340]
// Decompiled from void __stdcall CBBSupportLogFile::Delete(const WCHAR *this)
void __stdcall CBBSupportLogFile::Delete(void) {
  
  DWORD dwErrCode; // [esp+0h] [ebp-4h]

  dwErrCode = GetLastError();
  DeleteFileW(this + 10);
  SetLastError(dwErrCode);
}


// address=[0x2f34370]
// Decompiled from void __stdcall CBBSupportLogFile::Close(CBBSupportLogFile *this)
void __stdcall CBBSupportLogFile::Close(void) {
  
  DWORD dwErrCode; // [esp+0h] [ebp-8h]
  HANDLE hObject; // [esp+4h] [ebp-4h]

  if ( CBBSupportLogFile::IsOpen(this) )
  {
    dwErrCode = GetLastError();
    hObject = (HANDLE)*((_DWORD *)this + 4);
    *((_DWORD *)this + 2) = -1;
    *((_DWORD *)this + 4) = 0;
    CloseHandle(hObject);
    SetLastError(dwErrCode);
  }
  else
  {
    *((_DWORD *)this + 2) = -1;
    *((_DWORD *)this + 4) = 0;
  }
}


// address=[0x2f343e0]
// Decompiled from char __stdcall CBBSupportLogFile::GetFilePath(CBBSupportLogFile *this, wchar_t *a2, unsigned int a3)
bool __stdcall CBBSupportLogFile::GetFilePath(wchar_t *,unsigned int) {
  
  if ( *((_WORD *)this + 10) != 0 && *((_DWORD *)this + 1) != 0 )
  {
    BBSupportLib::BBSCopyString<wchar_t>(a2, (char *)this + 20, a3);
    return 1;
  }
  else
  {
    BBSupportLib::BBSCopyString<wchar_t>(a2, off_3ABA9C0, a3);
    return 0;
  }
}


// address=[0x2f34670]
// Decompiled from bool __stdcall CBBSupportLogFile::OpenIfNecessary(CBBSupportLogFile *this)
bool __stdcall CBBSupportLogFile::OpenIfNecessary(void) {
  
  if ( *((_DWORD *)this + 2) == 0 && *((_DWORD *)this + 1) == 2 )
    (*(void (__stdcall **)(CBBSupportLogFile *))(*(_DWORD *)this + 36))(this);
  return CBBSupportLogFile::IsOpen(this);
}


