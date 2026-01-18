#include "COpenListEntry16.h"

// Definitions for class COpenListEntry16

// address=[0x15d6090]
// Decompiled from bool __thiscall COpenListEntry16::operator<(_DWORD *this, _DWORD *a2)
bool  COpenListEntry16::operator<(class COpenListEntry16 const & a2)const {
  
  return *this > *a2;
}


// address=[0x15d65a0]
// Decompiled from int __thiscall COpenListEntry16::G(COpenListEntry16 *this)
int  COpenListEntry16::G(void)const {
  
  return (unsigned __int16)*(_DWORD *)this;
}


// address=[0x15d6640]
// Decompiled from int __thiscall COpenListEntry16::Index(COpenListEntry16 *this)
int  COpenListEntry16::Index(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x15d6740]
// Decompiled from void __thiscall COpenListEntry16::MaxItem(std::_Basic_container_proxy_ptr12 *this)
void  COpenListEntry16::MaxItem(void) {
  
  *(_DWORD *)this = 0;
}


// address=[0x15d6d20]
// Decompiled from int __thiscall COpenListEntry16::Set(COpenListEntry16 *this, int a2, int a3, int a4)
void  COpenListEntry16::Set(int a2, int a3, int a4) {
  
  int result; // eax

  *(_DWORD *)this = a3 | ((a4 + a3) << 16);
  result = a2;
  *((_DWORD *)this + 1) = a2;
  return result;
}


