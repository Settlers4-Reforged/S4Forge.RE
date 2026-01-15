#include "CSchedule.h"

// Definitions for class CSchedule

// address=[0x2f41e40]
// Decompiled from CSchedule *__thiscall CSchedule::CSchedule(CSchedule *this, struct CEcoSectorAI *a2, int a3, int a4)
 CSchedule::CSchedule(class CEcoSectorAI *,int,int) {
  
  CDebitLevelManager *v5; // [esp+8h] [ebp-18h]
  CDebitLevelManager *C; // [esp+Ch] [ebp-14h]

  *((_DWORD *)this + 7) = 1;
  *((_DWORD *)this + 5) = a3;
  *((_DWORD *)this + 6) = a4;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = a2;
  *(_DWORD *)this = *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 10) = *((_DWORD *)a2 + 5);
  C = (CDebitLevelManager *)operator new(0x328u);
  if ( C )
    v5 = CDebitLevelManager::CDebitLevelManager(C, this);
  else
    v5 = 0;
  *((_DWORD *)this + 2) = v5;
  CSchedule::InitSchedule(this);
  CSchedule::InitLevelManager(this);
  BBSupportTracePrintF(0, "Init CSchedule for Player %d", *((_DWORD *)this + 5));
  return this;
}


// address=[0x2f41f40]
// Decompiled from CDynList **__thiscall CSchedule::~CSchedule(CDynList **this)
 CSchedule::~CSchedule(void) {
  
  CDynList **result; // eax

  if ( this[1] )
    delete this[1];
  result = this;
  if ( this[2] )
    return (CDynList **)delete this[2];
  return result;
}


// address=[0x2f41fb0]
// Decompiled from int __thiscall CSchedule::InitSchedule(CSchedule *this)
void  CSchedule::InitSchedule(void) {
  
  struct IScheduleEntry *v2; // [esp+70h] [ebp-E8h]
  void *v3; // [esp+74h] [ebp-E4h]
  struct IScheduleEntry *v4; // [esp+78h] [ebp-E0h]
  void *v5; // [esp+7Ch] [ebp-DCh]
  struct IScheduleEntry *v6; // [esp+80h] [ebp-D8h]
  void *v7; // [esp+84h] [ebp-D4h]
  struct IScheduleEntry *v8; // [esp+88h] [ebp-D0h]
  void *v9; // [esp+8Ch] [ebp-CCh]
  struct IScheduleEntry *v10; // [esp+90h] [ebp-C8h]
  void *v11; // [esp+94h] [ebp-C4h]
  struct IScheduleEntry *v12; // [esp+98h] [ebp-C0h]
  void *v13; // [esp+9Ch] [ebp-BCh]
  struct IScheduleEntry *v14; // [esp+A0h] [ebp-B8h]
  void *v15; // [esp+A4h] [ebp-B4h]
  struct IScheduleEntry *v16; // [esp+A8h] [ebp-B0h]
  void *v17; // [esp+ACh] [ebp-ACh]
  struct IScheduleEntry *v18; // [esp+B0h] [ebp-A8h]
  void *v19; // [esp+B4h] [ebp-A4h]
  struct IScheduleEntry *v20; // [esp+B8h] [ebp-A0h]
  void *v21; // [esp+BCh] [ebp-9Ch]
  struct IScheduleEntry *v22; // [esp+C0h] [ebp-98h]
  void *v23; // [esp+C4h] [ebp-94h]
  struct IScheduleEntry *v24; // [esp+C8h] [ebp-90h]
  CResourceManagerTask *v25; // [esp+CCh] [ebp-8Ch]
  struct IScheduleEntry *v26; // [esp+D0h] [ebp-88h]
  CResourceManagerTask *v27; // [esp+D4h] [ebp-84h]
  struct IScheduleEntry *v28; // [esp+D8h] [ebp-80h]
  CResourceManagerTask *v29; // [esp+DCh] [ebp-7Ch]
  struct IScheduleEntry *v30; // [esp+E0h] [ebp-78h]
  CResourceManagerTask *v31; // [esp+E4h] [ebp-74h]
  struct IScheduleEntry *v32; // [esp+E8h] [ebp-70h]
  CResourceManagerTask *v33; // [esp+ECh] [ebp-6Ch]
  struct IScheduleEntry *v34; // [esp+F0h] [ebp-68h]
  CResourceManagerTask *v35; // [esp+F4h] [ebp-64h]
  struct IScheduleEntry *v36; // [esp+F8h] [ebp-60h]
  CResourceManagerTask *v37; // [esp+FCh] [ebp-5Ch]
  struct IScheduleEntry *v38; // [esp+100h] [ebp-58h]
  CResourceManagerTask *v39; // [esp+104h] [ebp-54h]
  struct IScheduleEntry *v40; // [esp+108h] [ebp-50h]
  CResourceManagerTask *v41; // [esp+10Ch] [ebp-4Ch]
  struct IScheduleEntry *v42; // [esp+110h] [ebp-48h]
  CResourceManagerTask *v43; // [esp+114h] [ebp-44h]
  struct IScheduleEntry *v44; // [esp+118h] [ebp-40h]
  CResourceManagerTask *v45; // [esp+11Ch] [ebp-3Ch]
  struct IScheduleEntry *v46; // [esp+120h] [ebp-38h]
  CResourceManagerTask *v47; // [esp+124h] [ebp-34h]
  struct IScheduleEntry *v48; // [esp+128h] [ebp-30h]
  CExpandationManagerTask *v49; // [esp+12Ch] [ebp-2Ch]
  struct IScheduleEntry *v50; // [esp+130h] [ebp-28h]
  CBuildingManagerTask *v51; // [esp+134h] [ebp-24h]
  struct IScheduleEntry *v52; // [esp+138h] [ebp-20h]
  CPeopleManagerTask *v53; // [esp+13Ch] [ebp-1Ch]
  CDynList *v54; // [esp+140h] [ebp-18h]
  CDynList *C; // [esp+144h] [ebp-14h]

  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 3) = 0;
  C = (CDynList *)operator new(0xCu);
  if ( C )
    v54 = CDynList::CDynList(C);
  else
    v54 = 0;
  *((_DWORD *)this + 1) = v54;
  v53 = (CPeopleManagerTask *)operator new(0x44u);
  if ( v53 )
    v52 = CPeopleManagerTask::CPeopleManagerTask(v53);
  else
    v52 = 0;
  CSchedule::NewSchedEntry(this, v52);
  v51 = (CBuildingManagerTask *)operator new(0x14Cu);
  if ( v51 )
    v50 = CBuildingManagerTask::CBuildingManagerTask(v51);
  else
    v50 = 0;
  CSchedule::NewSchedEntry(this, v50);
  v49 = (CExpandationManagerTask *)operator new(0x70u);
  if ( v49 )
    v48 = CExpandationManagerTask::CExpandationManagerTask(v49);
  else
    v48 = 0;
  CSchedule::NewSchedEntry(this, v48);
  v47 = (CResourceManagerTask *)operator new(0x64u);
  if ( v47 )
    v46 = CResourceManagerTask::CResourceManagerTask(v47, 112);
  else
    v46 = 0;
  CSchedule::NewSchedEntry(this, v46);
  v45 = (CResourceManagerTask *)operator new(0x64u);
  if ( v45 )
    v44 = CResourceManagerTask::CResourceManagerTask(v45, 96);
  else
    v44 = 0;
  CSchedule::NewSchedEntry(this, v44);
  v43 = (CResourceManagerTask *)operator new(0x64u);
  if ( v43 )
    v42 = CResourceManagerTask::CResourceManagerTask(v43, 0);
  else
    v42 = 0;
  CSchedule::NewSchedEntry(this, v42);
  v41 = (CResourceManagerTask *)operator new(0x64u);
  if ( v41 )
    v40 = CResourceManagerTask::CResourceManagerTask(v41, 16);
  else
    v40 = 0;
  CSchedule::NewSchedEntry(this, v40);
  v39 = (CResourceManagerTask *)operator new(0x64u);
  if ( v39 )
    v38 = CResourceManagerTask::CResourceManagerTask(v39, 32);
  else
    v38 = 0;
  CSchedule::NewSchedEntry(this, v38);
  v37 = (CResourceManagerTask *)operator new(0x64u);
  if ( v37 )
    v36 = CResourceManagerTask::CResourceManagerTask(v37, -3);
  else
    v36 = 0;
  CSchedule::NewSchedEntry(this, v36);
  v35 = (CResourceManagerTask *)operator new(0x64u);
  if ( v35 )
    v34 = CResourceManagerTask::CResourceManagerTask(v35, -4);
  else
    v34 = 0;
  CSchedule::NewSchedEntry(this, v34);
  v33 = (CResourceManagerTask *)operator new(0x64u);
  if ( v33 )
    v32 = CResourceManagerTask::CResourceManagerTask(v33, 48);
  else
    v32 = 0;
  CSchedule::NewSchedEntry(this, v32);
  v31 = (CResourceManagerTask *)operator new(0x64u);
  if ( v31 )
    v30 = CResourceManagerTask::CResourceManagerTask(v31, 64);
  else
    v30 = 0;
  CSchedule::NewSchedEntry(this, v30);
  v29 = (CResourceManagerTask *)operator new(0x64u);
  if ( v29 )
    v28 = CResourceManagerTask::CResourceManagerTask(v29, -2);
  else
    v28 = 0;
  CSchedule::NewSchedEntry(this, v28);
  v27 = (CResourceManagerTask *)operator new(0x64u);
  if ( v27 )
    v26 = CResourceManagerTask::CResourceManagerTask(v27, -6);
  else
    v26 = 0;
  CSchedule::NewSchedEntry(this, v26);
  v25 = (CResourceManagerTask *)operator new(0x64u);
  if ( v25 )
    v24 = CResourceManagerTask::CResourceManagerTask(v25, 80);
  else
    v24 = 0;
  CSchedule::NewSchedEntry(this, v24);
  v23 = operator new(0x44u);
  if ( v23 )
    v22 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v23, 32, 0);
  else
    v22 = 0;
  CSchedule::NewSchedEntry(this, v22);
  v21 = operator new(0x44u);
  if ( v21 )
    v20 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v21, 7, 0);
  else
    v20 = 0;
  CSchedule::NewSchedEntry(this, v20);
  v19 = operator new(0x44u);
  if ( v19 )
    v18 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v19, 34, 0);
  else
    v18 = 0;
  CSchedule::NewSchedEntry(this, v18);
  if ( *((_DWORD *)this + 6) == 2 )
  {
    v17 = operator new(0x44u);
    if ( v17 )
      v16 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v17, 35, 0);
    else
      v16 = 0;
    CSchedule::NewSchedEntry(this, v16);
  }
  if ( !*((_DWORD *)this + 6) )
  {
    v15 = operator new(0x44u);
    if ( v15 )
      v14 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v15, 37, 0);
    else
      v14 = 0;
    CSchedule::NewSchedEntry(this, v14);
  }
  if ( *((_DWORD *)this + 6) == 1 )
  {
    v13 = operator new(0x44u);
    if ( v13 )
      v12 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v13, 23, 0);
    else
      v12 = 0;
    CSchedule::NewSchedEntry(this, v12);
  }
  if ( *((_DWORD *)this + 6) == 4 )
  {
    v11 = operator new(0x44u);
    if ( v11 )
      v10 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v11, 41, 0);
    else
      v10 = 0;
    CSchedule::NewSchedEntry(this, v10);
  }
  v9 = operator new(0x44u);
  if ( v9 )
    v8 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v9, 14, 0);
  else
    v8 = 0;
  CSchedule::NewSchedEntry(this, v8);
  v7 = operator new(0x44u);
  if ( v7 )
    v6 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v7, 9, 0);
  else
    v6 = 0;
  CSchedule::NewSchedEntry(this, v6);
  v5 = operator new(0x44u);
  if ( v5 )
    v4 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v5, 24, 0);
  else
    v4 = 0;
  CSchedule::NewSchedEntry(this, v4);
  v3 = operator new(0x44u);
  if ( v3 )
    v2 = (struct IScheduleEntry *)CMaterialManagerTask::CMaterialManagerTask(v3, 11, 0);
  else
    v2 = 0;
  return CSchedule::NewSchedEntry(this, v2);
}


// address=[0x2f42970]
// Decompiled from int __thiscall CSchedule::InitLevelManager(CSchedule *this)
void  CSchedule::InitLevelManager(void) {
  
  if ( *((_DWORD *)this + 6) == 1 )
  {
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 32, 0, 0, 40, 0, 0, 10000, 0);
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 7, 0, 0, 160, 0, 0, 10000, 0);
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 23, 0, 0, 25, 20000, 4, 10000, 0);
  }
  if ( *((_DWORD *)this + 6) == 2 )
  {
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 32, 0, 0, 80, 0, 0, 10000, 0);
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 7, 0, 0, 102, 0, 0, 10000, 0);
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 35, 0, 0, 25, 20000, 4, 10000, 0);
  }
  if ( *((_DWORD *)this + 6) == 4 )
  {
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 32, 0, 0, 80, 0, 0, 10000, 0);
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 7, 0, 0, 102, 0, 0, 10000, 0);
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 41, 0, 0, 25, 20000, 4, 10000, 0);
  }
  if ( !*((_DWORD *)this + 6) )
  {
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 32, 0, 0, 60, 0, 0, 10000, 0);
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 7, 0, 0, 155, 0, 0, 10000, 0);
    CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 37, 0, 0, 25, 20000, 4, 10000, 0);
  }
  CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 34, 0, 0, 25, 4000, 2, 10000, 0);
  CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 14, 0, 0, 25, 5000, 3, 10000, 0);
  CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 9, 0, 0, 20, 5000, 5, 10000, 0);
  CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 24, 0, 0, 20, 5000, 6, 10000, 0);
  CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 11, 0, 0, 50, 5000, 2, 10000, 0);
  CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 34, 0, 1, 50, 10000, 3, 10000, 0);
  CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 34, 0, 2, 100, 12000, 9, 10000, 0);
  CDebitLevelManager::AddDebitLevel(*((_DWORD *)this + 2), *((_DWORD *)this + 6), 9, 0, 1, 40, 12000, 10, 10000, 0);
  return CDebitLevelManager::AddDebitLevel(
           *((_DWORD *)this + 2),
           *((_DWORD *)this + 6),
           24,
           0,
           1,
           40,
           12000,
           10,
           10000,
           0);
}


// address=[0x2f42ce0]
// Decompiled from int __thiscall CSchedule::Settings(CSchedule *this)
int  CSchedule::Settings(void) {
  
  unsigned int v1; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int v9; // [esp-10h] [ebp-80h]
  int v10; // [esp-Ch] [ebp-7Ch]
  int v11; // [esp-8h] [ebp-78h]
  _BYTE v12[16]; // [esp+4h] [ebp-6Ch] BYREF
  int v13; // [esp+14h] [ebp-5Ch]
  struct IScheduleEntry *v14; // [esp+18h] [ebp-58h]
  struct IScheduleEntry *v15; // [esp+1Ch] [ebp-54h]
  struct IAIEcoManager *v16; // [esp+20h] [ebp-50h]
  struct IAIEcoManager *v17; // [esp+24h] [ebp-4Ch]
  struct IScheduleEntry *v18; // [esp+28h] [ebp-48h]
  void *v19; // [esp+2Ch] [ebp-44h]
  int v20; // [esp+30h] [ebp-40h]
  int v21; // [esp+34h] [ebp-3Ch]
  struct IScheduleEntry *v22; // [esp+38h] [ebp-38h]
  void *C; // [esp+3Ch] [ebp-34h]
  int v24; // [esp+40h] [ebp-30h] BYREF
  int v25; // [esp+44h] [ebp-2Ch] BYREF
  struct IAIEcoManager *v26; // [esp+48h] [ebp-28h]
  struct IAIEcoManager *v27; // [esp+4Ch] [ebp-24h]
  struct IAIEcoManager *EcoSector; // [esp+50h] [ebp-20h]
  struct IScheduleEntry *SpecialTask; // [esp+54h] [ebp-1Ch]
  unsigned int j; // [esp+58h] [ebp-18h]
  int i; // [esp+5Ch] [ebp-14h]
  CSchedule *v32; // [esp+60h] [ebp-10h]
  int v33; // [esp+6Ch] [ebp-4h]

  v32 = this;
  std::vector<int>::vector<int>(v12);
  v33 = 0;
  SpecialTask = 0;
  for ( i = 1; dword_46878FC[15 * i]; ++i )
  {
    std::vector<int>::clear();
    EcoSector = CSchedule::GetEcoSector(v32);
    (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)EcoSector + 160))(
      EcoSector,
      dword_46878FC[15 * i],
      v12);
    for ( j = 0; ; ++j )
    {
      v1 = std::vector<int>::size(v12);
      if ( j >= v1 )
        break;
      v27 = CSchedule::GetEcoSector(v32);
      v2 = (_DWORD *)std::vector<int>::operator[](j);
      (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int *, int *))(*(_DWORD *)v27 + 52))(v27, *v2, &v24, &v25);
      v21 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v32, v24, v25);
      v26 = CSchedule::GetEcoSector(v32);
      v3 = (_DWORD *)std::vector<int>::operator[](j);
      if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v26 + 68))(v26, *v3) >= 100 )
      {
        v20 = 3;
      }
      else
      {
        v20 = 2;
        C = operator new(0x58u);
        LOBYTE(v33) = 1;
        if ( C )
        {
          v4 = (_DWORD *)std::vector<int>::operator[](j);
          v22 = (struct IScheduleEntry *)CBuildingEvent::CBuildingEvent(
                                           C,
                                           dword_46878FC[15 * i],
                                           0,
                                           v24 / 16,
                                           v25 / 16,
                                           v21,
                                           *v4,
                                           2);
        }
        else
        {
          v22 = 0;
        }
        v15 = v22;
        LOBYTE(v33) = 0;
        CSchedule::NewSchedEntry(v32, v22);
      }
      if ( CProductionDataTab::BuildingMustBeControl(*((void **)v32 + 10), dword_46878FC[15 * i], *((_DWORD *)v32 + 6)) )
      {
        v19 = operator new(0x70u);
        LOBYTE(v33) = 2;
        if ( v19 )
        {
          v11 = v21;
          v10 = dword_46878FC[15 * i];
          v9 = v20;
          v5 = (_DWORD *)std::vector<int>::operator[](j);
          v18 = (struct IScheduleEntry *)CProductivityControll::CProductivityControll(v19, *v5, v9, v10, v11, 0);
        }
        else
        {
          v18 = 0;
        }
        v14 = v18;
        LOBYTE(v33) = 0;
        CSchedule::NewSchedEntry(v32, v18);
      }
      if ( dword_46878FC[15 * i] == 40 || dword_46878FC[15 * i] == 41 || dword_46878FC[15 * i] == 42 )
      {
        v17 = CSchedule::GetEcoSector(v32);
        v6 = (_DWORD *)std::vector<int>::operator[](j);
        if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v17 + 68))(v17, *v6) < 100
          || (v16 = CSchedule::GetEcoSector(v32),
              v7 = (_DWORD *)std::vector<int>::operator[](j),
              (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v16 + 92))(v16, *v7) > 0) )
        {
          SpecialTask = CSchedule::GetSpecialTask(v32, 8);
          if ( SpecialTask )
            *((_BYTE *)SpecialTask + 60) = 0;
        }
      }
    }
  }
  std::vector<int>::clear();
  v13 = 0;
  v33 = -1;
  std::vector<int>::~vector<int>();
  return v13;
}


