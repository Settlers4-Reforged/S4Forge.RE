#include "CSlaveRole.h"

// Definitions for class CSlaveRole

// address=[0x1401e40]
// Decompiled from int __cdecl CSlaveRole::New(int a1)
class CPersistence * __cdecl CSlaveRole::New(std::istream & a1) {
  
  if ( operator new(0x38u) )
    return CSlaveRole::CSlaveRole(a1);
  else
    return 0;
}


// address=[0x15888c0]
// Decompiled from int __cdecl CSlaveRole::Load(int a1)
class CSlaveRole * __cdecl CSlaveRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CSlaveRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x158caa0]
// Decompiled from int __thiscall CSlaveRole::InitWalking(CSlaveRole *this, struct CSettler *a2)
class CWalking *  CSlaveRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x158cae0]
// Decompiled from CSlaveRole *__thiscall CSlaveRole::LogicUpdateJob(CSlaveRole *this, struct CSettler *a2)
void  CSlaveRole::LogicUpdateJob(class CSettler * a2) {
  
  CSlaveRole *result; // eax
  int v3; // [esp+0h] [ebp-8h]

  result = this;
  LOBYTE(v3) = *((_BYTE *)this + 4);
  switch ( (_BYTE)v3 )
  {
    case 2:
      if ( (*(unsigned __int8 (__thiscall **)(CSlaveRole *, struct CSettler *))(*(_DWORD *)this + 132))(this, a2) )
      {
        IMovingEntity::ResetToDoList(v3);
        return (CSlaveRole *)(*(int (__thiscall **)(CSlaveRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
      }
      else
      {
        return (CSlaveRole *)IAnimatedEntity::RegisterForLogicUpdate(31);
      }
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      return (CSlaveRole *)(*(int (__thiscall **)(CSlaveRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
    case 0x10:
      CSlaveRole::ClearWorkPositionAndFlagIfNecessary(this);
      if ( (*(unsigned __int8 (__thiscall **)(CSlaveRole *, struct CSettler *))(*(_DWORD *)this + 132))(this, a2) )
      {
        IMovingEntity::IncToDoListIter(a2);
        return (CSlaveRole *)(*(int (__thiscall **)(CSlaveRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      }
      else
      {
        (*(void (__thiscall **)(CSlaveRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
        return (CSlaveRole *)IAnimatedEntity::RegisterForLogicUpdate(1);
      }
  }
  return result;
}


// address=[0x158cbd0]
// Decompiled from int __thiscall CSlaveRole::UpdateJob(CSlaveRole *this, struct CSettler *a2)
void  CSlaveRole::UpdateJob(class CSettler * a2) {
  
  int v2; // ecx
  int result; // eax
  int v4; // eax
  char v5; // al
  char v6; // al

  v2 = *((char *)this + 4);
  result = v2 - 13;
  switch ( v2 )
  {
    case 13:
    case 16:
      v4 = IAnimatedEntity::Frame(a2);
      result = IAnimatedEntity::SetFrame((*((unsigned __int16 *)this + 4) + v4) % *((unsigned __int8 *)this + 7));
      break;
    case 21:
      v5 = IAnimatedEntity::Frame(a2);
      IAnimatedEntity::SetFrame(v5 - *((_WORD *)this + 4));
      result = IAnimatedEntity::Frame(a2);
      if ( result < 0 )
        result = IAnimatedEntity::SetFrame(0);
      break;
    case 22:
      v6 = IAnimatedEntity::Frame(a2);
      IAnimatedEntity::SetFrame(*((_WORD *)this + 4) + v6);
      result = IAnimatedEntity::Frame(a2);
      if ( result >= *((unsigned __int8 *)this + 7) )
        result = IAnimatedEntity::SetFrame(0);
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x158ccf0]
// Decompiled from int __stdcall CSlaveRole::PostLoadInit(CPropertySet *a1)
void  CSlaveRole::PostLoadInit(class CSettler * a1) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x158cd10]
// Decompiled from void __thiscall CSlaveRole::InitFlee(CSlaveRole *this, struct CSettler *a2, int a3)
void  CSlaveRole::InitFlee(class CSettler * a2, int a3) {
  
  ;
}


// address=[0x158cd20]
// Decompiled from bool __thiscall CSlaveRole::IsUnEmployed(CSlaveRole *this)
bool  CSlaveRole::IsUnEmployed(void)const {
  
  return !ISettlerRole::HomeEntityId(this) && *((_BYTE *)this + 4) != 27;
}


// address=[0x158cd60]
// Decompiled from char __thiscall CSlaveRole::SetFree(CSlaveRole *this, struct CSettler *a2, int a3)
bool  CSlaveRole::SetFree(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-4h] [ebp-Ch]
  int v8; // [esp+0h] [ebp-8h]

  CSlaveRole::ClearWorkPositionAndFlagIfNecessary(this);
  if ( !ISettlerRole::HomeEntityId(this) )
    return 0;
  v7 = *((unsigned __int16 *)this + 16);
  v3 = IEntity::ID();
  CTrace::Print("SlaveRole: Freeing %i from %i", v3, v7);
  v4 = ISettlerRole::HomeEntityId(this);
  v8 = CMapObjectMgr::EntityPtr(v4);
  if ( !v8 && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 927, "pEntity != 0") == 1 )
    __debugbreak();
  if ( v8 )
  {
    v5 = IEntity::EntityId((unsigned __int16 *)a2);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 64))(v8, v5);
  }
  if ( ISettlerRole::HomeEntityId(this)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 934, "HomeEntityId() == 0") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x158ce30]
// Decompiled from char __thiscall CSlaveRole::ESChanged(CSlaveRole *this, struct CSettler *a2)
bool  CSlaveRole::ESChanged(class CSettler * a2) {
  
  return 0;
}


// address=[0x158ce40]
// Decompiled from char *__thiscall CSlaveRole::CSlaveRole(char *this, int a2)
 CSlaveRole::CSlaveRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CSlaveRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSlaveRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v5 + 44));
  operator^<int>(a2, (int)(v5 + 48));
  operator^<int>(a2, (int)(v5 + 52));
  v6 = -1;
  return v5;
}


// address=[0x158cf30]
// Decompiled from int __thiscall CSlaveRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CSlaveRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = (int *)this;
  ISettlerRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<int>((int)a2, v4 + 11);
  operator^<int>((int)a2, v4 + 12);
  return operator^<int>((int)a2, v4 + 13);
}


// address=[0x158e470]
// Decompiled from int __thiscall CSlaveRole::ClassID(CSlaveRole *this)
unsigned long  CSlaveRole::ClassID(void)const {
  
  return CSlaveRole::m_iClassID;
}


// address=[0x158e4b0]
// Decompiled from int __thiscall CSlaveRole::GetSettlerRole(CSlaveRole *this)
int  CSlaveRole::GetSettlerRole(void)const {
  
  return 17;
}


// address=[0x3d8bf9c]
// [Decompilation failed for static unsigned long CSlaveRole::m_iClassID]

// address=[0x158cfa0]
// Decompiled from CSlaveRole *__thiscall CSlaveRole::CSlaveRole(CSlaveRole *this)
 CSlaveRole::CSlaveRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CSlaveRole::_vftable_;
  *((_DWORD *)this + 11) = -1;
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 13) = 0;
  return this;
}


// address=[0x158cfe0]
// Decompiled from ISettlerRole *__thiscall CSlaveRole::~CSlaveRole(CSlaveRole *this)
 CSlaveRole::~CSlaveRole(void) {
  
  *(_DWORD *)this = &CSlaveRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x158d000]
// Decompiled from int __thiscall CSlaveRole::GetNextJob(CSlaveRole *this, struct CSettler *a2)
void  CSlaveRole::GetNextJob(class CSettler * a2) {
  
  CSlaveRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(v3);
  return (*(int (__thiscall **)(CSlaveRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x158d040]
// Decompiled from void __thiscall CSlaveRole::TakeJob(int this, CPaneContainer *a2)
void  CSlaveRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int LastLogicUpdateTick; // eax
  CBuilding *v7; // eax
  int v8; // esi
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // [esp-8h] [ebp-38h]
  int v13; // [esp-4h] [ebp-34h]
  int v14; // [esp-4h] [ebp-34h]
  int v15; // [esp-4h] [ebp-34h]
  int v16; // [esp-4h] [ebp-34h]
  int v17; // [esp-4h] [ebp-34h]
  int v18; // [esp+Ch] [ebp-24h]
  int v19; // [esp+10h] [ebp-20h]
  int v20; // [esp+14h] [ebp-1Ch]
  unsigned __int8 *v21; // [esp+18h] [ebp-18h]
  int v22; // [esp+1Ch] [ebp-14h]
  struct CManakopter *ManakopterPtr; // [esp+24h] [ebp-Ch]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues((ISettlerRole *)this, a2, ActualTask);
  switch ( *(_BYTE *)(this + 4) )
  {
    case 7:
    case 0x21:
      IAnimatedEntity::SetFrame(1);
      v18 = *(__int16 *)(this + 14) + Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
      v19 = *(__int16 *)(this + 16) + Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
      *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v18, v19);
      if ( *(_BYTE *)(this + 4) == 33 )
        v22 = 0x2000;
      else
        v22 = 0;
      IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), v22);
      *(_BYTE *)(this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(int, CPaneContainer *))(*(_DWORD *)this + 16))(this, a2);
      return;
    case 0xE:
      IAnimatedEntity::SetFrame(1);
      IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 28), 0);
      *(_BYTE *)(this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(int, CPaneContainer *))(*(_DWORD *)this + 16))(this, a2);
      return;
    case 0x10:
      if ( CSlaveRole::WorkPositionValid((CSlaveRole *)this) )
      {
        IMovingEntity::SetDirection(a2, 5);
        IMovingEntity::SetDisplacementCosts(10);
        IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      else
      {
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      return;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(0);
      IAnimatedEntity::RegisterForLogicUpdate(31);
      return;
    case 0x18:
      if ( !ISettlerRole::HomeEntityId(this) )
        goto LABEL_21;
      *(_DWORD *)(this + 36) = 0;
      *(_DWORD *)(this + 40) = 0;
      *(_DWORD *)(this + 24) = 0;
      IMovingEntity::SetDisplacementCosts(10);
      v15 = IEntity::ID();
      LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(a2);
      CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v15);
      v21 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*(unsigned __int16 *)(this + 32));
      if ( !v21 )
        goto LABEL_21;
      v20 = IEntity::ObjType(v21);
      if ( v20 == 8 )
      {
        v16 = IEntity::ID();
        v7 = (CBuilding *)CBuildingMgr::operator[](*(unsigned __int16 *)(this + 32));
        CBuilding::SettlerEnter(v7, v16);
      }
      else if ( v20 == 64 )
      {
        ManakopterPtr = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, *(unsigned __int16 *)(this + 32));
        v8 = IEntity::Y(ManakopterPtr);
        v17 = v8 - IEntity::Y(a2);
        v9 = IEntity::X(ManakopterPtr);
        v10 = IEntity::X(a2);
        if ( (int)Grid::Distance((Grid *)(v9 - v10), v17) >= 4
          || IEntity::FlagBits(ManakopterPtr, (EntityFlag)&unk_4000000) )
        {
LABEL_21:
          CSlaveRole::FreeServant((CSlaveRole *)this, a2);
        }
        else
        {
          v11 = IEntity::ID();
          CManakopter::SettlerEnter(ManakopterPtr, v11);
        }
      }
      return;
    case 0x1C:
      v13 = IEntity::Type((unsigned __int16 *)a2);
      v3 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v3, v13);
      v14 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](2);
      v12 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](2);
      v4 = IEntity::Race(a2);
      v5 = CEntityToDoListMgr::SettlerJobList(v4, v12);
      (*(void (__thiscall **)(CPaneContainer *, int, int))(*(_DWORD *)a2 + 112))(a2, v5, v14);
      return;
    default:
      CTrace::Print("SlaveRole - TakeJob unknown task");
      return;
  }
}


