#include "CBuilding.h"

// Definitions for class CBuilding

// address=[0x12fd5a0]
// Decompiled from int __thiscall CBuilding::Role(_DWORD *this)
class IBuildingRole &  CBuilding::Role(void) {
  
  return std::auto_ptr<IBuildingRole>::operator*(this + 21);
}


// address=[0x1307110]
// Decompiled from int __thiscall CBuilding::EnsignX(CBuilding *this)
int  CBuilding::EnsignX(void)const {
  
  return Y16X16::UnpackXFast(*((_DWORD *)this + 19));
}


// address=[0x1307130]
// Decompiled from int __thiscall CBuilding::EnsignY(CBuilding *this)
int  CBuilding::EnsignY(void)const {
  
  return Y16X16::UnpackYFast(*((_DWORD *)this + 19));
}


// address=[0x130eb40]
// Decompiled from int __thiscall CBuilding::EnsignPackedXY(_DWORD *this)
int  CBuilding::EnsignPackedXY(void)const {
  
  return this[19];
}


// address=[0x130f010]
// Decompiled from int __thiscall CBuilding::HaveInhabitant(_DWORD *this)
bool  CBuilding::HaveInhabitant(void)const {
  
  void *v1; // eax

  v1 = (void *)std::auto_ptr<IBuildingRole>::operator->(this + 21);
  return IBuildingRole::HaveInhabitant(v1, (int)this);
}


// address=[0x13466c0]
// Decompiled from int __thiscall CBuilding::GetBuildingNeed(CBuilding *this, int a2)
int  CBuilding::GetBuildingNeed(int)const {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 52))(v3, a2);
}


// address=[0x1346700]
// Decompiled from int __thiscall CBuilding::GetPileIdWithGood(CBuilding *this, int a2)
int  CBuilding::GetPileIdWithGood(int)const {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 56))(v3, a2);
}


// address=[0x1346740]
// Decompiled from int __thiscall CBuilding::GetWorkingAreaPackedXY(CBuilding *this)
int  CBuilding::GetWorkingAreaPackedXY(void)const {
  
  return *((_DWORD *)this + 20);
}


// address=[0x1346790]
// Decompiled from bool __thiscall CBuilding::IsBuildUp(_DWORD *this)
bool  CBuilding::IsBuildUp(void)const {
  
  return IEntity::FlagBits(this, Birth) == 0;
}


// address=[0x13ffd20]
// Decompiled from int __cdecl CBuilding::New(int a1)
static class CPersistence * __cdecl CBuilding::New(std::istream &) {
  
  if ( CBuilding::operator new(0x64u) )
    return CBuilding::CBuilding(a1);
  else
    return 0;
}


// address=[0x1439b00]
// Decompiled from int __thiscall CBuilding::GetPileIdWithNeedForGood(CBuilding *this, int a2)
int  CBuilding::GetPileIdWithNeedForGood(int)const {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 64))(v3, a2);
}


// address=[0x14604d0]
// Decompiled from int __thiscall CBuilding::FillDialog(CBuilding *this)
void  CBuilding::FillDialog(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, CBuilding *, _DWORD))(*(_DWORD *)v2 + 88))(v2, this, 0);
}


// address=[0x1460760]
// Decompiled from int __thiscall CBuilding::NotifySelected(CBuilding *this)
void  CBuilding::NotifySelected(void) {
  
  int v1; // eax

  v1 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, CBuilding *, int))(*(_DWORD *)v1 + 48))(v1, this, v1);
}


// address=[0x1473110]
// Decompiled from int __thiscall CBuilding::SetWorkingAreaPackedXY(CBuilding *this, int a2)
void  CBuilding::SetWorkingAreaPackedXY(int) {
  
  int v2; // eax

  *((_DWORD *)this + 20) = a2;
  v2 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return IBuildingRole::WorkingAreaChanged(v2);
}


// address=[0x1473150]
// Decompiled from int __thiscall CBuilding::Switch(_DWORD *this)
void  CBuilding::Switch(void) {
  
  int v1; // eax

  v1 = std::auto_ptr<IBuildingRole>::operator->(this + 21);
  return (*(int (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)v1 + 32))(v1, this, v1);
}


// address=[0x14e88b0]
// Decompiled from int __thiscall CBuilding::BuildingTypeEx(unsigned __int8 *this)
int  CBuilding::BuildingTypeEx(void) {
  
  return this[68];
}


// address=[0x14e8910]
// Decompiled from int __thiscall CBuilding::DoorPackedXY(CMFCToolBarButton *this)
int  CBuilding::DoorPackedXY(void)const {
  
  return *((_DWORD *)this + 18);
}


// address=[0x14e89b0]
// Decompiled from int __thiscall CBuilding::Delete(CBuilding *this)
void  CBuilding::Delete(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int LastLogicUpdateTick; // eax
  int v5; // eax
  int v7; // [esp-8h] [ebp-44h]
  int v8; // [esp-4h] [ebp-40h]
  _BYTE v9[24]; // [esp+4h] [ebp-38h] BYREF
  int v10; // [esp+1Ch] [ebp-20h]
  const struct CEntityEvent *v11; // [esp+20h] [ebp-1Ch]
  const struct CEntityEvent *v12; // [esp+24h] [ebp-18h]
  int v13; // [esp+28h] [ebp-14h]
  CPaneContainer *v14; // [esp+2Ch] [ebp-10h]
  int v15; // [esp+38h] [ebp-4h]

  v14 = this;
  v10 = IAnimatedEntity::Next(this);
  CWarMap::RemoveEntity(v14);
  if ( !(unsigned __int8)CBuilding::IsBuildUp(v14) )
  {
    v1 = IEntity::WorldIdx();
    CWorldManager::SetObjectId(v1, 0);
  }
  v7 = IAnimatedEntity::AttackerPlayerId();
  v2 = IEntity::EntityId((unsigned __int16 *)v14);
  v12 = CEntityEvent::CEntityEvent((CEntityEvent *)v9, 9u, 0, v2, v7, 0);
  v11 = v12;
  v15 = 0;
  CObserverList::NotifyAndDetachAllObservers((CPaneContainer *)((char *)v14 + 88), v12);
  v15 = -1;
  CEntityEvent::~CEntityEvent(v9);
  if ( *((_WORD *)v14 + 35) )
  {
    v13 = CBuildingMgr::operator[](*((unsigned __int16 *)v14 + 35));
    v3 = IEntity::ID();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v13 + 64))(v13, v3);
  }
  v8 = *((unsigned __int16 *)v14 + 4);
  LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(v14);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v8);
  v5 = IEntity::ID();
  CBuildingMgr::CheckOutBuilding((CBuildingMgr *)g_cBuildingMgr, v5);
  IEntity::EntityId((unsigned __int16 *)v14);
  IEntity::OwnerId((unsigned __int8 *)v14);
  return (*(int (__cdecl **)(int))(*(_DWORD *)off_3D7A3D8 + 44))(4);
}


