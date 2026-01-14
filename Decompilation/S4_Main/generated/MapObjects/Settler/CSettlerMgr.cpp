#include "all_headers.h"

// Definitions for class CSettlerMgr

// address=[0x130e490]
// Decompiled from unsigned __int8 *__stdcall CSettlerMgr::operator[](int a1)
class CSettler &  CSettlerMgr::operator[](int) {
  
  unsigned __int8 *v2; // [esp+4h] [ebp-4h]

  v2 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( !v2
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         299,
         "pEntity != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::ObjType(v2) != 1
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         300,
         "pEntity->ObjType() == SETTLER_OBJ") == 1 )
  {
    __debugbreak();
  }
  return v2;
}


// address=[0x130ecc0]
// Decompiled from int __thiscall CSettlerMgr::GetNumberOfSettlers(CSettlerMgr *this, int a2, int a3)
int  CSettlerMgr::GetNumberOfSettlers(int,int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         371,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         372,
         "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 67 * a2 + a3 + 610);
}


// address=[0x130edf0]
// Decompiled from CSettler *__thiscall CSettlerMgr::GetSettlerPtr(struct CSettlerMgr *this, int a1)
class CSettler *  CSettlerMgr::GetSettlerPtr(int) {
  
  CSettler *v4; // [esp+Ch] [ebp-4h]

  v4 = (CSettler *)CMapObjectMgr::EntityPtr(a1);
  if ( v4 && IEntity::ObjType(v4) == 1 )
    return v4;
  else
    return 0;
}


// address=[0x1311cd0]
// Decompiled from int __thiscall CSettlerMgr::GetNumberOfOfferedSettlers(CSettlerMgr *this, int a2, int a3)
int  CSettlerMgr::GetNumberOfOfferedSettlers(int,int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         385,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         386,
         "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 67 * a2 + a3 + 1213);
}


// address=[0x1439bb0]
// Decompiled from CSettlerMgr::SSettlerInfos *__cdecl CSettlerMgr::GetSettlerInfo(int race, int type)
static struct CSettlerMgr::SSettlerInfos const & __cdecl CSettlerMgr::GetSettlerInfo(int,int) {
  
  return &CSettlerMgr::m_vSettlerInfos[70 * race + type];
}


// address=[0x1439ed0]
// Decompiled from int __cdecl CSettlerMgr::SettlerWarriorType(int a1)
static int __cdecl CSettlerMgr::SettlerWarriorType(int) {
  
  if ( !CSettlerMgr::m_uSettlerWarriorTypes[29]
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         347,
         "m_uSettlerWarriorTypes[SETTLER_SWORDSMAN_01] != 0") == 1 )
  {
    __debugbreak();
  }
  return (unsigned __int8)CSettlerMgr::m_uSettlerWarriorTypes[a1];
}


// address=[0x1580220]
// Decompiled from CSettlerMgr *__thiscall CSettlerMgr::CSettlerMgr(CSettlerMgr *this)
 CSettlerMgr::CSettlerMgr(void) {
  
  unsigned __int8 *i; // [esp+8h] [ebp-10h]

  MemoryAllocator::MemoryAllocator(this, 0x68u, 0x20u, 0);
  *((_WORD *)this + 12) = 0;
  *((_BYTE *)this + 26) = 0;
  memset(CSettlerMgr::m_uSettlerWarriorTypes, 0, 0x46u);
  memset(CSettlerMgr::m_uSettlerWarriorLevels, 0, 0x46u);
  memset(CSettlerMgr::m_vSettlerInfos, 0, 0x3C28u);
  for ( i = (unsigned __int8 *)&unk_37B5B38; *i; i += 4 )
  {
    if ( *i >= 0x43u
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 219, "pInfo->m_uType < SETTLER_MAX") == 1 )
    {
      __debugbreak();
    }
    if ( i[1] >= 0xFu
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 220, "pInfo->m_uWarriorType < WARRIOR_TYPE_MAX") == 1 )
    {
      __debugbreak();
    }
    if ( CSettlerMgr::m_uSettlerWarriorTypes[*i]
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerMgr.cpp",
           221,
           "m_uSettlerWarriorTypes[pInfo->m_uType] == 0") == 1 )
    {
      __debugbreak();
    }
    if ( CSettlerMgr::m_uSettlerWarriorLevels[*i] )
    {
      if ( BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\SettlerMgr.cpp",
             222,
             "m_uSettlerWarriorLevels[pInfo->m_uType] == 0") == 1 )
        __debugbreak();
    }
    CSettlerMgr::m_uSettlerWarriorTypes[*i] = i[1];
    CSettlerMgr::m_uSettlerWarriorLevels[*i] = i[2];
  }
  memset((char *)this + 28, 0, 0x96Cu);
  memset((char *)this + 2440, 0, 0x96Cu);
  memset((char *)this + 4852, 0, 0x96Cu);
  return this;
}


// address=[0x1580410]
// Decompiled from void __thiscall CSettlerMgr::~CSettlerMgr(CSettlerMgr *this)
 CSettlerMgr::~CSettlerMgr(void) {
  
  MemoryAllocator::~MemoryAllocator(this);
}


// address=[0x1580430]
// Decompiled from int __thiscall CSettlerMgr::Clear(CSettlerMgr *this)
void  CSettlerMgr::Clear(void) {
  
  memset((char *)this + 28, 0, 0x96Cu);
  memset((char *)this + 2440, 0, 0x96Cu);
  memset((char *)this + 4852, 0, 0x96Cu);
  *((_WORD *)this + 12) = 0;
  return (*(int (__thiscall **)(void *))(*(_DWORD *)g_pHJBMgr + 20))(g_pHJBMgr);
}


// address=[0x15804a0]
// Decompiled from struct ISettlerRole *__thiscall CSettlerMgr::CreateSettlerRole(CSettlerMgr *this, unsigned int race, int type)
class ISettlerRole *  CSettlerMgr::CreateSettlerRole(int,int) {
  
  struct ISettlerRole *result; // eax MAPDST

