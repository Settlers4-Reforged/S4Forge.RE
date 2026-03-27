#if FALSE
#include "CMapObjectMgr.h"

// Definitions for class CMapObjectMgr

// address=[0x12fd030]
// Decompiled from IEntity *__cdecl CMapObjectMgr::EntityPtr(int a1)
class IEntity * __cdecl CMapObjectMgr::EntityPtr(int a1) {
  
  if ( !CMapObjectMgr::ValidEntityId(a1) && BBSupportDbgReport(2, string__2, 212, "ValidEntityId( _iId )") == 1 )
    __debugbreak();
  return CMapObjectMgr::m_vEntities[a1];
}


// address=[0x12fd860]
// Decompiled from bool __cdecl CMapObjectMgr::ValidEntityId(unsigned int a1)
bool __cdecl CMapObjectMgr::ValidEntityId(int a1) {
  
  return a1 <= CMapObjectMgr::m_iMaxLastUsedId;
}


// address=[0x13094c0]
// Decompiled from IEntity *__cdecl CMapObjectMgr::Entity(unsigned int a1)
class IEntity & __cdecl CMapObjectMgr::Entity(int a1) {
  
  if ( !CMapObjectMgr::ValidUsedEntityId(a1) && BBSupportDbgReport(2, string__2, 228, "ValidUsedEntityId( _iId )") == 1 )
    __debugbreak();
  return CMapObjectMgr::m_vEntities[a1];
}


// address=[0x13096b0]
// Decompiled from bool __cdecl CMapObjectMgr::ValidUsedEntityId(unsigned int a1)
bool __cdecl CMapObjectMgr::ValidUsedEntityId(int a1) {
  
  return a1 <= CMapObjectMgr::m_iLastUsedId && CMapObjectMgr::m_vEntities[a1];
}


// address=[0x130ee70]
// Decompiled from int __cdecl CMapObjectMgr::GetUniqueId(unsigned int a1)
int __cdecl CMapObjectMgr::GetUniqueId(int a1) {
  
  IEntity *v3; // [esp+4h] [ebp-4h]

  if ( !CMapObjectMgr::ValidEntityId(a1) && BBSupportDbgReport(2, string__2, 257, "ValidEntityId( _iId )") == 1 )
    __debugbreak();
  v3 = CMapObjectMgr::m_vEntities[a1];
  if ( v3 )
    return v3->m_iUniqueId;
  else
    return 0;
}


// address=[0x130f140]
// Decompiled from IEntity *__cdecl CMapObjectMgr::MovingEntity(unsigned int _iId)
class IMovingEntity & __cdecl CMapObjectMgr::MovingEntity(int _iId) {
  
  IEntity *v2; // [esp+0h] [ebp-4h]

  if ( !CMapObjectMgr::ValidUsedEntityId(_iId)
    && BBSupportDbgReport(2, string__2, 246, "ValidUsedEntityId( _iId )") == 1 )
  {
    __debugbreak();
  }
  v2 = CMapObjectMgr::m_vEntities[_iId];
  if ( !j____RTDynamicCast(
          (void **)&v2->__vftable,
          0,
          &IEntity__RTTI_Type_Descriptor_,
          &IMovingEntity__RTTI_Type_Descriptor_,
          0)
    && BBSupportDbgReport(2, string__2, 250, "dynamic_cast<IMovingEntity*>( pEntity ) != 0") == 1 )
  {
    __debugbreak();
  }
  return v2;
}


// address=[0x1439c10]
// Decompiled from int CMapObjectMgr::LastUsedId()
int __cdecl CMapObjectMgr::LastUsedId(void) {
  
  return CMapObjectMgr::m_iLastUsedId;
}


// address=[0x14aaa30]
// Decompiled from int CMapObjectMgr::CRCLogicUpdate()
unsigned int __cdecl CMapObjectMgr::CRCLogicUpdate(void) {
  
  return CMapObjectMgr::m_uCRCLogicUpdate;
}


// address=[0x15560f0]
// Decompiled from CMapObjectMgr *__thiscall CMapObjectMgr::CMapObjectMgr(CMapObjectMgr *this)
 CMapObjectMgr::CMapObjectMgr(void) {
  
  int id; // eax
  int FreeSlot; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  CSettler *v8; // [esp+20h] [ebp-3Ch]
  CSettler *v9; // [esp+28h] [ebp-34h]
  CSettler *v10; // [esp+30h] [ebp-2Ch]
  CSettler *v11; // [esp+38h] [ebp-24h]
  CSettler *v12; // [esp+40h] [ebp-1Ch]
  CSettler *v13; // [esp+48h] [ebp-14h]

  std::vector<std::deque<unsigned short>>::vector<std::deque<unsigned short>>(this);
  std::vector<std::deque<unsigned short>>::vector<std::deque<unsigned short>>(&this->unk_14);
  memset(CMapObjectMgr::m_vEntities, 0, 0x40000u);
  CMapObjectMgr::m_iMinFreeId = 1;
  CMapObjectMgr::m_iLastUsedId = 0;
  CMapObjectMgr::m_iMaxLastUsedId = 0;
  CMapObjectMgr::m_iCurrentUniqueId = 1;
  v13 = (CSettler *)CSettler::operator new(0x68u);
  if ( v13 )
  {
    id = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v13, 0x44u, id);
  }
  v12 = (CSettler *)CSettler::operator new(0x68u);
  if ( v12 )
  {
    FreeSlot = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v12, 0x44u, FreeSlot);
  }
  v11 = (CSettler *)CSettler::operator new(0x68u);
  if ( v11 )
  {
    v3 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v11, 0x44u, v3);
  }
  v10 = (CSettler *)CSettler::operator new(0x68u);
  if ( v10 )
  {
    v4 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v10, 0x44u, v4);
  }
  v9 = (CSettler *)CSettler::operator new(0x68u);
  if ( v9 )
  {
    v5 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v9, 0x44u, v5);
  }
  v8 = (CSettler *)CSettler::operator new(0x68u);
  if ( v8 )
  {
    v6 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v8, 0x44u, v6);
  }
  std::vector<std::deque<unsigned short>>::resize((void **)&this->m_vLogicUpdateSlots, (_DWORD *)0x20);
  this->m_vLogicUpdateListItem = 0;
  std::vector<std::deque<unsigned short>>::resize((void **)&this->unk_14, (_DWORD *)0x20);
  CMapObjectMgr::m_uCRCLogicUpdate = 1;
  return this;
}


