#if FALSE
#include "CSettlerMgr.h"

// Definitions for class CSettlerMgr

// address=[0x130e490]
// Decompiled from IEntity *__stdcall CSettlerMgr::operator[](int a1)
class CSettler &  CSettlerMgr::operator[](int a1) {
  
  IEntity *pEntity; // [esp+4h] [ebp-4h]

  pEntity = CMapObjectMgr::EntityPtr(a1);
  if ( !pEntity
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         299,
         "pEntity != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::ObjType(pEntity) != SETTLER_OBJ
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         300,
         "pEntity->ObjType() == SETTLER_OBJ") == 1 )
  {
    __debugbreak();
  }
  return pEntity;
}


// address=[0x130ecc0]
// Decompiled from int __thiscall CSettlerMgr::GetNumberOfSettlers(CSettlerMgr *this, int _iPlayerId, S4_SETTLER_ENUM _iSettlerType)
int  CSettlerMgr::GetNumberOfSettlers(int _iPlayerId, int _iSettlerType)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         371,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= SETTLER_NO_SETTLER || _iSettlerType >= SETTLER_MAX)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         372,
         "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return this->m_vPlayerSettlerNumber[_iPlayerId][_iSettlerType];
}


// address=[0x130edf0]
// Decompiled from CSettler *__thiscall CSettlerMgr::GetSettlerPtr(struct CSettlerMgr *this, int a1)
class CSettler *  CSettlerMgr::GetSettlerPtr(int a1) {
  
  CSettler *pEntity; // [esp+Ch] [ebp-4h]

  pEntity = (CSettler *)CMapObjectMgr::EntityPtr(a1);
  if ( pEntity && IEntity::ObjType(pEntity) == SETTLER_OBJ )
    return pEntity;
  else
    return 0;
}


// address=[0x1311cd0]
// Decompiled from int __thiscall CSettlerMgr::GetNumberOfOfferedSettlers(CSettlerMgr *this, int _iPlayerId, int _iSettlerType)
int  CSettlerMgr::GetNumberOfOfferedSettlers(int _iPlayerId, int _iSettlerType)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         385,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= 0 || _iSettlerType >= 67)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         386,
         "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return this->m_vPlayerSettlerOfferedNumber[_iPlayerId][_iSettlerType];
}


// address=[0x1439bb0]
// Decompiled from CSettlerMgr::SSettlerInfos *__cdecl CSettlerMgr::GetSettlerInfo(int _iRace, int _iType)
struct CSettlerMgr::SSettlerInfos const & __cdecl CSettlerMgr::GetSettlerInfo(int _iRace, int _iType) {
  
  return &CSettlerMgr::m_vSettlerInfos[_iRace][_iType];
}


// address=[0x1439ed0]
// Decompiled from int __cdecl CSettlerMgr::SettlerWarriorType(int a1)
int __cdecl CSettlerMgr::SettlerWarriorType(int a1) {
  
  if ( !CSettlerMgr::m_uSettlerWarriorTypes[SETTLER_SWORDSMAN_01]
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         347,
         "m_uSettlerWarriorTypes[SETTLER_SWORDSMAN_01] != 0") == 1 )
  {
    __debugbreak();
  }
  return CSettlerMgr::m_uSettlerWarriorTypes[a1];
}


// address=[0x1580220]
// Decompiled from CSettlerMgr *__thiscall CSettlerMgr::CSettlerMgr(CSettlerMgr *this)
 CSettlerMgr::CSettlerMgr(void) {
  
  CSettlerMgr::SDefaultInfo *i; // [esp+8h] [ebp-10h]

  MemoryAllocator::MemoryAllocator(&this->m_cAllocator, 0x68u, 0x20u, 0);
  this->m_uTotalSettlers = 0;
  this->m_bLoaded = 0;
  memset(CSettlerMgr::m_uSettlerWarriorTypes, 0, 0x46u);
  memset(CSettlerMgr::m_uSettlerWarriorLevels, 0, 0x46u);
  memset(CSettlerMgr::m_vSettlerInfos, 0, sizeof(CSettlerMgr::m_vSettlerInfos));
  for ( i = s_sDefaultSettlerInfos; i->m_uType; ++i )
  {
    if ( i->m_uType >= (unsigned int)SETTLER_MAX
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 219, "pInfo->m_uType < SETTLER_MAX") == 1 )
    {
      __debugbreak();
    }
    if ( i->m_uWarriorType >= 15u
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 220, "pInfo->m_uWarriorType < WARRIOR_TYPE_MAX") == 1 )
    {
      __debugbreak();
    }
    if ( CSettlerMgr::m_uSettlerWarriorTypes[i->m_uType]
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerMgr.cpp",
           221,
           "m_uSettlerWarriorTypes[pInfo->m_uType] == 0") == 1 )
    {
      __debugbreak();
    }
    if ( CSettlerMgr::m_uSettlerWarriorLevels[i->m_uType] )
    {
      if ( BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\SettlerMgr.cpp",
             222,
             "m_uSettlerWarriorLevels[pInfo->m_uType] == 0") == 1 )
        __debugbreak();
    }
    CSettlerMgr::m_uSettlerWarriorTypes[i->m_uType] = i->m_uWarriorType;
    CSettlerMgr::m_uSettlerWarriorLevels[i->m_uType] = i->m_uWarriorLevel;
  }
  memset(this->m_vFirstSettlerId, 0, sizeof(this->m_vFirstSettlerId));
  memset(this->m_vPlayerSettlerNumber, 0, sizeof(this->m_vPlayerSettlerNumber));
  memset(this->m_vPlayerSettlerOfferedNumber, 0, sizeof(this->m_vPlayerSettlerOfferedNumber));
  return this;
}


// address=[0x1580410]
// Decompiled from void __thiscall CSettlerMgr::~CSettlerMgr(CSettlerMgr *this)
 CSettlerMgr::~CSettlerMgr(void) {
  
  MemoryAllocator::~MemoryAllocator(&this->m_cAllocator);
}


// address=[0x1580430]
// Decompiled from void __thiscall CSettlerMgr::Clear(CSettlerMgr *this)
void  CSettlerMgr::Clear(void) {
  
  memset(this->m_vFirstSettlerId, 0, sizeof(this->m_vFirstSettlerId));
  memset(this->m_vPlayerSettlerNumber, 0, sizeof(this->m_vPlayerSettlerNumber));
  memset(this->m_vPlayerSettlerOfferedNumber, 0, sizeof(this->m_vPlayerSettlerOfferedNumber));
  this->m_uTotalSettlers = 0;
  g_pHJBMgr->InitHJBManager(g_pHJBMgr);
}


// address=[0x15804a0]
// Decompiled from struct ISettlerRole *__thiscall CSettlerMgr::CreateSettlerRole(CSettlerMgr *this, unsigned int _iRace, int _iType)
class ISettlerRole *  CSettlerMgr::CreateSettlerRole(int _iRace, int _iType) {
  
  struct ISettlerRole *result; // eax MAPDST