  if ( race > 4
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1446, "_iRace>=0 && _iRace<RACE_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (type <= 0 || type >= 67)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1447,
         "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  switch ( CSettlerMgr::m_vSettlerInfos[70 * race + type].roleId )
  {
    case 1u:
      result = (struct ISettlerRole *)operator new(0x38u);
      if ( result )
        result = (struct ISettlerRole *)CCarrierRole::CCarrierRole((CCarrierRole *)result);
      else
        result = 0;
      break;
    case 2u:
      result = (struct ISettlerRole *)operator new(0x30u);
      if ( result )
        result = (struct ISettlerRole *)CDiggerRole::CDiggerRole((CDiggerRole *)result);
      else
        result = 0;
      break;
    case 3u:
      result = (struct ISettlerRole *)operator new(0x30u);
      if ( result )
        result = (struct ISettlerRole *)CBuilderRole::CBuilderRole((CBuilderRole *)result);
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
        result = (struct ISettlerRole *)CSoldierRole::CSoldierRole((CSoldierRole *)result);
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
        result = (struct ISettlerRole *)CGardenerRole::CGardenerRole((CGardenerRole *)result);
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
        result = (struct ISettlerRole *)CDonkeyRole::CDonkeyRole((CDonkeyRole *)result);
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
      CTrace::Print("This settler type %s has no role ... ", (&SettlerTypeToNameMap)[2 * type]);
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
// Decompiled from int __cdecl CSettlerMgr::LoadSettlerRole(int a1, int a2)
static class ISettlerRole * __cdecl CSettlerMgr::LoadSettlerRole(std::istream &,int) {
  
  int result; // eax

  switch ( a2 )
  {
    case 1:
      result = CCarrierRole::Load(a1);
      break;
    case 2:
      result = CDiggerRole::Load(a1);
      break;
    case 3:
      result = CBuilderRole::Load(a1);
      break;
    case 4:
      result = CHouseWorkerRole::Load(a1);
      break;
    case 5:
      result = CFreeWorkerRole::Load(a1);
      break;
    case 7:
      result = CSoldierRole::Load(a1);
      break;
    case 8:
      result = CHunterRole::Load(a1);
      break;
    case 9:
      result = CPriestRole::Load(a1);
      break;
    case 10:
      result = CSaboteurRole::Load(a1);
      break;
    case 11:
      result = CPioneerRole::Load(a1);
      break;
    case 12:
      result = CGeologistRole::Load(a1);
      break;
    case 13:
      result = CGardenerRole::Load(a1);
      break;
    case 14:
      result = CDarkGardenerRole::Load(a1);
      break;
    case 15:
      result = CMushroomFarmerRole::Load(a1);
      break;
    case 16:
      result = CShamanRole::Load(a1);
      break;
    case 17:
      result = CSlaveRole::Load(a1);
      break;
    case 18:
      result = CFleeRole::Load(a1);
      break;
    case 19:
      result = CThiefRole::Load(a1);
      break;
    case 20:
      result = CDonkeyRole::Load(a1);
      break;
    case 21:
      result = CDoorRole::Load(a1);
      break;
    case 22:
      result = CTowerSoldier::Load(a1);
      break;
    case 23:
      result = CSquadLeaderRole::Load_HACK_VERSION(a1);
      break;
    case 24:
      result = CHJBRole::Load(a1);
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
// Decompiled from void __thiscall CSettlerMgr::LoadSettlerData(CSettlerMgr *this, struct S4::CMapFile *a2, unsigned __int16 a3)
void  CSettlerMgr::LoadSettlerData(class S4::CMapFile &,int) {
  
  char *v4; // [esp+10h] [ebp-28h]
  int v5; // [esp+14h] [ebp-24h]
  int v6; // [esp+20h] [ebp-18h] BYREF
  int v7; // [esp+24h] [ebp-14h]
  int v8; // [esp+28h] [ebp-10h]
  char *v9; // [esp+2Ch] [ebp-Ch]
  int i; // [esp+30h] [ebp-8h]
  int v11; // [esp+34h] [ebp-4h]

  v6 = 0;
  v4 = (char *)S4::CMapFile::LoadChunk(a2, a3, 0, &v6, 0);
  for ( i = 0; i < v6; ++i )
  {
    v9 = &v4[6 * i];
    v7 = *(unsigned __int16 *)v9;
    v8 = *((unsigned __int16 *)v9 + 1);
    CWorldManager::Index(v7, v8);
    v5 = (unsigned __int8)v9[5];
    v11 = (unsigned __int8)v9[4];
    if ( v11 >= 200 )
    {
      CVehicleMgr::AddVehicle((CVehicleMgr *)&g_cVehicleMgr, v7, v8, v5, v11 - 200, -1, 0);
    }
    else if ( v11 < 67 && v11 >= 0 )
    {
      CSettlerMgr::AddSettler(this, v7, v8, v5, v11, 0);
    }
  }
  S4::CMapFile::CloseChunk(a2, a3, 0);
}


// address=[0x1580fe0]
// Decompiled from unsigned int __thiscall CSettlerMgr::LoadInfo(_BYTE *this, char a2)
void  CSettlerMgr::LoadInfo(bool) {
  
  unsigned int result; // eax
  int v3; // eax
  int v4; // eax
  const char *v5; // eax
  char v6; // al
  const char *v7; // eax
  char v8; // al
  const char *v9; // eax
  char v10; // al
  const char *v11; // eax
  char v12; // al
  const char *v13; // eax
  char v14; // al
  const char *v15; // eax
  char v16; // al
  char *v17; // eax
  int v18; // eax
  const char *v19; // eax
  char v20; // al
  char *v21; // eax
  char *v22; // eax
  int v23; // eax
  int v24; // [esp+0h] [ebp-794h] BYREF
  _BYTE v25[28]; // [esp+10h] [ebp-784h] BYREF
  _BYTE v26[16]; // [esp+2Ch] [ebp-768h] BYREF
  _BYTE v27[16]; // [esp+4Ch] [ebp-748h] BYREF
  _BYTE v28[16]; // [esp+5Ch] [ebp-738h] BYREF
  _BYTE v29[16]; // [esp+6Ch] [ebp-728h] BYREF
  _BYTE v30[16]; // [esp+7Ch] [ebp-718h] BYREF
  _BYTE v31[16]; // [esp+8Ch] [ebp-708h] BYREF
  _BYTE v32[16]; // [esp+9Ch] [ebp-6F8h] BYREF
  _BYTE v33[16]; // [esp+ACh] [ebp-6E8h] BYREF
  _DWORD v34[4]; // [esp+BCh] [ebp-6D8h] BYREF
  _DWORD v35[4]; // [esp+CCh] [ebp-6C8h] BYREF
  _DWORD v36[4]; // [esp+DCh] [ebp-6B8h] BYREF
  _DWORD v37[21]; // [esp+ECh] [ebp-6A8h] BYREF
  _DWORD v38[4]; // [esp+140h] [ebp-654h] BYREF
  _DWORD v39[4]; // [esp+150h] [ebp-644h] BYREF
  int v40; // [esp+160h] [ebp-634h]
  int v41; // [esp+164h] [ebp-630h]
  int v42; // [esp+168h] [ebp-62Ch]
  int v43; // [esp+16Ch] [ebp-628h]
  _DWORD v44[4]; // [esp+170h] [ebp-624h] BYREF
  const struct AdvXMLParser::Attribute *v45; // [esp+180h] [ebp-614h]
  AdvXMLParser::Element *v46; // [esp+184h] [ebp-610h]
  int v47; // [esp+188h] [ebp-60Ch]
  _DWORD *v48; // [esp+18Ch] [ebp-608h]
  _DWORD *v49; // [esp+190h] [ebp-604h]
  int v50; // [esp+194h] [ebp-600h]
  _DWORD *v51; // [esp+198h] [ebp-5FCh]
  _DWORD *v52; // [esp+19Ch] [ebp-5F8h]
  int v53; // [esp+1A0h] [ebp-5F4h]
  int ValueOfDefine; // [esp+1A4h] [ebp-5F0h]
  const struct AdvXMLParser::Attribute *v55; // [esp+1A8h] [ebp-5ECh]
  AdvXMLParser::Element *v56; // [esp+1ACh] [ebp-5E8h]
  _DWORD *v57; // [esp+1B0h] [ebp-5E4h]
  _DWORD *v58; // [esp+1B4h] [ebp-5E0h]
  _DWORD *v59; // [esp+1B8h] [ebp-5DCh]
  _DWORD *v60; // [esp+1BCh] [ebp-5D8h]
  void *v61; // [esp+1C0h] [ebp-5D4h]
  int Root; // [esp+1C4h] [ebp-5D0h]
  int v63; // [esp+1C8h] [ebp-5CCh]
  _BYTE *v64; // [esp+1CCh] [ebp-5C8h]
  void *C; // [esp+1D0h] [ebp-5C4h]
  int v66; // [esp+1D4h] [ebp-5C0h]
  int v67; // [esp+1D8h] [ebp-5BCh]
  CConfigManager *v68; // [esp+1DCh] [ebp-5B8h]
  void *v69; // [esp+1E0h] [ebp-5B4h]
  void *v70; // [esp+1E4h] [ebp-5B0h]
  int v71; // [esp+1E8h] [ebp-5ACh]
  _DWORD *v72; // [esp+1ECh] [ebp-5A8h]
  _DWORD *v73; // [esp+1F0h] [ebp-5A4h]
  const struct AdvXMLParser::Element *v74; // [esp+1F4h] [ebp-5A0h]
  AdvXMLParser::Element *v75; // [esp+1F8h] [ebp-59Ch]
  _DWORD *v76; // [esp+1FCh] [ebp-598h]
  _DWORD *v77; // [esp+200h] [ebp-594h]
  const struct AdvXMLParser::Element *v78; // [esp+204h] [ebp-590h]
  AdvXMLParser::Element *v79; // [esp+208h] [ebp-58Ch]
  char *SearchData; // [esp+20Ch] [ebp-588h]
  int v81; // [esp+210h] [ebp-584h]
  void *v82; // [esp+214h] [ebp-580h]
  void *v83; // [esp+218h] [ebp-57Ch]
  int v84; // [esp+21Ch] [ebp-578h]
  _DWORD *v85; // [esp+220h] [ebp-574h]
  _DWORD *v86; // [esp+224h] [ebp-570h]
  const struct AdvXMLParser::Element *v87; // [esp+228h] [ebp-56Ch]
  AdvXMLParser::Element *v88; // [esp+22Ch] [ebp-568h]
  _DWORD *v89; // [esp+230h] [ebp-564h]
  _DWORD *v90; // [esp+234h] [ebp-560h]
  const struct AdvXMLParser::Element *v91; // [esp+238h] [ebp-55Ch]
  AdvXMLParser::Element *v92; // [esp+23Ch] [ebp-558h]
  void *v93; // [esp+240h] [ebp-554h]
  const struct AdvXMLParser::Element *v94; // [esp+244h] [ebp-550h]
  AdvXMLParser::Element *v95; // [esp+248h] [ebp-54Ch]
  int v96; // [esp+24Ch] [ebp-548h]
  int v97; // [esp+250h] [ebp-544h]
  void *v98; // [esp+254h] [ebp-540h]
  void *v99; // [esp+258h] [ebp-53Ch]
  CConfigManager *v100; // [esp+25Ch] [ebp-538h]
  const struct AdvXMLParser::Element *v101; // [esp+260h] [ebp-534h]
  AdvXMLParser::Element *v102; // [esp+264h] [ebp-530h]
  int v103; // [esp+268h] [ebp-52Ch]
  void *v104; // [esp+26Ch] [ebp-528h]
  void *v105; // [esp+270h] [ebp-524h]
  const struct AdvXMLParser::Element *v106; // [esp+274h] [ebp-520h]
  AdvXMLParser::Element *v107; // [esp+278h] [ebp-51Ch]
  void *v108; // [esp+27Ch] [ebp-518h]
  const struct AdvXMLParser::Element *v109; // [esp+280h] [ebp-514h]
  AdvXMLParser::Element *v110; // [esp+284h] [ebp-510h]
  void *v111; // [esp+288h] [ebp-50Ch]
  const struct AdvXMLParser::Element *v112; // [esp+28Ch] [ebp-508h]
  AdvXMLParser::Element *v113; // [esp+290h] [ebp-504h]
  void *v114; // [esp+294h] [ebp-500h]
  const struct AdvXMLParser::Element *v115; // [esp+298h] [ebp-4FCh]
  AdvXMLParser::Element *v116; // [esp+29Ch] [ebp-4F8h]
  void *v117; // [esp+2A0h] [ebp-4F4h]
  const struct AdvXMLParser::Element *v118; // [esp+2A4h] [ebp-4F0h]
  AdvXMLParser::Element *v119; // [esp+2A8h] [ebp-4ECh]
  void *v120; // [esp+2ACh] [ebp-4E8h]
  const struct AdvXMLParser::Element *v121; // [esp+2B0h] [ebp-4E4h]
  AdvXMLParser::Element *v122; // [esp+2B4h] [ebp-4E0h]
  void *v123; // [esp+2B8h] [ebp-4DCh]
  const struct AdvXMLParser::Element *v124; // [esp+2BCh] [ebp-4D8h]
  AdvXMLParser::Element *v125; // [esp+2C0h] [ebp-4D4h]
  int v126; // [esp+2C4h] [ebp-4D0h]
  const struct AdvXMLParser::Element *v127; // [esp+2C8h] [ebp-4CCh]
  AdvXMLParser::Element *v128; // [esp+2CCh] [ebp-4C8h]
  int v129; // [esp+2D0h] [ebp-4C4h]
  int v130; // [esp+2D4h] [ebp-4C0h]
  int v131; // [esp+2D8h] [ebp-4BCh]
  CConfigManager *Instance; // [esp+2DCh] [ebp-4B8h]
  int v133; // [esp+2E0h] [ebp-4B4h]
  const struct AdvXMLParser::Attribute *v134; // [esp+2E4h] [ebp-4B0h]
  const struct AdvXMLParser::Attribute *v135; // [esp+2E8h] [ebp-4ACh]
  CConfigManager *v136; // [esp+2ECh] [ebp-4A8h]
  int v137; // [esp+2F0h] [ebp-4A4h]
  const struct AdvXMLParser::Element *v138; // [esp+2F4h] [ebp-4A0h]
  const struct AdvXMLParser::Element *v139; // [esp+2F8h] [ebp-49Ch]
  const struct AdvXMLParser::Element *v140; // [esp+2FCh] [ebp-498h]
  const struct AdvXMLParser::Element *v141; // [esp+300h] [ebp-494h]
  const struct AdvXMLParser::Element *v142; // [esp+304h] [ebp-490h]
  const struct AdvXMLParser::Element *v143; // [esp+308h] [ebp-48Ch]
  const struct AdvXMLParser::Element *v144; // [esp+30Ch] [ebp-488h]
  const struct AdvXMLParser::Element *v145; // [esp+310h] [ebp-484h]
  const struct AdvXMLParser::Element *v146; // [esp+314h] [ebp-480h]
  const struct AdvXMLParser::Element *v147; // [esp+318h] [ebp-47Ch]
  int v148; // [esp+31Ch] [ebp-478h] BYREF
  char v149; // [esp+320h] [ebp-474h]
  char v150; // [esp+321h] [ebp-473h]
  char v151; // [esp+322h] [ebp-472h]
  char v152; // [esp+323h] [ebp-471h]
  CConfigManager *v153; // [esp+324h] [ebp-470h]
  char v155[4]; // [esp+32Ch] [ebp-468h] BYREF
  int v156; // [esp+330h] [ebp-464h]
  CConfigManager *v157; // [esp+334h] [ebp-460h]
  int v158; // [esp+338h] [ebp-45Ch]
  int v159; // [esp+33Ch] [ebp-458h]
  int v160; // [esp+340h] [ebp-454h]
  int v161; // [esp+344h] [ebp-450h] BYREF
  int v162; // [esp+348h] [ebp-44Ch]
  __int16 v163; // [esp+34Eh] [ebp-446h] BYREF
  _DWORD v164[4]; // [esp+350h] [ebp-444h] BYREF
  void *v165; // [esp+360h] [ebp-434h]
  int j; // [esp+364h] [ebp-430h]
  char *v167; // [esp+368h] [ebp-42Ch]
  int i; // [esp+36Ch] [ebp-428h]
  int k; // [esp+370h] [ebp-424h]
  char *v174; // [esp+378h] [ebp-41Ch]
  _BYTE v175[28]; // [esp+5A4h] [ebp-1F0h] BYREF
  _BYTE v176[28]; // [esp+5C0h] [ebp-1D4h] BYREF
  _BYTE v177[28]; // [esp+5DCh] [ebp-1B8h] BYREF
  _BYTE v178[28]; // [esp+5F8h] [ebp-19Ch] BYREF
  _BYTE v179[28]; // [esp+614h] [ebp-180h] BYREF
  _BYTE v180[28]; // [esp+630h] [ebp-164h] BYREF
  _BYTE v181[28]; // [esp+64Ch] [ebp-148h] BYREF
  _BYTE v182[28]; // [esp+668h] [ebp-12Ch] BYREF
  _BYTE v183[28]; // [esp+684h] [ebp-110h] BYREF
  _BYTE v184[28]; // [esp+6A0h] [ebp-F4h] BYREF
  _BYTE v185[28]; // [esp+6BCh] [ebp-D8h] BYREF
  _BYTE v186[28]; // [esp+6D8h] [ebp-BCh] BYREF
  _BYTE v187[28]; // [esp+6F4h] [ebp-A0h] BYREF
  _BYTE v188[28]; // [esp+710h] [ebp-84h] BYREF
  _BYTE v189[28]; // [esp+72Ch] [ebp-68h] BYREF
  char v190[28]; // [esp+748h] [ebp-4Ch] BYREF
  char v191[28]; // [esp+764h] [ebp-30h] BYREF
  int *v192; // [esp+784h] [ebp-10h]
  int v193; // [esp+790h] [ebp-4h]

  v192 = &v24;
  v64 = this;
  result = (unsigned int)this;
  if ( this[26] == 1 )
    return result;
  v161 = 0;
  v167 = 0;
  result = (unsigned int)(a2
                        ? AdvXMLParser::Parser::OpenXMLFile(aGamedataSettle, &v161)
                        : AdvXMLParser::Parser::OpenXMLFile(aGamedataSettle_0, &v161));
  v167 = (char *)result;
  if ( !result )
    return result;
  v193 = 0;
  v37[18] = AdvXMLParser::Parser::Parser(v25);
  LOBYTE(v193) = 1;
  v63 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v25, v167, v161);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v63);
  LOBYTE(v193) = 2;
  v3 = std::auto_ptr<AdvXMLParser::Document>::operator->(v24);
  Root = AdvXMLParser::Document::GetRoot(v3);
  v133 = Root;
  v61 = (void *)CDefineTranslator::Instance();
  v165 = v61;
  v37[10] = 0;
  v60 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v133, v33);
  v59 = v60;
  LOBYTE(v193) = 3;
  v37[9] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v44, v60);
  LOBYTE(v193) = 5;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v33);
  v58 = (_DWORD *)AdvXMLParser::NodeContainer::End(v133, v32);
  v57 = v58;
  LOBYTE(v193) = 6;
  v37[8] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v34, v58);
  LOBYTE(v193) = 8;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v32);
  while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<((int)v34) )
  {
    v56 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v44);
    v55 = AdvXMLParser::Element::operator[](v56, "id");
    v134 = v55;
    v37[7] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, _BYTE *))(*(_DWORD *)v55 + 8))(v55, v188);
    LOBYTE(v193) = 9;
    ValueOfDefine = CDefineTranslator::GetValueOfDefine(v165, (int)v188);
    v129 = ValueOfDefine;
    v53 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v44);
    v52 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v53, v31);
    v51 = v52;
    LOBYTE(v193) = 10;
    v37[6] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v164, v52);
    LOBYTE(v193) = 12;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v31);
    v50 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v44);
    v49 = (_DWORD *)AdvXMLParser::NodeContainer::End(v50, v30);
    v48 = v49;
    LOBYTE(v193) = 13;
    v37[5] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v35, v49);
    LOBYTE(v193) = 15;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v30);
    while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<((int)v35) )
    {
      v47 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v37[4] = v47;
      v46 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v45 = AdvXMLParser::Element::operator[](v46, "id");
      v135 = v45;
      v37[20] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, _BYTE *))(*(_DWORD *)v45 + 8))(v45, v187);
      LOBYTE(v193) = 16;
      Instance = CConfigManagerPtr::GetInstance();
      v136 = Instance;
      v4 = std::string::c_str(v187);
      v131 = ((int (__thiscall *)(CConfigManager *, int))v136->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v136, v4);
      v137 = v131;
      if ( v131 == -1 )
      {
        v130 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1791, "index != -1");
        if ( v130 == 1 )
          __debugbreak();
      }
      v174 = &CSettlerMgr::m_vSettlerInfos[3080 * v129 + 44 * v137];
      v128 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v127 = AdvXMLParser::Element::operator()(v128, "role", 0);
      v139 = v127;
      v37[19] = (*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v127 + 8))(v127, v186);
      LOBYTE(v193) = 17;
      v126 = CDefineTranslator::GetValueOfDefine(v165, (int)v186);
      *v174 = v126;
      v125 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v124 = AdvXMLParser::Element::operator()(v125, "speed", 0);
      v140 = v124;
      v123 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v124 + 8))(
                       v124,
                       v175);
      v5 = (const char *)std::string::c_str(v123);
      v6 = j__atoi(v5);
      v174[1] = v6;
      std::string::~string(v175);
      v122 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v121 = AdvXMLParser::Element::operator()(v122, "health", 0);
      v141 = v121;
      v120 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v121 + 8))(
                       v121,
                       v176);
      v7 = (const char *)std::string::c_str(v120);
      v8 = j__atoi(v7);
      v174[2] = v8;
      std::string::~string(v176);
      v119 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v118 = AdvXMLParser::Element::operator()(v119, "armor", 0);
      v142 = v118;
      v117 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v118 + 8))(
                       v118,
                       v177);
      v9 = (const char *)std::string::c_str(v117);
      v10 = j__atoi(v9);
      v174[4] = v10;
      std::string::~string(v177);
      v116 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v115 = AdvXMLParser::Element::operator()(v116, "damage", 0);
      v143 = v115;
      v114 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v115 + 8))(
                       v115,
                       v185);
      v11 = (const char *)std::string::c_str(v114);
      v12 = j__atoi(v11);
      v174[3] = v12;
      std::string::~string(v185);
      v113 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v112 = AdvXMLParser::Element::operator()(v113, "damage2", 0);
      v144 = v112;
      v111 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v112 + 8))(
                       v112,
                       v178);
      v13 = (const char *)std::string::c_str(v111);
      v14 = j__atoi(v13);
      v174[40] = v14;
      std::string::~string(v178);
      v110 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v109 = AdvXMLParser::Element::operator()(v110, "damage3", 0);
      v145 = v109;
      v108 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v109 + 8))(
                       v109,
                       v179);
      v15 = (const char *)std::string::c_str(v108);
      v16 = j__atoi(v15);
      v174[41] = v16;
      std::string::~string(v179);
      v107 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v106 = AdvXMLParser::Element::operator()(v107, "other", 0);
      v146 = v106;
      v105 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v106 + 8))(
                       v106,
                       v180);
      v104 = v105;
      LOBYTE(v193) = 18;
      v17 = (char *)std::string::c_str(v105);
      v37[11] = std::string::string(v189, v17);
      LOBYTE(v193) = 19;
      v103 = CDefineTranslator::GetValueOfDefine(v165, (int)v189);
      v174[6] = v103;
      LOBYTE(v193) = 18;
      std::string::~string(v189);
      LOBYTE(v193) = 17;
      std::string::~string(v180);
      v102 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v101 = AdvXMLParser::Element::operator()(v102, "tool", 0);
      v147 = v101;
      v100 = CConfigManagerPtr::GetInstance();
      v153 = v100;
      v99 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v147 + 8))(
                      v147,
                      v181);
      v98 = v99;
      LOBYTE(v193) = 20;
      v18 = std::string::c_str(v99);
      v97 = ((int (__thiscall *)(CConfigManager *, int))v153->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v153, v18);
      v174[5] = v97;
      LOBYTE(v193) = 17;
      std::string::~string(v181);
      if ( (unsigned __int8)v174[5] == -1 )
      {
        v96 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1811, "sI.m_uTool != -1");
        if ( v96 == 1 )
          __debugbreak();
      }
      v95 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v94 = AdvXMLParser::Element::operator()(v95, "misc", 0);
      v138 = v94;
      v93 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v94 + 8))(
                      v94,
                      v182);
      v19 = (const char *)std::string::c_str(v93);
      v20 = j__atoi(v19);
      v174[7] = v20;
      std::string::~string(v182);
      v92 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v91 = AdvXMLParser::Element::operator()(v92, "search", 0);
      v90 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v91, v29);
      v89 = v90;
      LOBYTE(v193) = 21;
      v37[17] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v38, v90);
      LOBYTE(v193) = 23;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v29);
      v88 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v87 = AdvXMLParser::Element::operator()(v88, "search", 0);
      v86 = (_DWORD *)AdvXMLParser::NodeContainer::End(v87, v26);
      v85 = v86;
      LOBYTE(v193) = 24;
      v37[16] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v36, v86);
      LOBYTE(v193) = 26;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v26);
      while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<((int)v36) )
      {
        v84 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v38);
        v160 = v84;
        v83 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v84 + 8))(v84, v183);
        v82 = v83;
        LOBYTE(v193) = 27;
        v21 = (char *)std::string::c_str(v83);
        v37[15] = std::string::string(v190, v21);
        LOBYTE(v193) = 29;
        std::string::~string(v183);
        v81 = CDefineTranslator::GetValueOfDefine(v165, (int)v190);
        v159 = v81;
        SearchData = CSearchRoutines::GetSearchData(v81);
        v40 = *(_DWORD *)SearchData;
        v41 = *((_DWORD *)SearchData + 1);
        v42 = *((_DWORD *)SearchData + 2);
        v43 = *((_DWORD *)SearchData + 3);
        v148 = v40;
        v149 = v159;
        v150 = v42;
        v151 = v43;
        v152 = 0;
        std::vector<CSettlerMgr::SSearchInfos>::push_back(&v148);
        LOBYTE(v193) = 26;
        std::string::~string(v190);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v38);
      }
      v79 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v78 = AdvXMLParser::Element::operator()(v79, "animLists", 0);
      v77 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v78, v28);
      v76 = v77;
      LOBYTE(v193) = 30;
      v37[14] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v39, v77);
      LOBYTE(v193) = 32;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v28);
      v75 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v164);
      v74 = AdvXMLParser::Element::operator()(v75, "animLists", 0);
      v73 = (_DWORD *)AdvXMLParser::NodeContainer::End(v74, v27);
      v72 = v73;
      LOBYTE(v193) = 33;
      v37[13] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v37, v73);
      LOBYTE(v193) = 35;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v27);
      while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<((int)v37) )
      {
        v71 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v39);
        v158 = v71;
        v70 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v71 + 8))(v71, v184);
        v69 = v70;
        LOBYTE(v193) = 36;
        v22 = (char *)std::string::c_str(v70);
        v37[12] = std::string::string(v191, v22);
        LOBYTE(v193) = 38;
        std::string::~string(v184);
        v68 = CConfigManagerPtr::GetInstance();
        v157 = v68;
        v23 = std::string::c_str(v191);
        v67 = ((int (__thiscall *)(CConfigManager *, int))v157->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v157, v23);
        v156 = v67;
        if ( v67 == -1 )
        {
          v66 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1842, "iAnimList != -1");
          if ( v66 == 1 )
            __debugbreak();
        }
        v163 = v156;
        std::vector<unsigned short>::push_back(&v163);
        LOBYTE(v193) = 35;
        std::string::~string(v191);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v39);
      }
      LOBYTE(v193) = 32;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v37);
      LOBYTE(v193) = 26;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v39);
      LOBYTE(v193) = 23;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v36);
      LOBYTE(v193) = 17;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v38);
      LOBYTE(v193) = 16;
      std::string::~string(v186);
      LOBYTE(v193) = 15;
      std::string::~string(v187);
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v164);
    }
    LOBYTE(v193) = 12;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v35);
    LOBYTE(v193) = 9;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v164);
    LOBYTE(v193) = 8;
    std::string::~string(v188);
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v44);
  }
  LOBYTE(v193) = 5;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v34);
  LOBYTE(v193) = 2;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v44);
  LOBYTE(v193) = 1;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v155);
  LOBYTE(v193) = 0;
  AdvXMLParser::Parser::~Parser(v25);
  v193 = -1;
  C = v167;
  operator delete[](v167);
  for ( i = 1; i < 67; ++i )
  {
    for ( j = 0; j < 5; ++j )
    {
      if ( !CSettlerMgr::m_vSettlerInfos[3080 * j + 44 * i] )
        CSettlerMgr::SSettlerInfos::operator=(
          &CSettlerMgr::m_vSettlerInfos[3080 * j + 44 * i],
          &CSettlerMgr::m_vSettlerInfos[44 * i]);
    }
  }
  v162 = (unsigned __int8)byte_4153E47[1936];
  if ( !v162 )
    v162 = 10;
  CSettlerMgr::m_iSquadLeaderBoni256[0] = (v162 << 8) / 100;
  for ( k = 0; k < 5; ++k )
  {
    if ( k )
    {
      if ( byte_4153E47[3080 * k + 1936] )
        CSettlerMgr::m_iSquadLeaderBoni256[k] = CSettlerMgr::m_iSquadLeaderBoni256[0];
      else
        CSettlerMgr::m_iSquadLeaderBoni256[k] = 0;
    }
  }
  if ( !byte_4153E47[1540] )
    byte_4153E47[1540] = 3;
  if ( !byte_4153E47[1584] )
    byte_4153E47[1584] = 5;
  if ( !byte_4153E47[1628] )
    byte_4153E47[1628] = 7;
  if ( byte_4153E47[7964] )
    g_iBlowgunWarriorFreezeChange = CRandom16::PercentValue((unsigned __int8)byte_4153E47[7964]);
  if ( byte_4153E47[8008] )
    *(&g_iBlowgunWarriorFreezeChange + 1) = CRandom16::PercentValue((unsigned __int8)byte_4153E47[8008]);
  if ( byte_4153E47[8052] )
    *(&g_iBlowgunWarriorFreezeChange + 2) = CRandom16::PercentValue((unsigned __int8)byte_4153E47[8052]);
  if ( !byte_4153E47[8844] )
    byte_4153E47[8844] = 55;
  g_iBackPackCatapultistPercent[0] = (unsigned __int8)byte_4153E47[8844];
  if ( !byte_4153E47[8888] )
    byte_4153E47[8888] = 65;
  g_iBackPackCatapultistPercent[1] = (unsigned __int8)byte_4153E47[8888];
  if ( !byte_4153E47[8932] )
    byte_4153E47[8932] = 75;
  g_iBackPackCatapultistPercent[2] = (unsigned __int8)byte_4153E47[8932];
  result = 3080;
  if ( !byte_4153E47[2024] )
    return result;
  result = CRandom16::PercentValue((unsigned __int8)byte_4153E47[2024]);
  g_uSaboteurHitChange = result;
  return result;
}


