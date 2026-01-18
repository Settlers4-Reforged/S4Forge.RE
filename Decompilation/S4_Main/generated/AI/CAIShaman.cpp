#include "CAIShaman.h"

// Definitions for class CAIShaman

// address=[0x13264f0]
// Decompiled from char __thiscall CAIShaman::FindGlobalTargetForShaman(CAIShaman *this, int player, int a3, int *x, int *y, bool a6)
bool  CAIShaman::FindGlobalTargetForShaman(int player, int a3, int & x, int & y, bool a6) {
  
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  unsigned int v8; // esi
  int PlayerId; // [esp+14h] [ebp-34h]
  int v11; // [esp+18h] [ebp-30h]
  unsigned int v12; // [esp+1Ch] [ebp-2Ch]
  int MostRequiredGood; // [esp+20h] [ebp-28h]
  int FirstBuildingId; // [esp+24h] [ebp-24h]
  int v15; // [esp+28h] [ebp-20h] BYREF
  int j; // [esp+2Ch] [ebp-1Ch]
  int v17; // [esp+30h] [ebp-18h]
  int v18; // [esp+34h] [ebp-14h] BYREF
  int v19; // [esp+38h] [ebp-10h] BYREF
  int i; // [esp+3Ch] [ebp-Ch]
  int v21; // [esp+40h] [ebp-8h]
  CAIShaman *v22; // [esp+44h] [ebp-4h]

  v22 = this;
  *((_DWORD *)this + 1) = player;
  *((_DWORD *)v22 + 2) = IAIEnvironment::AlliancesAllianceId(player);
  *((_DWORD *)v22 + 3) = CAlliances::PlayerEnemyBits(player);
  *((_DWORD *)v22 + 4) = *x;
  *((_DWORD *)v22 + 5) = *y;
  *((_DWORD *)v22 + 6) = IAIEnvironment::WorldSectorId(*x, *y);
  v21 = 0;
  FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, player, 80);
  if ( FirstBuildingId )
  {
    v6 = (_DWORD *)CBuildingMgr::operator[](FirstBuildingId);
    if ( IEntity::FlagBits(v6, EntityFlag_Ready) )
    {
      v7 = (_DWORD *)CBuildingMgr::operator[](FirstBuildingId);
      v11 = CBuilding::Role(v7);
      MostRequiredGood = CManakopterHallRole::GetMostRequiredGood(v11);
      if ( MostRequiredGood )
      {
        v21 = MostRequiredGood == 7;
        if ( MostRequiredGood == 20 )
          v21 = 2;
      }
    }
  }
  if ( !v21 )
  {
    v8 = IAIEnvironment::Rand();
    if ( v8 < CRandom16::PercentValue(0x46u) )
      v21 = 3;
  }
  if ( *((int *)v22 + 6) <= 0 )
    return 0;
  v19 = 0;
  v18 = 0;
  v15 = 0;
  v17 = dword_3D7A6F0[v21];
  v12 = CStateGame::Rand(g_pGame) % (unsigned int)v17;
  PlayerId = IAIEnvironment::AlliancesLastPlayerId();
  for ( i = 1; ; ++i )
  {
    if ( i > PlayerId )
      return 0;
    if ( (a3 & IAIEnvironment::AlliancesPlayerBit(i)) != 0 )
    {
      for ( j = 0; j < v17 - 1; ++j )
        CAIShaman::FindBetterTargetBuilding(v22, i, dword_3D7A6B0[4 * v21 + (int)(j + v12) % v17], &v19, &v18, &v15, a6);
      if ( v15 <= 0 )
        CAIShaman::FindBetterTargetBuilding(
          v22,
          i,
          dword_3D7A6B0[4 * v21 + (int)(v12 + v17 - 1) % v17],
          &v19,
          &v18,
          &v15,
          a6);
      if ( v15 > 0 )
        break;
    }
  }
  if ( v21 == 1 )
    (*(void (__thiscall **)(CAIShaman *, int *, int *, int))(*(_DWORD *)v22 + 8))(v22, &v19, &v18, 7);
  if ( v21 == 2 )
    (*(void (__thiscall **)(CAIShaman *, int *, int *, int))(*(_DWORD *)v22 + 8))(v22, &v19, &v18, 20);
  if ( v21 == 3 )
    (*(void (__thiscall **)(CAIShaman *, int *, int *, int))(*(_DWORD *)v22 + 12))(v22, &v19, &v18, 25);
  *x = v19;
  *y = v18;
  return 1;
}


// address=[0x13267b0]
// Decompiled from char __thiscall CAIShaman::FindNearTargetForShaman(CAIShaman *this, int a2, int a3, int *a4, int *a5)
bool  CAIShaman::FindNearTargetForShaman(int a2, int a3, int & a4, int & a5) {
  
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h] BYREF

  v7 = -1;
  IAIEnvironment::AlliancesAllianceId(a2);
  v6 = CAlliances::PlayerEnemyBits(a2);
  if ( CScanner::CountCiviliansAndFindNearestInSector(*a4, *a5, a3, v6, &v7) <= 0 )
    return 0;
  *a4 = IAIEnvironment::UnpackXFast(v7);
  *a5 = IAIEnvironment::UnpackYFast(v7);
  return 1;
}


