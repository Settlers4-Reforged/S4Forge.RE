#if FALSE
#include "CPlayerData.h"

// Definitions for class CPlayerData

// address=[0x2fbefb0]
// Decompiled from CPlayerData *__thiscall CPlayerData::CPlayerData(CPlayerData *this)
 CPlayerData::CPlayerData(void) {
  
  CPlayerData::Init(this);
  return this;
}


// address=[0x2fbefd0]
// Decompiled from void __thiscall CPlayerData::Init(CPlayerData *this)
void  CPlayerData::Init(void) {
  
  int k; // [esp+0h] [ebp-14h]
  int j; // [esp+4h] [ebp-10h]
  int i; // [esp+Ch] [ebp-8h]
  char Source; // [esp+13h] [ebp-1h] BYREF

  this->m_iNumberOfSetups = 1;
  this->m_uNumberOfPlayers = 1;
  Source = 0;
  for ( i = 0; i < 8; ++i )
  {
    this->m_sPlayers[i].m_uX = 128;
    this->m_sPlayers[i].m_uY = 128;
    j__strncpy(this->m_sPlayers[i].m_sName, &Source, 0x21u);
    this->m_sPlayers[i].m_uRace = 0;
    for ( j = 0; j < 10; ++j )
    {
      this->m_sSetups[j][i].m_iPlayerControl = 1;
      this->m_sSetups[j][i].m_iTeam = 0;
    }
  }
  for ( k = 0; k < 10; ++k )
    memset(this->m_uSetupNames[k], 0, sizeof(this->m_uSetupNames[k]));
}


// address=[0x2fbf0f0]
// Decompiled from int __thiscall CPlayerData::GetNumberOfPlayers(CPlayerData *this)
int  CPlayerData::GetNumberOfPlayers(void) {
  
  return this->m_uNumberOfPlayers;
}


// address=[0x2fbf110]
// Decompiled from int __thiscall CPlayerData::GetNumberOfSetups(CPlayerData *this)
int  CPlayerData::GetNumberOfSetups(void) {
  
  return this->m_iNumberOfSetups;
}


// address=[0x2fbf130]
// Decompiled from int __thiscall CPlayerData::AddPlayer(CPlayerData *this, DWORD _iRace, DWORD _iX, DWORD _iY, char *_spName)
int  CPlayerData::AddPlayer(int _iRace, int _iX, int _iY, char * _spName) {
  
  char *Destination; // [esp+0h] [ebp-8h]

  if ( (int)this->m_uNumberOfPlayers >= 8 )
    return 0;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uRace = _iRace;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uX = _iX;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uY = _iY;
  Destination = this->m_sPlayers[this->m_uNumberOfPlayers++].m_sName;
  j__strcpy_0(Destination, _spName);
  return 1;
}


// address=[0x2fbf1e0]
// Decompiled from int __thiscall CPlayerData::DeletePlayer(CPlayerData *this, int _Number)
int  CPlayerData::DeletePlayer(int _Number) {
  
  int iNewPlayers; // [esp+8h] [ebp-8h]

  if ( _Number <= 0 || _Number > MAX_PLAYER )
    j___wassert(L"_Number>0 && _Number<=MAX_PLAYER", L"PlayerAndTeamData.cpp", 0xAEu);
  if ( (int)this->m_uNumberOfPlayers < 2 )
    return 0;
  iNewPlayers = this->m_uNumberOfPlayers - 1;
  this->m_uNumberOfPlayers = iNewPlayers;
  qmemcpy(&this->m_uSetupNames[8][0x2D * _Number + 0x15], &this->m_sPlayers[iNewPlayers], 0x2Du);// Replace player to delete with latest player and decrement that by 1
  return 1;
}


// address=[0x2fbf270]
// Decompiled from int __thiscall CPlayerData::AddSetup(CPlayerData *this)
int  CPlayerData::AddSetup(void) {
  
  int i; // [esp+0h] [ebp-8h]

  if ( this->m_iNumberOfSetups >= 10 )
    return 0;
  for ( i = 0; i < 8; ++i )
  {
    this->m_sSetups[this->m_iNumberOfSetups][i].m_iPlayerControl = 1;
    this->m_sSetups[this->m_iNumberOfSetups][i].m_iTeam = 0;
  }
  ++this->m_iNumberOfSetups;
  return 1;
}


