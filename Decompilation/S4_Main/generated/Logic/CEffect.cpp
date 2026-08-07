#if FALSE
#include "CEffect.h"

// Definitions for class CEffect

// address=[0x144a5e0]
// Decompiled from int __thiscall CEffect::InitEffect(CEffect *this, int _uEffect, SIV_SOUNDS _tSoundId, int _iX, int _iY, uint _uStartDelay, int _iDuration, bool _bTopEffect)
void  CEffect::InitEffect(int _uEffect, enum SIV_SOUNDS _tSoundId, int _iX, int _iY, unsigned int _uStartDelay, int _iDuration, bool _bTopEffect) {
  
  int EffectNumberOfFrames; // [esp+4h] [ebp-8h]

  *(_QWORD *)&this->uEffect.m_iX = __PAIR64__(_iY, _iX);// XY
  this->m_iEffect = _uEffect;
  this->m_tSoundId = _tSoundId;
  EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(_uEffect);
  this->uEffect.m_iMaxDir = 1;
  this->uEffect.m_uFramesMax = EffectNumberOfFrames;
  if ( !this->uEffect.m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 689, "m_uFramesMax != 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iDuration <= 0 )
  {
    _iDuration = EffectNumberOfFrames;
  }
  this->uEffect.m_iDir = 0;
  this->uEffect.m_iFrame = 0;
  this->uEffect.m_iNextTick = _uStartDelay + CStateGame::GetTickCounter(g_pGame);
  this->uEffect.m_iDuration = _iDuration;
  if ( this->uEffect.m_iDuration <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 704, "m_iDuration > 0") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetWorldScreenCoordinates(_iX, _iY, &this->uEffect.m_fWorldX, &this->uEffect.m_fWorldY);
  if ( _bTopEffect )
  {
    return (int)CEffect::SetVisualizeFunc(this, VISUALIZE_FUNC_TOP_EFFECT);
  }
  else
  {
    return (int)CEffect::SetVisualizeFunc(this, VISUALIZE_FUNC_EFFECT);
  }
}


// address=[0x144a700]
// Decompiled from void __thiscall CEffect::InitAngel(CEffect *this, int _tAngel, BYTE a3, int _iX, int _iY, int a6, unsigned int a7)
void  CEffect::InitAngel(enum T_EFFECT_ANGEL _tAngel, enum SIV_SOUNDS a3, int _iX, int _iY, int a6, unsigned int a7) {
  
  unsigned __int8 iColor; // al
  BYTE v8; // [esp+Ch] [ebp-10h]
  DWORD iRace; // [esp+10h] [ebp-Ch]
  unsigned int SettlerJobFrameCount; // [esp+14h] [ebp-8h]

  if ( !_tAngel && BBSupportDbgReport(2, "Logic\\Effects.cpp", 725, "_tAngel != EFFECT_ANGEL_NONE") == 1 )
  {
    __debugbreak();
  }
  this->uAngel.m_iX = _iX;
  this->uAngel.m_iY = _iY;
  this->m_iEffect = _tAngel;
  this->m_tSoundId = a3;
  iRace = CPlayerManager::Race(a6);
  iColor = CPlayerManager::Color(a6);
  this->uAngel.m_iRace = iRace;
  this->uAngel.m_iColor = iColor;
  SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount(g_pGfxManager, iRace, s_iAngelEffectJobIds[_tAngel], 2u);
  if ( SettlerJobFrameCount )
  {
    v8 = SettlerJobFrameCount;
  }
  else
  {
    v8 = 1;
  }
  this->uAngel.m_uFramesMax = v8;
  this->uAngel.m_iFrame = 0;
  if ( !this->uAngel.m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 744, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  this->uAngel.m_iNextTick = a7 + CStateGame::GetTickCounter(g_pGame);
  this->uAngel.m_iDuration = SettlerJobFrameCount;
  if ( this->uAngel.m_iDuration <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 751, "m_iDuration > 0") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetWorldScreenCoordinates(_iX, _iY, &this->uAngel.m_fWorldX, &this->uAngel.m_fWorldY);
  CEffect::SetVisualizeFunc(this, 3);
}


// address=[0x144a880]
// Decompiled from void __thiscall CEffect::InitMissile(CEffect *this, int a2, int _iAttackerXY, int _iTargetXY, int _iStartDelay, int a6, int a7)
void  CEffect::InitMissile(enum T_EFFECT_MISSILE a2, int _iAttackerXY, int _iTargetXY, unsigned int _iStartDelay, int a6, int a7) {
  
  BYTE EffectNumberOfFrames; // al
  unsigned __int8 iCalcDir; // al
  float fArcAcceleration; // [esp+8h] [ebp-5Ch]
  int TickCounter; // [esp+10h] [ebp-54h]
  float fTargetY; // [esp+14h] [ebp-50h] BYREF
  float fTargetX; // [esp+18h] [ebp-4Ch] BYREF
  int iTargetX; // [esp+1Ch] [ebp-48h]
  int iTargetY; // [esp+20h] [ebp-44h]
  float fArcVelocity; // [esp+24h] [ebp-40h]
  int iEffectId; // [esp+28h] [ebp-3Ch]
  int iAttackerX; // [esp+2Ch] [ebp-38h]
  int iAttackerY; // [esp+30h] [ebp-34h]
  float fImpactDistance; // [esp+34h] [ebp-30h]
  float fDistance; // [esp+38h] [ebp-2Ch]
  float fInvDuration; // [esp+3Ch] [ebp-28h]
  int iTravelTime; // [esp+40h] [ebp-24h]
  float fDirectionScale; // [esp+44h] [ebp-20h]
  float fAttackerScreenY; // [esp+48h] [ebp-1Ch] BYREF
  float fAttackerScreenX; // [esp+4Ch] [ebp-18h] BYREF
  CEffect::SMissileProperties *sProps; // [esp+50h] [ebp-14h]
  float fRelativeY; // [esp+54h] [ebp-10h]
  float fDirY; // [esp+54h] [ebp-10h] SPLIT
  float fRelativeX; // [esp+58h] [ebp-Ch]
  float fDirX; // [esp+58h] [ebp-Ch] SPLIT
  bool bHasHit; // [esp+63h] [ebp-1h]

  sProps = &s_sMissileProperties[a2];
  iEffectId = sProps->m_iMissileId;
  iAttackerX = Y16X16::UnpackXFast(_iAttackerXY);
  iAttackerY = Y16X16::UnpackYFast(_iAttackerXY);
  this->uMissile.m_iAttackerX = iAttackerX;
  this->uMissile.m_iAttackerY = iAttackerY;
  this->m_iEffect = iEffectId;
  this->m_tSoundId = 0;
  iTargetX = Y16X16::UnpackXFast(_iTargetXY);
  iTargetY = Y16X16::UnpackYFast(_iTargetXY);
  CEffect::GetWorldScreenCoordinates(iAttackerX, iAttackerY, &fAttackerScreenX, &fAttackerScreenY);
  fAttackerScreenX = (float)a6 + fAttackerScreenX;
  fAttackerScreenY = (float)a7 + fAttackerScreenY;
  CEffect::GetWorldScreenCoordinates(iTargetX, iTargetY, &fTargetX, &fTargetY);
  fRelativeX = fTargetX - fAttackerScreenX;
  fRelativeY = fTargetY - fAttackerScreenY;
  fDistance = sqrt((float)((float)(fTargetX - fAttackerScreenX) * (float)(fTargetX - fAttackerScreenX)) + (float)((float)(fTargetY - fAttackerScreenY) * (float)(fTargetY - fAttackerScreenY)));
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(iEffectId);
  this->uMissile.m_uFramesMax = EffectNumberOfFrames;
  iCalcDir = sProps->m_fpDirCalculator(COERCE_FLOAT(LODWORD(fRelativeX)), COERCE_FLOAT(LODWORD(fRelativeY)));
  this->uMissile.m_iDir = iCalcDir;
  this->uMissile.m_iNextTick = _iStartDelay + TickCounter;
  if ( !this->uMissile.m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 805, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  bHasHit = 1;
  if ( fDistance > 0.0 )
  {
    fImpactDistance = fDistance - (float)(2.0 * sProps->m_fSize);
    if ( fImpactDistance > 0.0 )
    {
      fDirectionScale = sProps->m_fSize * (float)(1.0 / fDistance);
      fAttackerScreenX = (float)(fDirectionScale * fRelativeX) + fAttackerScreenX;
      fAttackerScreenY = (float)(fDirectionScale * fRelativeY) + fAttackerScreenY;
      fDirX = fRelativeX - (float)((float)(2.0 * fDirectionScale) * fRelativeX);
      fDirY = fRelativeY - (float)((float)(2.0 * fDirectionScale) * fRelativeY);
      iTravelTime = (int)(float)(sProps->m_fTravelTimeScale * fImpactDistance);
      if ( iTravelTime < 1 )
      {
        iTravelTime = 1;
      }
      this->uMissile.m_iDuration = iTravelTime + 1;
      fArcAcceleration = sProps->m_fArcHeightScale * fImpactDistance;
      fInvDuration = 1.0 / (float)iTravelTime;
      fArcVelocity = (float)(4.0 * fArcAcceleration) * fInvDuration;
      this->uMissile.m_fVelocityX = fDirX * fInvDuration;
      this->uMissile.m_fVelocityY = (float)(fDirY * fInvDuration) - fArcVelocity;
      this->uMissile.m_fArcStep = fArcVelocity * fInvDuration;
      bHasHit = 0;
    }
  }
  if ( bHasHit )
  {
    this->uMissile.m_iDuration = 1;
    this->uMissile.m_fVelocityX = 0.0;
    this->uMissile.m_fVelocityY = 0.0;
    this->uMissile.m_fArcStep = 0.0;
  }
  this->uMissile.m_fWorldX = fAttackerScreenX;
  this->uMissile.m_fWorldY = fAttackerScreenY + sProps->m_iYOffset;
  CEffect::SetVisualizeFunc(this, (T_S4_VISUALIZE_FUNC)sProps->m_iVisualizeFunc);
}


// address=[0x144ac00]
// Decompiled from void __thiscall CEffect::InitSporeCloud(CEffect *this, int _iSrcXY, int _iDstXY, unsigned int _iNextTick)
void  CEffect::InitSporeCloud(int _iSrcXY, int _iDstXY, unsigned int _iNextTick) {
  
  int TickCounter; // eax
  int iOffsetY; // [esp+4h] [ebp-38h]
  int iOffsetX; // [esp+8h] [ebp-34h]
  float fDistance; // [esp+Ch] [ebp-30h]
  int iDstX; // [esp+10h] [ebp-2Ch]
  int iDstY; // [esp+14h] [ebp-28h]
  float fRelDstWorldY; // [esp+18h] [ebp-24h]
  float fRelDstWorldX; // [esp+1Ch] [ebp-20h]
  float fDstYScreen; // [esp+20h] [ebp-1Ch] BYREF
  float fDstXScreen; // [esp+24h] [ebp-18h] BYREF
  int iSrcX; // [esp+28h] [ebp-14h]
  int iSrcY; // [esp+2Ch] [ebp-10h]
  float fInvDuration; // [esp+30h] [ebp-Ch]
  int iTimeIdxMax; // [esp+34h] [ebp-8h]

  this->m_iEffect = 21;
  this->m_tSoundId = 0;
  iSrcX = Y16X16::UnpackXFast(_iSrcXY);
  iSrcY = Y16X16::UnpackYFast(_iSrcXY);
  this->uSpore.m_iSrcX = iSrcX;
  this->uSpore.m_iSrcY = iSrcY;
  iDstX = Y16X16::UnpackXFast(_iDstXY);
  iDstY = Y16X16::UnpackYFast(_iDstXY);
  iOffsetX = iDstX - iSrcX;
  iOffsetY = iDstY - iSrcY;
  CEffect::GetWorldScreenCoordinates(iSrcX, iSrcY, &this->uAngel.m_fWorldX, &this->uAngel.m_fWorldY);
  this->uSpore.m_fSrcScreenX = this->uAngel.m_fWorldX + 0.0;
  this->uSpore.m_fSrcScreenY = this->uAngel.m_fWorldY + -18.0;
  CEffect::GetWorldScreenCoordinates(iDstX, iDstY, &fDstXScreen, &fDstYScreen);
  fDstXScreen = fDstXScreen + -48.0;
  fDstYScreen = fDstYScreen + -90.0;
  fRelDstWorldX = fDstXScreen - this->uSpore.m_fSrcScreenX;
  fRelDstWorldY = fDstYScreen - this->uSpore.m_fSrcScreenY;
  fDistance = sqrt((float)(fRelDstWorldX * fRelDstWorldX) + (float)(fRelDstWorldY * fRelDstWorldY));
  iTimeIdxMax = (int)(float)(fDistance * 0.2);
  if ( iTimeIdxMax >= 255 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 901, "iTimeIdxMax < 255") == 1 )
  {
    __debugbreak();
  }
  if ( iTimeIdxMax <= 0 )
  {
    iTimeIdxMax = 1;
    this->uSpore.m_fScreenStepX = 0.0;
    this->uSpore.m_fScreenStepY = 0.0;
    this->uSpore.m_fTileStepX = 0.0;
    this->uSpore.m_fTileStepY = 0.0;
  }
  else
  {
    fInvDuration = 1.0 / (float)iTimeIdxMax;
    this->uSpore.m_fScreenStepX = fRelDstWorldX * fInvDuration;
    this->uSpore.m_fScreenStepY = fRelDstWorldY * fInvDuration;
    this->uSpore.m_fTileStepX = (float)iOffsetX * fInvDuration;
    this->uSpore.m_fTileStepY = (float)iOffsetY * fInvDuration;
  }
  this->uSpore.m_iDir = 0;
  this->uSpore.m_iFrame = 0;
  this->uSpore.m_iDuration = iTimeIdxMax;
  this->uSpore.m_iMaxDir = 1;
  this->uSpore.m_uFramesMax = CEffect::GetEffectNumberOfFrames(EFFECT_SPORECLOUD_GROWNUP);
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  this->uSpore.m_iNextTick = _iNextTick + TickCounter;
  if ( this->m_iDuration <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 932, "m_iDuration > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 933, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  CEffect::SetVisualizeFunc(this, VISUALIZE_FUNC_SPORE_CLOUD);
}


// address=[0x144aed0]
// Decompiled from void __thiscall CEffect::InitStagnantAnimal(CEffect *this, int a2, char a3, int a4, int a5, char a6, int a7)
void  CEffect::InitStagnantAnimal(enum SIV_ANIMALS a2, enum SIV_SOUNDS a3, int a4, int a5, int a6, unsigned int a7) {
  
  int AnimalFrameCount; // [esp+4h] [ebp-8h]

  *(_QWORD *)&this->uEffect.m_iX = __PAIR64__(a5, a4);
  this->m_iEffect = a2;
  this->m_tSoundId = a3;
  AnimalFrameCount = CGfxManager::GetAnimalFrameCount(g_pGfxManager, a2);
  this->uEffect.m_iMaxDir = 6;
  this->uEffect.m_uFramesMax = AnimalFrameCount;
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 956, "m_uFramesMax != 0") == 1 )
  {
    __debugbreak();
  }
  this->uEffect.m_iDir = a6;
  this->uEffect.m_iFrame = 0;
  this->m_iNextTick = a7 + CStateGame::GetTickCounter(g_pGame);
  this->m_iDuration = AnimalFrameCount;
  if ( this->m_iDuration <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 966, "m_iDuration > 0") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetWorldScreenCoordinates(a4, a5, &this->uEffect.m_fWorldX, &this->uEffect.m_fWorldY);
  CEffect::SetVisualizeFunc(this, VISUALIZE_FUNC_STAGNANT_ANIMAL);
}


// address=[0x144afe0]
// Decompiled from void __thiscall CEffect::InitMovingEffect(CEffect *this, int a2, int _iX, int _iY)
void  CEffect::InitMovingEffect(int a2, int _iX, int _iY) {
  
  *(_QWORD *)&this->uMoving.m_iX = __PAIR64__(_iY, _iX);
  this->m_iEffect = a2;
  this->m_tSoundId = 0;
  this->uMoving.m_iMaxDir = 16;
  this->uMoving.m_uFramesMax = CEffect::GetEffectNumberOfFrames(a2);
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 989, "m_uFramesMax != 0") == 1 )
  {
    __debugbreak();
  }
  this->uMoving.m_iDir = 0;
  this->uMoving.m_iFrame = 0;
  this->m_uDelay = 0;
  this->uMoving.m_iStartX = this->uMoving.m_iX;
  this->uMoving.m_iStartY = this->uMoving.m_iY;
  this->uMoving.m_iNextTick = CStateGame::GetTickCounter(g_pGame);
  this->uMoving.m_iDuration = 0x7FFFFFFF;
  CEffect::GetWorldScreenCoordinates(_iX, _iY, &this->uMoving.m_iStartScreenX, &this->uMoving.m_iStartScreenY);
  this->uMoving.m_iScreenX = this->uMoving.m_iStartScreenX;
  this->uMoving.m_iScreenY = this->uMoving.m_iStartScreenY;
  this->uMoving.m_uSpeed = 100;
  CEffect::SetVisualizeFunc(this, VISUALIZE_FUNC_MOVING_EFFECT);
}


