#include "all_headers.h"

// Definitions for class CTransportpriorityInfo

// address=[0x1454980]
// Decompiled from CTransportpriorityInfo *__thiscall CTransportpriorityInfo::CTransportpriorityInfo(CTransportpriorityInfo *this)
 CTransportpriorityInfo::CTransportpriorityInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CTransportpriorityInfo::_vftable_;
  *((_BYTE *)this + 8) = 0;
  *((_DWORD *)this + 3) = 0;
  return this;
}


// address=[0x1454e50]
// Decompiled from int __thiscall CTransportpriorityInfo::Size(CTransportpriorityInfo *this)
unsigned int  CTransportpriorityInfo::Size(void)const {
  
  return 136;
}


