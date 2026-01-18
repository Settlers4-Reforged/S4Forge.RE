#include "CWarShip.h"

// Definitions for class CWarShip

// address=[0x14028e0]
// Decompiled from int __cdecl CWarShip::New(int a1)
class CPersistence * __cdecl CWarShip::New(std::istream & a1) {
  
  if ( CWarShip::operator new(0xC8u) )
    return CWarShip::CWarShip(a1);
  else
    return 0;
}


// address=[0x15a09e0]
// Decompiled from int __thiscall CWarShip::WarriorTaskWalkOneStep(CWarShip *this, struct IMovingEntity *a2)
int  CWarShip::WarriorTaskWalkOneStep(class IMovingEntity & a2) {
  
  int v2; // eax
  int v3; // eax
  struct CWalking *v5; // [esp+0h] [ebp-8h]

  v5 = IMovingEntity::Walking((CWarShip *)((char *)this - 172));
  v2 = IEntity::PackedXY((char *)this - 172);
  v3 = (*(int (__thiscall **)(struct CWalking *, int))(*(_DWORD *)v5 + 12))(v5, v2);
  CVehicle::WalkDirAndRegister((CWarShip *)((char *)this - 172), v3, 0);
  return *((unsigned __int8 *)this - 68);
}


// address=[0x15a0a40]
// Decompiled from int __thiscall CWarShip::WarriorTaskAttack(char *this, int a2, int a3, int a4)
void  CWarShip::WarriorTaskAttack(class IMovingEntity & a2, int a3, enum T_WARRIOR_ATTACK a4) {
  
  int v4; // eax

  CVehicle::AttackTarget((CVehicle *)(this - 172), a3);
  CVehicle::TakeJobPart((CVehicle *)(this - 172), 1u);
  v4 = CVehicle::TurnCounter((CVehicle *)(this - 172));
  return CVehicle::RegisterNewTask((CVehicle *)(this - 172), 16, (unsigned __int8)*(this - 63) + v4);
}


// address=[0x15a0aa0]
// Decompiled from int __thiscall CWarShip::WarriorTaskFinished(CWarShip *this, struct IMovingEntity *a2)
void  CWarShip::WarriorTaskFinished(class IMovingEntity & a2) {
  
  return CVehicle::GetNextJob((CWarShip *)((char *)this - 172));
}


// address=[0x15a0ac0]
// Decompiled from int __thiscall CWarShip::WarriorTaskIdleWalk(CWarShip *this, struct IMovingEntity *a2)
int  CWarShip::WarriorTaskIdleWalk(class IMovingEntity & a2) {
  
  int v2; // eax
  int v3; // eax
  struct CWalking *v5; // [esp+0h] [ebp-8h]

  v5 = IMovingEntity::Walking((CWarShip *)((char *)this - 172));
  v2 = IEntity::PackedXY((char *)this - 172);
  v3 = (*(int (__thiscall **)(struct CWalking *, int, _DWORD))(*(_DWORD *)v5 + 16))(v5, v2, 0);
  CVehicle::WalkDirAndRegister((CWarShip *)((char *)this - 172), v3, 0);
  return *((unsigned __int8 *)this - 68);
}


// address=[0x15a0b20]
// Decompiled from unsigned int __cdecl CWarShip::operator new(unsigned int a1)
void * __cdecl CWarShip::operator new(unsigned int a1) {
  
  return CVehicleMgr::Alloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x15a0b40]
// Decompiled from void __cdecl CWarShip::operator delete(void *a1)
void __cdecl CWarShip::operator delete(void * a1) {
  
  CVehicleMgr::Dealloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x15a0b80]
// Decompiled from void __thiscall CWarShip::ConvertEventIntoGoal(CWarShip *this, struct CEntityEvent *a2)
void  CWarShip::ConvertEventIntoGoal(class CEntityEvent * a2) {
  
  int v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+4h] [ebp-10h]
  int v5; // [esp+10h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Ship\\WarShip.cpp", 164, "_pEvent!=NULL") == 1 )
    __debugbreak();
  if ( !a2
    || *((_DWORD *)a2 + 1) != 17
    || *((_DWORD *)a2 + 2) != 13
    || (v5 = *((_DWORD *)a2 + 4),
        v2 = Y16X16::UnpackXFast(v5),
        v3 = Y16X16::UnpackYFast(v5),
        !CWarShip::AttackTargetAt(this, v2, v3)) )
  {
    CVehicle::ConvertEventIntoGoal(this, a2);
  }
}


