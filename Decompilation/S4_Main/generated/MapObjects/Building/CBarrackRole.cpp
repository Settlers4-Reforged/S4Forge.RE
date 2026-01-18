#include "CBarrackRole.h"

// Definitions for class CBarrackRole

// address=[0x13ffb40]
// Decompiled from int __cdecl CBarrackRole::New(int a1)
class CPersistence * __cdecl CBarrackRole::New(std::istream & a1) {
  
  if ( operator new(0x190u) )
    return CBarrackRole::CBarrackRole(a1);
  else
    return 0;
}


// address=[0x14e6900]
// Decompiled from CBarrackRole *__thiscall CBarrackRole::CBarrackRole(CBarrackRole *this)
 CBarrackRole::CBarrackRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CBarrackRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 384);
  *((_BYTE *)this + 380) = 2;
  return this;
}


// address=[0x14e6940]
// Decompiled from int __thiscall CBarrackRole::LogicUpdate(CBarrackRole *this, struct CBuilding *a2)
void  CBarrackRole::LogicUpdate(class CBuilding * a2) {
  
  int v2; // eax
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned __int8 v12; // al
  int v14; // [esp-8h] [ebp-C4h]
  int v15; // [esp-4h] [ebp-C0h]
  int v16; // [esp-4h] [ebp-C0h]
  _BYTE v17[24]; // [esp+8h] [ebp-B4h] BYREF
  CEntityEvent *v18; // [esp+20h] [ebp-9Ch]
  CEntityEvent *v19; // [esp+24h] [ebp-98h]
  int v20; // [esp+28h] [ebp-94h]
  int v21; // [esp+2Ch] [ebp-90h]
  int v22; // [esp+30h] [ebp-8Ch]
  int v23; // [esp+34h] [ebp-88h]
  int v24; // [esp+38h] [ebp-84h]
  int NrOfSoldierOrder; // [esp+3Ch] [ebp-80h]
  int v26; // [esp+40h] [ebp-7Ch]
  int v27; // [esp+44h] [ebp-78h]
  int v28; // [esp+48h] [ebp-74h]
  int v29; // [esp+4Ch] [ebp-70h]
  unsigned __int8 *v30; // [esp+50h] [ebp-6Ch]
  int v31; // [esp+54h] [ebp-68h]
  int v32; // [esp+58h] [ebp-64h]
  int v33; // [esp+5Ch] [ebp-60h]
  int v34; // [esp+60h] [ebp-5Ch]
  int v35; // [esp+64h] [ebp-58h]
  int v36; // [esp+68h] [ebp-54h]
  CSettler *v37; // [esp+6Ch] [ebp-50h]
  int v38; // [esp+70h] [ebp-4Ch]
  int v39; // [esp+74h] [ebp-48h]
  int v40; // [esp+78h] [ebp-44h]
  int v41; // [esp+7Ch] [ebp-40h]
  int v42; // [esp+80h] [ebp-3Ch]
  int v43; // [esp+84h] [ebp-38h]
  int v44; // [esp+88h] [ebp-34h]
  int v45; // [esp+8Ch] [ebp-30h]
  _DWORD *v46; // [esp+90h] [ebp-2Ch]
  int i; // [esp+94h] [ebp-28h]
  CEcoSector *v48; // [esp+98h] [ebp-24h]
  int j; // [esp+9Ch] [ebp-20h]
  int NearestSettler; // [esp+A0h] [ebp-1Ch]
  int *v51; // [esp+A4h] [ebp-18h]
  char v52; // [esp+ABh] [ebp-11h]
  unsigned __int8 *v53; // [esp+ACh] [ebp-10h]
  int v54; // [esp+B8h] [ebp-4h]

  v53 = (unsigned __int8 *)this;
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(unsigned __int8 *, struct CBuilding *, int))(*(_DWORD *)v53 + 88))(v53, a2, 1);
  if ( IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
  {
    v32 = IEntity::Race(a2);
    v2 = CBuilding::EnsignWorldIdx(a2);
    v26 = CWorldManager::EcoSectorId(v2);
    v27 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v53 + 56))(v53, 14);
    v30 = CPileMgr::operator[](v27);
    v48 = (CEcoSector *)CEcoSectorMgr::operator[](v26);
    v22 = CPile::NumberOfAvailableGoods((CPile *)v30);
    v21 = v53[380] % 3 + 3;
    v44 = -1;
    v43 = -1;
    v45 = 0;
    v41 = -1;
    v38 = -1;
    v34 = -1;
    v52 = 1;
    for ( i = 9; i >= 0; --i )
    {
      v51 = (int *)((char *)&sRecruiteNeedDesc + 240 * v32 + 24 * i);
      if ( v51[1] <= 0
        && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 931, "rInfo.iWeaponType > 0") == 1 )
      {
        __debugbreak();
      }
      for ( j = 0; g_vSoldierProductionMap[2 * j] && g_vSoldierProductionMap[2 * j] != *v51; ++j )
        ;
      if ( g_vSoldierProductionMap[2 * j] >= 0 )
      {
        v33 = dword_3D8AE1C[2 * j];
        NrOfSoldierOrder = CEcoSector::GetNrOfSoldierOrder(v48, v33);
        if ( NrOfSoldierOrder > 0 )
        {
          v52 = 0;
          v24 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v53 + 56))(v53, v51[1]);
          v23 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v53 + 56))(v53, v51[2]);
          if ( v51[1] )
          {
            v3 = CPileMgr::operator[](v24);
            if ( CPile::NumberOfAvailableGoods((CPile *)v3) > 0 )
            {
              if ( !v51[2] || (v4 = CPileMgr::operator[](v23), CPile::NumberOfAvailableGoods((CPile *)v4) > 0) )
              {
                if ( !v51[3] || v22 >= v51[3] )
                {
                  v39 = *v51;
                  v42 = SettlerTypePrioLevel(v39);
                  v40 = SettlerTypePrioClass(v39);
                  if ( v40 < 0 )
                    v36 = -1;
                  else
                    v36 = (v21 - v40) % 3;
                  v35 = v36;
                  if ( v42 > v41 || v42 == v41 && v35 > v34 )
                  {
                    v41 = v42;
                    v38 = v40;
                    v34 = v35;
                    v44 = i;
                    v45 = v39;
                    v43 = v33;
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( v52 )
    {
      if ( v44 != -1 && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1000, "iBestIndex == -1") == 1 )
        __debugbreak();
      v53[380] = 2;
    }
    if ( v44 >= 0 )
    {
      if ( v43 < 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1007, "iBestSlot >= 0") == 1 )
        __debugbreak();
      if ( v45 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1008, "iBestType > 0") == 1 )
        __debugbreak();
      v46 = (_DWORD *)((char *)&sRecruiteNeedDesc + 240 * v32 + 24 * v44);
      NearestSettler = 0;
      if ( CEcoSector::CarrierForJobOrderAvailable(v48, 1) )
      {
        v15 = IEntity::Y(a2);
        v5 = IEntity::X(a2);
        NearestSettler = CEcoSector::GetNearestSettler(v48, 1, v5, v15);
      }
      else
      {
        v6 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( v6 == CPlayerManager::GetLocalPlayerId() )
        {
          v16 = IEntity::Y(a2);
          v14 = IEntity::X(a2);
          v7 = IEntity::OwnerId((unsigned __int8 *)a2);
          CTextMsgHandler::AddWarningMsg(2459, v7, v14, v16);
        }
      }
      if ( NearestSettler > 0 )
      {
        if ( v38 >= 0 )
          v53[380] = v38;
        v31 = CEcoSector::GetNrOfSoldierOrder(v48, v43);
        if ( v31 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 1035, "iSoldierOrder > 0") == 1 )
          __debugbreak();
        if ( v31 != 100 )
          CEcoSector::DecNrOfSoldierOrder(v48, v43);
        v37 = (CSettler *)CSettlerMgr::operator[](NearestSettler);
        v29 = (*(int (__thiscall **)(unsigned __int8 *, _DWORD))(*(_DWORD *)v53 + 56))(v53, v46[1]);
        v20 = (*(int (__thiscall **)(unsigned __int8 *, _DWORD))(*(_DWORD *)v53 + 56))(v53, v46[2]);
        v8 = CPileMgr::operator[](v29);
        CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v8, NearestSettler, 1, 2);
        if ( (int)v46[3] <= 0 )
          CSettler::MarkSourcePile2AsUnused(v37);
        else
          CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v30, NearestSettler, v46[3], 3);
        if ( v46[2] )
        {
          v9 = CPileMgr::operator[](v20);
          CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v9, NearestSettler, 1, 4);
        }
        else
        {
          CSettler::MarkSourcePile3AsUnused(v37);
        }
        v10 = IEntity::EntityId((unsigned __int16 *)a2);
        CSettler::AttachToBuilding(v37, v10);
        CEcoSector::GetCarrierOutOfOfferAndSetNextSettlerType(v48, NearestSettler, v45);
        v28 = CSettlerMgr::operator[](NearestSettler);
        v11 = IEntity::EntityId((unsigned __int16 *)a2);
        v19 = CEntityEvent::CEntityEvent((CEntityEvent *)v17, 0x1Au, 0, v45, v29, v11);
        v18 = v19;
        v54 = 0;
        (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v28 + 80))(v28, v19);
        v54 = -1;
        CEntityEvent::~CEntityEvent(v17);
        CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 18, v45);
      }
    }
  }
  v12 = (unsigned __int8)CGameData::Rand(g_pGameData);
  return IAnimatedEntity::RegisterForLogicUpdate((v12 & 2) + 13);
}