// address=[0x1556330]
// Decompiled from int __thiscall CMapObjectMgr::~CMapObjectMgr(CMapObjectMgr *this)
 CMapObjectMgr::~CMapObjectMgr(void) {
  
  int i; // [esp+14h] [ebp-10h]

  if ( CMapObjectMgr::m_vEntities[0]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 114, "m_vEntities[0] == 0") == 1 )
  {
    __debugbreak();
  }
  CMapObjectMgr::m_vEntities[0] = 0;
  for ( i = 1; i < 0xFFFF; ++i )
  {
    if ( CMapObjectMgr::m_vEntities[i] )
    {                                           // delete[] m_vEntities
      CMapObjectMgr::m_vEntities[i]->j_??_GIEntity@@UAEPAXI@Z(
        (Concurrency::details::_Condition_variable *)CMapObjectMgr::m_vEntities[i],
        1);
      CMapObjectMgr::m_vEntities[i] = 0;
    }
  }
  if ( CMapObjectMgr::m_vEntities[0xFFFF]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 132, "m_vEntities[MAX_ENTRIES] == 0") == 1 )
  {
    __debugbreak();
  }
  CMapObjectMgr::m_vEntities[0xFFFF] = 0;
  std::vector<std::deque<unsigned short>>::clear(this);
  std::vector<std::deque<unsigned short>>::clear(&this->unk_14);
  CMapObjectMgr::m_iMinFreeId = 1;
  CMapObjectMgr::m_iLastUsedId = 0;
  CMapObjectMgr::m_iMaxLastUsedId = 0;
  CMapObjectMgr::m_iCurrentUniqueId = 1;
  std::vector<std::deque<unsigned short>>::~vector<std::deque<unsigned short>>(&this->unk_14);
  return std::vector<std::deque<unsigned short>>::~vector<std::deque<unsigned short>>(this);
}


// address=[0x15564b0]
// Decompiled from int CMapObjectMgr::GetFreeSlot()
int __cdecl CMapObjectMgr::GetFreeSlot(void) {
  
  int i; // [esp+8h] [ebp-4h]

  if ( (CMapObjectMgr::m_iMinFreeId < 1 || CMapObjectMgr::m_iMinFreeId > 0xFFFF)
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 328, "m_iMinFreeId >= 1 && m_iMinFreeId <= MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  for ( i = CMapObjectMgr::m_iMinFreeId; i < 0xFFFF; ++i )
  {
    if ( !CMapObjectMgr::m_vEntities[i] )
    {
      CMapObjectMgr::m_iMinFreeId = i;
      IMessageTracer::PushFormatedInts(g_pMsgTracer, "CMapObjectMgr::GetFreeSlot(): New free slot %i", (char *)i);
      return i;
    }
  }
  CMapObjectMgr::m_iMinFreeId = 0xFFFF;
  IMessageTracer::PushStaticText(g_pMsgTracer, "CMapObjectMgr::GetFreeSlot(): No new free slot");
  return -1;
}


// address=[0x1556580]
// Decompiled from void __cdecl CMapObjectMgr::RegisterEntity(int _iId, struct IEntity *_pEntity, bool a3)
void __cdecl CMapObjectMgr::RegisterEntity(int _iId, class IEntity * _pEntity, bool a3) {
  
  if ( !_pEntity && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 381, "_pEntity != NULL") == 1 )
    __debugbreak();
  if ( (_iId <= 0 || _iId >= 0xFFFF)
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 382, "_iId>0 && _iId<MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( CMapObjectMgr::m_vEntities[_iId]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 383, "m_vEntities[ _iId ] == NULL") == 1 )
  {
    __debugbreak();
  }
  if ( a3 )
  {
    if ( _pEntity->m_iUniqueId != -1
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 389, "_pEntity->m_iUniqueId == -1") == 1 )
    {
      __debugbreak();
    }
    if ( CMapObjectMgr::m_iCurrentUniqueId <= 0
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 390, "m_iCurrentUniqueId > 0") == 1 )
    {
      __debugbreak();
    }
    if ( (CMapObjectMgr::m_iCurrentUniqueId & 0x20000000) != 0
      && BBSupportDbgReport(
           2,
           "MapObjects\\MapObjectMgr.cpp",
           391,
           "(m_iCurrentUniqueId & IEntity::UNIQUE_ID_DEAD_ENTITY_BIT) == 0") == 1 )
    {
      __debugbreak();
    }
    _pEntity->m_iUniqueId = CMapObjectMgr::m_iCurrentUniqueId++;
  }
  else if ( _pEntity->m_iUniqueId <= 0
         && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 397, "_pEntity->m_iUniqueId > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iId > CMapObjectMgr::m_iLastUsedId )
  {
    CMapObjectMgr::m_iLastUsedId = _iId;
    if ( _iId > CMapObjectMgr::m_iMaxLastUsedId )
      CMapObjectMgr::m_iMaxLastUsedId = _iId;
  }
  CMapObjectMgr::m_vEntities[_iId] = _pEntity;
}


// address=[0x1556710]
// Decompiled from void __cdecl CMapObjectMgr::AssignNewUniqueId(int _iId)
void __cdecl CMapObjectMgr::AssignNewUniqueId(int _iId) {
  
  IEntity *v1; // [esp+0h] [ebp-4h]

  if ( _iId > 0 && _iId < 0xFFFF )
  {
    v1 = CMapObjectMgr::m_vEntities[_iId];
    if ( v1 )
    {
      if ( (v1->m_iUniqueId & 0x20000000) == 0 )
        v1->m_iUniqueId = CMapObjectMgr::m_iCurrentUniqueId++;
    }
  }
}


