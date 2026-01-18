#include "CTowerSoldier.h"

// Definitions for class CTowerSoldier

// address=[0x1402340]
// Decompiled from int __cdecl CTowerSoldier::New(int a1)
class CPersistence * __cdecl CTowerSoldier::New(std::istream & a1) {
  
  if ( operator new(0x34u) )
    return CTowerSoldier::CTowerSoldier(a1);
  else
    return 0;
}


// address=[0x15139d0]
// Decompiled from int __thiscall CTowerSoldier::GetSlot(CTowerSoldier *this)
int  CTowerSoldier::GetSlot(void)const {
  
  return *((unsigned __int8 *)this + 44);
}


// address=[0x1588980]
// Decompiled from int __cdecl CTowerSoldier::Load(int a1)
class CTowerSoldier * __cdecl CTowerSoldier::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CTowerSoldier__RTTI_Type_Descriptor_, 1);
}


// address=[0x15948d0]
// Decompiled from int __thiscall CTowerSoldier::InitWalking(CTowerSoldier *this, struct CSettler *a2)
class CWalking *  CTowerSoldier::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1594910]
// Decompiled from void __thiscall CTowerSoldier::LogicUpdate(CTowerSoldier *this, struct CSettler *a2)
void  CTowerSoldier::LogicUpdate(class CSettler * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  struct IEntity *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  struct IEntity *v16; // eax
  Y16X16 *v17; // eax
  int v18; // eax
  struct IEntity *v19; // eax
  int v20; // eax
  char v21; // al
  int v22; // [esp-10h] [ebp-60h]
  int v23; // [esp-10h] [ebp-60h]
  int v24; // [esp-8h] [ebp-58h]
  int v25; // [esp-8h] [ebp-58h]
  int v26; // [esp-4h] [ebp-54h]
  int v27; // [esp-4h] [ebp-54h]
  int v28; // [esp-4h] [ebp-54h]
  int v29; // [esp-4h] [ebp-54h]
  int v30; // [esp-4h] [ebp-54h]
  int v31; // [esp-4h] [ebp-54h]
  int v32; // [esp-4h] [ebp-54h]
  int v33; // [esp-4h] [ebp-54h]
  int v34; // [esp-4h] [ebp-54h]
  int v35; // [esp-4h] [ebp-54h]
  int v36; // [esp-4h] [ebp-54h]
  int v37; // [esp+8h] [ebp-48h]
  char v38; // [esp+Ch] [ebp-44h]
  char v39; // [esp+10h] [ebp-40h]
  int v40; // [esp+18h] [ebp-38h]
  int v41; // [esp+1Ch] [ebp-34h]
  int v42; // [esp+20h] [ebp-30h]
  int v43; // [esp+24h] [ebp-2Ch]
  int BuildingInfo; // [esp+28h] [ebp-28h]
  char v45; // [esp+30h] [ebp-20h]
  char v46; // [esp+34h] [ebp-1Ch]
  int v47; // [esp+38h] [ebp-18h]
  int v48; // [esp+38h] [ebp-18h]
  CMFCToolBarButton *v49; // [esp+3Ch] [ebp-14h]
  unsigned __int8 *v50; // [esp+40h] [ebp-10h]
  int v51; // [esp+44h] [ebp-Ch]
  int v52; // [esp+44h] [ebp-Ch]
  char v54; // [esp+4Fh] [ebp-1h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Settler\\TowerSoldierRole.cpp", 255, "_pSettler != 0") == 1 )
    __debugbreak();
  v45 = *((_BYTE *)this + 4);
  if ( v45 == 16 )
  {
    v50 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
    if ( v50 && IEntity::FlagBits(v50, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    {
      v47 = *((unsigned __int8 *)this + 47);
      v2 = IEntity::OwnerId((unsigned __int8 *)a2);
      v48 = (CStatistic::DefenceStrength256((CStatistic *)&g_cStatistic, v2) * v47 + 127) >> 8;
      v3 = IEntity::OwnerId(v50);
      if ( v3 == CPlayerManager::GetLocalPlayerId() )
      {
        v26 = IEntity::Y(v50);
        v4 = IEntity::X(v50);
        CAttackMsgList::SendAttackMessage((CAttackMsgList *)&g_cAttackMsgList, v4, v26);
      }
      v5 = IEntity::OwnerId((unsigned __int8 *)a2);
      (*(void (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)v50 + 28))(v50, v48, v5);
      *((_DWORD *)this + 12) = CStateGame::GetTickCounter(g_pGame);
    }
  }
  else if ( v45 != 17 )
  {
    if ( BBSupportDbgReportF(
           1,
           "MapObjects\\Settler\\TowerSoldierRole.cpp",
           431,
           "CTowerSoldier::LogicUpdate(): Invalid task %i!",
           *((char *)this + 4)) == 1 )
      __debugbreak();
    return;
  }
  v49 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  v51 = 0;
  v46 = 0;
  v54 = 0;
  switch ( *((_BYTE *)this + 45) )
  {
    case 0:
      return;
    case 1:
      v27 = CBuilding::DoorPackedXY(v49);
      v6 = IEntity::OwnerId((unsigned __int8 *)v49);
      v52 = CTowerSoldier::SearchDoorGuardTarget(v6, v27);
      if ( v52 <= 0 )
        goto LABEL_17;
      v28 = IEntity::Type((unsigned __int16 *)a2);
      v7 = IEntity::Race(a2);
      v39 = *(_BYTE *)(CSettlerMgr::GetSettlerInfo(v7, v28) + 3);
      *((_WORD *)this + 17) = v52;
      *((_BYTE *)this + 47) = v39 + CStaticConfigVarInt::operator int(&unk_4158CC0);
      IMovingEntity::SetDirection(a2, *((unsigned __int8 *)this + 46));
      CSettler::TakeAnimList(a2, 2);
      if ( IEntity::WarriorType() != 3 )
        return;
      v29 = IEntity::Type((unsigned __int16 *)v49);
      v8 = IEntity::Race(a2);
      BuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v8, v29);
      v43 = CLogic::Effects((DWORD *)g_pLogic);
      v30 = *(_DWORD *)(BuildingInfo + 12 * *((unsigned __int8 *)this + 44) + 228);
      v24 = *(_DWORD *)(BuildingInfo + 12 * *((unsigned __int8 *)this + 44) + 224);
      v9 = CMapObjectMgr::Entity(*((unsigned __int16 *)this + 17));
      v22 = IEntity::PackedXY(v9);
      v10 = IEntity::PackedXY(a2);
      (*(void (__thiscall **)(int, int, int, int, int, int, int))(*(_DWORD *)v43 + 24))(v43, 5, v10, v22, 15, v24, v30);
      return;
    case 2:
LABEL_17:
      v31 = IEntity::PackedXY(a2);
      v11 = IEntity::OwnerId((unsigned __int8 *)a2);
      v51 = CTowerSoldier::SearchBowmanTarget(v11, v31);
      v46 = CStaticConfigVarInt::operator int(&unk_4158CB4);
      goto LABEL_35;
    case 3:
      if ( !*((_DWORD *)this + 12)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\TowerSoldierRole.cpp", 346, "m_uLastActionTick > 0") == 1 )
      {
        __debugbreak();
      }
      v12 = IEntity::PackedXY(a2);
      if ( v12 != CBuilding::DoorPackedXY(v49)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\TowerSoldierRole.cpp",
             347,
             "_pSettler->PackedXY() == rBuilding.DoorPackedXY()") == 1 )
      {
        __debugbreak();
      }
      if ( IEntity::WarriorType() != 13
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\TowerSoldierRole.cpp",
             348,
             "_pSettler->WarriorType() == WARRIOR_TYPE_TOWER_GUARD") == 1 )
      {
        __debugbreak();
      }
      v32 = IEntity::PackedXY(a2);
      v13 = IEntity::OwnerId((unsigned __int8 *)a2);
      v51 = CTowerSoldier::SearchDoorGuardTarget(v13, v32);
      v46 = CStaticConfigVarInt::operator int(&unk_4158CCC);
      v14 = IEntity::Type((unsigned __int16 *)a2);
      if ( CSettlerMgr::SettlerWarriorType(v14) == 3 )
        v54 = 1;
      if ( v51 > 0 || CStateGame::GetTickCounter(g_pGame) < (unsigned int)(*((_DWORD *)this + 12) + 45) )
        goto LABEL_35;
      CTowerSoldier::WorkIsDone(this, a2);
      break;
    default:
      if ( BBSupportDbgReportF(
             1,
             "MapObjects\\Settler\\TowerSoldierRole.cpp",
             372,
             "CTowerSoldier::LogicUpdate(): Invalid position %i!",
             *((unsigned __int8 *)this + 45)) == 1 )
        __debugbreak();
LABEL_35:
      if ( v51 <= 0 )
      {
        *((_WORD *)this + 17) = 0;
        IMovingEntity::SetDirection(a2, *((unsigned __int8 *)this + 46));
        if ( *((_BYTE *)this + 4) == 17 )
        {
          if ( *((_BYTE *)this + 45) == 3 )
            v40 = 4;
          else
            v40 = 31;
          v21 = CStateGame::Rand(g_pGame);
          IAnimatedEntity::RegisterForLogicUpdate(v40 - (v21 & 3));
        }
        else
        {
          CSettler::TakeWaitList(a2);
        }
      }
      else
      {
        v33 = IEntity::Type((unsigned __int16 *)a2);
        v15 = IEntity::Race(a2);
        v38 = *(_BYTE *)(CSettlerMgr::GetSettlerInfo(v15, v33) + 3);
        *((_WORD *)this + 17) = v51;
        *((_BYTE *)this + 47) = v46 + v38;
        v16 = CMapObjectMgr::Entity(v51);
        v34 = IEntity::PackedXY(v16);
        v17 = (Y16X16 *)IEntity::PackedXY(a2);
        v37 = Y16X16::DirectionFast(v17, v34);
        IMovingEntity::SetDirection(a2, v37);
        if ( v54 )
        {
          CSettler::TakeAnimList(a2, 3);
        }
        else
        {
          CSettler::TakeAnimList(a2, 1);
          if ( IEntity::WarriorType() == 3 )
          {
            v35 = IEntity::Type((unsigned __int16 *)v49);
            v18 = IEntity::Race(a2);
            v42 = CBuildingInfoMgr::GetBuildingInfo(v18, v35);
            v41 = CLogic::Effects((DWORD *)g_pLogic);
            v36 = *(_DWORD *)(v42 + 12 * *((unsigned __int8 *)this + 44) + 228);
            v25 = *(_DWORD *)(v42 + 12 * *((unsigned __int8 *)this + 44) + 224);
            v19 = CMapObjectMgr::Entity(*((unsigned __int16 *)this + 17));
            v23 = IEntity::PackedXY(v19);
            v20 = IEntity::PackedXY(a2);
            (*(void (__thiscall **)(int, _DWORD, int, int, int, int, int))(*(_DWORD *)v41 + 24))(
              v41,
              0,
              v20,
              v23,
              15,
              v25,
              v36);
          }
        }
      }
      break;
  }
}