// address=[0x2f43000]
// Decompiled from char __thiscall CSchedule::trigger(CSchedule *this)
bool  CSchedule::trigger(void) {
  
  int v2; // esi
  CPerformanceCounter *v3; // [esp+14h] [ebp-24h]
  CPerformanceCounter *v4; // [esp+18h] [ebp-20h]
  int v5; // [esp+1Ch] [ebp-1Ch]
  struct IScheduleEntry *SchedEntry; // [esp+24h] [ebp-14h]
  bool v8; // [esp+2Bh] [ebp-Dh]

  v8 = 0;
  ++*((_DWORD *)this + 4);
  v5 = 0;
  CProfile::Begin((CProfile *)&stru_46871A0);
  if ( CSchedule::ReadMessages(this) )
    return 1;
  v4 = (CPerformanceCounter *)operator new(0x18u);
  if ( v4 )
    v3 = CPerformanceCounter::CPerformanceCounter(v4);
  else
    v3 = 0;
  v2 = *((_DWORD *)this + 3) + 1;
  if ( v2 > CDynList::size(*((CDynList **)this + 1)) )
    *((_DWORD *)this + 3) = 0;
  while ( !v8 )
  {
    if ( *((_DWORD *)this + 8) )
    {
      SchedEntry = CSchedule::GetSchedEntry(this, *((_DWORD *)this + 8));
      *((_DWORD *)this + 3) = CDynListEntry::GetIndex(SchedEntry);
    }
    else
    {
      SchedEntry = (struct IScheduleEntry *)CDynList::elementAt(*((CDynList **)this + 1), *((_DWORD *)this + 3));
    }
    if ( SchedEntry )
    {
      *((_DWORD *)SchedEntry + 9) = 0;
      if ( *((_DWORD *)SchedEntry + 5) == 1
        && (*(unsigned __int8 (__thiscall **)(struct IScheduleEntry *))(*(_DWORD *)SchedEntry + 16))(SchedEntry)
        && (*(unsigned __int8 (__thiscall **)(struct IScheduleEntry *))(*(_DWORD *)SchedEntry + 20))(SchedEntry) )
      {
        *((_DWORD *)SchedEntry + 5) = 2;
      }
      if ( *((_DWORD *)SchedEntry + 5) == 2
        && (*(unsigned __int8 (__thiscall **)(struct IScheduleEntry *))(*(_DWORD *)SchedEntry + 8))(SchedEntry) == 1 )
      {
        (*(void (__thiscall **)(struct IScheduleEntry *))(*(_DWORD *)SchedEntry + 12))(SchedEntry);
      }
      if ( *((_DWORD *)SchedEntry + 5) == 3 )
      {
        CDynList::delElement(*((CDynList **)this + 1), SchedEntry);
        --*((_DWORD *)this + 3);
        break;
      }
      ++*((_DWORD *)this + 3);
      v8 = 1;
      if ( *((_DWORD *)SchedEntry + 9) == 1 )
        v8 = ++v5 > 20;
    }
    else
    {
      v8 = 1;
    }
  }
  operator delete(v3);
  return v8;
}


// address=[0x2f43220]
// Decompiled from int __thiscall CSchedule::GenerateSchedKey(CSchedule *this)
int  CSchedule::GenerateSchedKey(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = *((_DWORD *)this + 7);
  *((_DWORD *)this + 7) = v2 + 1;
  return v2;
}


// address=[0x2f43260]
// Decompiled from int __thiscall CSchedule::NewSchedEntry(CDynList **this, struct IScheduleEntry *a2)
int  CSchedule::NewSchedEntry(class IScheduleEntry *) {
  
  *((_DWORD *)a2 + 3) = CSchedule::GenerateSchedKey((CSchedule *)this);
  *((_DWORD *)a2 + 10) = this;
  CDynList::addElement(this[1], a2);
  return *((_DWORD *)a2 + 3);
}


// address=[0x2f432a0]
// Decompiled from int __thiscall CSchedule::NewSchedEntry(CSchedule *this, struct IScheduleEntry *a2, int a3)
int  CSchedule::NewSchedEntry(class IScheduleEntry *,int) {
  
  *((_DWORD *)a2 + 8) = a3;
  return CSchedule::NewSchedEntry(this, a2);
}


// address=[0x2f432d0]
// Decompiled from struct CDynListEntry *__thiscall CSchedule::GetSchedEntry(CDynList **this, int a2)
class IScheduleEntry *  CSchedule::GetSchedEntry(int) {
  
  struct CDynListEntry *i; // [esp+Ch] [ebp-4h]

  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 3) == a2 )
      return i;
  }
  return 0;
}


// address=[0x2f43330]
// Decompiled from struct CDynListEntry *__thiscall CSchedule::GetSpecialTask(CDynList **this, int a2)
class IScheduleEntry *  CSchedule::GetSpecialTask(int) {
  
  struct CDynListEntry *i; // [esp+8h] [ebp-4h]

  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 4) == a2 )
      return i;
  }
  return 0;
}


// address=[0x2f43380]
// Decompiled from struct CDynListEntry *__thiscall CSchedule::GetMaterialManager(CDynList **this, int a2)
class CMaterialManagerTask *  CSchedule::GetMaterialManager(enum PILE_TYPES) {
  
  struct CDynListEntry *i; // [esp+10h] [ebp-4h]

  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 4) == 4 && *((_DWORD *)i + 13) == a2 )
      return i;
  }
  return 0;
}


// address=[0x2f433f0]
// Decompiled from struct CDynListEntry *__thiscall CSchedule::GetResourceManager(CDynList **this, int a2)
class CResourceManagerTask *  CSchedule::GetResourceManager(int) {
  
  struct CDynListEntry *i; // [esp+10h] [ebp-4h]

  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 4) == 5 && *((_DWORD *)i + 11) == a2 )
      return i;
  }
  return 0;
}


// address=[0x2f43460]
// Decompiled from struct CDynListEntry *__thiscall CSchedule::GetProductivityControll(CDynList **this, int a2, int a3)
class CProductivityControll *  CSchedule::GetProductivityControll(struct SBuildId) {
  
  struct CDynListEntry *i; // [esp+Ch] [ebp-4h]

  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)i + 4) == 2 && *((_DWORD *)i + 11) == a2 && *((_DWORD *)i + 12) == a3 )
      return i;
  }
  return 0;
}


// address=[0x2f434e0]
// Decompiled from struct CDynListEntry *__thiscall CSchedule::GetExpandationEvent(CDynList **this, int a2)
class CExpandationEvent *  CSchedule::GetExpandationEvent(int) {
  
  struct CDynListEntry *i; // [esp+Ch] [ebp-4h]

  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 4) == 7 && *((_DWORD *)i + 22) == a2 )
      return i;
  }
  return 0;
}


// address=[0x2f43550]
// Decompiled from bool __thiscall CSchedule::IsBorderElement(CSchedule *this, int a2, int a3)
bool  CSchedule::IsBorderElement(int,int) {
  
  CExpandationManagerTask *SpecialTask; // eax

  SpecialTask = CSchedule::GetSpecialTask(this, 6);
  return CExpandationManagerTask::IsBorderElement(SpecialTask, a2, a3);
}


// address=[0x2f43580]
// Decompiled from struct CDynListEntry *__thiscall CSchedule::GetBuildingEvent(CDynList **this, int a2, int a3)
class CBuildingEvent *  CSchedule::GetBuildingEvent(int,enum T_BUILD_LEVEL) {
  
  struct CDynListEntry *i; // [esp+Ch] [ebp-4h]

  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)i + 4) == 9 && *((_DWORD *)i + 12) == a2 && *((_DWORD *)i + 13) == a3 )
      return i;
  }
  return 0;
}


// address=[0x2f43600]
// Decompiled from char __thiscall CSchedule::GetBuildingInPlannedStatus(CDynList **this, struct CReserveEntry *a2)
bool  CSchedule::GetBuildingInPlannedStatus(class CReserveEntry *) {
  
  struct CDynListEntry *i; // [esp+8h] [ebp-10h]
  int v4; // [esp+10h] [ebp-8h]
  char v5; // [esp+17h] [ebp-1h]

  v4 = 0;
  v5 = 0;
  while ( *((_DWORD *)a2 + 11 * v4 + 3) )
    ++v4;
  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)i + 4) == 9 )
    {
      *((_DWORD *)a2 + 11 * v4 + 6) = 0;
      *((_DWORD *)a2 + 11 * v4 + 4) = *((_DWORD *)i + 15);
      *((_DWORD *)a2 + 11 * v4 + 5) = *((_DWORD *)i + 16);
      *((_DWORD *)a2 + 11 * v4 + 3) = *((_DWORD *)i + 11);
      *((_DWORD *)a2 + 11 * v4 + 8) = *((_DWORD *)i + 17);
      *((_DWORD *)a2 + 11 * ++v4 + 3) = 0;
      v5 = 1;
    }
  }
  return v5;
}


// address=[0x2f43700]
// Decompiled from CDynListEntry *__thiscall CSchedule::GetBuildingAtPosition(CDynList **this, int a2, int a3)
class CBuildingEvent *  CSchedule::GetBuildingAtPosition(int,int) {
  
  int v4; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+4h] [ebp-14h] BYREF
  CReserveDatabase **v6; // [esp+8h] [ebp-10h]
  CDynListEntry *v7; // [esp+Ch] [ebp-Ch]
  CDynListEntry *v8; // [esp+10h] [ebp-8h]
  CDynListEntry *i; // [esp+14h] [ebp-4h]

  v6 = this;
  v7 = 0;
  for ( i = CDynList::FirstEntry(this[1]); i; i = (CDynListEntry *)CDynListEntry::Next(i) )
  {
    v8 = i;
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)v8 + 4) == 9 )
    {
      v7 = v8;
      CReserveDatabase::UnpackPosition(*v6, *((_DWORD *)v8 + 17), &v5, &v4);
      if ( v5 == a2 && v4 == a3 )
        return v7;
    }
  }
  return 0;
}


// address=[0x2f43790]
// Decompiled from int __thiscall CSchedule::GetTmpMaxNumberOfBuildingType(int this, int a2)
int  CSchedule::GetTmpMaxNumberOfBuildingType(enum BUILDING_TYPES) {
  
  int NumberOfBuildingType; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v7; // [esp+8h] [ebp-8h]

  v7 = 0;
  switch ( a2 )
  {
    case 2:
      v7 = CSchedule::GetNumberOfBuildingType(this, 1) / 2 + 1;
      break;
    case 5:
      NumberOfBuildingType = CSchedule::GetNumberOfBuildingType(this, 10);
      v3 = CSchedule::GetNumberOfBuildingType(this, 12) + NumberOfBuildingType;
      v4 = CSchedule::GetNumberOfBuildingType(this, 39) + v3;
      v7 = (v4 + CSchedule::GetNumberOfBuildingType(this, 37)) / 2 + 1;
      break;
    case 7:
      if ( ((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 36) + 12))(*(_DWORD *)(this + 36)) & 0x10) != 0 )
        v7 = 2;
      else
        v7 = 0;
      break;
    case 11:
      v5 = CSchedule::GetNumberOfBuildingType(this, 9);
      v7 = v5 + CSchedule::GetNumberOfBuildingType(this, 12) + 1;
      break;
    case 14:
      if ( ((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 36) + 12))(*(_DWORD *)(this + 36)) & 0x10) != 0 )
      {
        if ( *(_DWORD *)(this + 24) == 2 )
          v7 = 2;
        if ( !*(_DWORD *)(this + 24) )
          v7 = 1;
        if ( *(_DWORD *)(this + 24) == 1 )
          v7 = 1;
        if ( *(_DWORD *)(this + 24) == 4 )
          v7 = 1;
      }
      else
      {
        v7 = 0;
      }
      break;
    case 25:
      v7 = 0;
      if ( *(_DWORD *)(this + 24) == 1 )
        v7 = 2;
      break;
    default:
      return v7;
  }
  return v7;
}


// address=[0x2f43930]
// Decompiled from bool __thiscall CSchedule::EnoughNumberOfBuildingType(void *this, int a2)
bool  CSchedule::EnoughNumberOfBuildingType(enum BUILDING_TYPES) {
  
  int TmpMaxNumberOfBuildingType; // esi

  TmpMaxNumberOfBuildingType = CSchedule::GetTmpMaxNumberOfBuildingType((int)this, a2);
  return TmpMaxNumberOfBuildingType <= CSchedule::GetNumberOfBuildingType(this, a2);
}


// address=[0x2f43970]
// Decompiled from int __thiscall CSchedule::GetSumResourceAmount(int this, int a2, int a3, int a4, int a5)
int  CSchedule::GetSumResourceAmount(enum BUILDING_TYPES,int,int,int) {
  
  int v5; // eax
  int MaxDistance; // eax
  int v8; // [esp+4h] [ebp-50h] BYREF
  int v9; // [esp+8h] [ebp-4Ch] BYREF
  struct IAIEcoManager *v10; // [esp+Ch] [ebp-48h]
  int v11; // [esp+10h] [ebp-44h]
  struct IAIEcoManager *v12; // [esp+14h] [ebp-40h]
  struct IAIEcoManager *v13; // [esp+18h] [ebp-3Ch]
  int v14; // [esp+1Ch] [ebp-38h]
  struct IAIEcoManager *v15; // [esp+20h] [ebp-34h]
  struct IAIEcoManager *EcoSector; // [esp+24h] [ebp-30h]
  int v17; // [esp+28h] [ebp-2Ch]
  int v18; // [esp+2Ch] [ebp-28h]
  int ResourceForBuilding; // [esp+30h] [ebp-24h]
  int v20; // [esp+34h] [ebp-20h] BYREF
  int v21; // [esp+38h] [ebp-1Ch]
  int v22; // [esp+3Ch] [ebp-18h] BYREF
  struct CDynListEntry *ResourceManager; // [esp+40h] [ebp-14h]
  struct IFilterEntry *FilterEntry; // [esp+44h] [ebp-10h]
  int v25; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  CDynList **v27; // [esp+50h] [ebp-4h]

  v27 = (CDynList **)this;
  v25 = 0;
  v21 = 0;
  v11 = 0;
  v14 = 0;
  ResourceManager = 0;
  ResourceForBuilding = CProductionDataTab::GetResourceForBuilding(*(void **)(this + 40), a2, *(_DWORD *)(this + 24));
  if ( ResourceForBuilding == -1 )
    return v25;
  CReserveDatabase::UnpackPosition(*v27, a3, &v22, &v20);
  if ( a5 != 1 )
  {
    v22 = a5 / 2 + a5 * v22;
    v20 = a5 / 2 + a5 * v22;
  }
  v18 = a2 - 1;
  switch ( a2 )
  {
    case 1:
    case 4:
    case 6:
    case 7:
      ResourceManager = CSchedule::GetResourceManager(v27, ResourceForBuilding);
      if ( ResourceManager )
      {
        for ( i = 0; i < *(_DWORD *)(*((_DWORD *)ResourceManager + 21) + 8); ++i )
        {
          FilterEntry = CFilter::GetFilterEntry(*((CFilter **)ResourceManager + 21), i);
          v21 = CSchedule::CalcDistance(
                  (CSchedule *)v27,
                  v22,
                  v20,
                  16 * *((_DWORD *)FilterEntry + 3) + 8,
                  16 * *((_DWORD *)FilterEntry + 4) + 8);
          if ( v21 < 20 )
          {
            v17 = *((_DWORD *)FilterEntry + 5);
            if ( 20 * v17 - v21 > 0 )
              v25 += 20 * v17 - v21;
          }
        }
      }
      if ( !v25 )
      {
        EcoSector = CSchedule::GetEcoSector((CSchedule *)v27);
        v25 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)EcoSector + 176))(
                EcoSector,
                ResourceForBuilding,
                v22 / 16,
                v20 / 16);
      }
      break;
    case 5:
      v10 = CSchedule::GetEcoSector((CSchedule *)v27);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v10 + 228))(v10, v22, v20) )
        v25 = 1000;
      break;
    case 11:
    case 35:
    case 36:
    case 38:
      ResourceManager = CSchedule::GetResourceManager(v27, ResourceForBuilding);
      if ( ResourceManager )
      {
        for ( i = 0; i < *(_DWORD *)(*((_DWORD *)ResourceManager + 21) + 8); ++i )
        {
          FilterEntry = CFilter::GetFilterEntry(*((CFilter **)ResourceManager + 21), i);
          v25 = 10 * *((_DWORD *)FilterEntry + 5);
          v21 = CSchedule::CalcDistance(
                  (CSchedule *)v27,
                  v22,
                  v20,
                  16 * *((_DWORD *)FilterEntry + 3) + 8,
                  16 * *((_DWORD *)FilterEntry + 4) + 8);
          MaxDistance = CProductionDataTab::GetMaxDistance(v27[10], a2, v27[6]);
          if ( v21 > MaxDistance )
            v25 -= v21;
          if ( v25 > v11 )
          {
            v11 = v25;
            CReserveDatabase::PackPosition(
              *v27,
              16 * *((_DWORD *)FilterEntry + 3) + 8,
              16 * *((_DWORD *)FilterEntry + 4) + 8);
          }
        }
      }
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
      v15 = CSchedule::GetEcoSector((CSchedule *)v27);
      v14 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v15 + 296))(v15, 3);
      for ( i = 0; i < v14; ++i )
      {
        v13 = CSchedule::GetEcoSector((CSchedule *)v27);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)v13 + 300))(v13, i, &v8, &v9);
        v12 = CSchedule::GetEcoSector((CSchedule *)v27);
        v5 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v12 + 236))(
               v12,
               ResourceForBuilding,
               v8 + v22,
               v9 + v20);
        v25 += v5;
      }
      break;
    default:
      return v25;
  }
  return v25;
}


// address=[0x2f43d20]
// Decompiled from int __thiscall CSchedule::AreaHasOtherResource(CDynList **this, int a2, int a3, int a4)
int  CSchedule::AreaHasOtherResource(enum BUILDING_TYPES,int,int) {
  
  struct IAIEcoManager *v4; // eax
  struct IAIEcoManager *v6; // [esp+20h] [ebp-24h]
  struct IAIEcoManager *EcoSector; // [esp+24h] [ebp-20h]
  struct CDynListEntry *i; // [esp+38h] [ebp-Ch]
  int v10; // [esp+40h] [ebp-4h]

  v10 = 0;
  if ( a2 < 5 || a2 > 6 && a2 != 46 )
  {
    EcoSector = CSchedule::GetEcoSector((CSchedule *)this);
    if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)EcoSector + 232))(
           EcoSector,
           a3,
           a4) )
    {
      v10 = 2;
    }
    v6 = CSchedule::GetEcoSector((CSchedule *)this);
    if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v6 + 224))(v6, a3, a4) )
      v10 = 2;
    if ( CSchedule::IsBorderElement((CSchedule *)this, a3, a4) )
      v10 += 10;
  }
  v4 = CSchedule::GetEcoSector((CSchedule *)this);
  if ( (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v4 + 244))(v4, 2, a3, a4) > 0 )
    v10 += 30;
  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 4) == 5 && CResourceManagerTask::AreaHasResource(i, a3, a4) )
    {
      ++v10;
      switch ( *((_DWORD *)i + 11) )
      {
        case 0:
          if ( a2 < 5 || a2 > 6 )
            ++v10;
          break;
        case 0x10:
        case 0x20:
          switch ( a2 )
          {
            case 15:
            case 17:
            case 20:
            case 21:
            case 22:
              continue;
            default:
              v10 += 2;
              break;
          }
          break;
        case 0x30:
          if ( a2 == 15 || a2 == 17 )
            ++v10;
          break;
        case 0x40:
          if ( a2 == 15 || a2 == 17 )
            ++v10;
          break;
        case 0x60:
          if ( a2 != 4 )
            ++v10;
          break;
        case 0x70:
          if ( a2 >= 2 && (a2 <= 4 || a2 == 6) )
            ++v10;
          break;
        default:
          continue;
      }
    }
  }
  return v10;
}


