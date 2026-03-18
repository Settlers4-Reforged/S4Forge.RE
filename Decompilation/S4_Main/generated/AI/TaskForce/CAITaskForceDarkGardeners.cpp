#include "CAITaskForceDarkGardeners.h"

// Definitions for class CAITaskForceDarkGardeners

// address=[0x132a100]
// Decompiled from CAITaskForceDarkGardeners *__thiscall CAITaskForceDarkGardeners::CAITaskForceDarkGardeners(  CAITaskForceDarkGardeners *this,  int a2,  int a3)
 CAITaskForceDarkGardeners::CAITaskForceDarkGardeners(int a2, int a3) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 6, 11, a3);
  this->__vftable = (CAITaskForceEx_vtbl *)CAITaskForceDarkGardeners::_vftable_;
  return this;
}


// address=[0x132a280]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForceDarkGardeners::~CAITaskForceDarkGardeners(CAITaskForce **this)
 CAITaskForceDarkGardeners::~CAITaskForceDarkGardeners(void) {
  
  return CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132ce70]
// Decompiled from void __thiscall CAITaskForceDarkGardeners::Execute(CAITaskForceDarkGardeners *this)
void  CAITaskForceDarkGardeners::Execute(void) {
  
  if ( CAITaskForce::State(this) == 2 )
  {
    if ( CAITaskForce::Status(this) != 6 )
    {
      CAITaskForceEx::FindWaypoints(this);
      CAITaskForceEx::InitWalk(this, 1);
      CAITaskForce::SetStatus(this, 6);
      CAITaskForce::SetWaitCounter(this, 0xFAu);
    }
  }
  else
  {
    CAITaskForceEx::Execute(this);
  }
}


// address=[0x132cee0]
// Decompiled from char __thiscall CAITaskForceDarkGardeners::NewCommand(CAITaskForceDarkGardeners *this, unsigned int a2, int a3, int a4)
bool  CAITaskForceDarkGardeners::NewCommand(int a2, int a3, int a4) {
  
  CAITaskForceEx::SetCommandAndClearStuff(this, a2, a3, a4);
  if ( !a2 )
    return 1;
  if ( a2 == 5 )
  {
    CAITaskForce::MarkGoalAsPosition(this);
    this->SetDestinationXY(this, a3);
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


