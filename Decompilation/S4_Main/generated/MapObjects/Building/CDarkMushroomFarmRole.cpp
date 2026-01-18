#include "CDarkMushroomFarmRole.h"

// Definitions for class CDarkMushroomFarmRole

// address=[0x1400220]
// Decompiled from int __cdecl CDarkMushroomFarmRole::New(int a1)
class CPersistence * __cdecl CDarkMushroomFarmRole::New(std::istream & a1) {
  
  if ( operator new(0x19Cu) )
    return CDarkMushroomFarmRole::CDarkMushroomFarmRole(a1);
  else
    return 0;
}


// address=[0x141da00]
// Decompiled from unsigned int __thiscall CDarkMushroomFarmRole::NumberOfAssociatedServants(CMFCVisualManagerOffice2003 *this)
int  CDarkMushroomFarmRole::NumberOfAssociatedServants(void)const {
  
  return *((_DWORD *)this + 99);
}


// address=[0x14fc940]
// Decompiled from CDarkMushroomFarmRole *__thiscall CDarkMushroomFarmRole::CDarkMushroomFarmRole(CDarkMushroomFarmRole *this)
 CDarkMushroomFarmRole::CDarkMushroomFarmRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CDarkMushroomFarmRole::_vftable_;
  return this;
}


// address=[0x14fcbd0]
// Decompiled from int __thiscall CDarkMushroomFarmRole::~CDarkMushroomFarmRole(CDarkMushroomFarmRole *this)
 CDarkMushroomFarmRole::~CDarkMushroomFarmRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd080]
// Decompiled from int __thiscall CDarkMushroomFarmRole::ClassID(CDarkMushroomFarmRole *this)
unsigned long  CDarkMushroomFarmRole::ClassID(void)const {
  
  return CDarkMushroomFarmRole::m_iClassID;
}


// address=[0x14fd320]
// Decompiled from void *__thiscall CDarkMushroomFarmRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CDarkMushroomFarmRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x14fd460]
// Decompiled from int __thiscall CDarkMushroomFarmRole::GetBuildingRole(CDarkMushroomFarmRole *this)
int  CDarkMushroomFarmRole::GetBuildingRole(void) {
  
  return 20;
}


// address=[0x14fd5c0]
// Decompiled from void *__thiscall CDarkMushroomFarmRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)
int  CDarkMushroomFarmRole::GetPileIdWithGood(int a2)const {
  
  return 0;
}


