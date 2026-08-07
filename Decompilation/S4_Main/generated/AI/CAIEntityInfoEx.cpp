#if FALSE
#include "CAIEntityInfoEx.h"

// Definitions for class CAIEntityInfoEx

// address=[0x130acc0]
// Decompiled from CAIEntityInfoEx *__thiscall CAIEntityInfoEx::CAIEntityInfoEx(CAIEntityInfoEx *this, char a2)
 CAIEntityInfoEx::CAIEntityInfoEx(enum T_AI_ENTITY_INFO_EX_CLASS a2) {
  
  this->vftable = (CAIEntityInfoEx_vtbl *)&CAIEntityInfoEx::_vftable_;
  this->m_bClass = a2;
  return this;
}


// address=[0x130acf0]
// Decompiled from CAIEntityInfoEx *__thiscall CAIEntityInfoEx::~CAIEntityInfoEx(CAIEntityInfoEx *this)
 CAIEntityInfoEx::~CAIEntityInfoEx(void) {
  
  CAIEntityInfoEx *result; // eax

  result = this;
  *(_DWORD *)this = &CAIEntityInfoEx::_vftable_;
  return result;
}


// address=[0x130adb0]
// Decompiled from int __thiscall CAIEntityInfoEx::Class(CAIEntityInfoEx *this)
enum T_AI_ENTITY_INFO_EX_CLASS  CAIEntityInfoEx::Class(void)const {
  
  return (unsigned __int8)this->m_bClass;
}


// address=[0x130aaf0]
// Decompiled from CAIEntityInfoTower *__cdecl CAIEntityInfoEx::CreateExtendedInfo(int a1)
class CAIEntityInfoEx * __cdecl CAIEntityInfoEx::CreateExtendedInfo(enum T_AI_ENTITY_INFO_EX_CLASS a1) {
  
  int v2; // [esp+Ch] [ebp-18h]
  CAIEntityInfoTower *C; // [esp+14h] [ebp-10h]

  v2 = 0;
  if ( a1 )
  {
    if ( BBSupportDbgReport(1, "AI\\AI_EntityInfo.cpp", 135, "CAIEntityInfoEx::CreateExtendedInfo(): Invalid class!") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    C = (CAIEntityInfoTower *)operator new(0x14u);
    if ( C )
    {
      return CAIEntityInfoTower::CAIEntityInfoTower(C);
    }
    else
    {
      return 0;
    }
  }
  return (CAIEntityInfoTower *)v2;
}


#endif // Already implemented
