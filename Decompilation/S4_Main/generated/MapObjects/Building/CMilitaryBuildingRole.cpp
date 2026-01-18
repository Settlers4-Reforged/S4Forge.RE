#include "CMilitaryBuildingRole.h"

// Definitions for class CMilitaryBuildingRole

// address=[0x14013a0]
// Decompiled from int __cdecl CMilitaryBuildingRole::New(int a1)
class CPersistence * __cdecl CMilitaryBuildingRole::New(std::istream & a1) {
  
  if ( operator new(0x1B8u) )
    return CMilitaryBuildingRole::CMilitaryBuildingRole(a1);
  else
    return 0;
}


// address=[0x14fca30]
// Decompiled from CMilitaryBuildingRole *__thiscall CMilitaryBuildingRole::CMilitaryBuildingRole(CMilitaryBuildingRole *this)
 CMilitaryBuildingRole::CMilitaryBuildingRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CMilitaryBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 408);
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 424);
  return this;
}


// address=[0x14fcc70]
// Decompiled from int __thiscall CMilitaryBuildingRole::~CMilitaryBuildingRole(CMilitaryBuildingRole *this)
 CMilitaryBuildingRole::~CMilitaryBuildingRole(void) {
  
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 424);
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 408);
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd120]
// Decompiled from int __thiscall CMilitaryBuildingRole::ClassID(CMilitaryBuildingRole *this)
unsigned long  CMilitaryBuildingRole::ClassID(void)const {
  
  return CMilitaryBuildingRole::m_iClassID;
}


// address=[0x14fd3c0]
// Decompiled from void *__thiscall CMilitaryBuildingRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CMilitaryBuildingRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x14fd500]
// Decompiled from int __thiscall CMilitaryBuildingRole::GetBuildingRole(CMFCButton *this)
int  CMilitaryBuildingRole::GetBuildingRole(void) {
  
  return 10;
}


// address=[0x14fd660]
// Decompiled from void *__thiscall CMilitaryBuildingRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)
int  CMilitaryBuildingRole::GetPileIdWithGood(int a2)const {
  
  return 0;
}


// address=[0x14fd730]
// Decompiled from void __thiscall CMilitaryBuildingRole::GoodArrive(CMilitaryBuildingRole *this, int a2)
void  CMilitaryBuildingRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x14fdaf0]
// Decompiled from int __cdecl CMilitaryBuildingRole::Load(int a1)
class CMilitaryBuildingRole * __cdecl CMilitaryBuildingRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CMilitaryBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x150de70]
// Decompiled from int __thiscall CMilitaryBuildingRole::LogicUpdate(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::LogicUpdate(class CBuilding * a2) {
  
  unsigned int v2; // esi
  int v3; // eax

  if ( (*(int (__thiscall **)(struct CBuilding *))(*(_DWORD *)a2 + 40))(a2) < *(unsigned __int8 *)(*((_DWORD *)this + 94)
                                                                                                 + 500) )
  {
    v2 = CStateGame::Rand(g_pGame);
    if ( v2 < CRandom16::PercentValue(0x21u) )
    {
      (*(void (__thiscall **)(struct CBuilding *))(*(_DWORD *)a2 + 24))(a2);
      v3 = (*(int (__thiscall **)(struct CBuilding *, int))(*(_DWORD *)a2 + 40))(a2, 10);
      CMilitaryBuildingRole::SetEffectDisplay(this, v3, 1);
    }
  }
  CMilitaryBuildingRole::ThrowOut(this, a2);
  CMilitaryBuildingRole::OrderWarrior(this, a2);
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(CMilitaryBuildingRole *, struct CBuilding *, int))(*(_DWORD *)this + 88))(this, a2, 1);
  return IAnimatedEntity::RegisterForLogicUpdate(15);
}


// address=[0x150df40]
// Decompiled from int __thiscall CMilitaryBuildingRole::Update(int this, CMFCCaptionButton *a2)
void  CMilitaryBuildingRole::Update(class CBuilding * a2) {
  
  int result; // eax

  result = IBuildingRole::Update(a2);
  if ( !*(_WORD *)(this + 10) )
    return result;
  result = this;
  if ( !*(_BYTE *)(this + 400) )
    return result;
  result = this;
  *(_BYTE *)(this + 359) = (*(unsigned __int8 *)(this + 359) + 1) % *(_DWORD *)(this + 404);
  return result;
}


// address=[0x150dfa0]
// Decompiled from int __thiscall CMilitaryBuildingRole::FillGfxInfo(_DWORD *this, unsigned __int16 *a2, int a3)
void  CMilitaryBuildingRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  _DWORD *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int16 *v7; // eax
  CSettler *v8; // eax
  int result; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-4h] [ebp-8A4h]
  int v13; // [esp+10h] [ebp-890h]
  int v14; // [esp+14h] [ebp-88Ch]
  int v15; // [esp+18h] [ebp-888h]
  unsigned int j; // [esp+1Ch] [ebp-884h]
  int v17; // [esp+20h] [ebp-880h]
  int i; // [esp+24h] [ebp-87Ch]
  _DWORD v20[180]; // [esp+2Ch] [ebp-874h] BYREF
  _DWORD v21[180]; // [esp+2FCh] [ebp-5A4h] BYREF
  _DWORD v22[180]; // [esp+5CCh] [ebp-2D4h] BYREF

  v14 = IEntity::Race(a2);
  IEntity::Type(a2);
  if ( *((_BYTE *)this + 336) )
  {
    this[37] = this[85];
    v3 = (_DWORD *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 193));
    if ( !IEntity::FlagBits(v3, (EntityFlag)0x10000u) )
      ++this[37];
  }
  (*(void (__thiscall **)(_DWORD *, unsigned __int16 *))(*this + 16))(this, a2);
  v4 = IEntity::Type(a2);
  CGfxManager::GetBuildingGfxInfo(a3, v14, v4, 9, (int)(this + 19));
  v5 = IEntity::OwnerId((unsigned __int8 *)a2);
  *(_BYTE *)(a3 + 715) = CPlayerManager::Color(v5);
  if ( *((_BYTE *)this + 400) )
  {
    v17 = 0;
    v13 = IEntity::Type(a2);
    switch ( v13 )
    {
      case '.':
        v17 = 0;
        break;
      case '/':
        v17 = 1;
        break;
      case '0':
        v17 = 2;
        break;
    }
    for ( i = 0; i < this[99] && dword_3D8B148[45 * v14 + 15 * v17 + 3 * i]; ++i )
    {
      CGfxManager::GetEffectGfxInfo(
        (CGfxManager *)g_pGfxManager,
        (struct SGfxObjectInfo *)v22,
        dword_3D8B148[45 * v14 + 15 * v17 + 3 * i],
        0,
        *((unsigned __int8 *)this + 359));
      *(_DWORD *)(a3 + 16 * i + 104) = v22[0];
      *(_DWORD *)(a3 + 16 * i + 108) = v22[1];
      *(_DWORD *)(a3 + 16 * i + 112) = dword_3D8B148[45 * v14 + 1 + 15 * v17 + 3 * i];
      *(_DWORD *)(a3 + 16 * i + 116) = dword_3D8B148[45 * v14 + 2 + 15 * v17 + 3 * i];
    }
  }
  v6 = IEntity::OwnerId((unsigned __int8 *)a2);
  *(_BYTE *)(a3 + 715) = CPlayerManager::Color(v6);
  for ( j = 0; j < std::vector<unsigned short>::size(this + 106); ++j )
  {
    if ( *(_WORD *)std::vector<unsigned short>::operator[](this + 106, j) )
    {
      if ( *(unsigned __int16 *)std::vector<unsigned short>::operator[](this + 106, j) != *((unsigned __int16 *)this
                                                                                          + 194) )
      {
        v7 = (unsigned __int16 *)std::vector<unsigned short>::operator[](this + 106, j);
        v8 = (CSettler *)CSettlerMgr::operator[](*v7);
        CSettler::GetPatchGfx(v8, (struct SGfxPatchObject *)(a3 + 16 * j + 200));
      }
    }
  }
  result = *((unsigned __int8 *)this + 29);
  if ( !*((_BYTE *)this + 29) )
    return result;
  v15 = 0;
  switch ( IEntity::Race(a2) )
  {
    case 0:
      v15 = 541;
      break;
    case 1:
      v15 = 543;
      break;
    case 2:
      v15 = 542;
      break;
    case 4:
      v15 = 542;
      break;
    default:
      v12 = IEntity::Type(a2);
      v10 = IEntity::Race(a2);
      if ( BBSupportDbgReportF(
             2,
             "MapObjects\\Building\\MilitaryBuilding.cpp",
             1040,
             "Invalid Race %u for Military Building Role Type %u",
             v10,
             v12) == 1 )
        __debugbreak();
      break;
  }
  if ( v15 )
  {
    CGfxManager::GetObjectGfxInfo((int)v21, v15, 0, 1);
    v11 = IEntity::OwnerId((unsigned __int8 *)a2);
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)g_pGfxManager + 4))(g_pGfxManager, v20, v11, 0);
    *(_DWORD *)(a3 + 80) = v21[0];
    *(_DWORD *)(a3 + 84) = v21[1];
    *(_DWORD *)(a3 + 24) = *(_DWORD *)(this[94] + 44);
    *(_DWORD *)(a3 + 28) = *(_DWORD *)(this[94] + 48);
    *(_DWORD *)(a3 + 72) = v20[0];
    result = a3;
    *(_DWORD *)(a3 + 76) = v20[1];
  }
  else
  {
    *(_DWORD *)(a3 + 80) = 0;
    result = a3;
    *(_DWORD *)(a3 + 84) = 0;
    *(_DWORD *)(a3 + 72) = 0;
    *(_DWORD *)(a3 + 76) = 0;
  }
  return result;
}


// address=[0x150e500]
// Decompiled from int __thiscall CMilitaryBuildingRole::Init(_DWORD *this, _DWORD *a2)
void  CMilitaryBuildingRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v6; // [esp+0h] [ebp-Ch]

  IBuildingRole::InitCommon((int)a2);
  if ( !*(_BYTE *)(this[94] + 220)
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Building\\MilitaryBuilding.cpp",
         378,
         (int)"m_pBuildingInfo->m_uWarriorNumber > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_BYTE *)(this[94] + 221)
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Building\\MilitaryBuilding.cpp",
         379,
         (int)"m_pBuildingInfo->m_uSwordsmanNumber > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_BYTE *)(this[94] + 222)
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Building\\MilitaryBuilding.cpp",
         380,
         (int)"m_pBuildingInfo->m_uBowmanNumber > 0") == 1 )
  {
    __debugbreak();
  }
  if ( *(char *)(this[94] + 223) < 0
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Building\\MilitaryBuilding.cpp",
         381,
         (int)"m_pBuildingInfo->m_iAboveDoorSlot >= 0") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(a2, (EntityFlag)0xFu);
  IEntity::SetFlagBits(a2, (EntityFlag)0xCu);
  IEntity::SetFlagBits(a2, Ready|VulnerableMask);
  *((_BYTE *)this + 380) = 0;
  *((_BYTE *)this + 381) = 0;
  *((_BYTE *)this + 382) = 0;
  *((_BYTE *)this + 383) = 0;
  *((_BYTE *)this + 384) = 0;
  *((_BYTE *)this + 385) = 0;
  *((_WORD *)this + 193) = 0;
  *((_WORD *)this + 194) = 0;
  this[101] = 0;
  this[99] = 0;
  *((_BYTE *)this + 400) = 0;
  this[98] = 0;
  std::vector<unsigned short>::clear();
  std::vector<unsigned short>::clear();
  std::vector<unsigned short>::resize(*(unsigned __int8 *)(this[94] + 220));
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(_DWORD *, _DWORD *, _DWORD))(*this + 88))(this, a2, 0);
  v2 = IEntity::WorldIdx();
  v6 = *(char *)(this[94] + 40) + CWorldManager::X(v2);
  v3 = IEntity::WorldIdx();
  v4 = CWorldManager::Y(v3);
  CWorldManager::ClearBlockedPosition(v6, *(char *)(this[94] + 41) + v4);
  CMilitaryBuildingRole::InsertDoor(a2, 0);
  return IAnimatedEntity::RegisterForLogicUpdate(16);
}


