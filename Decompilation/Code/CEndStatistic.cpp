#include "CEndStatistic.h"

// Definitions for class CEndStatistic

// address=[0x144f850]
// Decompiled from CEndStatistic *__thiscall CEndStatistic::CEndStatistic(CEndStatistic *this)

 CEndStatistic::CEndStatistic(void) {
  
  CStatistic::CStatistic(this);
  *(_DWORD *)this = CEndStatistic::_vftable_;
  std::wstring::wstring((char *)this + 39544);
  `eh vector constructor iterator'((char *)this + 39572, 0x1Cu, 9u, std::wstring::wstring, std::wstring::~wstring);
  CEndStatistic::Clear(this);
  return this;
}


// address=[0x144f8e0]
// Decompiled from CEndStatistic *__thiscall CEndStatistic::Clear(CEndStatistic *this)

void  CEndStatistic::Clear(void) {
  
  CEndStatistic *result; // eax
  int i; // [esp+0h] [ebp-8h]

  CStatistic::Clear(this);
  *((_DWORD *)this + 9957) = 0;
  *((_DWORD *)this + 9956) = 0;
  std::wstring::operator=((char *)this + 39544, (wchar_t *)&word_36AD034);
  *((_BYTE *)this + 39536) = 0;
  result = this;
  *((_DWORD *)this + 9885) = 0;
  for ( i = 1; i < 9; ++i )
  {
    *((_DWORD *)this + i + 9958) = 0;
    *((_DWORD *)this + i + 9967) = 0;
    result = (CEndStatistic *)i;
    *((_DWORD *)this + i + 9976) = 0;
  }
  return result;
}


// address=[0x144f990]
// Decompiled from int __thiscall CEndStatistic::Init(CEndStatistic *this)

void  CEndStatistic::Init(void) {
  
  int result; // eax

  result = CPlayerManager::NumberOfPlayers();
  *((_DWORD *)this + 9956) = result;
  return result;
}


// address=[0x144f9b0]
// Decompiled from int __userpurge CEndStatistic::Update@<eax>(
        int a1@<ecx>,
        char a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63)

void  CEndStatistic::Update(class CStatistic) {
  
  int result; // eax
  int v65; // [esp+0h] [ebp-2Ch]
  int i; // [esp+4h] [ebp-28h]
  _BYTE v68[28]; // [esp+Ch] [ebp-20h] BYREF

  CStatistic::Update((CStatistic *)a1, (struct CStatistic *)&a2);
  *(_DWORD *)(a1 + 39824) = CPlayerManager::NumberOfPlayers();
  *(_DWORD *)(a1 + 39828) = CGameData::GetTickCounter(g_pGameData);
  std::wstring::operator=(g_pGameType + 28);
  *(_BYTE *)(a1 + 39536) = CGameData::IsGameWon(g_pGameData);
  if ( *(_BYTE *)(a1 + 39536) )
    *(_DWORD *)(a1 + 39540) = CGameData::TeamWon(g_pGameData);
  for ( i = 1; ; ++i )
  {
    result = a1;
    if ( i > *(_DWORD *)(a1 + 39824) )
      break;
    v65 = CPlayerManager::Name(v68, i);
    std::wstring::operator=(v65);
    std::wstring::~wstring(v68);
    *(_DWORD *)(a1 + 4 * i + 39832) = CPlayerManager::Race(i);
    *(_DWORD *)(a1 + 4 * i + 39868) = CPlayerManager::Color(i);
    *(_DWORD *)(a1 + 4 * i + 39904) = CAlliances::AllianceId(i);
  }
  return result;
}


// address=[0x144fb00]
// Decompiled from _DWORD *__thiscall CEndStatistic::GetMapName(CEndStatistic *this)

wchar_t const *  CEndStatistic::GetMapName(void) {
  
  return std::wstring::c_str((CEndStatistic *)((char *)this + 39544));
}


// address=[0x144fb20]
// Decompiled from int __thiscall CEndStatistic::GetPlayerName(void *this, int a2, int a3)

std::wstring  CEndStatistic::GetPlayerName(int) {
  
  if ( (a3 <= 0 || a3 >= 9)
    && BBSupportDbgReport(2, "Logic\\EndStatistic.cpp", 112, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  std::wstring::wstring((int)this + 28 * a3 + 39572);
  return a2;
}


// address=[0x144fb90]
// Decompiled from int __thiscall CEndStatistic::GetNumberOfPlayers(CEndStatistic *this)

int  CEndStatistic::GetNumberOfPlayers(void) {
  
  return *((_DWORD *)this + 9956);
}


// address=[0x144fbb0]
// Decompiled from int __thiscall CEndStatistic::GetPlayerRace(CEndStatistic *this, int a2)

int  CEndStatistic::GetPlayerRace(int) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\EndStatistic.cpp", 121, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + a2 + 9958);
}


// address=[0x144fc00]
// Decompiled from int __thiscall CEndStatistic::GetPlayerColor(CEndStatistic *this, int a2)

int  CEndStatistic::GetPlayerColor(int) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\EndStatistic.cpp", 126, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + a2 + 9967);
}


// address=[0x144fc50]
// Decompiled from int __thiscall CEndStatistic::GetPlayerAlliance(CEndStatistic *this, int a2)

int  CEndStatistic::GetPlayerAlliance(int) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\EndStatistic.cpp", 131, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + a2 + 9976);
}


// address=[0x144fca0]
// Decompiled from char __thiscall CEndStatistic::IsGameWone(CEndStatistic *this)

bool  CEndStatistic::IsGameWone(void) {
  
  return *((_BYTE *)this + 39536);
}


// address=[0x144fcc0]
// Decompiled from int __thiscall CEndStatistic::GetWonAlliance(CEndStatistic *this)

int  CEndStatistic::GetWonAlliance(void) {
  
  return *((_DWORD *)this + 9885);
}


// address=[0x144fce0]
// Decompiled from int __thiscall CEndStatistic::GetTickCounter(CEndStatistic *this)

unsigned int  CEndStatistic::GetTickCounter(void) {
  
  return *((_DWORD *)this + 9957);
}


// address=[0x144fe20]
// Decompiled from void __thiscall CEndStatistic::~CEndStatistic(CEndStatistic *this)

 CEndStatistic::~CEndStatistic(void) {
  
  `eh vector destructor iterator'((char *)this + 39572, 0x1Cu, 9u, std::wstring::~wstring);
  std::wstring::~wstring((char *)this + 39544);
}


