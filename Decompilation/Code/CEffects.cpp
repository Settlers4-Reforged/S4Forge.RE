#include "CEffects.h"

// Definitions for class CEffects

// address=[0x144bfb0]
// Decompiled from CEffects *__thiscall CEffects::CEffects(CEffects *this)
 CEffects::CEffects(void) {
  
  unsigned int i; // [esp+4h] [ebp-14h]

  IEffects::IEffects(this);
  CBBObject::CBBObject((CEffects *)((char *)this + 8), (int)"CEffects", 1);
  *(_DWORD *)this = &CEffects::_vftable_;
  *((_DWORD *)this + 1) = &CEffects::`vftable';
  *((_DWORD *)this + 2) = &CEffects::`vftable';
  j__memset((char *)this + 24, 0, 0x20A4u);
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 13) = -1;
  j__memset((char *)this + 8380, 0, 0x2100u);
  j__memset((char *)this + 16828, 0, 0x3C000u);
  j__memset((char *)this + 262588, 255, 0x4000u);
  *((_WORD *)this + 8472) = 0;
  *((_WORD *)this + 8473) = 2;
  *((_WORD *)this + 8502) = 1;
  *((_WORD *)this + 8503) = 3;
  for ( i = 3; i < 0xFFF; ++i )
  {
    *((_WORD *)this + 30 * i + 8442) = i - 1;
    *((_WORD *)this + 30 * i + 8443) = i + 1;
  }
  *((_WORD *)this + 131292) = 4094;
  *((_WORD *)this + 131293) = 0;
  *((_DWORD *)this + 69743) = 0;
  *((_DWORD *)this + 69744) = 0;
  j__memset((char *)this + 278980, 0, 0x1D0u);
  j__memset(&CEffects::m_sGfxInfo, 0, 0x2D0u);
  if ( !g_pGfxEngine && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1696, "g_pGfxEngine != 0") == 1 )
    __debugbreak();
  IGfxEngine::SetEffectSystemInterfacePtr((IGfxEngine *)g_pGfxEngine, this);
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
// Decompiled from CEffects *__thiscall CEffects::SetEffectsViewport(CEffects *this, int a2, int a3, int a4, int a5, int a6)
void  CEffects::SetEffectsViewport(int,int,int,int,int) {
  
  CEffects *result; // eax

  CEffects::ClipXOrY(&a2);
  CEffects::ClipXOrY(&a3);
  CEffects::ClipXOrY(&a4);
  CEffects::ClipXOrY(&a5);
  CEffects::ClipXOrY(&a6);
  if ( a2 > a4 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1731, "_iX0 <= _iX1") == 1 )
    __debugbreak();
  if ( a4 > a6 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1732, "_iX1 <= _iX2") == 1 )
    __debugbreak();
  if ( a3 > a5 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1733, "_iY0 <= _iY1") == 1 )
    __debugbreak();
  *((_DWORD *)this + 6) = a2;
  *((_DWORD *)this + 7) = a3;
  *((_DWORD *)this + 8) = a4;
  *((_DWORD *)this + 9) = a5;
  *((_DWORD *)this + 10) = a6;
  *((_DWORD *)this + 11) = CStateGame::GetTickCounter(g_pGame);
  *((_DWORD *)this + 12) = -1;
  result = this;
  *((_DWORD *)this + 13) = -1;
  *((_DWORD *)this + 14) = 0;
  return result;
}


// address=[0x144c3a0]
// Decompiled from int __thiscall CEffects::FirstEffect(CEffects *this, Squares *a2)
struct SGfxObjectInfo *  CEffects::FirstEffect(int) {
  
  struct IUnknown *v3; // [esp+0h] [ebp-34h]
  unsigned int v4; // [esp+8h] [ebp-2Ch]
  int v5; // [esp+Ch] [ebp-28h]
  int v6; // [esp+10h] [ebp-24h]
  int v7; // [esp+14h] [ebp-20h]
  int v8; // [esp+18h] [ebp-1Ch]
  Squares *i; // [esp+1Ch] [ebp-18h]
  int v10; // [esp+20h] [ebp-14h]
  Squares *v11; // [esp+24h] [ebp-10h]
  struct IUnknown *j; // [esp+28h] [ebp-Ch]
  CEffect *v13; // [esp+2Ch] [ebp-8h]