  if ( _iRace > 4
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1446, "_iRace>=0 && _iRace<RACE_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (_iType <= 0 || _iType >= SETTLER_MAX)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1447,
         "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  switch ( CSettlerMgr::m_vSettlerInfos[_iRace][_iType].m_uRole )
  {
    case 1u:
      result = (struct ISettlerRole *)operator new(0x38u);
      if ( result )
        result = CCarrierRole::CCarrierRole((CCarrierRole *)result);
      else
        result = 0;
      break;
    case 2u:
      result = (struct ISettlerRole *)operator new(0x30u);
      if ( result )
        result = CDiggerRole::CDiggerRole((CDiggerRole *)result);
      else
        result = 0;
      break;
    case 3u:
      result = (struct ISettlerRole *)operator new(0x30u);
      if ( result )
        result = CBuilderRole::CBuilderRole((CBuilderRole *)result);
      else
        result = 0;
      break;
    case 4u:
      result = (struct ISettlerRole *)operator new(0x34u);
      if ( result )
        result = (struct ISettlerRole *)CHouseWorkerRole::CHouseWorkerRole((CHouseWorkerRole *)result);
      else
        result = 0;
      break;
    case 5u:
      result = (struct ISettlerRole *)operator new(0x38u);
      if ( result )
        result = (struct ISettlerRole *)CFreeWorkerRole::CFreeWorkerRole((CFreeWorkerRole *)result);
      else
        result = 0;
      break;
    case 7u:
      result = (struct ISettlerRole *)operator new(0x64u);
      if ( result )
        result = CSoldierRole::CSoldierRole((CSoldierRole *)result);
      else
        result = 0;
      break;
    case 8u:
      result = (struct ISettlerRole *)operator new(0x30u);
      if ( result )
        result = (struct ISettlerRole *)CHunterRole::CHunterRole((CHunterRole *)result);
      else
        result = 0;
      break;
    case 9u:
      result = (struct ISettlerRole *)operator new(0x40u);
      if ( result )
        result = (struct ISettlerRole *)CPriestRole::CPriestRole((CPriestRole *)result);
      else
        result = 0;
      break;
    case 0xAu:
      result = (struct ISettlerRole *)operator new(0x68u);
      if ( result )
        result = (struct ISettlerRole *)CSaboteurRole::CSaboteurRole((CSaboteurRole *)result);
      else
        result = 0;
      break;
    case 0xBu:
      result = (struct ISettlerRole *)operator new(0x4Cu);
      if ( result )
        result = (struct ISettlerRole *)CPioneerRole::CPioneerRole((CPioneerRole *)result);
      else
        result = 0;
      break;
    case 0xCu:
      result = (struct ISettlerRole *)operator new(0x54u);
      if ( result )
        result = (struct ISettlerRole *)CGeologistRole::CGeologistRole((CGeologistRole *)result);
      else
        result = 0;
      break;
    case 0xDu:
      result = (struct ISettlerRole *)operator new(0x54u);
      if ( result )
        result = CGardenerRole::CGardenerRole((CGardenerRole *)result);
      else
        result = 0;
      break;
    case 0xEu:
      result = (struct ISettlerRole *)operator new(0x50u);
      if ( result )
        result = (struct ISettlerRole *)CDarkGardenerRole::CDarkGardenerRole((CDarkGardenerRole *)result);
      else
        result = 0;
      break;
    case 0xFu:
      result = (struct ISettlerRole *)operator new(0x30u);
      if ( result )
        result = (struct ISettlerRole *)CMushroomFarmerRole::CMushroomFarmerRole((CMushroomFarmerRole *)result);
      else
        result = 0;
      break;
    case 0x10u:
      result = (struct ISettlerRole *)operator new(0x74u);
      if ( result )
        result = (struct ISettlerRole *)CShamanRole::CShamanRole((CShamanRole *)result);
      else
        result = 0;
      break;
    case 0x11u:
      result = (struct ISettlerRole *)operator new(0x38u);
      if ( result )
        result = (struct ISettlerRole *)CSlaveRole::CSlaveRole((CSlaveRole *)result);
      else
        result = 0;
      break;
    case 0x13u:
      result = (struct ISettlerRole *)operator new(0x44u);
      if ( result )
        result = (struct ISettlerRole *)CThiefRole::CThiefRole((CThiefRole *)result);
      else
        result = 0;
      break;
    case 0x14u:
      result = (struct ISettlerRole *)operator new(0x7Cu);
      if ( result )
        result = CDonkeyRole::CDonkeyRole((CDonkeyRole *)result);
      else
        result = 0;
      break;
    case 0x17u:
      result = (struct ISettlerRole *)operator new(0x74u);
      if ( result )
        result = (struct ISettlerRole *)CSquadLeaderRole::CSquadLeaderRole((CSquadLeaderRole *)result);
      else
        result = 0;
      break;
    default:
      CTrace::Print("This settler type %s has no role ... ", (&SettlerTypeToNameMap)[2 * _iType]);
      if ( BBSupportDbgReport(
             1,
             "MapObjects\\Settler\\SettlerMgr.cpp",
             1568,
             "Internal error (SE4) - aborting!\nInterner Fehler (SE4) - Programm wird abgebrochen!") == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


// address=[0x1580c20]
// Decompiled from struct ISettlerRole *__cdecl CSettlerMgr::LoadSettlerRole(struct std::istream *a1, int a2)
class ISettlerRole * __cdecl CSettlerMgr::LoadSettlerRole(std::istream & a1, int a2) {
  
  struct ISettlerRole *result; // eax

  switch ( a2 )
  {
    case 1:
      result = (struct ISettlerRole *)CCarrierRole::Load((int)a1);
      break;
    case 2:
      result = (struct ISettlerRole *)CDiggerRole::Load((int)a1);
      break;
    case 3:
      result = (struct ISettlerRole *)CBuilderRole::Load((int)a1);
      break;
    case 4:
      result = (struct ISettlerRole *)CHouseWorkerRole::Load((int)a1);
      break;
    case 5:
      result = (struct ISettlerRole *)CFreeWorkerRole::Load((int)a1);
      break;
    case 7:
      result = (struct ISettlerRole *)CSoldierRole::Load((int)a1);
      break;
    case 8:
      result = (struct ISettlerRole *)CHunterRole::Load((int)a1);
      break;
    case 9:
      result = (struct ISettlerRole *)CPriestRole::Load((int)a1);
      break;
    case 10:
      result = (struct ISettlerRole *)CSaboteurRole::Load((int)a1);
      break;
    case 11:
      result = (struct ISettlerRole *)CPioneerRole::Load((int)a1);
      break;
    case 12:
      result = (struct ISettlerRole *)CGeologistRole::Load((int)a1);
      break;
    case 13:
      result = (struct ISettlerRole *)CGardenerRole::Load((int)a1);
      break;
    case 14:
      result = (struct ISettlerRole *)CDarkGardenerRole::Load((int)a1);
      break;
    case 15:
      result = (struct ISettlerRole *)CMushroomFarmerRole::Load((int)a1);
      break;
    case 16:
      result = (struct ISettlerRole *)CShamanRole::Load((int)a1);
      break;
    case 17:
      result = (struct ISettlerRole *)CSlaveRole::Load((int)a1);
      break;
    case 18:
      result = (struct ISettlerRole *)CFleeRole::Load((int)a1);
      break;
    case 19:
      result = (struct ISettlerRole *)CThiefRole::Load((int)a1);
      break;
    case 20:
      result = (struct ISettlerRole *)CDonkeyRole::Load((int)a1);
      break;
    case 21:
      result = (struct ISettlerRole *)CDoorRole::Load((int)a1);
      break;
    case 22:
      result = (struct ISettlerRole *)CTowerSoldier::Load((int)a1);
      break;
    case 23:
      result = (struct ISettlerRole *)CSquadLeaderRole::Load_HACK_VERSION(a1);
      break;
    case 24:
      result = (struct ISettlerRole *)CHJBRole::Load((int)a1);
      break;
    default:
      if ( BBSupportDbgReportF(1, "MapObjects\\Settler\\SettlerMgr.cpp", 1726, "Can't load settler role %d", a2) == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


// address=[0x1580eb0]
// Decompiled from void __thiscall CSettlerMgr::LoadSettlerData(CSettlerMgr *this, struct S4::CMapFile *_pMapFile, T_S4_MAP_CHUNK _iChunk)
void  CSettlerMgr::LoadSettlerData(class S4::CMapFile & _pMapFile, int _iChunk) {
  
  char *pChunk; // [esp+10h] [ebp-28h]
  int iOwnerId; // [esp+14h] [ebp-24h]
  int iSize; // [esp+20h] [ebp-18h] BYREF
  int iX; // [esp+24h] [ebp-14h]
  int iY; // [esp+28h] [ebp-10h]
  char *v9; // [esp+2Ch] [ebp-Ch]
  int i; // [esp+30h] [ebp-8h]
  int iSettlerType; // [esp+34h] [ebp-4h]

  iSize = 0;
  pChunk = (char *)S4::CMapFile::LoadChunk(_pMapFile, _iChunk, 0, &iSize, 0);
  for ( i = 0; i < iSize; ++i )
  {
    v9 = &pChunk[6 * i];
    iX = *(unsigned __int16 *)v9;
    iY = *((unsigned __int16 *)v9 + 1);
    CWorldManager::Index(iX, iY);
    iOwnerId = (unsigned __int8)v9[5];
    iSettlerType = (unsigned __int8)v9[4];
    if ( iSettlerType >= 200 )
    {
      CVehicleMgr::AddVehicle((CVehicleMgr *)&g_cVehicleMgr, iX, iY, iOwnerId, iSettlerType - 200, -1, 0);
    }
    else if ( iSettlerType < SETTLER_MAX && iSettlerType >= SETTLER_NO_SETTLER )
    {
      CSettlerMgr::AddSettler(this, iX, iY, iOwnerId, iSettlerType, 0);
    }
  }
  S4::CMapFile::CloseChunk(_pMapFile, _iChunk, 0);
}


// address=[0x1580fe0]
// Decompiled from void __thiscall CSettlerMgr::LoadInfo(struct CSettlerMgr *this, char isMP)
void  CSettlerMgr::LoadInfo(bool isMP) {
  
  int v2; // eax
  char *v3; // eax
  char *v4; // eax
  BYTE v5; // al
  char *v6; // eax
  BYTE v7; // al
  char *v8; // eax
  BYTE v9; // al
  char *v10; // eax
  BYTE v11; // al
  char *v12; // eax
  BYTE v13; // al
  char *v14; // eax
  BYTE v15; // al
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  BYTE v19; // al
  char *v20; // eax
  char *v21; // eax
  char *v22; // eax
  int v23; // [esp+0h] [ebp-794h] BYREF
  _BYTE v24[28]; // [esp+10h] [ebp-784h] BYREF
  _DWORD v25[4]; // [esp+2Ch] [ebp-768h] BYREF
  _DWORD v26[4]; // [esp+4Ch] [ebp-748h] BYREF
  _BYTE v27[16]; // [esp+5Ch] [ebp-738h] BYREF
  _BYTE v28[16]; // [esp+6Ch] [ebp-728h] BYREF
  _DWORD v29[4]; // [esp+7Ch] [ebp-718h] BYREF
  _BYTE v30[16]; // [esp+8Ch] [ebp-708h] BYREF
  _DWORD v31[4]; // [esp+9Ch] [ebp-6F8h] BYREF
  _BYTE v32[16]; // [esp+ACh] [ebp-6E8h] BYREF
  _DWORD v33[4]; // [esp+BCh] [ebp-6D8h] BYREF
  _DWORD v34[4]; // [esp+CCh] [ebp-6C8h] BYREF
  _DWORD v35[4]; // [esp+DCh] [ebp-6B8h] BYREF
  _DWORD v36[21]; // [esp+ECh] [ebp-6A8h] BYREF
  char v37[16]; // [esp+140h] [ebp-654h] BYREF
  char v38[16]; // [esp+150h] [ebp-644h] BYREF
  SSearchData v39; // [esp+160h] [ebp-634h]
  char v40[16]; // [esp+170h] [ebp-624h] BYREF
  const struct AdvXMLParser::Attribute *v41; // [esp+180h] [ebp-614h]
  AdvXMLParser::Element *v42; // [esp+184h] [ebp-610h]
  AdvXMLParser::Element *v43; // [esp+188h] [ebp-60Ch]
  _DWORD *v44; // [esp+18Ch] [ebp-608h]
  _DWORD *v45; // [esp+190h] [ebp-604h]
  AdvXMLParser::Element *v46; // [esp+194h] [ebp-600h]
  _DWORD *v47; // [esp+198h] [ebp-5FCh]
  _DWORD *v48; // [esp+19Ch] [ebp-5F8h]
  AdvXMLParser::Element *v49; // [esp+1A0h] [ebp-5F4h]
  int ValueOfDefine; // [esp+1A4h] [ebp-5F0h]
  const struct AdvXMLParser::Attribute *v51; // [esp+1A8h] [ebp-5ECh]
  AdvXMLParser::Element *v52; // [esp+1ACh] [ebp-5E8h]
  _DWORD *v53; // [esp+1B0h] [ebp-5E4h]
  _DWORD *v54; // [esp+1B4h] [ebp-5E0h]
  _DWORD *v55; // [esp+1B8h] [ebp-5DCh]
  _DWORD *v56; // [esp+1BCh] [ebp-5D8h]
  struct CDefineTranslator *defineTranslator; // [esp+1C0h] [ebp-5D4h] MAPDST
  void *Root; // [esp+1C4h] [ebp-5D0h]
  int v59; // [esp+1C8h] [ebp-5CCh]
  void *C; // [esp+1D0h] [ebp-5C4h]
  int v62; // [esp+1D4h] [ebp-5C0h]
  int iAnimList; // [esp+1D8h] [ebp-5BCh] MAPDST
  std::string *v65; // [esp+1E0h] [ebp-5B4h]
  std::string *v66; // [esp+1E4h] [ebp-5B0h]
  AdvXMLParser::Element *v67; // [esp+1E8h] [ebp-5ACh]
  _DWORD *v68; // [esp+1ECh] [ebp-5A8h]
  _DWORD *v69; // [esp+1F0h] [ebp-5A4h]
  AdvXMLParser::Element *v70; // [esp+1F4h] [ebp-5A0h]
  AdvXMLParser::Element *v71; // [esp+1F8h] [ebp-59Ch]
  _DWORD *v72; // [esp+1FCh] [ebp-598h]
  _DWORD *v73; // [esp+200h] [ebp-594h]
  AdvXMLParser::Element *v74; // [esp+204h] [ebp-590h]
  AdvXMLParser::Element *v75; // [esp+208h] [ebp-58Ch]
  SSearchData *SearchData; // [esp+20Ch] [ebp-588h]
  int v77; // [esp+210h] [ebp-584h]
  std::string *v78; // [esp+214h] [ebp-580h]
  std::string *v79; // [esp+218h] [ebp-57Ch]
  AdvXMLParser::Element *v80; // [esp+21Ch] [ebp-578h]
  _DWORD *v81; // [esp+220h] [ebp-574h]
  _DWORD *v82; // [esp+224h] [ebp-570h]
  AdvXMLParser::Element *v83; // [esp+228h] [ebp-56Ch]
  AdvXMLParser::Element *v84; // [esp+22Ch] [ebp-568h]
  _DWORD *v85; // [esp+230h] [ebp-564h]
  _DWORD *v86; // [esp+234h] [ebp-560h]
  AdvXMLParser::Element *v87; // [esp+238h] [ebp-55Ch]
  AdvXMLParser::Element *v88; // [esp+23Ch] [ebp-558h]
  std::string *v89; // [esp+240h] [ebp-554h]
  AdvXMLParser::Element *v90; // [esp+244h] [ebp-550h]
  AdvXMLParser::Element *v91; // [esp+248h] [ebp-54Ch]
  int v92; // [esp+24Ch] [ebp-548h]
  int v93; // [esp+250h] [ebp-544h]
  std::string *v94; // [esp+254h] [ebp-540h]
  std::string *v95; // [esp+258h] [ebp-53Ch]
  AdvXMLParser::Element *v97; // [esp+260h] [ebp-534h]
  AdvXMLParser::Element *v98; // [esp+264h] [ebp-530h]
  int v99; // [esp+268h] [ebp-52Ch]
  std::string *v100; // [esp+26Ch] [ebp-528h]
  std::string *v101; // [esp+270h] [ebp-524h]
  AdvXMLParser::Element *v102; // [esp+274h] [ebp-520h]
  AdvXMLParser::Element *v103; // [esp+278h] [ebp-51Ch]
  std::string *v104; // [esp+27Ch] [ebp-518h]
  AdvXMLParser::Element *v105; // [esp+280h] [ebp-514h]
  AdvXMLParser::Element *v106; // [esp+284h] [ebp-510h]
  std::string *v107; // [esp+288h] [ebp-50Ch]
  AdvXMLParser::Element *v108; // [esp+28Ch] [ebp-508h]
  AdvXMLParser::Element *v109; // [esp+290h] [ebp-504h]
  std::string *v110; // [esp+294h] [ebp-500h]
  AdvXMLParser::Element *v111; // [esp+298h] [ebp-4FCh]
  AdvXMLParser::Element *v112; // [esp+29Ch] [ebp-4F8h]
  std::string *v113; // [esp+2A0h] [ebp-4F4h]
  AdvXMLParser::Element *v114; // [esp+2A4h] [ebp-4F0h]
  AdvXMLParser::Element *v115; // [esp+2A8h] [ebp-4ECh]
  std::string *v116; // [esp+2ACh] [ebp-4E8h]
  AdvXMLParser::Element *v117; // [esp+2B0h] [ebp-4E4h]
  AdvXMLParser::Element *v118; // [esp+2B4h] [ebp-4E0h]
  std::string *v119; // [esp+2B8h] [ebp-4DCh]
  AdvXMLParser::Element *v120; // [esp+2BCh] [ebp-4D8h]
  AdvXMLParser::Element *v121; // [esp+2C0h] [ebp-4D4h]
  int v122; // [esp+2C4h] [ebp-4D0h]
  AdvXMLParser::Element *v123; // [esp+2C8h] [ebp-4CCh]
  AdvXMLParser::Element *v124; // [esp+2CCh] [ebp-4C8h]
  int tribeId; // [esp+2D0h] [ebp-4C4h]
  int v126; // [esp+2D4h] [ebp-4C0h]
  int settlerInfoId; // [esp+2D8h] [ebp-4BCh] MAPDST
  CConfigManager *configManager; // [esp+2DCh] [ebp-4B8h] MAPDST
  void *v129; // [esp+2E0h] [ebp-4B4h]
  const struct AdvXMLParser::Attribute *v130; // [esp+2E4h] [ebp-4B0h]
  const struct AdvXMLParser::Attribute *v131; // [esp+2E8h] [ebp-4ACh]
  AdvXMLParser::Element *v134; // [esp+2F4h] [ebp-4A0h]
  AdvXMLParser::Element *v135; // [esp+2F8h] [ebp-49Ch]
  AdvXMLParser::Element *v136; // [esp+2FCh] [ebp-498h]
  AdvXMLParser::Element *v137; // [esp+300h] [ebp-494h]
  AdvXMLParser::Element *v138; // [esp+304h] [ebp-490h]
  AdvXMLParser::Element *v139; // [esp+308h] [ebp-48Ch]
  AdvXMLParser::Element *v140; // [esp+30Ch] [ebp-488h]
  AdvXMLParser::Element *v141; // [esp+310h] [ebp-484h]
  AdvXMLParser::Element *v142; // [esp+314h] [ebp-480h]
  AdvXMLParser::Element *v143; // [esp+318h] [ebp-47Ch]
  CSettlerMgr::SSearchInfos v144; // [esp+31Ch] [ebp-478h] BYREF
  char v145; // [esp+323h] [ebp-471h]
  CConfigManager *v146; // [esp+324h] [ebp-470h]
  char v148[4]; // [esp+32Ch] [ebp-468h] BYREF
  AdvXMLParser::Element *v151; // [esp+338h] [ebp-45Ch]
  int v152; // [esp+33Ch] [ebp-458h]
  AdvXMLParser::Element *v153; // [esp+340h] [ebp-454h]
  int v154; // [esp+344h] [ebp-450h] BYREF
  int m_bMisc; // [esp+348h] [ebp-44Ch]
  __int16 v156; // [esp+34Eh] [ebp-446h] BYREF
  char v157[16]; // [esp+350h] [ebp-444h] BYREF
  int j; // [esp+364h] [ebp-430h]
  char *v160; // [esp+368h] [ebp-42Ch]
  int i; // [esp+36Ch] [ebp-428h]
  int k; // [esp+370h] [ebp-424h]
  CSettlerMgr::SSettlerInfos *settlerInfo; // [esp+378h] [ebp-41Ch]
  _BYTE v168[28]; // [esp+5A4h] [ebp-1F0h] BYREF
  _BYTE v169[28]; // [esp+5C0h] [ebp-1D4h] BYREF
  _BYTE v170[28]; // [esp+5DCh] [ebp-1B8h] BYREF
  _BYTE v171[28]; // [esp+5F8h] [ebp-19Ch] BYREF
  _BYTE v172[28]; // [esp+614h] [ebp-180h] BYREF
  _BYTE v173[28]; // [esp+630h] [ebp-164h] BYREF
  _BYTE v174[28]; // [esp+64Ch] [ebp-148h] BYREF
  _BYTE v175[28]; // [esp+668h] [ebp-12Ch] BYREF
  _BYTE v176[28]; // [esp+684h] [ebp-110h] BYREF
  _BYTE v177[28]; // [esp+6A0h] [ebp-F4h] BYREF
  _BYTE v178[28]; // [esp+6BCh] [ebp-D8h] BYREF
  struct std::string v179; // [esp+6D8h] [ebp-BCh] BYREF
  std::string v180; // [esp+6F4h] [ebp-A0h] BYREF
  struct std::string v181; // [esp+710h] [ebp-84h] BYREF
  struct std::string v182; // [esp+72Ch] [ebp-68h] BYREF
  struct std::string v183; // [esp+748h] [ebp-4Ch] BYREF
  char v184[28]; // [esp+764h] [ebp-30h] BYREF
  int *v185; // [esp+784h] [ebp-10h]
  int v186; // [esp+790h] [ebp-4h]

  v185 = &v23;
  if ( !this->m_bLoaded )
  {
    v154 = 0;
    v160 = 0;
    v160 = (char *)(isMP
                  ? AdvXMLParser::Parser::OpenXMLFile(aGamedataSettle, &v154)
                  : AdvXMLParser::Parser::OpenXMLFile(aGamedataSettle_0, &v154));
    if ( v160 )
    {
      v186 = 0;
      v36[18] = AdvXMLParser::Parser::Parser(v24);
      LOBYTE(v186) = 1;
      v59 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v24, v160, v154);
      std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v59);
      LOBYTE(v186) = 2;
      v2 = std::auto_ptr<AdvXMLParser::Document>::operator->(v23);
      Root = (void *)AdvXMLParser::Document::GetRoot(v2);
      v129 = Root;
      defineTranslator = (struct CDefineTranslator *)CDefineTranslator::Instance();
      v36[10] = 0;
      v56 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v129, v32);
      v55 = v56;
      LOBYTE(v186) = 3;
      v36[9] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v40, v56);
      LOBYTE(v186) = 5;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v32);
      v54 = AdvXMLParser::NodeContainer::End(v129, v31);
      v53 = v54;
      LOBYTE(v186) = 6;
      v36[8] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v33, v54);
      LOBYTE(v186) = 8;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v31);
      while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v40, (int)v33) )
      {
        v52 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v40);
        v51 = AdvXMLParser::Element::operator[](v52, "id");
        v130 = v51;
        v36[7] = v51->GetValue(v51, &v181);
        LOBYTE(v186) = 9;
        ValueOfDefine = CDefineTranslator::GetValueOfDefine(defineTranslator, &v181);
        tribeId = ValueOfDefine;
        v49 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v40);
        v48 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v49, v30);
        v47 = v48;
        LOBYTE(v186) = 10;
        v36[6] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v157, v48);
        LOBYTE(v186) = 12;
        AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v30);
        v46 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v40);
        v45 = AdvXMLParser::NodeContainer::End(v46, v29);
        v44 = v45;
        LOBYTE(v186) = 13;
        v36[5] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v34, v45);
        LOBYTE(v186) = 15;
        AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v29);
        while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v157, (int)v34) )
        {
          v43 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v36[4] = v43;
          v42 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v41 = AdvXMLParser::Element::operator[](v42, "id");
          v131 = v41;
          v36[20] = v41->GetValue(v41, &v180);
          LOBYTE(v186) = 16;
          configManager = CConfigManagerPtr::GetInstance();
          v3 = std::string::c_str(&v180);
          settlerInfoId = configManager->GetDefineValue(configManager, v3);
          if ( settlerInfoId == -1 )
          {
            v126 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1791, "index != -1");
            if ( v126 == 1 )
              __debugbreak();
          }
          settlerInfo = &CSettlerMgr::m_vSettlerInfos[tribeId][settlerInfoId];
          v124 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v123 = AdvXMLParser::Element::operator()(v124, "role", 0);
          v135 = v123;
          v36[19] = ((int (__thiscall *)(AdvXMLParser::Element *, struct std::string *))v123->GetValue)(v123, &v179);
          LOBYTE(v186) = 17;
          v122 = CDefineTranslator::GetValueOfDefine(defineTranslator, &v179);
          settlerInfo->m_uRole = v122;
          v121 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v120 = AdvXMLParser::Element::operator()(v121, "speed", 0);
          v136 = v120;
          v119 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v120->GetValue)(v120, v168);
          v4 = std::string::c_str(v119);
          v5 = j__atoi(v4);
          settlerInfo->m_bSpeed = v5;
          std::string::~string(v168);
          v118 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v117 = AdvXMLParser::Element::operator()(v118, "health", 0);
          v137 = v117;
          v116 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v117->GetValue)(v117, v169);
          v6 = std::string::c_str(v116);
          v7 = j__atoi(v6);
          settlerInfo->m_iMaxLifePoints = v7;
          std::string::~string(v169);
          v115 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v114 = AdvXMLParser::Element::operator()(v115, "armor", 0);
          v138 = v114;
          v113 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v114->GetValue)(v114, v170);
          v8 = std::string::c_str(v113);
          v9 = j__atoi(v8);
          settlerInfo->m_bArmor = v9;
          std::string::~string(v170);
          v112 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v111 = AdvXMLParser::Element::operator()(v112, "damage", 0);
          v139 = v111;
          v110 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v111->GetValue)(v111, v178);
          v10 = std::string::c_str(v110);
          v11 = j__atoi(v10);
          settlerInfo->m_bDamage = v11;
          std::string::~string(v178);
          v109 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v108 = AdvXMLParser::Element::operator()(v109, "damage2", 0);
          v140 = v108;
          v107 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v108->GetValue)(v108, v171);
          v12 = std::string::c_str(v107);
          v13 = j__atoi(v12);
          settlerInfo->m_bDamage2 = v13;
          std::string::~string(v171);
          v106 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v105 = AdvXMLParser::Element::operator()(v106, "damage3", 0);
          v141 = v105;
          v104 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v105->GetValue)(v105, v172);
          v14 = std::string::c_str(v104);
          v15 = j__atoi(v14);
          settlerInfo->m_bDamage3 = v15;
          std::string::~string(v172);
          v103 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v102 = AdvXMLParser::Element::operator()(v103, "other", 0);
          v142 = v102;
          v101 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v102->GetValue)(v102, v173);
          v100 = v101;
          LOBYTE(v186) = 18;
          v16 = std::string::c_str(v101);
          v36[11] = std::string::string(&v182, v16);
          LOBYTE(v186) = 19;
          v99 = CDefineTranslator::GetValueOfDefine(defineTranslator, &v182);
          settlerInfo->m_uFarmerType = v99;
          LOBYTE(v186) = 18;
          std::string::~string(&v182);
          LOBYTE(v186) = 17;
          std::string::~string(v173);
          v98 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v97 = AdvXMLParser::Element::operator()(v98, "tool", 0);
          v143 = v97;
          configManager = CConfigManagerPtr::GetInstance();
          v146 = configManager;
          v95 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v143->GetValue)(v143, v174);
          v94 = v95;
          LOBYTE(v186) = 20;
          v17 = std::string::c_str(v95);
          v93 = v146->GetDefineValue(v146, v17);
          settlerInfo->m_uTool = v93;
          LOBYTE(v186) = 17;
          std::string::~string(v174);
          if ( settlerInfo->m_uTool == -1 )
          {
            v92 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1811, "sI.m_uTool != -1");
            if ( v92 == 1 )
              __debugbreak();
          }
          v91 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v90 = AdvXMLParser::Element::operator()(v91, "misc", 0);
          v134 = v90;
          v89 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v90->GetValue)(v90, v175);
          v18 = std::string::c_str(v89);
          v19 = j__atoi(v18);
          settlerInfo->m_bMisc = v19;
          std::string::~string(v175);
          v88 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v87 = AdvXMLParser::Element::operator()(v88, "search", 0);
          v86 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v87, v28);
          v85 = v86;
          LOBYTE(v186) = 21;
          v36[17] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v37, v86);
          LOBYTE(v186) = 23;
          AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v28);
          v84 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v83 = AdvXMLParser::Element::operator()(v84, "search", 0);
          v82 = AdvXMLParser::NodeContainer::End(v83, v25);
          v81 = v82;
          LOBYTE(v186) = 24;
          v36[16] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v35, v82);
          LOBYTE(v186) = 26;
          AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v25);
          while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v37, (int)v35) )
          {
            v80 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v37);
            v153 = v80;
            v79 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v80->GetValue)(v80, v176);
            v78 = v79;
            LOBYTE(v186) = 27;
            v20 = std::string::c_str(v79);
            v36[15] = std::string::string(&v183, v20);
            LOBYTE(v186) = 29;
            std::string::~string(v176);
            v77 = CDefineTranslator::GetValueOfDefine(defineTranslator, &v183);
            v152 = v77;
            SearchData = (SSearchData *)CSearchRoutines::GetSearchData(v77);
            v39 = *SearchData;
            v144.m_pSearchFkt = v39.m_pSearchFunk;
            v144.m_iSearchType = v152;
            v144.m_iOffsetX = v39.m_iOffsetX;
            v144.m_iOffsetY = v39.m_iOffsetY;
            v145 = 0;
            std::vector<CSettlerMgr::SSearchInfos>::push_back(&v144);
            LOBYTE(v186) = 26;
            std::string::~string(&v183);
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v37);
          }
          v75 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v74 = AdvXMLParser::Element::operator()(v75, "animLists", 0);
          v73 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v74, v27);
          v72 = v73;
          LOBYTE(v186) = 30;
          v36[14] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v38, v73);
          LOBYTE(v186) = 32;
          AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v27);
          v71 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v157);
          v70 = AdvXMLParser::Element::operator()(v71, "animLists", 0);
          v69 = AdvXMLParser::NodeContainer::End(v70, v26);
          v68 = v69;
          LOBYTE(v186) = 33;
          v36[13] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v36, v69);
          LOBYTE(v186) = 35;
          AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v26);
          while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v38, (int)v36) )
          {
            v67 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v38);
            v151 = v67;
            v66 = (std::string *)((int (__thiscall *)(AdvXMLParser::Element *, _BYTE *))v67->GetValue)(v67, v177);
            v65 = v66;
            LOBYTE(v186) = 36;
            v21 = std::string::c_str(v66);
            v36[12] = std::string::string((std::string *)v184, v21);
            LOBYTE(v186) = 38;
            std::string::~string(v177);
            configManager = CConfigManagerPtr::GetInstance();
            v22 = std::string::c_str((std::string *)v184);
            iAnimList = configManager->GetDefineValue(configManager, v22);
            if ( iAnimList == -1 )
            {
              v62 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1842, "iAnimList != -1");
              if ( v62 == 1 )
                __debugbreak();
            }
            v156 = iAnimList;
            std::vector<unsigned short>::push_back(&settlerInfo->g_vAnimLists, &v156);
            LOBYTE(v186) = 35;
            std::string::~string(v184);
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v38);
          }
          LOBYTE(v186) = 32;
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v36);
          LOBYTE(v186) = 26;
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v38);
          LOBYTE(v186) = 23;
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v35);
          LOBYTE(v186) = 17;
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v37);
          LOBYTE(v186) = 16;
          std::string::~string(&v179);
          LOBYTE(v186) = 15;
          std::string::~string(&v180);
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v157);
        }
        LOBYTE(v186) = 12;
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v34);
        LOBYTE(v186) = 9;
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v157);
        LOBYTE(v186) = 8;
        std::string::~string(&v181);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v40);
      }
      LOBYTE(v186) = 5;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v33);
      LOBYTE(v186) = 2;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v40);
      LOBYTE(v186) = 1;
      std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v148);
      LOBYTE(v186) = 0;
      AdvXMLParser::Parser::~Parser(v24);
      v186 = -1;
      C = v160;
      operator delete[](v160);
      for ( i = 1; i < 67; ++i )
      {
        for ( j = 0; j < 5; ++j )
        {
          if ( !CSettlerMgr::m_vSettlerInfos[j][i].m_uRole )// If info not set, replace with info from first tribe
            CSettlerMgr::SSettlerInfos::operator=(
              &CSettlerMgr::m_vSettlerInfos[j][i],
              &CSettlerMgr::m_vSettlerInfos[0][i]);
        }
      }
      m_bMisc = CSettlerMgr::m_vSettlerInfos[0][44].m_bMisc;
      if ( !m_bMisc )
        m_bMisc = 10;
      CSettlerMgr::m_iSquadLeaderBoni256[0] = (m_bMisc << 8) / 100;
      for ( k = 0; k < 5; ++k )
      {
        if ( k )
        {
          if ( CSettlerMgr::m_vSettlerInfos[k][44].m_bMisc )// Seems like squad leader boni are set here, with the id coming from the config.
                                                // misc is either squad bonus attack in % or medic healing per animation and it seems like other special troops
            CSettlerMgr::m_iSquadLeaderBoni256[k] = CSettlerMgr::m_iSquadLeaderBoni256[0];
          else
            CSettlerMgr::m_iSquadLeaderBoni256[k] = 0;
        }
      }
      if ( !CSettlerMgr::m_vSettlerInfos[0][35].m_bMisc )
        CSettlerMgr::m_vSettlerInfos[0][35].m_bMisc = 3;
      if ( !CSettlerMgr::m_vSettlerInfos[0][36].m_bMisc )
        CSettlerMgr::m_vSettlerInfos[0][36].m_bMisc = 5;
      if ( !CSettlerMgr::m_vSettlerInfos[0][37].m_bMisc )
        CSettlerMgr::m_vSettlerInfos[0][37].m_bMisc = 7;
      if ( CSettlerMgr::m_vSettlerInfos[2][41].m_bMisc )
        g_iBlowgunWarriorFreezeChange = CRandom16::PercentValue(CSettlerMgr::m_vSettlerInfos[2][41].m_bMisc);
      if ( CSettlerMgr::m_vSettlerInfos[2][42].m_bMisc )
        *(&g_iBlowgunWarriorFreezeChange + 1) = CRandom16::PercentValue(CSettlerMgr::m_vSettlerInfos[2][42].m_bMisc);
      if ( CSettlerMgr::m_vSettlerInfos[2][43].m_bMisc )
        *(&g_iBlowgunWarriorFreezeChange + 2) = CRandom16::PercentValue(CSettlerMgr::m_vSettlerInfos[2][43].m_bMisc);
      if ( !CSettlerMgr::m_vSettlerInfos[2][61].m_bMisc )
        CSettlerMgr::m_vSettlerInfos[2][61].m_bMisc = 55;
      g_iBackPackCatapultistPercent[0] = CSettlerMgr::m_vSettlerInfos[2][61].m_bMisc;
      if ( !CSettlerMgr::m_vSettlerInfos[2][62].m_bMisc )
        CSettlerMgr::m_vSettlerInfos[2][62].m_bMisc = 65;
      g_iBackPackCatapultistPercent[1] = CSettlerMgr::m_vSettlerInfos[2][62].m_bMisc;
      if ( !CSettlerMgr::m_vSettlerInfos[2][63].m_bMisc )
        CSettlerMgr::m_vSettlerInfos[2][63].m_bMisc = 75;
      g_iBackPackCatapultistPercent[2] = CSettlerMgr::m_vSettlerInfos[2][63].m_bMisc;
      if ( CSettlerMgr::m_vSettlerInfos[0][46].m_bMisc )
        g_uSaboteurHitChange = CRandom16::PercentValue(CSettlerMgr::m_vSettlerInfos[0][46].m_bMisc);
    }
  }
}


