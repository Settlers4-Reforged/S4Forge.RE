#include "CConfigFile.h"

// Definitions for class CConfigFile

// address=[0x2f28860]
// Decompiled from CConfigFile *__thiscall CConfigFile::CConfigFile(CConfigFile *this, wchar_t *FileName)
 CConfigFile::CConfigFile(wchar_t const * FileName) {
  
  _DWORD v4[26]; // [esp+Ch] [ebp-7Ch] BYREF
  int v5; // [esp+74h] [ebp-14h] BYREF
  int v6; // [esp+84h] [ebp-4h]

  std::wstring::wstring(this);
  v6 = 0;
  std::wstring::operator=(this, FileName);
  this->m_pConfig = 0;
  CFileEx::CFileEx((CFileEx *)v4, 1);
  LOBYTE(v6) = 1;
  CFileEx::Open(&v5, FileName, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  this->m_iSize = CFileEx::Size(v4);
  this->m_pConfig = (char *)operator new[](this->m_iSize + 1);
  this->m_pConfig[this->m_iSize] = 0;
  CFileEx::Read(&v5, this->m_pConfig, 1, this->m_iSize, UNUSED_ARG(), UNUSED_ARG());
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
// Decompiled from char *__thiscall CConfigFile::GetConfig(CConfigFile *this)
char *  CConfigFile::GetConfig(void) {
  
  return this->m_pConfig;
}


// address=[0x2f289e0]
// Decompiled from int __thiscall CConfigFile::GetSize(CConfigFile *this)
unsigned int  CConfigFile::GetSize(void) {
  
  return this->m_iSize;
}


// address=[0x2f28a00]
// Decompiled from wchar_t *__thiscall CConfigFile::GetName(CConfigFile *this)
wchar_t const *  CConfigFile::GetName(void) {
  
  return std::wstring::c_str((std::wstring *)this);
}


