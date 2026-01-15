#include "CMapObjectMgr.h"

// Definitions for class CMapObjectMgr

// address=[0x12fd030]
// Decompiled from IEntity *__cdecl CMapObjectMgr::EntityPtr(int a1)
static class IEntity * __cdecl CMapObjectMgr::EntityPtr(int) {
  
  if ( !CMapObjectMgr::ValidEntityId(a1) && BBSupportDbgReport(2, string__2, 212, "ValidEntityId( _iId )") == 1 )
    __debugbreak();
  return CMapObjectMgr::m_vEntities[a1];
}


// address=[0x12fd860]
// Decompiled from bool __cdecl CMapObjectMgr::ValidEntityId(unsigned int a1)
static bool __cdecl CMapObjectMgr::ValidEntityId(int) {
  
  return a1 <= CMapObjectMgr::m_iMaxLastUsedId;
}


// address=[0x13094c0]
// Decompiled from int __cdecl CMapObjectMgr::Entity(int a1)
static class IEntity & __cdecl CMapObjectMgr::Entity(int) {
  
  if ( !CMapObjectMgr::ValidUsedEntityId(a1) && BBSupportDbgReport(2, string__2, 228, "ValidUsedEntityId( _iId )") == 1 )
    __debugbreak();
  return CMapObjectMgr::m_vEntities[a1];
}


// address=[0x13096b0]
// Decompiled from bool __cdecl CMapObjectMgr::ValidUsedEntityId(unsigned int a1)
static bool __cdecl CMapObjectMgr::ValidUsedEntityId(int) {
  
  return a1 <= CMapObjectMgr::m_iLastUsedId && CMapObjectMgr::m_vEntities[a1];
}


// address=[0x130ee70]
// Decompiled from int __cdecl CMapObjectMgr::GetUniqueId(unsigned int a1)
static int __cdecl CMapObjectMgr::GetUniqueId(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  if ( !CMapObjectMgr::ValidEntityId(a1) && BBSupportDbgReport(2, string__2, 257, "ValidEntityId( _iId )") == 1 )
    __debugbreak();
  v3 = CMapObjectMgr::m_vEntities[a1];
  if ( v3 )
    return *(_DWORD *)(v3 + 4);
  else
    return 0;
}


// address=[0x130f140]
// Decompiled from void **__cdecl CMapObjectMgr::MovingEntity(int a1)
static class IMovingEntity & __cdecl CMapObjectMgr::MovingEntity(int) {
  
  void **v2; // [esp+0h] [ebp-4h]

  if ( !CMapObjectMgr::ValidUsedEntityId(a1) && BBSupportDbgReport(2, string__2, 246, "ValidUsedEntityId( _iId )") == 1 )
    __debugbreak();
  v2 = (void **)CMapObjectMgr::m_vEntities[a1];
  if ( !j____RTDynamicCast(v2, 0, &IEntity__RTTI_Type_Descriptor_, &IMovingEntity__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(2, string__2, 250, "dynamic_cast<IMovingEntity*>( pEntity ) != 0") == 1 )
  {
    __debugbreak();
  }
  return v2;
}


// address=[0x1439c10]
// Decompiled from int CMapObjectMgr::LastUsedId()
static int __cdecl CMapObjectMgr::LastUsedId(void) {
  
  return CMapObjectMgr::m_iLastUsedId;
}


// address=[0x14aaa30]
// Decompiled from int CMapObjectMgr::CRCLogicUpdate()
static unsigned int __cdecl CMapObjectMgr::CRCLogicUpdate(void) {
  
  return CMapObjectMgr::m_uCRCLogicUpdate;
}


// address=[0x15560f0]
// Decompiled from CMapObjectMgr *__thiscall CMapObjectMgr::CMapObjectMgr(CMapObjectMgr *this)
 CMapObjectMgr::CMapObjectMgr(void) {
  
  int FreeSlot; // eax
  int v2; // eax
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

  std::vector<std::deque<unsigned short>>::vector<std::deque<unsigned short>>();
  std::vector<std::deque<unsigned short>>::vector<std::deque<unsigned short>>();
  memset(CMapObjectMgr::m_vEntities, 0, 0x40000u);
  CMapObjectMgr::m_iMinFreeId = 1;
  CMapObjectMgr::m_iLastUsedId = 0;
  CMapObjectMgr::m_iMaxLastUsedId = 0;
  CMapObjectMgr::m_iCurrentUniqueId = 1;
  v13 = (CSettler *)CSettler::operator new(0x68u);
  if ( v13 )
  {
    FreeSlot = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v13, 68, FreeSlot);
  }
  v12 = (CSettler *)CSettler::operator new(0x68u);
  if ( v12 )
  {
    v2 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v12, 68, v2);
  }
  v11 = (CSettler *)CSettler::operator new(0x68u);
  if ( v11 )
  {
    v3 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v11, 68, v3);
  }
  v10 = (CSettler *)CSettler::operator new(0x68u);
  if ( v10 )
  {
    v4 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v10, 68, v4);
  }
  v9 = (CSettler *)CSettler::operator new(0x68u);
  if ( v9 )
  {
    v5 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v9, 68, v5);
  }
  v8 = (CSettler *)CSettler::operator new(0x68u);
  if ( v8 )
  {
    v6 = CMapObjectMgr::GetFreeSlot();
    CSettler::CSettler(v8, 68, v6);
  }
  std::vector<std::deque<unsigned short>>::resize(32);
  *((_DWORD *)this + 4) = 0;
  std::vector<std::deque<unsigned short>>::resize(32);
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
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)CMapObjectMgr::m_vEntities[i] + 8))(
        CMapObjectMgr::m_vEntities[i],
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
  std::vector<std::deque<unsigned short>>::clear();
  std::vector<std::deque<unsigned short>>::clear();
  CMapObjectMgr::m_iMinFreeId = 1;
  CMapObjectMgr::m_iLastUsedId = 0;
  CMapObjectMgr::m_iMaxLastUsedId = 0;
  CMapObjectMgr::m_iCurrentUniqueId = 1;
  std::vector<std::deque<unsigned short>>::~vector<std::deque<unsigned short>>();
  return std::vector<std::deque<unsigned short>>::~vector<std::deque<unsigned short>>();
}