  if ( (int)a2 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1755, "_iY >= 0") == 1 )
    __debugbreak();
  if ( (int)a2 >= 1024
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1756, "_iY < Squares::SQUARE_MAX_SUPPORTED_MAP_WIDTH_HEIGHT") == 1 )
  {
    __debugbreak();
  }
  if ( (int)a2 < *((_DWORD *)this + 7)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1758, "_iY >= m_sViewPortData.m_iViewY0") == 1 )
  {
    __debugbreak();
  }
  if ( (int)a2 > *((_DWORD *)this + 9)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1759, "_iY <= m_sViewPortData.m_iViewY1") == 1 )
  {
    __debugbreak();
  }
  if ( (int)a2 <= *((_DWORD *)this + 12)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1761, "_iY > m_sViewPortData.m_iCurrentY") == 1 )
  {
    __debugbreak();
  }
  v7 = Squares::XYToVW(a2);
  if ( v7 != *((_DWORD *)this + 13) )
  {
    *((_DWORD *)this + 13) = v7;
    v11 = (Squares *)Squares::XYToVW(*((Squares **)this + 6));
    v10 = Squares::XYToVW(*((Squares **)this + 10));
    if ( !Squares::ValidVW(v11) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1772, "Squares::ValidVW(iVLeft)") == 1 )
      __debugbreak();
    if ( !Squares::ValidVW((Squares *)v10)
      && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1773, "Squares::ValidVW(iVRight)") == 1 )
    {
      __debugbreak();
    }
    if ( (int)v11 > 0 )
      v11 = (Squares *)((char *)v11 - 1);
    if ( v10 < 63 )
      ++v10;
    j__memset((char *)this + 60, 0, 0x80u);
    for ( i = v11; (int)i <= v10; i = (Squares *)((char *)i + 1) )
    {
      for ( j = (struct IUnknown *)*CEffects::EffectSquareListHeadVW(this, i, v7); j; j = v3 )
      {
        v13 = (CEffects *)((char *)this + 60 * (_DWORD)j + 16828);
        v3 = (struct IUnknown *)*((unsigned __int16 *)this + 30 * (_DWORD)j + 8443);
        v6 = CEffect::TimeIndex(v13, *((_DWORD *)this + 11));
        if ( v6 >= 0 )
        {
          if ( CEffect::IsOutOfDate(v13, v6) )
            goto LABEL_40;
          v5 = *((unsigned __int8 *)this + 60 * (_DWORD)j + 16830);
          if ( *((_BYTE *)this + 60 * (_DWORD)j + 16830) )
          {
            *((_BYTE *)this + 60 * (_DWORD)j + 16830) = 0;
            if ( !v6 )
              CSoundManager::PlayEnvironmentSound(
                g_pSoundManager,
                v5,
                *((_DWORD *)this + 15 * (_DWORD)j + 4211),
                *((_DWORD *)this + 15 * (_DWORD)j + 4212),
                0);
          }
          if ( !*((_BYTE *)this + 60 * (_DWORD)j + 16829) )
          {
LABEL_40:
            CEffects::MoveEffectFromSquareListToFreeList(this, j);
          }
          else
          {
            v8 = CEffect::SquareRow(v13);
            v4 = *((unsigned __int16 *)this + v8 + 30);
            if ( v4 < 0x40 )
            {
              ++*((_WORD *)this + v8 + 30);
              *((_WORD *)this + 64 * v8 + v4 + 94) = (_WORD)j;
            }
          }
        }
      }
    }
  }
  *((_DWORD *)this + 12) = a2;
  *((_DWORD *)this + 14) = 0;
  return (*(int (__thiscall **)(CEffects *))(*(_DWORD *)this + 8))(this);
}


// address=[0x144c6e0]
// Decompiled from void *__thiscall CEffects::NextEffect(CEffects *this)
struct SGfxObjectInfo *  CEffects::NextEffect(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-18h]
  unsigned int v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-Ch]
  CEffect *v8; // [esp+10h] [ebp-8h]

  if ( *((int *)this + 12) < 0
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1855, "m_sViewPortData.m_iCurrentY >= 0") == 1 )
  {
    __debugbreak();
  }
  v7 = *((_DWORD *)this + 12) & 0xF;
  if ( *((_DWORD *)this + 14) >= (int)*((unsigned __int16 *)this + v7 + 30) )
    return 0;
  v5 = *((unsigned __int16 *)this + 64 * v7 + (*((_DWORD *)this + 14))++ + 94);
  v8 = (CEffects *)((char *)this + 60 * v5 + 16828);
  byte_3F12232 = 1;
  byte_3F12231 = 0;
  if ( *(_BYTE *)v8 == 11 )
  {
    v6 = *((_DWORD *)this + 15 * v5 + 4219);
    if ( !CEffects::CheckParentEffect(this, v6) )
      return 0;
    v2 = CEffect::TimeIndex((CEffects *)((char *)this + 60 * v6 + 16828), *((_DWORD *)this + 11));
    CEffect::Visualize(
      (int (__thiscall **)(CEffect *, struct SGfxObjectInfo *, int))this + 15 * v6 + 4207,
      (struct SGfxObjectInfo *)&CEffects::m_sGfxInfo,
      v2);
    v3 = CEffect::TimeIndex(v8, *((_DWORD *)this + 11));
    CEffect::Visualize(
      (int (__thiscall **)(CEffect *, struct SGfxObjectInfo *, int))v8,
      (struct SGfxObjectInfo *)&CEffects::m_sGfxInfo,
      v3);
  }
  else
  {
    v4 = CEffect::TimeIndex(v8, *((_DWORD *)this + 11));
    CEffect::Visualize(
      (int (__thiscall **)(CEffect *, struct SGfxObjectInfo *, int))v8,
      (struct SGfxObjectInfo *)&CEffects::m_sGfxInfo,
      v4);
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(*((_DWORD *)this + 15 * v5 + 4211), *((_DWORD *)this + 15 * v5 + 4212))
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1890, "g_cWorld.InWorld(rEffect.m_iX, rEffect.m_iY)") == 1 )
  {
    __debugbreak();
  }
  dword_3F12228 = *((_DWORD *)this + 15 * v5 + 4211);
  dword_3F1222C = *((_DWORD *)this + 15 * v5 + 4212);
  return &CEffects::m_sGfxInfo;
}


// address=[0x144c880]
// Decompiled from int __thiscall CEffects::Load(CEffects *this, struct IS4Chunk *a2)
void  CEffects::Load(class IS4Chunk &) {
  
  int v2; // eax
  unsigned __int8 *v4; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+4h] [ebp-8h]

  j__memset((char *)this + 20, 0, 0x20A4u);
  *((_DWORD *)this + 11) = -1;
  *((_DWORD *)this + 12) = -1;
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1824106861);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 4096, 4096);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 60, 60);
  (*(void (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 8376, 8448);
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 16824, 245760);
  *((_DWORD *)this + 69742) = 0;
  *((_DWORD *)this + 69743) = 0;
  j__memset((char *)this + 278976, 0, 0x1D0u);
  j__memset(&CEffects::m_sGfxInfo, 0, 0x2D0u);
  for ( i = 2; i < 0x1000; ++i )
  {
    v4 = (unsigned __int8 *)this + 60 * i + 16824;
    v2 = CEffect::VisualizeFunc(v4);
    CEffect::SetVisualizeFunc(v4, v2);
    if ( CEffect::VisualizeFunc(v4) == 8 )
      CEffects::IncreaseMovingEffectCounter((CEffects *)((char *)this - 4), *((unsigned __int8 *)this + 60 * i + 16825));
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 1452512070);
}


