#ifndef CSETTLERSTATISTICINFO_H
#define CSETTLERSTATISTICINFO_H

#include "Logic/CInfoExchange.h"
#include "defines.h"

class CSettlerStatisticInfo : public CInfoExchange {
  public:
    // address=[0x1454860]
    CSettlerStatisticInfo(void);

    // address=[0x1454d90]
    virtual unsigned int Size(void) const;

    // Type information members
  public:
    bool m_bInEcoSector;
    int m_iCurrentTotalBeds;
    int m_iCurrentFreeBeds;
    int m_iBedDifference;
    int m_iWorkingSettlers;
    int m_iStrikingSettlers;
    int m_iWorkingSettlersInSector;
    int m_iStrikingSettlersInSector;

    struct {
        int m_iSettlerType;
        int m_iCount;
    } m_vSettlerCounts[36];
};

#endif // CSETTLERSTATISTICINFO_H
