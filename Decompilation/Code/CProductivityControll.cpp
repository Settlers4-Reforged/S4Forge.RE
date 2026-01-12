#include "CProductivityControll.h"

// Definitions for class CProductivityControll

// address=[0x2f57570]
// Decompiled from // public: __thiscall CProductivityControll::CProductivityControll(void)
CProductivityControll *__thiscall CProductivityControll::CProductivityControll(CProductivityControll *this)

 CProductivityControll::CProductivityControll(void) {
  
  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CProductivityControll::_vftable_;
  *((_BYTE *)this + 101) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 26) = 5;
  return this;
}


// address=[0x2f575b0]
// Decompiled from IScheduleEntry *__thiscall CProductivityControll::CProductivityControll(
        IScheduleEntry *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6)

 CProductivityControll::CProductivityControll(struct SBuildId,enum BUILDING_TYPES,int,int) {
  
  _BYTE v7[112]; // [esp+4h] [ebp-80h] BYREF
  IScheduleEntry *v8; // [esp+74h] [ebp-10h]
  int v9; // [esp+80h] [ebp-4h]

  v8 = this;
  IScheduleEntry::IScheduleEntry(this);
  v9 = 0;
  *(_DWORD *)v8 = &CProductivityControll::_vftable_;
  CProductivityControll::CProductivityControll(v7, a2, a3, a4, a5, a6);
  CProductivityControll::~CProductivityControll((CProductivityControll *)v7);
  return v8;
}


// address=[0x2f57630]
// Decompiled from int __thiscall CProductivityControll::CProductivityControll(int this, int a2, int a3, int a4, int a5, int a6)

 CProductivityControll::CProductivityControll(int,enum T_BUILD_LEVEL,enum BUILDING_TYPES,int,int) {
  
  IScheduleEntry::IScheduleEntry((IScheduleEntry *)this);
  *(_DWORD *)this = &CProductivityControll::_vftable_;
  *(_DWORD *)(this + 16) = 2;
  *(_DWORD *)(this + 20) = 2;
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 1;
  *(_DWORD *)(this + 60) = a6;
  *(_DWORD *)(this + 68) = a5;
  *(_DWORD *)(this + 72) = a5;
  *(_DWORD *)(this + 44) = a2;
  *(_DWORD *)(this + 48) = a3;
  *(_DWORD *)(this + 84) = a4;
  *(_BYTE *)(this + 89) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_BYTE *)(this + 100) = 0;
  *(_BYTE *)(this + 101) = 0;
  switch ( *(_DWORD *)(this + 84) )
  {
    case 0xE:
      *(_DWORD *)(this + 76) = 24;
      break;
    case 0xF:
      *(_DWORD *)(this + 76) = 24;
      break;
    case 0x10:
      *(_DWORD *)(this + 76) = 11;
      break;
    case 0x11:
      *(_DWORD *)(this + 76) = 9;
      break;
    case 0x12:
      *(_DWORD *)(this + 76) = 11;
      break;
    default:
      *(_DWORD *)(this + 76) = 0;
      break;
  }
  *(_DWORD *)(this + 80) = 0;
  *(_DWORD *)(this + 108) = 0;
  *(_DWORD *)(this + 104) = 5;
  return this;
}


// address=[0x2f57770]
// Decompiled from void __thiscall CProductivityControll::~CProductivityControll(CProductivityControll *this)

 CProductivityControll::~CProductivityControll(void) {
  
  *(_DWORD *)this = &CProductivityControll::_vftable_;
  IScheduleEntry::~IScheduleEntry(this);
}


// address=[0x2f57790]
// Decompiled from char __thiscall CProductivityControll::IsShooting(CProductivityControll *this)

