#include "CManakopterHallRole.h"

// Definitions for class CManakopterHallRole

// address=[0x14011c0]
// Decompiled from int __cdecl CManakopterHallRole::New(int a1)
class CPersistence * __cdecl CManakopterHallRole::New(std::istream & a1) {
  
  if ( operator new(0x198u) )
    return CManakopterHallRole::CManakopterHallRole(a1);
  else
    return 0;
}


// address=[0x14fdab0]
// Decompiled from int __cdecl CManakopterHallRole::Load(int a1)
class CManakopterHallRole * __cdecl CManakopterHallRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CManakopterHallRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x150c8f0]
// Decompiled from char *__thiscall CManakopterHallRole::CManakopterHallRole(char *this, int a2)
 CManakopterHallRole::CManakopterHallRole(std::istream & a2) {
  
  int v3; // [esp+4h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+Ch] [ebp-14h]
  char *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v7 = 0;
  *(_DWORD *)v6 = &CManakopterHallRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  *((_DWORD *)v6 + 101) = 0;
  v5 = v3;
  if ( v3 != 1 )
  {
    if ( v5 != 2 )
    {
      if ( v5 != 3 )
      {
        BBSupportTracePrintF(3, "Unknown version of CManakopterHallRole in input stream.");
        pExceptionObject = 0;
        CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
        _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
      }
      operator^<int>(a2, (int)(v6 + 392));
      operator^<int>(a2, (int)(v6 + 396));
      operator^<int>(a2, (int)(v6 + 400));
    }
    operator^<int>(a2, (int)(v6 + 404));
  }
  operator^<int>(a2, (int)(v6 + 380));
  operator^<int>(a2, (int)(v6 + 384));
  operator^<int>(a2, (int)(v6 + 388));
  v7 = -1;
  return v6;
}


// address=[0x150ca90]
// Decompiled from int __thiscall CManakopterHallRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CManakopterHallRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = (int *)this;
  IBuildingRole::Store(this, a2);
  v3 = 3;
  operator^<unsigned int>(a2, &v3);
  operator^<int>((int)a2, v4 + 98);
  operator^<int>((int)a2, v4 + 99);
  operator^<int>((int)a2, v4 + 100);
  operator^<int>((int)a2, v4 + 101);
  operator^<int>((int)a2, v4 + 95);
  operator^<int>((int)a2, v4 + 96);
  return operator^<int>((int)a2, v4 + 97);
}


// address=[0x150cb90]
// Decompiled from CManakopterHallRole *__thiscall CManakopterHallRole::CManakopterHallRole(CManakopterHallRole *this)
 CManakopterHallRole::CManakopterHallRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CManakopterHallRole::_vftable_;
  *((_DWORD *)this + 95) = 0;
  *((_DWORD *)this + 96) = 0;
  *((_DWORD *)this + 97) = 0;
  *((_DWORD *)this + 98) = 0;
  *((_DWORD *)this + 99) = 0;
  *((_DWORD *)this + 100) = 0;
  *((_DWORD *)this + 101) = 0;
  return this;
}


