#include "CEffect.h"

#include <cmath>

#include "CBB/CBBSupport.h"
#include "Main/CGameStateHandler.h"
#include "Main/Players/CPlayerManager.h"
#include "World/helper.h"

// Definitions for class CEffect

// address=[0x144a5e0]
// Decompiled from int __thiscall CEffect::InitEffect(  CEffect *this,  int _uEffect,  SIV_SOUNDS _tSoundId,  int _iX,  int _iY,  uint _uStartDelay,  int _iDuration,  bool _bTopEffect)
void CEffect::InitEffect(int _uEffect, SIV_SOUNDS _tSoundId, int _iX, int _iY, unsigned int _uStartDelay, int _iDuration, bool _bTopEffect) {
  // [esp+4h] [ebp-8h]

  this->uEffect.m_iX = _iX;
  this->uEffect.m_iY = _iY;
  this->m_uEffect = _uEffect;
  this->m_tSoundId = _tSoundId;
  unsigned int EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(_uEffect);
  this->uEffect.m_iMaxDir = 1;
  this->uEffect.m_uFramesMax = EffectNumberOfFrames;
  BB_ASSERT(m_uFramesMax != 0)

  if(_iDuration <= 0)
    _iDuration = EffectNumberOfFrames;
  this->uEffect.m_iDir = 0;
  this->uEffect.m_iFrame = 0;
  this->uEffect.m_iNextTick = _uStartDelay + g_pGame->GetTickCounter();
  this->uEffect.m_iDuration = _iDuration;
  BB_ASSERT(m_iDuration > 0)

  CEffect::GetWorldScreenCoordinates(_iX, _iY, this->uEffect.m_fWorldX, this->uEffect.m_fWorldY);
  if(_bTopEffect)
    CEffect::SetVisualizeFunc(VISUALIZE_FUNC_TOP_EFFECT);
  else
    CEffect::SetVisualizeFunc(VISUALIZE_FUNC_EFFECT);
}

// address=[0x036AC278]
int s_iAngelEffectJobIds[4] = {
  0,
  0x14D,
  0x14E,
  0x14F
};

// address=[0x144a700]
// Decompiled from void __thiscall CEffect::InitAngel(CEffect *this, int _tAngel, BYTE a3, int _iX, int _iY, int a6, unsigned int a7)
void CEffect::InitAngel(T_EFFECT_ANGEL _tAngel, SIV_SOUNDS _tSound, int _iX, int _iY, int a6, unsigned int _uDelay) {
  // al
  BYTE v8; // [esp+Ch] [ebp-10h]
  // [esp+10h] [ebp-Ch]
  // [esp+14h] [ebp-8h]

  BB_ASSERT(_tAngel != EFFECT_ANGEL_NONE)

  this->m_iX = _iX;
  this->m_iY = _iY;
  this->m_uEffect = _tAngel;
  this->m_tSoundId = _tSound;

  DWORD           iRace = CPlayerManager::Race(a6);
  unsigned __int8 iColor = CPlayerManager::Color(a6);

  this->uAngel.m_iRace = iRace;
  this->uAngel.m_iColor = iColor;
  unsigned int SettlerJobFrameCount = g_pGfxManager->GetSettlerJobFrameCount(iRace, s_iAngelEffectJobIds[_tAngel], 2u);
  if(SettlerJobFrameCount)
    v8 = SettlerJobFrameCount;
  else
    v8 = 1;
  this->uAngel.m_uFramesMax = v8;
  this->uAngel.m_iFrame = 0;
  BB_ASSERT(m_uFramesMax > 0)
  this->uAngel.m_iNextTick = _uDelay + g_pGame->GetTickCounter();
  this->uAngel.m_iDuration = SettlerJobFrameCount;
  BB_ASSERT(m_iDuration > 0)
  CEffect::GetWorldScreenCoordinates(_iX, _iY, this->uAngel.m_fWorldX, this->uAngel.m_fWorldY);
  CEffect::SetVisualizeFunc(VISUALIZE_FUNC_ANGEL);
}

// address=[0x0144A400]
int fast_atan2_quantized(float _fX, float _fY) {
  constexpr float DIAGONAL_SCALE = -0.66817862f;
  constexpr float THRESHOLD = 0.41421357f;

  // Rotated coordinate system used for octant classification
  float fRotatedY = DIAGONAL_SCALE * _fY + _fX;
  float fRotatedX = DIAGONAL_SCALE * _fX - _fY;

  int   iBaseSector;
  float fPrimaryDistance;
  float fSecondaryDistance;

  if(fRotatedX < 0.0f) {
    if(fRotatedY > 0.0f) {
      // Sector 12-15
      iBaseSector = 12;
      fPrimaryDistance = std::fabs(fRotatedX);
      fSecondaryDistance = fRotatedY;
    } else {
      // Sector 8-11
      iBaseSector = 8;
      fPrimaryDistance = std::fabs(fRotatedY);
      fSecondaryDistance = std::fabs(fRotatedX);
    }
  } else if(fRotatedY < 0.0f) {
    // Sector 4-7
    iBaseSector = 4;
    fPrimaryDistance = fRotatedX;
    fSecondaryDistance = std::fabs(fRotatedY);
  } else {
    // Sector 0-3
    iBaseSector = 0;
    fPrimaryDistance = fRotatedY;
    fSecondaryDistance = fRotatedX;
  }

  // Refine within the quadrant/octant
  if(fPrimaryDistance < fSecondaryDistance) {
    return iBaseSector
           + ((THRESHOLD * fSecondaryDistance) >= fPrimaryDistance)
           + 2;
  } else {
    return iBaseSector
           + (fSecondaryDistance >= (THRESHOLD * fPrimaryDistance));
  }
}