// address=[0x14e8b00]
// Decompiled from void __thiscall CBuilding::PostLoadInit(CBuilding *this)
void  CBuilding::PostLoadInit(void) {
  
  int v1; // eax
  IBuildingRole *v2; // eax

  IEntity::PostLoadInit();
  CWarMap::AddEntity(this);
  v1 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  (*(void (__thiscall **)(int, CBuilding *))(*(_DWORD *)v1 + 28))(v1, this);
  if ( *(_DWORD *)(std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21) + 376)
    && *(_BYTE *)(*(_DWORD *)(std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21) + 376) + 6) )
  {
    if ( IEntity::FlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    {
      v2 = (IBuildingRole *)std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
      IBuildingRole::PostLoadSetWaterFlags(v2, this);
    }
  }
}


// address=[0x14e8ba0]
// Decompiled from int __thiscall CBuilding::LogicUpdate(CBuilding *this)
void  CBuilding::LogicUpdate(void) {
  
  int result; // eax
  int v2; // eax

  result = IAnimatedEntity::ProcessAllEvents(this);
  if ( (_BYTE)result )
    return result;
  v2 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, CBuilding *))(*(_DWORD *)v2 + 12))(v2, this);
}


// address=[0x14e8be0]
// Decompiled from void *__thiscall sub_18E8BE0(_BYTE *this)
struct SGfxObjectInfo *  CBuilding::GetGfxInfos(void) {
  
  int v1; // eax

  if ( (unsigned __int8)CInputProcessor::IsBoxSelection(&g_cInputProcessor) )
    IAnimatedEntity::BoxSelection(this);
  dword_40FE2A8 = 0;
  dword_40FE2AC = 0;
  v1 = std::auto_ptr<IBuildingRole>::operator->();
  (*(void (__thiscall **)(int, _BYTE *, void *))(*(_DWORD *)v1 + 20))(v1, this, &IEntity::m_sGfxInfo);
  byte_40FE518 = this[10];
  byte_40FE51A = IEntity::IsVisible(this);
  if ( IEntity::FlagBits(512) )
    byte_40FE266 = 28;
  else
    byte_40FE266 = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x14e8c80]
// Decompiled from int __thiscall CBuilding::EnsignWorldIdx(CBuilding *this)
int  CBuilding::EnsignWorldIdx(void)const {
  
  return CWorldManager::Index(*((_DWORD *)this + 19));
}


// address=[0x14e8ca0]
// Decompiled from int __thiscall CBuilding::DoorWorldIdx(int *this)
int  CBuilding::DoorWorldIdx(void)const {
  
  return CWorldManager::Index(this[18]);
}


// address=[0x14e8cc0]
// Decompiled from int __thiscall CBuilding::EcoSectorId(CBuilding *this)
int  CBuilding::EcoSectorId(void)const {
  
  int v1; // eax

  v1 = CBuilding::EnsignWorldIdx(this);
  return CWorldManager::EcoSectorId(v1);
}


// address=[0x14e8ce0]
// Decompiled from _DWORD *__thiscall CBuilding::TryCrushBuilding(CBuilding *this)
void  CBuilding::TryCrushBuilding(void) {
  
  _DWORD *result; // eax
  int v2; // eax
  int v3; // eax
  int v4; // [esp+8h] [ebp-30h]
  CEvn_Event v6; // [esp+10h] [ebp-28h] BYREF
  int v7; // [esp+34h] [ebp-4h]

  v4 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  result = (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 40))(v4);
  if ( !(_BYTE)result )
    return result;
  dword_3F1E4A4 = 10;
  dword_3F1E4A8 = 0;
  v2 = IEntity::Type((unsigned __int16 *)this);
  if ( CBuildingMgr::IsMilitaryBuildingEx(v2) && CBuilding::IsOccupied(this) )
  {
    v3 = IEntity::OwnerId((unsigned __int8 *)this);
    if ( !CBuildingMgr::CheckNumberOfOccupiedMilitaryBuildings((CBuildingMgr *)g_cBuildingMgr, v3, 2) )
      dword_3F1E4A8 = 1;
  }
  CEvn_Event::CEvn_Event(&v6, 0x25Au, 0, (unsigned int)&g_cInfoExchangeInt, 0);
  v7 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "MapObjects\\Building\\Building.cpp", 538, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v6);
  v7 = -1;
  return CEvn_Event::~CEvn_Event(&v6);
}


// address=[0x14e8e20]
// Decompiled from int __thiscall CBuilding::CrushBuilding(CBuilding *this)
void  CBuilding::CrushBuilding(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  void *v8; // eax
  int v9; // eax
  int v11; // [esp-10h] [ebp-30h]
  int v12; // [esp-10h] [ebp-30h]
  int v13; // [esp-4h] [ebp-24h]
  int v14; // [esp-4h] [ebp-24h]
  int v15; // [esp+4h] [ebp-1Ch]
  int v16; // [esp+8h] [ebp-18h]
  int v17; // [esp+Ch] [ebp-14h]
  int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  char *BuildingInfo; // [esp+18h] [ebp-8h]

  v1 = IEntity::WorldIdx();
  if ( CWorldManager::BuildingId(v1) )
  {
    v2 = IEntity::WorldIdx();
    CWorldManager::SetMapObjectId(v2, 0);
  }
  v19 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  (*(void (__thiscall **)(int, CBuilding *))(*(_DWORD *)v19 + 100))(v19, this);
  CBuilding::RemoveBuildingBits(this);
  v18 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  (*(void (__thiscall **)(int, CBuilding *))(*(_DWORD *)v18 + 96))(v18, this);
  v13 = IEntity::Type((unsigned __int16 *)this);
  v3 = IEntity::Race(this);
  BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v3, v13);
  if ( (BuildingInfo[55] - BuildingInfo[54]) * (BuildingInfo[53] - BuildingInfo[52]) >= 90 )
  {
    v16 = CLogic::Effects((DWORD *)g_pLogic);
    v12 = IEntity::Y(this);
    v5 = IEntity::X(this);
    (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v16 + 16))(
      v16,
      60,
      2,
      v5,
      v12,
      0,
      0,
      0);
  }
  else
  {
    v17 = CLogic::Effects((DWORD *)g_pLogic);
    v11 = IEntity::Y(this);
    v4 = IEntity::X(this);
    (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v17 + 16))(
      v17,
      62,
      3,
      v4,
      v11,
      0,
      0,
      0);
  }
  if ( IEntity::Race(this) != 3 )
  {
    v14 = IEntity::ID();
    v6 = CBuilding::EnsignWorldIdx(this);
    v7 = CWorldManager::EcoSectorId(v6);
    v8 = (void *)CEcoSectorMgr::operator[](v7);
    CEcoSector::CleanUpBuildingNeed(v8, v14);
  }
  v9 = IEntity::ID();
  CMapObjectMgr::Kill(v9, 0);
  v15 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 44))(v15);
}


