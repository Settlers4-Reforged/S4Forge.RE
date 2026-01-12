#include "CAITaskForcePriests.h"

// Definitions for class CAITaskForcePriests

// address=[0x132b400]
// Decompiled from char __thiscall CAITaskForcePriests::NewCommand(CAITaskForcePriests *this, unsigned int a2, int a3, int a4)

bool  CAITaskForcePriests::NewCommand(int,int,int) {
  
  CAITaskForceEx::SetCommandAndClearStuff(this, a2, a3, a4);
  *((_DWORD *)this + 24) = 0;
  if ( !a2 )
    return 1;
  if ( a2 == 6 )
  {
    CAITaskForce::SetNewStatusAndState(this, 7, 106, 0);
    return 1;
  }
  else
  {
    if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 1673, "CAITaskForcePriests::NewCommand(): Invalid command!") == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x132b480]
// Decompiled from _DWORD *__thiscall CAITaskForcePriests::CAITaskForcePriests(_DWORD *this, int a2, int a3, int a4)

 CAITaskForcePriests::CAITaskForcePriests(int,enum T_AI_TASK_FORCE_TYPE,int) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 3, a3, a4);
  *this = CAITaskForcePriests::_vftable_;
  this[24] = 0;
  return this;
}


// address=[0x132b4c0]
// Decompiled from char __thiscall CAITaskForcePriests::IsAddEntityOk(CAITaskForcePriests *this, int a2)

bool  CAITaskForcePriests::IsAddEntityOk(int) {
  
  if ( IAIEnvironment::EntityWarriorType(a2) == 6 )
    return 1;
  IAIEnvironment::DbgTracePrintF("CAITaskForcePriests::IsAddEntityOk(): Entity %i is not a priest!", a2);
  return 0;
}


// address=[0x132b500]
// Decompiled from char __thiscall CAITaskForcePriests::Execute(CAITaskForcePriests *this)

void  CAITaskForcePriests::Execute(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  _BYTE v5[4]; // [esp+0h] [ebp-5Ch] BYREF
  int v6; // [esp+4h] [ebp-58h]
  int v7; // [esp+8h] [ebp-54h]
  int v8; // [esp+Ch] [ebp-50h]
  int v9; // [esp+10h] [ebp-4Ch]
  int v10; // [esp+14h] [ebp-48h]
  int v11; // [esp+18h] [ebp-44h]
  _DWORD *v12; // [esp+1Ch] [ebp-40h]
  unsigned int v13; // [esp+20h] [ebp-3Ch]
  int v14; // [esp+24h] [ebp-38h]
  int v15; // [esp+28h] [ebp-34h]
  int v16; // [esp+2Ch] [ebp-30h]
  int j; // [esp+30h] [ebp-2Ch]
  int i; // [esp+34h] [ebp-28h]
  char v19; // [esp+3Bh] [ebp-21h]
  CAITaskForceEx *v20; // [esp+3Ch] [ebp-20h]
  _BYTE v21[24]; // [esp+40h] [ebp-1Ch] BYREF

  v20 = this;
  v13 = IAIEnvironment::TickCounter();
  if ( v13 < *((_DWORD *)v20 + 24) )
    return CAITaskForceEx::Execute(v20);
  v1 = CAITaskForce::OwnerId(v20);
  v16 = CAIPlayersScriptVars::operator[](v1);
  v15 = 0;
  if ( !CAIPlayerScriptVars::operator[](8) )
  {
    v7 = CAIPlayerScriptVars::operator[](9);
    v6 = CAIPlayerScriptVars::operator[](10);
    for ( i = 0; i < 8; ++i )
    {
      if ( (v7 & (1 << i)) != 0 )
      {
        v2 = CAITaskForce::OwnerId(v20);
        if ( CMagic::CheckManaForCastSpell(v2, i, v6) )
          v15 |= 1 << i;
      }
    }
  }
  v19 = 0;
  CTmpEntitiesRef::CTmpEntitiesRef((CTmpEntitiesRef *)v5);
  for ( j = CAITaskForce::FirstEntity(v20); j; j = CAIEntityInfo::Next(j) )
  {
    v8 = CAIEntityInfo::EntityId(j);
    v12 = (_DWORD *)CTmpEntitiesRef::operator[](v8);
    v10 = IEntity::X(v12);
    v11 = IEntity::Y(v12);
    v3 = CAITaskForce::OwnerId(v20);
    CScanner::CountFighters((struct SCountFightersResult *)v21, v10, v11, 20, v3);
    v14 = (*(int (__thiscall **)(CAITaskForceEx *, _BYTE *, int))(*(_DWORD *)v20 + 48))(v20, v21, v15);
    if ( v14 >= 0 )
    {
      v9 = (*(int (__thiscall **)(CAITaskForceEx *, int, int, int, _DWORD))(*(_DWORD *)v20 + 52))(v20, v14, v10, v11, 0);
      if ( v9 >= 0 )
      {
        IAIEnvironment::EntitySendCastSpellCommand(v8, v14, v9);
        v19 = 1;
        break;
      }
    }
  }
  if ( v19 )
    *((_DWORD *)v20 + 24) = v13 + (IAIEnvironment::Rand() & 0x1F) + 45;
  else
    *((_DWORD *)v20 + 24) = v13 + 30;
  return CAITaskForceEx::Execute(v20);
}