// address=[0x1556760]
// Decompiled from void __thiscall CMapObjectMgr::Kill(CMapObjectMgr *this, int _iEntityId, int _iAttackerId)
void  CMapObjectMgr::Kill(int _iEntityId, int _iAttackerId) {
  
  int v3; // eax
  void *v4; // eax
  int v5; // [esp-Ch] [ebp-38h]
  int type; // [esp-8h] [ebp-34h] MAPDST
  DWORD v7; // [esp+0h] [ebp-2Ch]
  CAIEntityInfo *m_psAIEntityInfo; // [esp+10h] [ebp-1Ch]
  int ownerId; // [esp+14h] [ebp-18h]
  IAnimatedEntity *pAnimatedEntity; // [esp+18h] [ebp-14h]
  int objType; // [esp+1Ch] [ebp-10h]
  IEntity *entity; // [esp+24h] [ebp-8h]
  __int16 v15; // [esp+2Ah] [ebp-2h] BYREF

  if ( (_iEntityId <= 0 || _iEntityId >= 0xFFFF)
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 449, "_iEntityId>0 && _iEntityId<MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( !CMapObjectMgr::m_vEntities[_iEntityId]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 450, "m_vEntities[ _iEntityId ] != 0") == 1 )
  {
    __debugbreak();
  }
  entity = CMapObjectMgr::m_vEntities[_iEntityId];
  type = IEntity::Type(entity);
  v5 = IEntity::ObjType(entity);
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CMapObjectMgr::Kill(): id %u, type %u / %u, attacker %i",
    _iEntityId,
    v5,
    type,
    (char *)_iAttackerId);
  if ( (entity->m_iUniqueId & 0x20000000) != 0 )
  {
    if ( IEntity::FlagBits(entity, EntityFlag_AliveMask)
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 460, "pEntity->FlagBits(ENTITY_FLAG_ALIVE_MASK) == 0") == 1 )
    {
      __debugbreak();
    }
    if ( !IEntity::FlagBits(entity, EntityFlag_Died)
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 461, "pEntity->FlagBits(ENTITY_FLAG_DIED) != 0") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    entity->m_iUniqueId |= 0x20000000u;
    if ( IEntity::FlagBits(entity, EntityFlag_Died)
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 468, "pEntity->FlagBits(ENTITY_FLAG_DIED) == 0") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::FlagBits(entity, EntityFlag_Birth) )
      IEntity::SetFlagBits(entity, (EntityFlag)0x100000);
    else
      IEntity::ClearFlagBits(entity, (EntityFlag)0x100000);
    IEntity::ClearFlagBits(entity, EntityFlag_AliveMask);
    IEntity::SetFlagBits(entity, EntityFlag_Died);
    if ( CWarMapNode::IsInWarMap(&entity->m_warMapNode) )
      CWarMap::RemoveEntity(entity);
    if ( IEntity::FlagBits(entity, EntityFlag_Selected) || IEntity::FlagBits(entity, (EntityFlag)1024) )
    {
      v3 = IEntity::ID(entity);
      CInputProcessor::DeSelectEntity(&g_cInputProcessor, v3);
    }
    if ( entity->GetGroupFlags() )
      g_pGroupMgr->DetachEntityFromAllGroups(_iEntityId);
    if ( _iAttackerId > 0 )
    {
      ownerId = IEntity::OwnerId(entity);
      objType = IEntity::ObjType(entity);
      type = IEntity::Type(entity);
      if ( objType == 1 )
      {
        CStatistic::IncKillsOfType(_iAttackerId, type);
        CStatistic::IncLossesOfType((CStatistic *)&g_cStatistic, ownerId, type);
      }
      if ( objType == 2 || objType == 4 )
      {
        CStatistic::IncKillsVehicleOfType((CStatistic *)&g_cStatistic, _iAttackerId, type);
        CStatistic::IncLossesVehicleOfType((CStatistic *)&g_cStatistic, ownerId, type);
      }
    }
    if ( entity->m_psAIEntityInfo )
    {
      m_psAIEntityInfo = entity->m_psAIEntityInfo;
      if ( m_psAIEntityInfo )
        delete m_psAIEntityInfo;
      entity->m_psAIEntityInfo = 0;
    }
    entity->Delete();
    pAnimatedEntity = (IAnimatedEntity *)j____RTDynamicCast(
                                           (void **)&entity->__vftable,
                                           0,
                                           &IEntity__RTTI_Type_Descriptor_,
                                           &IAnimatedEntity__RTTI_Type_Descriptor_,
                                           0);
    if ( pAnimatedEntity )
    {
      if ( IAnimatedEntity::Previous(pAnimatedEntity)
        && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 548, "pAnimatedEntity->Previous() == 0") == 1 )
      {
        __debugbreak();
      }
      if ( IAnimatedEntity::Next(pAnimatedEntity)
        && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 549, "pAnimatedEntity->Next() == 0") == 1 )
      {
        __debugbreak();
      }
    }
    v7 = (this->m_vLogicUpdateListItem + 31) % 0x20;
    v15 = _iEntityId;
    v4 = (void *)std::vector<std::deque<unsigned short>>::operator[](&this->unk_14, v7);
    std::deque<unsigned short>::push_front(v4, (int)&v15);
  }
}


