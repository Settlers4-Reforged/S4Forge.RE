#include "CBuildingSiteRole.h"

// Definitions for class CBuildingSiteRole

// address=[0x13ffe60]
// Decompiled from CBuildingSiteRole *__cdecl CBuildingSiteRole::New(int a1)
class CPersistence * __cdecl CBuildingSiteRole::New(std::istream & a1) {
  
  CBuildingSiteRole *C; // [esp+Ch] [ebp-10h]

  C = (CBuildingSiteRole *)operator new(0x1C8u);
  if ( C )
  {
    return CBuildingSiteRole::CBuildingSiteRole(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x1447610]
// Decompiled from bool __thiscall CBuildingSiteRole::HaveBoardPriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HaveBoardPriority(void)const {
  
  return this->m_bBoardPriority;
}


// address=[0x1447630]
// Decompiled from bool __thiscall CBuildingSiteRole::HaveBuilderPriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HaveBuilderPriority(void)const {
  
  return this->m_bBuilderPriority;
}


// address=[0x1447650]
// Decompiled from bool __thiscall CBuildingSiteRole::HaveDiggerPriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HaveDiggerPriority(void)const {
  
  return this->m_bDiggerPriority;
}


// address=[0x1447670]
// Decompiled from bool __thiscall CBuildingSiteRole::HavePriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HavePriority(void)const {
  
  return this->m_bPriority;
}


// address=[0x1447690]
// Decompiled from bool __thiscall CBuildingSiteRole::HaveStonePriority(CBuildingSiteRole *this)
bool  CBuildingSiteRole::HaveStonePriority(void)const {
  
  return this->m_bStonePriority;
}


// address=[0x14476b0]
// Decompiled from int __thiscall CBuildingSiteRole::MaxNeededBuilder(CBuildingSiteRole *this)
int  CBuildingSiteRole::MaxNeededBuilder(void)const {
  
  return this->m_pBuildingInfo->m_iBuilderNumber;
}


// address=[0x14476d0]
// Decompiled from int __thiscall CBuildingSiteRole::MaxNeededDigger(CBuildingSiteRole *this)
int  CBuildingSiteRole::MaxNeededDigger(void)const {
  
  return this->m_iMaxNeededDigger;
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
// Decompiled from void __thiscall CBuildingSiteRole::Init(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  unsigned int v3; // eax
  int v4; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  this->m_fBarDiv = 0.0;
  v6 = CBuilding::BuildingTypeEx(a2);
  v2 = IEntity::Race(a2);
  this->m_pBuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v2, v6);
  this->m_uBuilderNumber = this->m_pBuildingInfo->m_iBuilderNumber;
  this->m_uBoards = this->m_pBuildingInfo->m_iBoards;
  this->m_uProvidedBoards = 0;
  this->m_uStone = this->m_pBuildingInfo->m_iStone;
  this->m_uProvidedStone = 0;
  this->m_uGold = this->m_pBuildingInfo->m_iGold;
  this->m_uProvidedGold = 0;
  v3 = IEntity::Race(a2);
  this->m_iFrameCount = CGfxManager::GetSettlerJobFrameCount(g_pGfxManager, v3, 0x35u, 2u);
  this->m_iScaledTotalResources = 200 * (this->m_uGold + this->m_uStone + this->m_uBoards);
  this->m_iInverseScaledTotalResources = 131070 / this->m_iScaledTotalResources;
  IEntity::ClearFlagBits(a2, ENTITY_FLAG_Ready);
  IEntity::SetFlagBits(a2, (EntityFlag)0x1001000);
  this->m_uSettlerId = 0;
  this->m_iEntityId = IEntity::ID(a2);
  CBuildingSiteRole::PrepareGround(this, a2);
  IAnimatedEntity::RegisterForLogicUpdate(a2, 16);
  v5 = IEntity::ID(a2);
  v4 = IEntity::OwnerId(a2);
  g_pAI->PostAIEvent(g_pAI, 5, v4, v5, 0);
}


// address=[0x1501570]
// Decompiled from void __thiscall CBuildingSiteRole::LogicUpdate(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::LogicUpdate(class CBuilding * arg0) {
  
  int iDiggingNeeded; // edx MAPDST
  int v3; // eax
  _DWORD *v4; // eax
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
  int v38; // eax
  int v39; // [esp-10h] [ebp-104h]
  int v40; // [esp-10h] [ebp-104h]
  int v41; // [esp-10h] [ebp-104h]
  int v42; // [esp-10h] [ebp-104h]
  int m_iHotSpotX; // [esp-Ch] [ebp-100h]
  int v44; // [esp-Ch] [ebp-100h]
  int v45; // [esp-Ch] [ebp-100h]
  int m_iHotSpotY; // [esp-8h] [ebp-FCh]
  int v47; // [esp-8h] [ebp-FCh]
  int v48; // [esp-8h] [ebp-FCh]
  std::vector *p_m_vWaterRepealingPosLines; // [esp-4h] [ebp-F8h]
  int v50; // [esp-4h] [ebp-F8h]
  __int16 v51; // [esp-4h] [ebp-F8h]
  std::vector *p_m_vBlockPosLines; // [esp-4h] [ebp-F8h]
  int v53; // [esp-4h] [ebp-F8h]
  std::vector *v54; // [esp-4h] [ebp-F8h]
  int v55; // [esp-4h] [ebp-F8h]
  __int16 v56; // [esp-4h] [ebp-F8h]
  CBuildingFlagsWalk v57; // [esp+4h] [ebp-F0h] BYREF
  CBuildingFlagsWalk v58; // [esp+20h] [ebp-D4h] BYREF
  CBuildingFlagsWalk v59; // [esp+3Ch] [ebp-B8h] BYREF
  _BYTE v60[12]; // [esp+58h] [ebp-9Ch] BYREF
  _BYTE v61[12]; // [esp+64h] [ebp-90h] BYREF
  int v62; // [esp+70h] [ebp-84h]
  int v63; // [esp+74h] [ebp-80h]
  int v64; // [esp+78h] [ebp-7Ch]
  int v65; // [esp+7Ch] [ebp-78h]
  int v66; // [esp+80h] [ebp-74h]
  int v67; // [esp+84h] [ebp-70h]
  std::_Iterator_base12 *v68; // [esp+88h] [ebp-6Ch]
  std::_Iterator_base12 *v69; // [esp+8Ch] [ebp-68h]
  int v70; // [esp+90h] [ebp-64h]
  int v71; // [esp+94h] [ebp-60h]
  _DWORD v72[3]; // [esp+98h] [ebp-5Ch] BYREF
  struct IEffects *v73; // [esp+A4h] [ebp-50h]
  int v74; // [esp+A8h] [ebp-4Ch]
  int v75; // [esp+ACh] [ebp-48h]
  int v76; // [esp+B0h] [ebp-44h]
  int iDiggerCalled; // [esp+B4h] [ebp-40h]
  int iEcoSectorId; // [esp+BCh] [ebp-38h]
  int v80; // [esp+C0h] [ebp-34h]
  int v81; // [esp+C4h] [ebp-30h]
  int v82; // [esp+C8h] [ebp-2Ch]
  int v83; // [esp+CCh] [ebp-28h]
  int v84; // [esp+D0h] [ebp-24h]
  int v85; // [esp+D4h] [ebp-20h]
  int i; // [esp+D8h] [ebp-1Ch]
  unsigned int uDelay; // [esp+DCh] [ebp-18h]
  char v88; // [esp+E3h] [ebp-11h]
  int v90; // [esp+F0h] [ebp-4h]

  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) )
  {
    this->FillDialog(this, a2, 1);
  }
  IAnimatedEntity::RegisterForLogicUpdate(a2, 15);
  if ( IEntity::FlagBits(a2, (EntityFlag)4096) )
  {
    iEcoSectorId = CBuildingSiteRole::GetEcoSectorId(this, a2);
    if ( IEntity::Type(a2) == 49 || IEntity::Type(a2) == 80 )
    {
      goto LABEL_77;
    }
    if ( !iEcoSectorId && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 439, "iEcoSectorId != 0") == 1 )
    {
      __debugbreak();
    }
    if ( iEcoSectorId )
    {
LABEL_77:
      v83 = this->m_uBuildStage - 2;
      switch ( v83 )
      {
        case 0:
          iDiggingNeeded = this->m_iDiggingNeeded;
          if ( iDiggingNeeded <= 0 )
          {
            goto LABEL_12;
          }
          CBuildingSiteRole::OrderDigger(this, iDiggingNeeded, a2);
          iDiggerCalled = this->m_uDiggerAct;
          if ( !iDiggerCalled )
          {
            return;
          }
          if ( iDiggingNeeded / iDiggerCalled < 25 )
          {
            this->m_uBuildStage = 3;
          }
          return;
        case 1:
          if ( this->m_iDiggingNeeded <= 0 )
          {
LABEL_12:
            v3 = IEntity::OwnerId(a2);
            CBuildingSiteRole::DiggingIsReady(this, v3);
          }
          else
          {
            CBuildingSiteRole::OrderDigger(this, (int)a2, a2);
            CBuildingSiteRole::OrderMaterial(this, a2);
          }
          return;
        case 2:
          CBuildingSiteRole::OrderMaterial(this, a2);
          v84 = 0;
          std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v72);
          v90 = 0;
          v80 = 0;
          v71 = std::vector<unsigned int>::begin(&this->m_pBuildingInfo->m_vBlockPosLines, (int)v61);
          v70 = v71;
          LOBYTE(v90) = 1;
          std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v72, v71);
          LOBYTE(v90) = 0;
          std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v61);
          while ( 1 )
          {
            v69 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(&this->m_pBuildingInfo->m_vBlockPosLines, (int)v60);
            v68 = v69;
            LOBYTE(v90) = 2;
            v88 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v69);
            LOBYTE(v90) = 0;
            std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v60);
            if ( !v88 )
            {
              break;
            }
            ++v80;
            if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v72) )
            {
              for ( i = 31;
                    i >= 0;
                    --i )
              {
                v4 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v72);
                if ( (*v4 & (1 << i)) != 0 )
                {
                  v5 = IEntity::WorldIdx(a2);
                  v6 = CWorldManager::X(v5);
                  v81 = v6 + 32 - i - this->m_pBuildingInfo->m_iHotSpotX - 1;
                  v7 = IEntity::WorldIdx(a2);
                  v8 = CWorldManager::Y(v7);
                  v82 = v80 + v8 - this->m_pBuildingInfo->m_iHotSpotY - 1;
                  v9 = CWorldManager::Index(v81, v82);
                  CWorldManager::SetMoveCostsBits(v9, 7);
                  v10 = IEntity::WorldIdx(a2);
                  CWorldManager::SetFlagBits(v10, 2u);
                  if ( !CWorldManager::CheckBlockable(v81, v82) )
                  {
                    v84 = 1;
                  }
                }
              }
            }
            std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v72);
          }
          if ( this->m_pBuildingInfo->m_bIsPort )
          {
            p_m_vWaterRepealingPosLines = &this->m_pBuildingInfo->m_vWaterRepealingPosLines;
            m_iHotSpotY = this->m_pBuildingInfo->m_iHotSpotY;
            m_iHotSpotX = this->m_pBuildingInfo->m_iHotSpotX;
            v39 = IEntity::Y(a2);
            v11 = IEntity::X(a2);
            CBuildingFlagsWalk::CBuildingFlagsWalk(&v59, v11, v39, m_iHotSpotX, m_iHotSpotY, p_m_vWaterRepealingPosLines);
            while ( CBuildingFlagsWalk::NextPosition(&v59) )
            {
              v50 = CBuildingFlagsWalk::CurrentY(&v59);
              v12 = CBuildingFlagsWalk::CurrentX(&v59);
              v85 = CWorldManager::Index(v12, v50);
              v67 = CWorldManager::Flags(v85);
              if ( (v67 & 1) != 0 )
              {
                CWaterFlags::SetWaterFlagBitRepelling(v85);
                if ( CWorldManager::MapObjectId(v85) )
                {
                  v84 = 1;
                }
              }
              else
              {
                v13 = CWorldManager::Index(v81, v82);
                CWorldManager::SetMoveCostsBits(v13, 7);
                v14 = IEntity::WorldIdx(a2);
                CWorldManager::SetFlagBits(v14, 2u);
                if ( !CWorldManager::CheckBlockable(v81, v82) )
                {
                  v84 = 1;
                }
              }
              CWorldManager::SetObjectId(v85, 0);
              CWorldManager::SetFlagBits(v85, 8u);
            }
            v15 = IEntity::X(a2);
            v65 = (char)this->m_pBuildingInfo->m_iWorkPosXOffset + v15;
            v16 = IEntity::Y(a2);
            v66 = (char)this->m_pBuildingInfo->m_iWorkPosYOffset + v16;
            v64 = CWorldManager::Index(v65, v66);
            v17 = CBuilding::BuildingTypeEx(a2);
            if ( CBuildingMgr::IsShipyardEx(v17) )
            {
              CWaterFlags::SetWaterFlagBitRepelling(v64);
            }
          }
          v18 = IEntity::Type(a2);
          if ( CBuildingMgr::IsMilitary(v18) )
          {
            v19 = IEntity::WorldIdx(a2);
            v20 = CWorldManager::X(v19);
            v75 = (char)this->m_pBuildingInfo->m_iDoorXOffset + v20;
            v21 = IEntity::WorldIdx(a2);
            v22 = CWorldManager::Y(v21);
            v76 = (char)this->m_pBuildingInfo->m_iDoorYOffset + v22;
            v23 = CWorldManager::Index(v75, v76);
            CWorldManager::SetMoveCostsBits(v23, 7);
            v24 = IEntity::WorldIdx(a2);
            CWorldManager::SetFlagBits(v24, 2u);
            if ( !CWorldManager::CheckBlockable(v75, v76) )
            {
              v84 = 1;
            }
          }
          if ( !v84 )
          {
            v25 = IEntity::Type(a2);
            if ( CBuildingMgr::IsMilitary(v25) )
            {
              v26 = IEntity::WorldIdx(a2);
              v27 = CWorldManager::X(v26);
              v62 = (char)this->m_pBuildingInfo->m_iDoorXOffset + v27;
              v28 = IEntity::WorldIdx(a2);
              v29 = CWorldManager::Y(v28);
              v63 = (char)this->m_pBuildingInfo->m_iDoorYOffset + v29;
              CWorldManager::SetBlockedPosition(v62, v63);
            }
            this->m_uBuildStage = 5;
            v51 = IEntity::ID(a2);
            v30 = IEntity::WorldIdx(a2);
            CWorldManager::SetMapObjectId(v30, v51);
            CBuilding::SetToWorld(a2);
            v31 = IEntity::WorldIdx(a2);
            CWorldManager::SetObjectId(v31, 0);
          }
          v90 = -1;
          std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v72);
          return;
        case 3:
          CBuildingSiteRole::OrderBuilder(this, a2);
          CBuildingSiteRole::OrderMaterial(this, a2);
          if ( this->m_iProvidedScaledTotalResouces < this->m_iScaledTotalResources )
          {
            return;
          }
          CBuildingSiteRole::DeleteStakes(this, a2);
          CBuildingSiteRole::BuildingDone(this, a2);
          return;
        case 4:
          p_m_vBlockPosLines = &this->m_pBuildingInfo->m_vBlockPosLines;
          v47 = this->m_pBuildingInfo->m_iHotSpotY;
          v44 = this->m_pBuildingInfo->m_iHotSpotX;
          v40 = IEntity::Y(a2);
          v32 = IEntity::X(a2);
          CBuildingFlagsWalk::CBuildingFlagsWalk(&v58, v32, v40, v44, v47, p_m_vBlockPosLines);
          while ( CBuildingFlagsWalk::NextPosition(&v58) )
          {
            v53 = CBuildingFlagsWalk::CurrentY(&v58);
            v33 = CBuildingFlagsWalk::CurrentX(&v58);
            v74 = CWorldManager::Index(v33, v53);
            CWorldManager::SetMoveCostsBits(v74, 7);
            CWorldManager::SetFlagBits(v74, 2u);
          }
          this->m_uBuildStage = 7;
          goto LABEL_57;
        case 5:
LABEL_57:
          v54 = &this->m_pBuildingInfo->m_vBlockPosLines;
          v48 = this->m_pBuildingInfo->m_iHotSpotY;
          v45 = this->m_pBuildingInfo->m_iHotSpotX;
          v41 = IEntity::Y(a2);
          v34 = IEntity::X(a2);
          CBuildingFlagsWalk::CBuildingFlagsWalk(&v57, v34, v41, v45, v48, v54);
          break;
        case 6:
          v56 = IEntity::ID(a2);
          v37 = IEntity::WorldIdx(a2);
          CWorldManager::SetMapObjectId(v37, v56);
          v38 = IEntity::WorldIdx(a2);
          CWorldManager::SetObjectId(v38, 0);
          IEntity::ClearFlagBits(a2, ENTITY_FLAG_Birth);
          IEntity::SetFlagBits(a2, ENTITY_FLAG_Ready);
          CBuilding::Ready(a2);
          return;
        default:
          return;
      }
      while ( CBuildingFlagsWalk::NextPosition(&v57) )
      {
        v55 = CBuildingFlagsWalk::CurrentY(&v57);
        v35 = CBuildingFlagsWalk::CurrentX(&v57);
        if ( !CWorldManager::CheckBlockable(v35, v55) )
        {
          return;
        }
      }
      uDelay = 1;
      if ( IEntity::Type(a2) == BUILDING_MUSHROOMFARM )
      {
        v73 = CLogic::Effects(g_pLogic);
        v42 = IEntity::Y(a2);
        v36 = IEntity::X(a2);
        v73->AddEffect(v73, EFFECT_MUSHROOMFARM_BUILD, 0, v36, v42, 0, 0, 0);
      }
      if ( !uDelay && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 716, "uDelay > 0") == 1 )
      {
        __debugbreak();
      }
      if ( uDelay > 31 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 717, "uDelay <= CMapObjectMgr::MAX_DELTA_TICKS_FOR_LOGIC_UPDATE") == 1 )
      {
        __debugbreak();
      }
      if ( uDelay )
      {
        if ( uDelay > 31 )
        {
          uDelay = 31;
        }
      }
      else
      {
        uDelay = 1;
      }
      CBuilding::SetToWorld(a2);
      IAnimatedEntity::RegisterForLogicUpdate(a2, uDelay);
      this->m_uBuildStage = 8;
    }
  }
}


// address=[0x1501eb0]
// Decompiled from void __thiscall CBuildingSiteRole::PostLoadInit(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = CBuilding::BuildingTypeEx(a2);
  v2 = IEntity::Race(a2);
  this->m_pBuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v2, v3);
  this->m_uBuilderNumber = this->m_pBuildingInfo->m_iBuilderNumber;
  this->m_uBoards = this->m_pBuildingInfo->m_iBoards;
  this->m_uStone = this->m_pBuildingInfo->m_iStone;
  this->m_uGold = this->m_pBuildingInfo->m_iGold;
  if ( this->m_pBuildingInfo->m_bIsPort )
  {
    if ( this->m_uBuildStage == 5 )
    {
      IBuildingRole::PostLoadSetWaterFlags(this, a2);
    }
  }
}


// address=[0x1501f60]
// Decompiled from void __thiscall CBuildingSiteRole::FillGfxInfo(CBuildingSiteRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CBuildingSiteRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  unsigned int v3; // eax
  unsigned int v4; // [esp-Ch] [ebp-14h]
  int v5; // [esp+0h] [ebp-8h]

  if ( this->m_iU0 < this->m_iProvidedScaledTotalResouces - this->m_uBuilderAct )
  {
    if ( this->m_iU0 >= this->m_iProvidedScaledTotalResouces - 2 * this->m_uBuilderAct )
    {
      this->m_iU0 += this->m_uBuilderAct;
    }
    else
    {
      this->m_iU0 = this->m_iProvidedScaledTotalResouces;
    }
  }
  if ( this->m_iU0 >= this->m_iScaledTotalResources / 2 )
  {
    v5 = 3;
    a3->uConstructionProgress = 0xFFFF - this->m_iInverseScaledTotalResources - this->m_iInverseScaledTotalResources * (this->m_iU0 - this->m_iScaledTotalResources / 2);
    if ( a3->uConstructionProgress > 0xFFFFu )
    {
      a3->uConstructionProgress = 0;
    }
    if ( a3->uConstructionProgress > 0xFFFFu && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 392, "_sGfxInfo.uConstructionProgress <= BUILDING_PROGRESS_MAX") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    v5 = 2;
    a3->uConstructionProgress = 0xFFFF - this->m_iInverseScaledTotalResources * this->m_iU0;
    if ( a3->uConstructionProgress > 0xFFFFu )
    {
      a3->uConstructionProgress = 0;
    }
    if ( a3->uConstructionProgress > 0xFFFFu && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 378, "_sGfxInfo.uConstructionProgress <= BUILDING_PROGRESS_MAX") == 1 )
    {
      __debugbreak();
    }
  }
  v4 = CBuilding::BuildingTypeEx(a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo(g_pGfxManager, a3, v3, v4, v5, 0);
}


// address=[0x1502120]
// Decompiled from int __thiscall CBuildingSiteRole::GoodArrive(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::GoodArrive(int a2) {
  
  return a2;
}