// address=[0x144ca00]
// Decompiled from int __thiscall CEffects::Save(CEffects *this, struct IS4Chunk *a2)
void  CEffects::Save(class IS4Chunk &) {
  
  if ( *((_DWORD *)this + 69743) < (unsigned int)CStateGame::GetTickCounter(g_pGame) )
    CEffects::CleanUp((CEffects *)((char *)this - 4));
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1824106861);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 4096);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 60);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 245760);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 8376, 8448);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 16824, 245760);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 1452512070);
}


// address=[0x144cae0]
// Decompiled from int __thiscall CEffects::AddEffect(CEffects *this, int a2, char a3, int a4, int a5, int a6, int a7, char a8)
unsigned int  CEffects::AddEffect(int,enum SIV_SOUNDS,int,int,unsigned int,int,bool) {
  
  unsigned int FreeEffectId; // [esp+10h] [ebp-4h]

  if ( (unsigned __int8)CWorldManager::InWorld(a4, a5) )
  {
    FreeEffectId = CEffects::FirstFreeEffectId(this);
    if ( FreeEffectId )
    {
      CEffects::RemoveEffectFromList(this, FreeEffectId);
      CEffect::InitEffect((int)this + 60 * FreeEffectId + 16828, a2, a3, a4, a5, a6, a7, a8);
      CEffects::AddEffectToSquareList(this, FreeEffectId);
      return *((_DWORD *)this + 15 * FreeEffectId + 4210) + a6;
    }
    else if ( a6 )
    {
      return a6;
    }
    else
    {
      return 1;
    }
  }
  else if ( a6 )
  {
    return a6;
  }
  else
  {
    return 1;
  }
}


// address=[0x144cbb0]
// Decompiled from unsigned int __thiscall CEffects::AddAngel(CEffects *this, int a2, char a3, int a4, int a5, int a6, unsigned int a7)
unsigned int  CEffects::AddAngel(enum T_EFFECT_ANGEL,enum SIV_SOUNDS,int,int,int,unsigned int) {
  
  unsigned int FreeEffectId; // [esp+10h] [ebp-4h]

  if ( a2 > 3 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2361, "_tAngel <= EFFECT_ANGEL_LAST") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorld(a4, a5)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2362, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( !CPlayerManager::ValidUsedPlayerId(a6)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2363, "g_cPlayerMgr.ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( a7 >= 0x400 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2364, "_uStartDelay < 1024") == 1 )
    __debugbreak();
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( FreeEffectId == 0 || a2 == 0 )
    return a7;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitAngel((int)this + 60 * FreeEffectId + 16828, a2, a3, a4, a5, a6, a7);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return *((_DWORD *)this + 15 * FreeEffectId + 4210) + a7;
}


// address=[0x144cd20]
// Decompiled from unsigned int __thiscall CEffects::AddMissile(CEffects *this, int a2, int a3, int a4, unsigned int a5, int a6, int a7)
unsigned int  CEffects::AddMissile(enum T_EFFECT_MISSILE,int,int,unsigned int,int,int) {
  
  unsigned int FreeEffectId; // [esp+8h] [ebp-4h]

  if ( a2 > 10 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2260, "_tMissile <= EFFECT_MISSILE_LAST") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a3)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2261, "g_cWorld.InWorldPackedXY(_iAttackerXY)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a4)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2262, "g_cWorld.InWorldPackedXY(_iTargetXY)") == 1 )
  {
    __debugbreak();
  }
  if ( a5 >= 0x400 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2263, "_uStartDelay < 1024") == 1 )
    __debugbreak();
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( !FreeEffectId )
    return a5;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitMissile((_DWORD *)this + 15 * FreeEffectId + 4207, a2, a3, a4, a5, a6, a7);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return *((_DWORD *)this + 15 * FreeEffectId + 4210) + a5;
}


// address=[0x144ce50]
// Decompiled from unsigned int __thiscall CEffects::AddSporeCloud(CEffects *this, int a2, int a3, unsigned int a4)
unsigned int  CEffects::AddSporeCloud(int,int,unsigned int) {
  
  int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+4h] [ebp-10h]
  unsigned int FreeEffectId; // [esp+Ch] [ebp-8h]
  unsigned int v9; // [esp+24h] [ebp+10h]

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2292, "g_cWorld.InWorldPackedXY(_iSrcXY)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a3)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2293, "g_cWorld.InWorldPackedXY(_iDstXY)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 0x400 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2294, "_uStartDelay < 1024") == 1 )
    __debugbreak();
  v5 = Y16X16::UnpackXFast(a2);
  v6 = Y16X16::UnpackYFast(a2);
  v9 = (*(int (__thiscall **)(CEffects *, int, _DWORD, int, int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)this + 16))(
         this,
         20,
         0,
         v5,
         v6,
         a4,
         0,
         0);
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( !FreeEffectId )
    return v9;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitSporeCloud((CEffects *)((char *)this + 60 * FreeEffectId + 16828), a2, a3, v9);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return *((_DWORD *)this + 15 * FreeEffectId + 4210) + v9;
}


