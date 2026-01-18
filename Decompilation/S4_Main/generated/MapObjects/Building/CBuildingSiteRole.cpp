#include "CBuildingSiteRole.h"

// Definitions for class CBuildingSiteRole

// address=[0x13ffe60]
// Decompiled from int __cdecl CBuildingSiteRole::New(int a1)
class CPersistence * __cdecl CBuildingSiteRole::New(std::istream & a1) {
  
  if ( operator new(0x1C8u) )
    return CBuildingSiteRole::CBuildingSiteRole(a1);
  else
    return 0;
}


// address=[0x1447610]
// Decompiled from char __thiscall CBuildingSiteRole::HaveBoardPriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HaveBoardPriority(void)const {
  
  return *((_BYTE *)this + 443);
}


// address=[0x1447630]
// Decompiled from char __thiscall CBuildingSiteRole::HaveBuilderPriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HaveBuilderPriority(void)const {
  
  return *((_BYTE *)this + 442);
}


// address=[0x1447650]
// Decompiled from char __thiscall CBuildingSiteRole::HaveDiggerPriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HaveDiggerPriority(void)const {
  
  return *((_BYTE *)this + 441);
}


// address=[0x1447670]
// Decompiled from char __thiscall CBuildingSiteRole::HavePriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HavePriority(void)const {
  
  return *((_BYTE *)this + 440);
}


// address=[0x1447690]
// Decompiled from char __thiscall CBuildingSiteRole::HaveStonePriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HaveStonePriority(void)const {
  
  return *((_BYTE *)this + 444);
}


// address=[0x14476b0]
// Decompiled from int __thiscall CBuildingSiteRole::MaxNeededBuilder(CBuildingSiteRole *this)
int  CBuildingSiteRole::MaxNeededBuilder(void)const {
  
  return *(char *)(*((_DWORD *)this + 94) + 7);
}


// address=[0x14476d0]
// Decompiled from int __thiscall CBuildingSiteRole::MaxNeededDigger(CBuildingSiteRole *this)
int  CBuildingSiteRole::MaxNeededDigger(void)const {
  
  return *((_DWORD *)this + 97);
}


// address=[0x14fd8b0]
// Decompiled from int __cdecl CBuildingSiteRole::Load(int a1)
class CBuildingSiteRole * __cdecl CBuildingSiteRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CBuildingSiteRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1501250]
// Decompiled from CBuildingSiteRole *__thiscall CBuildingSiteRole::CBuildingSiteRole(CBuildingSiteRole *this)
 CBuildingSiteRole::CBuildingSiteRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CBuildingSiteRole::_vftable_;
  *((_BYTE *)this + 396) = 0;
  *((_DWORD *)this + 96) = -1;
  *((_DWORD *)this + 97) = 0;
  *((_DWORD *)this + 98) = 0;
  *((_BYTE *)this + 397) = 0;
  *((_BYTE *)this + 399) = 0;
  *((_BYTE *)this + 440) = 0;
  *((_BYTE *)this + 441) = 0;
  *((_BYTE *)this + 442) = 0;
  *((_BYTE *)this + 443) = 0;
  *((_BYTE *)this + 444) = 0;
  *((_BYTE *)this + 400) = 0;
  *((_BYTE *)this + 401) = 0;
  *((_BYTE *)this + 402) = 0;
  *((_DWORD *)this + 95) = 0;
  *((_BYTE *)this + 403) = 0;
  *((_BYTE *)this + 404) = 0;
  *((_BYTE *)this + 405) = 0;
  *((_BYTE *)this + 406) = 0;
  *((_BYTE *)this + 407) = 0;
  *((_BYTE *)this + 408) = 0;
  *((_DWORD *)this + 106) = 0;
  *((_DWORD *)this + 104) = 0;
  *((_DWORD *)this + 103) = 0;
  *((_DWORD *)this + 107) = 0;
  *((_DWORD *)this + 105) = 0;
  *((_WORD *)this + 216) = 0;
  *((_WORD *)this + 217) = 0;
  *((_WORD *)this + 218) = 0;
  *((_WORD *)this + 219) = 0;
  *((_DWORD *)this + 112) = 1;
  *((_DWORD *)this + 113) = 0;
  return this;
}


// address=[0x15013e0]
// Decompiled from int __thiscall CBuildingSiteRole::Init(int this, unsigned __int8 *a2)
void  CBuildingSiteRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  unsigned int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-Ch]
  int v7; // [esp-4h] [ebp-8h]

  *(_DWORD *)(this + 452) = 0;
  v7 = CBuilding::BuildingTypeEx(a2);
  v2 = IEntity::Race(a2);
  *(_DWORD *)(this + 376) = CBuildingInfoMgr::GetBuildingInfo(v2, v7);
  *(_BYTE *)(this + 400) = *(_BYTE *)(*(_DWORD *)(this + 376) + 7);
  *(_BYTE *)(this + 403) = *(_BYTE *)(*(_DWORD *)(this + 376) + 3);
  *(_BYTE *)(this + 404) = 0;
  *(_BYTE *)(this + 405) = *(_BYTE *)(*(_DWORD *)(this + 376) + 2);
  *(_BYTE *)(this + 406) = 0;
  *(_BYTE *)(this + 407) = *(_BYTE *)(*(_DWORD *)(this + 376) + 4);
  *(_BYTE *)(this + 408) = 0;
  v3 = IEntity::Race(a2);
  *(_DWORD *)(this + 424) = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, v3, 0x35u, 2u);
  *(_DWORD *)(this + 416) = 200
                          * (*(unsigned __int8 *)(this + 407)
                           + *(unsigned __int8 *)(this + 405)
                           + *(unsigned __int8 *)(this + 403));
  *(_DWORD *)(this + 420) = 131070 / *(_DWORD *)(this + 416);
  IEntity::ClearFlagBits(a2, EntityFlag_Ready);
  IEntity::SetFlagBits(a2, (EntityFlag)0x1001000u);
  *(_WORD *)(this + 8) = 0;
  *(_WORD *)(this + 6) = IEntity::ID();
  CBuildingSiteRole::PrepareGround((_DWORD *)this, (unsigned __int16 *)a2);
  IAnimatedEntity::RegisterForLogicUpdate(16);
  v6 = IEntity::ID();
  v4 = IEntity::OwnerId(a2);
  return (*(int (__thiscall **)(void *, int, int, int, _DWORD))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 5, v4, v6, 0);
}


