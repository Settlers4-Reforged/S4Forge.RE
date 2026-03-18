#if FALSE
#include "T_GFX_MAP_ELEMENT.h"

// Definitions for class T_GFX_MAP_ELEMENT

// address=[0x151aa30]
// Decompiled from int __thiscall T_GFX_MAP_ELEMENT::GetGradient(T_GFX_MAP_ELEMENT *this)
int  T_GFX_MAP_ELEMENT::GetGradient(void) {
  
  return this->m_uGradient & 0xF;
}


// address=[0x15db1b0]
// Decompiled from int __thiscall T_GFX_MAP_ELEMENT::GetNewFogging(T_GFX_MAP_ELEMENT *this)
int  T_GFX_MAP_ELEMENT::GetNewFogging(void) {
  
  return (this->m_uGfxBits & 0x38) >> 3;
}


// address=[0x15db1d0]
// Decompiled from int __thiscall T_GFX_MAP_ELEMENT::GetOldFogging(T_GFX_MAP_ELEMENT *this)
int  T_GFX_MAP_ELEMENT::GetOldFogging(void) {
  
  return this->m_uGfxBits & 7;
}


// address=[0x2f90e30]
// Decompiled from void __thiscall T_GFX_MAP_ELEMENT::SetNewFogging(T_GFX_MAP_ELEMENT *this, int a2)
void  T_GFX_MAP_ELEMENT::SetNewFogging(int a2) {
  
  this->m_uGfxBits = (8 * a2) | this->m_uGfxBits & 0xC7;
}


#endif // Already implemented
