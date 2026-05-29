#include "IEffects.h"

// Definitions for class IEffects

// address=[0x144a370]
// Decompiled from CEffects *IEffects::CreateEffects()
class IEffects * __cdecl IEffects::CreateEffects(void) {
    return new CEffects();
}


// address=[0x144f280]
// Decompiled from IEffects *__thiscall IEffects::IEffects(IEffects *this)
IEffects::IEffects(void) = default;


// address=[0x147e720]
// Decompiled from int __thiscall IEffects::DeleteMovingEffect(IEffects *this, unsigned int a2)
void IEffects::DeleteMovingEffect(unsigned int a2) {
    this->DeleteEffect(a2);
}


