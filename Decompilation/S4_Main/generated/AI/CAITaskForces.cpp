#if FALSE
#include "CAITaskForces.h"

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
  memset(&s_sTaskForcesData, 0, 0x208u);
  s_bTaskForcesInitialized = 1;
}


// address=[0x1328e70]
// Decompiled from void CAITaskForces::Done()
void __cdecl CAITaskForces::Done(void) {
  
  if ( s_bTaskForcesInitialized )
  {
    s_bTaskForcesInitialized = 0;
    while ( s_sTaskForcesData.m_pFirstTaskForce )
    {
      s_sTaskForcesData.m_pFirstTaskForce->dtor(s_sTaskForcesData.m_pFirstTaskForce, 1);
    }
  }
}


// address=[0x1328ed0]
// Decompiled from void CAITaskForces::Execute()
void __cdecl CAITaskForces::Execute(void) {
  
  CAITaskForce *m_pFirstTaskForce; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]
  int v2; // [esp+8h] [ebp-Ch]
  int v3; // [esp+Ch] [ebp-8h]
  CAITaskForce *m_pCurrentTaskForce; // [esp+10h] [ebp-4h]

  v2 = s_sTaskForcesData.m_iTotalNumberOfTaskForces / 8;
  v3 = s_sTaskForcesData.m_iTaskForceRemainder + s_sTaskForcesData.m_iTotalNumberOfTaskForces % 8;
  if ( v3 >= 8 )
  {
    ++v2;
    v3 -= 8;
  }
  s_sTaskForcesData.m_iTaskForceRemainder = v3;
  if ( v2 > 0 )
  {
    m_pCurrentTaskForce = s_sTaskForcesData.m_pCurrentTaskForce;
    if ( !s_sTaskForcesData.m_pCurrentTaskForce )
    {
      m_pCurrentTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
    }
    if ( m_pCurrentTaskForce )
    {
      for ( i = 0;
            i < v2;
            ++i )
      {
        m_pFirstTaskForce = m_pCurrentTaskForce->m_pFirstTaskForce;
        if ( !CAITaskForce::DecWaitCounter(m_pCurrentTaskForce, 8u) )
        {
          m_pCurrentTaskForce->Execute(m_pCurrentTaskForce);
        }
        m_pCurrentTaskForce = m_pFirstTaskForce;
        if ( !m_pFirstTaskForce )
        {
          m_pCurrentTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
          break;
        }
      }
      s_sTaskForcesData.m_pCurrentTaskForce = m_pCurrentTaskForce;
    }
    else if ( BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 1408, "CAITaskForces::Execute(): Invalid number of task forces!") == 1 )
    {
      __debugbreak();
    }
  }
}


// address=[0x1328fd0]
// Decompiled from void __cdecl CAITaskForces::RemoveEntityFromTaskForce(int a1)
void __cdecl CAITaskForces::RemoveEntityFromTaskForce(int a1) {
  
  struct CAITaskForce *v1; // [esp+0h] [ebp-8h]
  CAIEntityInfo *EntityInfo; // [esp+4h] [ebp-4h]

  if ( a1 > 0 )
  {
    EntityInfo = IAIEnvironment::EntityGetEntityInfo(a1, 0);
    if ( EntityInfo )
    {
      v1 = CAIEntityInfo::TaskForce(EntityInfo);
      if ( v1 )
      {
        v1->RemoveEntity(v1, EntityInfo);
      }
    }
  }
}


// address=[0x1329020]
// Decompiled from CAITaskForce *__cdecl CAITaskForces::CreateTaskForce(int iPlayerId, T_AI_TASK_FORCE_TYPE iTaskForceType)
class CAITaskForce * __cdecl CAITaskForces::CreateTaskForce(int iPlayerId, enum T_AI_TASK_FORCE_TYPE iTaskForceType) {
  
