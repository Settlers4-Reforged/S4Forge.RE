#include "CStatistic.h"

// Definitions for class CStatistic

// address=[0x13adcc0]
// Decompiled from int __thiscall CStatistic::DefenceStrength100Max(CStatistic *this, int a2)
int  CStatistic::DefenceStrength100Max(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\Statistic.h",
         365,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (100 * *((_DWORD *)this + 1098 * a2 + 1053)) >> 8;
}


// address=[0x13add30]
// Decompiled from int __thiscall CStatistic::GetDontShowLastNPlayers(CStatistic *this)
int  CStatistic::GetDontShowLastNPlayers(void) {
  
  return *((_DWORD *)this + 9883);
}


// address=[0x13add50]
// Decompiled from int __thiscall CStatistic::OffenceStrength100Max(CStatistic *this, int a2)
int  CStatistic::OffenceStrength100Max(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\Statistic.h",
         381,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (100 * *((_DWORD *)this + 1098 * a2 + 1054)) >> 8;
}


// address=[0x1475d60]
// Decompiled from CStatistic *__thiscall CStatistic::CStatistic(CStatistic *this)
 CStatistic::CStatistic(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CStatistic::_vftable_;
  CStatistic::Clear(this);
  return this;
}


// address=[0x1475d90]
// Decompiled from void *__thiscall CStatistic::Clear(CStatistic *this)
void  CStatistic::Clear(void) {
  
  void *result; // eax

  result = j__memset((char *)this + 4, 0, 0x9A68u);
  *((_DWORD *)this + 9883) = 0;
  return result;
}


// address=[0x1475dc0]
// Decompiled from void __thiscall CStatistic::Init(CStatistic *this)
void  CStatistic::Init(void) {
  
  CStatistic::Clear(this);
  CStatistic::CalcPlayerOffenceStrengthBaseValues(this);
  CStatistic::CalculateFightingStrengths(this);
}


// address=[0x1475df0]
// Decompiled from void *__thiscall CStatistic::Update(CStatistic *this)
void  CStatistic::Update(void) {
  
  void *result; // eax
  int i; // [esp+4h] [ebp-4h]

  CStatistic::CalculateLandSize(this);
  CStatistic::CalculateMana(this);
  CStatistic::CalculateFightingStrengths(this);
  result = (void *)g_pGameType;
  if ( *(int *)(g_pGameType + 752) <= 0 || CStatistic::m_bWonStateSaved )
    return result;
  CStatistic::m_bWonStateSaved = 1;
  for ( i = 0; i < 9; ++i )
    result = j__memcpy((char *)this + 4392 * i + 4220, (char *)this + 4392 * i + 2568, 0xACu);
  return result;
}


// address=[0x1475e80]
// Decompiled from struct CStatistic *__thiscall CStatistic::Update(CStatistic *this, struct CStatistic *a2)
void  CStatistic::Update(class CStatistic &) {
  
  struct CStatistic *result; // eax

  CStatistic::Update(a2);
  j__memcpy((char *)this + 4, (char *)a2 + 4, 0x9A68u);
  result = a2;
  *((_DWORD *)this + 9883) = *((_DWORD *)a2 + 9883);
  return result;
}


// address=[0x1475ed0]
// Decompiled from int __thiscall CStatistic::Load(CStatistic *this, struct IS4Chunk *a2)
void  CStatistic::Load(class IS4Chunk &) {
  
  int result; // eax
  unsigned int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  unsigned int v6; // [esp+Ch] [ebp-4h]

  CStatistic::Clear(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 762231707);
  result = (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 3, 4);
  v4 = result;
  if ( result == 3 )
  {
    v6 = 4388;
  }
  else
  {
    result = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 4392);
    v6 = result;
  }
  if ( v6 > 0x1128 )
  {
    result = BBSupportDbgReport(2, "Logic\\Statistic.cpp", 118, "uStructSize <= sizeof(SPlayerStatistic)");
    if ( result == 1 )
      __debugbreak();
  }
  for ( i = 0; i < 9; ++i )
    result = (**(int (__thiscall ***)(struct IS4Chunk *, char *, unsigned int))a2)(a2, (char *)this + 4392 * i + 4, v6);
  if ( v4 >= 4 )
    return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 762231803);
  return result;
}


// address=[0x1475fc0]
// Decompiled from int __thiscall CStatistic::Save(CStatistic *this, struct IS4Chunk *a2)
void  CStatistic::Save(class IS4Chunk &) {
  
  CStatistic::Update(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 762231707);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 4392);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 4, 39528);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 762231803);
}


// address=[0x1476040]
// Decompiled from int __thiscall CStatistic::DecSettler(CStatistic *this, int a2, int a3)
void  CStatistic::DecSettler(int,int) {
  
  int result; // eax

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 328, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 329, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 1098 * a2 + a3 + 1) <= 0
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         331,
         "m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType] > 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 1098 * a2 + 68) <= 0
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 332, "m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler > 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 1098 * a2 + a3 + 1) > 0 )
    --*((_DWORD *)this + 1098 * a2 + a3 + 1);
  if ( *((int *)this + 1098 * a2 + 68) > 0 )
    --*((_DWORD *)this + 1098 * a2 + 68);
  result = CSettlerMgr::SettlerWarriorType(a3);
  switch ( result )
  {
    case 0:
      if ( *((int *)this + 1098 * a2 + 137) <= 0
        && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 369, "m_sPlayerStats[_iPlayerId].m_iNrOfCivilian > 0") == 1 )
      {
        __debugbreak();
      }
      result = (int)this;
      if ( *((int *)this + 1098 * a2 + 137) > 0 )
      {
        result = *((_DWORD *)this + 1098 * a2 + 137) - 1;
        *((_DWORD *)this + 1098 * a2 + 137) = result;
      }
      break;
    case 1:
    case 6:
    case 7:
    case 14:
      return result;
    default:
      if ( *((int *)this + 1098 * a2 + 138) <= 0
        && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 380, "m_sPlayerStats[_iPlayerId].m_iNrOfSoldier > 0") == 1 )
      {
        __debugbreak();
      }
      result = 4392 * a2;
      if ( *((int *)this + 1098 * a2 + 138) > 0 )
      {
        result = (int)this;
        --*((_DWORD *)this + 1098 * a2 + 138);
      }
      break;
  }
  return result;
}


