#include "CCatapult.h"

// Definitions for class CCatapult

// address=[0x153d480]
// Decompiled from void __thiscall CCatapult::Delete(CCatapult *this)

void  CCatapult::Delete(void) {
  
  CWheeler::Delete(this);
}


// address=[0x153d4a0]
// Decompiled from void __thiscall CCatapult::VehicleLogicUpdate(CCatapult *this)

void  CCatapult::VehicleLogicUpdate(void) {
  
  int v1; // [esp+4h] [ebp-18h]
  BOOL v2; // [esp+8h] [ebp-14h]
  int v3; // [esp+Ch] [ebp-10h]
  unsigned int TickCounter; // [esp+10h] [ebp-Ch]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( CWheeler::FULL_UPDATE_DELAY + *((_DWORD *)this + 53) < TickCounter )
  {
    CCatapult::TakeAmmo(this);
    v3 = CWheeler::RepairBuildingInRange(this);
    if ( v3 )
      CWheeler::RepairAt(this, v3);
    *((_DWORD *)this + 53) = TickCounter;
  }
  v2 = !CVehicle::ReadyToFire(this, TickCounter);
  if ( (*(unsigned __int8 (__thiscall **)(CCatapult *))(*(_DWORD *)this + 204))(this) )
    v1 = 0;
  else
    v1 = 2;
  if ( !IEntity::FlagBits(this, OnBoard) )
    CWarriorBehavior::WarriorVehicleLogicUpdate((CCatapult *)((char *)this + 180), this, TickCounter, v1 | v2);
}


// address=[0x153d590]
// Decompiled from void __thiscall CCatapult::ConvertEventIntoGoal(CCatapult *this, struct CEntityEvent *a2)

void  CCatapult::ConvertEventIntoGoal(class CEntityEvent *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-60h]
  _BYTE v5[24]; // [esp+4h] [ebp-58h] BYREF
  int v6; // [esp+1Ch] [ebp-40h]
  CEntityEvent *v7; // [esp+20h] [ebp-3Ch]
  CEntityEvent *v8; // [esp+24h] [ebp-38h]
  int v9; // [esp+28h] [ebp-34h]
  CDonkeyRole *v10; // [esp+2Ch] [ebp-30h]
  int v11; // [esp+30h] [ebp-2Ch]
  int v12; // [esp+34h] [ebp-28h]
  int v13; // [esp+38h] [ebp-24h]
  int v14; // [esp+3Ch] [ebp-20h]
  int v15; // [esp+40h] [ebp-1Ch]
  int v16; // [esp+44h] [ebp-18h]
  int *v17; // [esp+48h] [ebp-14h]
  unsigned __int8 *SettlerPtr; // [esp+4Ch] [ebp-10h]
  int v19; // [esp+58h] [ebp-4h]

  v17 = (int *)this;
  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 379, "_pEvent!=NULL") == 1 )
    __debugbreak();
  if ( a2 )
  {
    v13 = *((_DWORD *)a2 + 1);
    if ( v13 == 17 && *((_DWORD *)a2 + 2) == 13 )
    {
      v16 = *((_DWORD *)a2 + 4);
      v11 = Y16X16::UnpackXFast(v16);
      v12 = Y16X16::UnpackYFast(v16);
      if ( CCatapult::AttackTargetAt((CCatapult *)v17, v11, v12) )
        return;
      if ( v17[52] > 0 )
      {
        SettlerPtr = CSettlerMgr::GetSettlerPtr(v17[52]);
        if ( SettlerPtr && IEntity::Type((unsigned __int16 *)SettlerPtr) == 60 )
        {
          if ( IEntity::Type((unsigned __int16 *)SettlerPtr) != 60
            && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 407, "pSettler->Type() == SETTLER_DONKEY") == 1 )
          {
            __debugbreak();
          }
          v15 = CSettler::Role(SettlerPtr);
          if ( (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 72))(v15) != 20
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\Catapult\\Catapult.cpp",
                 408,
                 "pSettler->Role().GetSettlerRole() == DONKEY_ROLE") == 1 )
          {
            __debugbreak();
          }
          v10 = (CDonkeyRole *)CSettler::Role(SettlerPtr);
          CDonkeyRole::UpdateCatapultPosition(v10, v16);
        }
        if ( SettlerPtr && IEntity::Type((unsigned __int16 *)SettlerPtr) == 1 )
        {
          if ( IEntity::Type((unsigned __int16 *)SettlerPtr) != 1
            && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 417, "pSettler->Type() == SETTLER_CARRIER") == 1 )
          {
            __debugbreak();
          }
          v14 = CSettler::Role(SettlerPtr);
          if ( (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(v14) != 1
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\Catapult\\Catapult.cpp",
                 418,
                 "pSettler->Role().GetSettlerRole() == CARRIER_ROLE") == 1 )
          {
            __debugbreak();
          }
          v6 = CSettler::Role(SettlerPtr);
          v4 = IEntity::Y(v17);
          v2 = IEntity::X(v17);
          v9 = CWorldManager::EcoSectorId(v2, v4);
          v3 = IEntity::ID();
          v8 = CEntityEvent::CEntityEvent((CEntityEvent *)v5, 9u, 0, v3, v9, 0);
          v7 = v8;
          v19 = 0;
          (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v8);
          v19 = -1;
          CEntityEvent::~CEntityEvent(v5);
          v17[52] = 0;
        }
      }
    }
  }
  CWheeler::ConvertEventIntoGoal((CWheeler *)v17, a2);
}