// address=[0x1501570]
// Decompiled from void __thiscall CBuildingSiteRole::LogicUpdate(CBuildingSiteRole *this, unsigned __int8 *a2)
void  CBuildingSiteRole::LogicUpdate(class CBuilding * a2) {
  
  int v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // [esp-10h] [ebp-104h]
  int v39; // [esp-10h] [ebp-104h]
  int v40; // [esp-10h] [ebp-104h]
  int v41; // [esp-10h] [ebp-104h]
  int v42; // [esp-Ch] [ebp-100h]
  int v43; // [esp-Ch] [ebp-100h]
  int v44; // [esp-Ch] [ebp-100h]
  int v45; // [esp-8h] [ebp-FCh]
  int v46; // [esp-8h] [ebp-FCh]
  int v47; // [esp-8h] [ebp-FCh]
  int v48; // [esp-4h] [ebp-F8h]
  int v49; // [esp-4h] [ebp-F8h]
  __int16 v50; // [esp-4h] [ebp-F8h]
  int v51; // [esp-4h] [ebp-F8h]
  int v52; // [esp-4h] [ebp-F8h]
  int v53; // [esp-4h] [ebp-F8h]
  int v54; // [esp-4h] [ebp-F8h]
  __int16 v55; // [esp-4h] [ebp-F8h]
  _DWORD v56[7]; // [esp+4h] [ebp-F0h] BYREF
  _DWORD v57[7]; // [esp+20h] [ebp-D4h] BYREF
  _DWORD v58[7]; // [esp+3Ch] [ebp-B8h] BYREF
  _BYTE v59[12]; // [esp+58h] [ebp-9Ch] BYREF
  _BYTE v60[12]; // [esp+64h] [ebp-90h] BYREF
  int v61; // [esp+70h] [ebp-84h]
  int v62; // [esp+74h] [ebp-80h]
  int v63; // [esp+78h] [ebp-7Ch]
  int v64; // [esp+7Ch] [ebp-78h]
  int v65; // [esp+80h] [ebp-74h]
  unsigned int v66; // [esp+84h] [ebp-70h]
  std::_Iterator_base12 *v67; // [esp+88h] [ebp-6Ch]
  std::_Iterator_base12 *v68; // [esp+8Ch] [ebp-68h]
  int v69; // [esp+90h] [ebp-64h]
  int v70; // [esp+94h] [ebp-60h]
  _BYTE v71[12]; // [esp+98h] [ebp-5Ch] BYREF
  int v72; // [esp+A4h] [ebp-50h]
  int v73; // [esp+A8h] [ebp-4Ch]
  int v74; // [esp+ACh] [ebp-48h]
  int v75; // [esp+B0h] [ebp-44h]
  int v76; // [esp+B4h] [ebp-40h]
  int v77; // [esp+B8h] [ebp-3Ch]
  int EcoSectorId; // [esp+BCh] [ebp-38h]
  int v79; // [esp+C0h] [ebp-34h]
  int v80; // [esp+C4h] [ebp-30h]
  int v81; // [esp+C8h] [ebp-2Ch]
  int v82; // [esp+CCh] [ebp-28h]
  int v83; // [esp+D0h] [ebp-24h]
  int v84; // [esp+D4h] [ebp-20h]
  int i; // [esp+D8h] [ebp-1Ch]
  unsigned int v86; // [esp+DCh] [ebp-18h]
  char v87; // [esp+E3h] [ebp-11h]
  int v89; // [esp+F0h] [ebp-4h]

  if ( IEntity::FlagBits(a2, EntityFlag_Selected) )
    (*(void (__thiscall **)(CBuildingSiteRole *, unsigned __int8 *, int))(*(_DWORD *)this + 88))(this, a2, 1);
  IAnimatedEntity::RegisterForLogicUpdate(15);
  if ( IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
  {
    EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this, (struct CBuilding *)a2);
    if ( IEntity::Type((unsigned __int16 *)a2) == 49 || IEntity::Type((unsigned __int16 *)a2) == 80 )
      goto LABEL_77;
    if ( !EcoSectorId && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 439, "iEcoSectorId != 0") == 1 )
      __debugbreak();
    if ( EcoSectorId )
    {
LABEL_77:
      v82 = *((unsigned __int8 *)this + 396) - 2;
      switch ( v82 )
      {
        case 0:
          v77 = *((_DWORD *)this + 98);
          if ( v77 <= 0 )
            goto LABEL_12;
          CBuildingSiteRole::OrderDigger(this, (struct CBuilding *)a2);
          v76 = *((unsigned __int8 *)this + 397);
          if ( !v76 )
            return;
          if ( v77 / v76 < 25 )
            *((_BYTE *)this + 396) = 3;
          return;
        case 1:
          if ( *((int *)this + 98) <= 0 )
          {
LABEL_12:
            v2 = IEntity::OwnerId(a2);
            CBuildingSiteRole::DiggingIsReady(this, v2);
          }
          else
          {
            CBuildingSiteRole::OrderDigger(this, (struct CBuilding *)a2);
            CBuildingSiteRole::OrderMaterial(this, (struct CBuilding *)a2);
          }
          return;
        case 2:
          CBuildingSiteRole::OrderMaterial(this, (struct CBuilding *)a2);
          v83 = 0;
          std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v71);
          v89 = 0;
          v79 = 0;
          v70 = std::vector<unsigned int>::begin(v60);
          v69 = v70;
          LOBYTE(v89) = 1;
          std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v70);
          LOBYTE(v89) = 0;
          std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v60);
          while ( 1 )
          {
            v68 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v59);
            v67 = v68;
            LOBYTE(v89) = 2;
            v87 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v68);
            LOBYTE(v89) = 0;
            std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v59);
            if ( !v87 )
              break;
            ++v79;
            if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v71) )
            {
              for ( i = 31; i >= 0; --i )
              {
                v3 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v71);
                if ( (*v3 & (1 << i)) != 0 )
                {
                  v4 = IEntity::WorldIdx();
                  v5 = CWorldManager::X(v4);
                  v80 = v5 + 32 - i - **((char **)this + 94) - 1;
                  v6 = IEntity::WorldIdx();
                  v7 = CWorldManager::Y(v6);
                  v81 = v79 + v7 - *(char *)(*((_DWORD *)this + 94) + 1) - 1;
                  v8 = CWorldManager::Index(v80, v81);
                  CWorldManager::SetMoveCostsBits(v8, 7);
                  v9 = IEntity::WorldIdx();
                  CWorldManager::SetFlagBits(v9, 2u);
                  if ( !CWorldManager::CheckBlockable(v80, v81) )
                    v83 = 1;
                }
              }
            }
            std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v71);
          }
          if ( *(_BYTE *)(*((_DWORD *)this + 94) + 6) )
          {
            v48 = *((_DWORD *)this + 94) + 816;
            v45 = *(char *)(*((_DWORD *)this + 94) + 1);
            v42 = **((char **)this + 94);
            v38 = IEntity::Y(a2);
            v10 = IEntity::X(a2);
            CBuildingFlagsWalk::CBuildingFlagsWalk(v10, v38, v42, v45, v48);
            while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v58) )
            {
              v49 = CBuildingFlagsWalk::CurrentY(v58);
              v11 = CBuildingFlagsWalk::CurrentX(v58);
              v84 = CWorldManager::Index(v11, v49);
              v66 = CWorldManager::Flags(v84);
              if ( (v66 & 1) != 0 )
              {
                CWaterFlags::SetWaterFlagBitRepelling(v84);
                if ( CWorldManager::MapObjectId(v84) )
                  v83 = 1;
              }
              else
              {
                v12 = CWorldManager::Index(v80, v81);
                CWorldManager::SetMoveCostsBits(v12, 7);
                v13 = IEntity::WorldIdx();
                CWorldManager::SetFlagBits(v13, 2u);
                if ( !CWorldManager::CheckBlockable(v80, v81) )
                  v83 = 1;
              }
              CWorldManager::SetObjectId(v84, 0);
              CWorldManager::SetFlagBits(v84, 8u);
            }
            v14 = IEntity::X(a2);
            v64 = *(char *)(*((_DWORD *)this + 94) + 42) + v14;
            v15 = IEntity::Y(a2);
            v65 = *(char *)(*((_DWORD *)this + 94) + 43) + v15;
            v63 = CWorldManager::Index(v64, v65);
            v16 = CBuilding::BuildingTypeEx(a2);
            if ( CBuildingMgr::IsShipyardEx(v16) )
              CWaterFlags::SetWaterFlagBitRepelling(v63);
          }
          v17 = IEntity::Type((unsigned __int16 *)a2);
          if ( (unsigned __int8)CBuildingMgr::IsMilitary(v17) )
          {
            v18 = IEntity::WorldIdx();
            v19 = CWorldManager::X(v18);
            v74 = *(char *)(*((_DWORD *)this + 94) + 40) + v19;
            v20 = IEntity::WorldIdx();
            v21 = CWorldManager::Y(v20);
            v75 = *(char *)(*((_DWORD *)this + 94) + 41) + v21;
            v22 = CWorldManager::Index(v74, v75);
            CWorldManager::SetMoveCostsBits(v22, 7);
            v23 = IEntity::WorldIdx();
            CWorldManager::SetFlagBits(v23, 2u);
            if ( !CWorldManager::CheckBlockable(v74, v75) )
              v83 = 1;
          }
          if ( !v83 )
          {
            v24 = IEntity::Type((unsigned __int16 *)a2);
            if ( (unsigned __int8)CBuildingMgr::IsMilitary(v24) )
            {
              v25 = IEntity::WorldIdx();
              v26 = CWorldManager::X(v25);
              v61 = *(char *)(*((_DWORD *)this + 94) + 40) + v26;
              v27 = IEntity::WorldIdx();
              v28 = CWorldManager::Y(v27);
              v62 = *(char *)(*((_DWORD *)this + 94) + 41) + v28;
              CWorldManager::SetBlockedPosition(v61, v62);
            }
            *((_BYTE *)this + 396) = 5;
            v50 = IEntity::ID();
            v29 = IEntity::WorldIdx();
            CWorldManager::SetMapObjectId(v29, v50);
            CBuilding::SetToWorld(a2);
            v30 = IEntity::WorldIdx();
            CWorldManager::SetObjectId(v30, 0);
          }
          v89 = -1;
          std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v71);
          return;
        case 3:
          CBuildingSiteRole::OrderBuilder(this, (struct CBuilding *)a2);
          CBuildingSiteRole::OrderMaterial(this, (struct CBuilding *)a2);
          if ( *((_DWORD *)this + 103) < *((_DWORD *)this + 104) )
            return;
          CBuildingSiteRole::DeleteStakes(this, (struct CBuilding *)a2);
          CBuildingSiteRole::BuildingDone(this, (struct CBuilding *)a2);
          return;
        case 4:
          v51 = *((_DWORD *)this + 94) + 752;
          v46 = *(char *)(*((_DWORD *)this + 94) + 1);
          v43 = **((char **)this + 94);
          v39 = IEntity::Y(a2);
          v31 = IEntity::X(a2);
          CBuildingFlagsWalk::CBuildingFlagsWalk(v31, v39, v43, v46, v51);
          while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v57) )
          {
            v52 = CBuildingFlagsWalk::CurrentY(v57);
            v32 = CBuildingFlagsWalk::CurrentX(v57);
            v73 = CWorldManager::Index(v32, v52);
            CWorldManager::SetMoveCostsBits(v73, 7);
            CWorldManager::SetFlagBits(v73, 2u);
          }
          *((_BYTE *)this + 396) = 7;
          goto LABEL_57;
        case 5:
LABEL_57:
          v53 = *((_DWORD *)this + 94) + 752;
          v47 = *(char *)(*((_DWORD *)this + 94) + 1);
          v44 = **((char **)this + 94);
          v40 = IEntity::Y(a2);
          v33 = IEntity::X(a2);
          CBuildingFlagsWalk::CBuildingFlagsWalk(v33, v40, v44, v47, v53);
          break;
        case 6:
          v55 = IEntity::ID();
          v36 = IEntity::WorldIdx();
          CWorldManager::SetMapObjectId(v36, v55);
          v37 = IEntity::WorldIdx();
          CWorldManager::SetObjectId(v37, 0);
          IEntity::ClearFlagBits(a2, EntityFlag_Birth);
          IEntity::SetFlagBits(a2, EntityFlag_Ready);
          CBuilding::Ready(a2);
          return;
        default:
          return;
      }
      while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v56) )
      {
        v54 = CBuildingFlagsWalk::CurrentY(v56);
        v34 = CBuildingFlagsWalk::CurrentX(v56);
        if ( !CWorldManager::CheckBlockable(v34, v54) )
          return;
      }
      v86 = 1;
      if ( IEntity::Type((unsigned __int16 *)a2) == 49 )
      {
        v72 = CLogic::Effects((DWORD *)g_pLogic);
        v41 = IEntity::Y(a2);
        v35 = IEntity::X(a2);
        (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v72 + 16))(
          v72,
          58,
          0,
          v35,
          v41,
          0,
          0,
          0);
      }
      if ( !v86 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 716, "uDelay > 0") == 1 )
        __debugbreak();
      if ( v86 > 0x1F
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\BuildingSite.cpp",
             717,
             "uDelay <= CMapObjectMgr::MAX_DELTA_TICKS_FOR_LOGIC_UPDATE") == 1 )
      {
        __debugbreak();
      }
      if ( v86 )
      {
        if ( v86 > 0x1F )
          v86 = 31;
      }
      else
      {
        v86 = 1;
      }
      CBuilding::SetToWorld(a2);
      IAnimatedEntity::RegisterForLogicUpdate(v86);
      *((_BYTE *)this + 396) = 8;
    }
  }
}


// address=[0x1501eb0]
// Decompiled from void __thiscall CBuildingSiteRole::PostLoadInit(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v3);
  *((_BYTE *)this + 400) = *(_BYTE *)(*((_DWORD *)this + 94) + 7);
  *((_BYTE *)this + 403) = *(_BYTE *)(*((_DWORD *)this + 94) + 3);
  *((_BYTE *)this + 405) = *(_BYTE *)(*((_DWORD *)this + 94) + 2);
  *((_BYTE *)this + 407) = *(_BYTE *)(*((_DWORD *)this + 94) + 4);
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 6) )
  {
    if ( *((_BYTE *)this + 396) == 5 )
      IBuildingRole::PostLoadSetWaterFlags(this, a2);
  }
}


