#include "CPlayerData.h"

// Definitions for class CPlayerData

// address=[0x2fbefb0]
// Decompiled from CPlayerData *__thiscall CPlayerData::CPlayerData(CPlayerData *this)

 CPlayerData::CPlayerData(void) {
  
  CPlayerData::Init(this);
  return this;
}


// address=[0x2fbefd0]
// Decompiled from CPlayerData *__thiscall CPlayerData::Init(CPlayerData *this)

void  CPlayerData::Init(void) {
  
  CPlayerData *result; // eax
  int k; // [esp+0h] [ebp-14h]
  int j; // [esp+4h] [ebp-10h]
  int i; // [esp+Ch] [ebp-8h]
  char Source; // [esp+13h] [ebp-1h] BYREF

  result = this;
  *((_DWORD *)this + 214) = 1;
  *((_DWORD *)this + 213) = 1;
  Source = 0;
  for ( i = 0; i < 8; ++i )
  {
    *(_DWORD *)((char *)this + 45 * i + 334) = 128;
    *(_DWORD *)((char *)this + 45 * i + 338) = 128;
    j__strncpy((char *)this + 45 * i + 342, &Source, 0x21u);
    result = this;
    *(_DWORD *)((char *)this + 45 * i + 330) = 0;
    for ( j = 0; j < 10; ++j )
    {
      *((_BYTE *)this + 16 * j + 2 * i + 691) = 1;
      result = (CPlayerData *)i;
      *((_BYTE *)this + 16 * j + 2 * i + 690) = 0;
    }
  }
  for ( k = 0; k < 10; ++k )
    result = (CPlayerData *)j__memset((char *)this + 33 * k, 0, 0x21u);
  return result;
}


// address=[0x2fbf0f0]
// Decompiled from int __thiscall CPlayerData::GetNumberOfPlayers(CPlayerData *this)

int  CPlayerData::GetNumberOfPlayers(void) {
  
  return *((_DWORD *)this + 213);
}


// address=[0x2fbf110]
// Decompiled from int __thiscall CPlayerData::GetNumberOfSetups(CPlayerData *this)

int  CPlayerData::GetNumberOfSetups(void) {
  
  return *((_DWORD *)this + 214);
}


// address=[0x2fbf130]
// Decompiled from // public: int __thiscall CPlayerData::AddPlayer(int,int,int,char *)
int __thiscall CPlayerData::AddPlayer(int *this, int a2, int a3, int a4, char *Source)

int  CPlayerData::AddPlayer(int,int,int,char *) {
  
  char *Destination; // [esp+0h] [ebp-8h]

  if ( this[213] >= 8 )
    return 0;
  *(int *)((char *)this + 45 * this[213] + 330) = a2;
  *(int *)((char *)this + 45 * this[213] + 334) = a3;
  *(int *)((char *)this + 45 * this[213] + 338) = a4;
  Destination = (char *)this + 45 * this[213]++ + 342;
  j__strcpy_0(Destination, Source);
  return 1;
}


// address=[0x2fbf1e0]
// Decompiled from // public: int __thiscall CPlayerData::DeletePlayer(int)
int __thiscall CPlayerData::DeletePlayer(int *this, int a2)

int  CPlayerData::DeletePlayer(int) {
  
  int v3; // [esp+8h] [ebp-8h]

  if ( a2 <= 0 || a2 > 8 )
    j___wassert(L"_Number>0 && _Number<=MAX_PLAYER", L"PlayerAndTeamData.cpp", 0xAEu);
  if ( this[213] < 2 )
    return 0;
  v3 = this[213] - 1;
  this[213] = v3;
  qmemcpy((char *)this + 45 * a2 + 285, (char *)this + 45 * v3 + 330, 0x2Du);
  return 1;
}


// address=[0x2fbf270]
// Decompiled from // public: int __thiscall CPlayerData::AddSetup(void)
int __thiscall CPlayerData::AddSetup(int *this)

int  CPlayerData::AddSetup(void) {
  
  int i; // [esp+0h] [ebp-8h]

  if ( this[214] >= 10 )
    return 0;
  for ( i = 0; i < 8; ++i )
  {
    *((_BYTE *)&this[4 * this[214] + 172] + 2 * i + 3) = 1;
    *((_BYTE *)&this[4 * this[214] + 172] + 2 * i + 2) = 0;
  }
  ++this[214];
  return 1;
}


// address=[0x2fbf300]
// Decompiled from // public: int __thiscall CPlayerData::DeleteSetup(int)
int __thiscall CPlayerData::DeleteSetup(int *this, int a2)

