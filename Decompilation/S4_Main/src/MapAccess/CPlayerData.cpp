#include "CPlayerData.h"

#include "CBB/CBBSupport.h"
#include "Defines/Players.h"
#include "LoadSave/SMapChunkHeader.h"

// Definitions for class CPlayerData

// address=[0x2fbefb0]
// Decompiled from CPlayerData *__thiscall CPlayerData::CPlayerData(CPlayerData *this)
CPlayerData::CPlayerData(void) {
  CPlayerData::Init();
}


// address=[0x2fbefd0]
// Decompiled from void __thiscall CPlayerData::Init(CPlayerData *this)
void CPlayerData::Init(void) {
  // [esp+0h] [ebp-14h]
  // [esp+4h] [ebp-10h]
  // [esp+Ch] [ebp-8h]
  char Source; // [esp+13h] [ebp-1h] BYREF

  this->m_iNumberOfSetups = 1;
  this->m_uNumberOfPlayers = 1;
  Source = 0;
  for(int i = 0; i < 8; ++i) {
    this->m_sPlayers[i].m_uX = 128;
    this->m_sPlayers[i].m_uY = 128;
    strncpy(this->m_sPlayers[i].m_sName, &Source, 0x21u);
    this->m_sPlayers[i].m_uRace = 0;
    for(int j = 0; j < 10; ++j) {
      this->m_sSetups[j][i].m_iPlayerControl = 1;
      this->m_sSetups[j][i].m_iTeam = 0;
    }
  }
  for(int k = 0; k < 10; ++k)
    memset(this->m_uSetupNames[k], 0, sizeof(this->m_uSetupNames[k]));
}


// address=[0x2fbf0f0]
// Decompiled from int __thiscall CPlayerData::GetNumberOfPlayers(CPlayerData *this)
int CPlayerData::GetNumberOfPlayers(void) {
  return this->m_uNumberOfPlayers;
}


// address=[0x2fbf110]
// Decompiled from int __thiscall CPlayerData::GetNumberOfSetups(CPlayerData *this)
int CPlayerData::GetNumberOfSetups(void) {
  return this->m_iNumberOfSetups;
}


// address=[0x2fbf130]
// Decompiled from int __thiscall CPlayerData::AddPlayer(CPlayerData *this, DWORD _iRace, DWORD _iX, DWORD _iY, char *_spName)
int CPlayerData::AddPlayer(int _iRace, int _iX, int _iY, char *_spName) {
  char *Destination; // [esp+0h] [ebp-8h]

  if((int) this->m_uNumberOfPlayers >= 8)
    return 0;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uRace = _iRace;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uX = _iX;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uY = _iY;
  strcpy(this->m_sPlayers[this->m_uNumberOfPlayers].m_sName, _spName);
  this->m_uNumberOfPlayers++;
  return 1;
}


// address=[0x2fbf1e0]
// Decompiled from int __thiscall CPlayerData::DeletePlayer(CPlayerData *this, T_CONSTANTS _Number)
int CPlayerData::DeletePlayer(int _Number) {
  // [esp+8h] [ebp-8h]

  BB_ASSERT(_Number>0 && _Number<=MAX_PLAYER)
  BB_ASSERT(_Number<this->m_uNumberOfPlayers) //CUSTOM ASSERT: Swap technique of the original does not work with the last player
  if(this->m_uNumberOfPlayers < 2)
    return 0;
  // Player numbers start from 1!!
  // e.g. delete player 2: replace player [2-1] with last player [num-1]
  // NOTE: this breaks when the player to delete is the last one!
  // This function is not used anywhere
  memcpy(&this->m_sPlayers[_Number - 1], &this->m_sPlayers[this->m_uNumberOfPlayers - 1], sizeof(this->m_sPlayers));


  this->m_uNumberOfPlayers--;
  return 1;
}


// address=[0x2fbf270]
// Decompiled from int __thiscall CPlayerData::AddSetup(CPlayerData *this)
int CPlayerData::AddSetup(void) {
  // [esp+0h] [ebp-8h]

  if(this->m_iNumberOfSetups >= 10)
    return 0;
  for(int i = 0; i < 8; ++i) {
    this->m_sSetups[this->m_iNumberOfSetups][i].m_iTeam = 1;
    this->m_sSetups[this->m_iNumberOfSetups][i].m_iPlayerControl = 0;
  }
  ++this->m_iNumberOfSetups;
  return 1;
}


