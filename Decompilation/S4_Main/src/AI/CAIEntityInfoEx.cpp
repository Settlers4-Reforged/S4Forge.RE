#include "CAIEntityInfoEx.h"

#include "CBB/CBBSupport.h"

// Definitions for class CAIEntityInfoEx

// address=[0x130acc0]
// Decompiled from CAIEntityInfoEx *__thiscall CAIEntityInfoEx::CAIEntityInfoEx(CAIEntityInfoEx *this, char a2)
CAIEntityInfoEx::CAIEntityInfoEx(T_AI_ENTITY_INFO_EX_CLASS a2) {
  this->m_bClass = a2;
}


// address=[0x130acf0]
// Decompiled from CAIEntityInfoEx *__thiscall CAIEntityInfoEx::~CAIEntityInfoEx(CAIEntityInfoEx *this)
CAIEntityInfoEx::~CAIEntityInfoEx(void) = default;


// address=[0x130adb0]
// Decompiled from int __thiscall CAIEntityInfoEx::Class(unsigned __int8 *this)
enum T_AI_ENTITY_INFO_EX_CLASS CAIEntityInfoEx::Class(void) const {
  return this->m_bClass;
}


// address=[0x130aaf0]
// Decompiled from CAIEntityInfoTower *__cdecl CAIEntityInfoEx::CreateExtendedInfo(int a1)
class CAIEntityInfoEx * __cdecl CAIEntityInfoEx::CreateExtendedInfo(enum T_AI_ENTITY_INFO_EX_CLASS a1) {
  // [esp+Ch] [ebp-18h]
  // [esp+14h] [ebp-10h]


  if(a1 >= AI_ENTITY_INFO_EX_CLASS_MAX) {
    if(BBSupportDbgReport(1, "AI\\AI_EntityInfo.cpp", 135, "CAIEntityInfoEx::CreateExtendedInfo(): Invalid class!") == 1)
      __debugbreak();
  } else {
    return new CAIEntityInfoTower();
  }
  return nullptr;
}


