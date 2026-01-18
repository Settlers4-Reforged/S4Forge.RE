#include "IAIEnvironment.h"

// Definitions for class IAIEnvironment

// address=[0x12fd370]
// Decompiled from int __cdecl IAIEnvironment::MinutesToTicks(int a1)
unsigned int __cdecl IAIEnvironment::MinutesToTicks(int a1) {
  
  return 840 * a1;
}


// address=[0x12fd4d0]
// Decompiled from int __cdecl IAIEnvironment::PackXYFast(int a1, int a2)
int __cdecl IAIEnvironment::PackXYFast(int a1, int a2) {
  
  return a1 + (a2 << 16);
}


// address=[0x12fd580]
// Decompiled from unsigned int IAIEnvironment::Rand()
unsigned int __cdecl IAIEnvironment::Rand(void) {
  
  return CRandom16::Rand((CRandom16 *)IAIEnvironment::m_pRandom);
}


// address=[0x12fd770]
// Decompiled from int IAIEnvironment::TickCounter()
unsigned int __cdecl IAIEnvironment::TickCounter(void) {
  
  return IAIEnvironment::m_uTickCounter;
}


// address=[0x12fd7c0]
// Decompiled from int __cdecl IAIEnvironment::UnpackXFast(unsigned __int16 a1)
int __cdecl IAIEnvironment::UnpackXFast(int a1) {
  
  return a1;
}


// address=[0x12fd7d0]
// Decompiled from int __cdecl IAIEnvironment::UnpackYFast(int a1)
int __cdecl IAIEnvironment::UnpackYFast(int a1) {
  
  return a1 >> 16;
}


// address=[0x12fd890]
// Decompiled from bool __cdecl IAIEnvironment::WorldInWorld(unsigned int a1, unsigned int a2)
bool __cdecl IAIEnvironment::WorldInWorld(int a1, int a2) {
  
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  if ( a1 < IAIEnvironment::m_iWorldWidthHeigth )
    v4 = -1;
  else
    v4 = 0;
  if ( a2 < IAIEnvironment::m_iWorldWidthHeigth )
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x12fd910]
// Decompiled from int __cdecl IAIEnvironment::WorldIndex(int a1, int a2)
int __cdecl IAIEnvironment::WorldIndex(int a1, int a2) {
  
  return a1 + IAIEnvironment::m_iWorldWidthHeigth * a2;
}


// address=[0x12fd930]
// Decompiled from int __cdecl IAIEnvironment::WorldSectorId(int x, int y)
int __cdecl IAIEnvironment::WorldSectorId(int x, int y) {
  
  int v2; // eax

  v2 = IAIEnvironment::WorldIndex(x, y);
  return IAIEnvironment::WorldSectorId(v2);
}


// address=[0x1301140]
// Decompiled from bool __cdecl IAIEnvironment::AlliancesAllied(int a1, int a2)
bool __cdecl IAIEnvironment::AlliancesAllied(int a1, int a2) {
  
  int v2; // esi

  v2 = CAlliances::AllianceId(a1);
  return v2 == CAlliances::AllianceId(a2);
}


// address=[0x1301190]
// Decompiled from bool __cdecl IAIEnvironment::AlliancesIsValidUsedPlayerId(int a1)
bool __cdecl IAIEnvironment::AlliancesIsValidUsedPlayerId(int a1) {
  
  return CAlliances::IsValidUsedPlayerId(a1);
}


// address=[0x13011b0]
// Decompiled from int __cdecl IAIEnvironment::AlliancesPlayerAllyBits(int a1)
int __cdecl IAIEnvironment::AlliancesPlayerAllyBits(int a1) {
  
  return CAlliances::PlayerAllyBits(a1);
}


// address=[0x13011d0]
// Decompiled from int __cdecl IAIEnvironment::AlliancesPlayerBit(int a1)
int __cdecl IAIEnvironment::AlliancesPlayerBit(int a1) {
  
  return CAlliances::PlayerBit(a1);
}


// address=[0x13011f0]
// Decompiled from int __cdecl IAIEnvironment::ClipMax(int a1, int a2)
int __cdecl IAIEnvironment::ClipMax(int a1, int a2) {
  
  if ( a1 > a2 )
    return a2;
  else
    return a1;
}


// address=[0x1303a10]
// Decompiled from bool __cdecl IAIEnvironment::WorldInWorldPackedXY(int a1)
bool __cdecl IAIEnvironment::WorldInWorldPackedXY(int a1) {
  
  int v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v3 = IAIEnvironment::UnpackYFast(a1);
  v1 = IAIEnvironment::UnpackXFast(a1);
  return IAIEnvironment::WorldInWorld(v1, v3);
}


// address=[0x1303c40]
// Decompiled from int IAIEnvironment::AlliancesLastPlayerId()
int __cdecl IAIEnvironment::AlliancesLastPlayerId(void) {
  
  return CAlliances::LastPlayerId();
}


// address=[0x1306400]
// Decompiled from int __cdecl IAIEnvironment::AlliancesAllianceId(int a1)
int __cdecl IAIEnvironment::AlliancesAllianceId(int a1) {
  
  return CAlliances::AllianceId(a1);
}


// address=[0x1306420]
// Decompiled from int __cdecl IAIEnvironment::AlliancesPlayerEnemyBits(int a1)
int __cdecl IAIEnvironment::AlliancesPlayerEnemyBits(int a1) {
  
  return CAlliances::PlayerEnemyBits(a1);
}


// address=[0x1306440]
// Decompiled from void __cdecl IAIEnvironment::BuildingGetEnsignPosition(int a1, int *a2, int *a3)
void __cdecl IAIEnvironment::BuildingGetEnsignPosition(int a1, int & a2, int & a3) {
  
  int v3; // eax

  v3 = IAIEnvironment::BuildingPackedEnsignPosition(a1);
  IAIEnvironment::UnpackXYFast(v3, a2, a3);
}


// address=[0x13065c0]
// Decompiled from void __cdecl IAIEnvironment::EntityGetPosition(int a1, int *a2, int *a3)
void __cdecl IAIEnvironment::EntityGetPosition(int a1, int & a2, int & a3) {
  
  int v3; // eax

  v3 = IAIEnvironment::EntityPackedPosition(a1);
  IAIEnvironment::UnpackXYFast(v3, a2, a3);
}


// address=[0x1306a20]
// Decompiled from int *__cdecl IAIEnvironment::UnpackXYFast(int a1, int *a2, int *a3)
void __cdecl IAIEnvironment::UnpackXYFast(int a1, int & a2, int & a3) {
  
  int *result; // eax

  *a2 = (unsigned __int16)a1;
  result = a3;
  *a3 = a1 >> 16;
  return result;
}


// address=[0x1306a50]
// Decompiled from void __cdecl IAIEnvironment::WorldEcoSectorIdPackedXY(struct _iobuf *a1)
int __cdecl IAIEnvironment::WorldEcoSectorIdPackedXY(int a1) {
  
  int v1; // eax

  v1 = IAIEnvironment::WorldIndexPackedXY(a1);
  IAIEnvironment::WorldEcoSectorId(v1);
}


// address=[0x1306a70]
// Decompiled from int IAIEnvironment::WorldHeight()
int __cdecl IAIEnvironment::WorldHeight(void) {
  
  return IAIEnvironment::m_iWorldWidthHeigth;
}


// address=[0x1306a80]
// Decompiled from int __cdecl IAIEnvironment::WorldIndexPackedXY(int a1)
int __cdecl IAIEnvironment::WorldIndexPackedXY(int a1) {
  
  int v1; // esi

  v1 = IAIEnvironment::UnpackXFast(a1);
  return v1 + IAIEnvironment::m_iWorldWidthHeigth * IAIEnvironment::UnpackYFast(a1);
}


// address=[0x1306ac0]
// Decompiled from bool __cdecl IAIEnvironment::WorldIsScree(struct _Cnd_internal_imp_t *a1, struct _Mtx_internal_imp_t *a2)
bool __cdecl IAIEnvironment::WorldIsScree(int a1, int a2) {
  
  int v2; // eax

  v2 = IAIEnvironment::WorldIndex((int)a1, (int)a2);
  return IAIEnvironment::WorldIsScree(v2);
}


// address=[0x1306af0]
// Decompiled from int IAIEnvironment::WorldWidth()
int __cdecl IAIEnvironment::WorldWidth(void) {
  
  return IAIEnvironment::m_iWorldWidthHeigth;
}


// address=[0x13093c0]
// Decompiled from const int *__cdecl IAIEnvironment::AlliancesEnemyPlayerIds(int a1)
int const * __cdecl IAIEnvironment::AlliancesEnemyPlayerIds(int a1) {
  
  return CAlliances::EnemyPlayerIds(a1);
}


// address=[0x1309420]
// Decompiled from int __cdecl IAIEnvironment::Clip(int a1, int a2, int a3)
int __cdecl IAIEnvironment::Clip(int a1, int a2, int a3) {
  
  if ( a1 <= a2 )
    return a2;
  if ( a1 < a3 )
    return a1;
  else
    return a3;
}


// address=[0x1309470]
// Decompiled from int __cdecl IAIEnvironment::ClipMin(int a1, int a2)
int __cdecl IAIEnvironment::ClipMin(int a1, int a2) {
  
  if ( a1 < a2 )
    return a2;
  else
    return a1;
}


