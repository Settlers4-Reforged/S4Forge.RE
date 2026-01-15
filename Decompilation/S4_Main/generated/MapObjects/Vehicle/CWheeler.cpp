#include "CWheeler.h"

// Definitions for class CWheeler

// address=[0x1539640]
// Decompiled from void __thiscall CWheeler::~CWheeler(CWheeler *this)
 CWheeler::~CWheeler(void) {
  
  CVehicle::~CVehicle(this);
}


// address=[0x153fdc0]
// Decompiled from void __thiscall CWheeler::FillDialog(CWheeler *this, bool a2)
void  CWheeler::FillDialog(bool) {
  
  ;
}


// address=[0x153feb0]
// Decompiled from void __thiscall CWheeler::UnloadToPosition(CWheeler *this, int a2)
void  CWheeler::UnloadToPosition(int) {
  
  ;
}


// address=[0x159bb30]
// Decompiled from int __thiscall CWheeler::RemoveFromWorld(CWheeler *this)
void  CWheeler::RemoveFromWorld(void) {
  
  int v1; // eax
  int result; // eax

  v1 = IEntity::PackedXY(this);
  result = (*(int (__thiscall **)(CWheeler *, int))(*(_DWORD *)this + 200))(this, v1);
  *((_DWORD *)this + 6) = 0;
  return result;
}


// address=[0x15afef0]
// Decompiled from int __thiscall CWheeler::Delete(CWheeler *this)
void  CWheeler::Delete(void) {
  
  void **v1; // eax
  int v2; // eax
  int v4; // [esp+0h] [ebp-8h]

  if ( *((int *)this + 43) <= 0 )
    return CVehicle::Delete(this);
  v1 = (void **)CMapObjectMgr::EntityPtr(*((_DWORD *)this + 43));
  if ( !j____RTDynamicCast(v1, 0, &IEntity__RTTI_Type_Descriptor_, &CFerryShip__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Wheeler.cpp",
         176,
         "dynamic_cast<CFerryShip*>(g_pMapObjectMgr->EntityPtr(m_iFerryID))!= NULL") == 1 )
  {
    __debugbreak();
  }
  v4 = CMapObjectMgr::EntityPtr(*((_DWORD *)this + 43));
  if ( !v4 )
    return CVehicle::Delete(this);
  v2 = IEntity::ID();
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 124))(v4, v2);
  return CVehicle::Delete(this);
}


// address=[0x15aff90]
// Decompiled from void *__thiscall CWheeler::GetGfxInfos(int this)
struct SGfxObjectInfo *  CWheeler::GetGfxInfos(void) {
  
  int v1; // eax
  unsigned int v3; // [esp+0h] [ebp-10h]
  char v4; // [esp+4h] [ebp-Ch]
  char v5; // [esp+8h] [ebp-8h]

  if ( (unsigned __int8)CInputProcessor::IsBoxSelection(&g_cInputProcessor) )
    IAnimatedEntity::BoxSelection();
  CVehicle::Update(this);
  if ( (unsigned __int8)CVehicle::IsTurning(this) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)this + 184))(this);
  }
  else
  {
    v3 = IEntity::Race((_BYTE *)this);
    CGfxManager::GetVehicleGfxInfo(
      (CGfxManager *)g_pGfxManager,
      (struct SGfxObjectInfo *)&IEntity::m_sGfxInfo,
      v3,
      *(unsigned __int16 *)(this + 38),
      *(char *)(this + 68),
      *(unsigned __int8 *)(this + 36),
      0,
      0);
  }
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  byte_40FE51B = CPlayerManager::Color(v1);
  byte_40FE51D = *(_BYTE *)(this + 68);
  byte_40FE51C = *(_BYTE *)(this + 69);
  byte_40FE518 = 4;
  byte_40FE51A = IEntity::IsVisible((_DWORD *)this);
  if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)&dword_F29144[220079]) )
    dword_40FE2AC = 65534 - *(unsigned __int16 *)(this + 124) * *(unsigned __int16 *)(this + 128);
  if ( IEntity::FlagBits((_DWORD *)this, Selected) )
  {
    if ( IEntity::FlagBits((_DWORD *)this, Selected) )
      v5 = 73;
    else
      v5 = 0;
    byte_40FE266 = v5;
  }
  else if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x400u) )
  {
    if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x400u) )
      v4 = 90;
    else
      v4 = 0;
    byte_40FE266 = v4;
  }
  return &IEntity::m_sGfxInfo;
}


