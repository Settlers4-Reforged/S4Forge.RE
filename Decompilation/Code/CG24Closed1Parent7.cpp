#include "CG24Closed1Parent7.h"

// Definitions for class CG24Closed1Parent7

// address=[0x15d61d0]
// Decompiled from int __thiscall CG24Closed1Parent7::Closed(CG24Closed1Parent7 *this)

int  CG24Closed1Parent7::Closed(void)const {
  
  return *(_DWORD *)this & 0x80;
}


// address=[0x15d6580]
// Decompiled from int __thiscall CG24Closed1Parent7::G(CG24Closed1Parent7 *this)

int  CG24Closed1Parent7::G(void)const {
  
  return *(_DWORD *)this >> 8;
}


// address=[0x15d6800]
// Decompiled from int __thiscall CG24Closed1Parent7::Parent(CG24Closed1Parent7 *this)

int  CG24Closed1Parent7::Parent(void)const {
  
  return *(_DWORD *)this & 0x7F;
}


// address=[0x15d6cf0]
// Decompiled from int __thiscall CG24Closed1Parent7::Set(CG24Closed1Parent7 *this, int a2, bool a3, int a4)

void  CG24Closed1Parent7::Set(int,bool,int) {
  
  int result; // eax

  result = a4 | (a3 << 7) | (a2 << 8);
  *(_DWORD *)this = result;
  return result;
}


// address=[0x15d6db0]
// Decompiled from CG24Closed1Parent7 *__thiscall CG24Closed1Parent7::SetClosedFlag(CG24Closed1Parent7 *this)

void  CG24Closed1Parent7::SetClosedFlag(void) {
  
  CG24Closed1Parent7 *result; // eax

  result = this;
  *(_DWORD *)this |= 0x80u;
  return result;
}