// address=[0x1594ef0]
// Decompiled from void __thiscall CTowerSoldier::PostLoadInit(CTowerSoldier *this, struct CSettler *a2)
void  CTowerSoldier::PostLoadInit(class CSettler *) {
  
  ;
}


// address=[0x1594f00]
// Decompiled from char __thiscall CTowerSoldier::SetFree(CTowerSoldier *this, struct CSettler *a2, int a3)
bool  CTowerSoldier::SetFree(class CSettler * a2, int a3) {
  
  CBuilding *v3; // eax
  int v5; // [esp-4h] [ebp-8h]

  if ( !*((_WORD *)this + 16) )
    return 0;
  v5 = IEntity::ID();
  v3 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  CBuilding::InhabitantFlee(v3, v5);
  *((_WORD *)this + 16) = 0;
  return 0;
}


// address=[0x1594f50]
// Decompiled from int __thiscall CTowerSoldier::SetTowerInfo(int this, unsigned int a2, int a3, unsigned int a4)
void  CTowerSoldier::SetTowerInfo(int a2, enum CTowerSoldier::T_TOWER_POSITION a3, int a4) {
  
  int result; // eax

  if ( a2 >= 0x100
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\TowerSoldierRole.cpp",
         926,
         "(_iSlotIndex >= 0) && (_iSlotIndex < 256)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 6
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\TowerSoldierRole.cpp",
         927,
         "(_iDefaultDir >= 0) && (_iDefaultDir < 6)") == 1 )
  {
    __debugbreak();
  }
  *(_BYTE *)(this + 44) = a2;
  *(_BYTE *)(this + 45) = a3;
  result = this;
  *(_BYTE *)(this + 46) = a4;
  if ( a3 == 3 )
  {
    result = CStateGame::GetTickCounter(g_pGame);
    *(_DWORD *)(this + 48) = result;
  }
  else
  {
    *(_DWORD *)(this + 48) = 0;
  }
  return result;
}


