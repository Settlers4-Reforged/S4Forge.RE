#include "CVehicleMgr.h"

// Definitions for class CVehicleMgr

// address=[0x130e530]
// Decompiled from int __stdcall CVehicleMgr::operator[](int a1)
class CVehicle &  CVehicleMgr::operator[](int a1) {
  
  return CMapObjectMgr::EntityPtr(a1);
}


// address=[0x130ec90]
// Decompiled from int __thiscall CVehicleMgr::GetFirstVehicleId(CVehicleMgr *this, int a2, int a3)
int  CVehicleMgr::GetFirstVehicleId(int a2, int a3) {
  
  return *((unsigned __int16 *)this + 6 * a2 + a3 + 176);
}


// address=[0x130ed60]
// Decompiled from int __thiscall CVehicleMgr::GetNumberOfVehicles(CVehicleMgr *this, int a2, int a3, int a4)
int  CVehicleMgr::GetNumberOfVehicles(int a2, int a3, int a4) {
  
  if ( a4 )
    return *((unsigned __int16 *)this + 18 * a2 + 3 * a3 + a4 + 14);
  else
    return *((unsigned __int16 *)this + 18 * a2 + 3 * a3 + 16) + *((unsigned __int16 *)this + 18 * a2 + 3 * a3 + 15);
}


// address=[0x130eef0]
// Decompiled from unsigned __int8 *__cdecl CVehicleMgr::GetVehiclePtr(int a1)
class CVehicle * __cdecl CVehicleMgr::GetVehiclePtr(int a1) {
  
  __int64 v2; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v3; // [esp+8h] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( !v3 )
    return 0;
  HIDWORD(v2) = IEntity::ObjType(v3) == 2;
  LODWORD(v2) = IEntity::ObjType(v3) == 4;
  if ( !v2 )
    return 0;
  if ( !j____RTDynamicCast((void **)v3, 0, &IEntity__RTTI_Type_Descriptor_, &CVehicle__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleMgr.h",
         248,
         "dynamic_cast< CVehicle* >( pEntity ) != 0") == 1 )
  {
    __debugbreak();
  }
  return v3;
}


// address=[0x153a3f0]
// Decompiled from unsigned int __thiscall CVehicleMgr::Alloc(CVehicleMgr *this, unsigned int a2)
void *  CVehicleMgr::Alloc(unsigned int a2) {
  
  return MemoryAllocator::allocate((unsigned int *)this, a2);
}


// address=[0x153a440]
// Decompiled from void __thiscall CVehicleMgr::Dealloc(CVehicleMgr *this, void *a2)
void  CVehicleMgr::Dealloc(void * a2) {
  
  MemoryAllocator::deallocate(this, a2);
}


// address=[0x15a8b20]
// Decompiled from CVehicleMgr *__thiscall CVehicleMgr::CVehicleMgr(CVehicleMgr *this)
 CVehicleMgr::CVehicleMgr(void) {
  
  int v1; // eax
  unsigned int v2; // eax
  _BYTE v4[16]; // [esp+4h] [ebp-50h] BYREF
  int v5; // [esp+14h] [ebp-40h]
  int v6; // [esp+18h] [ebp-3Ch]
  int v7; // [esp+1Ch] [ebp-38h] BYREF
  int v8; // [esp+20h] [ebp-34h] BYREF
  int v9; // [esp+24h] [ebp-30h] BYREF
  int v10; // [esp+28h] [ebp-2Ch] BYREF
  int v11; // [esp+2Ch] [ebp-28h] BYREF
  int v12; // [esp+30h] [ebp-24h] BYREF
  int v13; // [esp+34h] [ebp-20h] BYREF
  int v14; // [esp+38h] [ebp-1Ch] BYREF
  int v15; // [esp+3Ch] [ebp-18h] BYREF
  int v16; // [esp+40h] [ebp-14h] BYREF
  CVehicleMgr *v17; // [esp+44h] [ebp-10h]
  int v18; // [esp+50h] [ebp-4h]

  v17 = this;
  v16 = 324;
  v15 = 216;
  v14 = 216;
  v13 = 216;
  v12 = 300;
  v11 = 216;
  v10 = 200;
  v9 = 200;
  v8 = 200;
  v7 = 324;
  v6 = CreateArgv<unsigned int>(v4, &v7);
  v5 = v6;
  v18 = 0;
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v8);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v9);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v10);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v11);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v12);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v13);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v14);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v15);
  v1 = TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v16);
  v2 = sub_15AA620(v1);
  MemoryAllocator::MemoryAllocator(v17, v2, 0x20u, 0);
  LOBYTE(v18) = 2;
  TArgv<unsigned int,std::vector<unsigned int>>::~TArgv<unsigned int,std::vector<unsigned int>>(v4);
  CVehicleMgr::Clear(v17);
  return v17;
}


