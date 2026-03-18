#if FALSE
#include "CAITaskForceGroup.h"

// Definitions for class CAITaskForceGroup

// address=[0x12fd0d0]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForceGroup::FirstTaskForce(CAITaskForceGroup *this, int a2)
class CAITaskForce *  CAITaskForceGroup::FirstTaskForce(enum T_AI_TASK_FORCE_CLASS a2)const {
  
  return this->m_sData.m_pTaskForces[a2];
}


// address=[0x13015c0]
// Decompiled from int __thiscall CAITaskForceGroup::NumberOfTaskForcesOfType(CAITaskForceGroup *this, int a2)
int  CAITaskForceGroup::NumberOfTaskForcesOfType(enum T_AI_TASK_FORCE_TYPE a2)const {
  
  return this->m_sData.m_iNumberOfTaskForcesOfType[a2];
}


// address=[0x1303970]
// Decompiled from DWORD __thiscall CAITaskForceGroup::NumberOfTaskForcesOfClass(CAITaskForceGroup *this, int a2)
int  CAITaskForceGroup::NumberOfTaskForcesOfClass(enum T_AI_TASK_FORCE_CLASS a2)const {
  
  return this->m_sData.m_iNumberOfTaskForcesOfClass[a2];
}


// address=[0x1328380]
// Decompiled from CAITaskForceGroup *__thiscall CAITaskForceGroup::CAITaskForceGroup(CAITaskForceGroup *this, int a2)
 CAITaskForceGroup::CAITaskForceGroup(int a2) {
  
  this->vftable = CAITaskForceGroup::_vftable_;
  memset(&this->m_sData, 0, sizeof(this->m_sData));
  this->m_sData.m_iPlayerId = a2;
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
class CAITaskForce *  CAITaskForceGroup::CreateTaskForce(enum T_AI_TASK_FORCE_TYPE a2) {
  
  struct CAITaskForce *TaskForce; // [esp+4h] [ebp-4h]

  TaskForce = (struct CAITaskForce *)CAITaskForces::CreateTaskForce(this->m_sData.m_iPlayerId, a2);
  if ( TaskForce )
    CAITaskForceGroup::AddTaskForce(this, TaskForce);
  return TaskForce;
}


// address=[0x1328450]
// Decompiled from void __thiscall CAITaskForceGroup::DeleteAllTaskForces(CAITaskForceGroup *this)
void  CAITaskForceGroup::DeleteAllTaskForces(void) {
  
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-20h]
  CAITaskForce *i; // [esp+18h] [ebp-8h]
  int tTaskForceClass; // [esp+1Ch] [ebp-4h]

  for ( tTaskForceClass = 0; tTaskForceClass < 9; ++tTaskForceClass )
  {
    for ( i = CAITaskForceGroup::FirstTaskForce(this, tTaskForceClass); i; i = TaskForceGroupMemberOfSameClass )
    {
      TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
      i->dtor(i, 1);
    }
    if ( CAITaskForceGroup::FirstTaskForce(this, tTaskForceClass) )
    {
      if ( BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 880, "FirstTaskForce(tTaskForceClass) == 0") == 1 )
        __debugbreak();
    }
  }
}


// address=[0x1328510]
// Decompiled from void __thiscall CAITaskForceGroup::Load(CAITaskForceGroup *this, struct IS4Chunk *a2)
void  CAITaskForceGroup::Load(class IS4Chunk & a2) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-30h]
  int v4; // [esp+8h] [ebp-24h]
  CAITaskForce **v5; // [esp+10h] [ebp-1Ch]
  int v6; // [esp+14h] [ebp-18h]
  int v7; // [esp+18h] [ebp-14h]
  CAITaskForce *pAssociatedTaskForce; // [esp+1Ch] [ebp-10h]
  int i; // [esp+24h] [ebp-8h]
  struct CAITaskForce *pTaskForce; // [esp+28h] [ebp-4h]

  CAITaskForceGroup::DeleteAllTaskForces(this);
  a2->LoadSignature(-1516371968);
  a2->LoadUnsigned32(1, 1);
  a2->LoadSignature(-1516371966);
  v3 = CAITaskForceGroup::PlayerId(this);
  v2 = CAITaskForceGroup::PlayerId(this);
  a2->LoadUnsigned32(v2, v3);
  a2->LoadSignature(-1516371965);
  v7 = a2->LoadUnsigned32_(a2);
  if ( v7 > 0 )
  {
    v5 = (CAITaskForce **)operator new[](4 * v7);
    for ( i = 0; i < v7; ++i )
    {
      v4 = a2->LoadUnsigned32(0, 13);
      a2->LoadUnsigned32_(a2);
      pTaskForce = CAITaskForceGroup::CreateTaskForce(this, v4);
      if ( !pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1012, "pTaskForce != 0") == 1 )
        __debugbreak();
      v5[i] = pTaskForce;
      pTaskForce->Load(pTaskForce, a2);
      v6 = a2->LoadUnsigned32_(a2);
      if ( v6 >= 0 && v6 < i )
      {
        pAssociatedTaskForce = v5[v6];
        if ( !pAssociatedTaskForce
          && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1028, "pAssociatedTaskForce != 0") == 1 )
        {
          __debugbreak();
        }
        if ( pAssociatedTaskForce )
        {
          pTaskForce->m_pAssociatedTaskForce = pAssociatedTaskForce;
          pAssociatedTaskForce->m_pAssociatedTaskForce = pTaskForce;
        }
      }
    }
  }
  a2->LoadSignature(-1516371967);
}


