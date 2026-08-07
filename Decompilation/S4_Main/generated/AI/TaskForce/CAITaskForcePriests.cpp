#if FALSE
#include "CAITaskForcePriests.h"

// Definitions for class CAITaskForcePriests

// address=[0x132b400]
// Decompiled from char __thiscall CAITaskForcePriests::NewCommand(CAITaskForcePriests *this, unsigned int a2, int a3, int a4)
bool  CAITaskForcePriests::NewCommand(int a2, int a3, int a4) {
  
  CAITaskForceEx::SetCommandAndClearStuff(this, a2, a3, a4);
  this->m_uNextSpellTick = 0;
  if ( !a2 )
  {
    return 1;
  }
  if ( a2 == 6 )
  {
    CAITaskForce::SetNewStatusAndState(this, 7, 106, 0);
    return 1;
  }
  else
  {
    if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 1673, "CAITaskForcePriests::NewCommand(): Invalid command!") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
}


// address=[0x132b480]
// Decompiled from CAITaskForcePriests *__thiscall CAITaskForcePriests::CAITaskForcePriests(CAITaskForcePriests *this, int iOwnerId, int tType, int iFlags)
 CAITaskForcePriests::CAITaskForcePriests(int iOwnerId, enum T_AI_TASK_FORCE_TYPE tType, int iFlags) {
  
  CAITaskForceEx::CAITaskForceEx(this, iOwnerId, 3, tType, iFlags);
  this->__vftable = (CAITaskForceEx_vtbl *)CAITaskForcePriests::_vftable_;
  this->m_uNextSpellTick = 0;
  return this;
}


// address=[0x132b4c0]
// Decompiled from char __thiscall CAITaskForcePriests::IsAddEntityOk(CAITaskForcePriests *this, int a2)
bool  CAITaskForcePriests::IsAddEntityOk(int a2) {
  
  if ( IAIEnvironment::EntityWarriorType(a2) == 6 )
  {
    return 1;
  }
  IAIEnvironment::DbgTracePrintF("CAITaskForcePriests::IsAddEntityOk(): Entity %i is not a priest!", a2);
  return 0;
}


// address=[0x132b500]
// Decompiled from void __thiscall CAITaskForcePriests::Execute(CAITaskForcePriests *this)
void  CAITaskForcePriests::Execute(void) {
  
  unsigned int iOwnerId; // eax
  int v2; // eax
  int v3; // eax
  _BYTE v4[4]; // [esp+0h] [ebp-5Ch] BYREF
  int v5; // [esp+4h] [ebp-58h]
  int v6; // [esp+8h] [ebp-54h]
  int v7; // [esp+Ch] [ebp-50h]
  int iDstXY; // [esp+10h] [ebp-4Ch]
  int v9; // [esp+14h] [ebp-48h]
  int v10; // [esp+18h] [ebp-44h]
  IEntity *v11; // [esp+1Ch] [ebp-40h]
  unsigned int iTick; // [esp+20h] [ebp-3Ch]
  int v13; // [esp+24h] [ebp-38h]
  int v14; // [esp+28h] [ebp-34h]
  char *v15; // [esp+2Ch] [ebp-30h]
  CAIEntityInfo *j; // [esp+30h] [ebp-2Ch]
  int i; // [esp+34h] [ebp-28h]
  char v18; // [esp+3Bh] [ebp-21h]
  struct SCountFightersResult v20; // [esp+40h] [ebp-1Ch] BYREF

  iTick = IAIEnvironment::TickCounter();
  if ( iTick >= this->m_uNextSpellTick )
  {
    iOwnerId = CAITaskForce::OwnerId(this);
    v15 = CAIPlayersScriptVars::operator[]((char *)g_cAIPlayersScriptVars, iOwnerId);
    v14 = 0;
    if ( !CAIPlayerScriptVars::operator[](v15, 8u) )
    {
      v6 = CAIPlayerScriptVars::operator[](v15, 9u);
      v5 = CAIPlayerScriptVars::operator[](v15, 0xAu);
      for ( i = 0;
            i < 8;
            ++i )
      {
        if ( (v6 & (1 << i)) != 0 )
        {
          v2 = CAITaskForce::OwnerId(this);
          if ( CMagic::CheckManaForCastSpell(v2, i, v5) )
          {
            v14 |= 1 << i;
          }
        }
      }
    }
    v18 = 0;
    CTmpEntitiesRef::CTmpEntitiesRef((CTmpEntitiesRef *)v4);
    for ( j = CAITaskForce::FirstEntity(this);
          j;
          j = CAIEntityInfo::Next(j) )
    {
      v7 = CAIEntityInfo::EntityId(j);
      v11 = CTmpEntitiesRef::operator[](v7);
      v9 = IEntity::X(v11);
      v10 = IEntity::Y(v11);
      v3 = CAITaskForce::OwnerId(this);
      CScanner::CountFighters(&v20, v9, v10, 20, v3);
      v13 = this->ChooseMilitarySpell(this, &v20, v14);
      if ( v13 >= 0 )
      {
        iDstXY = this->ChooseMilitarySpellDestination(this, v13, v9, v10, 0);
        if ( iDstXY >= 0 )
        {
          IAIEnvironment::EntitySendCastSpellCommand(v7, v13, iDstXY);
          v18 = 1;
          break;
        }
      }
    }
    if ( v18 )
    {
      this->m_uNextSpellTick = iTick + (IAIEnvironment::Rand() & 0x1F) + 45;
    }
    else
    {
      this->m_uNextSpellTick = iTick + 30;
    }
  }
  CAITaskForceEx::Execute(this);
}


