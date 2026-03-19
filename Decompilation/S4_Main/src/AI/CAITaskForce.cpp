#include "CAITaskForce.h"

#include "AI/IAIEnvironment.h"
#include "../LoadSave/IS4Chunk.h"

#include "CAIEntityInfo.h"
#include "CAITaskForceGroup.h"
#include "CAITaskForces.h"
#include "CBB/CBBSupport.h"

// Definitions for class CAITaskForce

// address=[0x12fce10]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForce::AssociatedTaskForce(CAITaskForce *this)
class CAITaskForce *CAITaskForce::AssociatedTaskForce(void) const {
  return this->m_pAssociatedTaskForce;
}


// address=[0x12fcf20]
// Decompiled from unsigned int __thiscall CAITaskForce::ClearFlagBit(CAITaskForce *this, unsigned int a2)
void CAITaskForce::ClearFlagBit(unsigned int a2) {
  this->m_uFlags &= ~a2;
}


// address=[0x12fcf50]
// Decompiled from int __thiscall CAITaskForce::CmdGoal(CAITaskForce *this)
int CAITaskForce::CmdGoal(void) const {
  return this->m_uCmdGoal;
}


// address=[0x12fcf70]
// Decompiled from unsigned int __thiscall CAITaskForce::CmdTimeStamp(CAITaskForce *this)
unsigned int CAITaskForce::CmdTimeStamp(void) const {
  return this->m_uCmdTimeStamp;
}


// address=[0x12fcf90]
// Decompiled from unsigned int __thiscall CAITaskForce::Command(CAITaskForce *this)
enum T_AI_TASK_FORCE_CMD CAITaskForce::Command(void) const {
  return static_cast<enum T_AI_TASK_FORCE_CMD>((this->m_uFlags & 0xFF0u) >> 4);
}


// address=[0x12fd0b0]
// Decompiled from struct CAIEntityInfo *__thiscall CAITaskForce::FirstEntity(CAITaskForce *this)
class CAIEntityInfo *CAITaskForce::FirstEntity(void) const {
  return this->m_pFirstEntity;
}


// address=[0x12fd130]
// Decompiled from DWORD __thiscall CAITaskForce::Flags(CAITaskForce *this)
int CAITaskForce::Flags(void) const {
  return this->m_uFlags;
}


// address=[0x12fd420]
// Decompiled from struct CAITaskForce *__thiscall CAITaskForce::NextTaskForceGroupMemberOfSameClass(CAITaskForce *this)
class CAITaskForce *CAITaskForce::NextTaskForceGroupMemberOfSameClass(void) const {
  return this->m_pNextTaskForceGroupMember;
}


// address=[0x12fd460]
// Decompiled from int __thiscall CAITaskForce::NumberOfEntities(CAITaskForce *this)
int CAITaskForce::NumberOfEntities(void) const {
  return this->m_iNumberOfEntities;
}


// address=[0x12fd660]
// Decompiled from void __thiscall CAITaskForce::SetFlagBit(CAITaskForce *this, unsigned int a2)
void CAITaskForce::SetFlagBit(unsigned int a2) {
  this->m_uFlags |= a2;
}


// address=[0x12fd710]
// Decompiled from int __thiscall CAITaskForce::Status(CAITaskForce *this)
enum T_AI_TASK_FORCE_STATUS CAITaskForce::Status(void) const {
  return this->m_bStatus;
}


// address=[0x12fd7a0]
// Decompiled from int __thiscall CAITaskForce::Type(CAITaskForce *this)
enum T_AI_TASK_FORCE_TYPE CAITaskForce::Type(void) const {
  return this->m_tType;
}


// address=[0x13014a0]
// Decompiled from int __thiscall CAITaskForce::GoalEntityId(CAITaskForce *this)
int CAITaskForce::GoalEntityId(void) const {
  if((this->m_uFlags & 0x1000) != 0)
    return this->m_uCmdGoal;
  else
    return 0;
}


// address=[0x13014e0]
// Decompiled from int __thiscall CAITaskForce::GoalUniqueId(CAITaskForce *this)
int CAITaskForce::GoalUniqueId(void) const {
  if((this->m_uFlags & 0x1000) != 0)
    return this->m_uCmdUniqueId;
  else
    return 0;
}


// address=[0x13015e0]
// Decompiled from int __thiscall CAITaskForce::OwnerId(CAITaskForce *this)
int CAITaskForce::OwnerId(void) const {
  return this->m_uFlags & 0xF;
}


// address=[0x13037f0]
// Decompiled from void __thiscall CAITaskForce::ClearEntityAddedFlag(CAITaskForce *this)
void CAITaskForce::ClearEntityAddedFlag(void) {
  this->m_uFlags &= ~0x4000000u;
}


// address=[0x13039b0]
// Decompiled from void __thiscall CAITaskForce::SetTimeStamp(CAITaskForce *this, unsigned int a2)
void CAITaskForce::SetTimeStamp(unsigned int a2) {
  this->m_uTimeStamp = a2;
}


// address=[0x13039f0]
// Decompiled from int __thiscall CAITaskForce::TimeStamp(CAITaskForce *this)
unsigned int CAITaskForce::TimeStamp(void) const {
  return this->m_uTimeStamp;
}