// address=[0x1582460]
// Decompiled from int __thiscall CSettlerMgr::AddSettler(CSettlerMgr *this, int posX, int posY, int player, int settlerType, int a6)
int  CSettlerMgr::AddSettler(int,int,int,int,int) {
  
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

  if ( !CWorldManager::InWorld(posX, posY)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 467, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (player <= 0 || player >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 468, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (settlerType <= 0 || settlerType >= 67)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 469, "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int16 *)this + 12) >= 0x7FFFu )
  {
    CTrace::Print("No more settler allowed!");
    return 0;
  }
  else
  {
    ++*((_WORD *)this + 12);
    playerInfo = CPlayerManager::PlayerInfo(player);
    race = CPlayerInfo::Race(playerInfo);
    v25 = 0;
    if ( settlerType != 1 || player == CWorldManager::OwnerId(posX, posY) )
    {
      v25 = CSettlerMgr::CreateSettlerRole((CSettlerMgr *)g_cSettlerMgr, race, settlerType);
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
      pNewSettler = CSettler::CSettler(settler, posX, posY, settlerType, player, v9.ptr, freeSlot);
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
    if ( CSettlerMgr::SettlerWarriorType(settlerType) )
    {
      CSettlerMgr::AttachSettler(this, pNewSettler);
      if ( a6 > 0 )
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          20,
          player,
          v27,
          a6);
    }
    CSettlerMgr::IncNumberOfSettler(this, player, settlerType);
    v13 = v27;
    v29 = -1;
    std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
    return v13;
  }
}


// address=[0x1582720]
// Decompiled from bool __thiscall CSettlerMgr::IsAddSettlerOk(CSettlerMgr *this, int a2, int a3, int a4)
bool  CSettlerMgr::IsAddSettlerOk(int,int,int) {
  
  int v5; // [esp+4h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3) )
    return 0;
  v5 = CWorldManager::Index(a2, a3);
  if ( CWorldManager::FlagBits(v5, 1u) )
    return 0;
  if ( CWorldManager::MapObjectId(v5) )
    return 0;
  return !a4 || ITiling::OwnerId(v5) == a4;
}


// address=[0x15827b0]
// Decompiled from int __thiscall CSettlerMgr::AddSettlers(CSettlerMgr *this, int a2, int a3, int a4, int a5, int a6, int a7)
void  CSettlerMgr::AddSettlers(int,int,int,int,int,int) {
  
  int result; // eax
  int v9; // [esp+10h] [ebp-14h]
  int v10; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h]
  int v13; // [esp+20h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 560, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 561, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a5 <= 0 || a5 >= 67)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 562, "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a6 <= 0 || a6 >= 10000)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 563, "_iAmount>0 && _iAmount<10000") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  v13 = 0;
  v10 = a6;
  while ( v10 && v13 < 20000 )
  {
    v11 = a2 + CSpiralOffsets::DeltaX(v13);
    v12 = a3 + CSpiralOffsets::DeltaY(v13);
    v9 = CWorldManager::Index(v11, v12);
    if ( (unsigned __int8)CWorldManager::InWorld(v11, v12)
      && !CWorldManager::MapObjectId(v9)
      && !CWorldManager::FlagBits(v9, 0x39u) )
    {
      if ( CSettlerMgr::AddSettler(this, v11, v12, a4, a5, a7) )
        --v10;
    }
    result = ++v13;
  }
  return result;
}


// address=[0x1582970]
// Decompiled from int __thiscall CSettlerMgr::AddGuardSettler(CSettlerMgr *this, int a2, int a3, int a4)
int  CSettlerMgr::AddGuardSettler(int,int,int) {
  
  int v5; // [esp-8h] [ebp-54h] BYREF
  int v6; // [esp-4h] [ebp-50h]
  int v7; // [esp+4h] [ebp-48h]
  int *v8; // [esp+8h] [ebp-44h]
  int v9; // [esp+Ch] [ebp-40h]
  int v10; // [esp+10h] [ebp-3Ch]
  int v11; // [esp+14h] [ebp-38h]
  int v12; // [esp+18h] [ebp-34h]
  CDoorRole *v13; // [esp+1Ch] [ebp-30h]
  char v14[4]; // [esp+20h] [ebp-2Ch] BYREF
  int FreeSlot; // [esp+24h] [ebp-28h]
  int v16; // [esp+28h] [ebp-24h]
  CDoorRole *v18; // [esp+30h] [ebp-1Ch]
  void *C; // [esp+34h] [ebp-18h]
  CDoorRole *v20; // [esp+38h] [ebp-14h]
  CSettlerMgr *v21; // [esp+3Ch] [ebp-10h]
  int v22; // [esp+48h] [ebp-4h]

  v21 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 616, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 617, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int16 *)v21 + 12) >= 0x7FFFu )
  {
    CTrace::Print("No more settler allowed!");
    return 0;
  }
  else
  {
    ++*((_WORD *)v21 + 12);
    C = operator new(0x2Cu);
    v22 = 0;
    if ( C )
      v18 = CDoorRole::CDoorRole((CDoorRole *)C);
    else
      v18 = 0;
    v13 = v18;
    v20 = v18;
    std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v18);
    v22 = 2;
    FreeSlot = CMapObjectMgr::GetFreeSlot();
    if ( CSettler::operator new(0x68u) )
    {
      v6 = FreeSlot;
      v5 = FreeSlot;
      v8 = &v5;
      v7 = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v14);
      v12 = CSettler::CSettler(a2, a3, a4, v5, v6);
      v16 = v12;
    }
    else
    {
      v16 = 0;
    }
    v11 = v16;
    LOBYTE(v22) = 1;
    v10 = v16;
    (*(void (__thiscall **)(CDoorRole *, int))(*(_DWORD *)v20 + 44))(v20, v16);
    v9 = FreeSlot;
    v22 = -1;
    std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(v14);
    return v9;
  }
}


