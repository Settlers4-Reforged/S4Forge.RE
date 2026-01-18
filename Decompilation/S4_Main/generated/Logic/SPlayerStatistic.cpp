#include "SPlayerStatistic.h"

// Definitions for class SPlayerStatistic

// address=[0x1478cc0]
// Decompiled from void __thiscall CStatistic::SPlayerStatistic::UpdateFightingStrength(  CStatistic::SPlayerStatistic *this,  int a2,  int a3,  int a4,  int a5,  bool a6)
void  CStatistic::SPlayerStatistic::UpdateFightingStrength(int a2, int a3, int a4, int a5, bool a6) {
  
  *((_DWORD *)this + 753) += a3;
  *((_DWORD *)this + 753) += a4;
  *((_DWORD *)this + 753) += a5;
  *((_DWORD *)this + 745) += a3;
  *((_DWORD *)this + 746) += a4;
  *((_DWORD *)this + 747) += a5;
  if ( a6 )
  {
    *((_DWORD *)this + 748) += a3;
    *((_DWORD *)this + 749) += a4;
    *((_DWORD *)this + 750) += a5;
  }
  CStatistic::SPlayerStatistic::CalculateFightingStrength(this, a2);
}


// address=[0x1478da0]
// Decompiled from _DWORD *__thiscall CStatistic::SPlayerStatistic::CalculateFightingStrength(CStatistic::SPlayerStatistic *this, int a2)
void  CStatistic::SPlayerStatistic::CalculateFightingStrength(int a2) {
  
  _DWORD *result; // eax
  int v3; // [esp+4h] [ebp-6Ch]
  int v4; // [esp+10h] [ebp-60h]
  int v5; // [esp+14h] [ebp-5Ch]
  int v6; // [esp+18h] [ebp-58h]
  int v7; // [esp+1Ch] [ebp-54h]
  int NumberOfBuildings; // [esp+20h] [ebp-50h]
  int v9; // [esp+24h] [ebp-4Ch]
  int i; // [esp+28h] [ebp-48h]
  int v11; // [esp+2Ch] [ebp-44h]
  bool v12; // [esp+33h] [ebp-3Dh]
  int v13; // [esp+34h] [ebp-3Ch]
  _DWORD v15[12]; // [esp+3Ch] [ebp-34h]

  if ( *((int *)this + 744) <= 0
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1213, "m_iOffenceStrengthBase256 > 0") == 1 )
  {
    __debugbreak();
  }
  v12 = CStaticConfigVarInt::operator int(&unk_3F29D98) == 1;
  v11 = 256;
  if ( *((int *)this + 1097) <= 0 )
  {
    if ( *((_DWORD *)this + 744) != 256 && !v12 )
    {
      if ( g_pGameType
        && CPlayerManager::IsAI(a2)
        && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)off_3D7A3D8 + 16))(off_3D7A3D8)
        && IAIDifficultyLevels::GetDifficultyLevel(a2) >= 2 )
      {
        v9 = *((_DWORD *)this + 746) + *((_DWORD *)this + 745) + 2 * *((_DWORD *)this + 747);
        v6 = v9;
      }
      else
      {
        v9 = *((_DWORD *)this + 746) + *((_DWORD *)this + 745) + 2 * *((_DWORD *)this + 747);
        v6 = 2 * (*((_DWORD *)this + 749) + *((_DWORD *)this + 748) + 2 * *((_DWORD *)this + 750));
      }
      if ( CStaticConfigVarInt::operator int(&unk_3F29DA4) <= 0 )
        v7 = 1000;
      else
        v7 = CStaticConfigVarInt::operator int(&unk_3F29DA4);
      v3 = (((v6 + v9) << 8) + 127) / v7 + *((_DWORD *)this + 744);
      v15[0] = 64;
      v15[1] = 65;
      v15[2] = 66;
      v15[3] = 67;
      v15[4] = 68;
      v15[5] = 69;
      v15[6] = 70;
      v15[7] = 71;
      v15[8] = 72;
      v15[9] = 73;
      v15[10] = 74;
      v15[11] = 75;
      NumberOfBuildings = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, a2, 64, 1u);
      for ( i = 1; i < 12; ++i )
      {
        v5 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, a2, v15[i], 1u);
        if ( v5 < NumberOfBuildings )
          NumberOfBuildings = v5;
      }
      v13 = v3 + 30 * NumberOfBuildings;
      if ( v13 > 128 )
      {
        v13 = (v13 - 128) / 2 + 128;
        if ( v13 > 256 )
        {
          v13 = (v13 - 256) / 2 + 256;
          if ( v13 > 320 )
          {
            v13 = (v13 - 320) / 2 + 320;
            if ( v13 > 384 )
              v13 = 384;
          }
        }
      }
      if ( v13 <= 0 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1333, "iTemp > 0") == 1 )
        __debugbreak();
      v11 = v13;
    }
  }
  else
  {
    v11 = *((_DWORD *)this + 1097);
  }
  if ( g_pGameData && CGameData::GetMode(g_pGameData) == 3 )
  {
    if ( v11 < 4 )
      v4 = 1;
    else
      v4 = v11 / 4;
    v11 = v4;
  }
  *((_DWORD *)this + 752) = v11;
  if ( *((int *)this + 752) <= 0
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1346, "m_iEffectiveOffenceStrength256 > 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 752) > 384
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1347, "m_iEffectiveOffenceStrength256 <= 384") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 752) <= 256 )
    *((_DWORD *)this + 751) = 256;
  else
    *((_DWORD *)this + 751) = (*((_DWORD *)this + 752) - 256) / 2 + 256;
  *((_DWORD *)this + 1052) = *(_DWORD *)std::max<int>((char *)this + 4208, (char *)this + 3004);
  result = (_DWORD *)std::max<int>((char *)this + 4212, (char *)this + 3008);
  *((_DWORD *)this + 1053) = *result;
  return result;
}


