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
// Decompiled from EntityFlag __thiscall CSimpleBuildingRole::LogicUpdate(unsigned __int8 *this, IAnimatedEntity *a2)
void  CSimpleBuildingRole::LogicUpdate(class CBuilding * a2) {
  
  EntityFlag result; // eax
  int v3; // eax
  int v4; // esi
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  unsigned __int8 *v14; // eax
  int WorkingAreaPackedXY; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // esi
  int v20; // eax
  ISettlerRole *v21; // eax
  ISettlerRole *v22; // eax
  int v23; // eax
  int v24; // esi
  int v25; // [esp-4h] [ebp-D8h]
  char v26; // [esp-4h] [ebp-D8h]
  __int16 v27; // [esp-4h] [ebp-D8h]
  int v28; // [esp-4h] [ebp-D8h]
  int v29; // [esp-4h] [ebp-D8h]
  CEntityEvent v30; // [esp+8h] [ebp-CCh] BYREF
  CEntityEvent v31; // [esp+20h] [ebp-B4h] BYREF
  CEntityEvent v32; // [esp+38h] [ebp-9Ch] BYREF
  int v33; // [esp+50h] [ebp-84h]
  IEntity *v34; // [esp+54h] [ebp-80h]
  CEntityEvent *v35; // [esp+58h] [ebp-7Ch]
  CEntityEvent *v36; // [esp+5Ch] [ebp-78h]
  CSettlerMgr::SSettlerInfos *v37; // [esp+60h] [ebp-74h]
  int v38; // [esp+64h] [ebp-70h]
  int v39; // [esp+68h] [ebp-6Ch]
  int v40; // [esp+6Ch] [ebp-68h]
  CEntityEvent *v41; // [esp+70h] [ebp-64h]
  CEntityEvent *v42; // [esp+74h] [ebp-60h]
  CSettlerMgr::SSettlerInfos *v43; // [esp+78h] [ebp-5Ch]
  CEntityEvent *v44; // [esp+7Ch] [ebp-58h]
  CEntityEvent *v45; // [esp+80h] [ebp-54h]
  int v46; // [esp+84h] [ebp-50h]
  unsigned int v47; // [esp+88h] [ebp-4Ch]
  unsigned int v48; // [esp+8Ch] [ebp-48h]
  IEntity *v49; // [esp+90h] [ebp-44h]
  IEntity *v50; // [esp+94h] [ebp-40h]
  int v51; // [esp+98h] [ebp-3Ch]
  int v52; // [esp+9Ch] [ebp-38h]
  int v53; // [esp+A0h] [ebp-34h]
  T_OBJECT_TYPE ObjectType; // [esp+A4h] [ebp-30h]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+A8h] [ebp-2Ch]
  unsigned __int8 v56; // [esp+ACh] [ebp-28h]
  IEntity *v57; // [esp+B0h] [ebp-24h]
  IEntity *v58; // [esp+B4h] [ebp-20h]
  int v59; // [esp+B8h] [ebp-1Ch]
  IEntity *v60; // [esp+BCh] [ebp-18h]
  char v61; // [esp+C3h] [ebp-11h]
  unsigned __int8 *v62; // [esp+C4h] [ebp-10h]
  int v63; // [esp+D0h] [ebp-4h]

  v62 = this;
  result = IEntity::FlagBits(a2, EntityFlag_Selected);
  if ( result )
    result = (*(int (__thiscall **)(unsigned __int8 *, IAnimatedEntity *, int))(*(_DWORD *)v62 + 88))(v62, a2, 1);
  v56 = v62[4];
  switch ( v56 )
  {
    case 1u:
      result = (*(int (__thiscall **)(unsigned __int8 *, IAnimatedEntity *))(*(_DWORD *)v62 + 120))(v62, a2);
      if ( (_BYTE)result )
        v62[4] = 3;
      else
        return IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
      break;
    case 2u:
      if ( v62[5] > (int)*(unsigned __int8 *)(*((_DWORD *)v62 + 94) + 480) )
      {
        v62[5] = 0;
        v62[4] = 3;
        return IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
      }
      else
      {
        ++v62[5];
        return IAnimatedEntity::RegisterForLogicUpdate(a2, 14);
      }
    case 3u:
      if ( !v62[29] || !IEntity::FlagBits(a2, (EntityFlag)4096) )
        return IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
      if ( IEntity::Type(a2) == 2 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(unsigned __int8 *, IAnimatedEntity *, int))(*(_DWORD *)v62 + 104))(
               v62,
               a2,
               1) )
        {
          v57 = CSettlerMgr::operator[](*((unsigned __int16 *)v62 + 4));
          v25 = IEntity::Type(v57);
          v3 = IEntity::Race(v57);
          SettlerInfo = CSettlerMgr::GetSettlerInfo(v3, v25);
          v4 = Y16X16::UnpackXFast(*((_DWORD *)v62 + 4));
          v51 = v4 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 5);
          v5 = Y16X16::UnpackYFast(*((_DWORD *)v62 + 4));
          v52 = v5 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 6);
          v26 = CWorldManager::Ground(v51, v52);
          v6 = IEntity::Race(v57);
          ObjectType = CDecoObjMgr::GetObjectType(&g_cDecoObjMgr, SettlerInfo->m_uFarmerType, v6, v26);
          if ( ObjectType == OBJECT_NO_OBJECT )
            return IAnimatedEntity::RegisterForLogicUpdate(a2, 14);
          CDecoObjMgr::SetFlagsForObject(&g_cDecoObjMgr, v51, v52, ObjectType, 0);
          v7 = CBuilding::DoorPackedXY((CMFCToolBarButton *)a2);
          IEntity::SetPosition(v57, v7);
          v27 = *((_WORD *)v62 + 4);
          v8 = CBuilding::DoorWorldIdx(a2);
          CWorldManager::SetSettlerId(v8, v27);
          IEntity::ClearFlagBits(v57, EntityFlag_OnBoard|EntityFlag_Visible);
          v50 = CSettlerMgr::operator[](*((unsigned __int16 *)v62 + 4));
          v45 = CEntityEvent::CEntityEvent(&v32, 6u, 0, 0, ObjectType, *((_DWORD *)v62 + 4));
          v44 = v45;
          v63 = 0;
          v50->SetEvent(v50, v45);
          v63 = -1;
          return CEntityEvent::~CEntityEvent(&v32);
        }
      }
      else if ( IEntity::Type(a2) == 27 )
      {
        v9 = CBuilding::EnsignWorldIdx((CBuilding *)a2);
        v53 = CWorldManager::SettlerId(v9);
        if ( v53 )
        {
          v58 = CSettlerMgr::operator[](v53);
          v28 = IEntity::Type(v58);
          v10 = IEntity::Race(v58);
          v43 = CSettlerMgr::GetSettlerInfo(v10, v28);
          v11 = IEntity::OwnerId(v58);
          v12 = CAlliances::AllianceId(v11);
          v13 = IEntity::OwnerId(a2);
          if ( v12 == CAlliances::AllianceId(v13)
            && IEntity::WarriorType(v58)
            && ((int (__thiscall *)(IEntity *))v58->Amount)(v58) < v43->m_bHealth )
          {
            v62[380] = 0;
            v34 = CSettlerMgr::operator[](*((unsigned __int16 *)v62 + 4));
            v49 = CSettlerMgr::operator[](*((unsigned __int16 *)v62 + 4));
            v14 = (unsigned __int8 *)std::vector<unsigned char>::operator[](0);
            v42 = CEntityEvent::CEntityEvent(&v31, 3u, 0, 0, *v14, v53);
            v41 = v42;
            v63 = 1;
            v49->SetEvent(v49, v42);
            v63 = -1;
            return CEntityEvent::~CEntityEvent(&v31);
          }
        }
        if ( v62[380] )
        {
          --v62[380];
        }
        else
        {
          WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(a2);
          v40 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
          v16 = CBuilding::GetWorkingAreaPackedXY(a2);
          v39 = Y16X16::UnpackYFast(v16);
          v59 = 0;
          v61 = 0;
          v33 = 30;
          while ( v59 < 30 )
          {
            v47 = v40 + CSpiralOffsets::DeltaX(v59 + *((unsigned __int16 *)v62 + 10));
            v48 = v39 + CSpiralOffsets::DeltaY(v59 + *((unsigned __int16 *)v62 + 10));
            v38 = CWorldManager::Index(v47, v48);
            if ( CWorldManager::InWorld(v47, v48) )
            {
              v46 = CWorldManager::SettlerId(v38);
              if ( v46 )
              {
                v60 = CSettlerMgr::operator[](v46);
                v29 = IEntity::Type(v60);
                v17 = IEntity::Race(v60);
                v37 = CSettlerMgr::GetSettlerInfo(v17, v29);
                if ( IEntity::WarriorType(v60) )
                {
                  v18 = IEntity::OwnerId(v60);
                  v19 = CAlliances::AllianceId(v18);
                  v20 = IEntity::OwnerId(a2);
                  if ( v19 == CAlliances::AllianceId(v20)
                    && ((int (__thiscall *)(IEntity *))v60->Amount)(v60) < v37->m_bHealth )
                  {
                    v21 = (ISettlerRole *)CSettler::Role((CSettler *)v60);
                    if ( ISettlerRole::GetTask(v21) == 27
                      || (v22 = (ISettlerRole *)CSettler::Role((CSettler *)v60), ISettlerRole::GetTask(v22) == 17) )
                    {
                      v23 = CBuilding::EnsignPackedXY(a2);
                      v36 = CEntityEvent::CEntityEvent(&v30, 0x11u, 13, 0, v23, 0);
                      v35 = v36;
                      v63 = 2;
                      v60->SetEvent(v60, v36);
                      v63 = -1;
                      CEntityEvent::~CEntityEvent(&v30);
                      v61 = 1;
                      ++v59;
                      break;
                    }
                  }
                }
              }
            }
            ++v59;
          }
          *((_WORD *)v62 + 10) += v59;
          v24 = *((unsigned __int16 *)v62 + 10);
          if ( v24 >= CSpiralOffsets::Last(*(_DWORD *)(*((_DWORD *)v62 + 94) + 492)) )
            *((_WORD *)v62 + 10) = 0;
          if ( v61 == 1 )
          {
            v62[380] = 10;
            return IAnimatedEntity::RegisterForLogicUpdate(a2, 14);
          }
        }
      }
      return IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
    default:
      return result;
  }
  return result;
}


