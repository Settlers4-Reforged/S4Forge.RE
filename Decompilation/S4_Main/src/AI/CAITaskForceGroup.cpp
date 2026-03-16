#include "CAITaskForceGroup.h"

#include "../LoadSave/IS4Chunk.h"

#include "CAITaskForce.h"
#include "CBB/CBBSupport.h"

// Definitions for class CAITaskForceGroup

// address=[0x12fd0d0]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForceGroup::FirstTaskForce(CAITaskForceGroup *this, int a2)
class CAITaskForce *CAITaskForceGroup::FirstTaskForce(enum T_AI_TASK_FORCE_CLASS a2) const {
  return this->m_sData.m_pTaskForces[a2];
}


// address=[0x13015c0]
// Decompiled from int __thiscall CAITaskForceGroup::NumberOfTaskForcesOfType(CAITaskForceGroup *this, int a2)
int CAITaskForceGroup::NumberOfTaskForcesOfType(enum T_AI_TASK_FORCE_TYPE a2) const {
  return this->m_sData.m_iNumberOfTaskForcesOfType[a2];
}


// address=[0x1303970]
// Decompiled from DWORD __thiscall CAITaskForceGroup::NumberOfTaskForcesOfClass(CAITaskForceGroup *this, int a2)
int CAITaskForceGroup::NumberOfTaskForcesOfClass(enum T_AI_TASK_FORCE_CLASS a2) const {
  return this->m_sData.m_iNumberOfTaskForcesOfClass[a2];
}


// address=[0x1328380]
// Decompiled from CAITaskForceGroup *__thiscall CAITaskForceGroup::CAITaskForceGroup(CAITaskForceGroup *this, int a2)
CAITaskForceGroup::CAITaskForceGroup(int a2) {
  memset(&this->m_sData, 0, sizeof(this->m_sData));
  this->m_sData.m_iPlayerId = a2;
}


// address=[0x13283c0]
// Decompiled from void __thiscall CAITaskForceGroup::~CAITaskForceGroup(CAITaskForceGroup *this)
CAITaskForceGroup::~CAITaskForceGroup(void) {
  this->DeleteAllTaskForces();
}


// address=[0x1328410]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForceGroup::CreateTaskForce(CAITaskForceGroup *this, int a2)
CAITaskForce *CAITaskForceGroup::CreateTaskForce(enum T_AI_TASK_FORCE_TYPE a2) {
  // [esp+4h] [ebp-4h]

  CAITaskForce *pTaskForce = CAITaskForces::CreateTaskForce(this->m_sData.m_iPlayerId, a2);
  if(pTaskForce)
    this->AddTaskForce(pTaskForce);
  return pTaskForce;
}


// address=[0x1328450]
// Decompiled from void __thiscall CAITaskForceGroup::DeleteAllTaskForces(CAITaskForceGroup *this)
void CAITaskForceGroup::DeleteAllTaskForces(void) {
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-20h]
  // [esp+18h] [ebp-8h]
  // [esp+1Ch] [ebp-4h]

  for(int tTaskForceClass = 0; tTaskForceClass < AI_TASK_FORCE_CLASS_MAX; ++tTaskForceClass) {
    for(CAITaskForce *i = this->FirstTaskForce(static_cast<T_AI_TASK_FORCE_CLASS>(tTaskForceClass)); i; i = TaskForceGroupMemberOfSameClass) {
      TaskForceGroupMemberOfSameClass = i->NextTaskForceGroupMemberOfSameClass();
      delete i;
    }
    if(this->FirstTaskForce(static_cast<T_AI_TASK_FORCE_CLASS>(tTaskForceClass))) {
      if(BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 880, "FirstTaskForce(tTaskForceClass) == 0") == 1)
        __debugbreak();
    }
  }
}