// address=[0x144cf90]
// Decompiled from unsigned int __thiscall CEffects::AddStagnantAnimal(  CEffects *this,  signed int a2,  char a3,  int a4,  int a5,  unsigned int a6,  unsigned int a7)
unsigned int  CEffects::AddStagnantAnimal(enum SIV_ANIMALS,enum SIV_SOUNDS,int,int,int,unsigned int) {
  
  unsigned int FreeEffectId; // [esp+8h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2328, "_tAnimalJob != ANIMAL_NO_ANIMAL_WALK") == 1 )
    __debugbreak();
  if ( a2 >= 42 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2329, "_tAnimalJob < SIV_ANIMAL_MAX") == 1 )
    __debugbreak();
  if ( a6 >= 6 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2330, "(_iDir >= 0) && (_iDir < 6)") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorld(a4, a5)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2331, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a7 >= 0x400 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2332, "_uStartDelay < 1024") == 1 )
    __debugbreak();
  FreeEffectId = CEffects::FirstFreeEffectId(this);
  if ( !FreeEffectId )
    return a7;
  CEffects::RemoveEffectFromList(this, FreeEffectId);
  CEffect::InitStagnantAnimal((int)this + 60 * FreeEffectId + 16828, a2, a3, a4, a5, a6, a7);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return *((_DWORD *)this + 15 * FreeEffectId + 4210) + a7;
}


// address=[0x144d0f0]
// Decompiled from _BYTE *__thiscall CEffects::DeleteEffect(CEffects *this, struct IUnknown *a2)
void  CEffects::DeleteEffect(unsigned int) {
  
  _BYTE *result; // eax

  if ( (!a2 || (unsigned int)a2 >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2395, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( !a2 )
    return result;
  if ( (unsigned int)a2 >= 0x1000 )
    return result;
  result = (char *)this + 60 * (_DWORD)a2 + 16828;
  if ( !*result )
    return result;
  if ( *((_BYTE *)this + 60 * (_DWORD)a2 + 16828) == 8 )
    CEffects::DecreaseMovingEffectCounter(this, *((unsigned __int8 *)this + 60 * (_DWORD)a2 + 16829));
  return (_BYTE *)CEffects::MoveEffectFromSquareListToFreeList(this, a2);
}


// address=[0x144d180]
// Decompiled from unsigned int __thiscall CEffects::CreateMovingEffect(CEffects *this, int a2, int a3, int a4)
unsigned int  CEffects::CreateMovingEffect(int,int,int) {
  
  unsigned int FreeEffectId; // [esp+4h] [ebp-8h]

  if ( (a2 <= 0 || a2 >= 86)
    && (a2 <= 100 || a2 >= 116)
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
  CEffect::InitMovingEffect((CEffects *)((char *)this + 60 * FreeEffectId + 16828), a2, a3, a4);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  CEffects::IncreaseMovingEffectCounter(this, a2);
  return FreeEffectId;
}


// address=[0x144d230]
// Decompiled from unsigned int __thiscall CEffects::ChangeMovingEffectType(CEffects *this, unsigned int a2, unsigned int a3)
void  CEffects::ChangeMovingEffectType(unsigned int,int) {
  
  unsigned int result; // eax
  _BYTE *v5; // [esp+Ch] [ebp-4h]

  if ( (!a2 || a2 >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2447, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a3 >= 0x56 || a2 == 0 )
    return result;
  v5 = (char *)this + 60 * a2 + 16828;
  if ( *v5 != 8
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2453, "rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT") == 1 )
  {
    __debugbreak();
  }
  result = (unsigned __int8)*v5;
  if ( result != 8 )
    return result;
  CEffects::DecreaseMovingEffectCounter(this, *((unsigned __int8 *)this + 60 * a2 + 16829));
  CEffects::IncreaseMovingEffectCounter(this, a3);
  *((_BYTE *)this + 60 * a2 + 16829) = a3;
  result = CEffect::GetEffectNumberOfFrames(a3);
  *((_BYTE *)this + 60 * a2 + 16834) = result;
  *((_BYTE *)this + 60 * a2 + 16835) = 0;
  return result;
}


// address=[0x144d330]
// Decompiled from int __thiscall CEffects::NumberOfMovingEffects(CEffects *this, unsigned int a2)
int  CEffects::NumberOfMovingEffects(int) {
  
  if ( a2 >= 0x56
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2475, "static_cast<unsigned int>(_tEffect) < EFFECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + a2 + 69745) < 0
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2477, "m_iMovingEffectCounters[_tEffect] >= 0") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + a2 + 69745);
}


// address=[0x144d3a0]
// Decompiled from int __thiscall CEffects::GetMovingEffectInfo(CEffects *this, unsigned int a2, int *a3, int *a4, int *a5, int *a6)
void  CEffects::GetMovingEffectInfo(unsigned int,int &,int &,int &,int &) {
  
  int result; // eax
  int v8; // [esp+4h] [ebp-14h]
  unsigned int TickCounter; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]

  if ( (!a2 || a2 >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2489, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 60 * a2 + 16828) != 8
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2493, "rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT") == 1 )
  {
    __debugbreak();
  }
  *a3 = *((unsigned __int8 *)this + 60 * a2 + 16829);
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( TickCounter < *((_DWORD *)this + 15 * a2 + 4209) )
    v8 = 0;
  else
    v8 = TickCounter - *((_DWORD *)this + 15 * a2 + 4209);
  v10 = *((unsigned __int8 *)this + 60 * a2 + 16831);
  if ( v8 < v10 )
  {
    if ( v8 <= 0 )
    {
      *a4 = *((_DWORD *)this + 15 * a2 + 4211);
      *a5 = *((_DWORD *)this + 15 * a2 + 4212);
    }
    else
    {
      *a4 = *((_DWORD *)this + 15 * a2 + 4211)
          + v8 * (*((_DWORD *)this + 15 * a2 + 4213) - *((_DWORD *)this + 15 * a2 + 4211)) / v10;
      *a5 = *((_DWORD *)this + 15 * a2 + 4212)
          + v8 * (*((_DWORD *)this + 15 * a2 + 4214) - *((_DWORD *)this + 15 * a2 + 4212)) / v10;
    }
  }
  else
  {
    *a4 = *((_DWORD *)this + 15 * a2 + 4213);
    *a5 = *((_DWORD *)this + 15 * a2 + 4214);
  }
  result = *((unsigned __int8 *)this + 60 * a2 + 16833);
  *a6 = result;
  return result;
}


