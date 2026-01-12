#include "CDonkeyRole.h"

// Definitions for class CDonkeyRole

// address=[0x1400540]
// Decompiled from int __cdecl CDonkeyRole::New(int a1)

static class CPersistence * __cdecl CDonkeyRole::New(std::istream &) {
  
  if ( operator new(0x7Cu) )
    return CDonkeyRole::CDonkeyRole(a1);
  else
    return 0;
}


// address=[0x152bdb0]
// Decompiled from // MFC 3.1-14.0 32bit
int __thiscall CDonkeyRole::GetTradingState(_DWORD *this)

enum CDonkeyRole::TIntTraderState  CDonkeyRole::GetTradingState(void) {
  
  return this[29];
}


// address=[0x152be10]
// Decompiled from char __thiscall CDonkeyRole::IsNeutralTrader(CDonkeyRole *this)

bool  CDonkeyRole::IsNeutralTrader(void) {
  
  return *((_BYTE *)this + 104);
}


// address=[0x152be70]
// Decompiled from int __thiscall CDonkeyRole::MemHomePosition(CDonkeyRole *this)

void  CDonkeyRole::MemHomePosition(void) {
  
  unsigned __int8 *SettlerPtr; // eax
  int result; // eax

  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  result = IEntity::PackedXY(SettlerPtr);
  *((_DWORD *)this + 7) = result;
  return result;
}


// address=[0x1569d40]
// Decompiled from int __thiscall CDonkeyRole::InitWalking(CDonkeyRole *this, struct CSettler *a2)

class CWalking *  CDonkeyRole::InitWalking(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1569d80]
// Decompiled from CDonkeyRole *__thiscall CDonkeyRole::LogicUpdateJob(CDonkeyRole *this, struct CSettler *a2)

void  CDonkeyRole::LogicUpdateJob(class CSettler *) {
  
  int v2; // eax
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // eax
  int v5; // eax
  int v6; // eax
  CDonkeyRole *result; // eax
  int v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+4h] [ebp-Ch]

  if ( IEntity::FlagBits(a2, Selected) || IEntity::FlagBits(a2, (EntityFlag)0x400u) )
    (*(void (__thiscall **)(CDonkeyRole *, int))(*(_DWORD *)this + 132))(this, 1);
  switch ( *((_BYTE *)this + 4) )
  {
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      (*(void (__thiscall **)(CDonkeyRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      if ( !IEntity::FlagBits(a2, Registered) && debug && DEBUG_FLAGS[dword_41520AC] )
      {
        v2 = IEntity::ID();
        BBSupportTracePrintF(0, "LogicUpdateJob - Go - not registered donkey %u", v2);
      }
      break;
    case 0x15:
    case 0x16:
      goto LABEL_28;
    case 0x17:
      if ( !*((_WORD *)this + 38)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 364, "m_uDestinationEntityID > 0") == 1 )
      {
        __debugbreak();
      }
      v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 38));
      if ( IEntity::ObjType(v3) != 4 )
      {
        v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 38));
        if ( IEntity::ObjType(v4) != 2
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\DonkeyRole.cpp",
               367,
               "(g_pMapObjectMgr->EntityPtr( m_uDestinationEntityID ))->ObjType() == CATAPULT_OBJ || (g_pMapObjectMgr->En"
               "tityPtr( m_uDestinationEntityID ))->ObjType() == SHIP_OBJ") == 1 )
        {
          __debugbreak();
        }
      }
      v9 = CVehicleMgr::operator[](*((unsigned __int16 *)this + 38));
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v9 + 132))(
        v9,
        *((unsigned __int8 *)this + 72),
        *((_DWORD *)this + 17));
      v5 = IEntity::ID();
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 64))(v9, v5);
      *((_WORD *)this + 38) = 0;
      *((_DWORD *)this + 17) = 0;
      CDonkeyRole::SetFree(this);
      CDonkeyRole::TryToGoHome(this);
      CDonkeyRole::SetJobType(this, 0);
      if ( !IEntity::FlagBits(a2, Registered) && debug && DEBUG_FLAGS[dword_41520AC] )
      {
        v6 = IEntity::ID();
        BBSupportTracePrintF(0, "LogicUpdateJob - LoadGood ready - not registered settler %u", v6);
      }
      break;
    case 0x20:
      v8 = *((unsigned __int8 *)this + 7) / 2;
      *((_BYTE *)this + 6) -= v8;
      if ( *((char *)this + 6) < v8 )
      {
        if ( *((_DWORD *)this + 14) )
        {
          *((_DWORD *)this + 13) = *((_DWORD *)this + 14);
          *((_DWORD *)this + 14) = 0;
        }
LABEL_28:
        (*(void (__thiscall **)(CDonkeyRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      }
      else
      {
        CDonkeyRole::DropGoods(this, a2);
        IAnimatedEntity::RegisterForLogicUpdate(v8 - 1);
      }
      break;
    default:
      CTrace::Print("LogicUpdateJob Donkey - unknown task %u", *((char *)this + 4));
      break;
  }
  if ( *((char *)this + 4) != *((unsigned __int8 *)this + 44)
    && (*((_DWORD *)this + 15) || *((_BYTE *)this + 120))
    && *((_BYTE *)this + 44) == 6 )
  {
    CDonkeyRole::DonkeyArrived(this);
  }
  result = this;
  *((_BYTE *)this + 44) = *((_BYTE *)this + 4);
  return result;
}


// address=[0x156a0d0]
// Decompiled from CDonkeyRole *__fastcall CDonkeyRole::UpdateJob(CDonkeyRole *this, int a2, struct CSettler *a3)

void  CDonkeyRole::UpdateJob(class CSettler *) {
  
  CDonkeyRole *result; // eax
  char v4; // al

  result = this;
  if ( *((_BYTE *)this + 4) != 32 )
    return result;
  v4 = IAnimatedEntity::Frame(a3);
  IAnimatedEntity::SetFrame(*((_WORD *)this + 4) + v4);
  result = (CDonkeyRole *)IAnimatedEntity::Frame(a3);
  if ( (int)result >= *((unsigned __int8 *)this + 7) )
    return (CDonkeyRole *)IAnimatedEntity::SetFrame(0);
  return result;
}


// address=[0x156a130]
// Decompiled from int __stdcall CDonkeyRole::PostLoadInit(CPropertySet *a1)

void  CDonkeyRole::PostLoadInit(class CSettler *) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x156a150]
// Decompiled from void __thiscall CDonkeyRole::InitFlee(CDonkeyRole *this, struct CSettler *a2, int a3)

