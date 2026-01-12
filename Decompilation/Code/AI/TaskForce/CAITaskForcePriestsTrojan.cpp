#include "CAITaskForcePriestsTrojan.h"

// Definitions for class CAITaskForcePriestsTrojan

// address=[0x132be00]
// Decompiled from int __thiscall CAITaskForcePriestsTrojan::ChooseMilitarySpell(  CAITaskForcePriestsTrojan *this,  const struct SCountFightersResult *a2,  int a3)
int  CAITaskForcePriestsTrojan::ChooseMilitarySpell(struct SCountFightersResult const &,int) {
  
  unsigned int v4; // esi
  unsigned int v5; // esi
  int v6; // eax
  int v7; // [esp-14h] [ebp-28h]
  int v8; // [esp-8h] [ebp-1Ch]
  int v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  v10 = *((_DWORD *)a2 + 5);
  if ( v10 <= 0 )
    return -1;
  if ( v10 < 5 )
  {
    v4 = IAIEnvironment::Rand();
    if ( v4 >= v10 * CRandom16::PercentValue(0x14u) )
      return -1;
  }
  v9 = *((_DWORD *)a2 + 5) - *((_DWORD *)a2 + 4);
  if ( v9 < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2121, "iEnemyNonBowmen >= 0") == 1 )
    __debugbreak();
  if ( !v9 )
    a3 &= ~0x10u;
  if ( v10 < 10 )
  {
    v5 = IAIEnvironment::Rand();
    if ( v5 >= CRandom16::PercentValue(0x14u) * (v10 - 5) )
      a3 &= ~0x40u;
  }
  if ( (a3 & 0x70) == 0 )
    return -1;
  v8 = CStaticConfigVarInt::operator int(&unk_3ECD050);
  v7 = CStaticConfigVarInt::operator int(&unk_3ECD044);
  v6 = CStaticConfigVarInt::operator int(&unk_3ECD038);
  return sub_132D6A0(4, v6, 6, v7, 5, 0, v8, a3);
}


// address=[0x132bf10]
// Decompiled from int __thiscall CAITaskForcePriestsTrojan::ChooseMilitarySpellDestination(  CAITaskForcePriestsTrojan *this,  int a2,  int a3,  int a4,  int a5)
int  CAITaskForcePriestsTrojan::ChooseMilitarySpellDestination(int,int,int,int) {
  
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // [esp-4h] [ebp-14h]
  struct IEntity *v10; // [esp+4h] [ebp-Ch]
  int NearestOwnTowerInSector; // [esp+8h] [ebp-8h]

  switch ( a2 )
  {
    case 4:
      v5 = CAITaskForce::OwnerId(this);
      NearestOwnTowerInSector = CScanner::FindNearestOwnTowerInSector(a3, a4, 20, v5);
      if ( NearestOwnTowerInSector )
      {
        v10 = CMapObjectMgr::Entity(NearestOwnTowerInSector);
        v9 = IEntity::Y(v10);
        v6 = IEntity::X(v10);
        return Y16X16::PackXYFast(v6, v9);
      }
      else
      {
        return -1;
      }
    case 5:
      return -1;
    case 6:
      v7 = CAITaskForce::OwnerId(this);
      return CScanner::FindNearestEnemyFighter(a3, a4, 20, v7);
    default:
      return -1;
  }
}


// address=[0x132e560]
// Decompiled from _DWORD *__thiscall CAITaskForcePriestsTrojan::CAITaskForcePriestsTrojan(_DWORD *this, int a2, int a3, int a4)
 CAITaskForcePriestsTrojan::CAITaskForcePriestsTrojan(int,enum T_AI_TASK_FORCE_TYPE,int) {
  
  CAITaskForcePriests::CAITaskForcePriests(this, a2, a3, a4);
  *this = CAITaskForcePriestsTrojan::_vftable_;
  return this;
}


// address=[0x132e670]
// Decompiled from void __thiscall CAITaskForcePriestsTrojan::~CAITaskForcePriestsTrojan(CAITaskForcePriestsTrojan *this)
 CAITaskForcePriestsTrojan::~CAITaskForcePriestsTrojan(void) {
  
  CAITaskForcePriests::~CAITaskForcePriests(this);
}


