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

  this->m_uNumberOfSetups = 1;
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
      this->m_sSetups[8 * j + i].field_1 = 1;
      this->m_sSetups[8 * j + i].field_0 = 0;
    }
  }
  for ( k = 0; k < 10; ++k )
    memset((char *)this + 33 * k, 0, 0x21u);
}


// address=[0x2fbf0f0]
// Decompiled from int __thiscall CPlayerData::GetNumberOfPlayers(CPlayerData *this)
int  CPlayerData::GetNumberOfPlayers(void) {
  
  return this->m_uNumberOfPlayers;
}


// address=[0x2fbf110]
// Decompiled from int __thiscall CPlayerData::GetNumberOfSetups(CPlayerData *this)
int  CPlayerData::GetNumberOfSetups(void) {
  
  return this->m_uNumberOfSetups;
}


// address=[0x2fbf130]
// Decompiled from int __thiscall CPlayerData::AddPlayer(CPlayerData *this, DWORD a2, DWORD a3, DWORD a4, char *Source)
int  CPlayerData::AddPlayer(int a2, int a3, int a4, char * Source) {
  
  char *Destination; // [esp+0h] [ebp-8h]

  if ( (int)this->m_uNumberOfPlayers >= 8 )
    return 0;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uRace = a2;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uX = a3;
  this->m_sPlayers[this->m_uNumberOfPlayers].m_uY = a4;
  Destination = this->m_sPlayers[this->m_uNumberOfPlayers++].m_sName;
  j__strcpy_0(Destination, Source);
  return 1;
}


// address=[0x2fbf1e0]
// Decompiled from int __thiscall CPlayerData::DeletePlayer(CPlayerData *this, int a2)
int  CPlayerData::DeletePlayer(int a2) {
  
  int v3; // [esp+8h] [ebp-8h]

  if ( a2 <= 0 || a2 > 8 )
    j___wassert(L"_Number>0 && _Number<=MAX_PLAYER", L"PlayerAndTeamData.cpp", 0xAEu);
  if ( (int)this->m_uNumberOfPlayers < 2 )
    return 0;
  v3 = this->m_uNumberOfPlayers - 1;
  this->m_uNumberOfPlayers = v3;
  qmemcpy(&this->m_uSetupNames[45 * a2 + 0x11D], &this->m_sPlayers[v3], 0x2Du);// Replace player to delete with latest player and decrement that by 1
  return 1;
}


// address=[0x2fbf270]
// Decompiled from int __thiscall CPlayerData::AddSetup(CPlayerData *this)
int  CPlayerData::AddSetup(void) {
  
  int i; // [esp+0h] [ebp-8h]

  if ( (int)this->m_uNumberOfSetups >= 10 )
    return 0;
  for ( i = 0; i < 8; ++i )
  {
    this->m_sSetups[16 * this->m_uNumberOfSetups + 1 + 2 * i] = 1;
    this->m_sSetups[16 * this->m_uNumberOfSetups + 2 * i] = 0;
  }
  ++this->m_uNumberOfSetups;
  return 1;
}


// address=[0x2fbf300]
// Decompiled from int __thiscall CPlayerData::DeleteSetup(CPlayerData *this, int a2)
int  CPlayerData::DeleteSetup(int a2) {
  
  int i; // [esp+0h] [ebp-8h]

  if ( (int)this->m_uNumberOfSetups < 2 )
    return 0;
  for ( i = 0; i < 8; ++i )
    this->m_sSetups[8 * a2 + i] = *(CPlayerData::Setup *)&this->m_sPlayers[7].m_sName[16 * this->m_uNumberOfSetups
                                                                                    + 17
                                                                                    + 2 * i];
  --this->m_uNumberOfSetups;
  return 1;
}


