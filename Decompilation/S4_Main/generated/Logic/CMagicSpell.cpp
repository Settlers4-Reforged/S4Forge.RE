#include "CMagicSpell.h"

// Definitions for class CMagicSpell

// address=[0x146c970]
// Decompiled from int __thiscall CMagicSpell::SettlerFlagBitChange(_DWORD *this, int a2, int a3, EntityFlag a4, int a5, int a6)
int  CMagicSpell::SettlerFlagBitChange(int a2, int a3, int a4, int a5, enum SIV_SOUNDS a6) {
  
  int v6; // eax
  int v7; // eax
  int v9; // [esp-10h] [ebp-48h]
  _DWORD v10[8]; // [esp+0h] [ebp-38h] BYREF
  int v11; // [esp+20h] [ebp-18h]
  int v12; // [esp+24h] [ebp-14h]
  int v13; // [esp+28h] [ebp-10h]
  struct IEntity *v14; // [esp+2Ch] [ebp-Ch] BYREF
  int v15; // [esp+30h] [ebp-8h]
  _DWORD *v16; // [esp+34h] [ebp-4h]

  v16 = this;
  v15 = 0;
  CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk((CWarriorEntitySpiralWalk *)v10, this[2], this[3], this[4], a2, a3);
  while ( CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v10, &v14) )
  {
    if ( !IEntity::FlagBits(v14, a4) )
    {
      IEntity::SetFlagBits(v14, a4);
      v13 = CLogic::FutureEvents(g_pLogic);
      v6 = IEntity::ID();
      (*(void (__thiscall **)(int, int, _DWORD, int, _DWORD, EntityFlag))(*(_DWORD *)v13 + 12))(
        v13,
        1,
        v16[6],
        v6,
        0,
        a4);
      if ( a5 )
      {
        v12 = CLogic::Effects((DWORD *)g_pLogic);
        v9 = CSettlerSpiralWalk::CurrentY(v10);
        v7 = CSettlerSpiralWalk::CurrentX(v10);
        (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
          v12,
          a5,
          0,
          v7,
          v9,
          0,
          0,
          0);
      }
      if ( ++v15 >= v16[5] )
        break;
    }
  }
  if ( v15 <= 0 || !a6 )
    return v15;
  v11 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v11 + 16))(
    v11,
    0,
    a6,
    v16[2],
    v16[3],
    0,
    0,
    0);
  return v15;
}


// address=[0x146cac0]
// Decompiled from int __thiscall CMagicSpell::SpellDoNothing(CMagicSpell *this)
int  CMagicSpell::SpellDoNothing(void) {
  
  return 0;
}


// address=[0x146cad0]
// Decompiled from int __thiscall CMagicSpell::SpellDivinePresent(_DWORD *this)
int  CMagicSpell::SpellDivinePresent(void) {
  
  int v1; // eax
  unsigned int v2; // eax
  int *v3; // eax
  unsigned int v4; // eax
  _DWORD *v6; // [esp+10h] [ebp-60h]
  int v7; // [esp+24h] [ebp-4Ch]
  int v8; // [esp+28h] [ebp-48h]
  int v9; // [esp+2Ch] [ebp-44h]
  int v10; // [esp+3Ch] [ebp-34h]
  int v11; // [esp+40h] [ebp-30h] BYREF
  int v12; // [esp+44h] [ebp-2Ch] BYREF
  int v13; // [esp+48h] [ebp-28h]
  int v14; // [esp+4Ch] [ebp-24h]
  int v15; // [esp+50h] [ebp-20h]
  int i; // [esp+54h] [ebp-1Ch]
  int v17; // [esp+58h] [ebp-18h]
  int v18; // [esp+5Ch] [ebp-14h]
  _DWORD *v19; // [esp+60h] [ebp-10h]
  int j; // [esp+64h] [ebp-Ch]
  int v21; // [esp+68h] [ebp-8h]
  char v22; // [esp+6Fh] [ebp-1h]

  v19 = this;
  v15 = 0;
  CSpiralWalk::CSpiralWalk(this[2], this[3], this[4]);
  while ( (unsigned __int8)CSpiralWalk::NextXY(&v11, &v12) )
  {
    v18 = CWorldManager::Index(v11, v12);
    if ( !CWorldManager::FlagBits(v18, 51) && !CWorldManager::MapObjectId(v18) && !CWorldManager::ObjectId(v18) )
    {
      v14 = CWorldManager::Ground(v18) & 0xF0;
      if ( v14 == 16 || v14 == 64 || v14 == 144 )
      {
        v22 = 1;
        for ( i = 0; i < 6; ++i )
        {
          v1 = CWorldManager::NeighborRelIndex(i);
          if ( CWorldManager::PileId(v18 + v1) )
          {
            v22 = 0;
            break;
          }
        }
        if ( v22 )
        {
          j = 0;
          v17 = *(_DWORD *)TStaticConfigIntArrayBase<8>::operator[](7);
          if ( v17 <= 0 )
          {
            v17 = 0;
          }
          else
          {
            v2 = CStateGame::Rand(g_pGame);
            v17 = v2 % v17;
          }
          for ( j = 0; j < 8; ++j )
          {
            v3 = (int *)TStaticConfigIntArrayBase<8>::operator[](j);
            if ( v17 < *v3 )
              break;
          }
          v13 = *(_DWORD *)TStaticConfigIntArrayBase<8>::operator[](j);
          if ( v13 < 43 && v13 > 0 )
          {
            v21 = *(_DWORD *)TStaticConfigIntArrayBase<8>::operator[](j);
            if ( v21 <= 1 )
            {
              v21 = 1;
            }
            else
            {
              v4 = CStateGame::Rand(g_pGame);
              v21 -= v4 % ((v21 + 2) >> 1);
            }
            if ( v21 > 8 )
              v21 = 8;
            if ( v21 < 1 && BBSupportDbgReport(2, (int)"Logic\\Magic.cpp", 1253, (int)"iAmount >= 1") == 1 )
              __debugbreak();
            v10 = CPileMgr::AddPile(v11, v12, v13, v21, 3, 0, 0, 0, 0);
            if ( v10 )
            {
              v6 = (_DWORD *)CMapObjectMgr::Entity(v10);
              IEntity::SetFlagBits(v6, EntityFlag_MagicInvisible);
              v8 = CStateGame::Rand(g_pGame) & 3;
              v9 = CLogic::Effects((DWORD *)g_pLogic);
              (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v9 + 16))(
                v9,
                24,
                0,
                v11,
                v12,
                v8,
                0,
                0);
              v7 = CLogic::FutureEvents(g_pLogic);
              (*(void (__thiscall **)(int, int, int, int, _DWORD, int))(*(_DWORD *)v7 + 12))(
                v7,
                1,
                v8 + 4,
                v10,
                0,
                0x80000);
              if ( ++v15 >= v19[5] )
                break;
            }
          }
        }
      }
    }
  }
  return v15;
}


