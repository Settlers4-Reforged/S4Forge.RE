#include "CExpandationManagerTask.h"

// Definitions for class CExpandationManagerTask

// address=[0x2f51910]
// Decompiled from CExpandationManagerTask *__thiscall CExpandationManagerTask::CExpandationManagerTask(CExpandationManagerTask *this)
 CExpandationManagerTask::CExpandationManagerTask(void) {
  
  IScheduleEntry::IScheduleEntry(this);
  *(_DWORD *)this = &CExpandationManagerTask::_vftable_;
  std::vector<int>::vector<int>((char *)this + 52);
  *((_DWORD *)this + 4) = 6;
  *((_DWORD *)this + 5) = 2;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 17) = 2;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 16;
  *((_DWORD *)this + 22) = 96;
  *((_DWORD *)this + 23) = 32;
  *((_DWORD *)this + 24) = 48;
  *((_DWORD *)this + 25) = 112;
  *((_DWORD *)this + 26) = -3;
  *((_DWORD *)this + 27) = -4;
  *((_BYTE *)this + 76) = 1;
  return this;
}


// address=[0x2f51a10]
// Decompiled from void __thiscall CExpandationManagerTask::~CExpandationManagerTask(CExpandationManagerTask *this)
 CExpandationManagerTask::~CExpandationManagerTask(void) {
  
  *(_DWORD *)this = &CExpandationManagerTask::_vftable_;
  std::vector<int>::clear();
  std::vector<int>::~vector<int>();
  IScheduleEntry::~IScheduleEntry(this);
}


// address=[0x2f51a50]
// Decompiled from char __thiscall CExpandationManagerTask::GetExpandationPermission(  CExpandationManagerTask *this,  struct CExpandationEvent *a2)
bool  CExpandationManagerTask::GetExpandationPermission(class CExpandationEvent *) {
  
  struct CDynListEntry *i; // [esp+8h] [ebp-8h]

  *((_DWORD *)this + 11) = 0;
  for ( i = CDynList::FirstEntry(*(CDynList **)(*((_DWORD *)this + 10) + 4));
        i;
        i = (struct CDynListEntry *)CDynListEntry::Next(i) )
  {
    if ( *((_DWORD *)i + 4) == 7 && *((_DWORD *)i + 3) != *((_DWORD *)a2 + 3) )
      return 0;
    if ( *((_DWORD *)i + 4) == 9 && (*((_DWORD *)i + 11) == 46 || *((_DWORD *)i + 11) == 47) )
      return 0;
  }
  return 1;
}


// address=[0x2f51af0]
// Decompiled from char __thiscall CExpandationManagerTask::IsBorderElement(CReserveDatabase ***this, int a2, int a3)
bool  CExpandationManagerTask::IsBorderElement(int,int) {
  
  int v4; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-4h]

  v4 = CReserveDatabase::PackPosition(*this[10], a2, a3);
  for ( i = 0; i < std::vector<int>::size(this + 13); ++i )
  {
    if ( v4 == *(_DWORD *)std::vector<int>::operator[](i) )
      return 1;
  }
  return 0;
}


// address=[0x2f51b60]
// Decompiled from char __thiscall CExpandationManagerTask::IsShooting(CSchedule **this)
bool  CExpandationManagerTask::IsShooting(void) {
  
  struct IAIEcoManager *EcoSector; // eax
  struct IScheduleEntry *v3; // [esp+8h] [ebp-1Ch]
  CExpandationEvent *C; // [esp+Ch] [ebp-18h]

  std::vector<int>::clear();
  EcoSector = CSchedule::GetEcoSector(this[10]);
  (*(void (__thiscall **)(struct IAIEcoManager *, char *))(*(_DWORD *)EcoSector + 256))(EcoSector, (char *)this + 52);
  if ( this[17] )
  {
    if ( this[17] == (CSchedule *)1 )
    {
      *((_BYTE *)this + 76) = 1;
      this[20] = (CSchedule *)((char *)this[20] + 1);
      if ( (int)this[20] > 4 )
        this[20] = 0;
    }
    if ( *((_BYTE *)this + 76) && (int)this[18] < 490 && !CSchedule::IsAnyExpandation((CDynList **)this[10]) )
    {
      C = (CExpandationEvent *)operator new(0x74u);
      if ( C )
        v3 = CExpandationEvent::CExpandationEvent(C, this[3], 0, this[(_DWORD)this[20] + 21]);
      else
        v3 = 0;
      this[8] = (CSchedule *)CSchedule::NewSchedEntry(this[10], v3);
      this[17] = 0;
      this[18] = (CSchedule *)500;
      *((_BYTE *)this + 76) = 0;
    }
  }
  else if ( (int)this[18] < 10 )
  {
    this[17] = (CSchedule *)1;
    *((_BYTE *)this + 76) = 1;
    this[18] = (CSchedule *)500;
    this[20] = (CSchedule *)((char *)this[20] + 1);
  }
  this[18] = (CSchedule *)((char *)this[18] - 1);
  return 0;
}


// address=[0x2f51d10]
// Decompiled from char __thiscall CExpandationManagerTask::action(CExpandationManagerTask *this)
bool  CExpandationManagerTask::action(void) {
  
  return 0;
}


// address=[0x2f51d20]
// Decompiled from char __thiscall CExpandationManagerTask::IsAlive(CExpandationManagerTask *this)
bool  CExpandationManagerTask::IsAlive(void) {
  
  return 1;
}


// address=[0x2f51d30]
// Decompiled from char __thiscall CExpandationManagerTask::WaitFor(CExpandationManagerTask *this)
bool  CExpandationManagerTask::WaitFor(void) {
  
  return 1;
}