// address=[0x1306750]
// Decompiled from struct CAIEntityInfo *__thiscall CAITaskForce::LastEntity(CAITaskForce *this)
class CAIEntityInfo *CAITaskForce::LastEntity(void) const {
  return this->m_pLastEntity;
}


// address=[0x1309690]
// Decompiled from int __thiscall CAITaskForce::StatusTimeStamp(CAITaskForce *this)
unsigned int CAITaskForce::StatusTimeStamp(void) const {
  return this->m_uStatusTimeStamp;
}


// address=[0x1319810]
// Decompiled from char __thiscall CAITaskForce::NewCommand(CAITaskForce *this, int a2, int a3, int a4)
bool CAITaskForce::NewCommand(int, int, int) {
  return 0;
}


// address=[0x1319830]
// Decompiled from int __stdcall CAITaskForce::NumberOfEntities(int a1)
int CAITaskForce::NumberOfEntities(enum T_AI_WARRIOR_TYPE) const {
  return -1;
}


// address=[0x1321b40]
// Decompiled from int __thiscall CAITaskForce::Class(CAITaskForce *this)
enum T_AI_TASK_FORCE_CLASS CAITaskForce::Class(void) const {
  return this->m_tClass;
}


// address=[0x13270c0]
// Decompiled from void __thiscall CAITaskForce::~CAITaskForce(CAITaskForce *this)
CAITaskForce::~CAITaskForce(void) {
  this->ClearAssociatedTaskForce();
  if(this->m_pTaskForceGroup)
    this->m_pTaskForceGroup->RemoveTaskForce(this);
  this->RemoveAllEntities();
  CAITaskForces::RemoveTaskForce(this);
}


// address=[0x1327140]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::Release(CAITaskForce *this)
void CAITaskForce::Release(void) {
  delete this;
}


T_AI_TASK_FORCE_CLASS const s_tAITaskForceTypeToClassMap[] = {
  static_cast<T_AI_TASK_FORCE_CLASS>(0),
  static_cast<T_AI_TASK_FORCE_CLASS>(1),
  static_cast<T_AI_TASK_FORCE_CLASS>(6),
  static_cast<T_AI_TASK_FORCE_CLASS>(6),
  static_cast<T_AI_TASK_FORCE_CLASS>(3),
  static_cast<T_AI_TASK_FORCE_CLASS>(4),
  static_cast<T_AI_TASK_FORCE_CLASS>(5),
  static_cast<T_AI_TASK_FORCE_CLASS>(6),
  static_cast<T_AI_TASK_FORCE_CLASS>(7),
  static_cast<T_AI_TASK_FORCE_CLASS>(8)
};

// address=[0x03679264]
T_AI_TASK_FORCE_CLASS const *const g_tAITaskForceTypeToClassMap = s_tAITaskForceTypeToClassMap;
// g_tAITaskForceTypeToClassMap dd 0                    ; 0
// .rdata:03679264                                         ; DATA XREF: CAITaskForces::TaskForceClass(T_AI_TASK_FORCE_TYPE)+6↑r
// .rdata:03679264                                         ; CAITaskForce::CAITaskForce(int,T_AI_TASK_FORCE_CLASS,T_AI_TASK_FORCE_TYPE,int)+54↑r ...
// .rdata:03679268                 dd 1                    ; 1 ; enum T_AI_TASK_FORCE_CLASS const * const g_tAITaskForceTypeToClassMap
// .rdata:0367926C                 dd 6 dup(2)             ; 2
// .rdata:03679284                 dd 3                    ; 8
// .rdata:03679288                 dd 4                    ; 9
// .rdata:0367928C                 dd 5                    ; 10
// .rdata:03679290                 dd 6                    ; 11
// .rdata:03679294                 dd 7                    ; 12
// .rdata:03679298                 dd 8                    ; 13

// address=[0x1327180]
// Decompiled from void __thiscall CAITaskForce::ChangeType(struct CAITaskForce *this, int a2)


void CAITaskForce::ChangeType(enum T_AI_TASK_FORCE_TYPE a2) {
  if(this->m_tType != a2) {
    if(g_tAITaskForceTypeToClassMap[a2] == this->Class()) {
      if(this->m_pTaskForceGroup) {
        if(this->m_pTaskForceGroup->m_sData.m_iNumberOfTaskForcesOfType[this->m_tType] <= 0
           && BBSupportDbgReport(
             2,
             "AI\\AI_TaskForces.cpp",
             181,
             "m_pTaskForceGroup->m_sData.m_iNumberOfTaskForcesOfType[m_tTaskForceType] > 0") == 1) {
          __debugbreak();
        }
        --this->m_pTaskForceGroup->m_sData.m_iNumberOfTaskForcesOfType[this->m_tType];
        ++this->m_pTaskForceGroup->m_sData.m_iNumberOfTaskForcesOfType[a2];
      }
      this->m_tType = a2;
    } else if(BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 191, "CAITaskForce::ChangeType(): Invalid type!") == 1) {
      __debugbreak();
    }
  }
}


