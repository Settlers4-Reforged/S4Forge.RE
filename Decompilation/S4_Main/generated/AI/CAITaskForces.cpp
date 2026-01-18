#include "CAITaskForces.h"

// Definitions for class CAITaskForces

// address=[0x13039d0]
// Decompiled from int __cdecl CAITaskForces::TaskForceClass(int a1)
enum T_AI_TASK_FORCE_CLASS __cdecl CAITaskForces::TaskForceClass(enum T_AI_TASK_FORCE_TYPE a1) {
  
  return g_tAITaskForceTypeToClassMap[a1];
}


// address=[0x1328e40]
// Decompiled from void *CAITaskForces::Init()
void __cdecl CAITaskForces::Init(void) {
  
  void *result; // eax

  CAITaskForces::Done();
  result = memset(&dword_3ECCD28, 0, 0x208u);
  dword_3ECCD24 = 1;
  return result;
}


// address=[0x1328e70]
// Decompiled from void CAITaskForces::Done()
void __cdecl CAITaskForces::Done(void) {
  
  if ( dword_3ECCD24 )
  {
    dword_3ECCD24 = 0;
    while ( dword_3ECCD30 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_3ECCD30 + 8))(dword_3ECCD30, 1);
  }
}


// address=[0x1328ed0]
// Decompiled from int CAITaskForces::Execute()
void __cdecl CAITaskForces::Execute(void) {
  
  int result; // eax
  CAITaskForce *v1; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]
  int v3; // [esp+8h] [ebp-Ch]
  int v4; // [esp+Ch] [ebp-8h]
  CAITaskForce *v5; // [esp+10h] [ebp-4h]

  v3 = dword_3ECCD28 / 8;
  v4 = dword_3ECCD2C + dword_3ECCD28 % 8;
  if ( v4 >= 8 )
  {
    ++v3;
    v4 -= 8;
  }
  result = v4;
  dword_3ECCD2C = v4;
  if ( v3 <= 0 )
    return result;
  v5 = (CAITaskForce *)dword_3ECCD34;
  if ( !dword_3ECCD34 )
    v5 = (CAITaskForce *)dword_3ECCD30;
  if ( v5 )
  {
    for ( i = 0; i < v3; ++i )
    {
      v1 = (CAITaskForce *)*((_DWORD *)v5 + 7);
      if ( !CAITaskForce::DecWaitCounter(v5, 8u) )
        (*(void (__thiscall **)(CAITaskForce *))(*(_DWORD *)v5 + 40))(v5);
      v5 = v1;
      if ( !v1 )
      {
        v5 = (CAITaskForce *)dword_3ECCD30;
        break;
      }
    }
    result = (int)v5;
    dword_3ECCD34 = (int)v5;
  }
  else
  {
    result = BBSupportDbgReport(
               1,
               "AI\\AI_TaskForces.cpp",
               1408,
               "CAITaskForces::Execute(): Invalid number of task forces!");
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x1328fd0]
// Decompiled from void __cdecl CAITaskForces::RemoveEntityFromTaskForce(int a1)
void __cdecl CAITaskForces::RemoveEntityFromTaskForce(int a1) {
  
  int v1; // [esp+0h] [ebp-8h]
  int EntityInfo; // [esp+4h] [ebp-4h]

  if ( a1 > 0 )
  {
    EntityInfo = IAIEnvironment::EntityGetEntityInfo(a1, 0);
    if ( EntityInfo )
    {
      v1 = CAIEntityInfo::TaskForce(EntityInfo);
      if ( v1 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v1 + 24))(v1, EntityInfo);
    }
  }
}


// address=[0x1329020]
// Decompiled from int __cdecl CAITaskForces::CreateTaskForce(int a1, int a2)
class CAITaskForce * __cdecl CAITaskForces::CreateTaskForce(int a1, enum T_AI_TASK_FORCE_TYPE a2) {
  
  int result; // eax
  int v3; // [esp+18h] [ebp-64h]
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
  int v14; // [esp+50h] [ebp-2Ch]
  void *v15; // [esp+54h] [ebp-28h]
  CAITaskForceReservoir *v16; // [esp+58h] [ebp-24h]
  CAITaskForceReservoir *C; // [esp+5Ch] [ebp-20h]
  __int64 v18; // [esp+60h] [ebp-1Ch]
  int PriestsTaskForce; // [esp+6Ch] [ebp-10h]

