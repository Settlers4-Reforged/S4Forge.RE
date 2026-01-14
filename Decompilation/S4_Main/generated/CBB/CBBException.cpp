#include "all_headers.h"

// Definitions for class CBBException

// address=[0x1313e80]
// Decompiled from CBBException *__thiscall CBBException::CBBException(  CBBException *this,  const struct boost::exception_detail::clone_base *a2)
 CBBException::CBBException(class CBBException const &) {
  
  *(_DWORD *)this = &CBBException::_vftable_;
  return this;
}


// address=[0x1313ea0]
// Decompiled from CBBException *__thiscall CBBException::CBBException(CBBException *this)
 CBBException::CBBException(void) {
  
  *(_DWORD *)this = &CBBException::_vftable_;
  return this;
}


// address=[0x2f30950]
// Decompiled from CBBException *__thiscall CBBException::~CBBException(CBBException *this)
 CBBException::~CBBException(void) {
  
  CBBException *result; // eax

  result = this;
  *(_DWORD *)this = &CBBException::_vftable_;
  return result;
}


// address=[0x2f30970]
// Decompiled from char __thiscall CBBException::GetErrorMessage(CBBException *this, char *a2, unsigned int a3)
bool  CBBException::GetErrorMessage(char *,unsigned int) {
  
  return 0;
}


