#include "CAIPlayerEvaluation.h"

// Definitions for class CAIPlayerEvaluation

// address=[0x1310d40]
// Decompiled from CAIPlayerEvaluation *__thiscall CAIPlayerEvaluation::Clear(CAIPlayerEvaluation *this)
void  CAIPlayerEvaluation::Clear(void) {
  
  CAIPlayerEvaluation *result; // eax

  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  result = this;
  *((_DWORD *)this + 21) = 0;
  return result;
}


// address=[0x1310e30]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluatePlayer(CAIPlayerEvaluation *this, int a2)
void  CAIPlayerEvaluation::EvaluatePlayer(int) {
  
  int Seed; // eax
  int NumberOfRandCalls; // [esp-4h] [ebp-8h]

  *(_DWORD *)this = IAIEnvironment::TickCounter();
  NumberOfRandCalls = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  Seed = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "==> Evaluation: AI_tick %u, seed 0x%08x, counter %u",
    *(_DWORD *)this,
    Seed,
    NumberOfRandCalls);
  CAIPlayerEvaluation::EvaluateGoods(this, a2);
  CAIPlayerEvaluation::EvaluateWarriors(this, a2);
  CAIPlayerEvaluation::EvaluateBuildings(this, a2);
}


// address=[0x1310ea0]
// Decompiled from void __thiscall CAIPlayerEvaluation::DbgPrint(CAIPlayerEvaluation *this)
void  CAIPlayerEvaluation::DbgPrint(void) {
  
  IAIEnvironment::DbgTracePrintF(
    "F-S/B/U/L, P:      %5i, %5i, %5i, %5i, %5i",
    *((_DWORD *)this + 8),
    *((_DWORD *)this + 9),
    *((_DWORD *)this + 10),
    *((_DWORD *)this + 11),
    *((_DWORD *)this + 12));
  IAIEnvironment::DbgTracePrintF("Units (Value):     %5i, %5i", *((_DWORD *)this + 13), *((_DWORD *)this + 14));
  IAIEnvironment::DbgTracePrintF(
    "Towers & castles:  %5i, %5i, %5i",
    *((_DWORD *)this + 17),
    *((_DWORD *)this + 18),
    *((_DWORD *)this + 19));
  IAIEnvironment::DbgTracePrintF("Buildings (Value): %5i, %5i", *((_DWORD *)this + 20), *((_DWORD *)this + 21));
}


// address=[0x1310f40]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluateGoods(CAIPlayerEvaluation *this, int a2)
void  CAIPlayerEvaluation::EvaluateGoods(int) {
  
  int v2; // [esp+0h] [ebp-Ch]

  v2 = IAIEnvironment::PlayerRace(a2);
  *((_DWORD *)this + 1) = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 34);
  *((_DWORD *)this + 2) = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 8);
  switch ( v2 )
  {
    case 1:
      *((_DWORD *)this + 3) = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 5);
      break;
    case 2:
      *((_DWORD *)this + 3) = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 6);
      break;
    case 4:
      *((_DWORD *)this + 3) = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 38);
      break;
    default:
      *((_DWORD *)this + 3) = 0;
      break;
  }
  *((_DWORD *)this + 4) = *((_DWORD *)this + 3) + *((_DWORD *)this + 2) + *((_DWORD *)this + 1);
  *((_DWORD *)this + 5) = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, 14);
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "CAIPlayerEvaluation(Goods): Player %i: %i %i %i %i",
    a2,
    *((_DWORD *)this + 1),
    *((_DWORD *)this + 2),
    *((_DWORD *)this + 3),
    *((_DWORD *)this + 5));
}


