#include "CGroupMgr.h"

// Definitions for class CGroupMgr

// address=[0x1550a80]
// Decompiled from void __thiscall CGroupMgr::Clear(CGroupMgr *this)

void  CGroupMgr::Clear(void) {
  
  int j; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  j__memset((char *)this + 4, 0, 0x63u);
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 11; ++j )
      TStaticArray<unsigned short,100>::Init((CGroupMgr *)((char *)this + 2244 * i + 204 * j + 104));
  }
}


// address=[0x1550af0]
// Decompiled from int __thiscall CGroupMgr::GetGroupSize(CGroupMgr *this, int a2, int a3)

int  CGroupMgr::GetGroupSize(int,int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         220,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 < 1 || a3 > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 221, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  return TStaticArray<unsigned short,100>::Size((char *)this + 2244 * a2 + 204 * a3 + 104);
}


// address=[0x1550b80]
// Decompiled from int __thiscall CGroupMgr::GetGroupEntityIds(CGroupMgr *this, int a2, int a3)

unsigned short const *  CGroupMgr::GetGroupEntityIds(int,int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         233,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 < 1 || a3 > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 234, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  return TStaticArray<unsigned short,100>::operator[](0);
}


// address=[0x1550c10]
// Decompiled from char __thiscall CGroupMgr::AttachEntity(CGroupMgr *this, int a2, int a3, int a4)

bool  CGroupMgr::AttachEntity(int,int,int) {
  
  int v5; // [esp+0h] [ebp-34h]
  int v6; // [esp+4h] [ebp-30h]
  int v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+10h] [ebp-24h]
  int i; // [esp+18h] [ebp-1Ch]
  int v11; // [esp+1Ch] [ebp-18h]
  char *v12; // [esp+20h] [ebp-14h]
  int v13; // [esp+24h] [ebp-10h]
  unsigned __int8 *v14; // [esp+28h] [ebp-Ch]
  __int16 v15; // [esp+2Ch] [ebp-8h] BYREF
  __int16 v16; // [esp+2Eh] [ebp-6h] BYREF
  __int16 v17; // [esp+30h] [ebp-4h] BYREF

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         246,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 < 1 || a3 > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 247, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  v14 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a4);
  if ( !v14 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 251, "pEntity != 0") == 1 )
    __debugbreak();
  if ( !v14 )
    return 0;
  v7 = IEntity::OwnerId(v14);
  if ( v7 != a2 )
    return 0;
  v11 = 1 << a3;
  v13 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v14 + 84))(v14);
  if ( ((1 << a3) & v13) != 0 )
    return 0;
  v12 = (char *)this + 2244 * v7 + 204 * a3 + 104;
  v17 = a4;
  if ( (int)TStaticArray<unsigned short,100>::FindEntry(&v17) >= 0
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 267, "rGroupArray.FindEntry(_iEntityId) < 0") == 1 )
  {
    __debugbreak();
  }
  if ( TStaticArray<unsigned short,100>::Size(v12) >= 100 )
    return 0;
  if ( !IEntity::CheckType((IEntity *)v14, 1, 44) )
  {
    if ( (v11 & (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v14 + 92))(v14, v11)) == 0 )
      return 0;
    v16 = a4;
    TStaticArray<unsigned short,100>::PushBack(&v16);
    return 1;
  }
  if ( (*((_BYTE *)this + 11 * a2 + a3 + 4) & 1) != 0 )
    return 0;
  if ( v13 )
    return 0;
  if ( (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v14 + 88))(v14, v11 | (a3 << 12)) != (v11 | (a3 << 12))
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 300, "iGroupFlags == iNewGroupFlags") == 1 )
  {
    __debugbreak();
  }
  v6 = TStaticArray<unsigned short,100>::Size(v12);
  for ( i = 0; i < v6; ++i )
  {
    v5 = *(unsigned __int16 *)TStaticArray<unsigned short,100>::operator[](i);
    v8 = CMapObjectMgr::EntityPtr(v5);
    if ( v8 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 92))(v8, 2048);
  }
  *((_BYTE *)this + 11 * a2 + a3 + 4) |= 1u;
  v15 = a4;
  TStaticArray<unsigned short,100>::PushBack(&v15);
  return 1;
}


