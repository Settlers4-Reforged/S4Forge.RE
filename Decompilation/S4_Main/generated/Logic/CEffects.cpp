#if FALSE
#include "CEffects.h"

// Definitions for class CEffects

// address=[0x144bfb0]
// Decompiled from CEffects *__thiscall CEffects::CEffects(CEffects *this)
 CEffects::CEffects(void) {
  
  unsigned int i; // [esp+4h] [ebp-14h]

  IEffects::IEffects(this);
  CBBObject::CBBObject(&this->CBBObject, (int)"CEffects", 1);
  this->IEffects::IGfxEffects::__vftable = (CEffects_vtbl *)&CEffects::_vftable_;
  this->IEffects::IS4ChunkObject::__vftable = (IS4ChunkObject_vtbl *)&CEffects::`vftable';
  this->vtable = &CEffects::`vftable';
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
  for ( i = 3; i < 0xFFF; ++i )
  {
    this->m_cEffects[i].m_uPrevEffect = i - 1;
    this->m_cEffects[i].m_uNextEffect = i + 1;
  }
  this->m_cEffects[4095].m_uPrevEffect = 4094;
  this->m_cEffects[4095].m_uNextEffect = 0;
  this->m_iMaxXY = 0;
  this->m_iTickCounter = 0;
  memset(this->m_iMovingEffectCounters, 0, sizeof(this->m_iMovingEffectCounters));
  memset(&CEffects::m_sGfxInfo, 0, sizeof(CEffects::m_sGfxInfo));
  if ( !g_pGfxEngine && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1696, "g_pGfxEngine != 0") == 1 )
    __debugbreak();
  IGfxEngine::SetEffectSystemInterfacePtr(g_pGfxEngine, this);
  return this;
}


// address=[0x144c200]
// Decompiled from void __thiscall CEffects::~CEffects(CEffects *this)
 CEffects::~CEffects(void) {
  
  *(_DWORD *)this = &CEffects::_vftable_;
  *((_DWORD *)this + 1) = &CEffects::`vftable';
  *((_DWORD *)this + 2) = &CEffects::`vftable';
  if ( g_pGfxEngine )
    IGfxEngine::SetEffectSystemInterfacePtr((IGfxEngine *)g_pGfxEngine, 0);
  CBBObject::~CBBObject((CEffects *)((char *)this + 8));
}


// address=[0x144c280]
// Decompiled from CEffects *__thiscall CEffects::SetEffectsViewport(CEffects *this, int _iX0, int _iY0, int _iX1, int _iY1, int _iX2)
void  CEffects::SetEffectsViewport(int _iX0, int _iY0, int _iX1, int _iY1, int _iX2) {
  
  CEffects *result; // eax

  CEffects::ClipXOrY(&_iX0);
  CEffects::ClipXOrY(&_iY0);
  CEffects::ClipXOrY(&_iX1);
  CEffects::ClipXOrY(&_iY1);
  CEffects::ClipXOrY(&_iX2);
  if ( _iX0 > _iX1 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1731, "_iX0 <= _iX1") == 1 )
    __debugbreak();
  if ( _iX1 > _iX2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1732, "_iX1 <= _iX2") == 1 )
    __debugbreak();
  if ( _iY0 > _iY1 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1733, "_iY0 <= _iY1") == 1 )
    __debugbreak();
  this->m_sViewPortData.m_iViewX0 = _iX0;
  this->m_sViewPortData.m_iViewY0 = _iY0;
  this->m_sViewPortData.m_iViewX1 = _iX1;
  this->m_sViewPortData.m_iViewY1 = _iY1;
  this->m_sViewPortData.m_iViewX2 = _iX2;
  this->m_sViewPortData.m_iTick = CStateGame::GetTickCounter(g_pGame);
  this->m_sViewPortData.m_iCurrentY = -1;
  result = this;
  this->m_sViewPortData.m_uU1C = -1;
  this->m_sViewPortData.m_uU20 = 0;
  return result;
}


// address=[0x144c3a0]
// Decompiled from int __thiscall CEffects::FirstEffect(CEffects *this, int _iY)
struct SGfxObjectInfo *  CEffects::FirstEffect(int _iY) {
  
  unsigned int m_uNextEffect; // [esp+0h] [ebp-34h]
  unsigned int v4; // [esp+8h] [ebp-2Ch]
  int tSoundId; // [esp+Ch] [ebp-28h]
  int v6; // [esp+10h] [ebp-24h]
  int v7; // [esp+14h] [ebp-20h]
  int v8; // [esp+18h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-18h]
  signed int iVRight; // [esp+20h] [ebp-14h]
  int iVLeft; // [esp+24h] [ebp-10h]
  unsigned int j; // [esp+28h] [ebp-Ch]
  CEffect *v13; // [esp+2Ch] [ebp-8h]