// address=[0x15b0110]
// Decompiled from void __thiscall CWheeler::ConvertEventIntoGoal(CWheeler *this, struct CEntityEvent *a2)
void  CWheeler::ConvertEventIntoGoal(class CEntityEvent *) {
  
  int v2; // eax
  void **v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char v9; // al
  int v10; // [esp-8h] [ebp-30h]
  int v11; // [esp+0h] [ebp-28h]
  int v12; // [esp+4h] [ebp-24h]
  IEntity *VehiclePtr; // [esp+8h] [ebp-20h]
  int v14; // [esp+Ch] [ebp-1Ch]
  CPropertySheet *FerryShipAt; // [esp+10h] [ebp-18h]
  int v16; // [esp+14h] [ebp-14h]
  int v17; // [esp+18h] [ebp-10h]
  int v18; // [esp+1Ch] [ebp-Ch]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 241, "_pEvent!=NULL") == 1 )
    __debugbreak();
  if ( a2 )
  {
    switch ( *((_DWORD *)a2 + 1) )
    {
      case 7:
        IEntity::SetFlagBits(this, Selectable);
        IEntity::ClearFlagBits(this, OnBoard);
        v10 = IEntity::Y(this);
        v8 = IEntity::X(this);
        v9 = CVehicle::NewDestination(this, v8, v10, 0);
        CVehicle::NotifyCallTakeJob(v9);
        *((_DWORD *)this + 43) = 0;
        *((_DWORD *)this + 42) = 0;
        break;
      case 0x11:
        if ( *((_DWORD *)a2 + 2) != 13 || *((int *)this + 43) > 0 )
          goto CWheeler__ConvertEventIntoGoal___def_19B016F;
        v11 = Y16X16::UnpackXFast(*((_DWORD *)a2 + 5));
        v12 = Y16X16::UnpackYFast(*((_DWORD *)a2 + 5));
        FerryShipAt = (CPropertySheet *)CVehicleMgr::GetFerryShipAt(v11, v12);
        if ( !FerryShipAt )
        {
          if ( *((int *)this + 43) > 0 )
          {
            v3 = (void **)CMapObjectMgr::EntityPtr(*((_DWORD *)this + 43));
            if ( !j____RTDynamicCast(v3, 0, &IEntity__RTTI_Type_Descriptor_, &CFerryShip__RTTI_Type_Descriptor_, 0)
              && BBSupportDbgReport(
                   2,
                   "MapObjects\\Wheeler.cpp",
                   274,
                   "dynamic_cast<CFerryShip*>(g_pMapObjectMgr->EntityPtr( m_iFerryID ))!= NULL") == 1 )
            {
              __debugbreak();
            }
            v18 = CMapObjectMgr::EntityPtr(*((_DWORD *)this + 43));
            if ( v18 )
            {
              v4 = IEntity::ID();
              (*(void (__thiscall **)(int, int))(*(_DWORD *)v18 + 124))(v18, v4);
              *((_DWORD *)this + 43) = 0;
              *((_DWORD *)this + 42) = 0;
            }
          }
          goto CWheeler__ConvertEventIntoGoal___def_19B016F;
        }
        v2 = IEntity::EntityId((unsigned __int16 *)this);
        CFerryShip::Request(FerryShipAt, v2);
        break;
      case 0x18:
        (*(void (__thiscall **)(CWheeler *, _DWORD))(*(_DWORD *)this + 224))(this, *((_DWORD *)a2 + 3));
        break;
      case 0x19:
        v14 = *((_DWORD *)a2 + 3);
        v16 = *((_DWORD *)a2 + 4);
        v17 = *((_DWORD *)a2 + 5);
        v5 = IEntity::ObjType((unsigned __int8 *)this);
        if ( CVehicleMgr::IsPositionFreeForVehicle((CVehicleMgr *)&g_cVehicleMgr, v16, v17, v5) )
        {
          v6 = Y16X16::PackXYFast(v16, v17);
          (*(void (__thiscall **)(CWheeler *, int))(*(_DWORD *)this + 196))(this, v6);
          IEntity::SetPosition((IEntity *)this, v16, v17);
          IEntity::SetFlagBits(this, Selectable);
          IEntity::ClearFlagBits(this, OnBoard);
          IEntity::SetFlagBits(this, Visible);
          *((_DWORD *)this + 42) = 0;
        }
        else
        {
          if ( !v14 && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 303, "iFerryID!=0") == 1 )
            __debugbreak();
          VehiclePtr = (IEntity *)CVehicleMgr::GetVehiclePtr(v14);
          if ( !VehiclePtr && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 305, "pFerry!=NULL") == 1 )
            __debugbreak();
          *((_DWORD *)this + 42) = 0;
          v7 = IEntity::ID();
          CFerryShip::EmergencyReload(VehiclePtr, v7);
        }
        break;
      default:
CWheeler__ConvertEventIntoGoal___def_19B016F:
        CVehicle::ConvertEventIntoGoal(this, a2);
        break;
    }
  }
}


