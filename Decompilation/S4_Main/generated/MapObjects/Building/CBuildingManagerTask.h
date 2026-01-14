#ifndef CBUILDINGMANAGERTASK_H
#define CBUILDINGMANAGERTASK_H

class CBuildingManagerTask : public IScheduleEntry {
public:
    // address=[0x2f4f710]
     CBuildingManagerTask(void);

    // address=[0x2f4fb00]
    virtual  ~CBuildingManagerTask(void);

    // address=[0x2f4fb60]
    virtual bool  IsShooting(void);

    // address=[0x2f4fe10]
    virtual bool  action(void);

    // address=[0x2f4fed0]
    virtual bool  IsAlive(void);

    // address=[0x2f4fee0]
    virtual bool  WaitFor(void);

    // address=[0x2f4ff10]
    void  UpdateRequireGoods(bool);

    // address=[0x2f50810]
    int  GetToolRequireIndex(enum PILE_TYPES);

    // address=[0x2f50860]
    bool  GetBuildingPermission(class CBuildingEvent *);

    // address=[0x2f50b50]
    bool  GetSeperateBuildingPermission(class CBuildingEvent *);

    // address=[0x2f50db0]
    void  SetRejectedBuilding(enum BUILDING_TYPES);

    // address=[0x2f50e00]
    bool  IsRejectedBuilding(enum BUILDING_TYPES,bool);

    // address=[0x2f50e60]
    bool  SetBuildingAtPlanning(enum BUILDING_TYPES);

    // address=[0x2f50eb0]
    bool  IsBuildingAtPlanning(enum BUILDING_TYPES);

    // address=[0x2f50f00]
    bool  RemoveBuildingAtPlanning(enum BUILDING_TYPES);

    // address=[0x2f50f60]
    bool  AlertLevelZero(void);

    // address=[0x2f511f0]
    bool  AlertLevelOne(void);

};


#endif // CBUILDINGMANAGERTASK_H