// address=[0x1327260]
// Decompiled from int __thiscall CAITaskForce::AddEntity(CAITaskForce *this, CAIEntityInfo *_pEntityInfo, int a3)
T_RESULT CAITaskForce::AddEntity(CAIEntityInfo *_pEntityInfo, enum CAITaskForce::T_POSITION a3) {
  if(!_pEntityInfo)
    return RESULT_INVALID;
  if(_pEntityInfo->m_pTaskForce == this) {
    if(a3 == POSITION_FIRST) {
      if(this->m_pFirstEntity == _pEntityInfo)
        return RESULT_FAILED;
    } else {
      if(a3 != POSITION_LAST)
        return RESULT_FAILED;
      if(this->m_pLastEntity == _pEntityInfo)
        return RESULT_FAILED;
    }
  }
  if(_pEntityInfo->m_pTaskForce)
    _pEntityInfo->m_pTaskForce->RemoveEntity(_pEntityInfo);
  if(_pEntityInfo->m_pTaskForce
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 245, "_pEntityInfo->m_pTaskForce == 0") == 1) {
    __debugbreak();
  }
  _pEntityInfo->m_pTaskForce = this;
  if(a3 == 1) {
    _pEntityInfo->m_pPrevEntity = 0;
    _pEntityInfo->m_pNextEntity = this->m_pFirstEntity;
    if(this->m_pFirstEntity) {
      if(this->m_pFirstEntity->m_pTaskForce != this
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 281, "m_pFirstEntity->m_pTaskForce == this") == 1) {
        __debugbreak();
      }
      if(this->m_pFirstEntity->m_pPrevEntity
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 282, "m_pFirstEntity->m_pPrevEntity == 0") == 1) {
        __debugbreak();
      }
      this->m_pFirstEntity->m_pPrevEntity = _pEntityInfo;
    } else {
      if(this->m_iNumberOfEntities
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 288, "m_iNumberOfEntities == 0") == 1) {
        __debugbreak();
      }
      this->m_pLastEntity = _pEntityInfo;
    }
    this->m_pFirstEntity = _pEntityInfo;
  } else {
    _pEntityInfo->m_pPrevEntity = this->m_pLastEntity;
    _pEntityInfo->m_pNextEntity = 0;
    if(this->m_pLastEntity) {
      if(this->m_pLastEntity->m_pTaskForce != this
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 258, "m_pLastEntity->m_pTaskForce == this") == 1) {
        __debugbreak();
      }
      if(this->m_pLastEntity->m_pNextEntity
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 259, "m_pLastEntity->m_pNextEntity == 0") == 1) {
        __debugbreak();
      }
      this->m_pLastEntity->m_pNextEntity = _pEntityInfo;
    } else {
      if(this->m_iNumberOfEntities
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 265, "m_iNumberOfEntities == 0") == 1) {
        __debugbreak();
      }
      this->m_pFirstEntity = _pEntityInfo;
    }
    this->m_pLastEntity = _pEntityInfo;
  }
  _pEntityInfo->SetTimeStamp(0);
  ++this->m_iNumberOfEntities;
  this->m_uFlags |= 0xC000000u;
  if(this->m_iNumberOfEntities <= 0) {
    if(this->m_pFirstEntity && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 319, "m_pFirstEntity == 0") == 1)
      __debugbreak();
    if(this->m_pLastEntity && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 320, "m_pLastEntity == 0") == 1)
      __debugbreak();
  } else {
    if(!this->m_pFirstEntity && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 311, "m_pFirstEntity != 0") == 1)
      __debugbreak();
    if(!this->m_pLastEntity && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 312, "m_pLastEntity != 0") == 1)
      __debugbreak();
    if(this->m_pFirstEntity->m_pPrevEntity
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 314, "m_pFirstEntity->m_pPrevEntity == 0") == 1) {
      __debugbreak();
    }
    if(this->m_pLastEntity->m_pNextEntity) {
      if(BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 315, "m_pLastEntity->m_pNextEntity == 0") == 1)
        __debugbreak();
    }
  }
  return RESULT_ADDED;
}


// address=[0x13275f0]
// Decompiled from int __thiscall CAITaskForce::AddEntity(CAITaskForce *this, int _iEntityId, int a3)
T_RESULT CAITaskForce::AddEntity(int _iEntityId, enum CAITaskForce::T_POSITION a3) {
  CAIEntityInfo *pEntityInfo = IAIEnvironment::EntityGetEntityInfo(_iEntityId, 1);
  if(pEntityInfo) {
    if(pEntityInfo->m_iEntityId != _iEntityId
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 341, "pEntityInfo->m_uEntityId == _iEntityId") == 1) {
      __debugbreak();
    }
    return this->AddEntity(pEntityInfo, a3);
  } else {
    if(BBSupportDbgReportF(
         1,
         "AI\\AI_TaskForces.cpp",
         347,
         "CAITaskForce::AddEntity(): Invalid entity id %i!",
         _iEntityId) == 1)
      __debugbreak();
    return RESULT_INVALID;
  }
}


