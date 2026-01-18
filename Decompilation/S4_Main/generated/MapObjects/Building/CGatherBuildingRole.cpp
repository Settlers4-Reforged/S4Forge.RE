#include "CGatherBuildingRole.h"

// Definitions for class CGatherBuildingRole

// address=[0x1400c20]
// Decompiled from int __cdecl CGatherBuildingRole::New(int a1)
class CPersistence * __cdecl CGatherBuildingRole::New(std::istream & a1) {
  
  if ( operator new(0x180u) )
    return CGatherBuildingRole::CGatherBuildingRole(a1);
  else
    return 0;
}


// address=[0x14fc9d0]
// Decompiled from CGatherBuildingRole *__thiscall CGatherBuildingRole::CGatherBuildingRole(CGatherBuildingRole *this)
 CGatherBuildingRole::CGatherBuildingRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CGatherBuildingRole::_vftable_;
  return this;
}


// address=[0x14fcc30]
// Decompiled from int __thiscall CGatherBuildingRole::~CGatherBuildingRole(CGatherBuildingRole *this)
 CGatherBuildingRole::~CGatherBuildingRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd0e0]
// Decompiled from int __thiscall CGatherBuildingRole::ClassID(CGatherBuildingRole *this)
unsigned long  CGatherBuildingRole::ClassID(void)const {
  
  return CGatherBuildingRole::m_iClassID;
}


// address=[0x14fd380]
// Decompiled from void *__thiscall CGatherBuildingRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CGatherBuildingRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x14fd4c0]
// Decompiled from int __thiscall CGatherBuildingRole::GetBuildingRole(CTaskDialog *this)
int  CGatherBuildingRole::GetBuildingRole(void) {
  
  return 6;
}


// address=[0x14fd620]
// Decompiled from int __thiscall CGatherBuildingRole::GetPileIdWithGood(CGatherBuildingRole *this, int a2)
int  CGatherBuildingRole::GetPileIdWithGood(int a2)const {
  
  return *((unsigned __int16 *)this + 190);
}


