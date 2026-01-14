#include "all_headers.h"

// Definitions for class CAITaskForceGroup

// address=[0x12fd0d0]
// Decompiled from int __thiscall CAITaskForceGroup::FirstTaskForce(_DWORD *this, int a2)
class CAITaskForce *  CAITaskForceGroup::FirstTaskForce(enum T_AI_TASK_FORCE_CLASS)const {
  
  return this[a2 + 26];
}


// address=[0x13015c0]
// Decompiled from int __thiscall CAITaskForceGroup::NumberOfTaskForcesOfType(_DWORD *this, int a2)
int  CAITaskForceGroup::NumberOfTaskForcesOfType(enum T_AI_TASK_FORCE_TYPE)const {
  
  return this[a2 + 12];
}


// address=[0x1303970]
// Decompiled from int __thiscall CAITaskForceGroup::NumberOfTaskForcesOfClass(_DWORD *this, int a2)
int  CAITaskForceGroup::NumberOfTaskForcesOfClass(enum T_AI_TASK_FORCE_CLASS)const {
  
  return this[a2 + 3];
}


// address=[0x1328380]
// Decompiled from CAITaskForceGroup *__thiscall CAITaskForceGroup::CAITaskForceGroup(CAITaskForceGroup *this, int a2)
 CAITaskForceGroup::CAITaskForceGroup(int) {
  
  *(_DWORD *)this = CAITaskForceGroup::_vftable_;
  memset((char *)this + 4, 0, 0x88u);
  *((_DWORD *)this + 1) = a2;
  return this;
}


// address=[0x13283c0]
// Decompiled from void __thiscall CAITaskForceGroup::~CAITaskForceGroup(CAITaskForceGroup *this)
 CAITaskForceGroup::~CAITaskForceGroup(void) {
  
  *(_DWORD *)this = CAITaskForceGroup::_vftable_;
  CAITaskForceGroup::DeleteAllTaskForces(this);
}


// address=[0x1328410]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForceGroup::CreateTaskForce(CAITaskForceGroup *this, int a2)
class CAITaskForce *  CAITaskForceGroup::CreateTaskForce(enum T_AI_TASK_FORCE_TYPE) {
  
  struct CAITaskForce *TaskForce; // [esp+4h] [ebp-4h]

  TaskForce = (struct CAITaskForce *)CAITaskForces::CreateTaskForce(*((_DWORD *)this + 1), a2);
  if ( TaskForce )
    CAITaskForceGroup::AddTaskForce(this, TaskForce);
  return TaskForce;
}


// address=[0x1328450]
// Decompiled from void __thiscall CAITaskForceGroup::DeleteAllTaskForces(CAITaskForceGroup *this)
void  CAITaskForceGroup::DeleteAllTaskForces(void) {
  
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-20h]
  CAITaskForce *j; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  for ( i = 0; i < 9; ++i )
  {
    for ( j = (CAITaskForce *)CAITaskForceGroup::FirstTaskForce(this, i); j; j = TaskForceGroupMemberOfSameClass )
    {
      TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(j);
      (*(void (__thiscall **)(CAITaskForce *, int))(*(_DWORD *)j + 8))(j, 1);
    }
    if ( CAITaskForceGroup::FirstTaskForce(this, i) )
    {
      if ( BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 880, "FirstTaskForce(tTaskForceClass) == 0") == 1 )
        __debugbreak();
    }
  }
}