// address=[0x1326840]
// Decompiled from int __thiscall CAIShaman::FindTeleportationTarget(CAIShaman *this, int *a2, int *a3, int a4)
int  CAIShaman::FindTeleportationTarget(int & a2, int & a3, int a4) {
  
  int GoodOffer; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp-4h] [ebp-24h]
  struct CPile *v9; // [esp+4h] [ebp-1Ch]
  char *v10; // [esp+8h] [ebp-18h]
  char *v11; // [esp+Ch] [ebp-14h]
  CEcoSector *v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch]
  int v14; // [esp+18h] [ebp-8h]
  struct CPile *PilePtr; // [esp+1Ch] [ebp-4h]

  v14 = 0;
  v13 = CWorldManager::EcoSectorId(*a2, *a3);
  if ( v13 )
  {
    v12 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, v13);
    if ( v12 )
    {
      GoodOffer = CEcoSector::GetGoodOffer(v12, a4);
      PilePtr = CPileMgr::GetPilePtr(GoodOffer);
      v10 = (char *)&dword_F29144[220078] + 3;
      while ( PilePtr )
      {
        v8 = IEntity::Y(PilePtr) - *a3;
        v5 = IEntity::X(PilePtr);
        v11 = (char *)Grid::Distance((Grid *)(v5 - *a2), v8);
        if ( (int)v11 < (int)v10 )
        {
          if ( (unsigned __int8)CPile::GoodAvailable(PilePtr) )
          {
            v14 = IEntity::ID();
            v10 = v11;
          }
        }
        v6 = IAnimatedEntity::Next(PilePtr);
        PilePtr = CPileMgr::GetPilePtr(v6);
      }
    }
  }
  if ( !v14 )
    return v14;
  v9 = CPileMgr::GetPilePtr(v14);
  *a2 = IEntity::X(v9);
  *a3 = IEntity::Y(v9);
  return v14;
}


// address=[0x1326950]
// Decompiled from int __thiscall CAIShaman::FindFieldToRot(CAIShaman *this, int *a2, int *a3, int a4)
int  CAIShaman::FindFieldToRot(int & a2, int & a3, int a4) {
  
  _DWORD v5[5]; // [esp+0h] [ebp-30h] BYREF
  int v6; // [esp+14h] [ebp-1Ch]
  int v7; // [esp+18h] [ebp-18h]
  unsigned __int16 *DecoObjPtr; // [esp+1Ch] [ebp-14h]
  int v9; // [esp+20h] [ebp-10h]
  int v10; // [esp+24h] [ebp-Ch] BYREF
  int v11[2]; // [esp+28h] [ebp-8h] BYREF

  v5[4] = this;
  v11[0] = *a2;
  v10 = *a3;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v5, v11[0], v10, a4);
  v9 = 0;
  while ( CSpiralWalk::NextXY(v5, v11, &v10) && !v9 )
  {
    v7 = CWorldManager::ObjectId(v11[0], v10);
    DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(v7);
    if ( DecoObjPtr )
    {
      v6 = IEntity::Type(DecoObjPtr);
      v11[1] = v6 - 209;
      switch ( v6 )
      {
        case 209:
        case 210:
        case 211:
        case 217:
        case 255:
          v9 = v7;
          *a2 = v11[0];
          *a3 = v10;
          break;
        default:
          continue;
      }
    }
  }
  return v9;
}


// address=[0x1326d60]
// Decompiled from CAIShaman *__thiscall CAIShaman::CAIShaman(CAIShaman *this)
 CAIShaman::CAIShaman(void) {
  
  IAIShaman::IAIShaman(this);
  *(_DWORD *)this = &CAIShaman::_vftable_;
  return this;
}


// address=[0x1326a60]
// Decompiled from int __thiscall CAIShaman::EvaluateTargetPosition(CAIShaman *this, Squares *a2, Squares *a3)
int  CAIShaman::EvaluateTargetPosition(int a2, int a3) {
  
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  int NearestInSector; // [esp+14h] [ebp-8h]

  v5 = Squares::XYToVW(a2);
  v6 = Squares::XYToVW(a3);
  v4 = -CInfluMap::EnemyValueVW(v5, v6, *((_DWORD *)this + 2));
  NearestInSector = CScanner::CountCiviliansAndFindNearestInSector((int)a2, (int)a3, 24, *((_DWORD *)this + 3), 0);
  if ( NearestInSector <= 0 )
    v7 = 0;
  else
    v7 = 100;
  return v7 + 8 * NearestInSector - v4;
}


// address=[0x1326af0]
// Decompiled from int __thiscall CAIShaman::FindBetterTargetBuilding(  CAIShaman *this,  int a2,  int a3,  struct _Cnd_internal_imp_t **a4,  Squares **a5,  int *a6,  bool a7)
void  CAIShaman::FindBetterTargetBuilding(int a2, int a3, int & a4, int & a5, int & a6, bool a7) {
  
  int result; // eax
  int v8; // [esp+4h] [ebp-18h]
  int i; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  Squares *v12; // [esp+14h] [ebp-8h]
  struct _Cnd_internal_imp_t *v13; // [esp+18h] [ebp-4h]

  result = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, a2, a3);
  for ( i = result; i; i = result )
  {
    v11 = CBuildingMgr::operator[](i);
    v13 = (struct _Cnd_internal_imp_t *)CBuilding::EnsignX(v11);
    v12 = (Squares *)CBuilding::EnsignY(v11);
    if ( IAIEnvironment::WorldSectorId((int)v13, (int)v12) == *((_DWORD *)this + 6) || a7 )
    {
      v8 = CAIShaman::EvaluateTargetPosition(this, v13, v12);
      if ( v8 > *a6 )
      {
        *a6 = v8;
        *a4 = v13;
        *a5 = v12;
      }
    }
    result = IAnimatedEntity::Next(v11);
  }
  return result;
}