// address=[0x14fd710]
// Decompiled from void __thiscall CGatherBuildingRole::GoodArrive(CGatherBuildingRole *this, int a2)
void  CGatherBuildingRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x14fda30]
// Decompiled from int __cdecl CGatherBuildingRole::Load(int a1)
class CGatherBuildingRole * __cdecl CGatherBuildingRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CGatherBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x150b5b0]
// Decompiled from int __thiscall CGatherBuildingRole::LogicUpdate(CGatherBuildingRole *this, struct CBuilding *a2)
void  CGatherBuildingRole::LogicUpdate(class CBuilding * a2) {
  
  int result; // eax
  int WorkingAreaPackedXY; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-10h] [ebp-7Ch]
  int v9; // [esp-Ch] [ebp-78h]
  int v10; // [esp-8h] [ebp-74h]
  int v11; // [esp-4h] [ebp-70h]
  int v12; // [esp-4h] [ebp-70h]
  _BYTE v13[24]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v14[24]; // [esp+1Ch] [ebp-50h] BYREF
  CEntityEvent *v15; // [esp+34h] [ebp-38h]
  CEntityEvent *v16; // [esp+38h] [ebp-34h]
  CEntityEvent *v17; // [esp+3Ch] [ebp-30h]
  CEntityEvent *v18; // [esp+40h] [ebp-2Ch]
  int v19; // [esp+44h] [ebp-28h]
  unsigned __int8 *v20; // [esp+48h] [ebp-24h]
  unsigned __int8 *v21; // [esp+4Ch] [ebp-20h]
  char v22; // [esp+50h] [ebp-1Ch]
  int NearestAnimal; // [esp+54h] [ebp-18h]
  _DWORD *v24; // [esp+58h] [ebp-14h]
  CGatherBuildingRole *v25; // [esp+5Ch] [ebp-10h]
  int v26; // [esp+68h] [ebp-4h]

  v25 = this;
  result = IEntity::FlagBits(a2, EntityFlag_Selected);
  if ( result )
    result = (*(int (__thiscall **)(CGatherBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v25 + 88))(v25, a2, 1);
  v22 = *((_BYTE *)v25 + 4);
  if ( v22 == 1 )
  {
    result = (*(unsigned __int8 (__thiscall **)(CGatherBuildingRole *, struct CBuilding *))(*(_DWORD *)v25 + 120))(
               v25,
               a2);
    if ( !(_BYTE)result )
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    *((_BYTE *)v25 + 4) = 3;
    return result;
  }
  if ( v22 != 2 )
  {
    if ( v22 != 3 )
      return result;
    *((_WORD *)v25 + 6) = 0;
    *((_DWORD *)v25 + 4) = 0;
    if ( *((_BYTE *)v25 + 29) )
    {
      if ( IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
      {
        v20 = CPileMgr::operator[](*((unsigned __int16 *)v25 + 190));
        if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v20 + 40))(v20) < 8 )
        {
          if ( IEntity::Type((unsigned __int16 *)a2) == 7 )
          {
            v11 = CBuilding::EcoSectorId(a2);
            v9 = *(_DWORD *)(*((_DWORD *)v25 + 94) + 492);
            WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(a2);
            v8 = Y16X16::UnpackYFast(WorkingAreaPackedXY);
            v4 = CBuilding::GetWorkingAreaPackedXY(a2);
            v5 = Y16X16::UnpackXFast(v4);
            NearestAnimal = CScanner::FindNearestAnimal(v5, v8, v9, 1, v11);
            if ( NearestAnimal != -1 )
            {
              v12 = Y16X16::UnpackYFast(NearestAnimal);
              v6 = Y16X16::UnpackXFast(NearestAnimal);
              v19 = CWorldManager::MapObjectId(v6, v12);
              v21 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v19);
              if ( v21 )
              {
                if ( IEntity::ObjType(v21) == 128 && IEntity::FlagBits(v21, (EntityFlag)&loc_3000000) )
                {
                  *((_WORD *)v25 + 6) = v19;
                  *((_DWORD *)v25 + 4) = NearestAnimal;
                }
              }
            }
          }
          else
          {
            (*(void (__thiscall **)(CGatherBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)v25 + 104))(
              v25,
              a2,
              0);
          }
        }
      }
    }
    if ( !*((_DWORD *)v25 + 4) )
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    v24 = (_DWORD *)CSettlerMgr::operator[](*((unsigned __int16 *)v25 + 4));
    IEntity::ClearFlagBits(v24, EntityFlag_Visible);
    v10 = Y16X16::UnpackYFast(*((_DWORD *)v25 + 4));
    v7 = Y16X16::UnpackXFast(*((_DWORD *)v25 + 4));
    CWorldManager::SetFlagBits(v7, v10, 32);
    if ( *((_WORD *)v25 + 6) )
    {
      v16 = CEntityEvent::CEntityEvent(
              (CEntityEvent *)v13,
              5u,
              0,
              0,
              *((unsigned __int16 *)v25 + 6),
              *((_DWORD *)v25 + 4));
      v15 = v16;
      v26 = 1;
      (*(void (__thiscall **)(_DWORD *, CEntityEvent *))(*v24 + 80))(v24, v16);
      v26 = -1;
      return CEntityEvent::~CEntityEvent(v13);
    }
    else
    {
      v18 = CEntityEvent::CEntityEvent((CEntityEvent *)v14, 6u, 0, 0, 0, *((_DWORD *)v25 + 4));
      v17 = v18;
      v26 = 0;
      (*(void (__thiscall **)(_DWORD *, CEntityEvent *))(*v24 + 80))(v24, v18);
      v26 = -1;
      return CEntityEvent::~CEntityEvent(v14);
    }
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  }
  if ( *((unsigned __int8 *)v25 + 5) > (int)*(unsigned __int8 *)(*((_DWORD *)v25 + 94) + 480) )
  {
    *((_BYTE *)v25 + 5) = 0;
    *((_BYTE *)v25 + 4) = 3;
    return IAnimatedEntity::RegisterForLogicUpdate(1);
  }
  else
  {
    ++*((_BYTE *)v25 + 5);
    return IAnimatedEntity::RegisterForLogicUpdate(14);
  }
}


