#ifndef CPRODUCTIONDATATAB_H
#define CPRODUCTIONDATATAB_H

class CProductionDataTab {
public:
    // address=[0x2f3bba0]
    int  GetMaxDistance(enum BUILDING_TYPES,int);

    // address=[0x2f4c730]
    bool  BuildingMustBeControl(enum BUILDING_TYPES,int);

    // address=[0x2f4c930]
    enum PILE_TYPES  GetInputTypePile(enum BUILDING_TYPES,int,int);

    // address=[0x2f4c980]
    int  GetMaxBuildingInGroup(enum BUILDING_TYPES,int);

    // address=[0x2f4c9b0]
    enum PILE_TYPES  GetOutputTypePile(enum BUILDING_TYPES,int);

    // address=[0x2f53a90]
    enum SETTLER_TYPES  GetNeededSettler(enum BUILDING_TYPES);

    // address=[0x2f53ac0]
    enum PILE_TYPES  GetTool(enum BUILDING_TYPES);

    // address=[0x2f54120]
     CProductionDataTab(void);

    // address=[0x2f54910]
     ~CProductionDataTab(void);

    // address=[0x2f54920]
    enum BUILDING_TYPES  GoodTypeProducedBy(enum PILE_TYPES,int,int);

    // address=[0x2f549a0]
    enum BUILDING_TYPES  GetBuildingForResource(int,int);

    // address=[0x2f54a00]
    int  GetResourceForBuilding(enum BUILDING_TYPES,int);

    // address=[0x2f54a20]
    void  SetProdTabValue(enum BUILDING_TYPES,int,int);

    // address=[0x2f5a2c0]
    int  GetMaxWorkLoad(enum BUILDING_TYPES,int);

    // address=[0x2f5a2f0]
    int  GetMinWorkLoad(enum BUILDING_TYPES,int);

    // address=[0x2f5a320]
    int  GetNeededFixTicks(enum BUILDING_TYPES,int);

    // address=[0x2f5a350]
    int  GetNeededVarTicks(enum BUILDING_TYPES,int);

    // address=[0x46878f8]
    static struct SProductionDataEntry * CProductionDataTab::m_aProductionDataEntry;

protected:
    // address=[0x2f3bb70]
    struct SProductionDataEntry const *  CProductionDataTab::GetBuildData(enum BUILDING_TYPES,int);

    // address=[0x2f54ad0]
    void  PDT(int,enum BUILDING_TYPES,int,int,int,int,enum PILE_TYPES,enum PILE_TYPES,enum PILE_TYPES,enum PILE_TYPES,int,enum SETTLER_TYPES,int,int,int);

    // address=[0x2f55000]
    int  GetProdDataTabIndex(enum BUILDING_TYPES,int);

    // address=[0x4687270]
    static int m_iNumberOfEntries;

    // address=[0x4687278]
    static int (* m_aBuildingTypeToTabIndexMap)[83];

};


#endif // CPRODUCTIONDATATAB_H