// address=[0x1556b00]
// Decompiled from void __thiscall CMapObjectMgr::Destroy(CMapObjectMgr *this, int _iEntityId)
void  CMapObjectMgr::Destroy(int _iEntityId) {
  
  IEntity *v2; // [esp+14h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-4h]

  if ( (_iEntityId <= 0 || _iEntityId >= 0xFFFF)
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 566, "_iEntityId>0 && _iEntityId<MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( !CMapObjectMgr::m_vEntities[_iEntityId]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 567, "m_vEntities[ _iEntityId ] != 0") == 1 )
  {
    __debugbreak();
  }
  v2 = CMapObjectMgr::m_vEntities[_iEntityId];
  if ( v2->m_nEntityId != _iEntityId
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 571, "pEntity->m_uID == _iEntityId") == 1 )
  {
    __debugbreak();
  }
  if ( v2 )
    v2->j_??_GIEntity@@UAEPAXI@Z((Concurrency::details::_Condition_variable *)v2, 1);
  CMapObjectMgr::m_vEntities[_iEntityId] = 0;
  if ( _iEntityId < CMapObjectMgr::m_iMinFreeId )
    CMapObjectMgr::m_iMinFreeId = _iEntityId;
  if ( CMapObjectMgr::m_iLastUsedId < 0
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 582, "m_iLastUsedId >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( CMapObjectMgr::m_vEntities[0]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 583, "m_vEntities[0] == 0") == 1 )
  {
    __debugbreak();
  }
  for ( i = CMapObjectMgr::m_iLastUsedId; CMapObjectMgr::m_vEntities[i] == 0 && i > 0; --i )
    ;
  CMapObjectMgr::m_iLastUsedId = i;
}


// address=[0x1556cb0]
// Decompiled from void __thiscall CMapObjectMgr::LogicUpdate(CMapObjectMgr *this)
void  CMapObjectMgr::LogicUpdate(void) {
  
  unsigned int v1; // eax
  int size; // eax
  int objType; // eax
  int v4; // [esp-4h] [ebp-8E0h]
  int type; // [esp-4h] [ebp-8E0h]
  int v6; // [esp+4h] [ebp-8D8h]
  int crc1; // [esp+8h] [ebp-8D4h]
  DWORD v8; // [esp+18h] [ebp-8C4h]
  int crc2; // [esp+1Ch] [ebp-8C0h]
  int crc3; // [esp+20h] [ebp-8BCh]
  int v11; // [esp+24h] [ebp-8B8h]
  void *v12; // [esp+28h] [ebp-8B4h]
  int v13; // [esp+30h] [ebp-8ACh]
  int i; // [esp+34h] [ebp-8A8h]
  int iEntity; // [esp+38h] [ebp-8A4h]
  int k; // [esp+3Ch] [ebp-8A0h]
  int j; // [esp+40h] [ebp-89Ch]
  int a2; // [esp+44h] [ebp-898h]
  IAnimatedEntity *pEntity; // [esp+48h] [ebp-894h]
  unsigned int v20; // [esp+4Ch] [ebp-890h]
  void *q; // [esp+54h] [ebp-888h]
  _DWORD v23[32]; // [esp+58h] [ebp-884h] BYREF
  _WORD v24[1024]; // [esp+D8h] [ebp-804h] BYREF

  q = (void *)std::vector<std::deque<unsigned short>>::operator[](
                (void **)&this->m_vLogicUpdateSlots,
                this->m_vLogicUpdateListItem);
  crc1 = CMapObjectMgr::m_uCRCLogicUpdate;
  crc2 = CMapObjectMgr::m_uCRCLogicUpdate;
  crc3 = CMapObjectMgr::m_uCRCLogicUpdate;
  if ( std::deque<unsigned short>::size(q) )
  {
    v11 = std::deque<unsigned short>::size(q);
    v20 = 0;
    for ( i = 0; i < v11 / 1024; ++i )
    {
      for ( j = 0; j < 1024; ++j )
        v24[j] = *(_WORD *)std::deque<unsigned short>::operator[](q, v20++);
      CMapObjectMgr::m_uCRCLogicUpdate = Adler32((unsigned __int8 *)v24, 0x800u, CMapObjectMgr::m_uCRCLogicUpdate);
    }
    crc2 = CMapObjectMgr::m_uCRCLogicUpdate;
    v13 = v11 % 1024;
    if ( v11 % 1024 > 0 )
    {
      for ( k = 0; k < v13; ++k )
        v24[k] = *(_WORD *)std::deque<unsigned short>::operator[](q, v20++);
      CMapObjectMgr::m_uCRCLogicUpdate = Adler32((unsigned __int8 *)v24, 2 * v13, CMapObjectMgr::m_uCRCLogicUpdate);
    }
    crc3 = CMapObjectMgr::m_uCRCLogicUpdate;
  }
  for ( a2 = 0; a2 < 32; ++a2 )
  {
    v1 = std::vector<std::deque<unsigned short>>::operator[]((void **)&this->m_vLogicUpdateSlots, a2);
    v23[a2] = std::deque<unsigned short>::size(v1);
  }
  CMapObjectMgr::m_uCRCLogicUpdate = Adler32((unsigned __int8 *)v23, 0x80u, CMapObjectMgr::m_uCRCLogicUpdate);
  v4 = CMapObjectMgr::m_uCRCLogicUpdate;
  size = std::deque<unsigned short>::size(q);
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CMapObjectMgr::LogicUpdate(): size %u, CRCs 0x%08x, 0x%08x, 0x%08x, 0x%08x",
    size,
    crc1,
    crc2,
    crc3,
    v4);
  while ( !(unsigned __int8)std::deque<unsigned short>::empty(q) )
  {
    iEntity = *(unsigned __int16 *)std::deque<unsigned short>::front(q);
    if ( ((unsigned __int8)std::deque<unsigned short>::empty(q) || !*(_WORD *)std::deque<unsigned short>::front(q))
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 781, "q.empty() == false && 0 != q.front()") == 1 )
    {
      __debugbreak();
    }
    std::deque<unsigned short>::pop_front(q);
    pEntity = (IAnimatedEntity *)CMapObjectMgr::EntityPtr(iEntity);
    if ( pEntity )
    {
      if ( IEntity::ID(pEntity) != iEntity
        && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 795, "pEntity->ID() == iEntityId") == 1 )
      {
        __debugbreak();
      }
      if ( !j____RTDynamicCast(
              (void **)&pEntity->__vftable,
              0,
              &IEntity__RTTI_Type_Descriptor_,
              &IAnimatedEntity__RTTI_Type_Descriptor_,
              0)
        && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 796, "dynamic_cast<IAnimatedEntity*>(pEntity) != 0") == 1 )
      {
        __debugbreak();
      }
      IEntity::ClearFlagBits(pEntity, EntityFlag_Registered);
      type = IEntity::Type(pEntity);
      objType = IEntity::ObjType(pEntity);
      IMessageTracer::PushFormatedInts(g_pMsgTracer, "LogicUpdate(): id %u, type %u / %u", iEntity, objType, type);
      pEntity->LogicUpdate();
    }
    else
    {
      BBSupportTracePrintF(
        3,
        "### CMapObjectMgr::LogicUpdate(): EntityPtr for entity id %i in list %i is NULL! ###",
        iEntity,
        this->m_vLogicUpdateListItem);
    }
  }
  v12 = (void *)std::vector<std::deque<unsigned short>>::operator[](
                  (void **)&this->unk_14,
                  this->m_vLogicUpdateListItem);
  while ( !(unsigned __int8)std::deque<unsigned short>::empty(v12) )
  {
    v6 = *(unsigned __int16 *)std::deque<unsigned short>::front(v12);
    std::deque<unsigned short>::pop_front(v12);
    CMapObjectMgr::Destroy(this, v6);
  }
  v8 = this->m_vLogicUpdateListItem + 1;
  this->m_vLogicUpdateListItem = v8;
  this->m_vLogicUpdateListItem = v8 % 32;
}


