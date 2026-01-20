#include "CGroupMgr.h"

#include "CBB/CBBSupport.h"
#include "World/helper.h"
#include "Main/Players/CPlayerManager.h"
#include "MapObjects/CGroupDestinations.h"
#include "Logic/Events/CEntityEvent.h"
#include "../Logic/Events/CEvn_Event.h"
#include "Logic/CInfoExchange.h"
#include "Logic/CMagic.h"
#include "Info/CGroupSideBarInfo.h"
#include "Info/CMagicSpellSideBarInfo.h"
#include "../LoadSave/IS4Chunk.h"
#include "CMapObjectMgr.h"
#include "IEntity.h"

// Definitions for class CGroupMgr

// address=[0x1550a80]
// Decompiled from void __thiscall CGroupMgr::Clear(CGroupMgr *this)
void CGroupMgr::Clear(void)
{

  int j; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  memset(this->m_bGroupFlags, 0, sizeof(this->m_bGroupFlags));
  for (i = 0; i < MAX_PLAYERS; ++i)
  {
    for (j = 0; j < MAX_GROUPS_PER_PLAYER; ++j)
      this->m_vEntries[0xB * i + j].Init();
  }
}

// address=[0x1550af0]
// Decompiled from int __thiscall CGroupMgr::GetGroupSize(CGroupMgr *this, int playerId, int groupId)
int CGroupMgr::GetGroupSize(int playerId, int groupId) const
{

  if ((playerId < PLAYER_FIRST || playerId > PLAYER_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 220, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1)
  {
    __debugbreak();
  }
  if ((groupId < GROUP_FIRST || groupId > GROUP_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 221, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1)
  {
    __debugbreak();
  }
  return this->m_vEntries[MAX_GROUPS_PER_PLAYER * playerId + groupId].Size();
}

// address=[0x1550b80]
// Decompiled from WORD *__thiscall CGroupMgr::GetGroupEntityIds(CGroupMgr *this, int playerId, int groupId)
unsigned short const *CGroupMgr::GetGroupEntityIds(int playerId, int groupId) const
{

  if ((playerId < PLAYER_FIRST || playerId > PLAYER_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 233, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1)
  {
    __debugbreak();
  }
  if ((groupId < GROUP_FIRST || groupId > GROUP_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 234, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1)
  {
    __debugbreak();
  }
  return this->m_vEntries[MAX_GROUPS_PER_PLAYER * playerId + groupId];
}

// address=[0x1550c10]
// Decompiled from char __thiscall CGroupMgr::AttachEntity(CGroupMgr *this, int playerId, int groupId, int entityIdToAttach)
bool CGroupMgr::AttachEntity(int playerId, int groupId, int _entityIdToAttach)
{

  int iEntityId;                                // [esp+0h] [ebp-34h]
  int currentSize;                              // [esp+4h] [ebp-30h]
  int ownerId;                                  // [esp+Ch] [ebp-28h]
  int i;                                        // [esp+18h] [ebp-1Ch]
  int groupFlagBits;                            // [esp+1Ch] [ebp-18h]
  TStaticArray<unsigned short, 100> *groupList; // [esp+20h] [ebp-14h]
  int v13;                                      // [esp+24h] [ebp-10h]
  IEntity *entityToAttach;                      // [esp+28h] [ebp-Ch]
  unsigned short v15;                           // [esp+2Ch] [ebp-8h] BYREF
  unsigned short v16;                           // [esp+2Eh] [ebp-6h] BYREF
  unsigned short a1;                            // [esp+30h] [ebp-4h] BYREF

  if ((playerId < PLAYER_FIRST || playerId > PLAYER_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 246, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1)
  {
    __debugbreak();
  }

  if ((groupId < GROUP_FIRST || groupId > GROUP_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 247, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1)
  {
    __debugbreak();
  }

  unsigned short entityIdToAttach = static_cast<unsigned short>(_entityIdToAttach);

  entityToAttach = g_pMapObjectMgr->EntityPtr(entityIdToAttach);
  if (!entityToAttach && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 251, "pEntity != 0") == 1)
    __debugbreak();

  if (!entityToAttach)
    return 0;

  ownerId = entityToAttach->OwnerId();
  if (ownerId != playerId)
    return 0;

  groupFlagBits = 1 << groupId;
  v13 = entityToAttach->GetGroupFlags();
  if (((1 << groupId) & v13) != 0)
    return 0;

  groupList = &this->m_vEntries[MAX_GROUPS_PER_PLAYER * ownerId + groupId];
  if (groupList->FindEntry(&entityIdToAttach) >= 0 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 267, "rGroupArray.FindEntry(_iEntityId) < 0") == 1)
  {
    __debugbreak();
  }

  if (groupList->Size() >= MAX_GROUP_SIZE)
    return 0;

  if (!entityToAttach->CheckType(1, 44))
  {
    if ((groupFlagBits & (int)entityToAttach->SetGroupFlagBits(groupFlagBits)) == 0)
      return 0;
    groupList->PushBack(&entityIdToAttach);
    return 1;
  }

  if ((this->m_bGroupFlags[MAX_GROUPS_PER_PLAYER * playerId + groupId] & 1) != 0)
    return 0;
  if (v13)
    return 0;
  if (entityToAttach->SetGroupFlags(groupFlagBits | (groupId << 12)) != (groupFlagBits | (groupId << 12)) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 300, "iGroupFlags == iNewGroupFlags") == 1)
  {
    __debugbreak();
  }
  currentSize = groupList->Size();
  for (i = 0; i < currentSize; ++i)
  {
    iEntityId = (*groupList)[i];
    IEntity *pEntity = CMapObjectMgr::EntityPtr(iEntityId);
    if (pEntity)
      pEntity->SetGroupFlagBits(0x800);
  }
  this->m_bGroupFlags[MAX_GROUPS_PER_PLAYER * playerId + groupId] |= 1u;
  groupList->PushBack(&entityIdToAttach);

  return 1;
}

// address=[0x1550ec0]
// Decompiled from char __thiscall CGroupMgr::DetachEntity(CGroupMgr *this, int playerId, int groupId, int entityId)
bool CGroupMgr::DetachEntity(int _iPlayerId, int _iGroupId, int _iEntityId)
{

  int v5;                                              // [esp+0h] [ebp-30h]
  int v6;                                              // [esp+4h] [ebp-2Ch]
  int owner;                                           // [esp+Ch] [ebp-24h]
  IEntity *v8;                                         // [esp+10h] [ebp-20h]
  int groupFlags;                                      // [esp+14h] [ebp-1Ch]
  TStaticArray<unsigned short, 100> *groupEntityArray; // [esp+18h] [ebp-18h]
  int i;                                               // [esp+1Ch] [ebp-14h]
  IEntity *entity;                                     // [esp+24h] [ebp-Ch]
  unsigned short a1;                                   // [esp+2Ah] [ebp-6h] BYREF
  unsigned short _entityId;                            // [esp+2Ch] [ebp-4h] BYREF
  char entityFound;                                    // [esp+2Fh] [ebp-1h]

  if ((_iPlayerId < PLAYER_FIRST || _iPlayerId > PLAYER_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 339, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1)
  {
    __debugbreak();
  }
  if ((_iGroupId < GROUP_FIRST || _iGroupId > GROUP_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 340, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1)
  {
    __debugbreak();
  }
  entity = CMapObjectMgr::EntityPtr(_iEntityId);
  if (!entity && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 344, "pEntity != 0") == 1)
    __debugbreak();
  if (!entity)
    return 0;
  owner = entity->OwnerId();
  if (owner != _iPlayerId)
    return 0;
  groupEntityArray = &this->m_vEntries[MAX_GROUPS_PER_PLAYER * owner + _iGroupId];
  groupFlags = 1 << _iGroupId;
  if (((1 << _iGroupId) & entity->GetGroupFlags()) == 0)
  {
    a1 = _iEntityId;
    if (groupEntityArray->FindEntry(&a1) >= 0 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 402, "rGroupArray.FindEntry(_iEntityId) < 0") == 1)
    {
      __debugbreak();
    }
    return 0;
  }
  _entityId = _iEntityId;
  entityFound = groupEntityArray->RemoveEntry(&_entityId);
  if (!entityFound && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 362, "bEntityFound") == 1)
    __debugbreak();
  if (entity->CheckType(1, 44))
  {
    entity->SetGroupFlags(0);
    if ((this->m_bGroupFlags[11 * _iPlayerId + _iGroupId] & 1) == 0 && BBSupportDbgReport(
                                                                           2,
                                                                           "MapObjects\\GroupMgr.cpp",
                                                                           376,
                                                                           "(m_uPlayersGroupsFlags[_iPlayerId][_iGroupId] & PLAYER_GROUP_FLAG_HAS_SQUAD_LEADER) != 0") == 1)
    {
      __debugbreak();
    }
    this->m_bGroupFlags[11 * _iPlayerId + _iGroupId] &= ~1u;
    v6 = groupEntityArray->Size();
    for (i = 0; i < v6; ++i)
    {
      v5 = *groupEntityArray[i];
      v8 = CMapObjectMgr::EntityPtr(v5);
      if (v8)
        v8->ClearGroupFlagBits(2048);
    }
  }
  else
  {
    entity->ClearGroupFlagBits(groupFlags);
    if ((groupFlags & entity->GetGroupFlags()) != 0 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 370, "(pEntity->GetGroupFlags() & iGroupBit) == 0") == 1)
    {
      __debugbreak();
    }
  }
  return 1;
}

// address=[0x1551170]
// Decompiled from void __thiscall CGroupMgr::DetachEntityFromAllGroups(CGroupMgr *this, int entityId)
void CGroupMgr::DetachEntityFromAllGroups(int entityId)
{

  int owner;      // [esp+0h] [ebp-18h]
  int groupFlags; // [esp+8h] [ebp-10h]
  int i;          // [esp+10h] [ebp-8h]
  IEntity *v6;    // [esp+14h] [ebp-4h]

  v6 = CMapObjectMgr::EntityPtr(entityId);
  if (!v6 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 419, "pEntity != 0") == 1)
    __debugbreak();
  if (v6)
  {
    owner = v6->OwnerId();
    groupFlags = v6->GetGroupFlags();
    for (i = 1; i <= 10; ++i)
    {
      if (((1 << i) & groupFlags) != 0)
        this->DetachEntity(owner, i, entityId);
    }
    if ((v6->GetGroupFlags() & 0xFFFFF7FF) != 0 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 436, "(pEntity->GetGroupFlags() & ~GROUP_FLAG_IN_GROUP_WITH_SQUAD_LEADER) == 0") == 1)
    {
      __debugbreak();
    }
    v6->SetGroupFlags(0);
  }
}