// address=[0x1582460]
// Decompiled from int __thiscall CSettlerMgr::AddSettler(CSettlerMgr *this, int _iX, int _iY, int _iOwnerId, int _iSettlerType, int a6)
int  CSettlerMgr::AddSettler(int _iX, int _iY, int _iOwnerId, int _iSettlerType, int a6) {
  
  CPlayerInfo *playerInfo; // eax
  CSettler *getSettler; // eax
  auto_ptr_ISettlerRole v9; // [esp-8h] [ebp-5Ch] BYREF
  int freeSlot; // [esp-4h] [ebp-58h]
  auto_ptr_ISettlerRole *v11; // [esp+4h] [ebp-50h]
  auto_ptr_ISettlerRole *v12; // [esp+8h] [ebp-4Ch]
  int v13; // [esp+Ch] [ebp-48h]
  CSettler *pNewSettler; // [esp+18h] [ebp-3Ch] MAPDST
  DWORD race; // [esp+1Ch] [ebp-38h]
  auto_ptr_ISettlerRole a2; // [esp+24h] [ebp-30h] BYREF
  CSettler *settler; // [esp+30h] [ebp-24h]
  ISettlerRole *v25; // [esp+3Ch] [ebp-18h] MAPDST
  int settlerRole; // [esp+40h] [ebp-14h]
  int v27; // [esp+40h] [ebp-14h] SPLIT
  int v29; // [esp+50h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 467, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iOwnerId <= 0 || _iOwnerId >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 468, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= 0 || _iSettlerType >= 67)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 469, "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uTotalSettlers >= 0x7FFFu )
  {
    CTrace::Print("No more settler allowed!");
    return 0;
  }
  else
  {
    ++this->m_uTotalSettlers;
    playerInfo = CPlayerManager::PlayerInfo(_iOwnerId);
    race = CPlayerInfo::Race(playerInfo);
    v25 = 0;
    if ( _iSettlerType != 1 || _iOwnerId == CWorldManager::OwnerId(_iX, _iY) )
    {
      v25 = CSettlerMgr::CreateSettlerRole(&g_cSettlerMgr, race, _iSettlerType);
    }
    else
    {
      v25 = (ISettlerRole *)operator new(0x2Cu);
      v29 = 0;
      if ( v25 )
        v25 = (ISettlerRole *)CFleeRole::CFleeRole((CFleeRole *)v25);
      else
        v25 = 0;
      v29 = -1;
    }
    std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&a2, v25);
    v29 = 1;
    settlerRole = CMapObjectMgr::GetFreeSlot();
    settler = (CSettler *)CSettler::operator new(0x68u);
    LOBYTE(v29) = 2;
    if ( settler )
    {
      freeSlot = settlerRole;
      v9.ptr = (ISettlerRole *)settlerRole;
      v12 = &v9;
      v11 = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&v9, &a2);
      pNewSettler = CSettler::CSettler(settler, _iX, _iY, _iSettlerType, _iOwnerId, v9.ptr, freeSlot);
    }
    else
    {
      pNewSettler = 0;
    }
    LOBYTE(v29) = 1;
    getSettler = CSettlerMgr::GetSettlerPtr(this, v27);
    if ( pNewSettler != getSettler
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 503, "pNewSettler == GetSettlerPtr(iEntityId)") == 1 )
    {
      __debugbreak();
    }
    if ( CSettlerMgr::SettlerWarriorType(_iSettlerType) )
    {
      CSettlerMgr::AttachSettler(this, pNewSettler);
      if ( a6 > 0 )
        g_pAI->PostAIEvent(g_pAI, 20, _iOwnerId, v27, a6);
    }
    CSettlerMgr::IncNumberOfSettler(this, _iOwnerId, (S4_SETTLER_ENUM)_iSettlerType);
    v13 = v27;
    v29 = -1;
    std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
    return v13;
  }
}


