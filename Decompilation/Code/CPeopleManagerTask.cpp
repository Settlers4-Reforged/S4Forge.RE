#include "CPeopleManagerTask.h"

// Definitions for class CPeopleManagerTask

// address=[0x2f56aa0]
// Decompiled from CPeopleManagerTask *__thiscall CPeopleManagerTask::CPeopleManagerTask(CPeopleManagerTask *this)

 CPeopleManagerTask::CPeopleManagerTask(void) {
  
  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CPeopleManagerTask::_vftable_;
  *((_DWORD *)this + 4) = 8;
  *((_DWORD *)this + 5) = 2;
  *((_BYTE *)this + 60) = 1;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 16) = 0;
  return this;
}


// address=[0x2f56b00]
// Decompiled from void __thiscall CPeopleManagerTask::~CPeopleManagerTask(CPeopleManagerTask *this)

 CPeopleManagerTask::~CPeopleManagerTask(void) {
  
  *(_DWORD *)this = &CPeopleManagerTask::_vftable_;
  IScheduleEntry::~IScheduleEntry(this);
}


// address=[0x2f56b20]
// Decompiled from char __thiscall CPeopleManagerTask::IsShooting(CSchedule **this)

bool  CPeopleManagerTask::IsShooting(void) {
  
  int v2; // [esp+8h] [ebp-48h]
  int NeededCarierSettler; // [esp+Ch] [ebp-44h]
  struct IAIEcoManager *v4; // [esp+10h] [ebp-40h]
  int v5; // [esp+14h] [ebp-3Ch]
  int v6; // [esp+18h] [ebp-38h]
  struct IAIEcoManager *v7; // [esp+1Ch] [ebp-34h]
  int v8; // [esp+20h] [ebp-30h]
  int v9; // [esp+24h] [ebp-2Ch]
  struct IAIEcoManager *v10; // [esp+28h] [ebp-28h]
  struct IAIEcoManager *v11; // [esp+2Ch] [ebp-24h]
  struct IAIEcoManager *EcoSector; // [esp+30h] [ebp-20h]
  int v13; // [esp+34h] [ebp-1Ch]
  int NeededBuildingSettler; // [esp+44h] [ebp-Ch]
  char v16; // [esp+4Fh] [ebp-1h]

  v16 = 0;
  EcoSector = CSchedule::GetEcoSector(this[10]);
  v9 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 152))(EcoSector, 2);
  v11 = CSchedule::GetEcoSector(this[10]);
  v6 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v11 + 152))(v11, 3);
  v10 = CSchedule::GetEcoSector(this[10]);
  v2 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v10 + 152))(v10, 1);
  NeededCarierSettler = CPeopleManagerTask::GetNeededCarierSettler((CPeopleManagerTask *)this);
  NeededBuildingSettler = CPeopleManagerTask::GetNeededBuildingSettler((CPeopleManagerTask *)this, NeededCarierSettler);
  CPeopleManagerTask::DestroyResidenceBuildings((CPeopleManagerTask *)this);
  CPeopleManagerTask::SetMinimumCarrier((CPeopleManagerTask *)this);
  this[11] = 0;
  this[13] = 0;
  if ( NeededBuildingSettler > v9 )
    v8 = NeededBuildingSettler - v9;
  else
    v8 = 0;
  if ( v8 > 0 )
  {
    v7 = CSchedule::GetEcoSector(this[10]);
    if ( v8 - (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v7 + 144))(v7, 31) > 0 )
      this[11] = (CSchedule *)((unsigned int)this[11] | 1);
  }
  if ( NeededBuildingSettler > v6 )
    v5 = NeededBuildingSettler - v6;
  else
    v5 = 0;
  if ( v5 > 0 )
  {
    v4 = CSchedule::GetEcoSector(this[10]);
    (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v4 + 144))(v4, 18);
    this[11] = (CSchedule *)((unsigned int)this[11] | 2);
  }
  v13 = v5 + v8;
  if ( v5 + v8 > 10 )
    v13 = 10;
  if ( v2 >= NeededCarierSettler + v13 || this[8] )
    return v16;
  this[11] = (CSchedule *)((unsigned int)this[11] | 4);
  return 1;
}


