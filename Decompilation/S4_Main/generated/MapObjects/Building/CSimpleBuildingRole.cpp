#include "CSimpleBuildingRole.h"

// Definitions for class CSimpleBuildingRole

// address=[0x1401da0]
// Decompiled from int __cdecl CSimpleBuildingRole::New(int a1)
class CPersistence * __cdecl CSimpleBuildingRole::New(std::istream & a1) {
  
  if ( operator new(0x180u) )
    return CSimpleBuildingRole::CSimpleBuildingRole(a1);
  else
    return 0;
}


// address=[0x14fcb10]
// Decompiled from CSimpleBuildingRole *__thiscall CSimpleBuildingRole::CSimpleBuildingRole(CSimpleBuildingRole *this)
 CSimpleBuildingRole::CSimpleBuildingRole(void) {
  
  IBuildingRole::IBuildingRole((IBuildingRole *)this);
  *(_DWORD *)this = &CSimpleBuildingRole::_vftable_;
  return this;
}


// address=[0x14fcd20]
// Decompiled from int __thiscall CSimpleBuildingRole::~CSimpleBuildingRole(CSimpleBuildingRole *this)
 CSimpleBuildingRole::~CSimpleBuildingRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd180]
// Decompiled from int __thiscall CSimpleBuildingRole::ClassID(CSimpleBuildingRole *this)
unsigned long  CSimpleBuildingRole::ClassID(void)const {
  
  return CSimpleBuildingRole::m_iClassID;
}


// address=[0x14fd400]
// Decompiled from void *__thiscall CSimpleBuildingRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CSimpleBuildingRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x14fd560]
// Decompiled from int __thiscall CSimpleBuildingRole::GetBuildingRole(CSimpleBuildingRole *this)
int  CSimpleBuildingRole::GetBuildingRole(void) {
  
  return 1;
}


// address=[0x14fd6a0]
// Decompiled from void *__thiscall CSimpleBuildingRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)
int  CSimpleBuildingRole::GetPileIdWithGood(int a2)const {
  
  return 0;
}