// address=[0x14fd6e0]
// Decompiled from void __thiscall CDarkMushroomFarmRole::GoodArrive(CDarkMushroomFarmRole *this, int a2)
void  CDarkMushroomFarmRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x14fd930]
// Decompiled from int __cdecl CDarkMushroomFarmRole::Load(int a1)
class CDarkMushroomFarmRole * __cdecl CDarkMushroomFarmRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CDarkMushroomFarmRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1506a60]
// Decompiled from int __thiscall CDarkMushroomFarmRole::LogicUpdate(unsigned int *this, CMFCToolBarButton *a2)
void  CDarkMushroomFarmRole::LogicUpdate(class CBuilding * a2) {
  
  int result; // eax
  unsigned int v3; // eax
  int BuildingJobFrameCount; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // [esp-4h] [ebp-1Ch]
  unsigned int v9; // [esp-4h] [ebp-1Ch]
  unsigned int v10; // [esp-4h] [ebp-1Ch]
  int v11; // [esp+0h] [ebp-18h]
  int TickCounter; // [esp+4h] [ebp-14h]
  int v13; // [esp+8h] [ebp-10h]
  unsigned __int8 v15; // [esp+16h] [ebp-2h]
  bool IsDoorNeighborAndEnsignPosGreen; // [esp+17h] [ebp-1h]

  if ( IEntity::FlagBits(a2, EntityFlag_Selected) )
    (*(void (__thiscall **)(unsigned int *, CMFCToolBarButton *, int))(*this + 88))(this, a2, 1);
  switch ( *((_BYTE *)this + 4) )
  {
    case 1:
      if ( CDarkMushroomFarmRole::IsDoorNeighborAndEnsignPosGreen((CDarkMushroomFarmRole *)this, a2)
        || (v7 = IEntity::ID(), (**(int (__thiscall ***)(void *, int))g_pDarkTribe)(g_pDarkTribe, v7) <= 0) )
      {
        result = IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      else
      {
        *((_BYTE *)this + 4) = 3;
        result = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
    case 3:
      TickCounter = CStateGame::GetTickCounter(g_pGame);
      CDarkMushroomFarmRole::TellServantsToWork((CDarkMushroomFarmRole *)this, a2);
      if ( !*((_BYTE *)this + 29) )
        goto LABEL_31;
      IsDoorNeighborAndEnsignPosGreen = 0;
      v15 = 0;
      if ( (int)this[98] < (int)this[95] )
      {
        if ( !(unsigned __int8)CDarkMushroomFarmRole::PlantMushroom(a2) )
          IsDoorNeighborAndEnsignPosGreen = CDarkMushroomFarmRole::IsDoorNeighborAndEnsignPosGreen(
                                              (CDarkMushroomFarmRole *)this,
                                              a2);
      }
      else
      {
        this[98] = 0;
        IsDoorNeighborAndEnsignPosGreen = 1;
        v15 = 1;
      }
      if ( IsDoorNeighborAndEnsignPosGreen )
      {
        v13 = *((unsigned __int16 *)this + 4);
        v11 = CSettlerMgr::operator[](v13);
        CSettler::SetFree(v11);
        (*(void (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)g_pDarkTribe + 4))(g_pDarkTribe, v13, v15);
        *((_BYTE *)this + 4) = 1;
        *((_WORD *)this + 4) = 0;
        *((_BYTE *)this + 29) = 0;
        result = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      else
      {
LABEL_31:
        if ( this[98] == this[95]
          || (int)(this[101] + 280) >= TickCounter
          || !CDarkMushroomFarmRole::HarvestMushroom((CDarkMushroomFarmRole *)this, a2) )
        {
          result = IAnimatedEntity::RegisterForLogicUpdate(1);
        }
        else
        {
          this[101] = TickCounter;
          *((_BYTE *)this + 4) = 4;
          *((_BYTE *)this + 156) = 1;
          v10 = this[40];
          v6 = IEntity::Race(a2);
          *((_BYTE *)this + 164) = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v6, v10);
          *((_BYTE *)this + 157) = 0;
          *((_BYTE *)this + 159) = 0;
          *((_BYTE *)this + 165) = 0;
          this[20] = 0;
          result = IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 164));
        }
      }
      break;
    case 4:
      if ( *((_BYTE *)this + 29) )
        CDarkMushroomFarmRole::PlantMushroom(a2);
      if ( CStateGame::GetTickCounter(g_pGame) >= this[102] )
      {
        CDarkMushroomFarmRole::TellServantsToWork((CDarkMushroomFarmRole *)this, a2);
        *((_BYTE *)this + 4) = 5;
        *((_BYTE *)this + 156) = 0;
        *((_BYTE *)this + 176) = 1;
        v9 = this[45];
        v5 = IEntity::Race(a2);
        *((_BYTE *)this + 184) = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v5, v9);
        *((_BYTE *)this + 177) = 0;
        *((_BYTE *)this + 179) = 0;
        *((_BYTE *)this + 185) = 0;
        this[22] = 0;
        result = IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 184) - 1);
      }
      else
      {
        v8 = this[40];
        v3 = IEntity::Race(a2);
        BuildingJobFrameCount = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v3, v8);
        result = IAnimatedEntity::RegisterForLogicUpdate(BuildingJobFrameCount);
      }
      break;
    case 5:
      if ( *((_BYTE *)this + 29) )
        CDarkMushroomFarmRole::PlantMushroom(a2);
      CDarkMushroomFarmRole::TellServantsToWork((CDarkMushroomFarmRole *)this, a2);
      ++this[98];
      *((_BYTE *)this + 176) = 0;
      *((_BYTE *)this + 4) = 3;
      result = IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    default:
      result = CTrace::Print("Unknown update for DarkMushroomFarm Logicupdate!");
      break;
  }
  return result;
}