// address=[0x153d840]
// Decompiled from int __thiscall CCatapult::WarriorTaskWalkOneStep(CCatapult *this, struct IMovingEntity *a2)

int  CCatapult::WarriorTaskWalkOneStep(class IMovingEntity &) {
  
  int v2; // eax
  int v3; // eax
  struct CWalking *v5; // [esp+0h] [ebp-8h]

  v5 = IMovingEntity::Walking((CCatapult *)((char *)this - 180));
  v2 = IEntity::PackedXY((char *)this - 180);
  v3 = (*(int (__thiscall **)(struct CWalking *, int))(*(_DWORD *)v5 + 12))(v5, v2);
  CVehicle::WalkDirAndRegister((CCatapult *)((char *)this - 180), v3, 0);
  return *((unsigned __int8 *)this - 76);
}


// address=[0x153d8a0]
// Decompiled from int __thiscall CCatapult::WarriorTaskAttack(char *this, int a2, int a3, int a4)

void  CCatapult::WarriorTaskAttack(class IMovingEntity &,int,enum T_WARRIOR_ATTACK) {
  
  int v4; // eax

  CVehicle::AttackTarget((CVehicle *)(this - 180), a3);
  CVehicle::TakeJobPart((CVehicle *)(this - 180), 0x23u);
  v4 = CVehicle::TurnCounter((CVehicle *)(this - 180));
  return CVehicle::RegisterNewTask((CVehicle *)(this - 180), 16, (unsigned __int8)*(this - 71) + v4);
}


// address=[0x153d900]
// Decompiled from int __thiscall CCatapult::WarriorTaskFinished(CCatapult *this, struct IMovingEntity *a2)

void  CCatapult::WarriorTaskFinished(class IMovingEntity &) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  CCarrierRole *v6; // [esp+0h] [ebp-18h]
  CDonkeyRole *v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+10h] [ebp-8h]

  if ( *((int *)this + 7) <= 0 )
    return CVehicle::GetNextJob((CCatapult *)((char *)this - 180));
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 7));
  if ( !SettlerPtr && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 650, "pSettler!= NULL") == 1 )
    __debugbreak();
  if ( !SettlerPtr )
    return CVehicle::GetNextJob((CCatapult *)((char *)this - 180));
  v9 = CSettler::Role(SettlerPtr);
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 72))(v9) == 20 )
  {
    v7 = (CDonkeyRole *)CSettler::Role(SettlerPtr);
    v2 = (*(int (__thiscall **)(char *, int, _DWORD))(*((_DWORD *)this - 45) + 140))(
           (char *)this - 180,
           1,
           *((_DWORD *)this + 7));
    CDonkeyRole::UpdateCatapultPosition(v7, v2);
  }
  v8 = CSettler::Role(SettlerPtr);
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 72))(v8) != 1 )
    return CVehicle::GetNextJob((CCatapult *)((char *)this - 180));
  v6 = (CCarrierRole *)CSettler::Role(SettlerPtr);
  v3 = IEntity::ID();
  v4 = (*(int (__thiscall **)(char *, int, int))(*((_DWORD *)this - 45) + 140))((char *)this - 180, 1, v3);
  CCarrierRole::UpdateCatapultPosition(v6, v4);
  return CVehicle::GetNextJob((CCatapult *)((char *)this - 180));
}


