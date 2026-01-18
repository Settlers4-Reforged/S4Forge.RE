#include "CMaterialManagerTask.h"

// Definitions for class CMaterialManagerTask

// address=[0x2f55020]
// Decompiled from IScheduleEntry *__thiscall CMaterialManagerTask::CMaterialManagerTask(IScheduleEntry *this, int a2, int a3)
 CMaterialManagerTask::CMaterialManagerTask(enum PILE_TYPES a2, int a3) {
  
  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CMaterialManagerTask::_vftable_;
  *((_DWORD *)this + 4) = 4;
  *((_DWORD *)this + 5) = 2;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 13) = a2;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 12) = 1;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = a3;
  return this;
}


// address=[0x2f55090]
// Decompiled from void __thiscall CMaterialManagerTask::~CMaterialManagerTask(CMaterialManagerTask *this)
 CMaterialManagerTask::~CMaterialManagerTask(void) {
  
  *(_DWORD *)this = &CMaterialManagerTask::_vftable_;
  IScheduleEntry::~IScheduleEntry(this);
}


// address=[0x2f550b0]
// Decompiled from bool __thiscall CMaterialManagerTask::IsShooting(CMaterialManagerTask *this)
bool  CMaterialManagerTask::IsShooting(void) {
  
  int v2; // esi

  if ( (int)--*((_DWORD *)this + 15) <= 0 )
  {
    *((_DWORD *)this + 15) = 5;
    v2 = CMaterialManagerTask::MinDebitOutput(this, *((_DWORD *)this + 13));
    return v2 > CMaterialManagerTask::MinCreditOutput(this, *((_DWORD *)this + 13));
  }
  else
  {
    return 0;
  }
}


// address=[0x2f55110]
// Decompiled from char __thiscall CMaterialManagerTask::action(CMaterialManagerTask *this)
bool  CMaterialManagerTask::action(void a2) {
  
  CExpandationEvent *v2; // [esp+14h] [ebp-40h]
  CExpandationEvent *v3; // [esp+18h] [ebp-3Ch]
  struct IScheduleEntry *v4; // [esp+1Ch] [ebp-38h]
  CExpandationEvent *v5; // [esp+20h] [ebp-34h]
  struct IScheduleEntry *v6; // [esp+24h] [ebp-30h]
  CMainProblemSolveEvent *v7; // [esp+28h] [ebp-2Ch]
  int TargetPosition; // [esp+2Ch] [ebp-28h]
  struct IScheduleEntry *v9; // [esp+30h] [ebp-24h]
  CMainProblemSolveEvent *C; // [esp+34h] [ebp-20h]
  int v11; // [esp+40h] [ebp-14h]

  *((_DWORD *)this + 14) = 0;
  switch ( *((_DWORD *)this + 13) )
  {
    case 7:
      v11 = 112;
      break;
    case 0xB:
      v11 = 0;
      break;
    case 0xE:
      v11 = 48;
      break;
    case 0x14:
    case 0x22:
      v11 = 16;
      break;
    case 0x20:
      v11 = 96;
      break;
    case 0x21:
      v11 = 64;
      break;
    case 0x23:
      v11 = -6;
      break;
    default:
      v11 = -4;
      break;
  }
  switch ( *((_DWORD *)this + 12) )
  {
    case 1:
      if ( !(unsigned __int8)CMaterialManagerTask::IsSingleChainProduction(this, *((_DWORD *)this + 13)) )
      {
        C = (CMainProblemSolveEvent *)operator new(0x70u);
        if ( C )
          v9 = CMainProblemSolveEvent::CMainProblemSolveEvent(
                 C,
                 *((_DWORD *)this + 3),
                 3,
                 *((_DWORD *)this + 13),
                 0,
                 0,
                 0);
        else
          v9 = 0;
        *((_DWORD *)this + 8) = CSchedule::NewSchedEntry(*((CSchedule **)this + 10), v9);
        goto CMaterialManagerTask__action___def_33551D7;
      }
      *((_DWORD *)this + 12) = 2;
      return 1;
    case 2:
      TargetPosition = CSchedule::GetTargetPosition(*((CSchedule **)this + 10), *((_DWORD *)this + 13));
      v7 = (CMainProblemSolveEvent *)operator new(0x70u);
      if ( v7 )
        v6 = CMainProblemSolveEvent::CMainProblemSolveEvent(
               v7,
               *((_DWORD *)this + 3),
               10,
               *((_DWORD *)this + 13),
               0,
               TargetPosition,
               0);
      else
        v6 = 0;
      *((_DWORD *)this + 8) = CSchedule::NewSchedEntry(*((CSchedule **)this + 10), v6);
      goto CMaterialManagerTask__action___def_33551D7;
    case 3:
      if ( CSchedule::IsAnyExpandation(*((CDynList ***)this + 10)) )
      {
        *((_DWORD *)this + 12) = 1;
        return 0;
      }
      v5 = (CExpandationEvent *)operator new(0x74u);
      if ( v5 )
        v4 = CExpandationEvent::CExpandationEvent(v5, *((_DWORD *)this + 3), 0, v11);
      else
        v4 = 0;
      *((_DWORD *)this + 8) = CSchedule::NewSchedEntry(*((CSchedule **)this + 10), v4);
      goto CMaterialManagerTask__action___def_33551D7;
    case 4:
      if ( CSchedule::IsAnyExpandation(*((CDynList ***)this + 10)) )
      {
        *((_DWORD *)this + 12) = 1;
        return 0;
      }
      else
      {
        v3 = (CExpandationEvent *)operator new(0x74u);
        if ( v3 )
          v2 = CExpandationEvent::CExpandationEvent(v3, -5, *((CDynList ***)this + 10));
        else
          v2 = 0;
        *((_DWORD *)this + 8) = CSchedule::NewSchedEntry(*((CSchedule **)this + 10), v2);
CMaterialManagerTask__action___def_33551D7:
        *((_DWORD *)this + 5) = 1;
        return 1;
      }
    default:
      goto CMaterialManagerTask__action___def_33551D7;
  }
}