// address=[0x1501f60]
// Decompiled from int __thiscall CBuildingSiteRole::FillGfxInfo(CBuildingSiteRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CBuildingSiteRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-14h]
  int v6; // [esp+0h] [ebp-8h]

  if ( *((_DWORD *)this + 107) < *((_DWORD *)this + 103) - *((unsigned __int8 *)this + 401) )
  {
    if ( *((_DWORD *)this + 107) >= *((_DWORD *)this + 103) - 2 * *((unsigned __int8 *)this + 401) )
      *((_DWORD *)this + 107) += *((unsigned __int8 *)this + 401);
    else
      *((_DWORD *)this + 107) = *((_DWORD *)this + 103);
  }
  if ( *((_DWORD *)this + 107) >= *((_DWORD *)this + 104) / 2 )
  {
    v6 = 3;
    *((_DWORD *)a3 + 23) = 0xFFFF
                         - *((_DWORD *)this + 105)
                         - *((_DWORD *)this + 105) * (*((_DWORD *)this + 107) - *((_DWORD *)this + 104) / 2);
    if ( *((_DWORD *)a3 + 23) > 0xFFFFu )
      *((_DWORD *)a3 + 23) = 0;
    if ( *((_DWORD *)a3 + 23) > 0xFFFFu
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingSite.cpp",
           392,
           "_sGfxInfo.uConstructionProgress <= BUILDING_PROGRESS_MAX") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    v6 = 2;
    *((_DWORD *)a3 + 23) = 0xFFFF - *((_DWORD *)this + 105) * *((_DWORD *)this + 107);
    if ( *((_DWORD *)a3 + 23) > 0xFFFFu )
      *((_DWORD *)a3 + 23) = 0;
    if ( *((_DWORD *)a3 + 23) > 0xFFFFu
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingSite.cpp",
           378,
           "_sGfxInfo.uConstructionProgress <= BUILDING_PROGRESS_MAX") == 1 )
    {
      __debugbreak();
    }
  }
  v5 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
  v3 = IEntity::Race(a2);
  return CGfxManager::GetBuildingGfxInfo((int)a3, v3, v5, v6, 0);
}


// address=[0x1502120]
// Decompiled from int __thiscall CBuildingSiteRole::GoodArrive(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::GoodArrive(int a2) {
  
  return a2;
}


// address=[0x1502140]
// Decompiled from char __thiscall CBuildingSiteRole::SettlerEnter(CBuildingSiteRole *this, struct CBuilding *a2, int a3)
bool  CBuildingSiteRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  unsigned __int16 *v3; // eax

  v3 = (unsigned __int16 *)CSettlerMgr::operator[](a3);
  IEntity::Type(v3);
  return 1;
}


// address=[0x1502170]
// Decompiled from int __thiscall CBuildingSiteRole::GetBuildingNeed(CBuildingSiteRole *this, int a2)
int  CBuildingSiteRole::GetBuildingNeed(int a2)const {
  
  switch ( a2 )
  {
    case 7:
      return CBuildingSiteRole::NeedBoards(this);
    case 14:
      return CBuildingSiteRole::NeedGold(this);
    case 32:
      return CBuildingSiteRole::NeedStone(this);
  }
  return 0;
}


// address=[0x15021c0]
// Decompiled from int __thiscall CBuildingSiteRole::GetPileIdWithGood(CBuildingSiteRole *this, int a2)
int  CBuildingSiteRole::GetPileIdWithGood(int a2)const {
  
  switch ( a2 )
  {
    case 7:
      return *((unsigned __int16 *)this + 216);
    case 14:
      return *((unsigned __int16 *)this + 218);
    case 32:
      return *((unsigned __int16 *)this + 217);
  }
  return 0;
}


// address=[0x1502220]
// Decompiled from BOOL __thiscall CBuildingSiteRole::HaveBuildingMaterial(CBuildingSiteRole *this)
int  CBuildingSiteRole::HaveBuildingMaterial(void) {
  
  unsigned __int8 *v1; // eax
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // eax
  BOOL result; // eax

  result = 1;
  if ( *((_WORD *)this + 216) )
  {
    v1 = CPileMgr::operator[](*((unsigned __int16 *)this + 216));
    if ( (unsigned __int8)CPile::GoodAvailable(v1) )
      return result;
  }
  if ( *((_WORD *)this + 217) )
  {
    v2 = CPileMgr::operator[](*((unsigned __int16 *)this + 217));
    if ( (unsigned __int8)CPile::GoodAvailable(v2) )
      return result;
  }
  if ( !*((_WORD *)this + 218) )
    return 0;
  v3 = CPileMgr::operator[](*((unsigned __int16 *)this + 218));
  if ( !(unsigned __int8)CPile::GoodAvailable(v3) )
    return 0;
  return result;
}


// address=[0x15022d0]
// Decompiled from CBuildingSiteRole *__thiscall CBuildingSiteRole::SetDiggingInfos(CBuildingSiteRole *this, int a2, int a3)
void  CBuildingSiteRole::SetDiggingInfos(int a2, int a3) {
  
  CBuildingSiteRole *result; // eax

  if ( a3 <= 1 )
  {
    result = this;
    *((_DWORD *)this + 98) = 0;
    *((_DWORD *)this + 97) = 0;
  }
  else
  {
    *((_DWORD *)this + 96) = a2;
    *((_DWORD *)this + 98) = a3;
    result = this;
    *((_DWORD *)this + 97) = ((*((_DWORD *)this + 98) + 16) >> 5) + 1;
    if ( *((int *)this + 97) > 8 )
      *((_DWORD *)this + 97) = 8;
  }
  return result;
}


// address=[0x1502350]
// Decompiled from int __thiscall CBuildingSiteRole::BuildingProgress(CBuildingSiteRole *this)
int  CBuildingSiteRole::BuildingProgress(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( *((float *)this + 113) == 0.0 )
  {
    *((float *)this + 113) = (float)(*((_DWORD *)this + 104) + *((_DWORD *)this + 98)) / 100.0;
    if ( *((float *)this + 113) == 0.0 )
      *((float *)this + 113) = FLOAT_1_0;
  }
  if ( *((float *)this + 113) == 0.0
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 2185, "m_fBarDiv != 0.0f") == 1 )
  {
    __debugbreak();
  }
  v2 = (int)(float)(100.0
                  - (float)((float)(*((_DWORD *)this + 104) + *((_DWORD *)this + 98) - *((_DWORD *)this + 103))
                          / *((float *)this + 113)));
  if ( v2 > 100 )
    v2 = 100;
  if ( v2 < 0 )
    return 0;
  return v2;
}


// address=[0x1502460]
// Decompiled from void __thiscall CBuildingSiteRole::SwitchPriority(CBuildingSiteRole *this)
void  CBuildingSiteRole::SwitchPriority(void) {
  
  int EcoSectorId; // [esp+0h] [ebp-8h]

  EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this);
  if ( EcoSectorId > 0 )
  {
    if ( *((_BYTE *)this + 440) == 1 )
    {
      *((_BYTE *)this + 440) = 0;
      CBuildingSiteRole::CheckDeactivateUrgentBoards(this, EcoSectorId);
      CBuildingSiteRole::CheckDeactivateUrgentStones(this, EcoSectorId);
      CBuildingSiteRole::CheckDeactivateUrgentDigger(this, EcoSectorId);
      CBuildingSiteRole::CheckDeactivateUrgentBuilder(this, EcoSectorId);
    }
    else
    {
      *((_BYTE *)this + 440) = 1;
      CBuildingSiteRole::CheckActivateUrgentBoards(this, EcoSectorId);
      CBuildingSiteRole::CheckActivateUrgentStones(this, EcoSectorId);
      CBuildingSiteRole::CheckActivateUrgentDigger(this, EcoSectorId);
      CBuildingSiteRole::CheckActivateUrgentBuilder(this, EcoSectorId);
    }
  }
}


// address=[0x1502510]
// Decompiled from _DWORD *__thiscall CBuildingSiteRole::FillDialog(CBuildingSiteRole *this, struct CBuilding *a2, bool a3)
void  CBuildingSiteRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // eax
  CEcoSector *v6; // eax
  CEcoSector *v7; // eax
  int v8; // eax
  int v9; // eax
  CEcoSector *v10; // eax
  CEcoSector *v11; // eax
  CEcoSector *v12; // eax
  int v14; // [esp-8h] [ebp-70h]
  int v15; // [esp-8h] [ebp-70h]
  unsigned int v16; // [esp+4h] [ebp-64h]
  unsigned __int8 *v17; // [esp+8h] [ebp-60h]
  unsigned __int8 *v18; // [esp+Ch] [ebp-5Ch]
  unsigned __int8 *v19; // [esp+10h] [ebp-58h]
  unsigned __int8 *v20; // [esp+14h] [ebp-54h]
  unsigned __int8 *v21; // [esp+18h] [ebp-50h]
  unsigned __int8 *v22; // [esp+1Ch] [ebp-4Ch]
  int v23; // [esp+24h] [ebp-44h]
  int v24; // [esp+28h] [ebp-40h]
  int v25; // [esp+2Ch] [ebp-3Ch]
  int v26; // [esp+30h] [ebp-38h]
  int v27; // [esp+34h] [ebp-34h]
  int v28; // [esp+38h] [ebp-30h]
  CEvn_Event v30; // [esp+40h] [ebp-28h] BYREF
  int v31; // [esp+64h] [ebp-4h]

  v3 = CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v4 = CBuilding::EnsignWorldIdx(v3);
  v28 = CWorldManager::EcoSectorId(v4);
  if ( !v28 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 2208, "iESId > 0") == 1 )
    __debugbreak();
  dword_3F1E4C4 = 1;
  byte_3F1E4C8 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E4C9 = IEntity::Race(a2);
  byte_3F1E4CB = 1;
  v5 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  byte_3F1E4CC = IEntity::FlagBits(v5, (EntityFlag)0x1000u) != 0;
  byte_3F1E4E0 = *((_BYTE *)this + 440);
  v24 = *(char *)(*((_DWORD *)this + 94) + 479);
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 479) )
  {
    v6 = (CEcoSector *)CEcoSectorMgr::operator[](v28);
    if ( (int)CEcoSector::NrOfGoods(v6, v24) <= 0 )
      byte_3F1E4D2 = -(char)v24;
    else
      byte_3F1E4D2 = v24;
  }
  v23 = *(char *)(*((_DWORD *)this + 94) + 478);
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 478) )
  {
    v7 = (CEcoSector *)CEcoSectorMgr::operator[](v28);
    if ( (int)CEcoSector::NrOfSettler(v7, v23) <= 0 )
      byte_3F1E4D1 = -(char)v23;
    else
      byte_3F1E4D1 = v23;
  }
  byte_3F1E4CD = *(_DWORD *)(*((_DWORD *)this + 94) + 492) > 0;
  v14 = IEntity::Type((unsigned __int16 *)a2);
  v8 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4CF = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v8, v14, 0);
  v15 = IEntity::Type((unsigned __int16 *)a2);
  v9 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4D0 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v9, v15, 1u);
  byte_3F1E4CE = CBuildingSiteRole::BuildingProgress(this);
  if ( *((_WORD *)this + 216) )
  {
    v27 = CBuildingSiteRole::NeedBoards(this);
    v10 = (CEcoSector *)CEcoSectorMgr::operator[](v28);
    if ( CEcoSector::NrOfGoods(v10, 7) < v27 )
      v27 = -v27;
    byte_3F1E4D5[0] = v27;
    if ( v27 )
      byte_3F1E4D4 = 7;
    else
      byte_3F1E4D4 = 0;
  }
  else
  {
    byte_3F1E4D4 = 0;
  }
  if ( *((_WORD *)this + 217) )
  {
    v26 = CBuildingSiteRole::NeedStone(this);
    v11 = (CEcoSector *)CEcoSectorMgr::operator[](v28);
    if ( CEcoSector::NrOfGoods(v11, 32) < v26 )
      v26 = -v26;
    byte_3F1E4D5[2] = v26;
    if ( v26 )
      *(&byte_3F1E4D4 + 2) = 32;
    else
      *(&byte_3F1E4D4 + 2) = 0;
  }
  else
  {
    *(&byte_3F1E4D4 + 2) = 0;
  }
  if ( *((_WORD *)this + 218) )
  {
    v25 = CBuildingSiteRole::NeedGold(this);
    v12 = (CEcoSector *)CEcoSectorMgr::operator[](v28);
    if ( CEcoSector::NrOfGoods(v12, 14) < v25 )
      v25 = -v25;
    byte_3F1E4D5[4] = v25;
    if ( v25 )
      *(&byte_3F1E4D4 + 4) = 14;
    else
      *(&byte_3F1E4D4 + 4) = 0;
  }
  else
  {
    *(&byte_3F1E4D4 + 4) = 0;
  }
  if ( *((_WORD *)this + 216) )
  {
    v22 = CPileMgr::operator[](*((unsigned __int16 *)this + 216));
    byte_3F1E4DB = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v22 + 40))(v22);
    v21 = CPileMgr::operator[](*((unsigned __int16 *)this + 216));
    byte_3F1E4DA = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v21 + 60))(v21);
  }
  else
  {
    byte_3F1E4DB = 0;
    byte_3F1E4DA = 0;
  }
  if ( *((_WORD *)this + 217) )
  {
    v20 = CPileMgr::operator[](*((unsigned __int16 *)this + 217));
    *(&byte_3F1E4DB + 2) = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v20 + 40))(v20);
    v19 = CPileMgr::operator[](*((unsigned __int16 *)this + 217));
    *(&byte_3F1E4DA + 2) = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v19 + 60))(v19);
  }
  else
  {
    *(&byte_3F1E4DB + 2) = 0;
    *(&byte_3F1E4DA + 2) = 0;
  }
  if ( *((_WORD *)this + 218) )
  {
    v18 = CPileMgr::operator[](*((unsigned __int16 *)this + 218));
    *(&byte_3F1E4DB + 4) = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v18 + 40))(v18);
    v17 = CPileMgr::operator[](*((unsigned __int16 *)this + 218));
    *(&byte_3F1E4DA + 4) = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v17 + 60))(v17);
  }
  else
  {
    *(&byte_3F1E4DB + 4) = 0;
    *(&byte_3F1E4DA + 4) = 0;
  }
  v16 = 604;
  if ( !a3 )
    v16 = 602;
  CEvn_Event::CEvn_Event(&v30, v16, 0, (unsigned int)&g_cBuildingSiteInfo, 0);
  v31 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v30);
  v31 = -1;
  return CEvn_Event::~CEvn_Event(&v30);
}


