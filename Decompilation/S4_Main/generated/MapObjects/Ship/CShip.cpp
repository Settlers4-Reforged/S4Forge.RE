#include "CShip.h"

// Definitions for class CShip

// address=[0x159d4e0]
// Decompiled from void __thiscall CShip::VehicleLogicUpdate(CShip *this)
void  CShip::VehicleLogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-18h]
  int v6; // [esp+0h] [ebp-18h]
  int v7; // [esp+4h] [ebp-14h]
  unsigned int TickCounter; // [esp+8h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-Ch]
  char v10; // [esp+10h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( *((_DWORD *)this + 42) + 20 < TickCounter )
  {
    v9 = CShip::RepairBuildingInRange(this);
    if ( v9 )
      CShip::RepairAt(this, v9);
    *((_DWORD *)this + 42) = TickCounter;
  }
  v10 = *((_BYTE *)this + 107);
  switch ( v10 )
  {
    case 6:
      v6 = std::auto_ptr<CWalking>::operator->(v5);
      v3 = IEntity::PackedXY(this);
      v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 12))(v6, v3);
      CVehicle::WalkDirAndRegister(this, v4, 0);
      break;
    case 17:
      v7 = std::auto_ptr<CWalking>::operator->(v5);
      v1 = IEntity::PackedXY(this);
      v2 = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v7 + 16))(v7, v1, 0);
      CVehicle::WalkDirAndRegister(this, v2, 0);
      break;
    case 27:
      CVehicle::GetNextJob(this);
      break;
  }
}


// address=[0x159d5c0]
// Decompiled from void *__thiscall CShip::GetGfxInfos(int this)
struct SGfxObjectInfo *  CShip::GetGfxInfos(void) {
  
  int v1; // eax
  char v3; // [esp+4h] [ebp-1Ch]
  char v4; // [esp+8h] [ebp-18h]
  unsigned int v5; // [esp+Ch] [ebp-14h]
  unsigned int v6; // [esp+10h] [ebp-10h]
  unsigned int v7; // [esp+18h] [ebp-8h]