// address=[0x150b910]
// Decompiled from CPile *__thiscall CGatherBuildingRole::FillGfxInfo(  CGatherBuildingRole *this,  struct CBuilding *a2,  struct SGfxObjectInfo *a3)
void  CGatherBuildingRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  CPile *result; // eax
  unsigned __int8 *v7; // eax
  int v8; // [esp-Ch] [ebp-10h]

  (*(void (__thiscall **)(CGatherBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v8 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v8, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  IBuildingRole::MiniFlag(this, a3, v4);
  v5 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  result = (CPile *)(unsigned __int8)CPile::IsPatchPile(v5);
  if ( !(_BYTE)result )
    return result;
  v7 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  return CPile::GetPatchGfx((CPile *)v7, (struct SGfxObjectInfo *)((char *)a3 + 536));
}


// address=[0x150b9c0]
// Decompiled from int __thiscall CGatherBuildingRole::Init(CGatherBuildingRole *this, struct CBuilding *a2)
void  CGatherBuildingRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax
  int result; // eax
  int v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]
  int v10; // [esp+0h] [ebp-Ch]

  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 4) = 1;
  *((_BYTE *)this + 28) = 0;
  *((_WORD *)this + 190) = 0;
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 57) != 1
    && BBSupportDbgReport(2, "MapObjects\\Building\\GatherBuilding.cpp", 132, "m_pBuildingInfo->iPilesNumber == 1") == 1 )
  {
    __debugbreak();
  }
  v2 = IEntity::WorldIdx();
  v10 = *(char *)(*((_DWORD *)this + 94) + 60) + CWorldManager::X(v2);
  v3 = IEntity::WorldIdx();
  v4 = CWorldManager::Y(v3);
  *((_WORD *)this + 190) = CPileMgr::AddPile(
                             (CPileMgr *)&g_cPileMgr,
                             v10,
                             *(char *)(*((_DWORD *)this + 94) + 61) + v4,
                             *(char *)(*((_DWORD *)this + 94) + 62),
                             0,
                             *(char *)(*((_DWORD *)this + 94) + 63),
                             0,
                             0,
                             0,
                             0);
  if ( !*((_WORD *)this + 190)
    && BBSupportDbgReport(2, "MapObjects\\Building\\GatherBuilding.cpp", 137, "m_uProdPileId != 0") == 1 )
  {
    __debugbreak();
  }
  v9 = IEntity::ID();
  v5 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  CPile::SetBuildingId((CPile *)v5, v9);
  v8 = *(char *)(*((_DWORD *)this + 94) + 478);
  v6 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v6, v8);
  *((_DWORD *)this + 8) = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](0);
  if ( !*((_DWORD *)this + 8)
    && BBSupportDbgReport(2, "MapObjects\\Building\\GatherBuilding.cpp", 144, "m_pSearchFkt != 0") == 1 )
  {
    __debugbreak();
  }
  IAnimatedEntity::RegisterForLogicUpdate(2);
  result = IEntity::FlagBits(a2, EntityFlag_Selected);
  if ( result )
    return (*(int (__thiscall **)(CGatherBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(
             this,
             a2,
             0);
  return result;
}


// address=[0x150bbc0]
// Decompiled from int __thiscall CGatherBuildingRole::PostLoadInit(CGatherBuildingRole *this, struct CBuilding *a2)
void  CGatherBuildingRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  int result; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  v6 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v6);
  v5 = *(char *)(*((_DWORD *)this + 94) + 478);
  v3 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v3, v5);
  result = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](0);
  *((_DWORD *)this + 8) = result;
  if ( *((_DWORD *)this + 8) )
    return result;
  result = BBSupportDbgReport(2, "MapObjects\\Building\\GatherBuilding.cpp", 112, "m_pSearchFkt != 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x150bc50]
// Decompiled from char __thiscall CGatherBuildingRole::SettlerEnter(CGatherBuildingRole *this, struct CBuilding *a2, int a3)
bool  CGatherBuildingRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  int v3; // eax
  void *v4; // eax
  int v5; // eax
  const char *BuildingName; // eax
  const char *v8; // [esp-8h] [ebp-10h]
  const char *RaceName; // [esp-4h] [ebp-Ch]
  _DWORD *v10; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 29) = 1;
  *((_WORD *)this + 4) = a3;
  v10 = (_DWORD *)CSettlerMgr::operator[](a3);
  IEntity::ClearFlagBits(v10, EntityFlag_Visible);
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 480) )
  {
    *((_BYTE *)this + 5) = 0;
    IAnimatedEntity::RegisterForLogicUpdate(14);
    *((_BYTE *)this + 4) = 2;
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
    BBSupportTracePrintF(
      2,
      "WARNING: Building %s (role %s) of race %s has no production delay!",
      BuildingName,
      v8,
      RaceName);
  }
  return 1;
}


