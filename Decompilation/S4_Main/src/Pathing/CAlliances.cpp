#include "CAlliances.h"

#include "CBB/CBBSupport.h"
#include "Defines/Players.h"

// Definitions for class CAlliances

// address=[0x1301120]
// Decompiled from int __cdecl CAlliances::AllianceId(int a1)
int __cdecl CAlliances::AllianceId(int a1) {
  return m_sData.m_iAllianceIds[a1];
}


// address=[0x1301520]
// Decompiled from bool __cdecl CAlliances::IsValidUsedPlayerId(int a1)
bool __cdecl CAlliances::IsValidUsedPlayerId(int a1) {
  return (unsigned int) (a1 - 1) <= 7 && m_sData.m_iAllianceIds[a1] > 0;
}


// address=[0x1301620]
// Decompiled from int __cdecl CAlliances::PlayerAllyBits(int a1)
int __cdecl CAlliances::PlayerAllyBits(int a1) {
  return m_sData.m_iPlayersAllyBits[a1];
}


// address=[0x1301640]
// Decompiled from int __cdecl CAlliances::PlayerBit(char a1)
int __cdecl CAlliances::PlayerBit(int a1) {
  return 1 << a1 >> 1;
}


// address=[0x1301660]
// Decompiled from int __cdecl CAlliances::PlayerEnemyBits(int a1)
int __cdecl CAlliances::PlayerEnemyBits(int a1) {
  return m_sData.m_iPlayersEnemyBits[a1];
}


// address=[0x1303c80]
// Decompiled from int CAlliances::LastPlayerId()
int __cdecl CAlliances::LastPlayerId(void) {
  return m_sData.m_iLastPlayerId;
}


// address=[0x13094a0]
// Decompiled from int *__cdecl CAlliances::EnemyPlayerIds(int a1)
int const * __cdecl CAlliances::EnemyPlayerIds(int a1) {
  return m_sData.m_iEnemyPlayerIds[a1];
}


// address=[0x130e8e0]
// Decompiled from int *__cdecl CAlliances::AllyPlayerIds(int a1)
int const * __cdecl CAlliances::AllyPlayerIds(int a1) {
  return m_sData.m_iAllyPlayerIds[a1];
}


// address=[0x13172d0]
// Decompiled from int CAlliances::AllPlayersBits()
int __cdecl CAlliances::AllPlayersBits(void) {
  return m_sData.m_iAllPlayersBits;
}


// address=[0x1317430]
// Decompiled from int CAlliances::LastAllianceId()
int __cdecl CAlliances::LastAllianceId(void) {
  return m_sData.m_iLastAllianceId;
}


// address=[0x15d2fc0]
// Decompiled from void *CAlliances::Init()
void __cdecl CAlliances::Init(void) {
  memset(&CAlliances::m_sData, 0, sizeof(m_sData));
  m_iInitialized = 1;
  m_iLocked = 0;
}


// address=[0x15d3010]
// Decompiled from void *CAlliances::Done()
void __cdecl CAlliances::Done(void) {
  memset(&CAlliances::m_sData, 0, sizeof(m_sData));
  m_iInitialized = 0;
  m_iLocked = 0;
}


// address=[0x15d3040]
// Decompiled from char __cdecl CAlliances::AddPlayer(int _iPlayerId, int iAllianceId)
bool __cdecl CAlliances::AddPlayer(int _iPlayerId, int iAllianceId) {
  if(!m_iInitialized) {
    BB_REPORT("CAlliances::AddPlayer(): Not initialized!");
    return false;
  }
  if(m_iLocked) {
    BB_REPORT("CAlliances::AddPlayer(): Already locked!");
    return false;
  }
  if(_iPlayerId < 1 || _iPlayerId > 8) {
    BB_REPORT("CAlliances::AddPlayer(): Invalid player id!");
    return false;
  }
  if(iAllianceId != 9 && (iAllianceId > 8 || iAllianceId < 1)) {
    BB_REPORT("CAlliances::AddPlayer(): Invalid alliance id!");
    return false;
  }
  if(m_sData.m_iAllianceIds[_iPlayerId]) {
    BB_REPORT("CAlliances::AddPlayer():  Player already in alliance!");
    return false;
  }

  ++m_sData.m_iNumberOfPlayers;
  if(_iPlayerId > m_sData.m_iLastPlayerId)
    m_sData.m_iLastPlayerId = _iPlayerId;
  m_sData.m_iAllianceIds[_iPlayerId] = iAllianceId;
  if(iAllianceId != 9)
    ++m_sData.m_iAlliancesNumberOfAllies[iAllianceId];
  return true;
}