// address=[0x132b6f0]
// Decompiled from int __cdecl CAITaskForcePriests::CreatePriestsTaskForce(int a1, int a2, int a3, int a4)

static class CAITaskForcePriests * __cdecl CAITaskForcePriests::CreatePriestsTaskForce(int,int,enum T_AI_TASK_FORCE_TYPE,int) {
  
  int result; // eax
  int v5; // [esp+14h] [ebp-30h]
  void *v6; // [esp+18h] [ebp-2Ch]
  int v7; // [esp+1Ch] [ebp-28h]
  void *v8; // [esp+20h] [ebp-24h]
  int v9; // [esp+24h] [ebp-20h]
  void *v10; // [esp+28h] [ebp-1Ch]
  int v11; // [esp+2Ch] [ebp-18h]
  void *C; // [esp+30h] [ebp-14h]

  switch ( a1 )
  {
    case 0:
      C = operator new(0x64u);
      if ( C )
        v11 = CAITaskForcePriestsRoman::CAITaskForcePriestsRoman(C, a2, a3, a4);
      else
        v11 = 0;
      result = v11;
      break;
    case 1:
      v10 = operator new(0x64u);
      if ( v10 )
        v9 = CAITaskForcePriestsViking::CAITaskForcePriestsViking(v10, a2, a3, a4);
      else
        v9 = 0;
      result = v9;
      break;
    case 2:
      v8 = operator new(0x64u);
      if ( v8 )
        v7 = CAITaskForcePriestsMaya::CAITaskForcePriestsMaya(v8, a2, a3, a4);
      else
        v7 = 0;
      result = v7;
      break;
    case 4:
      v6 = operator new(0x64u);
      if ( v6 )
        v5 = CAITaskForcePriestsTrojan::CAITaskForcePriestsTrojan(v6, a2, a3, a4);
      else
        v5 = 0;
      result = v5;
      break;
    default:
      if ( BBSupportDbgReport(
             1,
             "AI\\AI_TaskForcesEx.cpp",
             1639,
             "CAITaskForcePriests::CreatePriestsTaskForce(): Unkown race!") == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


// address=[0x132e610]
// Decompiled from void __thiscall CAITaskForcePriests::~CAITaskForcePriests(CAITaskForcePriests *this)

 CAITaskForcePriests::~CAITaskForcePriests(void) {
  
  CAITaskForceEx::~CAITaskForceEx(this);
}


