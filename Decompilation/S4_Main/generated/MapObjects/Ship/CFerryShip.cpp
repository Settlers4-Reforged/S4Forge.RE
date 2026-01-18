#include "CFerryShip.h"

// Definitions for class CFerryShip

// address=[0x14009a0]
// Decompiled from int __cdecl CFerryShip::New(int a1)
class CPersistence * __cdecl CFerryShip::New(std::istream & a1) {
  
  if ( CFerryShip::operator new(0xD8u) )
    return CFerryShip::CFerryShip(a1);
  else
    return 0;
}


// address=[0x1596310]
// Decompiled from int __thiscall CFerryShip::Delete(CFerryShip *this)
void  CFerryShip::Delete(void) {
  
  unsigned int v1; // eax
  const struct CFerryShip::CCargo *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  _BYTE v7[24]; // [esp+4h] [ebp-54h] BYREF
  _DWORD v8[3]; // [esp+1Ch] [ebp-3Ch] BYREF
  int v9; // [esp+28h] [ebp-30h]
  char v10; // [esp+31h] [ebp-27h]
  CEntityEvent *v11; // [esp+34h] [ebp-24h]
  CEntityEvent *v12; // [esp+38h] [ebp-20h]
  int v13; // [esp+3Ch] [ebp-1Ch]
  void **v14; // [esp+40h] [ebp-18h]
  unsigned int i; // [esp+44h] [ebp-14h]
  CVehicle *v16; // [esp+48h] [ebp-10h]
  int v17; // [esp+54h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v1 = std::vector<CFerryShip::CCargo>::size((char *)v16 + 180);
    if ( i >= v1 )
      break;
    v2 = (const struct CFerryShip::CCargo *)std::vector<CFerryShip::CCargo>::operator[](i);
    CFerryShip::CCargo::CCargo((CFerryShip::CCargo *)v8, v2);
    if ( v8[2] > 0 )
    {
      if ( v8[0] == 1 )
      {
        if ( v10 )
        {
          CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, v9);
        }
        else
        {
          v3 = std::vector<CFerryShip::CCargo>::operator[](i);
          v14 = (void **)CMapObjectMgr::EntityPtr(*(_DWORD *)(v3 + 12));
          if ( !v14 && BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 333, "pEntity!=NULL") == 1 )
            __debugbreak();
          if ( v14 )
          {
            if ( !j____RTDynamicCast(v14, 0, &IEntity__RTTI_Type_Descriptor_, &IMovingEntity__RTTI_Type_Descriptor_, 0)
              && BBSupportDbgReport(
                   2,
                   "MapObjects\\Ship\\FerryShip.cpp",
                   336,
                   "dynamic_cast<IMovingEntity*>(pEntity)!=NULL") == 1 )
            {
              __debugbreak();
            }
            v13 = j____RTDynamicCast(v14, 0, &IEntity__RTTI_Type_Descriptor_, &IMovingEntity__RTTI_Type_Descriptor_, 0);
            if ( v13 )
            {
              v4 = IEntity::ID();
              v12 = CEntityEvent::CEntityEvent((CEntityEvent *)v7, 7u, 0, v4, 0, 0);
              v11 = v12;
              v17 = 0;
              (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v13 + 80))(v13, v12);
              v17 = -1;
              CEntityEvent::~CEntityEvent(v7);
              v5 = IEntity::ID();
              (*(void (__thiscall **)(CVehicle *, int))(*(_DWORD *)v16 + 64))(v16, v5);
            }
          }
        }
      }
      else
      {
        CVehicleMgr::DeleteVehicle((CVehicleMgr *)&g_cVehicleMgr, v9);
      }
    }
  }
  std::vector<CFerryShip::CCargo>::clear();
  return CVehicle::Delete(v16);
}


// address=[0x1596500]
// Decompiled from int __thiscall CFerryShip::GetMeetingPointXY(CFerryShip *this, int a2, unsigned int a3)
int const  CFerryShip::GetMeetingPointXY(enum OBJ_TYPE a2, int a3) {
  
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v7; // [esp-4h] [ebp-20h]
  int v8; // [esp+4h] [ebp-18h]
  int v9; // [esp+8h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+10h] [ebp-Ch] BYREF
  _DWORD *v12; // [esp+14h] [ebp-8h]
  CFerryShip *v13; // [esp+18h] [ebp-4h]

  v13 = this;
  if ( !CMapObjectMgr::ValidEntityId(a3)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 1021, "g_pMapObjectMgr->ValidEntityId(_iEntityId)") == 1 )
  {
    __debugbreak();
  }
  v9 = CFerryShip::CalcDistanceToLand(v13, &v10, &v11);
  if ( v9 <= *((_DWORD *)v13 + 43)
    && (v12 = (_DWORD *)CMapObjectMgr::EntityPtr(a3)) != 0
    && (v3 = IEntity::Y(v12),
        v7 = v3 - IEntity::Y(v13),
        v4 = IEntity::X(v12),
        v5 = IEntity::X(v13),
        v8 = Grid::Distance((Grid *)(v4 - v5), v7),
        v8 < *((_DWORD *)v13 + 44))
    && CFerryShip::FindLoadPosition(v13, a3, &v10, &v11) )
  {
    return Y16X16::PackXYFast(v10, v11);
  }
  else
  {
    return 0;
  }
}


// address=[0x15965f0]
// Decompiled from int __thiscall CFerryShip::Request(CPropertySheet *this, int a2)
enum CFerryShip::TFerryRequestResult  CFerryShip::Request(int a2) {
  
  void **VehiclePtr; // eax
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int CargoSize; // eax
  char v19; // [esp-10h] [ebp-E0h] BYREF
  int v20; // [esp-Ch] [ebp-DCh]
  int v21; // [esp-8h] [ebp-D8h]
  int v22; // [esp-4h] [ebp-D4h]
  _BYTE v23[24]; // [esp+8h] [ebp-C8h] BYREF
  _BYTE v24[24]; // [esp+20h] [ebp-B0h] BYREF
  _BYTE v25[24]; // [esp+38h] [ebp-98h] BYREF
  _BYTE v26[12]; // [esp+50h] [ebp-80h] BYREF
  _BYTE v27[12]; // [esp+5Ch] [ebp-74h] BYREF
  int v28; // [esp+68h] [ebp-68h]
  int v29; // [esp+6Ch] [ebp-64h]
  char *v30; // [esp+70h] [ebp-60h]
  struct std::_Iterator_base12 *v31; // [esp+74h] [ebp-5Ch]
  struct std::_Iterator_base12 *v32; // [esp+78h] [ebp-58h]
  CEntityEvent *v33; // [esp+7Ch] [ebp-54h]
  CEntityEvent *v34; // [esp+80h] [ebp-50h]
  int v35; // [esp+84h] [ebp-4Ch]
  CEntityEvent *v36; // [esp+88h] [ebp-48h]
  CEntityEvent *v37; // [esp+8Ch] [ebp-44h]
  int v38; // [esp+90h] [ebp-40h]
  int v39; // [esp+94h] [ebp-3Ch]
  int v40; // [esp+98h] [ebp-38h]
  int v41; // [esp+9Ch] [ebp-34h]
  unsigned __int8 *v42; // [esp+A0h] [ebp-30h]
  int v43; // [esp+A4h] [ebp-2Ch]
  unsigned __int8 *SettlerPtr; // [esp+A8h] [ebp-28h]
  int v45; // [esp+ACh] [ebp-24h]
  int v46; // [esp+B0h] [ebp-20h]
  int i; // [esp+B4h] [ebp-1Ch]
  char v48; // [esp+BBh] [ebp-15h]
  CPropertySheet *v49; // [esp+BCh] [ebp-14h]
  unsigned __int16 *v50; // [esp+C0h] [ebp-10h]
  int v51; // [esp+CCh] [ebp-4h]

