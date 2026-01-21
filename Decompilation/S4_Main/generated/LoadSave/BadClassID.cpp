#include "BadClassID.h"

// Definitions for class BadClassID

// address=[0x13f24f0]
// Decompiled from boost::exception_detail::clone_base *__thiscall CPersistence::BadClassID::BadClassID(  boost::exception_detail::clone_base *this,  struct boost::exception_detail::clone_base *a2)
 CPersistence::BadClassID::BadClassID(class CPersistence::BadClassID const & a2) {
  
  CPersistence::Error::Error(this, a2);
  *(_DWORD *)this = &CPersistence::BadClassID::_vftable_;
  return this;
}


// address=[0x13f2520]
// Decompiled from CPersistence::BadClassID *__thiscall CPersistence::BadClassID::BadClassID(CPersistence::BadClassID *this)
 CPersistence::BadClassID::BadClassID(void) {
  
  CPersistence::Error::Error(this);
  *(_DWORD *)this = &CPersistence::BadClassID::_vftable_;
  return this;
}


// address=[0x13f55e0]
// Decompiled from const char *__thiscall CPersistence::BadClassID::What(CPersistence::BadClassID *this)
char const *  CPersistence::BadClassID::What(void)const {
  
  return "persistence bad class ID";
}