bool  CProductivityControll::IsShooting(void) {
  
  char result; // al
  int v2; // eax
  struct IAIEcoManager *v3; // eax
  struct IAIEcoManager *v4; // [esp+20h] [ebp-48h]
  struct IAIEcoManager *v5; // [esp+24h] [ebp-44h]
  struct IAIEcoManager *v6; // [esp+28h] [ebp-40h]
  struct IAIEcoManager *v7; // [esp+2Ch] [ebp-3Ch]
  struct IAIEcoManager *EcoSector; // [esp+30h] [ebp-38h]
  struct IAIEcoManager *v9; // [esp+34h] [ebp-34h]
  struct IScheduleEntry *SpecialTask; // [esp+3Ch] [ebp-2Ch]
  int v11; // [esp+40h] [ebp-28h]
  int ContentOfWorkingArea; // [esp+40h] [ebp-28h]
  int v13; // [esp+40h] [ebp-28h]
  int v14; // [esp+44h] [ebp-24h] BYREF
  int v15; // [esp+48h] [ebp-20h] BYREF
  CProductivityControll *v16; // [esp+4Ch] [ebp-1Ch]
  char v17; // [esp+50h] [ebp-18h]
  char v18; // [esp+51h] [ebp-17h]
  char v19; // [esp+52h] [ebp-16h]
  char v20; // [esp+53h] [ebp-15h]
  char v21; // [esp+54h] [ebp-14h]
  char v22; // [esp+55h] [ebp-13h]
  char v23; // [esp+56h] [ebp-12h]
  char v24; // [esp+57h] [ebp-11h]
  char v25; // [esp+58h] [ebp-10h]
  char v26; // [esp+59h] [ebp-Fh]
  int v27; // [esp+64h] [ebp-4h]

  v16 = this;
  v14 = 0;
  v15 = 0;
  std::vector<SBuildId>::vector<SBuildId>();
  v27 = 0;
  SpecialTask = CSchedule::GetSpecialTask(*((CSchedule **)v16 + 10), 3);
  if ( *((_DWORD *)v16 + 12) == 1
    || (v9 = CSchedule::GetEcoSector(*((CSchedule **)v16 + 10)),
        (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v9 + 304))(
          v9,
          *((_DWORD *)v16 + 11))) )
  {
    if ( (int)--*((_DWORD *)v16 + 27) < 0 )
    {
      if ( *((_DWORD *)SpecialTask + 23) )
      {
        if ( *((_DWORD *)v16 + 12) != 1 )
        {
          EcoSector = CSchedule::GetEcoSector(*((CSchedule **)v16 + 10));
          if ( !(*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 84))(
                  EcoSector,
                  *((_DWORD *)v16 + 11)) )
          {
            v7 = CSchedule::GetEcoSector(*((CSchedule **)v16 + 10));
            if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, int))(*(_DWORD *)v7 + 56))(
                   v7,
                   *((_DWORD *)SpecialTask + 23),
                   10) > 3 )
            {
              v6 = CSchedule::GetEcoSector(*((CSchedule **)v16 + 10));
              if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, int))(*(_DWORD *)v6 + 56))(
                     v6,
                     *((_DWORD *)SpecialTask + 23),
                     20) > 3 )
              {
                *((_BYTE *)v16 + 101) = 0;
                *((_DWORD *)v16 + 27) = 60;
              }
            }
          }
        }
      }
    }
    if ( (int)--*((_DWORD *)v16 + 14) <= 0 )
    {
      *((_DWORD *)v16 + 14) = 1;
      CProductivityControll::PileDistribution(v16);
      CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v16 + 10), *((_DWORD *)v16 + 17), &v14, &v15);
      v2 = CProductivityControll::CalcPotentialOutput(v16);
      *((_DWORD *)v16 + 16) = v2;
      switch ( *((_DWORD *)v16 + 21) )
      {
        case 1:
        case 7:
          if ( *((_DWORD *)v16 + 12) == 1 )
            goto CProductivityControll__IsShooting___def_33579A4;
          CSchedule::SetBestWorkingAreaPosition(
            *((CSchedule **)v16 + 10),
            *((_DWORD *)v16 + 11),
            *((_DWORD *)v16 + 21),
            (int)&v14,
            (int)&v15);
          ContentOfWorkingArea = CSchedule::GetContentOfWorkingArea(
                                   *((_DWORD *)v16 + 10),
                                   *((_DWORD *)v16 + 21),
                                   v14,
                                   v15);
          if ( *((_DWORD *)v16 + 21) == 7 )
            goto CProductivityControll__IsShooting___def_33579A4;
          CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v16 + 10), *((_DWORD *)v16 + 17), &v14, &v15);
          if ( *((_BYTE *)v16 + 89)
            || CSchedule::ResourceNearAtWork(*((CSchedule **)v16 + 10), *((_DWORD *)v16 + 21), 2, v14, v15, 50)
            || ContentOfWorkingArea > CProductionDataTab::GetMinWorkLoad(
                                        *(void **)(*((_DWORD *)v16 + 10) + 40),
                                        *((_DWORD *)v16 + 21),
                                        *(_DWORD *)(*((_DWORD *)v16 + 10) + 24)) )
          {
            goto CProductivityControll__IsShooting___def_33579A4;
          }
          v24 = 1;
          v27 = -1;
          std::vector<SBuildId>::~vector<SBuildId>();
          return v24;
        case 2:
          if ( *((_DWORD *)v16 + 12) == 3 )
          {
            v13 = CSchedule::GetContentOfWorkingArea(*((_DWORD *)v16 + 10), 1, v14, v15);
            if ( v13 > CProductionDataTab::GetMaxWorkLoad(
                         *(void **)(*((_DWORD *)v16 + 10) + 40),
                         *((_DWORD *)v16 + 21),
                         *(_DWORD *)(*((_DWORD *)v16 + 10) + 24))
              && !*((_BYTE *)v16 + 89) )
            {
              *((_BYTE *)v16 + 89) = 1;
              v5 = CSchedule::GetEcoSector(*((CSchedule **)v16 + 10));
              (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v5 + 276))(v5, *((_DWORD *)v16 + 11));
            }
            if ( v13 < CProductionDataTab::GetMinWorkLoad(
                         *(void **)(*((_DWORD *)v16 + 10) + 40),
                         *((_DWORD *)v16 + 21),
                         *(_DWORD *)(*((_DWORD *)v16 + 10) + 24))
              && *((_BYTE *)v16 + 89) )
            {
              *((_BYTE *)v16 + 89) = 0;
              v4 = CSchedule::GetEcoSector(*((CSchedule **)v16 + 10));
              (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v4 + 276))(v4, *((_DWORD *)v16 + 11));
            }
          }
          goto CProductivityControll__IsShooting___def_33579A4;
        case 4:
        case 5:
        case 6:
          if ( *((_DWORD *)v16 + 12) == 1 )
            goto LABEL_19;
          if ( CSchedule::SetBestWorkingAreaPosition(
                 *((CSchedule **)v16 + 10),
                 *((_DWORD *)v16 + 11),
                 *((_DWORD *)v16 + 21),
                 (int)&v14,
                 (int)&v15) )
          {
            goto CProductivityControll__IsShooting___def_33579A4;
          }
          CReserveDatabase::PackPosition(**((CReserveDatabase ***)v16 + 10), v14, v15);
          if ( *((_DWORD *)v16 + 12) == 3
            && (v11 = CSchedule::GetContentOfWorkingArea(
                        *((CSchedule **)v16 + 10),
                        *((_DWORD *)v16 + 11),
                        *((_DWORD *)v16 + 21)),
                v11 <= CProductionDataTab::GetMinWorkLoad(
                         *(void **)(*((_DWORD *)v16 + 10) + 40),
                         *((_DWORD *)v16 + 21),
                         *(_DWORD *)(*((_DWORD *)v16 + 10) + 24))) )
          {
            v26 = 1;
            v27 = -1;
            std::vector<SBuildId>::~vector<SBuildId>();
            result = v26;
          }
          else
          {
LABEL_19:
            v25 = 0;
            v27 = -1;
            std::vector<SBuildId>::~vector<SBuildId>();
            result = v25;
          }
          break;
        case 0xA:
        case 0xC:
          if ( CSchedule::EnoughNumberOfBuildingType(*((void **)v16 + 10), 5)
            || *((_BYTE *)v16 + 89)
            || CSchedule::ResourceNearAtWork(*((CSchedule **)v16 + 10), *((_DWORD *)v16 + 21), 5, v14, v15, 150) )
          {
            goto CProductivityControll__IsShooting___def_33579A4;
          }
          v21 = 1;
          v27 = -1;
          std::vector<SBuildId>::~vector<SBuildId>();
          return v21;
        case 0xB:
        case 0x24:
          if ( *((_DWORD *)v16 + 12) == 3 )
            CSchedule::SetSpecialWorkingAreaPosition(
              *((CSchedule **)v16 + 10),
              *((_DWORD *)v16 + 11),
              *((_DWORD *)v16 + 21),
              (int)&v14,
              (int)&v15,
              0);
          goto CProductivityControll__IsShooting___def_33579A4;
        case 0xE:
        case 0xF:
        case 0x10:
        case 0x11:
        case 0x12:
          *((_DWORD *)v16 + 24) = 0;
          if ( *((_DWORD *)v16 + 12) != 3 || CProductivityControll::CheckProductivity(v16) )
          {
            if ( *((_DWORD *)v16 + 12) == 1
              || CSchedule::GetContentOfWorkingArea(
                   *((CSchedule **)v16 + 10),
                   *((_DWORD *)v16 + 11),
                   *((_DWORD *)v16 + 21)) )
            {
CProductivityControll__IsShooting___def_33579A4:
              v17 = 0;
              v27 = -1;
              std::vector<SBuildId>::~vector<SBuildId>();
              result = v17;
            }
            else
            {
              *((_DWORD *)v16 + 24) = 2;
              v22 = 1;
              v27 = -1;
              std::vector<SBuildId>::~vector<SBuildId>();
              result = v22;
            }
          }
          else
          {
            v23 = 0;
            v27 = -1;
            std::vector<SBuildId>::~vector<SBuildId>();
            result = v23;
          }
          break;
        case 0x16:
          if ( (unsigned __int8)CBuildingManagerTask::IsBuildingAtPlanning(SpecialTask, 24)
            || *((_BYTE *)v16 + 89)
            || CSchedule::GetNumberOfBuildingType(*((_DWORD *)v16 + 10), 24) >= 1 )
          {
            goto CProductivityControll__IsShooting___def_33579A4;
          }
          v20 = 1;
          v27 = -1;
          std::vector<SBuildId>::~vector<SBuildId>();
          return v20;
        case 0x18:
          if ( *((_DWORD *)v16 + 12) == 3 && !*((_BYTE *)v16 + 89) )
          {
            v3 = CSchedule::GetEcoSector(*((CSchedule **)v16 + 10));
            (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int, int))(*(_DWORD *)v3 + 272))(
              v3,
              *((_DWORD *)v16 + 11),
              29,
              2);
            *((_BYTE *)v16 + 89) = 1;
          }
          goto CProductivityControll__IsShooting___def_33579A4;
        case 0x23:
          if ( *((_DWORD *)v16 + 12) == 3 )
            CSchedule::SetSpecialWorkingAreaPosition(
              *((CSchedule **)v16 + 10),
              *((_DWORD *)v16 + 11),
              *((_DWORD *)v16 + 21),
              (int)&v14,
              (int)&v15,
              0);
          goto LABEL_57;
        case 0x25:
        case 0x27:
LABEL_57:
          if ( (unsigned __int8)CBuildingManagerTask::IsBuildingAtPlanning(SpecialTask, 43)
            || *((_DWORD *)v16 + 12) == 1
            || *((_BYTE *)v16 + 89)
            || CSchedule::GetNumberOfBuildingType(*((_DWORD *)v16 + 10), 43) >= 1 )
          {
            goto CProductivityControll__IsShooting___def_33579A4;
          }
          v19 = 1;
          v27 = -1;
          std::vector<SBuildId>::~vector<SBuildId>();
          result = v19;
          break;
        case 0x2B:
          if ( (unsigned __int8)CBuildingManagerTask::IsBuildingAtPlanning(SpecialTask, 44)
            || CDebitLevelManager::DebitPreCondition(*(CDebitLevelManager **)(*((_DWORD *)v16 + 10) + 8), 9)
            || *((_DWORD *)v16 + 12) == 1
            || *((_BYTE *)v16 + 89)
            || CSchedule::GetNumberOfBuildingType(*((_DWORD *)v16 + 10), 44) >= 1 )
          {
            goto CProductivityControll__IsShooting___def_33579A4;
          }
          v18 = 1;
          v27 = -1;
          std::vector<SBuildId>::~vector<SBuildId>();
          result = v18;
          break;
        default:
          goto CProductivityControll__IsShooting___def_33579A4;
      }
    }
    else
    {
      v27 = -1;
      std::vector<SBuildId>::~vector<SBuildId>();
      return 0;
    }
  }
  else
  {
    *((_DWORD *)v16 + 5) = 3;
    v27 = -1;
    std::vector<SBuildId>::~vector<SBuildId>();
    return 0;
  }
  return result;
}


