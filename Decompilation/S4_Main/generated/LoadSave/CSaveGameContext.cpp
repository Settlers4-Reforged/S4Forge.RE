#include "CSaveGameContext.h"

// Definitions for class CSaveGameContext

// address=[0x14b6130]
// Decompiled from CSaveGameContext *__thiscall CSaveGameContext::CSaveGameContext(CSaveGameContext *this)
 CSaveGameContext::CSaveGameContext(void) {
  
  std::wstring::wstring((char *)this + 12, (wchar_t *)&off_3743B14);
  *((_BYTE *)this + 40) = 0;
  return this;
}


// address=[0x14b61a0]
// Decompiled from void __thiscall CSaveGameContext::~CSaveGameContext(CSaveGameContext *this)
 CSaveGameContext::~CSaveGameContext(void) {
  
  std::wstring::~wstring((char *)this + 12);
}