// address=[0x1582b30]
// Decompiled from int __thiscall CSettlerMgr::DeleteSettler(CSettlerMgr *this, int a2)
void  CSettlerMgr::DeleteSettler(int) {
  
  unsigned __int8 *v2; // eax

  if ( (a2 <= 1 || a2 >= 0xFFFF)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         652,
         "_iSettlerId>1 && _iSettlerId<CMapObjectMgr::MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  v2 = (unsigned __int8 *)CMapObjectMgr::Entity(a2);
  if ( IEntity::ObjType(v2) != 1
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         653,
         "g_pMapObjectMgr->Entity(_iSettlerId).ObjType() == SETTLER_OBJ") == 1 )
  {
    __debugbreak();
  }
  return CMapObjectMgr::Kill(a2, 0);
}


// address=[0x1582bc0]
// Decompiled from char __thiscall CSettlerMgr::SearchSpaceForSettler(CSettlerMgr *this, int a2, int a3, int a4)
bool  CSettlerMgr::SearchSpaceForSettler(int,int,int) {
  
  int v4; // eax
  int v5; // eax
  int v7; // [esp-8h] [ebp-24h]
  int v8; // [esp-4h] [ebp-20h]
  int v9; // [esp+8h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  IEntity *v13; // [esp+18h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a3, a4)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 737, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (a2 <= 1 || a2 >= 0xFFFF)
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
    v10 = a3 + CSpiralOffsets::DeltaX(i);
    v11 = a4 + CSpiralOffsets::DeltaY(i);
    v9 = CWorldManager::Index(v10, v11);
    if ( (unsigned __int8)CWorldManager::InWorld(v10, v11)
      && !CWorldManager::MapObjectId(v9)
      && CWorldManager::SectorId(v9) )
    {
      CWorldManager::SetSettlerId(v9, a2);
      v13 = (IEntity *)CSettlerMgr::operator[](a2);
      IEntity::SetPosition(v13, v10, v11);
      v8 = IEntity::Type((unsigned __int16 *)v13);
      v7 = IEntity::Type((unsigned __int16 *)v13);
      v4 = IEntity::Race(v13);
      v5 = CEntityToDoListMgr::SettlerJobList(v4, v7);
      ((void (__thiscall *)(IEntity *, int, int))v13->CPersistence[2].GetRelationship)(v13, v5, v8);
      return 1;
    }
  }
  return 0;
}


// address=[0x1582d50]
// Decompiled from char __thiscall CSettlerMgr::SearchFreePositionInSector(CSettlerMgr *this, int *a2, int *a3, int a4, int a5)
bool  CSettlerMgr::SearchFreePositionInSector(int &,int &,int,int) {
  
  _DWORD v6[6]; // [esp+0h] [ebp-24h] BYREF
  int v7; // [esp+18h] [ebp-Ch] BYREF
  int v8; // [esp+1Ch] [ebp-8h] BYREF
  int v9; // [esp+20h] [ebp-4h]
  unsigned int v10; // [esp+38h] [ebp+14h]

  v6[5] = this;
  if ( a4 == -1 )
  {
    a4 = CWorldManager::SectorId(*a2, *a3);
    if ( a4 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2687, "_iSectorId > 0") == 1 )
      __debugbreak();
  }
  if ( a4 <= 0 )
    return 0;
  v10 = a5 | 1;
  v6[4] = 15;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v6, *a2, *a3, 15);
  while ( CSpiralWalk::NextXY(v6, &v8, &v7) )
  {
    v9 = CWorldManager::Index(v8, v7);
    if ( !CWorldManager::FlagBits(v9, v10) && !CWorldManager::MapObjectId(v9) && ITiling::SectorId(v9) == a4 )
    {
      *a2 = v8;
      *a3 = v7;
      return 1;
    }
  }
  return 0;
}


// address=[0x1582e60]
// Decompiled from char __thiscall CSettlerMgr::SearchFreePositionInEcoSector(CSettlerMgr *this, int *a2, int *a3, int a4)
bool  CSettlerMgr::SearchFreePositionInEcoSector(int &,int &,int) {
  
  _DWORD v5[6]; // [esp+0h] [ebp-24h] BYREF
  int v6; // [esp+18h] [ebp-Ch] BYREF
  int v7; // [esp+1Ch] [ebp-8h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  v5[5] = this;
  if ( a4 <= 0 )
    return 0;
  v5[4] = 15;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v5, *a2, *a3, 15);
  while ( CSpiralWalk::NextXY(v5, &v7, &v6) )
  {
    v8 = CWorldManager::Index(v7, v6);
    if ( !CWorldManager::FlagBits(v8, 0x21u) && !CWorldManager::MapObjectId(v8) && ITiling::EcoSectorId(v8) == a4 )
    {
      *a2 = v7;
      *a3 = v6;
      return 1;
    }
  }
  return 0;
}


// address=[0x1582f20]
// Decompiled from int __thiscall CSettlerMgr::GetFirstSettlerId(CSettlerMgr *this, int a2, int a3)
int  CSettlerMgr::GetFirstSettlerId(int,int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 792, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 793, "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 67 * a2 + a3 + 7);
}


