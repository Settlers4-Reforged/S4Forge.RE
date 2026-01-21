#ifndef IEVENTHANDLER_H
#define IEVENTHANDLER_H

#include "defines.h"

typedef bool(__thiscall *EventHandlerFunc)(class IEventHandler *processor, struct CEvn_Logic *event);

class IEventHandler
{
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
