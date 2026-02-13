#include "CStringEngine.h"

#include "Main/UI/CStringEngineEx.h"

// Definitions for class CStringEngine

// address=[0x14ce700]
// Decompiled from void *__cdecl CStringEngine::CreateStringEngine(int a1)
class CStringEngine * __cdecl CStringEngine::CreateStringEngine(int a1) {
  return new CStringEngineEx(a1);
}


// address=[0x14cf320]
// Decompiled from _DWORD *__thiscall CStringEngine::CStringEngine(_DWORD *this)
 CStringEngine::CStringEngine(void) = default;


// address=[0x14cf340]
// Decompiled from CStringEngine *__thiscall CStringEngine::~CStringEngine(CStringEngine *this)
 CStringEngine::~CStringEngine(void) = default;


