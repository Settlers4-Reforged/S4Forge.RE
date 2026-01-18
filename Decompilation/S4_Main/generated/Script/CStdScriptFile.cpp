#include "CStdScriptFile.h"

// Definitions for class CStdScriptFile

// address=[0x160dbd0]
// Decompiled from int __thiscall CStdScriptFile::CStdScriptFile(int this, wchar_t *FileName)
 CStdScriptFile::CStdScriptFile(wchar_t const * FileName) {
  
  _DWORD v4[26]; // [esp+Ch] [ebp-7Ch] BYREF
  int v5; // [esp+74h] [ebp-14h] BYREF
  int v6; // [esp+84h] [ebp-4h]

  IScriptFile::IScriptFile((IScriptFile *)this);
  v6 = 0;
  *(_DWORD *)this = &CStdScriptFile::_vftable_;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  if ( !FileName )
    return this;
  CFileEx::CFileEx((CFileEx *)v4, 1);
  LOBYTE(v6) = 1;
  CFileEx::Open(&v5, FileName, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  *(_DWORD *)(this + 8) = CFileEx::Size(v4);
  *(_DWORD *)(this + 4) = operator new[](*(_DWORD *)(this + 8) + 1);
  *(_BYTE *)(*(_DWORD *)(this + 4) + *(_DWORD *)(this + 8)) = 0;
  CFileEx::Read(&v5, *(void **)(this + 4), 1, *(_DWORD *)(this + 8), "Script\\ScriptFile.cpp", 49);
  CFileEx::Close((CFileEx *)&v5, UNUSED_ARG(), UNUSED_ARG());
  LOBYTE(v6) = 0;
  CFileEx::~CFileEx(v4);
  return this;
}


// address=[0x160dd00]
// Decompiled from void __thiscall CStdScriptFile::~CStdScriptFile(void **this)
 CStdScriptFile::~CStdScriptFile(void) {
  
  *this = &CStdScriptFile::_vftable_;
  if ( this[1] )
  {
    operator delete[](this[1]);
    this[1] = 0;
  }
  IScriptFile::~IScriptFile((IScriptFile *)this);
}


// address=[0x160dd50]
// Decompiled from int __thiscall CStdScriptFile::GetScript(CStdScriptFile *this)
char const *  CStdScriptFile::GetScript(void) {
  
  return *((_DWORD *)this + 1);
}


// address=[0x160dd70]
// Decompiled from int __thiscall CStdScriptFile::GetSize(CStdScriptFile *this)
unsigned int  CStdScriptFile::GetSize(void) {
  
  return *((_DWORD *)this + 2);
}