// address=[0x1582720]
// Decompiled from bool __thiscall CSettlerMgr::IsAddSettlerOk(CSettlerMgr *this, unsigned int _iX, unsigned int _iY, int _iOwnerId)
bool  CSettlerMgr::IsAddSettlerOk(int _iX, int _iY, int _iOwnerId) {
  
  int iIdx; // [esp+4h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY) )
    return 0;
  iIdx = CWorldManager::Index(_iX, _iY);
  if ( CWorldManager::FlagBits(iIdx, 1u) )
    return 0;
  if ( CWorldManager::MapObjectId(iIdx) )
    return 0;
  return !_iOwnerId || ITiling::OwnerId(iIdx) == _iOwnerId;
}


// address=[0x15827b0]
// Decompiled from void __thiscall CSettlerMgr::AddSettlers(  CSettlerMgr *this,  unsigned int _iX,  unsigned int _iY,  int _iOwnerId,  int _iSettlerType,  int _iAmount,  int a7)
void  CSettlerMgr::AddSettlers(int _iX, int _iY, int _iOwnerId, int _iSettlerType, int _iAmount, int a7) {
  
  int iIdx; // [esp+10h] [ebp-14h]
  int iAmountLeft; // [esp+14h] [ebp-10h]
  unsigned int iOffsetX; // [esp+18h] [ebp-Ch]
  unsigned int iOffsetY; // [esp+1Ch] [ebp-8h]
  int iOffsetStep; // [esp+20h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 560, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iOwnerId <= 0 || _iOwnerId >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 561, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= 0 || _iSettlerType >= 67)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 562, "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (_iAmount <= 0 || _iAmount >= 10000)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 563, "_iAmount>0 && _iAmount<10000") == 1 )
  {
    __debugbreak();
  }
  iOffsetStep = 0;
  iAmountLeft = _iAmount;
  while ( iAmountLeft && iOffsetStep < 20000 )
  {
    iOffsetX = _iX + CSpiralOffsets::DeltaX(iOffsetStep);
    iOffsetY = _iY + CSpiralOffsets::DeltaY(iOffsetStep);
    iIdx = CWorldManager::Index(iOffsetX, iOffsetY);
    if ( CWorldManager::InWorld(iOffsetX, iOffsetY)
      && !CWorldManager::MapObjectId(iIdx)
      && !CWorldManager::FlagBits(iIdx, 0x39u) )
    {
      if ( CSettlerMgr::AddSettler(this, iOffsetX, iOffsetY, _iOwnerId, _iSettlerType, a7) )
        --iAmountLeft;
    }
    ++iOffsetStep;
  }
}


// address=[0x1582970]
// Decompiled from int __thiscall CSettlerMgr::AddGuardSettler(CSettlerMgr *this, unsigned int iX, unsigned int iY, int iOwnerId)
int  CSettlerMgr::AddGuardSettler(int iX, int iY, int iOwnerId) {
  
  auto_ptr_ISettlerRole v5; // [esp-8h] [ebp-54h] BYREF
  auto_ptr_ISettlerRole *v7; // [esp+4h] [ebp-48h]
  auto_ptr_ISettlerRole *v8; // [esp+8h] [ebp-44h]
  int v9; // [esp+Ch] [ebp-40h]
  CSettler *v10; // [esp+10h] [ebp-3Ch]
  CSettler *v11; // [esp+14h] [ebp-38h]
  CSettler *v12; // [esp+18h] [ebp-34h]
  auto_ptr_ISettlerRole a2; // [esp+20h] [ebp-2Ch] BYREF
  int FreeSlot; // [esp+24h] [ebp-28h] MAPDST
  CSettler *v16; // [esp+28h] [ebp-24h]
  CSettler *v17; // [esp+2Ch] [ebp-20h]
  ISettlerRole *pDoorRole; // [esp+30h] [ebp-1Ch] MAPDST
  void *C; // [esp+34h] [ebp-18h]
  int exceptionBlock; // [esp+48h] [ebp-4h]

  if ( !CWorldManager::InWorld(iX, iY)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 616, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (iOwnerId <= 0 || iOwnerId >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 617, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uTotalSettlers >= 0x7FFFu )
  {
    CTrace::Print("No more settler allowed!");
    return 0;
  }
  else
  {
    ++this->m_uTotalSettlers;
    C = operator new(0x2Cu);
    exceptionBlock = 0;
    if ( C )
      pDoorRole = (ISettlerRole *)CDoorRole::CDoorRole((CDoorRole *)C);
    else
      pDoorRole = 0;
    exceptionBlock = -1;
    std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&a2, pDoorRole);
    exceptionBlock = 1;
    FreeSlot = CMapObjectMgr::GetFreeSlot();
    v17 = (CSettler *)CSettler::operator new(0x68u);
    LOBYTE(exceptionBlock) = 2;
    if ( v17 )
    {
      v5.ptr = (ISettlerRole *)FreeSlot;
      v8 = &v5;
      v7 = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&v5, &a2);
      v12 = CSettler::CSettler(v17, iX, iY, iOwnerId, v5, FreeSlot);
      v16 = v12;
    }
    else
    {
      v16 = 0;
    }
    v11 = v16;
    LOBYTE(exceptionBlock) = 1;
    v10 = v16;
    pDoorRole->Init(pDoorRole, v16);
    v9 = FreeSlot;
    exceptionBlock = -1;
    std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
    return v9;
  }
}


// address=[0x1582b30]
// Decompiled from void __thiscall CSettlerMgr::DeleteSettler(CSettlerMgr *this, int _iSettlerId)
void  CSettlerMgr::DeleteSettler(int _iSettlerId) {
  
  IEntity *v2; // eax

  if ( (_iSettlerId <= 1 || _iSettlerId >= 0xFFFF)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         652,
         "_iSettlerId>1 && _iSettlerId<CMapObjectMgr::MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  v2 = CMapObjectMgr::Entity(_iSettlerId);
  if ( IEntity::ObjType(v2) != SETTLER_OBJ
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         653,
         "g_pMapObjectMgr->Entity(_iSettlerId).ObjType() == SETTLER_OBJ") == 1 )
  {
    __debugbreak();
  }
  CMapObjectMgr::Kill(g_pMapObjectMgr, _iSettlerId, 0);
}


// address=[0x1582bc0]
// Decompiled from char __thiscall CSettlerMgr::SearchSpaceForSettler(  CSettlerMgr *this,  int _iSettlerId,  unsigned int _iX,  unsigned int _iY)
bool  CSettlerMgr::SearchSpaceForSettler(int _iSettlerId, int _iX, int _iY) {
  
  unsigned int v4; // eax
  int v5; // eax
  unsigned int v7; // [esp-8h] [ebp-24h]
  int v8; // [esp-4h] [ebp-20h]
  int v9; // [esp+8h] [ebp-14h]
  unsigned int v10; // [esp+Ch] [ebp-10h]
  unsigned int v11; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  CSettler *rSettler; // [esp+18h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 737, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerId <= 1 || _iSettlerId >= 0xFFFF)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         738,
         "_iSettlerId>1 && _iSettlerId<CMapObjectMgr::MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; i < 0x3E8; ++i )
  {
    v10 = _iX + CSpiralOffsets::DeltaX(i);
    v11 = _iY + CSpiralOffsets::DeltaY(i);
    v9 = CWorldManager::Index(v10, v11);
    if ( CWorldManager::InWorld(v10, v11) && !CWorldManager::MapObjectId(v9) && CWorldManager::SectorId(v9) )
    {
      CWorldManager::SetSettlerId(v9, _iSettlerId);
      rSettler = CSettlerMgr::operator[](_iSettlerId);
      IEntity::SetPosition(rSettler, v10, v11);
      v8 = IEntity::Type(rSettler);
      v7 = IEntity::Type(rSettler);
      v4 = IEntity::Race(rSettler);
      v5 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v4, v7);
      rSettler->NewToDoList(rSettler, v5, v8);
      return 1;
    }
  }
  return 0;
}


// address=[0x1582d50]
// Decompiled from bool __thiscall CSettlerMgr::SearchFreePositionInSector(CSettlerMgr *this, int *_rX, int *_rY, int _iSectorId, char a5)
bool  CSettlerMgr::SearchFreePositionInSector(int & _rX, int & _rY, int _iSectorId, int a5) {
  
  int v6[4]; // [esp+0h] [ebp-24h] BYREF
  int v7; // [esp+10h] [ebp-14h]
  int iY; // [esp+18h] [ebp-Ch] BYREF
  int iX; // [esp+1Ch] [ebp-8h] BYREF
  int iIdx; // [esp+20h] [ebp-4h]
  char a5a; // [esp+38h] [ebp+14h]

  if ( _iSectorId == -1 )
  {
    _iSectorId = CWorldManager::SectorId(*_rX, *_rY);
    if ( _iSectorId <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2687, "_iSectorId > 0") == 1 )
      __debugbreak();
  }
  if ( _iSectorId <= 0 )
    return 0;
  a5a = a5 | 1;
  v7 = 15;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v6, *_rX, *_rY, 15);
  while ( CSpiralWalk::NextXY(v6, &iX, &iY) )
  {
    iIdx = CWorldManager::Index(iX, iY);
    if ( !CWorldManager::FlagBits(iIdx, a5a)
      && !CWorldManager::MapObjectId(iIdx)
      && ITiling::SectorId(iIdx) == _iSectorId )
    {
      *_rX = iX;
      *_rY = iY;
      return 1;
    }
  }
  return 0;
}


// address=[0x1582e60]
// Decompiled from char __thiscall CSettlerMgr::SearchFreePositionInEcoSector(CSettlerMgr *this, int *_rX, int *_rY, int _iEcoSectorId)
bool  CSettlerMgr::SearchFreePositionInEcoSector(int & _rX, int & _rY, int _iEcoSectorId) {
  
  int v5[4]; // [esp+0h] [ebp-24h] BYREF
  int v6; // [esp+10h] [ebp-14h]
  int iOffsetY; // [esp+18h] [ebp-Ch] BYREF
  int iOffsetX; // [esp+1Ch] [ebp-8h] BYREF
  int iIdx; // [esp+20h] [ebp-4h]

  if ( _iEcoSectorId <= 0 )
    return 0;
  v6 = 15;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v5, *_rX, *_rY, 15);
  while ( CSpiralWalk::NextXY(v5, &iOffsetX, &iOffsetY) )
  {
    iIdx = CWorldManager::Index(iOffsetX, iOffsetY);
    if ( !CWorldManager::FlagBits(iIdx, 0x21u)
      && !CWorldManager::MapObjectId(iIdx)
      && ITiling::EcoSectorId(iIdx) == _iEcoSectorId )
    {
      *_rX = iOffsetX;
      *_rY = iOffsetY;
      return 1;
    }
  }
  return 0;
}


