#if FALSE
#include "CGroupMgr.h"

// Definitions for class CGroupMgr

// address=[0x1550a80]
// Decompiled from void __thiscall CGroupMgr::Clear(CGroupMgr *this)
void  CGroupMgr::Clear(void) {
  
  int j; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  memset(this->m_bGroupFlags, 0, sizeof(this->m_bGroupFlags));
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 11; ++j )
      TStaticArray<unsigned short,100>::Init(&this->m_vEntries[11 * i + j]);
  }
}


// address=[0x1550af0]
// Decompiled from int __thiscall CGroupMgr::GetGroupSize(CGroupMgr *this, int playerId, int groupId)
int  CGroupMgr::GetGroupSize(int playerId, int groupId)const {
  
  if ( (playerId < 1 || playerId > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         220,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (groupId < 1 || groupId > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 221, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  return TStaticArray<unsigned short,100>::Size(&this->m_vEntries[11 * playerId + groupId]);
}


// address=[0x1550b80]
// Decompiled from WORD *__thiscall CGroupMgr::GetGroupEntityIds(CGroupMgr *this, int playerId, int groupId)
unsigned short const *  CGroupMgr::GetGroupEntityIds(int playerId, int groupId)const {
  
  if ( (playerId < 1 || playerId > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         233,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (groupId < 1 || groupId > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 234, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  return TStaticArray<unsigned short,100>::operator[](&this->m_vEntries[11 * playerId + groupId], 0);
}


// address=[0x1550c10]
// Decompiled from char __thiscall CGroupMgr::AttachEntity(CGroupMgr *this, int playerId, int groupId, int entityIdToAttach)
bool  CGroupMgr::AttachEntity(int playerId, int groupId, int entityIdToAttach) {
  
  int v5; // [esp+0h] [ebp-34h]
  int currentSize; // [esp+4h] [ebp-30h]
  int ownerId; // [esp+Ch] [ebp-28h]
  IEntity *v8; // [esp+10h] [ebp-24h]
  int i; // [esp+18h] [ebp-1Ch]
  int groupFlagBits; // [esp+1Ch] [ebp-18h]
  struct CGroupMgr::TStaticArray100short *groupList; // [esp+20h] [ebp-14h]
  int v13; // [esp+24h] [ebp-10h]
  IEntity *entityToAttach; // [esp+28h] [ebp-Ch]
  __int16 v15; // [esp+2Ch] [ebp-8h] BYREF
  __int16 v16; // [esp+2Eh] [ebp-6h] BYREF
  unsigned __int16 a1; // [esp+30h] [ebp-4h] BYREF

  if ( (playerId < 1 || playerId > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         246,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (groupId < 1 || groupId > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 247, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  entityToAttach = CMapObjectMgr::EntityPtr(entityIdToAttach);
  if ( !entityToAttach && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 251, "pEntity != 0") == 1 )
    __debugbreak();
  if ( !entityToAttach )
    return 0;
  ownerId = IEntity::OwnerId(entityToAttach);
  if ( ownerId != playerId )
    return 0;
  groupFlagBits = 1 << groupId;
  v13 = entityToAttach->GetGroupFlags();
  if ( ((1 << groupId) & v13) != 0 )
    return 0;
  groupList = &this->m_vEntries[11 * ownerId + groupId];
  a1 = entityIdToAttach;
  if ( TStaticArray<unsigned short,100>::FindEntry(groupList, &a1) >= 0
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 267, "rGroupArray.FindEntry(_iEntityId) < 0") == 1 )
  {
    __debugbreak();
  }
  if ( TStaticArray<unsigned short,100>::Size(groupList) >= 100 )
    return 0;
  if ( !IEntity::CheckType(entityToAttach, 1, 44) )
  {
    if ( (groupFlagBits & (unsigned int)entityToAttach->SetGroupFlagBits(groupFlagBits)) == 0 )
      return 0;
    v16 = entityIdToAttach;
    TStaticArray<unsigned short,100>::PushBack(groupList, &v16);
    return 1;
  }
  if ( (this->m_bGroupFlags[11 * playerId + groupId] & 1) != 0 )
    return 0;
  if ( v13 )
    return 0;
  if ( entityToAttach->SetGroupFlags(entityToAttach, groupFlagBits | (groupId << 12)) != (void *)(groupFlagBits | (groupId << 12))
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 300, "iGroupFlags == iNewGroupFlags") == 1 )
  {
    __debugbreak();
  }
  currentSize = TStaticArray<unsigned short,100>::Size(groupList);
  for ( i = 0; i < currentSize; ++i )
  {
    v5 = *TStaticArray<unsigned short,100>::operator[](groupList, i);
    v8 = CMapObjectMgr::EntityPtr(v5);
    if ( v8 )
      ((void (__thiscall *)(IEntity *, int))v8->SetGroupFlagBits)(v8, 0x800);
  }
  this->m_bGroupFlags[11 * playerId + groupId] |= 1u;
  v15 = entityIdToAttach;
  TStaticArray<unsigned short,100>::PushBack(groupList, &v15);
  return 1;
}


// address=[0x1550ec0]
// Decompiled from char __thiscall CGroupMgr::DetachEntity(CGroupMgr *this, int playerId, int groupId, int entityId)
bool  CGroupMgr::DetachEntity(int playerId, int groupId, int entityId) {
  
  int v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+4h] [ebp-2Ch]
  int owner; // [esp+Ch] [ebp-24h]
  IEntity *v8; // [esp+10h] [ebp-20h]
  int groupFlags; // [esp+14h] [ebp-1Ch]
  struct CGroupMgr::TStaticArray100short *v10; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  IEntity *entity; // [esp+24h] [ebp-Ch]
  unsigned __int16 a1; // [esp+2Ah] [ebp-6h] BYREF
  __int16 _entityId; // [esp+2Ch] [ebp-4h] BYREF
  char entityFound; // [esp+2Fh] [ebp-1h]

  if ( (playerId < 1 || playerId > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         339,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (groupId < 1 || groupId > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 340, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  entity = CMapObjectMgr::EntityPtr(entityId);
  if ( !entity && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 344, "pEntity != 0") == 1 )
    __debugbreak();
  if ( !entity )
    return 0;
  owner = IEntity::OwnerId(entity);
  if ( owner != playerId )
    return 0;
  v10 = &this->m_vEntries[11 * owner + groupId];
  groupFlags = 1 << groupId;
  if ( ((1 << groupId) & entity->GetGroupFlags(entity)) == 0 )
  {
    a1 = entityId;
    if ( TStaticArray<unsigned short,100>::FindEntry(v10, &a1) >= 0
      && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 402, "rGroupArray.FindEntry(_iEntityId) < 0") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
  _entityId = entityId;
  entityFound = TStaticArray<unsigned short,100>::RemoveEntry(&_entityId);
  if ( !entityFound && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 362, "bEntityFound") == 1 )
    __debugbreak();
  if ( IEntity::CheckType(entity, 1, 44) )
  {
    entity->SetGroupFlags(entity, 0);
    if ( (this->m_bGroupFlags[11 * playerId + groupId] & 1) == 0
      && BBSupportDbgReport(
           2,
           "MapObjects\\GroupMgr.cpp",
           376,
           "(m_uPlayersGroupsFlags[_iPlayerId][_iGroupId] & PLAYER_GROUP_FLAG_HAS_SQUAD_LEADER) != 0") == 1 )
    {
      __debugbreak();
    }
    this->m_bGroupFlags[11 * playerId + groupId] &= ~1u;
    v6 = TStaticArray<unsigned short,100>::Size(v10);
    for ( i = 0; i < v6; ++i )
    {
      v5 = *TStaticArray<unsigned short,100>::operator[](v10, i);
      v8 = CMapObjectMgr::EntityPtr(v5);
      if ( v8 )
        v8->ClearGroupFlagBits(v8, 2048);
    }
  }
  else
  {
    entity->ClearGroupFlagBits(entity, groupFlags);
    if ( (groupFlags & entity->GetGroupFlags(entity)) != 0
      && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 370, "(pEntity->GetGroupFlags() & iGroupBit) == 0") == 1 )
    {
      __debugbreak();
    }
  }
  return 1;
}


// address=[0x1551170]
// Decompiled from void __thiscall CGroupMgr::DetachEntityFromAllGroups(CGroupMgr *this, int entityId)
void  CGroupMgr::DetachEntityFromAllGroups(int entityId) {
  
  int owner; // [esp+0h] [ebp-18h]
  int groupFlags; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  IEntity *v6; // [esp+14h] [ebp-4h]

  v6 = CMapObjectMgr::EntityPtr(entityId);
  if ( !v6 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 419, "pEntity != 0") == 1 )
    __debugbreak();
  if ( v6 )
  {
    owner = IEntity::OwnerId(v6);
    groupFlags = v6->GetGroupFlags(v6);
    for ( i = 1; i <= 10; ++i )
    {
      if ( ((1 << i) & groupFlags) != 0 )
        this->DetachEntity(this, owner, i, entityId);
    }
    if ( (v6->GetGroupFlags(v6) & 0xFFFFF7FF) != 0
      && BBSupportDbgReport(
           2,
           "MapObjects\\GroupMgr.cpp",
           436,
           "(pEntity->GetGroupFlags() & ~GROUP_FLAG_IN_GROUP_WITH_SQUAD_LEADER) == 0") == 1 )
    {
      __debugbreak();
    }
    v6->SetGroupFlags(v6, 0);
  }
}


// address=[0x1551270]
// Decompiled from int __thiscall CGroupMgr::DetachAllEntitiesFromGroup(CGroupMgr *this, int playerId, int groupId)
void  CGroupMgr::DetachAllEntitiesFromGroup(int playerId, int groupId) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-10h]
  int v6; // [esp+8h] [ebp-8h]
  struct CGroupMgr::TStaticArray100short *v7; // [esp+Ch] [ebp-4h]

  if ( (playerId < 1 || playerId > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         449,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (groupId < 1 || groupId > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 450, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  v7 = &this->m_vEntries[11 * playerId + groupId];
  while ( 1 )
  {
    result = TStaticArray<unsigned short,100>::Size(v7);
    if ( result <= 0 )
      break;
    v6 = TStaticArray<unsigned short,100>::Size(v7);
    v4 = *TStaticArray<unsigned short,100>::operator[](v7, v6 - 1);
    this->DetachEntity(this, playerId, groupId, v4);
    if ( TStaticArray<unsigned short,100>::Size(v7) != v6 - 1
      && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 461, "rGroupArray.Size() == (iOldSize - 1)") == 1 )
    {
      __debugbreak();
    }
    if ( TStaticArray<unsigned short,100>::Size(v7) >= v6 )
    {
      if ( *TStaticArray<unsigned short,100>::operator[](v7, v6 - 1) != v4
        && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 465, "rGroupArray[iOldSize - 1] == iEntityId") == 1 )
      {
        __debugbreak();
      }
      TStaticArray<unsigned short,100>::PopBack(v7);
    }
    if ( TStaticArray<unsigned short,100>::Size(v7) != v6 - 1
      && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 470, "rGroupArray.Size() == (iOldSize - 1)") == 1 )
    {
      __debugbreak();
    }
  }
  return result;
}


// address=[0x15513f0]
// Decompiled from bool __thiscall CGroupMgr::HasSquadLeader(CGroupMgr *this, int a2, int a3)
bool  CGroupMgr::HasSquadLeader(int a2, int a3) {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         481,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 < 1 || a3 > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 482, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (this->m_bGroupFlags[11 * a2 + a3] & 1) != 0;
}


// address=[0x1551490]
// Decompiled from void __thiscall CGroupMgr::SendGroupCommand(  CGroupMgr *this,  int groupSize,  const unsigned __int16 *group,  int x,  int y,  int sendFlags)
void  CGroupMgr::SendGroupCommand(int groupSize, unsigned short const * group, int x, int y, int sendFlags) {
  
  int firstGroupMemberPackedXY; // [esp-4h] [ebp-234h]
  _BYTE v7[24]; // [esp+4h] [ebp-22Ch] BYREF
  _BYTE v8[24]; // [esp+1Ch] [ebp-214h] BYREF
  CEntityEvent *v12; // [esp+40h] [ebp-1F0h]
  CEntityEvent *v13; // [esp+44h] [ebp-1ECh]
  int packedXY; // [esp+48h] [ebp-1E8h]
  int groupMemberId; // [esp+4Ch] [ebp-1E4h]
  int firstGroupMemberId; // [esp+54h] [ebp-1DCh]
  CEntityEvent *v18; // [esp+58h] [ebp-1D8h]
  CEntityEvent *v19; // [esp+5Ch] [ebp-1D4h]
  int v20; // [esp+60h] [ebp-1D0h]
  int v21; // [esp+64h] [ebp-1CCh]
  int NextDestination; // [esp+68h] [ebp-1C8h]
  int v23; // [esp+6Ch] [ebp-1C4h] MAPDST
  IEntity *v24; // [esp+70h] [ebp-1C0h]
  IEntity *firstGroupMember; // [esp+74h] [ebp-1BCh]
  IEntity *groupMember; // [esp+78h] [ebp-1B8h]
  IEntity *v27; // [esp+7Ch] [ebp-1B4h]
  int i; // [esp+80h] [ebp-1B0h] MAPDST
  _BYTE v30[408]; // [esp+88h] [ebp-1A8h] BYREF
  int v31; // [esp+22Ch] [ebp-4h]

  if ( groupSize > 0 && group )
  {
    i = -1;
    for ( i = 0; i < groupSize; ++i )
    {
      v21 = group[i];
      v24 = CMapObjectMgr::EntityPtr(v21);
      if ( v24 && IEntity::FlagBits(v24, ENTITY_FLAG_Ready|ENTITY_FLAG_OnBoard) == 0x2000000 )
        break;
    }
    if ( i >= 0 )
    {
      if ( (sendFlags & 8) != 0 )
      {                                         // Seems like, when 8 Flag is set, then all commands are send to the individuals instead of as a whole group
        while ( i < groupSize )
        {
          v20 = group[i];
          v27 = CMapObjectMgr::EntityPtr(v20);
          if ( v27 )
          {
            if ( IEntity::FlagBits(v27, ENTITY_FLAG_Ready|ENTITY_FLAG_OnBoard) == ENTITY_FLAG_Ready )
            {
              v19 = CEntityEvent::CEntityEvent((CEntityEvent *)v8, 0x11u, 13, sendFlags, 0, 0);
              v18 = v19;
              v31 = 0;
              v27->SetEvent(v27, v19);
              v31 = -1;
              CEntityEvent::~CEntityEvent(v8);
            }
          }
          ++i;
        }
      }
      else
      {
        packedXY = Y16X16::PackXYFast(x, y);
        firstGroupMemberId = group[i];
        firstGroupMember = CMapObjectMgr::EntityPtr(firstGroupMemberId);
        if ( !firstGroupMember && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 697, "pFirstEntity != 0") == 1 )
          __debugbreak();
        if ( IEntity::ObjType(firstGroupMember) == 4 )
          v23 = 3;
        else
          v23 = 1;
        firstGroupMemberPackedXY = IEntity::PackedXY(firstGroupMember);
        CGroupDestinations::CGroupDestinations(
          (CGroupDestinations *)v30,
          x,
          y,
          groupSize,
          v23,
          firstGroupMemberPackedXY);
        while ( i < groupSize )
        {
          groupMemberId = group[i];
          groupMember = CMapObjectMgr::EntityPtr(groupMemberId);
          if ( groupMember && IEntity::FlagBits(groupMember, ENTITY_FLAG_Ready|ENTITY_FLAG_OnBoard) == ENTITY_FLAG_Ready )
          {
            NextDestination = CGroupDestinations::GetNextDestination((CGroupDestinations *)v30);
            if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(NextDestination)
              && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 713, "g_cWorld.InWorldPackedXY(iDestXY)") == 1 )
            {
              __debugbreak();
            }
            v13 = CEntityEvent::CEntityEvent((CEntityEvent *)v7, 0x11u, 13, sendFlags, NextDestination, packedXY);
            v12 = v13;
            v31 = 1;
            groupMember->SetEvent(groupMember, v13);
            v31 = -1;
            CEntityEvent::~CEntityEvent(v7);
          }
          ++i;
        }
      }
    }
  }
}


