#include "CExpandationEvent.h"

// Definitions for class CExpandationEvent

// address=[0x2f51d40]
// Decompiled from CExpandationEvent *__thiscall CExpandationEvent::CExpandationEvent(CExpandationEvent *this, int a2, int a3, int a4)
 CExpandationEvent::CExpandationEvent(int,int,int) {
  
  CExpandationEvent *v6; // [esp+0h] [ebp-4h]

  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CExpandationEvent::_vftable_;
  std::vector<SRESOURCECONCENTRATIONDATA>::vector<SRESOURCECONCENTRATIONDATA>(this);
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::vector<SUNDERGROUNDCONCENTRATIONDATA>();
  *((_DWORD *)v6 + 8) = a2;
  *((_DWORD *)v6 + 20) = a3;
  *((_DWORD *)v6 + 22) = a4;
  *((_DWORD *)v6 + 11) = 0;
  *((_DWORD *)v6 + 26) = 0;
  *((_DWORD *)v6 + 4) = 7;
  *((_DWORD *)v6 + 27) = 0;
  *((_DWORD *)v6 + 5) = 2;
  *((_DWORD *)v6 + 23) = 0;
  *((_DWORD *)v6 + 24) = 0;
  return v6;
}


// address=[0x2f51de0]
// Decompiled from CExpandationEvent *__thiscall CExpandationEvent::CExpandationEvent(CExpandationEvent *this, int a2, CDynList **a3)
 CExpandationEvent::CExpandationEvent(int,class CSchedule *) {
  
  int v4; // [esp+0h] [ebp-50h]
  struct IFilterEntry *v5; // [esp+14h] [ebp-3Ch]
  CFilterResourceLandscape *v6; // [esp+18h] [ebp-38h]
  CFilter *v7; // [esp+20h] [ebp-30h]
  CFilter *C; // [esp+24h] [ebp-2Ch]
  int j; // [esp+2Ch] [ebp-24h]
  struct CDynListEntry *i; // [esp+30h] [ebp-20h]
  float v11; // [esp+34h] [ebp-1Ch]
  struct IFilterEntry *FilterEntry; // [esp+3Ch] [ebp-14h]

  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CExpandationEvent::_vftable_;
  std::vector<SRESOURCECONCENTRATIONDATA>::vector<SRESOURCECONCENTRATIONDATA>(v4);
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::vector<SUNDERGROUNDCONCENTRATIONDATA>();
  *((_DWORD *)this + 4) = 7;
  *((_DWORD *)this + 5) = 2;
  *((_DWORD *)this + 22) = a2;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 8) = 0;
  v11 = 0.0;
  *((_DWORD *)this + 27) = 0;
  if ( a2 != -5 )
    return this;
  C = (CFilter *)operator new(0x18u);
  if ( C )
    v7 = CFilter::CFilter(C, 5);
  else
    v7 = 0;
  *((_DWORD *)this + 11) = v7;
  for ( i = CDynList::FirstEntry(a3[1]); i; i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 4) == 5 )
    {
      for ( j = 0; j < *(_DWORD *)(*((_DWORD *)i + 21) + 8); ++j )
      {
        FilterEntry = CFilter::GetFilterEntry(*((CFilter **)i + 21), j);
        if ( *((_DWORD *)FilterEntry + 6) )
        {
          switch ( *((_DWORD *)i + 11) )
          {
            case 0x10:
              v11 = FLOAT_4_0;
              break;
            case 0x20:
              v11 = FLOAT_3_0;
              break;
            case 0x60:
              v11 = FLOAT_2_0;
              break;
            case 0x70:
              v11 = FLOAT_2_0;
              break;
            default:
              break;
          }
          v6 = (CFilterResourceLandscape *)operator new(0x20u);
          if ( v6 )
            v5 = CFilterResourceLandscape::CFilterResourceLandscape(
                   v6,
                   *((_DWORD *)FilterEntry + 3),
                   *((_DWORD *)FilterEntry + 4),
                   (int)(float)((float)*((int *)FilterEntry + 5) * v11),
                   *((_DWORD *)FilterEntry + 6),
                   *((_DWORD *)FilterEntry + 7));
          else
            v5 = 0;
          CFilter::AddFilterEntry(*((CFilter **)this + 11), v5);
          break;
        }
      }
    }
  }
  return this;
}


// address=[0x2f520f0]
// Decompiled from void __thiscall CExpandationEvent::~CExpandationEvent(CExpandationEvent *this)
 CExpandationEvent::~CExpandationEvent(void) {
  
  int v1; // [esp+0h] [ebp-10h]
  int v2; // [esp+4h] [ebp-Ch]

  *(_DWORD *)this = &CExpandationEvent::_vftable_;
  if ( *((_DWORD *)this + 11) )
  {
    v2 = *((_DWORD *)this + 11);
    if ( v2 )
      v1 = (***((int (__thiscall ****)(_DWORD, int))this + 11))(*((_DWORD *)this + 11), 1);
    else
      v1 = 0;
  }
  std::vector<SRESOURCECONCENTRATIONDATA>::clear();
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::clear();
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::~vector<SUNDERGROUNDCONCENTRATIONDATA>();
  std::vector<SRESOURCECONCENTRATIONDATA>::~vector<SRESOURCECONCENTRATIONDATA>(v1, v2);
  IScheduleEntry::~IScheduleEntry(this);
}