  v49 = this;
  if ( !IEntity::FlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return 2;
  v50 = 0;
  VehiclePtr = (void **)CVehicleMgr::GetVehiclePtr(a2);
  v42 = (unsigned __int8 *)j____RTDynamicCast(
                             VehiclePtr,
                             0,
                             &CVehicle__RTTI_Type_Descriptor_,
                             &CWheeler__RTTI_Type_Descriptor_,
                             0);
  SettlerPtr = CSettlerMgr::GetSettlerPtr(a2);
  if ( !SettlerPtr && !v42 )
    return 2;
  if ( SettlerPtr )
    v50 = (unsigned __int16 *)SettlerPtr;
  else
    v50 = (unsigned __int16 *)v42;
  if ( !v50 )
    return 1;
  v22 = IEntity::Type(v50);
  v4 = IEntity::ObjType((unsigned __int8 *)v50);
  if ( !CFerryShip::CanLoad(v49, v4, v22) )
    return 3;
  v5 = IEntity::OwnerId((unsigned __int8 *)v49);
  if ( v5 != IEntity::OwnerId((unsigned __int8 *)v50) )
    return 4;
  if ( (*(int (__thiscall **)(unsigned __int16 *, _DWORD))(*(_DWORD *)v50 + 72))(v50, 0) )
    return 4;
  v6 = IEntity::ID();
  if ( CFerryShip::HasRegisterdCargo(v49, v6) )
    return 4;
  v7 = IEntity::ObjType((unsigned __int8 *)v50);
  v43 = (*(int (__thiscall **)(CPropertySheet *, int, int))(*(_DWORD *)v49 + 140))(v49, v7, a2);
  if ( !v43 )
    return 2;
  v41 = Y16X16::UnpackXFast(v43);
  v40 = Y16X16::UnpackYFast(v43);
  v8 = IEntity::ID();
  v37 = CEntityEvent::CEntityEvent((CEntityEvent *)v25, 0x18u, 0, v8, v41, v40);
  v36 = v37;
  v51 = 0;
  (*(void (__thiscall **)(unsigned __int16 *, CEntityEvent *))(*(_DWORD *)v50 + 80))(v50, v37);
  v51 = -1;
  CEntityEvent::~CEntityEvent(v25);
  v46 = v41;
  v45 = v40;
  v35 = CSpiralOffsets::Last(10);
  v48 = 0;
  for ( i = 0; i <= v35 && !v48; ++i )
  {
    v9 = CSpiralOffsets::DeltaX(i);
    v38 = v46 + v9;
    v10 = CSpiralOffsets::DeltaY(i);
    v39 = v45 + v10;
    if ( (unsigned __int8)CWorldManager::InWorld(v38, v45 + v10) )
    {
      if ( CWorldManager::IsWater(v38, v39) )
      {
        v11 = CSpiralOffsets::DeltaX(i);
        v46 += v11;
        v12 = CSpiralOffsets::DeltaY(i);
        v45 += v12;
        v48 = 1;
      }
    }
  }
  v13 = Y16X16::PackXYFast(v46, v45);
  v34 = CEntityEvent::CEntityEvent((CEntityEvent *)v24, 0x11u, 13, 0, v13, 0);
  v33 = v34;
  v51 = 1;
  (*(void (__thiscall **)(CPropertySheet *, CEntityEvent *))(*(_DWORD *)v49 + 80))(v49, v34);
  v51 = -1;
  CEntityEvent::~CEntityEvent(v24);
  v14 = IEntity::X(v49);
  if ( v14 == v46 && (v15 = IEntity::Y(v49), v15 == v45) )
    CFerryShip::SetFerryJob(v49, 2);
  else
    CFerryShip::SetFerryJob(v49, 1);
  v22 = IEntity::ID();
  v20 = IEntity::Type(v50);
  v16 = IEntity::ObjType((unsigned __int8 *)v50);
  v22 = CFerryShip::CCargo::CCargo((CFerryShip::CCargo *)v23, v16, v20, 1, v22);
  v32 = (struct std::_Iterator_base12 *)std::vector<CFerryShip::CCargo>::end(v26);
  v31 = v32;
  v51 = 2;
  v30 = &v19;
  v29 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v32);
  v28 = std::vector<CFerryShip::CCargo>::insert(v27, v19, v20, v21, v22);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v27);
  v51 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v26);
  v22 = IEntity::Type(v50);
  v17 = IEntity::ObjType((unsigned __int8 *)v50);
  CargoSize = CFerryShip::GetCargoSize(v17, v22);
  *((_DWORD *)v49 + 50) += CargoSize;
  return 0;
}


// address=[0x15969f0]
// Decompiled from _DWORD *__thiscall CFerryShip::FillDialog(CFerryShip *this, bool a2)
void  CFerryShip::FillDialog(bool a2) {
  
  unsigned int v2; // eax
  const struct CFerryShip::CCargo *v3; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-50h] BYREF
  int v6; // [esp+8h] [ebp-4Ch]
  int v7; // [esp+Ch] [ebp-48h]
  char v8; // [esp+19h] [ebp-3Bh]
  unsigned int v9; // [esp+1Ch] [ebp-38h]
  CFerryShip *v10; // [esp+20h] [ebp-34h]
  int v11; // [esp+24h] [ebp-30h]
  unsigned int i; // [esp+28h] [ebp-2Ch]
  CEvn_Event v13; // [esp+2Ch] [ebp-28h] BYREF
  int v14; // [esp+50h] [ebp-4h]

  v10 = this;
  dword_3F1E8BC = 0;
  *(&dword_3F1E8BC + 1) = 0;
  dword_3F1E894[0] = 0;
  dword_3F1E894[1] = 0;
  dword_3F1E894[2] = 0;
  dword_3F1E894[3] = 0;
  dword_3F1E894[4] = 0;
  dword_3F1E8A8[4] = 0;
  dword_3F1E8A8[0] = 0;
  dword_3F1E8A8[1] = 0;
  dword_3F1E8A8[3] = 0;
  dword_3F1E8A8[2] = 0;
  dword_3F1E8A8[4] = 0;
  dword_3F1E890 = 23;
  for ( i = 0; ; ++i )
  {
    v2 = std::vector<CFerryShip::CCargo>::size((char *)v10 + 180);
    if ( i >= v2 )
      break;
    v3 = (const struct CFerryShip::CCargo *)std::vector<CFerryShip::CCargo>::operator[](i);
    CFerryShip::CCargo::CCargo((CFerryShip::CCargo *)v5, v3);
    if ( v8 )
    {
      v11 = v6 - 4;
      switch ( v6 )
      {
        case 4:
          dword_3F1E8BC += v7;
          break;
        case 5:
          *(&dword_3F1E8BC + 1) += v7;
          break;
        case 29:
        case 30:
        case 31:
          dword_3F1E8A8[0] += v7;
          break;
        case 32:
        case 33:
        case 34:
          dword_3F1E8A8[1] += v7;
          break;
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 61:
        case 62:
        case 63:
          dword_3F1E8A8[2] += v7;
          break;
        case 44:
          dword_3F1E8A8[3] += v7;
          break;
        case 45:
          dword_3F1E8A8[4] += v7;
          break;
        case 46:
          dword_3F1E894[4] += v7;
          break;
        case 47:
          dword_3F1E894[3] += v7;
          break;
        case 48:
          dword_3F1E894[2] += v7;
          break;
        case 49:
          dword_3F1E894[1] += v7;
          break;
        case 50:
          dword_3F1E894[0] += v7;
          break;
        default:
          continue;
      }
    }
  }
  v9 = 604;
  if ( !a2 )
    v9 = 602;
  CEvn_Event::CEvn_Event(&v13, v9, 0, (unsigned int)&g_cFerryLoadInfo, 0);
  v14 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v13);
  v14 = -1;
  return CEvn_Event::~CEvn_Event(&v13);
}


