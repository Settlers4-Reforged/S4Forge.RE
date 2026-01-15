#include "CAnimalEffect.h"

// Definitions for class CAnimalEffect

// address=[0x14d9390]
// Decompiled from CAnimalEffect *__thiscall CAnimalEffect::CAnimalEffect(CAnimalEffect *this)
 CAnimalEffect::CAnimalEffect(void) {
  
  CRandom16 *v2; // [esp+8h] [ebp-18h]
  CRandom16 *C; // [esp+Ch] [ebp-14h]

  C = (CRandom16 *)operator new(8u);
  if ( C )
    v2 = CRandom16::CRandom16(C, (unsigned int)&byte_12AFD6E[116023]);
  else
    v2 = 0;
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
// Decompiled from char __thiscall CAnimalEffect::Update(  CAnimalEffect *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  unsigned int a5)
void  CAnimalEffect::Update(unsigned int,unsigned int,unsigned int,unsigned int) {
  
  struct SAnimalData *AnimalEffectDataPtr; // eax
  int OutputWidth; // eax
  int v7; // edx
  int v8; // eax
  int v10; // [esp-Ch] [ebp-60h]
  int v11; // [esp+0h] [ebp-54h]
  unsigned int v12; // [esp+4h] [ebp-50h]
  struct SAnimalData *v13; // [esp+Ch] [ebp-48h]
  int v14; // [esp+10h] [ebp-44h]
  int v15; // [esp+14h] [ebp-40h]
  int v16; // [esp+18h] [ebp-3Ch]
  Squares *v17; // [esp+1Ch] [ebp-38h] BYREF
  Squares *v18; // [esp+20h] [ebp-34h] BYREF
  int v19; // [esp+24h] [ebp-30h]
  int v20; // [esp+28h] [ebp-2Ch]
  int v21; // [esp+2Ch] [ebp-28h] BYREF
  int v22; // [esp+30h] [ebp-24h]
  struct SAnimalData *v23; // [esp+34h] [ebp-20h]
  int v24; // [esp+38h] [ebp-1Ch]
  CAnimalEffect *v25; // [esp+3Ch] [ebp-18h]
  _DWORD v26[2]; // [esp+40h] [ebp-14h] BYREF
  Squares *v27; // [esp+48h] [ebp-Ch] BYREF
  Squares *v28; // [esp+4Ch] [ebp-8h] BYREF
  char v29; // [esp+53h] [ebp-1h]

  v25 = this;
  v29 = 0;
  v22 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, unsigned int, _DWORD *, Squares **, Squares **, int *))(*(_DWORD *)v22 + 52))(
    v22,
    a2,
    v26,
    &v27,
    &v28,
    &v21);
  LOBYTE(AnimalEffectDataPtr) = v26[0];
  v26[1] = v26[0] - 11;
  switch ( v26[0] )
  {
    case 0xB:
    case 0xC:
    case 0xD:
      v24 = v26[0] - 11;
      LOBYTE(AnimalEffectDataPtr) = CAnimalEffect::UpdateButterfly(v25, a2, v27, v28, v21, a5);
      v29 = (char)AnimalEffectDataPtr;
      break;
    case 0xE:
      v24 = 3;
      LOBYTE(AnimalEffectDataPtr) = CAnimalEffect::UpdateBird(v25, a2, v27, v28, a5);
      v29 = (char)AnimalEffectDataPtr;
      break;
    case 0xF:
    case 0x10:
      v24 = v26[0] - 11;
      LOBYTE(AnimalEffectDataPtr) = CAnimalEffect::UpdateSeagull(v25, a2, v27, v28, a5);
      v29 = (char)AnimalEffectDataPtr;
      break;
    case 0x11:
    case 0x12:
      v24 = v26[0] - 11;
      LOBYTE(AnimalEffectDataPtr) = CAnimalEffect::UpdateDuck(v25, a2, v27, v28, v21);
      v29 = (char)AnimalEffectDataPtr;
      break;
    default:
      break;
  }
  if ( !v29 )
    return (char)AnimalEffectDataPtr;
  AnimalEffectDataPtr = CAnimalMgr::GetAnimalEffectDataPtr((CAnimalMgr *)&g_cAnimalMgr, v24);
  v23 = AnimalEffectDataPtr;
  if ( !*((_DWORD *)AnimalEffectDataPtr + 8) )
    return (char)AnimalEffectDataPtr;
  v20 = CLogic::Effects((DWORD *)g_pLogic);
  v12 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v20 + 72))(v20, a2);
  LOBYTE(AnimalEffectDataPtr) = CSoundManager::IsPlaying((CSoundManager *)g_pSoundManager, v12);
  if ( (_BYTE)AnimalEffectDataPtr )
    return (char)AnimalEffectDataPtr;
  v19 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v19 + 76))(v19, a2, -1);
  v10 = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine) >> 1;
  OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  LOBYTE(AnimalEffectDataPtr) = IGfxEngine::GetClosestMapPoint(
                                  (IGfxEngine *)g_pGfxEngine,
                                  OutputWidth >> 1,
                                  v10,
                                  (int *)&v18,
                                  (int *)&v17);
  if ( (int)v17 < 0 || (int)v18 < 0 )
    return (char)AnimalEffectDataPtr;
  v16 = Squares::XYToVW(v18);
  v14 = Squares::XYToVW(v17);
  v15 = Squares::XYToVW(v27);
  AnimalEffectDataPtr = (struct SAnimalData *)Squares::XYToVW(v28);
  v13 = AnimalEffectDataPtr;
  if ( v15 < v16 - 1 || v15 > v16 + 1 )
    return (char)AnimalEffectDataPtr;
  LOBYTE(AnimalEffectDataPtr) = v14 - 1;
  if ( (int)v13 < v14 - 1 || (int)v13 > v14 + 1 )
    return (char)AnimalEffectDataPtr;
  if ( *((_BYTE *)v23 + 36) != 100 )
  {
    v7 = j__rand() % 100 + 1;
    LOBYTE(AnimalEffectDataPtr) = (_BYTE)v23;
    if ( v7 > *((unsigned __int8 *)v23 + 36) )
      return (char)AnimalEffectDataPtr;
  }
  LOBYTE(AnimalEffectDataPtr) = (*(int (__thiscall **)(void *, Squares *, Squares *))(*(_DWORD *)g_pFogging + 32))(
                                  g_pFogging,
                                  v27,
                                  v28);
  if ( !(_BYTE)AnimalEffectDataPtr )
    return (char)AnimalEffectDataPtr;
  v11 = CSoundManager::PlayEnvironmentSound(g_pSoundManager, *((_DWORD *)v23 + 8), v27, v28, 0);
  v8 = CLogic::Effects((DWORD *)g_pLogic);
  LOBYTE(AnimalEffectDataPtr) = (*(int (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v8 + 76))(v8, a2, v11);
  return (char)AnimalEffectDataPtr;
}


