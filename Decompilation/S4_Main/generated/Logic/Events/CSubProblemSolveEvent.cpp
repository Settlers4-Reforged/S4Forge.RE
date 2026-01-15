#include "CSubProblemSolveEvent.h"

// Definitions for class CSubProblemSolveEvent

// address=[0x2f4e360]
// Decompiled from CSubProblemSolveEvent *__thiscall CSubProblemSolveEvent::CSubProblemSolveEvent(  CSubProblemSolveEvent *this,  struct CSiedlerAI *a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  struct COptimizeOptions *a9)
 CSubProblemSolveEvent::CSubProblemSolveEvent(class CSiedlerAI *,int,int,int,int,int,int,class COptimizeOptions *) {
  
  int i; // [esp+4h] [ebp-14h]

  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CSubProblemSolveEvent::_vftable_;
  *((_DWORD *)this + 5) = 2;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 4) = 11;
  *((_DWORD *)this + 18) = a2;
  *((_DWORD *)this + 25) = a9;
  *((_DWORD *)this + 11) = a5;
  *((_DWORD *)this + 12) = a6;
  *((_DWORD *)this + 13) = a7;
  *((_DWORD *)this + 14) = a8;
  *((_DWORD *)this + 15) = a4;
  *((_DWORD *)this + 8) = a3;
  for ( i = 0; i < 6; ++i )
    *((_DWORD *)this + i + 19) = 0;
  CSiedlerAI::GetInvokeBuildingType(*((CSiedlerAI **)this + 18), this, (CSubProblemSolveEvent *)((char *)this + 76));
  *((_BYTE *)this + 104) = 0;
  return this;
}


// address=[0x2f4e470]
// Decompiled from void __thiscall CSubProblemSolveEvent::~CSubProblemSolveEvent(COptimizeOptions **this)
 CSubProblemSolveEvent::~CSubProblemSolveEvent(void) {
  
  *this = (COptimizeOptions *)&CSubProblemSolveEvent::_vftable_;
  if ( this[25] )
    delete this[25];
  IScheduleEntry::~IScheduleEntry((IScheduleEntry *)this);
}


// address=[0x2f4e4c0]
// Decompiled from char __thiscall CSubProblemSolveEvent::IsShooting(CSubProblemSolveEvent *this)
bool  CSubProblemSolveEvent::IsShooting(void) {
  
  int LockedSchedNr; // esi

  LockedSchedNr = CReserveDatabase::GetLockedSchedNr(**((CReserveDatabase ***)this + 10));
  if ( LockedSchedNr == CSchedule::GetMainProblemSolve(*((CSchedule **)this + 10), *((_DWORD *)this + 3)) )
  {
    if ( *((_DWORD *)this + 17) )
    {
      *((_DWORD *)this + 9) = 1;
      return 0;
    }
    else if ( CSchedule::AllSubProblemsSolved(*((CDynList ***)this + 10), *((_DWORD *)this + 3)) )
    {
      return 1;
    }
    else
    {
      *((_DWORD *)this + 9) = 1;
      return 0;
    }
  }
  else
  {
    *((_DWORD *)this + 9) = 1;
    return 0;
  }
}