// address=[0x15a8c60]
// Decompiled from void __thiscall CVehicleMgr::~CVehicleMgr(CVehicleMgr *this)
 CVehicleMgr::~CVehicleMgr(void) {
  
  MemoryAllocator::~MemoryAllocator(this);
}


// address=[0x15a8c80]
// Decompiled from void *__thiscall CVehicleMgr::Clear(CVehicleMgr *this)
void  CVehicleMgr::Clear(void) {
  
  *((_DWORD *)this + 6) = 0;
  memset((char *)this + 28, 0, 0x144u);
  return memset((char *)this + 352, 0, 0x6Cu);
}


// address=[0x15a8cd0]
// Decompiled from int __thiscall CVehicleMgr::AddVehicle(CVehicleMgr *this, int a2, int a3, int a4, int a5, int a6, bool a7)
int  CVehicleMgr::AddVehicle(int a2, int a3, int a4, int a5, int a6, bool a7) {
  
  int v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]

  if ( (a2 != -1 || a3)
    && !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(
         2,
         "MapObjects\\VehicleMgr.cpp",
         555,
         "(_iX == -1 && _iY == 0) || g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 556, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a5 == 1030 )
    v9 = 5;
  else
    v9 = a5;
  if ( (v9 <= 0 || v9 >= 6)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 560, "iVehicleType>0 && iVehicleType<VEHICLE_MAX") == 1 )
  {
    __debugbreak();
  }
  v10 = CVehicleMgr::Create(a2, a3, a4, a5, a6, a7);
  if ( !v10 )
    return v10;
  if ( a7 )
    v8 = 1;
  else
    v8 = 2;
  ++*((_WORD *)this + 18 * a4 + 3 * v9 + v8 + 14);
  CVehicleMgr::AttachVehicle(this, a4, v9, v10);
  CStatistic::AddVehicle((CStatistic *)&g_cStatistic, a4, v9, 1);
  return v10;
}


// address=[0x15a8e50]
// Decompiled from int __thiscall CVehicleMgr::AddFoundationCart(CVehicleMgr *this, int a2, int a3, int a4, int a5)
int  CVehicleMgr::AddFoundationCart(int a2, int a3, int a4, int a5) {
  
  return CVehicleMgr::AddVehicle(this, a2, a3, a4, 1030, a5, 0);
}


// address=[0x15a8e90]
// Decompiled from struct CVehicle *__thiscall CVehicleMgr::DeleteVehicle(CVehicleMgr *this, int a2)
void  CVehicleMgr::DeleteVehicle(int a2) {
  
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // eax
  struct CVehicle *result; // eax
  struct CVehicle *v5; // [esp+4h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 0xFFFF)
    && BBSupportDbgReport(
         2,
         "MapObjects\\VehicleMgr.cpp",
         856,
         "_iVehicleId>0 && _iVehicleId<CMapObjectMgr::MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  v2 = (unsigned __int8 *)CMapObjectMgr::Entity(a2);
  if ( IEntity::ObjType(v2) != 2 )
  {
    v3 = (unsigned __int8 *)CMapObjectMgr::Entity(a2);
    if ( IEntity::ObjType(v3) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\VehicleMgr.cpp",
           859,
           "g_pMapObjectMgr->Entity( _iVehicleId ).ObjType() == SHIP_OBJ || g_pMapObjectMgr->Entity( _iVehicleId ).ObjTyp"
           "e() == CATAPULT_OBJ") == 1 )
    {
      __debugbreak();
    }
  }
  result = 0;
  if ( !a2 )
    return result;
  result = CVehicleMgr::GetVehiclePtr(a2);
  v5 = result;
  if ( !result )
  {
    result = (struct CVehicle *)BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 866, "pVehicle!= NULL");
    if ( result == (struct CVehicle *)1 )
      __debugbreak();
  }
  if ( !v5 )
    return result;
  if ( IEntity::FlagBits(v5, (EntityFlag)0x600u) )
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, a2);
  return (struct CVehicle *)CMapObjectMgr::Kill(a2, 0);
}


