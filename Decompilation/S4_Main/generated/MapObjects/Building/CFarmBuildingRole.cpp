#include "CFarmBuildingRole.h"

// Definitions for class CFarmBuildingRole

// address=[0x1400900]
// Decompiled from int __cdecl CFarmBuildingRole::New(int a1)
class CPersistence * __cdecl CFarmBuildingRole::New(std::istream & a1) {
  
  if ( operator new(0x180u) )
  {
    return CFarmBuildingRole::CFarmBuildingRole(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14fc9a0]
// Decompiled from CFarmBuildingRole *__thiscall CFarmBuildingRole::CFarmBuildingRole(CFarmBuildingRole *this)
 CFarmBuildingRole::CFarmBuildingRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CFarmBuildingRole::_vftable_;
  return this;
}


// address=[0x14fcc10]
// Decompiled from int __thiscall CFarmBuildingRole::~CFarmBuildingRole(CFarmBuildingRole *this)
 CFarmBuildingRole::~CFarmBuildingRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd0c0]
// Decompiled from int __thiscall CFarmBuildingRole::ClassID(CFarmBuildingRole *this)
unsigned long  CFarmBuildingRole::ClassID(void)const {
  
  return CFarmBuildingRole::m_iClassID;
}


// address=[0x14fd360]
// Decompiled from void *__thiscall CFarmBuildingRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CFarmBuildingRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x14fd4a0]
// Decompiled from int __thiscall CFarmBuildingRole::GetBuildingRole(CFarmBuildingRole *this)
int  CFarmBuildingRole::GetBuildingRole(void) {
  
  return 8;
}


// address=[0x14fd600]
// Decompiled from int __thiscall CFarmBuildingRole::GetPileIdWithGood(CFarmBuildingRole *this, int a2)
int  CFarmBuildingRole::GetPileIdWithGood(int a2)const {
  
  return *((unsigned __int16 *)this + 190);
}


