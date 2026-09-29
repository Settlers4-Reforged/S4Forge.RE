#include "CSurfaceDescription.h"

// Definitions for class CSurfaceDescription

CSurfaceDescription s_cSurfaceDescription;

// address=[0x2f87700]
// Decompiled from CSurfaceDescription *__thiscall CSurfaceDescription::CSurfaceDescription(CSurfaceDescription *this)
CSurfaceDescription::CSurfaceDescription(void) {
    memset(&this->m_sSurfaceDescription, 0, sizeof(this->m_sSurfaceDescription));
    memset(&this->m_sSurfaceDescriptionOld, 0, sizeof(this->m_sSurfaceDescriptionOld));
    this->m_sSurfaceDescription.dwSize = 0x7C;
    this->m_sSurfaceDescriptionOld.dwSize = 108;
    this->m_sSurfaceDescription.ddpfPixelFormat.dwSize = 32;
    this->m_sSurfaceDescriptionOld.ddpfPixelFormat.dwSize = 32;
}