int  CPlayerData::DeleteSetup(int) {
  
  int i; // [esp+0h] [ebp-8h]

  if ( this[214] < 2 )
    return 0;
  for ( i = 0; i < 8; ++i )
    *((_WORD *)&this[4 * a2 + 172] + i + 1) = *((_WORD *)&this[4 * this[214] + 168] + i + 1);
  --this[214];
  return 1;
}


// address=[0x2fbf390]
// Decompiled from int __thiscall CPlayerData::GetRaceOfPlayer(CPlayerData *this, int a2)

int  CPlayerData::GetRaceOfPlayer(int) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0xDCu);
  return *(_DWORD *)((char *)this + 45 * a2 + 285);
}


// address=[0x2fbf3d0]
// Decompiled from int __thiscall CPlayerData::GetXOfPlayer(CPlayerData *this, int a2)

int  CPlayerData::GetXOfPlayer(int) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0xEAu);
  return *(_DWORD *)((char *)this + 45 * a2 + 289);
}


// address=[0x2fbf410]
// Decompiled from int __thiscall CPlayerData::GetYOfPlayer(CPlayerData *this, int a2)

int  CPlayerData::GetYOfPlayer(int) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0xF8u);
  return *(_DWORD *)((char *)this + 45 * a2 + 293);
}


// address=[0x2fbf450]
// Decompiled from // public: void __thiscall CPlayerData::ChangePlayer(int,int)
void __thiscall CPlayerData::ChangePlayer(CPlayerData *this, int a2, int a3)

void  CPlayerData::ChangePlayer(int,int) {
  
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

char *  CPlayerData::GetNameOfPlayer(int) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x106u);
  return (char *)this + 45 * a2 + 297;
}


// address=[0x2fbf5a0]
// Decompiled from char *__thiscall CPlayerData::GetSetupName(CPlayerData *this, int a2)

char *  CPlayerData::GetSetupName(int) {
  
  return (char *)this + 33 * a2;
}


// address=[0x2fbf5c0]
// Decompiled from int __thiscall CPlayerData::GetControlOfPlayer(CPlayerData *this, int a2, int a3)

int  CPlayerData::GetControlOfPlayer(int,int) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x189u);
  return *((unsigned __int8 *)this + 16 * a3 + 2 * a2 + 689);
}


// address=[0x2fbf610]
// Decompiled from int __thiscall CPlayerData::GetTeamOfPlayer(CPlayerData *this, int a2, int a3)

int  CPlayerData::GetTeamOfPlayer(int,int) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x198u);
  return *((unsigned __int8 *)this + 16 * a3 + 2 * a2 + 688);
}


// address=[0x2fbf660]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetRaceOfPlayer(CPlayerData *this, int a2, int a3)

void  CPlayerData::SetRaceOfPlayer(int,int) {
  
  CPlayerData *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x15Au);
  result = this;
  *(_DWORD *)((char *)this + 45 * a2 + 285) = a3;
  return result;
}


// address=[0x2fbf6a0]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetXOfPlayer(CPlayerData *this, int a2, int a3)

void  CPlayerData::SetXOfPlayer(int,int) {
  
  CPlayerData *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x13Cu);
  result = this;
  *(_DWORD *)((char *)this + 45 * a2 + 289) = a3;
  return result;
}


// address=[0x2fbf6e0]
// Decompiled from CPlayerData *__thiscall CPlayerData::SetYOfPlayer(CPlayerData *this, int a2, int a3)

void  CPlayerData::SetYOfPlayer(int,int) {
  
  CPlayerData *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x14Bu);
  result = this;
  *(_DWORD *)((char *)this + 45 * a2 + 293) = a3;
  return result;
}


// address=[0x2fbf720]
// Decompiled from char *__thiscall CPlayerData::SetNameOfPlayer(char *this, int a2, char *Source)

void  CPlayerData::SetNameOfPlayer(int,char *) {
  
  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x121u);
  return j__strcpy_0(&this[45 * a2 + 297], Source);
}


// address=[0x2fbf770]
// Decompiled from // public: void __thiscall CPlayerData::SetSetupName(int,char *)
char *__thiscall CPlayerData::SetSetupName(char *this, int a2, char *Source)

void  CPlayerData::SetSetupName(int,char *) {
  
  return j__strcpy_0(&this[33 * a2], Source);
}


// address=[0x2fbf7a0]
// Decompiled from char *__thiscall CPlayerData::SetControlOfPlayer(CPlayerData *this, int a2, int a3, char a4)

