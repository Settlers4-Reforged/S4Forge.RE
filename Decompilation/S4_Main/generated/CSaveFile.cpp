#include "all_headers.h"

// Definitions for class CSaveFile

// address=[0x13e50e0]
// Decompiled from void __thiscall S4::CSaveFile::~CSaveFile(CDaoIndexFieldInfo *this)
 S4::CSaveFile::~CSaveFile(void) {
  
  CFile::~CFile();
}


// address=[0x13e6580]
// Decompiled from int __thiscall S4::CSaveFile::GetFilePos(FILE **this)
unsigned int  S4::CSaveFile::GetFilePos(void) {
  
  return CFile::Tell(this + 1, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
}


// address=[0x13eb4f0]
// Decompiled from S4::CSaveFile *__thiscall S4::CSaveFile::CSaveFile(S4::CSaveFile *this, bool a2)
 S4::CSaveFile::CSaveFile(bool) {
  
  *(_BYTE *)this = a2;
  CFile::CFile((S4::CSaveFile *)((char *)this + 4));
  *((_DWORD *)this + 19) = 0;
  return this;
}


// address=[0x13eb520]
// Decompiled from char __stdcall S4::CSaveFile::Open(int a1, char a2)
bool  S4::CSaveFile::Open(std::wstring const &,int) {
  
  if ( (a2 & 2) != 0 )
  {
    CFile::Open(a1, 26, "LoadSave\\CSaveFile.cpp", 51);
  }
  else if ( (a2 & 1) != 0 )
  {
    CFile::Open(a1, 6, "LoadSave\\CSaveFile.cpp", 61);
    CFile::Seek(0, 0, (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
  }
  return 1;
}


// address=[0x13eb590]
// Decompiled from char __thiscall S4::CSaveFile::Close(S4::CSaveFile *this)
bool  S4::CSaveFile::Close(void) {
  
  CFile::Close(
    (S4::CSaveFile *)((char *)this + 4),
    "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h",
    0);
  return 1;
}


// address=[0x13eb5b0]
// Decompiled from size_t __thiscall S4::CSaveFile::Read(_DWORD *this, void *Buffer, size_t ElementSize)
int  S4::CSaveFile::Read(void *,int) {
  
  int v4; // [esp+0h] [ebp-8h]

  v4 = CFile::Read(
         Buffer,
         ElementSize,
         1u,
         (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h",
         0);
  if ( this[19] )
    return -1;
  else
    return ElementSize * v4;
}


// address=[0x13eb600]
// Decompiled from int __stdcall S4::CSaveFile::Write(void *Buffer, size_t ElementSize)
int  S4::CSaveFile::Write(void const *,int) {
  
  return CFile::Write(
           Buffer,
           ElementSize,
           1u,
           (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h",
           0);
}


// address=[0x13eb630]
// Decompiled from int __stdcall S4::CSaveFile::SetFilePos(int Offset, int Origin)
void  S4::CSaveFile::SetFilePos(int,int) {
  
  return CFile::Seek(Offset, Origin, (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
}


// address=[0x13eb660]
// Decompiled from int __thiscall S4::CSaveFile::GetFileSize(S4::CSaveFile *this)
unsigned int  S4::CSaveFile::GetFileSize(void) {
  
  return (*(int (__thiscall **)(char *, S4::CSaveFile *))(*((_DWORD *)this + 1) + 16))((char *)this + 4, this);
}


// address=[0x13eb680]
// Decompiled from bool __thiscall S4::CSaveFile::Eof(FILE **this)
bool  S4::CSaveFile::Eof(void) {
  
  return CFile::Eof(this + 1) != 0;
}