// address=[0x146ce20]
// Decompiled from int __thiscall CMagicSpell::SpellConvertGood(CMagicSpell *this)
int  CMagicSpell::SpellConvertGood(void) {
  
  int v1; // eax
  _DWORD v3[4]; // [esp+0h] [ebp-54h] BYREF
  int v4; // [esp+10h] [ebp-44h]
  int v5; // [esp+14h] [ebp-40h]
  int v6; // [esp+18h] [ebp-3Ch]
  int v7; // [esp+1Ch] [ebp-38h]
  int v8; // [esp+20h] [ebp-34h]
  int v9; // [esp+24h] [ebp-30h] BYREF
  int v10; // [esp+28h] [ebp-2Ch] BYREF
  int v11; // [esp+2Ch] [ebp-28h]
  int v12; // [esp+30h] [ebp-24h]
  int v13; // [esp+34h] [ebp-20h]
  int v14; // [esp+38h] [ebp-1Ch]
  unsigned int v15; // [esp+3Ch] [ebp-18h]
  unsigned int v16; // [esp+40h] [ebp-14h]
  int v17; // [esp+44h] [ebp-10h]
  CPile *v18; // [esp+48h] [ebp-Ch]
  CMagicSpell *v19; // [esp+4Ch] [ebp-8h]

  v19 = this;
  v17 = 0;
  v16 = CStaticConfigVarInt::operator int(*(&off_36B70E8 + *((_DWORD *)this + 1)));
  v15 = CStaticConfigVarInt::operator int(*(&off_36B70FC + *((_DWORD *)v19 + 1)));
  if ( !v16 || v16 >= 0x2B || !v15 || v15 >= 0x2B )
    return v17;
  if ( *((int *)v19 + 5) < 10 )
    v13 = 8;
  else
    v13 = *((_DWORD *)v19 + 5) - 2;
  v4 = v13;
  if ( *((int *)v19 + 5) < 8 )
    v12 = 10;
  else
    v12 = *((_DWORD *)v19 + 5) + 2;
  v6 = v12;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v3, *((_DWORD *)v19 + 2), *((_DWORD *)v19 + 3), *((_DWORD *)v19 + 4));
  while ( CSpiralWalk::NextXY(v3, &v9, &v10) )
  {
    v7 = CWorldManager::Index(v9, v10);
    v11 = CWorldManager::PileId(v7);
    if ( v11 )
    {
      v18 = (CPile *)CPileMgr::operator[](v11);
      v1 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)v18 + 60))(v18);
      if ( v1 == v16 )
      {
        v14 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)v18 + 40))(v18);
        if ( v14 < 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1346, "iPileAmount >= 0") == 1 )
          __debugbreak();
        if ( v14 + v17 <= v6 )
        {
          if ( (unsigned __int8)CPile::ChangeGoodTypeUnforseen(v18, v15) )
          {
            LOBYTE(v5) = CStateGame::Rand(g_pGame) & 3;
            v5 = (unsigned __int8)v5;
            v8 = CLogic::Effects((DWORD *)g_pLogic);
            (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v8 + 16))(
              v8,
              27,
              0,
              v9,
              v10,
              v5,
              0,
              0);
            v17 += v14;
            if ( v17 >= v4 )
              break;
          }
        }
      }
    }
  }
  return v17;
}


// address=[0x146d010]
// Decompiled from unsigned int __thiscall CMagicSpell::SpellConvertTerrain(CMagicSpell *this)
int  CMagicSpell::SpellConvertTerrain(void) {
  
  _DWORD v2[4]; // [esp+0h] [ebp-54h] BYREF
  void *v3; // [esp+10h] [ebp-44h]
  int v4; // [esp+14h] [ebp-40h]
  int v5; // [esp+18h] [ebp-3Ch]
  signed int v6; // [esp+1Ch] [ebp-38h]
  int v7; // [esp+20h] [ebp-34h]
  int v8; // [esp+24h] [ebp-30h] BYREF
  int v9; // [esp+28h] [ebp-2Ch] BYREF
  BOOL v10; // [esp+2Ch] [ebp-28h]
  BOOL v11; // [esp+30h] [ebp-24h]
  BOOL v12; // [esp+34h] [ebp-20h]
  int v13; // [esp+38h] [ebp-1Ch]
  int v14; // [esp+3Ch] [ebp-18h]
  int v15; // [esp+40h] [ebp-14h]
  int v16; // [esp+44h] [ebp-10h]
  signed int i; // [esp+48h] [ebp-Ch]
  unsigned int v18; // [esp+4Ch] [ebp-8h]
  CMagicSpell *v19; // [esp+50h] [ebp-4h]

  v19 = this;
  v18 = -1;
  v13 = CStaticConfigVarInt::operator int(*(&off_36B7110 + *((_DWORD *)this + 1)));
  v5 = CStaticConfigVarInt::operator int(*(&off_36B7124 + *((_DWORD *)v19 + 1)));
  v6 = *((_DWORD *)v19 + 4);
  v14 = v13 & 0xF0;
  if ( (v13 & 0xF0) == 0 || v13 == v5 )
    v14 = -1;
  v15 = *((_DWORD *)v19 + 4) - 2;
  if ( v15 < 0 )
    v15 = 0;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v2, *((_DWORD *)v19 + 2), *((_DWORD *)v19 + 3), v15);
  while ( CSpiralWalk::NextXY(v2, &v8, &v9) )
  {
    v4 = CWorldManager::Index(v8, v9);
    v16 = CWorldManager::Ground(v4);
    v12 = v16 == 128;
    v11 = v16 == 129;
    v10 = v16 == 35;
    if ( v10 || v11 || v12 )
    {
      v18 = 0;
      break;
    }
    if ( CWorldManager::FlagBits(v8, v9, 4u) )
    {
      v18 = 4;
      v6 = 5;
      break;
    }
    if ( (v16 & 0xF0) == v14 )
    {
      v18 = *((_DWORD *)v19 + 1) + 1;
      break;
    }
  }
  if ( v18 == -1 )
    return v18;
  v7 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 16))(
    v7,
    30,
    0,
    *((_DWORD *)v19 + 2),
    *((_DWORD *)v19 + 3),
    0,
    0,
    0);
  v3 = (void *)CLogic::FutureEvents(g_pLogic);
  for ( i = 0; i <= v6; ++i )
    IFutureEvents::AddFutureEvent16(v3, 4, i + 1, 0, *((_DWORD *)v19 + 2), *((_DWORD *)v19 + 3), i, v18);
  return v18;
}


// address=[0x146d220]
// Decompiled from int __thiscall CMagicSpell::SpellFoodMoreFish(CMagicSpell *this)
int  CMagicSpell::SpellFoodMoreFish(void) {
  
  char v1; // al
  _DWORD v3[5]; // [esp+0h] [ebp-40h] BYREF
  int v4; // [esp+14h] [ebp-2Ch]
  int v5; // [esp+18h] [ebp-28h] BYREF
  int v6[2]; // [esp+1Ch] [ebp-24h] BYREF
  int v7; // [esp+24h] [ebp-1Ch]
  int v8; // [esp+28h] [ebp-18h]
  int v9; // [esp+2Ch] [ebp-14h]
  int v10; // [esp+30h] [ebp-10h]
  int v11; // [esp+34h] [ebp-Ch]
  int v12; // [esp+38h] [ebp-8h]
  CMagicSpell *v13; // [esp+3Ch] [ebp-4h]

  v13 = this;
  v11 = 0;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v3, *((_DWORD *)this + 2), *((_DWORD *)this + 3), *((_DWORD *)this + 4));
  while ( CSpiralWalk::NextXY(v3, &v5, v6) )
  {
    v8 = CWorldManager::Index(v5, v6[0]);
    v4 = CWorldManager::Ground(v8);
    if ( (v4 & 0xF0) == 0 )
    {
      v7 = CWorldManager::Resource(v8);
      v9 = v7 & 0xF;
      v3[4] = v7 & 0xF0;
      if ( (v7 & 0xF0) != 0 && v9 || v9 >= 15 )
      {
        if ( !v11 )
          v11 = 1;
      }
      else
      {
        v1 = CStateGame::Rand(g_pGame);
        v6[1] = v1 & 3;
        v10 = ((unsigned __int8)(v1 & 2) >> 1) + v9 + (v1 & 1) + 1;
        if ( v10 > 15 )
          v10 = 15;
        if ( v10 <= v9
          && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1537, "iNewResourceAmount > iOldResourceAmount") == 1 )
        {
          __debugbreak();
        }
        CWorldManager::SetResource(v8, 0, v10);
        v11 += v10 - v9;
        if ( v11 >= *((_DWORD *)v13 + 5) )
          break;
      }
    }
  }
  if ( v11 <= 0 )
    return v11;
  v12 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
    v12,
    48,
    0,
    *((_DWORD *)v13 + 2),
    *((_DWORD *)v13 + 3),
    0,
    0,
    0);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
    v12,
    48,
    0,
    *((_DWORD *)v13 + 2) - 2,
    *((_DWORD *)v13 + 3) + 1,
    3,
    0,
    0);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
    v12,
    48,
    0,
    *((_DWORD *)v13 + 2) - 1,
    *((_DWORD *)v13 + 3) - 3,
    6,
    0,
    0);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
    v12,
    48,
    0,
    *((_DWORD *)v13 + 2) + 1,
    *((_DWORD *)v13 + 3) - 1,
    10,
    0,
    0);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
    v12,
    48,
    0,
    *((_DWORD *)v13 + 2) + 3,
    *((_DWORD *)v13 + 3) + 2,
    13,
    0,
    0);
  return v11;
}