// address=[0x1596e10]
// Decompiled from int __thiscall CFerryShip::VehicleLogicUpdate(CFerryShip *this)
void  CFerryShip::VehicleLogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax
  unsigned int v6; // eax
  int v7; // eax
  int CargoSize; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp+0h] [ebp-58h]
  _BYTE v13[24]; // [esp+4h] [ebp-54h] BYREF
  CEntityEvent *v14; // [esp+1Ch] [ebp-3Ch]
  CEntityEvent *v15; // [esp+20h] [ebp-38h]
  int v16; // [esp+24h] [ebp-34h]
  int v17; // [esp+28h] [ebp-30h]
  unsigned int TickCounter; // [esp+2Ch] [ebp-2Ch]
  int v19; // [esp+30h] [ebp-28h]
  char v20; // [esp+34h] [ebp-24h]
  int v21; // [esp+38h] [ebp-20h]
  void **v22; // [esp+3Ch] [ebp-1Ch]
  unsigned int i; // [esp+40h] [ebp-18h]
  CFerryShip::CCargo *v24; // [esp+44h] [ebp-14h]
  CShip *v25; // [esp+48h] [ebp-10h]
  int v26; // [esp+54h] [ebp-4h]

  v25 = this;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( CShip::FULL_UPDATE_DELAY + *((_DWORD *)v25 + 42) < TickCounter )
  {
    v19 = CShip::RepairBuildingInRange(v25);
    if ( v19 )
      CShip::RepairAt(v25, v19);
    *((_DWORD *)v25 + 42) = TickCounter;
  }
  if ( IEntity::FlagBits(v25, (EntityFlag)0x400u) )
    (*(void (__thiscall **)(CShip *, int))(*(_DWORD *)v25 + 148))(v25, 1);
  v20 = *((_BYTE *)v25 + 107);
  switch ( v20 )
  {
    case 6:
      v17 = std::auto_ptr<CWalking>::operator->(v12);
      v1 = IEntity::PackedXY(v25);
      v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v17 + 12))(v17, v1);
      CVehicle::WalkDirAndRegister(v25, v2, 1);
      break;
    case 17:
      goto LABEL_13;
    case 27:
      CVehicle::GetNextJob(v25);
LABEL_13:
      v16 = std::auto_ptr<CWalking>::operator->(v12);
      v3 = IEntity::PackedXY(v25);
      v4 = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v16 + 16))(v16, v3, 0);
      CVehicle::WalkDirAndRegister(v25, v4, 0);
      break;
  }
  result = IEntity::FlagBits(v25, (EntityFlag)&unk_4000000);
  if ( result )
    return result;
  if ( *((unsigned __int8 *)v25 + 107) != *((_DWORD *)v25 + 53) )
  {
    if ( *((_DWORD *)v25 + 53) == 6 )
      CFerryShip::OnShipArrived(v25);
    if ( *((_BYTE *)v25 + 107) == 6 )
    {
      for ( i = 0; ; ++i )
      {
        v6 = std::vector<CFerryShip::CCargo>::size((char *)v25 + 180);
        if ( i >= v6 )
          break;
        v24 = (CFerryShip::CCargo *)std::vector<CFerryShip::CCargo>::operator[](i);
        if ( *((int *)v24 + 2) > 0 && !*((_BYTE *)v24 + 21) )
        {
          v7 = std::vector<CFerryShip::CCargo>::operator[](i);
          result = CMapObjectMgr::EntityPtr(*(_DWORD *)(v7 + 12));
          v22 = (void **)result;
          if ( !result )
          {
            result = BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 281, "pEntity!=NULL");
            if ( result == 1 )
              __debugbreak();
          }
          if ( !v22 )
            return result;
          if ( !j____RTDynamicCast(v22, 0, &IEntity__RTTI_Type_Descriptor_, &IMovingEntity__RTTI_Type_Descriptor_, 0)
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\Ship\\FerryShip.cpp",
                 286,
                 "dynamic_cast<IMovingEntity*>(pEntity)!=NULL") == 1 )
          {
            __debugbreak();
          }
          v21 = j____RTDynamicCast(v22, 0, &IEntity__RTTI_Type_Descriptor_, &IMovingEntity__RTTI_Type_Descriptor_, 0);
          if ( !v21 )
          {
            (*(void (__thiscall **)(CShip *, _DWORD))(*(_DWORD *)v25 + 64))(v25, *((_DWORD *)v24 + 3));
            CargoSize = CFerryShip::CCargo::GetCargoSize(v24);
            *((_DWORD *)v25 + 50) -= *((_DWORD *)v24 + 2) * CargoSize;
            result = (int)v24;
            *((_DWORD *)v24 + 2) = 0;
            *((_BYTE *)v24 + 20) = 0;
            return result;
          }
          v9 = IEntity::ID();
          v15 = CEntityEvent::CEntityEvent((CEntityEvent *)v13, 7u, 0, v9, 0, 0);
          v14 = v15;
          v26 = 0;
          (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v21 + 80))(v21, v15);
          v26 = -1;
          CEntityEvent::~CEntityEvent(v13);
          v10 = IEntity::ID();
          (*(void (__thiscall **)(CShip *, int))(*(_DWORD *)v25 + 64))(v25, v10);
          v11 = CFerryShip::CCargo::GetCargoSize(v24);
          *((_DWORD *)v25 + 50) -= *((_DWORD *)v24 + 2) * v11;
          *((_DWORD *)v24 + 2) = 0;
          *((_BYTE *)v24 + 20) = 0;
        }
      }
      CFerryShip::ClearCargo(v25);
    }
  }
  result = *((unsigned __int8 *)v25 + 107);
  *((_DWORD *)v25 + 53) = result;
  return result;
}


// address=[0x15971a0]
// Decompiled from int __thiscall CFerryShip::Unload(CFerryShip *this)
void  CFerryShip::Unload(void) {
  
  int result; // eax
  unsigned int v2; // eax
  int CargoSize; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp+0h] [ebp-20h]
  int v7; // [esp+4h] [ebp-1Ch] BYREF
  int v8; // [esp+8h] [ebp-18h] BYREF
  int v9; // [esp+Ch] [ebp-14h] BYREF
  int v10; // [esp+10h] [ebp-10h] BYREF
  unsigned int i; // [esp+14h] [ebp-Ch]
  CFerryShip::CCargo *v12; // [esp+18h] [ebp-8h]
  CFerryShip *v13; // [esp+1Ch] [ebp-4h]

  v13 = this;
  result = IEntity::FlagBits(this, (EntityFlag)&unk_4000000);
  if ( result )
    return result;
  v8 = 0;
  v7 = 0;
  v6 = CFerryShip::CalcDistanceToLand(v13, &v8, &v7);
  if ( v6 > *((_DWORD *)v13 + 43) )
    return (*(int (__thiscall **)(CFerryShip *, int))(*(_DWORD *)v13 + 148))(v13, 1);
  for ( i = 0; ; ++i )
  {
    v2 = std::vector<CFerryShip::CCargo>::size((char *)v13 + 180);
    if ( i >= v2 )
      break;
    v12 = (CFerryShip::CCargo *)std::vector<CFerryShip::CCargo>::operator[](i);
    v9 = v8;
    v10 = v7;
    if ( *((int *)v12 + 2) > 0
      && *((_BYTE *)v12 + 21)
      && CFerryShip::FindUnLoadPosition(v13, *(_DWORD *)v12, &v9, &v10)
      && CFerryShip::UnloadAt(v13, *((_DWORD *)v12 + 3), v9, v10) )
    {
      CargoSize = CFerryShip::CCargo::GetCargoSize(v12);
      *((_DWORD *)v13 + 49) -= *((_DWORD *)v12 + 2) * CargoSize;
      v4 = CFerryShip::CCargo::GetCargoSize(v12);
      *((_DWORD *)v13 + 50) -= *((_DWORD *)v12 + 2) * v4;
      *((_DWORD *)v12 + 2) = 0;
      *((_BYTE *)v12 + 21) = 0;
      v5 = Y16X16::PackXYFast(v9, v10);
      *((_DWORD *)v12 + 4) = v5;
    }
  }
  CFerryShip::ClearCargo(v13);
  return (*(int (__thiscall **)(CFerryShip *, int))(*(_DWORD *)v13 + 148))(v13, 1);
}


