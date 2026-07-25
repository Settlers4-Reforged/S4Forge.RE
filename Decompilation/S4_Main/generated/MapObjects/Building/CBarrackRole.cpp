#include "CBarrackRole.h"

// Definitions for class CBarrackRole

// address=[0x13ffb40]
// Decompiled from CBarrackRole *__cdecl CBarrackRole::New(int a1)
class CPersistence * __cdecl CBarrackRole::New(std::istream & a1) {
  
  CBarrackRole *C; // [esp+Ch] [ebp-10h]

  C = (CBarrackRole *)operator new(0x190u);
  if ( C )
    return CBarrackRole::CBarrackRole(C, a1);
  else
    return 0;
}


// address=[0x14e6900]
// Decompiled from CBarrackRole *__thiscall CBarrackRole::CBarrackRole(CBarrackRole *this)
 CBarrackRole::CBarrackRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  this->__vftable = (IBuildingRole_vtbl *)&CBarrackRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(&this->m_vDeliverPiles);
  this->m_uU0 = 2;
  return this;
}


// address=[0x14e6940]
// Decompiled from void __thiscall CBarrackRole::LogicUpdate(CBarrackRole *this, CBuilding *a2)
void  CBarrackRole::LogicUpdate(class CBuilding * a2) {
  
  int v2; // eax
  CPile *v3; // eax
  CPile *v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // eax
  CPile *v8; // eax
  CPile *v9; // eax
  int v10; // eax
  int v11; // eax
  char v12; // al
  int v13; // [esp-8h] [ebp-C4h]
  int v14; // [esp-4h] [ebp-C0h]
  int v15; // [esp-4h] [ebp-C0h]
  CEntityEvent v16; // [esp+8h] [ebp-B4h] BYREF
  CEntityEvent *v17; // [esp+20h] [ebp-9Ch]
  CEntityEvent *v18; // [esp+24h] [ebp-98h]
  void *v19; // [esp+28h] [ebp-94h]
  int v20; // [esp+2Ch] [ebp-90h]
  int v21; // [esp+30h] [ebp-8Ch]
  void *v22; // [esp+34h] [ebp-88h]
  void *v23; // [esp+38h] [ebp-84h]
  int iOrder; // [esp+3Ch] [ebp-80h]
  int v25; // [esp+40h] [ebp-7Ch]
  void *v26; // [esp+44h] [ebp-78h]
  CSettler *v27; // [esp+48h] [ebp-74h]
  void *v28; // [esp+4Ch] [ebp-70h]
  CPile *v29; // [esp+50h] [ebp-6Ch]
  int iSoldierOrder; // [esp+54h] [ebp-68h]
  int iRace; // [esp+58h] [ebp-64h]
  int iToSlot; // [esp+5Ch] [ebp-60h]
  int v33; // [esp+60h] [ebp-5Ch]
  int v34; // [esp+64h] [ebp-58h]
  int v35; // [esp+68h] [ebp-54h]
  CSettler *v36; // [esp+6Ch] [ebp-50h]
  int iHighestPrioClass; // [esp+70h] [ebp-4Ch]
  int iSettlerType; // [esp+74h] [ebp-48h]
  int iPrioClass; // [esp+78h] [ebp-44h]
  int iHighestPrioLevel; // [esp+7Ch] [ebp-40h]
  int iPrioLevel; // [esp+80h] [ebp-3Ch]
  int iBestSlot; // [esp+84h] [ebp-38h]
  int iBestIndex; // [esp+88h] [ebp-34h]
  int iBestType; // [esp+8Ch] [ebp-30h]
  SRecruiteNeedDesc *v45; // [esp+90h] [ebp-2Ch]
  int i; // [esp+94h] [ebp-28h]
  CEcoSector *v47; // [esp+98h] [ebp-24h]
  int j; // [esp+9Ch] [ebp-20h]
  int NearestSettler; // [esp+A0h] [ebp-1Ch]
  SRecruiteNeedDesc *rInfo; // [esp+A4h] [ebp-18h]
  char v51; // [esp+ABh] [ebp-11h]
  int v53; // [esp+B8h] [ebp-4h]

  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) )
    this->FillDialog((CFarmBuildingRole *)this, a2, 1);
  if ( IEntity::FlagBits(a2, (EntityFlag)4096) )
  {
    iRace = IEntity::Race(a2);
    v2 = CBuilding::EnsignWorldIdx(a2);
    v25 = CWorldManager::EcoSectorId(v2);
    v26 = this->GetPileIdWithGood(this, 14);
    v29 = CPileMgr::operator[]((int)v26);
    v47 = CEcoSectorMgr::operator[](g_cESMgr, v25);
    v21 = CPile::NumberOfAvailableGoods(v29);
    v20 = this->m_uU0 % 3 + 3;
    iBestIndex = -1;
    iBestSlot = -1;
    iBestType = 0;
    iHighestPrioLevel = -1;
    iHighestPrioClass = -1;
    v33 = -1;
    v51 = 1;
    for ( i = 9; i >= 0; --i )
    {
      rInfo = &sRecruiteNeedDesc[iRace][i];
      if ( rInfo->m_iWeaponType <= 0
        && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 931, "rInfo.iWeaponType > 0") == 1 )
      {
        __debugbreak();
      }
      for ( j = 0; g_vSoldierProductionMap[j].m_iFrom && g_vSoldierProductionMap[j].m_iFrom != rInfo->m_iSettlerType; ++j )
        ;
      if ( g_vSoldierProductionMap[j].m_iFrom >= 0 )
      {
        iToSlot = g_vSoldierProductionMap[j].m_iTo;
        iOrder = CEcoSector::GetNrOfSoldierOrder(v47, iToSlot);
        if ( iOrder > 0 )
        {
          v51 = 0;
          v23 = this->GetPileIdWithGood(this, rInfo->m_iWeaponType);
          v22 = this->GetPileIdWithGood(this, rInfo->m_iGold);
          if ( rInfo->m_iWeaponType )
          {
            v3 = CPileMgr::operator[]((int)v23);
            if ( CPile::NumberOfAvailableGoods(v3) > 0 )
            {
              if ( !rInfo->m_iGold || (v4 = CPileMgr::operator[]((int)v22), CPile::NumberOfAvailableGoods(v4) > 0) )
              {
                if ( !rInfo->iWeaponAmount || v21 >= rInfo->iWeaponAmount )
                {
                  iSettlerType = rInfo->m_iSettlerType;
                  iPrioLevel = SettlerTypePrioLevel(iSettlerType);
                  iPrioClass = SettlerTypePrioClass(iSettlerType);
                  if ( iPrioClass < 0 )
                    v35 = -1;
                  else
                    v35 = (v20 - iPrioClass) % 3;
                  v34 = v35;
                  if ( iPrioLevel > iHighestPrioLevel || iPrioLevel == iHighestPrioLevel && v34 > v33 )
                  {
                    iHighestPrioLevel = iPrioLevel;
                    iHighestPrioClass = iPrioClass;
                    v33 = v34;
                    iBestIndex = i;
                    iBestType = iSettlerType;
                    iBestSlot = iToSlot;
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( v51 )
    {
      if ( iBestIndex != -1
        && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1000, "iBestIndex == -1") == 1 )
      {
        __debugbreak();
      }
      this->m_uU0 = 2;
    }
    if ( iBestIndex >= 0 )
    {
      if ( iBestSlot < 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1007, "iBestSlot >= 0") == 1 )
        __debugbreak();
      if ( iBestType <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1008, "iBestType > 0") == 1 )
        __debugbreak();
      v45 = &sRecruiteNeedDesc[iRace][iBestIndex];
      NearestSettler = 0;
      if ( CEcoSector::CarrierForJobOrderAvailable(v47, 1) )
      {
        v14 = IEntity::Y(a2);
        v5 = IEntity::X(a2);
        NearestSettler = CEcoSector::GetNearestSettler(v47, 1, v5, v14);
      }
      else
      {
        v6 = IEntity::OwnerId(a2);
        if ( v6 == CPlayerManager::GetLocalPlayerId() )
        {
          v15 = IEntity::Y(a2);
          v13 = IEntity::X(a2);
          v7 = IEntity::OwnerId(a2);
          CTextMsgHandler::AddWarningMsg(2459, v7, v13, v15);
        }
      }
      if ( NearestSettler > 0 )
      {
        if ( iHighestPrioClass >= 0 )
          this->m_uU0 = iHighestPrioClass;
        iSoldierOrder = CEcoSector::GetNrOfSoldierOrder(v47, iBestSlot);
        if ( iSoldierOrder <= 0
          && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1035, "iSoldierOrder > 0") == 1 )
        {
          __debugbreak();
        }
        if ( iSoldierOrder != 100 )
          CEcoSector::DecNrOfSoldierOrder(v47, iBestSlot);
        v36 = CSettlerMgr::operator[](NearestSettler);
        v28 = this->GetPileIdWithGood(this, v45->m_iWeaponType);
        v19 = this->GetPileIdWithGood(this, v45->m_iGold);
        v8 = CPileMgr::operator[]((int)v28);
        CPile::AttachAndIncAmountLeaving(v8, NearestSettler, 1, 2);
        if ( v45->iWeaponAmount <= 0 )
          CSettler::MarkSourcePile2AsUnused(v36);
        else
          CPile::AttachAndIncAmountLeaving(v29, NearestSettler, v45->iWeaponAmount, 3);
        if ( v45->m_iGold )
        {
          v9 = CPileMgr::operator[]((int)v19);
          CPile::AttachAndIncAmountLeaving(v9, NearestSettler, 1, 4);
        }
        else
        {
          CSettler::MarkSourcePile3AsUnused(v36);
        }
        v10 = IEntity::EntityId(a2);
        CSettler::AttachToBuilding(v36, v10);
        CEcoSector::GetCarrierOutOfOfferAndSetNextSettlerType(v47, NearestSettler, iBestType);
        v27 = CSettlerMgr::operator[](NearestSettler);
        v11 = IEntity::EntityId(a2);
        v18 = CEntityEvent::CEntityEvent(&v16, 0x1Au, 0, iBestType, (int)v28, v11);
        v17 = v18;
        v53 = 0;
        v27->SetEvent(v27, v18);
        v53 = -1;
        CEntityEvent::~CEntityEvent(&v16);
        CGameScriptManager::SendGameEvent(g_pScriptMgr, 0x12u, iBestType);
      }
    }
  }
  v12 = CGameData::Rand(g_pGameData);
  IAnimatedEntity::RegisterForLogicUpdate(a2, (v12 & 2) + 13);
}


// address=[0x14e6f50]
// Decompiled from void __thiscall CBarrackRole::FillGfxInfo(CBarrackRole *this, IEntity *a2, struct SGfxObjectInfo *a3)
void  CBarrackRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  unsigned int v3; // eax
  unsigned __int16 *v4; // eax
  CPile *v5; // eax
  unsigned __int16 *v6; // eax
  CPile *v7; // eax
  unsigned int v8; // [esp-Ch] [ebp-18h]
  int v9; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+4h] [ebp-8h]

  this->Update(this, a2);
  v8 = IEntity::Type(a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo(g_pGfxManager, a3, v3, v8, 1, (int)this->m_vPatchPairs);
  v9 = 0;
  for ( i = 0; i < std::vector<unsigned short>::size(&this->m_vDeliverPiles); ++i )
  {
    v4 = std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, i);
    v5 = CPileMgr::operator[](*v4);
    if ( CPile::IsPatchPile(v5) )
    {
      v6 = std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, i);
      v7 = CPileMgr::operator[](*v6);
      CPile::GetPatchGfx(v7, &a3->m_vPatches2[v9++]);
    }
  }
}


