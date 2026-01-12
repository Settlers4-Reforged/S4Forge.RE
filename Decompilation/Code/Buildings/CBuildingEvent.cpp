#include "CBuildingEvent.h"

// Definitions for class CBuildingEvent

// address=[0x2f51210]
// Decompiled from int __thiscall CBuildingEvent::CBuildingEvent(int this, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
 CBuildingEvent::CBuildingEvent(enum BUILDING_TYPES,int,int,int,int,int,enum T_BUILD_LEVEL) {
  
  IScheduleEntry::IScheduleEntry((IScheduleEntry *)this);
  *(_DWORD *)this = &CBuildingEvent::_vftable_;
  *(_DWORD *)(this + 16) = 9;
  *(_DWORD *)(this + 20) = 2;
  *(_DWORD *)(this + 44) = a2;
  *(_DWORD *)(this + 60) = a4;
  *(_DWORD *)(this + 64) = a5;
  *(_DWORD *)(this + 68) = a6;
  *(_DWORD *)(this + 72) = a3;
  *(_DWORD *)(this + 56) = 4;
  if ( a7 )
    *(_BYTE *)(this + 84) = 1;
  else
    *(_BYTE *)(this + 84) = 0;
  *(_DWORD *)(this + 48) = a7;
  *(_DWORD *)(this + 52) = a8;
  *(_BYTE *)(this + 85) = 0;
  *(_DWORD *)(this + 80) = 0;
  return this;
}


// address=[0x2f512c0]
// Decompiled from void __thiscall CBuildingEvent::~CBuildingEvent(CBuildingEvent *this)
 CBuildingEvent::~CBuildingEvent(void) {
  
  *(_DWORD *)this = &CBuildingEvent::_vftable_;
  IScheduleEntry::~IScheduleEntry(this);
}


// address=[0x2f512e0]
// Decompiled from char __thiscall CBuildingEvent::IsShooting(CSchedule **this)
bool  CBuildingEvent::IsShooting(void) {
  
  char result; // al
  struct IAIEcoManager *v2; // [esp+8h] [ebp-38h]
  struct IScheduleEntry *v3; // [esp+Ch] [ebp-34h]
  void *C; // [esp+10h] [ebp-30h]
  struct IAIEcoManager *v5; // [esp+14h] [ebp-2Ch]
  struct IAIEcoManager *EcoSector; // [esp+18h] [ebp-28h]
  int v7; // [esp+1Ch] [ebp-24h] BYREF
  int v8; // [esp+20h] [ebp-20h] BYREF
  int v9; // [esp+24h] [ebp-1Ch]
  CSchedule **SpecialTask; // [esp+28h] [ebp-18h]
  struct CDynListEntry *ProductivityControll; // [esp+2Ch] [ebp-14h]
  CSchedule **v12; // [esp+30h] [ebp-10h]
  int v13; // [esp+3Ch] [ebp-4h]

  v12 = this;
  SpecialTask = (CSchedule **)CSchedule::GetSpecialTask(this[10], 3);
  ProductivityControll = 0;
  if ( v12[13] != (CSchedule *)1 )
  {
    EcoSector = CSchedule::GetEcoSector(v12[10]);
    if ( !(*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, CSchedule *))(*(_DWORD *)EcoSector + 304))(
            EcoSector,
            v12[12]) )
    {
      v12[5] = (CSchedule *)3;
      return 0;
    }
    if ( v12[14] == (CSchedule *)5 || v12[14] == (CSchedule *)4 )
    {
      v5 = CSchedule::GetEcoSector(v12[10]);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, CSchedule *))(*(_DWORD *)v5 + 80))(v5, v12[12]) )
        v12[14] = (CSchedule *)4;
      else
        v12[14] = (CSchedule *)5;
    }
  }
  if ( !*((_BYTE *)v12 + 84) )
  {
    v12[12] = v12[3];
    v12[13] = (CSchedule *)1;
    v12[14] = (CSchedule *)1;
    if ( CProductionDataTab::BuildingMustBeControl(*((void **)v12[10] + 10), (int)v12[11], *((_DWORD *)v12[10] + 6)) )
    {
      C = operator new(0x70u);
      v13 = 0;
      if ( C )
        v3 = (struct IScheduleEntry *)CProductivityControll::CProductivityControll(C, v12[12], 1, v12[11], v12[17], 0);
      else
        v3 = 0;
      v13 = -1;
      CSchedule::NewSchedEntry(v12[10], v3);
    }
    *((_BYTE *)v12 + 84) = 1;
  }
  v9 = (int)v12[14] - 1;
  switch ( v9 )
  {
    case 0:
      CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v12[10], v12[17], &v7, &v8);
      CBuildingManagerTask::RemoveBuildingAtPlanning(SpecialTask, v12[11]);
      v2 = CSchedule::GetEcoSector(v12[10]);
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, CSchedule *, int, int))(*(_DWORD *)v2 + 36))(
             v2,
             v12[11],
             v7,
             v8) )
      {
        v12[20] = (CSchedule *)10;
        if ( !CBuildingManagerTask::GetBuildingPermission(SpecialTask, (struct CBuildingEvent *)v12) )
          goto CBuildingEvent__IsShooting___def_3351498;
        result = 1;
      }
      else
      {
        v12[5] = (CSchedule *)3;
        BBSupportTracePrintF(
          3,
          "AI BuildingEvent::PlayerNr %i can`t build a %s on position %i,%i",
          *((_DWORD *)v12[10] + 5),
          (&off_3ABF5D4)[2 * (_DWORD)v12[11]],
          v7,
          v8);
        CBuildingManagerTask::SetRejectedBuilding(SpecialTask, (int)v12[11]);
        ProductivityControll = CSchedule::GetProductivityControll((CDynList **)v12[10], (int)v12[12], (int)v12[13]);
        if ( ProductivityControll )
          *((_DWORD *)ProductivityControll + 5) = 3;
        result = 0;
      }
      break;
    case 1:
      CReserveDatabase::UnpackPosition(*(CReserveDatabase **)v12[10], v12[17], &v7, &v8);
      v12[20] = (CSchedule *)((char *)v12[20] - 1);
      if ( v12[20] )
        goto CBuildingEvent__IsShooting___def_3351498;
      v12[5] = (CSchedule *)3;
      BBSupportTracePrintF(
        3,
        "AI BuildingEvent::PlayerNr %i can`t build a %s on position %i,%i",
        *((_DWORD *)v12[10] + 5),
        (&off_3ABF5D4)[2 * (_DWORD)v12[11]],
        v7,
        v8);
      CBuildingManagerTask::SetRejectedBuilding(SpecialTask, (int)v12[11]);
      ProductivityControll = CSchedule::GetProductivityControll((CDynList **)v12[10], (int)v12[12], (int)v12[13]);
      if ( ProductivityControll )
        *((_DWORD *)ProductivityControll + 5) = 3;
      result = 0;
      break;
    case 2:
      result = 1;
      break;
    case 3:
      if ( CBuildingManagerTask::GetBuildingPermission(SpecialTask, (struct CBuildingEvent *)v12) )
        goto CBuildingEvent__IsShooting___def_3351498;
      result = 1;
      break;
    case 4:
      if ( !CBuildingManagerTask::GetBuildingPermission(SpecialTask, (struct CBuildingEvent *)v12) )
        goto CBuildingEvent__IsShooting___def_3351498;
      result = 1;
      break;
    case 5:
      result = 1;
      break;
    case 6:
      result = 1;
      break;
    default:
CBuildingEvent__IsShooting___def_3351498:
      result = 0;
      break;
  }
  return result;
}


// address=[0x2f516c0]
// Decompiled from char __thiscall CBuildingEvent::action(CBuildingEvent *this)
bool  CBuildingEvent::action(void) {
  
  int v1; // ecx
  struct IAIEcoManager *v2; // eax
  struct IAIEcoManager *v4; // [esp+Ch] [ebp-18h]
  int v5; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+14h] [ebp-10h] BYREF
  struct IAIEcoManager *EcoSector; // [esp+18h] [ebp-Ch]
  int v8; // [esp+1Ch] [ebp-8h]
  CBuildingEvent *v9; // [esp+20h] [ebp-4h]

  v9 = this;
  v1 = *((_DWORD *)this + 14);
  v8 = v1 - 1;
  switch ( v1 )
  {
    case 1:
      CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v9 + 10), *((_DWORD *)v9 + 17), &v5, &v6);
      EcoSector = CSchedule::GetEcoSector(*((CSchedule **)v9 + 10));
      (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int, int))(*(_DWORD *)EcoSector + 100))(
        EcoSector,
        *((_DWORD *)v9 + 11),
        v5,
        v6);
      *((_DWORD *)v9 + 14) = 2;
      BBSupportTracePrintF(
        3,
        "AI_BuildingEvent::PlayerNr %i construct %s on position, %i, %i",
        *(_DWORD *)(*((_DWORD *)v9 + 10) + 20),
        (&off_3ABF5D4)[2 * *((_DWORD *)v9 + 11)],
        v5,
        v6);
      break;
    case 3:
      CSchedule::ChangeBuildingLevel(*((_DWORD *)v9 + 10), *((_DWORD *)v9 + 12), 0, 2);
      *((_DWORD *)v9 + 14) = 4;
      break;
    case 4:
      v4 = CSchedule::GetEcoSector(*((CSchedule **)v9 + 10));
      (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v4 + 276))(v4, *((_DWORD *)v9 + 12));
      *((_DWORD *)v9 + 14) = 5;
      break;
    case 5:
      v2 = CSchedule::GetEcoSector(*((CSchedule **)v9 + 10));
      (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v2 + 276))(v2, *((_DWORD *)v9 + 12));
      *((_DWORD *)v9 + 14) = 4;
      break;
    case 6:
      *((_DWORD *)v9 + 14) = 7;
      break;
    case 7:
      *((_DWORD *)v9 + 5) = 3;
      break;
    default:
      return 1;
  }
  return 1;
}


// address=[0x2f51850]
// Decompiled from char __thiscall CBuildingEvent::IsAlive(CBuildingEvent *this)
bool  CBuildingEvent::IsAlive(void) {
  
  struct IAIEcoManager *EcoSector; // [esp+0h] [ebp-8h]

  if ( *((_DWORD *)this + 13) == 1 )
    return 1;
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 304))(
         EcoSector,
         *((_DWORD *)this + 12)) )
  {
    return 1;
  }
  *((_DWORD *)this + 5) = 3;
  return 0;
}


// address=[0x2f518b0]
// Decompiled from bool __thiscall CBuildingEvent::WaitFor(CReserveDatabase ***this)
bool  CBuildingEvent::WaitFor(void) {
  
  int v2; // [esp+0h] [ebp-10h] BYREF
  int v3; // [esp+4h] [ebp-Ch] BYREF
  struct IAIEcoManager *EcoSector; // [esp+8h] [ebp-8h]
  CReserveDatabase ***v5; // [esp+Ch] [ebp-4h]

  v5 = this;
  CReserveDatabase::UnpackPosition(*this[10], this[17], &v2, &v3);
  EcoSector = CSchedule::GetEcoSector((CSchedule *)v5[10]);
  return (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, CReserveDatabase **, int, int))(*(_DWORD *)EcoSector
                                                                                                  + 36))(
           EcoSector,
           v5[11],
           v2,
           v3) != 0;
}