// address=[0x1595000]
// Decompiled from int __thiscall CTowerSoldier::Decrease(CTowerSoldier *this, int a2)
int  CTowerSoldier::Decrease(int a2) {
  
  *((_DWORD *)this + 12) = CStateGame::GetTickCounter(g_pGame);
  return a2;
}


// address=[0x1595030]
// Decompiled from char *__thiscall CTowerSoldier::CTowerSoldier(char *this, int a2)
 CTowerSoldier::CTowerSoldier(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CTowerSoldier::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTowerSoldier");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v5 + 44);
  operator^<unsigned char>(a2, v5 + 45);
  operator^<unsigned char>(a2, v5 + 46);
  operator^<unsigned char>(a2, v5 + 47);
  operator^<unsigned int>(a2, v5 + 48);
  v6 = -1;
  return v5;
}


// address=[0x1595140]
// Decompiled from int __thiscall CTowerSoldier::Store(struct CPersistence *this, struct std::ostream *a2)
void  CTowerSoldier::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned char>(a2, (int)v4 + 44);
  operator^<unsigned char>(a2, (int)v4 + 45);
  operator^<unsigned char>(a2, (int)v4 + 46);
  operator^<unsigned char>(a2, (int)v4 + 47);
  return operator^<unsigned int>(a2, (int *)v4 + 12);
}