// address=[0x14e7040]
// Decompiled from void __thiscall CBarrackRole::Init(CBarrackRole *this, struct CBuilding *a2)
void  CBarrackRole::Init(class CBuilding * a2) {
  
  CPile *v2; // eax
  int v3; // [esp-4h] [ebp-4Ch]
  CEntityEvent v4; // [esp+4h] [ebp-44h] BYREF
  CEntityEvent *v5; // [esp+1Ch] [ebp-2Ch]
  int id; // [esp+20h] [ebp-28h]
  int v7; // [esp+24h] [ebp-24h]
  int v8; // [esp+28h] [ebp-20h]
  int iPileId; // [esp+2Ch] [ebp-1Ch]
  int i; // [esp+30h] [ebp-18h]
  __int16 v12; // [esp+3Ah] [ebp-Eh] BYREF
  int v13; // [esp+44h] [ebp-4h]

  IBuildingRole::InitCommon(a2);
  this->m_uU0 = 2;
  for ( i = 0; i < this->m_pBuildingInfo->m_iPileNumber; ++i )
  {
    v7 = this->m_pBuildingInfo->m_vPileSpots[i].m_uXOffset + IEntity::X(a2);
    v8 = this->m_pBuildingInfo->m_vPileSpots[i].m_uYOffset + IEntity::Y(a2);
    iPileId = CPileMgr::AddPile(
                &g_cPileMgr,
                v7,
                v8,
                this->m_pBuildingInfo->m_vPileSpots[i].m_iGood,
                0,
                (char)this->m_pBuildingInfo->m_vPileSpots[i].m_iType,
                0,
                0,
                0,
                0);
    v3 = IEntity::ID(a2);
    v2 = CPileMgr::operator[](iPileId);
    CPile::SetBuildingId(v2, v3);
    id = CWorldManager::PileId(v7, v8);
    if ( id != iPileId && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 765, "id == iPileId") == 1 )
      __debugbreak();
    if ( !iPileId && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 771, "iPileId != 0") == 1 )
      __debugbreak();
    if ( this->m_pBuildingInfo->m_vPileSpots[i].m_iType != 1
      && BBSupportDbgReportF(2, "MapObjects\\Building\\BarrackRole.cpp", 777, "Wrong pile type at barrack") == 1 )
    {
      __debugbreak();
    }
    v12 = iPileId;
    std::vector<unsigned short>::push_back(&this->m_vDeliverPiles, &v12);
  }
  if ( !std::vector<unsigned short>::size(&this->m_vDeliverPiles)
    && BBSupportDbgReportF(2, "MapObjects\\Building\\BarrackRole.cpp", 783, "No deliver pile at barrack") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) )
    this->FillDialog(this, a2, 0);
  if ( IEntity::FlagBits(a2, (EntityFlag)4096) )
  {
    CEntityEvent::CEntityEvent(&v4, 8u, 0, this->m_iEntityId, 0, 0);
    v13 = 0;
    v5 = &v4;
    a2->Notify(&v4);
    v13 = -1;
    CEntityEvent::~CEntityEvent(&v4);
  }
  IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
}


