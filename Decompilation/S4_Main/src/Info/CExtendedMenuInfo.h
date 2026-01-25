#ifndef CEXTENDEDMENUINFO_H
#define CEXTENDEDMENUINFO_H

#include "defines.h"
#include "CInfoExchange.h"

class CExtendedMenuInfo : public CInfoExchange {
public:
    // address=[0x1454560]
     CExtendedMenuInfo(void);

    // address=[0x1454b90]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    DWORD m_uCarriers;
    DWORD m_uNrTotalBeds;
    DWORD m_uGoodsBoards;
    DWORD m_uGoodsStone;
    DWORD m_uGoodsGoldbars;
    DWORD m_uGoodsWeapons;
    DWORD m_uGoodsFood;
    DWORD m_uSoldierCount;
    DWORD m_uOffenseStrength;
    DWORD m_uDefenceStrength;
    DWORD m_uMana;

};


#endif // CEXTENDEDMENUINFO_H