// address=[0x1597330]
// Decompiled from char __thiscall CFerryShip::EmergencyReload(IEntity *this, int a2)
bool  CFerryShip::EmergencyReload(int a2) {
  
  int v2; // eax
  unsigned int v3; // eax
  int v4; // eax
  int CargoSize; // eax
  char v7; // [esp-10h] [ebp-74h] BYREF
  int v8; // [esp-Ch] [ebp-70h]
  int v9; // [esp-8h] [ebp-6Ch]
  int v10; // [esp-4h] [ebp-68h]
  _BYTE v11[24]; // [esp+4h] [ebp-60h] BYREF
  _BYTE v12[12]; // [esp+1Ch] [ebp-48h] BYREF
  _BYTE v13[12]; // [esp+28h] [ebp-3Ch] BYREF
  int v14; // [esp+34h] [ebp-30h]
  int v15; // [esp+38h] [ebp-2Ch]
  char *v16; // [esp+3Ch] [ebp-28h]
  struct std::_Iterator_base12 *v17; // [esp+40h] [ebp-24h]
  struct std::_Iterator_base12 *v18; // [esp+44h] [ebp-20h]
  int v19; // [esp+48h] [ebp-1Ch]
  unsigned int i; // [esp+4Ch] [ebp-18h]
  unsigned __int16 *v21; // [esp+50h] [ebp-14h]
  IEntity *v22; // [esp+54h] [ebp-10h]
  int v23; // [esp+60h] [ebp-4h]

  v22 = this;
  v21 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(a2);
  if ( !v21 && BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 1127, "pEntity!=NULL") == 1 )
    __debugbreak();
  if ( !v21 )
    return 0;
  v10 = IEntity::ID();
  v8 = IEntity::Type(v21);
  v2 = IEntity::ObjType((unsigned __int8 *)v21);
  v10 = CFerryShip::CCargo::CCargo((CFerryShip::CCargo *)v11, v2, v8, 1, v10);
  v18 = (struct std::_Iterator_base12 *)std::vector<CFerryShip::CCargo>::end(v12);
  v17 = v18;
  v23 = 0;
  v16 = &v7;
  v15 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v18);
  v14 = std::vector<CFerryShip::CCargo>::insert(v13, v7, v8, v9, v10);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v13);
  v23 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v12);
  v19 = 0;
  for ( i = 0; !v19; ++i )
  {
    v3 = std::vector<CFerryShip::CCargo>::size(&v22[45]);
    if ( i >= v3 )
      break;
    if ( *(_DWORD *)(std::vector<CFerryShip::CCargo>::operator[](i) + 12) == a2 )
      v19 = std::vector<CFerryShip::CCargo>::operator[](i);
  }
  if ( !v19 && BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 1142, "pCargo!=NULL") == 1 )
    __debugbreak();
  *(_BYTE *)(v19 + 20) = 1;
  *(_BYTE *)(v19 + 21) = 1;
  IEntity::SetFlagBits(v21, EntityFlag_OnBoard);
  v10 = IEntity::Type(v21);
  v4 = IEntity::ObjType((unsigned __int8 *)v21);
  CargoSize = CFerryShip::GetCargoSize(v4, v10);
  v22[49].CPersistence = (struct IEntityVtbl *)((char *)v22[49].CPersistence + CargoSize);
  if ( IEntity::IsSelected(v22) )
    ((void (__thiscall *)(IEntity *, int))v22->CPersistence[3].Base)(v22, 1);
  return 1;
}


// address=[0x1597530]
// Decompiled from unsigned int __thiscall CFerryShip::EntityOrderCanceled(CFerryShip *this, int a2)
void  CFerryShip::EntityOrderCanceled(int a2) {
  
  unsigned int result; // eax
  int v3; // eax
  int CargoSize; // eax
  _DWORD v5[4]; // [esp-Ch] [ebp-94h] BYREF
  _BYTE v6[24]; // [esp+4h] [ebp-84h] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-6Ch] BYREF
  _BYTE v8[12]; // [esp+28h] [ebp-60h] BYREF
  _BYTE v9[12]; // [esp+34h] [ebp-54h] BYREF
  _BYTE v10[12]; // [esp+40h] [ebp-48h] BYREF
  int v11; // [esp+4Ch] [ebp-3Ch]
  int v12; // [esp+50h] [ebp-38h]
  _DWORD *v13; // [esp+54h] [ebp-34h]
  int v14; // [esp+58h] [ebp-30h]
  int v15; // [esp+5Ch] [ebp-2Ch]
  int v16; // [esp+60h] [ebp-28h]
  CEntityEvent *v17; // [esp+64h] [ebp-24h]
  CEntityEvent *v18; // [esp+68h] [ebp-20h]
  unsigned int i; // [esp+6Ch] [ebp-1Ch]
  CFerryShip::CCargo *v20; // [esp+70h] [ebp-18h]
  CPropertySheet *v21; // [esp+74h] [ebp-14h]
  char v22; // [esp+7Bh] [ebp-Dh]
  int v23; // [esp+84h] [ebp-4h]

  v21 = this;
  v20 = 0;
  for ( i = 0; ; ++i )
  {
    result = std::vector<CFerryShip::CCargo>::size((char *)v21 + 180);
    if ( i >= result )
      break;
    if ( *(_DWORD *)(std::vector<CFerryShip::CCargo>::operator[](i) + 12) == a2 )
      v20 = (CFerryShip::CCargo *)std::vector<CFerryShip::CCargo>::operator[](i);
  }
  if ( !v20 )
  {
    result = BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 364, "pCargo!=NULL");
    if ( result == 1 )
      __debugbreak();
  }
  if ( !v20 )
    return result;
  CFerryShip::SetFerryJob(v21, 0);
  v3 = IEntity::PackedXY(v21);
  v18 = CEntityEvent::CEntityEvent((CEntityEvent *)v6, 0x11u, 13, 0, v3, 0);
  v17 = v18;
  v23 = 0;
  (*(void (__thiscall **)(CPropertySheet *, CEntityEvent *))(*(_DWORD *)v21 + 80))(v21, v18);
  v23 = -1;
  CEntityEvent::~CEntityEvent(v6);
  CargoSize = CFerryShip::CCargo::GetCargoSize(v20);
  *((_DWORD *)v21 + 50) -= *((_DWORD *)v20 + 2) * CargoSize;
  std::vector<CFerryShip::CCargo>::begin(v10);
  v23 = 1;
  while ( 1 )
  {
    v16 = std::vector<CFerryShip::CCargo>::end(v8);
    v15 = v16;
    LOBYTE(v23) = 2;
    v22 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator<=(v16);
    LOBYTE(v23) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v8);
    if ( !v22 )
      break;
    v14 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator*(v10);
    if ( *(_DWORD *)(v14 + 12) == *((_DWORD *)v20 + 3) )
    {
      v13 = v5;
      v12 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>((struct std::_Iterator_base12 *)v10);
      v11 = std::vector<CFerryShip::CCargo>::erase(v7, v5[0], v5[1], v5[2]);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v7);
      v23 = -1;
      return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v10);
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator++(v9, 0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v9);
  }
  v23 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v10);
}


// address=[0x1597760]
// Decompiled from void __thiscall CFerryShip::EntityEnter(CFerryShip *this, int a2)
void  CFerryShip::EntityEnter(int a2) {
  
  int v2; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+4h] [ebp-8h]

  v2 = 0;
  for ( i = 0; i < std::vector<CFerryShip::CCargo>::size((char *)this + 180); ++i )
  {
    if ( *(_DWORD *)(std::vector<CFerryShip::CCargo>::operator[](i) + 12) == a2 )
      v2 = std::vector<CFerryShip::CCargo>::operator[](i);
  }
  if ( !v2 && BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 881, "pCargo!= NULL") == 1 )
    __debugbreak();
  if ( v2 )
  {
    *(_BYTE *)(v2 + 20) = 1;
    if ( CFerryShip::GetFerryJob(this) == 2 || !CFerryShip::GetFerryJob(this) || *((_BYTE *)this + 107) == 17 )
    {
      CFerryShip::OnLoad(this);
      CFerryShip::SetFerryJob(this, 0);
    }
  }
}


