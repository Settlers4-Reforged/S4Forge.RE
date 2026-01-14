#include "all_headers.h"

// Definitions for class CCart

// address=[0x1400040]
// Decompiled from int __cdecl CCart::New(int a1)
static class CPersistence * __cdecl CCart::New(std::istream &) {
  
  if ( CCart::operator new(0x144u) )
    return CCart::CCart(a1);
  else
    return 0;
}


// address=[0x152bdf0]
// Decompiled from char __thiscall CCart::IsNeutralTrader(CCart *this)
bool  CCart::IsNeutralTrader(void) {
  
  return *((_BYTE *)this + 321);
}


// address=[0x152be50]
// Decompiled from CCart *__thiscall CCart::MemHomePosition(CCart *this)
void  CCart::MemHomePosition(void) {
  
  CCart *result; // eax

  result = this;
  *((_DWORD *)this + 76) = *((_DWORD *)this + 6);
  return result;
}


// address=[0x1530b60]
// Decompiled from void __thiscall CCart::Delete(CCart *this)
void  CCart::Delete(void) {
  
  int v1; // eax
  CTradingBuildingRole *v2; // [esp+0h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-Ch]

  if ( *((_DWORD *)this + 78) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 78));
    if ( !BuildingPtr && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 2021, "pTradingBuilding!=NULL") == 1 )
      __debugbreak();
    if ( BuildingPtr )
    {
      v2 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
      v1 = IEntity::ID();
      CTradingBuildingRole::VehicleArriveCancel(v2, v1, 2);
    }
  }
  if ( IEntity::FlagBits(this, OnBoard) )
    CCart::KillAllLoadedSettlers(this);
  else
    CCart::DropGoods(this);
  CWheeler::Delete(this);
}


// address=[0x1530c20]
// Decompiled from bool __thiscall CCart::IsUnEmployed(CCart *this)
bool  CCart::IsUnEmployed(void)const {
  
  return CVehicle::IsUnEmployed(this) && !*((_BYTE *)this + 216);
}


// address=[0x1530c60]
// Decompiled from int __thiscall CCart::Detach(CCart *this, int a2)
void  CCart::Detach(int) {
  
  (*(void (__thiscall **)(CCart *, int))(*(_DWORD *)this + 124))(this, a2);
  return CVehicle::Detach(this, a2);
}


// address=[0x1530c90]
// Decompiled from int __thiscall CCart::GetMeetingPointXY(int this, int a2, int a3)
int const  CCart::GetMeetingPointXY(enum OBJ_TYPE,int) {
  
  int v3; // esi
  int v4; // esi
  unsigned __int8 *v5; // eax
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]
  int i; // [esp+18h] [ebp-4h]
  int v13; // [esp+18h] [ebp-4h]

  if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
  {
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
  }
  return 0;
}


// address=[0x1530d90]
// Decompiled from int __thiscall CCart::GetFrontMeetingPointXY(int this, int a2, int a3)
int const  CCart::GetFrontMeetingPointXY(enum OBJ_TYPE,int) {
  
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
    v9 = 2 * ((v13 + 3) % 6) + 17;
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


// address=[0x1530e80]
// Decompiled from void *__thiscall CCart::GetGfxInfos(CCart *this)
struct SGfxObjectInfo *  CCart::GetGfxInfos(void) {
  
  int v1; // eax
  unsigned int v2; // eax
  unsigned int v4; // [esp+0h] [ebp-14h]
  char v5; // [esp+4h] [ebp-10h]
  char v6; // [esp+8h] [ebp-Ch]
  BOOL v7; // [esp+Ch] [ebp-8h]

  if ( (unsigned __int8)CInputProcessor::IsBoxSelection(&g_cInputProcessor) )
    IAnimatedEntity::BoxSelection();
  CVehicle::Update(this);
  if ( (unsigned __int8)CVehicle::IsTurning(this) )
  {
    (*(void (__thiscall **)(CCart *))(*(_DWORD *)this + 184))(this);
  }
  else
  {
    v4 = IEntity::Race(this);
    v7 = !CCart::HasLoadedSomething(this);
    CGfxManager::GetVehicleGfxInfo(
      (CGfxManager *)g_pGfxManager,
      (struct SGfxObjectInfo *)&IEntity::m_sGfxInfo,
      v4,
      v7 + *((unsigned __int16 *)this + 19),
      *((char *)this + 68),
      *((unsigned __int8 *)this + 36),
      0,
      0);
  }
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  byte_40FE51B = CPlayerManager::Color(v1);
  byte_40FE51D = *((_BYTE *)this + 68);
  byte_40FE51C = *((_BYTE *)this + 69);
  byte_40FE518 = 4;
  byte_40FE51A = IEntity::IsVisible(this);
  if ( IEntity::FlagBits(this, (EntityFlag)&dword_F29144[220079]) )
  {
    v2 = IEntity::Race(this);
    CGfxManager::GetVehicleGfxInfo(
      (CGfxManager *)g_pGfxManager,
      (struct SGfxObjectInfo *)&IEntity::m_sGfxInfo,
      v2,
      0x2Eu,
      2u,
      0,
      0,
      0);
    dword_40FE2AC = 65534 - *((unsigned __int16 *)this + 62) * *((unsigned __int16 *)this + 64);
  }
  if ( IEntity::FlagBits(this, Selected) )
  {
    if ( IEntity::FlagBits(this, Selected) )
      v6 = 73;
    else
      v6 = 0;
    byte_40FE266 = v6;
  }
  else if ( IEntity::FlagBits(this, (EntityFlag)0x400u) )
  {
    if ( IEntity::FlagBits(this, (EntityFlag)0x400u) )
      v5 = 90;
    else
      v5 = 0;
    byte_40FE266 = v5;
  }
  return &IEntity::m_sGfxInfo;
}


// address=[0x1531040]
// Decompiled from _DWORD *__thiscall CCart::FillDialog(CCart *this, bool a2)
void  CCart::FillDialog(bool) {
  
  int v2; // esi
  unsigned int v3; // eax
  const struct CCart::CFoundationCardCargo *v4; // eax
  char v6[4]; // [esp+8h] [ebp-50h] BYREF
  int v7; // [esp+Ch] [ebp-4Ch]
  int v8; // [esp+10h] [ebp-48h]
  int v9; // [esp+14h] [ebp-44h]
  unsigned int v10; // [esp+1Ch] [ebp-3Ch]
  BOOL v11; // [esp+20h] [ebp-38h]
  int j; // [esp+24h] [ebp-34h]
  unsigned int i; // [esp+28h] [ebp-30h]
  CCart *v14; // [esp+2Ch] [ebp-2Ch]
  CEvn_Event v15; // [esp+30h] [ebp-28h] BYREF
  int v16; // [esp+54h] [ebp-4h]

  v14 = this;
  byte_3F1E880 = CCart::CanWalk(this);
  byte_3F1E881 = *((_BYTE *)v14 + 216);
  v11 = *((_BYTE *)v14 + 217) && !*((_BYTE *)v14 + 216) && CCart::HasEnoughGoodToCreateFoundationCart(v14);
  byte_3F1E882 = v11;
  if ( *((_BYTE *)v14 + 216) )
  {
    dword_3F1E884 = *((unsigned __int8 *)v14 + 213) + *((unsigned __int8 *)v14 + 212);
    v2 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfPioneers);
    dword_3F1E888 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfCarrier) + v2;
    byte_3F1E880 = CCart::CanTakeLand(v14);
    for ( i = 0; ; ++i )
    {
      v3 = std::vector<CCart::CFoundationCardCargo>::size((char *)v14 + 196);
      if ( i >= v3 )
        break;
      v4 = (const struct CCart::CFoundationCardCargo *)std::vector<CCart::CFoundationCardCargo>::operator[](i);
      CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)v6, v4);
      dword_3F1E798[3 * i] = v9;
      dword_3F1E794[3 * i] = v8;
      dword_3F1E790[3 * i] = v7;
    }
  }
  else
  {
    byte_3F1E880 = 0;
    dword_3F1E884 = 0;
    dword_3F1E888 = 0;
    for ( j = 0; j < 6; ++j )
    {
      dword_3F1E794[3 * j] = *((_DWORD *)v14 + 3 * j + 58);
      dword_3F1E790[3 * j] = *((_DWORD *)v14 + 3 * j + 57);
    }
  }
  dword_3F1E78C = 21;
  v10 = 604;
  if ( !a2 )
    v10 = 602;
  CEvn_Event::CEvn_Event(&v15, v10, 0, (unsigned int)&g_cVehicleLoadInfo, 0);
  v16 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v15);
  v16 = -1;
  return CEvn_Event::~CEvn_Event(&v15);
}


// address=[0x1531270]
// Decompiled from void __thiscall CCart::VehicleLogicUpdate(CCart *this)
void  CCart::VehicleLogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+0h] [ebp-Ch]
  char v5; // [esp+4h] [ebp-8h]

  *((_BYTE *)this + 217) = CCart::IsOnOwnEcoSector(this);
  (*(void (__thiscall **)(CCart *))(*(_DWORD *)this + 172))(this);
  if ( IEntity::FlagBits(this, Selected) || IEntity::FlagBits(this, (EntityFlag)0x400u) )
    (*(void (__thiscall **)(CCart *, int))(*(_DWORD *)this + 148))(this, 1);
  v5 = *((_BYTE *)this + 107);
  if ( v5 == 17 )
  {
    if ( *((_BYTE *)this + 216) )
    {
      CCart::OnRequestSettlers(this);
      CCart::OnRequestCargo(this);
      IAnimatedEntity::RegisterForLogicUpdate(16);
    }
    else
    {
      v4 = std::auto_ptr<CWalking>::operator->(v3);
      v1 = IEntity::PackedXY(this);
      v2 = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 16))(v4, v1, 0);
      CVehicle::WalkDirAndRegister(this, v2, 0);
    }
  }
  else if ( v5 == 27 )
  {
    if ( *((_BYTE *)this + 216) )
    {
      CCart::OnRequestSettlers(this);
      CCart::OnRequestCargo(this);
      IAnimatedEntity::RegisterForLogicUpdate(16);
    }
  }
  else
  {
    if ( IEntity::FlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
      CVehicle::VehicleLogicUpdate(this);
    if ( *((unsigned __int8 *)this + 107) != *((unsigned __int8 *)this + 320) && *((_BYTE *)this + 320) == 6 )
      CCart::CartArrived(this);
    *((_BYTE *)this + 320) = *((_BYTE *)this + 107);
  }
}


// address=[0x15313e0]
// Decompiled from void __thiscall CCart::EntityEnter(CCart *this, int a2)
void  CCart::EntityEnter(int) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-18h]
  CEcoSector *EcoSectorPtr; // [esp+4h] [ebp-14h]
  int v9; // [esp+8h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-Ch]
  CPropertySet *v11; // [esp+10h] [ebp-8h]

  if ( *((_BYTE *)this + 216) )
  {
    for ( i = 0; i < std::vector<CCart::CSettlerStatus>::size((char *)this + 180); ++i )
    {
      v7 = *(_DWORD *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 8);
      if ( v7 && *(_DWORD *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 8) == a2 )
      {
        *(_BYTE *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 4) = 1;
        if ( CCart::IsPioner(this, a2) )
          ++*((_BYTE *)this + 212);
        if ( CCart::IsCarrier(this, a2) )
          ++*((_BYTE *)this + 213);
        v11 = (CPropertySet *)CSettlerMgr::operator[](v7);
        CWarMap::RemoveEntity(v11);
        v2 = IEntity::WorldIdx();
        CWorldManager::SetSettlerId(v2, 0);
        IEntity::SetFlagBits(v11, OnBoard);
        v3 = IEntity::ID();
        if ( CCart::IsCarrier(this, v3) )
        {
          v4 = IEntity::WorldIdx();
          v9 = CWorldManager::EcoSectorId(v4);
          if ( !v9 && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1643, "iESId!= 0") == 1 )
            __debugbreak();
          if ( !v9 )
            return;
          EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v9);
          if ( !EcoSectorPtr && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1646, "pSector!=NULL") == 1 )
            __debugbreak();
          if ( EcoSectorPtr )
          {
            v5 = IEntity::Type((unsigned __int16 *)v11);
            CEcoSector::ChangeNrOfSettler(EcoSectorPtr, v5, -1);
          }
        }
        if ( IEntity::FlagBits(v11, Selected) )
        {
          v6 = IEntity::ID();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v6);
        }
        CObserverList::Detach((CCart *)((char *)this + 156), v7);
        (*(void (__thiscall **)(CCart *, int))(*(_DWORD *)this + 148))(this, 1);
      }
    }
  }
  CVehicle::EntityEnter(this, a2);
}


