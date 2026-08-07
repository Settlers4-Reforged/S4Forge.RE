#include "CAnimalEffect.h"

// Definitions for class CAnimalEffect

// address=[0x14d9390]
// Decompiled from CAnimalEffect *__thiscall CAnimalEffect::CAnimalEffect(CAnimalEffect *this)
 CAnimalEffect::CAnimalEffect(void) {
  
  CRandom16 *v2; // [esp+8h] [ebp-18h]
  CRandom16 *C; // [esp+Ch] [ebp-14h]

  C = (CRandom16 *)operator new(8u);
  if ( C )
  {
    v2 = CRandom16::CRandom16(C, (unsigned int)&byte_12AFD6E[116023]);
  }
  else
  {
    v2 = 0;
  }
  *(_DWORD *)this = v2;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 1) = 0;
  return this;
}


// address=[0x14d9480]
// Decompiled from void __thiscall CAnimalEffect::~CAnimalEffect(void **this)
 CAnimalEffect::~CAnimalEffect(void) {
  
  if ( *this )
  {
    operator delete(*this);
    *this = 0;
  }
}


// address=[0x14d94c0]
// Decompiled from void __thiscall CAnimalEffect::Update(CAnimalEffect *this, unsigned int a2, unsigned int a3, unsigned int a4, int a5)
void  CAnimalEffect::Update(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  int OutputWidth; // eax
  struct IEffects *v6; // eax
  int v7; // [esp-Ch] [ebp-60h]
  int v8; // [esp+0h] [ebp-54h]
  unsigned int v9; // [esp+4h] [ebp-50h]
  int v10; // [esp+Ch] [ebp-48h]
  int v11; // [esp+10h] [ebp-44h]
  int v12; // [esp+14h] [ebp-40h]
  int v13; // [esp+18h] [ebp-3Ch]
  int v14; // [esp+1Ch] [ebp-38h] BYREF
  int v15; // [esp+20h] [ebp-34h] BYREF
  struct IEffects *v16; // [esp+24h] [ebp-30h]
  struct IEffects *v17; // [esp+28h] [ebp-2Ch]
  int v18; // [esp+2Ch] [ebp-28h] BYREF
  struct IEffects *v19; // [esp+30h] [ebp-24h]
  int *AnimalEffectDataPtr; // [esp+34h] [ebp-20h]
  unsigned int v21; // [esp+38h] [ebp-1Ch]
  CAnimalEffect *v22; // [esp+3Ch] [ebp-18h]
  int v23; // [esp+40h] [ebp-14h] BYREF
  int v24; // [esp+44h] [ebp-10h]
  int v25; // [esp+48h] [ebp-Ch] BYREF
  int v26; // [esp+4Ch] [ebp-8h] BYREF
  char updated; // [esp+53h] [ebp-1h]

  v22 = this;
  updated = 0;
  v19 = CLogic::Effects(g_pLogic);
  v19->GetMovingEffectInfo(v19, a2, &v23, &v25, &v26, &v18);
  v24 = v23 - 11;
  switch ( v23 )
  {
    case 11:
    case 12:
    case 13:
      v21 = v23 - 11;
      updated = CAnimalEffect::UpdateButterfly(v22, a2, v25, v26, v18, a5);
      break;
    case 14:
      v21 = 3;
      updated = CAnimalEffect::UpdateBird(v22, a2, v25, v26, a5);
      break;
    case 15:
    case 16:
      v21 = v23 - 11;
      updated = CAnimalEffect::UpdateSeagull(v22, a2, v25, v26, a5);
      break;
    case 17:
    case 18:
      v21 = v23 - 11;
      updated = CAnimalEffect::UpdateDuck(v22, a2, v25, v26, v18);
      break;
    default:
      break;
  }
  if ( updated )
  {
    AnimalEffectDataPtr = CAnimalMgr::GetAnimalEffectDataPtr((CAnimalMgr *)&g_cAnimalMgr, v21);
    if ( AnimalEffectDataPtr[8] )
    {
      v17 = CLogic::Effects(g_pLogic);
      v9 = v17->GetMovingEffectSoundId(v17, a2);
      if ( !CSoundManager::IsPlaying(g_pSoundManager, v9) )
      {
        v16 = CLogic::Effects(g_pLogic);
        v16->SetMovingEffectSoundId(v16, a2, -1);
        v7 = IGfxEngine::GetOutputHeight(g_pGfxEngine) >> 1;
        OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
        IGfxEngine::GetClosestMapPoint(g_pGfxEngine, OutputWidth >> 1, v7, &v15, &v14);
        if ( v14 >= 0 && v15 >= 0 )
        {
          v13 = Squares::XYToVW(v15);
          v11 = Squares::XYToVW(v14);
          v12 = Squares::XYToVW(v25);
          v10 = Squares::XYToVW(v26);
          if ( v12 >= v13 - 1 && v12 <= v13 + 1 && v10 >= v11 - 1 && v10 <= v11 + 1 && (*((_BYTE *)AnimalEffectDataPtr + 36) == 100 || j__rand() % 100 + 1 <= *((unsigned __int8 *)AnimalEffectDataPtr + 36)) )
          {
            if ( (*(unsigned __int8 (__thiscall **)(void *, int, int))(*(_DWORD *)g_pFogging + 32))(g_pFogging, v25, v26) )
            {
              v8 = CSoundManager::PlayEnvironmentSound(g_pSoundManager, AnimalEffectDataPtr[8], v25, v26, 0);
              v6 = CLogic::Effects(g_pLogic);
              v6->SetMovingEffectSoundId(v6, a2, v8);
            }
          }
        }
      }
    }
  }
}