// address=[0x14fd700]
// Decompiled from void __thiscall CFarmBuildingRole::GoodArrive(CFarmBuildingRole *this, int a2)
void  CFarmBuildingRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x14fd9f0]
// Decompiled from int __cdecl CFarmBuildingRole::Load(int a1)
class CFarmBuildingRole * __cdecl CFarmBuildingRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CFarmBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x150a5e0]
// Decompiled from void __thiscall CFarmBuildingRole::LogicUpdate(CFarmBuildingRole *this, struct CBuilding *_pBuilding)
void  CFarmBuildingRole::LogicUpdate(class CBuilding * _pBuilding) {
  
  int v2; // eax
  CSettlerMgr::SSettlerInfos *SettlerInfo; // eax
  int v4; // eax
  CSettlerMgr::SSettlerInfos *v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // esi
  int v9; // eax
  int m_iBuildingInhabitant; // [esp-8h] [ebp-84h]
  int v11; // [esp-8h] [ebp-84h]
  int v12; // [esp-4h] [ebp-80h]
  char v13; // [esp-4h] [ebp-80h]
  CEntityEvent v14; // [esp+8h] [ebp-74h] BYREF
  CEntityEvent v15; // [esp+20h] [ebp-5Ch] BYREF
  CEntityEvent *v16; // [esp+38h] [ebp-44h]
  CEntityEvent *v17; // [esp+3Ch] [ebp-40h]
  CEntityEvent *v18; // [esp+40h] [ebp-3Ch]
  CEntityEvent *v19; // [esp+44h] [ebp-38h]
  CSettler *v20; // [esp+48h] [ebp-34h]
  T_OBJECT_TYPE ObjectType; // [esp+4Ch] [ebp-30h]
  unsigned int v22; // [esp+50h] [ebp-2Ch]
  unsigned int v23; // [esp+54h] [ebp-28h]
  CPile *v24; // [esp+58h] [ebp-24h]
  CSettlerMgr::SSettlerInfos *v25; // [esp+5Ch] [ebp-20h]
  CSettler *v26; // [esp+60h] [ebp-1Ch]
  unsigned __int8 byte4; // [esp+64h] [ebp-18h]
  IEntity *v28; // [esp+68h] [ebp-14h]
  int v30; // [esp+78h] [ebp-4h]

  if ( IEntity::FlagBits(_pBuilding, ENTITY_FLAG_Selected) )
  {
    this->FillDialog(this, _pBuilding, 1);
  }
  byte4 = this->m_uLogicState;
  if ( byte4 == 1 )
  {
    if ( this->OrderInhabitant(this, _pBuilding) )
    {
      this->m_uLogicState = 3;
      return;
    }
    goto LABEL_26;
  }
  if ( byte4 != 2 )
  {
    if ( byte4 != 3 )
    {
      return;
    }
    if ( this->m_bInhabitants && IEntity::FlagBits(_pBuilding, (EntityFlag)4096) )
    {
      m_iBuildingInhabitant = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
      v2 = IEntity::Race(_pBuilding);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v2, m_iBuildingInhabitant);
      this->m_pSearchFkt = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 0)->m_pSearchFkt;
      if ( !this->m_pSearchFkt && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 268, "m_pSearchFkt != 0") == 1 )
      {
        __debugbreak();
      }
      v24 = CPileMgr::operator[](LOWORD(this->m_iPileId));
      if ( v24->Amount(v24) < 8 && this->SearchInWorkingArea(this, _pBuilding, 0) )
      {
        v26 = CSettlerMgr::operator[](this->m_uSettlerId);
        IEntity::SetFlagBits(v26, ENTITY_FLAG_Visible);
        v19 = CEntityEvent::CEntityEvent(&v15, 5u, 0, 0, this->m_iFoundSearch, this->m_iFoundWorkAreaItemXY);
        v18 = v19;
        v30 = 0;
        v26->SetEvent(v26, v19);
        v30 = -1;
        CEntityEvent::~CEntityEvent(&v15);
        this->LockPiles(this, _pBuilding, 1);
        return;
      }
      v11 = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
      v4 = IEntity::Race(_pBuilding);
      v5 = CSettlerMgr::GetSettlerInfo(v4, v11);
      this->m_pSearchFkt = std::vector<CSettlerMgr::SSearchInfos>::operator[](&v5->m_vSearches, 1u)->m_pSearchFkt;
      if ( !this->m_pSearchFkt && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 297, "m_pSearchFkt != 0") == 1 )
      {
        __debugbreak();
      }
      if ( this->SearchInWorkingArea(this, _pBuilding, 1) )
      {
        v28 = CSettlerMgr::operator[](this->m_uSettlerId);
        v12 = IEntity::Type(v28);
        v6 = IEntity::Race(v28);
        v25 = CSettlerMgr::GetSettlerInfo(v6, v12);
        v7 = Y16X16::UnpackXFast(this->m_iFoundWorkAreaItemXY);
        v22 = v7 - std::vector<CSettlerMgr::SSearchInfos>::operator[](&v25->m_vSearches, 1u)->m_iOffsetX;
        v8 = Y16X16::UnpackYFast(this->m_iFoundWorkAreaItemXY);
        v23 = v8 - std::vector<CSettlerMgr::SSearchInfos>::operator[](&v25->m_vSearches, 1u)->m_iOffsetY;
        v13 = CWorldManager::Ground(v22, v23);
        v9 = IEntity::Race(v28);
        ObjectType = CDecoObjMgr::GetObjectType(&g_cDecoObjMgr, v25->m_uFarmerType, v9, v13);
        CDecoObjMgr::SetFlagsForObject(&g_cDecoObjMgr, v22, v23, ObjectType, 0);
        IEntity::SetFlagBits(v28, ENTITY_FLAG_Visible);
        v20 = CSettlerMgr::operator[](this->m_uSettlerId);
        v17 = CEntityEvent::CEntityEvent(&v14, 6u, 0, 0, ObjectType, this->m_iFoundWorkAreaItemXY);
        v16 = v17;
        v30 = 1;
        v20->SetEvent(v20, v17);
        v30 = -1;
        CEntityEvent::~CEntityEvent(&v14);
        this->LockPiles(this, _pBuilding, 1);
        return;
      }
    }
LABEL_26:
    IAnimatedEntity::RegisterForLogicUpdate(_pBuilding, 31);
    return;
  }
  if ( this->m_iDelayTick > (int)this->m_pBuildingInfo->m_iProductionDelay )
  {
    this->m_iDelayTick = 0;
    this->m_uLogicState = 3;
    IAnimatedEntity::RegisterForLogicUpdate(_pBuilding, 1);
  }
  else
  {
    ++this->m_iDelayTick;
    IAnimatedEntity::RegisterForLogicUpdate(_pBuilding, 14);
  }
}


