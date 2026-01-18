#include "CHouseWorkerRole.h"

// Definitions for class CHouseWorkerRole

// address=[0x1400ea0]
// Decompiled from int __cdecl CHouseWorkerRole::New(int a1)
class CPersistence * __cdecl CHouseWorkerRole::New(std::istream & a1) {
  
  if ( operator new(0x34u) )
    return CHouseWorkerRole::CHouseWorkerRole(a1);
  else
    return 0;
}


// address=[0x1575c50]
// Decompiled from int __thiscall CHouseWorkerRole::InitWalking(CHouseWorkerRole *this, struct CSettler *a2)
class CWalking *  CHouseWorkerRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(1, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1575c90]
// Decompiled from _BYTE *__thiscall CHouseWorkerRole::LogicUpdateJob(_BYTE *this, CMFCCaptionButton *a2)
void  CHouseWorkerRole::LogicUpdateJob(class CSettler * a2) {
  
  _BYTE *result; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  _DWORD *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax
  unsigned __int8 *v12; // eax
  int v13; // eax
  unsigned __int8 *v14; // eax
  int v15; // eax
  int v16; // [esp-4h] [ebp-40h]
  int v17; // [esp-4h] [ebp-40h]
  CProductionBuildingRole *v18; // [esp+0h] [ebp-3Ch]
  CVehicle *VehiclePtr; // [esp+4h] [ebp-38h]
  int v20; // [esp+Ch] [ebp-30h]
  int v21; // [esp+14h] [ebp-28h]
  int v22; // [esp+18h] [ebp-24h]
  int v23; // [esp+1Ch] [ebp-20h]
  int v24; // [esp+24h] [ebp-18h]
  int v25; // [esp+28h] [ebp-14h]
  int v26; // [esp+2Ch] [ebp-10h]
  unsigned __int8 *v27; // [esp+30h] [ebp-Ch]
  int v28; // [esp+34h] [ebp-8h]

  result = (_BYTE *)(*(int (__thiscall **)(_BYTE *, CMFCCaptionButton *))(*(_DWORD *)this + 124))(this, a2);
  if ( !(_BYTE)result )
    return result;
  ISettlerRole::Update(a2);
  result = this;
  switch ( this[4] )
  {
    case 0:
      this[6] -= 9;
      if ( (char)this[6] <= 0 )
        goto LABEL_62;
      result = (_BYTE *)IAnimatedEntity::RegisterForLogicUpdate(9);
      break;
    case 1:
      if ( (char)this[6] <= (int)(unsigned __int8)this[7] )
        v21 = (char)this[6];
      else
        v21 = (unsigned __int8)this[7];
      this[6] -= v21;
      if ( (char)this[6] <= 0 )
      {
        if ( IEntity::Type((unsigned __int16 *)a2) == 20 )
        {
          if ( !*((_WORD *)this + 17)
            && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 326, "m_uEntityId") == 1 )
          {
            __debugbreak();
          }
          v27 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
          if ( !v27 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 328, "pEntity") == 1 )
            __debugbreak();
          if ( v27 )
          {
            if ( IEntity::ObjType(v27) != 1
              && BBSupportDbgReport(
                   2,
                   "MapObjects\\Settler\\HouseWorkerRole.cpp",
                   331,
                   "pEntity->ObjType() == SETTLER_OBJ") == 1 )
            {
              __debugbreak();
            }
            if ( IEntity::ObjType(v27) == 1 )
              (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v27 + 24))(v27, -1);
          }
        }
        goto LABEL_62;
      }
      result = (_BYTE *)IAnimatedEntity::RegisterForLogicUpdate(v21);
      break;
    case 2:
      this[6] -= 31;
      if ( (char)this[6] <= 0 )
        goto LABEL_62;
      if ( (char)this[6] <= 31 )
        result = (_BYTE *)IAnimatedEntity::RegisterForLogicUpdate((char)this[6]);
      else
        result = (_BYTE *)IAnimatedEntity::RegisterForLogicUpdate(31);
      break;
    case 3:
      if ( (char)this[6] <= (int)(unsigned __int8)this[7] )
        v20 = (char)this[6];
      else
        v20 = (unsigned __int8)this[7];
      this[6] -= v20;
      if ( (char)this[6] <= 0 )
      {
        if ( CMapObjectMgr::ValidEntityId(*((unsigned __int16 *)this + 17)) )
        {
          VehiclePtr = CVehicleMgr::GetVehiclePtr(*((unsigned __int16 *)this + 17));
          if ( VehiclePtr )
            CVehicle::AddBuildingMaterial(VehiclePtr, (CVehicle *)(unsigned __int8)this[11]);
          this[11] = 0;
        }
        goto LABEL_62;
      }
      this[7] = *(_BYTE *)(IMovingEntity::GetActualTask(a2) + 8);
      result = (_BYTE *)IAnimatedEntity::RegisterForLogicUpdate(v20);
      break;
    case 4:
      v25 = (unsigned __int8)this[7] / 2;
      this[6] -= v25;
      if ( (char)this[6] < v25 )
        goto LABEL_62;
      if ( IEntity::Type((unsigned __int16 *)a2) == 15 )
      {
        v3 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
        v18 = (CProductionBuildingRole *)CBuilding::Role(v3);
        this[11] = CProductionBuildingRole::GetProductType(v18);
      }
      v4 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
      v23 = CBuilding::Role(v4);
      v26 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v23 + 56))(v23, (unsigned __int8)this[11]);
      if ( !v26 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 252, "iPileId != 0") == 1 )
        __debugbreak();
      v5 = CPileMgr::operator[](v26);
      if ( CPile::GetRoleType((CPile *)v5)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\HouseWorkerRole.cpp",
             253,
             "g_cPileMgr[ iPileId ].GetRoleType() == IPileRole::PILE_PRODUCTION") == 1 )
      {
        __debugbreak();
      }
      v6 = CPileMgr::operator[](v26);
      CPile::IncreaseUnforeseen((CPile *)v6, 1);
      this[11] = 0;
      result = (_BYTE *)IAnimatedEntity::RegisterForLogicUpdate(v25 - 1);
      break;
    case 5:
      v24 = (unsigned __int8)this[7] / 2;
      this[6] -= v24;
      if ( (char)this[6] < v24 )
      {
LABEL_62:
        result = (_BYTE *)(*(int (__thiscall **)(_BYTE *, CMFCCaptionButton *))(*(_DWORD *)this + 36))(this, a2);
      }
      else
      {
        v7 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
        v22 = CBuilding::Role(v7);
        v28 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v22 + 56))(v22, (unsigned __int8)this[11]);
        if ( !v28 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 285, "iPileId != 0") == 1 )
          __debugbreak();
        v8 = CPileMgr::operator[](v28);
        if ( CPile::GetRoleType((CPile *)v8) != 1 )
        {
          v9 = CPileMgr::operator[](v28);
          v16 = IEntity::Y(v9);
          v10 = CPileMgr::operator[](v28);
          v11 = IEntity::X(v10);
          if ( BBSupportDbgReportF(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 290, "Pile x: %u y: %u", v11, v16) == 1 )
            __debugbreak();
        }
        v12 = CPileMgr::operator[](v28);
        if ( !IEntity::FlagBits(v12, (EntityFlag)0x10u) )
        {
          v17 = IEntity::Race(a2);
          v13 = IEntity::Type((unsigned __int16 *)a2);
          if ( BBSupportDbgReportF(
                 2,
                 "MapObjects\\Settler\\HouseWorkerRole.cpp",
                 292,
                 "Pile not locked! Settler %u, Race %u",
                 v13,
                 v17) == 1 )
            __debugbreak();
        }
        v14 = CPileMgr::operator[](v28);
        CPile::DecreaseUnforeseen((CPile *)v14, 1);
        result = (_BYTE *)IAnimatedEntity::RegisterForLogicUpdate(v24);
      }
      break;
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      result = (_BYTE *)(*(int (__thiscall **)(_BYTE *, CMFCCaptionButton *))(*(_DWORD *)this + 16))(this, a2);
      break;
    default:
      if ( debug && DEBUG_FLAGS[dword_415212C] )
      {
        v15 = IEntity::ID();
        result = (_BYTE *)BBSupportTracePrintF(0, "HouseWorkerRole nr %u - LogicUpdate unknown task", v15);
      }
      break;
  }
  return result;
}