// address=[0x1551270]
// Decompiled from int __thiscall CGroupMgr::DetachAllEntitiesFromGroup(CGroupMgr *this, int playerId, int groupId)
void CGroupMgr::DetachAllEntitiesFromGroup(int playerId, int groupId)
{
  if ((playerId < PLAYER_FIRST || playerId > PLAYER_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 449, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1)
  {
    __debugbreak();
  }
  if ((groupId < GROUP_FIRST || groupId > GROUP_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 450, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1)
  {
    __debugbreak();
  }
  TStaticArray<unsigned short, 100> &rGroupArray = this->m_vEntries[11 * playerId + groupId];
  while (1)
  {
    if (rGroupArray.Size() <= 0)
      break;
    int iOldSize = rGroupArray.Size();
    int iEntityId = rGroupArray[iOldSize - 1];
    this->DetachEntity(playerId, groupId, iEntityId);
    if (rGroupArray.Size() != iOldSize - 1 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 461, "rGroupArray.Size() == (iOldSize - 1)") == 1)
    {
      __debugbreak();
    }
    if (rGroupArray.Size() >= iOldSize)
    {
      if (rGroupArray[iOldSize - 1] != iEntityId && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 465, "rGroupArray[iOldSize - 1] == iEntityId") == 1)
      {
        __debugbreak();
      }
      rGroupArray.PopBack(0);
    }
    if (rGroupArray.Size() != iOldSize - 1 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 470, "rGroupArray.Size() == (iOldSize - 1)") == 1)
    {
      __debugbreak();
    }
  }
}

