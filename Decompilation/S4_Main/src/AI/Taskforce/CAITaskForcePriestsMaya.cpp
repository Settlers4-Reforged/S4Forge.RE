#include "CAITaskForcePriestsMaya.h"

#include "AI/CAIConfigInt.h"
#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"
#include "CConfigManager/Var/CStaticConfigVarInt.h"
#include "Logic/CRandom16.h"
#include "Pathing/CScanner.h"

// Definitions for class CAITaskForcePriestsMaya


// address=[0x132bbf0]
// Decompiled from int __thiscall CAITaskForcePriestsMaya::ChooseMilitarySpell(  CAITaskForcePriestsMaya *this,  const struct SCountFightersResult *a2,  int a3)
int CAITaskForcePriestsMaya::ChooseMilitarySpell(struct SCountFightersResult const &_rFighterCount, int a3) {
  int m_uEnemySoldiers = _rFighterCount.m_uEnemySoldiers;
  if(m_uEnemySoldiers <= 0)
    return -1;
  if(m_uEnemySoldiers < 5) {
    unsigned int v4 = IAIEnvironment::Rand();
    if(v4 >= m_uEnemySoldiers * CRandom16::PercentValue(0x14u))
      return -1;
  }
  int m_uEnemyBowmen = _rFighterCount.m_uEnemyBowmen;
  if(m_uEnemyBowmen < 10) {
    unsigned int v5 = IAIEnvironment::Rand();
    if(v5 >= m_uEnemyBowmen * CRandom16::PercentValue(0xAu))
      a3 &= ~0x20u;
  }
  int m_uAllySoldiers = _rFighterCount.m_uAllySoldiers;
  if(m_uAllySoldiers < 10) {
    unsigned int v6; // esi
    if(m_uAllySoldiers < 5
       || (v6 = IAIEnvironment::Rand(), v6 >= CRandom16::PercentValue(0x14u) * (m_uAllySoldiers - 5))) {
      a3 &= ~0x40u;
    }
  }
  if((a3 & 0x70) == 0)
    return -1;

  return ChooseNextSpellType(
    4,
    s_sConfigMayaMilitarySpellChanceDefence,
    5,
    s_sConfigMayaMilitarySpellChanceAttack,
    6,
    s_sConfigMayaMilitarySpellChanceSoldier,
    s_sConfigMayaMilitarySpellChanceNone,
    a3);
}


// address=[0x132bd00]
// Decompiled from int __thiscall CAITaskForcePriestsMaya::ChooseMilitarySpellDestination(  CAITaskForcePriestsMaya *this,  int a2,  int a3,  int a4,  int a5)
int CAITaskForcePriestsMaya::ChooseMilitarySpellDestination(int a2, int _iX, int _iY, int a5) {
  if(a2 == 4) {
    int v11 = IAIEnvironment::WorldWidth() - 32;
    int v10 = IAIEnvironment::WorldHeight() - 32;
    if(v11 > 0 && v10 > 0) {
      for(int i = 0; i < 5; ++i) {
        int iRandX = IAIEnvironment::Rand() % v11 + 16;
        int iRandY = IAIEnvironment::Rand() % v10 + 16;
        if(IAIEnvironment::GetNearestNoneBlockedPosition(iRandX, iRandY) >= 0)
          return IAIEnvironment::PackXYFast(iRandX, iRandY);
      }
    }
    return -1;
  } else if(a2 == 5) {
    return CScanner::FindNearestEnemyBowman(_iX, _iY, 20, this->OwnerId());
  } else if(a2 == 6) {
    return CScanner::FindNearestOwnFighter(_iX, _iY, 20, this->OwnerId());
  } else {
    return -1;
  }
}


// address=[0x132e4e0]
// Decompiled from CAITaskForcePriestsMaya *__thiscall CAITaskForcePriestsMaya::CAITaskForcePriestsMaya(  CAITaskForcePriestsMaya *this,  int a2,  int a3,  int a4)
CAITaskForcePriestsMaya::CAITaskForcePriestsMaya(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) : CAITaskForcePriests(a2, a3, a4) {}


// address=[0x132e630]
// Decompiled from void __thiscall CAITaskForcePriestsMaya::~CAITaskForcePriestsMaya(CAITaskForcePriestsMaya *this)
CAITaskForcePriestsMaya::~CAITaskForcePriestsMaya(void) = default;