// address=[0x2f57f90]
// Decompiled from char __thiscall CProductivityControll::action(CReserveDatabase ***this)

bool  CProductivityControll::action(void) {
  
  CReserveDatabase **v1; // eax
  char result; // al
  CReserveDatabase **v3; // eax
  CReserveDatabase **v4; // eax
  CReserveDatabase **v5; // eax
  CReserveDatabase **v6; // eax
  int v7; // [esp+20h] [ebp-4Ch] BYREF
  int v8; // [esp+24h] [ebp-48h] BYREF
  struct IScheduleEntry *v9; // [esp+28h] [ebp-44h]
  void *v10; // [esp+2Ch] [ebp-40h]
  struct IScheduleEntry *v11; // [esp+30h] [ebp-3Ch]
  void *v12; // [esp+34h] [ebp-38h]
  struct IScheduleEntry *v13; // [esp+38h] [ebp-34h]
  void *v14; // [esp+3Ch] [ebp-30h]
  struct IScheduleEntry *v15; // [esp+40h] [ebp-2Ch]
  void *v16; // [esp+44h] [ebp-28h]
  struct IAIEcoManager *EcoSector; // [esp+48h] [ebp-24h]
  struct IScheduleEntry *v18; // [esp+4Ch] [ebp-20h]
  void *C; // [esp+50h] [ebp-1Ch]
  CReserveDatabase **v20; // [esp+54h] [ebp-18h]
  struct IScheduleEntry *SpecialTask; // [esp+58h] [ebp-14h]
  CReserveDatabase ***v22; // [esp+5Ch] [ebp-10h]
  int v23; // [esp+68h] [ebp-4h]

  v22 = this;
  v7 = 0;
  v8 = 0;
  SpecialTask = 0;
  CReserveDatabase::UnpackPosition(*this[10], this[17], &v7, &v8);
  v20 = v22[21];
  v20 = (CReserveDatabase **)((char *)v20 - 1);
  switch ( (unsigned int)v20 )
  {
    case 0u:
    case 6u:
      v22[23] = 0;
      C = operator new(0x70u);
      v23 = 0;
      if ( C )
        v18 = CMainProblemSolveEvent::CMainProblemSolveEvent((CMainProblemSolveEvent *)C, v22[3], 9, 2, v22[17], 0, 0);
      else
        v18 = 0;
      v23 = -1;
      v1 = (CReserveDatabase **)CSchedule::NewSchedEntry((CSchedule *)v22[10], v18);
      v22[8] = v1;
      SpecialTask = CSchedule::GetSpecialTask((CSchedule *)v22[10], 3);
      CBuildingManagerTask::SetBuildingAtPlanning(SpecialTask, 2);
      *((_BYTE *)v22 + 89) = 1;
      v22[5] = (CReserveDatabase **)1;
      goto CProductivityControll__action___def_335801D;
    case 3u:
    case 5u:
      BBSupportTracePrintF(
        3,
        "AI_BuildingEvent::PlayerNr %i destroy %s with ID %i",
        v22[10][5],
        (&off_3AC3FBC)[2 * (_DWORD)v22[21]],
        v22[11]);
      EcoSector = CSchedule::GetEcoSector((CSchedule *)v22[10]);
      (*(void (__thiscall **)(struct IAIEcoManager *, CReserveDatabase **))(*(_DWORD *)EcoSector + 104))(
        EcoSector,
        v22[11]);
      v22[5] = (CReserveDatabase **)3;
      goto CProductivityControll__action___def_335801D;
    case 9u:
    case 0xBu:
      v22[23] = 0;
      v16 = operator new(0x70u);
      v23 = 1;
      if ( v16 )
        v15 = CMainProblemSolveEvent::CMainProblemSolveEvent((CMainProblemSolveEvent *)v16, v22[3], 9, 5, v22[17], 0, 0);
      else
        v15 = 0;
      v23 = -1;
      v3 = (CReserveDatabase **)CSchedule::NewSchedEntry((CSchedule *)v22[10], v15);
      v22[8] = v3;
      SpecialTask = CSchedule::GetSpecialTask((CSchedule *)v22[10], 3);
      CBuildingManagerTask::SetBuildingAtPlanning(SpecialTask, 5);
      *((_BYTE *)v22 + 89) = 1;
      v22[5] = (CReserveDatabase **)1;
      goto CProductivityControll__action___def_335801D;
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      if ( v22[24] != (CReserveDatabase **)2 )
        goto CProductivityControll__action___def_335801D;
      result = 0;
      break;
    case 0x15u:
      v22[23] = 0;
      v14 = operator new(0x70u);
      v23 = 2;
      if ( v14 )
        v13 = CMainProblemSolveEvent::CMainProblemSolveEvent(
                (CMainProblemSolveEvent *)v14,
                v22[3],
                9,
                24,
                v22[17],
                0,
                0);
      else
        v13 = 0;
      v23 = -1;
      v4 = (CReserveDatabase **)CSchedule::NewSchedEntry((CSchedule *)v22[10], v13);
      v22[8] = v4;
      SpecialTask = CSchedule::GetSpecialTask((CSchedule *)v22[10], 3);
      CBuildingManagerTask::SetBuildingAtPlanning(SpecialTask, 24);
      *((_BYTE *)v22 + 89) = 1;
      v22[5] = (CReserveDatabase **)1;
      goto CProductivityControll__action___def_335801D;
    case 0x22u:
    case 0x24u:
    case 0x26u:
      v22[23] = 0;
      v12 = operator new(0x70u);
      v23 = 3;
      if ( v12 )
        v11 = CMainProblemSolveEvent::CMainProblemSolveEvent(
                (CMainProblemSolveEvent *)v12,
                v22[3],
                9,
                43,
                v22[17],
                0,
                0);
      else
        v11 = 0;
      v23 = -1;
      v5 = (CReserveDatabase **)CSchedule::NewSchedEntry((CSchedule *)v22[10], v11);
      v22[8] = v5;
      SpecialTask = CSchedule::GetSpecialTask((CSchedule *)v22[10], 3);
      CBuildingManagerTask::SetBuildingAtPlanning(SpecialTask, 43);
      *((_BYTE *)v22 + 89) = 1;
      v22[5] = (CReserveDatabase **)1;
      goto CProductivityControll__action___def_335801D;
    case 0x2Au:
      v22[23] = 0;
      v10 = operator new(0x70u);
      v23 = 4;
      if ( v10 )
        v9 = CMainProblemSolveEvent::CMainProblemSolveEvent((CMainProblemSolveEvent *)v10, v22[3], 9, 44, v22[17], 0, 0);
      else
        v9 = 0;
      v23 = -1;
      v6 = (CReserveDatabase **)CSchedule::NewSchedEntry((CSchedule *)v22[10], v9);
      v22[8] = v6;
      SpecialTask = CSchedule::GetSpecialTask((CSchedule *)v22[10], 3);
      CBuildingManagerTask::SetBuildingAtPlanning(SpecialTask, 44);
      *((_BYTE *)v22 + 89) = 1;
      v22[5] = (CReserveDatabase **)1;
      goto CProductivityControll__action___def_335801D;
    default:
CProductivityControll__action___def_335801D:
      result = 1;
      break;
  }
  return result;
}


