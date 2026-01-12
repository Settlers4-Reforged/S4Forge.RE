#include "CConfigVarInt.h"

// Definitions for class CConfigVarInt

// address=[0x2efa050]
// Decompiled from double __thiscall CConfigVarInt::GetFloatValue(CConfigVarInt *this)

float  CConfigVarInt::GetFloatValue(void)const {
  
  return (float)*((int *)this + 2);
}


// address=[0x2efa0d0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CConfigVarInt::GetIntValue(CConfigVarInt *this)

int  CConfigVarInt::GetIntValue(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2efa2d0]
// Decompiled from // MFC 3.1-14.0 32bit
CConfigVarInt *__thiscall CConfigVarInt::SetValue(CConfigVarInt *this, int a2)

void  CConfigVarInt::SetValue(int) {
  
  CConfigVarInt *result; // eax

  result = this;
  *((_DWORD *)this + 2) = a2;
  return result;
}


// address=[0x2efa2f0]
// Decompiled from int __thiscall CConfigVarInt::SetValue(CConfigVarInt *this, float a2)

void  CConfigVarInt::SetValue(float) {
  
  int result; // eax

  result = (int)a2;
  *((_DWORD *)this + 2) = (int)a2;
  return result;
}


// address=[0x2ef8730]
// Decompiled from CConfigVarInt *__thiscall CConfigVarInt::CConfigVarInt(CConfigVarInt *this, int a2)

 CConfigVarInt::CConfigVarInt(int) {
  
  CDynamicConfigVar::CDynamicConfigVar(this, 1, 1);
  *(_DWORD *)this = &CConfigVarInt::_vftable_;
  *((_DWORD *)this + 2) = a2;
  return this;
}


// address=[0x2ef8c50]
// Decompiled from void __thiscall CConfigVarInt::~CConfigVarInt(CConfigVarInt *this)

 CConfigVarInt::~CConfigVarInt(void) {
  
  *(_DWORD *)this = &CConfigVarInt::_vftable_;
  CDynamicConfigVar::~CDynamicConfigVar(this);
}