// address=[0x1506f00]
// Decompiled from int __thiscall CDarkMushroomFarmRole::FillGfxInfo(  CDarkMushroomFarmRole *this,  struct CBuilding *a2,  struct SGfxObjectInfo *a3)
void  CDarkMushroomFarmRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-14h]

  *((_BYTE *)this + 165) = 3;
  *((_BYTE *)this + 185) = 3;
  *((_BYTE *)this + 205) = 3;
  (*(void (__thiscall **)(CDarkMushroomFarmRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  if ( *((_DWORD *)this + 98) )
  {
    *((_DWORD *)this + 23) = *((_DWORD *)this + 50);
    *((_DWORD *)this + 24) = *((_DWORD *)this + 98) - 1;
  }
  else
  {
    *((_DWORD *)this + 23) = 0;
  }
  v5 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  return CGfxManager::GetBuildingGfxInfo((int)a3, v3, v5, 1, (int)this + 76);
}


// address=[0x1506fe0]
// Decompiled from int __thiscall CDarkMushroomFarmRole::Init(CDarkMushroomFarmRole *this, struct CBuilding *a2)
void  CDarkMushroomFarmRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  unsigned int v3; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]
  unsigned int v7; // [esp-4h] [ebp-8h]

  v6 = IEntity::Y(a2);
  v5 = IEntity::X(a2);
  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  BBSupportTracePrintF(
    0,
    "CDarkMushroomFarmRole::Init(): tick %u, owner %u, position (%i, %i)",
    g_uDbgTickCounter,
    v2,
    v5,
    v6);
  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 4) = 1;
  v7 = *((_DWORD *)this + 50);
  v3 = IEntity::Race(a2);
  *((_DWORD *)this + 95) = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v3, v7);
  *((_DWORD *)this + 96) = 0;
  *((_DWORD *)this + 97) = 0;
  *((_DWORD *)this + 98) = 0;
  *((_DWORD *)this + 99) = 0;
  *((_DWORD *)this + 100) = 0;
  *((_DWORD *)this + 101) = 0;
  *((_DWORD *)this + 102) = 0;
  return IAnimatedEntity::RegisterForLogicUpdate(1);
}


// address=[0x15070d0]
// Decompiled from unsigned int __thiscall CDarkMushroomFarmRole::PostLoadInit(CDarkMushroomFarmRole *this, struct CBuilding *a2)
void  CDarkMushroomFarmRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  unsigned int v3; // eax
  unsigned int result; // eax
  int v5; // [esp-4h] [ebp-8h]
  unsigned int v6; // [esp-4h] [ebp-8h]

  v5 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v5);
  v6 = *((_DWORD *)this + 50);
  v3 = IEntity::Race(a2);
  result = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v3, v6);
  *((_DWORD *)this + 95) = result;
  return result;
}


// address=[0x1507130]
// Decompiled from char __thiscall CDarkMushroomFarmRole::SettlerEnter(CDarkMushroomFarmRole *this, struct CBuilding *a2, int a3)
bool  CDarkMushroomFarmRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  _DWORD *v4; // [esp+0h] [ebp-8h]

  *((_WORD *)this + 4) = a3;
  v4 = (_DWORD *)CSettlerMgr::operator[](a3);
  IEntity::ClearFlagBits(v4, EntityFlag_Visible);
  *((_BYTE *)this + 29) = 1;
  return 0;
}


// address=[0x1507180]
// Decompiled from void __thiscall CDarkMushroomFarmRole::FillDialog(CDarkMushroomFarmRole *this, struct CBuilding *a2, bool a3)
void  CDarkMushroomFarmRole::FillDialog(class CBuilding * a2, bool a3) {
  
  ;
}