// address=[0x2f58410]
// Decompiled from char __thiscall CProductivityControll::IsAlive(CProductivityControll *this)

bool  CProductivityControll::IsAlive(void) {
  
  struct IAIEcoManager *EcoSector; // [esp+0h] [ebp-8h]

  if ( *((_DWORD *)this + 12) == 1 )
    return 1;
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 304))(
         EcoSector,
         *((_DWORD *)this + 11)) )
  {
    return 1;
  }
  *((_DWORD *)this + 5) = 3;
  return 0;
}


// address=[0x2f58470]
// Decompiled from char __thiscall CProductivityControll::WaitFor(CProductivityControll *this)

bool  CProductivityControll::WaitFor(void) {
  
  if ( *((_DWORD *)this + 23) == 1 )
  {
    *((_DWORD *)this + 8) = 0;
    *((_BYTE *)this + 89) = 0;
    if ( (int)--*((_DWORD *)this + 26) < 1 )
      return 1;
  }
  else if ( *((_DWORD *)this + 23) == 2 )
  {
    *((_DWORD *)this + 8) = 0;
    *((_BYTE *)this + 89) = 0;
    if ( (int)--*((_DWORD *)this + 26) < 1 )
      return 1;
  }
  else
  {
    *((_DWORD *)this + 26) = 5;
  }
  return 0;
}