  if ( _iY < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1755, "_iY >= 0") == 1 )
    __debugbreak();
  if ( _iY >= 1024
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1756, "_iY < Squares::SQUARE_MAX_SUPPORTED_MAP_WIDTH_HEIGHT") == 1 )
  {
    __debugbreak();
  }
  if ( _iY < this->m_sViewPortData.m_iViewY0
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1758, "_iY >= m_sViewPortData.m_iViewY0") == 1 )
  {
    __debugbreak();
  }
  if ( _iY > this->m_sViewPortData.m_iViewY1
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1759, "_iY <= m_sViewPortData.m_iViewY1") == 1 )
  {
    __debugbreak();
  }
  if ( _iY <= this->m_sViewPortData.m_iCurrentY
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1761, "_iY > m_sViewPortData.m_iCurrentY") == 1 )
  {
    __debugbreak();
  }
  v7 = Squares::XYToVW(_iY);
  if ( v7 != this->m_sViewPortData.m_uU1C )
  {
    this->m_sViewPortData.m_uU1C = v7;
    iVLeft = Squares::XYToVW(this->m_sViewPortData.m_iViewX0);
    iVRight = Squares::XYToVW(this->m_sViewPortData.m_iViewX2);
    if ( !Squares::ValidVW(iVLeft) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1772, "Squares::ValidVW(iVLeft)") == 1 )
      __debugbreak();
    if ( !Squares::ValidVW(iVRight)
      && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1773, "Squares::ValidVW(iVRight)") == 1 )
    {
      __debugbreak();
    }
    if ( iVLeft > 0 )
      --iVLeft;
    if ( iVRight < 63 )
      ++iVRight;
    memset(this->m_sViewPortData.m_iMaxRows, 0, sizeof(this->m_sViewPortData.m_iMaxRows));
    for ( i = iVLeft; i <= iVRight; ++i )
    {
      for ( j = *CEffects::EffectSquareListHeadVW(this, i, v7); j; j = m_uNextEffect )
      {
        v13 = &this->m_cEffects[j];
        m_uNextEffect = this->m_cEffects[j].m_uNextEffect;
        v6 = CEffect::TimeIndex(v13, this->m_sViewPortData.m_iTick);
        if ( v6 >= 0 )
        {
          if ( CEffect::IsOutOfDate(v13, v6) )
            goto LABEL_40;
          tSoundId = this->m_cEffects[j].m_tSoundId;
          if ( this->m_cEffects[j].m_tSoundId )
          {
            this->m_cEffects[j].m_tSoundId = 0;
            if ( !v6 )
              CSoundManager::PlayEnvironmentSound(
                g_pSoundManager,
                tSoundId,
                this->m_cEffects[j].uAngel.m_iX,
                this->m_cEffects[j].uAngel.m_iY,
                0);
          }
          if ( !this->m_cEffects[j].m_iEffect )
          {
LABEL_40:
            CEffects::MoveEffectFromSquareListToFreeList(this, j);
          }
          else
          {
            v8 = CEffect::SquareRow(v13);
            v4 = this->m_sViewPortData.m_iMaxRows[v8];
            if ( v4 < 64 )
            {
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
  return this->NextEffect(this);
}


// address=[0x144c6e0]
// Decompiled from SGfxObjectInfo *__thiscall CEffects::NextEffect(CEffects *this)
struct SGfxObjectInfo *  CEffects::NextEffect(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-18h]
  DWORD m_iTimeIdxMax; // [esp+8h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-Ch]
  CEffect *rEffect; // [esp+10h] [ebp-8h]

  if ( this->m_sViewPortData.m_iCurrentY < 0
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1855, "m_sViewPortData.m_iCurrentY >= 0") == 1 )
  {
    __debugbreak();
  }
  v7 = this->m_sViewPortData.m_iCurrentY & 0xF;
  if ( this->m_sViewPortData.m_uU20 >= this->m_sViewPortData.m_iMaxRows[v7] )
    return 0;
  v5 = this->m_sViewPortData.m_iRows[v7][this->m_sViewPortData.m_uU20++];
  rEffect = &this->m_cEffects[v5];
  CEffects::m_sGfxInfo.m_bIsVisible = 1;
  CEffects::m_sGfxInfo.m_iZOrdering = 0;
  if ( rEffect->m_uVisualizeFunc == VISUALIZE_FUNC_ATTACHED_EFFECT )
  {
    m_iTimeIdxMax = this->m_cEffects[v5].uAngel.m_iTimeIdxMax;
    if ( !CEffects::CheckParentEffect(this, m_iTimeIdxMax) )
      return 0;
    v2 = CEffect::TimeIndex(&this->m_cEffects[m_iTimeIdxMax], this->m_sViewPortData.m_iTick);
    CEffect::Visualize(&this->m_cEffects[m_iTimeIdxMax], &CEffects::m_sGfxInfo, v2);
    v3 = CEffect::TimeIndex(rEffect, this->m_sViewPortData.m_iTick);
    CEffect::Visualize(rEffect, &CEffects::m_sGfxInfo, v3);
  }
  else
  {
    v4 = CEffect::TimeIndex(rEffect, this->m_sViewPortData.m_iTick);
    CEffect::Visualize(rEffect, &CEffects::m_sGfxInfo, v4);
  }
  if ( !CWorldManager::InWorld(this->m_cEffects[v5].uAngel.m_iX, this->m_cEffects[v5].uAngel.m_iY)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1890, "g_cWorld.InWorld(rEffect.m_iX, rEffect.m_iY)") == 1 )
  {
    __debugbreak();
  }
  CEffects::m_sGfxInfo.m_iEffectX = this->m_cEffects[v5].uAngel.m_iX;
  CEffects::m_sGfxInfo.m_iEffectY = this->m_cEffects[v5].uAngel.m_iY;
  return &CEffects::m_sGfxInfo;
}


// address=[0x144c880]
// Decompiled from void __thiscall CEffects::Load(CEffects *__shifted(CEffects,4) this, struct IS4Chunk *a2)
void  CEffects::Load(class IS4Chunk & a2) {
  
  T_S4_VISUALIZE_FUNC fpVisFunc; // eax
  CEffect *rEffect; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+4h] [ebp-8h]

  memset(&ADJ(this)->m_sViewPortData, 0, sizeof(ADJ(this)->m_sViewPortData));
  ADJ(this)->m_sViewPortData.m_iCurrentY = -1;
  ADJ(this)->m_sViewPortData.m_uU1C = -1;
  a2->LoadSignature(-1824106861);
  a2->LoadUnsigned32(1, 1);
  a2->LoadUnsigned32(4096, 4096);
  a2->LoadUnsigned32(60, 60);
  a2->LoadUnsigned32_(a2);
  a2->Load(ADJ(this)->m_uEffectSquareListHeadVW, 8448);
  a2->Load(ADJ(this)->m_cEffects, 245760);
  ADJ(this)->m_iMaxXY = 0;
  ADJ(this)->m_iTickCounter = 0;
  memset(ADJ(this)->m_iMovingEffectCounters, 0, sizeof(ADJ(this)->m_iMovingEffectCounters));
  memset(&CEffects::m_sGfxInfo, 0, sizeof(CEffects::m_sGfxInfo));
  for ( i = 2; i < 0x1000; ++i )
  {
    rEffect = (CEffect *)(&ADJ(this)->IS4ChunkObject + 15 * i + 0x106E);
    fpVisFunc = CEffect::VisualizeFunc(rEffect);
    CEffect::SetVisualizeFunc(rEffect, fpVisFunc);
    if ( CEffect::VisualizeFunc(rEffect) == VISUALIZE_FUNC_MOVING_EFFECT )
      CEffects::IncreaseMovingEffectCounter(
        ADJ(this),
        *((unsigned __int8 *)&ADJ(this)->IS4ChunkObject + 60 * i + 0x41B9));// _iEffect
  }
  a2->LoadSignature(1452512070);
}