// address=[0x1582f20]
// Decompiled from DWORD __thiscall CSettlerMgr::GetFirstSettlerId(CSettlerMgr *this, int _iOwnerId, int _iSettlerType)
int  CSettlerMgr::GetFirstSettlerId(int _iOwnerId, int _iSettlerType)const {
  
  if ( (_iOwnerId <= 0 || _iOwnerId >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 792, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= 0 || _iSettlerType >= 67)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 793, "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_vFirstSettlerId[_iOwnerId][_iSettlerType];
}


// address=[0x1582fa0]
// Decompiled from int __thiscall CSettlerMgr::OrderWarrior(  CSettlerMgr *this,  int _iBuildingId,  int _iSettlerType,  unsigned int _iMaxDistance)
int  CSettlerMgr::OrderWarrior(int _iBuildingId, int _iSettlerType, int _iMaxDistance) {
  
  int v4; // eax
  int iIdx; // eax
  int iBuildingY; // esi
  int iBuildingX; // esi
  int iEntityX; // eax
  CSettler *v9; // eax
  CSettler *v10; // eax
  int v12; // [esp-4h] [ebp-60h]
  CEntityEvent cEvent; // [esp+8h] [ebp-54h] BYREF
  struct CEntityEvent *v15; // [esp+24h] [ebp-38h] MAPDST
  int iBuildingSector; // [esp+28h] [ebp-34h]
  int iOwnerId; // [esp+30h] [ebp-2Ch]
  unsigned int iSmallestDistance; // [esp+34h] [ebp-28h]
  unsigned int iDistance; // [esp+38h] [ebp-24h]
  CSettler *rSettler; // [esp+3Ch] [ebp-20h]
  IEntity *rSettlerIter; // [esp+40h] [ebp-1Ch]
  CBuilding *rBuilding; // [esp+44h] [ebp-18h]
  int iSettlerIdIter; // [esp+48h] [ebp-14h]
  int iNearestFreeSoldierId; // [esp+4Ch] [ebp-10h]
  int exceptionBlock; // [esp+58h] [ebp-4h]

  iSmallestDistance = -1;
  rBuilding = CBuildingMgr::operator[](_iBuildingId);
  v4 = CBuilding::EnsignWorldIdx(rBuilding);
  iBuildingSector = CWorldManager::SectorId(v4);
  iOwnerId = IEntity::OwnerId((IEntity *)rBuilding);
  iSettlerIdIter = CSettlerMgr::GetFirstSettlerId(this, iOwnerId, _iSettlerType);
  iNearestFreeSoldierId = 0;
  while ( iSettlerIdIter )
  {
    rSettlerIter = CSettlerMgr::operator[](iSettlerIdIter);
    if ( IEntity::FlagBits(rSettlerIter, ENTITY_FLAG_Selectable) )
    {
      iIdx = IEntity::WorldIdx();
      if ( CWorldManager::SectorId(iIdx) == iBuildingSector )
      {
        iBuildingY = IEntity::Y(rBuilding);
        v12 = iBuildingY - IEntity::Y(rSettlerIter);
        iBuildingX = IEntity::X(rBuilding);
        iEntityX = IEntity::X(rSettlerIter);
        iDistance = Grid::Distance(iBuildingX - iEntityX, v12);
        if ( iDistance < _iMaxDistance && iDistance < iSmallestDistance )
        {
          iSmallestDistance = iDistance;
          iNearestFreeSoldierId = iSettlerIdIter;
        }
      }
    }
    v9 = CSettlerMgr::operator[](iSettlerIdIter);
    iSettlerIdIter = IAnimatedEntity::Next(v9);
  }
  if ( !iNearestFreeSoldierId )
    return 0;
  v10 = CSettlerMgr::operator[](iNearestFreeSoldierId);
  IEntity::ClearFlagBits(v10, ENTITY_FLAG_Selectable);
  if ( iOwnerId == CPlayerManager::GetLocalPlayerId() )
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, iNearestFreeSoldierId);
  rSettler = CSettlerMgr::operator[](iNearestFreeSoldierId);
  IEntity::RemoveFromAllGroups();
  CSettler::AttachToBuilding(rSettler, _iBuildingId);
  v15 = CEntityEvent::CEntityEvent(&cEvent, 1u, 0, _iBuildingId, 0, 0);
  exceptionBlock = 0;
  rSettler->SetEvent(rSettler, v15);
  exceptionBlock = -1;
  CEntityEvent::~CEntityEvent(&cEvent);
  return iNearestFreeSoldierId;
}


// address=[0x1583190]
// Decompiled from int __thiscall CSettlerMgr::OrderAIWarrior(CSettlerMgr *this, int _iBuildingId, int _iWarriorType)
int  CSettlerMgr::OrderAIWarrior(int _iBuildingId, int _iWarriorType) {
  
  int v4; // eax
  int v5; // eax
  CEntityEvent cEvent; // [esp+4h] [ebp-50h] BYREF
  struct CEntityEvent *v8; // [esp+20h] [ebp-34h] MAPDST
  int v9; // [esp+24h] [ebp-30h]
  int v10; // [esp+28h] [ebp-2Ch]
  int iBuildingOwnerId; // [esp+2Ch] [ebp-28h]
  int iOwnerId; // [esp+34h] [ebp-20h]
  CAIEntityInfo *pAIEntityInfo; // [esp+38h] [ebp-1Ch]
  CBuilding *pBuilding; // [esp+3Ch] [ebp-18h]
  int iTargetId; // [esp+40h] [ebp-14h]
  CSettler *pSettler; // [esp+44h] [ebp-10h]
  int exceptionBlock; // [esp+50h] [ebp-4h]

  pBuilding = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, _iBuildingId);
  if ( !pBuilding )
    return 0;
  pAIEntityInfo = IEntity::AIEntityInfoPtr((IEntity *)pBuilding);
  if ( !pAIEntityInfo )
    return 0;
  iTargetId = CAIEntityInfo::TargetId(pAIEntityInfo);
  if ( iTargetId <= 0 )
    return 0;
  pSettler = CSettlerMgr::GetSettlerPtr(this, iTargetId);
  if ( !pSettler
    || IEntity::FlagBits(pSettler, ENTITY_FLAG_Ready|ENTITY_FLAG_ON_BOARD|ENTITY_FLAG_Selectable) != (ENTITY_FLAG_Ready|ENTITY_FLAG_Selectable)
    || IEntity::WarriorType(pSettler) != AI_WARRIOR_TYPE_SWORDMAN
    && IEntity::WarriorType(pSettler) != AI_WARRIOR_TYPE_BOWMAN )
  {
    goto LABEL_18;
  }
  if ( IEntity::WarriorType(pSettler) != _iWarriorType )
    return 0;
  iBuildingOwnerId = IEntity::OwnerId((IEntity *)pBuilding);
  iOwnerId = IEntity::OwnerId(pSettler);
  if ( iBuildingOwnerId == iOwnerId
    && (v4 = CBuilding::EnsignWorldIdx(pBuilding),
        v10 = ITiling::SectorId(v4),
        v5 = IEntity::WorldIdx(),
        v9 = ITiling::SectorId(v5),
        v10 == v9) )
  {
    IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_Selectable);
    if ( iOwnerId == CPlayerManager::GetLocalPlayerId() )
      CInputProcessor::DeSelectEntity(&g_cInputProcessor, iTargetId);
    IEntity::RemoveFromAllGroups();
    CSettler::AttachToBuilding(pSettler, _iBuildingId);
    v8 = CEntityEvent::CEntityEvent(&cEvent, 1u, 0, _iBuildingId, 0, 0);
    exceptionBlock = 0;
    pSettler->SetEvent(pSettler, v8);
    exceptionBlock = -1;
    CEntityEvent::~CEntityEvent(&cEvent);
    return iTargetId;
  }
  else
  {
LABEL_18:
    BBSupportTracePrintF(0, "CSettlerMgr::OrderAIWarrior(): Invalid settler id %i!", iTargetId);
    return 0;
  }
}


// address=[0x1583370]
// Decompiled from int __thiscall CSettlerMgr::OrderSpecialist(CSettlerMgr *this, int a2, int _iSettlerType)
int  CSettlerMgr::OrderSpecialist(int a2, int _iSettlerType) {
  
  int v4; // eax
  int iIdx; // eax
  int v6; // esi
  int iWheelerX; // esi
  int iX; // eax
  int v9; // [esp-4h] [ebp-60h]
  CEntityEvent cEvent; // [esp+8h] [ebp-54h] BYREF
  CEntityEvent *v12; // [esp+24h] [ebp-38h] MAPDST
  int iShortestDistance; // [esp+2Ch] [ebp-30h]
  unsigned int iDistance; // [esp+30h] [ebp-2Ch]
  int iSectorId; // [esp+34h] [ebp-28h]
  CSettler *v17; // [esp+38h] [ebp-24h]
  int iOwnerId; // [esp+3Ch] [ebp-20h]
  int iSettlerIdIter; // [esp+40h] [ebp-1Ch]
  int iClosestSettlerId; // [esp+44h] [ebp-18h]
  IEntity *rSettlerIter; // [esp+48h] [ebp-14h]
  IEntity *pWheeler; // [esp+4Ch] [ebp-10h]
  int v23; // [esp+58h] [ebp-4h]

  if ( CSettlerMgr::SettlerWarriorType(_iSettlerType) != AI_WARRIOR_TYPE_MISC_UNIT
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1363,
         "SettlerWarriorType(_iSettlerType) == WARRIOR_TYPE_MISC_UNIT") == 1 )
  {
    __debugbreak();
  }
  iShortestDistance = 4294967295;
  pWheeler = CVehicleMgr::GetVehiclePtr(a2);
  if ( !pWheeler && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1369, "pWheeler!= NULL") == 1 )
    __debugbreak();
  if ( !pWheeler )
    return 0;
  v4 = IEntity::WorldIdx();
  iSectorId = CWorldManager::SectorId(v4);
  if ( !iSectorId && BBSupportDbgReportF(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1376, "Stand on sector 0!") == 1 )
    __debugbreak();
  iOwnerId = IEntity::OwnerId(pWheeler);
  if ( !iOwnerId && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1379, "iOwnerId != 0") == 1 )
    __debugbreak();
  iSettlerIdIter = CSettlerMgr::GetFirstSettlerId(this, iOwnerId, _iSettlerType);
  iClosestSettlerId = 0;
  while ( iSettlerIdIter )
  {
    rSettlerIter = CSettlerMgr::operator[](iSettlerIdIter);
    if ( IEntity::FlagBits(rSettlerIter, ENTITY_FLAG_Selectable) )
    {
      iIdx = IEntity::WorldIdx();
      if ( CWorldManager::SectorId(iIdx) == iSectorId )
      {
        v6 = IEntity::Y(pWheeler);
        v9 = v6 - IEntity::Y(rSettlerIter);
        iWheelerX = IEntity::X(pWheeler);
        iX = IEntity::X(rSettlerIter);
        iDistance = Grid::Distance(iWheelerX - iX, v9);
        if ( iDistance < iShortestDistance )
        {
          iShortestDistance = iDistance;
          iClosestSettlerId = iSettlerIdIter;
        }
      }
    }
    iSettlerIdIter = IAnimatedEntity::Next(rSettlerIter);
  }
  if ( !iClosestSettlerId )
    return 0;
  v17 = CSettlerMgr::operator[](iClosestSettlerId);
  IEntity::ClearFlagBits(v17, ENTITY_FLAG_Selectable);
  if ( iOwnerId == CPlayerManager::GetLocalPlayerId() )
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, iClosestSettlerId);
  v12 = CEntityEvent::CEntityEvent(&cEvent, 0x18u, 0, a2, 0, 0);
  v23 = 0;
  v17->SetEvent(v17, v12);
  v23 = -1;
  CEntityEvent::~CEntityEvent(&cEvent);
  return iClosestSettlerId;
}


// address=[0x15835e0]
// Decompiled from void __thiscall CSettlerMgr::OrderWarriorToTower(CSettlerMgr *this, int _iBuildingId, int _iSettlerId)
void  CSettlerMgr::OrderWarriorToTower(int _iBuildingId, int _iSettlerId) {
  
  int v3; // esi
  CEntityEvent cEvent; // [esp+8h] [ebp-34h] BYREF
  struct CEntityEvent *v6; // [esp+24h] [ebp-18h] MAPDST
  CSettler *pSettler; // [esp+2Ch] [ebp-10h]
  int exceptionBlock; // [esp+38h] [ebp-4h]

  if ( _iBuildingId <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1223, "_iBuildingId > 0") == 1 )
    __debugbreak();
  if ( _iSettlerId <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1224, "_iSettlerId > 0") == 1 )
    __debugbreak();
  pSettler = CSettlerMgr::GetSettlerPtr(this, _iSettlerId);
  if ( !pSettler && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1228, "pSettler != 0") == 1 )
    __debugbreak();
  IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_Selectable);
  v3 = IEntity::OwnerId(pSettler);
  if ( v3 == CPlayerManager::GetLocalPlayerId() )
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, _iSettlerId);
  IEntity::RemoveFromAllGroups();
  CSettler::AttachToBuilding(pSettler, _iBuildingId);
  v6 = CEntityEvent::CEntityEvent(&cEvent, 1u, 0, _iBuildingId, 0, 0);
  exceptionBlock = 0;
  pSettler->SetEvent(pSettler, v6);
  exceptionBlock = -1;
  CEntityEvent::~CEntityEvent(&cEvent);
}


