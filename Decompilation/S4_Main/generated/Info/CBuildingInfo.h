#ifndef CBUILDINGINFO_H
#define CBUILDINGINFO_H

#include "defines.h"

class CBuildingInfo : public CInfoExchange {
public:
    // address=[0x14544a0]
     CBuildingInfo(void);

    // Type information members
public:
    BYTE m_cType;
    BYTE m_cRace;
    BYTE m_bInhabitants;
    BYTE m_unknownB;
    BYTE m_bSomeFlagBits;
    BYTE m_bHasWorkingArea;
    BYTE m_iBuildingProgress;
    BYTE m_cTotalCount;
    BYTE m_cTotalBuiltCount;
    BYTE m_iSettlerCount;
    BYTE m_iTools;
    BYTE m_bRemainingSettlers;

};


#endif // CBUILDINGINFO_H