// address=[0x15564b0]
// Decompiled from int CMapObjectMgr::GetFreeSlot()
static int __cdecl CMapObjectMgr::GetFreeSlot(void) {
  
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
// Decompiled from int __cdecl CMapObjectMgr::RegisterEntity(int a1, struct IEntity *pEntity, bool a3)
static void __cdecl CMapObjectMgr::RegisterEntity(int,class IEntity *,bool) {
  
  int result; // eax

  if ( !pEntity && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 381, "_pEntity != NULL") == 1 )
    __debugbreak();
  if ( (a1 <= 0 || a1 >= 0xFFFF)
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 382, "_iId>0 && _iId<MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( CMapObjectMgr::m_vEntities[a1]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 383, "m_vEntities[ _iId ] == NULL") == 1 )
  {
    __debugbreak();
  }
  if ( a3 )
  {
    if ( pEntity->m_iUniqueId != -1
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
    pEntity->m_iUniqueId = CMapObjectMgr::m_iCurrentUniqueId++;
  }
  else if ( (int)pEntity->m_iUniqueId <= 0
         && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 397, "_pEntity->m_iUniqueId > 0") == 1 )
  {
    __debugbreak();
  }
  result = a1;
  if ( a1 > CMapObjectMgr::m_iLastUsedId )
  {
    CMapObjectMgr::m_iLastUsedId = a1;
    if ( a1 > CMapObjectMgr::m_iMaxLastUsedId )
    {
      result = a1;
      CMapObjectMgr::m_iMaxLastUsedId = a1;
    }
  }
  CMapObjectMgr::m_vEntities[a1] = pEntity;
  return result;
}


// address=[0x1556710]
// Decompiled from int __cdecl CMapObjectMgr::AssignNewUniqueId(int a1)
static void __cdecl CMapObjectMgr::AssignNewUniqueId(int) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-4h]

  if ( a1 <= 0 || a1 >= 0xFFFF )
    return result;
  result = a1;
  v2 = CMapObjectMgr::m_vEntities[a1];
  if ( !v2 )
    return result;
  result = *(_DWORD *)(v2 + 4) & 0x20000000;
  if ( result )
    return result;
  *(_DWORD *)(v2 + 4) = CMapObjectMgr::m_iCurrentUniqueId;
  return ++CMapObjectMgr::m_iCurrentUniqueId;
}