// address=[0x1531620]
// Decompiled from void __thiscall CCart::EntityOrderCanceled(CCart *this, unsigned int a2)
void  CCart::EntityOrderCanceled(int) {
  
  _DWORD v2[4]; // [esp-Ch] [ebp-80h] BYREF
  _BYTE v3[12]; // [esp+4h] [ebp-70h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-64h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-58h] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-4Ch] BYREF
  _BYTE v7[12]; // [esp+34h] [ebp-40h] BYREF
  int v8; // [esp+40h] [ebp-34h]
  int v9; // [esp+44h] [ebp-30h]
  _DWORD *v10; // [esp+48h] [ebp-2Ch]
  int v11; // [esp+4Ch] [ebp-28h]
  int v12; // [esp+50h] [ebp-24h]
  int v13; // [esp+54h] [ebp-20h]
  std::_Iterator_base12 *v14; // [esp+58h] [ebp-1Ch]
  std::_Iterator_base12 *v15; // [esp+5Ch] [ebp-18h]
  CCart *v16; // [esp+60h] [ebp-14h]
  char v17; // [esp+67h] [ebp-Dh]
  int v18; // [esp+70h] [ebp-4h]

  v16 = this;
  if ( !CMapObjectMgr::ValidEntityId(a2)
    && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1712, "g_pMapObjectMgr->ValidEntityId(_iEntityId)") == 1 )
  {
    __debugbreak();
  }
  if ( CCart::WeAreWaitFor(v16, a2) )
  {
    if ( CCart::IsPioner(v16, a2) )
      ++*((_BYTE *)v16 + 214);
    if ( CCart::IsCarrier(v16, a2) )
      ++*((_BYTE *)v16 + 215);
    std::vector<CCart::CSettlerStatus>::begin(v7);
    v18 = 0;
    while ( 1 )
    {
      v15 = (std::_Iterator_base12 *)std::vector<CCart::CSettlerStatus>::end(v5);
      v14 = v15;
      LOBYTE(v18) = 1;
      v17 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::operator<(v15);
      LOBYTE(v18) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v5);
      if ( !v17 )
        break;
      v13 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::operator*(v7);
      if ( *(_DWORD *)(v13 + 8) == a2 )
      {
        v10 = v2;
        v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>((struct std::_Iterator_base12 *)v7);
        v8 = std::vector<CCart::CSettlerStatus>::erase(v4, v2[0], v2[1], v2[2]);
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v4);
        v12 = std::vector<CCart::CSettlerStatus>::end(v3);
        v11 = v12;
        LOBYTE(v18) = 2;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::operator=(v12);
        LOBYTE(v18) = 0;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v3);
      }
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::operator++(v6, 0);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v6);
    }
    v18 = -1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v7);
  }
  CVehicle::EntityOrderCanceled(v16, a2);
}


// address=[0x1531810]
// Decompiled from unsigned int __thiscall CCart::GoodIsComming(CCart *this, int a2, int a3)
void  CCart::GoodIsComming(int,int) {
  
  unsigned int result; // eax
  int v5; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( a2 != 18
    && a2 != 7
    && a2 != 32
    && BBSupportDbgReport(
         2,
         "MapObjects\\Cart.cpp",
         1869,
         "(_iGoodType == GOOD_HAMMER) || (_iGoodType == GOOD_BOARD) || (_iGoodType == GOOD_STONE)") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; ; ++i )
  {
    result = std::vector<CCart::CFoundationCardCargo>::size((char *)this + 196);
    if ( i >= result )
      break;
    v5 = std::vector<CCart::CFoundationCardCargo>::operator[](i);
    if ( *(_DWORD *)(v5 + 4) == a2 )
    {
      result = a3 + *(_DWORD *)(v5 + 12);
      *(_DWORD *)(v5 + 12) = result;
      return result;
    }
  }
  return result;
}


// address=[0x15318b0]
// Decompiled from unsigned int __thiscall CCart::GoodArrived(CCart *this, int a2, int a3)
void  CCart::GoodArrived(int,int) {
  
  unsigned int result; // eax
  unsigned int i; // [esp+0h] [ebp-Ch]
  _DWORD *v6; // [esp+8h] [ebp-4h]

  if ( a2 != 18
    && a2 != 7
    && a2 != 32
    && BBSupportDbgReport(
         2,
         "MapObjects\\Cart.cpp",
         1888,
         "(_iGoodType == GOOD_HAMMER) || (_iGoodType == GOOD_BOARD) || (_iGoodType == GOOD_STONE)") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; ; ++i )
  {
    result = std::vector<CCart::CFoundationCardCargo>::size((char *)this + 196);
    if ( i >= result )
      break;
    v6 = (_DWORD *)std::vector<CCart::CFoundationCardCargo>::operator[](i);
    if ( v6[1] == a2 )
    {
      if ( v6[2] > *v6
        && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1894, "Cargo.m_iArrived <= Cargo.m_iAmount") == 1 )
      {
        __debugbreak();
      }
      if ( v6[2] > *v6 )
        return (*(int (__thiscall **)(CCart *, int))(*(_DWORD *)this + 148))(this, 1);
      v6[2] += a3;
      *((_BYTE *)this + 218) += a3;
      return (*(int (__thiscall **)(CCart *, int))(*(_DWORD *)this + 148))(this, 1);
    }
  }
  return result;
}


// address=[0x15319c0]
// Decompiled from unsigned int __thiscall CCart::SupplyCanceled(CCart *this, int a2, int a3)
void  CCart::SupplyCanceled(int,int) {
  
  unsigned int result; // eax
  int v4; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+4h] [ebp-8h]

  if ( a2 != 18
    && a2 != 7
    && a2 != 32
    && BBSupportDbgReport(
         2,
         "MapObjects\\Cart.cpp",
         1913,
         "(_iGoodType == GOOD_HAMMER) || (_iGoodType == GOOD_BOARD) || (_iGoodType == GOOD_STONE)") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; ; ++i )
  {
    result = std::vector<CCart::CFoundationCardCargo>::size((char *)this + 196);
    if ( i >= result )
      break;
    v4 = std::vector<CCart::CFoundationCardCargo>::operator[](i);
    if ( *(_DWORD *)(v4 + 4) == a2 )
    {
      *(_DWORD *)(v4 + 12) -= a3;
      *((_BYTE *)this + 218) -= a3;
      if ( *(int *)(v4 + 12) < 0 && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1922, "Cargo.m_iRequested>=0") == 1 )
        __debugbreak();
      return (*(int (__thiscall **)(CCart *, int))(*(_DWORD *)this + 148))(this, 1);
    }
  }
  return result;
}


// address=[0x1531ac0]
// Decompiled from char __thiscall CCart::CreateFoundationCart(CCart *this)
bool  CCart::CreateFoundationCart(void) {
  
  int v1; // eax
  CEcoSector *v3; // eax
  int v4; // esi
  int v5; // esi
  int v6; // eax
  CEcoSector *v7; // eax
  int v8; // esi
  int v9; // esi
  int v10; // eax
  CEcoSector *v11; // eax
  int v12; // esi
  int v13; // esi
  int v14; // eax
  int IntValue; // eax
  int v16; // eax
  int v17; // eax
  char v18; // bl
  char v19; // bl
  char v20; // al
  int v21; // eax
  char v22; // [esp-10h] [ebp-F0h] BYREF
  int v23; // [esp-Ch] [ebp-ECh]
  int v24; // [esp-8h] [ebp-E8h]
  int v25; // [esp-4h] [ebp-E4h]
  int v26; // [esp+0h] [ebp-E0h]
  int v27; // [esp+4h] [ebp-DCh]
  _BYTE v28[20]; // [esp+Ch] [ebp-D4h] BYREF
  _BYTE v29[20]; // [esp+20h] [ebp-C0h] BYREF
  _BYTE v30[20]; // [esp+34h] [ebp-ACh] BYREF
  _BYTE v31[12]; // [esp+48h] [ebp-98h] BYREF
  _BYTE v32[12]; // [esp+54h] [ebp-8Ch] BYREF
  _BYTE v33[12]; // [esp+60h] [ebp-80h] BYREF
  _BYTE v34[12]; // [esp+6Ch] [ebp-74h] BYREF
  _BYTE v35[12]; // [esp+78h] [ebp-68h] BYREF
  _BYTE v36[12]; // [esp+84h] [ebp-5Ch] BYREF
  int v37; // [esp+90h] [ebp-50h]
  int v38; // [esp+94h] [ebp-4Ch]
  char *v39; // [esp+98h] [ebp-48h]
  int v40; // [esp+9Ch] [ebp-44h]
  int v41; // [esp+A0h] [ebp-40h]
  char *v42; // [esp+A4h] [ebp-3Ch]
  int v43; // [esp+A8h] [ebp-38h]
  int v44; // [esp+ACh] [ebp-34h]
  char *v45; // [esp+B0h] [ebp-30h]
  struct std::_Iterator_base12 *v46; // [esp+B4h] [ebp-2Ch]
  struct std::_Iterator_base12 *v47; // [esp+B8h] [ebp-28h]
  struct std::_Iterator_base12 *v48; // [esp+BCh] [ebp-24h]
  struct std::_Iterator_base12 *v49; // [esp+C0h] [ebp-20h]
  struct std::_Iterator_base12 *v50; // [esp+C4h] [ebp-1Ch]
  struct std::_Iterator_base12 *v51; // [esp+C8h] [ebp-18h]
  int v52; // [esp+CCh] [ebp-14h]
  _DWORD *v53; // [esp+D0h] [ebp-10h]
  int v54; // [esp+DCh] [ebp-4h]

  v53 = this;
  if ( *((_BYTE *)this + 216) || !*((_BYTE *)v53 + 217) )
    return 0;
  v1 = IEntity::WorldIdx();
  v52 = CWorldManager::EcoSectorId(v1);
  if ( !v52 )
    return 0;
  v3 = (CEcoSector *)CEcoSectorMgr::operator[](v52);
  v4 = CEcoSector::NrOfGoods(v3, 7);
  if ( v4 >= CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfBoard) )
  {
    v7 = (CEcoSector *)CEcoSectorMgr::operator[](v52);
    v8 = CEcoSector::NrOfGoods(v7, 32);
    if ( v8 >= CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfStone) )
    {
      v11 = (CEcoSector *)CEcoSectorMgr::operator[](v52);
      v12 = CEcoSector::NrOfGoods(v11, 18);
      if ( v12 >= CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfHammer) )
      {
        *((_BYTE *)v53 + 214) = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfPioneers);
        *((_BYTE *)v53 + 215) = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfCarrier);
        *((_BYTE *)v53 + 218) = 0;
        *((_BYTE *)v53 + 216) = 1;
        std::vector<CCart::CSettlerStatus>::clear(v26, v27);
        std::vector<CCart::CFoundationCardCargo>::clear(v26, v27);
        IntValue = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfBoard);
        v25 = CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)v30, 7, IntValue, 0, 0);
        v51 = (struct std::_Iterator_base12 *)std::vector<CCart::CFoundationCardCargo>::end(v35);
        v50 = v51;
        v54 = 0;
        v45 = &v22;
        v44 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v51);
        v43 = std::vector<CCart::CFoundationCardCargo>::insert(v36, v22, v23, v24, v25);
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v36);
        v54 = -1;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v35);
        v25 = 0;
        v24 = 0;
        v16 = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfStone);
        v25 = CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)v29, 32, v16, v24, v25);
        v49 = (struct std::_Iterator_base12 *)std::vector<CCart::CFoundationCardCargo>::end(v33);
        v48 = v49;
        v54 = 1;
        v42 = &v22;
        v41 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v49);
        v40 = std::vector<CCart::CFoundationCardCargo>::insert(v34, v22, v23, v24, v25);
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v34);
        v54 = -1;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v33);
        v25 = 0;
        v24 = 0;
        v17 = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfHammer);
        v25 = CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)v28, 18, v17, v24, v25);
        v47 = (struct std::_Iterator_base12 *)std::vector<CCart::CFoundationCardCargo>::end(v31);
        v46 = v47;
        v54 = 2;
        v39 = &v22;
        v38 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v47);
        v37 = std::vector<CCart::CFoundationCardCargo>::insert(v32, v22, v23, v24, v25);
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v32);
        v54 = -1;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v31);
        v18 = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfBoard);
        v19 = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfStone) + v18;
        v20 = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfHammer);
        *((_BYTE *)v53 + 219) = v20 + v19;
        IEntity::SetFlagBits(v53, VulnerableMask);
        v21 = IEntity::ID();
        CInputProcessor::DeSelectEntity(&g_cInputProcessor, v21);
        IAnimatedEntity::RegisterForLogicUpdate(16);
        *((_BYTE *)v53 + 107) = 27;
        return 1;
      }
      else
      {
        v13 = IEntity::OwnerId((unsigned __int8 *)v53);
        if ( v13 != CPlayerManager::GetLocalPlayerId() )
          return 0;
        v25 = IEntity::Y(v53);
        v24 = IEntity::X(v53);
        v14 = IEntity::OwnerId((unsigned __int8 *)v53);
        CTextMsgHandler::AddWarningMsg(2464, v14, v24, v25);
        return 0;
      }
    }
    else
    {
      v9 = IEntity::OwnerId((unsigned __int8 *)v53);
      if ( v9 != CPlayerManager::GetLocalPlayerId() )
        return 0;
      v25 = IEntity::Y(v53);
      v24 = IEntity::X(v53);
      v10 = IEntity::OwnerId((unsigned __int8 *)v53);
      CTextMsgHandler::AddWarningMsg(2467, v10, v24, v25);
      return 0;
    }
  }
  else
  {
    v5 = IEntity::OwnerId((unsigned __int8 *)v53);
    if ( v5 != CPlayerManager::GetLocalPlayerId() )
      return 0;
    v25 = IEntity::Y(v53);
    v24 = IEntity::X(v53);
    v6 = IEntity::OwnerId((unsigned __int8 *)v53);
    CTextMsgHandler::AddWarningMsg(2466, v6, v24, v25);
    return 0;
  }
}