// address=[0x2f58500]
// Decompiled from int __thiscall CProductivityControll::CalcPotentialOutput(CProductivityControll *this)

int  CProductivityControll::CalcPotentialOutput(void) {
  
  int NeededFixTicks; // esi
  int v2; // edi
  int v4; // [esp+Ch] [ebp-1Ch] BYREF
  int v5; // [esp+10h] [ebp-18h] BYREF
  int v6; // [esp+14h] [ebp-14h] BYREF
  int v7; // [esp+18h] [ebp-10h] BYREF
  int v8; // [esp+1Ch] [ebp-Ch]
  int v9; // [esp+20h] [ebp-8h]
  CProductivityControll *v10; // [esp+24h] [ebp-4h]

  v10 = this;
  v8 = 0;
  v9 = *((_DWORD *)this + 21);
  if ( v9 != 1 && (v9 <= 3 || v9 > 6) )
    return CProductionDataTab::GetNeededFixTicks(
             *(void **)(*((_DWORD *)v10 + 10) + 40),
             *((_DWORD *)v10 + 21),
             *(_DWORD *)(*((_DWORD *)v10 + 10) + 24));
  CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v10 + 10), *((_DWORD *)v10 + 17), &v4, &v5);
  CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v10 + 10), *((_DWORD *)v10 + 18), &v6, &v7);
  NeededFixTicks = CProductionDataTab::GetNeededFixTicks(
                     *(void **)(*((_DWORD *)v10 + 10) + 40),
                     *((_DWORD *)v10 + 21),
                     *(_DWORD *)(*((_DWORD *)v10 + 10) + 24));
  v2 = 2
     * CProductionDataTab::GetNeededVarTicks(
         *(void **)(*((_DWORD *)v10 + 10) + 40),
         *((_DWORD *)v10 + 21),
         *(_DWORD *)(*((_DWORD *)v10 + 10) + 24));
  return CSchedule::CalcDistance(*((CSchedule **)v10 + 10), v4, v5, v6, v7) * v2 + NeededFixTicks;
}


