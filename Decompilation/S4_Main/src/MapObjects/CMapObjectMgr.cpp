#include "CMapObjectMgr.h"

#include <string>
#include <sstream>

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "../Debug/IMessageTracer.h"
#include "Debug/CTrace.h"

#include "AI/CAIEntityInfo.h"
#include "MapObjects/Settler/CSettler.h"
#include "MapObjects/IAnimatedEntity.h"
#include "MapObjects/IMovingEntity.h"
#include "Pathing/CWarMap.h"

// Definitions for class CMapObjectMgr

// address=[0x12fd030]
// Decompiled from IEntity *__cdecl CMapObjectMgr::EntityPtr(int a1)
class IEntity *__cdecl CMapObjectMgr::EntityPtr(int a1)
{

  if (!CMapObjectMgr::ValidEntityId(a1) && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\MapObjectMgr.cpp", 212, "ValidEntityId( _iId )") == 1)
    __debugbreak();
  return m_vEntities[a1];
}

// address=[0x12fd860]
// Decompiled from bool __cdecl CMapObjectMgr::ValidEntityId(unsigned int a1)
bool __cdecl CMapObjectMgr::ValidEntityId(int a1)
{

  return a1 <= m_iMaxLastUsedId;
}

// address=[0x13094c0]
// Decompiled from IEntity *__cdecl CMapObjectMgr::Entity(unsigned int a1)
class IEntity &__cdecl CMapObjectMgr::Entity(int a1)
{