// address=[0x1597840]
// Decompiled from bool __thiscall CFerryShip::CanLoad(CFerryShip *this, int a2, int a3)
bool  CFerryShip::CanLoad(int a2, int a3) {
  
  int CargoSize; // [esp+4h] [ebp-8h]

  if ( a2 != 1 && a2 != 4 )
    return 0;
  if ( a2 == 4 && a3 != 5 && a3 != 4 )
    return 0;
  CargoSize = CFerryShip::GetCargoSize(a2, a3);
  return CargoSize + *((_DWORD *)this + 49) <= *((_DWORD *)this + 51)
      && CargoSize + *((_DWORD *)this + 50) <= *((_DWORD *)this + 51);
}


// address=[0x15978d0]
// Decompiled from char __thiscall CFerryShip::AddEntityToFerry(CFerryShip *this, int a2)
bool  CFerryShip::AddEntityToFerry(int a2) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-Ch] [ebp-3Ch]
  int v7; // [esp-4h] [ebp-34h]
  _DWORD v8[6]; // [esp+0h] [ebp-30h] BYREF
  int CargoSize; // [esp+18h] [ebp-18h]
  unsigned __int16 *v10; // [esp+1Ch] [ebp-14h]
  IAnimatedEntity *VehiclePtr; // [esp+20h] [ebp-10h]
  CFerryShip::CCargo *v12; // [esp+24h] [ebp-Ch]
  CFerryShip *v13; // [esp+28h] [ebp-8h]
  unsigned __int8 *SettlerPtr; // [esp+2Ch] [ebp-4h]

  v13 = this;
  if ( !CMapObjectMgr::ValidUsedEntityId(a2) )
    return 0;
  v10 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(a2);
  v7 = IEntity::Type(v10);
  v3 = IEntity::ObjType((unsigned __int8 *)v10);
  if ( !CFerryShip::CanLoad(v13, v3, v7) )
    return 0;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(a2);
  VehiclePtr = CVehicleMgr::GetVehiclePtr(a2);
  if ( !SettlerPtr && !VehiclePtr )
    return 0;
  v6 = IEntity::Type(v10);
  v4 = IEntity::ObjType((unsigned __int8 *)v10);
  v5 = CFerryShip::CCargo::CCargo((CFerryShip::CCargo *)v8, v4, v6, 1, a2);
  std::vector<CFerryShip::CCargo>::push_back(v5);
  v12 = (CFerryShip::CCargo *)std::vector<CFerryShip::CCargo>::back(v8[0], v8[1]);
  CargoSize = CFerryShip::CCargo::GetCargoSize(v12);
  *((_BYTE *)v12 + 20) = 1;
  *((_BYTE *)v12 + 21) = 1;
  *((_DWORD *)v13 + 49) += CargoSize * *((_DWORD *)v12 + 2);
  *((_DWORD *)v13 + 50) += CargoSize * *((_DWORD *)v12 + 2);
  if ( SettlerPtr )
  {
    if ( IEntity::FlagBits(SettlerPtr, EntityFlag_Selected) )
    {
      if ( BBSupportDbgReport(
             2,
             "MapObjects\\Ship\\FerryShip.cpp",
             727,
             "pSettler->FlagBits(ENTITY_FLAG_SELECTED) == 0") == 1 )
        __debugbreak();
    }
    CSettler::TakeWaitList(SettlerPtr);
    (*(void (__thiscall **)(unsigned __int8 *))(*(_DWORD *)SettlerPtr + 56))(SettlerPtr);
    IAnimatedEntity::UnRegisterFromLogicUpdate((IAnimatedEntity *)SettlerPtr);
    IEntity::ClearFlagBits(SettlerPtr, EntityFlag_Selectable|EntityFlag_Visible);
  }
  else
  {
    if ( !VehiclePtr && BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 736, "pVehicle != 0") == 1 )
      __debugbreak();
    IEntity::RemoveFromMapObjectLayerIfNecessary(VehiclePtr);
    IAnimatedEntity::UnRegisterFromLogicUpdate(VehiclePtr);
    IEntity::ClearFlagBits(VehiclePtr, EntityFlag_Selectable|EntityFlag_Visible);
  }
  return 1;
}


// address=[0x1597aa0]
// Decompiled from int __thiscall CFerryShip::CountCargo(CFerryShip *this, struct ICargoCounter *a2)
void  CFerryShip::CountCargo(class ICargoCounter & a2) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  unsigned __int8 *v7; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  result = std::vector<CFerryShip::CCargo>::size((char *)this + 180);
  v6 = result;
  for ( i = 0; i < v6; ++i )
  {
    v5 = std::vector<CFerryShip::CCargo>::operator[](i);
    v7 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*(_DWORD *)(v5 + 12));
    if ( v7 )
    {
      if ( IEntity::FlagBits(v7, (EntityFlag)&loc_3000000) )
      {
        v3 = IEntity::ObjType(v7);
        v4 = IEntity::Type((unsigned __int16 *)v7);
        (**(void (__thiscall ***)(struct ICargoCounter *, int, int))a2)(a2, v3, v4);
      }
    }
    result = i + 1;
  }
  return result;
}


// address=[0x1597b50]
// Decompiled from unsigned int __cdecl CFerryShip::operator new(unsigned int a1)
void * __cdecl CFerryShip::operator new(unsigned int a1) {
  
  return CVehicleMgr::Alloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x1597b70]
// Decompiled from void __cdecl CFerryShip::operator delete(void *a1)
void __cdecl CFerryShip::operator delete(void * a1) {
  
  CVehicleMgr::Dealloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x1597bb0]
// Decompiled from void *__thiscall CFerryShip::GetGfxInfos(CFerryShip *this)
struct SGfxObjectInfo *  CFerryShip::GetGfxInfos(void) {
  
  CShip::GetGfxInfos((int)this);
  if ( IEntity::FlagBits(this, EntityFlag_Selected) )
    byte_40FE264 = CShip::GetHealthDisplayID(this);
  return &IEntity::m_sGfxInfo;
}


// address=[0x1597bf0]
// Decompiled from _DWORD *__thiscall CFerryShip::CFerryShip(_DWORD *this, int a2)
 CFerryShip::CFerryShip(std::istream & a2) {
  
  char v3; // [esp-10h] [ebp-7Ch] BYREF
  int v4; // [esp-Ch] [ebp-78h]
  int v5; // [esp-8h] [ebp-74h]
  int *v6; // [esp-4h] [ebp-70h]
  int v7; // [esp+0h] [ebp-6Ch]
  int v8; // [esp+4h] [ebp-68h] BYREF
  _BYTE v9[4]; // [esp+8h] [ebp-64h] BYREF
  _BYTE v10[4]; // [esp+Ch] [ebp-60h] BYREF
  _BYTE v11[4]; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v12[4]; // [esp+14h] [ebp-58h] BYREF
  char v13; // [esp+18h] [ebp-54h] BYREF
  _BYTE v14[3]; // [esp+19h] [ebp-53h] BYREF
  _BYTE v15[12]; // [esp+1Ch] [ebp-50h] BYREF
  _BYTE v16[12]; // [esp+28h] [ebp-44h] BYREF
  int v17; // [esp+34h] [ebp-38h]
  int v18; // [esp+38h] [ebp-34h]
  char *v19; // [esp+3Ch] [ebp-30h]
  struct std::_Iterator_base12 *v20; // [esp+40h] [ebp-2Ch]
  struct std::_Iterator_base12 *v21; // [esp+44h] [ebp-28h]
  int v22; // [esp+48h] [ebp-24h]
  int v23; // [esp+4Ch] [ebp-20h] BYREF
  int pExceptionObject; // [esp+50h] [ebp-1Ch] BYREF
  int i; // [esp+54h] [ebp-18h]
  _DWORD *v26; // [esp+58h] [ebp-14h]
  unsigned __int8 v27; // [esp+5Eh] [ebp-Eh] BYREF
  unsigned __int8 v28; // [esp+5Fh] [ebp-Dh] BYREF
  int v29; // [esp+68h] [ebp-4h]

  v26 = this;
  CShip::CShip(a2);
  v29 = 0;
  *v26 = &CFerryShip::_vftable_;
  v26[43] = 10;
  v26[44] = 50;
  std::vector<CFerryShip::CCargo>::vector<CFerryShip::CCargo>(v7, v8);
  LOBYTE(v29) = 1;
  v26[51] = 15;
  operator^<unsigned int>(a2, &v23);
  v22 = v23;
  if ( v23 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CFerryShip");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v26 + 49));
  operator^<int>(a2, (int)(v26 + 50));
  v28 = 0;
  operator^<unsigned char>(a2, &v28);
  v26[52] = v28;
  operator^<int>(a2, (int)(v26 + 53));
  operator^<unsigned char>(a2, &v27);
  for ( i = 0; i < v27; ++i )
  {
    CFerryShip::CCargo::CCargo((CFerryShip::CCargo *)&v8);
    operator^<int>(a2, (int)v9);
    operator^<int>(a2, (int)v10);
    operator^<int>(a2, (int)v11);
    operator^<int>(a2, (int)v12);
    operator^<bool>(a2, &v13);
    operator^<int>(a2, (int)&v8);
    operator^<bool>(a2, v14);
    v6 = &v8;
    v21 = (struct std::_Iterator_base12 *)std::vector<CFerryShip::CCargo>::end(v15);
    v20 = v21;
    LOBYTE(v29) = 2;
    v19 = &v3;
    v18 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v21);
    v17 = std::vector<CFerryShip::CCargo>::insert(v16, v3, v4, v5, v6);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v16);
    LOBYTE(v29) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v15);
  }
  v29 = -1;
  return v26;
}


