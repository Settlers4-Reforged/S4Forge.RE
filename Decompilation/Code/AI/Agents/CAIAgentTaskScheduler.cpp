#include "CAIAgentTaskScheduler.h"

// Definitions for class CAIAgentTaskScheduler

// address=[0x1303d00]
// Decompiled from // public: virtual unsigned int __thiscall CAIAgentTaskScheduler::Execute(unsigned int,unsigned int)
int __thiscall CAIAgentTaskScheduler::Execute(CAINormalSectorAgent *this, int a2, int a3)

unsigned int  CAIAgentTaskScheduler::Execute(unsigned int,unsigned int) {
  
  struct CAINormalSectorAI *v3; // eax

  if ( !CAINormalSectorAgent::SectorAI(this)
    && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 253, "SectorAI() != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 10)
    && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 254, "m_pTaskExecutionFunc != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = CAINormalSectorAgent::SectorAI(this);
  return (*((int (__thiscall **)(int, int, int))this + 10))((int)v3 + *((_DWORD *)this + 11), a2, a3);
}


