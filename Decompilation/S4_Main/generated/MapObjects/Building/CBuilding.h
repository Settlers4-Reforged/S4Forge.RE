#ifndef CBUILDING_H
#define CBUILDING_H

#include "defines.h"

class CBuilding : public IAnimatedEntity {
public:
    // address=[0x12fd5a0]
    class IBuildingRole &  Role(void);

    // address=[0x1307110]
    int  EnsignX(void)const;

    // address=[0x1307130]
    int  EnsignY(void)const;

    // address=[0x130eb40]
    int  EnsignPackedXY(void)const;

    // address=[0x130f010]
    bool  HaveInhabitant(void)const;

    // address=[0x13466c0]
    int  GetBuildingNeed(int a2)const;

    // address=[0x1346700]
    int  GetPileIdWithGood(int a2)const;

    // address=[0x1346740]
    int  GetWorkingAreaPackedXY(void)const;

    // address=[0x1346790]
    bool  IsBuildUp(void)const;

    // address=[0x13ffd20]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1439b00]
    int  GetPileIdWithNeedForGood(int a2)const;

    // address=[0x14604d0]
    void  FillDialog(void);

    // address=[0x1460760]
    void  NotifySelected(void);

    // address=[0x1473110]
    void  SetWorkingAreaPackedXY(int a2);

    // address=[0x1473150]
    void  Switch(void);

    // address=[0x14e88b0]
    int  BuildingTypeEx(void);

    // address=[0x14e8910]
    int  DoorPackedXY(void)const;

    // address=[0x14e89b0]
    virtual void  Delete(void);

    // address=[0x14e8b00]
    virtual void  PostLoadInit(void);

    // address=[0x14e8ba0]
    virtual void  LogicUpdate(void);

    // address=[0x14e8be0]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x14e8c80]
    int  EnsignWorldIdx(void)const;

    // address=[0x14e8ca0]
    int  DoorWorldIdx(void)const;

    // address=[0x14e8cc0]
    int  EcoSectorId(void)const;

    // address=[0x14e8ce0]
    void  TryCrushBuilding(void);

    // address=[0x14e8e20]
    void  CrushBuilding(void);

    // address=[0x14e8fc0]
    void  DestroyBuilding(int a2);

    // address=[0x14e92f0]
    void  GoodArrive(int a2);

    // address=[0x14e9340]
    void  SetToWorld(void);

    // address=[0x14e9880]
    virtual void  Decrease(int a2);

    // address=[0x14e9980]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x14e99a0]
    static void __cdecl operator delete(void * a1);

    // address=[0x14e99e0]
    virtual void  Attach(int a2);

    // address=[0x14e9a10]
    virtual void  Detach(int a2);

    // address=[0x14e9a50]
    virtual void  Notify(class CEntityEvent const & a2)const;

    // address=[0x14e9a70]
    virtual void  Notify(class CEntityEvent const & a1, class INotifyFilter & a2)const;

    // address=[0x14e9a90]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET a2, int a3);

    // address=[0x14e9b00]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET a2);

    // address=[0x14e9b30]
     CBuilding(std::istream & a2);

    // address=[0x14e9cc0]
    virtual void  Store(std::ostream & a2);

    // address=[0x14eb2c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14eb550]
    bool  IsOccupied(void)const;

    // address=[0x14eb810]
    virtual void  Update(void);

    // address=[0x14fddd0]
    void  SettlerEnter(int a2);

    // address=[0x15010d0]
    int  DoorX(void)const;

    // address=[0x15010f0]
    int  DoorY(void)const;

    // address=[0x15670e0]
    void  InhabitantFlee(int a2);

    // address=[0x3d8b090]
    static unsigned long m_iClassID;

protected:
    // address=[0x15063e0]
    void  DetachAllNonePileObservers(void);

    // address=[0x1506610]
    void  NotifyAllObservers(class CEntityEvent const & a2)const;

    // address=[0x1506640]
    void  NotifyAndDetachAllObservers(class CEntityEvent const & a2);

private:
    // address=[0x14e9db0]
    void  CorrectBuildingBits(void);

    // address=[0x14e9e40]
     CBuilding(int a2, int a3, int a4, int a5, class std::auto_ptr<class IBuildingRole> a6, int a7);

    // address=[0x14ea0f0]
    virtual  ~CBuilding(void);

    // address=[0x14ea130]
    void  Ready(void);

    // address=[0x14ea320]
    void  RemoveBuildingBits(void);

    // address=[0x14eb340]
    virtual void  ConvertEventIntoGoal(class CEntityEvent * a2);

    // address=[0x14eb3e0]
    void  DetachWithoutNotify(int a2);

};


#endif // CBUILDING_H