// address=[0x15762a0]
// Decompiled from CHouseWorkerRole *__thiscall CHouseWorkerRole::UpdateJob(CHouseWorkerRole *this, struct CSettler *a2)
void  CHouseWorkerRole::UpdateJob(class CSettler * a2) {
  
  CHouseWorkerRole *result; // eax
  int v3; // eax
  int v4; // [esp+8h] [ebp-24h]
  unsigned int v5; // [esp+Ch] [ebp-20h]
  int v6; // [esp+10h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-18h]
  CHouseWorkerRole *i; // [esp+20h] [ebp-Ch]
  char v9; // [esp+24h] [ebp-8h]

  result = this;
  v9 = *((_BYTE *)this + 4);
  if ( v9 )
  {
    if ( v9 == 4 )
    {
      v7 = IAnimatedEntity::Frame(a2);
      v6 = *((unsigned __int16 *)this + 4);
      if ( v7 > v6 )
        return (CHouseWorkerRole *)IAnimatedEntity::SetFrame(v7 - v6);
    }
    else
    {
      if ( v9 != 5 )
        return result;
      v5 = *((unsigned __int16 *)this + 4) + IAnimatedEntity::Frame(a2);
      if ( v5 < *((unsigned __int8 *)this + 7) )
        return (CHouseWorkerRole *)IAnimatedEntity::SetFrame(v5);
      if ( *((_BYTE *)this + 7) )
        return (CHouseWorkerRole *)IAnimatedEntity::SetFrame(*((_BYTE *)this + 7) - 1);
    }
    return (CHouseWorkerRole *)IAnimatedEntity::SetFrame(0);
  }
  v3 = IAnimatedEntity::Frame(a2);
  IAnimatedEntity::SetFrame((*((unsigned __int16 *)this + 4) + v3) % *((unsigned __int8 *)this + 7));
  if ( !IAnimatedEntity::Frame(a2) && *((unsigned __int8 *)this + 7) > 1u )
    IAnimatedEntity::SetFrame(1);
  v4 = *((unsigned __int16 *)this + 4);
  for ( i = 0; ; i = (CHouseWorkerRole *)((char *)i + 1) )
  {
    result = i;
    if ( (int)i >= v4 )
      break;
    *((float *)this + 9) = *((float *)this + 9) + *((float *)this + 11);
    *((float *)this + 10) = *((float *)this + 10) + *((float *)this + 12);
  }
  return result;
}


