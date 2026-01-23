#ifndef CADDSOLDIERSIDEBARINFO_H
#define CADDSOLDIERSIDEBARINFO_H

#include "defines.h"

#include "../Logic/CInfoExchange.h"


class CAddSoldierSideBarInfo : public CInfoExchange {
public:
    // address=[0x14543e0]
     CAddSoldierSideBarInfo(void);

    // address=[0x1454ab0]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    unsigned char m_cLvl1SoldierCount[3];
    unsigned char m_cLvl2SoldierCount[3];
    unsigned char m_cLvl3SoldierCount[3];
    unsigned char m_cSpecialSoldierCount;
    unsigned int m_uMinCarrier;
};


#endif // CADDSOLDIERSIDEBARINFO_H