// address=[0x1550ec0]
// Decompiled from char __thiscall CGroupMgr::DetachEntity(CGroupMgr *this, int a2, int a3, int a4)

bool  CGroupMgr::DetachEntity(int,int,int) {
  
  int v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+4h] [ebp-2Ch]
  int v7; // [esp+Ch] [ebp-24h]
  int v8; // [esp+10h] [ebp-20h]
  int v9; // [esp+14h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *v12; // [esp+24h] [ebp-Ch]
  __int16 v13; // [esp+2Ah] [ebp-6h] BYREF
  __int16 v14; // [esp+2Ch] [ebp-4h] BYREF
  char v16; // [esp+2Fh] [ebp-1h]

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         339,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 < 1 || a3 > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 340, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  v12 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a4);
  if ( !v12 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 344, "pEntity != 0") == 1 )
    __debugbreak();
  if ( !v12 )
    return 0;
  v7 = IEntity::OwnerId(v12);
  if ( v7 != a2 )
    return 0;
  v9 = 1 << a3;
  if ( ((1 << a3) & (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v12 + 84))(v12)) == 0 )
  {
    v13 = a4;
    if ( (int)TStaticArray<unsigned short,100>::FindEntry(&v13) >= 0
      && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 402, "rGroupArray.FindEntry(_iEntityId) < 0") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
  v14 = a4;
  v16 = TStaticArray<unsigned short,100>::RemoveEntry(&v14);
  if ( !v16 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 362, "bEntityFound") == 1 )
    __debugbreak();
  if ( IEntity::CheckType((IEntity *)v12, 1, 44) )
  {
    (*(void (__thiscall **)(unsigned __int8 *, _DWORD))(*(_DWORD *)v12 + 88))(v12, 0);
    if ( (*((_BYTE *)this + 11 * a2 + a3 + 4) & 1) == 0
      && BBSupportDbgReport(
           2,
           "MapObjects\\GroupMgr.cpp",
           376,
           "(m_uPlayersGroupsFlags[_iPlayerId][_iGroupId] & PLAYER_GROUP_FLAG_HAS_SQUAD_LEADER) != 0") == 1 )
    {
      __debugbreak();
    }
    *((_BYTE *)this + 11 * a2 + a3 + 4) &= ~1u;
    v6 = TStaticArray<unsigned short,100>::Size((char *)this + 2244 * v7 + 204 * a3 + 104);
    for ( i = 0; i < v6; ++i )
    {
      v5 = *(unsigned __int16 *)TStaticArray<unsigned short,100>::operator[](i);
      v8 = CMapObjectMgr::EntityPtr(v5);
      if ( v8 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 96))(v8, 2048);
    }
  }
  else
  {
    (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v12 + 96))(v12, v9);
    if ( (v9 & (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v12 + 84))(v12)) != 0
      && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 370, "(pEntity->GetGroupFlags() & iGroupBit) == 0") == 1 )
    {
      __debugbreak();
    }
  }
  return 1;
}


// address=[0x1551170]
// Decompiled from int __thiscall CGroupMgr::DetachEntityFromAllGroups(CGroupMgr *this, int a2)

void  CGroupMgr::DetachEntityFromAllGroups(int) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  unsigned __int8 *v7; // [esp+14h] [ebp-4h]

  result = CMapObjectMgr::EntityPtr(a2);
  v7 = (unsigned __int8 *)result;
  if ( !result )
  {
    result = BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 419, "pEntity != 0");
    if ( result == 1 )
      __debugbreak();
  }
  if ( !v7 )
    return result;
  v3 = IEntity::OwnerId(v7);
  v4 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v7 + 84))(v7);
  for ( i = 1; i <= 10; ++i )
  {
    if ( ((1 << i) & v4) != 0 )
      (*(void (__thiscall **)(CGroupMgr *, int, int, int))(*(_DWORD *)this + 24))(this, v3, i, a2);
  }
  if ( ((*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v7 + 84))(v7) & 0xFFFFF7FF) != 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         436,
         "(pEntity->GetGroupFlags() & ~GROUP_FLAG_IN_GROUP_WITH_SQUAD_LEADER) == 0") == 1 )
  {
    __debugbreak();
  }
  return (*(int (__thiscall **)(unsigned __int8 *, _DWORD))(*(_DWORD *)v7 + 88))(v7, 0);
}


