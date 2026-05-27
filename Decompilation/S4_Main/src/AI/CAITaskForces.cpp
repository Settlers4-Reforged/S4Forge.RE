#include "CAITaskForces.h"

#include "CAIEntityInfo.h"
#include "CAITaskForce.h"
#include "IAIEnvironment.h"
#include "CBB/CBBSupport.h"
#include "Debug/CTrace.h"
#include "TaskForce/CAITaskForceReservoir.h"
#include "TaskForce/CAITaskForceSquad.h"
#include "TaskForce/CAITaskForceShamans.h"
#include "TaskForce/CAITaskForceManakopters.h"
#include "TaskForce/CAITaskForceDarkGardeners.h"
#include "TaskForce/CAITaskForcePriests.h"
#include "TaskForce/CTaskForceWarMachines.h"
#include "TaskForce/CTaskForceWarShips.h"

// Definitions for class CAITaskForces

// address=[0x13039d0]
// Decompiled from int __cdecl CAITaskForces::TaskForceClass(int a1)
enum T_AI_TASK_FORCE_CLASS __cdecl CAITaskForces::TaskForceClass(enum T_AI_TASK_FORCE_TYPE a1) {
  return g_tAITaskForceTypeToClassMap[a1];
}


// address=[0x1328e40]
// Decompiled from void CAITaskForces::Init()
void __cdecl CAITaskForces::Init(void) {
  CAITaskForces::Done();
  memset(&s_sTaskForcesData, 0, 16);//0x208u); NOTE: This 0x208 includes unused data
  s_bTaskForcesInitialized = 1;
}


// address=[0x1328e70]
// Decompiled from void CAITaskForces::Done()
void __cdecl CAITaskForces::Done(void) {
  if(s_bTaskForcesInitialized) {
    s_bTaskForcesInitialized = 0;
    while(s_sTaskForcesData.m_pFirstTaskForce)
      delete s_sTaskForcesData.m_pFirstTaskForce;
  }
}


// address=[0x1328ed0]
// Decompiled from void CAITaskForces::Execute()
void __cdecl CAITaskForces::Execute(void) {
  // [esp+0h] [ebp-14h]
  // [esp+4h] [ebp-10h]
  // [esp+8h] [ebp-Ch]
  // [esp+Ch] [ebp-8h]
  // [esp+10h] [ebp-4h]

  int v2 = s_sTaskForcesData.m_iTotalNumberOfTaskForces / 8;
  int v3 = s_sTaskForcesData.m_iTaskForceRemainder + s_sTaskForcesData.m_iTotalNumberOfTaskForces % 8;
  if(v3 >= 8) {
    ++v2;
    v3 -= 8;
  }
  s_sTaskForcesData.m_iTaskForceRemainder = v3;
  if(v2 > 0) {
    CAITaskForce *pCurrentTaskForce = s_sTaskForcesData.m_pCurrentTaskForce;
    if(!s_sTaskForcesData.m_pCurrentTaskForce)
      pCurrentTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
    if(pCurrentTaskForce) {
      for(int i = 0; i < v2; ++i) {
        CAITaskForce *m_pFirstTaskForce = pCurrentTaskForce->m_pNextTaskForce;
        if(!pCurrentTaskForce->DecWaitCounter(8u))
          pCurrentTaskForce->Execute();
        pCurrentTaskForce = m_pFirstTaskForce;
        if(!m_pFirstTaskForce) {
          pCurrentTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
          break;
        }
      }
      s_sTaskForcesData.m_pCurrentTaskForce = pCurrentTaskForce;
    } else {
      BB_REPORT("CAITaskForces::Execute(): Invalid number of task forces!")
    }
  }
}


// address=[0x1328fd0]
// Decompiled from void __cdecl CAITaskForces::RemoveEntityFromTaskForce(int a1)
void __cdecl CAITaskForces::RemoveEntityFromTaskForce(int a1) {
  // [esp+0h] [ebp-8h]
  // [esp+4h] [ebp-4h]

  if(a1 > 0) {
    CAIEntityInfo *pEntityInfo = IAIEnvironment::EntityGetEntityInfo(a1, 0);
    if(pEntityInfo) {
      CAITaskForce *pTaskForce = pEntityInfo->TaskForce();
      if(pTaskForce)
        pTaskForce->RemoveEntity(pEntityInfo);
    }
  }
}