// address=[0x2fbf300]
// Decompiled from int __thiscall CPlayerData::DeleteSetup(CPlayerData *this, int a2)
int CPlayerData::DeleteSetup(int _iSetupId) {
  // [esp+0h] [ebp-8h]

  if((int) this->m_iNumberOfSetups < 2)
    return 0;

  int iLast = m_iNumberOfSetups - 1;
  // Copy last setup into the deleted one
  for(int i = 0; i < 8; i++) {
    this->m_sSetups[_iSetupId][i] = this->m_sSetups[iLast][i];
  }
  --this->m_iNumberOfSetups;
  return 1;
}


// address=[0x2fbf390]
// Decompiled from int __thiscall CPlayerData::GetRaceOfPlayer(CPlayerData *this, int _Player)
int CPlayerData::GetRaceOfPlayer(int _Player) {
  BB_ASSERT(_Player>=1)
  return this->m_sPlayers[_Player - 1].m_uRace;//*(_DWORD *) &this->m_uSetupNames[8][45 * _Player + 21];// m_sPlayers.m_uRace
}


// address=[0x2fbf3d0]
// Decompiled from int __thiscall CPlayerData::GetXOfPlayer(CPlayerData *this, int a2)
int CPlayerData::GetXOfPlayer(int _Player) {
  BB_ASSERT(_Player>=1)

  return this->m_sPlayers[_Player - 1].m_uX;
}


// address=[0x2fbf410]
// Decompiled from int __thiscall CPlayerData::GetYOfPlayer(CPlayerData *this, int a2)
int CPlayerData::GetYOfPlayer(int _Player) {
  BB_ASSERT(_Player>=1)
  return this->m_sPlayers[_Player - 1].m_uY;
}


// address=[0x2fbf450]
// Decompiled from void __thiscall CPlayerData::ChangePlayer(CPlayerData *this, int _iSourcePlayer, int _iDestPlayer)
void CPlayerData::ChangePlayer(int _iSourcePlayer, int _iDestPlayer) {
  // eax
  // eax
  // eax
  // eax
  // al
  // eax
  // [esp+0h] [ebp-8h]

  BB_ASSERT(_iSourcePlayer!=0)
  BB_ASSERT(_iDestPlayer!=0)

  if(_iSourcePlayer != _iDestPlayer) {
    int XOfPlayer = CPlayerData::GetXOfPlayer(_iSourcePlayer);
    CPlayerData::SetXOfPlayer(_iDestPlayer, XOfPlayer);
    int YOfPlayer = CPlayerData::GetYOfPlayer(_iSourcePlayer);
    CPlayerData::SetYOfPlayer(_iDestPlayer, YOfPlayer);
    int RaceOfPlayer = CPlayerData::GetRaceOfPlayer(_iSourcePlayer);
    CPlayerData::SetRaceOfPlayer(_iDestPlayer, RaceOfPlayer);
    char *NameOfPlayer = CPlayerData::GetNameOfPlayer(_iSourcePlayer);
    CPlayerData::SetNameOfPlayer(_iDestPlayer, NameOfPlayer);
    for(int i = 0; i < 10; ++i) {
      int ControlOfPlayer = CPlayerData::GetControlOfPlayer(_iSourcePlayer, i);
      CPlayerData::SetControlOfPlayer(_iDestPlayer, i, ControlOfPlayer);
      int TeamOfPlayer = CPlayerData::GetTeamOfPlayer(_iSourcePlayer, i);
      CPlayerData::SetTeamOfPlayer(_iDestPlayer, i, TeamOfPlayer);
    }
  }
}


// address=[0x2fbf560]
// Decompiled from char *__thiscall CPlayerData::GetNameOfPlayer(CPlayerData *this, int a2)
char *CPlayerData::GetNameOfPlayer(int _Player) {
  BB_ASSERT(_Player>=1)
  return this->m_sPlayers[_Player - 1].m_sName;
}


// address=[0x2fbf5a0]
// Decompiled from char *__thiscall CPlayerData::GetSetupName(CPlayerData *this, int a2)
char *CPlayerData::GetSetupName(int a2) {
  return this->m_uSetupNames[a2];
}