// address=[0x144ca00]
// Decompiled from void __thiscall CEffects::Save(CEffects *__shifted(CEffects,4) this, struct IS4Chunk *a2)
void  CEffects::Save(class IS4Chunk & a2) {
  
  if ( ADJ(this)->m_iTickCounter < (unsigned int)CStateGame::GetTickCounter(g_pGame) )
    CEffects::CleanUp(ADJ(this));
  a2->SaveSignature(-1824106861);
  a2->SaveUnsigned32(1);
  a2->SaveUnsigned32(4096);
  a2->SaveUnsigned32(60);
  a2->SaveUnsigned32(245760);
  a2->Save(ADJ(this)->m_uEffectSquareListHeadVW, 0x2100u);
  a2->Save(ADJ(this)->m_cEffects, 0x3C000u);
  a2->SaveSignature(1452512070);
}


// address=[0x144cae0]
// Decompiled from uint __thiscall CEffects::AddEffect(  CEffects *this,  int _iEffect,  enum SIV_SOUNDS _tSound,  int iX,  int iY,  unsigned int _uStartDelay,  int _iDuration,  bool bTopEffect)
unsigned int  CEffects::AddEffect(int _iEffect, enum SIV_SOUNDS _tSound, int iX, int iY, unsigned int _uStartDelay, int _iDuration, bool bTopEffect) {
  
  unsigned int FreeEffectId; // [esp+10h] [ebp-4h]

  if ( CWorldManager::InWorld(iX, iY) )
  {
    FreeEffectId = CEffects::FirstFreeEffectId(this);
    if ( FreeEffectId )
    {
      CEffects::RemoveEffectFromList(this, FreeEffectId);
      CEffect::InitEffect(
        &this->m_cEffects[FreeEffectId],
        _iEffect,
        _tSound,
        iX,
        iY,
        _uStartDelay,
        _iDuration,
        bTopEffect);
      CEffects::AddEffectToSquareList(this, FreeEffectId);
      return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + _uStartDelay;// Just duration
    }
    else if ( _uStartDelay )
    {
      return _uStartDelay;
    }
    else
    {
      return 1;
    }
  }
  else if ( _uStartDelay )
  {
    return _uStartDelay;
  }
  else
  {
    return 1;
  }
}


// address=[0x144cbb0]
// Decompiled from unsigned int __thiscall CEffects::AddAngel(  CEffects *this,  int _tAngel,  BYTE tSoundId,  unsigned int _iX,  unsigned int _iY,  int _iPlayerId,  unsigned int _uStartDelay)
unsigned int  CEffects::AddAngel(enum T_EFFECT_ANGEL _tAngel, enum SIV_SOUNDS tSoundId, int _iX, int _iY, int _iPlayerId, unsigned int _uStartDelay) {
  
  unsigned int FreeEffectId; // [esp+10h] [ebp-4h]

  if ( _tAngel > 3 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2361, "_tAngel <= EFFECT_ANGEL_LAST") == 1 )
    __debugbreak();
  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2362, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( !CPlayerManager::ValidUsedPlayerId(_iPlayerId)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2363, "g_cPlayerMgr.ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( _uStartDelay >= 0x400 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2364, "_uStartDelay < 1024") == 1 )
    __debugbreak();
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( FreeEffectId == 0 || _tAngel == 0 )
    return _uStartDelay;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitAngel(&this->m_cEffects[FreeEffectId], _tAngel, tSoundId, _iX, _iY, _iPlayerId, _uStartDelay);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + _uStartDelay;
}


// address=[0x144cd20]
// Decompiled from unsigned int __thiscall CEffects::AddMissile(  CEffects *this,  int _tMissile,  int _iAttackerXY,  int _iTargetXY,  unsigned int _uStartDelay,  int _iTargetOffsetX,  int _iTargetOffsetY)
unsigned int  CEffects::AddMissile(enum T_EFFECT_MISSILE _tMissile, int _iAttackerXY, int _iTargetXY, unsigned int _uStartDelay, int _iTargetOffsetX, int _iTargetOffsetY) {
  
  unsigned int FreeEffectId; // [esp+8h] [ebp-4h]

  if ( _tMissile > 10 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2260, "_tMissile <= EFFECT_MISSILE_LAST") == 1 )
    __debugbreak();
  if ( !CWorldManager::InWorldPackedXY(_iAttackerXY)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2261, "g_cWorld.InWorldPackedXY(_iAttackerXY)") == 1 )
  {
    __debugbreak();
  }
  if ( !CWorldManager::InWorldPackedXY(_iTargetXY)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2262, "g_cWorld.InWorldPackedXY(_iTargetXY)") == 1 )
  {
    __debugbreak();
  }
  if ( _uStartDelay >= 0x400 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2263, "_uStartDelay < 1024") == 1 )
    __debugbreak();
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( !FreeEffectId )
    return _uStartDelay;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitMissile(
    &this->m_cEffects[FreeEffectId],
    _tMissile,
    _iAttackerXY,
    _iTargetXY,
    _uStartDelay,
    _iTargetOffsetX,
    _iTargetOffsetY);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + _uStartDelay;
}