// address=[0x14762c0]
// Decompiled from int __thiscall CStatistic::AddSettler(CStatistic *this, int a2, int a3)
void  CStatistic::AddSettler(int,int) {
  
  int result; // eax

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 283, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 284, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++*((_DWORD *)this + 1098 * a2 + a3 + 1);
  ++*((_DWORD *)this + 1098 * a2 + 68);
  result = CSettlerMgr::SettlerWarriorType(a3);
  switch ( result )
  {
    case 0:
      result = 4392 * a2;
      ++*((_DWORD *)this + 1098 * a2 + 137);
      break;
    case 1:
    case 6:
    case 7:
    case 14:
      return result;
    default:
      result = (int)this;
      ++*((_DWORD *)this + 1098 * a2 + 138);
      break;
  }
  return result;
}


// address=[0x1476410]
// Decompiled from int __thiscall CStatistic::GetSettler(_DWORD *this, int a2, int a3)
int  CStatistic::GetSettler(int,int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 398, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 399, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return this[1098 * a2 + 1 + a3];
}


// address=[0x1476490]
// Decompiled from int __thiscall CStatistic::GetTotalSettler(_DWORD *this, int a2)
int  CStatistic::GetTotalSettler(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 412, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this[1098 * a2 + 70];
}


// address=[0x14764f0]
// Decompiled from int __thiscall CStatistic::GetCivilian(CStatistic *this, int a2)
int  CStatistic::GetCivilian(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 467, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 137);
}


// address=[0x1476540]
// Decompiled from int __thiscall CStatistic::GetSoldiers(CStatistic *this, int a2)
int  CStatistic::GetSoldiers(int)const {
  
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 480, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  v5 = 0;
  for ( i = 0; i < 67; ++i )
  {
    v4 = CSettlerMgr::SettlerWarriorType(i);
    if ( v4 > 0 && v4 <= 6 )
      v5 += *((_DWORD *)this + 1098 * a2 + i + 69);
  }
  return v5;
}


// address=[0x14765e0]
// Decompiled from int __thiscall CStatistic::GetNrOfSoldiers(CStatistic *this, int a2)
int  CStatistic::GetNrOfSoldiers(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 512, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 138);
}


// address=[0x1476630]
// Decompiled from int __thiscall CStatistic::AddProducedSettler(CStatistic *this, int a2, int a3)
void  CStatistic::AddProducedSettler(int,int) {
  
  int result; // eax

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 426, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 427, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++*((_DWORD *)this + 1098 * a2 + a3 + 69);
  result = 4392 * a2;
  ++*((_DWORD *)this + 1098 * a2 + 136);
  return result;
}


// address=[0x14766f0]
// Decompiled from int __thiscall CStatistic::GetProducedSettler(CStatistic *this, int a2, int a3)
int  CStatistic::GetProducedSettler(int,int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 441, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 442, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + a3 + 69);
}


// address=[0x1476770]
// Decompiled from int __thiscall CStatistic::GetTotalProducedSettler(CStatistic *this, int a2)
int  CStatistic::GetTotalProducedSettler(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 454, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 136);
}


// address=[0x14767c0]
// Decompiled from int __thiscall CStatistic::GetBuildingProductivity(unsigned __int8 *this, int a2, int a3)
int  CStatistic::GetBuildingProductivity(int,int)const {
  
  return this[4392 * a2 + 3020 + a3];
}


// address=[0x14767f0]
// Decompiled from void __thiscall CStatistic::AddBuilding(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddBuilding(int,int,int) {
  
  int v4; // eax

  *((_DWORD *)this + 1098 * a2 + a3 + 139) += a4;
  *((_DWORD *)this + 1098 * a2 + 388) += a4;
  v4 = CPlayerManager::Race(a2);
  CStatistic::UpdateFightingStrength(this, a2, v4, a3, a4);
}


// address=[0x1476880]
// Decompiled from void __thiscall CStatistic::DecBuilding(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::DecBuilding(int,int,int) {
  
  int v4; // eax

  BBSupportTracePrintF(0, "CStatistic::DecBuilding(%i, %i, %i) called.", a2, a3, a4);
  if ( *((_DWORD *)this + 1098 * a2 + a3 + 139) < a4
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         555,
         "m_sPlayerStats[ _iPlayerId ].m_iNrOfBuildings[ _iBuildingType ] >= _iAmount") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 1098 * a2 + 388) -= a4;
  *((_DWORD *)this + 1098 * a2 + a3 + 139) -= a4;
  v4 = CPlayerManager::Race(a2);
  CStatistic::UpdateFightingStrength(this, a2, v4, a3, -a4);
}


// address=[0x1476960]
// Decompiled from int __thiscall CStatistic::GetBuildings(CStatistic *this, int a2, int a3)
int  CStatistic::GetBuildings(int,int)const {
  
  return *((_DWORD *)this + 1098 * a2 + a3 + 139);
}


// address=[0x1476990]
// Decompiled from int __thiscall CStatistic::AddProducedBuilding(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddProducedBuilding(int,int,int) {
  
  int result; // eax

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 610, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 83 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 611, "_iBuilding < BUILDING_MAX") == 1 )
    __debugbreak();
  *((_DWORD *)this + 1098 * a2 + a3 + 389) += a4;
  result = 4392 * a2;
  *((_DWORD *)this + 1098 * a2 + 472) += a4;
  return result;
}


// address=[0x1476a50]
// Decompiled from int __thiscall CStatistic::GetProducedBuildings(CStatistic *this, int a2, int a3)
int  CStatistic::GetProducedBuildings(int,int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 624, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 83 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 625, "_iBuilding < BUILDING_MAX") == 1 )
    __debugbreak();
  return *((_DWORD *)this + 1098 * a2 + a3 + 389);
}