// address=[0x146d460]
// Decompiled from int __thiscall CMagicSpell::SpellDefenceShield(CMagicSpell *this)
int  CMagicSpell::SpellDefenceShield(void) {
  
  int v2; // [esp+8h] [ebp-8h]

  v2 = CAlliances::PlayerAllyBits(*(_DWORD *)this);
  return CMagicSpell::SettlerFlagBitChange(this, v2, 60, (EntityFlag)0x200000u, 54, 0);
}


// address=[0x146d4b0]
// Decompiled from int __thiscall CMagicSpell::SpellAttackLightningBolt(CMagicSpell *this)
int  CMagicSpell::SpellAttackLightningBolt(void) {
  
  unsigned int v1; // eax
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v6; // [esp-10h] [ebp-60h]
  int v7; // [esp-4h] [ebp-54h]
  int v8; // [esp+0h] [ebp-50h]
  _DWORD v9[9]; // [esp+4h] [ebp-4Ch] BYREF
  unsigned int v10; // [esp+28h] [ebp-28h]
  int v11; // [esp+2Ch] [ebp-24h]
  int v12; // [esp+30h] [ebp-20h]
  unsigned int v13; // [esp+34h] [ebp-1Ch]
  int v14; // [esp+38h] [ebp-18h]
  int v15; // [esp+3Ch] [ebp-14h]
  int v16; // [esp+40h] [ebp-10h]
  int v17; // [esp+44h] [ebp-Ch]
  CMagicSpell *v18; // [esp+48h] [ebp-8h]
  struct IEntity *v19; // [esp+4Ch] [ebp-4h] BYREF

  v18 = this;
  v11 = CAlliances::PlayerEnemyBits(*(_DWORD *)this);
  v9[8] = 252;
  if ( CStaticConfigVarInt::operator int(&unk_3F200BC) <= 0 )
    v15 = 1;
  else
    v15 = CStaticConfigVarInt::operator int(&unk_3F200BC);
  v16 = v15;
  if ( CStaticConfigVarInt::operator int(&unk_3F200C8) < v15 )
    v14 = 1;
  else
    v14 = CStaticConfigVarInt::operator int(&unk_3F200C8) - v16 + 1;
  v13 = v14;
  if ( v14 <= 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1604, "iDamageMod > 0") == 1 )
    __debugbreak();
  v17 = 0;
  CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk(
    (CWarriorEntitySpiralWalk *)v9,
    *((_DWORD *)v18 + 2),
    *((_DWORD *)v18 + 3),
    *((_DWORD *)v18 + 4),
    v11,
    252);
  do
  {
    if ( !CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v9, &v19) )
      break;
    v1 = CStateGame::Rand(g_pGame);
    v10 = v16 + v1 % v13;
    v2 = IEntity::OwnerId((unsigned __int8 *)v19);
    if ( v2 == CPlayerManager::GetLocalPlayerId(v8) )
    {
      v7 = IEntity::Y(v19);
      v3 = IEntity::X(v19);
      CAttackMsgList::SendAttackMessage((CAttackMsgList *)&g_cAttackMsgList, v3, v7);
    }
    ((void (__thiscall *)(struct IEntity *, unsigned int))v19->NamedEntities)(v19, v10);
    v12 = CLogic::Effects((DWORD *)g_pLogic);
    v6 = CSettlerSpiralWalk::CurrentY(v9);
    v4 = CSettlerSpiralWalk::CurrentX(v9);
    (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
      v12,
      54,
      0,
      v4,
      v6,
      0,
      0,
      0);
    ++v17;
  }
  while ( v17 < *((_DWORD *)v18 + 5) );
  return v17;
}


// address=[0x146d650]
// Decompiled from int __thiscall CMagicSpell::SpellSoldierConvertBarbarians(CMagicSpell *this)
int  CMagicSpell::SpellSoldierConvertBarbarians(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // [esp-10h] [ebp-68h]
  int v5; // [esp-10h] [ebp-68h]
  int v6; // [esp-Ch] [ebp-64h]
  int v7; // [esp-8h] [ebp-60h]
  _DWORD v8[10]; // [esp+0h] [ebp-58h] BYREF
  int v9; // [esp+28h] [ebp-30h]
  struct IEntity *v10; // [esp+2Ch] [ebp-2Ch]
  int v11; // [esp+30h] [ebp-28h]
  int v12; // [esp+34h] [ebp-24h]
  int v13; // [esp+38h] [ebp-20h]
  int v14; // [esp+3Ch] [ebp-1Ch]
  int v15; // [esp+40h] [ebp-18h]
  int v16; // [esp+44h] [ebp-14h]
  int v17; // [esp+48h] [ebp-10h]
  CMagicSpell *v18; // [esp+4Ch] [ebp-Ch]
  struct IEntity *v19; // [esp+50h] [ebp-8h] BYREF
  int v20; // [esp+54h] [ebp-4h]

  v18 = this;
  v11 = CAlliances::PlayerEnemyBits(*(_DWORD *)this);
  v8[9] = 60;
  v16 = 0;
  CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk(
    (CWarriorEntitySpiralWalk *)v8,
    *((_DWORD *)v18 + 2),
    *((_DWORD *)v18 + 3),
    *((_DWORD *)v18 + 4),
    v11,
    60);
  while ( CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v8, &v19) )
  {
    if ( IEntity::ObjType((unsigned __int8 *)v19) == 1 )
    {
      v10 = v19;
      v14 = CSettler::Role(v19);
      v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(v14);
      if ( v13 == 7 || v13 == 23 )
      {
        v15 = IEntity::Type((unsigned __int16 *)v19);
        v20 = 0;
        v17 = v15 - 29;
        switch ( v15 )
        {
          case 29:
          case 30:
          case 31:
          case 32:
          case 33:
          case 34:
          case 44:
            v20 = v15;
            break;
          case 35:
          case 38:
          case 41:
          case 61:
            v20 = 35;
            break;
          case 36:
          case 39:
          case 42:
          case 62:
            v20 = 36;
            break;
          case 37:
          case 40:
          case 43:
          case 63:
            v20 = 37;
            break;
          default:
            v20 = 0;
            break;
        }
        if ( v20 )
        {
          v8[8] = ((int (__thiscall *)(struct IEntity *))v19->DefaultPhrase)(v19);
          CMagicSpell::InvisibleKill(v19);
          v7 = v20;
          v6 = *(_DWORD *)v18;
          v4 = CSettlerSpiralWalk::CurrentY(v8);
          v1 = CSettlerSpiralWalk::CurrentX(v8);
          v9 = CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v1, v4, v6, v7, 2);
          if ( !v9 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1744, "iNewSettlerId != 0") == 1 )
            __debugbreak();
          v12 = CLogic::Effects((DWORD *)g_pLogic);
          v5 = CSettlerSpiralWalk::CurrentY(v8);
          v2 = CSettlerSpiralWalk::CurrentX(v8);
          (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
            v12,
            55,
            0,
            v2,
            v5,
            0,
            0,
            0);
          if ( ++v16 >= *((_DWORD *)v18 + 5) )
            break;
        }
      }
    }
  }
  return v16;
}


