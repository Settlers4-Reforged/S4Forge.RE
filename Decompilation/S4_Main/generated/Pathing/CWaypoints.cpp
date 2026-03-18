#if FALSE
#include "CWaypoints.h"

// Definitions for class CWaypoints

// address=[0x130efd0]
// Decompiled from int __thiscall CWaypoints::GoalDistance(CWaypoints *this)
int  CWaypoints::GoalDistance(void)const {
  
  return this->m_iGoalDistance;
}


// address=[0x132e830]
// Decompiled from int __thiscall CWaypoints::Back(CWaypoints *this)
int  CWaypoints::Back(void)const {
  
  return this->m_iWaypoints[this->m_iCurrentPointer];
}


// address=[0x132e850]
// Decompiled from int __thiscall CWaypoints::CachedWaypointsCount(CWaypoints *this)
int  CWaypoints::CachedWaypointsCount(void)const {
  
  return this->m_iCachedWaypointsCount;
}


// address=[0x132ea70]
// Decompiled from void __thiscall CWaypoints::PopBack(CWaypoints *this)
void  CWaypoints::PopBack(void) {
  
  if ( this->m_iCachedWaypointsCount > 0 )
  {
    --this->m_iCachedWaypointsCount;
    this->m_iCurrentPointer = CWaypoints::DecWrap(this->m_iCurrentPointer);
  }
}


// address=[0x159e920]
// Decompiled from int __thiscall CWaypoints::Goal(CWaypoints *this)
int  CWaypoints::Goal(void)const {
  
  return this->m_iGoal;
}


// address=[0x15d65e0]
// Decompiled from char __thiscall CWaypoints::GoalCached(CWaypoints *this)
bool  CWaypoints::GoalCached(void)const {
  
  return this[5].m_iGoalDistance;
}


// address=[0x15d66b0]
// Decompiled from void __thiscall CWaypoints::Init(CWaypoints *this)
void  CWaypoints::Init(void) {
  
  this->m_iGoal = -1;
  this->m_iTotalWaypoints = 0;
  this->m_iCachedWaypointsCount = 0;
  this->m_iCurrentPointer = 15;
  this->m_bFullyCached = 0;
}


// address=[0x15d6a20]
// Decompiled from void __thiscall CWaypoints::PushBack(CWaypoints *this, int _iXY)
void  CWaypoints::PushBack(int _iXY) {
  
  this->m_bFullyCached = this->m_iCachedWaypointsCount < 16;
  ++this->m_iTotalWaypoints;
  this->m_iCachedWaypointsCount += this->m_iCachedWaypointsCount < 16;
  this->m_iCurrentPointer = CWaypoints::IncWrap(this->m_iCurrentPointer);
  this->m_iWaypoints[this->m_iCurrentPointer] = _iXY;
}


// address=[0x15d6ad0]
// Decompiled from void __thiscall CWaypoints::PushGoal(CWaypoints *this, int a2, int a3)
void  CWaypoints::PushGoal(int a2, int a3) {
  
  if ( this->m_iTotalWaypoints
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\pathing\\AStar.h",
         285,
         "m_iWaypointsCount == 0") == 1 )
  {
    __debugbreak();
  }
  this->m_iTotalWaypoints = 1;
  this->m_iCachedWaypointsCount = 1;
  this->m_iCurrentPointer = 0;
  this->m_iGoal = a2;
  this->m_iWaypoints[0] = a2;
  this->m_iGoalDistance = a3;
  this->m_bFullyCached = 1;
}


// address=[0x132e930]
// Decompiled from int __cdecl CWaypoints::DecWrap(int a1)
int __cdecl CWaypoints::DecWrap(int a1) {
  
  return ((_BYTE)a1 - 1) & 0xF;
}


// address=[0x15d6620]
// Decompiled from int __cdecl CWaypoints::IncWrap(char a1)
int __cdecl CWaypoints::IncWrap(int a1) {
  
  return (a1 + 1) & 0xF;
}


#endif // Already implemented