// address=[0x150e760]
// Decompiled from int __thiscall CMilitaryBuildingRole::PostLoadInit(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  if ( !*(_BYTE *)(*((_DWORD *)this + 94) + 220)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 362, "m_pBuildingInfo->m_uWarriorNumber > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_BYTE *)(*((_DWORD *)this + 94) + 221)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         363,
         "m_pBuildingInfo->m_uSwordsmanNumber > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_BYTE *)(*((_DWORD *)this + 94) + 222)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 364, "m_pBuildingInfo->m_uBowmanNumber > 0") == 1 )
  {
    __debugbreak();
  }
  result = *((_DWORD *)this + 94);
  if ( *(char *)(result + 223) >= 0 )
    return result;
  result = BBSupportDbgReport(
             2,
             "MapObjects\\Building\\MilitaryBuilding.cpp",
             365,
             "m_pBuildingInfo->m_iAboveDoorSlot >= 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x150e860]
// Decompiled from _DWORD *__thiscall CMilitaryBuildingRole::FillDialog(CMilitaryBuildingRole *this, struct CBuilding *a2, bool a3)
void  CMilitaryBuildingRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  _WORD *v5; // eax
  int v6; // eax
  int v8; // [esp-8h] [ebp-68h]
  int v9; // [esp-8h] [ebp-68h]
  int v10; // [esp-4h] [ebp-64h]
  int SettlerInfo; // [esp+8h] [ebp-58h]
  unsigned int v12; // [esp+Ch] [ebp-54h]
  int v13; // [esp+10h] [ebp-50h]
  int v14; // [esp+1Ch] [ebp-44h]
  int v15; // [esp+20h] [ebp-40h]
  int v16; // [esp+24h] [ebp-3Ch]
  int v17; // [esp+28h] [ebp-38h]
  unsigned __int16 *v18; // [esp+2Ch] [ebp-34h]
  int i; // [esp+34h] [ebp-2Ch]
  int j; // [esp+34h] [ebp-2Ch]
  unsigned int k; // [esp+34h] [ebp-2Ch]
  int m; // [esp+34h] [ebp-2Ch]
  int n; // [esp+34h] [ebp-2Ch]
  CEvn_Event v25; // [esp+38h] [ebp-28h] BYREF
  int v26; // [esp+5Ch] [ebp-4h]

  CInfoExchange::Clear(&g_cMilitaryBuildingInfo);
  dword_3F1E534 = 4;
  byte_3F1E539 = IEntity::Race(a2);
  byte_3F1E538 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E53B = 0;
  byte_3F1E53C = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E53D = 0;
  v8 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E53F = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v8, 0);
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E540 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v9, 1u);
  byte_3F1E53A = *((_BYTE *)this + 29);
  for ( i = 0; i < *((unsigned __int8 *)this + 385); ++i )
  {
    byte_3F1E558[2 * i] = -2;
    byte_3F1E559[2 * i] = 0;
  }
  for ( j = 0; j < *((unsigned __int8 *)this + 384); ++j )
  {
    byte_3F1E544[2 * j] = -2;
    byte_3F1E545[2 * j] = 0;
  }
  v17 = 0;
  v16 = 0;
  for ( k = 0; k < std::vector<unsigned short>::size((char *)this + 424); ++k )
  {
    v5 = (_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, k);
    if ( *v5 )
    {
      v18 = (unsigned __int16 *)CSettlerMgr::operator[]((unsigned __int16)*v5);
      v10 = IEntity::Type(v18);
      v6 = IEntity::Race(v18);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v6, v10);
      LOBYTE(v14) = 100;
      v15 = *(unsigned __int8 *)(SettlerInfo + 2);
      if ( *(_BYTE *)(SettlerInfo + 2) )
      {
        v13 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v18 + 40))(v18);
        if ( v13 < v15 )
          v14 = 100 * v13 / v15;
      }
      if ( *(_BYTE *)(*((_DWORD *)this + 94) + 12 * k + 233) )
      {
        byte_3F1E544[2 * v16] = IEntity::Type(v18);
        byte_3F1E545[2 * v16++] = v14;
      }
      else
      {
        byte_3F1E558[2 * v17] = IEntity::Type(v18);
        byte_3F1E559[2 * v17++] = v14;
      }
    }
  }
  for ( m = v17; m < *((unsigned __int8 *)this + 383) + *((unsigned __int8 *)this + 381); ++m )
  {
    byte_3F1E558[2 * m] = -1;
    byte_3F1E559[2 * m] = 0;
  }
  for ( n = v16; n < *((unsigned __int8 *)this + 382) + *((unsigned __int8 *)this + 380); ++n )
  {
    byte_3F1E544[2 * n] = -1;
    byte_3F1E545[2 * n] = 0;
  }
  v12 = 604;
  if ( !a3 )
    v12 = 602;
  CEvn_Event::CEvn_Event(&v25, v12, 0, (unsigned int)&g_cMilitaryBuildingInfo, 0);
  v26 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v25);
  v26 = -1;
  return CEvn_Event::~CEvn_Event(&v25);
}


// address=[0x150ebe0]
// Decompiled from char __thiscall CMilitaryBuildingRole::IncWishAndOrder(CMilitaryBuildingRole *this, int a2, bool a3)
bool  CMilitaryBuildingRole::IncWishAndOrder(int a2, bool a3) {
  
  if ( a2 == 2 )
  {
    if ( *((unsigned __int8 *)this + 385) >= (int)*(unsigned __int8 *)(*((_DWORD *)this + 94) + 221)
      || *((unsigned __int8 *)this + 383) + *((unsigned __int8 *)this + 381) >= *(unsigned __int8 *)(*((_DWORD *)this + 94) + 221) )
    {
      return 0;
    }
    if ( a3 )
      return 1;
    ++*((_BYTE *)this + 385);
    ++*((_BYTE *)this + 383);
    return 1;
  }
  else
  {
    if ( a2 != 3 )
    {
      if ( BBSupportDbgReport(
             1,
             "MapObjects\\Building\\MilitaryBuilding.cpp",
             1312,
             "CMilitaryBuildingRole::IncWishAndOrder(): Invalid warrior type!") == 1 )
        __debugbreak();
      return 0;
    }
    if ( *((unsigned __int8 *)this + 384) >= (int)*(unsigned __int8 *)(*((_DWORD *)this + 94) + 222)
      || *((unsigned __int8 *)this + 382) + *((unsigned __int8 *)this + 380) >= *(unsigned __int8 *)(*((_DWORD *)this + 94) + 222) )
    {
      return 0;
    }
    if ( a3 )
      return 1;
    ++*((_BYTE *)this + 384);
    ++*((_BYTE *)this + 382);
    return 1;
  }
}


// address=[0x150ed30]
// Decompiled from int __thiscall CMilitaryBuildingRole::GetWish(unsigned __int8 *this, int a2)
int  CMilitaryBuildingRole::GetWish(int a2) {
  
  if ( a2 == 2 )
    return this[385];
  if ( a2 == 3 )
    return this[384];
  return 0;
}


// address=[0x150ed70]
// Decompiled from int __thiscall CMilitaryBuildingRole::Decrease(CMilitaryBuildingRole *this, int a2)
int  CMilitaryBuildingRole::Decrease(int a2) {
  
  int v3; // [esp+0h] [ebp-Ch]
  IEntity *BuildingPtr; // [esp+8h] [ebp-4h]
  int v6; // [esp+14h] [ebp+8h]

  v6 = IBuildingRole::Decrease(this, a2);
  if ( v6 <= 0 )
    return 0;
  BuildingPtr = (IEntity *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  if ( !BuildingPtr || IEntity::FlagBits(BuildingPtr, (EntityFlag)&unk_4000000) )
    return v6;
  v3 = IEntity::Hitpoints(BuildingPtr) - v6;
  if ( v3 > 0 )
    CMilitaryBuildingRole::SetEffectDisplay(this, v3, 0);
  return v6;
}


// address=[0x150edf0]
// Decompiled from char __thiscall CMilitaryBuildingRole::HaveFreeSlots(CMilitaryBuildingRole *this, int a2)
bool  CMilitaryBuildingRole::HaveFreeSlots(int a2) {
  
  if ( a2 != 2 )
  {
    if ( a2 != 3
      || *((unsigned __int8 *)this + 384) >= (int)*(unsigned __int8 *)(*((_DWORD *)this + 94) + 222)
      || *((unsigned __int8 *)this + 382) + *((unsigned __int8 *)this + 380) >= *(unsigned __int8 *)(*((_DWORD *)this + 94) + 222) )
    {
      return 0;
    }
    if ( (int)CMilitaryBuildingRole::GetFirstFreeSlot(this, 1) < 0
      && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1919, "GetFirstFreeSlot(true) >= 0") == 1 )
    {
      __debugbreak();
    }
    ++*((_BYTE *)this + 382);
    ++*((_BYTE *)this + 384);
    return 1;
  }
  if ( *((unsigned __int8 *)this + 385) >= (int)*(unsigned __int8 *)(*((_DWORD *)this + 94) + 221)
    || *((unsigned __int8 *)this + 383) + *((unsigned __int8 *)this + 381) >= *(unsigned __int8 *)(*((_DWORD *)this + 94)
                                                                                                 + 221) )
  {
    return 0;
  }
  if ( (int)CMilitaryBuildingRole::GetFirstFreeSlot(this, 0) < 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1938, "GetFirstFreeSlot(false) >= 0") == 1 )
  {
    __debugbreak();
  }
  ++*((_BYTE *)this + 383);
  ++*((_BYTE *)this + 385);
  return 1;
}


// address=[0x150ef80]
// Decompiled from int __thiscall CMilitaryBuildingRole::RemoveInhabitant(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::RemoveInhabitant(class CBuilding * a2) {
  
  int result; // eax
  _WORD *v3; // eax
  _DWORD *v4; // eax
  signed int v5; // [esp+0h] [ebp-10h]
  signed int i; // [esp+8h] [ebp-8h]

  if ( *((_WORD *)this + 194) )
    CMilitaryBuildingRole::TowerGuardEnter(this, 0);
  CMilitaryBuildingRole::RemoveDoorIfNecessary(this, a2);
  result = std::vector<unsigned short>::size((char *)this + 424);
  v5 = result;
  for ( i = 0; i < v5; ++i )
  {
    v3 = (_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, i);
    if ( *v3 )
    {
      v4 = (_DWORD *)CSettlerMgr::operator[]((unsigned __int16)*v3);
      if ( !IEntity::FlagBits(v4, OnBoard)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\MilitaryBuilding.cpp",
             1175,
             "g_cSettlerMgr[iInhabitantId].FlagBits(ENTITY_FLAG_ON_BOARD) != 0") == 1 )
      {
        __debugbreak();
      }
      CMilitaryBuildingRole::ThrowOutSettler(this, a2, i);
      *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, i) = 0;
    }
    result = i + 1;
  }
  return result;
}