// address=[0x15a0c30]
// Decompiled from struct IMovingEntity *__thiscall CWarShip::CWarShip(struct IMovingEntity *this, int a2)
 CWarShip::CWarShip(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-20h] BYREF
  int v4; // [esp+Ch] [ebp-1Ch] BYREF
  int v5; // [esp+10h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+14h] [ebp-14h] BYREF
  struct IMovingEntity *v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  v7 = this;
  CShip::CShip(a2);
  v8 = 0;
  CWarriorBehavior::CWarriorBehavior((struct IMovingEntity *)((char *)v7 + 172));
  *(_DWORD *)v7 = &CWarShip::_vftable_;
  *((_DWORD *)v7 + 43) = &CWarShip::`vftable';
  operator^<unsigned int>(a2, &v3);
  v4 = 0;
  v5 = 0;
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CWarShip");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, (char *)v7 + 196);
  operator^<int>(a2, (int)&v4);
  operator^<int>(a2, (int)&v5);
  CWarriorBehavior::WarriorInit((struct IMovingEntity *)((char *)v7 + 172), v7, v4, v5);
  v8 = -1;
  return v7;
}


// address=[0x15a0d60]
// Decompiled from int __thiscall CWarShip::Store(char *this, struct std::ostream *a2)
void  CWarShip::Store(std::ostream & a2) {
  
  struct CWarriorBehavior::SWarriorBehaviorData *WarriorBehaviorData; // eax
  struct CWarriorBehavior::SWarriorBehaviorData *v3; // eax
  int v5; // [esp+0h] [ebp-8h] BYREF
  char *v6; // [esp+4h] [ebp-4h]

  v6 = this;
  CShip::Store(a2);
  v5 = 1;
  operator^<unsigned int>(a2, &v5);
  operator^<bool>((int)a2, (int)(v6 + 196));
  WarriorBehaviorData = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v6 + 172));
  operator^<int>((int)a2, (int *)WarriorBehaviorData + 2);
  v3 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v6 + 172));
  return operator^<unsigned int>(a2, (int *)v3 + 3);
}


// address=[0x15a2720]
// Decompiled from int __thiscall CWarShip::ClassID(CWarShip *this)
unsigned long  CWarShip::ClassID(void)const {
  
  return CWarShip::m_iClassID;
}


// address=[0x3d8bfe0]
// [Decompilation failed for static unsigned long CWarShip::m_iClassID]

// address=[0x15a0df0]
// Decompiled from CWarShip *__thiscall CWarShip::CWarShip(CWarShip *this, int a2, int a3, int a4, int a5, int a6, int a7, bool a8)
 CWarShip::CWarShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8) {
  
  CShip::CShip(this, a2, a3, a4, a5, a6, a7, a8);
  CWarriorBehavior::CWarriorBehavior((CWarShip *)((char *)this + 172));
  *(_DWORD *)this = &CWarShip::_vftable_;
  *((_DWORD *)this + 43) = &CWarShip::`vftable';
  *((_BYTE *)this + 196) = 1;
  if ( *(_DWORD *)(*((_DWORD *)this + 25) + 16) != 10
    && BBSupportDbgReport(
         2,
         "MapObjects\\Ship\\WarShip.cpp",
         79,
         "m_pVehicleProperties->m_tWarriorType == WARRIOR_TYPE_SHIP_WAR") == 1 )
  {
    __debugbreak();
  }
  CWarriorBehavior::WarriorInit((CWarShip *)((char *)this + 172), this, -1, 0);
  return this;
}