// address=[0x1551850]
// Decompiled from void __thiscall CGroupMgr::Load(CGroupMgr *this, struct IS4Chunk *a2)
void  CGroupMgr::Load(class IS4Chunk & a2) {
  
  signed int v2; // [esp+8h] [ebp-18h]
  signed int k; // [esp+Ch] [ebp-14h]
  int j; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  __int16 a1; // [esp+1Eh] [ebp-2h] BYREF

  this->Clear();
  a2->LoadSignature(0x3257F159);
  a2->LoadUnsigned32(1, 1);
  a2->LoadUnsigned32(10, 10);
  a2->LoadUnsigned32(100, 100);
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 11; ++j )
    {
      this->m_bGroupFlags[11 * i + j] = a2->LoadUnsigned32(0, 255);
      v2 = a2->LoadUnsigned32(0, 100);
      for ( k = 0; k < v2; ++k )
      {
        a1 = a2->LoadUnsigned32(0, 0xFFFF);
        TStaticArray<unsigned short,100>::PushBack(&this->m_vEntries[11 * i + j], &a1);
      }
    }
  }
  a2->LoadSignature(0x3257F151);
}


// address=[0x15519a0]
// Decompiled from void __thiscall CGroupMgr::Save(CGroupMgr *this, struct IS4Chunk *a2)
void  CGroupMgr::Save(class IS4Chunk & a2) {
  
  unsigned __int16 *v2; // eax
  int v3; // [esp+0h] [ebp-14h]
  int a1; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  a2->SaveSignature(0x3257F159);
  a2->SaveUnsigned32(1);
  a2->SaveUnsigned32(10);
  a2->SaveUnsigned32(100);
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 11; ++j )
    {
      a2->SaveUnsigned32(this->m_bGroupFlags[11 * i + j]);
      v3 = TStaticArray<unsigned short,100>::Size(&this->m_vEntries[11 * i + j]);
      a2->SaveUnsigned32(v3);
      for ( a1 = 0; a1 < v3; ++a1 )
      {
        v2 = TStaticArray<unsigned short,100>::operator[](&this->m_vEntries[11 * i + j], a1);
        a2->SaveUnsigned32(*v2);
      }
    }
  }
  a2->SaveSignature(0x3257F151);
}