  if (!CMapObjectMgr::ValidUsedEntityId(a1) && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\MapObjectMgr.cpp", 228, "ValidUsedEntityId( _iId )") == 1)
    __debugbreak();

  return *m_vEntities[a1];
}

// address=[0x13096b0]
// Decompiled from bool __cdecl CMapObjectMgr::ValidUsedEntityId(unsigned int a1)
bool __cdecl CMapObjectMgr::ValidUsedEntityId(int a1)
{

  return a1 <= m_iLastUsedId && m_vEntities[a1];
}

// address=[0x130ee70]
// Decompiled from int __cdecl CMapObjectMgr::GetUniqueId(unsigned int a1)
int __cdecl CMapObjectMgr::GetUniqueId(int a1)
{

  IEntity *v3; // [esp+4h] [ebp-4h]

  if (!CMapObjectMgr::ValidEntityId(a1) && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\MapObjectMgr.cpp", 257, "ValidEntityId( _iId )") == 1)
    __debugbreak();
  v3 = m_vEntities[a1];
  if (v3)
    return v3->m_iUniqueId;
  else
    return 0;
}

// address=[0x130f140]
// Decompiled from IEntity *__cdecl CMapObjectMgr::MovingEntity(unsigned int _iId)
class IMovingEntity &__cdecl CMapObjectMgr::MovingEntity(int _iId)
{

  if (!CMapObjectMgr::ValidUsedEntityId(_iId) && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\MapObjectMgr.cpp", 246, "ValidUsedEntityId( _iId )") == 1)
  {
    __debugbreak();
  }
  IMovingEntity *v2 = dynamic_cast<IMovingEntity *>(m_vEntities[_iId]);
  if (!v2 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\MapObjectMgr.cpp", 250, "dynamic_cast<IMovingEntity*>( pEntity ) != 0") == 1)
  {
    __debugbreak();
  }
  return *v2;
}

// address=[0x1439c10]
// Decompiled from int CMapObjectMgr::LastUsedId()
int __cdecl CMapObjectMgr::LastUsedId(void)
{
  return m_iLastUsedId;
}

// address=[0x14aaa30]
// Decompiled from int CMapObjectMgr::CRCLogicUpdate()
unsigned int __cdecl CMapObjectMgr::CRCLogicUpdate(void)
{
  return m_uCRCLogicUpdate;
}

// address=[0x15560f0]
// Decompiled from CMapObjectMgr *__thiscall CMapObjectMgr::CMapObjectMgr(CMapObjectMgr *this)
CMapObjectMgr::CMapObjectMgr(void)
{
  int iFreeSlot; // eax
  CSettler *v8;  // [esp+20h] [ebp-3Ch]
  CSettler *v9;  // [esp+28h] [ebp-34h]
  CSettler *v10; // [esp+30h] [ebp-2Ch]
  CSettler *v11; // [esp+38h] [ebp-24h]
  CSettler *v12; // [esp+40h] [ebp-1Ch]
  CSettler *v13; // [esp+48h] [ebp-14h]

  this->m_vLogicUpdateSlots = new std::vector<std::deque<unsigned short>>();
  this->m_vKilledEntities = new std::vector<std::deque<unsigned short>>();
  memset(m_vEntities, 0, sizeof(IEntity*) * (MAX_ENTRIES + 1));
  m_iMinFreeId = 1;
  m_iLastUsedId = 0;
  m_iMaxLastUsedId = 0;
  m_iCurrentUniqueId = 1;

  // TODO: find out what these settlers are for...
  iFreeSlot = CMapObjectMgr::GetFreeSlot();
  new CSettler(0x44, iFreeSlot);
  iFreeSlot = CMapObjectMgr::GetFreeSlot();
  new CSettler(0x44, iFreeSlot);
  iFreeSlot = CMapObjectMgr::GetFreeSlot();
  new CSettler(0x44, iFreeSlot);
  iFreeSlot = CMapObjectMgr::GetFreeSlot();
  new CSettler(0x44, iFreeSlot);
  iFreeSlot = CMapObjectMgr::GetFreeSlot();
  new CSettler(0x44, iFreeSlot);
  iFreeSlot = CMapObjectMgr::GetFreeSlot();
  new CSettler(0x44, iFreeSlot);

  this->m_vLogicUpdateSlots->resize(MAX_LOGIC_UPDATE_SLOTS);
  this->m_iCurrentLogicTick = 0;
  this->m_vKilledEntities->resize(MAX_LOGIC_UPDATE_SLOTS);
  m_uCRCLogicUpdate = 1;
}

// address=[0x1556330]
// Decompiled from int __thiscall CMapObjectMgr::~CMapObjectMgr(CMapObjectMgr *this)
CMapObjectMgr::~CMapObjectMgr(void)
{
  if (m_vEntities[0] && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 114, "m_vEntities[0] == 0") == 1)
  {
    __debugbreak();
  }
  m_vEntities[0] = 0;
  for (int i = 1; i < MAX_ENTRIES; ++i)
  {
    if (m_vEntities[i])
    { // delete[] m_vEntities
      delete m_vEntities[i];
      m_vEntities[i] = 0;
    }
  }
  if (m_vEntities[MAX_ENTRIES] && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 132, "m_vEntities[MAX_ENTRIES] == 0") == 1)
  {
    __debugbreak();
  }
  m_vEntities[MAX_ENTRIES] = 0;
  this->m_vLogicUpdateSlots->clear();
  this->m_vKilledEntities->clear();
  m_iMinFreeId = 1;
  m_iLastUsedId = 0;
  m_iMaxLastUsedId = 0;
  m_iCurrentUniqueId = 1;
  delete this->m_vLogicUpdateSlots;
  delete this->m_vKilledEntities;
}

// address=[0x15564b0]
// Decompiled from int CMapObjectMgr::GetFreeSlot()
int __cdecl CMapObjectMgr::GetFreeSlot(void)
{
  int i; // [esp+8h] [ebp-4h]

  if ((m_iMinFreeId < 1 || m_iMinFreeId > MAX_ENTRIES) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 328, "m_iMinFreeId >= 1 && m_iMinFreeId <= MAX_ENTRIES") == 1)
  {
    __debugbreak();
  }
  for (i = m_iMinFreeId; i < MAX_ENTRIES; ++i)
  {
    if (!m_vEntities[i])
    {
      m_iMinFreeId = i;
      g_pMsgTracer->PushFormatedInts("CMapObjectMgr::GetFreeSlot(): New free slot %i", (char *)i);
      return i;
    }
  }
  m_iMinFreeId = MAX_ENTRIES;
  g_pMsgTracer->PushStaticText("CMapObjectMgr::GetFreeSlot(): No new free slot");
  return -1;
}

// address=[0x1556580]
// Decompiled from void __cdecl CMapObjectMgr::RegisterEntity(int _iId, struct IEntity *_pEntity, bool a3)
void __cdecl CMapObjectMgr::RegisterEntity(int _iId, class IEntity *_pEntity, bool a3)
{

  if (!_pEntity && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 381, "_pEntity != NULL") == 1)
    __debugbreak();
  if ((_iId <= 0 || _iId >= MAX_ENTRIES) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 382, "_iId>0 && _iId<MAX_ENTRIES") == 1)
  {
    __debugbreak();
  }
  if (m_vEntities[_iId] && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 383, "m_vEntities[ _iId ] == NULL") == 1)
  {
    __debugbreak();
  }
  if (a3)
  {
    if (_pEntity->m_iUniqueId != -1 && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 389, "_pEntity->m_iUniqueId == -1") == 1)
    {
      __debugbreak();
    }
    if (m_iCurrentUniqueId <= 0 && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 390, "m_iCurrentUniqueId > 0") == 1)
    {
      __debugbreak();
    }
    if ((m_iCurrentUniqueId & 0x20000000) != 0 && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 391, "(m_iCurrentUniqueId & IEntity::UNIQUE_ID_DEAD_ENTITY_BIT) == 0") == 1)
    {
      __debugbreak();
    }
    _pEntity->m_iUniqueId = m_iCurrentUniqueId++;
  }
  else if (_pEntity->m_iUniqueId <= 0 && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 397, "_pEntity->m_iUniqueId > 0") == 1)
  {
    __debugbreak();
  }
  if (_iId > m_iLastUsedId)
  {
    m_iLastUsedId = _iId;
    if (_iId > m_iMaxLastUsedId)
      m_iMaxLastUsedId = _iId;
  }
  m_vEntities[_iId] = _pEntity;
}