// address=[0x1582fa0]
// Decompiled from int __thiscall CSettlerMgr::OrderWarrior(CSettlerMgr *this, int a2, int a3, unsigned int a4)
int  CSettlerMgr::OrderWarrior(int,int,int) {
  
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // esi
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  int v12; // [esp-4h] [ebp-60h]
  _BYTE v13[24]; // [esp+8h] [ebp-54h] BYREF
  CEntityEvent *v14; // [esp+20h] [ebp-3Ch]
  CEntityEvent *v15; // [esp+24h] [ebp-38h]
  int v16; // [esp+28h] [ebp-34h]
  CSettlerMgr *v17; // [esp+2Ch] [ebp-30h]
  int v18; // [esp+30h] [ebp-2Ch]
  unsigned int v19; // [esp+34h] [ebp-28h]
  unsigned int v20; // [esp+38h] [ebp-24h]
  CSettler *v21; // [esp+3Ch] [ebp-20h]
  _DWORD *v22; // [esp+40h] [ebp-1Ch]
  unsigned __int8 *v23; // [esp+44h] [ebp-18h]
  int FirstSettlerId; // [esp+48h] [ebp-14h]
  int v25; // [esp+4Ch] [ebp-10h]
  int v26; // [esp+58h] [ebp-4h]

  v17 = this;
  v19 = -1;
  v23 = (unsigned __int8 *)CBuildingMgr::operator[](a2);
  v4 = CBuilding::EnsignWorldIdx(v23);
  v16 = CWorldManager::SectorId(v4);
  v18 = IEntity::OwnerId(v23);
  FirstSettlerId = CSettlerMgr::GetFirstSettlerId(v17, v18, a3);
  v25 = 0;
  while ( FirstSettlerId )
  {
    v22 = (_DWORD *)CSettlerMgr::operator[](FirstSettlerId);
    if ( IEntity::FlagBits(v22, Selectable) )
    {
      v5 = IEntity::WorldIdx();
      if ( CWorldManager::SectorId(v5) == v16 )
      {
        v6 = IEntity::Y(v23);
        v12 = v6 - IEntity::Y(v22);
        v7 = IEntity::X(v23);
        v8 = IEntity::X(v22);
        v20 = Grid::Distance((Grid *)(v7 - v8), v12);
        if ( v20 < a4 && v20 < v19 )
        {
          v19 = v20;
          v25 = FirstSettlerId;
        }
      }
    }
    v9 = CSettlerMgr::operator[](FirstSettlerId);
    FirstSettlerId = IAnimatedEntity::Next(v9);
  }
  if ( !v25 )
    return 0;
  v10 = (_DWORD *)CSettlerMgr::operator[](v25);
  IEntity::ClearFlagBits(v10, Selectable);
  if ( v18 == CPlayerManager::GetLocalPlayerId() )
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, v25);
  v21 = (CSettler *)CSettlerMgr::operator[](v25);
  IEntity::RemoveFromAllGroups();
  CSettler::AttachToBuilding(v21, a2);
  v15 = CEntityEvent::CEntityEvent((CEntityEvent *)v13, 1u, 0, a2, 0, 0);
  v14 = v15;
  v26 = 0;
  (*(void (__thiscall **)(CSettler *, CEntityEvent *))(*(_DWORD *)v21 + 80))(v21, v15);
  v26 = -1;
  CEntityEvent::~CEntityEvent(v13);
  return v25;
}


// address=[0x1583190]
// Decompiled from int __thiscall CSettlerMgr::OrderAIWarrior(CSettlerMgr *this, int a2, int a3)
int  CSettlerMgr::OrderAIWarrior(int,int) {
  
  int v4; // eax
  int v5; // eax
  _BYTE v6[24]; // [esp+4h] [ebp-50h] BYREF
  CEntityEvent *v7; // [esp+1Ch] [ebp-38h]
  CEntityEvent *v8; // [esp+20h] [ebp-34h]
  int v9; // [esp+24h] [ebp-30h]
  int v10; // [esp+28h] [ebp-2Ch]
  int v11; // [esp+2Ch] [ebp-28h]
  CSettlerMgr *v12; // [esp+30h] [ebp-24h]
  int v13; // [esp+34h] [ebp-20h]
  CAIEntityInfo *v14; // [esp+38h] [ebp-1Ch]
  unsigned __int8 *BuildingPtr; // [esp+3Ch] [ebp-18h]
  int v16; // [esp+40h] [ebp-14h]
  unsigned __int8 *SettlerPtr; // [esp+44h] [ebp-10h]
  int v18; // [esp+50h] [ebp-4h]

  v12 = this;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  if ( !BuildingPtr )
    return 0;
  v14 = (CAIEntityInfo *)IEntity::AIEntityInfoPtr(BuildingPtr);
  if ( !v14 )
    return 0;
  v16 = CAIEntityInfo::TargetId(v14);
  if ( v16 <= 0 )
    return 0;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(v16);
  if ( !SettlerPtr
    || (_UNKNOWN *)IEntity::FlagBits(
                     SettlerPtr,
                     (EntityFlag)storm::echo::voicechat::outEvent::LocalChatterMuted::GetClassTypeName) != (_UNKNOWN *)((char *)&loc_2001FFF + 1)
    || IEntity::WarriorType() != 2 && IEntity::WarriorType() != 3 )
  {
    goto LABEL_18;
  }
  if ( IEntity::WarriorType() != a3 )
    return 0;
  v11 = IEntity::OwnerId(BuildingPtr);
  v13 = IEntity::OwnerId(SettlerPtr);
  if ( v11 == v13
    && (v4 = CBuilding::EnsignWorldIdx(BuildingPtr),
        v10 = ITiling::SectorId(v4),
        v5 = IEntity::WorldIdx(),
        v9 = ITiling::SectorId(v5),
        v10 == v9) )
  {
    IEntity::ClearFlagBits(SettlerPtr, Selectable);
    if ( v13 == CPlayerManager::GetLocalPlayerId() )
      CInputProcessor::DeSelectEntity(&g_cInputProcessor, v16);
    IEntity::RemoveFromAllGroups();
    CSettler::AttachToBuilding((CSettler *)SettlerPtr, a2);
    v8 = CEntityEvent::CEntityEvent((CEntityEvent *)v6, 1u, 0, a2, 0, 0);
    v7 = v8;
    v18 = 0;
    (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v8);
    v18 = -1;
    CEntityEvent::~CEntityEvent(v6);
    return v16;
  }
  else
  {
LABEL_18:
    BBSupportTracePrintF(0, "CSettlerMgr::OrderAIWarrior(): Invalid settler id %i!", v16);
    return 0;
  }
}


// address=[0x1583370]
// Decompiled from int __thiscall CSettlerMgr::OrderSpecialist(CSettlerMgr *this, int a2, int a3)
int  CSettlerMgr::OrderSpecialist(int,int) {
  
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // esi
  int v8; // eax
  int v9; // [esp-4h] [ebp-60h]
  _BYTE v10[24]; // [esp+8h] [ebp-54h] BYREF
  CEntityEvent *v11; // [esp+20h] [ebp-3Ch]
  CEntityEvent *v12; // [esp+24h] [ebp-38h]
  CSettlerMgr *v13; // [esp+28h] [ebp-34h]
  unsigned int v14; // [esp+2Ch] [ebp-30h]
  unsigned int v15; // [esp+30h] [ebp-2Ch]
  int v16; // [esp+34h] [ebp-28h]
  _DWORD *v17; // [esp+38h] [ebp-24h]
  int v18; // [esp+3Ch] [ebp-20h]
  int FirstSettlerId; // [esp+40h] [ebp-1Ch]
  int v20; // [esp+44h] [ebp-18h]
  _DWORD *v21; // [esp+48h] [ebp-14h]
  unsigned __int8 *VehiclePtr; // [esp+4Ch] [ebp-10h]
  int v23; // [esp+58h] [ebp-4h]

  v13 = this;
  if ( CSettlerMgr::SettlerWarriorType(a3) != 7
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1363,
         "SettlerWarriorType(_iSettlerType) == WARRIOR_TYPE_MISC_UNIT") == 1 )
  {
    __debugbreak();
  }
  v14 = -1;
  VehiclePtr = (unsigned __int8 *)CVehicleMgr::GetVehiclePtr(a2);
  if ( !VehiclePtr && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1369, "pWheeler!= NULL") == 1 )
    __debugbreak();
  if ( !VehiclePtr )
    return 0;
  v4 = IEntity::WorldIdx();
  v16 = CWorldManager::SectorId(v4);
  if ( !v16 && BBSupportDbgReportF(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1376, "Stand on sector 0!") == 1 )
    __debugbreak();
  v18 = IEntity::OwnerId(VehiclePtr);
  if ( !v18 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1379, "iOwnerId != 0") == 1 )
    __debugbreak();
  FirstSettlerId = CSettlerMgr::GetFirstSettlerId(v13, v18, a3);
  v20 = 0;
  while ( FirstSettlerId )
  {
    v21 = (_DWORD *)CSettlerMgr::operator[](FirstSettlerId);
    if ( IEntity::FlagBits(v21, Selectable) )
    {
      v5 = IEntity::WorldIdx();
      if ( CWorldManager::SectorId(v5) == v16 )
      {
        v6 = IEntity::Y(VehiclePtr);
        v9 = v6 - IEntity::Y(v21);
        v7 = IEntity::X(VehiclePtr);
        v8 = IEntity::X(v21);
        v15 = Grid::Distance((Grid *)(v7 - v8), v9);
        if ( v15 < v14 )
        {
          v14 = v15;
          v20 = FirstSettlerId;
        }
      }
    }
    FirstSettlerId = IAnimatedEntity::Next(v21);
  }
  if ( !v20 )
    return 0;
  v17 = (_DWORD *)CSettlerMgr::operator[](v20);
  IEntity::ClearFlagBits(v17, Selectable);
  if ( v18 == CPlayerManager::GetLocalPlayerId() )
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, v20);
  v12 = CEntityEvent::CEntityEvent((CEntityEvent *)v10, 0x18u, 0, a2, 0, 0);
  v11 = v12;
  v23 = 0;
  (*(void (__thiscall **)(_DWORD *, CEntityEvent *))(*v17 + 80))(v17, v12);
  v23 = -1;
  CEntityEvent::~CEntityEvent(v10);
  return v20;
}


// address=[0x15835e0]
// Decompiled from int __thiscall CSettlerMgr::OrderWarriorToTower(CSettlerMgr *this, int a2, int a3)
void  CSettlerMgr::OrderWarriorToTower(int,int) {
  
  int v3; // esi
  _BYTE v5[24]; // [esp+8h] [ebp-34h] BYREF
  CEntityEvent *v6; // [esp+20h] [ebp-1Ch]
  CEntityEvent *v7; // [esp+24h] [ebp-18h]
  CSettlerMgr *v8; // [esp+28h] [ebp-14h]
  unsigned __int8 *SettlerPtr; // [esp+2Ch] [ebp-10h]
  int v10; // [esp+38h] [ebp-4h]

  v8 = this;
  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1223, "_iBuildingId > 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1224, "_iSettlerId > 0") == 1 )
    __debugbreak();
  SettlerPtr = CSettlerMgr::GetSettlerPtr(a3);
  if ( !SettlerPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1228, "pSettler != 0") == 1 )
    __debugbreak();
  IEntity::ClearFlagBits(SettlerPtr, Selectable);
  v3 = IEntity::OwnerId(SettlerPtr);
  if ( v3 == CPlayerManager::GetLocalPlayerId() )
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, a3);
  IEntity::RemoveFromAllGroups();
  CSettler::AttachToBuilding((CSettler *)SettlerPtr, a2);
  v7 = CEntityEvent::CEntityEvent((CEntityEvent *)v5, 1u, 0, a2, 0, 0);
  v6 = v7;
  v10 = 0;
  (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v7);
  v10 = -1;
  return CEntityEvent::~CEntityEvent(v5);
}


