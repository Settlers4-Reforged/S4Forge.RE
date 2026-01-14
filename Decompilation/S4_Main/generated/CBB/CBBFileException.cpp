#include "all_headers.h"

// Definitions for class CBBFileException

// address=[0x14c2e30]
// Decompiled from int __thiscall CBBFileException::Cause(CBBFileException *this)
int  CBBFileException::Cause(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x14c2e50]
// Decompiled from const char *__thiscall CBBFileException::FileName(type_info *this)
wchar_t const *  CBBFileException::FileName(void)const {
  
  return (char *)this + 8;
}


// address=[0x14dfb00]
// Decompiled from _DWORD *__thiscall CBBFileException::CBBFileException(_DWORD *this, struct boost::exception_detail::clone_base *a2)
 CBBFileException::CBBFileException(class CBBFileException const &) {
  
  CBBException::CBBException((boost::exception_detail::clone_base *)this, a2);
  *this = &CBBFileException::_vftable_;
  this[1] = *((_DWORD *)a2 + 1);
  qmemcpy(this + 2, (char *)a2 + 8, 0x220u);
  return this;
}


// address=[0x2f309f0]
// Decompiled from CBBFileException *__thiscall CBBFileException::CBBFileException(CBBFileException *this, int a2, const wchar_t *a3)
 CBBFileException::CBBFileException(int,wchar_t const *) {
  
  CBBException::CBBException(this);
  *(_DWORD *)this = &CBBFileException::_vftable_;
  *((_DWORD *)this + 1) = a2;
  BBSupportLib::BBSCopyString<wchar_t>((char *)this + 8, a3, 544);
  return this;
}


// address=[0x2f30a70]
// Decompiled from CBBException *__thiscall CBBFileException::~CBBFileException(CBBFileException *this)
 CBBFileException::~CBBFileException(void) {
  
  *(_DWORD *)this = &CBBFileException::_vftable_;
  return CBBException::~CBBException(this);
}


// address=[0x2f30a90]
// Decompiled from char __thiscall CBBFileException::GetErrorMessage(CBBFileException *this, char *a2, unsigned int a3)
bool  CBBFileException::GetErrorMessage(char *,unsigned int) {
  
  const char *v3; // eax
  const char *v4; // eax
  int v6; // [esp+4h] [ebp-498h]
  char v8[88]; // [esp+10h] [ebp-48Ch] BYREF
  _BYTE v9[28]; // [esp+68h] [ebp-434h] BYREF
  char Buffer[1032]; // [esp+84h] [ebp-418h] BYREF
  int v11; // [esp+498h] [ebp-4h]

  memset(Buffer, 0, sizeof(Buffer));
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v8);
  v11 = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
    v9,
    (char *)this + 8);
  LOBYTE(v11) = 1;
  v6 = *((_DWORD *)this + 1);
  if ( v6 == 2 )
  {
    v3 = (const char *)std::string::c_str(v9);
    j__sprintf(Buffer, "File \"%s\" not found!", v3);
  }
  else
  {
    v4 = (const char *)std::string::c_str(v9);
    if ( v6 == 3 )
      j__sprintf(Buffer, "Error reading file \"%s\"!", v4);
    else
      j__sprintf(Buffer, "An file error occurred (\"%s\")!", v4);
  }
  BBSupportLib::BBSCopyString<char>(a2, Buffer, a3);
  LOBYTE(v11) = 0;
  std::string::~string(v9);
  v11 = -1;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v8);
  return 1;
}