// address=[0x1556710]
// Decompiled from void __cdecl CMapObjectMgr::AssignNewUniqueId(int _iId)
void __cdecl CMapObjectMgr::AssignNewUniqueId(int _iId)
{

  IEntity *v1; // [esp+0h] [ebp-4h]

  if (_iId > 0 && _iId < MAX_ENTRIES)
  {
    v1 = m_vEntities[_iId];
    if (v1)
    {
      if ((v1->m_iUniqueId & 0x20000000) == 0)
        v1->m_iUniqueId = m_iCurrentUniqueId++;
    }
  }
}

// address=[0x1556760]
// Decompiled from void __thiscall CMapObjectMgr::Kill(CMapObjectMgr *this, int _iEntityId, int _iAttackerId)
void CMapObjectMgr::Kill(int _iEntityId, int _iAttackerId)
{

  int v3;                           // eax
  int v5;                           // [esp-Ch] [ebp-38h]
  int type;                         // [esp-8h] [ebp-34h] MAPDST
  DWORD tick;                       // [esp+0h] [ebp-2Ch]
  int ownerId;                      // [esp+14h] [ebp-18h]
  IAnimatedEntity *pAnimatedEntity; // [esp+18h] [ebp-14h]
  int objType;                      // [esp+1Ch] [ebp-10h]
  IEntity *entity;                  // [esp+24h] [ebp-8h]
  __int16 v15;                      // [esp+2Ah] [ebp-2h] BYREF

  if ((_iEntityId <= 0 || _iEntityId >= MAX_ENTRIES) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 449, "_iEntityId>0 && _iEntityId<MAX_ENTRIES") == 1)
  {
    __debugbreak();
  }
  if (!m_vEntities[_iEntityId] && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 450, "m_vEntities[ _iEntityId ] != 0") == 1)
  {
    __debugbreak();
  }
  entity = m_vEntities[_iEntityId];
  type = entity->Type();
  v5 = entity->ObjType();
  g_pMsgTracer->PushFormatedInts(

      "CMapObjectMgr::Kill(): id %u, type %u / %u, attacker %i",
      _iEntityId,
      v5,
      type,
      (char *)_iAttackerId);

  if ((entity->m_iUniqueId & 0x20000000) != 0)
  {
    if (entity->FlagBits(EntityFlag_AliveMask) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 460, "pEntity->FlagBits(ENTITY_FLAG_ALIVE_MASK) == 0") == 1)
    {
      __debugbreak();
    }
    if (!entity->FlagBits(EntityFlag_Died) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 461, "pEntity->FlagBits(ENTITY_FLAG_DIED) != 0") == 1)
    {
      __debugbreak();
    }
  }
  else
  {
    entity->m_iUniqueId |= 0x20000000u;
    if (entity->FlagBits(EntityFlag_Died) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 468, "pEntity->FlagBits(ENTITY_FLAG_DIED) == 0") == 1)
    {
      __debugbreak();
    }
    if (entity->FlagBits(EntityFlag_Birth))
      entity->SetFlagBits((EntityFlag)0x100000);
    else
      entity->ClearFlagBits((EntityFlag)0x100000);
    entity->ClearFlagBits(EntityFlag_AliveMask);
    entity->SetFlagBits(EntityFlag_Died);
    if (entity->m_warMapNode.IsInWarMap())
      CWarMap::RemoveEntity(*entity);
    if (entity->FlagBits(EntityFlag_Selected) || entity->FlagBits((EntityFlag)1024))
    {
      v3 = entity->ID();
      g_cInputProcessor->DeSelectEntity(v3);
    }
    if (entity->GetGroupFlags())
      g_pGroupMgr->DetachEntityFromAllGroups(_iEntityId);
    if (_iAttackerId > 0)
    {
      ownerId = entity->OwnerId();
      objType = entity->ObjType();
      type = entity->Type();
      if (objType == 1)
      {
        g_cStatistic->IncKillsOfType(_iAttackerId, type);
        g_cStatistic->IncLossesOfType(ownerId, type);
      }
      if (objType == 2 || objType == 4)
      {
        g_cStatistic->IncKillsVehicleOfType(_iAttackerId, type);
        g_cStatistic->IncLossesVehicleOfType(ownerId, type);
      }
    }
    if (entity->m_psAIEntityInfo)
    {
      CAIEntityInfo *psAIEntityInfo = entity->m_psAIEntityInfo;
      if (psAIEntityInfo)
        delete psAIEntityInfo;
      entity->m_psAIEntityInfo = 0;
    }
    entity->Delete();
    pAnimatedEntity = dynamic_cast<IAnimatedEntity *>(entity);
    if (pAnimatedEntity)
    {
      if (pAnimatedEntity->Previous() && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 548, "pAnimatedEntity->Previous() == 0") == 1)
      {
        __debugbreak();
      }
      if (pAnimatedEntity->Next() && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 549, "pAnimatedEntity->Next() == 0") == 1)
      {
        __debugbreak();
      }
    }
    tick = (this->m_iCurrentLogicTick + 31) % 0x20;
    auto &v4 = this->m_vKilledEntities->at(tick);
    v4.push_front(static_cast<unsigned short>(_iEntityId));
  }
}