// address=[0x14d97b0]
// Decompiled from void __thiscall CAnimalEffect::SetCurrentAmoutButterflies(CPaneContainer *this, struct CPaneDivider *a2)
void  CAnimalEffect::SetCurrentAmoutButterflies(int) {
  
  *((_DWORD *)this + 3) = a2;
}


// address=[0x14d97d0]
// Decompiled from CAnimalEffect *__thiscall CAnimalEffect::SetMaxAmountButterflies(CAnimalEffect *this, int a2)
void  CAnimalEffect::SetMaxAmountButterflies(int) {
  
  CAnimalEffect *result; // eax

  result = this;
  *((_DWORD *)this + 2) = a2;
  return result;
}


// address=[0x14d97f0]
// Decompiled from int __thiscall CAnimalEffect::AddButterfly(CRandom16 **this, int a2, int a3)
int  CAnimalEffect::AddButterfly(int,int) {
  
  int v3; // eax
  unsigned int v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+4h] [ebp-Ch]

  v5 = CRandom16::Rand(*this) % 3 + 11;
  v3 = CLogic::Effects((DWORD *)g_pLogic);
  v6 = (*(int (__thiscall **)(int, unsigned int, int, int))(*(_DWORD *)v3 + 40))(v3, v5, a2, a3);
  if ( !v6 )
    return v6;
  this[3] = (CRandom16 *)((char *)this[3] + 1);
  if ( (int)this[3] >= (int)this[2] )
    this[4] = (CRandom16 *)((char *)this[4] + 1);
  return v6;
}