// address=[0x14e6f50]
// Decompiled from unsigned int __thiscall CBarrackRole::FillGfxInfo(CBarrackRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CBarrackRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  unsigned int result; // eax
  unsigned __int16 *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int16 *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // [esp-Ch] [ebp-18h]
  int v10; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+4h] [ebp-8h]

  (*(void (__thiscall **)(CBarrackRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v9, 1, (int)this + 76);
  v10 = 0;
  for ( i = 0; ; ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 384);
    if ( i >= result )
      break;
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v6 = CPileMgr::operator[](*v5);
    if ( (unsigned __int8)CPile::IsPatchPile(v6) )
    {
      v7 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, i);
      v8 = CPileMgr::operator[](*v7);
      CPile::GetPatchGfx((CPile *)v8, (struct SGfxObjectInfo *)((char *)a3 + 16 * v10++ + 536));
    }
  }
  return result;
}


// address=[0x14e7040]
// Decompiled from int __thiscall CBarrackRole::Init(CBarrackRole *this, struct CBuilding *a2)
void  CBarrackRole::Init(class CBuilding * a2) {
  
  unsigned __int8 *v2; // eax
  int v4; // [esp-4h] [ebp-4Ch]
  _BYTE v5[24]; // [esp+4h] [ebp-44h] BYREF
  _BYTE *v6; // [esp+1Ch] [ebp-2Ch]
  int v7; // [esp+20h] [ebp-28h]
  int v8; // [esp+24h] [ebp-24h]
  int v9; // [esp+28h] [ebp-20h]
  int v10; // [esp+2Ch] [ebp-1Ch]
  int i; // [esp+30h] [ebp-18h]
  CBarrackRole *v12; // [esp+34h] [ebp-14h]
  __int16 v13; // [esp+3Ah] [ebp-Eh] BYREF
  int v14; // [esp+44h] [ebp-4h]

  v12 = this;
  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)v12 + 380) = 2;
  for ( i = 0; i < *(char *)(*((_DWORD *)v12 + 94) + 57); ++i )
  {
    v8 = *(char *)(*((_DWORD *)v12 + 94) + 16 * i + 60) + IEntity::X(a2);
    v9 = *(char *)(*((_DWORD *)v12 + 94) + 16 * i + 61) + IEntity::Y(a2);
    v10 = CPileMgr::AddPile(
            (CPileMgr *)&g_cPileMgr,
            v8,
            v9,
            *(char *)(*((_DWORD *)v12 + 94) + 16 * i + 62),
            0,
            *(char *)(*((_DWORD *)v12 + 94) + 16 * i + 63),
            0,
            0,
            0,
            0);
    v4 = IEntity::ID();
    v2 = CPileMgr::operator[](v10);
    CPile::SetBuildingId((CPile *)v2, v4);
    v7 = CWorldManager::PileId(v8, v9);
    if ( v7 != v10 && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 765, "id == iPileId") == 1 )
      __debugbreak();
    if ( !v10 && BBSupportDbgReport(2, "MapObjects\\Building\\BarrackRole.cpp", 771, "iPileId != 0") == 1 )
      __debugbreak();
    if ( *(_BYTE *)(*((_DWORD *)v12 + 94) + 16 * i + 63) != 1
      && BBSupportDbgReportF(2, "MapObjects\\Building\\BarrackRole.cpp", 777, "Wrong pile type at barrack") == 1 )
    {
      __debugbreak();
    }
    v13 = v10;
    std::vector<unsigned short>::push_back(&v13);
  }
  if ( !std::vector<unsigned short>::size((char *)v12 + 384)
    && BBSupportDbgReportF(2, "MapObjects\\Building\\BarrackRole.cpp", 783, "No deliver pile at barrack") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(CBarrackRole *, struct CBuilding *, _DWORD))(*(_DWORD *)v12 + 88))(v12, a2, 0);
  if ( !IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  CEntityEvent::CEntityEvent((CEntityEvent *)v5, 8u, 0, *((unsigned __int16 *)v12 + 3), 0, 0);
  v14 = 0;
  v6 = v5;
  (*(void (__thiscall **)(struct CBuilding *, _BYTE *))(*(_DWORD *)a2 + 124))(a2, v5);
  v14 = -1;
  CEntityEvent::~CEntityEvent(v5);
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x14e72e0]
// Decompiled from int __thiscall CBarrackRole::PostLoadInit(CBarrackRole *this, struct CBuilding *a2)
void  CBarrackRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x14e7310]
// Decompiled from char __thiscall CBarrackRole::SettlerEnter(CBarrackRole *this, struct CBuilding *a2, int a3)
bool  CBarrackRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  return 1;
}