// address=[0x0144A3F0]
int default_angle(float, float) {
  return 0;
}

struct SMissileProperties {
  int   m_iMissileId;
  float m_iYOffset;
  float m_fArcHeightScale;
  float m_fTravelTimeScale;
  float m_fSize;

  int (*m_fpDirCalculator)(float, float);

  T_VISUALIZE_FUNC m_iVisualizeFunc;
};

// address=[0x036AC288]
SMissileProperties s_sMissileProperties[11] = {
  {1, -42.0, 0.1, 0.050000001, 50.0, fast_atan2_quantized, VISUALIZE_FUNC_ARROW},
  {0x54, -32.0, 0.050000001, 0.050000001, 30.0, fast_atan2_quantized, VISUALIZE_FUNC_ARROW},
  {9, -30.0, 0.15000001, 0.039999999, 90.0, default_angle, VISUALIZE_FUNC_TOP_FIREBALL},
  {5, -20.0, 0.125, 0.039999999, 90.0, default_angle, VISUALIZE_FUNC_TOP_FIREBALL},
  {0xa, -20.0, 0.125, 0.039999999, 90.0, default_angle, VISUALIZE_FUNC_TOP_FIREBALL},
  {0x13, 0.0, 0.0, 0.050000001, 0.0, default_angle, VISUALIZE_FUNC_ARROW},
  {0x17, 0.0, 0.0, 0.0, 0.0, default_angle, VISUALIZE_FUNC_EFFECT},
  {0x41, -42.0, 0.1, 0.050000001, 50.0, default_angle, VISUALIZE_FUNC_ARROW},
  {0x71, -42.0, 0.1, 0.050000001, 50.0, default_angle, VISUALIZE_FUNC_ARROW},
  {0x70, -42.0, 0.1, 0.050000001, 50.0, default_angle, VISUALIZE_FUNC_ARROW},
  {0x6b, -42.0, 0.1, 0.050000001, 50.0, fast_atan2_quantized, VISUALIZE_FUNC_TOP_FIREBALL},
};


// address=[0x144a880]
// Decompiled from void __thiscall CEffect::InitMissile(  CEffect *this,  int a2,  int _iAttackerXY,  int _iTargetXY,  int _iStartDelay,  int a6,  int a7)
void CEffect::InitMissile(T_EFFECT_MISSILE a2, int _iAttackerXY, int _iTargetXY, unsigned int _iStartDelay, int a6, int a7) {
  float fTargetY; // [esp+14h] [ebp-50h] BYREF
  float fTargetX; // [esp+18h] [ebp-4Ch] BYREF
  float fAttackerScreenY; // [esp+48h] [ebp-1Ch] BYREF
  float fAttackerScreenX; // [esp+4Ch] [ebp-18h] BYREF

  SMissileProperties *sProps = &s_sMissileProperties[a2];

  int iEffectId = sProps->m_iMissileId;
  int iAttackerX = Y16X16::UnpackXFast(_iAttackerXY);
  int iAttackerY = Y16X16::UnpackYFast(_iAttackerXY);

  this->uMissile.m_iAttackerX = iAttackerX;
  this->uMissile.m_iAttackerY = iAttackerY;
  this->m_uEffect = iEffectId;
  this->m_tSoundId = 0;
  int iTargetX = Y16X16::UnpackXFast(_iTargetXY);
  int iTargetY = Y16X16::UnpackYFast(_iTargetXY);
  CEffect::GetWorldScreenCoordinates(iAttackerX, iAttackerY, fAttackerScreenX, fAttackerScreenY);
  fAttackerScreenX = static_cast<float>(a6) + fAttackerScreenX;
  fAttackerScreenY = static_cast<float>(a7) + fAttackerScreenY;
  CEffect::GetWorldScreenCoordinates(iTargetX, iTargetY, fTargetX, fTargetY);
  float fRelativeX = fTargetX - fAttackerScreenX;
  float fRelativeY = fTargetY - fAttackerScreenY;
  float fDistance = sqrt(
    (fTargetX - fAttackerScreenX) * (fTargetX - fAttackerScreenX)
    + (fTargetY - fAttackerScreenY) * (fTargetY - fAttackerScreenY));
  int  TickCounter = g_pGame->GetTickCounter();
  BYTE EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(iEffectId);
  this->uMissile.m_uFramesMax = EffectNumberOfFrames;
  unsigned __int8 iCalcDir = sProps->m_fpDirCalculator(fRelativeX, fRelativeY);
  this->uMissile.m_iDir = iCalcDir;
  this->uMissile.m_iNextTick = _iStartDelay + TickCounter;
  if(!this->uMissile.m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 805, "m_uFramesMax > 0") == 1)
    __debugbreak();
  bool bHasHit = 1;
  if(fDistance > 0.0) {
    float fImpactDistance = fDistance - static_cast<float>(2.0 * sProps->m_fSize);
    if(fImpactDistance > 0.0) {
      float fDirectionScale = sProps->m_fSize * static_cast<float>(1.0 / fDistance);
      fAttackerScreenX = fDirectionScale * fRelativeX + fAttackerScreenX;
      fAttackerScreenY = fDirectionScale * fRelativeY + fAttackerScreenY;
      float fDirX = fRelativeX - static_cast<float>(2.0 * fDirectionScale) * fRelativeX;
      float fDirY = fRelativeY - static_cast<float>(2.0 * fDirectionScale) * fRelativeY;
      int   iTravelTime = static_cast<int>(sProps->m_fTravelTimeScale * fImpactDistance);
      if(iTravelTime < 1)
        iTravelTime = 1;
      this->uMissile.m_iDuration = iTravelTime + 1;
      float fArcAcceleration = sProps->m_fArcHeightScale * fImpactDistance;
      float fInvDuration = 1.0 / static_cast<float>(iTravelTime);
      float fArcVelocity = static_cast<float>(4.0 * fArcAcceleration) * fInvDuration;
      this->uMissile.m_fVelocityX = fDirX * fInvDuration;
      this->uMissile.m_fVelocityY = fDirY * fInvDuration - fArcVelocity;
      this->uMissile.m_fArcStep = fArcVelocity * fInvDuration;
      bHasHit = 0;
    }
  }
  if(bHasHit) {
    this->uMissile.m_iDuration = 1;
    this->uMissile.m_fVelocityX = 0.0;
    this->uMissile.m_fVelocityY = 0.0;
    this->uMissile.m_fArcStep = 0.0;
  }
  this->uMissile.m_fWorldX = fAttackerScreenX;
  this->uMissile.m_fWorldY = fAttackerScreenY + sProps->m_iYOffset;
  CEffect::SetVisualizeFunc(sProps->m_iVisualizeFunc);
}