// address=[0x14fd750]
// Decompiled from void __thiscall CSimpleBuildingRole::GoodArrive(CSimpleBuildingRole *this, int a2)
void  CSimpleBuildingRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x14fdbf0]
// Decompiled from int __cdecl CSimpleBuildingRole::Load(int a1)
class CSimpleBuildingRole * __cdecl CSimpleBuildingRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CSimpleBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x151ab50]
// Decompiled from void __thiscall CSimpleBuildingRole::LogicUpdate(CSimpleBuildingRole *this, CBuilding *a2)
void  CSimpleBuildingRole::LogicUpdate(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  unsigned __int8 *v13; // eax
  int WorkingAreaPackedXY; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // eax
  ISettlerRole *v20; // eax
  ISettlerRole *v21; // eax
  int v22; // eax
  int v23; // esi
  int v24; // [esp-4h] [ebp-D8h]
  char v25; // [esp-4h] [ebp-D8h]
  unsigned __int16 m_uSettlerId; // [esp-4h] [ebp-D8h]
  int v27; // [esp-4h] [ebp-D8h]
  int v28; // [esp-4h] [ebp-D8h]
  CEntityEvent v29; // [esp+8h] [ebp-CCh] BYREF
  CEntityEvent v30; // [esp+20h] [ebp-B4h] BYREF
  CEntityEvent v31; // [esp+38h] [ebp-9Ch] BYREF
  int v32; // [esp+50h] [ebp-84h]
  CSettler *v33; // [esp+54h] [ebp-80h]
  struct CEntityEvent *v34; // [esp+58h] [ebp-7Ch]
  struct CEntityEvent *v35; // [esp+5Ch] [ebp-78h]
  CSettlerMgr::SSettlerInfos *v36; // [esp+60h] [ebp-74h]
  int v37; // [esp+64h] [ebp-70h]
  int v38; // [esp+68h] [ebp-6Ch]
  int v39; // [esp+6Ch] [ebp-68h]
  CEntityEvent *v40; // [esp+70h] [ebp-64h]
  CEntityEvent *v41; // [esp+74h] [ebp-60h]
  CSettlerMgr::SSettlerInfos *v42; // [esp+78h] [ebp-5Ch]
  CEntityEvent *v43; // [esp+7Ch] [ebp-58h]
  CEntityEvent *v44; // [esp+80h] [ebp-54h]
  int v45; // [esp+84h] [ebp-50h]
  unsigned int v46; // [esp+88h] [ebp-4Ch]
  unsigned int v47; // [esp+8Ch] [ebp-48h]
  CSettler *v48; // [esp+90h] [ebp-44h]
  CSettler *v49; // [esp+94h] [ebp-40h]
  unsigned int v50; // [esp+98h] [ebp-3Ch]
  unsigned int v51; // [esp+9Ch] [ebp-38h]
  int v52; // [esp+A0h] [ebp-34h]
  T_OBJECT_TYPE ObjectType; // [esp+A4h] [ebp-30h]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+A8h] [ebp-2Ch]
  unsigned __int8 m_uLogicState; // [esp+ACh] [ebp-28h]
  IEntity *v56; // [esp+B0h] [ebp-24h]
  IEntity *v57; // [esp+B4h] [ebp-20h]
  int v58; // [esp+B8h] [ebp-1Ch]
  CSettler *v59; // [esp+BCh] [ebp-18h]
  char v60; // [esp+C3h] [ebp-11h]
  int v62; // [esp+D0h] [ebp-4h]

  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) )
    this->FillDialog(this, a2, 1);
  m_uLogicState = this->m_uLogicState;
  switch ( m_uLogicState )
  {
    case 1u:
      if ( this->OrderInhabitant(this, a2) )
        this->m_uLogicState = 3;
      else
        IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
      break;
    case 2u:
      if ( this->m_iDelayTick > (int)this->m_pBuildingInfo->m_iProductionDelay )
      {
        this->m_iDelayTick = 0;
        this->m_uLogicState = 3;
        IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
      }
      else
      {
        ++this->m_iDelayTick;
        IAnimatedEntity::RegisterForLogicUpdate(a2, 14);
      }
      break;
    case 3u:
      if ( this->m_bInhabitants && IEntity::FlagBits(a2, (EntityFlag)4096) )
      {
        if ( IEntity::Type(a2) == BUILDING_FORESTERHUT )
        {
          if ( this->SearchInWorkingArea((int)this, (_DWORD *)a2, 1) )
          {
            v56 = CSettlerMgr::operator[](this->m_uSettlerId);
            v24 = IEntity::Type(v56);
            v2 = IEntity::Race(v56);
            SettlerInfo = CSettlerMgr::GetSettlerInfo(v2, v24);
            v3 = Y16X16::UnpackXFast(this->m_iFoundWorkAreaItemXY);
            v50 = v3 - std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 1u)->m_iOffsetX;
            v4 = Y16X16::UnpackYFast(this->m_iFoundWorkAreaItemXY);
            v51 = v4 - std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 1u)->m_iOffsetY;
            v25 = CWorldManager::Ground(v50, v51);
            v5 = IEntity::Race(v56);
            ObjectType = CDecoObjMgr::GetObjectType(&g_cDecoObjMgr, SettlerInfo->m_uFarmerType, v5, v25);
            if ( ObjectType )
            {
              CDecoObjMgr::SetFlagsForObject(&g_cDecoObjMgr, v50, v51, ObjectType, 0);
              v6 = CBuilding::DoorPackedXY(a2);
              IEntity::SetPosition(v56, v6);
              m_uSettlerId = this->m_uSettlerId;
              v7 = CBuilding::DoorWorldIdx(a2);
              CWorldManager::SetSettlerId(v7, m_uSettlerId);
              IEntity::ClearFlagBits(v56, ENTITY_FLAG_ON_BOARD|ENTITY_FLAG_Visible);
              v49 = CSettlerMgr::operator[](this->m_uSettlerId);
              v44 = CEntityEvent::CEntityEvent(&v31, 6u, 0, 0, ObjectType, this->m_iFoundWorkAreaItemXY);
              v43 = v44;
              v62 = 0;
              v49->SetEvent(v49, v44);
              v62 = -1;
              CEntityEvent::~CEntityEvent(&v31);
            }
            else
            {
              IAnimatedEntity::RegisterForLogicUpdate(a2, 14);
            }
            return;
          }
        }
        else if ( IEntity::Type(a2) == BUILDING_HEALERHUT )
        {
          v8 = CBuilding::EnsignWorldIdx(a2);
          v52 = CWorldManager::SettlerId(v8);
          if ( v52 )
          {
            v57 = CSettlerMgr::operator[](v52);
            v27 = IEntity::Type(v57);
            v9 = IEntity::Race(v57);
            v42 = CSettlerMgr::GetSettlerInfo(v9, v27);
            v10 = IEntity::OwnerId(v57);
            v11 = CAlliances::AllianceId(v10);
            v12 = IEntity::OwnerId(a2);
            if ( v11 == CAlliances::AllianceId(v12)
              && IEntity::WarriorType(v57)
              && v57->Amount() < v42->m_iMaxLifePoints )
            {
              this->m_iNextWorkTicks = 0;
              v33 = CSettlerMgr::operator[](this->m_uSettlerId);
              v48 = CSettlerMgr::operator[](this->m_uSettlerId);
              v13 = std::vector<unsigned char>::operator[](0);
              v41 = CEntityEvent::CEntityEvent(&v30, 3u, 0, 0, *v13, v52);
              v40 = v41;
              v62 = 1;
              v48->SetEvent(v48, v41);
              v62 = -1;
              CEntityEvent::~CEntityEvent(&v30);
              return;
            }
          }
          if ( this->m_iNextWorkTicks )
          {
            --this->m_iNextWorkTicks;
          }
          else
          {
            WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(a2);
            v39 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
            v15 = CBuilding::GetWorkingAreaPackedXY(a2);
            v38 = Y16X16::UnpackYFast(v15);
            v58 = 0;
            v60 = 0;
            v32 = 30;
            while ( v58 < 30 )
            {
              v46 = v39 + CSpiralOffsets::DeltaX(v58 + this->m_vWorkingArea[0]);
              v47 = v38 + CSpiralOffsets::DeltaY(v58 + this->m_vWorkingArea[0]);
              v37 = CWorldManager::Index(v46, v47);
              if ( CWorldManager::InWorld(v46, v47) )
              {
                v45 = CWorldManager::SettlerId(v37);
                if ( v45 )
                {
                  v59 = CSettlerMgr::operator[](v45);
                  v28 = IEntity::Type(v59);
                  v16 = IEntity::Race(v59);
                  v36 = CSettlerMgr::GetSettlerInfo(v16, v28);
                  if ( IEntity::WarriorType(v59) )
                  {
                    v17 = IEntity::OwnerId(v59);
                    v18 = CAlliances::AllianceId(v17);
                    v19 = IEntity::OwnerId(a2);
                    if ( v18 == CAlliances::AllianceId(v19) && v59->Amount(v59) < v36->m_iMaxLifePoints )
                    {
                      v20 = CSettler::Role(v59);
                      if ( ISettlerRole::GetTask(v20) == 27
                        || (v21 = CSettler::Role(v59), ISettlerRole::GetTask(v21) == 17) )
                      {
                        v22 = CBuilding::EnsignPackedXY(a2);
                        v35 = CEntityEvent::CEntityEvent(&v29, 0x11u, 13, 0, v22, 0);
                        v34 = v35;
                        v62 = 2;
                        v59->SetEvent(v59, v35);
                        v62 = -1;
                        CEntityEvent::~CEntityEvent(&v29);
                        v60 = 1;
                        ++v58;
                        break;
                      }
                    }
                  }
                }
              }
              ++v58;
            }
            this->m_vWorkingArea[0] += v58;
            v23 = this->m_vWorkingArea[0];
            if ( v23 >= CSpiralOffsets::Last(this->m_pBuildingInfo->m_iWorkingAreaRadius) )
              this->m_vWorkingArea[0] = 0;
            if ( v60 == 1 )
            {
              this->m_iNextWorkTicks = 10;
              IAnimatedEntity::RegisterForLogicUpdate(a2, 14);
              return;
            }
          }
        }
      }
      IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
      return;
    default:
      return;
  }
}