// address=[0x144ce50]
// Decompiled from unsigned int __thiscall CEffects::AddSporeCloud(CEffects *this, int _iSrcXY, int _iDstXY, unsigned int _uStartDelay)
unsigned int  CEffects::AddSporeCloud(int _iSrcXY, int _iDstXY, unsigned int _uStartDelay) {
  
  int iX; // [esp+0h] [ebp-14h]
  int iY; // [esp+4h] [ebp-10h]
  unsigned int FreeEffectId; // [esp+Ch] [ebp-8h]
  unsigned int iNextTick; // [esp+24h] [ebp+10h]

  if ( !CWorldManager::InWorldPackedXY(_iSrcXY)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2292, "g_cWorld.InWorldPackedXY(_iSrcXY)") == 1 )
  {
    __debugbreak();
  }
  if ( !CWorldManager::InWorldPackedXY(_iDstXY)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2293, "g_cWorld.InWorldPackedXY(_iDstXY)") == 1 )
  {
    __debugbreak();
  }
  if ( _uStartDelay >= 0x400 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2294, "_uStartDelay < 1024") == 1 )
    __debugbreak();
  iX = Y16X16::UnpackXFast(_iSrcXY);
  iY = Y16X16::UnpackYFast(_iSrcXY);
  iNextTick = this->AddEffect(this, 20, 0, iX, iY, _uStartDelay, 0, 0);
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( !FreeEffectId )
    return iNextTick;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitSporeCloud(&this->m_cEffects[FreeEffectId], _iSrcXY, _iDstXY, iNextTick);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + iNextTick;
}


// address=[0x144cf90]
// Decompiled from unsigned int __thiscall CEffects::AddStagnantAnimal(  CEffects *this,  signed int _tAnimalJob,  char a3,  unsigned int _iX,  unsigned int _iY,  unsigned int iDir,  unsigned int _uStartDelay)
unsigned int  CEffects::AddStagnantAnimal(enum SIV_ANIMALS _tAnimalJob, enum SIV_SOUNDS a3, int _iX, int _iY, int iDir, unsigned int _uStartDelay) {
  
  unsigned int FreeEffectId; // [esp+8h] [ebp-4h]

  if ( !_tAnimalJob && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2328, "_tAnimalJob != ANIMAL_NO_ANIMAL_WALK") == 1 )
    __debugbreak();
  if ( _tAnimalJob >= 42 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2329, "_tAnimalJob < SIV_ANIMAL_MAX") == 1 )
    __debugbreak();
  if ( iDir >= 6 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2330, "(_iDir >= 0) && (_iDir < 6)") == 1 )
    __debugbreak();
  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2331, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _uStartDelay >= 0x400 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2332, "_uStartDelay < 1024") == 1 )
    __debugbreak();
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( !FreeEffectId )
    return _uStartDelay;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitStagnantAnimal(&this->m_cEffects[FreeEffectId], _tAnimalJob, a3, _iX, _iY, iDir, _uStartDelay);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return this->m_cEffects[FreeEffectId].uAngel.m_iDuration + _uStartDelay;
}