// address=[0x144ac00]
// Decompiled from void __thiscall CEffect::InitSporeCloud(CEffect *this, int _iSrcXY, int _iDstXY, unsigned int _iNextTick)
void CEffect::InitSporeCloud(int _iSrcXY, int _iDstXY, unsigned int _iNextTick) {
  // eax
  // [esp+4h] [ebp-38h]
  // [esp+8h] [ebp-34h]
  // [esp+Ch] [ebp-30h]
  // [esp+10h] [ebp-2Ch]
  // [esp+14h] [ebp-28h]
  // [esp+18h] [ebp-24h]
  // [esp+1Ch] [ebp-20h]
  float fDstYScreen; // [esp+20h] [ebp-1Ch] BYREF
  float fDstXScreen; // [esp+24h] [ebp-18h] BYREF
  // [esp+28h] [ebp-14h]
  // [esp+2Ch] [ebp-10h]
  // [esp+30h] [ebp-Ch]
  // [esp+34h] [ebp-8h]

  this->m_uEffect = 21;
  this->m_tSoundId = 0;
  int iSrcX = Y16X16::UnpackXFast(_iSrcXY);
  int iSrcY = Y16X16::UnpackYFast(_iSrcXY);
  this->uSpore.m_iSrcX = iSrcX;
  this->uSpore.m_iSrcY = iSrcY;
  int iDstX = Y16X16::UnpackXFast(_iDstXY);
  int iDstY = Y16X16::UnpackYFast(_iDstXY);
  int iOffsetX = iDstX - iSrcX;
  int iOffsetY = iDstY - iSrcY;
  CEffect::GetWorldScreenCoordinates(iSrcX, iSrcY, this->uAngel.m_fWorldX, this->uAngel.m_fWorldY);
  this->uSpore.m_fSrcScreenX = this->uAngel.m_fWorldX + 0.0;
  this->uSpore.m_fSrcScreenY = this->uAngel.m_fWorldY + -18.0;
  CEffect::GetWorldScreenCoordinates(iDstX, iDstY, fDstXScreen, fDstYScreen);
  fDstXScreen = fDstXScreen + -48.0;
  fDstYScreen = fDstYScreen + -90.0;
  float fRelDstWorldX = fDstXScreen - this->uSpore.m_fSrcScreenX;
  float fRelDstWorldY = fDstYScreen - this->uSpore.m_fSrcScreenY;
  float fDistance = sqrt(fRelDstWorldX * fRelDstWorldX + fRelDstWorldY * fRelDstWorldY);
  int   iTimeIdxMax = static_cast<int>((float) (fDistance * 0.2));
  BB_ASSERT(iTimeIdxMax < 255)
  if(iTimeIdxMax <= 0) {
    iTimeIdxMax = 1;
    this->uSpore.m_fScreenStepX = 0.0;
    this->uSpore.m_fScreenStepY = 0.0;
    this->uSpore.m_fTileStepX = 0.0;
    this->uSpore.m_fTileStepY = 0.0;
  } else {
    float fInvDuration = 1.0 / static_cast<float>(iTimeIdxMax);
    this->uSpore.m_fScreenStepX = fRelDstWorldX * fInvDuration;
    this->uSpore.m_fScreenStepY = fRelDstWorldY * fInvDuration;
    this->uSpore.m_fTileStepX = static_cast<float>(iOffsetX) * fInvDuration;
    this->uSpore.m_fTileStepY = static_cast<float>(iOffsetY) * fInvDuration;
  }
  this->uSpore.m_iDir = 0;
  this->uSpore.m_iFrame = 0;
  this->uSpore.m_iDuration = iTimeIdxMax;
  this->uSpore.m_iMaxDir = 1;
  this->uSpore.m_uFramesMax = CEffect::GetEffectNumberOfFrames(EFFECT_SPORECLOUD_GROWNUP);
  int TickCounter = g_pGame->GetTickCounter();
  this->uSpore.m_iNextTick = _iNextTick + TickCounter;
  BB_ASSERT(m_iDuration > 0)
  BB_ASSERT(m_uFramesMax > 0)
  CEffect::SetVisualizeFunc(VISUALIZE_FUNC_SPORE_CLOUD);
}