// address=[0x1531ed0]
// Decompiled from bool __thiscall CCart::CreateNormalCart(CCart *this)
bool  CCart::CreateNormalCart(void) {
  
  unsigned int v1; // eax
  int v2; // eax
  _BYTE v4[24]; // [esp+4h] [ebp-3Ch] BYREF
  CEntityEvent *v5; // [esp+1Ch] [ebp-24h]
  CEntityEvent *v6; // [esp+20h] [ebp-20h]
  int v7; // [esp+24h] [ebp-1Ch]
  int v8; // [esp+28h] [ebp-18h]
  unsigned int i; // [esp+2Ch] [ebp-14h]
  CCart *v10; // [esp+30h] [ebp-10h]
  int v11; // [esp+3Ch] [ebp-4h]

  v10 = this;
  if ( !*((_BYTE *)this + 216) )
    return 0;
  for ( i = 0; ; ++i )
  {
    v1 = std::vector<CCart::CSettlerStatus>::size((char *)v10 + 180);
    if ( i >= v1 )
      break;
    v8 = std::vector<CCart::CSettlerStatus>::operator[](i);
    if ( !*(_BYTE *)(v8 + 4) )
    {
      if ( *(_DWORD *)v8 )
      {
        v7 = CSettlerMgr::operator[](*(_DWORD *)(v8 + 8));
        v2 = IEntity::ID();
        v6 = CEntityEvent::CEntityEvent((CEntityEvent *)v4, 9u, 0, v2, 0, 0);
        v5 = v6;
        v11 = 0;
        (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v7 + 80))(v7, v6);
        v11 = -1;
        CEntityEvent::~CEntityEvent(v4);
      }
    }
  }
  return CCart::OnUnload(v10);
}


// address=[0x1531fe0]
// Decompiled from char __thiscall CCart::CreateSettlement(CCart *this)
bool  CCart::CreateSettlement(void) {
  
  if ( !*((_BYTE *)this + 216) || !CCart::CanTakeLand(this) )
    return 0;
  CCart::TakeLand(this);
  CCart::OnUnload(this);
  CCart::OnDestroyFoundationCart(this);
  return 1;
}


// address=[0x1532030]
// Decompiled from void __thiscall CCart::ConvertEventIntoGoal(CCart *this, struct CEntityEvent *a2)
void  CCart::ConvertEventIntoGoal(class CEntityEvent *) {
  
  if ( *((_DWORD *)a2 + 1) == 9 || *((_DWORD *)a2 + 1) == 7 )
  {
    if ( *((_DWORD *)a2 + 3) == *((_DWORD *)this + 77) )
      CCart::TargetBuildingDestroyed(this);
    if ( *((_DWORD *)a2 + 3) == *((_DWORD *)this + 78) )
      CCart::DepartBuildingDestroyed(this);
  }
  if ( *((_DWORD *)a2 + 1) == 17 && *((_DWORD *)a2 + 2) == 13 )
    *((_DWORD *)this + 76) = IEntity::PackedXY(this);
  CWheeler::ConvertEventIntoGoal(this, a2);
}


// address=[0x15320b0]
// Decompiled from void __thiscall CCart::Decrease(CCart *this, int a2)
void  CCart::Decrease(int) {
  
  if ( *((_BYTE *)this + 216) )
  {
    IEntity::Decrease((int)this, a2);
  }
  else if ( CCart::HasLoadedSomething(this) )
  {
    CCart::DropGoods(this);
    IEntity::ClearFlagBits(this, VulnerableMask);
    CCart::TargetBuildingDestroyed(this);
  }
  else
  {
    IEntity::ClearFlagBits(this, VulnerableMask);
  }
}


// address=[0x1532120]
// Decompiled from int __thiscall CCart::GetGoodAmount(CCart *this, int a2)
int  CCart::GetGoodAmount(int) {
  
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 6; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 57) == a2 )
      v3 += *((_DWORD *)this + 3 * i + 58);
  }
  return v3;
}


// address=[0x1532180]
// Decompiled from int __thiscall CCart::AddGood(CCart *this, int a2, int a3)
int  CCart::AddGood(int,int) {
  
  int v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  int i; // [esp+10h] [ebp-8h]
  int j; // [esp+10h] [ebp-8h]

  for ( i = 0; i < 6; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 57) == a2 && *((_DWORD *)this + 3 * i + 58) != 8 )
    {
      if ( 8 - *((_DWORD *)this + 3 * i + 58) >= a3 )
        v5 = a3;
      else
        v5 = 8 - *((_DWORD *)this + 3 * i + 58);
      *((_DWORD *)this + 3 * i + 58) += v5;
      a3 -= v5;
    }
  }
  if ( a3 )
  {
    for ( j = 0; j < 6; ++j )
    {
      if ( !*((_DWORD *)this + 3 * j + 57) && a3 )
      {
        if ( a3 <= 8 )
          v4 = a3;
        else
          v4 = 8;
        *((_DWORD *)this + 3 * j + 58) += v4;
        *((_DWORD *)this + 3 * j + 57) = a2;
        if ( *((int *)this + 3 * j + 58) > 0 )
          IEntity::SetFlagBits(this, VulnerableMask);
        a3 -= v4;
      }
    }
  }
  if ( IEntity::FlagBits(this, (EntityFlag)0x600u) )
    (*(void (__thiscall **)(CCart *, int))(*(_DWORD *)this + 148))(this, 1);
  if ( !CCart::HasLoadedSomething(this) || *((_BYTE *)this + 321) )
    IEntity::ClearFlagBits(this, VulnerableMask);
  else
    IEntity::SetFlagBits(this, VulnerableMask);
  return a3;
}


// address=[0x1532340]
// Decompiled from int __thiscall CCart::RemoveGood(CCart *this, int a2, int a3)
int  CCart::RemoveGood(int,int) {
  
  int v4; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  for ( i = 0; i < 6; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 57) == a2 )
    {
      if ( *((_DWORD *)this + 3 * i + 58) >= a3 )
        v4 = a3;
      else
        v4 = *((_DWORD *)this + 3 * i + 58);
      *((_DWORD *)this + 3 * i + 58) -= v4;
      if ( !*((_DWORD *)this + 3 * i + 58) )
        *((_DWORD *)this + 3 * i + 57) = 0;
      a3 -= v4;
    }
  }
  if ( IEntity::FlagBits(this, Selected) )
    (*(void (__thiscall **)(CCart *, int))(*(_DWORD *)this + 148))(this, 1);
  if ( !CCart::HasLoadedSomething(this) )
    IEntity::ClearFlagBits(this, VulnerableMask);
  return a3;
}


// address=[0x1532450]
// Decompiled from char __thiscall CCart::IsSpaceAvailable(CCart *this, int a2)
bool  CCart::IsSpaceAvailable(int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    if ( !*((_DWORD *)this + 3 * i + 57) )
      return 1;
    if ( *((_DWORD *)this + 3 * i + 57) == a2 && 8 - *((_DWORD *)this + 3 * i + 58) > 0 )
      return 1;
  }
  return 0;
}


// address=[0x15324c0]
// Decompiled from int __thiscall CCart::GetAvailableSpace(CCart *this, int a2)
int  CCart::GetAvailableSpace(int) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 6; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 57) == a2 && 8 - *((_DWORD *)this + 3 * i + 58) > 0 )
      v3 += 8 - *((_DWORD *)this + 3 * i + 58);
  }
  return v3;
}


// address=[0x1532540]
// Decompiled from int __thiscall CCart::GetAvailableSpace(CCart *this)
int  CCart::GetAvailableSpace(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < 6; ++i )
  {
    if ( !*((_DWORD *)this + 3 * i + 57) )
      v2 += 8;
  }
  return v2;
}


// address=[0x1532590]
// Decompiled from char __thiscall CCart::IsFull(CCart *this)
bool  CCart::IsFull(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    if ( !*((_DWORD *)this + 3 * i + 57) )
      return 0;
    if ( 8 - *((_DWORD *)this + 3 * i + 58) > 0 )
      return 0;
  }
  return 1;
}


// address=[0x15325f0]
// Decompiled from char __thiscall CCart::HasLoadedSomething(CCart *this)
bool  CCart::HasLoadedSomething(void) {
  
  unsigned int j; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  unsigned int k; // [esp+10h] [ebp-8h]
  char v6; // [esp+17h] [ebp-1h]

  v6 = 0;
  for ( i = 0; i < 6 && !v6; ++i )
    v6 = *((_DWORD *)this + 3 * i + 58) != 0;
  for ( j = 0; j < std::vector<CCart::CFoundationCardCargo>::size((char *)this + 196) && !v6; ++j )
    v6 = *(_DWORD *)(std::vector<CCart::CFoundationCardCargo>::operator[](j) + 8) > 0;
  for ( k = 0; k < std::vector<CCart::CSettlerStatus>::size((char *)this + 180) && !v6; ++k )
    v6 = *(_BYTE *)(std::vector<CCart::CSettlerStatus>::operator[](k) + 4);
  return v6;
}


// address=[0x15326f0]
// Decompiled from void __thiscall CCart::SetTargetBuildingID(CMFCPopupMenu *this, struct CWnd *a2)
void  CCart::SetTargetBuildingID(int) {
  
  *((_DWORD *)this + 77) = a2;
}


// address=[0x1532710]
// Decompiled from int __thiscall CCart::GetTargetBuildingID(CCart *this)
int  CCart::GetTargetBuildingID(void) {
  
  return *((_DWORD *)this + 77);
}


// address=[0x1532730]
// Decompiled from void __thiscall CCart::TargetBuildingDestroyed(CCart *this)
void  CCart::TargetBuildingDestroyed(void) {
  
  int v1; // eax
  int v2; // eax
  char IsNeutralTrader; // [esp-4h] [ebp-1Ch]
  CTradingBuildingRole *v4; // [esp+0h] [ebp-18h]
  struct CWnd *v5; // [esp+4h] [ebp-14h]
  CTradingBuildingRole *v6; // [esp+8h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *v8; // [esp+10h] [ebp-8h]

  if ( *((_DWORD *)this + 77) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 77));
    v6 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    v1 = IEntity::ID();
    CTradingBuildingRole::UnregisterIncomingTrader(v6, v1, 3);
  }
  CCart::SetTargetBuildingID(this, 0);
  if ( *((_DWORD *)this + 78) )
  {
    v5 = (struct CWnd *)*((_DWORD *)this + 78);
    v8 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, (int)v5);
    if ( *((_BYTE *)this + 302) )
      CCart::SetGoToTarget(this, 0);
    CCart::SetDepartBuildingID(this, 0);
    CCart::SetTargetBuildingID(this, v5);
    if ( v8 )
    {
      v4 = (CTradingBuildingRole *)CBuilding::Role(v8);
      IsNeutralTrader = CCart::IsNeutralTrader(this);
      v2 = IEntity::ID();
      CTradingBuildingRole::RegisterIncomingTrader(v4, v2, 3, IsNeutralTrader);
      CCart::MoveToTarget(this);
    }
    else
    {
      CCart::SetFree(this);
      CCart::SetJobType(this, 0);
      CCart::TryToGoHome(this);
    }
  }
  else
  {
    CCart::SetJobType(this, 0);
    CCart::TryToGoHome(this);
  }
}