// address=[0x150f070]
// Decompiled from void __thiscall CMilitaryBuildingRole::InhabitantFlee(CMilitaryBuildingRole *this, int a2)
void  CMilitaryBuildingRole::InhabitantFlee(int a2) {
  
  int v2; // [esp+0h] [ebp-10h]
  signed int Slot; // [esp+8h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1420, "_iSettlerId > 0") == 1 )
    __debugbreak();
  if ( a2 == *((unsigned __int16 *)this + 193) )
  {
    CMilitaryBuildingRole::OnDoorKilled(this);
  }
  else
  {
    Slot = CMilitaryBuildingRole::GetSlot(this, a2);
    if ( Slot < 0 )
    {
      CSettlerMgr::operator[](a2);
      if ( IEntity::WarriorType() == 3 )
      {
        if ( !*((_BYTE *)this + 382)
          && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1463, "m_uNrOfBowmenOrders > 0") == 1 )
        {
          __debugbreak();
        }
        --*((_BYTE *)this + 382);
      }
      else if ( IEntity::WarriorType() == 2 )
      {
        if ( !*((_BYTE *)this + 383)
          && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1469, "m_uNrOfSwordsmenOrders > 0") == 1 )
        {
          __debugbreak();
        }
        --*((_BYTE *)this + 383);
      }
      else if ( BBSupportDbgReportF(
                  1,
                  "MapObjects\\Building\\MilitaryBuilding.cpp",
                  1475,
                  "CMilitaryBuildingRole::InhabitantFlee(): Invalid settler id %i!",
                  a2) == 1 )
      {
        __debugbreak();
      }
      v2 = CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 64))(v2, a2);
    }
    else
    {
      *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, Slot) = 0;
      if ( CMilitaryBuildingRole::IsTopPosition(this, Slot) )
      {
        if ( !*((_BYTE *)this + 380)
          && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1437, "m_uNrOfBowmen > 0") == 1 )
        {
          __debugbreak();
        }
        --*((_BYTE *)this + 380);
        CMilitaryBuildingRole::MoveAfterAboveDoor(this);
      }
      else
      {
        if ( !*((_BYTE *)this + 381)
          && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1445, "m_uNrOfSwordsmen > 0") == 1 )
        {
          __debugbreak();
        }
        --*((_BYTE *)this + 381);
        CMilitaryBuildingRole::MoveAfterWindow(this);
      }
      if ( a2 == *((unsigned __int16 *)this + 194) )
        CMilitaryBuildingRole::OnTowerGuardKilled(this);
    }
  }
}


// address=[0x150f2c0]
// Decompiled from CMilitaryBuildingRole *__thiscall CMilitaryBuildingRole::SetDoorInvincible(CMilitaryBuildingRole *this, int a2)
void  CMilitaryBuildingRole::SetDoorInvincible(int a2) {
  
  CMilitaryBuildingRole *result; // eax
  int v3; // eax
  int v4; // [esp+0h] [ebp-Ch]
  _DWORD *v5; // [esp+4h] [ebp-8h]

  result = this;
  if ( !*((_WORD *)this + 193) )
    return result;
  v5 = (_DWORD *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 193));
  IEntity::ClearFlagBits(v5, (EntityFlag)0x10000u);
  v4 = CLogic::FutureEvents(g_pLogic);
  v3 = IEntity::ID();
  return (CMilitaryBuildingRole *)(*(int (__thiscall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)v4 + 12))(
                                    v4,
                                    1,
                                    a2,
                                    v3,
                                    0x10000,
                                    0);
}


// address=[0x150f340]
// Decompiled from char *__thiscall CMilitaryBuildingRole::CMilitaryBuildingRole(char *this, int a2)
 CMilitaryBuildingRole::CMilitaryBuildingRole(std::istream & a2) {
  
  unsigned int v2; // eax
  int pExceptionObject; // [esp+4h] [ebp-24h] BYREF
  unsigned int v5; // [esp+8h] [ebp-20h] BYREF
  unsigned int v6; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int i; // [esp+10h] [ebp-18h]
  char *v8; // [esp+14h] [ebp-14h]
  _BYTE v9[4]; // [esp+18h] [ebp-10h] BYREF
  int v10; // [esp+24h] [ebp-4h]

  v8 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v10 = 0;
  *(_DWORD *)v8 = &CMilitaryBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(v8 + 408);
  std::vector<unsigned short>::vector<unsigned short>(v8 + 424);
  LOBYTE(v10) = 2;
  operator^<unsigned int>(a2, &v6);
  if ( !v6 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMilitaryBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v8 + 380);
  operator^<unsigned char>(a2, v8 + 381);
  operator^<unsigned char>(a2, v8 + 382);
  operator^<unsigned char>(a2, v8 + 383);
  operator^<unsigned char>(a2, v8 + 384);
  operator^<unsigned char>(a2, v8 + 385);
  operator^<unsigned short>(a2, v8 + 386);
  operator^<unsigned short>(a2, v8 + 388);
  if ( v6 >= 2 )
    operator^<unsigned int>(a2, v8 + 392);
  if ( v6 >= 3 )
  {
    operator^<bool>(a2, v8 + 400);
    operator^<int>(a2, (int)(v8 + 404));
    operator^<int>(a2, (int)(v8 + 396));
  }
  operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
  {
    v2 = std::vector<unsigned short>::operator[](v8 + 408, i);
    operator^<unsigned short>(a2, v2);
  }
  operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
  {
    operator^<unsigned short>(a2, v9);
    std::vector<unsigned short>::push_back(v9);
  }
  v10 = -1;
  return v8;
}


// address=[0x150f5c0]
// Decompiled from unsigned int __thiscall CMilitaryBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CMilitaryBuildingRole::Store(std::ostream & a2) {
  
  __int16 *v2; // eax
  unsigned int result; // eax
  __int16 *v4; // eax
  int v5; // [esp+0h] [ebp-10h] BYREF
  int v6; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h]
  struct IBuildingRole *v8; // [esp+Ch] [ebp-4h]

  v8 = this;
  IBuildingRole::Store(this, a2);
  v5 = 3;
  operator^<unsigned int>(a2, &v5);
  operator^<unsigned char>(a2, (int)v8 + 380);
  operator^<unsigned char>(a2, (int)v8 + 381);
  operator^<unsigned char>(a2, (int)v8 + 382);
  operator^<unsigned char>(a2, (int)v8 + 383);
  operator^<unsigned char>(a2, (int)v8 + 384);
  operator^<unsigned char>(a2, (int)v8 + 385);
  operator^<unsigned short>((int)a2, (__int16 *)v8 + 193);
  operator^<unsigned short>((int)a2, (__int16 *)v8 + 194);
  operator^<unsigned int>(a2, (int *)v8 + 98);
  operator^<bool>((int)a2, (int)v8 + 400);
  operator^<int>((int)a2, (int *)v8 + 101);
  operator^<int>((int)a2, (int *)v8 + 99);
  v6 = std::vector<unsigned short>::size((char *)v8 + 408);
  operator^<unsigned int>(a2, &v6);
  for ( i = 0; i < v6; ++i )
  {
    v2 = (__int16 *)std::vector<unsigned short>::operator[]((char *)v8 + 408, i);
    operator^<unsigned short>((int)a2, v2);
  }
  v6 = std::vector<unsigned short>::size((char *)v8 + 424);
  operator^<unsigned int>(a2, &v6);
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v6 )
      break;
    v4 = (__int16 *)std::vector<unsigned short>::operator[]((char *)v8 + 424, i);
    operator^<unsigned short>((int)a2, v4);
  }
  return result;
}


// address=[0x15e2cd0]
// Decompiled from char *__thiscall CMilitaryBuildingRole::Inhabitants(char *this)
class std::vector<unsigned short,class std::allocator<unsigned short> > const &  CMilitaryBuildingRole::Inhabitants(void)const {
  
  return this + 424;
}


// address=[0x160da00]
// Decompiled from int __thiscall CMilitaryBuildingRole::GetNumberOfInhabitants(CMilitaryBuildingRole *this)
int  CMilitaryBuildingRole::GetNumberOfInhabitants(void)const {
  
  return *((unsigned __int8 *)this + 381) + *((unsigned __int8 *)this + 380);
}


// address=[0x3d8b140]
// [Decompilation failed for static unsigned long CMilitaryBuildingRole::m_iClassID]