// address=[0x1329020]
// Decompiled from CAITaskForcePriestsRoman *__cdecl CAITaskForces::CreateTaskForce(int _iPlayerId, int _iTaskForceType)
class CAITaskForce * __cdecl CAITaskForces::CreateTaskForce(int _iPlayerId, enum T_AI_TASK_FORCE_TYPE _iTaskForceType) {
  if(!s_bTaskForcesInitialized) {
    BB_REPORT("CAITaskForces::CreateTaskForce(): Not initialized!")
    return nullptr;
  }

  if(_iPlayerId < 1 && _iPlayerId > 8) {
    BB_REPORT("CAITaskForces::CreateTaskForce(): Invalid player id!");
    return nullptr;
  }

  int iRace = IAIEnvironment::PlayerRace(_iPlayerId);
  BB_ASSERT((_iPlayerId & ~AI_TASK_FORCE_FLAG_OWNER_ID_MASK) == 0)
  static_assert(~AI_TASK_FORCE_FLAG_OWNER_ID_MASK == 0xFFFFFFF0, "AI_TASK_FORCE_FLAG_OWNER_ID_MASK does not match original game value!");

  CAITaskForce *pTaskForce;
  switch(_iTaskForceType) {
    case AI_TASK_FORCE_TYPE_RESERVOIR:
      pTaskForce = new CAITaskForceReservoir(_iPlayerId);
      break;
    case AI_TASK_FORCE_TYPE_UNKNOWN_2:
    case AI_TASK_FORCE_TYPE_UNKNOWN_3:
    case AI_TASK_FORCE_TYPE_UNKNOWN_4:
    case AI_TASK_FORCE_TYPE_UNKNOWN_5:
    case AI_TASK_FORCE_TYPE_UNKNOWN_6:
    case AI_TASK_FORCE_TYPE_UNKNOWN_7:
      pTaskForce = new CAITaskForceSquad(_iPlayerId, _iTaskForceType, 0);
      break;
    case AI_TASK_FORCE_TYPE_PRIESTS:
      pTaskForce = CAITaskForcePriests::CreatePriestsTaskForce(iRace, _iPlayerId, _iTaskForceType, 0);
      break;
    case AI_TASK_FORCE_TYPE_WARMACHINES:
      pTaskForce = new CTaskForceWarMachines(_iPlayerId, _iTaskForceType, 0);
      break;
    case AI_TASK_FORCE_TYPE_WARSHIPS:
      pTaskForce = new CTaskForceWarShips(_iPlayerId, _iTaskForceType, 0);
      break;
    case AI_TASK_FORCE_TYPE_DARK_GARDENERS:
      pTaskForce = new CAITaskForceDarkGardeners(_iPlayerId, 0);
      break;
    case AI_TASK_FORCE_TYPE_SHAMANS:
      pTaskForce = new CAITaskForceShamans(_iPlayerId, 0);
      break;
    case AI_TASK_FORCE_TYPE_MANAKOPTERS:
      pTaskForce = new CAITaskForceManakopters(_iPlayerId, 0);
      break;
    default:
      BB_REPORT("CAITaskForces::CreateTaskForce(): Unknown task force class!")
      pTaskForce = 0;
      break;
  }

  BB_ASSERT(pTaskForce != 0)
  return pTaskForce;
}


// address=[0x13293f0]
// Decompiled from int CAITaskForces::DbgPrint()
void CAITaskForces::DbgPrint(void) {
  // eax
  // [esp+4h] [ebp-8h]
  // [esp+8h] [ebp-4h]

  CAITaskForce *m_pFirstTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
  int           v3 = 0;
  while(m_pFirstTaskForce) {
    ++v3;
    m_pFirstTaskForce = m_pFirstTaskForce->m_pNextTaskForce;
  }
  if(v3 == CAITaskForces::TotalNumberOfTaskForces())
    CTrace::Print("%i task forces.", v3);
  else
    CTrace::Print("%i task forces, but TotalNumberOfTaskForces() returns %i!", v3, CAITaskForces::TotalNumberOfTaskForces());
}


