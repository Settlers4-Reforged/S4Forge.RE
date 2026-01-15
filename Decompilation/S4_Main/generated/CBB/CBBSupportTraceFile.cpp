#include "CBBSupportTraceFile.h"

// Definitions for class CBBSupportTraceFile

// address=[0x2f2ee90]
// Decompiled from BBSupportLib::CBBSupportTraceFile *__thiscall BBSupportLib::CBBSupportTraceFile::CBBSupportTraceFile(  BBSupportLib::CBBSupportTraceFile *this)
 BBSupportLib::CBBSupportTraceFile::CBBSupportTraceFile(void) {
  
  char v2; // [esp+8h] [ebp-24h]
  char v3; // [esp+Ch] [ebp-20h]
  unsigned int v4; // [esp+10h] [ebp-1Ch]
  int i; // [esp+14h] [ebp-18h]

  BBSupportLib::IBBSupportTraceFile::IBBSupportTraceFile(this);
  *(_DWORD *)this = &BBSupportLib::CBBSupportTraceFile::_vftable_;
  memset((char *)this + 572, 0, 0x18u);
  memset((char *)this + 596, 0, 0xC8u);
  InitializeCriticalSection((LPCRITICAL_SECTION)((char *)this + 572));
  *((_BYTE *)this + 596) = 5;
  *((_BYTE *)this + 597) = 5;
  *((_BYTE *)this + 598) = 5;
  *((_BYTE *)this + 599) = 5;
  if ( BBSupportLib::BBSIsDevelopmentMachine() )
    v3 = 5;
  else
    v3 = 1;
  *((_BYTE *)this + 600) = v3;
  *((_BYTE *)this + 601) = 5;
  v4 = BBSupportDevelopmentMachineId();
  for ( i = 6; i <= 37; ++i )
  {
    if ( (v4 & 1) != 0 )
      v2 = 5;
    else
      v2 = 1;
    *((_BYTE *)this + i + 596) = v2;
    v4 >>= 1;
  }
  BBSupportLib::CBBSupportTraceFilePtr::m_pTraceFile = (int)this;
  return this;
}


// address=[0x2f2f020]
// Decompiled from void __thiscall BBSupportLib::CBBSupportTraceFile::~CBBSupportTraceFile(BBSupportLib::CBBSupportTraceFile *this)
 BBSupportLib::CBBSupportTraceFile::~CBBSupportTraceFile(void) {
  
  *(_DWORD *)this = &BBSupportLib::CBBSupportTraceFile::_vftable_;
  BBSupportLib::CBBSupportTraceFile::Close(this);
  BBSupportLib::CBBSupportTraceFilePtr::m_pTraceFile = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)this + 572));
  BBSupportLib::IBBSupportTraceFile::~IBBSupportTraceFile(this);
}


// address=[0x2f2f090]
// Decompiled from void __stdcall BBSupportLib::CBBSupportTraceFile::SetFilePath(  BBSupportLib::CBBSupportTraceFile *this,  const wchar_t *a2)
void __stdcall BBSupportLib::CBBSupportTraceFile::SetFilePath(wchar_t const *) {
  
  if ( a2 && *a2 )
    CBBSupportLogFile::SetFilePath(this, a2);
  else
    CBBSupportLogFile::SetFilePath(this, L"Trace.txt");
}


// address=[0x2f2f0d0]
// Decompiled from void __stdcall BBSupportLib::CBBSupportTraceFile::PrintTime(BBSupportLib::CBBSupportTraceFile *this)
void __stdcall BBSupportLib::CBBSupportTraceFile::PrintTime(void) {
  
  DWORD dwErrCode; // [esp+0h] [ebp-18h]
  struct _SYSTEMTIME SystemTime; // [esp+4h] [ebp-14h] BYREF

  dwErrCode = GetLastError();
  GetLocalTime(&SystemTime);
  (*(void (**)(BBSupportLib::CBBSupportTraceFile *, const char *, ...))(*(_DWORD *)this + 24))(
    this,
    "[ %02i/%02i/%04i %02i:%02i:%02i ]",
    SystemTime.wMonth,
    SystemTime.wDay,
    SystemTime.wYear,
    SystemTime.wHour,
    SystemTime.wMinute,
    SystemTime.wSecond);
  SetLastError(dwErrCode);
}


// address=[0x2f2f150]
// Decompiled from char __stdcall BBSupportLib::CBBSupportTraceFile::Open(BBSupportLib::CBBSupportTraceFile *this)
void __stdcall BBSupportLib::CBBSupportTraceFile::Open(void) {
  
  char result; // al

  result = CBBSupportLogFile::IsOpen(this);
  if ( result )
    return result;
  CBBSupportLogFile::Open(this);
  result = CBBSupportLogFile::IsOpen(this);
  if ( !result )
    return result;
  (*(void (__cdecl **)(BBSupportLib::CBBSupportTraceFile *))(*(_DWORD *)this + 28))(this);
  (*(void (__stdcall **)(BBSupportLib::CBBSupportTraceFile *))(*(_DWORD *)this + 52))(this);
  (*(void (__stdcall **)(BBSupportLib::CBBSupportTraceFile *, const char *))(*(_DWORD *)this + 20))(
    this,
    " Trace file opened.\r\n");
  (*(void (__cdecl **)(BBSupportLib::CBBSupportTraceFile *))(*(_DWORD *)this + 28))(this);
  return (*(int (__stdcall **)(BBSupportLib::CBBSupportTraceFile *))(*(_DWORD *)this + 32))(this);
}


// address=[0x2f2f1e0]
// Decompiled from void __stdcall BBSupportLib::CBBSupportTraceFile::Close(BBSupportLib::CBBSupportTraceFile *this)
void __stdcall BBSupportLib::CBBSupportTraceFile::Close(void) {
  
  if ( CBBSupportLogFile::IsOpen(this) )
  {
    (*(void (__cdecl **)(BBSupportLib::CBBSupportTraceFile *))(*(_DWORD *)this + 28))(this);
    (*(void (__stdcall **)(BBSupportLib::CBBSupportTraceFile *))(*(_DWORD *)this + 52))(this);
    (*(void (__stdcall **)(BBSupportLib::CBBSupportTraceFile *, const char *))(*(_DWORD *)this + 20))(
      this,
      " Closing trace file...\r\n");
    (*(void (__thiscall **)(BBSupportLib::CBBSupportTraceFile *, BBSupportLib::CBBSupportTraceFile *))(*(_DWORD *)this + 32))(
      this,
      this);
  }
  CBBSupportLogFile::Close(this);
}