// address=[0x2f58610]
// Decompiled from char __thiscall CProductivityControll::PileDistribution(CProductivityControll *this)

bool  CProductivityControll::PileDistribution(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-44h]
  int v9; // [esp-4h] [ebp-44h]
  struct IAIEcoManager *v10; // [esp+0h] [ebp-40h]
  struct IAIEcoManager *v11; // [esp+4h] [ebp-3Ch]
  struct IAIEcoManager *v12; // [esp+8h] [ebp-38h]
  struct IAIEcoManager *v13; // [esp+Ch] [ebp-34h]
  struct IAIEcoManager *v14; // [esp+10h] [ebp-30h]
  struct IAIEcoManager *v15; // [esp+14h] [ebp-2Ch]
  struct IAIEcoManager *v16; // [esp+18h] [ebp-28h]
  struct IAIEcoManager *v17; // [esp+1Ch] [ebp-24h]
  struct IAIEcoManager *EcoSector; // [esp+20h] [ebp-20h]
  int InputTypePile; // [esp+28h] [ebp-18h]
  int v20; // [esp+2Ch] [ebp-14h]
  int j; // [esp+30h] [ebp-10h]
  int i; // [esp+38h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    InputTypePile = CProductionDataTab::GetInputTypePile(
                      *(void **)(*((_DWORD *)this + 10) + 40),
                      *((_DWORD *)this + 21),
                      i,
                      *(_DWORD *)(*((_DWORD *)this + 10) + 24));
    if ( CSchedule::SharedPileType(InputTypePile) )
    {
      if ( *((_DWORD *)this + 12) == 3 )
      {
        EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, int))(*(_DWORD *)EcoSector + 56))(
               EcoSector,
               *((_DWORD *)this + 11),
               InputTypePile) < 3 )
        {
          v17 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
          v16 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
          v15 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
          v1 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v17 + 128))(v17, 0);
          v2 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v16 + 132))(v16, v1);
          v8 = CReserveDatabase::PackPosition(**((CReserveDatabase ***)this + 10), 5, v2);
          v3 = CReserveDatabase::PackPosition(
                 **((CReserveDatabase ***)this + 10),
                 *((_DWORD *)this + 21),
                 InputTypePile);
          (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v15 + 280))(v15, 5028, v3, v8);
          return 0;
        }
      }
    }
  }
  if ( *((_DWORD *)this + 12) != 3 )
    return 1;
  if ( !*((_DWORD *)this + 19) )
    return 1;
  v14 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, _DWORD))(*(_DWORD *)v14 + 56))(
         v14,
         *((_DWORD *)this + 11),
         *((_DWORD *)this + 19)) < 3 )
  {
    for ( j = 0; j < 3; ++j )
    {
      if ( j )
      {
        if ( j == 1 )
        {
          v20 = 24;
        }
        else if ( j == 2 )
        {
          v20 = 9;
        }
      }
      else
      {
        v20 = 11;
      }
      v13 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
      if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v13 + 144))(v13, v20) > 0 )
      {
        v12 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v11 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v10 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v5 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v12 + 128))(v12, 0);
        v6 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v11 + 132))(v11, v5);
        v9 = CReserveDatabase::PackPosition(**((CReserveDatabase ***)this + 10), 5, v6);
        v7 = CReserveDatabase::PackPosition(**((CReserveDatabase ***)this + 10), *((_DWORD *)this + 21), v20);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v10 + 280))(v10, 5028, v7, v9);
      }
    }
  }
  return 1;
}