// address=[0x150cc40]
// Decompiled from int __thiscall CManakopterHallRole::~CManakopterHallRole(CManakopterHallRole *this)
 CManakopterHallRole::~CManakopterHallRole(void) {
  
  *(_DWORD *)this = &CManakopterHallRole::_vftable_;
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x150cc60]
// Decompiled from CManakopterHallRole *__thiscall CManakopterHallRole::LogicUpdate(CManakopterHallRole *this, struct CBuilding *a2)
void  CManakopterHallRole::LogicUpdate(class CBuilding * a2) {
  
  CManakopterHallRole *result; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  int v6; // esi
  int v7; // esi
  int v8; // eax
  int v9; // [esp-Ch] [ebp-2Ch]
  int v10; // [esp-8h] [ebp-28h]
  unsigned int v11; // [esp-4h] [ebp-24h]
  unsigned int v12; // [esp-4h] [ebp-24h]
  unsigned int v13; // [esp-4h] [ebp-24h]
  int v14; // [esp+Ch] [ebp-14h]
  char v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]

  result = this;
  v15 = *((_BYTE *)this + 4);
  switch ( v15 )
  {
    case 1:
      if ( BBSupportDbgReportF(
             2,
             "MapObjects\\Building\\ManakopterHallRole.cpp",
             210,
             "ManakopterHall got into state ORDER_IHABITANT_STATE!") == 1 )
        __debugbreak();
      return 0;
    case 2:
      if ( *((_DWORD *)this + 95) < *((_DWORD *)this + 96)
        && *((_DWORD *)this + 95) < *((_DWORD *)this + 97)
        && *((_DWORD *)this + 95) < CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredMana) )
      {
        ++*((_DWORD *)this + 95);
      }
      return (CManakopterHallRole *)IAnimatedEntity::RegisterForLogicUpdate(31);
    case 3:
      v17 = 0;
      v16 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredMana) - *((_DWORD *)this + 98);
      if ( CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredIron) - *((_DWORD *)this + 100) >= v16 )
      {
        v17 = 2;
        v16 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredIron) - *((_DWORD *)this + 100);
      }
      if ( CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredBoard) - *((_DWORD *)this + 99) >= v16 )
      {
        v17 = 1;
        v16 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredBoard) - *((_DWORD *)this + 99);
      }
      if ( v16 <= 0 )
      {
        v10 = IEntity::OwnerId((unsigned __int8 *)a2);
        v9 = CBuilding::EnsignY(a2);
        v8 = CBuilding::EnsignX(a2);
        CFlyingMgr::AddFlyingEntity((CFlyingMgr *)g_cFlyingMgr, 1, v8, v9, v10, 1);
        *((_DWORD *)this + 101) = 0;
        *((_DWORD *)this + 98) = 0;
        *((_DWORD *)this + 99) = 0;
        *((_DWORD *)this + 100) = 0;
        *((_BYTE *)this + 256) = 0;
        *((_BYTE *)this + 257) = 0;
        *((_BYTE *)this + 276) = 0;
        *((_BYTE *)this + 277) = 0;
        *((_BYTE *)this + 4) = 2;
        return (CManakopterHallRole *)IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      else
      {
        ++*((_DWORD *)this + v17 + 98);
        --*((_DWORD *)this + v17 + 95);
        *((_BYTE *)this + 256) = 1;
        *((_DWORD *)this + 29) = *((_DWORD *)this + 65);
        v11 = *((_DWORD *)this + 65);
        v3 = IEntity::Race(a2);
        *((_BYTE *)this + 264) = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v3, v11);
        *((_BYTE *)this + 257) = 0;
        *((_BYTE *)this + 259) = 0;
        *((_BYTE *)this + 265) = 0;
        *((_BYTE *)this + 276) = 1;
        *((_DWORD *)this + 31) = *((_DWORD *)this + 70);
        v12 = *((_DWORD *)this + 70);
        v4 = IEntity::Race(a2);
        *((_BYTE *)this + 284) = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v4, v12);
        *((_BYTE *)this + 277) = 0;
        *((_BYTE *)this + 279) = 0;
        *((_BYTE *)this + 285) = 0;
        v13 = *((_DWORD *)this + 55);
        v5 = IEntity::Race(a2);
        *((_BYTE *)this + 224) = CGfxManager::GetBuildingJobFrameCount((CGfxManager *)g_pGfxManager, v5, v13);
        v14 = *((unsigned __int8 *)this + 224) - 2;
        v6 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredMana);
        v7 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredBoard) + v6;
        *((_DWORD *)this + 101) = (*((_DWORD *)this + 100) + *((_DWORD *)this + 99) + *((_DWORD *)this + 98))
                                * v14
                                / (CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredIron) + v7);
        return (CManakopterHallRole *)IAnimatedEntity::RegisterForLogicUpdate(3 * *((unsigned __int8 *)this + 264) - 1);
      }
  }
  return result;
}


// address=[0x150d170]
// Decompiled from int __thiscall CManakopterHallRole::FillGfxInfo(  CManakopterHallRole *this,  struct CBuilding *a2,  struct SGfxObjectInfo *a3)
void  CManakopterHallRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-14h]

  *((_BYTE *)this + 265) = 3;
  *((_BYTE *)this + 285) = 3;
  (*(void (__thiscall **)(CManakopterHallRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  if ( *((_BYTE *)this + 4) == 3 )
  {
    *((_DWORD *)this + 25) = *((_DWORD *)this + 55);
    *((_DWORD *)this + 26) = *((_DWORD *)this + 101);
  }
  else
  {
    *((_DWORD *)this + 25) = 0;
    *((_DWORD *)this + 30) = 0;
    *((_DWORD *)this + 32) = 0;
  }
  *((_DWORD *)this + 19) = *((_DWORD *)this + 40);
  *((_DWORD *)this + 20) = *((_DWORD *)this + 95);
  v5 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  return CGfxManager::GetBuildingGfxInfo((int)a3, v3, v5, 1, (int)this + 76);
}


// address=[0x150d2b0]
// Decompiled from int __thiscall CManakopterHallRole::PostLoadInit(CManakopterHallRole *this, struct CBuilding *a2)
void  CManakopterHallRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x150d2e0]
// Decompiled from int __thiscall CManakopterHallRole::Init(CManakopterHallRole *this, struct CBuilding *a2)
void  CManakopterHallRole::Init(class CBuilding * a2) {
  
  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 4) = 2;
  *((_DWORD *)this + 95) = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredMana);
  *((_DWORD *)this + 96) = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredBoard);
  *((_DWORD *)this + 97) = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredIron);
  *((_DWORD *)this + 101) = 0;
  *((_DWORD *)this + 98) = 0;
  *((_DWORD *)this + 99) = 0;
  *((_DWORD *)this + 100) = 0;
  return IAnimatedEntity::RegisterForLogicUpdate(14);
}