// address=[0x2f56d00]
// Decompiled from char __thiscall CPeopleManagerTask::action(CPeopleManagerTask *this)

bool  CPeopleManagerTask::action(void) {
  
  struct IScheduleEntry *v2; // [esp+8h] [ebp-1Ch]
  CMainProblemSolveEvent *C; // [esp+Ch] [ebp-18h]
  int GoodPositionForBuilding; // [esp+10h] [ebp-14h]

  if ( *((_DWORD *)this + 11) != (*((_DWORD *)this + 11) | 4) )
    return 1;
  GoodPositionForBuilding = CSchedule::GetGoodPositionForBuilding(*((CSchedule **)this + 10), 40);
  *((_DWORD *)this + 14) = CSchedule::GetResidenceBuildingLevel(*((CSchedule **)this + 10));
  C = (CMainProblemSolveEvent *)operator new(0x70u);
  if ( C )
    v2 = CMainProblemSolveEvent::CMainProblemSolveEvent(
           C,
           *((_DWORD *)this + 3),
           9,
           *((_DWORD *)this + 14),
           GoodPositionForBuilding,
           0,
           0);
  else
    v2 = 0;
  *((_DWORD *)this + 8) = CSchedule::NewSchedEntry(*((CSchedule **)this + 10), v2);
  *((_DWORD *)this + 5) = 1;
  *((_DWORD *)this + 13) = 0;
  *((_BYTE *)this + 60) = 0;
  *((_DWORD *)this + 16) = 200;
  return 1;
}


// address=[0x2f56e10]
// Decompiled from char __thiscall CPeopleManagerTask::IsAlive(CPeopleManagerTask *this)

bool  CPeopleManagerTask::IsAlive(void) {
  
  return 1;
}


// address=[0x2f56e20]
// Decompiled from char __thiscall CPeopleManagerTask::WaitFor(CSchedule **this)

bool  CPeopleManagerTask::WaitFor(void) {
  
  struct IScheduleEntry *SpecialTask; // [esp+8h] [ebp-1Ch]
  struct IScheduleEntry *v3; // [esp+Ch] [ebp-18h]
  CExpandationEvent *C; // [esp+10h] [ebp-14h]

  SpecialTask = CSchedule::GetSpecialTask(this[10], 3);
  CPeopleManagerTask::SetMinimumCarrier((CPeopleManagerTask *)this);
  CPeopleManagerTask::ExistNotEmptyResidence((CPeopleManagerTask *)this);
  if ( !this[13] )
    return 0;
  if ( this[13] != (CSchedule *)1 )
  {
    if ( CBuildingManagerTask::IsRejectedBuilding(SpecialTask, 41, 1)
      || CBuildingManagerTask::IsRejectedBuilding(SpecialTask, 42, 1) )
    {
      *((_BYTE *)this + 60) = 1;
    }
    if ( this[13] != (CSchedule *)2 )
      return 0;
    this[16] = (CSchedule *)((char *)this[16] - 1);
    if ( !*((_BYTE *)this + 60) )
      return 0;
    this[8] = 0;
    return 1;
  }
  if ( !this[8] || CSchedule::IsAnyExpandation((CDynList **)this[10]) )
    return 1;
  C = (CExpandationEvent *)operator new(0x74u);
  if ( C )
    v3 = CExpandationEvent::CExpandationEvent(C, this[3], 0, -3);
  else
    v3 = 0;
  this[8] = (CSchedule *)CSchedule::NewSchedEntry(this[10], v3);
  return 1;
}


// address=[0x2f56f70]
// Decompiled from int __thiscall CPeopleManagerTask::GetNeededCarierSettler(CSchedule **this)