// address=[0x2fbf300]
// Decompiled from int __thiscall CPlayerData::DeleteSetup(CPlayerData *this, int setupId)
int  CPlayerData::DeleteSetup(int setupId) {
  
  int i; // [esp+0h] [ebp-8h]

  if ( this->m_iNumberOfSetups < 2 )
    return 0;
  for ( i = 0; i < 8; ++i )
    this->m_sSetups[setupId][i] = *(CPlayerData::Team *)&this->m_sPlayers[7].m_sName[16 * this->m_iNumberOfSetups
                                                                                   + 17
                                                                                   + 2 * i];
  --this->m_iNumberOfSetups;
  return 1;
}


// address=[0x2fbf390]
// Decompiled from int __thiscall CPlayerData::GetRaceOfPlayer(CPlayerData *this, int _Player)
int  CPlayerData::GetRaceOfPlayer(int _Player) {
  
  if ( _Player < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0xDCu);
  return *(_DWORD *)&this->m_uSetupNames[8][45 * _Player + 21];// m_sPlayers.m_uRace
}


// address=[0x2fbf3d0]
// Decompiled from int __thiscall CPlayerData::GetXOfPlayer(CPlayerData *this, int a2)
int  CPlayerData::GetXOfPlayer(int a2) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0xEAu);
  return *(_DWORD *)&this->m_uSetupNames[45 * a2 + 289];
}


// address=[0x2fbf410]
// Decompiled from int __thiscall CPlayerData::GetYOfPlayer(CPlayerData *this, int a2)
int  CPlayerData::GetYOfPlayer(int a2) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0xF8u);
  return *(_DWORD *)&this->m_uSetupNames[45 * a2 + 293];
}


// address=[0x2fbf450]
// Decompiled from void __thiscall CPlayerData::ChangePlayer(CPlayerData *this, int _iSourcePlayer, int _iDestPlayer)
void  CPlayerData::ChangePlayer(int _iSourcePlayer, int _iDestPlayer) {
  
  int XOfPlayer; // eax
  int YOfPlayer; // eax
  int RaceOfPlayer; // eax
  char *NameOfPlayer; // eax
  char ControlOfPlayer; // al
  int TeamOfPlayer; // eax
  int i; // [esp+0h] [ebp-8h]

  if ( !_iSourcePlayer )
    j___wassert(L"_iSourcePlayer!=0", L"PlayerAndTeamData.cpp", 0x4Bu);
  if ( !_iDestPlayer )
    j___wassert(L"_iDestPlayer!=0", L"PlayerAndTeamData.cpp", 0x4Cu);
  if ( _iSourcePlayer != _iDestPlayer )
  {
    XOfPlayer = CPlayerData::GetXOfPlayer(this, _iSourcePlayer);
    CPlayerData::SetXOfPlayer(this, _iDestPlayer, XOfPlayer);
    YOfPlayer = CPlayerData::GetYOfPlayer(this, _iSourcePlayer);
    CPlayerData::SetYOfPlayer(this, _iDestPlayer, YOfPlayer);
    RaceOfPlayer = CPlayerData::GetRaceOfPlayer(this, _iSourcePlayer);
    CPlayerData::SetRaceOfPlayer(this, _iDestPlayer, RaceOfPlayer);
    NameOfPlayer = CPlayerData::GetNameOfPlayer(this, _iSourcePlayer);
    CPlayerData::SetNameOfPlayer(_iDestPlayer, NameOfPlayer);
    for ( i = 0; i < 10; ++i )
    {
      ControlOfPlayer = CPlayerData::GetControlOfPlayer(this, _iSourcePlayer, i);
      CPlayerData::SetControlOfPlayer(this, _iDestPlayer, i, ControlOfPlayer);
      TeamOfPlayer = CPlayerData::GetTeamOfPlayer(this, _iSourcePlayer, i);
      CPlayerData::SetTeamOfPlayer(this, _iDestPlayer, i, TeamOfPlayer);
    }
  }
}


