#if FALSE
#include "CNet_Event.h"

// Definitions for class CNet_Event

// address=[0x15c38b0]
// Decompiled from CNet_Event *__thiscall CNet_Event::CNet_Event(CNet_Event *this, CNet_Event *a2)
 CNet_Event::CNet_Event(class CNet_Event const & a2) {
  
  CEvn_Logic::CEvn_Logic(this, a2);
  this->__vftable = (CEvn_Event_vtbl *)CNet_Event::_vftable_;
  return this;
}


// address=[0x15c38e0]
// Decompiled from CNet_Event *__thiscall CNet_Event::CNet_Event(  CNet_Event *this,  uint a2,  uint a3,  uint a4,  uchar a5,  uint a6,  ushort a7,  uint a8)
 CNet_Event::CNet_Event(unsigned int a2, unsigned int a3, unsigned int a4, unsigned char a5, unsigned int a6, unsigned short a7, unsigned int a8) {
  
  CEvn_Logic::CEvn_Logic(this, a2, a3, a4, a5, a6, a7);
  this->__vftable = (CEvn_Event_vtbl *)CNet_Event::_vftable_;
  this->m_iTick = a8;
  return this;
}


// address=[0x15c3dc0]
// Decompiled from void __thiscall CNet_Event::~CNet_Event(CNet_Event *this)
 CNet_Event::~CNet_Event(void) {
  
  this->__vftable = (CEvn_Event_vtbl *)CNet_Event::_vftable_;
  CEvn_Logic::~CEvn_Logic(this);
}


// address=[0x15cad30]
// Decompiled from bool __thiscall CNet_Event::operator<(CNet_Event *this, CNet_Event *a2)
bool  CNet_Event::operator<(class CNet_Event const & a2) {
  
  return this->m_iMsgNr < (int)a2->m_iMsgNr;
}


#endif // Already implemented