// address=[0x14d9880]
// Decompiled from void __thiscall CAnimalEffect::SetCurrentAmoutBirds(CPaneContainer *this, struct CPaneContainer *a2)
void  CAnimalEffect::SetCurrentAmoutBirds(int) {
  
  *((_DWORD *)this + 6) = a2;
}


// address=[0x14d98a0]
// Decompiled from void __thiscall CAnimalEffect::SetMaxAmountBirds(CBaseTransition *this, struct CAnimationVariable *a2)
void  CAnimalEffect::SetMaxAmountBirds(int) {
  
  *((_DWORD *)this + 5) = a2;
}


// address=[0x14d98c0]
// Decompiled from int __thiscall CAnimalEffect::AddBird(CAnimalEffect *this, int a2, int a3)
int  CAnimalEffect::AddBird(int,int) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-Ch]

  v3 = CLogic::Effects((DWORD *)g_pLogic);
  v5 = (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v3 + 40))(v3, 14, a2, a3);
  if ( !v5 )
    return v5;
  if ( ++*((_DWORD *)this + 6) >= *((_DWORD *)this + 5) )
    ++*((_DWORD *)this + 7);
  return v5;
}


// address=[0x14d9930]
// Decompiled from void __thiscall CAnimalEffect::SetCurrentAmoutSeagulls(CMFCToolBarButton *this, unsigned int a2)
void  CAnimalEffect::SetCurrentAmoutSeagulls(int) {
  
  *((_DWORD *)this + 9) = a2;
}


// address=[0x14d9950]
// Decompiled from void __thiscall CAnimalEffect::SetMaxAmountSeagulls(CPaneContainer *this, int a2)
void  CAnimalEffect::SetMaxAmountSeagulls(int) {
  
  *((_DWORD *)this + 8) = a2;
}


// address=[0x14d9970]
// Decompiled from int __thiscall CAnimalEffect::AddSeagull(CAnimalEffect *this, int a2, int a3)
int  CAnimalEffect::AddSeagull(int,int) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-Ch]

  v3 = CLogic::Effects((DWORD *)g_pLogic);
  v5 = (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v3 + 40))(v3, 15, a2, a3);
  if ( !v5 )
    return v5;
  if ( ++*((_DWORD *)this + 9) >= *((_DWORD *)this + 8) )
    ++*((_DWORD *)this + 10);
  return v5;
}


// address=[0x14d99e0]
// Decompiled from _DWORD *__thiscall CAnimalEffect::SetCurrentAmoutDucks(_DWORD *this, int a2)
void  CAnimalEffect::SetCurrentAmoutDucks(int) {
  
  _DWORD *result; // eax

  result = this;
  this[12] = a2;
  return result;
}


// address=[0x14d9a00]
// Decompiled from void __thiscall CAnimalEffect::SetMaxAmountDucks(CMFCCaptionButton *this, int a2)
void  CAnimalEffect::SetMaxAmountDucks(int) {
  
  *((_DWORD *)this + 11) = a2;
}


// address=[0x14d9a20]
// Decompiled from int __thiscall CAnimalEffect::AddDuck(CAnimalEffect *this, int a2, int a3)
int  CAnimalEffect::AddDuck(int,int) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-Ch]

  v3 = CLogic::Effects((DWORD *)g_pLogic);
  v5 = (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v3 + 40))(v3, 17, a2, a3);
  if ( !v5 )
    return v5;
  if ( ++*((_DWORD *)this + 12) >= *((_DWORD *)this + 11) )
    ++*((_DWORD *)this + 13);
  return v5;
}


