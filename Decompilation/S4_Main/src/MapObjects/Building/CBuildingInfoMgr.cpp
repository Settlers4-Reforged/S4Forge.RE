#include "CBuildingInfoMgr.h"

#include <algorithm>

#include "CBuildingBits.h"
#include "CBuildingFlagsWalk.h"
#include "CConfigManager/CConfigManagerPtr.h"
#include "CConfigManager/IConfigManager.h"
#include "CBB/CBBSupport.h"
#include "Main/CDefineTranslator.h"
#include "Main/CS4DefineNames.h"
#include "MapObjects/CSpiralOffsets.h"
#include "World/helper.h"
#include "XMLParser/AdvXMLParser.h"

// Definitions for class CBuildingInfoMgr

// address=[0x133ac00]
// Decompiled from CBuildingInfoMgr::SBuildingInfos *__cdecl CBuildingInfoMgr::GetBuildingInfo(int a1, int a2)
struct CBuildingInfoMgr::SBuildingInfos const & __cdecl CBuildingInfoMgr::GetBuildingInfo(int a1, int a2) {
  BB_ASSERT(m_bInit == true)
  return CBuildingInfoMgr::m_vBuildingInfos[a1][a2];
}


// address=[0x1486f70]
// Decompiled from int __thiscall CBuildingInfoMgr::GetXMLVersion(CBuildingInfoMgr *this)
int CBuildingInfoMgr::GetXMLVersion(void) const {
  return this->m_iXmlVersion;
}


// address=[0x14eb8f0]
// Decompiled from CBuildingInfoMgr *__thiscall CBuildingInfoMgr::CBuildingInfoMgr(CBuildingInfoMgr *this)
CBuildingInfoMgr::CBuildingInfoMgr(void) {
  CBuildingInfoMgr::ClearInfo();
}


// address=[0x14eb910]
// Decompiled from void __thiscall CBuildingInfoMgr::~CBuildingInfoMgr(CBuildingInfoMgr *this)
CBuildingInfoMgr::~CBuildingInfoMgr(void) {
  CBuildingInfoMgr::m_bInit = false;
}


// address=[0x14eb930]
// Decompiled from void __thiscall CBuildingInfoMgr::LoadInfo(CBuildingInfoMgr *this, bool a2)
void CBuildingInfoMgr::LoadInfo(bool a2) {
  if(a2)
    CBuildingInfoMgr::ClearInfo();
  if(!CBuildingInfoMgr::m_bInit) {
    CBuildingInfoMgr::ReadBuildingInfo();
    CBuildingInfoMgr::m_bInit = true;
  }
}


