#include "CAITaskForcePriestsMaya.h"

// Definitions for class CAITaskForcePriestsMaya

// address=[0x132bbf0]
// Decompiled from int __thiscall CAITaskForcePriestsMaya::ChooseMilitarySpell(  CAITaskForcePriestsMaya *this,  const struct SCountFightersResult *a2,  int a3)
int  CAITaskForcePriestsMaya::ChooseMilitarySpell(struct SCountFightersResult const & a2, int a3) {
  
  unsigned int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // esi
  int v7; // eax
  int v8; // [esp-14h] [ebp-2Ch]
  int v9; // [esp-Ch] [ebp-24h]
  int v10; // [esp-8h] [ebp-20h]
  int v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]

  v13 = *((_DWORD *)a2 + 5);
  if ( v13 <= 0 )
    return -1;
  if ( v13 < 5 )
  {
    v4 = IAIEnvironment::Rand();
    if ( v4 >= v13 * CRandom16::PercentValue(0x14u) )
      return -1;
  }
  v11 = *((_DWORD *)a2 + 4);
  if ( v11 < 10 )
  {
    v5 = IAIEnvironment::Rand();
    if ( v5 >= v11 * CRandom16::PercentValue(0xAu) )
      a3 &= ~0x20u;
  }
  v12 = *((_DWORD *)a2 + 3);
  if ( v12 < 10 )
  {
    if ( v12 < 5 || (v6 = IAIEnvironment::Rand(), v6 >= CRandom16::PercentValue(0x14u) * (v12 - 5)) )
      a3 &= ~0x40u;
  }
  if ( (a3 & 0x70) == 0 )
    return -1;
  v10 = CStaticConfigVarInt::operator int(&unk_3ECD02C);
  v9 = CStaticConfigVarInt::operator int(&unk_3ECD020);
  v8 = CStaticConfigVarInt::operator int(&unk_3ECD008);
  v7 = CStaticConfigVarInt::operator int(&unk_3ECD014);
  return sub_132D6A0(4, v7, 5, v8, 6, v9, v10, a3);
}


// address=[0x132bd00]
// Decompiled from int __thiscall CAITaskForcePriestsMaya::ChooseMilitarySpellDestination(  CAITaskForcePriestsMaya *this,  int a2,  int a3,  int a4,  int a5)
int  CAITaskForcePriestsMaya::ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5) {
  
  int v5; // eax
  int v6; // eax
  unsigned int v8; // [esp+4h] [ebp-18h] BYREF
  unsigned int v9; // [esp+8h] [ebp-14h] BYREF
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h]

  v13 = a2;
  if ( a2 == 4 )
  {
    v11 = IAIEnvironment::WorldWidth() - 32;
    v10 = IAIEnvironment::WorldHeight() - 32;
    if ( v11 > 0 && v10 > 0 )
    {
      for ( i = 0; i < 5; ++i )
      {
        v8 = IAIEnvironment::Rand() % (unsigned int)v11 + 16;
        v9 = IAIEnvironment::Rand() % (unsigned int)v10 + 16;
        if ( (int)IAIEnvironment::GetNearestNoneBlockedPosition((int *)&v8, (int *)&v9) >= 0 )
          return IAIEnvironment::PackXYFast(v8, v9);
      }
    }
    return -1;
  }
  else if ( v13 == 5 )
  {
    v5 = CAITaskForce::OwnerId(this);
    return CScanner::FindNearestEnemyBowman(a3, a4, 20, v5);
  }
  else if ( v13 == 6 )
  {
    v6 = CAITaskForce::OwnerId(this);
    return CScanner::FindNearestOwnFighter(a3, a4, 20, v6);
  }
  else
  {
    return -1;
  }
}


// address=[0x132e4e0]
// Decompiled from _DWORD *__thiscall CAITaskForcePriestsMaya::CAITaskForcePriestsMaya(_DWORD *this, int a2, int a3, int a4)
 CAITaskForcePriestsMaya::CAITaskForcePriestsMaya(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) {
  
  CAITaskForcePriests::CAITaskForcePriests(this, a2, a3, a4);
  *this = CAITaskForcePriestsMaya::_vftable_;
  return this;
}


// address=[0x132e630]
// Decompiled from void __thiscall CAITaskForcePriestsMaya::~CAITaskForcePriestsMaya(CAITaskForcePriestsMaya *this)
 CAITaskForcePriestsMaya::~CAITaskForcePriestsMaya(void) {
  
  CAITaskForcePriests::~CAITaskForcePriests(this);
}