// address=[0x158d3f0]
// Decompiled from _DWORD *__thiscall CSlaveRole::Init(_DWORD *this, CPropertySet *a2)
void  CSlaveRole::Init(class CSettler * a2) {
  
  _DWORD *result; // eax

  CWarMap::AddEntity(a2);
  this[11] = -1;
  this[12] = -1;
  result = this;
  this[13] = 0;
  return result;
}


// address=[0x158d430]
// Decompiled from char __thiscall CSlaveRole::SearchPosition(CSlaveRole *this, struct CSettler *a2)
bool  CSlaveRole::SearchPosition(class CSettler * a2) {
  
  int v3; // eax
  int WorkingAreaPackedXY; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-8h] [ebp-4Ch]
  int (__cdecl *v8)(int, int, _DWORD); // [esp+4h] [ebp-40h]
  Grid *v9; // [esp+8h] [ebp-3Ch]
  int v10; // [esp+Ch] [ebp-38h]
  int v11; // [esp+10h] [ebp-34h]
  int v12; // [esp+14h] [ebp-30h]
  int v13; // [esp+18h] [ebp-2Ch]
  int v14; // [esp+1Ch] [ebp-28h]
  int v15; // [esp+20h] [ebp-24h]
  CPane *v16; // [esp+24h] [ebp-20h]
  int v17; // [esp+28h] [ebp-1Ch]
  int v18; // [esp+28h] [ebp-1Ch]
  int v19; // [esp+2Ch] [ebp-18h]
  int v20; // [esp+30h] [ebp-14h]
  int v21; // [esp+34h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+38h] [ebp-Ch]

  CSlaveRole::ClearWorkPositionAndFlagIfNecessary(this);
  if ( !ISettlerRole::HomeEntityId(this) )
    return 0;
  v3 = ISettlerRole::HomeEntityId(this);
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v3);
  if ( !BuildingPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 820, "pBuilding != NULL") == 1 )
    __debugbreak();
  if ( !BuildingPtr )
    return 0;
  if ( IEntity::Type((unsigned __int16 *)BuildingPtr) != 49
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 827, "pBuilding->Type() == BUILDING_MUSHROOMFARM") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::Type((unsigned __int16 *)BuildingPtr) != 49 )
    return 0;
  v16 = (CPane *)CBuilding::Role(BuildingPtr);
  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(BuildingPtr);
  v9 = (Grid *)Y16X16::UnpackXFast(WorkingAreaPackedXY);
  v5 = CBuilding::GetWorkingAreaPackedXY(BuildingPtr);
  v10 = Y16X16::UnpackYFast(v5);
  v12 = IEntity::X(a2);
  v11 = IEntity::Y(a2);
  v19 = -1;
  v17 = -1;
  v7 = *(char *)(CDarkMushroomFarmRole::GetBuildingInfo(v16) + 478);
  v6 = IEntity::Race(BuildingPtr);
  CSettlerMgr::GetSettlerInfo(v6, v7);
  v8 = *(int (__cdecl **)(int, int, _DWORD))std::vector<CSettlerMgr::SSearchInfos>::operator[](0);
  v15 = *(_DWORD *)(CDarkMushroomFarmRole::GetBuildingInfo(v16) + 492);
  v13 = CSpiralOffsets::Last(v15);
  v14 = *((_DWORD *)this + 13);
  while ( *((_DWORD *)this + 13) < v14 + 35 )
  {
    if ( ++*((_DWORD *)this + 13) > v13 )
    {
      *((_DWORD *)this + 13) = 0;
      break;
    }
    v21 = v12 + CSpiralOffsets::DeltaX(*((_DWORD *)this + 13));
    v20 = v11 + CSpiralOffsets::DeltaY(*((_DWORD *)this + 13));
    if ( (unsigned __int8)CWorldManager::InWorld(v21, v20)
      && (unsigned __int8)CWorldManager::InWorld(v21, v20 + 1)
      && Grid::Distance(v9, v10, v21, v20) <= v15
      && !CWorldManager::FlagBits(v21, v20 + 1, 0x20u)
      && v8(v21, v20, 0)
      && (unsigned int)CGameData::Rand(g_pGameData) >= 0x2000 )
    {
      v19 = v21;
      v17 = v20;
      break;
    }
  }
  if ( v19 == -1 )
    return 0;
  v18 = v17 + 1;
  CSlaveRole::SetWorkPositionAndFlag(this, v19, v18);
  ISettlerRole::NewDestination(this, a2, v19, v18, 4096);
  return 1;
}


