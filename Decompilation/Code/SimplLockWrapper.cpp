#include "SimplLockWrapper.h"

// Definitions for class SimplLockWrapper

// address=[0x2dbc220]
// Decompiled from SimplLockWrapper *__thiscall SimplLockWrapper::SimplLockWrapper(SimplLockWrapper *this, int a2)
 SimplLockWrapper::SimplLockWrapper(char const *) {
  
  InitializeCriticalSection((LPCRITICAL_SECTION)this);
  return this;
}


// address=[0x2dc1a70]
// Decompiled from void __thiscall SimplLockWrapper::~SimplLockWrapper(struct _RTL_CRITICAL_SECTION *this)
 SimplLockWrapper::~SimplLockWrapper(void) {
  
  DeleteCriticalSection(this);
}


// address=[0x2dd13a0]
// Decompiled from SimplLockWrapper *__thiscall SimplLockWrapper::GetLock(SimplLockWrapper *this)
struct _RTL_CRITICAL_SECTION &  SimplLockWrapper::GetLock(void) {
  
  return this;
}