// address=[0x1507190]
// Decompiled from char __thiscall CDarkMushroomFarmRole::HarvestMushroom(CDarkMushroomFarmRole *this, struct CBuilding *a2)
bool  CDarkMushroomFarmRole::HarvestMushroom(class CBuilding * a2) {
  
  int WorkingAreaPackedXY; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v8; // [esp-8h] [ebp-38h]
  int v9; // [esp-8h] [ebp-38h]
  int v10; // [esp+8h] [ebp-28h]
  int v11; // [esp+Ch] [ebp-24h]
  int v12; // [esp+10h] [ebp-20h]
  int v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+18h] [ebp-18h]
  int (__cdecl *v15)(int, int, _DWORD); // [esp+1Ch] [ebp-14h]
  int v16; // [esp+20h] [ebp-10h]
  int v17; // [esp+24h] [ebp-Ch]
  int v18; // [esp+28h] [ebp-8h]

  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(a2);
  v11 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
  v3 = CBuilding::GetWorkingAreaPackedXY(a2);
  v10 = Y16X16::UnpackYFast(v3);
  v16 = 0;
  v12 = *((_DWORD *)this + 99) + 1;
  v13 = *((_DWORD *)this + 96);
  v17 = 0;
  v18 = 0;
  v8 = *(char *)(*((_DWORD *)this + 94) + 478);
  v4 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v4, v8);
  v15 = *(int (__cdecl **)(int, int, _DWORD))std::vector<CSettlerMgr::SSearchInfos>::operator[](0);
  if ( v15 )
  {
    while ( *((_DWORD *)this + 96) < v12 + v13 )
    {
      v17 = v11 + CSpiralOffsets::DeltaX(*((_DWORD *)this + 96));
      v18 = v10 + CSpiralOffsets::DeltaY(*((_DWORD *)this + 96));
      if ( (unsigned __int8)CWorldManager::InWorld(v17, v18) )
      {
        v16 = v15(v17, v18, 0);
        if ( v16 )
        {
          ++*((_DWORD *)this + 96);
          if ( *((_DWORD *)this + 96) > CSpiralOffsets::Last(*(_DWORD *)(*((_DWORD *)this + 94) + 492)) )
            *((_DWORD *)this + 96) = 0;
          break;
        }
      }
      ++*((_DWORD *)this + 96);
      if ( *((_DWORD *)this + 96) > CSpiralOffsets::Last(*(_DWORD *)(*((_DWORD *)this + 94) + 492)) )
      {
        *((_DWORD *)this + 96) = 0;
        break;
      }
    }
  }
  if ( !v16 )
    return 0;
  v14 = CLogic::Effects((DWORD *)g_pLogic);
  v9 = IEntity::PackedXY(a2);
  v5 = Y16X16::PackXYFast(v17, v18);
  v6 = (*(int (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v14 + 28))(v14, v5, v9, 0);
  *((_DWORD *)this + 102) = v6 + CStateGame::GetTickCounter(g_pGame);
  return 1;
}


