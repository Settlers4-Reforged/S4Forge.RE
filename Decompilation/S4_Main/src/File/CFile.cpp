#include "CFile.h"

#include "File/CFileMgr.h"
#include "CBB/CBBFileException.h"

// Definitions for class CFile

// address=[0x135ca40]
// Decompiled from CFile *__thiscall CFile::CFile(CFile *this)
CFile::CFile(void) : m_spName("test"), m_spU24(), m_hFile(0), m_bTextMode(1) {}
//  {
//   IFSNode::IFSNode(this);
//   this->__vftable = (IFSNode_vtbl *)CFile::_vftable_;
//   std::string::string((struct std::string *)&this->m_spName, "test");
//   std::string::string(&this->m_spU24);
//   this->m_hFile = 0;
//   this->m_bTextMode = 1;
//   std::string::operator=(&this->m_spU24, " /\n\r\t");
//   return this;
// }

// address=[0x135d3a0]
// Decompiled from void __thiscall CFile::~CFile(CFile *this)
CFile::~CFile(void)
{
  this->Close(CFileLog);
}

// address=[0x135df00]
// Decompiled from int __thiscall CFile::Accept(CFile *this, struct IFSVisitor *a2)
void CFile::Accept(class IFSVisitor &a2)
{
  throw new std::exception("Not implemented");
  // return (*(int(__thiscall **)(struct IFSVisitor *, CFile *))(*(_DWORD *)a2 + 8))(a2, this);
}

// address=[0x135dff0]
// Decompiled from std::string **__thiscall CFile::GetName(CFile *this)
std::string const &CFile::GetName(void)
{
  return this->m_spName;
}

// address=[0x2f01020]
// Decompiled from CFile *__thiscall CFile::CFile(CFile *this, wstring *a2, int a3)
CFile::CFile(std::wstring const &a2, unsigned int a3) : CFile(a2.c_str(), a3) {}
// {
//   wchar_t *v3;        // eax
//   CFile v6;           // [esp+8h] [ebp-58h] BYREF
//   int exceptionBlock; // [esp+5Ch] [ebp-4h]
//   IFSNode::IFSNode(this);
//   exceptionBlock = 0;
//   this->__vftable = (IFSNode_vtbl *)&CFile::_vftable_;
//   std::string::string(&this->m_spName);
//   std::string::string(&this->m_spU24);
//   LOBYTE(exceptionBlock) = 2;
//   v3 = std::wstring::c_str(a2);
//   CFile::CFile(v3, a3);
//   CFile::~CFile(&v6);
//   return this;
// }

// address=[0x2f010d0]
// Decompiled from CFile *__thiscall CFile::CFile(CFile *this, wchar_t *FileName, int a3)
CFile::CFile(wchar_t const *FileName, unsigned int _eFileMode) : CFile()
{

  CFile *v4; // [esp+4h] [ebp-64h]
  CFile v6;  // [esp+10h] [ebp-58h] BYREF
  int v7;    // [esp+64h] [ebp-4h]
  if (_eFileMode)
  {
    this->m_spU24 = " /\n\r\t";
    this->Open(FileName, (CFile::Mode)_eFileMode, CFileLog);
  }
}

// address=[0x2f011c0]
// Decompiled from void __thiscall CFile::Open(CFile *this, wstring *a2, CFile::Mode a3, char *Str, int a5)
void CFile::Open(std::wstring const &_swpFileName, unsigned int _eFileMode, CFileLogAttributes)
{
  this->Open(_swpFileName.c_str(), _eFileMode, CFileLog);
}

// address=[0x2f011f0]
// Decompiled from void __thiscall CFile::Open(CFile *this, wchar_t *FileName, CFile::Mode a3, char *Str, int a5)
void CFile::Open(wchar_t const *FileName, unsigned int a3, CFileLogAttributes)
{

  wchar_t *v5;                 // eax
  _BYTE pExceptionObject[552]; // [esp+8h] [ebp-254h] BYREF
  int v9;                      // [esp+258h] [ebp-4h]

  std::wstring swFileMode; // [esp+230h] [ebp-2Ch] BYREF
  this->OpenMaskToCWStr(a3, swFileMode);
  this->m_hFile = CFileMgr::Open(FileName, swFileMode.c_str(), CFileLogFwd);
  if (!this->m_hFile)
    throw new CBBFileException(2, FileName);
}