  if ( (unsigned __int8)CInputProcessor::IsBoxSelection(&g_cInputProcessor) )
    IAnimatedEntity::BoxSelection();
  CVehicle::Update(this);
  if ( (unsigned __int8)CVehicle::IsTurning(this) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)this + 184))(this);
  }
  else
  {
    v5 = IEntity::Race((_BYTE *)this);
    v7 = *(_DWORD *)(*(_DWORD *)(this + 100) + 24);
    if ( (*(_BYTE *)(this + 104) & 8) != 0 )
    {
      if ( *(unsigned __int16 *)(this + 38) == v7 )
        v6 = *(_DWORD *)(*(_DWORD *)(this + 100) + 28);
      else
        v6 = *(unsigned __int16 *)(this + 38);
      CGfxManager::GetVehicleGfxInfo(
        (CGfxManager *)g_pGfxManager,
        (struct SGfxObjectInfo *)&IEntity::m_sGfxInfo,
        v5,
        v6,
        *(char *)(this + 68),
        0,
        0,
        0);
    }
    else
    {
      CGfxManager::GetVehicleGfxInfo(
        (CGfxManager *)g_pGfxManager,
        (struct SGfxObjectInfo *)&IEntity::m_sGfxInfo,
        v5,
        *(_DWORD *)(*(_DWORD *)(this + 100) + 28),
        *(char *)(this + 68),
        0,
        v7,
        *(unsigned __int8 *)(this + 36));
    }
  }
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  byte_40FE51B = CPlayerManager::Color(v1);
  byte_40FE51D = *(_BYTE *)(this + 68);
  byte_40FE51C = *(_BYTE *)(this + 69);
  byte_40FE518 = 2;
  byte_40FE51A = IEntity::IsVisible((_DWORD *)this);
  if ( IEntity::FlagBits((_DWORD *)this, EntityFlag_Selected) )
  {
    if ( IEntity::FlagBits((_DWORD *)this, EntityFlag_Selected) )
      v4 = 27;
    else
      v4 = 0;
    byte_40FE266 = v4;
  }
  else if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x400u) )
  {
    if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x400u) )
      v3 = 89;
    else
      v3 = 0;
    byte_40FE266 = v3;
  }
  byte_40FE264 = 0;
  if ( !IEntity::FlagBits((_DWORD *)this, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    dword_40FE2AC = 65534 - *(unsigned __int16 *)(this + 124) * *(unsigned __int16 *)(this + 128);
  return &IEntity::m_sGfxInfo;
}


// address=[0x159d7c0]
// Decompiled from int __cdecl CShip::FindBoardingLocation(int a1, int a2, void *a3)
int __cdecl CShip::FindBoardingLocation(class std::vector<unsigned short,class std::allocator<unsigned short> > const & a1, int a2, struct SBoardingInfo & a3) {
  
  struct IEntity *v3; // eax
  int v4; // eax
  int v6; // [esp+8h] [ebp-20h]
  int v7; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 *v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+14h] [ebp-14h]
  int v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  unsigned __int16 v13; // [esp+26h] [ebp-2h]

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 513, "g_cWorld.InWorldPackedXY(_iShipXY)") == 1 )
  {
    __debugbreak();
  }
  v10 = std::vector<unsigned short>::size(a1);
  if ( v10 <= 0 )
  {
    memset(a3, 0, 0x10u);
    return 0;
  }
  else
  {
    v11 = -1;
    v6 = -1;
    v7 = 0;
    for ( i = 0; i < v10; ++i )
    {
      v9 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
      if ( v9 <= 0 && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 527, "iEntityId > 0") == 1 )
        __debugbreak();
      v8 = (unsigned __int8 *)CMapObjectMgr::Entity(v9);
      if ( IEntity::CheckType((IEntity *)v8, 1, 44) )
      {
        if ( v11 >= 0 )
        {
          if ( IEntity::ObjType(v8) == 4 )
          {
            ++v7;
            if ( v6 < 0 )
              v6 = i;
          }
        }
        else
        {
          v11 = i;
        }
      }
    }
    if ( v11 < 0 )
      v13 = *(_WORD *)std::vector<unsigned short>::operator[](0);
    else
      v13 = *(_WORD *)std::vector<unsigned short>::operator[](v11);
    v3 = CMapObjectMgr::Entity(v13);
    v4 = IEntity::PackedXY(v3);
    return CShip::FindBoardingLocation(v4, a2, a3);
  }
}


// address=[0x159d950]
// Decompiled from int __cdecl CShip::FindBoardingLocation(int a1, int a2, int *a3)
int __cdecl CShip::FindBoardingLocation(int a1, int a2, struct SBoardingInfo & a3) {
  
  Y16X16 *v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp+0h] [ebp-8Ch]
  int v11; // [esp+4h] [ebp-88h]
  int v12; // [esp+8h] [ebp-84h]
  int v13; // [esp+Ch] [ebp-80h] BYREF
  int v14; // [esp+10h] [ebp-7Ch] BYREF
  int v15; // [esp+14h] [ebp-78h]
  int v16; // [esp+18h] [ebp-74h]
  int v17; // [esp+1Ch] [ebp-70h]
  int v18; // [esp+20h] [ebp-6Ch]
  int v19; // [esp+24h] [ebp-68h]
  int j; // [esp+28h] [ebp-64h]
  int i; // [esp+2Ch] [ebp-60h]
  _BYTE v22[88]; // [esp+30h] [ebp-5Ch] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a1)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 573, "g_cWorld.InWorldPackedXY(_iStartXY)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 574, "g_cWorld.InWorldPackedXY(_iShipXY)") == 1 )
  {
    __debugbreak();
  }
  memset(a3, 0, 0x10u);
  if ( (int)CAStarTiling::FindPath(a1, a2, (struct CWaypoints *)v22, 768) <= 0 )
    return 0;
  v3 = (Y16X16 *)CWaypoints::Goal((CWaypoints *)v22);
  Y16X16::UnpackXYFast(v3, &v14, &v13);
  v11 = CWorldManager::Index(v14, v13);
  v19 = -1;
  v16 = -1;
  for ( i = 0; i < 19; ++i )
  {
    v10 = v11 + CWorldManager::SurroundingHexPointRelIndex(i);
    if ( !CWaterFlags::IsBlockedWater(v10) )
    {
      v4 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
      v19 = v14 + v4;
      v5 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
      v16 = v13 + v5;
      break;
    }
  }
  if ( v19 < 0 )
    return 0;
  v15 = -1;
  v12 = -1;
  for ( j = 37; j < 91; ++j )
  {
    v7 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * j]);
    v18 = v19 + v7;
    v8 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * j]);
    v17 = v16 + v8;
    if ( (unsigned __int8)CWorldManager::InWorld(v18, v16 + v8) )
    {
      v9 = CWorldManager::Index(v18, v17);
      if ( !(unsigned __int8)CWorldManager::IsBlockedLand(v9) )
      {
        v15 = v18;
        v12 = v17;
        break;
      }
    }
  }
  if ( v15 < 0 )
    return 0;
  *a3 = v19;
  a3[1] = v16;
  a3[2] = v15;
  a3[3] = v12;
  return 1;
}