void  CDonkeyRole::InitFlee(class CSettler *,int) {
  
  ;
}


// address=[0x156a160]
// Decompiled from int __thiscall CDonkeyRole::Decrease(CDonkeyRole *this, int a2)

int  CDonkeyRole::Decrease(int) {
  
  int v2; // eax
  int v3; // eax
  unsigned __int8 *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( !CDonkeyRole::HasLoadedSomething(this) || !*((_DWORD *)this + 12) || *((_BYTE *)this + 4) == 32 )
    return 0;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  v2 = IEntity::Race(SettlerPtr);
  v3 = CEntityToDoListMgr::SettlerJobList(v2, 162);
  (*(void (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)SettlerPtr + 112))(SettlerPtr, v3, 162);
  return 0;
}


// address=[0x156a1e0]
// Decompiled from CDonkeyRole *__thiscall CDonkeyRole::NextStep(CDonkeyRole *this)

void  CDonkeyRole::NextStep(void) {
  
  CDonkeyRole *result; // eax

  result = this;
  if ( !*((_DWORD *)this + 12) )
    return result;
  CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  return (CDonkeyRole *)IAnimatedEntity::RegisterForLogicUpdate(1);
}


// address=[0x156a220]
// Decompiled from int __thiscall CDonkeyRole::GetGoodAmount(CDonkeyRole *this, int a2)

int  CDonkeyRole::GetGoodAmount(int) {
  
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 20) == a2 )
      v3 += *((_DWORD *)this + 3 * i + 21);
  }
  return v3;
}


// address=[0x156a280]
// Decompiled from int __thiscall CDonkeyRole::AddGood(CDonkeyRole *this, int a2, int a3)

int  CDonkeyRole::AddGood(int,int) {
  
  unsigned __int8 *SettlerPtr; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h]
  int i; // [esp+18h] [ebp-4h]
  int j; // [esp+18h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 20) == a2 && *((_DWORD *)this + 3 * i + 21) != 8 )
    {
      if ( 8 - *((_DWORD *)this + 3 * i + 21) >= a3 )
        v6 = a3;
      else
        v6 = 8 - *((_DWORD *)this + 3 * i + 21);
      *((_DWORD *)this + 3 * i + 21) += v6;
      a3 -= v6;
    }
  }
  if ( a3 )
  {
    for ( j = 0; j < 2; ++j )
    {
      if ( !*((_DWORD *)this + 3 * j + 20) && a3 )
      {
        if ( a3 <= 8 )
          v5 = a3;
        else
          v5 = 8;
        *((_DWORD *)this + 3 * j + 21) += v5;
        *((_DWORD *)this + 3 * j + 20) = a2;
        *((_DWORD *)this + 28) += v5;
        a3 -= v5;
      }
    }
  }
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  if ( IEntity::FlagBits(SettlerPtr, Selected) || IEntity::FlagBits(SettlerPtr, (EntityFlag)0x400u) )
    (*(void (__thiscall **)(CDonkeyRole *, int))(*(_DWORD *)this + 132))(this, 1);
  return a3;
}


// address=[0x156a400]
// Decompiled from int __thiscall CDonkeyRole::RemoveGood(CDonkeyRole *this, int a2, int a3)

int  CDonkeyRole::RemoveGood(int,int) {
  
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  if ( a3 < 0 )
    return 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 20) == a2 )
    {
      if ( *((_DWORD *)this + 3 * i + 21) >= a3 )
        v5 = a3;
      else
        v5 = *((_DWORD *)this + 3 * i + 21);
      *((_DWORD *)this + 3 * i + 21) -= v5;
      if ( !*((_DWORD *)this + 3 * i + 21) )
        *((_DWORD *)this + 3 * i + 20) = 0;
      a3 -= v5;
      *((_DWORD *)this + 27) += v5;
    }
  }
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  if ( IEntity::FlagBits(SettlerPtr, Selected) || IEntity::FlagBits(SettlerPtr, (EntityFlag)0x400u) )
    (*(void (__thiscall **)(CDonkeyRole *, int))(*(_DWORD *)this + 132))(this, 1);
  return a3;
}


// address=[0x156a520]
// Decompiled from char __thiscall CDonkeyRole::IsSpaceAvailable(CDonkeyRole *this, int a2)

bool  CDonkeyRole::IsSpaceAvailable(int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( !*((_DWORD *)this + 3 * i + 20) )
      return 1;
    if ( *((_DWORD *)this + 3 * i + 20) == a2 && 8 - *((_DWORD *)this + 3 * i + 21) > 0 )
      return 1;
  }
  return 0;
}


// address=[0x156a590]
// Decompiled from int __thiscall CDonkeyRole::GetAvailableSpace(CDonkeyRole *this, int a2)

int  CDonkeyRole::GetAvailableSpace(int) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 20) == a2 && 8 - *((_DWORD *)this + 3 * i + 21) > 0 )
      v3 += 8 - *((_DWORD *)this + 3 * i + 21);
  }
  return v3;
}


// address=[0x156a600]
// Decompiled from int __thiscall CDonkeyRole::GetAvailableSpace(CDonkeyRole *this)

int  CDonkeyRole::GetAvailableSpace(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( !*((_DWORD *)this + 3 * i + 20) )
      v2 += 8;
  }
  return v2;
}


// address=[0x156a650]
// Decompiled from char __thiscall CDonkeyRole::IsFull(CDonkeyRole *this)

bool  CDonkeyRole::IsFull(void) {
  
  int v2; // [esp+0h] [ebp-10h]
  int i; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]

  if ( CDonkeyRole::IsNeutralTrader(this) )
  {
    v2 = 0;
    for ( i = 0; i < 2; ++i )
    {
      v2 += *((_DWORD *)this + 3 * i + 21);
      if ( v2 >= 16 )
        return 1;
    }
    return 0;
  }
  else
  {
    for ( j = 0; j < 2; ++j )
    {
      if ( !*((_DWORD *)this + 3 * j + 20) )
        return 0;
      if ( 8 - *((_DWORD *)this + 3 * j + 21) > 0 )
        return 0;
    }
    return 1;
  }
}


// address=[0x156a700]
// Decompiled from char __thiscall CDonkeyRole::HasLoadedSomething(CDonkeyRole *this)

bool  CDonkeyRole::HasLoadedSomething(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 21) )
      return 1;
  }
  return 0;
}


// address=[0x156a740]
// Decompiled from int __thiscall CDonkeyRole::DropGoods(CDonkeyRole *this, struct CSettler *a2)

