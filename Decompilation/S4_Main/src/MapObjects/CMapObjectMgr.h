#ifndef CMAPOBJECTMGR_H
#define CMAPOBJECTMGR_H

#include "defines.h"
#include <deque>

#include "LoadSave/CMapFile.h"
#include "IEntity.h"
#include "IMovingEntity.h"

extern class CMapObjectMgr *g_pMapObjectMgr;

class CMapObjectMgr {
public:
    // address=[0x12fd030]
    static IEntity * __cdecl EntityPtr(int a1);

    // address=[0x12fd860]
    static bool __cdecl ValidEntityId(int a1);

    // address=[0x13094c0]
    static IEntity & __cdecl Entity(int a1);

    // address=[0x13096b0]
    static bool __cdecl ValidUsedEntityId(int a1);

    // address=[0x130ee70]
    static int __cdecl GetUniqueId(int a1);

    // address=[0x130f140]
    static IMovingEntity & __cdecl MovingEntity(int _iId);

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
    static void __cdecl RegisterEntity(int _iId, IEntity *_pEntity, bool a3);

    // address=[0x1556710]
    static void __cdecl AssignNewUniqueId(int _iId);

    // address=[0x1556760]
    void Kill(int _iEntityId, int _iAttackerId);

    // address=[0x1556b00]
    void Destroy(int _iEntityId);

    // address=[0x1556cb0]
    void LogicUpdate(void);

    // address=[0x15571c0]
    int RegisterForLogicUpdate(int iDeltaTicks, int _iEntityId);

    // address=[0x1557350]
    void UnRegisterFromLogicUpdate(int slot, int entity);

    // address=[0x15574c0]
    void Store(class S4::CMapFile &a2);

    // address=[0x1557910]
    void Load(class S4::CMapFile &a2);

    // address=[0x1557c60]
    void PrintEntity(int _iEntityId, int _iLogLevel, char const *_sCustomMessage);

    // address=[0x1557d40]
    void DbgPrintEntity(int _iEntityId, int _iLogLevel, char const *_sCustomMessage);

    // address=[0x1557d70]
    void PrintAllEntities(int _iLogLevel);

    // address=[0x15582e0]
    void DbgPrintAllEntities(int a2);

    // address=[0x1558cb0]
    struct SGfxObjectInfo *GetGfxInfo(int _iId, int a3);

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
    static class IEntity * *m_vEntities;


    static const int MAX_ENTRIES = 0xFFFF;
    static const int MAX_LOGIC_UPDATE_SLOTS = 32;
    static const int fileFormatVersion = 1;

    // Type information members
private:
    std::vector<std::deque<unsigned short> > *m_vLogicUpdateSlots;

    DWORD m_iCurrentLogicTick;

    std::vector<std::deque<unsigned short> > *m_vKilledEntities;
};


#endif // CMAPOBJECTMGR_H
