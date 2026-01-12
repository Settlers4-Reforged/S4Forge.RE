#include "SPoint.h"

// Definitions for class SPoint

// address=[0x15ddb00]
// Decompiled from _DWORD *__thiscall SPoint::operator=(_DWORD *this, char *a2)
struct SPoint &  SPoint::operator=(struct SPoint8 const &) {
  
  *this = *a2;
  this[1] = a2[1];
  return this;
}


// address=[0x15ddb40]
// Decompiled from BOOL __thiscall SPoint::operator==(_DWORD *this, _DWORD *a2)
bool  SPoint::operator==(struct SPoint const &)const {
  
  return this[1] == a2[1] && *this == *a2;
}


// address=[0x15ddbb0]
// Decompiled from int __thiscall SPoint::operator*(_DWORD *this, _DWORD *a2)
int  SPoint::operator*(struct SPoint const &)const {
  
  return a2[1] * this[1] + *a2 * *this;
}


// address=[0x15ddce0]
// Decompiled from int __thiscall SPoint::X(SPoint *this)
int  SPoint::X(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x15ddd00]
// Decompiled from int __thiscall SPoint::Y(SPoint *this)
int  SPoint::Y(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x15ddd20]
// Decompiled from _Stl_critical_section *__thiscall SPoint::Zero(_Stl_critical_section *this)
struct SPoint &  SPoint::Zero(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  return this;
}