// address=[0x1556760]
// Decompiled from void __thiscall CMapObjectMgr::Kill(_DWORD *this, int entityId, int attacker)
void  CMapObjectMgr::Kill(int,int) {
  
  int v3; // eax
  int v4; // [esp-Ch] [ebp-38h]
  int type; // [esp-8h] [ebp-34h]
  unsigned int v6; // [esp+0h] [ebp-2Ch]
  CAIEntityInfo *AIEntityInfoPtr; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+14h] [ebp-18h]
  int v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+20h] [ebp-Ch]
  IEntity *entity; // [esp+24h] [ebp-8h]
  __int16 v14; // [esp+2Ah] [ebp-2h] BYREF

  if ( (entityId <= 0 || entityId >= 0xFFFF)
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 449, "_iEntityId>0 && _iEntityId<MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( !CMapObjectMgr::m_vEntities[entityId]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 450, "m_vEntities[ _iEntityId ] != 0") == 1 )
  {
    __debugbreak();
  }
  entity = CMapObjectMgr::m_vEntities[entityId];
  type = IEntity::Type(entity);
  v4 = IEntity::ObjType(entity);
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CMapObjectMgr::Kill(): id %u, type %u / %u, attacker %i",
    entityId,
    v4,
    type,
    (char *)attacker);
  if ( (entity->m_iUniqueId & 0x20000000) != 0 )
  {
    if ( IEntity::FlagBits(entity, AliveMask)
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 460, "pEntity->FlagBits(ENTITY_FLAG_ALIVE_MASK) == 0") == 1 )
    {
      __debugbreak();
    }
    if ( !IEntity::FlagBits(entity, Died)
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 461, "pEntity->FlagBits(ENTITY_FLAG_DIED) != 0") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    entity->m_iUniqueId |= 0x20000000u;
    if ( IEntity::FlagBits(entity, Died)
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 468, "pEntity->FlagBits(ENTITY_FLAG_DIED) == 0") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::FlagBits(entity, Birth) )
      IEntity::SetFlagBits(entity, (EntityFlag)0x100000u);
    else
      IEntity::ClearFlagBits(entity, (EntityFlag)0x100000u);
    IEntity::ClearFlagBits(entity, AliveMask);
    IEntity::SetFlagBits(entity, Died);
    if ( CWarMapNode::IsInWarMap(&entity->m_warMapNode) )
      CWarMap::RemoveEntity(entity);
    if ( IEntity::FlagBits(entity, Selected) || IEntity::FlagBits(entity, (EntityFlag)0x400u) )
    {
      v3 = IEntity::ID(entity);
      CInputProcessor::DeSelectEntity(&g_cInputProcessor, v3);
    }
    if ( ((int (__stdcall *)())entity->GetGroupFlags)() )
      (*(void (__thiscall **)(CGroupMgr::TStaticArray100short (*)[], int))(*(_DWORD *)g_pGroupMgr + 28))(
        g_pGroupMgr,
        entityId);
    if ( attacker > 0 )
    {
      v9 = IEntity::OwnerId(entity);
      v11 = IEntity::ObjType(entity);
      v12 = IEntity::Type(entity);
      if ( v11 == 1 )
      {
        CStatistic::IncKillsOfType(attacker, v12);
        CStatistic::IncLossesOfType((CStatistic *)&g_cStatistic, v9, v12);
      }
      if ( v11 == 2 || v11 == 4 )
      {
        CStatistic::IncKillsVehicleOfType((CStatistic *)&g_cStatistic, attacker, v12);
        CStatistic::IncLossesVehicleOfType((CStatistic *)&g_cStatistic, v9, v12);
      }
    }
    if ( entity->m_psAIEntityInfo )
    {
      AIEntityInfoPtr = entity->m_psAIEntityInfo;
      if ( AIEntityInfoPtr )
        delete AIEntityInfoPtr;
      entity->m_psAIEntityInfo = 0;
    }
    ((void (__thiscall *)(IEntity *))entity->j_?Delete@IEntity@@UAEXXZ)(entity);
    v10 = j____RTDynamicCast(
            (void **)&entity->__vftable,
            0,
            &IEntity__RTTI_Type_Descriptor_,
            &IAnimatedEntity__RTTI_Type_Descriptor_,
            0);
    if ( v10 )
    {
      if ( IAnimatedEntity::Previous(v10)
        && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 548, "pAnimatedEntity->Previous() == 0") == 1 )
      {
        __debugbreak();
      }
      if ( IAnimatedEntity::Next(v10)
        && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 549, "pAnimatedEntity->Next() == 0") == 1 )
      {
        __debugbreak();
      }
    }
    v6 = (this[4] + 31) % 0x20u;
    v14 = entityId;
    std::vector<std::deque<unsigned short>>::operator[](v6);
    std::deque<unsigned short>::push_front((int)&v14);
  }
}


// address=[0x1556b00]
// Decompiled from int __thiscall CMapObjectMgr::Destroy(CMapObjectMgr *this, int a2)
void  CMapObjectMgr::Destroy(int) {
  
  int result; // eax
  unsigned __int16 *v3; // [esp+14h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 0xFFFF)
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 566, "_iEntityId>0 && _iEntityId<MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( !CMapObjectMgr::m_vEntities[a2]
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 567, "m_vEntities[ _iEntityId ] != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = (unsigned __int16 *)CMapObjectMgr::m_vEntities[a2];
  if ( v3[4] != a2 && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 571, "pEntity->m_uID == _iEntityId") == 1 )
    __debugbreak();
  if ( v3 )
    (*(void (__thiscall **)(unsigned __int16 *, int))(*(_DWORD *)v3 + 8))(v3, 1);
  CMapObjectMgr::m_vEntities[a2] = 0;
  if ( a2 < CMapObjectMgr::m_iMinFreeId )
    CMapObjectMgr::m_iMinFreeId = a2;
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
  result = i;
  CMapObjectMgr::m_iLastUsedId = i;
  return result;
}