// address=[0x1327690]
// Decompiled from int __thiscall CAITaskForce::RemoveEntity(CAITaskForce *this, struct CAIEntityInfo *_pEntityInfo)
enum T_RESULT CAITaskForce::RemoveEntity(class CAIEntityInfo *_pEntityInfo) {
  if(!_pEntityInfo)
    return RESULT_INVALID;
  if(_pEntityInfo->m_pTaskForce == this) {
    if(IAIEnvironment::EntityGetEntityInfo(_pEntityInfo->m_iEntityId, 0) != _pEntityInfo
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 374, "g_pAIEnv->EntityGetEntityInfo(iEntityId) == _pEntityInfo") == 1) {
      __debugbreak();
    }
    if(_pEntityInfo->m_pPrevEntity) {
      if(_pEntityInfo->m_pPrevEntity->m_pTaskForce != this
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 380, "_pEntityInfo->m_pPrevEntity->m_pTaskForce == this") == 1) {
        __debugbreak();
      }
      if(_pEntityInfo->m_pPrevEntity->m_pNextEntity != _pEntityInfo
         && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           381,
           "_pEntityInfo->m_pPrevEntity->m_pNextEntity == _pEntityInfo") == 1) {
        __debugbreak();
      }
      _pEntityInfo->m_pPrevEntity->m_pNextEntity = _pEntityInfo->m_pNextEntity;
    } else {
      if(this->m_pFirstEntity != _pEntityInfo
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 387, "m_pFirstEntity == _pEntityInfo") == 1) {
        __debugbreak();
      }
      this->m_pFirstEntity = _pEntityInfo->m_pNextEntity;
    }
    if(_pEntityInfo->m_pNextEntity) {
      if(_pEntityInfo->m_pNextEntity->m_pTaskForce != this
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 396, "_pEntityInfo->m_pNextEntity->m_pTaskForce == this") == 1) {
        __debugbreak();
      }
      if(_pEntityInfo->m_pNextEntity->m_pPrevEntity != _pEntityInfo
         && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           397,
           "_pEntityInfo->m_pNextEntity->m_pPrevEntity == _pEntityInfo") == 1) {
        __debugbreak();
      }
      _pEntityInfo->m_pNextEntity->m_pPrevEntity = _pEntityInfo->m_pPrevEntity;
    } else {
      if(this->m_pLastEntity != _pEntityInfo
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 403, "m_pLastEntity == _pEntityInfo") == 1) {
        __debugbreak();
      }
      this->m_pLastEntity = _pEntityInfo->m_pPrevEntity;
    }
    _pEntityInfo->m_pTaskForce = 0;
    _pEntityInfo->m_pPrevEntity = 0;
    _pEntityInfo->m_pNextEntity = 0;
    if(this->m_iNumberOfEntities <= 0
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 416, "m_iNumberOfEntities > 0") == 1) {
      __debugbreak();
    }
    if(this->m_iNumberOfEntities > 0)
      --this->m_iNumberOfEntities;
    if(this->m_iNumberOfEntities <= 0) {
      if(this->m_pFirstEntity && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 435, "m_pFirstEntity == 0") == 1)
        __debugbreak();
      if(this->m_pLastEntity && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 436, "m_pLastEntity == 0") == 1)
        __debugbreak();
    } else {
      if(!this->m_pFirstEntity && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 427, "m_pFirstEntity != 0") == 1)
        __debugbreak();
      if(!this->m_pLastEntity && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 428, "m_pLastEntity != 0") == 1)
        __debugbreak();
      if(this->m_pFirstEntity->m_pPrevEntity
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 430, "m_pFirstEntity->m_pPrevEntity == 0") == 1) {
        __debugbreak();
      }
      if(this->m_pLastEntity->m_pNextEntity
         && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 431, "m_pLastEntity->m_pNextEntity == 0") == 1) {
        __debugbreak();
      }
    }
    return RESULT_REMOVED;
  } else {
    if(BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 367, "CAITaskForce::RemoveEntity(): Entity not in taskforce!") == 1)
      __debugbreak();
    return RESULT_UNKNOWN_2;
  }
}


// address=[0x13279f0]
// Decompiled from void __thiscall CAITaskForce::RemoveEntity(CAITaskForce *this, int a2)
T_RESULT CAITaskForce::RemoveEntity(int a2) {
  if(CAIEntityInfo *EntityInfo = IAIEnvironment::EntityGetEntityInfo(a2, 0))
    this->RemoveEntity(EntityInfo);
}


