#include "CResourceManagerTask.h"

// Definitions for class CResourceManagerTask

// address=[0x2f558c0]
// Decompiled from IScheduleEntry *__thiscall CResourceManagerTask::CResourceManagerTask(IScheduleEntry *this)
 CResourceManagerTask::CResourceManagerTask(void) {
  
  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CResourceManagerTask::_vftable_;
  return this;
}


// address=[0x2f558e0]
// Decompiled from CResourceManagerTask *__thiscall CResourceManagerTask::CResourceManagerTask(CResourceManagerTask *this, int a2)
 CResourceManagerTask::CResourceManagerTask(int) {
  
  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CResourceManagerTask::_vftable_;
  *((_DWORD *)this + 4) = 5;
  *((_DWORD *)this + 11) = a2;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 5) = 2;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 12) = 100;
  *((_DWORD *)this + 8) = 0;
  *((_BYTE *)this + 88) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 200;
  if ( *((_DWORD *)this + 11) == 96 )
    *((_DWORD *)this + 12) = 40;
  else
    *((_DWORD *)this + 12) = 0;
  return this;
}


// address=[0x2f559a0]
// Decompiled from void __thiscall CResourceManagerTask::~CResourceManagerTask(CDynList **this)
 CResourceManagerTask::~CResourceManagerTask(void) {
  
  *this = (CDynList *)&CResourceManagerTask::_vftable_;
  if ( this[19] )
    CDynList::`scalar deleting destructor'(this[19], 1u);
  if ( this[21] )
    (**(void (__thiscall ***)(CDynList *, int))this[21])(this[21], 1);
  this[18] = 0;
  IScheduleEntry::~IScheduleEntry((IScheduleEntry *)this);
}


// address=[0x2f55a40]
// Decompiled from int __thiscall CResourceManagerTask::ClearBuildingPlaces(int this)
void  CResourceManagerTask::ClearBuildingPlaces(void) {
  
  int result; // eax

  while ( CDynList::size(*(CDynList **)(this + 76)) > 0 )
    CDynList::delElement(*(CDynList **)(this + 76), 0);
  *(_DWORD *)(this + 56) = 0;
  result = this;
  *(_DWORD *)(this + 64) = 0;
  return result;
}


// address=[0x2f55a80]
// Decompiled from int __thiscall CResourceManagerTask::NewBuildingPlace(CDynList **this, int a2, int a3, int a4)
void  CResourceManagerTask::NewBuildingPlace(int,int,int) {
  
  int result; // eax
  struct CDynListEntry *v5; // [esp+8h] [ebp-24h]
  CResourceManagerTask::CBuildingPlace *C; // [esp+Ch] [ebp-20h]
  _DWORD *v8; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  char v10; // [esp+1Fh] [ebp-Dh]

  v10 = 0;
  for ( i = 0; ; ++i )
  {
    result = CDynList::size(this[19]);
    if ( i >= result )
      break;
    v8 = (_DWORD *)CDynList::elementAt(this[19], i);
    v8[3] = a2;
    v8[4] = a3;
    v8[5] = a4;
    v10 = 1;
  }
  if ( v10 )
    return result;
  C = (CResourceManagerTask::CBuildingPlace *)operator new(0x18u);
  if ( C )
    v5 = (struct CDynListEntry *)CResourceManagerTask::CBuildingPlace::CBuildingPlace(C, a2, a3, a4);
  else
    v5 = 0;
  return CDynList::addElement(this[19], v5);
}


// address=[0x2f55b70]
// Decompiled from int __thiscall CResourceManagerTask::UpdateBuildingPlaces(int this)
void  CResourceManagerTask::UpdateBuildingPlaces(void) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < CDynList::size(*(CDynList **)(this + 76)); ++i )
    CDynList::elementAt(*(CDynList **)(this + 76), i);
  result = this;
  ++*(_DWORD *)(this + 64);
  return result;
}


// address=[0x2f55bd0]
// Decompiled from char __thiscall CResourceManagerTask::AreaHasResource(CFilter **this, int a2, int a3)
bool  CResourceManagerTask::AreaHasResource(int,int) {
  
  struct IFilterEntry *FilterEntry; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this[21] + 2); ++i )
  {
    FilterEntry = CFilter::GetFilterEntry(this[21], i);
    if ( FilterEntry && a2 - *((_DWORD *)FilterEntry + 3) < 1 && a3 - *((_DWORD *)FilterEntry + 4) < 1 )
      return 1;
  }
  return 0;
}


// address=[0x2f55c50]
// Decompiled from int __thiscall CResourceManagerTask::FillRareBuildings(CDynList **this, struct CReserveEntry *a2, int a3)
int  CResourceManagerTask::FillRareBuildings(class CReserveEntry *,int) {
  
  _DWORD *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[19]); ++i )
  {
    v5 = (_DWORD *)CDynList::elementAt(this[19], i);
    *((_DWORD *)a2 + 11 * i + 11 * a3 + 8) = v5[3];
    *((_DWORD *)a2 + 11 * i + 11 * a3 + 9) = v5[4];
    *((_DWORD *)a2 + 11 * i + 11 * a3 + 7) = v5[5];
  }
  return i;
}


// address=[0x2f55ce0]
// Decompiled from char __thiscall CResourceManagerTask::IsShooting(CResourceManagerTask *this)
bool  CResourceManagerTask::IsShooting(void) {
  
  int BuildingForResource; // eax
  int v2; // eax
  unsigned int v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v12[2]; // [esp-10h] [ebp-104h] BYREF
  int v13; // [esp-8h] [ebp-FCh]
  int v14; // [esp-4h] [ebp-F8h]
  int v15; // [esp+0h] [ebp-F4h]
  int v16; // [esp+4h] [ebp-F0h]
  int v17; // [esp+8h] [ebp-ECh]
  int *v18; // [esp+Ch] [ebp-E8h]
  int v19; // [esp+10h] [ebp-E4h]
  _BYTE v20[16]; // [esp+14h] [ebp-E0h] BYREF
  int (__thiscall ***v21)(_DWORD, int); // [esp+24h] [ebp-D0h]
  struct IFilterEntry *v22; // [esp+28h] [ebp-CCh]
  int v23; // [esp+2Ch] [ebp-C8h]
  int ResourceConsumption; // [esp+30h] [ebp-C4h]
  int v25; // [esp+34h] [ebp-C0h]
  CFilter *v26; // [esp+38h] [ebp-BCh]
  struct IFilterEntry *v27; // [esp+3Ch] [ebp-B8h]
  CFilter *v28; // [esp+40h] [ebp-B4h]
  struct IScheduleEntry *v29; // [esp+44h] [ebp-B0h]
  struct IScheduleEntry *v30; // [esp+48h] [ebp-ACh]
  struct IScheduleEntry *v31; // [esp+4Ch] [ebp-A8h]
  struct IScheduleEntry *v32; // [esp+50h] [ebp-A4h]
  int v33; // [esp+54h] [ebp-A0h]
  _BYTE v34[16]; // [esp+58h] [ebp-9Ch] BYREF
  void *C; // [esp+68h] [ebp-8Ch]
  struct IFilterEntry *v36; // [esp+6Ch] [ebp-88h]
  void *v37; // [esp+70h] [ebp-84h]
  struct IAIEcoManager *v38; // [esp+74h] [ebp-80h]
  CFilter *v39; // [esp+78h] [ebp-7Ch]
  void *v40; // [esp+7Ch] [ebp-78h]
  struct IAIEcoManager *v41; // [esp+80h] [ebp-74h]
  struct IFilterEntry *v42; // [esp+84h] [ebp-70h]
  void *v43; // [esp+88h] [ebp-6Ch]
  CFilter *v44; // [esp+8Ch] [ebp-68h]
  void *v45; // [esp+90h] [ebp-64h]
  struct IAIEcoManager *EcoSector; // [esp+94h] [ebp-60h]
  struct IScheduleEntry *v47; // [esp+98h] [ebp-5Ch]
  void *v48; // [esp+9Ch] [ebp-58h]
  struct IScheduleEntry *v49; // [esp+A0h] [ebp-54h]
  void *v50; // [esp+A4h] [ebp-50h]
  struct IScheduleEntry *v51; // [esp+A8h] [ebp-4Ch]
  void *v52; // [esp+ACh] [ebp-48h]
  struct IScheduleEntry *v53; // [esp+B0h] [ebp-44h]
  _BYTE v54[16]; // [esp+B4h] [ebp-40h] BYREF
  int v55; // [esp+C4h] [ebp-30h]
  int v56; // [esp+C8h] [ebp-2Ch]
  int (__thiscall ***v57)(_DWORD, int); // [esp+CCh] [ebp-28h]
  int v58; // [esp+D0h] [ebp-24h]
  int v59; // [esp+D4h] [ebp-20h]
  char v60; // [esp+DBh] [ebp-19h]
  int TargetPosition; // [esp+DCh] [ebp-18h]
  unsigned int i; // [esp+E0h] [ebp-14h]
  CResourceManagerTask *v63; // [esp+E4h] [ebp-10h]
  int v64; // [esp+F0h] [ebp-4h]

  v63 = this;
  v59 = 0;
  std::vector<SRESOURCECONCENTRATIONDATA>::vector<SRESOURCECONCENTRATIONDATA>(v15);
  v64 = 1;
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::vector<SUNDERGROUNDCONCENTRATIONDATA>();
  std::vector<int>::vector<int>(v20);
  LOBYTE(v64) = 2;
  v16 = 0;
  v55 = 0;
  TargetPosition = 0;
  v19 = 0;
  if ( *((_DWORD *)v63 + 21) )
  {
    v21 = (int (__thiscall ***)(_DWORD, int))*((_DWORD *)v63 + 21);
    v57 = v21;
    if ( v21 )
      v33 = (**v57)(v57, 1);
    else
      v33 = 0;
    *((_DWORD *)v63 + 21) = 0;
  }
  BuildingForResource = CProductionDataTab::GetBuildingForResource(
                          *((_DWORD *)v63 + 11),
                          *(_DWORD *)(*((_DWORD *)v63 + 10) + 24));
  *((_DWORD *)v63 + 20) = BuildingForResource;
  std::vector<int>::clear();
  CSchedule::CollectWorkingArea(*((CReserveDatabase ***)v63 + 10), *((_DWORD *)v63 + 20), (int)v20);
  if ( *((_DWORD *)v63 + 11) == 112 && !CSchedule::EnoughNumberOfBuildingType(*((void **)v63 + 10), 7) )
  {
    --*((_DWORD *)v63 + 24);
    if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)v63 + 10), 22) > 0 && *((int *)v63 + 24) < 0 )
    {
      TargetPosition = CSchedule::GetTargetPosition(*((CSchedule **)v63 + 10), 24);
      C = operator new(0x70u);
      LOBYTE(v64) = 3;
      if ( C )
        v53 = CMainProblemSolveEvent::CMainProblemSolveEvent(
                (CMainProblemSolveEvent *)C,
                *((_DWORD *)v63 + 3),
                9,
                7,
                TargetPosition,
                0,
                0);
      else
        v53 = 0;
      v32 = v53;
      LOBYTE(v64) = 2;
      CSchedule::NewSchedEntry(*((CSchedule **)v63 + 10), v53);
      *((_DWORD *)v63 + 24) = 200;
    }
  }
  if ( *((_DWORD *)v63 + 11) == 80 && !CSchedule::EnoughNumberOfBuildingType(*((void **)v63 + 10), 14) )
  {
    --*((_DWORD *)v63 + 24);
    if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)v63 + 10), 22) > 0 && *((int *)v63 + 24) < 0 )
    {
      TargetPosition = CSchedule::GetTargetPosition(*((CSchedule **)v63 + 10), 24);
      v52 = operator new(0x70u);
      LOBYTE(v64) = 4;
      if ( v52 )
        v51 = CMainProblemSolveEvent::CMainProblemSolveEvent(
                (CMainProblemSolveEvent *)v52,
                *((_DWORD *)v63 + 3),
                9,
                14,
                TargetPosition,
                0,
                0);
      else
        v51 = 0;
      v31 = v51;
      LOBYTE(v64) = 2;
      CSchedule::NewSchedEntry(*((CSchedule **)v63 + 10), v51);
      *((_DWORD *)v63 + 24) = 200;
    }
  }
  if ( *((_DWORD *)v63 + 11) == 16
    && *(_DWORD *)(*((_DWORD *)v63 + 10) + 24) == 1
    && !CSchedule::EnoughNumberOfBuildingType(*((void **)v63 + 10), 25) )
  {
    --*((_DWORD *)v63 + 24);
    if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)v63 + 10), 44) > 0 && *((int *)v63 + 24) < 0 )
    {
      TargetPosition = CSchedule::GetTargetPosition(*((CSchedule **)v63 + 10), 22);
      v50 = operator new(0x70u);
      LOBYTE(v64) = 5;
      if ( v50 )
        v49 = CMainProblemSolveEvent::CMainProblemSolveEvent(
                (CMainProblemSolveEvent *)v50,
                *((_DWORD *)v63 + 3),
                9,
                25,
                TargetPosition,
                0,
                0);
      else
        v49 = 0;
      v30 = v49;
      LOBYTE(v64) = 2;
      CSchedule::NewSchedEntry(*((CSchedule **)v63 + 10), v49);
      *((_DWORD *)v63 + 24) = 200;
    }
  }
  if ( *((_DWORD *)v63 + 11) == 16
    && *(_DWORD *)(*((_DWORD *)v63 + 10) + 24) == 4
    && !CSchedule::EnoughNumberOfBuildingType(*((void **)v63 + 10), 28) )
  {
    --*((_DWORD *)v63 + 24);
    if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)v63 + 10), 44) > 0 && *((int *)v63 + 24) < 0 )
    {
      TargetPosition = CSchedule::GetTargetPosition(*((CSchedule **)v63 + 10), 22);
      v48 = operator new(0x70u);
      LOBYTE(v64) = 6;
      if ( v48 )
        v47 = CMainProblemSolveEvent::CMainProblemSolveEvent(
                (CMainProblemSolveEvent *)v48,
                *((_DWORD *)v63 + 3),
                9,
                28,
                TargetPosition,
                0,
                0);
      else
        v47 = 0;
      v29 = v47;
      LOBYTE(v64) = 2;
      CSchedule::NewSchedEntry(*((CSchedule **)v63 + 10), v47);
      *((_DWORD *)v63 + 24) = 200;
    }
  }
  v56 = *((_DWORD *)v63 + 11);
  if ( v56 == -6 || v56 > -5 && v56 <= -2 )
  {
    if ( *((_DWORD *)v63 + 11) == -4 )
      v59 = 1;
    if ( *((_DWORD *)v63 + 11) == -3 )
      v59 = 5;
    if ( *((_DWORD *)v63 + 11) == -2 )
      v59 = 6;
    if ( *((_DWORD *)v63 + 11) == -6 )
      v59 = 2;
    CProfile::Begin((CProfile *)&unk_4689998);
    EcoSector = CSchedule::GetEcoSector(*((CSchedule **)v63 + 10));
    v2 = (*(int (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)EcoSector + 248))(EcoSector, v59, v34);
    *((_DWORD *)v63 + 13) = v2;
    CProfile::End((CProfile *)&unk_4689998);
    v45 = operator new(0x18u);
    LOBYTE(v64) = 7;
    if ( v45 )
      v44 = CFilter::CFilter((CFilter *)v45, 8);
    else
      v44 = 0;
    v28 = v44;
    LOBYTE(v64) = 2;
    *((_DWORD *)v63 + 21) = v44;
    CProfile::Begin((CProfile *)&unk_4689998);
    for ( i = 0; ; ++i )
    {
      v3 = std::vector<SUNDERGROUNDCONCENTRATIONDATA>::size(v34);
      if ( i >= v3 )
        break;
      if ( *(__int16 *)(std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i) + 4) > 0 )
      {
        v43 = operator new(0x18u);
        LOBYTE(v64) = 8;
        if ( v43 )
        {
          v14 = *(__int16 *)(std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i) + 4);
          v13 = *(__int16 *)(std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i) + 8);
          v4 = std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i);
          v42 = CResourceFilter::CResourceFilter((CResourceFilter *)v43, *(__int16 *)(v4 + 6), v13, v14);
        }
        else
        {
          v42 = 0;
        }
        v27 = v42;
        LOBYTE(v64) = 2;
        CFilter::AddFilterEntry(*((CFilter **)v63 + 21), v42);
      }
    }
    std::vector<SUNDERGROUNDCONCENTRATIONDATA>::clear();
    CProfile::End((CProfile *)&unk_4689998);
  }
  else
  {
    v41 = CSchedule::GetEcoSector(*((CSchedule **)v63 + 10));
    v5 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, _BYTE *))(*(_DWORD *)v41 + 180))(
           v41,
           *((_DWORD *)v63 + 11),
           v54);
    *((_DWORD *)v63 + 13) = v5;
    v40 = operator new(0x18u);
    LOBYTE(v64) = 9;
    if ( v40 )
      v39 = CFilter::CFilter((CFilter *)v40, 8);
    else
      v39 = 0;
    v26 = v39;
    LOBYTE(v64) = 2;
    *((_DWORD *)v63 + 21) = v39;
    for ( i = 0; ; ++i )
    {
      v6 = std::vector<SRESOURCECONCENTRATIONDATA>::size(v54);
      if ( i >= v6 )
        break;
      v58 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i) + 4);
      v14 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i) + 8);
      v7 = std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i);
      v25 = CReserveDatabase::PackPosition(**((CReserveDatabase ***)v63 + 10), *(__int16 *)(v7 + 6), v14);
      v18 = v12;
      v17 = std::vector<int>::vector<int>(v20);
      ResourceConsumption = CSchedule::GetResourceConsumption(*((_DWORD *)v63 + 11), v25, v12[0], v12[1], v13, v14);
      v23 = ResourceConsumption;
      if ( *((_DWORD *)v63 + 11) == 112 || *((_DWORD *)v63 + 11) == 96 )
      {
        v14 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i) + 8);
        v8 = std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i);
        if ( CSchedule::IsBorderElement(*((CSchedule **)v63 + 10), *(__int16 *)(v8 + 6), v14) )
        {
          v38 = CSchedule::GetEcoSector(*((CSchedule **)v63 + 10));
          v14 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i) + 8);
          v9 = std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i);
          v58 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, _DWORD, int))(*(_DWORD *)v38 + 176))(
                  v38,
                  *((_DWORD *)v63 + 11),
                  *(__int16 *)(v9 + 6),
                  v14);
        }
      }
      v58 -= v23;
      if ( v58 > 0 )
      {
        v37 = operator new(0x18u);
        LOBYTE(v64) = 10;
        if ( v37 )
        {
          v14 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i) + 4);
          v13 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i) + 8);
          v10 = std::vector<SRESOURCECONCENTRATIONDATA>::operator[](i);
          v36 = CResourceFilter::CResourceFilter((CResourceFilter *)v37, *(__int16 *)(v10 + 6), v13, v14);
        }
        else
        {
          v36 = 0;
        }
        v22 = v36;
        LOBYTE(v64) = 2;
        CFilter::AddFilterEntry(*((CFilter **)v63 + 21), v36);
        v55 += v58;
      }
    }
    std::vector<SRESOURCECONCENTRATIONDATA>::clear();
  }
  CDynList::resize(*(CDynList **)(*((_DWORD *)v63 + 21) + 4));
  std::vector<int>::clear();
  if ( !*((_DWORD *)v63 + 8) )
  {
    if ( v55 >= *((_DWORD *)v63 + 12) )
    {
      *((_DWORD *)v63 + 23) = 0;
    }
    else if ( !*((_DWORD *)v63 + 23) )
    {
      *((_DWORD *)v63 + 23) = 1;
    }
  }
  v60 = 0;
  LOBYTE(v64) = 1;
  std::vector<int>::~vector<int>();
  LOBYTE(v64) = 0;
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::~vector<SUNDERGROUNDCONCENTRATIONDATA>();
  v64 = -1;
  std::vector<SRESOURCECONCENTRATIONDATA>::~vector<SRESOURCECONCENTRATIONDATA>(v15, v16);
  return v60;
}


// address=[0x2f56630]
// Decompiled from char __thiscall CResourceManagerTask::action(CDynList ***this)
bool  CResourceManagerTask::action(void) {
  
  struct IScheduleEntry *v2; // [esp+8h] [ebp-18h]
  CExpandationEvent *C; // [esp+Ch] [ebp-14h]

  if ( CSchedule::IsAnyExpandation(this[10]) )
    return 1;
  C = (CExpandationEvent *)operator new(0x74u);
  if ( C )
    v2 = CExpandationEvent::CExpandationEvent(C, this[3], 0, this[11]);
  else
    v2 = 0;
  this[8] = (CDynList **)CSchedule::NewSchedEntry((CSchedule *)this[10], v2);
  return 1;
}


// address=[0x2f566e0]
// Decompiled from char __thiscall CResourceManagerTask::IsAlive(CResourceManagerTask *this)
bool  CResourceManagerTask::IsAlive(void) {
  
  return 1;
}


// address=[0x2f566f0]
// Decompiled from char __thiscall CResourceManagerTask::WaitFor(CResourceManagerTask *this)
bool  CResourceManagerTask::WaitFor(void) {
  
  if ( *(_DWORD *)(CSchedule::GetInvokeEvent(*((_DWORD *)this + 10), *((_DWORD *)this + 20)) + 48) != 2 )
    return 1;
  *((_DWORD *)this + 9) = 1;
  return 0;
}


