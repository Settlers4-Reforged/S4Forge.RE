#include "CResidenceBuildingRole.h"

// Definitions for class CResidenceBuildingRole

// address=[0x1401940]
// Decompiled from int __cdecl CResidenceBuildingRole::New(int a1)

static class CPersistence * __cdecl CResidenceBuildingRole::New(std::istream &) {
  
  if ( operator new(0x180u) )
    return CResidenceBuildingRole::CResidenceBuildingRole(a1);
  else
    return 0;
}


// address=[0x14fcae0]
// Decompiled from CResidenceBuildingRole *__thiscall CResidenceBuildingRole::CResidenceBuildingRole(CResidenceBuildingRole *this)

 CResidenceBuildingRole::CResidenceBuildingRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CResidenceBuildingRole::_vftable_;
  return this;
}


// address=[0x14fcd00]
// Decompiled from int __thiscall CResidenceBuildingRole::~CResidenceBuildingRole(CResidenceBuildingRole *this)

 CResidenceBuildingRole::~CResidenceBuildingRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd160]
// Decompiled from int __thiscall CResidenceBuildingRole::ClassID(CResidenceBuildingRole *this)

unsigned long  CResidenceBuildingRole::ClassID(void)const {
  
  return CResidenceBuildingRole::m_iClassID;
}


// address=[0x14fd3e0]
// Decompiled from void *__thiscall CResidenceBuildingRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)

int  CResidenceBuildingRole::GetBuildingNeed(int)const {
  
  return 0;
}


// address=[0x14fd540]
// Decompiled from int __thiscall CResidenceBuildingRole::GetBuildingRole(CResidenceBuildingRole *this)

int  CResidenceBuildingRole::GetBuildingRole(void) {
  
  return 14;
}


// address=[0x14fd680]
// Decompiled from void *__thiscall CResidenceBuildingRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)

int  CResidenceBuildingRole::GetPileIdWithGood(int)const {
  
  return 0;
}


// address=[0x14fd740]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CResidenceBuildingRole::GoodArrive(CResidenceBuildingRole *this, int a2)

void  CResidenceBuildingRole::GoodArrive(int) {
  
  ;
}


// address=[0x14fdbb0]
// Decompiled from int __cdecl CResidenceBuildingRole::Load(int a1)

static class CResidenceBuildingRole * __cdecl CResidenceBuildingRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CResidenceBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1518780]
// Decompiled from char __thiscall CResidenceBuildingRole::LogicUpdate(CResidenceBuildingRole *this, struct CBuilding *a2)