// address=[0x14d9a90]
// Decompiled from char __thiscall CAnimalEffect::UpdateButterfly(  CAnimalEffect *this,  unsigned int a2,  int a3,  int a4,  int a5,  __int16 a6)
bool  CAnimalEffect::UpdateButterfly(int,int,int,int,int) {
  
  IEffects *v6; // eax
  IEffects *v8; // eax
  void *v9; // eax
  IEffects *v10; // eax
  int v11; // [esp-18h] [ebp-64h]
  Squares *v12; // [esp-Ch] [ebp-58h]
  Squares *v13; // [esp-8h] [ebp-54h]
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
  int v24; // [esp+24h] [ebp-28h]
  int v25; // [esp+28h] [ebp-24h]
  int i; // [esp+2Ch] [ebp-20h]
  int v27; // [esp+30h] [ebp-1Ch]
  int j; // [esp+34h] [ebp-18h]
  CAnimalEffect *v29; // [esp+38h] [ebp-14h]
  Squares *v30; // [esp+3Ch] [ebp-10h]
  Squares *v31; // [esp+40h] [ebp-Ch]
  unsigned int v32; // [esp+44h] [ebp-8h]
  char v33; // [esp+49h] [ebp-3h]
  char v34; // [esp+4Ah] [ebp-2h]
  bool v35; // [esp+4Bh] [ebp-1h]

  v29 = this;
  v35 = 0;
  if ( *((_DWORD *)this + 4) )
  {
    ScreenOffsetsByMapIndices = IGfxEngine::GetScreenOffsetsByMapIndices(a3, a4, &v15, &v16);
    if ( ScreenOffsetsByMapIndices != 3 )
    {
      v6 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
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
      v8 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
      IEffects::DeleteMovingEffect(v8, a2);
      v25 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v25 + 16))(
        v25,
        64,
        69,
        a3,
        a4,
        0,
        0,
        0);
      --*((_DWORD *)v29 + 3);
      return 0;
    }
  }
  else
  {
    v27 = 0;
  }
  v32 = CRandom16::Rand(*(CRandom16 **)v29) % 0xC;
  v30 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v32 + 7));
  v31 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v32 + 7));
  v20 = Squares::XYToVW(v30);
  v19 = Squares::XYToVW(v31);
  v35 = CAnimalMgr::CheckButterflyUnderground((CAnimalMgr *)&g_cAnimalMgr, v30, v31);
  for ( i = 0; !v35 && i < 12; ++i )
  {
    if ( (int)++v32 > 12 )
      v32 = 0;
    v30 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v32 + 7));
    v31 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v32 + 7));
    v20 = Squares::XYToVW(v30);
    v19 = Squares::XYToVW(v31);
    v35 = CAnimalMgr::CheckButterflyUnderground((CAnimalMgr *)&g_cAnimalMgr, v30, v31);
  }
  if ( !v35 )
  {
    v32 = a5 + 6;
    if ( a5 + 6 > 12 )
      v32 -= 12;
    v30 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v32 + 7));
    v31 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v32 + 7));
  }
  if ( !CAnimalMgr::CheckButterflyUnderground((CAnimalMgr *)&g_cAnimalMgr, v30, v31) )
  {
    v17 = CSpiralOffsets::First(30);
    v18 = 19;
    v34 = 0;
    for ( j = 19; j < v17; ++j )
    {
      v30 = (Squares *)(a3 + CSpiralOffsets::DeltaX(j));
      v31 = (Squares *)(a4 + CSpiralOffsets::DeltaY(j));
      if ( CAnimalMgr::CheckButterflyUndergroundFast((CAnimalMgr *)&g_cAnimalMgr, v30, v31) )
      {
        v34 = 1;
        break;
      }
    }
    if ( !v34 && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalEffect.cpp", 522, "bFound") == 1 )
      __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld((int)v30, (int)v31)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalEffect.cpp", 526, "g_cWorld.InWorld( iNewX, iNewY )") == 1 )
  {
    __debugbreak();
  }
  v24 = CLogic::Effects((DWORD *)g_pLogic);
  v23 = (*(int (__thiscall **)(int, unsigned int, Squares *, Squares *, _DWORD))(*(_DWORD *)v24 + 60))(
          v24,
          a2,
          v30,
          v31,
          0);
  if ( !v23 )
    return 1;
  v14 = ((unsigned __int8)v27 << 8) + (unsigned __int8)v32;
  v13 = v31;
  v12 = v30;
  v11 = v23;
  v9 = (void *)CLogic::FutureEvents(g_pLogic);
  v33 = IFutureEvents::AddFutureEvent16(v9, 7, v11, 0, a2, (unsigned int)v12, (unsigned int)v13, v14);
  if ( v33 )
    return v33;
  v10 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
  IEffects::DeleteMovingEffect(v10, a2);
  return v33;
}


// address=[0x14d9ea0]
// Decompiled from char __thiscall CAnimalEffect::UpdateBird(CAnimalEffect *this, unsigned int a2, int a3, int a4, int a5)
bool  CAnimalEffect::UpdateBird(int,int,int,int) {
  
  IEffects *v5; // eax
  IEffects *v7; // eax
  void *v8; // eax
  int v9; // [esp-18h] [ebp-68h]
  Squares *v10; // [esp-Ch] [ebp-5Ch]
  Squares *v11; // [esp-8h] [ebp-58h]
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
  int v22; // [esp+24h] [ebp-2Ch]
  signed int v23; // [esp+28h] [ebp-28h]
  int v24; // [esp+2Ch] [ebp-24h]
  int i; // [esp+30h] [ebp-20h]
  signed int v26; // [esp+34h] [ebp-1Ch]
  int v27; // [esp+38h] [ebp-18h]
  Squares *v28; // [esp+3Ch] [ebp-14h]
  Squares *v29; // [esp+40h] [ebp-10h]
  CAnimalEffect *v30; // [esp+44h] [ebp-Ch]
  int v31; // [esp+48h] [ebp-8h]
  bool v33; // [esp+4Fh] [ebp-1h]

  v30 = this;
  v33 = 0;
  if ( *((_DWORD *)this + 7) )
  {
    ScreenOffsetsByMapIndices = IGfxEngine::GetScreenOffsetsByMapIndices(a3, a4, &v13, &v14);
    if ( ScreenOffsetsByMapIndices != 3 )
    {
LABEL_3:
      v5 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
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
      v7 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
      IEffects::DeleteMovingEffect(v7, a2);
      v24 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v24 + 16))(
        v24,
        64,
        69,
        a3,
        a4,
        0,
        0,
        0);
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
        v31 = 11;
    }
    else if ( ++v31 > 12 )
    {
      v31 = 0;
    }
  }
  v28 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v31 + 7));
  v29 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v31 + 7));
  v16 = Squares::XYToVW(v28);
  v15 = Squares::XYToVW(v29);
  v33 = CAnimalMgr::CheckBirdUnderground((CAnimalMgr *)&g_cAnimalMgr, v28, v29);
  v26 = CRandom16::Rand(*(CRandom16 **)v30);
  for ( i = 0; !v33 && i < 12; ++i )
  {
    if ( v26 >= v23 )
    {
      if ( --v31 < 0 )
        v31 = 11;
    }
    else if ( ++v31 > 12 )
    {
      v31 = 0;
    }
    v28 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v31 + 7));
    v29 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v31 + 7));
    v16 = Squares::XYToVW(v28);
    v15 = Squares::XYToVW(v29);
    v33 = CAnimalMgr::CheckBirdUnderground((CAnimalMgr *)&g_cAnimalMgr, v28, v29);
  }
  if ( !v33 )
  {
    v31 = a5 + 6;
    if ( a5 + 6 > 12 )
      v31 -= 12;
    v28 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v31 + 7));
    v29 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v31 + 7));
  }
  if ( !(unsigned __int8)CWorldManager::InWorld((int)v28, (int)v29)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalEffect.cpp", 685, "g_cWorld.InWorld( iNewX, iNewY )") == 1 )
  {
    __debugbreak();
  }
  v22 = CLogic::Effects((DWORD *)g_pLogic);
  v21 = (*(int (__thiscall **)(int, unsigned int, Squares *, Squares *, _DWORD))(*(_DWORD *)v22 + 60))(
          v22,
          a2,
          v28,
          v29,
          0);
  if ( !v21 )
    return 1;
  v12 = ((unsigned __int8)v27 << 8) + (unsigned __int8)v31;
  v11 = v29;
  v10 = v28;
  v9 = v21;
  v8 = (void *)CLogic::FutureEvents(g_pLogic);
  if ( !(unsigned __int8)IFutureEvents::AddFutureEvent16(v8, 7, v9, 0, a2, (unsigned int)v10, (unsigned int)v11, v12) )
    goto LABEL_3;
  return 1;
}


