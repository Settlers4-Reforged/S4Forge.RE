#if FALSE
#include "IEffects.h"

// Definitions for class IEffects

// address=[0x144a370]
// Decompiled from CEffects *IEffects::CreateEffects()
class IEffects * __cdecl IEffects::CreateEffects(void) {
  
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
  IS4ChunkObject::IS4ChunkObject(&this->IS4ChunkObject);
  this->IGfxEffects::__vftable = (IEffects_vtbl *)IEffects::_vftable_;
  this->IS4ChunkObject::__vftable = (IS4ChunkObject_vtbl *)&IEffects::`vftable';
  return this;
}


// address=[0x147e720]
// Decompiled from int __thiscall IEffects::DeleteMovingEffect(IEffects *this, unsigned int a2)
void  IEffects::DeleteMovingEffect(unsigned int a2) {
  
  return this->DeleteEffect(this, a2);
}


#endif // Already implemented
