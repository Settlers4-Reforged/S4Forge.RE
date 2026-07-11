#ifndef CSOLDIERINFO_H
#define CSOLDIERINFO_H

#include "Logic/CInfoExchange.h"
#include "defines.h"

class CSoldierInfo : public CInfoExchange {
  public:
    // address=[0x14548c0]
    CSoldierInfo(void);

    // address=[0x1454dd0]
    virtual unsigned int Size(void) const;

    // Type information members
  public:
    struct {
        int m_iTotalHitpoints;
        int m_iTotalDamage;
        int m_iCount;
    } m_vSoldiers[11];
    int m_iOffenceStrength;
    int m_iDefenceStrength;
    int m_iMana;
};

#endif // CSOLDIERINFO_H