// address=[0x15a8fa0]
// Decompiled from bool __thiscall CVehicleMgr::IsPositionFreeForVehicle(CVehicleMgr *this, int a2, int a3, int a4)
bool  CVehicleMgr::IsPositionFreeForVehicle(int a2, int a3, int a4) {
  
  int v5; // [esp+4h] [ebp-20h]
  int v6; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  bool v9; // [esp+22h] [ebp-2h]
  bool IsPlaceShipOk; // [esp+23h] [ebp-1h]

  IsPlaceShipOk = 0;
  if ( (unsigned __int8)CWorldManager::InWorld(a2, a3) )
  {
    switch ( a4 )
    {
      case 0:
        IsPlaceShipOk = 0;
        break;
      case 1:
      case 2:
      case 3:
        v6 = Y16X16::PackXYFast(a2, a3);
        IsPlaceShipOk = CWater::IsPlaceShipOk(v6);
        break;
      case 4:
      case 5:
        v7 = CWorldManager::Index(a2, a3);
        if ( ITiling::CatapultSectorId(v7) )
        {
          v9 = CWorldManager::MapObjectId(v7) != 0;
          if ( !v9 )
          {
            for ( i = 0; i < 6; ++i )
            {
              v5 = v7 + CWorldManager::NeighborRelIndex(i);
              if ( CWorldManager::MapObjectId(v5) )
              {
                v9 = 1;
                break;
              }
            }
          }
          IsPlaceShipOk = !v9;
        }
        break;
      default:
        return IsPlaceShipOk;
    }
  }
  return IsPlaceShipOk;
}


// address=[0x15a9100]
// Decompiled from int __thiscall CVehicleMgr::GetNearestVehicle(CVehicleMgr *this, int a2, int a3, int a4, int a5)
int  CVehicleMgr::GetNearestVehicle(int a2, int a3, int a4, int a5) {
  
  int v5; // eax
  int v7; // [esp-4h] [ebp-1Ch]
  int v9; // [esp+4h] [ebp-14h]
  unsigned int v10; // [esp+8h] [ebp-10h]
  unsigned int v11; // [esp+Ch] [ebp-Ch]
  _DWORD *v12; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  if ( (a2 <= 0 || a2 > CPlayerManager::LastPlayerId())
    && BBSupportDbgReport(
         2,
         "MapObjects\\VehicleMgr.cpp",
         822,
         "_iOwnerId>0 && _iOwnerId <= g_cPlayerMgr.LastPlayerId()") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 6)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 823, "_iVehicleType>0 && _iVehicleType<VEHICLE_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a4, a5)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 824, "g_cWorld.InWorld( _iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v10 = -1;
  v9 = 0;
  for ( i = CVehicleMgr::GetFirstVehicleId(this, a2, a3); i; i = IAnimatedEntity::Next(v12) )
  {
    v12 = (_DWORD *)CVehicleMgr::operator[](i);
    v7 = a5 - IEntity::Y(v12);
    v5 = IEntity::X(v12);
    v11 = Grid::Distance((Grid *)(a4 - v5), v7);
    if ( v11 < v10 )
    {
      v10 = v11;
      v9 = i;
    }
  }
  return v9;
}


// address=[0x15a9230]
// Decompiled from int __cdecl CVehicleMgr::GetFerryShipAt(int a1, int a2)
class CFerryShip * __cdecl CVehicleMgr::GetFerryShipAt(int a1, int a2) {
  
  void **v2; // eax
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 1093, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v4 = CSpiralOffsets::Last(2);
  for ( i = 0; i <= v4; ++i )
  {
    v6 = a1 + CSpiralOffsets::DeltaX(i);
    v7 = a2 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v6, v7) )
    {
      v5 = CWorldManager::MapObjectId(v6, v7);
      if ( v5 )
      {
        v2 = (void **)CMapObjectMgr::EntityPtr(v5);
        return j____RTDynamicCast(v2, 0, &IEntity__RTTI_Type_Descriptor_, &CFerryShip__RTTI_Type_Descriptor_, 0);
      }
    }
  }
  return 0;
}


