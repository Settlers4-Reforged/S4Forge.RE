#ifndef CSCHEDULE_H
#define CSCHEDULE_H

#include "defines.h"

class CSchedule {
public:
    // address=[0x2f41e40]
     CSchedule(class CEcoSectorAI * a2, int a3, int a4);

    // address=[0x2f41f40]
     ~CSchedule(void);

    // address=[0x2f41fb0]
    void  InitSchedule(void);

    // address=[0x2f42970]
    void  InitLevelManager(void);

    // address=[0x2f42ce0]
    int  Settings(void);

    // address=[0x2f43000]
    bool  trigger(void);

    // address=[0x2f43220]
    int  GenerateSchedKey(void);

    // address=[0x2f43260]
    int  NewSchedEntry(class IScheduleEntry * a2);

    // address=[0x2f432a0]
    int  NewSchedEntry(class IScheduleEntry * a2, int a3);

    // address=[0x2f432d0]
    class IScheduleEntry *  GetSchedEntry(int a2);

    // address=[0x2f43330]
    class IScheduleEntry *  GetSpecialTask(int a2);

    // address=[0x2f43380]
    class CMaterialManagerTask *  GetMaterialManager(enum PILE_TYPES a2);

    // address=[0x2f433f0]
    class CResourceManagerTask *  GetResourceManager(int a2);

    // address=[0x2f43460]
    class CProductivityControll *  GetProductivityControll(struct SBuildId a2);

    // address=[0x2f434e0]
    class CExpandationEvent *  GetExpandationEvent(int a2);

    // address=[0x2f43550]
    bool  IsBorderElement(int a2, int a3);

    // address=[0x2f43580]
    class CBuildingEvent *  GetBuildingEvent(int a2, enum T_BUILD_LEVEL a3);

    // address=[0x2f43600]
    bool  GetBuildingInPlannedStatus(class CReserveEntry * a2);

    // address=[0x2f43700]
    class CBuildingEvent *  GetBuildingAtPosition(int a2, int a3);

    // address=[0x2f43790]
    int  GetTmpMaxNumberOfBuildingType(enum BUILDING_TYPES a2);

    // address=[0x2f43930]
    bool  EnoughNumberOfBuildingType(enum BUILDING_TYPES a2);

    // address=[0x2f43970]
    int  GetSumResourceAmount(enum BUILDING_TYPES a2, int a3, int a4, int a5);

    // address=[0x2f43d20]
    int  AreaHasOtherResource(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x2f44030]
    int  GetNearExpandationPositionOutside(int a2, int a3, class std::vector<int,class std::allocator<int> > & a4);

    // address=[0x2f443a0]
    int  PreSelect16Grid(enum BUILDING_TYPES a2, struct SBUILDINFODATA * a3, class CReserveEntry * a4, class std::vector<struct SBUILDINFODATA,class std::allocator<struct SBUILDINFODATA> > & a5, int a6, int a7);

    // address=[0x2f444e0]
    int  GetMainProblemSolve(int a2);

    // address=[0x2f44540]
    void  UpdateExpandationEvents(int a2);

    // address=[0x2f44600]
    bool  IsAnyExpandation(void);

    // address=[0x2f44660]
    bool  SetPositionOfTower(int a2, int a3, int a4, int a5);

    // address=[0x2f446f0]
    bool  ProduceWeapons(int a2, int a3);

    // address=[0x2f44bb0]
    bool  AllSubProblemsSolved(int a2);

    // address=[0x2f44c40]
    int  GetTargetPosition(int a2);

    // address=[0x2f44f30]
    int  isDepSchedSolved(int a2);

    // address=[0x2f44fe0]
    bool  TerminateSubProblems(int a2);

    // address=[0x2f45070]
    bool  MarkSolvedProblem(int a2, bool a3);

    // address=[0x2f45250]
    int  SearchExternSolution(int a2, int a3, int a4, int a5, int a6, int a7);

    // address=[0x2f45310]
    class CSolutionTree *  GetSolution(int a2);

    // address=[0x2f45390]
    bool  InvokeNeeded(enum BUILDING_TYPES a2);

    // address=[0x2f45480]
    class CInvokeEvent *  GetInvokeEvent(enum BUILDING_TYPES a2);

    // address=[0x2f45500]
    int  GetContentOfWorkingArea(int a2, enum BUILDING_TYPES a3);

    // address=[0x2f456a0]
    int  GetContentOfWorkingArea(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x2f458f0]
    bool  SetBestWorkingAreaPosition(int a2, enum BUILDING_TYPES a3, int & a4, int & a5);

    // address=[0x2f45dc0]
    bool  SetSpecialWorkingAreaPosition(int a2, enum BUILDING_TYPES a3, int & a4, int & a5, int a6);

    // address=[0x2f46010]
    void  UnmarkBuildings(void);

    // address=[0x2f460d0]
    class CProductivityControll *  GetUnmarkBuildings(enum BUILDING_TYPES a2);