// address=[0x1328510]
// Decompiled from void __thiscall CAITaskForceGroup::Load(CAITaskForceGroup *this, struct IS4Chunk *a2)
void CAITaskForceGroup::Load(class IS4Chunk &a2) {
  // eax
  // [esp-4h] [ebp-30h]
  // [esp+8h] [ebp-24h]
  // [esp+10h] [ebp-1Ch]
  // [esp+14h] [ebp-18h]
  // [esp+18h] [ebp-14h]
  // [esp+1Ch] [ebp-10h]
  // [esp+24h] [ebp-8h]
  // [esp+28h] [ebp-4h]

  this->DeleteAllTaskForces();
  a2.LoadSignature(-1516371968);
  a2.LoadUnsigned32(1, 1);
  a2.LoadSignature(-1516371966);
  int v3 = this->PlayerId();
  int v2 = this->PlayerId();
  a2.LoadUnsigned32(v2, v3);
  a2.LoadSignature(-1516371965);
  int uTaskForceCount = a2.LoadUnsigned32();
  if(uTaskForceCount > 0) {
    //NOTE: This array is not really needed AND also not deleted...
    auto **pLoadedTaskForces = new CAITaskForce *[uTaskForceCount];
    for(int i = 0; i < uTaskForceCount; ++i) {
      int v4 = a2.LoadUnsigned32(0, 13);
      a2.LoadUnsigned32();
      CAITaskForce *pTaskForce = this->CreateTaskForce(static_cast<enum T_AI_TASK_FORCE_TYPE>(v4));
      if(!pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1012, "pTaskForce != 0") == 1)
        __debugbreak();
      pLoadedTaskForces[i] = pTaskForce;
      pTaskForce->Load(a2);
      int v6 = a2.LoadUnsigned32();
      if(v6 >= 0 && v6 < i) {
        CAITaskForce *pAssociatedTaskForce = pLoadedTaskForces[v6];
        if(!pAssociatedTaskForce
           && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1028, "pAssociatedTaskForce != 0") == 1) {
          __debugbreak();
        }
        if(pAssociatedTaskForce) {
          pTaskForce->m_pAssociatedTaskForce = pAssociatedTaskForce;
          pAssociatedTaskForce->m_pAssociatedTaskForce = pTaskForce;
        }
      }
    }
  }
  a2.LoadSignature(-1516371967);
}


// address=[0x13286f0]
// Decompiled from void __thiscall CAITaskForceGroup::Save(CAITaskForceGroup *this, struct IS4Chunk *a2)
void CAITaskForceGroup::Save(class IS4Chunk &a2) {
  // eax
  // eax
  // [esp+8h] [ebp-28h]
  // [esp+Ch] [ebp-24h]
  // [esp+10h] [ebp-20h]
  // [esp+14h] [ebp-1Ch]
  // [esp+18h] [ebp-18h]
  // [esp+1Ch] [ebp-14h]
  // [esp+20h] [ebp-10h]
  // [esp+28h] [ebp-8h]
  // [esp+2Ch] [ebp-4h]

  a2.SaveSignature(-1516371968);
  a2.SaveUnsigned32(1);
  a2.SaveSignature(-1516371966);
  int iPlayerId = this->PlayerId();
  a2.SaveUnsigned32(iPlayerId);
  a2.SaveSignature(-1516371965);
  int iNumberOfTaskForces = 0;
  for(int i = 1; i < AI_TASK_FORCE_CLASS_MAX; ++i) {
    for(CAITaskForce *j = this->FirstTaskForce(static_cast<enum T_AI_TASK_FORCE_CLASS>(i)); j; j = j->NextTaskForceGroupMemberOfSameClass())
      j->m_iAssociatedId = iNumberOfTaskForces++;
  }
  a2.SaveUnsigned32(iNumberOfTaskForces);
  if(iNumberOfTaskForces > 0) {
    int iTaskForceCounter = 0;
    for(int k = 1; k < AI_TASK_FORCE_CLASS_MAX; ++k) {
      for(CAITaskForce *m = this->FirstTaskForce(static_cast<enum T_AI_TASK_FORCE_CLASS>(k)); m; m = m->NextTaskForceGroupMemberOfSameClass()) {
        if(iTaskForceCounter >= iNumberOfTaskForces
           && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1103, "iTaskForceCounter < iNumberOfTaskForces") == 1) {
          __debugbreak();
        }
        int v3 = m->Type();
        a2.SaveUnsigned32(v3);
        a2.SaveUnsigned32(0);
        m->Save(a2);
        int           v4 = -1;
        CAITaskForce *pAssociatedTaskForce = m->AssociatedTaskForce();
        if(pAssociatedTaskForce) {
          if(pAssociatedTaskForce->TaskForceGroup() != this
             && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1122, "pAssociatedTaskForce->TaskForceGroup() == this") == 1) {
            __debugbreak();
          }
          if(pAssociatedTaskForce->TaskForceGroup() == this) {
            int iAssociatedId = pAssociatedTaskForce->m_iAssociatedId;
            if(iAssociatedId >= iNumberOfTaskForces
               && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1128, "iAssociatedId < iNumberOfTaskForces") == 1) {
              __debugbreak();
            }
            if(iAssociatedId < iNumberOfTaskForces)
              v4 = iAssociatedId;
          }
        }
        a2.SaveUnsigned32(v4);
        ++iTaskForceCounter;
      }
    }
    if(iTaskForceCounter != iNumberOfTaskForces
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 1147, "iTaskForceCounter == iNumberOfTaskForces") == 1) {
      __debugbreak();
    }
  }
  a2.SaveSignature(-1516371967);
}


