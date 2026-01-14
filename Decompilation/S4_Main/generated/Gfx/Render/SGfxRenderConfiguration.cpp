#include "all_headers.h"

// Definitions for class SGfxRenderConfiguration

// address=[0x148fbd0]
// Decompiled from SGfxRenderConfiguration *__thiscall SGfxRenderConfiguration::EnableFiltering(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::EnableFiltering(bool) {
  
  unsigned int v2; // edx
  SGfxRenderConfiguration *result; // eax

  if ( a2 )
    v2 = *((_DWORD *)this + 1) | 8;
  else
    v2 = *((_DWORD *)this + 1) & 0xFFFFFFF7;
  result = this;
  *((_DWORD *)this + 1) = v2;
  return result;
}


// address=[0x148fc20]
// Decompiled from SGfxRenderConfiguration *__thiscall SGfxRenderConfiguration::EnableHQTextureSet(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::EnableHQTextureSet(bool) {
  
  unsigned int v2; // edx
  SGfxRenderConfiguration *result; // eax

  if ( a2 )
    v2 = *((_DWORD *)this + 1) | 4;
  else
    v2 = *((_DWORD *)this + 1) & 0xFFFFFFFB;
  result = this;
  *((_DWORD *)this + 1) = v2;
  return result;
}


// address=[0x148fc70]
// Decompiled from SGfxRenderConfiguration *__thiscall SGfxRenderConfiguration::EnableHardwareLandscapeEngine(  SGfxRenderConfiguration *this,  bool a2)
void  SGfxRenderConfiguration::EnableHardwareLandscapeEngine(bool) {
  
  SGfxRenderConfiguration *result; // eax

  if ( !a2 )
    return (SGfxRenderConfiguration *)BBSupportTracePrintF(1, "LE software rendering is no longer supported");
  result = this;
  *((_DWORD *)this + 1) |= 1u;
  return result;
}


// address=[0x148fcc0]
// Decompiled from SGfxRenderConfiguration *__thiscall SGfxRenderConfiguration::EnableHardwareObjectEngine(  SGfxRenderConfiguration *this,  bool a2)
void  SGfxRenderConfiguration::EnableHardwareObjectEngine(bool) {
  
  SGfxRenderConfiguration *result; // eax

  if ( !a2 )
    return (SGfxRenderConfiguration *)BBSupportTracePrintF(1, "OE software rendering is no longer supported");
  result = this;
  *((_DWORD *)this + 1) |= 2u;
  return result;
}


// address=[0x148fd10]
// Decompiled from SGfxRenderConfiguration *__thiscall SGfxRenderConfiguration::ForceBlit(SGfxRenderConfiguration *this, bool a2)
void  SGfxRenderConfiguration::ForceBlit(bool) {
  
  unsigned int v2; // edx
  SGfxRenderConfiguration *result; // eax

  if ( a2 )
    v2 = *((_DWORD *)this + 1) | 0x20;
  else
    v2 = *((_DWORD *)this + 1) & 0xFFFFFFDF;
  result = this;
  *((_DWORD *)this + 1) = v2;
  return result;
}


// address=[0x148fe40]
// Decompiled from bool __thiscall SGfxRenderConfiguration::IsFiltering(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsFiltering(void)const {
  
  return (*((_DWORD *)this + 1) & 8) != 0;
}


// address=[0x148fe80]
// Decompiled from bool __thiscall SGfxRenderConfiguration::IsHQTextureSet(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsHQTextureSet(void)const {
  
  return (*((_DWORD *)this + 1) & 4) != 0;
}


// address=[0x148fec0]
// Decompiled from char __thiscall SGfxRenderConfiguration::IsHardwareObjectEngine(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsHardwareObjectEngine(void)const {
  
  return 0;
}


// address=[0x148ffc0]
// Decompiled from SGfxRenderConfiguration *__thiscall SGfxRenderConfiguration::SetPureSoftwareMode(  SGfxRenderConfiguration *this,  bool a2)
void  SGfxRenderConfiguration::SetPureSoftwareMode(bool) {
  
  SGfxRenderConfiguration *result; // eax

  if ( !a2 )
    return (SGfxRenderConfiguration *)BBSupportTracePrintF(1, "Pure software rendering is no longer supported");
  result = this;
  *((_DWORD *)this + 1) |= 0x10u;
  return result;
}


// address=[0x2f5f3d0]
// Decompiled from bool __thiscall SGfxRenderConfiguration::IsEditorMode(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsEditorMode(void)const {
  
  return (*((_DWORD *)this + 1) & 0x40) != 0;
}


// address=[0x2f5f410]
// Decompiled from char __thiscall SGfxRenderConfiguration::IsHardwareLandscapeEngine(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsHardwareLandscapeEngine(void)const {
  
  return 1;
}


// address=[0x2f69920]
// Decompiled from bool __thiscall SGfxRenderConfiguration::IsForceBlit(SGfxRenderConfiguration *this)
bool  SGfxRenderConfiguration::IsForceBlit(void)const {
  
  return (*((_DWORD *)this + 1) & 0x20) != 0;
}


