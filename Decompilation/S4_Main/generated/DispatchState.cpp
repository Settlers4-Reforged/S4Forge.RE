#include "all_headers.h"

// Definitions for class DispatchState

// address=[0x306f6a0]
// Decompiled from Concurrency::DispatchState *__thiscall Concurrency::DispatchState::DispatchState(Concurrency::DispatchState *this)
 Concurrency::DispatchState::DispatchState(void) {
  
  *(_DWORD *)this = 8;
  *((_DWORD *)this + 1) &= ~1u;
  *((_DWORD *)this + 1) &= 1u;
  return this;
}