// address=[0x151b270]
// Decompiled from CSimpleBuildingRole *__thiscall CSimpleBuildingRole::FillGfxInfo(  CSimpleBuildingRole *this,  struct CBuilding *a2,  struct SGfxObjectInfo *a3)
void  CSimpleBuildingRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CSimpleBuildingRole *result; // eax
  CSettler *v7; // eax
  int v8; // [esp-Ch] [ebp-14h]

  (*(void (__thiscall **)(CSimpleBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v8 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v8, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  *((_BYTE *)a3 + 715) = CPlayerManager::Color(v4);
  v5 = IEntity::OwnerId((unsigned __int8 *)a2);
  IBuildingRole::MiniFlag(this, a3, v5);
  result = this;
  if ( *((_BYTE *)this + 29) != 1 )
    return result;
  result = (CSimpleBuildingRole *)IEntity::Type((unsigned __int16 *)a2);
  if ( result != (CSimpleBuildingRole *)27 )
    return result;
  v7 = (CSettler *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 4));
  return (CSimpleBuildingRole *)CSettler::GetPatchGfx(v7, (struct SGfxObjectInfo *)((char *)a3 + 200));
}


// address=[0x151b340]
// Decompiled from void __thiscall CSimpleBuildingRole::Init(CSimpleBuildingRole *this, IAnimatedEntity *a2)
void  CSimpleBuildingRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // [esp-8h] [ebp-Ch]

  IBuildingRole::InitCommon((int)a2);
  LOBYTE(this[1].__vftable) = 0;
  this->field_1C = 0;
  this->byte4 = 1;
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
  if ( IEntity::FlagBits(a2, EntityFlag_Selected) )
    this->FillDialog(this, a2, 0);
}