// address=[0x14e7320]
// Decompiled from int __thiscall CBarrackRole::GetBuildingNeed(CBarrackRole *this, int a2)
int  CBarrackRole::GetBuildingNeed(int a2)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 384); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v3 = CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v3 + 60))(v3, v3) == a2 )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
  }
  BBSupportTracePrintF(0, "TROUBLE: illegal goodcheck good %u", a2);
  return 0;
}


// address=[0x14e73c0]
// Decompiled from int __thiscall CBarrackRole::GetPileIdWithGood(CBarrackRole *this, int a2)
int  CBarrackRole::GetPileIdWithGood(int a2)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 384); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v3 = CPileMgr::operator[](*v2);
    if ( a2 == (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v3 + 60))(v3, v3) )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
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
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  CEcoSector *v7; // eax
  int v8; // esi
  CEcoSector *v9; // eax
  int v11; // [esp+1Ch] [ebp-48h]
  unsigned int v12; // [esp+20h] [ebp-44h]
  int v13; // [esp+24h] [ebp-40h]
  int v15; // [esp+2Ch] [ebp-38h]
  CEcoSector *v16; // [esp+30h] [ebp-34h]
  int v17; // [esp+34h] [ebp-30h]
  int i; // [esp+38h] [ebp-2Ch]
  int j; // [esp+38h] [ebp-2Ch]
  int k; // [esp+38h] [ebp-2Ch]
  CEvn_Event v21; // [esp+3Ch] [ebp-28h] BYREF
  int v22; // [esp+60h] [ebp-4h]

  *((_DWORD *)a2 + 1) = 16;
  v3 = CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v4 = CBuilding::EnsignWorldIdx(v3);
  v11 = CWorldManager::EcoSectorId(v4);
  v16 = (CEcoSector *)CEcoSectorMgr::operator[](v11);
  v17 = 0;
  for ( i = 0; i < 3; ++i )
    *((_BYTE *)a2 + i + 8) = CEcoSector::GetNrOfSoldierOrder(v16, v17++);
  for ( j = 0; j < 3; ++j )
    *((_BYTE *)a2 + j + 11) = CEcoSector::GetNrOfSoldierOrder(v16, v17++);
  for ( k = 0; k < 3; ++k )
    *((_BYTE *)a2 + k + 14) = CEcoSector::GetNrOfSoldierOrder(v16, v17++);
  *((_BYTE *)a2 + 17) = CEcoSector::GetNrOfSoldierOrder(v16, v17);
  v5 = CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v6 = CBuilding::EnsignWorldIdx(v5);
  v13 = CWorldManager::EcoSectorId(v6);
  v7 = (CEcoSector *)CEcoSectorMgr::operator[](v13);
  v8 = CEcoSector::NrOfSettler(v7, 1);
  v9 = (CEcoSector *)CEcoSectorMgr::operator[](v13);
  v15 = v8 - CEcoSector::MinCarrier(v9);
  if ( v15 <= 0 )
    v15 = 0;
  *((_DWORD *)a2 + 5) = v15;
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
// Decompiled from char *__thiscall CBarrackRole::CBarrackRole(char *this, int a2)
 CBarrackRole::CBarrackRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-24h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  int i; // [esp+10h] [ebp-1Ch]
  char *v6; // [esp+14h] [ebp-18h]
  _WORD v7[3]; // [esp+18h] [ebp-14h] BYREF
  unsigned __int8 v8; // [esp+1Fh] [ebp-Dh] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v6 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v9 = 0;
  *(_DWORD *)v6 = &CBarrackRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(v6 + 384);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 3 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBarrackRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v6 + 380);
  v8 = 0;
  operator^<unsigned char>(a2, &v8);
  for ( i = 0; i < v8; ++i )
  {
    v7[0] = 0;
    operator^<unsigned short>(a2, v7);
    std::vector<unsigned short>::push_back(v7);
  }
  v9 = -1;
  return v6;
}


