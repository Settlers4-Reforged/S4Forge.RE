#include "CAITaskForce.h"

// Definitions for class CAITaskForce

// address=[0x12fce10]
// Decompiled from int __thiscall CAITaskForce::AssociatedTaskForce(CAITaskForce *this)
class CAITaskForce *  CAITaskForce::AssociatedTaskForce(void)const {
  
  return *((_DWORD *)this + 11);
}


// address=[0x12fcf20]
// Decompiled from unsigned int __thiscall CAITaskForce::ClearFlagBit(CAITaskForce *this, unsigned int a2)
void  CAITaskForce::ClearFlagBit(unsigned int a2) {
  
  unsigned int result; // eax

  result = *((_DWORD *)this + 14) & ~a2;
  *((_DWORD *)this + 14) = result;
  return result;
}


// address=[0x12fcf50]
// Decompiled from int __thiscall CAITaskForce::CmdGoal(CAITaskForce *this)
int  CAITaskForce::CmdGoal(void)const {
  
  return *((_DWORD *)this + 15);
}


// address=[0x12fcf70]
// Decompiled from unsigned int __thiscall CAITaskForce::CmdTimeStamp(CDockState *this)
unsigned int  CAITaskForce::CmdTimeStamp(void)const {
  
  return *((_DWORD *)this + 17);
}


// address=[0x12fcf90]
// Decompiled from unsigned int __thiscall CAITaskForce::Command(_DWORD *this)
enum T_AI_TASK_FORCE_CMD  CAITaskForce::Command(void)const {
  
  return (this[14] & 0xFF0u) >> 4;
}


// address=[0x12fd0b0]
// Decompiled from int __thiscall CAITaskForce::FirstEntity(CAITaskForce *this)
class CAIEntityInfo *  CAITaskForce::FirstEntity(void)const {
  
  return *((_DWORD *)this + 4);
}


// address=[0x12fd130]
// Decompiled from unsigned int __thiscall CAITaskForce::Flags(CUserToolsManager *this)
int  CAITaskForce::Flags(void)const {
  
  return *((_DWORD *)this + 14);
}


// address=[0x12fd420]
// Decompiled from int __thiscall CAITaskForce::NextTaskForceGroupMemberOfSameClass(CAITaskForce *this)
class CAITaskForce *  CAITaskForce::NextTaskForceGroupMemberOfSameClass(void)const {
  
  return *((_DWORD *)this + 9);
}


// address=[0x12fd460]
// Decompiled from int __thiscall CAITaskForce::NumberOfEntities(pairNode *this)
int  CAITaskForce::NumberOfEntities(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x12fd660]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::SetFlagBit(CAITaskForce *this, unsigned int a2)
void  CAITaskForce::SetFlagBit(unsigned int a2) {
  
  CAITaskForce *result; // eax

  result = this;
  *((_DWORD *)this + 14) |= a2;
  return result;
}


// address=[0x12fd710]
// Decompiled from int __thiscall CAITaskForce::Status(unsigned __int8 *this)
enum T_AI_TASK_FORCE_STATUS  CAITaskForce::Status(void)const {
  
  return this[55];
}


// address=[0x12fd7a0]
// Decompiled from int __thiscall CAITaskForce::Type(_DWORD *this)
enum T_AI_TASK_FORCE_TYPE  CAITaskForce::Type(void)const {
  
  return this[2];
}


// address=[0x13014a0]
// Decompiled from int __thiscall CAITaskForce::GoalEntityId(CAITaskForce *this)
int  CAITaskForce::GoalEntityId(void)const {
  
  if ( (*((_DWORD *)this + 14) & 0x1000) != 0 )
    return *((_DWORD *)this + 15);
  else
    return 0;
}


// address=[0x13014e0]
// Decompiled from int __thiscall CAITaskForce::GoalUniqueId(CAITaskForce *this)
int  CAITaskForce::GoalUniqueId(void)const {
  
  if ( (*((_DWORD *)this + 14) & 0x1000) != 0 )
    return *((_DWORD *)this + 16);
  else
    return 0;
}


// address=[0x13015e0]
// Decompiled from int __thiscall CAITaskForce::OwnerId(CAITaskForce *this)
int  CAITaskForce::OwnerId(void)const {
  
  return *((_DWORD *)this + 14) & 0xF;
}