// address=[0x1556b00]
// Decompiled from void __thiscall CMapObjectMgr::Destroy(CMapObjectMgr *this, int _iEntityId)
void CMapObjectMgr::Destroy(int _iEntityId)
{

  IEntity *v2; // [esp+14h] [ebp-Ch]
  int i;       // [esp+1Ch] [ebp-4h]

  if ((_iEntityId <= 0 || _iEntityId >= MAX_ENTRIES) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 566, "_iEntityId>0 && _iEntityId<MAX_ENTRIES") == 1)
  {
    __debugbreak();
  }
  if (!m_vEntities[_iEntityId] && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 567, "m_vEntities[ _iEntityId ] != 0") == 1)
  {
    __debugbreak();
  }
  v2 = m_vEntities[_iEntityId];
  if (v2->m_nEntityId != _iEntityId && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 571, "pEntity->m_uID == _iEntityId") == 1)
  {
    __debugbreak();
  }
  if (v2)
    delete v2;
  m_vEntities[_iEntityId] = 0;
  if (_iEntityId < m_iMinFreeId)
    m_iMinFreeId = _iEntityId;
  if (m_iLastUsedId < 0 && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 582, "m_iLastUsedId >= 0") == 1)
  {
    __debugbreak();
  }
  if (m_vEntities[0] && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 583, "m_vEntities[0] == 0") == 1)
  {
    __debugbreak();
  }
  for (i = m_iLastUsedId; m_vEntities[i] == 0 && i > 0; --i)
    ;
  m_iLastUsedId = i;
}

