#include "CAITaskForceDarkGardeners.h"

#include "CBB/CBBSupport.h"

// Definitions for class CAITaskForceDarkGardeners

// address=[0x132a100]
// Decompiled from CAITaskForceDarkGardeners *__thiscall CAITaskForceDarkGardeners::CAITaskForceDarkGardeners(  CAITaskForceDarkGardeners *this,  int a2,  int a3)
CAITaskForceDarkGardeners::CAITaskForceDarkGardeners(int a2, int a3) : CAITaskForceEx(a2, AI_TASK_FORCE_CLASS_GROUP, AI_TASK_FORCE_TYPE_DARK_GARDENERS, a3) {}


// address=[0x132a280]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForceDarkGardeners::~CAITaskForceDarkGardeners(CAITaskForce **this)
CAITaskForceDarkGardeners::~CAITaskForceDarkGardeners(void) {
  return CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132ce70]
// Decompiled from void __thiscall CAITaskForceDarkGardeners::Execute(CAITaskForceDarkGardeners *this)
void CAITaskForceDarkGardeners::Execute(void) {
  if(this->State() == 2) {
    if(this->Status() != 6) {
      this->FindWaypoints();
      this->InitWalk(true);
      this->SetStatus(TASK_FORCE_STATUS_UNKNOWN_6);
      this->SetWaitCounter(0xFAu);
    }
  } else {
    this->Execute();
  }
}


// address=[0x132cee0]
// Decompiled from char __thiscall CAITaskForceDarkGardeners::NewCommand(CAITaskForceDarkGardeners *this, unsigned int a2, int a3, int a4)
bool CAITaskForceDarkGardeners::NewCommand(int a2, int a3, int a4) {
  this->SetCommandAndClearStuff(a2, a3, a4);
  if(!a2)
    return 1;
  if(a2 == 5) {
    this->MarkGoalAsPosition();
    this->SetDestinationXY(a3);
    this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_2, 102, 2);
    return true;
  } else {
    if(BBSupportDbgReport(
         1,
         "AI\\AI_TaskForcesEx.cpp",
         2551,
         "CAITaskForceDarkGardeners::NewCommand(): Invalid command!") == 1)
      __debugbreak();
    return false;
  }
}