// address=[0x144b0f0]
// Decompiled from int __thiscall CEffect::SetNewDestinationForMovingEffect(CEffect *this, int _iDstX, int _iDstY, int a4)
unsigned int  CEffect::SetNewDestinationForMovingEffect(int _iDstX, int _iDstY, int a4) {
  
  int iTicks; // [esp+14h] [ebp-24h]
  unsigned int TickCounter; // [esp+18h] [ebp-20h]
  int iDeltaX; // [esp+1Ch] [ebp-1Ch]
  int iDeltaY; // [esp+20h] [ebp-18h]
  int uDelay; // [esp+24h] [ebp-14h]
  int m_uDelay; // [esp+28h] [ebp-10h]
  int iNewTimeIdxMax; // [esp+2Ch] [ebp-Ch]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( TickCounter < this->m_iNextTick )
  {
    iTicks = 0;
  }
  else
  {
    iTicks = TickCounter - this->m_iNextTick;
  }
  m_uDelay = this->m_uDelay;
  this->m_iFrame = (iTicks + (unsigned int)this->m_iFrame) % this->m_uFramesMax;
  if ( iTicks < m_uDelay )
  {
    if ( iTicks > 0 )
    {
      this->uMoving.m_iX += iTicks * (this->uMoving.m_iStartX - this->uMoving.m_iX) / m_uDelay;
      this->uMoving.m_iY += iTicks * (this->uMoving.m_iStartY - this->uMoving.m_iY) / m_uDelay;
      this->uMoving.m_iStartScreenX += iTicks * (this->uMoving.m_iScreenX - this->uMoving.m_iStartScreenX) / m_uDelay;
      this->uMoving.m_iStartScreenY += iTicks * (this->uMoving.m_iScreenY - this->uMoving.m_iStartScreenY) / m_uDelay;
    }
  }
  else
  {
    this->uMoving.m_iX = this->uMoving.m_iStartX;
    this->uMoving.m_iY = this->uMoving.m_iStartY;
    this->uMoving.m_iStartScreenX = this->uMoving.m_iScreenX;
    this->uMoving.m_iStartScreenY = this->uMoving.m_iScreenY;
  }
  if ( (a4 & 1) != 0 )
  {
    this->uMoving.m_iStartX = this->uMoving.m_iX;
    this->uMoving.m_iStartY = this->uMoving.m_iY;
    this->uMoving.m_iScreenX = this->uMoving.m_iStartScreenX;
    this->uMoving.m_iScreenY = this->uMoving.m_iStartScreenY;
    this->m_uDelay = 1;
    uDelay = this->m_uFramesMax;
  }
  else
  {
    this->uMoving.m_iStartX = _iDstX;
    this->uMoving.m_iStartY = _iDstY;
    CEffect::GetWorldScreenCoordinates(this->uMoving.m_iStartX, this->uMoving.m_iStartY, &this->uMoving.m_iScreenX, &this->uMoving.m_iScreenY);
    iDeltaX = this->uMoving.m_iScreenX - this->uMoving.m_iStartScreenX;
    iDeltaY = this->uMoving.m_iScreenY - this->uMoving.m_iStartScreenY;
    iNewTimeIdxMax = (int)(this->uMoving.m_uSpeed * fast_square_root(iDeltaY * iDeltaY + iDeltaX * iDeltaX)) >> 9;
    if ( iNewTimeIdxMax >= 255 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1072, "iNewTimeIdxMax < 255") == 1 )
    {
      __debugbreak();
    }
    if ( iNewTimeIdxMax > 0 )
    {
      if ( iNewTimeIdxMax > 255 )
      {
        iNewTimeIdxMax = 255;
      }
    }
    else
    {
      iNewTimeIdxMax = 1;
    }
    this->uMoving.m_iMaxDir = 16;
    this->uMoving.m_iDir = fast_atan2_quantized((float)iDeltaX, (float)iDeltaY);
    this->m_uDelay = iNewTimeIdxMax;
    uDelay = iNewTimeIdxMax;
  }
  this->uMoving.m_iNextTick = TickCounter;
  this->uMoving.m_iDuration = 0x7FFFFFFF;
  CEffect::SetVisualizeFunc(this, 8);
  if ( !uDelay && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1110, "uDelay > 0") == 1 )
  {
    __debugbreak();
  }
  return uDelay;
}


