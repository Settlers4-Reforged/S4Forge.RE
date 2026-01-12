#include "CStatisticArchive.h"

// Definitions for class CStatisticArchive

// address=[0x147a420]
// Decompiled from CStatisticArchive *__thiscall CStatisticArchive::CStatisticArchive(CStatisticArchive *this)
 CStatisticArchive::CStatisticArchive(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CStatisticArchive::_vftable_;
  *((_DWORD *)this + 21185) = 0;
  *((_DWORD *)this + 21188) = 0;
  *((_DWORD *)this + 4) = 16;
  *((_DWORD *)this + 3) = -1;
  *((_DWORD *)this + 5) = 15;
  *((_DWORD *)this + 2) = *((_DWORD *)this + 5) / 16;
  *((_DWORD *)this + 6) = 0;
  memset((char *)this + 68, 0, 0x6E40u);
  *((_DWORD *)this + 9) = 16;
  *((_DWORD *)this + 8) = -1;
  *((_DWORD *)this + 10) = 60;
  *((_DWORD *)this + 7) = *((_DWORD *)this + 10) / 16;
  *((_DWORD *)this + 11) = 0;
  memset((char *)this + 28292, 0, 0x6E40u);
  *((_DWORD *)this + 14) = 16;
  *((_DWORD *)this + 13) = -1;
  *((_DWORD *)this + 15) = 240;
  *((_DWORD *)this + 12) = *((_DWORD *)this + 15) / 16;
  *((_DWORD *)this + 16) = 0;
  memset((char *)this + 56516, 0, 0x6E40u);
  *((_DWORD *)this + 1) = 10;
  return this;
}


// address=[0x147a580]
// Decompiled from CStatisticArchive *__thiscall CStatisticArchive::~CStatisticArchive(CStatisticArchive *this)
 CStatisticArchive::~CStatisticArchive(void) {
  
  CStatisticArchive *result; // eax

  result = this;
  *(_DWORD *)this = CStatisticArchive::_vftable_;
  return result;
}


// address=[0x147a5a0]
// Decompiled from _DWORD *__thiscall CStatisticArchive::TriggerStatistic(CStatisticArchive *this)
void  CStatisticArchive::TriggerStatistic(void) {
  
  CEvn_Event *v2; // [esp+4h] [ebp-38h]
  int i; // [esp+Ch] [ebp-30h]
  CEvn_Event v5; // [esp+14h] [ebp-28h] BYREF
  int v6; // [esp+38h] [ebp-4h]

  if ( ++*((_DWORD *)this + 6) >= *((_DWORD *)this + 2) )
  {
    *((_DWORD *)this + 6) = 0;
    if ( ++*((_DWORD *)this + 3) >= *((_DWORD *)this + 4) )
      *((_DWORD *)this + 3) = 0;
  }
  if ( ++*((_DWORD *)this + 11) >= *((_DWORD *)this + 7) || *((_DWORD *)this + 8) == -1 )
  {
    *((_DWORD *)this + 11) = 0;
    if ( ++*((_DWORD *)this + 8) >= *((_DWORD *)this + 9) )
      *((_DWORD *)this + 8) = 0;
  }
  if ( ++*((_DWORD *)this + 16) >= *((_DWORD *)this + 12) || *((_DWORD *)this + 13) == -1 )
  {
    *((_DWORD *)this + 16) = 0;
    if ( ++*((_DWORD *)this + 13) >= *((_DWORD *)this + 14) )
      *((_DWORD *)this + 13) = 0;
  }
  for ( i = 1; i <= CPlayerManager::NumberOfPlayers(); ++i )
  {
    CStatisticArchive::GetAreaSizeData(this, i);
    CStatisticArchive::GetPopulationData(this, i);
    CStatisticArchive::GetRessourcesData(this, i);
    CStatisticArchive::GetSoldierData(this, i);
    CStatisticArchive::GetBeatenEnemiesData(this, i);
    CStatisticArchive::GetLostWarriorsData(this, i);
    CStatisticArchive::GetDestroyedBuildingsData(this, i);
    CStatisticArchive::GetGoodData(this, i);
  }
  *((_DWORD *)this + 1) += 10;
  if ( *((int *)this + 1) > 100 )
    *((_DWORD *)this + 1) = 0;
  v2 = CEvn_Event::CEvn_Event(&v5, 0x277u, 0, 0, 0);
  v6 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v2);
  v6 = -1;
  return CEvn_Event::~CEvn_Event(&v5);
}


// address=[0x147a7d0]
// Decompiled from int __thiscall CStatisticArchive::GetAreaSizeData(CStatisticArchive *this, int a2)
void  CStatisticArchive::GetAreaSizeData(int) {
  
  int result; // eax

  result = CStatistic::GetLandSizePercent((CStatistic *)&g_cStatistic, a2);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 17) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7073) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14129) = result;
  return result;
}