// address=[0x2fbf560]
// Decompiled from char *__thiscall CPlayerData::GetNameOfPlayer(CPlayerData *this, int a2)
char *  CPlayerData::GetNameOfPlayer(int a2) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x106u);
  return &this->m_uSetupNames[9][45 * a2];
}


// address=[0x2fbf5a0]
// Decompiled from char *__thiscall CPlayerData::GetSetupName(CPlayerData *this, int a2)
char *  CPlayerData::GetSetupName(int a2) {
  
  return (char *)this + 33 * a2;
}


// address=[0x2fbf5c0]
// Decompiled from int __thiscall CPlayerData::GetControlOfPlayer(CPlayerData *this, int player, int setupId)
int  CPlayerData::GetControlOfPlayer(int player, int setupId) {
  
  if ( player < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x189u);
  return (unsigned __int8)this->m_sPlayers[7].m_sName[16 * setupId + 32 + 2 * player];
}


// address=[0x2fbf610]
// Decompiled from int __thiscall CPlayerData::GetTeamOfPlayer(CPlayerData *this, int a2, int a3)
int  CPlayerData::GetTeamOfPlayer(int a2, int a3) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x198u);
  return (unsigned __int8)this->m_sPlayers[7].m_sName[16 * a3 + 31 + 2 * a2];// CPlayerData.m_sSetups.field_0
}


// address=[0x2fbf660]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetRaceOfPlayer(CPlayerData *this, int a2, int a3)
void  CPlayerData::SetRaceOfPlayer(int a2, int a3) {
  
  CPlayerData *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x15Au);
  result = this;
  *(_DWORD *)&this->m_uSetupNames[8][45 * a2 + 21] = a3;// CPlayerData.m_sPlayers.m_uRace
  return result;
}


// address=[0x2fbf6a0]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetXOfPlayer(CPlayerData *this, int a2, int a3)
void  CPlayerData::SetXOfPlayer(int a2, int a3) {
  
  CPlayerData *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x13Cu);
  result = this;
  *(_DWORD *)((char *)&this[9].m_uSetupNames + 45 * a2 + 1) = a3;
  return result;
}


// address=[0x2fbf6e0]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetYOfPlayer(CPlayerData *this, int a2, int a3)
void  CPlayerData::SetYOfPlayer(int a2, int a3) {
  
  CPlayerData *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x14Bu);
  result = this;
  *(_DWORD *)((char *)this + 45 * a2 + 293) = a3;
  return result;
}


// address=[0x2fbf720]
// Decompiled from char *__thiscall CPlayerData::SetNameOfPlayer(CPlayerData *this, int a2, char *Source)
void  CPlayerData::SetNameOfPlayer(int a2, char * Source) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x121u);
  return j__strcpy_0(&this->m_uSetupNames[9][45 * a2], Source);
}


// address=[0x2fbf770]
// Decompiled from char *__thiscall CPlayerData::SetSetupName(CPlayerData *this, int a2, char *Source)
void  CPlayerData::SetSetupName(int a2, char * Source) {
  
  return j__strcpy_0(this->m_uSetupNames[a2], Source);
}


// address=[0x2fbf7a0]
// Decompiled from CPlayerData::Team *__thiscall CPlayerData::SetControlOfPlayer(CPlayerData *this, int a2, int a3, BYTE a4)
void  CPlayerData::SetControlOfPlayer(int a2, int a3, int a4) {
  
  CPlayerData::Team *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x16Au);
  result = this->m_sSetups[a3];
  result[a2 - 1].m_iPlayerControl = a4;
  return result;
}


// address=[0x2fbf7f0]
// Decompiled from char *__thiscall CPlayerData::SetTeamOfPlayer(CPlayerData *this, int a2, int a3, char a4)
void  CPlayerData::SetTeamOfPlayer(int a2, int a3, int a4) {
  
  char *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x17Au);
  result = (char *)this + 16 * a3 + 690;
  result[2 * a2 - 2] = a4;
  return result;
}


