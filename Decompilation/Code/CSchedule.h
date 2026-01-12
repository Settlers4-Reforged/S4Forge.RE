#ifndef CSCHEDULE_H
#define CSCHEDULE_H

class CSchedule {
public:
    // address=[0x2f41e40]
     CSchedule(class CEcoSectorAI *,int,int);

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
    int  NewSchedEntry(class IScheduleEntry *);

    // address=[0x2f432a0]
    int  NewSchedEntry(class IScheduleEntry *,int);

    // address=[0x2f432d0]
    class IScheduleEntry *  GetSchedEntry(int);

    // address=[0x2f43330]
    class IScheduleEntry *  GetSpecialTask(int);

    // address=[0x2f43380]
    class CMaterialManagerTask *  GetMaterialManager(enum PILE_TYPES);

    // address=[0x2f433f0]
    class CResourceManagerTask *  GetResourceManager(int);

    // address=[0x2f43460]
    class CProductivityControll *  GetProductivityControll(struct SBuildId);

    // address=[0x2f434e0]
    class CExpandationEvent *  GetExpandationEvent(int);

    // address=[0x2f43550]
    bool  IsBorderElement(int,int);

    // address=[0x2f43580]
    class CBuildingEvent *  GetBuildingEvent(int,enum T_BUILD_LEVEL);

    // address=[0x2f43600]
    bool  GetBuildingInPlannedStatus(class CReserveEntry *);

    // address=[0x2f43700]
    class CBuildingEvent *  GetBuildingAtPosition(int,int);

    // address=[0x2f43790]
    int  GetTmpMaxNumberOfBuildingType(enum BUILDING_TYPES);

    // address=[0x2f43930]
    bool  EnoughNumberOfBuildingType(enum BUILDING_TYPES);

    // address=[0x2f43970]
    int  GetSumResourceAmount(enum BUILDING_TYPES,int,int,int);

    // address=[0x2f43d20]
    int  AreaHasOtherResource(enum BUILDING_TYPES,int,int);

    // address=[0x2f44030]
    int  GetNearExpandationPositionOutside(int,int,class std::vector<int,class std::allocator<int> > &);

    // address=[0x2f443a0]
    int  PreSelect16Grid(enum BUILDING_TYPES,struct SBUILDINFODATA *,class CReserveEntry *,class std::vector<struct SBUILDINFODATA,class std::allocator<struct SBUILDINFODATA> > &,int,int);

    // address=[0x2f444e0]
    int  GetMainProblemSolve(int);

    // address=[0x2f44540]
    void  UpdateExpandationEvents(int);

    // address=[0x2f44600]
    bool  IsAnyExpandation(void);

    // address=[0x2f44660]
    bool  SetPositionOfTower(int,int,int,int);

    // address=[0x2f446f0]
    bool  ProduceWeapons(int,int);

    // address=[0x2f44bb0]
    bool  AllSubProblemsSolved(int);

    // address=[0x2f44c40]
    int  GetTargetPosition(int);

    // address=[0x2f44f30]
    int  isDepSchedSolved(int);

    // address=[0x2f44fe0]
    bool  TerminateSubProblems(int);

    // address=[0x2f45070]
    bool  MarkSolvedProblem(int,bool);

    // address=[0x2f45250]
    int  SearchExternSolution(int,int,int,int,int,int);

    // address=[0x2f45310]
    class CSolutionTree *  GetSolution(int);

    // address=[0x2f45390]
    bool  InvokeNeeded(enum BUILDING_TYPES);

    // address=[0x2f45480]
    class CInvokeEvent *  GetInvokeEvent(enum BUILDING_TYPES);

    // address=[0x2f45500]
    int  GetContentOfWorkingArea(int,enum BUILDING_TYPES);

    // address=[0x2f456a0]
    int  GetContentOfWorkingArea(enum BUILDING_TYPES,int,int);

    // address=[0x2f458f0]
    bool  SetBestWorkingAreaPosition(int,enum BUILDING_TYPES,int &,int &);

    // address=[0x2f45dc0]
    bool  SetSpecialWorkingAreaPosition(int,enum BUILDING_TYPES,int &,int &,int);

    // address=[0x2f46010]
    void  UnmarkBuildings(void);

    // address=[0x2f460d0]
    class CProductivityControll *  GetUnmarkBuildings(enum BUILDING_TYPES);

    // address=[0x2f461c0]
    bool  VerifyAllBuildingIds(void);