// address=[0x13037f0]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::ClearEntityAddedFlag(CAITaskForce *this)
void  CAITaskForce::ClearEntityAddedFlag(void) {
  
  CAITaskForce *result; // eax

  result = this;
  *((_DWORD *)this + 14) &= ~0x4000000u;
  return result;
}


// address=[0x13039b0]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::SetTimeStamp(CAITaskForce *this, unsigned int a2)
void  CAITaskForce::SetTimeStamp(unsigned int a2) {
  
  CAITaskForce *result; // eax

  result = this;
  *((_DWORD *)this + 19) = a2;
  return result;
}


// address=[0x13039f0]
// Decompiled from int __thiscall CAITaskForce::TimeStamp(CAITaskForce *this)
unsigned int  CAITaskForce::TimeStamp(void)const {
  
  return *((_DWORD *)this + 19);
}


// address=[0x1306750]
// Decompiled from int __thiscall CAITaskForce::LastEntity(CAITaskForce *this)
class CAIEntityInfo *  CAITaskForce::LastEntity(void)const {
  
  return *((_DWORD *)this + 5);
}


// address=[0x1309690]
// Decompiled from int __thiscall CAITaskForce::StatusTimeStamp(CMFCToolBarButton *this)
unsigned int  CAITaskForce::StatusTimeStamp(void)const {
  
  return *((_DWORD *)this + 18);
}


// address=[0x1319810]
// Decompiled from char __thiscall CAITaskForce::NewCommand(CAITaskForce *this, int a2, int a3, int a4)
bool  CAITaskForce::NewCommand(int a2, int a3, int a4) {
  
  return 0;
}


// address=[0x1319830]
// Decompiled from int __stdcall CAITaskForce::NumberOfEntities(int a1)
int  CAITaskForce::NumberOfEntities(enum T_AI_WARRIOR_TYPE a1)const {
  
  return -1;
}


// address=[0x1321b40]
// Decompiled from int __thiscall CAITaskForce::Class(_DWORD *this)
enum T_AI_TASK_FORCE_CLASS  CAITaskForce::Class(void)const {
  
  return this[1];
}


// address=[0x13270c0]
// Decompiled from void __thiscall CAITaskForce::~CAITaskForce(CAITaskForce *this)
 CAITaskForce::~CAITaskForce(void) {
  
  *(_DWORD *)this = CAITaskForce::_vftable_;
  CAITaskForce::ClearAssociatedTaskForce(this);
  if ( *((_DWORD *)this + 10) )
    CAITaskForceGroup::RemoveTaskForce(*((_DWORD **)this + 10), this);
  CAITaskForce::RemoveAllEntities(this);
  CAITaskForces::RemoveTaskForce(this);
}


// address=[0x1327140]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::Release(CAITaskForce *this)
void  CAITaskForce::Release(void) {
  
  CAITaskForce *result; // eax

  result = this;
  if ( this )
    return (CAITaskForce *)(*(int (__thiscall **)(CAITaskForce *, int))(*(_DWORD *)this + 8))(this, 1);
  return result;
}


// address=[0x1327180]
// Decompiled from int __thiscall CAITaskForce::ChangeType(_DWORD *this, int a2)
void  CAITaskForce::ChangeType(enum T_AI_TASK_FORCE_TYPE a2) {
  
  int result; // eax

  result = (int)this;
  if ( this[2] == a2 )
    return result;
  if ( g_tAITaskForceTypeToClassMap[a2] == CAITaskForce::Class(this) )
  {
    if ( this[10] )
    {
      if ( *(int *)(this[10] + 4 * this[2] + 48) <= 0
        && BBSupportDbgReport(
             2,
             "AI\\AI_TaskForces.cpp",
             181,
             "m_pTaskForceGroup->m_sData.m_iNumberOfTaskForcesOfType[m_tTaskForceType] > 0") == 1 )
      {
        __debugbreak();
      }
      --*(_DWORD *)(this[10] + 4 * this[2] + 48);
      ++*(_DWORD *)(this[10] + 4 * a2 + 48);
    }
    result = a2;
    this[2] = a2;
  }
  else
  {
    result = BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 191, "CAITaskForce::ChangeType(): Invalid type!");
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x1327260]
// Decompiled from int __thiscall CAITaskForce::AddEntity(_DWORD *this, CAIEntityInfo *a2, int a3)
enum CAITaskForce::T_RESULT  CAITaskForce::AddEntity(class CAIEntityInfo * a2, enum CAITaskForce::T_POSITION a3) {
  
