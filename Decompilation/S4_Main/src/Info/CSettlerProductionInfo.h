#ifndef CSETTLERPRODUCTIONINFO_H
#define CSETTLERPRODUCTIONINFO_H

#include "Logic/CInfoExchange.h"
#include "defines.h"

class CSettlerProductionInfo : public CInfoExchange {
  public:
    // address=[0x1454830]
    CSettlerProductionInfo(void);

    // address=[0x1454d70]
    virtual unsigned int Size(void) const;

    // Type information members
  public:
    struct {
        int m_iType;
        int m_iCount;
        int m_iWished;
        bool m_bEnoughGoods;
        bool m_bAvailable;
        int m_iFreeGoods;
        int field_14;
    } m_vSpecialist[6];
    
    int m_iFreeCarriers;
    bool m_bInEcoSector;
};

#endif // CSETTLERPRODUCTIONINFO_H
