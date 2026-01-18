#ifndef CMINIMAPHANDLER_H
#define CMINIMAPHANDLER_H

#include "defines.h"

class CMinimapHandler {
public:
    // address=[0x15b1490]
    static void __cdecl FilterKeyPressed(int a1);

    // address=[0x15b1510]
    static void __cdecl Init(void);

    // address=[0x15b1730]
    static void __cdecl UpdateAlliances(void);

    // address=[0x16a6ef0]
    static void __cdecl GetEcoSectorColor(int a1, struct SGfxColor & a2);

    // address=[0x16a6f20]
    static bool __cdecl GetObjectColor(int a1, struct SGfxColor & a2, int a3, int a4);

    // address=[0x16a71c0]
    static bool __cdecl IsEcoSectorEnabled(void);

private:
    // address=[0x3d8c080]
    static int * m_iObjectType;

    // address=[0x415a610]
    static struct SGfxColor * m_sOwnerColorAlly;

    // address=[0x415a670]
    static struct SGfxColor * m_sOwnerColor;

    // address=[0x415a6d0]
    static int * m_iObjectGroups;

    // address=[0x415a8e0]
    static int * m_iGroupEnabled;

    // address=[0x415a8f8]
    static int * m_iObjectBitMask;

    // address=[0x415ab08]
    static struct SGfxColor * m_sObjectColor;

};


#endif // CMINIMAPHANDLER_H
