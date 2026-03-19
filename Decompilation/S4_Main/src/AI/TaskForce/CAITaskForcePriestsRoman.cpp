#include "CAITaskForcePriestsRoman.h"

#include "AI/CAIConfigInt.h"
#include "AI/IAIEnvironment.h"
#include "Logic/CRandom16.h"
#include "Pathing/CScanner.h"

// Definitions for class CAITaskForcePriestsRoman

// address=[0x132b8b0]
// Decompiled from int __thiscall CAITaskForcePriestsRoman::ChooseMilitarySpell(  CAITaskForcePriestsRoman *this,  const struct SCountFightersResult *a2,  int a3)
int CAITaskForcePriestsRoman::ChooseMilitarySpell(struct SCountFightersResult const &a2, int a3) {
  // esi
  // esi
  // eax
  // [esp-14h] [ebp-24h]
  // [esp-Ch] [ebp-1Ch]
  // [esp-8h] [ebp-18h]
  // [esp+8h] [ebp-8h]
  // [esp+Ch] [ebp-4h]

  int m_uEnemySoldiers = a2.m_uEnemySoldiers;
  if(m_uEnemySoldiers <= 0)
    return -1;
  if(m_uEnemySoldiers < 5) {
    unsigned int v4 = IAIEnvironment::Rand();
    if(v4 >= m_uEnemySoldiers * CRandom16::PercentValue(0x14u))
      return -1;
  }
  int m_uAllySoldiers = a2.m_uAllySoldiers;
  if(m_uAllySoldiers < 10) {
    unsigned int v5 = IAIEnvironment::Rand();
    if(v5 >= m_uAllySoldiers * CRandom16::PercentValue(0xAu))
      a3 &= ~0x10u;
  }
  if((a3 & 0x70) == 0)
    return -1;
  int v9 = s_cAIConfigRomanMilitarySpellChanceNone;
  int v8 = s_cAIConfigRomanMilitarySpellChanceSoldier;
  int v7 = s_cAIConfigRomanMilitarySpellChanceAttack;
  int v6 = s_cAIConfigRomanMilitarySpellChanceDefence;
  return ChooseNextSpellType(4, v6, 5, v7, 6, v8, v9, a3);
}


// address=[0x132b980]
// Decompiled from int __thiscall CAITaskForcePriestsRoman::ChooseMilitarySpellDestination(  CAITaskForcePriestsRoman *this,  int a2,  int a3,  int a4,  int a5)
int CAITaskForcePriestsRoman::ChooseMilitarySpellDestination(int a2, int _iX, int _iY, int a5) {
  if(a2 == 4) {
    int NearestFighter = CScanner::FindNearestFighter(_iX, _iY, 15, 36, CAlliances::PlayerBit(this->OwnerId()));
    if(NearestFighter <= 0) {
      return CScanner::FindNearestOwnFighter(_iX, _iY, 20, this->OwnerId());
    } else {
      return NearestFighter;
    }
  } else if(a2 > 4 && a2 <= 6) {
    return CScanner::FindNearestEnemyFighter(_iX, _iY, 20, this->OwnerId());
  } else {
    return -1;
  }
}


// address=[0x132e520]
// Decompiled from CAITaskForcePriestsRoman *__thiscall CAITaskForcePriestsRoman::CAITaskForcePriestsRoman(  CAITaskForcePriestsRoman *this,  int iOwnerId,  int tType,  int iFlags)
CAITaskForcePriestsRoman::CAITaskForcePriestsRoman(int iOwnerId, enum T_AI_TASK_FORCE_TYPE tType, int iFlags) : CAITaskForcePriests(iOwnerId, tType, iFlags) {}


// address=[0x132e650]
// Decompiled from void __thiscall CAITaskForcePriestsRoman::~CAITaskForcePriestsRoman(CAITaskForcePriestsRoman *this)
CAITaskForcePriestsRoman::~CAITaskForcePriestsRoman(void) = default;