// address=[0x2f44030]
// Decompiled from int __thiscall CSchedule::GetNearExpandationPositionOutside(CSchedule *this, int a2, int a3, int a4)
int  CSchedule::GetNearExpandationPositionOutside(int,int,class std::vector<int,class std::allocator<int> > &) {
  
  unsigned int v4; // eax
  _DWORD *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned __int8 v9; // al
  int v10; // eax
  int v11; // eax
  int v13; // [esp+14h] [ebp-68h] BYREF
  struct IFilterEntry *v14; // [esp+18h] [ebp-64h]
  void *v15; // [esp+1Ch] [ebp-60h]
  struct IAIEcoManager *v16; // [esp+20h] [ebp-5Ch]
  struct IAIEcoManager *v17; // [esp+24h] [ebp-58h]
  struct IAIEcoManager *v18; // [esp+28h] [ebp-54h]
  struct IAIEcoManager *v19; // [esp+2Ch] [ebp-50h]
  struct IAIEcoManager *v20; // [esp+30h] [ebp-4Ch]
  struct IAIEcoManager *v21; // [esp+34h] [ebp-48h]
  struct IAIEcoManager *EcoSector; // [esp+38h] [ebp-44h]
  int v23; // [esp+3Ch] [ebp-40h] BYREF
  int v24; // [esp+40h] [ebp-3Ch] BYREF
  CFilter *v25; // [esp+44h] [ebp-38h]
  void *C; // [esp+48h] [ebp-34h]
  CFilter *v27; // [esp+4Ch] [ebp-30h]
  struct IFilterEntry *FilterEntry; // [esp+50h] [ebp-2Ch]
  struct IScheduleEntry *SpecialTask; // [esp+54h] [ebp-28h]
  CFilter *v30; // [esp+58h] [ebp-24h]
  unsigned int i; // [esp+5Ch] [ebp-20h]
  CReserveDatabase **v32; // [esp+60h] [ebp-1Ch]
  int j; // [esp+64h] [ebp-18h]
  int k; // [esp+68h] [ebp-14h]
  int v35; // [esp+6Ch] [ebp-10h]
  int v36; // [esp+78h] [ebp-4h]

  v32 = (CReserveDatabase **)this;
  v30 = 0;
  v35 = 0;
  FilterEntry = 0;
  v13 = 0;
  SpecialTask = CSchedule::GetSpecialTask(this, 6);
  C = operator new(0x18u);
  v36 = 0;
  if ( C )
    v25 = CFilter::CFilter((CFilter *)C, 5);
  else
    v25 = 0;
  v36 = -1;
  v30 = v25;
  for ( i = 0; ; ++i )
  {
    v4 = std::vector<int>::size((char *)SpecialTask + 52);
    if ( i >= v4 )
      break;
    v5 = (_DWORD *)std::vector<int>::operator[](i);
    CReserveDatabase::UnpackPosition(*v32, *v5, &v24, &v23);
    v35 = 0;
    for ( j = v24 - 2; j < v24 + 2; ++j )
    {
      for ( k = v23 - 2; k < v23 + 2; ++k )
      {
        EcoSector = CSchedule::GetEcoSector((CSchedule *)v32);
        if ( !(*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)EcoSector + 196))(
                EcoSector,
                16 * j + 8,
                16 * k + 8) )
        {
          v21 = CSchedule::GetEcoSector((CSchedule *)v32);
          v6 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v21 + 236))(v21, 16, j, k);
          v35 += v6;
          v20 = CSchedule::GetEcoSector((CSchedule *)v32);
          v7 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v20 + 236))(v20, 48, j, k);
          v35 += v7;
          v19 = CSchedule::GetEcoSector((CSchedule *)v32);
          v8 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v19 + 236))(v19, 32, j, k);
          v35 += v8;
          v18 = CSchedule::GetEcoSector((CSchedule *)v32);
          v9 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v18 + 228))(v18, j, k);
          v35 += 20 * v9;
          v17 = CSchedule::GetEcoSector((CSchedule *)v32);
          v10 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v17 + 236))(v17, 96, j, k);
          v35 += v10;
          v16 = CSchedule::GetEcoSector((CSchedule *)v32);
          v11 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v16 + 236))(v16, 80, j, k);
          v35 += v11;
          v15 = operator new(0x18u);
          v36 = 1;
          if ( v15 )
            v14 = CResourceFilter::CResourceFilter((CResourceFilter *)v15, j, k, v35);
          else
            v14 = 0;
          v36 = -1;
          CFilter::AddFilterEntry(v30, v14);
        }
      }
    }
  }
  for ( i = 0; (signed int)i < *((_DWORD *)v30 + 2); ++i )
  {
    FilterEntry = CFilter::GetFilterEntry(v30, i);
    v13 = CReserveDatabase::PackPosition(*v32, *((_DWORD *)FilterEntry + 3), *((_DWORD *)FilterEntry + 4));
    std::vector<int>::push_back(&v13);
  }
  v27 = v30;
  if ( v30 )
    (**(void (__thiscall ***)(CFilter *, int))v27)(v27, 1);
  return std::vector<int>::size(a4);
}


// address=[0x2f443a0]
// Decompiled from int __thiscall CSchedule::PreSelect16Grid(CReserveDatabase **this, int a2, int a3, int a4, int a5, int a6, int a7)
int  CSchedule::PreSelect16Grid(enum BUILDING_TYPES,struct SBUILDINFODATA *,class CReserveEntry *,class std::vector<struct SBUILDINFODATA,class std::allocator<struct SBUILDINFODATA> > &,int,int) {
  
  int v8; // [esp+4h] [ebp-78h]
  int SumResourceAmount; // [esp+8h] [ebp-74h]
  int v11; // [esp+10h] [ebp-6Ch]
  int i; // [esp+1Ch] [ebp-60h]
  _BYTE v13[76]; // [esp+20h] [ebp-5Ch] BYREF
  int v14; // [esp+78h] [ebp-4h]

  SumResourceAmount = 0;
  SBUILDINFODATA::SBUILDINFODATA(v13);
  v14 = 0;
  std::vector<SBUILDINFODATA>::clear();
  for ( i = 0; i < a6; ++i )
  {
    switch ( a2 )
    {
      case 1:
      case 4:
      case 6:
      case 7:
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
        v11 = CReserveDatabase::PackPosition(*this, *(_DWORD *)(a3 + 76 * i), *(_DWORD *)(a3 + 76 * i + 4));
        SumResourceAmount = CSchedule::GetSumResourceAmount((int)this, a2, v11, 0, 16);
        break;
      default:
        break;
    }
    if ( SumResourceAmount > 0 )
      std::vector<SBUILDINFODATA>::push_back(a3 + 76 * i);
  }
  v8 = std::vector<SBUILDINFODATA>::size(a5);
  v14 = -1;
  SBUILDINFODATA::~SBUILDINFODATA(v13);
  return v8;
}


// address=[0x2f444e0]
// Decompiled from int __thiscall CSchedule::GetMainProblemSolve(CSchedule *this, int a2)
int  CSchedule::GetMainProblemSolve(int) {
  
  struct IScheduleEntry *SchedEntry; // [esp+4h] [ebp-4h]

  SchedEntry = CSchedule::GetSchedEntry(this, a2);
  if ( !SchedEntry )
    return 0;
  while ( *((_DWORD *)SchedEntry + 4) == 11 )
  {
    SchedEntry = CSchedule::GetSchedEntry(this, *((_DWORD *)SchedEntry + 8));
    if ( !SchedEntry )
      break;
    a2 = *((_DWORD *)SchedEntry + 3);
  }
  return a2;
}


// address=[0x2f44540]
// Decompiled from struct IScheduleEntry *__thiscall CSchedule::UpdateExpandationEvents(CDynList **this, int a2)
void  CSchedule::UpdateExpandationEvents(int) {
  
  int v2; // eax
  struct IScheduleEntry *result; // eax
  _BYTE v4[4]; // [esp+0h] [ebp-24h] BYREF
  _BYTE v5[4]; // [esp+4h] [ebp-20h] BYREF
  int v6; // [esp+8h] [ebp-1Ch]
  struct IAIEcoManager *EcoSector; // [esp+10h] [ebp-14h]
  int v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  CDynList **v11; // [esp+20h] [ebp-4h]

  v11 = this;
  v6 = 10;
  v9 = 0;
  v8 = 0;
  EcoSector = CSchedule::GetEcoSector((CSchedule *)this);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *, _BYTE *))(*(_DWORD *)EcoSector + 52))(
    EcoSector,
    a2,
    v4,
    v5);
  for ( i = 0; ; ++i )
  {
    v2 = CDynList::size(v11[1]);
    if ( i >= v2 )
      break;
    v9 = CDynList::elementAt(v11[1], i);
    if ( *(_DWORD *)(v9 + 16) == 7 )
    {
      v8 = v9;
      *(_DWORD *)(v9 + 20) = 3;
      CSchedule::MarkSolvedProblem((CSchedule *)v11, *(_DWORD *)(v8 + 32), 1);
    }
  }
  result = CSchedule::GetSpecialTask((CSchedule *)v11, 6);
  *((_BYTE *)result + 76) = 1;
  return result;
}


// address=[0x2f44600]
// Decompiled from char __thiscall CSchedule::IsAnyExpandation(CDynList **this)
bool  CSchedule::IsAnyExpandation(void) {
  
  struct CDynListEntry *i; // [esp+10h] [ebp-4h]

  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 4) == 7 )
      return 1;
  }
  return 0;
}


// address=[0x2f44660]
// Decompiled from char __thiscall CSchedule::SetPositionOfTower(CSchedule *this, int a2, int a3, int a4, int a5)
bool  CSchedule::SetPositionOfTower(int,int,int,int) {
  
  struct IScheduleEntry *SchedEntry; // [esp+14h] [ebp-8h]
  struct IScheduleEntry *v8; // [esp+18h] [ebp-4h]

  SchedEntry = CSchedule::GetSchedEntry(this, a2);
  if ( !SchedEntry )
    return 0;
  if ( *((_DWORD *)SchedEntry + 4) != 10 )
    return 0;
  v8 = CSchedule::GetSchedEntry(this, *((_DWORD *)SchedEntry + 8));
  if ( !v8 || *((_DWORD *)v8 + 4) != 7 )
    return 0;
  *((_DWORD *)v8 + 23) = a4;
  *((_DWORD *)v8 + 24) = a5;
  return 1;
}


// address=[0x2f446f0]
// Decompiled from char __thiscall CSchedule::ProduceWeapons(CSchedule *this, int a2, int a3)
bool  CSchedule::ProduceWeapons(int,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  _DWORD *v10; // eax
  _BYTE v12[16]; // [esp+14h] [ebp-90h] BYREF
  struct IAIEcoManager *v13; // [esp+24h] [ebp-80h]
  struct IAIEcoManager *v14; // [esp+28h] [ebp-7Ch]
  struct IAIEcoManager *v15; // [esp+2Ch] [ebp-78h]
  struct IAIEcoManager *v16; // [esp+30h] [ebp-74h]
  struct IAIEcoManager *v17; // [esp+34h] [ebp-70h]
  struct IAIEcoManager *v18; // [esp+38h] [ebp-6Ch]
  struct IAIEcoManager *v19; // [esp+3Ch] [ebp-68h]
  struct IAIEcoManager *v20; // [esp+40h] [ebp-64h]
  struct IAIEcoManager *v21; // [esp+44h] [ebp-60h]
  struct IAIEcoManager *v22; // [esp+48h] [ebp-5Ch]
  struct IAIEcoManager *v23; // [esp+4Ch] [ebp-58h]
  struct IAIEcoManager *v24; // [esp+50h] [ebp-54h]
  struct IAIEcoManager *v25; // [esp+54h] [ebp-50h]
  struct IAIEcoManager *v26; // [esp+58h] [ebp-4Ch]
  struct IAIEcoManager *v27; // [esp+5Ch] [ebp-48h]
  struct IAIEcoManager *v28; // [esp+60h] [ebp-44h]
  struct IAIEcoManager *v29; // [esp+64h] [ebp-40h]
  struct IAIEcoManager *v30; // [esp+68h] [ebp-3Ch]
  struct IAIEcoManager *v31; // [esp+6Ch] [ebp-38h]
  struct IAIEcoManager *v32; // [esp+70h] [ebp-34h]
  struct IAIEcoManager *EcoSector; // [esp+74h] [ebp-30h]
  int v34; // [esp+78h] [ebp-2Ch] BYREF
  int v35; // [esp+7Ch] [ebp-28h] BYREF
  int v36; // [esp+80h] [ebp-24h] BYREF
  unsigned int i; // [esp+84h] [ebp-20h]
  char v38; // [esp+8Bh] [ebp-19h]
  int v39; // [esp+8Ch] [ebp-18h] BYREF
  int v40; // [esp+90h] [ebp-14h]
  CSchedule *v41; // [esp+94h] [ebp-10h]
  int v42; // [esp+A0h] [ebp-4h]

  v41 = this;
  v36 = 0;
  v35 = 0;
  v39 = 0;
  v34 = 0;
  v40 = 0;
  std::vector<int>::vector<int>(v12);
  v42 = 0;
  std::vector<int>::clear();
  EcoSector = CSchedule::GetEcoSector(v41);
  if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 156))(EcoSector, 22) > 0 )
  {
    v32 = CSchedule::GetEcoSector(v41);
    (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)v32 + 160))(v32, 22, v12);
    CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v41, a2, &v36, &v35);
    v31 = CSchedule::GetEcoSector(v41);
    v3 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v31 + 144))(v31, 34);
    v36 -= v3;
    v30 = CSchedule::GetEcoSector(v41);
    v4 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v30 + 144))(v30, 8);
    v35 -= v4;
    CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v41, a3, &v39, &v34);
    v29 = CSchedule::GetEcoSector(v41);
    v5 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v29 + 144))(v29, 3);
    v34 -= v5;
    if ( *((_DWORD *)v41 + 6) == 1 )
    {
      v28 = CSchedule::GetEcoSector(v41);
      v6 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v28 + 144))(v28, 5);
      v39 -= v6;
    }
    if ( *((_DWORD *)v41 + 6) == 2 )
    {
      v27 = CSchedule::GetEcoSector(v41);
      v7 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v27 + 144))(v27, 6);
      v39 -= v7;
    }
    if ( *((_DWORD *)v41 + 6) == 4 )
    {
      v26 = CSchedule::GetEcoSector(v41);
      v8 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v26 + 144))(v26, 38);
      v39 -= v8;
    }
    for ( i = 0; ; ++i )
    {
      v9 = std::vector<int>::size(v12);
      if ( i >= v9 )
        break;
      v25 = CSchedule::GetEcoSector(v41);
      v10 = (_DWORD *)std::vector<int>::operator[](i);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v25 + 76))(v25, *v10) )
      {
        v40 = *(_DWORD *)std::vector<int>::operator[](i);
        break;
      }
    }
    if ( std::vector<int>::size(v12) && v40 )
    {
      v24 = CSchedule::GetEcoSector(v41);
      (*(void (__thiscall **)(struct IAIEcoManager *, int, int, _DWORD))(*(_DWORD *)v24 + 268))(v24, v40, 34, 0);
      v23 = CSchedule::GetEcoSector(v41);
      (*(void (__thiscall **)(struct IAIEcoManager *, int, int, _DWORD))(*(_DWORD *)v23 + 268))(v23, v40, 8, 0);
      v22 = CSchedule::GetEcoSector(v41);
      (*(void (__thiscall **)(struct IAIEcoManager *, int, int, _DWORD))(*(_DWORD *)v22 + 268))(v22, v40, 3, 0);
      if ( *((_DWORD *)v41 + 6) == 1 )
      {
        v21 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, _DWORD))(*(_DWORD *)v21 + 268))(v21, v40, 5, 0);
      }
      if ( *((_DWORD *)v41 + 6) == 2 )
      {
        v20 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, _DWORD))(*(_DWORD *)v20 + 268))(v20, v40, 6, 0);
      }
      if ( *((_DWORD *)v41 + 6) == 4 )
      {
        v19 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, _DWORD))(*(_DWORD *)v19 + 268))(v19, v40, 38, 0);
      }
      if ( v36 > 0 )
      {
        v18 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v18 + 268))(v18, v40, 34, v36);
      }
      if ( v35 > 0 )
      {
        v17 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v17 + 268))(v17, v40, 8, v35);
      }
      if ( v34 > 0 )
      {
        v16 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v16 + 268))(v16, v40, 3, v34);
      }
      if ( *((_DWORD *)v41 + 6) == 1 && v39 > 0 )
      {
        v15 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v15 + 268))(v15, v40, 5, v39);
      }
      if ( *((_DWORD *)v41 + 6) == 2 && v39 > 0 )
      {
        v14 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v14 + 268))(v14, v40, 6, v39);
      }
      if ( *((_DWORD *)v41 + 6) == 4 && v39 > 0 )
      {
        v13 = CSchedule::GetEcoSector(v41);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v13 + 268))(v13, v40, 38, v39);
      }
    }
  }
  v38 = 0;
  v42 = -1;
  std::vector<int>::~vector<int>();
  return v38;
}


// address=[0x2f44bb0]
// Decompiled from char __thiscall CSchedule::AllSubProblemsSolved(CDynList **this, int a2)
bool  CSchedule::AllSubProblemsSolved(int) {
  
  _DWORD *v4; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[1]); ++i )
  {
    v4 = (_DWORD *)CDynList::elementAt(this[1], i);
    if ( v4[4] == 11 && v4[8] == a2 && !v4[17] && !v4[16] )
      return 0;
  }
  return 1;
}


// address=[0x2f44c40]
// Decompiled from int __thiscall CSchedule::GetTargetPosition(CSchedule *this, int a2)
int  CSchedule::GetTargetPosition(int) {
  
  _BYTE v3[16]; // [esp+4h] [ebp-F4h] BYREF
  int v4; // [esp+14h] [ebp-E4h]
  int v5; // [esp+18h] [ebp-E0h]
  int v6; // [esp+1Ch] [ebp-DCh] BYREF
  int v7; // [esp+20h] [ebp-D8h] BYREF
  struct IAIEcoManager *v8; // [esp+24h] [ebp-D4h]
  struct IAIEcoManager *EcoSector; // [esp+28h] [ebp-D0h]
  int v10; // [esp+2Ch] [ebp-CCh]
  int v11; // [esp+30h] [ebp-C8h]
  int v12; // [esp+34h] [ebp-C4h]
  CSchedule *v13; // [esp+38h] [ebp-C0h]
  int v14; // [esp+3Ch] [ebp-BCh]
  int v15; // [esp+40h] [ebp-B8h]
  int i; // [esp+44h] [ebp-B4h]
  _DWORD v17[40]; // [esp+48h] [ebp-B0h] BYREF
  int v18; // [esp+F4h] [ebp-4h]

  v13 = this;
  v5 = 0;
  i = 0;
  v10 = 0;
  v11 = 0;
  v14 = 0;
  std::vector<int>::vector<int>(v3);
  v18 = 0;
  v15 = 0;
  v12 = a2 - 7;
  switch ( a2 )
  {
    case 7:
      v15 = 3;
      break;
    case 9:
      v15 = 17;
      break;
    case 11:
      v15 = 16;
      break;
    case 22:
      v15 = 1;
      break;
    case 24:
      v15 = 15;
      break;
    default:
      break;
  }
  if ( v15 && CSchedule::GetAllBuildingOfTypeInProdControl(v13, v15, v17) )
  {
    for ( i = 0; v17[2 * i] && i < 2; ++i )
    {
      EcoSector = CSchedule::GetEcoSector(v13);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 304))(
             EcoSector,
             v17[2 * i]) )
      {
        if ( v17[2 * i + 1] == 1 )
        {
          CSchedule::GetPlannedBuildingPosition(v13, v17[2 * i], &v7, &v6);
        }
        else
        {
          v8 = CSchedule::GetEcoSector(v13);
          (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int *, int *))(*(_DWORD *)v8 + 52))(
            v8,
            v17[2 * i],
            &v7,
            &v6);
        }
      }
      v10 += v7;
      v11 += v6;
      ++v14;
    }
    if ( v14 > 0 )
      v5 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v13, v10 / v14, v11 / v14);
  }
  v4 = v5;
  v18 = -1;
  std::vector<int>::~vector<int>();
  return v4;
}


// address=[0x2f44f30]
// Decompiled from int __thiscall CSchedule::isDepSchedSolved(CSchedule *this, int a2)
int  CSchedule::isDepSchedSolved(int) {
  
  struct IScheduleEntry *SchedEntry; // [esp+Ch] [ebp-4h]

  SchedEntry = CSchedule::GetSchedEntry(this, a2);
  if ( !SchedEntry )
    return 1;
  if ( *((_DWORD *)SchedEntry + 4) == 11 )
  {
    if ( *((_DWORD *)SchedEntry + 17) )
      return 2;
    if ( *(_DWORD *)(*((_DWORD *)SchedEntry + 18) + 36) == 3 )
      return 1;
  }
  if ( *((_DWORD *)SchedEntry + 4) != 10 )
    return 0;
  if ( *((_DWORD *)SchedEntry + 17) )
    return 2;
  return *((_DWORD *)SchedEntry + 25) && *(_DWORD *)(*((_DWORD *)SchedEntry + 25) + 36) == 3;
}


