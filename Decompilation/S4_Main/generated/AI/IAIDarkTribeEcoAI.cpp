#include "IAIDarkTribeEcoAI.h"

// Definitions for class IAIDarkTribeEcoAI

// address=[0x132fa50]
// Decompiled from int IAIDarkTribeEcoAI::CreateEcoAI()
static class IAIDarkTribeEcoAI * __cdecl IAIDarkTribeEcoAI::CreateEcoAI(struct SAIDarkTribeEcoAIParams const &) {
  
  std::bad_function_call *v2; // [esp+Ch] [ebp-10h]

  v2 = (std::bad_function_call *)operator new(0x4084u);
  if ( v2 )
    return CAIDarkTribe::CAIDarkTribe(v2);
  else
    return 0;
}


// address=[0x1334ef0]
// Decompiled from IAIDarkTribeEcoAI *__thiscall IAIDarkTribeEcoAI::IAIDarkTribeEcoAI(IAIDarkTribeEcoAI *this)
 IAIDarkTribeEcoAI::IAIDarkTribeEcoAI(void) {
  
  IAIUnknown::IAIUnknown(this);
  *(_DWORD *)this = IAIDarkTribeEcoAI::_vftable_;
  return this;
}