// address=[0x150f7b0]
// Decompiled from char __thiscall CMilitaryBuildingRole::TryCrushBuilding(CMilitaryBuildingRole *this)
bool  CMilitaryBuildingRole::TryCrushBuilding(void) {
  
  int v1; // esi
  int v2; // eax
  int v4; // [esp-8h] [ebp-14h]
  int v5; // [esp-4h] [ebp-10h]
  struct CBuilding *v7; // [esp+8h] [ebp-4h]

  v7 = (struct CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  if ( !CMilitaryBuildingRole::SearchAttacker(this, v7) )
    return 1;
  v1 = IEntity::OwnerId((unsigned __int8 *)v7);
  if ( v1 != CPlayerManager::GetLocalPlayerId() )
    return 0;
  v5 = IEntity::Y(v7);
  v4 = IEntity::X(v7);
  v2 = IEntity::OwnerId((unsigned __int8 *)v7);
  CTextMsgHandler::AddWarningMsg(2551, v2, v4, v5);
  return 0;
}


// address=[0x150f830]
// Decompiled from char __thiscall CMilitaryBuildingRole::CrushBuilding(CMilitaryBuildingRole *this)
bool  CMilitaryBuildingRole::CrushBuilding(void) {
  
  void *v1; // eax
  _DWORD *v2; // eax
  int v3; // eax
  void *v4; // eax
  _DWORD *v5; // eax
  int v6; // eax
  int v8; // [esp-4h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-Ch]

  v1 = (void *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v8 = IEntity::Y(v1);
  v2 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v3 = IEntity::X(v2);
  BBSupportTracePrintF(0, "### CrushBuilding(): building %i @ (%i, %i) ###", *((unsigned __int16 *)this + 3), v3, v8);
  v4 = (void *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v9 = IEntity::Y(v4);
  v5 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v6 = IEntity::X(v5);
  CWorldManager::SetOwner(v6, v9);
  return 1;
}


// address=[0x150f8d0]
// Decompiled from char __thiscall CMilitaryBuildingRole::SettlerEnter(CMilitaryBuildingRole *this, struct CBuilding *a2, int a3)
bool  CMilitaryBuildingRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  int v3; // esi
  unsigned __int8 *v4; // eax
  int v6; // ecx
  int v7; // eax
  struct CPaneContainer *v8; // eax
  int v9; // eax
  __int16 v10; // si
  __int16 v11; // si
  _DWORD v12[7]; // [esp-4h] [ebp-54h] BYREF
  signed int v13; // [esp+18h] [ebp-38h]
  signed int v14; // [esp+1Ch] [ebp-34h]
  CTowerSoldier *v15; // [esp+20h] [ebp-30h]
  _BYTE v16[4]; // [esp+24h] [ebp-2Ch] BYREF
  int v17; // [esp+28h] [ebp-28h]
  CTowerSoldier *v18; // [esp+2Ch] [ebp-24h]
  void *C; // [esp+30h] [ebp-20h]
  signed int j; // [esp+34h] [ebp-1Ch]
  signed int i; // [esp+38h] [ebp-18h]
  CPaneContainer *v22; // [esp+3Ch] [ebp-14h]
  IBuildingRole *v23; // [esp+40h] [ebp-10h]
  int v24; // [esp+4Ch] [ebp-4h]

  v23 = this;
  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 588, "_pBuilding != 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 589, "_iSettlerId > 0") == 1 )
    __debugbreak();
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = (unsigned __int8 *)CSettlerMgr::operator[](a3);
  if ( v3 == IEntity::OwnerId(v4) || *((unsigned __int16 *)v23 + 194) != a3 )
  {
    if ( *((_BYTE *)v23 + 29) || !CMilitaryBuildingRole::FirstSettlerEnter(v23, a2, a3) )
    {
      v22 = (CPaneContainer *)CSettlerMgr::operator[](a3);
      if ( *((unsigned __int16 *)v23 + 194) == a3 )
      {
        CMilitaryBuildingRole::TowerGuardEnter(v23, 1);
      }
      else
      {
        IBuildingRole::DetachWithoutNotify(v23, a2, a3);
        C = operator new(0x34u);
        v24 = 0;
        if ( C )
          v18 = CTowerSoldier::CTowerSoldier((CTowerSoldier *)C);
        else
          v18 = 0;
        v15 = v18;
        std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v18);
        v24 = 1;
        v12[0] = v6;
        v12[4] = v12;
        v12[3] = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v16);
        CSettler::NewRole(v22, v12[0]);
        v7 = IEntity::ID();
        CSettler::SetBuilding(v22, v7);
        v8 = (struct CPaneContainer *)IEntity::PackedXY(a2);
        IEntity::SetPosition(v22, v8);
        CSettler::TakeWaitList(v22);
        IEntity::ClearFlagBits(v22, Attached);
        IEntity::ClearFlagBits(v22, VulnerableMask);
        v9 = IEntity::Type((unsigned __int16 *)v22);
        v17 = CSettlerMgr::SettlerWarriorType(v9);
        if ( v17 == 2 )
        {
          v14 = *(unsigned __int8 *)(*((_DWORD *)v23 + 94) + 220);
          for ( i = 0; i < v14; ++i )
          {
            if ( !*(_BYTE *)(*((_DWORD *)v23 + 94) + 12 * i + 233)
              && !*(_WORD *)std::vector<unsigned short>::operator[]((char *)v23 + 424, i) )
            {
              v10 = IEntity::ID();
              *(_WORD *)std::vector<unsigned short>::operator[]((char *)v23 + 424, i) = v10;
              CMilitaryBuildingRole::SetSettlerTowerInfo(v23, v22, i, -1, 0);
              break;
            }
          }
          ++*((_BYTE *)v23 + 381);
          --*((_BYTE *)v23 + 383);
        }
        else if ( v17 == 3 )
        {
          v13 = *(unsigned __int8 *)(*((_DWORD *)v23 + 94) + 220);
          for ( j = 0; j < v13; ++j )
          {
            if ( *(_BYTE *)(*((_DWORD *)v23 + 94) + 12 * j + 233)
              && !*(_WORD *)std::vector<unsigned short>::operator[]((char *)v23 + 424, j) )
            {
              v11 = IEntity::ID();
              *(_WORD *)std::vector<unsigned short>::operator[]((char *)v23 + 424, j) = v11;
              CMilitaryBuildingRole::SetSettlerTowerInfo(v23, v22, j, -1, 0);
              break;
            }
          }
          ++*((_BYTE *)v23 + 380);
          --*((_BYTE *)v23 + 382);
        }
        else if ( BBSupportDbgReportF(
                    2,
                    "MapObjects\\Building\\MilitaryBuilding.cpp",
                    718,
                    "Wrong m_sWarriors type enter a tower") == 1 )
        {
          __debugbreak();
        }
        v24 = -1;
        std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(v16);
      }
      return 1;
    }
    else
    {
      v12[5] = CSettlerMgr::operator[](a3);
      CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, a3);
      (*(void (__thiscall **)(struct CBuilding *, int))(*(_DWORD *)a2 + 32))(a2, 10000);
      return 1;
    }
  }
  else
  {
    v12[6] = CMapObjectMgr::EntityPtr(a3);
    CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, a3);
    BBSupportTracePrintF(1, "[MM] Settler tried to turn into enemy guard!");
    return 0;
  }
}


// address=[0x150fd20]
// Decompiled from char __thiscall CMilitaryBuildingRole::FirstSettlerEnter(CMilitaryBuildingRole *this, struct CBuilding *a2, int a3)
bool  CMilitaryBuildingRole::FirstSettlerEnter(class CBuilding * a2, int a3) {
  
  int v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  char v17; // [esp-Ch] [ebp-8Ch]
  char v18; // [esp-Ch] [ebp-8Ch]
  int v19; // [esp-8h] [ebp-88h]
  int v20; // [esp-8h] [ebp-88h]
  int v21; // [esp-8h] [ebp-88h]
  int v22; // [esp-8h] [ebp-88h]
  int v23; // [esp-4h] [ebp-84h]
  int v24; // [esp-4h] [ebp-84h]
  __int16 v25; // [esp-4h] [ebp-84h]
  int v26; // [esp-4h] [ebp-84h]
  int v27; // [esp+8h] [ebp-78h]
  int v28; // [esp+Ch] [ebp-74h]
  int v29; // [esp+10h] [ebp-70h]
  int v30; // [esp+14h] [ebp-6Ch]
  int v31; // [esp+18h] [ebp-68h]
  int v32; // [esp+1Ch] [ebp-64h]
  int v33; // [esp+20h] [ebp-60h]
  int v34; // [esp+24h] [ebp-5Ch]
  unsigned __int8 *v35; // [esp+28h] [ebp-58h]
  _DWORD v37[8]; // [esp+30h] [ebp-50h] BYREF
  _DWORD v38[8]; // [esp+50h] [ebp-30h] BYREF
  int v39; // [esp+7Ch] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 441, "_pBuilding != 0") == 1 )
    __debugbreak();
  v35 = (unsigned __int8 *)CSettlerMgr::operator[](a3);
  if ( *((_BYTE *)this + 29)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 445, "!m_bWorkerInHouse") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 380)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 446, "m_uNrOfBowmen == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 381)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 447, "m_uNrOfSwordsmen == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::Race(v35) == 3 )
    return 1;
  *((_BYTE *)this + 29) = 1;
  if ( CBuildingMgr::InLoadBuildingData((CBuildingMgr *)g_cBuildingMgr) )
  {
    v28 = IEntity::X(a2);
    v29 = IEntity::Y(a2);
    v30 = IEntity::Type((unsigned __int16 *)a2);
    v31 = IEntity::OwnerId((unsigned __int8 *)a2);
    CWorldManager::SetTowerBits(v28, v29, v30, v31);
  }
  else
  {
    CMilitaryBuildingRole::RemoveDoorIfNecessary(this, a2);
    v4 = IEntity::OwnerId(v35);
    if ( v4 == IEntity::OwnerId((unsigned __int8 *)a2) )
    {
      v19 = IEntity::ID();
      v5 = IEntity::OwnerId((unsigned __int8 *)a2);
      (*(void (__thiscall **)(void *, int, int, int, _DWORD))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 10, v5, v19, 0);
      v17 = IEntity::OwnerId((unsigned __int8 *)a2);
      v6 = IEntity::ID();
      CEvn_Logic::CEvn_Logic((CEvn_Logic *)v38, 0x2BDu, v6, 0, v17, 0, 0);
      v39 = 0;
      if ( !g_pEvnEngine
        && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 479, "g_pEvnEngine != NULL") == 1 )
      {
        __debugbreak();
      }
      if ( g_pEvnEngine )
        IEventEngine::SendAMessage(g_pEvnEngine, v38);
      v39 = -1;
      CEvn_Logic::~CEvn_Logic(v38);
    }
    else
    {
      v27 = IEntity::UniqueId(a2);
      v7 = IEntity::EntityId((unsigned __int16 *)a2);
      CMapObjectMgr::AssignNewUniqueId(v7);
      if ( IEntity::UniqueId(a2) == v27
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\MilitaryBuilding.cpp",
             491,
             "_pBuilding->UniqueId() != iOldUniqueId") == 1 )
      {
        __debugbreak();
      }
      v8 = IEntity::OwnerId((unsigned __int8 *)a2);
      if ( v8 == CPlayerManager::GetLocalPlayerId() )
      {
        v23 = IEntity::Y(a2);
        v20 = IEntity::X(a2);
        v9 = IEntity::OwnerId((unsigned __int8 *)a2);
        CTextMsgHandler::AddWarningMsg(2462, v9, v20, v23);
      }
      v18 = IEntity::OwnerId((unsigned __int8 *)a2);
      v10 = IEntity::ID();
      CEvn_Logic::CEvn_Logic((CEvn_Logic *)v37, 0x2BFu, v10, 0, v18, 0, 0);
      v39 = 1;
      if ( !g_pEvnEngine
        && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 507, "g_pEvnEngine != NULL") == 1 )
      {
        __debugbreak();
      }
      if ( g_pEvnEngine )
        IEventEngine::SendAMessage(g_pEvnEngine, v37);
      v32 = IEntity::EntityId((unsigned __int16 *)a2);
      v34 = IEntity::OwnerId((unsigned __int8 *)a2);
      v33 = IEntity::OwnerId(v35);
      if ( v34 == CPlayerManager::GetLocalPlayerId() )
        CInputProcessor::DeSelectEntity(&g_cInputProcessor, v32);
      CBuildingMgr::ChangeOwnerIdOfBuilding((CBuildingMgr *)g_cBuildingMgr, v32, v33);
      v21 = IEntity::Y(a2);
      v11 = IEntity::X(a2);
      CWorldManager::SetMapObjectId(v11, v21, 0);
      CBuilding::RemoveBuildingBits(a2);
      v24 = IEntity::Y(a2);
      v12 = IEntity::X(a2);
      CWorldManager::SetOwner(v12, v24);
      CBuilding::SetToWorld(a2);
      v25 = IEntity::ID();
      v22 = IEntity::Y(a2);
      v13 = IEntity::X(a2);
      CWorldManager::SetMapObjectId(v13, v22, v25);
      v14 = IEntity::Type((unsigned __int16 *)a2);
      CStatistic::AddCaptureBuilding((CStatistic *)&g_cStatistic, v33, v34, v14);
      v15 = IEntity::ID();
      (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 3, v33, v15, v34);
      v39 = -1;
      CEvn_Logic::~CEvn_Logic(v37);
    }
    v26 = IEntity::Y(a2);
    v16 = IEntity::X(a2);
    CWorldManager::SetOwner(v16, v26);
    CMilitaryBuildingRole::InsertDoor(this, a2, 0);
  }
  return 0;
}