    // address=[0x2f461c0]
    bool  VerifyAllBuildingIds(void);

    // address=[0x2f46320]
    int  GetBuildingTypeInGroup(enum BUILDING_TYPES a2, int a3, int a4, class std::vector<struct SBuildId,class std::allocator<struct SBuildId> > & a5);

    // address=[0x2f46450]
    int  GetNearestInputBuildings(struct SBuildId a2, int a3, struct SBuildId * a4);

    // address=[0x2f46870]
    bool  GetNearestBuildingType(enum BUILDING_TYPES a2, int a3, int a4, int & a5);

    // address=[0x2f469f0]
    int  CollectWorkingArea(int a2, class std::vector<int,class std::allocator<int> > & a3);

    // address=[0x2f46b80]
    int  GetResourceConsumption(int a1, int a2, class std::vector<int,class std::allocator<int> > a3);

    // address=[0x2f46c50]
    bool  ResourceNearAtWork(enum BUILDING_TYPES a2, enum BUILDING_TYPES a3, int a4, int a5, int a6);

    // address=[0x2f46cd0]
    int  GetBuildingTypeAroundAt(enum BUILDING_TYPES a2, int a3, int a4, int a5, class std::vector<struct SBuildId,class std::allocator<struct SBuildId> > & a6);

    // address=[0x2f46e10]
    void  ChangeBuildingLevel(int a2, int a3, enum T_BUILD_LEVEL a4);

    // address=[0x2f46eb0]
    bool  GetWeakBuilding(enum BUILDING_TYPES a2, class std::vector<struct SMakroEntry,class std::allocator<struct SMakroEntry> > & a3, enum PILE_TYPES a4, int & a5);

    // address=[0x2f47a20]
    int  GetMakroIndex(class CProductionMakroData * a1, enum BUILDING_TYPES a2);

    // address=[0x2f47a70]
    int  GetWeakIndex(class CProductionMakroData * a2, int a3, enum PILE_TYPES a4, int & a5);

    // address=[0x2f47d70]
    int  GetPotentialGoodCapacity(enum PILE_TYPES a2);

    // address=[0x2f47e10]
    void  CopyMakroBuildings(struct SBuildId * a1, struct SBuildId * a2, int a3);

    // address=[0x2f47e90]
    bool  BuildingInWeakArray(struct SBuildId * a1, struct SBuildId * a2);

    // address=[0x2f47ef0]
    bool  CalcOptPositionForNewBuilding(struct SBuildId * a1, int & a2, int & a3);

    // address=[0x2f47f20]
    int  GetGoodPositionForBuilding(enum BUILDING_TYPES a2);

    // address=[0x2f48370]
    enum BUILDING_TYPES  GetResidenceBuildingLevel(void);

    // address=[0x2f483d0]
    bool  DestroySeveralBuildings(void);

    // address=[0x2f48640]
    bool  SharedPileType(enum PILE_TYPES a1);

    // address=[0x2f486b0]
    int  GetAllBuildingOfType(enum BUILDING_TYPES a2, struct SBuildId * a3);

    // address=[0x2f48850]
    int  GetAllBuildingOfTypeInProdControl(enum BUILDING_TYPES a2, struct SBuildId * a3);

    // address=[0x2f48970]
    int  GetPlannedBuildingId(int a2, int a3);

    // address=[0x2f48a10]
    int  GetNumberOfBuildingType(enum BUILDING_TYPES a2);

    // address=[0x2f48a90]
    int  GetNumberOfBuildingTypeAtBuilding(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x2f48b70]
    int  GetNumberOfBuildingTypeAtWork(enum BUILDING_TYPES a2);

    // address=[0x2f48c00]
    void  GetPlannedBuildingPosition(int a2, int & a3, int & a4);

    // address=[0x2f48c90]
    int  CollectPlannedBuildingPlaces(class CReserveEntry * a2);

    // address=[0x2f48da0]
    int  GetNextPositionInside(int a2, int a3);

    // address=[0x2f48ec0]
    bool  BestAndPossiblePlaceOf8Grid(enum BUILDING_TYPES a2, struct SBUILDINFODATA * a3, class CReserveEntry * a4, int & a5, int & a6, int a7, int a8, bool a9);

    // address=[0x2f49070]
    int  GeneralValuation(enum BUILDING_TYPES a2, int a3, int a4, int a5, int a6, bool a7, int a8);

    // address=[0x2f495f0]
    int  PreferBuildingPlaces(enum BUILDING_TYPES a1, class CReserveEntry * a2);

    // address=[0x2f49610]
    bool  ReadMessages(void);

    // address=[0x2f4c780]
    int  CalcDistance(int a2, int a3);

    // address=[0x2f4c850]
    int  CalcDistance(int a2, int a3, int a4, int a5);

    // address=[0x2f4c8f0]
    class IAIEcoManager *  GetEcoSector(void);

};


#endif // CSCHEDULE_H