// address=[0x15073a0]
// Decompiled from char __thiscall CDarkMushroomFarmRole::PlantMushroom(_DWORD *this, CMFCToolBarButton *a2)
bool  CDarkMushroomFarmRole::PlantMushroom(class CBuilding * a2) {
  
  int WorkingAreaPackedXY; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // esi
  int v9; // eax
  struct CPaneContainer *v10; // eax
  int v11; // eax
  int v13; // [esp-8h] [ebp-7Ch]
  int v14; // [esp-4h] [ebp-78h]
  char v15; // [esp-4h] [ebp-78h]
  int v16; // [esp-4h] [ebp-78h]
  _BYTE v17[24]; // [esp+8h] [ebp-6Ch] BYREF
  int v18; // [esp+20h] [ebp-54h]
  CEntityEvent *v19; // [esp+24h] [ebp-50h]
  CEntityEvent *v20; // [esp+28h] [ebp-4Ch]
  int v21; // [esp+2Ch] [ebp-48h]
  int v22; // [esp+30h] [ebp-44h]
  int v23; // [esp+34h] [ebp-40h]
  unsigned int ObjectType; // [esp+38h] [ebp-3Ch]
  int v25; // [esp+3Ch] [ebp-38h]
  int v26; // [esp+40h] [ebp-34h]
  int (__cdecl *v27)(int, int, _DWORD); // [esp+44h] [ebp-30h]
  int v28; // [esp+48h] [ebp-2Ch]
  int v29; // [esp+4Ch] [ebp-28h]
  int v30; // [esp+50h] [ebp-24h]
  int v31; // [esp+54h] [ebp-20h]
  CPaneContainer *v32; // [esp+58h] [ebp-1Ch]
  int SettlerInfo; // [esp+5Ch] [ebp-18h]
  _DWORD *v34; // [esp+60h] [ebp-14h]
  char v35; // [esp+67h] [ebp-Dh]
  int v36; // [esp+70h] [ebp-4h]

  v34 = this;
  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(a2);
  v28 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
  v3 = CBuilding::GetWorkingAreaPackedXY(a2);
  v29 = Y16X16::UnpackYFast(v3);
  v18 = 0;
  v21 = 10;
  v35 = 0;
  v22 = v34[97];
  v32 = (CPaneContainer *)CSettlerMgr::operator[](*((unsigned __int16 *)v34 + 4));
  v14 = IEntity::Type((unsigned __int16 *)v32);
  v4 = IEntity::Race(v32);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v4, v14);
  v27 = *(int (__cdecl **)(int, int, _DWORD))std::vector<CSettlerMgr::SSearchInfos>::operator[](1);
  if ( v27 )
  {
    while ( v34[97] < v21 + v22 )
    {
      if ( (unsigned int)CGameData::Rand(g_pGameData) >= 0x4000 )
      {
        v30 = v28 + CSpiralOffsets::DeltaX(v34[97]);
        v31 = v29 + CSpiralOffsets::DeltaY(v34[97]);
        if ( (unsigned __int8)CWorldManager::InWorld(v30, v31) )
        {
          v5 = CWorldManager::SectorId(v28, v29);
          if ( v5 == CWorldManager::SectorId(v30, v31) )
          {
            v13 = v31 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 6);
            v6 = std::vector<CSettlerMgr::SSearchInfos>::operator[](1);
            if ( v27(v30 - *(char *)(v6 + 5), v13, 0) )
            {
              v35 = 1;
              ++v34[97];
              if ( v34[97] > CSpiralOffsets::Last(*(_DWORD *)(v34[94] + 492)) )
                v34[97] = 0;
              break;
            }
          }
        }
        ++v34[97];
        if ( v34[97] > CSpiralOffsets::Last(*(_DWORD *)(v34[94] + 492)) )
        {
          v34[97] = 0;
          break;
        }
      }
    }
  }
  if ( !v35 )
    return 0;
  v34[4] = Y16X16::PackXYFast(v30, v31);
  v7 = Y16X16::UnpackXFast(v34[4]);
  v25 = v7 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 5);
  v8 = Y16X16::UnpackYFast(v34[4]);
  v26 = v8 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 6);
  v15 = CWorldManager::Ground(v25, v26);
  v9 = IEntity::Race(v32);
  ObjectType = CDecoObjMgr::GetObjectType((CDecoObjMgr *)&g_cDecoObjMgr, *(unsigned __int8 *)(SettlerInfo + 6), v9, v15);
  CDecoObjMgr::SetFlagsForObject((CDecoObjMgr *)&g_cDecoObjMgr, v25, v26, ObjectType, 0);
  v10 = (struct CPaneContainer *)CBuilding::DoorPackedXY(a2);
  IEntity::SetPosition(v32, v10);
  v16 = *((unsigned __int16 *)v34 + 4);
  v11 = CBuilding::DoorWorldIdx(a2);
  CWorldManager::SetSettlerId(v11, v16);
  IEntity::SetFlagBits(v32, EntityFlag_Visible);
  v23 = CSettlerMgr::operator[](*((unsigned __int16 *)v34 + 4));
  v20 = CEntityEvent::CEntityEvent((CEntityEvent *)v17, 6u, 0, 0, ObjectType, v34[4]);
  v19 = v20;
  v36 = 0;
  (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v23 + 80))(v23, v20);
  v36 = -1;
  CEntityEvent::~CEntityEvent(v17);
  *((_BYTE *)v34 + 29) = 0;
  return 1;
}


