#include "CHunterRole.h"

// Definitions for class CHunterRole

// address=[0x1400f40]
// Decompiled from int __cdecl CHunterRole::New(int a1)
class CPersistence * __cdecl CHunterRole::New(std::istream & a1) {
  
  if ( operator new(0x30u) )
    return CHunterRole::CHunterRole(a1);
  else
    return 0;
}


// address=[0x1577280]
// Decompiled from int __thiscall CHunterRole::InitWalking(CHunterRole *this, struct CSettler *a2)
class CWalking *  CHunterRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(1, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x15772c0]
// Decompiled from void __thiscall CHunterRole::LogicUpdateJob(CHunterRole *this, struct CSettler *a2)
void  CHunterRole::LogicUpdateJob(class CSettler * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // esi
  CBuilding *v7; // eax
  unsigned __int8 *v8; // eax
  Y16X16 *v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // [esp-4h] [ebp-3Ch]
  int v16; // [esp-4h] [ebp-3Ch]
  int v17; // [esp-4h] [ebp-3Ch]
  int v18; // [esp-4h] [ebp-3Ch]
  int v19; // [esp-4h] [ebp-3Ch]
  int v20; // [esp-4h] [ebp-3Ch]
  int v21; // [esp-4h] [ebp-3Ch]
  int v22; // [esp+4h] [ebp-34h]
  int PileIdWithGood; // [esp+8h] [ebp-30h]
  Grid *v24; // [esp+10h] [ebp-28h]
  int v25; // [esp+14h] [ebp-24h]
  int v26; // [esp+18h] [ebp-20h]
  int v27; // [esp+1Ch] [ebp-1Ch]
  int v28; // [esp+20h] [ebp-18h]
  int v29; // [esp+24h] [ebp-14h]
  struct CAnimal *AnimalPtr; // [esp+2Ch] [ebp-Ch]
  int VictimPosition; // [esp+30h] [ebp-8h]

  if ( (*(unsigned __int8 (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2) )
  {
    switch ( *((_BYTE *)this + 4) )
    {
      case 6:
        if ( CHunterRole::AreWeChasing(this, a2) )
        {
          VictimPosition = CHunterRole::GetVictimPosition(this);
          if ( !VictimPosition )
            goto LABEL_5;
          v15 = Y16X16::UnpackYFast(VictimPosition);
          v2 = Y16X16::UnpackXFast(VictimPosition);
          v3 = CWorldManager::EcoSectorId(v2, v15);
          v16 = IEntity::Y(a2);
          v4 = IEntity::X(a2);
          if ( v3 != CWorldManager::EcoSectorId(v4, v16) )
          {
            CTrace::Print("HunterRole: Animal went out of our economy sector. Going home!");
            CHunterRole::GoHomeEmpty(this, a2);
            return;
          }
          v5 = IEntity::X(a2);
          v24 = (Grid *)(v5 - Y16X16::UnpackXFast(VictimPosition));
          v6 = IEntity::Y(a2);
          v25 = v6 - Y16X16::UnpackYFast(VictimPosition);
          if ( (int)Grid::Distance(v24, v25) < 12 )
            goto LABEL_9;
          if ( *((_DWORD *)this + 6) != VictimPosition )
          {
            ISettlerRole::NewDestination(this, a2, VictimPosition, 0);
            IMovingEntity::WalkToXY(a2, VictimPosition, 0);
          }
        }
        IMovingEntity::SetDistance(a2, 0);
        (*(void (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0xD:
        if ( !*((_WORD *)this + 17)
          && BBSupportDbgReport(2, "MapObjects\\Settler\\HunterRole.cpp", 294, "m_uEntityId != 0") == 1 )
        {
          __debugbreak();
        }
        v27 = CHunterRole::GetVictimPosition(this);
        if ( !v27 )
          goto LABEL_5;
        v9 = (Y16X16 *)IEntity::PackedXY(a2);
        v22 = Y16X16::DirectionFast(v9, v27);
        IMovingEntity::SetDirection(a2, v22);
        v28 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
        if ( !v28 && BBSupportDbgReport(2, "MapObjects\\Settler\\HunterRole.cpp", 309, "pSupplier != 0") == 1 )
          __debugbreak();
        *((_BYTE *)this + 44) = (*(int (__thiscall **)(int))(*(_DWORD *)v28 + 60))(v28);
        if ( !*((_BYTE *)this + 44) && BBSupportDbgReport(2, "MapObjects\\Settler\\HunterRole.cpp", 311, "m_uGood") == 1 )
          __debugbreak();
        if ( *((_BYTE *)this + 44) )
        {
          v26 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v26 + 36))(v26, 1);
          v10 = (_DWORD *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
          IEntity::ClearFlagBits(v10, EntityFlag_Visible);
          v18 = *((unsigned __int16 *)this + 17);
          v11 = IEntity::ID();
          CTrace::Print("HunterRole: Hunter %d took animal entity %d", v11, v18);
          *((_WORD *)this + 17) = 0;
          (*(void (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
LABEL_5:
          CHunterRole::GoHomeEmpty(this, a2);
        }
        break;
      case 0x10:
        return;
      case 0x15:
        v29 = *((unsigned __int8 *)this + 7) / 2;
        *((_BYTE *)this + 6) -= v29;
        if ( *((char *)this + 6) < v29 )
        {
LABEL_9:
          (*(void (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
          v17 = *((unsigned __int8 *)this + 44);
          v7 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
          PileIdWithGood = CBuilding::GetPileIdWithGood(v7, v17);
          v8 = CPileMgr::operator[](PileIdWithGood);
          CPile::IncreaseUnforeseen((CPile *)v8, 1);
          IAnimatedEntity::RegisterForLogicUpdate(v29 - 1);
        }
        break;
      case 0x1C:
        if ( !*((_WORD *)this + 17)
          && BBSupportDbgReport(2, "MapObjects\\Settler\\HunterRole.cpp", 341, "m_uEntityId") == 1 )
        {
          __debugbreak();
        }
        if ( *((_WORD *)this + 17) )
        {
          AnimalPtr = CAnimalMgr::GetAnimalPtr(*((unsigned __int16 *)this + 17));
          if ( AnimalPtr )
          {
            (*(void (__thiscall **)(struct CAnimal *, int))(*(_DWORD *)AnimalPtr + 32))(AnimalPtr, 1);
            if ( IEntity::FlagBits(AnimalPtr, (EntityFlag)&loc_3000000) )
            {
              v19 = IEntity::ID();
              v12 = IEntity::ID();
              CTrace::Print("HunterRole: Hunter %d missed animal %d. Going home!", v12, v19);
              (*(void (__thiscall **)(CHunterRole *, _DWORD))(*(_DWORD *)this + 52))(this, 0);
              CHunterRole::GoHomeEmpty(this, a2);
            }
            else
            {
              v20 = IEntity::ID();
              v13 = IEntity::ID();
              CTrace::Print("HunterRole: Hunter %d killed animal %d. Harvesting...", v13, v20);
              CHunterRole::HarvestDeadAnimal(this, a2);
            }
          }
          else
          {
            (*(void (__thiscall **)(CHunterRole *, _DWORD))(*(_DWORD *)this + 52))(this, 0);
            CHunterRole::GoHomeEmpty(this, a2);
          }
        }
        break;
      default:
        if ( debug && DEBUG_FLAGS[dword_4152130] )
        {
          v21 = *((char *)this + 4);
          v14 = IEntity::ID();
          BBSupportTracePrintF(0, "LogicUpdateJob Hunter nr %u - unknown task %u", v14, v21);
        }
        break;
    }
  }
}


// address=[0x15777f0]
// Decompiled from int __thiscall CHunterRole::UpdateJob(CHunterRole *this, struct CSettler *a2)
void  CHunterRole::UpdateJob(class CSettler * a2) {
  
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  char v6; // [esp+Ch] [ebp-4h]

  v6 = *((_BYTE *)this + 4);
  if ( v6 != 4 && v6 != 21 )
    return CTrace::Print("HunterJob - Update unknown task");
  v4 = IAnimatedEntity::Frame(a2);
  v3 = *((unsigned __int16 *)this + 4);
  if ( v4 <= v3 )
    return IAnimatedEntity::SetFrame(0);
  else
    return IAnimatedEntity::SetFrame(v4 - v3);
}


// address=[0x1577860]
// Decompiled from int __stdcall CHunterRole::PostLoadInit(CPropertySet *a1)
void  CHunterRole::PostLoadInit(class CSettler * a1) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x1577880]
// Decompiled from char *__thiscall CHunterRole::CHunterRole(char *this, int a2)
 CHunterRole::CHunterRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CHunterRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CHunterRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v5 + 44);
  v6 = -1;
  return v5;
}


// address=[0x1577940]
// Decompiled from int __thiscall CHunterRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CHunterRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned char>(a2, (int)v4 + 44);
}


// address=[0x1578790]
// Decompiled from int __thiscall CHunterRole::ClassID(CHunterRole *this)
unsigned long  CHunterRole::ClassID(void)const {
  
  return CHunterRole::m_iClassID;
}


// address=[0x15787d0]
// Decompiled from int __thiscall CHunterRole::GetSettlerRole(CHunterRole *this)
int  CHunterRole::GetSettlerRole(void)const {
  
  return 8;
}


// address=[0x1588740]
// Decompiled from int __cdecl CHunterRole::Load(int a1)
class CHunterRole * __cdecl CHunterRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CHunterRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bee8]
// [Decompilation failed for static unsigned long CHunterRole::m_iClassID]

// address=[0x1577990]
// Decompiled from ISettlerRole *__thiscall CHunterRole::~CHunterRole(CHunterRole *this)
 CHunterRole::~CHunterRole(void) {
  
  *(_DWORD *)this = &CHunterRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x15779b0]
// Decompiled from int __thiscall CHunterRole::GetNextJob(CHunterRole *this, struct CSettler *a2)
void  CHunterRole::GetNextJob(class CSettler * a2) {
  
  int result; // eax

  IMovingEntity::IncToDoListIter(a2);
  result = IMovingEntity::IsEndIter(a2);
  if ( !(_BYTE)result )
    return (*(int (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
  *((_BYTE *)this + 4) = 17;
  return result;
}


// address=[0x15779f0]
// Decompiled from void __thiscall CHunterRole::TakeJob(CHunterRole *this, struct CSettler *a2)
void  CHunterRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  Y16X16 *v3; // eax
  int v4; // eax
  CMFCToolBarButton *v5; // eax
  int v6; // eax
  CBuilding *v7; // eax
  int v8; // eax
  CBuilding *v9; // eax
  int v10; // [esp-10h] [ebp-2Ch]
  int v11; // [esp-Ch] [ebp-28h]
  int v12; // [esp-4h] [ebp-20h]
  int v13; // [esp-4h] [ebp-20h]
  int v14; // [esp+0h] [ebp-1Ch]
  int PileIdWithGood; // [esp+4h] [ebp-18h]
  int v16; // [esp+8h] [ebp-14h]
  int v17; // [esp+Ch] [ebp-10h]
  int VictimPosition; // [esp+10h] [ebp-Ch]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  switch ( *((_BYTE *)this + 4) )
  {
    case 4:
    case 0x15:
      if ( (*(unsigned __int8 (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2) )
      {
        IMovingEntity::SetDisplacementCosts(10);
        IAnimatedEntity::SetFrame(*((_BYTE *)this + 7) - 1);
        IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6) / 2);
      }
      break;
    case 7:
      IAnimatedEntity::SetFrame(1);
      IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), 0);
      *((_BYTE *)this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 0xA:
      IAnimatedEntity::SetFrame(1);
      IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), 4096);
      *((_BYTE *)this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 0xD:
      if ( (*(unsigned __int8 (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2) )
      {
        IMovingEntity::SetDisplacementCosts(10);
        IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
      }
      break;
    case 0xE:
      if ( (*(unsigned __int8 (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2) )
      {
        IAnimatedEntity::SetFrame(0);
        v5 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
        v6 = CBuilding::DoorPackedXY(v5);
        IMovingEntity::WalkToXY(a2, v6, 0);
        *((_BYTE *)this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      }
      break;
    case 0x10:
      return;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(0);
      IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 0x13:
      if ( (*(unsigned __int8 (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2) )
      {
        v12 = *((unsigned __int8 *)this + 44);
        v7 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
        PileIdWithGood = CBuilding::GetPileIdWithGood(v7, v12);
        v8 = CMapObjectMgr::EntityPtr(PileIdWithGood);
        v14 = IEntity::PackedXY(v8);
        IMovingEntity::WalkToXY(a2, v14, 4096);
        *((_BYTE *)this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      }
      break;
    case 0x18:
      if ( (*(unsigned __int8 (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2) )
      {
        *((_DWORD *)this + 9) = 0;
        *((_DWORD *)this + 10) = 0;
        *((_DWORD *)this + 6) = 0;
        IMovingEntity::SetDisplacementCosts(10);
        v13 = IEntity::ID();
        v9 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
        CBuilding::SettlerEnter(v9, v13);
      }
      break;
    case 0x1C:
      IMovingEntity::SetDisplacementCosts(10);
      if ( debug && DEBUG_FLAGS[dword_4152130] )
        BBSupportTracePrint(0, "LogicUpdateJob WORK");
      VictimPosition = CHunterRole::GetVictimPosition(this);
      if ( VictimPosition )
      {
        v3 = (Y16X16 *)IEntity::PackedXY(a2);
        v16 = Y16X16::DirectionFast(v3, VictimPosition);
        IMovingEntity::SetDirection(a2, v16);
        IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
        v17 = CLogic::Effects((DWORD *)g_pLogic);
        v11 = *((char *)this + 6) - 3;
        v10 = CHunterRole::GetVictimPosition(this);
        v4 = IEntity::PackedXY(a2);
        (*(void (__thiscall **)(int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v17 + 24))(
          v17,
          0,
          v4,
          v10,
          v11,
          0,
          0);
      }
      else
      {
        CHunterRole::GoHomeEmpty(this, a2);
      }
      break;
    default:
      CTrace::Print("HunterJob - TakeJob unknown task");
      break;
  }
}


// address=[0x1577e00]
// Decompiled from int __thiscall CHunterRole::Init(_BYTE *this, CPropertySet *a2)
void  CHunterRole::Init(class CSettler * a2) {
  
  int result; // eax

  result = CWarMap::AddEntity(a2);
  this[44] = 0;
  return result;
}


// address=[0x1577e20]
// Decompiled from int __thiscall CHunterRole::GoHomeEmpty(CHunterRole *this, struct CSettler *a2)
void  CHunterRole::GoHomeEmpty(class CSettler * a2) {
  
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CMFCToolBarButton *v6; // [esp+0h] [ebp-8h]

  result = (*(int (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2);
  if ( !(_BYTE)result )
    return result;
  (*(void (__thiscall **)(CHunterRole *, _DWORD))(*(_DWORD *)this + 52))(this, 0);
  v6 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  v3 = CBuilding::DoorPackedXY(v6);
  ISettlerRole::NewDestination(this, a2, v3, 0);
  v4 = IEntity::Race(a2);
  v5 = CEntityToDoListMgr::SettlerJobList(v4, 77);
  return (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v5, 77);
}


// address=[0x1577eb0]
// Decompiled from void __thiscall CHunterRole::HarvestDeadAnimal(CHunterRole *this, struct CSettler *a2)
void  CHunterRole::HarvestDeadAnimal(class CSettler * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-4h] [ebp-10h]
  int v8; // [esp-4h] [ebp-10h]
  int VictimPosition; // [esp+8h] [ebp-4h]

  VictimPosition = CHunterRole::GetVictimPosition(this);
  if ( VictimPosition
    && (v7 = Y16X16::UnpackYFast(VictimPosition),
        v2 = Y16X16::UnpackXFast(VictimPosition),
        v3 = CWorldManager::EcoSectorId(v2, v7),
        v8 = IEntity::Y(a2),
        v4 = IEntity::X(a2),
        v3 == CWorldManager::EcoSectorId(v4, v8)) )
  {
    ISettlerRole::NewDestination(this, a2, VictimPosition, 0);
    v5 = IEntity::Race(a2);
    v6 = CEntityToDoListMgr::SettlerJobList(v5, 181);
    (*(void (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v6, 181);
  }
  else
  {
    CHunterRole::GoHomeEmpty(this, a2);
  }
}


// address=[0x1577f80]
// Decompiled from bool __thiscall CHunterRole::AreWeChasing(CHunterRole *this, struct CSettler *a2)
bool  CHunterRole::AreWeChasing(class CSettler *) {
  
  struct CAnimal *AnimalPtr; // [esp+0h] [ebp-Ch]

  if ( !*((_WORD *)this + 17) )
    return 0;
  AnimalPtr = CAnimalMgr::GetAnimalPtr(*((unsigned __int16 *)this + 17));
  if ( AnimalPtr )
    return IEntity::FlagBits(AnimalPtr, (EntityFlag)&loc_3000000) != 0;
  CTrace::Print("No more animal in chasing mode! This may not happen! Trace file -> Thomas or Stefan");
  (*(void (__thiscall **)(CHunterRole *, _DWORD))(*(_DWORD *)this + 52))(this, 0);
  CHunterRole::GoHomeEmpty(this, a2);
  return 0;
}


// address=[0x1578010]
// Decompiled from int __thiscall CHunterRole::GetVictimPosition(CHunterRole *this)
int  CHunterRole::GetVictimPosition(void) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-Ch]
  struct CAnimal *AnimalPtr; // [esp+4h] [ebp-4h]

  if ( !*((_WORD *)this + 17) && BBSupportDbgReport(2, "MapObjects\\Settler\\HunterRole.cpp", 871, "m_uEntityId") == 1 )
    __debugbreak();
  AnimalPtr = CAnimalMgr::GetAnimalPtr(*((unsigned __int16 *)this + 17));
  if ( !AnimalPtr )
    return 0;
  v3 = IEntity::Y(AnimalPtr);
  v2 = IEntity::X(AnimalPtr);
  return Y16X16::PackXYFast(v2, v3);
}


// address=[0x1578080]
// Decompiled from int __thiscall CHunterRole::ConvertEventIntoGoal(CHunterRole *this, struct CSettler *a2, struct CEntityEvent *a3)
void  CHunterRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp-8h] [ebp-1Ch]
  int v14; // [esp-8h] [ebp-1Ch]
  int v15; // [esp-8h] [ebp-1Ch]
  int v16; // [esp-4h] [ebp-18h]
  int v17; // [esp-4h] [ebp-18h]
  int v18; // [esp-4h] [ebp-18h]
  int v19; // [esp-4h] [ebp-18h]
  int v20; // [esp-4h] [ebp-18h]
  CMFCToolBarButton *v21; // [esp+8h] [ebp-Ch]
  int v22; // [esp+Ch] [ebp-8h]

  v22 = *((_DWORD *)a3 + 1);
  switch ( v22 )
  {
    case 1:
      v16 = IEntity::Type((unsigned __int16 *)a2);
      v4 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v4, v16);
      v21 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((_DWORD *)a3 + 3));
      *((_WORD *)this + 16) = IEntity::ID();
      result = (*(int (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2);
      if ( (_BYTE)result )
      {
        v5 = CBuilding::DoorPackedXY(v21);
        ISettlerRole::NewDestination(this, a2, v5, 0);
        v17 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v13 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v6 = IEntity::Race(a2);
        v7 = CEntityToDoListMgr::SettlerJobList(v6, v13);
        return (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v7, v17);
      }
      break;
    case 5:
      v18 = IEntity::Type((unsigned __int16 *)a2);
      v8 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v8, v18);
      ISettlerRole::NewDestination(this, a2, *((_DWORD *)a3 + 5), 0);
      v14 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
      v9 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
      CWorldManager::ClearFlagBits(v9, v14, 32);
      result = (*(unsigned __int8 (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2);
      if ( (_BYTE)result )
      {
        (*(void (__thiscall **)(CHunterRole *, _DWORD))(*(_DWORD *)this + 52))(this, *((_DWORD *)a3 + 4));
        v19 = *((_DWORD *)a3 + 4);
        v10 = IEntity::ID();
        CTrace::Print("HunterRole: GATHER was sent to Hunter %d for Entity %d", v10, v19);
        v20 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
        v15 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
        v11 = IEntity::Race(a2);
        v12 = CEntityToDoListMgr::SettlerJobList(v11, v15);
        return (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v12, v20);
      }
      break;
    case 9:
      IEntity::SetFlagBits(a2, EntityFlag_Visible);
      return (*(int (__thiscall **)(CHunterRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
    default:
      result = (*(int (__thiscall **)(CHunterRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2);
      if ( (_BYTE)result )
      {
        result = IEntity::FlagBits(a2, EntityFlag_Registered);
        if ( !result )
        {
          CTrace::Print("ConvertEventIntoGoal HunterRole - unknown event %u", *((_DWORD *)a3 + 1));
          return IAnimatedEntity::RegisterForLogicUpdate(1);
        }
      }
      break;
  }
  return result;
}


// address=[0x15782d0]
// Decompiled from char __thiscall CHunterRole::SetFree(CHunterRole *this, struct CSettler *a2, int a3)
bool  CHunterRole::SetFree(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-10h]
  unsigned int v6; // [esp-8h] [ebp-Ch]

  if ( !*((_BYTE *)this + 44) )
    return ISettlerRole::SetFree(this, a2, a3);
  v6 = *((unsigned __int8 *)this + 44);
  v5 = IEntity::Y(a2);
  v3 = IEntity::X(a2);
  CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v3, v5, v6, 1u);
  return ISettlerRole::SetFree(this, a2, a3);
}


// address=[0x1587ad0]
// Decompiled from CHunterRole *__thiscall CHunterRole::CHunterRole(CHunterRole *this)
 CHunterRole::CHunterRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CHunterRole::_vftable_;
  return this;
}