// address=[0x13286f0]
// Decompiled from void __thiscall CAITaskForceGroup::Save(CAITaskForceGroup *this, struct IS4Chunk *a2)
void  CAITaskForceGroup::Save(class IS4Chunk & a2) {
  
  int iPlayerId; // eax
  int v3; // eax
  int v4; // [esp+8h] [ebp-28h]
  int iAssociatedId; // [esp+Ch] [ebp-24h]
  int v6; // [esp+10h] [ebp-20h]
  struct CAITaskForce *pAssociatedTaskForce; // [esp+14h] [ebp-1Ch]
  int k; // [esp+18h] [ebp-18h]
  struct CAITaskForce *j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  CAITaskForce *m; // [esp+28h] [ebp-8h]
  int iNumberOfTaskForces; // [esp+2Ch] [ebp-4h]

  a2->SaveSignature(-1516371968);
  a2->SaveUnsigned32(1);
  a2->SaveSignature(-1516371966);
  iPlayerId = CAITaskForceGroup::PlayerId(this);
  a2->SaveUnsigned32(iPlayerId);
  a2->SaveSignature(-1516371965);
  iNumberOfTaskForces = 0;
  for ( i = 1; i < 9; ++i )
  {
    for ( j = CAITaskForceGroup::FirstTaskForce(this, i); j; j = CAITaskForce::NextTaskForceGroupMemberOfSameClass(j) )
      j->m_iAssociatedId = iNumberOfTaskForces++;
  }
  a2->SaveUnsigned32(iNumberOfTaskForces);
  if ( iNumberOfTaskForces > 0 )
  {
    v6 = 0;
    for ( k = 1; k < 9; ++k )
    {
      for ( m = CAITaskForceGroup::FirstTaskForce(this, k); m; m = CAITaskForce::NextTaskForceGroupMemberOfSameClass(m) )
      {
        if ( v6 >= iNumberOfTaskForces
          && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1103, "iTaskForceCounter < iNumberOfTaskForces") == 1 )
        {
          __debugbreak();
        }
        v3 = CAITaskForce::Type(m);
        a2->SaveUnsigned32(v3);
        a2->SaveUnsigned32(0);
        m->Save(m, a2);
        v4 = -1;
        pAssociatedTaskForce = CAITaskForce::AssociatedTaskForce(m);
        if ( pAssociatedTaskForce )
        {
          if ( CAITaskForce::TaskForceGroup(pAssociatedTaskForce) != this
            && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1122, "pAssociatedTaskForce->TaskForceGroup() == this") == 1 )
          {
            __debugbreak();
          }
          if ( CAITaskForce::TaskForceGroup(pAssociatedTaskForce) == this )
          {
            iAssociatedId = pAssociatedTaskForce->m_iAssociatedId;
            if ( iAssociatedId >= iNumberOfTaskForces
              && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1128, "iAssociatedId < iNumberOfTaskForces") == 1 )
            {
              __debugbreak();
            }
            if ( iAssociatedId < iNumberOfTaskForces )
              v4 = iAssociatedId;
          }
        }
        a2->SaveUnsigned32(v4);
        ++v6;
      }
    }
    if ( v6 != iNumberOfTaskForces
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1147, "iTaskForceCounter == iNumberOfTaskForces") == 1 )
    {
      __debugbreak();
    }
  }
  a2->SaveSignature(-1516371967);
}


// address=[0x132a500]
// Decompiled from int __thiscall CAITaskForceGroup::PlayerId(CAITaskForceGroup *this)
int  CAITaskForceGroup::PlayerId(void) {
  
  return this->m_sData.m_iPlayerId;
}