// address=[0x150aa20]
// Decompiled from int __thiscall CFarmBuildingRole::FillGfxInfo(CFarmBuildingRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CFarmBuildingRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  int result; // eax
  unsigned __int8 *v7; // eax
  int v8; // [esp-Ch] [ebp-14h]

  (*(void (__thiscall **)(CFarmBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v8 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v8, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  IBuildingRole::MiniFlag(this, a3, v4);
  v5 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  result = (unsigned __int8)CPile::IsPatchPile(v5);
  if ( !(_BYTE)result )
  {
    return result;
  }
  v7 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  CPile::GetPatchGfx((CPile *)v7, (struct SGfxObjectInfo *)((char *)a3 + 536));
  return 1;
}


// address=[0x150aae0]
// Decompiled from int __thiscall CFarmBuildingRole::Init(_BYTE *this, _BYTE *a2)
void  CFarmBuildingRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // [esp-8h] [ebp-14h]
  int v11; // [esp-8h] [ebp-14h]
  int v12; // [esp-4h] [ebp-10h]
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+4h] [ebp-8h]

  IBuildingRole::InitCommon((int)a2);
  this[4] = 1;
  this[28] = 0;
  *((_WORD *)this + 190) = 0;
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 57) != 1 && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 133, "m_pBuildingInfo->iPilesNumber == 1") == 1 )
  {
    __debugbreak();
  }
  v2 = IEntity::WorldIdx();
  v13 = *(char *)(*((_DWORD *)this + 94) + 60) + CWorldManager::X(v2);
  v3 = IEntity::WorldIdx();
  v14 = *(char *)(*((_DWORD *)this + 94) + 61) + CWorldManager::Y(v3);
  *((_WORD *)this + 190) = CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v13, v14, *(char *)(*((_DWORD *)this + 94) + 62), 0, *(char *)(*((_DWORD *)this + 94) + 63), *(char *)(*((_DWORD *)this + 94) + 64), *(char *)(*((_DWORD *)this + 94) + 65), *(_DWORD *)(*((_DWORD *)this + 94) + 68), *(_DWORD *)(*((_DWORD *)this + 94) + 72));
  if ( !*((_WORD *)this + 190) && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 150, "m_uProdPileId != 0") == 1 )
  {
    __debugbreak();
  }
  v12 = IEntity::ID();
  v4 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  CPile::SetBuildingId((CPile *)v4, v12);
  v5 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  if ( (unsigned __int8)CPile::IsPatchPile(v5) )
  {
    v6 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
    IEntity::ClearFlagBits(v6, ENTITY_FLAG_Visible);
  }
  v10 = *(char *)(*((_DWORD *)this + 94) + 478);
  v7 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v7, v10);
  *((_DWORD *)this + 8) = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](0);
  if ( !*((_DWORD *)this + 8) && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 162, "m_pSearchFkt != 0") == 1 )
  {
    __debugbreak();
  }
  v11 = *(char *)(*((_DWORD *)this + 94) + 478);
  v8 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v8, v11);
  *((_DWORD *)this + 8) = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](1);
  if ( !*((_DWORD *)this + 8) && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 165, "m_pSearchFkt != 0") == 1 )
  {
    __debugbreak();
  }
  IAnimatedEntity::RegisterForLogicUpdate(2);
  result = IEntity::FlagBits(a2, ENTITY_FLAG_Selected);
  if ( result )
  {
    return (*(int (__thiscall **)(_BYTE *, _BYTE *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  }
  return result;
}


// address=[0x150add0]
// Decompiled from int __thiscall CFarmBuildingRole::PostLoadInit(_DWORD *this, unsigned __int16 *a2)
void  CFarmBuildingRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type(a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  this[94] = result;
  return result;
}


// address=[0x150ae00]
// Decompiled from _DWORD *__thiscall CFarmBuildingRole::LockPiles(CFarmBuildingRole *this, struct CBuilding *a2, bool a3)
void  CFarmBuildingRole::LockPiles(class CBuilding * a2, bool a3) {
  
  unsigned __int8 *v3; // eax

  v3 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  if ( a3 )
  {
    return IEntity::SetFlagBits(v3, (EntityFlag)0x10u);
  }
  else
  {
    return (_DWORD *)IEntity::ClearFlagBits(v3, (EntityFlag)0x10u);
  }
}


// address=[0x150ae60]
// Decompiled from char __thiscall CFarmBuildingRole::SettlerEnter(CFarmBuildingRole *this, struct CBuilding *a2, int a3)
bool  CFarmBuildingRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  int v3; // eax
  void *v4; // eax
  int v5; // eax
  const char *BuildingName; // eax
  const char *v8; // [esp-8h] [ebp-10h]
  const char *RaceName; // [esp-4h] [ebp-Ch]
  _DWORD *v10; // [esp+0h] [ebp-8h]

  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 185, "_iSettlerId > 0") == 1 )
  {
    __debugbreak();
  }
  v10 = (_DWORD *)CSettlerMgr::operator[](a3);
  if ( *((_BYTE *)this + 29) )
  {
    if ( *((unsigned __int16 *)this + 4) != a3 && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 196, "m_uSettlerId == _iSettlerId") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    *((_BYTE *)this + 29) = 1;
    *((_WORD *)this + 4) = a3;
  }
  IEntity::ClearFlagBits(v10, ENTITY_FLAG_Visible);
  IMovingEntity::SetDisplacementCosts(10);
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 480) )
  {
    *((_BYTE *)this + 5) = 0;
    IAnimatedEntity::RegisterForLogicUpdate(14);
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(31);
    v3 = IEntity::Race(a2);
    RaceName = CS4DefineNames::GetRaceName(v3);
    v4 = (void *)typeid(this);
    v8 = (const char *)type_info::name(v4);
    v5 = IEntity::Type((unsigned __int16 *)a2);
    BuildingName = CS4DefineNames::GetBuildingName(v5);
    BBSupportTracePrintF(2, "WARNING: Building %s (role %s) of race %s has no production delay!", BuildingName, v8, RaceName);
  }
  *((_BYTE *)this + 4) = 2;
  (*(void (__thiscall **)(CFarmBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 72))(this, a2, 0);
  return 1;
}