void  CDonkeyRole::DropGoods(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp-Ch] [ebp-20h]
  unsigned int v6; // [esp+4h] [ebp-10h]
  int j; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 43; ++i )
  {
    for ( j = CDonkeyRole::GetGoodAmount(this, i); j; j -= v6 )
    {
      if ( j > 8 )
        v6 = 8;
      else
        v6 = j;
      v4 = IEntity::Y(a2);
      v2 = IEntity::X(a2);
      CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v2, v4, i, v6);
      CDonkeyRole::RemoveGood(this, i, v6);
    }
  }
  return IEntity::ClearFlagBits(a2, VulnerableMask);
}


// address=[0x156a7f0]
// Decompiled from char __thiscall CDonkeyRole::SetFree(CDonkeyRole *this)

bool  CDonkeyRole::SetFree(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // [esp-8h] [ebp-10h]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-4h]

  if ( !*((_DWORD *)this + 12) )
    return 0;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  if ( CDonkeyRole::HasLoadedSomething(this) )
    CDonkeyRole::DropGoods(this, (struct CSettler *)SettlerPtr);
  v5 = IEntity::Type((unsigned __int16 *)SettlerPtr);
  v4 = IEntity::Type((unsigned __int16 *)SettlerPtr);
  v1 = IEntity::Race(SettlerPtr);
  v2 = CEntityToDoListMgr::SettlerJobList(v1, v4);
  (*(void (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)SettlerPtr + 112))(SettlerPtr, v2, v5);
  return 0;
}


// address=[0x156a870]
// Decompiled from char __thiscall CDonkeyRole::HasLoadGood(int *this, int a2)

bool  CDonkeyRole::HasLoadGood(enum PILE_TYPES) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( this[3 * i + 21] > 0 && this[3 * i + 20] == a2 )
      return 1;
  }
  return 0;
}


// address=[0x156a8c0]
// Decompiled from // MFC 3.1-14.0 32bit
CDonkeyRole *__thiscall CDonkeyRole::SetTargetBuildingID(CDonkeyRole *this, int a2)

void  CDonkeyRole::SetTargetBuildingID(int) {
  
  CDonkeyRole *result; // eax

  result = this;
  *((_DWORD *)this + 13) = a2;
  return result;
}


// address=[0x156a8e0]
// Decompiled from int __thiscall CDonkeyRole::GetTargetBuildingID(CDonkeyRole *this)

int  CDonkeyRole::GetTargetBuildingID(void) {
  
  return *((_DWORD *)this + 13);
}


// address=[0x156a900]
// Decompiled from void __thiscall CDonkeyRole::TargetBuildingDestroyed(CDonkeyRole *this)

void  CDonkeyRole::TargetBuildingDestroyed(void) {
  
  char IsNeutralTrader; // al
  unsigned __int8 *v2; // eax
  int v3; // eax
  CTradingBuildingRole *v4; // [esp+0h] [ebp-18h]
  CTradingBuildingRole *v5; // [esp+4h] [ebp-14h]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-10h]
  unsigned __int8 *v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]

  if ( *((_BYTE *)this + 47) && *((_DWORD *)this + 13) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 13));
    v5 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    CTradingBuildingRole::UnregisterIncomingTrader(v5, *((_DWORD *)this + 12), 2);
  }
  CDonkeyRole::SetTargetBuildingID(this, 0);
  if ( *((_DWORD *)this + 14)
    && (v8 = *((_DWORD *)this + 14), (v7 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v8)) != 0) )
  {
    CDonkeyRole::SetDepartBuildingID(this, 0);
    CDonkeyRole::SetTargetBuildingID(this, v8);
    v4 = (CTradingBuildingRole *)CBuilding::Role(v7);
    IsNeutralTrader = CDonkeyRole::IsNeutralTrader(this);
    CTradingBuildingRole::RegisterIncomingTrader(v4, *((_DWORD *)this + 12), 2, IsNeutralTrader);
    v2 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 13));
    v3 = CBuilding::EnsignPackedXY(v2);
    CDonkeyRole::MoveToTarget(this, v3, 0);
  }
  else
  {
    CDonkeyRole::SetFree(this);
    CDonkeyRole::TryToGoHome(this);
    CDonkeyRole::SetJobType(this, 0);
  }
}


// address=[0x156aa30]
// Decompiled from void __thiscall CDonkeyRole::SetDepartBuildingID(CMFCToolBarImages *this, int a2)

void  CDonkeyRole::SetDepartBuildingID(int) {
  
  *((_DWORD *)this + 14) = a2;
}


// address=[0x156aa50]
// Decompiled from // Microsoft VisualC 14/net runtime
unsigned int __thiscall CDonkeyRole::GetDepartBuildingID(CUserToolsManager *this)

int  CDonkeyRole::GetDepartBuildingID(void) {
  
  return *((_DWORD *)this + 14);
}


// address=[0x156aa70]
// Decompiled from void __thiscall CDonkeyRole::DepartBuildingDestroyed(CDonkeyRole *this)

void  CDonkeyRole::DepartBuildingDestroyed(void) {
  
  CTradingBuildingRole *v1; // eax
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-Ch]
  int v3; // [esp+8h] [ebp-8h]

  v3 = *((_DWORD *)this + 14);
  CDonkeyRole::SetDepartBuildingID(this, 0);
  if ( *((_BYTE *)this + 46) )
  {
    if ( !v3 && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1025, "iDep") == 1 )
      __debugbreak();
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v3);
    v1 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    CTradingBuildingRole::UnregisterIncomingTrader(v1, *((_DWORD *)this + 12), 2);
  }
  if ( !CDonkeyRole::GetTargetBuildingID(this) )
  {
    CDonkeyRole::SetJobType(this, 0);
    CDonkeyRole::TryToGoHome(this);
  }
}


// address=[0x156ab10]
// Decompiled from char __thiscall CDonkeyRole::DonkeyArrived(CDonkeyRole *this)

