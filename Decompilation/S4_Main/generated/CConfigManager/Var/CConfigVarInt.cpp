#if FALSE
#include "CConfigVarInt.h"

// Definitions for class CConfigVarInt

// address=[0x2efa050]
// Decompiled from double __thiscall CConfigVarInt::GetFloatValue(CConfigVarInt *this)
float  CConfigVarInt::GetFloatValue(void)const {
  
  return (float)this->value;
}


// address=[0x2efa0d0]
// Decompiled from int __thiscall CConfigVarInt::GetIntValue(CConfigVarInt *this)
int  CConfigVarInt::GetIntValue(void)const {
  
  return this->value;
}


// address=[0x2efa2d0]
// Decompiled from void __thiscall CConfigVarInt::SetValue(CConfigVarInt *this, int a2)
void  CConfigVarInt::SetValue(int a2) {
  
  this->value = a2;
}


// address=[0x2efa2f0]
// Decompiled from void __thiscall CConfigVarInt::SetValue(CConfigVarInt *this, float a2)
void  CConfigVarInt::SetValue(float a2) {
  
  this->value = (int)a2;
}


// address=[0x2ef8730]
// Decompiled from CConfigVarInt *__thiscall CConfigVarInt::CConfigVarInt(CConfigVarInt *this, int a2)
 CConfigVarInt::CConfigVarInt(int a2) {
  
  CDynamicConfigVar::CDynamicConfigVar(this, CONFIGVAR_TYPE_INT, 1);
  this->__vftable = (CConfigVar_vtbl *)&CConfigVarInt::_vftable_;
  this->value = a2;
  return this;
}


// address=[0x2ef8c50]
// Decompiled from void __thiscall CConfigVarInt::~CConfigVarInt(CConfigVarInt *this)
 CConfigVarInt::~CConfigVarInt(void) {
  
  *(_DWORD *)this = &CConfigVarInt::_vftable_;
  CDynamicConfigVar::~CDynamicConfigVar(this);
}


#endif // Already implemented