// address=[0x2f4e550]
// Decompiled from char __thiscall CSubProblemSolveEvent::action(CSubProblemSolveEvent *this)
bool  CSubProblemSolveEvent::action(void) {
  
  int MainProblemSolve; // [esp+8h] [ebp-34h]
  int v3; // [esp+Ch] [ebp-30h] BYREF
  int v4[2]; // [esp+10h] [ebp-2Ch] BYREF
  int v5; // [esp+18h] [ebp-24h]
  int v6; // [esp+1Ch] [ebp-20h]
  struct IScheduleEntry *v7; // [esp+20h] [ebp-1Ch]
  void *C; // [esp+24h] [ebp-18h]
  int v9; // [esp+28h] [ebp-14h]
  CSubProblemSolveEvent *v10; // [esp+2Ch] [ebp-10h]
  int v11; // [esp+38h] [ebp-4h]

  v10 = this;
  v9 = 0;
  *(_DWORD *)(*((_DWORD *)this + 18) + 28) = *((_DWORD *)this + 3);
  v5 = 0;
  v6 = 0;
  if ( *((_DWORD *)v10 + 19) )
  {
    v9 = CSchedule::GetInvokeEvent(*((_DWORD *)v10 + 10), *((_DWORD *)v10 + 19));
    if ( !v9 )
    {
      C = operator new(0x50u);
      v11 = 0;
      if ( C )
        v7 = (struct IScheduleEntry *)CInvokeEvent::CInvokeEvent(C, *((_DWORD *)v10 + 19));
      else
        v7 = 0;
      v4[1] = (int)v7;
      v11 = -1;
      CSchedule::NewSchedEntry(*((CSchedule **)v10 + 10), v7);
      return 0;
    }
    if ( *(_DWORD *)(v9 + 48) == 2 && !*((_BYTE *)v10 + 104) )
    {
      v6 = CSiedlerAI::GetInvokePosition(
             *((CSiedlerAI **)v10 + 18),
             *((_DWORD *)v10 + 15),
             *((_DWORD *)v10 + 11),
             *((_DWORD *)v10 + 12),
             *((_DWORD *)v10 + 13),
             *((_DWORD *)v10 + 14));
      CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v10 + 10), v6, &v3, v4);
      v5 = CReserveDatabase::PackPosition(**((CReserveDatabase ***)v10 + 10), 16 * v3 + 8, 16 * v4[0] + 8);
      CInvokeEvent::AddInvokePositionAroundResource(v9, *((_DWORD *)v10 + 19), v5);
      *((_BYTE *)v10 + 104) = 1;
      *((_DWORD *)v10 + 9) = 1;
      return 0;
    }
    if ( *(_DWORD *)(v9 + 48) == 1 )
    {
      MainProblemSolve = CSchedule::GetMainProblemSolve(*((CSchedule **)v10 + 10), *((_DWORD *)v10 + 3));
      *((_DWORD *)CSchedule::GetSchedEntry(*((CSchedule **)v10 + 10), MainProblemSolve) + 16) = 1;
      return 0;
    }
  }
  if ( CSchedule::AllSubProblemsSolved(*((CDynList ***)v10 + 10), *((_DWORD *)v10 + 3)) )
  {
    BBSupportTracePrintF(
      0,
      "SubCall ProbNr:%i von EventNr: %i from Event: %i",
      *((_DWORD *)v10 + 15),
      *((_DWORD *)v10 + 3),
      *((_DWORD *)v10 + 8));
    *(_DWORD *)(*((_DWORD *)v10 + 18) + 36) = 0;
    *((_DWORD *)v10 + 17) = IAI_Module::Problem(
                              *((IAI_Module **)v10 + 18),
                              *((_DWORD *)v10 + 15),
                              *((_DWORD *)v10 + 11),
                              *((_DWORD *)v10 + 12),
                              *((_DWORD *)v10 + 13),
                              *((_DWORD *)v10 + 14));
    if ( *((_DWORD *)v10 + 17) )
    {
      *((_DWORD *)v10 + 16) = 2;
      *((_DWORD *)v10 + 5) = 1;
      BBSupportTracePrintF(
        0,
        "OK ProbNr:%i von EventNr: %i from Event %i",
        *((_DWORD *)v10 + 15),
        *((_DWORD *)v10 + 3),
        *((_DWORD *)v10 + 8));
      CSchedule::TerminateSubProblems(*((CDynList ***)v10 + 10), *((_DWORD *)v10 + 3));
      return 1;
    }
    else
    {
      if ( *(_DWORD *)(*((_DWORD *)v10 + 18) + 36) == 3 || *(_DWORD *)(*((_DWORD *)v10 + 18) + 36) == 1 )
      {
        BBSupportTracePrintF(
          0,
          "Reject ProbNr:%i von EventNr: %i from Event:%i",
          *((_DWORD *)v10 + 15),
          *((_DWORD *)v10 + 3),
          *((_DWORD *)v10 + 8));
        *((_DWORD *)v10 + 16) = 1;
        CSchedule::TerminateSubProblems(*((CDynList ***)v10 + 10), *((_DWORD *)v10 + 3));
      }
      if ( *(_DWORD *)(*((_DWORD *)v10 + 18) + 36) )
        return 0;
      *((_DWORD *)v10 + 16) = 2;
      *((_DWORD *)v10 + 5) = 1;
      return 0;
    }
  }
  else
  {
    *((_DWORD *)v10 + 9) = 1;
    return 0;
  }
}


// address=[0x2f4e8b0]
// Decompiled from char __thiscall CSubProblemSolveEvent::IsAlive(CSubProblemSolveEvent *this)
bool  CSubProblemSolveEvent::IsAlive(void) {
  
  if ( CSchedule::GetMainProblemSolve(*((CSchedule **)this + 10), *((_DWORD *)this + 8)) )
    return 1;
  *((_DWORD *)this + 5) = 3;
  return 0;
}


// address=[0x2f4e8f0]
// Decompiled from bool __thiscall CSubProblemSolveEvent::WaitFor(CSubProblemSolveEvent *this)
bool  CSubProblemSolveEvent::WaitFor(void) {
  
  return CSchedule::AllSubProblemsSolved(*((CDynList ***)this + 10), *((_DWORD *)this + 3)) && !*((_DWORD *)this + 17);
}


