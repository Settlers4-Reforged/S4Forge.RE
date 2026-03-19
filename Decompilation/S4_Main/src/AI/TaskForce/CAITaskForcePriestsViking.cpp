#include "CAITaskForcePriestsViking.h"

#include "AI/IAIEnvironment.h"
#include "Logic/CRandom16.h"
#include "Pathing/CScanner.h"

// Definitions for class CAITaskForcePriestsViking

// address=[0x132ba20]
// Decompiled from int __thiscall CAITaskForcePriestsViking::ChooseMilitarySpell(  CAITaskForcePriestsViking *this,  const struct SCountFightersResult *a2,  int a3)
int CAITaskForcePriestsViking::ChooseMilitarySpell(struct SCountFightersResult const &a2, int a3) {
  if((a3 & 0x80) != 0) {
    if(IAIEnvironment::Rand() < CRandom16::PercentValue(s_cAIConfigVikingMilitarySpellThorsHammer))
      return 7;
  }
  int uEnemySoldiers = a2.m_uEnemySoldiers;
  if(uEnemySoldiers <= 0)
    return -1;
  if(uEnemySoldiers < 5) {
    unsigned int v6 = IAIEnvironment::Rand();
    if(v6 >= uEnemySoldiers * CRandom16::PercentValue(0x14u))
      return -1;
  }
  int m_uAllySoldiers = a2.m_uAllySoldiers;
  if(m_uAllySoldiers < 10) {
    unsigned int v7 = IAIEnvironment::Rand();
    if(v7 >= m_uAllySoldiers * CRandom16::PercentValue(0xAu))
      a3 &= ~0x20u;
  }
  if((a3 & 0x70) == 0)
    return -1;
  int v11 = s_cAIConfigVikingMilitarySpellChanceNone;
  int v10 = s_cAIConfigVikingMilitarySpellChanceSoldier;
  int v9 = s_cAIConfigVikingMilitarySpellChanceAttack;
  int v8 = s_cAIConfigVikingMilitarySpellChanceDefence;
  return ChooseNextSpellType(4, v8, 5, v9, 6, v10, v11, a3);
}


// address=[0x132bb20]
// Decompiled from int __thiscall CAITaskForcePriestsViking::ChooseMilitarySpellDestination(  CAITaskForcePriestsViking *this,  int a2,  int a3,  int a4,  int a5)
int CAITaskForcePriestsViking::ChooseMilitarySpellDestination(int a2, int a3, int a4, int) {
  //int v11 = a2 - 4;
  switch(a2) {
    case 4:
    case 6:
      return CScanner::FindNearestEnemyFighter(a3, a4, 20, this->OwnerId());
    case 5:
      return CScanner::FindNearestOwnFighter(a3, a4, 20, this->OwnerId());
    case 7: {
      SFindNearestResult sNearestTower{};
      if(!CScanner::FindNearestEnemyTowerInSector(sNearestTower, a3, a4, 20, this->OwnerId()))
        return -1;
      IAIEnvironment::BuildingGetEnsignPosition(sNearestTower.m_iNearestFoundId, a3, a4);
      return IAIEnvironment::PackXYFast(a3, a4);
    }
    default:
      return -1;
  }
}


// address=[0x132e5a0]
// Decompiled from CAITaskForcePriestsViking *__thiscall CAITaskForcePriestsViking::CAITaskForcePriestsViking(  CAITaskForcePriestsViking *this,  int a2,  int a3,  int a4)
CAITaskForcePriestsViking::CAITaskForcePriestsViking(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) : CAITaskForcePriests(a2, a3, a4) {}


// address=[0x132e690]
// Decompiled from void __thiscall CAITaskForcePriestsViking::~CAITaskForcePriestsViking(CAITaskForcePriestsViking *this)
CAITaskForcePriestsViking::~CAITaskForcePriestsViking(void) = default;


