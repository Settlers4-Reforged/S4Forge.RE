#if FALSE
#include "CConfigVarString.h"

// Definitions for class CConfigVarString

// address=[0x2efa0f0]
// Decompiled from int __thiscall CConfigVarString::GetStringValue(char *this, int a2)
std::string  CConfigVarString::GetStringValue(void a2)const {
  
  std::string::string(this + 8);
  return a2;
}


// address=[0x2efa310]
// Decompiled from void __thiscall CConfigVarString::SetValue(CConfigVarString *this, void *a1)
void  CConfigVarString::SetValue(std::string const & a1) {
  
  std::string::operator=(&this->value, a1);
}


// address=[0x2efa340]
// Decompiled from void __thiscall CConfigVarString::SetValue(CConfigVarString *this, char *Str)
void  CConfigVarString::SetValue(char const * Str) {
  
  std::string::operator=(&this->value, Str);
}


// address=[0x2ef8770]
// Decompiled from CConfigVarString *__thiscall CConfigVarString::CConfigVarString(CConfigVarString *this, int a2)
 CConfigVarString::CConfigVarString(std::string const & a2) {
  
  CDynamicConfigVar::CDynamicConfigVar(this, CONFIGVAR_TYPE_STRING, 1);
  this->__vftable = (CConfigVar_vtbl *)&CConfigVarString::_vftable_;
  std::string::string(&this->value, a2);
  return this;
}


// address=[0x2ef8c80]
// Decompiled from CConfigVar *__thiscall CConfigVarString::~CConfigVarString(CConfigVarString *this)
 CConfigVarString::~CConfigVarString(void) {
  
  this->__vftable = (CConfigVar_vtbl *)&CConfigVarString::_vftable_;
  std::string::~string(&this->value);
  return CDynamicConfigVar::~CDynamicConfigVar(this);
}


#endif // Already implemented