// address=[0x159e8f0]
// Decompiled from void __thiscall CShip::FillDialog(CShip *this, bool a2)
void  CShip::FillDialog(bool a2) {
  
  ;
}


// address=[0x159e940]
// Decompiled from void __thiscall CShip::Unload(CShip *this)
void  CShip::Unload(void) {
  
  ;
}


// address=[0x159dbb0]
// Decompiled from CShip *__thiscall CShip::CShip(CShip *this, int a2, int a3, int a4, int a5, WORD a6, unsigned int a7, bool a8)
 CShip::CShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8) {
  
  int v8; // eax
  int v10; // [esp-8h] [ebp-1Ch]

  CVehicle::CVehicle(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CShip::_vftable_;
  *((_DWORD *)this + 42) = 0;
  CShip::PlaceVehicle((IEntity *)this, *((_DWORD *)this + 6));
  if ( a8 )
    return this;
  CWarMap::AddEntity((IEntity *)this);
  v10 = IEntity::Y(this);
  v8 = IEntity::X(this);
  CVehicle::NewDestination((IEntity *)this, v8, v10, 0);
  CShip::TakeJob(this);
  return this;
}


// address=[0x159dc80]
// Decompiled from void __thiscall CShip::~CShip(CShip *this)
 CShip::~CShip(void) {
  
  *(_DWORD *)this = &CShip::_vftable_;
  CVehicle::~CVehicle(this);
}


// address=[0x159dca0]
// Decompiled from _DWORD *__thiscall CShip::CShip(_DWORD *this, int a2)
 CShip::CShip(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CVehicle::CVehicle(this, a2);
  v6 = 0;
  *v5 = &CShip::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CShip");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v5 + 42));
  v6 = -1;
  return v5;
}


// address=[0x159dd60]
// Decompiled from int __thiscall CShip::Store(int *this, struct std::ostream *a2)
void  CShip::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CVehicle::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<int>((int)a2, v4 + 42);
}