// address=[0x1551ae0]
// Decompiled from void __thiscall CGroupMgr::FillGroupSideBarEx(CGroupMgr *this, struct CInfoExchange *_pInfoExchange, bool a3, int a4)
void  CGroupMgr::FillGroupSideBarEx(class CInfoExchange * _pInfoExchange, bool a3, int a4) {
  
  unsigned __int16 *v4; // eax
  CEvn_Event *v5; // [esp+4h] [ebp-60h]
  int LocalPlayerId; // [esp+1Ch] [ebp-48h]
  unsigned int v8; // [esp+20h] [ebp-44h]
  int v9; // [esp+24h] [ebp-40h]
  IEntity *v10; // [esp+28h] [ebp-3Ch]
  int i; // [esp+34h] [ebp-30h]
  CGroupSideBarInfo *pGroupSideBarInfo; // [esp+38h] [ebp-2Ch]
  CEvn_Event v13; // [esp+3Ch] [ebp-28h] BYREF
  int v14; // [esp+60h] [ebp-4h]

  if ( !_pInfoExchange && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 494, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  pGroupSideBarInfo = (CGroupSideBarInfo *)j____RTDynamicCast(
                                             (void **)&_pInfoExchange->__vftable,
                                             0,
                                             &CInfoExchange__RTTI_Type_Descriptor_,
                                             &CGroupSideBarInfo__RTTI_Type_Descriptor_,
                                             0);
  if ( !pGroupSideBarInfo && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 498, "pGroupSideBar != 0") == 1 )
    __debugbreak();
  if ( pGroupSideBarInfo )
  {
    pGroupSideBarInfo->Clear(pGroupSideBarInfo);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    for ( i = 1; i <= 10; ++i )
    {
      if ( TStaticArray<unsigned short,100>::Size(&this->m_vEntries[11 * LocalPlayerId + i]) > 0 )
      {
        v4 = TStaticArray<unsigned short,100>::operator[](&this->m_vEntries[11 * LocalPlayerId + i], 0);
        v10 = CMapObjectMgr::EntityPtr(*v4);
        if ( v10 )
          v9 = IEntity::WarriorType(v10);
        else
          v9 = 0;
        switch ( v9 )
        {
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
            *(&pGroupSideBarInfo->m_iUnknown + i) = 1;// Stupid loops starts at 1.. Thanks compiler
            break;
          case 7:
            *(&pGroupSideBarInfo->m_iUnknown + i) = 2;
            break;
          case 10:
          case 11:
            *(&pGroupSideBarInfo->m_iUnknown + i) = 3;
            break;
          default:
            continue;
        }
      }
    }
    pGroupSideBarInfo->m_iUnknown = 25;
    if ( a3 )
      v8 = 606;
    else
      v8 = 607;
    if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 564, "g_pEvnEngine != 0") == 1 )
      __debugbreak();
    if ( g_pEvnEngine )
    {
      v5 = CEvn_Event::CEvn_Event(&v13, v8, 0, (unsigned int)pGroupSideBarInfo, 0);
      v14 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v5);
      v14 = -1;
      CEvn_Event::~CEvn_Event(&v13);
    }
  }
}


