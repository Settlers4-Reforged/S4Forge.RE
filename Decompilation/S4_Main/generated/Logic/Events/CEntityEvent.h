#ifndef CENTITYEVENT_H
#define CENTITYEVENT_H

#include "defines.h"

class CEntityEvent : public CPersistence {
public:
    // address=[0x130e350]
     CEntityEvent(unsigned char a2, int a3, int a4, int a5, int a6);

    // address=[0x130e430]
     ~CEntityEvent(void);

    // address=[0x130e9d0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1400720]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14e44e0]
     CEntityEvent(class CEntityEvent const & a2);

    // address=[0x14e46f0]
    class CEntityEvent &  operator=(class CEntityEvent const & a2);

    // address=[0x14e4b20]
    static class CEntityEvent * __cdecl Load(std::istream & a1);

    // address=[0x154c110]
     CEntityEvent(std::istream & a2);

    // address=[0x154c1e0]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8bb20]
    static unsigned long m_iClassID;

};


#endif // CENTITYEVENT_H