// address=[0x1556cb0]
// Decompiled from CMapObjectMgr *__thiscall CMapObjectMgr::LogicUpdate(CMapObjectMgr *this)
void  CMapObjectMgr::LogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  CMapObjectMgr *result; // eax
  int v5; // [esp-4h] [ebp-8E0h]
  int v6; // [esp-4h] [ebp-8E0h]
  int v7; // [esp+0h] [ebp-8DCh]
  int v8; // [esp+4h] [ebp-8D8h]
  int v9; // [esp+8h] [ebp-8D4h]
  unsigned int v10; // [esp+18h] [ebp-8C4h]
  int v11; // [esp+1Ch] [ebp-8C0h]
  int v12; // [esp+20h] [ebp-8BCh]
  int v13; // [esp+24h] [ebp-8B8h]
  int v14; // [esp+28h] [ebp-8B4h]
  int v15; // [esp+30h] [ebp-8ACh]
  int i; // [esp+34h] [ebp-8A8h]
  int v17; // [esp+38h] [ebp-8A4h]
  int k; // [esp+3Ch] [ebp-8A0h]
  int j; // [esp+40h] [ebp-89Ch]
  int m; // [esp+44h] [ebp-898h]
  void **v21; // [esp+48h] [ebp-894h]
  int v22; // [esp+4Ch] [ebp-890h]
  int v24; // [esp+54h] [ebp-888h]
  _DWORD v25[32]; // [esp+58h] [ebp-884h] BYREF
  _WORD v26[1024]; // [esp+D8h] [ebp-804h] BYREF

  v24 = std::vector<std::deque<unsigned short>>::operator[](*((_DWORD *)this + 4));
  v9 = CMapObjectMgr::m_uCRCLogicUpdate;
  v11 = CMapObjectMgr::m_uCRCLogicUpdate;
  v12 = CMapObjectMgr::m_uCRCLogicUpdate;
  if ( std::deque<unsigned short>::size(v24) )
  {
    v7 = 1024;
    v13 = std::deque<unsigned short>::size(v24);
    v22 = 0;
    for ( i = 0; i < v13 / 1024; ++i )
    {
      for ( j = 0; j < 1024; ++j )
        v26[j] = *(_WORD *)std::deque<unsigned short>::operator[](v22++);
      CMapObjectMgr::m_uCRCLogicUpdate = Adler32(v26, 0x800u, CMapObjectMgr::m_uCRCLogicUpdate);
    }
    v11 = CMapObjectMgr::m_uCRCLogicUpdate;
    v15 = v13 % 1024;
    if ( v13 % 1024 > 0 )
    {
      for ( k = 0; k < v15; ++k )
        v26[k] = *(_WORD *)std::deque<unsigned short>::operator[](v22++);
      CMapObjectMgr::m_uCRCLogicUpdate = Adler32(v26, 2 * v15, CMapObjectMgr::m_uCRCLogicUpdate);
    }
    v12 = CMapObjectMgr::m_uCRCLogicUpdate;
  }
  for ( m = 0; m < 32; ++m )
  {
    v1 = std::vector<std::deque<unsigned short>>::operator[](m);
    v25[m] = std::deque<unsigned short>::size(v1);
  }
  CMapObjectMgr::m_uCRCLogicUpdate = Adler32(v25, 0x80u, CMapObjectMgr::m_uCRCLogicUpdate);
  v5 = CMapObjectMgr::m_uCRCLogicUpdate;
  v2 = std::deque<unsigned short>::size(v24);
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "CMapObjectMgr::LogicUpdate(): size %u, CRCs 0x%08x, 0x%08x, 0x%08x, 0x%08x",
    v2,
    v9,
    v11,
    v12,
    v5);
  while ( !(unsigned __int8)std::deque<unsigned short>::empty(v24) )
  {
    v17 = *(unsigned __int16 *)std::deque<unsigned short>::front(v7, v8);
    if ( ((unsigned __int8)std::deque<unsigned short>::empty(v24) || !*(_WORD *)std::deque<unsigned short>::front(
                                                                                  v7,
                                                                                  v8))
      && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 781, "q.empty() == false && 0 != q.front()") == 1 )
    {
      __debugbreak();
    }
    std::deque<unsigned short>::pop_front(v24);
    v21 = (void **)CMapObjectMgr::EntityPtr(v17);
    if ( v21 )
    {
      if ( IEntity::ID() != v17
        && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 795, "pEntity->ID() == iEntityId") == 1 )
      {
        __debugbreak();
      }
      if ( !j____RTDynamicCast(v21, 0, &IEntity__RTTI_Type_Descriptor_, &IAnimatedEntity__RTTI_Type_Descriptor_, 0)
        && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 796, "dynamic_cast<IAnimatedEntity*>(pEntity) != 0") == 1 )
      {
        __debugbreak();
      }
      IEntity::ClearFlagBits(v21, Registered);
      v6 = IEntity::Type((unsigned __int16 *)v21);
      v3 = IEntity::ObjType((unsigned __int8 *)v21);
      IMessageTracer::PushFormatedInts(
        (IMessageTracer *)g_pMsgTracer,
        "LogicUpdate(): id %u, type %u / %u",
        v17,
        v3,
        v6);
      (*((void (__thiscall **)(void **))*v21 + 25))(v21);
    }
    else
    {
      BBSupportTracePrintF(
        3,
        "### CMapObjectMgr::LogicUpdate(): EntityPtr for entity id %i in list %i is NULL! ###",
        v17,
        *((_DWORD *)this + 4));
    }
  }
  v14 = std::vector<std::deque<unsigned short>>::operator[](*((_DWORD *)this + 4));
  while ( !(unsigned __int8)std::deque<unsigned short>::empty(v14) )
  {
    v8 = *(unsigned __int16 *)std::deque<unsigned short>::front(v7, v8);
    std::deque<unsigned short>::pop_front(v14);
    CMapObjectMgr::Destroy(this, v8);
  }
  v10 = *((_DWORD *)this + 4) + 1;
  *((_DWORD *)this + 4) = v10;
  result = this;
  *((_DWORD *)this + 4) = v10 % 0x20;
  return result;
}


