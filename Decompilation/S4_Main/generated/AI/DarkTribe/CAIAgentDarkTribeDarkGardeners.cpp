#include "all_headers.h"

// Definitions for class CAIAgentDarkTribeDarkGardeners

// address=[0x1301980]
// Decompiled from unsigned int __thiscall CAIAgentDarkTribeDarkGardeners::Execute(  CAIAgentDarkTribeDarkGardeners *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentDarkTribeDarkGardeners::Execute(unsigned int,unsigned int) {
  
  struct CAIDarkTribeSectorAI *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  CAIDarkTribeSectorAI *v9; // eax
  int v10; // eax
  int v11; // eax
  CAIDarkTribeSectorAI *v12; // eax
  int v14; // [esp+8h] [ebp-68h]
  CUserToolsManager *TaskForceGroupMemberOfSameClass; // [esp+Ch] [ebp-64h]
  int v16; // [esp+18h] [ebp-58h] BYREF
  int v17; // [esp+1Ch] [ebp-54h] BYREF
  int v18; // [esp+20h] [ebp-50h] BYREF
  int v19; // [esp+24h] [ebp-4Ch] BYREF
  unsigned int v20; // [esp+28h] [ebp-48h]
  unsigned int v21; // [esp+2Ch] [ebp-44h]
  int v22; // [esp+30h] [ebp-40h]
  int v23; // [esp+34h] [ebp-3Ch]
  int v24; // [esp+38h] [ebp-38h] BYREF
  int v25; // [esp+3Ch] [ebp-34h] BYREF
  struct IAIDarkTribeEcoAI *v26; // [esp+40h] [ebp-30h]
  struct IAIDarkTribeEcoAI *v27; // [esp+44h] [ebp-2Ch]
  BOOL v28; // [esp+48h] [ebp-28h]
  CUserToolsManager *v29; // [esp+4Ch] [ebp-24h]
  CAIDarkTribeSectorAgent *v30; // [esp+50h] [ebp-20h]
  int v31; // [esp+54h] [ebp-1Ch] BYREF
  int v32; // [esp+58h] [ebp-18h] BYREF
  int v33; // [esp+5Ch] [ebp-14h]
  int v34; // [esp+60h] [ebp-10h]
  int v35; // [esp+64h] [ebp-Ch]
  CUserToolsManager *i; // [esp+68h] [ebp-8h]
  bool v37; // [esp+6Ch] [ebp-4h]
  bool PositionOfFirstEntity; // [esp+6Dh] [ebp-3h]
  bool v39; // [esp+6Eh] [ebp-2h]
  char v40; // [esp+6Fh] [ebp-1h]

  v30 = this;
  v3 = CAIDarkTribeSectorAgent::SectorAI(this);
  v4 = CAISectorAI::TaskForceGroup(v3);
  for ( i = (CUserToolsManager *)CAITaskForceGroup::FirstTaskForce(v4, 6); i; i = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
    v22 = CAITaskForce::NumberOfEntities(i);
    if ( v22 <= 0 )
    {
      v29 = i;
      if ( i )
        (*(void (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)v29 + 8))(v29, 1);
    }
    else
    {
      PositionOfFirstEntity = CAITaskForce::GetPositionOfFirstEntity(i, &v16, &v17);
      if ( !PositionOfFirstEntity && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 732, "bGetTaskForcePosOk") == 1 )
        __debugbreak();
      v21 = CAITaskForce::Flags(i);
      v14 = CAITaskForce::Status(i);
      v20 = CAITaskForce::Command(i);
      v39 = ((unsigned int)&unk_4000000 & v21) != 0;
      v37 = v39;
      v34 = CAITaskForce::TimeStamp(i);
      v28 = v37 || v34 + 1000 <= a2 || !v34 || v20 != 5;
      v40 = v28;
      if ( !v28 && v34 + 250 <= a2 && CAITaskForce::CmdTimeStamp(i) + 250 <= a2 )
      {
        if ( CAITaskForce::Command(i) != 5
          && BBSupportDbgReport(
               2,
               "AI\\AI_AgentsDark.cpp",
               749,
               "pTaskForce->Command() == AI_TASK_FORCE_CMD_MOVE_TO_WORK_POSITION") == 1 )
        {
          __debugbreak();
        }
        v5 = CAITaskForce::CmdGoal(i);
        if ( !IAIEnvironment::WorldInWorldPackedXY(v5)
          && BBSupportDbgReport(
               2,
               "AI\\AI_AgentsDark.cpp",
               750,
               "g_pAIEnv->WorldInWorldPackedXY(pTaskForce->CmdGoal())") == 1 )
        {
          __debugbreak();
        }
        v6 = CAITaskForce::CmdGoal(i);
        v31 = IAIEnvironment::UnpackXFast(v6);
        v7 = CAITaskForce::CmdGoal(i);
        v32 = IAIEnvironment::UnpackYFast(v7);
        if ( IAIEnvironment::GetNearestGreenBorderElement(&v31, &v32, 10) )
        {
          v8 = IAIEnvironment::PackXYFast(v31, v32);
          (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)i + 32))(i, 5, v8, 0);
        }
        else
        {
          v9 = CAIDarkTribeSectorAgent::SectorAI(v30);
          v27 = CAIDarkTribeSectorAI::EconomyAI(v9);
          v10 = CAITaskForce::CmdGoal(i);
          v33 = (*(int (__thiscall **)(struct IAIDarkTribeEcoAI *, int))(*(_DWORD *)v27 + 8))(v27, v10);
          if ( v33 <= 0 )
          {
            v40 = 1;
          }
          else
          {
            v18 = IAIEnvironment::UnpackXFast(v33);
            v19 = IAIEnvironment::UnpackYFast(v33);
            IAIEnvironment::GetNearestGreenBorderElement(&v18, &v19, 10);
            v11 = IAIEnvironment::PackXYFast(v31, v32);
            (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)i + 32))(i, 5, v11, 0);
          }
        }
      }
      if ( v40 )
      {
        CAITaskForce::ClearEntityAddedFlag(i);
        CAITaskForce::SetTimeStamp(i, a2);
        v12 = CAIDarkTribeSectorAgent::SectorAI(v30);
        v26 = CAIDarkTribeSectorAI::EconomyAI(v12);
        v35 = (*(int (__thiscall **)(struct IAIDarkTribeEcoAI *, int, int, int))(*(_DWORD *)v26 + 12))(
                v26,
                250,
                1000,
                v14);
        if ( v35 > 0 )
        {
          v24 = IAIEnvironment::UnpackXFast(v35);
          v25 = IAIEnvironment::UnpackYFast(v35);
          IAIEnvironment::GetNearestGreenBorderElement(&v24, &v25, 10);
          v23 = IAIEnvironment::GridDistance(v24 - v16, v25 - v17);
          if ( v23 > 5 )
            CAITaskForce::SetTimeStamp(i, a2 + 12 * v23);
          if ( !IAIEnvironment::WorldInWorldPackedXY(v35)
            && BBSupportDbgReport(
                 2,
                 "AI\\AI_AgentsDark.cpp",
                 801,
                 "g_pAIEnv->WorldInWorldPackedXY(iPackedWorkPosition)") == 1 )
          {
            __debugbreak();
          }
          (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)i + 32))(i, 5, v35, 0);
        }
      }
    }
  }
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1322d70]
// Decompiled from CAIAgentDarkTribeDarkGardeners *__thiscall CAIAgentDarkTribeDarkGardeners::CAIAgentDarkTribeDarkGardeners(  CAIAgentDarkTribeDarkGardeners *this)
 CAIAgentDarkTribeDarkGardeners::CAIAgentDarkTribeDarkGardeners(void) {
  
  CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(this, "dark gardeners");
  *(_DWORD *)this = &CAIAgentDarkTribeDarkGardeners::_vftable_;
  return this;
}


// address=[0x1322ee0]
// Decompiled from void __thiscall CAIAgentDarkTribeDarkGardeners::~CAIAgentDarkTribeDarkGardeners(CAIAgentDarkTribeDarkGardeners *this)
 CAIAgentDarkTribeDarkGardeners::~CAIAgentDarkTribeDarkGardeners(void) {
  
  CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(this);
}


