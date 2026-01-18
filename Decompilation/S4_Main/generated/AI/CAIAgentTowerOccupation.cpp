#include "CAIAgentTowerOccupation.h"

// Definitions for class CAIAgentTowerOccupation

// address=[0x1303df0]
// Decompiled from unsigned int __thiscall CAIAgentTowerOccupation::Execute(  CAIAgentTowerOccupation *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentTowerOccupation::Execute(unsigned int a2, unsigned int a3) {
  
  struct CAINormalSectorAI *v3; // eax
  CAISectorAI *v4; // eax
  int v6; // [esp+0h] [ebp-24h]
  int v8; // [esp+8h] [ebp-1Ch]
  CAIEntityInfo *EntityInfo; // [esp+10h] [ebp-14h]
  int v10; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  CAIEntityInfo *i; // [esp+1Ch] [ebp-8h]
  bool v13; // [esp+23h] [ebp-1h]

  v11 = 0;
  v3 = CAINormalSectorAgent::SectorAI(this);
  for ( i = (CAIEntityInfo *)CAITaskForce::FirstEntity((char *)v3 + 2564); i; i = (CAIEntityInfo *)v6 )
  {
    v6 = CAIEntityInfo::Next(i);
    v8 = CAIEntityInfo::EntityId(i);
    v13 = 1;
    v10 = CAIEntityInfo::TargetId(i);
    if ( v10 > 0 )
    {
      EntityInfo = (CAIEntityInfo *)IAIEnvironment::EntityGetEntityInfo(v10, 0);
      if ( EntityInfo )
        v13 = CAIEntityInfo::TargetId(EntityInfo) != v8;
    }
    if ( v13 )
    {
      v4 = CAINormalSectorAgent::SectorAI(this);
      CAISectorAI::AddEntityToReservoir(v4, v8);
    }
    ++v11;
  }
  if ( v11 )
    return CAIAgent::ExecuteResult(0, 0);
  else
    return CAIAgent::ExecuteResult(0, 0x20u);
}


// address=[0x1325b60]
// Decompiled from CAIAgentTowerOccupation *__thiscall CAIAgentTowerOccupation::CAIAgentTowerOccupation(CAIAgentTowerOccupation *this)
 CAIAgentTowerOccupation::CAIAgentTowerOccupation(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, string__25);
  *(_DWORD *)this = &CAIAgentTowerOccupation::_vftable_;
  return this;
}


// address=[0x1325cf0]
// Decompiled from void __thiscall CAIAgentTowerOccupation::~CAIAgentTowerOccupation(CAIAgentTowerOccupation *this)
 CAIAgentTowerOccupation::~CAIAgentTowerOccupation(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