// address=[0x15b0480]
// Decompiled from int __thiscall CWheeler::RepairBuildingInRange(CWheeler *this)
int  CWheeler::RepairBuildingInRange(void) {
  
  unsigned __int16 *v2; // [esp+0h] [ebp-24h]
  int v3; // [esp+4h] [ebp-20h]
  int v4; // [esp+8h] [ebp-1Ch]
  int v5; // [esp+Ch] [ebp-18h]
  int v6; // [esp+10h] [ebp-14h]
  int v7; // [esp+14h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v5 = IEntity::X(this);
  v4 = IEntity::Y(this);
  for ( i = 0; i < 721; ++i )
  {
    v6 = v5 + SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    v7 = v4 + SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
    if ( (unsigned __int8)CWorldManager::InWorld(v6, v7) )
    {
      v3 = CWorldManager::Index(v6, v7);
      v9 = CWorldManager::BuildingId(v3);
      if ( v9 )
      {
        v2 = (unsigned __int16 *)CBuildingMgr::operator[](v9);
        if ( IEntity::Type(v2) == 23 )
          return v9;
      }
    }
  }
  return 0;
}


// address=[0x15b0560]
// Decompiled from CWheeler *__thiscall CWheeler::RepairAt(CWheeler *this, int a2)
void  CWheeler::RepairAt(int) {
  
  CWheeler *result; // eax
  char v3; // dl

  if ( CWheeler::RepairBuildingInRange(this) != a2
    && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 562, "RepairBuildingInRange()==_iAtBuildingID") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 25)
    && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 563, "m_pVehicleProperties!= NULL") == 1 )
  {
    __debugbreak();
  }
  result = (CWheeler *)(*(int (__thiscall **)(CWheeler *))(*(_DWORD *)this + 40))(this);
  if ( (unsigned int)result >= *(_DWORD *)(*((_DWORD *)this + 25) + 48) )
    return result;
  v3 = CStaticConfigVarInt::operator int(&unk_415A600) + *((_BYTE *)this + 33);
  result = this;
  *((_BYTE *)this + 33) = v3;
  return result;
}


// address=[0x15b0600]
// Decompiled from _DWORD *__thiscall CWheeler::SetObserverTarget(_DWORD *this, int a2, int a3)
void  CWheeler::SetObserverTarget(enum T_OBSERVER_TARGET,int) {
  
  _DWORD *result; // eax
  unsigned int v4; // ecx

  if ( a2 )
  {
    if ( BBSupportDbgReport(1, "MapObjects\\Wheeler.cpp", 598, "CWheeler::SetObserverTarget(): Invalid target type!") == 1 )
      __debugbreak();
    return 0;
  }
  else
  {
    this[43] = a3;
    result = this;
    if ( a3 <= 0 )
      v4 = this[5] & 0xFFFFFFDF;
    else
      v4 = this[5] | 0x20;
    this[5] = v4;
  }
  return result;
}