// address=[0x144aed0]
// Decompiled from void __thiscall CEffect::InitStagnantAnimal(CEffect *this, int a2, char a3, int a4, int a5, char a6, int a7)
void CEffect::InitStagnantAnimal(SIV_ANIMALS _tAnimal, SIV_SOUNDS _tSound, int _iX, int _iY, int _iDir, unsigned int _uDelay) {
  // [esp+4h] [ebp-8h]

  this->uEffect.m_iX = _iX;
  this->uEffect.m_iY = _iY;
  this->m_uEffect = _tAnimal;
  this->m_tSoundId = _tSound;
  int AnimalFrameCount = g_pGfxManager->GetAnimalFrameCount(_tAnimal);
  this->uEffect.m_iMaxDir = 6;
  this->uEffect.m_uFramesMax = AnimalFrameCount;
  BB_ASSERT(m_uFramesMax != 0)
  this->uEffect.m_iDir = _iDir;
  this->uEffect.m_iFrame = 0;
  this->m_iNextTick = _uDelay + g_pGame->GetTickCounter();
  this->m_iDuration = AnimalFrameCount;
  BB_ASSERT(m_iDuration > 0)
  CEffect::GetWorldScreenCoordinates(_iX, _iY, this->uEffect.m_fWorldX, this->uEffect.m_fWorldY);
  CEffect::SetVisualizeFunc(VISUALIZE_FUNC_STAGNANT_ANIMAL);
}


// address=[0x144afe0]
// Decompiled from void __thiscall CEffect::InitMovingEffect(CEffect *this, int a2, int _iX, int _iY)
void CEffect::InitMovingEffect(int a2, int _iX, int _iY) {
  this->uMoving.m_iX = _iX;
  this->uMoving.m_iY = _iY;
  this->m_uEffect = a2;
  this->m_tSoundId = 0;
  this->uMoving.m_iMaxDir = 16;
  this->uMoving.m_uFramesMax = CEffect::GetEffectNumberOfFrames(a2);
  BB_ASSERT(m_uFramesMax != 0)
  this->uMoving.m_iDir = 0;
  this->uMoving.m_iFrame = 0;
  this->m_uDelay = 0;
  this->uMoving.m_iStartX = this->uMoving.m_iX;
  this->uMoving.m_iStartY = this->uMoving.m_iY;
  this->uMoving.m_iNextTick = g_pGame->GetTickCounter();
  this->uMoving.m_iDuration = 0x7FFFFFFF;
  CEffect::GetWorldScreenCoordinates(_iX, _iY, this->uMoving.m_iStartScreenX, this->uMoving.m_iStartScreenY);
  this->uMoving.m_iScreenX = this->uMoving.m_iStartScreenX;
  this->uMoving.m_iScreenY = this->uMoving.m_iStartScreenY;
  this->uMoving.m_uSpeed = 100;
  CEffect::SetVisualizeFunc(VISUALIZE_FUNC_MOVING_EFFECT);
}

unsigned int __fastcall fast_square_root(unsigned int a1) {
  int          v2; // [esp+0h] [ebp-14h]
  unsigned int v3; // [esp+4h] [ebp-10h]
  unsigned int v4; // [esp+8h] [ebp-Ch]
  unsigned int v5; // [esp+Ch] [ebp-8h]
  unsigned int v6; // [esp+10h] [ebp-4h]

  v4 = a1;
  v5 = 0;
  if(a1 < 0x10000)
    v2 = 0x4000;
  else
    v2 = 0x40000000;
  v6 = v2;
  do {
    v3 = v6 + v5;
    if(v4 >= v6 + v5) {
      v4 -= v3;
      v5 = v6 + v3;
    }
    v5 >>= 1;
    v6 >>= 2;
  } while(v6);
  return v5;
}