// address=[0x153da20]
// Decompiled from int __thiscall CCatapult::WarriorTaskIdleWalk(CCatapult *this, struct IMovingEntity *a2)

int  CCatapult::WarriorTaskIdleWalk(class IMovingEntity &) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  struct CWalking *v7; // [esp+0h] [ebp-8h]

  v2 = IEntity::PackedXY((char *)this - 180);
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(v2)
    && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 595, "g_cWorld.InWorldPackedXY(PackedXY())") == 1 )
  {
    __debugbreak();
  }
  v3 = IEntity::PackedXY((char *)this - 180);
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(v3) )
    return *((unsigned __int8 *)this - 76);
  v7 = IMovingEntity::Walking((CCatapult *)((char *)this - 180));
  v4 = IEntity::PackedXY((char *)this - 180);
  v5 = (*(int (__thiscall **)(struct CWalking *, int, _DWORD))(*(_DWORD *)v7 + 16))(v7, v4, 0);
  CVehicle::WalkDirAndRegister((CCatapult *)((char *)this - 180), v5, 0);
  return *((unsigned __int8 *)this - 76);
}


// address=[0x153dae0]
// Decompiled from CCatapult *__thiscall CCatapult::EntityOrderCanceled(CCatapult *this, int a2)

void  CCatapult::EntityOrderCanceled(int) {
  
  CCatapult *result; // eax

  result = this;
  if ( !*((_DWORD *)this + 52) )
  {
    result = (CCatapult *)BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 357, "m_iAmmoTransporterID != 0");
    if ( result == (CCatapult *)1 )
      __debugbreak();
  }
  *((_DWORD *)this + 52) = 0;
  return result;
}


// address=[0x153db30]
// Decompiled from CCatapult *__thiscall CCatapult::GoodArrived(CCatapult *this, int a2, int a3)

void  CCatapult::GoodArrived(int,int) {
  
  int v3; // edx
  CCatapult *result; // eax

  if ( !*((_DWORD *)this + 52)
    && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 371, "m_iAmmoTransporterID != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = a3 * (*(int (__thiscall **)(CCatapult *))(*(_DWORD *)this + 228))(this) + *((unsigned __int8 *)this + 111);
  result = this;
  *((_BYTE *)this + 111) = v3;
  *((_DWORD *)this + 52) = 0;
  return result;
}


// address=[0x153dba0]
// Decompiled from _DWORD *__thiscall CCatapult::CCatapult(_DWORD *this, int a2)

 CCatapult::CCatapult(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CWheeler::CWheeler(a2);
  v6 = 0;
  CWarriorBehavior::CWarriorBehavior((CWarriorBehavior *)(v5 + 45));
  *v5 = &CCatapult::_vftable_;
  v5[45] = &CCatapult::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CCatapult");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, v5 + 51);
  operator^<int>(a2, (int)(v5 + 52));
  operator^<int>(a2, (int)(v5 + 53));
  v6 = -1;
  return v5;
}


// address=[0x153dcb0]
// Decompiled from int __thiscall CCatapult::Store(int *this, struct std::ostream *a2)

void  CCatapult::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CWheeler::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<bool>((int)a2, (int)(v4 + 51));
  operator^<int>((int)a2, v4 + 52);
  return operator^<int>((int)a2, v4 + 53);
}


// address=[0x153dd30]
// Decompiled from CCatapult *__thiscall CCatapult::RequestAmmoDonkey(CCatapult *this)

void  CCatapult::RequestAmmoDonkey(void) {
  
  CCatapult *result; // eax

  result = this;
  if ( *((_DWORD *)this + 52) )
    return result;
  result = this;
  if ( (unsigned int)*((unsigned __int8 *)this + 111) >= *(_DWORD *)(*((_DWORD *)this + 25) + 84) )
    return result;
  result = (CCatapult *)CCatapult::RequestDonkey(this);
  *((_DWORD *)this + 52) = result;
  return result;
}