// address=[0x144b3e0]
// Decompiled from void __thiscall CEffect::UpdateAttachedEffect(CEffect *this, const struct CEffect *rParent)
void  CEffect::UpdateAttachedEffect(class CEffect const & rParent) {
  
  if ( this->uAttached.m_iMaxDir > 1u )
  {
    this->uAttached.m_iDir = rParent->uEffect.m_iDir % (__int16)this->uAttached.m_iMaxDir;
  }
  *(_QWORD *)&this->uAttached.m_iX = *(_QWORD *)&rParent->uEffect.m_iX;
  if ( (int)this->uAttached.m_iY < 1024 )
  {
    ++this->uAttached.m_iY;
  }
}


// address=[0x144b450]
// Decompiled from void __thiscall CEffect::InitAttachedEffect(CEffect *this, unsigned int a2, unsigned int _iParentId, const struct CEffect *rParent, char a5)
void  CEffect::InitAttachedEffect(int a2, unsigned int _iParentId, class CEffect const & rParent, int a5) {
  
  BYTE iMaxDir; // [esp+0h] [ebp-Ch]
  int EffectNumberOfFrames; // [esp+4h] [ebp-8h]

  this->m_iEffect = a2;
  this->m_tSoundId = 0;
  this->m_uDelay = 0;
  if ( (a5 & 1) != 0 )
  {
    iMaxDir = rParent->uEffect.m_iMaxDir;
  }
  else
  {
    iMaxDir = 1;
  }
  *(_WORD *)&this->uAttached.m_iMaxDir = iMaxDir;// Also resets dir to 0 (f*n decompiler getting smart on me here)
  EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(a2);
  if ( !EffectNumberOfFrames )
  {
    LOBYTE(EffectNumberOfFrames) = 1;
  }
  this->uAttached.m_uFramesMax = EffectNumberOfFrames;
  this->uAttached.m_iFrame = 0;
  *(_QWORD *)&this->m_iNextTick = *(_QWORD *)&rParent->m_iNextTick;// Also copies m_iDuration
  this->uAttached.m_fOffsetX = 0.0;
  this->uAttached.m_fOffsetY = 0.0;
  this->uAttached.m_bProcessed = 0;
  this->uAttached.m_iParentId = _iParentId;
  CEffect::SetVisualizeFunc(this, VISUALIZE_FUNC_ATTACHED_EFFECT);
  CEffect::UpdateAttachedEffect(this, rParent);
}