// address=[0x14eb970]
// Decompiled from char __thiscall CBuildingInfoMgr::DbgCheckBuildingBits(CBuildingInfoMgr *this, int _iRace, int _iBuildingType)
bool CBuildingInfoMgr::DbgCheckBuildingBits(int _iRace, int _iBuildingType) {
  int                               iX; // eax
  BYTE *                            v4; // esi
  int                               v5; // eax
  int                               v6; // eax
  int                               v7; // eax
  int                               v8; // eax
  int                               v9; // eax
  int                               v10; // eax
  const char *                      BuildingName; // eax
  const char *                      v12; // eax
  const char *                      v13; // eax
  unsigned int                      iY; // [esp-8h] [ebp-4C00h]
  const char *                      RaceName; // [esp-4h] [ebp-4BFCh]
  const char *                      v17; // [esp-4h] [ebp-4BFCh]
  const char *                      v18; // [esp-4h] [ebp-4BFCh]
  int                               v25; // [esp+94h] [ebp-4B64h]
  int                               v26; // [esp+98h] [ebp-4B60h]
  int                               v27; // [esp+9Ch] [ebp-4B5Ch]
  int                               v28; // [esp+A0h] [ebp-4B58h]
  int                               v29; // [esp+A4h] [ebp-4B54h]
  int                               iPileNumber; // [esp+A8h] [ebp-4B50h]
  int                               v31; // [esp+ACh] [ebp-4B4Ch]
  int                               m_iWorkPosYOffset; // [esp+B4h] [ebp-4B44h]
  BOOL                              v34; // [esp+B8h] [ebp-4B40h]
  int                               v35; // [esp+BCh] [ebp-4B3Ch]
  int                               v36; // [esp+C0h] [ebp-4B38h]
  int                               i; // [esp+C4h] [ebp-4B34h]
  int                               m_iGood; // [esp+C8h] [ebp-4B30h]
  char                              v39; // [esp+CFh] [ebp-4B29h]
  int                               iFlagX; // [esp+D0h] [ebp-4B28h]
  int                               iFlagY; // [esp+D4h] [ebp-4B24h]
  int                               m_uXOffset; // [esp+D8h] [ebp-4B20h]
  int                               m_uYOffset; // [esp+DCh] [ebp-4B1Ch]
  int                               j; // [esp+E0h] [ebp-4B18h]
  char                              v45; // [esp+E7h] [ebp-4B11h]
  char                              v46; // [esp+E8h] [ebp-4B10h]
  char                              v47; // [esp+E9h] [ebp-4B0Fh]
  char                              bAllInside; // [esp+EAh] [ebp-4B0Eh]
  char                              bValidBlockPosBits; // [esp+EBh] [ebp-4B0Dh]
  char                              bHotspotBlocked; // [esp+ECh] [ebp-4B0Ch]
  char                              v51; // [esp+EDh] [ebp-4B0Bh]
  char                              v52; // [esp+EEh] [ebp-4B0Ah]
  bool                              bSuccess; // [esp+EFh] [ebp-4B09h]
  CBuildingInfoMgr::SBuildingInfos *pBuildingInfo; // [esp+F0h] [ebp-4B08h]
  CBuildingBits                     cWaterBits{}; // [esp+F4h] [ebp-4B04h] BYREF
  CBuildingBits                     cBuildingBits{}; // [esp+19F4h] [ebp-3204h] BYREF
  CBuildingBits                     cBlockingBots{}; // [esp+32F4h] [ebp-1904h] BYREF

  bSuccess = true;

  BB_ASSERT(_iRace >= RACE_FIRST)
  BB_ASSERT(_iRace < RACE_MAX)
  BB_ASSERT(_iBuildingType > 0)
  BB_ASSERT(_iBuildingType < BUILDING_MAX)

  pBuildingInfo = &CBuildingInfoMgr::m_vBuildingInfos[_iRace][_iBuildingType];
  bAllInside = 1;
  CBuildingFlagsWalk cDigWalk = CBuildingFlagsWalk(0, 0, pBuildingInfo->m_iHotSpotX, pBuildingInfo->m_iHotSpotY, pBuildingInfo->m_vDigPosLines);; // [esp+58h] [ebp-4BA0h] BYREF
  while(cDigWalk.NextPosition()) {
    iY = cDigWalk.CurrentY() + 15;
    iX = cDigWalk.CurrentX();
    if(!Grid::InQuadrat(iX + 15, iY, 0x1Fu)) {
      bAllInside = 0;
      break;
    }
  }
  if(!bAllInside) {
    bSuccess = false;
    BBSupportTracePrintF(
      3,
      "Invalid digging bits for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_spName,
      _iRace);
  }
  v39 = 1;
  if(!pBuildingInfo->m_bIsPort
     && (pBuildingInfo->m_iBBRMinX < -15 || pBuildingInfo->m_iBBRMaxX > 15 || pBuildingInfo->m_iBBRMinY < -15 || pBuildingInfo->m_iBBRMaxY > 15)) {
    v39 = 0;
    BBSupportTracePrintF(
      3,
      "Invalid size of bounding box for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_spName,
      _iRace);
  }
  v47 = 1;
  v46 = 1;
  CBuildingFlagsWalk cBuildPosWalk = CBuildingFlagsWalk(
    0,
    0,
    pBuildingInfo->m_iHotSpotX,
    pBuildingInfo->m_iHotSpotY,
    pBuildingInfo->m_vBuildingPosLines);
  while(cBuildPosWalk.NextPosition()) {
    v4 = cBuildingBits.m_iBits[cBuildPosWalk.CurrentY() + 40];
    v4[cBuildPosWalk.CurrentX() + 40] = 1;
    v5 = cBuildPosWalk.CurrentX();
    if(v5 < pBuildingInfo->m_iBBRMinX
       || (v6 = cBuildPosWalk.CurrentX(), v6 > pBuildingInfo->m_iBBRMaxX)
       || (v7 = cBuildPosWalk.CurrentY(), v7 < pBuildingInfo->m_iBBRMinY)
       || (v8 = cBuildPosWalk.CurrentY(), v8 > pBuildingInfo->m_iBBRMaxY)) {
      v47 = 0;
    }
    if(cBuildPosWalk.CurrentX() < -15
       || cBuildPosWalk.CurrentX() > 15
       || cBuildPosWalk.CurrentY() < -15
       || cBuildPosWalk.CurrentY() > 15) {
      v46 = 0;
    }
  }
  if(!v47) {
    bSuccess = false;
    BBSupportTracePrintF(
      3,
      "Invalid bounding box for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_spName,
      _iRace);
  }
  if(!v46) {
    bSuccess = false;
    BBSupportTracePrintF(
      3,
      "Building bits out of range (-15..15) for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_spName,
      _iRace);
  }
  bValidBlockPosBits = 1;
  bHotspotBlocked = 0;
  CBuildingFlagsWalk cBlockPosWalk = CBuildingFlagsWalk(
    0,
    0,
    pBuildingInfo->m_iHotSpotX,
    pBuildingInfo->m_iHotSpotY,
    pBuildingInfo->m_vBlockPosLines);
  while(cBlockPosWalk.NextPosition()) {
    v35 = cBlockPosWalk.CurrentX();
    v36 = cBlockPosWalk.CurrentY();
    cBlockingBots.m_iBits[v36 + 40][v35 + 40] = 1;
    v34 = !v35 && !v36;
    bHotspotBlocked |= v34;
    for(i = 0; i <= 6; ++i) {
      v9 = CSpiralOffsets::DeltaX(i);
      v31 = v35 + v9;
      v10 = CSpiralOffsets::DeltaY(i);
      v25 = v36 + v10;
      if(!cBuildingBits.m_iBits[v36 + 40][80 * v10 + 40 + v31]) {
        BBSupportTracePrintF(3, "No building bits around blocking bit at (%i, %i)!", v35, v36);
        bValidBlockPosBits = 0;
      }
    }
  }
  if(!bHotspotBlocked) {
    BBSupportTracePrintF(3, "Hotspot not blocked!");
    bValidBlockPosBits = 0;
  }
  if(!bValidBlockPosBits) {
    bSuccess = false;
    BBSupportTracePrintF(
      3,
      "Invalid blocking bits for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_spName,
      _iRace);
  }
  v51 = 1;
  iPileNumber = pBuildingInfo->m_iPileNumber;
  for(j = 0; j < iPileNumber; ++j) {
    m_iGood = pBuildingInfo->m_vPileSpots[j].m_iGood;
    m_uXOffset = pBuildingInfo->m_vPileSpots[j].m_uXOffset;
    m_uYOffset = pBuildingInfo->m_vPileSpots[j].m_uYOffset;
    if((m_iGood <= 0 || m_iGood >= 43) && _iBuildingType != 13) {
      BBSupportTracePrintF(
        3,
        "Pile %i, good %i, position (%i, %i): Invalid good type!",
        j,
        m_iGood,
        m_uXOffset,
        m_uYOffset);
      v51 = 0;
    } else if(m_uXOffset < -15 || m_uXOffset > 15 || m_uYOffset < -15 || m_uYOffset > 15) {
      BBSupportTracePrintF(3, "Pile %i, good %i, position (%i, %i): Out of area!", j, m_iGood, m_uXOffset, m_uYOffset);
      v51 = 0;
    } else if(!cBuildingBits.m_iBits[m_uYOffset + 40][m_uXOffset + 40]) {
      BBSupportTracePrintF(
        3,
        "Pile %i, good %i, position (%i, %i): No building bit at position!",
        j,
        m_iGood,
        m_uXOffset,
        m_uYOffset);
      v51 = 0;
    } else if(cBlockingBots.m_iBits[m_uYOffset + 40][m_uXOffset + 40]) {
      BBSupportTracePrintF(
        3,
        "Pile %i, good %i, position (%i, %i): Position is blocked!",
        j,
        m_iGood,
        m_uXOffset,
        m_uYOffset);
      v51 = 0;
    }
  }
  if(!v51) {
    bSuccess = false;
    BBSupportTracePrintF(
      3,
      "Invalid piles for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_spName,
      _iRace);
  }
  v52 = 1;
  iFlagX = static_cast<char>(pBuildingInfo->m_iFlagX);
  iFlagY = static_cast<char>(pBuildingInfo->m_iFlagY);
  if(iFlagX >= -15 && iFlagX <= 15 && iFlagY >= -15 && iFlagY <= 15) {
    if(!cBuildingBits.m_iBits[iFlagY + 40][iFlagX + 39]) {
      BBSupportTracePrintF(3, "No building bit at flag position (-1, 0)!");
      v52 = 0;
    }
    if(!cBuildingBits.m_iBits[iFlagY + 40][iFlagX + 41]) {
      BBSupportTracePrintF(3, "No building bit at flag position (+1, 0)!");
      v52 = 0;
    }
    if(!cBuildingBits.m_iBits[iFlagY + 40][iFlagX + 40]) {
      BBSupportTracePrintF(3, "No building bit at flag position!");
      v52 = 0;
    }
    if(cBlockingBots.m_iBits[iFlagY + 40][iFlagX + 39]) {
      BBSupportTracePrintF(3, "Flag position (-1, 0) is blocked!");
      v52 = 0;
    }
    if(cBlockingBots.m_iBits[iFlagY + 40][iFlagX + 41]) {
      BBSupportTracePrintF(3, "Flag position (+1, 0) is blocked!");
      v52 = 0;
    }
    if(cBlockingBots.m_iBits[iFlagY + 40][iFlagX + 40]) {
      BBSupportTracePrintF(3, "Flag position is blocked!");
      v52 = 0;
    }
  } else {
    BBSupportTracePrintF(3, "Invalid flag position!");
    v52 = 0;
  }
  if(!v52)
    bSuccess = false;
  if(pBuildingInfo->m_bIsPort) {
    int m_iWorkPosXOffset;
    v45 = 0;
    m_iWorkPosXOffset = pBuildingInfo->m_iWorkPosXOffset;
    m_iWorkPosYOffset = pBuildingInfo->m_iWorkPosYOffset;
    CBuildingFlagsWalk v20 = CBuildingFlagsWalk(0, 0, pBuildingInfo->m_iHotSpotX, pBuildingInfo->m_iHotSpotY, pBuildingInfo->m_vBlockPosLines);
    while(v20.NextPosition()) {
      v29 = v20.CurrentX();
      v28 = v20.CurrentY();
      if(v29 == m_iWorkPosXOffset && v28 == m_iWorkPosYOffset) {
        v45 = 1;
        break;
      }
    }
    if(v45) {
      BBSupportTracePrintF(
        3,
        "Invalid working position (%i, %i) for building %i (%s) of race %i!",
        m_iWorkPosXOffset,
        m_iWorkPosYOffset,
        _iBuildingType,
        s_sBuildingDefines[_iBuildingType].m_spName,
        _iRace);
      bSuccess = false;
    }
  }
  if(pBuildingInfo->m_bIsPort) {
    CBuildingFlagsWalk v19 = CBuildingFlagsWalk(
      0,
      0,
      pBuildingInfo->m_iHotSpotX,
      pBuildingInfo->m_iHotSpotY,
      pBuildingInfo->m_vWaterRepealingPosLines);
    while(v19.NextPosition()) {
      v26 = v19.CurrentX();
      v27 = v19.CurrentY();
      cWaterBits.m_iBits[v27 + 40][v26 + 40] = 1;
    }
  }
  RaceName = CS4DefineNames::GetRaceName(_iRace);
  BuildingName = CS4DefineNames::GetBuildingName(_iBuildingType);
  BBSupportTracePrintF(-2147483641, "%s (%s)", BuildingName, RaceName);
  BBSupportTracePrintF(-2147483641, "Hotspot: ( %i, %i )", pBuildingInfo->m_iHotSpotX, pBuildingInfo->m_iHotSpotY);
  BBSupportTracePrintF(-2147483641, "B U I L D I N G   B I T S");
  cBuildingBits.PrintToTraceFile(-2147483641);
  v17 = CS4DefineNames::GetRaceName(_iRace);
  v12 = CS4DefineNames::GetBuildingName(_iBuildingType);
  BBSupportTracePrintF(-2147483641, "%s (%s)", v12, v17);
  BBSupportTracePrintF(-2147483641, "B L O C K I N G   B I T S");
  cBlockingBots.PrintToTraceFile(-2147483641);
  if(!pBuildingInfo->m_bIsPort)
    return bSuccess;
  v18 = CS4DefineNames::GetRaceName(_iRace);
  v13 = CS4DefineNames::GetBuildingName(_iBuildingType);
  BBSupportTracePrintF(-2147483641, "%s (%s)", v13, v18);
  BBSupportTracePrintF(-2147483641, "W A T E R   B I T S");
  cWaterBits.PrintToTraceFile(-2147483641);
  return bSuccess;
}


