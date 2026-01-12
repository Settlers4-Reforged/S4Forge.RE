#include "CAlliances.h"

// Definitions for class CAlliances

// address=[0x1301120]
// Decompiled from int __cdecl CAlliances::AllianceId(int a1)
static int __cdecl CAlliances::AllianceId(int) {
  
  return dword_415C3D4[a1];
}


// address=[0x1301520]
// Decompiled from bool __cdecl CAlliances::IsValidUsedPlayerId(int a1)
static bool __cdecl CAlliances::IsValidUsedPlayerId(int) {
  
  return (unsigned int)(a1 - 1) <= 7 && dword_415C3D4[a1] > 0;
}


// address=[0x1301620]
// Decompiled from int __cdecl CAlliances::PlayerAllyBits(int a1)
static int __cdecl CAlliances::PlayerAllyBits(int) {
  
  return dword_415C3F8[a1];
}


// address=[0x1301640]
// Decompiled from int __cdecl CAlliances::PlayerBit(char a1)
static int __cdecl CAlliances::PlayerBit(int) {
  
  return 1 << a1 >> 1;
}


// address=[0x1301660]
// Decompiled from int __cdecl CAlliances::PlayerEnemyBits(int a1)
static int __cdecl CAlliances::PlayerEnemyBits(int) {
  
  return dword_415C41C[a1];
}


// address=[0x1303c80]
// Decompiled from int CAlliances::LastPlayerId()
static int __cdecl CAlliances::LastPlayerId(void) {
  
  return dword_415C3C8;
}


// address=[0x13094a0]
// Decompiled from int *__cdecl CAlliances::EnemyPlayerIds(int a1)
static int const * __cdecl CAlliances::EnemyPlayerIds(int) {
  
  return &dword_415C5A8[8 * a1];
}


// address=[0x130e8e0]
// Decompiled from int *__cdecl CAlliances::AllyPlayerIds(int a1)
static int const * __cdecl CAlliances::AllyPlayerIds(int) {
  
  return &dword_415C488[8 * a1];
}


// address=[0x13172d0]
// Decompiled from int CAlliances::AllPlayersBits()
static int __cdecl CAlliances::AllPlayersBits(void) {
  
  return dword_415C3D0;
}


// address=[0x1317430]
// Decompiled from int CAlliances::LastAllianceId()
static int __cdecl CAlliances::LastAllianceId(void) {
  
  return dword_415C3CC;
}


// address=[0x15d2fc0]
// Decompiled from void *CAlliances::Init()
static void __cdecl CAlliances::Init(void) {
  
  void *result; // eax

  result = j__memset(&CAlliances::m_sData, 0, 0x308u);
  CAlliances::m_iInitialized = 1;
  CAlliances::m_iLocked = 0;
  return result;
}


// address=[0x15d3010]
// Decompiled from void *CAlliances::Done()
static void __cdecl CAlliances::Done(void) {
  
  void *result; // eax

  result = j__memset(&CAlliances::m_sData, 0, 0x308u);
  CAlliances::m_iInitialized = 0;
  CAlliances::m_iLocked = 0;
  return result;
}


