#include "CConfigVarFloat.h"

// Definitions for class CConfigVarFloat

// address=[0x2efa030]
// Decompiled from double __thiscall CConfigVarFloat::GetFloatValue(CConfigVarFloat *this)
float  CConfigVarFloat::GetFloatValue(void)const {
  
  return *((float *)this + 2);
}


// address=[0x2efa0b0]
// Decompiled from int __thiscall CConfigVarFloat::GetIntValue(CConfigVarFloat *this)
int  CConfigVarFloat::GetIntValue(void)const {
  
  return (int)*((float *)this + 2);
}


// address=[0x2efa290]
// Decompiled from CConfigVarFloat *__thiscall CConfigVarFloat::SetValue(CConfigVarFloat *this, int a2)
void  CConfigVarFloat::SetValue(int a2) {
  
  CConfigVarFloat *result; // eax

  result = this;
  *((float *)this + 2) = (float)a2;
  return result;
}


// address=[0x2efa2b0]
// Decompiled from CConfigVarFloat *__thiscall CConfigVarFloat::SetValue(CConfigVarFloat *this, float a2)
void  CConfigVarFloat::SetValue(float a2) {
  
  CConfigVarFloat *result; // eax

  result = this;
  *((float *)this + 2) = a2;
  return result;
}


// address=[0x2ef86f0]
// Decompiled from CConfigVarFloat *__thiscall CConfigVarFloat::CConfigVarFloat(CConfigVarFloat *this, float a2)
 CConfigVarFloat::CConfigVarFloat(float) {
  
  CDynamicConfigVar::CDynamicConfigVar(this, 3, 1);
  *(_DWORD *)this = &CConfigVarFloat::_vftable_;
  *((float *)this + 2) = a2;
  return this;
}


// address=[0x2ef8c20]
// Decompiled from void __thiscall CConfigVarFloat::~CConfigVarFloat(CConfigVarFloat *this)
 CConfigVarFloat::~CConfigVarFloat(void) {
  
  *(_DWORD *)this = &CConfigVarFloat::_vftable_;
  CDynamicConfigVar::~CDynamicConfigVar(this);
}