// address=[0x15571c0]
// Decompiled from int __thiscall CMapObjectMgr::RegisterForLogicUpdate(CMapObjectMgr *this, int iDeltaTicks, int _iEntityId)
int  CMapObjectMgr::RegisterForLogicUpdate(int iDeltaTicks, int _iEntityId) {
  
  int v3; // eax
  unsigned int LastLogicUpdateTick; // eax
  void *updateQueue; // eax
  int objType; // [esp-Ch] [ebp-20h]
  int type; // [esp-8h] [ebp-1Ch]
  int v9; // [esp-8h] [ebp-1Ch]
  DWORD logicUpdateSlot; // [esp+4h] [ebp-10h]
  IAnimatedEntity *pEntity; // [esp+Ch] [ebp-8h]
  WORD entityToBeUpdated; // [esp+12h] [ebp-2h] BYREF

  if ( (iDeltaTicks <= 0 || iDeltaTicks >= 32)
    && BBSupportDbgReport(
         2,
         "MapObjects\\MapObjectMgr.cpp",
         847,
         "(0 < _iDeltaTicks) && (_iDeltaTicks < MAX_LOGIC_UPDATE_SLOTS)") == 1 )
  {
    __debugbreak();
  }
  if ( iDeltaTicks > 0 )
  {
    if ( iDeltaTicks >= 32 )
      iDeltaTicks = 31;
  }
  else
  {
    iDeltaTicks = 1;
  }
  logicUpdateSlot = (iDeltaTicks + this->m_vLogicUpdateListItem) % 0x20;
  pEntity = (IAnimatedEntity *)CMapObjectMgr::EntityPtr(_iEntityId);
  if ( IMessageTracer::RemoveCurrentMsgIfEqual(
         (const char **)g_pMsgTracer,
         "LogicUpdate(): id %u, type %u / %u",
         (const char *)_iEntityId) )
  {
    type = IEntity::Type(pEntity);
    objType = IEntity::ObjType(pEntity);
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer,
      "LogicUpdate() + RegisterForLogicUpdate(): id %u, type %u / %u, delta ticks %u",
      _iEntityId,
      objType,
      type,
      (char *)iDeltaTicks);
  }
  else
  {
    v9 = IEntity::Type(pEntity);
    v3 = IEntity::ObjType(pEntity);
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer,
      "RegisterForLogicUpdate(): id %u, type %u / %u, delta ticks %u",
      _iEntityId,
      v3,
      v9,
      (char *)iDeltaTicks);
  }
  if ( IEntity::FlagBits(pEntity, (EntityFlag)&MEMORY[0x4000000])
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 874, "pEntity->FlagBits(ENTITY_FLAG_DIED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::GetLastLogicUpdateTick(pEntity) != -1
    && IAnimatedEntity::GetLastLogicUpdateTick(pEntity) != this->m_vLogicUpdateListItem )
  {
    LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(pEntity);
    CMapObjectMgr::UnRegisterFromLogicUpdate(this, LastLogicUpdateTick, _iEntityId);
  }
  entityToBeUpdated = _iEntityId;
  updateQueue = (void *)std::vector<std::deque<unsigned short>>::operator[](
                          (void **)&this->m_vLogicUpdateSlots,
                          logicUpdateSlot);
  std::deque<unsigned short>::push_front(updateQueue, &entityToBeUpdated);
  IEntity::SetFlagBits(pEntity, EntityFlag_Registered);
  return logicUpdateSlot;
}


// address=[0x1557350]
// Decompiled from void __thiscall CMapObjectMgr::UnRegisterFromLogicUpdate(CMapObjectMgr *this, unsigned int slot, int entity)
void  CMapObjectMgr::UnRegisterFromLogicUpdate(int slot, int entity) {
  
  char v3; // [esp-Ch] [ebp-70h] BYREF
  int v4; // [esp-8h] [ebp-6Ch]
  int v5; // [esp-4h] [ebp-68h]
  _BYTE v6[12]; // [esp+4h] [ebp-60h] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-54h] BYREF
  _BYTE v8[12]; // [esp+1Ch] [ebp-48h] BYREF
  _BYTE v9[12]; // [esp+28h] [ebp-3Ch] BYREF
  int v10; // [esp+34h] [ebp-30h]
  int v11; // [esp+38h] [ebp-2Ch]
  char *v12; // [esp+3Ch] [ebp-28h]
  IEntity *v13; // [esp+40h] [ebp-24h]
  int v14; // [esp+44h] [ebp-20h]
  std::_Iterator_base12 *v15; // [esp+48h] [ebp-1Ch]
  std::_Iterator_base12 *v16; // [esp+4Ch] [ebp-18h]
  void **p_m_vLogicUpdateSlots; // [esp+50h] [ebp-14h]
  char v18; // [esp+57h] [ebp-Dh]
  int exceptionBlock; // [esp+60h] [ebp-4h]

  p_m_vLogicUpdateSlots = (void **)&this->m_vLogicUpdateSlots;
  if ( slot < 0x20 )
  {
    std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots, slot);
    std::deque<unsigned short>::begin(v9);
    exceptionBlock = 0;
    while ( 1 )
    {
      std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots, slot);
      v16 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v8);
      v15 = v16;
      LOBYTE(exceptionBlock) = 1;
      v18 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v16);
      LOBYTE(exceptionBlock) = 0;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v8);
      if ( !v18 )
        break;
      if ( *(unsigned __int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v9) == entity )
      {
        v12 = &v3;
        v14 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>((struct std::_Iterator_base12 *)v9);
        v11 = v14;
        LOBYTE(exceptionBlock) = 2;
        std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots, slot);
        LOBYTE(exceptionBlock) = 0;
        v10 = std::deque<unsigned short>::erase(v7, v3, v4, v5);
        std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v7);
        v13 = CMapObjectMgr::EntityPtr(entity);
        IEntity::ClearFlagBits(v13, EntityFlag_Registered);
        exceptionBlock = -1;
        std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v9);
        return;
      }
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v6, 0);
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v6);
    }
    exceptionBlock = -1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v9);
  }
}