// address=[0x159ddb0]
// Decompiled from struct CVehicle *__thiscall CShip::TakeJob(CShip *this)
void  CShip::TakeJob(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  __int64 v6; // [esp+8h] [ebp-14h]
  __int16 *CurrentTaskPtr; // [esp+14h] [ebp-8h]

  CurrentTaskPtr = (__int16 *)CVehicle::GetCurrentTaskPtr(this);
  CVehicle::InitCommonTaskValues(this, (const struct CEntityTask *)CurrentTaskPtr);
  if ( CurrentTaskPtr )
  {
    switch ( *((_BYTE *)this + 107) )
    {
      case 6:
      case 7:
        goto LABEL_5;
      case 8:
        HIDWORD(v6) = CurrentTaskPtr[5] < 0;
        LODWORD(v6) = CurrentTaskPtr[6] < 0;
        if ( v6 )
        {
          CurrentTaskPtr[5] = IEntity::X(this);
          CurrentTaskPtr[6] = IEntity::Y(this);
        }
LABEL_5:
        v1 = Y16X16::PackXYFast(CurrentTaskPtr[5], CurrentTaskPtr[6]);
        *((_BYTE *)this + 107) = *(_BYTE *)(*((_DWORD *)this + 25) + 36);
        v5 = std::auto_ptr<CWalking>::operator->(v1);
        (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v5 + 8))(v5, v4, 0);
        return (struct CVehicle *)(*(int (__thiscall **)(CShip *))(*(_DWORD *)this + 144))(this);
      case 0x11:
        return (struct CVehicle *)(*(int (__thiscall **)(CShip *))(*(_DWORD *)this + 144))(this);
      case 0x24:
        IEntity::ClearFlagBits(this, EntityFlag_Visible);
        v2 = IEntity::EntityId((unsigned __int16 *)this);
        return CVehicleMgr::DeleteVehicle((CVehicleMgr *)&g_cVehicleMgr, v2);
      default:
        BBSupportTracePrintF(2, "CShip::TakeJob(): Invalid task! %d", *((unsigned __int8 *)this + 107));
        CVehicle::InitCommonTaskValues(this, 0);
        return (struct CVehicle *)(*(int (__thiscall **)(CShip *))(*(_DWORD *)this + 144))(this);
    }
  }
  return (struct CVehicle *)(*(int (__thiscall **)(CShip *))(*(_DWORD *)this + 144))(this);
}


// address=[0x159df50]
// Decompiled from char __thiscall CShip::WalkDir(CShip *this, char a2)
void  CShip::WalkDir(int a2) {
  
  int v2; // esi
  CWalking *v3; // eax
  int v4; // eax
  char result; // al
  int v6; // [esp-4h] [ebp-24h]
  int v7; // [esp+4h] [ebp-1Ch]
  __int16 v8; // [esp+8h] [ebp-18h]
  int v9; // [esp+Ch] [ebp-14h]
  int v10; // [esp+10h] [ebp-10h]
  struct CPaneContainer *v11; // [esp+14h] [ebp-Ch]
  Y16X16 *v12; // [esp+18h] [ebp-8h]

  v12 = (Y16X16 *)(a2 & 0xF);
  if ( (unsigned int)v12 < 6 )
  {
    v7 = IEntity::PackedXY(this);
    v9 = IEntity::WorldIdx();
    v2 = IEntity::PackedXY(this);
    v11 = (struct CPaneContainer *)(Y16X16::NeighborModifier(v12) + v2);
    v10 = CWorldManager::Index((int)v11);
    v3 = (CWalking *)std::auto_ptr<CWalking>::operator->(v10);
    if ( CWalking::IsFree(v3, v6) )
    {
      v4 = IEntity::PackedXY(this);
      if ( CWater::MoveShip(v11, v4) )
      {
        v8 = IEntity::ID();
        CWorldManager::SetMapObjectId(v9, 0);
        CWorldManager::SetMapObjectId(v10, v8);
        if ( v12 != (Y16X16 *)*((char *)this + 68) )
          CVehicle::InitTurn(this, (int)v12);
        IEntity::SetPosition(this, v11);
        IMovingEntity::InitDistance(this);
        CWarMap::NotifyMove(this, v7);
      }
      else
      {
        a2 |= 0x88u;
      }
    }
  }
  result = a2;
  *((_BYTE *)this + 104) = a2;
  return result;
}


// address=[0x159e070]
// Decompiled from int __thiscall CShip::PlaceVehicle(CShip *this, int a2)
void  CShip::PlaceVehicle(int a2) {
  
  __int16 v3; // [esp+0h] [ebp-10h]
  int v5; // [esp+8h] [ebp-8h]

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 651, "g_cWorld.InWorldPackedXY( _iXY )") == 1 )
  {
    __debugbreak();
  }
  v5 = CWorldManager::Index(a2);
  v3 = IEntity::EntityId((unsigned __int16 *)this);
  if ( CWorldManager::MapObjectId(v5)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 656, "g_cWorld.MapObjectId( iWorldIdx ) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !CWater::PlaceShip(a2) && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 660, "bPlaceShipOk") == 1 )
    __debugbreak();
  return CWorldManager::SetMapObjectId(v5, v3);
}


