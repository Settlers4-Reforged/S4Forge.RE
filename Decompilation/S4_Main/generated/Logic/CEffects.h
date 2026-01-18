#ifndef CEFFECTS_H
#define CEFFECTS_H

#include "defines.h"

class CEffects : public IEffects, public CBBObject {
public:
    // address=[0x144bfb0]
     CEffects(void);

    // address=[0x144c200]
    virtual  ~CEffects(void);

    // address=[0x144c280]
    virtual void  SetEffectsViewport(int a2, int a3, int a4, int a5, int a6);

    // address=[0x144c3a0]
    virtual struct SGfxObjectInfo *  FirstEffect(int a2);

    // address=[0x144c6e0]
    virtual struct SGfxObjectInfo *  NextEffect(void);

    // address=[0x144c880]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x144ca00]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x144cae0]
    virtual unsigned int  AddEffect(int a2, enum SIV_SOUNDS a3, int a4, int a5, unsigned int a6, int a7, bool a8);

    // address=[0x144cbb0]
    virtual unsigned int  AddAngel(enum T_EFFECT_ANGEL a2, enum SIV_SOUNDS a3, int a4, int a5, int a6, unsigned int a7);

    // address=[0x144cd20]
    virtual unsigned int  AddMissile(enum T_EFFECT_MISSILE a2, int a3, int a4, unsigned int a5, int a6, int a7);

    // address=[0x144ce50]
    virtual unsigned int  AddSporeCloud(int a2, int a3, unsigned int a4);

    // address=[0x144cf90]
    virtual unsigned int  AddStagnantAnimal(enum SIV_ANIMALS a2, enum SIV_SOUNDS a3, int a4, int a5, int a6, unsigned int a7);

    // address=[0x144d0f0]
    virtual void  DeleteEffect(unsigned int a2);

    // address=[0x144d180]
    virtual unsigned int  CreateMovingEffect(int a2, int a3, int a4);

    // address=[0x144d230]
    virtual void  ChangeMovingEffectType(unsigned int a2, int a3);

    // address=[0x144d330]
    virtual int  NumberOfMovingEffects(int a2);

    // address=[0x144d3a0]
    virtual void  GetMovingEffectInfo(unsigned int a2, int & a3, int & a4, int & a5, int & a6);

    // address=[0x144d4f0]
    virtual void  SetMovingEffectSpeed(unsigned int a2, int a3);

    // address=[0x144d560]
    virtual unsigned int  SetMovingEffectDestination(unsigned int a2, int a3, int a4, int a5);

    // address=[0x144d620]
    virtual int  GetMovingEffectDirection(unsigned int a2);

    // address=[0x144d680]
    virtual void  SetMovingEffectDirection(unsigned int a2, int a3);

    // address=[0x144d6f0]
    virtual int  GetMovingEffectSoundId(unsigned int a2);

    // address=[0x144d740]
    virtual void  SetMovingEffectSoundId(unsigned int a2, int a3);

    // address=[0x144d790]
    virtual unsigned int  CreateAttachedEffect(int a2, unsigned int a3, int a4);

    // address=[0x144d860]
    virtual void  SetAttachedEffectOffset(unsigned int a2, float a3, float a4);

    // address=[0x144d8c0]
    virtual void  UpdateAttachedEffect(unsigned int);

    // address=[0x144d950]
    virtual bool  WasAttachedEffectVisible(unsigned int);

    // address=[0x144d9b0]
    virtual void  Execute(void);

    // address=[0x144dbf0]
    virtual void  Release(void);

    // address=[0x144dc30]
    virtual unsigned int  DbgCheckData(int a2);

protected:
    // address=[0x144dc40]
    void  AddEffectToFreeList(unsigned int a2);

    // address=[0x144dda0]
    void  AddEffectToSquareList(unsigned int a2);

    // address=[0x144df80]
    void  RemoveEffectFromList(unsigned int a2);

    // address=[0x144e170]
    void  CleanUp(void);

    // address=[0x144f340]
    bool  CheckParentEffect(unsigned int);

    // address=[0x144f3b0]
    static void __cdecl ClipXOrY(int & a1);

    // address=[0x144f3f0]
    void  DecreaseMovingEffectCounter(int a2);

    // address=[0x144f4a0]
    unsigned short &  EffectSquareListHeadVW(int a2, int a3);

    // address=[0x144f4d0]
    unsigned int  FirstFreeEffectId(void);

    // address=[0x144f650]
    void  IncreaseMovingEffectCounter(int a2);

    // address=[0x144f6d0]
    void  MoveEffectFromSquareListToFreeList(unsigned int a2);

private:
    // address=[0x3f11f68]
    static struct SGfxObjectInfo m_sGfxInfo;

};


#endif // CEFFECTS_H