// address=[0x1510190]
// Decompiled from void __thiscall CMilitaryBuildingRole::TowerGuardEnter(CMilitaryBuildingRole *this, bool a2)
void  CMilitaryBuildingRole::TowerGuardEnter(bool a2) {
  
  int v2; // esi
  CMFCToolBarButton *v3; // [esp+4h] [ebp-Ch]
  IAnimatedEntity *v5; // [esp+Ch] [ebp-4h]

  if ( !*((_WORD *)this + 3)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 554, "m_uBuildingId > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_WORD *)this + 194)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 555, "m_uTowerGuardId > 0") == 1 )
  {
    __debugbreak();
  }
  v3 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v5 = (IAnimatedEntity *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 194));
  v2 = IEntity::PackedXY(v5);
  if ( v2 != CBuilding::DoorPackedXY(v3)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         560,
         "rTowerGuard.PackedXY() == rBuilding.DoorPackedXY()") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(IAnimatedEntity *))(*(_DWORD *)v5 + 56))(v5);
  (*(void (__thiscall **)(IAnimatedEntity *))(*(_DWORD *)v5 + 104))(v5);
  IAnimatedEntity::UnRegisterFromLogicUpdate(v5);
  CSettler::TakeWaitList(v5);
  IEntity::ClearFlagBits(v5, VulnerableMask);
  CMilitaryBuildingRole::SetSettlerTowerInfo(this, v5, -1, -1, 0);
  *((_WORD *)this + 194) = 0;
  if ( a2 )
    CMilitaryBuildingRole::InsertDoor(this, v3, 0);
}


// address=[0x15102d0]
// Decompiled from int __thiscall CMilitaryBuildingRole::KillInhabitant(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::KillInhabitant(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  _WORD *v4; // eax
  signed int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+4h] [ebp-10h]
  CSettler *v7; // [esp+8h] [ebp-Ch]
  signed int i; // [esp+Ch] [ebp-8h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  CStatistic::IncBuildingLosses((CStatistic *)&g_cStatistic, v2);
  if ( *((_WORD *)this + 194) )
    CMilitaryBuildingRole::TowerGuardEnter(this, 0);
  CMilitaryBuildingRole::RemoveDoorIfNecessary(this, a2);
  result = std::vector<unsigned short>::size((char *)this + 424);
  v5 = result;
  for ( i = 0; i < v5; ++i )
  {
    v4 = (_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, i);
    v6 = (unsigned __int16)*v4;
    if ( *v4 )
    {
      v7 = (CSettler *)CSettlerMgr::operator[](v6);
      if ( !IEntity::FlagBits(v7, OnBoard)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\MilitaryBuilding.cpp",
             1214,
             "rInhabitant.FlagBits(ENTITY_FLAG_ON_BOARD) != 0") == 1 )
      {
        __debugbreak();
      }
      CSettler::SetBuilding(v7, 0);
      IEntity::ClearFlagBits(v7, Visible);
      CMapObjectMgr::Kill(v6, 0);
      *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, i) = 0;
    }
    result = i + 1;
  }
  return result;
}


// address=[0x15103f0]
// Decompiled from char __thiscall CMilitaryBuildingRole::SearchAttacker(CMilitaryBuildingRole *this, struct CBuilding *a2)
bool  CMilitaryBuildingRole::SearchAttacker(class CBuilding * a2) {
  
  int v2; // eax
  int v4; // [esp-10h] [ebp-14h]
  int v5; // [esp-4h] [ebp-8h]

  v5 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = IEntity::Y(a2);
  v2 = IEntity::X(a2);
  return CScanner::FindAnyEnemyFighter(v2, v4, 10, 60, v5);
}


// address=[0x1510430]
// Decompiled from void __thiscall CMilitaryBuildingRole::ThrowOut(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::ThrowOut(class CBuilding *) {
  
  int LastUsedSlot; // [esp+4h] [ebp-Ch]
  bool v4; // [esp+Fh] [ebp-1h]

  if ( !CMilitaryBuildingRole::SearchAttacker(this, a2) )
  {
    v4 = 0;
    LastUsedSlot = -1;
    if ( *((unsigned __int8 *)this + 381) > (int)*((unsigned __int8 *)this + 385) )
    {
      LastUsedSlot = CMilitaryBuildingRole::GetLastUsedSlot(this, 0, 1);
      v4 = LastUsedSlot >= 0;
    }
    if ( !v4 && *((unsigned __int8 *)this + 380) > (int)*((unsigned __int8 *)this + 384) )
      LastUsedSlot = CMilitaryBuildingRole::GetLastUsedSlot(this, 1, 1);
    if ( LastUsedSlot >= 0 )
    {
      CMilitaryBuildingRole::ThrowOutSettler(this, a2, LastUsedSlot);
      if ( v4 )
        CMilitaryBuildingRole::MoveAfterWindow(this);
      else
        CMilitaryBuildingRole::MoveAfterAboveDoor(this);
    }
  }
}


// address=[0x1510510]
// Decompiled from void __thiscall CMilitaryBuildingRole::ThrowOutId(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::ThrowOutId(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // eax
  _DWORD v6[5]; // [esp-Ch] [ebp-5Ch] BYREF
  _BYTE v7[12]; // [esp+8h] [ebp-48h] BYREF
  _BYTE v8[12]; // [esp+14h] [ebp-3Ch] BYREF
  int v9; // [esp+20h] [ebp-30h]
  int v10; // [esp+24h] [ebp-2Ch]
  _DWORD *v11; // [esp+28h] [ebp-28h]
  int v12; // [esp+2Ch] [ebp-24h]
  struct std::_Iterator_base12 *v13; // [esp+30h] [ebp-20h]
  struct std::_Iterator_base12 *v14; // [esp+34h] [ebp-1Ch]
  int v15; // [esp+38h] [ebp-18h]
  signed int i; // [esp+3Ch] [ebp-14h]
  CMilitaryBuildingRole *v17; // [esp+40h] [ebp-10h]
  int v18; // [esp+4Ch] [ebp-4h]

  v17 = this;
  if ( std::vector<unsigned short>::size((char *)this + 408) )
  {
    if ( (*((_BYTE *)v17 + 380) || *((_BYTE *)v17 + 381) != 1) && (*((_BYTE *)v17 + 380) != 1 || *((_BYTE *)v17 + 381)) )
    {
      if ( !CMilitaryBuildingRole::SearchAttacker(v17, a2) )
      {
        v2 = CBuilding::EnsignWorldIdx(a2);
        if ( CWorldManager::IsPositionFreeForSettler(v2) )
        {
          v15 = 0;
          v12 = 0;
          for ( i = 0; i < *(unsigned __int8 *)(*((_DWORD *)v17 + 94) + 220); ++i )
          {
            v3 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)v17 + 424, i);
            if ( v3 == *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)v17 + 408, 0) )
            {
              v15 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)v17 + 408, 0);
              *(_WORD *)std::vector<unsigned short>::operator[]((char *)v17 + 424, i) = 0;
              v14 = (struct std::_Iterator_base12 *)std::vector<unsigned short>::begin(v7);
              v13 = v14;
              v18 = 0;
              v11 = v6;
              v10 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v14);
              v9 = std::vector<unsigned short>::erase(v8, v6[0], v6[1], v6[2]);
              std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v8);
              v18 = -1;
              std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v7);
              v4 = (unsigned __int16 *)CSettlerMgr::operator[](v15);
              v5 = IEntity::Type(v4);
              if ( CSettlerMgr::SettlerWarriorType(v5) == 3 )
              {
                --*((_BYTE *)v17 + 384);
                --*((_BYTE *)v17 + 380);
                CMilitaryBuildingRole::MoveAfterAboveDoor(v17);
              }
              else
              {
                --*((_BYTE *)v17 + 385);
                --*((_BYTE *)v17 + 381);
                CMilitaryBuildingRole::MoveAfterWindow(v17);
              }
              CMilitaryBuildingRole::ThrowOutSettler(v17, a2, i);
              return;
            }
          }
        }
      }
    }
    else
    {
      std::vector<unsigned short>::clear();
    }
  }
}