// address=[0x1556cb0]
// Decompiled from void __thiscall CMapObjectMgr::LogicUpdate(CMapObjectMgr *this)
void CMapObjectMgr::LogicUpdate(void)
{
  int v13;      // [esp+30h] [ebp-8ACh]
  int i;        // [esp+34h] [ebp-8A8h]
  int k;        // [esp+3Ch] [ebp-8A0h]
  int j;        // [esp+40h] [ebp-89Ch]
  signed int m; // [esp+44h] [ebp-898h]
  int v20;      // [esp+4Ch] [ebp-890h]

  std::deque<unsigned short> &qLogicQueue = this->m_vLogicUpdateSlots->at(this->m_iCurrentLogicTick);
  int crc1 = m_uCRCLogicUpdate;
  int crc2 = m_uCRCLogicUpdate;
  int crc3 = m_uCRCLogicUpdate;
  if (qLogicQueue.size())
  {
    int currentQueueSize = qLogicQueue.size();

    unsigned short aQueuedEntityList[1024];
    v20 = 0;
    for (i = 0; i < currentQueueSize / 1024; ++i)
    {
      for (j = 0; j < 1024; ++j)
        aQueuedEntityList[j] = qLogicQueue[v20++];
      m_uCRCLogicUpdate = Adler32(aQueuedEntityList, 0x800u, m_uCRCLogicUpdate);
    }
    crc2 = m_uCRCLogicUpdate;
    v13 = currentQueueSize % 1024;
    if (currentQueueSize % 1024 > 0)
    {
      for (k = 0; k < v13; ++k)
        aQueuedEntityList[k] = qLogicQueue[v20++];
      m_uCRCLogicUpdate = Adler32(aQueuedEntityList, 2 * v13, m_uCRCLogicUpdate);
    }
    crc3 = m_uCRCLogicUpdate;
  }

  int aLogicQueueSizes[MAX_LOGIC_UPDATE_SLOTS];
  for (m = 0; m < MAX_LOGIC_UPDATE_SLOTS; ++m)
  {
    std::deque<unsigned short> &queue = this->m_vLogicUpdateSlots->at(m);
    aLogicQueueSizes[m] = queue.size();
  }

  m_uCRCLogicUpdate = Adler32(aLogicQueueSizes, 0x80u, m_uCRCLogicUpdate);
  unsigned short queueSize = qLogicQueue.size();
  g_pMsgTracer->PushFormatedInts(
      "CMapObjectMgr::LogicUpdate(): size %u, CRCs 0x%08x, 0x%08x, 0x%08x, 0x%08x",
      queueSize,
      crc1,
      crc2,
      crc3,
      m_uCRCLogicUpdate);
  while (!qLogicQueue.empty())
  {
    int iEntity = qLogicQueue.front();
    if ((qLogicQueue.empty() || qLogicQueue.front() != 0) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 781, "q.empty() == false && 0 != q.front()") == 1)
    {
      __debugbreak();
    }
    qLogicQueue.pop_front();
    IEntity *pEntity = CMapObjectMgr::EntityPtr(iEntity);
    if (pEntity)
    {
      if (pEntity->ID() != iEntity && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 795, "pEntity->ID() == iEntityId") == 1)
      {
        __debugbreak();
      }

      IAnimatedEntity *pAnimatedEntity = dynamic_cast<IAnimatedEntity *>(pEntity);
      if (!pAnimatedEntity &&
          BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 796, "dynamic_cast<IAnimatedEntity*>(pEntity) != 0") == 1)
      {
        __debugbreak();
      }
      pAnimatedEntity->ClearFlagBits(EntityFlag_Registered);
      int type = pAnimatedEntity->Type();
      int objType = pAnimatedEntity->ObjType();
      g_pMsgTracer->PushFormatedInts("LogicUpdate(): id %u, type %u / %u", iEntity, objType, type);
      pAnimatedEntity->LogicUpdate();
    }
    else
    {
      BBSupportTracePrintF(
          3,
          "### CMapObjectMgr::LogicUpdate(): EntityPtr for entity id %i in list %i is NULL! ###",
          iEntity,
          this->m_iCurrentLogicTick);
    }
  }

  std::deque<unsigned short> &killedEntitiesQueue = this->m_vKilledEntities->at(this->m_iCurrentLogicTick);
  while (!killedEntitiesQueue.empty())
  {
    unsigned short iEntityIdToKill = killedEntitiesQueue.front();
    killedEntitiesQueue.pop_front();
    this->Destroy(iEntityIdToKill);
  }

  int nextTick = this->m_iCurrentLogicTick + 1;
  this->m_iCurrentLogicTick = nextTick % MAX_LOGIC_UPDATE_SLOTS;
}

// address=[0x15571c0]
// Decompiled from int __thiscall CMapObjectMgr::RegisterForLogicUpdate(CMapObjectMgr *this, int iDeltaTicks, int _iEntityId)
int CMapObjectMgr::RegisterForLogicUpdate(int iDeltaTicks, int _iEntityId)
{

  int v3;                   // eax
  int v9;                   // [esp-8h] [ebp-1Ch]
  DWORD logicUpdateSlot;    // [esp+4h] [ebp-10h]
  IAnimatedEntity *pEntity; // [esp+Ch] [ebp-8h]

  if ((iDeltaTicks <= 0 || iDeltaTicks >= MAX_LOGIC_UPDATE_SLOTS) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 847, "(0 < _iDeltaTicks) && (_iDeltaTicks < MAX_LOGIC_UPDATE_SLOTS)") == 1)
  {
    __debugbreak();
  }

  if (iDeltaTicks > 0)
  {
    if (iDeltaTicks >= 32)
      iDeltaTicks = 31;
  }
  else
  {
    iDeltaTicks = 1;
  }

  logicUpdateSlot = (iDeltaTicks + this->m_iCurrentLogicTick) % MAX_LOGIC_UPDATE_SLOTS;
  pEntity = (IAnimatedEntity *)CMapObjectMgr::EntityPtr(_iEntityId);
  if (g_pMsgTracer->RemoveCurrentMsgIfEqual(
          (const char **)"LogicUpdate(): id %u, type %u / %u",
          (const char *)_iEntityId))
  {
    g_pMsgTracer->PushFormatedInts(

        "LogicUpdate() + RegisterForLogicUpdate(): id %u, type %u / %u, delta ticks %u",
        _iEntityId,
        pEntity->ObjType(),
        pEntity->Type(),
        (char *)iDeltaTicks);
  }
  else
  {
    g_pMsgTracer->PushFormatedInts(

        "RegisterForLogicUpdate(): id %u, type %u / %u, delta ticks %u",
        _iEntityId,
        pEntity->ObjType(),
        pEntity->Type(),
        (char *)iDeltaTicks);
  }
  if (pEntity->FlagBits(EntityFlag_Died) && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 874, "pEntity->FlagBits(ENTITY_FLAG_DIED) == 0") == 1)
  {
    __debugbreak();
  }
  if (pEntity->GetLastLogicUpdateTick() != -1 && pEntity->GetLastLogicUpdateTick() != this->m_iCurrentLogicTick)
  {
    this->UnRegisterFromLogicUpdate(pEntity->GetLastLogicUpdateTick(), _iEntityId);
  }

  std::deque<unsigned short> &updateQueue = this->m_vLogicUpdateSlots->at(logicUpdateSlot);
  updateQueue.push_front(_iEntityId);
  pEntity->SetFlagBits(EntityFlag_Registered);

  return logicUpdateSlot;
}