int  CPeopleManagerTask::GetNeededCarierSettler(void) {
  
  int v1; // esi
  int v2; // edi
  int NumberOfBuildingType; // ebx
  int v5; // [esp+10h] [ebp-10h]
  struct IAIEcoManager *EcoSector; // [esp+14h] [ebp-Ch]
  struct IAIEcoManager *v7; // [esp+18h] [ebp-8h]

  EcoSector = CSchedule::GetEcoSector(this[10]);
  v7 = CSchedule::GetEcoSector(this[10]);
  v1 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v7 + 144))(v7, 8);
  v2 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 144))(EcoSector, 34);
  NumberOfBuildingType = CSchedule::GetNumberOfBuildingType(this[10], 1);
  v5 = CSchedule::GetNumberOfBuildingType(this[10], 4);
  return v1 + 10 * (NumberOfBuildingType + v5 + CSchedule::GetNumberOfBuildingType(this[10], 17)) + v2 + 20;
}


// address=[0x2f57010]
// Decompiled from int __thiscall CPeopleManagerTask::GetNeededBuildingSettler(CPeopleManagerTask *this, int a2)

int  CPeopleManagerTask::GetNeededBuildingSettler(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = (a2 - 20) / 6 + 5;
  if ( v3 < 5 )
    return 5;
  if ( v3 > 15 )
    return 15;
  return v3;
}


// address=[0x2f57060]
// Decompiled from char __thiscall CPeopleManagerTask::DestroyResidenceBuildings(CPeopleManagerTask *this)

bool  CPeopleManagerTask::DestroyResidenceBuildings(void) {
  
  _DWORD *v1; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  int v5; // [esp+4h] [ebp-74h]
  _BYTE v6[16]; // [esp+Ch] [ebp-6Ch] BYREF
  struct IAIEcoManager *v7; // [esp+1Ch] [ebp-5Ch]
  struct IAIEcoManager *v8; // [esp+20h] [ebp-58h]
  struct IAIEcoManager *v9; // [esp+24h] [ebp-54h]
  struct IAIEcoManager *v10; // [esp+28h] [ebp-50h]
  int v11; // [esp+2Ch] [ebp-4Ch]
  struct IAIEcoManager *v12; // [esp+30h] [ebp-48h]
  struct IAIEcoManager *v13; // [esp+34h] [ebp-44h]
  struct IAIEcoManager *v14; // [esp+38h] [ebp-40h]
  struct IAIEcoManager *v15; // [esp+3Ch] [ebp-3Ch]
  struct IAIEcoManager *EcoSector; // [esp+40h] [ebp-38h]
  int i; // [esp+44h] [ebp-34h]
  char v18; // [esp+4Ah] [ebp-2Eh]
  char v19; // [esp+4Bh] [ebp-2Dh]
  CPeopleManagerTask *v20; // [esp+4Ch] [ebp-2Ch]
  _DWORD v21[3]; // [esp+50h] [ebp-28h]
  _DWORD v22[3]; // [esp+5Ch] [ebp-1Ch]
  int v23; // [esp+74h] [ebp-4h]

  v20 = this;
  v11 = 0;
  std::vector<int>::vector<int>(v6);
  v23 = 0;
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
  v5 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)EcoSector + 284))(EcoSector) + 50;
  v15 = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
  v11 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v15 + 288))(v15) - v5;
  v14 = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
  v21[0] = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v14 + 88))(v14, 40);
  v13 = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
  v21[1] = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v13 + 88))(v13, 41);
  v12 = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
  v21[2] = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v12 + 88))(v12, 42);
  v22[0] = 40;
  v22[1] = 41;
  v22[2] = 42;
  for ( i = 0; i < 3; ++i )
  {
    if ( v11 > v21[i] )
    {
      v10 = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
      if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v10 + 156))(v10, v22[i]) > 0 )
      {
        std::vector<int>::clear();
        v9 = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
        (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, _BYTE *))(*(_DWORD *)v9 + 160))(v9, v22[i], v6);
        if ( std::vector<int>::size(v6) )
        {
          v8 = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
          v1 = (_DWORD *)std::vector<int>::operator[](0);
          if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v8 + 76))(v8, *v1) )
          {
            v2 = (_DWORD *)std::vector<int>::operator[](0);
            BBSupportTracePrintF(
              3,
              "AI_BuildingEvent::PlayerNr %i destroy %s with ID %i",
              *(_DWORD *)(*((_DWORD *)v20 + 10) + 20),
              (&off_3AC3FBC)[2 * v22[i]],
              *v2);
            v7 = CSchedule::GetEcoSector(*((CSchedule **)v20 + 10));
            v3 = (_DWORD *)std::vector<int>::operator[](0);
            (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v7 + 104))(v7, *v3);
            v19 = 1;
            v23 = -1;
            std::vector<int>::~vector<int>();
            return v19;
          }
        }
      }
    }
  }
  v18 = 0;
  v23 = -1;
  std::vector<int>::~vector<int>();
  return v18;
}


