#include "CBBMemoryException.h"

// Definitions for class CBBMemoryException

// address=[0x2f30980]
// Decompiled from CBBMemoryException *__thiscall CBBMemoryException::CBBMemoryException(CBBMemoryException *this)
 CBBMemoryException::CBBMemoryException(void) {
  
  CBBException::CBBException(this);
  *(_DWORD *)this = &CBBMemoryException::_vftable_;
  return this;
}


// address=[0x2f309a0]
// Decompiled from void __thiscall CBBMemoryException::~CBBMemoryException(_AFX_OLE_STATE *this)
 CBBMemoryException::~CBBMemoryException(void) {
  
  *(_DWORD *)this = &CBBMemoryException::_vftable_;
  CBBException::~CBBException(this);
}


// address=[0x2f309c0]
// Decompiled from char __thiscall CBBMemoryException::GetErrorMessage(CBBMemoryException *this, char *a2, unsigned int a3)
bool  CBBMemoryException::GetErrorMessage(char *,unsigned int) {
  
  BBSupportLib::BBSCopyString<char>(a2, "Out of memory!", a3);
  return 1;
}


// address=[0x2f337b0]
// Decompiled from boost::exception_detail::clone_base *__thiscall CBBMemoryException::CBBMemoryException(  boost::exception_detail::clone_base *this,  struct boost::exception_detail::clone_base *a2)
 CBBMemoryException::CBBMemoryException(class CBBMemoryException const &) {
  
  CBBException::CBBException(this, a2);
  *(_DWORD *)this = &CBBMemoryException::_vftable_;
  return this;
}