// address=[0x1309560]
// Decompiled from int __cdecl IAIEnvironment::GridDistancePackedXY(int a1, int a2)
int __cdecl IAIEnvironment::GridDistancePackedXY(int a1, int a2) {
  
  int v2; // esi
  int v3; // esi
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  v2 = IAIEnvironment::UnpackYFast(a2);
  v6 = v2 - IAIEnvironment::UnpackYFast(a1);
  v3 = IAIEnvironment::UnpackXFast(a2);
  v4 = IAIEnvironment::UnpackXFast(a1);
  return IAIEnvironment::GridDistance(v3 - v4, v6);
}


// address=[0x130a4b0]
// Decompiled from int IAIEnvironment::GlobalEcoAIFlags()
int __cdecl IAIEnvironment::GlobalEcoAIFlags(void) {
  
  return IAIEnvironment::m_iGlobalEcoAIFlags;
}


// address=[0x130a4e0]
// Decompiled from int IAIEnvironment::RandomPtr()
class CRandom16 * __cdecl IAIEnvironment::RandomPtr(void) {
  
  return IAIEnvironment::m_pRandom;
}


// address=[0x130add0]
// Decompiled from int __cdecl IAIEnvironment::GridDistance(Grid *a1, int a2)
int __cdecl IAIEnvironment::GridDistance(int a1, int a2) {
  
  return Grid::DistanceInline(a1, a2);
}


// address=[0x130adf0]
// Decompiled from int __cdecl IAIEnvironment::WorldOwnerId(int a1)
int __cdecl IAIEnvironment::WorldOwnerId(int a1) {
  
  return ITiling::OwnerId(a1);
}


// address=[0x130ae10]
// Decompiled from int __cdecl IAIEnvironment::WorldSectorId(int a1)
int __cdecl IAIEnvironment::WorldSectorId(int a1) {
  
  return ITiling::SectorId(a1);
}


// address=[0x130ae30]
// Decompiled from int __cdecl IAIEnvironment::WorldCatapultSectorId(int a1)
int __cdecl IAIEnvironment::WorldCatapultSectorId(int a1) {
  
  return ITiling::CatapultSectorId(a1);
}


// address=[0x130ae50]
// Decompiled from int __cdecl IAIEnvironment::WorldEcoSectorId(int a1)
int __cdecl IAIEnvironment::WorldEcoSectorId(int a1) {
  
  return ITiling::EcoSectorId(a1);
}


// address=[0x130ae70]
// Decompiled from int __cdecl IAIEnvironment::WorldIsBlockedLand(int a1)
bool __cdecl IAIEnvironment::WorldIsBlockedLand(int a1) {
  
  return CWorldManager::IsBlockedLand(a1);
}


// address=[0x130ae90]
// Decompiled from bool __cdecl IAIEnvironment::WorldIsScree(int a1)
bool __cdecl IAIEnvironment::WorldIsScree(int a1) {
  
  return CWorldManager::Ground(a1) == 32;
}


// address=[0x130aec0]
// Decompiled from int __cdecl IAIEnvironment::EntityObjectType(int a1)
int __cdecl IAIEnvironment::EntityObjectType(int a1) {
  
  unsigned __int8 *v1; // eax

  v1 = (unsigned __int8 *)CMapObjectMgr::Entity(a1);
  return IEntity::ObjType(v1);
}


// address=[0x130aee0]
// Decompiled from int __cdecl IAIEnvironment::EntityType(int a1)
int __cdecl IAIEnvironment::EntityType(int a1) {
  
  unsigned __int16 *v1; // eax

  v1 = (unsigned __int16 *)CMapObjectMgr::Entity(a1);
  return IEntity::Type(v1);
}


// address=[0x130af00]
// Decompiled from int __cdecl IAIEnvironment::EntityPackedPosition(int a1)
int __cdecl IAIEnvironment::EntityPackedPosition(int a1) {
  
  struct IEntity *v1; // eax

  v1 = CMapObjectMgr::Entity(a1);
  return IEntity::PackedXY(v1);
}


// address=[0x130af20]
// Decompiled from int __cdecl IAIEnvironment::EntitySectorId(int a1)
int __cdecl IAIEnvironment::EntitySectorId(int a1) {
  
  int v1; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v4 = 0;
  v5 = CMapObjectMgr::EntityPtr(a1);
  if ( !v5 )
    return v4;
  v1 = IEntity::PackedXY(v5);
  v3 = IAIEnvironment::WorldIndexPackedXY(v1);
  return ITiling::SectorId(v3);
}


// address=[0x130af70]
// Decompiled from int __cdecl IAIEnvironment::EntityUniqueId(signed int a1)
int __cdecl IAIEnvironment::EntityUniqueId(int a1) {
  
  int v2; // [esp+0h] [ebp-4h]

  v2 = 0;
  if ( a1 > 0 )
    return CMapObjectMgr::GetUniqueId(a1);
  return v2;
}


// address=[0x130afa0]
// Decompiled from int __cdecl IAIEnvironment::EntityGetEntityInfo(int a1, unsigned __int8 a2)
class CAIEntityInfo * __cdecl IAIEnvironment::EntityGetEntityInfo(int a1, bool a2) {
  
  int v3; // [esp+8h] [ebp-20h]
  int v4; // [esp+14h] [ebp-14h]
  _DWORD *v5; // [esp+18h] [ebp-10h]

  if ( a1 <= 0 && BBSupportDbgReport(2, (int)"AI\\AI_Environment.cpp", 355, (int)"_iEntityId > 0") == 1 )
    __debugbreak();
  v4 = 0;
  v5 = (_DWORD *)CMapObjectMgr::EntityPtr(a1);
  if ( !v5 )
    return v4;
  v4 = IEntity::AIEntityInfoPtr(v5);
  if ( ((v4 == 0) & a2) == 0 )
    return v4;
  if ( !IEntity::FlagBits(v5, AliveMask) )
    return v4;
  if ( IEntity::ID() != a1
    && BBSupportDbgReport(2, (int)"AI\\AI_Environment.cpp", 369, (int)"pEntity->ID() == _iEntityId") == 1 )
  {
    __debugbreak();
  }
  if ( operator new(0x18u) )
    v3 = CAIEntityInfo::CAIEntityInfo(a1);
  else
    v3 = 0;
  v4 = v3;
  IEntity::SetAIEntityInfoPtr(v3);
  return v4;
}


// address=[0x130b0e0]
// Decompiled from int __cdecl IAIEnvironment::EntityFlags(int a1)
int __cdecl IAIEnvironment::EntityFlags(int a1) {
  
  struct IEntity *v1; // eax

  v1 = CMapObjectMgr::Entity(a1);
  return IEntity::Flags(v1);
}


// address=[0x130b100]
// Decompiled from int __cdecl IAIEnvironment::EntityOwnerId(int a1)
int __cdecl IAIEnvironment::EntityOwnerId(int a1) {
  
  unsigned __int8 *v1; // eax

  v1 = (unsigned __int8 *)CMapObjectMgr::Entity(a1);
  return IEntity::OwnerId(v1);
}


// address=[0x130b120]
// Decompiled from _DWORD *__cdecl IAIEnvironment::EntitySetFlagBits(int a1, EntityFlag a2)
void __cdecl IAIEnvironment::EntitySetFlagBits(int a1, int a2) {
  
  struct IEntity *v2; // eax

  v2 = CMapObjectMgr::Entity(a1);
  return IEntity::SetFlagBits(v2, a2);
}


// address=[0x130b140]
// Decompiled from int __cdecl IAIEnvironment::EntityClearFlagBits(int a1, EntityFlag a2)
void __cdecl IAIEnvironment::EntityClearFlagBits(int a1, int a2) {
  
  _DWORD *v2; // eax

  v2 = (_DWORD *)CMapObjectMgr::Entity(a1);
  return IEntity::ClearFlagBits(v2, a2);
}


// address=[0x130b160]
// Decompiled from int __cdecl IAIEnvironment::EntityGetEntityTypeAndPosition(int a1, int *a2, int *a3, int *a4)
void __cdecl IAIEnvironment::EntityGetEntityTypeAndPosition(int a1, int & a2, int & a3, int & a4) {
  
  int result; // eax
  unsigned __int8 *v5; // [esp+0h] [ebp-4h]

  if ( a1 <= 0 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 388, "_iEntityId > 0") == 1 )
    __debugbreak();
  v5 = (unsigned __int8 *)CMapObjectMgr::Entity(a1);
  *a2 = IEntity::ObjType(v5);
  *a3 = IEntity::Type((unsigned __int16 *)v5);
  result = IEntity::PackedXY(v5);
  *a4 = result;
  return result;
}


// address=[0x130b1d0]
// Decompiled from unsigned int __cdecl IAIEnvironment::EntityWarriorType(int a1)
enum T_AI_WARRIOR_TYPE __cdecl IAIEnvironment::EntityWarriorType(int a1) {
  
  unsigned int v2; // [esp+8h] [ebp-4h]

  CMapObjectMgr::Entity(a1);
  v2 = IEntity::WarriorType();
  if ( v2 > 0xE
    && BBSupportDbgReport(2, (int)"AI\\AI_Environment.cpp", 408, (int)"uWarriorType <= AI_WARRIOR_TYPE_LAST") == 1 )
  {
    __debugbreak();
  }
  return v2;
}


