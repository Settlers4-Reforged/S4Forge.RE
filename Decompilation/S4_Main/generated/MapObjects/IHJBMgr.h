#ifndef IHJBMGR_H
#define IHJBMGR_H

#include "defines.h"

class IHJBMgr {
public:
    // address=[0x14b4790]
    static bool __cdecl LocalIsHJBAllowed(void);

    // address=[0x1574d70]
     IHJBMgr(void);

    // address=[0x1575bd0]
    static int __cdecl GetHJBEntityId(void);

    // address=[0x1575be0]
    static int __cdecl GetHJBPlayerId(void);

    // address=[0x1580100]
    static bool __cdecl LocalIsHJBGfxLoaded(void);

protected:
    // address=[0x1575c30]
    static void __cdecl SetHJBEntityId(int a1);

    // address=[0x1575c40]
    static void __cdecl SetHJBPlayerId(int a1);

    // address=[0x3d8bed0]
    static int m_iLocalHJBAllowed;

    // address=[0x3d8bed4]
    static int m_iLocalHJBGfxLoaded;

    // address=[0x3d8bed8]
    static int m_iHJBEntityId;

    // address=[0x41520d0]
    static int m_iHJBPlayerId;

};


#endif // IHJBMGR_H