// address=[0x1502140]
// Decompiled from char __thiscall CBuildingSiteRole::SettlerEnter(CBuildingSiteRole *this, struct CBuilding *a2, int a3)
bool  CBuildingSiteRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  CSettler *v3; // eax

  v3 = CSettlerMgr::operator[](a3);
  IEntity::Type(v3);
  return 1;
}


// address=[0x1502170]
// Decompiled from int __thiscall CBuildingSiteRole::GetBuildingNeed(CBuildingSiteRole *this, int a2)
int  CBuildingSiteRole::GetBuildingNeed(int a2)const {
  
  switch ( a2 )
  {
    case GOOD_BOARD:
      return CBuildingSiteRole::NeedBoards(this);
    case GOOD_GOLDBAR:
      return CBuildingSiteRole::NeedGold(this);
    case GOOD_STONE:
      return CBuildingSiteRole::NeedStone(this);
  }
  return 0;
}


// address=[0x15021c0]
// Decompiled from int __thiscall CBuildingSiteRole::GetPileIdWithGood(CBuildingSiteRole *this, int a2)
int  CBuildingSiteRole::GetPileIdWithGood(int a2)const {
  
  switch ( a2 )
  {
    case GOOD_BOARD:
      return this->m_uBoardsPileId;
    case GOOD_GOLDBAR:
      return this->m_uGoldPileId;
    case GOOD_STONE:
      return this->m_uStonePileId;
  }
  return 0;
}


// address=[0x1502220]
// Decompiled from int __thiscall CBuildingSiteRole::HaveBuildingMaterial(CBuildingSiteRole *this)
int  CBuildingSiteRole::HaveBuildingMaterial(void) {
  
  CPile *v1; // eax
  CPile *v2; // eax
  CPile *v3; // eax
  int result; // eax

  result = 1;
  if ( this->m_uBoardsPileId )
  {
    v1 = CPileMgr::operator[](this->m_uBoardsPileId);
    if ( CPile::GoodAvailable(v1) )
    {
      return result;
    }
  }
  if ( this->m_uStonePileId )
  {
    v2 = CPileMgr::operator[](this->m_uStonePileId);
    if ( CPile::GoodAvailable(v2) )
    {
      return result;
    }
  }
  if ( !this->m_uGoldPileId )
  {
    return 0;
  }
  v3 = CPileMgr::operator[](this->m_uGoldPileId);
  if ( !CPile::GoodAvailable(v3) )
  {
    return 0;
  }
  return result;
}


// address=[0x15022d0]
// Decompiled from void __thiscall CBuildingSiteRole::SetDiggingInfos(CBuildingSiteRole *this, int a2, int a3)
void  CBuildingSiteRole::SetDiggingInfos(int a2, int a3) {
  
  if ( a3 <= 1 )
  {
    this->m_iDiggingNeeded = 0;
    this->m_iMaxNeededDigger = 0;
  }
  else
  {
    this->m_iDigMap = a2;
    this->m_iDiggingNeeded = a3;
    this->m_iMaxNeededDigger = ((this->m_iDiggingNeeded + 16) >> 5) + 1;
    if ( this->m_iMaxNeededDigger > 8 )
    {
      this->m_iMaxNeededDigger = 8;
    }
  }
}


// address=[0x1502350]
// Decompiled from int __thiscall CBuildingSiteRole::BuildingProgress(CBuildingSiteRole *this)
int  CBuildingSiteRole::BuildingProgress(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( this->m_fBarDiv == 0.0 )
  {
    this->m_fBarDiv = (float)(this->m_iScaledTotalResources + this->m_iDiggingNeeded) / 100.0;
    if ( this->m_fBarDiv == 0.0 )
    {
      this->m_fBarDiv = FLOAT_1_0;
    }
  }
  if ( this->m_fBarDiv == 0.0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 2185, "m_fBarDiv != 0.0f") == 1 )
  {
    __debugbreak();
  }
  v2 = (int)(float)(100.0 - (float)((float)(this->m_iScaledTotalResources + this->m_iDiggingNeeded - this->m_iProvidedScaledTotalResouces) / this->m_fBarDiv));
  if ( v2 > 100 )
  {
    v2 = 100;
  }
  if ( v2 < 0 )
  {
    return 0;
  }
  return v2;
}


// address=[0x1502460]
// Decompiled from void __thiscall CBuildingSiteRole::SwitchPriority(CBuildingSiteRole *this)
void  CBuildingSiteRole::SwitchPriority(void) {
  
  int EcoSectorId; // [esp+0h] [ebp-8h]

  EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this);
  if ( EcoSectorId > 0 )
  {
    if ( this->m_bPriority )
    {
      this->m_bPriority = 0;
      CBuildingSiteRole::CheckDeactivateUrgentBoards(this, EcoSectorId);
      CBuildingSiteRole::CheckDeactivateUrgentStones(this, EcoSectorId);
      CBuildingSiteRole::CheckDeactivateUrgentDigger(this, EcoSectorId);
      CBuildingSiteRole::CheckDeactivateUrgentBuilder(this, EcoSectorId);
    }
    else
    {
      this->m_bPriority = 1;
      CBuildingSiteRole::CheckActivateUrgentBoards(this, EcoSectorId);
      CBuildingSiteRole::CheckActivateUrgentStones(this, EcoSectorId);
      CBuildingSiteRole::CheckActivateUrgentDigger(this, EcoSectorId);
      CBuildingSiteRole::CheckActivateUrgentBuilder(this, EcoSectorId);
    }
  }
}


// address=[0x1502510]
// Decompiled from _DWORD *__thiscall CBuildingSiteRole::FillDialog(CBuildingSiteRole *this, CBuilding *a2, bool a3)
void  CBuildingSiteRole::FillDialog(class CBuilding * a2, bool a3) {
  
  CBuilding *v3; // eax
  int v4; // eax
  CBuilding *v5; // eax
  CEcoSector *v6; // eax
  CEcoSector *v7; // eax
  int v8; // eax
  int v9; // eax
  CEcoSector *v10; // eax
  CEcoSector *v11; // eax
  CEcoSector *v12; // eax
  S4_BUILDING_ENUM v14; // [esp-8h] [ebp-70h]
  S4_BUILDING_ENUM v15; // [esp-8h] [ebp-70h]
  unsigned int v16; // [esp+4h] [ebp-64h]
  CPile *v17; // [esp+8h] [ebp-60h]
  CPile *v18; // [esp+Ch] [ebp-5Ch]
  CPile *v19; // [esp+10h] [ebp-58h]
  CPile *v20; // [esp+14h] [ebp-54h]
  CPile *v21; // [esp+18h] [ebp-50h]
  CPile *v22; // [esp+1Ch] [ebp-4Ch]
  S4_SETTLER_ENUM _iSettlerType; // [esp+24h] [ebp-44h]
  S4_GOOD_ENUM m_iTool; // [esp+28h] [ebp-40h]
  int bBuildingNeedsGold; // [esp+2Ch] [ebp-3Ch]
  int v26; // [esp+30h] [ebp-38h]
  int v27; // [esp+34h] [ebp-34h]
  int iESId; // [esp+38h] [ebp-30h]
  CEvn_Event v30; // [esp+40h] [ebp-28h] BYREF
  int v31; // [esp+64h] [ebp-4h]

  v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  v4 = CBuilding::EnsignWorldIdx(v3);
  iESId = CWorldManager::EcoSectorId(v4);
  if ( !iESId && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 2208, "iESId > 0") == 1 )
  {
    __debugbreak();
  }
  g_cBuildingSiteInfo.m_iUnknown = 1;
  g_cBuildingSiteInfo.m_cType = IEntity::Type(a2);
  g_cBuildingSiteInfo.m_cRace = IEntity::Race(a2);
  g_cBuildingSiteInfo.m_unknownB = 1;
  v5 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  g_cBuildingSiteInfo.m_bSomeFlagBits = IEntity::FlagBits(v5, (EntityFlag)0x1000) != 0;
  g_cBuildingSiteInfo.m_bPriority = this->m_bPriority;
  m_iTool = (char)this->m_pBuildingInfo->m_iTool;
  if ( this->m_pBuildingInfo->m_iTool )
  {
    v6 = CEcoSectorMgr::operator[](g_cESMgr, iESId);
    if ( CEcoSector::NrOfGoods(v6, m_iTool) <= 0 )
    {
      g_cBuildingSiteInfo.m_iTools = -(char)m_iTool;
    }
    else
    {
      g_cBuildingSiteInfo.m_iTools = m_iTool;
    }
  }
  _iSettlerType = this->m_pBuildingInfo->m_iBuildingInhabitant;
  if ( this->m_pBuildingInfo->m_iBuildingInhabitant )
  {
    v7 = CEcoSectorMgr::operator[](g_cESMgr, iESId);
    if ( CEcoSector::NrOfSettler(v7, _iSettlerType) <= 0 )
    {
      g_cBuildingSiteInfo.m_iSettlerCount = -(char)_iSettlerType;
    }
    else
    {
      g_cBuildingSiteInfo.m_iSettlerCount = _iSettlerType;
    }
  }
  g_cBuildingSiteInfo.m_bHasWorkingArea = this->m_pBuildingInfo->m_iWorkingAreaRadius > 0;
  v14 = IEntity::Type(a2);
  v8 = IEntity::OwnerId(a2);
  g_cBuildingSiteInfo.m_cTotalCount = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v8, v14, 0);
  v15 = IEntity::Type(a2);
  v9 = IEntity::OwnerId(a2);
  g_cBuildingSiteInfo.m_cTotalBuiltCount = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v9, v15, 1u);
  g_cBuildingSiteInfo.m_iBuildingProgress = CBuildingSiteRole::BuildingProgress(this);
  if ( this->m_uBoardsPileId )
  {
    v27 = CBuildingSiteRole::NeedBoards(this);
    v10 = CEcoSectorMgr::operator[](g_cESMgr, iESId);
    if ( CEcoSector::NrOfGoods(v10, GOOD_BOARD) < v27 )
    {
      v27 = -v27;
    }
    g_cBuildingSiteInfo.m_sRequiredRessources[0].m_cAmount = v27;
    if ( v27 )
    {
      g_cBuildingSiteInfo.m_sRequiredRessources[0].m_cType = GOOD_BOARD;
    }
    else
    {
      g_cBuildingSiteInfo.m_sRequiredRessources[0].m_cType = 0;
    }
  }
  else
  {
    g_cBuildingSiteInfo.m_sRequiredRessources[0].m_cType = 0;
  }
  if ( this->m_uStonePileId )
  {
    v26 = CBuildingSiteRole::NeedStone(this);
    v11 = CEcoSectorMgr::operator[](g_cESMgr, iESId);
    if ( CEcoSector::NrOfGoods(v11, GOOD_STONE) < v26 )
    {
      v26 = -v26;
    }
    g_cBuildingSiteInfo.m_sRequiredRessources[1].m_cAmount = v26;
    if ( v26 )
    {
      g_cBuildingSiteInfo.m_sRequiredRessources[1].m_cType = GOOD_STONE;
    }
    else
    {
      g_cBuildingSiteInfo.m_sRequiredRessources[1].m_cType = 0;
    }
  }
  else
  {
    g_cBuildingSiteInfo.m_sRequiredRessources[1].m_cType = 0;
  }
  if ( this->m_uGoldPileId )
  {
    bBuildingNeedsGold = CBuildingSiteRole::NeedGold(this);
    v12 = CEcoSectorMgr::operator[](g_cESMgr, iESId);
    if ( CEcoSector::NrOfGoods(v12, GOOD_GOLDBAR) < bBuildingNeedsGold )
    {
      bBuildingNeedsGold = -bBuildingNeedsGold;
    }
    g_cBuildingSiteInfo.m_sRequiredRessources[2].m_cAmount = bBuildingNeedsGold;
    if ( bBuildingNeedsGold )
    {
      g_cBuildingSiteInfo.m_sRequiredRessources[2].m_cType = GOOD_GOLDBAR;
    }
    else
    {
      g_cBuildingSiteInfo.m_sRequiredRessources[2].m_cType = 0;
    }
  }
  else
  {
    g_cBuildingSiteInfo.m_sRequiredRessources[2].m_cType = 0;
  }
  if ( this->m_uBoardsPileId )
  {
    v22 = CPileMgr::operator[](this->m_uBoardsPileId);
    g_cBuildingSiteInfo.m_sOtherRessources[0].m_cAmount = v22->Amount(v22);
    v21 = CPileMgr::operator[](this->m_uBoardsPileId);
    g_cBuildingSiteInfo.m_sOtherRessources[0].m_cType = v21->GetGoodType();
  }
  else
  {
    g_cBuildingSiteInfo.m_sOtherRessources[0].m_cAmount = 0;
    g_cBuildingSiteInfo.m_sOtherRessources[0].m_cType = 0;
  }
  if ( this->m_uStonePileId )
  {
    v20 = CPileMgr::operator[](this->m_uStonePileId);
    g_cBuildingSiteInfo.m_sOtherRessources[1].m_cAmount = v20->Amount(v20);
    v19 = CPileMgr::operator[](this->m_uStonePileId);
    g_cBuildingSiteInfo.m_sOtherRessources[1].m_cType = v19->GetGoodType();
  }
  else
  {
    g_cBuildingSiteInfo.m_sOtherRessources[1].m_cAmount = 0;
    g_cBuildingSiteInfo.m_sOtherRessources[1].m_cType = 0;
  }
  if ( this->m_uGoldPileId )
  {
    v18 = CPileMgr::operator[](this->m_uGoldPileId);
    g_cBuildingSiteInfo.m_sOtherRessources[2].m_cAmount = v18->Amount(v18);
    v17 = CPileMgr::operator[](this->m_uGoldPileId);
    g_cBuildingSiteInfo.m_sOtherRessources[2].m_cType = v17->GetGoodType();
  }
  else
  {
    g_cBuildingSiteInfo.m_sOtherRessources[2].m_cAmount = 0;
    g_cBuildingSiteInfo.m_sOtherRessources[2].m_cType = 0;
  }
  v16 = 604;
  if ( !a3 )
  {
    v16 = 602;
  }
  CEvn_Event::CEvn_Event(&v30, v16, 0, (unsigned int)&g_cBuildingSiteInfo, 0);
  v31 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v30);
  v31 = -1;
  return CEvn_Event::~CEvn_Event(&v30);
}


