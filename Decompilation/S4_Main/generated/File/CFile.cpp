#include "CFile.h"

// Definitions for class CFile

// address=[0x135ca40]
// Decompiled from CFile *__thiscall CFile::CFile(CFile *this)
 CFile::CFile(void) {
  
  IFSNode::IFSNode(this);
  *(_DWORD *)this = CFile::_vftable_;
  std::string::string((char *)this + 4, (char *)&dword_3686924[1]);
  std::string::string();
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 8) = 1;
  std::string::operator=((char *)this + 36, " /\n\r\t");
  return this;
}


// address=[0x135d3a0]
// Decompiled from void __thiscall CFile::~CFile(CFile *this)
 CFile::~CFile(void) {
  
  *(_DWORD *)this = CFile::_vftable_;
  CFile::Close(this, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
  std::string::~string((char *)this + 36);
  std::string::~string((char *)this + 4);
  IFSNode::~IFSNode(this);
}


// address=[0x135df00]
// Decompiled from int __thiscall CFile::Accept(CFile *this, struct IFSVisitor *a2)
void  CFile::Accept(class IFSVisitor & a2) {
  
  return (*(int (__thiscall **)(struct IFSVisitor *, CFile *))(*(_DWORD *)a2 + 8))(a2, this);
}


// address=[0x135dff0]
// Decompiled from char *__thiscall CFile::GetName(char *this)
std::string const &  CFile::GetName(void) {
  
  return this + 4;
}


// address=[0x2f01020]
// Decompiled from _DWORD *__thiscall CFile::CFile(_DWORD *this, _Cnd_internal_imp_t *a2, int a3)
 CFile::CFile(std::wstring const & a2, unsigned int a3) {
  
  wchar_t *v3; // eax

  IFSNode::IFSNode(this);
  *this = CFile::_vftable_;
  std::string::string();
  std::string::string();
  v3 = (wchar_t *)std::wstring::c_str(a2);
  CFile::CFile(v3, a3);
  CFile::~CFile();
  return this;
}


// address=[0x2f010d0]
// Decompiled from _DWORD *__thiscall CFile::CFile(_DWORD *this, wchar_t *FileName, int a3)
 CFile::CFile(wchar_t const * FileName, unsigned int a3) {
  
  CFile *v4; // [esp+4h] [ebp-64h]
  _BYTE v6[72]; // [esp+10h] [ebp-58h] BYREF
  int v7; // [esp+64h] [ebp-4h]

  IFSNode::IFSNode(this);
  v7 = 0;
  *this = CFile::_vftable_;
  std::string::string();
  std::string::string();
  LOBYTE(v7) = 2;
  if ( a3 )
  {
    std::string::operator=(this + 9, " /\n\r\t");
    CFile::Open(FileName, a3, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
  }
  else
  {
    v4 = CFile::CFile((CFile *)v6);
    LOBYTE(v7) = 3;
    CFile::operator=(v4);
    LOBYTE(v7) = 2;
    CFile::~CFile();
  }
  return this;
}


// address=[0x2f011c0]
// Decompiled from int __stdcall CFile::Open(_Cnd_internal_imp_t *a1, int a2, char *Str, int a4)
void  CFile::Open(std::wstring const & a1, unsigned int a2, char * Str, int a4) {
  
  wchar_t *v4; // eax

  v4 = (wchar_t *)std::wstring::c_str(a1);
  return CFile::Open(v4, a2, Str, a4);
}


// address=[0x2f011f0]
// Decompiled from void __thiscall CFile::Open(_DWORD *this, wchar_t *FileName, char a3, char *Str, int a5)
void  CFile::Open(wchar_t const * FileName, unsigned int a3, char * Str, int a5) {
  
  wchar_t *v5; // eax
  _BYTE pExceptionObject[552]; // [esp+8h] [ebp-254h] BYREF
  _BYTE v8[28]; // [esp+230h] [ebp-2Ch] BYREF
  int v9; // [esp+258h] [ebp-4h]

  std::wstring::wstring(v8);
  v9 = 0;
  CFile::OpenMaskToCWStr(this, a3, (int)v8);
  v5 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v8);
  this[17] = CFileMgr::Open(FileName, v5, Str, a5);
  if ( !this[17] )
  {
    CBBFileException::CBBFileException((CBBFileException *)pExceptionObject, 2, FileName);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCBBFileException__);
  }
  v9 = -1;
  std::wstring::~wstring(v8);
}


