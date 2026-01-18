#ifndef CMAPOBJECTMGR_H
#define CMAPOBJECTMGR_H

#include "defines.h"

class CMapObjectMgr {
public:
    // address=[0x12fd030]
    static class IEntity * __cdecl EntityPtr(int a1);

    // address=[0x12fd860]
    static bool __cdecl ValidEntityId(int a1);

    // address=[0x13094c0]
    static class IEntity & __cdecl Entity(int a1);

    // address=[0x13096b0]
    static bool __cdecl ValidUsedEntityId(int a1);

    // address=[0x130ee70]
    static int __cdecl GetUniqueId(int a1);

    // address=[0x130f140]
    static class IMovingEntity & __cdecl MovingEntity(int a1);

    // address=[0x1439c10]
    static int __cdecl LastUsedId(void);

    // address=[0x14aaa30]
    static unsigned int __cdecl CRCLogicUpdate(void);

    // address=[0x15560f0]
     CMapObjectMgr(void);

    // address=[0x1556330]
     ~CMapObjectMgr(void);

    // address=[0x15564b0]
    static int __cdecl GetFreeSlot(void);

    // address=[0x1556580]
    static void __cdecl RegisterEntity(int a1, class IEntity * pEntity, bool a3);

    // address=[0x1556710]
    static void __cdecl AssignNewUniqueId(int a1);

    // address=[0x1556760]
    void  Kill(int entityId, int attacker);

    // address=[0x1556b00]
    void  Destroy(int a2);

    // address=[0x1556cb0]
    void  LogicUpdate(void);

    // address=[0x15571c0]
    int  RegisterForLogicUpdate(int a2, int a3);

    // address=[0x1557350]
    void  UnRegisterFromLogicUpdate(int a2, int a3);

    // address=[0x15574c0]
    void  Store(class S4::CMapFile &);

    // address=[0x1557910]
    void  Load(class S4::CMapFile &);

    // address=[0x1557c60]
    void  PrintEntity(int entityId, int logLevel, char const * customMessage);

    // address=[0x1557d40]
    void  DbgPrintEntity(int a2, int a3, char const * a4);

    // address=[0x1557d70]
    void  PrintAllEntities(int a2);

    // address=[0x15582e0]
    void  DbgPrintAllEntities(int a2);

    // address=[0x1558cb0]
    struct SGfxObjectInfo *  GetGfxInfo(int a2, int a3);

private:
    // address=[0x3d8bba4]
    static int m_iMinFreeId;

    // address=[0x3d8bba8]
    static int m_iCurrentUniqueId;

    // address=[0x3d8bbac]
    static unsigned int m_uCRCLogicUpdate;

    // address=[0x4105380]
    static int m_iLastUsedId;

    // address=[0x4105384]
    static int m_iMaxLastUsedId;

    // address=[0x4105388]
    static class IEntity * * m_vEntities;

};


#endif // CMAPOBJECTMGR_H