// address=[0x14d97b0]
// Decompiled from void __thiscall CAnimalEffect::SetCurrentAmoutButterflies(CPaneContainer *this, struct CPaneDivider *a2)
void  CAnimalEffect::SetCurrentAmoutButterflies(int a2) {
  
  *((_DWORD *)this + 3) = a2;
}


// address=[0x14d97d0]
// Decompiled from CAnimalEffect *__thiscall CAnimalEffect::SetMaxAmountButterflies(CAnimalEffect *this, int a2)
void  CAnimalEffect::SetMaxAmountButterflies(int a2) {
  
  CAnimalEffect *result; // eax

  result = this;
  *((_DWORD *)this + 2) = a2;
  return result;
}


// address=[0x14d97f0]
// Decompiled from int __thiscall CAnimalEffect::AddButterfly(CRandom16 **this, int a2, int a3)
int  CAnimalEffect::AddButterfly(int a2, int a3) {
  
  int v3; // eax
  unsigned int v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+4h] [ebp-Ch]

  v5 = CRandom16::Rand(*this) % 3 + 11;
  v3 = CLogic::Effects((DWORD *)g_pLogic);
  v6 = (*(int (__thiscall **)(int, unsigned int, int, int))(*(_DWORD *)v3 + 40))(v3, v5, a2, a3);
  if ( !v6 )
  {
    return v6;
  }
  this[3] = (CRandom16 *)((char *)this[3] + 1);
  if ( (int)this[3] >= (int)this[2] )
  {
    this[4] = (CRandom16 *)((char *)this[4] + 1);
  }
  return v6;
}


// address=[0x14d9880]
// Decompiled from void __thiscall CAnimalEffect::SetCurrentAmoutBirds(CPaneContainer *this, struct CPaneContainer *a2)
void  CAnimalEffect::SetCurrentAmoutBirds(int a2) {
  
  *((_DWORD *)this + 6) = a2;
}


// address=[0x14d98a0]
// Decompiled from void __thiscall CAnimalEffect::SetMaxAmountBirds(CBaseTransition *this, struct CAnimationVariable *a2)
void  CAnimalEffect::SetMaxAmountBirds(int a2) {
  
  *((_DWORD *)this + 5) = a2;
}