// address=[0x1507740]
// Decompiled from CDarkMushroomFarmRole *__thiscall CDarkMushroomFarmRole::AttachServant(  CDarkMushroomFarmRole *this,  struct CBuilding *a2,  int a3)
void  CDarkMushroomFarmRole::AttachServant(class CBuilding * a2, int a3) {
  
  CDarkMushroomFarmRole *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkMushroomFarm.cpp", 633, "_pBuilding != 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkMushroomFarm.cpp", 634, "_iServantId > 0") == 1 )
    __debugbreak();
  (*(void (__thiscall **)(struct CBuilding *, int))(*(_DWORD *)a2 + 116))(a2, a3);
  result = this;
  ++*((_DWORD *)this + 99);
  return result;
}


// address=[0x15077c0]
// Decompiled from int __thiscall CDarkMushroomFarmRole::DetachServant(_DWORD *this, int a2, int a3)
void  CDarkMushroomFarmRole::DetachServant(class CBuilding * a2, int a3) {
  
  int result; // eax

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkMushroomFarm.cpp", 648, "_pBuilding != 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkMushroomFarm.cpp", 649, "_iServantId > 0") == 1 )
    __debugbreak();
  (*(void (__thiscall **)(int, int))(*(_DWORD *)a2 + 64))(a2, a3);
  if ( (int)this[99] <= 0 )
  {
    result = BBSupportDbgReport(
               1,
               "MapObjects\\Building\\DarkMushroomFarm.cpp",
               659,
               "CDarkMushroomFarmRole::DetachServant(): Invalid NumberOfAssociatedServants!");
    if ( result == 1 )
      __debugbreak();
  }
  else
  {
    result = this[99] - 1;
    this[99] = result;
  }
  return result;
}


// address=[0x1507870]
// Decompiled from int __thiscall CDarkMushroomFarmRole::TellServantsToWork(CDarkMushroomFarmRole *this, struct CBuilding *a2)
void  CDarkMushroomFarmRole::TellServantsToWork(class CBuilding * a2) {
  
  int result; // eax
  CNotifyExceptMushroomfarmer *v3; // [esp-4h] [ebp-3Ch]
  _BYTE v4[24]; // [esp+4h] [ebp-34h] BYREF
  CEntityEvent *v5; // [esp+1Ch] [ebp-1Ch]
  CEntityEvent *v6; // [esp+20h] [ebp-18h]
  int v7; // [esp+24h] [ebp-14h] BYREF
  CDarkMushroomFarmRole *v8; // [esp+28h] [ebp-10h]
  int v9; // [esp+34h] [ebp-4h]

  v8 = this;
  ++*((_DWORD *)this + 100);
  result = (int)v8;
  if ( *((int *)v8 + 100) <= 7 )
    return result;
  *((_DWORD *)v8 + 100) = 0;
  v7 = 0;
  v3 = CNotifyExceptMushroomfarmer::CNotifyExceptMushroomfarmer((CNotifyExceptMushroomfarmer *)&v7);
  v6 = CEntityEvent::CEntityEvent((CEntityEvent *)v4, 5u, 0, 0, 0, 0);
  v5 = v6;
  v9 = 0;
  (*(void (__thiscall **)(struct CBuilding *, CEntityEvent *, CNotifyExceptMushroomfarmer *))(*(_DWORD *)a2 + 120))(
    a2,
    v6,
    v3);
  v9 = -1;
  return CEntityEvent::~CEntityEvent(v4);
}