// address=[0x1329460]
// Decompiled from int CAITaskForces::TotalNumberOfTaskForces()
int __cdecl CAITaskForces::TotalNumberOfTaskForces(void) {
  return s_sTaskForcesData.m_iTotalNumberOfTaskForces;
}


// address=[0x1329470]
// Decompiled from int __cdecl CAITaskForces::NumberOfTaskForces(int a1, int a2)
int __cdecl CAITaskForces::NumberOfTaskForces(int a1, int a2) {
  throw;
  //return dword_3ECCD38[14 * a1 + a2]; Seems to be not used!
}


// address=[0x1329490]
// Decompiled from void __cdecl CAITaskForces::AddTaskForce(struct CAITaskForce *_pTaskForce)
void __cdecl CAITaskForces::AddTaskForce(class CAITaskForce *_pTaskForce) {
  if(!_pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1463, "_pTaskForce != 0") == 1)
    __debugbreak();
  _pTaskForce->m_pPrevTaskForce = 0;
  _pTaskForce->m_pNextTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
  if(s_sTaskForcesData.m_pFirstTaskForce) {
    BB_ASSERT(s_sTaskForcesData.m_pFirstTaskForce->m_pPrevTaskForce == 0)
    s_sTaskForcesData.m_pFirstTaskForce->m_pPrevTaskForce = _pTaskForce;
  } else {
    BB_ASSERT(s_sTaskForcesData.m_iTotalNumberOfTaskForces == 0)
    BB_ASSERT(s_sTaskForcesData.m_pCurrentTaskForce == 0)
    s_sTaskForcesData.m_pCurrentTaskForce = _pTaskForce;
  }
  s_sTaskForcesData.m_pFirstTaskForce = _pTaskForce;
  ++s_sTaskForcesData.m_iTotalNumberOfTaskForces;
}


// address=[0x1329590]
// Decompiled from void __cdecl CAITaskForces::RemoveTaskForce(struct CAITaskForce *_pTaskForce)
void __cdecl CAITaskForces::RemoveTaskForce(class CAITaskForce *_pTaskForce) {
  BB_ASSERT(_pTaskForce != 0)

  if(_pTaskForce) {
    if(_pTaskForce->m_pPrevTaskForce) {
      BB_ASSERT(_pTaskForce->m_pPrevTaskForce->m_pNextTaskForce == _pTaskForce)
      _pTaskForce->m_pPrevTaskForce->m_pNextTaskForce = _pTaskForce->m_pNextTaskForce;
    } else {
      BB_ASSERT(s_sTaskForcesData.m_pFirstTaskForce == _pTaskForce)
      s_sTaskForcesData.m_pFirstTaskForce = _pTaskForce->m_pNextTaskForce;
    }
    if(_pTaskForce->m_pNextTaskForce) {
      BB_ASSERT(_pTaskForce->m_pNextTaskForce->m_pPrevTaskForce == _pTaskForce)
      _pTaskForce->m_pNextTaskForce->m_pPrevTaskForce = _pTaskForce->m_pPrevTaskForce;
    }
    if(s_sTaskForcesData.m_pCurrentTaskForce == _pTaskForce)
      s_sTaskForcesData.m_pCurrentTaskForce = _pTaskForce->m_pNextTaskForce;
    if(!s_sTaskForcesData.m_pCurrentTaskForce)
      s_sTaskForcesData.m_pCurrentTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
    _pTaskForce->m_pPrevTaskForce = 0;
    _pTaskForce->m_pNextTaskForce = 0;
    BB_ASSERT(s_sTaskForcesData.m_iTotalNumberOfTaskForces > 0)
    if(s_sTaskForcesData.m_iTotalNumberOfTaskForces > 0)
      --s_sTaskForcesData.m_iTotalNumberOfTaskForces;
  }
}