// address=[0x15b0680]
// Decompiled from int __thiscall CWheeler::GetObserverTarget(_DWORD *this, int a2)
int  CWheeler::GetObserverTarget(enum T_OBSERVER_TARGET) {
  
  if ( a2 )
    return 0;
  else
    return this[43];
}


// address=[0x153a640]
// Decompiled from void __thiscall CWheeler::Unload(CWheeler *this)
void  CWheeler::Unload(void) {
  
  ;
}


// address=[0x15b06b0]
// Decompiled from CWheeler *__thiscall CWheeler::CWheeler(  CWheeler *this,  int a2,  int a3,  int a4,  int a5,  __int16 a6,  unsigned int a7,  bool a8)
 CWheeler::CWheeler(int,int,int,int,int,int,bool) {
  
  int v9; // [esp+8h] [ebp-14h]

  if ( a2 == -1 )
    v9 = 1;
  else
    v9 = a3;
  if ( a2 == -1 )
    CVehicle::CVehicle(this, 3, v9, a4, a5, a6, a7, a8);
  else
    CVehicle::CVehicle(this, a2, v9, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CWheeler::_vftable_;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 44) = 0;
  if ( *(_DWORD *)(*((_DWORD *)this + 25) + 8) != 4
    && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 99, "m_pVehicleProperties->m_uObjectType == CATAPULT_OBJ") == 1 )
  {
    __debugbreak();
  }
  if ( a2 < 0 )
  {
    IEntity::ClearFlagBits(this, Visible);
    IEntity::SetFlagBits(this, OnBoard);
  }
  else
  {
    CWheeler::PlaceVehicle(this, *((_DWORD *)this + 6));
    CWarMap::AddEntity(this);
  }
  return this;
}


// address=[0x15b07e0]
// Decompiled from _DWORD *__thiscall CWheeler::CWheeler(_DWORD *this, int a2)
 CWheeler::CWheeler(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CVehicle::CVehicle(this, a2);
  v6 = 0;
  *v5 = &CWheeler::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CWheeler");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v5 + 42));
  operator^<int>(a2, (int)(v5 + 43));
  operator^<int>(a2, (int)(v5 + 44));
  v6 = -1;
  return v5;
}


// address=[0x15b08d0]
// Decompiled from int __thiscall CWheeler::Store(int *this, struct std::ostream *a2)
void  CWheeler::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CVehicle::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<int>((int)a2, v4 + 42);
  operator^<int>((int)a2, v4 + 43);
  return operator^<int>((int)a2, v4 + 44);
}