// address=[0x1502ac0]
// Decompiled from void __thiscall CBuildingSiteRole::GetBuilderPos(CBuildingSiteRole *this, struct SBuilderPos *a2)
void  CBuildingSiteRole::GetBuilderPos(struct SBuilderPos & a2) {
  
  CBuilding *v2; // eax
  CBuilding *v3; // eax

  if ( !this->m_uBuilderAct && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 950, "m_uBuilderAct") == 1 )
  {
    __debugbreak();
  }
  this->m_uPosCounter = this->m_uBuilderAct - 1;
  if ( this->m_uPosCounter >= this->m_pBuildingInfo->m_iBuilderNumber && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 953, "m_uPosCounter < m_pBuildingInfo->iBuilderNumber") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pBuildingInfo && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 954, "m_pBuildingInfo != 0") == 1 )
  {
    __debugbreak();
  }
  v2 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  a2->m_iOffsetX = (char)this->m_pBuildingInfo->m_vBuilder[this->m_uPosCounter].m_iXOffset + IEntity::X(v2);
  v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  a2->m_iOffsetY = (char)this->m_pBuildingInfo->m_vBuilder[this->m_uPosCounter].m_iYOffset + IEntity::Y(v3);
  a2->m_iDirection = (char)this->m_pBuildingInfo->m_vBuilder[this->m_uPosCounter++].m_iDirection;
}


// address=[0x1502c30]
// Decompiled from void __thiscall CBuildingSiteRole::AddWork(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::AddWork(int a2) {
  
  CPile *v2; // eax
  CPile *v3; // eax
  CPile *v4; // eax
  CPile *v5; // eax
  CPile *v6; // eax
  CPile *v7; // eax

  this->m_iProvidedScaledTotalResouces += a2;
  if ( this->m_iProvidedScaledTotalResouces >= 200 * this->m_iTotalProvidedResources )
  {
    if ( this->m_uBoardsPileId && (v2 = CPileMgr::operator[](this->m_uBoardsPileId), CPile::GoodAvailable(v2)) )
    {
      ++this->m_iTotalProvidedResources;
      ++this->m_uProvidedBoards;
      v3 = CPileMgr::operator[](this->m_uBoardsPileId);
      CPile::DecreaseUnforeseen(v3, 1);
    }
    else if ( this->m_uStonePileId && (v4 = CPileMgr::operator[](this->m_uStonePileId), CPile::GoodAvailable(v4)) )
    {
      ++this->m_iTotalProvidedResources;
      ++this->m_uProvidedStone;
      v5 = CPileMgr::operator[](this->m_uStonePileId);
      CPile::DecreaseUnforeseen(v5, 1);
    }
    else if ( this->m_uGoldPileId )
    {
      v6 = CPileMgr::operator[](this->m_uGoldPileId);
      if ( CPile::GoodAvailable(v6) )
      {
        ++this->m_iTotalProvidedResources;
        ++this->m_uProvidedGold;
        v7 = CPileMgr::operator[](this->m_uGoldPileId);
        CPile::DecreaseUnforeseen(v7, 1);
      }
    }
  }
}


// address=[0x1502de0]
// Decompiled from CBuildingSiteRole *__thiscall CBuildingSiteRole::CBuildingSiteRole(CBuildingSiteRole *this, struct std::istream *a1)
 CBuildingSiteRole::CBuildingSiteRole(std::istream & a2) {
  
  _DWORD v3[5]; // [esp+0h] [ebp-30h] BYREF
  unsigned int v4; // [esp+14h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+18h] [ebp-18h] BYREF
  CBuildingSiteRole *v6; // [esp+1Ch] [ebp-14h]
  _DWORD *v7; // [esp+20h] [ebp-10h]
  int v8; // [esp+2Ch] [ebp-4h]

  v7 = v3;
  v6 = this;
  IBuildingRole::IBuildingRole(this, a1);
  v8 = 0;
  v6->__vftable = (IBuildingRole_vtbl *)&CBuildingSiteRole::_vftable_;
  operator^<unsigned int>(a1, &v4);
  v3[4] = v4;
  if ( v4 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuildingSiteRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a1, &v6->field_17C);
  operator^<int>(a1, &v6->m_iDigMap);
  operator^<int>(a1, &v6->m_iMaxNeededDigger);
  operator^<int>(a1, &v6->m_iDiggingNeeded);
  operator^<unsigned char>(a1, &v6->m_uBuildStage);
  operator^<unsigned char>(a1, &v6->m_uDiggerAct);
  operator^<unsigned char>(a1, &v6->field_18E);
  operator^<unsigned char>(a1, &v6->field_18F);
  operator^<unsigned char>(a1, &v6->m_uBuilderAct);
  operator^<unsigned char>(a1, &v6->m_uPosCounter);
  operator^<unsigned char>(a1, &v6->m_uProvidedBoards);
  operator^<unsigned char>(a1, &v6->m_uProvidedStone);
  operator^<unsigned char>(a1, &v6->m_uProvidedGold);
  operator^<int>(a1, &v6->m_iProvidedScaledTotalResouces);
  operator^<int>(a1, &v6->m_iScaledTotalResources);
  operator^<int>(a1, &v6->m_iInverseScaledTotalResources);
  operator^<int>(a1, &v6->m_iFrameCount);
  operator^<int>(a1, &v6->m_iU0);
  operator^<unsigned short>(a1, &v6->m_uBoardsPileId);
  operator^<unsigned short>(a1, &v6->m_uStonePileId);
  operator^<unsigned short>(a1, &v6->m_uGoldPileId);
  operator^<unsigned short>(a1, &v6->m_uU00);
  operator^<bool>(a1, &v6->m_bPriority);
  operator^<bool>(a1, &v6->m_bDiggerPriority);
  operator^<bool>(a1, &v6->m_bBuilderPriority);
  operator^<bool>(a1, &v6->m_bBoardPriority);
  operator^<bool>(a1, &v6->m_bStonePriority);
  operator^<bool>(a1, &v6->m_bU0);
  operator^<int>(a1, &v6->m_iTotalProvidedResources);
  LOBYTE(v8) = 1;
  operator^<float>(a1, &v6->m_fBarDiv);
  v8 = -1;
  return v6;
}


