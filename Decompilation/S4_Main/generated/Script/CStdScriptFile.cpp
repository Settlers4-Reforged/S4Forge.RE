#if FALSE
#include "CStdScriptFile.h"

// Definitions for class CStdScriptFile

// address=[0x160dbd0]
// Decompiled from CStdScriptFile *__thiscall CStdScriptFile::CStdScriptFile(CStdScriptFile *this, wchar_t *FileName)
 CStdScriptFile::CStdScriptFile(wchar_t const * FileName) {
  
  CFileEx v4; // [esp+Ch] [ebp-7Ch] BYREF
  int v5; // [esp+84h] [ebp-4h]

  IScriptFile::IScriptFile(this);
  v5 = 0;
  this->__vftable = (IScriptFile_vtbl *)&CStdScriptFile::_vftable_;
  this->m_pScript = 0;
  this->m_uSize = 0;
  if ( !FileName )
    return this;
  CFileEx::CFileEx(&v4, UNUSED_ARG());
  LOBYTE(v5) = 1;
  CFileEx::Open(&v4.IFileEx, FileName, CFile_BINARY|CFile_READ, 0, UNUSED_ARG(), UNUSED_ARG());
  this->m_uSize = CFileEx::Size(&v4);
  this->m_pScript = (const char *)operator new[](this->m_uSize + 1);
  this->m_pScript[this->m_uSize] = 0;
  CFileEx::Read(&v4.IFileEx.__vftable, (void *)this->m_pScript, 1, this->m_uSize, UNUSED_ARG(), UNUSED_ARG());
  CFileEx::Close(&v4.IFileEx, UNUSED_ARG(), UNUSED_ARG());
  LOBYTE(v5) = 0;
  CFileEx::~CFileEx(&v4);
  return this;
}


// address=[0x160dd00]
// Decompiled from void __thiscall CStdScriptFile::~CStdScriptFile(CStdScriptFile *this)
 CStdScriptFile::~CStdScriptFile(void) {
  
  this->__vftable = (IScriptFile_vtbl *)&CStdScriptFile::_vftable_;
  if ( this->m_pScript )
  {
    operator delete[]((void *)this->m_pScript);
    this->m_pScript = 0;
  }
  IScriptFile::~IScriptFile(this);
}


// address=[0x160dd50]
// Decompiled from const char *__thiscall CStdScriptFile::GetScript(CStdScriptFile *this)
char const *  CStdScriptFile::GetScript(void) {
  
  return this->m_pScript;
}


// address=[0x160dd70]
// Decompiled from int __thiscall CStdScriptFile::GetSize(CStdScriptFile *this)
unsigned int  CStdScriptFile::GetSize(void) {
  
  return this->m_uSize;
}


#endif // Already implemented