  if ( !a2 )
    return 0;
  if ( *((_DWORD **)a2 + 2) == this )
  {
    if ( a3 == 1 )
    {
      if ( (CAIEntityInfo *)this[4] == a2 )
        return 1;
    }
    else
    {
      if ( a3 != 2 )
        return 1;
      if ( (CAIEntityInfo *)this[5] == a2 )
        return 1;
    }
  }
  if ( *((_DWORD *)a2 + 2) )
    (*(void (__thiscall **)(_DWORD, CAIEntityInfo *))(**((_DWORD **)a2 + 2) + 24))(*((_DWORD *)a2 + 2), a2);
  if ( *((_DWORD *)a2 + 2)
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 245, "_pEntityInfo->m_pTaskForce == 0") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)a2 + 2) = this;
  if ( a3 == 1 )
  {
    *((_DWORD *)a2 + 3) = 0;
    *((_DWORD *)a2 + 4) = this[4];
    if ( this[4] )
    {
      if ( *(_DWORD **)(this[4] + 8) != this
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 281, "m_pFirstEntity->m_pTaskForce == this") == 1 )
      {
        __debugbreak();
      }
      if ( *(_DWORD *)(this[4] + 12)
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 282, "m_pFirstEntity->m_pPrevEntity == 0") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(this[4] + 12) = a2;
    }
    else
    {
      if ( this[3] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 288, "m_iNumberOfEntities == 0") == 1 )
        __debugbreak();
      this[5] = a2;
    }
    this[4] = a2;
  }
  else
  {
    *((_DWORD *)a2 + 3) = this[5];
    *((_DWORD *)a2 + 4) = 0;
    if ( this[5] )
    {
      if ( *(_DWORD **)(this[5] + 8) != this
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 258, "m_pLastEntity->m_pTaskForce == this") == 1 )
      {
        __debugbreak();
      }
      if ( *(_DWORD *)(this[5] + 16)
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 259, "m_pLastEntity->m_pNextEntity == 0") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(this[5] + 16) = a2;
    }
    else
    {
      if ( this[3] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 265, "m_iNumberOfEntities == 0") == 1 )
        __debugbreak();
      this[4] = a2;
    }
    this[5] = a2;
  }
  CAIEntityInfo::SetTimeStamp(a2, 0);
  ++this[3];
  this[14] |= 0xC000000u;
  if ( (int)this[3] <= 0 )
  {
    if ( this[4] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 319, "m_pFirstEntity == 0") == 1 )
      __debugbreak();
    if ( this[5] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 320, "m_pLastEntity == 0") == 1 )
      __debugbreak();
  }
  else
  {
    if ( !this[4] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 311, "m_pFirstEntity != 0") == 1 )
      __debugbreak();
    if ( !this[5] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 312, "m_pLastEntity != 0") == 1 )
      __debugbreak();
    if ( *(_DWORD *)(this[4] + 12)
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 314, "m_pFirstEntity->m_pPrevEntity == 0") == 1 )
    {
      __debugbreak();
    }
    if ( *(_DWORD *)(this[5] + 16) )
    {
      if ( BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 315, "m_pLastEntity->m_pNextEntity == 0") == 1 )
        __debugbreak();
    }
  }
  return 3;
}


// address=[0x13275f0]
// Decompiled from int __thiscall CAITaskForce::AddEntity(void *this, int a2, int a3)
enum CAITaskForce::T_RESULT  CAITaskForce::AddEntity(int a2, enum CAITaskForce::T_POSITION a3) {
  
  unsigned __int16 *EntityInfo; // [esp+4h] [ebp-4h]