// address=[0x144b530]
// Decompiled from void __thiscall CEffect::VisualizeEffect(CEffect *this, struct SGfxObjectInfo *rInfo, int _iTimeIndex)
void  CEffect::VisualizeEffect(struct SGfxObjectInfo & rInfo, int _iTimeIndex) {
  
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1122, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1123, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetEffectGfxInfo(rInfo, this->m_iEffect, 0, _iTimeIndex % (unsigned int)this->m_uFramesMax);
  rInfo->m_uObjType = 0x80;
  rInfo->m_iEffectScreenX = this->uEffect.m_fWorldX;
  rInfo->m_iEffectScreenY = this->uEffect.m_fWorldY;
}


// address=[0x144b5f0]
// Decompiled from void __thiscall CEffect::VisualizeAngel(CEffect *this, struct SGfxObjectInfo *rInfo, int _iTimeIndex)
void  CEffect::VisualizeAngel(struct SGfxObjectInfo & rInfo, int _iTimeIndex) {
  
  BYTE iColor; // [esp+0h] [ebp-18h]

  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1272, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1273, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  iColor = this->uAngel.m_iColor;
  CGfxManager::GetSettlerGfxInfo(g_pGfxManager, rInfo, this->uAngel.m_iRace, s_iAngelEffectJobIds[this->m_iEffect], _iTimeIndex % (unsigned int)this->m_uFramesMax, 2u);
  rInfo->m_uObjType = 1;
  rInfo->m_iColor = iColor;
  rInfo->m_iEffectScreenX = this->uAngel.m_fWorldX;
  rInfo->m_iEffectScreenY = this->uAngel.m_fWorldY;
}


