#if FALSE
#include "CSaveFile.h"

// Definitions for class CSaveFile

// address=[0x13e50e0]
// Decompiled from void __thiscall S4::CSaveFile::~CSaveFile(S4::CSaveFile *this)
 S4::CSaveFile::~CSaveFile(void) {
  
  CFile::~CFile(&this->m_cFile);
}


// address=[0x13e6580]
// Decompiled from int __thiscall S4::CSaveFile::GetFilePos(S4::CSaveFile *this)
unsigned int  S4::CSaveFile::GetFilePos(void) {
  
  return CFile::Tell(&this->m_cFile, UNUSED_ARG(), UNUSED_ARG());
}


// address=[0x13eb4f0]
// Decompiled from S4::CSaveFile *__thiscall S4::CSaveFile::CSaveFile(S4::CSaveFile *this, bool a2)
 S4::CSaveFile::CSaveFile(bool a2) {
  
  this->m_b1 = a2;
  CFile::CFile(&this->m_cFile);
  this->m_i2 = 0;
  return this;
}


// address=[0x13eb520]
// Decompiled from char __thiscall S4::CSaveFile::Open(S4::CSaveFile *this, std::wstring *a1, char a3)
bool  S4::CSaveFile::Open(std::wstring const & a1, int a3) {
  
  if ( (a3 & 2) != 0 )
  {
    CFile::Open(&this->m_cFile, a1, CFile_BINARY|CFile_WRITE|CFile_SPECIAL, UNUSED_ARG(), UNUSED_ARG());
  }
  else if ( (a3 & 1) != 0 )
  {
    CFile::Open(&this->m_cFile, a1, CFile_BINARY|CFile_READ, UNUSED_ARG(), UNUSED_ARG());
    CFile::Seek(&this->m_cFile, 0, 0, UNUSED_ARG(), UNUSED_ARG());
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
// Decompiled from size_t __thiscall S4::CSaveFile::Read(S4::CSaveFile *this, void *Buffer, size_t ElementSize)
int  S4::CSaveFile::Read(void * Buffer, int ElementSize) {
  
  size_t v4; // [esp+0h] [ebp-8h]

  v4 = CFile::Read(&this->m_cFile, Buffer, ElementSize, 1u, UNUSED_ARG(), UNUSED_ARG());
  if ( this->m_i2 )
    return -1;
  else
    return ElementSize * v4;
}


// address=[0x13eb600]
// Decompiled from unsigned int __thiscall S4::CSaveFile::Write(S4::CSaveFile *this, void *Buffer, size_t ElementSize)
int  S4::CSaveFile::Write(void const * Buffer, int ElementSize) {
  
  return CFile::Write(&this->m_cFile, Buffer, ElementSize, 1, UNUSED_ARG(), UNUSED_ARG());
}


// address=[0x13eb630]
// Decompiled from int __thiscall S4::CSaveFile::SetFilePos(S4::CSaveFile *this, int Offset, int Origin)
void  S4::CSaveFile::SetFilePos(int Offset, int Origin) {
  
  return CFile::Seek(&this->m_cFile, Offset, Origin, UNUSED_ARG(), UNUSED_ARG());
}


// address=[0x13eb660]
// Decompiled from int __thiscall S4::CSaveFile::GetFileSize(S4::CSaveFile *this)
unsigned int  S4::CSaveFile::GetFileSize(void) {
  
  return this->m_cFile.Size(&this->m_cFile, this);
}


// address=[0x13eb680]
// Decompiled from bool __thiscall S4::CSaveFile::Eof(S4::CSaveFile *this)
bool  S4::CSaveFile::Eof(void) {
  
  return CFile::Eof(&this->m_cFile) != 0;
}


#endif // Already implemented
