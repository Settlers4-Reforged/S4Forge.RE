#include "CAITaskForcePriestsMaya.h"

#include "AI/CAIConfigInt.h"
#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"
#include "CConfigManager/Var/CStaticConfigVarInt.h"
#include "Logic/CRandom16.h"
#include "Pathing/CScanner.h"

// Definitions for class CAITaskForcePriestsMaya

// address=[0x132D560]
int __cdecl sub_132D560(int *_pNumbers, int *_pChances, int _iSize) {
  int    j; // [esp+4h] [ebp-50h]
  _DWORD v8[16]; // [esp+10h] [ebp-44h]

  BB_ASSERT(_pNumbers != nullptr);
  BB_ASSERT(_pChances != nullptr);
  BB_ASSERT(_iSize >= 0);
  BB_ASSERT(_iSize <= 16);

  // if(!_pNumbers && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 79, "_pNumbers != 0") == 1)
  //   __debugbreak();
  // if(!_pChances && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 80, "_pChances != 0") == 1)
  //   __debugbreak();
  // if(_iSize < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 81, "_iSize >= 0") == 1)
  //   __debugbreak();
  // if(_iSize > 16 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 82, "_iSize <= 16") == 1)
  //   __debugbreak();

  unsigned int v6 = 0;
  for(int i = 0; i < _iSize; ++i) {
    if(_pChances[i] > 0)
      v6 += _pChances[i];
    v8[i] = v6;
  }
  if(!v6)
    return -1;
  unsigned int iChosenChance = IAIEnvironment::Rand() % v6;
  for(j = 0; v8[j] <= iChosenChance; ++j);
  return _pNumbers[j];
}

// address=[0x132D6A0]
int __cdecl sub_132D6A0(int _iNumber1, int a2, int _iNumber2, int a4, int _iNumber3, int a6, int a7, int a8) {
  int aNumbers[4]; // [esp+0h] [ebp-24h] BYREF
  int aChances[4]; // [esp+10h] [ebp-14h] BYREF

  BB_ASSERT(_iNumber1 >= 0);
  BB_ASSERT(_iNumber2 >= 0);
  BB_ASSERT(_iNumber3 >= 0);
  BB_ASSERT(_iNumber1 < 32);
  BB_ASSERT(_iNumber2 < 32);
  BB_ASSERT(_iNumber3 < 32);
  // if(_iNumber1 < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 152, "_iNumber1 >= 0") == 1)
  //   __debugbreak();
  // if(_iNumber2 < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 153, "_iNumber2 >= 0") == 1)
  //   __debugbreak();
  // if(_iNumber3 < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 154, "_iNumber3 >= 0") == 1)
  //   __debugbreak();
  // if(_iNumber1 >= 32 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 156, "_iNumber1 < 32") == 1)
  //   __debugbreak();
  // if(_iNumber2 >= 32 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 157, "_iNumber2 < 32") == 1)
  //   __debugbreak();
  // if(_iNumber3 >= 32 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 158, "_iNumber3 < 32") == 1)
  //   __debugbreak();
  if((a8 & (1 << _iNumber1)) == 0)
    a2 = 0;
  if((a8 & (1 << _iNumber2)) == 0)
    a4 = 0;
  if((a8 & (1 << _iNumber3)) == 0)
    a6 = 0;
  aNumbers[0] = _iNumber1;
  aNumbers[1] = _iNumber2;
  aNumbers[2] = _iNumber3;
  aNumbers[3] = -1;
  aChances[0] = a2;
  aChances[1] = a4;
  aChances[2] = a6;
  aChances[3] = a7;
  return sub_132D560(aNumbers, aChances, 4);
}

// 3ECD02C
CAIConfigInt s_sConfigMayaMilitarySpellChanceNone{"MayaMilitarySpellChanceNone", 5};
// 03ECD020
CAIConfigInt s_sConfigMayaMilitarySpellChanceSoldier{"MayaMilitarySpellChanceSoldier", 5};
// 3ECD008
CAIConfigInt s_sConfigMayaMilitarySpellChanceAttack{"MayaMilitarySpellChanceAttack", 5};
// 3ECD014
CAIConfigInt s_sConfigMayaMilitarySpellChanceDefence{"MayaMilitarySpellChanceDefence", 5};


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

  return sub_132D6A0(
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