// address=[0x2f52180]
// Decompiled from bool __thiscall CExpandationEvent::IsShooting(CSchedule **this)
bool  CExpandationEvent::IsShooting(void) {
  
  struct IAIEcoManager *v1; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // [esp-10h] [ebp-78h]
  int v12; // [esp-10h] [ebp-78h]
  int v13; // [esp-Ch] [ebp-74h]
  int v14; // [esp-Ch] [ebp-74h]
  int v15; // [esp-4h] [ebp-6Ch]
  int v16; // [esp-4h] [ebp-6Ch]
  int v17; // [esp-4h] [ebp-6Ch]
  int v18; // [esp-4h] [ebp-6Ch]
  CExpandationManagerTask *SpecialTask; // [esp+4h] [ebp-64h]
  struct IFilterEntry *v20; // [esp+14h] [ebp-54h]
  CFilterResourceLandscape *v21; // [esp+18h] [ebp-50h]
  struct IFilterEntry *v22; // [esp+1Ch] [ebp-4Ch]
  CFilterResourceLandscape *v23; // [esp+20h] [ebp-48h]
  CFilter *v24; // [esp+24h] [ebp-44h]
  CFilter *C; // [esp+28h] [ebp-40h]
  struct IAIEcoManager *v26; // [esp+2Ch] [ebp-3Ch]
  struct IAIEcoManager *EcoSector; // [esp+30h] [ebp-38h]
  struct IAIEcoManager *v28; // [esp+34h] [ebp-34h]
  struct IAIEcoManager *v29; // [esp+38h] [ebp-30h]
  int v30; // [esp+44h] [ebp-24h]
  int NextPositionInside; // [esp+44h] [ebp-24h]
  int v32; // [esp+48h] [ebp-20h]
  int v33; // [esp+48h] [ebp-20h]
  unsigned int i; // [esp+50h] [ebp-18h]
  unsigned int j; // [esp+54h] [ebp-14h]

  SpecialTask = CSchedule::GetSpecialTask(this[10], 6);
  if ( std::vector<SUNDERGROUNDCONCENTRATIONDATA>::size(this + 16)
    || std::vector<SRESOURCECONCENTRATIONDATA>::size(this + 12) )
  {
    if ( !this[11] )
    {
      C = (CFilter *)operator new(0x18u);
      if ( C )
        v24 = CFilter::CFilter(C, 5);
      else
        v24 = 0;
      this[11] = v24;
      if ( *((_BYTE *)this + 112) )
      {
        for ( i = 0; i < std::vector<SUNDERGROUNDCONCENTRATIONDATA>::size(this + 16); ++i )
        {
          v17 = *(__int16 *)(std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i) + 8);
          v7 = std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i);
          NextPositionInside = CSchedule::GetNextPositionInside(this[10], *(__int16 *)(v7 + 6), v17);
          v18 = *(__int16 *)(std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i) + 8);
          v8 = std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i);
          v9 = CReserveDatabase::PackPosition(*(CReserveDatabase **)this[10], *(__int16 *)(v8 + 6), v18);
          v33 = CSchedule::CalcDistance(this[10], NextPositionInside, v9);
          if ( v33 <= (int)this[26] + 40 )
          {
            v21 = (CFilterResourceLandscape *)operator new(0x20u);
            if ( v21 )
            {
              v14 = *(__int16 *)(std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i) + 4);
              v12 = *(__int16 *)(std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i) + 8);
              v10 = std::vector<SUNDERGROUNDCONCENTRATIONDATA>::operator[](i);
              v20 = CFilterResourceLandscape::CFilterResourceLandscape(
                      v21,
                      *(__int16 *)(v10 + 6),
                      v12,
                      v14,
                      NextPositionInside,
                      v33);
            }
            else
            {
              v20 = 0;
            }
            CFilter::AddFilterEntry(this[11], v20);
          }
        }
      }
      else
      {
        for ( j = 0; j < std::vector<SRESOURCECONCENTRATIONDATA>::size(this + 12); ++j )
        {
          v15 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](j) + 8);
          v3 = std::vector<SRESOURCECONCENTRATIONDATA>::operator[](j);
          v30 = CSchedule::GetNextPositionInside(this[10], *(__int16 *)(v3 + 6), v15);
          v16 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](j) + 8);
          v4 = std::vector<SRESOURCECONCENTRATIONDATA>::operator[](j);
          v5 = CReserveDatabase::PackPosition(*(CReserveDatabase **)this[10], *(__int16 *)(v4 + 6), v16);
          v32 = CSchedule::CalcDistance(this[10], v30, v5);
          if ( v32 <= (int)this[26] + 40 )
          {
            v23 = (CFilterResourceLandscape *)operator new(0x20u);
            if ( v23 )
            {
              v13 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](j) + 4);
              v11 = *(__int16 *)(std::vector<SRESOURCECONCENTRATIONDATA>::operator[](j) + 8);
              v6 = std::vector<SRESOURCECONCENTRATIONDATA>::operator[](j);
              v22 = CFilterResourceLandscape::CFilterResourceLandscape(v23, *(__int16 *)(v6 + 6), v11, v13, v30, v32);
            }
            else
            {
              v22 = 0;
            }
            CFilter::AddFilterEntry(this[11], v22);
          }
        }
      }
    }
    if ( *((_DWORD *)this[11] + 2) )
    {
      return CExpandationManagerTask::GetExpandationPermission(SpecialTask, (struct CExpandationEvent *)this);
    }
    else
    {
      this[26] = (CSchedule *)((char *)this[26] + 50);
      return 0;
    }
  }
  else
  {
    switch ( (unsigned int)this[22] )
    {
      case 0xFFFFFFFA:
        *((_BYTE *)this + 112) = 1;
        EcoSector = CSchedule::GetEcoSector(this[10]);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, char *))(*(_DWORD *)EcoSector + 252))(
          EcoSector,
          2,
          (char *)this + 64);
        break;
      case 0xFFFFFFFC:
        *((_BYTE *)this + 112) = 1;
        v28 = CSchedule::GetEcoSector(this[10]);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, char *))(*(_DWORD *)v28 + 252))(v28, 1, (char *)this + 64);
        break;
      case 0xFFFFFFFD:
        *((_BYTE *)this + 112) = 1;
        v1 = CSchedule::GetEcoSector(this[10]);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, char *))(*(_DWORD *)v1 + 252))(v1, 5, (char *)this + 64);
        break;
      case 0xFFFFFFFE:
        *((_BYTE *)this + 112) = 1;
        v29 = CSchedule::GetEcoSector(this[10]);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, char *))(*(_DWORD *)v29 + 252))(v29, 6, (char *)this + 64);
        break;
      default:
        *((_BYTE *)this + 112) = 0;
        v26 = CSchedule::GetEcoSector(this[10]);
        if ( !(*(int (__thiscall **)(struct IAIEcoManager *, CSchedule *, char *))(*(_DWORD *)v26 + 188))(
                v26,
                this[22],
                (char *)this + 48) )
          this[5] = (CSchedule *)3;
        break;
    }
    return 0;
  }
}