// address=[0x1551270]
// Decompiled from int __thiscall CGroupMgr::DetachAllEntitiesFromGroup(CGroupMgr *this, int a2, int a3)

void  CGroupMgr::DetachAllEntitiesFromGroup(int,int) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-10h]
  int v6; // [esp+8h] [ebp-8h]
  char *v7; // [esp+Ch] [ebp-4h]

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\GroupMgr.cpp",
         449,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 < 1 || a3 > 10)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 450, "(_iGroupId >= GROUP_FIRST) && (_iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  v7 = (char *)this + 2244 * a2 + 204 * a3 + 104;
  while ( 1 )
  {
    result = TStaticArray<unsigned short,100>::Size(v7);
    if ( result <= 0 )
      break;
    v6 = TStaticArray<unsigned short,100>::Size(v7);
    v4 = *(unsigned __int16 *)TStaticArray<unsigned short,100>::operator[](v6 - 1);
    (*(void (__thiscall **)(CGroupMgr *, int, int, int))(*(_DWORD *)this + 24))(this, a2, a3, v4);
    if ( TStaticArray<unsigned short,100>::Size(v7) != v6 - 1
      && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 461, "rGroupArray.Size() == (iOldSize - 1)") == 1 )
    {
      __debugbreak();
    }
    if ( TStaticArray<unsigned short,100>::Size(v7) >= v6 )
    {
      if ( *(unsigned __int16 *)TStaticArray<unsigned short,100>::operator[](v6 - 1) != v4
        && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 465, "rGroupArray[iOldSize - 1] == iEntityId") == 1 )
      {
        __debugbreak();
      }
      TStaticArray<unsigned short,100>::PopBack(v7, 0);
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

bool  CGroupMgr::HasSquadLeader(int,int) {
  
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
  return (*((_BYTE *)this + 11 * a2 + a3 + 4) & 1) != 0;
}


// address=[0x1551490]
// Decompiled from void __thiscall CGroupMgr::SendGroupCommand(
        CGroupMgr *this,
        int a2,
        const unsigned __int16 *a3,
        int a4,
        int a5,
        int a6)

