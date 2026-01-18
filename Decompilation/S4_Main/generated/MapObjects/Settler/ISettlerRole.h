#ifndef ISETTLERROLE_H
#define ISETTLERROLE_H

#include "defines.h"

class ISettlerRole : public CPersistence {
public:
    // address=[0x1351b50]
    int  GetTask(void)const;

    // address=[0x1563710]
    virtual  ~ISettlerRole(void);

    // address=[0x15637d0]
    virtual int  ClearGroupFlagBits(int a2);

    // address=[0x15637f0]
    virtual int  Decrease(int a2);

    // address=[0x1563810]
    virtual int  GetGroupFlags(void)const;

    // address=[0x1563840]
    virtual class CWarriorBehavior *  GetWarriorBehavior(void);

    // address=[0x1563850]
    int  HomeEntityId(void)const;

    // address=[0x1563930]
    virtual bool  IsUnEmployed(void)const;

    // address=[0x1563940]
    virtual void  SetBuilding(int a2);

    // address=[0x15639a0]
    virtual void  SetEntity(int a2);

    // address=[0x15639e0]
    virtual int  SetGroupFlagBits(int a2);

    // address=[0x1563a00]
    virtual int  SetGroupFlags(int a2);

    // address=[0x1563a20]
    virtual void  UpdateJob(class CSettler * a2);

    // address=[0x15671a0]
    int  SourcePileId(void)const;

    // address=[0x15897e0]
     ISettlerRole(void);

    // address=[0x15898a0]
    virtual void  Go(class CSettler * settler);

    // address=[0x15899a0]
    virtual void  LogicUpdate(class CSettler * a2);

    // address=[0x1589b30]
    void  Update(class CSettler * a2);

    // address=[0x1589e30]
    void  NewDestination(class CSettler * a2, int a3, int a4);

    // address=[0x1589e60]
    void  NewDestination(class CSettler * a2, int a3, int a4, int a5);

    // address=[0x1589ea0]
    bool  SearchPosition(class CSettler * a2, int a3);

    // address=[0x158a0a0]
    virtual bool  ESChanged(class CSettler * a2);

    // address=[0x158a230]
    virtual bool  SetFree(class CSettler * settler, int a3);

    // address=[0x158a4d0]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET observerTargetType, int target);

    // address=[0x158a530]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET a2);

    // address=[0x158a570]
     ISettlerRole(std::istream & a2);

    // address=[0x158a740]
    virtual void  Store(std::ostream & a2);

    // address=[0x158a8d0]
    virtual int  GetKindOfSelection(class CSettler * a2)const;

protected:
    // address=[0x158a8f0]
    void  MarkPileAsUnused(enum T_OBSERVER_TARGET a2);

    // address=[0x158a9c0]
    void  DetachFromPile(class CSettler * a2, enum T_OBSERVER_TARGET a3, bool a4);

    // address=[0x158ab30]
    virtual int  GetNextSettlerType(void);

    // address=[0x158ab40]
    virtual bool  SetNextSettlerType(int a2);

    // address=[0x158ab50]
    int  SettlerWalk(class CSettler * a2);

    // address=[0x158ab70]
    virtual bool  SearchRestingPlace(class CSettler * a2, int a3);

    // address=[0x158aca0]
    virtual bool  CheckHome(class CSettler * a2);

    // address=[0x158ace0]
    void  InitCommonTaskValues(class CSettler * a2, class CEntityTask const & a3);

    // address=[0x158afa0]
    virtual void  NewDestinationEx(class CSettler * a2, class std::list<class CEntityTask,class std::allocator<class CEntityTask> > & a3, int a4, int a5, int a6);

    // Type information members
private:
    CHAR task;
    BYTE settlerWalk;
    BYTE walkspeed;
    BYTE unk_07;
    WORD unk_08;
    BYTE unk_0A;
    BYTE unk_0B;
    BYTE unk_0C;
    BYTE pad_0D;
    WORD unk_0E;
    WORD unk_10;
    WORD unk_12;
    WORD sourcePileId;
    WORD pad_16;
    DWORD destinationPosition;
    DWORD startPosition;
    WORD homeEntityId;
    WORD entityId;
    WORD unk_24;
    WORD unk_26;
    WORD unk_28;
    WORD unk_2A;
    DWORD unk_2c;
    DWORD unk_30;

};


#endif // ISETTLERROLE_H
