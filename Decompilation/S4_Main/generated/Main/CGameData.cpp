#include "CGameData.h"

// Definitions for class CGameData

// address=[0x1360fd0]
// Decompiled from CGameData *__thiscall CGameData::CGameData(CGameData *this)
 CGameData::CGameData(void) {
  
  this->m_uTickCounter = 0;
  this->m_uVirtualTick = 0;
  this->m_iHeight = 0;
  this->m_iWidth = 0;
  this->dword10 = 0;
  this->m_uCamX = 0;
  this->m_uCamY = 0;
  this->m_uZoom = 0x180000;
  this->dword20 = -1;
  this->dword24 = -1;
  this->byte28 = 0;
  this->m_bFixedStartCamera = 0;
  CRandom16Ex::CRandom16Ex(&this->m_sRandom, 0);
  this->m_bIsGameWon = 0;
  this->m_iTeamWon = 0;
  std::string::string(&this->m_swGameType);
  std::string::string(&this->m_swMapMode);
  this->byte7E = 0;
  CRandom16Ex::Init(&this->m_sRandom, 290671, 0);
  if ( !g_pGameType && BBSupportDbgReport(2, "GameData.cpp", 57, "g_pGameType != NULL") == 1 )
    __debugbreak();
  if ( ((int)g_pGameType->m_iGameType <= 0 || (int)g_pGameType->m_iGameType >= 5)
    && BBSupportDbgReport(
         2,
         "GameData.cpp",
         58,
         "(g_pGameType->m_iGameType > GAMETYPE_NONE) && (g_pGameType->m_iGameType < GAMETYPE_MAX)") == 1 )
  {
    __debugbreak();
  }
  this->m_iType = g_pGameType->m_iGameType;
  std::string::operator=(&this->m_swGameType, g_pszGameType[this->m_iType]);
  if ( !this->m_iType && BBSupportDbgReport(2, "GameData.cpp", 63, "m_iType") == 1 )
    __debugbreak();
  this->m_iMode = g_pGameType->m_iMode;
  std::string::operator=(&this->m_swMapMode, g_pszMapMode[this->m_iMode]);
  if ( !this->m_iMode && BBSupportDbgReport(2, "GameData.cpp", 67, "m_iMode") == 1 )
    __debugbreak();
  *(_WORD *)&this->m_bIsNetworkGame = g_pGameType->m_bAIActive == 0;
  this->m_bIsGameWon = g_pGameType->m_bIsGameWon;
  this->m_iTeamWon = g_pGameType->m_iTeamWon;
  memcpy(this->m_pEconomyGoodsArray, g_pGameType->m_pEconomyGoodsArray, sizeof(this->m_pEconomyGoodsArray));
  this->m_bIsLadderGame = CGameType::IsLadderGame(g_pGameType);
  return this;
}


// address=[0x1361270]
// Decompiled from bool __thiscall CGameData::IsTutorial(CGameData *this)
bool  CGameData::IsTutorial(void) {
  
  return this->m_iType == 4;
}


// address=[0x13612a0]
// Decompiled from bool __thiscall CGameData::IsCampaign(CGameData *this)
bool  CGameData::IsCampaign(void) {
  
  return this->m_iType == 3;
}


// address=[0x13612d0]
// Decompiled from char __thiscall CGameData::IsLadder(CGameData *this)
bool  CGameData::IsLadder(void) {
  
  return this->m_bIsLadderGame;
}


// address=[0x1395840]
// Decompiled from int __thiscall CGameData::GetMode(CGameData *this)
int  CGameData::GetMode(void) {
  
  return this->m_iMode;
}


// address=[0x139fe80]
// Decompiled from char __thiscall CGameData::IsNetworkGame(CGameData *this)
bool  CGameData::IsNetworkGame(void) {
  
  return this->m_bIsNetworkGame;
}


// address=[0x144fe90]
// Decompiled from int __thiscall CGameData::GetTickCounter(CGameData *this)
unsigned int  CGameData::GetTickCounter(void)const {
  
  return this->m_uTickCounter;
}


// address=[0x144feb0]
// Decompiled from char __thiscall CGameData::IsGameWon(CGameData *this)
bool  CGameData::IsGameWon(void) {
  
  return this->m_bIsGameWon;
}


// address=[0x144ff50]
// Decompiled from unsigned int __thiscall CGameData::TeamWon(CGameData *this)
int  CGameData::TeamWon(void) {
  
  return this->m_iTeamWon;
}


// address=[0x14606b0]
// Decompiled from char __thiscall CGameData::IsLastFrameRendered(CGameData *this)
bool  CGameData::IsLastFrameRendered(void) {
  
  return this->m_bIsLastFrameRendered;
}


// address=[0x146ae80]
// Decompiled from unsigned int __thiscall CGameData::Rand(CGameData *this)
unsigned int  CGameData::Rand(void) {
  
  return CRandom16::Rand(&this->m_sRandom);
}


// address=[0x147a2f0]
// Decompiled from char *__thiscall CGameData::GetEconomyGoodsArray(CGameData *this)
unsigned char *  CGameData::GetEconomyGoodsArray(void) {
  
  return &this->m_pEconomyGoodsArray;
}


// address=[0x14aa9a0]
// Decompiled from void __thiscall CGameData::~CGameData(CGameData *this)
 CGameData::~CGameData(void) {
  
  std::string::~string((char *)this + 96);
  std::string::~string((char *)this + 64);
}


// address=[0x14aac40]
// Decompiled from std::string *__thiscall CGameData::GetModeString(CGameData *this, std::string *a2)
std::string  CGameData::GetModeString(void a2) {
  
  std::string::string(a2, (int)&this->m_swMapMode);
  return a2;
}


// address=[0x14aad60]
// Decompiled from std::string *__thiscall CGameData::GetTypeString(CGameData *this, std::string *a2)
std::string  CGameData::GetTypeString(void a2) {
  
  std::string::string(a2, (int)&this->m_swGameType);
  return a2;
}


// address=[0x14aaf30]
// Decompiled from void __thiscall CGameData::SetLastFrameRendered(CGameData *this, bool a2)
void  CGameData::SetLastFrameRendered(bool a2) {
  
  this->m_bIsLastFrameRendered = a2;
}


// address=[0x14b4a60]
// Decompiled from void __thiscall CGameData::TeamWon(CGameData *this, int a2)
void  CGameData::TeamWon(int a2) {
  
  this->m_iTeamWon = a2;
  this->m_bIsGameWon = 1;
}