  if ( dword_3ECCD24 )
  {
    HIDWORD(v18) = a1 < 1;
    LODWORD(v18) = a1 > 8;
    if ( v18 )
    {
      if ( BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 1279, "CAITaskForces::CreateTaskForce(): Invalid player id!") == 1 )
        __debugbreak();
      return 0;
    }
    else
    {
      v3 = IAIEnvironment::PlayerRace(a1);
      if ( (a1 & 0xFFFFFFF0) != 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1286, "(_iPlayerId & ~AI_TASK_FORCE_FLAG_OWNER_ID_MASK) == 0") == 1 )
      {
        __debugbreak();
      }
      switch ( a2 )
      {
        case 1:
          C = (CAITaskForceReservoir *)operator new(0x50u);
          if ( C )
            v16 = CAITaskForceReservoir::CAITaskForceReservoir(C, a1);
          else
            v16 = 0;
          PriestsTaskForce = (int)v16;
          goto LABEL_45;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
          v15 = operator new(0x70u);
          if ( v15 )
            v14 = CAITaskForceSquad::CAITaskForceSquad(v15, a1, a2, 0);
          else
            v14 = 0;
          PriestsTaskForce = v14;
          goto LABEL_45;
        case 8:
          PriestsTaskForce = CAITaskForcePriests::CreatePriestsTaskForce(v3, a1, a2, 0);
          goto LABEL_45;
        case 9:
          v13 = operator new(0x60u);
          if ( v13 )
            v12 = CTaskForceWarMachines::CTaskForceWarMachines(v13, a1, a2, 0);
          else
            v12 = 0;
          PriestsTaskForce = v12;
          goto LABEL_45;
        case 10:
          v11 = operator new(0x60u);
          if ( v11 )
            v10 = CTaskForceWarShips::CTaskForceWarShips(v11, a1, a2, 0);
          else
            v10 = 0;
          PriestsTaskForce = v10;
          goto LABEL_45;
        case 11:
          v9 = (CAITaskForceDarkGardeners *)operator new(0x60u);
          if ( v9 )
            v8 = CAITaskForceDarkGardeners::CAITaskForceDarkGardeners(v9, a1, 0);
          else
            v8 = 0;
          PriestsTaskForce = (int)v8;
          goto LABEL_45;
        case 12:
          v7 = (CAITaskForceShamans *)operator new(0x60u);
          if ( v7 )
            v6 = CAITaskForceShamans::CAITaskForceShamans(v7, a1, 0);
          else
            v6 = 0;
          PriestsTaskForce = (int)v6;
          goto LABEL_45;
        case 13:
          v5 = (CAITaskForceManakopters *)operator new(0x60u);
          if ( v5 )
            v4 = CAITaskForceManakopters::CAITaskForceManakopters(v5, a1, 0);
          else
            v4 = 0;
          PriestsTaskForce = (int)v4;
LABEL_45:
          if ( !PriestsTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1350, "pTaskForce != 0") == 1 )
            __debugbreak();
          result = PriestsTaskForce;
          break;
        default:
          if ( BBSupportDbgReport(
                 1,
                 "AI\\AI_TaskForces.cpp",
                 1344,
                 "CAITaskForces::CreateTaskForce(): Unknown task force class!") == 1 )
            __debugbreak();
          result = 0;
          break;
      }
    }
  }
  else
  {
    if ( BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 1272, "CAITaskForces::CreateTaskForce(): Not initialized!") == 1 )
      __debugbreak();
    return 0;
  }
  return result;
}


// address=[0x13293f0]
// Decompiled from int CAITaskForces::DbgPrint()
void  CAITaskForces::DbgPrint(void) {
  
  int v1; // eax
  int v2; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  v2 = dword_3ECCD30;
  v3 = 0;
  while ( v2 )
  {
    ++v3;
    v2 = *(_DWORD *)(v2 + 28);
  }
  if ( v3 == CAITaskForces::TotalNumberOfTaskForces() )
    return CTrace::Print("%i task forces.", v3);
  v1 = CAITaskForces::TotalNumberOfTaskForces();
  return CTrace::Print("%i task forces, but TotalNumberOfTaskForces() returns %i!", v3, v1);
}


