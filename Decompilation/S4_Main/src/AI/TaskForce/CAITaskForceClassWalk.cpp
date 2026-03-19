#include "CAITaskForceClassWalk.h"

#include "AI/CAITaskForce.h"
#include "AI/CAITaskForceGroup.h"

// Definitions for class CAITaskForceClassWalk

// address=[0x12fcfb0]
// Decompiled from CAITaskForce *__thiscall CAITaskForceClassWalk::CurrentTaskForce(CAITaskForceClassWalk *this)
class CAITaskForce *CAITaskForceClassWalk::CurrentTaskForce(void) const {
  return this->m_pCurrentTaskForce;
}


// address=[0x12fd3a0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this, int a2)
bool CAITaskForceClassWalk::NextTaskForce(enum T_AI_TASK_FORCE_CMD a2) {
  while(this->NextTaskForce()) {
    if(this->m_pCurrentTaskForce->Command() == a2)
      return 1;
  }
  return 0;
}


// address=[0x12fd3e0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this, int a2)
bool CAITaskForceClassWalk::NextTaskForce(enum T_AI_TASK_FORCE_TYPE a2) {
  while(this->NextTaskForce()) {
    if(this->m_pCurrentTaskForce->Type() == a2)
      return 1;
  }
  return 0;
}


// address=[0x1328da0]
// Decompiled from CAITaskForceClassWalk *__thiscall CAITaskForceClassWalk::CAITaskForceClassWalk(  CAITaskForceClassWalk *this,  CAITaskForceGroup *a2,  int a3)
CAITaskForceClassWalk::CAITaskForceClassWalk(class CAITaskForceGroup &a2, enum T_AI_TASK_FORCE_CLASS a3) {
  this->m_pCurrentTaskForce = 0;
  this->m_pNextTaskForce = a2.FirstTaskForce(a3);
}


// address=[0x1328dd0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this)
bool CAITaskForceClassWalk::NextTaskForce(void) {
  CAITaskForce *i; // [esp+4h] [ebp-4h]

  for(i = this->m_pNextTaskForce; i; i = i->NextTaskForceGroupMemberOfSameClass()) {
    if(i->NumberOfEntities() > 0) {
      this->m_pCurrentTaskForce = i;
      this->m_pNextTaskForce = i->NextTaskForceGroupMemberOfSameClass();
      return 1;
    }
  }
  this->m_pCurrentTaskForce = 0;
  this->m_pNextTaskForce = 0;
  return 0;
}


