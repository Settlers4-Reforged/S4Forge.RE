#include "CLink.h"

// Definitions for class CLink

// address=[0x15e7010]
// Decompiled from bool __thiscall CLink::IsHeader(CLink *this)
bool CLink::IsHeader(void) const {
  return HIBYTE(this->m_uData) == 253;
}


// address=[0x15e74d0]
// Decompiled from bool __thiscall CLink::Unused(CLink *this)
bool CLink::Unused(void) const {
  return HIBYTE(this->m_uData) == 255;
}


// address=[0x15e7550]
// Decompiled from bool __thiscall CLink::Used(CLink *this)
bool CLink::Used(void) const {
  return HIBYTE(this->m_uData) < 254u;
}


// address=[0x15f5360]
// Decompiled from bool __thiscall CLink::PrevLinkIsLastOne(CLink *this)
bool CLink::PrevLinkIsLastOne(void) const {
  return HIBYTE(this->m_uData) >= 253u;
}