// address=[0x146d870]
// Decompiled from int __thiscall CMagicSpell::SpellSpecialMoreResources(CMagicSpell *this)
int  CMagicSpell::SpellSpecialMoreResources(void) {
  
  int v1; // esi
  _DWORD v3[4]; // [esp+4h] [ebp-48h] BYREF
  int v4; // [esp+14h] [ebp-38h]
  int v5; // [esp+18h] [ebp-34h]
  int v6; // [esp+1Ch] [ebp-30h] BYREF
  int v7; // [esp+20h] [ebp-2Ch] BYREF
  int v8; // [esp+24h] [ebp-28h]
  BOOL v9; // [esp+28h] [ebp-24h]
  BOOL v10; // [esp+2Ch] [ebp-20h]
  int v11; // [esp+30h] [ebp-1Ch]
  int v12; // [esp+34h] [ebp-18h]
  int v13; // [esp+38h] [ebp-14h]
  int v14; // [esp+3Ch] [ebp-10h]
  int v15; // [esp+40h] [ebp-Ch]
  int v16; // [esp+44h] [ebp-8h]
  CMagicSpell *v17; // [esp+48h] [ebp-4h]

  v17 = this;
  v15 = 0;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v3, *((_DWORD *)this + 2), *((_DWORD *)this + 3), *((_DWORD *)this + 4));
  while ( CSpiralWalk::NextXY(v3, &v6, &v7) )
  {
    v12 = CWorldManager::Index(v6, v7);
    v5 = CWorldManager::Ground(v12);
    if ( (v5 & 0xF0) == 0x20 )
    {
      v11 = CWorldManager::Resource(v12);
      v14 = v11 & 0xF;
      v4 = v11 & 0xF0;
      v10 = v14 != 0;
      v9 = (unsigned int)v14 < 0xF;
      if ( v9 && v10 )
      {
        v1 = v14 + (v14 >> 2);
        v13 = v1 + (CStateGame::Rand(g_pGame) & 3) + 1;
        if ( v13 > 15 )
          v13 = 15;
        if ( v13 <= v14
          && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1810, "iNewResourceAmount > iOldResourceAmount") == 1 )
        {
          __debugbreak();
        }
        CWorldManager::SetResource(v12, v4, v13);
        v15 += v13 - v14;
        if ( v15 >= *((_DWORD *)v17 + 5) )
          break;
      }
      else
      {
        v8 = v15 == 0;
        v15 += v8;
      }
    }
  }
  if ( v15 <= 0 )
    return v15;
  v16 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v16 + 16))(
    v16,
    36,
    0,
    *((_DWORD *)v17 + 2),
    *((_DWORD *)v17 + 3),
    0,
    0,
    0);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v16 + 16))(
    v16,
    36,
    0,
    *((_DWORD *)v17 + 2) - 2,
    *((_DWORD *)v17 + 3) + 1,
    3,
    0,
    0);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v16 + 16))(
    v16,
    36,
    0,
    *((_DWORD *)v17 + 2) - 1,
    *((_DWORD *)v17 + 3) - 3,
    6,
    0,
    0);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v16 + 16))(
    v16,
    36,
    0,
    *((_DWORD *)v17 + 2) + 1,
    *((_DWORD *)v17 + 3) - 1,
    10,
    0,
    0);
  (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v16 + 16))(
    v16,
    36,
    0,
    *((_DWORD *)v17 + 2) + 3,
    *((_DWORD *)v17 + 3) + 2,
    13,
    0,
    0);
  return v15;
}


// address=[0x146dae0]
// Decompiled from int __thiscall CMagicSpell::SpellFoodMoreGame(_DWORD *this)
int  CMagicSpell::SpellFoodMoreGame(void) {
  
  int v1; // eax
  _DWORD spiral[4]; // [esp+0h] [ebp-44h] BYREF
  int v4; // [esp+10h] [ebp-34h]
  _DWORD *v5; // [esp+14h] [ebp-30h]
  int v6; // [esp+18h] [ebp-2Ch]
  int v7; // [esp+1Ch] [ebp-28h]
  int v8; // [esp+20h] [ebp-24h]
  int x; // [esp+24h] [ebp-20h] BYREF
  int y; // [esp+28h] [ebp-1Ch] BYREF
  int v11; // [esp+2Ch] [ebp-18h]
  int i; // [esp+34h] [ebp-10h]
  int v14; // [esp+38h] [ebp-Ch]
  int v15; // [esp+3Ch] [ebp-8h]
  char v16; // [esp+43h] [ebp-1h]

  v14 = 0;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)spiral, this[2], this[3], this[4]);
  while ( CSpiralWalk::NextXY(spiral, &x, &y) )
  {
    v15 = CWorldManager::Index(x, y);
    v7 = CWorldManager::Ground(v15);
    if ( (v7 & 0xF0) == 0x10
      && !(unsigned __int8)CWorldManager::IsBlockedLand(v15)
      && !CWorldManager::MapObjectId(v15)
      && !CWorldManager::ObjectId(v15) )
    {
      v16 = 1;
      for ( i = 1; i < 19; ++i )
      {
        v1 = CWorldManager::SurroundingHexPointRelIndex(i);
        v6 = v15 + v1;
        if ( CWorldManager::OccupyingEntityId(v15 + v1) )
        {
          v16 = 0;
          break;
        }
      }
      if ( v16 )
      {
        v11 = CAnimalMgr::AddAnimal(x, y, 5);
        if ( v11 )
        {
          v5 = (_DWORD *)CMapObjectMgr::Entity(v11);
          IEntity::SetFlagBits(v5, EntityFlag_MagicInvisible);
          v4 = v14 & 7;
          v8 = CLogic::FutureEvents(g_pLogic);
          (*(void (__thiscall **)(int, int, int, int, _DWORD, int))(*(_DWORD *)v8 + 12))(v8, 1, v4 + 4, v11, 0, 0x80000);
          if ( ++v14 >= this[5] )
            break;
        }
      }
    }
  }
  return v14;
}


// address=[0x146dc80]
// Decompiled from int __thiscall CMagicSpell::SpellDefenceFreezeFoes(CMagicSpell *this)
int  CMagicSpell::SpellDefenceFreezeFoes(void) {
  
  int v2; // [esp+8h] [ebp-8h]

  v2 = CAlliances::PlayerEnemyBits(*(_DWORD *)this);
  return CMagicSpell::SettlerFlagBitChange(this, v2, 60, (EntityFlag)dword_800000, 45, 0);
}


// address=[0x146dcd0]
// Decompiled from int __thiscall CMagicSpell::SpellAttackBloodlust(CMagicSpell *this)
int  CMagicSpell::SpellAttackBloodlust(void) {
  
  int v2; // [esp+8h] [ebp-8h]

  v2 = CAlliances::PlayerAllyBits(*(_DWORD *)this);
  return CMagicSpell::SettlerFlagBitChange(this, v2, 52, (EntityFlag)0x100000u, 34, 0);
}


// address=[0x146dd20]
// Decompiled from int __thiscall CMagicSpell::SpellSoldierFear(CMagicSpell *this)
int  CMagicSpell::SpellSoldierFear(void) {
  
  int v2; // [esp+8h] [ebp-8h]

  v2 = CAlliances::PlayerEnemyBits(*(_DWORD *)this);
  return CMagicSpell::SettlerFlagBitChange(this, v2, 60, (EntityFlag)0x400000u, 56, 0);
}


// address=[0x146dd70]
// Decompiled from int __thiscall CMagicSpell::SpellSpecialThorsHammer(CMagicSpell *this)
int  CMagicSpell::SpellSpecialThorsHammer(void) {
  
  int v1; // eax
  _DWORD v3[4]; // [esp+0h] [ebp-38h] BYREF
  int v4; // [esp+10h] [ebp-28h]
  int v5; // [esp+14h] [ebp-24h]
  int v6; // [esp+18h] [ebp-20h]
  int v7; // [esp+1Ch] [ebp-1Ch]
  int v8; // [esp+20h] [ebp-18h]
  int v9; // [esp+24h] [ebp-14h]
  int v10; // [esp+28h] [ebp-10h] BYREF
  int v11; // [esp+2Ch] [ebp-Ch] BYREF
  unsigned __int8 *BuildingPtr; // [esp+30h] [ebp-8h]
  int *v13; // [esp+34h] [ebp-4h]

  v13 = (int *)this;
  v4 = CAlliances::PlayerEnemyBits(*(_DWORD *)this);
  v6 = 0;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v3, v13[2], v13[3], v13[4]);
  while ( CSpiralWalk::NextXY(v3, &v10, &v11) )
  {
    v5 = CWorldManager::Index(v10, v11);
    v8 = CWorldManager::MapObjectId(v5);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v8);
    if ( BuildingPtr )
    {
      if ( (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(BuildingPtr)) != 0 && IEntity::Race(BuildingPtr) != 3 )
      {
        v1 = IEntity::OwnerId(BuildingPtr);
        if ( CAlliances::PlayerBit(v4 & v1) )
        {
          v9 = CLogic::Effects((DWORD *)g_pLogic);
          (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, int))(*(_DWORD *)v9 + 16))(
            v9,
            23,
            0,
            v10,
            v11,
            0,
            0,
            1);
          v7 = CLogic::FutureEvents(g_pLogic);
          (*(void (__thiscall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)v7 + 12))(v7, 2, 25, v8, 300, 0);
          return 1;
        }
      }
    }
  }
  return v6;
}


