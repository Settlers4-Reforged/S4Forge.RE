#include "CEcoManager.h"

// Definitions for class CEcoManager

// address=[0x133af00]
// Decompiled from CEcoManager *__thiscall CEcoManager::CEcoManager(  CEcoManager *this,  int a2,  struct IAISectorAI *a3,  struct IAIEventQueue *a4)
 CEcoManager::CEcoManager(int,class IAISectorAI *,class IAIEventQueue *) {
  
  int v4; // eax
  int v5; // ecx

  IAIEcoManager::IAIEcoManager(this);
  *(_DWORD *)this = &CEcoManager::_vftable_;
  CEcoManager::CEMD::CEMD((CEcoManager *)((char *)this + 4));
  *((_DWORD *)this + 65430) = a3;
  *((_DWORD *)this + 65431) = a4;
  EnableDebugFlag(dword_3ECD4F0);
  memset((char *)this + 4, 0, 0x3FE54u);
  if ( CEcoManager::AddRef() )
    CAIEcoSpecialBuildingInfos::TheObject();
  *((_DWORD *)this + 1) = a2;
  v4 = CEcoSectorMgr::operator[](a2);
  *((_DWORD *)this + 2) = CEcoSector::Owner(v4);
  *((_BYTE *)this + 261716) = CWorldManager::Width(this) / 16;
  *((_BYTE *)this + 261717) = CWorldManager::Height(v5, this) / 16;
  return this;
}


// address=[0x133b010]
// Decompiled from IAIEcoManager *__thiscall CEcoManager::~CEcoManager(CEcoManager *this)
 CEcoManager::~CEcoManager(void) {
  
  CAIEcoSpecialBuildingInfos *v2; // [esp+Ch] [ebp-18h]
  int i; // [esp+14h] [ebp-10h]

  *(_DWORD *)this = &CEcoManager::_vftable_;
  for ( i = 0; i < 83; ++i )
    CEcoManager::Discard(this, i);
  if ( !CEcoManager::Release() )
  {
    v2 = (CAIEcoSpecialBuildingInfos *)CAIEcoSpecialBuildingInfos::TheObject();
    if ( v2 )
      CAIEcoSpecialBuildingInfos::`scalar deleting destructor'(v2, 1u);
  }
  CEcoManager::CEMD::~CEMD((CEcoManager *)((char *)this + 4));
  return IAIEcoManager::~IAIEcoManager(this);
}


// address=[0x133b0c0]
// Decompiled from int __thiscall CEcoManager::InterfaceVersion(CEcoManager *this)
int  CEcoManager::InterfaceVersion(void) {
  
  return 2;
}


// address=[0x133b0d0]
// Decompiled from int __thiscall CEcoManager::GetEcoSectorID(CEcoManager *this)
int  CEcoManager::GetEcoSectorID(void) {
  
  return *((_DWORD *)this + 1);
}


// address=[0x133b0f0]
// Decompiled from int __thiscall CEcoManager::Invoke(_BYTE *this, unsigned int a2)
enum AI_ECOMANAGER_ERROR  CEcoManager::Invoke(enum BUILDING_TYPES) {
  
  int Tree; // [esp+0h] [ebp-8h]

  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 238, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  Tree = 0;
  if ( !this[a2 + 348] )
  {
    (*(void (__thiscall **)(_BYTE *, unsigned int))(*(_DWORD *)this + 16))(this, a2);
    this[a2 + 348] = 1;
    this[a2 + 680] = 0;
    this[a2 + 514] = 0;
    this[a2 + 431] = 0;
    *(_DWORD *)&this[4 * a2 + 259724] = 0;
  }
  if ( this[a2 + 348] )
    Tree = CEcoManager::CreateTree(this, a2, &this[4 * a2 + 16]);
  if ( Tree == 2 )
    return 2;
  if ( Tree == 1 || !CEcoManagerTree::GetNrValidOfAllBaseLeafes(*(_DWORD *)&this[4 * a2 + 16], 64) )
  {
    (*(void (__thiscall **)(_BYTE *, unsigned int))(*(_DWORD *)this + 16))(this, a2);
    return 1;
  }
  else
  {
    this[a2 + 348] = 0;
    return 0;
  }
}


// address=[0x133b240]
// Decompiled from int __thiscall CEcoManager::Invoke(CEcoManager *this, unsigned int iBuildingType, Squares *a3, unsigned int a4)
enum AI_ECOMANAGER_ERROR  CEcoManager::Invoke(enum BUILDING_TYPES,int,int) {
  
  _WORD v5[18]; // [esp+4h] [ebp-4Ch] BYREF
  int v6; // [esp+28h] [ebp-28h]
  int v7; // [esp+2Ch] [ebp-24h]
  int TileOfSquareVW; // [esp+30h] [ebp-20h]
  int v9; // [esp+34h] [ebp-1Ch]
  int j; // [esp+38h] [ebp-18h]
  int i; // [esp+3Ch] [ebp-14h]
  int v13; // [esp+4Ch] [ebp-4h]

  if ( !CheckBuildingType(iBuildingType)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 295, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( !CheckVW() && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 296, "CheckVW(_iV, _iW)") == 1 )
    __debugbreak();
  SAI_ECO_POSS_BUILD_PLACE::SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v5);
  v13 = 0;
  if ( Squares::ValidVW(a3, a4) )
  {
    v6 = 0;
    if ( !*((_BYTE *)this + iBuildingType + 348) )
    {
      (*(void (__thiscall **)(CEcoManager *, unsigned int))(*(_DWORD *)this + 16))(this, iBuildingType);
      *((_BYTE *)this + iBuildingType + 348) = 1;
      *((_BYTE *)this + iBuildingType + 680) = 0;
      *((_BYTE *)this + iBuildingType + 514) = 0;
      *((_BYTE *)this + iBuildingType + 431) = 1;
      *((_DWORD *)this + iBuildingType + 64931) = 0;
    }
    if ( *((_BYTE *)this + iBuildingType + 348) )
    {
      for ( i = a4 - 1; i <= (int)(a4 + 1); ++i )
      {
        for ( j = (int)a3 - 1; j <= (int)a3 + 1; ++j )
        {
          if ( !(unsigned __int8)CEcoManager::IsChecked(this, iBuildingType, j, i) )
          {
            TileOfSquareVW = ITiling::FirstTileOfSquareVW(j, i);
            if ( CEcoManager::IsMyTile(this, TileOfSquareVW) )
            {
              if ( (unsigned __int8)CEcoManager::WorkOnTile(
                                      this,
                                      iBuildingType,
                                      j,
                                      i,
                                      *((_DWORD *)this + iBuildingType + 4)) )
              {
                v5[0] = j + ((_WORD)i << 8);
                std::vector<SAI_ECO_POSS_BUILD_PLACE>::push_back((int)v5);
                CEcoManager::SetChecked(this, iBuildingType, j, i);
              }
            }
          }
        }
      }
    }
    v7 = 2;
    v13 = -1;
    SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v5);
    return v7;
  }
  else
  {
    v9 = 2;
    v13 = -1;
    SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v5);
    return v9;
  }
}


// address=[0x133b4c0]
// Decompiled from char __thiscall CEcoManager::Discard(_BYTE *this, unsigned int a2)
bool  CEcoManager::Discard(enum BUILDING_TYPES) {
  
  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 360, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  CEcoManager::ResetCheckField(this, 0, a2);
  this[a2 + 348] = 0;
  this[a2 + 431] = 0;
  this[a2 + 514] = 0;
  this[a2 + 597] = 0;
  this[a2 + 680] = 0;
  *(_DWORD *)&this[4 * a2 + 259724] = 0;
  *(_DWORD *)&this[4 * a2 + 260056] = 0;
  *(_DWORD *)&this[4 * a2 + 260388] = 0;
  *(_DWORD *)&this[4 * a2 + 260720] = 0;
  *(_DWORD *)&this[4 * a2 + 261052] = 0;
  *(_DWORD *)&this[4 * a2 + 261384] = 0;
  std::vector<SAI_ECO_POSS_BUILD_PLACE>::clear();
  if ( !*(_DWORD *)&this[4 * a2 + 16] )
    return 0;
  CEcoManagerTree::`scalar deleting destructor'(*(CEcoManagerTree **)&this[4 * a2 + 16], 1u);
  *(_DWORD *)&this[4 * a2 + 16] = 0;
  return 1;
}


// address=[0x133b620]
// Decompiled from bool __thiscall CEcoManager::DiscardPosition(_DWORD *this, unsigned int a2, struct SBUILDINFODATA *a3)
bool  CEcoManager::DiscardPosition(enum BUILDING_TYPES,struct SBUILDINFODATA *) {
  
  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 400, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( !a3 && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 401, "_paBuildInfoData != 0") == 1 )
    __debugbreak();
  return !this[a2 + 4] || CEcoManagerTree::RemoveLeaf((CEcoManagerTree *)this[a2 + 4], a3);
}


