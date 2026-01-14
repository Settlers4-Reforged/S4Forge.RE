#ifndef CPRODUCTIONTAB_H
#define CPRODUCTIONTAB_H

class CProductionTab {
public:
    // address=[0x2f3bbd0]
    enum BUILDING_TYPES  GetProdBuildingByProdIndex(int,int,int);

    // address=[0x2f3bc00]
    int  GetProdIdForGoodType(enum PILE_TYPES,int);

    // address=[0x2f53d00]
     CProductionTab(void);

    // address=[0x2f53f80]
     ~CProductionTab(void);

    // address=[0x2f53f90]
    int  GetAlternateProdForProdId(enum PILE_TYPES,int);

protected:
    // address=[0x4687274]
    static int m_iNumberOfEntries;

    // address=[0x4688c70]
    static int (* m_aRaceAndGoodToProdIdMap)[43];

    // address=[0x4688fd0]
    static struct SProductionEntry * CProductionTab::m_aProductionEntry;

private:
    // address=[0x2f53ff0]
    void  PT(char const *,int,enum PILE_TYPES,enum BUILDING_TYPES,enum BUILDING_TYPES,enum BUILDING_TYPES,enum BUILDING_TYPES,enum BUILDING_TYPES);

};


#endif // CPRODUCTIONTAB_H