// address=[0x14e8fc0]
// Decompiled from int __thiscall CBuilding::DestroyBuilding(CBuilding *this, int a2)
void  CBuilding::DestroyBuilding(int) {
  
  unsigned int v2; // eax
  int v3; // eax
  CPlayerGameData *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  void *v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // eax
  int result; // eax
  int v19; // [esp-10h] [ebp-6Ch]
  int v20; // [esp-10h] [ebp-6Ch]
  int v21; // [esp-10h] [ebp-6Ch]
  int v22; // [esp-8h] [ebp-64h]
  int v23; // [esp-4h] [ebp-60h]
  int v24; // [esp-4h] [ebp-60h]
  int v25; // [esp-4h] [ebp-60h]
  CEvn_Event *v26; // [esp+Ch] [ebp-50h]
  int v27; // [esp+14h] [ebp-48h]
  int v28; // [esp+18h] [ebp-44h]
  int v29; // [esp+1Ch] [ebp-40h]
  int v30; // [esp+20h] [ebp-3Ch]
  int v31; // [esp+24h] [ebp-38h]
  char *BuildingInfo; // [esp+28h] [ebp-34h]
  char v33; // [esp+2Fh] [ebp-2Dh]
  CEvn_Event v35; // [esp+34h] [ebp-28h] BYREF
  int v36; // [esp+58h] [ebp-4h]

  v33 = 0;
  if ( IEntity::Type((unsigned __int16 *)this) == 51
    && *(_DWORD *)(g_pGameType + 744) == 11
    && (*(_DWORD *)(g_pGameType + 740) == 15 || *(_DWORD *)(g_pGameType + 740) == 4) )
  {
    v33 = 1;
    v2 = IEntity::OwnerId((unsigned __int8 *)this);
    v26 = CEvn_Event::CEvn_Event(&v35, 0x38u, v2, 0, 0);
    v36 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v26);
    v36 = -1;
    CEvn_Event::~CEvn_Event(&v35);
    v3 = IEntity::OwnerId((unsigned __int8 *)this);
    v4 = CPlayerManager::PlayerGameData(v3);
    CPlayerGameData::SetPlayerLostFlag(v4);
  }
  v5 = IEntity::EntityId((unsigned __int16 *)this);
  BBSupportTracePrintF(0, "CBuilding::DestroyBuilding(): building %i, gardener player id %i.", v5, a2);
  if ( !v33 )
  {
    v6 = IEntity::WorldIdx();
    if ( CWorldManager::BuildingId(v6) )
    {
      v7 = IEntity::WorldIdx();
      CWorldManager::SetMapObjectId(v7, 0);
    }
    CBuilding::RemoveBuildingBits(this);
    if ( IEntity::Type((unsigned __int16 *)this) == 49 )
    {
      v29 = CLogic::Effects((DWORD *)g_pLogic);
      v21 = IEntity::Y(this);
      v11 = IEntity::X(this);
      (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v29 + 16))(
        v29,
        77,
        90,
        v11,
        v21,
        0,
        0,
        0);
    }
    else
    {
      v23 = IEntity::Type((unsigned __int16 *)this);
      v8 = IEntity::Race(this);
      BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v8, v23);
      if ( (BuildingInfo[55] - BuildingInfo[54]) * (BuildingInfo[53] - BuildingInfo[52]) >= 90 )
      {
        v30 = CLogic::Effects((DWORD *)g_pLogic);
        v20 = IEntity::Y(this);
        v10 = IEntity::X(this);
        (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v30 + 16))(
          v30,
          61,
          90,
          v10,
          v20,
          0,
          0,
          0);
      }
      else
      {
        v31 = CLogic::Effects((DWORD *)g_pLogic);
        v19 = IEntity::Y(this);
        v9 = IEntity::X(this);
        (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v31 + 16))(
          v31,
          63,
          91,
          v9,
          v19,
          0,
          0,
          0);
      }
    }
  }
  v28 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  (*(void (__thiscall **)(int, CBuilding *))(*(_DWORD *)v28 + 100))(v28, this);
  if ( IEntity::Race(this) != 3 )
  {
    v24 = IEntity::ID();
    v12 = CBuilding::EnsignWorldIdx(this);
    v13 = CWorldManager::EcoSectorId(v12);
    v14 = (void *)CEcoSectorMgr::operator[](v13);
    CEcoSector::CleanUpBuildingNeed(v14, v24);
  }
  v15 = IEntity::OwnerId((unsigned __int8 *)this);
  if ( v15 == CPlayerManager::GetLocalPlayerId() )
  {
    v25 = IEntity::Y(this);
    v22 = IEntity::X(this);
    v16 = IEntity::OwnerId((unsigned __int8 *)this);
    CTextMsgHandler::AddWarningMsg(2470, v16, v22, v25);
  }
  *((_BYTE *)this + 37) = a2;
  if ( !v33 )
  {
    v17 = IEntity::ID();
    CMapObjectMgr::Kill(v17, 0);
  }
  v27 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  result = (*(int (__thiscall **)(int))(*(_DWORD *)v27 + 44))(v27);
  *((_BYTE *)this + 37) = 0;
  return result;
}


// address=[0x14e92f0]
// Decompiled from int __thiscall CBuilding::GoodArrive(CBuilding *this, int a2)
void  CBuilding::GoodArrive(int) {
  
  int v2; // eax
  int v3; // eax

  v2 = IEntity::Type((unsigned __int16 *)this);
  CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 17, v2, a2, 1);
  v3 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 68))(v3, a2);
}