// address=[0x2f44fe0]
// Decompiled from char __thiscall CSchedule::TerminateSubProblems(CDynList **this, int a2)
bool  CSchedule::TerminateSubProblems(int) {
  
  _DWORD *v4; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[1]); ++i )
  {
    v4 = (_DWORD *)CDynList::elementAt(this[1], i);
    if ( v4[4] == 11 && v4[8] == a2 )
      v4[5] = 3;
  }
  return 1;
}


// address=[0x2f45070]
// Decompiled from char __thiscall CSchedule::MarkSolvedProblem(CSchedule *this, int a2, bool a3)
bool  CSchedule::MarkSolvedProblem(int,bool) {
  
  char result; // al
  struct IScheduleEntry *SchedEntry; // [esp+24h] [ebp-4h]

  SchedEntry = CSchedule::GetSchedEntry(this, a2);
  if ( !SchedEntry )
    return 0;
  switch ( *((_DWORD *)SchedEntry + 4) )
  {
    case 2:
      if ( *((_DWORD *)SchedEntry + 5) != 3 )
      {
        if ( a3 )
          *((_DWORD *)SchedEntry + 23) = 2;
        else
          *((_DWORD *)SchedEntry + 23) = 1;
      }
      result = 1;
      break;
    case 3:
      if ( a3 )
        *((_DWORD *)SchedEntry + 22) = 2;
      else
        *((_DWORD *)SchedEntry + 22) = 1;
      result = 1;
      break;
    case 4:
      if ( a3 )
        *((_DWORD *)SchedEntry + 14) = 2;
      else
        *((_DWORD *)SchedEntry + 14) = 1;
      result = 1;
      break;
    case 5:
      *((_DWORD *)SchedEntry + 8) = 0;
      if ( a3 )
        *((_DWORD *)SchedEntry + 18) = 2;
      else
        *((_DWORD *)SchedEntry + 18) = 1;
      result = 1;
      break;
    case 6:
      if ( a3 )
        *((_DWORD *)SchedEntry + 17) = 2;
      else
        *((_DWORD *)SchedEntry + 17) = 1;
      result = 1;
      break;
    case 7:
      if ( a3 )
        *((_DWORD *)SchedEntry + 27) = 2;
      else
        *((_DWORD *)SchedEntry + 27) = 1;
      result = 1;
      break;
    case 8:
      *((_DWORD *)SchedEntry + 8) = 0;
      if ( a3 )
        *((_DWORD *)SchedEntry + 13) = 2;
      else
        *((_DWORD *)SchedEntry + 13) = 1;
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}


// address=[0x2f45250]
// Decompiled from int __thiscall CSchedule::SearchExternSolution(CDynList **this, int a2, int a3, int a4, int a5, int a6, int a7)
int  CSchedule::SearchExternSolution(int,int,int,int,int,int) {
  
  int i; // [esp+4h] [ebp-Ch]
  _DWORD *v10; // [esp+8h] [ebp-8h]

  for ( i = 0; ; ++i )
  {
    if ( i >= CDynList::size(this[1]) )
      return 0;
    v10 = (_DWORD *)CDynList::elementAt(this[1], i);
    if ( v10[4] == 11
      && v10[8] == a2
      && a3 == v10[15]
      && v10[11] == a4
      && v10[12] == a5
      && v10[13] == a6
      && v10[14] == a7 )
    {
      break;
    }
  }
  if ( v10[16] )
    return v10[3];
  else
    return 0;
}


// address=[0x2f45310]
// Decompiled from int __thiscall CSchedule::GetSolution(CSchedule *this, int a2)
class CSolutionTree *  CSchedule::GetSolution(int) {
  
  struct IScheduleEntry *SchedEntry; // [esp+Ch] [ebp-4h]

  SchedEntry = CSchedule::GetSchedEntry(this, a2);
  if ( !SchedEntry )
    return 0;
  if ( *((_DWORD *)SchedEntry + 4) == 11 )
  {
    *((_DWORD *)SchedEntry + 5) = 1;
    return *((_DWORD *)SchedEntry + 17);
  }
  if ( *((_DWORD *)SchedEntry + 4) != 10 )
    return 0;
  *((_DWORD *)SchedEntry + 5) = 1;
  return *((_DWORD *)SchedEntry + 17);
}


// address=[0x2f45390]
// Decompiled from char __thiscall CSchedule::InvokeNeeded(CDynList **this, int a2)
bool  CSchedule::InvokeNeeded(enum BUILDING_TYPES) {
  
  int k; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int v7; // [esp+18h] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[1]); ++i )
  {
    v7 = CDynList::elementAt(this[1], i);
    if ( *(_DWORD *)(v7 + 16) == 11 )
    {
      for ( j = 0; *(_DWORD *)(v7 + 4 * j + 76); ++j )
      {
        if ( *(_DWORD *)(v7 + 4 * j + 76) == a2 )
          return 1;
      }
    }
    if ( *(_DWORD *)(v7 + 16) == 10 )
    {
      for ( k = 0; *(_DWORD *)(v7 + 4 * k + 76); ++k )
      {
        if ( *(_DWORD *)(v7 + 4 * k + 76) == a2 )
          return 1;
      }
    }
  }
  return 0;
}


// address=[0x2f45480]
// Decompiled from int __thiscall CSchedule::GetInvokeEvent(CDynList **this, int a2)
class CInvokeEvent *  CSchedule::GetInvokeEvent(enum BUILDING_TYPES) {
  
  int v4; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[1]); ++i )
  {
    v4 = CDynList::elementAt(this[1], i);
    if ( *(_DWORD *)(v4 + 16) == 12 && *(_DWORD *)(v4 + 44) == a2 )
      return v4;
  }
  return 0;
}


// address=[0x2f45500]
// Decompiled from int __thiscall CSchedule::GetContentOfWorkingArea(CSchedule *this, int a2, int a3)
int  CSchedule::GetContentOfWorkingArea(int,enum BUILDING_TYPES) {
  
  int v4; // [esp+4h] [ebp-2Ch] BYREF
  int v5; // [esp+8h] [ebp-28h] BYREF
  struct IAIEcoManager *v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+10h] [ebp-20h]
  int v8; // [esp+14h] [ebp-1Ch]
  struct IAIEcoManager *v9; // [esp+18h] [ebp-18h]
  struct IAIEcoManager *EcoSector; // [esp+1Ch] [ebp-14h]
  int ResourceForBuilding; // [esp+20h] [ebp-10h]
  int ContentOfWorkingArea; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  CSchedule *v14; // [esp+2Ch] [ebp-4h]

  v14 = this;
  ContentOfWorkingArea = 0;
  EcoSector = CSchedule::GetEcoSector(this);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)EcoSector + 120))(
    EcoSector,
    a2,
    &v4,
    &v5);
  v7 = v4 / 16;
  v8 = v5 / 16;
  ResourceForBuilding = CProductionDataTab::GetResourceForBuilding(*((void **)v14 + 10), a3, *((_DWORD *)v14 + 6));
  v13 = ResourceForBuilding + 6;
  switch ( ResourceForBuilding )
  {
    case -6:
    case -3:
    case -2:
      ContentOfWorkingArea = CSchedule::GetContentOfWorkingArea(v14, a3, v4, v5);
      break;
    case 0:
    case 16:
    case 32:
    case 80:
      v6 = CSchedule::GetEcoSector(v14);
      ContentOfWorkingArea = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v6 + 164))(
                               v6,
                               ResourceForBuilding,
                               v7,
                               v8);
      break;
    case 96:
    case 112:
      v9 = CSchedule::GetEcoSector(v14);
      ContentOfWorkingArea = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v9 + 176))(
                               v9,
                               ResourceForBuilding,
                               v7,
                               v8);
      break;
    default:
      return ContentOfWorkingArea;
  }
  return ContentOfWorkingArea;
}


// address=[0x2f456a0]
// Decompiled from int __thiscall CSchedule::GetContentOfWorkingArea(CSchedule *this, int a2, int a3, int a4)
int  CSchedule::GetContentOfWorkingArea(enum BUILDING_TYPES,int,int) {
  
  struct IAIEcoManager *v5; // [esp+8h] [ebp-48h]
  int ResourceForBuilding; // [esp+Ch] [ebp-44h]
  struct IAIEcoManager *v7; // [esp+10h] [ebp-40h]
  struct IAIEcoManager *v8; // [esp+14h] [ebp-3Ch]
  struct IAIEcoManager *v9; // [esp+18h] [ebp-38h]
  struct IAIEcoManager *v10; // [esp+1Ch] [ebp-34h]
  struct IAIEcoManager *v11; // [esp+20h] [ebp-30h]
  struct IAIEcoManager *v12; // [esp+24h] [ebp-2Ch]
  struct IAIEcoManager *v13; // [esp+28h] [ebp-28h]
  int v14; // [esp+2Ch] [ebp-24h]
  struct IAIEcoManager *EcoSector; // [esp+30h] [ebp-20h]
  int v16; // [esp+38h] [ebp-18h] BYREF
  int v17; // [esp+3Ch] [ebp-14h] BYREF
  int v18; // [esp+40h] [ebp-10h]
  int v19; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  CSchedule *v21; // [esp+4Ch] [ebp-4h]

  v21 = this;
  v19 = 0;
  v18 = 0;
  EcoSector = CSchedule::GetEcoSector(this);
  v14 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 124))(EcoSector, a2);
  ResourceForBuilding = CProductionDataTab::GetResourceForBuilding(*((void **)v21 + 10), a2, *((_DWORD *)v21 + 6));
  if ( ResourceForBuilding == -6 )
  {
    v9 = CSchedule::GetEcoSector(v21);
    v18 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v9 + 296))(v9, 20);
    v19 = 0;
    for ( i = 0; i < v18; ++i )
    {
      v8 = CSchedule::GetEcoSector(v21);
      (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)v8 + 300))(v8, i, &v16, &v17);
      v7 = CSchedule::GetEcoSector(v21);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v7 + 240))(
             v7,
             5,
             v16 + a3,
             v17 + a4) )
      {
        ++v19;
      }
    }
  }
  else if ( ResourceForBuilding <= -4 || ResourceForBuilding > -2 )
  {
    v5 = CSchedule::GetEcoSector(v21);
    return (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v5 + 176))(
             v5,
             ResourceForBuilding,
             a3 / 16,
             a4 / 16);
  }
  else
  {
    v13 = CSchedule::GetEcoSector(v21);
    v18 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v13 + 296))(v13, v14);
    for ( i = 0; i < v18; ++i )
    {
      v12 = CSchedule::GetEcoSector(v21);
      (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)v12 + 300))(v12, i, &v16, &v17);
      v11 = CSchedule::GetEcoSector(v21);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v11 + 240))(
             v11,
             2,
             v16 + a3,
             v17 + a4) )
      {
        v10 = CSchedule::GetEcoSector(v21);
        if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v10 + 196))(
               v10,
               v16 + a3,
               v17 + a4) )
        {
          ++v19;
        }
      }
    }
  }
  return v19;
}


// address=[0x2f458f0]
// Decompiled from char __thiscall CSchedule::SetBestWorkingAreaPosition(CSchedule *this, int a2, int a3, int a4, int a5)
bool  CSchedule::SetBestWorkingAreaPosition(int,enum BUILDING_TYPES,int &,int &) {
  
  int v5; // eax
  int v7; // [esp+0h] [ebp-88h]
  int v8; // [esp+8h] [ebp-80h] BYREF
  int v9; // [esp+Ch] [ebp-7Ch] BYREF
  struct IAIEcoManager *v10; // [esp+10h] [ebp-78h]
  struct IAIEcoManager *v11; // [esp+14h] [ebp-74h]
  struct IAIEcoManager *v12; // [esp+18h] [ebp-70h]
  struct IAIEcoManager *v13; // [esp+1Ch] [ebp-6Ch]
  struct IAIEcoManager *v14; // [esp+20h] [ebp-68h]
  int v15; // [esp+24h] [ebp-64h] BYREF
  int v16; // [esp+28h] [ebp-60h] BYREF
  struct IAIEcoManager *v17; // [esp+2Ch] [ebp-5Ch]
  struct IAIEcoManager *v18; // [esp+30h] [ebp-58h]
  struct IAIEcoManager *v19; // [esp+34h] [ebp-54h]
  struct IAIEcoManager *v20; // [esp+38h] [ebp-50h]
  struct IAIEcoManager *v21; // [esp+3Ch] [ebp-4Ch]
  struct IAIEcoManager *v22; // [esp+40h] [ebp-48h]
  struct IAIEcoManager *v23; // [esp+44h] [ebp-44h]
  int v24; // [esp+48h] [ebp-40h]
  int v25; // [esp+4Ch] [ebp-3Ch]
  struct IAIEcoManager *v26; // [esp+50h] [ebp-38h]
  struct IAIEcoManager *EcoSector; // [esp+54h] [ebp-34h]
  int v28; // [esp+58h] [ebp-30h]
  int ContentOfWorkingArea; // [esp+5Ch] [ebp-2Ch]
  int ResourceForBuilding; // [esp+60h] [ebp-28h]
  int v31; // [esp+64h] [ebp-24h]
  int v32; // [esp+68h] [ebp-20h]
  int v33; // [esp+6Ch] [ebp-1Ch] BYREF
  int v34; // [esp+70h] [ebp-18h] BYREF
  int v35; // [esp+74h] [ebp-14h]
  int i; // [esp+78h] [ebp-10h]
  int j; // [esp+7Ch] [ebp-Ch]
  char v38; // [esp+83h] [ebp-5h]
  CSchedule *v39; // [esp+84h] [ebp-4h]

  v39 = this;
  v28 = 0;
  v35 = 0;
  ContentOfWorkingArea = 0;
  v38 = 0;
  v32 = 1;
  EcoSector = CSchedule::GetEcoSector(this);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)EcoSector + 52))(
    EcoSector,
    a2,
    &v15,
    &v16);
  ResourceForBuilding = CProductionDataTab::GetResourceForBuilding(*((void **)v39 + 10), a3, *((_DWORD *)v39 + 6));
  ContentOfWorkingArea = CSchedule::GetContentOfWorkingArea(v39, a2, a3);
  v26 = CSchedule::GetEcoSector(v39);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)v26 + 120))(v26, a2, &v9, &v8);
  if ( ContentOfWorkingArea )
  {
    v34 = v9;
    v33 = v8;
    v38 = 0;
  }
  v25 = v15 / 16;
  v24 = v16 / 16;
  for ( i = v15 / 16 - v32; i <= v32 + v25; ++i )
  {
    for ( j = v24 - v32; j <= v32 + v24; ++j )
    {
      v31 = ResourceForBuilding + 6;
      switch ( ResourceForBuilding )
      {
        case -6:
          v12 = CSchedule::GetEcoSector(v39);
          v35 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v12 + 244))(v12, 2, i, j);
          break;
        case -3:
          v14 = CSchedule::GetEcoSector(v39);
          v35 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v14 + 244))(v14, 5, i, j);
          break;
        case -2:
          v13 = CSchedule::GetEcoSector(v39);
          v35 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v13 + 244))(v13, 6, i, j);
          break;
        case -1:
          if ( a3 == 5 )
          {
            v19 = CSchedule::GetEcoSector(v39);
            if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v19 + 232))(v19, i, j) )
              v35 = 500;
            v18 = CSchedule::GetEcoSector(v39);
            if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v18 + 228))(v18, i, j) )
              v35 = 1000;
            v17 = CSchedule::GetEcoSector(v39);
            v28 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v17 + 260))(v17, i, j);
            v7 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v39, v15, v16);
            v5 = CSchedule::CalcDistance(v39, v28, v7);
            v35 -= v5;
          }
          break;
        case 0:
          if ( CSchedule::IsBorderElement(v39, i, j)
            || (v22 = CSchedule::GetEcoSector(v39),
                (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v22 + 228))(v22, i, j)) )
          {
            v21 = CSchedule::GetEcoSector(v39);
            v35 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v21 + 164))(
                    v21,
                    ResourceForBuilding,
                    i,
                    j);
          }
          break;
        case 16:
        case 32:
        case 80:
          v20 = CSchedule::GetEcoSector(v39);
          v35 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v20 + 164))(
                  v20,
                  ResourceForBuilding,
                  i,
                  j);
          break;
        case 96:
        case 112:
          v23 = CSchedule::GetEcoSector(v39);
          v35 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v23 + 176))(
                  v23,
                  ResourceForBuilding,
                  i,
                  j);
          break;
        default:
          break;
      }
      if ( v35 > ContentOfWorkingArea )
      {
        v34 = 16 * i + 8;
        v33 = 16 * j + 8;
        ContentOfWorkingArea = v35;
        if ( a3 == 5 )
        {
          v11 = CSchedule::GetEcoSector(v39);
          v28 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v11 + 260))(v11, i, j);
          CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v39, v28, &v34, &v33);
        }
        v38 = 1;
      }
    }
  }
  if ( !v38 )
    return v38;
  BBSupportTracePrintF(3, "AI_BuildingEvent::Building %i change working area to %i, %i", a2, v34, v33);
  v10 = CSchedule::GetEcoSector(v39);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v10 + 116))(v10, a2, v34, v33);
  v9 = v34;
  v8 = v33;
  return v38;
}


// address=[0x2f45dc0]
// Decompiled from char __thiscall CSchedule::SetSpecialWorkingAreaPosition(CSchedule *this, int a2, int a3, int a4, int a5, int a6)
bool  CSchedule::SetSpecialWorkingAreaPosition(int,enum BUILDING_TYPES,int &,int &,int) {
  
  int ResourceForBuilding; // [esp+Ch] [ebp-58h]
  struct IAIEcoManager *v8; // [esp+10h] [ebp-54h]
  struct IAIEcoManager *v9; // [esp+14h] [ebp-50h]
  int v10; // [esp+18h] [ebp-4Ch]
  struct IAIEcoManager *v11; // [esp+1Ch] [ebp-48h]
  struct IAIEcoManager *v12; // [esp+20h] [ebp-44h]
  struct IAIEcoManager *v13; // [esp+24h] [ebp-40h]
  struct IAIEcoManager *EcoSector; // [esp+28h] [ebp-3Ch]
  int v15; // [esp+2Ch] [ebp-38h] BYREF
  int v16; // [esp+30h] [ebp-34h] BYREF
  int v17; // [esp+34h] [ebp-30h]
  int v18; // [esp+38h] [ebp-2Ch]
  int v19; // [esp+3Ch] [ebp-28h] BYREF
  int v20; // [esp+40h] [ebp-24h] BYREF
  int v21; // [esp+44h] [ebp-20h]
  int v22; // [esp+48h] [ebp-1Ch]
  int v23; // [esp+4Ch] [ebp-18h]
  int j; // [esp+50h] [ebp-14h]
  int i; // [esp+54h] [ebp-10h]
  int v26; // [esp+58h] [ebp-Ch]
  CSchedule *v27; // [esp+5Ch] [ebp-8h]
  char v28; // [esp+63h] [ebp-1h]

  v27 = this;
  v17 = 0;
  v26 = 0;
  v28 = 0;
  EcoSector = CSchedule::GetEcoSector(this);
  v10 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 124))(EcoSector, a3);
  v13 = CSchedule::GetEcoSector(v27);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)v13 + 52))(v13, a2, &v20, &v19);
  ResourceForBuilding = CProductionDataTab::GetResourceForBuilding(*((void **)v27 + 10), a3, *((_DWORD *)v27 + 6));
  v12 = CSchedule::GetEcoSector(v27);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)v12 + 120))(v12, a2, &v16, &v15);
  v11 = CSchedule::GetEcoSector(v27);
  v26 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v11 + 108))(v11, a3, v16, v15);
  if ( v26 )
  {
    v23 = v16;
    v22 = v15;
    v28 = 0;
    v21 = a3;
    if ( a3 == 11 )
    {
      if ( v26 > 50 )
        return 0;
    }
    else if ( v21 == 35 )
    {
      if ( v26 > 7 )
        return 0;
    }
    else if ( v21 == 36 && v26 > 110 )
    {
      return 0;
    }
  }
  for ( i = v20 - 16; i <= v20 + 16; i += v10 / 2 )
  {
    for ( j = v19 - 16; j <= v19 + 16; j += v10 / 2 )
    {
      v18 = ResourceForBuilding;
      if ( ResourceForBuilding == -6 || v18 > -4 && v18 <= -2 )
      {
        v9 = CSchedule::GetEcoSector(v27);
        v17 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v9 + 108))(v9, a3, i, j);
      }
      if ( v17 > v26 )
      {
        v23 = i;
        v22 = j;
        v26 = v17;
        v28 = 1;
      }
    }
  }
  if ( !v28 )
    return v28;
  BBSupportTracePrintF(3, "AI_BuildingEvent::Building %i change working area to %i, %i", a2, v23, v22);
  v8 = CSchedule::GetEcoSector(v27);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, int, int))(*(_DWORD *)v8 + 116))(v8, a2, v23, v22);
  v16 = v23;
  v15 = v22;
  return v28;
}