  EntityInfo = (unsigned __int16 *)IAIEnvironment::EntityGetEntityInfo(a2, 1u);
  if ( EntityInfo )
  {
    if ( *EntityInfo != a2
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 341, "pEntityInfo->m_uEntityId == _iEntityId") == 1 )
    {
      __debugbreak();
    }
    return (*(int (__thiscall **)(void *, unsigned __int16 *, int))(*(_DWORD *)this + 20))(this, EntityInfo, a3);
  }
  else
  {
    if ( BBSupportDbgReportF(1, "AI\\AI_TaskForces.cpp", 347, "CAITaskForce::AddEntity(): Invalid entity id %i!", a2) == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x1327690]
// Decompiled from int __thiscall CAITaskForce::RemoveEntity(int *this, _DWORD *a2)
enum CAITaskForce::T_RESULT  CAITaskForce::RemoveEntity(class CAIEntityInfo * a2) {
  
  if ( !a2 )
    return 0;
  if ( (int *)a2[2] == this )
  {
    if ( (_DWORD *)IAIEnvironment::EntityGetEntityInfo(*(unsigned __int16 *)a2, 0) != a2
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 374, "g_pAIEnv->EntityGetEntityInfo(iEntityId) == _pEntityInfo") == 1 )
    {
      __debugbreak();
    }
    if ( a2[3] )
    {
      if ( *(int **)(a2[3] + 8) != this
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 380, "_pEntityInfo->m_pPrevEntity->m_pTaskForce == this") == 1 )
      {
        __debugbreak();
      }
      if ( *(_DWORD **)(a2[3] + 16) != a2
        && BBSupportDbgReport(
             2,
             "AI\\AI_TaskForces.cpp",
             381,
             "_pEntityInfo->m_pPrevEntity->m_pNextEntity == _pEntityInfo") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(a2[3] + 16) = a2[4];
    }
    else
    {
      if ( (_DWORD *)this[4] != a2
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 387, "m_pFirstEntity == _pEntityInfo") == 1 )
      {
        __debugbreak();
      }
      this[4] = a2[4];
    }
    if ( a2[4] )
    {
      if ( *(int **)(a2[4] + 8) != this
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 396, "_pEntityInfo->m_pNextEntity->m_pTaskForce == this") == 1 )
      {
        __debugbreak();
      }
      if ( *(_DWORD **)(a2[4] + 12) != a2
        && BBSupportDbgReport(
             2,
             "AI\\AI_TaskForces.cpp",
             397,
             "_pEntityInfo->m_pNextEntity->m_pPrevEntity == _pEntityInfo") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(a2[4] + 12) = a2[3];
    }
    else
    {
      if ( (_DWORD *)this[5] != a2
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 403, "m_pLastEntity == _pEntityInfo") == 1 )
      {
        __debugbreak();
      }
      this[5] = a2[3];
    }
    a2[2] = 0;
    a2[3] = 0;
    a2[4] = 0;
    if ( this[3] <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 416, "m_iNumberOfEntities > 0") == 1 )
      __debugbreak();
    if ( this[3] > 0 )
      --this[3];
    if ( this[3] <= 0 )
    {
      if ( this[4] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 435, "m_pFirstEntity == 0") == 1 )
        __debugbreak();
      if ( this[5] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 436, "m_pLastEntity == 0") == 1 )
        __debugbreak();
    }
    else
    {
      if ( !this[4] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 427, "m_pFirstEntity != 0") == 1 )
        __debugbreak();
      if ( !this[5] && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 428, "m_pLastEntity != 0") == 1 )
        __debugbreak();
      if ( *(_DWORD *)(this[4] + 12)
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 430, "m_pFirstEntity->m_pPrevEntity == 0") == 1 )
      {
        __debugbreak();
      }
      if ( *(_DWORD *)(this[5] + 16)
        && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 431, "m_pLastEntity->m_pNextEntity == 0") == 1 )
      {
        __debugbreak();
      }
    }
    return 4;
  }
  else
  {
    if ( BBSupportDbgReport(1, "AI\\AI_TaskForces.cpp", 367, "CAITaskForce::RemoveEntity(): Entity not in taskforce!") == 1 )
      __debugbreak();
    return 2;
  }
}


// address=[0x13279f0]
// Decompiled from int __thiscall CAITaskForce::RemoveEntity(void *this, int a2)
enum CAITaskForce::T_RESULT  CAITaskForce::RemoveEntity(int a2) {
  
  int EntityInfo; // [esp+4h] [ebp-4h]

  EntityInfo = IAIEnvironment::EntityGetEntityInfo(a2, 0);
  if ( EntityInfo )
    return (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 24))(this, EntityInfo);
  else
    return 2;
}


// address=[0x1327a30]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::RemoveAllEntities(CAITaskForce *this)
void  CAITaskForce::RemoveAllEntities(void) {
  
  CAITaskForce *result; // eax
  int v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = *((_DWORD *)this + 4); i; i = v3 )
  {
    ++v2;
    v3 = *(_DWORD *)(i + 16);
    if ( *(CAITaskForce **)(i + 8) != this
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 486, "pEntityInfo->m_pTaskForce == this") == 1 )
    {
      __debugbreak();
    }
    if ( v3
      && *(_DWORD *)(v3 + 12) != i
      && BBSupportDbgReport(
           2,
           "AI\\AI_TaskForces.cpp",
           487,
           "(pNextEntityInfo == 0) || (pNextEntityInfo->m_pPrevEntity == pEntityInfo)") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(i + 8) = 0;
    *(_DWORD *)(i + 12) = 0;
    *(_DWORD *)(i + 16) = 0;
  }
  if ( *((_DWORD *)this + 3) != v2
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 500, "m_iNumberOfEntities == iCounter") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return result;
}


