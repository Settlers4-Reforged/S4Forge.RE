#include "all_headers.h"

// Definitions for class COpenListEntry24

// address=[0x15d60d0]
// Decompiled from bool __thiscall COpenListEntry24::operator<(_DWORD *this, _DWORD *a2)
bool  COpenListEntry24::operator<(class COpenListEntry24 const &)const {
  
  return *this > *a2;
}


// address=[0x15d65c0]
// Decompiled from unsigned int __thiscall COpenListEntry24::G(COpenListEntry24 *this)
int  COpenListEntry24::G(void)const {
  
  return ((unsigned int)&dword_F29144[220078] + 3) & *((_DWORD *)this + 1);
}


// address=[0x15d6660]
// Decompiled from int __thiscall COpenListEntry24::Index(COpenListEntry24 *this)
int  COpenListEntry24::Index(void)const {
  
  return HIBYTE(*((_DWORD *)this + 1)) | ((unsigned __int8)*(_DWORD *)this << 8);
}


// address=[0x15d6760]
// Decompiled from void __thiscall COpenListEntry24::MaxItem(std::_Basic_container_proxy_ptr12 *this)
void  COpenListEntry24::MaxItem(void) {
  
  *(_DWORD *)this = 0;
}


// address=[0x15d6d50]
// Decompiled from int __thiscall COpenListEntry24::Set(COpenListEntry24 *this, int a2, int a3, int a4)
void  COpenListEntry24::Set(int,int,int) {
  
  int result; // eax

  *(_DWORD *)this = (a2 >> 8) | ((a4 + a3) << 8);
  result = a3 | (a2 << 24);
  *((_DWORD *)this + 1) = result;
  return result;
}