// address=[0x130b230]
// Decompiled from unsigned int __cdecl IAIEnvironment::EntityGetWarriorTypeAndSectorId(int a1, unsigned int *a2, _DWORD *a3)
void __cdecl IAIEnvironment::EntityGetWarriorTypeAndSectorId(int a1, enum T_AI_WARRIOR_TYPE & a2, int & a3) {
  
  unsigned int result; // eax
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+8h] [ebp-Ch]
  unsigned int v6; // [esp+10h] [ebp-4h]

  if ( a1 <= 0 && BBSupportDbgReport(2, (int)"AI\\AI_Environment.cpp", 441, (int)"_iEntityId > 0") == 1 )
    __debugbreak();
  CMapObjectMgr::Entity(a1);
  v6 = IEntity::WarriorType();
  if ( v6 > 0xE
    && BBSupportDbgReport(2, (int)"AI\\AI_Environment.cpp", 447, (int)"uWarriorType <= AI_WARRIOR_TYPE_LAST") == 1 )
  {
    __debugbreak();
  }
  v5 = IEntity::WorldIdx();
  v4 = ITiling::SectorId(v5);
  result = v6;
  *a2 = v6;
  *a3 = v4;
  return result;
}


// address=[0x130b2d0]
// Decompiled from int __cdecl IAIEnvironment::EntityGetWarriorTypeAndPosition(int a1, enum T_AI_WARRIOR_TYPE *a2, int *a3, int *a4)
void __cdecl IAIEnvironment::EntityGetWarriorTypeAndPosition(int a1, enum T_AI_WARRIOR_TYPE & a2, int & a3, int & a4) {
  
  int result; // eax
  unsigned int v5; // [esp+0h] [ebp-8h]
  struct IEntity *v6; // [esp+4h] [ebp-4h]

  v6 = CMapObjectMgr::Entity(a1);
  v5 = IEntity::WarriorType();
  if ( v5 > 0xE && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 426, "uWarriorType <= AI_WARRIOR_TYPE_LAST") == 1 )
    __debugbreak();
  *(_DWORD *)a2 = v5;
  *a3 = IEntity::X(v6);
  result = IEntity::Y(v6);
  *a4 = result;
  return result;
}


// address=[0x130b340]
// Decompiled from bool __cdecl IAIEnvironment::EntityIsAlive(int a1)
bool __cdecl IAIEnvironment::EntityIsAlive(int a1) {
  
  _DWORD *v2; // [esp+0h] [ebp-8h]

  v2 = (_DWORD *)CMapObjectMgr::EntityPtr(a1);
  return v2 && IEntity::FlagBits(v2, (EntityFlag)&loc_3000000) != 0;
}


// address=[0x130b390]
// Decompiled from bool __cdecl IAIEnvironment::EntityIsReady(int a1)
bool __cdecl IAIEnvironment::EntityIsReady(int a1) {
  
  _DWORD *v2; // [esp+0h] [ebp-8h]

  v2 = (_DWORD *)CMapObjectMgr::EntityPtr(a1);
  return v2 && IEntity::FlagBits(v2, (EntityFlag)((char *)&loc_1FFFFFF + 1)) != 0;
}


// address=[0x130b3e0]
// Decompiled from bool __cdecl IAIEnvironment::EntityIsAliveAndHasGivenUniqueId(int a1, int a2)
bool __cdecl IAIEnvironment::EntityIsAliveAndHasGivenUniqueId(int a1, int a2) {
  
  _DWORD *v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+5h] [ebp-3h]

  v3 = (_DWORD *)CMapObjectMgr::EntityPtr(a1);
  if ( !v3 )
    return 0;
  v4 = IEntity::FlagBits(v3, AliveMask) != 0;
  return IEntity::UniqueId(v3) == a2 && v4;
}


// address=[0x130b450]
// Decompiled from bool __cdecl IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(int a1, int a2)
bool __cdecl IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(int a1, enum T_AI_WARRIOR_TYPE a2) {
  
  _DWORD *v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+5h] [ebp-3h]

  v3 = (_DWORD *)CMapObjectMgr::EntityPtr(a1);
  if ( !v3 )
    return 0;
  v4 = IEntity::FlagBits(v3, AliveMask) != 0;
  return IEntity::WarriorType() == a2 && v4;
}


// address=[0x130b4c0]
// Decompiled from void **__cdecl IAIEnvironment::EntityGetEntityInfoTower(int a1)
class CAIEntityInfoTower * __cdecl IAIEnvironment::EntityGetEntityInfoTower(int a1) {
  
  int v2; // [esp+0h] [ebp-Ch]
  int EntityInfo; // [esp+4h] [ebp-8h]
  void **v4; // [esp+8h] [ebp-4h]

  v2 = 0;
  EntityInfo = IAIEnvironment::EntityGetEntityInfo(a1, 1u);
  if ( !EntityInfo )
    return (void **)v2;
  v4 = (void **)CAIEntityInfo::ExtendedInfo(EntityInfo, 0);
  if ( !v4 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 473, "pEntityInfoEx != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(
          v4,
          0,
          &CAIEntityInfoEx__RTTI_Type_Descriptor_,
          &CAIEntityInfoTower__RTTI_Type_Descriptor_,
          0)
    && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 474, "dynamic_cast<CAIEntityInfoTower*>(pEntityInfoEx) != 0") == 1 )
  {
    __debugbreak();
  }
  return v4;
}


// address=[0x130b570]
// Decompiled from unsigned __int16 *__cdecl IAIEnvironment::EntitySendCastSpellCommand(int a1, int a2, int a3)
void __cdecl IAIEnvironment::EntitySendCastSpellCommand(int a1, int a2, int a3) {
  
  unsigned __int16 *result; // eax
  int v4; // eax
  _BYTE v5[24]; // [esp+4h] [ebp-30h] BYREF
  CEntityEvent *v6; // [esp+1Ch] [ebp-18h]
  CEntityEvent *v7; // [esp+20h] [ebp-14h]
  unsigned __int16 *v8; // [esp+24h] [ebp-10h]
  int v9; // [esp+30h] [ebp-4h]

  result = (unsigned __int16 *)CSettlerMgr::GetSettlerPtr(a1);
  v8 = result;
  if ( !result )
    return result;
  result = (unsigned __int16 *)IEntity::FlagBits(v8, Ready);
  if ( !result )
    return result;
  result = (unsigned __int16 *)IEntity::Type(v8);
  if ( result != (unsigned __int16 *)45 )
    return result;
  v4 = IEntity::OwnerId((unsigned __int8 *)v8);
  v7 = CEntityEvent::CEntityEvent((CEntityEvent *)v5, 3u, a2, v4, 0, a3);
  v6 = v7;
  v9 = 0;
  (*(void (__thiscall **)(unsigned __int16 *, CEntityEvent *))(*(_DWORD *)v8 + 80))(v8, v7);
  v9 = -1;
  return (unsigned __int16 *)CEntityEvent::~CEntityEvent(v5);
}


// address=[0x130b630]
// Decompiled from int __cdecl IAIEnvironment::MovingEntitySendMoveCommand(int a1, int a2, int a3, bool a4)
void __cdecl IAIEnvironment::MovingEntitySendMoveCommand(int a1, int a2, int a3, bool a4) {
  
  int result; // eax
  int v5; // eax
  _BYTE v6[24]; // [esp+4h] [ebp-3Ch] BYREF
  CEntityEvent *v7; // [esp+1Ch] [ebp-24h]
  CEntityEvent *v8; // [esp+20h] [ebp-20h]
  int v9; // [esp+24h] [ebp-1Ch]
  void **v10; // [esp+28h] [ebp-18h]
  int v11; // [esp+2Ch] [ebp-14h]
  int v12; // [esp+30h] [ebp-10h]
  int v13; // [esp+3Ch] [ebp-4h]

  v10 = (void **)CMapObjectMgr::EntityPtr(a1);
  result = j____RTDynamicCast(v10, 0, &IEntity__RTTI_Type_Descriptor_, &IMovingEntity__RTTI_Type_Descriptor_, 0);
  v12 = result;
  if ( !result )
    return result;
  if ( a4 )
    v11 = 0;
  else
    v11 = 4;
  v9 = v11;
  v5 = IAIEnvironment::PackXYFast(a2, a3);
  v8 = CEntityEvent::CEntityEvent((CEntityEvent *)v6, 0x11u, 13, v11, v5, 0);
  v7 = v8;
  v13 = 0;
  (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v12 + 80))(v12, v8);
  v13 = -1;
  return CEntityEvent::~CEntityEvent(v6);
}


// address=[0x130b710]
// Decompiled from bool __cdecl IAIEnvironment::MovingEntityIsWaiting(int a1)
bool __cdecl IAIEnvironment::MovingEntityIsWaiting(int a1) {
  
  void **v1; // eax

  v1 = CMapObjectMgr::MovingEntity(a1);
  return *(_BYTE *)(IMovingEntity::GetActualTask(v1) + 4) == 17;
}