// address=[0x14e72e0]
// Decompiled from void __thiscall CBarrackRole::PostLoadInit(CBarrackRole *this, IEntity *a2)
void  CBarrackRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = IEntity::Type(a2);
  v2 = IEntity::Race(a2);
  this->m_pBuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v2, v3);
}


// address=[0x14e7310]
// Decompiled from char __thiscall CBarrackRole::SettlerEnter(CBarrackRole *this, struct CBuilding *a2, int a3)
bool  CBarrackRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  return 1;
}


// address=[0x14e7320]
// Decompiled from int __thiscall CBarrackRole::GetBuildingNeed(CBarrackRole *this, int _iGood)
int  CBarrackRole::GetBuildingNeed(int _iGood)const {
  
  unsigned __int16 *v2; // eax
  CPile *v4; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size(&this->m_vDeliverPiles); ++i )
  {
    v2 = std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, i);
    v4 = CPileMgr::operator[](*v2);
    if ( v4->GetGoodType() == _iGood )
      return *std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, i);
  }
  BBSupportTracePrintF(0, "TROUBLE: illegal goodcheck good %u", _iGood);
  return 0;
}


// address=[0x14e73c0]
// Decompiled from int __thiscall CBarrackRole::GetPileIdWithGood(CBarrackRole *this, int _iGood)
int  CBarrackRole::GetPileIdWithGood(int _iGood)const {
  
  unsigned __int16 *v2; // eax
  CPile *v4; // [esp+0h] [ebp-Ch]
  unsigned int a1; // [esp+8h] [ebp-4h]

  for ( a1 = 0; a1 < std::vector<unsigned short>::size(&this->m_vDeliverPiles); ++a1 )
  {
    v2 = std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, a1);
    v4 = CPileMgr::operator[](*v2);
    if ( _iGood == v4->GetGoodType() )
      return *std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, a1);
  }
  return 0;
}