// address=[0x2fbf840]
// Decompiled from int __thiscall CPlayerData::Save(CPlayerData *this, void *a2)
int  CPlayerData::Save(unsigned char * a2) {
  
  int NumberOfPlayers; // eax

  NumberOfPlayers = CPlayerData::GetNumberOfPlayers(this);
  memcpy(a2, this->m_sPlayers, 45 * NumberOfPlayers);
  return 45 * CPlayerData::GetNumberOfPlayers(this);
}


// address=[0x2fbf890]
// Decompiled from int __thiscall CPlayerData::SaveTeamData(CPlayerData *this, char *a2, int a3)
int  CPlayerData::SaveTeamData(unsigned char * a2, int a3) {
  
  int NumberOfPlayers; // eax

  memcpy(a2, this->m_uSetupNames[a3], 33u);
  NumberOfPlayers = CPlayerData::GetNumberOfPlayers(this);
  memcpy(a2 + 33, this->m_sSetups[a3], 2 * NumberOfPlayers);
  return 2 * CPlayerData::GetNumberOfPlayers(this) + 33;
}


// address=[0x2fbf900]
// Decompiled from BOOL __thiscall CPlayerData::Load(CPlayerData *this, unsigned __int8 *lpBuffer, void *hFile, struct SMapChunkHeader a4)
int  CPlayerData::Load(unsigned char * a2, void * a3, struct SMapChunkHeader a4) {
  
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-Ch] BYREF
  BOOL v6; // [esp+4h] [ebp-8h]

  this->m_uNumberOfPlayers = a4.m_iNumberOfPlayers;
  v6 = ReadFile(hFile, lpBuffer, a4.m_iSize, &NumberOfBytesRead, 0);
  ReadChunk((char *)lpBuffer, a4.m_iSize, a4.m_iDecompressedSize);
  memcpy(this->m_sPlayers, lpBuffer, 45 * this->m_uNumberOfPlayers);
  return v6;
}


// address=[0x2fbf980]
// Decompiled from BOOL __thiscall CPlayerData::LoadTeamData(  CPlayerData *this,  unsigned __int8 *lpBuffer,  void *hFile,  struct SMapChunkHeader a4)
int  CPlayerData::LoadTeamData(unsigned char * a2, void * a3, struct SMapChunkHeader a4) {
  
  int NumberOfPlayers; // eax
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-10h] BYREF
  BOOL v7; // [esp+4h] [ebp-Ch]
  int iSetup; // [esp+Ch] [ebp-4h]

  iSetup = a4.m_iSetup;
  if ( a4.m_iSetup >= 10u )
    return 0;
  v7 = ReadFile(hFile, lpBuffer, a4.m_iSize, &NumberOfBytesRead, 0);
  ReadChunk((char *)lpBuffer, a4.m_iSize, a4.m_iDecompressedSize);
  memcpy(this->m_uSetupNames[iSetup], lpBuffer, sizeof(this->m_uSetupNames[iSetup]));
  if ( iSetup + 1 > this->m_iNumberOfSetups )
    this->m_iNumberOfSetups = iSetup + 1;
  NumberOfPlayers = CPlayerData::GetNumberOfPlayers(this);
  memcpy(&this->m_sSetups[8 * iSetup], lpBuffer + 33, 2 * NumberOfPlayers);
  return v7;
}


// address=[0x2fbfa50]
// Decompiled from int CPlayerData::GetSizeOfPlayerElement()
int  CPlayerData::GetSizeOfPlayerElement(void) {
  
  return 45;
}


// address=[0x2fbfa60]
// Decompiled from int __thiscall CPlayerData::GetSizeOfTeamElement(CPlayerData *this)
int  CPlayerData::GetSizeOfTeamElement(void) {
  
  return 2;
}