  CAITaskForce *result; // eax
  int iRace; // [esp+18h] [ebp-64h]
  CAITaskForceManakopters *v4; // [esp+28h] [ebp-54h]
  CAITaskForceManakopters *v5; // [esp+2Ch] [ebp-50h]
  CAITaskForceShamans *v6; // [esp+30h] [ebp-4Ch]
  CAITaskForceShamans *v7; // [esp+34h] [ebp-48h]
  CAITaskForceDarkGardeners *v8; // [esp+38h] [ebp-44h]
  CAITaskForceDarkGardeners *v9; // [esp+3Ch] [ebp-40h]
  int v10; // [esp+40h] [ebp-3Ch]
  void *v11; // [esp+44h] [ebp-38h]
  int v12; // [esp+48h] [ebp-34h]
  void *v13; // [esp+4Ch] [ebp-30h]
  CAITaskForceSquad *v14; // [esp+50h] [ebp-2Ch]
  CAITaskForceSquad *v15; // [esp+54h] [ebp-28h]
  CAITaskForceReservoir *v16; // [esp+58h] [ebp-24h]
  CAITaskForceReservoir *C; // [esp+5Ch] [ebp-20h]
  __int64 v18; // [esp+60h] [ebp-1Ch]
  CAITaskForcePriestsRoman *pTaskForce; // [esp+6Ch] [ebp-10h]

  if ( s_bTaskForcesInitialized )
  {
    HIDWORD(v18) = iPlayerId < 1;
    LODWORD(v18) = iPlayerId > 8;
    if ( v18 )
    {
      if ( BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 1279, "CAITaskForces::CreateTaskForce(): Invalid player id!") == 1 )
      {
        __debugbreak();
      }
      return 0;
    }
    else
    {
      iRace = IAIEnvironment::PlayerRace(iPlayerId);
      if ( (iPlayerId & ~0xFu) != 0 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1286, "(_iPlayerId & ~AI_TASK_FORCE_FLAG_OWNER_ID_MASK) == 0") == 1 )
      {
        __debugbreak();
      }
      switch ( iTaskForceType )
      {
        case AI_TASK_FORCE_TYPE_RESERVOIR:
          C = (CAITaskForceReservoir *)operator new(0x50u);
          if ( C )
          {
            v16 = CAITaskForceReservoir::CAITaskForceReservoir(C, iPlayerId);
          }
          else
          {
            v16 = 0;
          }
          pTaskForce = (CAITaskForcePriestsRoman *)v16;
          goto LABEL_45;
        case AI_TASK_FORCE_TYPE_UNKNOWN_2:
        case AI_TASK_FORCE_TYPE_UNKNOWN_3:
        case AI_TASK_FORCE_TYPE_UNKNOWN_4:
        case AI_TASK_FORCE_TYPE_UNKNOWN_5:
        case AI_TASK_FORCE_TYPE_UNKNOWN_6:
        case AI_TASK_FORCE_TYPE_UNKNOWN_7:
          v15 = (CAITaskForceSquad *)operator new(0x70u);
          if ( v15 )
          {
            v14 = CAITaskForceSquad::CAITaskForceSquad(v15, iPlayerId, iTaskForceType, 0);
          }
          else
          {
            v14 = 0;
          }
          pTaskForce = (CAITaskForcePriestsRoman *)v14;
          goto LABEL_45;
        case AI_TASK_FORCE_TYPE_PRIESTS:
          pTaskForce = CAITaskForcePriests::CreatePriestsTaskForce(iRace, iPlayerId, iTaskForceType, 0);
          goto LABEL_45;
        case AI_TASK_FORCE_TYPE_UNKNOWN_9:
          v13 = operator new(0x60u);
          if ( v13 )
          {
            v12 = CTaskForceWarMachines::CTaskForceWarMachines(v13, iPlayerId, iTaskForceType, 0);
          }
          else
          {
            v12 = 0;
          }
          pTaskForce = (CAITaskForcePriestsRoman *)v12;
          goto LABEL_45;
        case AI_TASK_FORCE_TYPE_UNKNOWN_10:
          v11 = operator new(0x60u);
          if ( v11 )
          {
            v10 = CTaskForceWarShips::CTaskForceWarShips(v11, iPlayerId, iTaskForceType, 0);
          }
          else
          {
            v10 = 0;
          }
          pTaskForce = (CAITaskForcePriestsRoman *)v10;
          goto LABEL_45;
        case AI_TASK_FORCE_TYPE_DARK_GARDENERS:
          v9 = (CAITaskForceDarkGardeners *)operator new(0x60u);
          if ( v9 )
          {
            v8 = CAITaskForceDarkGardeners::CAITaskForceDarkGardeners(v9, iPlayerId, 0);
          }
          else
          {
            v8 = 0;
          }
          pTaskForce = (CAITaskForcePriestsRoman *)v8;
          goto LABEL_45;
        case AI_TASK_FORCE_TYPE_SHAMANS:
          v7 = (CAITaskForceShamans *)operator new(0x60u);
          if ( v7 )
          {
            v6 = CAITaskForceShamans::CAITaskForceShamans(v7, iPlayerId, 0);
          }
          else
          {
            v6 = 0;
          }
          pTaskForce = (CAITaskForcePriestsRoman *)v6;
          goto LABEL_45;
        case AI_TASK_FORCE_TYPE_MANAKOPTERS:
          v5 = (CAITaskForceManakopters *)operator new(0x60u);
          if ( v5 )
          {
            v4 = CAITaskForceManakopters::CAITaskForceManakopters(v5, iPlayerId, 0);
          }
          else
          {
            v4 = 0;
          }
          pTaskForce = (CAITaskForcePriestsRoman *)v4;
LABEL_45:
          if ( !pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1350, "pTaskForce != 0") == 1 )
          {
            __debugbreak();
          }
          result = pTaskForce;
          break;
        default:
          if ( BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 1344, "CAITaskForces::CreateTaskForce(): Unknown task force class!") == 1 )
          {
            __debugbreak();
          }
          result = 0;
          break;
      }
    }
  }
  else
  {
    if ( BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 1272, "CAITaskForces::CreateTaskForce(): Not initialized!") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
  return result;
}


