#include "CAITaskForcePriestsTrojan.h"

#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"
#include "Logic/CRandom16.h"
#include "MapObjects/CMapObjectMgr.h"
#include "Pathing/CScanner.h"
#include "World/helper.h"

// Definitions for class CAITaskForcePriestsTrojan

// address=[0x132be00]
// Decompiled from int __thiscall CAITaskForcePriestsTrojan::ChooseMilitarySpell(  CAITaskForcePriestsTrojan *this,  const struct SCountFightersResult *a2,  int a3)
int CAITaskForcePriestsTrojan::ChooseMilitarySpell(struct SCountFightersResult const &a2, int a3) {
  // esi
  // esi
  // eax
  // [esp-14h] [ebp-28h]
  // [esp-8h] [ebp-1Ch]
  // [esp+Ch] [ebp-8h]
  // [esp+10h] [ebp-4h]

  int m_uEnemySoldiers = a2.m_uEnemySoldiers;
  if(m_uEnemySoldiers <= 0)
    return -1;
  if(m_uEnemySoldiers < 5) {
    unsigned int v4 = IAIEnvironment::Rand();
    if(v4 >= m_uEnemySoldiers * CRandom16::PercentValue(0x14u))
      return -1;
  }
  int iEnemyNonBowmen = a2.m_uEnemySoldiers - a2.m_uEnemyBowmen;
  BB_ASSERT(iEnemyNonBowmen >= 0);
  if(!iEnemyNonBowmen)
    a3 &= ~0x10u;
  if(m_uEnemySoldiers < 10) {
    unsigned int v5 = IAIEnvironment::Rand();
    if(v5 >= CRandom16::PercentValue(0x14u) * (m_uEnemySoldiers - 5))
      a3 &= ~0x40u;
  }
  if((a3 & 0x70) == 0)
    return -1;
  int v8 = s_cAIConfigTrojanMilitarySpellChanceNone;
  int v7 = s_cAIConfigTrojanMilitarySpellChanceSoldier;
  int v6 = s_cAIConfigTrojanMilitarySpellChanceDefence;
  return ChooseNextSpellType(4, v6, 6, v7, 5, 0, v8, a3);
}


// address=[0x132bf10]
// Decompiled from int __thiscall CAITaskForcePriestsTrojan::ChooseMilitarySpellDestination(  CAITaskForcePriestsTrojan *this,  int a2,  int a3,  int a4,  int a5)
int CAITaskForcePriestsTrojan::ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5) {
  // eax
  int v7; // eax
  // [esp-4h] [ebp-14h]
  struct IEntity *v10; // [esp+4h] [ebp-Ch]
  int             NearestOwnTowerInSector; // [esp+8h] [ebp-8h]

  switch(a2) {
    case 4:
      NearestOwnTowerInSector = CScanner::FindNearestOwnTowerInSector(a3, a4, 20, this->OwnerId());
      if(NearestOwnTowerInSector) {
        IEntity &rEntity = CMapObjectMgr::Entity(NearestOwnTowerInSector);
        return Y16X16::PackXYFast(rEntity.X(), rEntity.Y());
      } else {
        return -1;
      }
    case 5:
      return -1;
    case 6:
      return CScanner::FindNearestEnemyFighter(a3, a4, 20, this->OwnerId());
    default:
      return -1;
  }
}


// address=[0x132e560]
// Decompiled from _DWORD *__thiscall CAITaskForcePriestsTrojan::CAITaskForcePriestsTrojan(_DWORD *this, int a2, int a3, int a4)
CAITaskForcePriestsTrojan::CAITaskForcePriestsTrojan(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) : CAITaskForcePriests(a2, a3, a4) {}


// address=[0x132e670]
// Decompiled from void __thiscall CAITaskForcePriestsTrojan::~CAITaskForcePriestsTrojan(CAITaskForcePriestsTrojan *this)
CAITaskForcePriestsTrojan::~CAITaskForcePriestsTrojan(void) = default;