void  CResidenceBuildingRole::LogicUpdate(class CBuilding *) {
  
  int LocalPlayerId; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // esi
  int v10; // eax
  void *v11; // eax
  int v12; // eax
  const char *BuildingName; // eax
  int v15; // [esp-8h] [ebp-34h]
  int v16; // [esp-8h] [ebp-34h]
  const char *v17; // [esp-8h] [ebp-34h]
  const char *RaceName; // [esp-4h] [ebp-30h]
  int v19; // [esp+8h] [ebp-24h]
  int v20; // [esp+Ch] [ebp-20h]
  char v21; // [esp+10h] [ebp-1Ch]
  int v22; // [esp+14h] [ebp-18h] BYREF
  int v23; // [esp+18h] [ebp-14h] BYREF
  int v24; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  _DWORD *v26; // [esp+24h] [ebp-8h]
  unsigned __int8 v27; // [esp+2Bh] [ebp-1h]

  v26 = this;
  LocalPlayerId = IEntity::FlagBits(a2, Selected);
  if ( LocalPlayerId )
    LOBYTE(LocalPlayerId) = (*(int (__thiscall **)(_DWORD *, struct CBuilding *, int))(*v26 + 88))(v26, a2, 1);
  v21 = *((_BYTE *)v26 + 4);
  if ( v21 != 2 )
  {
    if ( v21 != 3 )
      return LocalPlayerId;
    LocalPlayerId = v26[94];
    if ( *((unsigned __int8 *)v26 + 380) >= *(int *)(LocalPlayerId + 496) )
      return LocalPlayerId;
    v22 = CBuilding::DoorX(a2);
    v23 = CBuilding::DoorY(a2);
    v19 = CWorldManager::EcoSectorId(v22, v23);
    if ( !v19 && BBSupportDbgReport(2, "MapObjects\\Building\\ResidenceBuilding.cpp", 197, "iEcoSectorId != 0") == 1 )
      __debugbreak();
    v24 = 0;
    for ( i = 1; i < 67; ++i )
    {
      v3 = IEntity::OwnerId((unsigned __int8 *)a2);
      v24 += CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, v3, i);
    }
    if ( CPlayerManager::NumberOfPlayers() > 4 )
      v20 = 10000 / CPlayerManager::NumberOfPlayers();
    else
      v20 = 2500;
    if ( v24 < v20 )
    {
      if ( CSettlerMgr::SearchFreePositionInEcoSector((CSettlerMgr *)g_cSettlerMgr, &v22, &v23, v19) )
      {
        v15 = *(char *)(v26[94] + 478);
        v4 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( (int)CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v22, v23, v4, v15, 0) > 0 )
        {
          v5 = IEntity::OwnerId((unsigned __int8 *)a2);
          CStatistic::AddProducedSettler((CStatistic *)&g_cStatistic, v5, 1);
          v27 = *((_BYTE *)v26 + 380) + 1;
          *((_BYTE *)v26 + 380) = v27;
          if ( v27 >= *(int *)(v26[94] + 496) )
          {
            v16 = IEntity::ID();
            v6 = IEntity::OwnerId((unsigned __int8 *)a2);
            (*(void (__thiscall **)(void *, int, int, int, _DWORD))(*(_DWORD *)off_3D7A3D8 + 44))(
              off_3D7A3D8,
              8,
              v6,
              v16,
              0);
            v7 = IEntity::ID();
            BBSupportTracePrintF(0, "Residence: last settler left the buiding %u", v7);
            LOBYTE(LocalPlayerId) = IEntity::IsSelected((IEntity *)a2);
            if ( !(_BYTE)LocalPlayerId )
              return LocalPlayerId;
            v8 = IEntity::OwnerId((unsigned __int8 *)a2);
            LocalPlayerId = CPlayerManager::GetLocalPlayerId();
            if ( v8 == LocalPlayerId )
              LOBYTE(LocalPlayerId) = (*(int (__thiscall **)(_DWORD *, struct CBuilding *, int))(*v26 + 88))(v26, a2, 1);
            return LocalPlayerId;
          }
          if ( IEntity::IsSelected((IEntity *)a2) )
          {
            v9 = IEntity::OwnerId((unsigned __int8 *)a2);
            if ( v9 == CPlayerManager::GetLocalPlayerId() )
              (*(void (__thiscall **)(_DWORD *, struct CBuilding *, int))(*v26 + 88))(v26, a2, 1);
          }
        }
      }
    }
    if ( *(_BYTE *)(v26[94] + 480) )
    {
      *((_BYTE *)v26 + 5) = 0;
      LOBYTE(LocalPlayerId) = IAnimatedEntity::RegisterForLogicUpdate(14);
      *((_BYTE *)v26 + 4) = 2;
    }
    else
    {
      IAnimatedEntity::RegisterForLogicUpdate(31);
      v10 = IEntity::Race(a2);
      RaceName = CS4DefineNames::GetRaceName(v10);
      v11 = (void *)j____RTtypeid(v26);
      v17 = (const char *)type_info::name(v11);
      v12 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
      BuildingName = CS4DefineNames::GetBuildingName(v12);
      LOBYTE(LocalPlayerId) = BBSupportTracePrintF(
                                2,
                                "WARNING: Building %s (role %s) of race %s has no production delay!",
                                BuildingName,
                                v17,
                                RaceName);
    }
    return LocalPlayerId;
  }
  if ( *((unsigned __int8 *)v26 + 5) > (int)*(unsigned __int8 *)(v26[94] + 480) )
  {
    LocalPlayerId = v26[94];
    if ( *((unsigned __int8 *)v26 + 380) < *(int *)(LocalPlayerId + 496) )
    {
      *((_BYTE *)v26 + 5) = 0;
      *((_BYTE *)v26 + 4) = 3;
      LOBYTE(LocalPlayerId) = IAnimatedEntity::RegisterForLogicUpdate(1);
    }
  }
  else
  {
    ++*((_BYTE *)v26 + 5);
    LOBYTE(LocalPlayerId) = IAnimatedEntity::RegisterForLogicUpdate(14);
  }
  return LocalPlayerId;
}


// address=[0x1518af0]
// Decompiled from int __thiscall CResidenceBuildingRole::FillGfxInfo(
        CResidenceBuildingRole *this,
        struct CBuilding *a2,
        struct SGfxObjectInfo *a3)

