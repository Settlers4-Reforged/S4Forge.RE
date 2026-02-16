#if FALSE
#include "CConfigVar.h"

// Definitions for class CConfigVar

// address=[0x12fd170]
// Decompiled from double CConfigVar::GetFloatValue()
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
// Decompiled from struct std::string *__stdcall CConfigVar::GetStringValue()
std::string  CConfigVar::GetStringValue(void)const {
  
  struct std::string *v1; // [esp+10h] [ebp+8h]

  std::string::string(v1, (char *)&off_366DCF4);
  return v1;
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
  
  return (unsigned __int8)this->m_cSize;
}


// address=[0x160dbb0]
// Decompiled from int __thiscall CConfigVar::Type(CConfigVar *this)
int  CConfigVar::Type(void)const {
  
  return (unsigned __int8)this->m_cType;
}


// address=[0x2efa370]
// Decompiled from bool __thiscall CConfigVar::Static(CConfigVar *this)
bool  CConfigVar::Static(void)const {
  
  return this->m_bIsStatic;
}


// address=[0x12fca20]
// Decompiled from CConfigVar *__thiscall CConfigVar::~CConfigVar(CConfigVar *this)
 CConfigVar::~CConfigVar(void) {
  
  CConfigVar *result; // eax

  result = this;
  this->__vftable = (CConfigVar_vtbl *)&CConfigVar::_vftable_;
  return result;
}


// address=[0x2ef86a0]
// Decompiled from CConfigVar *__thiscall CConfigVar::CConfigVar(CConfigVar *this, bool _bIsStatic, T_CFGVAR_TYPE _eType, char _iSize)
 CConfigVar::CConfigVar(bool _bIsStatic, enum T_CFGVAR_TYPE _eType, int _iSize) {
  
  this->__vftable = (CConfigVar_vtbl *)&CConfigVar::_vftable_;
  this->m_bIsStatic = _bIsStatic;
  this->m_cType = _eType;
  this->m_cSize = _iSize;
  this->m_cU7 = 0;
  return this;
}


#endif // Already implemented