// address=[0x1510780]
// Decompiled from int __thiscall CMilitaryBuildingRole::ThrowOutSettler(CMilitaryBuildingRole *this, struct CBuilding *a2, signed int a3)
void  CMilitaryBuildingRole::ThrowOutSettler(class CBuilding * a2, int a3) {
  
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp+4h] [ebp-2Ch]
  int v9; // [esp+8h] [ebp-28h] BYREF
  CCarrierRole *SettlerRole; // [esp+Ch] [ebp-24h]
  int v11; // [esp+10h] [ebp-20h]
  _BYTE v12[4]; // [esp+14h] [ebp-1Ch] BYREF
  int v13; // [esp+18h] [ebp-18h]
  CMilitaryBuildingRole *v14; // [esp+1Ch] [ebp-14h]
  CPropertySet *v15; // [esp+20h] [ebp-10h]
  int v16; // [esp+2Ch] [ebp-4h]

  v14 = this;
  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1562, "_pBuilding != 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1563, "_iSlot >= 0") == 1 )
    __debugbreak();
  if ( a3 >= (unsigned int)std::vector<unsigned short>::size((char *)v14 + 424)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1564, "_iSlot < m_vInhabitants.size()") == 1 )
  {
    __debugbreak();
  }
  v13 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)v14 + 424, a3);
  *(_WORD *)std::vector<unsigned short>::operator[]((char *)v14 + 424, a3) = 0;
  if ( *(_BYTE *)(*((_DWORD *)v14 + 94) + 12 * a3 + 233) )
  {
    if ( !*((_BYTE *)v14 + 380)
      && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1572, "m_uNrOfBowmen > 0") == 1 )
    {
      __debugbreak();
    }
    --*((_BYTE *)v14 + 380);
  }
  else
  {
    if ( !*((_BYTE *)v14 + 381)
      && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1578, "m_uNrOfSwordsmen > 0") == 1 )
    {
      __debugbreak();
    }
    --*((_BYTE *)v14 + 381);
  }
  v15 = (CPropertySet *)CSettlerMgr::operator[](v13);
  v3 = IEntity::Type((unsigned __int16 *)v15);
  v11 = CSettlerMgr::SettlerWarriorType(v3);
  (*(void (__thiscall **)(CPropertySet *))(*(_DWORD *)v15 + 104))(v15);
  IAnimatedEntity::UnRegisterFromLogicUpdate(v15);
  IEntity::ClearFlagBits(v15, (EntityFlag)0xFu);
  IEntity::SetFlagBits(v15, (EntityFlag)(v11 | 0x30000));
  v9 = IEntity::Type((unsigned __int16 *)v15);
  v4 = IEntity::Race(v15);
  SettlerRole = CSettlerMgr::CreateSettlerRole((CSettlerMgr *)g_cSettlerMgr, v4, v9);
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(SettlerRole);
  v16 = 0;
  v9 = (int)&v9;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v12);
  CSettler::NewRole(v15, v9);
  v9 = CBuilding::DoorY(a2);
  v5 = CBuilding::DoorX(a2);
  CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v13, v5, v9);
  CWarMap::AddEntity(v15);
  IEntity::SetFlagBits(v15, Selectable|Visible);
  IEntity::ClearFlagBits(v15, OnBoard);
  v9 = IEntity::EntityId((unsigned __int16 *)a2);
  v8 = v13;
  v6 = IEntity::OwnerId((unsigned __int8 *)v15);
  (*(void (__thiscall **)(void *, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 21, v6, v8);
  v16 = -1;
  return std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(v12);
}


// address=[0x1510a30]
// Decompiled from CMilitaryBuildingRole *__thiscall CMilitaryBuildingRole::FillAllSlots(CMilitaryBuildingRole *this)
void  CMilitaryBuildingRole::FillAllSlots(void) {
  
  CMilitaryBuildingRole *result; // eax

  *((_BYTE *)this + 384) = *(_BYTE *)(*((_DWORD *)this + 94) + 222);
  result = this;
  *((_BYTE *)this + 385) = *(_BYTE *)(*((_DWORD *)this + 94) + 221);
  return result;
}


// address=[0x1510a70]
// Decompiled from char __thiscall CMilitaryBuildingRole::OrderWarrior(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::OrderWarrior(class CBuilding * a2) {
  
  int LocalPlayerId; // eax
  int v3; // esi
  int v4; // eax
  int v6; // [esp-8h] [ebp-28h]
  int v7; // [esp-4h] [ebp-24h]
  bool v9; // [esp+17h] [ebp-9h]
  bool v10; // [esp+19h] [ebp-7h]
  bool v11; // [esp+1Fh] [ebp-1h]

  if ( *((unsigned __int8 *)this + 384) > (int)*(unsigned __int8 *)(*((_DWORD *)this + 94) + 222)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         1808,
         "m_uNrOfBowmenWish <= m_pBuildingInfo->m_uBowmanNumber") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int8 *)this + 385) > (int)*(unsigned __int8 *)(*((_DWORD *)this + 94) + 221)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         1809,
         "m_uNrOfSwordsmenWish <= m_pBuildingInfo->m_uSwordsmanNumber") == 1 )
  {
    __debugbreak();
  }
  v9 = *((unsigned __int8 *)this + 381) + *((unsigned __int8 *)this + 380) == 0;
  v11 = v9
     && *((unsigned __int8 *)this + 383) + *((unsigned __int8 *)this + 382) == 0
     && *((unsigned __int8 *)this + 385) + *((unsigned __int8 *)this + 384) == 0;
  if ( (*((unsigned __int8 *)this + 383) + *((unsigned __int8 *)this + 381) < *((unsigned __int8 *)this + 385) || v11)
    && (CSettlerMgr::OrderAIWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 2)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 31, 0x14u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 30, 0x14u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 29, 0x14u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 31, 0x28u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 30, 0x28u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 29, 0x28u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 31, 0x50u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 30, 0x50u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 29, 0x50u)) )
  {
    ++*((_BYTE *)this + 383);
    if ( v11 )
      *((_BYTE *)this + 385) = 1;
  }
  v10 = *((_BYTE *)this + 383) == 0 && v11;
  if ( (*((unsigned __int8 *)this + 382) + *((unsigned __int8 *)this + 380) < *((unsigned __int8 *)this + 384) || v10)
    && (CSettlerMgr::OrderAIWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 3)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 34, 0x14u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 33, 0x14u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 32, 0x14u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 34, 0x28u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 33, 0x28u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 32, 0x28u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 34, 0x50u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 33, 0x50u)
     || CSettlerMgr::OrderWarrior((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)this + 3), 32, 0x50u)) )
  {
    ++*((_BYTE *)this + 382);
    if ( v10 )
      *((_BYTE *)this + 384) = 1;
  }
  LOBYTE(LocalPlayerId) = *((unsigned __int8 *)this + 383) + *((unsigned __int8 *)this + 382) == 0;
  if ( ((unsigned __int8)LocalPlayerId & v9) == 0 )
    return LocalPlayerId;
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  if ( v3 != LocalPlayerId )
    return LocalPlayerId;
  v7 = IEntity::Y(a2);
  v6 = IEntity::X(a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(2461, v4, v6, v7);
  return LocalPlayerId;
}


// address=[0x1510f30]
// Decompiled from void __thiscall CMilitaryBuildingRole::MoveAfterAboveDoor(CMilitaryBuildingRole *this)
void  CMilitaryBuildingRole::MoveAfterAboveDoor(void) {
  
  _WORD *v1; // eax
  struct CSettler *v2; // [esp+0h] [ebp-28h]
  int v3; // [esp+4h] [ebp-24h]
  int v4; // [esp+8h] [ebp-20h]
  int v5; // [esp+Ch] [ebp-1Ch]
  unsigned __int16 *v6; // [esp+14h] [ebp-14h]
  signed int v7; // [esp+18h] [ebp-10h]
  signed int v8; // [esp+1Ch] [ebp-Ch]
  signed int i; // [esp+20h] [ebp-8h]

  if ( std::vector<unsigned short>::size((char *)this + 424) != *(unsigned __int8 *)(*((_DWORD *)this + 94) + 220)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         1636,
         "m_vInhabitants.size() == m_pBuildingInfo->m_uWarriorNumber") == 1 )
  {
    __debugbreak();
  }
  v3 = *(unsigned __int8 *)(*((_DWORD *)this + 94) + 220);
  v7 = *(char *)(*((_DWORD *)this + 94) + 223);
  if ( v7 >= 0 && !*(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, v7) )
  {
    v8 = -1;
    v5 = 0;
    for ( i = v3 - 1; i >= 0; --i )
    {
      if ( *(_BYTE *)(*((_DWORD *)this + 94) + 12 * i + 233) )
      {
        v1 = (_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, i);
        if ( *v1 )
        {
          v6 = (unsigned __int16 *)CMapObjectMgr::Entity((unsigned __int16)*v1);
          if ( IEntity::WarriorType() != 3
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\Building\\MilitaryBuilding.cpp",
                 1660,
                 "rEntity.WarriorType() == WARRIOR_TYPE_FIGHTER_BOWMAN") == 1 )
          {
            __debugbreak();
          }
          if ( IEntity::Type(v6) > v5 )
          {
            v5 = IEntity::Type(v6);
            v8 = i;
          }
        }
      }
    }
    if ( v8 >= 0 )
    {
      if ( v7 >= v8
        && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1675, "iAboveDoorSlot < iBestSlot") == 1 )
      {
        __debugbreak();
      }
      v4 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 424, v8);
      *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, v8) = 0;
      *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, v7) = v4;
      v2 = (struct CSettler *)CSettlerMgr::operator[](v4);
      CMilitaryBuildingRole::SetSettlerTowerInfo(this, v2, v7, -2, 0);
    }
  }
}


// address=[0x1511130]
// Decompiled from unsigned int __thiscall CMilitaryBuildingRole::MoveAfterWindow(CMilitaryBuildingRole *this)
void  CMilitaryBuildingRole::MoveAfterWindow(void) {
  
  unsigned int result; // eax
  int v2; // eax
  unsigned __int16 *v3; // [esp+0h] [ebp-20h]
  signed int v4; // [esp+4h] [ebp-1Ch]
  signed int v5; // [esp+8h] [ebp-18h]
  int v6; // [esp+Ch] [ebp-14h]
  signed int k; // [esp+10h] [ebp-10h]
  unsigned int i; // [esp+14h] [ebp-Ch]
  signed int j; // [esp+18h] [ebp-8h]

  v4 = *(unsigned __int8 *)(*((_DWORD *)this + 94) + 220);
  v5 = 0;
  for ( i = 0; ; ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 424);
    if ( i >= result )
      break;
    if ( *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, i) )
    {
      v6 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 424, i);
      v3 = (unsigned __int16 *)CSettlerMgr::operator[](v6);
      v2 = IEntity::Type(v3);
      if ( CSettlerMgr::SettlerWarriorType(v2) == 2 )
      {
        for ( j = v5; j < v4; ++j )
        {
          ++v5;
          if ( !*(_BYTE *)(*((_DWORD *)this + 94) + 12 * j + 233) )
          {
            for ( k = 0; k < v4; ++k )
            {
              if ( *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 424, k) == v6 )
              {
                *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, k) = 0;
                break;
              }
            }
            *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, j) = v6;
            CMilitaryBuildingRole::SetSettlerTowerInfo(this, (struct CSettler *)v3, j, -1, 0);
            break;
          }
        }
      }
    }
  }
  return result;
}


// address=[0x15112c0]
// Decompiled from int __thiscall CMilitaryBuildingRole::InsertDoor(CMilitaryBuildingRole *this, struct CBuilding *a2, bool a3)
void  CMilitaryBuildingRole::InsertDoor(class CBuilding * a2, bool a3) {
  
  int result; // eax
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  CSettler *v7; // [esp+10h] [ebp-8h]

  if ( *((_WORD *)this + 193)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1962, "m_uDoorId == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)this + 194)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1963, "m_uTowerGuardId == 0") == 1 )
  {
    __debugbreak();
  }
  v5 = CBuilding::DoorX(a2);
  v6 = CBuilding::DoorY(a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  if ( !CSettlerMgr::IsAddSettlerOk((CSettlerMgr *)g_cSettlerMgr, v5, v6, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         1969,
         "g_cSettlerMgr.IsAddSettlerOk(iDoorX, iDoorY)") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 193) = CSettlerMgr::AddGuardSettler((CSettlerMgr *)g_cSettlerMgr, v5, v6, v4);
  if ( !*((_WORD *)this + 193)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 1973, "m_uDoorId != 0") == 1 )
  {
    __debugbreak();
  }
  v7 = (CSettler *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 193));
  CSettler::SetBuilding(v7, *((unsigned __int16 *)this + 3));
  if ( a3 )
  {
    IEntity::ClearFlagBits(v7, VulnerableMask);
    *((_BYTE *)this + 336) = 0;
    *((_DWORD *)this + 37) = 0;
    result = (int)this;
  }
  else
  {
    IEntity::SetFlagBits(v7, (EntityFlag)0x10000u);
    *((_BYTE *)this + 336) = 1;
    *((_DWORD *)this + 37) = *((_DWORD *)this + 85);
    result = 8;
  }
  *((_DWORD *)this + 38) = 0;
  return result;
}


// address=[0x15114b0]
// Decompiled from CMilitaryBuildingRole *__thiscall CMilitaryBuildingRole::RemoveDoorIfNecessary(  CMilitaryBuildingRole *this,  struct CBuilding *a2)
void  CMilitaryBuildingRole::RemoveDoorIfNecessary(class CBuilding * a2) {
  
  CMilitaryBuildingRole *result; // eax
  CSettler *v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  result = this;
  v4 = *((unsigned __int16 *)this + 193);
  if ( !*((_WORD *)this + 193) )
    return result;
  *((_WORD *)this + 193) = 0;
  *((_BYTE *)this + 336) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  v3 = (CSettler *)CSettlerMgr::operator[](v4);
  IEntity::ClearFlagBits(v3, Visible);
  CSettler::SetBuilding(v3, 0);
  return (CMilitaryBuildingRole *)CMapObjectMgr::Kill(v4, 0);
}


// address=[0x1511550]
// Decompiled from int __thiscall CMilitaryBuildingRole::MakeInvisibleDoorVisible(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::MakeInvisibleDoorVisible(class CBuilding * a2) {
  
  int result; // eax
  _DWORD *v3; // [esp+4h] [ebp-Ch]

  result = (int)this;
  if ( !*((_WORD *)this + 193) )
    return result;
  v3 = (_DWORD *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 193));
  IEntity::SetFlagBits(v3, (EntityFlag)0x10000u);
  *((_BYTE *)this + 336) = 1;
  *((_DWORD *)this + 37) = *((_DWORD *)this + 85);
  result = 72;
  *((_DWORD *)this + 38) = 0;
  return result;
}