// address=[0x132a500]
// Decompiled from int __thiscall CAITaskForceGroup::PlayerId(CAITaskForceGroup *this)
int CAITaskForceGroup::PlayerId(void) {
  return this->m_sData.m_iPlayerId;
}


// address=[0x1328970]
// Decompiled from void __thiscall CAITaskForceGroup::AddTaskForce(CAITaskForceGroup *this, struct CAITaskForce *_pTaskForce)
void CAITaskForceGroup::AddTaskForce(class CAITaskForce *_pTaskForce) {
  int v2; // eax
  // [esp+Ch] [ebp-8h]

  if(!_pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 891, "_pTaskForce != 0") == 1)
    __debugbreak();
  if(_pTaskForce->m_pTaskForceGroup
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 892, "_pTaskForce->m_pTaskForceGroup == 0") == 1) {
    __debugbreak();
  }
  int iTaskForceClass = _pTaskForce->Class();
  if((iTaskForceClass >= 9 || iTaskForceClass < 0)
     && BBSupportDbgReport(
       2,
       "AI\\AI_TaskForces.cpp",
       896,
       "(iTaskForceClass >= 0) & (iTaskForceClass < AI_TASK_FORCE_CLASS_MAX)") == 1) {
    __debugbreak();
  }
  _pTaskForce->m_pPrevTaskForceGroupMember = 0;
  _pTaskForce->m_pNextTaskForceGroupMember = this->m_sData.m_pTaskForces[iTaskForceClass];
  _pTaskForce->m_pTaskForceGroup = this;
  if(this->m_sData.m_pTaskForces[iTaskForceClass]) {
    if(this->m_sData.m_pTaskForces[iTaskForceClass]->m_pPrevTaskForceGroupMember
       && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         905,
         "m_sData.m_pTaskForces[iTaskForceClass]->m_pPrevTaskForceGroupMember == 0") == 1) {
      __debugbreak();
    }
    this->m_sData.m_pTaskForces[iTaskForceClass]->m_pPrevTaskForceGroupMember = _pTaskForce;
  } else if(this->m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass]
            && BBSupportDbgReport(
              2,
              "AI\\AI_TaskForces.cpp",
              911,
              "m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass] == 0") == 1) {
    __debugbreak();
  }
  this->m_sData.m_pTaskForces[iTaskForceClass] = _pTaskForce;
  ++this->m_sData.m_iTotalNumberOfTaskForces;
  ++this->m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass];
  ++this->m_sData.m_iNumberOfTaskForcesOfType[_pTaskForce->Type()];
}


