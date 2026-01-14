#include "all_headers.h"

// Definitions for class CBBSStackTrace

// address=[0x2f30fa0]
// Decompiled from BBSupportLib::CBBSStackTrace *__thiscall BBSupportLib::CBBSStackTrace::CBBSStackTrace(  BBSupportLib::CBBSStackTrace *this,  void *a2,  void *a3,  const struct _CONTEXT *a4)
 BBSupportLib::CBBSStackTrace::CBBSStackTrace(void *,void *,struct _CONTEXT const &) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  qmemcpy((char *)this + 8, a4, 0x2CCu);
  sub_2F31910((char *)this + 724, (int)this + 8);
  return this;
}


// address=[0x2f30ff0]
// Decompiled from char *__thiscall BBSupportLib::CBBSStackTrace::GetNextTraceStr(BBSupportLib::CBBSStackTrace *this)
char const *  BBSupportLib::CBBSStackTrace::GetNextTraceStr(void) {
  
  if ( ATL::CComCriticalSection::Init(this) <= 0 )
    return 0;
  else
    return (char *)this + 888;
}


