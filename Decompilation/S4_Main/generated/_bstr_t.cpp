#include "all_headers.h"

// Definitions for class _bstr_t

// address=[0x2fbecd0]
// Decompiled from BSTR **__thiscall _bstr_t::_bstr_t(BSTR **this, OLECHAR *psz)
 _bstr_t::_bstr_t(wchar_t const *) {
  
  BSTR *v3; // [esp+8h] [ebp-18h]
  BSTR *C; // [esp+Ch] [ebp-14h]

  C = (BSTR *)_bstr_t::Data_t::operator new(0xCu);
  if ( C )
    v3 = _bstr_t::Data_t::Data_t(C, psz);
  else
    v3 = 0;
  *this = v3;
  if ( !*this )
    _com_issue_error(-2147024882);
  return this;
}


// address=[0x2fbedb0]
// Decompiled from void __thiscall _bstr_t::~_bstr_t(_bstr_t *this)
 _bstr_t::~_bstr_t(void) {
  
  _bstr_t::_Free(this);
}


// address=[0x2fbedf0]
// Decompiled from int __thiscall _bstr_t::operator char const *(_bstr_t::Data_t **this)
 _bstr_t::operator char const *(void)const {
  
  if ( *this )
    return _bstr_t::Data_t::GetString(*this);
  else
    return 0;
}


// address=[0x2fbef80]
// Decompiled from _bstr_t::Data_t **__thiscall _bstr_t::_Free(_bstr_t::Data_t **this)
void  _bstr_t::_Free(void) {
  
  _bstr_t::Data_t **result; // eax

  result = this;
  if ( !*this )
    return result;
  result = (_bstr_t::Data_t **)_bstr_t::Data_t::Release(*this);
  *this = 0;
  return result;
}