// address=[0x15571c0]
// Decompiled from unsigned int __thiscall CMapObjectMgr::RegisterForLogicUpdate(CMapObjectMgr *this, int a2, const char *a3)
int  CMapObjectMgr::RegisterForLogicUpdate(int,int) {
  
  int v3; // eax
  int v4; // eax
  unsigned int LastLogicUpdateTick; // eax
  int v7; // [esp-8h] [ebp-1Ch]
  int v8; // [esp-8h] [ebp-1Ch]
  unsigned int v9; // [esp+4h] [ebp-10h]
  IEntity *v11; // [esp+Ch] [ebp-8h]
  __int16 v12; // [esp+12h] [ebp-2h] BYREF

  if ( (a2 <= 0 || a2 >= 32)
    && BBSupportDbgReport(
         2,
         "MapObjects\\MapObjectMgr.cpp",
         847,
         "(0 < _iDeltaTicks) && (_iDeltaTicks < MAX_LOGIC_UPDATE_SLOTS)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 > 0 )
  {
    if ( a2 >= 32 )
      a2 = 31;
  }
  else
  {
    a2 = 1;
  }
  v9 = (a2 + *((_DWORD *)this + 4)) % 0x20u;
  v11 = CMapObjectMgr::EntityPtr((int)a3);
  if ( IMessageTracer::RemoveCurrentMsgIfEqual((const char **)g_pMsgTracer, "LogicUpdate(): id %u, type %u / %u", a3) )
  {
    v7 = IEntity::Type(v11);
    v3 = IEntity::ObjType(v11);
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer,
      "LogicUpdate() + RegisterForLogicUpdate(): id %u, type %u / %u, delta ticks %u",
      (int)a3,
      v3,
      v7,
      (char *)a2);
  }
  else
  {
    v8 = IEntity::Type(v11);
    v4 = IEntity::ObjType(v11);
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer,
      "RegisterForLogicUpdate(): id %u, type %u / %u, delta ticks %u",
      (int)a3,
      v4,
      v8,
      (char *)a2);
  }
  if ( IEntity::FlagBits(v11, (EntityFlag)&unk_4000000)
    && BBSupportDbgReport(2, "MapObjects\\MapObjectMgr.cpp", 874, "pEntity->FlagBits(ENTITY_FLAG_DIED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::GetLastLogicUpdateTick((CPaneContainer *)v11) != -1
    && IAnimatedEntity::GetLastLogicUpdateTick((CPaneContainer *)v11) != *((_DWORD *)this + 4) )
  {
    LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick((CPaneContainer *)v11);
    CMapObjectMgr::UnRegisterFromLogicUpdate(this, LastLogicUpdateTick, (int)a3);
  }
  v12 = (__int16)a3;
  std::vector<std::deque<unsigned short>>::operator[](v9);
  std::deque<unsigned short>::push_front((int)&v12);
  IEntity::SetFlagBits(v11, Registered);
  return v9;
}


// address=[0x1557350]
// Decompiled from void __thiscall CMapObjectMgr::UnRegisterFromLogicUpdate(CMapObjectMgr *this, unsigned int a2, int a3)
void  CMapObjectMgr::UnRegisterFromLogicUpdate(int,int) {
  
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
  _DWORD *v13; // [esp+40h] [ebp-24h]
  int v14; // [esp+44h] [ebp-20h]
  std::_Iterator_base12 *v15; // [esp+48h] [ebp-1Ch]
  std::_Iterator_base12 *v16; // [esp+4Ch] [ebp-18h]
  CMapObjectMgr *v17; // [esp+50h] [ebp-14h]
  char v18; // [esp+57h] [ebp-Dh]
  int v19; // [esp+60h] [ebp-4h]

  v17 = this;
  if ( a2 < 0x20 )
  {
    std::vector<std::deque<unsigned short>>::operator[](a2);
    std::deque<unsigned short>::begin(v9);
    v19 = 0;
    while ( 1 )
    {
      std::vector<std::deque<unsigned short>>::operator[](a2);
      v16 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v8);
      v15 = v16;
      LOBYTE(v19) = 1;
      v18 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v16);
      LOBYTE(v19) = 0;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v8);
      if ( !v18 )
        break;
      if ( *(unsigned __int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v9) == a3 )
      {
        v12 = &v3;
        v14 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>((struct std::_Iterator_base12 *)v9);
        v11 = v14;
        LOBYTE(v19) = 2;
        std::vector<std::deque<unsigned short>>::operator[](a2);
        LOBYTE(v19) = 0;
        v10 = std::deque<unsigned short>::erase(v7, v3, v4, v5);
        std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v7);
        v13 = (_DWORD *)CMapObjectMgr::EntityPtr(a3);
        IEntity::ClearFlagBits(v13, Registered);
        v19 = -1;
        std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v9);
        return;
      }
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v6, 0);
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v6);
    }
    v19 = -1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v9);
  }
}


