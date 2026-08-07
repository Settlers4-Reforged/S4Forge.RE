#if FALSE
#include "SGfxRenderConfiguration.h"

// Definitions for class SGfxRenderConfiguration

// address=[0x148fbd0]
// Decompiled from void __thiscall SGfxRenderConfiguration::EnableFiltering(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::EnableFiltering(bool a2) {
  
  int v2; // edx

  if ( a2 )
  {
    v2 = this->m_uFlags | 8;
  }
  else
  {
    v2 = this->m_uFlags & 0xFFFFFFF7;
  }
  this->m_uFlags = v2;
}


// address=[0x148fc20]
// Decompiled from void __thiscall SGfxRenderConfiguration::EnableHQTextureSet(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::EnableHQTextureSet(bool a2) {
  
  int v2; // edx

  if ( a2 )
  {
    v2 = this->m_uFlags | 4;
  }
  else
  {
    v2 = this->m_uFlags & 0xFFFFFFFB;
  }
  this->m_uFlags = v2;
}


// address=[0x148fc70]
// Decompiled from void __thiscall SGfxRenderConfiguration::EnableHardwareLandscapeEngine(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::EnableHardwareLandscapeEngine(bool a2) {
  
  if ( a2 )
  {
    this->m_uFlags |= 1u;
  }
  else
  {
    BBSupportTracePrintF(1, "LE software rendering is no longer supported");
  }
}


// address=[0x148fcc0]
// Decompiled from void __thiscall SGfxRenderConfiguration::EnableHardwareObjectEngine(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::EnableHardwareObjectEngine(bool a2) {
  
  if ( a2 )
  {
    this->m_uFlags |= 2u;
  }
  else
  {
    BBSupportTracePrintF(1, "OE software rendering is no longer supported");
  }
}


// address=[0x148fd10]
// Decompiled from void __thiscall SGfxRenderConfiguration::ForceBlit(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::ForceBlit(bool a2) {
  
  int v2; // edx

  if ( a2 )
  {
    v2 = this->m_uFlags | 0x20;
  }
  else
  {
    v2 = this->m_uFlags & 0xFFFFFFDF;
  }
  this->m_uFlags = v2;
}


// address=[0x148fe40]
// Decompiled from bool __thiscall SGfxRenderConfiguration::IsFiltering(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsFiltering(void)const {
  
  return (this->m_uFlags & 8) != 0;
}


// address=[0x148fe80]
// Decompiled from bool __thiscall SGfxRenderConfiguration::IsHQTextureSet(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsHQTextureSet(void)const {
  
  return (this->m_uFlags & 4) != 0;
}


// address=[0x148fec0]
// Decompiled from char __thiscall SGfxRenderConfiguration::IsHardwareObjectEngine(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsHardwareObjectEngine(void)const {
  
  return 0;
}


// address=[0x148ffc0]
// Decompiled from void __thiscall SGfxRenderConfiguration::SetPureSoftwareMode(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::SetPureSoftwareMode(bool a2) {
  
  if ( a2 )
  {
    this->m_uFlags |= 0x10u;
  }
  else
  {
    BBSupportTracePrintF(1, "Pure software rendering is no longer supported");
  }
}


// address=[0x2f5f3d0]
// Decompiled from bool __thiscall SGfxRenderConfiguration::IsEditorMode(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsEditorMode(void)const {
  
  return (this->m_uFlags & 0x40) != 0;
}


// address=[0x2f5f410]
// Decompiled from char __thiscall SGfxRenderConfiguration::IsHardwareLandscapeEngine(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsHardwareLandscapeEngine(void)const {
  
  return 1;
}


// address=[0x2f69920]
// Decompiled from bool __thiscall SGfxRenderConfiguration::IsForceBlit(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsForceBlit(void)const {
  
  return (this->m_uFlags & 0x20) != 0;
}


#endif // Already implemented