// address=[0x151b270]
// Decompiled from void __thiscall CSimpleBuildingRole::FillGfxInfo(IBuildingRole *this, IEntity *a2, struct SGfxObjectInfo *_rInfo)
void  CSimpleBuildingRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & _rInfo) {
  
  unsigned int iRace; // eax
  int v4; // eax
  int v5; // eax
  unsigned int iType; // [esp-Ch] [ebp-14h]
  IEntity *v7; // [esp+0h] [ebp-8h]

  this->Update(this, a2);
  iType = IEntity::Type(a2);
  iRace = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo(g_pGfxManager, _rInfo, iRace, iType, 1, (int)this->m_vPatchPairs);
  v4 = IEntity::OwnerId(a2);
  _rInfo->m_iColor = CPlayerManager::Color(v4);
  v5 = IEntity::OwnerId(a2);
  IBuildingRole::MiniFlag(this, _rInfo, v5);
  if ( this->m_bInhabitants == 1 && IEntity::Type(a2) == 27 )
  {
    v7 = CSettlerMgr::operator[](this->m_uSettlerId);
    CSettler::GetPatchGfx(v7, _rInfo->m_vPatches);
  }
}


// address=[0x151b340]
// Decompiled from void __thiscall CSimpleBuildingRole::Init(CSimpleBuildingRole *this, IAnimatedEntity *a2)
void  CSimpleBuildingRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // [esp-8h] [ebp-Ch]

  IBuildingRole::InitCommon((int)a2);
  LOBYTE(this[1].__vftable) = 0;
  this->m_bHasWarnedAboutEmptyWA = 0;
  this->m_uLogicState = 1;
  if ( IEntity::Type(a2) == 27 )
  {
    this->m_pSearchFkt = 0;
  }
  else
  {
    v3 = *((char *)this->m_pBuildingInfo + 478);
    v2 = IEntity::Race(a2);
    CSettlerMgr::GetSettlerInfo(v2, v3);
    this->m_pSearchFkt = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](1);
    if ( !this->m_pSearchFkt
      && BBSupportDbgReport(2, "MapObjects\\Building\\SimpleBuilding.cpp", 141, "m_pSearchFkt!= NULL") == 1 )
    {
      __debugbreak();
    }
  }
  IAnimatedEntity::RegisterForLogicUpdate(a2, 2);
  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) )
    this->FillDialog(this, a2, 0);
}


