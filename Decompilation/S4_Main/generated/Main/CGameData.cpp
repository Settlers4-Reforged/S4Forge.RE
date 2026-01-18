#include "CGameData.h"

// Definitions for class CGameData

// address=[0x1360fd0]
// Decompiled from CGameData *__thiscall CGameData::CGameData(CGameData *this)
 CGameData::CGameData(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 1572864;
  *((_DWORD *)this + 8) = -1;
  *((_DWORD *)this + 9) = -1;
  *((_BYTE *)this + 40) = 0;
  *((_BYTE *)this + 41) = 0;
  CRandom16Ex::CRandom16Ex((CGameData *)((char *)this + 44), 0);
  *((_BYTE *)this + 52) = 0;
  *((_DWORD *)this + 14) = 0;
  std::string::string();
  std::string::string();
  *((_BYTE *)this + 126) = 0;
  CRandom16Ex::Init((CGameData *)((char *)this + 44), 0x46F6Fu, 0);
  if ( !g_pGameType && BBSupportDbgReport(2, "GameData.cpp", 57, "g_pGameType != NULL") == 1 )
    __debugbreak();
  if ( (*(int *)(g_pGameType + 692) <= 0 || *(int *)(g_pGameType + 692) >= 5)
    && BBSupportDbgReport(
         2,
         "GameData.cpp",
         58,
         "(g_pGameType->m_iGameType > GAMETYPE_NONE) && (g_pGameType->m_iGameType < GAMETYPE_MAX)") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 15) = *(_DWORD *)(g_pGameType + 692);
  std::string::operator=((char *)this + 64, (&g_pszGameType)[*((_DWORD *)this + 15)]);
  if ( !*((_DWORD *)this + 15) && BBSupportDbgReport(2, "GameData.cpp", 63, "m_iType") == 1 )
    __debugbreak();
  *((_DWORD *)this + 23) = *(_DWORD *)(g_pGameType + 864);
  std::string::operator=((char *)this + 96, (&g_pszMapMode)[*((_DWORD *)this + 23)]);
  if ( !*((_DWORD *)this + 23) && BBSupportDbgReport(2, "GameData.cpp", 67, "m_iMode") == 1 )
    __debugbreak();
  *((_WORD *)this + 62) = *(_BYTE *)(g_pGameType + 732) == 0;
  *((_BYTE *)this + 52) = *(_BYTE *)(g_pGameType + 748);
  *((_DWORD *)this + 14) = *(_DWORD *)(g_pGameType + 752);
  j__memcpy((char *)this + 128, (const void *)(g_pGameType + 784), 7u);
  *((_BYTE *)this + 127) = CGameType::IsLadderGame(g_pGameType);
  return this;
}


// address=[0x1361270]
// Decompiled from bool __thiscall CGameData::IsTutorial(CGameData *this)
bool  CGameData::IsTutorial(void) {
  
  return *((_DWORD *)this + 15) == 4;
}


// address=[0x13612a0]
// Decompiled from bool __thiscall CGameData::IsCampaign(CGameData *this)
bool  CGameData::IsCampaign(void) {
  
  return *((_DWORD *)this + 15) == 3;
}


// address=[0x13612d0]
// Decompiled from char __thiscall CGameData::IsLadder(CGameData *this)
bool  CGameData::IsLadder(void) {
  
  return *((_BYTE *)this + 127);
}


// address=[0x1395840]
// Decompiled from int __thiscall CGameData::GetMode(CGameData *this)
int  CGameData::GetMode(void) {
  
  return *((_DWORD *)this + 23);
}


// address=[0x139fe80]
// Decompiled from char __thiscall CGameData::IsNetworkGame(CGameData *this)
bool  CGameData::IsNetworkGame(void) {
  
  return *((_BYTE *)this + 124);
}


// address=[0x144fe90]
// Decompiled from int __thiscall CGameData::GetTickCounter(CGameData *this)
unsigned int  CGameData::GetTickCounter(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x144feb0]
// Decompiled from char __thiscall CGameData::IsGameWon(CGameData *this)
bool  CGameData::IsGameWon(void) {
  
  return *((_BYTE *)this + 52);
}


// address=[0x144ff50]
// Decompiled from unsigned int __thiscall CGameData::TeamWon(CUserToolsManager *this)
int  CGameData::TeamWon(void) {
  
  return *((_DWORD *)this + 14);
}


// address=[0x14606b0]
// Decompiled from char __thiscall CGameData::IsLastFrameRendered(CGameData *this)
bool  CGameData::IsLastFrameRendered(void) {
  
  return *((_BYTE *)this + 125);
}


// address=[0x146ae80]
// Decompiled from const char *__thiscall CGameData::Rand(std::_Locinfo *this)
unsigned int  CGameData::Rand(void) {
  
  return (const char *)CRandom16::Rand((std::_Locinfo *)((char *)this + 44));
}


// address=[0x147a2f0]
// Decompiled from char *__thiscall CGameData::GetEconomyGoodsArray(CGameData *this)
unsigned char *  CGameData::GetEconomyGoodsArray(void) {
  
  return (char *)this + 128;
}


// address=[0x14aa9a0]
// Decompiled from void __thiscall CGameData::~CGameData(CGameData *this)
 CGameData::~CGameData(void) {
  
  std::string::~string((char *)this + 96);
  std::string::~string((char *)this + 64);
}


// address=[0x14aac40]
// Decompiled from int __thiscall CGameData::GetModeString(char *this, int a2)
std::string  CGameData::GetModeString(void a2) {
  
  std::string::string(this + 96);
  return a2;
}


// address=[0x14aad60]
// Decompiled from int __thiscall CGameData::GetTypeString(char *this, int a2)
std::string  CGameData::GetTypeString(void a2) {
  
  std::string::string(this + 64);
  return a2;
}


// address=[0x14aaf30]
// Decompiled from CGameData *__thiscall CGameData::SetLastFrameRendered(CGameData *this, bool a2)
void  CGameData::SetLastFrameRendered(bool a2) {
  
  CGameData *result; // eax

  result = this;
  *((_BYTE *)this + 125) = a2;
  return result;
}


// address=[0x14b4a60]
// Decompiled from CGameData *__thiscall CGameData::TeamWon(CGameData *this, int a2)
void  CGameData::TeamWon(int a2) {
  
  CGameData *result; // eax

  result = this;
  *((_DWORD *)this + 14) = a2;
  *((_BYTE *)this + 52) = 1;
  return result;
}