// address=[0x1327a30]
// Decompiled from void __thiscall CAITaskForce::RemoveAllEntities(CAITaskForce *this)
void CAITaskForce::RemoveAllEntities(void) {
  CAIEntityInfo *m_pNextEntity; // [esp+4h] [ebp-Ch]

  int iCounter = 0;
  for(CAIEntityInfo *pEntityInfo = this->m_pFirstEntity; pEntityInfo; pEntityInfo = m_pNextEntity) {
    ++iCounter;
    m_pNextEntity = pEntityInfo->m_pNextEntity;
    if(pEntityInfo->m_pTaskForce != this
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 486, "pEntityInfo->m_pTaskForce == this") == 1) {
      __debugbreak();
    }
    if(m_pNextEntity
       && m_pNextEntity->m_pPrevEntity != pEntityInfo
       && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         487,
         "(pNextEntityInfo == 0) || (pNextEntityInfo->m_pPrevEntity == pEntityInfo)") == 1) {
      __debugbreak();
    }
    pEntityInfo->m_pTaskForce = nullptr;
    pEntityInfo->m_pPrevEntity = nullptr;
    pEntityInfo->m_pNextEntity = nullptr;
  }
  if(this->m_iNumberOfEntities != iCounter
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 500, "m_iNumberOfEntities == iCounter") == 1) {
    __debugbreak();
  }
  this->m_iNumberOfEntities = 0;
  this->m_pFirstEntity = 0;
  this->m_pLastEntity = 0;
}


// address=[0x1327b40]
// Decompiled from void __thiscall CAITaskForce::SetAssociatedTaskForce(CAITaskForce *this, CAITaskForce *_pTaskForce)
void CAITaskForce::SetAssociatedTaskForce(class CAITaskForce *_pTaskForce) {
  if(this->m_pAssociatedTaskForce) {
    this->ClearAssociatedTaskForce();
    if(BBSupportDbgReport(
         1,
         "AI\\AI_TaskForces.cpp",
         520,
         "CAITaskForce::SetAssociatedTaskForce(): Task force has already a associated task force!") == 1)
      __debugbreak();
  }
  if(_pTaskForce) {
    if(_pTaskForce == this && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 525, "_pTaskForce != this") == 1)
      __debugbreak();
    if(_pTaskForce->m_pAssociatedTaskForce) {
      _pTaskForce->ClearAssociatedTaskForce();
      if(BBSupportDbgReport(
           1,
           "AI\\AI_TaskForces.cpp",
           531,
           "CAITaskForce::SetAssociatedTaskForce(): Associated task force is already associated!") == 1)
        __debugbreak();
    }
    if(!this->m_pTaskForceGroup && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 534, "m_pTaskForceGroup != 0") == 1)
      __debugbreak();
    if(this->m_pTaskForceGroup != _pTaskForce->m_pTaskForceGroup
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 535, "m_pTaskForceGroup == _pTaskForce->m_pTaskForceGroup") == 1) {
      __debugbreak();
    }
    this->m_pAssociatedTaskForce = _pTaskForce;
    _pTaskForce->m_pAssociatedTaskForce = this;
  } else if(BBSupportDbgReport(
              1,
              "AI\\AI_TaskForces.cpp",
              542,
              "CAITaskForce::SetAssociatedTaskForce(): Associated task force == 0!") == 1) {
    __debugbreak();
  }
}


// address=[0x1327c70]
// Decompiled from void __thiscall CAITaskForce::ClearAssociatedTaskForce(CAITaskForce *this)
void CAITaskForce::ClearAssociatedTaskForce(void) {
  if(this->m_pAssociatedTaskForce) {
    if(this->m_pAssociatedTaskForce->m_pAssociatedTaskForce != this
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 555, "m_pAssociatedTaskForce->m_pAssociatedTaskForce == this") == 1) {
      __debugbreak();
    }
    this->m_pAssociatedTaskForce->m_pAssociatedTaskForce = 0;
    this->m_pAssociatedTaskForce = 0;
  }
}


// address=[0x1327cd0]
// Decompiled from void __thiscall CAITaskForce::Load(CAITaskForce *this, struct IS4Chunk *a2)
void CAITaskForce::Load(IS4Chunk &a2) {
  // [esp+0h] [ebp-10h]
  // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  this->RemoveAllEntities();
  a2.LoadSignature(-1516371712);
  a2.LoadUnsigned32(1, 1);
  a2.LoadSignature(-1516371710);
  this->m_uNewCounter = a2.LoadUnsigned32();
  this->m_bState = a2.LoadUnsigned32();
  this->m_iNextState = a2.LoadUnsigned32();
  this->m_bStatus = static_cast<T_AI_TASK_FORCE_STATUS>(a2.LoadUnsigned32());
  this->m_uFlags = a2.LoadUnsigned32();
  this->m_uCmdGoal = a2.LoadUnsigned32();
  this->m_uCmdUniqueId = a2.LoadUnsigned32();
  this->m_uCmdTimeStamp = a2.LoadUnsigned32();
  this->m_uStatusTimeStamp = a2.LoadUnsigned32();
  this->m_uTimeStamp = a2.LoadUnsigned32();
  a2.LoadSignature(-1516371709);
  int iNumberOfEntities = a2.LoadUnsigned32();
  for(i = 0; i < iNumberOfEntities; ++i) {
    int iEntityId = a2.LoadUnsigned32();
    if(IAIEnvironment::EntityIsAlive(iEntityId))
      this->AddEntity(iEntityId, POSITION_LAST);
  }
  a2.LoadSignature(-1516371711);
}


