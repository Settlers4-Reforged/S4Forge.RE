#include "CSettlerMgr.h"

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
// Decompiled from unsigned __int8 *__stdcall CSettlerMgr::GetSettlerPtr(int a1)

class CSettler *  CSettlerMgr::GetSettlerPtr(int) {
  
  unsigned __int8 *v3; // [esp+Ch] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( v3 && IEntity::ObjType(v3) == 1 )
    return v3;
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
// Decompiled from char *__cdecl sub_1839BB0(int a1, int a2)

static struct CSettlerMgr::SSettlerInfos const & __cdecl CSettlerMgr::GetSettlerInfo(int,int) {
  
  return &CSettlerMgr::m_vSettlerInfos[3080 * a1 + 44 * a2];
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
  j__memset(CSettlerMgr::m_uSettlerWarriorTypes, 0, 0x46u);
  j__memset(CSettlerMgr::m_uSettlerWarriorLevels, 0, 0x46u);
  j__memset(CSettlerMgr::m_vSettlerInfos, 0, 0x3C28u);
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
  j__memset((char *)this + 28, 0, 0x96Cu);
  j__memset((char *)this + 2440, 0, 0x96Cu);
  j__memset((char *)this + 4852, 0, 0x96Cu);
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
  
  j__memset((char *)this + 28, 0, 0x96Cu);
  j__memset((char *)this + 2440, 0, 0x96Cu);
  j__memset((char *)this + 4852, 0, 0x96Cu);
  *((_WORD *)this + 12) = 0;
  return (*(int (__thiscall **)(void *))(*(_DWORD *)g_pHJBMgr + 20))(g_pHJBMgr);
}


// address=[0x15804a0]
// Decompiled from CCarrierRole *__thiscall CSettlerMgr::CreateSettlerRole(CSettlerMgr *this, unsigned int a2, int a3)

class ISettlerRole *  CSettlerMgr::CreateSettlerRole(int,int) {
  
  CCarrierRole *result; // eax
  CSquadLeaderRole *v4; // [esp+54h] [ebp-A8h]
  CSquadLeaderRole *v5; // [esp+58h] [ebp-A4h]
  CThiefRole *v6; // [esp+5Ch] [ebp-A0h]
  CThiefRole *v7; // [esp+60h] [ebp-9Ch]
  CDarkGardenerRole *v8; // [esp+64h] [ebp-98h]
  CDarkGardenerRole *v9; // [esp+68h] [ebp-94h]
  CMushroomFarmerRole *v10; // [esp+6Ch] [ebp-90h]
  CMushroomFarmerRole *v11; // [esp+70h] [ebp-8Ch]
  CShamanRole *v12; // [esp+74h] [ebp-88h]
  CShamanRole *v13; // [esp+78h] [ebp-84h]
  CSlaveRole *v14; // [esp+7Ch] [ebp-80h]
  CSlaveRole *v15; // [esp+80h] [ebp-7Ch]
  CPriestRole *v16; // [esp+84h] [ebp-78h]
  CPriestRole *v17; // [esp+88h] [ebp-74h]
  CGardenerRole *v18; // [esp+8Ch] [ebp-70h]
  CGardenerRole *v19; // [esp+90h] [ebp-6Ch]
  CPioneerRole *v20; // [esp+94h] [ebp-68h]
  CPioneerRole *v21; // [esp+98h] [ebp-64h]
  CSaboteurRole *v22; // [esp+9Ch] [ebp-60h]
  CSaboteurRole *v23; // [esp+A0h] [ebp-5Ch]
  CGeologistRole *v24; // [esp+A4h] [ebp-58h]
  CGeologistRole *v25; // [esp+A8h] [ebp-54h]
  CHunterRole *v26; // [esp+ACh] [ebp-50h]
  CHunterRole *v27; // [esp+B0h] [ebp-4Ch]
  CSoldierRole *v28; // [esp+B4h] [ebp-48h]
  CSoldierRole *v29; // [esp+B8h] [ebp-44h]
  CHouseWorkerRole *v30; // [esp+BCh] [ebp-40h]
  CHouseWorkerRole *v31; // [esp+C0h] [ebp-3Ch]
  CFreeWorkerRole *v32; // [esp+C4h] [ebp-38h]
  CFreeWorkerRole *v33; // [esp+C8h] [ebp-34h]
  CBuilderRole *v34; // [esp+CCh] [ebp-30h]
  CBuilderRole *v35; // [esp+D0h] [ebp-2Ch]
  CDiggerRole *v36; // [esp+D4h] [ebp-28h]
  CDiggerRole *v37; // [esp+D8h] [ebp-24h]
  CDonkeyRole *v38; // [esp+DCh] [ebp-20h]
  CDonkeyRole *v39; // [esp+E0h] [ebp-1Ch]
  CCarrierRole *v40; // [esp+E4h] [ebp-18h]
  CCarrierRole *C; // [esp+E8h] [ebp-14h]

