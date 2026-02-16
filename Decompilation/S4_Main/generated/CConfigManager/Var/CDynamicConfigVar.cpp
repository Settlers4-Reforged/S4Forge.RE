#if FALSE
#include "CDynamicConfigVar.h"

// Definitions for class CDynamicConfigVar

// address=[0x2ef8cb0]
// Decompiled from CConfigVar *__thiscall CDynamicConfigVar::~CDynamicConfigVar(CDynamicConfigVar *this)
 CDynamicConfigVar::~CDynamicConfigVar(void) {
  
  return CConfigVar::~CConfigVar(this);
}


// address=[0x2ef8800]
// Decompiled from CDynamicConfigVar *__thiscall CDynamicConfigVar::CDynamicConfigVar(CDynamicConfigVar *this, T_CFGVAR_TYPE a2, bool a4)
 CDynamicConfigVar::CDynamicConfigVar(enum T_CFGVAR_TYPE a2, int a4) {
  
  CConfigVar::CConfigVar(this, 0, a2, a4);
  this->__vftable = (CConfigVar_vtbl *)&CDynamicConfigVar::_vftable_;
  return this;
}


#endif // Already implemented