// address=[0x1583730]
// Decompiled from void __cdecl CSettlerMgr::FillSettlerAmount(struct CInfoExchange *_pInfoExchange, bool a2, bool _bInEcoSector)
void __cdecl CSettlerMgr::FillSettlerAmount(class CInfoExchange * _pInfoExchange, bool a2, bool _bInEcoSector) {
  
  int v3; // [esp+8h] [ebp-64h]
  int v4; // [esp+Ch] [ebp-60h]
  unsigned int iEventId; // [esp+10h] [ebp-5Ch]
  int NrOfStrikingCarriersInEcoSector; // [esp+18h] [ebp-54h]
  int v7; // [esp+1Ch] [ebp-50h]
  int v8; // [esp+20h] [ebp-4Ch]
  int LocalPlayerEcoSectorIdAtCenter; // [esp+28h] [ebp-44h]
  CEcoSector *v10; // [esp+2Ch] [ebp-40h]
  int i; // [esp+30h] [ebp-3Ch]
  S4_SETTLER_ENUM _iSettlerType; // [esp+34h] [ebp-38h]
  CSettlerStatisticInfo *pSettlerMenu; // [esp+38h] [ebp-34h]
  int LocalPlayerId; // [esp+3Ch] [ebp-30h]
  int iTotalCount; // [esp+40h] [ebp-2Ch]
  int iCountL1; // [esp+40h] [ebp-2Ch] MAPDST
  int iCountL12; // [esp+40h] [ebp-2Ch] MAPDST
  CEvn_Event v28; // [esp+44h] [ebp-28h] BYREF
  int v29; // [esp+68h] [ebp-4h]

  if ( !_pInfoExchange && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2033, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  pSettlerMenu = (CSettlerStatisticInfo *)j____RTDynamicCast(
                                            (void **)&_pInfoExchange->__vftable,
                                            0,
                                            &CInfoExchange__RTTI_Type_Descriptor_,
                                            &CSettlerStatisticInfo__RTTI_Type_Descriptor_,
                                            0);
  if ( !pSettlerMenu && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2037, "pSettlerMenu != 0") == 1 )
    __debugbreak();
  if ( pSettlerMenu )
  {
    pSettlerMenu->m_bInEcoSector = _bInEcoSector;
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    LocalPlayerEcoSectorIdAtCenter = 0;
    v10 = 0;
    if ( _bInEcoSector )
    {
      LocalPlayerEcoSectorIdAtCenter = CEcoSectorMgr::GetLocalPlayerEcoSectorIdAtCenter();
      if ( LocalPlayerEcoSectorIdAtCenter <= 0 )
        v8 = 0;
      else
        v8 = CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, LocalPlayerEcoSectorIdAtCenter);
      v10 = (CEcoSector *)v8;
    }
    for ( i = 0; i < SETTLER_MEDIC_02; ++i )
    {
      _iSettlerType = pSettlerMenu->m_vSettlerCounts[i].m_iSettlerType;
      if ( _iSettlerType )
      {
        iTotalCount = 0;
        switch ( _iSettlerType )
        {
          case SETTLER_SWORDSMAN_01:
          case SETTLER_SWORDSMAN_02:
          case SETTLER_SWORDSMAN_03:
            iCountL1 = CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_SWORDSMAN_01);
            iCountL12 = iCountL1 + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_SWORDSMAN_02);
            iTotalCount = iCountL12
                        + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_SWORDSMAN_03);
            break;
          case SETTLER_BOWMAN_01:
          case SETTLER_BOWMAN_02:
          case SETTLER_BOWMAN_03:
            iCountL1 = CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_BOWMAN_01);
            iCountL12 = iCountL1 + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_BOWMAN_02);
            iTotalCount = iCountL12 + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_BOWMAN_03);
            break;
          case SETTLER_MEDIC_01:
          case SETTLER_MEDIC_02:
          case SETTLER_MEDIC_03:
            iCountL1 = CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_MEDIC_01);
            iCountL12 = iCountL1 + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_MEDIC_02);
            iTotalCount = iCountL12 + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_MEDIC_03);
            break;
          case SETTLER_AXEWARRIOR_01:
          case SETTLER_AXEWARRIOR_02:
          case SETTLER_AXEWARRIOR_03:
            iCountL1 = CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_AXEWARRIOR_01);
            iCountL12 = iCountL1
                      + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_AXEWARRIOR_02);
            iTotalCount = iCountL12
                        + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_AXEWARRIOR_03);
            break;
          case SETTLER_BLOWGUNWARRIOR_01:
          case SETTLER_BLOWGUNWARRIOR_02:
          case SETTLER_BLOWGUNWARRIOR_03:
            iCountL1 = CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_BLOWGUNWARRIOR_01);
            iCountL12 = iCountL1
                      + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_BLOWGUNWARRIOR_02);
            iTotalCount = iCountL12
                        + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_BLOWGUNWARRIOR_03);
            break;
          case SETTLER_BACKPACKCATAPULTIST_01:
          case SETTLER_BACKPACKCATAPULTIST_02:
          case SETTLER_BACKPACKCATAPULTIST_03:
            iCountL1 = CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_BACKPACKCATAPULTIST_01);
            iCountL12 = iCountL1
                      + CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_BACKPACKCATAPULTIST_02);
            iTotalCount = iCountL12
                        + CSettlerMgr::GetNumberOfSettlers(
                            &g_cSettlerMgr,
                            LocalPlayerId,
                            SETTLER_BACKPACKCATAPULTIST_03);
            break;
          default:
            v4 = CSettlerMgr::SettlerWarriorType(_iSettlerType);
            if ( !_bInEcoSector || v4 )
            {
              iTotalCount = CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, _iSettlerType);
            }
            else if ( v10 )
            {
              iTotalCount = CEcoSector::NrOfSettler(v10, _iSettlerType);
            }
            break;
        }
        pSettlerMenu->m_vSettlerCounts[i].m_iCount = iTotalCount;
      }
    }
    pSettlerMenu->m_iCurrentTotalBeds = CEcoSectorMgr::GetNrOfCurrentTotalBeds((CEcoSectorMgr *)g_cESMgr, LocalPlayerId);
    pSettlerMenu->m_iCurrentFreeBeds = CEcoSectorMgr::GetNrOfInitialFreeBeds((CEcoSectorMgr *)g_cESMgr, LocalPlayerId);
    pSettlerMenu->m_iBedDifference = pSettlerMenu->m_iCurrentTotalBeds - pSettlerMenu->m_iCurrentFreeBeds;
    v3 = CSettlerMgr::GetNumberOfSettlers(&g_cSettlerMgr, LocalPlayerId, SETTLER_CARRIER);
    pSettlerMenu->m_iStrikingSettlers = CEcoSectorMgr::GetNrStrikingCarriers((CEcoSectorMgr *)g_cESMgr, LocalPlayerId);
    pSettlerMenu->m_iWorkingSettlers = v3 - pSettlerMenu->m_iStrikingSettlers;
    if ( _bInEcoSector )
    {
      if ( v10 )
        v7 = CEcoSector::NrOfSettler(v10, SETTLER_CARRIER);
      else
        v7 = 0;
      if ( LocalPlayerEcoSectorIdAtCenter <= 0 )
        NrOfStrikingCarriersInEcoSector = 0;
      else
        NrOfStrikingCarriersInEcoSector = CEcoSectorMgr::GetNrOfStrikingCarriersInEcoSector(
                                            (CEcoSectorMgr *)g_cESMgr,
                                            LocalPlayerEcoSectorIdAtCenter);
      pSettlerMenu->m_iStrikingSettlersInSector = NrOfStrikingCarriersInEcoSector;
      pSettlerMenu->m_iWorkingSettlersInSector = v7 - NrOfStrikingCarriersInEcoSector;
    }
    else
    {
      pSettlerMenu->m_iStrikingSettlersInSector = pSettlerMenu->m_iStrikingSettlers;
      pSettlerMenu->m_iWorkingSettlersInSector = pSettlerMenu->m_iWorkingSettlers;
    }
    pSettlerMenu->m_iUnknown = 29;
    iEventId = 604;
    if ( !a2 )
      iEventId = 602;
    CEvn_Event::CEvn_Event(&v28, iEventId, 0, (unsigned int)pSettlerMenu, 0);
    v29 = 0;
    if ( !g_pEvnEngine
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2186, "g_pEvnEngine != NULL") == 1 )
    {
      __debugbreak();
    }
    if ( g_pEvnEngine )
      IEventEngine::SendAMessage(g_pEvnEngine, &v28);
    v29 = -1;
    CEvn_Event::~CEvn_Event(&v28);
  }
}


// address=[0x1583c60]
// Decompiled from void __cdecl CSettlerMgr::FillFreeCarrier(CFreeCarrierInfo *_pInfoExchange, char a2)
void __cdecl CSettlerMgr::FillFreeCarrier(class CInfoExchange * _pInfoExchange, bool a2, bool a3) {
  
  int LocalPlayerId; // [esp+4h] [ebp-40h]
  unsigned int iEventId; // [esp+8h] [ebp-3Ch]
  int UserESInMiddleOfTheScreen; // [esp+Ch] [ebp-38h]
  CEcoSector *rEcoSector; // [esp+10h] [ebp-34h]
  bool bInOwnedES; // [esp+15h] [ebp-2Fh]
  CEvn_Event cEvent; // [esp+1Ch] [ebp-28h] BYREF
  int exceptionBlock; // [esp+40h] [ebp-4h]

  if ( !_pInfoExchange && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2304, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(
          (void **)&_pInfoExchange->__vftable,
          0,
          &CInfoExchange__RTTI_Type_Descriptor_,
          &CFreeCarrierInfo__RTTI_Type_Descriptor_,
          0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         2305,
         "dynamic_cast<CFreeCarrierInfo*>(_pInfoExchange) != 0") == 1 )
  {
    __debugbreak();
  }
  _pInfoExchange->Clear(_pInfoExchange);
  bInOwnedES = 0;
  UserESInMiddleOfTheScreen = CSettlerMgr::GetUserESInMiddleOfTheScreen();
  if ( UserESInMiddleOfTheScreen )
  {
    rEcoSector = CEcoSectorMgr::operator[](g_cESMgr, UserESInMiddleOfTheScreen);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    if ( CEcoSector::Owner(rEcoSector) == LocalPlayerId )
    {
      _pInfoExchange->m_uNrOfSettlers = CEcoSector::NrOfSettler(rEcoSector, SETTLER_CARRIER);
      _pInfoExchange->m_uNrOfCarriers = CEcoSector::MinCarrier(rEcoSector);
      _pInfoExchange->m_uNrOfNonCarriers = _pInfoExchange->m_uNrOfSettlers - _pInfoExchange->m_uNrOfCarriers;
      _pInfoExchange->m_uNrOfDigger = CEcoSector::NrOfSettler(rEcoSector, SETTLER_DIGGER);
      _pInfoExchange->m_uNrOfFreeDigger = CEcoSector::WorkerDeltaAmount(rEcoSector, SETTLER_DIGGER);
      _pInfoExchange->m_bHasShovels = CEcoSector::NrOfGoods(rEcoSector, GOOD_SHOVEL) > 0;
      _pInfoExchange->m_uNrOfShovels = CEcoSector::NrOfGoods(rEcoSector, GOOD_SHOVEL);
      _pInfoExchange->m_uNrOfBuilders = CEcoSector::NrOfSettler(rEcoSector, SETTLER_BUILDER);
      _pInfoExchange->m_uNrOfFreeBuilders = CEcoSector::WorkerDeltaAmount(rEcoSector, SETTLER_BUILDER);
      _pInfoExchange->m_bHasHammers = CEcoSector::NrOfGoods(rEcoSector, GOOD_HAMMER) > 0;
      _pInfoExchange->m_uNrOfHammers = CEcoSector::NrOfGoods(rEcoSector, GOOD_HAMMER);
      _pInfoExchange->m_bLooksAtEcoSector = 1;
      bInOwnedES = 1;
    }
  }
  if ( !bInOwnedES )
  {
    _pInfoExchange->m_uNrOfSettlers = 0;
    _pInfoExchange->m_uNrOfCarriers = 0;
    _pInfoExchange->m_uNrOfNonCarriers = 0;
    _pInfoExchange->m_uNrOfDigger = 0;
    _pInfoExchange->m_uNrOfFreeDigger = 0;
    _pInfoExchange->m_bHasShovels = 0;
    _pInfoExchange->m_uNrOfBuilders = 0;
    _pInfoExchange->m_uNrOfFreeBuilders = 0;
    _pInfoExchange->m_bHasHammers = 0;
    _pInfoExchange->m_bLooksAtEcoSector = 0;
  }
  _pInfoExchange->m_iUnknown = 31;
  iEventId = 604;
  if ( !a2 )
    iEventId = 602;
  CEvn_Event::CEvn_Event(&cEvent, iEventId, 0, (unsigned int)_pInfoExchange, 0);
  exceptionBlock = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2377, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &cEvent);
  exceptionBlock = -1;
  CEvn_Event::~CEvn_Event(&cEvent);
}


// address=[0x1583f30]
// Decompiled from void __cdecl CSettlerMgr::FillSpecialistProduction(CSettlerProductionInfo *pInfoExchange, bool a2, bool a3)
void __cdecl CSettlerMgr::FillSpecialistProduction(class CInfoExchange * pInfoExchange, bool a2, bool a3) {
  
  int v3; // esi
  DWORD v4; // eax
  CSettlerMgr::SSettlerInfos *rInfo; // eax
  unsigned int v6; // [esp+Ch] [ebp-64h]
  int v7; // [esp+10h] [ebp-60h]
  int bUserESInMiddleOfTheScreen; // [esp+14h] [ebp-5Ch]
  int LocalPlayerId; // [esp+18h] [ebp-58h]
  S4_SETTLER_ENUM iType; // [esp+1Ch] [ebp-54h]
  int j; // [esp+20h] [ebp-50h]
  CEcoSector *pEcoSector; // [esp+24h] [ebp-4Ch]
  int i; // [esp+28h] [ebp-48h]
  char bInOwnedES; // [esp+2Eh] [ebp-42h]
  CEvn_Event v15; // [esp+34h] [ebp-3Ch] BYREF
  _DWORD vSpecialists[5]; // [esp+4Ch] [ebp-24h]
  int v17; // [esp+6Ch] [ebp-4h]

  if ( !pInfoExchange && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2206, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(
          (void **)&pInfoExchange->__vftable,
          0,
          &CInfoExchange__RTTI_Type_Descriptor_,
          &CSettlerProductionInfo__RTTI_Type_Descriptor_,
          0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         2207,
         "dynamic_cast<CSettlerProductionInfo*>(_pInfoExchange) != 0") == 1 )
  {
    __debugbreak();
  }
  pInfoExchange->Clear(pInfoExchange);
  bInOwnedES = 0;
  vSpecialists[0] = SETTLER_THIEF;
  vSpecialists[1] = SETTLER_GARDENER;
  vSpecialists[2] = SETTLER_GEOLOGIST;
  vSpecialists[3] = SETTLER_SABOTEUR;
  vSpecialists[4] = SETTLER_PIONEER;
  bUserESInMiddleOfTheScreen = CSettlerMgr::GetUserESInMiddleOfTheScreen();
  if ( bUserESInMiddleOfTheScreen )
  {
    pEcoSector = CEcoSectorMgr::operator[](g_cESMgr, bUserESInMiddleOfTheScreen);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    if ( CEcoSector::Owner(pEcoSector) == LocalPlayerId )
    {
      v3 = CEcoSector::NrOfSettler(pEcoSector, SETTLER_CARRIER);
      pInfoExchange->m_iFreeCarriers = v3 - CEcoSector::MinCarrier(pEcoSector);
      if ( pInfoExchange->m_iFreeCarriers <= 0 )
        pInfoExchange->m_iFreeCarriers = 0;
      for ( i = 0; i < 5; ++i )
      {
        iType = vSpecialists[i];
        pInfoExchange->m_vSpecialist[i].m_iType = iType;
        pInfoExchange->m_vSpecialist[i].m_iCount = CSettlerMgr::GetNumberOfSettlers(
                                                     &g_cSettlerMgr,
                                                     LocalPlayerId,
                                                     iType);
        pInfoExchange->m_vSpecialist[i].m_iWished = CEcoSector::SpecialistWishes(pEcoSector, iType);
        v4 = CPlayerManager::Race(LocalPlayerId);
        rInfo = CSettlerMgr::GetSettlerInfo(v4, iType);
        v7 = CEcoSector::NrOfGoods(pEcoSector, (S4_GOOD_ENUM)rInfo->m_uTool);
        pInfoExchange->m_vSpecialist[i].m_bEnoughGoods = v7 > 0;
        pInfoExchange->m_vSpecialist[i].m_iFreeGoods = v7;
      }
      pInfoExchange->m_bInEcoSector = 1;
      bInOwnedES = 1;
    }
  }
  if ( !bInOwnedES )
  {
    pInfoExchange->m_iFreeCarriers = 0;
    for ( j = 0; j < 5; ++j )
    {
      pInfoExchange->m_vSpecialist[j].m_bEnoughGoods = 0;
      pInfoExchange->m_vSpecialist[j].m_bAvailable = 0;
    }
    pInfoExchange->m_bInEcoSector = 0;
  }
  pInfoExchange->m_iUnknown = 30;
  v6 = 604;
  if ( !a2 )
    v6 = 602;
  CEvn_Event::CEvn_Event(&v15, v6, 0, (unsigned int)pInfoExchange, 0);
  v17 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2284, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v15);
  v17 = -1;
  CEvn_Event::~CEvn_Event(&v15);
}


