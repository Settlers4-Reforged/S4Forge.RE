#ifndef CGROUPMGR_H
#define CGROUPMGR_H

#include "defines.h"
#include "Collections/TStaticArray.h"
#include "IGroupMgr.h"
#include "Defines/Players.h"

extern class CGroupMgr *g_pGroupMgr;

class CGroupMgr : public IGroupMgr {
public:
    // address=[0x1550a80]
    virtual void Clear(void);

    // address=[0x1550af0]
    virtual int GetGroupSize(int playerId, int groupId) const;

    // address=[0x1550b80]
    virtual unsigned short const *GetGroupEntityIds(int playerId, int groupId) const;

    // address=[0x1550c10]
    virtual bool AttachEntity(int playerId, int groupId, int entityIdToAttach);

    // address=[0x1550ec0]
    virtual bool DetachEntity(int playerId, int groupId, int entityId);

    // address=[0x1551170]
    virtual void DetachEntityFromAllGroups(int entityId);

    // address=[0x1551270]
    virtual void DetachAllEntitiesFromGroup(int playerId, int groupId);

    // address=[0x15513f0]
    virtual bool HasSquadLeader(int a2, int a3);

    // address=[0x1551490]
    virtual void SendGroupCommand(int groupSize, unsigned short const *group, int x, int y, int sendFlags);

    // address=[0x1551850]
    virtual void Load(class IS4Chunk &a2);

    // address=[0x15519a0]
    virtual void Save(class IS4Chunk &a2);

    // address=[0x1551ae0]
    void FillGroupSideBarEx(class CInfoExchange *a2, bool a3, int a4);

    // address=[0x1551d50]
    void FillMagicSideBarEx(class CInfoExchange *a1, bool a2, int a3);

    // address=[0x1552590]
    CGroupMgr(void);

    // Type information members
private:
    static const int MAX_GROUP_SIZE = 100;
    static const int MAX_GROUPS_PER_PLAYER = 11;
    static const int MAX_GROUPS = MAX_GROUPS_PER_PLAYER * MAX_PLAYERS; // 99


    static const int GROUP_FIRST = 1;
    static const int GROUP_LAST = MAX_GROUPS_PER_PLAYER - 1;

    BYTE                                         m_bGroupFlags[MAX_GROUPS];
    TStaticArray<unsigned short, MAX_GROUP_SIZE> m_vEntries[MAX_GROUPS];
};


#endif // CGROUPMGR_H