// address=[0x1327b40]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::SetAssociatedTaskForce(CAITaskForce *this, struct CAITaskForce *a2)
void  CAITaskForce::SetAssociatedTaskForce(class CAITaskForce * a2) {
  
  CAITaskForce *result; // eax

  if ( *((_DWORD *)this + 11) )
  {
    CAITaskForce::ClearAssociatedTaskForce(this);
    if ( BBSupportDbgReport(
           1,
           "AI\\AI_TaskForces.cpp",
           520,
           "CAITaskForce::SetAssociatedTaskForce(): Task force has already a associated task force!") == 1 )
      __debugbreak();
  }
  if ( a2 )
  {
    if ( a2 == this && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 525, "_pTaskForce != this") == 1 )
      __debugbreak();
    if ( *((_DWORD *)a2 + 11) )
    {
      CAITaskForce::ClearAssociatedTaskForce(a2);
      if ( BBSupportDbgReport(
             1,
             "AI\\AI_TaskForces.cpp",
             531,
             "CAITaskForce::SetAssociatedTaskForce(): Associated task force is already associated!") == 1 )
        __debugbreak();
    }
    if ( !*((_DWORD *)this + 10) && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 534, "m_pTaskForceGroup != 0") == 1 )
      __debugbreak();
    if ( *((_DWORD *)this + 10) != *((_DWORD *)a2 + 10)
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 535, "m_pTaskForceGroup == _pTaskForce->m_pTaskForceGroup") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)this + 11) = a2;
    result = this;
    *((_DWORD *)a2 + 11) = this;
  }
  else
  {
    result = (CAITaskForce *)BBSupportDbgReport(
                               1,
                               "AI\\AI_TaskForces.cpp",
                               542,
                               "CAITaskForce::SetAssociatedTaskForce(): Associated task force == 0!");
    if ( result == (CAITaskForce *)1 )
      __debugbreak();
  }
  return result;
}


// address=[0x1327c70]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::ClearAssociatedTaskForce(CAITaskForce **this)
void  CAITaskForce::ClearAssociatedTaskForce(void) {
  
  CAITaskForce *result; // eax

  result = (CAITaskForce *)this;
  if ( !this[11] )
    return result;
  if ( *((CAITaskForce ***)this[11] + 11) != this
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 555, "m_pAssociatedTaskForce->m_pAssociatedTaskForce == this") == 1 )
  {
    __debugbreak();
  }
  result = this[11];
  *((_DWORD *)result + 11) = 0;
  this[11] = 0;
  return result;
}


// address=[0x1327cd0]
// Decompiled from int __thiscall CAITaskForce::Load(CAITaskForce *this, struct IS4Chunk *a2)
void  CAITaskForce::Load(class IS4Chunk & a2) {
  
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  (*(void (__thiscall **)(CAITaskForce *))(*(_DWORD *)this + 28))(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371712);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371710);
  *((_BYTE *)this + 52) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_BYTE *)this + 53) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_BYTE *)this + 54) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_BYTE *)this + 55) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 14) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 15) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 16) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 17) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 18) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 19) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371709);
  v3 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  for ( i = 0; i < v3; ++i )
  {
    v4 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    if ( IAIEnvironment::EntityIsAlive(v4) )
      CAITaskForce::AddEntity(this, v4, 2);
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371711);
}


// address=[0x1327e60]
// Decompiled from int __thiscall CAITaskForce::Save(CAITaskForce *this, struct IS4Chunk *a2)
void  CAITaskForce::Save(class IS4Chunk & a2) {
  
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int Entity; // [esp+8h] [ebp-8h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371712);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371710);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((unsigned __int8 *)this + 52));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((unsigned __int8 *)this + 53));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((unsigned __int8 *)this + 54));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((unsigned __int8 *)this + 55));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 14));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 15));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 16));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 17));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 18));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 19));
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371709);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 3));
  v4 = 0;
  Entity = CAITaskForce::FirstEntity(this);
  while ( Entity )
  {
    v3 = CAIEntityInfo::EntityId(Entity);
    (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v3);
    Entity = CAIEntityInfo::Next(Entity);
    ++v4;
  }
  if ( v4 != *((_DWORD *)this + 3)
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 791, "iCounter == m_iNumberOfEntities") == 1 )
  {
    __debugbreak();
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371711);
}


