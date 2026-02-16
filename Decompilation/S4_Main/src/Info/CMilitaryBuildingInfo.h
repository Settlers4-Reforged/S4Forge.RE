#ifndef CMILITARYBUILDINGINFO_H
#define CMILITARYBUILDINGINFO_H

#include "defines.h"
#include "CBuildingInfo.h"
#include "Logic/CInfoExchange.h"

class CMilitaryBuildingInfo : public CBuildingInfo
{
public:
    // address=[0x1454710]
    CMilitaryBuildingInfo(void);

    // address=[0x1454cb0]
    virtual unsigned int Size(void) const;

private:
    struct Stationed
    {
        char m_cUnitType;
        BYTE m_cUnitHealth;
    };

    // Type information members
public:
    Stationed m_aStationedArchers[10];
    Stationed m_aStationedSoldiers[10];
};

#endif // CMILITARYBUILDINGINFO_H
