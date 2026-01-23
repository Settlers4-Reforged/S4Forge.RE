#if FALSE
#include "IEventHandler.h"

// Definitions for class IEventHandler

// address=[0x1460060]
// Decompiled from IEventHandler *__thiscall IEventHandler::IEventHandler(IEventHandler *this, int a2)
 IEventHandler::IEventHandler(int a2) {
  
  this->__vftable = (IEventHandler_vtbl *)&IEventHandler::_vftable_;
  this->m_pHandlers = (DWORD *)operator new[](4 * a2);
  return this;
}


// address=[0x1460140]
// Decompiled from int __thiscall IEventHandler::~IEventHandler(void **this)
 IEventHandler::~IEventHandler(void) {
  
  *this = &IEventHandler::_vftable_;
  return operator delete[](this[1]);
}


#endif // Already implemented