// address=[0x1503150]
// Decompiled from void __thiscall CBuildingSiteRole::Store(CBuildingSiteRole *this, struct std::ostream *a1)
void  CBuildingSiteRole::Store(std::ostream & a1) {
  
  unsigned int v2; // [esp+0h] [ebp-8h] BYREF

  IBuildingRole::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<int>(a1, &this->field_17C);
  operator^<int>(a1, &this->m_iDigMap);
  operator^<int>(a1, &this->m_iMaxNeededDigger);
  operator^<int>(a1, &this->m_iDiggingNeeded);
  operator^<unsigned char>(a1, &this->m_uBuildStage);
  operator^<unsigned char>(a1, &this->m_uDiggerAct);
  operator^<unsigned char>(a1, &this->field_18E);
  operator^<unsigned char>(a1, &this->field_18F);
  operator^<unsigned char>(a1, &this->m_uBuilderAct);
  operator^<unsigned char>(a1, &this->m_uPosCounter);
  operator^<unsigned char>(a1, &this->m_uProvidedBoards);
  operator^<unsigned char>(a1, &this->m_uProvidedStone);
  operator^<unsigned char>(a1, &this->m_uProvidedGold);
  operator^<int>(a1, &this->m_iProvidedScaledTotalResouces);
  operator^<int>(a1, &this->m_iScaledTotalResources);
  operator^<int>(a1, &this->m_iInverseScaledTotalResources);
  operator^<int>(a1, &this->m_iFrameCount);
  operator^<int>(a1, &this->m_iU0);
  operator^<unsigned short>(a1, &this->m_uBoardsPileId);
  operator^<unsigned short>(a1, &this->m_uStonePileId);
  operator^<unsigned short>(a1, &this->m_uGoldPileId);
  operator^<unsigned short>(a1, &this->m_uU00);
  operator^<bool>(a1, &this->m_bPriority);
  operator^<bool>(a1, &this->m_bDiggerPriority);
  operator^<bool>(a1, &this->m_bBuilderPriority);
  operator^<bool>(a1, &this->m_bBoardPriority);
  operator^<bool>(a1, &this->m_bStonePriority);
  operator^<bool>(a1, &this->m_bU0);
  operator^<int>(a1, &this->m_iTotalProvidedResources);
  operator^<float>(a1, &this->m_fBarDiv);
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
  
  struct CBuilding *BuildingPtr; // [esp+0h] [ebp-8h]

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  return CBuildingSiteRole::GetEcoSectorId(this, BuildingPtr);
}


// address=[0x1503440]
// Decompiled from char __thiscall CBuildingSiteRole::CrushBuilding(CBuildingSiteRole *this)
bool  CBuildingSiteRole::CrushBuilding(void) {
  
  CEntityEvent v2; // [esp+4h] [ebp-4Ch] BYREF
  int v3; // [esp+1Ch] [ebp-34h]
  int v4; // [esp+20h] [ebp-30h]
  CEntityEvent *v5; // [esp+24h] [ebp-2Ch]
  int iOwner; // [esp+28h] [ebp-28h]
  int v7; // [esp+2Ch] [ebp-24h]
  CBuilding *v8; // [esp+30h] [ebp-20h]
  int j; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  char v12; // [esp+43h] [ebp-Dh]
  int v13; // [esp+4Ch] [ebp-4h]

  CTrace::Print("CrushBuilding for building %u ", this->m_iEntityId);
  CEntityEvent::CEntityEvent(&v2, 9u, 0, this->m_iEntityId, 0, 0);
  v13 = 0;
  v5 = &v2;
  CBuildingSiteRole::TidyUp(this, &v2);
  v8 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  v3 = IEntity::X(v8);
  v4 = IEntity::Y(v8);
  if ( this->m_uBuildStage == 2 )
  {
    v7 = 31;
    iOwner = IEntity::OwnerId(v8);
    for ( i = 0;
          i < v7;
          ++i )
    {
      for ( j = 0;
            j < v7;
            ++j )
      {
        if ( s_iDigMap[iOwner][this->m_iDigMap].m_vCells[j][i] )
        {
          CWorldManager::ClearFlagBits(v3 + j - 15, v4 + i - 15, 16);
        }
      }
    }
    s_iDigMap[iOwner][this->m_iDigMap].m_uHeader = 0;
    this->m_iDigMap = -1;
  }
  CBuildingSiteRole::DeleteStakes(this, v8);
  v12 = 1;
  v13 = -1;
  CEntityEvent::~CEntityEvent(&v2);
  return v12;
}


// address=[0x15035e0]
// Decompiled from int __thiscall CBuildingSiteRole::Switch(CBuildingSiteRole *this)
void  CBuildingSiteRole::Switch(void) {
  
  int v1; // eax
  int v2; // eax
  struct CEcoSector *v3; // eax
  int m_iEntityId; // [esp-4h] [ebp-54h]
  CEntityEvent v6; // [esp+4h] [ebp-4Ch] BYREF
  CEntityEvent v7; // [esp+1Ch] [ebp-34h] BYREF
  CEntityEvent *v8; // [esp+34h] [ebp-1Ch]
  const struct CEntityEvent *v9; // [esp+38h] [ebp-18h]
  CBuilding *v10; // [esp+3Ch] [ebp-14h]
  int v12; // [esp+4Ch] [ebp-4h]

  v10 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  if ( IEntity::FlagBits(v10, (EntityFlag)4096) )
  {
    CTrace::Print("BuildingSite %u stopped", this->m_iEntityId);
    IEntity::ClearFlagBits(v10, (EntityFlag)4096);
    CEntityEvent::CEntityEvent(&v7, 7u, 0, this->m_iEntityId, 0, 0);
    v12 = 0;
    v9 = &v7;
    CBuildingSiteRole::TidyUp(this, &v7);
    CBuilding::NotifyAllObservers(v10, v9);
    CBuilding::DetachAllNonePileObservers(v10);
    this->m_uDiggerAct = 0;
    this->m_uBuilderAct = 0;
    m_iEntityId = this->m_iEntityId;
    v1 = CBuilding::EnsignWorldIdx(v10);
    v2 = CWorldManager::EcoSectorId(v1);
    v3 = CEcoSectorMgr::operator[](g_cESMgr, v2);
    CEcoSector::CleanUpBuildingNeed(v3, m_iEntityId);
    this->m_uPosCounter = 0;
    v12 = -1;
    return CEntityEvent::~CEntityEvent(&v7);
  }
  else
  {
    CTrace::Print("BuildingSite %u started", this->m_iEntityId);
    CEntityEvent::CEntityEvent(&v6, 8u, 0, this->m_iEntityId, 0, 0);
    v12 = 1;
    v8 = &v6;
    v10->Notify(&v6);
    IEntity::SetFlagBits(v10, (EntityFlag)4096);
    IAnimatedEntity::RegisterForLogicUpdate(v10, 1);
    v12 = -1;
    return CEntityEvent::~CEntityEvent(&v6);
  }
}


// address=[0x1503780]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivateUrgentBoards(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivateUrgentBoards(int a2) {
  
  CEcoSector *v2; // eax

  if ( this->m_bBoardPriority )
  {
    this->m_bBoardPriority = 0;
    v2 = CEcoSectorMgr::operator[](g_cESMgr, a2);
    CEcoSector::ChangePrioBoards(v2, -1);
    CBuildingSiteRole::CheckDeactivatePriority(this, a2);
  }
}


// address=[0x15037d0]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivateUrgentStones(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivateUrgentStones(int a2) {
  
  CEcoSector *v2; // eax

  if ( this->m_bStonePriority )
  {
    this->m_bStonePriority = 0;
    v2 = CEcoSectorMgr::operator[](g_cESMgr, a2);
    CEcoSector::ChangePrioStone(v2, -1);
    CBuildingSiteRole::CheckDeactivatePriority(this, a2);
  }
}


// address=[0x1503820]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivateUrgentBuilder(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivateUrgentBuilder(int a2) {
  
  CEcoSector *v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  if ( this->m_bBuilderPriority )
  {
    CTrace::Print("CheckDeactivateUrgentBuilder - DEACTIVATE for building %u", this->m_iEntityId);
    this->m_bBuilderPriority = 0;
    v3 = -this->m_pBuildingInfo->m_iBuilderNumber;
    v2 = CEcoSectorMgr::operator[](g_cESMgr, a2);
    CEcoSector::ChangePrioBuilder(v2, -1, v3);
    CBuildingSiteRole::CheckDeactivatePriority(this, a2);
  }
}


// address=[0x1503890]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivateUrgentDigger(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckDeactivateUrgentDigger(int a2) {
  
  CEcoSector *v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  if ( this->m_bDiggerPriority )
  {
    this->m_bDiggerPriority = 0;
    v3 = -this->m_iMaxNeededDigger;
    v2 = CEcoSectorMgr::operator[](g_cESMgr, a2);
    CEcoSector::ChangePrioDigger(v2, -1, v3);
    CBuildingSiteRole::CheckDeactivatePriority(this, a2);
  }
}


// address=[0x15038f0]
// Decompiled from void __thiscall CBuildingSiteRole::CheckDeactivatePriority(CBuildingSiteRole *this, int _iBuildingEcoSectorId)
void  CBuildingSiteRole::CheckDeactivatePriority(int _iBuildingEcoSectorId) {
  
  CEcoSector *v2; // eax
  CEcoSector *v3; // eax

  if ( !this->m_bBoardPriority && !this->m_bStonePriority && !this->m_bBuilderPriority && !this->m_bDiggerPriority )
  {
    v2 = CEcoSectorMgr::operator[](g_cESMgr, _iBuildingEcoSectorId);
    if ( !CEcoSector::BuildingSitesWithPrio(v2) && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 1871, "g_cESMgr[ _iBuildingEcoSectorId ].BuildingSitesWithPrio() != 0") == 1 )
    {
      __debugbreak();
    }
    this->m_bPriority = 0;
    v3 = CEcoSectorMgr::operator[](g_cESMgr, _iBuildingEcoSectorId);
    CEcoSector::ChangeBuildingSitesWithPrio(v3, -1);
  }
}