// address=[0x15115e0]
// Decompiled from void __thiscall CMilitaryBuildingRole::OnDoorKilled(CMilitaryBuildingRole *this)
void  CMilitaryBuildingRole::OnDoorKilled(void) {
  
  if ( !*((_WORD *)this + 193)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2061, "m_uDoorId > 0") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 193) = 0;
  *((_BYTE *)this + 336) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  CMilitaryBuildingRole::InsertTowerGuard(this);
}


// address=[0x1511670]
// Decompiled from void __thiscall CMilitaryBuildingRole::OnTowerGuardKilled(CMilitaryBuildingRole *this)
void  CMilitaryBuildingRole::OnTowerGuardKilled(void) {
  
  if ( !*((_WORD *)this + 194)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2082, "m_uTowerGuardId > 0") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 194) = 0;
  CMilitaryBuildingRole::InsertTowerGuard(this);
}


// address=[0x15116c0]
// Decompiled from void __thiscall CMilitaryBuildingRole::InsertTowerGuard(CMilitaryBuildingRole *this)
void  CMilitaryBuildingRole::InsertTowerGuard(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  _BYTE v5[24]; // [esp+0h] [ebp-70h] BYREF
  int v6; // [esp+18h] [ebp-58h]
  int v7; // [esp+1Ch] [ebp-54h]
  int v8; // [esp+20h] [ebp-50h]
  int v9; // [esp+24h] [ebp-4Ch]
  int v10; // [esp+28h] [ebp-48h]
  int v11; // [esp+2Ch] [ebp-44h]
  int v12; // [esp+30h] [ebp-40h]
  int v13; // [esp+34h] [ebp-3Ch]
  int v14; // [esp+38h] [ebp-38h]
  int v15; // [esp+3Ch] [ebp-34h]
  int v16; // [esp+40h] [ebp-30h]
  unsigned __int8 *v17; // [esp+44h] [ebp-2Ch]
  int v18; // [esp+48h] [ebp-28h] BYREF
  signed int v19; // [esp+4Ch] [ebp-24h]
  int k; // [esp+50h] [ebp-20h]
  signed int j; // [esp+54h] [ebp-1Ch]
  signed int i; // [esp+58h] [ebp-18h]
  CMFCToolBarButton *v23; // [esp+5Ch] [ebp-14h]
  IAnimatedEntity *v24; // [esp+60h] [ebp-10h]
  int v25; // [esp+64h] [ebp-Ch]
  CMilitaryBuildingRole *v26; // [esp+68h] [ebp-8h]
  bool v27; // [esp+6Fh] [ebp-1h]

  v26 = this;
  if ( *((_WORD *)this + 193)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2098, "m_uDoorId == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)v26 + 194)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2099, "m_uTowerGuardId == 0") == 1 )
  {
    __debugbreak();
  }
  v23 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)v26 + 3));
  v25 = 0;
  v19 = -1;
  for ( i = *(unsigned __int8 *)(*((_DWORD *)v26 + 94) + 220) - 1; i >= 0; --i )
  {
    if ( !*(_BYTE *)(*((_DWORD *)v26 + 94) + 12 * i + 233) )
    {
      v14 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)v26 + 424, i);
      if ( v14 )
      {
        v25 = v14;
        v19 = i;
        break;
      }
    }
  }
  if ( v25 <= 0 )
  {
    if ( *((_BYTE *)v26 + 381)
      && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2127, "m_uNrOfSwordsmen == 0") == 1 )
    {
      __debugbreak();
    }
    *((_BYTE *)v26 + 381) = 0;
  }
  if ( v25 <= 0 )
  {
    for ( j = *(unsigned __int8 *)(*((_DWORD *)v26 + 94) + 220) - 1; j >= 0; --j )
    {
      if ( *(_BYTE *)(*((_DWORD *)v26 + 94) + 12 * j + 233) )
      {
        v13 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)v26 + 424, j);
        if ( v13 )
        {
          v25 = v13;
          v19 = j;
          break;
        }
      }
    }
    if ( v25 <= 0 )
    {
      if ( *((_BYTE *)v26 + 380)
        && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2159, "m_uNrOfBowmen == 0") == 1 )
      {
        __debugbreak();
      }
      *((_BYTE *)v26 + 380) = 0;
    }
  }
  *((_WORD *)v26 + 194) = v25;
  if ( v25 > 0 )
  {
    if ( v25 != *((unsigned __int16 *)v26 + 194)
      && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2246, "iNewDoorGuardId == m_uTowerGuardId") == 1 )
    {
      __debugbreak();
    }
    if ( (v19 < 0 || *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)v26 + 424, v19) != v25)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\MilitaryBuilding.cpp",
           2247,
           "(iNewDoorGuardSlot >= 0) && (m_vInhabitants[iNewDoorGuardSlot] == iNewDoorGuardId)") == 1 )
    {
      __debugbreak();
    }
    v24 = (IAnimatedEntity *)CSettlerMgr::operator[](v25);
    v3 = CBuilding::DoorPackedXY(v23);
    v12 = CWorldManager::Index(v3);
    v11 = 2;
    for ( k = 5; k >= 0; --k )
    {
      v6 = v12 + CWorldManager::NeighborRelIndex(k);
      if ( !CWorldManager::FlagBits(v6, 1u) )
      {
        v11 = k;
        break;
      }
    }
    if ( CWorldManager::MapObjectId(v12)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\MilitaryBuilding.cpp",
           2267,
           "g_cWorld.MapObjectId(iDoorWorldIdx) == 0") == 1 )
    {
      __debugbreak();
    }
    (*(void (__thiscall **)(IAnimatedEntity *))(*(_DWORD *)v24 + 104))(v24);
    IAnimatedEntity::UnRegisterFromLogicUpdate(v24);
    IEntity::ClearFlagBits(v24, (EntityFlag)0x2000Fu);
    IEntity::SetFlagBits(v24, (EntityFlag)0x1010Du);
    v4 = CBuilding::DoorPackedXY(v23);
    (*(void (__thiscall **)(IAnimatedEntity *, int))(*(_DWORD *)v24 + 52))(v24, v4);
    CSettler::TakeWaitList(v24);
    CMilitaryBuildingRole::SetSettlerTowerInfo(v26, v24, v19, v11, 1);
  }
  else
  {
    if ( *((_BYTE *)v26 + 380)
      && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2173, "m_uNrOfBowmen == 0") == 1 )
    {
      __debugbreak();
    }
    if ( *((_BYTE *)v26 + 381)
      && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2174, "m_uNrOfSwordsmen == 0") == 1 )
    {
      __debugbreak();
    }
    *((_BYTE *)v26 + 29) = 0;
    v9 = CBuilding::DoorX(v23);
    v10 = CBuilding::DoorY(v23);
    CSettlerSpiralWalk::CSettlerSpiralWalk((CSettlerSpiralWalk *)v5, v9, v10, 3);
    v18 = 0;
    v15 = 0;
    v8 = IEntity::OwnerId((unsigned __int8 *)v23);
    v7 = CAlliances::PlayerEnemyBits(v8);
    while ( CSettlerSpiralWalk::NextSettlerId((CSettlerSpiralWalk *)v5, &v18) )
    {
      v17 = (unsigned __int8 *)CSettlerMgr::operator[](v18);
      v16 = IEntity::WarriorType();
      if ( (v16 == 2 || v16 == 3) && IEntity::FlagBits(v17, Selectable|Attached) == 0x2000 )
      {
        v1 = IEntity::OwnerId(v17);
        v2 = CAlliances::PlayerBit(v1);
        if ( (v7 & v2) != 0 )
        {
          v15 = v16;
          break;
        }
      }
    }
    if ( v15 )
    {
      CMilitaryBuildingRole::InsertDoor(v26, v23, 1);
      if ( v18 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2223, "iSettlerId > 0") == 1 )
        __debugbreak();
      CMilitaryBuildingRole::CancelAllOrders(v26, v23);
      *((_BYTE *)v26 + 384) = 0;
      *((_BYTE *)v26 + 385) = 0;
      v27 = CMilitaryBuildingRole::IncWishAndOrder(v26, v15, 0);
      if ( !v27 && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2232, "bIncWishAndOrderOk") == 1 )
        __debugbreak();
      CSettlerMgr::OrderWarriorToTower((CSettlerMgr *)g_cSettlerMgr, *((unsigned __int16 *)v26 + 3), v18);
    }
    else
    {
      CMilitaryBuildingRole::InsertDoor(v26, v23, 0);
    }
  }
}


// address=[0x1511c50]
// Decompiled from int __thiscall CMilitaryBuildingRole::CancelAllOrders(CMilitaryBuildingRole *this, struct CBuilding *a2)
void  CMilitaryBuildingRole::CancelAllOrders(class CBuilding * a2) {
  
  int result; // eax
  _BYTE v3[24]; // [esp+4h] [ebp-30h] BYREF
  const struct CEntityEvent *v4; // [esp+1Ch] [ebp-18h]
  const struct CEntityEvent *v5; // [esp+20h] [ebp-14h]
  CMilitaryBuildingRole *v6; // [esp+24h] [ebp-10h]
  int v7; // [esp+30h] [ebp-4h]

  v6 = this;
  v5 = CEntityEvent::CEntityEvent((CEntityEvent *)v3, 9u, 0, *((unsigned __int16 *)this + 3), 0, 0);
  v4 = v5;
  v7 = 0;
  CBuilding::NotifyAndDetachAllObservers(a2, v5);
  v7 = -1;
  result = CEntityEvent::~CEntityEvent(v3);
  *((_BYTE *)v6 + 382) = 0;
  *((_BYTE *)v6 + 383) = 0;
  return result;
}


// address=[0x1511ce0]
// Decompiled from int __thiscall CMilitaryBuildingRole::GetFirstFreeSlot(CMilitaryBuildingRole *this, bool a2)
int  CMilitaryBuildingRole::GetFirstFreeSlot(bool a2) {
  
  int v3; // [esp+0h] [ebp-Ch]
  signed int i; // [esp+8h] [ebp-4h]

  if ( std::vector<unsigned short>::size((char *)this + 424) != *(unsigned __int8 *)(*((_DWORD *)this + 94) + 220)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         2600,
         "m_vInhabitants.size() == m_pBuildingInfo->m_uWarriorNumber") == 1 )
  {
    __debugbreak();
  }
  v3 = std::vector<unsigned short>::size((char *)this + 424);
  for ( i = 0; i < v3; ++i )
  {
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 12 * i + 233) == a2
      && !*(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, i) )
    {
      return i;
    }
  }
  return -1;
}


// address=[0x1511da0]
// Decompiled from int __thiscall CMilitaryBuildingRole::GetLastUsedSlot(CMilitaryBuildingRole *this, bool a2, bool a3)
int  CMilitaryBuildingRole::GetLastUsedSlot(bool a2, bool a3) {
  
  _WORD *v3; // eax
  signed int i; // [esp+8h] [ebp-8h]

  if ( std::vector<unsigned short>::size((char *)this + 424) != *(unsigned __int8 *)(*((_DWORD *)this + 94) + 220)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         2633,
         "m_vInhabitants.size() == m_pBuildingInfo->m_uWarriorNumber") == 1 )
  {
    __debugbreak();
  }
  for ( i = std::vector<unsigned short>::size((char *)this + 424) - 1; i >= 0; --i )
  {
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 12 * i + 233) == a2 )
    {
      v3 = (_WORD *)std::vector<unsigned short>::operator[]((char *)this + 424, i);
      if ( *v3 )
      {
        if ( !a3 || *v3 != *((_WORD *)this + 194) )
          return i;
      }
    }
  }
  return -1;
}


