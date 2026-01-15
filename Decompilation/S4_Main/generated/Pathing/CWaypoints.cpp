#include "CWaypoints.h"

// Definitions for class CWaypoints

// address=[0x130efd0]
// Decompiled from int __thiscall CWaypoints::GoalDistance(CWaypoints *this)
int  CWaypoints::GoalDistance(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x132e830]
// Decompiled from int __thiscall CWaypoints::Back(CWaypoints *this)
int  CWaypoints::Back(void)const {
  
  return *((_DWORD *)this + *((_DWORD *)this + 4) + 5);
}


// address=[0x132e850]
// Decompiled from int __thiscall CWaypoints::CachedWaypointsCount(pairNode *this)
int  CWaypoints::CachedWaypointsCount(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x132ea70]
// Decompiled from CWaypoints *__thiscall CWaypoints::PopBack(CWaypoints *this)
void  CWaypoints::PopBack(void) {
  
  CWaypoints *result; // eax

  result = this;
  if ( *((int *)this + 3) <= 0 )
    return result;
  --*((_DWORD *)this + 3);
  result = (CWaypoints *)CWaypoints::DecWrap(*((_DWORD *)this + 4));
  *((_DWORD *)this + 4) = result;
  return result;
}


// address=[0x159e920]
// Decompiled from int __thiscall CWaypoints::Goal(CWaypoints *this)
int  CWaypoints::Goal(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x15d65e0]
// Decompiled from char __thiscall CWaypoints::GoalCached(CWaypoints *this)
bool  CWaypoints::GoalCached(void)const {
  
  return *((_BYTE *)this + 84);
}


// address=[0x15d66b0]
// Decompiled from CWaypoints *__thiscall CWaypoints::Init(CWaypoints *this)
void  CWaypoints::Init(void) {
  
  CWaypoints *result; // eax

  *(_DWORD *)this = -1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  result = this;
  *((_DWORD *)this + 4) = 15;
  *((_BYTE *)this + 84) = 0;
  return result;
}


// address=[0x15d6a20]
// Decompiled from int __thiscall CWaypoints::PushBack(CWaypoints *this, int a2)
void  CWaypoints::PushBack(int) {
  
  int result; // eax

  *((_BYTE *)this + 84) = *((_DWORD *)this + 3) < 16;
  ++*((_DWORD *)this + 2);
  *((_DWORD *)this + 3) += *((_DWORD *)this + 3) < 16;
  *((_DWORD *)this + 4) = CWaypoints::IncWrap(*((_DWORD *)this + 4));
  result = *((_DWORD *)this + 4);
  *((_DWORD *)this + result + 5) = a2;
  return result;
}


// address=[0x15d6ad0]
// Decompiled from int __thiscall CWaypoints::PushGoal(CWaypoints *this, int a2, int a3)
void  CWaypoints::PushGoal(int,int) {
  
  int result; // eax

  if ( *((_DWORD *)this + 2)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\pathing\\AStar.h",
         285,
         "m_iWaypointsCount == 0") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 2) = 1;
  *((_DWORD *)this + 3) = 1;
  *((_DWORD *)this + 4) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 5) = a2;
  result = a3;
  *((_DWORD *)this + 1) = a3;
  *((_BYTE *)this + 84) = 1;
  return result;
}


// address=[0x132e930]
// Decompiled from int __cdecl CWaypoints::DecWrap(char a1)
static int __cdecl CWaypoints::DecWrap(int) {
  
  return (a1 - 1) & 0xF;
}


// address=[0x15d6620]
// Decompiled from int __cdecl CWaypoints::IncWrap(char a1)
static int __cdecl CWaypoints::IncWrap(int) {
  
  return (a1 + 1) & 0xF;
}


