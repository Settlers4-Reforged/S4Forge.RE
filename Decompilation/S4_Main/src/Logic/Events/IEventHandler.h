#ifndef IEVENTHANDLER_H
#define IEVENTHANDLER_H

#include <functional>

#include "IEventHandler.h"
#include "defines.h"

class IEventHandler;

typedef bool (IEventHandler::*EventHandlerFunc)(void *event);

class IEventHandler {
  public:
    // address=[0x1460060]
    IEventHandler(int a2);

    // address=[0x1460140]
    virtual ~IEventHandler(void);

    // Type information members
  public:
    EventHandlerFunc *m_pHandlers;
};

#endif // IEVENTHANDLER_H