// address=[0x2f012d0]
// Decompiled from size_t __thiscall CFile::Read(FILE **this, void *Buffer, size_t ElementSize, size_t ElementCount, int a5, int a6)
unsigned int  CFile::Read(void * Buffer, int ElementSize, int ElementCount, char * a5, int a6) {
  
  return j__fread(Buffer, ElementSize, ElementCount, this[17]);
}


// address=[0x2f01300]
// Decompiled from size_t __thiscall CFile::Write(FILE **this, void *Buffer, size_t ElementSize, size_t ElementCount, int a5, int a6)
unsigned int  CFile::Write(void const * Buffer, int ElementSize, int ElementCount, char * a5, int a6) {
  
  return j__fwrite(Buffer, ElementSize, ElementCount, this[17]);
}


// address=[0x2f01330]
// Decompiled from int __thiscall CFile::Seek(FILE **this, int Offset, int Origin, int a4, int a5)
int  CFile::Seek(int Offset, int Origin, char * a4, int a5) {
  
  int v6; // [esp+4h] [ebp-8h]

  v6 = j__fseek(this[17], Offset, Origin);
  if ( Origin == 1 )
    j__ftell(this[17]);
  return v6;
}


// address=[0x2f01380]
// Decompiled from int __thiscall CFile::Size(FILE **this)
int  CFile::Size(void)const {
  
  int v2; // [esp+0h] [ebp-Ch]
  int Offset; // [esp+4h] [ebp-8h]

  Offset = j__ftell(this[17]);
  j__fseek(this[17], 0, 2);
  v2 = j__ftell(this[17]);
  j__fseek(this[17], Offset, 0);
  return v2;
}


// address=[0x2f013e0]
// Decompiled from int __thiscall CFile::Tell(FILE **this, char *a2, int a3)
int  CFile::Tell(char * a2, int a3)const {
  
  return j__ftell(this[17]);
}


// address=[0x2f01400]
// Decompiled from int __thiscall CFile::Eof(FILE **this)
int  CFile::Eof(void) {
  
  return j__feof(this[17]);
}


// address=[0x2f01420]
// Decompiled from int __thiscall CFile::Error(FILE **this)
int  CFile::Error(void) {
  
  return j__ferror(this[17]);
}


// address=[0x2f01440]
// Decompiled from int __thiscall CFile::Close(CFile *this, char *a2, int a3)
int  CFile::Close(char * a2, int a3) {
  
  int result; // eax
  struct SFileDesc *v4; // [esp+0h] [ebp-Ch]

  if ( !*((_DWORD *)this + 17) )
    return 0;
  v4 = CFileMgr::CheckValidFilePtr(*((struct _iobuf **)this + 17), "CFile::Close", a2, a3);
  if ( v4 )
    CFileMgr::RemoveFromList(v4);
  result = j__fclose(*((FILE **)this + 17));
  *((_DWORD *)this + 17) = 0;
  return result;
}


// address=[0x2f016b0]
// Decompiled from FILE **__thiscall CFile::operator=(FILE **this, CDockState *a2)
class CFile &  CFile::operator=(class CFile & a2) {
  
  j__fclose(this[17]);
  this[17] = (FILE *)CFile::GetFile(a2);
  return this;
}


// address=[0x2f016f0]
// Decompiled from unsigned int __thiscall CFile::GetFile(CDockState *this)
struct _iobuf *  CFile::GetFile(void) {
  
  return *((_DWORD *)this + 17);
}


// address=[0x2f014c0]
// Decompiled from int __thiscall CFile::OpenMaskToCWStr(_DWORD *this, char a2, int a3)
void  CFile::OpenMaskToCWStr(unsigned int a2, std::wstring & a3) {
  
  int result; // eax

  if ( (a2 & 0x20) != 0 )
    std::wstring::operator+=((wchar_t *)L"a");
  if ( (a2 & 4) != 0 )
    std::wstring::operator+=((wchar_t *)L"r");
  if ( (a2 & 8) != 0 )
    std::wstring::operator+=((wchar_t *)L"w");
  if ( (a2 & 0x10) != 0 )
    std::wstring::operator+=((wchar_t *)L"+");
  if ( (a2 & 1) != 0 )
  {
    std::wstring::operator+=((wchar_t *)L"t");
    this[8] = 1;
  }
  result = a2 & 2;
  if ( (a2 & 2) == 0 )
    return result;
  result = std::wstring::operator+=((wchar_t *)L"b");
  this[8] = 0;
  return result;
}