// address=[0x151b420]
// Decompiled from void __thiscall CSimpleBuildingRole::PostLoadInit(CSimpleBuildingRole *this, IEntity *a2)
void  CSimpleBuildingRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  CSettlerMgr::SSettlerInfos *SettlerInfo; // eax
  int m_iBuildingInhabitant; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  v6 = IEntity::Type(a2);
  v2 = IEntity::Race(a2);
  this->m_pBuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v2, v6);
  if ( IEntity::Type(a2) == 27 )
  {
    this->m_pSearchFkt = 0;
  }
  else
  {
    m_iBuildingInhabitant = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
    v3 = IEntity::Race(a2);
    SettlerInfo = CSettlerMgr::GetSettlerInfo(v3, m_iBuildingInhabitant);
    this->m_pSearchFkt = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 1u)->m_pSearchFkt;
    if ( !this->m_pSearchFkt
      && BBSupportDbgReport(2, "MapObjects\\Building\\SimpleBuilding.cpp", 115, "m_pSearchFkt != 0") == 1 )
    {
      __debugbreak();
    }
  }
}


// address=[0x151b4d0]
// Decompiled from char __thiscall CSimpleBuildingRole::SettlerEnter(CSimpleBuildingRole *this, struct CBuilding *a2, int a3)
bool  CSimpleBuildingRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  float v5; // xmm0_4
  int v6; // eax
  void *v7; // eax
  int v8; // eax
  const char *BuildingName; // eax
  const char *v11; // [esp+0h] [ebp-2Ch]
  const char *RaceName; // [esp+4h] [ebp-28h]
  int v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h]
  int v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h]
  CSettler *v17; // [esp+20h] [ebp-Ch]
  CMFCToolBarButton *v18; // [esp+24h] [ebp-8h]

  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\SimpleBuilding.cpp", 161, "_iSettlerId > 0") == 1 )
    __debugbreak();
  v17 = (CSettler *)CSettlerMgr::operator[](a3);
  if ( IEntity::Type((unsigned __int16 *)a2) == 27 )
  {
    if ( *((_BYTE *)this + 29) )
    {
      if ( *((unsigned __int16 *)this + 4) != a3
        && BBSupportDbgReport(2, "MapObjects\\Building\\SimpleBuilding.cpp", 184, "m_uSettlerId == _iSettlerId") == 1 )
      {
        __debugbreak();
      }
    }
    else
    {
      *((_BYTE *)this + 29) = 1;
      *((_WORD *)this + 4) = a3;
    }
    v18 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
    v3 = CBuilding::DoorPackedXY(v18);
    v15 = Y16X16::UnpackXFast(v3);
    v4 = CBuilding::DoorPackedXY(v18);
    v14 = Y16X16::UnpackYFast(v4);
    v13 = v15 - IEntity::X(v18);
    v16 = v14 - IEntity::Y(v18);
    v5 = (float)((float)v16 * 24.0) / 2.0;
    CSettler::SetOffset(v17, (float)((float)v13 + (float)((float)((float)v16 * -1.0) / 2.0)) * 24.0, v5);
    IEntity::SetFlagBits(v17, ENTITY_FLAG_MagicInvisible);
  }
  else if ( *((_BYTE *)this + 29) )
  {
    if ( *((unsigned __int16 *)this + 4) != a3
      && BBSupportDbgReport(2, "MapObjects\\Building\\SimpleBuilding.cpp", 210, "m_uSettlerId == _iSettlerId") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    *((_BYTE *)this + 29) = 1;
    *((_WORD *)this + 4) = a3;
  }
  IEntity::ClearFlagBits(v17, ENTITY_FLAG_Visible);
  IMovingEntity::SetDisplacementCosts(10);
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 480) )
  {
    *((_BYTE *)this + 5) = 0;
    IAnimatedEntity::RegisterForLogicUpdate(14);
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(31);
    v6 = IEntity::Race(a2);
    RaceName = CS4DefineNames::GetRaceName(v6);
    v7 = (void *)typeid(this);
    v11 = (const char *)type_info::name(v7);
    v8 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
    BuildingName = CS4DefineNames::GetBuildingName(v8);
    BBSupportTracePrintF(
      2,
      "WARNING: Building %s (role %s) of race %s has no production delay!",
      BuildingName,
      v11,
      RaceName);
  }
  *((_BYTE *)this + 4) = 2;
  (*(void (__thiscall **)(CSimpleBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 72))(this, a2, 0);
  return 1;
}


