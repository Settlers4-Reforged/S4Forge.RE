#ifndef CGROUPMGR_H
#define CGROUPMGR_H

#include "defines.h"

class CGroupMgr : public IGroupMgr {
public:
    // address=[0x1550a80]
    virtual void  Clear(void);

    // address=[0x1550af0]
    virtual int  GetGroupSize(int playerId, int groupId)const;

    // address=[0x1550b80]
    virtual unsigned short const *  GetGroupEntityIds(int playerId, int groupId)const;

    // address=[0x1550c10]
    virtual bool  AttachEntity(int playerId, int groupId, int entityIdToAttach);

    // address=[0x1550ec0]
    virtual bool  DetachEntity(int playerId, int groupId, int entityId);

    // address=[0x1551170]
    virtual void  DetachEntityFromAllGroups(int entityId);

    // address=[0x1551270]
    virtual void  DetachAllEntitiesFromGroup(int playerId, int groupId);

    // address=[0x15513f0]
    virtual bool  HasSquadLeader(int a2, int a3);

    // address=[0x1551490]
    virtual void  SendGroupCommand(int groupSize, unsigned short const * group, int x, int y, int sendFlags);

    // address=[0x1551850]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x15519a0]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1551ae0]
    void  FillGroupSideBarEx(class CInfoExchange * a2, bool a3, int a4);

    // address=[0x1551d50]
    void  FillMagicSideBarEx(class CInfoExchange * a1, bool a2, int a3);

    // address=[0x1552590]
     CGroupMgr(void);

    // Type information members
private:
    BYTE[100] groupFlags;
    struct CGroupMgr::TStaticArray100short[99] entries;

};


#endif // CGROUPMGR_H