// address=[0x150bd10]
// Decompiled from _DWORD *__thiscall CGatherBuildingRole::FillDialog(CGatherBuildingRole *this, struct CBuilding *a2, bool a3)
void  CGatherBuildingRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-48h]
  int v7; // [esp-8h] [ebp-48h]
  unsigned int v8; // [esp+4h] [ebp-3Ch]
  unsigned __int8 *v9; // [esp+8h] [ebp-38h]
  unsigned __int8 *v10; // [esp+Ch] [ebp-34h]
  CEvn_Event v12; // [esp+18h] [ebp-28h] BYREF
  int v13; // [esp+3Ch] [ebp-4h]

  dword_3F1E4E8 = 2;
  byte_3F1E4ED = IEntity::Race(a2);
  byte_3F1E4EC = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E4EF = 1;
  byte_3F1E4F0 = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E4F1 = 1;
  v6 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4F3 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v6, 0);
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4F4 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v7, 1u);
  byte_3F1E4F2 = -1;
  byte_3F1E4EE = *((_BYTE *)this + 29);
  if ( *((_BYTE *)this + 29) )
    byte_3F1E4F5 = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  v10 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  byte_3F1E4F9 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v10 + 40))(v10);
  v9 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  byte_3F1E4F8 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v9 + 60))(v9);
  v8 = 604;
  if ( !a3 )
    v8 = 602;
  CEvn_Event::CEvn_Event(&v12, v8, 0, (unsigned int)&g_cResourceCollectorInfo, 0);
  v13 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v12);
  v13 = -1;
  return CEvn_Event::~CEvn_Event(&v12);
}


// address=[0x150bed0]
// Decompiled from char *__thiscall CGatherBuildingRole::CGatherBuildingRole(char *this, int a2)
 CGatherBuildingRole::CGatherBuildingRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CGatherBuildingRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CGatherBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned short>(a2, v5 + 380);
  v6 = -1;
  return v5;
}


// address=[0x150bf90]
// Decompiled from int __thiscall CGatherBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CGatherBuildingRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned short>((int)a2, (__int16 *)v4 + 190);
}


// address=[0x3d8b134]
// [Decompilation failed for static unsigned long CGatherBuildingRole::m_iClassID]

// address=[0x14fd210]
// Decompiled from void __thiscall CGatherBuildingRole::ConvertEventIntoGoal(  CGatherBuildingRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CGatherBuildingRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x14fde40]
// Decompiled from char __thiscall CGatherBuildingRole::TryCrushBuilding(CGatherBuildingRole *this)
bool  CGatherBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


// address=[0x150bfe0]
// Decompiled from char __thiscall CGatherBuildingRole::CrushBuilding(CGatherBuildingRole *this)
bool  CGatherBuildingRole::CrushBuilding(void) {
  
  return 1;
}