// address=[0x14e9340]
// Decompiled from int __thiscall CBuilding::SetToWorld(_DWORD *this)
void  CBuilding::SetToWorld(void) {
  
  int v1; // eax
  _DWORD *v2; // eax
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v17; // [esp-10h] [ebp-E8h]
  int v18; // [esp-Ch] [ebp-E4h]
  int v19; // [esp-8h] [ebp-E0h]
  int v20; // [esp-8h] [ebp-E0h]
  int v21; // [esp-4h] [ebp-DCh]
  char *v22; // [esp-4h] [ebp-DCh]
  int v23; // [esp-4h] [ebp-DCh]
  _DWORD v24[7]; // [esp+4h] [ebp-D4h] BYREF
  _BYTE v25[12]; // [esp+20h] [ebp-B8h] BYREF
  _BYTE v26[12]; // [esp+2Ch] [ebp-ACh] BYREF
  _BYTE v27[12]; // [esp+38h] [ebp-A0h] BYREF
  _BYTE v28[12]; // [esp+44h] [ebp-94h] BYREF
  _BYTE v29[12]; // [esp+50h] [ebp-88h] BYREF
  _BYTE v30[12]; // [esp+5Ch] [ebp-7Ch] BYREF
  std::_Iterator_base12 *v31; // [esp+68h] [ebp-70h]
  std::_Iterator_base12 *v32; // [esp+6Ch] [ebp-6Ch]
  int v33; // [esp+70h] [ebp-68h]
  int v34; // [esp+74h] [ebp-64h]
  std::_Iterator_base12 *v35; // [esp+78h] [ebp-60h]
  std::_Iterator_base12 *v36; // [esp+7Ch] [ebp-5Ch]
  int v37; // [esp+80h] [ebp-58h]
  int v38; // [esp+84h] [ebp-54h]
  std::_Iterator_base12 *v39; // [esp+88h] [ebp-50h]
  std::_Iterator_base12 *v40; // [esp+8Ch] [ebp-4Ch]
  int v41; // [esp+90h] [ebp-48h]
  int v42; // [esp+94h] [ebp-44h]
  int v43; // [esp+98h] [ebp-40h]
  _BYTE v44[12]; // [esp+9Ch] [ebp-3Ch] BYREF
  int k; // [esp+A8h] [ebp-30h]
  int j; // [esp+ACh] [ebp-2Ch]
  int i; // [esp+B0h] [ebp-28h]
  int v48; // [esp+B4h] [ebp-24h]
  int v49; // [esp+B8h] [ebp-20h]
  char v50; // [esp+BDh] [ebp-1Bh]
  char v51; // [esp+BEh] [ebp-1Ah]
  char v52; // [esp+BFh] [ebp-19h]
  int v53; // [esp+C0h] [ebp-18h]
  _DWORD *v54; // [esp+C4h] [ebp-14h]
  char *BuildingInfo; // [esp+C8h] [ebp-10h]
  int v56; // [esp+D4h] [ebp-4h]

  v54 = this;
  v21 = CBuilding::BuildingTypeEx((unsigned __int8 *)this);
  v1 = IEntity::Race(v54);
  BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v1, v21);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v44);
  v56 = 0;
  v53 = 0;
  v42 = std::vector<unsigned int>::begin(v30);
  v41 = v42;
  LOBYTE(v56) = 1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v42);
  LOBYTE(v56) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v30);
  while ( 1 )
  {
    v40 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v29);
    v39 = v40;
    LOBYTE(v56) = 2;
    v52 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v40);
    LOBYTE(v56) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v29);
    if ( !v52 )
      break;
    ++v53;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v44) )
    {
      for ( i = 31; i >= 0; --i )
      {
        v2 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v44);
        if ( (*v2 & (1 << i)) != 0 )
        {
          v3 = IEntity::X(v54);
          v48 = v3 + 32 - i - *BuildingInfo - 1;
          v4 = IEntity::Y(v54);
          v49 = v53 + v4 - BuildingInfo[1] - 1;
          v43 = CWorldManager::Index(v48, v49);
          CWorldManager::SetMoveCostsBits(v43, 7);
          CWorldManager::SetFlagBits(v43, 2u);
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v44);
  }
  v53 = 0;
  v38 = std::vector<unsigned int>::begin(v28);
  v37 = v38;
  LOBYTE(v56) = 3;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v38);
  LOBYTE(v56) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v28);
  while ( 1 )
  {
    v36 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v27);
    v35 = v36;
    LOBYTE(v56) = 4;
    v51 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v36);
    LOBYTE(v56) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v27);
    if ( !v51 )
      break;
    ++v53;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v44) )
    {
      for ( j = 31; j >= 0; --j )
      {
        v5 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v44);
        if ( (*v5 & (1 << j)) != 0 )
        {
          v6 = IEntity::X(v54);
          v48 = v6 + 32 - j - *BuildingInfo - 1;
          v7 = IEntity::Y(v54);
          v49 = v53 + v7 - BuildingInfo[1] - 1;
          CWorldManager::SetFlagBits(v48, v49, 8);
          v8 = IEntity::Type((unsigned __int16 *)v54);
          if ( (unsigned __int8)CBuildingMgr::IsMilitary(v8) )
          {
            CWorldManager::SetFlagBits(v48, v49, 128);
            v9 = IEntity::OwnerId((unsigned __int8 *)v54);
            CWorldManager::SetOwnerId(v48, v49, v9);
          }
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v44);
  }
  v53 = 0;
  v34 = std::vector<unsigned int>::begin(v26);
  v33 = v34;
  LOBYTE(v56) = 5;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v34);
  LOBYTE(v56) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v26);
  while ( 1 )
  {
    v32 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v25);
    v31 = v32;
    LOBYTE(v56) = 6;
    v50 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v32);
    LOBYTE(v56) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v25);
    if ( !v50 )
      break;
    ++v53;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v44) )
    {
      for ( k = 31; k >= 0; --k )
      {
        v10 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v44);
        if ( (*v10 & (1 << k)) != 0 )
        {
          v11 = IEntity::X(v54);
          v48 = v11 + 32 - k - *BuildingInfo - 1;
          v12 = IEntity::Y(v54);
          v49 = v53 + v12 - BuildingInfo[1] - 1;
          CWorldManager::SetBlockedPosition(v48, v49);
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v44);
  }
  if ( BuildingInfo[6] )
  {
    v22 = BuildingInfo + 816;
    v19 = BuildingInfo[1];
    v18 = *BuildingInfo;
    v17 = IEntity::Y(v54);
    v13 = IEntity::X(v54);
    CBuildingFlagsWalk::CBuildingFlagsWalk(v13, v17, v18, v19, v22);
    while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v24) )
    {
      v23 = CBuildingFlagsWalk::CurrentY(v24);
      v14 = CBuildingFlagsWalk::CurrentX(v24);
      (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 16))(g_pTiling, v14, v23);
    }
  }
  CBuilding::CorrectBuildingBits(v54);
  v20 = IEntity::Y(v54);
  v15 = IEntity::X(v54);
  if ( !CWorldManager::FlagBits(v15, v20, 1u)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\Building.cpp",
         453,
         "g_cWorld.FlagBits(X(), Y(), FLAG_BLOCKED_LAND) != 0") == 1 )
  {
    __debugbreak();
  }
  v56 = -1;
  return std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v44);
}


