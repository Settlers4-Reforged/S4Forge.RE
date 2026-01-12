#include "CDynamicConfigVar.h"

// Definitions for class CDynamicConfigVar

// address=[0x2ef8cb0]
// Decompiled from CConfigVar *__thiscall CDynamicConfigVar::~CDynamicConfigVar(CDynamicConfigVar *this)

 CDynamicConfigVar::~CDynamicConfigVar(void) {
  
  return CConfigVar::~CConfigVar(this);
}


// address=[0x2ef8800]
// Decompiled from _BYTE *__thiscall CDynamicConfigVar::CDynamicConfigVar(_BYTE *this, char a2, char a3)

 CDynamicConfigVar::CDynamicConfigVar(enum T_CFGVAR_TYPE,int) {
  
  CConfigVar::CConfigVar(this, 0, a2, a3);
  *(_DWORD *)this = &CDynamicConfigVar::_vftable_;
  return this;
}