// address=[0x144d4f0]
// Decompiled from _BYTE *__thiscall CEffects::SetMovingEffectSpeed(CEffects *this, unsigned int a2, int a3)
void  CEffects::SetMovingEffectSpeed(unsigned int,int) {
  
  _BYTE *result; // eax

  if ( !a2 )
    return result;
  if ( a2 >= 0x1000 )
    return result;
  result = (char *)this + 60 * a2 + 16828;
  if ( *result != 8 )
    return result;
  if ( a3 >= 10 )
  {
    if ( a3 > 500 )
      a3 = 500;
  }
  else
  {
    a3 = 10;
  }
  result = (_BYTE *)a3;
  *((_DWORD *)this + 15 * a2 + 4219) = a3;
  return result;
}


// address=[0x144d560]
// Decompiled from int __thiscall CEffects::SetMovingEffectDestination(CEffects *this, unsigned int a2, int a3, int a4, char a5)
unsigned int  CEffects::SetMovingEffectDestination(unsigned int,int,int,int) {
  
  int v6; // [esp+0h] [ebp-Ch]
  CEffect *v7; // [esp+4h] [ebp-8h]

  if ( (!a2 || a2 >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2551, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  v6 = 0;
  if ( !a2 )
    return v6;
  CEffects::RemoveEffectFromList(this, a2);
  v7 = (CEffects *)((char *)this + 60 * a2 + 16828);
  if ( *(_BYTE *)v7 != 8
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2561, "rEffect.m_uVisualizeFunc == VISUALIZE_FUNC_MOVING_EFFECT") == 1 )
  {
    __debugbreak();
  }
  v6 = CEffect::SetNewDestinationForMovingEffect(v7, a3, a4, a5);
  CEffects::AddEffectToSquareList(this, a2);
  return v6;
}


// address=[0x144d620]
// Decompiled from int __thiscall CEffects::GetMovingEffectDirection(CEffects *this, unsigned int a2)
int  CEffects::GetMovingEffectDirection(unsigned int) {
  
  int v3; // [esp+4h] [ebp-8h]

  if ( !a2 || a2 >= 0x1000 )
    return 0;
  v3 = 0;
  if ( *((_BYTE *)this + 60 * a2 + 16828) == 8 )
    return *((unsigned __int8 *)this + 60 * a2 + 16833);
  return v3;
}


// address=[0x144d680]
// Decompiled from unsigned int __thiscall CEffects::SetMovingEffectDirection(CEffects *this, unsigned int a2, int a3)
void  CEffects::SetMovingEffectDirection(unsigned int,int) {
  
  unsigned int result; // eax

  if ( !a2 )
    return result;
  if ( a2 >= 0x1000 )
    return result;
  result = (unsigned int)this + 60 * a2 + 16828;
  if ( *(_BYTE *)result != 8 )
    return result;
  result = *((unsigned __int8 *)this + 60 * a2 + 16832);
  if ( result <= 1 || a3 < 0 )
    return result;
  result = (unsigned int)this + 60 * a2 + 16828;
  *((_BYTE *)this + 60 * a2 + 16833) = a3 % *((unsigned __int8 *)this + 60 * a2 + 16832);
  return result;
}


// address=[0x144d6f0]
// Decompiled from int __thiscall CEffects::GetMovingEffectSoundId(CEffects *this, unsigned int a2)
int  CEffects::GetMovingEffectSoundId(unsigned int) {
  
  if ( (!a2 || a2 >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2637, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + a2 + 65647);
}


// address=[0x144d740]
// Decompiled from int __thiscall CEffects::SetMovingEffectSoundId(CEffects *this, unsigned int a2, int a3)
void  CEffects::SetMovingEffectSoundId(unsigned int,int) {
  
  int result; // eax

  if ( (!a2 || a2 >= 0x1000)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2625, "(_uEffectId > 0) && (_uEffectId < EFFECTS_MAX)") == 1 )
  {
    __debugbreak();
  }
  result = a3;
  *((_DWORD *)this + a2 + 65647) = a3;
  return result;
}


// address=[0x144d790]
// Decompiled from unsigned int __thiscall CEffects::CreateAttachedEffect(CEffects *this, int a2, unsigned int a3, char a4)
unsigned int  CEffects::CreateAttachedEffect(int,unsigned int,int) {
  
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
  CEffect::InitAttachedEffect(
    (CEffects *)((char *)this + 60 * FreeEffectId + 16828),
    a2,
    a3,
    (CEffects *)((char *)this + 60 * a3 + 16828),
    a4);
  CEffects::AddEffectToSquareList(this, FreeEffectId);
  return FreeEffectId;
}


// address=[0x144d860]
// Decompiled from _BYTE *__thiscall CEffects::SetAttachedEffectOffset(CEffects *this, unsigned int a2, float a3, float a4)
void  CEffects::SetAttachedEffectOffset(unsigned int,float,float) {
  
  _BYTE *result; // eax

  if ( !a2 || a2 >= 0x1000 )
    return result;
  result = (char *)this + 60 * a2 + 16828;
  if ( *result != 11 )
    return result;
  *((float *)this + 15 * a2 + 4215) = a3;
  result = (char *)this + 60 * a2 + 16828;
  *((float *)this + 15 * a2 + 4216) = a4;
  return result;
}


// address=[0x144d8c0]
// Decompiled from void __thiscall CEffects::UpdateAttachedEffect(CEffects *this, unsigned int a2)
void  CEffects::UpdateAttachedEffect(unsigned int) {
  
  const struct CEffect *v2; // [esp+0h] [ebp-Ch]
  CEffect *v3; // [esp+4h] [ebp-8h]

  if ( a2 )
  {
    if ( a2 < 0x1000 )
    {
      v3 = (CEffects *)((char *)this + 60 * a2 + 16828);
      if ( *(_BYTE *)v3 == 11 && CEffects::CheckParentEffect(this, *((_DWORD *)this + 15 * a2 + 4219)) )
      {
        v2 = (CEffects *)((char *)this + 60 * *((_DWORD *)this + 15 * a2 + 4219) + 16828);
        CEffects::RemoveEffectFromList(this, a2);
        CEffect::UpdateAttachedEffect(v3, v2);
        CEffects::AddEffectToSquareList(this, a2);
      }
    }
  }
}


// address=[0x144d950]
// Decompiled from bool __thiscall CEffects::WasAttachedEffectVisible(CEffects *this, unsigned int a2)
bool  CEffects::WasAttachedEffectVisible(unsigned int) {
  
  bool v3; // [esp+Bh] [ebp-1h]

  if ( !a2 || a2 >= 0x1000 )
    return 0;
  v3 = 0;
  if ( *((_BYTE *)this + 60 * a2 + 16828) != 11 )
    return v3;
  v3 = *((_BYTE *)this + 60 * a2 + 16852) != 0;
  *((_BYTE *)this + 60 * a2 + 16852) = 0;
  return v3;
}


// address=[0x144d9b0]
// Decompiled from int __thiscall CEffects::Execute(CEffects *this)
void  CEffects::Execute(void) {
  
  Squares *v1; // eax
  int v2; // edx
  int v3; // ecx
  Squares *v4; // eax
  int result; // eax
  struct IUnknown *v6; // [esp+0h] [ebp-2Ch]
  int v7; // [esp+4h] [ebp-28h]
  int v8; // [esp+8h] [ebp-24h]
  int i; // [esp+10h] [ebp-1Ch]
  struct IUnknown *j; // [esp+14h] [ebp-18h]
  int v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]
  Squares *v14; // [esp+24h] [ebp-8h]
  int v15; // [esp+28h] [ebp-4h]

  v1 = (Squares *)CWorldManager::Width(this);
  v11 = Squares::XYToVW(v1);
  v4 = (Squares *)CWorldManager::Height(v3, v2);
  v12 = Squares::XYToVW(v4);
  if ( v12 <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2765, "iMaxV > 0") == 1 )
    __debugbreak();
  if ( v11 <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2766, "iMaxW > 0") == 1 )
    __debugbreak();
  if ( v12 > 64 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2768, "iMaxV <= Squares::SQUARE_GRID_MAX_V_W") == 1 )
    __debugbreak();
  if ( v11 > 64 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2769, "iMaxW <= Squares::SQUARE_GRID_MAX_V_W") == 1 )
    __debugbreak();
  v8 = (v11 * v12 + 31) / 32;
  if ( v8 <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2773, "iMaxCounter > 0") == 1 )
    __debugbreak();
  v14 = (Squares *)Y16X16::UnpackXFast(*((_DWORD *)this + 69743));
  v15 = Y16X16::UnpackYFast(*((_DWORD *)this + 69743));
  for ( i = 0; i < v8; ++i )
  {
    if ( (int)v14 >= v12 )
    {
      v14 = 0;
      ++v15;
    }
    if ( v15 >= v11 )
      v15 = 0;
    if ( !Squares::ValidVW(v14, v15)
      && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2792, "Squares::ValidVW(iV, iW)") == 1 )
    {
      __debugbreak();
    }
    for ( j = (struct IUnknown *)*CEffects::EffectSquareListHeadVW(this, v14, v15); j; j = v6 )
    {
      v6 = (struct IUnknown *)*((unsigned __int16 *)this + 30 * (_DWORD)j + 8443);
      v7 = CEffect::TimeIndex((CEffects *)((char *)this + 60 * (_DWORD)j + 16828), *((_DWORD *)this + 11));
      if ( CEffect::IsOutOfDate((CEffects *)((char *)this + 60 * (_DWORD)j + 16828), v7) )
        CEffects::MoveEffectFromSquareListToFreeList(this, j);
    }
    v14 = (Squares *)((char *)v14 + 1);
  }
  result = Y16X16::PackXYFast((int)v14, v15);
  *((_DWORD *)this + 69743) = result;
  return result;
}


