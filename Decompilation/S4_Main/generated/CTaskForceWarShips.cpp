#include "all_headers.h"

// Definitions for class CTaskForceWarShips

// address=[0x132a240]
// Decompiled from _DWORD *__thiscall CTaskForceWarShips::CTaskForceWarShips(_DWORD *this, int a2, int a3, int a4)
 CTaskForceWarShips::CTaskForceWarShips(int,enum T_AI_TASK_FORCE_TYPE,int) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 5, a3, a4);
  *this = CTaskForceWarShips::_vftable_;
  return this;
}


// address=[0x132a300]
// Decompiled from void __thiscall CTaskForceWarShips::~CTaskForceWarShips(CTaskForceWarShips *this)
 CTaskForceWarShips::~CTaskForceWarShips(void) {
  
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132ce30]
// Decompiled from char __thiscall CTaskForceWarShips::IsAddEntityOk(CTaskForceWarShips *this, int a2)
bool  CTaskForceWarShips::IsAddEntityOk(int) {
  
  if ( IAIEnvironment::EntityWarriorType(a2) == 10 )
    return 1;
  IAIEnvironment::DbgTracePrintF("CTaskForceWarShips::IsAddEntityOk(): Entity %i is not a war ship!", a2);
  return 0;
}