// address=[0x146deb0]
// Decompiled from int __thiscall CMagicSpell::SpellFoodFasterCrops(_DWORD *this)
int  CMagicSpell::SpellFoodFasterCrops(void) {
  
  void **v2; // [esp+10h] [ebp-34h]
  int v3; // [esp+14h] [ebp-30h] BYREF
  int v4; // [esp+18h] [ebp-2Ch] BYREF
  int v5; // [esp+1Ch] [ebp-28h]
  int v6; // [esp+20h] [ebp-24h]
  _DWORD *v7; // [esp+24h] [ebp-20h]
  int v8; // [esp+28h] [ebp-1Ch]
  int v9; // [esp+2Ch] [ebp-18h]
  __int64 v10; // [esp+30h] [ebp-14h]
  int v11; // [esp+38h] [ebp-Ch]
  _DWORD *v12; // [esp+3Ch] [ebp-8h]
  int v13; // [esp+40h] [ebp-4h]

  v12 = this;
  v13 = 0;
  CSpiralWalk::CSpiralWalk(this[2], this[3], this[4]);
  while ( (unsigned __int8)CSpiralWalk::NextXY(&v3, &v4) )
  {
    v9 = CWorldManager::Index(v3, v4);
    LOBYTE(v11) = CWorldManager::Ground(v9) & 0xF0;
    v11 = (unsigned __int8)v11;
    HIDWORD(v10) = (unsigned __int8)v11 == 16;
    LODWORD(v10) = (unsigned __int8)v11 == 64;
    if ( v10 )
    {
      v8 = CWorldManager::ObjectId(v9);
      if ( v8 )
      {
        v2 = (void **)CMapObjectMgr::EntityPtr(v8);
        v7 = (_DWORD *)j____RTDynamicCast(v2, 0, &IEntity__RTTI_Type_Descriptor_, &CPlant__RTTI_Type_Descriptor_, 0);
        if ( v7 )
        {
          IEntity::SetFlagBits(v7, (EntityFlag)0x100000u);
          ++v13;
        }
        else
        {
          v6 = v13 == 0;
          v13 += v6;
        }
      }
    }
  }
  if ( v13 <= 0 )
    return v13;
  v5 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 16))(
    v5,
    37,
    0,
    v12[2],
    v12[3],
    0,
    0,
    0);
  return v13;
}


// address=[0x146e020]
// Decompiled from int __thiscall CMagicSpell::SpellDefenceBanFoes(CMagicSpell *this)
int  CMagicSpell::SpellDefenceBanFoes(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v6; // [esp-8h] [ebp-94h]
  _BYTE v7[32]; // [esp+4h] [ebp-88h] BYREF
  _DWORD v8[5]; // [esp+24h] [ebp-68h] BYREF
  void **v9; // [esp+38h] [ebp-54h]
  int v10; // [esp+3Ch] [ebp-50h]
  int v11; // [esp+40h] [ebp-4Ch]
  int v12; // [esp+44h] [ebp-48h]
  int v13; // [esp+48h] [ebp-44h]
  int v14; // [esp+4Ch] [ebp-40h]
  int v15; // [esp+50h] [ebp-3Ch]
  int v16; // [esp+54h] [ebp-38h]
  int v17; // [esp+58h] [ebp-34h]
  int v18; // [esp+5Ch] [ebp-30h]
  int v19; // [esp+60h] [ebp-2Ch]
  int v20; // [esp+64h] [ebp-28h]
  int v21; // [esp+68h] [ebp-24h]
  int v22; // [esp+6Ch] [ebp-20h]
  struct IEntity *v23; // [esp+70h] [ebp-1Ch]
  int v24; // [esp+74h] [ebp-18h]
  int v25; // [esp+78h] [ebp-14h] BYREF
  int v26; // [esp+7Ch] [ebp-10h] BYREF
  CMagicSpell *v27; // [esp+80h] [ebp-Ch]
  void **v28; // [esp+84h] [ebp-8h] BYREF
  char v29; // [esp+8Bh] [ebp-1h]

  v27 = this;
  v13 = CAlliances::PlayerEnemyBits(*(_DWORD *)this);
  v8[4] = 60;
  v24 = 0;
  if ( !*((_DWORD *)v27 + 8) )
    return v24;
  v23 = CMapObjectMgr::Entity(*((_DWORD *)v27 + 8));
  if ( IEntity::WarriorType() != 6
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2121, "rPriest.WarriorType() == WARRIOR_TYPE_PRIEST") == 1 )
  {
    __debugbreak();
  }
  v21 = IEntity::X(v23);
  v22 = IEntity::Y(v23);
  CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk(
    (CWarriorEntitySpiralWalk *)v7,
    v21,
    v22,
    *((_DWORD *)v27 + 4),
    v13,
    60);
  while ( CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v7, (struct IEntity **)&v28) )
  {
    if ( !j____RTDynamicCast(v28, 0, &IEntity__RTTI_Type_Descriptor_, &IMovingEntity__RTTI_Type_Descriptor_, 0)
      && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2132, "dynamic_cast<IMovingEntity*>(pEnemy) != 0") == 1 )
    {
      __debugbreak();
    }
    v9 = v28;
    v1 = IEntity::X(v28);
    v11 = *((_DWORD *)v27 + 2) + v1 - v21;
    v2 = IEntity::Y(v28);
    v12 = *((_DWORD *)v27 + 3) + v2 - v22;
    CSpiralWalk::CSpiralWalk((CSpiralWalk *)v8, v11, v12, 4);
    v29 = 0;
    while ( CSpiralWalk::NextXY(v8, &v25, &v26) )
    {
      v10 = CWorldManager::Index(v25, v26);
      if ( IMovingEntity::IsFree((IMovingEntity *)v9, v10) )
      {
        v3 = IEntity::PackedXY(v28);
        if ( v3 != Y16X16::PackXYFast(v25, v26) )
        {
          v29 = 1;
          break;
        }
      }
    }
    if ( v29 )
    {
      v19 = IEntity::X(v28);
      v20 = IEntity::Y(v28);
      if ( v19 == v25
        && v20 == v26
        && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2166, "(iOldEnemyX != iNewEnemyX) || (iOldEnemyY != iNewEnemyY)") == 1 )
      {
        __debugbreak();
      }
      LOBYTE(v17) = CStateGame::Rand(g_pGame) & 3;
      v17 = (unsigned __int8)v17;
      v18 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v18 + 16))(
        v18,
        55,
        0,
        v19,
        v20,
        v17,
        0,
        0);
      v16 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v16 + 16))(
        v16,
        55,
        0,
        v25,
        v26,
        v17,
        0,
        0);
      v6 = IEntity::Type((unsigned __int16 *)v28);
      v4 = IEntity::OwnerId((unsigned __int8 *)v28);
      CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v25, v26, v4, v6, 2);
      CMagicSpell::InvisibleKill((struct IEntity *)v28);
      if ( ++v24 >= *((_DWORD *)v27 + 5) )
        break;
    }
  }
  if ( v24 <= 0 )
    return v24;
  v15 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, _DWORD, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v15 + 16))(
    v15,
    0,
    63,
    v21,
    v22,
    0,
    0,
    0);
  v14 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v14 + 16))(
    v14,
    0,
    63,
    *((_DWORD *)v27 + 2),
    *((_DWORD *)v27 + 3),
    0,
    0,
    0);
  return v24;
}