// address=[0x1476ad0]
// Decompiled from int __thiscall CStatistic::GetTotalBuildings(_DWORD *this, int a2)
int  CStatistic::GetTotalBuildings(int)const {
  
  return this[1098 * a2 + 388];
}


// address=[0x1476af0]
// Decompiled from int __thiscall CStatistic::GetTotalProducedBuildings(CStatistic *this, int a2)
int  CStatistic::GetTotalProducedBuildings(int)const {
  
  return *((_DWORD *)this + 1098 * a2 + 472);
}


// address=[0x1476b10]
// Decompiled from int __thiscall CStatistic::GetTotalBuildingsOfType(CStatistic *this, int a2, int a3)
int  CStatistic::GetTotalBuildingsOfType(int,int)const {
  
  int Buildings; // esi

  Buildings = CStatistic::GetBuildings(this, a2, a3);
  return Buildings + CStatistic::GetConstructions(this, a2, a3);
}


// address=[0x1476b50]
// Decompiled from char *__thiscall CStatistic::AddCaptureBuilding(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddCaptureBuilding(int,int,int) {
  
  char *result; // eax

  ++*((_DWORD *)this + 1098 * a2 + a4 + 222);
  result = (char *)this + 4392 * a3 + 4;
  ++*(_DWORD *)&result[4 * a4 + 1216];
  return result;
}


// address=[0x1476bd0]
// Decompiled from int __thiscall CStatistic::GetCapturedTowers(CStatistic *this, int a2)
int  CStatistic::GetCapturedTowers(int) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1584, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 270) + *((_DWORD *)this + 1098 * a2 + 269) + *((_DWORD *)this + 1098 * a2 + 268);
}


// address=[0x1476c70]
// Decompiled from int __thiscall CStatistic::GetLossesTowers(CStatistic *this, int a2)
int  CStatistic::GetLossesTowers(int) {
  
  return *((_DWORD *)this + 1098 * a2 + 353) + *((_DWORD *)this + 1098 * a2 + 352) + *((_DWORD *)this + 1098 * a2 + 351);
}


// address=[0x1476ce0]
// Decompiled from int __thiscall CStatistic::AddConstruction(_DWORD *this, int a2, int a3, int a4)
void  CStatistic::AddConstruction(int,int,int) {
  
  int result; // eax

  this[1098 * a2 + 473 + a3] += a4;
  result = a4 + this[1098 * a2 + 556];
  this[1098 * a2 + 556] = result;
  return result;
}


// address=[0x1476d50]
// Decompiled from int __thiscall CStatistic::DecConstruction(_DWORD *this, int a2, int a3, int a4)
void  CStatistic::DecConstruction(int,int,int) {
  
  int result; // eax

  if ( this[1098 * a2 + 473 + a3] < a4
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         661,
         "m_sPlayerStats[ _iPlayerId ].m_iNrOfBuildingSites[ _iBuildingType ] >= _iAmount") == 1 )
  {
    __debugbreak();
  }
  this[1098 * a2 + 473 + a3] -= a4;
  result = this[1098 * a2 + 556] - a4;
  this[1098 * a2 + 556] = result;
  return result;
}


// address=[0x1476e00]
// Decompiled from int __thiscall CStatistic::GetTotalBuildingsUnderConstruction(_DWORD *this, int a2)
int  CStatistic::GetTotalBuildingsUnderConstruction(int)const {
  
  return this[1098 * a2 + 556];
}


// address=[0x1476e20]
// Decompiled from int __thiscall CStatistic::GetConstructions(CStatistic *this, int a2, int a3)
int  CStatistic::GetConstructions(int,int)const {
  
  return *((_DWORD *)this + 1098 * a2 + a3 + 473);
}


// address=[0x1476e50]
// Decompiled from int __thiscall CStatistic::ChangeResidenceNeed(_DWORD *this, int a2, int a3)
void  CStatistic::ChangeResidenceNeed(int,int) {
  
  int result; // eax

  result = 4392 * a2;
  this[1098 * a2 + 640] += a3;
  return result;
}


// address=[0x1476e90]
// Decompiled from int __thiscall CStatistic::GetResidenceNeed(CStatistic *this, int a2)
int  CStatistic::GetResidenceNeed(int)const {
  
  return *((_DWORD *)this + 1098 * a2 + 2);
}


// address=[0x1476ec0]
// Decompiled from int __thiscall CStatistic::ChangeResidenceSpace(CStatistic *this, int a2, int a3)
void  CStatistic::ChangeResidenceSpace(int,int) {
  
  int result; // eax

  result = 4392 * a2;
  *((_DWORD *)this + 1098 * a2 + 641) += a3;
  return result;
}


// address=[0x1476f00]
// Decompiled from int __thiscall CStatistic::GetResidenceSpace(CStatistic *this, int a2)
int  CStatistic::GetResidenceSpace(int)const {
  
  return CEcoSectorMgr::GetNrOfCurrentTotalBeds((CEcoSectorMgr *)g_cESMgr, a2);
}


// address=[0x1476f20]
// Decompiled from int __thiscall CStatistic::AddGood(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddGood(int,int,int) {
  
  int result; // eax

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 162, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 163, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  *((_DWORD *)this + 1098 * a2 + a3 + 642) += a4;
  result = 4392 * a2;
  *((_DWORD *)this + 1098 * a2 + 685) += a4;
  if ( CStatistic::m_bWonStateSaved )
    return result;
  result = (int)this + 4392 * a2 + 4;
  *(_DWORD *)(result + 4 * a3 + 4216) = *(_DWORD *)(result + 4 * a3 + 2564);
  return result;
}


