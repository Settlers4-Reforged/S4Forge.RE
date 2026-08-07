#if FALSE
#include "CAITaskForceManakopters.h"

// Definitions for class CAITaskForceManakopters

// address=[0x132a180]
// Decompiled from CAITaskForceManakopters *__thiscall CAITaskForceManakopters::CAITaskForceManakopters(CAITaskForceManakopters *this, int a2, int a3)
 CAITaskForceManakopters::CAITaskForceManakopters(int a2, int a3) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 8, 13, a3);
  this->__vftable = (CAITaskForceEx_vtbl *)CAITaskForceManakopters::_vftable_;
  return this;
}


// address=[0x132a2a0]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForceManakopters::~CAITaskForceManakopters(CAITaskForce **this)
 CAITaskForceManakopters::~CAITaskForceManakopters(void) {
  
  return CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132d290]
// Decompiled from void __thiscall CAITaskForceManakopters::Execute(CAITaskForceManakopters *this)
void  CAITaskForceManakopters::Execute(void) {
  
  __int16 v1; // ax
  int v2; // eax
  __int16 v3; // [esp-4h] [ebp-24h]
  int v4; // [esp+0h] [ebp-20h]
  int v5; // [esp+4h] [ebp-1Ch]
  CAIEntityInfo *Entity; // [esp+Ch] [ebp-14h]
  CAIEntityInfo *v7; // [esp+14h] [ebp-Ch]
  CAIEntityInfo *v8; // [esp+18h] [ebp-8h]

  CAITaskForce::SetWaitCounter(this, 8u);
  switch ( CAITaskForce::State(this) )
  {
    case 0:
      return;
    case 103:
      Entity = CAITaskForce::FirstEntity(this);
      if ( Entity )
      {
        v2 = CAIEntityInfo::EntityId(Entity);
        if ( !IAIEnvironment::EntityIsManakopterMoving(v2) )
        {
          CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
        }
      }
      break;
    case 109:
      v7 = CAITaskForce::FirstEntity(this);
      if ( v7 && CAITaskForce::CmdGoal(this) > 0 )
      {
        while ( v7 )
        {
          v4 = CAIEntityInfo::EntityId(v7);
          v3 = Y16X16::UnpackYFast(this->m_iDestinationXY);
          v1 = Y16X16::UnpackXFast(this->m_iDestinationXY);
          IAIEnvironment::EntityManakopterFlyTo(v4, v1, v3);
          v7 = CAIEntityInfo::Next(v7);
        }
        CAITaskForce::SetState(this, 103);
      }
      break;
    case 110:
      v8 = CAITaskForce::FirstEntity(this);
      if ( v8 )
      {
        while ( v8 )
        {
          v5 = CAIEntityInfo::EntityId(v8);
          IAIEnvironment::EntityManakopterUnload(v5);
          v8 = CAIEntityInfo::Next(v8);
        }
        CAITaskForce::SetState(this, 0);
      }
      break;
    default:
      if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 2850, "CAITaskForceManakopters::Execute(): Invalid state!") == 1 )
      {
        __debugbreak();
      }
      break;
  }
}


// address=[0x132d480]
// Decompiled from char __thiscall CAITaskForceManakopters::NewCommand(CAITaskForceManakopters *this, unsigned int a2, int a3, int a4)
bool  CAITaskForceManakopters::NewCommand(int a2, int a3, int a4) {
  
  char result; // al

  CAITaskForceEx::SetCommandAndClearStuff(this, a2, a3, a4);
  switch ( a2 )
  {
    case 0u:
      result = 1;
      break;
    case 1u:
      CAITaskForce::MarkGoalAsPosition(this);
      this->SetDestinationXY(this, a3);
      CAITaskForce::SetNewStatusAndState(this, 8, 109, 0);
      result = 1;
      break;
    case 0xBu:
      CAITaskForce::SetNewStatusAndState(this, 1, 110, 0);
      result = 1;
      break;
    case 0xCu:
      CAITaskForce::SetNewStatusAndState(this, 10, 110, 0);
      result = 1;
      break;
    default:
      if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 2906, "CAITaskForceManakopters::NewCommand(): Invalid command!") == 1 )
      {
        __debugbreak();
      }
      result = 0;
      break;
  }
  return result;
}


#endif // Already implemented
