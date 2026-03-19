#if FALSE
#include "CAITaskForceClassWalk.h"

// Definitions for class CAITaskForceClassWalk

// address=[0x12fcfb0]
// Decompiled from CAITaskForce *__thiscall CAITaskForceClassWalk::CurrentTaskForce(CAITaskForceClassWalk *this)
class CAITaskForce *  CAITaskForceClassWalk::CurrentTaskForce(void)const {
  
  return this->m_pCurrentTaskForce;
}


// address=[0x12fd3a0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this, int a2)
bool  CAITaskForceClassWalk::NextTaskForce(enum T_AI_TASK_FORCE_CMD a2) {
  
  while ( CAITaskForceClassWalk::NextTaskForce(this) )
  {
    if ( CAITaskForce::Command(this->m_pCurrentTaskForce) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x12fd3e0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this, int a2)
bool  CAITaskForceClassWalk::NextTaskForce(enum T_AI_TASK_FORCE_TYPE a2) {
  
  while ( CAITaskForceClassWalk::NextTaskForce(this) )
  {
    if ( CAITaskForce::Type(this->m_pCurrentTaskForce) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x1328da0]
// Decompiled from CAITaskForceClassWalk *__thiscall CAITaskForceClassWalk::CAITaskForceClassWalk(  CAITaskForceClassWalk *this,  CAITaskForceGroup *a2,  int a3)
 CAITaskForceClassWalk::CAITaskForceClassWalk(class CAITaskForceGroup & a2, enum T_AI_TASK_FORCE_CLASS a3) {
  
  this->m_pCurrentTaskForce = 0;
  this->m_pNextTaskForce = CAITaskForceGroup::FirstTaskForce(a2, a3);
  return this;
}


// address=[0x1328dd0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this)
bool  CAITaskForceClassWalk::NextTaskForce(void) {
  
  CAITaskForce *i; // [esp+4h] [ebp-4h]

  for ( i = this->m_pNextTaskForce; i; i = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i) )
  {
    if ( CAITaskForce::NumberOfEntities(i) > 0 )
    {
      this->m_pCurrentTaskForce = i;
      this->m_pNextTaskForce = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
      return 1;
    }
  }
  this->m_pCurrentTaskForce = 0;
  this->m_pNextTaskForce = 0;
  return 0;
}


#endif // Already implemented