// address=[0x144b6e0]
// Decompiled from void __thiscall CEffect::VisualizeArrow(CEffect *this, struct SGfxObjectInfo *rInfo, int _iTimeIndex)
void  CEffect::VisualizeArrow(struct SGfxObjectInfo & rInfo, int _iTimeIndex) {
  
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1297, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iEffect >= (unsigned int)EFFECT_MAX && (this->m_iEffect <= (unsigned int)EFFECT_2_NO_EFFECT || this->m_iEffect >= (unsigned int)EFFECT_2_MAX) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1299, "(m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) )") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetEffectGfxInfo(rInfo, this->m_iEffect, this->uMissile.m_iDir, this->m_iFrame);
  rInfo->m_uObjType = 64;
  rInfo->m_iEffectScreenX = (float)(this->uMissile.m_fVelocityX * (float)_iTimeIndex) + this->uMissile.m_fWorldX;
  rInfo->m_iEffectScreenY = (float)((float)(this->uMissile.m_fVelocityY * (float)_iTimeIndex) + this->uMissile.m_fWorldY) + (float)((float)((float)_iTimeIndex * (float)_iTimeIndex) * this->uMissile.m_fArcStep);
}


// address=[0x144b800]
// Decompiled from void __thiscall CEffect::VisualizeCannonball(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void  CEffect::VisualizeCannonball(struct SGfxObjectInfo & a2, int _iTimeIndex) {
  
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1322, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iEffect >= 0x56u && (this->m_iEffect <= 0x64u || this->m_iEffect >= 0x74u) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1325, "(m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) )") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1326, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetEffectGfxInfo(a2, this->m_iEffect, this->uMissile.m_iDir, _iTimeIndex % (unsigned int)this->m_uFramesMax);
  a2->m_uObjType = 64;
  a2->m_iEffectScreenX = (float)(this->uMissile.m_fVelocityX * (float)_iTimeIndex) + this->uMissile.m_fWorldX;
  a2->m_iEffectScreenY = (float)((float)(this->uMissile.m_fVelocityY * (float)_iTimeIndex) + this->uMissile.m_fWorldY) + (float)((float)((float)_iTimeIndex * (float)_iTimeIndex) * this->uMissile.m_fArcStep);
}