// address=[0x2f46010]
// Decompiled from int __thiscall CSchedule::UnmarkBuildings(CSchedule *this)
void  CSchedule::UnmarkBuildings(void) {
  
  _BYTE v2[16]; // [esp+4h] [ebp-34h] BYREF
  int v3; // [esp+14h] [ebp-24h]
  int v4; // [esp+18h] [ebp-20h]
  CSchedule *v5; // [esp+1Ch] [ebp-1Ch]
  CDynListEntry *v6; // [esp+20h] [ebp-18h]
  CDynListEntry *v7; // [esp+24h] [ebp-14h]
  CDynListEntry *i; // [esp+28h] [ebp-10h]
  int v9; // [esp+34h] [ebp-4h]

  v5 = this;
  v4 = 0;
  v6 = 0;
  std::vector<int>::vector<int>(v2);
  v9 = 0;
  i = 0;
  v3 = 0;
  for ( i = CDynList::FirstEntry(*((CDynList **)v5 + 1)); i; i = (CDynListEntry *)CDynListEntry::Next(i) )
  {
    v7 = i;
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)v7 + 4) == 2 )
    {
      v6 = v7;
      *((_BYTE *)v7 + 100) = 0;
    }
  }
  v9 = -1;
  return std::vector<int>::~vector<int>();
}


// address=[0x2f460d0]
// Decompiled from CDynListEntry *__thiscall CSchedule::GetUnmarkBuildings(CDynList **this, int a2)
class CProductivityControll *  CSchedule::GetUnmarkBuildings(enum BUILDING_TYPES) {
  
  char v3[16]; // [esp+4h] [ebp-3Ch] BYREF
  int v4; // [esp+14h] [ebp-2Ch]
  int v5; // [esp+18h] [ebp-28h]
  int v6; // [esp+1Ch] [ebp-24h]
  CDynListEntry *v7; // [esp+20h] [ebp-20h]
  CDynList **v8; // [esp+24h] [ebp-1Ch]
  CDynListEntry *v9; // [esp+28h] [ebp-18h]
  CDynListEntry *v10; // [esp+2Ch] [ebp-14h]
  CDynListEntry *i; // [esp+30h] [ebp-10h]
  int v12; // [esp+3Ch] [ebp-4h]

  v8 = this;
  v5 = 0;
  v10 = 0;
  std::vector<int>::vector<int>(v3);
  v12 = 0;
  i = 0;
  v4 = 0;
  for ( i = CDynList::FirstEntry(v8[1]); i; i = (CDynListEntry *)CDynListEntry::Next(i) )
  {
    v9 = i;
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)v9 + 4) == 2 )
    {
      v10 = v9;
      if ( *((_DWORD *)v9 + 21) == a2 && !*((_BYTE *)v10 + 100) )
      {
        v7 = v10;
        v12 = -1;
        std::vector<int>::~vector<int>();
        return v7;
      }
    }
  }
  v6 = 0;
  v12 = -1;
  std::vector<int>::~vector<int>();
  return (CDynListEntry *)v6;
}


// address=[0x2f461c0]
// Decompiled from char __thiscall CSchedule::VerifyAllBuildingIds(CDynList **this)
bool  CSchedule::VerifyAllBuildingIds(void) {
  
  int v1; // eax
  int v2; // eax
  struct IAIEcoManager *v4; // [esp+0h] [ebp-24h]
  struct IAIEcoManager *EcoSector; // [esp+4h] [ebp-20h]
  int v6; // [esp+8h] [ebp-1Ch] BYREF
  int v7; // [esp+Ch] [ebp-18h] BYREF
  CDynListEntry *v8; // [esp+10h] [ebp-14h]
  CDynListEntry *v9; // [esp+14h] [ebp-10h]
  CSchedule *v10; // [esp+18h] [ebp-Ch]
  CDynListEntry *v11; // [esp+1Ch] [ebp-8h]
  CDynListEntry *i; // [esp+20h] [ebp-4h]

  v10 = (CSchedule *)this;
  v9 = 0;
  v8 = 0;
  i = 0;
  for ( i = CDynList::FirstEntry(this[1]); i; i = (CDynListEntry *)CDynListEntry::Next(i) )
  {
    v11 = i;
    if ( *((_DWORD *)i + 5) != 3 )
    {
      if ( *((_DWORD *)v11 + 4) == 2 )
      {
        v9 = v11;
        if ( *((_DWORD *)v11 + 12) != 1 )
        {
          EcoSector = CSchedule::GetEcoSector(v10);
          (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int *, int *))(*(_DWORD *)EcoSector + 52))(
            EcoSector,
            *((_DWORD *)v9 + 11),
            &v6,
            &v7);
          v1 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v10, v6, v7);
          if ( *((_DWORD *)v9 + 17) != v1
            && BBSupportDbgReport(
                 2,
                 "Source\\EcoAI_Schedule.cpp",
                 1244,
                 "pProdControl->m_iPackedWorldPos == m_pResData->PackPosition (riBuildPosX, riBuildPosY)") == 1 )
          {
            __debugbreak();
          }
        }
      }
      if ( *((_DWORD *)v11 + 4) == 9 )
      {
        v8 = v11;
        if ( *((_DWORD *)v11 + 13) != 1 )
        {
          v4 = CSchedule::GetEcoSector(v10);
          (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int *, int *))(*(_DWORD *)v4 + 52))(
            v4,
            *((_DWORD *)v8 + 12),
            &v6,
            &v7);
          v2 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v10, v6, v7);
          if ( *((_DWORD *)v8 + 17) != v2
            && BBSupportDbgReport(
                 2,
                 "Source\\EcoAI_Schedule.cpp",
                 1259,
                 "pBuildEvent->m_iPackWorldPosition == m_pResData->PackPosition (riBuildPosX, riBuildPosY)") == 1 )
          {
            __debugbreak();
          }
        }
      }
    }
  }
  return 1;
}


// address=[0x2f46320]
// Decompiled from int __thiscall CSchedule::GetBuildingTypeInGroup(CSchedule *this, int a2, int a3, int a4, int a5)
int  CSchedule::GetBuildingTypeInGroup(enum BUILDING_TYPES,int,int,class std::vector<struct SBuildId,class std::allocator<struct SBuildId> > &) {
  
  _BYTE v6[16]; // [esp+4h] [ebp-38h] BYREF
  int v7; // [esp+14h] [ebp-28h]
  int v8; // [esp+18h] [ebp-24h]
  int v9; // [esp+1Ch] [ebp-20h]
  CDynList **v10; // [esp+20h] [ebp-1Ch]
  CDynListEntry *v11; // [esp+24h] [ebp-18h]
  CDynListEntry *i; // [esp+28h] [ebp-14h]
  CDynListEntry *v13; // [esp+2Ch] [ebp-10h]
  int v14; // [esp+38h] [ebp-4h]

  v10 = (CDynList **)this;
  v7 = 0;
  v13 = 0;
  std::vector<int>::vector<int>(v6);
  v14 = 0;
  i = 0;
  v9 = 0;
  for ( i = CDynList::FirstEntry(v10[1]); i; i = (CDynListEntry *)CDynListEntry::Next(i) )
  {
    v11 = i;
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)v11 + 4) == 2 )
    {
      v13 = v11;
      if ( *((_DWORD *)v11 + 21) == a2
        && !*((_BYTE *)v13 + 100)
        && CSchedule::CalcDistance((CSchedule *)v10, *((_DWORD *)v13 + 17), a3) < a4 )
      {
        std::vector<SBuildId>::push_back((char *)v13 + 44);
        *((_BYTE *)v13 + 100) = 1;
        CSchedule::GetBuildingTypeInGroup(a2, *((_DWORD *)v13 + 17), a4, a5);
        ++v9;
      }
    }
  }
  v8 = v9;
  v14 = -1;
  std::vector<int>::~vector<int>();
  return v8;
}


// address=[0x2f46450]
// Decompiled from int __thiscall CSchedule::GetNearestInputBuildings(CDynList **this, int a2, int a3, int a4, int a5)
int  CSchedule::GetNearestInputBuildings(struct SBuildId,int,struct SBuildId *) {
  
  int InputTypePile; // eax
  int MaxBuildingInGroup; // eax
  int v7; // eax
  CDynList *v9; // [esp-4h] [ebp-118h]
  int MaxDistance; // [esp+10h] [ebp-104h]
  int v11; // [esp+14h] [ebp-100h] BYREF
  int v12; // [esp+18h] [ebp-FCh] BYREF
  int v13; // [esp+1Ch] [ebp-F8h] BYREF
  int v14[2]; // [esp+20h] [ebp-F4h] BYREF
  struct IFilterEntry *v15; // [esp+28h] [ebp-ECh]
  void *v16; // [esp+2Ch] [ebp-E8h]
  int v17; // [esp+30h] [ebp-E4h]
  CFilter *v18; // [esp+34h] [ebp-E0h]
  void *C; // [esp+38h] [ebp-DCh]
  int v20; // [esp+3Ch] [ebp-D8h]
  CFilter *v21; // [esp+40h] [ebp-D4h]
  int v22; // [esp+44h] [ebp-D0h]
  struct CDynListEntry *ProductivityControll; // [esp+48h] [ebp-CCh]
  CFilter *v24; // [esp+4Ch] [ebp-C8h]
  struct IFilterEntry *FilterEntry; // [esp+50h] [ebp-C4h]
  CProductivityControll *v26; // [esp+54h] [ebp-C0h]
  int v27; // [esp+58h] [ebp-BCh]
  int i; // [esp+5Ch] [ebp-B8h]
  CDynList **v29; // [esp+60h] [ebp-B4h]
  _DWORD v30[40]; // [esp+64h] [ebp-B0h] BYREF
  int v31; // [esp+110h] [ebp-4h]

  v29 = this;
  v20 = 0;
  v26 = 0;
  v27 = 0;
  FilterEntry = 0;
  ProductivityControll = CSchedule::GetProductivityControll(this, a2, a3);
  CReserveDatabase::UnpackPosition(*v29, *((_DWORD *)ProductivityControll + 17), &v13, v14);
  v9 = v29[6];
  InputTypePile = CProductionDataTab::GetInputTypePile(v29[10], *((_DWORD *)ProductivityControll + 21), a4, (int)v9);
  v22 = CProductionDataTab::GoodTypeProducedBy(v29[10], InputTypePile, 0, v9);
  MaxDistance = CProductionDataTab::GetMaxDistance(v29[10], v22, v29[6]);
  if ( !CSchedule::GetAllBuildingOfTypeInProdControl(v29, v22, v30) )
    return v20;
  C = operator new(0x18u);
  v31 = 0;
  if ( C )
  {
    MaxBuildingInGroup = CProductionDataTab::GetMaxBuildingInGroup(v29[10], v22, (int)v29[6]);
    v18 = CFilter::CFilter((CFilter *)C, MaxBuildingInGroup);
  }
  else
  {
    v18 = 0;
  }
  v14[1] = (int)v18;
  v31 = -1;
  v24 = v18;
  for ( i = 0; v30[2 * i]; ++i )
  {
    v26 = CSchedule::GetProductivityControll(v29, v30[2 * i], v30[2 * i + 1]);
    if ( v26 )
    {
      CReserveDatabase::UnpackPosition(*v29, *((_DWORD *)v26 + 17), &v11, &v12);
      v17 = CSchedule::CalcDistance((CSchedule *)v29, v11, v12, v13, v14[0]);
      if ( v17 <= MaxDistance )
      {
        v16 = operator new(0x1Cu);
        v31 = 1;
        if ( v16 )
        {
          v7 = CProductivityControll::CalcPotentialOutput(v26);
          v15 = (struct IFilterEntry *)CFilterNearCustomer::CFilterNearCustomer(
                                         v16,
                                         v17,
                                         v30[2 * i],
                                         v30[2 * i + 1],
                                         v7);
        }
        else
        {
          v15 = 0;
        }
        v31 = -1;
        CFilter::AddFilterEntry(v24, v15);
      }
    }
  }
  for ( i = 0; i < *((_DWORD *)v24 + 2); ++i )
  {
    FilterEntry = CFilter::GetFilterEntry(v24, i);
    *(_DWORD *)(a5 + 8 * v27) = *((_DWORD *)FilterEntry + 4);
    *(_DWORD *)(a5 + 8 * v27++ + 4) = *((_DWORD *)FilterEntry + 5);
    v20 += *((_DWORD *)FilterEntry + 6);
    *(_DWORD *)(a5 + 8 * v27) = 0;
  }
  v21 = v24;
  if ( v24 )
    (**(void (__thiscall ***)(CFilter *, int))v21)(v21, 1);
  return v20;
}


// address=[0x2f46870]
// Decompiled from bool __thiscall CSchedule::GetNearestBuildingType(CSchedule *this, int a2, int a3, int a4, _DWORD *a5)
bool  CSchedule::GetNearestBuildingType(enum BUILDING_TYPES,int,int,int &) {
  
  int v5; // eax
  int v7; // [esp+Ch] [ebp-20h] BYREF
  int v8; // [esp+10h] [ebp-1Ch] BYREF
  _DWORD *v9; // [esp+14h] [ebp-18h]
  _DWORD *v10; // [esp+18h] [ebp-14h]
  _DWORD *v11; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  CDynList **v13; // [esp+24h] [ebp-8h]
  int v14; // [esp+28h] [ebp-4h]

  v13 = (CDynList **)this;
  v10 = 0;
  v9 = 0;
  *a5 = 0;
  for ( i = 0; ; ++i )
  {
    v5 = CDynList::size(v13[1]);
    if ( i >= v5 )
      break;
    v11 = (_DWORD *)CDynList::elementAt(v13[1], i);
    if ( v11[5] != 3 )
    {
      if ( v11[4] == 2 )
      {
        v10 = v11;
        if ( v11[21] == a2 )
        {
          CReserveDatabase::UnpackPosition(*v13, v10[17], &v7, &v8);
          v14 = CSchedule::CalcDistance((CSchedule *)v13, v7, v8, a3, a4);
          if ( v14 < *a5 || !*a5 )
          {
            if ( v14 )
              *a5 = v14;
          }
        }
      }
      if ( v11[4] == 9 )
      {
        v9 = v11;
        if ( v11[11] == a2 )
        {
          CReserveDatabase::UnpackPosition(*v13, v9[17], &v7, &v8);
          v14 = CSchedule::CalcDistance((CSchedule *)v13, v7, v8, a3, a4);
          if ( v14 < *a5 || !*a5 )
          {
            if ( v14 )
              *a5 = v14;
          }
        }
      }
    }
  }
  return *a5 > 0;
}


// address=[0x2f469f0]
// Decompiled from int __thiscall CSchedule::CollectWorkingArea(CReserveDatabase **this, int a2, int a3)
int  CSchedule::CollectWorkingArea(int,class std::vector<int,class std::allocator<int> > &) {
  
  int v3; // eax
  _BYTE v5[16]; // [esp+4h] [ebp-4Ch] BYREF
  int v6; // [esp+14h] [ebp-3Ch]
  int v7; // [esp+18h] [ebp-38h] BYREF
  int v8; // [esp+1Ch] [ebp-34h]
  _DWORD *v9; // [esp+20h] [ebp-30h]
  _DWORD *v10; // [esp+24h] [ebp-2Ch]
  CReserveDatabase **v11; // [esp+28h] [ebp-28h]
  int j; // [esp+2Ch] [ebp-24h]
  int k; // [esp+30h] [ebp-20h]
  int v14; // [esp+34h] [ebp-1Ch]
  int v15; // [esp+38h] [ebp-18h] BYREF
  int v16; // [esp+3Ch] [ebp-14h] BYREF
  int i; // [esp+40h] [ebp-10h]
  int v18; // [esp+4Ch] [ebp-4h]

  v11 = this;
  v8 = 0;
  v9 = 0;
  std::vector<int>::vector<int>(v5);
  v18 = 0;
  std::vector<int>::clear();
  v14 = 2;
  for ( i = 0; ; ++i )
  {
    v3 = CDynList::size(v11[1]);
    if ( i >= v3 )
      break;
    v10 = (_DWORD *)CDynList::elementAt(v11[1], i);
    if ( v10[5] != 3 && v10[4] == 2 )
    {
      v9 = v10;
      if ( v10[21] == a2 )
      {
        CReserveDatabase::UnpackPosition(*v11, v9[17], &v16, &v15);
        v16 /= 16;
        v15 /= 16;
        for ( j = v16 - v14; j < v14 + v16; ++j )
        {
          for ( k = v15 - v14; k < v14 + v15; ++k )
          {
            v7 = CReserveDatabase::PackPosition(*v11, j, k);
            std::vector<int>::push_back(&v7);
          }
        }
        ++v8;
      }
    }
  }
  v6 = v8;
  v18 = -1;
  std::vector<int>::~vector<int>();
  return v6;
}


// address=[0x2f46b80]
// Decompiled from int __stdcall CSchedule::GetResourceConsumption(int a1, int a2, int a3, int a4, int a5, int a6)
int  CSchedule::GetResourceConsumption(int,int,class std::vector<int,class std::allocator<int> >) {
  
  int v7; // [esp+10h] [ebp-18h]
  int v8; // [esp+14h] [ebp-14h]
  unsigned int i; // [esp+18h] [ebp-10h]

  v7 = 0;
  v8 = 1;
  if ( a1 == 96 )
  {
    v8 = 20;
  }
  else if ( a1 == 112 )
  {
    v8 = 5;
  }
  for ( i = 0; i < std::vector<int>::size(&a3); ++i )
  {
    if ( *(_DWORD *)std::vector<int>::operator[](i) == a2 )
      v7 += v8;
  }
  std::vector<int>::~vector<int>();
  return v7;
}


// address=[0x2f46c50]
// Decompiled from bool __thiscall CSchedule::ResourceNearAtWork(CSchedule *this, int a2, int a3, int a4, int a5, int a6)
bool  CSchedule::ResourceNearAtWork(enum BUILDING_TYPES,enum BUILDING_TYPES,int,int,int) {
  
  struct IScheduleEntry *SpecialTask; // eax
  int v9; // [esp+10h] [ebp-8h] BYREF
  char v10; // [esp+17h] [ebp-1h]

  v10 = 0;
  v9 = 0;
  if ( CSchedule::GetNearestBuildingType(this, a3, a4, a5, &v9) && v9 < a6 )
    return 1;
  SpecialTask = CSchedule::GetSpecialTask(this, 3);
  return (unsigned __int8)CBuildingManagerTask::IsBuildingAtPlanning(SpecialTask, a3) != 0;
}


// address=[0x2f46cd0]
// Decompiled from int __thiscall CSchedule::GetBuildingTypeAroundAt(CDynList **this, int a2, int a3, int a4, int a5, int a6)
int  CSchedule::GetBuildingTypeAroundAt(enum BUILDING_TYPES,int,int,int,class std::vector<struct SBuildId,class std::allocator<struct SBuildId> > &) {
  
  int v7; // [esp+0h] [ebp-BCh] BYREF
  int v8; // [esp+4h] [ebp-B8h] BYREF
  int v9; // [esp+8h] [ebp-B4h]
  struct CDynListEntry *ProductivityControll; // [esp+Ch] [ebp-B0h]
  CDynList **v11; // [esp+10h] [ebp-ACh]
  int i; // [esp+14h] [ebp-A8h]
  _DWORD v13[40]; // [esp+18h] [ebp-A4h] BYREF

  v11 = this;
  ProductivityControll = 0;
  v9 = 0;
  std::vector<SBuildId>::clear(v7, v8);
  if ( CSchedule::GetAllBuildingOfTypeInProdControl(v11, a2, v13) )
  {
    for ( i = 0; v13[2 * i]; ++i )
    {
      ProductivityControll = CSchedule::GetProductivityControll(v11, v13[2 * i], v13[2 * i + 1]);
      if ( ProductivityControll )
      {
        CReserveDatabase::UnpackPosition(*v11, *((_DWORD *)ProductivityControll + 17), &v7, &v8);
        if ( CSchedule::CalcDistance((CSchedule *)v11, a3, a4, v7, v8) <= a5 )
        {
          std::vector<SBuildId>::push_back((char *)ProductivityControll + 44);
          ++v9;
        }
      }
    }
  }
  return v9;
}