// address=[0x144d0f0]
// Decompiled from void __thiscall CEffects::DeleteEffect(CEffects *this, unsigned int _uEffectId)
void  CEffects::DeleteEffect(unsigned int _uEffectId) {
  
  if ( (!_uEffectId || _uEffectId >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2395, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( _uEffectId && _uEffectId < 0x1000 && this->m_cEffects[_uEffectId].m_uVisualizeFunc )
  {
    if ( this->m_cEffects[_uEffectId].m_uVisualizeFunc == 8 )
      CEffects::DecreaseMovingEffectCounter(this, this->m_cEffects[_uEffectId].m_iEffect);
    CEffects::MoveEffectFromSquareListToFreeList(this, _uEffectId);
  }
}


// address=[0x144d180]
// Decompiled from unsigned int __thiscall CEffects::CreateMovingEffect(CEffects *this, int _iEffect, int a3, int a4)
unsigned int  CEffects::CreateMovingEffect(int _iEffect, int a3, int a4) {
  
  unsigned int FreeEffectId; // [esp+4h] [ebp-8h]

  if ( (_iEffect <= EFFECT_NO_EFFECT || _iEffect >= EFFECT_MAX)
    && (_iEffect <= EFFECT_2_NO_EFFECT || _iEffect >= EFFECT_2_MAX)
    && BBSupportDbgReport(
         2,
         "Logic\\Effects.cpp",
         2420,
         "((_iEffect > EFFECT_NO_EFFECT) && (_iEffect < EFFECT_MAX)) || ((_iEffect > EFFECT_2_NO_EFFECT) && (_iEffect < EFFECT_2_MAX))") == 1 )
  {
    __debugbreak();
  }
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( !FreeEffectId )
    return FreeEffectId;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitMovingEffect(&this->m_cEffects[FreeEffectId], _iEffect, a3, a4);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  CEffects::IncreaseMovingEffectCounter(this, _iEffect);
  return FreeEffectId;
}


// address=[0x144d230]
// Decompiled from void __thiscall CEffects::ChangeMovingEffectType(CEffects *this, unsigned int _uEffectId, unsigned int _iEffect)
void  CEffects::ChangeMovingEffectType(unsigned int _uEffectId, int _iEffect) {
  
  CEffect *rEffect; // [esp+Ch] [ebp-4h]

  if ( (!_uEffectId || _uEffectId >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2447, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( _iEffect < EFFECT_MAX && _uEffectId != 0 )
  {
    rEffect = &this->m_cEffects[_uEffectId];
    if ( rEffect->m_uVisualizeFunc != VISUALIZE_FUNC_MOVING_EFFECT
      && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2453, "rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT") == 1 )
    {
      __debugbreak();
    }
    if ( rEffect->m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT )
    {
      CEffects::DecreaseMovingEffectCounter(this, this->m_cEffects[_uEffectId].m_iEffect);
      CEffects::IncreaseMovingEffectCounter(this, _iEffect);
      this->m_cEffects[_uEffectId].m_iEffect = _iEffect;
      this->m_cEffects[_uEffectId].uAngel.m_uFramesMax = CEffect::GetEffectNumberOfFrames(_iEffect);
      this->m_cEffects[_uEffectId].uAngel.m_iFrame = 0;
    }
  }
}


// address=[0x144d330]
// Decompiled from int __thiscall CEffects::NumberOfMovingEffects(CEffects *this, DWORD _tEffect)
int  CEffects::NumberOfMovingEffects(int _tEffect) {
  
  if ( _tEffect >= EFFECT_MAX
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2475, "static_cast<unsigned int>(_tEffect) < EFFECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iMovingEffectCounters[_tEffect] < 0
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2477, "m_iMovingEffectCounters[_tEffect] >= 0") == 1 )
  {
    __debugbreak();
  }
  return this->m_iMovingEffectCounters[_tEffect];
}


// address=[0x144d3a0]
// Decompiled from void __thiscall CEffects::GetMovingEffectInfo(  CEffects *this,  unsigned int _uEffectId,  int *_rEffect,  int *_rX,  int *_rY,  int *_rDir)
void  CEffects::GetMovingEffectInfo(unsigned int _uEffectId, int & _rEffect, int & _rX, int & _rY, int & _rDir) {
  
  int iTick; // [esp+4h] [ebp-14h]
  unsigned int TickCounter; // [esp+8h] [ebp-10h]
  int uDelay; // [esp+Ch] [ebp-Ch]

  if ( (!_uEffectId || _uEffectId >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2489, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_cEffects[_uEffectId].m_uVisualizeFunc != 8
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2493, "rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT") == 1 )
  {
    __debugbreak();
  }
  *_rEffect = this->m_cEffects[_uEffectId].m_iEffect;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( TickCounter < this->m_cEffects[_uEffectId].uMoving.m_iNextTick )
    iTick = 0;
  else
    iTick = TickCounter - this->m_cEffects[_uEffectId].uMoving.m_iNextTick;
  uDelay = this->m_cEffects[_uEffectId].m_uDelay;
  if ( iTick < uDelay )
  {
    if ( iTick <= 0 )
    {
      *_rX = this->m_cEffects[_uEffectId].uMoving.m_iX;
      *_rY = this->m_cEffects[_uEffectId].uMoving.m_iY;
    }
    else
    {
      *_rX = this->m_cEffects[_uEffectId].uMoving.m_iX
           + iTick
           * (this->m_cEffects[_uEffectId].uMoving.m_iStartX - this->m_cEffects[_uEffectId].uMoving.m_iX)
           / uDelay;
      *_rY = this->m_cEffects[_uEffectId].uMoving.m_iY
           + iTick
           * (this->m_cEffects[_uEffectId].uMoving.m_iStartY - this->m_cEffects[_uEffectId].uMoving.m_iY)
           / uDelay;
    }
  }
  else
  {
    *_rX = this->m_cEffects[_uEffectId].uMoving.m_iStartX;
    *_rY = this->m_cEffects[_uEffectId].uMoving.m_iStartY;
  }
  *_rDir = this->m_cEffects[_uEffectId].uMoving.m_iDir;
}


// address=[0x144d4f0]
// Decompiled from void __thiscall CEffects::SetMovingEffectSpeed(CEffects *this, unsigned int _uEffectId, int _iSpeed)
void  CEffects::SetMovingEffectSpeed(unsigned int _uEffectId, int _iSpeed) {
  
  if ( _uEffectId
    && _uEffectId < 0x1000
    && this->m_cEffects[_uEffectId].m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT )
  {
    if ( _iSpeed >= 10 )
    {
      if ( _iSpeed > 500 )
        _iSpeed = 500;
    }
    else
    {
      _iSpeed = 10;
    }
    this->m_cEffects[_uEffectId].uMoving.m_uSpeed = _iSpeed;
  }
}


// address=[0x144d560]
// Decompiled from int __thiscall CEffects::SetMovingEffectDestination(CEffects *this, unsigned int _uEffectId, int a3, int a4, int a5)
unsigned int  CEffects::SetMovingEffectDestination(unsigned int _uEffectId, int a3, int a4, int a5) {
  
  int v6; // [esp+0h] [ebp-Ch]
  CEffect *rEffect; // [esp+4h] [ebp-8h]

  if ( (!_uEffectId || _uEffectId >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2551, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  v6 = 0;
  if ( !_uEffectId )
    return v6;
  CEffects::RemoveEffectFromList(this, _uEffectId);
  rEffect = &this->m_cEffects[_uEffectId];
  if ( rEffect->m_uVisualizeFunc != 8
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2561, "rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT") == 1 )
  {
    __debugbreak();
  }
  v6 = CEffect::SetNewDestinationForMovingEffect(rEffect, a3, a4, a5);
  CEffects::AddEffectToSquareList(this, _uEffectId);
  return v6;
}


// address=[0x144d620]
// Decompiled from int __thiscall CEffects::GetMovingEffectDirection(CEffects *this, unsigned int a2)
int  CEffects::GetMovingEffectDirection(unsigned int a2) {
  
  int v3; // [esp+4h] [ebp-8h]

  if ( !a2 || a2 >= 0x1000 )
    return 0;
  v3 = 0;
  if ( this->m_cEffects[a2].m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT )
    return this->m_cEffects[a2].uMoving.m_iDir;
  return v3;
}


// address=[0x144d680]
// Decompiled from void __thiscall CEffects::SetMovingEffectDirection(CEffects *this, unsigned int _iEffectId, int _iDir)
void  CEffects::SetMovingEffectDirection(unsigned int _iEffectId, int _iDir) {
  
  if ( _iEffectId
    && _iEffectId < 0x1000
    && this->m_cEffects[_iEffectId].m_uVisualizeFunc == 8
    && this->m_cEffects[_iEffectId].uMoving.m_iMaxDir > 1u
    && _iDir >= 0 )
  {
    this->m_cEffects[_iEffectId].uMoving.m_iDir = _iDir % this->m_cEffects[_iEffectId].uMoving.m_iMaxDir;
  }
}


// address=[0x144d6f0]
// Decompiled from int __thiscall CEffects::GetMovingEffectSoundId(CEffects *this, unsigned int _uEffectId)
int  CEffects::GetMovingEffectSoundId(unsigned int _uEffectId) {
  
  if ( (!_uEffectId || _uEffectId >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2637, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  return this->m_iMovingEffectSoundId[_uEffectId];
}


// address=[0x144d740]
// Decompiled from void __thiscall CEffects::SetMovingEffectSoundId(CEffects *this, unsigned int _uEffectId, int _tSoundId)
void  CEffects::SetMovingEffectSoundId(unsigned int _uEffectId, int _tSoundId) {
  
  if ( (!_uEffectId || _uEffectId >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2625, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  this->m_iMovingEffectSoundId[_uEffectId] = _tSoundId;
}


// address=[0x144d790]
// Decompiled from unsigned int __thiscall CEffects::CreateAttachedEffect(CEffects *this, int a2, unsigned int a3, char a4)
unsigned int  CEffects::CreateAttachedEffect(int a2, unsigned int a3, int a4) {
  
  unsigned int FreeEffectId; // [esp+8h] [ebp-8h]

  if ( (a2 <= 0 || a2 >= 86)
    && (a2 <= 100 || a2 >= 116)
    && BBSupportDbgReport(
         2,
         "Logic\\Effects.cpp",
         2650,
         "(_iEffectType > EFFECT_NO_EFFECT) && (_iEffectType < EFFECT_MAX) || (_iEffectType > EFFECT_2_NO_EFFECT && _iEff"
         "ectType < EFFECT_2_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( !CEffects::CheckParentEffect(this, a3) )
    return 0;
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( !FreeEffectId )
    return FreeEffectId;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitAttachedEffect(&this->m_cEffects[FreeEffectId], a2, a3, &this->m_cEffects[a3], a4);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return FreeEffectId;
}


// address=[0x144d860]
// Decompiled from void __thiscall CEffects::SetAttachedEffectOffset(CEffects *this, unsigned int a2, float a3, float a4)
void  CEffects::SetAttachedEffectOffset(unsigned int a2, float a3, float a4) {
  
  if ( a2 && a2 < 0x1000 && this->m_cEffects[a2].m_uVisualizeFunc == VISUALIZE_FUNC_ATTACHED_EFFECT )
  {
    this->m_cEffects[a2].uAttached.m_fOffsetX = a3;
    this->m_cEffects[a2].uAttached.m_fOffsetY = a4;
  }
}


// address=[0x144d8c0]
// Decompiled from void __thiscall CEffects::UpdateAttachedEffect(CEffects *this, unsigned int _uEffectId)
void  CEffects::UpdateAttachedEffect(unsigned int _uEffectId) {
  
  const struct CEffect *rParent; // [esp+0h] [ebp-Ch]
  CEffect *rEffect; // [esp+4h] [ebp-8h]

  if ( _uEffectId )
  {
    if ( _uEffectId < 0x1000 )
    {
      rEffect = &this->m_cEffects[_uEffectId];
      if ( rEffect->m_uVisualizeFunc == VISUALIZE_FUNC_ATTACHED_EFFECT
        && CEffects::CheckParentEffect(this, this->m_cEffects[_uEffectId].uAttached.m_iParentId) )
      {
        rParent = &this->m_cEffects[this->m_cEffects[_uEffectId].uAttached.m_iParentId];
        CEffects::RemoveEffectFromList(this, _uEffectId);
        CEffect::UpdateAttachedEffect(rEffect, rParent);
        CEffects::AddEffectToSquareList(this, _uEffectId);
      }
    }
  }
}


// address=[0x144d950]
// Decompiled from bool __thiscall CEffects::WasAttachedEffectVisible(CEffects *this, unsigned int a2)
bool  CEffects::WasAttachedEffectVisible(unsigned int a2) {
  
  bool m_bProcessed; // [esp+Bh] [ebp-1h]

  if ( !a2 || a2 >= 0x1000 )
    return 0;
  m_bProcessed = 0;
  if ( this->m_cEffects[a2].m_uVisualizeFunc != VISUALIZE_FUNC_ATTACHED_EFFECT )
    return m_bProcessed;
  m_bProcessed = this->m_cEffects[a2].uAttached.m_bProcessed;
  this->m_cEffects[a2].uAttached.m_bProcessed = 0;
  return m_bProcessed;
}


// address=[0x144d9b0]
// Decompiled from void __thiscall CEffects::Execute(CEffects *this)
void  CEffects::Execute(void) {
  
  int iWidth; // eax
  int iHeight; // eax
  unsigned int m_uNextEffect; // [esp+0h] [ebp-2Ch]
  int iTick; // [esp+4h] [ebp-28h]
  int iMaxCounter; // [esp+8h] [ebp-24h]
  int i; // [esp+10h] [ebp-1Ch]
  unsigned int j; // [esp+14h] [ebp-18h]
  int iMaxW; // [esp+18h] [ebp-14h]
  int iMaxV; // [esp+1Ch] [ebp-10h]
  int iV; // [esp+24h] [ebp-8h]
  int iW; // [esp+28h] [ebp-4h]

  iWidth = CWorldManager::Width();
  iMaxW = Squares::XYToVW(iWidth);
  iHeight = CWorldManager::Height();
  iMaxV = Squares::XYToVW(iHeight);
  if ( iMaxV <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2765, "iMaxV > 0") == 1 )
    __debugbreak();
  if ( iMaxW <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2766, "iMaxW > 0") == 1 )
    __debugbreak();
  if ( iMaxV > 64 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2768, "iMaxV <= Squares::SQUARE_GRID_MAX_V_W") == 1 )
    __debugbreak();
  if ( iMaxW > 64 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2769, "iMaxW <= Squares::SQUARE_GRID_MAX_V_W") == 1 )
    __debugbreak();
  iMaxCounter = (iMaxW * iMaxV + 31) / 32;
  if ( iMaxCounter <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2773, "iMaxCounter > 0") == 1 )
    __debugbreak();
  iV = Y16X16::UnpackXFast(this->m_iMaxXY);
  iW = Y16X16::UnpackYFast(this->m_iMaxXY);
  for ( i = 0; i < iMaxCounter; ++i )
  {
    if ( iV >= iMaxV )
    {
      iV = 0;
      ++iW;
    }
    if ( iW >= iMaxW )
      iW = 0;
    if ( !Squares::ValidVW(iV, iW) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2792, "Squares::ValidVW(iV, iW)") == 1 )
      __debugbreak();
    for ( j = *CEffects::EffectSquareListHeadVW(this, iV, iW); j; j = m_uNextEffect )
    {
      m_uNextEffect = this->m_cEffects[j].m_uNextEffect;
      iTick = CEffect::TimeIndex(&this->m_cEffects[j], this->m_sViewPortData.m_iTick);
      if ( CEffect::IsOutOfDate(&this->m_cEffects[j], iTick) )
        CEffects::MoveEffectFromSquareListToFreeList(this, j);
    }
    ++iV;
  }
  this->m_iMaxXY = Y16X16::PackXYFast(iV, iW);
}


// address=[0x144dbf0]
// Decompiled from void __thiscall CEffects::Release(CEffects *this)
void  CEffects::Release(void) {
  
  if ( this )
    (*(void (__thiscall **)(CBBObject *, int))this->vtable)(&this->CBBObject, 1);
}


// address=[0x144dc30]
// Decompiled from void *__thiscall CEffects::DbgCheckData(std::_Ref_count_base *this, const struct type_info *a2)
unsigned int  CEffects::DbgCheckData(int a2) {
  
  return 0;
}


// address=[0x144dc40]
// Decompiled from void __thiscall CEffects::AddEffectToFreeList(CEffects *this, unsigned int _uEffectId)
void  CEffects::AddEffectToFreeList(unsigned int _uEffectId) {
  
  int uNextEffect; // [esp+0h] [ebp-Ch]

  if ( _uEffectId < 2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2055, "_uEffectId >= FIRST_REAL_EFFECT") == 1 )
    __debugbreak();
  if ( _uEffectId >= 0x1000 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2056, "_uEffectId < EFFECTS_MAX") == 1 )
    __debugbreak();
  if ( this->m_cEffects[_uEffectId].m_uPrevEffect
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2060, "rEffect.m_uPrevEffect == 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_cEffects[_uEffectId].m_uNextEffect
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2061, "rEffect.m_uNextEffect == 0") == 1 )
  {
    __debugbreak();
  }
  this->m_cEffects[_uEffectId].m_uVisualizeFunc = 0;
  uNextEffect = this->m_cEffects[1].m_uNextEffect;
  this->m_cEffects[1].m_uNextEffect = _uEffectId;
  this->m_cEffects[_uEffectId].m_uNextEffect = uNextEffect;
  this->m_cEffects[_uEffectId].m_uPrevEffect = 1;
  if ( uNextEffect )
  {
    if ( this->m_cEffects[uNextEffect].m_uPrevEffect != 1
      && BBSupportDbgReport(
           2,
           "Logic\\Effects.cpp",
           2074,
           "m_cEffects[uNextEffectId].m_uPrevEffect == FREE_EFFECTS_LIST_HEAD") == 1 )
    {
      __debugbreak();
    }
    this->m_cEffects[uNextEffect].m_uPrevEffect = _uEffectId;
  }
}