// address=[0x1328020]
// Decompiled from bool __thiscall CAITaskForce::IsGoalValid(_DWORD *this, int a2)
bool  CAITaskForce::IsGoalValid(enum CAITaskForce::T_GOAL_TYPE a2) {
  
  if ( !a2 )
    return 0;
  if ( a2 == 1 )
    return (this[14] & 0x1000) != 0 && IAIEnvironment::EntityIsAliveAndHasGivenUniqueId(this[15], this[16]);
  else
    return a2 == 2 && (this[14] & 0x2000) != 0;
}


// address=[0x13280c0]
// Decompiled from char *__thiscall CAITaskForce::ShortName(_DWORD *this)
char const *  CAITaskForce::ShortName(void)const {
  
  return (&off_3D7A714)[this[2]];
}


// address=[0x13280e0]
// Decompiled from char __thiscall CAITaskForce::GetPositionOfFirstEntity(CAITaskForce *this, int *a2, int *a3)
bool  CAITaskForce::GetPositionOfFirstEntity(int & a2, int & a3) {
  
  int v4; // [esp+4h] [ebp-8h]
  int Entity; // [esp+8h] [ebp-4h]

  Entity = CAITaskForce::FirstEntity(this);
  if ( Entity )
  {
    v4 = CAIEntityInfo::EntityId(Entity);
    if ( v4 <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 646, "iEntityId > 0") == 1 )
      __debugbreak();
    IAIEnvironment::EntityGetPosition(v4, a2, a3);
    if ( !IAIEnvironment::WorldInWorld(*a2, *a3)
      && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 650, "g_pAIEnv->WorldInWorld(_rX, _rY)") == 1 )
    {
      __debugbreak();
    }
    return 1;
  }
  else
  {
    *a2 = -1;
    *a3 = -1;
    return 0;
  }
}


// address=[0x132a520]
// Decompiled from int __thiscall CAITaskForce::TaskForceGroup(CAITaskForce *this)
class CAITaskForceGroup const *  CAITaskForce::TaskForceGroup(void)const {
  
  return *((_DWORD *)this + 10);
}


// address=[0x132e9b0]
// Decompiled from bool __thiscall CAITaskForce::GoalIsEntity(CAITaskForce *this)
bool  CAITaskForce::GoalIsEntity(void)const {
  
  return (*((_DWORD *)this + 14) & 0x1000) != 0;
}


// address=[0x132e9f0]
// Decompiled from bool __thiscall CAITaskForce::GoalIsPosition(CAITaskForce *this)
bool  CAITaskForce::GoalIsPosition(void)const {
  
  return (*((_DWORD *)this + 14) & 0x2000) != 0;
}


// address=[0x132ec90]
// Decompiled from int __thiscall CAITaskForce::SetWaitCounter(CAITaskForce *this, unsigned int a2)
void  CAITaskForce::SetWaitCounter(unsigned int a2) {
  
  int result; // eax

  if ( a2 >= 0x100
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
         270,
         "_uNewCounter < 0x100") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  *((_BYTE *)this + 52) = a2;
  return result;
}


// address=[0x132ece0]
// Decompiled from int __thiscall CAITaskForce::State(CAITaskForce *this)
int  CAITaskForce::State(void)const {
  
  return *((unsigned __int8 *)this + 53);
}


// address=[0x13197f0]
// Decompiled from char __thiscall CAITaskForce::IsAddEntityOk(CAITaskForce *this, int a2)
bool  CAITaskForce::IsAddEntityOk(int a2) {
  
  return 1;
}