// address=[0x2f46e10]
// Decompiled from int __thiscall CSchedule::ChangeBuildingLevel(CDynList **this, int a2, int a3, int a4)
void  CSchedule::ChangeBuildingLevel(int,int,enum T_BUILD_LEVEL) {
  
  int result; // eax
  _DWORD *v6; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  for ( i = 0; ; ++i )
  {
    result = CDynList::size(this[1]);
    if ( i >= result )
      break;
    v6 = (_DWORD *)CDynList::elementAt(this[1], i);
    if ( v6[5] != 3 && v6[4] == 2 && v6 && v6[11] == a2 )
    {
      v6[11] = a3;
      v6[12] = a4;
    }
  }
  return result;
}


// address=[0x2f46eb0]
// Decompiled from bool __thiscall CSchedule::GetWeakBuilding(CSchedule *this, int a2, int a3, int a4, _DWORD *a5)
bool  CSchedule::GetWeakBuilding(enum BUILDING_TYPES,class std::vector<struct SMakroEntry,class std::allocator<struct SMakroEntry> > &,enum PILE_TYPES,int &) {
  
  int InputTypePile; // eax
  unsigned int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  int v20; // eax
  int v21; // [esp-4h] [ebp-EB8h]
  int v22; // [esp-4h] [ebp-EB8h]
  int MaxDistance; // [esp+Ch] [ebp-EA8h]
  _BYTE v24[16]; // [esp+10h] [ebp-EA4h] BYREF
  CDynListEntry *v25; // [esp+20h] [ebp-E94h]
  int v26; // [esp+24h] [ebp-E90h]
  CDynListEntry *j; // [esp+28h] [ebp-E8Ch]
  int MakroIndex; // [esp+2Ch] [ebp-E88h]
  int v29; // [esp+30h] [ebp-E84h]
  int v30; // [esp+34h] [ebp-E80h] BYREF
  int v31; // [esp+38h] [ebp-E7Ch] BYREF
  bool v32; // [esp+3Eh] [ebp-E76h]
  char v33; // [esp+3Fh] [ebp-E75h]
  int v34; // [esp+40h] [ebp-E74h]
  int v35; // [esp+44h] [ebp-E70h]
  CProductivityControll *v36; // [esp+48h] [ebp-E6Ch]
  int WeakIndex; // [esp+4Ch] [ebp-E68h]
  int v38; // [esp+50h] [ebp-E64h]
  char v39; // [esp+56h] [ebp-E5Eh]
  char v40; // [esp+57h] [ebp-E5Dh]
  CSchedule *v41; // [esp+58h] [ebp-E5Ch]
  char v42; // [esp+5Fh] [ebp-E55h]
  unsigned int k; // [esp+60h] [ebp-E54h]
  int i; // [esp+64h] [ebp-E50h]
  _DWORD v45[4]; // [esp+68h] [ebp-E4Ch] BYREF
  int v46; // [esp+78h] [ebp-E3Ch] BYREF
  int v47; // [esp+7Ch] [ebp-E38h]
  int v48; // [esp+80h] [ebp-E34h]
  int v49; // [esp+84h] [ebp-E30h]
  _BYTE v50[500]; // [esp+88h] [ebp-E2Ch] BYREF
  int v51; // [esp+27Ch] [ebp-C38h]
  int v52; // [esp+280h] [ebp-C34h]
  int v53; // [esp+284h] [ebp-C30h]
  _DWORD v54[121]; // [esp+288h] [ebp-C2Ch]
  int v55; // [esp+46Ch] [ebp-A48h] BYREF
  int v56; // [esp+EB0h] [ebp-4h]

  v41 = this;
  v42 = 1;
  v40 = 0;
  v39 = 1;
  _vec_ctor(v50, 0x204u, 7u, CProductionMakroData::CProductionMakroData, CProductionMakroData::~CProductionMakroData);
  v56 = 0;
  MakroIndex = 0;
  v34 = 0;
  v35 = 0;
  v38 = 0;
  v26 = 0;
  *a5 = 0;
  v36 = 0;
  std::vector<SMakroEntry>::vector<SMakroEntry>();
  LOBYTE(v56) = 1;
  CSchedule::UnmarkBuildings(v41);
  v53 = 0;
  v54[0] = 0;
  v51 = a2;
  v52 = 7;
  std::vector<SMakroEntry>::clear();
  for ( i = 1; i < 7; ++i )
  {
    v21 = *((_DWORD *)v41 + 6);
    InputTypePile = CProductionDataTab::GetInputTypePile(
                      *((void **)v41 + 10),
                      *(&v51 + 129 * ((i - 1) / 2)),
                      (i - 1) % 2,
                      v21);
    v29 = CProductionDataTab::GoodTypeProducedBy(*((_DWORD *)v41 + 10), InputTypePile, 0, v21);
    if ( v29 == 5 )
      v29 = 0;
    *(&v51 + 129 * i) = v29;
    MakroIndex = CSchedule::GetMakroIndex(v41, v50, v29);
    *(&v52 + 129 * i) = 7;
    if ( i != MakroIndex )
    {
      *(&v52 + 129 * i) = MakroIndex;
      *(&v52 + 129 * MakroIndex) = i;
    }
    v54[129 * i] = 0;
    v54[129 * i - 1] = 0;
    std::vector<SMakroEntry>::clear();
  }
  while ( v39 )
  {
    v39 = 0;
    v42 = 1;
    while ( v42 )
    {
      v42 = 0;
      for ( j = CDynList::FirstEntry(*((CDynList **)v41 + 1)); j; j = (CDynListEntry *)CDynListEntry::Next(j) )
      {
        v25 = j;
        if ( *((_DWORD *)j + 5) != 3 && *((_DWORD *)v25 + 4) == 2 )
        {
          v36 = v25;
          if ( !*((_BYTE *)v25 + 100) )
          {
            i = CSchedule::GetMakroIndex(v41, v50, *((_DWORD *)v36 + 21));
            if ( i != 7 )
            {
              v40 = 0;
              for ( k = 0; ; ++k )
              {
                v6 = std::vector<SMakroEntry>::size(v24);
                if ( k >= v6 )
                  break;
                MaxDistance = CProductionDataTab::GetMaxDistance(*((_DWORD *)v41 + 10), v51, *((_DWORD *)v41 + 6));
                v22 = *((_DWORD *)v36 + 17);
                v7 = std::vector<SMakroEntry>::operator[](k);
                if ( CSchedule::CalcDistance(v41, *(_DWORD *)(v7 + 12), v22) < MaxDistance )
                {
                  v40 = 1;
                  break;
                }
              }
              if ( !v40 && std::vector<SMakroEntry>::size(v24) )
              {
                v39 = 1;
              }
              else
              {
                v45[0] = *((_DWORD *)v36 + 11);
                v45[1] = *((_DWORD *)v36 + 12);
                v45[2] = *((_DWORD *)v36 + 21);
                v45[3] = *((_DWORD *)v36 + 17);
                std::vector<SMakroEntry>::push_back(v45);
                *((_BYTE *)v36 + 100) = 1;
                v8 = 129 * i;
                v9 = CProductivityControll::CalcPotentialOutput(v36);
                v54[129 * i - 1] = v54[v8 - 1] + v9;
                if ( *(&v52 + 129 * i) != 7 )
                {
                  v10 = 129 * *(&v52 + 129 * i);
                  v11 = CProductivityControll::CalcPotentialOutput(v36);
                  v54[129 * *(&v52 + 129 * i) - 1] = v54[v10 - 1] + v11;
                  std::vector<SMakroEntry>::push_back(v45);
                }
                std::vector<SMakroEntry>::push_back(v45);
                v42 = 1;
              }
            }
          }
        }
      }
    }
    if ( !std::vector<SMakroEntry>::size(v24) )
    {
      v33 = 0;
      LOBYTE(v56) = 0;
      std::vector<SMakroEntry>::~vector<SMakroEntry>();
      v56 = -1;
      `eh vector destructor iterator'(v50, 0x204u, 7u, CProductionMakroData::~CProductionMakroData);
      return v33;
    }
    WeakIndex = CSchedule::GetWeakIndex(v41, v50, 0, a4, a5);
    v34 = 0;
    v35 = 0;
    v38 = 0;
    if ( WeakIndex )
    {
      if ( std::vector<SMakroEntry>::size(&v50[516 * ((WeakIndex - 1) / 2) + 480]) )
      {
        for ( k = 0; ; ++k )
        {
          v13 = std::vector<SMakroEntry>::size(&v50[516 * ((WeakIndex - 1) / 2) + 480]);
          if ( k >= v13 )
            break;
          v14 = std::vector<SMakroEntry>::operator[](k);
          CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v41, *(_DWORD *)(v14 + 12), &v31, &v30);
          v34 += v31;
          v35 += v30;
          ++v38;
        }
      }
    }
    else
    {
      if ( std::vector<SMakroEntry>::size(&v55) )
      {
        for ( k = 0; ; ++k )
        {
          v15 = std::vector<SMakroEntry>::size(&v50[1032 * WeakIndex + 996]);
          if ( k >= v15 )
            break;
          v16 = std::vector<SMakroEntry>::operator[](k);
          CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v41, *(_DWORD *)(v16 + 12), &v31, &v30);
          v34 += v31;
          v35 += v30;
          ++v38;
        }
      }
      if ( std::vector<SMakroEntry>::size(&v50[1032 * WeakIndex + 1512]) )
      {
        for ( k = 0; ; ++k )
        {
          v17 = std::vector<SMakroEntry>::size(&v50[1032 * WeakIndex + 1512]);
          if ( k >= v17 )
            break;
          v18 = std::vector<SMakroEntry>::operator[](k);
          CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v41, *(_DWORD *)(v18 + 12), &v31, &v30);
          v34 += v31;
          v35 += v30;
          ++v38;
        }
      }
    }
    if ( v38 <= 0 )
    {
      if ( std::vector<SMakroEntry>::size(v24) )
      {
        for ( k = 0; ; ++k )
        {
          v19 = std::vector<SMakroEntry>::size(v24);
          if ( k >= v19 )
            break;
          v20 = std::vector<SMakroEntry>::operator[](k);
          CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v41, *(_DWORD *)(v20 + 12), &v31, &v30);
          v34 += v31;
          v35 += v30;
          ++v38;
        }
        v26 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v41, v34 / v38, v35 / v38);
        v46 = *(_DWORD *)std::vector<SMakroEntry>::operator[](0);
        v47 = *(_DWORD *)(std::vector<SMakroEntry>::operator[](0) + 4);
        v48 = *(&v51 + 129 * WeakIndex);
        v49 = v26;
        std::vector<SMakroEntry>::push_back(&v46);
      }
    }
    else
    {
      v26 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v41, v34 / v38, v35 / v38);
      v46 = 0;
      v47 = 3;
      v48 = *(&v51 + 129 * WeakIndex);
      v49 = v26;
      std::vector<SMakroEntry>::push_back(&v46);
    }
    for ( i = 0; i < 7; ++i )
    {
      std::vector<SMakroEntry>::clear();
      v54[129 * i] = 0;
      v54[129 * i - 1] = 0;
    }
    std::vector<SMakroEntry>::clear();
  }
  v32 = std::vector<SMakroEntry>::size(a3) != 0;
  LOBYTE(v56) = 0;
  std::vector<SMakroEntry>::~vector<SMakroEntry>();
  v56 = -1;
  `eh vector destructor iterator'(v50, 0x204u, 7u, CProductionMakroData::~CProductionMakroData);
  return v32;
}


// address=[0x2f47a20]
// Decompiled from int __stdcall CSchedule::GetMakroIndex(int a1, int a2)
int  CSchedule::GetMakroIndex(class CProductionMakroData *,enum BUILDING_TYPES) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 7; ++i )
  {
    if ( *(_DWORD *)(a1 + 516 * i + 500) == a2 )
      return i;
  }
  return 7;
}


// address=[0x2f47a70]
// Decompiled from int __thiscall CSchedule::GetWeakIndex(int this, int a2, int a3, int a4, _DWORD *a5)
int  CSchedule::GetWeakIndex(class CProductionMakroData *,int,enum PILE_TYPES,int &) {
  
  int v8; // [esp+18h] [ebp-1Ch]
  float v9; // [esp+1Ch] [ebp-18h]
  int v10; // [esp+20h] [ebp-14h]
  int v11; // [esp+24h] [ebp-10h]
  int v12; // [esp+28h] [ebp-Ch]
  int j; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  v8 = 0;
  v12 = 0;
  for ( i = 6; i >= 0; --i )
  {
    if ( *(_DWORD *)(a2 + 516 * i + 500) )
    {
      v11 = *(_DWORD *)(a2 + 516 * i + 504);
      if ( v11 == 7 )
      {
        *(_DWORD *)(a2 + 516 * i + 512) = *(_DWORD *)(a2 + 516 * i + 508);
      }
      else
      {
        v10 = *(_DWORD *)(a2 + 516 * ((v11 - 1) / 2) + 508) + *(_DWORD *)(a2 + 516 * ((i - 1) / 2) + 508);
        *(_DWORD *)(a2 + 516 * i + 512) = 0;
        v9 = FLOAT_1_0;
        if ( v10 > 0 )
          v9 = (float)*(int *)(a2 + 516 * ((i - 1) / 2) + 508) / (float)v10;
        *(_DWORD *)(a2 + 516 * i + 512) = (int)(float)((float)*(int *)(a2 + 516 * i + 508) * v9);
      }
      if ( !*(_DWORD *)(a2 + 516 * i + 508) && *(_DWORD *)(a2 + 516 * i + 504) == 7 )
        return i;
      if ( i < 3 )
      {
        for ( j = 1; j < 3; ++j )
        {
          if ( *(_DWORD *)(a2 + 516 * (j + 2 * i) + 500) )
          {
            if ( *(_DWORD *)(a2 + 516 * (j + 2 * i) + 512) < *(_DWORD *)(a2 + 516 * i + 512) )
            {
              *(_DWORD *)(a2 + 516 * i + 512) = *(_DWORD *)(a2 + 516 * (j + 2 * i) + 512);
              v12 = *(_DWORD *)(a2 + 516 * i + 508) - *(_DWORD *)(a2 + 516 * (j + 2 * i) + 512);
            }
            if ( v12 > v8 )
            {
              v8 = v12;
              a3 = j + 2 * i;
              v12 = 0;
            }
          }
        }
      }
      if ( a4
        && a4 == CProductionDataTab::GetOutputTypePile(
                   *(void **)(this + 40),
                   *(_DWORD *)(a2 + 516 * i + 500),
                   *(_DWORD *)(this + 24)) )
      {
        *a5 += *(_DWORD *)(a2 + 516 * i + 512);
      }
    }
  }
  return a3;
}


// address=[0x2f47d70]
// Decompiled from int __thiscall CSchedule::GetPotentialGoodCapacity(_DWORD *this, int a2)
int  CSchedule::GetPotentialGoodCapacity(enum PILE_TYPES) {
  
  char v3[16]; // [esp+4h] [ebp-2Ch] BYREF
  int v4; // [esp+14h] [ebp-1Ch]
  int v5; // [esp+18h] [ebp-18h]
  int v6; // [esp+1Ch] [ebp-14h] BYREF
  _DWORD *v7; // [esp+20h] [ebp-10h]
  int v8; // [esp+2Ch] [ebp-4h]

  v7 = this;
  v6 = 0;
  std::vector<SMakroEntry>::vector<SMakroEntry>();
  v8 = 0;
  v5 = CProductionDataTab::GoodTypeProducedBy(v7[10], a2, 0, v7[6]);
  CSchedule::GetWeakBuilding(v5, v3, a2, &v6);
  v4 = v6;
  v8 = -1;
  std::vector<SMakroEntry>::~vector<SMakroEntry>();
  return v4;
}


// address=[0x2f47e10]
// Decompiled from int __stdcall CSchedule::CopyMakroBuildings(void *a1, int a2, int a3)
void  CSchedule::CopyMakroBuildings(struct SBuildId *,struct SBuildId *,int) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-4h]

  v4 = 0;
  memset(a1, 0, 8 * a3);
  while ( 1 )
  {
    result = a2;
    if ( !*(_DWORD *)(a2 + 8 * v4) || v4 >= a3 )
      break;
    *((_DWORD *)a1 + 2 * v4) = *(_DWORD *)(a2 + 8 * v4);
    *((_DWORD *)a1 + 2 * v4 + 1) = *(_DWORD *)(a2 + 8 * v4 + 4);
    ++v4;
  }
  return result;
}


// address=[0x2f47e90]
// Decompiled from char __stdcall CSchedule::BuildingInWeakArray(int a1, _DWORD *a2)
bool  CSchedule::BuildingInWeakArray(struct SBuildId *,struct SBuildId *) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; *(_DWORD *)(a1 + 8 * i); ++i )
  {
    if ( *(_DWORD *)(a1 + 8 * i) == *a2 && *(_DWORD *)(a1 + 8 * i + 4) == a2[1] )
      return 1;
  }
  return 0;
}


// address=[0x2f47ef0]
// Decompiled from char __stdcall CSchedule::CalcOptPositionForNewBuilding(int a1, _DWORD *a2, _DWORD *a3)
bool  CSchedule::CalcOptPositionForNewBuilding(struct SBuildId *,int &,int &) {
  
  *a2 = 500;
  *a3 = 400;
  return 0;
}


// address=[0x2f47f20]
// Decompiled from int __thiscall CSchedule::GetGoodPositionForBuilding(CSchedule *this, int a2)
int  CSchedule::GetGoodPositionForBuilding(enum BUILDING_TYPES) {
  
  _DWORD *v2; // eax
  _BYTE v4[16]; // [esp+4h] [ebp-104h] BYREF
  int v5; // [esp+14h] [ebp-F4h]
  int v6; // [esp+18h] [ebp-F0h] BYREF
  int v7; // [esp+1Ch] [ebp-ECh] BYREF
  struct IAIEcoManager *v8; // [esp+20h] [ebp-E8h]
  struct IAIEcoManager *v9; // [esp+24h] [ebp-E4h]
  struct IAIEcoManager *v10; // [esp+28h] [ebp-E0h]
  struct IAIEcoManager *EcoSector; // [esp+2Ch] [ebp-DCh]
  int v12; // [esp+30h] [ebp-D8h]
  int v13; // [esp+34h] [ebp-D4h]
  int v14; // [esp+38h] [ebp-D0h]
  int v15; // [esp+3Ch] [ebp-CCh] BYREF
  int v16; // [esp+40h] [ebp-C8h] BYREF
  int v17; // [esp+44h] [ebp-C4h]
  int v18; // [esp+48h] [ebp-C0h]
  int v19; // [esp+4Ch] [ebp-BCh]
  CSchedule *v20; // [esp+50h] [ebp-B8h]
  int i; // [esp+54h] [ebp-B4h]
  _DWORD v22[40]; // [esp+58h] [ebp-B0h] BYREF
  int v23; // [esp+104h] [ebp-4h]

  v20 = this;
  v14 = 0;
  i = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  std::vector<int>::vector<int>(v4);
  v23 = 0;
  v13 = a2;
  if ( a2 == 21 )
  {
    if ( CSchedule::GetAllBuildingOfType(v20, 20, v22) )
    {
      for ( i = 0; v22[2 * i] && i < 2; ++i )
      {
        if ( v22[2 * i + 1] == 1 )
        {
          CSchedule::GetPlannedBuildingPosition(v20, v22[2 * i], &v16, &v15);
        }
        else
        {
          EcoSector = CSchedule::GetEcoSector(v20);
          (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int *, int *))(*(_DWORD *)EcoSector + 52))(
            EcoSector,
            v22[2 * i],
            &v16,
            &v15);
        }
        v17 += v16;
        v18 += v15;
        ++v19;
      }
    }
    if ( v19 > 0 )
      v14 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v20, v17 / v19, v18 / v19);
  }
  else if ( v13 > 39 && v13 <= 42 )
  {
    v12 = *((_DWORD *)v20 + 6);
    if ( v12 >= 0 && (v12 <= 2 || v12 == 4) )
    {
      if ( CSchedule::GetAllBuildingOfType(v20, 3, v22) )
      {
        for ( i = 0; v22[2 * i] && i < 2; ++i )
        {
          if ( v22[2 * i + 1] == 1 )
          {
            CSchedule::GetPlannedBuildingPosition(v20, v22[2 * i], &v16, &v15);
          }
          else
          {
            v10 = CSchedule::GetEcoSector(v20);
            (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int *, int *))(*(_DWORD *)v10 + 52))(
              v10,
              v22[2 * i],
              &v16,
              &v15);
          }
          v17 += v16;
          v18 += v15;
          ++v19;
        }
      }
      if ( v19 <= 0 )
      {
        v9 = CSchedule::GetEcoSector(v20);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)v9 + 160))(v9, 46, v4);
        if ( std::vector<int>::size(v4) )
        {
          v8 = CSchedule::GetEcoSector(v20);
          v2 = (_DWORD *)std::vector<int>::operator[](0);
          (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int *, int *))(*(_DWORD *)v8 + 52))(v8, *v2, &v6, &v7);
          v14 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v20, v6, v7);
        }
      }
      else
      {
        v14 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v20, v17 / v19, v18 / v19);
      }
    }
  }
  v5 = v14;
  v23 = -1;
  std::vector<int>::~vector<int>();
  return v5;
}