// address=[0x1502ac0]
// Decompiled from char __thiscall CBuildingSiteRole::GetBuilderPos(CBuildingSiteRole *this, struct SBuilderPos *a2)
void  CBuildingSiteRole::GetBuilderPos(struct SBuilderPos & a2) {
  
  _DWORD *v2; // eax
  void *v3; // eax
  char result; // al

  if ( !*((_BYTE *)this + 401)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 950, "m_uBuilderAct") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 402) = *((_BYTE *)this + 401) - 1;
  if ( *((unsigned __int8 *)this + 402) >= *(char *)(*((_DWORD *)this + 94) + 7)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingSite.cpp",
         953,
         "m_uPosCounter < m_pBuildingInfo->iBuilderNumber") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 94)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 954, "m_pBuildingInfo != 0") == 1 )
  {
    __debugbreak();
  }
  v2 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  *(_DWORD *)a2 = *(char *)(*((_DWORD *)this + 94) + 3 * *((unsigned __int8 *)this + 402) + 8) + IEntity::X(v2);
  v3 = (void *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  *((_DWORD *)a2 + 1) = *(char *)(*((_DWORD *)this + 94) + 3 * *((unsigned __int8 *)this + 402) + 9) + IEntity::Y(v3);
  *((_DWORD *)a2 + 2) = *(char *)(*((_DWORD *)this + 94) + 3 * *((unsigned __int8 *)this + 402) + 10);
  result = *((_BYTE *)this + 402) + 1;
  *((_BYTE *)this + 402) = result;
  return result;
}


// address=[0x1502c30]
// Decompiled from CBuildingSiteRole *__thiscall CBuildingSiteRole::AddWork(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::AddWork(int a2) {
  
  CBuildingSiteRole *result; // eax
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax

  *((_DWORD *)this + 103) += a2;
  result = this;
  if ( *((_DWORD *)this + 103) < 200 * *((_DWORD *)this + 112) )
    return result;
  if ( *((_WORD *)this + 216)
    && (v3 = CPileMgr::operator[](*((unsigned __int16 *)this + 216)), (unsigned __int8)CPile::GoodAvailable(v3)) )
  {
    ++*((_DWORD *)this + 112);
    ++*((_BYTE *)this + 404);
    v4 = CPileMgr::operator[](*((unsigned __int16 *)this + 216));
    return CPile::DecreaseUnforeseen((CPile *)v4, 1);
  }
  else if ( *((_WORD *)this + 217)
         && (v5 = CPileMgr::operator[](*((unsigned __int16 *)this + 217)), (unsigned __int8)CPile::GoodAvailable(v5)) )
  {
    ++*((_DWORD *)this + 112);
    ++*((_BYTE *)this + 406);
    v6 = CPileMgr::operator[](*((unsigned __int16 *)this + 217));
    return CPile::DecreaseUnforeseen((CPile *)v6, 1);
  }
  else
  {
    result = this;
    if ( *((_WORD *)this + 218) )
    {
      v7 = CPileMgr::operator[](*((unsigned __int16 *)this + 218));
      result = (CBuildingSiteRole *)CPile::GoodAvailable(v7);
      if ( (_BYTE)result )
      {
        ++*((_DWORD *)this + 112);
        ++*((_BYTE *)this + 408);
        v8 = CPileMgr::operator[](*((unsigned __int16 *)this + 218));
        return CPile::DecreaseUnforeseen((CPile *)v8, 1);
      }
    }
  }
  return result;
}


// address=[0x1502de0]
// Decompiled from char *__thiscall CBuildingSiteRole::CBuildingSiteRole(char *this, int a2)
 CBuildingSiteRole::CBuildingSiteRole(std::istream & a2) {
  
  _DWORD v3[5]; // [esp+0h] [ebp-30h] BYREF
  int v4; // [esp+14h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+18h] [ebp-18h] BYREF
  char *v6; // [esp+1Ch] [ebp-14h]
  _DWORD *v7; // [esp+20h] [ebp-10h]
  int v8; // [esp+2Ch] [ebp-4h]

  v7 = v3;
  v6 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v8 = 0;
  *(_DWORD *)v6 = &CBuildingSiteRole::_vftable_;
  operator^<unsigned int>(a2, &v4);
  v3[4] = v4;
  if ( v4 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuildingSiteRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v6 + 380));
  operator^<int>(a2, (int)(v6 + 384));
  operator^<int>(a2, (int)(v6 + 388));
  operator^<int>(a2, (int)(v6 + 392));
  operator^<unsigned char>(a2, v6 + 396);
  operator^<unsigned char>(a2, v6 + 397);
  operator^<unsigned char>(a2, v6 + 398);
  operator^<unsigned char>(a2, v6 + 399);
  operator^<unsigned char>(a2, v6 + 401);
  operator^<unsigned char>(a2, v6 + 402);
  operator^<unsigned char>(a2, v6 + 404);
  operator^<unsigned char>(a2, v6 + 406);
  operator^<unsigned char>(a2, v6 + 408);
  operator^<int>(a2, (int)(v6 + 412));
  operator^<int>(a2, (int)(v6 + 416));
  operator^<int>(a2, (int)(v6 + 420));
  operator^<int>(a2, (int)(v6 + 424));
  operator^<int>(a2, (int)(v6 + 428));
  operator^<unsigned short>(a2, v6 + 432);
  operator^<unsigned short>(a2, v6 + 434);
  operator^<unsigned short>(a2, v6 + 436);
  operator^<unsigned short>(a2, v6 + 438);
  operator^<bool>(a2, v6 + 440);
  operator^<bool>(a2, v6 + 441);
  operator^<bool>(a2, v6 + 442);
  operator^<bool>(a2, v6 + 443);
  operator^<bool>(a2, v6 + 444);
  operator^<bool>(a2, v6 + 445);
  operator^<int>(a2, (int)(v6 + 448));
  LOBYTE(v8) = 1;
  operator^<float>(a2, v6 + 452);
  v8 = -1;
  return v6;
}


// address=[0x1503150]
// Decompiled from int __thiscall CBuildingSiteRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CBuildingSiteRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<int>((int)a2, (int *)v4 + 95);
  operator^<int>((int)a2, (int *)v4 + 96);
  operator^<int>((int)a2, (int *)v4 + 97);
  operator^<int>((int)a2, (int *)v4 + 98);
  operator^<unsigned char>(a2, (int)v4 + 396);
  operator^<unsigned char>(a2, (int)v4 + 397);
  operator^<unsigned char>(a2, (int)v4 + 398);
  operator^<unsigned char>(a2, (int)v4 + 399);
  operator^<unsigned char>(a2, (int)v4 + 401);
  operator^<unsigned char>(a2, (int)v4 + 402);
  operator^<unsigned char>(a2, (int)v4 + 404);
  operator^<unsigned char>(a2, (int)v4 + 406);
  operator^<unsigned char>(a2, (int)v4 + 408);
  operator^<int>((int)a2, (int *)v4 + 103);
  operator^<int>((int)a2, (int *)v4 + 104);
  operator^<int>((int)a2, (int *)v4 + 105);
  operator^<int>((int)a2, (int *)v4 + 106);
  operator^<int>((int)a2, (int *)v4 + 107);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 216);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 217);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 218);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 219);
  operator^<bool>((int)a2, (int)v4 + 440);
  operator^<bool>((int)a2, (int)v4 + 441);
  operator^<bool>((int)a2, (int)v4 + 442);
  operator^<bool>((int)a2, (int)v4 + 443);
  operator^<bool>((int)a2, (int)v4 + 444);
  operator^<bool>((int)a2, (int)v4 + 445);
  operator^<int>((int)a2, (int *)v4 + 112);
  return operator^<float>(a2, (char *)v4 + 452);
}


// address=[0x1506140]
// Decompiled from int __thiscall CBuildingSiteRole::~CBuildingSiteRole(CBuildingSiteRole *this)
 CBuildingSiteRole::~CBuildingSiteRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x15063b0]
// Decompiled from int __thiscall CBuildingSiteRole::ClassID(CBuildingSiteRole *this)
unsigned long  CBuildingSiteRole::ClassID(void)const {
  
  return CBuildingSiteRole::m_iClassID;
}