// address=[0x15513f0]
// Decompiled from bool __thiscall CGroupMgr::HasSquadLeader(CGroupMgr *this, int a2, int a3)
bool CGroupMgr::HasSquadLeader(int _iPlayerId, int _iGroupId)
{

  if ((_iPlayerId < PLAYER_FIRST || _iPlayerId > PLAYER_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 481, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1)
  {
    __debugbreak();
  }
  if ((_iGroupId < GROUP_FIRST || _iGroupId > GROUP_LAST) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 482, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1)
  {
    __debugbreak();
  }
  return (this->m_bGroupFlags[MAX_GROUPS_PER_PLAYER * _iPlayerId + _iGroupId] & 1) != 0;
}

// address=[0x1551490]
// Decompiled from void __thiscall CGroupMgr::SendGroupCommand(  CGroupMgr *this,  int groupSize,  const unsigned __int16 *group,  int x,  int y,  int sendFlags)
void CGroupMgr::SendGroupCommand(int groupSize, unsigned short const *group, int x, int y, int sendFlags)
{

  int firstGroupMemberPackedXY; // [esp-4h] [ebp-234h]
  int packedXY;                 // [esp+48h] [ebp-1E8h]
  int groupMemberId;            // [esp+4Ch] [ebp-1E4h]
  int firstGroupMemberId;       // [esp+54h] [ebp-1DCh]
  int v20;                      // [esp+60h] [ebp-1D0h]
  int v21;                      // [esp+64h] [ebp-1CCh]
  int NextDestination;          // [esp+68h] [ebp-1C8h]
  int v23;                      // [esp+6Ch] [ebp-1C4h] MAPDST
  IEntity *v24;                 // [esp+70h] [ebp-1C0h]
  IEntity *firstGroupMember;    // [esp+74h] [ebp-1BCh]
  IEntity *groupMember;         // [esp+78h] [ebp-1B8h]
  IEntity *v27;                 // [esp+7Ch] [ebp-1B4h]
  int i;                        // [esp+80h] [ebp-1B0h] MAPDST
  int v31;                      // [esp+22Ch] [ebp-4h]

  if (groupSize > 0 && group)
  {
    i = -1;
    for (i = 0; i < groupSize; ++i)
    {
      v21 = group[i];
      v24 = CMapObjectMgr::EntityPtr(v21);
      if (v24 && v24->FlagBits(EntityFlag_Ready | EntityFlag_OnBoard) == 0x2000000)
        break;
    }
    if (i >= 0)
    {
      if ((sendFlags & 8) != 0)
      { // Seems like, when 8 Flag is set, then all commands are send to the individuals instead of as a whole group
        while (i < groupSize)
        {
          v20 = group[i];
          v27 = CMapObjectMgr::EntityPtr(v20);
          if (v27)
          {
            if (v27->FlagBits(EntityFlag_Ready | EntityFlag_OnBoard) == EntityFlag_Ready)
            {
              CEntityEvent v19 = CEntityEvent(0x11u, 13, sendFlags, 0, 0);
              v27->SetEvent(v19);
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
        if (!firstGroupMember && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 697, "pFirstEntity != 0") == 1)
          __debugbreak();
        if (firstGroupMember->ObjType() == 4)
          v23 = 3;
        else
          v23 = 1;
        firstGroupMemberPackedXY = firstGroupMember->PackedXY();
        CGroupDestinations v30 = CGroupDestinations(
            x,
            y,
            groupSize,
            v23,
            firstGroupMemberPackedXY);
        while (i < groupSize)
        {
          groupMemberId = group[i];
          groupMember = CMapObjectMgr::EntityPtr(groupMemberId);
          if (groupMember && groupMember->FlagBits(EntityFlag_Ready | EntityFlag_OnBoard) == EntityFlag_Ready)
          {
            NextDestination = v30.GetNextDestination();
            if (!g_cWorld.InWorldPackedXY(NextDestination) && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 713, "g_cWorld.InWorldPackedXY(iDestXY)") == 1)
            {
              __debugbreak();
            }
            CEntityEvent v13 = CEntityEvent(0x11u, 13, sendFlags, NextDestination, packedXY);
            groupMember->SetEvent(v13);
          }
          ++i;
        }
      }
    }
  }
}

// address=[0x1551850]
// Decompiled from int __thiscall CGroupMgr::Load(CGroupMgr::TStaticArray100short *this, struct IS4Chunk *a2)
void CGroupMgr::Load(IS4Chunk &a2)
{

  this->Clear();
  a2.LoadSignature(0x3257F159);
  a2.LoadUnsigned32(1, 1);
  a2.LoadUnsigned32(10, 10);
  a2.LoadUnsigned32(100, 100);

  for (int i = 0; i < MAX_PLAYERS; ++i)
  {
    for (int j = 0; j < MAX_GROUPS_PER_PLAYER; ++j)
    {
      this->m_bGroupFlags[MAX_GROUPS_PER_PLAYER * i + j] = a2.LoadUnsigned32(0, 255);
      int iSavedGroupSize = a2.LoadUnsigned32(0, MAX_GROUP_SIZE);
      for (int k = 0; k < iSavedGroupSize; ++k)
      {
        unsigned short sSavedEntityIdInGroup = a2.LoadUnsigned32(0, 0xFFFF);
        this->m_vEntries[MAX_GROUPS_PER_PLAYER * i + j].PushBack(&sSavedEntityIdInGroup);
      }
    }
  }

  a2.LoadSignature(0x3257F151);
}

// address=[0x15519a0]
// Decompiled from int __thiscall CGroupMgr::Save(CGroupMgr::TStaticArray100short *this, struct IS4Chunk *a2)
void CGroupMgr::Save(class IS4Chunk &a2)
{

  a2.SaveSignature(844624217);
  a2.SaveUnsigned32(1);
  a2.SaveUnsigned32(10);
  a2.SaveUnsigned32(100);
  for (int i = 0; i < MAX_PLAYERS; ++i)
  {
    for (int j = 0; j < MAX_GROUPS_PER_PLAYER; ++j)
    {
      a2.SaveUnsigned32(this->m_bGroupFlags[MAX_GROUPS_PER_PLAYER * i + j]);
      int v3 = this->m_vEntries[MAX_GROUPS_PER_PLAYER * i + j].Size();
      a2.SaveUnsigned32(v3);
      for (int a1 = 0; a1 < v3; ++a1)
      {
        unsigned short v2 = this->m_vEntries[MAX_GROUPS_PER_PLAYER * i + j][a1];
        a2.SaveUnsigned32(*v2);
      }
    }
  }
  a2.SaveSignature(844624209);
}

// address=[0x1551ae0]
// Decompiled from _DWORD *__thiscall CGroupMgr::FillGroupSideBarEx(char *this, void **a2, char a3, int a4)
void CGroupMgr::FillGroupSideBarEx(class CInfoExchange *_pInfoExchange, bool a3, int a4)
{
  unsigned __int16 *v4;                 // eax
  int LocalPlayerId;                    // [esp+1Ch] [ebp-48h]
  unsigned int v8;                      // [esp+20h] [ebp-44h]
  int warriorType;                      // [esp+24h] [ebp-40h]
  IEntity *pEntity;                     // [esp+28h] [ebp-3Ch]
  int i;                                // [esp+34h] [ebp-30h]
  CGroupSideBarInfo *pGroupSideBarInfo; // [esp+38h] [ebp-2Ch]
  int v14;                              // [esp+60h] [ebp-4h]

  if (!_pInfoExchange && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 494, "_pInfoExchange != 0") == 1)
    __debugbreak();
  pGroupSideBarInfo = dynamic_cast<CGroupSideBarInfo *>(_pInfoExchange);
  if (!pGroupSideBarInfo && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 498, "pGroupSideBar != 0") == 1)
    __debugbreak();
  if (pGroupSideBarInfo)
  {
    pGroupSideBarInfo->Clear();
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    for (i = 1; i <= 10; ++i)
    {
      if (this->m_vEntries[11 * LocalPlayerId + i].Size() > 0)
      {
        unsigned short sFirst = this->m_vEntries[11 * LocalPlayerId + i][0];
        pEntity = CMapObjectMgr::EntityPtr(sFirst);
        if (pEntity)
          warriorType = pEntity->WarriorType();
        else
          warriorType = 0;
        switch (warriorType)
        {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
          pGroupSideBarInfo->m_iUnknown[i] = 1;
          break;
        case 7:
          pGroupSideBarInfo->m_iUnknown[i] = 2;
          break;
        case 10:
        case 11:
          pGroupSideBarInfo->m_iUnknown[i] = 3;
          break;
        default:
          continue;
        }
      }
    }
    pGroupSideBarInfo->m_iUnknown[0] = 25;
    if (a3)
      v8 = 606;
    else
      v8 = 607;
    if (!g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 564, "g_pEvnEngine != 0") == 1)
      __debugbreak();
    if (g_pEvnEngine)
    {
      CEvn_Event v5 = CEvn_Event(v8, 0, (unsigned int)pGroupSideBarInfo, 0);
      g_pEvnEngine->SendAMessage(&v5);
    }
  }
}