void  CDonkeyRole::DonkeyArrived(void) {
  
  unsigned __int8 *v1; // eax
  void **VehiclePtr; // eax
  int v4; // [esp-4h] [ebp-28h]
  CTradingBuildingRole *v5; // [esp+4h] [ebp-20h]
  CTradingBuildingRole *v6; // [esp+8h] [ebp-1Ch]
  unsigned __int8 *SettlerPtr; // [esp+Ch] [ebp-18h]
  CTradingBuildingRole *v8; // [esp+10h] [ebp-14h]
  void **v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v12; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v13; // [esp+1Ch] [ebp-8h]

  *((_DWORD *)this + 27) = 0;
  if ( *((_BYTE *)this + 46) )
  {
    if ( *((_DWORD *)this + 14) )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 14));
      if ( BuildingPtr )
      {
        v8 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
        CTradingBuildingRole::VehicleArrived(v8, *((_DWORD *)this + 12), 2);
      }
    }
    if ( *((_BYTE *)this + 45) && !*((_BYTE *)this + 72) )
    {
      if ( !*((_WORD *)this + 37)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1077, "m_uSourcePileID > 0") == 1 )
      {
        __debugbreak();
      }
      v10 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 37));
      if ( !v10 && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1079, "pPile != 0") == 1 )
        __debugbreak();
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 40))(v10) < *((_DWORD *)this + 17)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1080, "pPile->Amount() >= m_iCargoAmount") == 1 )
      {
        __debugbreak();
      }
      *((_BYTE *)this + 72) = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 60))(v10);
      v4 = *((_DWORD *)this + 12);
      v1 = CPileMgr::operator[](*((unsigned __int16 *)this + 37));
      CPile::ChangeAmountAndDetach((CPile *)v1, v4);
      *((_WORD *)this + 37) = 0;
      SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
      (*(void (__thiscall **)(CDonkeyRole *, unsigned __int8 *))(*(_DWORD *)this + 36))(this, SettlerPtr);
    }
  }
  if ( *((_BYTE *)this + 47) )
  {
    if ( *((_DWORD *)this + 13) )
    {
      v12 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 13));
      if ( v12 )
      {
        v6 = (CTradingBuildingRole *)CBuilding::Role(v12);
        CTradingBuildingRole::VehicleArrived(v6, *((_DWORD *)this + 12), 2);
      }
    }
    if ( *((_DWORD *)this + 14) )
    {
      v13 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 14));
      if ( v13 )
      {
        v5 = (CTradingBuildingRole *)CBuilding::Role(v13);
        CTradingBuildingRole::VehicleArrivedAtTarget(v5, *((_DWORD *)this + 12), 2);
      }
    }
  }
  if ( *((int *)this + 15) > 0 )
  {
    if ( !CMapObjectMgr::ValidEntityId(*((_DWORD *)this + 15))
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\DonkeyRole.cpp",
           1125,
           "g_pMapObjectMgr->ValidEntityId((m_iTargetCardID))") == 1 )
    {
      __debugbreak();
    }
    VehiclePtr = (void **)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 15));
    v9 = VehiclePtr;
    if ( !VehiclePtr )
    {
      *((_DWORD *)this + 15) = 0;
      return (char)VehiclePtr;
    }
    if ( !j____RTDynamicCast(VehiclePtr, 0, &CVehicle__RTTI_Type_Descriptor_, &CCart__RTTI_Type_Descriptor_, 0)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1138, "dynamic_cast<CCart*>(pVehicle)!=NULL") == 1 )
    {
      __debugbreak();
    }
    CCart::DonkeyArrived((CCart *)v9, *((_DWORD *)this + 12));
    *((_DWORD *)this + 15) = 0;
  }
  LOBYTE(VehiclePtr) = *((_BYTE *)this + 120);
  if ( !(_BYTE)VehiclePtr )
    return (char)VehiclePtr;
  *((_BYTE *)this + 120) = 0;
  LOBYTE(VehiclePtr) = CDonkeyRole::SetFree(this);
  return (char)VehiclePtr;
}


// address=[0x156ae00]
// Decompiled from void __thiscall CDonkeyRole::MoveToTarget(CDonkeyRole *this, int a2, int a3)

void  CDonkeyRole::MoveToTarget(int,int) {
  
  unsigned __int8 *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( a2 )
  {
    if ( *((_DWORD *)this + 12) )
    {
      SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
      IMovingEntity::WalkToXY((IMovingEntity *)SettlerPtr, a2, a3);
      *((_BYTE *)this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(CDonkeyRole *, unsigned __int8 *))(*(_DWORD *)this + 16))(this, SettlerPtr);
    }
  }
}


// address=[0x156ae70]
// Decompiled from int __thiscall CDonkeyRole::OwnerId(CDonkeyRole *this)

int  CDonkeyRole::OwnerId(void) {
  
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-4h]

  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  if ( !SettlerPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1221, "pSettler != NULL") == 1 )
    __debugbreak();
  if ( SettlerPtr )
    return IEntity::OwnerId(SettlerPtr);
  else
    return 0;
}


// address=[0x156aed0]
// Decompiled from CDonkeyRole *__thiscall CDonkeyRole::UpdateCatapultPosition(CDonkeyRole *this, int a2)

void  CDonkeyRole::UpdateCatapultPosition(int) {
  
  CDonkeyRole *result; // eax
  unsigned __int8 *SettlerPtr; // [esp+0h] [ebp-8h]

  result = this;
  if ( !*((_WORD *)this + 38) )
    return result;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  *((_DWORD *)this + 6) = a2;
  result = this;
  if ( !*((_BYTE *)this + 47) )
    return result;
  IMovingEntity::WalkToXY((IMovingEntity *)SettlerPtr, *((_DWORD *)this + 6), 0);
  return (CDonkeyRole *)(*(int (__thiscall **)(CDonkeyRole *, unsigned __int8 *))(*(_DWORD *)this + 16))(
                          this,
                          SettlerPtr);
}


// address=[0x156af40]
// Decompiled from unsigned int __thiscall CDonkeyRole::ComeToBuildUpCart(CDonkeyRole *this, int a2, unsigned int a3)

void  CDonkeyRole::ComeToBuildUpCart(int,int) {
  
  int v3; // eax
  int v4; // eax
  unsigned int result; // eax
  unsigned __int8 *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( !CMapObjectMgr::ValidEntityId(a3)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1180, "g_pMapObjectMgr->ValidEntityId(_iCardID)") == 1 )
  {
    __debugbreak();
  }
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  v3 = IEntity::Race(SettlerPtr);
  v4 = CEntityToDoListMgr::SettlerJobList(v3, 237);
  (*(void (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)SettlerPtr + 112))(SettlerPtr, v4, 237);
  (*(void (__thiscall **)(CDonkeyRole *, unsigned __int8 *))(*(_DWORD *)this + 40))(this, SettlerPtr);
  CDonkeyRole::MoveToTarget(this, a2, 0);
  result = a3;
  *((_DWORD *)this + 15) = a3;
  *((_DWORD *)this + 16) = 5;
  return result;
}


// address=[0x156b000]
// Decompiled from int __thiscall CDonkeyRole::SetJobType(CDonkeyRole *this, int a2)