// address=[0x15574c0]
// Decompiled from void __thiscall CMapObjectMgr::Store(CMapObjectMgr *this, struct S4::CMapFile *a2)
void  CMapObjectMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-160h] BYREF
  _DWORD v5[42]; // [esp+10h] [ebp-150h] BYREF
  _BYTE v6[12]; // [esp+B8h] [ebp-A8h] BYREF
  _BYTE v7[12]; // [esp+C4h] [ebp-9Ch] BYREF
  int v8; // [esp+D0h] [ebp-90h]
  _BYTE v9[12]; // [esp+D4h] [ebp-8Ch] BYREF
  _BYTE v10[12]; // [esp+E0h] [ebp-80h] BYREF
  unsigned int v11; // [esp+ECh] [ebp-74h]
  size_t Size; // [esp+F0h] [ebp-70h]
  void *Src; // [esp+F4h] [ebp-6Ch]
  __int16 *v14; // [esp+F8h] [ebp-68h]
  std::_Iterator_base12 *v15; // [esp+FCh] [ebp-64h]
  std::_Iterator_base12 *v16; // [esp+100h] [ebp-60h]
  int v17; // [esp+104h] [ebp-5Ch]
  int v18; // [esp+108h] [ebp-58h]
  int v19; // [esp+10Ch] [ebp-54h] BYREF
  int v20; // [esp+110h] [ebp-50h]
  __int16 *v21; // [esp+114h] [ebp-4Ch]
  std::_Iterator_base12 *v22; // [esp+118h] [ebp-48h]
  std::_Iterator_base12 *v23; // [esp+11Ch] [ebp-44h]
  int v24; // [esp+120h] [ebp-40h]
  int v25; // [esp+124h] [ebp-3Ch]
  int v26; // [esp+128h] [ebp-38h] BYREF
  int v27; // [esp+12Ch] [ebp-34h]
  int v28; // [esp+130h] [ebp-30h] BYREF
  __int16 v29; // [esp+138h] [ebp-28h] BYREF
  __int16 v30; // [esp+13Ch] [ebp-24h] BYREF
  int v31; // [esp+140h] [ebp-20h] BYREF
  CMapObjectMgr *v32; // [esp+144h] [ebp-1Ch]
  char v33; // [esp+148h] [ebp-18h]
  char v34; // [esp+149h] [ebp-17h]
  char v35; // [esp+14Ah] [ebp-16h]
  char v36; // [esp+14Bh] [ebp-15h]
  unsigned int i; // [esp+14Ch] [ebp-14h]
  int *v38; // [esp+150h] [ebp-10h]
  int v39; // [esp+15Ch] [ebp-4h]

  v38 = &v4;
  v32 = this;
  v8 = 262400;
  std::ostrstream::ostrstream(0, 262400, 0, 2, 1);
  v39 = 0;
  v11 = std::ios_base::exceptions((char *)v5 + *(_DWORD *)(v5[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v39) = 1;
  v28 = 1;
  operator^<unsigned int>((struct std::ostream *)v5, &v28);
  operator^<int>((int)v5, &CMapObjectMgr::m_iMinFreeId);
  operator^<int>((int)v5, &CMapObjectMgr::m_iLastUsedId);
  operator^<int>((int)v5, &CMapObjectMgr::m_iMaxLastUsedId);
  operator^<int>((int)v5, &CMapObjectMgr::m_iCurrentUniqueId);
  operator^<unsigned int>((struct std::ostream *)v5, &CMapObjectMgr::m_uCRCLogicUpdate);
  operator^<unsigned int>((struct std::ostream *)v5, (int *)v32 + 4);
  v31 = 32;
  operator^<unsigned int>((struct std::ostream *)v5, &v31);
  for ( i = 0; i < v31; ++i )
  {
    v27 = std::vector<std::deque<unsigned short>>::operator[](i);
    v26 = std::deque<unsigned short>::size(v27);
    operator^<unsigned int>((struct std::ostream *)v5, &v26);
    v25 = std::vector<std::deque<unsigned short>>::operator[](i);
    std::deque<unsigned short>::begin(v10);
    LOBYTE(v39) = 2;
    while ( 1 )
    {
      v24 = std::vector<std::deque<unsigned short>>::operator[](i);
      v23 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v7);
      v22 = v23;
      LOBYTE(v39) = 3;
      v36 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v23);
      v35 = v36;
      LOBYTE(v39) = 2;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v7);
      if ( !v35 )
        break;
      v21 = (__int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v10);
      v30 = *v21;
      operator^<unsigned short>((int)v5, &v30);
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v10);
    }
    LOBYTE(v39) = 1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v10);
  }
  operator^<unsigned int>((struct std::ostream *)v5, &v31);
  for ( i = 0; i < v31; ++i )
  {
    v20 = std::vector<std::deque<unsigned short>>::operator[](i);
    v19 = std::deque<unsigned short>::size(v20);
    operator^<unsigned int>((struct std::ostream *)v5, &v19);
    v18 = std::vector<std::deque<unsigned short>>::operator[](i);
    std::deque<unsigned short>::begin(v9);
    LOBYTE(v39) = 4;
    while ( 1 )
    {
      v17 = std::vector<std::deque<unsigned short>>::operator[](i);
      v16 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v6);
      v15 = v16;
      LOBYTE(v39) = 5;
      v34 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v16);
      v33 = v34;
      LOBYTE(v39) = 4;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v6);
      if ( !v33 )
        break;
      v14 = (__int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v9);
      v29 = *v14;
      operator^<unsigned short>((int)v5, &v29);
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v9);
    }
    LOBYTE(v39) = 1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v9);
  }
  std::ostream::put(0);
  v39 = 0;
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(170, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), v11);
  v39 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x1557910]
