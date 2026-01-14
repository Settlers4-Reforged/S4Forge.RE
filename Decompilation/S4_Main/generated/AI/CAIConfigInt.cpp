#include "all_headers.h"

// Definitions for class CAIConfigInt

// address=[0x12fc7b0]
// Decompiled from CAIConfigInt *__thiscall CAIConfigInt::CAIConfigInt(CAIConfigInt *this, const char *a2, int a3)
 CAIConfigInt::CAIConfigInt(char const *,int) {
  
  CStaticConfigVarInt::CStaticConfigVarInt(this, (const char *)off_366E0C8, a2, a3);
  *(_DWORD *)this = &CAIConfigInt::_vftable_;
  return this;
}


// address=[0x12fc9e0]
// Decompiled from void __thiscall CAIConfigInt::~CAIConfigInt(CAIConfigInt *this)
 CAIConfigInt::~CAIConfigInt(void) {
  
  CStaticConfigVarInt::~CStaticConfigVarInt(this);
}