// address=[0x2f57310]
// Decompiled from int __thiscall CPeopleManagerTask::SetMinimumCarrier(CPeopleManagerTask *this)

void  CPeopleManagerTask::SetMinimumCarrier(void) {
  
  int NumberOfBuildingTypeAtWork; // esi
  int v2; // esi
  struct IAIEcoManager *v4; // [esp+4h] [ebp-18h]
  struct IAIEcoManager *v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  struct IAIEcoManager *EcoSector; // [esp+10h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-4h]

  NumberOfBuildingTypeAtWork = CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 17);
  v2 = CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 4) + NumberOfBuildingTypeAtWork;
  v9 = 7 * (CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 1) + v2) + 10;
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  v6 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 152))(EcoSector, 1);
  if ( v6 - v9 < 10 )
    v9 = v6 - 10;
  if ( v9 < 5 )
    v9 = 5;
  if ( v9 > 80 )
    v9 = 80;
  v5 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  (*(void (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v5 + 320))(v5, 12);
  v4 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  return (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v4 + 312))(v4, v9);
}


// address=[0x2f573f0]
// Decompiled from char __thiscall CPeopleManagerTask::ExistNotEmptyResidence(CPeopleManagerTask *this)

bool  CPeopleManagerTask::ExistNotEmptyResidence(void) {
  
  unsigned int v1; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _BYTE v5[16]; // [esp+4h] [ebp-48h] BYREF
  struct IAIEcoManager *v6; // [esp+14h] [ebp-38h]
  struct IAIEcoManager *v7; // [esp+18h] [ebp-34h]
  struct IAIEcoManager *EcoSector; // [esp+1Ch] [ebp-30h]
  int i; // [esp+20h] [ebp-2Ch]
  CPeopleManagerTask *v10; // [esp+24h] [ebp-28h]
  unsigned int j; // [esp+28h] [ebp-24h]
  char v12; // [esp+2Fh] [ebp-1Dh]
  _DWORD v13[3]; // [esp+30h] [ebp-1Ch]
  int v14; // [esp+48h] [ebp-4h]

  v10 = this;
  std::vector<int>::vector<int>(v5);
  v14 = 0;
  v13[0] = 40;
  v13[1] = 41;
  v13[2] = 42;
  std::vector<int>::clear();
  for ( i = 0; i < 3; ++i )
  {
    EcoSector = CSchedule::GetEcoSector(*((CSchedule **)v10 + 10));
    (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, _BYTE *))(*(_DWORD *)EcoSector + 160))(
      EcoSector,
      v13[i],
      v5);
    for ( j = 0; ; ++j )
    {
      v1 = std::vector<int>::size(v5);
      if ( j >= v1 )
        break;
      v7 = CSchedule::GetEcoSector(*((CSchedule **)v10 + 10));
      v2 = (_DWORD *)std::vector<int>::operator[](j);
      if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v7 + 68))(v7, *v2) >= 100 )
      {
        v6 = CSchedule::GetEcoSector(*((CSchedule **)v10 + 10));
        v3 = (_DWORD *)std::vector<int>::operator[](j);
        if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v6 + 92))(v6, *v3) <= 0 )
          continue;
      }
      *((_BYTE *)v10 + 60) = 0;
    }
  }
  std::vector<int>::clear();
  v12 = *((_BYTE *)v10 + 60);
  v14 = -1;
  std::vector<int>::~vector<int>();
  return v12;
}


