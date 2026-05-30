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
    virtual void  SetEffectsViewport(int _iX0, int _iY0, int _iX1, int _iY1, int _iX2);

    // address=[0x144c3a0]
    virtual struct SGfxObjectInfo *  FirstEffect(int _iY);

    // address=[0x144c6e0]
    virtual struct SGfxObjectInfo *  NextEffect(void);

    // address=[0x144c880]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x144ca00]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x144cae0]
    virtual unsigned int  AddEffect(int _iEffect, enum SIV_SOUNDS _tSound, int iX, int iY, unsigned int _uStartDelay, int _iDuration, bool bTopEffect);

    // address=[0x144cbb0]
    virtual unsigned int  AddAngel(enum T_EFFECT_ANGEL _tAngel, enum SIV_SOUNDS tSoundId, int _iX, int _iY, int _iPlayerId, unsigned int _uStartDelay);

    // address=[0x144cd20]
    virtual unsigned int  AddMissile(enum T_EFFECT_MISSILE _tMissile, int _iAttackerXY, int _iTargetXY, unsigned int _uStartDelay, int _iTargetOffsetX, int _iTargetOffsetY);

    // address=[0x144ce50]
    virtual unsigned int  AddSporeCloud(int _iSrcXY, int _iDstXY, unsigned int _uStartDelay);

    // address=[0x144cf90]
    virtual unsigned int  AddStagnantAnimal(enum SIV_ANIMALS _tAnimalJob, enum SIV_SOUNDS a3, int _iX, int _iY, int iDir, unsigned int _uStartDelay);

    // address=[0x144d0f0]
    virtual void  DeleteEffect(unsigned int _uEffectId);

    // address=[0x144d180]
    virtual unsigned int  CreateMovingEffect(int _iEffect, int a3, int a4);

    // address=[0x144d230]
    virtual void  ChangeMovingEffectType(unsigned int _uEffectId, int _iEffect);

    // address=[0x144d330]
    virtual int  NumberOfMovingEffects(int _tEffect);

    // address=[0x144d3a0]
    virtual void  GetMovingEffectInfo(unsigned int _uEffectId, int & _rEffect, int & _rX, int & _rY, int & _rDir);

    // address=[0x144d4f0]
    virtual void  SetMovingEffectSpeed(unsigned int _uEffectId, int _iSpeed);

    // address=[0x144d560]
    virtual unsigned int  SetMovingEffectDestination(unsigned int _uEffectId, int a3, int a4, int a5);

    // address=[0x144d620]
    virtual int  GetMovingEffectDirection(unsigned int a2);

    // address=[0x144d680]
    virtual void  SetMovingEffectDirection(unsigned int _iEffectId, int _iDir);

    // address=[0x144d6f0]
    virtual int  GetMovingEffectSoundId(unsigned int _uEffectId);

    // address=[0x144d740]
    virtual void  SetMovingEffectSoundId(unsigned int _uEffectId, int _tSoundId);

    // address=[0x144d790]
    virtual unsigned int  CreateAttachedEffect(int a2, unsigned int a3, int a4);

    // address=[0x144d860]
    virtual void  SetAttachedEffectOffset(unsigned int a2, float a3, float a4);

    // address=[0x144d8c0]
    virtual void  UpdateAttachedEffect(unsigned int _uEffectId);

    // address=[0x144d950]
    virtual bool  WasAttachedEffectVisible(unsigned int a2);

    // address=[0x144d9b0]
    virtual void  Execute(void);

    // address=[0x144dbf0]
    virtual void  Release(void);

    // address=[0x144dc30]
    virtual unsigned int  DbgCheckData(int a2);

protected:
    // address=[0x144dc40]
    void  AddEffectToFreeList(unsigned int _uEffectId);

    // address=[0x144dda0]
    void  AddEffectToSquareList(unsigned int _uEffectId);

    // address=[0x144df80]
    void  RemoveEffectFromList(unsigned int _uEffectId);

    // address=[0x144e170]
    void  CleanUp(void);

    // address=[0x144f340]
    bool  CheckParentEffect(unsigned int a2);

    // address=[0x144f3b0]
    static void __cdecl ClipXOrY(int & a1);

    // address=[0x144f3f0]
    void  DecreaseMovingEffectCounter(int _iEffect);

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

    // Type information members
public:
    CEffects::SViewPortData m_sViewPortData;
    unsigned __int16[66][64] m_uEffectSquareListHeadVW;
    CEffect[4096] m_cEffects;
    int[4096] m_iMovingEffectSoundId;
    _DWORD m_iMaxXY;
    _DWORD m_iTickCounter;
    int[116] m_iMovingEffectCounters;

};


#endif // CEFFECTS_H
