#if FALSE
#include "CBuildingInfoMgr.h"

// Definitions for class CBuildingInfoMgr

// address=[0x133ac00]
// Decompiled from CBuildingInfoMgr::SBuildingInfos *__cdecl CBuildingInfoMgr::GetBuildingInfo(int a1, int a2)
struct CBuildingInfoMgr::SBuildingInfos const & __cdecl CBuildingInfoMgr::GetBuildingInfo(int a1, int a2) {
  
  if ( CBuildingInfoMgr::m_bInit != 1
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\building\\BuildingInfoMgr.h",
         312,
         "m_bInit == true") == 1 )
  {
    __debugbreak();
  }
  return &CBuildingInfoMgr::m_vBuildingInfos[a1][a2];
}


// address=[0x1486f70]
// Decompiled from int __thiscall CBuildingInfoMgr::GetXMLVersion(CBuildingInfoMgr *this)
int  CBuildingInfoMgr::GetXMLVersion(void)const {
  
  return this->m_iXmlVersion;
}


// address=[0x14eb8f0]
// Decompiled from CBuildingInfoMgr *__thiscall CBuildingInfoMgr::CBuildingInfoMgr(CBuildingInfoMgr *this)
 CBuildingInfoMgr::CBuildingInfoMgr(void) {
  
  CBuildingInfoMgr::ClearInfo(this);
  return this;
}


// address=[0x14eb910]
// Decompiled from void __thiscall CBuildingInfoMgr::~CBuildingInfoMgr(CBuildingInfoMgr *this)
 CBuildingInfoMgr::~CBuildingInfoMgr(void) {
  
  CBuildingInfoMgr::m_bInit = 0;
}


// address=[0x14eb930]
// Decompiled from void __thiscall CBuildingInfoMgr::LoadInfo(CBuildingInfoMgr *this, bool a2)
void  CBuildingInfoMgr::LoadInfo(bool a2) {
  
  if ( a2 )
    CBuildingInfoMgr::ClearInfo(this);
  if ( !CBuildingInfoMgr::m_bInit )
  {
    CBuildingInfoMgr::ReadBuildingInfo(this);
    CBuildingInfoMgr::m_bInit = 1;
  }
}