// address=[0x144dda0]
// Decompiled from void __thiscall CEffects::AddEffectToSquareList(CEffects *this, unsigned int _uEffectId)
void  CEffects::AddEffectToSquareList(unsigned int _uEffectId) {
  
  unsigned __int16 *v2; // [esp+0h] [ebp-18h]
  int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  int uOldHeadEffectId; // [esp+10h] [ebp-8h]

  if ( _uEffectId < 2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2087, "_uEffectId >= FIRST_REAL_EFFECT") == 1 )
    __debugbreak();
  if ( _uEffectId >= 0x1000 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2088, "_uEffectId < EFFECTS_MAX") == 1 )
    __debugbreak();
  if ( !this->m_cEffects[_uEffectId].m_uVisualizeFunc )
  {
    if ( BBSupportDbgReport(
           1,
           "Logic\\Effects.cpp",
           2094,
           "CEffects::AddEffectToSquareList(): Invalid visualize function!") == 1 )
      __debugbreak();
    CEffect::SetVisualizeFunc(&this->m_cEffects[_uEffectId].m_uVisualizeFunc, VISUALIZE_FUNC_NOP_2);
  }
  if ( this->m_cEffects[_uEffectId].m_uPrevEffect
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2099, "rEffect.m_uPrevEffect == 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_cEffects[_uEffectId].m_uNextEffect
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2100, "rEffect.m_uNextEffect == 0") == 1 )
  {
    __debugbreak();
  }
  v3 = Squares::XYToVW(this->m_cEffects[_uEffectId].uAngel.m_iX);
  v4 = Squares::XYToVW(this->m_cEffects[_uEffectId].uAngel.m_iY);
  if ( !Squares::ValidVW(v3, v4) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2105, "Squares::ValidVW(iV, iW)") == 1 )
    __debugbreak();
  v2 = CEffects::EffectSquareListHeadVW(this, v3, v4);
  uOldHeadEffectId = *v2;
  *v2 = _uEffectId;
  this->m_cEffects[_uEffectId].m_uPrevEffect = 0;
  this->m_cEffects[_uEffectId].m_uNextEffect = uOldHeadEffectId;
  if ( uOldHeadEffectId )
  {
    if ( this->m_cEffects[uOldHeadEffectId].m_uPrevEffect )
    {
      if ( BBSupportDbgReport(2, "Logic\\Effects.cpp", 2118, "m_cEffects[uOldHeadEffectId].m_uPrevEffect == 0") == 1 )
        __debugbreak();
    }
    this->m_cEffects[uOldHeadEffectId].m_uPrevEffect = _uEffectId;
  }
}


