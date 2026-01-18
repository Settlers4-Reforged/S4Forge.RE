#ifndef CPRODUCTIONTAB_H
#define CPRODUCTIONTAB_H

#include "defines.h"

class CProductionTab {
public:
    // address=[0x2f3bbd0]
    enum BUILDING_TYPES  GetProdBuildingByProdIndex(int a1, int a2, int a3);

    // address=[0x2f3bc00]
    int  GetProdIdForGoodType(enum PILE_TYPES a1, int a2);

    // address=[0x2f53d00]
     CProductionTab(void);

    // address=[0x2f53f80]
     ~CProductionTab(void);

    // address=[0x2f53f90]
    int  GetAlternateProdForProdId(enum PILE_TYPES a2, int a3);

protected:
    // address=[0x4687274]
    static int m_iNumberOfEntries;

    // address=[0x4688c70]
    static int (* m_aRaceAndGoodToProdIdMap)[43];

    // address=[0x4688fd0]
    static struct SProductionEntry * CProductionTab::m_aProductionEntry;

private:
    // address=[0x2f53ff0]
    void  PT(char const * a1, int a2, enum PILE_TYPES a3, enum BUILDING_TYPES a4, enum BUILDING_TYPES a5, enum BUILDING_TYPES a6, enum BUILDING_TYPES a7, enum BUILDING_TYPES a8);

};


#endif // CPRODUCTIONTAB_H