// address=[0x14e9880]
// Decompiled from int __thiscall CBuilding::Decrease(int this, int a2)
void  CBuilding::Decrease(int) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  char v6; // [esp+14h] [ebp+8h]

  v4 = std::auto_ptr<IBuildingRole>::operator->();
  result = (*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 108))(v4, a2);
  v6 = result;
  if ( result <= 0 )
    return result;
  if ( result < *(unsigned __int8 *)(this + 33) )
  {
    result = this;
    *(_BYTE *)(this + 33) -= v6;
  }
  else
  {
    *(_BYTE *)(this + 33) = 0;
    if ( (*(_DWORD *)(this + 4) & 0x20000000) != 0 )
    {
      if ( IEntity::FlagBits((_DWORD *)this, 0x3000000)
        && BBSupportDbgReport(
             2,
             (int)"MapObjects\\Building\\Building.cpp",
             1017,
             (int)"FlagBits(ENTITY_FLAG_ALIVE_MASK) == 0") == 1 )
      {
        __debugbreak();
      }
      result = IEntity::FlagBits((_DWORD *)this, 0x4000000);
      if ( !result )
      {
        result = BBSupportDbgReport(
                   2,
                   (int)"MapObjects\\Building\\Building.cpp",
                   1018,
                   (int)"FlagBits(ENTITY_FLAG_DIED) != 0");
        if ( result == 1 )
          __debugbreak();
      }
    }
    else
    {
      v3 = std::auto_ptr<IBuildingRole>::operator->();
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 116))(v3, this);
      return CBuilding::DestroyBuilding(0);
    }
  }
  return result;
}


// address=[0x14e9980]
// Decompiled from unsigned int __cdecl CBuilding::operator_new(unsigned int a1)
static void * __cdecl CBuilding::operator new(unsigned int) {
  
  return CBuildingMgr::Alloc(g_cBuildingMgr, a1);
}


// address=[0x14e99a0]
// Decompiled from void __cdecl CBuilding::operator delete(void *a1)
static void __cdecl CBuilding::operator delete(void *) {
  
  CBuildingMgr::Dealloc((CBuildingMgr *)g_cBuildingMgr, a1);
}


// address=[0x14e99e0]
// Decompiled from void __thiscall CBuilding::Attach(CBuilding *this, int a2)
void  CBuilding::Attach(int) {
  
  int v2; // eax

  v2 = IEntity::EntityId((unsigned __int16 *)this);
  CObserverList::Attach((CBuilding *)((char *)this + 88), v2, a2);
}


// address=[0x14e9a10]
// Decompiled from int __thiscall CBuilding::Detach(CBuilding *this, int a2)
void  CBuilding::Detach(int) {
  
  int v3; // [esp+0h] [ebp-8h]

  CBuilding::DetachWithoutNotify(this, a2);
  v3 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, CBuilding *, int))(*(_DWORD *)v3 + 124))(v3, this, a2);
}


// address=[0x14e9a50]
// Decompiled from int __stdcall CBuilding::Notify(int a1)
void  CBuilding::Notify(class CEntityEvent const &)const {
  
  return CObserverList::NotifyAllObservers(a1);
}


// address=[0x14e9a70]
// Decompiled from int __stdcall CBuilding::Notify_0(int a1, int a2)
void  CBuilding::Notify(class CEntityEvent const &,class INotifyFilter &)const {
  
  return CObserverList::NotifyAllObservers(a1, a2);
}


// address=[0x14e9a90]
// Decompiled from int __thiscall CBuilding::SetObserverTarget(int this, int a2, int a3)
void  CBuilding::SetObserverTarget(enum T_OBSERVER_TARGET,int) {
  
  int result; // eax
  unsigned int v4; // ecx

  if ( a2 )
  {
    if ( BBSupportDbgReport(
           1,
           "MapObjects\\Building\\Building.cpp",
           971,
           "ISettlerRole::SetObserverTarget(): Invalid target type!") == 1 )
      __debugbreak();
    return 0;
  }
  else
  {
    *(_WORD *)(this + 70) = a3;
    result = this;
    if ( a3 <= 0 )
      v4 = *(_DWORD *)(this + 20) & 0xFFFFFFDF;
    else
      v4 = *(_DWORD *)(this + 20) | 0x20;
    *(_DWORD *)(this + 20) = v4;
  }
  return result;
}


// address=[0x14e9b00]
// Decompiled from int __thiscall CBuilding::GetObserverTarget(unsigned __int16 *this, int a2)
int  CBuilding::GetObserverTarget(enum T_OBSERVER_TARGET) {
  
  if ( a2 )
    return 0;
  else
    return this[35];
}


// address=[0x14e9b30]
// Decompiled from char *__thiscall CBuilding::CBuilding(char *this, int a2)
 CBuilding::CBuilding(std::istream &) {
  
  int BuildingRole; // [esp+4h] [ebp-28h]
  int v4; // [esp+Ch] [ebp-20h] BYREF
  int v5; // [esp+10h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+14h] [ebp-18h] BYREF
  char *v7; // [esp+18h] [ebp-14h]
  unsigned __int8 v8; // [esp+1Fh] [ebp-Dh] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  IAnimatedEntity::IAnimatedEntity(a2);
  v9 = 0;
  *(_DWORD *)v7 = &CBuilding::_vftable_;
  std::auto_ptr<IBuildingRole>::auto_ptr<IBuildingRole>((_DWORD *)v7 + 21, 0);
  CObserverList::CObserverList(a2);
  LOBYTE(v9) = 2;
  operator^<unsigned int>(a2, &v4);
  if ( v4 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuilding");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v7 + 72));
  operator^<int>(a2, (int)(v7 + 76));
  operator^<int>(a2, (int)(v7 + 80));
  operator^<unsigned short>(a2, v7 + 70);
  operator^<unsigned char>(a2, v7 + 68);
  operator^<unsigned char>(a2, &v8);
  BuildingRole = CBuildingMgr::LoadBuildingRole(a2, v8);
  std::auto_ptr<IBuildingRole>::auto_ptr<IBuildingRole>(&v5, BuildingRole);
  LOBYTE(v9) = 3;
  std::auto_ptr<IBuildingRole>::operator=(&v5);
  CBuilding::CorrectBuildingBits(v7);
  LOBYTE(v9) = 2;
  std::auto_ptr<IBuildingRole>::~auto_ptr<IBuildingRole>(&v5);
  v9 = -1;
  return v7;
}


// address=[0x14e9cc0]
// Decompiled from int __thiscall CBuilding::Store(void *this, struct std::ostream *a2)
void  CBuilding::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-14h] BYREF
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  void *v6; // [esp+Ch] [ebp-8h]
  int var1; // [esp+13h] [ebp-1h] BYREF

  v6 = this;
  IAnimatedEntity::Store(a2);
  CObserverList::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<int>((int)a2, (int *)v6 + 18);
  operator^<int>((int)a2, (int *)v6 + 19);
  operator^<int>((int)a2, (int *)v6 + 20);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 35);
  operator^<unsigned char>(a2, (int)v6 + 68);
  v5 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)v6 + 21);
  LOBYTE(var1) = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 112))(v5);
  operator^<unsigned char>(a2, (int)&var1);
  v4 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)v6 + 21);
  return (*(int (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v4 + 4))(v4, a2);
}