// address=[0x151b740]
// Decompiled from _DWORD *__thiscall CSimpleBuildingRole::FillDialog(CSimpleBuildingRole *this, IEntity *a2, bool a3)
void  CSimpleBuildingRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  int v6; // eax
  int v7; // eax
  S4_BUILDING_ENUM v8; // [esp-8h] [ebp-60h]
  S4_BUILDING_ENUM v9; // [esp-8h] [ebp-60h]
  S4_BUILDING_ENUM v10; // [esp-8h] [ebp-60h]
  S4_BUILDING_ENUM v11; // [esp-8h] [ebp-60h]
  unsigned int v12; // [esp+4h] [ebp-54h]
  unsigned int v13; // [esp+Ch] [ebp-4Ch]
  CEvn_Event v15; // [esp+18h] [ebp-40h] BYREF
  CEvn_Event v16; // [esp+30h] [ebp-28h] BYREF
  int v17; // [esp+54h] [ebp-4h]

  if ( IEntity::Type(a2) == 27 )
  {
    g_cBuildingInfo.m_iUnknown = 0;
    g_cBuildingInfo.m_cRace = IEntity::Race(a2);
    g_cBuildingInfo.m_cType = IEntity::Type(a2);
    g_cBuildingInfo.m_unknownB = 1;
    MEMORY[0x3F1E4B8] = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
    MEMORY[0x3F1E4B9] = *((_DWORD *)this->m_pBuildingInfo + 123) > 0;
    v8 = IEntity::Type(a2);
    v3 = IEntity::OwnerId(a2);
    MEMORY[0x3F1E4BB] = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v8, 0);
    v9 = IEntity::Type(a2);
    v4 = IEntity::OwnerId(a2);
    MEMORY[0x3F1E4BC] = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v9, 1u);
    g_cBuildingInfo.m_bInhabitants = this->m_bInhabitants;
    if ( this->m_bInhabitants )
      MEMORY[0x3F1E4BD] = *((_BYTE *)this->m_pBuildingInfo + 478);
    v13 = 604;
    if ( !a3 )
      v13 = 602;
    CEvn_Event::CEvn_Event(&v16, v13, 0, (unsigned int)&g_cBuildingInfo, 0);
    v17 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, &v16);
    v17 = -1;
    return CEvn_Event::~CEvn_Event(&v16);
  }
  else
  {
    MEMORY[0x3F1E4E8] = 2;
    MEMORY[0x3F1E4ED] = IEntity::Race(a2);
    MEMORY[0x3F1E4EC] = IEntity::Type(a2);
    MEMORY[0x3F1E4EF] = 1;
    MEMORY[0x3F1E4F0] = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
    MEMORY[0x3F1E4F1] = *((_DWORD *)this->m_pBuildingInfo + 123) > 0;
    v10 = IEntity::Type(a2);
    v6 = IEntity::OwnerId(a2);
    MEMORY[0x3F1E4F3] = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v6, v10, 0);
    v11 = IEntity::Type(a2);
    v7 = IEntity::OwnerId(a2);
    MEMORY[0x3F1E4F4] = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v7, v11, 1u);
    MEMORY[0x3F1E4EE] = this->m_bInhabitants;
    MEMORY[0x3F1E4F9] = 0;
    MEMORY[0x3F1E4F8] = 0;
    if ( this->m_bInhabitants )
      MEMORY[0x3F1E4F5] = *((_BYTE *)this->m_pBuildingInfo + 478);
    v12 = 604;
    if ( !a3 )
      v12 = 602;
    CEvn_Event::CEvn_Event(&v15, v12, 0, (unsigned int)&g_cResourceCollectorInfo, 0);
    v17 = 1;
    IEventEngine::SendAMessage(g_pEvnEngine, &v15);
    v17 = -1;
    return CEvn_Event::~CEvn_Event(&v15);
  }
}


// address=[0x151ba20]
// Decompiled from char *__thiscall CSimpleBuildingRole::CSimpleBuildingRole(char *this, int a2)
 CSimpleBuildingRole::CSimpleBuildingRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CSimpleBuildingRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSimpleBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v5 + 380);
  v6 = -1;
  return v5;
}


// address=[0x151bae0]
// Decompiled from int __thiscall CSimpleBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CSimpleBuildingRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned char>(a2, (int)v4 + 380);
}


// address=[0x3d8b798]
// [Decompilation failed for static unsigned long CSimpleBuildingRole::m_iClassID]

// address=[0x14fd250]
// Decompiled from void __thiscall CSimpleBuildingRole::ConvertEventIntoGoal(  CSimpleBuildingRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CSimpleBuildingRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
  ;
}


// address=[0x14fd2b0]
// Decompiled from char __thiscall CSimpleBuildingRole::CrushBuilding(CSimpleBuildingRole *this)
bool  CSimpleBuildingRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14fde80]
// Decompiled from char __thiscall CSimpleBuildingRole::TryCrushBuilding(CSimpleBuildingRole *this)
bool  CSimpleBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


