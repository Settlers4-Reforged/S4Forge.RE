#include "CHJBRole.h"

// Definitions for class CHJBRole

// address=[0x1400e00]
// Decompiled from int __cdecl CHJBRole::New(int a1)
class CPersistence * __cdecl CHJBRole::New(std::istream & a1) {
  
  if ( operator new(0x80u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CHJBRole::CHJBRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x1574e20]
// Decompiled from unsigned int *__thiscall CHJBRole::CHJBRole(unsigned int *this, struct std::istream *a2)
 CHJBRole::CHJBRole(std::istream & a2) {
  
  int pExceptionObject; // [esp+8h] [ebp-14h] BYREF
  unsigned int *v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  v4 = this;
  ((void (__stdcall *)(struct std::istream *))CSquadLeaderRole::CSquadLeaderRole)(a2);
  v5 = 0;
  *v4 = (unsigned int)&CHJBRole::_vftable_;
  v4[12] = (unsigned int)&CHJBRole::`vftable';
  if ( Serial::LoadVersion(a2) != 1 )
  {
    BBSupportTracePrintF(3, (char *)&dword_37AE128[1]);
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned int>(a2, v4 + 29);
  operator^<unsigned int>(a2, v4 + 30);
  operator^<unsigned int>(a2, v4 + 31);
  v5 = -1;
  return v4;
}


// address=[0x1574f10]
// Decompiled from int __thiscall CHJBRole::Store(int *this, struct std::ostream *a2)
void  CHJBRole::Store(std::ostream & a2) {
  
  ((void (__stdcall *)(struct std::ostream *))CSquadLeaderRole::Store)(a2);
  Serial::StoreVersion(a2, 1);
  operator^<unsigned int>(a2, (unsigned int *)this + 29);
  operator^<unsigned int>(a2, (unsigned int *)this + 30);
  return operator^<unsigned int>(a2, (unsigned int *)this + 31);
}


// address=[0x1575030]
// Decompiled from void __thiscall CHJBRole::LogicUpdateJob(CSoldierRole *this, struct CSettler *a2)
void  CHJBRole::LogicUpdateJob(class CSettler * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  char v6; // al
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int v10; // [esp-10h] [ebp-38h]
  int v11; // [esp-10h] [ebp-38h]
  int v12; // [esp-Ch] [ebp-34h]
  int v13; // [esp-8h] [ebp-30h]
  int v14; // [esp-4h] [ebp-2Ch]
  int v15; // [esp-4h] [ebp-2Ch]
  int NewHJBPosition; // [esp+4h] [ebp-24h]
  int v17; // [esp+Ch] [ebp-1Ch]
  int v18; // [esp+10h] [ebp-18h]
  int v19; // [esp+14h] [ebp-14h]
  int v20; // [esp+18h] [ebp-10h]
  int NearestEnemyFighter; // [esp+1Ch] [ebp-Ch]
  unsigned int TickCounter; // [esp+20h] [ebp-8h]

  if ( this->m_iU3 == 0 || (this->m_iU3 = 0, ((void (__thiscall *)(CSoldierRole *, struct CSettler *))this->ISelectableSettlerRole::ISettlerRole::CPersistence::__vftable[2].j_?WarriorInit@CWarriorBehavior@@UAEXAAVIMovingEntity@@HH@Z)(this, a2), this->m_iTask == 27) )
  {
    TickCounter = CStateGame::GetTickCounter(g_pGame);
    if ( TickCounter > *((_DWORD *)this + 30) )
    {
      *((_DWORD *)this + 30) += 20;
      if ( *((_DWORD *)this + 30) <= TickCounter )
      {
        *((_DWORD *)this + 30) = TickCounter + 10;
      }
      ((void (__thiscall *)(struct CSettler *, int))a2->j_?Increase@CSettler@@UAEHH@Z)(a2, 1);
    }
    if ( TickCounter <= *((_DWORD *)this + 31) )
    {
      goto LABEL_13;
    }
    v2 = IEntity::OwnerId(a2);
    v14 = CAlliances::AllianceId(v2);
    v13 = IEntity::Y(a2);
    v3 = IEntity::X(a2);
    if ( (int)CInfluMap::EnemyValueXY(v3, v13, v14) <= 0 || (v15 = IEntity::OwnerId(a2), v12 = IEntity::Y(a2), v4 = IEntity::X(a2), (NearestEnemyFighter = CScanner::FindNearestEnemyFighter(v4, v12, 13, v15)) <= 0) )
    {
LABEL_13:
      if ( IEntity::Hitpoints(a2) >= 8 )
      {
        if ( ((unsigned int)&byte_C00000 & IEntity::Flags(a2)) != 0 )
        {
          CSoldierRole::SoldierMagicIdleWalk(this, a2);
        }
        else
        {
          v9 = CGameData::GetTickCounter(g_pGameData);
          CWarriorBehavior::WarriorLogicUpdate(&this->CWarriorBehavior, a2, v9, 16);
        }
        if ( CWarriorBehavior::GetWarriorBehaviorData(&this->CWarriorBehavior)->m_uState != 0 || *((int *)this + 28) <= 0 )
        {
          *((_DWORD *)this + 28) = IEntity::PackedXY(a2);
        }
      }
      else
      {
        v6 = CStateGame::Rand(g_pGame);
        ((void (__thiscall *)(struct CSettler *, int))a2->j_?Increase@CSettler@@UAEHH@Z)(a2, (v6 & 0x40) + 24);
        v18 = (int)CLogic::Effects(g_pLogic);
        v10 = IEntity::Y(a2);
        v7 = IEntity::X(a2);
        (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v18 + 16))(v18, 76, 0, v7, v10, 0, 0, 0);
        a2->j_?RemoveFromMapObjectLayer@IEntity@@UAEXXZ((CPropertySet *)a2);
        NewHJBPosition = CHJBRole::FindNewHJBPosition((CHJBRole *)this, a2);
        a2->PlaceInMapObjectLayer(a2, NewHJBPosition);
        v17 = (int)CLogic::Effects(g_pLogic);
        v11 = IEntity::Y(a2);
        v8 = IEntity::X(a2);
        (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v17 + 16))(v17, 76, 0, v8, v11, 0, 0, 0);
        this->WarriorTaskFinished(&this->CWarriorBehavior, a2);
      }
    }
    else
    {
      *((_DWORD *)this + 31) += 50;
      if ( *((_DWORD *)this + 31) <= TickCounter )
      {
        *((_DWORD *)this + 31) = TickCounter + 10;
      }
      v19 = Y16X16::UnpackXFast(NearestEnemyFighter);
      v20 = Y16X16::UnpackYFast(NearestEnemyFighter);
      v5 = CWorldManager::MapObjectId(v19, v20);
      this->WarriorTaskAttack(&this->CWarriorBehavior, a2, v5, 4);
      CHJBRole::ExecuteAttackSpell((CHJBRole *)this, a2, v19, v20);
    }
  }
}


// address=[0x1575310]
// Decompiled from int __thiscall CHJBRole::Decrease(ISelectableSettlerRole *this, int a2)
int  CHJBRole::Decrease(int a2) {
  
  int v4; // [esp+4h] [ebp-8h]
  IEntity *v5; // [esp+8h] [ebp-4h]
  int v6; // [esp+14h] [ebp+8h]

  v6 = ISelectableSettlerRole::Decrease(this, a2);
  if ( v6 <= 0 )
  {
    return 0;
  }
  if ( v6 <= 3 )
  {
    v4 = 1;
  }
  else
  {
    v4 = v6 - 3;
  }
  v5 = CMapObjectMgr::EntityPtr(this->m_uAttachedSettlerId);
  if ( v5 == 0 )
  {
    return 0;
  }
  if ( IEntity::Hitpoints(v5) <= 1 )
  {
    return 0;
  }
  if ( v4 < IEntity::Hitpoints(v5) )
  {
    return v4;
  }
  return IEntity::Hitpoints(v5) - 1;
}


// address=[0x1575b90]
// Decompiled from int __thiscall CHJBRole::ClassID(CHJBRole *this)
unsigned long  CHJBRole::ClassID(void)const {
  
  return CHJBRole::m_iClassID;
}


// address=[0x1575c10]
// Decompiled from char __thiscall CHJBRole::IsHJB(CHJBRole *this)
bool  CHJBRole::IsHJB(void) {
  
  return 1;
}


// address=[0x15886c0]
// Decompiled from int __cdecl CHJBRole::Load(struct std::istream *a1)
class CHJBRole * __cdecl CHJBRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CHJBRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bee0]
// [Decompilation failed for static unsigned long CHJBRole::m_iClassID]

// address=[0x1574dd0]
// Decompiled from CHJBRole *__thiscall CHJBRole::CHJBRole(CHJBRole *this)
 CHJBRole::CHJBRole(void) {
  
  CSquadLeaderRole::CSquadLeaderRole(this);
  *(_DWORD *)this = &CHJBRole::_vftable_;
  *((_DWORD *)this + 12) = &CHJBRole::`vftable';
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  return this;
}


// address=[0x1574f70]
// Decompiled from void __thiscall CHJBRole::PostLoadInit(void *this, CPropertySet *a2)
void  CHJBRole::PostLoadInit(class CSettler * a2) {
  
  struct CFrameWnd *v2; // eax
  struct CFrameWnd *v3; // eax

  if ( a2 != 0 )
  {
    CSoldierRole::PostLoadInit(a2);
    if ( IEntity::FlagBits((IEntity *)a2, (EntityFlag)&s_iMsgTracer2.m_aMessages[15456]) == 0 )
    {
      if ( ((int (__cdecl *)(void *))IHJBMgr::GetHJBPlayerId)(this) != 0 && BBSupportDbgReport(2, "mapobjects\\settler\\HJBRole.cpp", 95, "g_pHJBMgr->GetHJBPlayerId() == PLAYER_NO_PLAYER") == 1 )
      {
        __debugbreak();
      }
      if ( ((int (__thiscall *)(_DWORD))IHJBMgr::GetHJBEntityId)(0) != -1 && BBSupportDbgReport(2, "mapobjects\\settler\\HJBRole.cpp", 96, "g_pHJBMgr->GetHJBEntityId() == -1") == 1 )
      {
        __debugbreak();
      }
      v2 = (struct CFrameWnd *)IEntity::OwnerId((IEntity *)a2);
      IHJBMgr::SetHJBPlayerId(v2);
      v3 = (struct CFrameWnd *)IEntity::EntityId((IEntity *)a2);
      IHJBMgr::SetHJBEntityId(v3);
      ((void (__thiscall *)(CHJBMgr *))g_pHJBMgr->j_?LocalLoadHJBGfxFileIfNecessary@CHJBMgr@@UAE_NXZ)(g_pHJBMgr);
    }
  }
}


// address=[0x15753b0]
// Decompiled from int __thiscall CHJBRole::FindNewHJBPosition(CHJBRole *this, struct CSettler *a2)
int  CHJBRole::FindNewHJBPosition(class CSettler * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v7; // [esp+8h] [ebp-74h]
  int v9; // [esp+10h] [ebp-6Ch]
  int v10; // [esp+14h] [ebp-68h]
  int v11; // [esp+1Ch] [ebp-60h]
  int v12; // [esp+20h] [ebp-5Ch]
  int v13; // [esp+28h] [ebp-54h]
  int v14; // [esp+2Ch] [ebp-50h]
  int v15; // [esp+30h] [ebp-4Ch]
  int v16; // [esp+34h] [ebp-48h]
  int v17; // [esp+38h] [ebp-44h]
  int v18; // [esp+3Ch] [ebp-40h]
  int v19; // [esp+48h] [ebp-34h]
  int i; // [esp+4Ch] [ebp-30h]
  _BYTE v21[4]; // [esp+50h] [ebp-2Ch] BYREF
  int v22; // [esp+54h] [ebp-28h]
  int v23; // [esp+58h] [ebp-24h]
  _BYTE v24[8]; // [esp+68h] [ebp-14h] BYREF
  int v25; // [esp+70h] [ebp-Ch]

  v14 = IEntity::X(a2);
  v15 = IEntity::Y(a2);
  v7 = CWorldManager::SectorId(v14, v15);
  v13 = -1;
  v9 = -1;
  v10 = -1000000;
  for ( i = 0;
        i < 12;
        ++i )
  {
    v19 = CStateGame::Rand(g_pGame);
    v12 = (v19 & 0x100) != 0 ? -((v19 & 0xF) + 32 - 2 * i) : (v19 & 0xF) + 32 - 2 * i;
    v11 = (v19 & 0x200) != 0 ? -(((v19 >> 4) & 0xF) + 32 - 2 * i) : ((v19 >> 4) & 0xF) + 32 - 2 * i;
    v16 = CHJBRole::FindNearFreePositionInSector(this, v12 + v14, v11 + v15, v7);
    if ( v16 > 0 )
    {
      v18 = Y16X16::UnpackXFast(v16);
      v17 = Y16X16::UnpackYFast(v16);
      v2 = IEntity::OwnerId(a2);
      CScanner::EvaluateFighters((struct SEvalFightersResult *)v21, v18, v17, 15, v2);
      v3 = IEntity::OwnerId(a2);
      CScanner::EvaluateTowers((struct SEvalTowersResult *)v24, v18, v17, 15, v3);
      v4 = Grid::Distance(v14 - v18, v15 - v17);
      if ( v22 + v4 - 2 * v23 - v25 > v10 )
      {
        v13 = v18;
        v9 = v17;
        v10 = v22 + v4 - 2 * v23 - v25;
        if ( i >= 6 )
        {
          break;
        }
      }
    }
  }
  if ( v13 <= 0 )
  {
    return IEntity::PackedXY(a2);
  }
  else
  {
    return Y16X16::PackXYFast(v13, v9);
  }
}


// address=[0x15755d0]
// Decompiled from int __thiscall CHJBRole::FindNearFreePositionInSector(CHJBRole *this, int a2, int a3, int a4)
int  CHJBRole::FindNearFreePositionInSector(int a2, int a3, int a4) {
  
  _BYTE v5[20]; // [esp+0h] [ebp-2Ch] BYREF
  CHJBRole *v6; // [esp+14h] [ebp-18h]
  int v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+20h] [ebp-Ch] BYREF
  int v10; // [esp+24h] [ebp-8h] BYREF
  int v11; // [esp+28h] [ebp-4h]

  v6 = this;
  if ( a4 <= 0 )
  {
    return -1;
  }
  CSectorSpiralWalk::CSectorSpiralWalk((CSectorSpiralWalk *)v5, a2, a3, 15, a4);
  v11 = -1;
  v8 = -1;
  while ( CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v5, &v10, &v9) )
  {
    if ( CWorldManager::MapObjectId(v10, v9) == 0 )
    {
      if ( CWorldManager::CatapultTileId(v10, v9) > 0 )
      {
        v11 = v10;
        v8 = v9;
        break;
      }
      if ( v11 < 0 )
      {
        v11 = v10;
        v8 = v9;
      }
    }
  }
  if ( v11 < 0 )
  {
    return -1;
  }
  else
  {
    return Y16X16::PackXYFast(v11, v8);
  }
}