// address=[0x144dbf0]
// Decompiled from CEffects *__thiscall CEffects::Release(CEffects *this)
void  CEffects::Release(void) {
  
  CEffects *result; // eax

  result = this;
  if ( this )
    return (CEffects *)(**((int (__thiscall ***)(char *, int))this + 2))((char *)this + 8, 1);
  return result;
}


// address=[0x144dc30]
// Decompiled from void *__thiscall CEffects::DbgCheckData(std::_Ref_count_base *this, const struct type_info *a2)
unsigned int  CEffects::DbgCheckData(int) {
  
  return 0;
}


// address=[0x144dc40]
// Decompiled from CEffects *__thiscall CEffects::AddEffectToFreeList(CEffects *this, unsigned int a2)
void  CEffects::AddEffectToFreeList(unsigned int) {
  
  CEffects *result; // eax
  int v3; // [esp+0h] [ebp-Ch]

  if ( a2 < 2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2055, "_uEffectId >= FIRST_REAL_EFFECT") == 1 )
    __debugbreak();
  if ( a2 >= 0x1000 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2056, "_uEffectId < EFFECTS_MAX") == 1 )
    __debugbreak();
  if ( *((_WORD *)this + 30 * a2 + 8442)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2060, "rEffect.m_uPrevEffect == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)this + 30 * a2 + 8443)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2061, "rEffect.m_uNextEffect == 0") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 60 * a2 + 16828) = 0;
  v3 = *((unsigned __int16 *)this + 8473);
  *((_WORD *)this + 8473) = a2;
  *((_WORD *)this + 30 * a2 + 8443) = v3;
  result = (CEffects *)((char *)this + 60 * a2 + 16828);
  *((_WORD *)this + 30 * a2 + 8442) = 1;
  if ( !v3 )
    return result;
  if ( *((_WORD *)this + 30 * v3 + 8442) != 1
    && BBSupportDbgReport(
         2,
         "Logic\\Effects.cpp",
         2074,
         "m_cEffects[uNextEffectId].m_uPrevEffect == FREE_EFFECTS_LIST_HEAD") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_WORD *)this + 30 * v3 + 8442) = a2;
  return result;
}