// address=[0x1532860]
// Decompiled from CCart *__thiscall CCart::SetDepartBuildingID(CCart *this, int a2)
void  CCart::SetDepartBuildingID(int) {
  
  CCart *result; // eax

  result = this;
  *((_DWORD *)this + 78) = a2;
  return result;
}


// address=[0x1532880]
// Decompiled from int __thiscall CCart::GetDepartBuildingID(CMFCBaseTabCtrl *this)
int  CCart::GetDepartBuildingID(void) {
  
  return *((_DWORD *)this + 78);
}


// address=[0x15328a0]
// Decompiled from void __thiscall CCart::DepartBuildingDestroyed(CCart *this)
void  CCart::DepartBuildingDestroyed(void) {
  
  int v1; // eax
  CTradingBuildingRole *v2; // [esp+0h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]

  v4 = *((_DWORD *)this + 78);
  CCart::SetDepartBuildingID(this, 0);
  if ( *((_BYTE *)this + 300) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v4);
    v2 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    v1 = IEntity::ID();
    CTradingBuildingRole::UnregisterIncomingTrader(v2, v1, 3);
    CCart::SetJobType(this, 0);
    CCart::TryToGoHome(this);
  }
}


// address=[0x1532920]
// Decompiled from void __thiscall CCart::CartArrived(CCart *this)
void  CCart::CartArrived(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  CTradingBuildingRole *v4; // [esp+0h] [ebp-14h]
  CTradingBuildingRole *v5; // [esp+4h] [ebp-10h]
  CTradingBuildingRole *v6; // [esp+8h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v8; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v9; // [esp+Ch] [ebp-8h]

  if ( *((_BYTE *)this + 300) )
  {
    if ( *((_DWORD *)this + 78) )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 78));
      if ( BuildingPtr )
      {
        v6 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
        v1 = IEntity::ID();
        CTradingBuildingRole::VehicleArrived(v6, v1, 3);
      }
    }
  }
  if ( *((_BYTE *)this + 302) )
  {
    if ( *((_DWORD *)this + 77) )
    {
      v8 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 77));
      if ( v8 )
      {
        v5 = (CTradingBuildingRole *)CBuilding::Role(v8);
        v2 = IEntity::ID();
        CTradingBuildingRole::VehicleArrived(v5, v2, 3);
        CCart::SetGoToTarget(this, 0);
      }
    }
    if ( *((_DWORD *)this + 78) )
    {
      v9 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 78));
      if ( v9 )
      {
        v4 = (CTradingBuildingRole *)CBuilding::Role(v9);
        v3 = IEntity::ID();
        CTradingBuildingRole::VehicleArrivedAtTarget(v4, v3, 3);
      }
    }
  }
}


// address=[0x1532a30]
// Decompiled from CCart *__thiscall CCart::MoveToTarget(CCart *this)
void  CCart::MoveToTarget(void) {
  
  CCart *result; // eax
  Y16X16 *v2; // eax
  int v3; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-8h]
  CCart *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  result = this;
  if ( !*((_DWORD *)this + 77) )
    return result;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)v6 + 77));
  if ( !BuildingPtr && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1492, "pTargetBuilding") == 1 )
    __debugbreak();
  v2 = (Y16X16 *)CBuilding::EnsignPackedXY(BuildingPtr);
  Y16X16::UnpackXYFast(v2, &v3, &v4);
  CCart::SetGoToSource(v6, 0);
  CCart::SetGoToTarget(v6, 1);
  return (CCart *)CVehicle::MoveTo(v6, v3, v4, 0);
}


// address=[0x1532ad0]
// Decompiled from void __thiscall CCart::TryToGoHome(CCart *this)
void  CCart::TryToGoHome(void) {
  
  int v1; // eax
  int v2; // esi
  int v3; // eax
  int v4; // [esp+4h] [ebp-Ch] BYREF
  int v5; // [esp+8h] [ebp-8h] BYREF
  CMFCPopupMenu *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  if ( *((int *)this + 76) <= 0 )
  {
    v4 = IEntity::X(v6);
    v5 = IEntity::Y(v6);
  }
  else
  {
    Y16X16::UnpackXYFast(*((Y16X16 **)v6 + 76), &v4, &v5);
  }
  v1 = CWorldManager::Index(v4, v5);
  v2 = CWorldManager::EcoSectorId(v1);
  v3 = IEntity::WorldIdx();
  if ( v2 == CWorldManager::EcoSectorId(v3) )
  {
    CCart::SetFree(v6);
    CVehicle::MoveTo(v6, v4, v5, 0);
    CCart::SetGoToSource(v6, 0);
    CCart::SetGoToTarget(v6, 0);
    CCart::SetTargetBuildingID(v6, 0);
    CCart::SetDepartBuildingID(v6, 0);
  }
  else
  {
    CVehicle::MoveTo(v6, v4, v5, 0);
    *((_DWORD *)v6 + 76) = -1;
  }
}


// address=[0x1532bb0]
// Decompiled from CCart *__thiscall CCart::SetJobType(CCart *this, int a2)
void  CCart::SetJobType(int) {
  
  CCart *result; // eax

  if ( !a2 )
  {
    result = this;
    if ( *((_DWORD *)this + 77) )
      CCart::SetTargetBuildingID(this, 0);
  }
  *((_DWORD *)this + 79) = a2;
  return result;
}


// address=[0x1532bf0]
// Decompiled from int __thiscall CCart::GetJobType(CCart *this)
int  CCart::GetJobType(void) {
  
  return *((_DWORD *)this + 79);
}


// address=[0x1532c10]
// Decompiled from CCart *__thiscall CCart::SetGoToSource(CCart *this, bool a2)
void  CCart::SetGoToSource(bool) {
  
  CCart *result; // eax

  result = this;
  *((_BYTE *)this + 300) = a2;
  return result;
}


// address=[0x1532c30]
// Decompiled from CCart *__thiscall CCart::SetGoToTarget(CCart *this, bool a2)
void  CCart::SetGoToTarget(bool) {
  
  CCart *result; // eax

  result = this;
  *((_BYTE *)this + 302) = a2;
  return result;
}


// address=[0x1532c50]
// Decompiled from CCart *__thiscall CCart::SetNeutralTraderStatus(CCart *this, bool a2)
void  CCart::SetNeutralTraderStatus(bool) {
  
  CCart *result; // eax

  result = this;
  *((_BYTE *)this + 321) = a2;
  return result;
}


// address=[0x1532c70]
// Decompiled from CCart *__thiscall CCart::ClearNeutralTraderStatus(CCart *this)
void  CCart::ClearNeutralTraderStatus(void) {
  
  CCart *result; // eax

  result = this;
  *((_BYTE *)this + 321) = 0;
  return result;
}


// address=[0x1532c90]
// Decompiled from int __thiscall CCart::OnBuildReady(CCart *this)
void  CCart::OnBuildReady(void) {
  
  int v1; // eax
  void **v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int result; // eax
  int LocalPlayerId; // eax
  int v8; // esi
  int v9; // eax
  int v10; // [esp-10h] [ebp-24h]
  int v11; // [esp-Ch] [ebp-20h]
  int v12; // [esp-8h] [ebp-1Ch]
  int v13; // [esp-8h] [ebp-1Ch]
  int v14; // [esp-4h] [ebp-18h]
  int v15; // [esp-4h] [ebp-18h]
  int v16; // [esp-4h] [ebp-18h]
  void **NearestEntity; // [esp+4h] [ebp-10h]
  CDonkeyRole *v18; // [esp+8h] [ebp-Ch]
  int v19; // [esp+Ch] [ebp-8h]

  v19 = 0;
  v18 = 0;
  v14 = IEntity::Y(this);
  v12 = IEntity::X(this);
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  NearestEntity = (void **)CTransportMgr::GetNearestEntity(1, 60, v1, v12, v14);
  if ( NearestEntity )
  {
    v19 = j____RTDynamicCast(
            NearestEntity,
            0,
            &IMovingEntity__RTTI_Type_Descriptor_,
            &CSettler__RTTI_Type_Descriptor_,
            0);
    if ( !v19 && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 2059, "pDonkey != 0") == 1 )
      __debugbreak();
  }
  if ( v19 )
  {
    v2 = (void **)CSettler::Role(v19);
    v18 = (CDonkeyRole *)j____RTDynamicCast(
                           v2,
                           0,
                           &ISettlerRole__RTTI_Type_Descriptor_,
                           &CDonkeyRole__RTTI_Type_Descriptor_,
                           0);
    if ( !v18 && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 2066, "pDonkeyRole != 0") == 1 )
      __debugbreak();
  }
  if ( v18 )
  {
    v15 = IEntity::ID();
    v3 = IEntity::ID();
    v4 = (*(int (__thiscall **)(CCart *, int, int))(*(_DWORD *)this + 228))(this, 1, v3);
    CDonkeyRole::ComeToBuildUpCart(v18, v4, v15);
    v5 = IEntity::OwnerId((unsigned __int8 *)this);
    result = CPlayerManager::GetLocalPlayerId();
    if ( v5 == result )
    {
      v11 = IEntity::Y(this);
      v10 = IEntity::X(this);
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      return CTextMsgHandler::AddTextMsg(1910, LocalPlayerId, v10, v11, 0, 0);
    }
  }
  else
  {
    v8 = IEntity::OwnerId((unsigned __int8 *)this);
    if ( v8 != CPlayerManager::GetLocalPlayerId() )
      return IAnimatedEntity::RegisterForLogicUpdate(16);
    v16 = IEntity::Y(this);
    v13 = IEntity::X(this);
    v9 = CPlayerManager::GetLocalPlayerId();
    CTextMsgHandler::AddWarningMsg(2528, v9, v13, v16);
    return IAnimatedEntity::RegisterForLogicUpdate(16);
  }
  return result;
}


// address=[0x1532e30]
// Decompiled from int __thiscall CCart::DonkeyArrived(CCart *this, unsigned int a2)
void  CCart::DonkeyArrived(int) {
  
  int v2; // eax
  int v3; // eax
  CPropertySet *v6; // [esp+4h] [ebp-4h]

  if ( !CMapObjectMgr::ValidEntityId(a2)
    && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 2095, "g_pMapObjectMgr->ValidEntityId(_iDonkeyID)") == 1 )
  {
    __debugbreak();
  }
  v6 = (CPropertySet *)CSettlerMgr::operator[](a2);
  CWarMap::RemoveEntity(v6);
  v2 = IEntity::WorldIdx();
  CWorldManager::SetSettlerId(v2, 0);
  IEntity::SetFlagBits(v6, OnBoard);
  if ( IEntity::FlagBits(v6, Selected) )
  {
    v3 = IEntity::ID();
    CInputProcessor::DeSelectEntity(&g_cInputProcessor, v3);
  }
  IEntity::ClearFlagBits(v6, Visible);
  IAnimatedEntity::UnRegisterFromLogicUpdate(v6);
  CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, a2);
  IEntity::ClearFlagBits(this, VulnerableMask);
  return CVehicle::OnBuildReady((int)this);
}


// address=[0x1532f10]
// Decompiled from _DWORD *__thiscall CCart::SetSelectable(CCart *this)
void  CCart::SetSelectable(void) {
  
  _DWORD *result; // eax
  bool v2; // [esp+0h] [ebp-Ch]
  bool v4; // [esp+9h] [ebp-3h]

  v4 = IEntity::FlagBits(this, (EntityFlag)0x400u) != 0;
  v2 = *((_BYTE *)this + 300) || *((_BYTE *)this + 301) || *((_BYTE *)this + 302);
  result = (_DWORD *)IEntity::FlagBits(this, (EntityFlag)&dword_F29144[220079]);
  if ( result )
    return result;
  (*(void (__thiscall **)(CCart *))(*(_DWORD *)this + 176))(this);
  if ( !*((_BYTE *)this + 216) || !CCart::CanWalk(this) || v2 || *((_DWORD *)this + 43) )
  {
    if ( IEntity::FlagBits(this, (EntityFlag)&dword_F29144[220079]) )
    {
      return 0;
    }
    else
    {
      result = IEntity::SetFlagBits(this, (EntityFlag)0x4000u);
      if ( v4 )
        return IEntity::SetFlagBits(this, (EntityFlag)0x400u);
    }
  }
  else
  {
    return IEntity::SetFlagBits(this, Selectable);
  }
  return result;
}