// address=[0x14da2a0]
// Decompiled from char __thiscall CAnimalEffect::UpdateSeagull(CAnimalEffect *this, unsigned int a2, int a3, int a4, int a5)
bool  CAnimalEffect::UpdateSeagull(int,int,int,int) {
  
  IEffects *v5; // eax
  IEffects *v7; // eax
  int v8; // ecx
  IEffects *v9; // eax
  void *v10; // eax
  IEffects *v11; // eax
  int v12; // [esp-18h] [ebp-80h]
  Squares *v13; // [esp-Ch] [ebp-74h]
  Squares *v14; // [esp-8h] [ebp-70h]
  unsigned int v15; // [esp-4h] [ebp-6Ch]
  _BYTE v16[4]; // [esp+0h] [ebp-68h] BYREF
  _BYTE v17[4]; // [esp+4h] [ebp-64h] BYREF
  _BYTE v18[4]; // [esp+8h] [ebp-60h] BYREF
  int v19; // [esp+Ch] [ebp-5Ch]
  int v20; // [esp+10h] [ebp-58h] BYREF
  int v21; // [esp+14h] [ebp-54h] BYREF
  int ScreenOffsetsByMapIndices; // [esp+18h] [ebp-50h]
  int v23; // [esp+1Ch] [ebp-4Ch]
  int v24; // [esp+20h] [ebp-48h]
  int v25; // [esp+24h] [ebp-44h]
  signed int v26; // [esp+28h] [ebp-40h]
  signed int v27; // [esp+2Ch] [ebp-3Ch]
  int v28; // [esp+30h] [ebp-38h]
  BOOL v29; // [esp+34h] [ebp-34h]
  signed int v30; // [esp+38h] [ebp-30h]
  BOOL v31; // [esp+3Ch] [ebp-2Ch]
  int i; // [esp+40h] [ebp-28h]
  int v33; // [esp+44h] [ebp-24h]
  int v34; // [esp+48h] [ebp-20h]
  int v35; // [esp+4Ch] [ebp-1Ch] BYREF
  signed int v36; // [esp+50h] [ebp-18h]
  Squares *v37; // [esp+54h] [ebp-14h]
  Squares *v38; // [esp+58h] [ebp-10h]
  CAnimalEffect *v39; // [esp+5Ch] [ebp-Ch]
  int v40; // [esp+60h] [ebp-8h]
  bool v42; // [esp+67h] [ebp-1h]

  v39 = this;
  v42 = 0;
  if ( !(unsigned __int8)CWorldManager::InWorld(a3, a4)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalEffect.cpp", 728, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)CWorldManager::InWorld(a3, a4) )
  {
    if ( !*((_DWORD *)v39 + 10)
      || (ScreenOffsetsByMapIndices = IGfxEngine::GetScreenOffsetsByMapIndices(a3, a4, &v20, &v21),
          ScreenOffsetsByMapIndices == 3) )
    {
      v26 = CRandom16::PercentValue(0x19u);
      v30 = CRandom16::PercentValue(0x32u);
      v40 = a5;
      v27 = CRandom16::Rand(*(CRandom16 **)v39);
      if ( v27 < v26 )
      {
        v36 = CRandom16::Rand(*(CRandom16 **)v39);
        if ( v36 >= v30 )
        {
          if ( --v40 < 0 )
            v40 = 11;
        }
        else if ( ++v40 > 12 )
        {
          v40 = 0;
        }
      }
      v37 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v40 + 7));
      v38 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v40 + 7));
      v33 = Squares::XYToVW(v37);
      v34 = Squares::XYToVW(v38);
      v31 = CAnimalMgr::IsSeagullLand((CAnimalMgr *)&g_cAnimalMgr, v33, v34)
         && CAnimalMgr::CheckSeagullUndergroundAddPosition((CAnimalMgr *)&g_cAnimalMgr, v37, v38);
      v42 = v31;
      v36 = CRandom16::Rand(*(CRandom16 **)v39);
      for ( i = 0; !v42 && i < 12; ++i )
      {
        if ( v36 >= v30 )
        {
          if ( --v40 < 0 )
            v40 = 11;
        }
        else if ( ++v40 > 12 )
        {
          v40 = 0;
        }
        v37 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v40 + 7));
        v38 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v40 + 7));
        v33 = Squares::XYToVW(v37);
        v34 = Squares::XYToVW(v38);
        v29 = CAnimalMgr::IsSeagullLand((CAnimalMgr *)&g_cAnimalMgr, v33, v34)
           && CAnimalMgr::CheckSeagullUndergroundAddPosition((CAnimalMgr *)&g_cAnimalMgr, v37, v38);
        LOBYTE(v8) = v29;
        v42 = v29;
      }
      if ( !v42 )
      {
        v40 = a5 + 6;
        if ( a5 + 6 > 12 )
          v40 -= 12;
        v37 = (Squares *)(a3 + CSpiralOffsets::DeltaX(v40 + 7));
        v38 = (Squares *)(a4 + CSpiralOffsets::DeltaY(v40 + 7));
      }
      v19 = CWorldManager::Width(v8);
      if ( (unsigned __int8)CWorldManager::InWorld((int)v37, (int)v38) )
      {
        v28 = CLogic::Effects((DWORD *)g_pLogic);
        (*(void (__thiscall **)(int, unsigned int, int *, _BYTE *, _BYTE *, _BYTE *))(*(_DWORD *)v28 + 52))(
          v28,
          a2,
          &v35,
          v16,
          v17,
          v18);
        v36 = CRandom16::Rand(*(CRandom16 **)v39);
        if ( v27 < v26 )
        {
          if ( v35 == 15 )
            v35 = 16;
          else
            v35 = 15;
          v25 = CLogic::Effects((DWORD *)g_pLogic);
          (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v25 + 44))(v25, a2, v35);
        }
        v24 = CLogic::Effects((DWORD *)g_pLogic);
        v23 = (*(int (__thiscall **)(int, unsigned int, Squares *, Squares *, _DWORD))(*(_DWORD *)v24 + 60))(
                v24,
                a2,
                v37,
                v38,
                0);
        if ( !v23 )
          return 1;
        v15 = v40;
        v14 = v38;
        v13 = v37;
        v12 = v23;
        v10 = (void *)CLogic::FutureEvents(g_pLogic);
        if ( (unsigned __int8)IFutureEvents::AddFutureEvent16(
                                v10,
                                7,
                                v12,
                                0,
                                a2,
                                (unsigned int)v13,
                                (unsigned int)v14,
                                v15) )
        {
          return 1;
        }
        else
        {
          v11 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
          IEffects::DeleteMovingEffect(v11, a2);
          --*((_DWORD *)v39 + 10);
          --*((_DWORD *)v39 + 9);
          return 0;
        }
      }
      else
      {
        v9 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
        IEffects::DeleteMovingEffect(v9, a2);
        if ( *((int *)v39 + 10) > 0 )
          --*((_DWORD *)v39 + 10);
        if ( *((int *)v39 + 9) > 0 )
          --*((_DWORD *)v39 + 9);
        return 0;
      }
    }
    else
    {
      v7 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
      IEffects::DeleteMovingEffect(v7, a2);
      --*((_DWORD *)v39 + 10);
      --*((_DWORD *)v39 + 9);
      return 0;
    }
  }
  else
  {
    v5 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
    IEffects::DeleteMovingEffect(v5, a2);
    if ( *((int *)v39 + 10) > 0 )
      --*((_DWORD *)v39 + 10);
    if ( *((int *)v39 + 9) > 0 )
      --*((_DWORD *)v39 + 9);
    return 0;
  }
}


// address=[0x14da790]
// Decompiled from char __thiscall CAnimalEffect::UpdateDuck(CAnimalEffect *this, int a2, int a3, int a4, int a5)
bool  CAnimalEffect::UpdateDuck(int,int,int,int) {
  
  return 1;
}