// address=[0x153dd70]
// Decompiled from int __thiscall CCatapult::GetMeetingPointXY(int this, int a2, int a3)

int const  CCatapult::GetMeetingPointXY(enum OBJ_TYPE,int) {
  
  int v3; // esi
  int v4; // esi
  unsigned __int8 *v5; // eax
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]
  int i; // [esp+18h] [ebp-4h]
  int v13; // [esp+18h] [ebp-4h]

  for ( i = *(char *)(this + 68); i < *(char *)(this + 68) + 6; i = v13 + 1 )
  {
    v13 = i % 6;
    v9 = 2 * ((v13 + 3) % 6) + 8;
    v3 = IEntity::X((_DWORD *)this);
    v7 = CSpiralOffsets::DeltaX(v9) + v3;
    v4 = IEntity::Y((void *)this);
    v8 = CSpiralOffsets::DeltaY(v9) + v4;
    v10 = CWorldManager::MapObjectId(v7, v8);
    if ( !v10 )
      return Y16X16::PackXYFast(v7, v8);
    v5 = (unsigned __int8 *)CMapObjectMgr::Entity(v10);
    if ( !IEntity::ObjType(v5) )
      continue;
    return Y16X16::PackXYFast(v7, v8);
  }
  return 0;
}


// address=[0x153de60]
// Decompiled from CCatapult *__thiscall CCatapult::SupplyCanceled(CCatapult *this, int a2, int a3)

void  CCatapult::SupplyCanceled(int,int) {
  
  CCatapult *result; // eax

  result = this;
  *((_DWORD *)this + 52) = 0;
  return result;
}


// address=[0x153de80]
// Decompiled from char __thiscall CCatapult::PostLoadInit(CCatapult *this)

void  CCatapult::PostLoadInit(void) {
  
  struct CWarriorBehavior::SWarriorBehaviorData *WarriorBehaviorData; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = *((_DWORD *)CWarriorBehavior::GetWarriorBehaviorData((CCatapult *)((char *)this + 180)) + 3);
  WarriorBehaviorData = CWarriorBehavior::GetWarriorBehaviorData((CCatapult *)((char *)this + 180));
  (**((void (__thiscall ***)(char *, CCatapult *, _DWORD, int))this + 45))(
    (char *)this + 180,
    this,
    *((_DWORD *)WarriorBehaviorData + 2),
    v3);
  return CVehicle::PostLoadInit(this);
}


// address=[0x153dee0]
// Decompiled from unsigned __int8 *__thiscall CCatapult::OnComeToFerry(CCatapult *this, int a2)

void  CCatapult::OnComeToFerry(int) {
  
  unsigned __int8 *result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-40h]
  _BYTE v6[24]; // [esp+4h] [ebp-38h] BYREF
  CEntityEvent *v7; // [esp+1Ch] [ebp-20h]
  CEntityEvent *v8; // [esp+20h] [ebp-1Ch]
  int v9; // [esp+24h] [ebp-18h]
  unsigned __int8 *v10; // [esp+28h] [ebp-14h]
  int *v11; // [esp+2Ch] [ebp-10h]
  int v12; // [esp+38h] [ebp-4h]

  v11 = (int *)this;
  result = (unsigned __int8 *)CWheeler::OnComeToFerry(this, a2);
  if ( v11[43] <= 0 || v11[52] <= 0 )
    return result;
  result = CSettlerMgr::GetSettlerPtr(v11[52]);
  v10 = result;
  if ( !result )
  {
    result = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 739, "pSettler!=NULL");
    if ( result == (unsigned __int8 *)1 )
      __debugbreak();
  }
  if ( !v10 )
    return result;
  v5 = IEntity::Y(v11);
  v3 = IEntity::X(v11);
  v9 = CWorldManager::EcoSectorId(v3, v5);
  v4 = IEntity::ID();
  v8 = CEntityEvent::CEntityEvent((CEntityEvent *)v6, 9u, 0, v4, v9, 0);
  v7 = v8;
  v12 = 0;
  (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)v10 + 80))(v10, v8);
  v12 = -1;
  result = (unsigned __int8 *)CEntityEvent::~CEntityEvent(v6);
  v11[52] = 0;
  return result;
}