    // address=[0x2f46320]
    int  GetBuildingTypeInGroup(enum BUILDING_TYPES,int,int,class std::vector<struct SBuildId,class std::allocator<struct SBuildId> > &);

    // address=[0x2f46450]
    int  GetNearestInputBuildings(struct SBuildId,int,struct SBuildId *);

    // address=[0x2f46870]
    bool  GetNearestBuildingType(enum BUILDING_TYPES,int,int,int &);

    // address=[0x2f469f0]
    int  CollectWorkingArea(int,class std::vector<int,class std::allocator<int> > &);

    // address=[0x2f46b80]
    int  GetResourceConsumption(int,int,class std::vector<int,class std::allocator<int> >);

    // address=[0x2f46c50]
    bool  ResourceNearAtWork(enum BUILDING_TYPES,enum BUILDING_TYPES,int,int,int);

    // address=[0x2f46cd0]
    int  GetBuildingTypeAroundAt(enum BUILDING_TYPES,int,int,int,class std::vector<struct SBuildId,class std::allocator<struct SBuildId> > &);

    // address=[0x2f46e10]
    void  ChangeBuildingLevel(int,int,enum T_BUILD_LEVEL);

    // address=[0x2f46eb0]
    bool  GetWeakBuilding(enum BUILDING_TYPES,class std::vector<struct SMakroEntry,class std::allocator<struct SMakroEntry> > &,enum PILE_TYPES,int &);

    // address=[0x2f47a20]
    int  GetMakroIndex(class CProductionMakroData *,enum BUILDING_TYPES);

    // address=[0x2f47a70]
    int  GetWeakIndex(class CProductionMakroData *,int,enum PILE_TYPES,int &);

    // address=[0x2f47d70]
    int  GetPotentialGoodCapacity(enum PILE_TYPES);

    // address=[0x2f47e10]
    void  CopyMakroBuildings(struct SBuildId *,struct SBuildId *,int);

    // address=[0x2f47e90]
    bool  BuildingInWeakArray(struct SBuildId *,struct SBuildId *);

    // address=[0x2f47ef0]
    bool  CalcOptPositionForNewBuilding(struct SBuildId *,int &,int &);

    // address=[0x2f47f20]
    int  GetGoodPositionForBuilding(enum BUILDING_TYPES);

    // address=[0x2f48370]
    enum BUILDING_TYPES  GetResidenceBuildingLevel(void);

    // address=[0x2f483d0]
    bool  DestroySeveralBuildings(void);

    // address=[0x2f48640]
    bool  SharedPileType(enum PILE_TYPES);

    // address=[0x2f486b0]
    int  GetAllBuildingOfType(enum BUILDING_TYPES,struct SBuildId *);

    // address=[0x2f48850]
    int  GetAllBuildingOfTypeInProdControl(enum BUILDING_TYPES,struct SBuildId *);

    // address=[0x2f48970]
    int  GetPlannedBuildingId(int,int);

    // address=[0x2f48a10]
    int  GetNumberOfBuildingType(enum BUILDING_TYPES);

    // address=[0x2f48a90]
    int  GetNumberOfBuildingTypeAtBuilding(enum BUILDING_TYPES,int,int);

    // address=[0x2f48b70]
    int  GetNumberOfBuildingTypeAtWork(enum BUILDING_TYPES);

    // address=[0x2f48c00]
    void  GetPlannedBuildingPosition(int,int &,int &);

    // address=[0x2f48c90]
    int  CollectPlannedBuildingPlaces(class CReserveEntry *);

    // address=[0x2f48da0]
    int  GetNextPositionInside(int,int);

    // address=[0x2f48ec0]
    bool  BestAndPossiblePlaceOf8Grid(enum BUILDING_TYPES,struct SBUILDINFODATA *,class CReserveEntry *,int &,int &,int,int,bool);

    // address=[0x2f49070]
    int  GeneralValuation(enum BUILDING_TYPES,int,int,int,int,bool,int);

    // address=[0x2f495f0]
    int  PreferBuildingPlaces(enum BUILDING_TYPES,class CReserveEntry *);

    // address=[0x2f49610]
    bool  ReadMessages(void);

    // address=[0x2f4c780]
    int  CalcDistance(int,int);

    // address=[0x2f4c850]
    int  CalcDistance(int,int,int,int);

    // address=[0x2f4c8f0]
    class IAIEcoManager *  GetEcoSector(void);

};


#endif // CSCHEDULE_H