// address=[0x1584240]
// Decompiled from _DWORD *__cdecl CSettlerMgr::FillSoldierMenu(CSoldierInfo *_pInfoExchange, char a2)
void __cdecl CSettlerMgr::FillSoldierMenu(class CInfoExchange * _pInfoExchange, bool a2, bool a3) {
  
  unsigned __int16 *v2; // eax
  int v4; // [esp+4h] [ebp-64h]
  int v5; // [esp+8h] [ebp-60h]
  int iSelectionSize; // [esp+10h] [ebp-58h]
  unsigned int iEventId; // [esp+14h] [ebp-54h]
  std::vector *pSelection; // [esp+18h] [ebp-50h]
  int LocalPlayerId; // [esp+1Ch] [ebp-4Ch]
  int iMaxLifePoints; // [esp+20h] [ebp-48h]
  int iHitpoints; // [esp+24h] [ebp-44h]
  int a1; // [esp+2Ch] [ebp-3Ch]
  CSettler *SettlerPtr; // [esp+30h] [ebp-38h]
  int iType; // [esp+34h] [ebp-34h]
  CSoldierInfo::SSoldier *v15; // [esp+3Ch] [ebp-2Ch]
  CEvn_Event cEvent; // [esp+40h] [ebp-28h] BYREF
  int exceptionBlock; // [esp+64h] [ebp-4h]

  if ( !_pInfoExchange && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2397, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(
          (void **)&_pInfoExchange->__vftable,
          0,
          &CInfoExchange__RTTI_Type_Descriptor_,
          &CSoldierInfo__RTTI_Type_Descriptor_,
          0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         2398,
         "dynamic_cast<CSoldierInfo*>(_pInfoExchange) != 0") == 1 )
  {
    __debugbreak();
  }
  _pInfoExchange->Clear(_pInfoExchange);
  pSelection = CInputProcessor::Selection();
  iSelectionSize = std::vector<unsigned short>::size(pSelection);
  for ( a1 = 0; a1 < iSelectionSize; ++a1 )
  {
    v2 = std::vector<unsigned short>::operator[](a1);
    SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, *v2);
    if ( SettlerPtr )
    {
      iType = IEntity::Type(SettlerPtr);
      v15 = 0;
      switch ( iType )
      {
        case SETTLER_SWORDSMAN_01:
        case SETTLER_SWORDSMAN_02:
        case SETTLER_SWORDSMAN_03:              // iType-29
          v15 = (CSoldierInfo::SSoldier *)((char *)&_pInfoExchange[-2] + 12 * iType - 36);// v15 = _pInfoExchange.m_vSoldiers[iType-29];
          break;
        case SETTLER_BOWMAN_01:
        case SETTLER_BOWMAN_02:
        case SETTLER_BOWMAN_03:                 // iType-29 / 3,4,5
          v15 = (CSoldierInfo::SSoldier *)((char *)&_pInfoExchange[-2] + 12 * iType - 36);
          break;
        case SETTLER_MEDIC_01:
        case SETTLER_MEDIC_02:
        case SETTLER_MEDIC_03:                  // iType-29 / 6,7,8
          v15 = (CSoldierInfo::SSoldier *)((char *)&_pInfoExchange[-2] + 12 * iType - 36);
          break;
        case SETTLER_AXEWARRIOR_01:
        case SETTLER_AXEWARRIOR_02:
        case SETTLER_AXEWARRIOR_03:             // iType-32 / 6,7,8
          v15 = &_pInfoExchange[-3].m_vSoldiers[iType + 6];
          break;
        case SETTLER_BLOWGUNWARRIOR_01:
        case SETTLER_BLOWGUNWARRIOR_02:
        case SETTLER_BLOWGUNWARRIOR_03:         // iType-35 / 6,7,8
          v15 = (CSoldierInfo::SSoldier *)((char *)&_pInfoExchange[-2] + 12 * iType - 108);
          break;
        case SETTLER_SQUADLEADER:
          v15 = &_pInfoExchange->m_vSoldiers[9];
          break;
        case SETTLER_PRIEST:
          v15 = &_pInfoExchange->m_vSoldiers[10];
          break;
        case SETTLER_BACKPACKCATAPULTIST_01:
        case SETTLER_BACKPACKCATAPULTIST_02:
        case SETTLER_BACKPACKCATAPULTIST_03:    // iType - 55 / 6,7,8
          v15 = (CSoldierInfo::SSoldier *)((char *)&_pInfoExchange[-4] + 0xC * iType - 44);
          break;
        default:
          break;
      }
      if ( v15 )
      {
        v4 = IEntity::Race(SettlerPtr);
        v5 = IEntity::Type(SettlerPtr);
        iMaxLifePoints = CSettlerMgr::GetSettlerInfo(v4, v5)->m_iMaxLifePoints;
        iHitpoints = IEntity::Hitpoints(SettlerPtr);
        if ( iHitpoints > iMaxLifePoints )
          iHitpoints = iMaxLifePoints;
        v15->m_iTotalHitpoints += iHitpoints;
        v15->m_iTotalDamage += iMaxLifePoints - iHitpoints;
        ++v15->m_iCount;
      }
    }
  }
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  _pInfoExchange->m_iOffenceStrength = CStatistic::OffenceStrength100(&g_cStatistic, LocalPlayerId);
  _pInfoExchange->m_iDefenceStrength = CStatistic::DefenceStrength100(&g_cStatistic, LocalPlayerId);
  _pInfoExchange->m_iMana = CStatistic::GetMana(&g_cStatistic, LocalPlayerId);
  _pInfoExchange->m_iUnknown = 18;
  iEventId = 604;
  if ( !a2 )
    iEventId = 602;
  CEvn_Event::CEvn_Event(&cEvent, iEventId, 0, (unsigned int)_pInfoExchange, 0);
  exceptionBlock = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2529, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &cEvent);
  exceptionBlock = -1;
  return CEvn_Event::~CEvn_Event(&cEvent);
}


// address=[0x15845d0]
// Decompiled from _DWORD *__cdecl CSettlerMgr::FillSpecialistMenu(CSpecialistsInfo *_pInfoExchange, char a2)
void __cdecl CSettlerMgr::FillSpecialistMenu(class CInfoExchange * _pInfoExchange, bool a2, bool a3) {
  
  unsigned __int16 *v2; // eax
  int v4; // [esp+4h] [ebp-60h]
  int v5; // [esp+8h] [ebp-5Ch]
  int iSelectionSize; // [esp+14h] [ebp-50h]
  unsigned int v7; // [esp+18h] [ebp-4Ch]
  std::vector *pSelection; // [esp+1Ch] [ebp-48h]
  int m_iMaxLifePoints; // [esp+20h] [ebp-44h]
  int v10; // [esp+24h] [ebp-40h]
  int i; // [esp+2Ch] [ebp-38h]
  CSettler *SettlerPtr; // [esp+30h] [ebp-34h]
  CSpecialistsInfo::SSpecialist *m_vSpecialists; // [esp+38h] [ebp-2Ch]
  CEvn_Event v14; // [esp+3Ch] [ebp-28h] BYREF
  int v15; // [esp+60h] [ebp-4h]

  if ( !_pInfoExchange && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2550, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(
          (void **)&_pInfoExchange->__vftable,
          0,
          &CInfoExchange__RTTI_Type_Descriptor_,
          &CSpecialistsInfo__RTTI_Type_Descriptor_,
          0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         2551,
         "dynamic_cast<CSpecialistsInfo*>(_pInfoExchange) != 0") == 1 )
  {
    __debugbreak();
  }
  _pInfoExchange->Clear(_pInfoExchange);
  pSelection = CInputProcessor::Selection();
  iSelectionSize = std::vector<unsigned short>::size(pSelection);
  for ( i = 0; i < iSelectionSize; ++i )
  {
    v2 = std::vector<unsigned short>::operator[](i);
    SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, *v2);
    if ( SettlerPtr )
    {
      m_vSpecialists = 0;
      switch ( IEntity::Type(SettlerPtr) )
      {
        case SETTLER_SABOTEUR:
          m_vSpecialists = &_pInfoExchange->m_vSpecialists[2];
          break;
        case SETTLER_PIONEER:
          m_vSpecialists = &_pInfoExchange->m_vSpecialists[3];
          break;
        case SETTLER_THIEF:
          m_vSpecialists = &_pInfoExchange->m_vSpecialists[4];
          break;
        case SETTLER_GEOLOGIST:
          m_vSpecialists = &_pInfoExchange->m_vSpecialists[1];
          break;
        case SETTLER_GARDENER:
          m_vSpecialists = _pInfoExchange->m_vSpecialists;
          break;
        default:
          break;
      }
      if ( m_vSpecialists )
      {
        v4 = IEntity::Race(SettlerPtr);
        v5 = IEntity::Type(SettlerPtr);
        m_iMaxLifePoints = CSettlerMgr::GetSettlerInfo(v4, v5)->m_iMaxLifePoints;
        v10 = IEntity::Hitpoints(SettlerPtr);
        if ( v10 > m_iMaxLifePoints )
          v10 = m_iMaxLifePoints;
        m_vSpecialists->m_iHitpoints += v10;
        m_vSpecialists->m_iDamageTaken += m_iMaxLifePoints - v10;
        ++m_vSpecialists->m_iCount;
      }
    }
  }
  _pInfoExchange->m_iUnknown = 19;
  v7 = 604;
  if ( !a2 )
    v7 = 602;
  CEvn_Event::CEvn_Event(&v14, v7, 0, (unsigned int)_pInfoExchange, 0);
  v15 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2635, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v14);
  v15 = -1;
  return CEvn_Event::~CEvn_Event(&v14);
}


// address=[0x1584870]
// Decompiled from void __thiscall CSettlerMgr::Store(CSettlerMgr *this, struct S4::CMapFile *a2)
void  CSettlerMgr::Store(class S4::CMapFile & a2) {
  
  char *v2; // eax
  int v3; // [esp+0h] [ebp-334h] BYREF
  std::ostrstream stream; // [esp+10h] [ebp-324h] BYREF
  size_t Size; // [esp+BCh] [ebp-278h]
  void *Src; // [esp+C0h] [ebp-274h]
  CSettler *pSettler; // [esp+C4h] [ebp-270h] MAPDST
  int iLastUsedId; // [esp+D0h] [ebp-264h] MAPDST
  int iVersion; // [esp+D4h] [ebp-260h] BYREF
  int iSettlerCount; // [esp+E0h] [ebp-254h] BYREF
  int j; // [esp+E4h] [ebp-250h]
  int i; // [esp+E8h] [ebp-24Ch]
  int m; // [esp+F0h] [ebp-244h]
  int k; // [esp+F4h] [ebp-240h]
  int *v20; // [esp+324h] [ebp-10h]
  int exceptionBlock; // [esp+330h] [ebp-4h]

  v20 = &v3;
  std::ostrstream::ostrstream(stream.v4, 0, 0x40000LL, 2, 1);
  exceptionBlock = 0;
  stream.v4[42] = std::ios_base::exceptions((char *)&stream + *(_DWORD *)(stream.v4[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)&stream + *(_DWORD *)(stream.v4[0] + 4)), 6);
  LOBYTE(exceptionBlock) = 1;
  iVersion = 1;
  operator^<unsigned int>(&stream, &iVersion);
  iLastUsedId = CMapObjectMgr::LastUsedId();
  iSettlerCount = 0;
  for ( i = 1; i <= iLastUsedId; ++i )
  {
    if ( CSettlerMgr::GetSettlerPtr(this, i) )
      ++iSettlerCount;
  }
  operator^<unsigned int>(&stream, &iSettlerCount);
  for ( j = 1; j <= iLastUsedId; ++j )
  {
    pSettler = CSettlerMgr::GetSettlerPtr(this, j);
    if ( pSettler )
      pSettler->Store((int)&stream);
  }
  for ( k = 0; k < 9; ++k )
  {
    for ( m = 0; m < 67; ++m )
      operator^<int>(&stream, (int *)&this->m_vFirstSettlerId[k][m]);
  }
  for ( k = 0; k < 9; ++k )
  {
    for ( m = 0; m < 67; ++m )
      operator^<int>(&stream, &this->m_vPlayerSettlerNumber[k][m]);
  }
  for ( k = 0; k < 9; ++k )
  {
    for ( m = 0; m < SETTLER_MAX; ++m )
      operator^<int>(&stream, &this->m_vPlayerSettlerOfferedNumber[k][m]);
  }
  std::ostream::put(0);
  exceptionBlock = 0;
  std::ostrstream::freeze(&stream, 1);
  v2 = std::ostrstream::rdbuf(&stream);
  Size = std::strstreambuf::pcount((std::strstreambuf *)v2);
  Src = std::ostrstream::str(&stream);
  S4::CMapFile::SaveChunk(a2, 0xA1u, 0, Size, Src, 0);
  std::ostrstream::freeze(&stream, 0);
  exceptionBlock = -1;
  std::ostrstream::`vbase destructor'(&stream);
}


// address=[0x1584c80]
// Decompiled from void __thiscall CSettlerMgr::Load(CSettlerMgr *this, struct S4::CMapFile *a2)
void  CSettlerMgr::Load(class S4::CMapFile & a2) {
  
  int v2; // [esp+0h] [ebp-100h] BYREF
  _DWORD stream[44]; // [esp+10h] [ebp-F0h] BYREF
  unsigned int v4; // [esp+C0h] [ebp-40h]
  IEntity *v5; // [esp+C4h] [ebp-3Ch]
  IEntity *v6; // [esp+C8h] [ebp-38h]
  int v7; // [esp+CCh] [ebp-34h]
  int v8; // [esp+D0h] [ebp-30h] BYREF
  int a4; // [esp+D4h] [ebp-2Ch] BYREF
  unsigned int v10; // [esp+D8h] [ebp-28h] BYREF
  int pExceptionObject; // [esp+DCh] [ebp-24h] BYREF
  char *Str; // [esp+E0h] [ebp-20h]
  int j; // [esp+E8h] [ebp-18h]
  int i; // [esp+ECh] [ebp-14h]
  int *v16; // [esp+F0h] [ebp-10h]
  int v17; // [esp+FCh] [ebp-4h]

  v16 = &v2;
  CTrace::Print("CSettlerMgr load");
  CSettlerMgr::Clear(this);
  a4 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, MAP_CHUNK_SAVE_SETTLERS, 0, &a4, 0);
  if ( Str )
  {
    std::istrstream::istrstream(Str, 1);
    v17 = 0;
    v4 = std::ios_base::exceptions((char *)stream + *(_DWORD *)(stream[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)stream + *(_DWORD *)(stream[0] + 4)), 6);
    LOBYTE(v17) = 1;
    operator^<unsigned int>(stream, &v8);
    v7 = v8;
    if ( v8 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSettlerMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v10 = 0;
    operator^<unsigned int>(stream, &v10);
    for ( i = 0; i < v10; ++i )
    {
      v6 = (IEntity *)CPersistence::New((struct std::istream *)stream);
      v5 = v6;
      ++this->m_uTotalSettlers;
      IEntity::ClearFlagBits(v5, ENTITY_FLAG_Selected);
    }
    for ( i = 0; i < 9; ++i )
    {
      for ( j = 0; j < 67; ++j )
        operator^<int>((struct std::istream *)stream, (int *)&this->m_vFirstSettlerId[i][j]);
    }
    for ( i = 0; i < 9; ++i )
    {
      for ( j = 0; j < 67; ++j )
        operator^<int>((struct std::istream *)stream, &this->m_vPlayerSettlerNumber[i][j]);
    }
    for ( i = 0; i < 9; ++i )
    {
      for ( j = 0; j < 67; ++j )
        operator^<int>((struct std::istream *)stream, &this->m_vPlayerSettlerOfferedNumber[i][j]);
    }
    v17 = 0;
    std::ios_base::exceptions((std::ios_base *)((char *)stream + *(_DWORD *)(stream[0] + 4)), v4);
    v17 = -1;
    std::istrstream::`vbase destructor'((std::istrstream *)stream);
  }
}


// address=[0x1584f70]
// Decompiled from void __thiscall CSettlerMgr::IncNumberOfSettler(CSettlerMgr *this, int _iPlayerId, S4_SETTLER_ENUM _iSettlerType)
void  CSettlerMgr::IncNumberOfSettler(int _iPlayerId, int _iSettlerType) {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1036,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= SETTLER_NO_SETTLER || _iSettlerType >= SETTLER_MAX)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1037,
         "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++this->m_vPlayerSettlerNumber[_iPlayerId][_iSettlerType];
  CStatistic::AddSettler(&g_cStatistic, _iPlayerId, _iSettlerType);
}