// address=[0x1477020]
// Decompiled from CStatistic *__thiscall CStatistic::DecGood(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::DecGood(int,int,int) {
  
  CStatistic *result; // eax
  int v5; // [esp+0h] [ebp-8h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 183, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 184, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  v5 = a4;
  if ( *((_DWORD *)this + 1098 * a2 + a3 + 642) < a4 )
    v5 = *((_DWORD *)this + 1098 * a2 + a3 + 642);
  *((_DWORD *)this + 1098 * a2 + a3 + 642) -= v5;
  result = this;
  *((_DWORD *)this + 1098 * a2 + 685) -= v5;
  return result;
}


// address=[0x1477120]
// Decompiled from int __thiscall CStatistic::GetGood(CStatistic *this, int a2, int a3)
int  CStatistic::GetGood(int,int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 202, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 203, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  return *((_DWORD *)this + 1098 * a2 + a3 + 642);
}


// address=[0x14771a0]
// Decompiled from int __thiscall CStatistic::GetWinGood(CStatistic *this, int a2, int a3)
int  CStatistic::GetWinGood(int,int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 210, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 211, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  return *((_DWORD *)this + 1098 * a2 + a3 + 1055);
}


// address=[0x1477220]
// Decompiled from int __thiscall CStatistic::GetTotalGood(_DWORD *this, int a2)
int  CStatistic::GetTotalGood(int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 223, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this[1098 * a2 + 685];
}


// address=[0x1477270]
// Decompiled from int __thiscall CStatistic::AddProducedGoods(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddProducedGoods(int,int,int) {
  
  int result; // eax

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 235, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 236, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  *((_DWORD *)this + 1098 * a2 + a3 + 686) += a4;
  result = 4392 * a2;
  *((_DWORD *)this + 1098 * a2 + 729) += a4;
  return result;
}


// address=[0x1477330]
// Decompiled from int __thiscall CStatistic::GetProducedGoods(CStatistic *this, int a2, int a3)
int  CStatistic::GetProducedGoods(int,int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 249, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 250, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  return *((_DWORD *)this + 1098 * a2 + a3 + 686);
}


// address=[0x14773b0]
// Decompiled from int __thiscall CStatistic::GetTotalProducedGood(_DWORD *this, int a2)
int  CStatistic::GetTotalProducedGood(int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 263, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this[1098 * a2 + 729];
}


// address=[0x1477400]
// Decompiled from int __thiscall CStatistic::AddVehicle(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddVehicle(int,int,int) {
  
  int result; // eax

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 759, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 6 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 760, "_iVehicleType < VEHICLE_MAX") == 1 )
    __debugbreak();
  *((_DWORD *)this + 1098 * a2 + a3 + 730) += a4;
  result = 4392 * a2;
  *((_DWORD *)this + 1098 * a2 + 736) += a4;
  return result;
}


// address=[0x14774c0]
// Decompiled from int __thiscall CStatistic::DecVehicle(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::DecVehicle(int,int,int) {
  
  int result; // eax
  int v5; // [esp+0h] [ebp-8h]

  v5 = a4;
  if ( *((_DWORD *)this + 1098 * a2 + a3 + 730) < a4 )
    v5 = *((_DWORD *)this + 1098 * a2 + a3 + 730);
  *((_DWORD *)this + 1098 * a2 + a3 + 730) -= v5;
  result = 4392 * a2;
  *((_DWORD *)this + 1098 * a2 + 736) -= v5;
  return result;
}


// address=[0x1477570]
// Decompiled from int __thiscall CStatistic::GetVehicle(_DWORD *this, int a2, int a3)
int  CStatistic::GetVehicle(int,int)const {
  
  return this[1098 * a2 + 730 + a3];
}


// address=[0x14775a0]
// Decompiled from int __thiscall CStatistic::GetTotalVehicle(_DWORD *this, int a2)
int  CStatistic::GetTotalVehicle(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 803, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this[1098 * a2 + 736];
}


// address=[0x14775f0]
// Decompiled from int __thiscall CStatistic::AddProducedVehicle(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddProducedVehicle(int,int,int) {
  
  int result; // eax

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 817, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 6)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 818, "(_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 1098 * a2 + a3 + 737) += a4;
  result = 4392 * a2;
  *((_DWORD *)this + 1098 * a2 + 743) += a4;
  return result;
}


// address=[0x14776b0]
// Decompiled from int __thiscall CStatistic::GetProducedVehicle(CStatistic *this, int a2, int a3)
int  CStatistic::GetProducedVehicle(int,int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 831, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 6)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 832, "(_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + a3 + 737);
}


// address=[0x1477730]
// Decompiled from int __thiscall CStatistic::GetTotalProducedVehicled(_DWORD *this, int a2)
int  CStatistic::GetTotalProducedVehicled(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 845, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this[1098 * a2 + 743];
}


// address=[0x1477780]
// Decompiled from int __thiscall CStatistic::GetMana(CStatistic *this, int a2)
int  CStatistic::GetMana(int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1104, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 1049);
}


// address=[0x14777d0]
// Decompiled from int __thiscall CStatistic::GetProducedMana(CStatistic *this, int a2)
int  CStatistic::GetProducedMana(int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1116, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 1050);
}


// address=[0x1477820]
// Decompiled from int __thiscall CStatistic::IncKillsOfType(_DWORD *this, int a2, int a3)
void  CStatistic::IncKillsOfType(int,int) {
  
  int result; // eax

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 863, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a3 <= 0 )
  {
    result = BBSupportDbgReport(2, "Logic\\Statistic.cpp", 864, "_iSettlerType > 0");
    if ( result == 1 )
      __debugbreak();
  }
  if ( a3 >= 67 )
    return result;
  ++this[1098 * a2 + 776 + a3];
  result = 4392 * a2;
  ++this[1098 * a2 + 843];
  return result;
}


// address=[0x14778e0]
// Decompiled from int __thiscall CStatistic::GetKillsOfType(_DWORD *this, int a2, int a3)
int  CStatistic::GetKillsOfType(int,int)const {
  
  return this[1098 * a2 + 776 + a3];
}