// address=[0x14eb2c0]
// Decompiled from int __thiscall CBuilding::ClassID(CBuilding *this)
unsigned long  CBuilding::ClassID(void)const {
  
  return CBuilding::m_iClassID;
}


// address=[0x14eb550]
// Decompiled from bool __thiscall CBuilding::IsOccupied(CBuilding *this)
bool  CBuilding::IsOccupied(void)const {
  
  void *v1; // eax
  int v3; // [esp+0h] [ebp-8h]
  char v4; // [esp+0h] [ebp-8h]

  v4 = 0;
  if ( !IEntity::FlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return v4;
  v1 = (void *)std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  if ( (unsigned __int8)IBuildingRole::HaveInhabitant(v1, v3) )
    return 1;
  return v4;
}


// address=[0x14eb810]
// Decompiled from int __thiscall CBuilding::Update(CBuilding *this)
void  CBuilding::Update(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, CBuilding *))(*(_DWORD *)v2 + 16))(v2, this);
}


// address=[0x14fddd0]
// Decompiled from int __thiscall CBuilding::SettlerEnter(CBuilding *this, int a2)
void  CBuilding::SettlerEnter(int) {
  
  int v2; // eax

  v2 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, CBuilding *, int))(*(_DWORD *)v2 + 76))(v2, this, a2);
}


// address=[0x15010d0]
// Decompiled from int __thiscall CBuilding::DoorX(CBuilding *this)
int  CBuilding::DoorX(void)const {
  
  return Y16X16::UnpackXFast(*((_DWORD *)this + 18));
}


// address=[0x15010f0]
// Decompiled from int __thiscall CBuilding::DoorY(CBuilding *this)
int  CBuilding::DoorY(void)const {
  
  return Y16X16::UnpackYFast(*((_DWORD *)this + 18));
}


// address=[0x15670e0]
// Decompiled from int __thiscall CBuilding::InhabitantFlee(CBuilding *this, int a2)
void  CBuilding::InhabitantFlee(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(v3, a2);
}


// address=[0x3d8b090]
// [Decompilation failed for static unsigned long CBuilding::m_iClassID]

// address=[0x15063e0]
// Decompiled from void __thiscall CBuilding::DetachAllNonePileObservers(CBuilding *this)
void  CBuilding::DetachAllNonePileObservers(void) {
  
  CObserverList::DetachAllNonePileObservers((CBuilding *)((char *)this + 88));
}


// address=[0x1506610]
// Decompiled from int __thiscall CBuilding::NotifyAllObservers(CBuilding *this, const struct CEntityEvent *a2)
void  CBuilding::NotifyAllObservers(class CEntityEvent const &)const {
  
  return CObserverList::NotifyAllObservers((char *)this + 88, (int)a2);
}


// address=[0x1506640]
// Decompiled from void __thiscall CBuilding::NotifyAndDetachAllObservers(CBuilding *this, const struct CEntityEvent *a2)
void  CBuilding::NotifyAndDetachAllObservers(class CEntityEvent const &) {
  
  CObserverList::NotifyAndDetachAllObservers((CBuilding *)((char *)this + 88), a2);
}


// address=[0x14e9db0]
// Decompiled from int __thiscall CBuilding::CorrectBuildingBits(_BYTE *this)
void  CBuilding::CorrectBuildingBits(void) {
  
  int v1; // eax
  int result; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-8h]
  int v5; // [esp-4h] [ebp-8h]

  if ( IEntity::Race(this) == 1 && IEntity::Type((unsigned __int16 *)this) == 47 )
  {
    v4 = IEntity::Y(this) + 1;
    v1 = IEntity::X(this);
    return CWorldManager::ClearBlockedPosition(v1 - 2, v4);
  }
  else
  {
    result = IEntity::Race(this);
    if ( result == 2 )
    {
      result = IEntity::Type((unsigned __int16 *)this);
      if ( result == 48 )
      {
        v5 = IEntity::Y(this) + 4;
        v3 = IEntity::X(this);
        return CWorldManager::ClearBlockedPosition(v3 - 2, v5);
      }
    }
  }
  return result;
}


// address=[0x14e9e40]
// Decompiled from int __thiscall CBuilding::CBuilding_0(int this, int a2, int a3, int a4, int a5, int a6, int a7)
 CBuilding::CBuilding(int,int,int,int,class std::auto_ptr<class IBuildingRole>,int) {
  
  void *v7; // eax
  char v8; // al
  int v9; // eax
  int v11; // [esp+4h] [ebp-1Ch]
  int v12; // [esp+8h] [ebp-18h]
  char *BuildingInfo; // [esp+Ch] [ebp-14h]

  IAnimatedEntity::IAnimatedEntity(a7);
  *(_DWORD *)this = &CBuilding::_vftable_;
  std::auto_ptr<IBuildingRole>::auto_ptr<IBuildingRole>((int)&a6);
  CObserverList::CObserverList((void *)(this + 88));
  *(_BYTE *)(this + 68) = a4;
  *(_BYTE *)(this + 69) = 0;
  *(_WORD *)(this + 70) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  IMessageTracer::PushFormatedInts(
    "CBuilding::CBuilding(): entity id %u, player %u, building type %u, position (%i, %i)",
    a7,
    a5,
    a4,
    a2,
    a3);
  if ( (a4 <= 0 || a4 >= 83)
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Building\\Building.cpp",
         89,
         (int)"(_iBuildingTypeEx > BUILDING_NO_BUILDING) && (_iBuildingTypeEx < BUILDING_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 == 32
    && BBSupportDbgReport(2, (int)"MapObjects\\Building\\Building.cpp", 90, (int)"_iBuildingTypeEx != BUILDING_PORT") == 1 )
  {
    __debugbreak();
  }
  if ( a4 == 31
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Building\\Building.cpp",
         91,
         (int)"_iBuildingTypeEx != BUILDING_SHIPYARD") == 1 )
  {
    __debugbreak();
  }
  IEntity::SetPosition(a2, a3);
  IEntity::SetOwnerId(a5);
  v7 = (void *)CPlayerManager::PlayerInfo(a5);
  v8 = CPlayerInfo::Race(v7);
  IEntity::SetRace(v8);
  v9 = IEntity::Race((_BYTE *)this);
  BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v9, a4);
  *(_DWORD *)(this + 72) = Y16X16::PackXYFast(a2 + BuildingInfo[40], a3 + BuildingInfo[41]);
  *(_DWORD *)(this + 76) = Y16X16::PackXYFast(a2 + BuildingInfo[38], a3 + BuildingInfo[39]);
  *(_DWORD *)(this + 80) = CBuilding::EnsignPackedXY((_DWORD *)this);
  if ( (unsigned __int8)CBuildingMgr::IsPortEx(a4) )
  {
    v12 = 32;
  }
  else if ( (unsigned __int8)CBuildingMgr::IsShipyardEx(a4) )
  {
    v12 = 31;
  }
  else
  {
    v12 = a4;
  }
  *(_WORD *)(this + 12) = v12;
  *(_BYTE *)(this + 10) = 8;
  IEntity::SetFlagBits((_DWORD *)this, (EntityFlag)0x1100u);
  if ( (unsigned __int8)CBuildingMgr::IsMilitary(v12) )
    IEntity::SetFlagBits((_DWORD *)this, (EntityFlag)0xCu);
  CWarMap::AddEntity((CPropertySet *)this);
  v11 = std::auto_ptr<IBuildingRole>::operator->();
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 24))(v11, this);
  std::auto_ptr<IBuildingRole>::~auto_ptr<IBuildingRole>(&a6);
  return this;
}