// address=[0x153e000]
// Decompiled from CCatapult *__thiscall CCatapult::CCatapult(CCatapult *this, int a2, int a3, int a4, int a5, int a6, int a7, bool a8)

 CCatapult::CCatapult(int,int,int,int,int,int,bool) {
  
  CWheeler::CWheeler(this, a2, a3, a4, a5, a6, a7, a8);
  CWarriorBehavior::CWarriorBehavior((CCatapult *)((char *)this + 180));
  *(_DWORD *)this = &CCatapult::_vftable_;
  *((_DWORD *)this + 45) = &CCatapult::`vftable';
  *((_BYTE *)this + 204) = 1;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 53) = 0;
  if ( *(_DWORD *)(*((_DWORD *)this + 25) + 16) != 8
    && BBSupportDbgReport(
         2,
         "MapObjects\\Catapult\\Catapult.cpp",
         110,
         "m_pVehicleProperties->m_tWarriorType == WARRIOR_TYPE_VEHICLE_WAR") == 1 )
  {
    __debugbreak();
  }
  CWarriorBehavior::WarriorInit((CCatapult *)((char *)this + 180), this, -1, 0);
  if ( !a8 )
    CCatapult::TakeJob(this);
  return this;
}


// address=[0x153e110]
// Decompiled from void __thiscall CCatapult::~CCatapult(CCatapult *this)

 CCatapult::~CCatapult(void) {
  
  *(_DWORD *)this = &CCatapult::_vftable_;
  *((_DWORD *)this + 45) = &CCatapult::`vftable';
  CWheeler::~CWheeler(this);
}


// address=[0x153e140]
// Decompiled from void *__thiscall CCatapult::GetGfxInfos(CCatapult *this)

struct SGfxObjectInfo *  CCatapult::GetGfxInfos(void) {
  
  CWheeler::GetGfxInfos((int)this);
  if ( !IEntity::FlagBits(this, Selected) )
    return &IEntity::m_sGfxInfo;
  byte_40FE264 = CCatapult::GetHealthDisplayID(this);
  byte_40FE265 = CCatapult::GetAmmoDisplayID(this);
  return &IEntity::m_sGfxInfo;
}


// address=[0x153e190]
// Decompiled from int __thiscall CCatapult::TakeJob(CCatapult *this)

void  CCatapult::TakeJob(void) {
  
  int v1; // eax
  int v2; // eax
  __int64 v4; // [esp+0h] [ebp-14h]
  char v5; // [esp+8h] [ebp-Ch]
  int CurrentTaskPtr; // [esp+Ch] [ebp-8h]

  CVehicle::InitCommonTaskValues(this, 0);
  CurrentTaskPtr = CVehicle::GetCurrentTaskPtr(this);
  if ( !CurrentTaskPtr )
  {
LABEL_12:
    (**((void (__thiscall ***)(char *, CCatapult *, int, _DWORD))this + 45))((char *)this + 180, this, -1, 0);
    return (*(int (__thiscall **)(CCatapult *))(*(_DWORD *)this + 144))(this);
  }
  v5 = *(_BYTE *)(CurrentTaskPtr + 4);
  if ( v5 == 6 )
  {
    v1 = Y16X16::PackXYFast(*(__int16 *)(CurrentTaskPtr + 10), *(__int16 *)(CurrentTaskPtr + 12));
    (**((void (__thiscall ***)(char *, CCatapult *, int, int))this + 45))((char *)this + 180, this, v1, 0x200000);
  }
  else
  {
    if ( v5 != 7 )
    {
      if ( v5 != 8 )
      {
        if ( BBSupportDbgReport(1, "MapObjects\\Catapult\\Catapult.cpp", 528, "CCatapult::TakeJob(): Invalid task!") == 1 )
          __debugbreak();
        goto LABEL_12;
      }
      HIDWORD(v4) = *(__int16 *)(CurrentTaskPtr + 10) < 0;
      LODWORD(v4) = *(__int16 *)(CurrentTaskPtr + 12) < 0;
      if ( v4 )
      {
        *(_WORD *)(CurrentTaskPtr + 10) = IEntity::X(this);
        *(_WORD *)(CurrentTaskPtr + 12) = IEntity::Y(this);
      }
    }
    v2 = Y16X16::PackXYFast(*(__int16 *)(CurrentTaskPtr + 10), *(__int16 *)(CurrentTaskPtr + 12));
    (**((void (__thiscall ***)(char *, CCatapult *, int, int))this + 45))((char *)this + 180, this, v2, 0x100000);
  }
  return (*(int (__thiscall **)(CCatapult *))(*(_DWORD *)this + 144))(this);
}


