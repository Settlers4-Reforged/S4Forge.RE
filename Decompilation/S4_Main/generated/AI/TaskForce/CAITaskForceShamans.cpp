#if FALSE
#include "CAITaskForceShamans.h"

// Definitions for class CAITaskForceShamans

// address=[0x132a1c0]
// Decompiled from CAITaskForceShamans *__thiscall CAITaskForceShamans::CAITaskForceShamans(  CAITaskForceShamans *this,  int iOwnerId,  int iFlags)
 CAITaskForceShamans::CAITaskForceShamans(int iOwnerId, int iFlags) {
  
  CAITaskForceEx::CAITaskForceEx((CAITaskForceEx *)this, iOwnerId, 7, 12, iFlags);
  *(_DWORD *)this = CAITaskForceShamans::_vftable_;
  return this;
}


// address=[0x132a2c0]
// Decompiled from void __thiscall CAITaskForceShamans::~CAITaskForceShamans(CAITaskForceShamans *this)
 CAITaskForceShamans::~CAITaskForceShamans(void) {
  
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132cf70]
// Decompiled from void __thiscall CAITaskForceShamans::Execute(CAITaskForceShamans *this)
void  CAITaskForceShamans::Execute(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp+0h] [ebp-30h]
  int v4; // [esp+4h] [ebp-2Ch]
  int v5; // [esp+8h] [ebp-28h]
  int v6; // [esp+Ch] [ebp-24h]
  CAIEntityInfo *v7; // [esp+18h] [ebp-18h]
  CAIEntityInfo *v8; // [esp+1Ch] [ebp-14h]
  CAIEntityInfo *v9; // [esp+20h] [ebp-10h]
  CAIEntityInfo *Entity; // [esp+24h] [ebp-Ch]
  bool v12; // [esp+2Eh] [ebp-2h]
  char v13; // [esp+2Fh] [ebp-1h]

  CAITaskForce::SetWaitCounter(this, 8u);
  switch ( CAITaskForce::State(this) )
  {
    case 0x6B:
      Entity = CAITaskForce::FirstEntity(this);
      if ( Entity && CAITaskForce::CmdGoal(this) > 0 )
      {
        while ( Entity )
        {
          v6 = CAIEntityInfo::EntityId(Entity);
          v1 = CAITaskForce::CmdGoal(this);
          IAIEnvironment::EntityEnterManakopter(v6, v1);
          Entity = CAIEntityInfo::Next(Entity);
        }
        CAITaskForce::SetNewStatusAndState(this, 9, 108, 0);
      }
      break;
    case 0x6C:
      v9 = CAITaskForce::FirstEntity(this);
      v13 = 1;
      if ( v9 && CAITaskForce::CmdGoal(this) > 0 )
      {
        while ( v9 )
        {
          v5 = CAIEntityInfo::EntityId(v9);
          if ( (IAIEnvironment::EntityFlags(v5) & EntityFlag_OnBoard) == 0 )
          {
            v13 = 0;
            break;
          }
          v9 = CAIEntityInfo::Next(v9);
        }
        if ( v13 )
          CAITaskForce::SetStatus(this, 8);
      }
      break;
    case 0x6F:
      v8 = CAITaskForce::FirstEntity(this);
      v12 = 1;
      if ( v8 )
      {
        while ( v8 )
        {
          v4 = CAIEntityInfo::EntityId(v8);
          if ( !IAIEnvironment::EntityIsShamanOutOfMana(v4) )
            v12 = 0;
          v8 = CAIEntityInfo::Next(v8);
        }
        if ( v12 )
          CAITaskForce::SetStatus(this, 10);
      }
      break;
    case 0x70:
      v7 = CAITaskForce::FirstEntity(this);
      if ( v7 )
      {
        while ( v7 )
        {
          v3 = CAIEntityInfo::EntityId(v7);
          v2 = CAITaskForce::CmdGoal(this);
          if ( !IAIEnvironment::EntitySendShamanWorkEvent(v3, v2) )
            return;
          v7 = CAIEntityInfo::Next(v7);
        }
        CAITaskForce::SetState(this, 111);
      }
      break;
    default:
      CAITaskForceEx::Execute(this);
      break;
  }
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
      this->SetDestinationXY(this, a3);
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


#endif // Already implemented