// address=[0x15039a0]
// Decompiled from void __thiscall CBuildingSiteRole::CheckActivateUrgentBoards(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckActivateUrgentBoards(int a2) {
  
  CEcoSector *v2; // eax
  CBuilding *v3; // eax
  CEcoSector *v4; // eax
  CEcoSector *v5; // eax

  if ( CBuildingSiteRole::NeedBoards(this) )
  {
    v2 = CEcoSectorMgr::operator[](g_cESMgr, a2);
    if ( CEcoSector::BuildingSitesWithPrio(v2) < 10 )
    {
      v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
      if ( IEntity::FlagBits(v3, (EntityFlag)4096) )
      {
        if ( !this->m_bBoardPriority && !this->m_bStonePriority && !this->m_bBuilderPriority && !this->m_bDiggerPriority )
        {
          v4 = CEcoSectorMgr::operator[](g_cESMgr, a2);
          CEcoSector::ChangeBuildingSitesWithPrio(v4, 1);
        }
        if ( !this->m_bBoardPriority )
        {
          this->m_bBoardPriority = 1;
          v5 = CEcoSectorMgr::operator[](g_cESMgr, a2);
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
  CBuilding *v3; // eax
  CEcoSector *v4; // eax
  CEcoSector *v5; // eax

  if ( CBuildingSiteRole::NeedStone(this) )
  {
    v2 = CEcoSectorMgr::operator[](g_cESMgr, a2);
    if ( CEcoSector::BuildingSitesWithPrio(v2) < 10 )
    {
      v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
      if ( IEntity::FlagBits(v3, (EntityFlag)4096) )
      {
        if ( !this->m_bBoardPriority && !this->m_bStonePriority && !this->m_bBuilderPriority && !this->m_bDiggerPriority )
        {
          v4 = CEcoSectorMgr::operator[](g_cESMgr, a2);
          CEcoSector::ChangeBuildingSitesWithPrio(v4, 1);
        }
        if ( !this->m_bStonePriority )
        {
          this->m_bStonePriority = 1;
          v5 = CEcoSectorMgr::operator[](g_cESMgr, a2);
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
  CBuilding *v3; // eax
  CEcoSector *v4; // eax
  CEcoSector *v5; // eax
  int m_iBuilderNumber; // [esp-4h] [ebp-8h]

  v2 = CEcoSectorMgr::operator[](g_cESMgr, a2);
  if ( CEcoSector::BuildingSitesWithPrio(v2) < 10 )
  {
    v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
    if ( IEntity::FlagBits(v3, (EntityFlag)4096) )
    {
      if ( !this->m_bBoardPriority && !this->m_bStonePriority && !this->m_bBuilderPriority && !this->m_bDiggerPriority )
      {
        v4 = CEcoSectorMgr::operator[](g_cESMgr, a2);
        CEcoSector::ChangeBuildingSitesWithPrio(v4, 1);
      }
      if ( !this->m_bBuilderPriority )
      {
        this->m_bBuilderPriority = 1;
        m_iBuilderNumber = this->m_pBuildingInfo->m_iBuilderNumber;
        v5 = CEcoSectorMgr::operator[](g_cESMgr, a2);
        CEcoSector::ChangePrioBuilder(v5, 1, m_iBuilderNumber);
      }
    }
  }
}


// address=[0x1503c40]
// Decompiled from void __thiscall CBuildingSiteRole::CheckActivateUrgentDigger(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::CheckActivateUrgentDigger(int a2) {
  
  CEcoSector *v2; // eax
  CBuilding *v3; // eax
  CEcoSector *v4; // eax
  CEcoSector *v5; // eax
  int m_iMaxNeededDigger; // [esp-4h] [ebp-8h]

  if ( this->m_iDiggingNeeded > 0 && this->m_iMaxNeededDigger - this->m_uDiggerAct > 0 )
  {
    v2 = CEcoSectorMgr::operator[](g_cESMgr, a2);
    if ( CEcoSector::BuildingSitesWithPrio(v2) < 10 )
    {
      v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
      if ( IEntity::FlagBits(v3, (EntityFlag)4096) )
      {
        if ( !this->m_bBoardPriority && !this->m_bStonePriority && !this->m_bBuilderPriority && !this->m_bDiggerPriority )
        {
          v4 = CEcoSectorMgr::operator[](g_cESMgr, a2);
          CEcoSector::ChangeBuildingSitesWithPrio(v4, 1);
        }
        if ( !this->m_bDiggerPriority )
        {
          this->m_bDiggerPriority = 1;
          m_iMaxNeededDigger = this->m_iMaxNeededDigger;
          v5 = CEcoSectorMgr::operator[](g_cESMgr, a2);
          CEcoSector::ChangePrioDigger(v5, 1, m_iMaxNeededDigger);
        }
      }
    }
  }
}


// address=[0x1503d50]
// Decompiled from void __fastcall CBuildingSiteRole::OrderDigger(CBuildingSiteRole *this, int a2, struct CBuilding *a3)
void  CBuildingSiteRole::OrderDigger(class CBuilding * a2) {
  
  int v3; // esi
  int v4; // eax
  int EcoSectorId; // [esp+Ch] [ebp-Ch]
  CEcoSector *v6; // [esp+10h] [ebp-8h]

  if ( this->m_iDiggingNeeded > 0 )
  {
    EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this, a3);
    if ( EcoSectorId > 0 )
    {
      v6 = CEcoSectorMgr::operator[](g_cESMgr, EcoSectorId);
      if ( this->m_bDiggerPriority || (v3 = CEcoSector::NeededPrioDigger(v6), v3 < CEcoSector::NrOfSettler(v6, SETTLER_DIGGER)) )
      {
        if ( (!this->m_uDiggerAct || this->m_iDiggingNeeded / this->m_uDiggerAct >= 10) && this->m_iMaxNeededDigger - this->m_uDiggerAct > 0 )
        {
          v4 = IEntity::ID(a3);
          if ( CEcoSector::CallWorker(v6, v4, 2) )
          {
            ++this->m_uDiggerAct;
          }
        }
      }
    }
  }
}


// address=[0x1503e40]
// Decompiled from void __thiscall CBuildingSiteRole::DiggingIsReady(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::DiggingIsReady(int a2) {
  
  int EcoSectorId; // [esp+0h] [ebp-8h]

  this->m_uBuildStage = 4;
  if ( this->m_iDigMap != -1 )
  {
    s_iDigMap[a2][this->m_iDigMap].m_uHeader = 0;
    this->m_iDigMap = -1;
  }
  EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this);
  if ( EcoSectorId > 0 )
  {
    CBuildingSiteRole::CheckDeactivateUrgentDigger(this, EcoSectorId);
  }
}


// address=[0x1503eb0]
// Decompiled from void __thiscall CBuildingSiteRole::TidyUp(CBuildingSiteRole *this, struct CEntityEvent *a2)
void  CBuildingSiteRole::TidyUp(class CEntityEvent & a2) {
  
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
// Decompiled from void __thiscall CBuildingSiteRole::NotifyDeliverPiles(CBuildingSiteRole *this, CEntityEvent *a2)
void  CBuildingSiteRole::NotifyDeliverPiles(class CEntityEvent & a2) {
  
  CPile *v2; // eax
  CPile *v3; // [esp+4h] [ebp-Ch]
  CPile *v4; // [esp+8h] [ebp-8h]

  if ( this->m_uBoardsPileId )
  {
    v4 = CPileMgr::operator[](this->m_uBoardsPileId);
    v4->SetEvent(v4, a2);
  }
  if ( this->m_uStonePileId )
  {
    v3 = CPileMgr::operator[](this->m_uStonePileId);
    v3->SetEvent(v3, a2);
  }
  if ( this->m_uGoldPileId )
  {
    v2 = CPileMgr::operator[](this->m_uGoldPileId);
    v2->SetEvent(v2, a2);
  }
}


// address=[0x1503fd0]
// Decompiled from void __thiscall CBuildingSiteRole::OrderBuilder(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::OrderBuilder(class CBuilding * a2) {
  
  int v2; // esi
  int v3; // eax
  int EcoSectorId; // [esp+10h] [ebp-Ch]
  CEcoSector *v5; // [esp+14h] [ebp-8h]

  if ( CBuildingSiteRole::HaveBuildingMaterial(this) )
  {
    EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this, a2);
    if ( EcoSectorId > 0 )
    {
      v5 = CEcoSectorMgr::operator[](g_cESMgr, EcoSectorId);
      if ( this->m_bBuilderPriority || (v2 = CEcoSector::NeededPrioBuilder(v5), v2 < CEcoSector::NrOfSettler(v5, SETTLER_BUILDER)) )
      {
        if ( (this->m_uBuildStage >= 4u || this->m_iDiggingNeeded < 40 && this->m_uDiggerAct) && this->m_uBuilderNumber - this->m_uBuilderAct > 0 )
        {
          v3 = IEntity::ID(a2);
          if ( CEcoSector::CallWorker(v5, v3, 3) )
          {
            ++this->m_uBuilderAct;
          }
        }
      }
    }
  }
}


// address=[0x15040d0]
// Decompiled from void __thiscall CBuildingSiteRole::OrderMaterial(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::OrderMaterial(class CBuilding * a2) {
  
  int v2; // esi
  CEcoSector *v3; // eax
  int v4; // esi
  CEcoSector *v5; // eax
  int v6; // esi
  __int16 v7; // [esp-8h] [ebp-2Ch]
  __int16 v8; // [esp-8h] [ebp-2Ch]
  __int16 v9; // [esp-8h] [ebp-2Ch]
  int v10; // [esp+4h] [ebp-20h]
  int v11; // [esp+8h] [ebp-1Ch]
  int v12; // [esp+Ch] [ebp-18h]
  CPile *v13; // [esp+10h] [ebp-14h]
  CPile *v14; // [esp+14h] [ebp-10h]
  CPile *v15; // [esp+18h] [ebp-Ch]
  int EcoSectorId; // [esp+1Ch] [ebp-8h]

  EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this, a2);
  if ( EcoSectorId > 0 )
  {
    if ( this->m_bPriority )
    {
      if ( CBuildingSiteRole::NeedBoards(this) )
      {
        CBuildingSiteRole::CheckActivateUrgentBoards(this, EcoSectorId);
      }
      else
      {
        CBuildingSiteRole::CheckDeactivateUrgentBoards(this, EcoSectorId);
      }
      if ( CBuildingSiteRole::NeedStone(this) )
      {
        CBuildingSiteRole::CheckActivateUrgentStones(this, EcoSectorId);
      }
      else
      {
        CBuildingSiteRole::CheckDeactivateUrgentStones(this, EcoSectorId);
      }
    }
    if ( this->m_uDiggerAct || this->m_uBuildStage >= 3u )
    {
      if ( this->m_uBoardsPileId )
      {
        v15 = CPileMgr::operator[](this->m_uBoardsPileId);
        v2 = CPile::AmountComing(v15);
        v12 = v15->Amount(v15) + v2;
        if ( v12 < this->m_uBoards - this->m_uProvidedBoards && v12 < 8 )
        {
          v3 = CEcoSectorMgr::operator[](g_cESMgr, EcoSectorId);
          if ( !CEcoSector::PrioBoards(v3) || this->m_bBoardPriority )
          {
            v7 = IEntity::ID(a2);
            CEcoSectorMgr::operator[](g_cESMgr, EcoSectorId);
            CEcoSector::RequestGood(v7, 7);
          }
        }
      }
      if ( this->m_uStonePileId )
      {
        v14 = CPileMgr::operator[](this->m_uStonePileId);
        v4 = CPile::AmountComing(v14);
        v11 = v14->Amount(v14) + v4;
        if ( v11 < this->m_uStone - this->m_uProvidedStone && v11 < 8 )
        {
          v5 = CEcoSectorMgr::operator[](g_cESMgr, EcoSectorId);
          if ( !CEcoSector::PrioStone(v5) || this->m_bStonePriority )
          {
            v8 = IEntity::ID(a2);
            CEcoSectorMgr::operator[](g_cESMgr, EcoSectorId);
            CEcoSector::RequestGood(v8, 32);
          }
        }
      }
      if ( this->m_uGoldPileId )
      {
        v13 = CPileMgr::operator[](this->m_uGoldPileId);
        v6 = CPile::AmountComing(v13);
        v10 = v13->Amount(v13) + v6;
        if ( v10 < this->m_uGold - this->m_uProvidedGold && v10 < 8 )
        {
          v9 = IEntity::ID(a2);
          CEcoSectorMgr::operator[](g_cESMgr, EcoSectorId);
          CEcoSector::RequestGood(v9, 14);
        }
      }
    }
  }
}