// address=[0x15962c0]
// Decompiled from int __thiscall CTowerSoldier::ClassID(CTowerSoldier *this)
unsigned long  CTowerSoldier::ClassID(void)const {
  
  return CTowerSoldier::m_iClassID;
}


// address=[0x15962e0]
// Decompiled from int __thiscall CTowerSoldier::GetSettlerRole(CTowerSoldier *this)
int  CTowerSoldier::GetSettlerRole(void)const {
  
  return 22;
}


// address=[0x1596300]
// Decompiled from void __thiscall CTowerSoldier::LogicUpdateJob(CTowerSoldier *this, struct CSettler *a2)
void  CTowerSoldier::LogicUpdateJob(class CSettler *) {
  
  ;
}


// address=[0x3d8bfac]
// [Decompilation failed for static unsigned long CTowerSoldier::m_iClassID]

// address=[0x15951e0]
// Decompiled from int __cdecl CTowerSoldier::SearchDoorGuardTarget(int a1, int a2)
int __cdecl CTowerSoldier::SearchDoorGuardTarget(int a1, int a2) {
  
  int v2; // eax
  int v4; // [esp+8h] [ebp-40h]
  int v5; // [esp+Ch] [ebp-3Ch]
  int v6; // [esp+10h] [ebp-38h]
  int v7; // [esp+14h] [ebp-34h]
  int v8; // [esp+18h] [ebp-30h]
  int v9; // [esp+1Ch] [ebp-2Ch]
  __int64 v10; // [esp+20h] [ebp-28h]
  int v11; // [esp+28h] [ebp-20h]
  int v12; // [esp+2Ch] [ebp-1Ch]
  int v13; // [esp+30h] [ebp-18h]
  int v14; // [esp+34h] [ebp-14h]
  int v15; // [esp+38h] [ebp-10h]
  int v16; // [esp+3Ch] [ebp-Ch]
  unsigned __int8 *v17; // [esp+40h] [ebp-8h]
  int i; // [esp+44h] [ebp-4h]

  v14 = Y16X16::UnpackXFast(a2);
  v13 = Y16X16::UnpackYFast(a2);
  v11 = CAlliances::AllianceId(a1);
  if ( !CWorldManager::InInnerWorld2(v14, v13)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\TowerSoldierRole.cpp", 734, "g_cWorld.InInnerWorld2(iX0, iY0)") == 1 )
  {
    __debugbreak();
  }
  for ( i = 1; i <= 6; ++i )
  {
    v8 = v14 + CSpiralOffsets::DeltaX(i);
    v9 = v13 + CSpiralOffsets::DeltaY(i);
    v16 = CWorldManager::Index(v8, v9);
    if ( !CWorldManager::FlagBits(v16, 1u) )
    {
      v15 = CWorldManager::MapObjectId(v16);
      if ( v15 > 0 )
      {
        v17 = (unsigned __int8 *)CMapObjectMgr::Entity(v15);
        v7 = IEntity::WarriorType();
        v2 = IEntity::OwnerId(v17);
        v6 = CAlliances::AllianceId(v2);
        v5 = IEntity::Flags(v17);
        if ( v7 )
        {
          if ( v6 != v11 && (char *)(((unsigned int)&loc_301FFFE + 2) & v5) == &byte_201FFE1[31] )
          {
            v4 = ITiling::OwnerId(v16);
            v12 = CAlliances::AllianceId(v4);
            HIDWORD(v10) = v12 == 0;
            LODWORD(v10) = v12 == v11;
            if ( v10 )
              return v15;
          }
        }
      }
    }
  }
  return 0;
}


// address=[0x15953a0]
// Decompiled from int __cdecl CTowerSoldier::SearchBowmanTarget(int a1, int a2)
int __cdecl CTowerSoldier::SearchBowmanTarget(int a1, int a2) {
  
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  void *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp+0h] [ebp-6Ch]
  int v9; // [esp+4h] [ebp-68h]
  int v10; // [esp+8h] [ebp-64h]
  int v11; // [esp+Ch] [ebp-60h]
  int v12; // [esp+10h] [ebp-5Ch]
  int v13; // [esp+14h] [ebp-58h]
  int v14; // [esp+18h] [ebp-54h]
  __int64 v15; // [esp+1Ch] [ebp-50h]
  int v16; // [esp+24h] [ebp-48h]
  int v17; // [esp+28h] [ebp-44h]
  int v18; // [esp+2Ch] [ebp-40h]
  int v19; // [esp+30h] [ebp-3Ch]
  int v20; // [esp+34h] [ebp-38h]
  int v21; // [esp+38h] [ebp-34h]
  int v22; // [esp+3Ch] [ebp-30h]
  int v23; // [esp+40h] [ebp-2Ch]
  int v24; // [esp+44h] [ebp-28h]
  int v25; // [esp+48h] [ebp-24h]
  int v26; // [esp+4Ch] [ebp-20h]
  unsigned __int8 *v27; // [esp+50h] [ebp-1Ch]
  int v28; // [esp+54h] [ebp-18h]
  int v29; // [esp+58h] [ebp-14h]
  int v30; // [esp+5Ch] [ebp-10h]
  int j; // [esp+60h] [ebp-Ch]
  int NearestEntity; // [esp+64h] [ebp-8h]
  int i; // [esp+68h] [ebp-4h]

  v28 = Y16X16::UnpackXFast(a2);
  v29 = Y16X16::UnpackYFast(a2);
  if ( !CScanner::CheckIfAEnemyUnitMayBeInRange(v28, v29, 20, a1) )
    return 0;
  v25 = CAlliances::AllianceId(a1);
  v22 = Y16X16::UnpackXFast(a2);
  v23 = Y16X16::UnpackYFast(a2);
  v30 = -1;
  v20 = 20;
  for ( i = 1; i <= CPlayerManager::NumberOfPlayers(); ++i )
  {
    if ( CPlayerManager::Race(i) == 3 && CAlliances::AllianceId(i) != v25 )
    {
      NearestEntity = CFlyingMgr::GetNearestEntity((CFlyingMgr *)g_cFlyingMgr, i, 1, v22, v23, 0);
      if ( NearestEntity )
      {
        v3 = (_DWORD *)CFlyingMgr::operator[](NearestEntity);
        if ( (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(v3)) != 0 )
        {
          v4 = (_DWORD *)CFlyingMgr::operator[](NearestEntity);
          v13 = IEntity::X(v4);
          v5 = (void *)CFlyingMgr::operator[](NearestEntity);
          v14 = IEntity::Y(v5);
          v21 = Grid::Distance((Grid *)(v13 - v22), v14 - v23);
          if ( v21 < v20 )
          {
            v20 = v21;
            v30 = NearestEntity;
          }
        }
      }
    }
  }
  if ( v30 != -1 )
    return v30;
  v12 = CSpiralOffsets::First(1);
  v11 = CSpiralOffsets::Last(20);
  for ( j = v12; j <= v11; ++j )
  {
    v18 = v28 + CSpiralOffsets::DeltaX(j);
    v6 = CSpiralOffsets::DeltaY(j);
    v19 = v29 + v6;
    if ( (int)Grid::Distance((Grid *)(v18 - v28), v6) <= 20 )
    {
      v26 = CWorldManager::Index(v18, v19);
      if ( !CWorldManager::FlagBits(v26, 1u) )
      {
        v24 = CWorldManager::MapObjectId(v26);
        if ( v24 > 0 )
        {
          v27 = (unsigned __int8 *)CMapObjectMgr::Entity(v24);
          v10 = IEntity::WarriorType();
          v7 = IEntity::OwnerId(v27);
          v9 = CAlliances::AllianceId(v7);
          v17 = IEntity::Flags(v27);
          if ( v10 )
          {
            if ( v9 != v25
              && (char *)(((unsigned int)&loc_301FFFE + 2) & v17) == &byte_201FFE1[31]
              && (v17 & 0x8000000) == 0 )
            {
              v8 = ITiling::OwnerId(v26);
              v16 = CAlliances::AllianceId(v8);
              HIDWORD(v15) = v16 == 0;
              LODWORD(v15) = v16 == v25;
              if ( v15 )
                return v24;
            }
          }
        }
      }
    }
  }
  return 0;
}


