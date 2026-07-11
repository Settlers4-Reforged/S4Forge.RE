#ifndef CSETTLERPRODUCTIONINFO_H
#define CSETTLERPRODUCTIONINFO_H

#include "defines.h"

class CSettlerProductionInfo : public CInfoExchange {
public:
    // address=[0x1454830]
     CSettlerProductionInfo(void);

    // address=[0x1454d70]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CSettlerProductionInfo::SSpecialist[6] m_vSpecialist;
    int m_iFreeCarriers;
    bool m_bInEcoSector;

};


#endif // CSETTLERPRODUCTIONINFO_H