// address=[0x14ea0f0]
// Decompiled from void __thiscall CBuilding::~CBuilding(CBuilding *this)
 CBuilding::~CBuilding(void) {
  
  *(_DWORD *)this = &CBuilding::_vftable_;
  CObserverList::~CObserverList((CBuilding *)((char *)this + 88));
  std::auto_ptr<IBuildingRole>::~auto_ptr<IBuildingRole>((char *)this + 84);
  IAnimatedEntity::~IAnimatedEntity(this);
}


// address=[0x14ea130]
// Decompiled from int __thiscall CBuilding::Ready(unsigned __int8 *this)
void  CBuilding::Ready(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  struct IBuildingRole *BuildingRole; // eax
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // [esp-10h] [ebp-30h]
  int v14; // [esp-Ch] [ebp-2Ch]
  int v15; // [esp-Ch] [ebp-2Ch]
  int v16; // [esp-Ch] [ebp-2Ch]
  int v17; // [esp-8h] [ebp-28h]
  int v18; // [esp-8h] [ebp-28h]
  int v19; // [esp-8h] [ebp-28h]
  int v20; // [esp-8h] [ebp-28h]
  int v21; // [esp-8h] [ebp-28h]
  int v22; // [esp+8h] [ebp-18h] BYREF
  int v23; // [esp+Ch] [ebp-14h]
  unsigned __int8 *v24; // [esp+10h] [ebp-10h]
  int v25; // [esp+1Ch] [ebp-4h]

  v24 = this;
  v14 = IEntity::Type((unsigned __int16 *)this);
  v1 = IEntity::OwnerId(v24);
  CBuildingMgr::ChangeNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v1, v14, 0, -1);
  v15 = IEntity::Type((unsigned __int16 *)v24);
  v2 = IEntity::OwnerId(v24);
  CBuildingMgr::ChangeNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v2, v15, 1, 1);
  v17 = IEntity::Type((unsigned __int16 *)v24);
  v3 = IEntity::OwnerId(v24);
  CStatistic::AddBuilding((CStatistic *)&g_cStatistic, v3, v17, 1);
  v18 = IEntity::Type((unsigned __int16 *)v24);
  v4 = IEntity::OwnerId(v24);
  CStatistic::AddProducedBuilding((CStatistic *)&g_cStatistic, v4, v18, 1);
  v19 = IEntity::ID();
  v5 = IEntity::OwnerId(v24);
  (*(void (__thiscall **)(void *, int, int, int, _DWORD))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 6, v5, v19, 0);
  v20 = IEntity::Race(v24);
  v6 = CBuilding::BuildingTypeEx(v24);
  BuildingRole = CBuildingMgr::CreateBuildingRole(v6, v20, 0);
  std::auto_ptr<IBuildingRole>::auto_ptr<IBuildingRole>(&v22, (int)BuildingRole);
  v25 = 0;
  std::auto_ptr<IBuildingRole>::operator=(&v22);
  v23 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)v24 + 21);
  (*(void (__thiscall **)(int, unsigned __int8 *))(*(_DWORD *)v23 + 24))(v23, v24);
  IEntity::SetFlagBits(v24, (EntityFlag)0x10000u);
  if ( CBuilding::BuildingTypeEx(v24) == 34 )
  {
    v8 = IEntity::OwnerId(v24);
    if ( v8 == CPlayerManager::GetLocalPlayerId() )
    {
      v16 = IEntity::Y(v24);
      v13 = IEntity::X(v24);
      v9 = IEntity::OwnerId(v24);
      v10 = CPlayerManager::Color(v9);
      CTextMsgHandler::AddTextMsg(509, v10, v13, v16, 0, 0);
    }
  }
  v21 = IEntity::Y(v24);
  v11 = IEntity::X(v24);
  if ( !CWorldManager::FlagBits(v11, v21, 1u)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\Building.cpp",
         346,
         "g_cWorld.FlagBits(X(), Y(), FLAG_BLOCKED_LAND) != 0") == 1 )
  {
    __debugbreak();
  }
  v25 = -1;
  return std::auto_ptr<IBuildingRole>::~auto_ptr<IBuildingRole>(&v22);
}


