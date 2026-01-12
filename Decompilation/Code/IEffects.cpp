#include "IEffects.h"

// Definitions for class IEffects

// address=[0x144a370]
// Decompiled from CEffects *IEffects::CreateEffects()
static class IEffects * __cdecl IEffects::CreateEffects(void) {
  
  CEffects *C; // [esp+Ch] [ebp-10h]

  C = (CEffects *)operator new(0x44394u);
  if ( C )
    return CEffects::CEffects(C);
  else
    return 0;
}


// address=[0x144f280]
// Decompiled from IEffects *__thiscall IEffects::IEffects(IEffects *this)
 IEffects::IEffects(void) {
  
  IGfxEffects::IGfxEffects(this);
  IS4ChunkObject::IS4ChunkObject((IEffects *)((char *)this + 4));
  *(_DWORD *)this = IEffects::_vftable_;
  *((_DWORD *)this + 1) = &IEffects::`vftable';
  return this;
}


// address=[0x147e720]
// Decompiled from int __thiscall IEffects::DeleteMovingEffect(IEffects *this, unsigned int a2)
void  IEffects::DeleteMovingEffect(unsigned int) {
  
  return (*(int (__thiscall **)(IEffects *, unsigned int))(*(_DWORD *)this + 36))(this, a2);
}