  if ( a2 > 4 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1446, "_iRace>=0 && _iRace<RACE_MAX") == 1 )
    __debugbreak();
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         1447,
         "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  switch ( CSettlerMgr::m_vSettlerInfos[3080 * a2 + 44 * a3] )
  {
    case 1:
      C = (CCarrierRole *)operator new(0x38u);
      if ( C )
        v40 = CCarrierRole::CCarrierRole(C);
      else
        v40 = 0;
      result = v40;
      break;
    case 2:
      v37 = (CDiggerRole *)operator new(0x30u);
      if ( v37 )
        v36 = CDiggerRole::CDiggerRole(v37);
      else
        v36 = 0;
      result = v36;
      break;
    case 3:
      v35 = (CBuilderRole *)operator new(0x30u);
      if ( v35 )
        v34 = CBuilderRole::CBuilderRole(v35);
      else
        v34 = 0;
      result = v34;
      break;
    case 4:
      v31 = (CHouseWorkerRole *)operator new(0x34u);
      if ( v31 )
        v30 = CHouseWorkerRole::CHouseWorkerRole(v31);
      else
        v30 = 0;
      result = v30;
      break;
    case 5:
      v33 = (CFreeWorkerRole *)operator new(0x38u);
      if ( v33 )
        v32 = CFreeWorkerRole::CFreeWorkerRole(v33);
      else
        v32 = 0;
      result = v32;
      break;
    case 7:
      v29 = (CSoldierRole *)operator new(0x64u);
      if ( v29 )
        v28 = CSoldierRole::CSoldierRole(v29);
      else
        v28 = 0;
      result = v28;
      break;
    case 8:
      v27 = (CHunterRole *)operator new(0x30u);
      if ( v27 )
        v26 = CHunterRole::CHunterRole(v27);
      else
        v26 = 0;
      result = v26;
      break;
    case 9:
      v17 = (CPriestRole *)operator new(0x40u);
      if ( v17 )
        v16 = CPriestRole::CPriestRole(v17);
      else
        v16 = 0;
      result = v16;
      break;
    case 10:
      v23 = (CSaboteurRole *)operator new(0x68u);
      if ( v23 )
        v22 = CSaboteurRole::CSaboteurRole(v23);
      else
        v22 = 0;
      result = v22;
      break;
    case 11:
      v21 = (CPioneerRole *)operator new(0x4Cu);
      if ( v21 )
        v20 = CPioneerRole::CPioneerRole(v21);
      else
        v20 = 0;
      result = v20;
      break;
    case 12:
      v25 = (CGeologistRole *)operator new(0x54u);
      if ( v25 )
        v24 = CGeologistRole::CGeologistRole(v25);
      else
        v24 = 0;
      result = v24;
      break;
    case 13:
      v19 = (CGardenerRole *)operator new(0x54u);
      if ( v19 )
        v18 = CGardenerRole::CGardenerRole(v19);
      else
        v18 = 0;
      result = v18;
      break;
    case 14:
      v9 = (CDarkGardenerRole *)operator new(0x50u);
      if ( v9 )
        v8 = CDarkGardenerRole::CDarkGardenerRole(v9);
      else
        v8 = 0;
      result = v8;
      break;
    case 15:
      v11 = (CMushroomFarmerRole *)operator new(0x30u);
      if ( v11 )
        v10 = CMushroomFarmerRole::CMushroomFarmerRole(v11);
      else
        v10 = 0;
      result = v10;
      break;
    case 16:
      v13 = (CShamanRole *)operator new(0x74u);
      if ( v13 )
        v12 = CShamanRole::CShamanRole(v13);
      else
        v12 = 0;
      result = v12;
      break;
    case 17:
      v15 = (CSlaveRole *)operator new(0x38u);
      if ( v15 )
        v14 = CSlaveRole::CSlaveRole(v15);
      else
        v14 = 0;
      result = v14;
      break;
    case 19:
      v7 = (CThiefRole *)operator new(0x44u);
      if ( v7 )
        v6 = CThiefRole::CThiefRole(v7);
      else
        v6 = 0;
      result = v6;
      break;
    case 20:
      v39 = (CDonkeyRole *)operator new(0x7Cu);
      if ( v39 )
        v38 = CDonkeyRole::CDonkeyRole(v39);
      else
        v38 = 0;
      result = v38;
      break;
    case 23:
      v5 = (CSquadLeaderRole *)operator new(0x74u);
      if ( v5 )
        v4 = CSquadLeaderRole::CSquadLeaderRole(v5);
      else
        v4 = 0;
      result = v4;
      break;
    default:
      CTrace::Print("This settler type %s has no role ... ", (&off_37B2B0C)[2 * a3]);
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
  _DWORD v24[4]; // [esp+0h] [ebp-794h] BYREF
  _BYTE v25[28]; // [esp+10h] [ebp-784h] BYREF
  _BYTE v26[16]; // [esp+2Ch] [ebp-768h] BYREF
  _BYTE v27[16]; // [esp+4Ch] [ebp-748h] BYREF
  _BYTE v28[16]; // [esp+5Ch] [ebp-738h] BYREF
  _BYTE v29[16]; // [esp+6Ch] [ebp-728h] BYREF
  _BYTE v30[16]; // [esp+7Ch] [ebp-718h] BYREF
  _BYTE v31[16]; // [esp+8Ch] [ebp-708h] BYREF
  _BYTE v32[16]; // [esp+9Ch] [ebp-6F8h] BYREF
  _BYTE v33[16]; // [esp+ACh] [ebp-6E8h] BYREF
  _BYTE v34[16]; // [esp+BCh] [ebp-6D8h] BYREF
  _BYTE v35[16]; // [esp+CCh] [ebp-6C8h] BYREF
  _BYTE v36[16]; // [esp+DCh] [ebp-6B8h] BYREF
  _BYTE v37[16]; // [esp+ECh] [ebp-6A8h] BYREF
  int v38; // [esp+FCh] [ebp-698h]
  int v39; // [esp+100h] [ebp-694h]
  int v40; // [esp+104h] [ebp-690h]
  int v41; // [esp+108h] [ebp-68Ch]
  int v42; // [esp+10Ch] [ebp-688h]
  int v43; // [esp+110h] [ebp-684h]
  int v44; // [esp+114h] [ebp-680h]
  void *v45; // [esp+118h] [ebp-67Ch]
  void *v46; // [esp+11Ch] [ebp-678h]
  int v47; // [esp+120h] [ebp-674h]
  int v48; // [esp+124h] [ebp-670h]
  void *v49; // [esp+128h] [ebp-66Ch]
  int v50; // [esp+12Ch] [ebp-668h]
  int v51; // [esp+130h] [ebp-664h]
  int v52; // [esp+134h] [ebp-660h]
  int v53; // [esp+138h] [ebp-65Ch]
  int v54; // [esp+13Ch] [ebp-658h]
  _BYTE v55[16]; // [esp+140h] [ebp-654h] BYREF
  _BYTE v56[16]; // [esp+150h] [ebp-644h] BYREF
  int v57; // [esp+160h] [ebp-634h]
  int v58; // [esp+164h] [ebp-630h]
  int v59; // [esp+168h] [ebp-62Ch]
  int v60; // [esp+16Ch] [ebp-628h]
  _BYTE v61[16]; // [esp+170h] [ebp-624h] BYREF
  int v62; // [esp+180h] [ebp-614h]
  int v63; // [esp+184h] [ebp-610h]
  int v64; // [esp+188h] [ebp-60Ch]
  int v65; // [esp+18Ch] [ebp-608h]
  int v66; // [esp+190h] [ebp-604h]
  int v67; // [esp+194h] [ebp-600h]
  int v68; // [esp+198h] [ebp-5FCh]
  int v69; // [esp+19Ch] [ebp-5F8h]
  int v70; // [esp+1A0h] [ebp-5F4h]
  int ValueOfDefine; // [esp+1A4h] [ebp-5F0h]
  int v72; // [esp+1A8h] [ebp-5ECh]
  int v73; // [esp+1ACh] [ebp-5E8h]
  int v74; // [esp+1B0h] [ebp-5E4h]
  int v75; // [esp+1B4h] [ebp-5E0h]
  int v76; // [esp+1B8h] [ebp-5DCh]
  int v77; // [esp+1BCh] [ebp-5D8h]
  int v78; // [esp+1C0h] [ebp-5D4h]
  int Root; // [esp+1C4h] [ebp-5D0h]
  struct Document *v80; // [esp+1C8h] [ebp-5CCh]
  _BYTE *v81; // [esp+1CCh] [ebp-5C8h]
  void *C; // [esp+1D0h] [ebp-5C4h]
  int v83; // [esp+1D4h] [ebp-5C0h]
  int v84; // [esp+1D8h] [ebp-5BCh]
  CConfigManager *v85; // [esp+1DCh] [ebp-5B8h]
  void *v86; // [esp+1E0h] [ebp-5B4h]
  void *v87; // [esp+1E4h] [ebp-5B0h]
  int v88; // [esp+1E8h] [ebp-5ACh]
  int v89; // [esp+1ECh] [ebp-5A8h]
  int v90; // [esp+1F0h] [ebp-5A4h]
  int v91; // [esp+1F4h] [ebp-5A0h]
  int v92; // [esp+1F8h] [ebp-59Ch]
  int v93; // [esp+1FCh] [ebp-598h]
  int v94; // [esp+200h] [ebp-594h]
  int v95; // [esp+204h] [ebp-590h]
  int v96; // [esp+208h] [ebp-58Ch]
  const struct SSearchData *SearchData; // [esp+20Ch] [ebp-588h]
  int v98; // [esp+210h] [ebp-584h]
  void *v99; // [esp+214h] [ebp-580h]
  void *v100; // [esp+218h] [ebp-57Ch]
  int v101; // [esp+21Ch] [ebp-578h]
  int v102; // [esp+220h] [ebp-574h]
  int v103; // [esp+224h] [ebp-570h]
  int v104; // [esp+228h] [ebp-56Ch]
  int v105; // [esp+22Ch] [ebp-568h]
  int v106; // [esp+230h] [ebp-564h]
  int v107; // [esp+234h] [ebp-560h]
  int v108; // [esp+238h] [ebp-55Ch]
  int v109; // [esp+23Ch] [ebp-558h]
  void *v110; // [esp+240h] [ebp-554h]
  int v111; // [esp+244h] [ebp-550h]
  int v112; // [esp+248h] [ebp-54Ch]
  int v113; // [esp+24Ch] [ebp-548h]
  int v114; // [esp+250h] [ebp-544h]
  void *v115; // [esp+254h] [ebp-540h]
  void *v116; // [esp+258h] [ebp-53Ch]
  CConfigManager *v117; // [esp+25Ch] [ebp-538h]
  int v118; // [esp+260h] [ebp-534h]
  int v119; // [esp+264h] [ebp-530h]
  int v120; // [esp+268h] [ebp-52Ch]
  void *v121; // [esp+26Ch] [ebp-528h]
  void *v122; // [esp+270h] [ebp-524h]
  int v123; // [esp+274h] [ebp-520h]
  int v124; // [esp+278h] [ebp-51Ch]
  void *v125; // [esp+27Ch] [ebp-518h]
  int v126; // [esp+280h] [ebp-514h]
  int v127; // [esp+284h] [ebp-510h]
  void *v128; // [esp+288h] [ebp-50Ch]
  int v129; // [esp+28Ch] [ebp-508h]
  int v130; // [esp+290h] [ebp-504h]
  void *v131; // [esp+294h] [ebp-500h]
  int v132; // [esp+298h] [ebp-4FCh]
  int v133; // [esp+29Ch] [ebp-4F8h]
  void *v134; // [esp+2A0h] [ebp-4F4h]
  int v135; // [esp+2A4h] [ebp-4F0h]
  int v136; // [esp+2A8h] [ebp-4ECh]
  void *v137; // [esp+2ACh] [ebp-4E8h]
  int v138; // [esp+2B0h] [ebp-4E4h]
  int v139; // [esp+2B4h] [ebp-4E0h]
  void *v140; // [esp+2B8h] [ebp-4DCh]
  int v141; // [esp+2BCh] [ebp-4D8h]
  int v142; // [esp+2C0h] [ebp-4D4h]
  int v143; // [esp+2C4h] [ebp-4D0h]
  int v144; // [esp+2C8h] [ebp-4CCh]
  int v145; // [esp+2CCh] [ebp-4C8h]
  int v146; // [esp+2D0h] [ebp-4C4h]
  int v147; // [esp+2D4h] [ebp-4C0h]
  int v148; // [esp+2D8h] [ebp-4BCh]
  CConfigManager *Instance; // [esp+2DCh] [ebp-4B8h]
  int v150; // [esp+2E0h] [ebp-4B4h]
  int v151; // [esp+2E4h] [ebp-4B0h]
  int v152; // [esp+2E8h] [ebp-4ACh]
  CConfigManager *v153; // [esp+2ECh] [ebp-4A8h]
  int v154; // [esp+2F0h] [ebp-4A4h]
  int v155; // [esp+2F4h] [ebp-4A0h]
  int v156; // [esp+2F8h] [ebp-49Ch]
  int v157; // [esp+2FCh] [ebp-498h]
  int v158; // [esp+300h] [ebp-494h]
  int v159; // [esp+304h] [ebp-490h]
  int v160; // [esp+308h] [ebp-48Ch]
  int v161; // [esp+30Ch] [ebp-488h]
  int v162; // [esp+310h] [ebp-484h]
  int v163; // [esp+314h] [ebp-480h]
  int v164; // [esp+318h] [ebp-47Ch]
  int v165; // [esp+31Ch] [ebp-478h] BYREF
  char v166; // [esp+320h] [ebp-474h]
  char v167; // [esp+321h] [ebp-473h]
  char v168; // [esp+322h] [ebp-472h]
  char v169; // [esp+323h] [ebp-471h]
  CConfigManager *v170; // [esp+324h] [ebp-470h]
  char v172[4]; // [esp+32Ch] [ebp-468h] BYREF
  int v173; // [esp+330h] [ebp-464h]
  CConfigManager *v174; // [esp+334h] [ebp-460h]
  int v175; // [esp+338h] [ebp-45Ch]
  int v176; // [esp+33Ch] [ebp-458h]
  int v177; // [esp+340h] [ebp-454h]
  int v178; // [esp+344h] [ebp-450h] BYREF
  int v179; // [esp+348h] [ebp-44Ch]
  __int16 v180; // [esp+34Eh] [ebp-446h] BYREF
  _BYTE v181[16]; // [esp+350h] [ebp-444h] BYREF
  int v182; // [esp+360h] [ebp-434h]
  int j; // [esp+364h] [ebp-430h]
  char *v184; // [esp+368h] [ebp-42Ch]
  int i; // [esp+36Ch] [ebp-428h]
  int k; // [esp+370h] [ebp-424h]
  char *v191; // [esp+378h] [ebp-41Ch]
  _BYTE v192[28]; // [esp+5A4h] [ebp-1F0h] BYREF
  _BYTE v193[28]; // [esp+5C0h] [ebp-1D4h] BYREF
  _BYTE v194[28]; // [esp+5DCh] [ebp-1B8h] BYREF
  _BYTE v195[28]; // [esp+5F8h] [ebp-19Ch] BYREF
  _BYTE v196[28]; // [esp+614h] [ebp-180h] BYREF
  _BYTE v197[28]; // [esp+630h] [ebp-164h] BYREF
  _BYTE v198[28]; // [esp+64Ch] [ebp-148h] BYREF
  _BYTE v199[28]; // [esp+668h] [ebp-12Ch] BYREF
  _BYTE v200[28]; // [esp+684h] [ebp-110h] BYREF
  _BYTE v201[28]; // [esp+6A0h] [ebp-F4h] BYREF
  _BYTE v202[28]; // [esp+6BCh] [ebp-D8h] BYREF
  _BYTE v203[28]; // [esp+6D8h] [ebp-BCh] BYREF
  _BYTE v204[28]; // [esp+6F4h] [ebp-A0h] BYREF
  _BYTE v205[28]; // [esp+710h] [ebp-84h] BYREF
  _BYTE v206[28]; // [esp+72Ch] [ebp-68h] BYREF
  char v207[28]; // [esp+748h] [ebp-4Ch] BYREF
  char v208[28]; // [esp+764h] [ebp-30h] BYREF
  _DWORD *v209; // [esp+784h] [ebp-10h]
  int v210; // [esp+790h] [ebp-4h]

  v209 = v24;
  v81 = this;
  result = (unsigned int)this;
  if ( this[26] == 1 )
    return result;
  v178 = 0;
  v184 = 0;
  result = (unsigned int)(a2
                        ? AdvXMLParser::Parser::OpenXMLFile(aGamedataSettle, &v178)
                        : AdvXMLParser::Parser::OpenXMLFile(aGamedataSettle_0, &v178));
  v184 = (char *)result;
  if ( !result )
    return result;
  v210 = 0;
  v52 = AdvXMLParser::Parser::Parser(v25);
  LOBYTE(v210) = 1;
  v80 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v25, v184, v178);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v80);
  LOBYTE(v210) = 2;
  v3 = std::auto_ptr<AdvXMLParser::Document>::operator->(v24[0], v24[1]);
  Root = AdvXMLParser::Document::GetRoot(v3);
  v150 = Root;
  v78 = CDefineTranslator::Instance();
  v182 = v78;
  v44 = 0;
  v77 = AdvXMLParser::NodeContainer::Begin(v150, v33);
  v76 = v77;
  LOBYTE(v210) = 3;
  v43 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v77);
  LOBYTE(v210) = 5;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v33);
  v75 = AdvXMLParser::NodeContainer::End(v150, v32);
  v74 = v75;
  LOBYTE(v210) = 6;
  v42 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v75);
  LOBYTE(v210) = 8;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v32);
  while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v34) )
  {
    v73 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v61);
    v72 = AdvXMLParser::Element::operator[]("id");
    v151 = v72;
    v41 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v72 + 8))(v72, v205);
    LOBYTE(v210) = 9;
    ValueOfDefine = CDefineTranslator::GetValueOfDefine(v205);
    v146 = ValueOfDefine;
    v70 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v61);
    v69 = AdvXMLParser::NodeContainer::Begin(v70, v31);
    v68 = v69;
    LOBYTE(v210) = 10;
    v40 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v69);
    LOBYTE(v210) = 12;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v31);
    v67 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v61);
    v66 = AdvXMLParser::NodeContainer::End(v67, v30);
    v65 = v66;
    LOBYTE(v210) = 13;
    v39 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v66);
    LOBYTE(v210) = 15;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v30);
    while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v35) )
    {
      v64 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v38 = v64;
      v63 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v62 = AdvXMLParser::Element::operator[]("id");
      v152 = v62;
      v54 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v62 + 8))(v62, v204);
      LOBYTE(v210) = 16;
      Instance = CConfigManagerPtr::GetInstance();
      v153 = Instance;
      v4 = std::string::c_str(v204);
      v148 = ((int (__thiscall *)(CConfigManager *, int))v153->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v153, v4);
      v154 = v148;
      if ( v148 == -1 )
      {
        v147 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1791, "index != -1");
        if ( v147 == 1 )
          __debugbreak();
      }
      v191 = &CSettlerMgr::m_vSettlerInfos[3080 * v146 + 44 * v154];
      v145 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v144 = AdvXMLParser::Element::operator()("role", 0);
      v156 = v144;
      v53 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v144 + 8))(v144, v203);
      LOBYTE(v210) = 17;
      v143 = CDefineTranslator::GetValueOfDefine(v203);
      *v191 = v143;
      v142 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v141 = AdvXMLParser::Element::operator()("speed", 0);
      v157 = v141;
      v140 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v141 + 8))(v141, v192);
      v5 = (const char *)std::string::c_str(v140);
      v6 = j__atoi(v5);
      v191[1] = v6;
      std::string::~string(v192);
      v139 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v138 = AdvXMLParser::Element::operator()("health", 0);
      v158 = v138;
      v137 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v138 + 8))(v138, v193);
      v7 = (const char *)std::string::c_str(v137);
      v8 = j__atoi(v7);
      v191[2] = v8;
      std::string::~string(v193);
      v136 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v135 = AdvXMLParser::Element::operator()("armor", 0);
      v159 = v135;
      v134 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v135 + 8))(v135, v194);
      v9 = (const char *)std::string::c_str(v134);
      v10 = j__atoi(v9);
      v191[4] = v10;
      std::string::~string(v194);
      v133 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v132 = AdvXMLParser::Element::operator()("damage", 0);
      v160 = v132;
      v131 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v132 + 8))(v132, v202);
      v11 = (const char *)std::string::c_str(v131);
      v12 = j__atoi(v11);
      v191[3] = v12;
      std::string::~string(v202);
      v130 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v129 = AdvXMLParser::Element::operator()("damage2", 0);
      v161 = v129;
      v128 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v129 + 8))(v129, v195);
      v13 = (const char *)std::string::c_str(v128);
      v14 = j__atoi(v13);
      v191[40] = v14;
      std::string::~string(v195);
      v127 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v126 = AdvXMLParser::Element::operator()("damage3", 0);
      v162 = v126;
      v125 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v126 + 8))(v126, v196);
      v15 = (const char *)std::string::c_str(v125);
      v16 = j__atoi(v15);
      v191[41] = v16;
      std::string::~string(v196);
      v124 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v123 = AdvXMLParser::Element::operator()("other", 0);
      v163 = v123;
      v122 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v123 + 8))(v123, v197);
      v121 = v122;
      LOBYTE(v210) = 18;
      v17 = (char *)std::string::c_str(v122);
      v45 = std::string::string(v206, v17);
      LOBYTE(v210) = 19;
      v120 = CDefineTranslator::GetValueOfDefine(v206);
      v191[6] = v120;
      LOBYTE(v210) = 18;
      std::string::~string(v206);
      LOBYTE(v210) = 17;
      std::string::~string(v197);
      v119 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v118 = AdvXMLParser::Element::operator()("tool", 0);
      v164 = v118;
      v117 = CConfigManagerPtr::GetInstance();
      v170 = v117;
      v116 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v164 + 8))(v164, v198);
      v115 = v116;
      LOBYTE(v210) = 20;
      v18 = std::string::c_str(v116);
      v114 = ((int (__thiscall *)(CConfigManager *, int))v170->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v170, v18);
      v191[5] = v114;
      LOBYTE(v210) = 17;
      std::string::~string(v198);
      if ( (unsigned __int8)v191[5] == -1 )
      {
        v113 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1811, "sI.m_uTool != -1");
        if ( v113 == 1 )
          __debugbreak();
      }
      v112 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v111 = AdvXMLParser::Element::operator()("misc", 0);
      v155 = v111;
      v110 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v111 + 8))(v111, v199);
      v19 = (const char *)std::string::c_str(v110);
      v20 = j__atoi(v19);
      v191[7] = v20;
      std::string::~string(v199);
      v109 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v108 = AdvXMLParser::Element::operator()("search", 0);
      v107 = AdvXMLParser::NodeContainer::Begin(v108, v29);
      v106 = v107;
      LOBYTE(v210) = 21;
      v51 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v107);
      LOBYTE(v210) = 23;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v29);
      v105 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v104 = AdvXMLParser::Element::operator()("search", 0);
      v103 = AdvXMLParser::NodeContainer::End(v104, v26);
      v102 = v103;
      LOBYTE(v210) = 24;
      v50 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v103);
      LOBYTE(v210) = 26;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v26);
      while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v36) )
      {
        v101 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v55);
        v177 = v101;
        v100 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v101 + 8))(v101, v200);
        v99 = v100;
        LOBYTE(v210) = 27;
        v21 = (char *)std::string::c_str(v100);
        v49 = std::string::string(v207, v21);
        LOBYTE(v210) = 29;
        std::string::~string(v200);
        v98 = CDefineTranslator::GetValueOfDefine(v207);
        v176 = v98;
        SearchData = CSearchRoutines::GetSearchData(v98);
        v57 = *(_DWORD *)SearchData;
        v58 = *((_DWORD *)SearchData + 1);
        v59 = *((_DWORD *)SearchData + 2);
        v60 = *((_DWORD *)SearchData + 3);
        v165 = v57;
        v166 = v176;
        v167 = v59;
        v168 = v60;
        v169 = 0;
        std::vector<CSettlerMgr::SSearchInfos>::push_back(&v165);
        LOBYTE(v210) = 26;
        std::string::~string(v207);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v55);
      }
      v96 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v95 = AdvXMLParser::Element::operator()("animLists", 0);
      v94 = AdvXMLParser::NodeContainer::Begin(v95, v28);
      v93 = v94;
      LOBYTE(v210) = 30;
      v48 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v94);
      LOBYTE(v210) = 32;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v28);
      v92 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v181);
      v91 = AdvXMLParser::Element::operator()("animLists", 0);
      v90 = AdvXMLParser::NodeContainer::End(v91, v27);
      v89 = v90;
      LOBYTE(v210) = 33;
      v47 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v90);
      LOBYTE(v210) = 35;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v27);
      while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v37) )
      {
        v88 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v56);
        v175 = v88;
        v87 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v88 + 8))(v88, v201);
        v86 = v87;
        LOBYTE(v210) = 36;
        v22 = (char *)std::string::c_str(v87);
        v46 = std::string::string(v208, v22);
        LOBYTE(v210) = 38;
        std::string::~string(v201);
        v85 = CConfigManagerPtr::GetInstance();
        v174 = v85;
        v23 = std::string::c_str(v208);
        v84 = ((int (__thiscall *)(CConfigManager *, int))v174->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v174, v23);
        v173 = v84;
        if ( v84 == -1 )
        {
          v83 = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 1842, "iAnimList != -1");
          if ( v83 == 1 )
            __debugbreak();
        }
        v180 = v173;
        std::vector<unsigned short>::push_back(&v180);
        LOBYTE(v210) = 35;
        std::string::~string(v208);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v56);
      }
      LOBYTE(v210) = 32;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v37);
      LOBYTE(v210) = 26;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v56);
      LOBYTE(v210) = 23;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v36);
      LOBYTE(v210) = 17;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v55);
      LOBYTE(v210) = 16;
      std::string::~string(v203);
      LOBYTE(v210) = 15;
      std::string::~string(v204);
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v181);
    }
    LOBYTE(v210) = 12;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v35);
    LOBYTE(v210) = 9;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v181);
    LOBYTE(v210) = 8;
    std::string::~string(v205);
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v61);
  }
  LOBYTE(v210) = 5;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v34);
  LOBYTE(v210) = 2;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v61);
  LOBYTE(v210) = 1;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v172);
  LOBYTE(v210) = 0;
  AdvXMLParser::Parser::~Parser(v25);
  v210 = -1;
  C = v184;
  operator delete[](v184);
  for ( i = 1; i < 67; ++i )
  {
    for ( j = 0; j < 5; ++j )
    {
      if ( !CSettlerMgr::m_vSettlerInfos[3080 * j + 44 * i] )
        CSettlerMgr::SSettlerInfos::operator=(&CSettlerMgr::m_vSettlerInfos[44 * i]);
    }
  }
  v179 = (unsigned __int8)byte_4153E47[1936];
  if ( !v179 )
    v179 = 10;
  CSettlerMgr::m_iSquadLeaderBoni256[0] = (v179 << 8) / 100;
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
// Decompiled from int __thiscall CSettlerMgr::AddSettler(CSettlerMgr *this, int a2, int a3, int a4, int a5, int a6)

