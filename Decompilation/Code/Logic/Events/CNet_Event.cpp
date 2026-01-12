#include "CNet_Event.h"

// Definitions for class CNet_Event

// address=[0x15c38b0]
// Decompiled from _DWORD *__thiscall CNet_Event::CNet_Event(_DWORD *this, struct boost::exception_detail::clone_base *a2)
 CNet_Event::CNet_Event(class CNet_Event const &) {
  
  CEvn_Logic::CEvn_Logic(a2);
  *this = CNet_Event::_vftable_;
  return this;
}


// address=[0x15c38e0]
// Decompiled from CNet_Event *__thiscall CNet_Event::CNet_Event(  CNet_Event *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  char a5,  unsigned int a6,  unsigned __int16 a7,  unsigned int a8)
 CNet_Event::CNet_Event(unsigned int,unsigned int,unsigned int,unsigned char,unsigned int,unsigned short,unsigned int) {
  
  CEvn_Logic::CEvn_Logic(this, a2, a3, a4, a5, a6, a7);
  *(_DWORD *)this = CNet_Event::_vftable_;
  *((_DWORD *)this + 4) = a8;
  return this;
}


// address=[0x15c3dc0]
// Decompiled from void __thiscall CNet_Event::~CNet_Event(CNet_Event *this)
 CNet_Event::~CNet_Event(void) {
  
  *(_DWORD *)this = CNet_Event::_vftable_;
  CEvn_Logic::~CEvn_Logic(this);
}


// address=[0x15cad30]
// Decompiled from bool __thiscall CNet_Event::operator<(unsigned __int8 *this, int a2)
bool  CNet_Event::operator<(class CNet_Event const &) {
  
  return this[20] < (int)*(unsigned __int8 *)(a2 + 20);
}