// address=[0x144b950]
// Decompiled from void __thiscall CEffect::VisualizeSporeCloud(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void  CEffect::VisualizeSporeCloud(struct SGfxObjectInfo & a2, int _iTimeIndex) {
  
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1143, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1144, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetEffectGfxInfo(a2, this->m_iEffect, this->uSpore.m_iDir, _iTimeIndex % (unsigned int)this->m_uFramesMax);
  a2->m_uObjType = 0x80;
  a2->m_iEffectScreenX = (float)(this->uSpore.m_fScreenStepX * (float)_iTimeIndex) + this->uSpore.m_fSrcScreenX;
  a2->m_iEffectScreenY = (float)(this->uSpore.m_fScreenStepY * (float)_iTimeIndex) + this->uSpore.m_fSrcScreenY;
}


// address=[0x144ba40]
// Decompiled from void __thiscall CEffect::VisualizeStagnantAnimal(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void  CEffect::VisualizeStagnantAnimal(struct SGfxObjectInfo & a2, int _iTimeIndex) {
  
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1166, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1167, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  CGfxManager::GetAnimalGfxInfo(g_pGfxManager, a2, this->m_iEffect, this->uEffect.m_iDir, _iTimeIndex % (unsigned int)this->m_uFramesMax);
  a2->m_uObjType = 128;
  a2->m_iEffectScreenX = this->uEffect.m_fWorldX;
  a2->m_iEffectScreenY = this->uEffect.m_fWorldY;
}


