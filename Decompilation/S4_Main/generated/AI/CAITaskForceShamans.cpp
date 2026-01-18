#include "CAITaskForceShamans.h"

// Definitions for class CAITaskForceShamans

// address=[0x132a1c0]
// Decompiled from CAITaskForceShamans *__thiscall CAITaskForceShamans::CAITaskForceShamans(CAITaskForceShamans *this, int a2, int a3)
 CAITaskForceShamans::CAITaskForceShamans(int a2, int a3) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 7, 12, a3);
  *(_DWORD *)this = CAITaskForceShamans::_vftable_;
  return this;
}


// address=[0x132a2c0]
// Decompiled from void __thiscall CAITaskForceShamans::~CAITaskForceShamans(CAITaskForceShamans *this)
 CAITaskForceShamans::~CAITaskForceShamans(void) {
  
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132cf70]
// Decompiled from char __thiscall CAITaskForceShamans::Execute(CAITaskForceShamans *this)
void  CAITaskForceShamans::Execute(void) {
  
  int Entity; // eax
  int v2; // eax
  int v3; // eax
  int v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+4h] [ebp-2Ch]
  int v7; // [esp+8h] [ebp-28h]
  int v8; // [esp+Ch] [ebp-24h]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  char v14; // [esp+2Eh] [ebp-2h]
  char v15; // [esp+2Fh] [ebp-1h]

  CAITaskForce::SetWaitCounter(this, 8u);
  switch ( CAITaskForce::State(this) )
  {
    case 'k':
      Entity = CAITaskForce::FirstEntity(this);
      v12 = Entity;
      if ( Entity )
      {
        Entity = CAITaskForce::CmdGoal(this);
        if ( Entity > 0 )
        {
          while ( v12 )
          {
            v8 = CAIEntityInfo::EntityId(v12);
            v2 = CAITaskForce::CmdGoal(this);
            IAIEnvironment::EntityEnterManakopter(v8, v2);
            v12 = CAIEntityInfo::Next(v12);
          }
          LOBYTE(Entity) = CAITaskForce::SetNewStatusAndState(this, 9, 108, 0);
        }
      }
      break;
    case 'l':
      Entity = CAITaskForce::FirstEntity(this);
      v11 = Entity;
      v15 = 1;
      if ( Entity )
      {
        Entity = CAITaskForce::CmdGoal(this);
        if ( Entity > 0 )
        {
          while ( v11 )
          {
            v7 = CAIEntityInfo::EntityId(v11);
            Entity = IAIEnvironment::EntityFlags(v7) & 0x8000;
            if ( !Entity )
            {
              v15 = 0;
              break;
            }
            Entity = CAIEntityInfo::Next(v11);
            v11 = Entity;
          }
          if ( v15 )
            LOBYTE(Entity) = CAITaskForce::SetStatus(this, 8);
        }
      }
      break;
    case 'o':
      Entity = CAITaskForce::FirstEntity(this);
      v10 = Entity;
      v14 = 1;
      if ( Entity )
      {
        while ( v10 )
        {
          v6 = CAIEntityInfo::EntityId(v10);
          if ( !IAIEnvironment::EntityIsShamanOutOfMana(v6) )
            v14 = 0;
          Entity = CAIEntityInfo::Next(v10);
          v10 = Entity;
        }
        if ( v14 )
          LOBYTE(Entity) = CAITaskForce::SetStatus(this, 10);
      }
      break;
    case 'p':
      Entity = CAITaskForce::FirstEntity(this);
      v9 = Entity;
      if ( Entity )
      {
        while ( v9 )
        {
          v5 = CAIEntityInfo::EntityId(v9);
          v3 = CAITaskForce::CmdGoal(this);
          LOBYTE(Entity) = IAIEnvironment::EntitySendShamanWorkEvent(v5, v3);
          if ( !(_BYTE)Entity )
            return Entity;
          v9 = CAIEntityInfo::Next(v9);
        }
        LOBYTE(Entity) = (unsigned __int8)CAITaskForce::SetState(this, 111);
      }
      break;
    default:
      LOBYTE(Entity) = CAITaskForceEx::Execute(this);
      break;
  }
  return Entity;
}


// address=[0x132d170]
// Decompiled from char __thiscall CAITaskForceShamans::NewCommand(CAITaskForceShamans *this, unsigned int a2, int a3, int a4)
bool  CAITaskForceShamans::NewCommand(int a2, int a3, int a4) {
  
  char result; // al
  char SneakUpPosition; // [esp+Bh] [ebp-1h]

  CAITaskForceEx::SetCommandAndClearStuff(this, a2, a3, a4);
  switch ( a2 )
  {
    case 0u:
      result = 1;
      break;
    case 1u:
    case 7u:
      CAITaskForce::MarkGoalAsPosition(this);
      (*(void (__thiscall **)(CAITaskForceShamans *, int))(*(_DWORD *)this + 44))(this, a3);
      CAITaskForce::SetNewStatusAndState(this, 2, 102, 0);
      result = 1;
      break;
    case 3u:
      CAITaskForce::MarkGoalAsPosition(this);
      SneakUpPosition = CAITaskForceEx::FindSneakUpPosition(this);
      if ( SneakUpPosition )
        CAITaskForce::SetNewStatusAndState(this, 2, 102, 0);
      result = SneakUpPosition;
      break;
    case 9u:
    case 0xEu:
      CAITaskForce::MarkGoalAsPosition(this);
      CAITaskForce::SetNewStatusAndState(this, 6, 112, 0);
      result = 1;
      break;
    case 0xAu:
      CAITaskForce::SetNewStatusAndState(this, 9, 107, 0);
      result = 1;
      break;
    default:
      if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 2755, "CAITaskForceShamans::NewCommand(): Invalid command!") == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