// address=[0x144b0f0]
// Decompiled from int __thiscall CEffect::SetNewDestinationForMovingEffect(CEffect *this, int _iDstX, int _iDstY, int a4)
unsigned int CEffect::SetNewDestinationForMovingEffect(int _iDstX, int _iDstY, int a4) {
  int iTicks; // [esp+14h] [ebp-24h]
  // [esp+18h] [ebp-20h]
  // [esp+1Ch] [ebp-1Ch]
  // [esp+20h] [ebp-18h]
  int uDelay; // [esp+24h] [ebp-14h]
  // [esp+28h] [ebp-10h]
  // [esp+2Ch] [ebp-Ch]

  unsigned int TickCounter = g_pGame->GetTickCounter();
  if(TickCounter < this->m_iNextTick)
    iTicks = 0;
  else
    iTicks = TickCounter - this->m_iNextTick;
  int m_uDelay = this->m_uDelay;
  this->m_iFrame = (iTicks + static_cast<unsigned int>(this->m_iFrame)) % this->m_uFramesMax;
  if(iTicks < m_uDelay) {
    if(iTicks > 0) {
      this->uMoving.m_iX += iTicks * (this->uMoving.m_iStartX - this->uMoving.m_iX) / m_uDelay;
      this->uMoving.m_iY += iTicks * (this->uMoving.m_iStartY - this->uMoving.m_iY) / m_uDelay;
      this->uMoving.m_iStartScreenX += iTicks * (this->uMoving.m_iScreenX - this->uMoving.m_iStartScreenX) / m_uDelay;
      this->uMoving.m_iStartScreenY += iTicks * (this->uMoving.m_iScreenY - this->uMoving.m_iStartScreenY) / m_uDelay;
    }
  } else {
    this->uMoving.m_iX = this->uMoving.m_iStartX;
    this->uMoving.m_iY = this->uMoving.m_iStartY;
    this->uMoving.m_iStartScreenX = this->uMoving.m_iScreenX;
    this->uMoving.m_iStartScreenY = this->uMoving.m_iScreenY;
  }
  if((a4 & 1) != 0) {
    this->uMoving.m_iStartX = this->uMoving.m_iX;
    this->uMoving.m_iStartY = this->uMoving.m_iY;
    this->uMoving.m_iScreenX = this->uMoving.m_iStartScreenX;
    this->uMoving.m_iScreenY = this->uMoving.m_iStartScreenY;
    this->m_uDelay = 1;
    uDelay = this->m_uFramesMax;
  } else {
    this->uMoving.m_iStartX = _iDstX;
    this->uMoving.m_iStartY = _iDstY;
    CEffect::GetWorldScreenCoordinates(
      this->uMoving.m_iStartX,
      this->uMoving.m_iStartY,
      this->uMoving.m_iScreenX,
      this->uMoving.m_iScreenY);
    int iDeltaX = this->uMoving.m_iScreenX - this->uMoving.m_iStartScreenX;
    int iDeltaY = this->uMoving.m_iScreenY - this->uMoving.m_iStartScreenY;
    int iNewTimeIdxMax = static_cast<int>(this->uMoving.m_uSpeed * fast_square_root(iDeltaY * iDeltaY + iDeltaX * iDeltaX)) >> 9;
    BB_ASSERT(iNewTimeIdxMax < 255)

    if(iNewTimeIdxMax > 0) {
      if(iNewTimeIdxMax > 255)
        iNewTimeIdxMax = 255;
    } else {
      iNewTimeIdxMax = 1;
    }
    this->uMoving.m_iMaxDir = 16;
    this->uMoving.m_iDir = fast_atan2_quantized(static_cast<float>(iDeltaX), static_cast<float>(iDeltaY));
    this->m_uDelay = iNewTimeIdxMax;
    uDelay = iNewTimeIdxMax;
  }
  this->uMoving.m_iNextTick = TickCounter;
  this->uMoving.m_iDuration = 0x7FFFFFFF;
  CEffect::SetVisualizeFunc(VISUALIZE_FUNC_MOVING_EFFECT);
  BB_ASSERT(uDelay > 0)
  return uDelay;
}


// address=[0x144b3e0]
// Decompiled from void __thiscall CEffect::UpdateAttachedEffect(CEffect *this, const struct CEffect *rParent)
void CEffect::UpdateAttachedEffect(CEffect const &_rParent) {
  if(this->uAttached.m_iMaxDir > 1u)
    this->uAttached.m_iDir = _rParent.uEffect.m_iDir % static_cast<__int16>(this->uAttached.m_iMaxDir);
  this->uAttached.m_iX = _rParent.uEffect.m_iX;
  this->uAttached.m_iY = _rParent.uEffect.m_iY;
  if(this->uAttached.m_iY < 1024)
    ++this->uAttached.m_iY;
}


// address=[0x144b450]
// Decompiled from void __thiscall CEffect::InitAttachedEffect(  CEffect *this,  unsigned int a2,  unsigned int _iParentId,  const struct CEffect *rParent,  char a5)
void CEffect::InitAttachedEffect(int _iEffect, unsigned int _uParentId, CEffect const &rParent, int a5) {
  BYTE iMaxDir; // [esp+0h] [ebp-Ch]
  // [esp+4h] [ebp-8h]

  this->m_uEffect = _iEffect;
  this->m_tSoundId = 0;
  this->m_uDelay = 0;
  if((a5 & 1) != 0)
    iMaxDir = rParent.uEffect.m_iMaxDir;
  else
    iMaxDir = 1;
  this->uAttached.m_iMaxDir = iMaxDir;
  this->uAttached.m_iDir = 0;

  unsigned int EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(_iEffect);
  if(!EffectNumberOfFrames)
    EffectNumberOfFrames = 1;
  this->uAttached.m_uFramesMax = EffectNumberOfFrames;
  this->uAttached.m_iFrame = 0;
  this->m_iNextTick = rParent.m_iNextTick;
  this->m_iDuration = rParent.m_iDuration;
  this->uAttached.m_fOffsetX = 0.0;
  this->uAttached.m_fOffsetY = 0.0;
  this->uAttached.m_bProcessed = 0;
  this->uAttached.m_iParentId = _uParentId;
  CEffect::SetVisualizeFunc(VISUALIZE_FUNC_ATTACHED_EFFECT);
  CEffect::UpdateAttachedEffect(rParent);
}