// address=[0x13293f0]
// Decompiled from int CAITaskForces::DbgPrint()
void  CAITaskForces::DbgPrint(void) {
  
  int v1; // eax
  CAITaskForce *m_pFirstTaskForce; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  m_pFirstTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
  v3 = 0;
  while ( m_pFirstTaskForce )
  {
    ++v3;
    m_pFirstTaskForce = m_pFirstTaskForce->m_pFirstTaskForce;
  }
  if ( v3 == CAITaskForces::TotalNumberOfTaskForces() )
  {
    return CTrace::Print("%i task forces.", v3);
  }
  v1 = CAITaskForces::TotalNumberOfTaskForces();
  return CTrace::Print("%i task forces, but TotalNumberOfTaskForces() returns %i!", v3, v1);
}


// address=[0x1329460]
// Decompiled from int CAITaskForces::TotalNumberOfTaskForces()
int __cdecl CAITaskForces::TotalNumberOfTaskForces(void) {
  
  return s_sTaskForcesData.m_iTotalNumberOfTaskForces;
}


// address=[0x1329470]
// Decompiled from int __cdecl CAITaskForces::NumberOfTaskForces(int a1, int a2)
int __cdecl CAITaskForces::NumberOfTaskForces(int a1, int a2) {
  
  return dword_3ECCD38[14 * a1 + a2];
}