// address=[0x2f52680]
// Decompiled from char __thiscall CExpandationEvent::action(CExpandationEvent *this)
bool  CExpandationEvent::action(void) {
  
  struct IScheduleEntry *v2; // [esp+8h] [ebp-18h]
  CMainProblemSolveEvent *C; // [esp+Ch] [ebp-14h]

  C = (CMainProblemSolveEvent *)operator new(0x70u);
  if ( C )
    v2 = CMainProblemSolveEvent::CMainProblemSolveEvent(C, *((_DWORD *)this + 3), 11, *((_DWORD *)this + 22), 0, 0, 0);
  else
    v2 = 0;
  *((_DWORD *)this + 21) = CSchedule::NewSchedEntry(*((CSchedule **)this + 10), v2, *((_DWORD *)this + 3));
  *((_DWORD *)this + 5) = 1;
  return 1;
}


// address=[0x2f52730]
// Decompiled from char __thiscall CExpandationEvent::IsAlive(CExpandationEvent *this)
bool  CExpandationEvent::IsAlive(void) {
  
  return 1;
}


// address=[0x2f52740]
// Decompiled from char __thiscall CExpandationEvent::WaitFor(CExpandationEvent *this)
bool  CExpandationEvent::WaitFor(void) {
  
  int v2; // [esp+4h] [ebp-8h]

  v2 = *((_DWORD *)this + 27);
  if ( v2 == 1 )
  {
    if ( !*((_DWORD *)this + 8) )
      return 0;
    CSchedule::MarkSolvedProblem(*((CSchedule **)this + 10), *((_DWORD *)this + 8), 0);
    *((_DWORD *)this + 8) = 0;
    *((_DWORD *)this + 5) = 3;
    return 0;
  }
  else
  {
    if ( v2 != 2 )
      return 0;
    if ( *((_DWORD *)this + 8) )
      CSchedule::MarkSolvedProblem(*((CSchedule **)this + 10), *((_DWORD *)this + 8), 1);
    *((_DWORD *)this + 5) = 3;
    return 0;
  }
}