// address=[0x1328b20]
// Decompiled from void __thiscall CAITaskForceGroup::RemoveTaskForce(struct CAITaskForceGroup *this, CAITaskForce *_pTaskForce)
void CAITaskForceGroup::RemoveTaskForce(class CAITaskForce *_pTaskForce) {
  // eax
  // [esp+Ch] [ebp-8h]

  if(!_pTaskForce && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 928, "_pTaskForce != 0") == 1)
    __debugbreak();
  if(_pTaskForce->m_pTaskForceGroup != this
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 929, "_pTaskForce->m_pTaskForceGroup == this") == 1) {
    __debugbreak();
  }
  int iTaskForceClass = _pTaskForce->Class();
  if((iTaskForceClass >= 9 || iTaskForceClass < 0)
     && BBSupportDbgReport(
       2,
       "AI\\AI_TaskForces.cpp",
       933,
       "(iTaskForceClass >= 0) & (iTaskForceClass < AI_TASK_FORCE_CLASS_MAX)") == 1) {
    __debugbreak();
  }
  if(_pTaskForce->m_pPrevTaskForceGroupMember) {
    if(_pTaskForce->m_pPrevTaskForceGroupMember->m_pNextTaskForceGroupMember != _pTaskForce
       && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         937,
         "_pTaskForce->m_pPrevTaskForceGroupMember->m_pNextTaskForceGroupMember == _pTaskForce") == 1) {
      __debugbreak();
    }
    _pTaskForce->m_pPrevTaskForceGroupMember->m_pNextTaskForceGroupMember = _pTaskForce->m_pNextTaskForceGroupMember;
  } else {
    if(this->m_sData.m_pTaskForces[iTaskForceClass] != _pTaskForce
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 943, "m_sData.m_pTaskForces[iTaskForceClass] == _pTaskForce") == 1) {
      __debugbreak();
    }
    this->m_sData.m_pTaskForces[iTaskForceClass] = _pTaskForce->m_pNextTaskForceGroupMember;
  }
  if(_pTaskForce->m_pNextTaskForceGroupMember) {
    if(_pTaskForce->m_pNextTaskForceGroupMember->m_pPrevTaskForceGroupMember != _pTaskForce
       && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         950,
         "_pTaskForce->m_pNextTaskForceGroupMember->m_pPrevTaskForceGroupMember == _pTaskForce") == 1) {
      __debugbreak();
    }
    _pTaskForce->m_pNextTaskForceGroupMember->m_pPrevTaskForceGroupMember = _pTaskForce->m_pPrevTaskForceGroupMember;
  }
  _pTaskForce->m_pPrevTaskForceGroupMember = 0;
  _pTaskForce->m_pNextTaskForceGroupMember = 0;
  _pTaskForce->m_pTaskForceGroup = 0;
  --this->m_sData.m_iTotalNumberOfTaskForces;
  --this->m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass];
  int v2 = _pTaskForce->Type();
  --this->m_sData.m_iNumberOfTaskForcesOfType[v2];
  if(this->m_sData.m_iTotalNumberOfTaskForces < 0
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 964, "m_sData.m_iTotalNumberOfTaskForces >= 0") == 1) {
    __debugbreak();
  }
  if(this->m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass] < 0
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 965, "m_sData.m_iNumberOfTaskForcesOfClass[iTaskForceClass] >= 0") == 1) {
    __debugbreak();
  }
  if(this->m_sData.m_iNumberOfTaskForcesOfType[_pTaskForce->Type()] < 0
     && BBSupportDbgReport(
       2,
       "AI\\AI_TaskForces.cpp",
       966,
       "m_sData.m_iNumberOfTaskForcesOfType[_pTaskForce->Type()] >= 0") == 1) {
    __debugbreak();
  }
}


