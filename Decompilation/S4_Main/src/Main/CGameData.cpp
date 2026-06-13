#include "CGameData.h"

#include "CBB/CBBSupport.h"
#include "Defines/Game.h"

#include <array>

// Definitions for class CGameData

// address=[0x3D89B4C]
constexpr std::array<std::string_view, GAMETYPE_MAX> s_pszGameType = {
    "NONE",
    "Singleplayer",
    "Multiplayer",
    "Campaign",
    "Tutorial",
};
static_assert(std::size(s_pszGameType) == GAMETYPE_MAX, "Size of s_pszGameType is not correct");
static_assert(s_pszGameType[GAMETYPE_NONE] == "NONE", "s_pszGameType[GAMETYPE_NONE] is not correct");
static_assert(s_pszGameType[GAMETYPE_TUTORIAL] == "Tutorial", "s_pszGameType[GAMETYPE_TUTORIAL] is not correct");

// address=[0x3D89B30]
constexpr std::array<std::string_view, MODE_MAX> s_pszMapMode = {
    "None",
    "Conflict Mode",
    "Cooperation Mode",
    "--not found---",
    "--not found---",
    "--not found---",
    "--not found---",
};
static_assert(std::size(s_pszMapMode) == MODE_MAX, "Size of s_pszMapMode is not correct");
static_assert(s_pszMapMode[MODE_NONE] == "None", "s_pszMapMode[MODE_NONE] is not correct");
static_assert(s_pszMapMode[MODE_CONFLICT] == "Conflict Mode", "s_pszMapMode[MODE_CONFLICT] is not correct");
static_assert(s_pszMapMode[MODE_COOP] == "Cooperation Mode", "s_pszMapMode[MODE_COOP] is not correct");

// address=[0x03ECDBE8]
CGameData *g_pGameData;

// address=[0x1360fd0]
// Decompiled from CGameData *__thiscall CGameData::CGameData(CGameData *this)
CGameData::CGameData(void) : m_sRandom(0), m_swGameType(), m_swMapMode() {
    this->m_uTickCounter = 0;
    this->m_uVirtualTick = 0;
    this->m_iHeight = 0;
    this->m_iWidth = 0;
    this->m_uUnknown = 0;
    this->m_uCamX = 0;
    this->m_uCamY = 0;
    this->m_uZoom = 0x180000;
    this->m_iScreenMouseX = -1;
    this->m_iScreenMouseY = -1;
    this->m_bUnknown = 0;
    this->m_bFixedStartCamera = 0;
    this->m_bIsGameWon = 0;
    this->m_iTeamWon = 0;
    this->m_bUnknown2 = 0;
    this->m_sRandom.Init(290671, 0);
    BB_ASSERT(g_pGameType != NULL)
    BB_ASSERT((g_pGameType->m_iGameType > GAMETYPE_NONE) && (g_pGameType->m_iGameType < GAMETYPE_MAX))
    this->m_iType = g_pGameType->m_iGameType;
    this->m_swGameType = s_pszGameType[this->m_iType];
    BB_ASSERT(m_iType)
    this->m_iMode = g_pGameType->m_iMode;
    this->m_swMapMode = s_pszMapMode[this->m_iMode];
    BB_ASSERT(m_iMode)
    this->m_bIsNetworkGame = g_pGameType->m_bAIActive == 0;
    this->m_bIsLastFrameRendered = false;
    this->m_bIsGameWon = g_pGameType->m_bIsGameWon;
    this->m_iTeamWon = g_pGameType->m_iTeamWon;
    memcpy(this->m_pEconomyGoodsArray, g_pGameType->m_pEconomyGoodsArray, sizeof(this->m_pEconomyGoodsArray));
    this->m_bIsLadderGame = g_pGameType->IsLadderGame();
}

// address=[0x1361270]
// Decompiled from bool __thiscall CGameData::IsTutorial(CGameData *this)
bool CGameData::IsTutorial(void) {
    return this->m_iType == GAMETYPE_TUTORIAL;
}

// address=[0x13612a0]
// Decompiled from bool __thiscall CGameData::IsCampaign(CGameData *this)
bool CGameData::IsCampaign(void) {
    return this->m_iType == GAMETYPE_CAMPAIGN;
}

// address=[0x13612d0]
// Decompiled from char __thiscall CGameData::IsLadder(CGameData *this)
bool CGameData::IsLadder(void) {
    return this->m_bIsLadderGame;
}

// address=[0x1395840]
// Decompiled from int __thiscall CGameData::GetMode(CGameData *this)
int CGameData::GetMode(void) {
    return this->m_iMode;
}

// address=[0x139fe80]
// Decompiled from char __thiscall CGameData::IsNetworkGame(CGameData *this)
bool CGameData::IsNetworkGame(void) {
    return this->m_bIsNetworkGame;
}

// address=[0x144fe90]
// Decompiled from int __thiscall CGameData::GetTickCounter(CGameData *this)
unsigned int CGameData::GetTickCounter(void) const {
    return this->m_uTickCounter;
}

// address=[0x144feb0]
// Decompiled from char __thiscall CGameData::IsGameWon(CGameData *this)
bool CGameData::IsGameWon(void) {
    return this->m_bIsGameWon;
}

// address=[0x144ff50]
// Decompiled from int __thiscall CGameData::TeamWon(CGameData *this)
int CGameData::TeamWon(void) {

    return this->m_iTeamWon;
}

// address=[0x14606b0]
// Decompiled from char __thiscall CGameData::IsLastFrameRendered(CGameData *this)
bool CGameData::IsLastFrameRendered(void) {

    return this->m_bIsLastFrameRendered;
}

// address=[0x146ae80]
// Decompiled from unsigned int __thiscall CGameData::Rand(CGameData *this)
unsigned int CGameData::Rand(void) {
    return this->m_sRandom.Rand();
}

// address=[0x147a2f0]
// Decompiled from char *__thiscall CGameData::GetEconomyGoodsArray(CGameData *this)
unsigned char *CGameData::GetEconomyGoodsArray(void) {
    return this->m_pEconomyGoodsArray;
}

// address=[0x14aa9a0]
// Decompiled from void __thiscall CGameData::~CGameData(CGameData *this)
CGameData::~CGameData(void) = default;

// address=[0x14aac40]
// Decompiled from std::string *__thiscall CGameData::GetModeString(CGameData *this, std::string *a2)
std::string CGameData::GetModeString(void) {
    return this->m_swMapMode; // TODO: reference?
}

// address=[0x14aad60]
// Decompiled from std::string *__thiscall CGameData::GetTypeString(CGameData *this, std::string *a2)
std::string CGameData::GetTypeString(void) {
    return this->m_swGameType; // TODO: reference?
}

// address=[0x14aaf30]
// Decompiled from void __thiscall CGameData::SetLastFrameRendered(CGameData *this, bool a2)
void CGameData::SetLastFrameRendered(bool a2) {
    this->m_bIsLastFrameRendered = a2;
}

// address=[0x14b4a60]
// Decompiled from void __thiscall CGameData::TeamWon(CGameData *this, int a2)
void CGameData::TeamWon(int a2) {
    this->m_iTeamWon = a2;
    this->m_bIsGameWon = 1;
}