// address=[0x1576430]
// Decompiled from int __stdcall CHouseWorkerRole::PostLoadInit(CPropertySet *a1)
void  CHouseWorkerRole::PostLoadInit(class CSettler * a1) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x1576450]
// Decompiled from char *__thiscall CHouseWorkerRole::CHouseWorkerRole(char *this, int a2)
 CHouseWorkerRole::CHouseWorkerRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CHouseWorkerRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CHouseWorkerRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<float>(a2, v5 + 44);
  operator^<float>(a2, v5 + 48);
  v6 = -1;
  return v5;
}


// address=[0x1576520]
// Decompiled from int __thiscall CHouseWorkerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CHouseWorkerRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<float>(a2, (char *)v4 + 44);
  return operator^<float>(a2, (char *)v4 + 48);
}


// address=[0x1577220]
// Decompiled from int __thiscall CHouseWorkerRole::ClassID(CHouseWorkerRole *this)
unsigned long  CHouseWorkerRole::ClassID(void)const {
  
  return CHouseWorkerRole::m_iClassID;
}


// address=[0x1577260]
// Decompiled from int __thiscall CHouseWorkerRole::GetSettlerRole(CHouseWorkerRole *this)
int  CHouseWorkerRole::GetSettlerRole(void)const {
  
  return 4;
}


// address=[0x1588700]
// Decompiled from int __cdecl CHouseWorkerRole::Load(int a1)
class CHouseWorkerRole * __cdecl CHouseWorkerRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CHouseWorkerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bee4]
// [Decompilation failed for static unsigned long CHouseWorkerRole::m_iClassID]

// address=[0x1576580]
// Decompiled from ISettlerRole *__thiscall CHouseWorkerRole::~CHouseWorkerRole(CHouseWorkerRole *this)
 CHouseWorkerRole::~CHouseWorkerRole(void) {
  
  *(_DWORD *)this = &CHouseWorkerRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x15765a0]
