#ifndef CBBOBJECTTRACER_H
#define CBBOBJECTTRACER_H

#include "defines.h"

class CBBObjectTracer {
public:
    // address=[0x2f33a90]
    static void __cdecl Enter(void);

    // address=[0x2f33ad0]
    static void __cdecl InitObject(class CBBObject & a1, char const * a2, bool a3);

    // address=[0x2f33b70]
    static bool __cdecl IsObjectInList(unsigned int a1, class CBBObject * & a2);

    // address=[0x2f33bd0]
    static void __cdecl DumpObjects(void);

    // address=[0x2f33dd0]
    static void __cdecl Leave(void);

    // address=[0x4687170]
    static unsigned int m_uCurrentSerialNumber;

    // address=[0x4687174]
    static int m_iNumberOfObjects;

    // address=[0x4687178]
    static class CBBObject * m_pObjectFirst;

    // address=[0x468717c]
    static struct _RTL_CRITICAL_SECTION m_sCriticalSection;

};


#endif // CBBOBJECTTRACER_H
