#include "all_headers.h"

// Definitions for class CStaticConfigVarInt

// address=[0x12fc830]
// Decompiled from CStaticConfigVarInt *__thiscall CStaticConfigVarInt::CStaticConfigVarInt(  CStaticConfigVarInt *this,  const char *a2,  const char *a3,  int a4)
 CStaticConfigVarInt::CStaticConfigVarInt(char const *,char const *,int) {
  
  CStaticConfigVar::CStaticConfigVar(this, a2, a3, 1, 1);
  *(_DWORD *)this = &CStaticConfigVarInt::_vftable_;
  *((_DWORD *)this + 2) = a4;
  return this;
}


// address=[0x12fca60]
// Decompiled from void __thiscall CStaticConfigVarInt::~CStaticConfigVarInt(CStaticConfigVarInt *this)
 CStaticConfigVarInt::~CStaticConfigVarInt(void) {
  
  CStaticConfigVar::~CStaticConfigVar(this);
}


// address=[0x12fcc30]
// Decompiled from int __thiscall CStaticConfigVarInt::operator int(_DWORD *this)
 CStaticConfigVarInt::operator int(void)const {
  
  return this[2];
}


// address=[0x12fd180]
// Decompiled from double __thiscall CStaticConfigVarInt::GetFloatValue(CStaticConfigVarInt *this)
float  CStaticConfigVarInt::GetFloatValue(void)const {
  
  return (float)*((int *)this + 2);
}


// address=[0x12fd1d0]
// Decompiled from int __thiscall CStaticConfigVarInt::GetIntValue(CStaticConfigVarInt *this)
int  CStaticConfigVarInt::GetIntValue(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x12fd6d0]
// Decompiled from CStaticConfigVarInt *__thiscall CStaticConfigVarInt::SetValue(CStaticConfigVarInt *this, int a2)
void  CStaticConfigVarInt::SetValue(int) {
  
  CStaticConfigVarInt *result; // eax

  result = this;
  *((_DWORD *)this + 2) = a2;
  return result;
}


// address=[0x12fd6f0]
// Decompiled from int __thiscall CStaticConfigVarInt::SetValue(CStaticConfigVarInt *this, float a2)
void  CStaticConfigVarInt::SetValue(float) {
  
  int result; // eax

  result = (int)a2;
  *((_DWORD *)this + 2) = (int)a2;
  return result;
}


// address=[0x1355250]
// Decompiled from _DWORD *__thiscall CStaticConfigVarInt::operator=(_DWORD *this, int a2)
class CStaticConfigVarInt &  CStaticConfigVarInt::operator=(int) {
  
  this[2] = a2;
  return this;
}


