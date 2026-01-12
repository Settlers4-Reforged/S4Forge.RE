#include "CAIEntityInfo.h"

// Definitions for class CAIEntityInfo

// address=[0x12fd010]
// Decompiled from int __thiscall CAIEntityInfo::EntityId(CAIEntityInfo *this)

int  CAIEntityInfo::EntityId(void)const {
  
  return *(unsigned __int16 *)this;
}


// address=[0x12fd380]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CAIEntityInfo::Next(CAIEntityInfo *this)

class CAIEntityInfo *  CAIEntityInfo::Next(void)const {
  
  return *((_DWORD *)this + 4);
}


// address=[0x12fd730]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CAIEntityInfo::TaskForce(CAIEntityInfo *this)

class CAITaskForce *  CAIEntityInfo::TaskForce(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x1306910]
// Decompiled from int __thiscall CAIEntityInfo::Prev(pairNode *this)

class CAIEntityInfo *  CAIEntityInfo::Prev(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x13069a0]
// Decompiled from void __thiscall CAIEntityInfo::SetTargetId(CPropertySet *this, unsigned __int16 a2)

void  CAIEntityInfo::SetTargetId(int) {
  
  *((_WORD *)this + 1) = a2;
}


// address=[0x13069c0]
// Decompiled from // MFC 3.1-14.0 32bit
CAIEntityInfo *__thiscall CAIEntityInfo::SetTimeStamp(CAIEntityInfo *this, unsigned int a2)

void  CAIEntityInfo::SetTimeStamp(unsigned int) {
  
  CAIEntityInfo *result; // eax

  result = this;
  *((_DWORD *)this + 1) = a2;
  return result;
}


// address=[0x13069e0]
// Decompiled from int __thiscall CAIEntityInfo::TargetId(CAIEntityInfo *this)

int  CAIEntityInfo::TargetId(void)const {
  
  return *((unsigned __int16 *)this + 1);
}


// address=[0x1306a00]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CAIEntityInfo::TimeStamp(CAIEntityInfo *this)

unsigned int  CAIEntityInfo::TimeStamp(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x130a880]
// Decompiled from CAIEntityInfo *__thiscall CAIEntityInfo::CAIEntityInfo(CAIEntityInfo *this, __int16 a2)

 CAIEntityInfo::CAIEntityInfo(int) {
  
  *(_WORD *)this = a2;
  *((_WORD *)this + 1) = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
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
// Decompiled from int __thiscall CAIEntityInfo::ExtendedInfo(_DWORD *this, int a2)

class CAIEntityInfoEx *  CAIEntityInfo::ExtendedInfo(enum T_AI_ENTITY_INFO_EX_CLASS) {
  
  void (__thiscall ***v3)(_DWORD, int); // [esp+8h] [ebp-8h]

  if ( this[5] )
  {
    if ( CAIEntityInfoEx::Class(this[5]) == a2 )
      return this[5];
    if ( BBSupportDbgReport(
           1,
           "AI\\AI_EntityInfo.cpp",
           93,
           "CAIEntityInfo::ExtendedInfo(): Given class differs from current one!") == 1 )
      __debugbreak();
    v3 = (void (__thiscall ***)(_DWORD, int))this[5];
    if ( v3 )
      (**v3)(v3, 1);
    this[5] = 0;
  }
  if ( this[5] && BBSupportDbgReport(2, "AI\\AI_EntityInfo.cpp", 101, "m_pInfoEx == 0") == 1 )
    __debugbreak();
  this[5] = CAIEntityInfoEx::CreateExtendedInfo(a2);
  if ( !this[5] && BBSupportDbgReport(2, "AI\\AI_EntityInfo.cpp", 105, "m_pInfoEx != 0") == 1 )
    __debugbreak();
  return this[5];
}


