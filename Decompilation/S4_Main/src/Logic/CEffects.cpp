#include "CEffects.h"

#include "CBB/CBBSupport.h"
#include "Defines/Effects.h"
#include "Main/CGameStateHandler.h"
#include "Main/Players/CPlayerManager.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

// Definitions for class CEffects

// address=[0x144bfb0]
// Decompiled from CEffects *__thiscall CEffects::CEffects(CEffects *this)
CEffects::CEffects(void) : IEffects(), CBBObject("CEffects", 1) {
  memset(&this->m_sViewPortData, 0, sizeof(this->m_sViewPortData));
  this->m_sViewPortData.m_iCurrentY = -1;
  this->m_sViewPortData.m_uU1C = -1;
  memset(this->m_uEffectSquareListHeadVW, 0, sizeof(this->m_uEffectSquareListHeadVW));
  memset(this->m_cEffects, 0, sizeof(this->m_cEffects));
  memset(this->m_iMovingEffectSoundId, 255, sizeof(this->m_iMovingEffectSoundId));
  this->m_cEffects[1].m_uPrevEffect = 0;        // Set up linked list
  this->m_cEffects[1].m_uNextEffect = 2;
  this->m_cEffects[2].m_uPrevEffect = 1;
  this->m_cEffects[2].m_uNextEffect = 3;
  for(unsigned int i = 3; i < EFFECTS_MAX - 1; ++i) {
    this->m_cEffects[i].m_uPrevEffect = i - 1;
    this->m_cEffects[i].m_uNextEffect = i + 1;
  }
  this->m_cEffects[EFFECTS_MAX - 1].m_uPrevEffect = EFFECTS_MAX - 2;
  this->m_cEffects[EFFECTS_MAX - 1].m_uNextEffect = 0;
  this->m_iMaxXY = 0;
  this->m_iTickCounter = 0;
  memset(this->m_iMovingEffectCounters, 0, sizeof(this->m_iMovingEffectCounters));
  memset(&CEffects::m_sGfxInfo, 0, sizeof(CEffects::m_sGfxInfo));
  BB_ASSERT(g_pGfxEngine != 0)
  g_pGfxEngine->SetEffectSystemInterfacePtr(this);
}


// address=[0x144c200]
// Decompiled from void __thiscall CEffects::~CEffects(CEffects *this)
CEffects::~CEffects(void) {
  if(g_pGfxEngine)
    g_pGfxEngine->SetEffectSystemInterfacePtr(0);
}


// address=[0x144c280]
// Decompiled from CEffects *__thiscall CEffects::SetEffectsViewport(CEffects *this, int _iX0, int _iY0, int _iX1, int _iY1, int _iX2)
void CEffects::SetEffectsViewport(int _iX0, int _iY0, int _iX1, int _iY1, int _iX2) {
  CEffects::ClipXOrY(_iX0);
  CEffects::ClipXOrY(_iY0);
  CEffects::ClipXOrY(_iX1);
  CEffects::ClipXOrY(_iY1);
  CEffects::ClipXOrY(_iX2);
  if(_iX0 > _iX1 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1731, "_iX0 <= _iX1") == 1)
    __debugbreak();
  if(_iX1 > _iX2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1732, "_iX1 <= _iX2") == 1)
    __debugbreak();
  if(_iY0 > _iY1 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1733, "_iY0 <= _iY1") == 1)
    __debugbreak();
  this->m_sViewPortData.m_iViewX0 = _iX0;
  this->m_sViewPortData.m_iViewY0 = _iY0;
  this->m_sViewPortData.m_iViewX1 = _iX1;
  this->m_sViewPortData.m_iViewY1 = _iY1;
  this->m_sViewPortData.m_iViewX2 = _iX2;
  this->m_sViewPortData.m_iTick = g_pGame->GetTickCounter();
  this->m_sViewPortData.m_iCurrentY = -1;
  this->m_sViewPortData.m_uU1C = -1;
  this->m_sViewPortData.m_uU20 = 0;
}


// address=[0x144c3a0]
// Decompiled from int __thiscall CEffects::FirstEffect(CEffects *this, int _iY)
struct SGfxObjectInfo *CEffects::FirstEffect(int _iY) {
  unsigned int m_uNextEffect; // [esp+0h] [ebp-34h]
  unsigned int v4; // [esp+8h] [ebp-2Ch]
  int          tSoundId; // [esp+Ch] [ebp-28h]
  int          v6; // [esp+10h] [ebp-24h]
  // [esp+14h] [ebp-20h]
  int v8; // [esp+18h] [ebp-1Ch]
  // [esp+1Ch] [ebp-18h]
  signed int iVRight; // [esp+20h] [ebp-14h]
  int        iVLeft; // [esp+24h] [ebp-10h]
  // [esp+28h] [ebp-Ch]

  BB_ASSERT(_iY >= 0)
  BB_ASSERT(_iY < Squares::SQUARE_MAX_SUPPORTED_MAP_WIDTH_HEIGHT)
  BB_ASSERT(_iY >= m_sViewPortData.m_iViewY0)
  BB_ASSERT(_iY <= m_sViewPortData.m_iViewY1)
  BB_ASSERT(_iY > m_sViewPortData.m_iCurrentY)