// address=[0x1328510]
// Decompiled from int __thiscall CAITaskForceGroup::Load(CAITaskForceGroup *this, struct IS4Chunk *a2)
void  CAITaskForceGroup::Load(class IS4Chunk &) {
  
  int v2; // eax
  int v4; // [esp-4h] [ebp-30h]
  int v5; // [esp+0h] [ebp-2Ch]
  int v6; // [esp+8h] [ebp-24h]
  _DWORD *v7; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-18h]
  int v9; // [esp+18h] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-10h]
  int i; // [esp+24h] [ebp-8h]
  struct CAITaskForce *TaskForce; // [esp+28h] [ebp-4h]

  CAITaskForceGroup::DeleteAllTaskForces(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371968);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371966);
  v4 = CAITaskForceGroup::PlayerId(this);
  v2 = CAITaskForceGroup::PlayerId(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, v2, v4);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371965);
  v9 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  if ( v9 <= 0 )
    return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371967);
  v7 = operator new[](4 * v9);
  for ( i = 0; i < v9; ++i )
  {
    v6 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 13);
    v5 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    TaskForce = CAITaskForceGroup::CreateTaskForce(this, v6);
    if ( !TaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1012, "pTaskForce != 0") == 1 )
      __debugbreak();
    v7[i] = TaskForce;
    (**(void (__thiscall ***)(struct CAITaskForce *, struct IS4Chunk *))TaskForce)(TaskForce, a2);
    v8 = (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 8))(a2, v5, v6);
    if ( v8 >= 0 && v8 < i )
    {
      v10 = v7[v8];
      if ( !v10 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1028, "pAssociatedTaskForce != 0") == 1 )
        __debugbreak();
      if ( v10 )
      {
        *((_DWORD *)TaskForce + 11) = v10;
        *(_DWORD *)(v10 + 44) = TaskForce;
      }
    }
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371967);
}


// address=[0x13286f0]
// Decompiled from int __thiscall CAITaskForceGroup::Save(CAITaskForceGroup *this, struct IS4Chunk *a2)
void  CAITaskForceGroup::Save(class IS4Chunk &) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp+8h] [ebp-28h]
  int v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+10h] [ebp-20h]
  CAITaskForce *v8; // [esp+14h] [ebp-1Ch]
  int k; // [esp+18h] [ebp-18h]
  struct CAITaskForce *j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  CAITaskForce *m; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371968);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371966);
  v2 = CAITaskForceGroup::PlayerId(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371965);
  v14 = 0;
  for ( i = 1; i < 9; ++i )
  {
    for ( j = (struct CAITaskForce *)CAITaskForceGroup::FirstTaskForce(this, i);
          j;
          j = CAITaskForce::NextTaskForceGroupMemberOfSameClass(j) )
    {
      *((_DWORD *)j + 12) = v14++;
    }
  }
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v14);
  if ( v14 <= 0 )
    return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371967);
  v7 = 0;
  for ( k = 1; k < 9; ++k )
  {
    for ( m = (CAITaskForce *)CAITaskForceGroup::FirstTaskForce(this, k);
          m;
          m = CAITaskForce::NextTaskForceGroupMemberOfSameClass(m) )
    {
      if ( v7 >= v14
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1103, "iTaskForceCounter < iNumberOfTaskForces") == 1 )
      {
        __debugbreak();
      }
      v3 = CAITaskForce::Type(m);
      (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v3);
      (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, 0);
      (*(void (__thiscall **)(CAITaskForce *, struct IS4Chunk *))(*(_DWORD *)m + 4))(m, a2);
      v5 = -1;
      v8 = (CAITaskForce *)CAITaskForce::AssociatedTaskForce(m);
      if ( v8 )
      {
        if ( (CAITaskForceGroup *)CAITaskForce::TaskForceGroup(v8) != this
          && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1122, "pAssociatedTaskForce->TaskForceGroup() == this") == 1 )
        {
          __debugbreak();
        }
        if ( (CAITaskForceGroup *)CAITaskForce::TaskForceGroup(v8) == this )
        {
          v6 = *((_DWORD *)v8 + 12);
          if ( v6 >= v14
            && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1128, "iAssociatedId < iNumberOfTaskForces") == 1 )
          {
            __debugbreak();
          }
          if ( v6 < v14 )
            v5 = v6;
        }
      }
      (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v5);
      ++v7;
    }
  }
  if ( v7 != v14
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1147, "iTaskForceCounter == iNumberOfTaskForces") == 1 )
  {
    __debugbreak();
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371967);
}