// address=[0x14ea320]
// Decompiled from int __thiscall CBuilding::RemoveBuildingBits(CBuilding *this)
void  CBuilding::RemoveBuildingBits(void) {
  
  int v1; // eax
  int v2; // eax
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
  int v16; // [esp-10h] [ebp-CCh]
  int v17; // [esp-10h] [ebp-CCh]
  int v18; // [esp-Ch] [ebp-C8h]
  int v19; // [esp-Ch] [ebp-C8h]
  int v20; // [esp-8h] [ebp-C4h]
  int v21; // [esp-8h] [ebp-C4h]
  int v22; // [esp-4h] [ebp-C0h]
  char *v23; // [esp-4h] [ebp-C0h]
  int v24; // [esp-4h] [ebp-C0h]
  int v25; // [esp-4h] [ebp-C0h]
  int v26; // [esp-4h] [ebp-C0h]
  char *v27; // [esp-4h] [ebp-C0h]
  int v28; // [esp-4h] [ebp-C0h]
  int v29; // [esp-4h] [ebp-C0h]
  _DWORD v30[7]; // [esp+4h] [ebp-B8h] BYREF
  _BYTE v31[12]; // [esp+20h] [ebp-9Ch] BYREF
  _BYTE v32[12]; // [esp+2Ch] [ebp-90h] BYREF
  _DWORD v33[7]; // [esp+38h] [ebp-84h] BYREF
  int v34; // [esp+54h] [ebp-68h]
  int v35; // [esp+58h] [ebp-64h]
  int v36; // [esp+5Ch] [ebp-60h]
  int v37; // [esp+60h] [ebp-5Ch]
  int v38; // [esp+64h] [ebp-58h]
  int v39; // [esp+68h] [ebp-54h]
  std::_Iterator_base12 *v40; // [esp+6Ch] [ebp-50h]
  std::_Iterator_base12 *v41; // [esp+70h] [ebp-4Ch]
  int v42; // [esp+74h] [ebp-48h]
  int v43; // [esp+78h] [ebp-44h]
  _BYTE v44[12]; // [esp+7Ch] [ebp-40h] BYREF
  int v45; // [esp+88h] [ebp-34h]
  int v46; // [esp+8Ch] [ebp-30h]
  unsigned __int8 *v47; // [esp+90h] [ebp-2Ch]
  int v48; // [esp+94h] [ebp-28h]
  int i; // [esp+98h] [ebp-24h]
  int v50; // [esp+9Ch] [ebp-20h]
  char v51; // [esp+A3h] [ebp-19h]
  int v52; // [esp+A4h] [ebp-18h]
  _DWORD *v53; // [esp+A8h] [ebp-14h]
  char *BuildingInfo; // [esp+ACh] [ebp-10h]
  int v55; // [esp+B8h] [ebp-4h]

  v53 = this;
  v22 = CBuilding::BuildingTypeEx((unsigned __int8 *)this);
  v1 = IEntity::Race(v53);
  BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v1, v22);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v44);
  v55 = 0;
  v48 = 0;
  v2 = IEntity::X(v53);
  v38 = v2 + 32 - *BuildingInfo - 1;
  v3 = IEntity::Y(v53);
  v39 = v3 - BuildingInfo[1] - 1;
  v43 = std::vector<unsigned int>::begin(v32);
  v42 = v43;
  LOBYTE(v55) = 1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v43);
  LOBYTE(v55) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v32);
  while ( 1 )
  {
    v41 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v31);
    v40 = v41;
    LOBYTE(v55) = 2;
    v51 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v41);
    LOBYTE(v55) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v31);
    if ( !v51 )
      break;
    ++v48;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v44) )
    {
      v46 = v48 + v39;
      for ( i = 31; i >= 0; --i )
      {
        v4 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v44);
        if ( (*v4 & (1 << i)) != 0 )
        {
          v45 = v38 - i;
          v50 = CWorldManager::Index(v38 - i, v46);
          CWorldManager::SetMoveCount(v50, 10);
          CWorldManager::SetMoveCostsBits(v50, 2);
          CWorldManager::ClearFlagBits(v50, 58);
          if ( CWorldManager::PileId(v50) )
          {
            v5 = CWorldManager::PileId(v50);
            v47 = CPileMgr::operator[](v5);
            if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v47 + 40))(v47) > 0 )
            {
              CWorldManager::SetMoveCostsBits(v50, 7);
              CWorldManager::SetFlagBits(v50, 2u);
            }
          }
          CWorldManager::ClearBlockedPosition(v45, v46);
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v44);
  }
  if ( BuildingInfo[6] )
  {
    v23 = BuildingInfo + 816;
    v20 = BuildingInfo[1];
    v18 = *BuildingInfo;
    v16 = IEntity::Y(v53);
    v6 = IEntity::X(v53);
    CBuildingFlagsWalk::CBuildingFlagsWalk(v6, v16, v18, v20, v23);
    while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v33) )
    {
      v24 = CBuildingFlagsWalk::CurrentY(v33);
      v7 = CBuildingFlagsWalk::CurrentX(v33);
      v52 = CWorldManager::Index(v7, v24);
      if ( CWorldManager::IsWater(v52) )
      {
        v25 = CBuildingFlagsWalk::CurrentY(v33);
        v8 = CBuildingFlagsWalk::CurrentX(v33);
        (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 24))(g_pTiling, v8, v25);
        CWaterFlags::ClearWaterFlagBitRepelling(v52);
        CWorldManager::ClearFlagBits(v52, 8);
      }
      else
      {
        v26 = CBuildingFlagsWalk::CurrentY(v33);
        v9 = CBuildingFlagsWalk::CurrentX(v33);
        (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 20))(g_pTiling, v9, v26);
        if ( CWorldManager::PileId(v52) )
        {
          CWorldManager::SetMoveCostsBits(v52, 7);
          CWorldManager::ClearFlagBits(v52, 56);
          CWorldManager::SetFlagBits(v52, 2u);
        }
        else
        {
          CWorldManager::SetMoveCostsBits(v52, 2);
          CWorldManager::ClearFlagBits(v52, 58);
        }
      }
    }
    v27 = BuildingInfo + 832;
    v21 = BuildingInfo[1];
    v19 = *BuildingInfo;
    v17 = IEntity::Y(v53);
    v10 = IEntity::X(v53);
    CBuildingFlagsWalk::CBuildingFlagsWalk(v10, v17, v19, v21, v27);
    while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v30) )
    {
      v28 = CBuildingFlagsWalk::CurrentY(v30);
      v11 = CBuildingFlagsWalk::CurrentX(v30);
      v37 = CWorldManager::Index(v11, v28);
      v29 = CBuildingFlagsWalk::CurrentY(v33);
      v12 = CBuildingFlagsWalk::CurrentX(v33);
      (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 24))(g_pTiling, v12, v29);
      CWorldManager::ClearFlagBits(v37, 8);
    }
    v13 = IEntity::X(v53);
    v35 = BuildingInfo[42] + v13;
    v14 = IEntity::Y(v53);
    v36 = BuildingInfo[43] + v14;
    v34 = CWorldManager::Index(v35, v36);
    CWaterFlags::ClearWaterFlagBitRepelling(v34);
  }
  v55 = -1;
  return std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v44);
}


// address=[0x14eb340]
// Decompiled from int __thiscall CBuilding::ConvertEventIntoGoal(CBuilding *this, struct CEntityEvent *a2)
void  CBuilding::ConvertEventIntoGoal(class CEntityEvent *) {
  
  int v2; // eax

  v2 = std::auto_ptr<IBuildingRole>::operator->((_DWORD *)this + 21);
  return (*(int (__thiscall **)(int, CBuilding *, struct CEntityEvent *))(*(_DWORD *)v2 + 92))(v2, this, a2);
}


// address=[0x14eb3e0]
// Decompiled from void __thiscall CBuilding::DetachWithoutNotify(CBuilding *this, int a2)
void  CBuilding::DetachWithoutNotify(int) {
  
  CObserverList::Detach((CBuilding *)((char *)this + 88), a2);
}