// address=[0x1329460]
// Decompiled from int CAITaskForces::TotalNumberOfTaskForces()
int __cdecl CAITaskForces::TotalNumberOfTaskForces(void) {
  
  return dword_3ECCD28;
}


// address=[0x1329470]
// Decompiled from int __cdecl CAITaskForces::NumberOfTaskForces(int a1, int a2)
int __cdecl CAITaskForces::NumberOfTaskForces(int a1, int a2) {
  
  return dword_3ECCD38[14 * a1 + a2];
}


// address=[0x1329490]
// Decompiled from int __cdecl CAITaskForces::AddTaskForce(struct CAITaskForce *a1)
void __cdecl CAITaskForces::AddTaskForce(class CAITaskForce * a1) {
  
  if ( !a1 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1463, "_pTaskForce != 0") == 1 )
    __debugbreak();
  *((_DWORD *)a1 + 6) = 0;
  *((_DWORD *)a1 + 7) = dword_3ECCD30;
  if ( dword_3ECCD30 )
  {
    if ( *(_DWORD *)(dword_3ECCD30 + 24)
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           1470,
           "s_sTaskForcesData.m_pFirstTaskForce->m_pPrevTaskForce == 0") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(dword_3ECCD30 + 24) = a1;
  }
  else
  {
    if ( dword_3ECCD28
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1476, "s_sTaskForcesData.m_iTotalNumberOfTaskForces == 0") == 1 )
    {
      __debugbreak();
    }
    if ( dword_3ECCD34
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1477, "s_sTaskForcesData.m_pCurrentTaskForce == 0") == 1 )
    {
      __debugbreak();
    }
    dword_3ECCD34 = (int)a1;
  }
  dword_3ECCD30 = (int)a1;
  return ++dword_3ECCD28;
}


// address=[0x1329590]
// Decompiled from struct CAITaskForce *__cdecl CAITaskForces::RemoveTaskForce(struct CAITaskForce *a1)
void __cdecl CAITaskForces::RemoveTaskForce(class CAITaskForce * a1) {
  
  struct CAITaskForce *result; // eax

  if ( !a1 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1494, "_pTaskForce != 0") == 1 )
    __debugbreak();
  result = 0;
  if ( !a1 )
    return result;
  if ( *((_DWORD *)a1 + 6) )
  {
    if ( *(struct CAITaskForce **)(*((_DWORD *)a1 + 6) + 28) != a1
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           1500,
           "_pTaskForce->m_pPrevTaskForce->m_pNextTaskForce == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(*((_DWORD *)a1 + 6) + 28) = *((_DWORD *)a1 + 7);
  }
  else
  {
    if ( (struct CAITaskForce *)dword_3ECCD30 != a1
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1506, "s_sTaskForcesData.m_pFirstTaskForce == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    dword_3ECCD30 = *((_DWORD *)a1 + 7);
  }
  if ( *((_DWORD *)a1 + 7) )
  {
    if ( *(struct CAITaskForce **)(*((_DWORD *)a1 + 7) + 24) != a1
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           1513,
           "_pTaskForce->m_pNextTaskForce->m_pPrevTaskForce == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(*((_DWORD *)a1 + 7) + 24) = *((_DWORD *)a1 + 6);
  }
  if ( (struct CAITaskForce *)dword_3ECCD34 == a1 )
    dword_3ECCD34 = *((_DWORD *)a1 + 7);
  if ( !dword_3ECCD34 )
    dword_3ECCD34 = dword_3ECCD30;
  result = a1;
  *((_DWORD *)a1 + 6) = 0;
  *((_DWORD *)a1 + 7) = 0;
  if ( dword_3ECCD28 <= 0 )
  {
    result = (struct CAITaskForce *)BBSupportDbgReport(
                                      2,
                                      "AI\\AI_TaskForces.cpp",
                                      1531,
                                      "s_sTaskForcesData.m_iTotalNumberOfTaskForces > 0");
    if ( result == (struct CAITaskForce *)1 )
      __debugbreak();
  }
  if ( dword_3ECCD28 > 0 )
    return (struct CAITaskForce *)--dword_3ECCD28;
  return result;
}