// address=[0x2fbf390]
// Decompiled from int __thiscall CPlayerData::GetRaceOfPlayer(CPlayerData *this, int a2)
int  CPlayerData::GetRaceOfPlayer(int a2) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0xDCu);
  return *(_DWORD *)&this->m_uSetupNames[45 * a2 + 285];// m_sPlayers.m_uRace
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
// Decompiled from void __thiscall CPlayerData::ChangePlayer(CPlayerData *this, int a2, int a3)
void  CPlayerData::ChangePlayer(int a2, int a3) {
  
  int XOfPlayer; // eax
  int YOfPlayer; // eax
  int RaceOfPlayer; // eax
  char *NameOfPlayer; // eax
  char ControlOfPlayer; // al
  int TeamOfPlayer; // eax
  int i; // [esp+0h] [ebp-8h]

  if ( !a2 )
    j___wassert(L"_iSourcePlayer!=0", L"PlayerAndTeamData.cpp", 0x4Bu);
  if ( !a3 )
    j___wassert(L"_iDestPlayer!=0", L"PlayerAndTeamData.cpp", 0x4Cu);
  if ( a2 != a3 )
  {
    XOfPlayer = CPlayerData::GetXOfPlayer(this, a2);
    CPlayerData::SetXOfPlayer(this, a3, XOfPlayer);
    YOfPlayer = CPlayerData::GetYOfPlayer(this, a2);
    CPlayerData::SetYOfPlayer(this, a3, YOfPlayer);
    RaceOfPlayer = CPlayerData::GetRaceOfPlayer(this, a2);
    CPlayerData::SetRaceOfPlayer(this, a3, RaceOfPlayer);
    NameOfPlayer = CPlayerData::GetNameOfPlayer(this, a2);
    CPlayerData::SetNameOfPlayer(a3, NameOfPlayer);
    for ( i = 0; i < 10; ++i )
    {
      ControlOfPlayer = CPlayerData::GetControlOfPlayer(this, a2, i);
      CPlayerData::SetControlOfPlayer(this, a3, i, ControlOfPlayer);
      TeamOfPlayer = CPlayerData::GetTeamOfPlayer(this, a2, i);
      CPlayerData::SetTeamOfPlayer(this, a3, i, TeamOfPlayer);
    }
  }
}


// address=[0x2fbf560]
// Decompiled from char *__thiscall CPlayerData::GetNameOfPlayer(CPlayerData *this, int a2)
char *  CPlayerData::GetNameOfPlayer(int a2) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x106u);
  return (char *)this + 45 * a2 + 297;
}


// address=[0x2fbf5a0]
// Decompiled from char *__thiscall CPlayerData::GetSetupName(CPlayerData *this, int a2)
char *  CPlayerData::GetSetupName(int a2) {
  
  return (char *)this + 33 * a2;
}


// address=[0x2fbf5c0]
// Decompiled from int __thiscall CPlayerData::GetControlOfPlayer(CPlayerData *this, int a2, int a3)
int  CPlayerData::GetControlOfPlayer(int a2, int a3) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x189u);
  return (unsigned __int8)this->m_sPlayers[7].m_sName[16 * a3 + 32 + 2 * a2];
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
// Decompiled from char *__thiscall CPlayerData::SetNameOfPlayer(char *this, int a2, char *Source)
void  CPlayerData::SetNameOfPlayer(int a2, char * Source) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x121u);
  return j__strcpy_0(&this[45 * a2 + 297], Source);
}


// address=[0x2fbf770]
// Decompiled from char *__thiscall CPlayerData::SetSetupName(char *this, int a2, char *Source)
void  CPlayerData::SetSetupName(int a2, char * Source) {
  
  return j__strcpy_0(&this[33 * a2], Source);
}


// address=[0x2fbf7a0]
// Decompiled from char *__thiscall CPlayerData::SetControlOfPlayer(CPlayerData *this, int a2, int a3, char a4)
void  CPlayerData::SetControlOfPlayer(int a2, int a3, int a4) {
  
  char *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x16Au);
  result = (char *)this + 16 * a3 + 690;
  result[2 * a2 - 1] = a4;
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
  memcpy(a2 + 33, &this->m_sSetups[8 * a3], 2 * NumberOfPlayers);
  return 2 * CPlayerData::GetNumberOfPlayers(this) + 33;
}


// address=[0x2fbf900]
// Decompiled from BOOL __thiscall CPlayerData::Load(  CPlayerData *this,  LPVOID lpBuffer,  HANDLE hFile,  int a4,  DWORD nNumberOfBytesToRead,  int a6,  int a7,  int a8,  int a9)
int  CPlayerData::Load(unsigned char * lpBuffer, void * hFile, struct SMapChunkHeader a4) {
  
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-Ch] BYREF
  BOOL v11; // [esp+4h] [ebp-8h]

  this->m_uNumberOfPlayers = a9;
  v11 = ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
  ReadChunk(lpBuffer, nNumberOfBytesToRead, a6);
  memcpy(this->m_sPlayers, lpBuffer, 45 * this->m_uNumberOfPlayers);
  return v11;
}