// address=[0x15b0950]
// Decompiled from char __thiscall CWheeler::WalkDir(CWheeler *this, char a2)
void  CWheeler::WalkDir(int) {
  
  int v2; // esi
  CWalking *v3; // eax
  int v4; // eax
  char result; // al
  int v6; // [esp-4h] [ebp-24h]
  int v7; // [esp+8h] [ebp-18h]
  struct CVehicle *VehiclePtr; // [esp+Ch] [ebp-14h]
  int v9; // [esp+10h] [ebp-10h]
  struct CPaneContainer *v10; // [esp+14h] [ebp-Ch]
  Y16X16 *v11; // [esp+18h] [ebp-8h]

  v11 = (Y16X16 *)(a2 & 0xF);
  if ( (unsigned int)v11 < 6 )
  {
    if ( (a2 & 0x20) != 0
      && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 344, "( _iWalkResult & WALK_RESULT_FLAG_GOAL_REACHED ) == 0") == 1 )
    {
      __debugbreak();
    }
    v9 = IEntity::PackedXY(this);
    IEntity::WorldIdx();
    v2 = IEntity::PackedXY(this);
    v10 = (struct CPaneContainer *)(Y16X16::NeighborModifier(v11) + v2);
    v7 = CWorldManager::Index((int)v10);
    (*(void (__thiscall **)(CWheeler *, int))(*(_DWORD *)this + 200))(this, v9);
    v3 = (CWalking *)std::auto_ptr<CWalking>::operator->(v7);
    if ( CWalking::IsFree(v3, v6) )
    {
      (*(void (__thiscall **)(CWheeler *, struct CPaneContainer *))(*(_DWORD *)this + 196))(this, v10);
      if ( v11 != (Y16X16 *)*((char *)this + 68) )
        CVehicle::InitTurn(this, (int)v11);
      IEntity::SetPosition(this, v10);
      IMovingEntity::InitDistance(this);
      CWarMap::NotifyMove(this, v9);
    }
    else
    {
      (*(void (__thiscall **)(CWheeler *, int))(*(_DWORD *)this + 196))(this, v9);
      a2 |= 0x88u;
    }
  }
  if ( (a2 & 0x20) != 0 )
  {
    if ( *((_DWORD *)this + 43) )
    {
      if ( IEntity::PackedXY(this) == *((_DWORD *)this + 42) )
      {
        VehiclePtr = CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 43));
        if ( VehiclePtr )
        {
          v4 = IEntity::ID();
          (*(void (__thiscall **)(struct CVehicle *, int))(*(_DWORD *)VehiclePtr + 128))(VehiclePtr, v4);
          *((_DWORD *)this + 43) = 0;
        }
      }
    }
  }
  result = a2;
  *((_BYTE *)this + 104) = a2;
  return result;
}


// address=[0x15b0af0]
// Decompiled from int __thiscall CWheeler::PlaceVehicle(CWheeler *this, int a2)
void  CWheeler::PlaceVehicle(int) {
  
  int result; // eax
  __int16 v3; // [esp+0h] [ebp-14h]
  unsigned int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 404, "g_cWorld.InWorldPackedXY( _iXY )") == 1 )
  {
    __debugbreak();
  }
  v5 = CWorldManager::Index(a2);
  if ( (unsigned __int8)CWorldManager::IsBlockedLand(v5)
    && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 408, "!g_cWorld.IsBlockedLand( iWorldIdx )") == 1 )
  {
    __debugbreak();
  }
  if ( CWorldManager::SettlerId(v5)
    && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 409, "g_cWorld.SettlerId( iWorldIdx ) == 0") == 1 )
  {
    __debugbreak();
  }
  v3 = IEntity::ID();
  result = CWorldManager::SetMapObjectId(v5, v3);
  for ( i = 0; i < 6; ++i )
  {
    v4 = v5 + CWorldManager::NeighborRelIndex(i);
    if ( !CWorldManager::InWorld(v4)
      && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 419, "g_cWorld.InWorld( iNeighborWorldIdx )") == 1 )
    {
      __debugbreak();
    }
    if ( (unsigned __int8)CWorldManager::IsBlockedLand(v4)
      && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 420, "!g_cWorld.IsBlockedLand( iNeighborWorldIdx )") == 1 )
    {
      __debugbreak();
    }
    if ( CWorldManager::MapObjectId(v4) )
    {
      if ( BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 421, "g_cWorld.MapObjectId( iNeighborWorldIdx ) == 0") == 1 )
        __debugbreak();
    }
    result = CWorldManager::SetMapObjectId(v4, i + 1);
  }
  return result;
}