// address=[0x1477910]
// Decompiled from int __thiscall CStatistic::GetKills(CStatistic *this, int a2)
int  CStatistic::GetKills(int)const {
  
  return *((_DWORD *)this + 1098 * a2 + 843);
}


// address=[0x1477930]
// Decompiled from int __thiscall CStatistic::IncLossesOfType(CStatistic *this, int a2, int a3)
void  CStatistic::IncLossesOfType(int,int) {
  
  int result; // eax

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 899, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a3 <= 0 )
  {
    result = BBSupportDbgReport(2, "Logic\\Statistic.cpp", 900, "_iSettlerType > 0");
    if ( result == 1 )
      __debugbreak();
  }
  if ( a3 >= 67 )
    return result;
  ++*((_DWORD *)this + 1098 * a2 + a3 + 844);
  result = 4392 * a2;
  ++*((_DWORD *)this + 1098 * a2 + 911);
  return result;
}


// address=[0x14779f0]
// Decompiled from int __thiscall CStatistic::GetLossesOfType(_DWORD *this, int a2, int a3)
int  CStatistic::GetLossesOfType(int,int)const {
  
  return this[1098 * a2 + 844 + a3];
}


// address=[0x1477a20]
// Decompiled from int __thiscall CStatistic::GetLosses(CStatistic *this, int a2)
int  CStatistic::GetLosses(int)const {
  
  return *((_DWORD *)this + 1098 * a2 + 911);
}


// address=[0x1477a40]
// Decompiled from int __thiscall CStatistic::IncKillsVehicleOfType(CStatistic *this, int a2, int a3)
void  CStatistic::IncKillsVehicleOfType(int,int) {
  
  int result; // eax

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 962, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 6)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 963, "(_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++*((_DWORD *)this + 1098 * a2 + a3 + 913);
  result = 4392 * a2;
  ++*((_DWORD *)this + 1098 * a2 + 980);
  return result;
}


// address=[0x1477b00]
// Decompiled from int __thiscall CStatistic::GetKillsVehicleOfType(_DWORD *this, int a2, int a3)
int  CStatistic::GetKillsVehicleOfType(int,int)const {
  
  return this[1098 * a2 + 913 + a3];
}


// address=[0x1477b30]
// Decompiled from int __thiscall CStatistic::GetKillsVehicle(CStatistic *this, int a2)
int  CStatistic::GetKillsVehicle(int)const {
  
  return *((_DWORD *)this + 1098 * a2 + 980);
}


// address=[0x1477b50]
// Decompiled from int __thiscall CStatistic::IncLossesVehicleOfType(CStatistic *this, int a2, int a3)
void  CStatistic::IncLossesVehicleOfType(int,int) {
  
  int result; // eax

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 996, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 6)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 997, "(_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++*((_DWORD *)this + 1098 * a2 + a3 + 981);
  result = 4392 * a2;
  ++*((_DWORD *)this + 1098 * a2 + 1048);
  return result;
}


// address=[0x1477c10]
// Decompiled from int __thiscall CStatistic::GetLossesVehicleOfType(_DWORD *this, int a2, int a3)
int  CStatistic::GetLossesVehicleOfType(int,int)const {
  
  return this[1098 * a2 + 981 + a3];
}


// address=[0x1477c40]
// Decompiled from int __thiscall CStatistic::GetLossesVehicle(CStatistic *this, int a2)
int  CStatistic::GetLossesVehicle(int)const {
  
  return *((_DWORD *)this + 1098 * a2 + 1048);
}


// address=[0x1477c60]
// Decompiled from int __thiscall CStatistic::IncBuildingLosses(CStatistic *this, int a2)
void  CStatistic::IncBuildingLosses(int) {
  
  int result; // eax

  result = 4392 * a2;
  ++*((_DWORD *)this + 1098 * a2 + 912);
  return result;
}


// address=[0x1477ca0]
// Decompiled from int __thiscall CStatistic::GetBuildingLosses(CStatistic *this, int a2)
int  CStatistic::GetBuildingLosses(int) {
  
  return *((_DWORD *)this + 1098 * a2 + 912);
}


// address=[0x1477cc0]
// Decompiled from void __thiscall CStatistic::DecLandSize(CStatistic *this, int a2, int a3)
void  CStatistic::DecLandSize(int,int) {
  
  ;
}


// address=[0x1477cd0]
// Decompiled from void __thiscall CStatistic::IncLandSize(CStatistic *this, int a2, int a3)
void  CStatistic::IncLandSize(int,int) {
  
  ;
}


// address=[0x1477ce0]
// Decompiled from int __thiscall CStatistic::GetLandSize(CStatistic *this, int a2)
int  CStatistic::GetLandSize(int)const {
  
  return *((_DWORD *)this + 1098 * a2 + 744);
}


// address=[0x1477d00]
// Decompiled from int __thiscall CStatistic::GetMaxLandSize(CStatistic *this, int a2)
int  CStatistic::GetMaxLandSize(int)const {
  
  return *((_DWORD *)this + 1098 * a2 + 1052);
}


// address=[0x1477d20]
// Decompiled from int __thiscall CStatistic::GetLandSizePercent(CStatistic *this, int a2)
int  CStatistic::GetLandSizePercent(int) {
  
  CStatistic::CalculateLandSize(this);
  return *((_DWORD *)this + 1098 * a2 + 744);
}


