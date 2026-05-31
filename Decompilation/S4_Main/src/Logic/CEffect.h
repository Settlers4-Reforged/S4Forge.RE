#ifndef CEFFECT_H
#define CEFFECT_H

#include "defines.h"
#include "Defines/Effects.h"
#include "Defines/Sound.h"
#include <cstddef>

#include "Defines/Animals.h"

class CEffect {
public:
    // address=[0x144a5e0]
    void InitEffect(int _uEffect, SIV_SOUNDS _tSoundId, int _iX, int _iY, unsigned int _uStartDelay, int _iDuration, bool _bTopEffect);

    // address=[0x144a700]
    void InitAngel(enum T_EFFECT_ANGEL _tAngel, enum SIV_SOUNDS _tSound, int _iX, int _iY, int a6, unsigned int _uDelay);

    // address=[0x144a880]
    void InitMissile(enum T_EFFECT_MISSILE a2, int _iAttackerXY, int _iTargetXY, unsigned int _iStartDelay, int a6, int a7);

    // address=[0x144ac00]
    void InitSporeCloud(int _iSrcXY, int _iDstXY, unsigned int _iNextTick);

    // address=[0x144aed0]
    void InitStagnantAnimal(SIV_ANIMALS _tAnimal, SIV_SOUNDS _tSound, int _iX, int _iY, int _iDir, unsigned int _uDelay);

    // address=[0x144afe0]
    void InitMovingEffect(int a2, int a3, int a4);

    // address=[0x144b0f0]
    unsigned int SetNewDestinationForMovingEffect(int a2, int a3, int a4);

    // address=[0x144b3e0]
    void UpdateAttachedEffect(CEffect const &_rParent);

    // address=[0x144b450]
    void InitAttachedEffect(int _iEffect, unsigned int a3, CEffect const &a4, int a5);

    // address=[0x144b530]
    void VisualizeEffect(struct SGfxObjectInfo &a2, int a3);

    // address=[0x144b5f0]
    void VisualizeAngel(struct SGfxObjectInfo &a2, int _iTimeIndex);

    // address=[0x144b6e0]
    void VisualizeArrow(struct SGfxObjectInfo &a2, int _iTimeIndex);

    // address=[0x144b800]
    void VisualizeCannonball(struct SGfxObjectInfo &_rInfo, int _iTimeIndex);

    // address=[0x144b950]
    void VisualizeSporeCloud(struct SGfxObjectInfo &_rInfo, int _iTimeIndex);

    // address=[0x144ba40]
    void VisualizeStagnantAnimal(struct SGfxObjectInfo &_rInfo, int _iTimeIndex);

    // address=[0x144bb10]
    void VisualizeMovingEffect(struct SGfxObjectInfo &_rInfo, int _iTimeIndex);

    // address=[0x144bc80]
    void VisualizeTopEffect(struct SGfxObjectInfo &_rInfo, int _iTimeIndex);

    // address=[0x144bd50]
    void VisualizeTopFireball(struct SGfxObjectInfo &_rInfo, int _iTimeIndex);

    // address=[0x144beb0]
    void VisualizeAttachedEffect(struct SGfxObjectInfo &a2, int _iTimeIndex);

    // address=[0x144f270]
    void VisualizeNOP(struct SGfxObjectInfo &a2, int a3);

    // address=[0x144f500]
    static void __cdecl GetEffectGfxInfo(struct SGfxObjectInfo &a1, int a2, unsigned int a3, unsigned int a4);

    // address=[0x144f530]
    static unsigned int __cdecl GetEffectNumberOfFrames(int a1);

    // address=[0x144f5c0]
    static void __cdecl GetWorldScreenCoordinates(int a1, int a2, int &a3, int &a4);

    // address=[0x144f620]
    static void __cdecl GetWorldScreenCoordinates(int a1, int a2, float &a3, float &a4);

    // address=[0x144f690]
    int IsOutOfDate(int a2) const;

    // address=[0x144f700]
    void SetVisualizeFunc(T_VISUALIZE_FUNC a2);

    // address=[0x144f770]
    int SquareRow(void) const;

    // address=[0x144f790]
    int TimeIndex(unsigned int a2) const;

    // address=[0x144f7b0]
    void Visualize(struct SGfxObjectInfo &a2, int a3);

    // address=[0x144f7e0]
    enum T_VISUALIZE_FUNC VisualizeFunc(void) const;

    struct SAngelEffectInfo {
        BYTE            m_iRace;
        unsigned __int8 m_iColor;
        BYTE            m_uFramesMax;
        unsigned __int8 m_iFrame;
        _DWORD          m_iNextTick;
        int             m_iDuration;
        _DWORD          m_iX;
        _DWORD          m_iY;
        float           m_fWorldX;
        float           m_fWorldY;
        float           m_fStepX;
        float           m_fStepY;
        float           m_fDstOffsetX;
        float           m_fDstOffsetY;
        int             m_iTimeIdxMax;
    };

    struct SAttachedEffectInfo {
        BYTE            m_iMaxDir;
        unsigned __int8 m_iDir;
        BYTE            m_uFramesMax;
        unsigned __int8 m_iFrame;
        _DWORD          m_iNextTick;
        int             m_iDuration;
        _DWORD          m_iX;
        _DWORD          m_iY;
        bool            m_bProcessed;
        float           m_fWorldY; // unused...
        float           m_fOffsetX;
        float           m_fOffsetY;
        float           m_fDstOffsetX; // unused
        float           m_fDstOffsetY; // unused
        unsigned int    m_iParentId;
    };