// address=[0x15b0ca0]
// Decompiled from int __thiscall CWheeler::RemoveVehicle(CWheeler *this, int a2)
void  CWheeler::RemoveVehicle(int) {
  
  int result; // eax
  int v3; // [esp+8h] [ebp-Ch]
  unsigned int v4; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 436, "g_cWorld.InWorldPackedXY( _iXY )") == 1 )
  {
    __debugbreak();
  }
  v3 = CWorldManager::Index(a2);
  if ( (unsigned __int8)CWorldManager::IsBlockedLand(v3)
    && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 440, "!g_cWorld.IsBlockedLand( iWorldIdx )") == 1 )
  {
    __debugbreak();
  }
  IEntity::ID();
  result = CWorldManager::SetMapObjectId(v3, 0);
  for ( i = 0; i < 6; ++i )
  {
    v4 = v3 + CWorldManager::NeighborRelIndex(i);
    if ( !CWorldManager::InWorld(v4)
      && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 451, "g_cWorld.InWorld( iNeighborWorldIdx )") == 1 )
    {
      __debugbreak();
    }
    if ( (unsigned __int8)CWorldManager::IsBlockedLand(v4)
      && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 452, "!g_cWorld.IsBlockedLand( iNeighborWorldIdx )") == 1 )
    {
      __debugbreak();
    }
    if ( CWorldManager::MapObjectId(v4) != i + 1
      && BBSupportDbgReport(
           2,
           "MapObjects\\Wheeler.cpp",
           453,
           "g_cWorld.MapObjectId( iNeighborWorldIdx ) == WHEELER_PSEUDO_ID + i") == 1 )
    {
      __debugbreak();
    }
    result = CWorldManager::SetMapObjectId(v4, 0);
  }
  return result;
}


// address=[0x15b0e20]
// Decompiled from int __thiscall CWheeler::OnComeToFerry(CWheeler *this, int a2)
void  CWheeler::OnComeToFerry(int) {
  
  void **VehiclePtr; // eax
  int result; // eax
  int v4; // eax
  CWalking *v5; // eax
  int v6; // eax
  char v7; // al
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-8h] [ebp-18h]
  int v13; // [esp-8h] [ebp-18h]
  int v14; // [esp-4h] [ebp-14h]
  int v15; // [esp-4h] [ebp-14h]
  int v16; // [esp-4h] [ebp-14h]
  int v17; // [esp+0h] [ebp-10h]
  int v18; // [esp+4h] [ebp-Ch]
  int v19; // [esp+8h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Wheeler.cpp", 193, "_iFerryID > 0") == 1 )
    __debugbreak();
  VehiclePtr = (void **)CVehicleMgr::GetVehiclePtr(a2);
  if ( !j____RTDynamicCast(VehiclePtr, 0, &CVehicle__RTTI_Type_Descriptor_, &CFerryShip__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Wheeler.cpp",
         196,
         "dynamic_cast<CFerryShip*>(g_cVehicleMgr.GetVehiclePtr( _iFerryID ))!= NULL") == 1 )
  {
    __debugbreak();
  }
  result = (int)CVehicleMgr::GetVehiclePtr(a2);
  v18 = result;
  if ( !result )
    return result;
  v19 = result;
  v14 = IEntity::ID();
  v4 = IEntity::ObjType((unsigned __int8 *)this);
  result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v19 + 140))(v19, v4, v14);
  *((_DWORD *)this + 42) = result;
  if ( !*((_DWORD *)this + 42) )
    return result;
  v17 = CWorldManager::Index(*((_DWORD *)this + 42));
  v5 = (CWalking *)std::auto_ptr<CWalking>::operator->(v17);
  result = CWalking::IsFree(v5, v15);
  if ( !(_BYTE)result )
    return result;
  v12 = Y16X16::UnpackYFast(*((_DWORD *)this + 42));
  v6 = Y16X16::UnpackXFast(*((_DWORD *)this + 42));
  v7 = CVehicle::NewDestination(this, v6, v12, 0);
  CVehicle::NotifyCallTakeJob(v7);
  v8 = IEntity::ID();
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v18 + 164))(v18, v8);
  v9 = IEntity::ID();
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v9);
  if ( IEntity::FlagBits(this, Selected) )
  {
    v10 = IEntity::ID();
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, v10);
  }
  IEntity::ClearFlagBits(this, Selectable|Selected);
  v16 = IEntity::ID();
  v13 = IEntity::ID();
  v11 = IEntity::OwnerId((unsigned __int8 *)this);
  return (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
           off_3D7A3D8,
           18,
           v11,
           v13,
           v16);
}


// address=[0x37c1a4c]
// [Decompilation failed for static int const CWheeler::REPAIT_BUILDING_SCAN_RANGE]

// address=[0x37c1a50]
// [Decompilation failed for static int const CWheeler::FULL_UPDATE_DELAY]