// address=[0x130b750]
// Decompiled from int __cdecl IAIEnvironment::MovingEntityWalkingState(int a1)
int __cdecl IAIEnvironment::MovingEntityWalkingState(int a1) {
  
  void **v2; // [esp+0h] [ebp-Ch]
  IMovingEntity *v3; // [esp+4h] [ebp-8h]
  struct CWalking *v4; // [esp+8h] [ebp-4h]

  v2 = (void **)CMapObjectMgr::EntityPtr(a1);
  v3 = (IMovingEntity *)j____RTDynamicCast(
                          v2,
                          0,
                          &IEntity__RTTI_Type_Descriptor_,
                          &IMovingEntity__RTTI_Type_Descriptor_,
                          0);
  if ( v3 && (v4 = IMovingEntity::Walking(v3)) != 0 )
    return (*(int (__thiscall **)(struct CWalking *, _DWORD))(*(_DWORD *)v4 + 52))(v4, 0);
  else
    return 0;
}


// address=[0x130b7b0]
// Decompiled from int __cdecl IAIEnvironment::EntityEnterManakopter(int a1, int a2)
void __cdecl IAIEnvironment::EntityEnterManakopter(int a1, int a2) {
  
  int result; // eax
  _BYTE v3[24]; // [esp+4h] [ebp-34h] BYREF
  CEntityEvent *v4; // [esp+1Ch] [ebp-1Ch]
  CEntityEvent *v5; // [esp+20h] [ebp-18h]
  void **v6; // [esp+24h] [ebp-14h]
  int v7; // [esp+28h] [ebp-10h]
  int v8; // [esp+34h] [ebp-4h]

  v6 = (void **)CMapObjectMgr::EntityPtr(a1);
  result = j____RTDynamicCast(v6, 0, &IEntity__RTTI_Type_Descriptor_, &IAnimatedEntity__RTTI_Type_Descriptor_, 0);
  v7 = result;
  if ( !result )
    return result;
  v5 = CEntityEvent::CEntityEvent((CEntityEvent *)v3, 0x1Cu, 0, a2, 0, 0);
  v4 = v5;
  v8 = 0;
  (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v7 + 80))(v7, v5);
  v8 = -1;
  return CEntityEvent::~CEntityEvent(v3);
}


// address=[0x130b860]
// Decompiled from void __cdecl IAIEnvironment::EntityManakopterUnload(int a1)
void __cdecl IAIEnvironment::EntityManakopterUnload(int a1) {
  
  CManakopter *ManakopterPtr; // [esp+0h] [ebp-4h]

  ManakopterPtr = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, a1);
  if ( ManakopterPtr )
    CManakopter::UnloadSettlers(ManakopterPtr);
}


// address=[0x130b890]
// Decompiled from IFlyingEntity *__cdecl IAIEnvironment::EntityManakopterFlyTo(int a1, __int16 a2, __int16 a3)
void __cdecl IAIEnvironment::EntityManakopterFlyTo(int a1, int a2, int a3) {
  
  IFlyingEntity *result; // eax

  result = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, a1);
  if ( result )
    return (IFlyingEntity *)IFlyingEntity::FlyTo(result, a2, a3);
  return result;
}


// address=[0x130b8c0]
// Decompiled from bool __cdecl IAIEnvironment::EntityIsManakopterMoving(int a1)
bool __cdecl IAIEnvironment::EntityIsManakopterMoving(int a1) {
  
  IFlyingEntity *ManakopterPtr; // [esp+0h] [ebp-4h]

  ManakopterPtr = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, a1);
  if ( !ManakopterPtr && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 634, "pManakopter != NULL") == 1 )
    __debugbreak();
  return ManakopterPtr && IFlyingEntity::FlyingFlagBits(ManakopterPtr, 1);
}


// address=[0x130b920]
// Decompiled from int __cdecl IAIEnvironment::EntityFindNearestManakopter(int a1, int a2, int a3, bool a4)
int __cdecl IAIEnvironment::EntityFindNearestManakopter(int a1, int a2, int a3, bool a4) {
  
  int v5; // [esp+0h] [ebp-4h]

  v5 = 0;
  if ( a4 )
    v5 = 2;
  return CFlyingMgr::GetNearestEntity((CFlyingMgr *)g_cFlyingMgr, a1, 1, a2, a3, v5);
}


// address=[0x130b960]
// Decompiled from bool __cdecl IAIEnvironment::EntityIsShamanOutOfMana(int a1)
bool __cdecl IAIEnvironment::EntityIsShamanOutOfMana(int a1) {
  
  CShamanRole *v2; // [esp+0h] [ebp-8h]
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-4h]

  SettlerPtr = CSettlerMgr::GetSettlerPtr(a1);
  if ( !SettlerPtr && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 675, "pSettler != NULL") == 1 )
    __debugbreak();
  if ( !SettlerPtr || IEntity::Type((unsigned __int16 *)SettlerPtr) != 54 )
    return 0;
  v2 = (CShamanRole *)CSettler::Role(SettlerPtr);
  return CShamanRole::IsManaPoolEmpty(v2);
}


// address=[0x130b9d0]
// Decompiled from char __cdecl IAIEnvironment::EntitySendShamanWorkEvent(int a1, int a2)
bool __cdecl IAIEnvironment::EntitySendShamanWorkEvent(int a1, int a2) {
  
  _BYTE v3[24]; // [esp+4h] [ebp-34h] BYREF
  CEntityEvent *v4; // [esp+1Ch] [ebp-1Ch]
  CEntityEvent *v5; // [esp+20h] [ebp-18h]
  void **v6; // [esp+24h] [ebp-14h]
  unsigned __int16 *v7; // [esp+28h] [ebp-10h]
  int v8; // [esp+34h] [ebp-4h]

  v6 = (void **)CMapObjectMgr::EntityPtr(a1);
  v7 = (unsigned __int16 *)j____RTDynamicCast(
                             v6,
                             0,
                             &IEntity__RTTI_Type_Descriptor_,
                             &IAnimatedEntity__RTTI_Type_Descriptor_,
                             0);
  if ( !v7 || IEntity::Type(v7) != 54 )
    return 0;
  v5 = CEntityEvent::CEntityEvent((CEntityEvent *)v3, 3u, 0, a2, 0, 0);
  v4 = v5;
  v8 = 0;
  (*(void (__thiscall **)(unsigned __int16 *, CEntityEvent *))(*(_DWORD *)v7 + 80))(v7, v5);
  v8 = -1;
  CEntityEvent::~CEntityEvent(v3);
  return 1;
}


// address=[0x130ba90]
// Decompiled from int __cdecl IAIEnvironment::BuildingPackedEnsignPosition(int a1)
int __cdecl IAIEnvironment::BuildingPackedEnsignPosition(int a1) {
  
  unsigned __int8 *BuildingPtr; // [esp+0h] [ebp-4h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a1);
  if ( BuildingPtr )
    return CBuilding::EnsignPackedXY(BuildingPtr);
  else
    return -1;
}


// address=[0x130bac0]
// Decompiled from int __cdecl IAIEnvironment::BuildingGetNumberOfBuildings(int a1, int a2, unsigned int a3)
int __cdecl IAIEnvironment::BuildingGetNumberOfBuildings(int a1, int a2, int a3) {
  
  return CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, a1, a2, a3);
}


// address=[0x130bae0]
// Decompiled from int __cdecl IAIEnvironment::BuildingGetNumberOfAllyBuildings(int a1, int a2, unsigned int a3)
int __cdecl IAIEnvironment::BuildingGetNumberOfAllyBuildings(int a1, int a2, int a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]
  int *i; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = IAIEnvironment::AlliancesAllianceId(a1);
  for ( i = (int *)IAIEnvironment::AlliancesAllyPlayerIds(v4); *i; ++i )
    v5 += CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, *i, a2, a3);
  return v5;
}


// address=[0x130bb50]
// Decompiled from int __cdecl IAIEnvironment::BuildingGetNumberOfEnemyBuildings(int a1, int a2, unsigned int a3)
int __cdecl IAIEnvironment::BuildingGetNumberOfEnemyBuildings(int a1, int a2, int a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]
  int *i; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = IAIEnvironment::AlliancesAllianceId(a1);
  for ( i = (int *)IAIEnvironment::AlliancesEnemyPlayerIds(v4); *i; ++i )
    v5 += CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, *i, a2, a3);
  return v5;
}


// address=[0x130bbc0]
// Decompiled from int __cdecl IAIEnvironment::BuildingGetFirstBuildingId(int a1, int a2)
int __cdecl IAIEnvironment::BuildingGetFirstBuildingId(int a1, int a2) {
  
  return CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, a1, a2);
}


