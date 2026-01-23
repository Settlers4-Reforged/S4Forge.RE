#ifndef CBUILDINGINFO_H
#define CBUILDINGINFO_H

#include "defines.h"
#include "../Logic/CInfoExchange.h"

class CBuildingInfo : public CInfoExchange {
public:
    // address=[0x14544a0]
     CBuildingInfo(void);

     
    BYTE m_cType;
    BYTE m_cRace;
    BYTE m_unknownA;
    BYTE m_unknownB;
    BYTE m_bSomeFlagBits;
    BYTE m_unknownD;
    BYTE m_unknownE;
    BYTE m_cTotalCount;
    BYTE m_cTotalBuiltCount;
    BYTE m_iSettlerCount;
    BYTE m_unknown12;
    BYTE m_bRemainingSettlers;
};


#endif // CBUILDINGINFO_H