// address=[0x1506420]
// Decompiled from int __thiscall CBuildingSiteRole::GetBuildingRole(CBuildingSiteRole *this)
int  CBuildingSiteRole::GetBuildingRole(void) {
  
  return 0;
}


// address=[0x1506480]
// Decompiled from void __thiscall CBuildingSiteRole::InhabitantFlee(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::InhabitantFlee(int a2) {
  
  ;
}


// address=[0x3d8b11c]
// [Decompilation failed for static unsigned long CBuildingSiteRole::m_iClassID]

// address=[0x1503410]
// Decompiled from int __thiscall CBuildingSiteRole::GetEcoSectorId(CBuildingSiteRole *this)
int  CBuildingSiteRole::GetEcoSectorId(void) {
  
  unsigned __int8 *BuildingPtr; // [esp+0h] [ebp-8h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  return CBuildingSiteRole::GetEcoSectorId(this, (struct CBuilding *)BuildingPtr);
}


// address=[0x1503440]
// Decompiled from char __thiscall CBuildingSiteRole::CrushBuilding(CBuildingSiteRole *this)
bool  CBuildingSiteRole::CrushBuilding(void) {
  
  _BYTE v2[24]; // [esp+4h] [ebp-4Ch] BYREF
  int v3; // [esp+1Ch] [ebp-34h]
  int v4; // [esp+20h] [ebp-30h]
  _BYTE *v5; // [esp+24h] [ebp-2Ch]
  int v6; // [esp+28h] [ebp-28h]
  int v7; // [esp+2Ch] [ebp-24h]
  _DWORD *v8; // [esp+30h] [ebp-20h]
  int j; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  CBuildingSiteRole *v11; // [esp+3Ch] [ebp-14h]
  char v12; // [esp+43h] [ebp-Dh]
  int v13; // [esp+4Ch] [ebp-4h]

  v11 = this;
  CTrace::Print("CrushBuilding for building %u ", *((unsigned __int16 *)this + 3));
  CEntityEvent::CEntityEvent((CEntityEvent *)v2, 9u, 0, *((unsigned __int16 *)v11 + 3), 0, 0);
  v13 = 0;
  v5 = v2;
  CBuildingSiteRole::TidyUp(v11, (struct CEntityEvent *)v2);
  v8 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)v11 + 3));
  v3 = IEntity::X(v8);
  v4 = IEntity::Y(v8);
  if ( *((_BYTE *)v11 + 396) == 2 )
  {
    v7 = 31;
    v6 = IEntity::OwnerId((unsigned __int8 *)v8);
    for ( i = 0; i < v7; ++i )
    {
      for ( j = 0; j < v7; ++j )
      {
        if ( byte_409F9AD[30750 * v6 + 1 + 1025 * *((_DWORD *)v11 + 96) + 32 * j + i] )
          CWorldManager::ClearFlagBits(v3 + j - 15, v4 + i - 15, 16);
      }
    }
    byte_409F9AD[30750 * v6 + 1025 * *((_DWORD *)v11 + 96)] = 0;
    *((_DWORD *)v11 + 96) = -1;
  }
  CBuildingSiteRole::DeleteStakes(v11, (struct CBuilding *)v8);
  v12 = 1;
  v13 = -1;
  CEntityEvent::~CEntityEvent(v2);
  return v12;
}


// address=[0x15035e0]
// Decompiled from int __thiscall CBuildingSiteRole::Switch(CBuildingSiteRole *this)
void  CBuildingSiteRole::Switch(void) {
  
  int v1; // eax
  int v2; // eax
  void *v3; // eax
  int v5; // [esp-4h] [ebp-54h]
  _BYTE v6[24]; // [esp+4h] [ebp-4Ch] BYREF
  _BYTE v7[24]; // [esp+1Ch] [ebp-34h] BYREF
  _BYTE *v8; // [esp+34h] [ebp-1Ch]
  const struct CEntityEvent *v9; // [esp+38h] [ebp-18h]
  CBuilding *v10; // [esp+3Ch] [ebp-14h]
  CBuildingSiteRole *v11; // [esp+40h] [ebp-10h]
  int v12; // [esp+4Ch] [ebp-4h]

  v11 = this;
  v10 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  if ( IEntity::FlagBits(v10, (EntityFlag)0x1000u) )
  {
    CTrace::Print("BuildingSite %u stopped", *((unsigned __int16 *)v11 + 3));
    IEntity::ClearFlagBits(v10, (EntityFlag)0x1000u);
    CEntityEvent::CEntityEvent((CEntityEvent *)v7, 7u, 0, *((unsigned __int16 *)v11 + 3), 0, 0);
    v12 = 0;
    v9 = (const struct CEntityEvent *)v7;
    CBuildingSiteRole::TidyUp(v11, (struct CEntityEvent *)v7);
    CBuilding::NotifyAllObservers(v10, v9);
    CBuilding::DetachAllNonePileObservers(v10);
    *((_BYTE *)v11 + 397) = 0;
    *((_BYTE *)v11 + 401) = 0;
    v5 = *((unsigned __int16 *)v11 + 3);
    v1 = CBuilding::EnsignWorldIdx(v10);
    v2 = CWorldManager::EcoSectorId(v1);
    v3 = (void *)CEcoSectorMgr::operator[](v2);
    CEcoSector::CleanUpBuildingNeed(v3, v5);
    *((_BYTE *)v11 + 402) = 0;
    v12 = -1;
    return CEntityEvent::~CEntityEvent(v7);
  }
  else
  {
    CTrace::Print("BuildingSite %u started", *((unsigned __int16 *)v11 + 3));
    CEntityEvent::CEntityEvent((CEntityEvent *)v6, 8u, 0, *((unsigned __int16 *)v11 + 3), 0, 0);
    v12 = 1;
    v8 = v6;
    (*(void (__thiscall **)(CBuilding *, _BYTE *))(*(_DWORD *)v10 + 124))(v10, v6);
    IEntity::SetFlagBits(v10, (EntityFlag)0x1000u);
    IAnimatedEntity::RegisterForLogicUpdate(1);
    v12 = -1;
    return CEntityEvent::~CEntityEvent(v6);
  }
}


// address=[0x1503780]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivateUrgentBoards(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivateUrgentBoards(int a2) {
  
  CEcoSector *v2; // eax

  if ( *((_BYTE *)this + 443) )
  {
    *((_BYTE *)this + 443) = 0;
    v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    CEcoSector::ChangePrioBoards(v2, -1);
    CBuildingSiteRole::CheckDeactivatePriority(this, a2);
  }
}


// address=[0x15037d0]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivateUrgentStones(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivateUrgentStones(int a2) {
  
  CEcoSector *v2; // eax

  if ( *((_BYTE *)this + 444) )
  {
    *((_BYTE *)this + 444) = 0;
    v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    CEcoSector::ChangePrioStone(v2, -1);
    CBuildingSiteRole::CheckDeactivatePriority(this, a2);
  }
}


// address=[0x1503820]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivateUrgentBuilder(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivateUrgentBuilder(int a2) {
  
  CEcoSector *v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  if ( *((_BYTE *)this + 442) )
  {
    CTrace::Print("CheckDeactivateUrgentBuilder - DEACTIVATE for building %u", *((unsigned __int16 *)this + 3));
    *((_BYTE *)this + 442) = 0;
    v3 = -*(char *)(*((_DWORD *)this + 94) + 7);
    v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    CEcoSector::ChangePrioBuilder(v2, -1, v3);
    CBuildingSiteRole::CheckDeactivatePriority(this, a2);
  }
}


// address=[0x1503890]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivateUrgentDigger(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivateUrgentDigger(int a2) {
  
  CEcoSector *v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  if ( *((_BYTE *)this + 441) )
  {
    *((_BYTE *)this + 441) = 0;
    v3 = -*((_DWORD *)this + 97);
    v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    CEcoSector::ChangePrioDigger(v2, -1, v3);
    CBuildingSiteRole::CheckDeactivatePriority(this, a2);
  }
}


// address=[0x15038f0]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivatePriority(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivatePriority(int a2) {
  
  CEcoSector *v2; // eax
  CEcoSector *v3; // eax

  if ( !*((_BYTE *)this + 443) && !*((_BYTE *)this + 444) && !*((_BYTE *)this + 442) && !*((_BYTE *)this + 441) )
  {
    v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    if ( !CEcoSector::BuildingSitesWithPrio(v2)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingSite.cpp",
           1871,
           "g_cESMgr[ _iBuildingEcoSectorId ].BuildingSitesWithPrio() != 0") == 1 )
    {
      __debugbreak();
    }
    *((_BYTE *)this + 440) = 0;
    v3 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    CEcoSector::ChangeBuildingSitesWithPrio(v3, -1);
  }
}


// address=[0x15039a0]
// Decompiled from void __thiscall CBuildingSiteRole::CheckActivateUrgentBoards(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckActivateUrgentBoards(int a2) {
  
  CEcoSector *v2; // eax
  _DWORD *v3; // eax
  CEcoSector *v4; // eax
  CEcoSector *v5; // eax

  if ( CBuildingSiteRole::NeedBoards(this) )
  {
    v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    if ( (int)CEcoSector::BuildingSitesWithPrio(v2) < 10 )
    {
      v3 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
      if ( IEntity::FlagBits(v3, (EntityFlag)0x1000u) )
      {
        if ( !*((_BYTE *)this + 443) && !*((_BYTE *)this + 444) && !*((_BYTE *)this + 442) && !*((_BYTE *)this + 441) )
        {
          v4 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
          CEcoSector::ChangeBuildingSitesWithPrio(v4, 1);
        }
        if ( !*((_BYTE *)this + 443) )
        {
          *((_BYTE *)this + 443) = 1;
          v5 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
          CEcoSector::ChangePrioBoards(v5, 1);
        }
      }
    }
  }
}


// address=[0x1503a80]
// Decompiled from void __thiscall CBuildingSiteRole::CheckActivateUrgentStones(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckActivateUrgentStones(int a2) {
  
  CEcoSector *v2; // eax
  _DWORD *v3; // eax
  CEcoSector *v4; // eax
  CEcoSector *v5; // eax

  if ( CBuildingSiteRole::NeedStone(this) )
  {
    v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    if ( (int)CEcoSector::BuildingSitesWithPrio(v2) < 10 )
    {
      v3 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
      if ( IEntity::FlagBits(v3, (EntityFlag)0x1000u) )
      {
        if ( !*((_BYTE *)this + 443) && !*((_BYTE *)this + 444) && !*((_BYTE *)this + 442) && !*((_BYTE *)this + 441) )
        {
          v4 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
          CEcoSector::ChangeBuildingSitesWithPrio(v4, 1);
        }
        if ( !*((_BYTE *)this + 444) )
        {
          *((_BYTE *)this + 444) = 1;
          v5 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
          CEcoSector::ChangePrioStone(v5, 1);
        }
      }
    }
  }
}