// address=[0x153e320]
// Decompiled from unsigned int __fastcall CCatapult::TakeAmmo(CCatapult *this)

void  CCatapult::TakeAmmo(void) {
  
  unsigned int result; // eax
  char v2; // dl
  int v3; // [esp+0h] [ebp-1Ch]
  unsigned __int8 *v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+14h] [ebp-8h]

  result = (unsigned int)this;
  if ( !*((_BYTE *)this + 204) )
    return result;
  result = *((unsigned __int8 *)this + 111);
  if ( result >= *(_DWORD *)(*((_DWORD *)this + 25) + 84) )
    return result;
  result = CCatapult::SearchForAmmo(this);
  if ( !result )
    return result;
  v4 = CPileMgr::operator[](result);
  v3 = CPile::NumberOfAvailableGoods((CPile *)v4);
  v6 = v3 * (*(int (__thiscall **)(CCatapult *))(*(_DWORD *)this + 228))(this);
  v5 = *(_DWORD *)(*((_DWORD *)this + 25) + 84) - *((unsigned __int8 *)this + 111);
  v7 = v6 / (*(int (__thiscall **)(CCatapult *))(*(_DWORD *)this + 228))(this);
  if ( v6 > v5 )
    v7 = v5 / (*(int (__thiscall **)(CCatapult *))(*(_DWORD *)this + 228))(this);
  CPile::DecreaseUnforeseen((CPile *)v4, v7);
  v2 = v7 * (*(int (__thiscall **)(CCatapult *))(*(_DWORD *)this + 228))(this) + *((_BYTE *)this + 111);
  result = (unsigned int)this;
  *((_BYTE *)this + 111) = v2;
  return result;
}


// address=[0x153e420]
// Decompiled from int __thiscall CCatapult::SearchForAmmo(CCatapult *this)

int  CCatapult::SearchForAmmo(void) {
  
  int v2; // [esp+0h] [ebp-2Ch]
  int v3; // [esp+4h] [ebp-28h]
  int v4; // [esp+8h] [ebp-24h]
  int v5; // [esp+Ch] [ebp-20h]
  int v6; // [esp+10h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-18h]
  int v8; // [esp+18h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *v10; // [esp+20h] [ebp-Ch]
  int i; // [esp+28h] [ebp-4h]

  if ( IEntity::Race(this) == 1 )
    return 0;
  v3 = *(_DWORD *)(*((_DWORD *)this + 25) + 80);
  v6 = IEntity::X(this);
  v5 = IEntity::Y(this);
  for ( i = 0; i < 91; ++i )
  {
    v7 = v6 + SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    v8 = v5 + SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
    if ( (unsigned __int8)CWorldManager::InWorld(v7, v8) )
    {
      v4 = CWorldManager::Index(v7, v8);
      v9 = CWorldManager::PileId(v4);
      if ( v9 )
      {
        v10 = CPileMgr::operator[](v9);
        if ( (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v10 + 60))(v10, v2) == v3 )
        {
          v2 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v10 + 40))(v10);
          if ( v2 > 0 )
            return v9;
        }
      }
    }
  }
  return 0;
}


// address=[0x153e530]
// Decompiled from int __thiscall CCatapult::GetAmmoDisplayID(CCatapult *this)