// address=[0x2fbf5c0]
// Decompiled from int __thiscall CPlayerData::GetControlOfPlayer(CPlayerData *this, int a2, int a3)
int CPlayerData::GetControlOfPlayer(int _Player, int _Setup) {
  BB_ASSERT(_Player>=1)
  return m_sSetups[_Setup][_Player - 1].m_iPlayerControl;
}


// address=[0x2fbf610]
// Decompiled from int __thiscall CPlayerData::GetTeamOfPlayer(CPlayerData *this, int a2, int a3)
int CPlayerData::GetTeamOfPlayer(int _Player, int _Setup) {
  BB_ASSERT(_Player>=1)
  return m_sSetups[_Setup][_Player - 1].m_iTeam;
}


// address=[0x2fbf660]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetRaceOfPlayer(CPlayerData *this, int a2, int a3)
void CPlayerData::SetRaceOfPlayer(int _Player, int _iValue) {
  BB_ASSERT(_Player>=1)
  this->m_sPlayers[_Player - 1].m_uRace = _iValue;
}


// address=[0x2fbf6a0]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetXOfPlayer(CPlayerData *this, int a2, int a3)
void CPlayerData::SetXOfPlayer(int _Player, int _iValue) {
  BB_ASSERT(_Player>=1)
  this->m_sPlayers[_Player - 1].m_uX = _iValue;
}


// address=[0x2fbf6e0]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetYOfPlayer(CPlayerData *this, int a2, int a3)
void CPlayerData::SetYOfPlayer(int _Player, int _iValue) {
  BB_ASSERT(_Player>=1)
  this->m_sPlayers[_Player - 1].m_uY = _iValue;
}


// address=[0x2fbf720]
// Decompiled from char *__thiscall CPlayerData::SetNameOfPlayer(CPlayerData *this, int a2, char *Source)
void CPlayerData::SetNameOfPlayer(int _Player, char *_spName) {
  BB_ASSERT(_Player>=1)
  strcpy(this->m_sPlayers[_Player - 1].m_sName, _spName);
}


// address=[0x2fbf770]
// Decompiled from char *__thiscall CPlayerData::SetSetupName(CPlayerData *this, int a2, char *Source)
void CPlayerData::SetSetupName(int _iSetup, char *_spName) {
  strcpy(this->m_uSetupNames[_iSetup], _spName);
}


// address=[0x2fbf7a0]
// Decompiled from char *__thiscall CPlayerData::SetControlOfPlayer(CPlayerData *this, int a2, int a3, char a4)
void CPlayerData::SetControlOfPlayer(int _Player, int _iSetup, int _iControl) {
  BB_ASSERT(_Player>=1)
  this->m_sSetups[_iSetup][_Player - 1].m_iPlayerControl = _iControl;
}


// address=[0x2fbf7f0]
// Decompiled from char *__thiscall CPlayerData::SetTeamOfPlayer(CPlayerData *this, int a2, int a3, char a4)
void CPlayerData::SetTeamOfPlayer(int _Player, int _iSetup, int _iTeam) {
  BB_ASSERT(_Player>=1)
  this->m_sSetups[_iSetup][_Player - 1].m_iTeam = _iTeam;
}


// address=[0x2fbf840]
// Decompiled from int __thiscall CPlayerData::Save(CPlayerData *this, void *a2)
int CPlayerData::Save(unsigned char *a2) {
  // eax
  int iNumberOfPlayers = CPlayerData::GetNumberOfPlayers();
  static_assert(sizeof(CPlayerData::Player) == 45, "Size of m_sPlayers does not match expected size of 45 bytes per player for 8 players");
  int iSize = sizeof(CPlayerData::Player) * iNumberOfPlayers;
  memcpy(a2, this->m_sPlayers, iSize);
  return iSize;
}


