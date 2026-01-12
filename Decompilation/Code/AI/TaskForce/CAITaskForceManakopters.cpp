#include "CAITaskForceManakopters.h"

// Definitions for class CAITaskForceManakopters

// address=[0x132a180]
// Decompiled from CAITaskForceManakopters *__thiscall CAITaskForceManakopters::CAITaskForceManakopters(  CAITaskForceManakopters *this,  int a2,  int a3)
 CAITaskForceManakopters::CAITaskForceManakopters(int,int) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 8, 13, a3);
  *(_DWORD *)this = CAITaskForceManakopters::_vftable_;
  return this;
}


// address=[0x132a2a0]
// Decompiled from void __thiscall CAITaskForceManakopters::~CAITaskForceManakopters(CAITaskForceManakopters *this)
 CAITaskForceManakopters::~CAITaskForceManakopters(void) {
  
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132d290]
// Decompiled from int __thiscall CAITaskForceManakopters::Execute(CAITaskForceManakopters *this)
void  CAITaskForceManakopters::Execute(void) {
  
  int result; // eax
  __int16 v2; // ax
  int v3; // eax
  __int16 v4; // [esp-4h] [ebp-24h]
  int v5; // [esp+0h] [ebp-20h]
  int v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-Ch]
  int v8; // [esp+18h] [ebp-8h]

  CAITaskForce::SetWaitCounter(this, 8u);
  result = CAITaskForce::State(this);
  switch ( result )
  {
    case 0:
      return result;
    case 103:
      result = CAITaskForce::FirstEntity(this);
      if ( result )
      {
        v3 = CAIEntityInfo::EntityId(result);
        result = IAIEnvironment::EntityIsManakopterMoving(v3);
        if ( !(_BYTE)result )
          result = CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
      }
      break;
    case 109:
      result = CAITaskForce::FirstEntity(this);
      v7 = result;
      if ( result )
      {
        result = CAITaskForce::CmdGoal(this);
        if ( result > 0 )
        {
          while ( v7 )
          {
            v5 = CAIEntityInfo::EntityId(v7);
            v4 = Y16X16::UnpackYFast(*((_DWORD *)this + 20));
            v2 = Y16X16::UnpackXFast(*((_DWORD *)this + 20));
            IAIEnvironment::EntityManakopterFlyTo(v5, v2, v4);
            v7 = CAIEntityInfo::Next(v7);
          }
          result = (int)CAITaskForce::SetState(this, 103);
        }
      }
      break;
    case 110:
      result = CAITaskForce::FirstEntity(this);
      v8 = result;
      if ( result )
      {
        while ( v8 )
        {
          v6 = CAIEntityInfo::EntityId(v8);
          IAIEnvironment::EntityManakopterUnload(v6);
          v8 = CAIEntityInfo::Next(v8);
        }
        result = (int)CAITaskForce::SetState(this, 0);
      }
      break;
    default:
      result = BBSupportDbgReport(
                 1,
                 "AI\\AI_TaskForcesEx.cpp",
                 2850,
                 "CAITaskForceManakopters::Execute(): Invalid state!");
      if ( result == 1 )
        __debugbreak();
      break;
  }
  return result;
}


// address=[0x132d480]
// Decompiled from char __thiscall CAITaskForceManakopters::NewCommand(CAITaskForceManakopters *this, unsigned int a2, int a3, int a4)
bool  CAITaskForceManakopters::NewCommand(int,int,int) {
  
  char result; // al

  CAITaskForceEx::SetCommandAndClearStuff(this, a2, a3, a4);
  switch ( a2 )
  {
    case 0u:
      result = 1;
      break;
    case 1u:
      CAITaskForce::MarkGoalAsPosition(this);
      (*(void (__thiscall **)(CAITaskForceManakopters *, int))(*(_DWORD *)this + 44))(this, a3);
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
      if ( BBSupportDbgReport(
             1,
             "AI\\AI_TaskForcesEx.cpp",
             2906,
             "CAITaskForceManakopters::NewCommand(): Invalid command!") == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