// address=[0x1557350]
// Decompiled from void __thiscall CMapObjectMgr::UnRegisterFromLogicUpdate(CMapObjectMgr *this, unsigned int slot, int entity)
void CMapObjectMgr::UnRegisterFromLogicUpdate(int slot, int entity)
{

  char v3;                    // [esp-Ch] [ebp-70h] BYREF
  int v4;                     // [esp-8h] [ebp-6Ch]
  int v5;                     // [esp-4h] [ebp-68h]
  int v10;                    // [esp+34h] [ebp-30h]
  int v11;                    // [esp+38h] [ebp-2Ch]
  char *v12;                  // [esp+3Ch] [ebp-28h]
  IEntity *v13;               // [esp+40h] [ebp-24h]
  int v14;                    // [esp+44h] [ebp-20h]
  std::_Iterator_base12 *v15; // [esp+48h] [ebp-1Ch]
  std::_Iterator_base12 *v16; // [esp+4Ch] [ebp-18h]
  char v18;                   // [esp+57h] [ebp-Dh]
  int exceptionBlock;         // [esp+60h] [ebp-4h]

  if (slot < 0x20)
  {
    std::deque<unsigned short> &updateQueue = this->m_vLogicUpdateSlots->at(slot);

    for (auto it = updateQueue.begin(); it != updateQueue.end();)
    {
      if (*it == entity)
      {
        updateQueue.erase(it);
        IEntity *pEntity = CMapObjectMgr::EntityPtr(entity);
        pEntity->ClearFlagBits(EntityFlag_Registered);
        return;
      }
      else
      {
        ++it;
      }
    }
  }
}

// address=[0x15574c0]
// Decompiled from void __thiscall CMapObjectMgr::Store(CMapObjectMgr *this, struct S4::CMapFile *arg0)
void CMapObjectMgr::Store(class S4::CMapFile &arg0)
{
  std::stringstream stringStream = std::stringstream();
  // EXCEPTION HANDLING
  stringStream << fileFormatVersion; // VERSION
  stringStream << m_iMinFreeId;
  stringStream << m_iLastUsedId;
  stringStream << m_iMaxLastUsedId;
  stringStream << m_iCurrentUniqueId;
  stringStream << m_uCRCLogicUpdate;
  stringStream << 4; // NOTE(WizzardMaker) Why is this 4? According to LOAD this should be this->m_iCurrentLogicTick
  stringStream << MAX_LOGIC_UPDATE_SLOTS;
  for (int updateSlot = 0; updateSlot < MAX_LOGIC_UPDATE_SLOTS; ++updateSlot)
  {
    auto &slotQueue = this->m_vLogicUpdateSlots->at(updateSlot);
    stringStream << slotQueue.size();

    for (auto &queueItem : slotQueue)
    {
      stringStream << queueItem;
    }
  }
  stringStream << MAX_LOGIC_UPDATE_SLOTS;
  for (int killSlot = 0; killSlot < MAX_LOGIC_UPDATE_SLOTS; ++killSlot)
  {
    auto &slotQueue = this->m_vKilledEntities->at(killSlot);
    stringStream << slotQueue.size();

    for (auto &queueItem : slotQueue)
    {
      stringStream << queueItem;
    }
  }
  
  stringStream.put(0);
  
  // EXCEPTION HANDLING
  arg0.SaveChunk(0xAAu, 0, stringStream.gcount(), stringStream.str().c_str(), 0);
}

