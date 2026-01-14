#ifndef CRESERVEDATABASE_H
#define CRESERVEDATABASE_H

class CReserveDatabase {
public:
    // address=[0x2f3bc30]
    int  PackPosition(int,int);

    // address=[0x2f3bc50]
    void  UnpackPosition(int,int &,int &);

    // address=[0x2f40540]
     CReserveDatabase(void);

    // address=[0x2f40670]
     ~CReserveDatabase(void);

    // address=[0x2f40700]
    int  ReserveBuilding(enum BUILDING_TYPES,int,int,int,signed char,int,int);

    // address=[0x2f408f0]
    bool  RemoveBuilding(int,int);

    // address=[0x2f40960]
    void  RemoveGrpEntry(int,class CGrpReserveEntry *);

    // address=[0x2f40ab0]
    bool  GetResPosition(int,int &,int &);

    // address=[0x2f40b10]
    int  GetReserveBuilding(int,enum BUILDING_TYPES);

    // address=[0x2f40b70]
    int  GetResGrpNr(int);

    // address=[0x2f40ba0]
    int  CreateGrpNumber(int,int);

    // address=[0x2f40bc0]
    bool  NewSubReserveEntry(class CGrpReserveEntry *,int);

    // address=[0x2f40c20]
    bool  GetSubReserveEntry(int,class CGrpReserveEntry * &,enum BUILDING_TYPES);

    // address=[0x2f40d70]
    bool  GetResBuildingInGroup(int,class CReserveEntry *);

    // address=[0x2f40f70]
    enum BUILDING_TYPES  GetResBuildingType(int);

    // address=[0x2f40ff0]
    class CGrpReserveEntry *  GetGrpResBuilding(int);

    // address=[0x2f410a0]
    class CGrpReserveEntry *  GetGrpResBuilding(int,class CGrpReserveEntry *);

    // address=[0x2f41190]
    bool  IsBuildingPlaceAvailable(class IAIEcoManager *,enum BUILDING_TYPES,int,class CReserveEntry *);

    // address=[0x2f41240]
    bool  IsBuildingTypeInGrp(enum BUILDING_TYPES,int);

    // address=[0x2f413b0]
    bool  InSameGroup(int,int);

    // address=[0x2f41440]
    bool  UnLockReserveDatabase(int);

    // address=[0x2f414a0]
    int  GetLockedSchedNr(void);

    // address=[0x2f414c0]
    bool  LockReserveDatabase(int);

    // address=[0x2f41510]
    bool  ReserveLock(int);

    // address=[0x2f41540]
    int  UpdateReservedBuildingPlaces(enum BUILDING_TYPES);

    // address=[0x2f41550]
    void  SetScoringData(int,int);

    // address=[0x2f41580]
    int  GetScoringData(int);

    // address=[0x2f415b0]
    int  GetPackWorldPosition(int);

    // address=[0x2f415e0]
    int  GetPackWorldPosition(int,int &,int &);

    // address=[0x2f41630]
    bool  InSameGrid8(int,int);

};


#endif // CRESERVEDATABASE_H