// address=[0x15a9330]
// Decompiled from int __cdecl CVehicleMgr::FillVehicleGroupMenu(struct CInfoExchange *a1, bool a2)
void __cdecl CVehicleMgr::FillVehicleGroupMenu(class CInfoExchange * a1, bool a2, bool a3) {
  
  unsigned __int16 *v2; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-60h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-54h] BYREF
  unsigned __int16 *v6; // [esp+1Ch] [ebp-48h]
  std::_Iterator_base12 *v7; // [esp+20h] [ebp-44h]
  std::_Iterator_base12 *v8; // [esp+24h] [ebp-40h]
  unsigned int v9; // [esp+28h] [ebp-3Ch]
  int v10; // [esp+2Ch] [ebp-38h]
  int v11; // [esp+30h] [ebp-34h]
  char v12; // [esp+37h] [ebp-2Dh]
  void *v13; // [esp+38h] [ebp-2Ch]
  CEvn_Event v14; // [esp+3Ch] [ebp-28h] BYREF
  int v15; // [esp+60h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 1016, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  v13 = a1;
  memset(a1, 0, 0x20u);
  *((_DWORD *)a1 + 2) = 4;
  *((_DWORD *)v13 + 4) = 1;
  *((_DWORD *)v13 + 6) = 2;
  v10 = CInputProcessor::Selection();
  std::vector<unsigned short>::begin(v5);
  v15 = 0;
  while ( 1 )
  {
    v8 = (std::_Iterator_base12 *)std::vector<unsigned short>::end(v4);
    v7 = v8;
    LOBYTE(v15) = 1;
    v12 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=(v8);
    LOBYTE(v15) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v4);
    if ( !v12 )
      break;
    v2 = (unsigned __int16 *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v5);
    v6 = (unsigned __int16 *)CVehicleMgr::operator[](*v2);
    v11 = IEntity::Type(v6);
    switch ( v11 )
    {
      case 1:
        ++*((_DWORD *)v13 + 5);
        break;
      case 2:
        ++*((_DWORD *)v13 + 7);
        break;
      case 4:
        ++*((_DWORD *)v13 + 3);
        break;
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v5);
  }
  *((_DWORD *)v13 + 1) = 20;
  v9 = 604;
  if ( !a2 )
    v9 = 602;
  CEvn_Event::CEvn_Event(&v14, v9, 0, (unsigned int)v13, 0);
  LOBYTE(v15) = 2;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 1066, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v14);
  LOBYTE(v15) = 0;
  CEvn_Event::~CEvn_Event(&v14);
  v15 = -1;
  return std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v5);
}