// address=[0x144df80]
// Decompiled from void __thiscall CEffects::RemoveEffectFromList(CEffects *this, unsigned int _uEffectId)
void  CEffects::RemoveEffectFromList(unsigned int _uEffectId) {
  
  unsigned __int16 *rSquareListHead; // [esp+0h] [ebp-14h]
  int iV; // [esp+4h] [ebp-10h]
  int iW; // [esp+8h] [ebp-Ch]

  if ( _uEffectId < 2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2131, "_uEffectId >= FIRST_REAL_EFFECT") == 1 )
    __debugbreak();
  if ( _uEffectId >= 0x1000 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2132, "_uEffectId < EFFECTS_MAX") == 1 )
    __debugbreak();
  if ( this->m_cEffects[_uEffectId].m_uPrevEffect )
  {
    if ( this->m_cEffects[this->m_cEffects[_uEffectId].m_uPrevEffect].m_uNextEffect != _uEffectId
      && BBSupportDbgReport(
           2,
           "Logic\\Effects.cpp",
           2138,
           "m_cEffects[rEffect.m_uPrevEffect].m_uNextEffect == _uEffectId") == 1 )
    {
      __debugbreak();
    }
    this->m_cEffects[this->m_cEffects[_uEffectId].m_uPrevEffect].m_uNextEffect = this->m_cEffects[_uEffectId].m_uNextEffect;
  }
  else
  {
    iV = Squares::XYToVW(this->m_cEffects[_uEffectId].uEffect.m_iX);
    iW = Squares::XYToVW(this->m_cEffects[_uEffectId].uEffect.m_iY);
    if ( !Squares::ValidVW(iV, iW) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2147, "Squares::ValidVW(iV, iW)") == 1 )
      __debugbreak();
    rSquareListHead = CEffects::EffectSquareListHeadVW(this, iV, iW);
    if ( *rSquareListHead != _uEffectId
      && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2151, "rSquareListHead == _uEffectId") == 1 )
    {
      __debugbreak();
    }
    *rSquareListHead = this->m_cEffects[_uEffectId].m_uNextEffect;
  }
  if ( this->m_cEffects[_uEffectId].m_uNextEffect )
  {
    if ( this->m_cEffects[this->m_cEffects[_uEffectId].m_uNextEffect].m_uPrevEffect != _uEffectId
      && BBSupportDbgReport(
           2,
           "Logic\\Effects.cpp",
           2158,
           "m_cEffects[rEffect.m_uNextEffect].m_uPrevEffect == _uEffectId") == 1 )
    {
      __debugbreak();
    }
    this->m_cEffects[this->m_cEffects[_uEffectId].m_uNextEffect].m_uPrevEffect = this->m_cEffects[_uEffectId].m_uPrevEffect;
  }
  this->m_cEffects[_uEffectId].m_uPrevEffect = 0;
  this->m_cEffects[_uEffectId].m_uNextEffect = 0;
}