void  CDonkeyRole::SetJobType(int) {
  
  int result; // eax

  if ( a2 )
  {
    if ( a2 == 3 || a2 == 4 )
    {
      CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
      IMovingEntity::SetDisplacementCosts(10);
    }
  }
  else
  {
    if ( *((_DWORD *)this + 13) )
      CDonkeyRole::SetTargetBuildingID(this, 0);
    CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
    IMovingEntity::SetDisplacementCosts(5);
  }
  result = a2;
  *((_DWORD *)this + 16) = a2;
  return result;
}


// address=[0x156b080]
// Decompiled from // MFC 3.1-14.0 32bit
int __thiscall CDonkeyRole::GetJobType(CDonkeyRole *this)

int  CDonkeyRole::GetJobType(void) {
  
  return *((_DWORD *)this + 16);
}


// address=[0x156b0a0]
// Decompiled from // public: void __thiscall CDonkeyRole::SetGoToSource(bool)
_BYTE *__thiscall CDonkeyRole::SetGoToSource(_BYTE *this, char a2)

void  CDonkeyRole::SetGoToSource(bool) {
  
  _BYTE *result; // eax

  result = this;
  this[46] = a2;
  return result;
}


// address=[0x156b0c0]
// Decompiled from // public: void __thiscall CDonkeyRole::SetGoToTarget(bool)
_BYTE *__thiscall CDonkeyRole::SetGoToTarget(_BYTE *this, char a2)

void  CDonkeyRole::SetGoToTarget(bool) {
  
  _BYTE *result; // eax

  result = this;
  this[47] = a2;
  return result;
}


// address=[0x156b0e0]
// Decompiled from char __thiscall CDonkeyRole::GetNextJob(CDonkeyRole *this, struct CSettler *a2)

void  CDonkeyRole::GetNextJob(class CSettler *) {
  
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    return CDonkeyRole::SetFree(this);
  else
    return (*(int (__thiscall **)(CDonkeyRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
}


// address=[0x156b120]
// Decompiled from _DWORD *__thiscall CDonkeyRole::FillDialog(CDonkeyRole *this, bool a2)

void  CDonkeyRole::FillDialog(bool) {
  
  unsigned int v3; // [esp+4h] [ebp-34h]
  int i; // [esp+Ch] [ebp-2Ch]
  CEvn_Event v6; // [esp+10h] [ebp-28h] BYREF
  int v7; // [esp+34h] [ebp-4h]

  CInfoExchange::Clear(&g_cVehicleLoadInfo);
  for ( i = 0; i < 2; ++i )
  {
    dword_3F1E790[3 * i] = *((_DWORD *)this + 3 * i + 20);
    dword_3F1E794[3 * i] = *((_DWORD *)this + 3 * i + 21);
  }
  dword_3F1E78C = 24;
  v3 = 604;
  if ( !a2 )
    v3 = 602;
  CEvn_Event::CEvn_Event(&v6, v3, 0, (unsigned int)&g_cVehicleLoadInfo, 0);
  v7 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v6);
  v7 = -1;
  return CEvn_Event::~CEvn_Event(&v6);
}


// address=[0x156b210]
// Decompiled from char __thiscall CDonkeyRole::SetNeutralTraderStatus(CDonkeyRole *this, bool a2)

void  CDonkeyRole::SetNeutralTraderStatus(bool) {
  
  unsigned __int8 *SettlerPtr; // eax
  unsigned __int8 *v4; // [esp+0h] [ebp-8h]

  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  v4 = SettlerPtr;
  if ( !SettlerPtr )
  {
    SettlerPtr = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1606, "pDonkey!=NULL");
    if ( SettlerPtr == (unsigned __int8 *)1 )
      __debugbreak();
  }
  if ( !v4 )
    return (char)SettlerPtr;
  if ( a2 )
  {
    IEntity::ClearFlagBits(v4, VulnerableMask);
    if ( !*((_DWORD *)this + 29) || *((_DWORD *)this + 29) == 2 )
    {
      LOBYTE(SettlerPtr) = (_BYTE)this;
      *((_DWORD *)this + 29) = 1;
      *((_BYTE *)this + 104) = a2;
      return (char)SettlerPtr;
    }
    if ( *((_DWORD *)this + 29) == 1 )
    {
      *((_DWORD *)this + 29) = 2;
      LOBYTE(SettlerPtr) = a2;
      *((_BYTE *)this + 104) = a2;
      return (char)SettlerPtr;
    }
  }
  else
  {
    *((_DWORD *)this + 29) = 0;
  }
  LOBYTE(SettlerPtr) = a2;
  *((_BYTE *)this + 104) = a2;
  return (char)SettlerPtr;
}


// address=[0x156b2d0]
// Decompiled from CDonkeyRole *__thiscall CDonkeyRole::ClearNeutralTraderStatus(CDonkeyRole *this)

void  CDonkeyRole::ClearNeutralTraderStatus(void) {
  
  CDonkeyRole *result; // eax

  result = this;
  *((_BYTE *)this + 104) = 0;
  *((_DWORD *)this + 29) = 0;
  return result;
}


// address=[0x156b2f0]
// Decompiled from CDonkeyRole *__thiscall CDonkeyRole::TryToGoHome(CDonkeyRole *this)

void  CDonkeyRole::TryToGoHome(void) {
  
  CDonkeyRole *result; // eax
  int v2; // eax
  int v3; // eax
  CDonkeyRole *v4; // esi
  int v5; // eax
  int v6; // [esp-4h] [ebp-10h]
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-8h]

  result = this;
  if ( !*((_DWORD *)this + 12) )
    return result;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  v6 = Y16X16::UnpackYFast(*((_DWORD *)this + 7));
  v2 = Y16X16::UnpackXFast(*((_DWORD *)this + 7));
  v3 = CWorldManager::Index(v2, v6);
  v4 = (CDonkeyRole *)CWorldManager::EcoSectorId(v3);
  v5 = IEntity::WorldIdx();
  result = (CDonkeyRole *)CWorldManager::EcoSectorId(v5);
  if ( v4 != result )
    return result;
  CDonkeyRole::SetFree(this);
  IAnimatedEntity::SetFrame(1);
  IMovingEntity::WalkToXY((IMovingEntity *)SettlerPtr, *((_DWORD *)this + 7), 0);
  *((_BYTE *)this + 4) = 6;
  IMovingEntity::SetDisplacementCosts(5);
  (*(void (__thiscall **)(CDonkeyRole *, unsigned __int8 *))(*(_DWORD *)this + 16))(this, SettlerPtr);
  result = this;
  *((_BYTE *)this + 120) = 1;
  return result;
}


// address=[0x156b3c0]
// Decompiled from unsigned __int8 *__thiscall CDonkeyRole::GoToHomeTradingBuilding(CDonkeyRole *this)

