#include "all_headers.h"

// Definitions for class CMainProblemSolveEvent

// address=[0x2f4dcc0]
// Decompiled from CMainProblemSolveEvent *__thiscall CMainProblemSolveEvent::CMainProblemSolveEvent(  CMainProblemSolveEvent *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7)
 CMainProblemSolveEvent::CMainProblemSolveEvent(int,int,int,int,int,int) {
  
  int i; // [esp+0h] [ebp-8h]

  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CMainProblemSolveEvent::_vftable_;
  *((_DWORD *)this + 5) = 2;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 4) = 10;
  *((_DWORD *)this + 11) = a4;
  *((_DWORD *)this + 12) = a5;
  *((_DWORD *)this + 13) = a6;
  *((_DWORD *)this + 14) = a7;
  *((_DWORD *)this + 15) = a3;
  *((_DWORD *)this + 8) = a2;
  *((_BYTE *)this + 72) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_BYTE *)this + 104) = 0;
  *((_DWORD *)this + 27) = a6;
  for ( i = 0; i < 6; ++i )
    *((_DWORD *)this + i + 19) = 0;
  return this;
}


// address=[0x2f4dd90]
// Decompiled from void __thiscall CMainProblemSolveEvent::~CMainProblemSolveEvent(CMainProblemSolveEvent *this)
 CMainProblemSolveEvent::~CMainProblemSolveEvent(void) {
  
  *(_DWORD *)this = &CMainProblemSolveEvent::_vftable_;
  if ( *((_DWORD *)this + 17) )
    (***((void (__thiscall ****)(_DWORD, int))this + 17))(*((_DWORD *)this + 17), 1);
  if ( *((_DWORD *)this + 25) )
    CSiedlerAI::`scalar deleting destructor'(*((CSiedlerAI **)this + 25), 1u);
  IScheduleEntry::~IScheduleEntry(this);
}


// address=[0x2f4de10]
// Decompiled from char __thiscall CMainProblemSolveEvent::IsShooting(CMainProblemSolveEvent *this)
bool  CMainProblemSolveEvent::IsShooting(void) {
  
  int LockedSchedNr; // [esp+0h] [ebp-8h]

  LockedSchedNr = CReserveDatabase::GetLockedSchedNr(**((CReserveDatabase ***)this + 10));
  if ( LockedSchedNr )
  {
    if ( LockedSchedNr != *((_DWORD *)this + 3) )
    {
      *((_DWORD *)this + 9) = 1;
      return 0;
    }
  }
  else
  {
    CReserveDatabase::LockReserveDatabase(**((CReserveDatabase ***)this + 10), *((_DWORD *)this + 3));
  }
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


// address=[0x2f4deb0]
// Decompiled from char __thiscall CMainProblemSolveEvent::action(CMainProblemSolveEvent *this)
bool  CMainProblemSolveEvent::action(void) {
  
  struct IScheduleEntry *SpecialTask; // [esp+4h] [ebp-38h]
  struct IScheduleEntry *v3; // [esp+10h] [ebp-2Ch]
  void *v4; // [esp+14h] [ebp-28h]
  CSiedlerAI *v5; // [esp+18h] [ebp-24h]
  CSiedlerAI *C; // [esp+1Ch] [ebp-20h]
  int i; // [esp+20h] [ebp-1Ch]
  _DWORD *v8; // [esp+24h] [ebp-18h]
  char v10; // [esp+2Fh] [ebp-Dh]

  v8 = 0;
  v10 = 0;
  if ( *((_BYTE *)this + 72) )
  {
    *(_DWORD *)(*((_DWORD *)this + 25) + 28) = *((_DWORD *)this + 3);
  }
  else
  {
    C = (CSiedlerAI *)operator new(0x48u);
    if ( C )
      v5 = CSiedlerAI::CSiedlerAI(C, *(struct CEcoSectorAI **)(*((_DWORD *)this + 10) + 36), *((_DWORD *)this + 3));
    else
      v5 = 0;
    *((_DWORD *)this + 25) = v5;
    *((_BYTE *)this + 72) = 1;
  }
  CSiedlerAI::GetInvokeBuildingType(*((CSiedlerAI **)this + 25), this, (CMainProblemSolveEvent *)((char *)this + 76));
  for ( i = 0; *((_DWORD *)this + i + 19); ++i )
  {
    v8 = (_DWORD *)CSchedule::GetInvokeEvent(*((_DWORD *)this + 10), *((_DWORD *)this + i + 19));
    if ( v8 )
    {
      if ( v8[12] == 2 )
      {
        if ( !*((_BYTE *)this + 104) )
        {
          CInvokeEvent::AddInvokePositionAroundResource(v8, *((_DWORD *)this + 19), *((_DWORD *)this + 27));
          *((_BYTE *)this + 104) = 1;
        }
        if ( !i )
          v10 = 1;
      }
    }
    else
    {
      v4 = operator new(0x50u);
      if ( v4 )
        v3 = (struct IScheduleEntry *)CInvokeEvent::CInvokeEvent(v4, *((_DWORD *)this + i + 19));
      else
        v3 = 0;
      CSchedule::NewSchedEntry(*((CSchedule **)this + 10), v3);
      if ( !i )
        v10 = 1;
    }
  }
  if ( v10 )
  {
    *((_DWORD *)this + 9) = 1;
    return 0;
  }
  else if ( CSchedule::AllSubProblemsSolved(*((CDynList ***)this + 10), *((_DWORD *)this + 3)) )
  {
    *(_DWORD *)(*((_DWORD *)this + 25) + 36) = 0;
    BBSupportTracePrintF(0, "MainCall ProbNr:%i von EventNr: %i", *((_DWORD *)this + 15), *((_DWORD *)this + 3));
    *((_DWORD *)this + 17) = IAI_Module::Problem(
                               *((IAI_Module **)this + 25),
                               *((_DWORD *)this + 15),
                               *((_DWORD *)this + 11),
                               *((_DWORD *)this + 12),
                               *((_DWORD *)this + 13),
                               *((_DWORD *)this + 14));
    if ( *((_DWORD *)this + 17) )
    {
      BBSupportTracePrintF(0, "Main OK ProbNr:%i von EventNr: %i", *((_DWORD *)this + 15), *((_DWORD *)this + 3));
      IAI_Module::Execute(*((IAI_Module **)this + 25), *((struct CSolutionTree **)this + 17));
      CReserveDatabase::UnLockReserveDatabase(**((CReserveDatabase ***)this + 10), *((_DWORD *)this + 3));
      *((_DWORD *)this + 5) = 1;
      CSchedule::MarkSolvedProblem(*((CSchedule **)this + 10), *((_DWORD *)this + 8), 1);
      *((_DWORD *)this + 5) = 3;
      if ( v8 )
        v8[5] = 3;
    }
    else
    {
      *((_DWORD *)this + 5) = 1;
      if ( *(_DWORD *)(*((_DWORD *)this + 25) + 36) == 3 || *(_DWORD *)(*((_DWORD *)this + 25) + 36) == 1 )
      {
        BBSupportTracePrintF(0, "Main Reject ProbNr:%i von EventNr: %i", *((_DWORD *)this + 15), *((_DWORD *)this + 3));
        *((_DWORD *)this + 16) = 1;
        CSchedule::MarkSolvedProblem(*((CSchedule **)this + 10), *((_DWORD *)this + 8), 0);
        CReserveDatabase::UnLockReserveDatabase(**((CReserveDatabase ***)this + 10), *((_DWORD *)this + 3));
        *((_DWORD *)this + 5) = 3;
        if ( v8 )
        {
          v8[5] = 3;
          SpecialTask = CSchedule::GetSpecialTask(*((CSchedule **)this + 10), 3);
          CBuildingManagerTask::RemoveBuildingAtPlanning(SpecialTask, v8[11]);
        }
      }
      if ( !*(_DWORD *)(*((_DWORD *)this + 25) + 36) )
      {
        *((_DWORD *)this + 16) = 2;
        CReserveDatabase::UnLockReserveDatabase(**((CReserveDatabase ***)this + 10), *((_DWORD *)this + 3));
        CSchedule::MarkSolvedProblem(*((CSchedule **)this + 10), *((_DWORD *)this + 8), 0);
      }
    }
    return 0;
  }
  else
  {
    *((_DWORD *)this + 9) = 1;
    return 0;
  }
}


// address=[0x2f4e2a0]
// Decompiled from char __thiscall CMainProblemSolveEvent::IsAlive(CMainProblemSolveEvent *this)
bool  CMainProblemSolveEvent::IsAlive(void) {
  
  if ( *((_DWORD *)this + 16) == 1 )
  {
    *((_DWORD *)this + 5) = 3;
    CReserveDatabase::UnLockReserveDatabase(**((CReserveDatabase ***)this + 10), *((_DWORD *)this + 3));
    CSchedule::MarkSolvedProblem(*((CSchedule **)this + 10), *((_DWORD *)this + 8), 0);
    return 0;
  }
  else if ( *((_DWORD *)this + 16) == 2 )
  {
    CSchedule::MarkSolvedProblem(*((CSchedule **)this + 10), *((_DWORD *)this + 8), 1);
    CReserveDatabase::UnLockReserveDatabase(**((CReserveDatabase ***)this + 10), *((_DWORD *)this + 3));
    *((_DWORD *)this + 5) = 3;
    return 0;
  }
  else
  {
    return 1;
  }
}


// address=[0x2f4e330]
// Decompiled from bool __thiscall CMainProblemSolveEvent::WaitFor(CMainProblemSolveEvent *this)
bool  CMainProblemSolveEvent::WaitFor(void) {
  
  return CSchedule::AllSubProblemsSolved(*((CDynList ***)this + 10), *((_DWORD *)this + 3)) != 0;
}