// address=[0x147a870]
// Decompiled from int __thiscall CStatisticArchive::GetPopulationData(CStatisticArchive *this, int a2)
void  CStatisticArchive::GetPopulationData(int) {
  
  int result; // eax

  result = CStatistic::GetCivilian((CStatistic *)&g_cStatistic, a2);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 49) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7105) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14161) = result;
  return result;
}


// address=[0x147a900]
// Decompiled from int __thiscall CStatisticArchive::GetRessourcesData(CStatisticArchive *this, int a2)
void  CStatisticArchive::GetRessourcesData(int) {
  
  int result; // eax

  result = CStatistic::UsedBuildingMaterial((CStatistic *)&g_cStatistic, a2);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 33) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7089) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14145) = result;
  return result;
}


// address=[0x147a9a0]
// Decompiled from int __thiscall CStatisticArchive::GetSoldierData(CStatisticArchive *this, int a2)
void  CStatisticArchive::GetSoldierData(int) {
  
  int result; // eax

  result = CStatistic::GetNrOfSoldiers((CStatistic *)&g_cStatistic, a2);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 65) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7121) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14177) = result;
  return result;
}


// address=[0x147aa40]
// Decompiled from int __thiscall CStatisticArchive::GetBeatenEnemiesData(CStatisticArchive *this, int a2)
void  CStatisticArchive::GetBeatenEnemiesData(int) {
  
  int result; // eax

  result = CStatistic::GetKills((CStatistic *)&g_cStatistic, a2);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 81) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7137) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14193) = result;
  return result;
}


// address=[0x147aae0]
// Decompiled from int __thiscall CStatisticArchive::GetLostWarriorsData(CStatisticArchive *this, int a2)
void  CStatisticArchive::GetLostWarriorsData(int) {
  
  int result; // eax

  result = CStatistic::GetLosses((CStatistic *)&g_cStatistic, a2);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 97) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7153) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14209) = result;
  return result;
}


// address=[0x147ab80]
// Decompiled from int __thiscall CStatisticArchive::GetDestroyedBuildingsData(CStatisticArchive *this, int a2)
void  CStatisticArchive::GetDestroyedBuildingsData(int) {
  
  int result; // eax

  result = CStatistic::GetBuildingLosses((CStatistic *)&g_cStatistic, a2);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 113) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7169) = result;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14225) = result;
  return result;
}


// address=[0x147ac20]
// Decompiled from int __thiscall CStatisticArchive::GetGoodData(CStatisticArchive *this, int a2)
void  CStatisticArchive::GetGoodData(int) {
  
  int Good; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int result; // eax
  int v44; // [esp+0h] [ebp-8h]

  Good = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 1);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 129) = Good;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7185) = Good;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14241) = Good;
  v3 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 2);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 145) = v3;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7201) = v3;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14257) = v3;
  v4 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 3);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 161) = v4;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7217) = v4;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14273) = v4;
  v5 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 4);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 177) = v5;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7233) = v5;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14289) = v5;
  v6 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 38);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 721) = v6;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7777) = v6;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14833) = v6;
  v7 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 5);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 193) = v7;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7249) = v7;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14305) = v7;
  v8 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 6);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 209) = v8;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7265) = v8;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14321) = v8;
  v9 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 7);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 225) = v9;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7281) = v9;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14337) = v9;
  v10 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 8);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 241) = v10;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7297) = v10;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14353) = v10;
  v11 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 9);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 257) = v11;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7313) = v11;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14369) = v11;
  v12 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 10);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 273) = v12;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7329) = v12;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14385) = v12;
  v13 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 40);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 737) = v13;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7793) = v13;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14849) = v13;
  v14 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 11);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 289) = v14;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7345) = v14;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14401) = v14;
  v15 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 12);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 305) = v15;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7361) = v15;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14417) = v15;
  v16 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 13);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 321) = v16;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7377) = v16;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14433) = v16;
  v17 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 14);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 337) = v17;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7393) = v17;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14449) = v17;
  v18 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 15);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 353) = v18;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7409) = v18;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14465) = v18;
  v19 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 39);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 753) = v19;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7809) = v19;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14865) = v19;
  v20 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 16);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 369) = v20;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7425) = v20;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14481) = v20;
  v21 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 17);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 385) = v21;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7441) = v21;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14497) = v21;
  v22 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 18);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 401) = v22;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7457) = v22;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14513) = v22;
  v23 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 19);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 417) = v23;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7473) = v23;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14529) = v23;
  v24 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 20);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 433) = v24;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7489) = v24;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14545) = v24;
  v25 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 21);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 449) = v25;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7505) = v25;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14561) = v25;
  v26 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 22);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 465) = v26;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7521) = v26;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14577) = v26;
  v27 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 23);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 481) = v27;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7537) = v27;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14593) = v27;
  v28 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 24);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 497) = v28;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7553) = v28;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14609) = v28;
  v29 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 25);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 513) = v29;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7569) = v29;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14625) = v29;
  v30 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 26);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 529) = v30;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7585) = v30;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14641) = v30;
  v31 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 27);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 545) = v31;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7601) = v31;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14657) = v31;
  v32 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 28);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 561) = v32;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7617) = v32;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14673) = v32;
  v33 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 29);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 577) = v33;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7633) = v33;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14689) = v33;
  v34 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 30);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 593) = v34;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7649) = v34;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14705) = v34;
  v35 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 31);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 609) = v35;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7665) = v35;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14721) = v35;
  v36 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 32);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 625) = v36;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7681) = v36;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14737) = v36;
  v37 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 33);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 641) = v37;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7697) = v37;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14753) = v37;
  v38 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 42);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 769) = v38;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7825) = v38;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14881) = v38;
  v39 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 41);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 785) = v39;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7841) = v39;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14897) = v39;
  v40 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 34);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 657) = v40;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7713) = v40;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14769) = v40;
  v41 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 35);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 673) = v41;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7729) = v41;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14785) = v41;
  v42 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 36);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 689) = v42;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7745) = v42;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 13) + 14801) = v42;
  v44 = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 37);
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 3) + 705) = v44;
  *((_DWORD *)this + 784 * a2 + *((_DWORD *)this + 8) + 7761) = v44;
  result = *((_DWORD *)this + 13);
  *((_DWORD *)this + 784 * a2 + result + 14817) = v44;
  return result;
}