// address=[0x14e7450]
// Decompiled from void __thiscall CBarrackRole::InhabitantFlee(CBarrackRole *this, int a2)
void  CBarrackRole::InhabitantFlee(int a2) {
  
  ;
}


// address=[0x14e7460]
// Decompiled from _DWORD *__thiscall CBarrackRole::FillAddSoldierSideBar(CBarrackRole *this, struct CAddSoldierSideBarInfo *a2, bool a3)
void  CBarrackRole::FillAddSoldierSideBar(class CAddSoldierSideBarInfo * a2, bool a3) {
  
  CBuilding *v3; // eax
  int v4; // eax
  CBuilding *v5; // eax
  int v6; // eax
  CEcoSector *v7; // eax
  int v8; // esi
  CEcoSector *v9; // eax
  int v11; // [esp+1Ch] [ebp-48h]
  unsigned int v12; // [esp+20h] [ebp-44h]
  int v13; // [esp+24h] [ebp-40h]
  signed int v15; // [esp+2Ch] [ebp-38h]
  CEcoSector *pEcoSector; // [esp+30h] [ebp-34h]
  int soldierType; // [esp+34h] [ebp-30h]
  int i; // [esp+38h] [ebp-2Ch]
  int j; // [esp+38h] [ebp-2Ch]
  int k; // [esp+38h] [ebp-2Ch]
  CEvn_Event v21; // [esp+3Ch] [ebp-28h] BYREF
  int v22; // [esp+60h] [ebp-4h]

  a2->m_iUnknown = 16;
  v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  v4 = CBuilding::EnsignWorldIdx(v3);
  v11 = CWorldManager::EcoSectorId(v4);
  pEcoSector = CEcoSectorMgr::operator[](g_cESMgr, v11);
  soldierType = 0;
  for ( i = 0; i < 3; ++i )
    a2->m_cLvl1SoldierCount[i] = CEcoSector::GetNrOfSoldierOrder(pEcoSector, soldierType++);
  for ( j = 0; j < 3; ++j )
    a2->m_cLvl2SoldierCount[j] = CEcoSector::GetNrOfSoldierOrder(pEcoSector, soldierType++);
  for ( k = 0; k < 3; ++k )
    a2->m_cLvl3SoldierCount[k] = CEcoSector::GetNrOfSoldierOrder(pEcoSector, soldierType++);
  a2->m_cSpecialSoldierCount = CEcoSector::GetNrOfSoldierOrder(pEcoSector, soldierType);
  v5 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iEntityId);
  v6 = CBuilding::EnsignWorldIdx(v5);
  v13 = CWorldManager::EcoSectorId(v6);
  v7 = CEcoSectorMgr::operator[](g_cESMgr, v13);
  v8 = CEcoSector::NrOfSettler(v7, SETTLER_CARRIER);
  v9 = CEcoSectorMgr::operator[](g_cESMgr, v13);
  v15 = v8 - CEcoSector::MinCarrier(v9);
  if ( v15 <= 0 )
    v15 = 0;
  a2->m_uMinCarrier = v15;
  v12 = 606;
  if ( !a3 )
    v12 = 607;
  CEvn_Event::CEvn_Event(&v21, v12, 0, (unsigned int)a2, 0);
  v22 = 0;
  if ( !g_pEvnEngine
    && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1217, "g_pEvnEngine != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v21);
  v22 = -1;
  return CEvn_Event::~CEvn_Event(&v21);
}