// address=[0x150d3b0]
// Decompiled from char __thiscall CManakopterHallRole::SettlerEnter(CManakopterHallRole *this, struct CBuilding *a2, int a3)
bool  CManakopterHallRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  if ( BBSupportDbgReportF(
         2,
         "MapObjects\\Building\\ManakopterHallRole.cpp",
         194,
         "[MM] Settler tried to enter ManakopterHall!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x150d3f0]
// Decompiled from int __thiscall CManakopterHallRole::GoodArrive(CManakopterHallRole *this, int a2)
void  CManakopterHallRole::GoodArrive(int a2) {
  
  int result; // eax

  if ( a2 == 7 )
  {
    result = *((_DWORD *)this + 96) + 1;
    *((_DWORD *)this + 96) = result;
  }
  else if ( a2 == 20 )
  {
    result = 8;
    ++*((_DWORD *)this + 97);
  }
  else
  {
    if ( BBSupportDbgReportF(
           2,
           "MapObjects\\Building\\ManakopterHallRole.cpp",
           413,
           "Shaman teleported invalid good to MKH. See trace file.") == 1 )
      __debugbreak();
    return BBSupportTracePrintF(
             1,
             "Shaman teleported invalid good %s to ManakopterHall.",
             (const char *)dword_3786468[2 * a2]);
  }
  return result;
}


// address=[0x150d4c0]
// Decompiled from void __thiscall CManakopterHallRole::FillDialog(CManakopterHallRole *this, struct CBuilding *a2, bool a3)
void  CManakopterHallRole::FillDialog(class CBuilding *,bool) {
  
  ;
}


// address=[0x150d4d0]
// Decompiled from int __thiscall CManakopterHallRole::GetMostRequiredGood(CManakopterHallRole *this)
int  CManakopterHallRole::GetMostRequiredGood(void) {
  
  int v3; // [esp+Ch] [ebp-14h]
  int v4; // [esp+10h] [ebp-10h]
  int v5; // [esp+14h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-8h]

  v5 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredBoard) - *((_DWORD *)this + 96);
  v4 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredIron) - *((_DWORD *)this + 97);
  if ( v5 <= v4 )
    v6 = 20;
  else
    v6 = 7;
  if ( v6 == 7 )
    v3 = v5;
  else
    v3 = v4;
  if ( v3 <= 0 )
    return 0;
  else
    return v6;
}


// address=[0x150d570]
// Decompiled from int __thiscall CManakopterHallRole::TeleportGoods(CManakopterHallRole *this, int a2, int a3)
void  CManakopterHallRole::TeleportGoods(int a2, int a3) {
  
  int result; // eax

  if ( a2 == 7 )
  {
    result = a3 + *((_DWORD *)this + 96);
    *((_DWORD *)this + 96) = result;
  }
  else if ( a2 == 20 )
  {
    result = 8;
    *((_DWORD *)this + 97) += a3;
  }
  else
  {
    if ( BBSupportDbgReportF(
           2,
           "MapObjects\\Building\\ManakopterHallRole.cpp",
           464,
           "Shaman teleported invalid good to MKH. See trace file.") == 1 )
      __debugbreak();
    return BBSupportTracePrintF(
             1,
             "Shaman teleported %d invalid goods %s to ManakopterHall.",
             a3,
             (const char *)dword_3786468[2 * a2]);
  }
  return result;
}


// address=[0x150d640]
// Decompiled from char __thiscall CManakopterHallRole::TryMakingManakopter(CManakopterHallRole *this, struct CBuilding *a2)
bool  CManakopterHallRole::TryMakingManakopter(class CBuilding * a2) {
  
  int v3; // eax

  if ( *((_BYTE *)this + 4) == 3 )
    return 1;
  if ( *((_DWORD *)this + 95) < CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredMana) )
    return 0;
  if ( *((_DWORD *)this + 96) < CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredBoard) )
    return 0;
  if ( *((_DWORD *)this + 97) < CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredIron) )
    return 0;
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  if ( CFlyingMgr::GetFirstEntityId((CFlyingMgr *)g_cFlyingMgr, v3, 1) )
    return 0;
  *((_BYTE *)this + 4) = 3;
  IAnimatedEntity::RegisterForLogicUpdate(1);
  return 1;
}