  int v7 = Squares::XYToVW(_iY);
  if(v7 != this->m_sViewPortData.m_uU1C) {
    this->m_sViewPortData.m_uU1C = v7;
    iVLeft = Squares::XYToVW(this->m_sViewPortData.m_iViewX0);
    iVRight = Squares::XYToVW(this->m_sViewPortData.m_iViewX2);
    BB_ASSERT(Squares::ValidVW(iVLeft))
    BB_ASSERT(Squares::ValidVW(iVRight))

    if(iVLeft > 0)
      --iVLeft;
    if(iVRight < 63)
      ++iVRight;
    memset(this->m_sViewPortData.m_iMaxRows, 0, sizeof(this->m_sViewPortData.m_iMaxRows));
    for(int i = iVLeft; i <= iVRight; ++i) {
      for(unsigned int j = this->EffectSquareListHeadVW(i, v7); j; j = m_uNextEffect) {
        CEffect &rEffect = this->m_cEffects[j];
        m_uNextEffect = this->m_cEffects[j].m_uNextEffect;
        v6 = rEffect.TimeIndex(this->m_sViewPortData.m_iTick);
        if(v6 >= 0) {
          if(rEffect.IsOutOfDate(v6))
            goto LABEL_40;
          tSoundId = this->m_cEffects[j].m_tSoundId;
          if(this->m_cEffects[j].m_tSoundId) {
            this->m_cEffects[j].m_tSoundId = 0;
            if(!v6)
              g_pSoundManager->PlayEnvironmentSound(
                tSoundId,
                this->m_cEffects[j].m_iX,
                this->m_cEffects[j].m_iY,
                0);
          }
          if(!this->m_cEffects[j].m_uEffect) {
          LABEL_40:
            this->MoveEffectFromSquareListToFreeList(j);
          } else {
            v8 = rEffect.SquareRow();
            v4 = this->m_sViewPortData.m_iMaxRows[v8];
            if(v4 < 64) {
              ++this->m_sViewPortData.m_iMaxRows[v8];
              this->m_sViewPortData.m_iRows[v8][v4] = j;
            }
          }
        }
      }
    }
  }
  this->m_sViewPortData.m_iCurrentY = _iY;
  this->m_sViewPortData.m_uU20 = 0;
  return this->NextEffect();
}


// address=[0x144c6e0]
// Decompiled from SGfxObjectInfo *__thiscall CEffects::NextEffect(CEffects *this)
struct SGfxObjectInfo *CEffects::NextEffect(void) {
  // eax
  // eax
  // eax
  // [esp+0h] [ebp-18h]
  // [esp+8h] [ebp-10h]
  // [esp+Ch] [ebp-Ch]
  // [esp+10h] [ebp-8h]

  BB_ASSERT(m_sViewPortData.m_iCurrentY >= 0)

  int v7 = this->m_sViewPortData.m_iCurrentY & 0xF;
  if(this->m_sViewPortData.m_uU20 >= this->m_sViewPortData.m_iMaxRows[v7])
    return 0;
  int      v5 = this->m_sViewPortData.m_iRows[v7][this->m_sViewPortData.m_uU20++];
  CEffect &rEffect = this->m_cEffects[v5];
  CEffects::m_sGfxInfo.m_bIsVisible = 1;
  CEffects::m_sGfxInfo.m_iZOrdering = 0;
  if(rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_ATTACHED_EFFECT) {
    DWORD iParentId = rEffect.uAttached.m_iParentId;
    if(!this->CheckParentEffect(iParentId))
      return 0;
    int v2 = this->m_cEffects[iParentId].TimeIndex(this->m_sViewPortData.m_iTick);
    this->m_cEffects[iParentId].Visualize(CEffects::m_sGfxInfo, v2);
    int v3 = rEffect.TimeIndex(this->m_sViewPortData.m_iTick);
    rEffect.Visualize(CEffects::m_sGfxInfo, v3);
  } else {
    int v4 = rEffect.TimeIndex(this->m_sViewPortData.m_iTick);
    rEffect.Visualize(CEffects::m_sGfxInfo, v4);
  }
  BB_ASSERT(g_cWorld.InWorld(rEffect.m_iX, rEffect.m_iY))

  CEffects::m_sGfxInfo.m_iEffectX = rEffect.m_iX;
  CEffects::m_sGfxInfo.m_iEffectY = rEffect.m_iY;
  return &CEffects::m_sGfxInfo;
}


// address=[0x144c880]
// Decompiled from void __thiscall CEffects::Load(CEffects *__shifted(CEffects,4) this, struct IS4Chunk *a2)
void CEffects::Load(class IS4Chunk &rChunk) {
  // eax
  // [esp+0h] [ebp-Ch]
  // [esp+4h] [ebp-8h]

  memset(&this->m_sViewPortData, 0, sizeof(this->m_sViewPortData));
  this->m_sViewPortData.m_iCurrentY = -1;
  this->m_sViewPortData.m_uU1C = -1;
  rChunk.LoadSignature(-1824106861);
  rChunk.LoadUnsigned32(1, 1);
  rChunk.LoadUnsigned32(4096, 4096);
  rChunk.LoadUnsigned32(60, 60);
  rChunk.LoadUnsigned32();
  rChunk.Load(this->m_uEffectSquareListHeadVW, 8448);
  rChunk.Load(this->m_cEffects, 245760);
  this->m_iMaxXY = 0;
  this->m_iTickCounter = 0;
  memset(this->m_iMovingEffectCounters, 0, sizeof(this->m_iMovingEffectCounters));
  memset(&CEffects::m_sGfxInfo, 0, sizeof(CEffects::m_sGfxInfo));
  for(unsigned int i = 2; i < EFFECTS_MAX; ++i) {
    CEffect &        rEffect = this->m_cEffects[i];
    T_VISUALIZE_FUNC fpVisFunc = rEffect.VisualizeFunc();
    rEffect.SetVisualizeFunc(fpVisFunc);
    if(rEffect.VisualizeFunc() == VISUALIZE_FUNC_MOVING_EFFECT)
      this->IncreaseMovingEffectCounter(rEffect.m_uEffect);// _iEffect
  }
  rChunk.LoadSignature(1452512070);
}


