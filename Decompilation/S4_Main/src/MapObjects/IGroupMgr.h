#ifndef IGROUPMGR_H
#define IGROUPMGR_H

#include "defines.h"
#include "../LoadSave/IS4ChunkObject.h"

class IGroupMgr : public IS4ChunkObject
{
public:
    // address=[0x1550a40]
    static void __cdecl FillGroupSideBar(class CInfoExchange *a1, bool a2, int a3);

    // address=[0x1550a60]
    static void __cdecl FillMagicSideBar(class CInfoExchange *a1, bool a2, int a3);

    // address=[0x15525e0]
    IGroupMgr(void) = default;

    virtual int GetGroupSize(int, int) const = 0;
    virtual unsigned short const *GetGroupEntityIds(int, int) const = 0;
    virtual bool AttachEntity(int, int, int) = 0;
    virtual bool DetachEntity(int, int, int) = 0;
    virtual void DetachEntityFromAllGroups(int) = 0;
    virtual void DetachAllEntitiesFromGroup(int, int) = 0;
    virtual bool HasSquadLeader(int, int) = 0;
    virtual void SendGroupCommand(int, unsigned short const *, int, int, int) = 0;
};

#endif // IGROUPMGR_H
