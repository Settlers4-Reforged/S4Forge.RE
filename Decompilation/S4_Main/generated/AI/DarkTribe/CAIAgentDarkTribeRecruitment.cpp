#include "CAIAgentDarkTribeRecruitment.h"

// Definitions for class CAIAgentDarkTribeRecruitment

// address=[0x1301f00]
// Decompiled from unsigned int __thiscall CAIAgentDarkTribeRecruitment::Execute(  CAIAgentDarkTribeRecruitment *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentDarkTribeRecruitment::Execute(unsigned int,unsigned int) {
  
  struct CAIDarkTribeSectorAI *v3; // eax
  pairNode *v4; // eax
  CAIPlayerScriptVars *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  CAISectorAI *v10; // eax
  int v11; // eax
  CAISectorAI *v12; // eax
  int v13; // eax
  CAISectorAI *v14; // eax
  int v15; // eax
  CAISectorAI *v16; // eax
  int v17; // eax
  int v19; // [esp-10h] [ebp-74h]
  int v20; // [esp-10h] [ebp-74h]
  int v21; // [esp-Ch] [ebp-70h]
  int v22; // [esp-Ch] [ebp-70h]
  int v23; // [esp-8h] [ebp-6Ch]
  int v24; // [esp-8h] [ebp-6Ch]
  int v25; // [esp-4h] [ebp-68h]
  int v26; // [esp-4h] [ebp-68h]
  int v27; // [esp+14h] [ebp-50h]
  int v28; // [esp+18h] [ebp-4Ch]
  int v29; // [esp+1Ch] [ebp-48h]
  int v30; // [esp+20h] [ebp-44h]
  int v31; // [esp+28h] [ebp-3Ch]
  int v32; // [esp+2Ch] [ebp-38h]
  int v33; // [esp+30h] [ebp-34h]
  int v34; // [esp+34h] [ebp-30h]
  int v35; // [esp+3Ch] [ebp-28h]
  int v36; // [esp+40h] [ebp-24h]
  int v37; // [esp+44h] [ebp-20h]
  int v38; // [esp+48h] [ebp-1Ch]
  int v39; // [esp+4Ch] [ebp-18h]
  int NumberOfSettlers; // [esp+50h] [ebp-14h]
  int v41; // [esp+54h] [ebp-10h]
  int v43; // [esp+5Ch] [ebp-8h]

  v3 = CAIDarkTribeSectorAgent::SectorAI(this);
  v4 = (pairNode *)CAISectorAI::PlayerAI(v3);
  v43 = CAIPlayerAI::PlayerId(v4);
  v31 = IAIEnvironment::MagicCurrentManaAmount(v43);
  if ( v31 < 20 )
    return CAIAgent::ExecuteResult(0, 1u);
  v5 = (CAIPlayerScriptVars *)CAIPlayersScriptVars::operator[](v43);
  v35 = CAIPlayerScriptVars::Flags(v5);
  NumberOfSettlers = IAIEnvironment::SettlerGetNumberOfSettlers(v43, 29);
  v41 = IAIEnvironment::SettlerGetNumberOfSettlers(v43, 32);
  v29 = IAIEnvironment::SettlerGetNumberOfSettlers(v43, 52);
  v27 = IAIEnvironment::SettlerGetNumberOfSettlers(v43, 54);
  IAIEnvironment::SettlerGetNumberOfSettlers(v43, 55);
  IAIEnvironment::BuildingGetNumberOfBuildings(v43, 49, 2u);
  v39 = v41 + NumberOfSettlers;
  v6 = CStaticConfigVarInt::operator int(&unk_3E8DD78);
  v33 = 0;
  v32 = 0;
  if ( v41 + NumberOfSettlers >= sub_1303080(v6, 0, 1000) )
  {
    if ( (v35 & 0x10000000) == 0 )
    {
      v25 = CStaticConfigVarInt::operator int(&unk_3E8DDB4);
      v23 = CStaticConfigVarInt::operator int(&unk_3E8DDA8);
      v21 = CStaticConfigVarInt::operator int(&unk_3E8DD9C);
      v19 = CStaticConfigVarInt::operator int(&unk_3E8DD90);
      v7 = CStaticConfigVarInt::operator int(&unk_3E8DD84);
      v30 = sub_1303110(v39, v7, v19, v21, v23, v25);
      v33 = sub_1303080(v30 - v29, 0, 5);
    }
    if ( (v35 & 0x20000000) == 0 )
    {
      v26 = CStaticConfigVarInt::operator int(&unk_3E8DDF0);
      v24 = CStaticConfigVarInt::operator int(&unk_3E8DDE4);
      v22 = CStaticConfigVarInt::operator int(&unk_3E8DDD8);
      v20 = CStaticConfigVarInt::operator int(&unk_3E8DDCC);
      v8 = CStaticConfigVarInt::operator int(&unk_3E8DDC0);
      v28 = sub_1303110(v39, v8, v20, v22, v24, v26);
      v32 = sub_1303080(v28 - v27, 0, 5);
    }
  }
  v9 = CStaticConfigVarInt::operator int(&unk_3E8DD6C);
  v38 = sub_1303080(v9, 0, 4096);
  v37 = 0;
  v36 = 0;
  if ( (v38 * NumberOfSettlers + 128) >> 8 < v41 )
  {
    if ( v38 > 0 )
    {
      v34 = (v41 << 8) / v38;
      if ( v34 < NumberOfSettlers
        && BBSupportDbgReport(2, aAiAiAgentsdark_5, 240, "iScheduledSwordsmanNumber >= iSwordsmanNumber") == 1 )
      {
        __debugbreak();
      }
      v37 = sub_1303080(v34 - NumberOfSettlers, 0, 10);
    }
  }
  else
  {
    v36 = sub_1303080(((v38 * NumberOfSettlers + 128) >> 8) - v41, 0, 10);
  }
  v10 = CAIDarkTribeSectorAgent::SectorAI(this);
  v11 = CAISectorAI::HeadquarterId(v10);
  IAIEnvironment::EventSendDarkTribeProductionMsg(v43, v11, 52, v33);
  v12 = CAIDarkTribeSectorAgent::SectorAI(this);
  v13 = CAISectorAI::HeadquarterId(v12);
  IAIEnvironment::EventSendDarkTribeProductionMsg(v43, v13, 54, v32);
  if ( v39 >= CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v43, 5) )
    return CAIAgent::ExecuteResult(0, 0);
  if ( v31 >= 50 )
  {
    v37 += 4;
    v36 += (4 * v38 + 128) >> 8;
  }
  v14 = CAIDarkTribeSectorAgent::SectorAI(this);
  v15 = CAISectorAI::HeadquarterId(v14);
  IAIEnvironment::EventSendDarkTribeProductionMsg(v43, v15, 29, v37);
  v16 = CAIDarkTribeSectorAgent::SectorAI(this);
  v17 = CAISectorAI::HeadquarterId(v16);
  IAIEnvironment::EventSendDarkTribeProductionMsg(v43, v17, 32, v36);
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1322e40]
// Decompiled from CAIAgentDarkTribeRecruitment *__thiscall CAIAgentDarkTribeRecruitment::CAIAgentDarkTribeRecruitment(  CAIAgentDarkTribeRecruitment *this)
 CAIAgentDarkTribeRecruitment::CAIAgentDarkTribeRecruitment(void) {
  
  CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(this, "dark tribe recruitment");
  *(_DWORD *)this = &CAIAgentDarkTribeRecruitment::_vftable_;
  return this;
}


// address=[0x1322f60]
// Decompiled from void __thiscall CAIAgentDarkTribeRecruitment::~CAIAgentDarkTribeRecruitment(CAIAgentDarkTribeRecruitment *this)
 CAIAgentDarkTribeRecruitment::~CAIAgentDarkTribeRecruitment(void) {
  
  CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(this);
}