// address=[0x1327e60]
// Decompiled from void __thiscall CAITaskForce::Save(CAITaskForce *this, struct IS4Chunk *a2)
void CAITaskForce::Save(class IS4Chunk &a2) {
  // [esp+0h] [ebp-10h]
  // [esp+4h] [ebp-Ch]


  a2.SaveSignature(-1516371712);
  a2.SaveUnsigned32(1);
  a2.SaveSignature(-1516371710);
  a2.SaveUnsigned32(this->m_uNewCounter);
  a2.SaveUnsigned32(this->m_bState);
  a2.SaveUnsigned32(this->m_iNextState);
  a2.SaveUnsigned32(this->m_bStatus);
  a2.SaveUnsigned32(this->m_uFlags);
  a2.SaveUnsigned32(this->m_uCmdGoal);
  a2.SaveUnsigned32(this->m_uCmdUniqueId);
  a2.SaveUnsigned32(this->m_uCmdTimeStamp);
  a2.SaveUnsigned32(this->m_uStatusTimeStamp);
  a2.SaveUnsigned32(this->m_uTimeStamp);
  a2.SaveSignature(-1516371709);
  a2.SaveUnsigned32(this->m_iNumberOfEntities);

  int            iCounter = 0;
  CAIEntityInfo *pEntity = this->FirstEntity();
  while(pEntity) {
    a2.SaveUnsigned32(pEntity->EntityId());
    pEntity = pEntity->Next();
    ++iCounter;
  }
  if(iCounter != this->m_iNumberOfEntities
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 791, "iCounter == m_iNumberOfEntities") == 1) {
    __debugbreak();
  }
  a2.SaveSignature(-1516371711);
}


// address=[0x1328020]
// Decompiled from bool __thiscall CAITaskForce::IsGoalValid(CAITaskForce *this, int a2)
bool CAITaskForce::IsGoalValid(enum CAITaskForce::T_GOAL_TYPE a2) {
  if(!a2)
    return 0;
  if(a2 == 1)
    return (this->m_uFlags & 0x1000) != 0
           && IAIEnvironment::EntityIsAliveAndHasGivenUniqueId(this->m_uCmdGoal, this->m_uCmdUniqueId);
  else
    return a2 == 2 && (this->m_uFlags & 0x2000) != 0;
}

// address=[0x03D7A714]
const char *s_spTaskShortName[] = {
  "-   ",
  "R   ",
  "S-R",
  "S-MH",
  "S-SM",
  "S-D ",
  "S-A ",
  "S-E ",
  "P   ",
  "WM  ",
  "WS  ",
  "D-DG",
  "D-S ",
  "D-M ",
};


// address=[0x13280c0]
// Decompiled from char *__thiscall CAITaskForce::ShortName(CAITaskForce *this)
char const *CAITaskForce::ShortName(void) const {
  return s_spTaskShortName[this->m_tType];
}


// address=[0x13280e0]
// Decompiled from char __thiscall CAITaskForce::GetPositionOfFirstEntity(CAITaskForce *this, int *_rX, int *_rY)
bool CAITaskForce::GetPositionOfFirstEntity(int &_rX, int &_rY) {
  CAIEntityInfo *pEntity = this->FirstEntity();
  if(pEntity) {
    int iEntityId = pEntity->EntityId();
    if(iEntityId <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 646, "iEntityId > 0") == 1)
      __debugbreak();
    IAIEnvironment::EntityGetPosition(iEntityId, _rX, _rY);
    if(!IAIEnvironment::WorldInWorld(_rX, _rY)
       && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 650, "g_pAIEnv->WorldInWorld(_rX, _rY)") == 1) {
      __debugbreak();
    }
    return 1;
  } else {
    _rX = -1;
    _rY = -1;
    return 0;
  }
}


// address=[0x132a520]
// Decompiled from struct CAITaskForceGroup *__thiscall CAITaskForce::TaskForceGroup(CAITaskForce *this)
class CAITaskForceGroup const *CAITaskForce::TaskForceGroup(void) const {
  return this->m_pTaskForceGroup;
}


// address=[0x132e9b0]
// Decompiled from bool __thiscall CAITaskForce::GoalIsEntity(CAITaskForce *this)
bool CAITaskForce::GoalIsEntity(void) const {
  return (this->m_uFlags & 0x1000) != 0;
}


// address=[0x132e9f0]
// Decompiled from bool __thiscall CAITaskForce::GoalIsPosition(CAITaskForce *this)
bool CAITaskForce::GoalIsPosition(void) const {
  return (this->m_uFlags & 0x2000) != 0;
}


// address=[0x132ec90]
// Decompiled from void __thiscall CAITaskForce::SetWaitCounter(CAITaskForce *this, unsigned int _uNewCounter)
void CAITaskForce::SetWaitCounter(unsigned int _uNewCounter) {
  if(_uNewCounter >= 0x100
     && BBSupportDbgReport(
       2,
       "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
       270,
       "_uNewCounter < 0x100") == 1) {
    __debugbreak();
  }
  this->m_uNewCounter = _uNewCounter;
}


// address=[0x132ece0]
// Decompiled from int __thiscall CAITaskForce::State(CAITaskForce *this)
int CAITaskForce::State(void) const {
  return (unsigned __int8) this->m_bState;
}