int  CSettlerMgr::AddSettler(int,int,int,int,int) {
  
  void *v6; // eax
  unsigned __int8 *SettlerPtr; // eax
  int v9; // [esp-8h] [ebp-5Ch] BYREF
  int v10; // [esp-4h] [ebp-58h]
  int v11; // [esp+4h] [ebp-50h]
  int *v12; // [esp+8h] [ebp-4Ch]
  int v13; // [esp+Ch] [ebp-48h]
  struct CSettler *v15; // [esp+14h] [ebp-40h]
  IEntity *v16; // [esp+18h] [ebp-3Ch]
  unsigned int v17; // [esp+1Ch] [ebp-38h]
  _AFX_OLE_STATE *v18; // [esp+20h] [ebp-34h]
  _BYTE v19[4]; // [esp+24h] [ebp-30h] BYREF
  struct CSettler *v20; // [esp+28h] [ebp-2Ch]
  struct CSettler *v21; // [esp+2Ch] [ebp-28h]
  IEntity *v22; // [esp+30h] [ebp-24h]
  _AFX_OLE_STATE *v23; // [esp+34h] [ebp-20h]
  _AFX_OLE_STATE *v24; // [esp+38h] [ebp-1Ch]
  CCarrierRole *SettlerRole; // [esp+3Ch] [ebp-18h]
  int FreeSlot; // [esp+40h] [ebp-14h]
  CSettlerMgr *v27; // [esp+44h] [ebp-10h]
  int v28; // [esp+50h] [ebp-4h]

  v27 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 467, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 468, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a5 <= 0 || a5 >= 67)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 469, "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int16 *)v27 + 12) >= 0x7FFFu )
  {
    CTrace::Print("No more settler allowed!");
    return 0;
  }
  else
  {
    ++*((_WORD *)v27 + 12);
    v6 = (void *)CPlayerManager::PlayerInfo(a4);
    v17 = CPlayerInfo::Race(v6);
    SettlerRole = 0;
    if ( a5 != 1 || a4 == CWorldManager::OwnerId(a2, a3) )
    {
      SettlerRole = CSettlerMgr::CreateSettlerRole((CSettlerMgr *)g_cSettlerMgr, v17, a5);
    }
    else
    {
      v24 = (_AFX_OLE_STATE *)operator new(0x2Cu);
      v28 = 0;
      if ( v24 )
        v23 = CFleeRole::CFleeRole(v24);
      else
        v23 = 0;
      v18 = v23;
      v28 = -1;
      SettlerRole = v23;
    }
    std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(SettlerRole);
    v28 = 2;
    FreeSlot = CMapObjectMgr::GetFreeSlot();
    v22 = (IEntity *)CSettler::operator new(0x68u);
    if ( v22 )
    {
      v10 = FreeSlot;
      v9 = FreeSlot;
      v12 = &v9;
      v11 = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v19);
      v16 = CSettler::CSettler(v22, a2, a3, a5, a4, v9, v10);
      v21 = (struct CSettler *)v16;
    }
    else
    {
      v21 = 0;
    }
    v15 = v21;
    LOBYTE(v28) = 1;
    v20 = v21;
    SettlerPtr = CSettlerMgr::GetSettlerPtr(FreeSlot);
    if ( v20 != (struct CSettler *)SettlerPtr
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 503, "pNewSettler == GetSettlerPtr(iEntityId)") == 1 )
    {
      __debugbreak();
    }
    if ( CSettlerMgr::SettlerWarriorType(a5) )
    {
      CSettlerMgr::AttachSettler(v27, v20);
      if ( a6 > 0 )
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          20,
          a4,
          FreeSlot,
          a6);
    }
    CSettlerMgr::IncNumberOfSettler(v27, a4, a5);
    v13 = FreeSlot;
    v28 = -1;
    std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(v19);
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
      ((void (__thiscall *)(IEntity *, int, int))v13->lpVtbl[2].GetRelationship)(v13, v5, v8);
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
// Decompiled from void __thiscall CSettlerMgr::AttachSettler(CSettlerMgr *this, struct CSettler *a2)