// address=[0x1311060]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluateWarriors(CAIPlayerEvaluation *this, int a2)
void  CAIPlayerEvaluation::EvaluateWarriors(int) {
  
  int v2; // [esp+0h] [ebp-7Ch]
  int v3; // [esp+4h] [ebp-78h]
  int v4; // [esp+8h] [ebp-74h]
  int v5; // [esp+Ch] [ebp-70h]
  int v6; // [esp+10h] [ebp-6Ch]
  int NumberOfOfferedSettlers; // [esp+14h] [ebp-68h]
  int NumberOfSettlers; // [esp+18h] [ebp-64h]
  int v9; // [esp+24h] [ebp-58h]
  int v10; // [esp+28h] [ebp-54h]
  int j; // [esp+2Ch] [ebp-50h]
  int i; // [esp+30h] [ebp-4Ch]
  _DWORD v14[16]; // [esp+38h] [ebp-44h] BYREF

  j__memset(v14, 0, sizeof(v14));
  for ( i = 0; dword_3D7A218[3 * i]; ++i )
  {
    NumberOfSettlers = IAIEnvironment::SettlerGetNumberOfSettlers(a2, dword_3D7A218[3 * i]);
    v10 = dword_3D7A218[3 * i + 1];
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer2,
      "SettlerEvals %i, Eval type %i number: %i",
      i,
      v10,
      NumberOfSettlers);
    v14[2 * v10] += NumberOfSettlers;
    v14[2 * v10 + 1] += dword_3D7A218[3 * i + 2] * NumberOfSettlers;
  }
  for ( j = 0; dword_3D7A318[3 * j]; ++j )
  {
    NumberOfOfferedSettlers = CSettlerMgr::GetNumberOfOfferedSettlers(
                                (CSettlerMgr *)g_cSettlerMgr,
                                a2,
                                dword_3D7A318[3 * j]);
    v9 = dword_3D7A318[3 * j + 1];
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer2,
      "SettlerEvalsEx %i, Eval type %i number: %i",
      j,
      v9,
      NumberOfOfferedSettlers);
    v14[2 * v9] += NumberOfOfferedSettlers;
    v14[2 * v9 + 1] += dword_3D7A318[3 * j + 2] * NumberOfOfferedSettlers;
  }
  v5 = v14[10] + v14[8] + v14[6];
  v4 = v14[11] + v14[9] + v14[7];
  v6 = v14[13];
  IMessageTracer::PushFormatedInts(g_pMsgTracer2, "FighterNumber %i, FighterValue %i, LeaderValue %i.", v5, v4, v14[13]);
  *((_DWORD *)this + 6) = v14[2];
  *((_DWORD *)this + 7) = v14[4];
  *((_DWORD *)this + 8) = v14[6];
  *((_DWORD *)this + 9) = v14[8];
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "OfferedSwordmen %i, OfferedBowmen %i, TotalSwordmen %i, TotalBowmen %i.",
    *((_DWORD *)this + 6),
    *((_DWORD *)this + 7),
    *((_DWORD *)this + 8),
    *((_DWORD *)this + 9));
  *((_DWORD *)this + 10) = v14[10];
  *((_DWORD *)this + 11) = v14[12];
  *((_DWORD *)this + 12) = v14[14];
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "SpecialistsNumber %i, LeadersNumber %i, PriestsNumber %i",
    *((_DWORD *)this + 10),
    *((_DWORD *)this + 11),
    *((_DWORD *)this + 12));
  *((_DWORD *)this + 13) = *((_DWORD *)this + 12) + *((_DWORD *)this + 11) + v5;
  *((_DWORD *)this + 14) = v6 + v4;
  v2 = v14[10] + v14[4] + v14[2];
  v3 = v14[11] + v14[5] + v14[3];
  *((_DWORD *)this + 15) = *((_DWORD *)this + 12) + *((_DWORD *)this + 11) + v2;
  *((_DWORD *)this + 16) = v6 + v3;
  IMessageTracer::PushFormatedInts(g_pMsgTracer2, "FighterNumberEx %i, FighterValueEx %i", v2, v3);
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "CAIPlayerEvaluation(MilUnits): Player %i: %i %i %i %i",
    a2,
    *((_DWORD *)this + 13),
    *((_DWORD *)this + 14),
    *((_DWORD *)this + 15),
    *((_DWORD *)this + 16));
}


// address=[0x1311400]
// Decompiled from char *__thiscall CAIPlayerEvaluation::EvaluateBuildings(CAIPlayerEvaluation *this, int a2)
void  CAIPlayerEvaluation::EvaluateBuildings(int) {
  
  int NumberOfBuildings; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+10h] [ebp-8h]

  v5 = 0;
  v4 = 0;
  v6 = 0;
  *((_DWORD *)this + 17) = IAIEnvironment::BuildingGetNumberOfBuildings(a2, 46, 2u);
  *((_DWORD *)this + 18) = IAIEnvironment::BuildingGetNumberOfBuildings(a2, 47, 2u);
  *((_DWORD *)this + 19) = IAIEnvironment::BuildingGetNumberOfBuildings(a2, 48, 2u);
  while ( dword_3D7A36C[2 * v6] )
  {
    NumberOfBuildings = IAIEnvironment::BuildingGetNumberOfBuildings(a2, dword_3D7A36C[2 * v6], 2u);
    v5 += NumberOfBuildings;
    v4 += NumberOfBuildings * dword_3D7A36C[2 * v6++ + 1];
  }
  *((_DWORD *)this + 20) = v5;
  *((_DWORD *)this + 21) = v4;
  return IMessageTracer::PushFormatedInts(
           g_pMsgTracer2,
           "CAIPlayerEvaluation(MilBuildings): Player %i: %i %i",
           a2,
           *((_DWORD *)this + 20),
           *((_DWORD *)this + 21));
}