// address=[0x144ca00]
// Decompiled from void __thiscall CEffects::Save(CEffects *__shifted(CEffects,4) this, struct IS4Chunk *a2)
void CEffects::Save(class IS4Chunk &rChunk) {
  if(this->m_iTickCounter < g_pGame->GetTickCounter())
    this->CleanUp();
  rChunk.SaveSignature(-1824106861);
  rChunk.SaveUnsigned32(1);
  rChunk.SaveUnsigned32(4096);
  rChunk.SaveUnsigned32(60);
  rChunk.SaveUnsigned32(245760);
  rChunk.Save(this->m_uEffectSquareListHeadVW, 0x2100u);
  rChunk.Save(this->m_cEffects, 0x3C000u);
  static_assert(sizeof(this->m_uEffectSquareListHeadVW) == 0x2100u, "Size of m_uEffectSquareListHeadVW must match original");
  static_assert(sizeof(this->m_cEffects) == 0x3C000u, "Size of m_cEffects must match original");
  rChunk.SaveSignature(1452512070);
}


// address=[0x144cae0]
// Decompiled from uint __thiscall CEffects::AddEffect(  CEffects *this,  int _iEffect,  enum SIV_SOUNDS _tSound,  int iX,  int iY,  unsigned int _uStartDelay,  int _iDuration,  bool bTopEffect)
unsigned int CEffects::AddEffect(int _iEffect, enum SIV_SOUNDS _tSound, int iX, int iY, unsigned int _uStartDelay, int _iDuration, bool bTopEffect) {
  if(CWorldManager::InWorld(iX, iY)) {
    unsigned int iFreeId = this->FirstFreeEffectId();
    if(iFreeId) {
      this->RemoveEffectFromList(iFreeId);
      this->m_cEffects[iFreeId].InitEffect(
        _iEffect,
        _tSound,
        iX,
        iY,
        _uStartDelay,
        _iDuration,
        bTopEffect);
      this->AddEffectToSquareList(iFreeId);
      return this->m_cEffects[iFreeId].uAngel.m_iDuration + _uStartDelay;// Just duration
    }
  }

  if(_uStartDelay)
    return _uStartDelay;

  return 1;
}


// address=[0x144cbb0]
// Decompiled from unsigned int __thiscall CEffects::AddAngel(  CEffects *this,  int _tAngel,  BYTE tSoundId,  unsigned int _iX,  unsigned int _iY,  int _iPlayerId,  unsigned int _uStartDelay)
unsigned int CEffects::AddAngel(enum T_EFFECT_ANGEL _tAngel, enum SIV_SOUNDS tSoundId, int _iX, int _iY, int _iPlayerId, unsigned int _uStartDelay) {
  // [esp+10h] [ebp-4h]
  BB_ASSERT(_tAngel <= EFFECT_ANGEL_LAST)
  BB_ASSERT(g_cWorld.InWorld(_iX, _iY))
  BB_ASSERT(g_cPlayerMgr.ValidUsedPlayerId(_iPlayerId))
  BB_ASSERT(_uStartDelay < 1024)

  unsigned int FreeEffectId = CEffects::FirstFreeEffectId();
  if(FreeEffectId == 0 || _tAngel == 0)
    return _uStartDelay;
  CEffects::RemoveEffectFromList(FreeEffectId);
  this->m_cEffects[FreeEffectId].InitAngel(_tAngel, tSoundId, _iX, _iY, _iPlayerId, _uStartDelay);
  CEffects::AddEffectToSquareList(FreeEffectId);
  return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + _uStartDelay;
}


// address=[0x144cd20]
// Decompiled from unsigned int __thiscall CEffects::AddMissile(  CEffects *this,  int _tMissile,  int _iAttackerXY,  int _iTargetXY,  unsigned int _uStartDelay,  int _iTargetOffsetX,  int _iTargetOffsetY)
unsigned int CEffects::AddMissile(enum T_EFFECT_MISSILE _tMissile, int _iAttackerXY, int _iTargetXY, unsigned int _uStartDelay, int _iTargetOffsetX, int _iTargetOffsetY) {
  // [esp+8h] [ebp-4h]
  BB_ASSERT(_tMissile <= EFFECT_MISSILE_LAST)
  BB_ASSERT(g_cWorld.InWorldPackedXY(_iAttackerXY))
  BB_ASSERT(g_cWorld.InWorldPackedXY(_iTargetXY))
  BB_ASSERT(_uStartDelay < 1024)
  unsigned int FreeEffectId = CEffects::FirstFreeEffectId();
  if(!FreeEffectId)
    return _uStartDelay;
  CEffects::RemoveEffectFromList(FreeEffectId);
  this->m_cEffects[FreeEffectId].InitMissile(
    _tMissile,
    _iAttackerXY,
    _iTargetXY,
    _uStartDelay,
    _iTargetOffsetX,
    _iTargetOffsetY);
  CEffects::AddEffectToSquareList(FreeEffectId);
  return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + _uStartDelay;
}