void  CGroupMgr::SendGroupCommand(int,unsigned short const *,int,int,int) {
  
  int v6; // eax
  _BYTE v7[24]; // [esp+4h] [ebp-22Ch] BYREF
  _BYTE v8[24]; // [esp+1Ch] [ebp-214h] BYREF
  int v9; // [esp+34h] [ebp-1FCh]
  int v10; // [esp+38h] [ebp-1F8h]
  CGroupMgr *v11; // [esp+3Ch] [ebp-1F4h]
  CEntityEvent *v12; // [esp+40h] [ebp-1F0h]
  CEntityEvent *v13; // [esp+44h] [ebp-1ECh]
  int v14; // [esp+48h] [ebp-1E8h]
  int v15; // [esp+4Ch] [ebp-1E4h]
  int v16; // [esp+50h] [ebp-1E0h]
  int v17; // [esp+54h] [ebp-1DCh]
  CEntityEvent *v18; // [esp+58h] [ebp-1D8h]
  CEntityEvent *v19; // [esp+5Ch] [ebp-1D4h]
  int v20; // [esp+60h] [ebp-1D0h]
  int v21; // [esp+64h] [ebp-1CCh]
  int NextDestination; // [esp+68h] [ebp-1C8h]
  int v23; // [esp+6Ch] [ebp-1C4h]
  _DWORD *v24; // [esp+70h] [ebp-1C0h]
  unsigned __int8 *v25; // [esp+74h] [ebp-1BCh]
  _DWORD *v26; // [esp+78h] [ebp-1B8h]
  _DWORD *v27; // [esp+7Ch] [ebp-1B4h]
  int v28; // [esp+80h] [ebp-1B0h]
  int v29; // [esp+84h] [ebp-1ACh]
  _BYTE v30[408]; // [esp+88h] [ebp-1A8h] BYREF
  int v31; // [esp+22Ch] [ebp-4h]

  v11 = this;
  if ( a2 > 0 && a3 )
  {
    v29 = -1;
    v28 = 0;
    while ( 1 )
    {
      v21 = a3[v28];
      v24 = (_DWORD *)CMapObjectMgr::EntityPtr(v21);
      if ( v24 )
      {
        if ( (_UNKNOWN *)IEntity::FlagBits(v24, (EntityFlag)&loc_2008000) == (_UNKNOWN *)((char *)&loc_1FFFFFF + 1) )
          break;
      }
      if ( ++v28 >= a2 )
        goto LABEL_8;
    }
    v29 = v28;
LABEL_8:
    if ( v29 >= 0 )
    {
      if ( (a6 & 8) != 0 )
      {
        while ( v29 < a2 )
        {
          v20 = a3[v29];
          v27 = (_DWORD *)CMapObjectMgr::EntityPtr(v20);
          if ( v27 )
          {
            if ( (_UNKNOWN *)IEntity::FlagBits(v27, (EntityFlag)&loc_2008000) == (_UNKNOWN *)((char *)&loc_1FFFFFF + 1) )
            {
              v19 = CEntityEvent::CEntityEvent((CEntityEvent *)v8, 0x11u, 13, a6, 0, 0);
              v18 = v19;
              v31 = 0;
              (*(void (__thiscall **)(_DWORD *, CEntityEvent *))(*v27 + 80))(v27, v19);
              v31 = -1;
              CEntityEvent::~CEntityEvent(v8);
            }
          }
          ++v29;
        }
      }
      else
      {
        v14 = Y16X16::PackXYFast(a4, a5);
        v10 = a4;
        v9 = a5;
        v17 = a3[v29];
        v25 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v17);
        if ( !v25 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 697, "pFirstEntity != 0") == 1 )
          __debugbreak();
        if ( IEntity::ObjType(v25) == 4 )
          v23 = 3;
        else
          v23 = 1;
        v16 = v23;
        v6 = IEntity::PackedXY(v25);
        CGroupDestinations::CGroupDestinations((CGroupDestinations *)v30, a4, a5, a2, v23, v6);
        while ( v29 < a2 )
        {
          v15 = a3[v29];
          v26 = (_DWORD *)CMapObjectMgr::EntityPtr(v15);
          if ( v26
            && (_UNKNOWN *)IEntity::FlagBits(v26, (EntityFlag)&loc_2008000) == (_UNKNOWN *)((char *)&loc_1FFFFFF + 1) )
          {
            NextDestination = CGroupDestinations::GetNextDestination(v30);
            if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(NextDestination)
              && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 713, "g_cWorld.InWorldPackedXY(iDestXY)") == 1 )
            {
              __debugbreak();
            }
            v13 = CEntityEvent::CEntityEvent((CEntityEvent *)v7, 0x11u, 13, a6, NextDestination, v14);
            v12 = v13;
            v31 = 1;
            (*(void (__thiscall **)(_DWORD *, CEntityEvent *))(*v26 + 80))(v26, v13);
            v31 = -1;
            CEntityEvent::~CEntityEvent(v7);
          }
          ++v29;
        }
      }
    }
  }
}


// address=[0x1551850]
// Decompiled from int __thiscall CGroupMgr::Load(CGroupMgr *this, struct IS4Chunk *a2)