// address=[0x1583730]
// Decompiled from _DWORD *__cdecl CSettlerMgr::FillSettlerAmount(void **a1, char a2, char a3)
static void __cdecl CSettlerMgr::FillSettlerAmount(class CInfoExchange *,bool,bool) {
  
  _DWORD *result; // eax
  int v4; // [esp+8h] [ebp-64h]
  int v5; // [esp+Ch] [ebp-60h]
  unsigned int v6; // [esp+10h] [ebp-5Ch]
  int NrOfStrikingCarriersInEcoSector; // [esp+18h] [ebp-54h]
  int v8; // [esp+1Ch] [ebp-50h]
  int v9; // [esp+20h] [ebp-4Ch]
  int LocalPlayerEcoSectorIdAtCenter; // [esp+28h] [ebp-44h]
  CEcoSector *v11; // [esp+2Ch] [ebp-40h]
  int i; // [esp+30h] [ebp-3Ch]
  int v13; // [esp+34h] [ebp-38h]
  unsigned int v14; // [esp+38h] [ebp-34h]
  int LocalPlayerId; // [esp+3Ch] [ebp-30h]
  int v16; // [esp+40h] [ebp-2Ch]
  int NumberOfSettlers; // [esp+40h] [ebp-2Ch]
  int v18; // [esp+40h] [ebp-2Ch]
  int v19; // [esp+40h] [ebp-2Ch]
  int v20; // [esp+40h] [ebp-2Ch]
  int v21; // [esp+40h] [ebp-2Ch]
  int v22; // [esp+40h] [ebp-2Ch]
  int v23; // [esp+40h] [ebp-2Ch]
  int v24; // [esp+40h] [ebp-2Ch]
  int v25; // [esp+40h] [ebp-2Ch]
  int v26; // [esp+40h] [ebp-2Ch]
  int v27; // [esp+40h] [ebp-2Ch]
  int v28; // [esp+40h] [ebp-2Ch]
  CEvn_Event v29; // [esp+44h] [ebp-28h] BYREF
  int v30; // [esp+68h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2033, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  result = (_DWORD *)j____RTDynamicCast(
                       a1,
                       0,
                       &CInfoExchange__RTTI_Type_Descriptor_,
                       &CSettlerStatisticInfo__RTTI_Type_Descriptor_,
                       0);
  v14 = (unsigned int)result;
  if ( !result )
  {
    result = (_DWORD *)BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2037, "pSettlerMenu != 0");
    if ( result == (_DWORD *)1 )
      __debugbreak();
  }
  if ( !v14 )
    return result;
  *(_BYTE *)(v14 + 8) = a3;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  LocalPlayerEcoSectorIdAtCenter = 0;
  v11 = 0;
  if ( a3 )
  {
    LocalPlayerEcoSectorIdAtCenter = CEcoSectorMgr::GetLocalPlayerEcoSectorIdAtCenter();
    if ( LocalPlayerEcoSectorIdAtCenter <= 0 )
      v9 = 0;
    else
      v9 = CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, LocalPlayerEcoSectorIdAtCenter);
    v11 = (CEcoSector *)v9;
  }
  for ( i = 0; i < 36; ++i )
  {
    v13 = *(_DWORD *)(v14 + 8 * i + 40);
    if ( v13 )
    {
      v16 = 0;
      switch ( v13 )
      {
        case 29:
        case 30:
        case 31:
          NumberOfSettlers = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 29);
          v18 = NumberOfSettlers + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 30);
          v16 = v18 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 31);
          break;
        case 32:
        case 33:
        case 34:
          v19 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 32);
          v20 = v19 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 33);
          v16 = v20 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 34);
          break;
        case 35:
        case 36:
        case 37:
          v21 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 35);
          v22 = v21 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 36);
          v16 = v22 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 37);
          break;
        case 38:
        case 39:
        case 40:
          v23 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 38);
          v24 = v23 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 39);
          v16 = v24 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 40);
          break;
        case 41:
        case 42:
        case 43:
          v25 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 41);
          v26 = v25 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 42);
          v16 = v26 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 43);
          break;
        case 61:
        case 62:
        case 63:
          v27 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 61);
          v28 = v27 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 62);
          v16 = v28 + CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 63);
          break;
        default:
          v5 = CSettlerMgr::SettlerWarriorType(v13);
          if ( !a3 || v5 )
          {
            v16 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, v13);
          }
          else if ( v11 )
          {
            v16 = CEcoSector::NrOfSettler(v11, v13);
          }
          break;
      }
      *(_DWORD *)(v14 + 8 * i + 44) = v16;
    }
  }
  *(_DWORD *)(v14 + 12) = CEcoSectorMgr::GetNrOfCurrentTotalBeds((CEcoSectorMgr *)g_cESMgr, LocalPlayerId);
  *(_DWORD *)(v14 + 16) = CEcoSectorMgr::GetNrOfInitialFreeBeds((CEcoSectorMgr *)g_cESMgr, LocalPlayerId);
  *(_DWORD *)(v14 + 20) = *(_DWORD *)(v14 + 12) - *(_DWORD *)(v14 + 16);
  v4 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 1);
  *(_DWORD *)(v14 + 28) = CEcoSectorMgr::GetNrStrikingCarriers((CEcoSectorMgr *)g_cESMgr, LocalPlayerId);
  *(_DWORD *)(v14 + 24) = v4 - *(_DWORD *)(v14 + 28);
  if ( a3 )
  {
    if ( v11 )
      v8 = CEcoSector::NrOfSettler(v11, 1);
    else
      v8 = 0;
    if ( LocalPlayerEcoSectorIdAtCenter <= 0 )
      NrOfStrikingCarriersInEcoSector = 0;
    else
      NrOfStrikingCarriersInEcoSector = CEcoSectorMgr::GetNrOfStrikingCarriersInEcoSector(
                                          (CEcoSectorMgr *)g_cESMgr,
                                          LocalPlayerEcoSectorIdAtCenter);
    *(_DWORD *)(v14 + 36) = NrOfStrikingCarriersInEcoSector;
    *(_DWORD *)(v14 + 32) = v8 - NrOfStrikingCarriersInEcoSector;
  }
  else
  {
    *(_DWORD *)(v14 + 36) = *(_DWORD *)(v14 + 28);
    *(_DWORD *)(v14 + 32) = *(_DWORD *)(v14 + 24);
  }
  *(_DWORD *)(v14 + 4) = 29;
  v6 = 604;
  if ( !a2 )
    v6 = 602;
  CEvn_Event::CEvn_Event(&v29, v6, 0, v14, 0);
  v30 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2186, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v29);
  v30 = -1;
  return CEvn_Event::~CEvn_Event(&v29);
}


// address=[0x1583c60]
// Decompiled from _DWORD *__cdecl CSettlerMgr::FillFreeCarrier(void **a1, char a2)
static void __cdecl CSettlerMgr::FillFreeCarrier(class CInfoExchange *,bool,bool) {
  
  int LocalPlayerId; // [esp+4h] [ebp-40h]
  unsigned int v4; // [esp+8h] [ebp-3Ch]
  int UserESInMiddleOfTheScreen; // [esp+Ch] [ebp-38h]
  CEcoSector *v6; // [esp+10h] [ebp-34h]
  char v7; // [esp+15h] [ebp-2Fh]
  CEvn_Event v8; // [esp+1Ch] [ebp-28h] BYREF
  int v9; // [esp+40h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2304, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(a1, 0, &CInfoExchange__RTTI_Type_Descriptor_, &CFreeCarrierInfo__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         2305,
         "dynamic_cast<CFreeCarrierInfo*>(_pInfoExchange) != 0") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(void **))*a1)(a1);
  v7 = 0;
  UserESInMiddleOfTheScreen = CSettlerMgr::GetUserESInMiddleOfTheScreen();
  if ( UserESInMiddleOfTheScreen )
  {
    v6 = (CEcoSector *)CEcoSectorMgr::operator[](UserESInMiddleOfTheScreen);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    if ( CEcoSector::Owner(v6) == LocalPlayerId )
    {
      a1[2] = (void *)CEcoSector::NrOfSettler(v6, 1);
      a1[3] = (void *)CEcoSector::MinCarrier(v6);
      a1[4] = (void *)((_BYTE *)a1[2] - (_BYTE *)a1[3]);
      a1[5] = (void *)CEcoSector::NrOfSettler(v6, 2);
      a1[6] = (void *)CEcoSector::WorkerDeltaAmount(v6, 2);
      *((_BYTE *)a1 + 28) = CEcoSector::NrOfGoods(v6, 31) > 0;
      a1[8] = (void *)CEcoSector::NrOfGoods(v6, 31);
      a1[9] = (void *)CEcoSector::NrOfSettler(v6, 3);
      a1[10] = (void *)CEcoSector::WorkerDeltaAmount(v6, 3);
      *((_BYTE *)a1 + 44) = CEcoSector::NrOfGoods(v6, 18) > 0;
      a1[12] = (void *)CEcoSector::NrOfGoods(v6, 18);
      *((_BYTE *)a1 + 52) = 1;
      v7 = 1;
    }
  }
  if ( !v7 )
  {
    a1[2] = 0;
    a1[3] = 0;
    a1[4] = 0;
    a1[5] = 0;
    a1[6] = 0;
    *((_BYTE *)a1 + 28) = 0;
    a1[9] = 0;
    a1[10] = 0;
    *((_BYTE *)a1 + 44) = 0;
    *((_BYTE *)a1 + 52) = 0;
  }
  a1[1] = (void *)31;
  v4 = 604;
  if ( !a2 )
    v4 = 602;
  CEvn_Event::CEvn_Event(&v8, v4, 0, (unsigned int)a1, 0);
  v9 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2377, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v8);
  v9 = -1;
  return CEvn_Event::~CEvn_Event(&v8);
}


// address=[0x1583f30]
// Decompiled from _DWORD *__cdecl CSettlerMgr::FillSpecialistProduction(void **a1, char a2)
static void __cdecl CSettlerMgr::FillSpecialistProduction(class CInfoExchange *,bool,bool) {
  
  int v2; // esi
  int v3; // eax
  int SettlerInfo; // eax
  unsigned int v6; // [esp+Ch] [ebp-64h]
  void *v7; // [esp+10h] [ebp-60h]
  int UserESInMiddleOfTheScreen; // [esp+14h] [ebp-5Ch]
  int LocalPlayerId; // [esp+18h] [ebp-58h]
  void *v10; // [esp+1Ch] [ebp-54h]
  int j; // [esp+20h] [ebp-50h]
  CEcoSector *v12; // [esp+24h] [ebp-4Ch]
  int i; // [esp+28h] [ebp-48h]
  char v14; // [esp+2Eh] [ebp-42h]
  CEvn_Event v15; // [esp+34h] [ebp-3Ch] BYREF
  _DWORD v16[5]; // [esp+4Ch] [ebp-24h]
  int v17; // [esp+6Ch] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2206, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(
          a1,
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
  (*(void (__thiscall **)(void **))*a1)(a1);
  v14 = 0;
  v16[0] = 48;
  v16[1] = 50;
  v16[2] = 49;
  v16[3] = 46;
  v16[4] = 47;
  UserESInMiddleOfTheScreen = CSettlerMgr::GetUserESInMiddleOfTheScreen();
  if ( UserESInMiddleOfTheScreen )
  {
    v12 = (CEcoSector *)CEcoSectorMgr::operator[](UserESInMiddleOfTheScreen);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    if ( CEcoSector::Owner(v12) == LocalPlayerId )
    {
      v2 = CEcoSector::NrOfSettler(v12, 1);
      a1[38] = (void *)(v2 - CEcoSector::MinCarrier(v12));
      if ( (int)a1[38] <= 0 )
        a1[38] = 0;
      for ( i = 0; i < 5; ++i )
      {
        v10 = (void *)v16[i];
        a1[6 * i + 2] = v10;
        a1[6 * i + 3] = (void *)CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, v10);
        a1[6 * i + 4] = (void *)CEcoSector::SpecialistWishes(v12, v10);
        v3 = CPlayerManager::Race(LocalPlayerId);
        SettlerInfo = CSettlerMgr::GetSettlerInfo(v3, (int)v10);
        v7 = (void *)CEcoSector::NrOfGoods(v12, *(unsigned __int8 *)(SettlerInfo + 5));
        LOBYTE(a1[6 * i + 5]) = (int)v7 > 0;
        a1[6 * i + 6] = v7;
      }
      *((_BYTE *)a1 + 156) = 1;
      v14 = 1;
    }
  }
  if ( !v14 )
  {
    a1[38] = 0;
    for ( j = 0; j < 5; ++j )
    {
      LOBYTE(a1[6 * j + 5]) = 0;
      BYTE1(a1[6 * j + 5]) = 0;
    }
    *((_BYTE *)a1 + 156) = 0;
  }
  a1[1] = (void *)30;
  v6 = 604;
  if ( !a2 )
    v6 = 602;
  CEvn_Event::CEvn_Event(&v15, v6, 0, (unsigned int)a1, 0);
  v17 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2284, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v15);
  v17 = -1;
  return CEvn_Event::~CEvn_Event(&v15);
}