// address=[0x14ec5d0]
// Decompiled from void __thiscall CBuildingInfoMgr::DbgTraceProductionDelays(CBuildingInfoMgr *this)
void CBuildingInfoMgr::DbgTraceProductionDelays(void) {
  const char *BuildingName; // eax
  int         v2; // [esp-10h] [ebp-34h]
  int         v3; // [esp-Ch] [ebp-30h]
  int         v4; // [esp-8h] [ebp-2Ch]
  int         v5; // [esp-4h] [ebp-28h]
  signed int  i; // [esp+4h] [ebp-20h]
  int         j; // [esp+8h] [ebp-1Ch]
  _DWORD      v8[5]; // [esp+Ch] [ebp-18h]

  BBSupportTracePrintF(1, "%-30s  %-7s %-7s %-7s %-7s", "Building", "Roman", "Viking", "Maya", "Trojan");
  for(i = 1; i < 83; ++i) {
    for(j = 0; j < 5; ++j)
      v8[j] = CBuildingInfoMgr::m_vBuildingInfos[j][i].m_iProductionDelay;
    v5 = v8[4];
    v4 = v8[2];
    v3 = v8[1];
    v2 = v8[0];
    BuildingName = CS4DefineNames::GetBuildingName(i);
    BBSupportTracePrintF(1, "%-30s  %3i     %3i     %3i     %3i", BuildingName, v2, v3, v4, v5);
  }
}


