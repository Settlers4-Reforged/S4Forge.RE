#include "CAITaskForceManakopters.h"

#include "AI/CAIEntityInfo.h"
#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"
#include "World/helper.h"

// Definitions for class CAITaskForceManakopters

// address=[0x132a180]
// Decompiled from CAITaskForceManakopters *__thiscall CAITaskForceManakopters::CAITaskForceManakopters(  CAITaskForceManakopters *this,  int a2,  int a3)
CAITaskForceManakopters::CAITaskForceManakopters(int a2, int a3) : CAITaskForceEx(a2, AI_TASK_FORCE_CLASS_MANAKOPTERS, AI_TASK_FORCE_TYPE_MANAKOPTERS, a3) {}


// address=[0x132a2a0]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForceManakopters::~CAITaskForceManakopters(CAITaskForce **this)
CAITaskForceManakopters::~CAITaskForceManakopters(void) = default;


// address=[0x132d290]
// Decompiled from void __thiscall CAITaskForceManakopters::Execute(CAITaskForceManakopters *this)
void CAITaskForceManakopters::Execute(void) {
  CAIEntityInfo *Entity; // [esp+Ch] [ebp-14h]
  CAIEntityInfo *v8; // [esp+18h] [ebp-8h]

  CAIEntityInfo *pEntityInfo;
  this->SetWaitCounter(8u);
  switch(this->State()) {
    case 0:
      return;
    case 103:
      pEntityInfo = this->FirstEntity();
      if(pEntityInfo) {
        if(!IAIEnvironment::EntityIsManakopterMoving(pEntityInfo->EntityId()))
          this->SetNewStatusAndState(1, 0, 0);
      }
      break;
    case 109:
      pEntityInfo = this->FirstEntity();
      if(pEntityInfo && this->CmdGoal() > 0) {
        while(pEntityInfo) {
          int iDstX = Y16X16::UnpackXFast(this->m_iDestinationXY);
          int iDstY = Y16X16::UnpackYFast(this->m_iDestinationXY);
          IAIEnvironment::EntityManakopterFlyTo(pEntityInfo->EntityId(), iDstX, iDstY);
          pEntityInfo = pEntityInfo->Next();
        }
        this->SetState(103);
      }
      break;
    case 110:
      pEntityInfo = this->FirstEntity();
      if(pEntityInfo) {
        while(pEntityInfo) {
          IAIEnvironment::EntityManakopterUnload(pEntityInfo->EntityId());
          pEntityInfo = pEntityInfo->Next();
        }
        this->SetState(0);
      }
      break;
    default:
      BB_REPORT("CAITaskForceManakopters::Execute(): Invalid state!")
      // if(BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 2850, "CAITaskForceManakopters::Execute(): Invalid state!") == 1)
      //   __debugbreak();
      break;
  }
}


// address=[0x132d480]
// Decompiled from char __thiscall CAITaskForceManakopters::NewCommand(CAITaskForceManakopters *this, unsigned int a2, int a3, int a4)
bool CAITaskForceManakopters::NewCommand(int a2, int a3, int a4) {
  char result; // al

  this->SetCommandAndClearStuff(a2, a3, a4);
  switch(a2) {
    case 0u:
      return true;
    case 1u:
      this->MarkGoalAsPosition();
      this->SetDestinationXY(a3);
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_8, 109, 0);
      return true;
    case 0xBu:
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_1, 110, 0);
      return true;
    case 0xCu:
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_10, 110, 0);
      return true;
    default:
      BB_REPORT("CAITaskForceManakopters::NewCommand(): Invalid command!")
      return false;
  }
}


