#include "CHouseWorkerRole.h"

// Definitions for class CHouseWorkerRole

// address=[0x1400ea0]
// Decompiled from int __cdecl CHouseWorkerRole::New(int a1)
class CPersistence * __cdecl CHouseWorkerRole::New(std::istream & a1) {
  
  if ( operator new(0x34u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CHouseWorkerRole::CHouseWorkerRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x1575c50]
// Decompiled from int __thiscall CHouseWorkerRole::InitWalking(CHouseWorkerRole *this, struct CSettler *a2)
class CWalking *  CHouseWorkerRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = (int)CWalking::Create(1, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1575c90]
// Decompiled from _BYTE *__thiscall CHouseWorkerRole::LogicUpdateJob(_BYTE *this, IMovingEntity *a2)
void  CHouseWorkerRole::LogicUpdateJob(class CSettler * a2) {
  
  _BYTE *result; // eax
  CBuilding *v3; // eax
  CBuilding *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  CBuilding *v7; // eax
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

  result = (_BYTE *)(*(int (__thiscall **)(_BYTE *, IMovingEntity *))(*(_DWORD *)this + 124))(this, a2);
  if ( (_BYTE)result != 0 )
  {
    ((void (__stdcall *)(CMFCCaptionButton *))ISettlerRole::Update)((CMFCCaptionButton *)a2);
    result = this;
    switch ( *(this + 4) )
    {
      case 0:
        *(this + 6) -= 9;
        if ( (char)*(this + 6) <= 0 )
        {
          goto LABEL_62;
        }
        result = (_BYTE *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(9);
        break;
      case 1:
        if ( (char)*(this + 6) <= (int)(unsigned __int8)*(this + 7) )
        {
          v21 = (char)*(this + 6);
        }
        else
        {
          v21 = (unsigned __int8)*(this + 7);
        }
        *(this + 6) -= v21;
        if ( (char)*(this + 6) <= 0 )
        {
          if ( IEntity::Type(a2) == 20 )
          {
            if ( *((_WORD *)this + 17) == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 326, "m_uEntityId") == 1 )
            {
              __debugbreak();
            }
            v27 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
            if ( v27 == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 328, "pEntity") == 1 )
            {
              __debugbreak();
            }
            if ( v27 != 0 )
            {
              if ( IEntity::ObjType((IEntity *)v27) != SETTLER_OBJ && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 331, "pEntity->ObjType() == SETTLER_OBJ") == 1 )
              {
                __debugbreak();
              }
              if ( IEntity::ObjType((IEntity *)v27) == SETTLER_OBJ )
              {
                (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v27 + 24))(v27, -1);
              }
            }
          }
          goto LABEL_62;
        }
        result = (_BYTE *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v21);
        break;
      case 2:
        *(this + 6) -= 31;
        if ( (char)*(this + 6) <= 0 )
        {
          goto LABEL_62;
        }
        if ( (char)*(this + 6) <= 31 )
        {
          result = (_BYTE *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)((char)*(this + 6));
        }
        else
        {
          result = (_BYTE *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
        }
        break;
      case 3:
        if ( (char)*(this + 6) <= (int)(unsigned __int8)*(this + 7) )
        {
          v20 = (char)*(this + 6);
        }
        else
        {
          v20 = (unsigned __int8)*(this + 7);
        }
        *(this + 6) -= v20;
        if ( (char)*(this + 6) <= 0 )
        {
          if ( CMapObjectMgr::ValidEntityId(*((unsigned __int16 *)this + 17)) )
          {
            VehiclePtr = (struct CVehicle *)CVehicleMgr::GetVehiclePtr(*((unsigned __int16 *)this + 17));
            if ( VehiclePtr != 0 )
            {
              CVehicle::AddBuildingMaterial(VehiclePtr, (unsigned __int8)*(this + 11));
            }
            *(this + 11) = 0;
          }
          goto LABEL_62;
        }
        *(this + 7) = IMovingEntity::GetActualTask(a2)->m_iFrameCount;
        result = (_BYTE *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v20);
        break;
      case 4:
        v25 = (unsigned __int8)*(this + 7) / 2;
        *(this + 6) -= v25;
        if ( (char)*(this + 6) < v25 )
        {
          goto LABEL_62;
        }
        if ( IEntity::Type(a2) == 15 )
        {
          v3 = (CBuilding *)((CBuilding *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 16));
          v18 = (CProductionBuildingRole *)CBuilding::Role(v3);
          *(this + 11) = CProductionBuildingRole::GetProductType(v18);
        }
        v4 = (CBuilding *)((CBuilding *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 16));
        v23 = (int)CBuilding::Role(v4);
        v26 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v23 + 56))(v23, (unsigned __int8)*(this + 11));
        if ( v26 == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 252, "iPileId != 0") == 1 )
        {
          __debugbreak();
        }
        v5 = (unsigned __int8 *)CPileMgr::operator[](v26);
        if ( CPile::GetRoleType((CPile *)v5) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 253, "g_cPileMgr[ iPileId ].GetRoleType() == IPileRole::PILE_PRODUCTION") == 1 )
        {
          __debugbreak();
        }
        v6 = (unsigned __int8 *)CPileMgr::operator[](v26);
        CPile::IncreaseUnforeseen((CPile *)v6, 1);
        *(this + 11) = 0;
        result = (_BYTE *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v25 - 1);
        break;
      case 5:
        v24 = (unsigned __int8)*(this + 7) / 2;
        *(this + 6) -= v24;
        if ( (char)*(this + 6) < v24 )
        {
LABEL_62:
          result = (_BYTE *)(*(int (__thiscall **)(_BYTE *, IMovingEntity *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
          v7 = (CBuilding *)((CBuilding *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 16));
          v22 = (int)CBuilding::Role(v7);
          v28 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v22 + 56))(v22, (unsigned __int8)*(this + 11));
          if ( v28 == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 285, "iPileId != 0") == 1 )
          {
            __debugbreak();
          }
          v8 = (unsigned __int8 *)CPileMgr::operator[](v28);
          if ( CPile::GetRoleType((CPile *)v8) != 1 )
          {
            v9 = (unsigned __int8 *)CPileMgr::operator[](v28);
            v16 = IEntity::Y(v9);
            v10 = (unsigned __int8 *)CPileMgr::operator[](v28);
            v11 = IEntity::X(v10);
            if ( BBSupportDbgReportF(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 290, "Pile x: %u y: %u", v11, v16) == 1 )
            {
              __debugbreak();
            }
          }
          v12 = (unsigned __int8 *)CPileMgr::operator[](v28);
          if ( IEntity::FlagBits((IEntity *)v12, (EntityFlag)16) == 0 )
          {
            v17 = IEntity::Race(a2);
            v13 = IEntity::Type(a2);
            if ( BBSupportDbgReportF(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 292, "Pile not locked! Settler %u, Race %u", v13, v17) == 1 )
            {
              __debugbreak();
            }
          }
          v14 = (unsigned __int8 *)CPileMgr::operator[](v28);
          CPile::DecreaseUnforeseen((CPile *)v14, 1);
          result = (_BYTE *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v24);
        }
        break;
      case 6:
        IMovingEntity::SetDistance(a2, 0);
        result = (_BYTE *)(*(int (__thiscall **)(_BYTE *, IMovingEntity *))(*(_DWORD *)this + 16))(this, a2);
        break;
      default:
        if ( debug != 0 && DEBUG_FLAGS[dword_415212C] != 0 )
        {
          v15 = ((int (__stdcall *)())IEntity::ID)();
          result = (_BYTE *)BBSupportTracePrintF(0, "HouseWorkerRole nr %u - LogicUpdate unknown task", v15);
        }
        break;
    }
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
  if ( v9 != 0 )
  {
    if ( v9 == 4 )
    {
      v7 = IAnimatedEntity::Frame(a2);
      v6 = *((unsigned __int16 *)this + 4);
      if ( v7 > v6 )
      {
        return (CHouseWorkerRole *)((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(v7 - v6);
      }
    }
    else
    {
      if ( v9 != 5 )
      {
        return result;
      }
      v5 = *((unsigned __int16 *)this + 4) + IAnimatedEntity::Frame(a2);
      if ( v5 < *((unsigned __int8 *)this + 7) )
      {
        return (CHouseWorkerRole *)((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(v5);
      }
      if ( *((_BYTE *)this + 7) != 0 )
      {
        return (CHouseWorkerRole *)((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(*((_BYTE *)this + 7) - 1);
      }
    }
    return (CHouseWorkerRole *)((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(0);
  }
  v3 = IAnimatedEntity::Frame(a2);
  ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)((*((unsigned __int16 *)this + 4) + v3) % *((unsigned __int8 *)this + 7));
  if ( IAnimatedEntity::Frame(a2) == 0 && *((unsigned __int8 *)this + 7) > 1u )
  {
    ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
  }
  v4 = *((unsigned __int16 *)this + 4);
  for ( i = 0;
        ;
        i = (CHouseWorkerRole *)((char *)i + 1) )
  {
    result = i;
    if ( (int)i >= v4 )
    {
      break;
    }
    *((float *)this + 9) = *((float *)this + 9) + *((float *)this + 11);
    *((float *)this + 10) = *((float *)this + 10) + *((float *)this + 12);
  }
  return result;
}


// address=[0x1576430]
// Decompiled from int __stdcall CHouseWorkerRole::PostLoadInit(IEntity *a1)
void  CHouseWorkerRole::PostLoadInit(class CSettler * a1) {
  
  return ((int (__cdecl *)(CPropertySet *))CWarMap::AddEntity)((CPropertySet *)a1);
}


// address=[0x1576450]
// Decompiled from char *__thiscall CHouseWorkerRole::CHouseWorkerRole(char *this, int a2)
 CHouseWorkerRole::CHouseWorkerRole(std::istream & a2) {
  
  unsigned int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole((ISettlerRole *)this, (struct std::istream *)a2);
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
  operator^<float>(a2, (int)(v5 + 44));
  operator^<float>(a2, (int)(v5 + 48));
  v6 = -1;
  return v5;
}


// address=[0x1576520]
// Decompiled from int __thiscall CHouseWorkerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CHouseWorkerRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store((ISettlerRole *)this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, (unsigned int *)&v3);
  operator^<float>(a2, (float *)&v4[11]);
  return operator^<float>(a2, (float *)&v4[12]);
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
// Decompiled from int __cdecl CHouseWorkerRole::Load(struct std::istream *a1)
class CHouseWorkerRole * __cdecl CHouseWorkerRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CHouseWorkerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bee4]
// [Decompilation failed for static unsigned long CHouseWorkerRole::m_iClassID]

// address=[0x1576580]
// Decompiled from ISettlerRole *__thiscall CHouseWorkerRole::~CHouseWorkerRole(ISettlerRole *this)
 CHouseWorkerRole::~CHouseWorkerRole(void) {
  
  this->__vftable = (ISettlerRole_vtbl *)&CHouseWorkerRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x15765a0]
// Decompiled from int __thiscall CHouseWorkerRole::GetNextJob(CHouseWorkerRole *this, struct CSettler *a2)
void  CHouseWorkerRole::GetNextJob(class CSettler * a2) {
  
  int result; // eax

  IMovingEntity::IncToDoListIter(a2);
  result = IMovingEntity::IsEndIter(a2);
  if ( (_BYTE)result == 0 )
  {
    return (*(int (__thiscall **)(CHouseWorkerRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
  }
  *((_BYTE *)this + 4) = 17;
  return result;
}


// address=[0x15765e0]
// Decompiled from void __thiscall CHouseWorkerRole::TakeJob(ISettlerRole *this, struct CSettler *a2)
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
  ActualTask = IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(v21, a2, ActualTask);
  v18 = v21->m_iTask;
  switch ( v18 )
  {
    case 0:
      if ( v21->CheckHome(v21, a2) != 0 )
      {
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
        v17 = (float)v21->m_iDestinationOffsetY * 12.0;
        v14 = (float)((float)v21->m_iDestinationOffsetX * 24.0) - v17;
        v16 = v14 - v21->m_fOffsetX;
        v19 = v17 - v21->m_fOffsetY;
        v13 = abs(v19);
        v11 = (int)(float)((float)(v13 * 0.083333336) + 0.5);
        v12 = abs(v16 - v19);
        v10 = (int)((float)(v12 * 0.041666668) + 0.5);
        v20 = 9 * *BB::Max<int>(&v10, &v11);
        if ( v20 < 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 550, "iJobCounter >= 0") == 1 )
        {
          __debugbreak();
        }
        if ( v20 >= 128 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 551, "iJobCounter < 128") == 1 )
        {
          __debugbreak();
        }
        v21->m_iWalkspeed = v20;
        if ( v20 <= 0 )
        {
          v21[1].__vftable = 0;
          *(_DWORD *)&v21[1].m_iTask = 0;
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
        }
        else
        {
          v15 = 1.0 / (float)v20;
          *(float *)&v21[1].__vftable = v16 * v15;
          *(float *)&v21[1].m_iTask = v19 * v15;
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(9);
        }
      }
      break;
    case 1:
      if ( v21->CheckHome(v21, a2) != 0 )
      {
        goto LABEL_14;
      }
      break;
    case 2:
      if ( v21->CheckHome(v21, a2) != 0 )
      {
        if ( v21->m_iWalkspeed <= 31 )
        {
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v21->m_iWalkspeed);
        }
        else
        {
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
        }
      }
      break;
    case 3:
      if ( v21->CheckHome(v21, a2) != 0 )
      {
LABEL_14:
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v21->m_uCycleFrames - 1);
      }
      break;
    case 4:
      if ( v21->CheckHome(v21, a2) != 0 )
      {
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(v21->m_uCycleFrames - 1);
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v21->m_iWalkspeed / 2);
      }
      break;
    case 5:
      if ( v21->CheckHome(v21, a2) != 0 )
      {
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v21->m_iWalkspeed / 2);
      }
      break;
    case 10:
      ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
      v8 = v21->m_iDestinationOffsetX + Y16X16::UnpackXFast(v21->m_iDestinationPosition);
      v9 = v21->m_iDestinationOffsetY + Y16X16::UnpackYFast(v21->m_iDestinationPosition);
      v21->m_iDestinationPosition = Y16X16::PackXYFast(v8, v9);
      IMovingEntity::WalkToXY(a2, v21->m_iDestinationPosition, 0);
      v21->m_iTask = 6;
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
      v21->Go(v21, a2);
      break;
    case 17:
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
      v4 = CStateGame::Rand(g_pGame);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v4 % 4 + 1);
      break;
    case 24:
      if ( v21->CheckHome(v21, a2) != 0 )
      {
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
        IEntity::ClearFlagBits(a2, ENTITY_FLAG_Visible);
        v21->m_fOffsetX = 0.0;
        v21->m_fOffsetY = 0.0;
        v7 = ((int (__stdcall *)())IEntity::ID)();
        v5 = (CBuilding *)((CBuilding *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(v21->m_uHomeEntityId);
        CBuilding::SettlerEnter(v5, v7);
      }
      break;
    default:
      if ( debug != 0 && DEBUG_FLAGS[dword_415212C] != 0 )
      {
        v6 = ((int (__stdcall *)())IEntity::ID)();
        BBSupportTracePrintF(0, "HouseWorkerRole nr %u - TakeJob unknown task", v6);
      }
      break;
  }
}


// address=[0x1576b00]
// Decompiled from int __thiscall CHouseWorkerRole::Init(_DWORD *this, IEntity *a2)
void  CHouseWorkerRole::Init(class CSettler * a2) {
  
  int result; // eax

  result = ((int (__cdecl *)(CPropertySet *))CWarMap::AddEntity)((CPropertySet *)a2);
  *(this + 9) = 0;
  *(this + 10) = 0;
  return result;
}


// address=[0x1576b30]
// Decompiled from EntityFlag __thiscall CHouseWorkerRole::ConvertEventIntoGoal(ISettlerRole *this, struct CSettler *a2, _DWORD *a3)
void  CHouseWorkerRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  EntityFlag result; // eax
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
      result = this->CheckHome(this, a2);
      if ( (_BYTE)result != 0 )
      {
        v13 = IEntity::Type(a2);
        v4 = IEntity::Race(a2);
        CSettlerMgr::GetSettlerInfo(v4, v13);
        v17 = (CMFCToolBarButton *)((CMFCToolBarButton *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(a3[3]);
        this->m_uHomeEntityId = ((int (__stdcall *)())IEntity::ID)();
        v5 = CBuilding::DoorPackedXY((CBuilding *)v17);
        ISettlerRole::NewDestination(this, a2, v5, 0);
        v14 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
        v12 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
        v6 = IEntity::Race(a2);
        v7 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v6, v12);
        result = a2->NewToDoList(a2, v7, v14);
      }
      break;
    case 3:
      if ( IEntity::FlagBits(a2, ENTITY_FLAG_MagicInvisible) == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\HouseWorkerRole.cpp", 788, "_pSettler->FlagBits(ENTITY_FLAG_MAGIC_INVISIBLE)!=0") == 1 )
      {
        __debugbreak();
      }
      result = this->CheckHome(this, a2);
      if ( (_BYTE)result != 0 )
      {
        v15 = a3[4];
        v8 = IEntity::Race(a2);
        v9 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v8, v15);
        a2->NewToDoList(a2, v9, v15);
        result = ((int (__thiscall *)(ISettlerRole *, _DWORD))this->SetEntity)(this, a3[5]);
      }
      break;
    case 4:
      result = ((int (__thiscall *)(ISettlerRole *, struct CSettler *))this->CheckHome)(this, a2);
      if ( (_BYTE)result != 0 )
      {
        this->SetEntity(this, a3[5]);
        v16 = a3[4];
        v10 = IEntity::Race(a2);
        v11 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v10, v16);
        result = a2->NewToDoList(a2, v11, v16);
      }
      break;
    case 9:
      result = ((int (__thiscall *)(ISettlerRole *, struct CSettler *, _DWORD))this->SetFree)(this, a2, a3[5]);
      break;
    default:
      result = IEntity::FlagBits(a2, ENTITY_FLAG_Registered);
      if ( result == 0 )
      {
        CTrace::Print("ConvertEventIntoGoal HouseWorker - unknown event %u", a3[1]);
        result = ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
      }
      break;
  }
  return result;
}


// address=[0x1587a80]
// Decompiled from CHouseWorkerRole *__thiscall CHouseWorkerRole::CHouseWorkerRole(CHouseWorkerRole *this)
 CHouseWorkerRole::CHouseWorkerRole(void) {
  
  ISettlerRole::ISettlerRole((ISettlerRole *)this);
  *(_DWORD *)this = &CHouseWorkerRole::_vftable_;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  return this;
}