// address=[0x15956a0]
// Decompiled from CTowerSoldier *__thiscall CTowerSoldier::CTowerSoldier(CTowerSoldier *this)
 CTowerSoldier::CTowerSoldier(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CTowerSoldier::_vftable_;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 45) = 0;
  *((_BYTE *)this + 46) = 0;
  *((_BYTE *)this + 47) = 0;
  *((_DWORD *)this + 12) = 0;
  return this;
}


// address=[0x15956f0]
// Decompiled from ISettlerRole *__thiscall CTowerSoldier::~CTowerSoldier(CTowerSoldier *this)
 CTowerSoldier::~CTowerSoldier(void) {
  
  *(_DWORD *)this = &CTowerSoldier::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x1595710]
// Decompiled from int __thiscall CTowerSoldier::GetNextJob(CTowerSoldier *this, struct CSettler *a2)
void  CTowerSoldier::GetNextJob(class CSettler * a2) {
  
  CTowerSoldier *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(v3);
  return (*(int (__thiscall **)(CTowerSoldier *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x1595750]
// Decompiled from int __thiscall CTowerSoldier::TakeJob(CTowerSoldier *this, struct CSettler *a2)
void  CTowerSoldier::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  int result; // eax
  char v4; // [esp+0h] [ebp-8h]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  v4 = *((_BYTE *)this + 4);
  if ( v4 == 16 )
  {
    if ( !*((_WORD *)this + 17)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\TowerSoldierRole.cpp", 230, "m_uEntityId > 0") == 1 )
    {
      __debugbreak();
    }
    if ( *((char *)this + 6) <= 0
      && BBSupportDbgReport(2, "MapObjects\\Settler\\TowerSoldierRole.cpp", 231, "m_iJobCounter > 0") == 1 )
    {
      __debugbreak();
    }
    return IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
  }
  else if ( v4 == 17 )
  {
    return IAnimatedEntity::RegisterForLogicUpdate(1);
  }
  else
  {
    result = BBSupportDbgReportF(
               1,
               "MapObjects\\Settler\\TowerSoldierRole.cpp",
               240,
               "CTowerSoldier::TakeJob(): Invalid task %i!",
               *((char *)this + 4));
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x1595830]
// Decompiled from CTowerSoldier *__thiscall CTowerSoldier::Init(CTowerSoldier *this, struct CSettler *a2)
void  CTowerSoldier::Init(class CSettler * a2) {
  
  CTowerSoldier *result; // eax

  if ( IEntity::FlagBits(a2, EntityFlag_Offered|EntityFlag_Attached)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\TowerSoldierRole.cpp",
         180,
         "!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED | ENTITY_FLAG_OFFERED )") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)this + 16)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\TowerSoldierRole.cpp", 181, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 9) = IEntity::ID();
  IMovingEntity::SetDisplacementCosts(10);
  *((_BYTE *)this + 44) = 0;
  result = this;
  *((_BYTE *)this + 45) = 0;
  *((_BYTE *)this + 46) = 0;
  return result;
}


// address=[0x15958d0]
// Decompiled from void __thiscall CTowerSoldier::SearchEnemy(CTowerSoldier *this, struct CSettler *a2)
void  CTowerSoldier::SearchEnemy(class CSettler * a2) {
  
  int v2; // eax

  v2 = IEntity::PackedXY(a2);
  if ( CTowerSoldier::GetAttacker(this, a2, v2) )
    (*(void (__thiscall **)(CTowerSoldier *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
  else
    CTowerSoldier::WorkIsDone(this, a2);
}


// address=[0x1595920]
// Decompiled from char __thiscall CTowerSoldier::GetAttacker(CTowerSoldier *this, struct CSettler *a2, int a3)
bool  CTowerSoldier::GetAttacker(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // esi
  int v7; // eax
  int v9; // [esp-Ch] [ebp-1Ch]
  int v10; // [esp-4h] [ebp-14h]
  int v11; // [esp-4h] [ebp-14h]
  int v12; // [esp-4h] [ebp-14h]
  int v13; // [esp+4h] [ebp-Ch]
  int NearestEnemyFighter; // [esp+Ch] [ebp-4h]

  v10 = IEntity::OwnerId((unsigned __int8 *)a2);
  v9 = Y16X16::UnpackYFast(a3);
  v3 = Y16X16::UnpackXFast(a3);
  NearestEnemyFighter = CScanner::FindNearestEnemyFighter(v3, v9, 3, v10);
  if ( NearestEnemyFighter == -1 )
    return 0;
  v11 = Y16X16::UnpackYFast(NearestEnemyFighter);
  v4 = Y16X16::UnpackXFast(NearestEnemyFighter);
  *((_WORD *)this + 17) = CWorldManager::SettlerId(v4, v11);
  v5 = Y16X16::UnpackYFast(NearestEnemyFighter);
  v12 = v5 - IEntity::Y(a2);
  v6 = Y16X16::UnpackXFast(NearestEnemyFighter);
  v7 = IEntity::X(a2);
  v13 = Grid::Direction((Grid *)(v6 - v7), v12);
  IMovingEntity::SetDirection(a2, v13);
  return 1;
}


// address=[0x15959e0]
// Decompiled from void __thiscall CTowerSoldier::WorkIsDone(CTowerSoldier *this, struct CSettler *a2)
void  CTowerSoldier::WorkIsDone(class CSettler * a2) {
  
  CBuilding *v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  *((_WORD *)this + 17) = 0;
  v3 = IEntity::ID();
  v2 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  CBuilding::SettlerEnter(v2, v3);
}


// address=[0x1595a20]
// Decompiled from void __thiscall CTowerSoldier::ConvertEventIntoGoal(int this, CPropertySet *a2, int a3)
void  CTowerSoldier::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int v15; // eax
  int v16; // [esp-8h] [ebp-28h]
  int v17; // [esp-8h] [ebp-28h]
  int v18; // [esp-8h] [ebp-28h]
  int v19; // [esp-8h] [ebp-28h]
  int v20; // [esp-8h] [ebp-28h]
  int v21; // [esp-8h] [ebp-28h]
  int v22; // [esp-4h] [ebp-24h]
  int v23; // [esp-4h] [ebp-24h]
  int v24; // [esp-4h] [ebp-24h]
  int v25; // [esp-4h] [ebp-24h]
  int v26; // [esp-4h] [ebp-24h]
  int v27; // [esp-4h] [ebp-24h]
  int v28; // [esp-4h] [ebp-24h]
  int v29; // [esp-4h] [ebp-24h]
  int v30; // [esp+4h] [ebp-1Ch]
  int v31; // [esp+8h] [ebp-18h]
  int v32; // [esp+10h] [ebp-10h]
  int v33; // [esp+14h] [ebp-Ch]

  switch ( *(_DWORD *)(a3 + 4) )
  {
    case 7:
    case 9:
      if ( !*(_WORD *)(this + 32)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\TowerSoldierRole.cpp", 575, "m_uHomeEntityId != 0") == 1 )
      {
        __debugbreak();
      }
      if ( *(_WORD *)(this + 32) )
      {
        IEntity::SetFlagBits(a2, EntityFlag_Selectable);
        IEntity::ClearFlagBits(a2, EntityFlag_OnBoard);
        v22 = IEntity::Type((unsigned __int16 *)a2);
        v16 = IEntity::Type((unsigned __int16 *)a2);
        v3 = IEntity::Race(a2);
        v4 = CEntityToDoListMgr::SettlerJobList(v3, v16);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v4, v22);
        v23 = *(unsigned __int16 *)(this + 32);
        v17 = IEntity::ID();
        v5 = IEntity::OwnerId((unsigned __int8 *)a2);
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          21,
          v5,
          v17,
          v23);
        *(_WORD *)(this + 32) = 0;
      }
      break;
    case 0xF:
      v33 = *(_DWORD *)(a3 + 16);
      if ( CTowerSoldier::GetAttacker((CTowerSoldier *)this, a2, v33) )
      {
        v26 = Y16X16::UnpackYFast(v33);
        v20 = Y16X16::UnpackXFast(v33);
        v8 = IEntity::ID();
        CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v8, v20, v26);
        CWarMap::AddEntity(a2);
        IEntity::ClearFlagBits(a2, (EntityFlag)0x800Fu);
        IEntity::SetFlagBits(a2, (EntityFlag)0x1010Du);
        v27 = IEntity::Type((unsigned __int16 *)a2);
        v9 = IEntity::Race(a2);
        CSettlerMgr::GetSettlerInfo(v9, v27);
        v28 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
        v21 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
        v10 = IEntity::Race(a2);
        v11 = CEntityToDoListMgr::SettlerJobList(v10, v21);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v11, v28);
        v12 = CSettlerMgr::operator[](*(unsigned __int16 *)(this + 34));
        v31 = IEntity::PackedXY(v12);
        v13 = Y16X16::UnpackYFast(v31);
        v29 = v13 - IEntity::Y(a2);
        v14 = Y16X16::UnpackXFast(v31);
        v15 = IEntity::X(a2);
        v30 = Grid::Direction((Grid *)(v14 - v15), v29);
        IMovingEntity::SetDirection(a2, v30);
      }
      break;
    case 0x19:
      v32 = *(_DWORD *)(a3 + 16);
      v24 = Y16X16::UnpackYFast(v32);
      v18 = Y16X16::UnpackXFast(v32);
      v6 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v6, v18, v24);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, EntityFlag_Selectable|EntityFlag_Visible);
      IEntity::ClearFlagBits(a2, EntityFlag_OnBoard);
      *(_BYTE *)(this + 4) = 27;
      v25 = *(unsigned __int16 *)(this + 32);
      v19 = IEntity::ID();
      v7 = IEntity::OwnerId((unsigned __int8 *)a2);
      (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 21, v7, v19, v25);
      *(_WORD *)(this + 32) = 0;
      break;
    default:
      if ( !IEntity::FlagBits(a2, EntityFlag_Registered) )
      {
        CTrace::Print("ConvertEventIntoGoal SoldierRole - unknown event %u", *(_DWORD *)(a3 + 4));
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
  }
}