// address=[0x15d31c0]
// Decompiled from char CAlliances::Lock()
bool __cdecl CAlliances::Lock(void) {
  // esi
  // esi
  _DWORD iAllyBits[9]; // [esp+4Ch] [ebp-28h] BYREF

  if(!m_iInitialized) {
    BB_REPORT("CAlliances::Lock(): Not initialized!");
    return false;
  }
  if(m_iLocked) {
    BB_REPORT("CAlliances::Lock(): Already locked!");
    return false;
  }

  m_iLocked = 1;
  int iAllianceId = 1;
  for(int i = 1; i <= m_sData.m_iLastPlayerId; ++i) {
    if(m_sData.m_iAllianceIds[i] == 9) {
      while(m_sData.m_iAlliancesNumberOfAllies[iAllianceId] != 0 && iAllianceId < 8)
        ++iAllianceId;
      BB_ASSERT(m_sData.m_iAlliancesNumberOfAllies[iAllianceId] == 0)
      m_sData.m_iAllianceIds[i] = iAllianceId;
      m_sData.m_iAlliancesNumberOfAllies[iAllianceId] = 1;
    }
  }
  for(iAllianceId = 1; iAllianceId <= 8; ++iAllianceId) {
    int iPlayerId = m_sData.m_iAlliancesNumberOfAllies[iAllianceId];
    if(iPlayerId > 0) {
      ++m_sData.m_iNumberOfAlliances;
      m_sData.m_iLastAllianceId = iAllianceId;
      m_sData.m_iAlliancesNumberOfEnemies[iAllianceId] = m_sData.m_iNumberOfPlayers - iPlayerId;

      static_assert((PLAYER_LAST - PLAYER_FIRST) == 7, "This code here assumes that there are at most 7 players");
      BB_ASSERT(m_sData.m_iAlliancesNumberOfEnemies[iAllianceId] <= (PLAYER_LAST - PLAYER_FIRST))

      int iAllyCounter = 0;
      int iEnemyCounter = 0;
      int iLastPlayerId = m_sData.m_iLastPlayerId;
      for(int k = 1; k <= iLastPlayerId; ++k) {
        int v5 = m_sData.m_iAllianceIds[k];
        if(v5) {
          if(v5 == iAllianceId)
            m_sData.m_iAllyPlayerIds[iAllianceId][iAllyCounter++] = k;
          else
            m_sData.m_iEnemyPlayerIds[iAllianceId][iEnemyCounter++] = k;
        }
      }
      BB_ASSERT(m_sData.m_iAlliancesNumberOfAllies[iAllianceId] == iAllyCounter)
      BB_ASSERT(m_sData.m_iAlliancesNumberOfEnemies[iAllianceId] == iEnemyCounter)
    }
  }
  int iAllPlayerBits = 0;
  memset(iAllyBits, 0, sizeof(iAllyBits));
  for(int m = 1; m <= m_sData.m_iLastPlayerId; ++m) {
    int v4 = PlayerBit(m);
    int v7 = m_sData.m_iAllianceIds[m];
    if(v7) {
      iAllPlayerBits |= v4;
      iAllyBits[v7] |= v4;
    }
  }
  m_sData.m_iAllPlayersBits = iAllPlayerBits;
  for(iAllianceId = 1; iAllianceId <= m_sData.m_iLastPlayerId; ++iAllianceId) {
    int iThisAlliance = m_sData.m_iAllianceIds[iAllianceId];
    if(iThisAlliance) {
      m_sData.m_iPlayersAllyBits[iAllianceId] = iAllyBits[iThisAlliance];
      m_sData.m_iPlayersEnemyBits[iAllianceId] = iAllPlayerBits & ~iAllyBits[iThisAlliance];
      BB_ASSERT(m_sData.m_iPlayersEnemyBits[iAllianceId] == (iAllyBits[iThisAlliance] ^ iAllPlayerBits))
    }
  }
  for(iAllianceId = 1; iAllianceId <= 8; ++iAllianceId) {
    BB_ASSERT(AllyPlayerIds(iAllianceId)[NumberOfAllies(iAllianceId)] == PLAYER_NO_PLAYER)
    BB_ASSERT(EnemyPlayerIds(iAllianceId)[NumberOfEnemies(iAllianceId)] == PLAYER_NO_PLAYER)
  }
  return true;
}


// address=[0x15d37e0]
// Decompiled from int __cdecl CAlliances::NumberOfAllies(int a1)
int __cdecl CAlliances::NumberOfAllies(int a1) {
  return m_sData.m_iAlliancesNumberOfAllies[a1];
}


// address=[0x15d3800]
// Decompiled from int __cdecl CAlliances::NumberOfEnemies(int a1)
int __cdecl CAlliances::NumberOfEnemies(int a1) {
  return m_sData.m_iAlliancesNumberOfEnemies[a1];
}


// address=[0x15db1f0]
// Decompiled from int CAlliances::NumberOfPlayers()
int __cdecl CAlliances::NumberOfPlayers(void) {
  return m_sData.m_iNumberOfPlayers;
}


// address=[0x160dac0]
// Decompiled from int CAlliances::NumberOfAlliances()
int __cdecl CAlliances::NumberOfAlliances(void) {
  return m_sData.m_iNumberOfAlliances;
}


// address=[0x415c3b4]
// [Decompilation failed for static int CAlliances::m_iInitialized]

// address=[0x415c3b8]
// [Decompilation failed for static int CAlliances::m_iLocked]

// address=[0x415c3c0]
// [Decompilation failed for static struct CAlliances::SAlliancesData CAlliances::m_sData]