// address=[0x130bbe0]
// Decompiled from bool __cdecl IAIEnvironment::BuildingIsReadyAndInSector(int a1, int a2)
bool __cdecl IAIEnvironment::BuildingIsReadyAndInSector(int a1, int a2) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-8h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a1);
  if ( !BuildingPtr )
    return 0;
  if ( !IEntity::FlagBits(BuildingPtr, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return 0;
  v3 = CBuilding::EnsignPackedXY(BuildingPtr);
  v4 = IAIEnvironment::WorldIndexPackedXY(v3);
  return ITiling::SectorId(v4) == a2;
}


// address=[0x130bc70]
// Decompiled from char __cdecl IAIEnvironment::BuildingSearchNearestBuildingInSector(  int a1,  int a2,  int a3,  int a4,  int a5,  struct SAIBuildingSearchResult *a6)
bool __cdecl IAIEnvironment::BuildingSearchNearestBuildingInSector(int a1, int a2, int a3, int a4, int a5, struct SAIBuildingSearchResult & a6) {
  
  int v6; // eax
  int v7; // eax
  int v9; // [esp+0h] [ebp-28h]
  int v10; // [esp+4h] [ebp-24h]
  int v11; // [esp+8h] [ebp-20h]
  int v12; // [esp+Ch] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-18h]
  int v14; // [esp+14h] [ebp-14h]
  unsigned __int8 *v15; // [esp+18h] [ebp-10h]
  int v16; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  unsigned __int8 *v18; // [esp+24h] [ebp-4h]

  if ( !IAIEnvironment::AlliancesIsValidUsedPlayerId(a1)
    && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 956, "AlliancesIsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 <= 0 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 957, "_iBuildingType > 0") == 1 )
    __debugbreak();
  if ( a2 >= 83 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 958, "_iBuildingType < BUILDING_MAX") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorld(a3, a4)
    && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 959, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a5 <= 0 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 960, "_iSectorId > 0") == 1 )
    __debugbreak();
  v16 = 0;
  v14 = 0x4000;
  for ( i = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, a1, a2); i; i = IAnimatedEntity::Next(v18) )
  {
    v18 = CBuildingMgr::Building((CBuildingMgr *)g_cBuildingMgr, i);
    if ( IEntity::ObjType(v18) != 8
      && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 972, "rBuilding.ObjType() == BUILDING_OBJ") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::Type((unsigned __int16 *)v18) != a2
      && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 973, "rBuilding.Type() == _iBuildingType") == 1 )
    {
      __debugbreak();
    }
    v11 = CBuilding::EnsignWorldIdx(v18);
    v13 = ITiling::SectorId(v11);
    if ( v13 <= 0 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 978, "iEnsignSectorId > 0") == 1 )
      __debugbreak();
    if ( v13 == a5 )
    {
      v9 = IEntity::X(v18);
      v10 = IEntity::X(v18);
      v12 = Grid::Distance((Grid *)(v9 - a3), v10 - a4);
      if ( v12 < v14 )
      {
        v14 = v12;
        v16 = i;
      }
    }
  }
  if ( v16 )
  {
    v15 = CBuildingMgr::Building((CBuildingMgr *)g_cBuildingMgr, v16);
    *(_DWORD *)a6 = v16;
    *((_DWORD *)a6 + 1) = IEntity::X(v15);
    *((_DWORD *)a6 + 2) = IEntity::Y(v15);
    v6 = CBuilding::EnsignPackedXY(v15);
    *((_DWORD *)a6 + 3) = Y16X16::UnpackXFast(v6);
    v7 = CBuilding::EnsignPackedXY(v15);
    *((_DWORD *)a6 + 4) = Y16X16::UnpackYFast(v7);
    *((_DWORD *)a6 + 5) = v14;
    return 1;
  }
  else
  {
    *(_DWORD *)a6 = 0;
    return 0;
  }
}


// address=[0x130bf10]
// Decompiled from int __cdecl IAIEnvironment::BuildingHasInhabitant(int a1)
int __cdecl IAIEnvironment::BuildingHasInhabitant(int a1) {
  
  if ( CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a1) )
    return (unsigned __int8)CBuilding::HaveInhabitant() != 0;
  else
    return -1;
}


// address=[0x130bf60]
// Decompiled from int __cdecl IAIEnvironment::BuildingGetNextBuildingOfSameType(int a1)
int __cdecl IAIEnvironment::BuildingGetNextBuildingOfSameType(int a1) {
  
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-4h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a1);
  if ( BuildingPtr )
    return IAnimatedEntity::Next(BuildingPtr);
  else
    return 0;
}


// address=[0x130bfa0]
// Decompiled from int __cdecl IAIEnvironment::BuildingGetEnsignSectorId(int a1)
int __cdecl IAIEnvironment::BuildingGetEnsignSectorId(int a1) {
  
  int v1; // eax
  int v2; // eax
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-4h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a1);
  if ( !BuildingPtr )
    return 0;
  v1 = CBuilding::EnsignPackedXY(BuildingPtr);
  v2 = IAIEnvironment::WorldIndexPackedXY(v1);
  return ITiling::SectorId(v2);
}


// address=[0x130bff0]
// Decompiled from int __cdecl IAIEnvironment::VehicleGetNumberOfVehicles(int a1, int a2, int a3)
int __cdecl IAIEnvironment::VehicleGetNumberOfVehicles(int a1, int a2, int a3) {
  
  return CVehicleMgr::GetNumberOfVehicles((CVehicleMgr *)&g_cVehicleMgr, a1, a2, a3);
}


// address=[0x130c010]
// Decompiled from int __cdecl IAIEnvironment::VehicleGetNumberOfAllyVehicles(int a1, int a2, int a3)
int __cdecl IAIEnvironment::VehicleGetNumberOfAllyVehicles(int a1, int a2, int a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]
  const int *i; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = IAIEnvironment::AlliancesAllianceId(a1);
  for ( i = IAIEnvironment::AlliancesAllyPlayerIds(v4); *i; ++i )
    v5 += CVehicleMgr::GetNumberOfVehicles((CVehicleMgr *)&g_cVehicleMgr, *i, a2, a3);
  return v5;
}


// address=[0x130c080]
// Decompiled from int __cdecl IAIEnvironment::VehicleGetNumberOfEnemyVehicles(int a1, int a2, int a3)
int __cdecl IAIEnvironment::VehicleGetNumberOfEnemyVehicles(int a1, int a2, int a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]
  int *i; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = IAIEnvironment::AlliancesAllianceId(a1);
  for ( i = (int *)IAIEnvironment::AlliancesEnemyPlayerIds(v4); *i; ++i )
    v5 += IAIEnvironment::VehicleGetNumberOfVehicles(*i, a2, a3);
  return v5;
}


// address=[0x130c0f0]
// Decompiled from int __cdecl IAIEnvironment::VehicleGetFirstReadyAndCheckedOutVehicleId(int a1, int a2)
int __cdecl IAIEnvironment::VehicleGetFirstReadyAndCheckedOutVehicleId(int a1, int a2) {
  
  _DWORD *v3; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  for ( i = CVehicleMgr::GetFirstVehicleId(a1, a2); i > 0; i = IAnimatedEntity::Next(v3) )
  {
    v3 = (_DWORD *)CVehicleMgr::operator[](i);
    if ( (_UNKNOWN *)IEntity::FlagBits(v3, Ready|OnBoard) == &loc_1C00000 )
      return i;
  }
  return 0;
}


// address=[0x130c150]
// Decompiled from int __cdecl IAIEnvironment::VehicleGetNextReadyAndCheckedOutVehicleId(int a1)
int __cdecl IAIEnvironment::VehicleGetNextReadyAndCheckedOutVehicleId(int a1) {
  
  int v2; // [esp+0h] [ebp-Ch]
  _DWORD *v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( !a1 )
    return 0;
  v2 = CVehicleMgr::operator[](a1);
  for ( i = IAnimatedEntity::Next(v2); i > 0; i = IAnimatedEntity::Next(v3) )
  {
    v3 = (_DWORD *)CVehicleMgr::operator[](i);
    if ( (_UNKNOWN *)IEntity::FlagBits(v3, (EntityFlag)&loc_2008000) == (_UNKNOWN *)((char *)&loc_1FFFFFF + 1) )
      return i;
  }
  return 0;
}


// address=[0x130c1d0]
// Decompiled from struct CVehicle *__cdecl IAIEnvironment::VehicleSendQueuedVanishCommand(int a1)
void __cdecl IAIEnvironment::VehicleSendQueuedVanishCommand(int a1) {
  
  struct CVehicle *result; // eax
  _BYTE v2[24]; // [esp+4h] [ebp-30h] BYREF
  CEntityEvent *v3; // [esp+1Ch] [ebp-18h]
  CEntityEvent *v4; // [esp+20h] [ebp-14h]
  struct CVehicle *v5; // [esp+24h] [ebp-10h]
  int v6; // [esp+30h] [ebp-4h]

  result = CVehicleMgr::GetVehiclePtr(a1);
  v5 = result;
  if ( !result )
    return result;
  v4 = CEntityEvent::CEntityEvent((CEntityEvent *)v2, 0x11u, 13, 18, 0, 0);
  v3 = v4;
  v6 = 0;
  (*(void (__thiscall **)(struct CVehicle *, CEntityEvent *))(*(_DWORD *)v5 + 80))(v5, v4);
  v6 = -1;
  return (struct CVehicle *)CEntityEvent::~CEntityEvent(v2);
}


// address=[0x130c260]
// Decompiled from int __cdecl IAIEnvironment::SettlerGetNumberOfSettlers(int a1, int a2)
int __cdecl IAIEnvironment::SettlerGetNumberOfSettlers(int a1, int a2) {
  
  return CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, a2);
}


// address=[0x130c280]
// Decompiled from int __cdecl IAIEnvironment::SettlerGetFirstReadyAndCheckedOutSettlerId(int a1, int a2)
int __cdecl IAIEnvironment::SettlerGetFirstReadyAndCheckedOutSettlerId(int a1, int a2) {
  
  _DWORD *v3; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  for ( i = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, a1, a2); i > 0; i = IAnimatedEntity::Next(v3) )
  {
    v3 = (_DWORD *)CSettlerMgr::operator[](i);
    if ( (_UNKNOWN *)IEntity::FlagBits(v3, (EntityFlag)&loc_2008000) == (_UNKNOWN *)((char *)&loc_1FFFFFF + 1) )
      return i;
  }
  return 0;
}


