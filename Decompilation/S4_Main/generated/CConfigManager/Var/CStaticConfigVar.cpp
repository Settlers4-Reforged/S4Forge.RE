#if FALSE
#include "CStaticConfigVar.h"

// Definitions for class CStaticConfigVar

// address=[0x12fca40]
// Decompiled from CConfigVar *__thiscall CStaticConfigVar::~CStaticConfigVar(CStaticConfigVar *this)
 CStaticConfigVar::~CStaticConfigVar(void) {
  
  return CConfigVar::~CConfigVar(this);
}


// address=[0x2eeeea0]
// Decompiled from CStaticConfigVar *__thiscall CStaticConfigVar::CStaticConfigVar(  CStaticConfigVar *this,  int a2,  int arg4,  T_CFGVAR_TYPE a3,  bool a4)
 CStaticConfigVar::CStaticConfigVar(char const * a2, char const * a3, enum T_CFGVAR_TYPE a4, int a5) {
  
  CConfigManager *Instance; // [esp+4h] [ebp-14h]

  CConfigVar::CConfigVar(this, 1, a3, a4);
  this->__vftable = (CConfigVar_vtbl *)&CStaticConfigVar::_vftable_;
  Instance = CConfigManagerPtr::GetInstance();
  Instance->AddStaticConfigVar(a2);
  return this;
}


#endif // Already implemented
