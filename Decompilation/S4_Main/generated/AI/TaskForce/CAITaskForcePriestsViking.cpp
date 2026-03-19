#if FALSE
#include "CAITaskForcePriestsViking.h"

// Definitions for class CAITaskForcePriestsViking

// address=[0x132ba20]
// Decompiled from int __thiscall CAITaskForcePriestsViking::ChooseMilitarySpell(  CAITaskForcePriestsViking *this,  const struct SCountFightersResult *a2,  int a3)
int  CAITaskForcePriestsViking::ChooseMilitarySpell(struct SCountFightersResult const & a2, int a3) {
  
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned int v6; // esi
  unsigned int v7; // esi
  int v8; // eax
  int v9; // [esp-14h] [ebp-24h]
  int v10; // [esp-Ch] [ebp-1Ch]
  int v11; // [esp-8h] [ebp-18h]
  int m_uAllySoldiers; // [esp+8h] [ebp-8h]
  int m_uEnemySoldiers; // [esp+Ch] [ebp-4h]

  if ( (a3 & 0x80) != 0 )
  {
    v3 = IAIEnvironment::Rand();
    v4 = CStaticConfigVarInt::operator int(&s_cAIConfigVikingMilitarySpellThorsHammer);
    if ( v3 < CRandom16::PercentValue(v4) )
      return 7;
  }
  m_uEnemySoldiers = a2->m_uEnemySoldiers;
  if ( m_uEnemySoldiers <= 0 )
    return -1;
  if ( m_uEnemySoldiers < 5 )
  {
    v6 = IAIEnvironment::Rand();
    if ( v6 >= m_uEnemySoldiers * CRandom16::PercentValue(0x14u) )
      return -1;
  }
  m_uAllySoldiers = a2->m_uAllySoldiers;
  if ( m_uAllySoldiers < 10 )
  {
    v7 = IAIEnvironment::Rand();
    if ( v7 >= m_uAllySoldiers * CRandom16::PercentValue(0xAu) )
      a3 &= ~0x20u;
  }
  if ( (a3 & 0x70) == 0 )
    return -1;
  v11 = CStaticConfigVarInt::operator int(&s_cAIConfigVikingMilitarySpellChanceNone);
  v10 = CStaticConfigVarInt::operator int(&s_cAIConfigVikingMilitarySpellChanceSoldier);
  v9 = CStaticConfigVarInt::operator int(&s_cAIConfigVikingMilitarySpellChanceAttack);
  v8 = CStaticConfigVarInt::operator int(&s_cAIConfigVikingMilitarySpellChanceDefence);
  return sub_132D6A0(4, v8, 5, v9, 6, v10, v11, a3);
}


// address=[0x132bb20]
// Decompiled from int __thiscall CAITaskForcePriestsViking::ChooseMilitarySpellDestination(  CAITaskForcePriestsViking *this,  int a2,  int a3,  int a4,  int a5)
int  CAITaskForcePriestsViking::ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5) {
  
  int v5; // eax
  int result; // eax
  int v7; // eax
  int v8; // eax
  int v9; // [esp+0h] [ebp-10h] BYREF
  CAITaskForce *v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]

  v10 = this;
  v11 = a2 - 4;
  switch ( a2 )
  {
    case 4:
    case 6:
      v7 = CAITaskForce::OwnerId(v10);
      result = CScanner::FindNearestEnemyFighter(a3, a4, 20, v7);
      break;
    case 5:
      v5 = CAITaskForce::OwnerId(v10);
      result = CScanner::FindNearestOwnFighter(a3, a4, 20, v5);
      break;
    case 7:
      v8 = CAITaskForce::OwnerId(v10);
      if ( !CScanner::FindNearestEnemyTowerInSector((struct SFindNearestResult *)&v9, a3, a4, 20, v8) )
        goto CAITaskForcePriestsViking__ChooseMilitarySpellDestination___def_172BB45;
      IAIEnvironment::BuildingGetEnsignPosition(v9, &a3, &a4);
      result = IAIEnvironment::PackXYFast(a3, a4);
      break;
    default:
CAITaskForcePriestsViking__ChooseMilitarySpellDestination___def_172BB45:
      result = -1;
      break;
  }
  return result;
}


// address=[0x132e5a0]
// Decompiled from CAITaskForcePriestsViking *__thiscall CAITaskForcePriestsViking::CAITaskForcePriestsViking(  CAITaskForcePriestsViking *this,  int a2,  int a3,  int a4)
 CAITaskForcePriestsViking::CAITaskForcePriestsViking(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) {
  
  CAITaskForcePriests::CAITaskForcePriests(this, a2, a3, a4);
  this->__vftable = (CAITaskForcePriests_vtbl *)CAITaskForcePriestsViking::_vftable_;
  return this;
}


// address=[0x132e690]
// Decompiled from void __thiscall CAITaskForcePriestsViking::~CAITaskForcePriestsViking(CAITaskForcePriestsViking *this)
 CAITaskForcePriestsViking::~CAITaskForcePriestsViking(void) {
  
  CAITaskForcePriests::~CAITaskForcePriests(this);
}


#endif // Already implemented