// address=[0x1326f40]
// Decompiled from int __thiscall CAITaskForce::CAITaskForce(int this, int a2, int a3, int a4, int a5)
 CAITaskForce::CAITaskForce(int a2, enum T_AI_TASK_FORCE_CLASS a3, enum T_AI_TASK_FORCE_TYPE a4, int a5) {
  
  IS4ChunkObject::IS4ChunkObject((IS4ChunkObject *)this);
  *(_DWORD *)this = CAITaskForce::_vftable_;
  *(_DWORD *)(this + 4) = a3;
  if ( !IAIEnvironment::AlliancesIsValidUsedPlayerId(a2)
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 98, "g_pAIEnv->AlliancesIsValidUsedPlayerId(_iOwnerId)") == 1 )
  {
    __debugbreak();
  }
  if ( g_tAITaskForceTypeToClassMap[a4] != a3
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 99, "g_tAITaskForceTypeToClassMap[_tType] == _tClass") == 1 )
  {
    __debugbreak();
  }
  if ( (a5 & 0xFFFFFFF) != 0
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         100,
         "(_iFlags & ~(AI_TASK_FORCE_FLAG_TASK_FORCE_FLAGS_MASK & ~AI_TASK_FORCE_FLAG_TASK_FORCE_INTERNAL_FLAGS_MASK)) == 0") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)(this + 8) = a4;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  *(_DWORD *)(this + 44) = 0;
  *(_BYTE *)(this + 52) = 0;
  *(_BYTE *)(this + 53) = 0;
  *(_BYTE *)(this + 54) = 0;
  *(_BYTE *)(this + 55) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 56) = a2 | a5;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_DWORD *)(this + 76) = 0;
  CAITaskForces::AddTaskForce((struct CAITaskForce *)this);
  return this;
}


// address=[0x13281a0]
// Decompiled from int __thiscall CAITaskForce::SetCommand(CAITaskForce *this, unsigned int a2, int a3, int a4)
void  CAITaskForce::SetCommand(int a2, int a3, int a4) {
  
  int result; // eax

  if ( a2 > 0xE
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         806,
         "static_cast<unsigned int>(_iCommand) <= AI_TASK_FORCE_CMD_LAST") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 & 0xFFFF3FFF) != 0
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         807,
         "(_iFlags & ~(AI_TASK_FORCE_FLAG_CMD_FLAGS_MASK & ~AI_TASK_FORCE_FLAG_CMD_INTERNAL_FLAGS_MASK)) == 0") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 14) = a4 | (16 * a2) | *((_DWORD *)this + 14) & 0xF3FF000F;
  *((_DWORD *)this + 15) = a3;
  *((_DWORD *)this + 16) = 0;
  result = IAIEnvironment::TickCounter();
  *((_DWORD *)this + 17) = result;
  return result;
}


// address=[0x1328240]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::MarkGoalAsEntity(CAITaskForce *this)
void  CAITaskForce::MarkGoalAsEntity(void) {
  
  CAITaskForce *result; // eax
  int v2; // [esp+0h] [ebp-8h]

  if ( (*((_DWORD *)this + 14) & 0x3000) != 0
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         579,
         "(m_uFlags & (AI_TASK_FORCE_FLAG_CMD_GOAL_IS_ENTITY | AI_TASK_FORCE_FLAG_CMD_GOAL_IS_POSITION)) == 0") == 1 )
  {
    __debugbreak();
  }
  v2 = IAIEnvironment::EntityUniqueId(*((_DWORD *)this + 15));
  if ( v2 <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 583, "iCmdUniqueId > 0") == 1 )
    __debugbreak();
  *((_DWORD *)this + 14) |= 0x1000u;
  result = this;
  *((_DWORD *)this + 16) = v2;
  return result;
}


// address=[0x13282d0]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::MarkGoalAsPosition(CAITaskForce *this)
void  CAITaskForce::MarkGoalAsPosition(void) {
  
  CAITaskForce *result; // eax

  if ( (*((_DWORD *)this + 14) & 0x3000) != 0
    && BBSupportDbgReport(
         2,
         "AI\\AI_TaskForces.cpp",
         670,
         "(m_uFlags & (AI_TASK_FORCE_FLAG_CMD_GOAL_IS_ENTITY | AI_TASK_FORCE_FLAG_CMD_GOAL_IS_POSITION)) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !IAIEnvironment::WorldInWorldPackedXY(*((_DWORD *)this + 15))
    && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 672, "g_pAIEnv->WorldInWorldPackedXY(m_uCmdGoal)") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 16) && BBSupportDbgReport(2, "AI\\AI_TaskForces.cpp", 673, "m_uCmdUniqueId == 0") == 1 )
    __debugbreak();
  result = this;
  *((_DWORD *)this + 14) |= 0x2000u;
  return result;
}