// address=[0x144b530]
// Decompiled from void __thiscall CEffect::VisualizeEffect(CEffect *this, struct SGfxObjectInfo *rInfo, int _iTimeIndex)
void CEffect::VisualizeEffect(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  BB_ASSERT(m_uFramesMax > 0)
  BB_ASSERT(_iTimeIndex >= 0)

  CEffect::GetEffectGfxInfo(_rInfo, this->m_uEffect, 0, _iTimeIndex % static_cast<unsigned int>(this->m_uFramesMax));
  _rInfo.m_uObjType = 0x80;
  _rInfo.m_iEffectScreenX = this->uEffect.m_fWorldX;
  _rInfo.m_iEffectScreenY = this->uEffect.m_fWorldY;
}


// address=[0x144b5f0]
// Decompiled from void __thiscall CEffect::VisualizeAngel(CEffect *this, struct SGfxObjectInfo *rInfo, int _iTimeIndex)
void CEffect::VisualizeAngel(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  // [esp+0h] [ebp-18h]

  BB_ASSERT(m_uFramesMax > 0)
  BB_ASSERT(_iTimeIndex >= 0)
  g_pGfxManager->GetSettlerGfxInfo(
    _rInfo,
    this->uAngel.m_iRace,
    s_iAngelEffectJobIds[this->m_uEffect],
    _iTimeIndex % static_cast<unsigned int>(this->uAngel.m_uFramesMax),
    2u);
  _rInfo.m_uObjType = 1;
  _rInfo.m_iColor = this->uAngel.m_iColor;
  _rInfo.m_iEffectScreenX = this->uAngel.m_fWorldX;
  _rInfo.m_iEffectScreenY = this->uAngel.m_fWorldY;
}


// address=[0x144b6e0]
// Decompiled from void __thiscall CEffect::VisualizeArrow(CEffect *this, struct SGfxObjectInfo *rInfo, int _iTimeIndex)
void CEffect::VisualizeArrow(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  BB_ASSERT(_iTimeIndex >= 0)
  BB_ASSERT((m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) ))

  CEffect::GetEffectGfxInfo(_rInfo, this->m_uEffect, this->uMissile.m_iDir, this->m_iFrame);
  _rInfo.m_uObjType = 64;
  _rInfo.m_iEffectScreenX = this->uMissile.m_fVelocityX * static_cast<float>(_iTimeIndex) + this->uMissile.m_fWorldX;
  _rInfo.m_iEffectScreenY = this->uMissile.m_fVelocityY * static_cast<float>(_iTimeIndex) + this->uMissile.m_fWorldY
                           + static_cast<float>(_iTimeIndex) * static_cast<float>(_iTimeIndex) * this->uMissile.m_fArcStep;
}


// address=[0x144b800]
// Decompiled from void __thiscall CEffect::VisualizeCannonball(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void CEffect::VisualizeCannonball(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  BB_ASSERT(_iTimeIndex >= 0)
  BB_ASSERT((m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) ))

  BB_ASSERT(m_uFramesMax > 0)

  CEffect::GetEffectGfxInfo(_rInfo, this->m_uEffect, this->uMissile.m_iDir, _iTimeIndex % static_cast<unsigned int>(this->m_uFramesMax));
  _rInfo.m_uObjType = 64;
  _rInfo.m_iEffectScreenX = this->uMissile.m_fVelocityX * static_cast<float>(_iTimeIndex) + this->uMissile.m_fWorldX;
  _rInfo.m_iEffectScreenY = this->uMissile.m_fVelocityY * static_cast<float>(_iTimeIndex) + this->uMissile.m_fWorldY
                        + static_cast<float>(_iTimeIndex) * static_cast<float>(_iTimeIndex) * this->uMissile.m_fArcStep;
}


// address=[0x144b950]
// Decompiled from void __thiscall CEffect::VisualizeSporeCloud(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void CEffect::VisualizeSporeCloud(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  BB_ASSERT(m_uFramesMax > 0)
  BB_ASSERT(_iTimeIndex >= 0)

  CEffect::GetEffectGfxInfo(_rInfo, this->m_uEffect, this->uSpore.m_iDir, _iTimeIndex % static_cast<unsigned int>(this->m_uFramesMax));
  _rInfo.m_uObjType = 0x80;
  _rInfo.m_iEffectScreenX = this->uSpore.m_fScreenStepX * static_cast<float>(_iTimeIndex) + this->uSpore.m_fSrcScreenX;
  _rInfo.m_iEffectScreenY = this->uSpore.m_fScreenStepY * static_cast<float>(_iTimeIndex) + this->uSpore.m_fSrcScreenY;
}


// address=[0x144ba40]
// Decompiled from void __thiscall CEffect::VisualizeStagnantAnimal(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void CEffect::VisualizeStagnantAnimal(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  BB_ASSERT(m_uFramesMax > 0)
  BB_ASSERT(_iTimeIndex >= 0)

  g_pGfxManager->GetAnimalGfxInfo(
    _rInfo,
    this->m_uEffect,
    this->uEffect.m_iDir,
    _iTimeIndex % static_cast<unsigned int>(this->m_uFramesMax));
  _rInfo.m_uObjType = 128;
  _rInfo.m_iEffectScreenX = this->uEffect.m_fWorldX;
  _rInfo.m_iEffectScreenY = this->uEffect.m_fWorldY;
}