// address=[0x2f012d0]
// Decompiled from size_t __thiscall CFile::Read(  struct CFile *this,  void *Buffer,  size_t ElementSize,  size_t ElementCount,  int a5,  int a6)
unsigned int CFile::Read(void *Buffer, int ElementSize, int ElementCount, CFileLogAttributes)
{

  return fread(Buffer, ElementSize, ElementCount, this->m_hFile);
}

// address=[0x2f01300]
// Decompiled from unsigned int __thiscall CFile::Write(  struct CFile *this,  const void *Buffer,  int ElementSize,  int ElementCount,  char *a5,  int a6)
unsigned int CFile::Write(const void *Buffer, int ElementSize, int ElementCount, CFileLogAttributes)
{

  return fwrite(Buffer, ElementSize, ElementCount, this->m_hFile);
}

// address=[0x2f01330]
// Decompiled from int __thiscall CFile::Seek(CFile *this, int Offset, int Origin, int a4, int a5)
int CFile::Seek(int Offset, int Origin, char *a4, int a5)
{

  int v6; // [esp+4h] [ebp-8h]

  v6 = fseek(this->m_hFile, Offset, Origin);
  if (Origin == 1)
    ftell(this->m_hFile);
  return v6;
}

// address=[0x2f01380]
// Decompiled from int __thiscall CFile::Size(CFile *this)
int CFile::Size(void) const
{

  int v2;     // [esp+0h] [ebp-Ch]
  int Offset; // [esp+4h] [ebp-8h]

  Offset = ftell(this->m_hFile);
  fseek(this->m_hFile, 0, 2);
  v2 = ftell(this->m_hFile);
  fseek(this->m_hFile, Offset, 0);
  return v2;
}

// address=[0x2f013e0]
// Decompiled from int __thiscall CFile::Tell(CFile *this, char *a2, int a3)
int CFile::Tell(char *a2, int a3) const
{

  return ftell(this->m_hFile);
}

// address=[0x2f01400]
// Decompiled from int __thiscall CFile::Eof(CFile *this)
int CFile::Eof(void)
{

  return feof(this->m_hFile);
}

// address=[0x2f01420]
// Decompiled from int __thiscall CFile::Error(CFile *this)
int CFile::Error(void)
{

  return ferror(this->m_hFile);
}

// address=[0x2f01440]
// Decompiled from int __thiscall CFile::Close(CFile *this, char *a2, int a3)
int CFile::Close(char *a2, int a3)
{

  int result; // eax

  if (!this->m_hFile)
    return 0;
  auto v4 = CFileMgr::CheckValidFilePtr(this->m_hFile, "CFile::Close", a2, a3);
  if (v4)
    CFileMgr::RemoveFromList(v4);
  result = fclose(this->m_hFile);
  this->m_hFile = 0;
  return result;
}

// address=[0x2f016b0]
// Decompiled from CFile *__thiscall CFile::operator=(CFile *this, CFile *a2)
class CFile &CFile::operator=(class CFile &a2)
{

  fclose(this->m_hFile);
  this->m_hFile = a2.GetFile();
  return *this;
}

// address=[0x2f016f0]
// Decompiled from FILE *__thiscall CFile::GetFile(CFile *this)
struct _iobuf *CFile::GetFile(void)
{

  return this->m_hFile;
}

// address=[0x2f014c0]
// Decompiled from void __thiscall CFile::OpenMaskToCWStr(CFile *this, CFile::Mode a2, char *_spFileMode)
void CFile::OpenMaskToCWStr(unsigned int a2, std::wstring &_spFileMode)
{

  if ((a2 & CFile_APPEND) != 0)
    _spFileMode += L"a";
  if ((a2 & CFile_READ) != 0)
    _spFileMode += L"r";
  if ((a2 & CFile_WRITE) != 0)
    _spFileMode += L"w";
  if ((a2 & CFile_SPECIAL) != 0)
    _spFileMode += L"+";
  if ((a2 & CFile_TEXT) != 0)
  {
    _spFileMode += L"t";
    this->m_bTextMode = 1;
  }
  if ((a2 & CFile_BINARY) != 0)
  {
    _spFileMode += L"b";
    this->m_bTextMode = 0;
  }
}