void  CDonkeyRole::GoToHomeTradingBuilding(void) {
  
  unsigned __int8 *result; // eax
  unsigned __int8 *BuildingPtr; // eax
  unsigned __int8 *v3; // eax
  int v4; // [esp+0h] [ebp-10h]
  IMovingEntity *v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  result = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 12));
  v5 = (IMovingEntity *)result;
  if ( !result )
  {
    result = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1258, "pSettler!=NULL");
    if ( result == (unsigned __int8 *)1 )
      __debugbreak();
  }
  if ( !v5 )
    return result;
  v6 = *((_DWORD *)this + 7);
  if ( *((_DWORD *)this + 29) == 1 && *((_DWORD *)this + 14) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 14));
    v6 = CBuilding::EnsignPackedXY(BuildingPtr);
  }
  if ( *((_DWORD *)this + 29) == 2 )
  {
    if ( *((_DWORD *)this + 13) )
    {
      v3 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 13));
      v6 = CBuilding::EnsignPackedXY(v3);
    }
  }
  IMovingEntity::WalkToXY(v5, v6, 0);
  v4 = *((_DWORD *)this + 14);
  *((_DWORD *)this + 14) = *((_DWORD *)this + 13);
  *((_DWORD *)this + 13) = v4;
  CDonkeyRole::ClearNeutralTraderStatus(this);
  result = (unsigned __int8 *)this;
  *((_BYTE *)this + 120) = 1;
  return result;
}


// address=[0x156b4b0]
// Decompiled from char *__thiscall CDonkeyRole::CDonkeyRole(char *this, int a2)

 CDonkeyRole::CDonkeyRole(std::istream &) {
  
  int v3; // [esp+4h] [ebp-20h] BYREF
  int pExceptionObject; // [esp+8h] [ebp-1Ch] BYREF
  int i; // [esp+Ch] [ebp-18h]
  unsigned int v6; // [esp+10h] [ebp-14h] BYREF
  char *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v7 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v8 = 0;
  *(_DWORD *)v7 = &CDonkeyRole::_vftable_;
  *((_DWORD *)v7 + 27) = 0;
  *((_DWORD *)v7 + 28) = 0;
  *((_DWORD *)v7 + 29) = 0;
  v7[120] = 0;
  operator^<unsigned int>(a2, &v6);
  if ( !v6 || v6 > 5 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDonkeyRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v7 + 44);
  operator^<bool>(a2, v7 + 45);
  operator^<bool>(a2, v7 + 46);
  operator^<bool>(a2, v7 + 47);
  operator^<int>(a2, (int)(v7 + 48));
  operator^<int>(a2, (int)(v7 + 52));
  operator^<int>(a2, (int)(v7 + 56));
  operator^<int>(a2, (int)(v7 + 60));
  operator^<int>(a2, (int)(v7 + 64));
  operator^<int>(a2, (int)(v7 + 68));
  operator^<unsigned char>(a2, v7 + 72);
  operator^<unsigned short>(a2, v7 + 74);
  operator^<unsigned short>(a2, v7 + 76);
  for ( i = 0; i < 2; ++i )
  {
    operator^<int>(a2, (int)&v7[12 * i + 84]);
    operator^<int>(a2, (int)&v7[12 * i + 88]);
    operator^<int>(a2, (int)&v7[12 * i + 80]);
  }
  if ( v6 == 2 )
    operator^<bool>(a2, v7 + 104);
  if ( v6 >= 3 )
  {
    operator^<bool>(a2, v7 + 104);
    operator^<int>(a2, (int)(v7 + 108));
  }
  if ( v6 >= 4 )
  {
    operator^<int>(a2, (int)&v3);
    *((_DWORD *)v7 + 29) = v3;
  }
  if ( v6 == 5 )
    operator^<bool>(a2, v7 + 120);
  return v7;
}


// address=[0x156b770]
// Decompiled from int __thiscall CDonkeyRole::Store(struct CPersistence *this, struct std::ostream *a2)

void  CDonkeyRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h]
  struct CPersistence *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  ISettlerRole::Store(this, a2);
  v4 = 5;
  operator^<unsigned int>(a2, &v4);
  operator^<unsigned char>(a2, (int)v6 + 44);
  operator^<bool>((int)a2, (int)v6 + 45);
  operator^<bool>((int)a2, (int)v6 + 46);
  operator^<bool>((int)a2, (int)v6 + 47);
  operator^<int>((int)a2, (int *)v6 + 12);
  operator^<int>((int)a2, (int *)v6 + 13);
  operator^<int>((int)a2, (int *)v6 + 14);
  operator^<int>((int)a2, (int *)v6 + 15);
  operator^<int>((int)a2, (int *)v6 + 16);
  operator^<int>((int)a2, (int *)v6 + 17);
  operator^<unsigned char>(a2, (int)v6 + 72);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 37);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 38);
  for ( i = 0; i < 2; ++i )
  {
    operator^<int>((int)a2, (int *)v6 + 3 * i + 21);
    operator^<int>((int)a2, (int *)v6 + 3 * i + 22);
    operator^<int>((int)a2, (int *)v6 + 3 * i + 20);
  }
  operator^<bool>((int)a2, (int)v6 + 104);
  operator^<int>((int)a2, (int *)v6 + 27);
  v3 = *((_DWORD *)v6 + 29);
  operator^<int>((int)a2, &v3);
  return operator^<bool>((int)a2, (int)v6 + 120);
}


// address=[0x156cdf0]
// Decompiled from int __thiscall CDonkeyRole::ClassID(CDonkeyRole *this)

unsigned long  CDonkeyRole::ClassID(void)const {
  
  return CDonkeyRole::m_iClassID;
}


// address=[0x156ce10]
// Decompiled from int __thiscall CDonkeyRole::GetSettlerRole(CDonkeyRole *this)

int  CDonkeyRole::GetSettlerRole(void)const {
  
  return 20;
}


// address=[0x156ce30]
// Decompiled from bool __thiscall CDonkeyRole::IsUnEmployed(CDonkeyRole *this)

bool  CDonkeyRole::IsUnEmployed(void)const {
  
  return *((_DWORD *)this + 16) == 0;
}


// address=[0x1588540]
// Decompiled from int __cdecl CDonkeyRole::Load(int a1)

static class CDonkeyRole * __cdecl CDonkeyRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CDonkeyRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8beb4]
// [Decompilation failed for static unsigned long CDonkeyRole::m_iClassID]