// address=[0x144bb10]
// Decompiled from void __thiscall CEffect::VisualizeMovingEffect(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void CEffect::VisualizeMovingEffect(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  int iTimeIndex; // [esp+8h] [ebp-10h]
  // [esp+10h] [ebp-8h]

  BB_ASSERT(m_uFramesMax > 0)
  BB_ASSERT(_iTimeIndex >= 0)
  g_pGfxManager->GetEffectGfxInfo(
    _rInfo,
    this->m_uEffect,
    this->uMoving.m_iDir,
    (_iTimeIndex + static_cast<unsigned int>(this->uMoving.m_iFrame)) % this->uMoving.m_uFramesMax);

  _rInfo.m_uObjType = 128;
  int uDelay = this->m_uDelay;
  if(_iTimeIndex > uDelay)
    iTimeIndex = this->m_uDelay;
  else
    iTimeIndex = _iTimeIndex;
  if(this->m_uDelay && iTimeIndex > 0) {
    _rInfo.m_iEffectScreenX = static_cast<float>(iTimeIndex * (this->uMoving.m_iScreenX - this->uMoving.m_iStartScreenX) / uDelay
                                             + this->uMoving.m_iStartScreenX);
    _rInfo.m_iEffectScreenY = static_cast<float>(iTimeIndex * (this->uMoving.m_iScreenY - this->uMoving.m_iStartScreenY) / uDelay
                                             + this->uMoving.m_iStartScreenY);
  } else {
    _rInfo.m_iEffectScreenX = static_cast<float>(this->uMoving.m_iStartScreenX);
    _rInfo.m_iEffectScreenY = static_cast<float>(this->uMoving.m_iStartScreenY);
  }
  _rInfo.m_iZOrdering = -64;
}


// address=[0x144bc80]
// Decompiled from void __thiscall CEffect::VisualizeTopEffect(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void CEffect::VisualizeTopEffect(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  BB_ASSERT(m_uFramesMax > 0)
  BB_ASSERT(_iTimeIndex >= 0)
  CEffect::GetEffectGfxInfo(_rInfo, this->m_uEffect, 0, _iTimeIndex % static_cast<unsigned int>(this->m_uFramesMax));
  _rInfo.m_uObjType = 0x80;
  _rInfo.m_iEffectScreenX = this->uEffect.m_fWorldX;
  _rInfo.m_iEffectScreenY = this->uEffect.m_fWorldY;
  _rInfo.m_iZOrdering = -64;                       // Maybe related to Top?
}


// address=[0x144bd50]
// Decompiled from void __thiscall CEffect::VisualizeTopFireball(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void CEffect::VisualizeTopFireball(SGfxObjectInfo &_rInfo, int _iTimeIndex) {
  BB_ASSERT(m_uFramesMax > 0)
  BB_ASSERT(_iTimeIndex >= 0)
  BB_ASSERT((m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) ))

  CEffect::GetEffectGfxInfo(
    _rInfo,
    this->m_uEffect,
    this->uMissile.m_iDir,
    _iTimeIndex % static_cast<unsigned int>(this->uAngel.m_uFramesMax));
  _rInfo.m_uObjType = 64;
  _rInfo.m_iEffectScreenX = this->uMissile.m_fVelocityX * static_cast<float>(_iTimeIndex) + this->uMissile.m_fWorldX;
  _rInfo.m_iEffectScreenY = this->uMissile.m_fVelocityY * static_cast<float>(_iTimeIndex) + this->uMissile.m_fWorldY
                        + static_cast<float>(_iTimeIndex) * static_cast<float>(_iTimeIndex) * this->uMissile.m_fArcStep;
  _rInfo.m_iZOrdering = -64;
}


// address=[0x144beb0]
// Decompiled from void __thiscall CEffect::VisualizeAttachedEffect(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void CEffect::VisualizeAttachedEffect(SGfxObjectInfo &a2, int _iTimeIndex) {
  BB_ASSERT(m_uFramesMax > 0)
  BB_ASSERT(_iTimeIndex >= 0)

  unsigned int m_iEffect = this->m_uEffect;
  unsigned int iDir = this->uAttached.m_iDir;
  unsigned int iJob = _iTimeIndex % static_cast<unsigned int>(this->uAngel.m_uFramesMax);
  this->uAttached.m_bProcessed = 1;
  CEffect::GetEffectGfxInfo(a2, m_iEffect, iDir, iJob);
  a2.m_uObjType = 0x80;
  a2.m_iEffectScreenX = a2.m_iEffectScreenX + this->uAttached.m_fOffsetX;
  a2.m_iEffectScreenY = a2.m_iEffectScreenY + this->uAttached.m_fOffsetY;
  a2.m_iZOrdering = -64;
}


// address=[0x144f270]
// Decompiled from void __thiscall CEffect::VisualizeNOP(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void CEffect::VisualizeNOP(SGfxObjectInfo &, int) {
  ;
}


// address=[0x144f500]
// Decompiled from void __cdecl CEffect::GetEffectGfxInfo(struct SGfxObjectInfo *a1, unsigned int a2, unsigned int a3, unsigned int a4)
void __cdecl CEffect::GetEffectGfxInfo(SGfxObjectInfo &a1, int a2, unsigned int a3, unsigned int a4) {
  g_pGfxManager->GetEffectGfxInfo(a1, a2, a3, a4);
}