// address=[0x14f3cc0]
// Decompiled from bool __cdecl CBuildingInfoMgr::BuildingTypeExIsPort(S4_BUILDING_ENUM a1)
bool __cdecl CBuildingInfoMgr::BuildingTypeExIsPort(int a1) {
  return a1 >= BUILDING_PORTA && a1 <= BUILDING_PORTF || a1 >= BUILDING_PORTG && a1 <= BUILDING_PORTH;
}


// address=[0x14f3d00]
// Decompiled from bool __cdecl CBuildingInfoMgr::BuildingTypeExIsShipyard(S4_BUILDING_ENUM a1)
bool __cdecl CBuildingInfoMgr::BuildingTypeExIsShipyard(int a1) {
  return a1 >= BUILDING_SHIPYARDA && a1 <= BUILDING_SHIPYARDF || a1 >= BUILDING_SHIPYARDG && a1 <= BUILDING_SHIPYARDH;
}


// address=[0x1501110]
// Decompiled from CBuildingInfoMgr::STriggerInfos *__cdecl CBuildingInfoMgr::GetTriggerInfo(int a1, int a2)
struct CBuildingInfoMgr::STriggerInfos const & __cdecl CBuildingInfoMgr::GetTriggerInfo(int a1, int a2) {
  BB_ASSERT(m_bInit == true)

  return CBuildingInfoMgr::m_vTriggerInfos[a1][a2];
}


// address=[0x14ec6c0]
// Decompiled from void __thiscall CBuildingInfoMgr::ClearInfo(CBuildingInfoMgr *this)
void CBuildingInfoMgr::ClearInfo(void) {
  int                               j; // [esp+8h] [ebp-Ch]
  int                               i; // [esp+Ch] [ebp-8h]
  CBuildingInfoMgr::SBuildingInfos *v4; // [esp+10h] [ebp-4h]

  CBuildingInfoMgr::m_bInit = false;
  for(i = 0; i < 5; ++i) {
    for(j = 0; j < 83; ++j) {
      v4 = &CBuildingInfoMgr::m_vBuildingInfos[i][j];
      // NOTE: This memset seems to be not quite right... Then again... maybe just me doing something wrong with the object definition?
      // Seems almost like it doesnt want to memset the vectors (Which is probably for the best?
      memset(
        v4,
        0,
        (char *) &CBuildingInfoMgr::m_vBuildingInfos[0][0].m_vAnimationList - (char *) CBuildingInfoMgr::m_vBuildingInfos);
      v4->m_vAnimationList.clear();
      v4->m_vBuildingPosLines.clear();
      v4->m_vDigPosLines.clear();
      v4->m_vBlockPosLines.clear();
      v4->m_vRepealingPosLines.clear();
      v4->m_vWaterPosLines.clear();
      v4->m_vWaterBlockPosLines.clear();
      v4->m_vWaterRepealingPosLines.clear();
      v4->m_vWaterFreePosLines.clear();
    }
  }
  memset(CBuildingInfoMgr::m_vTriggerInfos, 0, sizeof(CBuildingInfoMgr::m_vTriggerInfos));
  this->m_iXmlVersion = 0;
}

#define LOAD_INT(element, name, index) atoi(element(name, index).GetValue().c_str())
#define LOAD_CHILD_INT(element, base, child, index) atoi(element(base, 0)(child, index).GetValue().c_str())