// address=[0x158d700]
// Decompiled from void __thiscall CSlaveRole::ConvertEventIntoGoal(ISettlerRole *this, CPropertySet *a2, _DWORD *a3)
void  CSlaveRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int v3; // eax
  CEntityTask *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int WorkingAreaPackedXY; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // [esp-8h] [ebp-70h]
  int v26; // [esp-8h] [ebp-70h]
  int v27; // [esp-8h] [ebp-70h]
  int v28; // [esp-8h] [ebp-70h]
  int v29; // [esp-4h] [ebp-6Ch]
  int v30; // [esp-4h] [ebp-6Ch]
  int v31; // [esp-4h] [ebp-6Ch]
  int v32; // [esp-4h] [ebp-6Ch]
  int v33; // [esp-4h] [ebp-6Ch]
  int v34; // [esp-4h] [ebp-6Ch]
  int v35; // [esp-4h] [ebp-6Ch]
  _DWORD v36[7]; // [esp+0h] [ebp-68h] BYREF
  int v37; // [esp+1Ch] [ebp-4Ch]
  int v38; // [esp+20h] [ebp-48h]
  CMFCToolBarButton *v39; // [esp+24h] [ebp-44h]
  void *v40; // [esp+28h] [ebp-40h]
  int v41; // [esp+2Ch] [ebp-3Ch]
  int v42; // [esp+30h] [ebp-38h]
  int v43; // [esp+34h] [ebp-34h]
  int v44; // [esp+38h] [ebp-30h]
  int v45; // [esp+3Ch] [ebp-2Ch]
  int SettlerInfo; // [esp+40h] [ebp-28h]
  int v47; // [esp+44h] [ebp-24h]
  int v48; // [esp+48h] [ebp-20h]
  int v49; // [esp+4Ch] [ebp-1Ch]
  int v50; // [esp+50h] [ebp-18h]
  int v51; // [esp+54h] [ebp-14h]
  struct CManakopter *ManakopterPtr; // [esp+58h] [ebp-10h]
  int v53; // [esp+5Ch] [ebp-Ch]
  int v54; // [esp+60h] [ebp-8h]
  ISettlerRole *v55; // [esp+64h] [ebp-4h]

  v55 = this;
  v54 = a3[1] - 1;
  switch ( v54 )
  {
    case 0:
      CSlaveRole::ClearWorkPositionAndFlagIfNecessary(v55);
      if ( !ISettlerRole::HomeEntityId(v55) )
        goto LABEL_15;
      v8 = ISettlerRole::HomeEntityId(v55);
      if ( CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v8) )
      {
        v9 = ISettlerRole::HomeEntityId(v55);
        v40 = (void *)CBuildingMgr::operator[](v9);
        WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(v40);
        ISettlerRole::NewDestination(v55, a2, WorkingAreaPackedXY, 0);
        CSettler::TakeAnimList(a2, 1);
      }
      break;
    case 1:
      v47 = ISettlerRole::HomeEntityId(v55);
      if ( v47 )
      {
        v39 = (CMFCToolBarButton *)CBuildingMgr::operator[](v47);
        v11 = CBuilding::DoorPackedXY(v39);
        ISettlerRole::NewDestination(v55, a2, v11, 0);
        CSettler::TakeAnimList(a2, 0);
      }
      else
      {
LABEL_15:
        (*(void (__thiscall **)(ISettlerRole *, CPropertySet *, int))(*(_DWORD *)v55 + 64))(v55, a2, -1);
      }
      break;
    case 2:
      v30 = IEntity::Type((unsigned __int16 *)a2);
      v12 = IEntity::Race(a2);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v12, v30);
      ISettlerRole::NewDestination(v55, a2, a3[5], 0);
      (*(void (__thiscall **)(ISettlerRole *, _DWORD))(*(_DWORD *)v55 + 52))(v55, a3[4]);
      v31 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
      v25 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
      v13 = IEntity::Race(a2);
      v14 = CEntityToDoListMgr::SettlerJobList(v13, v25);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v14, v31);
      break;
    case 4:
      if ( *((_BYTE *)v55 + 4) == 17
        && (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CPropertySet *))(*(_DWORD *)v55 + 132))(v55, a2) )
      {
        IMovingEntity::ResetToDoList(v36[0]);
        (*(void (__thiscall **)(ISettlerRole *, CPropertySet *))(*(_DWORD *)v55 + 40))(v55, a2);
      }
      IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 8:
      v3 = IEntity::ID();
      CTrace::Print("SlaveRole: Target %i dies for %i", a3[3], v3);
      (*(void (__thiscall **)(ISettlerRole *, CPropertySet *, int))(*(_DWORD *)v55 + 64))(v55, a2, -1);
      if ( !std::list<CEntityTask>::size(&unk_4158C88) )
      {
        v4 = CEntityTask::CEntityTask((CEntityTask *)v36, 27, 325, 0, 0, -1, 1, -1, 1, 1, 0, 0, 0, 0);
        std::list<CEntityTask>::push_back(v4);
      }
      v48 = IEntity::EntityId((unsigned __int16 *)a2);
      v36[6] = a3[3];
      v51 = a3[4];
      if ( v51 <= 0 )
      {
        v5 = IEntity::OwnerId((unsigned __int8 *)a2);
        v49 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)g_pDarkTribe + 24))(g_pDarkTribe, v5);
        if ( v49 )
        {
          v6 = CBuilding::EnsignWorldIdx(v49);
          v42 = CWorldManager::SectorId(v6);
          v29 = IEntity::Y(a2);
          v7 = IEntity::X(a2);
          v41 = CWorldManager::SectorId(v7, v29);
          if ( v42 == v41 )
            (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pDarkTribe + 8))(g_pDarkTribe, v48);
          else
            CSlaveRole::FreeServant(v55, a2);
        }
      }
      else
      {
        (*(void (__thiscall **)(CPropertySet *, void *, int))(*(_DWORD *)a2 + 112))(a2, &unk_4158C88, -1);
        IMovingEntity::SetDisplacementCosts(10);
        v50 = CLogic::FutureEvents(g_pLogic);
        (*(void (__thiscall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)v50 + 12))(v50, 9, 4, v48, v51, 0);
      }
      break;
    case 24:
      v43 = a3[4];
      v35 = Y16X16::UnpackYFast(v43);
      v28 = Y16X16::UnpackXFast(v43);
      v23 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v23, v28, v35);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, Selectable|Visible);
      IEntity::ClearFlagBits(a2, OnBoard);
      (*(void (__thiscall **)(ISettlerRole *, CPropertySet *, int))(*(_DWORD *)v55 + 64))(v55, a2, -1);
      *((_BYTE *)v55 + 4) = 17;
      v24 = IEntity::EntityId((unsigned __int16 *)a2);
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pDarkTribe + 8))(g_pDarkTribe, v24);
      break;
    case 27:
      v32 = IEntity::Type((unsigned __int16 *)a2);
      v15 = IEntity::Race(a2);
      v44 = CSettlerMgr::GetSettlerInfo(v15, v32);
      ManakopterPtr = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, a3[3]);
      v53 = 0;
      if ( !ManakopterPtr || IEntity::FlagBits(ManakopterPtr, (EntityFlag)&unk_4000000) )
      {
        v16 = IEntity::OwnerId((unsigned __int8 *)a2);
        v45 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)g_pDarkTribe + 24))(g_pDarkTribe, v16);
        if ( v45 )
        {
          v17 = CBuilding::EnsignWorldIdx(v45);
          v38 = CWorldManager::SectorId(v17);
          v33 = IEntity::Y(a2);
          v18 = IEntity::X(a2);
          v37 = CWorldManager::SectorId(v18, v33);
          if ( v38 != v37 )
            CSlaveRole::FreeServant(v55, a2);
        }
      }
      else
      {
        v53 = IEntity::PackedXY(ManakopterPtr);
      }
      if ( v53 )
      {
        v26 = Y16X16::UnpackYFast(v53);
        v19 = Y16X16::UnpackXFast(v53);
        ISettlerRole::NewDestination(v55, a2, v19, v26, 0);
        v34 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v27 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v20 = IEntity::Race(a2);
        v21 = CEntityToDoListMgr::SettlerJobList(v20, v27);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v21, v34);
        IEntity::ClearFlagBits(a2, Selectable|Selected);
        v22 = IEntity::ID();
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v22);
      }
      break;
    default:
      IEntity::SetFlagBits(a2, (EntityFlag)0x80000000);
      break;
  }
}