// address=[0x14eb970]
// Decompiled from char __thiscall CBuildingInfoMgr::DbgCheckBuildingBits(CBuildingInfoMgr *this, int _iRace, int _iBuildingType)
bool  CBuildingInfoMgr::DbgCheckBuildingBits(int _iRace, int _iBuildingType) {
  
  int iX; // eax
  BYTE *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  const char *BuildingName; // eax
  const char *v12; // eax
  const char *v13; // eax
  unsigned int iY; // [esp-8h] [ebp-4C00h]
  const char *RaceName; // [esp-4h] [ebp-4BFCh]
  const char *v17; // [esp-4h] [ebp-4BFCh]
  const char *v18; // [esp-4h] [ebp-4BFCh]
  CBuildingFlagsWalk v19; // [esp+4h] [ebp-4BF4h] BYREF
  CBuildingFlagsWalk v20; // [esp+20h] [ebp-4BD8h] BYREF
  CBuildingFlagsWalk cBlockPosWalk; // [esp+3Ch] [ebp-4BBCh] BYREF
  CBuildingFlagsWalk cDigWalk; // [esp+58h] [ebp-4BA0h] BYREF
  CBuildingFlagsWalk cBuildPosWalk; // [esp+78h] [ebp-4B80h] BYREF
  int v25; // [esp+94h] [ebp-4B64h]
  int v26; // [esp+98h] [ebp-4B60h]
  int v27; // [esp+9Ch] [ebp-4B5Ch]
  int v28; // [esp+A0h] [ebp-4B58h]
  int v29; // [esp+A4h] [ebp-4B54h]
  int iPileNumber; // [esp+A8h] [ebp-4B50h]
  int v31; // [esp+ACh] [ebp-4B4Ch]
  int m_iWorkPosXOffset; // [esp+B0h] [ebp-4B48h]
  int m_iWorkPosYOffset; // [esp+B4h] [ebp-4B44h]
  BOOL v34; // [esp+B8h] [ebp-4B40h]
  int v35; // [esp+BCh] [ebp-4B3Ch]
  int v36; // [esp+C0h] [ebp-4B38h]
  int i; // [esp+C4h] [ebp-4B34h]
  int m_iGood; // [esp+C8h] [ebp-4B30h]
  char v39; // [esp+CFh] [ebp-4B29h]
  int iFlagX; // [esp+D0h] [ebp-4B28h]
  int iFlagY; // [esp+D4h] [ebp-4B24h]
  int m_uXOffset; // [esp+D8h] [ebp-4B20h]
  int m_uYOffset; // [esp+DCh] [ebp-4B1Ch]
  int j; // [esp+E0h] [ebp-4B18h]
  char v45; // [esp+E7h] [ebp-4B11h]
  char v46; // [esp+E8h] [ebp-4B10h]
  char v47; // [esp+E9h] [ebp-4B0Fh]
  char bAllInside; // [esp+EAh] [ebp-4B0Eh]
  char bValidBlockPosBits; // [esp+EBh] [ebp-4B0Dh]
  char bHotspotBlocked; // [esp+ECh] [ebp-4B0Ch]
  char v51; // [esp+EDh] [ebp-4B0Bh]
  char v52; // [esp+EEh] [ebp-4B0Ah]
  char v53; // [esp+EFh] [ebp-4B09h]
  CBuildingInfoMgr::SBuildingInfos *v54; // [esp+F0h] [ebp-4B08h]
  CBuildingBits cWaterBits; // [esp+F4h] [ebp-4B04h] BYREF
  CBuildingBits cBuildingBits; // [esp+19F4h] [ebp-3204h] BYREF
  CBuildingBits cBlockingBots; // [esp+32F4h] [ebp-1904h] BYREF

  v53 = 1;
  CBuildingBits::CBuildingBits(&cBuildingBits);
  CBuildingBits::CBuildingBits(&cBlockingBots);
  CBuildingBits::CBuildingBits(&cWaterBits);
  if ( _iRace < 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 198, "_iRace >= RACE_FIRST") == 1 )
  {
    __debugbreak();
  }
  if ( _iRace >= 5 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 199, "_iRace < RACE_MAX") == 1 )
    __debugbreak();
  if ( _iBuildingType <= 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 200, "_iBuildingType > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iBuildingType >= 83
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 201, "_iBuildingType < BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v54 = &CBuildingInfoMgr::m_vBuildingInfos[_iRace][_iBuildingType];
  bAllInside = 1;
  CBuildingFlagsWalk::CBuildingFlagsWalk(&cDigWalk, 0, 0, v54->m_iHotSpotX, v54->m_iHotSpotY, &v54->m_vDigPosLines);
  while ( CBuildingFlagsWalk::NextPosition(&cDigWalk) )
  {
    iY = CBuildingFlagsWalk::CurrentY(&cDigWalk) + 15;
    iX = CBuildingFlagsWalk::CurrentX(&cDigWalk);
    if ( !Grid::InQuadrat(iX + 15, iY, 0x1Fu) )
    {
      bAllInside = 0;
      break;
    }
  }
  if ( !bAllInside )
  {
    v53 = 0;
    BBSupportTracePrintF(
      3,
      "Invalid digging bits for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_sName,
      _iRace);
  }
  v39 = 1;
  if ( !v54->m_bIsPort
    && (v54->m_iBBRMinX < -15 || v54->m_iBBRMaY > 15 || v54->m_iBBRMinY < -15 || v54->m_iBBRMaxY > 15) )
  {
    v39 = 0;
    BBSupportTracePrintF(
      3,
      "Invalid size of bounding box for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_sName,
      _iRace);
  }
  v47 = 1;
  v46 = 1;
  CBuildingFlagsWalk::CBuildingFlagsWalk(
    &cBuildPosWalk,
    0,
    0,
    v54->m_iHotSpotX,
    v54->m_iHotSpotY,
    &v54->m_vBuildingPosLines);
  while ( CBuildingFlagsWalk::NextPosition(&cBuildPosWalk) )
  {
    v4 = cBuildingBits.m_iBits[CBuildingFlagsWalk::CurrentY(&cBuildPosWalk) + 40];
    v4[CBuildingFlagsWalk::CurrentX(&cBuildPosWalk) + 40] = 1;
    v5 = CBuildingFlagsWalk::CurrentX(&cBuildPosWalk);
    if ( v5 < v54->m_iBBRMinX
      || (v6 = CBuildingFlagsWalk::CurrentX(&cBuildPosWalk), v6 > v54->m_iBBRMaY)
      || (v7 = CBuildingFlagsWalk::CurrentY(&cBuildPosWalk), v7 < v54->m_iBBRMinY)
      || (v8 = CBuildingFlagsWalk::CurrentY(&cBuildPosWalk), v8 > v54->m_iBBRMaxY) )
    {
      v47 = 0;
    }
    if ( CBuildingFlagsWalk::CurrentX(&cBuildPosWalk) < -15
      || CBuildingFlagsWalk::CurrentX(&cBuildPosWalk) > 15
      || CBuildingFlagsWalk::CurrentY(&cBuildPosWalk) < -15
      || CBuildingFlagsWalk::CurrentY(&cBuildPosWalk) > 15 )
    {
      v46 = 0;
    }
  }
  if ( !v47 )
  {
    v53 = 0;
    BBSupportTracePrintF(
      3,
      "Invalid bounding box for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_sName,
      _iRace);
  }
  if ( !v46 )
  {
    v53 = 0;
    BBSupportTracePrintF(
      3,
      "Building bits out of range (-15..15) for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_sName,
      _iRace);
  }
  bValidBlockPosBits = 1;
  bHotspotBlocked = 0;
  CBuildingFlagsWalk::CBuildingFlagsWalk(
    &cBlockPosWalk,
    0,
    0,
    v54->m_iHotSpotX,
    v54->m_iHotSpotY,
    &v54->m_vBlockPosLines);
  while ( CBuildingFlagsWalk::NextPosition(&cBlockPosWalk) )
  {
    v35 = CBuildingFlagsWalk::CurrentX(&cBlockPosWalk);
    v36 = CBuildingFlagsWalk::CurrentY(&cBlockPosWalk);
    cBlockingBots.m_iBits[v36 + 40][v35 + 40] = 1;
    v34 = !v35 && !v36;
    bHotspotBlocked |= v34;
    for ( i = 0; i <= 6; ++i )
    {
      v9 = CSpiralOffsets::DeltaX(i);
      v31 = v35 + v9;
      v10 = CSpiralOffsets::DeltaY(i);
      v25 = v36 + v10;
      if ( !cBuildingBits.m_iBits[v36 + 40][80 * v10 + 40 + v31] )
      {
        BBSupportTracePrintF(3, "No building bits around blocking bit at (%i, %i)!", v35, v36);
        bValidBlockPosBits = 0;
      }
    }
  }
  if ( !bHotspotBlocked )
  {
    BBSupportTracePrintF(3, "Hotspot not blocked!");
    bValidBlockPosBits = 0;
  }
  if ( !bValidBlockPosBits )
  {
    v53 = 0;
    BBSupportTracePrintF(
      3,
      "Invalid blocking bits for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_sName,
      _iRace);
  }
  v51 = 1;
  iPileNumber = v54->m_iPileNumber;
  for ( j = 0; j < iPileNumber; ++j )
  {
    m_iGood = v54->m_vPileSpots[j].m_iGood;
    m_uXOffset = v54->m_vPileSpots[j].m_uXOffset;
    m_uYOffset = v54->m_vPileSpots[j].m_uYOffset;
    if ( (m_iGood <= 0 || m_iGood >= 43) && _iBuildingType != 13 )
    {
      BBSupportTracePrintF(
        3,
        "Pile %i, good %i, position (%i, %i): Invalid good type!",
        j,
        m_iGood,
        m_uXOffset,
        m_uYOffset);
      v51 = 0;
    }
    else if ( m_uXOffset < -15 || m_uXOffset > 15 || m_uYOffset < -15 || m_uYOffset > 15 )
    {
      BBSupportTracePrintF(3, "Pile %i, good %i, position (%i, %i): Out of area!", j, m_iGood, m_uXOffset, m_uYOffset);
      v51 = 0;
    }
    else if ( !cBuildingBits.m_iBits[m_uYOffset + 40][m_uXOffset + 40] )
    {
      BBSupportTracePrintF(
        3,
        "Pile %i, good %i, position (%i, %i): No building bit at position!",
        j,
        m_iGood,
        m_uXOffset,
        m_uYOffset);
      v51 = 0;
    }
    else if ( cBlockingBots.m_iBits[m_uYOffset + 40][m_uXOffset + 40] )
    {
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
  if ( !v51 )
  {
    v53 = 0;
    BBSupportTracePrintF(
      3,
      "Invalid piles for building %i (%s) of race %i!",
      _iBuildingType,
      s_sBuildingDefines[_iBuildingType].m_sName,
      _iRace);
  }
  v52 = 1;
  iFlagX = (char)v54->m_iFlagX;
  iFlagY = (char)v54->m_iFlagY;
  if ( iFlagX >= -15 && iFlagX <= 15 && iFlagY >= -15 && iFlagY <= 15 )
  {
    if ( !cBuildingBits.m_iBits[iFlagY + 40][iFlagX + 39] )
    {
      BBSupportTracePrintF(3, "No building bit at flag position (-1, 0)!");
      v52 = 0;
    }
    if ( !cBuildingBits.m_iBits[iFlagY + 40][iFlagX + 41] )
    {
      BBSupportTracePrintF(3, "No building bit at flag position (+1, 0)!");
      v52 = 0;
    }
    if ( !cBuildingBits.m_iBits[iFlagY + 40][iFlagX + 40] )
    {
      BBSupportTracePrintF(3, "No building bit at flag position!");
      v52 = 0;
    }
    if ( cBlockingBots.m_iBits[iFlagY + 40][iFlagX + 39] )
    {
      BBSupportTracePrintF(3, "Flag position (-1, 0) is blocked!");
      v52 = 0;
    }
    if ( cBlockingBots.m_iBits[iFlagY + 40][iFlagX + 41] )
    {
      BBSupportTracePrintF(3, "Flag position (+1, 0) is blocked!");
      v52 = 0;
    }
    if ( cBlockingBots.m_iBits[iFlagY + 40][iFlagX + 40] )
    {
      BBSupportTracePrintF(3, "Flag position is blocked!");
      v52 = 0;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "Invalid flag position!");
    v52 = 0;
  }
  if ( !v52 )
    v53 = 0;
  if ( v54->m_bIsPort )
  {
    v45 = 0;
    m_iWorkPosXOffset = (char)v54->m_iWorkPosXOffset;
    m_iWorkPosYOffset = (char)v54->m_iWorkPosYOffset;
    CBuildingFlagsWalk::CBuildingFlagsWalk(&v20, 0, 0, v54->m_iHotSpotX, v54->m_iHotSpotY, &v54->m_vBlockPosLines);
    while ( CBuildingFlagsWalk::NextPosition(&v20) )
    {
      v29 = CBuildingFlagsWalk::CurrentX(&v20);
      v28 = CBuildingFlagsWalk::CurrentY(&v20);
      if ( v29 == m_iWorkPosXOffset && v28 == m_iWorkPosYOffset )
      {
        v45 = 1;
        break;
      }
    }
    if ( v45 )
    {
      BBSupportTracePrintF(
        3,
        "Invalid working position (%i, %i) for building %i (%s) of race %i!",
        m_iWorkPosXOffset,
        m_iWorkPosYOffset,
        _iBuildingType,
        s_sBuildingDefines[_iBuildingType].m_sName,
        _iRace);
      v53 = 0;
    }
  }
  if ( v54->m_bIsPort )
  {
    CBuildingFlagsWalk::CBuildingFlagsWalk(
      &v19,
      0,
      0,
      v54->m_iHotSpotX,
      v54->m_iHotSpotY,
      &v54->m_vWaterRepealingPosLines);
    while ( CBuildingFlagsWalk::NextPosition(&v19) )
    {
      v26 = CBuildingFlagsWalk::CurrentX(&v19);
      v27 = CBuildingFlagsWalk::CurrentY(&v19);
      cWaterBits.m_iBits[v27 + 40][v26 + 40] = 1;
    }
  }
  RaceName = CS4DefineNames::GetRaceName(_iRace);
  BuildingName = CS4DefineNames::GetBuildingName(_iBuildingType);
  BBSupportTracePrintF(-2147483641, "%s (%s)", BuildingName, RaceName);
  BBSupportTracePrintF(-2147483641, "Hotspot: ( %i, %i )", v54->m_iHotSpotX, v54->m_iHotSpotY);
  BBSupportTracePrintF(-2147483641, "B U I L D I N G   B I T S");
  CBuildingBits::PrintToTraceFile(&cBuildingBits, -2147483641);
  v17 = CS4DefineNames::GetRaceName(_iRace);
  v12 = CS4DefineNames::GetBuildingName(_iBuildingType);
  BBSupportTracePrintF(-2147483641, "%s (%s)", v12, v17);
  BBSupportTracePrintF(-2147483641, "B L O C K I N G   B I T S");
  CBuildingBits::PrintToTraceFile(&cBlockingBots, -2147483641);
  if ( !v54->m_bIsPort )
    return v53;
  v18 = CS4DefineNames::GetRaceName(_iRace);
  v13 = CS4DefineNames::GetBuildingName(_iBuildingType);
  BBSupportTracePrintF(-2147483641, "%s (%s)", v13, v18);
  BBSupportTracePrintF(-2147483641, "W A T E R   B I T S");
  CBuildingBits::PrintToTraceFile(&cWaterBits, -2147483641);
  return v53;
}


// address=[0x14ec5d0]
// Decompiled from void __thiscall CBuildingInfoMgr::DbgTraceProductionDelays(CBuildingInfoMgr *this)
void  CBuildingInfoMgr::DbgTraceProductionDelays(void) {
  
  const char *BuildingName; // eax
  int v2; // [esp-10h] [ebp-34h]
  int v3; // [esp-Ch] [ebp-30h]
  int v4; // [esp-8h] [ebp-2Ch]
  int v5; // [esp-4h] [ebp-28h]
  signed int i; // [esp+4h] [ebp-20h]
  int j; // [esp+8h] [ebp-1Ch]
  _DWORD v8[5]; // [esp+Ch] [ebp-18h]

  BBSupportTracePrintF(1, "%-30s  %-7s %-7s %-7s %-7s", "Building", "Roman", "Viking", "Maya", "Trojan");
  for ( i = 1; i < 83; ++i )
  {
    for ( j = 0; j < 5; ++j )
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
  
  if ( CBuildingInfoMgr::m_bInit != 1
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\building\\BuildingInfoMgr.h",
         351,
         "m_bInit == true") == 1 )
  {
    __debugbreak();
  }
  return &CBuildingInfoMgr::m_vTriggerInfos[a1][a2];
}


// address=[0x14ec6c0]
// Decompiled from void __thiscall CBuildingInfoMgr::ClearInfo(CBuildingInfoMgr *this)
void  CBuildingInfoMgr::ClearInfo(void) {
  
  int j; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  CBuildingInfoMgr::SBuildingInfos *v4; // [esp+10h] [ebp-4h]

  CBuildingInfoMgr::m_bInit = 0;
  for ( i = 0; i < 5; ++i )
  {
    for ( j = 0; j < 83; ++j )
    {
      v4 = &CBuildingInfoMgr::m_vBuildingInfos[i][j];
      memset(
        v4,
        0,
        (char *)&CBuildingInfoMgr::m_vBuildingInfos[0][0].m_vAnimationList - (char *)CBuildingInfoMgr::m_vBuildingInfos);
      std::vector<unsigned char>::clear(&v4->m_vAnimationList);
      std::vector<unsigned int>::clear(&v4->m_vBuildingPosLines);
      std::vector<unsigned int>::clear(&v4->m_vDigPosLines);
      std::vector<unsigned int>::clear(&v4->m_vBlockPosLines);
      std::vector<unsigned int>::clear(&v4->m_vRepealingPosLines);
      std::vector<unsigned int>::clear(&v4->m_vWaterPosLines);
      std::vector<unsigned int>::clear(&v4->m_vWaterBlockPosLines);
      std::vector<unsigned int>::clear(&v4->m_vWaterRepealingPosLines);
      std::vector<unsigned int>::clear(&v4->m_vWaterFreePosLines);
    }
  }
  memset(CBuildingInfoMgr::m_vTriggerInfos, 0, sizeof(CBuildingInfoMgr::m_vTriggerInfos));
  this->m_iXmlVersion = 0;
}


// address=[0x14ec810]
// Decompiled from void __thiscall CBuildingInfoMgr::ReadBuildingInfo(CBuildingInfoMgr *this)
void  CBuildingInfoMgr::ReadBuildingInfo(void) {
  
  int v1; // eax
  char *v2; // eax
  int v3; // eax
  char *v4; // eax
  char *v5; // eax
  char v6; // al
  char *v7; // eax
  char v8; // al
  char *v9; // eax
  BYTE v10; // al
  char *v11; // eax
  BYTE v12; // al
  char *v13; // eax
  BYTE v14; // al
  char *v15; // eax
  char v16; // al
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  char *v21; // eax
  char *v22; // eax
  char *v23; // eax
  char *v24; // eax
  char v25; // al
  char *v26; // eax
  BYTE v27; // al
  char *v28; // eax
  BYTE v29; // al
  char *v30; // eax
  BYTE v31; // al
  char *v32; // eax
  BYTE v33; // al
  char *v34; // eax
  BYTE v35; // al
  char *v36; // eax
  BYTE v37; // al
  char *v38; // eax
  BYTE v39; // al
  char *v40; // eax
  BYTE v41; // al
  char *v42; // eax
  BYTE v43; // al
  char *v44; // eax
  char v45; // al
  char *v46; // eax
  char v47; // al
  char *v48; // eax
  char v49; // al
  char *v50; // eax
  char v51; // al
  char *v52; // eax
  char v53; // al
  char *v54; // eax
  char v55; // al
  char *v56; // eax
  char v57; // al
  char *v58; // eax
  char *v59; // eax
  char v60; // al
  char *v61; // eax
  char v62; // al
  char *v63; // eax
  char v64; // al
  char *v65; // eax
  int v66; // eax
  char *v67; // eax
  int v68; // eax
  char *v69; // eax
  BYTE v70; // al
  char *v71; // eax
  int v72; // eax
  char *v73; // eax
  int v74; // eax
  char *v75; // eax
  char v76; // al
  char *v77; // eax
  char *v78; // eax
  char *v79; // eax
  BYTE v80; // al
  char *v81; // eax
  int v82; // eax
  char *v83; // eax
  int v84; // eax
  char *v85; // eax
  char *v86; // eax
  char *v87; // eax
  char *v88; // eax
  char *v89; // eax
  char *v90; // eax
  char *v91; // eax
  int v92; // eax
  char *v93; // eax
  int v94; // eax
  char *v95; // eax
  int v96; // eax
  char *v97; // eax
  int v98; // eax
  char *v99; // eax
  char *v100; // eax
  int v101; // eax
  char *v102; // eax
  char v103; // al
  char *v104; // eax
  char *v105; // eax
  char *v106; // eax
  char *v107; // eax
  char *v108; // eax
  char *v109; // eax
  char *v110; // eax
  char *v111; // eax
  BYTE v112; // al
  char *v113; // eax
  BYTE v114; // al
  char *v115; // eax
  char *v116; // eax
  BYTE v117; // al
  char *v118; // eax
  BYTE v119; // al
  char *v120; // eax
  char *v121; // eax
  char *v122; // eax
  int v123; // eax
  char *v124; // eax
  char *v125; // eax
  char *v126; // eax
  BYTE v127; // al
  char *v128; // eax
  BYTE v129; // al
  char *v130; // eax
  char *v131; // eax
  char *v132; // eax
  char *v133; // eax
  char *v134; // eax
  BYTE v135; // al
  char *v136; // eax
  BYTE v137; // al
  char *v138; // eax
  char *v139; // eax
  WORD v140; // ax
  char *v141; // eax
  WORD v142; // ax
  char *v143; // eax
  BYTE v144; // al
  char *v145; // eax
  BYTE v146; // al
  char *v147; // eax
  char *v148; // eax
  BYTE v149; // al
  char *v150; // eax
  BYTE v151; // al
  int v152; // [esp-4h] [ebp-1B34h]
  int v153; // [esp-4h] [ebp-1B34h]
  char *v154; // [esp-4h] [ebp-1B34h]
  int v155; // [esp+0h] [ebp-1B30h] BYREF
  _BYTE v156[28]; // [esp+10h] [ebp-1B20h] BYREF
  _BYTE v157[28]; // [esp+2Ch] [ebp-1B04h] BYREF
  _BYTE v158[16]; // [esp+58h] [ebp-1AD8h] BYREF
  _DWORD v159[4]; // [esp+68h] [ebp-1AC8h] BYREF
  _BYTE v160[16]; // [esp+78h] [ebp-1AB8h] BYREF
  _DWORD v161[4]; // [esp+88h] [ebp-1AA8h] BYREF
  _BYTE v162[16]; // [esp+98h] [ebp-1A98h] BYREF
  _DWORD v163[4]; // [esp+B8h] [ebp-1A78h] BYREF
  _BYTE v164[16]; // [esp+C8h] [ebp-1A68h] BYREF
  _DWORD v165[4]; // [esp+D8h] [ebp-1A58h] BYREF
  _BYTE v166[16]; // [esp+E8h] [ebp-1A48h] BYREF
  _DWORD v167[4]; // [esp+F8h] [ebp-1A38h] BYREF
  _BYTE v168[16]; // [esp+108h] [ebp-1A28h] BYREF
  _DWORD v169[4]; // [esp+118h] [ebp-1A18h] BYREF
  _DWORD v170[4]; // [esp+128h] [ebp-1A08h] BYREF
  _BYTE v171[16]; // [esp+138h] [ebp-19F8h] BYREF
  _DWORD v172[4]; // [esp+148h] [ebp-19E8h] BYREF
  _DWORD v173[4]; // [esp+158h] [ebp-19D8h] BYREF
  _DWORD v174[4]; // [esp+168h] [ebp-19C8h] BYREF
  _DWORD v175[4]; // [esp+178h] [ebp-19B8h] BYREF
  _DWORD v176[4]; // [esp+188h] [ebp-19A8h] BYREF
  _DWORD v177[4]; // [esp+198h] [ebp-1998h] BYREF
  _DWORD v178[39]; // [esp+1A8h] [ebp-1988h] BYREF
  _DWORD v179[4]; // [esp+244h] [ebp-18ECh] BYREF
  _DWORD v180[4]; // [esp+254h] [ebp-18DCh] BYREF
  _DWORD v181[4]; // [esp+264h] [ebp-18CCh] BYREF
  const struct AdvXMLParser::Element *v182; // [esp+274h] [ebp-18BCh]
  std::string *v183; // [esp+278h] [ebp-18B8h]
  AdvXMLParser::Element *v184; // [esp+27Ch] [ebp-18B4h]
  const struct AdvXMLParser::Element *v185; // [esp+280h] [ebp-18B0h]
  std::string *v186; // [esp+284h] [ebp-18ACh]
  AdvXMLParser::Element *v187; // [esp+288h] [ebp-18A8h]
  AdvXMLParser::Element *v188; // [esp+28Ch] [ebp-18A4h]
  AdvXMLParser::Element *v189; // [esp+290h] [ebp-18A0h]
  std::string *v190; // [esp+294h] [ebp-189Ch]
  AdvXMLParser::Element *v191; // [esp+298h] [ebp-1898h]
  AdvXMLParser::Element *v192; // [esp+29Ch] [ebp-1894h]
  AdvXMLParser::Element *v193; // [esp+2A0h] [ebp-1890h]
  std::string *v194; // [esp+2A4h] [ebp-188Ch]
  AdvXMLParser::Element *v195; // [esp+2A8h] [ebp-1888h]
  AdvXMLParser::Element *v196; // [esp+2ACh] [ebp-1884h]
  AdvXMLParser::Element *v197; // [esp+2B0h] [ebp-1880h]
  CConfigManager *v198; // [esp+2B4h] [ebp-187Ch]
  std::string *v199; // [esp+2B8h] [ebp-1878h]
  std::string *v200; // [esp+2BCh] [ebp-1874h]
  int v201; // [esp+2C0h] [ebp-1870h]
  AdvXMLParser::Element *v202; // [esp+2C4h] [ebp-186Ch]
  AdvXMLParser::Element *v203; // [esp+2C8h] [ebp-1868h]
  AdvXMLParser::Element *v204; // [esp+2CCh] [ebp-1864h]
  std::string *v205; // [esp+2D0h] [ebp-1860h]
  AdvXMLParser::Element *v206; // [esp+2D4h] [ebp-185Ch]
  AdvXMLParser::Element *v207; // [esp+2D8h] [ebp-1858h]
  AdvXMLParser::Element *v208; // [esp+2DCh] [ebp-1854h]
  std::string *v209; // [esp+2E0h] [ebp-1850h]
  AdvXMLParser::Element *v210; // [esp+2E4h] [ebp-184Ch]
  AdvXMLParser::Element *v211; // [esp+2E8h] [ebp-1848h]
  AdvXMLParser::Element *v212; // [esp+2ECh] [ebp-1844h]
  std::string *v213; // [esp+2F0h] [ebp-1840h]
  AdvXMLParser::Element *v214; // [esp+2F4h] [ebp-183Ch]
  AdvXMLParser::Element *v215; // [esp+2F8h] [ebp-1838h]
  const struct AdvXMLParser::Element *v216; // [esp+2FCh] [ebp-1834h]
  std::string *v217; // [esp+300h] [ebp-1830h]
  AdvXMLParser::Element *v218; // [esp+304h] [ebp-182Ch]
  AdvXMLParser::Element *v219; // [esp+308h] [ebp-1828h]
  const struct AdvXMLParser::Element *v220; // [esp+30Ch] [ebp-1824h]
  std::string *v221; // [esp+310h] [ebp-1820h]
  AdvXMLParser::Element *v222; // [esp+314h] [ebp-181Ch]
  AdvXMLParser::Element *v223; // [esp+318h] [ebp-1818h]
  std::string *v224; // [esp+31Ch] [ebp-1814h]
  int v225; // [esp+320h] [ebp-1810h]
  AdvXMLParser::Element *v226; // [esp+324h] [ebp-180Ch]
  AdvXMLParser::Element *v227; // [esp+328h] [ebp-1808h]
  AdvXMLParser::Element *v228; // [esp+32Ch] [ebp-1804h]
  std::string *v229; // [esp+330h] [ebp-1800h]
  AdvXMLParser::Element *v230; // [esp+334h] [ebp-17FCh]
  AdvXMLParser::Element *v231; // [esp+338h] [ebp-17F8h]
  const struct AdvXMLParser::Element *v232; // [esp+33Ch] [ebp-17F4h]
  std::string *v233; // [esp+340h] [ebp-17F0h]
  AdvXMLParser::Element *v234; // [esp+344h] [ebp-17ECh]
  AdvXMLParser::Element *v235; // [esp+348h] [ebp-17E8h]
  const struct AdvXMLParser::Element *v236; // [esp+34Ch] [ebp-17E4h]
  std::string *v237; // [esp+350h] [ebp-17E0h]
  AdvXMLParser::Element *v238; // [esp+354h] [ebp-17DCh]
  AdvXMLParser::Element *v239; // [esp+358h] [ebp-17D8h]
  AdvXMLParser::Element *v240; // [esp+35Ch] [ebp-17D4h]
  std::string *v241; // [esp+360h] [ebp-17D0h]
  int v242; // [esp+364h] [ebp-17CCh]
  int v243; // [esp+368h] [ebp-17C8h]
  AdvXMLParser::Element *v244; // [esp+36Ch] [ebp-17C4h]
  AdvXMLParser::Element *v245; // [esp+370h] [ebp-17C0h]
  std::string *v246; // [esp+374h] [ebp-17BCh]
  AdvXMLParser::Element *v247; // [esp+378h] [ebp-17B8h]
  AdvXMLParser::Element *v248; // [esp+37Ch] [ebp-17B4h]
  AdvXMLParser::Element *v249; // [esp+380h] [ebp-17B0h]
  std::string *v250; // [esp+384h] [ebp-17ACh]
  AdvXMLParser::Element *v251; // [esp+388h] [ebp-17A8h]
  AdvXMLParser::Element *v252; // [esp+38Ch] [ebp-17A4h]
  AdvXMLParser::Element *v253; // [esp+390h] [ebp-17A0h]
  std::string *v254; // [esp+394h] [ebp-179Ch]
  AdvXMLParser::Element *v255; // [esp+398h] [ebp-1798h]
  AdvXMLParser::Element *v256; // [esp+39Ch] [ebp-1794h]
  std::string *v257; // [esp+3A0h] [ebp-1790h]
  std::string *v258; // [esp+3A4h] [ebp-178Ch]
  struct CDefineTranslator *v259; // [esp+3A8h] [ebp-1788h]
  int v260; // [esp+3ACh] [ebp-1784h]
  AdvXMLParser::Element *v261; // [esp+3B0h] [ebp-1780h]
  AdvXMLParser::Element *v262; // [esp+3B4h] [ebp-177Ch]
  std::string *v263; // [esp+3B8h] [ebp-1778h]
  std::string *v264; // [esp+3BCh] [ebp-1774h]
  CConfigManager *v265; // [esp+3C0h] [ebp-1770h]
  int v266; // [esp+3C4h] [ebp-176Ch]
  AdvXMLParser::Element *v267; // [esp+3C8h] [ebp-1768h]
  AdvXMLParser::Element *v268; // [esp+3CCh] [ebp-1764h]
  CConfigManager *v269; // [esp+3D0h] [ebp-1760h]
  std::string *v270; // [esp+3D4h] [ebp-175Ch]
  std::string *v271; // [esp+3D8h] [ebp-1758h]
  int v272; // [esp+3DCh] [ebp-1754h]
  AdvXMLParser::Element *v273; // [esp+3E0h] [ebp-1750h]
  AdvXMLParser::Element *v274; // [esp+3E4h] [ebp-174Ch]
  AdvXMLParser::Element *v275; // [esp+3E8h] [ebp-1748h]
  std::string *v276; // [esp+3ECh] [ebp-1744h]
  std::string *v277; // [esp+3F0h] [ebp-1740h]
  int v278; // [esp+3F4h] [ebp-173Ch]
  AdvXMLParser::Element *v279; // [esp+3F8h] [ebp-1738h]
  AdvXMLParser::Element *v280; // [esp+3FCh] [ebp-1734h]
  std::string *v281; // [esp+400h] [ebp-1730h]
  AdvXMLParser::Element *v282; // [esp+404h] [ebp-172Ch]
  AdvXMLParser::Element *v283; // [esp+408h] [ebp-1728h]
  _DWORD v284[4]; // [esp+40Ch] [ebp-1724h] BYREF
  std::string *v285; // [esp+41Ch] [ebp-1714h]
  AdvXMLParser::Element *v286; // [esp+420h] [ebp-1710h]
  std::string *v287; // [esp+424h] [ebp-170Ch]
  void *v288; // [esp+428h] [ebp-1708h]
  std::string *v289; // [esp+42Ch] [ebp-1704h]
  AdvXMLParser::Element *v290; // [esp+430h] [ebp-1700h]
  AdvXMLParser::Element *v291; // [esp+434h] [ebp-16FCh]
  AdvXMLParser::Element *v292; // [esp+438h] [ebp-16F8h]
  AdvXMLParser::Element *v293; // [esp+43Ch] [ebp-16F4h]
  std::string *v294; // [esp+440h] [ebp-16F0h]
  AdvXMLParser::Element *v295; // [esp+444h] [ebp-16ECh]
  AdvXMLParser::Element *v296; // [esp+448h] [ebp-16E8h]
  AdvXMLParser::Element *v297; // [esp+44Ch] [ebp-16E4h]
  AdvXMLParser::Element *v298; // [esp+450h] [ebp-16E0h]
  int v299; // [esp+454h] [ebp-16DCh]
  std::string *v300; // [esp+458h] [ebp-16D8h]
  std::string *v301; // [esp+45Ch] [ebp-16D4h]
  CConfigManager *v302; // [esp+460h] [ebp-16D0h]
  AdvXMLParser::Element *v303; // [esp+464h] [ebp-16CCh]
  AdvXMLParser::Element *v304; // [esp+468h] [ebp-16C8h]
  AdvXMLParser::Element *v305; // [esp+46Ch] [ebp-16C4h]
  AdvXMLParser::Element *v306; // [esp+470h] [ebp-16C0h]
  std::string *v307; // [esp+474h] [ebp-16BCh]
  AdvXMLParser::Element *v308; // [esp+478h] [ebp-16B8h]
  AdvXMLParser::Element *v309; // [esp+47Ch] [ebp-16B4h]
  AdvXMLParser::Element *v310; // [esp+480h] [ebp-16B0h]
  std::string *v311; // [esp+484h] [ebp-16ACh]
  AdvXMLParser::Element *v312; // [esp+488h] [ebp-16A8h]
  AdvXMLParser::Element *v313; // [esp+48Ch] [ebp-16A4h]
  AdvXMLParser::Element *v314; // [esp+490h] [ebp-16A0h]
  std::string *v315; // [esp+494h] [ebp-169Ch]
  AdvXMLParser::Element *v316; // [esp+498h] [ebp-1698h]
  AdvXMLParser::Element *v317; // [esp+49Ch] [ebp-1694h]
  AdvXMLParser::Element *v318; // [esp+4A0h] [ebp-1690h]
  std::string *v319; // [esp+4A4h] [ebp-168Ch]
  AdvXMLParser::Element *v320; // [esp+4A8h] [ebp-1688h]
  AdvXMLParser::Element *v321; // [esp+4ACh] [ebp-1684h]
  AdvXMLParser::Element *v322; // [esp+4B0h] [ebp-1680h]
  int v323; // [esp+4B4h] [ebp-167Ch]
  std::string *v324; // [esp+4B8h] [ebp-1678h]
  std::string *v325; // [esp+4BCh] [ebp-1674h]
  CConfigManager *v326; // [esp+4C0h] [ebp-1670h]
  AdvXMLParser::Element *v327; // [esp+4C4h] [ebp-166Ch]
  AdvXMLParser::Element *v328; // [esp+4C8h] [ebp-1668h]
  AdvXMLParser::Element *v329; // [esp+4CCh] [ebp-1664h]
  std::string *v330; // [esp+4D0h] [ebp-1660h]
  AdvXMLParser::Element *v331; // [esp+4D4h] [ebp-165Ch]
  AdvXMLParser::Element *v332; // [esp+4D8h] [ebp-1658h]
  AdvXMLParser::Element *v333; // [esp+4DCh] [ebp-1654h]
  AdvXMLParser::Element *v334; // [esp+4E0h] [ebp-1650h]
  std::string *v335; // [esp+4E4h] [ebp-164Ch]
  AdvXMLParser::Element *v336; // [esp+4E8h] [ebp-1648h]
  AdvXMLParser::Element *v337; // [esp+4ECh] [ebp-1644h]
  AdvXMLParser::Element *v338; // [esp+4F0h] [ebp-1640h]
  AdvXMLParser::Element *v339; // [esp+4F4h] [ebp-163Ch]
  int v340; // [esp+4F8h] [ebp-1638h]
  CConfigManager *v341; // [esp+4FCh] [ebp-1634h]
  std::string *v342; // [esp+500h] [ebp-1630h]
  std::string *v343; // [esp+504h] [ebp-162Ch]
  AdvXMLParser::Element *v344; // [esp+508h] [ebp-1628h]
  AdvXMLParser::Element *v345; // [esp+50Ch] [ebp-1624h]
  AdvXMLParser::Element *v346; // [esp+510h] [ebp-1620h]
  AdvXMLParser::Element *v347; // [esp+514h] [ebp-161Ch]
  int v348; // [esp+518h] [ebp-1618h]
  struct CDefineTranslator *v349; // [esp+51Ch] [ebp-1614h]
  std::string *v350; // [esp+520h] [ebp-1610h]
  std::string *v351; // [esp+524h] [ebp-160Ch]
  AdvXMLParser::Element *v352; // [esp+528h] [ebp-1608h]
  AdvXMLParser::Element *v353; // [esp+52Ch] [ebp-1604h]
  std::string *v354; // [esp+530h] [ebp-1600h]
  AdvXMLParser::Element *v355; // [esp+534h] [ebp-15FCh]
  AdvXMLParser::Element *v356; // [esp+538h] [ebp-15F8h]
  AdvXMLParser::Element *v357; // [esp+53Ch] [ebp-15F4h]
  std::string *v358; // [esp+540h] [ebp-15F0h]
  AdvXMLParser::Element *v359; // [esp+544h] [ebp-15ECh]
  AdvXMLParser::Element *v360; // [esp+548h] [ebp-15E8h]
  AdvXMLParser::Element *v361; // [esp+54Ch] [ebp-15E4h]
  int v362; // [esp+550h] [ebp-15E0h]
  CConfigManager *v363; // [esp+554h] [ebp-15DCh]
  std::string *v364; // [esp+558h] [ebp-15D8h]
  std::string *v365; // [esp+55Ch] [ebp-15D4h]
  AdvXMLParser::Element *v366; // [esp+560h] [ebp-15D0h]
  AdvXMLParser::Element *v367; // [esp+564h] [ebp-15CCh]
  AdvXMLParser::Element *v368; // [esp+568h] [ebp-15C8h]
  int v369; // [esp+56Ch] [ebp-15C4h]
  int v370; // [esp+570h] [ebp-15C0h]
  int v371; // [esp+574h] [ebp-15BCh]
  const struct AdvXMLParser::Attribute *v372; // [esp+578h] [ebp-15B8h]
  AdvXMLParser::Element *v373; // [esp+57Ch] [ebp-15B4h]
  _DWORD *v374; // [esp+580h] [ebp-15B0h]
  _DWORD *v375; // [esp+584h] [ebp-15ACh]
  void *v376; // [esp+588h] [ebp-15A8h]
  _DWORD *v377; // [esp+58Ch] [ebp-15A4h]
  _DWORD *v378; // [esp+590h] [ebp-15A0h]
  int v379; // [esp+594h] [ebp-159Ch]
  int v380; // [esp+598h] [ebp-1598h]
  const struct AdvXMLParser::Attribute *v381; // [esp+59Ch] [ebp-1594h]
  AdvXMLParser::Element *v382; // [esp+5A0h] [ebp-1590h]
  _DWORD *v383; // [esp+5A4h] [ebp-158Ch]
  _DWORD *v384; // [esp+5A8h] [ebp-1588h]
  _DWORD *v385; // [esp+5ACh] [ebp-1584h]
  _DWORD *v386; // [esp+5B0h] [ebp-1580h]
  struct CDefineTranslator *v387; // [esp+5B4h] [ebp-157Ch]
  void *v388; // [esp+5B8h] [ebp-1578h]
  int v389; // [esp+5BCh] [ebp-1574h]
  void *C; // [esp+5C0h] [ebp-1570h]
  int v391; // [esp+5C4h] [ebp-156Ch]
  const char *RaceName; // [esp+5C8h] [ebp-1568h]
  int v393; // [esp+5CCh] [ebp-1564h]
  int v394; // [esp+5D0h] [ebp-1560h]
  int v395; // [esp+5D4h] [ebp-155Ch]
  int v396; // [esp+5D8h] [ebp-1558h]
  int v397; // [esp+5DCh] [ebp-1554h]
  int *v398; // [esp+5E0h] [ebp-1550h]
  signed int m_iLines; // [esp+5E4h] [ebp-154Ch]
  int v400; // [esp+5E8h] [ebp-1548h]
  int v401; // [esp+5ECh] [ebp-1544h]
  int v402; // [esp+5F0h] [ebp-1540h]
  struct CDefineTranslator *v403; // [esp+5F4h] [ebp-153Ch]
  std::string *v404; // [esp+5F8h] [ebp-1538h]
  std::string *v405; // [esp+5FCh] [ebp-1534h]
  const struct AdvXMLParser::Element *v406; // [esp+600h] [ebp-1530h]
  AdvXMLParser::Element *v407; // [esp+604h] [ebp-152Ch]
  std::string *v408; // [esp+608h] [ebp-1528h]
  const struct AdvXMLParser::Element *v409; // [esp+60Ch] [ebp-1524h]
  AdvXMLParser::Element *v410; // [esp+610h] [ebp-1520h]
  _DWORD *v411; // [esp+614h] [ebp-151Ch]
  _DWORD *v412; // [esp+618h] [ebp-1518h]
  struct AdvXMLParser::Element *v413; // [esp+61Ch] [ebp-1514h]
  AdvXMLParser::Element *v414; // [esp+620h] [ebp-1510h]
  _DWORD *v415; // [esp+624h] [ebp-150Ch]
  _DWORD *v416; // [esp+628h] [ebp-1508h]
  const struct AdvXMLParser::Element *v417; // [esp+62Ch] [ebp-1504h]
  AdvXMLParser::Element *v418; // [esp+630h] [ebp-1500h]
  std::string *v419; // [esp+634h] [ebp-14FCh]
  AdvXMLParser::Element *v420; // [esp+638h] [ebp-14F8h]
  AdvXMLParser::Element *v421; // [esp+63Ch] [ebp-14F4h]
  AdvXMLParser::Element *v422; // [esp+640h] [ebp-14F0h]
  std::string *v423; // [esp+644h] [ebp-14ECh]
  AdvXMLParser::Element *v424; // [esp+648h] [ebp-14E8h]
  AdvXMLParser::Element *v425; // [esp+64Ch] [ebp-14E4h]
  AdvXMLParser::Element *v426; // [esp+650h] [ebp-14E0h]
  int v427; // [esp+654h] [ebp-14DCh]
  std::string *v428; // [esp+658h] [ebp-14D8h]
  std::string *v429; // [esp+65Ch] [ebp-14D4h]
  CConfigManager *v430; // [esp+660h] [ebp-14D0h]
  AdvXMLParser::Element *v431; // [esp+664h] [ebp-14CCh]
  AdvXMLParser::Element *v432; // [esp+668h] [ebp-14C8h]
  AdvXMLParser::Element *v433; // [esp+66Ch] [ebp-14C4h]
  std::string *v434; // [esp+670h] [ebp-14C0h]
  AdvXMLParser::Element *v435; // [esp+674h] [ebp-14BCh]
  AdvXMLParser::Element *v436; // [esp+678h] [ebp-14B8h]
  std::string *v437; // [esp+67Ch] [ebp-14B4h]
  AdvXMLParser::Element *v438; // [esp+680h] [ebp-14B0h]
  AdvXMLParser::Element *v439; // [esp+684h] [ebp-14ACh]
  int v440; // [esp+688h] [ebp-14A8h]
  struct CDefineTranslator *v441; // [esp+68Ch] [ebp-14A4h]
  std::string *v442; // [esp+690h] [ebp-14A0h]
  std::string *v443; // [esp+694h] [ebp-149Ch]
  AdvXMLParser::Element *v444; // [esp+698h] [ebp-1498h]
  AdvXMLParser::Element *v445; // [esp+69Ch] [ebp-1494h]
  int v446; // [esp+6A0h] [ebp-1490h]
  int jobDefineValue; // [esp+6A4h] [ebp-148Ch] MAPDST
  std::string *v448; // [esp+6A8h] [ebp-1488h]
  std::string *v449; // [esp+6ACh] [ebp-1484h]
  CConfigManager *v450; // [esp+6B0h] [ebp-1480h]
  AdvXMLParser::Element *v451; // [esp+6B4h] [ebp-147Ch]
  AdvXMLParser::Element *v452; // [esp+6B8h] [ebp-1478h]
  int v453; // [esp+6BCh] [ebp-1474h]
  std::string *v454; // [esp+6C0h] [ebp-1470h]
  std::string *v455; // [esp+6C4h] [ebp-146Ch]
  AdvXMLParser::Element *v456; // [esp+6C8h] [ebp-1468h]
  AdvXMLParser::Element *v457; // [esp+6CCh] [ebp-1464h]
  _DWORD *v458; // [esp+6D0h] [ebp-1460h]
  _DWORD *v459; // [esp+6D4h] [ebp-145Ch]
  struct AdvXMLParser::Element *v460; // [esp+6D8h] [ebp-1458h]
  AdvXMLParser::Element *v461; // [esp+6DCh] [ebp-1454h]
  _DWORD *v462; // [esp+6E0h] [ebp-1450h]
  _DWORD *v463; // [esp+6E4h] [ebp-144Ch]
  const struct AdvXMLParser::Element *v464; // [esp+6E8h] [ebp-1448h]
  AdvXMLParser::Element *v465; // [esp+6ECh] [ebp-1444h]
  int v466; // [esp+6F0h] [ebp-1440h]
  int v467; // [esp+6F4h] [ebp-143Ch]
  CConfigManager *v468; // [esp+6F8h] [ebp-1438h]
  std::string *v469; // [esp+6FCh] [ebp-1434h]
  std::string *v470; // [esp+700h] [ebp-1430h]
  AdvXMLParser::Element *v471; // [esp+704h] [ebp-142Ch]
  _DWORD *v472; // [esp+708h] [ebp-1428h]
  _DWORD *v473; // [esp+70Ch] [ebp-1424h]
  struct AdvXMLParser::Element *v474; // [esp+710h] [ebp-1420h]
  AdvXMLParser::Element *v475; // [esp+714h] [ebp-141Ch]
  _DWORD *v476; // [esp+718h] [ebp-1418h]
  _DWORD *v477; // [esp+71Ch] [ebp-1414h]
  const struct AdvXMLParser::Element *v478; // [esp+720h] [ebp-1410h]
  AdvXMLParser::Element *v479; // [esp+724h] [ebp-140Ch]
  int iTotalResources; // [esp+728h] [ebp-1408h]
  int m_iGold; // [esp+72Ch] [ebp-1404h]
  int m_iBoards; // [esp+730h] [ebp-1400h]
  int m_iStone; // [esp+734h] [ebp-13FCh]
  std::string *v484; // [esp+738h] [ebp-13F8h]
  AdvXMLParser::Element *v485; // [esp+73Ch] [ebp-13F4h]
  AdvXMLParser::Element *v486; // [esp+740h] [ebp-13F0h]
  std::string *v487; // [esp+744h] [ebp-13ECh]
  AdvXMLParser::Element *v488; // [esp+748h] [ebp-13E8h]
  AdvXMLParser::Element *v489; // [esp+74Ch] [ebp-13E4h]
  int v490; // [esp+750h] [ebp-13E0h]
  struct CDefineTranslator *v491; // [esp+754h] [ebp-13DCh]
  std::string *v492; // [esp+758h] [ebp-13D8h]
  std::string *v493; // [esp+75Ch] [ebp-13D4h]
  AdvXMLParser::Element *v494; // [esp+760h] [ebp-13D0h]
  AdvXMLParser::Element *v495; // [esp+764h] [ebp-13CCh]
  std::string *v496; // [esp+768h] [ebp-13C8h]
  AdvXMLParser::Element *v497; // [esp+76Ch] [ebp-13C4h]
  AdvXMLParser::Element *v498; // [esp+770h] [ebp-13C0h]
  AdvXMLParser::Element *v499; // [esp+774h] [ebp-13BCh]
  AdvXMLParser::Element *v500; // [esp+778h] [ebp-13B8h]
  std::string *v501; // [esp+77Ch] [ebp-13B4h]
  const struct AdvXMLParser::Element *v502; // [esp+780h] [ebp-13B0h]
  AdvXMLParser::Element *v503; // [esp+784h] [ebp-13ACh]
  AdvXMLParser::Element *v504; // [esp+788h] [ebp-13A8h]
  std::string *v505; // [esp+78Ch] [ebp-13A4h]
  const struct AdvXMLParser::Element *v506; // [esp+790h] [ebp-13A0h]
  AdvXMLParser::Element *v507; // [esp+794h] [ebp-139Ch]
  AdvXMLParser::Element *v508; // [esp+798h] [ebp-1398h]
  std::string *v509; // [esp+79Ch] [ebp-1394h]
  AdvXMLParser::Element *v510; // [esp+7A0h] [ebp-1390h]
  AdvXMLParser::Element *v511; // [esp+7A4h] [ebp-138Ch]
  AdvXMLParser::Element *v512; // [esp+7A8h] [ebp-1388h]
  std::string *v513; // [esp+7ACh] [ebp-1384h]
  AdvXMLParser::Element *v514; // [esp+7B0h] [ebp-1380h]
  AdvXMLParser::Element *v515; // [esp+7B4h] [ebp-137Ch]
  AdvXMLParser::Element *v516; // [esp+7B8h] [ebp-1378h]
  std::string *v517; // [esp+7BCh] [ebp-1374h]
  AdvXMLParser::Element *v518; // [esp+7C0h] [ebp-1370h]
  AdvXMLParser::Element *v519; // [esp+7C4h] [ebp-136Ch]
  AdvXMLParser::Element *v520; // [esp+7C8h] [ebp-1368h]
  std::string *v521; // [esp+7CCh] [ebp-1364h]
  AdvXMLParser::Element *v522; // [esp+7D0h] [ebp-1360h]
  AdvXMLParser::Element *v523; // [esp+7D4h] [ebp-135Ch]
  AdvXMLParser::Element *v524; // [esp+7D8h] [ebp-1358h]
  std::string *v525; // [esp+7DCh] [ebp-1354h]
  AdvXMLParser::Element *v526; // [esp+7E0h] [ebp-1350h]
  AdvXMLParser::Element *v527; // [esp+7E4h] [ebp-134Ch]
  AdvXMLParser::Element *v528; // [esp+7E8h] [ebp-1348h]
  std::string *v529; // [esp+7ECh] [ebp-1344h]
  AdvXMLParser::Element *v530; // [esp+7F0h] [ebp-1340h]
  AdvXMLParser::Element *v531; // [esp+7F4h] [ebp-133Ch]
  AdvXMLParser::Element *v532; // [esp+7F8h] [ebp-1338h]
  std::string *v533; // [esp+7FCh] [ebp-1334h]
  AdvXMLParser::Element *v534; // [esp+800h] [ebp-1330h]
  AdvXMLParser::Element *v535; // [esp+804h] [ebp-132Ch]
  AdvXMLParser::Element *v536; // [esp+808h] [ebp-1328h]
  std::string *v537; // [esp+80Ch] [ebp-1324h]
  AdvXMLParser::Element *v538; // [esp+810h] [ebp-1320h]
  AdvXMLParser::Element *v539; // [esp+814h] [ebp-131Ch]
  AdvXMLParser::Element *v540; // [esp+818h] [ebp-1318h]
  std::string *v541; // [esp+81Ch] [ebp-1314h]
  AdvXMLParser::Element *v542; // [esp+820h] [ebp-1310h]
  AdvXMLParser::Element *v543; // [esp+824h] [ebp-130Ch]
  AdvXMLParser::Element *v544; // [esp+828h] [ebp-1308h]
  std::string *v545; // [esp+82Ch] [ebp-1304h]
  AdvXMLParser::Element *v546; // [esp+830h] [ebp-1300h]
  AdvXMLParser::Element *v547; // [esp+834h] [ebp-12FCh]
  AdvXMLParser::Element *v548; // [esp+838h] [ebp-12F8h]
  std::string *v549; // [esp+83Ch] [ebp-12F4h]
  AdvXMLParser::Element *v550; // [esp+840h] [ebp-12F0h]
  AdvXMLParser::Element *v551; // [esp+844h] [ebp-12ECh]
  int v552; // [esp+848h] [ebp-12E8h] BYREF
  int v553; // [esp+84Ch] [ebp-12E4h]
  std::string *v554; // [esp+850h] [ebp-12E0h]
  AdvXMLParser::Element *v555; // [esp+854h] [ebp-12DCh]
  AdvXMLParser::Element *v556; // [esp+858h] [ebp-12D8h]
  AdvXMLParser::Element *v557; // [esp+85Ch] [ebp-12D4h]
  int v558; // [esp+860h] [ebp-12D0h] BYREF
  int v559; // [esp+864h] [ebp-12CCh] BYREF
  std::string *v560; // [esp+868h] [ebp-12C8h]
  AdvXMLParser::Element *v561; // [esp+86Ch] [ebp-12C4h]
  AdvXMLParser::Element *v562; // [esp+870h] [ebp-12C0h]
  AdvXMLParser::Element *v563; // [esp+874h] [ebp-12BCh]
  int v564; // [esp+878h] [ebp-12B8h] BYREF
  std::string *v565; // [esp+87Ch] [ebp-12B4h]
  AdvXMLParser::Element *v566; // [esp+880h] [ebp-12B0h]
  AdvXMLParser::Element *v567; // [esp+884h] [ebp-12ACh]
  AdvXMLParser::Element *v568; // [esp+888h] [ebp-12A8h]
  int v569; // [esp+88Ch] [ebp-12A4h] BYREF
  std::string *v570; // [esp+890h] [ebp-12A0h]
  AdvXMLParser::Element *v571; // [esp+894h] [ebp-129Ch]
  AdvXMLParser::Element *v572; // [esp+898h] [ebp-1298h]
  AdvXMLParser::Element *v573; // [esp+89Ch] [ebp-1294h]
  int v574; // [esp+8A0h] [ebp-1290h] BYREF
  std::string *v575; // [esp+8A4h] [ebp-128Ch]
  AdvXMLParser::Element *v576; // [esp+8A8h] [ebp-1288h]
  AdvXMLParser::Element *v577; // [esp+8ACh] [ebp-1284h]
  AdvXMLParser::Element *v578; // [esp+8B0h] [ebp-1280h]
  int v579; // [esp+8B4h] [ebp-127Ch] BYREF
  std::string *v580; // [esp+8B8h] [ebp-1278h]
  AdvXMLParser::Element *v581; // [esp+8BCh] [ebp-1274h]
  AdvXMLParser::Element *v582; // [esp+8C0h] [ebp-1270h]
  AdvXMLParser::Element *v583; // [esp+8C4h] [ebp-126Ch]
  int v584; // [esp+8C8h] [ebp-1268h] BYREF
  std::string *v585; // [esp+8CCh] [ebp-1264h]
  AdvXMLParser::Element *v586; // [esp+8D0h] [ebp-1260h]
  AdvXMLParser::Element *v587; // [esp+8D4h] [ebp-125Ch]
  AdvXMLParser::Element *v588; // [esp+8D8h] [ebp-1258h]
  std::string *v589; // [esp+8DCh] [ebp-1254h]
  const struct AdvXMLParser::Element *v590; // [esp+8E0h] [ebp-1250h]
  AdvXMLParser::Element *v591; // [esp+8E4h] [ebp-124Ch]
  std::string *v592; // [esp+8E8h] [ebp-1248h]
  const struct AdvXMLParser::Element *v593; // [esp+8ECh] [ebp-1244h]
  AdvXMLParser::Element *v594; // [esp+8F0h] [ebp-1240h]
  std::string *v595; // [esp+8F4h] [ebp-123Ch]
  const struct AdvXMLParser::Element *v596; // [esp+8F8h] [ebp-1238h]
  AdvXMLParser::Element *v597; // [esp+8FCh] [ebp-1234h]
  std::string *v598; // [esp+900h] [ebp-1230h]
  AdvXMLParser::Element *v599; // [esp+904h] [ebp-122Ch]
  AdvXMLParser::Element *v600; // [esp+908h] [ebp-1228h]
  std::string *v601; // [esp+90Ch] [ebp-1224h]
  AdvXMLParser::Element *v602; // [esp+910h] [ebp-1220h]
  AdvXMLParser::Element *v603; // [esp+914h] [ebp-121Ch]
  std::string *v604; // [esp+918h] [ebp-1218h]
  AdvXMLParser::Element *v605; // [esp+91Ch] [ebp-1214h]
  AdvXMLParser::Element *v606; // [esp+920h] [ebp-1210h]
  int v607; // [esp+924h] [ebp-120Ch]
  int v608; // [esp+928h] [ebp-1208h]
  CConfigManager *Instance; // [esp+92Ch] [ebp-1204h]
  int v610; // [esp+930h] [ebp-1200h]
  const struct AdvXMLParser::Attribute *v611; // [esp+934h] [ebp-11FCh]
  AdvXMLParser::Element *v612; // [esp+938h] [ebp-11F8h]
  _DWORD *v613; // [esp+93Ch] [ebp-11F4h]
  _DWORD *v614; // [esp+940h] [ebp-11F0h]
  void *v615; // [esp+944h] [ebp-11ECh]
  _DWORD *v616; // [esp+948h] [ebp-11E8h]
  _DWORD *v617; // [esp+94Ch] [ebp-11E4h]
  int v618; // [esp+950h] [ebp-11E0h]
  int ValueOfDefine; // [esp+954h] [ebp-11DCh]
  struct CDefineTranslator *v620; // [esp+958h] [ebp-11D8h]
  const struct AdvXMLParser::Attribute *v621; // [esp+95Ch] [ebp-11D4h]
  AdvXMLParser::Element *v622; // [esp+960h] [ebp-11D0h]
  std::string *v623; // [esp+964h] [ebp-11CCh]
  int Name; // [esp+968h] [ebp-11C8h]
  int v625; // [esp+96Ch] [ebp-11C4h]
  _DWORD *v626; // [esp+970h] [ebp-11C0h]
  _DWORD *v627; // [esp+974h] [ebp-11BCh]
  _DWORD *v628; // [esp+978h] [ebp-11B8h]
  _DWORD *v629; // [esp+97Ch] [ebp-11B4h]
  struct CDefineTranslator *v630; // [esp+980h] [ebp-11B0h]
  void *Root; // [esp+984h] [ebp-11ACh]
  int v632; // [esp+988h] [ebp-11A8h]
  _DWORD v633[5]; // [esp+98Ch] [ebp-11A4h] BYREF
  _BYTE v634[4]; // [esp+9A0h] [ebp-1190h] BYREF
  AdvXMLParser::Element *v635; // [esp+9A4h] [ebp-118Ch]
  AdvXMLParser::Element *v636; // [esp+9A8h] [ebp-1188h]
  CConfigManager *v637; // [esp+9ACh] [ebp-1184h]
  AdvXMLParser::Element *v638; // [esp+9B0h] [ebp-1180h]
  AdvXMLParser::Element *v639; // [esp+9B4h] [ebp-117Ch]
  AdvXMLParser::Element *v640; // [esp+9B8h] [ebp-1178h]
  AdvXMLParser::Element *v641; // [esp+9BCh] [ebp-1174h]
  AdvXMLParser::Element *v642; // [esp+9C0h] [ebp-1170h]
  CConfigManager *v643; // [esp+9C4h] [ebp-116Ch]
  AdvXMLParser::Element *v644; // [esp+9C8h] [ebp-1168h]
  AdvXMLParser::Element *v645; // [esp+9CCh] [ebp-1164h]
  AdvXMLParser::Element *v646; // [esp+9D0h] [ebp-1160h]
  CConfigManager *v647; // [esp+9D4h] [ebp-115Ch]
  AdvXMLParser::Element *v648; // [esp+9D8h] [ebp-1158h]
  AdvXMLParser::Element *v649; // [esp+9DCh] [ebp-1154h]
  AdvXMLParser::Element *v650; // [esp+9E0h] [ebp-1150h]
  AdvXMLParser::Element *v651; // [esp+9E4h] [ebp-114Ch]
  CConfigManager *v652; // [esp+9E8h] [ebp-1148h]
  AdvXMLParser::Element *v653; // [esp+9ECh] [ebp-1144h]
  struct CDefineTranslator *v654; // [esp+9F0h] [ebp-1140h]
  const struct AdvXMLParser::Attribute *v655; // [esp+9F4h] [ebp-113Ch]
  const struct AdvXMLParser::Attribute *v656; // [esp+9F8h] [ebp-1138h]
  void *v657; // [esp+9FCh] [ebp-1134h]
  _BYTE v658[4]; // [esp+A00h] [ebp-1130h] BYREF
  unsigned int v660; // [esp+A08h] [ebp-1128h]
  const struct AdvXMLParser::Element *v661; // [esp+A0Ch] [ebp-1124h]
  const struct AdvXMLParser::Element *v662; // [esp+A10h] [ebp-1120h]
  AdvXMLParser::Element *v663; // [esp+A14h] [ebp-111Ch]
  AdvXMLParser::Element *v664; // [esp+A18h] [ebp-1118h]
  CConfigManager *v665; // [esp+A1Ch] [ebp-1114h]
  AdvXMLParser::Element *v666; // [esp+A20h] [ebp-1110h]
  AdvXMLParser::Element *v667; // [esp+A24h] [ebp-110Ch]
  AdvXMLParser::Element *v668; // [esp+A28h] [ebp-1108h]
  AdvXMLParser::Element *v669; // [esp+A2Ch] [ebp-1104h]
  char *v670; // [esp+A30h] [ebp-1100h]
  CConfigManager *v671; // [esp+A34h] [ebp-10FCh]
  AdvXMLParser::Element *v672; // [esp+A38h] [ebp-10F8h]
  AdvXMLParser::Element *v673; // [esp+A3Ch] [ebp-10F4h]
  CConfigManager *v674; // [esp+A40h] [ebp-10F0h]
  AdvXMLParser::Element *v675; // [esp+A44h] [ebp-10ECh]
  int v676; // [esp+A48h] [ebp-10E8h]
  int v677; // [esp+A4Ch] [ebp-10E4h]
  AdvXMLParser::Element *v678; // [esp+A50h] [ebp-10E0h]
  AdvXMLParser::Element *v679; // [esp+A54h] [ebp-10DCh]
  AdvXMLParser::Element *v680; // [esp+A58h] [ebp-10D8h]
  AdvXMLParser::Element *v681; // [esp+A5Ch] [ebp-10D4h]
  AdvXMLParser::Element *v682; // [esp+A60h] [ebp-10D0h]
  AdvXMLParser::Element *v683; // [esp+A64h] [ebp-10CCh]
  AdvXMLParser::Element *v684; // [esp+A68h] [ebp-10C8h]
  CConfigManager *v685; // [esp+A6Ch] [ebp-10C4h]
  AdvXMLParser::Element *v686; // [esp+A70h] [ebp-10C0h]
  CConfigManager *v687; // [esp+A74h] [ebp-10BCh]
  AdvXMLParser::Element *v688; // [esp+A78h] [ebp-10B8h]
  AdvXMLParser::Element *v689; // [esp+A7Ch] [ebp-10B4h]
  AdvXMLParser::Element *v690; // [esp+A80h] [ebp-10B0h]
  AdvXMLParser::Element *v691; // [esp+A84h] [ebp-10ACh]
  AdvXMLParser::Element *v692; // [esp+A88h] [ebp-10A8h]
  int m_uWarriorNumber; // [esp+A8Ch] [ebp-10A4h]
  BOOL v694; // [esp+A90h] [ebp-10A0h]
  AdvXMLParser::Element *v695; // [esp+A94h] [ebp-109Ch]
  const struct AdvXMLParser::Element *v696; // [esp+A98h] [ebp-1098h]
  const struct AdvXMLParser::Element *v697; // [esp+A9Ch] [ebp-1094h]
  AdvXMLParser::Element *v698; // [esp+AA0h] [ebp-1090h]
  AdvXMLParser::Element *v699; // [esp+AA4h] [ebp-108Ch]
  const struct AdvXMLParser::Element *v700; // [esp+AA8h] [ebp-1088h]
  const struct AdvXMLParser::Element *v701; // [esp+AACh] [ebp-1084h]
  AdvXMLParser::Element *v702; // [esp+AB0h] [ebp-1080h]
  AdvXMLParser::Element *v703; // [esp+AB4h] [ebp-107Ch]
  AdvXMLParser::Element *v704; // [esp+AB8h] [ebp-1078h]
  CConfigManager *v705; // [esp+ABCh] [ebp-1074h]
  AdvXMLParser::Element *v706; // [esp+AC0h] [ebp-1070h]
  AdvXMLParser::Element *v707; // [esp+AC4h] [ebp-106Ch]
  AdvXMLParser::Element *v708; // [esp+AC8h] [ebp-1068h]
  const struct AdvXMLParser::Element *v709; // [esp+ACCh] [ebp-1064h]
  const struct AdvXMLParser::Element *v710; // [esp+AD0h] [ebp-1060h]
  const struct AdvXMLParser::Element *v711; // [esp+AD4h] [ebp-105Ch]
  const struct AdvXMLParser::Element *v712; // [esp+AD8h] [ebp-1058h]
  AdvXMLParser::Element *v713; // [esp+ADCh] [ebp-1054h]
  AdvXMLParser::Element *v714; // [esp+AE0h] [ebp-1050h]
  AdvXMLParser::Element *v715; // [esp+AE4h] [ebp-104Ch]
  AdvXMLParser::Element *v716; // [esp+AE8h] [ebp-1048h]
  AdvXMLParser::Element *v717; // [esp+AECh] [ebp-1044h]
  AdvXMLParser::Element *v718; // [esp+AF0h] [ebp-1040h]
  AdvXMLParser::Element *v719; // [esp+AF4h] [ebp-103Ch]
  AdvXMLParser::Element *v720; // [esp+AF8h] [ebp-1038h]
  AdvXMLParser::Element *v721; // [esp+AFCh] [ebp-1034h]
  AdvXMLParser::Element *v722; // [esp+B00h] [ebp-1030h]
  AdvXMLParser::Element *v723; // [esp+B04h] [ebp-102Ch]
  AdvXMLParser::Element *v724; // [esp+B08h] [ebp-1028h]
  int v725; // [esp+B0Ch] [ebp-1024h]
  int v726; // [esp+B10h] [ebp-1020h]
  AdvXMLParser::Element *v727; // [esp+B14h] [ebp-101Ch]
  AdvXMLParser::Element *v728; // [esp+B18h] [ebp-1018h]
  AdvXMLParser::Element *v729; // [esp+B1Ch] [ebp-1014h]
  AdvXMLParser::Element *v730; // [esp+B20h] [ebp-1010h]
  AdvXMLParser::Element *v731; // [esp+B24h] [ebp-100Ch]
  AdvXMLParser::Element *v732; // [esp+B28h] [ebp-1008h]
  const struct AdvXMLParser::Element *v733; // [esp+B2Ch] [ebp-1004h]
  const struct AdvXMLParser::Element *v734; // [esp+B30h] [ebp-1000h]
  const struct AdvXMLParser::Element *v735; // [esp+B34h] [ebp-FFCh]
  AdvXMLParser::Element *v736; // [esp+B38h] [ebp-FF8h]
  AdvXMLParser::Element *v737; // [esp+B3Ch] [ebp-FF4h]
  AdvXMLParser::Element *v738; // [esp+B40h] [ebp-FF0h]
  CConfigManager *v739; // [esp+B44h] [ebp-FECh]
  const struct AdvXMLParser::Attribute *v740; // [esp+B48h] [ebp-FE8h]
  const struct AdvXMLParser::Attribute *v741; // [esp+B4Ch] [ebp-FE4h]
  void *v742; // [esp+B50h] [ebp-FE0h]
  int v743; // [esp+B54h] [ebp-FDCh]
  int v744; // [esp+B58h] [ebp-FD8h]
  int v745; // [esp+B5Ch] [ebp-FD4h]
  _DWORD v746[4]; // [esp+B60h] [ebp-FD0h] BYREF
  int v747; // [esp+B70h] [ebp-FC0h]
  int v749; // [esp+B78h] [ebp-FB8h] BYREF
  unsigned int iMaxDistance; // [esp+B7Ch] [ebp-FB4h]
  unsigned int a2; // [esp+B80h] [ebp-FB0h]
  int ii; // [esp+B84h] [ebp-FACh]
  int iRace; // [esp+B88h] [ebp-FA8h]
  int j; // [esp+B8Ch] [ebp-FA4h]
  int i; // [esp+B90h] [ebp-FA0h]
  char *v757; // [esp+B98h] [ebp-F98h]
  int iProductionDelay; // [esp+B9Ch] [ebp-F94h]
  int v759; // [esp+BA0h] [ebp-F90h]
  char v765; // [esp+BA9h] [ebp-F87h] BYREF
  bool IsPort; // [esp+BACh] [ebp-F84h]
  bool IsShipyard; // [esp+BADh] [ebp-F83h]
  int k; // [esp+BB0h] [ebp-F80h]
  int iBuildingType; // [esp+BB4h] [ebp-F7Ch]
  int v774; // [esp+BB8h] [ebp-F78h]
  int n; // [esp+BBCh] [ebp-F74h]
  _DWORD v776[4]; // [esp+BC0h] [ebp-F70h] BYREF
  int m; // [esp+BD0h] [ebp-F60h]
  CBuildingInfoMgr::STriggerInfos *v778; // [esp+BD4h] [ebp-F5Ch]
  CBuildingInfoMgr::SBuildingInfos *v779; // [esp+BD8h] [ebp-F58h]
  _BYTE v780[28]; // [esp+102Ch] [ebp-B04h] BYREF
  _BYTE v781[28]; // [esp+1048h] [ebp-AE8h] BYREF
  _BYTE v782[28]; // [esp+1064h] [ebp-ACCh] BYREF
  _BYTE v783[28]; // [esp+1080h] [ebp-AB0h] BYREF
  _BYTE v784[28]; // [esp+109Ch] [ebp-A94h] BYREF
  _BYTE v785[28]; // [esp+10B8h] [ebp-A78h] BYREF
  _BYTE v786[28]; // [esp+10D4h] [ebp-A5Ch] BYREF
  _BYTE v787[28]; // [esp+10F0h] [ebp-A40h] BYREF
  _BYTE v788[28]; // [esp+110Ch] [ebp-A24h] BYREF
  _BYTE v789[28]; // [esp+1128h] [ebp-A08h] BYREF
  _BYTE v790[28]; // [esp+1144h] [ebp-9ECh] BYREF
  _BYTE v791[28]; // [esp+1160h] [ebp-9D0h] BYREF
  _BYTE v792[28]; // [esp+117Ch] [ebp-9B4h] BYREF
  _BYTE v793[28]; // [esp+1198h] [ebp-998h] BYREF
  _BYTE v794[28]; // [esp+11B4h] [ebp-97Ch] BYREF
  _BYTE v795[28]; // [esp+11D0h] [ebp-960h] BYREF
  _BYTE v796[28]; // [esp+11ECh] [ebp-944h] BYREF
  _BYTE v797[28]; // [esp+1208h] [ebp-928h] BYREF
  _BYTE v798[28]; // [esp+1224h] [ebp-90Ch] BYREF
  _BYTE v799[28]; // [esp+1240h] [ebp-8F0h] BYREF
  _BYTE v800[28]; // [esp+125Ch] [ebp-8D4h] BYREF
  _BYTE v801[28]; // [esp+1278h] [ebp-8B8h] BYREF
  _BYTE v802[28]; // [esp+1294h] [ebp-89Ch] BYREF
  _BYTE v803[28]; // [esp+12B0h] [ebp-880h] BYREF
  _BYTE v804[28]; // [esp+12CCh] [ebp-864h] BYREF
  _BYTE v805[28]; // [esp+12E8h] [ebp-848h] BYREF
  _BYTE v806[28]; // [esp+1304h] [ebp-82Ch] BYREF
  _BYTE v807[28]; // [esp+1320h] [ebp-810h] BYREF
  _BYTE v808[28]; // [esp+133Ch] [ebp-7F4h] BYREF
  _BYTE v809[28]; // [esp+1358h] [ebp-7D8h] BYREF
  _BYTE v810[28]; // [esp+1374h] [ebp-7BCh] BYREF
  _BYTE v811[28]; // [esp+1390h] [ebp-7A0h] BYREF
  _BYTE v812[28]; // [esp+13ACh] [ebp-784h] BYREF
  _BYTE v813[28]; // [esp+13C8h] [ebp-768h] BYREF
  _BYTE v814[28]; // [esp+13E4h] [ebp-74Ch] BYREF
  _BYTE v815[28]; // [esp+1400h] [ebp-730h] BYREF
  _BYTE v816[28]; // [esp+141Ch] [ebp-714h] BYREF
  _BYTE v817[28]; // [esp+1438h] [ebp-6F8h] BYREF
  _BYTE v818[28]; // [esp+1454h] [ebp-6DCh] BYREF
  _BYTE v819[28]; // [esp+1470h] [ebp-6C0h] BYREF
  _BYTE v820[28]; // [esp+148Ch] [ebp-6A4h] BYREF
  _BYTE v821[28]; // [esp+14A8h] [ebp-688h] BYREF
  _BYTE v822[28]; // [esp+14C4h] [ebp-66Ch] BYREF
  _BYTE v823[28]; // [esp+14E0h] [ebp-650h] BYREF
  _BYTE v824[28]; // [esp+14FCh] [ebp-634h] BYREF
  _BYTE v825[28]; // [esp+1518h] [ebp-618h] BYREF
  _BYTE v826[28]; // [esp+1534h] [ebp-5FCh] BYREF
  _BYTE v827[28]; // [esp+1550h] [ebp-5E0h] BYREF
  _BYTE v828[28]; // [esp+156Ch] [ebp-5C4h] BYREF
  _BYTE v829[28]; // [esp+1588h] [ebp-5A8h] BYREF
  _BYTE v830[28]; // [esp+15A4h] [ebp-58Ch] BYREF
  _BYTE v831[28]; // [esp+15C0h] [ebp-570h] BYREF
  _BYTE v832[28]; // [esp+15DCh] [ebp-554h] BYREF
  _BYTE v833[28]; // [esp+15F8h] [ebp-538h] BYREF
  _BYTE v834[28]; // [esp+1614h] [ebp-51Ch] BYREF
  _BYTE v835[28]; // [esp+1630h] [ebp-500h] BYREF
  _BYTE v836[28]; // [esp+164Ch] [ebp-4E4h] BYREF
  _BYTE v837[28]; // [esp+1668h] [ebp-4C8h] BYREF
  _BYTE v838[28]; // [esp+1684h] [ebp-4ACh] BYREF
  _BYTE v839[28]; // [esp+16A0h] [ebp-490h] BYREF
  _BYTE v840[28]; // [esp+16BCh] [ebp-474h] BYREF
  _BYTE v841[28]; // [esp+16D8h] [ebp-458h] BYREF
  _BYTE v842[28]; // [esp+16F4h] [ebp-43Ch] BYREF
  _BYTE v843[28]; // [esp+1710h] [ebp-420h] BYREF
  _BYTE v844[28]; // [esp+172Ch] [ebp-404h] BYREF
  _BYTE v845[28]; // [esp+1748h] [ebp-3E8h] BYREF
  _BYTE v846[28]; // [esp+1764h] [ebp-3CCh] BYREF
  _BYTE v847[28]; // [esp+1780h] [ebp-3B0h] BYREF
  _BYTE v848[28]; // [esp+179Ch] [ebp-394h] BYREF
  _BYTE v849[28]; // [esp+17B8h] [ebp-378h] BYREF
  _BYTE v850[28]; // [esp+17D4h] [ebp-35Ch] BYREF
  _BYTE v851[28]; // [esp+17F0h] [ebp-340h] BYREF
  _BYTE v852[28]; // [esp+180Ch] [ebp-324h] BYREF
  _BYTE v853[28]; // [esp+1828h] [ebp-308h] BYREF
  _BYTE v854[28]; // [esp+1844h] [ebp-2ECh] BYREF
  _BYTE v855[28]; // [esp+1860h] [ebp-2D0h] BYREF
  _BYTE v856[28]; // [esp+187Ch] [ebp-2B4h] BYREF
  _BYTE v857[28]; // [esp+1898h] [ebp-298h] BYREF
  _BYTE v858[28]; // [esp+18B4h] [ebp-27Ch] BYREF
  _BYTE v859[28]; // [esp+18D0h] [ebp-260h] BYREF
  _BYTE v860[28]; // [esp+18ECh] [ebp-244h] BYREF
  _BYTE v861[28]; // [esp+1908h] [ebp-228h] BYREF
  struct std::string v862; // [esp+1924h] [ebp-20Ch] BYREF
  std::string v863; // [esp+1940h] [ebp-1F0h] BYREF
  std::string v864; // [esp+195Ch] [ebp-1D4h] BYREF
  std::string v865; // [esp+1978h] [ebp-1B8h] BYREF
  std::string v866; // [esp+1994h] [ebp-19Ch] BYREF
  std::string v867; // [esp+19B0h] [ebp-180h] BYREF
  std::string v868; // [esp+19CCh] [ebp-164h] BYREF
  std::string v869; // [esp+19E8h] [ebp-148h] BYREF
  std::string v870; // [esp+1A04h] [ebp-12Ch] BYREF
  std::string v871; // [esp+1A20h] [ebp-110h] BYREF
  std::string v872; // [esp+1A3Ch] [ebp-F4h] BYREF
  std::string v873; // [esp+1A58h] [ebp-D8h] BYREF
  std::string v874; // [esp+1A74h] [ebp-BCh] BYREF
  struct std::string v875; // [esp+1A90h] [ebp-A0h] BYREF
  std::string v876; // [esp+1AACh] [ebp-84h] BYREF
  std::string v877; // [esp+1AC8h] [ebp-68h] BYREF
  std::string v878; // [esp+1AE4h] [ebp-4Ch] BYREF
  std::string v879; // [esp+1B00h] [ebp-30h] BYREF
  int *v880; // [esp+1B20h] [ebp-10h]
  int exceptionBlock; // [esp+1B2Ch] [ebp-4h]

  v880 = &v155;
  v749 = 0;
  v757 = (char *)AdvXMLParser::Parser::OpenXMLFile(aGamedataBuildi, &v749);
  if ( v757 )
  {
    exceptionBlock = 0;
    v178[25] = AdvXMLParser::Parser::Parser(v156);
    LOBYTE(exceptionBlock) = 1;
    v632 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v156, v757, v749);
    std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v632);
    LOBYTE(exceptionBlock) = 2;
    v1 = std::auto_ptr<AdvXMLParser::Document>::operator->(v155);
    Root = (void *)AdvXMLParser::Document::GetRoot(v1);
    v742 = Root;
    v630 = (struct CDefineTranslator *)CDefineTranslator::Instance();
    v620 = v630;
    v629 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v742, v171);
    v628 = v629;
    LOBYTE(exceptionBlock) = 3;
    v178[24] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v284, v629);
    LOBYTE(exceptionBlock) = 5;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v171);
    v627 = AdvXMLParser::NodeContainer::End(v742, v170);
    v626 = v627;
    LOBYTE(exceptionBlock) = 6;
    v178[21] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v176, v627);
    LOBYTE(exceptionBlock) = 8;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v170);
    while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v284, (int)v176) )
    {
      v625 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v284);
      v745 = v625;
      Name = AdvXMLParser::Node::GetName(v625);
      if ( std::operator==<char>(Name, "BuildingXMLVersion") )
      {
        v623 = (std::string *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v745 + 8))(v745, v811);
        v2 = std::string::c_str(v623);
        v3 = j__atoi(v2);
        this->m_iXmlVersion = v3;
        std::string::~string(v811);
      }
      else
      {
        v622 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v284);
        v621 = AdvXMLParser::Element::operator[](v622, "id");
        v741 = v621;
        v178[23] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, std::string *))(*(_DWORD *)v621 + 8))(
                     v621,
                     &v877);
        LOBYTE(exceptionBlock) = 9;
        if ( std::string::length(&v877) )
        {
          ValueOfDefine = CDefineTranslator::GetValueOfDefine(v620, &v877);
          iRace = ValueOfDefine;
          v618 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v284);
          v617 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v618, v160);
          v616 = v617;
          LOBYTE(exceptionBlock) = 10;
          v178[22] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(
                       v776,
                       v617);
          LOBYTE(exceptionBlock) = 12;
          AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v160);
          v615 = (void *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v284);
          v614 = AdvXMLParser::NodeContainer::End(v615, v169);
          v613 = v614;
          LOBYTE(exceptionBlock) = 13;
          v178[20] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(
                       v177,
                       v614);
          LOBYTE(exceptionBlock) = 15;
          AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v169);
          while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v776, (int)v177) )
          {
            v612 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
            v611 = AdvXMLParser::Element::operator[](v612, "id");
            v740 = v611;
            v178[19] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, std::string *))(*(_DWORD *)v611 + 8))(
                         v611,
                         &v879);
            LOBYTE(exceptionBlock) = 16;
            if ( !std::string::length(&v879) )
            {
              v610 = BBSupportDbgReport(
                       2,
                       "MapObjects\\Building\\BuildingInfoMgr.cpp",
                       609,
                       "strBuildingName.length() > 0");
              if ( v610 == 1 )
                __debugbreak();
            }
            if ( !std::string::length(&v879) )
              goto LABEL_16;
            Instance = CConfigManagerPtr::GetInstance();
            v739 = Instance;
            v4 = std::string::c_str(&v879);
            v608 = v739->GetDefineValue(v739, v4);
            iBuildingType = v608;
            if ( v608 <= 0 )
            {
              v607 = BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 618, "buildingIdx > 0");
              if ( v607 == 1 )
                __debugbreak();
            }
            if ( iBuildingType > 0 )
            {
              v779 = &CBuildingInfoMgr::m_vBuildingInfos[iRace][iBuildingType];
              v606 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v605 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v606, "iHotSpotX", 0);
              v738 = v605;
              v604 = v605->GetValue(v605);
              v5 = std::string::c_str(v604);
              v6 = j__atoi(v5);
              v779->m_iHotSpotX = v6;
              std::string::~string(v812);
              v603 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v602 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v603, "iHotSpotY", 0);
              v737 = v602;
              v601 = v602->GetValue(v602);
              v7 = std::string::c_str(v601);
              v8 = j__atoi(v7);
              v779->m_iHotSpotY = v8;
              std::string::~string(v813);
              v600 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v599 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v600, "stone", 0);
              v736 = v599;
              v598 = v599->GetValue(v599);
              v9 = std::string::c_str(v598);
              v10 = j__atoi(v9);
              v779->m_iStone = v10;
              std::string::~string(v814);
              v597 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v596 = AdvXMLParser::Element::operator()(v597, "boards", 0);
              v735 = v596;
              v595 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v596->GetValue)(
                                      v596,
                                      v815);
              v11 = std::string::c_str(v595);
              v12 = j__atoi(v11);
              v779->m_iBoards = v12;
              std::string::~string(v815);
              v594 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v593 = AdvXMLParser::Element::operator()(v594, "gold", 0);
              v734 = v593;
              v592 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v593->GetValue)(
                                      v593,
                                      v816);
              v13 = std::string::c_str(v592);
              v14 = j__atoi(v13);
              v779->m_iGold = v14;
              std::string::~string(v816);
              v591 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v590 = AdvXMLParser::Element::operator()(v591, "lines", 0);
              v733 = v590;
              v589 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v590->GetValue)(
                                      v590,
                                      v817);
              v15 = std::string::c_str(v589);
              v16 = j__atoi(v15);
              v779->m_iLines = v16;
              std::string::~string(v817);
              for ( i = 0; i < (unsigned __int8)v779->m_iLines; ++i )
              {
                v588 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v587 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v588, "buildingPosLines", 0);
                v586 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v587, "value", i);
                v732 = v586;
                v585 = v586->GetValue(v586);
                v17 = std::string::c_str(v585);
                v759 = j__atoi(v17);
                std::string::~string(v818);
                v584 = v759;
                std::vector<unsigned int>::push_back(&v779->m_vBuildingPosLines, (int)&v584);
                v583 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v582 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v583, "digPosLines", 0);
                v581 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v582, "value", i);
                v731 = v581;
                v580 = v581->GetValue(v581);
                v18 = std::string::c_str(v580);
                v759 = j__atoi(v18);
                std::string::~string(v819);
                v579 = v759;
                std::vector<unsigned int>::push_back(&v779->m_vDigPosLines, (int)&v579);
                v578 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v577 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v578, "blockPosLines", 0);
                v576 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v577, "value", i);
                v730 = v576;
                v575 = v576->GetValue(v576);
                v19 = std::string::c_str(v575);
                v759 = j__atoi(v19);
                std::string::~string(v820);
                v574 = v759;
                std::vector<unsigned int>::push_back(&v779->m_vBlockPosLines, (int)&v574);
                v573 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v572 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v573, "repealingPosLines", 0);
                v571 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v572, "value", i);
                v729 = v571;
                v570 = v571->GetValue(v571);
                v20 = std::string::c_str(v570);
                v759 = j__atoi(v20);
                std::string::~string(v821);
                v569 = v759;
                std::vector<unsigned int>::push_back(&v779->m_vRepealingPosLines, (int)&v569);
              }
              IsShipyard = CBuildingInfoMgr::BuildingTypeExIsShipyard((S4_BUILDING_ENUM)iBuildingType);
              if ( IsShipyard || (IsPort = CBuildingInfoMgr::BuildingTypeExIsPort((S4_BUILDING_ENUM)iBuildingType)) )
              {
                v779->m_bIsPort = 1;
                for ( j = 0; j < (unsigned __int8)v779->m_iLines; ++j )
                {
                  v568 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                  v567 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v568, "waterPosLines", 0);
                  v566 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v567, "value", j);
                  v728 = v566;
                  v565 = v566->GetValue(v566);
                  v21 = std::string::c_str(v565);
                  v726 = j__atoi(v21);
                  std::string::~string(v822);
                  v564 = v726;
                  std::vector<unsigned int>::push_back(&v779->m_vWaterPosLines, (int)&v564);
                  v563 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                  v562 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v563, "waterBlockPosLines", 0);
                  v561 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v562, "value", j);
                  v727 = v561;
                  v560 = v561->GetValue(v561);
                  v22 = std::string::c_str(v560);
                  v725 = j__atoi(v22);
                  std::string::~string(v823);
                  v559 = v725;
                  std::vector<unsigned int>::push_back(&v779->m_vWaterBlockPosLines, (int)&v559);
                  v558 = v725 | v726;
                  std::vector<unsigned int>::push_back(&v558);
                  v557 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                  v556 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v557, "waterFreePosLines", 0);
                  v555 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v556, "value", j);
                  v724 = v555;
                  v554 = v555->GetValue(v555);
                  v23 = std::string::c_str(v554);
                  v553 = j__atoi(v23);
                  std::string::~string(v824);
                  v552 = v553;
                  std::vector<unsigned int>::push_back(&v779->m_vWaterFreePosLines, (int)&v552);
                }
              }
              v551 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v550 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v551, "builderNumber", 0);
              v723 = v550;
              v549 = v550->GetValue(v550);
              v24 = std::string::c_str(v549);
              v25 = j__atoi(v24);
              v779->m_iBuilderNumber = v25;
              std::string::~string(v825);
              for ( k = 0; k < (char)v779->m_iBuilderNumber; ++k )
              {
                v548 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v547 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v548, "builderInfo", k);
                v546 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v547, "xOffset", 0);
                v722 = v546;
                v545 = v546->GetValue(v546);
                v26 = std::string::c_str(v545);
                v27 = j__atoi(v26);
                v779->m_vBuilder[k].m_iXOffset = v27;
                std::string::~string(v826);
                v544 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v543 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v544, "builderInfo", k);
                v542 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v543, "yOffset", 0);
                v721 = v542;
                v541 = v542->GetValue(v542);
                v28 = std::string::c_str(v541);
                v29 = j__atoi(v28);
                v779->m_vBuilder[k].m_iYOffset = v29;
                std::string::~string(v827);
                v540 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v539 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v540, "builderInfo", k);
                v538 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v539, "dir", 0);
                v720 = v538;
                v537 = v538->GetValue(v538);
                v30 = std::string::c_str(v537);
                v31 = j__atoi(v30);
                v779->m_vBuilder[k].m_iDirection = v31;
                std::string::~string(v828);
              }
              v536 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v535 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v536, "flag", 0);
              v534 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v535, "xOffset", 0);
              v719 = v534;
              v533 = v534->GetValue(v534);
              v32 = std::string::c_str(v533);
              v33 = j__atoi(v32);
              v779->m_iFlagX = v33;
              std::string::~string(v829);
              v532 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v531 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v532, "flag", 0);
              v530 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v531, "yOffset", 0);
              v718 = v530;
              v529 = v530->GetValue(v530);
              v34 = std::string::c_str(v529);
              v35 = j__atoi(v34);
              v779->m_iFlagY = v35;
              std::string::~string(v830);
              v528 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v527 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v528, "door", 0);
              v526 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v527, "xOffset", 0);
              v717 = v526;
              v525 = v526->GetValue(v526);
              v36 = std::string::c_str(v525);
              v37 = j__atoi(v36);
              v779->m_iDoorXOffset = v37;
              std::string::~string(v831);
              v524 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v523 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v524, "door", 0);
              v522 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v523, "yOffset", 0);
              v716 = v522;
              v521 = v522->GetValue(v522);
              v38 = std::string::c_str(v521);
              v39 = j__atoi(v38);
              v779->m_iDoorYOffset = v39;
              std::string::~string(v832);
              v520 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v519 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v520, "workingpos", 0);
              v518 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v519, "xOffset", 0);
              v715 = v518;
              v517 = v518->GetValue(v518);
              v40 = std::string::c_str(v517);
              v41 = j__atoi(v40);
              v779->m_iWorkPosXOffset = v41;
              std::string::~string(v833);
              v516 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v515 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v516, "workingpos", 0);
              v514 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v515, "yOffset", 0);
              v714 = v514;
              v513 = v514->GetValue(v514);
              v42 = std::string::c_str(v513);
              v43 = j__atoi(v42);
              v779->m_iWorkPosYOffset = v43;
              std::string::~string(v834);
              v512 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v511 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v512, "bitBoundingRect", 0);
              v510 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v511, "minX", 0);
              v713 = v510;
              v509 = v510->GetValue(v510);
              v44 = std::string::c_str(v509);
              v45 = j__atoi(v44);
              v779->m_iBBRMinX = v45;
              std::string::~string(v835);
              v508 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v507 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v508, "bitBoundingRect", 0);
              v506 = AdvXMLParser::Element::operator()(v507, "maxX", 0);
              v712 = v506;
              v505 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v506->GetValue)(
                                      v506,
                                      v836);
              v46 = std::string::c_str(v505);
              v47 = j__atoi(v46);
              v779->m_iBBRMaY = v47;
              std::string::~string(v836);
              v504 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v503 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v504, "bitBoundingRect", 0);
              v502 = AdvXMLParser::Element::operator()(v503, "minY", 0);
              v711 = v502;
              v501 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v502->GetValue)(
                                      v502,
                                      v837);
              v48 = std::string::c_str(v501);
              v49 = j__atoi(v48);
              v779->m_iBBRMinY = v49;
              std::string::~string(v837);
              v500 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v499 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v500, "bitBoundingRect", 0);
              v182 = AdvXMLParser::Element::operator()(v499, "maxY", 0);
              v710 = v182;
              v183 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v182->GetValue)(
                                      v182,
                                      v838);
              v50 = std::string::c_str(v183);
              v51 = j__atoi(v50);
              v779->m_iBBRMaxY = v51;
              std::string::~string(v838);
              v184 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v185 = AdvXMLParser::Element::operator()(v184, "pileNumber", 0);
              v709 = v185;
              v186 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v185->GetValue)(
                                      v185,
                                      v839);
              v52 = std::string::c_str(v186);
              v53 = j__atoi(v52);
              v779->m_iPileNumber = v53;
              std::string::~string(v839);
              for ( m = 0; m < v779->m_iPileNumber; ++m )
              {
                v187 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v188 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v187, "pile", m);
                v189 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v188, "xOffset", 0);
                v708 = v189;
                v190 = v189->GetValue(v189);
                v54 = std::string::c_str(v190);
                v55 = j__atoi(v54);
                v779->m_vPileSpots[m].m_uXOffset = v55;
                std::string::~string(v840);
                v191 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v192 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v191, "pile", m);
                v193 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v192, "yOffset", 0);
                v707 = v193;
                v194 = v193->GetValue(v193);
                v56 = std::string::c_str(v194);
                v57 = j__atoi(v56);
                v779->m_vPileSpots[m].m_uYOffset = v57;
                std::string::~string(v841);
                v195 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v196 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v195, "pile", m);
                v197 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v196, "good", 0);
                v706 = v197;
                v198 = CConfigManagerPtr::GetInstance();
                v705 = v198;
                v199 = v706->GetValue(v706);
                v200 = v199;
                LOBYTE(exceptionBlock) = 17;
                v58 = std::string::c_str(v199);
                v201 = v705->GetDefineValue(v705, v58);
                v779->m_vPileSpots[m].m_iGood = v201;
                LOBYTE(exceptionBlock) = 16;
                std::string::~string(v842);
                v202 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v203 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v202, "pile", m);
                v204 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v203, "type", 0);
                v704 = v204;
                v205 = v204->GetValue(v204);
                v59 = std::string::c_str(v205);
                v60 = j__atoi(v59);
                v779->m_vPileSpots[m].m_iType = v60;
                std::string::~string(v843);
                v206 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v207 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v206, "pile", m);
                v208 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v207, "patch", 0);
                v703 = v208;
                v209 = v208->GetValue(v208);
                v61 = std::string::c_str(v209);
                v62 = j__atoi(v61);
                v779->m_vPileSpots[m].m_iPatch = v62;
                std::string::~string(v845);
                v210 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v211 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v210, "pile", m);
                v212 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v211, "appearance", 0);
                v702 = v212;
                v213 = v212->GetValue(v212);
                v63 = std::string::c_str(v213);
                v64 = j__atoi(v63);
                v779->m_vPileSpots[m].m_iAppearance = v64;
                std::string::~string(v810);
                v214 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v215 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v214, "pile", m);
                v216 = AdvXMLParser::Element::operator()(v215, "xPixelOffset", 0);
                v701 = v216;
                v217 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v216->GetValue)(
                                        v216,
                                        v846);
                v65 = std::string::c_str(v217);
                v66 = j__atoi(v65);
                v779->m_vPileSpots[m].m_iXPixelOffset = v66;
                std::string::~string(v846);
                v218 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v219 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v218, "pile", m);
                v220 = AdvXMLParser::Element::operator()(v219, "yPixelOffset", 0);
                v700 = v220;
                v221 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v220->GetValue)(
                                        v220,
                                        v847);
                v67 = std::string::c_str(v221);
                v68 = j__atoi(v67);
                v779->m_vPileSpots[m].m_iYPixelOffset = v68;
                std::string::~string(v847);
              }
              v222 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v223 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v222, "settlerNumber", 0);
              v699 = v223;
              v224 = v223->GetValue(v223);
              v69 = std::string::c_str(v224);
              v70 = j__atoi(v69);
              v779->m_uWarriorNumber = v70;
              std::string::~string(v848);
              if ( v779->m_uWarriorNumber >= 21u )
              {
                v225 = BBSupportDbgReport(
                         2,
                         "MapObjects\\Building\\BuildingInfoMgr.cpp",
                         738,
                         "bI.m_uWarriorNumber < MAX_NUMBER_OF_BUILDING_SETTLERS");
                if ( v225 == 1 )
                  __debugbreak();
              }
              for ( n = 0; n < v779->m_uWarriorNumber; ++n )
              {
                v226 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v227 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v226, "settler", n);
                v228 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v227, "xOffset", 0);
                v698 = v228;
                v229 = v228->GetValue(v228);
                v71 = std::string::c_str(v229);
                v72 = j__atoi(v71);
                v779->m_vSettlerSpots[n].m_iXOffset = v72;
                std::string::~string(v849);
                v230 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v231 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v230, "settler", n);
                v232 = AdvXMLParser::Element::operator()(v231, "yOffset", 0);
                v697 = v232;
                v233 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v232->GetValue)(
                                        v232,
                                        v850);
                v73 = std::string::c_str(v233);
                v74 = j__atoi(v73);
                v779->m_vSettlerSpots[n].m_iYOffset = v74;
                std::string::~string(v850);
                v234 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v235 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v234, "settler", n);
                v236 = AdvXMLParser::Element::operator()(v235, "direction", 0);
                v696 = v236;
                v237 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v236->GetValue)(
                                        v236,
                                        v851);
                v75 = std::string::c_str(v237);
                v76 = j__atoi(v75);
                v779->m_vSettlerSpots[n].m_iDirection = v76;
                std::string::~string(v851);
                v178[18] = std::string::string(&v864, "true");
                LOBYTE(exceptionBlock) = 18;
                v238 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
                v239 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v238, "settler", n);
                v240 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v239, "top", 0);
                v695 = v240;
                v241 = v240->GetValue(v240);
                v694 = std::string::compare(v241) == 0;
                v779->m_vSettlerSpots[n].m_bTop = v694;
                std::string::~string(v852);
                LOBYTE(exceptionBlock) = 16;
                std::string::~string(&v864);
              }
              m_uWarriorNumber = v779->m_uWarriorNumber;
              v779->m_uSwordsmanNumber = 0;
              v779->m_uBowmanNumber = 0;
              v779->m_uU0 = -1;
              if ( m_uWarriorNumber > 0 )
              {
                for ( ii = 0; ii < m_uWarriorNumber; ++ii )
                {
                  if ( v779->m_vSettlerSpots[ii].m_bTop )
                  {
                    ++v779->m_uBowmanNumber;
                    if ( (v779->m_uU0 & 0x80u) != 0 )
                      v779->m_uU0 = ii;
                  }
                  else
                  {
                    ++v779->m_uSwordsmanNumber;
                  }
                }
                if ( !v779->m_uBowmanNumber )
                {
                  v152 = iRace;
                  v77 = std::string::c_str(&v879);
                  v242 = BBSupportDbgReportF(
                           2,
                           "MapObjects\\Building\\BuildingInfoMgr.cpp",
                           783,
                           "Bowman number == 0 for building %i (%s) of race %i!",
                           iBuildingType,
                           v77,
                           v152);
                  if ( v242 == 1 )
                    __debugbreak();
                }
                if ( !v779->m_uSwordsmanNumber )
                {
                  v153 = iRace;
                  v78 = std::string::c_str(&v879);
                  v243 = BBSupportDbgReportF(
                           2,
                           "MapObjects\\Building\\BuildingInfoMgr.cpp",
                           784,
                           "Swordsman number == 0 for building %i (%s) of race %i!",
                           iBuildingType,
                           v78,
                           v153);
                  if ( v243 == 1 )
                    __debugbreak();
                }
              }
              v244 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v283 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v244, "patchSettlerSlot", 0);
              v692 = v283;
              v246 = v283->GetValue(v283);
              v79 = std::string::c_str(v246);
              v80 = j__atoi(v79);
              v779->m_iPatchSettlerSlot = v80;
              std::string::~string(v853);
              v247 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v248 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v247, "miniflag", 0);
              v249 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v248, "xOffset", 0);
              v691 = v249;
              v250 = v249->GetValue(v249);
              v81 = std::string::c_str(v250);
              v82 = j__atoi(v81);
              v779->m_iMiniFlagXOffset = v82;
              std::string::~string(v854);
              v251 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v252 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v251, "miniflag", 0);
              v253 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v252, "yOffset", 0);
              v690 = v253;
              v254 = v253->GetValue(v253);
              v83 = std::string::c_str(v254);
              v84 = j__atoi(v83);
              v779->m_iMiniFlagYOffset = v84;
              std::string::~string(v855);
              v255 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v256 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v255, "kind", 0);
              v689 = v256;
              v257 = v256->GetValue(v256);
              v258 = v257;
              LOBYTE(exceptionBlock) = 19;
              v85 = std::string::c_str(v257);
              v178[17] = std::string::string(&v865, v85);
              LOBYTE(exceptionBlock) = 20;
              v259 = (struct CDefineTranslator *)CDefineTranslator::Instance();
              v260 = CDefineTranslator::GetValueOfDefine(v259, &v865);
              v779->m_iBuildingKind = v260;
              LOBYTE(exceptionBlock) = 19;
              std::string::~string(&v865);
              LOBYTE(exceptionBlock) = 16;
              std::string::~string(v856);
              v261 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v262 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v261, "inhabitant", 0);
              v688 = v262;
              v263 = v262->GetValue(v262);
              v264 = v263;
              LOBYTE(exceptionBlock) = 21;
              v86 = std::string::c_str(v263);
              v178[16] = std::string::string(&v876, v86);
              LOBYTE(exceptionBlock) = 23;
              std::string::~string(v857);
              if ( std::operator==<char>((int)&v876, (char *)&byte_3778517) )
              {
                v779->m_iBuildingInhabitant = 0;
              }
              else
              {
                v265 = CConfigManagerPtr::GetInstance();
                v687 = v265;
                v87 = std::string::c_str(&v876);
                v266 = v687->GetDefineValue(v687, v87);
                v779->m_iBuildingInhabitant = v266;
              }
              v267 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v268 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v267, "tool", 0);
              v686 = v268;
              v269 = CConfigManagerPtr::GetInstance();
              v685 = v269;
              v270 = v686->GetValue(v686);
              v271 = v270;
              LOBYTE(exceptionBlock) = 24;
              v88 = std::string::c_str(v270);
              v272 = v685->GetDefineValue(v685, v88);
              v779->m_iTool = v272;
              LOBYTE(exceptionBlock) = 23;
              std::string::~string(v858);
              v273 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v275 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v273, "productiondelay", 0);
              v684 = v275;
              v276 = v275->GetValue(v275);
              v277 = v276;
              LOBYTE(exceptionBlock) = 25;
              v89 = std::string::c_str(v276);
              v178[15] = std::string::string(&v870, v89);
              LOBYTE(exceptionBlock) = 27;
              std::string::~string(v859);
              v90 = std::string::c_str(&v870);
              iProductionDelay = j__atoi(v90);
              if ( (unsigned int)iProductionDelay >= 0x100 )
              {
                v278 = BBSupportDbgReport(
                         2,
                         "MapObjects\\Building\\BuildingInfoMgr.cpp",
                         816,
                         "(iProductionDelay >= 0) && (iProductionDelay <= 255)");
                if ( v278 == 1 )
                  __debugbreak();
              }
              if ( iProductionDelay >= 0 )
              {
                if ( iProductionDelay > 255 )
                  iProductionDelay = 255;
              }
              else
              {
                iProductionDelay = 0;
              }
              v779->m_iProductionDelay = iProductionDelay;
              v279 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v280 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v279, "dummyValue", 0);
              v683 = v280;
              v281 = v280->GetValue(v280);
              v91 = std::string::c_str(v281);
              v92 = j__atoi(v91);
              v779->m_iDummyValue = v92;
              std::string::~string(v860);
              v282 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v286 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v282, "influenceRadius", 0);
              v633[4] = v286;
              v287 = v286->GetValue(v286);
              v93 = std::string::c_str(v287);
              v94 = j__atoi(v93);
              v779->m_iInfluenceRadius = v94;
              std::string::~string(v861);
              v309 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v274 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v309, "explorerRadius", 0);
              v682 = v274;
              v285 = v274->GetValue(v274);
              v95 = std::string::c_str(v285);
              v96 = j__atoi(v95);
              v779->m_iExplorerRadius = v96;
              std::string::~string(v780);
              v498 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v497 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v498, "workingAreaRadius", 0);
              v681 = v497;
              v496 = v497->GetValue(v497);
              v97 = std::string::c_str(v496);
              v98 = j__atoi(v97);
              v779->m_iWorkingAreaRadius = v98;
              std::string::~string(v781);
              v495 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v494 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v495, "searchType", 0);
              v680 = v494;
              v493 = v494->GetValue(v494);
              v492 = v493;
              LOBYTE(exceptionBlock) = 28;
              v99 = std::string::c_str(v493);
              v178[14] = std::string::string(&v866, v99);
              LOBYTE(exceptionBlock) = 29;
              v491 = (struct CDefineTranslator *)CDefineTranslator::Instance();
              v490 = CDefineTranslator::GetValueOfDefine(v491, &v866);
              v779->m_iSearchType = v490;
              LOBYTE(exceptionBlock) = 28;
              std::string::~string(&v866);
              LOBYTE(exceptionBlock) = 27;
              std::string::~string(v782);
              v489 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v488 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v489, "Hitpoints", 0);
              v679 = v488;
              v487 = v488->GetValue(v488);
              v100 = std::string::c_str(v487);
              v101 = j__atoi(v100);
              v779->m_iHealth = v101 / 2;
              std::string::~string(v783);
              v486 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v485 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v486, "Armor", 0);
              v678 = v485;
              v484 = v485->GetValue(v485);
              v102 = std::string::c_str(v484);
              v103 = j__atoi(v102);
              v779->m_iArmor = v103;
              std::string::~string(v784);
              if ( !v779->m_iHealth )
              {
                m_iStone = (char)v779->m_iStone;
                m_iBoards = (char)v779->m_iBoards;
                m_iGold = (char)v779->m_iGold;
                iTotalResources = m_iGold + m_iBoards + m_iStone;
                v677 = 8 * iTotalResources / 2;
                if ( v677 >= 250 )
                  v676 = 250;
                else
                  v676 = v677;
                v779->m_iHealth = v676;
              }
              v479 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v478 = AdvXMLParser::Element::operator()(v479, "animLists", 0);
              v477 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v478, v168);
              v476 = v477;
              LOBYTE(exceptionBlock) = 30;
              v178[13] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(
                           v179,
                           v477);
              LOBYTE(exceptionBlock) = 32;
              AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v168);
              v475 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v474 = (struct AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v475, "animLists", 0);
              v473 = AdvXMLParser::NodeContainer::End(v474, v167);
              v472 = v473;
              LOBYTE(exceptionBlock) = 33;
              v178[12] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(
                           v178,
                           v473);
              LOBYTE(exceptionBlock) = 35;
              AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v167);
              while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v179, (int)v178) )
              {
                v471 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v179);
                v675 = v471;
                v470 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v471->GetValue)(v471, v785);
                v469 = v470;
                LOBYTE(exceptionBlock) = 36;
                v104 = std::string::c_str(v470);
                v178[11] = std::string::string(&v867, v104);
                LOBYTE(exceptionBlock) = 38;
                std::string::~string(v785);
                v468 = CConfigManagerPtr::GetInstance();
                v674 = v468;
                v105 = std::string::c_str(&v867);
                v467 = v674->GetDefineValue(v674, v105);
                v466 = v467;
                v765 = v467;
                std::vector<unsigned char>::push_back(&v779->m_vAnimationList, (int)&v765);
                LOBYTE(exceptionBlock) = 35;
                std::string::~string(&v867);
                AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++((char *)v179);
              }
              v774 = 0;
              v465 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v464 = AdvXMLParser::Element::operator()(v465, "patches", 0);
              v463 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v464, v166);
              v462 = v463;
              LOBYTE(exceptionBlock) = 39;
              v178[31] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(
                           v633,
                           v463);
              LOBYTE(exceptionBlock) = 41;
              AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v166);
              v461 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v460 = (struct AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v461, "patches", 0);
              v459 = AdvXMLParser::NodeContainer::End(v460, v165);
              v458 = v459;
              LOBYTE(exceptionBlock) = 42;
              v178[9] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(
                          v172,
                          v459);
              LOBYTE(exceptionBlock) = 44;
              AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v165);
              while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v633, (int)v172) )
              {
                v457 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v633);
                v456 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v457, "job", 0);
                v673 = v456;
                v455 = v456->GetValue(v456);
                v454 = v455;
                LOBYTE(exceptionBlock) = 45;
                v106 = std::string::c_str(v455);
                v178[8] = std::string::string(&v878, v106);
                LOBYTE(exceptionBlock) = 47;
                std::string::~string(v786);
                if ( !std::string::length(&v878) )
                {
                  v453 = BBSupportDbgReport(
                           2,
                           "MapObjects\\Building\\BuildingInfoMgr.cpp",
                           864,
                           "patchName.length() > 0");
                  if ( v453 == 1 )
                    __debugbreak();
                }
                v452 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v633);
                v451 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v452, "job", 0);
                v672 = v451;
                v450 = CConfigManagerPtr::GetInstance();
                v671 = v450;
                v449 = v672->GetValue(v672);
                v448 = v449;
                LOBYTE(exceptionBlock) = 48;
                v107 = std::string::c_str(v449);
                jobDefineValue = v671->GetDefineValue(v671, v107);
                LOBYTE(exceptionBlock) = 47;
                std::string::~string(v787);
                if ( jobDefineValue < 0 )
                {
                  v670 = std::string::length(&v878) ? std::string::c_str(&v878) : (char *)&unk_3778527;
                  v154 = std::string::c_str(&v877);
                  v108 = std::string::c_str(&v879);
                  v446 = BBSupportDbgReportF(
                           2,
                           "MapObjects\\Building\\BuildingInfoMgr.cpp",
                           868,
                           "Patch job \"%s\" not valid for building %s for race %s!",
                           v670,
                           v108,
                           v154);
                  if ( v446 == 1 )
                    __debugbreak();
                }
                v779->m_vPatches[v774].m_iJob = jobDefineValue;
                v445 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v633);
                v444 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v445, "type", 0);
                v669 = v444;
                v443 = v444->GetValue(v444);
                v442 = v443;
                LOBYTE(exceptionBlock) = 49;
                v109 = std::string::c_str(v443);
                std::string::operator=(&v878, v109);
                LOBYTE(exceptionBlock) = 47;
                std::string::~string(v788);
                v110 = std::string::c_str(&v878);
                v178[7] = std::string::string(&v863, v110);
                LOBYTE(exceptionBlock) = 50;
                v441 = (struct CDefineTranslator *)CDefineTranslator::Instance();
                v440 = CDefineTranslator::GetValueOfDefine(v441, &v863);
                jobDefineValue = v440;
                LOBYTE(exceptionBlock) = 47;
                std::string::~string(&v863);
                v779->m_vPatches[v774].m_iType = jobDefineValue;
                v439 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v633);
                v438 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v439, "ticks", 0);
                v668 = v438;
                v437 = v438->GetValue(v438);
                v111 = std::string::c_str(v437);
                v112 = j__atoi(v111);
                v779->m_vPatches[v774].m_iTicks = v112;
                std::string::~string(v789);
                v436 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v633);
                v435 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v436, "slot", 0);
                v667 = v435;
                v434 = v435->GetValue(v435);
                v113 = std::string::c_str(v434);
                v114 = j__atoi(v113);
                v779->m_vPatches[v774].m_iSlot = v114;
                std::string::~string(v790);
                v433 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v633);
                v432 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v433, "sound", 0);
                v431 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v432, "def", 0);
                v666 = v431;
                v430 = CConfigManagerPtr::GetInstance();
                v665 = v430;
                v429 = v666->GetValue(v666);
                v428 = v429;
                LOBYTE(exceptionBlock) = 51;
                v115 = std::string::c_str(v429);
                v427 = v665->GetDefineValue(v665, v115);
                v744 = v427;
                LOBYTE(exceptionBlock) = 47;
                std::string::~string(v791);
                if ( v744 < 0 )
                  v744 = 0;
                v779->m_vPatches[v774].m_iSound = v744;
                v426 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v633);
                v425 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v426, "sound", 0);
                v424 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v425, "frame", 0);
                v664 = v424;
                v423 = v424->GetValue(v424);
                v116 = std::string::c_str(v423);
                v117 = j__atoi(v116);
                v779->m_vPatches[v774].m_iSoundFrame = v117;
                std::string::~string(v792);
                v422 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v633);
                v421 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v422, "sound", 0);
                v420 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v421, "random", 0);
                v663 = v420;
                v419 = v420->GetValue(v420);
                v118 = std::string::c_str(v419);
                v119 = j__atoi(v118);
                v779->m_vPatches[v774].m_iSoundRandomness = v119;
                std::string::~string(v793);
                if ( !v779->m_vPatches[v774].m_iSoundRandomness )
                  v779->m_vPatches[v774].m_iSoundRandomness = 100;
                ++v774;
                LOBYTE(exceptionBlock) = 44;
                std::string::~string(&v878);
                AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++((char *)v633);
              }
              v418 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v417 = AdvXMLParser::Element::operator()(v418, "triggers", 0);
              v416 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v417, v164);
              v415 = v416;
              LOBYTE(exceptionBlock) = 52;
              v178[6] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(
                          v180,
                          v416);
              LOBYTE(exceptionBlock) = 54;
              AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v164);
              v414 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v776);
              v413 = (struct AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v414, "triggers", 0);
              v412 = AdvXMLParser::NodeContainer::End(v413, v163);
              v411 = v412;
              LOBYTE(exceptionBlock) = 55;
              v178[5] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(
                          v173,
                          v412);
              LOBYTE(exceptionBlock) = 57;
              AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v163);
              while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v180, (int)v173) )
              {
                v410 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v180);
                v409 = AdvXMLParser::Element::operator()(v410, "slot", 0);
                v662 = v409;
                v408 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v409->GetValue)(
                                        v409,
                                        v794);
                v120 = std::string::c_str(v408);
                v401 = j__atoi(v120);
                std::string::~string(v794);
                v407 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v180);
                v406 = AdvXMLParser::Element::operator()(v407, "job", 0);
                v661 = v406;
                v405 = (std::string *)((int (__thiscall *)(const struct AdvXMLParser::Element *, _BYTE *))v406->GetValue)(
                                        v406,
                                        v795);
                v404 = v405;
                LOBYTE(exceptionBlock) = 58;
                v121 = std::string::c_str(v405);
                v178[4] = std::string::string(&v869, v121);
                LOBYTE(exceptionBlock) = 60;
                std::string::~string(v795);
                v122 = std::string::c_str(&v869);
                v178[38] = std::string::string(&v868, v122);
                LOBYTE(exceptionBlock) = 61;
                v403 = (struct CDefineTranslator *)CDefineTranslator::Instance();
                v402 = CDefineTranslator::GetValueOfDefine(v403, &v868);
                v400 = v402;
                LOBYTE(exceptionBlock) = 60;
                std::string::~string(&v868);
                v779->m_vTriggers[v401] = v400;
                LOBYTE(exceptionBlock) = 57;
                std::string::~string(&v869);
                AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++((char *)v180);
              }
              iMaxDistance = 0;
              v396 = -v779->m_iHotSpotX;
              v397 = -v779->m_iHotSpotY;
              m_iLines = (unsigned __int8)v779->m_iLines;
              for ( a2 = 0; (int)a2 < m_iLines; ++a2 )
              {
                v398 = (int *)std::vector<unsigned int>::operator[](&v779->m_vBuildingPosLines, a2);
                v747 = *v398;
                v395 = a2 + v397;
                v743 = v396;
                while ( v747 )
                {
                  if ( v747 < 0 )
                  {
                    v394 = Grid::DistanceInline(v743, v395);
                    v660 = v394;
                    if ( v394 > (int)iMaxDistance )
                      iMaxDistance = v660;
                  }
                  ++v743;
                  v747 *= 2;
                }
              }
              if ( iMaxDistance >= 0x40 )
              {
                v393 = BBSupportDbgReport(
                         2,
                         "MapObjects\\Building\\BuildingInfoMgr.cpp",
                         952,
                         "(iMaxDistance >= 0) && (iMaxDistance < 64)");
                if ( v393 == 1 )
                  __debugbreak();
              }
              v779->m_iMaxDistance = iMaxDistance;
              if ( !CBuildingInfoMgr::DbgCheckBuildingBits(this, iRace, iBuildingType) )
              {
                RaceName = CS4DefineNames::GetRaceName(iRace);
                v391 = BBSupportDbgReportF(
                         2,
                         "MapObjects\\Building\\BuildingInfoMgr.cpp",
                         956,
                         "Invalid building info for building %i (%s) of race %i (%s)!",
                         iBuildingType,
                         s_sBuildingDefines[iBuildingType].m_sName,
                         iRace,
                         RaceName);
                if ( v391 == 1 )
                  __debugbreak();
              }
              LOBYTE(exceptionBlock) = 54;
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v173);
              LOBYTE(exceptionBlock) = 44;
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v180);
              LOBYTE(exceptionBlock) = 41;
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v172);
              LOBYTE(exceptionBlock) = 35;
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v633);
              LOBYTE(exceptionBlock) = 32;
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v178);
              LOBYTE(exceptionBlock) = 27;
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v179);
              LOBYTE(exceptionBlock) = 23;
              std::string::~string(&v870);
              LOBYTE(exceptionBlock) = 16;
              std::string::~string(&v876);
              LOBYTE(exceptionBlock) = 15;
              std::string::~string(&v879);
            }
            else
            {
LABEL_16:
              LOBYTE(exceptionBlock) = 15;
              std::string::~string(&v879);
            }
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++((char *)v776);
          }
          LOBYTE(exceptionBlock) = 12;
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v177);
          LOBYTE(exceptionBlock) = 9;
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v776);
          LOBYTE(exceptionBlock) = 8;
          std::string::~string(&v877);
        }
        else
        {
          LOBYTE(exceptionBlock) = 8;
          std::string::~string(&v877);
        }
      }
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++((char *)v284);
    }
    LOBYTE(exceptionBlock) = 5;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v176);
    LOBYTE(exceptionBlock) = 2;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v284);
    LOBYTE(exceptionBlock) = 1;
    std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v658);
    LOBYTE(exceptionBlock) = 0;
    AdvXMLParser::Parser::~Parser(v156);
    exceptionBlock = -1;
    C = v757;
    operator delete[](v757);
    if ( CBuildingInfoMgr::m_vBuildingInfos[0][46].m_uSwordsmanNumber != 1
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           973,
           "m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[0][46].m_uBowmanNumber != 2
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           974,
           "m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[0][47].m_uSwordsmanNumber != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           976,
           "m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[0][47].m_uBowmanNumber != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           977,
           "m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[0][48].m_uSwordsmanNumber != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           979,
           "m_vBuildingInfos[RACE_ROMAN][BUILDING_CASTLE].m_uSwordsmanNumber == 4") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[0][48].m_uBowmanNumber != 5
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           980,
           "m_vBuildingInfos[RACE_ROMAN][BUILDING_CASTLE].m_uBowmanNumber == 5") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[1][46].m_uSwordsmanNumber != 1
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           982,
           "m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[1][46].m_uBowmanNumber != 2
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           983,
           "m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[1][47].m_uSwordsmanNumber != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           985,
           "m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[1][47].m_uBowmanNumber != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           986,
           "m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[1][48].m_uSwordsmanNumber != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           988,
           "m_vBuildingInfos[RACE_VIKING][BUILDING_CASTLE].m_uSwordsmanNumber == 4") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[1][48].m_uBowmanNumber != 5
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           989,
           "m_vBuildingInfos[RACE_VIKING][BUILDING_CASTLE].m_uBowmanNumber == 5") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[2][46].m_uSwordsmanNumber != 1
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           991,
           "m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[2][46].m_uBowmanNumber != 2
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           992,
           "m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[2][47].m_uSwordsmanNumber != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           994,
           "m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[2][47].m_uBowmanNumber != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           995,
           "m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[2][48].m_uSwordsmanNumber != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           997,
           "m_vBuildingInfos[RACE_MAYA][BUILDING_CASTLE].m_uSwordsmanNumber == 4") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[2][48].m_uBowmanNumber != 5
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           998,
           "m_vBuildingInfos[RACE_MAYA][BUILDING_CASTLE].m_uBowmanNumber == 5") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[4][46].m_uSwordsmanNumber != 1
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           1000,
           "m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[4][46].m_uBowmanNumber != 2
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           1001,
           "m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[4][47].m_uSwordsmanNumber != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           1003,
           "m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[4][47].m_uBowmanNumber != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           1004,
           "m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[4][48].m_uSwordsmanNumber != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           1006,
           "m_vBuildingInfos[RACE_TROJAN][BUILDING_CASTLE].m_uSwordsmanNumber == 4") == 1 )
    {
      __debugbreak();
    }
    if ( CBuildingInfoMgr::m_vBuildingInfos[4][48].m_uBowmanNumber != 5
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingInfoMgr.cpp",
           1007,
           "m_vBuildingInfos[RACE_TROJAN][BUILDING_CASTLE].m_uBowmanNumber == 5") == 1 )
    {
      __debugbreak();
    }
    memset(CBuildingInfoMgr::m_vTriggerInfos, 0, sizeof(CBuildingInfoMgr::m_vTriggerInfos));
    v749 = 0;
    v757 = (char *)AdvXMLParser::Parser::OpenXMLFile(aGamedataBuildi_0, &v749);
    if ( v757 )
    {
      exceptionBlock = 64;
      v178[37] = AdvXMLParser::Parser::Parser(v157);
      LOBYTE(exceptionBlock) = 65;
      v389 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v157, v757, v749);
      std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v389);
      LOBYTE(exceptionBlock) = 66;
      v123 = std::auto_ptr<AdvXMLParser::Document>::operator->(v155);
      v388 = (void *)AdvXMLParser::Document::GetRoot(v123);
      v657 = v388;
      v387 = (struct CDefineTranslator *)CDefineTranslator::Instance();
      v654 = v387;
      v178[36] = 0;
      v386 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v657, v162);
      v385 = v386;
      LOBYTE(exceptionBlock) = 67;
      v178[35] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v181, v386);
      LOBYTE(exceptionBlock) = 69;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v162);
      v384 = AdvXMLParser::NodeContainer::End(v657, v161);
      v383 = v384;
      LOBYTE(exceptionBlock) = 70;
      v178[34] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v174, v384);
      LOBYTE(exceptionBlock) = 72;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v161);
      while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v181, (int)v174) )
      {
        v382 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v181);
        v381 = AdvXMLParser::Element::operator[](v382, "id");
        v656 = v381;
        v178[33] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, struct std::string *))(*(_DWORD *)v381 + 8))(
                     v381,
                     &v862);
        LOBYTE(exceptionBlock) = 73;
        v380 = CDefineTranslator::GetValueOfDefine(v654, &v862);
        v369 = v380;
        v379 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v181);
        v378 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v379, v158);
        v377 = v378;
        LOBYTE(exceptionBlock) = 74;
        v178[32] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v746, v378);
        LOBYTE(exceptionBlock) = 76;
        AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v158);
        v376 = (void *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v181);
        v375 = AdvXMLParser::NodeContainer::End(v376, v159);
        v374 = v375;
        LOBYTE(exceptionBlock) = 77;
        v178[30] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v175, v375);
        LOBYTE(exceptionBlock) = 79;
        AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v159);
        while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v746, (int)v175) )
        {
          v373 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v372 = AdvXMLParser::Element::operator[](v373, "id");
          v655 = v372;
          v178[10] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, struct std::string *))(*(_DWORD *)v372 + 8))(
                       v372,
                       &v875);
          LOBYTE(exceptionBlock) = 80;
          v371 = CDefineTranslator::GetValueOfDefine(v654, &v875);
          v370 = v371;
          v778 = &CBuildingInfoMgr::m_vTriggerInfos[v369][v371];
          v368 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v367 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v368, "patch", 0);
          v366 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v367, "def", 0);
          v653 = v366;
          v365 = v366->GetValue(v366);
          v364 = v365;
          LOBYTE(exceptionBlock) = 81;
          v124 = std::string::c_str(v365);
          v178[29] = std::string::string(&v874, v124);
          LOBYTE(exceptionBlock) = 83;
          std::string::~string(v796);
          v363 = CConfigManagerPtr::GetInstance();
          v652 = v363;
          v125 = std::string::c_str(&v874);
          v362 = v652->GetDefineValue(v652, v125);
          v778->m_iPatchDefine = v362;
          v361 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v360 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v361, "patch", 0);
          v359 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v360, "slot", 0);
          v651 = v359;
          v358 = v359->GetValue(v359);
          v126 = std::string::c_str(v358);
          v127 = j__atoi(v126);
          v778->m_iSlot = v127;
          std::string::~string(v844);
          v357 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v356 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v357, "patch", 0);
          v355 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v356, "duration", 0);
          v650 = v355;
          v354 = v355->GetValue(v355);
          v128 = std::string::c_str(v354);
          v129 = j__atoi(v128);
          v778->m_iDuration = v129;
          std::string::~string(v797);
          v353 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v352 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v353, "type", 0);
          v649 = v352;
          v351 = v352->GetValue(v352);
          v350 = v351;
          LOBYTE(exceptionBlock) = 84;
          v130 = std::string::c_str(v351);
          v178[28] = std::string::string(&v873, v130);
          LOBYTE(exceptionBlock) = 86;
          std::string::~string(v798);
          v131 = std::string::c_str(&v873);
          v178[27] = std::string::string(&v871, v131);
          LOBYTE(exceptionBlock) = 87;
          v349 = (struct CDefineTranslator *)CDefineTranslator::Instance();
          v348 = CDefineTranslator::GetValueOfDefine(v349, &v871);
          v778->m_iType = v348;
          LOBYTE(exceptionBlock) = 86;
          std::string::~string(&v871);
          v347 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v346 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v347, "patch", 0);
          v345 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v346, "sound", 0);
          v344 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v345, "def", 0);
          v648 = v344;
          v343 = v344->GetValue(v344);
          v342 = v343;
          LOBYTE(exceptionBlock) = 88;
          v132 = std::string::c_str(v343);
          v178[26] = std::string::string(&v872, v132);
          LOBYTE(exceptionBlock) = 90;
          std::string::~string(v799);
          v341 = CConfigManagerPtr::GetInstance();
          v647 = v341;
          v133 = std::string::c_str(&v872);
          v340 = v647->GetDefineValue(v647, v133);
          v778->m_iPatchSoundId = v340;
          if ( v778->m_iPatchSoundId == -1 )
            v778->m_iPatchSoundId = 0;
          v339 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v338 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v339, "patch", 0);
          v337 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v338, "sound", 0);
          v336 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v337, "random", 0);
          v646 = v336;
          v335 = v336->GetValue(v336);
          v134 = std::string::c_str(v335);
          v135 = j__atoi(v134);
          v778->m_iPatchSoundRandomness = v135;
          std::string::~string(v800);
          if ( !v778->m_iPatchSoundRandomness )
            v778->m_iPatchSoundRandomness = 100;
          v334 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v333 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v334, "patch", 0);
          v332 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v333, "sound", 0);
          v331 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v332, "frame", 0);
          v645 = v331;
          v330 = v331->GetValue(v331);
          v136 = std::string::c_str(v330);
          v137 = j__atoi(v136);
          v778->m_iPatchSoundFrame = v137;
          std::string::~string(v801);
          v329 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v328 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v329, "effect", 0);
          v327 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v328, "def", 0);
          v644 = v327;
          v326 = CConfigManagerPtr::GetInstance();
          v643 = v326;
          v325 = v644->GetValue(v644);
          v324 = v325;
          LOBYTE(exceptionBlock) = 91;
          v138 = std::string::c_str(v325);
          v323 = v643->GetDefineValue(v643, v138);
          v778->m_iEffectId = v323;
          LOBYTE(exceptionBlock) = 90;
          std::string::~string(v802);
          v322 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v321 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v322, "effect", 0);
          v320 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v321, "x", 0);
          v642 = v320;
          v319 = v320->GetValue(v320);
          v139 = std::string::c_str(v319);
          v140 = j__atoi(v139);
          v778->m_iEffectX = v140;
          std::string::~string(v803);
          v318 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v317 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v318, "effect", 0);
          v316 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v317, "y", 0);
          v641 = v316;
          v315 = v316->GetValue(v316);
          v141 = std::string::c_str(v315);
          v142 = j__atoi(v141);
          v778->m_iEffectY = v142;
          std::string::~string(v804);
          v314 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v313 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v314, "effect", 0);
          v312 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v313, "smoke", 0);
          v640 = v312;
          v311 = v312->GetValue(v312);
          v143 = std::string::c_str(v311);
          v144 = j__atoi(v143);
          v778->m_bEffectSmoke = v144;
          std::string::~string(v805);
          v310 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v245 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v310, "effect", 0);
          v308 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v245, "duration", 0);
          v639 = v308;
          v307 = v308->GetValue(v308);
          v145 = std::string::c_str(v307);
          v146 = j__atoi(v145);
          v778->m_iEffectDuration = v146;
          std::string::~string(v806);
          v306 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v305 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v306, "effect", 0);
          v304 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v305, "sound", 0);
          v303 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v304, "def", 0);
          v638 = v303;
          v302 = CConfigManagerPtr::GetInstance();
          v637 = v302;
          v301 = v638->GetValue(v638);
          v300 = v301;
          LOBYTE(exceptionBlock) = 92;
          v147 = std::string::c_str(v301);
          v299 = v637->GetDefineValue(v637, v147);
          v778->m_iEffectSoundId = v299;
          LOBYTE(exceptionBlock) = 90;
          std::string::~string(v807);
          if ( v778->m_iEffectSoundId == -1 )
            v778->m_iEffectSoundId = 0;
          v298 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v297 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v298, "effect", 0);
          v296 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v297, "sound", 0);
          v295 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v296, "random", 0);
          v636 = v295;
          v294 = v295->GetValue(v295);
          v148 = std::string::c_str(v294);
          v149 = j__atoi(v148);
          v778->m_iEffectSoundRandomness = v149;
          std::string::~string(v808);
          if ( !v778->m_iPatchSoundRandomness )
            v778->m_iPatchSoundRandomness = 100;
          v293 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v746);
          v292 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v293, "effect", 0);
          v291 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v292, "sound", 0);
          v290 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v291, "frame", 0);
          v635 = v290;
          v289 = v290->GetValue(v290);
          v150 = std::string::c_str(v289);
          v151 = j__atoi(v150);
          v778->m_iPatchSoundFrame = v151;      // Whooops, looks wrong O.O
          std::string::~string(v809);
          LOBYTE(exceptionBlock) = 86;
          std::string::~string(&v872);
          LOBYTE(exceptionBlock) = 83;
          std::string::~string(&v873);
          LOBYTE(exceptionBlock) = 80;
          std::string::~string(&v874);
          LOBYTE(exceptionBlock) = 79;
          std::string::~string(&v875);
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++((char *)v746);
        }
        LOBYTE(exceptionBlock) = 76;
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v175);
        LOBYTE(exceptionBlock) = 73;
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v746);
        LOBYTE(exceptionBlock) = 72;
        std::string::~string(&v862);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++((char *)v181);
      }
      LOBYTE(exceptionBlock) = 69;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v174);
      LOBYTE(exceptionBlock) = 66;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v181);
      LOBYTE(exceptionBlock) = 65;
      std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v634);
      LOBYTE(exceptionBlock) = 64;
      AdvXMLParser::Parser::~Parser(v157);
      exceptionBlock = -1;
      v288 = v757;
      operator delete[](v757);
    }
  }
}


// address=[0x4033188]
// [Decompilation failed for static struct CBuildingInfoMgr::STriggerInfos (* CBuildingInfoMgr::m_vTriggerInfos)[47]]

// address=[0x4035294]
// [Decompilation failed for static bool CBuildingInfoMgr::m_bInit]

// address=[0x40352a0]
// [Decompilation failed for static struct CBuildingInfoMgr::SBuildingInfos (* CBuildingInfoMgr::m_vBuildingInfos)[83]]

#endif // Already implemented