// address=[0x1557910]
// Decompiled from void __thiscall CMapObjectMgr::Load(CMapObjectMgr *this, struct S4::CMapFile *arg0)
void CMapObjectMgr::Load(class S4::CMapFile &arg0)
{
  CTrace::Print("CMapObjectMgr load");
  int unknown = 0;
  void *chunk = arg0.LoadChunk(0xAAu, 0, unknown, nullptr);
  if (chunk)
  {
    std::istringstream chunkStream = std::istringstream(static_cast<char *>(chunk));
    // EXCEPTION HANDLING
    
    // EXCEPTION HANDLING
    int version = 0;
    chunkStream >> version;
    if (version != fileFormatVersion)
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMapObjectMgr");
      throw new CS4InvalidMapException();
    }
    this->m_vLogicUpdateSlots->resize(MAX_LOGIC_UPDATE_SLOTS);
    this->m_iCurrentLogicTick = 0;
    this->m_vKilledEntities->resize(MAX_LOGIC_UPDATE_SLOTS);
    chunkStream >> m_iMinFreeId;
    chunkStream >> m_iLastUsedId;
    chunkStream >> m_iMaxLastUsedId;
    chunkStream >> m_iCurrentUniqueId;
    chunkStream >> m_uCRCLogicUpdate;
    chunkStream >> this->m_iCurrentLogicTick;

    int logicUpdateSlotCount = 0;
    chunkStream >> logicUpdateSlotCount;
    for (int updateSlot = 0; updateSlot < logicUpdateSlotCount; ++updateSlot)
    {
      int queueSize = 0;
      chunkStream >> queueSize;

      for (int i = 0; i < queueSize; ++i)
      {
        int queuedEntityId = 0;
        chunkStream >> queuedEntityId;
        auto &slotQueue = this->m_vLogicUpdateSlots->at(updateSlot);
        slotQueue.push_back(queuedEntityId);
      }
    }

    int killedEntitiesSlotCount = 0;
    chunkStream >> killedEntitiesSlotCount;
    for (int killSlot = 0; killSlot < killedEntitiesSlotCount; ++killSlot)
    {
      int queueSize = 0;
      chunkStream >> queueSize;

      for (int i = 0; i < queueSize; ++i)
      {
        int queuedEntityId = 0;
        chunkStream >> queuedEntityId;
        auto &slotQueue = this->m_vKilledEntities->at(killSlot);
        slotQueue.push_back(queuedEntityId);
      }
    }
  }
}

// address=[0x1557c60]
// Decompiled from int __thiscall CMapObjectMgr::PrintEntity(  CMapObjectMgr *this,  int _iEntityId,  int _iLogLevel,  const char *_sCustomMessage)
void CMapObjectMgr::PrintEntity(int _iEntityId, int _iLogLevel, char const *_sCustomMessage)
{
  const char *message; // [esp+4h] [ebp-Ch]
  if (_sCustomMessage)
    message = _sCustomMessage;
  else
    message = "CMapObjectMgr::PrintEntity()";

  if ((unsigned int)_iEntityId > MAX_ENTRIES)
    return BBSupportTracePrintF(_iLogLevel, "%s: Entity id %i out of range!", message, _iEntityId);
  if (!_iEntityId)
    return BBSupportTracePrintF(_iLogLevel, "%s: Entity id 0 is reserved!", message);
  if (_iEntityId > m_iMaxLastUsedId)
    return BBSupportTracePrintF(_iLogLevel, "%s: Entity id %i is > MaxLastUsedId!", message, _iEntityId);
  IEntity *pEntity = m_vEntities[_iEntityId];
  if (pEntity)
    return pEntity->DbgPrint(_iLogLevel, message);
  else
    return BBSupportTracePrintF(_iLogLevel, "%s: Entity id %i is unused!", message, _iEntityId);
}

// address=[0x1557d40]
// Decompiled from int __thiscall CMapObjectMgr::DbgPrintEntity(  CMapObjectMgr *this,  int _iEntityId,  int _iLogLevel,  const char *_sCustomMessage)
void CMapObjectMgr::DbgPrintEntity(int _iEntityId, int _iLogLevel, char const *_sCustomMessage)
{

  return this->PrintEntity(_iEntityId, _iLogLevel, _sCustomMessage);
}

