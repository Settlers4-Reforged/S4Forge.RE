#ifndef IEFFECTS_H
#define IEFFECTS_H

class IEffects : public IGfxEffects, public IS4ChunkObject {
public:
    // address=[0x144a370]
    static class IEffects * __cdecl CreateEffects(void);

    // address=[0x144f280]
     IEffects(void);

    // address=[0x147e720]
    void  DeleteMovingEffect(unsigned int);

};


#endif // IEFFECTS_H