// address=[0x144bb10]
// Decompiled from void __thiscall CEffect::VisualizeMovingEffect(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void  CEffect::VisualizeMovingEffect(struct SGfxObjectInfo & a2, int _iTimeIndex) {
  
  int iTimeIndex; // [esp+8h] [ebp-10h]
  int uDelay; // [esp+10h] [ebp-8h]

  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1187, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1188, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  CGfxManager::GetEffectGfxInfo(g_pGfxManager, a2, this->m_iEffect, this->uMoving.m_iDir, (_iTimeIndex + (unsigned int)this->uMoving.m_iFrame) % this->uMoving.m_uFramesMax);
  a2->m_uObjType = 128;
  uDelay = this->m_uDelay;
  if ( _iTimeIndex > uDelay )
  {
    iTimeIndex = this->m_uDelay;
  }
  else
  {
    iTimeIndex = _iTimeIndex;
  }
  if ( this->m_uDelay && iTimeIndex > 0 )
  {
    a2->m_iEffectScreenX = (float)(iTimeIndex * (this->uMoving.m_iScreenX - this->uMoving.m_iStartScreenX) / uDelay + this->uMoving.m_iStartScreenX);
    a2->m_iEffectScreenY = (float)(iTimeIndex * (this->uMoving.m_iScreenY - this->uMoving.m_iStartScreenY) / uDelay + this->uMoving.m_iStartScreenY);
  }
  else
  {
    a2->m_iEffectScreenX = (float)this->uMoving.m_iStartScreenX;
    a2->m_iEffectScreenY = (float)this->uMoving.m_iStartScreenY;
  }
  a2->m_iZOrdering = -64;
}


// address=[0x144bc80]
// Decompiled from void __thiscall CEffect::VisualizeTopEffect(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void  CEffect::VisualizeTopEffect(struct SGfxObjectInfo & a2, int _iTimeIndex) {
  
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1221, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1222, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetEffectGfxInfo(a2, this->m_iEffect, 0, _iTimeIndex % (unsigned int)this->m_uFramesMax);
  a2->m_uObjType = 0x80;
  a2->m_iEffectScreenX = this->uEffect.m_fWorldX;
  a2->m_iEffectScreenY = this->uEffect.m_fWorldY;
  a2->m_iZOrdering = -64;                       // Maybe related to Top?
}


// address=[0x144bd50]
// Decompiled from void __thiscall CEffect::VisualizeTopFireball(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void  CEffect::VisualizeTopFireball(struct SGfxObjectInfo & a2, int _iTimeIndex) {
  
  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1244, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1245, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iEffect >= (unsigned int)EFFECT_MAX && (this->m_iEffect <= 0x64u || this->m_iEffect >= 0x74u) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1247, "(m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) )") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetEffectGfxInfo(a2, this->m_iEffect, this->uMissile.m_iDir, _iTimeIndex % (unsigned int)this->uAngel.m_uFramesMax);
  a2->m_uObjType = 64;
  a2->m_iEffectScreenX = (float)(this->uMissile.m_fVelocityX * (float)_iTimeIndex) + this->uMissile.m_fWorldX;
  a2->m_iEffectScreenY = (float)((float)(this->uMissile.m_fVelocityY * (float)_iTimeIndex) + this->uMissile.m_fWorldY) + (float)((float)((float)_iTimeIndex * (float)_iTimeIndex) * this->uMissile.m_fArcStep);
  a2->m_iZOrdering = -64;
}