// address=[0x13197f0]
// Decompiled from char __thiscall CAITaskForce::IsAddEntityOk(CAITaskForce *this, int a2)
bool CAITaskForce::IsAddEntityOk(int a2) {
  return 1;
}


// address=[0x1326f40]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::CAITaskForce(  CAITaskForce *this,  int _iOwnerId,  int _tClass,  int _tType,  int _iFlags)
CAITaskForce::CAITaskForce(int _iOwnerId, enum T_AI_TASK_FORCE_CLASS _tClass, enum T_AI_TASK_FORCE_TYPE _tType, int _iFlags) : IS4ChunkObject() {
  this->m_tClass = _tClass;
  if(!IAIEnvironment::AlliancesIsValidUsedPlayerId(_iOwnerId)
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 98, "g_pAIEnv->AlliancesIsValidUsedPlayerId(_iOwnerId)") == 1) {
    __debugbreak();
  }
  if(g_tAITaskForceTypeToClassMap[_tType] != _tClass
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 99, "g_tAITaskForceTypeToClassMap[_tType] == _tClass") == 1) {
    __debugbreak();
  }
  if((_iFlags & 0xFFFFFFF) != 0
     && BBSupportDbgReport(
       2,
       "AI\\AI_TaskForces.cpp",
       100,
       "(_iFlags & ~(AI_TASK_FORCE_FLAG_TASK_FORCE_FLAGS_MASK & ~AI_TASK_FORCE_FLAG_TASK_FORCE_INTERNAL_FLAGS_MASK)) == 0") == 1) {
    __debugbreak();
  }
  this->m_tType = _tType;
  this->m_iNumberOfEntities = 0;
  this->m_pFirstEntity = 0;
  this->m_pLastEntity = 0;
  this->m_pPrevTaskForce = 0;
  this->m_pFirstTaskForce = 0;
  this->m_pPrevTaskForceGroupMember = 0;
  this->m_pNextTaskForceGroupMember = 0;
  this->m_pTaskForceGroup = 0;
  this->m_pAssociatedTaskForce = 0;
  this->m_uNewCounter = 0;
  this->m_bState = 0;
  this->m_iNextState = 0;
  this->m_bStatus = TASK_FORCE_STATUS_NONE;
  this->m_uStatusTimeStamp = 0;
  this->m_uFlags = _iOwnerId | _iFlags;
  this->m_uCmdGoal = 0;
  this->m_uCmdUniqueId = 0;
  this->m_uCmdTimeStamp = 0;
  this->m_uTimeStamp = 0;
  CAITaskForces::AddTaskForce();
}


// address=[0x13281a0]
// Decompiled from void __thiscall CAITaskForce::SetCommand(CAITaskForce *this, unsigned int _iCommand, int a3, int _iFlags)
void CAITaskForce::SetCommand(int _iCommand, int a3, int _iFlags) {
  if(_iCommand > 0xE
     && BBSupportDbgReport(
       2,
       "AI\\AI_TaskForces.cpp",
       806,
       "static_cast<unsigned int>(_iCommand) <= AI_TASK_FORCE_CMD_LAST") == 1) {
    __debugbreak();
  }
  if((_iFlags & 0xFFFF3FFF) != 0
     && BBSupportDbgReport(
       2,
       "AI\\AI_TaskForces.cpp",
       807,
       "(_iFlags & ~(AI_TASK_FORCE_FLAG_CMD_FLAGS_MASK & ~AI_TASK_FORCE_FLAG_CMD_INTERNAL_FLAGS_MASK)) == 0") == 1) {
    __debugbreak();
  }
  this->m_uFlags = _iFlags | (16 * _iCommand) | this->m_uFlags & 0xF3FF000F;
  this->m_uCmdGoal = a3;
  this->m_uCmdUniqueId = 0;
  this->m_uCmdTimeStamp = IAIEnvironment::TickCounter();
}


// address=[0x1328240]
// Decompiled from void __thiscall CAITaskForce::MarkGoalAsEntity(CAITaskForce *this)
void CAITaskForce::MarkGoalAsEntity(void) {
  signed int iCmdUniqueId; // [esp+0h] [ebp-8h]

  if((this->m_uFlags & 0x3000) != 0
     && BBSupportDbgReport(
       2,
       "AI\\AI_TaskForces.cpp",
       579,
       "(m_uFlags & (AI_TASK_FORCE_FLAG_CMD_GOAL_IS_ENTITY | AI_TASK_FORCE_FLAG_CMD_GOAL_IS_POSITION)) == 0") == 1) {
    __debugbreak();
  }
  iCmdUniqueId = IAIEnvironment::EntityUniqueId(this->m_uCmdGoal);
  if(iCmdUniqueId <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 583, "iCmdUniqueId > 0") == 1)
    __debugbreak();
  this->m_uFlags |= 0x1000u;
  this->m_uCmdUniqueId = iCmdUniqueId;
}