// address=[0x1551d50]
// Decompiled from void __stdcall CGroupMgr::FillMagicSideBarEx(struct CInfoExchange *_pInfoExchange, bool _bSpecialSidebar, int unused)
void  CGroupMgr::FillMagicSideBarEx(class CInfoExchange * _pInfoExchange, bool _bSpecialSidebar, int unused) {
  
  CEvn_Event *v3; // [esp+8h] [ebp-58h]
  DWORD v4; // [esp+18h] [ebp-48h]
  unsigned int v5; // [esp+1Ch] [ebp-44h]
  DWORD CurrentSpellCategoryCost; // [esp+20h] [ebp-40h]
  DWORD v7; // [esp+24h] [ebp-3Ch]
  int CurrentManaAmount; // [esp+28h] [ebp-38h]
  int LocalPlayerId; // [esp+2Ch] [ebp-34h]
  CMagicSpellSideBarInfo *pMagicSpellSideBarInfo; // [esp+30h] [ebp-30h]
  int i; // [esp+34h] [ebp-2Ch]
  CEvn_Event v12; // [esp+38h] [ebp-28h] BYREF
  int v13; // [esp+5Ch] [ebp-4h]

  if ( !_pInfoExchange && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 587, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  pMagicSpellSideBarInfo = (CMagicSpellSideBarInfo *)j____RTDynamicCast(
                                                       (void **)&_pInfoExchange->__vftable,
                                                       0,
                                                       &CInfoExchange__RTTI_Type_Descriptor_,
                                                       &CMagicSpellSideBarInfo__RTTI_Type_Descriptor_,
                                                       0);
  if ( !pMagicSpellSideBarInfo && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 591, "pMagicSpellSideBar != 0") == 1 )
    __debugbreak();
  if ( pMagicSpellSideBarInfo )
  {
    pMagicSpellSideBarInfo->Clear(pMagicSpellSideBarInfo);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    for ( i = 0; i < 8; ++i )
    {
      v4 = CMagic::CalculatePossibleNumberOfCastSpell(LocalPlayerId, i, 0);
      CurrentSpellCategoryCost = CMagic::GetCurrentSpellCategoryCost(LocalPlayerId, i);
      CurrentManaAmount = CMagic::GetCurrentManaAmount(LocalPlayerId);
      if ( CurrentManaAmount <= 0 )
        v7 = 0;
      else
        v7 = (int)(100 * CurrentSpellCategoryCost) / CurrentManaAmount;
      pMagicSpellSideBarInfo->m_aSpells[i].m_uPossibleNumberOfCasts = v4;
      pMagicSpellSideBarInfo->m_aSpells[i].m_uAvailableCastsPercent = v7;
      pMagicSpellSideBarInfo->m_aSpells[i].m_uCost = CurrentSpellCategoryCost;
      pMagicSpellSideBarInfo->m_aSpells[i].m_uSpellId = i;
    }
    pMagicSpellSideBarInfo->m_iUnknown = 26;
    if ( _bSpecialSidebar )
      v5 = 606;
    else
      v5 = 607;
    if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 620, "g_pEvnEngine != 0") == 1 )
      __debugbreak();
    if ( g_pEvnEngine )
    {
      v3 = CEvn_Event::CEvn_Event(&v12, v5, 0, (unsigned int)pMagicSpellSideBarInfo, 0);
      v13 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v3);
      v13 = -1;
      CEvn_Event::~CEvn_Event(&v12);
    }
  }
}


// address=[0x1552590]
// Decompiled from CGroupMgr *__thiscall CGroupMgr::CGroupMgr(CGroupMgr *this)
 CGroupMgr::CGroupMgr(void) {
  
  IGroupMgr::IGroupMgr(this);
  this->__vftable = (CGroupMgr_vtbl *)CGroupMgr::_vftable_;
  _vec_ctor_no(
    this->m_vEntries,
    204u,
    99u,
    (void *(__thiscall *)(void *))TStaticArray<unsigned short,100>::TStaticArray<unsigned short,100>);
  return this;
}


#endif // Already implemented
