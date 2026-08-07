#if FALSE
#include "CInfoExchange.h"

// Definitions for class CInfoExchange

// address=[0x1454320]
// Decompiled from void __thiscall CInfoExchange::Clear(CInfoExchange *this)
void  CInfoExchange::Clear(void) {
  
  unsigned int uSize; // [esp+8h] [ebp-8h]

  uSize = this->Size(this);
  if ( uSize < 8 && BBSupportDbgReport(2, "Logic\\InfoExchange.cpp", 86, "uSize >= 8") == 1 )
  {
    __debugbreak();
  }
  if ( uSize > 4 )
  {
    memset(this->m_iUnknown, 0, uSize - 4);
  }
}


// address=[0x1415220]
// Decompiled from CInfoExchange *__thiscall CInfoExchange::CInfoExchange(CInfoExchange *this)
 CInfoExchange::CInfoExchange(void) {
  
  this->__vftable = (CInfoExchange_vtbl *)&CInfoExchange::_vftable_;
  this->m_iUnknown = 0;
  return this;
}


#endif // Already implemented