// address=[0x144e170]
// Decompiled from void __thiscall CEffects::CleanUp(CEffects *this)
void  CEffects::CleanUp(void) {
  
  int v1; // [esp+0h] [ebp-20h]
  unsigned int TickCounter; // [esp+4h] [ebp-1Ch]
  int v3; // [esp+Ch] [ebp-14h]
  CEffect *v4; // [esp+10h] [ebp-10h]
  unsigned int i; // [esp+18h] [ebp-8h]
  bool v7; // [esp+1Fh] [ebp-1h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  this->m_iMaxXY = 0;
  this->m_iTickCounter = TickCounter;
  v3 = 1;
  this->m_cEffects[1].m_uNextEffect = 0;
  for ( i = 2; i < 0x1000; ++i )
  {
    v4 = &this->m_cEffects[i];
    v7 = v4->m_uVisualizeFunc == VISUALIZE_FUNC_NOP_1;
    if ( v4->m_uVisualizeFunc )
    {
      v1 = CEffect::TimeIndex(v4, TickCounter);
      if ( CEffect::IsOutOfDate(v4, v1) )
      {
        CEffects::RemoveEffectFromList(this, i);
        v7 = 1;
      }
    }
    if ( v7 )
    {
      memset(v4, 0, sizeof(CEffect));
      this->m_cEffects[i].m_uPrevEffect = v3;
      this->m_cEffects[v3].m_uNextEffect = i;
      v3 = i;
    }
  }
}


// address=[0x144f340]
// Decompiled from bool __thiscall CEffects::CheckParentEffect(CEffects *this, unsigned int a2)
bool  CEffects::CheckParentEffect(unsigned int a2) {
  
  return a2
      && a2 < 0x1000
      && this->m_cEffects[a2].m_uVisualizeFunc
      && this->m_cEffects[a2].m_uVisualizeFunc != VISUALIZE_FUNC_ATTACHED_EFFECT;
}


// address=[0x144f3b0]
// Decompiled from void __cdecl CEffects::ClipXOrY(int *a1)
void __cdecl CEffects::ClipXOrY(int & a1) {
  
  if ( *a1 >= 0 )
  {
    if ( *a1 > 1023 )
      *a1 = 1023;
  }
  else
  {
    *a1 = 0;
  }
}


// address=[0x144f3f0]
// Decompiled from void __thiscall CEffects::DecreaseMovingEffectCounter(CEffects *this, unsigned int _iEffect)
void  CEffects::DecreaseMovingEffectCounter(int _iEffect) {
  
  if ( _iEffect < 0x74 )
  {
    if ( this->m_iMovingEffectCounters[_iEffect] <= 0
      && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2042, "m_iMovingEffectCounters[_iEffect] > 0") == 1 )
    {
      __debugbreak();
    }
    this->m_iMovingEffectCounters[_iEffect] -= this->m_iMovingEffectCounters[_iEffect] > 0;
  }
}


// address=[0x144f4a0]
// Decompiled from unsigned __int16 *__thiscall CEffects::EffectSquareListHeadVW(CEffects *this, int a2, int a3)
unsigned short &  CEffects::EffectSquareListHeadVW(int a2, int a3) {
  
  return &this->m_uEffectSquareListHeadVW[a3][a2];
}


// address=[0x144f4d0]
// Decompiled from int __thiscall CEffects::FirstFreeEffectId(CEffects *this)
unsigned int  CEffects::FirstFreeEffectId(void) {
  
  return this->m_cEffects[1].m_uNextEffect;
}


// address=[0x144f650]
// Decompiled from void __thiscall CEffects::IncreaseMovingEffectCounter(CEffects *this, unsigned int a2)
void  CEffects::IncreaseMovingEffectCounter(int a2) {
  
  if ( a2 < 116 )
    ++this->m_iMovingEffectCounters[a2];
}


// address=[0x144f6d0]
// Decompiled from void __thiscall CEffects::MoveEffectFromSquareListToFreeList(CEffects *this, unsigned int a2)
void  CEffects::MoveEffectFromSquareListToFreeList(unsigned int a2) {
  
  CEffects::RemoveEffectFromList(this, a2);
  CEffects::AddEffectToFreeList(this, a2);
}


// address=[0x3f11f68]
// [Decompilation failed for static struct SGfxObjectInfo CEffects::m_sGfxInfo]

#endif // Already implemented
