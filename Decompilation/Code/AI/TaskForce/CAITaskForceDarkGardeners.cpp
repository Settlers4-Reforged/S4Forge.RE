#include "CAITaskForceDarkGardeners.h"

// Definitions for class CAITaskForceDarkGardeners

// address=[0x132a100]
// Decompiled from CAITaskForceDarkGardeners *__thiscall CAITaskForceDarkGardeners::CAITaskForceDarkGardeners(  CAITaskForceDarkGardeners *this,  int a2,  int a3)
 CAITaskForceDarkGardeners::CAITaskForceDarkGardeners(int,int) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 6, 11, a3);
  *(_DWORD *)this = CAITaskForceDarkGardeners::_vftable_;
  return this;
}


// address=[0x132a280]
// Decompiled from void __thiscall CAITaskForceDarkGardeners::~CAITaskForceDarkGardeners(CAITaskForceDarkGardeners *this)
 CAITaskForceDarkGardeners::~CAITaskForceDarkGardeners(void) {
  
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132ce70]
// Decompiled from char __thiscall CAITaskForceDarkGardeners::Execute(CAITaskForceDarkGardeners *this)
void  CAITaskForceDarkGardeners::Execute(void) {
  
  int v1; // eax

  if ( CAITaskForce::State(this) == 2 )
  {
    v1 = CAITaskForce::Status(this);
    if ( v1 != 6 )
    {
      CAITaskForceEx::FindWaypoints(this);
      CAITaskForceEx::InitWalk(this, 1);
      CAITaskForce::SetStatus(this, 6);
      LOBYTE(v1) = CAITaskForce::SetWaitCounter(this, 0xFAu);
    }
  }
  else
  {
    LOBYTE(v1) = CAITaskForceEx::Execute(this);
  }
  return v1;
}


// address=[0x132cee0]
// Decompiled from char __thiscall CAITaskForceDarkGardeners::NewCommand(CAITaskForceDarkGardeners *this, unsigned int a2, int a3, int a4)
bool  CAITaskForceDarkGardeners::NewCommand(int,int,int) {
  
  CAITaskForceEx::SetCommandAndClearStuff(this, a2, a3, a4);
  if ( !a2 )
    return 1;
  if ( a2 == 5 )
  {
    CAITaskForce::MarkGoalAsPosition(this);
    (*(void (__thiscall **)(CAITaskForceDarkGardeners *, int))(*(_DWORD *)this + 44))(this, a3);
    CAITaskForce::SetNewStatusAndState(this, 2, 102, 2);
    return 1;
  }
  else
  {
    if ( BBSupportDbgReport(
           1,
           "AI\\AI_TaskForcesEx.cpp",
           2551,
           "CAITaskForceDarkGardeners::NewCommand(): Invalid command!") == 1 )
      __debugbreak();
    return 0;
  }
}