// address=[0x132a500]
// Decompiled from int __thiscall CAITaskForceGroup::PlayerId(CAITaskForceGroup *this)
int  CAITaskForceGroup::PlayerId(void) {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1328970]
// Decompiled from _DWORD *__thiscall CAITaskForceGroup::AddTaskForce(CAITaskForceGroup *this, struct CAITaskForce *a2)
void  CAITaskForceGroup::AddTaskForce(class CAITaskForce *) {
  
  _DWORD *result; // eax
  int v3; // [esp+Ch] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 891, "_pTaskForce != 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)a2 + 10)
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 892, "_pTaskForce->m_pTaskForceGroup == 0") == 1 )
  {
    __debugbreak();
  }
  v3 = CAITaskForce::Class(a2);
  if ( (v3 >= 9 || v3 < 0)
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         896,
         "(iTaskForceClass >= 0) & (iTaskForceClass < AI_TASK_FORCE_CLASS_MAX)") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)a2 + 8) = 0;
  *((_DWORD *)a2 + 9) = *((_DWORD *)this + v3 + 26);
  *((_DWORD *)a2 + 10) = this;
  if ( *((_DWORD *)this + v3 + 26) )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + v3 + 26) + 32)
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           905,
           "m_sData.m_pTaskForces[iTaskForceClass]->m_pPrevTaskForceGroupMember == 0") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(*((_DWORD *)this + v3 + 26) + 32) = a2;
  }
  else if ( *((_DWORD *)this + v3 + 3)
         && BBSupportDbgReport(
              2,
              "AI\\AI_TaskForces.cpp",
              911,
              "m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass] == 0") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + v3 + 26) = a2;
  ++*((_DWORD *)this + 2);
  ++*((_DWORD *)this + v3 + 3);
  result = (_DWORD *)((char *)this + 4 * CAITaskForce::Type(a2) + 48);
  ++*result;
  return result;
}


// address=[0x1328b20]
// Decompiled from int __thiscall CAITaskForceGroup::RemoveTaskForce(_DWORD *this, _DWORD *a2)
void  CAITaskForceGroup::RemoveTaskForce(class CAITaskForce *) {
  
  int v2; // eax
  int v4; // [esp+Ch] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 928, "_pTaskForce != 0") == 1 )
    __debugbreak();
  if ( (_DWORD *)a2[10] != this
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 929, "_pTaskForce->m_pTaskForceGroup == this") == 1 )
  {
    __debugbreak();
  }
  v4 = CAITaskForce::Class(a2);
  if ( (v4 >= 9 || v4 < 0)
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         933,
         "(iTaskForceClass >= 0) & (iTaskForceClass < AI_TASK_FORCE_CLASS_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( a2[8] )
  {
    if ( *(_DWORD **)(a2[8] + 36) != a2
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           937,
           "_pTaskForce->m_pPrevTaskForceGroupMember->m_pNextTaskForceGroupMember == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(a2[8] + 36) = a2[9];
  }
  else
  {
    if ( (_DWORD *)this[v4 + 26] != a2
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 943, "m_sData.m_pTaskForces[iTaskForceClass] == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    this[v4 + 26] = a2[9];
  }
  if ( a2[9] )
  {
    if ( *(_DWORD **)(a2[9] + 32) != a2
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           950,
           "_pTaskForce->m_pNextTaskForceGroupMember->m_pPrevTaskForceGroupMember == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(a2[9] + 32) = a2[8];
  }
  a2[8] = 0;
  a2[9] = 0;
  a2[10] = 0;
  --this[2];
  --this[v4 + 3];
  v2 = CAITaskForce::Type(a2);
  --this[v2 + 12];
  if ( (int)this[2] < 0
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 964, "m_sData.m_iTotalNumberOfTaskForces >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( (int)this[v4 + 3] < 0
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 965, "m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass] >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( (int)this[CAITaskForce::Type(a2) + 12] < 0
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         966,
         "m_sData.m_iNumberOfTaskForcesOfType[_pTaskForce->Type()] >= 0") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