// address=[0x130c2e0]
// Decompiled from int __cdecl IAIEnvironment::SettlerGetNextReadyAndCheckedOutSettlerId(int a1)
int __cdecl IAIEnvironment::SettlerGetNextReadyAndCheckedOutSettlerId(int a1) {
  
  int v2; // [esp+0h] [ebp-Ch]
  _DWORD *v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( !a1 )
    return 0;
  v2 = CSettlerMgr::operator[](a1);
  for ( i = IAnimatedEntity::Next(v2); i > 0; i = IAnimatedEntity::Next(v3) )
  {
    v3 = (_DWORD *)CSettlerMgr::operator[](i);
    if ( (_UNKNOWN *)IEntity::FlagBits(v3, (EntityFlag)&loc_2008000) == (_UNKNOWN *)((char *)&loc_1FFFFFF + 1) )
      return i;
  }
  return 0;
}


// address=[0x130c360]
// Decompiled from int __cdecl IAIEnvironment::MagicCurrentManaAmount(int a1)
int __cdecl IAIEnvironment::MagicCurrentManaAmount(int a1) {
  
  return CMagic::GetCurrentManaAmount(a1);
}


// address=[0x130c380]
// Decompiled from void __cdecl IAIEnvironment::MagicIncreaseMana(int a1, int a2)
void __cdecl IAIEnvironment::MagicIncreaseMana(int a1, int a2) {
  
  CMagic::IncreaseMana(a1, a2);
}


// address=[0x130c3a0]
// Decompiled from void __cdecl IAIEnvironment::MagicDecreaseMana(int a1, int a2)
void __cdecl IAIEnvironment::MagicDecreaseMana(int a1, int a2) {
  
  CMagic::DecreaseMana(a1, a2);
}


// address=[0x130c3c0]
// Decompiled from int __cdecl IAIEnvironment::PlayerRace(int a1)
int __cdecl IAIEnvironment::PlayerRace(int a1) {
  
  return CPlayerManager::Race(a1);
}


// address=[0x130c3e0]
// Decompiled from bool __cdecl IAIEnvironment::EcoSectorCheckId(int a1)
bool __cdecl IAIEnvironment::EcoSectorCheckId(int a1) {
  
  return CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, a1) != 0;
}


// address=[0x130c410]
// Decompiled from bool __cdecl IAIEnvironment::EcoSectorCheckId(int a1, int a2)
bool __cdecl IAIEnvironment::EcoSectorCheckId(int a1, int a2) {
  
  return CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, a1, a2) != 0;
}


// address=[0x130c450]
// Decompiled from int __cdecl IAIEnvironment::EcoSectorGetUniqueId(int a1)
int __cdecl IAIEnvironment::EcoSectorGetUniqueId(int a1) {
  
  struct CEcoSector *EcoSectorPtr; // [esp+4h] [ebp-4h]

  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, a1);
  if ( EcoSectorPtr )
    return CEcoSector::GetUniqueId(EcoSectorPtr);
  else
    return 0;
}


// address=[0x130c490]
// Decompiled from int __cdecl IAIEnvironment::EcoSectorOwnerId(int a1)
int __cdecl IAIEnvironment::EcoSectorOwnerId(int a1) {
  
  struct CEcoSector *EcoSectorPtr; // [esp+4h] [ebp-4h]

  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, a1);
  if ( EcoSectorPtr )
    return CEcoSector::Owner(EcoSectorPtr);
  else
    return 0;
}


// address=[0x130c4d0]
// Decompiled from int __cdecl IAIEnvironment::EcoSectorNumberOfPossibleCarriers(int a1)
int __cdecl IAIEnvironment::EcoSectorNumberOfPossibleCarriers(int a1) {
  
  CEcoSector *EcoSectorPtr; // [esp+4h] [ebp-4h]

  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, a1);
  if ( EcoSectorPtr )
    return CEcoSector::NrOfSettler(EcoSectorPtr, 1);
  else
    return 0;
}


// address=[0x130c510]
// Decompiled from char __cdecl IAIEnvironment::EcoSectorGetPosition(int a1, int *a2, int *a3)
bool __cdecl IAIEnvironment::EcoSectorGetPosition(int a1, int & a2, int & a3) {
  
  int v3; // ecx
  int v5; // [esp+0h] [ebp-4h]
  int v6; // [esp+0h] [ebp-4h]

  v5 = (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 44))(g_pTiling, a1, v3);
  if ( v5 <= 0 )
  {
    *a2 = 0;
    *a3 = 0;
    return 0;
  }
  else
  {
    *a2 = IAIEnvironment::UnpackXFast(v5);
    *a3 = IAIEnvironment::UnpackYFast(v6);
    return 1;
  }
}


// address=[0x130c580]
// Decompiled from int __cdecl IAIEnvironment::EcoSectorGetSectorId(int a1)
int __cdecl IAIEnvironment::EcoSectorGetSectorId(int a1) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF
  int v3; // [esp+4h] [ebp-4h] BYREF

  v2 = 0;
  v3 = 0;
  if ( IAIEnvironment::EcoSectorGetPosition(a1, &v2, &v3) )
    return CWorldManager::SectorId(v2, v3);
  else
    return 0;
}


// address=[0x130c5d0]
// Decompiled from int __cdecl IAIEnvironment::EcoSectorGetNextEcoSectorInSector(int a1, int a2)
int __cdecl IAIEnvironment::EcoSectorGetNextEcoSectorInSector(int a1, int a2) {
  
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  int UsedEcoSectorId; // [esp+10h] [ebp-Ch]
  int v6; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  UsedEcoSectorId = CEcoSectorMgr::LastUsedEcoSectorId((CEcoSectorMgr *)g_cESMgr);
  if ( !a2 || a2 >= UsedEcoSectorId )
    return 0;
  if ( a2 <= 0 )
    v6 = 1;
  else
    v6 = a2 + 1;
  for ( i = v6; i <= UsedEcoSectorId; ++i )
  {
    if ( CEcoSectorMgr::GetEcoSectorPtrEx((CEcoSectorMgr *)g_cESMgr, i) )
    {
      v4 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)g_pTiling + 44))(g_pTiling, i);
      v3 = IAIEnvironment::WorldIndexPackedXY(v4);
      if ( ITiling::SectorId(v3) == a1 )
        return i;
    }
  }
  return 0;
}


// address=[0x130c690]
// Decompiled from bool __cdecl IAIEnvironment::EventSendDarkTribeProductionMsg(int a1, int a2, int a3, int a4)
void __cdecl IAIEnvironment::EventSendDarkTribeProductionMsg(int a1, int a2, int a3, int a4) {
  
  if ( a4 < 0 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1710, "_iAmount >= 0") == 1 )
    __debugbreak();
  if ( a4 > 99 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1711, "_iAmount <= 99") == 1 )
    __debugbreak();
  return INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, 0x13B7u, a3 | (a2 << 16), a4 + 10000, a1);
}


// address=[0x130c720]
// Decompiled from bool __cdecl IAIEnvironment::EventSendSettlerProductionMsg(int a1, int a2, int a3, signed int a4)
void __cdecl IAIEnvironment::EventSendSettlerProductionMsg(int a1, int a2, int a3, int a4) {
  
  bool result; // al

  if ( a3 == -1 )
    a3 = 67;
  result = INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, 0x13B7u, a3 | (a2 << 16), 0, a1);
  if ( a4 > 0 )
    return INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, 0x13B7u, a3 | (a2 << 16), a4, a1);
  return result;
}


