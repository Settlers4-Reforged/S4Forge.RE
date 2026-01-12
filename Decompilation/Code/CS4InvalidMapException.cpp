#include "CS4InvalidMapException.h"

// Definitions for class CS4InvalidMapException

// address=[0x1313ec0]
// Decompiled from boost::exception_detail::clone_base *__thiscall CS4InvalidMapException::CS4InvalidMapException(
        boost::exception_detail::clone_base *this,
        struct boost::exception_detail::clone_base *a2)

 CS4InvalidMapException::CS4InvalidMapException(class CS4InvalidMapException const &) {
  
  CBBException::CBBException(this, a2);
  *(_DWORD *)this = &CS4InvalidMapException::_vftable_;
  return this;
}


// address=[0x1313ef0]
// Decompiled from CS4InvalidMapException *__thiscall CS4InvalidMapException::CS4InvalidMapException(CS4InvalidMapException *this)

 CS4InvalidMapException::CS4InvalidMapException(void) {
  
  CBBException::CBBException(this);
  *(_DWORD *)this = &CS4InvalidMapException::_vftable_;
  return this;
}


// address=[0x1313f80]
// Decompiled from CBBException *__thiscall CS4InvalidMapException::~CS4InvalidMapException(CS4InvalidMapException *this)

 CS4InvalidMapException::~CS4InvalidMapException(void) {
  
  *(_DWORD *)this = &CS4InvalidMapException::_vftable_;
  return CBBException::~CBBException(this);
}


