#ifndef ISETTLERROLE_H
#define ISETTLERROLE_H

#include "Defines/Roles.h"
#include "LoadSave/CPersistence.h"
#include "defines.h"

class ISettlerRole : public CPersistence {
  public:
    // address=[0x1351b50]
    int GetTask(void) const;

    // address=[0x1563710]
    virtual ~ISettlerRole(void);

    // address=[0x15637d0]
    virtual int ClearGroupFlagBits(int a2);

    // address=[0x15637f0]
    virtual int Decrease(int a2);

    // address=[0x1563810]
    virtual int GetGroupFlags(void) const;

    // address=[0x1563840]
    virtual class CWarriorBehavior *GetWarriorBehavior(void);

    // address=[0x1563850]
    int HomeEntityId(void) const;

    // address=[0x1563930]
    virtual bool IsUnEmployed(void) const;

    // address=[0x1563940]
    virtual void SetBuilding(int a2);

    // address=[0x15639a0]
    virtual void SetEntity(int a2);

    // address=[0x15639e0]
    virtual int SetGroupFlagBits(int a2);

    // address=[0x1563a00]
    virtual int SetGroupFlags(int a2);

    // address=[0x1563a20]
    virtual void UpdateJob(class CSettler *a2);

    // address=[0x15671a0]
    int SourcePileId(void) const;

    // address=[0x15897e0]
    ISettlerRole(void);

    // address=[0x15898a0]
    virtual void Go(class CSettler *pSettler);

    // address=[0x15899a0]
    virtual void LogicUpdate(class CSettler *_pSettler);

    // address=[0x1589b30]
    void Update(class CSettler *_pSettler);

    // address=[0x1589e30]
    void NewDestination(class CSettler *_pSettler, int _iXY, int a4);

    // address=[0x1589e60]
    void NewDestination(class CSettler *_pSettler, int _iX, int _iY, int a5);

    // address=[0x1589ea0]
    bool SearchPosition(class CSettler *_pSettler, int _iSearchIndex);

    // address=[0x158a0a0]
    virtual bool ESChanged(class CSettler *_pSettler);

    // address=[0x158a230]
    virtual bool SetFree(class CSettler *_pSettler, int a3);

    // address=[0x158a4d0]
    virtual void SetObserverTarget(T_OBSERVER_TARGET observerTargetType, int target);

    // address=[0x158a530]
    virtual int GetObserverTarget(T_OBSERVER_TARGET a2);

    // address=[0x158a570]
    ISettlerRole(std::istream &_rStream);

    // address=[0x158a740]
    virtual void Store(std::ostream &_rStream);

    // address=[0x158a8d0]
    virtual int GetKindOfSelection(class CSettler *a2) const;

    virtual void PostLoadInit(class CSettler *a1) = 0;
    virtual class CWalking *InitWalking(class CSettler *a2) = 0;
    virtual void LogicUpdateJob(class CSettler *a2) = 0;
    virtual int GetSettlerRole(void) const = 0;

  protected:
    // address=[0x158a8f0]
    void MarkPileAsUnused(enum T_OBSERVER_TARGET _tObserverTarget);

    // address=[0x158a9c0]
    void DetachFromPile(class CSettler *a2, enum T_OBSERVER_TARGET a3, bool a4);

    // address=[0x158ab30]
    virtual int GetNextSettlerType(void);

    // address=[0x158ab40]
    virtual bool SetNextSettlerType(int a2);

    // address=[0x158ab50]
    int SettlerWalk(class CSettler *_pSettler);

    // address=[0x158ab70]
    virtual bool SearchRestingPlace(class CSettler *_pSettler, int _iDistance);

    // address=[0x158aca0]
    virtual bool CheckHome(class CSettler *a2);

    // address=[0x158ace0]
    void InitCommonTaskValues(class CSettler *_pSettler, class CEntityTask const &_rTask);

    // address=[0x158afa0]
    virtual void NewDestinationEx(class CSettler *a2, class std::list<class CEntityTask, class std::allocator<class CEntityTask>> &_rTaskList, int a4, int a5, int a6);

    virtual void GetNextJob(class CSettler *a2) = 0;
    virtual void TakeJob(class CSettler *a2) = 0;
    virtual void Init(class CSettler *a2) = 0;
    virtual void ConvertEventIntoGoal(class CSettler *a2, class CEntityEvent *a3) = 0;

    // Type information members
  public:
    signed char m_iTask;                   // CHAR m_iTask;
    unsigned __int8 m_uSettlerWalk;        // BYTE m_uSettlerWalk;
    signed char m_iWalkspeed;              // char m_iWalkspeed;
    unsigned __int8 m_uCycleFrames;        // unsigned __int8 m_iCycleFrames;
    WORD m_uTick;                          // WORD m_uTick;
    unsigned __int8 m_bForward;            // bool m_bForward;
    unsigned __int8 unk_0B;                // BYTE unk_0B;
    unsigned __int8 m_uToDoCount;          // unsigned __int8 m_uToDoCount;
    __int16 m_iDestinationOffsetX;         //__int16 m_iDestinationOffsetX;
    __int16 m_iDestinationOffsetY;         //__int16 m_iDestinationOffsetY;
    unsigned __int16 m_uAttachedSettlerId; // WORD m_uAttachedSettlerId;
    unsigned __int16 m_uSourcePileId;      // WORD m_uSourcePileId;
    int m_iDestinationPosition;            // int m_iDestinationPosition;
    int m_iStartPosition;                  // int m_iStartPosition;
    unsigned __int16 m_uHomeEntityId;      // WORD m_uHomeEntityId;
    unsigned __int16 m_uEntityId;          // WORD m_uEntityId;
    float m_fOffsetX;                      // float m_fOffsetX;
    float m_fOffsetY;                      // float m_fOffsetY;
};

#endif // ISETTLERROLE_H