// address=[0x1477d50]
// Decompiled from void __thiscall CStatistic::SetOffenceStrength100(CStatistic *this, int a2, int a3)
void  CStatistic::SetOffenceStrength100(int,int) {
  
  int v4; // [esp+8h] [ebp-4h]

  if ( (a2 < 1 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1150, "_iPlayerId >= 1 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a2 >= 1 && a2 < 9 )
  {
    v4 = 0;
    if ( a3 > 0 )
    {
      v4 = (a3 << 8) / 100;
      if ( v4 >= *((_DWORD *)this + 1098 * a2 + 745) )
      {
        if ( v4 > 384 )
          v4 = 384;
      }
      else
      {
        v4 = *((_DWORD *)this + 1098 * a2 + 745);
      }
    }
    *((_DWORD *)this + 1098 * a2 + 1098) = v4;
    CStatistic::SPlayerStatistic::CalculateFightingStrength((CStatistic *)((char *)this + 4392 * a2 + 4), a2);
  }
}


// address=[0x1477e10]
// Decompiled from int __thiscall CStatistic::UsedBuildingMaterial(CStatistic *this, int a2)
int  CStatistic::UsedBuildingMaterial(int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1129, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 754);
}


// address=[0x1477e60]
// Decompiled from int __thiscall CStatistic::GetTotalTowers(CStatistic *this, int a2)
int  CStatistic::GetTotalTowers(int) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1523, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 437) + *((_DWORD *)this + 1098 * a2 + 436) + *((_DWORD *)this + 1098 * a2 + 435);
}


// address=[0x1477f00]
// Decompiled from int __thiscall CStatistic::GetTotalMineProduction(CStatistic *this, int a2)
int  CStatistic::GetTotalMineProduction(int) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1535, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 707)
       + *((_DWORD *)this + 1098 * a2 + 719)
       + *((_DWORD *)this + 1098 * a2 + 701)
       + *((_DWORD *)this + 1098 * a2 + 696);
}


// address=[0x1477fb0]
// Decompiled from int __thiscall CStatistic::GetTotalFood(CStatistic *this, int a2)
int  CStatistic::GetTotalFood(int) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1548, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 710) + *((_DWORD *)this + 1098 * a2 + 697) + *((_DWORD *)this + 1098 * a2 + 695);
}


// address=[0x1478050]
// Decompiled from int __thiscall CStatistic::SetPlayerExitTime(_DWORD *this, int a2, int a3)
void  CStatistic::SetPlayerExitTime(int,unsigned int) {
  
  int result; // eax

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1560, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  result = a3;
  this[1098 * a2 + 1051] = a3;
  return result;
}


// address=[0x14780a0]
// Decompiled from int __thiscall CStatistic::GetPlayerExitTime(CStatistic *this, int a2)
unsigned int  CStatistic::GetPlayerExitTime(int) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1570, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 1051);
}


// address=[0x14780f0]
// Decompiled from int __thiscall CStatistic::UpdateStartStatistic(CStatistic *this)
void  CStatistic::UpdateStartStatistic(void) {
  
  int result; // eax
  int n; // [esp+4h] [ebp-18h]
  int m; // [esp+8h] [ebp-14h]
  int k; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  int i; // [esp+18h] [ebp-4h]

  for ( i = 1; i <= 8; ++i )
  {
    for ( j = 0; j < 67; ++j )
    {
      *((_DWORD *)this + 1098 * i + j + 69) = *((_DWORD *)this + 1098 * i + j + 1);
      *((_DWORD *)this + 1098 * i + 136) += *((_DWORD *)this + 1098 * i + j + 1);
    }
    for ( k = 0; k < 83; ++k )
    {
      *((_DWORD *)this + 1098 * i + k + 389) = *((_DWORD *)this + 1098 * i + k + 139);
      *((_DWORD *)this + 1098 * i + 472) += *((_DWORD *)this + 1098 * i + k + 139);
    }
    for ( m = 0; m < 6; ++m )
    {
      *((_DWORD *)this + 1098 * i + m + 737) = *((_DWORD *)this + 1098 * i + m + 730);
      *((_DWORD *)this + 1098 * i + 743) += *((_DWORD *)this + 1098 * i + m + 730);
    }
    for ( n = 0; n < 43; ++n )
    {
      *((_DWORD *)this + 1098 * i + n + 686) = *((_DWORD *)this + 1098 * i + n + 642);
      *((_DWORD *)this + 1098 * i + 729) += *((_DWORD *)this + 1098 * i + n + 642);
    }
    result = i + 1;
  }
  return result;
}


