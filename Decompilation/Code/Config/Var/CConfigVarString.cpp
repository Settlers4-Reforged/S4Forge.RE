#include "CConfigVarString.h"

// Definitions for class CConfigVarString

// address=[0x2efa0f0]
// Decompiled from int __thiscall CConfigVarString::GetStringValue(char *this, int a2)

std::string  CConfigVarString::GetStringValue(void)const {
  
  std::string::string(this + 8);
  return a2;
}


// address=[0x2efa310]
// Decompiled from int __stdcall CConfigVarString::SetValue(int a1)

void  CConfigVarString::SetValue(std::string const &) {
  
  return std::string::operator=(a1);
}


// address=[0x2efa340]
// Decompiled from void *__thiscall CConfigVarString::SetValue(CConfigVarString *this, char *Str)

void  CConfigVarString::SetValue(char const *) {
  
  return std::string::operator=((char *)this + 8, Str);
}


// address=[0x2ef8770]
// Decompiled from _DWORD *__thiscall CConfigVarString::CConfigVarString(_DWORD *this, int a2)

 CConfigVarString::CConfigVarString(std::string const &) {
  
  CDynamicConfigVar::CDynamicConfigVar(this, 4, 1);
  *this = &CConfigVarString::_vftable_;
  std::string::string(a2);
  return this;
}


// address=[0x2ef8c80]
// Decompiled from void __thiscall CConfigVarString::~CConfigVarString(CConfigVarString *this)

 CConfigVarString::~CConfigVarString(void) {
  
  *(_DWORD *)this = &CConfigVarString::_vftable_;
  std::string::~string((char *)this + 8);
  CDynamicConfigVar::~CDynamicConfigVar(this);
}