void  CResidenceBuildingRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-10h]

  (*(void (__thiscall **)(CResidenceBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v5 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  return CGfxManager::GetBuildingGfxInfo((int)a3, v3, v5, 1, (int)this + 76);
}


// address=[0x1518b40]
// Decompiled from CResidenceBuildingRole *__thiscall CResidenceBuildingRole::Init(CResidenceBuildingRole *this, struct CBuilding *a2)

void  CResidenceBuildingRole::Init(class CBuilding *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CResidenceBuildingRole *result; // eax
  int v7; // [esp-8h] [ebp-10h]
  int v8; // [esp-4h] [ebp-Ch]
  int NrStrikingCarriers; // [esp+0h] [ebp-8h]

  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 4) = 3;
  *((_BYTE *)this + 380) = 0;
  v8 = *(_DWORD *)(*((_DWORD *)this + 94) + 496);
  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  CStatistic::ChangeResidenceSpace((CStatistic *)&g_cStatistic, v2, v8);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  if ( CEcoSectorMgr::GetNrStrikingCarriers((CEcoSectorMgr *)g_cESMgr, v3) )
  {
    v4 = IEntity::OwnerId((unsigned __int8 *)a2);
    NrStrikingCarriers = CEcoSectorMgr::GetNrStrikingCarriers((CEcoSectorMgr *)g_cESMgr, v4);
    if ( NrStrikingCarriers < *(_DWORD *)(*((_DWORD *)this + 94) + 496) )
    {
      *((_BYTE *)this + 380) = NrStrikingCarriers;
    }
    else
    {
      *((_BYTE *)this + 380) = *(_DWORD *)(*((_DWORD *)this + 94) + 496) + 1;
      v7 = IEntity::ID();
      v5 = IEntity::OwnerId((unsigned __int8 *)a2);
      (*(void (__thiscall **)(void *, int, int, int, _DWORD))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 8, v5, v7, 0);
    }
  }
  CEcoSectorMgr::UpdateStrikeSettlers(g_cESMgr);
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(CResidenceBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  result = this;
  if ( *((unsigned __int8 *)this + 380) < *(int *)(*((_DWORD *)this + 94) + 496) )
    return (CResidenceBuildingRole *)IAnimatedEntity::RegisterForLogicUpdate(31);
  return result;
}


// address=[0x1518c80]
// Decompiled from int __thiscall CResidenceBuildingRole::PostLoadInit(CResidenceBuildingRole *this, struct CBuilding *a2)

void  CResidenceBuildingRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x1518cb0]
// Decompiled from _DWORD *__thiscall CResidenceBuildingRole::FillDialog(CResidenceBuildingRole *this, struct CBuilding *a2, bool a3)

void  CResidenceBuildingRole::FillDialog(class CBuilding *,bool) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-40h]
  int v7; // [esp-8h] [ebp-40h]
  unsigned int v9; // [esp+8h] [ebp-30h]
  CEvn_Event v10; // [esp+10h] [ebp-28h] BYREF
  int v11; // [esp+34h] [ebp-4h]

  dword_3F1E4B0 = 0;
  byte_3F1E4B5 = IEntity::Race(a2);
  byte_3F1E4B4 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E4CC = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E4B7 = 0;
  byte_3F1E4B9 = 0;
  byte_3F1E4B6 = 0;
  byte_3F1E4BA = -1;
  byte_3F1E4BF = CResidenceBuildingRole::ReturnRemainingSettlers(this);
  v6 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4BB = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v6, 0);
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4BC = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v7, 1u);
  v9 = 604;
  if ( !a3 )
    v9 = 602;
  CEvn_Event::CEvn_Event(&v10, v9, 0, (unsigned int)&g_cBuildingInfo, 0);
  v11 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v10);
  v11 = -1;
  return CEvn_Event::~CEvn_Event(&v10);
}


// address=[0x1518e10]
// Decompiled from int __thiscall CResidenceBuildingRole::ReturnRemainingSettlers(CResidenceBuildingRole *this)

int  CResidenceBuildingRole::ReturnRemainingSettlers(void) {
  
  int v2; // [esp+4h] [ebp-4h]

  v2 = *(_DWORD *)(*((_DWORD *)this + 94) + 496) - *((unsigned __int8 *)this + 380);
  if ( v2 < 0 )
    return 0;
  return v2;
}


// address=[0x1518e50]
// Decompiled from char *__thiscall CResidenceBuildingRole::CResidenceBuildingRole(char *this, int a2)

 CResidenceBuildingRole::CResidenceBuildingRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CResidenceBuildingRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CResidenceBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v5 + 380);
  v6 = -1;
  return v5;
}


// address=[0x1518f10]
// Decompiled from int __thiscall CResidenceBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)

void  CResidenceBuildingRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned char>(a2, (int)v4 + 380);
}


// address=[0x3d8b58c]
// [Decompilation failed for static unsigned long CResidenceBuildingRole::m_iClassID]

// address=[0x14fd240]
// Decompiled from void __thiscall CResidenceBuildingRole::ConvertEventIntoGoal(
        CResidenceBuildingRole *this,
        struct CBuilding *a2,
        struct CEntityEvent *a3)

void  CResidenceBuildingRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x14fde70]
// Decompiled from char __thiscall CResidenceBuildingRole::TryCrushBuilding(CResidenceBuildingRole *this)

bool  CResidenceBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


// address=[0x1518f60]
// Decompiled from char __thiscall CResidenceBuildingRole::CrushBuilding(CResidenceBuildingRole *this)

bool  CResidenceBuildingRole::CrushBuilding(void) {
  
  unsigned __int8 *v1; // eax
  int v2; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = -*(_DWORD *)(*((_DWORD *)this + 94) + 496);
  v1 = (unsigned __int8 *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v2 = IEntity::OwnerId(v1);
  CStatistic::ChangeResidenceSpace((CStatistic *)&g_cStatistic, v2, v4);
  return 1;
}


