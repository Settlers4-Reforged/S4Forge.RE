#include "all_headers.h"

// Definitions for class CInvokeEvent

// address=[0x2f4e930]
// Decompiled from int __thiscall CInvokeEvent::CInvokeEvent(int this)
 CInvokeEvent::CInvokeEvent(void) {
  
  IScheduleEntry::IScheduleEntry((IScheduleEntry *)this);
  *(_DWORD *)this = &CInvokeEvent::_vftable_;
  std::vector<int>::vector<int>((void *)(this + 60));
  return this;
}


// address=[0x2f4e960]
// Decompiled from int __thiscall CInvokeEvent::CInvokeEvent(int this, int a2)
 CInvokeEvent::CInvokeEvent(enum BUILDING_TYPES) {
  
  IScheduleEntry::IScheduleEntry((IScheduleEntry *)this);
  *(_DWORD *)this = &CInvokeEvent::_vftable_;
  std::vector<int>::vector<int>((void *)(this + 60));
  *(_DWORD *)(this + 16) = 12;
  *(_DWORD *)(this + 20) = 2;
  *(_DWORD *)(this + 44) = a2;
  *(_DWORD *)(this + 48) = 2;
  *(_DWORD *)(this + 52) = 0;
  std::vector<int>::clear();
  *(_BYTE *)(this + 56) = 1;
  *(_BYTE *)(this + 76) = 0;
  return this;
}


// address=[0x2f4e9e0]
// Decompiled from char __thiscall CInvokeEvent::AddInvokePosition(CReserveDatabase ***this, int a2, int a3)
bool  CInvokeEvent::AddInvokePosition(int,int) {
  
  int v4; // [esp+0h] [ebp-8h] BYREF
  CReserveDatabase ***v5; // [esp+4h] [ebp-4h]

  v5 = this;
  *((_BYTE *)this + 56) = 0;
  v4 = CReserveDatabase::PackPosition(*v5[10], a2, a3);
  std::vector<int>::push_back(&v4);
  return 1;
}


// address=[0x2f4ea20]
// Decompiled from char __thiscall CInvokeEvent::AddInvokePosition(CInvokeEvent *this, int a2)
bool  CInvokeEvent::AddInvokePosition(int) {
  
  *((_BYTE *)this + 56) = 0;
  std::vector<int>::push_back(&a2);
  return 1;
}


// address=[0x2f4ea50]
// Decompiled from int __thiscall CInvokeEvent::AddInvokePositionAroundResource(CInvokeEvent *this, int a2, int a3)
int  CInvokeEvent::AddInvokePositionAroundResource(enum BUILDING_TYPES,int) {
  
  int ResourceForBuilding; // [esp+0h] [ebp-38h]
  int v5; // [esp+4h] [ebp-34h]
  int v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+8h] [ebp-30h]
  struct CDynListEntry *ResourceManager; // [esp+Ch] [ebp-2Ch]
  int i; // [esp+10h] [ebp-28h]
  int v10; // [esp+18h] [ebp-20h]
  struct IFilterEntry *FilterEntry; // [esp+1Ch] [ebp-1Ch]
  int v12; // [esp+24h] [ebp-14h] BYREF
  int v13; // [esp+28h] [ebp-10h] BYREF
  int j; // [esp+2Ch] [ebp-Ch]
  int k; // [esp+30h] [ebp-8h]
  CInvokeEvent *v16; // [esp+34h] [ebp-4h]

  v16 = this;
  v10 = 0;
  *((_BYTE *)this + 76) = 1;
  switch ( a2 )
  {
    case 1:
    case 4:
    case 6:
    case 14:
    case 16:
    case 17:
    case 18:
      ResourceForBuilding = CProductionDataTab::GetResourceForBuilding(
                              *(void **)(*((_DWORD *)v16 + 10) + 40),
                              a2,
                              *(_DWORD *)(*((_DWORD *)v16 + 10) + 24));
      ResourceManager = CSchedule::GetResourceManager(*((CDynList ***)v16 + 10), ResourceForBuilding);
      if ( ResourceManager )
      {
        for ( i = 0; i < *(_DWORD *)(*((_DWORD *)ResourceManager + 21) + 8); ++i )
        {
          FilterEntry = CFilter::GetFilterEntry(*((CFilter **)ResourceManager + 21), i);
          if ( FilterEntry )
          {
            CReserveDatabase::PackPosition(
              **((CReserveDatabase ***)v16 + 10),
              *((_DWORD *)FilterEntry + 3),
              *((_DWORD *)FilterEntry + 4));
            v5 = CReserveDatabase::PackPosition(
                   **((CReserveDatabase ***)v16 + 10),
                   16 * *((_DWORD *)FilterEntry + 3) + 8,
                   16 * *((_DWORD *)FilterEntry + 4) + 8);
            if ( a3 <= 0 || (int)CSchedule::CalcDistance(*((CSchedule **)v16 + 10), v5, a3) <= 80 )
            {
              ++v10;
              CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v16 + 10), v5, &v13, &v12);
              v13 /= 16;
              v12 /= 16;
              for ( j = v13 - 6; j < v13 + 6; ++j )
              {
                for ( k = v12 - 6; k < v12 + 6; ++k )
                {
                  if ( j >= 0 && k >= 0 )
                  {
                    v6 = CReserveDatabase::PackPosition(**((CReserveDatabase ***)v16 + 10), j, k);
                    CInvokeEvent::AddInvokePosition(v16, v6);
                  }
                }
              }
            }
          }
        }
      }
      break;
    case 5:
    case 15:
    case 43:
    case 44:
      return v10;
    default:
      if ( a3 )
      {
        CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v16 + 10), a3, &v13, &v12);
        v13 /= 16;
        v12 /= 16;
        for ( j = v13 - 6; j < v13 + 6; ++j )
        {
          for ( k = v12 - 6; k < v12 + 6; ++k )
          {
            v7 = CReserveDatabase::PackPosition(**((CReserveDatabase ***)v16 + 10), j, k);
            CInvokeEvent::AddInvokePosition(v16, v7);
          }
        }
        v10 = 1;
      }
      break;
  }
  return v10;
}