// address=[0x144f530]
// Decompiled from int __cdecl CEffect::GetEffectNumberOfFrames(unsigned int a1)
unsigned int __cdecl CEffect::GetEffectNumberOfFrames(int a1) {
  // [esp+4h] [ebp-4h]

  unsigned int uNumberOfFrames = g_pGfxManager->GetEffectFrameCount(a1);
  BB_ASSERT(uNumberOfFrames < 256)

  return (static_cast<_BYTE>(uNumberOfFrames) == 0) + static_cast<unsigned __int8>(uNumberOfFrames);
}


// address=[0x144f5c0]
// Decompiled from void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, int *a3, int *a4)
void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, int &a3, int &a4) {
  float v4 = 0.0; // [esp+0h] [ebp-8h] BYREF
  float v5 = 0.0; // [esp+4h] [ebp-4h] BYREF
  g_pGfxEngine->ConvertMapPositionToWorldScreenOffsets(a1, a2, &v5, &v4);
  a3 = static_cast<int>(v5);
  a4 = static_cast<int>(v4);
}


// address=[0x144f620]
// Decompiled from void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, float *a3, float *a4)
void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, float &a3, float &a4) {
  IGfxEngine::ConvertMapPositionToWorldScreenOffsets(g_pGfxEngine, a1, a2, a3, a4);
}


// address=[0x144f690]
// Decompiled from BOOL __thiscall CEffect::IsOutOfDate(CEffect *this, int a2)
int CEffect::IsOutOfDate(int a2) const {
  return a2 >= this->m_iDuration;
}

void (__thiscall CEffect::*s_fpVisualizeFunctions[12])(SGfxObjectInfo &, int) = {
  &CEffect::VisualizeNOP,
  &CEffect::VisualizeNOP,
  &CEffect::VisualizeEffect,
  &CEffect::VisualizeAngel,
  &CEffect::VisualizeArrow,
  &CEffect::VisualizeCannonball,
  &CEffect::VisualizeSporeCloud,
  &CEffect::VisualizeStagnantAnimal,
  &CEffect::VisualizeMovingEffect,
  &CEffect::VisualizeTopEffect,
  &CEffect::VisualizeTopFireball,
  &CEffect::VisualizeAttachedEffect,
};

/*
.data:03D894F0 s_fpVisualizeFunctions dd offset CEffect::VisualizeNOP(SGfxObjectInfo &,int)
.data:03D894F4                 dd offset CEffect::VisualizeNOP(SGfxObjectInfo &,int)
.data:03D894F8                 dd offset CEffect::VisualizeEffect(SGfxObjectInfo &,int)
.data:03D894FC                 dd offset CEffect::VisualizeAngel(SGfxObjectInfo &,int)
.data:03D89500                 dd offset CEffect::VisualizeArrow(SGfxObjectInfo &,int)
.data:03D89504                 dd offset CEffect::VisualizeCannonball(SGfxObjectInfo &,int)
.data:03D89508                 dd offset CEffect::VisualizeSporeCloud(SGfxObjectInfo &,int)
.data:03D8950C                 dd offset CEffect::VisualizeStagnantAnimal(SGfxObjectInfo &,int)
.data:03D89510                 dd offset CEffect::VisualizeMovingEffect(SGfxObjectInfo &,int)
.data:03D89514                 dd offset CEffect::VisualizeTopEffect(SGfxObjectInfo &,int)
.data:03D89518                 dd offset CEffect::VisualizeTopFireball(SGfxObjectInfo &,int)
.data:03D8951C                 dd offset CEffect::VisualizeAttachedEffect(SGfxObjectInfo &,int)
*/

// address=[0x144f700]
// Decompiled from void __thiscall CEffect::SetVisualizeFunc(CEffect *this, int a2)
void CEffect::SetVisualizeFunc(T_VISUALIZE_FUNC a2) {
  if(a2 >= VISUALIZE_FUNC_MAX) {
    if(BBSupportDbgReport(1, "Logic\\Effects.cpp", 633, "CEffect::VisualizeFunc(): Invalid visualize function!") == 1)
      __debugbreak();
    a2 = VISUALIZE_FUNC_NOP_2;
  }
  this->m_uVisualizeFunc = a2;
  this->m_fpVisualize = s_fpVisualizeFunctions[a2];
}


// address=[0x144f770]
// Decompiled from int __thiscall CEffect::SquareRow(CEffect *this)
int CEffect::SquareRow(void) const {
  return this->m_iY & 0xF;
}


// address=[0x144f790]
// Decompiled from int __thiscall CEffect::TimeIndex(CEffect *this, unsigned int a2)
int CEffect::TimeIndex(unsigned int a2) const {
  return a2 - this->m_iNextTick;
}


// address=[0x144f7b0]
// Decompiled from int __thiscall CEffect::Visualize(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void CEffect::Visualize(SGfxObjectInfo &a2, int a3) {
  return (this->*m_fpVisualize)(a2, a3);
}


// address=[0x144f7e0]
// Decompiled from int __thiscall CEffect::VisualizeFunc(CEffect *this)
T_VISUALIZE_FUNC CEffect::VisualizeFunc(void) const {
  return static_cast<T_VISUALIZE_FUNC>(this->m_uVisualizeFunc);
}