// address=[0x130c780]
// Decompiled from int __cdecl IAIEnvironment::GetNearestGreenBorderElement(int *a1, int *a2, int a3)
int __cdecl IAIEnvironment::GetNearestGreenBorderElement(int & a1, int & a2, int a3) {
  
  int v4; // eax
  int v5; // [esp+4h] [ebp-54h]
  int v6; // [esp+8h] [ebp-50h]
  __int64 v7; // [esp+Ch] [ebp-4Ch]
  int v8; // [esp+14h] [ebp-44h]
  __int64 v9; // [esp+18h] [ebp-40h]
  int v10; // [esp+20h] [ebp-38h]
  int v11; // [esp+24h] [ebp-34h]
  int v12; // [esp+28h] [ebp-30h]
  int v13; // [esp+2Ch] [ebp-2Ch]
  int v14; // [esp+30h] [ebp-28h]
  int v15; // [esp+34h] [ebp-24h]
  int v16; // [esp+38h] [ebp-20h]
  int v17; // [esp+3Ch] [ebp-1Ch]
  int v18; // [esp+40h] [ebp-18h]
  int v19; // [esp+44h] [ebp-14h]
  int j; // [esp+48h] [ebp-10h]
  int v21; // [esp+4Ch] [ebp-Ch]
  int v22; // [esp+50h] [ebp-8h]
  int i; // [esp+54h] [ebp-4h]

  if ( a3 <= 0 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1507, "_iSearchRadius > 0") == 1 )
    __debugbreak();
  if ( a3 >= 75 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1508, "_iSearchRadius < SPIRAL_RADIUS_MAX") == 1 )
    __debugbreak();
  v22 = *a1;
  v21 = *a2;
  if ( !(unsigned __int8)CWorldManager::InWorld(*a1, *a2) )
    return 0;
  v17 = CWorldManager::SectorId(v22, v21);
  if ( v17 <= 0 )
    return 0;
  v14 = CSpiralOffsets::Last(a3);
  for ( i = 0; i <= v14; ++i )
  {
    v11 = v22 + CSpiralOffsets::DeltaX(i);
    v12 = v21 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v11, v12) )
    {
      v18 = CWorldManager::Index(v11, v12);
      if ( !CWorldManager::FlagBits(v18, 0x25u) )
      {
        v10 = CWorldManager::Ground(v18) & 0xF0;
        HIDWORD(v9) = v10 == 32;
        LODWORD(v9) = v10 == 48;
        if ( !v9 && ITiling::SectorId(v18) == v17 )
          break;
      }
    }
  }
  v13 = i;
  while ( i <= v14 )
  {
    v16 = v22 + CSpiralOffsets::DeltaX(i);
    v15 = v21 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v16, v15) )
    {
      v19 = CWorldManager::Index(v16, v15);
      if ( !CWorldManager::FlagBits(v19, 0x25u) )
      {
        v8 = CWorldManager::Ground(v19) & 0xF0;
        HIDWORD(v7) = v8 == 32;
        LODWORD(v7) = v8 == 48;
        if ( !v7 && ITiling::SectorId(v19) == v17 )
        {
          for ( j = 0; j < 6; ++j )
          {
            v6 = v19 + CWorldManager::NeighborRelIndex(j);
            if ( CWorldManager::FlagBits(v6, 4u) )
            {
              *a1 = v16;
              *a2 = v15;
              return 1;
            }
          }
        }
      }
    }
    ++i;
  }
  if ( v13 > v14 )
    return 0;
  v5 = v22 + CSpiralOffsets::DeltaX(v13);
  v4 = CSpiralOffsets::DeltaY(v13);
  *a1 = v5;
  *a2 = v21 + v4;
  return -1;
}


// address=[0x130cab0]
// Decompiled from int __cdecl IAIEnvironment::GetNearestNoneBlockedPosition(Grid **a1, int *a2)
int __cdecl IAIEnvironment::GetNearestNoneBlockedPosition(int & a1, int & a2) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-18h]
  int v4; // [esp+8h] [ebp-14h]
  Grid *v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+10h] [ebp-Ch]
  Grid *v7; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v5 = *a1;
  v4 = *a2;
  for ( i = 0; i < 19825; ++i )
  {
    v7 = (Grid *)((char *)v5 + CSpiralOffsets::DeltaX(i));
    v6 = v4 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld((int)v7, v6) )
    {
      v3 = CWorldManager::Index((int)v7, v6);
      if ( !(unsigned __int8)CWorldManager::IsBlockedLand(v3) )
      {
        result = Grid::Distance(v7, v6, *a1, *a2);
        *a1 = v7;
        *a2 = v6;
        return result;
      }
    }
  }
  return -1;
}


// address=[0x130cb90]
// Decompiled from char __cdecl IAIEnvironment::FindNearestSectorPosition(int *a1, int *a2, int a3, int a4)
bool __cdecl IAIEnvironment::FindNearestSectorPosition(int & a1, int & a2, int a3, int a4) {
  
  _DWORD v5[4]; // [esp+0h] [ebp-20h] BYREF
  int v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+14h] [ebp-Ch]
  int v8; // [esp+18h] [ebp-8h] BYREF
  int v9; // [esp+1Ch] [ebp-4h] BYREF

  if ( a3 <= 0 )
    return 0;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v5, *a1, *a2, a4);
  while ( CSpiralWalk::NextXY(v5, &v8, &v9) )
  {
    v7 = CWorldManager::Index(v8, v9);
    v6 = ITiling::SectorId(v7);
    if ( v6 == a3 )
      return 1;
  }
  return 0;
}


// address=[0x130cc10]
// Decompiled from int __cdecl IAIEnvironment::FindNearestCatapultSectorPosition(int a1, int a2, int a3, int a4)
int __cdecl IAIEnvironment::FindNearestCatapultSectorPosition(int a1, int a2, int a3, int a4) {
  
  _DWORD v5[4]; // [esp+0h] [ebp-20h] BYREF
  int v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+14h] [ebp-Ch]
  int v8; // [esp+18h] [ebp-8h] BYREF
  int v9; // [esp+1Ch] [ebp-4h] BYREF

  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v5, a2, a3, a4);
  while ( CSpiralWalk::NextXY(v5, &v8, &v9) )
  {
    v7 = CWorldManager::Index(v8, v9);
    v6 = ITiling::CatapultSectorId(v7);
    if ( v6 == a1 )
      return Y16X16::PackXYFast(v8, v9);
  }
  return -1;
}


// address=[0x130cc90]
// Decompiled from int __cdecl IAIEnvironment::CalculateRoughlyDistanceToEnemyPosition(int a1, int a2, int a3)
int __cdecl IAIEnvironment::CalculateRoughlyDistanceToEnemyPosition(int a1, int a2, int a3) {
  
  int v4; // [esp+4h] [ebp-64h]
  int v5; // [esp+8h] [ebp-60h]
  _BYTE v6[88]; // [esp+Ch] [ebp-5Ch] BYREF

  if ( a1 <= 0 && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1624, "_iPlayerId > 0") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1625, "g_cWorld.InWorldPackedXY(_iStartXY)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a3)
    && BBSupportDbgReport(2, "AI\\AI_Environment.cpp", 1626, "g_cWorld.InWorldPackedXY(_iEnemyXY)") == 1 )
  {
    __debugbreak();
  }
  v4 = 0;
  if ( !CAStarTiling::FindPath(a3, a2, (struct CWaypoints *)v6, a1 | 0x2C000600) )
    return v4;
  v5 = CWaypoints::GoalDistance((CWaypoints *)v6);
  if ( v5 > 0 )
    return v5;
  return v4;
}


// address=[0x130cd90]
// Decompiled from struct SAIEvalOwnerResults *__cdecl IAIEnvironment::EvaluateOwnerMap(  int a1,  Squares *a2,  Squares *a3,  struct SAIEvalOwnerResults *a4)
void __cdecl IAIEnvironment::EvaluateOwnerMap(int a1, int a2, int a3, struct SAIEvalOwnerResults & a4) {
  
  bool valid; // si
  bool v5; // si
  struct SAIEvalOwnerResults *result; // eax
  int v7; // [esp+0h] [ebp-60h]
  int v8; // [esp+0h] [ebp-60h]
  int v9; // [esp+0h] [ebp-60h]
  int v10; // [esp+8h] [ebp-58h]
  Squares *v11; // [esp+10h] [ebp-50h]
  Squares *v12; // [esp+14h] [ebp-4Ch]
  int v13; // [esp+1Ch] [ebp-44h]
  Squares *v14; // [esp+24h] [ebp-3Ch]
  Squares *v15; // [esp+28h] [ebp-38h]
  int v16; // [esp+30h] [ebp-30h]
  int v17; // [esp+38h] [ebp-28h]
  int v18; // [esp+3Ch] [ebp-24h]
  int v19; // [esp+40h] [ebp-20h]
  int v20; // [esp+44h] [ebp-1Ch]
  int v21; // [esp+48h] [ebp-18h]
  int v22; // [esp+4Ch] [ebp-14h]
  int v23; // [esp+50h] [ebp-10h]
  int v24; // [esp+54h] [ebp-Ch]
  int j; // [esp+58h] [ebp-8h]
  int i; // [esp+5Ch] [ebp-4h]

  v22 = Squares::XYToVW(a2);
  v21 = Squares::XYToVW(a3);
  v20 = IAIEnvironment::AlliancesPlayerBit(a1);
  v19 = IAIEnvironment::AlliancesPlayerEnemyBits(a1);
  v16 = COwnerMap::OwnerBits1VW(v22, v21);
  *(_DWORD *)a4 = (v20 & v16) != 0;
  *((_DWORD *)a4 + 4) = (v19 & v16) != 0;
  v24 = 0;
  v23 = 0;
  for ( i = 0; i <= 7; ++i )
  {
    v14 = (Squares *)(dword_36706E8[2 * i] + v22);
    v15 = (Squares *)(dword_36706EC[2 * i] + v21);
    valid = Squares::ValidVW(v14, v7);
    if ( Squares::ValidVW(v15, v8) && valid )
    {
      v13 = COwnerMap::OwnerBits1VW(v14, v15);
      v24 += (v20 & v13) != 0;
      v23 += (v19 & v13) != 0;
    }
  }
  *((_DWORD *)a4 + 1) = v24;
  *((_DWORD *)a4 + 5) = v23;
  v18 = 0;
  v17 = 0;
  for ( j = 8; j <= 23; ++j )
  {
    v11 = (Squares *)(dword_36706E8[2 * j] + v22);
    v12 = (Squares *)(dword_36706EC[2 * j] + v21);
    v5 = Squares::ValidVW(v11, v7);
    if ( Squares::ValidVW(v12, v9) && v5 )
    {
      v10 = COwnerMap::OwnerBits1VW(v11, v12);
      v18 += (v20 & v10) != 0;
      v17 += (v19 & v10) != 0;
    }
  }
  *((_DWORD *)a4 + 2) = v18;
  *((_DWORD *)a4 + 6) = v17;
  *((_DWORD *)a4 + 3) = *((_DWORD *)a4 + 2) + (*(_DWORD *)a4 << 6) + 4 * *((_DWORD *)a4 + 1);
  result = a4;
  *((_DWORD *)a4 + 7) = *((_DWORD *)a4 + 6) + (*((_DWORD *)a4 + 4) << 6) + 4 * *((_DWORD *)a4 + 5);
  return result;
}