// address=[0x14d98c0]
// Decompiled from int __thiscall CAnimalEffect::AddBird(CAnimalEffect *this, int a2, int a3)
int  CAnimalEffect::AddBird(int a2, int a3) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-Ch]

  v3 = CLogic::Effects((DWORD *)g_pLogic);
  v5 = (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v3 + 40))(v3, 14, a2, a3);
  if ( !v5 )
  {
    return v5;
  }
  if ( ++*((_DWORD *)this + 6) >= *((_DWORD *)this + 5) )
  {
    ++*((_DWORD *)this + 7);
  }
  return v5;
}


// address=[0x14d9930]
// Decompiled from void __thiscall CAnimalEffect::SetCurrentAmoutSeagulls(CMFCToolBarButton *this, unsigned int a2)
void  CAnimalEffect::SetCurrentAmoutSeagulls(int a2) {
  
  *((_DWORD *)this + 9) = a2;
}


// address=[0x14d9950]
// Decompiled from void __thiscall CAnimalEffect::SetMaxAmountSeagulls(CPaneContainer *this, int a2)
void  CAnimalEffect::SetMaxAmountSeagulls(int a2) {
  
  *((_DWORD *)this + 8) = a2;
}


// address=[0x14d9970]
// Decompiled from int __thiscall CAnimalEffect::AddSeagull(CAnimalEffect *this, int a2, int a3)
int  CAnimalEffect::AddSeagull(int a2, int a3) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-Ch]

  v3 = CLogic::Effects((DWORD *)g_pLogic);
  v5 = (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v3 + 40))(v3, 15, a2, a3);
  if ( !v5 )
  {
    return v5;
  }
  if ( ++*((_DWORD *)this + 9) >= *((_DWORD *)this + 8) )
  {
    ++*((_DWORD *)this + 10);
  }
  return v5;
}


// address=[0x14d99e0]
// Decompiled from _DWORD *__thiscall CAnimalEffect::SetCurrentAmoutDucks(_DWORD *this, int a2)
void  CAnimalEffect::SetCurrentAmoutDucks(int a2) {
  
  _DWORD *result; // eax

  result = this;
  this[12] = a2;
  return result;
}


// address=[0x14d9a00]
// Decompiled from void __thiscall CAnimalEffect::SetMaxAmountDucks(CMFCCaptionButton *this, int a2)
void  CAnimalEffect::SetMaxAmountDucks(int a2) {
  
  *((_DWORD *)this + 11) = a2;
}


// address=[0x14d9a20]
// Decompiled from int __thiscall CAnimalEffect::AddDuck(CAnimalEffect *this, int a2, int a3)
int  CAnimalEffect::AddDuck(int a2, int a3) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-Ch]

  v3 = CLogic::Effects((DWORD *)g_pLogic);
  v5 = (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v3 + 40))(v3, 17, a2, a3);
  if ( !v5 )
  {
    return v5;
  }
  if ( ++*((_DWORD *)this + 12) >= *((_DWORD *)this + 11) )
  {
    ++*((_DWORD *)this + 13);
  }
  return v5;
}


