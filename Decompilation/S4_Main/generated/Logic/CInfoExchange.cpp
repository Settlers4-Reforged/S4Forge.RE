#include "all_headers.h"

// Definitions for class CInfoExchange

// address=[0x1454320]
// Decompiled from void *__thiscall CInfoExchange::Clear(char *this)
void  CInfoExchange::Clear(void) {
  
  void *result; // eax
  unsigned int v2; // [esp+8h] [ebp-8h]

  v2 = (*(int (__thiscall **)(char *))(*(_DWORD *)this + 4))(this);
  if ( v2 < 8 && BBSupportDbgReport(2, "Logic\\InfoExchange.cpp", 86, "uSize >= 8") == 1 )
    __debugbreak();
  result = this + 4;
  if ( v2 > 4 )
    return memset(this + 4, 0, v2 - 4);
  return result;
}


// address=[0x1415220]
// Decompiled from CInfoExchange *__thiscall CInfoExchange::CInfoExchange(CInfoExchange *this)
 CInfoExchange::CInfoExchange(void) {
  
  *(_DWORD *)this = &CInfoExchange::_vftable_;
  *((_DWORD *)this + 1) = 0;
  return this;
}


