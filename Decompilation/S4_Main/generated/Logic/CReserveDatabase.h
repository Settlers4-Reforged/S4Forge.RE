#ifndef CRESERVEDATABASE_H
#define CRESERVEDATABASE_H

#include "defines.h"

class CReserveDatabase {
public:
    // address=[0x2f3bc30]
    int  PackPosition(int a2, int a3);

    // address=[0x2f3bc50]
    void  UnpackPosition(int a2, int & a3, int & a4);

    // address=[0x2f40540]
     CReserveDatabase(void);

    // address=[0x2f40670]
     ~CReserveDatabase(void);

    // address=[0x2f40700]
    int  ReserveBuilding(enum BUILDING_TYPES a2, int a3, int a4, int a5, signed char a6, int a7, int a8);

    // address=[0x2f408f0]
    bool  RemoveBuilding(int a2, int a3);

    // address=[0x2f40960]
    void  RemoveGrpEntry(int a2, class CGrpReserveEntry * a3);

    // address=[0x2f40ab0]
    bool  GetResPosition(int a2, int & a3, int & a4);

    // address=[0x2f40b10]
    int  GetReserveBuilding(int a2, enum BUILDING_TYPES a3);

    // address=[0x2f40b70]
    int  GetResGrpNr(int a2);

    // address=[0x2f40ba0]
    int  CreateGrpNumber(int a2, int a3);

    // address=[0x2f40bc0]
    bool  NewSubReserveEntry(class CGrpReserveEntry * a2, int a3);

    // address=[0x2f40c20]
    bool  GetSubReserveEntry(int a2, class CGrpReserveEntry * & a3, enum BUILDING_TYPES a4);

    // address=[0x2f40d70]
    bool  GetResBuildingInGroup(int a2, class CReserveEntry * a3);

    // address=[0x2f40f70]
    enum BUILDING_TYPES  GetResBuildingType(int a2);

    // address=[0x2f40ff0]
    class CGrpReserveEntry *  GetGrpResBuilding(int a2);

    // address=[0x2f410a0]
    class CGrpReserveEntry *  GetGrpResBuilding(int a2, class CGrpReserveEntry * a3);

    // address=[0x2f41190]
    bool  IsBuildingPlaceAvailable(class IAIEcoManager * a2, enum BUILDING_TYPES a3, int a4, class CReserveEntry * a5);

    // address=[0x2f41240]
    bool  IsBuildingTypeInGrp(enum BUILDING_TYPES a2, int a3);

    // address=[0x2f413b0]
    bool  InSameGroup(int a2, int a3);

    // address=[0x2f41440]
    bool  UnLockReserveDatabase(int a2);

    // address=[0x2f414a0]
    int  GetLockedSchedNr(void);

    // address=[0x2f414c0]
    bool  LockReserveDatabase(int a2);

    // address=[0x2f41510]
    bool  ReserveLock(int a2);

    // address=[0x2f41540]
    int  UpdateReservedBuildingPlaces(enum BUILDING_TYPES a2);

    // address=[0x2f41550]
    void  SetScoringData(int a2, int a3);

    // address=[0x2f41580]
    int  GetScoringData(int a2);

    // address=[0x2f415b0]
    int  GetPackWorldPosition(int a2);

    // address=[0x2f415e0]
    int  GetPackWorldPosition(int a2, int & a3, int & a4);

    // address=[0x2f41630]
    bool  InSameGrid8(int a2, int a3);

};


#endif // CRESERVEDATABASE_H