// address=[0x2fbf980]
// Decompiled from BOOL __thiscall CPlayerData::LoadTeamData(  CPlayerData *this,  char *lpBuffer,  HANDLE hFile,  int a4,  DWORD nNumberOfBytesToRead,  int a6,  int a7,  int a8,  int a9)
int  CPlayerData::LoadTeamData(unsigned char * lpBuffer, void * hFile, struct SMapChunkHeader a4) {
  
  int NumberOfPlayers; // eax
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-10h] BYREF
  BOOL v12; // [esp+4h] [ebp-Ch]
  CPlayerData *v13; // [esp+8h] [ebp-8h]
  int v14; // [esp+Ch] [ebp-4h]

  v13 = this;
  v14 = HIWORD(a4);
  if ( HIWORD(a4) >= 0xAu )
    return 0;
  v12 = ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
  ReadChunk(lpBuffer, nNumberOfBytesToRead, a6);
  memcpy(v13->m_uSetupNames[v14], lpBuffer, sizeof(v13->m_uSetupNames[v14]));
  if ( v14 + 1 > v13->m_uNumberOfSetups )
    v13->m_uNumberOfSetups = v14 + 1;
  NumberOfPlayers = CPlayerData::GetNumberOfPlayers(v13);
  memcpy(&v13->m_sSetups[8 * v14], lpBuffer + 33, 2 * NumberOfPlayers);
  return v12;
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
  int v3; // [esp+4h] [ebp-34h]
  int i; // [esp+Ch] [ebp-2Ch]
  int j; // [esp+10h] [ebp-28h]
  int k; // [esp+10h] [ebp-28h]
  int m; // [esp+10h] [ebp-28h]
  _DWORD uSetups[8]; // [esp+14h] [ebp-24h]

  for ( i = 0; i < this->m_uNumberOfSetups; ++i )
  {
    for ( j = 0; j < 8; ++j )
      uSetups[j] = 0;
    for ( k = 0; k < this->m_uNumberOfPlayers; ++k )
    {
      v3 = this->m_sSetups[8 * i + k].field_0;
      if ( v3 != 255 )
      {
        if ( v3 >= this->m_uNumberOfPlayers )
          return 0;
        uSetups[v3] = 1;
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
// Decompiled from CPlayerData *__thiscall CPlayerData::CPlayerData(CPlayerData *this, int a2, bool a3)
 CPlayerData::CPlayerData(int a2, bool a3) {
  
  this->? = a2;
  this->? = a3;
  this->m_uSetupNames = 0;
  this->? = 0;
  this->? = 0;
  this->? = 0;
  this->? = 0;
  this->? = 0;
  return this;
}


// address=[0x2fc5390]
// Decompiled from int __thiscall CPlayerData::setStartPos_Basic(CPlayerData *this, int a2, int a3)
void  CPlayerData::setStartPos_Basic(int a2, int a3) {
  
  int result; // eax

  *(_DWORD *)this = a2;
  result = a3;
  *((_DWORD *)this + 1) = a3;
  return result;
}


// address=[0x2fc53b0]
// Decompiled from int *__thiscall CPlayerData::getStartPos_Basic(CPlayerData *this, int *a2, int *a3)
void  CPlayerData::getStartPos_Basic(int & a2, int & a3) {
  
  int *result; // eax

  *a2 = *(_DWORD *)this;
  result = a3;
  *a3 = *((_DWORD *)this + 1);
  return result;
}


// address=[0x2fc53e0]
// Decompiled from int __thiscall CPlayerData::setStartPos_Real(CPlayerData *this, int a2, int a3)
void  CPlayerData::setStartPos_Real(int a2, int a3) {
  
  int result; // eax

  *((_DWORD *)this + 2) = a2;
  result = a3;
  *((_DWORD *)this + 3) = a3;
  return result;
}


// address=[0x2fc5400]
// Decompiled from int *__thiscall CPlayerData::getStartPos_Real(CPlayerData *this, int *a2, int *a3)
void  CPlayerData::getStartPos_Real(int & a2, int & a3) {
  
  int *result; // eax

  *a2 = *((_DWORD *)this + 2);
  result = a3;
  *a3 = *((_DWORD *)this + 3);
  return result;
}


// address=[0x2fc5430]
// Decompiled from int *__thiscall CPlayerData::getNearestMountain(CPlayerData *this, int *a2, int *a3)
void  CPlayerData::getNearestMountain(int & a2, int & a3) {
  
  int *result; // eax

  *a2 = this->?;
  result = a3;
  *a3 = this->?;
  return result;
}


// address=[0x2fc5460]
// Decompiled from int __thiscall CPlayerData::setNearestMountain(CPlayerData *this, int a2, int a3)
void  CPlayerData::setNearestMountain(int a2, int a3) {
  
  int result; // eax

  *((_DWORD *)this + 4) = a2;
  result = a3;
  *((_DWORD *)this + 5) = a3;
  return result;
}


// address=[0x2fc5480]
// Decompiled from int __thiscall CPlayerData::getRace(CPlayerData *this)
int  CPlayerData::getRace(void) {
  
  return *(_DWORD *)&this->m_uSetupNames[0][24];
}


// address=[0x2fc54a0]
// Decompiled from bool __thiscall CPlayerData::isAI(ATL::CImage *this)
bool  CPlayerData::isAI(void) {
  
  return *((_BYTE *)this + 28);
}