// address=[0x13282d0]
// Decompiled from void __thiscall CAITaskForce::MarkGoalAsPosition(CAITaskForce *this)
void CAITaskForce::MarkGoalAsPosition(void) {
  if((this->m_uFlags & 0x3000) != 0
     && BBSupportDbgReport(
       2,
       "AI\\AI_TaskForces.cpp",
       670,
       "(m_uFlags & (AI_TASK_FORCE_FLAG_CMD_GOAL_IS_ENTITY | AI_TASK_FORCE_FLAG_CMD_GOAL_IS_POSITION)) == 0") == 1) {
    __debugbreak();
  }
  if(!IAIEnvironment::WorldInWorldPackedXY(this->m_uCmdGoal)
     && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 672, "g_pAIEnv->WorldInWorldPackedXY(m_uCmdGoal)") == 1) {
    __debugbreak();
  }
  if(this->m_uCmdUniqueId && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 673, "m_uCmdUniqueId == 0") == 1)
    __debugbreak();
  this->m_uFlags |= 0x2000u;
}


// address=[0x132a4a0]
// Decompiled from DWORD __thiscall CAITaskForce::DecWaitCounter(CAITaskForce *this, unsigned int a2)
unsigned int CAITaskForce::DecWaitCounter(unsigned int a2) {
  unsigned __int8 v3; // [esp+0h] [ebp-8h]

  if(this->m_uNewCounter <= a2)
    v3 = 0;
  else
    v3 = this->m_uNewCounter - a2;
  this->m_uNewCounter = v3;
  return this->m_uNewCounter;
}


// address=[0x132e810]
// Decompiled from void __thiscall CAITaskForce::ActivateNextState(CAITaskForce *this)
void CAITaskForce::ActivateNextState(void) {
  this->m_bState = this->m_iNextState;
}


// address=[0x132e870]
// Decompiled from void __thiscall CAITaskForce::ClearInternalFlagBit(CAITaskForce *this, unsigned int a2)
void CAITaskForce::ClearInternalFlagBit(unsigned int a2) {
  if((a2 & 0xF0FFFFFF) != 0
     && BBSupportDbgReport(
       2,
       "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
       357,
       "(_uMask & ~AI_TASK_FORCE_FLAG_TASK_FORCE_INTERNAL_FLAGS_MASK) == 0") == 1) {
    __debugbreak();
  }
  this->m_uFlags &= ~a2;
}


// address=[0x132e8d0]
// Decompiled from void __thiscall CAITaskForce::ClearStateFlagBit(CAITaskForce *this, unsigned int a2)
void CAITaskForce::ClearStateFlagBit(unsigned int a2) {
  if((a2 & 0xFF00FFFF) != 0
     && BBSupportDbgReport(
       2,
       "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
       371,
       "(_uMask & ~AI_TASK_FORCE_FLAG_STATE_FLAGS_MASK) == 0") == 1) {
    __debugbreak();
  }
  this->m_uFlags &= ~a2;
}


// address=[0x132ea30]
// Decompiled from bool __thiscall CAITaskForce::IsTaskForceExState(CAITaskForce *this, int a2)
bool CAITaskForce::IsTaskForceExState(int a2) {
  return (unsigned int) (a2 - 100) < 0xD;
}


// address=[0x132eb20]
// Decompiled from int __thiscall CAITaskForce::SetNewStatusAndState(CAITaskForce *this, int a2, char a3, int a4)
void CAITaskForce::SetNewStatusAndState(enum T_AI_TASK_FORCE_STATUS a2, int a3, int a4) {
  this->SetStateEx(a3, a4);
  this->SetStatus(a2);
}


// address=[0x132eb60]
// Decompiled from void __thiscall CAITaskForce::SetState(CAITaskForce *this, char a2)
void CAITaskForce::SetState(int a2) {
  this->m_bState = a2;
}


// address=[0x132eb80]
// Decompiled from void __thiscall CAITaskForce::SetStateEx(CAITaskForce *this, char a2, int _iNextState)
void CAITaskForce::SetStateEx(int a2, int _iNextState) {
  if(_iNextState
     && this->IsTaskForceExState(_iNextState)
     && BBSupportDbgReport(
       2,
       "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
       433,
       "(_iNextState == AI_TASK_FORCE_STATE_IDLE) || !IsTaskForceExState(_iNextState)") == 1) {
    __debugbreak();
  }
  this->m_bState = a2;
  this->m_iNextState = _iNextState;
}


// address=[0x132ebf0]
// Decompiled from void __thiscall CAITaskForce::SetStateFlagBit(CAITaskForce *this, unsigned int _uMask)
void CAITaskForce::SetStateFlagBit(unsigned int _uMask) {
  if((_uMask & 0xFF00FFFF) != 0
     && BBSupportDbgReport(
       2,
       "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
       364,
       "(_uMask & ~AI_TASK_FORCE_FLAG_STATE_FLAGS_MASK) == 0") == 1) {
    __debugbreak();
  }
  this->m_uFlags |= _uMask;
}


// address=[0x132ec50]
// Decompiled from void __thiscall CAITaskForce::SetStatus(CAITaskForce *this, int a2)
void CAITaskForce::SetStatus(enum T_AI_TASK_FORCE_STATUS a2) {
  if(this->m_bStatus != a2) {
    this->m_bStatus = a2;
    this->m_uStatusTimeStamp = IAIEnvironment::TickCounter();
  }
}