// address=[0x144dda0]
// Decompiled from int __thiscall CEffects::AddEffectToSquareList(CEffects *this, unsigned int a2)
void  CEffects::AddEffectToSquareList(unsigned int) {
  
  int result; // eax
  unsigned __int16 *v3; // [esp+0h] [ebp-18h]
  Squares *v4; // [esp+4h] [ebp-14h]
  unsigned int v5; // [esp+8h] [ebp-10h]
  int v7; // [esp+10h] [ebp-8h]

  if ( a2 < 2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2087, "_uEffectId >= FIRST_REAL_EFFECT") == 1 )
    __debugbreak();
  if ( a2 >= 0x1000 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2088, "_uEffectId < EFFECTS_MAX") == 1 )
    __debugbreak();
  if ( !*((_BYTE *)this + 60 * a2 + 16828) )
  {
    if ( BBSupportDbgReport(
           1,
           "Logic\\Effects.cpp",
           2094,
           "CEffects::AddEffectToSquareList(): Invalid visualize function!") == 1 )
      __debugbreak();
    CEffect::SetVisualizeFunc((char *)this + 60 * a2 + 16828, 1);
  }
  if ( *((_WORD *)this + 30 * a2 + 8442)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2099, "rEffect.m_uPrevEffect == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)this + 30 * a2 + 8443)
    && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2100, "rEffect.m_uNextEffect == 0") == 1 )
  {
    __debugbreak();
  }
  v4 = (Squares *)Squares::XYToVW(*((Squares **)this + 15 * a2 + 4211));
  v5 = Squares::XYToVW(*((Squares **)this + 15 * a2 + 4212));
  if ( !Squares::ValidVW(v4, v5) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2105, "Squares::ValidVW(iV, iW)") == 1 )
    __debugbreak();
  v3 = CEffects::EffectSquareListHeadVW(this, v4, v5);
  v7 = *v3;
  *v3 = a2;
  *((_WORD *)this + 30 * a2 + 8442) = 0;
  result = (int)this + 60 * a2 + 16828;
  *((_WORD *)this + 30 * a2 + 8443) = v7;
  if ( !v7 )
    return result;
  if ( *((_WORD *)this + 30 * v7 + 8442) )
  {
    if ( BBSupportDbgReport(2, "Logic\\Effects.cpp", 2118, "m_cEffects[uOldHeadEffectId].m_uPrevEffect == 0") == 1 )
      __debugbreak();
  }
  result = 60 * v7;
  *((_WORD *)this + 30 * v7 + 8442) = a2;
  return result;
}


// address=[0x144df80]
// Decompiled from char *__thiscall CEffects::RemoveEffectFromList(CEffects *this, unsigned int a2)
void  CEffects::RemoveEffectFromList(unsigned int) {
  
  char *result; // eax
  unsigned __int16 *v3; // [esp+0h] [ebp-14h]
  Squares *v4; // [esp+4h] [ebp-10h]
  unsigned int v5; // [esp+8h] [ebp-Ch]

  if ( a2 < 2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2131, "_uEffectId >= FIRST_REAL_EFFECT") == 1 )
    __debugbreak();
  if ( a2 >= 0x1000 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2132, "_uEffectId < EFFECTS_MAX") == 1 )
    __debugbreak();
  if ( *((_WORD *)this + 30 * a2 + 8442) )
  {
    if ( *((unsigned __int16 *)this + 30 * *((unsigned __int16 *)this + 30 * a2 + 8442) + 8443) != a2
      && BBSupportDbgReport(
           2,
           "Logic\\Effects.cpp",
           2138,
           "m_cEffects[rEffect.m_uPrevEffect].m_uNextEffect == _uEffectId") == 1 )
    {
      __debugbreak();
    }
    *((_WORD *)this + 30 * *((unsigned __int16 *)this + 30 * a2 + 8442) + 8443) = *((_WORD *)this + 30 * a2 + 8443);
  }
  else
  {
    v4 = (Squares *)Squares::XYToVW(*((Squares **)this + 15 * a2 + 4211));
    v5 = Squares::XYToVW(*((Squares **)this + 15 * a2 + 4212));
    if ( !Squares::ValidVW(v4, v5) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2147, "Squares::ValidVW(iV, iW)") == 1 )
      __debugbreak();
    v3 = CEffects::EffectSquareListHeadVW(this, v4, v5);
    if ( *v3 != a2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2151, "rSquareListHead == _uEffectId") == 1 )
      __debugbreak();
    *v3 = *((_WORD *)this + 30 * a2 + 8443);
  }
  if ( *((_WORD *)this + 30 * a2 + 8443) )
  {
    if ( *((unsigned __int16 *)this + 30 * *((unsigned __int16 *)this + 30 * a2 + 8443) + 8442) != a2
      && BBSupportDbgReport(
           2,
           "Logic\\Effects.cpp",
           2158,
           "m_cEffects[rEffect.m_uNextEffect].m_uPrevEffect == _uEffectId") == 1 )
    {
      __debugbreak();
    }
    *((_WORD *)this + 30 * *((unsigned __int16 *)this + 30 * a2 + 8443) + 8442) = *((_WORD *)this + 30 * a2 + 8442);
  }
  result = (char *)this + 60 * a2 + 16828;
  *((_WORD *)this + 30 * a2 + 8442) = 0;
  *((_WORD *)this + 30 * a2 + 8443) = 0;
  return result;
}