// address=[0x1597e50]
// Decompiled from int __thiscall CFerryShip::Store(int *this, struct std::ostream *a2)
void  CFerryShip::Store(std::ostream & a2) {
  
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int *v8; // eax
  int v9; // eax
  int v10; // [esp+0h] [ebp-10h] BYREF
  int i; // [esp+4h] [ebp-Ch]
  int *v12; // [esp+8h] [ebp-8h]
  int var1; // [esp+Fh] [ebp-1h] BYREF

  v12 = this;
  CShip::Store(a2);
  v10 = 1;
  operator^<unsigned int>(a2, &v10);
  operator^<int>((int)a2, v12 + 49);
  operator^<int>((int)a2, v12 + 50);
  operator^<enum CFerryShip::TFerryJob>(a2, v12 + 52);
  operator^<int>((int)a2, v12 + 53);
  LOBYTE(var1) = std::vector<CFerryShip::CCargo>::size(v12 + 45);
  result = operator^<unsigned char>(a2, (int)&var1);
  for ( i = 0; i < (unsigned __int8)var1; ++i )
  {
    v3 = std::vector<CFerryShip::CCargo>::operator[](i);
    operator^<int>((int)a2, (int *)(v3 + 4));
    v4 = std::vector<CFerryShip::CCargo>::operator[](i);
    operator^<int>((int)a2, (int *)(v4 + 8));
    v5 = std::vector<CFerryShip::CCargo>::operator[](i);
    operator^<int>((int)a2, (int *)(v5 + 12));
    v6 = std::vector<CFerryShip::CCargo>::operator[](i);
    operator^<int>((int)a2, (int *)(v6 + 16));
    v7 = std::vector<CFerryShip::CCargo>::operator[](i);
    operator^<bool>((int)a2, v7 + 20);
    v8 = (int *)std::vector<CFerryShip::CCargo>::operator[](i);
    operator^<int>((int)a2, v8);
    v9 = std::vector<CFerryShip::CCargo>::operator[](i);
    result = operator^<bool>((int)a2, v9 + 21);
  }
  return result;
}


// address=[0x159ba90]
// Decompiled from int __thiscall CFerryShip::ClassID(CFerryShip *this)
unsigned long  CFerryShip::ClassID(void)const {
  
  return CFerryShip::m_iClassID;
}


// address=[0x159bae0]
// Decompiled from int __cdecl CFerryShip::GetCargoSize(int a1, int a2)
int __cdecl CFerryShip::GetCargoSize(int a1, int a2) {
  
  if ( a1 == 4 && (a2 == 5 || a2 == 4) )
    return 5;
  else
    return 1;
}


// address=[0x3d8bfb0]
// [Decompilation failed for static unsigned long CFerryShip::m_iClassID]

// address=[0x1598010]
// Decompiled from CFerryShip *__thiscall CFerryShip::CFerryShip(  CFerryShip *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  bool a8)
 CFerryShip::CFerryShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8) {
  
  int v10; // [esp+0h] [ebp-4h]

  CShip::CShip(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CFerryShip::_vftable_;
  *((_DWORD *)this + 43) = 10;
  *((_DWORD *)this + 44) = 50;
  std::vector<CFerryShip::CCargo>::vector<CFerryShip::CCargo>(this);
  *(_DWORD *)(v10 + 196) = 0;
  *(_DWORD *)(v10 + 200) = 0;
  *(_DWORD *)(v10 + 204) = 15;
  *(_DWORD *)(v10 + 208) = 0;
  *(_DWORD *)(v10 + 212) = *(unsigned __int8 *)(v10 + 107);
  return (CFerryShip *)v10;
}


// address=[0x15980c0]
// Decompiled from void __thiscall CFerryShip::~CFerryShip(CFerryShip *this)
 CFerryShip::~CFerryShip(void) {
  
  CShip *v1; // [esp+0h] [ebp-4h]

  *(_DWORD *)this = &CFerryShip::_vftable_;
  std::vector<CFerryShip::CCargo>::~vector<CFerryShip::CCargo>(this);
  CShip::~CShip(v1);
}


// address=[0x15980f0]
// Decompiled from char __thiscall CFerryShip::OnShipArrived(CFerryShip *this)
bool  CFerryShip::OnShipArrived(void) {
  
  if ( CFerryShip::GetFerryJob(this) != 1 )
    return 1;
  if ( CFerryShip::OnLoad(this) )
  {
    CFerryShip::SetFerryJob(this, 0);
  }
  else
  {
    CFerryShip::SetFerryJob(this, 2);
    IAnimatedEntity::RegisterForLogicUpdate(16);
  }
  return 1;
}


// address=[0x1598140]
// Decompiled from char __thiscall CFerryShip::OnLoad(IEntity *this)
bool  CFerryShip::OnLoad(void) {
  
  void **VehiclePtr; // eax
  int LastLogicUpdateTick; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // [esp-4h] [ebp-1Ch]
  int v10; // [esp-4h] [ebp-1Ch]
  unsigned __int16 *v11; // [esp+0h] [ebp-18h]
  unsigned int i; // [esp+4h] [ebp-14h]
  int v13; // [esp+8h] [ebp-10h]
  CPaneContainer *v14; // [esp+Ch] [ebp-Ch]
  CPropertySet *SettlerPtr; // [esp+10h] [ebp-8h]

  for ( i = 0; i < std::vector<CFerryShip::CCargo>::size(&this[45]); ++i )
  {
    v13 = std::vector<CFerryShip::CCargo>::operator[](i);
    if ( *(_BYTE *)(v13 + 20) && !*(_BYTE *)(v13 + 21) )
    {
      v11 = 0;
      VehiclePtr = (void **)CVehicleMgr::GetVehiclePtr(*(_DWORD *)(v13 + 12));
      v14 = (CPaneContainer *)j____RTDynamicCast(
                                VehiclePtr,
                                0,
                                &CVehicle__RTTI_Type_Descriptor_,
                                &CWheeler__RTTI_Type_Descriptor_,
                                0);
      SettlerPtr = (CPropertySet *)CSettlerMgr::GetSettlerPtr(*(_DWORD *)(v13 + 12));
      if ( !SettlerPtr && !v14 )
        return 0;
      if ( v14 )
      {
        CWheeler::RemoveFromWorld(v14);
        v9 = IEntity::ID();
        LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(v14);
        CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v9);
        IEntity::SetFlagBits(v14, EntityFlag_OnBoard);
        v11 = (unsigned __int16 *)v14;
        v4 = IEntity::ID();
        ((void (__thiscall *)(IEntity *, int))this->CPersistence[1].Relationships)(this, v4);
      }
      if ( SettlerPtr )
      {
        CWarMap::RemoveEntity(SettlerPtr);
        v5 = IEntity::WorldIdx();
        CWorldManager::SetSettlerId(v5, 0);
        IEntity::SetFlagBits(SettlerPtr, EntityFlag_OnBoard);
        if ( IEntity::FlagBits(SettlerPtr, EntityFlag_Selected) )
        {
          v6 = IEntity::ID();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v6);
        }
        v11 = (unsigned __int16 *)SettlerPtr;
        v7 = IEntity::ID();
        ((void (__thiscall *)(IEntity *, int))this->CPersistence[1].Relationships)(this, v7);
      }
      v10 = IEntity::Type(v11);
      v8 = IEntity::ObjType((unsigned __int8 *)v11);
      this[49].CPersistence = (struct IEntityVtbl *)((char *)this[49].CPersistence + CFerryShip::GetCargoSize(v8, v10));
      *(_BYTE *)(v13 + 21) = 1;
    }
  }
  if ( IEntity::IsSelected(this) )
    ((void (__thiscall *)(IEntity *, int))this->CPersistence[3].Base)(this, 1);
  return 1;
}


