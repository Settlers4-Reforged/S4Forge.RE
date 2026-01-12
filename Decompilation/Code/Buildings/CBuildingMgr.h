#ifndef CBUILDINGMGR_H
#define CBUILDINGMGR_H

class CBuildingMgr {
public:
    // address=[0x12fcb90]
    class CBuilding &  operator[](int);

    // address=[0x130e930]
    class CBuilding &  Building(int);

    // address=[0x130eba0]
    class CBuilding *  GetBuildingPtr(int);

    // address=[0x13361b0]
    int  GetTimeSinceHallDestruction(int);

    // address=[0x1336400]
    bool  PlayerUsesManakopterHalls(int);

    // address=[0x14eb500]
    static bool __cdecl IsMilitaryBuildingEx(int);

    // address=[0x14f42d0]
     CBuildingMgr(void);

    // address=[0x14f4340]
     ~CBuildingMgr(void);

    // address=[0x14f4360]
    void  Clear(void);

    // address=[0x14f4450]
    void  LoadInfo(void);

    // address=[0x14f4470]
    void  LoadBuildingData(class S4::CMapFile &,int);

    // address=[0x14f4630]
    int  AddBuilding(int,int,int,int,bool);

    // address=[0x14f4990]
    int  SearchSpaceForBuilding(int,int,int,int,bool,int);

    // address=[0x14f4b50]
    void  DestroyBuilding(int,int,int);

    // address=[0x14f4f60]
    int  GetFirstBuildingId(int,int)const;

    // address=[0x14f4fe0]
    class CBuilding *  GetNextBuilding(int,int)const;

    // address=[0x14f50e0]
    class CBuilding *  GetBuilding(int,int)const;

    // address=[0x14f51a0]
    int  GetNumberOfBuildings(int,int,int)const;

    // address=[0x14f52f0]
    void  ChangeNumberOfBuildings(int,int,int,int);

    // address=[0x14f5460]
    bool  CheckNumberOfOccupiedMilitaryBuildings(int,int);

    // address=[0x14f5580]
    static bool __cdecl IsMine(int);

    // address=[0x14f55e0]
    static bool __cdecl IsMilitary(int);

    // address=[0x14f5660]
    static bool __cdecl IsPortEx(int);

    // address=[0x14f56a0]
    static bool __cdecl IsShipyardEx(int);

    // address=[0x14f56e0]
    int  CheckForBuild(int,int,int,int,int);

    // address=[0x14f6050]
    int  CheckForBuildInWater(int,int,int,int);

    // address=[0x14f60b0]
    int  CheckForBuildDarkTribe(int,int,int,int,int);

    // address=[0x14f67f0]
    void  ShowWorkingArea(int)const;

    // address=[0x14f69b0]
    bool  IsGoodWorkingAreaCenter(int,int &,int &)const;

    // address=[0x14f6ad0]
    static void __cdecl FillBuildingAmount(class CInfoExchange *,bool,bool);

    // address=[0x14f6d90]
    static void __cdecl FillAddSoldierSideBar(class CInfoExchange *,bool,int);

    // address=[0x14f6e20]
    static void __cdecl FillToolSideBar(class CInfoExchange *,bool,int);

    // address=[0x14f6eb0]
    static void __cdecl FillWeaponSideBar(class CInfoExchange *,bool,int);

    // address=[0x14f6f40]
    static void __cdecl FillGoodsOutSideBar(class CInfoExchange *,bool,int);

    // address=[0x14f6fd0]
    static void __cdecl FillTradeSideBar(class CInfoExchange *,bool,int);

    // address=[0x14f7060]
    static void __cdecl FillStorageSideBar(class CInfoExchange *,bool,int);

    // address=[0x14f70f0]
    static void __cdecl FillEyeCatcherSideBar(class CInfoExchange *,bool,int);

    // address=[0x14f72c0]
    static void __cdecl FillAddVehicleSideBar(class CInfoExchange *,bool,int);

    // address=[0x14f7350]
    void  Store(class S4::CMapFile &);

    // address=[0x14f7890]
    void  Load(class S4::CMapFile &);

    // address=[0x14f7d90]
    void  ChangeOwnerIdOfBuilding(int,int);

    // address=[0x14f7f00]
    void  CalculateNumberOfBuildingsInEcoSector(int,int,int,int &,int &);

    // address=[0x14fab40]
    int  GetValidManakopterHallPosition(int);

    // address=[0x14fabe0]
    bool  IsPositionNearMKHPosition(int,int);

    // address=[0x15139f0]
    bool  InLoadBuildingData(void)const;

    // address=[0x151fa20]
    int  EcoSectorId(int)const;

private:
    // address=[0x14eb280]
    void *  Alloc(unsigned int);

    // address=[0x14eb3c0]
    void  Dealloc(void *);

    // address=[0x14f8030]
    int  CheckForBuildWater(int,int,int,int,int);

    // address=[0x14f8850]
    static class IBuildingRole * __cdecl CreateBuildingRole(int,int,bool);

    // address=[0x14f9170]
    static class IBuildingRole * __cdecl LoadBuildingRole(std::istream &,int);

    // address=[0x14f9410]
    int  CheckForBuildCalc(int,int,int,int,int,int);

    // address=[0x14fa560]
    void  AddSoldierToStartTower(int,int);

    // address=[0x14fa7b0]
    void  CheckOutBuilding(int);

    // address=[0x14fa900]
    void  AttachBuilding(int,int,int);

    // address=[0x14fa9f0]
    void  DetachBuilding(int,int,int);

    // address=[0x14facb0]
    bool  IsValidManakopterHallPosition(int,int);

    // address=[0x14fad00]
    bool  AddPositionToList(int,int);

};


#endif // CBUILDINGMGR_H