// address=[0x147c210]
// Decompiled from int __thiscall CStatisticArchive::Load(CStatisticArchive *this, struct IS4Chunk *a2)
void  CStatisticArchive::Load(class IS4Chunk &) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-1Ch] BYREF
  int v4; // [esp+4h] [ebp-18h] BYREF
  int v5; // [esp+8h] [ebp-14h] BYREF
  int v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-Ch] BYREF
  int v8; // [esp+14h] [ebp-8h] BYREF
  CStatisticArchive *v9; // [esp+18h] [ebp-4h]

  v9 = this;
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 762236059);
  v8 = 0;
  result = (**(int (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v8, 4);
  if ( v8 != 1 )
    return result;
  (**(void (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v7, 4);
  if ( v7 != 9 && BBSupportDbgReport(2, "logic\\StatisticArchive.cpp", 95, "iNumberPlayer== PLAYER_MAX") == 1 )
    __debugbreak();
  (**(void (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v6, 4);
  if ( v6 != 49
    && BBSupportDbgReport(2, "logic\\StatisticArchive.cpp", 98, "StatisticTypeMax == STATISTICTYPE_MAX") == 1 )
  {
    __debugbreak();
  }
  (**(void (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v5, 4);
  if ( v5 != 16 && BBSupportDbgReport(2, "logic\\StatisticArchive.cpp", 101, "MaxSamplesShort == MAX_SAMPLESSHORT") == 1 )
    __debugbreak();
  (**(void (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v4, 4);
  if ( v4 != 16
    && BBSupportDbgReport(2, "logic\\StatisticArchive.cpp", 104, "MaxSamplesMedium == MAX_SAMPLESMEDIUM") == 1 )
  {
    __debugbreak();
  }
  (**(void (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v3, 4);
  if ( v3 != 16 && BBSupportDbgReport(2, "logic\\StatisticArchive.cpp", 107, "MaxSamplesLong == MAX_SAMPLESLONG") == 1 )
    __debugbreak();
  (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v9 + 68, 28224);
  (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v9 + 28292, 28224);
  (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v9 + 56516, 28224);
  return (**(int (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v9 + 84740, 196);
}


// address=[0x147c3d0]
// Decompiled from int __thiscall CStatisticArchive::Save(CStatisticArchive *this, struct IS4Chunk *a2)
void  CStatisticArchive::Save(class IS4Chunk &) {
  
  int v3; // [esp+0h] [ebp-1Ch] BYREF
  int v4; // [esp+4h] [ebp-18h] BYREF
  int v5; // [esp+8h] [ebp-14h] BYREF
  int v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-Ch] BYREF
  int v8; // [esp+14h] [ebp-8h] BYREF
  CStatisticArchive *v9; // [esp+18h] [ebp-4h]

  v9 = this;
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 762236059);
  v8 = 1;
  (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v8, 4);
  v7 = 9;
  (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v7, 4);
  v6 = 49;
  (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v6, 4);
  v5 = 16;
  (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v5, 4);
  v4 = 16;
  (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v4, 4);
  v3 = 16;
  (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v3, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v9 + 68, 28224);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v9 + 28292, 28224);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v9 + 56516, 28224);
  return (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v9 + 84740, 196);
}


