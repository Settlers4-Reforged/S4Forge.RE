#include "SimplScopedLock.h"

// Definitions for class SimplScopedLock

// address=[0x2dbc270]
// Decompiled from SimplScopedLock *__thiscall SimplScopedLock::SimplScopedLock(SimplScopedLock *this, struct _RTL_CRITICAL_SECTION *a2)

 SimplScopedLock::SimplScopedLock(struct _RTL_CRITICAL_SECTION &) {
  
  *(_DWORD *)this = a2;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)this);
  return this;
}


// address=[0x2dc1ab0]
// Decompiled from void __thiscall SimplScopedLock::~SimplScopedLock(LPCRITICAL_SECTION *this)

 SimplScopedLock::~SimplScopedLock(void) {
  
  LeaveCriticalSection(*this);
}