// address=[0x15756a0]
// Decompiled from char __thiscall CHJBRole::ExecuteAttackSpell(CHJBRole *this, struct CSettler *a2, int a3, int a4)
void  CHJBRole::ExecuteAttackSpell(class CSettler * a2, int a3, int a4) {
  
  int v4; // eax
  char result; // al
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // [esp-10h] [ebp-60h]
  int v10; // [esp-4h] [ebp-54h]
  _DWORD v11[13]; // [esp+4h] [ebp-4Ch] BYREF
  unsigned int v12; // [esp+38h] [ebp-18h]
  int v13; // [esp+3Ch] [ebp-14h]
  int v14; // [esp+40h] [ebp-10h]
  int v15; // [esp+44h] [ebp-Ch]
  int v16; // [esp+48h] [ebp-8h]
  struct IEntity *v17; // [esp+4Ch] [ebp-4h] BYREF

  v11[12] = this;
  v15 = (int)CLogic::Effects(g_pLogic);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v15 + 16))(v15, 42, 0, a3, a4, 0, 0, 0);
  v4 = IEntity::OwnerId(a2);
  v13 = CAlliances::PlayerEnemyBits(v4);
  v11[11] = 252;
  v11[10] = 12;
  v11[9] = 8;
  v11[8] = 6;
  v16 = 0;
  CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk((CWarriorEntitySpiralWalk *)v11, a3, a4, 6, v13, 252);
  do
  {
    result = CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v11, &v17);
    if ( result == 0 )
    {
      break;
    }
    v12 = CStateGame::Rand(g_pGame) % 8 + 12;
    v6 = IEntity::OwnerId(v17);
    if ( v6 == CPlayerManager::GetLocalPlayerId() )
    {
      v10 = IEntity::Y(v17);
      v7 = IEntity::X(v17);
      CAttackMsgList::SendAttackMessage((CAttackMsgList *)&g_cAttackMsgList, v7, v10);
    }
    ((void (__thiscall *)(struct IEntity *, unsigned int))v17->Decrease)(v17, v12);
    v14 = (int)CLogic::Effects(g_pLogic);
    v9 = CSettlerSpiralWalk::CurrentY(v11);
    v8 = CSettlerSpiralWalk::CurrentX(v11);
    result = (*(int (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v14 + 16))(v14, 56, 0, v8, v9, 0, 0, 0);
    ++v16;
  }
  while ( v16 < 6 );
  return result;
}


// address=[0x1575a80]
// Decompiled from void __thiscall CHJBRole::~CHJBRole(CHJBRole *this)
 CHJBRole::~CHJBRole(void) {
  
  *(_DWORD *)this = &CHJBRole::_vftable_;
  *((_DWORD *)this + 12) = &CHJBRole::`vftable';
  CSquadLeaderRole::~CSquadLeaderRole(this);
}


