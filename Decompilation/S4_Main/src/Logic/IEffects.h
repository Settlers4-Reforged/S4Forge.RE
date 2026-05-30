#ifndef IEFFECTS_H
#define IEFFECTS_H

#include "defines.h"

#include "IGfxEffects.h"
#include "LoadSave/IS4ChunkObject.h"

class IEffects : public IGfxEffects, public IS4ChunkObject {
public:
    // address=[0x144a370]
    static class IEffects * __cdecl CreateEffects(void);

    // address=[0x144f280]
    IEffects(void);

    // address=[0x147e720]
    void DeleteMovingEffect(unsigned int a2);

    virtual unsigned int AddEffect(int a2, enum SIV_SOUNDS a3, int a4, int a5, unsigned int a6, int a7, bool a8) = 0;

    virtual unsigned int AddAngel(enum T_EFFECT_ANGEL a2, enum SIV_SOUNDS a3, int a4, int a5, int a6, unsigned int a7) = 0;

    virtual unsigned int AddMissile(enum T_EFFECT_MISSILE a2, int a3, int a4, unsigned int a5, int a6, int a7) = 0;

    virtual unsigned int AddSporeCloud(int a2, int a3, unsigned int a4) = 0;

    virtual unsigned int AddStagnantAnimal(enum SIV_ANIMALS a2, enum SIV_SOUNDS a3, int a4, int a5, int a6, unsigned int a7) = 0;

    virtual void DeleteEffect(unsigned int a2) = 0;

    virtual unsigned int CreateMovingEffect(int a2, int a3, int a4) = 0;

    virtual void ChangeMovingEffectType(unsigned int a2, int a3) = 0;

    virtual int NumberOfMovingEffects(int a2) = 0;

    virtual void GetMovingEffectInfo(unsigned int a2, int &a3, int &a4, int &a5, int &a6) = 0;

    virtual void SetMovingEffectSpeed(unsigned int a2, int a3) = 0;

    virtual unsigned int SetMovingEffectDestination(unsigned int a2, int a3, int a4, int a5) = 0;

    virtual int GetMovingEffectDirection(unsigned int a2) = 0;

    virtual void SetMovingEffectDirection(unsigned int a2, int a3) = 0;

    virtual int GetMovingEffectSoundId(unsigned int a2) = 0;

    virtual void SetMovingEffectSoundId(unsigned int a2, int a3) = 0;

    virtual unsigned int CreateAttachedEffect(int a2, unsigned int a3, int a4) = 0;

    virtual void SetAttachedEffectOffset(unsigned int a2, float a3, float a4) = 0;

    virtual void UpdateAttachedEffect(unsigned int a2) = 0;

    virtual bool WasAttachedEffectVisible(unsigned int a2) = 0;

    virtual void Execute(void) = 0;

    virtual void Release(void) = 0;
};


#endif // IEFFECTS_H
