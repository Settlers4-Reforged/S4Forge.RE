#include "CInfoExchangeInt.h"

// Definitions for class CInfoExchangeInt

// address=[0x14546b0]
// Decompiled from CInfoExchangeInt *__thiscall CInfoExchangeInt::CInfoExchangeInt(CInfoExchangeInt *this)

 CInfoExchangeInt::CInfoExchangeInt(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CInfoExchangeInt::_vftable_;
  return this;
}


// address=[0x1454c70]
// Decompiled from int __thiscall CInfoExchangeInt::Size(CInfoExchangeInt *this)

unsigned int  CInfoExchangeInt::Size(void)const {
  
  return 12;
}


