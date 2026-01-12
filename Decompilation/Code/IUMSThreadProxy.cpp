#include "IUMSThreadProxy.h"

// Definitions for class IUMSThreadProxy

// address=[0x3042800]
// Decompiled from Concurrency::IUMSThreadProxy *__thiscall Concurrency::IUMSThreadProxy::IUMSThreadProxy(  Concurrency::IUMSThreadProxy *this)
 Concurrency::IUMSThreadProxy::IUMSThreadProxy(void) {
  
  Concurrency::IThreadProxy::IThreadProxy(this);
  *(_DWORD *)this = Concurrency::IUMSThreadProxy::_vftable_;
  return this;
}