void  CPlayerData::SetControlOfPlayer(int,int,int) {
  
  char *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x16Au);
  result = (char *)this + 16 * a3 + 690;
  result[2 * a2 - 1] = a4;
  return result;
}


// address=[0x2fbf7f0]
// Decompiled from char *__thiscall CPlayerData::SetTeamOfPlayer(CPlayerData *this, int a2, int a3, char a4)

void  CPlayerData::SetTeamOfPlayer(int,int,int) {
  
  char *result; // eax

  if ( a2 < 1 )
    j___wassert(L"_Player>=1", L"PlayerAndTeamData.cpp", 0x17Au);
  result = (char *)this + 16 * a3 + 690;
  result[2 * a2 - 2] = a4;
  return result;
}


// address=[0x2fbf840]
// Decompiled from // public: int __thiscall CPlayerData::Save(unsigned char *)
int __thiscall CPlayerData::Save(int this, void *a2)

int  CPlayerData::Save(unsigned char *) {
  
  int NumberOfPlayers; // eax

  NumberOfPlayers = CPlayerData::GetNumberOfPlayers(this);
  j__memcpy(a2, (const void *)(this + 330), 45 * NumberOfPlayers);
  return 45 * CPlayerData::GetNumberOfPlayers(this);
}


// address=[0x2fbf890]
// Decompiled from // public: int __thiscall CPlayerData::SaveTeamData(unsigned char *,int)
int __thiscall CPlayerData::SaveTeamData(char *this, char *a2, int a3)

int  CPlayerData::SaveTeamData(unsigned char *,int) {
  
  int NumberOfPlayers; // eax

  j__memcpy(a2, &this[33 * a3], 0x21u);
  NumberOfPlayers = CPlayerData::GetNumberOfPlayers(this);
  j__memcpy(a2 + 33, &this[16 * a3 + 690], 2 * NumberOfPlayers);
  return 2 * CPlayerData::GetNumberOfPlayers(this) + 33;
}


// address=[0x2fbf900]
// Decompiled from BOOL __thiscall CPlayerData::Load(
        _DWORD *this,
        LPVOID lpBuffer,
        HANDLE hFile,
        int a4,
        DWORD nNumberOfBytesToRead,
        int a6,
        int a7,
        int a8,
        int a9)

int  CPlayerData::Load(unsigned char *,void *,struct SMapChunkHeader) {
  
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-Ch] BYREF
  BOOL v11; // [esp+4h] [ebp-8h]
  _DWORD *v12; // [esp+8h] [ebp-4h]

  v12 = this;
  this[213] = a9;
  v11 = ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
  ReadChunk(lpBuffer, nNumberOfBytesToRead, a6);
  j__memcpy((char *)v12 + 330, lpBuffer, 45 * v12[213]);
  return v11;
}


// address=[0x2fbf980]
// Decompiled from BOOL __thiscall CPlayerData::LoadTeamData(
        _DWORD *this,
        char *lpBuffer,
        HANDLE hFile,
        int a4,
        DWORD nNumberOfBytesToRead,
        int a6,
        int a7,
        int a8,
        int a9)

int  CPlayerData::LoadTeamData(unsigned char *,void *,struct SMapChunkHeader) {
  
  int NumberOfPlayers; // eax
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-10h] BYREF
  BOOL v12; // [esp+4h] [ebp-Ch]
  _DWORD *v13; // [esp+8h] [ebp-8h]
  int v14; // [esp+Ch] [ebp-4h]

  v13 = this;
  v14 = HIWORD(a4);
  if ( HIWORD(a4) >= 0xAu )
    return 0;
  v12 = ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
  ReadChunk(lpBuffer, nNumberOfBytesToRead, a6);
  j__memcpy((char *)v13 + 33 * v14, lpBuffer, 0x21u);
  if ( v14 + 1 > v13[214] )
    v13[214] = v14 + 1;
  NumberOfPlayers = CPlayerData::GetNumberOfPlayers(v13);
  j__memcpy((char *)&v13[4 * v14 + 172] + 2, lpBuffer + 33, 2 * NumberOfPlayers);
  return v12;
}


// address=[0x2fbfa50]
// Decompiled from // public: int __thiscall CPlayerData::GetSizeOfPlayerElement(void)
int CPlayerData::GetSizeOfPlayerElement()

int  CPlayerData::GetSizeOfPlayerElement(void) {
  
  return 45;
}


// address=[0x2fbfa60]
// Decompiled from // MFC 3.1-14.0 32bit
int __thiscall CPlayerData::GetSizeOfTeamElement(CPlayerData *this)