// address=[0x2fbf890]
// Decompiled from int __thiscall CPlayerData::SaveTeamData(CPlayerData *this, char *a2, int a3)
int CPlayerData::SaveTeamData(unsigned char *a2, int _iSetup) {
  // eax
  static_assert(sizeof(this->m_uSetupNames[_iSetup]) == 33, "Size of m_uSetupNames does not match expected size of 33 bytes per setup name");
  memcpy(a2, this->m_uSetupNames[_iSetup], sizeof(this->m_uSetupNames[_iSetup]));
  int iNumberOfPlayers = CPlayerData::GetNumberOfPlayers();
  static_assert(sizeof(CPlayerData::Team) == 2, "Size of m_sSetups does not match expected size of 2 bytes per team for 8 players");
  memcpy(a2 + sizeof(this->m_uSetupNames[_iSetup]), this->m_sSetups[_iSetup], sizeof(CPlayerData::Team) * iNumberOfPlayers);
  return sizeof(this->m_uSetupNames[_iSetup]) * iNumberOfPlayers + sizeof(CPlayerData::Team);
}


// address=[0x2fbf900]
// Decompiled from BOOL __thiscall CPlayerData::Load(CPlayerData *this, unsigned __int8 *lpBuffer, void *hFile, struct SMapChunkHeader a4)
int CPlayerData::Load(unsigned char *lpBuffer, void *hFile, struct SMapChunkHeader a4) {
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-Ch] BYREF
  // [esp+4h] [ebp-8h]

  this->m_uNumberOfPlayers = a4.m_iNumberOfPlayers;
  BOOL v6 = ReadFile(hFile, lpBuffer, a4.m_iSize, &NumberOfBytesRead, 0);
  ReadChunk((char *) lpBuffer, a4.m_iSize, a4.m_iDecompressedSize);
  memcpy(this->m_sPlayers, lpBuffer, 45 * this->m_uNumberOfPlayers);
  return v6;
}


// address=[0x2fbf980]
// Decompiled from BOOL __thiscall CPlayerData::LoadTeamData(  CPlayerData *this,  unsigned __int8 *lpBuffer,  void *hFile,  struct SMapChunkHeader a4)
int CPlayerData::LoadTeamData(unsigned char *lpBuffer, void *hFile, struct SMapChunkHeader a4) {
  // eax
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-10h] BYREF
  // [esp+4h] [ebp-Ch]
  // [esp+Ch] [ebp-4h]

  int iSetup = a4.m_iSetup;
  if(a4.m_iSetup >= 10u)
    return 0;
  BOOL v7 = ReadFile(hFile, lpBuffer, a4.m_iSize, &NumberOfBytesRead, 0);
  ReadChunk((char *) lpBuffer, a4.m_iSize, a4.m_iDecompressedSize);
  memcpy(this->m_uSetupNames[iSetup], lpBuffer, sizeof(this->m_uSetupNames[iSetup]));
  if(iSetup + 1 > this->m_iNumberOfSetups)
    this->m_iNumberOfSetups = iSetup + 1;
  int NumberOfPlayers = CPlayerData::GetNumberOfPlayers();
  memcpy(&this->m_sSetups[8 * iSetup], lpBuffer + 33, 2 * NumberOfPlayers);
  return v7;
}


// address=[0x2fbfa50]
// Decompiled from int CPlayerData::GetSizeOfPlayerElement()
int CPlayerData::GetSizeOfPlayerElement(void) {
  return 0x2D;
}


// address=[0x2fbfa60]
// Decompiled from int __thiscall CPlayerData::GetSizeOfTeamElement(CPlayerData *this)
int CPlayerData::GetSizeOfTeamElement(void) {
  return 2;
}


// address=[0x2fbfa70]
// Decompiled from int __thiscall CPlayerData::CheckTeams(CPlayerData *this)
int CPlayerData::CheckTeams(void) {
  _DWORD uSetups[8]; // [esp+14h] [ebp-24h]

  for(int i = 0; i < this->m_iNumberOfSetups; ++i) {
    for(int j = 0; j < 8; ++j)
      uSetups[j] = 0;
    for(int k = 0; k < this->m_uNumberOfPlayers; ++k) {
      int m_iTeam = this->m_sSetups[i][k].m_iTeam;
      if(m_iTeam != 255) {
        if(m_iTeam >= this->m_uNumberOfPlayers)
          return 0;
        uSetups[m_iTeam] = 1;
      }
    }
    if(!uSetups[0])
      return 0;
    int v2 = 1;
    for(int m = 0; m < 8; ++m) {
      if(v2) {
        if(!uSetups[m])
          v2 = 0;
      } else if(uSetups[m]) {
        return 0;
      }
    }
  }
  return 1;
}