// address=[0x1503b60]
// Decompiled from void __thiscall CBuildingSiteRole::CheckActivateUrgentBuilder(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckActivateUrgentBuilder(int a2) {
  
  CEcoSector *v2; // eax
  _DWORD *v3; // eax
  CEcoSector *v4; // eax
  CEcoSector *v5; // eax
  int v6; // [esp-4h] [ebp-8h]

  v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
  if ( (int)CEcoSector::BuildingSitesWithPrio(v2) < 10 )
  {
    v3 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
    if ( IEntity::FlagBits(v3, (EntityFlag)0x1000u) )
    {
      if ( !*((_BYTE *)this + 443) && !*((_BYTE *)this + 444) && !*((_BYTE *)this + 442) && !*((_BYTE *)this + 441) )
      {
        v4 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
        CEcoSector::ChangeBuildingSitesWithPrio(v4, 1);
      }
      if ( !*((_BYTE *)this + 442) )
      {
        *((_BYTE *)this + 442) = 1;
        v6 = *(char *)(*((_DWORD *)this + 94) + 7);
        v5 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
        CEcoSector::ChangePrioBuilder(v5, 1, v6);
      }
    }
  }
}


// address=[0x1503c40]
// Decompiled from void __thiscall CBuildingSiteRole::CheckActivateUrgentDigger(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckActivateUrgentDigger(int a2) {
  
  CEcoSector *v2; // eax
  _DWORD *v3; // eax
  CEcoSector *v4; // eax
  CEcoSector *v5; // eax
  int v6; // [esp-4h] [ebp-8h]

  if ( *((int *)this + 98) > 0 && *((_DWORD *)this + 97) - *((unsigned __int8 *)this + 397) > 0 )
  {
    v2 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
    if ( (int)CEcoSector::BuildingSitesWithPrio(v2) < 10 )
    {
      v3 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
      if ( IEntity::FlagBits(v3, (EntityFlag)0x1000u) )
      {
        if ( !*((_BYTE *)this + 443) && !*((_BYTE *)this + 444) && !*((_BYTE *)this + 442) && !*((_BYTE *)this + 441) )
        {
          v4 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
          CEcoSector::ChangeBuildingSitesWithPrio(v4, 1);
        }
        if ( !*((_BYTE *)this + 441) )
        {
          *((_BYTE *)this + 441) = 1;
          v6 = *((_DWORD *)this + 97);
          v5 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
          CEcoSector::ChangePrioDigger(v5, 1, v6);
        }
      }
    }
  }
}


// address=[0x1503d50]
// Decompiled from int __fastcall CBuildingSiteRole::OrderDigger(CBuildingSiteRole *this, int a2, struct CBuilding *a3)
void  CBuildingSiteRole::OrderDigger(class CBuilding * a2) {
  
  int result; // eax
  int v4; // esi
  int v5; // eax
  CEcoSector *v6; // [esp+10h] [ebp-8h]

  result = (int)this;
  if ( *((int *)this + 98) <= 0 )
    return result;
  result = CBuildingSiteRole::GetEcoSectorId(this, a3);
  if ( result <= 0 )
    return result;
  v6 = (CEcoSector *)CEcoSectorMgr::operator[](result);
  if ( !*((_BYTE *)this + 441) )
  {
    v4 = CEcoSector::NeededPrioDigger(v6);
    result = CEcoSector::NrOfSettler(v6, 2);
    if ( v4 >= result )
      return result;
  }
  if ( *((_BYTE *)this + 397) )
  {
    result = *((_DWORD *)this + 98) / (int)*((unsigned __int8 *)this + 397);
    if ( result < 10 )
      return result;
  }
  result = *((_DWORD *)this + 97) - *((unsigned __int8 *)this + 397);
  if ( result <= 0 )
    return result;
  v5 = IEntity::ID();
  result = CEcoSector::CallWorker(v6, v5, 2);
  if ( !result )
    return result;
  result = (int)this;
  ++*((_BYTE *)this + 397);
  return result;
}


// address=[0x1503e40]
// Decompiled from void __thiscall CBuildingSiteRole::DiggingIsReady(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::DiggingIsReady(int a2) {
  
  int EcoSectorId; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 396) = 4;
  if ( *((_DWORD *)this + 96) != -1 )
  {
    byte_409F9AD[30750 * a2 + 1025 * *((_DWORD *)this + 96)] = 0;
    *((_DWORD *)this + 96) = -1;
  }
  EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this);
  if ( EcoSectorId > 0 )
    CBuildingSiteRole::CheckDeactivateUrgentDigger(this, EcoSectorId);
}


// address=[0x1503eb0]
// Decompiled from void __thiscall CBuildingSiteRole::TidyUp(CBuildingSiteRole *this, struct CEntityEvent *a2)
void  CBuildingSiteRole::TidyUp(class CEntityEvent &) {
  
  int EcoSectorId; // [esp+4h] [ebp-4h]

  EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this);
  if ( EcoSectorId > 0 )
  {
    CBuildingSiteRole::CheckDeactivateUrgentBoards(this, EcoSectorId);
    CBuildingSiteRole::CheckDeactivateUrgentStones(this, EcoSectorId);
    CBuildingSiteRole::CheckDeactivateUrgentDigger(this, EcoSectorId);
    CBuildingSiteRole::CheckDeactivateUrgentBuilder(this, EcoSectorId);
  }
}


// address=[0x1503f10]
// Decompiled from int __thiscall CBuildingSiteRole::NotifyDeliverPiles(unsigned __int16 *this, int a2)
void  CBuildingSiteRole::NotifyDeliverPiles(class CEntityEvent & a2) {
  
  int result; // eax
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // [esp+4h] [ebp-Ch]
  unsigned __int8 *v5; // [esp+8h] [ebp-8h]

  if ( this[216] )
  {
    v5 = CPileMgr::operator[](this[216]);
    (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v5 + 80))(v5, a2);
  }
  if ( this[217] )
  {
    v4 = CPileMgr::operator[](this[217]);
    (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v4 + 80))(v4, a2);
  }
  result = (int)this;
  if ( !this[218] )
    return result;
  v3 = CPileMgr::operator[](this[218]);
  return (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v3 + 80))(v3, a2);
}


// address=[0x1503fd0]
// Decompiled from int __thiscall CBuildingSiteRole::OrderBuilder(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::OrderBuilder(class CBuilding * a2) {
  
  int result; // eax
  int v3; // esi
  int v4; // eax
  CEcoSector *v5; // [esp+14h] [ebp-8h]

  result = CBuildingSiteRole::HaveBuildingMaterial(this);
  if ( !result )
    return result;
  result = CBuildingSiteRole::GetEcoSectorId(this, a2);
  if ( result <= 0 )
    return result;
  v5 = (CEcoSector *)CEcoSectorMgr::operator[](result);
  if ( !*((_BYTE *)this + 442) )
  {
    v3 = CEcoSector::NeededPrioBuilder(v5);
    result = CEcoSector::NrOfSettler(v5, 3);
    if ( v3 >= result )
      return result;
  }
  if ( *((unsigned __int8 *)this + 396) < 4u )
  {
    result = (int)this;
    if ( *((int *)this + 98) >= 40 || !*((_BYTE *)this + 397) )
      return result;
  }
  result = *((unsigned __int8 *)this + 401);
  if ( *((unsigned __int8 *)this + 400) - result <= 0 )
    return result;
  v4 = IEntity::ID();
  result = CEcoSector::CallWorker(v5, v4, 3);
  if ( !result )
    return result;
  result = (int)this;
  ++*((_BYTE *)this + 401);
  return result;
}


// address=[0x15040d0]
// Decompiled from CBuildingSiteRole *__thiscall CBuildingSiteRole::OrderMaterial(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::OrderMaterial(class CBuilding * a2) {
  
  CBuildingSiteRole *result; // eax
  int v3; // esi
  CEcoSector *v4; // eax
  int v5; // esi
  CEcoSector *v6; // eax
  int v7; // esi
  __int16 v8; // [esp-8h] [ebp-2Ch]
  __int16 v9; // [esp-8h] [ebp-2Ch]
  __int16 v10; // [esp-8h] [ebp-2Ch]
  int v11; // [esp+4h] [ebp-20h]
  int v12; // [esp+8h] [ebp-1Ch]
  int v13; // [esp+Ch] [ebp-18h]
  unsigned __int8 *v14; // [esp+10h] [ebp-14h]
  unsigned __int8 *v15; // [esp+14h] [ebp-10h]
  unsigned __int8 *v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]

  result = (CBuildingSiteRole *)CBuildingSiteRole::GetEcoSectorId(this, a2);
  v17 = (int)result;
  if ( (int)result <= 0 )
    return result;
  if ( *((_BYTE *)this + 440) )
  {
    if ( CBuildingSiteRole::NeedBoards(this) )
      CBuildingSiteRole::CheckActivateUrgentBoards(this, v17);
    else
      CBuildingSiteRole::CheckDeactivateUrgentBoards(this, v17);
    if ( CBuildingSiteRole::NeedStone(this) )
      CBuildingSiteRole::CheckActivateUrgentStones(this, v17);
    else
      CBuildingSiteRole::CheckDeactivateUrgentStones(this, v17);
  }
  if ( !*((_BYTE *)this + 397) )
  {
    result = this;
    if ( *((unsigned __int8 *)this + 396) < 3u )
      return result;
  }
  if ( *((_WORD *)this + 216) )
  {
    v16 = CPileMgr::operator[](*((unsigned __int16 *)this + 216));
    v3 = CPile::AmountComing((CPile *)v16);
    v13 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v16 + 40))(v16) + v3;
    if ( v13 < *((unsigned __int8 *)this + 403) - *((unsigned __int8 *)this + 404) && v13 < 8 )
    {
      v4 = (CEcoSector *)CEcoSectorMgr::operator[](v17);
      if ( !CEcoSector::PrioBoards(v4) || *((_BYTE *)this + 443) )
      {
        v8 = IEntity::ID();
        CEcoSectorMgr::operator[](v17);
        CEcoSector::RequestGood(v8, 7);
      }
    }
  }
  if ( *((_WORD *)this + 217) )
  {
    v15 = CPileMgr::operator[](*((unsigned __int16 *)this + 217));
    v5 = CPile::AmountComing((CPile *)v15);
    v12 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v15 + 40))(v15) + v5;
    if ( v12 < *((unsigned __int8 *)this + 405) - *((unsigned __int8 *)this + 406) && v12 < 8 )
    {
      v6 = (CEcoSector *)CEcoSectorMgr::operator[](v17);
      if ( !CEcoSector::PrioStone(v6) || *((_BYTE *)this + 444) )
      {
        v9 = IEntity::ID();
        CEcoSectorMgr::operator[](v17);
        CEcoSector::RequestGood(v9, 32);
      }
    }
  }
  result = this;
  if ( !*((_WORD *)this + 218) )
    return result;
  v14 = CPileMgr::operator[](*((unsigned __int16 *)this + 218));
  v7 = CPile::AmountComing((CPile *)v14);
  v11 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v14 + 40))(v14) + v7;
  result = this;
  if ( v11 >= *((unsigned __int8 *)this + 407) - *((unsigned __int8 *)this + 408) || v11 >= 8 )
    return result;
  v10 = IEntity::ID();
  CEcoSectorMgr::operator[](v17);
  return (CBuildingSiteRole *)CEcoSector::RequestGood(v10, 14);
}


