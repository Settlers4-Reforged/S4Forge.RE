#include "CAIEntityInfo.h"

// Definitions for class CAIEntityInfo

// address=[0x12fd010]
// Decompiled from int __thiscall CAIEntityInfo::EntityId(CAIEntityInfo *this)
int  CAIEntityInfo::EntityId(void)const {
  
  return this->m_iEntityId;
}


// address=[0x12fd380]
// Decompiled from CAIEntityInfo *__thiscall CAIEntityInfo::Next(CAIEntityInfo *this)
class CAIEntityInfo *  CAIEntityInfo::Next(void)const {
  
  return this->m_pNextEntity;
}


// address=[0x12fd730]
// Decompiled from struct CAITaskForce *__thiscall CAIEntityInfo::TaskForce(CAIEntityInfo *this)
class CAITaskForce *  CAIEntityInfo::TaskForce(void)const {
  
  return this->m_pTaskForce;
}


// address=[0x1306910]
// Decompiled from int __thiscall CAIEntityInfo::Prev(pairNode *this)
class CAIEntityInfo *  CAIEntityInfo::Prev(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x13069a0]
// Decompiled from void __thiscall CAIEntityInfo::SetTargetId(CAIEntityInfo *this, unsigned __int16 a2)
void  CAIEntityInfo::SetTargetId(int a2) {
  
  this->m_iTargetId = a2;
}


// address=[0x13069c0]
// Decompiled from void __thiscall CAIEntityInfo::SetTimeStamp(CAIEntityInfo *this, unsigned int a2)
void  CAIEntityInfo::SetTimeStamp(unsigned int a2) {
  
  this->m_uTimeStamp = a2;
}


// address=[0x13069e0]
// Decompiled from int __thiscall CAIEntityInfo::TargetId(CAIEntityInfo *this)
int  CAIEntityInfo::TargetId(void)const {
  
  return *((unsigned __int16 *)this + 1);
}


// address=[0x1306a00]
// Decompiled from int __thiscall CAIEntityInfo::TimeStamp(CAIEntityInfo *this)
unsigned int  CAIEntityInfo::TimeStamp(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x130a880]
// Decompiled from CAIEntityInfo *__thiscall CAIEntityInfo::CAIEntityInfo(CAIEntityInfo *this, __int16 a2)
 CAIEntityInfo::CAIEntityInfo(int a2) {
  
  this->m_iEntityId = a2;
  this->m_iTargetId = 0;
  this->m_uTimeStamp = 0;
  this->m_pTaskForce = 0;
  this->m_pPrevEntity = 0;
  this->m_pNextEntity = 0;
  this->m_pInfoEx = 0;
  return this;
}


// address=[0x130a8e0]
// Decompiled from CAIEntityInfo *__thiscall CAIEntityInfo::~CAIEntityInfo(CAIEntityInfo *this)
 CAIEntityInfo::~CAIEntityInfo(void) {
  
  CAIEntityInfo *result; // eax

  if ( *((_DWORD *)this + 2) )
  {
    (*(void (__thiscall **)(_DWORD, CAIEntityInfo *))(**((_DWORD **)this + 2) + 24))(*((_DWORD *)this + 2), this);
    *((_DWORD *)this + 2) = 0;
  }
  if ( *((_DWORD *)this + 2) && BBSupportDbgReport(2, "AI\\AI_EntityInfo.cpp", 66, "m_pTaskForce == 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 3) && BBSupportDbgReport(2, "AI\\AI_EntityInfo.cpp", 67, "m_pPrevEntity == 0") == 1 )
    __debugbreak();
  result = this;
  if ( *((_DWORD *)this + 4) )
  {
    result = (CAIEntityInfo *)BBSupportDbgReport(2, "AI\\AI_EntityInfo.cpp", 68, "m_pNextEntity == 0");
    if ( result == (CAIEntityInfo *)1 )
      __debugbreak();
  }
  if ( !*((_DWORD *)this + 5) )
    return result;
  result = (CAIEntityInfo *)(***((int (__thiscall ****)(_DWORD, int))this + 5))(*((_DWORD *)this + 5), 1);
  *((_DWORD *)this + 5) = 0;
  return result;
}


// address=[0x130aa00]
// Decompiled from CAIEntityInfoEx *__thiscall CAIEntityInfo::ExtendedInfo(CAIEntityInfo *this, int a2)
class CAIEntityInfoEx *  CAIEntityInfo::ExtendedInfo(enum T_AI_ENTITY_INFO_EX_CLASS a2) {
  
  CAIEntityInfoEx *m_pInfoEx; // [esp+8h] [ebp-8h]

  if ( this->m_pInfoEx )
  {
    if ( CAIEntityInfoEx::Class((unsigned __int8 *)this->m_pInfoEx) == a2 )
      return this->m_pInfoEx;
    if ( BBSupportDbgReport(
           1,
           "AI\\AI_EntityInfo.cpp",
           93,
           "CAIEntityInfo::ExtendedInfo(): Given class differs from current one!") == 1 )
      __debugbreak();
    m_pInfoEx = this->m_pInfoEx;
    if ( m_pInfoEx )
      m_pInfoEx->vftable->dtor(m_pInfoEx, 1);
    this->m_pInfoEx = 0;
  }
  if ( this->m_pInfoEx && BBSupportDbgReport(2, "AI\\AI_EntityInfo.cpp", 101, "m_pInfoEx == 0") == 1 )
    __debugbreak();
  this->m_pInfoEx = CAIEntityInfoEx::CreateExtendedInfo(a2);
  if ( !this->m_pInfoEx && BBSupportDbgReport(2, "AI\\AI_EntityInfo.cpp", 105, "m_pInfoEx != 0") == 1 )
    __debugbreak();
  return this->m_pInfoEx;
}