void  CGroupMgr::Load(class IS4Chunk &) {
  
  int v3; // [esp+8h] [ebp-18h]
  int k; // [esp+Ch] [ebp-14h]
  int j; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  __int16 v8; // [esp+1Eh] [ebp-2h] BYREF

  (*(void (__thiscall **)(CGroupMgr *))(*(_DWORD *)this + 8))(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 844624217);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 10, 10);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 100, 100);
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 11; ++j )
    {
      *((_BYTE *)this + 11 * i + j + 4) = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(
                                            a2,
                                            0,
                                            255);
      v3 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 100);
      for ( k = 0; k < v3; ++k )
      {
        v8 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 0xFFFF);
        TStaticArray<unsigned short,100>::PushBack(&v8);
      }
    }
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 844624209);
}


// address=[0x15519a0]
// Decompiled from int __thiscall CGroupMgr::Save(CGroupMgr *this, struct IS4Chunk *a2)

void  CGroupMgr::Save(class IS4Chunk &) {
  
  unsigned __int16 *v2; // eax
  int v4; // [esp+0h] [ebp-14h]
  int k; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 844624217);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 10);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 100);
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 11; ++j )
    {
      (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(
        a2,
        *((unsigned __int8 *)this + 11 * i + j + 4));
      v4 = TStaticArray<unsigned short,100>::Size((char *)this + 2244 * i + 204 * j + 104);
      (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v4);
      for ( k = 0; k < v4; ++k )
      {
        v2 = (unsigned __int16 *)TStaticArray<unsigned short,100>::operator[](k);
        (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *v2);
      }
    }
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 844624209);
}


// address=[0x1551ae0]
// Decompiled from _DWORD *__thiscall CGroupMgr::FillGroupSideBarEx(char *this, void **a2, char a3, int a4)

void  CGroupMgr::FillGroupSideBarEx(class CInfoExchange *,bool,int) {
  
  _DWORD *result; // eax
  unsigned __int16 *v5; // eax
  int v6; // [esp+0h] [ebp-64h]
  CEvn_Event *v7; // [esp+4h] [ebp-60h]
  int LocalPlayerId; // [esp+1Ch] [ebp-48h]
  unsigned int v10; // [esp+20h] [ebp-44h]
  int v11; // [esp+24h] [ebp-40h]
  int i; // [esp+34h] [ebp-30h]
  unsigned int v13; // [esp+38h] [ebp-2Ch]
  CEvn_Event v14; // [esp+3Ch] [ebp-28h] BYREF
  int v15; // [esp+60h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 494, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  result = (_DWORD *)j____RTDynamicCast(
                       a2,
                       0,
                       &CInfoExchange__RTTI_Type_Descriptor_,
                       &CGroupSideBarInfo__RTTI_Type_Descriptor_,
                       0);
  v13 = (unsigned int)result;
  if ( !result )
  {
    result = (_DWORD *)BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 498, "pGroupSideBar != 0");
    if ( result == (_DWORD *)1 )
      __debugbreak();
  }
  if ( !v13 )
    return result;
  (**(void (__thiscall ***)(unsigned int))v13)(v13);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v6);
  for ( i = 1; i <= 10; ++i )
  {
    if ( TStaticArray<unsigned short,100>::Size(&this[2244 * LocalPlayerId + 104 + 204 * i]) > 0 )
    {
      v5 = (unsigned __int16 *)TStaticArray<unsigned short,100>::operator[](0);
      if ( CMapObjectMgr::EntityPtr(*v5) )
        v11 = IEntity::WarriorType();
      else
        v11 = 0;
      switch ( v11 )
      {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
          *(_DWORD *)(v13 + 4 * i + 4) = 1;
          break;
        case 7:
          *(_DWORD *)(v13 + 4 * i + 4) = 2;
          break;
        case 10:
        case 11:
          *(_DWORD *)(v13 + 4 * i + 4) = 3;
          break;
        default:
          continue;
      }
    }
  }
  *(_DWORD *)(v13 + 4) = 25;
  if ( a3 )
    v10 = 606;
  else
    v10 = 607;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 564, "g_pEvnEngine != 0") == 1 )
    __debugbreak();
  result = 0;
  if ( !g_pEvnEngine )
    return result;
  v7 = CEvn_Event::CEvn_Event(&v14, v10, 0, v13, 0);
  v15 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v7);
  v15 = -1;
  return CEvn_Event::~CEvn_Event(&v14);
}