int  CPlayerData::GetSizeOfTeamElement(void) {
  
  return 2;
}


// address=[0x2fbfa70]
// Decompiled from // public: int __thiscall CPlayerData::CheckTeams(void)
int __thiscall CPlayerData::CheckTeams(_DWORD *this)

int  CPlayerData::CheckTeams(void) {
  
  int v2; // [esp+0h] [ebp-38h]
  int v3; // [esp+4h] [ebp-34h]
  int i; // [esp+Ch] [ebp-2Ch]
  int j; // [esp+10h] [ebp-28h]
  int k; // [esp+10h] [ebp-28h]
  int m; // [esp+10h] [ebp-28h]
  _DWORD v8[8]; // [esp+14h] [ebp-24h]

  for ( i = 0; i < this[214]; ++i )
  {
    for ( j = 0; j < 8; ++j )
      v8[j] = 0;
    for ( k = 0; k < this[213]; ++k )
    {
      v3 = *((unsigned __int8 *)&this[4 * i + 172] + 2 * k + 2);
      if ( v3 != 255 )
      {
        if ( v3 >= this[213] )
          return 0;
        v8[v3] = 1;
      }
    }
    if ( !v8[0] )
      return 0;
    v2 = 1;
    for ( m = 0; m < 8; ++m )
    {
      if ( v2 )
      {
        if ( !v8[m] )
          v2 = 0;
      }
      else if ( v8[m] )
      {
        return 0;
      }
    }
  }
  return 1;
}


// address=[0x2fc5330]
// Decompiled from CPlayerData *__thiscall CPlayerData::CPlayerData(CPlayerData *this, int a2, bool a3)

 CPlayerData::CPlayerData(int,bool) {
  
  *((_DWORD *)this + 6) = a2;
  *((_BYTE *)this + 28) = a3;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return this;
}


// address=[0x2fc5390]
// Decompiled from int __thiscall CPlayerData::setStartPos_Basic(CPlayerData *this, int a2, int a3)

void  CPlayerData::setStartPos_Basic(int,int) {
  
  int result; // eax

  *(_DWORD *)this = a2;
  result = a3;
  *((_DWORD *)this + 1) = a3;
  return result;
}


// address=[0x2fc53b0]
// Decompiled from int *__thiscall CPlayerData::getStartPos_Basic(CPlayerData *this, int *a2, int *a3)

void  CPlayerData::getStartPos_Basic(int &,int &) {
  
  int *result; // eax

  *a2 = *(_DWORD *)this;
  result = a3;
  *a3 = *((_DWORD *)this + 1);
  return result;
}


// address=[0x2fc53e0]
// Decompiled from int __thiscall CPlayerData::setStartPos_Real(CPlayerData *this, int a2, int a3)

void  CPlayerData::setStartPos_Real(int,int) {
  
  int result; // eax

  *((_DWORD *)this + 2) = a2;
  result = a3;
  *((_DWORD *)this + 3) = a3;
  return result;
}


// address=[0x2fc5400]
// Decompiled from int *__thiscall CPlayerData::getStartPos_Real(CPlayerData *this, int *a2, int *a3)

void  CPlayerData::getStartPos_Real(int &,int &) {
  
  int *result; // eax

  *a2 = *((_DWORD *)this + 2);
  result = a3;
  *a3 = *((_DWORD *)this + 3);
  return result;
}


// address=[0x2fc5430]
// Decompiled from int *__thiscall CPlayerData::getNearestMountain(CPlayerData *this, int *a2, int *a3)

void  CPlayerData::getNearestMountain(int &,int &) {
  
  int *result; // eax

  *a2 = *((_DWORD *)this + 4);
  result = a3;
  *a3 = *((_DWORD *)this + 5);
  return result;
}


// address=[0x2fc5460]
// Decompiled from int __thiscall CPlayerData::setNearestMountain(CPlayerData *this, int a2, int a3)

void  CPlayerData::setNearestMountain(int,int) {
  
  int result; // eax

  *((_DWORD *)this + 4) = a2;
  result = a3;
  *((_DWORD *)this + 5) = a3;
  return result;
}


// address=[0x2fc5480]
// Decompiled from // MFC 3.1-14.0 32bit
int __thiscall CPlayerData::getRace(CPlayerData *this)

int  CPlayerData::getRace(void) {
  
  return *((_DWORD *)this + 6);
}


// address=[0x2fc54a0]
// Decompiled from bool __thiscall CPlayerData::isAI(ATL::CImage *this)

bool  CPlayerData::isAI(void) {
  
  return *((_BYTE *)this + 28);
}


