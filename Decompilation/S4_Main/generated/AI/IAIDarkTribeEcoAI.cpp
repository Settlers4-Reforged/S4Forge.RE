#include "IAIDarkTribeEcoAI.h"

// Definitions for class IAIDarkTribeEcoAI

// address=[0x132fa50]
// Decompiled from struct IAIDarkTribeEcoAI *__cdecl IAIDarkTribeEcoAI::CreateEcoAI(const struct SAIDarkTribeEcoAIParams *a1)
class IAIDarkTribeEcoAI * __cdecl IAIDarkTribeEcoAI::CreateEcoAI(struct SAIDarkTribeEcoAIParams const & a1) {
  
  std::bad_function_call *v3; // [esp+Ch] [ebp-10h]

  v3 = (std::bad_function_call *)operator new(0x4084u);
  if ( v3 )
    return CAIDarkTribe::CAIDarkTribe(v3, *(_DWORD *)a1);
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