void  CSettlerMgr::AttachSettler(class CSettler &) {
  
  unsigned __int8 *SettlerPtr; // [esp+0h] [ebp-18h]
  int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  int v6; // [esp+10h] [ebp-8h]
  int v7; // [esp+14h] [ebp-4h]

  if ( IEntity::FlagBits(a2, Offered)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 806, "_rSettler.FlagBits(ENTITY_FLAG_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(a2, GlobalOffered)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerMgr.cpp",
         807,
         "_rSettler.FlagBits(ENTITY_FLAG_GLOBAL_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::Previous(a2)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 808, "_rSettler.Previous() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::Next(a2)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 809, "_rSettler.Next() == 0") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(a2, Offered);
  IEntity::SetFlagBits(a2, GlobalOffered);
  v7 = IEntity::OwnerId((unsigned __int8 *)a2);
  v3 = IEntity::EntityId((unsigned __int16 *)a2);
  v6 = IEntity::Type((unsigned __int16 *)a2);
  if ( v7 < 1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 818, "iPlayerId >= PLAYER_FIRST") == 1 )
    __debugbreak();
  if ( v7 > 8 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 819, "iPlayerId <= PLAYER_LAST") == 1 )
    __debugbreak();
  if ( v3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 820, "iSettlerId > 0") == 1 )
    __debugbreak();
  if ( v6 <= 0
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 821, "iSettlerType > SETTLER_NO_SETTLER") == 1 )
  {
    __debugbreak();
  }
  if ( v6 >= 67 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 822, "iSettlerType < SETTLER_MAX") == 1 )
    __debugbreak();
  ++*((_DWORD *)this + 67 * v7 + v6 + 1213);
  v4 = *((_DWORD *)this + 67 * v7 + v6 + 7);
  if ( v4 == v3 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 828, "iOldHeadId != iSettlerId") == 1 )
    __debugbreak();
  *((_DWORD *)this + 67 * v7 + v6 + 7) = v3;
  IAnimatedEntity::SetPrevious(a2, 0);
  IAnimatedEntity::SetNext(a2, v4);
  if ( v4 )
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr(v4);
    if ( !SettlerPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 839, "pOldHead != 0") == 1 )
      __debugbreak();
    if ( IAnimatedEntity::Previous(SettlerPtr) )
    {
      if ( BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerMgr.cpp", 841, "pOldHead->Previous() == 0") == 1 )
        __debugbreak();
    }
    IAnimatedEntity::SetPrevious((IAnimatedEntity *)SettlerPtr, v3);
  }
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