// address=[0x144ce50]
// Decompiled from unsigned int __thiscall CEffects::AddSporeCloud(CEffects *this, int _iSrcXY, int _iDstXY, unsigned int _uStartDelay)
unsigned int CEffects::AddSporeCloud(int _iSrcXY, int _iDstXY, unsigned int _uStartDelay) {
  // [esp+0h] [ebp-14h]
  // [esp+4h] [ebp-10h]
  // [esp+Ch] [ebp-8h]
  // [esp+24h] [ebp+10h]

  BB_ASSERT(g_cWorld.InWorldPackedXY(_iSrcXY))
  BB_ASSERT(g_cWorld.InWorldPackedXY(_iDstXY))
  BB_ASSERT(_uStartDelay < 1024)

  int          iX = Y16X16::UnpackXFast(_iSrcXY);
  int          iY = Y16X16::UnpackYFast(_iSrcXY);
  unsigned int iNextTick = this->AddEffect(EFFECT_SPORECLOUD_GROW, SOUND_NO_SOUND, iX, iY, _uStartDelay, 0, 0);
  unsigned int FreeEffectId = CEffects::FirstFreeEffectId();
  if(!FreeEffectId)
    return iNextTick;
  CEffects::RemoveEffectFromList(FreeEffectId);
  this->m_cEffects[FreeEffectId].InitSporeCloud(_iSrcXY, _iDstXY, iNextTick);
  CEffects::AddEffectToSquareList(FreeEffectId);
  return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + iNextTick;
}


// address=[0x144cf90]
// Decompiled from unsigned int __thiscall CEffects::AddStagnantAnimal(  CEffects *this,  signed int _tAnimalJob,  char a3,  unsigned int _iX,  unsigned int _iY,  unsigned int iDir,  unsigned int _uStartDelay)
unsigned int CEffects::AddStagnantAnimal(enum SIV_ANIMALS _tAnimalJob, enum SIV_SOUNDS a3, int _iX, int _iY, int _iDir, unsigned int _uStartDelay) {
  // [esp+8h] [ebp-4h]

  BB_ASSERT(_tAnimalJob != ANIMAL_NO_ANIMAL_WALK)
  BB_ASSERT(_tAnimalJob < SIV_ANIMAL_MAX)
  BB_ASSERT((_iDir >= 0) && (_iDir < 6))
  BB_ASSERT(g_cWorld.InWorld(_iX, _iY))
  BB_ASSERT(_uStartDelay < 1024)
  unsigned int FreeEffectId = CEffects::FirstFreeEffectId();
  if(!FreeEffectId)
    return _uStartDelay;
  CEffects::RemoveEffectFromList(FreeEffectId);
  this->m_cEffects[FreeEffectId].InitStagnantAnimal(_tAnimalJob, a3, _iX, _iY, _iDir, _uStartDelay);
  CEffects::AddEffectToSquareList(FreeEffectId);
  return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + _uStartDelay;
}


// address=[0x144d0f0]
// Decompiled from void __thiscall CEffects::DeleteEffect(CEffects *this, unsigned int _uEffectId)
void CEffects::DeleteEffect(unsigned int _uEffectId) {
  BB_ASSERT((_uEffectId > 0) && (_uEffectId < EFFECTS_MAX))
  if(_uEffectId && _uEffectId < EFFECTS_MAX && this->m_cEffects[_uEffectId].m_uVisualizeFunc) {
    if(this->m_cEffects[_uEffectId].m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT)
      CEffects::DecreaseMovingEffectCounter(this->m_cEffects[_uEffectId].m_uEffect);
    CEffects::MoveEffectFromSquareListToFreeList(_uEffectId);
  }
}


// address=[0x144d180]
// Decompiled from unsigned int __thiscall CEffects::CreateMovingEffect(CEffects *this, int _iEffect, int a3, int a4)
unsigned int CEffects::CreateMovingEffect(int _iEffect, int a3, int a4) {
  // [esp+4h] [ebp-8h]

  BB_ASSERT(((_iEffect > EFFECT_NO_EFFECT) && (_iEffect < EFFECT_MAX)) || ((_iEffect > EFFECT_2_NO_EFFECT) && (_iEffect < EFFECT_2_MAX)))

  unsigned int FreeEffectId = CEffects::FirstFreeEffectId();
  if(!FreeEffectId)
    return FreeEffectId;
  CEffects::RemoveEffectFromList(FreeEffectId);
  this->m_cEffects[FreeEffectId].InitMovingEffect(_iEffect, a3, a4);
  CEffects::AddEffectToSquareList(FreeEffectId);
  CEffects::IncreaseMovingEffectCounter(_iEffect);
  return FreeEffectId;
}


// address=[0x144d230]
// Decompiled from void __thiscall CEffects::ChangeMovingEffectType(CEffects *this, unsigned int _uEffectId, unsigned int _iEffect)
void CEffects::ChangeMovingEffectType(unsigned int _uEffectId, int _iEffect) {
  // [esp+Ch] [ebp-4h]

  BB_ASSERT((_uEffectId > 0) && (_uEffectId < EFFECTS_MAX))
  if(_iEffect < EFFECT_MAX && _uEffectId != 0) {
    CEffect &rEffect = this->m_cEffects[_uEffectId];
    BB_ASSERT(rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT)

    if(rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT) {
      CEffects::DecreaseMovingEffectCounter(this->m_cEffects[_uEffectId].m_uEffect);
      CEffects::IncreaseMovingEffectCounter(_iEffect);
      this->m_cEffects[_uEffectId].m_uEffect = _iEffect;
      this->m_cEffects[_uEffectId].uAngel.m_uFramesMax = CEffect::GetEffectNumberOfFrames(_iEffect);
      this->m_cEffects[_uEffectId].uAngel.m_iFrame = 0;
    }
  }
}