// address=[0x15a0ed0]
// Decompiled from void __thiscall CWarShip::~CWarShip(CWarShip *this)
 CWarShip::~CWarShip(void) {
  
  *(_DWORD *)this = &CWarShip::_vftable_;
  *((_DWORD *)this + 43) = &CWarShip::`vftable';
  CShip::~CShip(this);
}


// address=[0x15a0f00]
// Decompiled from void __thiscall CWarShip::VehicleLogicUpdate(CWarShip *this)
void  CWarShip::VehicleLogicUpdate(void) {
  
  int v1; // [esp+4h] [ebp-18h]
  int v2; // [esp+8h] [ebp-14h]
  BOOL v3; // [esp+Ch] [ebp-10h]
  unsigned int TickCounter; // [esp+10h] [ebp-Ch]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v3 = !CVehicle::ReadyToFire(this, TickCounter);
  if ( (*(unsigned __int8 (__thiscall **)(CWarShip *))(*(_DWORD *)this + 204))(this) )
    v2 = 0;
  else
    v2 = 2;
  if ( CShip::FULL_UPDATE_DELAY + *((_DWORD *)this + 42) < TickCounter )
  {
    CWarShip::TakeAmmo(this);
    v1 = CShip::RepairBuildingInRange(this);
    if ( v1 )
      CShip::RepairAt(this, v1);
    *((_DWORD *)this + 42) = TickCounter;
  }
  CWarriorBehavior::WarriorVehicleLogicUpdate((CWarShip *)((char *)this + 172), this, TickCounter, v2 | v3);
}


// address=[0x15a0fe0]
// Decompiled from struct CVehicle *__thiscall CWarShip::TakeJob(CWarShip *this)
void  CWarShip::TakeJob(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  __int64 v5; // [esp+0h] [ebp-14h]
  int CurrentTaskPtr; // [esp+Ch] [ebp-8h]

  CVehicle::InitCommonTaskValues(this, 0);
  CurrentTaskPtr = CVehicle::GetCurrentTaskPtr(this);
  if ( CurrentTaskPtr )
  {
    switch ( *(_BYTE *)(CurrentTaskPtr + 4) )
    {
      case 6:
        v1 = Y16X16::PackXYFast(*(__int16 *)(CurrentTaskPtr + 10), *(__int16 *)(CurrentTaskPtr + 12));
        (**((void (__thiscall ***)(char *, CWarShip *, int, int))this + 43))((char *)this + 172, this, v1, 0x200000);
        return (struct CVehicle *)(*(int (__thiscall **)(CWarShip *))(*(_DWORD *)this + 144))(this);
      case 7:
        goto LABEL_7;
      case 8:
        HIDWORD(v5) = *(__int16 *)(CurrentTaskPtr + 10) < 0;
        LODWORD(v5) = *(__int16 *)(CurrentTaskPtr + 12) < 0;
        if ( v5 )
        {
          *(_WORD *)(CurrentTaskPtr + 10) = IEntity::X(this);
          *(_WORD *)(CurrentTaskPtr + 12) = IEntity::Y(this);
        }
LABEL_7:
        v2 = Y16X16::PackXYFast(*(__int16 *)(CurrentTaskPtr + 10), *(__int16 *)(CurrentTaskPtr + 12));
        (**((void (__thiscall ***)(char *, CWarShip *, int, int))this + 43))((char *)this + 172, this, v2, 0x100000);
        return (struct CVehicle *)(*(int (__thiscall **)(CWarShip *))(*(_DWORD *)this + 144))(this);
      case 0xA:
        (**((void (__thiscall ***)(char *, CWarShip *, _DWORD, int *))this + 43))(
          (char *)this + 172,
          this,
          *(unsigned __int16 *)(CurrentTaskPtr + 16),
          dword_600000);
        return (struct CVehicle *)(*(int (__thiscall **)(CWarShip *))(*(_DWORD *)this + 144))(this);
      case 0x24:
        IEntity::ClearFlagBits(this, Visible);
        v3 = IEntity::EntityId((unsigned __int16 *)this);
        return CVehicleMgr::DeleteVehicle((CVehicleMgr *)&g_cVehicleMgr, v3);
      default:
        if ( BBSupportDbgReport(1, "MapObjects\\Ship\\WarShip.cpp", 335, "CWarShip::TakeJob(): Invalid task!") == 1 )
          __debugbreak();
        break;
    }
  }
  (**((void (__thiscall ***)(char *, CWarShip *, int, _DWORD))this + 43))((char *)this + 172, this, -1, 0);
  return (struct CVehicle *)(*(int (__thiscall **)(CWarShip *))(*(_DWORD *)this + 144))(this);
}


// address=[0x15a1240]
// Decompiled from void *__thiscall CWarShip::GetGfxInfos(CWarShip *this)
struct SGfxObjectInfo *  CWarShip::GetGfxInfos(void) {
  
  CShip::GetGfxInfos((int)this);
  if ( !IEntity::FlagBits(this, Selected) )
    return &IEntity::m_sGfxInfo;
  byte_40FE264 = CShip::GetHealthDisplayID(this);
  byte_40FE265 = CWarShip::GetAmmoDisplayID(this);
  return &IEntity::m_sGfxInfo;
}


// address=[0x15a1290]
// Decompiled from int __thiscall CWarShip::GetAmmoDisplayID(CWarShip *this)
int  CWarShip::GetAmmoDisplayID(void) {
  
  int v2; // eax
  int v3; // [esp+4h] [ebp-18h]
  unsigned int CurrentManaAmount; // [esp+8h] [ebp-14h]
  unsigned int v5; // [esp+Ch] [ebp-10h]
  signed int v7; // [esp+14h] [ebp-8h]
  signed int v8; // [esp+18h] [ebp-4h]

  if ( !*((_DWORD *)this + 25)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\WarShip.cpp", 192, "m_pVehicleProperties!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 25) )
    return 0;
  if ( IEntity::Race(this) != 1 )
  {
    v8 = 4 - 4 * (unsigned int)*((unsigned __int8 *)this + 111) / *(_DWORD *)(*((_DWORD *)this + 25) + 84);
    if ( (unsigned int)v8 > 4
      && BBSupportDbgReport(2, "MapObjects\\Ship\\WarShip.cpp", 198, "iIndex>=0 && iIndex<=MAX_AMMO_DISPLAY_INDEX") == 1 )
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
    return dword_3D8BFF4[v8];
  }
  if ( CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost) <= 0 )
    v3 = 1;
  else
    v3 = CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost);
  v2 = IEntity::OwnerId((unsigned __int8 *)this);
  CurrentManaAmount = CMagic::GetCurrentManaAmount(v2);
  v5 = 40 * v3;
  if ( !(40 * v3) && BBSupportDbgReport(2, "MapObjects\\Ship\\WarShip.cpp", 207, "iMaxAmmo != 0") == 1 )
    __debugbreak();
  if ( !v5 )
    return 0;
  if ( CurrentManaAmount > v5 )
    CurrentManaAmount = 40 * v3;
  v7 = 4 - 4 * CurrentManaAmount / v5;
  if ( (unsigned int)v7 > 4
    && BBSupportDbgReport(2, "MapObjects\\Ship\\WarShip.cpp", 213, "iIndex>=0 && iIndex<=MAX_AMMO_DISPLAY_INDEX") == 1 )
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
  return dword_3D8BFF4[v7];
}


// address=[0x15a1450]
// Decompiled from char __thiscall CWarShip::AttackTargetAt(CWarShip *this, int a2, int a3)
bool  CWarShip::AttackTargetAt(int a2, int a3) {
  
  const struct IEntity *v4; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int i; // [esp+18h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\WarShip.cpp", 411, "g_cWorld.InWorld(_iX, _iY)") == 1 )
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
        if ( CWarriorBehavior::IsValidTarget((CWarShip *)((char *)this + 172), this, v4) )
        {
          (**((void (__thiscall ***)(char *, CWarShip *, int, int *))this + 43))(
            (char *)this + 172,
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


// address=[0x15a1570]
// Decompiled from unsigned int __fastcall CWarShip::TakeAmmo(CWarShip *this)
void  CWarShip::TakeAmmo(void) {
  
  unsigned int result; // eax
  int v2; // esi
  int v3; // eax
  unsigned __int8 *v4; // [esp+8h] [ebp-18h]
  int v5; // [esp+Ch] [ebp-14h]
  int v6; // [esp+14h] [ebp-Ch]

  result = (unsigned int)this;
  if ( !*((_BYTE *)this + 196) )
    return result;
  result = *((unsigned __int8 *)this + 111);
  if ( result >= *(_DWORD *)(*((_DWORD *)this + 25) + 84) )
    return result;
  result = CWarShip::SearchForAmmo(this);
  if ( !result )
    return result;
  v4 = CPileMgr::operator[](result);
  v2 = CPile::NumberOfAvailableGoods((CPile *)v4);
  v6 = (*(int (__thiscall **)(CWarShip *))(*(_DWORD *)this + 220))(this) * v2;
  if ( v6 >= *(_DWORD *)(*((_DWORD *)this + 25) + 84) - *((unsigned __int8 *)this + 111) )
    v5 = *(_DWORD *)(*((_DWORD *)this + 25) + 84) - *((unsigned __int8 *)this + 111);
  else
    v5 = v6;
  v3 = (*(int (__thiscall **)(CWarShip *))(*(_DWORD *)this + 220))(this);
  CPile::DecreaseUnforeseen((CPile *)v4, v5 / v3);
  result = v5 + *((unsigned __int8 *)this + 111);
  *((_BYTE *)this + 111) = result;
  return result;
}


// address=[0x15a1650]
// Decompiled from int __thiscall CWarShip::SearchForAmmo(CWarShip *this)
int  CWarShip::SearchForAmmo(void) {
  
  void **v1; // eax
  int v3; // [esp+0h] [ebp-13Ch]
  int v4; // [esp+4h] [ebp-138h]
  int v5; // [esp+8h] [ebp-134h]
  int v6; // [esp+Ch] [ebp-130h]
  int v7; // [esp+10h] [ebp-12Ch]
  int v8; // [esp+14h] [ebp-128h]
  int PileIdWithGood; // [esp+18h] [ebp-124h]
  int v10; // [esp+1Ch] [ebp-120h]
  int v11; // [esp+20h] [ebp-11Ch]
  int v12; // [esp+24h] [ebp-118h]
  int v13; // [esp+28h] [ebp-114h]
  int v14; // [esp+2Ch] [ebp-110h]
  int v15; // [esp+30h] [ebp-10Ch]
  struct CPile *PilePtr; // [esp+34h] [ebp-108h]
  unsigned __int16 *v17; // [esp+38h] [ebp-104h]
  _BYTE v19[248]; // [esp+40h] [ebp-FCh] BYREF

  v8 = 0;
  v10 = 0x4000;
  if ( IEntity::Race(this) == 1 )
    return v8;
  v14 = *(_DWORD *)(*((_DWORD *)this + 25) + 80);
  v12 = IEntity::X(this);
  v13 = IEntity::Y(this);
  v5 = IEntity::Race(this);
  CFindBuildings::CFindBuildings((CFindBuildings *)v19, v12, v13, 20);
  while ( CFindBuildings::NextBuilding((CFindBuildings *)v19) )
  {
    v17 = (unsigned __int16 *)CFindBuildings::BuildingPtr((CFindBuildings *)v19);
    v7 = IEntity::Type(v17);
    v6 = IEntity::Race(v17);
    if ( v7 == 31 && v6 == v5 )
    {
      v1 = (void **)CBuilding::Role(v17);
      v15 = j____RTDynamicCast(
              v1,
              0,
              &IBuildingRole__RTTI_Type_Descriptor_,
              &CWorkshopBuildingRole__RTTI_Type_Descriptor_,
              0);
      if ( v15 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v15 + 60))(v15, v14) )
        {
          PileIdWithGood = CBuilding::GetPileIdWithGood((CBuilding *)v17, v14);
          PilePtr = CPileMgr::GetPilePtr(PileIdWithGood);
          if ( PilePtr )
          {
            if ( CPile::NumberOfAvailableGoods(PilePtr) > 0 )
            {
              v3 = IEntity::X(PilePtr);
              v4 = IEntity::Y(PilePtr);
              v11 = Grid::Distance((Grid *)(v3 - v12), v4 - v13);
              if ( v11 < v10 )
              {
                v10 = v11;
                v8 = PileIdWithGood;
              }
            }
          }
        }
      }
    }
  }
  return v8;
}


// address=[0x15a2680]
// Decompiled from int __thiscall CWarShip::AmmoPerPile(CWarShip *this)
int const  CWarShip::AmmoPerPile(void) {
  
  return 4;
}


// address=[0x37bdf08]
// [Decompilation failed for static int const CWarShip::AMMO_SCAN_RANGE]

