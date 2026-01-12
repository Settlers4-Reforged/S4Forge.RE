#include "CTileIdRef.h"

// Definitions for class CTileIdRef

// address=[0x15d5f80]
// Decompiled from _DWORD *__thiscall CTileIdRef::CTileIdRef(_DWORD *this, int a2, int a3)
 CTileIdRef::CTileIdRef(enum T_TILING_TYPE,int) {
  
  *this = &(&ITiling::m_pTileIds)[a2][a3];
  return this;
}


// address=[0x15d6e70]
// Decompiled from int __thiscall CTileIdRef::TileId(CTileIdRef *this, int a2)
int  CTileIdRef::TileId(int)const {
  
  return *(unsigned __int16 *)(*(_DWORD *)this + 2 * a2);
}


// address=[0x15f4080]
// Decompiled from _DWORD *__thiscall CTileIdRef::operator++(_DWORD *this)
class CTileIdRef &  CTileIdRef::operator++(void) {
  
  *this += 2;
  return this;
}


// address=[0x15f40b0]
// Decompiled from _DWORD *__thiscall CTileIdRef::operator+=(_DWORD *this, int a2)
class CTileIdRef &  CTileIdRef::operator+=(int) {
  
  *this += 2 * a2;
  return this;
}


// address=[0x15f5860]
// Decompiled from CTileIdRef *__thiscall CTileIdRef::SetTileId(CTileIdRef *this, __int16 a2)
void  CTileIdRef::SetTileId(int)const {
  
  CTileIdRef *result; // eax

  result = this;
  **(_WORD **)this = a2;
  return result;
}


// address=[0x15f5880]
// Decompiled from __int16 __thiscall CTileIdRef::SetTileId(CTileIdRef *this, int a2, __int16 a3)
void  CTileIdRef::SetTileId(int,int)const {
  
  __int16 result; // ax

  result = a3;
  *(_WORD *)(*(_DWORD *)this + 2 * a2) = a3;
  return result;
}