// address=[0x133b6b0]
// Decompiled from int __thiscall CEcoManager::GetBuildPlace(_DWORD *this, int a2, unsigned int a3, int a4)
int  CEcoManager::GetBuildPlace(enum IECONOMANAGERGRIDRESOLUTION,enum BUILDING_TYPES,class std::vector<struct SBUILDINFODATA,class std::allocator<struct SBUILDINFODATA> > &) {
  
  struct Concurrency::details::stl_condition_variable_win7 *BuildInfo; // eax
  struct Concurrency::details::stl_condition_variable_win7 *v6; // eax
  struct Concurrency::details::stl_condition_variable_win7 *v7; // eax
  int NrBaseLeaves; // [esp+4h] [ebp-24h]
  struct CEcoManagerLeaf *v10; // [esp+Ch] [ebp-1Ch]
  struct CEcoManagerLeaf *BaseLeaf; // [esp+10h] [ebp-18h]
  CEcoManagerTree *v12; // [esp+14h] [ebp-14h]
  struct CEcoManagerLeaf *Child; // [esp+18h] [ebp-10h]
  int k; // [esp+1Ch] [ebp-Ch]
  int j; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  if ( !CheckBuildingType(a3)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 426, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( !a3 )
    return 0;
  v12 = (CEcoManagerTree *)this[a3 + 4];
  if ( !v12 )
    return 0;
  NrBaseLeaves = CEcoManagerTree::GetNrBaseLeaves(v12, 0);
  for ( i = 0; i < NrBaseLeaves; ++i )
  {
    BaseLeaf = CEcoManagerTree::GetBaseLeaf(v12, i);
    if ( a2 == 64 )
    {
      BuildInfo = CEcoManagerLeaf::GetBuildInfo(BaseLeaf);
      std::vector<SBUILDINFODATA>::push_back(BuildInfo);
    }
    else
    {
      for ( j = 0; j < CEcoManagerLeaf::GetNrChilds(BaseLeaf); ++j )
      {
        Child = CEcoManagerLeaf::GetChild(BaseLeaf, j);
        if ( Child )
        {
          if ( a2 == 32 )
          {
            v6 = CEcoManagerLeaf::GetBuildInfo(Child);
            std::vector<SBUILDINFODATA>::push_back(v6);
          }
          else
          {
            for ( k = 0; k < CEcoManagerLeaf::GetNrChilds(Child); ++k )
            {
              v10 = CEcoManagerLeaf::GetChild(Child, k);
              if ( v10 )
              {
                v7 = CEcoManagerLeaf::GetBuildInfo(v10);
                std::vector<SBUILDINFODATA>::push_back(v7);
              }
            }
          }
        }
      }
    }
  }
  return std::vector<SBUILDINFODATA>::size(a4);
}


// address=[0x133b820]
// Decompiled from int __thiscall CEcoManager::GetBuildPlace(unsigned __int8 *this, int a2, int *a3, int a4, unsigned int a5)
int  CEcoManager::GetBuildPlace(enum BUILDING_TYPES,struct SBUILDINFODATA *,class std::vector<struct SBUILDINFODATA,class std::allocator<struct SBUILDINFODATA> > &,int) {
  
  struct Concurrency::details::stl_condition_variable_win7 *BuildInfo; // eax
  int v7; // [esp+4h] [ebp-20h]
  _Cnd_internal_imp_t *Leaf; // [esp+8h] [ebp-1Ch]
  int v9; // [esp+Ch] [ebp-18h]
  int v10; // [esp+10h] [ebp-14h]
  int v11; // [esp+14h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-8h]
  int j; // [esp+20h] [ebp-4h]

  if ( !(unsigned __int8)CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 501, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( a5 >= 0x400
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 502, "static_cast<unsigned int>(_iDistance) < 1024") == 1 )
  {
    __debugbreak();
  }
  if ( !a3 || !a2 )
    return 0;
  v9 = *(_DWORD *)&this[4 * a2 + 16];
  if ( !v9 )
    return 0;
  v10 = *a3;
  v11 = a3[1];
  v7 = a3[2];
  for ( i = -a5; i < (int)(a5 + 1); ++i )
  {
    for ( j = -a5; j < (int)(a5 + 1); ++j )
    {
      if ( (i || j || !v7) && i + v10 >= 0 && i + v10 <= this[261716] && j + v11 >= 0 && j + v11 <= this[261717] )
      {
        Leaf = (_Cnd_internal_imp_t *)CEcoManagerTree::FindLeaf(v9, a3[3], i + v10, j + v11);
        if ( Leaf )
        {
          BuildInfo = CEcoManagerLeaf::GetBuildInfo(Leaf);
          std::vector<SBUILDINFODATA>::push_back(BuildInfo);
        }
      }
    }
  }
  return std::vector<SBUILDINFODATA>::size(a4);
}


// address=[0x133b9c0]
// Decompiled from void *__thiscall CEcoManager::GetBuildPlace(_DWORD *this, void *a2, int a3, unsigned int a4, int a5, int a6, int a7)
struct SBUILDINFODATA  CEcoManager::GetBuildPlace(enum IECONOMANAGERGRIDRESOLUTION,enum BUILDING_TYPES,int,int,int) {
  
  _Cnd_internal_imp_t *v8; // [esp+4h] [ebp-ECh]
  int v9; // [esp+8h] [ebp-E8h]
  int v10; // [esp+10h] [ebp-E0h]
  int v11; // [esp+24h] [ebp-CCh] BYREF
  int v12; // [esp+28h] [ebp-C8h] BYREF
  int v13; // [esp+2Ch] [ebp-C4h] BYREF
  int v14; // [esp+30h] [ebp-C0h] BYREF
  int v15; // [esp+34h] [ebp-BCh] BYREF
  int v16; // [esp+38h] [ebp-B8h] BYREF
  _DWORD *v17; // [esp+3Ch] [ebp-B4h]
  int v18; // [esp+40h] [ebp-B0h]
  bool v19; // [esp+45h] [ebp-ABh]
  bool v20; // [esp+46h] [ebp-AAh]
  bool v21; // [esp+47h] [ebp-A9h]
  int v22[19]; // [esp+48h] [ebp-A8h] BYREF
  _BYTE v23[76]; // [esp+94h] [ebp-5Ch] BYREF
  int v24; // [esp+ECh] [ebp-4h]

  v17 = this;
  v18 = 0;
  if ( !CheckBuildingType(a4)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 569, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  SBUILDINFODATA::SBUILDINFODATA(v22);
  v24 = 1;
  `eh vector constructor iterator'(v23, 0x4Cu, 1u, SBUILDINFODATA::SBUILDINFODATA, SBUILDINFODATA::~SBUILDINFODATA);
  LOBYTE(v24) = 2;
  memset(v22, 0, sizeof(v22));
  v15 = 0;
  v16 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v19 = a5 != -1;
  v21 = a6 != -1;
  v20 = a7 != -1;
  if ( (a5 != -1 || v21 || v20) && (v9 = v17[a4 + 4]) != 0 )
  {
    v10 = v20 + v21 + v19;
    if ( (!v19 || (*(unsigned __int8 (__thiscall **)(_DWORD *, int, int *, int *))(*v17 + 52))(v17, a5, &v12, &v11))
      && (!v21 || (*(unsigned __int8 (__thiscall **)(_DWORD *, int, int *, int *))(*v17 + 52))(v17, a6, &v16, &v14))
      && (!v20 || (*(unsigned __int8 (__thiscall **)(_DWORD *, int, int *, int *))(*v17 + 52))(v17, a7, &v15, &v13)) )
    {
      v12 >>= 4;
      v11 >>= 4;
      v16 >>= 4;
      v14 >>= 4;
      v15 >>= 4;
      v13 >>= 4;
      v8 = (_Cnd_internal_imp_t *)CEcoManagerTree::FindNearLeaf(
                                    v9,
                                    16,
                                    (v15 + v16 + v12) / v10,
                                    (v13 + v14 + v11) / v10,
                                    1);
      if ( v8 )
      {
        v22[3] = 16;
        CEcoManager::CopyData(v8, (int)v22);
        if ( a3 != 16 )
        {
          (*(void (__thiscall **)(_DWORD *, unsigned int, int, int *, _BYTE *))(*v17 + 264))(v17, a4, a3, v22, v23);
          SBUILDINFODATA::operator=(v23);
        }
      }
    }
    SBUILDINFODATA::SBUILDINFODATA(v22);
    v18 |= 1u;
    LOBYTE(v24) = 1;
    `eh vector destructor iterator'(v23, 0x4Cu, 1u, SBUILDINFODATA::~SBUILDINFODATA);
    LOBYTE(v24) = 0;
    SBUILDINFODATA::~SBUILDINFODATA(v22);
    return a2;
  }
  else
  {
    SBUILDINFODATA::SBUILDINFODATA(v22);
    v18 |= 1u;
    LOBYTE(v24) = 1;
    `eh vector destructor iterator'(v23, 0x4Cu, 1u, SBUILDINFODATA::~SBUILDINFODATA);
    LOBYTE(v24) = 0;
    SBUILDINFODATA::~SBUILDINFODATA(v22);
    return a2;
  }
}


// address=[0x133bf80]
// Decompiled from bool __thiscall CEcoManager::IsInside(void *this, unsigned int a2, int a3, int a4)
bool  CEcoManager::IsInside(enum BUILDING_TYPES,int,int) {
  
  int v5; // eax

  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 672, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)_should_initialize_environment_1(a3, a4)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 673, "CheckXY(_iWorldX, _iWorldY)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a3, a4) )
    return 0;
  v5 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 128))(this);
  return CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, a3, a4, v5, a2, 0) > 0;
}


// address=[0x133c050]
// Decompiled from bool __thiscall CEcoManager::AreBuildingsOverlapped(void *this, unsigned int a2, int a3, unsigned int a4, int a5)
bool  CEcoManager::AreBuildingsOverlapped(enum BUILDING_TYPES,int,enum BUILDING_TYPES,int) {
  
  int v5; // eax
  int v6; // eax
  int v8; // [esp+20h] [ebp-20h]
  int v10; // [esp+28h] [ebp-18h]
  int v11; // [esp+2Ch] [ebp-14h]
  int v12; // [esp+30h] [ebp-10h]
  Grid *v13; // [esp+34h] [ebp-Ch]
  char *v14; // [esp+38h] [ebp-8h]
  char *BoundingBoxInfo; // [esp+3Ch] [ebp-4h]

  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 694, "CheckBuildingType(_iBuildingType1)") == 1 )
  {
    __debugbreak();
  }
  if ( !CheckBuildingType(a4)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 695, "CheckBuildingType(_iBuildingType2)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)_should_initialize_environment_2(a3)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 696, "CheckPackedXY(_iPackedxy1)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)_should_initialize_environment_2(a5)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 697, "CheckPackedXY(_iPackedxy2)") == 1 )
  {
    __debugbreak();
  }
  v8 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 136))(this);
  v5 = CAIEcoSpecialBuildingInfos::TheObject();
  BoundingBoxInfo = (char *)CAIEcoSpecialBuildingInfos::GetBoundingBoxInfo(v5, v8, a2);
  v6 = CAIEcoSpecialBuildingInfos::TheObject();
  v14 = (char *)CAIEcoSpecialBuildingInfos::GetBoundingBoxInfo(v6, v8, a4);
  v13 = (Grid *)Y16X16::UnpackXFast(a3);
  v12 = Y16X16::UnpackYFast(a3);
  v11 = Y16X16::UnpackXFast(a5);
  v10 = Y16X16::UnpackYFast(a5);
  if ( (int)Grid::Distance(v13, v12, v11, v10) < 5 )
    return 1;
  if ( (int)v13 + *BoundingBoxInfo > v11 + v14[1] || (int)v13 + BoundingBoxInfo[1] < v11 + *v14 )
    return 0;
  return v12 + BoundingBoxInfo[2] <= v10 + v14[3] && v12 + BoundingBoxInfo[3] >= v10 + v14[2];
}


// address=[0x133c260]
// Decompiled from int __thiscall CEcoManager::CheckBuildingOverlappingWithinGrid(void *this, unsigned int a2, int a3)
int  CEcoManager::CheckBuildingOverlappingWithinGrid(enum BUILDING_TYPES,int) {
  
  int v3; // eax
  struct CPtrList *v5; // eax
  int v6; // [esp-4h] [ebp-18h]
  int v7; // [esp+0h] [ebp-14h]
  int v8; // [esp+4h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 757, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)_should_initialize_environment_2(a3)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 758, "CheckPackedXY(_iPackedXY)") == 1 )
  {
    __debugbreak();
  }
  v7 = Y16X16::UnpackXFast(a3) >> 4;
  v8 = Y16X16::UnpackYFast(a3) >> 4;
  for ( i = CWarMap::FirstEntityIdVW(2, v7, v8); i; i = CWarMapNode::Next(v5) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, i);
    v6 = CBuilding::EnsignPackedXY(BuildingPtr);
    v3 = IEntity::Type((unsigned __int16 *)BuildingPtr);
    if ( (*(unsigned __int8 (__thiscall **)(void *, unsigned int, int, int, int))(*(_DWORD *)this + 40))(
           this,
           a2,
           a3,
           v3,
           v6) )
    {
      return i;
    }
    v5 = IEntity::WarMapNode((CPropertySet *)BuildingPtr);
  }
  return 0;
}


// address=[0x133c370]
// Decompiled from int __thiscall CEcoManager::GetBuildingIndex(CEcoManager *this, int a2, int a3)
int  CEcoManager::GetBuildingIndex(int,int) {
  
  if ( !(unsigned __int8)_should_initialize_environment_1(a2, a3)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 793, "CheckXY(_iWorldX, _iWorldY)") == 1 )
  {
    __debugbreak();
  }
  return CWorldManager::BuildingId(a2, a3);
}


// address=[0x133c3d0]
// Decompiled from char __thiscall CEcoManager::GetBuildingPosition(CEcoManager *this, int a2, int *a3, int *a4)
bool  CEcoManager::GetBuildingPosition(int,int &,int &) {
  
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-4h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  if ( BuildingPtr && !IEntity::FlagBits(BuildingPtr, (EntityFlag)&unk_4000000) )
  {
    if ( CBuilding::EcoSectorId(BuildingPtr) != *((_DWORD *)this + 1)
      && BBSupportDbgReport(
           2,
           "AI\\EcoManager\\CEcoManager.cpp",
           824,
           "pBuilding->EcoSectorId() == m_Vars.iUsedEcoSector") == 1 )
    {
      __debugbreak();
    }
    *a3 = IEntity::X(BuildingPtr);
    *a4 = IEntity::Y(BuildingPtr);
    return 1;
  }
  else
  {
    BBSupportTracePrintF(
      3,
      "### CEcoManager::GetBuildingPosition(): eco-sector %i, building id %i failed! ###",
      *((_DWORD *)this + 1),
      a2);
    *a3 = 0;
    *a4 = 0;
    return 0;
  }
}


// address=[0x133c490]
// Decompiled from int __thiscall CEcoManager::GetPileAmount(void *this, int a2, int a3)
int  CEcoManager::GetPileAmount(int,enum PILE_TYPES) {
  
  int PileIdWithGood; // [esp+0h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-Ch]
  struct CPile *PilePtr; // [esp+Ch] [ebp-4h]

  if ( !(*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 838, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)sub_13406F0(a3)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 839, "CheckGoodType(_iPileType)") == 1 )
  {
    __debugbreak();
  }
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  if ( !BuildingPtr )
    return 0;
  PileIdWithGood = CBuilding::GetPileIdWithGood((CBuilding *)BuildingPtr, a3);
  if ( !PileIdWithGood )
    return 0;
  PilePtr = CPileMgr::GetPilePtr(PileIdWithGood);
  if ( PilePtr )
    return (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr);
  else
    return 0;
}


// address=[0x133c570]
// Decompiled from int __thiscall CEcoManager::GetCountOfGoodsForBuilding(void *this, unsigned int a2, int a3)
int  CEcoManager::GetCountOfGoodsForBuilding(enum BUILDING_TYPES,enum IECONEEDEDRESOURCE) {
  
  unsigned __int8 *v3; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-8h] [ebp-Ch]
  int v9; // [esp-8h] [ebp-Ch]

  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 870, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      v8 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 136))(this);
      v5 = (unsigned __int8 *)CAIEcoSpecialBuildingInfos::TheObject();
      return CAIEcoSpecialBuildingInfos::GetNrNeededStones(v5, v8, a2);
    }
    else if ( a3 == 2 )
    {
      v9 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 136))(this);
      v6 = (unsigned __int8 *)CAIEcoSpecialBuildingInfos::TheObject();
      return CAIEcoSpecialBuildingInfos::GetNrNeededGold(v6, v9, a2);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v7 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 136))(this);
    v3 = (unsigned __int8 *)CAIEcoSpecialBuildingInfos::TheObject();
    return CAIEcoSpecialBuildingInfos::GetNrNeededBoards(v3, v7, a2);
  }
}


// address=[0x133c630]
// Decompiled from int __thiscall CEcoManager::GetCountOfPendingGoodsForBuilding(void *this, int a2, int a3)
int  CEcoManager::GetCountOfPendingGoodsForBuilding(int,enum IECONEEDEDRESOURCE) {
  
  int v4; // [esp+8h] [ebp-8h]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-4h]

  if ( !(*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 890, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  v4 = 0;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  if ( !BuildingPtr )
    return 0;
  switch ( a3 )
  {
    case 0:
      return CBuilding::GetBuildingNeed((CBuilding *)BuildingPtr, 7);
    case 1:
      return CBuilding::GetBuildingNeed((CBuilding *)BuildingPtr, 32);
    case 2:
      return CBuilding::GetBuildingNeed((CBuilding *)BuildingPtr, 15);
  }
  return v4;
}


// address=[0x133c6f0]
// Decompiled from int __thiscall CEcoManager::BuildingProgress(CEcoManager *this, int a2)
int  CEcoManager::BuildingProgress(int) {
  
  CBuildingSiteRole *v3; // [esp+0h] [ebp-Ch]
  _DWORD *v4; // [esp+4h] [ebp-8h]

  if ( !(*(unsigned __int8 (__thiscall **)(CEcoManager *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 931, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  v4 = (_DWORD *)CBuildingMgr::operator[](a2);
  if ( (unsigned __int8)CBuilding::IsBuildUp(v4) )
    return 100;
  v3 = (CBuildingSiteRole *)CBuilding::Role(v4);
  return CBuildingSiteRole::BuildingProgress(v3);
}


// address=[0x133c780]
// Decompiled from bool __thiscall CEcoManager::IsActive(void *this, int a2)
bool  CEcoManager::IsActive(int) {
  
  _DWORD *v4; // [esp+4h] [ebp-8h]

  if ( !(*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, (int)"AI\\EcoManager\\CEcoManager.cpp", 949, (int)"CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  v4 = (_DWORD *)CBuildingMgr::operator[](a2);
  return (unsigned __int8)CBuilding::IsBuildUp(v4) && IEntity::FlagBits(v4, 0x1000);
}


// address=[0x133c810]
// Decompiled from bool __thiscall CEcoManager::IsBuildingPlaceActive(void *this, int a2)
bool  CEcoManager::IsBuildingPlaceActive(int) {
  
  _DWORD *v3; // [esp+0h] [ebp-Ch]

  if ( !(*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, (int)"AI\\EcoManager\\CEcoManager.cpp", 963, (int)"CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  v3 = (_DWORD *)CBuildingMgr::operator[](a2);
  return IEntity::FlagBits(v3, 0x1000) != 0;
}


// address=[0x133c890]
// Decompiled from int __thiscall CEcoManager::GetBuildingType(void *this, int a2)
enum BUILDING_TYPES  CEcoManager::GetBuildingType(int) {
  
  unsigned __int16 *v3; // [esp+0h] [ebp-8h]

  if ( !(*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 977, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  v3 = (unsigned __int16 *)CBuildingMgr::operator[](a2);
  return IEntity::Type(v3);
}


// address=[0x133c900]
// Decompiled from int __thiscall CEcoManager::HaveInhabitant(CEcoManager *this, int a2)
bool  CEcoManager::HaveInhabitant(int) {
  
  if ( !(*(unsigned __int8 (__thiscall **)(CEcoManager *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 990, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  CBuildingMgr::operator[](a2);
  return CBuilding::HaveInhabitant();
}


// address=[0x133c970]
// Decompiled from int __thiscall CEcoManager::GetNrOfSettlerComingOutOfResidence(void *this, int a2)
int  CEcoManager::GetNrOfSettlerComingOutOfResidence(enum BUILDING_TYPES) {
  
  int v2; // eax

  v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 136))(this);
  return *(_DWORD *)(CBuildingInfoMgr::GetBuildingInfo(v2, a2) + 496);
}


// address=[0x133c9b0]
// Decompiled from int __thiscall CEcoManager::GetRemainingNrOfSettlersComingOutOfResidence(CEcoManager *this, int a2)
int  CEcoManager::GetRemainingNrOfSettlersComingOutOfResidence(int) {
  
  CResidenceBuildingRole *v3; // [esp+0h] [ebp-10h]
  unsigned __int16 *v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-4h]

  if ( !(*(unsigned __int8 (__thiscall **)(CEcoManager *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1014, "CheckBuildingId(_iBuildingId)") == 1 )
  {
    __debugbreak();
  }
  v4 = (unsigned __int16 *)CBuildingMgr::operator[](a2);
  v5 = IEntity::Type(v4);
  if ( v5 != 40 && v5 != 41 && v5 != 42 )
    return 0;
  v3 = (CResidenceBuildingRole *)CBuilding::Role(v4);
  return CResidenceBuildingRole::ReturnRemainingSettlers(v3);
}


// address=[0x133ca40]
// Decompiled from int __thiscall CEcoManager::GetBuildingEcoSectorID(_DWORD *this, int a2)
int  CEcoManager::GetBuildingEcoSectorID(int) {
  
  _DWORD *BuildingPtr; // [esp+4h] [ebp-4h]

  BuildingPtr = (_DWORD *)CBuildingMgr::GetBuildingPtr(a2);
  if ( BuildingPtr && !IEntity::FlagBits(BuildingPtr, 0x4000000) )
    return CBuilding::EcoSectorId(BuildingPtr);
  BBSupportTracePrintF(
    3,
    "### CEcoManager::GetBuildingEcoSectorID(): eco-sector %i, building id %i failed! ###",
    this[1],
    a2);
  return 0;
}


// address=[0x133caa0]
// Decompiled from int __thiscall CEcoManager::ConstructBuilding(int *this, unsigned int a2, int a3, int a4)
enum AI_ECOMANAGER_ERROR  CEcoManager::ConstructBuilding(enum BUILDING_TYPES,int,int) {
  
  int v4; // eax
  char v5; // al
  unsigned int v7; // [esp+8h] [ebp-38h]
  _BYTE v9[32]; // [esp+10h] [ebp-30h] BYREF
  unsigned int v10; // [esp+34h] [ebp-Ch]
  unsigned __int16 v11; // [esp+38h] [ebp-8h]
  int v12; // [esp+3Ch] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CEcoManager::ConstructBuilding(): player %i, eco-sector %i, building type %i, position (%i, %i)",
    this[2],
    this[1],
    a2,
    a3,
    a4);
  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1062, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)_should_initialize_environment_1(a3, a4)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1063, "CheckXY(_iWorldX, _iWorldY)") == 1 )
  {
    __debugbreak();
  }
  v4 = Y16X16::PackXYFast(a3, a4);
  v5 = (*(int (__thiscall **)(int *, _DWORD, _DWORD))(*this + 128))(this, 0, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v9, 0x13A1u, a2, v7, v5, v10, v11);
  v12 = 0;
  INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v9);
  v12 = -1;
  CEvn_Logic::~CEvn_Logic(v9);
  return 0;
}


// address=[0x133cbf0]
// Decompiled from int __thiscall CEcoManager::DestroyBuilding(int *this, unsigned int a2)
enum AI_ECOMANAGER_ERROR  CEcoManager::DestroyBuilding(int) {
  
  char v2; // al
  _BYTE v5[32]; // [esp+Ch] [ebp-30h] BYREF
  unsigned int v6; // [esp+30h] [ebp-Ch]
  unsigned __int16 v7; // [esp+34h] [ebp-8h]
  int v8; // [esp+38h] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CEcoManager::DestroyBuilding(): player %i, eco-sector %i, building id %i",
    this[2],
    this[1],
    a2);
  if ( !(*(unsigned __int8 (__thiscall **)(int *, unsigned int))(*this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1080, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  v2 = (*(int (__thiscall **)(int *, _DWORD, _DWORD))(*this + 128))(this, 0, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v5, 0x138Au, a2, 0, v2, v6, v7);
  v8 = 0;
  INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v5);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v5);
  return 0;
}


// address=[0x133ccf0]
// Decompiled from int __thiscall CEcoManager::GetContentOfWorkingArea(CEcoManager *this, int a2)
int  CEcoManager::GetContentOfWorkingArea(int) {
  
  int v2; // eax
  int v4; // [esp-8h] [ebp-14h]
  int v5; // [esp-4h] [ebp-10h]
  void *v6; // [esp+0h] [ebp-Ch]
  int WorkingAreaPackedXY; // [esp+4h] [ebp-8h]

  if ( !(*(unsigned __int8 (__thiscall **)(CEcoManager *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1099, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  v6 = (void *)CBuildingMgr::operator[](a2);
  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(v6);
  v5 = Y16X16::UnpackYFast(WorkingAreaPackedXY);
  v4 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
  v2 = IEntity::Type((unsigned __int16 *)v6);
  return (*(int (__thiscall **)(CEcoManager *, int, int, int))(*(_DWORD *)this + 108))(this, v2, v4, v5);
}


// address=[0x133cd90]
// Decompiled from char __thiscall CEcoManager::ChangeWorkingAreaTo(CEcoManager *this, unsigned int a2, int a3, int a4)
bool  CEcoManager::ChangeWorkingAreaTo(int,int,int) {
  
  char v5; // al
  unsigned int v6; // [esp+4h] [ebp-3Ch]
  _BYTE v8[32]; // [esp+10h] [ebp-30h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CEcoManager::ChangeWorkingAreaTo(): player %i, eco-sector %i, building id %i, position (%i, %i)",
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 1),
    a2,
    a3,
    a4);
  if ( !(*(unsigned __int8 (__thiscall **)(CEcoManager *, unsigned int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1116, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)_should_initialize_environment_1(a3, a4)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1117, "CheckXY(_iWorldX, _iWorldY)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a3, a4) )
    return 0;
  v6 = Y16X16::PackXYFast(a3, a4);
  v5 = (*(int (__thiscall **)(CEcoManager *))(*(_DWORD *)this + 128))(this);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, 0x1389u, a2, v6, v5, 0, 0);
  v9 = 0;
  INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v8);
  v9 = -1;
  CEvn_Logic::~CEvn_Logic(v8);
  return 1;
}


// address=[0x133cf00]
// Decompiled from char __thiscall CEcoManager::GetPositionWorkingArea(CEcoManager *this, int a2, int *a3, int *a4)
bool  CEcoManager::GetPositionWorkingArea(int,int &,int &) {
  
  void *v5; // [esp+0h] [ebp-Ch]
  int WorkingAreaPackedXY; // [esp+4h] [ebp-8h]

  if ( !(*(unsigned __int8 (__thiscall **)(CEcoManager *, int))(*(_DWORD *)this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1135, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  *a3 = 0;
  *a4 = 0;
  v5 = (void *)CBuildingMgr::operator[](a2);
  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(v5);
  *a3 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
  *a4 = Y16X16::UnpackYFast(WorkingAreaPackedXY);
  return 1;
}


// address=[0x133cfa0]
// Decompiled from int __thiscall CEcoManager::GetContentOfWorkingArea(void *this, unsigned int a2, int a3, int a4)
int  CEcoManager::GetContentOfWorkingArea(enum BUILDING_TYPES,int,int) {
  
  _DWORD v5[4]; // [esp+0h] [ebp-38h] BYREF
  void *v6; // [esp+10h] [ebp-28h]
  int v7; // [esp+14h] [ebp-24h]
  int v8; // [esp+18h] [ebp-20h]
  int v9; // [esp+1Ch] [ebp-1Ch]
  int v10; // [esp+20h] [ebp-18h]
  int v11; // [esp+24h] [ebp-14h]
  unsigned int v12; // [esp+28h] [ebp-10h]
  int v13; // [esp+2Ch] [ebp-Ch] BYREF
  int v14; // [esp+30h] [ebp-8h] BYREF
  int v15; // [esp+34h] [ebp-4h]

  v6 = this;
  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1156, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)_should_initialize_environment_1(a3, a4)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1157, "CheckXY(_iWorldX, _iWorldY)") == 1 )
  {
    __debugbreak();
  }
  v11 = (*(int (__thiscall **)(void *, unsigned int))(*(_DWORD *)v6 + 124))(v6, a2);
  if ( v11 > 7 )
    v11 = 7;
  v15 = 0;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v5, a3, a4, v11);
  v12 = a2 - 11;
  switch ( a2 )
  {
    case 0xBu:
      while ( CSpiralWalk::NextXY(v5, &v13, &v14) )
      {
        v10 = CWorldManager::Index(v13, v14);
        if ( (CWorldManager::Ground(v10) & 0xF0) == 0x10
          && (CWorldManager::Flags(v10) & 0xD) == 0
          && (int)CSearchRoutines::CalcRawness(v10) <= 7 )
        {
          ++v15;
        }
      }
      break;
    case 0x23u:
      while ( CSpiralWalk::NextXY(v5, &v13, &v14) )
      {
        v9 = CWorldManager::Index(v13, v14);
        if ( (CWorldManager::Ground(v9) & 0xF0) == 0x10
          && (CWorldManager::Flags(v9) & 0xD) == 0
          && (int)CSearchRoutines::CalcRawness(v9) > 7 )
        {
          ++v15;
        }
      }
      break;
    case 0x24u:
      while ( CSpiralWalk::NextXY(v5, &v13, &v14) )
      {
        v8 = CWorldManager::Index(v13, v14);
        if ( (CWorldManager::Ground(v8) & 0xF0) == 0x40
          && (CWorldManager::Flags(v8) & 0xD) == 0
          && (int)CSearchRoutines::CalcRawness(v8) <= 7 )
        {
          ++v15;
        }
      }
      break;
    case 0x52u:
      while ( CSpiralWalk::NextXY(v5, &v13, &v14) )
      {
        v7 = CWorldManager::Index(v13, v14);
        if ( (CWorldManager::Ground(v7) & 0xF0) == 0x10
          && (CWorldManager::Flags(v7) & 0xD) == 0
          && (int)CSearchRoutines::CalcRawness(v7) > 7 )
        {
          ++v15;
        }
      }
      break;
    default:
      return v15;
  }
  return v15;
}


// address=[0x133d2a0]
// Decompiled from int __thiscall CEcoManager::GetWorkingAreaSize(void *this, unsigned int a2)
int  CEcoManager::GetWorkingAreaSize(enum BUILDING_TYPES) {
  
  int v2; // eax

  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1265, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 136))(this);
  return *(_DWORD *)(CBuildingInfoMgr::GetBuildingInfo(v2, a2) + 492);
}


// address=[0x133d310]
// Decompiled from int __thiscall CEcoManager::GetPlayerId(CEcoManager *this)
int  CEcoManager::GetPlayerId(void) {
  
  int v1; // eax

  v1 = CEcoSectorMgr::operator[](*((_DWORD *)this + 1));
  CEcoSector::Owner(v1);
  return *((_DWORD *)this + 2);
}


// address=[0x133d340]
// Decompiled from int __thiscall CEcoManager::GetRace(CEcoManager *this)
int  CEcoManager::GetRace(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = (*(int (__thiscall **)(CEcoManager *))(*(_DWORD *)this + 128))(this);
  return CPlayerManager::Race(v2);
}


// address=[0x133d370]
// Decompiled from int __thiscall CEcoManager::GetRangeOfTower(void *this, unsigned int a2)
int  CEcoManager::GetRangeOfTower(enum BUILDING_TYPES) {
  
  int v2; // eax

  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1293, "CheckBuildingType(_iBuildingType2)") == 1 )
  {
    __debugbreak();
  }
  v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 136))(this);
  return *(_DWORD *)(CBuildingInfoMgr::GetBuildingInfo(v2, a2) + 484);
}


// address=[0x133d3e0]
// Decompiled from int __thiscall CEcoManager::GetGoodAmount(int *this, int a2)
int  CEcoManager::GetGoodAmount(enum PILE_TYPES) {
  
  CEcoSector *v2; // eax

  if ( !(unsigned __int8)sub_13406F0(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1305, "CheckGoodType(_iGoodType)") == 1 )
  {
    __debugbreak();
  }
  v2 = (CEcoSector *)CEcoSectorMgr::operator[](this[1]);
  return CEcoSector::NrOfGoods(v2, a2);
}


// address=[0x133d440]
// Decompiled from int __thiscall CEcoManager::WorkerDeltaAmount(CEcoManager *this, int a2)
int  CEcoManager::WorkerDeltaAmount(int) {
  
  CEcoSector *v2; // eax

  v2 = (CEcoSector *)CEcoSectorMgr::operator[](*((_DWORD *)this + 1));
  return CEcoSector::WorkerDeltaAmount(v2, a2);
}


// address=[0x133d470]
// Decompiled from int __thiscall CEcoManager::GetSettlerAmount(int *this, int a2)
int  CEcoManager::GetSettlerAmount(enum SETTLER_TYPES) {
  
  CEcoSector *v2; // eax

  if ( !(unsigned __int8)sub_1340720(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1323, "CheckSettlerType(_iSettlerType)") == 1 )
  {
    __debugbreak();
  }
  v2 = (CEcoSector *)CEcoSectorMgr::operator[](this[1]);
  return CEcoSector::NrOfSettler(v2, a2);
}


// address=[0x133d4d0]
// Decompiled from int __thiscall CEcoManager::GetBuildingAmount(CEcoManager *this, unsigned int a2)
int  CEcoManager::GetBuildingAmount(enum BUILDING_TYPES) {
  
  int v3; // [esp+4h] [ebp-14h]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  if ( !CheckBuildingType(a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 1333, "CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  v3 = (*(int (__thiscall **)(CEcoManager *))(*(_DWORD *)this + 128))(this);
  v5 = 0;
  for ( i = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, v3, a2);
        i;
        i = IAnimatedEntity::Next(BuildingPtr) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, i);
    if ( CEcoManager::GetBuildingEcoSectorID(this, (struct CBuilding *)BuildingPtr) == *((_DWORD *)this + 1) )
      ++v5;
  }
  return v5;
}


// address=[0x133d590]
// Decompiled from int __thiscall CEcoManager::GetBuildingIDs(_DWORD *this, int a2, int a3)
int  CEcoManager::GetBuildingIDs(enum BUILDING_TYPES,class std::vector<int,class std::allocator<int> > &) {
  
  int v3; // eax
  int BuildingEcoSectorID_0; // eax
  int v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+4h] [ebp-10h]
  _DWORD *BuildingPtr; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h] BYREF
  _DWORD *v10; // [esp+10h] [ebp-4h]

  v10 = this;
  if ( !(unsigned __int8)CheckBuildingType(a2)
    && BBSupportDbgReport(2, (int)"AI\\EcoManager\\CEcoManager.cpp", 1369, (int)"CheckBuildingType(_iBuildingType)") == 1 )
  {
    __debugbreak();
  }
  v3 = (*(int (__thiscall **)(_DWORD *))(*v10 + 128))(v10);
  std::vector<int>::clear(v3, 0);
  for ( i = CBuildingMgr::GetFirstBuildingId(v6, a2); i; i = IAnimatedEntity::Next(BuildingPtr) )
  {
    BuildingPtr = (_DWORD *)CBuildingMgr::GetBuildingPtr(i);
    if ( IEntity::FlagBits(BuildingPtr, 0x3000000) )
    {
      BuildingEcoSectorID_0 = CEcoManager::GetBuildingEcoSectorID(BuildingPtr);
      if ( BuildingEcoSectorID_0 == v10[1] )
      {
        std::vector<int>::push_back(&i);
        ++v7;
      }
    }
    else
    {
      BBSupportTracePrintF(3, "### CEcoManager::GetBuildingIds(): Dead building in buildinglist! ###");
    }
  }
  return v7;
}


// address=[0x133d680]
// Decompiled from int __thiscall CEcoManager::GetResourceAmountAt(CEcoManager *this, int a2, Squares *a3, unsigned int a4)
int  CEcoManager::GetResourceAmountAt(int,int,int) {
  
  CAIResourceData *v5; // eax

  if ( !Squares::ValidVW(a3, a4) )
    return 0;
  if ( a2 >> 4 >= 8 )
    return 0;
  v5 = CAIResourceMap::ResourceDataVW(a3, a4);
  return CAIResourceData::ResourceAmount1(v5, a2 >> 4);
}


// address=[0x133d6e0]
// Decompiled from int __thiscall CEcoManager::GetResourceAmountAtAndAround(CEcoManager *this, int a2, Squares *a3, unsigned int a4)
int  CEcoManager::GetResourceAmountAtAndAround(int,int,int) {
  
  CAIResourceData *v5; // eax

  if ( !Squares::ValidVW(a3, a4) )
    return 0;
  if ( a2 >> 4 >= 8 )
    return 0;
  v5 = CAIResourceMap::ResourceDataVW(a3, a4);
  return CAIResourceData::ResourceAmount9(v5, a2 >> 4);
}


// address=[0x133d740]
// Decompiled from char __thiscall CEcoManager::GetResourceCenterXY(CEcoManager *this, int a2, Squares *a3, Squares *a4, int *a5, int *a6)
bool  CEcoManager::GetResourceCenterXY(int,int,int,int &,int &) {
  
  int v7; // edx
  int v8; // ecx
  int v9; // [esp+0h] [ebp-34h]
  int v10; // [esp+4h] [ebp-30h]
  int v11; // [esp+8h] [ebp-2Ch]
  int v12; // [esp+Ch] [ebp-28h]
  int v13; // [esp+10h] [ebp-24h]
  int v14; // [esp+14h] [ebp-20h]
  int v15; // [esp+18h] [ebp-1Ch]
  int i; // [esp+20h] [ebp-14h]
  int v18; // [esp+24h] [ebp-10h]
  int j; // [esp+28h] [ebp-Ch]
  int v20; // [esp+2Ch] [ebp-8h]
  char v21; // [esp+33h] [ebp-1h]

  v21 = 0;
  v18 = 0;
  v12 = 0;
  v11 = 0;
  v10 = Squares::VWToXY(a3);
  v9 = Squares::VWToXY(a4);
  if ( !(unsigned __int8)CWorldManager::InWorld(v10, v9) )
    return 0;
  for ( i = 0; i < 16; ++i )
  {
    for ( j = 0; j < 16; ++j )
    {
      v15 = j + v10;
      v13 = i + v9;
      if ( j + v10 <= CWorldManager::Width(i + v9) )
      {
        if ( v13 <= CWorldManager::Height(v8, v7) )
        {
          v20 = 0;
          v14 = 0;
          if ( a2 == 112 )
          {
            v20 = 1;
            v14 = 1;
          }
          if ( a2 == 96 )
          {
            v20 = 2;
            v14 = 2;
          }
          if ( (*(unsigned __int8 (__thiscall **)(CEcoManager *, int, int))(*(_DWORD *)this + 196))(
                 this,
                 v14 + v15,
                 v20 + v13) )
          {
            if ( (*(int (__thiscall **)(CEcoManager *, int, int, int))(*(_DWORD *)this + 236))(this, a2, v15, v13) )
            {
              v11 += v14 + v15;
              v12 += v20 + v13;
              ++v18;
            }
          }
        }
        else
        {
          j = 16;
          i = 16;
        }
      }
      else
      {
        j = 16;
      }
    }
  }
  if ( !v18 )
    return v21;
  *a5 = v11 / v18;
  *a6 = v12 / v18;
  return 1;
}


// address=[0x133d8f0]
// Decompiled from int __thiscall CEcoManager::GetSingleResourceConcentrationAt(CEcoManager *this, int a2, Squares *a3, Squares *a4)
int  CEcoManager::GetSingleResourceConcentrationAt(int,int,int) {
  
  int v5; // edx
  int v6; // ecx
  int v7; // [esp+0h] [ebp-28h]
  int v8; // [esp+4h] [ebp-24h]
  int v9; // [esp+8h] [ebp-20h]
  int v10; // [esp+Ch] [ebp-1Ch]
  int v11; // [esp+10h] [ebp-18h]
  int v12; // [esp+14h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-Ch]
  int v15; // [esp+20h] [ebp-8h]
  int j; // [esp+24h] [ebp-4h]

  if ( !Squares::ValidVW(a3, (unsigned int)a4) )
    return 0;
  v9 = 0;
  v8 = Squares::VWToXY(a3);
  v7 = Squares::VWToXY(a4);
  if ( !(unsigned __int8)CWorldManager::InWorld(v8, v7) )
    return 0;
  for ( i = 0; i < 16; ++i )
  {
    for ( j = 0; j < 16; ++j )
    {
      v10 = j + v8;
      v11 = i + v7;
      if ( j + v8 <= CWorldManager::Width(j + v8) )
      {
        if ( v11 <= CWorldManager::Height(v6, v5) )
        {
          v15 = 0;
          v12 = 0;
          if ( a2 == 112 )
          {
            v15 = 1;
            v12 = 1;
          }
          if ( a2 == 96 )
          {
            v15 = 2;
            v12 = 2;
          }
          if ( (*(unsigned __int8 (__thiscall **)(CEcoManager *, int, int))(*(_DWORD *)this + 196))(
                 this,
                 v12 + v10,
                 v15 + v11) )
          {
            v9 += (*(int (__thiscall **)(CEcoManager *, int, int, int))(*(_DWORD *)this + 236))(this, a2, v10, v11);
          }
        }
        else
        {
          j = 16;
          i = 16;
        }
      }
      else
      {
        j = 16;
      }
    }
  }
  return v9;
}


// address=[0x133da60]
// Decompiled from int __thiscall CEcoManager::GetSingleResourceConcentrationInside(int *this, int a2, int a3)
int  CEcoManager::GetSingleResourceConcentrationInside(int,class std::vector<struct SRESOURCECONCENTRATIONDATA,class std::allocator<struct SRESOURCECONCENTRATIONDATA> > &) {
  
  int v4; // [esp+4h] [ebp-A40h]
  __int16 Next; // [esp+8h] [ebp-A3Ch]
  _BYTE v7[2576]; // [esp+18h] [ebp-A2Ch] BYREF
  int v8; // [esp+A28h] [ebp-1Ch] BYREF
  __int16 v9; // [esp+A2Ch] [ebp-18h]
  __int16 v10; // [esp+A2Eh] [ebp-16h]
  __int16 v11; // [esp+A30h] [ebp-14h]
  char v12; // [esp+A32h] [ebp-12h]
  int v13; // [esp+A40h] [ebp-4h]

  CAI_Ecosector_Grid_Iterator::CAI_Ecosector_Grid_Iterator(v7);
  v13 = 0;
  std::vector<SRESOURCECONCENTRATIONDATA>::clear();
  CAI_Ecosector_Grid_Iterator::Init((CAI_Ecosector_Grid_Iterator *)v7, this[1]);
  while ( !(unsigned __int8)CAI_Ecosector_Grid_Iterator::IsEnd((CAI_Ecosector_Grid_Iterator *)v7) )
  {
    Next = CAI_Ecosector_Grid_Iterator::GetNext((CAI_Ecosector_Grid_Iterator *)v7);
    if ( (*(int (__thiscall **)(int *, int, _DWORD, int))(*this + 164))(
           this,
           a2,
           (unsigned __int8)Next,
           (Next & 0xFF00) >> 8) )
    {
      v12 = 1;
      v8 = a2;
      v10 = (unsigned __int8)Next;
      v11 = (Next & 0xFF00) >> 8;
      v9 = 0;
      v9 = (*(int (__thiscall **)(int *, int, _DWORD, int))(*this + 164))(
             this,
             a2,
             (unsigned __int8)Next,
             (Next & 0xFF00) >> 8);
      if ( v9 )
        std::vector<SRESOURCECONCENTRATIONDATA>::push_back(&v8);
    }
  }
  v4 = std::vector<SRESOURCECONCENTRATIONDATA>::size(a3);
  v13 = -1;
  CAI_Ecosector_Grid_Iterator::~CAI_Ecosector_Grid_Iterator(v7);
  return v4;
}


// address=[0x133dbf0]
// Decompiled from int __thiscall CEcoManager::GetAroundResourceConcentrationInside(int *this, int a2, int a3)
int  CEcoManager::GetAroundResourceConcentrationInside(int,class std::vector<struct SRESOURCECONCENTRATIONDATA,class std::allocator<struct SRESOURCECONCENTRATIONDATA> > &) {
  
  int v4; // [esp+4h] [ebp-A40h]
  __int16 Next; // [esp+8h] [ebp-A3Ch]
  _BYTE v7[2576]; // [esp+18h] [ebp-A2Ch] BYREF
  int v8; // [esp+A28h] [ebp-1Ch] BYREF
  __int16 v9; // [esp+A2Ch] [ebp-18h]
  __int16 v10; // [esp+A2Eh] [ebp-16h]
  __int16 v11; // [esp+A30h] [ebp-14h]
  char v12; // [esp+A32h] [ebp-12h]
  int v13; // [esp+A40h] [ebp-4h]

  CAI_Ecosector_Grid_Iterator::CAI_Ecosector_Grid_Iterator(v7);
  v13 = 0;
  std::vector<SRESOURCECONCENTRATIONDATA>::clear();
  CAI_Ecosector_Grid_Iterator::Init((CAI_Ecosector_Grid_Iterator *)v7, this[1]);
  while ( !(unsigned __int8)CAI_Ecosector_Grid_Iterator::IsEnd((CAI_Ecosector_Grid_Iterator *)v7) )
  {
    Next = CAI_Ecosector_Grid_Iterator::GetNext((CAI_Ecosector_Grid_Iterator *)v7);
    if ( (*(int (__thiscall **)(int *, int, _DWORD, int))(*this + 168))(
           this,
           a2,
           (unsigned __int8)Next,
           (Next & 0xFF00) >> 8) )
    {
      v12 = 1;
      v8 = a2;
      v9 = (*(int (__thiscall **)(int *, int, _DWORD, int))(*this + 168))(
             this,
             a2,
             (unsigned __int8)Next,
             (Next & 0xFF00) >> 8);
      v10 = (unsigned __int8)Next;
      v11 = (Next & 0xFF00) >> 8;
      std::vector<SRESOURCECONCENTRATIONDATA>::push_back(&v8);
    }
  }
  v4 = std::vector<SRESOURCECONCENTRATIONDATA>::size(a3);
  v13 = -1;
  CAI_Ecosector_Grid_Iterator::~CAI_Ecosector_Grid_Iterator(v7);
  return v4;
}


// address=[0x133dd70]
// Decompiled from int __thiscall CEcoManager::GetSingleResourceConcentrationOutside(unsigned __int8 *this, int a2, int a3)
int  CEcoManager::GetSingleResourceConcentrationOutside(int,class std::vector<struct SRESOURCECONCENTRATIONDATA,class std::allocator<struct SRESOURCECONCENTRATIONDATA> > &) {
  
  int v4; // eax
  int TileOfSquareVW; // [esp+0h] [ebp-28h]
  int v6; // [esp+4h] [ebp-24h]
  int j; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  int v10; // [esp+18h] [ebp-10h] BYREF
  __int16 v11; // [esp+1Ch] [ebp-Ch]
  __int16 v12; // [esp+1Eh] [ebp-Ah]
  __int16 v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+22h] [ebp-6h]

  std::vector<SRESOURCECONCENTRATIONDATA>::clear();
  if ( !CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, *((_DWORD *)this + 1)) )
    return 0;
  v4 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)this + 128))(this);
  v6 = COwnerMap::OwnerBit(v4);
  for ( i = 0; i < this[261716]; ++i )
  {
    for ( j = 0; j < this[261717]; ++j )
    {
      TileOfSquareVW = ITiling::FirstTileOfSquareVW(i, j);
      if ( (v6 & COwnerMap::OwnerBits1VW(i, j)) == 0 && !CEcoManager::IsMyTile((CEcoManager *)this, TileOfSquareVW) )
      {
        if ( (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 164))(this, a2, i, j) )
        {
          v14 = 0;
          v10 = a2;
          v11 = (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 164))(this, a2, i, j);
          v12 = i;
          v13 = j;
          std::vector<SRESOURCECONCENTRATIONDATA>::push_back(&v10);
        }
      }
    }
  }
  return std::vector<SRESOURCECONCENTRATIONDATA>::size(a3);
}


// address=[0x133dee0]
// Decompiled from int __thiscall CEcoManager::GetAroundResourceConcentrationOutside(unsigned __int8 *this, int a2, int a3)
int  CEcoManager::GetAroundResourceConcentrationOutside(int,class std::vector<struct SRESOURCECONCENTRATIONDATA,class std::allocator<struct SRESOURCECONCENTRATIONDATA> > &) {
  
  int v4; // eax
  int TileOfSquareVW; // [esp+0h] [ebp-28h]
  int v6; // [esp+4h] [ebp-24h]
  int j; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  int v10; // [esp+18h] [ebp-10h] BYREF
  __int16 v11; // [esp+1Ch] [ebp-Ch]
  __int16 v12; // [esp+1Eh] [ebp-Ah]
  __int16 v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+22h] [ebp-6h]

  std::vector<SRESOURCECONCENTRATIONDATA>::clear();
  if ( !CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, *((_DWORD *)this + 1)) )
    return 0;
  v4 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)this + 128))(this);
  v6 = COwnerMap::OwnerBit(v4);
  for ( i = 0; i < this[261716]; ++i )
  {
    for ( j = 0; j < this[261717]; ++j )
    {
      TileOfSquareVW = ITiling::FirstTileOfSquareVW(i, j);
      if ( (v6 & COwnerMap::OwnerBits1VW(i, j)) == 0 && !CEcoManager::IsMyTile((CEcoManager *)this, TileOfSquareVW) )
      {
        if ( (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 168))(this, a2, i, j) )
        {
          v14 = 0;
          v10 = a2;
          v11 = (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 168))(this, a2, i, j);
          v12 = i;
          v13 = j;
          std::vector<SRESOURCECONCENTRATIONDATA>::push_back(&v10);
        }
      }
    }
  }
  return std::vector<SRESOURCECONCENTRATIONDATA>::size(a3);
}


// address=[0x133e050]
// Decompiled from bool __thiscall CEcoManager::IsMyEcoSector(CEcoManager *this, int a2, int a3)
bool  CEcoManager::IsMyEcoSector(int,int) {
  
  return (unsigned __int8)CWorldManager::InWorld(a2, a3) && *((_DWORD *)this + 1) == CWorldManager::EcoSectorId(a2, a3);
}


// address=[0x133e0b0]
// Decompiled from char __thiscall CEcoManager::IsBorderElement(CEcoManager *this, Squares *a2, unsigned int a3)
bool  CEcoManager::IsBorderElement(int,int) {
  
  struct CTile *v5; // [esp+4h] [ebp-8h]
  int TileOfSquareVW; // [esp+8h] [ebp-4h]

  if ( !Squares::ValidVW(a2, a3) )
    return 0;
  TileOfSquareVW = ITiling::FirstTileOfSquareVW((int)a2, a3);
  if ( !CEcoManager::IsMyTile(this, TileOfSquareVW) )
    return 0;
  while ( TileOfSquareVW )
  {
    v5 = (struct CTile *)ITiling::Tile(TileOfSquareVW);
    if ( CTile::TilingType(v5) )
      return 1;
    if ( CTile::EcoSectorId(v5) != *((_DWORD *)this + 1) )
      return 1;
    TileOfSquareVW = CTile::NextSquareTile(v5);
  }
  return 0;
}


// address=[0x133e150]
// Decompiled from char __thiscall CEcoManager::IsResourceAround(CEcoManager *this, int a2, Squares *a3, unsigned int a4, int a5)
bool  CEcoManager::IsResourceAround(int,int,int,int) {
  
  int v7; // [esp+20h] [ebp-3Ch]
  int i; // [esp+24h] [ebp-38h]
  int j; // [esp+28h] [ebp-34h]
  _BYTE v10[44]; // [esp+2Ch] [ebp-30h] BYREF

  if ( !Squares::ValidVW(a3, a4) )
    return 0;
  v7 = a2 >> 4;
  qmemcpy(v10, CAIResourceMap::ResourceDataVW(a3, a4), 0x2Au);
  if ( CAIResourceData::ResourceAmount9((CAIResourceData *)v10, a2 >> 4) )
    return 1;
  if ( CAIResourceData::ResourceAmount1((CAIResourceData *)v10, v7) )
    return 1;
  for ( i = -a5; i < a5 + 1; ++i )
  {
    for ( j = -a5; j < a5 + 1; ++j )
    {
      if ( j * j + i * i <= a5 * a5
        && (i || j)
        && (int)a3 + i >= 0
        && (int)a3 + i <= *((unsigned __int8 *)this + 261716)
        && (int)(j + a4) >= 0
        && (int)(j + a4) <= *((unsigned __int8 *)this + 261717) )
      {
        qmemcpy(v10, CAIResourceMap::ResourceDataVW((char *)a3 + i, j + a4), 0x2Au);
        if ( CAIResourceData::ResourceAmount1((CAIResourceData *)v10, v7) )
          return 1;
      }
    }
  }
  return 0;
}


// address=[0x133e300]
// Decompiled from char __thiscall CEcoManager::IsLandscapeAround(CEcoManager *this, int a2, Squares *a3, unsigned int a4, int a5)
bool  CEcoManager::IsLandscapeAround(int,int,int,int) {
  
  int i; // [esp+20h] [ebp-38h]
  int j; // [esp+24h] [ebp-34h]
  _BYTE v9[44]; // [esp+28h] [ebp-30h] BYREF

  if ( !Squares::ValidVW(a3, a4) )
    return 0;
  qmemcpy(v9, CAIResourceMap::ResourceDataVW(a3, a4), 0x2Au);
  if ( CAIResourceData::GroundInfo1((CAIResourceData *)v9, a2) )
    return 1;
  for ( i = -a5; i < a5 + 1; ++i )
  {
    for ( j = -a5; j < a5 + 1; ++j )
    {
      if ( j * j + i * i <= a5 * a5
        && (i || j)
        && (int)a3 + i >= 0
        && (int)a3 + i <= *((unsigned __int8 *)this + 261716)
        && (int)(j + a4) >= 0
        && (int)(j + a4) <= *((unsigned __int8 *)this + 261717)
        && (*(int (__thiscall **)(CEcoManager *, int, int, unsigned int))(*(_DWORD *)this + 244))(
             this,
             a2,
             (int)a3 + i,
             j + a4) )
      {
        return 1;
      }
    }
  }
  return 0;
}


// address=[0x133e480]
// Decompiled from bool __thiscall CEcoManager::HasLand(CEcoManager *this, Squares *a2, unsigned int a3)
bool  CEcoManager::HasLand(int,int) {
  
  CAIResourceData *v4; // [esp+4h] [ebp-4h]

  if ( !Squares::ValidVW(a2, a3) )
    return 0;
  v4 = CAIResourceMap::ResourceDataVW(a2, a3);
  return (CAIResourceData::Flags1(v4) & 1) != 0;
}


// address=[0x133e4d0]
// Decompiled from bool __thiscall CEcoManager::HasLandAround(CEcoManager *this, Squares *a2, unsigned int a3)
bool  CEcoManager::HasLandAround(int,int) {
  
  CAIResourceData *v4; // [esp+4h] [ebp-4h]

  if ( !Squares::ValidVW(a2, a3) )
    return 0;
  v4 = CAIResourceMap::ResourceDataVW(a2, a3);
  return (CAIResourceData::Flags1(v4) & 1) != 0;
}


// address=[0x133e520]
// Decompiled from bool __thiscall CEcoManager::HasWater(CEcoManager *this, Squares *a2, unsigned int a3)
bool  CEcoManager::HasWater(int,int) {
  
  CAIResourceData *v4; // [esp+4h] [ebp-4h]

  if ( !Squares::ValidVW(a2, a3) )
    return 0;
  v4 = CAIResourceMap::ResourceDataVW(a2, a3);
  return (CAIResourceData::Flags1(v4) & 2) != 0;
}


// address=[0x133e570]
// Decompiled from bool __thiscall CEcoManager::HasWaterAround(CEcoManager *this, Squares *a2, unsigned int a3)
bool  CEcoManager::HasWaterAround(int,int) {
  
  CAIResourceData *v4; // [esp+4h] [ebp-4h]

  if ( !Squares::ValidVW(a2, a3) )
    return 0;
  v4 = CAIResourceMap::ResourceDataVW(a2, a3);
  return (CAIResourceData::Flags9(v4) & 2) != 0;
}


// address=[0x133e5c0]
// Decompiled from bool __thiscall CEcoManager::HasRiver(CEcoManager *this, Squares *a2, unsigned int a3)
bool  CEcoManager::HasRiver(int,int) {
  
  CAIResourceData *v4; // [esp+4h] [ebp-4h]

  if ( !Squares::ValidVW(a2, a3) )
    return 0;
  v4 = CAIResourceMap::ResourceDataVW(a2, a3);
  return (CAIResourceData::Flags1(v4) & 4) != 0;
}


// address=[0x133e610]
// Decompiled from bool __thiscall CEcoManager::HasRiverAround(CEcoManager *this, Squares *a2, unsigned int a3)
bool  CEcoManager::HasRiverAround(int,int) {
  
  CAIResourceData *v4; // [esp+4h] [ebp-4h]

  if ( !Squares::ValidVW(a2, a3) )
    return 0;
  v4 = CAIResourceMap::ResourceDataVW(a2, a3);
  return (CAIResourceData::Flags9(v4) & 4) != 0;
}


// address=[0x133e660]
// Decompiled from int __thiscall CEcoManager::GetResourceAmountXY(CEcoManager *this, int a2, int a3, int a4)
int  CEcoManager::GetResourceAmountXY(int,int,int) {
  
  if ( (unsigned __int8)CWorldManager::InWorld(a3, a4) )
    return CWorldManager::ResourceAmount(a3, a4, a2);
  else
    return 0;
}


// address=[0x133e6a0]
// Decompiled from bool __stdcall CEcoManager::HasLandscapeType(int a1, int a2, int a3)
bool  CEcoManager::HasLandscapeType(enum AI_ECO_LANDSCAPE_TYPE,int,int) {
  
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+14h] [ebp-4h]

  v5 = CWorldManager::Index(a2, a3);
  v4 = CWorldManager::Ground(v5) & 0xF0;
  v6 = 0;
  switch ( a1 )
  {
    case 2:
      v6 = 16;
      break;
    case 3:
      v6 = 32;
      break;
    case 4:
      v6 = 48;
      break;
    case 5:
      v6 = 64;
      break;
    case 6:
      v6 = 80;
      break;
    case 7:
      v6 = 96;
      break;
    case 8:
      v6 = 112;
      break;
    case 9:
      v6 = 128;
      break;
    case 10:
      v6 = 144;
      break;
    default:
      return v4 == v6;
  }
  return v4 == v6;
}


// address=[0x133e790]
// Decompiled from int __thiscall CEcoManager::GetLandscapeAmount(CEcoManager *this, int a2, Squares *a3, unsigned int a4)
int  CEcoManager::GetLandscapeAmount(int,int,int) {
  
  CAIResourceData *v5; // [esp+4h] [ebp-4h]

  if ( !Squares::ValidVW(a3, a4) )
    return 0;
  v5 = CAIResourceMap::ResourceDataVW(a3, a4);
  return CAIResourceData::GroundInfo1(v5, a2);
}


// address=[0x133e7e0]
// Decompiled from int __thiscall CEcoManager::GetLandscapeConcentrationInside(int *this, int a2, int a3)
int  CEcoManager::GetLandscapeConcentrationInside(int,class std::vector<struct SUNDERGROUNDCONCENTRATIONDATA,class std::allocator<struct SUNDERGROUNDCONCENTRATIONDATA> > &) {
  
  int v4; // [esp+4h] [ebp-A40h]
  __int16 Next; // [esp+8h] [ebp-A3Ch]
  _BYTE v7[2576]; // [esp+18h] [ebp-A2Ch] BYREF
  int v8; // [esp+A28h] [ebp-1Ch] BYREF
  __int16 v9; // [esp+A2Ch] [ebp-18h]
  __int16 v10; // [esp+A2Eh] [ebp-16h]
  __int16 v11; // [esp+A30h] [ebp-14h]
  char v12; // [esp+A32h] [ebp-12h]
  int v13; // [esp+A40h] [ebp-4h]

  CAI_Ecosector_Grid_Iterator::CAI_Ecosector_Grid_Iterator(v7);
  v13 = 0;
  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::clear();
  CAI_Ecosector_Grid_Iterator::Init((CAI_Ecosector_Grid_Iterator *)v7, this[1]);
  while ( !(unsigned __int8)CAI_Ecosector_Grid_Iterator::IsEnd((CAI_Ecosector_Grid_Iterator *)v7) )
  {
    Next = CAI_Ecosector_Grid_Iterator::GetNext((CAI_Ecosector_Grid_Iterator *)v7);
    if ( (*(int (__thiscall **)(int *, int, _DWORD, int))(*this + 244))(
           this,
           a2,
           (unsigned __int8)Next,
           (Next & 0xFF00) >> 8) )
    {
      v12 = 1;
      v8 = a2;
      v9 = (*(int (__thiscall **)(int *, int, _DWORD, int))(*this + 244))(
             this,
             a2,
             (unsigned __int8)Next,
             (Next & 0xFF00) >> 8);
      v10 = (unsigned __int8)Next;
      v11 = (Next & 0xFF00) >> 8;
      std::vector<SUNDERGROUNDCONCENTRATIONDATA>::push_back(&v8);
    }
  }
  v4 = std::vector<SUNDERGROUNDCONCENTRATIONDATA>::size(a3);
  v13 = -1;
  CAI_Ecosector_Grid_Iterator::~CAI_Ecosector_Grid_Iterator(v7);
  return v4;
}


// address=[0x133e960]
// Decompiled from int __thiscall CEcoManager::GetLandscapeConcentrationOutside(unsigned __int8 *this, int a2, int a3)
int  CEcoManager::GetLandscapeConcentrationOutside(int,class std::vector<struct SUNDERGROUNDCONCENTRATIONDATA,class std::allocator<struct SUNDERGROUNDCONCENTRATIONDATA> > &) {
  
  int v3; // eax
  int TileOfSquareVW; // [esp+0h] [ebp-24h]
  int v6; // [esp+4h] [ebp-20h]
  int j; // [esp+8h] [ebp-1Ch]
  int i; // [esp+Ch] [ebp-18h]
  int v10; // [esp+14h] [ebp-10h] BYREF
  __int16 v11; // [esp+18h] [ebp-Ch]
  __int16 v12; // [esp+1Ah] [ebp-Ah]
  __int16 v13; // [esp+1Ch] [ebp-8h]
  char v14; // [esp+1Eh] [ebp-6h]

  std::vector<SUNDERGROUNDCONCENTRATIONDATA>::clear();
  v3 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)this + 128))(this);
  v6 = COwnerMap::OwnerBit(v3);
  for ( i = 0; i < this[261716]; ++i )
  {
    for ( j = 0; j < this[261717]; ++j )
    {
      TileOfSquareVW = ITiling::FirstTileOfSquareVW(i, j);
      if ( (v6 & COwnerMap::OwnerBits1VW(i, j)) == 0 && !CEcoManager::IsMyTile((CEcoManager *)this, TileOfSquareVW) )
      {
        if ( (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(this, a2, i, j) )
        {
          v14 = 0;
          v10 = a2;
          v11 = (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(this, a2, i, j);
          v12 = i;
          v13 = j;
          std::vector<SUNDERGROUNDCONCENTRATIONDATA>::push_back(&v10);
        }
      }
    }
  }
  return std::vector<SUNDERGROUNDCONCENTRATIONDATA>::size(a3);
}


// address=[0x133eab0]
// Decompiled from int __thiscall CEcoManager::GetBorderElements(int *this, int a2)
int  CEcoManager::GetBorderElements(class std::vector<int,class std::allocator<int> > &) {
  
  int v3; // [esp+4h] [ebp-A38h]
  int v4; // [esp+8h] [ebp-A34h] BYREF
  int v5; // [esp+Ch] [ebp-A30h]
  int v6; // [esp+10h] [ebp-A2Ch]
  int Next; // [esp+14h] [ebp-A28h]
  int *v8; // [esp+18h] [ebp-A24h]
  _BYTE v9[2576]; // [esp+1Ch] [ebp-A20h] BYREF
  int v10; // [esp+A38h] [ebp-4h]

  v8 = this;
  CAI_Ecosector_Grid_Iterator::CAI_Ecosector_Grid_Iterator(v9);
  v10 = 0;
  std::vector<int>::clear();
  CAI_Ecosector_Grid_Iterator::Init((CAI_Ecosector_Grid_Iterator *)v9, v8[1]);
  while ( !(unsigned __int8)CAI_Ecosector_Grid_Iterator::IsEnd((CAI_Ecosector_Grid_Iterator *)v9) )
  {
    Next = CAI_Ecosector_Grid_Iterator::GetNext((CAI_Ecosector_Grid_Iterator *)v9);
    v5 = (unsigned __int8)Next;
    v6 = (Next & 0xFF00) >> 8;
    if ( (*(unsigned __int8 (__thiscall **)(int *, _DWORD, int))(*v8 + 200))(v8, (unsigned __int8)Next, v6) )
    {
      v4 = (unsigned __int16)v5 + (v6 << 16);
      std::vector<int>::push_back(&v4);
    }
  }
  v3 = std::vector<int>::size(a2);
  v10 = -1;
  CAI_Ecosector_Grid_Iterator::~CAI_Ecosector_Grid_Iterator(v9);
  return v3;
}


// address=[0x133ec00]
// Decompiled from int __thiscall CEcoManager::GetFirstRiverPos(CEcoManager *this, Squares *a2, Squares *a3)
int  CEcoManager::GetFirstRiverPos(int,int) {
  
  int v4; // [esp+8h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v4 = Squares::VWToXY(a2);
  v5 = Squares::VWToXY(a3);
  for ( i = 16; i > 0; --i )
  {
    for ( j = 16; j > 0; --j )
    {
      if ( (CWorldManager::Ground(j + v4, i + v5) & 0xF0) == 0x60 )
        return Y16X16::PackXYFast(j + v4, i + v5);
    }
  }
  return 0;
}


// address=[0x133eca0]
// Decompiled from int __thiscall CEcoManager::ConvertTo(_DWORD *this, int a2, int a3, _DWORD *a4, int a5)
int  CEcoManager::ConvertTo(enum BUILDING_TYPES,enum IECONOMANAGERGRIDRESOLUTION,struct SBUILDINFODATA *,struct SBUILDINFODATA *) {
  
  int j; // eax
  _Cnd_internal_imp_t *v7; // eax
  _Cnd_internal_imp_t *v8; // eax
  _Cnd_internal_imp_t *v9; // [esp+0h] [ebp-34h]
  int v10; // [esp+4h] [ebp-30h]
  int v11; // [esp+8h] [ebp-2Ch]
  CEcoManagerLeaf *Child; // [esp+Ch] [ebp-28h]
  int v13; // [esp+14h] [ebp-20h]
  int v14; // [esp+18h] [ebp-1Ch]
  int k; // [esp+1Ch] [ebp-18h]
  int v16; // [esp+20h] [ebp-14h]
  int i; // [esp+24h] [ebp-10h]
  CEcoManagerLeaf *Leaf; // [esp+2Ch] [ebp-8h]
  int v19; // [esp+30h] [ebp-4h]

  v19 = 0;
  if ( !a4 || !a5 )
    return 0;
  v14 = this[a2 + 4];
  if ( !v14 )
    return 0;
  v13 = a4[3];
  if ( a3 == v13 )
    return 0;
  if ( a3 <= v13 )
  {
    Leaf = (CEcoManagerLeaf *)CEcoManagerTree::FindLeaf(v14, a4[3], *a4, a4[1]);
    if ( !Leaf )
      return 0;
    if ( v13 == 64 && a3 == 16 )
    {
      for ( i = 0; i < CEcoManagerLeaf::GetNrChilds(Leaf); ++i )
      {
        if ( CEcoManagerLeaf::GetChild(Leaf, i) )
        {
          Child = CEcoManagerLeaf::GetChild(Leaf, i);
          v16 = 0;
          for ( j = CEcoManagerLeaf::GetNrChilds(Child); v16 < j; j = CEcoManagerLeaf::GetNrChilds(Child) )
          {
            if ( CEcoManagerLeaf::GetChild(Child, v16) )
            {
              *(_DWORD *)(a5 + 76 * v19 + 12) = a3;
              v7 = CEcoManagerLeaf::GetChild(Child, v16);
              CEcoManager::CopyData(v7, a5 + 76 * v19++);
            }
            ++v16;
          }
        }
      }
    }
    else
    {
      for ( k = 0; k < CEcoManagerLeaf::GetNrChilds(Leaf); ++k )
      {
        if ( CEcoManagerLeaf::GetChild(Leaf, k) )
        {
          *(_DWORD *)(a5 + 76 * v19 + 12) = a3;
          v8 = CEcoManagerLeaf::GetChild(Leaf, k);
          CEcoManager::CopyData(v8, a5 + 76 * v19++);
        }
      }
    }
  }
  else
  {
    v10 = (int)*a4 >> 1;
    v11 = (int)a4[1] >> 1;
    if ( a3 == 64 && v13 == 16 )
    {
      v10 = (int)*a4 >> 1;
      v11 = (int)a4[1] >> 1;
    }
    v9 = (_Cnd_internal_imp_t *)CEcoManagerTree::FindLeaf(v14, a3, v10, v11);
    if ( !v9 )
      return 0;
    *(_DWORD *)(a5 + 12) = a3;
    CEcoManager::CopyData(v9, a5);
  }
  return v19;
}


// address=[0x133eef0]
// Decompiled from int __thiscall CEcoManager::SendProduceOrder(int *this, int a2, int a3, unsigned int a4)
enum AI_ECOMANAGER_ERROR  CEcoManager::SendProduceOrder(int,enum PILE_TYPES,int) {
  
  char v4; // al
  unsigned int v6; // [esp+8h] [ebp-38h]
  _BYTE v8[32]; // [esp+10h] [ebp-30h] BYREF
  unsigned int v9; // [esp+34h] [ebp-Ch]
  unsigned __int16 v10; // [esp+38h] [ebp-8h]
  int v11; // [esp+3Ch] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CEcoManager::SendProduceOrder(): player %i, eco-sector %i, building id %i, good %i, amount %i",
    this[2],
    this[1],
    a2,
    a3,
    a4);
  v4 = (*(int (__thiscall **)(int *, _DWORD, _DWORD))(*this + 128))(this, 0, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, 0x13A9u, v6, a4, v4, v9, v10);
  v11 = 0;
  INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v8);
  v11 = -1;
  CEvn_Logic::~CEvn_Logic(v8);
  return 0;
}


// address=[0x133efd0]
// Decompiled from int __thiscall CEcoManager::RecruteSpecialist(int *this, int a2, int a3, unsigned int a4)
enum AI_ECOMANAGER_ERROR  CEcoManager::RecruteSpecialist(int,enum SETTLER_TYPES,int) {
  
  char v4; // al
  unsigned int v6; // [esp+8h] [ebp-38h]
  _BYTE v8[32]; // [esp+10h] [ebp-30h] BYREF
  unsigned int v9; // [esp+34h] [ebp-Ch]
  unsigned __int16 v10; // [esp+38h] [ebp-8h]
  int v11; // [esp+3Ch] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CEcoManager::RecruteSpecialist(): player %i, eco-sector %i, building id %i, settler type %i, amount %i",
    this[2],
    this[1],
    a2,
    a3,
    a4);
  v4 = (*(int (__thiscall **)(int *, _DWORD, _DWORD))(*this + 128))(this, 0, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, 0x13B7u, v6, a4, v4, v9, v10);
  v11 = 0;
  INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v8);
  v11 = -1;
  CEvn_Logic::~CEvn_Logic(v8);
  return 0;
}


// address=[0x133f0b0]
// Decompiled from int __thiscall CEcoManager::SwitchBuildingStatus(int *this, unsigned int a2)
enum AI_ECOMANAGER_ERROR  CEcoManager::SwitchBuildingStatus(int) {
  
  char v2; // al
  _BYTE v5[32]; // [esp+Ch] [ebp-30h] BYREF
  unsigned int v6; // [esp+30h] [ebp-Ch]
  unsigned __int16 v7; // [esp+34h] [ebp-8h]
  int v8; // [esp+38h] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CEcoManager::SwitchBuildingStatus(): player %i, eco-sector %i, building id %i",
    this[2],
    this[1],
    a2);
  if ( !(*(unsigned __int8 (__thiscall **)(int *, unsigned int))(*this + 304))(this, a2)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 2428, "CheckBuildingId(_iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  v2 = (*(int (__thiscall **)(int *, _DWORD, _DWORD))(*this + 128))(this, 0, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v5, 0x138Bu, a2, 0, v2, v6, v7);
  v8 = 0;
  INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v5);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v5);
  return 0;
}


// address=[0x133f1b0]
// Decompiled from int __thiscall CEcoManager::SendNetMessage(  _DWORD *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  int a5,  unsigned int a6)
enum AI_ECOMANAGER_ERROR  CEcoManager::SendNetMessage(int,int,int,int,int) {
  
  _BYTE v7[32]; // [esp+Ch] [ebp-50h] BYREF
  _BYTE v8[32]; // [esp+2Ch] [ebp-30h] BYREF
  int v9; // [esp+58h] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CEcoManager::SendNetMessage(): player %i, eco-sector %i",
    this[2],
    this[1]);
  if ( (a5 <= 0 || a5 >= 9)
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 2446, "0<_iData3 && _iData3 < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a2 == 5027 )
  {
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, 0x13A3u, ((unsigned __int16)a3 << 16) | (unsigned __int16)a4, a6, a5, 0, 0);
    v9 = 0;
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v8);
    v9 = -1;
    CEvn_Logic::~CEvn_Logic(v8);
  }
  else
  {
    if ( a6 && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 2458, "_iData4 == 0") == 1 )
      __debugbreak();
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, a2, a3, a4, a5, 0, 0);
    v9 = 1;
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
    v9 = -1;
    CEvn_Logic::~CEvn_Logic(v7);
  }
  return 0;
}


// address=[0x133f310]
// Decompiled from int __thiscall CEcoManager::GetResidenceNeed(CEcoManager *this)
int  CEcoManager::GetResidenceNeed(void) {
  
  int v1; // eax

  v1 = (*(int (__thiscall **)(CEcoManager *, CEcoManager *))(*(_DWORD *)this + 128))(this, this);
  return CStatistic::GetResidenceNeed((CStatistic *)&g_cStatistic, v1);
}


// address=[0x133f340]
// Decompiled from int __thiscall CEcoManager::GetResidenceSpace(CEcoManager *this)
int  CEcoManager::GetResidenceSpace(void) {
  
  int v1; // eax

  v1 = (*(int (__thiscall **)(CEcoManager *, CEcoManager *))(*(_DWORD *)this + 128))(this, this);
  return CStatistic::GetResidenceSpace((CStatistic *)&g_cStatistic, v1);
}


// address=[0x133f370]
// Decompiled from int __thiscall CEcoManager::GetTickCount(CEcoManager *this)
unsigned int  CEcoManager::GetTickCount(void) {
  
  return CStateGame::GetTickCounter(g_pGame);
}


// address=[0x133f390]
// Decompiled from int __thiscall CEcoManager::GetLastSpiralIndex(CEcoManager *this, int a2)
int  CEcoManager::GetLastSpiralIndex(int) {
  
  return CSpiralOffsets::First(a2 + 1) - 1;
}


// address=[0x133f3b0]
// Decompiled from int __thiscall CEcoManager::GetSpiralDeltaOffset(CEcoManager *this, int a2, int *a3, int *a4)
void  CEcoManager::GetSpiralDeltaOffset(int,int &,int &) {
  
  int result; // eax

  *a3 = CSpiralOffsets::DeltaX(a2);
  result = CSpiralOffsets::DeltaY(a2);
  *a4 = result;
  return result;
}


// address=[0x133f3e0]
// Decompiled from int __thiscall CEcoManager::GetStoragePlace(CEcoManager *this, int a2, int a3)
int  CEcoManager::GetStoragePlace(int,int) {
  
  CStorageBuildingRole *v3; // eax
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-4h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  if ( !BuildingPtr && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 2531, "pBuilding") == 1 )
    __debugbreak();
  if ( IEntity::Type((unsigned __int16 *)BuildingPtr) != 34
    && BBSupportDbgReport(2, "AI\\EcoManager\\CEcoManager.cpp", 2532, "pBuilding->Type() == BUILDING_STORAGEAREA") == 1 )
  {
    __debugbreak();
  }
  v3 = (CStorageBuildingRole *)CBuilding::Role(BuildingPtr);
  return CStorageBuildingRole::GetSpaceAmount(v3, a3);
}


// address=[0x133f470]
// Decompiled from char __thiscall CEcoManager::CheckBuildingId(_DWORD *this, unsigned int a2)
bool  CEcoManager::CheckBuildingId(unsigned int) {
  
  _DWORD *BuildingPtr; // [esp+Ch] [ebp-4h]

  if ( a2 < 0xFFFF && a2 != 0 )
  {
    BuildingPtr = (_DWORD *)CBuildingMgr::GetBuildingPtr(a2);
    if ( BuildingPtr )
    {
      if ( !IEntity::FlagBits(BuildingPtr, 0x4000000) && CBuilding::EcoSectorId(BuildingPtr) == this[1] )
        return 1;
    }
  }
  BBSupportTracePrintF(0, "CEcoManager::CheckBuildingId(): Invalid building id %i!", a2);
  return 0;
}


// address=[0x133f510]
// Decompiled from int __thiscall CEcoManager::GetMinimumCarrier(CEcoManager *this)
int  CEcoManager::GetMinimumCarrier(void) {
  
  CEcoSector *v1; // eax

  v1 = (CEcoSector *)CEcoSectorMgr::operator[](*((_DWORD *)this + 1));
  return CEcoSector::MinCarrier(v1);
}


// address=[0x133f540]
// Decompiled from void __thiscall CEcoManager::SetMinimumCarrier(CEcoManager *this, int a2)
void  CEcoManager::SetMinimumCarrier(int) {
  
  int v2; // [esp+0h] [ebp-10h]
  CEcoSector *v3; // [esp+Ch] [ebp-4h]

  v3 = (CEcoSector *)CEcoSectorMgr::operator[](*((_DWORD *)this + 1));
  v2 = a2 - CEcoSector::MinCarrier(v3);
  CEcoSector::ChangeMinMaxValues(v3, 1, v2);
}


// address=[0x133f590]
// Decompiled from int __thiscall CEcoManager::GetMinimumCarrierForRecruitment(CEcoManager *this)
int  CEcoManager::GetMinimumCarrierForRecruitment(void) {
  
  CEcoSector *v1; // eax

  v1 = (CEcoSector *)CEcoSectorMgr::operator[](*((_DWORD *)this + 1));
  return CEcoSector::ExtraMinCarrierForRecruitment(v1);
}


// address=[0x133f5c0]
// Decompiled from CEcoSector *__thiscall CEcoManager::SetMinimumCarrierForRecruitment(CEcoManager *this, int a2)
void  CEcoManager::SetMinimumCarrierForRecruitment(int) {
  
  int v3; // [esp+0h] [ebp-10h]
  CEcoSector *v4; // [esp+Ch] [ebp-4h]

  v4 = (CEcoSector *)CEcoSectorMgr::operator[](*((_DWORD *)this + 1));
  v3 = a2 - CEcoSector::ExtraMinCarrierForRecruitment(v4);
  return CEcoSector::SetExtraMinCarrierForRecruitment(v4, v3);
}


// address=[0x133f610]
// Decompiled from int __thiscall CEcoManager::GetConfigManager(CEcoManager *this)
class IConfigManager *  CEcoManager::GetConfigManager(void) {
  
  return CConfigManagerPtr::GetInstance(this);
}


// address=[0x133f620]
// Decompiled from int __thiscall CEcoManager::GetSectorAI(CEcoManager *this)
class IAISectorAI *  CEcoManager::GetSectorAI(void) {
  
  return *((_DWORD *)this + 65430);
}


// address=[0x133f640]
// Decompiled from int __thiscall CEcoManager::GetEventQueue(CEcoManager *this)
class IAIEventQueue *  CEcoManager::GetEventQueue(void) {
  
  return *((_DWORD *)this + 65431);
}


// address=[0x133f660]
// Decompiled from int CEcoManager::AddRef()
static int __cdecl CEcoManager::AddRef(void) {
  
  return ++CEcoManager::m_iRefCounter;
}


// address=[0x133f680]
// Decompiled from int CEcoManager::Release()
static int __cdecl CEcoManager::Release(void) {
  
  return --CEcoManager::m_iRefCounter;
}


// address=[0x133f6a0]
// Decompiled from int __thiscall CEcoManager::CreateTree(CEcoManager *this, int a2, CEcoManagerTree **a3)
enum AI_ECOMANAGER_ERROR  CEcoManager::CreateTree(enum BUILDING_TYPES,class CEcoManagerTree * &) {
  
  unsigned int v4; // eax
  unsigned __int16 *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-8h] [ebp-D8h]
  int v9; // [esp-8h] [ebp-D8h]
  int v10; // [esp-4h] [ebp-D4h]
  int v11; // [esp-4h] [ebp-D4h]
  _WORD v12[18]; // [esp+8h] [ebp-C8h] BYREF
  int v13; // [esp+2Ch] [ebp-A4h]
  int BuildingInfo; // [esp+30h] [ebp-A0h]
  int BoundingBoxInfo; // [esp+34h] [ebp-9Ch]
  int v16; // [esp+38h] [ebp-98h]
  int v18; // [esp+40h] [ebp-90h]
  int v19; // [esp+44h] [ebp-8Ch]
  int v20; // [esp+48h] [ebp-88h]
  int v21; // [esp+4Ch] [ebp-84h]
  int v22; // [esp+50h] [ebp-80h]
  int BlockingBitAmount; // [esp+54h] [ebp-7Ch]
  int v24; // [esp+58h] [ebp-78h]
  int v25; // [esp+5Ch] [ebp-74h]
  int v26; // [esp+60h] [ebp-70h]
  int TileOfSquareVW; // [esp+64h] [ebp-6Ch]
  int v28; // [esp+68h] [ebp-68h]
  CEcoManagerTree *v29; // [esp+6Ch] [ebp-64h]
  int v30; // [esp+70h] [ebp-60h]
  int v31; // [esp+74h] [ebp-5Ch] BYREF
  char v32; // [esp+78h] [ebp-58h]
  int v33; // [esp+7Ch] [ebp-54h]
  int v34; // [esp+80h] [ebp-50h]
  int v35; // [esp+84h] [ebp-4Ch]
  unsigned __int8 *BuildingPtr; // [esp+88h] [ebp-48h]
  int v37; // [esp+8Ch] [ebp-44h]
  int v38; // [esp+90h] [ebp-40h]
  float v39; // [esp+94h] [ebp-3Ch]
  int v40; // [esp+98h] [ebp-38h]
  CEcoManagerTree *v41; // [esp+9Ch] [ebp-34h]
  void *C; // [esp+A0h] [ebp-30h]
  int DefaultUndergroundByRace; // [esp+A4h] [ebp-2Ch]
  int v44; // [esp+A8h] [ebp-28h]
  int v45; // [esp+ACh] [ebp-24h]
  int v46; // [esp+B0h] [ebp-20h]
  int v47; // [esp+B4h] [ebp-1Ch]
  __int16 Next; // [esp+B8h] [ebp-18h]
  unsigned __int8 v49; // [esp+BEh] [ebp-12h]
  unsigned __int8 v50; // [esp+BFh] [ebp-11h]
  CEcoManager *v51; // [esp+C0h] [ebp-10h]
  int v52; // [esp+CCh] [ebp-4h]

  v51 = this;
  SAI_ECO_POSS_BUILD_PLACE::SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v12);
  v52 = 0;
  if ( CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, *((_DWORD *)v51 + 1)) )
  {
    if ( !*a3 )
    {
      C = operator new(0x10u);
      LOBYTE(v52) = 1;
      if ( C )
        v41 = CEcoManagerTree::CEcoManagerTree((CEcoManagerTree *)C);
      else
        v41 = 0;
      v29 = v41;
      LOBYTE(v52) = 0;
      *a3 = v41;
    }
    v35 = (*(int (__thiscall **)(CEcoManager *))(*(_DWORD *)v51 + 128))(v51);
    v47 = 0;
    v13 = COwnerMap::OwnerBit(v35);
    if ( *((_BYTE *)v51 + a2 + 431) )
    {
      v4 = std::vector<SAI_ECO_POSS_BUILD_PLACE>::size((char *)v51 + 16 * a2 + 214572);
      if ( *((_DWORD *)v51 + a2 + 64931) >= v4 )
      {
        v18 = 0;
        v52 = -1;
        SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v12);
        return v18;
      }
      else
      {
        v40 = *(unsigned __int16 *)std::vector<SAI_ECO_POSS_BUILD_PLACE>::operator[](*((_DWORD *)v51 + a2 + 64931));
        v49 = v40;
        v50 = (unsigned __int16)(v40 & 0xFF00) >> 8;
        if ( !*((_BYTE *)v51 + a2 + 514) )
        {
          std::vector<SPOSS_BUILD_PLACE>::clear();
          *((_BYTE *)v51 + a2 + 514) = 1;
          *((_BYTE *)v51 + a2 + 597) = 0;
          DefaultUndergroundByRace = 1;
          DefaultUndergroundByRace = CEcoManager::GetDefaultUndergroundByRace(v51);
          if ( a2 == 14 || a2 == 15 || a2 == 16 || a2 == 17 || a2 == 18 )
            DefaultUndergroundByRace = 4;
          v10 = v50;
          v24 = (*(int (__thiscall **)(CEcoManager *, int, _DWORD))(*(_DWORD *)v51 + 244))(
                  v51,
                  DefaultUndergroundByRace,
                  v49);
          v8 = (*(int (__thiscall **)(CEcoManager *, int))(*(_DWORD *)v51 + 136))(v51, a2);
          v5 = (unsigned __int16 *)CAIEcoSpecialBuildingInfos::TheObject();
          BlockingBitAmount = CAIEcoSpecialBuildingInfos::GetBlockingBitAmount(v5, v8, v10);
          v39 = (float)(v24 / BlockingBitAmount);
          if ( v39 >= 1.0 )
          {
            *((_DWORD *)v51 + a2 + 65097) = (int)v39;
            *((_DWORD *)v51 + a2 + 65014) = 256 / *((_DWORD *)v51 + a2 + 65097);
          }
          else
          {
            *((_DWORD *)v51 + a2 + 65014) = 256;
            *((_DWORD *)v51 + a2 + 65097) = 1;
          }
          *((_DWORD *)v51 + a2 + 65180) = 0;
        }
        v31 = 0;
        v32 = 0;
        if ( *((_BYTE *)v51 + a2 + 597) )
        {
          if ( std::vector<SPOSS_BUILD_PLACE>::size() )
          {
            CEcoManagerTree::CreateBaseLeaf(a2, v49, v50, (char *)v51 + 16 * a2 + 215900);
            ++*((_DWORD *)v51 + a2 + 65263);
          }
          *((_BYTE *)v51 + a2 + 514) = 0;
          ++*((_DWORD *)v51 + a2 + 65346);
          ++*((_DWORD *)v51 + a2 + 64931);
        }
        else
        {
          v21 = 16 * v49;
          v20 = 16 * v50;
          v16 = *((_DWORD *)v51 + a2 + 65180);
          v9 = (*(int (__thiscall **)(CEcoManager *))(*(_DWORD *)v51 + 136))(v51);
          v6 = CAIEcoSpecialBuildingInfos::TheObject();
          BoundingBoxInfo = CAIEcoSpecialBuildingInfos::GetBoundingBoxInfo(v6, v9, a2);
          v44 = 0;
          v22 = *((_DWORD *)v51 + a2 + 65180) * *((_DWORD *)v51 + a2 + 65014);
          while ( v44 < *((_DWORD *)v51 + a2 + 65014) )
          {
            v38 = v44 + v22;
            v45 = v21 + (v44 + v22) % 16;
            v46 = v20 + ((v44 + v22) >> 4);
            v34 = Y16X16::PackXYFast(v45, v46);
            if ( !(*(int (__thiscall **)(CEcoManager *, int, int, int))(*(_DWORD *)v51 + 236))(v51, v45, v46, 112)
              && !(*(int (__thiscall **)(CEcoManager *, int, int, int))(*(_DWORD *)v51 + 236))(v51, v45, v46, 96) )
            {
              v37 = (*(int (__thiscall **)(CEcoManager *, int, int))(*(_DWORD *)v51 + 44))(v51, a2, v34);
              if ( v37 )
              {
                BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v37);
                if ( BuildingPtr )
                {
                  v11 = IEntity::Type((unsigned __int16 *)BuildingPtr);
                  v7 = (*(int (__thiscall **)(CEcoManager *))(*(_DWORD *)v51 + 136))(v51);
                  BuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v7, v11);
                }
              }
              else
              {
                v33 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, v45, v46, v35, a2, 0);
                if ( v33 > 0 )
                {
                  v31 = v34;
                  v32 = v33;
                  std::vector<SPOSS_BUILD_PLACE>::push_back(&v31);
                }
              }
            }
            ++v44;
          }
          if ( ++*((_DWORD *)v51 + a2 + 65180) >= *((_DWORD *)v51 + a2 + 65097) )
            *((_BYTE *)v51 + a2 + 597) = 1;
        }
        v19 = 2;
        v52 = -1;
        SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v12);
        return v19;
      }
    }
    else if ( *((_BYTE *)v51 + a2 + 680) )
    {
      v47 = 0;
      while ( !(unsigned __int8)CAI_Ecosector_Grid_Iterator::IsEnd((CEcoManager *)((char *)v51 + 2576 * a2 + 764)) )
      {
        Next = CAI_Ecosector_Grid_Iterator::GetNext((CEcoManager *)((char *)v51 + 2576 * a2 + 764));
        v49 = Next;
        v50 = (unsigned __int16)(Next & 0xFF00) >> 8;
        if ( !(unsigned __int8)CEcoManager::IsChecked(v51, a2, (unsigned __int8)Next, v50) )
        {
          TileOfSquareVW = ITiling::FirstTileOfSquareVW(v49, v50);
          if ( CEcoManager::IsMyTile(v51, TileOfSquareVW) )
          {
            if ( (unsigned __int8)CEcoManager::WorkOnTile(v51, a2, v49, v50, *a3) )
            {
              v12[0] = Next;
              std::vector<SAI_ECO_POSS_BUILD_PLACE>::push_back(v12);
              CEcoManager::SetChecked(v51, a2, v49, v50);
            }
            if ( ++v47 == 2 )
            {
              v26 = 2;
              v52 = -1;
              SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v12);
              return v26;
            }
          }
        }
      }
      *((_BYTE *)v51 + a2 + 431) = 1;
      v25 = 2;
      v52 = -1;
      SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v12);
      return v25;
    }
    else
    {
      *((_BYTE *)v51 + a2 + 680) = 1;
      *((_BYTE *)v51 + a2 + 514) = 0;
      CAI_Ecosector_Grid_Iterator::Init((CEcoManager *)((char *)v51 + 2576 * a2 + 764), *((_DWORD *)v51 + 1));
      *((_DWORD *)v51 + a2 + 65263) = 0;
      *((_DWORD *)v51 + a2 + 65346) = 0;
      *((_DWORD *)v51 + a2 + 64931) = 0;
      v28 = 2;
      v52 = -1;
      SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v12);
      return v28;
    }
  }
  else
  {
    v30 = 1;
    v52 = -1;
    SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE((SAI_ECO_POSS_BUILD_PLACE *)v12);
    return v30;
  }
}


// address=[0x133fea0]
// Decompiled from char __thiscall CEcoManager::WorkOnTile(unsigned __int8 *this, int a2, int a3, int a4, int a5)
bool  CEcoManager::WorkOnTile(enum BUILDING_TYPES,int,int,class CEcoManagerTree *) {
  
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int v13; // [esp+14h] [ebp-2Ch]
  int DefaultUndergroundByRace; // [esp+1Ch] [ebp-24h]
  int v15; // [esp+20h] [ebp-20h]
  int v16; // [esp+24h] [ebp-1Ch]
  int v17; // [esp+28h] [ebp-18h]
  int v18; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h]
  int v20; // [esp+34h] [ebp-Ch]
  char v22; // [esp+3Fh] [ebp-1h]

  v22 = 1;
  if ( !(*(unsigned __int8 (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)this + 212))(this, a3, a4) )
    return 0;
  DefaultUndergroundByRace = CEcoManager::GetDefaultUndergroundByRace((CEcoManager *)this);
  if ( a2 != 14 && a2 != 15 && a2 != 16 && a2 != 17 && a2 != 18 )
  {
    v17 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)this + 136))(this);
    if ( v17 == 2 || v17 == 1 )
    {
      if ( v17 == 2 )
        v13 = 2;
      if ( v17 == 1 )
        v13 = 3;
      v6 = (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(
             this,
             DefaultUndergroundByRace,
             a3,
             a4);
      if ( (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(this, v13, a3, a4) + v6 <= 0 )
        return 0;
    }
    else if ( v17 == 4 )
    {
      v7 = (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(
             this,
             DefaultUndergroundByRace,
             a3,
             a4);
      v8 = (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(this, 2, a3, a4) + v7;
      if ( (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(this, 3, a3, a4) + v8 <= 0 )
        return 0;
    }
    else if ( (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(
                this,
                DefaultUndergroundByRace,
                a3,
                a4) <= 0 )
    {
      return 0;
    }
  }
  switch ( a2 )
  {
    case 1:
    case 7:
      return (*(unsigned __int8 (__thiscall **)(unsigned __int8 *, int, int, int, int))(*(_DWORD *)this + 204))(
               this,
               112,
               a3,
               a4,
               2)
          || (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 164))(this, 112, a3, a4);
    case 4:
      return (*(unsigned __int8 (__thiscall **)(unsigned __int8 *, int, int, int, int))(*(_DWORD *)this + 204))(
               this,
               96,
               a3,
               a4,
               2)
          || (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 164))(this, 96, a3, a4);
    case 5:
      return (*(int (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)this + 232))(this, a3, a4);
    case 6:
      v22 = (*(int (__thiscall **)(unsigned __int8 *, _DWORD, int, int, int))(*(_DWORD *)this + 204))(
              this,
              0,
              a3,
              a4,
              2);
      if ( !v22 || CEcoManager::CanBeReachedByFisher(this, a3, a4) )
        return v22;
      v22 = 0;
      v20 = -2;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
      v18 = 0;
      if ( a2 == 14 )
        v18 = 80;
      if ( a2 == 15 )
        v18 = 32;
      if ( a2 == 16 )
        v18 = 48;
      if ( a2 == 17 )
        v18 = 16;
      if ( a2 == 18 )
        v18 = 64;
      return (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 164))(this, v18, a3, a4) != 0;
    case 31:
    case 32:
      return (*(int (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)this + 224))(this, a3, a4);
    case 35:
      return (*(int (__thiscall **)(unsigned __int8 *, int, int, int, int))(*(_DWORD *)this + 208))(this, 6, a3, a4, 1);
    case 36:
      return (*(unsigned __int8 (__thiscall **)(unsigned __int8 *, int, int, int, int))(*(_DWORD *)this + 208))(
               this,
               2,
               a3,
               a4,
               1)
          || (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(this, 2, a3, a4);
    case 82:
      return (*(unsigned __int8 (__thiscall **)(unsigned __int8 *, int, int, int, int))(*(_DWORD *)this + 208))(
               this,
               1,
               a3,
               a4,
               1)
          || (*(int (__thiscall **)(unsigned __int8 *, int, int, int))(*(_DWORD *)this + 244))(this, 1, a3, a4);
    default:
      return v22;
  }
  while ( v20 < 3 )
  {
    for ( i = -2; i < 3; ++i )
    {
      if ( i * i + v20 * v20 <= 4 && (v20 || i) )
      {
        v15 = v20 + a3;
        v16 = i + a4;
        if ( v20 + a3 >= 0
          && v15 <= this[261716]
          && v16 >= 0
          && v16 <= this[261717]
          && (*(unsigned __int8 (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)this + 212))(this, v15, v16)
          && (*(unsigned __int8 (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)this + 220))(this, v15, v16)
          && CEcoManager::CanBeReachedByFisher(this, v15, v16) )
        {
          return 1;
        }
      }
    }
    ++v20;
  }
  return v22;
}


// address=[0x1340480]
// Decompiled from char __thiscall CEcoManager::IsMyTile(CEcoManager *this, int SquareTile)
bool  CEcoManager::IsMyTile(int) {
  
  struct CTile *v5; // [esp+8h] [ebp-4h]

  while ( SquareTile )
  {
    v5 = (struct CTile *)ITiling::Tile(SquareTile);
    if ( CTile::TilingType(v5) )
      return 0;
    if ( CTile::EcoSectorId(v5) == *((_DWORD *)this + 1) )
      return 1;
    SquareTile = CTile::NextSquareTile(v5);
  }
  return 0;
}


// address=[0x13404e0]
// Decompiled from int __stdcall CEcoManager::GetResourceAmountFast(int a1, int a2, int a3)
int  CEcoManager::GetResourceAmountFast(int,int,int) {
  
  CAIResourceData *v3; // eax

  v3 = CAIResourceMap::ResourceDataVW(a2, a3);
  return CAIResourceData::ResourceAmount1(v3, a1 >> 4);
}


// address=[0x1340510]
// Decompiled from int __thiscall CEcoManager::GetDefaultUndergroundByRace(CEcoManager *this)
int  CEcoManager::GetDefaultUndergroundByRace(void) {
  
  int result; // eax

  switch ( (*(int (__thiscall **)(CEcoManager *))(*(_DWORD *)this + 136))(this) )
  {
    case 0:
      result = 1;
      break;
    case 1:
      result = 1;
      break;
    case 2:
      result = 1;
      break;
    case 3:
      result = 0;
      break;
    case 4:
      result = 1;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}


// address=[0x1340580]
// Decompiled from int __thiscall CEcoManager::GetBuildingEcoSectorID(CEcoManager *this, struct CBuilding *a2)
int  CEcoManager::GetBuildingEcoSectorID(class CBuilding *) {
  
  int v2; // eax

  v2 = CBuilding::EnsignWorldIdx(a2);
  return CWorldManager::EcoSectorId(v2);
}


// address=[0x13405a0]
// Decompiled from char __thiscall CEcoManager::CanBeReachedByFisher(_DWORD *this, int a2, int a3)
bool  CEcoManager::CanBeReachedByFisher(int,int) {
  
  int j; // eax
  unsigned __int16 *v4; // eax
  void *v5; // eax
  unsigned __int8 *v8; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  void *v10; // [esp+14h] [ebp-8h]
  int v11; // [esp+18h] [ebp-4h]

  for ( i = ITiling::FirstTileOfSquareVW(a2, a3); i; i = CTile::NextSquareTile(v10) )
  {
    v10 = (void *)ITiling::Tile(i);
    if ( CTile::EcoSectorId(v10) == this[1] )
    {
      v8 = (unsigned __int8 *)CTile::LinkList(v10);
      v11 = 0;
      for ( j = CLinkList::Size(v8); v11 < j; j = CLinkList::Size(v8) )
      {
        v4 = (unsigned __int16 *)CLinkList::operator[](v11);
        v5 = (void *)ITiling::Tile(*v4);
        if ( (CTile::Type(v5, (int)v5) & 0x4000000) != 0 )
          return 1;
        ++v11;
      }
    }
  }
  return 0;
}


// address=[0x1340660]
// Decompiled from char __stdcall CEcoManager::CopyData(_Cnd_internal_imp_t *a1, int a2)
bool  CEcoManager::CopyData(class CEcoManagerLeaf *,struct SBUILDINFODATA *) {
  
  struct Concurrency::details::stl_condition_variable_win7 *BuildInfo; // eax

  if ( !a1 || !a2 )
    return 0;
  BuildInfo = CEcoManagerLeaf::GetBuildInfo(a1);
  SBUILDINFODATA::operator=(BuildInfo);
  return 1;
}


// address=[0x13467d0]
// Decompiled from bool __thiscall CEcoManager::IsChecked(unsigned __int8 *this, int a2, int a3, int a4)
bool  CEcoManager::IsChecked(enum BUILDING_TYPES,int,int) {
  
  if ( a3 < 0 || a4 < 0 )
    return 1;
  if ( 8 * a4 + (a3 >> 3) < 512 )
    return ((1 << (a3 & 7)) & this[512 * a2 + 217228 + 8 * a4 + (a3 >> 3)]) != 0;
  return 1;
}


// address=[0x13468b0]
// Decompiled from void *__thiscall CEcoManager::ResetCheckField(char *this, int a2)
void  CEcoManager::ResetCheckField(enum BUILDING_TYPES) {
  
  return memset(&this[512 * a2 + 217228], 0, 0x200u);
}


// address=[0x13468f0]
// Decompiled from int __thiscall CEcoManager::SetChecked(_BYTE *this, int a2, int a3, int a4)
void  CEcoManager::SetChecked(enum BUILDING_TYPES,int,int) {
  
  int result; // eax
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  if ( a3 < 0 || a4 < 0 )
    return result;
  v5 = a3 >> 3;
  v6 = 8 * a4;
  result = 8 * a4 + (a3 >> 3);
  if ( result >= 512 )
    return result;
  result = (1 << (a3 & 7)) | (unsigned __int8)this[512 * a2 + 217228 + v5 + v6];
  this[512 * a2 + 217228 + v5 + v6] = result;
  return result;
}


// address=[0x3ecd4b8]
// [Decompilation failed for static int CEcoManager::m_iRefCounter]

