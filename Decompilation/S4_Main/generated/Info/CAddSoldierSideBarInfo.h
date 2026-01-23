#ifndef CADDSOLDIERSIDEBARINFO_H
#define CADDSOLDIERSIDEBARINFO_H

#include "defines.h"

class CAddSoldierSideBarInfo : public CInfoExchange {
public:
    // address=[0x14543e0]
     CAddSoldierSideBarInfo(void);

    // address=[0x1454ab0]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    char[3] m_cLvl1SoldierCount;
    char[3] m_cLvl2SoldierCount;
    BYTE[3] m_cLvl3SoldierCount;
    BYTE m_cSpecialSoldierCount;
    DWORD m_uMinCarrier;

};


#endif // CADDSOLDIERSIDEBARINFO_H