// address=[0x144d330]
// Decompiled from int __thiscall CEffects::NumberOfMovingEffects(CEffects *this, DWORD _tEffect)
int CEffects::NumberOfMovingEffects(int _tEffect) {
  BB_ASSERT(static_cast<unsigned int>(_tEffect) < EFFECT_MAX)
  BB_ASSERT(m_iMovingEffectCounters[_tEffect] >= 0)

  return this->m_iMovingEffectCounters[_tEffect];
}


// address=[0x144d3a0]
// Decompiled from void __thiscall CEffects::GetMovingEffectInfo(  CEffects *this,  unsigned int _uEffectId,  int *_rEffect,  int *_rX,  int *_rY,  int *_rDir)
void CEffects::GetMovingEffectInfo(unsigned int _uEffectId, int &_rEffect, int &_rX, int &_rY, int &_rDir) {
  int iTick; // [esp+4h] [ebp-14h]
  // [esp+8h] [ebp-10h]
  // [esp+Ch] [ebp-Ch]

  BB_ASSERT((_uEffectId > 0) && (_uEffectId < EFFECTS_MAX))
  CEffect &rEffect = this->m_cEffects[_uEffectId];
  BB_ASSERT(rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT)
  _rEffect = this->m_cEffects[_uEffectId].m_uEffect;
  unsigned int TickCounter = g_pGame->GetTickCounter();
  if(TickCounter < this->m_cEffects[_uEffectId].uMoving.m_iNextTick)
    iTick = 0;
  else
    iTick = TickCounter - this->m_cEffects[_uEffectId].uMoving.m_iNextTick;
  int uDelay = this->m_cEffects[_uEffectId].m_uDelay;
  if(iTick < uDelay) {
    if(iTick <= 0) {
      _rX = this->m_cEffects[_uEffectId].uMoving.m_iX;
      _rY = this->m_cEffects[_uEffectId].uMoving.m_iY;
    } else {
      _rX = this->m_cEffects[_uEffectId].uMoving.m_iX
            + iTick
            * (this->m_cEffects[_uEffectId].uMoving.m_iStartX - this->m_cEffects[_uEffectId].uMoving.m_iX)
            / uDelay;
      _rY = this->m_cEffects[_uEffectId].uMoving.m_iY
            + iTick
            * (this->m_cEffects[_uEffectId].uMoving.m_iStartY - this->m_cEffects[_uEffectId].uMoving.m_iY)
            / uDelay;
    }
  } else {
    _rX = this->m_cEffects[_uEffectId].uMoving.m_iStartX;
    _rY = this->m_cEffects[_uEffectId].uMoving.m_iStartY;
  }
  _rDir = this->m_cEffects[_uEffectId].uMoving.m_iDir;
}


// address=[0x144d4f0]
// Decompiled from void __thiscall CEffects::SetMovingEffectSpeed(CEffects *this, unsigned int _uEffectId, int _iSpeed)
void CEffects::SetMovingEffectSpeed(unsigned int _uEffectId, int _iSpeed) {
  if(!_uEffectId || _uEffectId >= EFFECTS_MAX || this->m_cEffects[_uEffectId].m_uVisualizeFunc != VISUALIZE_FUNC_MOVING_EFFECT) return;

  if(_iSpeed < 10)
    _iSpeed = 10;
  if(_iSpeed > 500)
    _iSpeed = 500;

  this->m_cEffects[_uEffectId].uMoving.m_uSpeed = _iSpeed;
}


// address=[0x144d560]
// Decompiled from int __thiscall CEffects::SetMovingEffectDestination(CEffects *this, unsigned int _uEffectId, int a3, int a4, int a5)
unsigned int CEffects::SetMovingEffectDestination(unsigned int _uEffectId, int a3, int a4, int a5) {
  // [esp+0h] [ebp-Ch]
  // [esp+4h] [ebp-8h]

  BB_ASSERT((_uEffectId > 0) && (_uEffectId < EFFECTS_MAX))
  if(!_uEffectId)
    return 0;
  CEffects::RemoveEffectFromList(_uEffectId);
  CEffect &rEffect = this->m_cEffects[_uEffectId];
  BB_ASSERT(rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT)

  unsigned int v6 = rEffect.SetNewDestinationForMovingEffect(a3, a4, a5);
  CEffects::AddEffectToSquareList(_uEffectId);
  return v6;
}


// address=[0x144d620]
// Decompiled from int __thiscall CEffects::GetMovingEffectDirection(CEffects *this, unsigned int a2)
int CEffects::GetMovingEffectDirection(unsigned int _iEffectId) {
  // [esp+4h] [ebp-8h]

  if(!_iEffectId || _iEffectId >= EFFECTS_MAX)
    return 0;
  int v3 = 0;
  if(this->m_cEffects[_iEffectId].m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT)
    return this->m_cEffects[_iEffectId].uMoving.m_iDir;
  return v3;
}


