#include "SerialError.h"

// Definitions for class SerialError

// address=[0x13f2590]
// Decompiled from boost::exception_detail::clone_base *__thiscall CPersistence::SerialError::SerialError(
        boost::exception_detail::clone_base *this,
        struct boost::exception_detail::clone_base *a2)

 CPersistence::SerialError::SerialError(class CPersistence::SerialError const &) {
  
  CPersistence::Error::Error(this, a2);
  *(_DWORD *)this = &CPersistence::SerialError::_vftable_;
  return this;
}


// address=[0x13f25c0]
// Decompiled from CPersistence::SerialError *__thiscall CPersistence::SerialError::SerialError(CPersistence::SerialError *this)

 CPersistence::SerialError::SerialError(void) {
  
  CPersistence::Error::Error(this);
  *(_DWORD *)this = &CPersistence::SerialError::_vftable_;
  return this;
}


// address=[0x13f5600]
// Decompiled from const char *__thiscall CPersistence::SerialError::What(CPersistence::SerialError *this)

char const *  CPersistence::SerialError::What(void)const {
  
  return "persistence (de)-serialisation error";
}


