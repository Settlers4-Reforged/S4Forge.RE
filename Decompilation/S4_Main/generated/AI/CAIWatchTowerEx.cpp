#include "CAIWatchTowerEx.h"

// Definitions for class CAIWatchTowerEx

// address=[0x132efa0]
// Decompiled from int __thiscall CAIWatchTowerEx::Calculate(CAIWatchTowerEx *this)
int  CAIWatchTowerEx::Calculate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned int v5; // eax
  int v7; // [esp+0h] [ebp-2Ch] BYREF
  int v8; // [esp+4h] [ebp-28h]
  int v9; // [esp+8h] [ebp-24h]
  int v10; // [esp+Ch] [ebp-20h]
  BOOL v11; // [esp+10h] [ebp-1Ch]
  int v12; // [esp+14h] [ebp-18h]
  int v13; // [esp+18h] [ebp-14h]
  int v14; // [esp+1Ch] [ebp-10h] BYREF
  CAIWatchTower *v15; // [esp+20h] [ebp-Ch]
  int v16; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v15 = this;
  if ( !CAIWatchTower::Used(this) && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 235, "Used()") == 1 )
    __debugbreak();
  v1 = CAIWatchTower::PackedXY(v15);
  IAIEnvironment::UnpackXYFast(v1, &v14, &v7);
  v9 = CAIWatchTower::AllianceId(v15);
  v16 = 0;
  for ( i = 0; i < SurroundingHexPointsCount(2); ++i )
  {
    v2 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    v12 = v14 + 16 * v2;
    v3 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
    v13 = v14 + 16 * v3;
    if ( IAIEnvironment::WorldInWorld(v12, v13) )
    {
      v4 = CInfluMap::EnemyValueXY(v12, v13, v9);
      v16 += v4;
    }
  }
  v11 = v16 > 0;
  v5 = CAIWatchTower::Value(v15);
  if ( v16 == v5 )
    v10 = 0;
  else
    v10 = 2;
  v8 = v10 | v11;
  CAIWatchTower::SetValue(v15, v16);
  return v8;
}