// address=[0x15574c0]
// Decompiled from void __thiscall CMapObjectMgr::Store(CMapObjectMgr *this, struct S4::CMapFile *arg0)
void  CMapObjectMgr::Store(class S4::CMapFile & a2) {
  
  std::strstreambuf *v2; // eax
  int v3; // [esp+0h] [ebp-160h] BYREF
  char stringStream[168]; // [esp+10h] [ebp-150h] BYREF
  _BYTE v5[12]; // [esp+B8h] [ebp-A8h] BYREF
  _BYTE v6[12]; // [esp+C4h] [ebp-9Ch] BYREF
  int v7; // [esp+D0h] [ebp-90h]
  _BYTE v8[12]; // [esp+D4h] [ebp-8Ch] BYREF
  _BYTE v9[12]; // [esp+E0h] [ebp-80h] BYREF
  unsigned int v10; // [esp+ECh] [ebp-74h]
  size_t Size; // [esp+F0h] [ebp-70h]
  void *mgrSerializationOutput; // [esp+F4h] [ebp-6Ch]
  WORD *v13; // [esp+F8h] [ebp-68h]
  std::_Iterator_base12 *v14; // [esp+FCh] [ebp-64h]
  std::_Iterator_base12 *v15; // [esp+100h] [ebp-60h]
  unsigned int v16; // [esp+104h] [ebp-5Ch]
  unsigned int v17; // [esp+108h] [ebp-58h]
  int v18; // [esp+10Ch] [ebp-54h] BYREF
  unsigned int v19; // [esp+110h] [ebp-50h]
  WORD *v20; // [esp+114h] [ebp-4Ch]
  std::_Iterator_base12 *v21; // [esp+118h] [ebp-48h]
  std::_Iterator_base12 *v22; // [esp+11Ch] [ebp-44h]
  unsigned int v23; // [esp+120h] [ebp-40h]
  unsigned int v24; // [esp+124h] [ebp-3Ch]
  int v25; // [esp+128h] [ebp-38h] BYREF
  unsigned int v26; // [esp+12Ch] [ebp-34h]
  int v27; // [esp+130h] [ebp-30h] BYREF
  WORD v28; // [esp+138h] [ebp-28h] BYREF
  WORD v29; // [esp+13Ch] [ebp-24h] BYREF
  int v30; // [esp+140h] [ebp-20h] BYREF
  void **p_m_vLogicUpdateSlots; // [esp+144h] [ebp-1Ch]
  char v32; // [esp+148h] [ebp-18h]
  char v33; // [esp+149h] [ebp-17h]
  char v34; // [esp+14Ah] [ebp-16h]
  char v35; // [esp+14Bh] [ebp-15h]
  unsigned int a2; // [esp+14Ch] [ebp-14h]
  int *v37; // [esp+150h] [ebp-10h]
  int v38; // [esp+15Ch] [ebp-4h]

  v37 = &v3;
  p_m_vLogicUpdateSlots = (void **)&this->m_vLogicUpdateSlots;
  v7 = 0x40100;
  std::ostrstream::ostrstream((DWORD *)stringStream, 0, 262400LL, 2, 1);
  v38 = 0;
  v10 = std::ios_base::exceptions(&stringStream[*(_DWORD *)(*(_DWORD *)stringStream + 4)]);
  std::ios_base::exceptions((std::ios_base *)&stringStream[*(_DWORD *)(*(_DWORD *)stringStream + 4)], 6);
  LOBYTE(v38) = 1;
  v27 = 1;
  operator^<unsigned int>((struct std::ostream *)stringStream, &v27);
  operator^<int>((struct std::ostream *)stringStream, &CMapObjectMgr::m_iMinFreeId);
  operator^<int>((struct std::ostream *)stringStream, &CMapObjectMgr::m_iLastUsedId);
  operator^<int>((struct std::ostream *)stringStream, &CMapObjectMgr::m_iMaxLastUsedId);
  operator^<int>((struct std::ostream *)stringStream, &CMapObjectMgr::m_iCurrentUniqueId);
  operator^<unsigned int>((struct std::ostream *)stringStream, &CMapObjectMgr::m_uCRCLogicUpdate);
  operator^<unsigned int>((struct std::ostream *)stringStream, (int *)p_m_vLogicUpdateSlots + 4);
  v30 = 32;
  operator^<unsigned int>((struct std::ostream *)stringStream, &v30);
  for ( a2 = 0; a2 < v30; ++a2 )
  {
    v26 = std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots, a2);
    v25 = std::deque<unsigned short>::size(v26);
    operator^<unsigned int>((struct std::ostream *)stringStream, &v25);
    v24 = std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots, a2);
    std::deque<unsigned short>::begin(v9);
    LOBYTE(v38) = 2;
    while ( 1 )
    {
      v23 = std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots, a2);
      v22 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v6);
      v21 = v22;
      LOBYTE(v38) = 3;
      v35 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v22);
      v34 = v35;
      LOBYTE(v38) = 2;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v6);
      if ( !v34 )
        break;
      v20 = (WORD *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v9);
      v29 = *v20;
      operator^<unsigned short>((struct std::ostream *)stringStream, &v29);
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v9);
    }
    LOBYTE(v38) = 1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v9);
  }
  operator^<unsigned int>((struct std::ostream *)stringStream, &v30);
  for ( a2 = 0; a2 < v30; ++a2 )
  {
    v19 = std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots + 5, a2);
    v18 = std::deque<unsigned short>::size(v19);
    operator^<unsigned int>((struct std::ostream *)stringStream, &v18);
    v17 = std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots + 5, a2);
    std::deque<unsigned short>::begin(v8);
    LOBYTE(v38) = 4;
    while ( 1 )
    {
      v16 = std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots + 5, a2);
      v15 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v5);
      v14 = v15;
      LOBYTE(v38) = 5;
      v33 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v15);
      v32 = v33;
      LOBYTE(v38) = 4;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v5);
      if ( !v32 )
        break;
      v13 = (WORD *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v8);
      v28 = *v13;
      operator^<unsigned short>((struct std::ostream *)stringStream, &v28);
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v8);
    }
    LOBYTE(v38) = 1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v8);
  }
  std::ostream::put(0);
  v38 = 0;
  v2 = std::ostrstream::rdbuf((std::ostrstream *)stringStream);
  Size = std::strstreambuf::pcount(v2);
  mgrSerializationOutput = std::ostrstream::str(stringStream);
  S4::CMapFile::SaveChunk(arg0, 0xAAu, 0, Size, mgrSerializationOutput, 0);
  std::ostrstream::freeze((std::ostrstream *)stringStream, 0);
  std::ios_base::exceptions((std::ios_base *)&stringStream[*(_DWORD *)(*(_DWORD *)stringStream + 4)], v10);
  v38 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)stringStream);
}