// address=[0x1511e80]
// Decompiled from int __thiscall CMilitaryBuildingRole::GetSlot(CMilitaryBuildingRole *this, int a2)
int  CMilitaryBuildingRole::GetSlot(int a2) {
  
  int v3; // [esp+0h] [ebp-Ch]
  signed int i; // [esp+8h] [ebp-4h]

  if ( a2 <= 0 )
    return -1;
  if ( std::vector<unsigned short>::size((char *)this + 424) != *(unsigned __int8 *)(*((_DWORD *)this + 94) + 220)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         2675,
         "m_vInhabitants.size() == m_pBuildingInfo->m_uWarriorNumber") == 1 )
  {
    __debugbreak();
  }
  v3 = std::vector<unsigned short>::size((char *)this + 424);
  for ( i = 0; i < v3; ++i )
  {
    if ( *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 424, i) == a2 )
      return i;
  }
  return -1;
}


// address=[0x1511f30]
// Decompiled from _DWORD *__thiscall CMilitaryBuildingRole::ConvertEventIntoGoal(  CMilitaryBuildingRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CMilitaryBuildingRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
  int v4; // [esp+8h] [ebp-8h]

  v4 = *((_DWORD *)a3 + 1);
  if ( v4 == 18 )
  {
    CMilitaryBuildingRole::FillAllSlots(this);
  }
  else if ( v4 == 19 )
  {
    if ( *((int *)a3 + 3) >= 0 )
    {
      if ( *((_DWORD *)a3 + 2) )
      {
        if ( *((unsigned __int8 *)this + 384) > 1u
          || *((_BYTE *)this + 384) == 1 && *((_BYTE *)this + 385) && *((_BYTE *)this + 381) )
        {
          --*((_BYTE *)this + 384);
        }
      }
      else if ( *((unsigned __int8 *)this + 385) > 1u
             || *((_BYTE *)this + 385) == 1 && *((_BYTE *)this + 384) && *((_BYTE *)this + 380) )
      {
        --*((_BYTE *)this + 385);
      }
    }
    else
    {
      CMilitaryBuildingRole::CancelAllOrders(this, a2);
      if ( *((_BYTE *)this + 381) || *((_BYTE *)this + 383) && !*((_BYTE *)this + 380) )
      {
        *((_BYTE *)this + 384) = 0;
        *((_BYTE *)this + 385) = 1;
      }
      else if ( *((_BYTE *)this + 380) || *((_BYTE *)this + 382) )
      {
        *((_BYTE *)this + 384) = 1;
        *((_BYTE *)this + 385) = 0;
      }
      else
      {
        *((_BYTE *)this + 384) = 0;
        *((_BYTE *)this + 385) = 0;
      }
    }
  }
  return IEntity::SetFlagBits(a2, (EntityFlag)0x80000000);
}


// address=[0x15120d0]
// Decompiled from int __thiscall CMilitaryBuildingRole::SetSettlerTowerInfo(  CMilitaryBuildingRole *this,  struct CSettler *a2,  signed int Slot,  int a4,  bool a5)
void  CMilitaryBuildingRole::SetSettlerTowerInfo(class CSettler & a2, int Slot, int a4, bool a5) {
  
  void **v5; // eax
  int v6; // esi
  int v8; // [esp+1Ch] [ebp-1Ch]
  int v9; // [esp+20h] [ebp-18h]
  signed int v10; // [esp+24h] [ebp-14h]
  CTowerSoldier *v11; // [esp+28h] [ebp-10h]

  v10 = *(unsigned __int8 *)(*((_DWORD *)this + 94) + 220);
  if ( (Slot < -1 || Slot >= v10)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         744,
         "(_iSlotIdx >= -1) && (_iSlotIdx < iNumberOfSlots)") == 1 )
  {
    __debugbreak();
  }
  v5 = (void **)CSettler::Role(a2);
  if ( !j____RTDynamicCast(v5, 0, &ISettlerRole__RTTI_Type_Descriptor_, &CTowerSoldier__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         745,
         "dynamic_cast<CTowerSoldier*>(&_rSettler.Role()) != 0") == 1 )
  {
    __debugbreak();
  }
  v11 = (CTowerSoldier *)CSettler::Role(a2);
  if ( Slot < 0 )
  {
    Slot = CTowerSoldier::GetSlot(v11);
    if ( (Slot < 0 || Slot >= v10)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\MilitaryBuilding.cpp",
           753,
           "(_iSlotIdx >= 0) && (_iSlotIdx < iNumberOfSlots)") == 1 )
    {
      __debugbreak();
    }
  }
  v6 = IEntity::EntityId((unsigned __int16 *)a2);
  if ( v6 != *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 424, Slot)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\MilitaryBuilding.cpp",
         756,
         "_rSettler.EntityId() == m_vInhabitants[_iSlotIdx]") == 1 )
  {
    __debugbreak();
  }
  if ( a5 )
    CSettler::SetOffset(a2, 0.0, 0.0);
  else
    CSettler::SetOffset(
      a2,
      (float)*(int *)(*((_DWORD *)this + 94) + 12 * Slot + 224),
      (float)*(int *)(*((_DWORD *)this + 94) + 12 * Slot + 228));
  if ( a4 < 0 )
    v9 = *(unsigned __int8 *)(*((_DWORD *)this + 94) + 12 * Slot + 232);
  else
    v9 = a4;
  if ( a4 != -2 || ISettlerRole::GetTask(v11) == 17 )
    IMovingEntity::SetDirection(a2, v9);
  if ( a5 )
  {
    if ( IEntity::EntityId((unsigned __int16 *)a2) != *((unsigned __int16 *)this + 194)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\MilitaryBuilding.cpp",
           782,
           "_rSettler.EntityId() == m_uTowerGuardId") == 1 )
    {
      __debugbreak();
    }
    return CTowerSoldier::SetTowerInfo(v11, Slot, 3, v9);
  }
  else if ( *(_BYTE *)(*((_DWORD *)this + 94) + 12 * Slot + 233) )
  {
    if ( Slot == *(char *)(*((_DWORD *)this + 94) + 223) )
      v8 = 1;
    else
      v8 = 2;
    return CTowerSoldier::SetTowerInfo(v11, Slot, v8, v9);
  }
  else
  {
    return CTowerSoldier::SetTowerInfo(v11, Slot, 0, v9);
  }
}


// address=[0x1512380]
// Decompiled from CMilitaryBuildingRole *__thiscall CMilitaryBuildingRole::SetEffectDisplay(CMilitaryBuildingRole *this, int a2, int a3)
void  CMilitaryBuildingRole::SetEffectDisplay(int a2, int a3) {
  
  CMilitaryBuildingRole *result; // eax
  int v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]

  v4 = *(unsigned __int8 *)(*((_DWORD *)this + 94) + 500);
  v5 = 100 * a2;
  v7 = 80;
  v6 = 100;
  switch ( *((_DWORD *)this + 99) )
  {
    case 1:
      v7 = 65;
      v6 = 100;
      break;
    case 2:
      v7 = 50;
      v6 = 80;
      break;
    case 3:
      v7 = 35;
      v6 = 65;
      break;
    case 4:
      v7 = 20;
      v6 = 50;
      break;
    case 5:
      v7 = 0;
      v6 = 35;
      break;
    default:
      break;
  }
  if ( v5 < v7 * v4 )
    ++*((_DWORD *)this + 99);
  if ( v5 >= v6 * v4 )
    --*((_DWORD *)this + 99);
  if ( !*((_BYTE *)this + 400) && *((_DWORD *)this + 99) )
  {
    *((_BYTE *)this + 400) = 1;
    *((_DWORD *)this + 101) = CGfxManager::GetEffectFrameCount((CGfxManager *)g_pGfxManager, 0x4Fu);
    *((_BYTE *)this + 359) = 0;
    *((_BYTE *)this + 356) = 0;
  }
  result = (CMilitaryBuildingRole *)*((_DWORD *)this + 94);
  if ( v5 < 100 * *((unsigned __int8 *)result + 500) )
    return result;
  result = this;
  *((_BYTE *)this + 400) = 0;
  *((_DWORD *)this + 99) = 0;
  return result;
}


// address=[0x1513a10]
// Decompiled from char __thiscall CMilitaryBuildingRole::IsTopPosition(CMilitaryBuildingRole *this, int a2)
bool  CMilitaryBuildingRole::IsTopPosition(int a2) {
  
  return *(_BYTE *)(*((_DWORD *)this + 94) + 12 * a2 + 233);
}


// address=[0x1512500]
// Decompiled from unsigned __int8 *__thiscall CMilitaryBuildingRole::NotifyDetach(  CMilitaryBuildingRole *this,  struct CBuilding *a2,  int a3)
void  CMilitaryBuildingRole::NotifyDetach(class CBuilding * a2, int a3) {
  
  unsigned __int8 *result; // eax
  int v4; // esi
  int v5; // eax
  int v6; // [esp+4h] [ebp-10h]
  unsigned __int8 *v7; // [esp+8h] [ebp-Ch]
  char v9; // [esp+13h] [ebp-1h]

  v9 = 0;
  result = CSettlerMgr::GetSettlerPtr(a3);
  v7 = result;
  if ( result )
  {
    v6 = IEntity::WarriorType();
    if ( v6 == 3 )
    {
      if ( !*((_BYTE *)this + 382)
        && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2710, "m_uNrOfBowmenOrders > 0") == 1 )
      {
        __debugbreak();
      }
      if ( (int)CMilitaryBuildingRole::GetSlot(this, a3) >= 0
        && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2711, "GetSlot(_iObserverId) < 0") == 1 )
      {
        __debugbreak();
      }
      if ( *((_BYTE *)this + 382) )
        --*((_BYTE *)this + 382);
      v9 = 1;
    }
    if ( v6 == 2 )
    {
      if ( !*((_BYTE *)this + 383)
        && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2723, "m_uNrOfSwordsmenOrders > 0") == 1 )
      {
        __debugbreak();
      }
      if ( (int)CMilitaryBuildingRole::GetSlot(this, a3) >= 0
        && BBSupportDbgReport(2, "MapObjects\\Building\\MilitaryBuilding.cpp", 2724, "GetSlot(_iObserverId) < 0") == 1 )
      {
        __debugbreak();
      }
      if ( *((_BYTE *)this + 383) )
        --*((_BYTE *)this + 383);
      v9 = 1;
    }
    v4 = IEntity::OwnerId(v7);
    result = (unsigned __int8 *)IEntity::OwnerId((unsigned __int8 *)a2);
    if ( (unsigned __int8 *)v4 != result )
    {
      CMilitaryBuildingRole::CancelAllOrders(this, a2);
      result = (unsigned __int8 *)CMilitaryBuildingRole::MakeInvisibleDoorVisible(this, a2);
    }
  }
  if ( v9 )
    return result;
  BBSupportTracePrintF(3, "CMilitaryBuildingRole::NotifyDetach(): Invalid observer!");
  v5 = IEntity::EntityId((unsigned __int16 *)a2);
  CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v5, 0, 0);
  return (unsigned __int8 *)CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, a3, 0, 0);
}


