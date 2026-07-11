#ifndef CSOLDIERINFO_H
#define CSOLDIERINFO_H

#include "defines.h"

class CSoldierInfo : public CInfoExchange {
public:
    // address=[0x14548c0]
     CSoldierInfo(void);

    // address=[0x1454dd0]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CSoldierInfo::SSoldier[11] m_vSoldiers;
    int m_iOffenceStrength;
    int m_iDefenceStrength;
    int m_iMana;

};


#endif // CSOLDIERINFO_H