// address=[0x14e77f0]
// Decompiled from int __thiscall CBarrackRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CBarrackRole::Store(std::ostream & a2) {
  
  int result; // eax
  __int16 *v3; // eax
  int v4; // [esp+0h] [ebp-10h] BYREF
  struct IBuildingRole *v5; // [esp+4h] [ebp-Ch]
  signed int i; // [esp+8h] [ebp-8h]
  int var1; // [esp+Fh] [ebp-1h] BYREF

  v5 = this;
  IBuildingRole::Store(this, a2);
  v4 = 3;
  operator^<unsigned int>(a2, &v4);
  operator^<unsigned char>(a2, (int)v5 + 380);
  LOBYTE(var1) = std::vector<unsigned short>::size((char *)v5 + 384);
  result = operator^<unsigned char>(a2, (int)&var1);
  for ( i = 0; i < (unsigned __int8)var1; ++i )
  {
    v3 = (__int16 *)std::vector<unsigned short>::operator[]((char *)v5 + 384, i);
    result = operator^<unsigned short>((int)a2, v3);
  }
  return result;
}


// address=[0x14e8030]
// Decompiled from int __thiscall CBarrackRole::~CBarrackRole(CBarrackRole *this)
 CBarrackRole::~CBarrackRole(void) {
  
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 384);
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
// Decompiled from int __cdecl CBarrackRole::Load(int a1)
class CBarrackRole * __cdecl CBarrackRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CBarrackRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8af58]
// [Decompilation failed for static unsigned long CBarrackRole::m_iClassID]

