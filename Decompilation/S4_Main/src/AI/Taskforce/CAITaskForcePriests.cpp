#include "CAITaskForcePriests.h"

#include "CAITaskForcePriestsMaya.h"
#include "CAITaskForcePriestsRoman.h"
#include "CAITaskForcePriestsTrojan.h"
#include "CAITaskForcePriestsViking.h"
#include "AI/CAIEntityInfo.h"
#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"
#include "MapObjects/CTmpEntitiesRef.h"
#include "MapObjects/IEntity.h"
#include "Pathing/CScanner.h"

// Definitions for class CAITaskForcePriests

// address=[0x132b400]
// Decompiled from char __thiscall CAITaskForcePriests::NewCommand(CAITaskForcePriests *this, unsigned int a2, int a3, int a4)
bool CAITaskForcePriests::NewCommand(int a2, int a3, int a4) {
  this->SetCommandAndClearStuff(a2, a3, a4);
  this->m_uNextSpellTick = 0;
  if(!a2)
    return true;
  if(a2 == 6) {
    this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_7, 106, 0);
    return true;
  }

  BB_REPORT("CAITaskForcePriests::NewCommand(): Invalid command!")
  return true;
}


// address=[0x132b480]
// Decompiled from CAITaskForcePriests *__thiscall CAITaskForcePriests::CAITaskForcePriests(  CAITaskForcePriests *this,  int iOwnerId,  int tType,  int iFlags)
CAITaskForcePriests::CAITaskForcePriests(int iOwnerId, enum T_AI_TASK_FORCE_TYPE tType, int iFlags) : CAITaskForceEx(iOwnerId, AI_TASK_FORCE_CLASS_PRIESTS, tType, iFlags) {
  this->m_uNextSpellTick = 0;
}


// address=[0x132b4c0]
// Decompiled from char __thiscall CAITaskForcePriests::IsAddEntityOk(CAITaskForcePriests *this, int a2)
bool CAITaskForcePriests::IsAddEntityOk(int a2) {
  if(IAIEnvironment::EntityWarriorType(a2) == 6)
    return 1;
  IAIEnvironment::DbgTracePrintF("CAITaskForcePriests::IsAddEntityOk(): Entity %i is not a priest!", a2);
  return 0;
}


// address=[0x132b500]
// Decompiled from void __thiscall CAITaskForcePriests::Execute(CAITaskForcePriests *this)
void CAITaskForcePriests::Execute(void) {
  unsigned int iTick = IAIEnvironment::TickCounter();
  if(iTick >= this->m_uNextSpellTick) {
    char *pPlayerVars = g_cAIPlayersScriptVars[this->OwnerId()];
    int   v14 = 0;
    if(!pPlayerVars[8u]) {
      int v6 = pPlayerVars[9u];
      int v5 = pPlayerVars[0xAu];
      for(int i = 0; i < 8; ++i) {
        if((v6 & (1 << i)) != 0) {
          if(CMagic::CheckManaForCastSpell(this->OwnerId(), i, v5))
            v14 |= 1 << i;
        }
      }
    }
    char v18 = 0;
    auto cTmpEntityRef = CTmpEntitiesRef(); //NOTE: This TmpRef does not really seem like its of any importance... Should probably just be a pointer to the entity?
    for(CAIEntityInfo *j = this->FirstEntity(); j; j = j->Next()) {
      int      iEntityId = j->EntityId();
      IEntity &rEntity = cTmpEntityRef[iEntityId];
      int      iEntityX = rEntity.X();
      int      iEntityY = rEntity.Y();

      SCountFightersResult v20{}; // [esp+40h] [ebp-1Ch] BYREF
      CScanner::CountFighters(v20, iEntityX, iEntityY, 20, this->OwnerId());
      int iChosenSpell = this->ChooseMilitarySpell(v20, v14);
      if(iChosenSpell >= 0) {
        int iDstXY = this->ChooseMilitarySpellDestination(iChosenSpell, iEntityX, iEntityY, 0);
        if(iDstXY >= 0) {
          IAIEnvironment::EntitySendCastSpellCommand(iEntityId, iChosenSpell, iDstXY);
          v18 = 1;
          break;
        }
      }
    }
    if(v18)
      this->m_uNextSpellTick = iTick + (IAIEnvironment::Rand() & 0x1F) + 45;
    else
      this->m_uNextSpellTick = iTick + 30;
  }

  this->Execute();
}


// address=[0x132b6f0]
// Decompiled from CAITaskForcePriests *__cdecl CAITaskForcePriests::CreatePriestsTaskForce(  int iRace,  int iOwnerId,  int tType,  int iFlags)
CAITaskForcePriests * __cdecl CAITaskForcePriests::CreatePriestsTaskForce(int _iRace, int _iOwnerId, T_AI_TASK_FORCE_TYPE _tType, int _iFlags) {
  switch(_iRace) {
    case 0:
      return new CAITaskForcePriestsRoman(_iOwnerId, _tType, _iFlags);
    case 1:
      return new CAITaskForcePriestsViking(_iOwnerId, _tType, _iFlags);
    case 2:
      return new CAITaskForcePriestsMaya(_iOwnerId, _tType, _iFlags);
    case 4:
      return new CAITaskForcePriestsTrojan(_iOwnerId, _tType, _iFlags);
    default:
      BB_REPORT("CAITaskForcePriests::CreatePriestsTaskForce(): Unkown race!")
      return nullptr;
  }
}


// address=[0x132e610]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForcePriests::~CAITaskForcePriests(CAITaskForce **this)
CAITaskForcePriests::~CAITaskForcePriests(void) = default;