int  CCatapult::GetAmmoDisplayID(void) {
  
  int v2; // eax
  int v3; // [esp+4h] [ebp-18h]
  unsigned int CurrentManaAmount; // [esp+8h] [ebp-14h]
  unsigned int v5; // [esp+Ch] [ebp-10h]
  signed int v7; // [esp+14h] [ebp-8h]
  signed int v8; // [esp+18h] [ebp-4h]

  if ( !*((_DWORD *)this + 25)
    && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 201, "m_pVehicleProperties!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 25) )
    return 0;
  if ( IEntity::Race(this) == 1 )
  {
    if ( CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost) <= 0 )
      v3 = 1;
    else
      v3 = CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost);
    v2 = IEntity::OwnerId((unsigned __int8 *)this);
    CurrentManaAmount = CMagic::GetCurrentManaAmount(v2);
    v5 = 40 * v3;
    if ( !(40 * v3) && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 217, "iMaxAmmo != 0") == 1 )
      __debugbreak();
    if ( v5 )
    {
      if ( CurrentManaAmount > v5 )
        CurrentManaAmount = 40 * v3;
      v7 = 4 - 4 * CurrentManaAmount / v5;
      if ( (unsigned int)v7 > 4
        && BBSupportDbgReport(
             2,
             "MapObjects\\Catapult\\Catapult.cpp",
             223,
             "iIndex>=0 && iIndex<=MAX_AMMO_DISPLAY_INDEX") == 1 )
      {
        __debugbreak();
      }
      if ( v7 >= 0 )
      {
        if ( v7 > 4 )
          v7 = 4;
      }
      else
      {
        v7 = 0;
      }
      return dword_3D8B840[v7];
    }
    else
    {
      return dword_3D8B840[0];
    }
  }
  else
  {
    v8 = 4 - 4 * (unsigned int)*((unsigned __int8 *)this + 111) / *(_DWORD *)(*((_DWORD *)this + 25) + 84);
    if ( (unsigned int)v8 > 4
      && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 207, "iIndex>=0 && iIndex<=MAX_AMMO_DISPLAY_INDEX") == 1 )
    {
      __debugbreak();
    }
    if ( v8 >= 0 )
    {
      if ( v8 > 4 )
        v8 = 4;
    }
    else
    {
      v8 = 0;
    }
    return dword_3D8B840[v8];
  }
}


// address=[0x153e700]
// Decompiled from int __thiscall CCatapult::GetHealthDisplayID(CCatapult *this)

int  CCatapult::GetHealthDisplayID(void) {
  
  signed int v2; // [esp+0h] [ebp-8h]

  if ( !*((_DWORD *)this + 25)
    && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 236, "m_pVehicleProperties!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 25) )
    return 0;
  if ( !*(_DWORD *)(*((_DWORD *)this + 25) + 48)
    && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 239, "m_pVehicleProperties->m_uHitpoints!=0") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_DWORD *)(*((_DWORD *)this + 25) + 48) )
    return 0;
  v2 = 7
     - (unsigned int)(7 * (*(int (__thiscall **)(CCatapult *))(*(_DWORD *)this + 40))(this))
     / *(_DWORD *)(*((_DWORD *)this + 25) + 48);
  if ( (unsigned int)v2 >= 8
    && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 243, "iIndex>=0 && iIndex<=MAX_HEALTH_DISPLAY_INDEX") == 1 )
  {
    __debugbreak();
  }
  if ( v2 >= 0 )
  {
    if ( v2 > 7 )
      v2 = 7;
  }
  else
  {
    v2 = 0;
  }
  return dword_3D8B854[v2];
}


// address=[0x153e800]
// Decompiled from char __thiscall CCatapult::AttackTargetAt(CCatapult *this, int a2, int a3)

bool  CCatapult::AttackTargetAt(int,int) {
  
  const struct IEntity *v4; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int i; // [esp+18h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Catapult\\Catapult.cpp", 676, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v5 = CSpiralOffsets::Last(2);
  for ( i = 0; i <= v5; ++i )
  {
    v6 = a2 + CSpiralOffsets::DeltaX(i);
    v7 = a3 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v6, v7) )
    {
      v8 = CWorldManager::MapObjectId(v6, v7);
      if ( v8 )
      {
        v4 = CMapObjectMgr::Entity(v8);
        if ( CWarriorBehavior::IsValidTarget((CCatapult *)((char *)this + 180), this, v4) )
        {
          (**((void (__thiscall ***)(char *, CCatapult *, int, int *))this + 45))(
            (char *)this + 180,
            this,
            v8,
            &dword_6FC800[3584]);
          return 1;
        }
      }
    }
  }
  return 0;
}


// address=[0x153e920]
// Decompiled from int __thiscall CCatapult::RequestDonkey(CCatapult *this)