// address=[0x1504360]
// Decompiled from void __thiscall CBuildingSiteRole::BuildingDone(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::BuildingDone(class CBuilding * a2) {
  
  int v2; // eax
  CEntityEvent v3; // [esp+4h] [ebp-34h] BYREF
  const struct CEntityEvent *v4; // [esp+1Ch] [ebp-1Ch]
  const struct CEntityEvent *v5; // [esp+20h] [ebp-18h]
  int EcoSectorId; // [esp+24h] [ebp-14h]
  int v8; // [esp+34h] [ebp-4h]

  v2 = IEntity::ID(a2);
  CTrace::Print("Building nr: %u ready", v2);
  EcoSectorId = CBuildingSiteRole::GetEcoSectorId(this, a2);
  if ( EcoSectorId > 0 )
  {
    CBuildingSiteRole::CheckDeactivateUrgentBoards(this, EcoSectorId);
    CBuildingSiteRole::CheckDeactivateUrgentStones(this, EcoSectorId);
    CBuildingSiteRole::CheckDeactivateUrgentDigger(this, EcoSectorId);
    CBuildingSiteRole::CheckDeactivateUrgentBuilder(this, EcoSectorId);
    if ( this->m_uBoardsPileId )
    {
      a2->Detach(a2, this->m_uBoardsPileId);
      CPileMgr::DeletePile(&g_cPileMgr, this->m_uBoardsPileId);
    }
    if ( this->m_uStonePileId )
    {
      a2->Detach(a2, this->m_uStonePileId);
      CPileMgr::DeletePile(&g_cPileMgr, this->m_uStonePileId);
    }
    if ( this->m_uGoldPileId )
    {
      a2->Detach(a2, this->m_uGoldPileId);
      CPileMgr::DeletePile(&g_cPileMgr, this->m_uGoldPileId);
    }
    v5 = CEntityEvent::CEntityEvent(&v3, 9u, 0, 0, 0, 0);
    v4 = v5;
    v8 = 0;
    CBuilding::NotifyAndDetachAllObservers(a2, v5);
    v8 = -1;
    CEntityEvent::~CEntityEvent(&v3);
    IEntity::ClearFlagBits(a2, ENTITY_FLAG_Birth);
    IEntity::SetFlagBits(a2, ENTITY_FLAG_Ready);
    CBuilding::Ready(a2);
  }
}


// address=[0x1504510]
// Decompiled from void __thiscall CBuildingSiteRole::DeleteStakes(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::DeleteStakes(class CBuilding * a2) {
  
  _DWORD *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  _BYTE v8[12]; // [esp+4h] [ebp-58h] BYREF
  _BYTE v9[12]; // [esp+10h] [ebp-4Ch] BYREF
  _DWORD v10[4]; // [esp+1Ch] [ebp-40h] BYREF
  std::_Iterator_base12 *v11; // [esp+2Ch] [ebp-30h]
  int v12; // [esp+30h] [ebp-2Ch]
  int v13; // [esp+34h] [ebp-28h]
  int v14; // [esp+38h] [ebp-24h]
  int v15; // [esp+3Ch] [ebp-20h]
  int v16; // [esp+40h] [ebp-1Ch]
  int i; // [esp+48h] [ebp-14h]
  char v19; // [esp+4Fh] [ebp-Dh]
  int v20; // [esp+58h] [ebp-4h]

  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v10);
  v20 = 0;
  v16 = 0;
  v13 = std::vector<unsigned int>::begin(&this->m_pBuildingInfo->m_vBuildingPosLines, (int)v9);
  v12 = v13;
  LOBYTE(v20) = 1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v10, v13);
  LOBYTE(v20) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v9);
  while ( 1 )
  {
    v11 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(&this->m_pBuildingInfo->m_vBuildingPosLines, (int)v8);
    v10[3] = v11;
    LOBYTE(v20) = 2;
    v19 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v11);
    LOBYTE(v20) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v8);
    if ( !v19 )
    {
      break;
    }
    ++v16;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v10) )
    {
      for ( i = 31;
            i >= 0;
            --i )
      {
        v2 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v10);
        if ( (*v2 & (1 << i)) != 0 )
        {
          v3 = IEntity::WorldIdx(a2);
          v4 = CWorldManager::X(v3);
          v14 = v4 + 32 - i - this->m_pBuildingInfo->m_iHotSpotX - 1;
          v5 = IEntity::WorldIdx(a2);
          v6 = CWorldManager::Y(v5);
          v15 = v16 + v6 - this->m_pBuildingInfo->m_iHotSpotY - 1;
          if ( !CWorldManager::PileId(v14, v15) )
          {
            v7 = CWorldManager::Index(v14, v15);
            CWorldManager::SetObjectId(v7, 0);
          }
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v10);
  }
  v20 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v10);
}


// address=[0x15046e0]
// Decompiled from void __thiscall CBuildingSiteRole::BuilderLeft(CBuildingSiteRole *this, int a2)
void  CBuildingSiteRole::BuilderLeft(int a2) {
  
  CSettler *v2; // eax
  CSettler *v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-8h]

  v2 = CSettlerMgr::operator[](a2);
  v5 = IEntity::Type(v2);
  if ( v5 == SETTLER_DIGGER )
  {
    if ( !this->m_uDiggerAct && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingSite.cpp", 1183, "m_uDiggerAct") == 1 )
    {
      __debugbreak();
    }
    --this->m_uDiggerAct;
  }
  else if ( v5 == SETTLER_BUILDER )
  {
    if ( this->m_uBuilderAct )
    {
      --this->m_uBuilderAct;
    }
  }
  else
  {
    v3 = CSettlerMgr::operator[](a2);
    v4 = IEntity::Type(v3);
    if ( BBSupportDbgReportF(2, "MapObjects\\Building\\BuildingSite.cpp", 1201, "Wrong Builder left. ID %d, Type %d", a2, v4) == 1 )
    {
      __debugbreak();
    }
  }
}


// address=[0x15047d0]
// Decompiled from void __thiscall CBuildingSiteRole::ReturnBuildingMaterial(CBuildingSiteRole *this, struct CBuilding *a2)
void  CBuildingSiteRole::ReturnBuildingMaterial(class CBuilding * a2) {
  
  unsigned int v2; // [esp+0h] [ebp-18h]
  unsigned int v3; // [esp+4h] [ebp-14h]
  signed int v5; // [esp+Ch] [ebp-Ch]
  signed int v6; // [esp+10h] [ebp-8h]
  signed int v7; // [esp+14h] [ebp-4h]

  v2 = IEntity::X(a2);
  v3 = IEntity::Y(a2);
  if ( this->m_uBoardsPileId )
  {
    v7 = this->m_uProvidedBoards / 2;
    while ( v7 )
    {
      if ( v7 <= 8 )
      {
        CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v2, v3, GOOD_BOARD, v7);
        v7 = 0;
      }
      else
      {
        CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v2, v3, GOOD_BOARD, 8u);
        v7 -= 8;
      }
    }
  }
  if ( this->m_uStonePileId )
  {
    v6 = this->m_uProvidedStone / 2;
    while ( v6 )
    {
      if ( v6 <= 8 )
      {
        CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v2, v3, GOOD_STONE, v6);
        v6 = 0;
      }
      else
      {
        CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v2, v3, GOOD_STONE, 8u);
        v6 -= 8;
      }
    }
  }
  if ( this->m_uGoldPileId )
  {
    v5 = this->m_uProvidedGold / 2;
    while ( v5 )
    {
      if ( v5 <= 8 )
      {
        CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v2, v3, GOOD_GOLDBAR, v5);
        v5 = 0;
      }
      else
      {
        CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v2, v3, GOOD_GOLDBAR, 8u);
        v5 -= 8;
      }
    }
  }
}