// address=[0x1533030]
// Decompiled from int __thiscall CCart::DeleteSelectable(CCart *this)
void  CCart::DeleteSelectable(void) {
  
  if ( IEntity::FlagBits(this, (EntityFlag)0x400u) )
    return IEntity::ClearFlagBits(this, (EntityFlag)0x4400u);
  else
    return IEntity::ClearFlagBits(this, (EntityFlag)0x2400u);
}


// address=[0x15335c0]
// Decompiled from CCart *__thiscall CCart::CCart(CCart *this, int a2)
 CCart::CCart(std::istream &) {
  
  char v3; // [esp-10h] [ebp-B8h] BYREF
  int v4; // [esp-Ch] [ebp-B4h]
  int v5; // [esp-8h] [ebp-B0h]
  _BYTE *v6; // [esp-4h] [ebp-ACh]
  int v7; // [esp+0h] [ebp-A8h]
  _DWORD v8[3]; // [esp+4h] [ebp-A4h] BYREF
  _BYTE v9[12]; // [esp+10h] [ebp-98h] BYREF
  _BYTE v10[12]; // [esp+1Ch] [ebp-8Ch] BYREF
  _BYTE v11[12]; // [esp+28h] [ebp-80h] BYREF
  int v12; // [esp+34h] [ebp-74h]
  int v13; // [esp+38h] [ebp-70h]
  char *v14; // [esp+3Ch] [ebp-6Ch]
  int v15; // [esp+40h] [ebp-68h]
  int v16; // [esp+44h] [ebp-64h]
  char *v17; // [esp+48h] [ebp-60h]
  _BYTE v18[4]; // [esp+4Ch] [ebp-5Ch] BYREF
  _BYTE v19[4]; // [esp+50h] [ebp-58h] BYREF
  _BYTE v20[4]; // [esp+54h] [ebp-54h] BYREF
  _BYTE v21[8]; // [esp+58h] [ebp-50h] BYREF
  _BYTE v22[4]; // [esp+60h] [ebp-48h] BYREF
  _BYTE v23[4]; // [esp+64h] [ebp-44h] BYREF
  _BYTE v24[4]; // [esp+68h] [ebp-40h] BYREF
  int v25; // [esp+6Ch] [ebp-3Ch]
  struct std::_Iterator_base12 *v26; // [esp+70h] [ebp-38h]
  struct std::_Iterator_base12 *v27; // [esp+74h] [ebp-34h]
  struct std::_Iterator_base12 *v28; // [esp+78h] [ebp-30h]
  struct std::_Iterator_base12 *v29; // [esp+7Ch] [ebp-2Ch]
  int v30; // [esp+80h] [ebp-28h] BYREF
  int pExceptionObject; // [esp+84h] [ebp-24h] BYREF
  unsigned int v32; // [esp+88h] [ebp-20h] BYREF
  int j; // [esp+8Ch] [ebp-1Ch]
  int i; // [esp+90h] [ebp-18h]
  unsigned __int8 v35; // [esp+96h] [ebp-12h] BYREF
  unsigned __int8 v36; // [esp+97h] [ebp-11h] BYREF
  CCart *v37; // [esp+98h] [ebp-10h]
  int v38; // [esp+A4h] [ebp-4h]

  v37 = this;
  CWheeler::CWheeler(a2);
  v38 = 0;
  *(_DWORD *)v37 = &CCart::_vftable_;
  std::vector<CCart::CSettlerStatus>::vector<CCart::CSettlerStatus>(v7, v8[0]);
  std::vector<CCart::CFoundationCardCargo>::vector<CCart::CFoundationCardCargo>(v7, v8[0]);
  LOBYTE(v38) = 2;
  operator^<unsigned int>(a2, &v32);
  if ( !v32 || v32 > 2 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CCart");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, (char *)v37 + 212);
  operator^<unsigned char>(a2, (char *)v37 + 213);
  operator^<unsigned char>(a2, (char *)v37 + 214);
  operator^<unsigned char>(a2, (char *)v37 + 215);
  operator^<bool>(a2, (char *)v37 + 216);
  operator^<bool>(a2, (char *)v37 + 217);
  operator^<unsigned char>(a2, (char *)v37 + 218);
  operator^<unsigned char>(a2, (char *)v37 + 219);
  operator^<int>(a2, (int)v37 + 224);
  operator^<unsigned char>(a2, (char *)v37 + 120);
  operator^<unsigned char>(a2, (char *)v37 + 121);
  operator^<unsigned char>(a2, (char *)v37 + 122);
  operator^<unsigned char>(a2, (char *)v37 + 123);
  operator^<unsigned short>(a2, (char *)v37 + 124);
  operator^<unsigned short>(a2, (char *)v37 + 126);
  operator^<unsigned short>(a2, (char *)v37 + 128);
  operator^<unsigned short>(a2, (char *)v37 + 130);
  operator^<unsigned short>(a2, (char *)v37 + 132);
  operator^<float>(a2, (char *)v37 + 136);
  operator^<bool>(a2, (char *)v37 + 300);
  operator^<bool>(a2, (char *)v37 + 301);
  operator^<bool>(a2, (char *)v37 + 302);
  operator^<int>(a2, (int)v37 + 304);
  operator^<int>(a2, (int)v37 + 308);
  operator^<int>(a2, (int)v37 + 312);
  operator^<int>(a2, (int)v37 + 316);
  operator^<unsigned char>(a2, (char *)v37 + 320);
  operator^<unsigned char>(a2, &v36);
  for ( i = 0; i < v36; ++i )
  {
    CCart::CSettlerStatus::CSettlerStatus((CCart::CSettlerStatus *)v22);
    LOBYTE(v38) = 3;
    operator^<int>(a2, (int)v22);
    operator^<bool>(a2, v23);
    operator^<int>(a2, (int)v24);
    operator^<int>(a2, (int)&v30);
    v25 = v30;
    v6 = v22;
    v29 = (struct std::_Iterator_base12 *)std::vector<CCart::CSettlerStatus>::end(v10);
    v28 = v29;
    LOBYTE(v38) = 4;
    v17 = &v3;
    v16 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v29);
    v15 = std::vector<CCart::CSettlerStatus>::insert(v11, v3, v4, v5, v6);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v11);
    LOBYTE(v38) = 3;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v10);
    LOBYTE(v38) = 2;
    CCart::CSettlerStatus::~CSettlerStatus((CCart::CSettlerStatus *)v22);
  }
  operator^<unsigned char>(a2, &v35);
  for ( j = 0; j < v35; ++j )
  {
    CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)v18);
    operator^<int>(a2, (int)v18);
    operator^<int>(a2, (int)v19);
    operator^<int>(a2, (int)v20);
    operator^<int>(a2, (int)v21);
    v6 = v18;
    v27 = (struct std::_Iterator_base12 *)std::vector<CCart::CFoundationCardCargo>::end(v8);
    v26 = v27;
    LOBYTE(v38) = 5;
    v14 = &v3;
    v13 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v27);
    v12 = std::vector<CCart::CFoundationCardCargo>::insert(v9, v3, v4, v5, v6);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v9);
    LOBYTE(v38) = 2;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v8);
  }
  LoadArray<SLoadInfo>(a2, (char *)v37 + 228, 72);
  if ( v32 == 2 )
    operator^<bool>(a2, (char *)v37 + 321);
  CCart::SetSelectable(v37);
  v38 = -1;
  return v37;
}


// address=[0x1533af0]
// Decompiled from int __thiscall CCart::Store(char *this, struct std::ostream *a2)
void  CCart::Store(std::ostream &) {
  
  const struct CCart::CSettlerStatus *v2; // eax
  const struct CCart::CFoundationCardCargo *v3; // eax
  int v5; // [esp+4h] [ebp-48h] BYREF
  int v6; // [esp+8h] [ebp-44h] BYREF
  int v7; // [esp+Ch] [ebp-40h] BYREF
  int v8; // [esp+10h] [ebp-3Ch] BYREF
  int v9; // [esp+18h] [ebp-34h] BYREF
  char v10[4]; // [esp+1Ch] [ebp-30h] BYREF
  int v11[2]; // [esp+20h] [ebp-2Ch] BYREF
  int v12; // [esp+28h] [ebp-24h] BYREF
  int v13; // [esp+2Ch] [ebp-20h] BYREF
  int j; // [esp+30h] [ebp-1Ch]
  int i; // [esp+34h] [ebp-18h]
  char *v16; // [esp+38h] [ebp-14h]
  unsigned __int8 v17; // [esp+3Eh] [ebp-Eh] BYREF
  unsigned __int8 v18; // [esp+3Fh] [ebp-Dh] BYREF
  int v19; // [esp+48h] [ebp-4h]

  v16 = this;
  CWheeler::Store(a2);
  v13 = 2;
  operator^<unsigned int>(a2, &v13);
  operator^<unsigned char>(a2, (int)(v16 + 212));
  operator^<unsigned char>(a2, (int)(v16 + 213));
  operator^<unsigned char>(a2, (int)(v16 + 214));
  operator^<unsigned char>(a2, (int)(v16 + 215));
  operator^<bool>((int)a2, (int)(v16 + 216));
  operator^<bool>((int)a2, (int)(v16 + 217));
  operator^<unsigned char>(a2, (int)(v16 + 218));
  operator^<unsigned char>(a2, (int)(v16 + 219));
  operator^<int>((int)a2, (int *)v16 + 56);
  operator^<unsigned char>(a2, (int)(v16 + 120));
  operator^<unsigned char>(a2, (int)(v16 + 121));
  operator^<unsigned char>(a2, (int)(v16 + 122));
  operator^<unsigned char>(a2, (int)(v16 + 123));
  operator^<unsigned short>((int)a2, (__int16 *)v16 + 62);
  operator^<unsigned short>((int)a2, (__int16 *)v16 + 63);
  operator^<unsigned short>((int)a2, (__int16 *)v16 + 64);
  operator^<unsigned short>((int)a2, (__int16 *)v16 + 65);
  operator^<unsigned short>((int)a2, (__int16 *)v16 + 66);
  operator^<float>(a2, v16 + 136);
  operator^<bool>((int)a2, (int)(v16 + 300));
  operator^<bool>((int)a2, (int)(v16 + 301));
  operator^<bool>((int)a2, (int)(v16 + 302));
  operator^<int>((int)a2, (int *)v16 + 76);
  operator^<int>((int)a2, (int *)v16 + 77);
  operator^<int>((int)a2, (int *)v16 + 78);
  operator^<int>((int)a2, (int *)v16 + 79);
  operator^<unsigned char>(a2, (int)(v16 + 320));
  v18 = std::vector<CCart::CSettlerStatus>::size(v16 + 180);
  operator^<unsigned char>(a2, (int)&v18);
  for ( i = 0; i < v18; ++i )
  {
    v2 = (const struct CCart::CSettlerStatus *)std::vector<CCart::CSettlerStatus>::operator[](i);
    CCart::CSettlerStatus::CSettlerStatus((CCart::CSettlerStatus *)&v9, v2);
    v19 = 0;
    operator^<int>((int)a2, &v9);
    operator^<bool>((int)a2, (int)v10);
    operator^<int>((int)a2, v11);
    v12 = v11[1];
    operator^<int>((int)a2, &v12);
    v19 = -1;
    CCart::CSettlerStatus::~CSettlerStatus((CCart::CSettlerStatus *)&v9);
  }
  v17 = std::vector<CCart::CFoundationCardCargo>::size(v16 + 196);
  operator^<unsigned char>(a2, (int)&v17);
  for ( j = 0; j < v17; ++j )
  {
    v3 = (const struct CCart::CFoundationCardCargo *)std::vector<CCart::CFoundationCardCargo>::operator[](j);
    CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)&v5, v3);
    operator^<int>((int)a2, &v5);
    operator^<int>((int)a2, &v6);
    operator^<int>((int)a2, &v7);
    operator^<int>((int)a2, &v8);
  }
  StoreArray<SLoadInfo>(a2, v16 + 228, 72);
  return operator^<bool>((int)a2, (int)(v16 + 321));
}


