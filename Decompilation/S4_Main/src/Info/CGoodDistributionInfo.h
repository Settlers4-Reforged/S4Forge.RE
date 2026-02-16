#ifndef CGOODDISTRIBUTIONINFO_H
#define CGOODDISTRIBUTIONINFO_H

#include "defines.h"
#include "Logic/CInfoExchange.h"

class CGoodDistributionInfo : public CInfoExchange
{
public:
    // address=[0x14151e0]
    CGoodDistributionInfo(void);

    // address=[0x1417170]
    virtual unsigned int Size(void) const;

private:
    struct Good
    {
        DWORD m_uBuildingId;
        DWORD m_uPriority;
    };

    // Type information members
public:
    int m_uSupplyBuildings;
    DWORD m_uPlayerRace;
    Good m_aSupplyPriorities[5];
    BYTE m_bU4;
    DWORD m_uU5;
    DWORD m_uEcoSectorId;
};

#endif // CGOODDISTRIBUTIONINFO_H