// address=[0x15a9580]
// Decompiled from void __thiscall CVehicleMgr::Store(CVehicleMgr *this, struct S4::CMapFile *a2)
void  CVehicleMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-10Ch] BYREF
  _DWORD v5[43]; // [esp+10h] [ebp-FCh] BYREF
  unsigned int v6; // [esp+BCh] [ebp-50h]
  size_t Size; // [esp+C0h] [ebp-4Ch]
  void *Src; // [esp+C4h] [ebp-48h]
  int v9; // [esp+C8h] [ebp-44h]
  int v10; // [esp+CCh] [ebp-40h]
  unsigned __int8 *v11; // [esp+D0h] [ebp-3Ch]
  int v12; // [esp+D4h] [ebp-38h]
  int v13; // [esp+D8h] [ebp-34h]
  unsigned __int8 *v14; // [esp+DCh] [ebp-30h]
  int UsedId; // [esp+E0h] [ebp-2Ch]
  int v16; // [esp+E4h] [ebp-28h] BYREF
  int v17; // [esp+E8h] [ebp-24h]
  int v18; // [esp+ECh] [ebp-20h] BYREF
  unsigned __int8 *v19; // [esp+F0h] [ebp-1Ch]
  unsigned __int8 *v20; // [esp+F4h] [ebp-18h]
  int i; // [esp+F8h] [ebp-14h]
  int *v22; // [esp+FCh] [ebp-10h]
  int v23; // [esp+108h] [ebp-4h]

  v22 = &v4;
  v5[42] = this;
  std::ostrstream::ostrstream(0, 0x40000, 0, 2, 1);
  v23 = 0;
  v6 = std::ios_base::exceptions((char *)v5 + *(_DWORD *)(v5[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v23) = 1;
  v16 = 1;
  operator^<unsigned int>((struct std::ostream *)v5, &v16);
  UsedId = CMapObjectMgr::LastUsedId();
  v17 = UsedId;
  v18 = 0;
  for ( i = 0; i <= v17; ++i )
  {
    v14 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v19 = v14;
    if ( v14 )
    {
      v13 = IEntity::ObjType(v19);
      if ( v13 == 2 || (v12 = IEntity::ObjType(v19), v12 == 4) )
        ++v18;
    }
  }
  operator^<unsigned int>((struct std::ostream *)v5, &v18);
  for ( i = 0; i <= v17; ++i )
  {
    v11 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v20 = v11;
    if ( v11 )
    {
      v10 = IEntity::ObjType(v20);
      if ( v10 == 2 || (v9 = IEntity::ObjType(v20), v9 == 4) )
        (*(void (__thiscall **)(unsigned __int8 *, _DWORD *))(*(_DWORD *)v20 + 4))(v20, v5);
    }
  }
  std::ostream::put(0);
  v23 = 0;
  std::ostrstream::freeze((std::ostrstream *)v5, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(166, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), v6);
  v23 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x15a97e0]
// Decompiled from void __thiscall CVehicleMgr::Load(CVehicleMgr *this, struct S4::CMapFile *a2)
void  CVehicleMgr::Load(class S4::CMapFile &) {
  
  int v2; // [esp+0h] [ebp-154h] BYREF
  _DWORD v3[42]; // [esp+10h] [ebp-144h] BYREF
  unsigned int v4; // [esp+B8h] [ebp-9Ch]
  int v5; // [esp+BCh] [ebp-98h]
  int v6; // [esp+C0h] [ebp-94h]
  int v7; // [esp+C4h] [ebp-90h]
  int v8; // [esp+C8h] [ebp-8Ch]
  int v9; // [esp+CCh] [ebp-88h]
  int v10; // [esp+D0h] [ebp-84h]
  int v12; // [esp+D8h] [ebp-7Ch]
  int v13; // [esp+DCh] [ebp-78h]
  int v14; // [esp+E0h] [ebp-74h]
  int v15; // [esp+E4h] [ebp-70h]
  unsigned __int16 *v16; // [esp+E8h] [ebp-6Ch]
  int v17; // [esp+ECh] [ebp-68h]
  int v18; // [esp+F0h] [ebp-64h] BYREF
  int v19; // [esp+F4h] [ebp-60h] BYREF
  _WORD *v20; // [esp+FCh] [ebp-58h]
  int v21; // [esp+100h] [ebp-54h]
  int v22; // [esp+104h] [ebp-50h] BYREF
  unsigned int v23; // [esp+108h] [ebp-4Ch] BYREF
  int pExceptionObject; // [esp+10Ch] [ebp-48h] BYREF
  char *Str; // [esp+110h] [ebp-44h]
  CVehicleMgr *v26; // [esp+114h] [ebp-40h]
  unsigned int i; // [esp+118h] [ebp-3Ch]
  unsigned __int16 *v29; // [esp+120h] [ebp-34h]
  _BYTE v30[28]; // [esp+124h] [ebp-30h] BYREF
  int *v31; // [esp+144h] [ebp-10h]
  int v32; // [esp+150h] [ebp-4h]

  v31 = &v2;
  v26 = this;
  CVehicleMgr::Clear(this);
  v19 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xA6u, 0, &v19, 0);
  if ( Str )
  {
    std::string::string(v30, Str);
    v32 = 0;
    std::istringstream::istringstream(v30, 1, 1);
    LOBYTE(v32) = 1;
    v4 = std::ios_base::exceptions((char *)v3 + *(_DWORD *)(v3[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), 6);
    LOBYTE(v32) = 2;
    operator^<unsigned int>(v3, &v18);
    v17 = v18;
    if ( v18 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CVehicleMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v23 = 0;
    operator^<unsigned int>(v3, &v23);
    for ( i = 0; i < v23; ++i )
    {
      v16 = (unsigned __int16 *)CPersistence::New(v3, v2);
      v29 = v16;
      if ( !v16 )
      {
        v15 = BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 481, "pNewVehicle!=NULL");
        if ( v15 == 1 )
          __debugbreak();
      }
      if ( !v29 )
      {
        v22 = 0;
        CS4InvalidMapException::CS4InvalidMapException(&v22);
        _CxxThrowException(&v22, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
      }
      IEntity::ClearFlagBits(v29, Selected);
      (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v29 + 12))(v29);
      v14 = IEntity::ID();
      v13 = IEntity::Type(v29);
      v12 = IEntity::OwnerId((unsigned __int8 *)v29);
      CVehicleMgr::AttachVehicle(v26, v12, v13, v14);
      if ( IEntity::FlagBits(v29, (EntityFlag)&dword_F29144[220079]) )
        v21 = 1;
      else
        v21 = 2;
      v8 = v21;
      v9 = IEntity::OwnerId((unsigned __int8 *)v29);
      v10 = IEntity::Type(v29);
      v20 = (_WORD *)((char *)v26 + 36 * v9 + 6 * v10 + 2 * v8 + 28);
      ++*v20;
      v7 = IEntity::ObjType((unsigned __int8 *)v29);
      if ( v7 == 2 )
      {
        v6 = IEntity::WorldIdx();
        v5 = v6;
        if ( CWaterFlags::IsBlockedWater(v6) )
        {
          IEntity::ClearFlagBits(v29, Visible);
          (*(void (__thiscall **)(unsigned __int16 *, int))(*(_DWORD *)v29 + 32))(v29, 0x4000);
        }
      }
    }
    v32 = 1;
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), v4);
    LOBYTE(v32) = 0;
    std::istringstream::`vbase destructor'(v3);
    v32 = -1;
    std::string::~string(v30);
  }
}


// address=[0x15a9b60]
// Decompiled from int __thiscall CVehicleMgr::LoadInfo(CVehicleMgr *this)
void  CVehicleMgr::LoadInfo(void) {
  
  return (**(int (__thiscall ***)(void *, _DWORD, _DWORD))g_pVehicleInfoMgr)(g_pVehicleInfoMgr, 0, 0);
}


// address=[0x15a9b80]
// Decompiled from int __cdecl CVehicleMgr::Create(int a1, int a2, int a3, int a4, int a5, bool a6)
int __cdecl CVehicleMgr::Create(int a1, int a2, int a3, int a4, int a5, bool a6) {
  
  void *v6; // eax
  CCart *v8; // [esp+34h] [ebp-80h]
  CTrojanCatapult *v9; // [esp+3Ch] [ebp-78h]
  CMayaCatapult *v10; // [esp+44h] [ebp-70h]
  CVikingCatapult *v11; // [esp+4Ch] [ebp-68h]
  CRomanCatapult *v12; // [esp+54h] [ebp-60h]
  int v13; // [esp+5Ch] [ebp-58h]
  CTransportShip *v14; // [esp+64h] [ebp-50h]
  CFerryShip *v15; // [esp+6Ch] [ebp-48h]
  CTrojanWarShip *v16; // [esp+74h] [ebp-40h]
  CMayaWarShip *v17; // [esp+7Ch] [ebp-38h]
  CVikingWarShip *v18; // [esp+84h] [ebp-30h]
  CRomanWarShip *v19; // [esp+8Ch] [ebp-28h]
  int v20; // [esp+94h] [ebp-20h]
  int FreeSlot; // [esp+9Ch] [ebp-18h]
  char v22; // [esp+A7h] [ebp-Dh]

  if ( a4 == 1030 )
    v20 = 5;
  else
    v20 = a4;
  if ( (a1 != -1 || a2)
    && !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(
         2,
         "MapObjects\\VehicleMgr.cpp",
         611,
         "( _iX == -1 && _iY == 0) || g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( !CPlayerManager::ValidUsedPlayerId(a3)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 612, "g_cPlayerMgr.ValidUsedPlayerId( _iOwnerId )") == 1 )
  {
    __debugbreak();
  }
  if ( (v20 <= 0 || v20 >= 6)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 613, "iVehicleType > 0 && iVehicleType < VEHICLE_MAX") == 1 )
  {
    __debugbreak();
  }
  v6 = (void *)CPlayerManager::PlayerInfo(a3);
  v13 = CPlayerInfo::Race(v6);
  FreeSlot = CMapObjectMgr::GetFreeSlot();
  v22 = 0;
  switch ( v20 )
  {
    case 1:
      switch ( v13 )
      {
        case 0:
          v19 = (CRomanWarShip *)CWarShip::operator new(0xC8u);
          if ( v19 )
            CRomanWarShip::CRomanWarShip(v19, a1, a2, a3, FreeSlot, v20, a5, a6);
          break;
        case 1:
          v18 = (CVikingWarShip *)CWarShip::operator new(0xC8u);
          if ( v18 )
            CVikingWarShip::CVikingWarShip(v18, a1, a2, a3, FreeSlot, v20, a5, a6);
          break;
        case 2:
          v17 = (CMayaWarShip *)CWarShip::operator new(0xC8u);
          if ( v17 )
            CMayaWarShip::CMayaWarShip(v17, a1, a2, a3, FreeSlot, v20, a5, a6);
          break;
        case 4:
          v16 = (CTrojanWarShip *)CWarShip::operator new(0xC8u);
          if ( v16 )
            CTrojanWarShip::CTrojanWarShip(v16, a1, a2, a3, FreeSlot, v20, a5, a6);
          break;
        default:
          v22 = 1;
          break;
      }
      break;
    case 2:
      v15 = (CFerryShip *)CFerryShip::operator new(0xD8u);
      if ( v15 )
        CFerryShip::CFerryShip(v15, a1, a2, a3, FreeSlot, v20, a5, a6);
      break;
    case 3:
      v14 = (CTransportShip *)CTransportShip::operator new(0x12Cu);
      if ( v14 )
        CTransportShip::CTransportShip(v14, a1, a2, a3, FreeSlot, v20, a5, a6);
      break;
    case 4:
      switch ( v13 )
      {
        case 0:
          v12 = (CRomanCatapult *)CRomanCatapult::operator new(0xD8u);
          if ( v12 )
            CRomanCatapult::CRomanCatapult(v12, a1, a2, a3, FreeSlot, v20, a5, a6);
          break;
        case 1:
          v11 = (CVikingCatapult *)CVikingCatapult::operator new(0xD8u);
          if ( v11 )
            CVikingCatapult::CVikingCatapult(v11, a1, a2, a3, FreeSlot, v20, a5, a6);
          break;
        case 2:
          v10 = (CMayaCatapult *)CMayaCatapult::operator new(0xD8u);
          if ( v10 )
            CMayaCatapult::CMayaCatapult(v10, a1, a2, a3, FreeSlot, v20, a5, a6);
          break;
        case 4:
          v9 = (CTrojanCatapult *)CTrojanCatapult::operator new(0xD8u);
          if ( v9 )
            CTrojanCatapult::CTrojanCatapult(v9, a1, a2, a3, FreeSlot, v20, a5, a6);
          break;
        default:
          v22 = 1;
          break;
      }
      break;
    case 5:
      v8 = (CCart *)CCart::operator new(0x144u);
      if ( v8 )
        CCart::CCart(v8, a1, a2, a3, FreeSlot, a4, a5, a6);
      break;
    default:
      v22 = 1;
      break;
  }
  if ( v22
    && BBSupportDbgReport(1, "MapObjects\\VehicleMgr.cpp", 723, "The program can't use this vehicle at the moment!") == 1 )
  {
    __debugbreak();
  }
  return FreeSlot;
}


// address=[0x15aa1b0]
// Decompiled from int __thiscall CVehicleMgr::AttachVehicle(CVehicleMgr *this, int a2, int a3, int a4)
void  CVehicleMgr::AttachVehicle(int a2, int a3, int a4) {
  
  IAnimatedEntity *v4; // eax
  IAnimatedEntity *v5; // eax
  _WORD *v6; // eax
  int result; // eax
  int v9; // [esp+4h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 945, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 6)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 946, "_iVehicleType>0 && _iVehicleType<VEHICLE_MAX") == 1 )
  {
    __debugbreak();
  }
  v4 = (IAnimatedEntity *)CVehicleMgr::operator[](a4);
  IAnimatedEntity::SetPrevious(v4, 0);
  v9 = *((unsigned __int16 *)this + 6 * a2 + a3 + 176);
  if ( *((_WORD *)this + 6 * a2 + a3 + 176) )
  {
    v5 = (IAnimatedEntity *)CVehicleMgr::operator[](v9);
    IAnimatedEntity::SetPrevious(v5, a4);
  }
  v6 = (_WORD *)CVehicleMgr::operator[](a4);
  IAnimatedEntity::SetNext(v6, v9);
  result = a3;
  *((_WORD *)this + 6 * a2 + a3 + 176) = a4;
  return result;
}


// address=[0x15aa2a0]
// Decompiled from void __thiscall CVehicleMgr::DetachVehicle(CVehicleMgr *this, int a2, int a3, int a4)
void  CVehicleMgr::DetachVehicle(int a2, int a3, int a4) {
  
  int v4; // eax
  _WORD *v5; // eax
  int v6; // eax
  IAnimatedEntity *v7; // eax
  int v8; // [esp-4h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-Ch]
  IAnimatedEntity *v11; // [esp+4h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 974, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 6)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 975, "_iVehicleType>0 && _iVehicleType<VEHICLE_MAX") == 1 )
  {
    __debugbreak();
  }
  v11 = (IAnimatedEntity *)CVehicleMgr::operator[](a4);
  if ( IAnimatedEntity::Previous(v11) )
  {
    v8 = IAnimatedEntity::Next(v11);
    v4 = IAnimatedEntity::Previous(v11);
    v5 = (_WORD *)CVehicleMgr::operator[](v4);
    IAnimatedEntity::SetNext(v5, v8);
  }
  else
  {
    if ( *((unsigned __int16 *)this + 6 * a2 + a3 + 176) != a4
      && BBSupportDbgReport(
           2,
           "MapObjects\\VehicleMgr.cpp",
           988,
           "m_iVehicleFirstIds[_iOwnerId][_iVehicleType] == _iVehicleId") == 1 )
    {
      __debugbreak();
    }
    *((_WORD *)this + 6 * a2 + a3 + 176) = IAnimatedEntity::Next(v11);
  }
  if ( IAnimatedEntity::Next(v11) )
  {
    v9 = IAnimatedEntity::Previous(v11);
    v6 = IAnimatedEntity::Next(v11);
    v7 = (IAnimatedEntity *)CVehicleMgr::operator[](v6);
    IAnimatedEntity::SetPrevious(v7, v9);
  }
  IAnimatedEntity::SetNext(v11, 0);
  IAnimatedEntity::SetPrevious(v11, 0);
}


// address=[0x15aa3f0]
// Decompiled from void __thiscall CVehicleMgr::CheckOutVehicle(CVehicleMgr *this, int a2)
void  CVehicleMgr::CheckOutVehicle(int a2) {
  
  int v2; // [esp+4h] [ebp-14h]
  int v4; // [esp+Ch] [ebp-Ch]
  int v5; // [esp+10h] [ebp-8h]
  unsigned __int8 *v6; // [esp+14h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 0xFFFF)
    && BBSupportDbgReport(
         2,
         "MapObjects\\VehicleMgr.cpp",
         885,
         "_iVehicleId>0 && _iVehicleId<CMapObjectMgr::MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  v6 = (unsigned __int8 *)CVehicleMgr::operator[](a2);
  v4 = IEntity::OwnerId(v6);
  v5 = IEntity::Type((unsigned __int16 *)v6);
  CVehicleMgr::DetachVehicle(this, v4, v5, a2);
  v2 = 2;
  if ( IEntity::FlagBits(v6, (EntityFlag)&dword_F29144[220079])
    || !IEntity::FlagBits(v6, (EntityFlag)&loc_3000000) && IEntity::FlagBits(v6, (EntityFlag)0x100000u) )
  {
    v2 = 1;
  }
  if ( *((_WORD *)this + 18 * v4 + 3 * v5 + v2 + 14) )
    --*((_WORD *)this + 18 * v4 + 3 * v5 + v2 + 14);
  CStatistic::DecVehicle((CStatistic *)&g_cStatistic, v4, v5, 1);
}