int  CCatapult::RequestDonkey(void) {
  
  int v1; // eax
  unsigned int v3; // esi
  int v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // [esp-14h] [ebp-68h]
  int v12; // [esp-10h] [ebp-64h]
  int v13; // [esp-Ch] [ebp-60h]
  int v14; // [esp-Ch] [ebp-60h]
  int v15; // [esp-8h] [ebp-5Ch]
  int v16; // [esp-8h] [ebp-5Ch]
  int v17; // [esp-4h] [ebp-58h]
  int v18; // [esp-4h] [ebp-58h]
  int v19; // [esp+0h] [ebp-54h]
  _BYTE v20[24]; // [esp+Ch] [ebp-48h] BYREF
  CEntityEvent *v21; // [esp+24h] [ebp-30h]
  CEntityEvent *v22; // [esp+28h] [ebp-2Ch]
  int v23; // [esp+2Ch] [ebp-28h]
  int NearestPileIDOfferGood; // [esp+30h] [ebp-24h]
  int v25; // [esp+34h] [ebp-20h]
  int v26; // [esp+38h] [ebp-1Ch] BYREF
  unsigned __int8 *VehicleCargoLoader; // [esp+3Ch] [ebp-18h]
  unsigned __int8 *v28; // [esp+40h] [ebp-14h]
  unsigned __int8 *v29; // [esp+44h] [ebp-10h]
  int v30; // [esp+50h] [ebp-4h]

  v29 = (unsigned __int8 *)this;
  v17 = *(_DWORD *)(*((_DWORD *)this + 25) + 80);
  v15 = IEntity::Y(this);
  v13 = IEntity::X(v29);
  v1 = IEntity::OwnerId(v29);
  NearestPileIDOfferGood = CEcoSectorMgr::GetNearestPileIDOfferGood((CEcoSectorMgr *)g_cESMgr, v1, v13, v15, v17);
  if ( NearestPileIDOfferGood <= 0 )
    return 0;
  v28 = CPileMgr::operator[](NearestPileIDOfferGood);
  v3 = *(_DWORD *)(*((_DWORD *)v29 + 25) + 84) - v29[111];
  v4 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v28 + 40))(v28);
  if ( v3 >= (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v29 + 228))(v29) * v4 )
  {
    v5 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v28 + 40))(v28);
    v23 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v29 + 228))(v29) * v5;
  }
  else
  {
    v23 = *(_DWORD *)(*((_DWORD *)v29 + 25) + 84) - v29[111];
  }
  v25 = v23;
  v26 = 0;
  v16 = IEntity::Y(v29);
  v14 = IEntity::X(v29);
  v12 = IEntity::Y(v28);
  v11 = IEntity::X(v28);
  v6 = IEntity::OwnerId(v29);
  VehicleCargoLoader = CTransportMgr::GetVehicleCargoLoader(4, v6, v11, v12, v14, v16, &v26);
  v7 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v29 + 228))(v29);
  v26 *= v7;
  if ( v26 < v23 )
    v25 = v26;
  if ( !VehicleCargoLoader || v25 <= 0 )
    return 0;
  if ( IEntity::Type((unsigned __int16 *)VehicleCargoLoader) == 1 )
  {
    v8 = IEntity::ID();
    CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v28, v8, 1, 2);
    v9 = IEntity::ID();
    (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v29 + 164))(v29, v9);
  }
  v18 = IEntity::ID();
  v10 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v29 + 228))(v29, NearestPileIDOfferGood);
  v22 = CEntityEvent::CEntityEvent((CEntityEvent *)v20, 0xBu, 0, v25 / v10, v18, v19);
  v21 = v22;
  v30 = 0;
  (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)VehicleCargoLoader + 80))(
    VehicleCargoLoader,
    v22);
  v30 = -1;
  CEntityEvent::~CEntityEvent(v20);
  return IEntity::ID();
}


// address=[0x153fce0]
// Decompiled from // MFC 3.1-14.0 32bit
int __thiscall CCatapult::AmmoPerPile(CCatapult *this)

int const  CCatapult::AmmoPerPile(void) {
  
  return 4;
}


// address=[0x379bc1c]
// [Decompilation failed for static int const CCatapult::AMMO_SCAN_RANGE]

// address=[0x379bc64]
// [Decompilation failed for static int const CCatapult::MAX_AMMO_FOR_VIKINKS]