// address=[0x2f4ed40]
// Decompiled from void __thiscall CInvokeEvent::~CInvokeEvent(CSchedule **this)
 CInvokeEvent::~CInvokeEvent(void) {
  
  struct IAIEcoManager *EcoSector; // [esp+4h] [ebp-14h]

  *this = (CSchedule *)&CInvokeEvent::_vftable_;
  EcoSector = CSchedule::GetEcoSector(this[10]);
  (*(void (__thiscall **)(struct IAIEcoManager *, CSchedule *))(*(_DWORD *)EcoSector + 16))(EcoSector, this[11]);
  std::vector<int>::clear();
  std::vector<int>::~vector<int>();
  IScheduleEntry::~IScheduleEntry((IScheduleEntry *)this);
}


// address=[0x2f4edc0]
// Decompiled from char __thiscall CInvokeEvent::IsShooting(CInvokeEvent *this)
bool  CInvokeEvent::IsShooting(void) {
  
  if ( !*((_BYTE *)this + 76) )
    return 0;
  if ( *((_DWORD *)this + 12) == 1 )
  {
    *((_DWORD *)this + 5) = 3;
    return 0;
  }
  else if ( *((_DWORD *)this + 12) == 2 )
  {
    return 1;
  }
  else
  {
    *((_DWORD *)this + 5) = 1;
    return 0;
  }
}


// address=[0x2f4ee10]
// Decompiled from char __thiscall CInvokeEvent::action(CInvokeEvent *this)
bool  CInvokeEvent::action(void) {
  
  unsigned int v1; // eax
  _DWORD *v2; // eax
  int v3; // eax
  struct IAIEcoManager *v5; // [esp+0h] [ebp-18h]
  struct IAIEcoManager *EcoSector; // [esp+4h] [ebp-14h]
  int v7; // [esp+8h] [ebp-10h] BYREF
  int v8; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int i; // [esp+10h] [ebp-8h]
  CInvokeEvent *v10; // [esp+14h] [ebp-4h]

  v10 = this;
  v7 = 0;
  v8 = 0;
  if ( !*(_DWORD *)(*((_DWORD *)this + 10) + 32) )
    *(_DWORD *)(*((_DWORD *)v10 + 10) + 32) = *((_DWORD *)v10 + 3);
  if ( *((_DWORD *)v10 + 12) == 2 )
  {
    if ( !*((_DWORD *)v10 + 13) && !*((_BYTE *)v10 + 56) )
    {
      for ( i = 0; ; ++i )
      {
        v1 = std::vector<int>::size((char *)v10 + 60);
        if ( i >= v1 )
          break;
        v2 = (_DWORD *)std::vector<int>::operator[](i);
        CReserveDatabase::UnpackPosition(**((CReserveDatabase ***)v10 + 10), *v2, &v7, &v8);
        EcoSector = CSchedule::GetEcoSector(*((CSchedule **)v10 + 10));
        (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int, int))(*(_DWORD *)EcoSector + 8))(
          EcoSector,
          *((_DWORD *)v10 + 11),
          v7,
          v8);
      }
    }
    if ( !*((_DWORD *)v10 + 12)
      && BBSupportDbgReport(2, "Source\\EcoAI_ProblemSolve.cpp", 679, "m_iInvokeError != AI_EME_OK") == 1 )
    {
      __debugbreak();
    }
    v5 = CSchedule::GetEcoSector(*((CSchedule **)v10 + 10));
    v3 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v5 + 12))(v5, *((_DWORD *)v10 + 11));
    *((_DWORD *)v10 + 12) = v3;
    ++*((_DWORD *)v10 + 13);
  }
  if ( *((_DWORD *)v10 + 12) == 2 )
    return 1;
  if ( *(_DWORD *)(*((_DWORD *)v10 + 10) + 32) == *((_DWORD *)v10 + 3) )
    *(_DWORD *)(*((_DWORD *)v10 + 10) + 32) = 0;
  *((_DWORD *)v10 + 5) = 1;
  return 1;
}


// address=[0x2f4ef80]
// Decompiled from char __thiscall CInvokeEvent::IsAlive(CInvokeEvent *this)
bool  CInvokeEvent::IsAlive(void) {
  
  struct IAIEcoManager *EcoSector; // [esp+0h] [ebp-8h]

  if ( *((_DWORD *)this + 12) != 1 )
    return 1;
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 16))(
    EcoSector,
    *((_DWORD *)this + 11));
  *((_DWORD *)this + 5) = 3;
  return 0;
}


// address=[0x2f4efd0]
// Decompiled from char __thiscall CInvokeEvent::WaitFor(CInvokeEvent *this)
bool  CInvokeEvent::WaitFor(void) {
  
  struct IAIEcoManager *EcoSector; // [esp+0h] [ebp-8h]

  if ( CSchedule::InvokeNeeded(*((CDynList ***)this + 10), *((_DWORD *)this + 11)) )
    return 0;
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 16))(
    EcoSector,
    *((_DWORD *)this + 11));
  *((_DWORD *)this + 5) = 3;
  return 0;
}


