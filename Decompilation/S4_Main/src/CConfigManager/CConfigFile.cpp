#include "CConfigFile.h"

#include "../File/CFile.h"
#include "File/CFileEx.h"

// Definitions for class CConfigFile

// address=[0x2f28860]
// Decompiled from CConfigFile *__thiscall CConfigFile::CConfigFile(CConfigFile *this, wchar_t *FileName)
CConfigFile::CConfigFile(wchar_t const *FileName)
{

  _DWORD v4[26]; // [esp+Ch] [ebp-7Ch] BYREF
  int v5;        // [esp+74h] [ebp-14h] BYREF
  int v6;        // [esp+84h] [ebp-4h]

  this->m_sFileName = FileName;
  this->m_pConfig = 0;
  CFileEx sConfigFile{};

  sConfigFile.Open(FileName, 6, 0, CFileLog);
  this->m_iSize = sConfigFile.Size();
  this->m_pConfig = new char[this->m_iSize + 1];
  this->m_pConfig[this->m_iSize] = 0;
  sConfigFile.Read(this->m_pConfig, 1, this->m_iSize, CFileLog);
  sConfigFile.Close(CFileLog);
}

// address=[0x2f28980]
// Decompiled from void __thiscall CConfigFile::~CConfigFile(void **this)
CConfigFile::~CConfigFile(void)
{
  delete[] this->m_pConfig;
}

// address=[0x2f289c0]
// Decompiled from char *__thiscall CConfigFile::GetConfig(CConfigFile *this)
char *CConfigFile::GetConfig(void)
{
  return this->m_pConfig;
}

// address=[0x2f289e0]
// Decompiled from int __thiscall CConfigFile::GetSize(CConfigFile *this)
unsigned int CConfigFile::GetSize(void)
{
  return this->m_iSize;
}

// address=[0x2f28a00]
// Decompiled from wchar_t *__thiscall CConfigFile::GetName(CConfigFile *this)
wchar_t const *CConfigFile::GetName(void)
{
  return this->m_sFileName.c_str();
}