// address=[0x1584240]
// Decompiled from _DWORD *__cdecl CSettlerMgr::FillSoldierMenu(void **a1, char a2)
static void __cdecl CSettlerMgr::FillSoldierMenu(class CInfoExchange *,bool,bool) {
  
  int v3; // [esp+4h] [ebp-64h]
  int v4; // [esp+8h] [ebp-60h]
  int v5; // [esp+Ch] [ebp-5Ch]
  int v6; // [esp+10h] [ebp-58h]
  unsigned int v7; // [esp+14h] [ebp-54h]
  int v8; // [esp+18h] [ebp-50h]
  int LocalPlayerId; // [esp+1Ch] [ebp-4Ch]
  int v10; // [esp+20h] [ebp-48h]
  int v11; // [esp+24h] [ebp-44h]
  int i; // [esp+2Ch] [ebp-3Ch]
  unsigned __int8 *SettlerPtr; // [esp+30h] [ebp-38h]
  int v14; // [esp+34h] [ebp-34h]
  void **v15; // [esp+3Ch] [ebp-2Ch]
  CEvn_Event v16; // [esp+40h] [ebp-28h] BYREF
  int v17; // [esp+64h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2397, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(a1, 0, &CInfoExchange__RTTI_Type_Descriptor_, &CSoldierInfo__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         2398,
         "dynamic_cast<CSoldierInfo*>(_pInfoExchange) != 0") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(void **))*a1)(a1);
  v8 = CInputProcessor::Selection();
  v6 = std::vector<unsigned short>::size(v8);
  for ( i = 0; i < v6; ++i )
  {
    v5 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    SettlerPtr = CSettlerMgr::GetSettlerPtr(v5);
    if ( SettlerPtr )
    {
      v14 = IEntity::Type((unsigned __int16 *)SettlerPtr);
      v15 = 0;
      switch ( v14 )
      {
        case 29:
        case 30:
        case 31:
          v15 = &a1[3 * v14 - 85];
          break;
        case 32:
        case 33:
        case 34:
          v15 = &a1[3 * v14 - 85];
          break;
        case 35:
        case 36:
        case 37:
          v15 = &a1[3 * v14 - 85];
          break;
        case 38:
        case 39:
        case 40:
          v15 = &a1[3 * v14 - 94];
          break;
        case 41:
        case 42:
        case 43:
          v15 = &a1[3 * v14 - 103];
          break;
        case 44:
          v15 = a1 + 29;
          break;
        case 45:
          v15 = a1 + 32;
          break;
        case 61:
        case 62:
        case 63:
          v15 = &a1[3 * v14 - 163];
          break;
        default:
          break;
      }
      if ( v15 )
      {
        v3 = IEntity::Race(SettlerPtr);
        v4 = IEntity::Type((unsigned __int16 *)SettlerPtr);
        v10 = *(unsigned __int8 *)(CSettlerMgr::GetSettlerInfo(v3, v4) + 2);
        v11 = IEntity::Hitpoints((IEntity *)SettlerPtr);
        if ( v11 > v10 )
          v11 = v10;
        *v15 = (char *)*v15 + v11;
        v15[1] = (char *)v15[1] + v10 - v11;
        v15[2] = (char *)v15[2] + 1;
      }
    }
  }
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  a1[35] = (void *)CStatistic::OffenceStrength100((CStatistic *)&g_cStatistic, LocalPlayerId);
  a1[36] = (void *)CStatistic::DefenceStrength100((CStatistic *)&g_cStatistic, LocalPlayerId);
  a1[37] = (void *)CStatistic::GetMana((CStatistic *)&g_cStatistic, LocalPlayerId);
  a1[1] = (void *)18;
  v7 = 604;
  if ( !a2 )
    v7 = 602;
  CEvn_Event::CEvn_Event(&v16, v7, 0, (unsigned int)a1, 0);
  v17 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2529, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v16);
  v17 = -1;
  return CEvn_Event::~CEvn_Event(&v16);
}