// address=[0x2f588c0]
// Decompiled from // public: enum BUILDING_TYPES __thiscall CProductivityControll::GetFoodBuilding(enum BUILDING_TYPES)
int __stdcall CProductivityControll::GetFoodBuilding(int a1)

enum BUILDING_TYPES  CProductivityControll::GetFoodBuilding(enum BUILDING_TYPES) {
  
  int result; // eax

  switch ( a1 )
  {
    case 14:
      result = 7;
      break;
    case 15:
      result = 8;
      break;
    case 16:
      result = 6;
      break;
    case 17:
      result = 10;
      break;
    case 18:
      result = 10;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x2f58930]
// Decompiled from char __thiscall CProductivityControll::CheckProductivity(CProductivityControll *this)

bool  CProductivityControll::CheckProductivity(void) {
  
  struct IAIEcoManager *EcoSector; // [esp+4h] [ebp-8h]

  if ( CSchedule::GetSumResourceAmount(*((_DWORD *)this + 10), *((_DWORD *)this + 21), *((_DWORD *)this + 17), 0, 1) >= 3 )
    return 1;
  BBSupportTracePrintF(
    3,
    "AI_BuildingEvent::PlayerNr %i destroy %s with ID %i",
    *(_DWORD *)(*((_DWORD *)this + 10) + 20),
    (&off_3AC3FBC)[2 * *((_DWORD *)this + 21)],
    *((_DWORD *)this + 11));
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 104))(
    EcoSector,
    *((_DWORD *)this + 11));
  *((_DWORD *)this + 5) = 3;
  return 0;
}


