#include "CAITaskForceShamans.h"

#include "AI/CAIEntityInfo.h"
#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"

// Definitions for class CAITaskForceShamans

// address=[0x132a1c0]
// Decompiled from CAITaskForceShamans *__thiscall CAITaskForceShamans::CAITaskForceShamans(  CAITaskForceShamans *this,  int iOwnerId,  int iFlags)
CAITaskForceShamans::CAITaskForceShamans(int iOwnerId, int iFlags) : CAITaskForceEx(iOwnerId, AI_TASK_FORCE_CLASS_SHAMANS, AI_TASK_FORCE_TYPE_SHAMANS, iFlags) {}


// address=[0x132a2c0]
// Decompiled from void __thiscall CAITaskForceShamans::~CAITaskForceShamans(CAITaskForceShamans *this)
CAITaskForceShamans::~CAITaskForceShamans(void) = default;


// address=[0x132cf70]
// Decompiled from void __thiscall CAITaskForceShamans::Execute(CAITaskForceShamans *this)
void CAITaskForceShamans::Execute(void) {
  CAIEntityInfo *pEntityInfo; // [esp+24h] [ebp-Ch]
  bool           bHasManaInSquad; // [esp+2Eh] [ebp-2h]
  char           v13; // [esp+2Fh] [ebp-1h]

  this->SetWaitCounter(8u);
  switch(this->State()) {
    case 0x6B:
      pEntityInfo = this->FirstEntity();
      if(pEntityInfo && this->CmdGoal() > 0) {
        while(pEntityInfo) {
          IAIEnvironment::EntityEnterManakopter(pEntityInfo->EntityId(), this->CmdGoal());
          pEntityInfo = pEntityInfo->Next();
        }
        this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_9, 108, 0);
      }
      break;
    case 0x6C:
      pEntityInfo = this->FirstEntity();
      v13 = 1;
      if(pEntityInfo && this->CmdGoal() > 0) {
        while(pEntityInfo) {
          if((IAIEnvironment::EntityFlags(pEntityInfo->EntityId()) & 0x8000) == 0) {
            v13 = 0;
            break;
          }
          pEntityInfo = pEntityInfo->Next();
        }
        if(v13)
          this->SetStatus(, 8);
      }
      break;
    case 0x6F:
      pEntityInfo = this->FirstEntity();
      bHasManaInSquad = 1;
      if(pEntityInfo) {
        while(pEntityInfo) {
          bHasManaInSquad = IAIEnvironment::EntityIsShamanOutOfMana(pEntityInfo->EntityId());
          pEntityInfo = pEntityInfo->Next();
        }
        if(bHasManaInSquad)
          this->SetStatus(TASK_FORCE_STATUS_UNKNOWN_10);
      }
      break;
    case 0x70:
      pEntityInfo = this->FirstEntity();
      if(pEntityInfo) {
        while(pEntityInfo) {
          if(!IAIEnvironment::EntitySendShamanWorkEvent(pEntityInfo->EntityId(), this->CmdGoal()))
            return;
          pEntityInfo = pEntityInfo->Next();
        }
        this->SetState(111);
      }
      break;
    default:
      this->Execute();
      break;
  }
}


// address=[0x132d170]
// Decompiled from char __thiscall CAITaskForceShamans::NewCommand(CAITaskForceShamans *this, unsigned int a2, int a3, int a4)
bool CAITaskForceShamans::NewCommand(int a2, int a3, int a4) {
  this->SetCommandAndClearStuff(, a2, a3, a4);
  switch(a2) {
    case 0u:
      return true;
    case 1u:
    case 7u:
      this->MarkGoalAsPosition();
      this->SetDestinationXY(a3);
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_2, 102, 0);
      return true;
    case 3u: {
      this->MarkGoalAsPosition();
      bool bFoundSneakUpPosition = this->FindSneakUpPosition();
      if(bFoundSneakUpPosition)
        this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_2, 102, 0);
      return bFoundSneakUpPosition;
    }
    case 9u:
    case 0xEu:
      this->MarkGoalAsPosition();
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_6, 112, 0);
      return true;
    case 0xAu:
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_9, 107, 0);
      return true;
    default:
      BB_REPORT("CAITaskForceShamans::NewCommand(): Invalid command!");
      return false;
  }
}