// address=[0x1585020]
// Decompiled from void __thiscall CSettlerMgr::DecNumberOfSettler(CSettlerMgr *this, int _iPlayerId, S4_SETTLER_ENUM _iSettlerType)
void  CSettlerMgr::DecNumberOfSettler(int _iPlayerId, int _iSettlerType) {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1053,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= SETTLER_NO_SETTLER || _iSettlerType >= SETTLER_MAX)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1054,
         "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_vPlayerSettlerNumber[_iPlayerId][_iSettlerType] <= 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1056,
         "m_vPlayerSettlerNumber[_iPlayerId][_iSettlerType] > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_vPlayerSettlerNumber[_iPlayerId][_iSettlerType] > 0 )
    --this->m_vPlayerSettlerNumber[_iPlayerId][_iSettlerType];
  CStatistic::DecSettler(&g_cStatistic, _iPlayerId, _iSettlerType);
}


// address=[0x15889c0]
// Decompiled from CSettler *__thiscall CSettlerMgr::Settler(CSettlerMgr *this, int iSettlerId)
class CSettler &  CSettlerMgr::Settler(int iSettlerId) {
  
  CSettler *pEntity; // [esp+4h] [ebp-4h]

  pEntity = (CSettler *)CMapObjectMgr::EntityPtr(iSettlerId);
  if ( !pEntity
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         314,
         "pEntity != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::ObjType(pEntity) != SETTLER_OBJ
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         315,
         "pEntity->ObjType() == SETTLER_OBJ") == 1 )
  {
    __debugbreak();
  }
  return pEntity;
}


// address=[0x1592200]
// Decompiled from int __cdecl CSettlerMgr::GetSquadLeaderBonus256(int a1)
int __cdecl CSettlerMgr::GetSquadLeaderBonus256(int a1) {
  
  return CSettlerMgr::m_iSquadLeaderBoni256[a1];
}


// address=[0x15a7b80]
// Decompiled from int __cdecl CSettlerMgr::SettlerWarriorLevel(int a1)
int __cdecl CSettlerMgr::SettlerWarriorLevel(int a1) {
  
  if ( !CSettlerMgr::m_uSettlerWarriorLevels[SETTLER_SWORDSMAN_01]
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         359,
         "m_uSettlerWarriorLevels[SETTLER_SWORDSMAN_01] != 0") == 1 )
  {
    __debugbreak();
  }
  return CSettlerMgr::m_uSettlerWarriorLevels[a1];
}


// address=[0x1585120]
// Decompiled from void __thiscall CSettlerMgr::AttachSettler(CSettlerMgr *this, CSettler *_rSettler)
void  CSettlerMgr::AttachSettler(class CSettler & _rSettler) {
  
  CSettler *pOldHead; // [esp+0h] [ebp-18h]
  int iSettlerId; // [esp+4h] [ebp-14h]
  DWORD iOldHeadId; // [esp+8h] [ebp-10h]
  int iSettlerType; // [esp+10h] [ebp-8h]
  int iPlayerId; // [esp+14h] [ebp-4h]

  if ( IEntity::FlagBits(_rSettler, ENTITY_FLAG_Offered)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 806, "_rSettler.FlagBits(ENTITY_FLAG_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(_rSettler, ENTITY_FLAG_GlobalOffered)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         807,
         "_rSettler.FlagBits(ENTITY_FLAG_GLOBAL_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::Previous(_rSettler)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 808, "_rSettler.Previous() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::Next(_rSettler)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 809, "_rSettler.Next() == 0") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(_rSettler, ENTITY_FLAG_Offered);
  IEntity::SetFlagBits(_rSettler, ENTITY_FLAG_GlobalOffered);
  iPlayerId = IEntity::OwnerId(_rSettler);
  iSettlerId = IEntity::EntityId(_rSettler);
  iSettlerType = IEntity::Type(_rSettler);
  if ( iPlayerId < 1
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 818, "iPlayerId >= PLAYER_FIRST") == 1 )
  {
    __debugbreak();
  }
  if ( iPlayerId > 8
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 819, "iPlayerId <= PLAYER_LAST") == 1 )
  {
    __debugbreak();
  }
  if ( iSettlerId <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 820, "iSettlerId > 0") == 1 )
    __debugbreak();
  if ( iSettlerType <= 0
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 821, "iSettlerType > SETTLER_NO_SETTLER") == 1 )
  {
    __debugbreak();
  }
  if ( iSettlerType >= 67
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 822, "iSettlerType < SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  ++this->m_vPlayerSettlerOfferedNumber[iPlayerId][iSettlerType];
  iOldHeadId = this->m_vFirstSettlerId[iPlayerId][iSettlerType];
  if ( iOldHeadId == iSettlerId
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 828, "iOldHeadId != iSettlerId") == 1 )
  {
    __debugbreak();
  }
  this->m_vFirstSettlerId[iPlayerId][iSettlerType] = iSettlerId;
  IAnimatedEntity::SetPrevious(_rSettler, 0);
  IAnimatedEntity::SetNext(_rSettler, iOldHeadId);
  if ( iOldHeadId )
  {
    pOldHead = CSettlerMgr::GetSettlerPtr(this, iOldHeadId);
    if ( !pOldHead && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 839, "pOldHead != 0") == 1 )
      __debugbreak();
    if ( IAnimatedEntity::Previous(pOldHead) )
    {
      if ( BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 841, "pOldHead->Previous() == 0") == 1 )
        __debugbreak();
    }
    IAnimatedEntity::SetPrevious(pOldHead, iSettlerId);
  }
}


// address=[0x15853f0]
// Decompiled from int __thiscall CSettlerMgr::DetachSettler(struct CSettlerMgr *this, struct CSettler *_rSettler)
void  CSettlerMgr::DetachSettler(class CSettler & _rSettler) {
  
  CSettler *pNextSettler; // [esp+0h] [ebp-20h]
  int iPrevSettlerId; // [esp+4h] [ebp-1Ch]
  CSettler *pPrevSettler; // [esp+8h] [ebp-18h]
  int iSettlerId; // [esp+Ch] [ebp-14h]
  int iNextSettlerId; // [esp+10h] [ebp-10h]
  int iSettlerType; // [esp+18h] [ebp-8h]
  int iPlayerId; // [esp+1Ch] [ebp-4h]

  if ( IEntity::FlagBits(_rSettler, ENTITY_FLAG_Offered)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 889, "_rSettler.FlagBits(ENTITY_FLAG_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !IEntity::FlagBits(_rSettler, ENTITY_FLAG_GlobalOffered)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         890,
         "_rSettler.FlagBits(ENTITY_FLAG_GLOBAL_OFFERED) != 0") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(_rSettler, ENTITY_FLAG_GlobalOffered|ENTITY_FLAG_Offered);
  iPlayerId = IEntity::OwnerId(_rSettler);
  iSettlerId = IEntity::EntityId(_rSettler);
  iSettlerType = IEntity::Type(_rSettler);
  if ( iPlayerId < 1
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 898, "iPlayerId >= PLAYER_FIRST") == 1 )
  {
    __debugbreak();
  }
  if ( iPlayerId > 8
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 899, "iPlayerId <= PLAYER_LAST") == 1 )
  {
    __debugbreak();
  }
  if ( iSettlerId <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 900, "iSettlerId > 0") == 1 )
    __debugbreak();
  if ( iSettlerType <= 0
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 901, "iSettlerType > SETTLER_NO_SETTLER") == 1 )
  {
    __debugbreak();
  }
  if ( iSettlerType >= 67
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 902, "iSettlerType < SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_vPlayerSettlerOfferedNumber[iPlayerId][iSettlerType] <= 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         904,
         "m_vPlayerSettlerOfferedNumber[iPlayerId][iSettlerType] > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_vPlayerSettlerOfferedNumber[iPlayerId][iSettlerType] > 0 )
    --this->m_vPlayerSettlerOfferedNumber[iPlayerId][iSettlerType];
  iPrevSettlerId = IAnimatedEntity::Previous(_rSettler);
  iNextSettlerId = IAnimatedEntity::Next(_rSettler);
  if ( iPrevSettlerId )
  {
    pPrevSettler = CSettlerMgr::GetSettlerPtr(this, iPrevSettlerId);
    if ( !pPrevSettler && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 918, "pPrevSettler != 0") == 1 )
      __debugbreak();
    if ( IAnimatedEntity::Next(pPrevSettler) != iSettlerId
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 919, "pPrevSettler->Next() == iSettlerId") == 1 )
    {
      __debugbreak();
    }
    IAnimatedEntity::SetNext(pPrevSettler, iNextSettlerId);
  }
  else
  {
    if ( this->m_vFirstSettlerId[iPlayerId][iSettlerType] != iSettlerId
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerMgr.cpp",
           925,
           "m_vPlayerSettler[iPlayerId][iSettlerType] == iSettlerId") == 1 )
    {
      __debugbreak();
    }
    this->m_vFirstSettlerId[iPlayerId][iSettlerType] = iNextSettlerId;
  }
  if ( iNextSettlerId )
  {
    pNextSettler = CSettlerMgr::GetSettlerPtr(this, iNextSettlerId);
    if ( !pNextSettler && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 934, "pNextSettler != 0") == 1 )
      __debugbreak();
    if ( IAnimatedEntity::Previous(pNextSettler) != iSettlerId
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 935, "pNextSettler->Previous() == iSettlerId") == 1 )
    {
      __debugbreak();
    }
    IAnimatedEntity::SetPrevious(pNextSettler, iPrevSettlerId);
  }
  IAnimatedEntity::SetPrevious(_rSettler, 0);
  return IAnimatedEntity::SetNext(_rSettler, 0);
}


// address=[0x157ff60]
// Decompiled from uint __thiscall CSettlerMgr::Alloc(CSettlerMgr *this, uint a2)
void *  CSettlerMgr::Alloc(unsigned int a2) {
  
  return MemoryAllocator::allocate(&this->m_cAllocator, a2);
}


// address=[0x1580020]
// Decompiled from void __thiscall CSettlerMgr::Dealloc(CSettlerMgr *this, uint *a2)
void  CSettlerMgr::Dealloc(void * a2) {
  
  MemoryAllocator::deallocate(&this->m_cAllocator, a2);
}


// address=[0x1585740]
// Decompiled from void __thiscall CSettlerMgr::CheckOutSettler(CSettlerMgr *this, int _iSettlerId)
void  CSettlerMgr::CheckOutSettler(int _iSettlerId) {
  
  int v2; // eax
  int v3; // esi
  int iOwnerId; // [esp+4h] [ebp-20h]
  ISettlerRole *v5; // [esp+Ch] [ebp-18h]
  int v6; // [esp+10h] [ebp-14h]
  S4_SETTLER_ENUM iType; // [esp+14h] [ebp-10h]
  CEcoSector *v8; // [esp+18h] [ebp-Ch]
  struct CSettler *pSettler; // [esp+20h] [ebp-4h]

  pSettler = CSettlerMgr::Settler(this, _iSettlerId);
  iOwnerId = IEntity::OwnerId(pSettler);
  iType = IEntity::Type(pSettler);
  if ( iType < SETTLER_MAX )
  {
    if ( IEntity::WarriorType(pSettler) )
    {
      CSettlerMgr::DetachSettler(this, pSettler);
    }
    else
    {
      v2 = IEntity::WorldIdx();
      v6 = CWorldManager::EcoSectorId(v2);
      if ( v6 > 0 )
      {
        v8 = CEcoSectorMgr::operator[](g_cESMgr, v6);
        v3 = CEcoSector::Owner(v8);
        if ( v3 == IEntity::OwnerId(pSettler) )
        {
          if ( IEntity::FlagBits(pSettler, ENTITY_FLAG_Offered) )
            CEcoSector::GetSettlerOutOfOffer(v8, _iSettlerId);
          v5 = CSettler::Role(pSettler);
          if ( v5->GetSettlerRole(v5) != 18
            && !IEntity::FlagBits(pSettler, (EntityFlag)128)
            && (!IEntity::FlagBits(pSettler, ENTITY_FLAG_ON_BOARD) || IEntity::FlagBits(pSettler, ENTITY_FLAG_Ownerless)) )
          {
            CEcoSector::ChangeNrOfSettler(v8, iType, -1);
            IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_Ownerless);
          }
        }
      }
    }
    CSettlerMgr::DecNumberOfSettler(this, iOwnerId, iType);
  }
  --this->m_uTotalSettlers;
  if ( IHJBMgr::GetHJBEntityId() == _iSettlerId )
    IHJBMgr::SetHJBEntityId(0);
}


// address=[0x15858b0]
// Decompiled from int CSettlerMgr::GetUserESInMiddleOfTheScreen()
int __cdecl CSettlerMgr::GetUserESInMiddleOfTheScreen(void) {
  
  int iOffsetX; // eax
  int iOffsetY; // eax
  struct CEcoSector *rEcoSector; // eax
  int iOwnerId; // esi
  int iCenterY; // [esp+8h] [ebp-18h] BYREF
  int iCenterX; // [esp+Ch] [ebp-14h] BYREF
  unsigned int iX; // [esp+10h] [ebp-10h]
  int iY; // [esp+14h] [ebp-Ch]
  int iEcoSectorId; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  iEcoSectorId = 0;
  iCenterX = 0;
  iCenterY = 0;
  CStateGame::GetCenterWorldCoordinate(g_pGame, &iCenterX, &iCenterY);
  iX = 0;
  iY = 0;
  for ( i = 0; i < 100; ++i )
  {
    iOffsetX = CSpiralOffsets::DeltaX(i);
    iX = iCenterX + iOffsetX;
    iOffsetY = CSpiralOffsets::DeltaY(i);
    iY = iCenterY + iOffsetY;
    if ( CWorldManager::InWorld(iX, iCenterY + iOffsetY) )
    {
      iEcoSectorId = CWorldManager::EcoSectorId(iX, iY);
      if ( iEcoSectorId )
      {
        rEcoSector = CEcoSectorMgr::operator[](g_cESMgr, iEcoSectorId);
        iOwnerId = CEcoSector::Owner(rEcoSector);
        if ( iOwnerId == CPlayerManager::GetLocalPlayerId() )
          return iEcoSectorId;
      }
      else
      {
        iEcoSectorId = 0;
      }
    }
  }
  return iEcoSectorId;
}


// address=[0x4152138]
// [Decompilation failed for static unsigned char * CSettlerMgr::m_uSettlerWarriorTypes]

// address=[0x4152180]
// [Decompilation failed for static unsigned char * CSettlerMgr::m_uSettlerWarriorLevels]

// address=[0x41521c8]
// [Decompilation failed for static int * CSettlerMgr::m_iSquadLeaderBoni256]

// address=[0x4153e40]
// [Decompilation failed for static struct CSettlerMgr::SSettlerInfos (* CSettlerMgr::m_vSettlerInfos)[70]]

#endif // Already implemented