// Decompiled from void __thiscall CMapObjectMgr::Load(CMapObjectMgr *this, struct S4::CMapFile *a2)
void  CMapObjectMgr::Load(class S4::CMapFile &) {
  
  int v2; // [esp+0h] [ebp-12Ch] BYREF
  _DWORD v3[42]; // [esp+10h] [ebp-11Ch] BYREF
  unsigned int v4; // [esp+B8h] [ebp-74h]
  int v5; // [esp+BCh] [ebp-70h]
  _DWORD v6[2]; // [esp+C0h] [ebp-6Ch] BYREF
  _DWORD v7[2]; // [esp+C8h] [ebp-64h] BYREF
  int v8; // [esp+D0h] [ebp-5Ch] BYREF
  int v9; // [esp+D4h] [ebp-58h] BYREF
  int pExceptionObject; // [esp+D8h] [ebp-54h] BYREF
  char *Str; // [esp+DCh] [ebp-50h]
  unsigned int k; // [esp+E0h] [ebp-4Ch]
  unsigned int v13; // [esp+E4h] [ebp-48h] BYREF
  unsigned int j; // [esp+E8h] [ebp-44h]
  _BYTE v15[4]; // [esp+ECh] [ebp-40h] BYREF
  _BYTE v16[4]; // [esp+F0h] [ebp-3Ch] BYREF
  CMapObjectMgr *v17; // [esp+F4h] [ebp-38h]
  unsigned int i; // [esp+F8h] [ebp-34h]
  _BYTE v19[28]; // [esp+FCh] [ebp-30h] BYREF
  int *v20; // [esp+11Ch] [ebp-10h]
  int v21; // [esp+128h] [ebp-4h]

  v20 = &v2;
  v17 = this;
  CTrace::Print("CMapObjectMgr load");
  v9 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xAAu, 0, &v9, 0);
  if ( Str )
  {
    std::string::string(v19, Str);
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
    std::vector<std::deque<unsigned short>>::resize(32);
    *((_DWORD *)v17 + 4) = 0;
    std::vector<std::deque<unsigned short>>::resize(32);
    operator^<int>((int)v3, (int)&CMapObjectMgr::m_iMinFreeId);
    operator^<int>((int)v3, (int)&CMapObjectMgr::m_iLastUsedId);
    operator^<int>((int)v3, (int)&CMapObjectMgr::m_iMaxLastUsedId);
    operator^<int>((int)v3, (int)&CMapObjectMgr::m_iCurrentUniqueId);
    operator^<unsigned int>(v3, &CMapObjectMgr::m_uCRCLogicUpdate);
    operator^<unsigned int>(v3, (char *)v17 + 16);
    operator^<unsigned int>(v3, &v13);
    for ( i = 0; i < v13; ++i )
    {
      operator^<unsigned int>(v3, v7);
      for ( j = 0; j < v7[0]; ++j )
      {
        operator^<unsigned short>(v3, v16);
        v6[1] = std::vector<std::deque<unsigned short>>::operator[](i);
        std::deque<unsigned short>::push_back(v16);
      }
    }
    operator^<unsigned int>(v3, &v13);
    for ( i = 0; i < v13; ++i )
    {
      operator^<unsigned int>(v3, v6);
      for ( k = 0; k < v6[0]; ++k )
      {
        operator^<unsigned short>(v3, v15);
        v5 = std::vector<std::deque<unsigned short>>::operator[](i);
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
// Decompiled from int __thiscall CMapObjectMgr::PrintEntity(CMapObjectMgr *this, int entityId, int logLevel, const char *customMessage)
void  CMapObjectMgr::PrintEntity(int,int,char const *) {
  
  const char *message; // [esp+4h] [ebp-Ch]
  IEntity *v6; // [esp+8h] [ebp-8h]

  if ( customMessage )
    message = customMessage;
  else
    message = "CMapObjectMgr::PrintEntity()";
  if ( (unsigned int)entityId >= 0x10000 )
    return BBSupportTracePrintF(logLevel, "%s: Entity id %i out of range!", message, entityId);
  if ( !entityId )
    return BBSupportTracePrintF(logLevel, "%s: Entity id 0 is reserved!", message);
  if ( entityId > CMapObjectMgr::m_iMaxLastUsedId )
    return BBSupportTracePrintF(logLevel, "%s: Entity id %i is > MaxLastUsedId!", message, entityId);
  v6 = CMapObjectMgr::m_vEntities[entityId];
  if ( v6 )
    return v6->DbgPrint(v6, logLevel, message);
  else
    return BBSupportTracePrintF(logLevel, "%s: Entity id %i is unused!", message, entityId);
}


// address=[0x1557d40]
// Decompiled from int __thiscall CMapObjectMgr::DbgPrintEntity(CMapObjectMgr *this, int a2, int a3, const char *a4)
void  CMapObjectMgr::DbgPrintEntity(int,int,char const *) {
  
  return CMapObjectMgr::PrintEntity(this, a2, a3, a4);
}


// address=[0x1557d70]
// Decompiled from int __thiscall CMapObjectMgr::PrintAllEntities(CMapObjectMgr *this, int a2)
void  CMapObjectMgr::PrintAllEntities(int) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-200C4h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-200B8h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-200ACh] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-200A0h] BYREF
  int v7; // [esp+34h] [ebp-20094h]
  std::_Iterator_base12 *v8; // [esp+38h] [ebp-20090h]
  std::_Iterator_base12 *v9; // [esp+3Ch] [ebp-2008Ch]
  std::_Iterator_base12 *v10; // [esp+40h] [ebp-20088h]
  std::_Iterator_base12 *v11; // [esp+44h] [ebp-20084h]
  CMapObjectMgr *v12; // [esp+48h] [ebp-20080h]
  _DWORD *v13; // [esp+4Ch] [ebp-2007Ch]
  int v14; // [esp+50h] [ebp-20078h]
  const char *v15; // [esp+54h] [ebp-20074h]
  const char *v16; // [esp+58h] [ebp-20070h]
  int v17; // [esp+5Ch] [ebp-2006Ch]
  int v18; // [esp+60h] [ebp-20068h]
  int v19; // [esp+64h] [ebp-20064h]
  int v20; // [esp+68h] [ebp-20060h]
  int v21; // [esp+6Ch] [ebp-2005Ch]
  int v22; // [esp+70h] [ebp-20058h]
  int v23; // [esp+74h] [ebp-20054h]
  int v24; // [esp+78h] [ebp-20050h]
  int v25; // [esp+7Ch] [ebp-2004Ch]
  int i; // [esp+80h] [ebp-20048h]
  int k; // [esp+84h] [ebp-20044h]
  int j; // [esp+88h] [ebp-20040h]
  char v30; // [esp+8Eh] [ebp-2003Ah]
  char v31; // [esp+8Fh] [ebp-20039h]
  int m; // [esp+90h] [ebp-20038h]
  bool v33; // [esp+96h] [ebp-20032h]
  bool v34; // [esp+97h] [ebp-20031h]
  _BYTE v35[65536]; // [esp+98h] [ebp-20030h] BYREF
  _BYTE v36[65536]; // [esp+10098h] [ebp-10030h] BYREF
  char v37[32]; // [esp+20098h] [ebp-30h] BYREF
  int v38; // [esp+200C4h] [ebp-4h]

  v12 = this;
  v18 = CMapObjectMgr::m_iLastUsedId;
  BBSupportTracePrintF(a2, "CMapObjectMgr::PrintAllEntities()...");
  BBSupportTracePrintF(a2, " Current tick is %u.", g_uDbgTickCounter);
  v21 = 0;
  v22 = 0;
  for ( i = 0; i <= v18; ++i )
  {
    v13 = (_DWORD *)CMapObjectMgr::m_vEntities[i];
    if ( v13 )
    {
      ++v21;
      if ( !IEntity::FlagBits(v13, (EntityFlag)&unk_4000000) )
        ++v22;
    }
  }
  memset(v35, 255, sizeof(v35));
  memset(v36, 0, sizeof(v36));
  for ( j = 0; j < 32; ++j )
  {
    v14 = std::vector<std::deque<unsigned short>>::operator[](j);
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
      v35[v24] = j;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v6);
    }
    v38 = -1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v6);
  }
  for ( k = 0; k < 32; ++k )
  {
    v19 = std::vector<std::deque<unsigned short>>::operator[](k);
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
      v35[v23] = k + 32;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v5);
    }
    v38 = -1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v5);
  }
  BBSupportTracePrintF(
    a2,
    " Used: %5i, Alive: %5i, MinFree: %5i, LastUsed: %5i, MaxLastUsed: %5i, UniqueId: %5i, CRC: 0x%08x",
    v21,
    v22,
    CMapObjectMgr::m_iMinFreeId,
    CMapObjectMgr::m_iLastUsedId,
    CMapObjectMgr::m_iMaxLastUsedId,
    CMapObjectMgr::m_iCurrentUniqueId,
    CMapObjectMgr::m_uCRCLogicUpdate);
  for ( m = 1; m <= v18; ++m )
  {
    v20 = CMapObjectMgr::m_vEntities[m];
    if ( v20 )
    {
      v25 = (char)v35[m];
      if ( v25 >= 0 )
      {
        v33 = v25 >= 32;
        v34 = v25 >= 32;
        if ( v25 < 32 )
          v17 = v25;
        else
          v17 = v25 - 32;
        v7 = v17;
        if ( v36[m] )
          v16 = "#";
        else
          v16 = "+";
        if ( v34 )
          v15 = "d";
        else
          v15 = "s";
        j___snprintf(v37, 0x20u, " %05i[%s%02i%s]", m, v15, v7, v16);
      }
      else
      {
        j___snprintf(v37, 0x20u, " %05i[----]", m);
      }
      (*(void (__thiscall **)(int, int, char *))(*(_DWORD *)v20 + 48))(v20, a2, v37);
    }
  }
  return BBSupportTracePrintF(a2, "CMapObjectMgr::PrintAllEntities(): End of entity dump.");
}


// address=[0x15582e0]
// Decompiled from int __thiscall CMapObjectMgr::DbgPrintAllEntities(CMapObjectMgr *this, int a2)
void  CMapObjectMgr::DbgPrintAllEntities(int) {
  
  return CMapObjectMgr::PrintAllEntities(this, a2);
}


// address=[0x1558cb0]
// Decompiled from int __thiscall CMapObjectMgr::GetGfxInfo(CMapObjectMgr *this, int a2, int a3)
struct SGfxObjectInfo *  CMapObjectMgr::GetGfxInfo(int,int) {
  
  if ( !CMapObjectMgr::ValidUsedEntityId(a2) && BBSupportDbgReport(2, string__2, 205, "ValidUsedEntityId( _iId )") == 1 )
    __debugbreak();
  return (*(int (__thiscall **)(int, CMapObjectMgr *))(*(_DWORD *)CMapObjectMgr::m_vEntities[a2] + 20))(
           CMapObjectMgr::m_vEntities[a2],
           this);
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