// address=[0x1551d50]
// Decompiled from unsigned int __stdcall CGroupMgr::FillMagicSideBarEx(void **a1, unsigned __int8 a2, int a3)

void  CGroupMgr::FillMagicSideBarEx(class CInfoExchange *,bool,int) {
  
  unsigned int result; // eax
  int v4; // [esp+0h] [ebp-60h]
  CEvn_Event *v5; // [esp+8h] [ebp-58h]
  int v6; // [esp+18h] [ebp-48h]
  unsigned int v7; // [esp+1Ch] [ebp-44h]
  int CurrentSpellCategoryCost; // [esp+20h] [ebp-40h]
  int v9; // [esp+24h] [ebp-3Ch]
  int CurrentManaAmount; // [esp+28h] [ebp-38h]
  int LocalPlayerId; // [esp+2Ch] [ebp-34h]
  unsigned int v12; // [esp+30h] [ebp-30h]
  int i; // [esp+34h] [ebp-2Ch]
  CEvn_Event v14; // [esp+38h] [ebp-28h] BYREF
  int v15; // [esp+5Ch] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 587, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  result = j____RTDynamicCast(
             a1,
             0,
             &CInfoExchange__RTTI_Type_Descriptor_,
             &CMagicSpellSideBarInfo__RTTI_Type_Descriptor_,
             0);
  v12 = result;
  if ( !result )
  {
    result = BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 591, "pMagicSpellSideBar != 0");
    if ( result == 1 )
      __debugbreak();
  }
  if ( !v12 )
    return result;
  (**(void (__thiscall ***)(unsigned int))v12)(v12);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v4);
  for ( i = 0; i < 8; ++i )
  {
    v6 = CMagic::CalculatePossibleNumberOfCastSpell(LocalPlayerId, i, 0);
    CurrentSpellCategoryCost = CMagic::GetCurrentSpellCategoryCost(LocalPlayerId, i);
    CurrentManaAmount = CMagic::GetCurrentManaAmount(LocalPlayerId);
    if ( CurrentManaAmount <= 0 )
      v9 = 0;
    else
      v9 = 100 * CurrentSpellCategoryCost / CurrentManaAmount;
    *(_DWORD *)(v12 + 16 * i + 12) = v6;
    *(_DWORD *)(v12 + 16 * i + 16) = v9;
    *(_DWORD *)(v12 + 16 * i + 20) = CurrentSpellCategoryCost;
    *(_DWORD *)(v12 + 16 * i + 8) = i;
  }
  *(_DWORD *)(v12 + 4) = 26;
  result = a2;
  if ( a2 )
    v7 = 606;
  else
    v7 = 607;
  if ( !g_pEvnEngine )
  {
    result = BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 620, "g_pEvnEngine != 0");
    if ( result == 1 )
      __debugbreak();
  }
  if ( !g_pEvnEngine )
    return result;
  v5 = CEvn_Event::CEvn_Event(&v14, v7, 0, v12, 0);
  v15 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v5);
  v15 = -1;
  return (unsigned int)CEvn_Event::~CEvn_Event(&v14);
}


// address=[0x1552590]
// Decompiled from CGroupMgr *__thiscall CGroupMgr::CGroupMgr(CGroupMgr *this)

 CGroupMgr::CGroupMgr(void) {
  
  IGroupMgr::IGroupMgr(this);
  *(_DWORD *)this = CGroupMgr::_vftable_;
  `vector constructor iterator'(
    (char *)this + 104,
    0xCCu,
    0x63u,
    (void *(__thiscall *)(void *))TStaticArray<unsigned short,100>::TStaticArray<unsigned short,100>);
  return this;
}