// address=[0x132b6f0]
// Decompiled from CAITaskForcePriests *__cdecl CAITaskForcePriests::CreatePriestsTaskForce(int iRace, int iOwnerId, int tType, int iFlags)
class CAITaskForcePriests * __cdecl CAITaskForcePriests::CreatePriestsTaskForce(int iRace, int iOwnerId, enum T_AI_TASK_FORCE_TYPE tType, int iFlags) {
  
  CAITaskForcePriests *result; // eax
  CAITaskForcePriestsTrojan *v5; // [esp+14h] [ebp-30h]
  CAITaskForcePriestsTrojan *v6; // [esp+18h] [ebp-2Ch]
  CAITaskForcePriestsMaya *v7; // [esp+1Ch] [ebp-28h]
  CAITaskForcePriestsMaya *v8; // [esp+20h] [ebp-24h]
  CAITaskForcePriestsViking *v9; // [esp+24h] [ebp-20h]
  CAITaskForcePriestsViking *v10; // [esp+28h] [ebp-1Ch]
  CAITaskForcePriestsRoman *v11; // [esp+2Ch] [ebp-18h]
  CAITaskForcePriestsRoman *C; // [esp+30h] [ebp-14h]

  switch ( iRace )
  {
    case 0:
      C = (CAITaskForcePriestsRoman *)operator new(0x64u);
      if ( C )
      {
        v11 = CAITaskForcePriestsRoman::CAITaskForcePriestsRoman(C, iOwnerId, tType, iFlags);
      }
      else
      {
        v11 = 0;
      }
      result = v11;
      break;
    case 1:
      v10 = (CAITaskForcePriestsViking *)operator new(0x64u);
      if ( v10 )
      {
        v9 = CAITaskForcePriestsViking::CAITaskForcePriestsViking(v10, iOwnerId, tType, iFlags);
      }
      else
      {
        v9 = 0;
      }
      result = v9;
      break;
    case 2:
      v8 = (CAITaskForcePriestsMaya *)operator new(0x64u);
      if ( v8 )
      {
        v7 = CAITaskForcePriestsMaya::CAITaskForcePriestsMaya(v8, iOwnerId, tType, iFlags);
      }
      else
      {
        v7 = 0;
      }
      result = v7;
      break;
    case 4:
      v6 = (CAITaskForcePriestsTrojan *)operator new(0x64u);
      if ( v6 )
      {
        v5 = CAITaskForcePriestsTrojan::CAITaskForcePriestsTrojan(v6, iOwnerId, tType, iFlags);
      }
      else
      {
        v5 = 0;
      }
      result = v5;
      break;
    default:
      if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 1639, "CAITaskForcePriests::CreatePriestsTaskForce(): Unkown race!") == 1 )
      {
        __debugbreak();
      }
      result = 0;
      break;
  }
  return result;
}


// address=[0x132e610]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForcePriests::~CAITaskForcePriests(CAITaskForce **this)
 CAITaskForcePriests::~CAITaskForcePriests(void) {
  
  return CAITaskForceEx::~CAITaskForceEx(this);
}


#endif // Already implemented