// address=[0x15845d0]
// Decompiled from _DWORD *__cdecl CSettlerMgr::FillSpecialistMenu(void **a1, char a2)
static void __cdecl CSettlerMgr::FillSpecialistMenu(class CInfoExchange *,bool,bool) {
  
  unsigned __int16 *v2; // eax
  int v4; // [esp+4h] [ebp-60h]
  int v5; // [esp+8h] [ebp-5Ch]
  int v6; // [esp+14h] [ebp-50h]
  unsigned int v7; // [esp+18h] [ebp-4Ch]
  int v8; // [esp+1Ch] [ebp-48h]
  int v9; // [esp+20h] [ebp-44h]
  int v10; // [esp+24h] [ebp-40h]
  int i; // [esp+2Ch] [ebp-38h]
  unsigned __int8 *SettlerPtr; // [esp+30h] [ebp-34h]
  void **v13; // [esp+38h] [ebp-2Ch]
  CEvn_Event v14; // [esp+3Ch] [ebp-28h] BYREF
  int v15; // [esp+60h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 2550, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(a1, 0, &CInfoExchange__RTTI_Type_Descriptor_, &CSpecialistsInfo__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         2551,
         "dynamic_cast<CSpecialistsInfo*>(_pInfoExchange) != 0") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(void **))*a1)(a1);
  v8 = CInputProcessor::Selection();
  v6 = std::vector<unsigned short>::size(v8);
  for ( i = 0; i < v6; ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    SettlerPtr = CSettlerMgr::GetSettlerPtr(*v2);
    if ( SettlerPtr )
    {
      v13 = 0;
      switch ( IEntity::Type((unsigned __int16 *)SettlerPtr) )
      {
        case '.':
          v13 = a1 + 8;
          break;
        case '/':
          v13 = a1 + 11;
          break;
        case '0':
          v13 = a1 + 14;
          break;
        case '1':
          v13 = a1 + 5;
          break;
        case '2':
          v13 = a1 + 2;
          break;
        default:
          break;
      }
      if ( v13 )
      {
        v4 = IEntity::Race(SettlerPtr);
        v5 = IEntity::Type((unsigned __int16 *)SettlerPtr);
        v9 = *(unsigned __int8 *)(CSettlerMgr::GetSettlerInfo(v4, v5) + 2);
        v10 = IEntity::Hitpoints((IEntity *)SettlerPtr);
        if ( v10 > v9 )
          v10 = v9;
        *v13 = (char *)*v13 + v10;
        v13[1] = (char *)v13[1] + v9 - v10;
        v13[2] = (char *)v13[2] + 1;
      }
    }
  }
  a1[1] = (void *)19;
  v7 = 604;
  if ( !a2 )
    v7 = 602;
  CEvn_Event::CEvn_Event(&v14, v7, 0, (unsigned int)a1, 0);
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
void  CSettlerMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-334h] BYREF
  _DWORD v5[43]; // [esp+10h] [ebp-324h] BYREF
  size_t Size; // [esp+BCh] [ebp-278h]
  void *Src; // [esp+C0h] [ebp-274h]
  unsigned __int8 *v8; // [esp+C4h] [ebp-270h]
  unsigned __int8 *v9; // [esp+C8h] [ebp-26Ch]
  unsigned __int8 *SettlerPtr; // [esp+CCh] [ebp-268h]
  int UsedId; // [esp+D0h] [ebp-264h]
  int v12; // [esp+D4h] [ebp-260h] BYREF
  int v13; // [esp+D8h] [ebp-25Ch]
  unsigned __int8 *v14; // [esp+DCh] [ebp-258h]
  int v15; // [esp+E0h] [ebp-254h] BYREF
  int j; // [esp+E4h] [ebp-250h]
  int i; // [esp+E8h] [ebp-24Ch]
  CSettlerMgr *v18; // [esp+ECh] [ebp-248h]
  int m; // [esp+F0h] [ebp-244h]
  int k; // [esp+F4h] [ebp-240h]
  int *v21; // [esp+324h] [ebp-10h]
  int v22; // [esp+330h] [ebp-4h]

  v21 = &v4;
  v18 = this;
  std::ostrstream::ostrstream(0, 0x40000, 0, 2, 1);
  v22 = 0;
  v5[42] = std::ios_base::exceptions((char *)v5 + *(_DWORD *)(v5[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v22) = 1;
  v12 = 1;
  operator^<unsigned int>((struct std::ostream *)v5, &v12);
  UsedId = CMapObjectMgr::LastUsedId();
  v13 = UsedId;
  v15 = 0;
  for ( i = 1; i <= v13; ++i )
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr(i);
    v9 = SettlerPtr;
    if ( SettlerPtr )
      ++v15;
  }
  operator^<unsigned int>((struct std::ostream *)v5, &v15);
  for ( j = 1; j <= v13; ++j )
  {
    v8 = CSettlerMgr::GetSettlerPtr(j);
    v14 = v8;
    if ( v8 )
      (*(void (__thiscall **)(unsigned __int8 *, _DWORD *))(*(_DWORD *)v14 + 4))(v14, v5);
  }
  for ( k = 0; k < 9; ++k )
  {
    for ( m = 0; m < 67; ++m )
      operator^<int>((int)v5, (int *)v18 + 67 * k + m + 7);
  }
  for ( k = 0; k < 9; ++k )
  {
    for ( m = 0; m < 67; ++m )
      operator^<int>((int)v5, (int *)v18 + 67 * k + m + 610);
  }
  for ( k = 0; k < 9; ++k )
  {
    for ( m = 0; m < 67; ++m )
      operator^<int>((int)v5, (int *)v18 + 67 * k + m + 1213);
  }
  std::ostream::put(0);
  v22 = 0;
  std::ostrstream::freeze((std::ostrstream *)v5, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(161, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  v22 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x1584c80]
// Decompiled from void __thiscall CSettlerMgr::Load(CSettlerMgr *this, struct S4::CMapFile *a2)
void  CSettlerMgr::Load(class S4::CMapFile &) {
  
  int v2; // [esp+0h] [ebp-100h] BYREF
  _DWORD v3[44]; // [esp+10h] [ebp-F0h] BYREF
  unsigned int v4; // [esp+C0h] [ebp-40h]
  _DWORD *v5; // [esp+C4h] [ebp-3Ch]
  _DWORD *v6; // [esp+C8h] [ebp-38h]
  int v7; // [esp+CCh] [ebp-34h]
  int v8; // [esp+D0h] [ebp-30h] BYREF
  int v9; // [esp+D4h] [ebp-2Ch] BYREF
  unsigned int v10; // [esp+D8h] [ebp-28h] BYREF
  int pExceptionObject; // [esp+DCh] [ebp-24h] BYREF
  char *Str; // [esp+E0h] [ebp-20h]
  CSettlerMgr *v13; // [esp+E4h] [ebp-1Ch]
  int j; // [esp+E8h] [ebp-18h]
  int i; // [esp+ECh] [ebp-14h]
  int *v16; // [esp+F0h] [ebp-10h]
  int v17; // [esp+FCh] [ebp-4h]

  v16 = &v2;
  v13 = this;
  CTrace::Print("CSettlerMgr load");
  CSettlerMgr::Clear(v13);
  v9 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xA1u, 0, &v9, 0);
  if ( Str )
  {
    std::istrstream::istrstream(Str, 1);
    v17 = 0;
    v4 = std::ios_base::exceptions((char *)v3 + *(_DWORD *)(v3[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), 6);
    LOBYTE(v17) = 1;
    operator^<unsigned int>(v3, &v8);
    v7 = v8;
    if ( v8 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSettlerMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v10 = 0;
    operator^<unsigned int>(v3, &v10);
    for ( i = 0; i < v10; ++i )
    {
      v6 = (_DWORD *)CPersistence::New(v3, v2);
      v5 = v6;
      ++*((_WORD *)v13 + 12);
      IEntity::ClearFlagBits(v5, Selected);
    }
    for ( i = 0; i < 9; ++i )
    {
      for ( j = 0; j < 67; ++j )
        operator^<int>((int)v3, (int)v13 + 268 * i + 4 * j + 28);
    }
    for ( i = 0; i < 9; ++i )
    {
      for ( j = 0; j < 67; ++j )
        operator^<int>((int)v3, (int)v13 + 268 * i + 4 * j + 2440);
    }
    for ( i = 0; i < 9; ++i )
    {
      for ( j = 0; j < 67; ++j )
        operator^<int>((int)v3, (int)v13 + 268 * i + 4 * j + 4852);
    }
    v17 = 0;
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), v4);
    v17 = -1;
    std::istrstream::`vbase destructor'((std::istrstream *)v3);
  }
}


// address=[0x1584f70]
// Decompiled from void __thiscall CSettlerMgr::IncNumberOfSettler(CSettlerMgr *this, int a2, int a3)
void  CSettlerMgr::IncNumberOfSettler(int,int) {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1036,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1037,
         "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++*((_DWORD *)this + 67 * a2 + a3 + 610);
  CStatistic::AddSettler((CStatistic *)&g_cStatistic, a2, a3);
}


// address=[0x1585020]
// Decompiled from void __thiscall CSettlerMgr::DecNumberOfSettler(CSettlerMgr *this, int a2, int a3)
void  CSettlerMgr::DecNumberOfSettler(int,int) {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1053,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1054,
         "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 67 * a2 + a3 + 610) <= 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1056,
         "m_vPlayerSettlerNumber[_iPlayerId][_iSettlerType] > 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 67 * a2 + a3 + 610) > 0 )
    --*((_DWORD *)this + 67 * a2 + a3 + 610);
  CStatistic::DecSettler((CStatistic *)&g_cStatistic, a2, a3);
}


// address=[0x15889c0]
// Decompiled from unsigned __int8 *__thiscall CSettlerMgr::Settler(CSettlerMgr *this, int a2)
class CSettler &  CSettlerMgr::Settler(int) {
  
  unsigned __int8 *v3; // [esp+4h] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a2);
  if ( !v3
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         314,
         "pEntity != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::ObjType(v3) != 1
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         315,
         "pEntity->ObjType() == SETTLER_OBJ") == 1 )
  {
    __debugbreak();
  }
  return v3;
}


// address=[0x1592200]
// Decompiled from int __cdecl CSettlerMgr::GetSquadLeaderBonus256(int a1)
static int __cdecl CSettlerMgr::GetSquadLeaderBonus256(int) {
  
  return CSettlerMgr::m_iSquadLeaderBoni256[a1];
}


// address=[0x15a7b80]
// Decompiled from int __cdecl CSettlerMgr::SettlerWarriorLevel(int a1)
static int __cdecl CSettlerMgr::SettlerWarriorLevel(int) {
  
  if ( !CSettlerMgr::m_uSettlerWarriorLevels[29]
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Settler\\SettlerMgr.h",
         359,
         "m_uSettlerWarriorLevels[SETTLER_SWORDSMAN_01] != 0") == 1 )
  {
    __debugbreak();
  }
  return (unsigned __int8)CSettlerMgr::m_uSettlerWarriorLevels[a1];
}


// address=[0x1585120]
// Decompiled from IAnimatedEntity *__thiscall CSettlerMgr::AttachSettler(CSettlerMgr *this, CSettler *settler)
void  CSettlerMgr::AttachSettler(class CSettler &) {
  
  IAnimatedEntity *result; // eax
  CSettler *SettlerPtr; // [esp+0h] [ebp-18h]
  int entityId; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int type; // [esp+10h] [ebp-8h]
  int ownerId; // [esp+14h] [ebp-4h]

  if ( IEntity::FlagBits(settler, Offered)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 806, "_rSettler.FlagBits(ENTITY_FLAG_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(settler, GlobalOffered)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         807,
         "_rSettler.FlagBits(ENTITY_FLAG_GLOBAL_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::Previous(settler)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 808, "_rSettler.Previous() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::Next(settler)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 809, "_rSettler.Next() == 0") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(settler, Offered);
  IEntity::SetFlagBits(settler, GlobalOffered);
  ownerId = IEntity::OwnerId(settler);
  entityId = IEntity::EntityId(settler);
  type = IEntity::Type(settler);
  if ( ownerId < 1
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 818, "iPlayerId >= PLAYER_FIRST") == 1 )
  {
    __debugbreak();
  }
  if ( ownerId > 8 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 819, "iPlayerId <= PLAYER_LAST") == 1 )
    __debugbreak();
  if ( entityId <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 820, "iSettlerId > 0") == 1 )
    __debugbreak();
  if ( type <= 0
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 821, "iSettlerType > SETTLER_NO_SETTLER") == 1 )
  {
    __debugbreak();
  }
  if ( type >= 67
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 822, "iSettlerType < SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  ++*((_DWORD *)this + 67 * ownerId + type + 1213);
  v5 = *((_DWORD *)this + 67 * ownerId + type + 7);
  if ( v5 == entityId
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 828, "iOldHeadId != iSettlerId") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 67 * ownerId + type + 7) = entityId;
  IAnimatedEntity::SetPrevious(settler, 0);
  result = (IAnimatedEntity *)IAnimatedEntity::SetNext(settler, v5);
  if ( !v5 )
    return result;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(v5);
  if ( !SettlerPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 839, "pOldHead != 0") == 1 )
    __debugbreak();
  if ( !IAnimatedEntity::Previous(SettlerPtr) )
    return IAnimatedEntity::SetPrevious(SettlerPtr, entityId);
  if ( BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 841, "pOldHead->Previous() == 0") == 1 )
    __debugbreak();
  return IAnimatedEntity::SetPrevious(SettlerPtr, entityId);
}


// address=[0x15853f0]
// Decompiled from int __thiscall CSettlerMgr::DetachSettler(int *this, unsigned __int8 *a2)
void  CSettlerMgr::DetachSettler(class CSettler &) {
  
  unsigned __int8 *v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+4h] [ebp-1Ch]
  unsigned __int8 *SettlerPtr; // [esp+8h] [ebp-18h]
  int v6; // [esp+Ch] [ebp-14h]
  int v7; // [esp+10h] [ebp-10h]
  int v9; // [esp+18h] [ebp-8h]
  int v10; // [esp+1Ch] [ebp-4h]

  if ( IEntity::FlagBits(a2, Offered)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 889, "_rSettler.FlagBits(ENTITY_FLAG_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !IEntity::FlagBits(a2, GlobalOffered)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         890,
         "_rSettler.FlagBits(ENTITY_FLAG_GLOBAL_OFFERED) != 0") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(a2, GlobalOffered|Offered);
  v10 = IEntity::OwnerId(a2);
  v6 = IEntity::EntityId((unsigned __int16 *)a2);
  v9 = IEntity::Type((unsigned __int16 *)a2);
  if ( v10 < 1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 898, "iPlayerId >= PLAYER_FIRST") == 1 )
    __debugbreak();
  if ( v10 > 8 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 899, "iPlayerId <= PLAYER_LAST") == 1 )
    __debugbreak();
  if ( v6 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 900, "iSettlerId > 0") == 1 )
    __debugbreak();
  if ( v9 <= 0
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 901, "iSettlerType > SETTLER_NO_SETTLER") == 1 )
  {
    __debugbreak();
  }
  if ( v9 >= 67 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 902, "iSettlerType < SETTLER_MAX") == 1 )
    __debugbreak();
  if ( this[67 * v10 + 1213 + v9] <= 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         904,
         "m_vPlayerSettlerOfferedNumber[iPlayerId][iSettlerType] > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this[67 * v10 + 1213 + v9] > 0 )
    --this[67 * v10 + 1213 + v9];
  v4 = IAnimatedEntity::Previous(a2);
  v7 = IAnimatedEntity::Next(a2);
  if ( v4 )
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr(v4);
    if ( !SettlerPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 918, "pPrevSettler != 0") == 1 )
      __debugbreak();
    if ( IAnimatedEntity::Next(SettlerPtr) != v6
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 919, "pPrevSettler->Next() == iSettlerId") == 1 )
    {
      __debugbreak();
    }
    IAnimatedEntity::SetNext(SettlerPtr, v7);
  }
  else
  {
    if ( this[67 * v10 + 7 + v9] != v6
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerMgr.cpp",
           925,
           "m_vPlayerSettler[iPlayerId][iSettlerType] == iSettlerId") == 1 )
    {
      __debugbreak();
    }
    this[67 * v10 + 7 + v9] = v7;
  }
  if ( v7 )
  {
    v3 = CSettlerMgr::GetSettlerPtr(v7);
    if ( !v3 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 934, "pNextSettler != 0") == 1 )
      __debugbreak();
    if ( IAnimatedEntity::Previous(v3) != v6
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 935, "pNextSettler->Previous() == iSettlerId") == 1 )
    {
      __debugbreak();
    }
    IAnimatedEntity::SetPrevious((IAnimatedEntity *)v3, v4);
  }
  IAnimatedEntity::SetPrevious((IAnimatedEntity *)a2, 0);
  return IAnimatedEntity::SetNext(a2, 0);
}


// address=[0x157ff60]
// Decompiled from unsigned int __thiscall CSettlerMgr::Alloc(CSettlerMgr *this, unsigned int a2)
void *  CSettlerMgr::Alloc(unsigned int) {
  
  return MemoryAllocator::allocate((unsigned int *)this, a2);
}


// address=[0x1580020]
// Decompiled from void __thiscall CSettlerMgr::Dealloc(CSettlerMgr *this, void *a2)
void  CSettlerMgr::Dealloc(void *) {
  
  MemoryAllocator::deallocate(this, a2);
}


// address=[0x1585740]
// Decompiled from void __thiscall CSettlerMgr::CheckOutSettler(CSettlerMgr *this, int a2)
void  CSettlerMgr::CheckOutSettler(int) {
  
  int v2; // eax
  int v3; // esi
  int v4; // [esp+4h] [ebp-20h]
  int v5; // [esp+Ch] [ebp-18h]
  int v6; // [esp+10h] [ebp-14h]
  int v7; // [esp+14h] [ebp-10h]
  CEcoSector *v8; // [esp+18h] [ebp-Ch]
  unsigned __int8 *v10; // [esp+20h] [ebp-4h]

  v10 = CSettlerMgr::Settler(this, a2);
  v4 = IEntity::OwnerId(v10);
  v7 = IEntity::Type((unsigned __int16 *)v10);
  if ( v7 < 67 )
  {
    if ( IEntity::WarriorType() )
    {
      CSettlerMgr::DetachSettler((int *)this, v10);
    }
    else
    {
      v2 = IEntity::WorldIdx();
      v6 = CWorldManager::EcoSectorId(v2);
      if ( v6 > 0 )
      {
        v8 = (CEcoSector *)CEcoSectorMgr::operator[](v6);
        v3 = CEcoSector::Owner(v8);
        if ( v3 == IEntity::OwnerId(v10) )
        {
          if ( IEntity::FlagBits(v10, Offered) )
            CEcoSector::GetSettlerOutOfOffer(v8, a2);
          v5 = CSettler::Role(v10);
          if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 72))(v5) != 18
            && !IEntity::FlagBits(v10, (EntityFlag)0x80u)
            && (!IEntity::FlagBits(v10, OnBoard) || IEntity::FlagBits(v10, (EntityFlag)0x10000000u)) )
          {
            CEcoSector::ChangeNrOfSettler(v8, v7, -1);
            IEntity::ClearFlagBits(v10, (EntityFlag)0x10000000u);
          }
        }
      }
    }
    CSettlerMgr::DecNumberOfSettler(this, v4, v7);
  }
  --*((_WORD *)this + 12);
  if ( IHJBMgr::GetHJBEntityId() == a2 )
    IHJBMgr::SetHJBEntityId(0);
}


// address=[0x15858b0]
// Decompiled from int CSettlerMgr::GetUserESInMiddleOfTheScreen()
static int __cdecl CSettlerMgr::GetUserESInMiddleOfTheScreen(void) {
  
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // esi
  int v5; // [esp+8h] [ebp-18h] BYREF
  int v6; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+14h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v9 = 0;
  v6 = 0;
  v5 = 0;
  CStateGame::GetCenterWorldCoordinate((CStateGame *)g_pGame, &v6, &v5);
  v7 = 0;
  v8 = 0;
  for ( i = 0; i < 100; ++i )
  {
    v0 = CSpiralOffsets::DeltaX(i);
    v7 = v6 + v0;
    v1 = CSpiralOffsets::DeltaY(i);
    v8 = v5 + v1;
    if ( (unsigned __int8)CWorldManager::InWorld(v7, v5 + v1) )
    {
      v9 = CWorldManager::EcoSectorId(v7, v8);
      if ( v9 )
      {
        v2 = CEcoSectorMgr::operator[](v9);
        v3 = CEcoSector::Owner(v2);
        if ( v3 == CPlayerManager::GetLocalPlayerId() )
          return v9;
      }
      else
      {
        v9 = 0;
      }
    }
  }
  return v9;
}


// address=[0x4152138]
// [Decompilation failed for static unsigned char * CSettlerMgr::m_uSettlerWarriorTypes]

// address=[0x4152180]
// [Decompilation failed for static unsigned char * CSettlerMgr::m_uSettlerWarriorLevels]

// address=[0x41521c8]
// [Decompilation failed for static int * CSettlerMgr::m_iSquadLeaderBoni256]

// address=[0x4153e40]
// [Decompilation failed for static struct CSettlerMgr::SSettlerInfos (* CSettlerMgr::m_vSettlerInfos)[70]]