// address=[0x144beb0]
// Decompiled from void __thiscall CEffect::VisualizeAttachedEffect(CEffect *this, struct SGfxObjectInfo *a2, int _iTimeIndex)
void  CEffect::VisualizeAttachedEffect(struct SGfxObjectInfo & a2, int _iTimeIndex) {
  
  unsigned int m_iEffect; // [esp+0h] [ebp-10h]
  unsigned int iDir; // [esp+4h] [ebp-Ch]
  unsigned int iJob; // [esp+8h] [ebp-8h]

  if ( !this->m_uFramesMax && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1349, "m_uFramesMax > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iTimeIndex < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1350, "_iTimeIndex >= 0") == 1 )
  {
    __debugbreak();
  }
  m_iEffect = this->m_iEffect;
  iDir = this->uAttached.m_iDir;
  iJob = _iTimeIndex % (unsigned int)this->uAngel.m_uFramesMax;
  this->uAttached.m_bProcessed = 1;
  CEffect::GetEffectGfxInfo(a2, m_iEffect, iDir, iJob);
  a2->m_uObjType = 0x80;
  a2->m_iEffectScreenX = a2->m_iEffectScreenX + this->uAttached.m_fOffsetX;
  a2->m_iEffectScreenY = a2->m_iEffectScreenY + this->uAttached.m_fOffsetY;
  a2->m_iZOrdering = -64;
}


// address=[0x144f270]
// Decompiled from void __thiscall CEffect::VisualizeNOP(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeNOP(struct SGfxObjectInfo & a2, int a3) {
  
  ;
}


// address=[0x144f500]
// Decompiled from void __cdecl CEffect::GetEffectGfxInfo(struct SGfxObjectInfo *a1, unsigned int a2, unsigned int a3, unsigned int a4)
void __cdecl CEffect::GetEffectGfxInfo(struct SGfxObjectInfo & a1, int a2, unsigned int a3, unsigned int a4) {
  
  CGfxManager::GetEffectGfxInfo(g_pGfxManager, a1, a2, a3, a4);
}


// address=[0x144f530]
// Decompiled from int __cdecl CEffect::GetEffectNumberOfFrames(unsigned int a1)
unsigned int __cdecl CEffect::GetEffectNumberOfFrames(int a1) {
  
  unsigned int uNumberOfFrames; // [esp+4h] [ebp-4h]

  uNumberOfFrames = CGfxManager::GetEffectFrameCount(g_pGfxManager, a1);
  if ( uNumberOfFrames >= 0x100 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 661, "uNumberOfFrames < 256") == 1 )
  {
    __debugbreak();
  }
  return ((_BYTE)uNumberOfFrames == 0) + (unsigned __int8)uNumberOfFrames;
}


// address=[0x144f5c0]
// Decompiled from void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, int *a3, int *a4)
void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, int & a3, int & a4) {
  
  float v4; // [esp+0h] [ebp-8h] BYREF
  float v5; // [esp+4h] [ebp-4h] BYREF

  v5 = 0.0;
  v4 = 0.0;
  IGfxEngine::ConvertMapPositionToWorldScreenOffsets(g_pGfxEngine, a1, a2, &v5, &v4);
  *a3 = (int)v5;
  *a4 = (int)v4;
}


// address=[0x144f620]
// Decompiled from void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, float *a3, float *a4)
void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, float & a3, float & a4) {
  
  IGfxEngine::ConvertMapPositionToWorldScreenOffsets(g_pGfxEngine, a1, a2, a3, a4);
}


// address=[0x144f690]
// Decompiled from BOOL __thiscall CEffect::IsOutOfDate(CEffect *this, int a2)
int  CEffect::IsOutOfDate(int a2)const {
  
  return a2 >= this->m_iDuration;
}


// address=[0x144f700]
// Decompiled from void __thiscall CEffect::SetVisualizeFunc(CEffect *this, int a2)
void  CEffect::SetVisualizeFunc(enum T_VISUALIZE_FUNC a2) {
  
  if ( a2 > 11 )
  {
    if ( BBSupportDbgReport(1, "Logic\\Effects.cpp", 633, "CEffect::VisualizeFunc(): Invalid visualize function!") == 1 )
    {
      __debugbreak();
    }
    a2 = 1;
  }
  this->m_uVisualizeFunc = a2;
  this->m_fpVisualize = (int (__thiscall *)(CEffect *, struct SGfxObjectInfo *, int))s_fpVisualizeFunctions[a2];
}


// address=[0x144f770]
// Decompiled from int __thiscall CEffect::SquareRow(CEffect *this)
int  CEffect::SquareRow(void)const {
  
  return this->m_iSquareRow & 0xF;
}


// address=[0x144f790]
// Decompiled from int __thiscall CEffect::TimeIndex(CEffect *this, unsigned int a2)
int  CEffect::TimeIndex(unsigned int a2)const {
  
  return a2 - this->m_iNextTick;
}


// address=[0x144f7b0]
// Decompiled from int __thiscall CEffect::Visualize(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::Visualize(struct SGfxObjectInfo & a2, int a3) {
  
  return this->m_fpVisualize(this, a2, a3);
}


// address=[0x144f7e0]
// Decompiled from int __thiscall CEffect::VisualizeFunc(CEffect *this)
enum T_VISUALIZE_FUNC  CEffect::VisualizeFunc(void)const {
  
  return this->m_uVisualizeFunc;
}


#endif // Already implemented