// address=[0x153a410]
// Decompiled from int __thiscall CCart::ClassID(CCart *this)
unsigned long  CCart::ClassID(void)const {
  
  return CCart::m_iClassID;
}


// address=[0x153a650]
// Decompiled from int __thiscall CCart::UnloadToPosition(CPaneContainer *this, struct CPaneContainer *a2)
void  CCart::UnloadToPosition(int) {
  
  IEntity::SetPosition(this, a2);
  (*(void (__thiscall **)(CPaneContainer *, struct CPaneContainer *))(*(_DWORD *)this + 196))(this, a2);
  CWarMap::AddEntity(this);
  IEntity::SetFlagBits(this, Selectable|Visible);
  return IEntity::ClearFlagBits(this, OnBoard);
}


// address=[0x3d8b834]
// [Decompilation failed for static unsigned long CCart::m_iClassID]

// address=[0x1533070]
// Decompiled from CCart *__thiscall CCart::CCart(CCart *this, int a2, int a3, int a4, int a5, int a6, int a7, bool a8)
 CCart::CCart(int,int,int,int,int,int,bool) {
  
  int i; // [esp+8h] [ebp-14h]

  if ( a6 == 1030 )
    CWheeler::CWheeler(this, a2, a3, a4, a5, 5, a7, a8);
  else
    CWheeler::CWheeler(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CCart::_vftable_;
  std::vector<CCart::CSettlerStatus>::vector<CCart::CSettlerStatus>();
  std::vector<CCart::CFoundationCardCargo>::vector<CCart::CFoundationCardCargo>();
  *((_BYTE *)this + 212) = 0;
  *((_BYTE *)this + 213) = 0;
  *((_BYTE *)this + 214) = 0;
  *((_BYTE *)this + 215) = 0;
  *((_BYTE *)this + 216) = 0;
  *((_BYTE *)this + 217) = 0;
  *((_BYTE *)this + 218) = 0;
  *((_BYTE *)this + 219) = 0;
  *((_DWORD *)this + 56) = 0;
  *((_BYTE *)this + 301) = 0;
  *((_DWORD *)this + 76) = -1;
  *((_BYTE *)this + 321) = 0;
  if ( !a8 )
    IEntity::SetFlagBits(this, (EntityFlag)&byte_20000CA[54]);
  *((_BYTE *)this + 217) = CCart::IsOnOwnEcoSector(this);
  for ( i = 0; i < 6; ++i )
  {
    *((_DWORD *)this + 3 * i + 57) = 0;
    *((_DWORD *)this + 3 * i + 58) = 0;
  }
  IEntity::ClearFlagBits(this, VulnerableMask);
  *((_BYTE *)this + 320) = *((_BYTE *)this + 107);
  *((_DWORD *)this + 78) = 0;
  *((_DWORD *)this + 77) = 0;
  *((_DWORD *)this + 79) = 0;
  *((_BYTE *)this + 300) = 0;
  *((_BYTE *)this + 302) = 0;
  CCart::SetSelectable(this);
  if ( a6 == 1030 )
    CCart::ChangeToFoundationCart(this);
  return this;
}


// address=[0x1533280]
// Decompiled from void __thiscall CCart::~CCart(CCart *this)
 CCart::~CCart(void) {
  
  int v1; // [esp+0h] [ebp-4h]
  int v2; // [esp+0h] [ebp-4h]
  int v3; // [esp+0h] [ebp-4h]
  CWheeler *v4; // [esp+0h] [ebp-4h]

  *(_DWORD *)this = &CCart::_vftable_;
  std::vector<CCart::CFoundationCardCargo>::clear(this);
  std::vector<CCart::CSettlerStatus>::clear(v1);
  std::vector<CCart::CFoundationCardCargo>::~vector<CCart::CFoundationCardCargo>(v2);
  std::vector<CCart::CSettlerStatus>::~vector<CCart::CSettlerStatus>(v3);
  CWheeler::~CWheeler(v4);
}


// address=[0x15332e0]
// Decompiled from int __thiscall CCart::TakeJob(CCart *this)
void  CCart::TakeJob(void) {
  
  int v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  char v5; // [esp+8h] [ebp-Ch]
  __int16 *CurrentTaskPtr; // [esp+Ch] [ebp-8h]

  CurrentTaskPtr = (__int16 *)CVehicle::GetCurrentTaskPtr(this);
  CVehicle::InitCommonTaskValues(this, (const struct CEntityTask *)CurrentTaskPtr);
  v5 = *((_BYTE *)this + 107);
  if ( v5 == 7 )
  {
    v2 = Y16X16::PackXYFast(CurrentTaskPtr[5], CurrentTaskPtr[6]);
    if ( CCart::CanWalk(this) )
    {
      *((_BYTE *)this + 107) = *(_BYTE *)(*((_DWORD *)this + 25) + 36);
      v4 = std::auto_ptr<CWalking>::operator->(v2);
      (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, v3, 0);
    }
    else
    {
      *((_BYTE *)this + 107) = 17;
    }
  }
  else if ( v5 != 17 )
  {
    CVehicle::InitCommonTaskValues(this, 0);
  }
  return (*(int (__thiscall **)(CCart *))(*(_DWORD *)this + 144))(this);
}


// address=[0x15333a0]
// Decompiled from void __thiscall CCart::SetFree(CCart *this)
void  CCart::SetFree(void) {
  
  if ( CCart::HasLoadedSomething(this) )
    CCart::DropGoods(this);
}


// address=[0x15333d0]
// Decompiled from int __thiscall CCart::DropGoods(CCart *this)
void  CCart::DropGoods(void) {
  
  int v1; // eax
  int v3; // [esp-Ch] [ebp-20h]
  unsigned int v4; // [esp+0h] [ebp-14h]
  int j; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  for ( i = 0; i < 43; ++i )
  {
    for ( j = CCart::GetGoodAmount(this, i); j; j -= v4 )
    {
      if ( j > 8 )
        v4 = 8;
      else
        v4 = j;
      v3 = IEntity::Y(this);
      v1 = IEntity::X(this);
      CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v1, v3, i, v4);
      CCart::RemoveGood(this, i, v4);
    }
  }
  CCart::UnLoadCargo(this);
  CCart::UnLoadSettler(this);
  return IEntity::ClearFlagBits(this, VulnerableMask);
}


// address=[0x1533490]
// Decompiled from void __thiscall CCart::GetTurnGfxInfo(CCart *this)
void  CCart::GetTurnGfxInfo(void) {
  
  unsigned int v1; // [esp+0h] [ebp-20h]
  unsigned int v2; // [esp+4h] [ebp-1Ch]
  unsigned int v3; // [esp+8h] [ebp-18h]
  int v4; // [esp+Ch] [ebp-14h]
  int v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+14h] [ebp-Ch]
  unsigned int v7; // [esp+18h] [ebp-8h]

  v1 = IEntity::Race(this);
  v6 = CVehicle::TurnDirEx(this);
  v5 = dword_37BEC10[5 * v6];
  if ( v5 )
    v4 = *(_DWORD *)(*((_DWORD *)this + 25) + 32) + v5 - 1;
  else
    v4 = *(_DWORD *)(*((_DWORD *)this + 25) + 28);
  v7 = v4;
  v2 = dword_37BEC14[5 * v6];
  v3 = dword_37BEC18[5 * v6];
  if ( !CCart::HasLoadedSomething(this) )
  {
    if ( v5 )
      v7 = v4 + 8;
    else
      v7 = v4 + 1;
  }
  CGfxManager::GetVehicleGfxInfo(
    (CGfxManager *)g_pGfxManager,
    (struct SGfxObjectInfo *)&IEntity::m_sGfxInfo,
    v1,
    v7,
    v2,
    v3,
    0,
    0);
  dword_40FE25C = 0;
}


// address=[0x1533560]
// Decompiled from unsigned int __cdecl CCart::operator new(unsigned int a1)
static void * __cdecl CCart::operator new(unsigned int) {
  
  return CVehicleMgr::Alloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x1533580]
// Decompiled from void __cdecl CCart::operator delete(void *a1)
static void __cdecl CCart::operator delete(void *) {
  
  CVehicleMgr::Dealloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x1533f10]
// Decompiled from unsigned __int8 *__thiscall CCart::ChangeToFoundationCart(CCart *this)
void  CCart::ChangeToFoundationCart(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // ebx
  int v5; // ebx
  char v6; // al
  int v7; // esi
  unsigned __int8 *result; // eax
  int v9; // eax
  int v10; // eax
  char v11; // [esp-10h] [ebp-114h] BYREF
  int v12; // [esp-Ch] [ebp-110h]
  int v13; // [esp-8h] [ebp-10Ch]
  int v14; // [esp-4h] [ebp-108h]
  int v15; // [esp+0h] [ebp-104h]
  _BYTE v16[20]; // [esp+Ch] [ebp-F8h] BYREF
  _BYTE v17[20]; // [esp+20h] [ebp-E4h] BYREF
  _BYTE v18[20]; // [esp+34h] [ebp-D0h] BYREF
  _BYTE v19[16]; // [esp+48h] [ebp-BCh] BYREF
  _BYTE v20[12]; // [esp+58h] [ebp-ACh] BYREF
  _BYTE v21[12]; // [esp+64h] [ebp-A0h] BYREF
  _BYTE v22[12]; // [esp+70h] [ebp-94h] BYREF
  _BYTE v23[12]; // [esp+7Ch] [ebp-88h] BYREF
  _BYTE v24[12]; // [esp+88h] [ebp-7Ch] BYREF
  _BYTE v25[12]; // [esp+94h] [ebp-70h] BYREF
  int v26; // [esp+A0h] [ebp-64h]
  int v27; // [esp+A4h] [ebp-60h]
  char *v28; // [esp+A8h] [ebp-5Ch]
  int v29; // [esp+ACh] [ebp-58h]
  int v30; // [esp+B0h] [ebp-54h]
  char *v31; // [esp+B4h] [ebp-50h]
  int v32; // [esp+B8h] [ebp-4Ch]
  int v33; // [esp+BCh] [ebp-48h]
  char *v34; // [esp+C0h] [ebp-44h]
  int v35; // [esp+C4h] [ebp-40h]
  int v36; // [esp+C8h] [ebp-3Ch]
  int v37; // [esp+CCh] [ebp-38h]
  struct std::_Iterator_base12 *v38; // [esp+D0h] [ebp-34h]
  struct std::_Iterator_base12 *v39; // [esp+D4h] [ebp-30h]
  struct std::_Iterator_base12 *v40; // [esp+D8h] [ebp-2Ch]
  struct std::_Iterator_base12 *v41; // [esp+DCh] [ebp-28h]
  struct std::_Iterator_base12 *v42; // [esp+E0h] [ebp-24h]
  struct std::_Iterator_base12 *v43; // [esp+E4h] [ebp-20h]
  int v44; // [esp+E8h] [ebp-1Ch]
  unsigned __int8 *i; // [esp+ECh] [ebp-18h]
  IAnimatedEntity *v46; // [esp+F0h] [ebp-14h]
  _DWORD *v47; // [esp+F4h] [ebp-10h]
  int v48; // [esp+100h] [ebp-4h]

  v47 = this;
  *((_BYTE *)this + 214) = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfPioneers);
  *((_BYTE *)v47 + 215) = CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfCarrier);
  *((_BYTE *)v47 + 216) = 1;
  std::vector<CCart::CSettlerStatus>::clear(v15);
  std::vector<CCart::CFoundationCardCargo>::clear(v15);
  v14 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfBoard);
  v13 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfBoard);
  v1 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfBoard);
  v14 = CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)v18, 7, v1, v13, v14);
  v43 = (struct std::_Iterator_base12 *)std::vector<CCart::CFoundationCardCargo>::end(v24);
  v42 = v43;
  v48 = 0;
  v34 = &v11;
  v33 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v43);
  v32 = std::vector<CCart::CFoundationCardCargo>::insert(v25, v11, v12, v13, v14);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v25);
  v48 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v24);
  v14 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfStone);
  v13 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfStone);
  v2 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfStone);
  v14 = CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)v17, 32, v2, v13, v14);
  v41 = (struct std::_Iterator_base12 *)std::vector<CCart::CFoundationCardCargo>::end(v22);
  v40 = v41;
  v48 = 1;
  v31 = &v11;
  v30 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v41);
  v29 = std::vector<CCart::CFoundationCardCargo>::insert(v23, v11, v12, v13, v14);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v23);
  v48 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v22);
  v14 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfHammer);
  v13 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfHammer);
  v3 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfHammer);
  v14 = CCart::CFoundationCardCargo::CFoundationCardCargo((CCart::CFoundationCardCargo *)v16, 18, v3, v13, v14);
  v39 = (struct std::_Iterator_base12 *)std::vector<CCart::CFoundationCardCargo>::end(v20);
  v38 = v39;
  v48 = 2;
  v28 = &v11;
  v27 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v39);
  v26 = std::vector<CCart::CFoundationCardCargo>::insert(v21, v11, v12, v13, v14);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v21);
  v48 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CFoundationCardCargo>>>(v20);
  v4 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfBoard);
  v5 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfStone) + v4;
  v6 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfHammer);
  *((_BYTE *)v47 + 219) = v6 + v5;
  *((_BYTE *)v47 + 218) = *((_BYTE *)v47 + 219);
  IEntity::SetFlagBits(v47, VulnerableMask);
  IAnimatedEntity::RegisterForLogicUpdate(1);
  *((_BYTE *)v47 + 107) = 27;
  *((_BYTE *)v47 + 214) = 0;
  *((_BYTE *)v47 + 215) = 0;
  *((_BYTE *)v47 + 212) = 0;
  *((_BYTE *)v47 + 213) = 0;
  v7 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfPioneers);
  v37 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfCarrier) + v7;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int)i >= v37 )
      break;
    v14 = 0;
    v13 = 47;
    v9 = IEntity::OwnerId((unsigned __int8 *)v47);
    v44 = CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, 1, 1, v9, v13, v14);
    result = CSettlerMgr::GetSettlerPtr(v44);
    v46 = (IAnimatedEntity *)result;
    if ( !result )
      break;
    CSettler::TakeWaitList(v46);
    (*(void (__thiscall **)(IAnimatedEntity *))(*(_DWORD *)v46 + 56))(v46);
    IAnimatedEntity::UnRegisterFromLogicUpdate(v46);
    IEntity::ClearFlagBits(v46, Selectable|Visible);
    v14 = 1;
    v10 = IEntity::Type((unsigned __int16 *)v46);
    v36 = CCart::CSettlerStatus::CSettlerStatus(v19, v44, v10, v14);
    v35 = v36;
    v48 = 3;
    std::vector<CCart::CSettlerStatus>::push_back(v36);
    v48 = -1;
    CCart::CSettlerStatus::~CSettlerStatus((CCart::CSettlerStatus *)v19);
    ++*((_BYTE *)v47 + 212);
  }
  return result;
}