// address=[0x1598330]
// Decompiled from int __thiscall CFerryShip::CalcDistanceToLand(CFerryShip *this, int *a2, int *a3)
int  CFerryShip::CalcDistanceToLand(int & a2, int & a3) {
  
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v7; // [esp-4h] [ebp-24h]
  int v8; // [esp+4h] [ebp-1Ch]
  int v9; // [esp+8h] [ebp-18h]
  int v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]

  v10 = *((_DWORD *)this + 43) + 1;
  v8 = CSpiralOffsets::Last(*((_DWORD *)this + 43));
  for ( i = 0; i <= v8; ++i )
  {
    v3 = IEntity::X(this);
    v12 = CSpiralOffsets::DeltaX(i) + v3;
    v4 = IEntity::Y(this);
    v11 = CSpiralOffsets::DeltaY(i) + v4;
    if ( (unsigned __int8)CWorldManager::InWorld(v12, v11) && !CWorldManager::IsWater(v12, v11) )
    {
      v7 = v11 - IEntity::Y(this);
      v5 = IEntity::X(this);
      v9 = Grid::Distance((Grid *)(v12 - v5), v7);
      if ( v9 < v10 )
      {
        v10 = v9;
        *a2 = v12;
        *a3 = v11;
      }
    }
  }
  return v10;
}


// address=[0x1598440]
// Decompiled from char __thiscall CFerryShip::FindLoadPosition(CFerryShip *this, unsigned int a2, int *a3, int *a4)
bool  CFerryShip::FindLoadPosition(int a2, int & a3, int & a4) {
  
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp+8h] [ebp-88h]
  int v9; // [esp+Ch] [ebp-84h]
  int v10; // [esp+10h] [ebp-80h]
  int v11; // [esp+1Ch] [ebp-74h]
  int i; // [esp+20h] [ebp-70h]
  int v13; // [esp+24h] [ebp-6Ch]
  int v14; // [esp+28h] [ebp-68h]
  unsigned __int8 *v15; // [esp+2Ch] [ebp-64h]
  bool v16; // [esp+33h] [ebp-5Dh]
  _BYTE v17[88]; // [esp+34h] [ebp-5Ch] BYREF

  if ( !CMapObjectMgr::ValidEntityId(a2)
    && BBSupportDbgReport(2, "MapObjects\\Ship\\FerryShip.cpp", 484, "g_pMapObjectMgr->ValidEntityId(_iEntityId)") == 1 )
  {
    __debugbreak();
  }
  v15 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a2);
  if ( !v15 )
    return 0;
  v10 = CSpiralOffsets::Last(10);
  for ( i = 0; i <= v10; ++i )
  {
    v14 = *a3 + CSpiralOffsets::DeltaX(i);
    v13 = *a4 + CSpiralOffsets::DeltaY(i);
    v11 = Y16X16::PackXYFast(v14, v13);
    if ( (unsigned __int8)CWorldManager::InWorld(v14, v13) && !CWorldManager::IsWater(v14, v13) )
    {
      if ( IEntity::ObjType(v15) == 1 && CWorldManager::IsPositionFreeForSettler(v14, v13)
        || IEntity::ObjType(v15) != 1
        && (v5 = IEntity::Type((unsigned __int16 *)v15),
            CVehicleMgr::IsPositionFreeForVehicle((CVehicleMgr *)&g_cVehicleMgr, v14, v13, v5)) )
      {
        v9 = CWorldManager::MapObjectId(v14, v13);
        v8 = CWorldManager::Index(v11);
        if ( !v9 && !CWorldManager::FlagBits(v8, 1u) )
        {
          if ( IEntity::ObjType(v15) == 1 )
          {
            v6 = IEntity::PackedXY(v15);
            v16 = CAStarTiling::FindPath(v6, v11, (struct CWaypoints *)v17, 0) != 0;
          }
          else
          {
            v7 = IEntity::PackedXY(v15);
            v16 = CAStarTiling::FindPath(v7, v11, (struct CWaypoints *)v17, 2) != 0;
          }
          if ( v16 )
          {
            *a3 = v14;
            *a4 = v13;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// address=[0x15986b0]
// Decompiled from char __thiscall CFerryShip::FindUnLoadPosition(CFerryShip *this, int a2, int *a3, int *a4)
bool  CFerryShip::FindUnLoadPosition(int a2, int & a3, int & a4) {
  
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v9; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+14h] [ebp-28h]
  int v11; // [esp+18h] [ebp-24h]
  int m; // [esp+20h] [ebp-1Ch]
  int k; // [esp+24h] [ebp-18h]
  unsigned int j; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  int v17; // [esp+30h] [ebp-Ch]
  int v18; // [esp+34h] [ebp-8h]
  char v19; // [esp+3Bh] [ebp-1h]

  v11 = CSpiralOffsets::Last(*((_DWORD *)this + 43));
  for ( i = 0; i <= v11; ++i )
  {
    v18 = *a3 + CSpiralOffsets::DeltaX(i);
    v17 = *a4 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v18, v17) )
    {
      if ( (v4 = CWorldManager::Index(v18, v17), ITiling::CatapultSectorId(v4), a2 == 1)
        && CWorldManager::IsPositionFreeForSettler(v18, v17)
        || a2 != 1 && CVehicleMgr::IsPositionFreeForVehicle((CVehicleMgr *)&g_cVehicleMgr, v18, v17, a2) )
      {
        v19 = 0;
        for ( j = 0; j < std::vector<CFerryShip::CCargo>::size((char *)this + 180) && !v19; ++j )
        {
          for ( k = 0; k < 6 && !v19; ++k )
          {
            v5 = Y16X16::PackXYFast(v18, v17);
            v10 = CWorldManager::Index(v5);
            v6 = std::vector<CFerryShip::CCargo>::operator[](j);
            v7 = CWorldManager::Index(*(_DWORD *)(v6 + 16));
            v9 = CWorldManager::NeighborRelIndex(k) + v7;
            for ( m = 0; m < 6; ++m )
            {
              if ( v9 == v10 + CWorldManager::NeighborRelIndex(m) )
              {
                v19 = 1;
                break;
              }
            }
          }
        }
        if ( !CWorldManager::MapObjectId(v18, v17) && !v19 )
        {
          *a3 = v18;
          *a4 = v17;
          return 1;
        }
      }
    }
  }
  return 0;
}


// address=[0x15988e0]
// Decompiled from char __thiscall CFerryShip::UnloadAt(CFerryShip *this, int a2, int a3, int a4)
bool  CFerryShip::UnloadAt(int a2, int a3, int a4) {
  
  void **VehiclePtr; // eax
  int v5; // eax
  int v7; // eax
  _BYTE v8[24]; // [esp+4h] [ebp-58h] BYREF
  _BYTE v9[24]; // [esp+1Ch] [ebp-40h] BYREF
  CEntityEvent *v10; // [esp+34h] [ebp-28h]
  CEntityEvent *v11; // [esp+38h] [ebp-24h]
  CEntityEvent *v12; // [esp+3Ch] [ebp-20h]
  CEntityEvent *v13; // [esp+40h] [ebp-1Ch]
  CFerryShip *v14; // [esp+44h] [ebp-18h]
  unsigned __int8 *SettlerPtr; // [esp+48h] [ebp-14h]
  int v16; // [esp+4Ch] [ebp-10h]
  int v17; // [esp+58h] [ebp-4h]

  v14 = this;
  VehiclePtr = (void **)CVehicleMgr::GetVehiclePtr(a2);
  v16 = j____RTDynamicCast(VehiclePtr, 0, &CVehicle__RTTI_Type_Descriptor_, &CWheeler__RTTI_Type_Descriptor_, 0);
  if ( v16 )
  {
    v5 = IEntity::ID();
    v13 = CEntityEvent::CEntityEvent((CEntityEvent *)v9, 0x19u, 0, v5, a3, a4);
    v12 = v13;
    v17 = 0;
    (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v16 + 80))(v16, v13);
    v17 = -1;
    CEntityEvent::~CEntityEvent(v9);
    return 1;
  }
  else
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr(a2);
    if ( SettlerPtr )
    {
      v7 = Y16X16::PackXYFast(a3, a4);
      v11 = CEntityEvent::CEntityEvent((CEntityEvent *)v8, 0x19u, 0, 0, v7, 0);
      v10 = v11;
      v17 = 1;
      (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v11);
      v17 = -1;
      CEntityEvent::~CEntityEvent(v8);
      return 1;
    }
    else
    {
      return 0;
    }
  }
}