// address=[0x151b420]
// Decompiled from CSimpleBuildingRole *__thiscall CSimpleBuildingRole::PostLoadInit(CSimpleBuildingRole *this, struct CBuilding *a2)
void  CSimpleBuildingRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  CSimpleBuildingRole *result; // eax
  int v4; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  v6 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v6);
  result = (CSimpleBuildingRole *)IEntity::Type((unsigned __int16 *)a2);
  if ( result == (CSimpleBuildingRole *)27 )
  {
    *((_DWORD *)this + 8) = 0;
  }
  else
  {
    v5 = *(char *)(*((_DWORD *)this + 94) + 478);
    v4 = IEntity::Race(a2);
    CSettlerMgr::GetSettlerInfo(v4, v5);
    *((_DWORD *)this + 8) = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](1);
    result = this;
    if ( !*((_DWORD *)this + 8) )
    {
      result = (CSimpleBuildingRole *)BBSupportDbgReport(
                                        2,
                                        "MapObjects\\Building\\SimpleBuilding.cpp",
                                        115,
                                        "m_pSearchFkt != 0");
      if ( result == (CSimpleBuildingRole *)1 )
        __debugbreak();
    }
  }
  return result;
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
    IEntity::SetFlagBits(v17, EntityFlag_MagicInvisible);
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
  IEntity::ClearFlagBits(v17, EntityFlag_Visible);
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
    byte_3F1E4B8 = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
    byte_3F1E4B9 = *((_DWORD *)this->m_pBuildingInfo + 123) > 0;
    v8 = IEntity::Type(a2);
    v3 = IEntity::OwnerId(a2);
    byte_3F1E4BB = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v8, 0);
    v9 = IEntity::Type(a2);
    v4 = IEntity::OwnerId(a2);
    byte_3F1E4BC = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v9, 1u);
    g_cBuildingInfo.m_unknownA = this->m_bInhabitants;
    if ( this->m_bInhabitants )
      byte_3F1E4BD = *((_BYTE *)this->m_pBuildingInfo + 478);
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
    dword_3F1E4E8 = 2;
    byte_3F1E4ED = IEntity::Race(a2);
    byte_3F1E4EC = IEntity::Type(a2);
    byte_3F1E4EF = 1;
    byte_3F1E4F0 = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
    byte_3F1E4F1 = *((_DWORD *)this->m_pBuildingInfo + 123) > 0;
    v10 = IEntity::Type(a2);
    v6 = IEntity::OwnerId(a2);
    byte_3F1E4F3 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v6, v10, 0);
    v11 = IEntity::Type(a2);
    v7 = IEntity::OwnerId(a2);
    byte_3F1E4F4 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v7, v11, 1u);
    byte_3F1E4EE = this->m_bInhabitants;
    byte_3F1E4F9 = 0;
    byte_3F1E4F8 = 0;
    if ( this->m_bInhabitants )
      byte_3F1E4F5 = *((_BYTE *)this->m_pBuildingInfo + 478);
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


