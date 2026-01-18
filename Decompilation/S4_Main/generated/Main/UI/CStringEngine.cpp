#include "CStringEngine.h"

// Definitions for class CStringEngine

// address=[0x14ce700]
// Decompiled from void *__cdecl CStringEngine::CreateStringEngine(int a1)
class CStringEngine * __cdecl CStringEngine::CreateStringEngine(int a1) {
  
  CStringEngineEx *C; // [esp+Ch] [ebp-10h]

  C = (CStringEngineEx *)operator new(8u);
  if ( C )
    return CStringEngineEx::CStringEngineEx(C, a1);
  else
    return 0;
}


// address=[0x14cf320]
// Decompiled from _DWORD *__thiscall CStringEngine::CStringEngine(_DWORD *this)
 CStringEngine::CStringEngine(void) {
  
  *this = &CStringEngine::_vftable_;
  return this;
}


// address=[0x14cf340]
// Decompiled from CStringEngine *__thiscall CStringEngine::~CStringEngine(CStringEngine *this)
 CStringEngine::~CStringEngine(void) {
  
  CStringEngine *result; // eax

  result = this;
  *(_DWORD *)this = &CStringEngine::_vftable_;
  return result;
}


