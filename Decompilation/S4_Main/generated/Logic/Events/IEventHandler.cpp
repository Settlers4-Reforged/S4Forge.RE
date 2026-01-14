#include "all_headers.h"

// Definitions for class IEventHandler

// address=[0x1460060]
// Decompiled from IEventHandler *__thiscall IEventHandler::IEventHandler(IEventHandler *this, int a2)
 IEventHandler::IEventHandler(int) {
  
  *(_DWORD *)this = &IEventHandler::_vftable_;
  *((_DWORD *)this + 1) = operator new[](4 * a2);
  return this;
}


// address=[0x1460140]
// Decompiled from int __thiscall IEventHandler::~IEventHandler(void **this)
 IEventHandler::~IEventHandler(void) {
  
  *this = &IEventHandler::_vftable_;
  return operator delete[](this[1]);
}