// address=[0x15342f0]
// Decompiled from char __thiscall CCart::OnRequestSettlers(CCart *this)
bool  CCart::OnRequestSettlers(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // eax
  int v5; // eax
  char v6; // [esp-10h] [ebp-E4h] BYREF
  int v7; // [esp-Ch] [ebp-E0h]
  int v8; // [esp-8h] [ebp-DCh]
  int v9; // [esp-4h] [ebp-D8h]
  _BYTE v10[24]; // [esp+4h] [ebp-D0h] BYREF
  _BYTE v11[16]; // [esp+1Ch] [ebp-B8h] BYREF
  _BYTE v12[16]; // [esp+2Ch] [ebp-A8h] BYREF
  _BYTE v13[12]; // [esp+3Ch] [ebp-98h] BYREF
  _BYTE v14[12]; // [esp+48h] [ebp-8Ch] BYREF
  _BYTE v15[12]; // [esp+54h] [ebp-80h] BYREF
  _BYTE v16[12]; // [esp+60h] [ebp-74h] BYREF
  int v17; // [esp+6Ch] [ebp-68h]
  int v18; // [esp+70h] [ebp-64h]
  char *v19; // [esp+74h] [ebp-60h]
  int v20; // [esp+78h] [ebp-5Ch]
  int v21; // [esp+7Ch] [ebp-58h]
  char *v22; // [esp+80h] [ebp-54h]
  struct std::_Iterator_base12 *v23; // [esp+84h] [ebp-50h]
  struct std::_Iterator_base12 *v24; // [esp+88h] [ebp-4Ch]
  int v25; // [esp+8Ch] [ebp-48h]
  int v26; // [esp+90h] [ebp-44h]
  CEntityEvent *v27; // [esp+94h] [ebp-40h]
  CEntityEvent *v28; // [esp+98h] [ebp-3Ch]
  struct std::_Iterator_base12 *v29; // [esp+9Ch] [ebp-38h]
  struct std::_Iterator_base12 *v30; // [esp+A0h] [ebp-34h]
  int v31; // [esp+A4h] [ebp-30h]
  int v32; // [esp+A8h] [ebp-2Ch]
  int v33; // [esp+ACh] [ebp-28h]
  int v34; // [esp+B0h] [ebp-24h]
  int NearestSettler; // [esp+B4h] [ebp-20h]
  CEcoSector *EcoSectorPtr; // [esp+B8h] [ebp-1Ch]
  unsigned __int8 *SettlerPtr; // [esp+BCh] [ebp-18h]
  int i; // [esp+C0h] [ebp-14h]
  _BYTE *v39; // [esp+C4h] [ebp-10h]
  int v40; // [esp+D0h] [ebp-4h]

  v39 = this;
  for ( i = 0; i < (unsigned __int8)v39[214]; ++i )
  {
    v9 = 47;
    v1 = IEntity::ID();
    v34 = CSettlerMgr::OrderSpecialist((CSettlerMgr *)g_cSettlerMgr, v1, v9);
    if ( v34 > 0 )
    {
      --v39[214];
      v32 = CCart::CSettlerStatus::CSettlerStatus(v12, v34, 47, 0);
      v31 = v32;
      v40 = 0;
      v9 = v32;
      v30 = (struct std::_Iterator_base12 *)std::vector<CCart::CSettlerStatus>::end(v15);
      v29 = v30;
      LOBYTE(v40) = 1;
      v22 = &v6;
      v21 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v30);
      v20 = std::vector<CCart::CSettlerStatus>::insert(v16, v6, v7, v8, v9);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v16);
      LOBYTE(v40) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v15);
      v40 = -1;
      CCart::CSettlerStatus::~CSettlerStatus((CCart::CSettlerStatus *)v12);
    }
  }
  for ( i = 0; i < (unsigned __int8)v39[215]; ++i )
  {
    v2 = IEntity::WorldIdx();
    v33 = CWorldManager::EcoSectorId(v2);
    if ( !v33 )
      return 0;
    EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v33);
    if ( !EcoSectorPtr && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1578, "pEcoSector!= NULL") == 1 )
      __debugbreak();
    if ( !EcoSectorPtr )
      return 0;
    v9 = IEntity::Y(v39);
    v4 = IEntity::X(v39);
    NearestSettler = CEcoSector::GetNearestSettler(EcoSectorPtr, 1, v4, v9);
    if ( NearestSettler > 0 )
    {
      CEcoSector::GetSettlerOutOfOffer(EcoSectorPtr, NearestSettler);
      SettlerPtr = CSettlerMgr::GetSettlerPtr(NearestSettler);
      if ( !SettlerPtr && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1591, "pSettler!=NULL") == 1 )
        __debugbreak();
      if ( !SettlerPtr )
        return 0;
      v9 = 0;
      v8 = 0;
      v5 = IEntity::ID();
      v28 = CEntityEvent::CEntityEvent((CEntityEvent *)v10, 0x18u, 0, v5, v8, v9);
      v27 = v28;
      v40 = 2;
      (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v28);
      v40 = -1;
      CEntityEvent::~CEntityEvent(v10);
      IEntity::ClearFlagBits(SettlerPtr, Selectable|Selected);
      --v39[215];
      v26 = CCart::CSettlerStatus::CSettlerStatus(v11, NearestSettler, 1, 0);
      v25 = v26;
      v40 = 3;
      v9 = v26;
      v24 = (struct std::_Iterator_base12 *)std::vector<CCart::CSettlerStatus>::end(v13);
      v23 = v24;
      LOBYTE(v40) = 4;
      v19 = &v6;
      v18 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v24);
      v17 = std::vector<CCart::CSettlerStatus>::insert(v14, v6, v7, v8, v9);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v14);
      LOBYTE(v40) = 3;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CCart::CSettlerStatus>>>(v13);
      v40 = -1;
      CCart::CSettlerStatus::~CSettlerStatus((CCart::CSettlerStatus *)v11);
    }
  }
  return 1;
}


// address=[0x1534640]
// Decompiled from char __thiscall CCart::OnRequestCargo(CCart *this)
bool  CCart::OnRequestCargo(void) {
  
  int v1; // eax
  CEcoSector *v3; // eax
  int v4; // [esp-8h] [ebp-20h]
  int v5; // [esp-4h] [ebp-1Ch]
  int v6; // [esp+4h] [ebp-14h]
  int j; // [esp+8h] [ebp-10h]
  unsigned int i; // [esp+10h] [ebp-8h]
  _DWORD *v10; // [esp+14h] [ebp-4h]

  v1 = IEntity::WorldIdx();
  v6 = CWorldManager::EcoSectorId(v1);
  if ( !v6 )
    return 0;
  for ( i = 0; i < std::vector<CCart::CFoundationCardCargo>::size((char *)this + 196); ++i )
  {
    v10 = (_DWORD *)std::vector<CCart::CFoundationCardCargo>::operator[](i);
    if ( *v10 > v10[3] )
    {
      for ( j = 0; j < *v10 - v10[3]; ++j )
      {
        v5 = v10[1];
        v4 = IEntity::ID();
        v3 = (CEcoSector *)CEcoSectorMgr::operator[](v6);
        CEcoSector::RequestGoodToVehicle(v3, v4, v5);
        v10[4] = CStateGame::GetTickCounter(g_pGame);
      }
    }
  }
  return 1;
}


// address=[0x1534720]
// Decompiled from char __thiscall CCart::OnUnload(CCart *this)
bool  CCart::OnUnload(void) {
  
  CCart::UnLoadSettler(this);
  CCart::UnLoadCargo(this);
  return 1;
}


// address=[0x1534740]
// Decompiled from char __thiscall CCart::UnLoadSettler(CCart *this)
bool  CCart::UnLoadSettler(void) {
  
  unsigned int v1; // eax
  int v2; // esi
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // [esp+0h] [ebp-A0h]
  _BYTE v10[24]; // [esp+8h] [ebp-98h] BYREF
  _BYTE v11[24]; // [esp+20h] [ebp-80h] BYREF
  _BYTE v12[24]; // [esp+38h] [ebp-68h] BYREF
  CEntityEvent *v13; // [esp+50h] [ebp-50h]
  CEntityEvent *v14; // [esp+54h] [ebp-4Ch]
  CEntityEvent *v15; // [esp+58h] [ebp-48h]
  CEntityEvent *v16; // [esp+5Ch] [ebp-44h]
  CEntityEvent *v17; // [esp+60h] [ebp-40h]
  CEntityEvent *v18; // [esp+64h] [ebp-3Ch]
  int v19; // [esp+68h] [ebp-38h]
  int v20; // [esp+6Ch] [ebp-34h]
  int v21; // [esp+70h] [ebp-30h]
  int v22; // [esp+74h] [ebp-2Ch]
  int v23; // [esp+78h] [ebp-28h]
  int v24; // [esp+7Ch] [ebp-24h]
  int v25; // [esp+80h] [ebp-20h]
  unsigned __int16 *EcoSectorPtr; // [esp+84h] [ebp-1Ch]
  unsigned int i; // [esp+88h] [ebp-18h]
  char *v28; // [esp+8Ch] [ebp-14h]
  unsigned __int16 *v29; // [esp+90h] [ebp-10h]
  int v30; // [esp+9Ch] [ebp-4h]

  v28 = (char *)this;
  for ( i = 0; ; ++i )
  {
    v1 = std::vector<CCart::CSettlerStatus>::size(v28 + 180);
    if ( i >= v1 )
      break;
    v25 = std::vector<CCart::CSettlerStatus>::operator[](i);
    v21 = *(_DWORD *)(v25 + 8);
    v29 = (unsigned __int16 *)CSettlerMgr::operator[](v21);
    if ( *(_BYTE *)(v25 + 4) )
    {
      v24 = (v28[68] + 3) % 6 + 8;
      v2 = IEntity::X(v28);
      v19 = CSpiralOffsets::DeltaX(v24) + v2;
      v3 = IEntity::Y(v28);
      v20 = CSpiralOffsets::DeltaY(v24) + v3;
      v23 = Y16X16::PackXYFast(v19, v20);
      v18 = CEntityEvent::CEntityEvent((CEntityEvent *)v12, 0x19u, 0, 0, v23, 0);
      v17 = v18;
      v30 = 0;
      (*(void (__thiscall **)(unsigned __int16 *, CEntityEvent *))(*(_DWORD *)v29 + 80))(v29, v18);
      v30 = -1;
      CEntityEvent::~CEntityEvent(v12);
      v16 = CEntityEvent::CEntityEvent((CEntityEvent *)v11, 0x11u, 13, 0, v23, 0);
      v15 = v16;
      v30 = 1;
      (*(void (__thiscall **)(unsigned __int16 *, CEntityEvent *))(*(_DWORD *)v29 + 80))(v29, v16);
      v30 = -1;
      CEntityEvent::~CEntityEvent(v11);
    }
    else
    {
      v4 = IEntity::ID();
      v14 = CEntityEvent::CEntityEvent((CEntityEvent *)v10, 9u, 0, v4, 0, 0);
      v13 = v14;
      v30 = 2;
      (*(void (__thiscall **)(unsigned __int16 *, CEntityEvent *))(*(_DWORD *)v29 + 80))(v29, v14);
      v30 = -1;
      CEntityEvent::~CEntityEvent(v10);
      if ( IEntity::Type(v29) == 1 )
      {
        v5 = IEntity::WorldIdx();
        v22 = CWorldManager::EcoSectorId(v5);
        if ( v22 <= 0 )
        {
          v7 = IEntity::ID();
          CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, v7);
        }
        else
        {
          EcoSectorPtr = (unsigned __int16 *)CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v22);
          if ( !EcoSectorPtr && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1805, "pSector != NULL") == 1 )
            __debugbreak();
          if ( EcoSectorPtr )
          {
            v6 = IEntity::ID();
            CEcoSector::SetSettlerOffer(EcoSectorPtr, 1, v6);
          }
        }
      }
    }
  }
  std::vector<CCart::CSettlerStatus>::clear(v9);
  return 1;
}