// address=[0x1478330]
// Decompiled from _DWORD *__thiscall CStatistic::FillExtraInfo(CStatistic *this)
void  CStatistic::FillExtraInfo(void) {
  
  int v1; // esi
  int Good; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int NumberOfSettlers; // esi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // esi
  int v16; // esi
  int v17; // esi
  int v18; // esi
  int v19; // esi
  int v20; // esi
  int v21; // esi
  int v22; // esi
  int v23; // esi
  int v24; // esi
  int v25; // esi
  int v27; // [esp+Ch] [ebp-48h]
  int v28; // [esp+10h] [ebp-44h]
  int i; // [esp+14h] [ebp-40h]
  CPlayerGameData *v30; // [esp+18h] [ebp-3Ch]
  CEcoSector *EcoSectorPtr; // [esp+1Ch] [ebp-38h]
  int LocalPlayerId; // [esp+28h] [ebp-2Ch]
  CEvn_Event v34; // [esp+2Ch] [ebp-28h] BYREF
  int v35; // [esp+50h] [ebp-4h]

  ((void (__thiscall *)(void *))*g_cExtendedMenuInfo)(&g_cExtendedMenuInfo);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v28 = 0;
  v30 = CPlayerManager::PlayerGameData(LocalPlayerId);
  CPlayerGameData::ResetIterator(v30);
  for ( i = CPlayerGameData::GetNextEcoSectorId(v30); i; i = CPlayerGameData::GetNextEcoSectorId(v30) )
  {
    EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, i);
    if ( EcoSectorPtr && CEcoSector::Owner(EcoSectorPtr) == LocalPlayerId )
    {
      v1 = CEcoSector::NrOfSettler(EcoSectorPtr, 1);
      v27 = v1 - CEcoSector::MinCarrier(EcoSectorPtr);
      if ( v27 > 0 )
        v28 += v27;
    }
  }
  *((_DWORD *)&g_cExtendedMenuInfo + 2) = v28;
  *((_DWORD *)&g_cExtendedMenuInfo + 3) = CEcoSectorMgr::GetNrOfCurrentTotalBeds(
                                            (CEcoSectorMgr *)g_cESMgr,
                                            LocalPlayerId);
  *((_DWORD *)&g_cExtendedMenuInfo + 4) = CStatistic::GetGood(this, LocalPlayerId, 7);
  *((_DWORD *)&g_cExtendedMenuInfo + 5) = CStatistic::GetGood(this, LocalPlayerId, 32);
  *((_DWORD *)&g_cExtendedMenuInfo + 6) = CStatistic::GetGood(this, LocalPlayerId, 14);
  Good = CStatistic::GetGood(this, LocalPlayerId, 8);
  v3 = CStatistic::GetGood(this, LocalPlayerId, 34) + Good;
  v4 = CStatistic::GetGood(this, LocalPlayerId, 5) + v3;
  v5 = CStatistic::GetGood(this, LocalPlayerId, 6) + v4;
  *((_DWORD *)&g_cExtendedMenuInfo + 7) = CStatistic::GetGood(this, LocalPlayerId, 38) + v5;
  v6 = CStatistic::GetGood(this, LocalPlayerId, 9);
  v7 = CStatistic::GetGood(this, LocalPlayerId, 24) + v6;
  *((_DWORD *)&g_cExtendedMenuInfo + 8) = CStatistic::GetGood(this, LocalPlayerId, 11) + v7;
  NumberOfSettlers = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 29);
  v9 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 30) + NumberOfSettlers;
  v10 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 31) + v9;
  v11 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 32) + v10;
  v12 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 33) + v11;
  v13 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 34) + v12;
  v14 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 38) + v13;
  v15 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 39) + v14;
  v16 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 40) + v15;
  v17 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 41) + v16;
  v18 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 42) + v17;
  v19 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 43) + v18;
  v20 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 35) + v19;
  v21 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 36) + v20;
  v22 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 37) + v21;
  v23 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 61) + v22;
  v24 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 62) + v23;
  v25 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, 63) + v24;
  *((_DWORD *)&g_cExtendedMenuInfo + 9) = CSettlerMgr::GetNumberOfSettlers(
                                            (CSettlerMgr *)g_cSettlerMgr,
                                            LocalPlayerId,
                                            44)
                                        + v25;
  *((_DWORD *)&g_cExtendedMenuInfo + 10) = CStatistic::OffenceStrength100(this, LocalPlayerId);
  *((_DWORD *)&g_cExtendedMenuInfo + 11) = CStatistic::DefenceStrength100(this, LocalPlayerId);
  *((_DWORD *)&g_cExtendedMenuInfo + 12) = CStatistic::GetMana(this, LocalPlayerId);
  *((_DWORD *)&g_cExtendedMenuInfo + 1) = 37;
  CEvn_Event::CEvn_Event(&v34, 0x25Cu, 0, (unsigned int)&g_cExtendedMenuInfo, 0);
  v35 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1701, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v34);
  v35 = -1;
  return CEvn_Event::~CEvn_Event(&v34);
}


// address=[0x1478720]
// Decompiled from _DWORD *CStatistic::FillEconomyGameMenu()
static void __cdecl CStatistic::FillEconomyGameMenu(class CInfoExchange *,bool,bool) {
  
  CEvn_Event *v1; // [esp+8h] [ebp-40h]
  int v2; // [esp+14h] [ebp-34h]
  int j; // [esp+18h] [ebp-30h]
  int i; // [esp+1Ch] [ebp-2Ch]
  CEvn_Event v5; // [esp+20h] [ebp-28h] BYREF
  int v6; // [esp+44h] [ebp-4h]

  CInfoExchange::Clear(&g_cEconomyGameInfo);
  dword_3F1EE84 = 36;
  for ( i = 0; i < 7; ++i )
  {
    v2 = (unsigned __int8)CGameData::GetEconomyGoodsArray(g_pGameData)[i];
    dword_3F1EE88[3 * i] = v2;
    for ( j = 1; j <= CPlayerManager::LastPlayerId(); ++j )
    {
      if ( CAlliances::AllianceId(j) == 1 )
        dword_3F1EE8C[3 * i] += CStatistic::GetWinGood((CStatistic *)&g_cStatistic, j, v2);
      else
        dword_3F1EE90[3 * i] += CStatistic::GetWinGood((CStatistic *)&g_cStatistic, j, v2);
    }
  }
  v1 = CEvn_Event::CEvn_Event(&v5, 0x25Au, 0, (unsigned int)&g_cEconomyGameInfo, 0);
  v6 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v1);
  v6 = -1;
  return CEvn_Event::~CEvn_Event(&v5);
}


// address=[0x1478890]
// Decompiled from void *__thiscall CStatistic::FreezeEcoStatistic(CStatistic *this)
void  CStatistic::FreezeEcoStatistic(void) {
  
  void *result; // eax
  int i; // [esp+4h] [ebp-4h]

  result = (void *)(unsigned __int8)CStatistic::m_bWonStateSaved;
  if ( CStatistic::m_bWonStateSaved )
    return result;
  CStatistic::m_bWonStateSaved = 1;
  for ( i = 0; i < 9; ++i )
    result = j__memcpy((char *)this + 4392 * i + 4220, (char *)this + 4392 * i + 2568, 0xACu);
  return result;
}


// address=[0x147a280]
// Decompiled from int __thiscall CStatistic::DefenceStrength100(CStatistic *this, int a2)
int  CStatistic::DefenceStrength100(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\Statistic.h",
         357,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (100 * *((_DWORD *)this + 1098 * a2 + 752)) >> 8;
}


// address=[0x147a3b0]
// Decompiled from int __thiscall CStatistic::OffenceStrength100(CStatistic *this, int a2)
int  CStatistic::OffenceStrength100(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\Statistic.h",
         371,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (100 * *((_DWORD *)this + 1098 * a2 + 753)) >> 8;
}