// address=[0x156b950]
// Decompiled from CDonkeyRole *__thiscall CDonkeyRole::CDonkeyRole(CDonkeyRole *this)

 CDonkeyRole::CDonkeyRole(void) {
  
  int i; // [esp+0h] [ebp-8h]

  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CDonkeyRole::_vftable_;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_BYTE *)this + 104) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_BYTE *)this + 120) = 0;
  *((_BYTE *)this + 44) = 0;
  for ( i = 0; i < 2; ++i )
  {
    *((_DWORD *)this + 3 * i + 20) = 0;
    *((_DWORD *)this + 3 * i + 21) = 0;
  }
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_WORD *)this + 38) = 0;
  *((_WORD *)this + 37) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_BYTE *)this + 46) = 0;
  *((_BYTE *)this + 47) = 0;
  return this;
}


// address=[0x156ba30]
// Decompiled from ISettlerRole *__thiscall CDonkeyRole::~CDonkeyRole(CDonkeyRole *this)

 CDonkeyRole::~CDonkeyRole(void) {
  
  *(_DWORD *)this = &CDonkeyRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x156ba50]
// Decompiled from void __thiscall CDonkeyRole::TakeJob(CDonkeyRole *this, struct CSettler *a2)

void  CDonkeyRole::TakeJob(class CSettler *) {
  
  const struct CEntityTask *ActualTask; // eax
  unsigned int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int8 *BuildingPtr; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  char IsNeutralTrader; // al
  int v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-18h]
  CTradingBuildingRole *v15; // [esp+8h] [ebp-10h]
  unsigned __int8 *v16; // [esp+Ch] [ebp-Ch]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  switch ( *((_BYTE *)this + 4) )
  {
    case 0xA:
      IAnimatedEntity::SetFrame(1);
      v14 = *((__int16 *)this + 7) + Y16X16::UnpackXFast(*((_DWORD *)this + 6));
      v13 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
      *((_DWORD *)this + 6) = Y16X16::PackXYFast(v14, *((__int16 *)this + 8) + v13);
      CDonkeyRole::MoveToTarget(this, *((_DWORD *)this + 6), 0);
      *((_BYTE *)this + 47) = 1;
      break;
    case 0xE:
      CDonkeyRole::TryToGoHome(this);
      break;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(0);
      v3 = CStateGame::Rand(g_pGame);
      IAnimatedEntity::RegisterForLogicUpdate(v3 % 0x10 + 1);
      break;
    case 0x12:
      if ( debug && DEBUG_FLAGS[dword_41520A8] )
      {
        v6 = IEntity::ID();
        BBSupportTracePrintF(0, "Carier %u TakeJob go to source pile", v6);
      }
      *((_DWORD *)this + 7) = IEntity::PackedXY(a2);
      *((_BYTE *)this + 46) = 1;
      *((_BYTE *)this + 47) = 0;
      if ( *((_DWORD *)this + 14) )
      {
        BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 14));
        v8 = CBuilding::EnsignPackedXY(BuildingPtr);
        CDonkeyRole::MoveToTarget(this, v8, 0);
      }
      else if ( *((_WORD *)this + 37) )
      {
        v9 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 37));
        v10 = IEntity::PackedXY(v9);
        CDonkeyRole::MoveToTarget(this, v10, 4096);
      }
      break;
    case 0x13:
      *((_BYTE *)this + 46) = 0;
      *((_BYTE *)this + 47) = 1;
      if ( *((_DWORD *)this + 13) )
      {
        v16 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 13));
        v15 = (CTradingBuildingRole *)CBuilding::Role(v16);
        IsNeutralTrader = CDonkeyRole::IsNeutralTrader(this);
        CTradingBuildingRole::RegisterIncomingTrader(v15, *((_DWORD *)this + 12), 2, IsNeutralTrader);
        v12 = CBuilding::EnsignPackedXY(v16);
        CDonkeyRole::MoveToTarget(this, v12, 0);
        if ( CDonkeyRole::HasLoadedSomething(this) && !CDonkeyRole::IsNeutralTrader(this) )
          IEntity::SetFlagBits(a2, VulnerableMask);
      }
      break;
    case 0x15:
      if ( debug && DEBUG_FLAGS[dword_41520A8] )
      {
        v4 = IEntity::ID();
        BBSupportTracePrintF(0, "Carier %u TakeJob put_good", v4);
      }
      IMovingEntity::SetDisplacementCosts(10);
      IEntity::ClearFlagBits(a2, VulnerableMask);
      CDonkeyRole::DonkeyArrived(this);
      break;
    case 0x16:
      if ( debug && DEBUG_FLAGS[dword_41520A8] )
      {
        v5 = IEntity::ID();
        BBSupportTracePrintF(0, "Carier %u TakeJob get_good", v5);
      }
      IMovingEntity::SetDisplacementCosts(10);
      CDonkeyRole::DonkeyArrived(this);
      break;
    case 0x17:
      IMovingEntity::SetDisplacementCosts(10);
      IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
      break;
    case 0x20:
      IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6) / 2 - 1);
      break;
    default:
      CTrace::Print("Donkey TakeJob - unknown job");
      IAnimatedEntity::RegisterForLogicUpdate(3);
      break;
  }
}


// address=[0x156bdd0]
// Decompiled from int __thiscall CDonkeyRole::Init(int this, CPropertySet *a2)

void  CDonkeyRole::Init(class CSettler *) {
  
  int result; // eax

  if ( IEntity::FlagBits(a2, Attached)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 255, "!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
  {
    __debugbreak();
  }
  if ( *(_WORD *)(this + 32)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 256, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)(this + 48) = IEntity::ID();
  CWarMap::AddEntity(a2);
  IEntity::ClearFlagBits(a2, VulnerableMask|Selectable|Selected);
  IEntity::SetFlagBits(a2, (EntityFlag)0x4000u);
  result = this;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 64) = 0;
  return result;
}


// address=[0x156be90]
// Decompiled from int __thiscall CDonkeyRole::ConvertEventIntoGoal(CDonkeyRole *this, struct CSettler *a2, struct CEntityEvent *a3)

