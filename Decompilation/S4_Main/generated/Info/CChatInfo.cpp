#include "CChatInfo.h"

// Definitions for class CChatInfo

// address=[0x14aa640]
// Decompiled from CChatInfo *__thiscall CChatInfo::CChatInfo(CChatInfo *this)
 CChatInfo::CChatInfo(void) {
  
  _vec_ctor((char *)this->m_asPlayerInfo, 0x28u, 8u, (void (__thiscall *)(void *))SPlayerInfo::SPlayerInfo, SPlayerInfo::~SPlayerInfo);
  return this;
}


// address=[0x14aa940]
// Decompiled from void __thiscall CChatInfo::~CChatInfo(CChatInfo *this)
 CChatInfo::~CChatInfo(void) {
  
  `eh vector destructor iterator'(this->m_asPlayerInfo, 0x28u, 8u, SPlayerInfo::~SPlayerInfo);
}


