#include "CInfoExchangeEx.h"

// Definitions for class CInfoExchangeEx

// address=[0x1454680]
// Decompiled from CInfoExchangeEx *__thiscall CInfoExchangeEx::CInfoExchangeEx(CInfoExchangeEx *this)

 CInfoExchangeEx::CInfoExchangeEx(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CInfoExchangeEx::_vftable_;
  return this;
}


// address=[0x1454c50]
// Decompiled from int __thiscall CInfoExchangeEx::Size(CInfoExchangeEx *this)

unsigned int  CInfoExchangeEx::Size(void)const {
  
  return 8;
}


