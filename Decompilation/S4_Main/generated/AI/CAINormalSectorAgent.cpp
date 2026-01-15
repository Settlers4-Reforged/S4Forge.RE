#include "CAINormalSectorAgent.h"

// Definitions for class CAINormalSectorAgent

// address=[0x1300fe0]
// Decompiled from CAINormalSectorAgent *__thiscall CAINormalSectorAgent::CAINormalSectorAgent(CAINormalSectorAgent *this, const char *a2)
 CAINormalSectorAgent::CAINormalSectorAgent(char const *) {
  
  CAIAgent::CAIAgent(this, a2);
  *(_DWORD *)this = &CAINormalSectorAgent::_vftable_;
  *((_DWORD *)this + 9) = 0;
  return this;
}


// address=[0x1301040]
// Decompiled from void __thiscall CAINormalSectorAgent::~CAINormalSectorAgent(CAINormalSectorAgent *this)
 CAINormalSectorAgent::~CAINormalSectorAgent(void) {
  
  CAIAgent::~CAIAgent(this);
}


// address=[0x1301810]
// Decompiled from int __thiscall CAINormalSectorAgent::SectorAI(CAINormalSectorAgent *this)
class CAINormalSectorAI *  CAINormalSectorAgent::SectorAI(void)const {
  
  return *((_DWORD *)this + 9);
}


// address=[0x1303c90]
// Decompiled from CAINormalSectorAgent *__thiscall CAINormalSectorAgent::AttachSectorAI(  CAINormalSectorAgent *this,  struct CAINormalSectorAI *a2)
void  CAINormalSectorAgent::AttachSectorAI(class CAINormalSectorAI *) {
  
  CAINormalSectorAgent *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 235, "_pSectorAI != 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 9) && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 236, "m_pSectorAI == 0") == 1 )
    __debugbreak();
  result = this;
  *((_DWORD *)this + 9) = a2;
  return result;
}