// address=[0x2f48370]
// Decompiled from int __thiscall CSchedule::GetResidenceBuildingLevel(CSchedule *this)
enum BUILDING_TYPES  CSchedule::GetResidenceBuildingLevel(void) {
  
  struct IAIEcoManager *EcoSector; // [esp+0h] [ebp-8h]

  EcoSector = CSchedule::GetEcoSector(this);
  if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 156))(EcoSector, 41) > 2 )
    return 42;
  if ( CSchedule::GetNumberOfBuildingType(this, 3) < 2 || CSchedule::GetNumberOfBuildingType(this, 4) < 2 )
    return 41;
  return 42;
}


// address=[0x2f483d0]
// Decompiled from char __thiscall CSchedule::DestroySeveralBuildings(CSchedule *this)
bool  CSchedule::DestroySeveralBuildings(void) {
  
  _DWORD *v1; // eax
  _DWORD *v2; // eax
  _BYTE v4[16]; // [esp+4h] [ebp-5Ch] BYREF
  int v5; // [esp+14h] [ebp-4Ch]
  int v6; // [esp+18h] [ebp-48h]
  struct IAIEcoManager *v7; // [esp+1Ch] [ebp-44h]
  int v8; // [esp+20h] [ebp-40h]
  struct IAIEcoManager *v9; // [esp+24h] [ebp-3Ch]
  struct IAIEcoManager *v10; // [esp+28h] [ebp-38h]
  struct IAIEcoManager *v11; // [esp+2Ch] [ebp-34h]
  struct IAIEcoManager *v12; // [esp+30h] [ebp-30h]
  struct IAIEcoManager *v13; // [esp+34h] [ebp-2Ch]
  struct IAIEcoManager *EcoSector; // [esp+38h] [ebp-28h]
  int v15; // [esp+3Ch] [ebp-24h]
  int v16; // [esp+40h] [ebp-20h]
  int v17; // [esp+44h] [ebp-1Ch]
  int v18; // [esp+48h] [ebp-18h]
  CSchedule *v19; // [esp+4Ch] [ebp-14h]
  char v20; // [esp+51h] [ebp-Fh]
  char v21; // [esp+52h] [ebp-Eh]
  char v22; // [esp+53h] [ebp-Dh]
  int v23; // [esp+5Ch] [ebp-4h]

  v19 = this;
  v17 = 0;
  v22 = 0;
  v18 = 0;
  v15 = 0;
  std::vector<int>::vector<int>(v4);
  v23 = 0;
  EcoSector = CSchedule::GetEcoSector(v19);
  v5 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)EcoSector + 284))(EcoSector);
  v13 = CSchedule::GetEcoSector(v19);
  v6 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v13 + 288))(v13);
  while ( !v22 && v17 < 10 )
  {
    v16 = v17;
    if ( v17 )
    {
      if ( v16 == 1 )
        v22 = 0;
    }
    else
    {
      v15 = v6 - v5;
      if ( v6 - v5 > 40 )
      {
        v12 = CSchedule::GetEcoSector(v19);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)v12 + 160))(v12, 42, v4);
        if ( std::vector<int>::size(v4) )
        {
          v11 = CSchedule::GetEcoSector(v19);
          v1 = (_DWORD *)std::vector<int>::operator[](0);
          if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v11 + 76))(v11, *v1) )
            goto LABEL_10;
        }
      }
      if ( v15 > 15 )
      {
        v10 = CSchedule::GetEcoSector(v19);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)v10 + 160))(v10, 41, v4);
        if ( std::vector<int>::size(v4) )
        {
          v9 = CSchedule::GetEcoSector(v19);
          v2 = (_DWORD *)std::vector<int>::operator[](0);
          if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v9 + 76))(v9, *v2) )
          {
LABEL_10:
            v18 = *(_DWORD *)std::vector<int>::operator[](0);
            v8 = 42;
            v22 = 1;
          }
        }
      }
    }
    ++v17;
  }
  if ( v18 )
  {
    BBSupportTracePrintF(
      3,
      "AI_BuildingEvent::PlayerNr %i destroy %s with ID %i for getting require material",
      *((_DWORD *)v19 + 5),
      (&off_3ABC174)[2 * v8],
      v18);
    v7 = CSchedule::GetEcoSector(v19);
    (*(void (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v7 + 104))(v7, v18);
    v21 = 1;
    v23 = -1;
    std::vector<int>::~vector<int>();
    return v21;
  }
  else
  {
    v20 = 0;
    v23 = -1;
    std::vector<int>::~vector<int>();
    return v20;
  }
}


// address=[0x2f48640]
// Decompiled from char __stdcall CSchedule::SharedPileType(int a1)
bool  CSchedule::SharedPileType(enum PILE_TYPES) {
  
  char result; // al

  switch ( a1 )
  {
    case 7:
    case 9:
    case 10:
    case 11:
    case 16:
    case 20:
    case 24:
    case 36:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x2f486b0]
// Decompiled from int __thiscall CSchedule::GetAllBuildingOfType(CSchedule *this, int a2, _DWORD *a3)
int  CSchedule::GetAllBuildingOfType(enum BUILDING_TYPES,struct SBuildId *) {
  
  unsigned int v3; // eax
  _DWORD *v4; // eax
  int v5; // eax
  _BYTE v7[16]; // [esp+4h] [ebp-38h] BYREF
  int v8; // [esp+14h] [ebp-28h]
  struct IAIEcoManager *EcoSector; // [esp+18h] [ebp-24h]
  _DWORD *v10; // [esp+1Ch] [ebp-20h]
  CDynList **v11; // [esp+20h] [ebp-1Ch]
  _DWORD *v12; // [esp+24h] [ebp-18h]
  int v13; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  int v15; // [esp+38h] [ebp-4h]

  v11 = (CDynList **)this;
  v13 = 0;
  v12 = 0;
  std::vector<int>::vector<int>(v7);
  v15 = 0;
  EcoSector = CSchedule::GetEcoSector((CSchedule *)v11);
  (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)EcoSector + 160))(EcoSector, a2, v7);
  *a3 = 0;
  for ( i = 0; ; ++i )
  {
    v3 = std::vector<int>::size(v7);
    if ( i >= v3 )
      break;
    v4 = (_DWORD *)std::vector<int>::operator[](i);
    a3[2 * i] = *v4;
    a3[2 * i + 1] = 3;
    a3[2 * i + 2] = 0;
  }
  v13 = std::vector<int>::size(v7);
  for ( i = 0; ; ++i )
  {
    v5 = CDynList::size(v11[1]);
    if ( i >= v5 )
      break;
    v10 = (_DWORD *)CDynList::elementAt(v11[1], i);
    if ( v10[5] != 3 && v10[4] == 9 )
    {
      v12 = v10;
      if ( v10[14] == 1 && v12[11] == a2 )
      {
        a3[2 * v13] = v12[12];
        a3[2 * v13 + 1] = 1;
        a3[2 * v13++ + 2] = 0;
      }
    }
  }
  v8 = v13;
  v15 = -1;
  std::vector<int>::~vector<int>();
  return v8;
}


// address=[0x2f48850]
// Decompiled from int __thiscall CSchedule::GetAllBuildingOfTypeInProdControl(CDynList **this, int a2, int a3)
int  CSchedule::GetAllBuildingOfTypeInProdControl(enum BUILDING_TYPES,struct SBuildId *) {
  
  char v4[16]; // [esp+4h] [ebp-34h] BYREF
  int v5; // [esp+14h] [ebp-24h]
  CDynList **v6; // [esp+18h] [ebp-20h]
  CDynListEntry *v7; // [esp+1Ch] [ebp-1Ch]
  CDynListEntry *v8; // [esp+20h] [ebp-18h]
  CDynListEntry *i; // [esp+24h] [ebp-14h]
  int v10; // [esp+28h] [ebp-10h]
  int v11; // [esp+34h] [ebp-4h]

  v6 = this;
  v10 = 0;
  v8 = 0;
  std::vector<int>::vector<int>(v4);
  v11 = 0;
  for ( i = CDynList::FirstEntry(v6[1]); i; i = (CDynListEntry *)CDynListEntry::Next(i) )
  {
    v7 = i;
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)v7 + 4) == 2 )
    {
      v8 = v7;
      if ( *((_DWORD *)v7 + 21) == a2 )
      {
        *(_DWORD *)(a3 + 8 * v10) = *((_DWORD *)v8 + 11);
        *(_DWORD *)(a3 + 8 * v10 + 4) = *((_DWORD *)v8 + 12);
        *(_DWORD *)(a3 + 8 * v10++ + 8) = 0;
        if ( v10 >= 20
          && BBSupportDbgReport(2, "Source\\EcoAI_Schedule.cpp", 2132, "iCountBuildings < MAX_BUILDING_OF_TYPE") == 1 )
        {
          __debugbreak();
        }
      }
    }
  }
  v5 = v10;
  v11 = -1;
  std::vector<int>::~vector<int>();
  return v5;
}


// address=[0x2f48970]
// Decompiled from int __thiscall CSchedule::GetPlannedBuildingId(CReserveDatabase **this, int a2, int a3)
int  CSchedule::GetPlannedBuildingId(int,int) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-18h] BYREF
  int v6; // [esp+4h] [ebp-14h] BYREF
  _DWORD *v7; // [esp+8h] [ebp-10h]
  CReserveDatabase **v8; // [esp+Ch] [ebp-Ch]
  _DWORD *v9; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v8 = this;
  v7 = 0;
  for ( i = 0; ; ++i )
  {
    v3 = CDynList::size(v8[1]);
    if ( i >= v3 )
      break;
    v9 = (_DWORD *)CDynList::elementAt(v8[1], i);
    if ( v9[5] != 3 && v9[4] == 9 )
    {
      v7 = v9;
      CReserveDatabase::UnpackPosition(*v8, v9[17], &v6, &v5);
      if ( v6 == a2 && v5 == a3 )
        return v7[12];
    }
  }
  return 0;
}


// address=[0x2f48a10]
// Decompiled from int __thiscall CSchedule::GetNumberOfBuildingType(CDynList **this, int a2)
int  CSchedule::GetNumberOfBuildingType(enum BUILDING_TYPES) {
  
  int v3; // [esp+8h] [ebp-Ch]
  struct CDynListEntry *i; // [esp+10h] [ebp-4h]

  v3 = 0;
  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)i + 4) == 2 && *((_DWORD *)i + 21) == a2 )
      ++v3;
  }
  return v3;
}


// address=[0x2f48a90]
// Decompiled from int __thiscall CSchedule::GetNumberOfBuildingTypeAtBuilding(CDynList **this, int a2, int a3, int a4)
int  CSchedule::GetNumberOfBuildingTypeAtBuilding(enum BUILDING_TYPES,int,int) {
  
  struct IAIEcoManager *EcoSector; // eax
  _DWORD *v6; // [esp+4h] [ebp-14h]
  int NumberOfBuildingTypeAtWork; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  NumberOfBuildingTypeAtWork = 0;
  if ( a4 )
    NumberOfBuildingTypeAtWork = CSchedule::GetNumberOfBuildingTypeAtWork(this, a2);
  for ( i = 0; i < CDynList::size(this[1]); ++i )
  {
    v6 = (_DWORD *)CDynList::elementAt(this[1], i);
    if ( v6[5] != 3 && v6[4] == 9 && v6[11] == a2 && (int)v6[14] > 1 && v6[13] != 1 && a3 )
    {
      EcoSector = CSchedule::GetEcoSector((CSchedule *)this);
      if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 68))(EcoSector, v6[12]) > a3 )
        ++NumberOfBuildingTypeAtWork;
    }
  }
  return NumberOfBuildingTypeAtWork;
}


// address=[0x2f48b70]
// Decompiled from int __thiscall CSchedule::GetNumberOfBuildingTypeAtWork(CDynList **this, int a2)
int  CSchedule::GetNumberOfBuildingTypeAtWork(enum BUILDING_TYPES) {
  
  int v3; // [esp+4h] [ebp-10h]
  struct CDynListEntry *i; // [esp+10h] [ebp-4h]

  v3 = 0;
  for ( i = CDynList::FirstEntry(this[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 5) != 3 && *((_DWORD *)i + 4) == 2 && *((_DWORD *)i + 21) == a2 && *((_DWORD *)i + 12) == 3 )
      ++v3;
  }
  return v3;
}


// address=[0x2f48c00]
// Decompiled from void __thiscall CSchedule::GetPlannedBuildingPosition(CDynList **this, int a2, int *a3, int *a4)
void  CSchedule::GetPlannedBuildingPosition(int,int &,int &) {
  
  _DWORD *v5; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < CDynList::size(this[1]); ++i )
  {
    v5 = (_DWORD *)CDynList::elementAt(this[1], i);
    if ( v5[5] != 3 && v5[4] == 9 && v5[12] == a2 )
    {
      CReserveDatabase::UnpackPosition(*this, v5[17], a3, a4);
      return;
    }
  }
}


// address=[0x2f48c90]
// Decompiled from int __thiscall CSchedule::CollectPlannedBuildingPlaces(CDynList **this, struct CReserveEntry *a2)
int  CSchedule::CollectPlannedBuildingPlaces(class CReserveEntry *) {
  
  int v4; // [esp+8h] [ebp-14h]
  int v5; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int v7; // [esp+18h] [ebp-4h]

  v4 = 0;
  while ( *((_DWORD *)a2 + 3) )
    ++v4;
  v7 = v4;
  for ( i = 0; i < CDynList::size(this[1]); ++i )
  {
    v5 = CDynList::elementAt(this[1], i);
    if ( *(_DWORD *)(v5 + 20) != 3 && *(_DWORD *)(v5 + 16) == 9 && *(_DWORD *)(v5 + 56) == 1 )
    {
      *((_DWORD *)a2 + 11 * v7 + 3) = *(_DWORD *)(v5 + 44);
      *((_DWORD *)a2 + 11 * v7++ + 9) = *(_DWORD *)(v5 + 68);
    }
    if ( *(_DWORD *)(v5 + 16) == 5 )
      v7 += CResourceManagerTask::FillRareBuildings((CDynList **)v5, a2, v7);
  }
  return v7;
}


// address=[0x2f48da0]
// Decompiled from int __thiscall CSchedule::GetNextPositionInside(CSchedule *this, int a2, int a3)
int  CSchedule::GetNextPositionInside(int,int) {
  
  unsigned int v3; // eax
  _DWORD *v4; // eax
  int v6; // [esp+18h] [ebp-34h]
  int v7; // [esp+1Ch] [ebp-30h]
  int v8; // [esp+20h] [ebp-2Ch]
  int v9; // [esp+24h] [ebp-28h] BYREF
  int v10; // [esp+28h] [ebp-24h] BYREF
  int v11; // [esp+2Ch] [ebp-20h]
  struct IScheduleEntry *SpecialTask; // [esp+30h] [ebp-1Ch]
  int v13; // [esp+34h] [ebp-18h]
  CSchedule *v14; // [esp+38h] [ebp-14h]
  unsigned int i; // [esp+3Ch] [ebp-10h]
  int v16; // [esp+48h] [ebp-4h]

  v14 = this;
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::vector<SUNDERGROUNDCONCENTRATIONDATA>();
  v16 = 0;
  v11 = 100;
  v7 = 0;
  v8 = 0;
  v13 = 0;
  SpecialTask = CSchedule::GetSpecialTask(v14, 6);
  for ( i = 0; ; ++i )
  {
    v3 = std::vector<int>::size((char *)SpecialTask + 52);
    if ( i >= v3 )
      break;
    v4 = (_DWORD *)std::vector<int>::operator[](i);
    CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v14, *v4, &v10, &v9);
    v13 = CSchedule::CalcDistance(v14, a2, a3, v10, v9);
    if ( v13 < v11 )
    {
      v11 = v13;
      v7 = v10;
      v8 = v9;
    }
  }
  v6 = CReserveDatabase::PackPosition(*(CReserveDatabase **)v14, v7, v8);
  v16 = -1;
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::~vector<SUNDERGROUNDCONCENTRATIONDATA>();
  return v6;
}


// address=[0x2f48ec0]
// Decompiled from char __thiscall CSchedule::BestAndPossiblePlaceOf8Grid(  CSchedule *this,  int a2,  _DWORD *a3,  int a4,  int *a5,  int *a6,  int a7,  int a8,  unsigned __int8 a9)
bool  CSchedule::BestAndPossiblePlaceOf8Grid(enum BUILDING_TYPES,struct SBUILDINFODATA *,class CReserveEntry *,int &,int &,int,int,bool) {
  
  struct IAIEcoManager *v9; // eax
  _DWORD *v10; // eax
  int v12; // [esp-8h] [ebp-44h]
  int v13; // [esp-4h] [ebp-40h]
  int v14; // [esp+0h] [ebp-3Ch] BYREF
  int v15; // [esp+4h] [ebp-38h] BYREF
  int v16; // [esp+8h] [ebp-34h] BYREF
  int v17[2]; // [esp+Ch] [ebp-30h] BYREF
  int v18; // [esp+14h] [ebp-28h]
  int v19; // [esp+18h] [ebp-24h]
  int v20; // [esp+1Ch] [ebp-20h]
  struct IAIEcoManager *EcoSector; // [esp+20h] [ebp-1Ch]
  int v22; // [esp+24h] [ebp-18h]
  int v23; // [esp+28h] [ebp-14h]
  int v24; // [esp+2Ch] [ebp-10h]
  CReserveDatabase **v25; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  char v27; // [esp+3Bh] [ebp-1h]

  v25 = (CReserveDatabase **)this;
  v23 = 0;
  v17[1] = 0;
  v22 = 0;
  v20 = 0;
  v27 = 0;
  v24 = std::vector<SPOSS_BUILD_PLACE>::size();
  if ( v24 > 256 && BBSupportDbgReport(2, "Source\\EcoAI_Schedule.cpp", 2631, "iCountBuildingPlaces <= 256") == 1 )
    __debugbreak();
  CReserveDatabase::UnpackPosition(*v25, a7, &v16, v17);
  CReserveDatabase::UnpackPosition(*v25, a8, &v14, &v15);
  v18 = v24 / 20 + 1;
  v19 = a2;
  if ( a2 == 5 )
  {
    EcoSector = CSchedule::GetEcoSector((CSchedule *)v25);
    a8 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, _DWORD))(*(_DWORD *)EcoSector + 260))(
           EcoSector,
           *a3,
           a3[1]);
  }
  for ( i = 0; i < v24; i += v18 )
  {
    v12 = *(_DWORD *)std::vector<SPOSS_BUILD_PLACE>::operator[](i);
    v9 = CSchedule::GetEcoSector((CSchedule *)v25);
    if ( CReserveDatabase::IsBuildingPlaceAvailable(*v25, (int)v9, a2, v12, a4) )
    {
      v13 = *(char *)(std::vector<SPOSS_BUILD_PLACE>::operator[](i) + 4);
      v10 = (_DWORD *)std::vector<SPOSS_BUILD_PLACE>::operator[](i);
      v23 = CSchedule::GeneralValuation(v25, a2, 1, *v10, a7, a8, a9, v13);
      if ( v23 > v22 )
      {
        v22 = v23;
        v20 = i;
        v27 = 1;
      }
    }
  }
  *a5 = v22;
  *a6 = v20;
  return v27;
}


