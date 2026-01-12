#include "IUMSScheduler.h"

// Definitions for class IUMSScheduler

// address=[0x3069260]
// Decompiled from Concurrency::IUMSScheduler *__thiscall Concurrency::IUMSScheduler::IUMSScheduler(Concurrency::IUMSScheduler *this)
 Concurrency::IUMSScheduler::IUMSScheduler(void) {
  
  Concurrency::IScheduler::IScheduler(this);
  *(_DWORD *)this = Concurrency::IUMSScheduler::_vftable_;
  return this;
}