// address=[0x1557910]
// Decompiled from void __thiscall CMapObjectMgr::Load(CMapObjectMgr *this, struct S4::CMapFile *arg0)
void  CMapObjectMgr::Load(class S4::CMapFile & a2) {
  
  int v2; // [esp+0h] [ebp-12Ch] BYREF
  _DWORD v3[42]; // [esp+10h] [ebp-11Ch] BYREF
  unsigned int v4; // [esp+B8h] [ebp-74h]
  unsigned int v5; // [esp+BCh] [ebp-70h]
  _DWORD v6[2]; // [esp+C0h] [ebp-6Ch] BYREF
  _DWORD v7[2]; // [esp+C8h] [ebp-64h] BYREF
  int v8; // [esp+D0h] [ebp-5Ch] BYREF
  int v9; // [esp+D4h] [ebp-58h] BYREF
  int pExceptionObject; // [esp+D8h] [ebp-54h] BYREF
  void *Str; // [esp+DCh] [ebp-50h]
  unsigned int j; // [esp+E0h] [ebp-4Ch]
  unsigned int v13; // [esp+E4h] [ebp-48h] BYREF
  unsigned int i; // [esp+E8h] [ebp-44h]
  _BYTE v15[4]; // [esp+ECh] [ebp-40h] BYREF
  _BYTE v16[4]; // [esp+F0h] [ebp-3Ch] BYREF
  unsigned int a2; // [esp+F8h] [ebp-34h]
  _BYTE v19[28]; // [esp+FCh] [ebp-30h] BYREF
  int *v20; // [esp+11Ch] [ebp-10h]
  int v21; // [esp+128h] [ebp-4h]

  v20 = &v2;
  CTrace::Print("CMapObjectMgr load");
  v9 = 0;
  Str = S4::CMapFile::LoadChunk(arg0, 0xAAu, 0, &v9, 0);
  if ( Str )
  {
    std::string::string((struct std::string *)v19, (char *)Str);
    v21 = 0;
    std::istringstream::istringstream(v19, 1, 1);
    LOBYTE(v21) = 1;
    v4 = std::ios_base::exceptions((char *)v3 + *(_DWORD *)(v3[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), 6);
    LOBYTE(v21) = 2;
    operator^<unsigned int>(v3, &v8);
    v7[1] = v8;
    if ( v8 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMapObjectMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    std::vector<std::deque<unsigned short>>::resize((void **)&this->m_vLogicUpdateSlots, (_DWORD *)0x20);
    this->m_vLogicUpdateListItem = 0;
    std::vector<std::deque<unsigned short>>::resize((void **)&this->unk_14, (_DWORD *)0x20);
    operator^<int>((struct std::istream *)v3, &CMapObjectMgr::m_iMinFreeId);
    operator^<int>((struct std::istream *)v3, &CMapObjectMgr::m_iLastUsedId);
    operator^<int>((struct std::istream *)v3, &CMapObjectMgr::m_iMaxLastUsedId);
    operator^<int>((struct std::istream *)v3, &CMapObjectMgr::m_iCurrentUniqueId);
    operator^<unsigned int>(v3, &CMapObjectMgr::m_uCRCLogicUpdate);
    operator^<unsigned int>(v3, &this->m_vLogicUpdateListItem);
    operator^<unsigned int>(v3, &v13);
    for ( a2 = 0; a2 < v13; ++a2 )
    {
      operator^<unsigned int>(v3, v7);
      for ( i = 0; i < v7[0]; ++i )
      {
        operator^<unsigned short>(v3, v16);
        v6[1] = std::vector<std::deque<unsigned short>>::operator[]((void **)&this->m_vLogicUpdateSlots, a2);
        std::deque<unsigned short>::push_back(v16);
      }
    }
    operator^<unsigned int>(v3, &v13);
    for ( a2 = 0; a2 < v13; ++a2 )
    {
      operator^<unsigned int>(v3, v6);
      for ( j = 0; j < v6[0]; ++j )
      {
        operator^<unsigned short>(v3, v15);
        v5 = std::vector<std::deque<unsigned short>>::operator[]((void **)&this->unk_14, a2);
        std::deque<unsigned short>::push_back(v15);
      }
    }
    v21 = 1;
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), v4);
    LOBYTE(v21) = 0;
    std::istringstream::`vbase destructor'(v3);
    v21 = -1;
    std::string::~string(v19);
  }
}


// address=[0x1557c60]
// Decompiled from int __thiscall CMapObjectMgr::PrintEntity(  CMapObjectMgr *this,  int _iEntityId,  int _iLogLevel,  const char *_sCustomMessage)
void  CMapObjectMgr::PrintEntity(int _iEntityId, int _iLogLevel, char const * _sCustomMessage) {
  
  const char *message; // [esp+4h] [ebp-Ch]
  IEntity *pEntity; // [esp+8h] [ebp-8h]

  if ( _sCustomMessage )
    message = _sCustomMessage;
  else
    message = "CMapObjectMgr::PrintEntity()";
  if ( (unsigned int)_iEntityId >= 0x10000 )
    return BBSupportTracePrintF(_iLogLevel, "%s: Entity id %i out of range!", message, _iEntityId);
  if ( !_iEntityId )
    return BBSupportTracePrintF(_iLogLevel, "%s: Entity id 0 is reserved!", message);
  if ( _iEntityId > CMapObjectMgr::m_iMaxLastUsedId )
    return BBSupportTracePrintF(_iLogLevel, "%s: Entity id %i is > MaxLastUsedId!", message, _iEntityId);
  pEntity = CMapObjectMgr::m_vEntities[_iEntityId];
  if ( pEntity )
    return pEntity->DbgPrint(_iLogLevel, message);
  else
    return BBSupportTracePrintF(_iLogLevel, "%s: Entity id %i is unused!", message, _iEntityId);
}


// address=[0x1557d40]
// Decompiled from int __thiscall CMapObjectMgr::DbgPrintEntity(  CMapObjectMgr *this,  int _iEntityId,  int _iLogLevel,  const char *_sCustomMessage)
void  CMapObjectMgr::DbgPrintEntity(int _iEntityId, int _iLogLevel, char const * _sCustomMessage) {
  
  return CMapObjectMgr::PrintEntity(this, _iEntityId, _iLogLevel, _sCustomMessage);
}


// address=[0x1557d70]
// Decompiled from int __thiscall CMapObjectMgr::PrintAllEntities(CMapObjectMgr *this, int _iLogLevel)
void  CMapObjectMgr::PrintAllEntities(int _iLogLevel) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-200C4h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-200B8h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-200ACh] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-200A0h] BYREF
  int v7; // [esp+34h] [ebp-20094h]
  std::_Iterator_base12 *v8; // [esp+38h] [ebp-20090h]
  std::_Iterator_base12 *v9; // [esp+3Ch] [ebp-2008Ch]
  std::_Iterator_base12 *v10; // [esp+40h] [ebp-20088h]
  std::_Iterator_base12 *v11; // [esp+44h] [ebp-20084h]
  void **p_m_vLogicUpdateSlots; // [esp+48h] [ebp-20080h]
  IEntity *v13; // [esp+4Ch] [ebp-2007Ch]
  unsigned int v14; // [esp+50h] [ebp-20078h]
  const char *v15; // [esp+54h] [ebp-20074h]
  const char *v16; // [esp+58h] [ebp-20070h]
  int v17; // [esp+5Ch] [ebp-2006Ch]
  int _iLastUsedId; // [esp+60h] [ebp-20068h]
  unsigned int v19; // [esp+64h] [ebp-20064h]
  IEntity *pEntity; // [esp+68h] [ebp-20060h]
  int used; // [esp+6Ch] [ebp-2005Ch]
  int alive; // [esp+70h] [ebp-20058h]
  int v23; // [esp+74h] [ebp-20054h]
  int v24; // [esp+78h] [ebp-20050h]
  int v25; // [esp+7Ch] [ebp-2004Ch]
  int i; // [esp+80h] [ebp-20048h]
  unsigned int j; // [esp+84h] [ebp-20044h]
  unsigned int a2; // [esp+88h] [ebp-20040h]
  char v30; // [esp+8Eh] [ebp-2003Ah]
  char v31; // [esp+8Fh] [ebp-20039h]
  int k; // [esp+90h] [ebp-20038h]
  bool v33; // [esp+96h] [ebp-20032h]
  bool v34; // [esp+97h] [ebp-20031h]
  _BYTE v35[65536]; // [esp+98h] [ebp-20030h] BYREF
  _BYTE v36[65536]; // [esp+10098h] [ebp-10030h] BYREF
  char v37[32]; // [esp+20098h] [ebp-30h] BYREF
  int v38; // [esp+200C4h] [ebp-4h]

  p_m_vLogicUpdateSlots = (void **)&this->m_vLogicUpdateSlots;
  _iLastUsedId = CMapObjectMgr::m_iLastUsedId;
  BBSupportTracePrintF(_iLogLevel, "CMapObjectMgr::PrintAllEntities()...");
  BBSupportTracePrintF(_iLogLevel, " Current tick is %u.", g_uDbgTickCounter);
  used = 0;
  alive = 0;
  for ( i = 0; i <= _iLastUsedId; ++i )
  {
    v13 = CMapObjectMgr::m_vEntities[i];
    if ( v13 )
    {
      ++used;
      if ( !IEntity::FlagBits(v13, EntityFlag_Died) )
        ++alive;
    }
  }
  memset(v35, 255, sizeof(v35));
  memset(v36, 0, sizeof(v36));
  for ( a2 = 0; (int)a2 < 32; ++a2 )
  {
    v14 = std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots, a2);
    std::deque<unsigned short>::begin(v6);
    v38 = 0;
    while ( 1 )
    {
      v11 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v4);
      v10 = v11;
      LOBYTE(v38) = 1;
      v31 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v11);
      LOBYTE(v38) = 0;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v4);
      if ( !v31 )
        break;
      v24 = *(unsigned __int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v6);
      if ( (char)v35[v24] != -1 )
        v36[v24] = 1;
      v35[v24] = a2;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v6);
    }
    v38 = -1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v6);
  }
  for ( j = 0; (int)j < 32; ++j )
  {
    v19 = std::vector<std::deque<unsigned short>>::operator[](p_m_vLogicUpdateSlots + 5, j);
    std::deque<unsigned short>::begin(v5);
    v38 = 2;
    while ( 1 )
    {
      v9 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v3);
      v8 = v9;
      LOBYTE(v38) = 3;
      v30 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v9);
      LOBYTE(v38) = 2;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v3);
      if ( !v30 )
        break;
      v23 = *(unsigned __int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v5);
      if ( (char)v35[v23] != -1 )
        v36[v23] = 1;
      v35[v23] = j + 32;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v5);
    }
    v38 = -1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v5);
  }
  BBSupportTracePrintF(
    _iLogLevel,
    " Used: %5i, Alive: %5i, MinFree: %5i, LastUsed: %5i, MaxLastUsed: %5i, UniqueId: %5i, CRC: 0x%08x",
    used,
    alive,
    CMapObjectMgr::m_iMinFreeId,
    CMapObjectMgr::m_iLastUsedId,
    CMapObjectMgr::m_iMaxLastUsedId,
    CMapObjectMgr::m_iCurrentUniqueId,
    CMapObjectMgr::m_uCRCLogicUpdate);
  for ( k = 1; k <= _iLastUsedId; ++k )
  {
    pEntity = CMapObjectMgr::m_vEntities[k];
    if ( pEntity )
    {
      v25 = (char)v35[k];
      if ( v25 >= 0 )
      {
        v33 = v25 >= 32;
        v34 = v25 >= 32;
        if ( v25 < 32 )
          v17 = v25;
        else
          v17 = v25 - 32;
        v7 = v17;
        if ( v36[k] )
          v16 = "#";
        else
          v16 = "+";
        if ( v34 )
          v15 = "d";
        else
          v15 = "s";
        snprintf(v37, 0x20u, " %05i[%s%02i%s]", k, v15, v7, v16);
      }
      else
      {
        snprintf(v37, 0x20u, " %05i[----]", k);
      }
      pEntity->DbgPrint(_iLogLevel, v37);
    }
  }
  return BBSupportTracePrintF(_iLogLevel, "CMapObjectMgr::PrintAllEntities(): End of entity dump.");
}


// address=[0x15582e0]
// Decompiled from int __thiscall CMapObjectMgr::DbgPrintAllEntities(CMapObjectMgr *this, int a2)
void  CMapObjectMgr::DbgPrintAllEntities(int a2) {
  
  return CMapObjectMgr::PrintAllEntities(this, a2);
}


// address=[0x1558cb0]
// Decompiled from struct SGfxObjectInfo *__thiscall CMapObjectMgr::GetGfxInfo(CMapObjectMgr *this, unsigned int _iId, int a3)
struct SGfxObjectInfo *  CMapObjectMgr::GetGfxInfo(int _iId, int a3) {
  
  if ( !CMapObjectMgr::ValidUsedEntityId(_iId)
    && BBSupportDbgReport(2, string__2, 205, "ValidUsedEntityId( _iId )") == 1 )
  {
    __debugbreak();
  }
  return CMapObjectMgr::m_vEntities[_iId]->GetGfxInfos();
}


// address=[0x3d8bba4]
// [Decompilation failed for static int CMapObjectMgr::m_iMinFreeId]

// address=[0x3d8bba8]
// [Decompilation failed for static int CMapObjectMgr::m_iCurrentUniqueId]

// address=[0x3d8bbac]
// [Decompilation failed for static unsigned int CMapObjectMgr::m_uCRCLogicUpdate]

// address=[0x4105380]
// [Decompilation failed for static int CMapObjectMgr::m_iLastUsedId]

// address=[0x4105384]
// [Decompilation failed for static int CMapObjectMgr::m_iMaxLastUsedId]

// address=[0x4105388]
// [Decompilation failed for static class IEntity * * CMapObjectMgr::m_vEntities]

#endif // Already implemented