// address=[0x144d680]
// Decompiled from void __thiscall CEffects::SetMovingEffectDirection(CEffects *this, unsigned int _iEffectId, int _iDir)
void CEffects::SetMovingEffectDirection(unsigned int _iEffectId, int _iDir) {
  if(!_iEffectId || _iEffectId >= EFFECTS_MAX
     || this->m_cEffects[_iEffectId].m_uVisualizeFunc != VISUALIZE_FUNC_MOVING_EFFECT
     || this->m_cEffects[_iEffectId].uMoving.m_iMaxDir <= 1u
     || _iDir < 0)
    return;
  this->m_cEffects[_iEffectId].uMoving.m_iDir = _iDir % this->m_cEffects[_iEffectId].uMoving.m_iMaxDir;
}


// address=[0x144d6f0]
// Decompiled from int __thiscall CEffects::GetMovingEffectSoundId(CEffects *this, unsigned int _uEffectId)
int CEffects::GetMovingEffectSoundId(unsigned int _uEffectId) {
  BB_ASSERT((_uEffectId > 0) && (_uEffectId < EFFECTS_MAX))
  return this->m_iMovingEffectSoundId[_uEffectId];
}


// address=[0x144d740]
// Decompiled from void __thiscall CEffects::SetMovingEffectSoundId(CEffects *this, unsigned int _uEffectId, int _tSoundId)
void CEffects::SetMovingEffectSoundId(unsigned int _uEffectId, int _tSoundId) {
  BB_ASSERT((_uEffectId > 0) && (_uEffectId < EFFECTS_MAX))
  this->m_iMovingEffectSoundId[_uEffectId] = _tSoundId;
}


// address=[0x144d790]
// Decompiled from unsigned int __thiscall CEffects::CreateAttachedEffect(CEffects *this, int a2, unsigned int a3, char a4)
unsigned int CEffects::CreateAttachedEffect(int _iEffectType, unsigned int a3, int a4) {
  // [esp+8h] [ebp-8h]

  BB_ASSERT((_iEffectType > EFFECT_NO_EFFECT) && (_iEffectType < EFFECT_MAX) || (_iEffectType > EFFECT_2_NO_EFFECT && _iEffectType < EFFECT_2_MAX))
  if(!CEffects::CheckParentEffect(a3))
    return 0;
  unsigned int FreeEffectId = CEffects::FirstFreeEffectId();
  if(!FreeEffectId)
    return FreeEffectId;
  CEffects::RemoveEffectFromList(FreeEffectId);
  this->m_cEffects[FreeEffectId].InitAttachedEffect(_iEffectType, a3, this->m_cEffects[a3], a4);
  CEffects::AddEffectToSquareList(FreeEffectId);
  return FreeEffectId;
}


// address=[0x144d860]
// Decompiled from void __thiscall CEffects::SetAttachedEffectOffset(CEffects *this, unsigned int a2, float a3, float a4)
void CEffects::SetAttachedEffectOffset(unsigned int _uEffectId, float _fX, float _fY) {
  if(_uEffectId && _uEffectId < EFFECTS_MAX && this->m_cEffects[_uEffectId].m_uVisualizeFunc == VISUALIZE_FUNC_ATTACHED_EFFECT) {
    this->m_cEffects[_uEffectId].uAttached.m_fOffsetX = _fX;
    this->m_cEffects[_uEffectId].uAttached.m_fOffsetY = _fY;
  }
}


// address=[0x144d8c0]
// Decompiled from void __thiscall CEffects::UpdateAttachedEffect(CEffects *this, unsigned int _uEffectId)
void CEffects::UpdateAttachedEffect(unsigned int _uEffectId) {
  if(!_uEffectId || _uEffectId >= EFFECTS_MAX) return;

  CEffect &rEffect = this->m_cEffects[_uEffectId];
  if(rEffect.m_uVisualizeFunc != VISUALIZE_FUNC_ATTACHED_EFFECT || !CheckParentEffect(rEffect.uAttached.m_iParentId)) return;

  CEffect &rParent = this->m_cEffects[rEffect.uAttached.m_iParentId];
  CEffects::RemoveEffectFromList(_uEffectId);
  rEffect.UpdateAttachedEffect(rParent);
  CEffects::AddEffectToSquareList(_uEffectId);
}


// address=[0x144d950]
// Decompiled from bool __thiscall CEffects::WasAttachedEffectVisible(CEffects *this, unsigned int a2)
bool CEffects::WasAttachedEffectVisible(unsigned int _uEffectId) {
  // [esp+Bh] [ebp-1h]

  if(!_uEffectId || _uEffectId >= EFFECTS_MAX)
    return 0;
  bool m_bProcessed = 0;
  if(this->m_cEffects[_uEffectId].m_uVisualizeFunc != VISUALIZE_FUNC_ATTACHED_EFFECT)
    return m_bProcessed;
  m_bProcessed = this->m_cEffects[_uEffectId].uAttached.m_bProcessed;
  this->m_cEffects[_uEffectId].uAttached.m_bProcessed = 0;
  return m_bProcessed;
}