    struct SEffectInfo {
        BYTE            m_iMaxDir;
        unsigned __int8 m_iDir;
        BYTE            m_uFramesMax;
        unsigned __int8 m_iFrame;
        _DWORD          m_iNextTick;
        int             m_iDuration;
        _DWORD          m_iX;
        _DWORD          m_iY;
        float           m_fWorldX;
        float           m_fWorldY;
        float           m_fStepX;
        float           m_fStepY;
        float           m_fDstOffsetX;
        float           m_fDstOffsetY;
        int             m_iTimeIdxMax;
    };

    struct SMissileEffectInfo {
        BYTE            m_iMaxDir;
        unsigned __int8 m_iDir;
        BYTE            m_uFramesMax;
        unsigned __int8 m_iFrame;
        _DWORD          m_iNextTick;
        int             m_iDuration;
        _DWORD          m_iAttackerX;
        _DWORD          m_iAttackerY;
        float           m_fWorldX;
        float           m_fWorldY;
        float           m_fVelocityX;
        float           m_fVelocityY;
        float           m_fDstOffsetX;
        float           m_fDstOffsetY;
        float           m_fArcStep;
    };

    struct SMovingEffectInfo {
        BYTE            m_iMaxDir;
        unsigned __int8 m_iDir;
        BYTE            m_uFramesMax;
        unsigned __int8 m_iFrame;
        _DWORD          m_iNextTick;
        int             m_iDuration;
        int             m_iX;
        int             m_iY;
        int             m_iStartX;
        int             m_iStartY;
        int             m_iStartScreenX;
        int             m_iStartScreenY;
        int             m_iScreenX;
        int             m_iScreenY;
        int             m_uSpeed;
    };

    struct SSporeCloudEffectInfo {
        BYTE            m_iMaxDir;
        unsigned __int8 m_iDir;
        BYTE            m_uFramesMax;
        unsigned __int8 m_iFrame;
        _DWORD          m_iNextTick;
        int             m_iDuration;
        _DWORD          m_iSrcX;
        _DWORD          m_iSrcY;
        float           m_fSrcScreenX;
        float           m_fSrcScreenY;
        float           m_fScreenStepX;
        float           m_fScreenStepY;
        float           m_fTileStepX;
        float           m_fTileStepY;
        float           m_fArcStep;
    };


    static_assert(sizeof(CEffect::SAttachedEffectInfo) == sizeof(CEffect::SAngelEffectInfo), "Size must match between effect infos.");
    static_assert(sizeof(CEffect::SAttachedEffectInfo) == sizeof(CEffect::SMovingEffectInfo), "Size must match between effect infos.");
    static_assert(sizeof(CEffect::SAttachedEffectInfo) == sizeof(CEffect::SEffectInfo), "Size must match between effect infos.");
    static_assert(sizeof(CEffect::SAttachedEffectInfo) == sizeof(CEffect::SMissileEffectInfo), "Size must match between effect infos.");

    static_assert(sizeof(CEffect::SAttachedEffectInfo) == sizeof(CEffect::SSporeCloudEffectInfo), "Size must match between effect infos.");
    static_assert(sizeof(CEffect::SAttachedEffectInfo) == 0x30, "Size must match to original.");

    static_assert(offsetof(CEffect::SAngelEffectInfo, m_iColor) == offsetof(CEffect::SAttachedEffectInfo, m_iDir), "Offset of m_iDir must match between effect infos.");

    // Type information members
public:
    BYTE            m_uVisualizeFunc;
    unsigned __int8 m_uEffect;
    BYTE            m_tSoundId;
    unsigned __int8 m_uDelay;

    // NOTE(WizzardMaker): this should probably be changed as compilers behave differently here
    // Probably not quite what they did back then either
    union {
        SAngelEffectInfo      uAngel;
        SMovingEffectInfo     uMoving;
        SAttachedEffectInfo   uAttached;
        SMissileEffectInfo    uMissile;
        SEffectInfo           uEffect;
        SSporeCloudEffectInfo uSpore;

        // anonymous struct, to allow for direct access to fields
        struct {
            BYTE            m_iData0;
            BYTE            m_iData1;
            BYTE            m_uFramesMax;
            unsigned __int8 m_iFrame;
            unsigned int    m_iNextTick;
            int             m_iDuration;
            int             m_iX;
            int             m_iY;
            int             m_iData4;
            int             m_iData5;
            int             m_iData6;
            int             m_iData7;
            int             m_iData8;
            int             m_iData9;
            int             m_iData10;
        };
    };

    void (CEffect::*m_fpVisualize)(struct SGfxObjectInfo &, int);

    WORD             m_uPrevEffect;
    unsigned __int16 m_uNextEffect;
};

static_assert(offsetof(CEffect, uAngel.m_iTimeIdxMax) == offsetof(CEffect, m_iData10), "Offset of m_iData10 must match between effect infos.");

static_assert(sizeof(CEffect) == 0x3c, "Size of CEffect is not correct.");


#endif // CEFFECT_H