// address=[0x144e170]
// Decompiled from __int16 __thiscall CEffects::CleanUp(CEffects *this)
void  CEffects::CleanUp(void) {
  
  __int16 result; // ax
  int v2; // [esp+0h] [ebp-20h]
  unsigned int TickCounter; // [esp+4h] [ebp-1Ch]
  int v4; // [esp+Ch] [ebp-14h]
  CEffect *v5; // [esp+10h] [ebp-10h]
  unsigned int i; // [esp+18h] [ebp-8h]
  bool v8; // [esp+1Fh] [ebp-1h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  *((_DWORD *)this + 69743) = 0;
  *((_DWORD *)this + 69744) = TickCounter;
  v4 = 1;
  result = (__int16)this;
  *((_WORD *)this + 8473) = 0;
  for ( i = 2; i < 0x1000; ++i )
  {
    v5 = (CEffects *)((char *)this + 60 * i + 16828);
    v8 = *(_BYTE *)v5 == 0;
    if ( *(_BYTE *)v5 )
    {
      v2 = CEffect::TimeIndex(v5, TickCounter);
      if ( CEffect::IsOutOfDate(v5, v2) )
      {
        CEffects::RemoveEffectFromList(this, i);
        v8 = 1;
      }
    }
    result = v8;
    if ( v8 )
    {
      j__memset(v5, 0, 0x3Cu);
      *((_WORD *)this + 30 * i + 8442) = v4;
      result = i;
      *((_WORD *)this + 30 * v4 + 8443) = i;
      v4 = i;
    }
  }
  return result;
}


// address=[0x144f340]
// Decompiled from bool __thiscall CEffects::CheckParentEffect(CEffects *this, unsigned int a2)
bool  CEffects::CheckParentEffect(unsigned int) {
  
  return a2 && a2 < 0x1000 && *((_BYTE *)this + 60 * a2 + 16828) && *((_BYTE *)this + 60 * a2 + 16828) != 11;
}


// address=[0x144f3b0]
// Decompiled from int *__cdecl CEffects::ClipXOrY(int *a1)
static void __cdecl CEffects::ClipXOrY(int &) {
  
  int *result; // eax

  result = a1;
  if ( *a1 >= 0 )
  {
    if ( *a1 > 1023 )
    {
      result = a1;
      *a1 = 1023;
    }
  }
  else
  {
    *a1 = 0;
  }
  return result;
}


// address=[0x144f3f0]
// Decompiled from void __thiscall CEffects::DecreaseMovingEffectCounter(CEffects *this, unsigned int a2)
void  CEffects::DecreaseMovingEffectCounter(int) {
  
  if ( a2 < 0x74 )
  {
    if ( *((int *)this + a2 + 69745) <= 0
      && BBSupportDbgReport(2, "Logic\\Effects.cpp", 2042, "m_iMovingEffectCounters[_iEffect] > 0") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)this + a2 + 69745) -= *((_DWORD *)this + a2 + 69745) > 0;
  }
}


// address=[0x144f4a0]
// Decompiled from char *__thiscall CEffects::EffectSquareListHeadVW(CEffects *this, int a2, int a3)
unsigned short &  CEffects::EffectSquareListHeadVW(int,int) {
  
  return (char *)this + 128 * a3 + 2 * a2 + 8380;
}


// address=[0x144f4d0]
// Decompiled from int __thiscall CEffects::FirstFreeEffectId(CEffects *this)
unsigned int  CEffects::FirstFreeEffectId(void) {
  
  return *((unsigned __int16 *)this + 8473);
}


// address=[0x144f650]
// Decompiled from unsigned int __thiscall CEffects::IncreaseMovingEffectCounter(CEffects *this, unsigned int a2)
void  CEffects::IncreaseMovingEffectCounter(int) {
  
  unsigned int result; // eax

  if ( a2 >= 0x74 )
    return result;
  result = a2;
  ++*((_DWORD *)this + a2 + 69745);
  return result;
}


// address=[0x144f6d0]
// Decompiled from CEffects *__thiscall CEffects::MoveEffectFromSquareListToFreeList(ATL::CDynamicAccessor *this, struct IUnknown *a2)
void  CEffects::MoveEffectFromSquareListToFreeList(unsigned int) {
  
  CEffects::RemoveEffectFromList(this, (unsigned int)a2);
  return CEffects::AddEffectToFreeList(this, (unsigned int)a2);
}


// address=[0x3f11f68]
// [Decompilation failed for static struct SGfxObjectInfo CEffects::m_sGfxInfo]