// address=[0x14d9a90]
// Decompiled from char __thiscall CAnimalEffect::UpdateButterfly(CAnimalEffect *this, int a2, int a3, int a4, int a5, int a6)
bool  CAnimalEffect::UpdateButterfly(int a2, int a3, int a4, int a5, int a6) {
  
  IEffects *v6; // eax
  IEffects *v8; // eax
  struct IFutureEvents *v9; // eax
  IEffects *v10; // eax
  int v11; // [esp-18h] [ebp-64h]
  unsigned int v12; // [esp-Ch] [ebp-58h]
  unsigned int v13; // [esp-8h] [ebp-54h]
  unsigned int v14; // [esp-4h] [ebp-50h]
  int v15; // [esp+0h] [ebp-4Ch] BYREF
  int v16; // [esp+4h] [ebp-48h] BYREF
  int v17; // [esp+8h] [ebp-44h]
  int v18; // [esp+Ch] [ebp-40h]
  int v19; // [esp+10h] [ebp-3Ch]
  int v20; // [esp+14h] [ebp-38h]
  int v21; // [esp+18h] [ebp-34h]
  int ScreenOffsetsByMapIndices; // [esp+1Ch] [ebp-30h]
  int v23; // [esp+20h] [ebp-2Ch]
  struct IEffects *v24; // [esp+24h] [ebp-28h]
  struct IEffects *v25; // [esp+28h] [ebp-24h]
  int i; // [esp+2Ch] [ebp-20h]
  int v27; // [esp+30h] [ebp-1Ch]
  int j; // [esp+34h] [ebp-18h]
  CAnimalEffect *v29; // [esp+38h] [ebp-14h]
  int v30; // [esp+3Ch] [ebp-10h]
  int v31; // [esp+40h] [ebp-Ch]
  DWORD v32; // [esp+44h] [ebp-8h]
  char v33; // [esp+49h] [ebp-3h]
  char v34; // [esp+4Ah] [ebp-2h]
  char v35; // [esp+4Bh] [ebp-1h]

  v29 = this;
  v35 = 0;
  if ( *((_DWORD *)this + 4) )
  {
    ScreenOffsetsByMapIndices = IGfxEngine::GetScreenOffsetsByMapIndices(a3, a4, &v15, &v16);
    if ( ScreenOffsetsByMapIndices != 3 )
    {
      v6 = CLogic::Effects(g_pLogic);
      IEffects::DeleteMovingEffect(v6, a2);
      --*((_DWORD *)v29 + 4);
      --*((_DWORD *)v29 + 3);
      return 0;
    }
  }
  v21 = CWorldManager::Index(a3, a4);
  v27 = (a6 & 0xFF00) >> 8;
  if ( CWorldManager::FlagBits(v21, 4u) )
  {
    if ( ++v27 > 0 )
    {
      v8 = CLogic::Effects(g_pLogic);
      IEffects::DeleteMovingEffect(v8, a2);
      v25 = CLogic::Effects(g_pLogic);
      v25->AddEffect(v25, EFFECT_ANIM_SMOKE, 69, a3, a4, 0, 0, 0);
      --*((_DWORD *)v29 + 3);
      return 0;
    }
  }
  else
  {
    v27 = 0;
  }
  v32 = CRandom16::Rand(*(CRandom16 **)v29) % 0xC;
  v30 = a3 + CSpiralOffsets::DeltaX(v32 + 7);
  v31 = a4 + CSpiralOffsets::DeltaY(v32 + 7);
  v20 = Squares::XYToVW(v30);
  v19 = Squares::XYToVW(v31);
  v35 = CAnimalMgr::CheckButterflyUnderground((CAnimalMgr *)&g_cAnimalMgr, v30, v31);
  for ( i = 0;
        !v35 && i < 12;
        ++i )
  {
    if ( (int)++v32 > 12 )
    {
      v32 = 0;
    }
    v30 = a3 + CSpiralOffsets::DeltaX(v32 + 7);
    v31 = a4 + CSpiralOffsets::DeltaY(v32 + 7);
    v20 = Squares::XYToVW(v30);
    v19 = Squares::XYToVW(v31);
    v35 = CAnimalMgr::CheckButterflyUnderground((CAnimalMgr *)&g_cAnimalMgr, v30, v31);
  }
  if ( !v35 )
  {
    v32 = a5 + 6;
    if ( a5 + 6 > 12 )
    {
      v32 -= 12;
    }
    v30 = a3 + CSpiralOffsets::DeltaX(v32 + 7);
    v31 = a4 + CSpiralOffsets::DeltaY(v32 + 7);
  }
  if ( !CAnimalMgr::CheckButterflyUnderground((CAnimalMgr *)&g_cAnimalMgr, v30, v31) )
  {
    v17 = CSpiralOffsets::First(30);
    v18 = 19;
    v34 = 0;
    for ( j = 19;
          j < v17;
          ++j )
    {
      v30 = a3 + CSpiralOffsets::DeltaX(j);
      v31 = a4 + CSpiralOffsets::DeltaY(j);
      if ( CAnimalMgr::CheckButterflyUndergroundFast((CAnimalMgr *)&g_cAnimalMgr, v30, v31) )
      {
        v34 = 1;
        break;
      }
    }
    if ( !v34 && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalEffect.cpp", 522, "bFound") == 1 )
    {
      __debugbreak();
    }
  }
  if ( !CWorldManager::InWorld(v30, v31) && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalEffect.cpp", 526, "g_cWorld.InWorld( iNewX, iNewY )") == 1 )
  {
    __debugbreak();
  }
  v24 = CLogic::Effects(g_pLogic);
  v23 = ((int (__thiscall *)(struct IEffects *, int, int, int, _DWORD))v24->j_?SetMovingEffectDestination@CEffects@@UAEIIHHH@Z)(v24, a2, v30, v31, 0);
  if ( !v23 )
  {
    return 1;
  }
  v14 = ((unsigned __int8)v27 << 8) + (unsigned __int8)v32;
  v13 = v31;
  v12 = v30;
  v11 = v23;
  v9 = CLogic::FutureEvents(g_pLogic);
  v33 = IFutureEvents::AddFutureEvent16(v9, 7, v11, 0, a2, v12, v13, v14);
  if ( v33 )
  {
    return v33;
  }
  v10 = CLogic::Effects(g_pLogic);
  IEffects::DeleteMovingEffect(v10, a2);
  return v33;
}


// address=[0x14d9ea0]
// Decompiled from char __thiscall CAnimalEffect::UpdateBird(CAnimalEffect *this, int a2, int a3, int a4, int a5)
bool  CAnimalEffect::UpdateBird(int a2, int a3, int a4, int a5) {
  
  IEffects *v5; // eax
  IEffects *v7; // eax
  struct IFutureEvents *v8; // eax
  int v9; // [esp-18h] [ebp-68h]
  unsigned int v10; // [esp-Ch] [ebp-5Ch]
  unsigned int v11; // [esp-8h] [ebp-58h]
  unsigned int v12; // [esp-4h] [ebp-54h]
  int v13; // [esp+0h] [ebp-50h] BYREF
  int v14; // [esp+4h] [ebp-4Ch] BYREF
  int v15; // [esp+8h] [ebp-48h]
  int v16; // [esp+Ch] [ebp-44h]
  signed int v17; // [esp+10h] [ebp-40h]
  signed int v18; // [esp+14h] [ebp-3Ch]
  int v19; // [esp+18h] [ebp-38h]
  int ScreenOffsetsByMapIndices; // [esp+1Ch] [ebp-34h]
  int v21; // [esp+20h] [ebp-30h]
  struct IEffects *v22; // [esp+24h] [ebp-2Ch]
  signed int v23; // [esp+28h] [ebp-28h]
  struct IEffects *v24; // [esp+2Ch] [ebp-24h]
  int i; // [esp+30h] [ebp-20h]
  signed int v26; // [esp+34h] [ebp-1Ch]
  int v27; // [esp+38h] [ebp-18h]
  int v28; // [esp+3Ch] [ebp-14h]
  int v29; // [esp+40h] [ebp-10h]
  CAnimalEffect *v30; // [esp+44h] [ebp-Ch]
  int v31; // [esp+48h] [ebp-8h]
  char v33; // [esp+4Fh] [ebp-1h]

  v30 = this;
  v33 = 0;
  if ( *((_DWORD *)this + 7) )
  {
    ScreenOffsetsByMapIndices = IGfxEngine::GetScreenOffsetsByMapIndices(a3, a4, &v13, &v14);
    if ( ScreenOffsetsByMapIndices != 3 )
    {
LABEL_3:
      v5 = CLogic::Effects(g_pLogic);
      IEffects::DeleteMovingEffect(v5, a2);
      --*((_DWORD *)v30 + 7);
      --*((_DWORD *)v30 + 6);
      return 0;
    }
  }
  v19 = CWorldManager::Index(a3, a4);
  v27 = (a5 & 0xFF00) >> 8;
  if ( CWorldManager::FlagBits(v19, 4u) )
  {
    if ( ++v27 > 0 )
    {
      v7 = CLogic::Effects(g_pLogic);
      IEffects::DeleteMovingEffect(v7, a2);
      v24 = CLogic::Effects(g_pLogic);
      v24->AddEffect(v24, EFFECT_ANIM_SMOKE, 69, a3, a4, 0, 0, 0);
      --*((_DWORD *)v30 + 6);
      return 0;
    }
  }
  else
  {
    v27 = 0;
  }
  v17 = CRandom16::PercentValue(0x19u);
  v23 = CRandom16::PercentValue(0x32u);
  v31 = (unsigned __int8)a5;
  v18 = CRandom16::Rand(*(CRandom16 **)v30);
  if ( v18 < v17 )
  {
    v26 = CRandom16::Rand(*(CRandom16 **)v30);
    if ( v26 >= v23 )
    {
      if ( --v31 < 0 )
      {
        v31 = 11;
      }
    }
    else if ( ++v31 > 12 )
    {
      v31 = 0;
    }
  }
  v28 = a3 + CSpiralOffsets::DeltaX(v31 + 7);
  v29 = a4 + CSpiralOffsets::DeltaY(v31 + 7);
  v16 = Squares::XYToVW(v28);
  v15 = Squares::XYToVW(v29);
  v33 = CAnimalMgr::CheckBirdUnderground((CAnimalMgr *)&g_cAnimalMgr, v28, v29);
  v26 = CRandom16::Rand(*(CRandom16 **)v30);
  for ( i = 0;
        !v33 && i < 12;
        ++i )
  {
    if ( v26 >= v23 )
    {
      if ( --v31 < 0 )
      {
        v31 = 11;
      }
    }
    else if ( ++v31 > 12 )
    {
      v31 = 0;
    }
    v28 = a3 + CSpiralOffsets::DeltaX(v31 + 7);
    v29 = a4 + CSpiralOffsets::DeltaY(v31 + 7);
    v16 = Squares::XYToVW(v28);
    v15 = Squares::XYToVW(v29);
    v33 = CAnimalMgr::CheckBirdUnderground((CAnimalMgr *)&g_cAnimalMgr, v28, v29);
  }
  if ( !v33 )
  {
    v31 = a5 + 6;
    if ( a5 + 6 > 12 )
    {
      v31 -= 12;
    }
    v28 = a3 + CSpiralOffsets::DeltaX(v31 + 7);
    v29 = a4 + CSpiralOffsets::DeltaY(v31 + 7);
  }
  if ( !CWorldManager::InWorld(v28, v29) && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalEffect.cpp", 685, "g_cWorld.InWorld( iNewX, iNewY )") == 1 )
  {
    __debugbreak();
  }
  v22 = CLogic::Effects(g_pLogic);
  v21 = ((int (__thiscall *)(struct IEffects *, int, int, int, _DWORD))v22->j_?SetMovingEffectDestination@CEffects@@UAEIIHHH@Z)(v22, a2, v28, v29, 0);
  if ( !v21 )
  {
    return 1;
  }
  v12 = ((unsigned __int8)v27 << 8) + (unsigned __int8)v31;
  v11 = v29;
  v10 = v28;
  v9 = v21;
  v8 = CLogic::FutureEvents(g_pLogic);
  if ( !(unsigned __int8)IFutureEvents::AddFutureEvent16(v8, 7, v9, 0, a2, v10, v11, v12) )
  {
    goto LABEL_3;
  }
  return 1;
}


// address=[0x14da2a0]
// Decompiled from char __thiscall CAnimalEffect::UpdateSeagull(CAnimalEffect *this, int a2, int a3, int a4, int a5)
bool  CAnimalEffect::UpdateSeagull(int a2, int a3, int a4, int a5) {
  
  IEffects *v5; // eax
  IEffects *v7; // eax
  IEffects *v8; // eax
  struct IFutureEvents *v9; // eax
  IEffects *v10; // eax
  int v11; // [esp-18h] [ebp-80h]
  unsigned int v12; // [esp-Ch] [ebp-74h]
  unsigned int v13; // [esp-8h] [ebp-70h]
  unsigned int v14; // [esp-4h] [ebp-6Ch]
  _BYTE v15[4]; // [esp+0h] [ebp-68h] BYREF
  _BYTE v16[4]; // [esp+4h] [ebp-64h] BYREF
  _BYTE v17[4]; // [esp+8h] [ebp-60h] BYREF
  int v18; // [esp+Ch] [ebp-5Ch]
  int v19; // [esp+10h] [ebp-58h] BYREF
  int v20; // [esp+14h] [ebp-54h] BYREF
  int ScreenOffsetsByMapIndices; // [esp+18h] [ebp-50h]
  int v22; // [esp+1Ch] [ebp-4Ch]
  struct IEffects *v23; // [esp+20h] [ebp-48h]
  struct IEffects *v24; // [esp+24h] [ebp-44h]
  signed int v25; // [esp+28h] [ebp-40h]
  signed int v26; // [esp+2Ch] [ebp-3Ch]
  struct IEffects *v27; // [esp+30h] [ebp-38h]
  BOOL v28; // [esp+34h] [ebp-34h]
  signed int v29; // [esp+38h] [ebp-30h]
  BOOL v30; // [esp+3Ch] [ebp-2Ch]
  int i; // [esp+40h] [ebp-28h]
  int v32; // [esp+44h] [ebp-24h]
  int v33; // [esp+48h] [ebp-20h]
  int v34; // [esp+4Ch] [ebp-1Ch] BYREF
  signed int v35; // [esp+50h] [ebp-18h]
  int v36; // [esp+54h] [ebp-14h]
  int v37; // [esp+58h] [ebp-10h]
  CAnimalEffect *v38; // [esp+5Ch] [ebp-Ch]
  int v39; // [esp+60h] [ebp-8h]
  bool v41; // [esp+67h] [ebp-1h]

  v38 = this;
  v41 = 0;
  if ( !CWorldManager::InWorld(a3, a4) && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalEffect.cpp", 728, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( CWorldManager::InWorld(a3, a4) )
  {
    if ( !*((_DWORD *)v38 + 10) || (ScreenOffsetsByMapIndices = IGfxEngine::GetScreenOffsetsByMapIndices(a3, a4, &v19, &v20), ScreenOffsetsByMapIndices == 3) )
    {
      v25 = CRandom16::PercentValue(0x19u);
      v29 = CRandom16::PercentValue(0x32u);
      v39 = a5;
      v26 = CRandom16::Rand(*(CRandom16 **)v38);
      if ( v26 < v25 )
      {
        v35 = CRandom16::Rand(*(CRandom16 **)v38);
        if ( v35 >= v29 )
        {
          if ( --v39 < 0 )
          {
            v39 = 11;
          }
        }
        else if ( ++v39 > 12 )
        {
          v39 = 0;
        }
      }
      v36 = a3 + CSpiralOffsets::DeltaX(v39 + 7);
      v37 = a4 + CSpiralOffsets::DeltaY(v39 + 7);
      v32 = Squares::XYToVW(v36);
      v33 = Squares::XYToVW(v37);
      v30 = CAnimalMgr::IsSeagullLand((CAnimalMgr *)&g_cAnimalMgr, v32, v33) && CAnimalMgr::CheckSeagullUndergroundAddPosition((CAnimalMgr *)&g_cAnimalMgr, v36, v37);
      v41 = v30;
      v35 = CRandom16::Rand(*(CRandom16 **)v38);
      for ( i = 0;
            !v41 && i < 12;
            ++i )
      {
        if ( v35 >= v29 )
        {
          if ( --v39 < 0 )
          {
            v39 = 11;
          }
        }
        else if ( ++v39 > 12 )
        {
          v39 = 0;
        }
        v36 = a3 + CSpiralOffsets::DeltaX(v39 + 7);
        v37 = a4 + CSpiralOffsets::DeltaY(v39 + 7);
        v32 = Squares::XYToVW(v36);
        v33 = Squares::XYToVW(v37);
        v28 = CAnimalMgr::IsSeagullLand((CAnimalMgr *)&g_cAnimalMgr, v32, v33) && CAnimalMgr::CheckSeagullUndergroundAddPosition((CAnimalMgr *)&g_cAnimalMgr, v36, v37);
        v41 = v28;
      }
      if ( !v41 )
      {
        v39 = a5 + 6;
        if ( a5 + 6 > 12 )
        {
          v39 -= 12;
        }
        v36 = a3 + CSpiralOffsets::DeltaX(v39 + 7);
        v37 = a4 + CSpiralOffsets::DeltaY(v39 + 7);
      }
      v18 = CWorldManager::Width();
      if ( CWorldManager::InWorld(v36, v37) )
      {
        v27 = CLogic::Effects(g_pLogic);
        v27->GetMovingEffectInfo((CEffects *)v27, a2, &v34, (int *)v15, (int *)v16, (int *)v17);
        v35 = CRandom16::Rand(*(CRandom16 **)v38);
        if ( v26 < v25 )
        {
          if ( v34 == 15 )
          {
            v34 = 16;
          }
          else
          {
            v34 = 15;
          }
          v24 = CLogic::Effects(g_pLogic);
          ((void (__thiscall *)(struct IEffects *, int, int))v24->j_?ChangeMovingEffectType@CEffects@@UAEXIH@Z)(v24, a2, v34);
        }
        v23 = CLogic::Effects(g_pLogic);
        v22 = ((int (__thiscall *)(struct IEffects *, int, int, int, _DWORD))v23->j_?SetMovingEffectDestination@CEffects@@UAEIIHHH@Z)(v23, a2, v36, v37, 0);
        if ( !v22 )
        {
          return 1;
        }
        v14 = v39;
        v13 = v37;
        v12 = v36;
        v11 = v22;
        v9 = CLogic::FutureEvents(g_pLogic);
        if ( (unsigned __int8)IFutureEvents::AddFutureEvent16(v9, 7, v11, 0, a2, v12, v13, v14) )
        {
          return 1;
        }
        else
        {
          v10 = CLogic::Effects(g_pLogic);
          IEffects::DeleteMovingEffect(v10, a2);
          --*((_DWORD *)v38 + 10);
          --*((_DWORD *)v38 + 9);
          return 0;
        }
      }
      else
      {
        v8 = CLogic::Effects(g_pLogic);
        IEffects::DeleteMovingEffect(v8, a2);
        if ( *((int *)v38 + 10) > 0 )
        {
          --*((_DWORD *)v38 + 10);
        }
        if ( *((int *)v38 + 9) > 0 )
        {
          --*((_DWORD *)v38 + 9);
        }
        return 0;
      }
    }
    else
    {
      v7 = CLogic::Effects(g_pLogic);
      IEffects::DeleteMovingEffect(v7, a2);
      --*((_DWORD *)v38 + 10);
      --*((_DWORD *)v38 + 9);
      return 0;
    }
  }
  else
  {
    v5 = CLogic::Effects(g_pLogic);
    IEffects::DeleteMovingEffect(v5, a2);
    if ( *((int *)v38 + 10) > 0 )
    {
      --*((_DWORD *)v38 + 10);
    }
    if ( *((int *)v38 + 9) > 0 )
    {
      --*((_DWORD *)v38 + 9);
    }
    return 0;
  }
}


// address=[0x14da790]
// Decompiled from char __thiscall CAnimalEffect::UpdateDuck(CAnimalEffect *this, int a2, int a3, int a4, int a5)
bool  CAnimalEffect::UpdateDuck(int a2, int a3, int a4, int a5) {
  
  return 1;
}