// address=[0x1329490]
// Decompiled from void __cdecl CAITaskForces::AddTaskForce(struct CAITaskForce *_pTaskForce)
void __cdecl CAITaskForces::AddTaskForce(class CAITaskForce * _pTaskForce) {
  
  if ( !_pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1463, "_pTaskForce != 0") == 1 )
  {
    __debugbreak();
  }
  _pTaskForce->m_pPrevTaskForce = 0;
  _pTaskForce->m_pFirstTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
  if ( s_sTaskForcesData.m_pFirstTaskForce )
  {
    if ( s_sTaskForcesData.m_pFirstTaskForce->m_pPrevTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1470, "s_sTaskForcesData.m_pFirstTaskForce->m_pPrevTaskForce == 0") == 1 )
    {
      __debugbreak();
    }
    s_sTaskForcesData.m_pFirstTaskForce->m_pPrevTaskForce = _pTaskForce;
  }
  else
  {
    if ( s_sTaskForcesData.m_iTotalNumberOfTaskForces && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1476, "s_sTaskForcesData.m_iTotalNumberOfTaskForces == 0") == 1 )
    {
      __debugbreak();
    }
    if ( s_sTaskForcesData.m_pCurrentTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1477, "s_sTaskForcesData.m_pCurrentTaskForce == 0") == 1 )
    {
      __debugbreak();
    }
    s_sTaskForcesData.m_pCurrentTaskForce = _pTaskForce;
  }
  s_sTaskForcesData.m_pFirstTaskForce = _pTaskForce;
  ++s_sTaskForcesData.m_iTotalNumberOfTaskForces;
}


// address=[0x1329590]
// Decompiled from void __cdecl CAITaskForces::RemoveTaskForce(struct CAITaskForce *_pTaskForce)
void __cdecl CAITaskForces::RemoveTaskForce(class CAITaskForce * _pTaskForce) {
  
  if ( !_pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1494, "_pTaskForce != 0") == 1 )
  {
    __debugbreak();
  }
  if ( _pTaskForce )
  {
    if ( _pTaskForce->m_pPrevTaskForce )
    {
      if ( _pTaskForce->m_pPrevTaskForce->m_pFirstTaskForce != _pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1500, "_pTaskForce->m_pPrevTaskForce->m_pNextTaskForce == _pTaskForce") == 1 )
      {
        __debugbreak();
      }
      _pTaskForce->m_pPrevTaskForce->m_pFirstTaskForce = _pTaskForce->m_pFirstTaskForce;
    }
    else
    {
      if ( s_sTaskForcesData.m_pFirstTaskForce != _pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1506, "s_sTaskForcesData.m_pFirstTaskForce == _pTaskForce") == 1 )
      {
        __debugbreak();
      }
      s_sTaskForcesData.m_pFirstTaskForce = _pTaskForce->m_pFirstTaskForce;
    }
    if ( _pTaskForce->m_pFirstTaskForce )
    {
      if ( _pTaskForce->m_pFirstTaskForce->m_pPrevTaskForce != _pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1513, "_pTaskForce->m_pNextTaskForce->m_pPrevTaskForce == _pTaskForce") == 1 )
      {
        __debugbreak();
      }
      _pTaskForce->m_pFirstTaskForce->m_pPrevTaskForce = _pTaskForce->m_pPrevTaskForce;
    }
    if ( s_sTaskForcesData.m_pCurrentTaskForce == _pTaskForce )
    {
      s_sTaskForcesData.m_pCurrentTaskForce = _pTaskForce->m_pFirstTaskForce;
    }
    if ( !s_sTaskForcesData.m_pCurrentTaskForce )
    {
      s_sTaskForcesData.m_pCurrentTaskForce = s_sTaskForcesData.m_pFirstTaskForce;
    }
    _pTaskForce->m_pPrevTaskForce = 0;
    _pTaskForce->m_pFirstTaskForce = 0;
    if ( s_sTaskForcesData.m_iTotalNumberOfTaskForces <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1531, "s_sTaskForcesData.m_iTotalNumberOfTaskForces > 0") == 1 )
    {
      __debugbreak();
    }
    if ( s_sTaskForcesData.m_iTotalNumberOfTaskForces > 0 )
    {
      --s_sTaskForcesData.m_iTotalNumberOfTaskForces;
    }
  }
}


#endif // Already implemented