// address=[0x144d9b0]
// Decompiled from void __thiscall CEffects::Execute(CEffects *this)
void CEffects::Execute(void) {
  // eax
  // eax
  unsigned int m_uNextEffect; // [esp+0h] [ebp-2Ch]
  // [esp+4h] [ebp-28h]
  // [esp+8h] [ebp-24h]
  // [esp+10h] [ebp-1Ch]
  // [esp+14h] [ebp-18h]
  // [esp+18h] [ebp-14h]
  // [esp+1Ch] [ebp-10h]
  // [esp+24h] [ebp-8h]
  // [esp+28h] [ebp-4h]

  int iWidth = CWorldManager::Width();
  int iMaxW = Squares::XYToVW(iWidth);
  int iHeight = CWorldManager::Height();
  int iMaxV = Squares::XYToVW(iHeight);

  BB_ASSERT(iMaxV > 0)
  BB_ASSERT(iMaxW > 0)
  BB_ASSERT(iMaxV <= Squares::SQUARE_GRID_MAX_V_W)
  BB_ASSERT(iMaxW <= Squares::SQUARE_GRID_MAX_V_W)

  int iMaxCounter = (iMaxW * iMaxV + 31) / 32;
  BB_ASSERT(iMaxCounter > 0)
  int iV = Y16X16::UnpackXFast(this->m_iMaxXY);
  int iW = Y16X16::UnpackYFast(this->m_iMaxXY);
  for(int i = 0; i < iMaxCounter; ++i) {
    if(iV >= iMaxV) {
      iV = 0;
      ++iW;
    }
    if(iW >= iMaxW)
      iW = 0;
    BB_ASSERT(Squares::ValidVW(iV, iW))

    for(unsigned int j = CEffects::EffectSquareListHeadVW(iV, iW); j; j = m_uNextEffect) {
      m_uNextEffect = this->m_cEffects[j].m_uNextEffect;
      int iTick = this->m_cEffects[j].TimeIndex(this->m_sViewPortData.m_iTick);
      if(this->m_cEffects[j].IsOutOfDate(iTick))
        CEffects::MoveEffectFromSquareListToFreeList(j);
    }
    ++iV;
  }
  this->m_iMaxXY = Y16X16::PackXYFast(iV, iW);
}


// address=[0x144dbf0]
// Decompiled from void __thiscall CEffects::Release(CEffects *this)
void CEffects::Release(void) {
  // NOTE: this calls the virtual destructor in CBBObject...
}


// address=[0x144dc30]
// Decompiled from void *__thiscall CEffects::DbgCheckData(std::_Ref_count_base *this, const struct type_info *a2)
unsigned int CEffects::DbgCheckData(int a2) {
  return 0;
}


// address=[0x144dc40]
// Decompiled from void __thiscall CEffects::AddEffectToFreeList(CEffects *this, unsigned int _uEffectId)
void CEffects::AddEffectToFreeList(unsigned int _uEffectId) {
  // [esp+0h] [ebp-Ch]
  BB_ASSERT(_uEffectId >= FIRST_REAL_EFFECT)
  BB_ASSERT(_uEffectId < EFFECTS_MAX)

  CEffect &rEffect = this->m_cEffects[_uEffectId];
  BB_ASSERT(rEffect.m_uPrevEffect == 0)
  BB_ASSERT(rEffect.m_uNextEffect == 0)
  rEffect.m_uVisualizeFunc = 0;
  int uNextEffectId = this->m_cEffects[1].m_uNextEffect;
  this->m_cEffects[1].m_uNextEffect = _uEffectId;
  rEffect.m_uNextEffect = uNextEffectId;
  rEffect.m_uPrevEffect = 1;
  if(uNextEffectId) {
    BB_ASSERT(m_cEffects[uNextEffectId].m_uPrevEffect == FREE_EFFECTS_LIST_HEAD)
    this->m_cEffects[uNextEffectId].m_uPrevEffect = _uEffectId;
  }
}


// address=[0x144dda0]
// Decompiled from void __thiscall CEffects::AddEffectToSquareList(CEffects *this, unsigned int _uEffectId)
void CEffects::AddEffectToSquareList(unsigned int _uEffectId) {
  // [esp+4h] [ebp-14h]
  // [esp+8h] [ebp-10h]
  // [esp+10h] [ebp-8h]

  BB_ASSERT(_uEffectId >= FIRST_REAL_EFFECT)
  BB_ASSERT(_uEffectId < EFFECTS_MAX)

  CEffect &rEffect = this->m_cEffects[_uEffectId];
  if(!rEffect.m_uVisualizeFunc) {
    BB_REPORT("CEffects::AddEffectToSquareList(): Invalid visualize function!")
    rEffect.SetVisualizeFunc(VISUALIZE_FUNC_NOP_2);
  }
  BB_ASSERT(rEffect.m_uPrevEffect == 0)
  BB_ASSERT(rEffect.m_uNextEffect == 0)

  int iV = Squares::XYToVW(rEffect.m_iX);
  int iW = Squares::XYToVW(rEffect.m_iY);
  BB_ASSERT(Squares::ValidVW(iV, iW))
  unsigned __int16 &uHeadEffectId = CEffects::EffectSquareListHeadVW(iV, iW);

  int uOldHeadEffectId = uHeadEffectId;
  uHeadEffectId = _uEffectId;

  rEffect.m_uPrevEffect = 0;
  rEffect.m_uNextEffect = uOldHeadEffectId;
  if(uOldHeadEffectId) {
    BB_ASSERT(m_cEffects[uOldHeadEffectId].m_uPrevEffect == 0)
    this->m_cEffects[uOldHeadEffectId].m_uPrevEffect = _uEffectId;
  }
}


