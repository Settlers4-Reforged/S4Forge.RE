#ifndef CBUILDINGMGR_H
#define CBUILDINGMGR_H

#include "defines.h"

class CBuildingMgr {
public:
    // address=[0x12fcb90]
    class CBuilding &  operator[](int a1);

    // address=[0x130e930]
    class CBuilding &  Building(int a2);

    // address=[0x130eba0]
    class CBuilding *  GetBuildingPtr(int a2);

    // address=[0x13361b0]
    int  GetTimeSinceHallDestruction(int a2);

    // address=[0x1336400]
    bool  PlayerUsesManakopterHalls(int a2);

    // address=[0x14eb500]
    static bool __cdecl IsMilitaryBuildingEx(int a1);

    // address=[0x14f42d0]
     CBuildingMgr(void);

    // address=[0x14f4340]
     ~CBuildingMgr(void);

    // address=[0x14f4360]
    void  Clear(void);

    // address=[0x14f4450]
    void  LoadInfo(void);

    // address=[0x14f4470]
    void  LoadBuildingData(class S4::CMapFile & a2, int a3);

    // address=[0x14f4630]
    int  AddBuilding(int a2, int a3, int a4, int a5, bool a6);

    // address=[0x14f4990]
    int  SearchSpaceForBuilding(int a2, int a3, int a4, int a5, bool a6, int a7);

    // address=[0x14f4b50]
    void  DestroyBuilding(int a2, int a3, int a4);

    // address=[0x14f4f60]
    int  GetFirstBuildingId(int a2, int a3)const;

    // address=[0x14f4fe0]
    class CBuilding *  GetNextBuilding(int a2, int a3)const;

    // address=[0x14f50e0]
    class CBuilding *  GetBuilding(int a2, int a3)const;

    // address=[0x14f51a0]
    int  GetNumberOfBuildings(int a2, int a3, int a4)const;

    // address=[0x14f52f0]
    void  ChangeNumberOfBuildings(int a2, int a3, int a4, int a5);

    // address=[0x14f5460]
    bool  CheckNumberOfOccupiedMilitaryBuildings(int a2, int a3);

    // address=[0x14f5580]
    static bool __cdecl IsMine(int buildingType);

    // address=[0x14f55e0]
    static bool __cdecl IsMilitary(int a1);

    // address=[0x14f5660]
    static bool __cdecl IsPortEx(int a1);

    // address=[0x14f56a0]
    static bool __cdecl IsShipyardEx(int a1);

    // address=[0x14f56e0]
    int  CheckForBuild(int x, int y, int ownerId, int a5, int a6);

    // address=[0x14f6050]
    int  CheckForBuildInWater(int a2, int a3, int a4, int a5);

    // address=[0x14f60b0]
    int  CheckForBuildDarkTribe(int a2, int a3, int a4, int a5, int a6);

    // address=[0x14f67f0]
    void  ShowWorkingArea(int a2)const;

    // address=[0x14f69b0]
    bool  IsGoodWorkingAreaCenter(int a2, int & a3, int & a4)const;

    // address=[0x14f6ad0]
    static void __cdecl FillBuildingAmount(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x14f6d90]
    static void __cdecl FillAddSoldierSideBar(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x14f6e20]
    static void __cdecl FillToolSideBar(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x14f6eb0]
    static void __cdecl FillWeaponSideBar(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x14f6f40]
    static void __cdecl FillGoodsOutSideBar(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x14f6fd0]
    static void __cdecl FillTradeSideBar(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x14f7060]
    static void __cdecl FillStorageSideBar(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x14f70f0]
    static void __cdecl FillEyeCatcherSideBar(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x14f72c0]
    static void __cdecl FillAddVehicleSideBar(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x14f7350]
    void  Store(class S4::CMapFile & a2);

    // address=[0x14f7890]
    void  Load(class S4::CMapFile & a2);

    // address=[0x14f7d90]
    void  ChangeOwnerIdOfBuilding(int a2, int a3);

    // address=[0x14f7f00]
    void  CalculateNumberOfBuildingsInEcoSector(int a2, int a3, int a4, int & a5, int & a6);

    // address=[0x14fab40]
    int  GetValidManakopterHallPosition(int a2);

    // address=[0x14fabe0]
    bool  IsPositionNearMKHPosition(int a2, int a3);

    // address=[0x15139f0]
    bool  InLoadBuildingData(void)const;

    // address=[0x151fa20]
    int  EcoSectorId(int a2)const;

private:
    // address=[0x14eb280]
    void *  Alloc(unsigned int a2);

    // address=[0x14eb3c0]
    void  Dealloc(void * a2);

    // address=[0x14f8030]
    int  CheckForBuildWater(int a2, int a3, int a4, int a5, int a6);

    // address=[0x14f8850]
    static class IBuildingRole * __cdecl CreateBuildingRole(int a1, int a2, bool a3);

    // address=[0x14f9170]
    static class IBuildingRole * __cdecl LoadBuildingRole(std::istream & a1, int a2);

    // address=[0x14f9410]
    int  CheckForBuildCalc(int a2, int a3, int a4, int a5, int a6, int a7);

    // address=[0x14fa560]
    void  AddSoldierToStartTower(int a2, int a3);

    // address=[0x14fa7b0]
    void  CheckOutBuilding(int a2);

    // address=[0x14fa900]
    void  AttachBuilding(int a2, int a3, int a4);

    // address=[0x14fa9f0]
    void  DetachBuilding(int a2, int a3, int a4);

    // address=[0x14facb0]
    bool  IsValidManakopterHallPosition(int a2, int a3);

    // address=[0x14fad00]
    bool  AddPositionToList(int a2, int a3);

};


#endif // CBUILDINGMGR_H
