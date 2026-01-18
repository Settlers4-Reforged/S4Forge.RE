#include "CConfigVar.h"

// Definitions for class CConfigVar

// address=[0x12fd170]
// Decompiled from double sub_16FD170()
float  CConfigVar::GetFloatValue(void)const {
  
  return 0.0;
}


// address=[0x12fd1a0]
// Decompiled from int __thiscall CConfigVar::GetIntArray(CConfigVar *this)
int *  CConfigVar::GetIntArray(void) {
  
  return 0;
}


// address=[0x12fd1b0]
// Decompiled from int __thiscall CConfigVar::GetIntArray(CConfigVar *this)
int const *  CConfigVar::GetIntArray(void)const {
  
  return 0;
}


// address=[0x12fd1c0]
// Decompiled from int CConfigVar::GetIntValue()
int  CConfigVar::GetIntValue(void)const {
  
  return 0;
}


// address=[0x12fd250]
// Decompiled from int __stdcall sub_16FD250(int a1)
std::string  CConfigVar::GetStringValue(void a1)const {
  
  std::string::string((char *)&off_366DCF4);
  return a1;
}


// address=[0x12fd690]
// Decompiled from void __stdcall CConfigVar::SetValue(int a1)
void  CConfigVar::SetValue(std::string const & a1) {
  
  ;
}


// address=[0x12fd6a0]
// Decompiled from void __thiscall CConfigVar::SetValue(CConfigVar *this, int a2)
void  CConfigVar::SetValue(int a2) {
  
  ;
}


// address=[0x12fd6b0]
// Decompiled from void __thiscall CConfigVar::SetValue(CConfigVar *this, float a2)
void  CConfigVar::SetValue(float a2) {
  
  ;
}


// address=[0x12fd6c0]
// Decompiled from void __thiscall CConfigVar::SetValue(CConfigVar *this, const char *a2)
void  CConfigVar::SetValue(char const * a2) {
  
  ;
}


// address=[0x160db90]
// Decompiled from int __thiscall CConfigVar::Size(CConfigVar *this)
int  CConfigVar::Size(void)const {
  
  return *((unsigned __int8 *)this + 6);
}


// address=[0x160dbb0]
// Decompiled from int __thiscall CConfigVar::Type(CConfigVar *this)
int  CConfigVar::Type(void)const {
  
  return *((unsigned __int8 *)this + 5);
}


// address=[0x2efa370]
// Decompiled from char __thiscall CConfigVar::Static(_BYTE *this)
bool  CConfigVar::Static(void)const {
  
  return this[4];
}


// address=[0x12fca20]
// Decompiled from CConfigVar *__thiscall CConfigVar::~CConfigVar(CConfigVar *this)
 CConfigVar::~CConfigVar(void) {
  
  CConfigVar *result; // eax

  result = this;
  *(_DWORD *)this = &CConfigVar::_vftable_;
  return result;
}


// address=[0x2ef86a0]
// Decompiled from _BYTE *__thiscall CConfigVar::CConfigVar(_BYTE *this, char a2, char a3, char a4)
 CConfigVar::CConfigVar(bool a2, enum T_CFGVAR_TYPE a3, int a4) {
  
  *(_DWORD *)this = &CConfigVar::_vftable_;
  this[4] = a2;
  this[5] = a3;
  this[6] = a4;
  this[7] = 0;
  return this;
}