// address=[0x14aa6b0]
// Decompiled from int __thiscall CStatistic::CStatistic(int this, struct boost::exception_detail::clone_base *a2)
 CStatistic::CStatistic(class CStatistic const &) {
  
  IS4ChunkObject::IS4ChunkObject((boost::exception_detail::clone_base *)this, a2);
  *(_DWORD *)this = CStatistic::_vftable_;
  j__memcpy((void *)(this + 4), (char *)a2 + 4, 0x9A6Cu);
  return this;
}


// address=[0x1592160]
// Decompiled from int __thiscall CStatistic::DefenceStrength256(CStatistic *this, int a2)
int  CStatistic::DefenceStrength256(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\Statistic.h",
         387,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 752);
}


// address=[0x1592220]
// Decompiled from int __thiscall CStatistic::OffenceStrength256(CStatistic *this, int a2)
int  CStatistic::OffenceStrength256(int)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\Statistic.h",
         395,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 1098 * a2 + 753);
}


// address=[0x160db70]
// Decompiled from CStatistic *__thiscall CStatistic::SetDontShowLastNPlayers(CStatistic *this, int a2)
void  CStatistic::SetDontShowLastNPlayers(int) {
  
  CStatistic *result; // eax

  result = this;
  *((_DWORD *)this + 9883) = a2;
  return result;
}


// address=[0x1478900]
// Decompiled from int __thiscall CStatistic::CalcPlayerOffenceStrengthBaseValues(CStatistic *this)
void  CStatistic::CalcPlayerOffenceStrengthBaseValues(void) {
  
  int result; // eax
  int v2; // [esp+4h] [ebp-10h]
  int v4; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v4 = CPlayerManager::NumberOfPlayers();
  if ( v4 <= 0 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1373, "iNumberOfPlayers > 0") == 1 )
    __debugbreak();
  result = 0;
  if ( v4 <= 0 )
    return result;
  result = 768 / (v4 + 4);
  v2 = result;
  if ( result <= 0 )
  {
    result = BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1383, "iOffenceStrengthBase256 > 0");
    if ( result == 1 )
      __debugbreak();
  }
  for ( i = 1; i < v4 + 1; ++i )
  {
    if ( CPlayerManager::Race(i) == 3 )
      *((_DWORD *)this + 1098 * i + 745) = 256;
    else
      *((_DWORD *)this + 1098 * i + 745) = v2;
    CStatistic::SPlayerStatistic::CalculateFightingStrength((CStatistic *)((char *)this + 4392 * i + 4), i);
    result = i + 1;
  }
  return result;
}


// address=[0x1478a00]
// Decompiled from void __thiscall CStatistic::UpdateFightingStrength(CStatistic *this, int a2, unsigned int a3, int a4, int a5)
void  CStatistic::UpdateFightingStrength(int,int,int,int) {
  
  char *BuildingInfo; // [esp+10h] [ebp-8h]

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         1411,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 > 4 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1412, "(_iRace >= 0) && (_iRace < RACE_MAX)") == 1 )
    __debugbreak();
  if ( (a4 <= 0 || a4 >= 83)
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         1413,
         "(_iBuildingType > BUILDING_NO_BUILDING) && (_iBuildingType < BUILDING_MAX)") == 1 )
  {
    __debugbreak();
  }
  BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(a3, a4);
  if ( a4 < 64 || a4 > 75 )
    CStatistic::SPlayerStatistic::UpdateFightingStrength(
      (CStatistic *)((char *)this + 4392 * a2 + 4),
      a2,
      BuildingInfo[3] * a5,
      BuildingInfo[2] * a5,
      BuildingInfo[4] * a5,
      0);
  else
    CStatistic::SPlayerStatistic::UpdateFightingStrength(
      (CStatistic *)((char *)this + 4392 * a2 + 4),
      a2,
      BuildingInfo[3] * a5,
      BuildingInfo[2] * a5,
      BuildingInfo[4] * a5,
      1);
}


// address=[0x1478b20]
// Decompiled from int __thiscall CStatistic::CalculateFightingStrengths(CStatistic *this)
void  CStatistic::CalculateFightingStrengths(void) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  result = CPlayerManager::LastPlayerId();
  v3 = result;
  for ( i = 1; i <= v3; ++i )
  {
    CStatistic::SPlayerStatistic::CalculateFightingStrength((CStatistic *)((char *)this + 4392 * i + 4), i);
    result = i + 1;
  }
  return result;
}


// address=[0x1478b70]
// Decompiled from int __thiscall CStatistic::CalculateLandSize(CStatistic *this)
void  CStatistic::CalculateLandSize(void) {
  
  int result; // eax
  int v2; // esi
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  result = CPlayerManager::LastPlayerId();
  v3 = result;
  for ( i = 1; i <= v3; ++i )
  {
    *((_DWORD *)this + 1098 * i + 744) = (*(int (__thiscall **)(void *, int))(*(_DWORD *)g_pTiling + 60))(g_pTiling, i);
    v2 = 100 * *((_DWORD *)this + 1098 * i + 744);
    *((_DWORD *)this + 1098 * i + 744) = v2 / (*(int (__thiscall **)(void *))(*(_DWORD *)g_pTiling + 52))(g_pTiling);
    *((_DWORD *)this + 1098 * i + 1052) = *(_DWORD *)std::max<long>(
                                                       (char *)this + 4392 * i + 4208,
                                                       (char *)this + 4392 * i + 2976);
    result = i + 1;
  }
  return result;
}


// address=[0x1478c50]
// Decompiled from int __thiscall CStatistic::CalculateMana(CStatistic *this)
void  CStatistic::CalculateMana(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  result = CPlayerManager::LastPlayerId();
  v2 = result;
  for ( i = 1; i <= v2; ++i )
  {
    *((_DWORD *)this + 1098 * i + 1049) = CMagic::GetCurrentManaAmount(i);
    *((_DWORD *)this + 1098 * i + 1050) = CMagic::TotalAmountOfCollectedMana(i);
    result = i + 1;
  }
  return result;
}


// address=[0x3f20320]
// [Decompilation failed for static bool CStatistic::m_bWonStateSaved]