// address=[0x146e350]
// Decompiled from int __thiscall CMagicSpell::SpellAttackPunishBowmen(CMagicSpell *this)
int  CMagicSpell::SpellAttackPunishBowmen(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // [esp-10h] [ebp-48h]
  int v5; // [esp-Ch] [ebp-44h]
  int v6; // [esp-4h] [ebp-3Ch]
  _DWORD v7[9]; // [esp+0h] [ebp-38h] BYREF
  int v8; // [esp+24h] [ebp-14h]
  int v9; // [esp+28h] [ebp-10h]
  struct IEntity *v10; // [esp+2Ch] [ebp-Ch] BYREF
  int v11; // [esp+30h] [ebp-8h]
  CMagicSpell *v12; // [esp+34h] [ebp-4h]

  v12 = this;
  v8 = CAlliances::PlayerEnemyBits(*(_DWORD *)this);
  v7[8] = 8;
  v11 = 0;
  CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk(
    (CWarriorEntitySpiralWalk *)v7,
    *((_DWORD *)v12 + 2),
    *((_DWORD *)v12 + 3),
    *((_DWORD *)v12 + 4),
    v8,
    8);
  do
  {
    if ( !CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v7, &v10) )
      break;
    v9 = CLogic::Effects((DWORD *)g_pLogic);
    v5 = CStateGame::Rand(g_pGame) & 3;
    v4 = IEntity::Y(v10);
    v1 = IEntity::X(v10);
    (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v9 + 16))(
      v9,
      56,
      0,
      v1,
      v4,
      v5,
      0,
      0);
    CMagicSpell::InvisibleKill(v10);
    v6 = CSettlerSpiralWalk::CurrentY(v7);
    v2 = CSettlerSpiralWalk::CurrentX(v7);
    CAnimalMgr::AddButterfly((CAnimalMgr *)&g_cAnimalMgr, v2, v6);
    ++v11;
  }
  while ( v11 < *((_DWORD *)v12 + 5) );
  return v11;
}


// address=[0x146e440]
// Decompiled from int __thiscall CMagicSpell::SpellSoldierRevaluation(CMagicSpell *this)
int  CMagicSpell::SpellSoldierRevaluation(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // [esp-10h] [ebp-60h]
  int v5; // [esp-10h] [ebp-60h]
  int v6; // [esp-Ch] [ebp-5Ch]
  int v7; // [esp-8h] [ebp-58h]
  _DWORD v8[10]; // [esp+0h] [ebp-50h] BYREF
  int v9; // [esp+28h] [ebp-28h]
  int v10; // [esp+2Ch] [ebp-24h]
  int v11; // [esp+30h] [ebp-20h]
  int v12; // [esp+34h] [ebp-1Ch]
  int v13; // [esp+38h] [ebp-18h]
  int v14; // [esp+3Ch] [ebp-14h]
  int v15; // [esp+40h] [ebp-10h]
  struct IEntity *v16; // [esp+44h] [ebp-Ch] BYREF
  CMagicSpell *v17; // [esp+48h] [ebp-8h]
  int v18; // [esp+4Ch] [ebp-4h]

  v17 = this;
  v10 = CAlliances::PlayerAllyBits(*(_DWORD *)this);
  v8[9] = 28;
  v15 = 0;
  CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk(
    (CWarriorEntitySpiralWalk *)v8,
    *((_DWORD *)v17 + 2),
    *((_DWORD *)v17 + 3),
    *((_DWORD *)v17 + 4),
    v10,
    28);
  while ( CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v8, &v16) )
  {
    if ( IEntity::ObjType((unsigned __int8 *)v16) != 1
      && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2287, "pEntity->ObjType() == SETTLER_OBJ") == 1 )
    {
      __debugbreak();
    }
    v13 = IEntity::Type((unsigned __int16 *)v16);
    v18 = 0;
    v14 = v13 - 29;
    switch ( v13 )
    {
      case 29:
        v18 = 30;
        break;
      case 30:
        v18 = 31;
        break;
      case 31:
        v18 = 0;
        break;
      case 32:
        v18 = 33;
        break;
      case 33:
        v18 = 34;
        break;
      case 34:
        v18 = 0;
        break;
      case 35:
        v18 = 36;
        break;
      case 36:
        v18 = 37;
        break;
      case 37:
        v18 = 0;
        break;
      case 38:
        v18 = 39;
        break;
      case 39:
        v18 = 40;
        break;
      case 40:
        v18 = 0;
        break;
      case 41:
        v18 = 42;
        break;
      case 42:
        v18 = 43;
        break;
      case 43:
        v18 = 0;
        break;
      case 61:
        v18 = 61;
        break;
      case 62:
        v18 = 62;
        break;
      case 63:
        v18 = 63;
        break;
      default:
        v18 = 0;
        break;
    }
    if ( v18 )
    {
      if ( v13 == v18 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2393, "iOldSettlerType != iNewSettlerType") == 1 )
        __debugbreak();
      v9 = IEntity::OwnerId((unsigned __int8 *)v16);
      CMagicSpell::InvisibleKill(v16);
      v7 = v18;
      v6 = v9;
      v4 = CSettlerSpiralWalk::CurrentY(v8);
      v1 = CSettlerSpiralWalk::CurrentX(v8);
      v8[8] = CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v1, v4, v6, v7, 2);
      v12 = CLogic::Effects((DWORD *)g_pLogic);
      v5 = IEntity::Y(v16);
      v2 = IEntity::X(v16);
      (*(void (__thiscall **)(int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
        v12,
        41,
        0,
        v2,
        v5,
        0,
        0,
        0);
      if ( ++v15 >= *((_DWORD *)v17 + 5) )
        break;
    }
  }
  if ( v15 <= 0 )
    return v15;
  v11 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v11 + 16))(
    v11,
    0,
    81,
    *((_DWORD *)v17 + 2),
    *((_DWORD *)v17 + 3),
    0,
    0,
    0);
  return v15;
}


// address=[0x146e740]
// Decompiled from int __thiscall CMagicSpell::SpellSpecialRainOfStone(CMagicSpell *this)
int  CMagicSpell::SpellSpecialRainOfStone(void) {
  
  char v1; // al
  int v3; // [esp+8h] [ebp-34h]
  int v4; // [esp+14h] [ebp-28h]
  int v5; // [esp+18h] [ebp-24h]
  unsigned int v6; // [esp+1Ch] [ebp-20h]
  int v7; // [esp+20h] [ebp-1Ch]
  int v8; // [esp+24h] [ebp-18h]
  int v9; // [esp+28h] [ebp-14h]
  int i; // [esp+30h] [ebp-Ch]
  int v12; // [esp+34h] [ebp-8h]
  int v13; // [esp+38h] [ebp-4h]

  v9 = 0;
  v8 = CSpiralOffsets::Last(*((_DWORD *)this + 4)) + 1;
  if ( v8 <= 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2451, "iMaxIdx > 0") == 1 )
    __debugbreak();
  for ( i = 0; i < v8; ++i )
  {
    v6 = CStateGame::Rand(g_pGame) % (unsigned int)v8;
    v12 = *((_DWORD *)this + 2) + CSpiralOffsets::DeltaX(v6);
    v13 = *((_DWORD *)this + 3) + CSpiralOffsets::DeltaY(v6);
    if ( (unsigned __int8)CWorldManager::InWorld(v12, v13) )
    {
      v5 = CWorldManager::Index(v12, v13);
      if ( ITiling::CatapultSectorId(v5) )
      {
        v7 = CWorldManager::Ground(v5) & 0xF0;
        if ( v7 == 16 || v7 == 64 || v7 == 144 )
        {
          if ( CDecoObjMgr::IsAddDecoObjOk((CDecoObjMgr *)&g_cDecoObjMgr, v12, v13, 41, 0, 1) )
          {
            v3 = (CStateGame::Rand(g_pGame) & 3) + 8;
            if ( CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, v12, v13, 41, v3, 1) )
            {
              v4 = CLogic::Effects((DWORD *)g_pLogic);
              v1 = CStateGame::Rand(g_pGame);
              (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v4 + 16))(
                v4,
                47,
                0,
                v12,
                v13,
                v1 & 3,
                0,
                0);
              i += CStateGame::Rand(g_pGame) & 7;
              if ( ++v9 >= *((_DWORD *)this + 5) )
                break;
            }
          }
        }
      }
    }
  }
  return v9;
}