// Decompiled from int __thiscall CHouseWorkerRole::GetNextJob(CHouseWorkerRole *this, struct CSettler *a2)
void  CHouseWorkerRole::GetNextJob(class CSettler * a2) {
  
  int result; // eax

  IMovingEntity::IncToDoListIter(a2);
  result = IMovingEntity::IsEndIter(a2);
  if ( !(_BYTE)result )
    return (*(int (__thiscall **)(CHouseWorkerRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
  *((_BYTE *)this + 4) = 17;
  return result;
}


// address=[0x15765e0]
// Decompiled from void __thiscall CHouseWorkerRole::TakeJob(ISettlerRole *this, CMFCCaptionButton *a2)
void  CHouseWorkerRole::TakeJob(class CSettler * a2) {
  
  int TickCounter; // eax
  const struct CEntityTask *ActualTask; // eax
  unsigned int v4; // eax
  CBuilding *v5; // eax
  int v6; // eax
  int v7; // [esp+4h] [ebp-44h]
  int v8; // [esp+10h] [ebp-38h]
  int v9; // [esp+14h] [ebp-34h]
  int v10; // [esp+18h] [ebp-30h] BYREF
  int v11; // [esp+1Ch] [ebp-2Ch] BYREF
  float v12; // [esp+20h] [ebp-28h]
  float v13; // [esp+24h] [ebp-24h]
  float v14; // [esp+28h] [ebp-20h]
  float v15; // [esp+2Ch] [ebp-1Ch]
  float v16; // [esp+30h] [ebp-18h]
  float v17; // [esp+34h] [ebp-14h]
  int v18; // [esp+38h] [ebp-10h]
  float v19; // [esp+3Ch] [ebp-Ch]
  int v20; // [esp+40h] [ebp-8h]
  ISettlerRole *v21; // [esp+44h] [ebp-4h]

  v21 = this;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(a2, TickCounter);
  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(v21, a2, ActualTask);
  v18 = *((char *)v21 + 4);
  switch ( v18 )
  {
    case 0:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v21 + 124))(v21, a2) )
      {
        IMovingEntity::SetDisplacementCosts(10);
        v17 = (float)*((__int16 *)v21 + 8) * 12.0;
        v14 = (float)((float)*((__int16 *)v21 + 7) * 24.0) - v17;
        v16 = v14 - *((float *)v21 + 9);
        v19 = v17 - *((float *)v21 + 10);
        v13 = abs(v19);
        v11 = (int)(float)((float)(v13 * 0.083333336) + 0.5);
        v12 = abs(v16 - v19);
        v10 = (int)((float)(v12 * 0.041666668) + 0.5);
        v20 = 9 * *(_DWORD *)BB::Max<int>(&v10, &v11);
        if ( v20 < 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 550, "iJobCounter >= 0") == 1 )
          __debugbreak();
        if ( v20 >= 128
          && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 551, "iJobCounter < 128") == 1 )
        {
          __debugbreak();
        }
        *((_BYTE *)v21 + 6) = v20;
        if ( v20 <= 0 )
        {
          *((_DWORD *)v21 + 11) = 0;
          *((_DWORD *)v21 + 12) = 0;
          IAnimatedEntity::RegisterForLogicUpdate(1);
        }
        else
        {
          v15 = 1.0 / (float)v20;
          *((float *)v21 + 11) = v16 * v15;
          *((float *)v21 + 12) = v19 * v15;
          IAnimatedEntity::RegisterForLogicUpdate(9);
        }
      }
      break;
    case 1:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v21 + 124))(v21, a2) )
        goto LABEL_14;
      break;
    case 2:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v21 + 124))(v21, a2) )
      {
        if ( *((char *)v21 + 6) <= 31 )
          IAnimatedEntity::RegisterForLogicUpdate(*((char *)v21 + 6));
        else
          IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      break;
    case 3:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v21 + 124))(v21, a2) )
LABEL_14:
        IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)v21 + 7) - 1);
      break;
    case 4:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v21 + 124))(v21, a2) )
      {
        IAnimatedEntity::SetFrame(*((_BYTE *)v21 + 7) - 1);
        IAnimatedEntity::RegisterForLogicUpdate(*((char *)v21 + 6) / 2);
      }
      break;
    case 5:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v21 + 124))(v21, a2) )
        IAnimatedEntity::RegisterForLogicUpdate(*((char *)v21 + 6) / 2);
      break;
    case 10:
      IAnimatedEntity::SetFrame(1);
      v8 = *((__int16 *)v21 + 7) + Y16X16::UnpackXFast(*((_DWORD *)v21 + 6));
      v9 = *((__int16 *)v21 + 8) + Y16X16::UnpackYFast(*((_DWORD *)v21 + 6));
      *((_DWORD *)v21 + 6) = Y16X16::PackXYFast(v8, v9);
      IMovingEntity::WalkToXY(a2, *((_DWORD *)v21 + 6), 0);
      *((_BYTE *)v21 + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v21 + 16))(v21, a2);
      break;
    case 17:
      IMovingEntity::SetDisplacementCosts(0);
      v4 = CStateGame::Rand(g_pGame);
      IAnimatedEntity::RegisterForLogicUpdate(v4 % 4 + 1);
      break;
    case 24:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v21 + 124))(v21, a2) )
      {
        IMovingEntity::SetDisplacementCosts(10);
        IEntity::ClearFlagBits(a2, Visible);
        *((_DWORD *)v21 + 9) = 0;
        *((_DWORD *)v21 + 10) = 0;
        v7 = IEntity::ID();
        v5 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)v21 + 16));
        CBuilding::SettlerEnter(v5, v7);
      }
      break;
    default:
      if ( debug && DEBUG_FLAGS[dword_415212C] )
      {
        v6 = IEntity::ID();
        BBSupportTracePrintF(0, "HouseWorkerRole nr %u - TakeJob unknown task", v6);
      }
      break;
  }
}