// address=[0x2f49070]
// Decompiled from int __thiscall CSchedule::GeneralValuation(CDynList **this, int a2, int a3, int a4, int a5, int a6, char a7, int a8)
int  CSchedule::GeneralValuation(enum BUILDING_TYPES,int,int,int,int,bool,int) {
  
  int SumResourceAmount; // eax
  int HasOtherResource; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  _DWORD *v13; // eax
  int v14; // eax
  _BYTE v16[16]; // [esp+4h] [ebp-7Ch] BYREF
  int v17; // [esp+14h] [ebp-6Ch]
  int v18; // [esp+18h] [ebp-68h]
  int v19; // [esp+1Ch] [ebp-64h]
  int v20; // [esp+20h] [ebp-60h]
  int v21; // [esp+24h] [ebp-5Ch]
  struct IAIEcoManager *v22; // [esp+28h] [ebp-58h]
  struct IAIEcoManager *v23; // [esp+2Ch] [ebp-54h]
  struct IAIEcoManager *v24; // [esp+30h] [ebp-50h]
  struct IAIEcoManager *v25; // [esp+34h] [ebp-4Ch]
  struct IAIEcoManager *v26; // [esp+38h] [ebp-48h]
  struct IAIEcoManager *EcoSector; // [esp+3Ch] [ebp-44h]
  int v28; // [esp+40h] [ebp-40h]
  int v29; // [esp+44h] [ebp-3Ch] BYREF
  int v30; // [esp+48h] [ebp-38h] BYREF
  unsigned int i; // [esp+4Ch] [ebp-34h]
  int v32; // [esp+50h] [ebp-30h]
  int v33; // [esp+54h] [ebp-2Ch]
  int v34; // [esp+58h] [ebp-28h] BYREF
  int v35; // [esp+5Ch] [ebp-24h] BYREF
  int v36; // [esp+60h] [ebp-20h]
  int v37; // [esp+64h] [ebp-1Ch] BYREF
  int v38; // [esp+68h] [ebp-18h] BYREF
  int v39; // [esp+6Ch] [ebp-14h]
  CDynList **v40; // [esp+70h] [ebp-10h]
  int v41; // [esp+7Ch] [ebp-4h]
  int v42; // [esp+98h] [ebp+18h]

  v40 = this;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  v39 = 0;
  v21 = 0;
  v33 = 0;
  std::vector<int>::vector<int>(v16);
  v41 = 0;
  v32 = a2 - 1;
  switch ( a2 )
  {
    case 1:
    case 4:
    case 6:
    case 7:
    case 11:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 35:
    case 36:
    case 38:
    case 82:
      CReserveDatabase::UnpackPosition(*v40, a4, &v37, &v38);
      if ( a3 == 1 )
      {
        v37 /= 16;
        v38 /= 16;
      }
      SumResourceAmount = CSchedule::GetSumResourceAmount((int)v40, a2, a4, 0, a3);
      v39 += 10 * SumResourceAmount;
      HasOtherResource = CSchedule::AreaHasOtherResource(v40, a2, v37, v38);
      v39 -= 10 * HasOtherResource;
      break;
    case 2:
    case 3:
    case 8:
    case 9:
    case 10:
    case 12:
    case 19:
    case 20:
    case 21:
    case 22:
    case 25:
    case 37:
    case 39:
    case 43:
    case 81:
      CReserveDatabase::UnpackPosition(*v40, a4, &v37, &v38);
      v39 = 2000 - 10 * a8;
      v10 = CSchedule::AreaHasOtherResource(v40, a2, v37, v38);
      v39 -= 30 * v10;
      CReserveDatabase::UnpackPosition(*v40, a5, &v34, &v35);
      v11 = CSchedule::CalcDistance((CSchedule *)v40, v37, v38, v34, v35);
      v39 += 1000 - 10 * v11;
      if ( a6 > 0 )
      {
        CReserveDatabase::UnpackPosition(*v40, a6, &v29, &v30);
        v36 = CSchedule::CalcDistance((CSchedule *)v40, v37, v38, v29, v30);
        v28 = CSchedule::CalcDistance((CSchedule *)v40, v34, v35, v29, v30);
        if ( v28 < v36 )
          v39 -= 200 * (v36 - v28);
        if ( a7 == 1 )
          v39 += 1000 - 10 * v36;
      }
      break;
    case 5:
      CReserveDatabase::UnpackPosition(*v40, a4, &v37, &v38);
      CReserveDatabase::UnpackPosition(*v40, a5, &v34, &v35);
      if ( a6 )
        v33 = CSchedule::CalcDistance((CSchedule *)v40, a4, a6);
      EcoSector = CSchedule::GetEcoSector((CSchedule *)v40);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)EcoSector + 228))(
             EcoSector,
             v37 / 16,
             v38 / 16) )
      {
        v26 = CSchedule::GetEcoSector((CSchedule *)v40);
        v42 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v26 + 260))(v26, v37 / 16, v38 / 16);
        v33 = CSchedule::CalcDistance((CSchedule *)v40, a4, v42);
      }
      else
      {
        v33 = 25;
      }
      v36 = CSchedule::CalcDistance((CSchedule *)v40, v37, v38, v34, v35);
      if ( a3 == 1 )
      {
        v37 /= 16;
        v38 /= 16;
      }
      v25 = CSchedule::GetEcoSector((CSchedule *)v40);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v25 + 232))(v25, v37, v38) )
        v39 = 1500 - v36 - 25 * v33;
      v24 = CSchedule::GetEcoSector((CSchedule *)v40);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v24 + 228))(v24, v37, v38) )
        v39 = 2000 - v36 - 25 * v33;
      break;
    case 24:
    case 40:
    case 41:
    case 42:
    case 44:
      v39 = 1000 - 80 * a8;
      break;
    case 46:
    case 47:
      CReserveDatabase::UnpackPosition(*v40, a4, &v37, &v38);
      v39 = 1000 - 3 * a8;
      CReserveDatabase::UnpackPosition(*v40, a6, &v29, &v30);
      v23 = CSchedule::GetEcoSector((CSchedule *)v40);
      (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)v23 + 160))(v23, a2, v16);
      for ( i = 0; ; ++i )
      {
        v12 = std::vector<int>::size(v16);
        if ( i >= v12 )
          break;
        v22 = CSchedule::GetEcoSector((CSchedule *)v40);
        v13 = (_DWORD *)std::vector<int>::operator[](i);
        (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int *, int *))(*(_DWORD *)v22 + 52))(
          v22,
          *v13,
          &v34,
          &v35);
        v21 = CSchedule::CalcDistance((CSchedule *)v40, v34, v35, v37, v38);
        if ( v21 < 20 / a3 )
          v39 -= 1000;
      }
      v14 = CSchedule::CalcDistance((CSchedule *)v40, v37, v38, v29, v30);
      v39 -= 5 * v14;
      break;
    default:
      if ( v39 <= 0 && BBSupportDbgReport(2, "Source\\EcoAI_Schedule.cpp", 2906, "iCurScore > 0") == 1 )
        __debugbreak();
      break;
  }
  v20 = v39;
  v41 = -1;
  std::vector<int>::~vector<int>();
  return v20;
}


// address=[0x2f495f0]
// Decompiled from int __stdcall CSchedule::PreferBuildingPlaces(int a1, int a2)
int  CSchedule::PreferBuildingPlaces(enum BUILDING_TYPES,class CReserveEntry *) {
  
  return 0;
}


// address=[0x2f49610]
// Decompiled from char __thiscall CSchedule::ReadMessages(CDynList **this)
bool  CSchedule::ReadMessages(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // eax
  int v19; // [esp-4h] [ebp-B8h]
  int v20; // [esp-4h] [ebp-B8h]
  int v21; // [esp-4h] [ebp-B8h]
  int v22; // [esp-4h] [ebp-B8h]
  struct IScheduleEntry *v23; // [esp+10h] [ebp-A4h]
  void *C; // [esp+14h] [ebp-A0h]
  struct IAIEcoManager *v25; // [esp+18h] [ebp-9Ch]
  struct IAIEcoManager *v26; // [esp+1Ch] [ebp-98h]
  struct IAIEcoManager *v27; // [esp+20h] [ebp-94h]
  struct IAIEcoManager *v28; // [esp+24h] [ebp-90h]
  struct IAIEcoManager *v29; // [esp+28h] [ebp-8Ch]
  int v30; // [esp+2Ch] [ebp-88h]
  struct IAIEcoManager *v31; // [esp+30h] [ebp-84h]
  struct IAIEcoManager *v32; // [esp+34h] [ebp-80h]
  struct IAIEcoManager *v33; // [esp+38h] [ebp-7Ch]
  struct IAIEcoManager *v34; // [esp+3Ch] [ebp-78h]
  struct IAIEcoManager *v35; // [esp+40h] [ebp-74h]
  struct IAIEcoManager *v36; // [esp+44h] [ebp-70h]
  struct IAIEcoManager *v37; // [esp+48h] [ebp-6Ch]
  int v38; // [esp+4Ch] [ebp-68h] BYREF
  int v39; // [esp+50h] [ebp-64h] BYREF
  struct IAIEcoManager *v40; // [esp+54h] [ebp-60h]
  struct IAIEcoManager *v41; // [esp+58h] [ebp-5Ch]
  struct IAIEcoManager *v42; // [esp+5Ch] [ebp-58h]
  struct IAIEcoManager *v43; // [esp+60h] [ebp-54h]
  struct IAIEcoManager *v44; // [esp+64h] [ebp-50h]
  struct IAIEcoManager *EcoSector; // [esp+68h] [ebp-4Ch]
  struct IScheduleEntry *SpecialTask; // [esp+6Ch] [ebp-48h]
  int v47; // [esp+70h] [ebp-44h]
  int v48; // [esp+74h] [ebp-40h]
  int v49; // [esp+78h] [ebp-3Ch]
  _BYTE v50[16]; // [esp+7Ch] [ebp-38h] BYREF
  int v51; // [esp+8Ch] [ebp-28h]
  int v52; // [esp+90h] [ebp-24h]
  struct CDynListEntry *ProductivityControll; // [esp+94h] [ebp-20h]
  struct CDynListEntry *BuildingEvent; // [esp+98h] [ebp-1Ch]
  int v55; // [esp+9Ch] [ebp-18h]
  CDynList **v56; // [esp+A0h] [ebp-14h]
  char v57; // [esp+A7h] [ebp-Dh]
  int v58; // [esp+B0h] [ebp-4h]

  v56 = this;
  CAIEvent::CAIEvent((CAIEvent *)v50, 0, 0, 0, 0);
  EcoSector = CSchedule::GetEcoSector((CSchedule *)v56);
  v48 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)EcoSector + 336))(EcoSector);
  ProductivityControll = 0;
  SpecialTask = 0;
  v57 = 0;
  if ( !v48 )
    return 0;
  while ( (*(unsigned __int8 (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v48 + 8))(v48, v50, 1) )
  {
    v2 = CAIEvent::Type((CAIEvent *)v50);
    v49 = v2 - 4;
    switch ( v2 )
    {
      case 4:
        v51 = CAIEvent::Data2((CAIEvent *)v50);
        v33 = CSchedule::GetEcoSector((CSchedule *)v56);
        v34 = CSchedule::GetEcoSector((CSchedule *)v56);
        v8 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v34 + 132))(v34);
        v9 = CAIEvent::Data2((CAIEvent *)v50);
        if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v33 + 96))(v33, v9) == v8 )
        {
          v52 = 3;
          BuildingEvent = CSchedule::GetBuildingEvent(v56, v51, 2);
          if ( BuildingEvent )
          {
            v52 = 2;
            *((_DWORD *)BuildingEvent + 5) = 3;
          }
          ProductivityControll = CSchedule::GetProductivityControll(v56, v51, v52);
          if ( ProductivityControll )
            *((_DWORD *)ProductivityControll + 5) = 3;
          v19 = CAIEvent::Data1((CAIEvent *)v50);
          v10 = CAIEvent::Data2((CAIEvent *)v50);
          BBSupportTracePrintF(3, "AI Building %i died from PlayerNr %i", v10, v19);
          v57 = 1;
        }
        break;
      case 5:
        v55 = CAIEvent::Data2((CAIEvent *)v50);
        v3 = CAIEvent::Data1((CAIEvent *)v50);
        BBSupportTracePrintF(3, "AI Building %i birth from PlayerNr %i", v55, v3);
        v44 = CSchedule::GetEcoSector((CSchedule *)v56);
        if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v44 + 304))(v44, v55) )
        {
          v42 = CSchedule::GetEcoSector((CSchedule *)v56);
          v43 = CSchedule::GetEcoSector((CSchedule *)v56);
          v4 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v43 + 132))(v43);
          if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v42 + 96))(v42, v55) == v4 )
          {
            v41 = CSchedule::GetEcoSector((CSchedule *)v56);
            (*(void (__thiscall **)(struct IAIEcoManager *, int, int *, int *))(*(_DWORD *)v41 + 52))(
              v41,
              v55,
              &v38,
              &v39);
            BuildingEvent = CSchedule::GetBuildingAtPosition(v56, v38, v39);
            if ( BuildingEvent )
            {
              CSchedule::ChangeBuildingLevel(v56, *((_DWORD *)BuildingEvent + 12), v55, 2);
              *((_DWORD *)BuildingEvent + 12) = v55;
              *((_DWORD *)BuildingEvent + 13) = 2;
              *((_DWORD *)BuildingEvent + 14) = 4;
            }
            v51 = v55;
            v52 = 2;
            v40 = CSchedule::GetEcoSector((CSchedule *)v56);
            v47 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v40 + 72))(v40, v55);
            v5 = CAIEvent::Data1((CAIEvent *)v50);
            BBSupportTracePrintF(3, "AI BuildingType %s birth from PlayerNr %i", (&off_3ABC174)[2 * v47], v5);
            ProductivityControll = CSchedule::GetProductivityControll(v56, v51, v52);
            if ( !ProductivityControll && CProductionDataTab::BuildingMustBeControl(v56[10], v47, (int)v56[6]) )
            {
              C = operator new(0x70u);
              v58 = 0;
              if ( C )
              {
                v6 = CReserveDatabase::PackPosition(*v56, v38, v39);
                v23 = (struct IScheduleEntry *)CProductivityControll::CProductivityControll(C, v55, 2, v47, v6, 0);
              }
              else
              {
                v23 = 0;
              }
              v58 = -1;
              CSchedule::NewSchedEntry((CSchedule *)v56, v23);
            }
            v57 = 1;
          }
        }
        break;
      case 6:
        v55 = CAIEvent::Data2((CAIEvent *)v50);
        v37 = CSchedule::GetEcoSector((CSchedule *)v56);
        if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v37 + 304))(v37, v55) )
        {
          v35 = CSchedule::GetEcoSector((CSchedule *)v56);
          v36 = CSchedule::GetEcoSector((CSchedule *)v56);
          v7 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v36 + 132))(v36);
          if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v35 + 96))(v35, v55) == v7 )
          {
            BuildingEvent = CSchedule::GetBuildingEvent(v56, v55, 2);
            if ( BuildingEvent )
            {
              v52 = 2;
              *((_DWORD *)BuildingEvent + 14) = 7;
              *((_DWORD *)BuildingEvent + 13) = 3;
            }
            CSchedule::ChangeBuildingLevel(v56, v55, v55, 3);
            v57 = 1;
          }
        }
        break;
      case 7:
        v51 = CAIEvent::Data2((CAIEvent *)v50);
        v52 = 3;
        v26 = CSchedule::GetEcoSector((CSchedule *)v56);
        v27 = CSchedule::GetEcoSector((CSchedule *)v56);
        v16 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v27 + 132))(v27);
        v17 = CAIEvent::Data2((CAIEvent *)v50);
        if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v26 + 96))(v26, v17) == v16 )
        {
          ProductivityControll = CSchedule::GetProductivityControll(v56, v51, v52);
          if ( ProductivityControll )
            v57 = 1;
        }
        break;
      case 8:
        SpecialTask = CSchedule::GetSpecialTask((CSchedule *)v56, 8);
        v28 = CSchedule::GetEcoSector((CSchedule *)v56);
        v29 = CSchedule::GetEcoSector((CSchedule *)v56);
        v13 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v29 + 132))(v29);
        v14 = CAIEvent::Data2((CAIEvent *)v50);
        if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v28 + 96))(v28, v14) == v13 )
        {
          if ( SpecialTask )
            *((_BYTE *)SpecialTask + 60) = 1;
          v57 = 1;
          v21 = CAIEvent::Data1((CAIEvent *)v50);
          v15 = CAIEvent::Data2((CAIEvent *)v50);
          BBSupportTracePrintF(3, "AI Residence %i empty from PlayerNr %i", v15, v21);
        }
        break;
      case 10:
        v30 = CAIEvent::Data2((CAIEvent *)v50);
        v31 = CSchedule::GetEcoSector((CSchedule *)v56);
        v32 = CSchedule::GetEcoSector((CSchedule *)v56);
        v11 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v32 + 132))(v32);
        if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v31 + 96))(v31, v30) == v11 )
        {
          CSchedule::UpdateExpandationEvents(v56, v30);
          v57 = 1;
          v20 = CAIEvent::Data1((CAIEvent *)v50);
          v12 = CAIEvent::Data2((CAIEvent *)v50);
          BBSupportTracePrintF(3, "AI Tower %i  occupied from PlayerNr %i", v12, v20);
        }
        break;
      case 12:
        v57 = 1;
        break;
      case 30:
        v25 = CSchedule::GetEcoSector((CSchedule *)v56);
        (*(void (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)v25 + 132))(v25);
        v22 = CAIEvent::Data2((CAIEvent *)v50);
        v18 = CAIEvent::Data1((CAIEvent *)v50);
        CSchedule::ProduceWeapons((CSchedule *)v56, v18, v22);
        v57 = 1;
        break;
      default:
        v57 = 1;
        break;
    }
  }
  return v57;
}


// address=[0x2f4c780]
// Decompiled from int __thiscall CSchedule::CalcDistance(CReserveDatabase **this, int a2, int a3)
int  CSchedule::CalcDistance(int,int) {
  
  int v4; // [esp+0h] [ebp-28h]
  int v5; // [esp+4h] [ebp-24h] BYREF
  int v6; // [esp+8h] [ebp-20h] BYREF
  int v7; // [esp+Ch] [ebp-1Ch] BYREF
  int v8; // [esp+10h] [ebp-18h] BYREF
  CReserveDatabase **v11; // [esp+1Ch] [ebp-Ch]
  int v12; // [esp+20h] [ebp-8h]
  int Number; // [esp+24h] [ebp-4h]

  v11 = this;
  CReserveDatabase::UnpackPosition(*this, a2, &v7, &v5);
  CReserveDatabase::UnpackPosition(*v11, a3, &v8, &v6);
  Number = v8 - v7;
  v12 = v6 - v5;
  v4 = (v6 - v5) ^ (v8 - v7);
  Number = j__abs(v8 - v7);
  v12 = j__abs(v12);
  if ( v4 < 0 )
    return v12 + Number;
  if ( Number >= v12 )
    return Number;
  else
    return v12;
}


// address=[0x2f4c850]
// Decompiled from int __thiscall CSchedule::CalcDistance(CSchedule *this, int a2, int a3, int a4, int a5)
int  CSchedule::CalcDistance(int,int,int,int) {
  
  int v8; // [esp+10h] [ebp-8h]
  int Number; // [esp+14h] [ebp-4h]

  Number = j__abs(a4 - a2);
  v8 = j__abs(a5 - a3);
  if ( ((a5 - a3) ^ (a4 - a2)) < 0 )
    return v8 + Number;
  if ( Number >= v8 )
    return Number;
  else
    return v8;
}


// address=[0x2f4c8f0]
// Decompiled from int __thiscall CSchedule::GetEcoSector(CSchedule *this)
class IAIEcoManager *  CSchedule::GetEcoSector(void) {
  
  return *(_DWORD *)(*((_DWORD *)this + 9) + 24);
}