// address=[0x1504960]
// Decompiled from void __thiscall CBuildingSiteRole::PrepareGround(CBuildingSiteRole *this, CBuilding *a2)
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
  WORD v14; // ax
  CPile *v15; // eax
  WORD v16; // ax
  CPile *v17; // eax
  WORD v18; // ax
  CPile *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // [esp-10h] [ebp-140h]
  int v29; // [esp-10h] [ebp-140h]
  int v30; // [esp-10h] [ebp-140h]
  int v31; // [esp-Ch] [ebp-13Ch]
  int v32; // [esp-Ch] [ebp-13Ch]
  int m_iHotSpotX; // [esp-Ch] [ebp-13Ch]
  int v34; // [esp-8h] [ebp-138h]
  int v35; // [esp-8h] [ebp-138h]
  int m_iHotSpotY; // [esp-8h] [ebp-138h]
  __int16 v37; // [esp-4h] [ebp-134h]
  int v38; // [esp-4h] [ebp-134h]
  int v39; // [esp-4h] [ebp-134h]
  int v40; // [esp-4h] [ebp-134h]
  std::vector *p_m_vWaterRepealingPosLines; // [esp-4h] [ebp-134h]
  int v42; // [esp-4h] [ebp-134h]
  std::vector *p_m_vWaterFreePosLines; // [esp-4h] [ebp-134h]
  int v44; // [esp-4h] [ebp-134h]
  std::vector *p_m_vBuildingPosLines; // [esp-4h] [ebp-134h]
  int v46; // [esp-4h] [ebp-134h]
  __int16 v47; // [esp-4h] [ebp-134h]
  CBuildingFlagsWalk v48; // [esp+8h] [ebp-128h] BYREF
  CBuildingFlagsWalk v49; // [esp+24h] [ebp-10Ch] BYREF
  CBuildingFlagsWalk v50; // [esp+40h] [ebp-F0h] BYREF
  _BYTE v51[12]; // [esp+5Ch] [ebp-D4h] BYREF
  _BYTE v52[12]; // [esp+68h] [ebp-C8h] BYREF
  int v53; // [esp+74h] [ebp-BCh]
  int v54; // [esp+78h] [ebp-B8h]
  int v55; // [esp+7Ch] [ebp-B4h]
  int v56; // [esp+80h] [ebp-B0h]
  std::_Iterator_base12 *v57; // [esp+84h] [ebp-ACh]
  std::_Iterator_base12 *v58; // [esp+88h] [ebp-A8h]
  int v59; // [esp+8Ch] [ebp-A4h]
  int v60; // [esp+90h] [ebp-A0h]
  _DWORD v61[3]; // [esp+94h] [ebp-9Ch] BYREF
  int v62; // [esp+A0h] [ebp-90h]
  int v63; // [esp+A4h] [ebp-8Ch]
  int v64; // [esp+A8h] [ebp-88h]
  int v65; // [esp+ACh] [ebp-84h]
  int v66; // [esp+B0h] [ebp-80h]
  int v67; // [esp+B4h] [ebp-7Ch]
  int j; // [esp+B8h] [ebp-78h]
  int k; // [esp+BCh] [ebp-74h]
  char v70; // [esp+C2h] [ebp-6Eh]
  int v72; // [esp+C4h] [ebp-6Ch]
  int v73; // [esp+C8h] [ebp-68h]
  int i; // [esp+CCh] [ebp-64h]
  _DWORD v77[18]; // [esp+D8h] [ebp-58h] BYREF
  int v78; // [esp+12Ch] [ebp-4h]

  if ( IEntity::Type(a2) == BUILDING_MUSHROOMFARM || IEntity::Type(a2) == BUILDING_MANACOPTERHALL )
  {
    p_m_vBuildingPosLines = &this->m_pBuildingInfo->m_vBuildingPosLines;
    m_iHotSpotY = this->m_pBuildingInfo->m_iHotSpotY;
    m_iHotSpotX = this->m_pBuildingInfo->m_iHotSpotX;
    v30 = IEntity::Y(a2);
    v25 = IEntity::X(a2);
    CBuildingFlagsWalk::CBuildingFlagsWalk(&v48, v25, v30, m_iHotSpotX, m_iHotSpotY, p_m_vBuildingPosLines);
    while ( CBuildingFlagsWalk::NextPosition(&v48) )
    {
      v46 = CBuildingFlagsWalk::CurrentY(&v48);
      v26 = CBuildingFlagsWalk::CurrentX(&v48);
      v62 = CWorldManager::Index(v26, v46);
      CWorldManager::SetObjectId(v62, 0);
      CWorldManager::SetFlagBits(v62, 8u);
    }
    v47 = IEntity::ID(a2);
    v27 = IEntity::WorldIdx(a2);
    CWorldManager::SetObjectId(v27, v47);
    this->m_uBuildStage = 6;
  }
  else
  {
    v54 = 1;
    for ( i = 0;
          i < 6;
          ++i )
    {
      v77[3 * i] = 0;
    }
    v55 = IEntity::X(a2) + 32 - this->m_pBuildingInfo->m_iHotSpotX - 1;
    v56 = IEntity::Y(a2) - this->m_pBuildingInfo->m_iHotSpotY - 1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v61);
    v78 = 0;
    v66 = 0;
    v60 = std::vector<unsigned int>::begin(&this->m_pBuildingInfo->m_vBuildingPosLines, (int)v52);
    v59 = v60;
    LOBYTE(v78) = 1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v61, v60);
    LOBYTE(v78) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v52);
    while ( 1 )
    {
      v58 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(&this->m_pBuildingInfo->m_vBuildingPosLines, (int)v51);
      v57 = v58;
      LOBYTE(v78) = 2;
      v70 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v58);
      LOBYTE(v78) = 0;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v51);
      if ( !v70 )
      {
        break;
      }
      ++v66;
      if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v61) )
      {
        v72 = v66 + v56;
        for ( j = 31;
              j >= 0;
              --j )
        {
          v2 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v61);
          if ( (*v2 & (1 << j)) != 0 )
          {
            v73 = v55 - j;
            if ( IGfxEngine::CanChangeGround(g_pGfxEngine, v55 - j, v72, 28) )
            {
              CWorldManager::SetGround(v73, v72, 28);
              IGfxEngine::UpdateWorldPosition(g_pGfxEngine, v73, v72);
            }
            CWorldManager::SetObjectId(v73, v72, 0);
            CWorldManager::SetFlagBits(v73, v72, 8);
            if ( v54 && (v73 || v72) )
            {
              for ( k = 0;
                    ;
                    ++k )
              {
                v3 = IEntity::X(a2);
                v4 = CSpiralOffsets::DeltaX(k);
                if ( v4 + v3 == v73 )
                {
                  v5 = IEntity::Y(a2);
                  v6 = CSpiralOffsets::DeltaY(k);
                  if ( v6 + v5 == v72 )
                  {
                    break;
                  }
                }
              }
              v67 = CSpiralOffsets::Direction(k);
              v7 = CSpiralOffsets::Radius(k);
              if ( v7 >= v77[3 * v67] )
              {
                v8 = CSpiralOffsets::Radius(k);
                v77[3 * v67] = v8;
                v77[3 * v67 + 1] = v73;
                v77[3 * v67 + 2] = v72;
              }
            }
          }
        }
      }
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v61);
    }
    for ( i = 0;
          i < 6;
          ++i )
    {
      if ( (int)v77[3 * i] >= 1 )
      {
        CDecoObjMgr::AddDecoObj(&g_cDecoObjMgr, v77[3 * i + 1], v77[3 * i + 2], OBJECT_PEG01, 0, 1);
      }
    }
    v37 = IEntity::ID(a2);
    v9 = IEntity::WorldIdx(a2);
    CWorldManager::SetObjectId(v9, v37);
    v10 = IEntity::WorldIdx(a2);
    v11 = CWorldManager::X(v10);
    v64 = (char)this->m_pBuildingInfo->m_iFlagX + v11;
    v12 = IEntity::WorldIdx(a2);
    v13 = CWorldManager::Y(v12);
    v65 = (char)this->m_pBuildingInfo->m_iFlagY + v13;
    if ( this->m_uBoards )
    {
      v14 = CPileMgr::AddPile(&g_cPileMgr, v64 + 1, v65, 7, 0, 5, 0, 0, 0, 0);
      this->m_uBoardsPileId = v14;
      v38 = IEntity::ID(a2);
      v15 = CPileMgr::operator[](this->m_uBoardsPileId);
      CPile::SetBuildingId(v15, v38);
    }
    if ( this->m_uStone )
    {
      v16 = CPileMgr::AddPile(&g_cPileMgr, v64 - 1, v65, 32, 0, 5, 0, 0, 0, 0);
      this->m_uStonePileId = v16;
      v39 = IEntity::ID(a2);
      v17 = CPileMgr::operator[](this->m_uStonePileId);
      CPile::SetBuildingId(v17, v39);
    }
    if ( this->m_uGold )
    {
      v18 = CPileMgr::AddPile(&g_cPileMgr, v64, v65, 14, 0, 5, 0, 0, 0, 0);
      this->m_uGoldPileId = v18;
      v40 = IEntity::ID(a2);
      v19 = CPileMgr::operator[](this->m_uGoldPileId);
      CPile::SetBuildingId(v19, v40);
    }
    v20 = IEntity::Type(a2);
    if ( CBuildingMgr::IsMine(v20) )
    {
      this->m_uBuildStage = 4;
    }
    else
    {
      this->m_uBuildStage = 2;
    }
    if ( this->m_pBuildingInfo->m_bIsPort )
    {
      p_m_vWaterRepealingPosLines = &this->m_pBuildingInfo->m_vWaterRepealingPosLines;
      v34 = this->m_pBuildingInfo->m_iHotSpotY;
      v31 = this->m_pBuildingInfo->m_iHotSpotX;
      v28 = IEntity::Y(a2);
      v21 = IEntity::X(a2);
      CBuildingFlagsWalk::CBuildingFlagsWalk(&v50, v21, v28, v31, v34, p_m_vWaterRepealingPosLines);
      while ( CBuildingFlagsWalk::NextPosition(&v50) )
      {
        v42 = CBuildingFlagsWalk::CurrentY(&v50);
        v22 = CBuildingFlagsWalk::CurrentX(&v50);
        v63 = CWorldManager::Index(v22, v42);
        CWorldManager::SetObjectId(v63, 0);
        CWorldManager::SetFlagBits(v63, 8u);
      }
      p_m_vWaterFreePosLines = &this->m_pBuildingInfo->m_vWaterFreePosLines;
      v35 = this->m_pBuildingInfo->m_iHotSpotY;
      v32 = this->m_pBuildingInfo->m_iHotSpotX;
      v29 = IEntity::Y(a2);
      v23 = IEntity::X(a2);
      CBuildingFlagsWalk::CBuildingFlagsWalk(&v49, v23, v29, v32, v35, p_m_vWaterFreePosLines);
      while ( CBuildingFlagsWalk::NextPosition(&v49) )
      {
        v44 = CBuildingFlagsWalk::CurrentY(&v49);
        v24 = CBuildingFlagsWalk::CurrentX(&v49);
        v53 = CWorldManager::Index(v24, v44);
        CWorldManager::SetFlagBits(v53, 8u);
      }
    }
    v78 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v61);
  }
}


// address=[0x15063d0]
// Decompiled from void __thiscall CBuildingSiteRole::ConvertEventIntoGoal(CBuildingSiteRole *this, struct CBuilding *a2, struct CEntityEvent *a3)
void  CBuildingSiteRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
  ;
}


// address=[0x1506430]
// Decompiled from int __thiscall CBuildingSiteRole::GetEcoSectorId(CBuildingSiteRole *this, struct CBuilding *a2)
int  CBuildingSiteRole::GetEcoSectorId(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax

  if ( !a2 )
  {
    return 0;
  }
  v2 = CBuilding::EnsignPackedXY(a2);
  v3 = CWorldManager::Index(v2);
  return ITiling::EcoSectorId(v3);
}


// address=[0x1506490]
// Decompiled from int __thiscall CBuildingSiteRole::NeedBoards(CBuildingSiteRole *this)
int  CBuildingSiteRole::NeedBoards(void)const {
  
  CPile *v1; // eax
  int m_uProvidedBoards; // esi

  if ( !this->m_uBoards )
  {
    return 0;
  }
  v1 = CPileMgr::operator[](this->m_uBoardsPileId);
  m_uProvidedBoards = this->m_uProvidedBoards;
  return this->m_uBoards - v1->Amount(v1) - m_uProvidedBoards;
}


// address=[0x1506510]
// Decompiled from int __thiscall CBuildingSiteRole::NeedGold(CBuildingSiteRole *this)
int  CBuildingSiteRole::NeedGold(void)const {
  
  CPile *v1; // eax
  int m_uProvidedGold; // esi

  if ( !this->m_uGold )
  {
    return 0;
  }
  v1 = CPileMgr::operator[](this->m_uGoldPileId);
  m_uProvidedGold = this->m_uProvidedGold;
  return this->m_uGold - v1->Amount(v1) - m_uProvidedGold;
}


// address=[0x1506590]
// Decompiled from int __thiscall CBuildingSiteRole::NeedStone(CBuildingSiteRole *this)
int  CBuildingSiteRole::NeedStone(void)const {
  
  CPile *v1; // eax
  int m_uiProvidedStone; // esi

  if ( !this->m_uStone )
  {
    return 0;
  }
  v1 = CPileMgr::operator[](this->m_uStonePileId);
  m_uiProvidedStone = this->m_uProvidedStone;
  return this->m_uStone - v1->Amount(v1) - m_uiProvidedStone;
}


// address=[0x15067d0]
// Decompiled from char __thiscall CBuildingSiteRole::TryCrushBuilding(CBuildingSiteRole *this)
bool  CBuildingSiteRole::TryCrushBuilding(void) {
  
  return 1;
}


