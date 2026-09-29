#if FALSE
#include "CSurfaceDescription.h"

// Definitions for class CSurfaceDescription

// address=[0x2f87700]
// Decompiled from CSurfaceDescription *__thiscall CSurfaceDescription::CSurfaceDescription(CSurfaceDescription *this)
 CSurfaceDescription::CSurfaceDescription(void) {
  
  memset(this, 0, 0x7Cu);
  memset(&this->m_sSurfaceDescriptionOld, 0, sizeof(this->m_sSurfaceDescriptionOld));
  this->m_sSurfaceDescription.dwSize = 0x7C;
  this->m_sSurfaceDescriptionOld.dwSize = 108;
  this->m_sSurfaceDescription.ddpfPixelFormat.dwSize = 32;
  this->m_sSurfaceDescriptionOld.ddpfPixelFormat.dwSize = 32;
  return this;
}


#endif // Already implemented
