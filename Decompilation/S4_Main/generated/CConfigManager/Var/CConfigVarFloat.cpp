#if FALSE
#include "CConfigVarFloat.h"

// Definitions for class CConfigVarFloat

// address=[0x2efa030]
// Decompiled from double __thiscall CConfigVarFloat::GetFloatValue(CConfigVarFloat *this)
float  CConfigVarFloat::GetFloatValue(void)const {
  
  return this->value;
}


// address=[0x2efa0b0]
// Decompiled from int __thiscall CConfigVarFloat::GetIntValue(CConfigVarFloat *this)
int  CConfigVarFloat::GetIntValue(void)const {
  
  return (int)this->value;
}


// address=[0x2efa290]
// Decompiled from void __thiscall CConfigVarFloat::SetValue(CConfigVarFloat *this, int a2)
void  CConfigVarFloat::SetValue(int a2) {
  
  this->value = (float)a2;
}


// address=[0x2efa2b0]
// Decompiled from void __thiscall CConfigVarFloat::SetValue(CConfigVarFloat *this, float a2)
void  CConfigVarFloat::SetValue(float a2) {
  
  this->value = a2;
}


// address=[0x2ef86f0]
// Decompiled from void __thiscall CConfigVarFloat::CConfigVarFloat(CConfigVarFloat *this, float a2)
 CConfigVarFloat::CConfigVarFloat(float a2) {
  
  CDynamicConfigVar::CDynamicConfigVar(this, CONFIGVAR_TYPE_FLOAT, 1);
  this->__vftable = (CConfigVar_vtbl *)&CConfigVarFloat::_vftable_;
  this->value = a2;
}


// address=[0x2ef8c20]
// Decompiled from void __thiscall CConfigVarFloat::~CConfigVarFloat(CConfigVarFloat *this)
 CConfigVarFloat::~CConfigVarFloat(void) {
  
  this->__vftable = (CConfigVar_vtbl *)&CConfigVarFloat::_vftable_;
  CDynamicConfigVar::~CDynamicConfigVar(this);
}


#endif // Already implemented
