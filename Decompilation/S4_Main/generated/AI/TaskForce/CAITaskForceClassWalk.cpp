#include "all_headers.h"

// Definitions for class CAITaskForceClassWalk

// address=[0x12fcfb0]
// Decompiled from int __thiscall CAITaskForceClassWalk::CurrentTaskForce(CAITaskForceClassWalk *this)
class CAITaskForce *  CAITaskForceClassWalk::CurrentTaskForce(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x12fd3a0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this, int a2)
bool  CAITaskForceClassWalk::NextTaskForce(enum T_AI_TASK_FORCE_CMD) {
  
  while ( CAITaskForceClassWalk::NextTaskForce(this) )
  {
    if ( CAITaskForce::Command(*(_DWORD **)this) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x12fd3e0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this, int a2)
bool  CAITaskForceClassWalk::NextTaskForce(enum T_AI_TASK_FORCE_TYPE) {
  
  while ( CAITaskForceClassWalk::NextTaskForce(this) )
  {
    if ( CAITaskForce::Type(*(_DWORD *)this) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x1328da0]
// Decompiled from _DWORD *__thiscall CAITaskForceClassWalk::CAITaskForceClassWalk(_DWORD *this, int a2, int a3)
 CAITaskForceClassWalk::CAITaskForceClassWalk(class CAITaskForceGroup &,enum T_AI_TASK_FORCE_CLASS) {
  
  *this = 0;
  this[1] = CAITaskForceGroup::FirstTaskForce(a2, a3);
  return this;
}


// address=[0x1328dd0]
// Decompiled from char __thiscall CAITaskForceClassWalk::NextTaskForce(CAITaskForceClassWalk *this)
bool  CAITaskForceClassWalk::NextTaskForce(void) {
  
  pairNode *i; // [esp+4h] [ebp-4h]

  for ( i = (pairNode *)*((_DWORD *)this + 1); i; i = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i) )
  {
    if ( CAITaskForce::NumberOfEntities(i) > 0 )
    {
      *(_DWORD *)this = i;
      *((_DWORD *)this + 1) = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
      return 1;
    }
  }
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  return 0;
}


