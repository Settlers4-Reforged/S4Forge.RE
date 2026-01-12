#include "Data_t.h"

// Definitions for class Data_t

// address=[0x2fbec70]
// Decompiled from BSTR *__thiscall _bstr_t::Data_t::Data_t(BSTR *this, OLECHAR *psz)
 _bstr_t::Data_t::Data_t(wchar_t const *) {
  
  this[1] = 0;
  this[2] = (BSTR)1;
  *this = SysAllocString(psz);
  if ( !*this && psz )
    _com_issue_error(-2147024882);
  return this;
}


// address=[0x2fbedd0]
// Decompiled from void *__cdecl _bstr_t::Data_t::operator new(size_t Size)
static void * __cdecl _bstr_t::Data_t::operator new(unsigned int) {
  
  return operator new(Size);
}


// address=[0x2fbee70]
// Decompiled from int __thiscall _bstr_t::Data_t::GetString(_bstr_t::Data_t *this)
char const *  _bstr_t::Data_t::GetString(void)const {
  
  if ( !*((_DWORD *)this + 1) )
    *((_DWORD *)this + 1) = _com_util::ConvertBSTRToString(*(LPCWCH *)this);
  return *((_DWORD *)this + 1);
}


// address=[0x2fbeeb0]
// Decompiled from signed __int32 __thiscall _bstr_t::Data_t::Release(_bstr_t::Data_t *this)
unsigned long  _bstr_t::Data_t::Release(void) {
  
  signed __int32 v2; // [esp+8h] [ebp-Ch]

  v2 = _InterlockedDecrement((volatile signed __int32 *)this + 2);
  if ( !v2 && this )
    _bstr_t::Data_t::`scalar deleting destructor'(this, 1u);
  return v2;
}


// address=[0x2fbed90]
// Decompiled from void __thiscall _bstr_t::Data_t::~Data_t(_bstr_t::Data_t *this)
 _bstr_t::Data_t::~Data_t(void) {
  
  _bstr_t::Data_t::_Free(this);
}


// address=[0x2fbef10]
// Decompiled from _bstr_t::Data_t *__thiscall _bstr_t::Data_t::_Free(void **this)
void  _bstr_t::Data_t::_Free(void) {
  
  _bstr_t::Data_t *result; // eax

  result = (_bstr_t::Data_t *)this;
  if ( *this )
  {
    SysFreeString((BSTR)*this);
    result = (_bstr_t::Data_t *)this;
    *this = 0;
  }
  if ( !this[1] )
    return result;
  result = (_bstr_t::Data_t *)operator delete[](this[1]);
  this[1] = 0;
  return result;
}