// address=[0x1504360]
// Decompiled from int __thiscall CBuildingSiteRole::BuildingDone(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::BuildingDone(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  _BYTE v4[24]; // [esp+4h] [ebp-34h] BYREF
  const struct CEntityEvent *v5; // [esp+1Ch] [ebp-1Ch]
  const struct CEntityEvent *v6; // [esp+20h] [ebp-18h]
  int v7; // [esp+24h] [ebp-14h]
  CBuildingSiteRole *v8; // [esp+28h] [ebp-10h]
  int v9; // [esp+34h] [ebp-4h]

  v8 = this;
  v2 = IEntity::ID();
  CTrace::Print("Building nr: %u ready", v2);
  result = CBuildingSiteRole::GetEcoSectorId(v8, a2);
  v7 = result;
  if ( result <= 0 )
    return result;
  CBuildingSiteRole::CheckDeactivateUrgentBoards(v8, v7);
  CBuildingSiteRole::CheckDeactivateUrgentStones(v8, v7);
  CBuildingSiteRole::CheckDeactivateUrgentDigger(v8, v7);
  CBuildingSiteRole::CheckDeactivateUrgentBuilder(v8, v7);
  if ( *((_WORD *)v8 + 216) )
  {
    (*(void (__thiscall **)(struct CBuilding *, _DWORD))(*(_DWORD *)a2 + 64))(a2, *((unsigned __int16 *)v8 + 216));
    CPileMgr::DeletePile((CPileMgr *)&g_cPileMgr, *((unsigned __int16 *)v8 + 216));
  }
  if ( *((_WORD *)v8 + 217) )
  {
    (*(void (__thiscall **)(struct CBuilding *, _DWORD))(*(_DWORD *)a2 + 64))(a2, *((unsigned __int16 *)v8 + 217));
    CPileMgr::DeletePile((CPileMgr *)&g_cPileMgr, *((unsigned __int16 *)v8 + 217));
  }
  if ( *((_WORD *)v8 + 218) )
  {
    (*(void (__thiscall **)(struct CBuilding *, _DWORD))(*(_DWORD *)a2 + 64))(a2, *((unsigned __int16 *)v8 + 218));
    CPileMgr::DeletePile((CPileMgr *)&g_cPileMgr, *((unsigned __int16 *)v8 + 218));
  }
  v6 = CEntityEvent::CEntityEvent((CEntityEvent *)v4, 9u, 0, 0, 0, 0);
  v5 = v6;
  v9 = 0;
  CBuilding::NotifyAndDetachAllObservers(a2, v6);
  v9 = -1;
  CEntityEvent::~CEntityEvent(v4);
  IEntity::ClearFlagBits(a2, (EntityFlag)&dword_F29144[220079]);
  IEntity::SetFlagBits(a2, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  return CBuilding::Ready((unsigned __int8 *)a2);
}


// address=[0x1504510]
// Decompiled from int __thiscall CBuildingSiteRole::DeleteStakes(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::DeleteStakes(class CBuilding * a2) {
  
  _DWORD *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  _BYTE v9[12]; // [esp+4h] [ebp-58h] BYREF
  _BYTE v10[12]; // [esp+10h] [ebp-4Ch] BYREF
  _BYTE v11[12]; // [esp+1Ch] [ebp-40h] BYREF
  std::_Iterator_base12 *v12; // [esp+28h] [ebp-34h]
  std::_Iterator_base12 *v13; // [esp+2Ch] [ebp-30h]
  int v14; // [esp+30h] [ebp-2Ch]
  int v15; // [esp+34h] [ebp-28h]
  int v16; // [esp+38h] [ebp-24h]
  int v17; // [esp+3Ch] [ebp-20h]
  int v18; // [esp+40h] [ebp-1Ch]
  CBuildingSiteRole *v19; // [esp+44h] [ebp-18h]
  int i; // [esp+48h] [ebp-14h]
  char v21; // [esp+4Fh] [ebp-Dh]
  int v22; // [esp+58h] [ebp-4h]

  v19 = this;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v11);
  v22 = 0;
  v18 = 0;
  v15 = std::vector<unsigned int>::begin(v10);
  v14 = v15;
  LOBYTE(v22) = 1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v15);
  LOBYTE(v22) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v10);
  while ( 1 )
  {
    v13 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v9);
    v12 = v13;
    LOBYTE(v22) = 2;
    v21 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v13);
    LOBYTE(v22) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v9);
    if ( !v21 )
      break;
    ++v18;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v11) )
    {
      for ( i = 31; i >= 0; --i )
      {
        v2 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v11);
        if ( (*v2 & (1 << i)) != 0 )
        {
          v3 = IEntity::WorldIdx();
          v4 = CWorldManager::X(v3);
          v16 = v4 + 32 - i - **((char **)v19 + 94) - 1;
          v5 = IEntity::WorldIdx();
          v6 = CWorldManager::Y(v5);
          v17 = v18 + v6 - *(char *)(*((_DWORD *)v19 + 94) + 1) - 1;
          if ( !CWorldManager::PileId(v16, v17) )
          {
            v7 = CWorldManager::Index(v16, v17);
            CWorldManager::SetObjectId(v7, 0);
          }
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v11);
  }
  v22 = -1;
  return std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v11);
}


// address=[0x15046e0]
// Decompiled from CBuildingSiteRole *__thiscall CBuildingSiteRole::BuilderLeft(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::BuilderLeft(int a2) {
  
  unsigned __int16 *v2; // eax
  CBuildingSiteRole *result; // eax
  unsigned __int16 *v4; // eax
  int v5; // eax

  v2 = (unsigned __int16 *)CSettlerMgr::operator[](a2);
  result = (CBuildingSiteRole *)IEntity::Type(v2);
  if ( result == (CBuildingSiteRole *)2 )
  {
    if ( !*((_BYTE *)this + 397)
      && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 1183, "m_uDiggerAct") == 1 )
    {
      __debugbreak();
    }
    result = this;
    --*((_BYTE *)this + 397);
  }
  else if ( result == (CBuildingSiteRole *)3 )
  {
    if ( *((_BYTE *)this + 401) )
    {
      result = this;
      --*((_BYTE *)this + 401);
    }
  }
  else
  {
    v4 = (unsigned __int16 *)CSettlerMgr::operator[](a2);
    v5 = IEntity::Type(v4);
    if ( BBSupportDbgReportF(
           2,
           "MapObjects\\Building\\BuildingSite.cpp",
           1201,
           "Wrong Builder left. ID %d, Type %d",
           a2,
           v5) == 1 )
      __debugbreak();
    return 0;
  }
  return result;
}


// address=[0x15047d0]
// Decompiled from int __thiscall CBuildingSiteRole::ReturnBuildingMaterial(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::ReturnBuildingMaterial(class CBuilding * a2) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  signed int v6; // [esp+Ch] [ebp-Ch]
  signed int v7; // [esp+10h] [ebp-8h]
  signed int v8; // [esp+14h] [ebp-4h]

  v3 = IEntity::X(a2);
  v4 = IEntity::Y(a2);
  if ( *((_WORD *)this + 216) )
  {
    v8 = *((unsigned __int8 *)this + 404) / 2;
    while ( v8 )
    {
      if ( v8 <= 8 )
      {
        CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v3, v4, 7u, v8);
        v8 = 0;
      }
      else
      {
        CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v3, v4, 7u, 8u);
        v8 -= 8;
      }
    }
  }
  if ( *((_WORD *)this + 217) )
  {
    v7 = *((unsigned __int8 *)this + 406) / 2;
    while ( v7 )
    {
      if ( v7 <= 8 )
      {
        CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v3, v4, 0x20u, v7);
        v7 = 0;
      }
      else
      {
        CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v3, v4, 0x20u, 8u);
        v7 -= 8;
      }
    }
  }
  result = *((unsigned __int16 *)this + 218);
  if ( !*((_WORD *)this + 218) )
    return result;
  result = *((unsigned __int8 *)this + 408) / 2;
  v6 = result;
  while ( v6 )
  {
    if ( v6 <= 8 )
    {
      result = CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v3, v4, 0xEu, v6);
      v6 = 0;
    }
    else
    {
      result = CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v3, v4, 0xEu, 8u);
      v6 -= 8;
    }
  }
  return result;
}


