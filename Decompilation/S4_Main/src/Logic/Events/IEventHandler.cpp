#include "IEventHandler.h"

// Definitions for class IEventHandler

// address=[0x1460060]
// Decompiled from IEventHandler *__thiscall IEventHandler::IEventHandler(IEventHandler *this, int a2)
IEventHandler::IEventHandler(int a2)
{
  this->m_pHandlers = new EventHandlerFunc[a2];
}

// address=[0x1460140]
// Decompiled from int __thiscall IEventHandler::~IEventHandler(void **this)
IEventHandler::~IEventHandler(void)
{
  delete[] this->m_pHandlers;
}
