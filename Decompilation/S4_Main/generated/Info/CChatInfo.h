#ifndef CCHATINFO_H
#define CCHATINFO_H

#include "defines.h"

class CChatInfo {
public:
    // address=[0x14aa640]
     CChatInfo(void);

    // address=[0x14aa940]
     ~CChatInfo(void);

    // Type information members
public:
    int m_sChatInfo;
    _DWORD field_188;
    _DWORD m_iActualPlayerCount;
    _DWORD m_uLocalPlayerId;
    CStateGame::SPlayerInfo[8] m_asPlayerInfo;

};


#endif // CCHATINFO_H