// address=[0x1504960]
// Decompiled from _DWORD *__thiscall CBuildingSiteRole::PrepareGround(_DWORD *this, unsigned __int16 *a2)
void  CBuildingSiteRole::PrepareGround(class CBuilding * a2) {
  
  _DWORD *v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  __int16 v14; // ax
  unsigned __int8 *v15; // eax
  __int16 v16; // ax
  unsigned __int8 *v17; // eax
  __int16 v18; // ax
  unsigned __int8 *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  _DWORD *result; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // [esp-10h] [ebp-140h]
  int v30; // [esp-10h] [ebp-140h]
  int v31; // [esp-10h] [ebp-140h]
  int v32; // [esp-Ch] [ebp-13Ch]
  int v33; // [esp-Ch] [ebp-13Ch]
  int v34; // [esp-Ch] [ebp-13Ch]
  int v35; // [esp-8h] [ebp-138h]
  int v36; // [esp-8h] [ebp-138h]
  int v37; // [esp-8h] [ebp-138h]
  __int16 v38; // [esp-4h] [ebp-134h]
  int v39; // [esp-4h] [ebp-134h]
  int v40; // [esp-4h] [ebp-134h]
  int v41; // [esp-4h] [ebp-134h]
  int v42; // [esp-4h] [ebp-134h]
  int v43; // [esp-4h] [ebp-134h]
  int v44; // [esp-4h] [ebp-134h]
  int v45; // [esp-4h] [ebp-134h]
  int v46; // [esp-4h] [ebp-134h]
  int v47; // [esp-4h] [ebp-134h]
  __int16 v48; // [esp-4h] [ebp-134h]
  _DWORD v49[7]; // [esp+8h] [ebp-128h] BYREF
  _DWORD v50[7]; // [esp+24h] [ebp-10Ch] BYREF
  _DWORD v51[7]; // [esp+40h] [ebp-F0h] BYREF
  _BYTE v52[12]; // [esp+5Ch] [ebp-D4h] BYREF
  _BYTE v53[12]; // [esp+68h] [ebp-C8h] BYREF
  int v54; // [esp+74h] [ebp-BCh]
  int v55; // [esp+78h] [ebp-B8h]
  int v56; // [esp+7Ch] [ebp-B4h]
  int v57; // [esp+80h] [ebp-B0h]
  std::_Iterator_base12 *v58; // [esp+84h] [ebp-ACh]
  std::_Iterator_base12 *v59; // [esp+88h] [ebp-A8h]
  int v60; // [esp+8Ch] [ebp-A4h]
  int v61; // [esp+90h] [ebp-A0h]
  _BYTE v62[12]; // [esp+94h] [ebp-9Ch] BYREF
  int v63; // [esp+A0h] [ebp-90h]
  int v64; // [esp+A4h] [ebp-8Ch]
  int v65; // [esp+A8h] [ebp-88h]
  int v66; // [esp+ACh] [ebp-84h]
  int v67; // [esp+B0h] [ebp-80h]
  int v68; // [esp+B4h] [ebp-7Ch]
  int j; // [esp+B8h] [ebp-78h]
  int k; // [esp+BCh] [ebp-74h]
  char v71; // [esp+C2h] [ebp-6Eh]
  bool v72; // [esp+C3h] [ebp-6Dh]
  int v73; // [esp+C4h] [ebp-6Ch]
  int v74; // [esp+C8h] [ebp-68h]
  int i; // [esp+CCh] [ebp-64h]
  bool v76; // [esp+D3h] [ebp-5Dh]
  _DWORD *v77; // [esp+D4h] [ebp-5Ch]
  _DWORD v78[18]; // [esp+D8h] [ebp-58h] BYREF
  int v79; // [esp+12Ch] [ebp-4h]

  v77 = this;
  v76 = IEntity::Type(a2) == 49 || IEntity::Type(a2) == 80;
  v72 = v76;
  if ( v76 )
  {
    v46 = v77[94] + 720;
    v37 = *(char *)(v77[94] + 1);
    v34 = *(char *)v77[94];
    v31 = IEntity::Y(a2);
    v26 = IEntity::X(a2);
    CBuildingFlagsWalk::CBuildingFlagsWalk(v26, v31, v34, v37, v46);
    while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v49) )
    {
      v47 = CBuildingFlagsWalk::CurrentY(v49);
      v27 = CBuildingFlagsWalk::CurrentX(v49);
      v63 = CWorldManager::Index(v27, v47);
      CWorldManager::SetObjectId(v63, 0);
      CWorldManager::SetFlagBits(v63, 8u);
    }
    v48 = IEntity::ID();
    v28 = IEntity::WorldIdx();
    CWorldManager::SetObjectId(v28, v48);
    result = v77;
    *((_BYTE *)v77 + 396) = 6;
  }
  else
  {
    v55 = 1;
    for ( i = 0; i < 6; ++i )
      v78[3 * i] = 0;
    v56 = IEntity::X(a2) + 32 - *(char *)v77[94] - 1;
    v57 = IEntity::Y(a2) - *(char *)(v77[94] + 1) - 1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v62);
    v79 = 0;
    v67 = 0;
    v61 = std::vector<unsigned int>::begin(v53);
    v60 = v61;
    LOBYTE(v79) = 1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v61);
    LOBYTE(v79) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v53);
    while ( 1 )
    {
      v59 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v52);
      v58 = v59;
      LOBYTE(v79) = 2;
      v71 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v59);
      LOBYTE(v79) = 0;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v52);
      if ( !v71 )
        break;
      ++v67;
      if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v62) )
      {
        v73 = v67 + v57;
        for ( j = 31; j >= 0; --j )
        {
          v2 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v62);
          if ( (*v2 & (1 << j)) != 0 )
          {
            v74 = v56 - j;
            if ( IGfxEngine::CanChangeGround((IGfxEngine *)g_pGfxEngine, v56 - j, v73, 28) )
            {
              CWorldManager::SetGround(v74, v73, 28);
              IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, v74, v73);
            }
            CWorldManager::SetObjectId(v74, v73, 0);
            CWorldManager::SetFlagBits(v74, v73, 8);
            if ( v55 && (v74 || v73) )
            {
              for ( k = 0; ; ++k )
              {
                v3 = IEntity::X(a2);
                v4 = CSpiralOffsets::DeltaX(k);
                if ( v4 + v3 == v74 )
                {
                  v5 = IEntity::Y(a2);
                  v6 = CSpiralOffsets::DeltaY(k);
                  if ( v6 + v5 == v73 )
                    break;
                }
              }
              v68 = CSpiralOffsets::Direction(k);
              v7 = CSpiralOffsets::Radius(k);
              if ( v7 >= v78[3 * v68] )
              {
                v8 = CSpiralOffsets::Radius(k);
                v78[3 * v68] = v8;
                v78[3 * v68 + 1] = v74;
                v78[3 * v68 + 2] = v73;
              }
            }
          }
        }
      }
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v62);
    }
    for ( i = 0; i < 6; ++i )
    {
      if ( (int)v78[3 * i] >= 1 )
        CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, v78[3 * i + 1], v78[3 * i + 2], 123, 0, 1);
    }
    v38 = IEntity::ID();
    v9 = IEntity::WorldIdx();
    CWorldManager::SetObjectId(v9, v38);
    v10 = IEntity::WorldIdx();
    v11 = CWorldManager::X(v10);
    v65 = *(char *)(v77[94] + 38) + v11;
    v12 = IEntity::WorldIdx();
    v13 = CWorldManager::Y(v12);
    v66 = *(char *)(v77[94] + 39) + v13;
    if ( *((_BYTE *)v77 + 403) )
    {
      v14 = CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v65 + 1, v66, 7, 0, 5, 0, 0, 0, 0);
      *((_WORD *)v77 + 216) = v14;
      v39 = IEntity::ID();
      v15 = CPileMgr::operator[](*((unsigned __int16 *)v77 + 216));
      CPile::SetBuildingId((CPile *)v15, v39);
    }
    if ( *((_BYTE *)v77 + 405) )
    {
      v16 = CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v65 - 1, v66, 32, 0, 5, 0, 0, 0, 0);
      *((_WORD *)v77 + 217) = v16;
      v40 = IEntity::ID();
      v17 = CPileMgr::operator[](*((unsigned __int16 *)v77 + 217));
      CPile::SetBuildingId((CPile *)v17, v40);
    }
    if ( *((_BYTE *)v77 + 407) )
    {
      v18 = CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v65, v66, 14, 0, 5, 0, 0, 0, 0);
      *((_WORD *)v77 + 218) = v18;
      v41 = IEntity::ID();
      v19 = CPileMgr::operator[](*((unsigned __int16 *)v77 + 218));
      CPile::SetBuildingId((CPile *)v19, v41);
    }
    v20 = IEntity::Type(a2);
    if ( (unsigned __int8)CBuildingMgr::IsMine(v20) )
      *((_BYTE *)v77 + 396) = 4;
    else
      *((_BYTE *)v77 + 396) = 2;
    if ( *(_BYTE *)(v77[94] + 6) )
    {
      v42 = v77[94] + 816;
      v35 = *(char *)(v77[94] + 1);
      v32 = *(char *)v77[94];
      v29 = IEntity::Y(a2);
      v21 = IEntity::X(a2);
      CBuildingFlagsWalk::CBuildingFlagsWalk(v21, v29, v32, v35, v42);
      while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v51) )
      {
        v43 = CBuildingFlagsWalk::CurrentY(v51);
        v22 = CBuildingFlagsWalk::CurrentX(v51);
        v64 = CWorldManager::Index(v22, v43);
        CWorldManager::SetObjectId(v64, 0);
        CWorldManager::SetFlagBits(v64, 8u);
      }
      v44 = v77[94] + 832;
      v36 = *(char *)(v77[94] + 1);
      v33 = *(char *)v77[94];
      v30 = IEntity::Y(a2);
      v23 = IEntity::X(a2);
      CBuildingFlagsWalk::CBuildingFlagsWalk(v23, v30, v33, v36, v44);
      while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v50) )
      {
        v45 = CBuildingFlagsWalk::CurrentY(v50);
        v24 = CBuildingFlagsWalk::CurrentX(v50);
        v54 = CWorldManager::Index(v24, v45);
        CWorldManager::SetFlagBits(v54, 8u);
      }
    }
    v79 = -1;
    return (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v62);
  }
  return result;
}


// address=[0x15063d0]
// Decompiled from void __thiscall CBuildingSiteRole::ConvertEventIntoGoal(  CBuildingSiteRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CBuildingSiteRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x1506430]
// Decompiled from int __thiscall CBuildingSiteRole::GetEcoSectorId(CBuildingSiteRole *this, struct CBuilding *a2)
int  CBuildingSiteRole::GetEcoSectorId(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax

  if ( !a2 )
    return 0;
  v2 = CBuilding::EnsignPackedXY(a2);
  v3 = CWorldManager::Index(v2);
  return ITiling::EcoSectorId(v3);
}


// address=[0x1506490]
// Decompiled from int __thiscall CBuildingSiteRole::NeedBoards(CBuildingSiteRole *this)
int  CBuildingSiteRole::NeedBoards(void)const {
  
  unsigned __int8 *v1; // eax
  int v2; // esi

  if ( !*((_BYTE *)this + 403) )
    return 0;
  v1 = CPileMgr::operator[](*((unsigned __int16 *)this + 216));
  v2 = *((unsigned __int8 *)this + 404);
  return *((unsigned __int8 *)this + 403) - (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v1 + 40))(v1) - v2;
}


// address=[0x1506510]
// Decompiled from int __thiscall CBuildingSiteRole::NeedGold(CBuildingSiteRole *this)
int  CBuildingSiteRole::NeedGold(void)const {
  
  unsigned __int8 *v1; // eax
  int v2; // esi

  if ( !*((_BYTE *)this + 407) )
    return 0;
  v1 = CPileMgr::operator[](*((unsigned __int16 *)this + 218));
  v2 = *((unsigned __int8 *)this + 408);
  return *((unsigned __int8 *)this + 407) - (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v1 + 40))(v1) - v2;
}


// address=[0x1506590]
// Decompiled from int __thiscall CBuildingSiteRole::NeedStone(CBuildingSiteRole *this)
int  CBuildingSiteRole::NeedStone(void)const {
  
  unsigned __int8 *v1; // eax
  int v2; // esi

  if ( !*((_BYTE *)this + 405) )
    return 0;
  v1 = CPileMgr::operator[](*((unsigned __int16 *)this + 217));
  v2 = *((unsigned __int8 *)this + 406);
  return *((unsigned __int8 *)this + 405) - (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v1 + 40))(v1) - v2;
}


// address=[0x15067d0]
// Decompiled from char __thiscall CBuildingSiteRole::TryCrushBuilding(CBuildingSiteRole *this)
bool  CBuildingSiteRole::TryCrushBuilding(void) {
  
  return 1;
}


