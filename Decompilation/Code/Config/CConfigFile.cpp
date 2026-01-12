#include "CConfigFile.h"

// Definitions for class CConfigFile

// address=[0x2f28860]
// Decompiled from int __thiscall CConfigFile::CConfigFile(int this, wchar_t *FileName)

 CConfigFile::CConfigFile(wchar_t const *) {
  
  _DWORD v4[26]; // [esp+Ch] [ebp-7Ch] BYREF
  int v5; // [esp+74h] [ebp-14h] BYREF
  int v6; // [esp+84h] [ebp-4h]

  std::wstring::wstring((void *)this);
  v6 = 0;
  std::wstring::operator=((void *)this, FileName);
  *(_DWORD *)(this + 28) = 0;
  CFileEx::CFileEx((CFileEx *)v4, 1);
  LOBYTE(v6) = 1;
  CFileEx::Open(&v5, FileName, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  *(_DWORD *)(this + 32) = CFileEx::Size(v4);
  *(_DWORD *)(this + 28) = operator new[](*(_DWORD *)(this + 32) + 1);
  *(_BYTE *)(*(_DWORD *)(this + 28) + *(_DWORD *)(this + 32)) = 0;
  CFileEx::Read(&v5, *(void **)(this + 28), 1, *(_DWORD *)(this + 32), "Source\\ConfigManager\\ConfigFile.cpp", 32);
  CFileEx::Close((CFileEx *)&v5, UNUSED_ARG(), UNUSED_ARG());
  LOBYTE(v6) = 0;
  CFileEx::~CFileEx(v4);
  return this;
}


// address=[0x2f28980]
// Decompiled from void __thiscall CConfigFile::~CConfigFile(void **this)

 CConfigFile::~CConfigFile(void) {
  
  if ( this[7] )
    operator delete(this[7]);
  std::wstring::~wstring(this);
}


// address=[0x2f289c0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CConfigFile::GetConfig(CConfigFile *this)

char *  CConfigFile::GetConfig(void) {
  
  return *((_DWORD *)this + 7);
}


// address=[0x2f289e0]
// Decompiled from // MFC 3.1-14.0 32bit
int __thiscall CConfigFile::GetSize(CConfigFile *this)

unsigned int  CConfigFile::GetSize(void) {
  
  return *((_DWORD *)this + 8);
}


// address=[0x2f28a00]
// Decompiled from // public: wchar_t const * __thiscall CConfigFile::GetName(void)
_DWORD *__thiscall CConfigFile::GetName(_Cnd_internal_imp_t *this)

wchar_t const *  CConfigFile::GetName(void) {
  
  return std::wstring::c_str(this);
}