// address=[0x146e940]
// Decompiled from int __thiscall CMagicSpell::SpellWitherPlants(CMagicSpell *this)
int  CMagicSpell::SpellWitherPlants(void) {
  
  int v1; // ecx
  int v2; // eax
  _DWORD v4[4]; // [esp+0h] [ebp-24h] BYREF
  int v5; // [esp+10h] [ebp-14h]
  int v6; // [esp+14h] [ebp-10h]
  int v7; // [esp+18h] [ebp-Ch] BYREF
  int v8; // [esp+1Ch] [ebp-8h] BYREF
  CMagicSpell *v9; // [esp+20h] [ebp-4h]

  v9 = this;
  v6 = 0;
  v7 = *((_DWORD *)this + 2);
  v8 = *((_DWORD *)this + 3);
  v5 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 16))(
    v5,
    101,
    59,
    *((_DWORD *)v9 + 2),
    *((_DWORD *)v9 + 3),
    0,
    0,
    0);
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v4, v7, v8, *((_DWORD *)v9 + 4));
  while ( CSpiralWalk::NextXY(v4, &v7, &v8) )
  {
    v2 = CWorldManager::Width(v1);
    CDecoObjMgr::Rod((CDecoObjMgr *)&g_cDecoObjMgr, v7 + v8 * v2, 1);
    ++v6;
  }
  return v6;
}


// address=[0x146e9f0]
// Decompiled from int __thiscall CMagicSpell::SpellTeleportPiles(CMagicSpell *this)
int  CMagicSpell::SpellTeleportPiles(void) {
  
  int v1; // esi
  int v2; // eax
  Grid *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  _DWORD *v8; // eax
  void **v9; // eax
  int v10; // [esp-10h] [ebp-44h]
  CManakopterHallRole *v11; // [esp+4h] [ebp-30h]
  int v12; // [esp+8h] [ebp-2Ch]
  int v13; // [esp+Ch] [ebp-28h]
  int v14; // [esp+10h] [ebp-24h]
  int FirstBuildingId; // [esp+14h] [ebp-20h]
  int v16; // [esp+1Ch] [ebp-18h]
  int v17; // [esp+24h] [ebp-10h]
  unsigned __int8 *SettlerPtr; // [esp+28h] [ebp-Ch]
  CPile *PilePtr; // [esp+30h] [ebp-4h]

  v17 = 0;
  v16 = CWorldManager::PileId(*((_DWORD *)this + 2), *((_DWORD *)this + 3));
  SettlerPtr = CSettlerMgr::GetSettlerPtr(*((_DWORD *)this + 8));
  v13 = IEntity::OwnerId(SettlerPtr);
  if ( !v16 )
    return v17;
  if ( !SettlerPtr )
    return v17;
  PilePtr = CPileMgr::GetPilePtr(v16);
  v12 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr);
  v1 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr);
  v14 = v1 - CPile::AmountLeaving(PilePtr);
  if ( !PilePtr )
    return v17;
  v2 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 16))(
    v2,
    102,
    63,
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 3),
    0,
    0,
    0);
  if ( IEntity::FlagBits(PilePtr, (EntityFlag)0x10u) )
    return 0;
  v10 = IEntity::Y(PilePtr);
  v4 = (Grid *)IEntity::X(PilePtr);
  v5 = Grid::Distance(v4, v10, 0, 0);
  if ( !(unsigned __int8)CPile::ForceAmountLeaving(PilePtr, v5, 1) )
    return 0;
  v6 = IEntity::ID();
  CPile::AttachAndIncAmountLeaving((unsigned __int16 *)PilePtr, v6, v14, 2);
  v7 = IEntity::ID();
  CPile::ChangeAmountAndDetach(PilePtr, v7);
  FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, v13, 80);
  if ( !FirstBuildingId )
    return 1;
  v8 = (_DWORD *)CBuildingMgr::operator[](FirstBuildingId);
  v9 = (void **)CBuilding::Role(v8);
  v11 = (CManakopterHallRole *)j____RTDynamicCast(
                                 v9,
                                 0,
                                 &IBuildingRole__RTTI_Type_Descriptor_,
                                 &CManakopterHallRole__RTTI_Type_Descriptor_,
                                 0);
  CManakopterHallRole::TeleportGoods(v11, v12, v14);
  return 1;
}


// address=[0x146ebc0]
// Decompiled from int __thiscall CMagicSpell::SpellFoodRestockMines(CMagicSpell *this)
int  CMagicSpell::SpellFoodRestockMines(void) {
  
  void **v1; // eax
  int v2; // eax
  int v4; // [esp-10h] [ebp-124h]
  int v5; // [esp-Ch] [ebp-120h]
  CMineRole *v6; // [esp+4h] [ebp-110h]
  int v7; // [esp+8h] [ebp-10Ch]
  int v8; // [esp+Ch] [ebp-108h]
  struct CBuilding *v9; // [esp+10h] [ebp-104h]
  _BYTE v11[248]; // [esp+18h] [ebp-FCh] BYREF

  v8 = 0;
  CFindBuildings::CFindBuildings(
    (CFindBuildings *)v11,
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 3),
    *((_DWORD *)this + 4));
  while ( CFindBuildings::NextBuilding((CFindBuildings *)v11) )
  {
    v9 = CFindBuildings::BuildingPtr((CFindBuildings *)v11);
    if ( IEntity::OwnerId((unsigned __int8 *)v9) == *(_DWORD *)this )
    {
      v1 = (void **)CBuilding::Role(v9);
      v6 = (CMineRole *)j____RTDynamicCast(
                          v1,
                          0,
                          &IBuildingRole__RTTI_Type_Descriptor_,
                          &CMineRole__RTTI_Type_Descriptor_,
                          0);
      if ( v6 )
      {
        v7 = CLogic::Effects((DWORD *)g_pLogic);
        v5 = CStateGame::Rand(g_pGame) & 7;
        v4 = IEntity::Y(v9);
        v2 = IEntity::X(v9);
        (*(void (__thiscall **)(int, int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v7 + 16))(
          v7,
          106,
          59,
          v2,
          v4,
          v5,
          0,
          0);
        CMineRole::RestockFavouriteFood(v6);
        ++v8;
      }
    }
  }
  return v8;
}


// address=[0x146ed10]
// Decompiled from int __thiscall CMagicSpell::SpellDefenceFortifyDoors(CMagicSpell *this)
int  CMagicSpell::SpellDefenceFortifyDoors(void) {
  
  void **v1; // eax
  int v2; // eax
  int v4; // [esp-10h] [ebp-124h]
  CMilitaryBuildingRole *v5; // [esp+4h] [ebp-110h]
  int v6; // [esp+8h] [ebp-10Ch]
  int v7; // [esp+Ch] [ebp-108h]
  struct CBuilding *v8; // [esp+10h] [ebp-104h]
  _BYTE v10[248]; // [esp+18h] [ebp-FCh] BYREF

  v7 = 0;
  CFindBuildings::CFindBuildings(
    (CFindBuildings *)v10,
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 3),
    *((_DWORD *)this + 4));
  while ( CFindBuildings::NextBuilding((CFindBuildings *)v10) )
  {
    v8 = CFindBuildings::BuildingPtr((CFindBuildings *)v10);
    if ( IEntity::OwnerId((unsigned __int8 *)v8) == *(_DWORD *)this )
    {
      v1 = (void **)CBuilding::Role(v8);
      v5 = (CMilitaryBuildingRole *)j____RTDynamicCast(
                                      v1,
                                      0,
                                      &IBuildingRole__RTTI_Type_Descriptor_,
                                      &CMilitaryBuildingRole__RTTI_Type_Descriptor_,
                                      0);
      if ( v5 )
      {
        v6 = CLogic::Effects((DWORD *)g_pLogic);
        v4 = IEntity::Y(v8);
        v2 = IEntity::X(v8);
        (*(void (__thiscall **)(int, int, int, int, int, int, _DWORD, int))(*(_DWORD *)v6 + 16))(
          v6,
          104,
          98,
          v2,
          v4,
          5,
          0,
          1);
        CMilitaryBuildingRole::SetDoorInvincible(v5, *((_DWORD *)this + 6));
        if ( ++v7 >= *((_DWORD *)this + 5) )
          break;
      }
    }
  }
  return v7;
}