// address=[0x158dca0]
// Decompiled from int __thiscall CSlaveRole::SetWorkPositionAndFlag(CSlaveRole *this, int a2, int a3)
void  CSlaveRole::SetWorkPositionAndFlag(int a2, int a3) {
  
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 995, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( CWorldManager::FlagBits(a2, a3, 0x20u)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 996, "g_cWorld.FlagBits(_iX, _iY, FLAG_WORK) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 11) != -1
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 998, "m_iWorkPosX == -1") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 12) != -1
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 999, "m_iWorkPosY == -1") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 11) = a2;
  *((_DWORD *)this + 12) = a3;
  return CWorldManager::SetFlagBits(a2, a3, 32);
}


// address=[0x158dd90]
// Decompiled from int __thiscall CSlaveRole::ClearWorkPositionAndFlagIfNecessary(CSlaveRole *this)
void  CSlaveRole::ClearWorkPositionAndFlagIfNecessary(void) {
  
  int result; // eax

  if ( *((int *)this + 11) < 0 )
  {
    if ( *((_DWORD *)this + 11) != -1
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 1022, "m_iWorkPosX == -1") == 1 )
    {
      __debugbreak();
    }
    if ( *((_DWORD *)this + 12) != -1
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 1023, "m_iWorkPosY == -1") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
  else
  {
    if ( !(unsigned __int8)CWorldManager::InWorld(*((_DWORD *)this + 11), *((_DWORD *)this + 12))
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SlaveRole.cpp", 1012, "g_cWorld.InWorld(m_iWorkPosX, m_iWorkPosY)") == 1 )
    {
      __debugbreak();
    }
    if ( !CWorldManager::FlagBits(*((_DWORD *)this + 11), *((_DWORD *)this + 12), 0x20u)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SlaveRole.cpp",
           1013,
           "g_cWorld.FlagBits(m_iWorkPosX, m_iWorkPosY, FLAG_WORK) != 0") == 1 )
    {
      __debugbreak();
    }
    result = CWorldManager::ClearFlagBits(*((_DWORD *)this + 11), *((_DWORD *)this + 12), 32);
    *((_DWORD *)this + 11) = -1;
    *((_DWORD *)this + 12) = -1;
  }
  return result;
}


// address=[0x158deb0]
// Decompiled from int __thiscall CSlaveRole::FreeServant(CSlaveRole *this, struct CSettler *a2)
void  CSlaveRole::FreeServant(class CSettler * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax

  if ( !IEntity::FlagBits(a2, OnBoard) )
  {
    v2 = IEntity::WorldIdx();
    v3 = CWorldManager::MapObjectId(v2);
    if ( v3 == IEntity::ID() )
      IEntity::SetFlagBits(a2, Visible);
  }
  v4 = IEntity::ID();
  return CMapObjectMgr::Kill(v4, 0);
}


// address=[0x158e4d0]
// Decompiled from bool __thiscall CSlaveRole::WorkPositionValid(CSlaveRole *this)
bool  CSlaveRole::WorkPositionValid(void) {
  
  return *((_DWORD *)this + 11) >= 0;
}