// address=[0x2fbfa70]
// Decompiled from int __thiscall CPlayerData::CheckTeams(CPlayerData *this)
int  CPlayerData::CheckTeams(void) {
  
  int v2; // [esp+0h] [ebp-38h]
  int m_iTeam; // [esp+4h] [ebp-34h]
  int i; // [esp+Ch] [ebp-2Ch]
  int j; // [esp+10h] [ebp-28h]
  int k; // [esp+10h] [ebp-28h]
  int m; // [esp+10h] [ebp-28h]
  _DWORD uSetups[8]; // [esp+14h] [ebp-24h]

  for ( i = 0; i < this->m_iNumberOfSetups; ++i )
  {
    for ( j = 0; j < 8; ++j )
      uSetups[j] = 0;
    for ( k = 0; k < this->m_uNumberOfPlayers; ++k )
    {
      m_iTeam = this->m_sSetups[i][k].m_iTeam;
      if ( m_iTeam != 255 )
      {
        if ( m_iTeam >= this->m_uNumberOfPlayers )
          return 0;
        uSetups[m_iTeam] = 1;
      }
    }
    if ( !uSetups[0] )
      return 0;
    v2 = 1;
    for ( m = 0; m < 8; ++m )
    {
      if ( v2 )
      {
        if ( !uSetups[m] )
          v2 = 0;
      }
      else if ( uSetups[m] )
      {
        return 0;
      }
    }
  }
  return 1;
}


// address=[0x2fc5330]
// Decompiled from MG::CPlayerData *__thiscall CPlayerData::CPlayerData(MG::CPlayerData *this, int a2, bool a3)
 CPlayerData::CPlayerData(int a2, bool a3) {
  
  this->m_iRace = a2;
  this->m_bIsAI = a3;
  this->m_iBasicX = 0;
  this->m_iBasicY = 0;
  this->m_iRealX = 0;
  this->m_iRealY = 0;
  this->m_iNearestMountainX = 0;
  this->m_iNearestMountainY = 0;
  return this;
}


// address=[0x2fc5390]
// Decompiled from void __thiscall CPlayerData::setStartPos_Basic(MG::CPlayerData *this, int a2, int a3)
void  CPlayerData::setStartPos_Basic(int a2, int a3) {
  
  this->m_iBasicX = a2;
  this->m_iBasicY = a3;
}


// address=[0x2fc53b0]
// Decompiled from void __thiscall CPlayerData::getStartPos_Basic(MG::CPlayerData *this, int *a2, int *a3)
void  CPlayerData::getStartPos_Basic(int & a2, int & a3) {
  
  *a2 = this->m_iBasicX;
  *a3 = this->m_iBasicY;
}


// address=[0x2fc53e0]
// Decompiled from void __thiscall CPlayerData::setStartPos_Real(MG::CPlayerData *this, int a2, int a3)
void  CPlayerData::setStartPos_Real(int a2, int a3) {
  
  this->m_iRealX = a2;
  this->m_iRealY = a3;
}


// address=[0x2fc5400]
// Decompiled from void __thiscall CPlayerData::getStartPos_Real(MG::CPlayerData *this, int *a2, int *a3)
void  CPlayerData::getStartPos_Real(int & a2, int & a3) {
  
  *a2 = this->m_iRealX;
  *a3 = this->m_iRealY;
}


// address=[0x2fc5430]
// Decompiled from void __thiscall CPlayerData::getNearestMountain(MG::CPlayerData *this, int *a2, int *a3)
void  CPlayerData::getNearestMountain(int & a2, int & a3) {
  
  *a2 = this->m_iNearestMountainX;
  *a3 = this->m_iNearestMountainY;
}


// address=[0x2fc5460]
// Decompiled from void __thiscall CPlayerData::setNearestMountain(MG::CPlayerData *this, int a2, int a3)
void  CPlayerData::setNearestMountain(int a2, int a3) {
  
  this->m_iNearestMountainX = a2;
  this->m_iNearestMountainY = a3;
}


// address=[0x2fc5480]
// Decompiled from int __thiscall CPlayerData::getRace(MG::CPlayerData *this)
int  CPlayerData::getRace(void) {
  
  return this->m_iRace;
}


// address=[0x2fc54a0]
// Decompiled from bool __thiscall CPlayerData::isAI(MG::CPlayerData *this)
bool  CPlayerData::isAI(void) {
  
  return this->m_bIsAI;
}


#endif // Already implemented