// address=[0x150d6f0]
// Decompiled from char __thiscall CManakopterHallRole::CheatIfRequired(CManakopterHallRole *this, struct CBuilding *a2)
bool  CManakopterHallRole::CheatIfRequired(class CBuilding * a2) {
  
  int v2; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // [esp-10h] [ebp-28h]
  int v10; // [esp+4h] [ebp-14h] BYREF
  int v11; // [esp+8h] [ebp-10h] BYREF
  BOOL v12; // [esp+Ch] [ebp-Ch]
  CManakopterHallRole *v13; // [esp+10h] [ebp-8h]
  bool v15; // [esp+17h] [ebp-1h]

  v13 = this;
  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  if ( CFlyingMgr::GetFirstEntityId((CFlyingMgr *)g_cFlyingMgr, v2, 1) )
  {
    if ( BBSupportDbgReportF(
           2,
           "MapObjects\\Building\\ManakopterHallRole.cpp",
           514,
           "[MM] CheatIfRequired called while Manakopter exists.") == 1 )
      __debugbreak();
    return 0;
  }
  else
  {
    v12 = *((_DWORD *)v13 + 95) < CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredMana)
       || *((_DWORD *)v13 + 96) < CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredBoard)
       || *((_DWORD *)v13 + 97) < CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredIron);
    v15 = v12;
    if ( v12 )
    {
      if ( *((_BYTE *)v13 + 4) == 3 )
      {
        if ( BBSupportDbgReportF(
               2,
               "MapObjects\\Building\\ManakopterHallRole.cpp",
               534,
               "[MM] CheatIfRequired called while Manakopter is made.") == 1 )
          __debugbreak();
        return 0;
      }
      else
      {
        v10 = CBuilding::EnsignX(a2);
        v11 = CBuilding::EnsignY(a2);
        v4 = IEntity::OwnerId((unsigned __int8 *)a2);
        v9 = IAIEnvironment::AlliancesPlayerEnemyBits(v4);
        v5 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( (**(unsigned __int8 (__thiscall ***)(void *, int, int, int *, int *, _DWORD))off_3D7A6A8)(
               off_3D7A6A8,
               v5,
               v9,
               &v10,
               &v11,
               0) )
        {
          return 0;
        }
        else
        {
          v6 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredMana);
          *((_DWORD *)v13 + 95) = v6;
          v7 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredBoard);
          *((_DWORD *)v13 + 96) = v7;
          v8 = CStaticConfigVarInt::operator int(&CManakopterHallRole::s_iRequiredIron);
          *((_DWORD *)v13 + 97) = v8;
          CManakopterHallRole::TryMakingManakopter(v13, a2);
          return 1;
        }
      }
    }
    else
    {
      if ( BBSupportDbgReportF(
             2,
             "MapObjects\\Building\\ManakopterHallRole.cpp",
             527,
             "[MM] CheatIfRequired called while enough goods on hand.") == 1 )
        __debugbreak();
      return 0;
    }
  }
}


// address=[0x150dd40]
// Decompiled from int __thiscall CManakopterHallRole::ClassID(CManakopterHallRole *this)
unsigned long  CManakopterHallRole::ClassID(void)const {
  
  return CManakopterHallRole::m_iClassID;
}


// address=[0x150dd80]
// Decompiled from void *__thiscall CManakopterHallRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CManakopterHallRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x150dda0]
// Decompiled from int __thiscall CManakopterHallRole::GetBuildingRole(CManakopterHallRole *this)
int  CManakopterHallRole::GetBuildingRole(void) {
  
  return 21;
}


// address=[0x150de40]
// Decompiled from void *__thiscall CManakopterHallRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)
int  CManakopterHallRole::GetPileIdWithGood(int a2)const {
  
  return 0;
}


// address=[0x3d8b13c]
// [Decompilation failed for static unsigned long CManakopterHallRole::m_iClassID]

// address=[0x150dd60]
// Decompiled from void __thiscall CManakopterHallRole::ConvertEventIntoGoal(  CManakopterHallRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CManakopterHallRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x150dd70]
// Decompiled from char __thiscall CManakopterHallRole::CrushBuilding(CManakopterHallRole *this)
bool  CManakopterHallRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x150de60]
// Decompiled from char __thiscall CManakopterHallRole::TryCrushBuilding(CManakopterHallRole *this)
bool  CManakopterHallRole::TryCrushBuilding(void) {
  
  return 1;
}


// address=[0x40f2290]
// [Decompilation failed for static class CAIConfigInt CManakopterHallRole::s_iRequiredMana]

// address=[0x40f229c]
// [Decompilation failed for static class CAIConfigInt CManakopterHallRole::s_iRequiredBoard]

// address=[0x40f22a8]
// [Decompilation failed for static class CAIConfigInt CManakopterHallRole::s_iRequiredIron]