// address=[0x132a4a0]
// Decompiled from int __thiscall CAITaskForce::DecWaitCounter(CAITaskForce *this, unsigned int a2)
unsigned int  CAITaskForce::DecWaitCounter(unsigned int a2) {
  
  char v3; // [esp+0h] [ebp-8h]

  if ( *((unsigned __int8 *)this + 52) <= a2 )
    v3 = 0;
  else
    v3 = *((_BYTE *)this + 52) - a2;
  *((_BYTE *)this + 52) = v3;
  return *((unsigned __int8 *)this + 52);
}


// address=[0x132e810]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::ActivateNextState(CAITaskForce *this)
void  CAITaskForce::ActivateNextState(void) {
  
  CAITaskForce *result; // eax

  result = this;
  *((_BYTE *)this + 53) = *((_BYTE *)this + 54);
  return result;
}


// address=[0x132e870]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::ClearInternalFlagBit(CAITaskForce *this, unsigned int a2)
void  CAITaskForce::ClearInternalFlagBit(unsigned int a2) {
  
  CAITaskForce *result; // eax

  if ( (a2 & 0xF0FFFFFF) != 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
         357,
         "(_uMask & ~AI_TASK_FORCE_FLAG_TASK_FORCE_INTERNAL_FLAGS_MASK) == 0") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_DWORD *)this + 14) &= ~a2;
  return result;
}


// address=[0x132e8d0]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::ClearStateFlagBit(CAITaskForce *this, unsigned int a2)
void  CAITaskForce::ClearStateFlagBit(unsigned int a2) {
  
  CAITaskForce *result; // eax

  if ( (a2 & 0xFF00FFFF) != 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
         371,
         "(_uMask & ~AI_TASK_FORCE_FLAG_STATE_FLAGS_MASK) == 0") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_DWORD *)this + 14) &= ~a2;
  return result;
}


// address=[0x132ea30]
// Decompiled from bool __thiscall CAITaskForce::IsTaskForceExState(CAITaskForce *this, int a2)
bool  CAITaskForce::IsTaskForceExState(int a2) {
  
  return (unsigned int)(a2 - 100) < 0xD;
}


// address=[0x132eb20]
// Decompiled from int __thiscall CAITaskForce::SetNewStatusAndState(CAITaskForce *this, int a2, char a3, int a4)
void  CAITaskForce::SetNewStatusAndState(enum T_AI_TASK_FORCE_STATUS a2, int a3, int a4) {
  
  CAITaskForce::SetStateEx(this, a3, a4);
  return CAITaskForce::SetStatus(this, a2);
}


// address=[0x132eb60]
// Decompiled from CAITaskForce *__thiscall CAITaskForce::SetState(CAITaskForce *this, char a2)
void  CAITaskForce::SetState(int a2) {
  
  CAITaskForce *result; // eax

  result = this;
  *((_BYTE *)this + 53) = a2;
  return result;
}


// address=[0x132eb80]
// Decompiled from char __thiscall CAITaskForce::SetStateEx(CAITaskForce *this, char a2, int a3)
void  CAITaskForce::SetStateEx(int a2, int a3) {
  
  char result; // al

  if ( a3
    && CAITaskForce::IsTaskForceExState(this, a3)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
         433,
         "(_iNextState == AI_TASK_FORCE_STATE_IDLE) || !IsTaskForceExState(_iNextState)") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 53) = a2;
  result = a3;
  *((_BYTE *)this + 54) = a3;
  return result;
}


// address=[0x132ebf0]
// Decompiled from unsigned int __thiscall CAITaskForce::SetStateFlagBit(CAITaskForce *this, unsigned int a2)
void  CAITaskForce::SetStateFlagBit(unsigned int a2) {
  
  unsigned int result; // eax

  if ( (a2 & 0xFF00FFFF) != 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_TaskForces.h",
         364,
         "(_uMask & ~AI_TASK_FORCE_FLAG_STATE_FLAGS_MASK) == 0") == 1 )
  {
    __debugbreak();
  }
  result = a2 | *((_DWORD *)this + 14);
  *((_DWORD *)this + 14) = result;
  return result;
}


// address=[0x132ec50]
// Decompiled from int __thiscall CAITaskForce::SetStatus(int this, int a2)
void  CAITaskForce::SetStatus(enum T_AI_TASK_FORCE_STATUS a2) {
  
  int result; // eax

  result = this;
  if ( *(unsigned __int8 *)(this + 55) == a2 )
    return result;
  *(_BYTE *)(this + 55) = a2;
  result = IAIEnvironment::TickCounter();
  *(_DWORD *)(this + 72) = result;
  return result;
}