// address=[0x14e76c0]
// Decompiled from CBarrackRole *__thiscall CBarrackRole::CBarrackRole(CBarrackRole *this, struct std::istream *a2)
 CBarrackRole::CBarrackRole(std::istream & a2) {
  
  unsigned int v3; // [esp+8h] [ebp-24h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  int i; // [esp+10h] [ebp-1Ch]
  unsigned __int16 v7[3]; // [esp+18h] [ebp-14h] BYREF
  unsigned __int8 v8; // [esp+1Fh] [ebp-Dh] BYREF
  int v9; // [esp+28h] [ebp-4h]

  IBuildingRole::IBuildingRole(this, a2);
  v9 = 0;
  this->__vftable = (IBuildingRole_vtbl *)&CBarrackRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(&this->m_vDeliverPiles);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 3 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBarrackRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, &this->m_uU0);
  v8 = 0;
  operator^<unsigned char>(a2, &v8);
  for ( i = 0; i < v8; ++i )
  {
    v7[0] = 0;
    operator^<unsigned short>(a2, v7);
    std::vector<unsigned short>::push_back(&this->m_vDeliverPiles, (__int16 *)v7);
  }
  v9 = -1;
  return this;
}


// address=[0x14e77f0]
// Decompiled from void __thiscall CBarrackRole::Store(CBarrackRole *this, struct std::ostream *a1)
void  CBarrackRole::Store(std::ostream & a1) {
  
  unsigned __int16 *v2; // eax
  unsigned int v3; // [esp+0h] [ebp-10h] BYREF
  unsigned int i; // [esp+8h] [ebp-8h]
  unsigned __int8 uSize; // [esp+Fh] [ebp-1h] BYREF

  IBuildingRole::Store(this, a1);
  v3 = 3;
  operator^<unsigned int>(a1, &v3);
  operator^<unsigned char>(a1, &this->m_uU0);
  uSize = std::vector<unsigned short>::size(&this->m_vDeliverPiles);
  operator^<unsigned char>(a1, &uSize);
  for ( i = 0; (int)i < uSize; ++i )
  {
    v2 = std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, i);
    operator^<unsigned short>(a1, v2);
  }
}