// address=[0x1576b00]
// Decompiled from int __thiscall CHouseWorkerRole::Init(_DWORD *this, CPropertySet *a2)
void  CHouseWorkerRole::Init(class CSettler * a2) {
  
  int result; // eax

  result = CWarMap::AddEntity(a2);
  this[9] = 0;
  this[10] = 0;
  return result;
}


// address=[0x1576b30]
// Decompiled from int __thiscall CHouseWorkerRole::ConvertEventIntoGoal(ISettlerRole *this, unsigned __int16 *a2, _DWORD *a3)
void  CHouseWorkerRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-8h] [ebp-18h]
  int v13; // [esp-4h] [ebp-14h]
  int v14; // [esp-4h] [ebp-14h]
  int v15; // [esp-4h] [ebp-14h]
  int v16; // [esp-4h] [ebp-14h]
  CMFCToolBarButton *v17; // [esp+4h] [ebp-Ch]

  switch ( a3[1] )
  {
    case 1:
      result = (*(unsigned __int8 (__thiscall **)(ISettlerRole *, unsigned __int16 *))(*(_DWORD *)this + 124))(this, a2);
      if ( (_BYTE)result )
      {
        v13 = IEntity::Type(a2);
        v4 = IEntity::Race(a2);
        CSettlerMgr::GetSettlerInfo(v4, v13);
        v17 = (CMFCToolBarButton *)CBuildingMgr::operator[](a3[3]);
        *((_WORD *)this + 16) = IEntity::ID();
        v5 = CBuilding::DoorPackedXY(v17);
        ISettlerRole::NewDestination(this, (struct CSettler *)a2, v5, 0);
        v14 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v12 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v6 = IEntity::Race(a2);
        v7 = CEntityToDoListMgr::SettlerJobList(v6, v12);
        result = (*(int (__thiscall **)(unsigned __int16 *, int, int))(*(_DWORD *)a2 + 112))(a2, v7, v14);
      }
      break;
    case 3:
      if ( !IEntity::FlagBits(a2, MagicInvisible)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\HouseWorkerRole.cpp",
             788,
             "_pSettler->FlagBits(ENTITY_FLAG_MAGIC_INVISIBLE)!=0") == 1 )
      {
        __debugbreak();
      }
      result = (*(unsigned __int8 (__thiscall **)(ISettlerRole *, unsigned __int16 *))(*(_DWORD *)this + 124))(this, a2);
      if ( (_BYTE)result )
      {
        v15 = a3[4];
        v8 = IEntity::Race(a2);
        v9 = CEntityToDoListMgr::SettlerJobList(v8, v15);
        (*(void (__thiscall **)(unsigned __int16 *, int, int))(*(_DWORD *)a2 + 112))(a2, v9, v15);
        result = (*(int (__thiscall **)(ISettlerRole *, _DWORD))(*(_DWORD *)this + 52))(this, a3[5]);
      }
      break;
    case 4:
      result = (*(int (__thiscall **)(ISettlerRole *, unsigned __int16 *))(*(_DWORD *)this + 124))(this, a2);
      if ( (_BYTE)result )
      {
        (*(void (__thiscall **)(ISettlerRole *, _DWORD))(*(_DWORD *)this + 52))(this, a3[5]);
        v16 = a3[4];
        v10 = IEntity::Race(a2);
        v11 = CEntityToDoListMgr::SettlerJobList(v10, v16);
        result = (*(int (__thiscall **)(unsigned __int16 *, int, int))(*(_DWORD *)a2 + 112))(a2, v11, v16);
      }
      break;
    case 9:
      result = (*(int (__thiscall **)(ISettlerRole *, unsigned __int16 *, _DWORD))(*(_DWORD *)this + 64))(
                 this,
                 a2,
                 a3[5]);
      break;
    default:
      result = IEntity::FlagBits(a2, Registered);
      if ( !result )
      {
        CTrace::Print("ConvertEventIntoGoal HouseWorker - unknown event %u", a3[1]);
        result = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
  }
  return result;
}


// address=[0x1587a80]
// Decompiled from CHouseWorkerRole *__thiscall CHouseWorkerRole::CHouseWorkerRole(CHouseWorkerRole *this)
 CHouseWorkerRole::CHouseWorkerRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CHouseWorkerRole::_vftable_;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  return this;
}