// address=[0x146ee70]
// Decompiled from int __thiscall CMagicSpell::SpellAttackInvisibility(CMagicSpell *this)
int  CMagicSpell::SpellAttackInvisibility(void) {
  
  int v1; // eax

  v1 = CAlliances::PlayerBit(*(_DWORD *)this);
  return CMagicSpell::SettlerFlagBitChange(this, v1, 60, (EntityFlag)0x8000000u, 56, 0);
}


// address=[0x146eea0]
// Decompiled from int __thiscall CMagicSpell::SpellSoldierPacify(CMagicSpell *this)
int  CMagicSpell::SpellSoldierPacify(void) {
  
  int v1; // eax
  _BYTE v3[32]; // [esp+0h] [ebp-54h] BYREF
  int v4; // [esp+20h] [ebp-34h]
  int v5; // [esp+24h] [ebp-30h]
  int v6; // [esp+28h] [ebp-2Ch]
  int v7; // [esp+2Ch] [ebp-28h]
  int v8; // [esp+30h] [ebp-24h]
  int v9; // [esp+34h] [ebp-20h]
  int v10; // [esp+38h] [ebp-1Ch]
  int v11; // [esp+3Ch] [ebp-18h]
  int v12; // [esp+40h] [ebp-14h]
  CMagicSpell *v13; // [esp+44h] [ebp-10h]
  struct IEntity *v14; // [esp+48h] [ebp-Ch] BYREF
  int v15; // [esp+4Ch] [ebp-8h]
  int v16; // [esp+50h] [ebp-4h]

  v13 = this;
  v12 = 0;
  v6 = CAlliances::PlayerEnemyBits(*(_DWORD *)this);
  v4 = 60;
  CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk(
    (CWarriorEntitySpiralWalk *)v3,
    *((_DWORD *)v13 + 2),
    *((_DWORD *)v13 + 3),
    *((_DWORD *)v13 + 4),
    v6,
    60);
  while ( CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v3, &v14) )
  {
    v10 = IEntity::WarriorType();
    v8 = IEntity::Race(v14);
    if ( v8 == 3 )
    {
      if ( v10 == 2 || v10 == 3 )
      {
        v1 = IEntity::ID();
        CMapObjectMgr::Kill(v1, 0);
      }
    }
    else
    {
      v15 = IEntity::X(v14);
      v16 = IEntity::Y(v14);
      v5 = IEntity::OwnerId((unsigned __int8 *)v14);
      v9 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v9 + 16))(
        v9,
        55,
        0,
        v15,
        v16,
        5,
        0,
        0);
      CMagicSpell::InvisibleKill(v14);
      v11 = v10;
      if ( v10 == 2 )
      {
LABEL_11:
        CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v15, v16, 34, 1, 3, 0, 0, 0, 0);
      }
      else if ( v11 == 3 )
      {
        CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v15, v16, 8, 1, 3, 0, 0, 0, 0);
      }
      else if ( v11 == 4 )
      {
        v7 = v8;
        switch ( v8 )
        {
          case 0:
            goto LABEL_11;
          case 1:
            CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v15, v16, 5, 1, 3, 0, 0, 0, 0);
            break;
          case 2:
            CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v15, v16, 6, 1, 3, 0, 0, 0, 0);
            break;
          case 4:
            CPileMgr::AddPile((CPileMgr *)&g_cPileMgr, v15, v16, 38, 1, 3, 0, 0, 0, 0);
            break;
          default:
            break;
        }
      }
      CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v15, v16, v5, 1, 0);
      if ( ++v12 >= *((_DWORD *)v13 + 5) )
        return v12;
    }
  }
  return v12;
}


// address=[0x146f100]
// Decompiled from int __thiscall CMagicSpell::SpellSpecialOracle(CMagicSpell *this)
int  CMagicSpell::SpellSpecialOracle(void) {
  
  int TickCounter; // esi
  _DWORD *v2; // eax
  int v4; // [esp-4h] [ebp-10h]

  v4 = *(_DWORD *)this;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v2 = (_DWORD *)TStaticConfigIntArrayBase<8>::operator[](7);
  (*(void (__thiscall **)(void *, _DWORD, _DWORD, int, int))(*(_DWORD *)g_pFogging + 60))(
    g_pFogging,
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 3),
    *v2 + TickCounter,
    v4);
  return 1;
}


// address=[0x146f170]
// Decompiled from int *__cdecl CMagicSpell::ShowSpellEffect(int a1, int a2, int a3, int a4)
void __cdecl CMagicSpell::ShowSpellEffect(int a1, int a2, int a3, int a4) {
  
  int *result; // eax
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  if ( !(unsigned __int8)sub_146C530(a1)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1015, "MagicIsValidRace(_iRace)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)sub_146C500(a2)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1016, "MagicIsValidSpellCategory(_iSpellCategory)") == 1 )
  {
    __debugbreak();
  }
  v8 = *(_DWORD *)TStaticConfigIntArrayBase<8>::operator[](a2);
  result = (int *)TStaticConfigIntArrayBase<8>::operator[](a2);
  v7 = *result;
  if ( (v8 <= 0 || v8 >= 86) && (v8 <= 100 || v8 >= 116) )
    return result;
  v6 = 0;
  if ( v7 > 0 && v7 < 109 )
    v6 = *result;
  if ( !g_pLogic && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1031, "g_pLogic != 0") == 1 )
    __debugbreak();
  v5 = CLogic::Effects((DWORD *)g_pLogic);
  return (int *)(*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 16))(
                  v5,
                  v8,
                  v6,
                  a3,
                  a4,
                  0,
                  0,
                  0);
}


// address=[0x14704b0]
// Decompiled from CMagicSpell *__thiscall CMagicSpell::CMagicSpell(  CMagicSpell *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  int a9,  int a10)
 CMagicSpell::CMagicSpell(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 3) = a5;
  *((_DWORD *)this + 4) = a6;
  *((_DWORD *)this + 5) = a7;
  *((_DWORD *)this + 6) = a8;
  *((_DWORD *)this + 7) = a9;
  *((_DWORD *)this + 8) = a10;
  return this;
}


// address=[0x14708b0]
// Decompiled from int __thiscall CMagicSpell::CastSpell(CMagicSpell *this, int a2, int a3)
int  CMagicSpell::CastSpell(int a2, int a3) {
  
  return ((int (__thiscall *)(CMagicSpell *, CMagicSpell *))*(&CMagicSpell::m_pSpellFuncs[8 * a2] + a3))(this, this);
}


// address=[0x14709e0]
// Decompiled from int __cdecl CMagicSpell::InvisibleKill(struct IEntity *a1)
void __cdecl CMagicSpell::InvisibleKill(class IEntity * a1) {
  
  int v2; // [esp+0h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 998, "_pEntity != 0") == 1 )
    __debugbreak();
  v2 = IEntity::ID();
  if ( v2 <= 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 1002, "iEntityId > 0") == 1 )
    __debugbreak();
  IEntity::ClearFlagBits(a1, EntityFlag_Visible);
  return CMapObjectMgr::Kill(v2, 0);
}


// address=[0x36b72d8]
// [Decompilation failed for static int ( CMagicSpell::*(* CMagicSpell::m_pSpellFuncs)[8])(void)]