// address=[0x1328970]
// Decompiled from void __thiscall CAITaskForceGroup::AddTaskForce(CAITaskForceGroup *this, struct CAITaskForce *_pTaskForce)
void  CAITaskForceGroup::AddTaskForce(class CAITaskForce * _pTaskForce) {
  
  int v2; // eax
  int iTaskForceClass; // [esp+Ch] [ebp-8h]

  if ( !_pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 891, "_pTaskForce != 0") == 1 )
    __debugbreak();
  if ( _pTaskForce->m_pTaskForceGroup
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 892, "_pTaskForce->m_pTaskForceGroup == 0") == 1 )
  {
    __debugbreak();
  }
  iTaskForceClass = CAITaskForce::Class(_pTaskForce);
  if ( (iTaskForceClass >= 9 || iTaskForceClass < 0)
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         896,
         "(iTaskForceClass >= 0) & (iTaskForceClass < AI_TASK_FORCE_CLASS_MAX)") == 1 )
  {
    __debugbreak();
  }
  _pTaskForce->m_pPrevTaskForceGroupMember = 0;
  _pTaskForce->m_pNextTaskForceGroupMember = this->m_sData.m_pTaskForces[iTaskForceClass];
  _pTaskForce->m_pTaskForceGroup = this;
  if ( this->m_sData.m_pTaskForces[iTaskForceClass] )
  {
    if ( this->m_sData.m_pTaskForces[iTaskForceClass]->m_pPrevTaskForceGroupMember
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           905,
           "m_sData.m_pTaskForces[iTaskForceClass]->m_pPrevTaskForceGroupMember == 0") == 1 )
    {
      __debugbreak();
    }
    this->m_sData.m_pTaskForces[iTaskForceClass]->m_pPrevTaskForceGroupMember = _pTaskForce;
  }
  else if ( this->m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass]
         && BBSupportDbgReport(
              2,
              "AI\\AI_TaskForces.cpp",
              911,
              "m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass] == 0") == 1 )
  {
    __debugbreak();
  }
  this->m_sData.m_pTaskForces[iTaskForceClass] = _pTaskForce;
  ++this->m_sData.m_iTotalNumberOfTaskForces;
  ++this->m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass];
  v2 = CAITaskForce::Type(_pTaskForce);
  ++this->m_sData.m_iNumberOfTaskForcesOfType[v2];
}


// address=[0x1328b20]
// Decompiled from void __thiscall CAITaskForceGroup::RemoveTaskForce(struct CAITaskForceGroup *this, CAITaskForce *_pTaskForce)
void  CAITaskForceGroup::RemoveTaskForce(class CAITaskForce * _pTaskForce) {
  
  int v2; // eax
  int iTaskForceClass; // [esp+Ch] [ebp-8h]

  if ( !_pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 928, "_pTaskForce != 0") == 1 )
    __debugbreak();
  if ( _pTaskForce->m_pTaskForceGroup != this
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 929, "_pTaskForce->m_pTaskForceGroup == this") == 1 )
  {
    __debugbreak();
  }
  iTaskForceClass = CAITaskForce::Class(_pTaskForce);
  if ( (iTaskForceClass >= 9 || iTaskForceClass < 0)
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         933,
         "(iTaskForceClass >= 0) & (iTaskForceClass < AI_TASK_FORCE_CLASS_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( _pTaskForce->m_pPrevTaskForceGroupMember )
  {
    if ( _pTaskForce->m_pPrevTaskForceGroupMember->m_pNextTaskForceGroupMember != _pTaskForce
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           937,
           "_pTaskForce->m_pPrevTaskForceGroupMember->m_pNextTaskForceGroupMember == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    _pTaskForce->m_pPrevTaskForceGroupMember->m_pNextTaskForceGroupMember = _pTaskForce->m_pNextTaskForceGroupMember;
  }
  else
  {
    if ( this->m_sData.m_pTaskForces[iTaskForceClass] != _pTaskForce
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 943, "m_sData.m_pTaskForces[iTaskForceClass] == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    this->m_sData.m_pTaskForces[iTaskForceClass] = _pTaskForce->m_pNextTaskForceGroupMember;
  }
  if ( _pTaskForce->m_pNextTaskForceGroupMember )
  {
    if ( _pTaskForce->m_pNextTaskForceGroupMember->m_pPrevTaskForceGroupMember != _pTaskForce
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           950,
           "_pTaskForce->m_pNextTaskForceGroupMember->m_pPrevTaskForceGroupMember == _pTaskForce") == 1 )
    {
      __debugbreak();
    }
    _pTaskForce->m_pNextTaskForceGroupMember->m_pPrevTaskForceGroupMember = _pTaskForce->m_pPrevTaskForceGroupMember;
  }
  _pTaskForce->m_pPrevTaskForceGroupMember = 0;
  _pTaskForce->m_pNextTaskForceGroupMember = 0;
  _pTaskForce->m_pTaskForceGroup = 0;
  --this->m_sData.m_iTotalNumberOfTaskForces;
  --this->m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass];
  v2 = CAITaskForce::Type(_pTaskForce);
  --this->m_sData.m_iNumberOfTaskForcesOfType[v2];
  if ( this->m_sData.m_iTotalNumberOfTaskForces < 0
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 964, "m_sData.m_iTotalNumberOfTaskForces >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass] < 0
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 965, "m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass] >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_sData.m_iNumberOfTaskForcesOfType[CAITaskForce::Type(_pTaskForce)] < 0
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         966,
         "m_sData.m_iNumberOfTaskForcesOfType[_pTaskForce->Type()] >= 0") == 1 )
  {
    __debugbreak();
  }
}


#endif // Already implemented
