#ifndef CPILE_H
#define CPILE_H

#include "defines.h"

class CPile : public IAnimatedEntity {
public:
    // address=[0x12fd290]
    bool  GoodAvailable(void)const;

    // address=[0x1401580]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1439a40]
    int  AmountComing(void)const;

    // address=[0x1470870]
    int  AmountLeaving(void)const;

    // address=[0x14708e0]
    bool  ChangeGoodTypeUnforseen(int a2);

    // address=[0x14e8150]
    bool  IsPatchPile(void)const;

    // address=[0x14e8190]
    int  NumberOfAvailableGoods(void)const;

    // address=[0x151fa90]
    int  GetRoleType(void)const;

    // address=[0x151fab0]
    class IPileRole &  Role(void);

    // address=[0x151fad0]
    void  SetGoodType(int a2);

    // address=[0x152f210]
    bool  HasSpace(void)const;

    // address=[0x155b300]
    void  OfferCompletePileIfPossible(int a2);

    // address=[0x155b340]
    void  SetOfferFlag(bool a2);

    // address=[0x155b360]
    void  SetRoleType(int a2);

    // address=[0x155b7d0]
    int  GetBuildingId(void)const;

    // address=[0x155b820]
    bool  GetOfferFlag(void)const;

    // address=[0x155b840]
    bool  IsInOfferList(void)const;

    // address=[0x155bda0]
    virtual void  Delete(void);

    // address=[0x155bed0]
    virtual void  LogicUpdate(void);

    // address=[0x155bf10]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x155bfa0]
    void  GetPatchGfx(struct SGfxPatchObject & a2);

    // address=[0x155c030]
    void  ChangeRole(int a2);

    // address=[0x155c130]
    int  IncreaseUnforeseen(int a2);

    // address=[0x155c2a0]
    void  DecreaseUnforeseen(int a2);

    // address=[0x155c430]
    bool  ForceAmountLeaving(int a2, int a3);

    // address=[0x155c580]
    void  SetBuildingId(int a2);

    // address=[0x155c640]
    void  Occupied(int a2);

    // address=[0x155c700]
    bool  SetFree(int a2);

    // address=[0x155c780]
    void  NotifyChangeEcoSector(int a2, int a3);

    // address=[0x155c860]
    void  Offer(int a2, int a3);

    // address=[0x155c8e0]
    void  CancelOffer(int a2, int a3);

    // address=[0x155c960]
    void  CancelCompleteOfferIfInOfferList(int a2);

    // address=[0x155c990]
    void  ChangeNumberOfOfferedGoodsInEcoSector(int a2, int a3);

    // address=[0x155c9a0]
    int  CalcUrgent(void)const;

    // address=[0x155c9d0]
    void  NotifyTargetDieAndDetachAllObservers(void);

    // address=[0x155cab0]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x155cad0]
    static void __cdecl operator delete(void * a1);

    // address=[0x155cb10]
    virtual void  Detach(int a2);

    // address=[0x155cb80]
    void  ChangeAmountAndDetach(int a2);

    // address=[0x155cbf0]
    void  AttachAndIncAmountLeaving(int a2, int a3, enum T_OBSERVER_TARGET a4);

    // address=[0x155cc90]
    void  AttachAndIncAmountComing(int a2);

    // address=[0x155ccd0]
    virtual void  Notify(class CEntityEvent const & a2)const;

    // address=[0x155ccf0]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET a2, int a3);

    // address=[0x155ce70]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET a2);

    // address=[0x155ce90]
    void  RequestSpaceIfPossible(void);

    // address=[0x155d7c0]
     CPile(std::istream & a2);

    // address=[0x155d9a0]
    virtual void  Store(std::ostream & a2);

    // address=[0x155e770]
    virtual int  Amount(void)const;

    // address=[0x155e790]
    virtual unsigned long  ClassID(void)const;

    // address=[0x155e7d0]
    virtual int  GetGoodType(void)const;

    // address=[0x15604c0]
    void  ReassessDistance(int & a2);

    // address=[0x15615b0]
    int  BuildingId(void)const;

    // address=[0x3d8bbc0]
    static unsigned long m_iClassID;

protected:
    // address=[0x155cef0]
    void  IncreaseEx(int a2);

    // address=[0x155d180]
    void  DecreaseEx(int a2);

    // address=[0x155d370]
    virtual int  Increase(int a2);

    // address=[0x155d3a0]
    virtual void  Decrease(int a2);

    // address=[0x155d3d0]
    void  IncAmountLeaving(int a2);

    // address=[0x155d480]
    void  DecAmountLeaving(int a2);

    // address=[0x155d540]
    void  IncAmountComing(void);

    // address=[0x155d5b0]
    void  DecAmountComing(void);

    // address=[0x155d620]
    void  AdjustStatistic(int a2, int a3);

    // address=[0x155d720]
    bool  ExecuteChangeGoodTypeUnforseen(int a2);

private:
    // address=[0x155dae0]
     CPile(int a2, int a3, int a4, int a5, class std::auto_ptr<class IPileRole> a6, int a7, int a8, int a9, int a10, int a11);

    // address=[0x155dcc0]
    virtual  ~CPile(void);

    // address=[0x155dcf0]
    virtual void  ConvertEventIntoGoal(class CEntityEvent * a2);

};


#endif // CPILE_H