// address=[0x15d3040]
// Decompiled from char __cdecl CAlliances::AddPlayer(int a1, int a2)
static bool __cdecl CAlliances::AddPlayer(int,int) {
  
  if ( CAlliances::m_iInitialized )
  {
    if ( CAlliances::m_iLocked )
    {
      if ( BBSupportDbgReport(1, "Pathing\\Alliances.cpp", 83, "CAlliances::AddPlayer(): Already locked!") == 1 )
        __debugbreak();
      return 0;
    }
    else if ( a1 >= 1 && a1 <= 8 )
    {
      if ( a2 != 9 && (a2 > 8 || a2 < 1) )
      {
        if ( BBSupportDbgReport(1, "Pathing\\Alliances.cpp", 97, "CAlliances::AddPlayer(): Invalid alliance id!") == 1 )
          __debugbreak();
        return 0;
      }
      else if ( dword_415C3D4[a1] )
      {
        if ( BBSupportDbgReport(
               1,
               "Pathing\\Alliances.cpp",
               104,
               "CAlliances::AddPlayer(): Player already in alliance!") == 1 )
          __debugbreak();
        return 0;
      }
      else
      {
        ++CAlliances::m_sData;
        if ( a1 > dword_415C3C8 )
          dword_415C3C8 = a1;
        dword_415C3D4[a1] = a2;
        if ( a2 != 9 )
          ++dword_415C440[a2];
        return 1;
      }
    }
    else
    {
      if ( BBSupportDbgReport(1, "Pathing\\Alliances.cpp", 90, "CAlliances::AddPlayer(): Invalid player id!") == 1 )
        __debugbreak();
      return 0;
    }
  }
  else
  {
    if ( BBSupportDbgReport(1, "Pathing\\Alliances.cpp", 76, "CAlliances::AddPlayer(): Not initialized!") == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x15d31c0]
// Decompiled from char CAlliances::Lock()
static bool __cdecl CAlliances::Lock(void) {
  
  const int *v1; // esi
  const int *v2; // esi
  int v3; // [esp+4h] [ebp-70h]
  int v4; // [esp+8h] [ebp-6Ch]
  int v5; // [esp+Ch] [ebp-68h]
  int v6; // [esp+10h] [ebp-64h]
  int v7; // [esp+1Ch] [ebp-58h]
  int v8; // [esp+20h] [ebp-54h]
  int v9; // [esp+24h] [ebp-50h]
  int v10; // [esp+28h] [ebp-4Ch]
  int v11; // [esp+2Ch] [ebp-48h]
  int m; // [esp+30h] [ebp-44h]
  int i; // [esp+34h] [ebp-40h]
  int k; // [esp+38h] [ebp-3Ch]
  int ii; // [esp+3Ch] [ebp-38h]
  int n; // [esp+40h] [ebp-34h]
  int v17; // [esp+44h] [ebp-30h]
  int j; // [esp+48h] [ebp-2Ch]
  _DWORD v19[9]; // [esp+4Ch] [ebp-28h] BYREF

  if ( CAlliances::m_iInitialized )
  {
    if ( CAlliances::m_iLocked )
    {
      if ( BBSupportDbgReport(1, "Pathing\\Alliances.cpp", 150, "CAlliances::Lock(): Already locked!") == 1 )
        __debugbreak();
      return 0;
    }
    else
    {
      CAlliances::m_iLocked = 1;
      v17 = 1;
      for ( i = 1; i <= dword_415C3C8; ++i )
      {
        if ( dword_415C3D4[i] == 9 )
        {
          while ( dword_415C440[v17] != 0 && v17 < 8 )
            ++v17;
          if ( dword_415C440[v17]
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Alliances.cpp",
                 171,
                 "m_sData.m_iAlliancesNumberOfAllies[iAllianceId] == 0") == 1 )
          {
            __debugbreak();
          }
          dword_415C3D4[i] = v17;
          dword_415C440[v17] = 1;
        }
      }
      for ( j = 1; j <= 8; ++j )
      {
        v6 = dword_415C440[j];
        if ( v6 > 0 )
        {
          ++dword_415C3C4;
          dword_415C3CC = j;
          dword_415C464[j] = CAlliances::m_sData - v6;
          if ( dword_415C464[j] > 7
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Alliances.cpp",
                 197,
                 "m_sData.m_iAlliancesNumberOfEnemies[iAllianceId] <= (PLAYER_LAST - PLAYER_FIRST)") == 1 )
          {
            __debugbreak();
          }
          v10 = 0;
          v9 = 0;
          v3 = dword_415C3C8;
          for ( k = 1; k <= v3; ++k )
          {
            v5 = dword_415C3D4[k];
            if ( v5 )
            {
              if ( v5 == j )
                dword_415C488[8 * j + v10++] = k;
              else
                dword_415C5A8[8 * j + v9++] = k;
            }
          }
          if ( dword_415C440[j] != v10
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Alliances.cpp",
                 224,
                 "m_sData.m_iAlliancesNumberOfAllies[iAllianceId] == iAllyCounter") == 1 )
          {
            __debugbreak();
          }
          if ( dword_415C464[j] != v9
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Alliances.cpp",
                 225,
                 "m_sData.m_iAlliancesNumberOfEnemies[iAllianceId] == iEnemyCounter") == 1 )
          {
            __debugbreak();
          }
        }
      }
      v11 = 0;
      j__memset(v19, 0, sizeof(v19));
      for ( m = 1; m <= dword_415C3C8; ++m )
      {
        v4 = CAlliances::PlayerBit(m);
        v7 = dword_415C3D4[m];
        if ( v7 )
        {
          v11 |= v4;
          v19[v7] |= v4;
        }
      }
      dword_415C3D0 = v11;
      for ( n = 1; n <= dword_415C3C8; ++n )
      {
        v8 = dword_415C3D4[n];
        if ( v8 )
        {
          dword_415C3F8[n] = v19[v8];
          dword_415C41C[n] = v11 & ~v19[v8];
          if ( dword_415C41C[n] != (v19[v8] ^ v11)
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Alliances.cpp",
                 265,
                 "m_sData.m_iPlayersEnemyBits[iPlayerId] == (iAllPlayersBits ^ iAlliancesAllyBits[iAllianceId])") == 1 )
          {
            __debugbreak();
          }
        }
      }
      for ( ii = 1; ii <= 8; ++ii )
      {
        v1 = CAlliances::AllyPlayerIds(ii);
        if ( v1[CAlliances::NumberOfAllies(ii)]
          && BBSupportDbgReport(
               2,
               "Pathing\\Alliances.cpp",
               277,
               "AllyPlayerIds(iAllianceId)[NumberOfAllies(iAllianceId)] == PLAYER_NO_PLAYER") == 1 )
        {
          __debugbreak();
        }
        v2 = CAlliances::EnemyPlayerIds(ii);
        if ( v2[CAlliances::NumberOfEnemies(ii)]
          && BBSupportDbgReport(
               2,
               "Pathing\\Alliances.cpp",
               278,
               "EnemyPlayerIds(iAllianceId)[NumberOfEnemies(iAllianceId)] == PLAYER_NO_PLAYER") == 1 )
        {
          __debugbreak();
        }
      }
      return 1;
    }
  }
  else
  {
    if ( BBSupportDbgReport(1, "Pathing\\Alliances.cpp", 143, "CAlliances::Lock(): Not initialized!") == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x15d37e0]
// Decompiled from int __cdecl CAlliances::NumberOfAllies(int a1)
static int __cdecl CAlliances::NumberOfAllies(int) {
  
  return dword_415C440[a1];
}


// address=[0x15d3800]
// Decompiled from int __cdecl CAlliances::NumberOfEnemies(int a1)
static int __cdecl CAlliances::NumberOfEnemies(int) {
  
  return dword_415C464[a1];
}


// address=[0x15db1f0]
// Decompiled from int CAlliances::NumberOfPlayers()
static int __cdecl CAlliances::NumberOfPlayers(void) {
  
  return CAlliances::m_sData;
}


// address=[0x160dac0]
// Decompiled from int CAlliances::NumberOfAlliances()
static int __cdecl CAlliances::NumberOfAlliances(void) {
  
  return dword_415C3C4;
}


// address=[0x415c3b4]
// [Decompilation failed for static int CAlliances::m_iInitialized]

// address=[0x415c3b8]
// [Decompilation failed for static int CAlliances::m_iLocked]

// address=[0x415c3c0]
// [Decompilation failed for static struct CAlliances::SAlliancesData CAlliances::m_sData]

