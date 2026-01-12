#include "CAIEnemySettlerInSectorIterator.h"

// Definitions for class CAIEnemySettlerInSectorIterator

// address=[0x130d470]
// Decompiled from CAIEnemySettlerInSectorIterator *__thiscall CAIEnemySettlerInSectorIterator::CAIEnemySettlerInSectorIterator(  CAIEnemySettlerInSectorIterator *this,  int a2,  int a3,  int a4)
 CAIEnemySettlerInSectorIterator::CAIEnemySettlerInSectorIterator(int,int,int) {
  
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+4h] [ebp-8h]

  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  if ( !IAIEnvironment::AlliancesIsValidUsedPlayerId(a2)
    && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1931, "g_pAIEnv->AlliancesIsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1932, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1933, "_iSectorId > 0") == 1 )
    __debugbreak();
  v5 = IAIEnvironment::AlliancesAllianceId(a2);
  *(_DWORD *)this = IAIEnvironment::AlliancesEnemyPlayerIds(v5);
  if ( !*(_DWORD *)this && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1939, "m_pEnemyPlayerIds != 0") == 1 )
    __debugbreak();
  v6 = **(_DWORD **)this;
  if ( v6
    && !IAIEnvironment::AlliancesIsValidUsedPlayerId(v6)
    && BBSupportDbgReport(
         2,
         "AI\\AI_Environment.cpp",
         1943,
         "(iEnemyPlayerId == PLAYER_NO_PLAYER) || g_pAIEnv->AlliancesIsValidUsedPlayerId(iEnemyPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( v6 )
  {
    *((_DWORD *)this + 3) = -1;
    *((_DWORD *)this + 4) = 0;
  }
  else
  {
    *((_DWORD *)this + 3) = 0;
    *((_DWORD *)this + 4) = -1;
  }
  return this;
}


// address=[0x130d5e0]
// Decompiled from char __thiscall CAIEnemySettlerInSectorIterator::NextEnemySettler(_DWORD *this, int *a2)
bool  CAIEnemySettlerInSectorIterator::NextEnemySettler(int &) {
  
  int v3; // [esp+4h] [ebp-28h]
  int v4; // [esp+8h] [ebp-24h]
  int v5; // [esp+Ch] [ebp-20h]
  bool v6; // [esp+14h] [ebp-18h]
  int v7; // [esp+18h] [ebp-14h]
  int v8; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *v9; // [esp+20h] [ebp-Ch]
  int FirstSettlerId; // [esp+24h] [ebp-8h]

  FirstSettlerId = this[4];
  if ( FirstSettlerId >= 0 )
  {
    if ( (int)this[3] >= 0
      && !*(_DWORD *)(*this + 4 * this[3])
      && BBSupportDbgReport(
           2,
           "AI\\AI_Environment.cpp",
           1973,
           "(m_iCurrentPlayerIdx < 0) || (m_pEnemyPlayerIds[m_iCurrentPlayerIdx] != PLAYER_NO_PLAYER)") == 1 )
    {
      __debugbreak();
    }
    if ( FirstSettlerId > 0 )
    {
      v4 = CSettlerMgr::operator[](FirstSettlerId);
      FirstSettlerId = IAnimatedEntity::Next(v4);
    }
    while ( 1 )
    {
      while ( FirstSettlerId )
      {
        v9 = (unsigned __int8 *)CSettlerMgr::operator[](FirstSettlerId);
        if ( IEntity::ObjType(v9) != 1
          && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1988, "rSettler.ObjType() == SETTLER_OBJ") == 1 )
        {
          __debugbreak();
        }
        if ( IEntity::Type((unsigned __int16 *)v9) != this[1]
          && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1989, "rSettler.Type() == m_iSettlerType") == 1 )
        {
          __debugbreak();
        }
        v6 = IEntity::FlagBits(v9, AliveMask) != 0;
        if ( IEntity::FlagBits(v9, OnBoard) == 0 && v6 )
        {
          v7 = IEntity::X(v9);
          v8 = IEntity::Y(v9);
          if ( !(unsigned __int8)CWorldManager::InWorld(v7, v8)
            && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1996, "g_cWorld.InWorld(iX, iY)") == 1 )
          {
            __debugbreak();
          }
          if ( CWorldManager::SettlerId(v7, v8) != FirstSettlerId
            && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1997, "g_cWorld.SettlerId(iX, iY) == iSettlerId") == 1 )
          {
            __debugbreak();
          }
          v3 = CWorldManager::Index(v7, v8);
          if ( ITiling::SectorId(v3) == this[2] )
          {
            *a2 = FirstSettlerId;
            this[4] = FirstSettlerId;
            return 1;
          }
        }
        FirstSettlerId = IAnimatedEntity::Next(v9);
      }
      ++this[3];
      v5 = *(_DWORD *)(*this + 4 * this[3]);
      if ( !v5 )
        break;
      FirstSettlerId = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v5, this[1]);
    }
    *a2 = 0;
    this[4] = -1;
    return 0;
  }
  else
  {
    *a2 = 0;
    return 0;
  }
}


