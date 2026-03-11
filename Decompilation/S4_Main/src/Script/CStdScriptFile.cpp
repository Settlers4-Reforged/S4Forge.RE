#include "CStdScriptFile.h"

#include "../File/CFileEx.h"

// Definitions for class CStdScriptFile

// address=[0x160dbd0]
// Decompiled from CStdScriptFile *__thiscall CStdScriptFile::CStdScriptFile(CStdScriptFile *this, wchar_t *FileName)
CStdScriptFile::CStdScriptFile(wchar_t const *FileName) : IScriptFile()
{

  this->m_pScript = 0;
  this->m_uSize = 0;
  if (!FileName)
    return;
  CFileEx v4 = CFileEx();

  v4.Open(FileName, CFile::CFile_BINARY | CFile::CFile_READ, 0, CFileLog);
  this->m_uSize = v4.Size();
  char *pScript = new char[this->m_uSize + 1];
  pScript[this->m_uSize] = 0;
  this->m_pScript = pScript;
  v4.Read((void *)this->m_pScript, 1, this->m_uSize, CFileLog);
  v4.Close(CFileLog);
}

// address=[0x160dd00]
// Decompiled from void __thiscall CStdScriptFile::~CStdScriptFile(CStdScriptFile *this)
CStdScriptFile::~CStdScriptFile(void)
{
  delete[] this->m_pScript;
  this->m_pScript = 0;
}

// address=[0x160dd50]
// Decompiled from const char *__thiscall CStdScriptFile::GetScript(CStdScriptFile *this)
char const *CStdScriptFile::GetScript(void)
{
  return this->m_pScript;
}

// address=[0x160dd70]
// Decompiled from int __thiscall CStdScriptFile::GetSize(CStdScriptFile *this)
unsigned int CStdScriptFile::GetSize(void)
{
  return this->m_uSize;
}