// address=[0x14e78a0]
// Decompiled from _DWORD *__thiscall CBarrackRole::FillDialog(CBarrackRole *this, struct CBuilding *a2, bool a3)
void  CBarrackRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  int v8; // [esp-8h] [ebp-4Ch]
  int v9; // [esp-8h] [ebp-4Ch]
  unsigned int v10; // [esp+4h] [ebp-40h]
  unsigned __int8 *v11; // [esp+8h] [ebp-3Ch]
  unsigned __int8 *v12; // [esp+Ch] [ebp-38h]
  unsigned int i; // [esp+18h] [ebp-2Ch]
  CEvn_Event v15; // [esp+1Ch] [ebp-28h] BYREF
  int v16; // [esp+40h] [ebp-4h]

  dword_3F1E5E8 = 7;
  byte_3F1E5ED = IEntity::Race(a2);
  byte_3F1E5EC = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E5EF = 1;
  byte_3F1E5F0 = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E5F1 = 0;
  v8 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E5F3 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v8, 0);
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E5F4 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v9, 1u);
  byte_3F1E5EE = *((_BYTE *)this + 29);
  if ( *((_BYTE *)this + 29) )
    byte_3F1E5F5 = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 384); ++i )
  {
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v12 = CPileMgr::operator[](*v5);
    byte_3F1E5F9[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v12 + 40))(v12);
    v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v11 = CPileMgr::operator[](*v6);
    byte_3F1E5F8[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v11 + 60))(v11);
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
void  CBarrackRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
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