// address=[0x1551d50]
// Decompiled from unsigned int __stdcall CGroupMgr::FillMagicSideBarEx(void **a1, unsigned __int8 a2, int a3)
void CGroupMgr::FillMagicSideBarEx(class CInfoExchange *_pInfoExchange, bool _bSpecialSidebar, int unused)
{
  int v4;                                         // [esp+18h] [ebp-48h]
  unsigned int v5;                                // [esp+1Ch] [ebp-44h]
  int CurrentSpellCategoryCost;                   // [esp+20h] [ebp-40h]
  int v7;                                         // [esp+24h] [ebp-3Ch]
  int CurrentManaAmount;                          // [esp+28h] [ebp-38h]
  int LocalPlayerId;                              // [esp+2Ch] [ebp-34h]
  CMagicSpellSideBarInfo *pMagicSpellSideBarInfo; // [esp+30h] [ebp-30h]
  int i;                                          // [esp+34h] [ebp-2Ch]
  int v13;                                        // [esp+5Ch] [ebp-4h]

  if (!_pInfoExchange && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 587, "_pInfoExchange != 0") == 1)
    __debugbreak();
  pMagicSpellSideBarInfo = dynamic_cast<CMagicSpellSideBarInfo *>(_pInfoExchange);
  if (!pMagicSpellSideBarInfo && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 591, "pMagicSpellSideBar != 0") == 1)
    __debugbreak();
  if (pMagicSpellSideBarInfo)
  {
    pMagicSpellSideBarInfo->Clear();
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    for (i = 0; i < 8; ++i)
    {
      v4 = CMagic::CalculatePossibleNumberOfCastSpell(LocalPlayerId, i, 0);
      CurrentSpellCategoryCost = CMagic::GetCurrentSpellCategoryCost(LocalPlayerId, i);
      CurrentManaAmount = CMagic::GetCurrentManaAmount(LocalPlayerId);
      if (CurrentManaAmount <= 0)
        v7 = 0;
      else
        v7 = 100 * CurrentSpellCategoryCost / CurrentManaAmount;
      *(_DWORD *)(pMagicSpellSideBarInfo + 16 * i + 12) = v4;
      *(_DWORD *)(pMagicSpellSideBarInfo + 16 * i + 16) = v7;
      *(_DWORD *)(pMagicSpellSideBarInfo + 16 * i + 20) = CurrentSpellCategoryCost;
      *(_DWORD *)(pMagicSpellSideBarInfo + 16 * i + 8) = i;
    }
    *(_DWORD *)(pMagicSpellSideBarInfo + 4) = 26;
    if (_bSpecialSidebar)
      v5 = 606;
    else
      v5 = 607;
    if (!g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 620, "g_pEvnEngine != 0") == 1)
      __debugbreak();
    if (g_pEvnEngine)
    {
      CEvn_Event v3 = CEvn_Event(v5, 0, reinterpret_cast<unsigned int>(pMagicSpellSideBarInfo), 0);
      g_pEvnEngine->SendAMessage(v3);
    }
  }
}

// address=[0x1552590]
// Decompiled from CGroupMgr *__thiscall CGroupMgr::CGroupMgr(CGroupMgr *this)
CGroupMgr::CGroupMgr(void)
{
  // TODO: Check if needed...
  //_vec_ctor_no(this->m_vEntries, 204u, 99u, TStaticArray<unsigned short, 100>::TStaticArray<unsigned short, 100>);
}
