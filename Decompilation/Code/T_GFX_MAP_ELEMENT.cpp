#include "T_GFX_MAP_ELEMENT.h"

// Definitions for class T_GFX_MAP_ELEMENT

// address=[0x151aa30]
// Decompiled from int __thiscall T_GFX_MAP_ELEMENT::GetGradient(T_GFX_MAP_ELEMENT *this)
int  T_GFX_MAP_ELEMENT::GetGradient(void) {
  
  return *((_BYTE *)this + 2) & 0xF;
}


// address=[0x15db1b0]
// Decompiled from int __thiscall T_GFX_MAP_ELEMENT::GetNewFogging(T_GFX_MAP_ELEMENT *this)
int  T_GFX_MAP_ELEMENT::GetNewFogging(void) {
  
  return (*((_BYTE *)this + 3) & 0x38) >> 3;
}


// address=[0x15db1d0]
// Decompiled from int __thiscall T_GFX_MAP_ELEMENT::GetOldFogging(T_GFX_MAP_ELEMENT *this)
int  T_GFX_MAP_ELEMENT::GetOldFogging(void) {
  
  return *((_BYTE *)this + 3) & 7;
}


// address=[0x2f90e30]
// Decompiled from T_GFX_MAP_ELEMENT *__thiscall T_GFX_MAP_ELEMENT::SetNewFogging(T_GFX_MAP_ELEMENT *this, char a2)
void  T_GFX_MAP_ELEMENT::SetNewFogging(int) {
  
  T_GFX_MAP_ELEMENT *result; // eax

  result = this;
  *((_BYTE *)this + 3) = (8 * a2) | *((_BYTE *)this + 3) & 0xC7;
  return result;
}