// address=[0x2f55460]
// Decompiled from char __thiscall CMaterialManagerTask::IsAlive(CMaterialManagerTask *this)
bool  CMaterialManagerTask::IsAlive(void) {
  
  return 1;
}


// address=[0x2f55470]
// Decompiled from char __thiscall CMaterialManagerTask::WaitFor(CSchedule **this)
bool  CMaterialManagerTask::WaitFor(void) {
  
  char result; // al
  struct IScheduleEntry *SpecialTask; // [esp+0h] [ebp-Ch]

  SpecialTask = CSchedule::GetSpecialTask(this[10], 3);
  switch ( (unsigned int)this[12] )
  {
    case 1u:
      if ( this[14] == (CSchedule *)1 )
      {
        this[12] = (CSchedule *)2;
        this[8] = 0;
        BBSupportTracePrintF(
          0,
          "AI Failed: PlayerNr %i do not adding production of %s",
          *((_DWORD *)this[10] + 5),
          (&off_3AC3C14)[2 * (_DWORD)this[13]]);
        result = 1;
      }
      else
      {
        if ( this[14] != (CSchedule *)2 )
          goto CMaterialManagerTask__WaitFor___def_33554A8;
        this[12] = (CSchedule *)1;
        this[8] = 0;
        BBSupportTracePrintF(
          0,
          "AI Success: PlayerNr %i add production of %s",
          *((_DWORD *)this[10] + 5),
          (&off_3AC3C14)[2 * (_DWORD)this[13]]);
        result = 1;
      }
      break;
    case 2u:
      if ( this[14] == (CSchedule *)1 )
      {
        this[8] = 0;
        this[12] = (CSchedule *)3;
        BBSupportTracePrintF(
          0,
          "AI Failed: PlayerNr %i do not init a new production of %s",
          *((_DWORD *)this[10] + 5),
          (&off_3AC3C14)[2 * (_DWORD)this[13]]);
        result = 1;
      }
      else
      {
        if ( this[14] != (CSchedule *)2 )
          goto CMaterialManagerTask__WaitFor___def_33554A8;
        this[8] = 0;
        this[12] = (CSchedule *)1;
        BBSupportTracePrintF(
          0,
          "AI Success: PlayerNr %i init a new production of %s",
          *((_DWORD *)this[10] + 5),
          (&off_3AC3C14)[2 * (_DWORD)this[13]]);
        result = 1;
      }
      break;
    case 3u:
      if ( CBuildingManagerTask::IsRejectedBuilding(SpecialTask, 46, 1) )
        this[14] = (CSchedule *)1;
      if ( this[14] == (CSchedule *)2 )
      {
        this[8] = 0;
        this[12] = (CSchedule *)1;
        BBSupportTracePrintF(
          0,
          "AI Success: PlayerNr %i init an expandation for getting %s",
          *((_DWORD *)this[10] + 5),
          (&off_3AC3C14)[2 * (_DWORD)this[13]]);
        result = 1;
      }
      else
      {
        if ( this[14] != (CSchedule *)1 )
          goto CMaterialManagerTask__WaitFor___def_33554A8;
        this[8] = 0;
        this[12] = (CSchedule *)4;
        BBSupportTracePrintF(
          0,
          "AI failed: PlayerNr %i can't do an expandation for getting %s",
          *((_DWORD *)this[10] + 5),
          (&off_3AC3C14)[2 * (_DWORD)this[13]]);
        result = 1;
      }
      break;
    case 4u:
      if ( CBuildingManagerTask::IsRejectedBuilding(SpecialTask, 46, 1) )
        this[14] = (CSchedule *)1;
      if ( this[14] == (CSchedule *)2 )
      {
        this[8] = 0;
        this[12] = (CSchedule *)1;
        BBSupportTracePrintF(
          0,
          "AI Success: PlayerNr %i init an safty expandation for getting %s",
          *((_DWORD *)this[10] + 5),
          (&off_3AC3C14)[2 * (_DWORD)this[13]]);
        result = 1;
      }
      else
      {
        if ( this[14] != (CSchedule *)1 )
          goto CMaterialManagerTask__WaitFor___def_33554A8;
        this[8] = 0;
        this[12] = (CSchedule *)1;
        BBSupportTracePrintF(
          0,
          "AI Success: PlayerNr %i can't do an safty expandation for getting %s",
          *((_DWORD *)this[10] + 5),
          (&off_3AC3C14)[2 * (_DWORD)this[13]]);
        result = 1;
      }
      break;
    default:
CMaterialManagerTask__WaitFor___def_33554A8:
      if ( this[8] )
      {
        if ( !CSchedule::GetSchedEntry(this[10], this[8]) )
          this[14] = (CSchedule *)1;
      }
      result = 0;
      break;
  }
  return result;
}