// address=[0x15349d0]
// Decompiled from char __thiscall CCart::UnLoadCargo(CCart *this)
bool  CCart::UnLoadCargo(void) {
  
  int v1; // eax
  int v3; // [esp-Ch] [ebp-24h]
  unsigned int v4; // [esp-8h] [ebp-20h]
  unsigned int v5; // [esp+0h] [ebp-18h]
  unsigned int v6; // [esp+4h] [ebp-14h]
  unsigned int i; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  _DWORD *v10; // [esp+14h] [ebp-4h]

  for ( i = 0; i < std::vector<CCart::CFoundationCardCargo>::size((char *)this + 196); ++i )
  {
    v10 = (_DWORD *)std::vector<CCart::CFoundationCardCargo>::operator[](i);
    if ( v10[2] && *v10 )
    {
      for ( j = 0; j < *v10; j += v6 )
      {
        if ( *v10 - j <= 8 )
          v6 = *v10 - j;
        else
          v6 = 8;
        v5 = v6;
        v4 = v10[1];
        v3 = IEntity::Y(this);
        v1 = IEntity::X(this);
        CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v1, v3, v4, v6);
      }
      *v10 = 0;
    }
  }
  std::vector<CCart::CFoundationCardCargo>::clear(v5);
  IEntity::ClearFlagBits(this, VulnerableMask);
  return 1;
}


// address=[0x1534ad0]
// Decompiled from bool __thiscall CCart::CanTakeLand(CCart *this)
bool  CCart::CanTakeLand(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v5; // [esp-Ch] [ebp-3Ch]
  int v6; // [esp-4h] [ebp-34h]
  _BYTE v7[20]; // [esp+0h] [ebp-30h] BYREF
  int v8; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+1Ch] [ebp-14h]
  int v10; // [esp+20h] [ebp-10h]
  int v11; // [esp+24h] [ebp-Ch] BYREF
  int v12; // [esp+28h] [ebp-8h] BYREF
  _DWORD *v13; // [esp+2Ch] [ebp-4h]

  v13 = this;
  v6 = IEntity::Y(this);
  v1 = IEntity::X(v13);
  v8 = CWorldManager::SectorId(v1, v6);
  v5 = IEntity::Y(v13);
  v2 = IEntity::X(v13);
  CSectorSpiralWalk::CSectorSpiralWalk((CSectorSpiralWalk *)v7, v2, v5, 3, v8);
  v11 = IEntity::X(v13);
  v12 = IEntity::Y(v13);
  v10 = 0;
  while ( CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v7, &v11, &v12) )
  {
    v9 = CWorldManager::OwnerId(v11, v12);
    v3 = IEntity::OwnerId((unsigned __int8 *)v13);
    if ( (v9 == v3 || v9 <= 0) && CWorldManager::IsPositionFreeForSettler(v11, v12) )
      ++v10;
  }
  return v10 >= 28;
}


// address=[0x1534bb0]
// Decompiled from BOOL __thiscall CCart::TakeLand(CCart *this)
void  CCart::TakeLand(void) {
  
  int v1; // eax
  int v2; // eax
  BOOL result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-Ch] [ebp-38h]
  int v7; // [esp-4h] [ebp-30h]
  _BYTE v8[20]; // [esp+0h] [ebp-2Ch] BYREF
  int v9; // [esp+14h] [ebp-18h]
  int v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+20h] [ebp-Ch] BYREF
  int v13; // [esp+24h] [ebp-8h] BYREF
  _DWORD *v14; // [esp+28h] [ebp-4h]

  v14 = this;
  v7 = IEntity::Y(this);
  v1 = IEntity::X(v14);
  v10 = CWorldManager::SectorId(v1, v7);
  v6 = IEntity::Y(v14);
  v2 = IEntity::X(v14);
  CSectorSpiralWalk::CSectorSpiralWalk((CSectorSpiralWalk *)v8, v2, v6, 3, v10);
  v12 = IEntity::X(v14);
  v13 = IEntity::Y(v14);
  v9 = 0;
  while ( 1 )
  {
    result = CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v8, &v12, &v13);
    if ( !result )
      break;
    v11 = CWorldManager::OwnerId(v12, v13);
    v4 = IEntity::OwnerId((unsigned __int8 *)v14);
    if ( v11 == v4 || v11 <= 0 )
    {
      v5 = IEntity::OwnerId((unsigned __int8 *)v14);
      CWorldManager::SetOwnerId(v12, v13, v5);
    }
  }
  return result;
}


// address=[0x1534c70]
// Decompiled from char __thiscall CCart::OnDestroyFoundationCart(CCart *this)
bool  CCart::OnDestroyFoundationCart(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // [esp-20h] [ebp-24h]
  int v5; // [esp-18h] [ebp-1Ch]

  v5 = CStaticConfigVarInt::operator int(&CCart::m_iAmountOfRecycledBoard);
  v4 = IEntity::Y(this);
  v1 = IEntity::X(this);
  CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v1, v4, 7, v5, 3, 0, 0, 0, 0);
  IEntity::ClearFlagBits(this, Visible);
  v2 = IEntity::ID();
  CVehicleMgr::DeleteVehicle((CVehicleMgr *)&g_cVehicleMgr, v2);
  return 1;
}


// address=[0x1534cd0]
// Decompiled from bool __thiscall CCart::HasEnoughGoodToCreateFoundationCart(CCart *this)
bool  CCart::HasEnoughGoodToCreateFoundationCart(void) {
  
  int v1; // eax
  bool result; // al
  CEcoSector *v3; // eax
  int v4; // esi
  CEcoSector *v5; // eax
  int v6; // esi
  CEcoSector *v7; // eax
  int v8; // esi
  int v9; // [esp+8h] [ebp-4h]

  v1 = IEntity::WorldIdx();
  v9 = CWorldManager::EcoSectorId(v1);
  if ( !v9 )
    return 0;
  v3 = (CEcoSector *)CEcoSectorMgr::operator[](v9);
  v4 = CEcoSector::NrOfGoods(v3, 7);
  result = 0;
  if ( v4 < CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfBoard) )
    return result;
  v5 = (CEcoSector *)CEcoSectorMgr::operator[](v9);
  v6 = CEcoSector::NrOfGoods(v5, 32);
  if ( v6 < CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfStone) )
    return result;
  v7 = (CEcoSector *)CEcoSectorMgr::operator[](v9);
  v8 = CEcoSector::NrOfGoods(v7, 18);
  if ( v8 >= CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfHammer) )
    return 1;
  return result;
}


// address=[0x1534d80]
// Decompiled from bool __thiscall CCart::WeAreWaitFor(CCart *this, int a2)
bool  CCart::WeAreWaitFor(int) {
  
  unsigned int i; // [esp+Ch] [ebp-4h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Cart.cpp", 1749, "_iPioneerId>0") == 1 )
    __debugbreak();
  for ( i = 0; ; ++i )
  {
    if ( i >= std::vector<CCart::CSettlerStatus>::size((char *)this + 180) )
      return 0;
    if ( *(_DWORD *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 8) == a2 )
      break;
  }
  return *(_DWORD *)std::vector<CCart::CSettlerStatus>::operator[](i)
      && !*(_BYTE *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 4);
}


// address=[0x1534e50]
// Decompiled from char __thiscall CCart::IsPioner(CCart *this, int a2)
bool  CCart::IsPioner(int) {
  
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < std::vector<CCart::CSettlerStatus>::size((char *)this + 180); ++i )
  {
    if ( *(_DWORD *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 8) == a2
      && *(_DWORD *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 12) == 47 )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x1534ec0]
// Decompiled from char __thiscall CCart::IsCarrier(CCart *this, int a2)
bool  CCart::IsCarrier(int) {
  
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < std::vector<CCart::CSettlerStatus>::size((char *)this + 180); ++i )
  {
    if ( *(_DWORD *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 8) == a2
      && *(_DWORD *)(std::vector<CCart::CSettlerStatus>::operator[](i) + 12) == 1 )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x1534f30]
// Decompiled from bool __thiscall CCart::CanWalk(CCart *this)
bool  CCart::CanWalk(void) {
  
  int v1; // esi
  bool v3; // [esp+4h] [ebp-Ch]

  v3 = 1;
  if ( !*((_BYTE *)this + 216) )
    return v3;
  v1 = *((unsigned __int8 *)this + 212);
  if ( v1 < CStaticConfigVarInt::GetIntValue((CStaticConfigVarInt *)&CCart::m_iAmountOfPioneers)
    || *((unsigned __int8 *)this + 218) < (int)*((unsigned __int8 *)this + 219) )
  {
    return 0;
  }
  return v3;
}


// address=[0x1534fa0]
// Decompiled from int __thiscall CCart::KillAllLoadedSettlers(CCart *this)
void  CCart::KillAllLoadedSettlers(void) {
  
  int v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < std::vector<CCart::CSettlerStatus>::size((char *)this + 180); ++i )
  {
    v4 = std::vector<CCart::CSettlerStatus>::operator[](i);
    v3 = *(_DWORD *)(v4 + 8);
    v2 = CSettlerMgr::operator[](v3);
    if ( *(_BYTE *)(v4 + 4) )
      CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, v3);
  }
  return std::vector<CCart::CSettlerStatus>::clear(v2);
}


// address=[0x153a4b0]
// Decompiled from bool __thiscall CCart::IsOnOwnEcoSector(CCart *this)
bool  CCart::IsOnOwnEcoSector(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // esi
  char v5; // [esp+4h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-4h]

  v1 = IEntity::WorldIdx();
  v7 = CWorldManager::EcoSectorId(v1);
  v5 = 0;
  if ( !v7 )
    return v5;
  v2 = CEcoSectorMgr::operator[](v7);
  v3 = CEcoSector::Owner(v2);
  if ( v3 == IEntity::OwnerId((unsigned __int8 *)this) )
    return 1;
  return v5;
}


// address=[0x40f22c8]
// [Decompilation failed for static class CStaticConfigVarInt CCart::m_iAmountOfPioneers]

// address=[0x40f22d4]
// [Decompilation failed for static class CStaticConfigVarInt CCart::m_iAmountOfCarrier]

// address=[0x40f22e0]
// [Decompilation failed for static class CStaticConfigVarInt CCart::m_iAmountOfBoard]

// address=[0x40f22ec]
// [Decompilation failed for static class CStaticConfigVarInt CCart::m_iAmountOfStone]

// address=[0x40f22f8]
// [Decompilation failed for static class CStaticConfigVarInt CCart::m_iAmountOfHammer]

// address=[0x40f2304]
// [Decompilation failed for static class CStaticConfigVarInt CCart::m_iAmountOfRecycledBoard]