// address=[0x150afa0]
// Decompiled from _DWORD *__thiscall CFarmBuildingRole::FillDialog(CFarmBuildingRole *this, struct CBuilding *a2, bool a3)
void  CFarmBuildingRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  S4_BUILDING_ENUM v6; // [esp-8h] [ebp-48h]
  S4_BUILDING_ENUM v7; // [esp-8h] [ebp-48h]
  unsigned int v8; // [esp+4h] [ebp-3Ch]
  CPile *v9; // [esp+8h] [ebp-38h]
  CPile *v10; // [esp+Ch] [ebp-34h]
  CEvn_Event v12; // [esp+18h] [ebp-28h] BYREF
  int v13; // [esp+3Ch] [ebp-4h]

  g_cResourceCollectorInfo.m_iUnknown = 2;
  g_cResourceCollectorInfo.m_cRace = IEntity::Race(a2);
  g_cResourceCollectorInfo.m_cType = IEntity::Type(a2);
  g_cResourceCollectorInfo.m_unknownB = 1;
  g_cResourceCollectorInfo.m_bSomeFlagBits = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
  g_cResourceCollectorInfo.m_bHasWorkingArea = 1;
  v6 = IEntity::Type(a2);
  v3 = IEntity::OwnerId(a2);
  g_cResourceCollectorInfo.m_cTotalCount = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v6, 0);
  v7 = IEntity::Type(a2);
  v4 = IEntity::OwnerId(a2);
  g_cResourceCollectorInfo.m_cTotalBuiltCount = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v7, 1u);
  g_cResourceCollectorInfo.m_bInhabitants = this->m_bInhabitants;
  if ( this->m_bInhabitants )
  {
    g_cResourceCollectorInfo.m_iSettlerCount = this->m_pBuildingInfo->m_iBuildingInhabitant;
  }
  v10 = CPileMgr::operator[](this->m_iPileId);
  g_cResourceCollectorInfo.m_uAmount = v10->Amount(v10);
  v9 = CPileMgr::operator[](this->m_iPileId);
  g_cResourceCollectorInfo.m_uGood = v9->GetGoodType();
  v8 = 604;
  if ( !a3 )
  {
    v8 = 602;
  }
  CEvn_Event::CEvn_Event(&v12, v8, 0, (unsigned int)&g_cResourceCollectorInfo, 0);
  v13 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v12);
  v13 = -1;
  return CEvn_Event::~CEvn_Event(&v12);
}


// address=[0x150b160]
// Decompiled from char *__thiscall CFarmBuildingRole::CFarmBuildingRole(char *this, int a2)
 CFarmBuildingRole::CFarmBuildingRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CFarmBuildingRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CFarmBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned short>(a2, v5 + 380);
  v6 = -1;
  return v5;
}


// address=[0x150b220]
// Decompiled from int __thiscall CFarmBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CFarmBuildingRole::Store(std::ostream & a2) {
  
  unsigned int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned short>(a2, (WORD *)&v4[1]);
}


// address=[0x3d8b130]
// [Decompilation failed for static unsigned long CFarmBuildingRole::m_iClassID]

// address=[0x14fd200]
// Decompiled from void __stdcall CFarmBuildingRole::ConvertEventIntoGoal(int a1, int a2)
void  CFarmBuildingRole::ConvertEventIntoGoal(class CBuilding * a1, class CEntityEvent * a2) {
  
  ;
}


// address=[0x14fd280]
// Decompiled from char __thiscall CFarmBuildingRole::CrushBuilding(CFarmBuildingRole *this)
bool  CFarmBuildingRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14fde30]
// Decompiled from char __thiscall CFarmBuildingRole::TryCrushBuilding(CFarmBuildingRole *this)
bool  CFarmBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