// address=[0x144df80]
// Decompiled from void __thiscall CEffects::RemoveEffectFromList(CEffects *this, unsigned int _uEffectId)
void CEffects::RemoveEffectFromList(unsigned int _uEffectId) {
  // [esp+4h] [ebp-10h]
  // [esp+8h] [ebp-Ch]

  BB_ASSERT(_uEffectId >= FIRST_REAL_EFFECT)
  BB_ASSERT(_uEffectId < EFFECTS_MAX)
  CEffect &rEffect = this->m_cEffects[_uEffectId];
  if(rEffect.m_uPrevEffect) {
    BB_ASSERT(m_cEffects[rEffect.m_uPrevEffect].m_uNextEffect == _uEffectId)
    this->m_cEffects[rEffect.m_uPrevEffect].m_uNextEffect = rEffect.m_uNextEffect;
  } else {
    int iV = Squares::XYToVW(rEffect.m_iX);
    int iW = Squares::XYToVW(rEffect.m_iY);
    BB_ASSERT(Squares::ValidVW(iV, iW))

    unsigned __int16 &rSquareListHead = CEffects::EffectSquareListHeadVW(iV, iW);
    BB_ASSERT(rSquareListHead == _uEffectId)
    rSquareListHead = rEffect.m_uNextEffect;
  }
  if(rEffect.m_uNextEffect) {
    BB_ASSERT(m_cEffects[rEffect.m_uNextEffect].m_uPrevEffect == _uEffectId)
    this->m_cEffects[rEffect.m_uNextEffect].m_uPrevEffect = rEffect.m_uPrevEffect;
  }
  rEffect.m_uPrevEffect = 0;
  rEffect.m_uNextEffect = 0;
}


// address=[0x144e170]
// Decompiled from void __thiscall CEffects::CleanUp(CEffects *this)
void CEffects::CleanUp(void) {
  // [esp+0h] [ebp-20h]
  // [esp+4h] [ebp-1Ch]
  // [esp+Ch] [ebp-14h]
  // [esp+10h] [ebp-10h]
  // [esp+18h] [ebp-8h]
  // [esp+1Fh] [ebp-1h]

  unsigned int TickCounter = g_pGame->GetTickCounter();
  this->m_iMaxXY = 0;
  this->m_iTickCounter = TickCounter;
  int v3 = 1;
  this->m_cEffects[1].m_uNextEffect = 0;
  for(unsigned int i = 2; i < EFFECTS_MAX; ++i) {
    CEffect &rEffect = this->m_cEffects[i];
    bool     v7 = rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_NOP_1;
    if(rEffect.m_uVisualizeFunc) {
      int v1 = rEffect.TimeIndex(TickCounter);
      if(rEffect.IsOutOfDate(v1)) {
        CEffects::RemoveEffectFromList(i);
        v7 = 1;
      }
    }
    if(v7) {
      memset(&rEffect, 0, sizeof(CEffect));
      this->m_cEffects[i].m_uPrevEffect = v3;
      this->m_cEffects[v3].m_uNextEffect = i;
      v3 = i;
    }
  }
}


// address=[0x144f340]
// Decompiled from bool __thiscall CEffects::CheckParentEffect(CEffects *this, unsigned int a2)
bool CEffects::CheckParentEffect(unsigned int a2) {
  return a2
         && a2 < 0x1000
         && this->m_cEffects[a2].m_uVisualizeFunc
         && this->m_cEffects[a2].m_uVisualizeFunc != VISUALIZE_FUNC_ATTACHED_EFFECT;
}


// address=[0x144f3b0]
// Decompiled from void __cdecl CEffects::ClipXOrY(int *a1)
void __cdecl CEffects::ClipXOrY(int &a1) {
  if(a1 >= 0) {
    if(a1 > 1023)
      a1 = 1023;
  } else {
    a1 = 0;
  }
}


// address=[0x144f3f0]
// Decompiled from void __thiscall CEffects::DecreaseMovingEffectCounter(CEffects *this, unsigned int _iEffect)
void CEffects::DecreaseMovingEffectCounter(int _iEffect) {
  if(_iEffect < 0x74) {
    BB_ASSERT(m_iMovingEffectCounters[_iEffect] > 0)
    this->m_iMovingEffectCounters[_iEffect] -= this->m_iMovingEffectCounters[_iEffect] > 0;
  }
}


// address=[0x144f4a0]
// Decompiled from unsigned __int16 *__thiscall CEffects::EffectSquareListHeadVW(CEffects *this, int a2, int a3)
unsigned short &CEffects::EffectSquareListHeadVW(int a2, int a3) {
  return this->m_uEffectSquareListHeadVW[a3][a2];
}


// address=[0x144f4d0]
// Decompiled from int __thiscall CEffects::FirstFreeEffectId(CEffects *this)
unsigned int CEffects::FirstFreeEffectId(void) {
  return this->m_cEffects[1].m_uNextEffect;
}


// address=[0x144f650]
// Decompiled from void __thiscall CEffects::IncreaseMovingEffectCounter(CEffects *this, unsigned int a2)
void CEffects::IncreaseMovingEffectCounter(int a2) {
  if(a2 < 116)
    ++this->m_iMovingEffectCounters[a2];
}


// address=[0x144f6d0]
// Decompiled from void __thiscall CEffects::MoveEffectFromSquareListToFreeList(CEffects *this, unsigned int a2)
void CEffects::MoveEffectFromSquareListToFreeList(unsigned int a2) {
  CEffects::RemoveEffectFromList(a2);
  CEffects::AddEffectToFreeList(a2);
}


// address=[0x3f11f68]
// [Decompilation failed for static struct SGfxObjectInfo CEffects::m_sGfxInfo]