// address=[0x159e150]
// Decompiled from char __thiscall CShip::RemoveVehicle(CShip *this, int a2)
void  CShip::RemoveVehicle(int a2) {
  
  int v2; // esi
  int v3; // esi
  int LocalPlayerId; // eax
  int v5; // eax
  int v7; // [esp-8h] [ebp-18h]
  int v8; // [esp-4h] [ebp-14h]
  int v9; // [esp+0h] [ebp-10h]
  int v10; // [esp+4h] [ebp-Ch]

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 674, "g_cWorld.InWorldPackedXY( _iXY )") == 1 )
  {
    __debugbreak();
  }
  v10 = CWorldManager::Index(a2);
  v2 = CWorldManager::MapObjectId(v10);
  if ( v2 != IEntity::EntityId((unsigned __int16 *)this)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 678, "g_cWorld.MapObjectId( iWorldIdx ) == EntityId()") == 1 )
  {
    __debugbreak();
  }
  if ( !CWater::RemoveShip(a2) && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 682, "bRemoveShipOk") == 1 )
    __debugbreak();
  CWorldManager::SetMapObjectId(v10, 0);
  v3 = IEntity::OwnerId((unsigned __int8 *)this);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v9);
  if ( v3 != LocalPlayerId )
    return LocalPlayerId;
  v8 = IEntity::Y(this);
  v7 = IEntity::X(this);
  v5 = IEntity::OwnerId((unsigned __int8 *)this);
  LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(2471, v5, v7, v8);
  return LocalPlayerId;
}


// address=[0x159e260]
// Decompiled from int __thiscall CShip::RepairBuildingInRange(CShip *this)
int  CShip::RepairBuildingInRange(void) {
  
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
        if ( IEntity::Type(v2) == 31 )
          return v9;
      }
    }
  }
  return 0;
}


// address=[0x159e340]
// Decompiled from CShip *__thiscall CShip::RepairAt(CShip *this, int a2)
void  CShip::RepairAt(int a2) {
  
  CShip *result; // eax
  char v3; // dl

  if ( CShip::RepairBuildingInRange(this) != a2
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 738, "RepairBuildingInRange()==_iAtBuildingID") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 25)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 739, "m_pVehicleProperties!= NULL") == 1 )
  {
    __debugbreak();
  }
  result = (CShip *)(*(int (__thiscall **)(CShip *))(*(_DWORD *)this + 40))(this);
  if ( (unsigned int)result >= *(_DWORD *)(*((_DWORD *)this + 25) + 48) )
    return result;
  v3 = CStaticConfigVarInt::operator int(&unk_4158CE0) + *((_BYTE *)this + 33);
  result = this;
  *((_BYTE *)this + 33) = v3;
  return result;
}


// address=[0x159e3e0]
// Decompiled from int __thiscall CShip::GetHealthDisplayID(CShip *this)
int  CShip::GetHealthDisplayID(void) {
  
  unsigned int v2; // [esp+0h] [ebp-8h]

  if ( !*((_DWORD *)this + 25)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 750, "m_pVehicleProperties!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 25) )
    return 0;
  if ( !*(_DWORD *)(*((_DWORD *)this + 25) + 48)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 753, "m_pVehicleProperties->m_uHitpoints!=0") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_DWORD *)(*((_DWORD *)this + 25) + 48) )
    return 0;
  v2 = 7
     - (unsigned int)(7 * (*(int (__thiscall **)(CShip *))(*(_DWORD *)this + 40))(this))
     / *(_DWORD *)(*((_DWORD *)this + 25) + 48);
  if ( v2 >= 8
    && BBSupportDbgReport(2, "MapObjects\\Ship\\Ship.cpp", 757, "iIndex>=0 && iIndex<=MAX_HEALTH_DISPLAY_INDEX") == 1 )
  {
    __debugbreak();
  }
  return dword_3D8BFB4[v2];
}


// address=[0x37bd380]
// [Decompilation failed for static int const CShip::SHIPYARD_SCAN_RANGE]

// address=[0x37bd384]
// [Decompilation failed for static int const CShip::FULL_UPDATE_DELAY]