// address=[0x130d090]
// Decompiled from _DWORD *__cdecl IAIEnvironment::EvaluateInfluenceMap(int a1, Squares *a2, Squares *a3, _DWORD *a4)
void __cdecl IAIEnvironment::EvaluateInfluenceMap(int a1, int a2, int a3, struct SAIEvalInfluResults & a4) {
  
  bool valid; // si
  _DWORD *result; // eax
  int v6; // [esp+4h] [ebp-24h]
  int v7; // [esp+8h] [ebp-20h]
  int v8; // [esp+Ch] [ebp-1Ch]
  int v9; // [esp+10h] [ebp-18h]
  int v10; // [esp+14h] [ebp-14h]
  int v11; // [esp+18h] [ebp-10h]
  int v12; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int j; // [esp+24h] [ebp-4h]

  v7 = Squares::XYToVW(a2);
  v6 = Squares::XYToVW(a3);
  v8 = IAIEnvironment::AlliancesAllianceId(a1);
  v10 = 0;
  v9 = 0;
  for ( i = -2; i <= 2; ++i )
  {
    for ( j = -2; j <= 2; ++j )
    {
      v11 = j + v7;
      v12 = i + v6;
      valid = Squares::ValidVW((Squares *)(j + v7));
      if ( Squares::ValidVW((Squares *)(i + v6)) && valid )
      {
        v10 += CInfluMap::AllyValueVW(v11, v12, v8);
        v9 += CInfluMap::EnemyValueVW(v11, v12, v8);
      }
    }
  }
  *a4 = v10;
  result = a4;
  a4[1] = v9;
  return result;
}


// address=[0x130d190]
// Decompiled from void IAIEnvironment::DbgTracePrintF(char *Format, ...)
void __cdecl IAIEnvironment::DbgTracePrintF(char const * Format, ... a2) {
  
  char Source[2048]; // [esp+4h] [ebp-804h] BYREF
  va_list va; // [esp+814h] [ebp+Ch] BYREF

  va_start(va, Format);
  __vcrt_va_start_verify_argument_type<char const *>();
  j___vsnprintf(Source, 0x7FFu, Format, va);
  BBSupportTracePrint(190, Source);
}


// address=[0x130d200]
// Decompiled from void IAIEnvironment::DbgEnableAITrace()
void __cdecl IAIEnvironment::DbgEnableAITrace(void) {
  
  BBSupportEnableTraceLevel(0xBEu);
}


// address=[0x130d210]
// Decompiled from void IAIEnvironment::DbgEnableAITraceEx()
void __cdecl IAIEnvironment::DbgEnableAITraceEx(void) {
  
  if ( BBSupportDevelopmentMachineId() == 1 )
    BBSupportEnableTraceLevel(0xBEu);
  else
    BBSupportDisableTraceLevel(0xBEu);
}


// address=[0x130d240]
// Decompiled from void IAIEnvironment::DbgDisableAITrace()
void __cdecl IAIEnvironment::DbgDisableAITrace(void) {
  
  BBSupportDisableTraceLevel(0xBEu);
}


// address=[0x130e8c0]
// Decompiled from const int *__cdecl IAIEnvironment::AlliancesAllyPlayerIds(int a1)
int const * __cdecl IAIEnvironment::AlliancesAllyPlayerIds(int a1) {
  
  return CAlliances::AllyPlayerIds(a1);
}


// address=[0x1314090]
// Decompiled from void __cdecl IAIEnvironment::SetGlobalEcoAIFlags(struct CFrameWnd *a1)
void __cdecl IAIEnvironment::SetGlobalEcoAIFlags(int a1) {
  
  IAIEnvironment::m_iGlobalEcoAIFlags = (int)a1;
}


// address=[0x13172e0]
// Decompiled from int IAIEnvironment::AlliancesAllPlayersBits()
int __cdecl IAIEnvironment::AlliancesAllPlayersBits(void) {
  
  return CAlliances::AllPlayersBits();
}


// address=[0x13172f0]
// Decompiled from int IAIEnvironment::AlliancesLastAllianceId()
int __cdecl IAIEnvironment::AlliancesLastAllianceId(void) {
  
  return CAlliances::LastAllianceId();
}


// address=[0x1321d20]
// Decompiled from int __cdecl IAIEnvironment::WorldOwnerId(struct _Cnd_internal_imp_t *a1, struct _Mtx_internal_imp_t *a2)
int __cdecl IAIEnvironment::WorldOwnerId(int a1, int a2) {
  
  int v2; // eax

  v2 = IAIEnvironment::WorldIndex((int)a1, (int)a2);
  return IAIEnvironment::WorldOwnerId(v2);
}


// address=[0x1326130]
// Decompiled from void __cdecl IAIEnvironment::EcoSectorGetFirstEcoSectorInSector(void *a1)
int __cdecl IAIEnvironment::EcoSectorGetFirstEcoSectorInSector(int a1) {
  
  IAIEnvironment::EcoSectorGetNextEcoSectorInSector((int)a1, -1);
}


// address=[0x132edc0]
// Decompiled from int __cdecl IAIEnvironment::WorldCatapultSectorId(struct _Cnd_internal_imp_t *a1, struct _Mtx_internal_imp_t *a2)
int __cdecl IAIEnvironment::WorldCatapultSectorId(int a1, int a2) {
  
  int v2; // eax

  v2 = IAIEnvironment::WorldIndex((int)a1, (int)a2);
  return IAIEnvironment::WorldCatapultSectorId(v2);
}


// address=[0x132edf0]
// Decompiled from void __cdecl IAIEnvironment::WorldCatapultSectorIdPackedXY(struct _iobuf *a1)
int __cdecl IAIEnvironment::WorldCatapultSectorIdPackedXY(int a1) {
  
  int v1; // eax

  v1 = IAIEnvironment::WorldIndexPackedXY(a1);
  IAIEnvironment::WorldCatapultSectorId(v1);
}


// address=[0x132ee10]
// Decompiled from bool __cdecl IAIEnvironment::WorldIsBlockedLand(struct _Cnd_internal_imp_t *a1, struct _Mtx_internal_imp_t *a2)
bool __cdecl IAIEnvironment::WorldIsBlockedLand(int a1, int a2) {
  
  int v2; // eax

  v2 = IAIEnvironment::WorldIndex((int)a1, (int)a2);
  return IAIEnvironment::WorldIsBlockedLand(v2);
}


// address=[0x132ee40]
// Decompiled from void __cdecl IAIEnvironment::WorldIsBlockedLandPackedXY(struct _iobuf *a1)
bool __cdecl IAIEnvironment::WorldIsBlockedLandPackedXY(int a1) {
  
  int v1; // eax

  v1 = IAIEnvironment::WorldIndexPackedXY(a1);
  IAIEnvironment::WorldIsBlockedLand(v1);
}


// address=[0x132ee60]
// Decompiled from void __cdecl IAIEnvironment::WorldOwnerIdPackedXY(struct _iobuf *a1)
int __cdecl IAIEnvironment::WorldOwnerIdPackedXY(int a1) {
  
  int v1; // eax

  v1 = IAIEnvironment::WorldIndexPackedXY(a1);
  IAIEnvironment::WorldOwnerId(v1);
}


// address=[0x130d250]
// Decompiled from int IAIEnvironment::Init()
void __cdecl IAIEnvironment::Init(void) {
  
  int v0; // ecx
  int result; // eax

  IAIEnvironment::m_pRandom = (int)CStateGame::Random16((CStateGame *)g_pGame);
  IAIEnvironment::m_uTickCounter = 0;
  result = CWorldManager::Width(v0);
  IAIEnvironment::m_iWorldWidthHeigth = result;
  IAIEnvironment::m_iGlobalEcoAIFlags = 0;
  return result;
}


// address=[0x130d340]
// Decompiled from void IAIEnvironment::Done()
void __cdecl IAIEnvironment::Done(void) {
  
  IAIEnvironment::m_pRandom = 0;
  IAIEnvironment::m_uTickCounter = 0;
  IAIEnvironment::m_iWorldWidthHeigth = 0;
}


// address=[0x130d370]
// Decompiled from int IAIEnvironment::UpdateTickCounter()
void __cdecl IAIEnvironment::UpdateTickCounter(void) {
  
  int result; // eax

  result = CStateGame::GetTickCounter(g_pGame);
  IAIEnvironment::m_uTickCounter = result;
  return result;
}


// address=[0x3e95184]
// [Decompilation failed for static class CRandom16 * IAIEnvironment::m_pRandom]

// address=[0x3e95188]
// [Decompilation failed for static unsigned int IAIEnvironment::m_uTickCounter]

// address=[0x3e9518c]
// [Decompilation failed for static int IAIEnvironment::m_iWorldWidthHeigth]

// address=[0x3e95190]
// [Decompilation failed for static int IAIEnvironment::m_iGlobalEcoAIFlags]