// address=[0x1598a10]
// Decompiled from int __thiscall CFerryShip::ClearCargo(CFerryShip *this)
void  CFerryShip::ClearCargo(void) {
  
  _DWORD v2[4]; // [esp-Ch] [ebp-78h] BYREF
  _BYTE v3[12]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-50h] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-44h] BYREF
  int v7; // [esp+34h] [ebp-38h]
  _DWORD *v8; // [esp+38h] [ebp-34h]
  int v9; // [esp+3Ch] [ebp-30h]
  int v10; // [esp+40h] [ebp-2Ch]
  int v11; // [esp+44h] [ebp-28h]
  std::_Iterator_base12 *v12; // [esp+48h] [ebp-24h]
  std::_Iterator_base12 *v13; // [esp+4Ch] [ebp-20h]
  BOOL v14; // [esp+50h] [ebp-1Ch]
  CFerryShip *v15; // [esp+54h] [ebp-18h]
  int v16; // [esp+58h] [ebp-14h]
  bool v17; // [esp+5Fh] [ebp-Dh]
  int v18; // [esp+68h] [ebp-4h]

  v15 = this;
  v16 = 0;
  std::vector<CFerryShip::CCargo>::begin(v6);
  v18 = 0;
  while ( 1 )
  {
    v14 = std::vector<CFerryShip::CCargo>::size((char *)v15 + 180)
       && (v13 = (std::_Iterator_base12 *)std::vector<CFerryShip::CCargo>::end(v5),
           v12 = v13,
           LOBYTE(v18) = 1,
           v16 |= 1u,
           (unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator!=(v13));
    v17 = v14;
    v18 = 0;
    if ( (v16 & 1) != 0 )
    {
      v16 &= ~1u;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v5);
    }
    if ( !v17 )
      break;
    v11 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator*(v6);
    if ( *(int *)(v11 + 8) > 0 )
    {
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator++(v3, 0);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v3);
    }
    else
    {
      v8 = v2;
      v7 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>((struct std::_Iterator_base12 *)v6);
      v10 = std::vector<CFerryShip::CCargo>::erase(v4, v2[0], v2[1], v2[2]);
      v9 = v10;
      LOBYTE(v18) = 2;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator=(v10);
      LOBYTE(v18) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v4);
    }
  }
  v18 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v6);
}


// address=[0x1598b80]
// Decompiled from int __thiscall CFerryShip::DeleteCargo(CFerryShip *this, struct CFerryShip::CCargo *a2)
void  CFerryShip::DeleteCargo(class CFerryShip::CCargo & a2) {
  
  _DWORD v3[4]; // [esp-Ch] [ebp-74h] BYREF
  _BYTE v4[12]; // [esp+4h] [ebp-64h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-58h] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-4Ch] BYREF
  _BYTE v7[12]; // [esp+28h] [ebp-40h] BYREF
  int v8; // [esp+34h] [ebp-34h]
  int v9; // [esp+38h] [ebp-30h]
  _DWORD *v10; // [esp+3Ch] [ebp-2Ch]
  int v11; // [esp+40h] [ebp-28h]
  int v12; // [esp+44h] [ebp-24h]
  int v13; // [esp+48h] [ebp-20h]
  BOOL v14; // [esp+4Ch] [ebp-1Ch]
  CFerryShip *v15; // [esp+50h] [ebp-18h]
  int v16; // [esp+54h] [ebp-14h]
  bool v17; // [esp+5Bh] [ebp-Dh]
  int v18; // [esp+64h] [ebp-4h]

  v15 = this;
  v16 = 0;
  std::vector<CFerryShip::CCargo>::begin(v7);
  v18 = 0;
  while ( 1 )
  {
    v14 = std::vector<CFerryShip::CCargo>::size((char *)v15 + 180)
       && (v13 = std::vector<CFerryShip::CCargo>::end(v5),
           v12 = v13,
           LOBYTE(v18) = 1,
           v16 |= 1u,
           (unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator<=(v13));
    v17 = v14;
    v18 = 0;
    if ( (v16 & 1) != 0 )
    {
      v16 &= ~1u;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v5);
    }
    if ( !v17 )
      break;
    v11 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator*(v7);
    if ( *(_DWORD *)(v11 + 12) == *((_DWORD *)a2 + 3) )
    {
      v10 = v3;
      v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>((struct std::_Iterator_base12 *)v7);
      v8 = std::vector<CFerryShip::CCargo>::erase(v4, v3[0], v3[1], v3[2]);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v4);
      v18 = -1;
      return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v7);
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::operator++(v6, 0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v6);
  }
  v18 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CFerryShip::CCargo>>>(v7);
}


// address=[0x1598cf0]
// Decompiled from char __thiscall CFerryShip::HasRegisterdCargo(CFerryShip *this, int a2)
bool  CFerryShip::HasRegisterdCargo(int a2) {
  
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < std::vector<CFerryShip::CCargo>::size((char *)this + 180); ++i )
  {
    if ( *(_DWORD *)(std::vector<CFerryShip::CCargo>::operator[](i) + 12) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x1598d50]
// Decompiled from _DWORD *__thiscall CFerryShip::NotifyDetach(CFerryShip *this, int a2)
void  CFerryShip::NotifyDetach(int a2) {
  
  _DWORD *result; // eax

  result = (_DWORD *)CMapObjectMgr::EntityPtr(a2);
  if ( !result )
    return result;
  result = (_DWORD *)IEntity::FlagBits(result, (EntityFlag)&loc_3000000);
  if ( !result )
    return (_DWORD *)(*(int (__thiscall **)(CFerryShip *, int))(*(_DWORD *)this + 124))(this, a2);
  return result;
}


// address=[0x159bb10]
// Decompiled from int __thiscall CFerryShip::GetFerryJob(_DWORD *this)
enum CFerryShip::TFerryJob  CFerryShip::GetFerryJob(void) {
  
  return this[52];
}


// address=[0x159bb70]
// Decompiled from void __thiscall CFerryShip::SetFerryJob(CPropertySheet *this, int a2)
void  CFerryShip::SetFerryJob(enum CFerryShip::TFerryJob a2) {
  
  *((_DWORD *)this + 52) = a2;
}