void  CDonkeyRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int result; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-3Ch]
  int v21; // [esp+0h] [ebp-38h]
  int v22; // [esp+4h] [ebp-34h]
  _DWORD *v23; // [esp+8h] [ebp-30h]
  _DWORD *v24; // [esp+Ch] [ebp-2Ch]
  int v25; // [esp+10h] [ebp-28h]
  unsigned __int8 *v26; // [esp+14h] [ebp-24h]
  unsigned __int8 *v27; // [esp+18h] [ebp-20h]
  int v28; // [esp+1Ch] [ebp-1Ch]
  int v29; // [esp+20h] [ebp-18h]
  unsigned __int8 *v30; // [esp+28h] [ebp-10h]
  _DWORD *v31; // [esp+2Ch] [ebp-Ch]
  int v32; // [esp+30h] [ebp-8h]

  switch ( *((_DWORD *)a3 + 1) )
  {
    case 7:
    case 9:
      if ( debug && DEBUG_FLAGS[dword_41520A8] )
      {
        v3 = IEntity::ID();
        BBSupportTracePrintF(0, "Donkey %u order canceled - target die", v3);
      }
      if ( *((_BYTE *)this + 45) )
      {
        if ( *((_DWORD *)a3 + 3) == *((unsigned __int16 *)this + 37) )
        {
          v27 = CPileMgr::operator[](*((unsigned __int16 *)this + 37));
          v4 = IEntity::ID();
          (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v27 + 64))(v27, v4);
          *((_WORD *)this + 37) = 0;
        }
        if ( *((_DWORD *)a3 + 3) == *((unsigned __int16 *)this + 38) )
        {
          v5 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 38));
          v29 = IEntity::ObjType(v5);
          if ( v29 == 2 || v29 == 4 )
          {
            v25 = CVehicleMgr::operator[](*((unsigned __int16 *)this + 38));
            v7 = IEntity::ID();
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v25 + 64))(v25, v7);
          }
          else if ( v29 == 16 )
          {
            v26 = CPileMgr::operator[](*((unsigned __int16 *)this + 38));
            v6 = IEntity::ID();
            (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v26 + 64))(v26, v6);
          }
          *((_WORD *)this + 38) = 0;
          CDonkeyRole::TryToGoHome(this);
        }
        *((_BYTE *)this + 45) = 0;
      }
      else if ( *((_DWORD *)a3 + 3) == *((_DWORD *)this + 13) )
      {
        CDonkeyRole::TargetBuildingDestroyed(this);
      }
      else if ( *((_DWORD *)a3 + 3) == *((_DWORD *)this + 14) )
      {
        CDonkeyRole::DepartBuildingDestroyed(this);
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      goto LABEL_57;
    case 0xA:
      if ( debug && DEBUG_FLAGS[dword_41520A8] )
      {
        v8 = IEntity::ID();
        BBSupportTracePrintF(0, "Donkey %u TRANSPORT_GOOD", v8);
      }
      *((_BYTE *)this + 45) = 0;
      *((_BYTE *)this + 120) = 0;
      if ( *((_DWORD *)this + 14) && *((_DWORD *)this + 13) )
      {
        v24 = (_DWORD *)CBuildingMgr::operator[](*((_DWORD *)this + 14));
        v23 = (_DWORD *)CBuildingMgr::operator[](*((_DWORD *)this + 13));
        if ( IEntity::FlagBits(v24, (EntityFlag)&loc_3000000) && IEntity::FlagBits(v23, (EntityFlag)&loc_3000000) )
        {
          v9 = IEntity::Race(a2);
          v10 = CEntityToDoListMgr::SettlerJobList(v9, 163);
          (*(void (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v10, 163);
        }
        else
        {
          if ( debug && DEBUG_FLAGS[dword_41520A8] )
          {
            v11 = IEntity::ID();
            BBSupportTracePrintF(0, "WARNING: Donkey %u CONV TRANSPORT_GOOD cancled!", v11);
          }
          if ( !IEntity::FlagBits(v24, (EntityFlag)&loc_3000000) )
            CDonkeyRole::DepartBuildingDestroyed(this);
          if ( !IEntity::FlagBits(v23, (EntityFlag)&loc_3000000) )
            CDonkeyRole::TargetBuildingDestroyed(this);
        }
      }
      goto LABEL_57;
    case 0xB:
      *((_BYTE *)this + 47) = 0;
      if ( CDonkeyRole::GetJobType(this) && CDonkeyRole::GetJobType(this) != 5 )
      {
        v21 = CVehicleMgr::operator[](*((_DWORD *)a3 + 5));
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v21 + 124))(v21, *((unsigned __int16 *)this + 9));
LABEL_57:
        result = IEntity::FlagBits(a2, Registered);
        if ( result || !debug )
          return result;
        result = dword_41520AC;
        if ( !DEBUG_FLAGS[dword_41520AC] )
          return result;
        v19 = IEntity::ID();
        return BBSupportTracePrintF(0, "ConvertEvent- not registered settler %u", v19);
      }
      *((_WORD *)this + 37) = *((_WORD *)a3 + 8);
      *((_WORD *)this + 38) = *((_WORD *)a3 + 10);
      v32 = *((_DWORD *)a3 + 3);
      *((_BYTE *)this + 72) = 0;
      v30 = CPileMgr::operator[](*((unsigned __int16 *)this + 37));
      v31 = (_DWORD *)CVehicleMgr::operator[](*((unsigned __int16 *)this + 38));
      v28 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v30 + 40))(v30);
      if ( (v32 <= 0 || v28 < v32)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1535, "(iAmount>0) && (iPileAmount >= iAmount)") == 1 )
      {
        __debugbreak();
      }
      result = v28;
      if ( v28 < v32 )
        v32 = v28;
      if ( !v32 )
        return result;
      v20 = IEntity::ID();
      v13 = IEntity::ObjType((unsigned __int8 *)a2);
      v22 = (*(int (__thiscall **)(_DWORD *, int, int))(*v31 + 140))(v31, v13, v20);
      if ( IEntity::FlagBits(v31, (EntityFlag)&loc_3000000) && v22 )
      {
        ISettlerRole::NewDestination(this, a2, v22, 0);
        v14 = IEntity::Race(a2);
        v15 = CEntityToDoListMgr::SettlerJobList(v14, 164);
        (*(void (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v15, 164);
        v16 = IEntity::ID();
        CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v30, v16, v32, 2);
        *((_DWORD *)this + 17) = v32;
        v17 = IEntity::ID();
        (*(void (__thiscall **)(_DWORD *, int))(*v31 + 164))(v31, v17);
        v18 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v30 + 60))(v30, v32);
        (*(void (__thiscall **)(_DWORD *, int))(*v31 + 120))(v31, v18);
        *((_BYTE *)this + 45) = 1;
        CDonkeyRole::SetJobType(this, 1);
      }
      else
      {
        CDonkeyRole::SetFree(this);
      }
      goto LABEL_57;
    default:
      if ( !IEntity::FlagBits(a2, Registered) )
      {
        CTrace::Print("ConvertEventIntoGoal DonkeyRole - unknown event %u", *((_DWORD *)a3 + 1));
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      goto LABEL_57;
  }
}


