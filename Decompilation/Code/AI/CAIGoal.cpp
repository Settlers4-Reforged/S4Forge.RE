#include "CAIGoal.h"

// Definitions for class CAIGoal

// address=[0x1301370]
// Decompiled from int __thiscall CAIGoal::EntityId(CAIGoal *this)
int  CAIGoal::EntityId(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x1301850]
// Decompiled from int __thiscall CAIGoal::UniqueId(CAIGoal *this)
int  CAIGoal::UniqueId(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x13096f0]
// Decompiled from int __thiscall CAIGoal::Value(CAIGoal *this)
int  CAIGoal::Value(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x1314ec0]
// Decompiled from CAIGoal *__thiscall CAIGoal::Maximum(CAIGoal *this)
void  CAIGoal::Maximum(void) {
  
  CAIGoal *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0x7FFFFFFF;
  return result;
}


// address=[0x1314f00]
// Decompiled from int __thiscall CAIGoal::Set(CAIGoal *this, int a2, int a3, int a4)
void  CAIGoal::Set(int,int,int) {
  
  int result; // eax

  *(_DWORD *)this = a2;
  result = a3;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  return result;
}