// address=[0x2f55790]
// Decompiled from int __thiscall CMaterialManagerTask::MinDebitOutput(CSchedule **this, int a2)
int  CMaterialManagerTask::MinDebitOutput(enum PILE_TYPES a2) {
  
  struct IAIEcoManager *EcoSector; // eax
  int v3; // eax

  EcoSector = CSchedule::GetEcoSector(this[10]);
  v3 = (*(int (__thiscall **)(struct IAIEcoManager *, struct IAIEcoManager *))(*(_DWORD *)EcoSector + 292))(
         EcoSector,
         EcoSector);
  return CDebitLevelManager::GetDebitValue(*((_DWORD *)this[10] + 2), *((_DWORD *)this[10] + 6), a2, 0, v3);
}


// address=[0x2f557e0]
// Decompiled from int __thiscall CMaterialManagerTask::MinCreditOutput(_DWORD *this, int a2)
int  CMaterialManagerTask::MinCreditOutput(enum PILE_TYPES a2) {
  
  int v3; // [esp+1Ch] [ebp-14h]

  std::vector<SMakroEntry>::vector<SMakroEntry>();
  this[11] = 0;
  CProductionDataTab::GoodTypeProducedBy(*(_DWORD *)(this[10] + 40), this[13], 0, *(_DWORD *)(this[10] + 24));
  this[11] = CSchedule::GetPotentialGoodCapacity((_DWORD *)this[10], this[13]);
  v3 = this[11];
  std::vector<SMakroEntry>::~vector<SMakroEntry>();
  return v3;
}


// address=[0x2f55890]
// Decompiled from bool __stdcall CMaterialManagerTask::IsSingleChainProduction(int a1)
bool  CMaterialManagerTask::IsSingleChainProduction(enum PILE_TYPES a1) {
  
  return a1 == 11 || a1 == 32 || a1 == 37;
}


