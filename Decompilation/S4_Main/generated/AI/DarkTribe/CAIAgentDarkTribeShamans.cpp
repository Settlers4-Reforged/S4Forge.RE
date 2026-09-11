#include "CAIAgentDarkTribeShamans.h"

// Definitions for class CAIAgentDarkTribeShamans

// address=[0x13022a0]
// Decompiled from unsigned int __thiscall CAIAgentDarkTribeShamans::Execute(CAIDarkTribeSectorAgent *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentDarkTribeShamans::Execute(unsigned int a2, unsigned int a3) {
  
  struct CAIDarkTribeSectorAI *v3; // eax
  int v4; // eax
  unsigned int v5; // esi
  CAIDarkTribeSectorAI *v6; // eax
  int v7; // eax
  CUserToolsManager *TaskForceGroupMemberOfSameClass; // [esp+8h] [ebp-30h]
  int v10; // [esp+14h] [ebp-24h] BYREF
  int v11; // [esp+18h] [ebp-20h] BYREF
  int v12; // [esp+1Ch] [ebp-1Ch]
  int v13; // [esp+20h] [ebp-18h] BYREF
  int v14; // [esp+24h] [ebp-14h] BYREF
  CAIDarkTribeSectorAgent *v15; // [esp+28h] [ebp-10h]
  unsigned int v16; // [esp+2Ch] [ebp-Ch]
  CUserToolsManager *v17; // [esp+30h] [ebp-8h]
  CUserToolsManager *i; // [esp+34h] [ebp-4h]

  v15 = this;
  v3 = CAIDarkTribeSectorAgent::SectorAI(this);
  v4 = CAISectorAI::TaskForceGroup(v3);
  for ( i = (CUserToolsManager *)CAITaskForceGroup::FirstTaskForce((CAITaskForceGroup *)v4, 7);
        i != 0;
        i = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = (CUserToolsManager *)CAITaskForce::NextTaskForceGroupMemberOfSameClass((CAITaskForce *)i);
    v12 = CAITaskForce::NumberOfEntities((CAITaskForce *)i);
    if ( v12 <= 0 )
    {
      v17 = i;
      if ( i != 0 )
      {
        (*(void (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)v17 + 8))(v17, 1);
      }
    }
    else
    {
      v16 = CAITaskForce::Command((CAITaskForce *)i);
      CAITaskForce::Status(i);
      if ( v16 != 3 && v16 != 9 && (CAITaskForce::Flags((CAITaskForce *)i) & 0x20000000) == 0 && (((unsigned int)&s_iMsgTracer2.m_aMessages[15456] & CAITaskForce::Flags((CAITaskForce *)i)) != 0 || CAITaskForce::Command((CAITaskForce *)i) != 1 || (v5 = CAITaskForce::CmdTimeStamp(i)) + IAIEnvironment::Rand() % 0x200 + 200 <= a2) )
      {
        CAITaskForce::ClearEntityAddedFlag((CAITaskForce *)i);
        if ( CAITaskForce::GetPositionOfFirstEntity((CAITaskForce *)i, &v11, &v10) )
        {
          v13 = v11;
          v14 = v10;
          v6 = CAIDarkTribeSectorAgent::SectorAI(v15);
          if ( CAIDarkTribeSectorAI::FindMushroomFarm(v6, (struct _Cnd_internal_imp_t **)&v13, (struct _Mtx_internal_imp_t **)&v14, 15, 120) )
          {
            v7 = IAIEnvironment::PackXYFast(v13, v14);
            (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)i + 32))(i, 1, v7, 0);
          }
        }
      }
    }
  }
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1322e70]
// Decompiled from CAIAgentDarkTribeShamans *__thiscall CAIAgentDarkTribeShamans::CAIAgentDarkTribeShamans(CAIAgentDarkTribeShamans *this)
 CAIAgentDarkTribeShamans::CAIAgentDarkTribeShamans(void) {
  
  CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent((CAIDarkTribeSectorAgent *)this, "shamans");
  *(_DWORD *)this = &CAIAgentDarkTribeShamans::_vftable_;
  return this;
}


// address=[0x1322f80]
// Decompiled from void __thiscall CAIAgentDarkTribeShamans::~CAIAgentDarkTribeShamans(CAIScheduler **this)
 CAIAgentDarkTribeShamans::~CAIAgentDarkTribeShamans(void) {
  
  CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(this);
}