// address=[0x1557d70]
// Decompiled from int __thiscall CMapObjectMgr::PrintAllEntities(CMapObjectMgr *this, int _iLogLevel)
void CMapObjectMgr::PrintAllEntities(int _iLogLevel)
{
  int _iLastUsedId = m_iLastUsedId;
  BBSupportTracePrintF(_iLogLevel, "CMapObjectMgr::PrintAllEntities()...");
  BBSupportTracePrintF(_iLogLevel, " Current tick is %u.", g_uDbgTickCounter);
  int used = 0;
  int alive = 0;
  for (int i = 0; i <= _iLastUsedId; ++i)
  {
    IEntity *pEntity = m_vEntities[i];
    if (pEntity)
    {
      ++used;
      if (!pEntity->FlagBits(EntityFlag_Died))
        ++alive;
    }
  }

  BYTE entitySlotList[MAX_ENTRIES+1]; // [esp+98h] [ebp-20030h] BYREF
  BYTE entityList[MAX_ENTRIES+1]; // [esp+10098h] [ebp-10030h] BYREF
  memset(entitySlotList, 255, sizeof(entitySlotList));
  memset(entityList, 0, sizeof(entityList));

  for (int slot = 0; (int)slot < MAX_LOGIC_UPDATE_SLOTS; ++slot)
  {
    auto &updateQueue = this->m_vLogicUpdateSlots->at(slot);

    for(auto entityId : updateQueue)
    {
      if ((char)entitySlotList[entityId] != -1)
        entityList[entityId] = 1;
      entitySlotList[entityId] = slot;
    }
  }
  for (int j = 0; (int)j < MAX_LOGIC_UPDATE_SLOTS; ++j)
  {
    auto &killQueue = this->m_vKilledEntities->at(j);

    for (auto entityId : killQueue)
    {
      if ((char)entitySlotList[entityId] != -1)
        entityList[entityId] = 1;
      entitySlotList[entityId] = j + MAX_LOGIC_UPDATE_SLOTS;
    }
  }
  BBSupportTracePrintF(
      _iLogLevel,
      " Used: %5i, Alive: %5i, MinFree: %5i, LastUsed: %5i, MaxLastUsed: %5i, UniqueId: %5i, CRC: 0x%08x",
      used,
      alive,
      m_iMinFreeId,
      m_iLastUsedId,
      m_iMaxLastUsedId,
      m_iCurrentUniqueId,
      m_uCRCLogicUpdate);
  for (int k = 1; k <= _iLastUsedId; ++k)
  {
    IEntity *pEntity = m_vEntities[k];
    if (pEntity)
    {
      char slotDebugStrBuffer[MAX_LOGIC_UPDATE_SLOTS];

      unsigned char entitySlot = entitySlotList[k];
      if (entitySlot >= 0)
      {
        bool isKillSlot = entitySlot >= MAX_LOGIC_UPDATE_SLOTS;

        unsigned char slotNr;
        if (entitySlot < MAX_LOGIC_UPDATE_SLOTS)
          slotNr = entitySlot;
        else
          slotNr = entitySlot - MAX_LOGIC_UPDATE_SLOTS;

        const char *slotOccupied, *slotState;
        if (entityList[k])
          slotOccupied = "#";
        else
          slotOccupied = "+";

        if (isKillSlot)
          slotState = "d";
        else
          slotState = "s";
        snprintf(slotDebugStrBuffer, sizeof(slotDebugStrBuffer), " %05i[%s%02i%s]", k, slotState, slotNr, slotOccupied);
      }
      else
      {
        snprintf(slotDebugStrBuffer, sizeof(slotDebugStrBuffer), " %05i[----]", k);
      }
      pEntity->DbgPrint(_iLogLevel, slotDebugStrBuffer);
    }
  }
  return BBSupportTracePrintF(_iLogLevel, "CMapObjectMgr::PrintAllEntities(): End of entity dump.");
}

// address=[0x15582e0]
// Decompiled from int __thiscall CMapObjectMgr::DbgPrintAllEntities(CMapObjectMgr *this, int a2)
void CMapObjectMgr::DbgPrintAllEntities(int a2)
{
  return this->PrintAllEntities(a2);
}

// address=[0x1558cb0]
// Decompiled from int __thiscall CMapObjectMgr::GetGfxInfo(CMapObjectMgr *this, unsigned int _iId, int a3)
struct SGfxObjectInfo *CMapObjectMgr::GetGfxInfo(int _iId, int a3)
{

  if (!CMapObjectMgr::ValidUsedEntityId(_iId) && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\MapObjectMgr.cpp", 205, "ValidUsedEntityId( _iId )") == 1)
  {
    __debugbreak();
  }
  return m_vEntities[_iId]->GetGfxInfos();
}

// address=[0x3d8bba4]
// [Decompilation failed for static int m_iMinFreeId]

// address=[0x3d8bba8]
// [Decompilation failed for static int m_iCurrentUniqueId]

// address=[0x3d8bbac]
// [Decompilation failed for static unsigned int m_uCRCLogicUpdate]

// address=[0x4105380]
// [Decompilation failed for static int m_iLastUsedId]

// address=[0x4105384]
// [Decompilation failed for static int m_iMaxLastUsedId]

// address=[0x4105388]
// [Decompilation failed for static class IEntity * * m_vEntities]
