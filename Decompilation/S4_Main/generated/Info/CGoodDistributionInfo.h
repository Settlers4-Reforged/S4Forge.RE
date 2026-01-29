#ifndef CGOODDISTRIBUTIONINFO_H
#define CGOODDISTRIBUTIONINFO_H

#include "defines.h"

class CGoodDistributionInfo : public CInfoExchange {
public:
    // address=[0x14151e0]
     CGoodDistributionInfo(void);

    // address=[0x1417170]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    int m_uSupplyBuildings;
    DWORD m_uPlayerRace;
    CGoodDistributionInfo::Good[5] m_aSupplyPriorities;
    BYTE m_bU4;
    DWORD m_uU5;
    DWORD m_uEcoSectorId;

};


#endif // CGOODDISTRIBUTIONINFO_H