// address=[0x14ec810]
// Decompiled from void __thiscall CBuildingInfoMgr::ReadBuildingInfo(CBuildingInfoMgr *this)
void CBuildingInfoMgr::ReadBuildingInfo(void) {
  using namespace AdvXMLParser;
  IConfigManager *pConfigManger = CConfigManagerPtr::GetInstance();

  long  iXmlSize = 0;
  auto *pInfoXmlData = Parser::OpenXMLFile(L"GameData\\BuildingInfo.xml", iXmlSize);
  if(!pInfoXmlData) {
    BB_REPORT("Failed to open BuildingInfo.xml file!");
    return;
  }

  Parser cParser = Parser();

  auto                   pDoc = std::unique_ptr<Document>(cParser.Parse(pInfoXmlData, iXmlSize));
  auto &                 rRoot = pDoc->GetRoot();
  ConstIterator<Element> rIt = rRoot.Begin();
  ConstIterator<Element> rEnd = rRoot.End();
  while(rIt < rEnd) {
    const Element &    rElement = *rIt;
    const std::string &rName = rElement.GetName();
    if(rName == "BuildingXMLVersion") {
      this->m_iXmlVersion = std::atoi(rElement.GetValue().c_str());
      ++rIt;
      continue;
    }


    const Attribute &  rIdAttr = rElement["id"];
    const std::string &sId = rIdAttr.GetValue();
    if(sId.empty()) {
      BBSupportTracePrintF(3, "BuildingInfo.xml: Missing id attribute for element '%s'!", rName.c_str());
      ++rIt;
      continue;
    }

    int                    iRace = g_pDefineTranslator->GetValueOfDefine(sId);
    ConstIterator<Element> rBuildingIt = rElement.Begin();
    ConstIterator<Element> rBuildingEnd = rElement.End();
    while(rBuildingIt < rBuildingEnd) {
      const Element &    rBuildingElement = *rBuildingIt;
      const Attribute &  rBuildingIdAttr = rBuildingElement["id"];
      const std::string &strBuildingName = rIdAttr.GetValue();

      BB_ASSERT(strBuildingName.length() > 0)
      if(strBuildingName.empty()) {
        BBSupportTracePrintF(3, "BuildingInfo.xml: Missing id attribute for building element '%s'!", rBuildingElement.GetName().c_str());
        ++rBuildingIt;
        continue;
      }

      int iBuildingIdx = pConfigManger->GetDefineValue(strBuildingName.c_str());
      BB_ASSERT(iBuildingIdx > 0)
      if(iBuildingIdx <= 0) {
        ++rBuildingIt;
        continue;
      }

      auto &rBuildingInfo = CBuildingInfoMgr::m_vBuildingInfos[iRace][iBuildingIdx];
      rBuildingInfo.m_iHotSpotX = LOAD_INT(rBuildingElement, "iHotSpotX", 0);
      rBuildingInfo.m_iHotSpotY = LOAD_INT(rBuildingElement, "iHotSpotY", 0);
      rBuildingInfo.m_iStone = LOAD_INT(rBuildingElement, "stone", 0);
      rBuildingInfo.m_iBoards = LOAD_INT(rBuildingElement, "boards", 0);
      rBuildingInfo.m_iGold = LOAD_INT(rBuildingElement, "gold", 0);
      rBuildingInfo.m_iLines = LOAD_INT(rBuildingElement, "lines", 0);

      for(int i = 0; i < rBuildingInfo.m_iLines; ++i) {
        rBuildingInfo.m_vBuildingPosLines.push_back(
          LOAD_CHILD_INT(rBuildingElement, "buildingPosLines", "value", i)
        );
        rBuildingInfo.m_vDigPosLines.push_back(
          LOAD_CHILD_INT(rBuildingElement, "digPosLines", "value", i)
        );
        rBuildingInfo.m_vBlockPosLines.push_back(
          LOAD_CHILD_INT(rBuildingElement, "blockPosLines", "value", i)
        );
        rBuildingInfo.m_vRepealingPosLines.push_back(
          LOAD_CHILD_INT(rBuildingElement, "repealingPosLines", "value", i)
        );
      }

      if(BuildingTypeExIsShipyard(iBuildingIdx) | BuildingTypeExIsPort(iBuildingIdx)) {
        rBuildingInfo.m_bIsPort = true;

        for(int i = 0; i < rBuildingInfo.m_iLines; ++i) {
          rBuildingInfo.m_vWaterPosLines.push_back(
            LOAD_CHILD_INT(rBuildingElement, "waterPosLines", "value", i)
          );
          rBuildingInfo.m_vWaterBlockPosLines.push_back(
            LOAD_CHILD_INT(rBuildingElement, "waterBlockPosLines", "value", i)
          );
          rBuildingInfo.m_vWaterFreePosLines.push_back(
            LOAD_CHILD_INT(rBuildingElement, "waterFreePosLines", "value", i)
          );
        }
      }

      rBuildingInfo.m_iBuilderNumber = atoi(rBuildingElement("builderNumber", 0).GetValue().c_str());
      for(int i = 0; i < rBuildingInfo.m_iBuilderNumber; ++i) {
        const auto &rBuilderInfoElement = rBuildingElement("builderInfo", i);
        rBuildingInfo.m_vBuilder[i].m_iXOffset = LOAD_INT(rBuilderInfoElement, "xOffset", 0);
        rBuildingInfo.m_vBuilder[i].m_iYOffset = LOAD_INT(rBuilderInfoElement, "yOffset", 0);
        rBuildingInfo.m_vBuilder[i].m_iDirection = LOAD_INT(rBuilderInfoElement, "dir", 0);
      }

      rBuildingInfo.m_iFlagX = LOAD_CHILD_INT(rBuildingElement, "flag", "xOffset", 0);
      rBuildingInfo.m_iFlagY = LOAD_CHILD_INT(rBuildingElement, "flag", "yOffset", 0);

      rBuildingInfo.m_iDoorXOffset = LOAD_CHILD_INT(rBuildingElement, "door", "xOffset", 0);
      rBuildingInfo.m_iDoorYOffset = LOAD_CHILD_INT(rBuildingElement, "door", "yOffset", 0);

      rBuildingInfo.m_iWorkPosXOffset = LOAD_CHILD_INT(rBuildingElement, "workingpos", "xOffset", 0);
      rBuildingInfo.m_iWorkPosYOffset = LOAD_CHILD_INT(rBuildingElement, "workingpos", "yOffset", 0);

      rBuildingInfo.m_iBBRMinX = LOAD_CHILD_INT(rBuildingElement, "bitBoundingRect", "minX", 0);
      rBuildingInfo.m_iBBRMaxX = LOAD_CHILD_INT(rBuildingElement, "bitBoundingRect", "maxX", 0);
      rBuildingInfo.m_iBBRMinY = LOAD_CHILD_INT(rBuildingElement, "bitBoundingRect", "minY", 0);
      rBuildingInfo.m_iBBRMaxY = LOAD_CHILD_INT(rBuildingElement, "bitBoundingRect", "maxY", 0);

      rBuildingInfo.m_iPileNumber = LOAD_INT(rBuildingElement, "pileNumber", 0);
      for(int i = 0; i < rBuildingInfo.m_iPileNumber; ++i) {
        const auto &rPileElement = rBuildingElement("pile", i);

        auto &rPileSpot = rBuildingInfo.m_vPileSpots[i];

        rPileSpot.m_uXOffset = LOAD_INT(rPileElement, "xOffset", 0);
        rPileSpot.m_uYOffset = LOAD_INT(rPileElement, "yOffset", 0);
        rPileSpot.m_iGood = pConfigManger->GetDefineValue(rPileElement("good", 0).GetValue().c_str());
        rPileSpot.m_iType = LOAD_INT(rPileElement, "type", 0);
        rPileSpot.m_iPatch = LOAD_INT(rPileElement, "patch", 0);
        rPileSpot.m_iAppearance = LOAD_INT(rPileElement, "appearance", 0);
        rPileSpot.m_iXPixelOffset = LOAD_INT(rPileElement, "xPixelOffset", 0);
        rPileSpot.m_iYPixelOffset = LOAD_INT(rPileElement, "yPixelOffset", 0);
      }
      rBuildingInfo.m_uWarriorNumber = LOAD_INT(rBuildingElement, "settlerNumber", 0);
      BB_ASSERT(rBuildingInfo.m_uWarriorNumber < MAX_NUMBER_OF_BUILDING_SETTLERS)
      for(int i = 0; i < rBuildingInfo.m_uWarriorNumber; ++i) {
        const auto &rSettlerElement = rBuildingElement("settler", i);
        auto &      rSettlerSpot = rBuildingInfo.m_vSettlerSpots[i];

        rSettlerSpot.m_iXOffset = LOAD_INT(rSettlerElement, "xOffset", 0);
        rSettlerSpot.m_iYOffset = LOAD_INT(rSettlerElement, "yOffset", 0);

        rSettlerSpot.m_iDirection = LOAD_INT(rSettlerElement, "direction", 0);
        rSettlerSpot.m_bTop = LOAD_INT(rSettlerElement, "top", 0);
      }

      rBuildingInfo.m_uSwordsmanNumber = 0;
      rBuildingInfo.m_uBowmanNumber = 0;
      rBuildingInfo.m_uU0 = -1;
      if(rBuildingInfo.m_uWarriorNumber > 0) {
        for(int i = 0; i < rBuildingInfo.m_uWarriorNumber; ++i) {
          if(rBuildingInfo.m_vSettlerSpots[i].m_bTop) {
            ++rBuildingInfo.m_uBowmanNumber;
            if((rBuildingInfo.m_uU0 & 0x80u) != 0)
              rBuildingInfo.m_uU0 = i;
          } else {
            ++rBuildingInfo.m_uSwordsmanNumber;
          }
        }

        if(!rBuildingInfo.m_uBowmanNumber) {
          BB_REPORTF("Bowman number == 0 for building %i (%s) of race %i!", iBuildingIdx, strBuildingName.c_str(), iRace);
        }
        if(!rBuildingInfo.m_uSwordsmanNumber) {
          BB_REPORTF("Swordsman number == 0 for building %i (%s) of race %i!", iBuildingIdx, strBuildingName.c_str(), iRace);
        }

        rBuildingInfo.m_iPatchSettlerSlot = LOAD_INT(rBuildingElement, "patchSettlerSlot", 0);
        rBuildingInfo.m_iMiniFlagXOffset = LOAD_CHILD_INT(rBuildingElement, "miniflag", "xOffset", 0);
        rBuildingInfo.m_iMiniFlagYOffset = LOAD_CHILD_INT(rBuildingElement, "miniflag", "yOffset", 0);
        rBuildingInfo.m_iBuildingKind = g_pDefineTranslator->GetValueOfDefine(rBuildingElement("kind", 0).GetValue());

        const auto &rInhabitant = rBuildingElement("inhabitant", 0).GetValue();
        if(rInhabitant.empty()) {
          rBuildingInfo.m_iBuildingInhabitant = 0;
        } else {
          rBuildingInfo.m_iBuildingInhabitant = pConfigManger->GetDefineValue(rInhabitant.c_str());
        }
        rBuildingInfo.m_iTool = pConfigManger->GetDefineValue(rBuildingElement("tool", 0).GetValue().c_str());
        auto iProductionDelay = LOAD_INT(rBuildingElement, "productiondelay", 0);

        BB_ASSERT((iProductionDelay >= 0) && (iProductionDelay <= 255))
        rBuildingInfo.m_iProductionDelay = min(max(iProductionDelay, 0), 255);
        rBuildingInfo.m_iDummyValue = LOAD_INT(rBuildingElement, "dummyValue", 0);
        rBuildingInfo.m_iInfluenceRadius = LOAD_INT(rBuildingElement, "influenceRadius", 0);
        rBuildingInfo.m_iExplorerRadius = LOAD_INT(rBuildingElement, "explorerRadius", 0);
        rBuildingInfo.m_iWorkingAreaRadius = LOAD_INT(rBuildingElement, "workingAreaRadius", 0);
        rBuildingInfo.m_iSearchType = g_pDefineTranslator->GetValueOfDefine(rBuildingElement("searchType", 0).GetValue());

        rBuildingInfo.m_iHealth = LOAD_INT(rBuildingElement, "Hitpoints", 0) / 2;
        rBuildingInfo.m_iArmor = LOAD_INT(rBuildingElement, "Armor", 0);
        if(!rBuildingInfo.m_iHealth) {
          char iStone = rBuildingInfo.m_iStone;
          char iBoards = rBuildingInfo.m_iBoards;
          char iGold = rBuildingInfo.m_iGold;
          int  iTotalResources = iGold + iBoards + iStone;
          int  iCalcHealth = 8 * iTotalResources / 2;
          if(iCalcHealth >= 250)
            rBuildingInfo.m_iHealth = 250;
          else
            rBuildingInfo.m_iHealth = iCalcHealth;
        }

        ConstIterator<Element> pAnimListIt = rBuildingElement("animationList", 0).Begin();
        ConstIterator<Element> pAnimListEnd = rBuildingElement("animationList", 0).End();
        while(pAnimListIt < pAnimListEnd) {
          const auto &rAnimElement = *pAnimListIt;
          const auto &rAnimName = rAnimElement.GetValue();
          rBuildingInfo.m_vAnimationList.push_back(pConfigManger->GetDefineValue(rAnimName.c_str()));
          ++pAnimListIt;
        }
        ConstIterator<Element> pPatchestIt = rBuildingElement("patches", 0).Begin();
        ConstIterator<Element> pPatchestEnd = rBuildingElement("patches", 0).End();
        int                    iPatch = 0;
        while(pPatchestIt < pPatchestEnd) {
          const auto &rPatchElement = *pPatchestIt;
          const auto &rJobElement = rPatchElement("job", 0);
          const auto &rJobName = rJobElement.GetValue();
          BB_ASSERT(rJobName.length() > 0)

          const auto iJobDefineValue = pConfigManger->GetDefineValue(rJobName.c_str());
          if(iJobDefineValue < 0) {
            BB_REPORTF("Patch job \"%s\" not valid for building %s for race %s!", rJobName.c_str(), strBuildingName.c_str(), CS4DefineNames::GetRaceName(iRace));
          }

          rBuildingInfo.m_vPatches[iPatch].m_iJob = iJobDefineValue;

          rBuildingInfo.m_vPatches[iPatch].m_iType = g_pDefineTranslator->GetValueOfDefine(rPatchElement("type", 0).GetValue().c_str());
          rBuildingInfo.m_vPatches[iPatch].m_iTicks = LOAD_INT(rPatchElement, "ticks", 0);
          rBuildingInfo.m_vPatches[iPatch].m_iSlot = LOAD_INT(rPatchElement, "slot", 0);
          rBuildingInfo.m_vPatches[iPatch].m_iSound = pConfigManger->GetDefineValue(rPatchElement("sound", 0)("def", 0).GetValue().c_str());
          rBuildingInfo.m_vPatches[iPatch].m_iSoundFrame = LOAD_CHILD_INT(rPatchElement, "sound", "frame", 0);
          rBuildingInfo.m_vPatches[iPatch].m_iSoundRandomness = LOAD_CHILD_INT(rPatchElement, "sound", "random", 0);
          if(!rBuildingInfo.m_vPatches[iPatch].m_iSoundRandomness)
            rBuildingInfo.m_vPatches[iPatch].m_iSoundRandomness = 100;

          ++iPatch;
          ++pPatchestIt;
        }

        ConstIterator<Element> pTriggerstIt = rBuildingElement("triggers", 0).Begin();
        ConstIterator<Element> pTriggerstEnd = rBuildingElement("triggers", 0).End();
        while(pTriggerstIt < pTriggerstEnd) {
          const auto &rTriggerElement = *pTriggerstIt;
          const auto  iSlot = LOAD_INT(rTriggerElement, "slot", 0);
          rBuildingInfo.m_vTriggers[iSlot] = g_pDefineTranslator->GetValueOfDefine(rTriggerElement("job", 0).GetValue().c_str());
          ++pTriggerstIt;
        }

        int iMaxDistance = 0;
        int iHotSpotX = -(char) rBuildingInfo.m_iHotSpotX;
        int iHotSpotY = -(char) rBuildingInfo.m_iHotSpotY;
        int m_iLines = (unsigned __int8) rBuildingInfo.m_iLines;
        for(int i = 0; i < m_iLines; ++i) {
          unsigned int uBuildingPosLine = rBuildingInfo.m_vBuildingPosLines[i];
          int          iX = i + iHotSpotY;
          int          iY = iHotSpotX;
          while(uBuildingPosLine) {
            if(uBuildingPosLine < 0) {
              int iPosDist = Grid::DistanceInline(iY, iX);
              if(iPosDist > iMaxDistance)
                iMaxDistance = iPosDist;
            }
            ++iY;
            uBuildingPosLine *= 2;
          }
        }
        BB_ASSERT((iMaxDistance >= 0) && (iMaxDistance < 64))
        rBuildingInfo.m_iMaxDistance = iMaxDistance;
        if(!this->DbgCheckBuildingBits(iRace, iBuildingIdx)) {
          BB_REPORTF("Invalid building bits for building %i (%s) of race %i (%s)!", iBuildingIdx, strBuildingName.c_str(), iRace, s_spRaceNames[iRace]);
        }
      }

      ++rBuildingIt;
    }

    ++rIt;
  }

  delete[] pInfoXmlData;
  pInfoXmlData = nullptr;

  BB_ASSERT(m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1)
  BB_ASSERT(m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2)
  BB_ASSERT(m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3)
  BB_ASSERT(m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3)
  BB_ASSERT(m_vBuildingInfos[RACE_ROMAN][BUILDING_CASTLE].m_uSwordsmanNumber == 4)
  BB_ASSERT(m_vBuildingInfos[RACE_ROMAN][BUILDING_CASTLE].m_uBowmanNumber == 5)
  BB_ASSERT(m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1)
  BB_ASSERT(m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2)
  BB_ASSERT(m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3)
  BB_ASSERT(m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3)
  BB_ASSERT(m_vBuildingInfos[RACE_VIKING][BUILDING_CASTLE].m_uSwordsmanNumber == 4)
  BB_ASSERT(m_vBuildingInfos[RACE_VIKING][BUILDING_CASTLE].m_uBowmanNumber == 5)
  BB_ASSERT(m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1)
  BB_ASSERT(m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2)
  BB_ASSERT(m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3)
  BB_ASSERT(m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3)
  BB_ASSERT(m_vBuildingInfos[RACE_MAYA][BUILDING_CASTLE].m_uSwordsmanNumber == 4)
  BB_ASSERT(m_vBuildingInfos[RACE_MAYA][BUILDING_CASTLE].m_uBowmanNumber == 5)
  BB_ASSERT(m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1)
  BB_ASSERT(m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2)
  BB_ASSERT(m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3)
  BB_ASSERT(m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3)
  BB_ASSERT(m_vBuildingInfos[RACE_TROJAN][BUILDING_CASTLE].m_uSwordsmanNumber == 4)
  BB_ASSERT(m_vBuildingInfos[RACE_TROJAN][BUILDING_CASTLE].m_uBowmanNumber == 5)

  memset(CBuildingInfoMgr::m_vTriggerInfos, 0, sizeof(CBuildingInfoMgr::m_vTriggerInfos));
  iXmlSize = 0;
  char *pTriggerXmlData = Parser::OpenXMLFile(L"GameData\\BuildingTrigger.xml", iXmlSize);
  BB_ASSERT(pTriggerXmlData)
  if(!pTriggerXmlData) return;

  auto                   pTriggerDocument = std::unique_ptr<Document>(Parser{}.Parse(pTriggerXmlData, iXmlSize));
  auto &                 rTriggerRoot = pTriggerDocument->GetRoot();
  ConstIterator<Element> rRaceIt = rTriggerRoot.Begin();
  ConstIterator<Element> rRaceEnd = rTriggerRoot.End();
  while(rRaceIt < rRaceEnd) {
    auto & rRaceRoot = *rRaceIt;
    auto &&rRaceId = rRaceRoot["id"].GetValue();
    auto   iRace = g_pDefineTranslator->GetValueOfDefine(rRaceId);

    ConstIterator<Element> rTriggerIt = rRaceRoot.Begin();
    ConstIterator<Element> rTriggerEnd = rRaceRoot.End();
    while(rTriggerIt < rTriggerEnd) {
      auto & rTriggerElement = *rTriggerIt;
      auto &&rTriggerId = rTriggerElement["id"].GetValue();
      auto   iId = g_pDefineTranslator->GetValueOfDefine(rTriggerId);

      auto &rTrigger = this->m_vTriggerInfos[iRace][iId];
      rTrigger.m_iType = g_pDefineTranslator->GetValueOfDefine(rTriggerElement("type", 0).GetValue());
      auto &rPatchElement = rTriggerElement("patch", 0);
      rTrigger.m_iPatchDefine = pConfigManger->GetDefineValue(rPatchElement("def", 0).GetValue().c_str());
      rTrigger.m_iSlot = LOAD_INT(rPatchElement, "slot", 0);
      rTrigger.m_iDuration = LOAD_INT(rPatchElement, "duration", 0);

      auto &rSoundElement = rTriggerElement("sound", 0);
      rTrigger.m_iPatchSoundId = pConfigManger->GetDefineValue(rSoundElement("def", 0).GetValue().c_str());
      rTrigger.m_iPatchSoundRandomness = LOAD_INT(rSoundElement, "random", 0);
      if(!rTrigger.m_iPatchSoundRandomness)
        rTrigger.m_iPatchSoundRandomness = 100;
      rTrigger.m_iPatchSoundFrame = LOAD_INT(rSoundElement, "frame", 0);

      auto &rEffectElement = rTriggerElement("effect", 0);
      rTrigger.m_iEffectX = LOAD_INT(rEffectElement, "x", 0);
      rTrigger.m_iEffectY = LOAD_INT(rEffectElement, "y", 0);
      rTrigger.m_bEffectSmoke = LOAD_INT(rEffectElement, "smoke", 0);
      rTrigger.m_iEffectDuration = LOAD_INT(rEffectElement, "duration", 0);

      auto &rEffectSoundElement = rEffectElement("sound", 0);
      rTrigger.m_iEffectSoundId = pConfigManger->GetDefineValue(rEffectSoundElement("def", 0).GetValue().c_str());
      rTrigger.m_iEffectSoundRandomness = LOAD_INT(rEffectSoundElement, "random", 0);
      if(!rTrigger.m_iPatchSoundRandomness) //NODE: Huh?
        rTrigger.m_iPatchSoundRandomness = 100;
      rTrigger.m_iPatchSoundFrame = LOAD_INT(rEffectSoundElement, "frame", 0);      // Whooops, looks wrong too O.O

      ++rTriggerIt;
    }

    ++rRaceIt;
  }

  delete[] pTriggerXmlData;
  pTriggerXmlData = nullptr;
}

// address=[0x4033188]
// [Decompilation failed for static struct CBuildingInfoMgr::STriggerInfos (* CBuildingInfoMgr::m_vTriggerInfos)[47]]

// address=[0x4035294]
// [Decompilation failed for static bool CBuildingInfoMgr::m_bInit]

// address=[0x40352a0]
// [Decompilation failed for static struct CBuildingInfoMgr::SBuildingInfos (* CBuildingInfoMgr::m_vBuildingInfos)[83]]