// address=[0x1507a20]
// Decompiled from char *__thiscall CDarkMushroomFarmRole::CDarkMushroomFarmRole(char *this, int a2)
 CDarkMushroomFarmRole::CDarkMushroomFarmRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CDarkMushroomFarmRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDarkMushroomFarmRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v5 + 384));
  operator^<int>(a2, (int)(v5 + 388));
  operator^<int>(a2, (int)(v5 + 392));
  operator^<int>(a2, (int)(v5 + 396));
  operator^<int>(a2, (int)(v5 + 400));
  operator^<int>(a2, (int)(v5 + 404));
  operator^<int>(a2, (int)(v5 + 408));
  v6 = -1;
  return v5;
}


// address=[0x1507b70]
// Decompiled from int __thiscall CDarkMushroomFarmRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CDarkMushroomFarmRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = (int *)this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<int>((int)a2, v4 + 96);
  operator^<int>((int)a2, v4 + 97);
  operator^<int>((int)a2, v4 + 98);
  operator^<int>((int)a2, v4 + 99);
  operator^<int>((int)a2, v4 + 100);
  operator^<int>((int)a2, v4 + 101);
  return operator^<int>((int)a2, v4 + 102);
}


// address=[0x158e490]
// Decompiled from int __thiscall CDarkMushroomFarmRole::GetBuildingInfo(CPane *this)
struct CBuildingInfoMgr::SBuildingInfos const *  CDarkMushroomFarmRole::GetBuildingInfo(void) {
  
  return *((_DWORD *)this + 94);
}


// address=[0x3d8b124]
// [Decompilation failed for static unsigned long CDarkMushroomFarmRole::m_iClassID]

// address=[0x1507930]
// Decompiled from bool __thiscall CDarkMushroomFarmRole::IsDoorNeighborAndEnsignPosGreen(  CDarkMushroomFarmRole *this,  struct CBuilding *a2)
bool  CDarkMushroomFarmRole::IsDoorNeighborAndEnsignPosGreen(class CBuilding * a2) {
  
  int v3; // eax
  int v4; // eax
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkMushroomFarm.cpp", 196, "_pBuilding != 0") == 1 )
    __debugbreak();
  v6 = CBuilding::DoorWorldIdx(a2);
  for ( i = 0; i < 6; ++i )
  {
    v5 = v6 + CWorldManager::NeighborRelIndex(i);
    if ( CWorldManager::FlagBits(v5, 5u) == 4 )
      return 0;
  }
  v3 = CBuilding::EnsignWorldIdx(a2);
  if ( CWorldManager::FlagBits(v3, 1u) )
  {
    if ( BBSupportDbgReport(
           2,
           "MapObjects\\Building\\DarkMushroomFarm.cpp",
           210,
           "g_cWorld.FlagBits(_pBuilding->EnsignWorldIdx(), FLAG_BLOCKED_LAND) == 0") == 1 )
      __debugbreak();
  }
  v4 = CBuilding::EnsignWorldIdx(a2);
  return CWorldManager::FlagBits(v4, 4u) == 0;
}


// address=[0x14fd1e0]
// Decompiled from void __thiscall CDarkMushroomFarmRole::ConvertEventIntoGoal(  CDarkMushroomFarmRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CDarkMushroomFarmRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
  ;
}


// address=[0x14fde10]
// Decompiled from char __thiscall CDarkMushroomFarmRole::TryCrushBuilding(CDarkMushroomFarmRole *this)
bool  CDarkMushroomFarmRole::TryCrushBuilding(void) {
  
  return 1;
}


// address=[0x1507c40]
// Decompiled from char __thiscall CDarkMushroomFarmRole::CrushBuilding(CDarkMushroomFarmRole *this)
bool  CDarkMushroomFarmRole::CrushBuilding(void) {
  
  CPlayerGameData *v1; // eax
  CPlayerStatisticData *v2; // eax
  int v4; // [esp+8h] [ebp-4h]

  CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v4 = IAnimatedEntity::AttackerPlayerId();
  if ( v4 <= 0 )
    return 1;
  v1 = CPlayerManager::PlayerGameData(v4);
  v2 = CPlayerGameData::StaticData(v1);
  CPlayerStatisticData::IncreaseMushroomFarmsDestroyed(v2);
  return 1;
}


