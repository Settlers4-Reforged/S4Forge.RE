#include "CAITaskForcePriestsRoman.h"

// Definitions for class CAITaskForcePriestsRoman

// address=[0x132b8b0]
// Decompiled from int __thiscall CAITaskForcePriestsRoman::ChooseMilitarySpell(  CAITaskForcePriestsRoman *this,  const struct SCountFightersResult *a2,  int a3)
int  CAITaskForcePriestsRoman::ChooseMilitarySpell(struct SCountFightersResult const & a2, int a3) {
  
  unsigned int v4; // esi
  unsigned int v5; // esi
  int v6; // eax
  int v7; // [esp-14h] [ebp-24h]
  int v8; // [esp-Ch] [ebp-1Ch]
  int v9; // [esp-8h] [ebp-18h]
  int v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]

  v11 = *((_DWORD *)a2 + 5);
  if ( v11 <= 0 )
    return -1;
  if ( v11 < 5 )
  {
    v4 = IAIEnvironment::Rand();
    if ( v4 >= v11 * CRandom16::PercentValue(0x14u) )
      return -1;
  }
  v10 = *((_DWORD *)a2 + 3);
  if ( v10 < 10 )
  {
    v5 = IAIEnvironment::Rand();
    if ( v5 >= v10 * CRandom16::PercentValue(0xAu) )
      a3 &= ~0x10u;
  }
  if ( (a3 & 0x70) == 0 )
    return -1;
  v9 = CStaticConfigVarInt::operator int(&unk_3ECCFC0);
  v8 = CStaticConfigVarInt::operator int(&unk_3ECCFB4);
  v7 = CStaticConfigVarInt::operator int(&unk_3ECCF9C);
  v6 = CStaticConfigVarInt::operator int(&unk_3ECCFA8);
  return sub_132D6A0(4, v6, 5, v7, 6, v8, v9, a3);
}


// address=[0x132b980]
// Decompiled from int __thiscall CAITaskForcePriestsRoman::ChooseMilitarySpellDestination(  CAITaskForcePriestsRoman *this,  int a2,  int a3,  int a4,  int a5)
int  CAITaskForcePriestsRoman::ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5) {
  
  int v5; // eax
  int v6; // eax
  int v8; // eax
  int v9; // eax
  int NearestFighter; // [esp+0h] [ebp-Ch]

  if ( a2 == 4 )
  {
    v5 = CAITaskForce::OwnerId(this);
    v6 = CAlliances::PlayerBit(v5);
    NearestFighter = CScanner::FindNearestFighter(a3, a4, 15, 36, v6);
    if ( NearestFighter <= 0 )
    {
      v8 = CAITaskForce::OwnerId(this);
      return CScanner::FindNearestOwnFighter(a3, a4, 20, v8);
    }
    else
    {
      return NearestFighter;
    }
  }
  else if ( a2 > 4 && a2 <= 6 )
  {
    v9 = CAITaskForce::OwnerId(this);
    return CScanner::FindNearestEnemyFighter(a3, a4, 20, v9);
  }
  else
  {
    return -1;
  }
}


// address=[0x132e520]
// Decompiled from _DWORD *__thiscall CAITaskForcePriestsRoman::CAITaskForcePriestsRoman(_DWORD *this, int a2, int a3, int a4)
 CAITaskForcePriestsRoman::CAITaskForcePriestsRoman(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) {
  
  CAITaskForcePriests::CAITaskForcePriests(this, a2, a3, a4);
  *this = CAITaskForcePriestsRoman::_vftable_;
  return this;
}


// address=[0x132e650]
// Decompiled from void __thiscall CAITaskForcePriestsRoman::~CAITaskForcePriestsRoman(CAITaskForcePriestsRoman *this)
 CAITaskForcePriestsRoman::~CAITaskForcePriestsRoman(void) {
  
  CAITaskForcePriests::~CAITaskForcePriests(this);
}