// address=[0x14e8030]
// Decompiled from int __thiscall CBarrackRole::~CBarrackRole(CBarrackRole *this)
 CBarrackRole::~CBarrackRole(void) {
  
  std::vector<unsigned short>::~vector<unsigned short>(&this->m_vDeliverPiles);
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14e80a0]
// Decompiled from int __thiscall CBarrackRole::ClassID(CBarrackRole *this)
unsigned long  CBarrackRole::ClassID(void)const {
  
  return CBarrackRole::m_iClassID;
}


// address=[0x14e8120]
// Decompiled from int __thiscall CBarrackRole::GetBuildingRole(CBarrackRole *this)
int  CBarrackRole::GetBuildingRole(void) {
  
  return 11;
}


// address=[0x14e8140]
// Decompiled from void __thiscall CBarrackRole::GoodArrive(CBarrackRole *this, int a2)
void  CBarrackRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x14fd830]
// Decompiled from int __cdecl CBarrackRole::Load(struct std::istream *a1)
class CBarrackRole * __cdecl CBarrackRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CBarrackRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8af58]
// [Decompilation failed for static unsigned long CBarrackRole::m_iClassID]

// address=[0x14e78a0]
// Decompiled from _DWORD *__thiscall CBarrackRole::FillDialog(CBarrackRole *this, CBuilding *a2, bool a3)
void  CBarrackRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  S4_BUILDING_ENUM v8; // [esp-8h] [ebp-4Ch]
  S4_BUILDING_ENUM v9; // [esp-8h] [ebp-4Ch]
  unsigned int v10; // [esp+4h] [ebp-40h]
  CPile *v11; // [esp+8h] [ebp-3Ch]
  CPile *v12; // [esp+Ch] [ebp-38h]
  unsigned int i; // [esp+18h] [ebp-2Ch]
  CEvn_Event v15; // [esp+1Ch] [ebp-28h] BYREF
  int v16; // [esp+40h] [ebp-4h]

  g_cBarracksInfo.m_iUnknown = 7;
  g_cBarracksInfo.m_cRace = IEntity::Race(a2);
  g_cBarracksInfo.m_cType = IEntity::Type(a2);
  g_cBarracksInfo.m_unknownB = 1;
  g_cBarracksInfo.m_bSomeFlagBits = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
  g_cBarracksInfo.m_bHasWorkingArea = 0;
  v8 = IEntity::Type(a2);
  v3 = IEntity::OwnerId(a2);
  g_cBarracksInfo.m_cTotalCount = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v8, 0);
  v9 = IEntity::Type(a2);
  v4 = IEntity::OwnerId(a2);
  g_cBarracksInfo.m_cTotalBuiltCount = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v9, 1u);
  g_cBarracksInfo.m_bInhabitants = this->m_bInhabitants;
  if ( this->m_bInhabitants )
    g_cBarracksInfo.m_iSettlerCount = this->m_pBuildingInfo->m_iBuildingInhabitant;
  for ( i = 0; i < std::vector<unsigned short>::size(&this->m_vDeliverPiles); ++i )
  {
    v5 = std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, i);
    v12 = CPileMgr::operator[](*v5);
    g_cBarracksInfo.m_sPairs[i].m_cPileAmount = v12->Amount(v12);
    v6 = std::vector<unsigned short>::operator[](&this->m_vDeliverPiles, i);
    v11 = CPileMgr::operator[](*v6);
    g_cBarracksInfo.m_sPairs[i].m_mPileGoodType = v11->GetGoodType();
  }
  v10 = 604;
  if ( !a3 )
    v10 = 602;
  CEvn_Event::CEvn_Event(&v15, v10, 0, (unsigned int)&g_cBarracksInfo, 0);
  v16 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v15);
  v16 = -1;
  return CEvn_Event::~CEvn_Event(&v15);
}


// address=[0x14e80c0]
// Decompiled from void __thiscall CBarrackRole::ConvertEventIntoGoal(CBarrackRole *this, struct CBuilding *a2, struct CEntityEvent *a3)
void  CBarrackRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
  ;
}


// address=[0x14e80d0]
// Decompiled from char __thiscall CBarrackRole::CrushBuilding(CBarrackRole *this)
bool  CBarrackRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14e81f0]
// Decompiled from char __thiscall CBarrackRole::TryCrushBuilding(CBarrackRole *this)
bool  CBarrackRole::TryCrushBuilding(void) {
  
  return 1;
}


