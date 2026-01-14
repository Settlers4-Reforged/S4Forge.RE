#include "all_headers.h"

// Definitions for class CEffect

// address=[0x144a5e0]
// Decompiled from int __thiscall CEffect::InitEffect(int this, int a2, char a3, int a4, int a5, int a6, int a7, char a8)
void  CEffect::InitEffect(int,enum SIV_SOUNDS,int,int,unsigned int,int,bool) {
  
  unsigned int EffectNumberOfFrames; // [esp+4h] [ebp-8h]

  *(_DWORD *)(this + 16) = a4;
  *(_DWORD *)(this + 20) = a5;
  *(_BYTE *)(this + 1) = a2;
  *(_BYTE *)(this + 2) = a3;
  EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(a2);
  *(_BYTE *)(this + 4) = 1;
  *(_BYTE *)(this + 6) = EffectNumberOfFrames;
  if ( !*(_BYTE *)(this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 689, "m_uFramesMax != 0") == 1 )
    __debugbreak();
  if ( a7 <= 0 )
    a7 = EffectNumberOfFrames;
  *(_BYTE *)(this + 5) = 0;
  *(_BYTE *)(this + 7) = 0;
  *(_DWORD *)(this + 8) = a6 + CStateGame::GetTickCounter(g_pGame);
  *(_DWORD *)(this + 12) = a7;
  if ( *(int *)(this + 12) <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 704, "m_iDuration > 0") == 1 )
    __debugbreak();
  CEffect::GetWorldScreenCoordinates(a4, a5, (float *)(this + 24), (float *)(this + 28));
  if ( a8 )
    return CEffect::SetVisualizeFunc(this, 9);
  else
    return CEffect::SetVisualizeFunc(this, 2);
}


// address=[0x144a700]
// Decompiled from int __thiscall CEffect::InitAngel(int this, int a2, char a3, int a4, int a5, int a6, int a7)
void  CEffect::InitAngel(enum T_EFFECT_ANGEL,enum SIV_SOUNDS,int,int,int,unsigned int) {
  
  char v7; // al
  char v9; // [esp+Ch] [ebp-10h]
  unsigned int v10; // [esp+10h] [ebp-Ch]
  unsigned int SettlerJobFrameCount; // [esp+14h] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 725, "_tAngel != EFFECT_ANGEL_NONE") == 1 )
    __debugbreak();
  *(_DWORD *)(this + 16) = a4;
  *(_DWORD *)(this + 20) = a5;
  *(_BYTE *)(this + 1) = a2;
  *(_BYTE *)(this + 2) = a3;
  v10 = CPlayerManager::Race(a6);
  v7 = CPlayerManager::Color(a6);
  *(_BYTE *)(this + 4) = v10;
  *(_BYTE *)(this + 5) = v7;
  SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, v10, dword_36AC278[a2], 2u);
  if ( SettlerJobFrameCount )
    v9 = SettlerJobFrameCount;
  else
    v9 = 1;
  *(_BYTE *)(this + 6) = v9;
  *(_BYTE *)(this + 7) = 0;
  if ( !*(_BYTE *)(this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 744, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  *(_DWORD *)(this + 8) = a7 + CStateGame::GetTickCounter(g_pGame);
  *(_DWORD *)(this + 12) = SettlerJobFrameCount;
  if ( *(int *)(this + 12) <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 751, "m_iDuration > 0") == 1 )
    __debugbreak();
  CEffect::GetWorldScreenCoordinates(a4, a5, (float *)(this + 24), (float *)(this + 28));
  return CEffect::SetVisualizeFunc(this, 3);
}


// address=[0x144a880]
// Decompiled from int __thiscall CEffect::InitMissile(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7)
void  CEffect::InitMissile(enum T_EFFECT_MISSILE,int,int,unsigned int,int,int) {
  
  char EffectNumberOfFrames; // al
  char v8; // al
  double v10; // [esp+4h] [ebp-60h]
  float v11; // [esp+8h] [ebp-5Ch]
  int TickCounter; // [esp+10h] [ebp-54h]
  float v13; // [esp+14h] [ebp-50h] BYREF
  float v14; // [esp+18h] [ebp-4Ch] BYREF
  int v15; // [esp+1Ch] [ebp-48h]
  int v16; // [esp+20h] [ebp-44h]
  float v17; // [esp+24h] [ebp-40h]
  int (__stdcall *v18)(float, float); // [esp+28h] [ebp-3Ch]
  int v19; // [esp+2Ch] [ebp-38h]
  int v20; // [esp+30h] [ebp-34h]
  float v21; // [esp+34h] [ebp-30h]
  float v22; // [esp+38h] [ebp-2Ch]
  float v23; // [esp+3Ch] [ebp-28h]
  int v24; // [esp+40h] [ebp-24h]
  float v25; // [esp+44h] [ebp-20h]
  float v26; // [esp+48h] [ebp-1Ch] BYREF
  float v27; // [esp+4Ch] [ebp-18h] BYREF
  int (__stdcall **v28)(float, float); // [esp+50h] [ebp-14h]
  float v29; // [esp+54h] [ebp-10h]
  float v30; // [esp+58h] [ebp-Ch]
  _DWORD *v31; // [esp+5Ch] [ebp-8h]
  char v32; // [esp+63h] [ebp-1h]

  v31 = this;
  v28 = (int (__stdcall **)(float, float))((char *)&unk_36AC288 + 28 * a2);
  v18 = *v28;
  v19 = Y16X16::UnpackXFast(a3);
  v20 = Y16X16::UnpackYFast(a3);
  v31[4] = v19;
  v31[5] = v20;
  *((_BYTE *)v31 + 1) = (_BYTE)v18;
  *((_BYTE *)v31 + 2) = 0;
  v15 = Y16X16::UnpackXFast(a4);
  v16 = Y16X16::UnpackYFast(a4);
  CEffect::GetWorldScreenCoordinates(v19, v20, &v27, &v26);
  v27 = (float)a6 + v27;
  v26 = (float)a7 + v26;
  CEffect::GetWorldScreenCoordinates(v15, v16, &v14, &v13);
  v30 = v14 - v27;
  v29 = v13 - v26;
  *(float *)&v10 = (float)((float)(v14 - v27) * (float)(v14 - v27)) + (float)((float)(v13 - v26) * (float)(v13 - v26));
  v22 = sqrt(v10);
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(v18);
  *((_BYTE *)v31 + 6) = EffectNumberOfFrames;
  v8 = v28[5](COERCE_FLOAT(LODWORD(v30)), COERCE_FLOAT(LODWORD(v29)));
  *((_BYTE *)v31 + 5) = v8;
  v31[2] = a5 + TickCounter;
  if ( !*((_BYTE *)v31 + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 805, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  v32 = 1;
  if ( v22 > 0.0 )
  {
    v21 = v22 - (float)(2.0 * *((float *)v28 + 4));
    if ( v21 > 0.0 )
    {
      v25 = *((float *)v28 + 4) * (float)(1.0 / v22);
      v27 = (float)(v25 * v30) + v27;
      v26 = (float)(v25 * v29) + v26;
      v30 = v30 - (float)((float)(2.0 * v25) * v30);
      v29 = v29 - (float)((float)(2.0 * v25) * v29);
      v24 = (int)(float)(*((float *)v28 + 3) * v21);
      if ( v24 < 1 )
        v24 = 1;
      v31[3] = v24 + 1;
      v11 = *((float *)v28 + 2) * v21;
      v23 = 1.0 / (float)v24;
      v17 = (float)(4.0 * v11) * v23;
      *((float *)v31 + 8) = v30 * v23;
      *((float *)v31 + 9) = (float)(v29 * v23) - v17;
      *((float *)v31 + 12) = v17 * v23;
      v32 = 0;
    }
  }
  if ( v32 )
  {
    v31[3] = 1;
    v31[8] = 0;
    v31[9] = 0;
    v31[12] = 0;
  }
  *((float *)v31 + 6) = v27;
  *((float *)v31 + 7) = v26 + *((float *)v28 + 1);
  return CEffect::SetVisualizeFunc(v31, v28[6]);
}


// address=[0x144ac00]
// Decompiled from int __thiscall CEffect::InitSporeCloud(CEffect *this, int a2, int a3, unsigned int a4)
void  CEffect::InitSporeCloud(int,int,unsigned int) {
  
  int TickCounter; // eax
  double v6; // [esp+0h] [ebp-3Ch]
  int v7; // [esp+4h] [ebp-38h]
  int v8; // [esp+8h] [ebp-34h]
  float v9; // [esp+Ch] [ebp-30h]
  int v10; // [esp+10h] [ebp-2Ch]
  int v11; // [esp+14h] [ebp-28h]
  float v12; // [esp+18h] [ebp-24h]
  float v13; // [esp+1Ch] [ebp-20h]
  float v14; // [esp+20h] [ebp-1Ch] BYREF
  float v15; // [esp+24h] [ebp-18h] BYREF
  int v16; // [esp+28h] [ebp-14h]
  int v17; // [esp+2Ch] [ebp-10h]
  float v18; // [esp+30h] [ebp-Ch]
  int v19; // [esp+34h] [ebp-8h]
  CEffect *v20; // [esp+38h] [ebp-4h]

  v20 = this;
  *((_BYTE *)this + 1) = 21;
  *((_BYTE *)v20 + 2) = 0;
  v16 = Y16X16::UnpackXFast(a2);
  v17 = Y16X16::UnpackYFast(a2);
  *((_DWORD *)v20 + 4) = v16;
  *((_DWORD *)v20 + 5) = v17;
  v10 = Y16X16::UnpackXFast(a3);
  v11 = Y16X16::UnpackYFast(a3);
  v8 = v10 - v16;
  HIDWORD(v6) = v11 - v17;
  CEffect::GetWorldScreenCoordinates(v16, v17, (float *)v20 + 6, (float *)v20 + 7);
  *((float *)v20 + 6) = *((float *)v20 + 6) + 0.0;
  *((float *)v20 + 7) = *((float *)v20 + 7) + -18.0;
  CEffect::GetWorldScreenCoordinates(v10, v11, &v15, &v14);
  v15 = v15 + -48.0;
  v14 = v14 + -90.0;
  v13 = v15 - *((float *)v20 + 6);
  v12 = v14 - *((float *)v20 + 7);
  *(float *)&v6 = (float)(v13 * v13) + (float)(v12 * v12);
  v9 = sqrt(v6);
  v19 = (int)(float)(v9 * 0.2);
  if ( v19 >= 255 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 901, "iTimeIdxMax < 255") == 1 )
    __debugbreak();
  if ( v19 <= 0 )
  {
    v19 = 1;
    *((_DWORD *)v20 + 8) = 0;
    *((_DWORD *)v20 + 9) = 0;
    *((_DWORD *)v20 + 10) = 0;
    *((_DWORD *)v20 + 11) = 0;
  }
  else
  {
    v18 = 1.0 / (float)v19;
    *((float *)v20 + 8) = v13 * v18;
    *((float *)v20 + 9) = v12 * v18;
    *((float *)v20 + 10) = (float)v8 * v18;
    *((float *)v20 + 11) = (float)v7 * v18;
  }
  *((_BYTE *)v20 + 5) = 0;
  *((_BYTE *)v20 + 7) = 0;
  *((_DWORD *)v20 + 3) = v19;
  *((_BYTE *)v20 + 4) = 1;
  *((_BYTE *)v20 + 6) = CEffect::GetEffectNumberOfFrames(21);
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  *((_DWORD *)v20 + 2) = a4 + TickCounter;
  if ( *((int *)v20 + 3) <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 932, "m_iDuration > 0") == 1 )
    __debugbreak();
  if ( !*((_BYTE *)v20 + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 933, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  return CEffect::SetVisualizeFunc(v20, 6);
}


// address=[0x144aed0]
// Decompiled from int __thiscall CEffect::InitStagnantAnimal(int this, unsigned int a2, char a3, int a4, int a5, char a6, int a7)
void  CEffect::InitStagnantAnimal(enum SIV_ANIMALS,enum SIV_SOUNDS,int,int,int,unsigned int) {
  
  unsigned int AnimalFrameCount; // [esp+4h] [ebp-8h]

  *(_DWORD *)(this + 16) = a4;
  *(_DWORD *)(this + 20) = a5;
  *(_BYTE *)(this + 1) = a2;
  *(_BYTE *)(this + 2) = a3;
  AnimalFrameCount = CGfxManager::GetAnimalFrameCount((CGfxManager *)g_pGfxManager, a2);
  *(_BYTE *)(this + 4) = 6;
  *(_BYTE *)(this + 6) = AnimalFrameCount;
  if ( !*(_BYTE *)(this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 956, "m_uFramesMax != 0") == 1 )
    __debugbreak();
  *(_BYTE *)(this + 5) = a6;
  *(_BYTE *)(this + 7) = 0;
  *(_DWORD *)(this + 8) = a7 + CStateGame::GetTickCounter(g_pGame);
  *(_DWORD *)(this + 12) = AnimalFrameCount;
  if ( *(int *)(this + 12) <= 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 966, "m_iDuration > 0") == 1 )
    __debugbreak();
  CEffect::GetWorldScreenCoordinates(a4, a5, (float *)(this + 24), (float *)(this + 28));
  return CEffect::SetVisualizeFunc(this, 7);
}


// address=[0x144afe0]
// Decompiled from int __thiscall CEffect::InitMovingEffect(CEffect *this, int a2, int a3, int a4)
void  CEffect::InitMovingEffect(int,int,int) {
  
  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 5) = a4;
  *((_BYTE *)this + 1) = a2;
  *((_BYTE *)this + 2) = 0;
  *((_BYTE *)this + 4) = 16;
  *((_BYTE *)this + 6) = CEffect::GetEffectNumberOfFrames(a2);
  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 989, "m_uFramesMax != 0") == 1 )
    __debugbreak();
  *((_BYTE *)this + 5) = 0;
  *((_BYTE *)this + 7) = 0;
  *((_BYTE *)this + 3) = 0;
  *((_DWORD *)this + 6) = *((_DWORD *)this + 4);
  *((_DWORD *)this + 7) = *((_DWORD *)this + 5);
  *((_DWORD *)this + 2) = CStateGame::GetTickCounter(g_pGame);
  *((_DWORD *)this + 3) = 0x7FFFFFFF;
  CEffect::GetWorldScreenCoordinates(a3, a4, (int *)this + 8, (int *)this + 9);
  *((_DWORD *)this + 10) = *((_DWORD *)this + 8);
  *((_DWORD *)this + 11) = *((_DWORD *)this + 9);
  *((_DWORD *)this + 12) = 100;
  return CEffect::SetVisualizeFunc(this, 8);
}


// address=[0x144b0f0]
// Decompiled from int __thiscall CEffect::SetNewDestinationForMovingEffect(CEffect *this, int a2, int a3, char a4)
unsigned int  CEffect::SetNewDestinationForMovingEffect(int,int,int) {
  
  int v5; // [esp+8h] [ebp-30h]
  int v6; // [esp+Ch] [ebp-2Ch]
  int v7; // [esp+14h] [ebp-24h]
  unsigned int TickCounter; // [esp+18h] [ebp-20h]
  int v9; // [esp+1Ch] [ebp-1Ch]
  int v10; // [esp+20h] [ebp-18h]
  int v11; // [esp+24h] [ebp-14h]
  int v12; // [esp+28h] [ebp-10h]
  int v13; // [esp+2Ch] [ebp-Ch]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( TickCounter < *((_DWORD *)this + 2) )
    v7 = 0;
  else
    v7 = TickCounter - *((_DWORD *)this + 2);
  v12 = *((unsigned __int8 *)this + 3);
  *((_BYTE *)this + 7) = (v7 + (unsigned int)*((unsigned __int8 *)this + 7)) % *((unsigned __int8 *)this + 6);
  if ( v7 < v12 )
  {
    if ( v7 > 0 )
    {
      *((_DWORD *)this + 4) += v7 * (*((_DWORD *)this + 6) - *((_DWORD *)this + 4)) / v12;
      *((_DWORD *)this + 5) += v7 * (*((_DWORD *)this + 7) - *((_DWORD *)this + 5)) / v12;
      *((_DWORD *)this + 8) += v7 * (*((_DWORD *)this + 10) - *((_DWORD *)this + 8)) / v12;
      *((_DWORD *)this + 9) += v7 * (*((_DWORD *)this + 11) - *((_DWORD *)this + 9)) / v12;
    }
  }
  else
  {
    *((_DWORD *)this + 4) = *((_DWORD *)this + 6);
    *((_DWORD *)this + 5) = *((_DWORD *)this + 7);
    *((_DWORD *)this + 8) = *((_DWORD *)this + 10);
    *((_DWORD *)this + 9) = *((_DWORD *)this + 11);
  }
  if ( (a4 & 1) != 0 )
  {
    *((_DWORD *)this + 6) = *((_DWORD *)this + 4);
    *((_DWORD *)this + 7) = *((_DWORD *)this + 5);
    *((_DWORD *)this + 10) = *((_DWORD *)this + 8);
    *((_DWORD *)this + 11) = *((_DWORD *)this + 9);
    *((_BYTE *)this + 3) = 1;
    v11 = *((unsigned __int8 *)this + 6);
  }
  else
  {
    *((_DWORD *)this + 6) = a2;
    *((_DWORD *)this + 7) = a3;
    v6 = a2 - *((_DWORD *)this + 4);
    v5 = a3 - *((_DWORD *)this + 5);
    CEffect::GetWorldScreenCoordinates(*((_DWORD *)this + 6), *((_DWORD *)this + 7), (int *)this + 10, (int *)this + 11);
    v9 = *((_DWORD *)this + 10) - *((_DWORD *)this + 8);
    v10 = *((_DWORD *)this + 11) - *((_DWORD *)this + 9);
    v13 = (*((_DWORD *)this + 12) * sub_144A570(v10 * v10 + v9 * v9, v5, v6)) >> 9;
    if ( v13 >= 255 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1072, "iNewTimeIdxMax < 255") == 1 )
      __debugbreak();
    if ( v13 > 0 )
    {
      if ( v13 > 255 )
        v13 = 255;
    }
    else
    {
      v13 = 1;
    }
    *((_BYTE *)this + 4) = 16;
    *((_BYTE *)this + 5) = ((_DWORD (__stdcall *)(_DWORD, _DWORD))sub_144A400)((float)v9, (float)v10);
    *((_BYTE *)this + 3) = v13;
    v11 = v13;
  }
  *((_DWORD *)this + 2) = TickCounter;
  *((_DWORD *)this + 3) = 0x7FFFFFFF;
  CEffect::SetVisualizeFunc(this, 8);
  if ( !v11 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1110, "uDelay > 0") == 1 )
    __debugbreak();
  return v11;
}


// address=[0x144b3e0]
// Decompiled from int __thiscall CEffect::UpdateAttachedEffect(CEffect *this, const struct CEffect *a2)
void  CEffect::UpdateAttachedEffect(class CEffect const &) {
  
  int result; // eax

  if ( *((unsigned __int8 *)this + 4) > 1u )
    *((_BYTE *)this + 5) = *((unsigned __int8 *)a2 + 5) % (__int16)*((unsigned __int8 *)this + 4);
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 4);
  result = *((_DWORD *)a2 + 5);
  *((_DWORD *)this + 5) = result;
  if ( *((int *)this + 5) >= 1024 )
    return result;
  result = *((_DWORD *)this + 5) + 1;
  *((_DWORD *)this + 5) = result;
  return result;
}


// address=[0x144b450]
// Decompiled from int __thiscall CEffect::InitAttachedEffect(CEffect *this, int a2, unsigned int a3, const struct CEffect *a4, char a5)
void  CEffect::InitAttachedEffect(int,unsigned int,class CEffect const &,int) {
  
  char v6; // [esp+0h] [ebp-Ch]
  unsigned int EffectNumberOfFrames; // [esp+4h] [ebp-8h]

  *((_BYTE *)this + 1) = a2;
  *((_BYTE *)this + 2) = 0;
  *((_BYTE *)this + 3) = 0;
  if ( (a5 & 1) != 0 )
    v6 = *((_BYTE *)a4 + 4);
  else
    v6 = 1;
  *((_BYTE *)this + 4) = v6;
  *((_BYTE *)this + 5) = 0;
  EffectNumberOfFrames = CEffect::GetEffectNumberOfFrames(a2);
  if ( !EffectNumberOfFrames )
    LOBYTE(EffectNumberOfFrames) = 1;
  *((_BYTE *)this + 6) = EffectNumberOfFrames;
  *((_BYTE *)this + 7) = 0;
  *((_DWORD *)this + 2) = *((_DWORD *)a4 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a4 + 3);
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_BYTE *)this + 24) = 0;
  *((_DWORD *)this + 12) = a3;
  CEffect::SetVisualizeFunc(this, 11);
  return CEffect::UpdateAttachedEffect(this, a4);
}


// address=[0x144b530]
// Decompiled from struct SGfxObjectInfo *__thiscall CEffect::VisualizeEffect(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeEffect(struct SGfxObjectInfo &,int) {
  
  struct SGfxObjectInfo *result; // eax

  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1122, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1123, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  CEffect::GetEffectGfxInfo(a2, *((unsigned __int8 *)this + 1), 0, a3 % (unsigned int)*((unsigned __int8 *)this + 6));
  *((_BYTE *)a2 + 712) = 0x80;
  *((_DWORD *)a2 + 174) = *((_DWORD *)this + 6);
  result = a2;
  *((_DWORD *)a2 + 175) = *((_DWORD *)this + 7);
  return result;
}


// address=[0x144b5f0]
// Decompiled from struct SGfxObjectInfo *__thiscall CEffect::VisualizeAngel(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeAngel(struct SGfxObjectInfo &,int) {
  
  struct SGfxObjectInfo *result; // eax
  char v4; // [esp+0h] [ebp-18h]

  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1272, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1273, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  v4 = *((_BYTE *)this + 5);
  CGfxManager::GetSettlerGfxInfo(
    (CGfxManager *)g_pGfxManager,
    a2,
    *((unsigned __int8 *)this + 4),
    dword_36AC278[*((unsigned __int8 *)this + 1)],
    a3 % (unsigned int)*((unsigned __int8 *)this + 6),
    2u);
  *((_BYTE *)a2 + 712) = 1;
  *((_BYTE *)a2 + 715) = v4;
  *((_DWORD *)a2 + 174) = *((_DWORD *)this + 6);
  result = a2;
  *((_DWORD *)a2 + 175) = *((_DWORD *)this + 7);
  return result;
}


// address=[0x144b6e0]
// Decompiled from CEffect *__thiscall CEffect::VisualizeArrow(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeArrow(struct SGfxObjectInfo &,int) {
  
  CEffect *result; // eax

  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1297, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  if ( *((unsigned __int8 *)this + 1) >= 0x56u
    && (*((unsigned __int8 *)this + 1) <= 0x64u || *((unsigned __int8 *)this + 1) >= 0x74u)
    && BBSupportDbgReport(
         2,
         "Logic\\Effects.cpp",
         1299,
         "(m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) )") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetEffectGfxInfo(
    a2,
    *((unsigned __int8 *)this + 1),
    *((unsigned __int8 *)this + 5),
    *((unsigned __int8 *)this + 7));
  *((_BYTE *)a2 + 712) = 64;
  *((float *)a2 + 174) = (float)(*((float *)this + 8) * (float)a3) + *((float *)this + 6);
  result = this;
  *((float *)a2 + 175) = (float)((float)(*((float *)this + 9) * (float)a3) + *((float *)this + 7))
                       + (float)((float)((float)a3 * (float)a3) * *((float *)this + 12));
  return result;
}


// address=[0x144b800]
// Decompiled from CEffect *__thiscall CEffect::VisualizeCannonball(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeCannonball(struct SGfxObjectInfo &,int) {
  
  CEffect *result; // eax

  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1322, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  if ( *((unsigned __int8 *)this + 1) >= 0x56u
    && (*((unsigned __int8 *)this + 1) <= 0x64u || *((unsigned __int8 *)this + 1) >= 0x74u)
    && BBSupportDbgReport(
         2,
         "Logic\\Effects.cpp",
         1325,
         "(m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) )") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1326, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  CEffect::GetEffectGfxInfo(
    a2,
    *((unsigned __int8 *)this + 1),
    *((unsigned __int8 *)this + 5),
    a3 % (unsigned int)*((unsigned __int8 *)this + 6));
  *((_BYTE *)a2 + 712) = 64;
  *((float *)a2 + 174) = (float)(*((float *)this + 8) * (float)a3) + *((float *)this + 6);
  result = this;
  *((float *)a2 + 175) = (float)((float)(*((float *)this + 9) * (float)a3) + *((float *)this + 7))
                       + (float)((float)((float)a3 * (float)a3) * *((float *)this + 12));
  return result;
}


// address=[0x144b950]
// Decompiled from CEffect *__thiscall CEffect::VisualizeSporeCloud(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeSporeCloud(struct SGfxObjectInfo &,int) {
  
  CEffect *result; // eax

  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1143, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1144, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  CEffect::GetEffectGfxInfo(
    a2,
    *((unsigned __int8 *)this + 1),
    *((unsigned __int8 *)this + 5),
    a3 % (unsigned int)*((unsigned __int8 *)this + 6));
  *((_BYTE *)a2 + 712) = 0x80;
  *((float *)a2 + 174) = (float)(*((float *)this + 8) * (float)a3) + *((float *)this + 6);
  result = this;
  *((float *)a2 + 175) = (float)(*((float *)this + 9) * (float)a3) + *((float *)this + 7);
  return result;
}


// address=[0x144ba40]
// Decompiled from int __thiscall sub_184BA40(int this, int a2, int a3)
void  CEffect::VisualizeStagnantAnimal(struct SGfxObjectInfo &,int) {
  
  int result; // eax

  if ( !*(_BYTE *)(this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1166, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1167, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  CGfxManager::GetAnimalGfxInfo(
    a2,
    *(unsigned __int8 *)(this + 1),
    *(unsigned __int8 *)(this + 5),
    a3 % (unsigned int)*(unsigned __int8 *)(this + 6));
  *(_BYTE *)(a2 + 712) = 0x80;
  *(_DWORD *)(a2 + 696) = *(_DWORD *)(this + 24);
  result = this;
  *(_DWORD *)(a2 + 700) = *(_DWORD *)(this + 28);
  return result;
}


// address=[0x144bb10]
// Decompiled from int __thiscall CEffect::VisualizeMovingEffect(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeMovingEffect(struct SGfxObjectInfo &,int) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-10h]
  int v5; // [esp+10h] [ebp-8h]

  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1187, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1188, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  CGfxManager::GetEffectGfxInfo(
    (CGfxManager *)g_pGfxManager,
    a2,
    *((unsigned __int8 *)this + 1),
    *((unsigned __int8 *)this + 5),
    (a3 + (unsigned int)*((unsigned __int8 *)this + 7)) % *((unsigned __int8 *)this + 6));
  *((_BYTE *)a2 + 712) = 0x80;
  v5 = *((unsigned __int8 *)this + 3);
  if ( a3 > v5 )
    v4 = *((unsigned __int8 *)this + 3);
  else
    v4 = a3;
  if ( *((_BYTE *)this + 3) && v4 > 0 )
  {
    *((float *)a2 + 174) = (float)(v4 * (*((_DWORD *)this + 10) - *((_DWORD *)this + 8)) / v5 + *((_DWORD *)this + 8));
    result = v4 * (*((_DWORD *)this + 11) - *((_DWORD *)this + 9)) / v5;
    *((float *)a2 + 175) = (float)(result + *((_DWORD *)this + 9));
  }
  else
  {
    *((float *)a2 + 174) = (float)*((int *)this + 8);
    result = (int)a2;
    *((float *)a2 + 175) = (float)*((int *)this + 9);
  }
  *((_BYTE *)a2 + 713) = -64;
  return result;
}


// address=[0x144bc80]
// Decompiled from struct SGfxObjectInfo *__thiscall CEffect::VisualizeTopEffect(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeTopEffect(struct SGfxObjectInfo &,int) {
  
  struct SGfxObjectInfo *result; // eax

  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1221, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1222, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  CEffect::GetEffectGfxInfo(a2, *((unsigned __int8 *)this + 1), 0, a3 % (unsigned int)*((unsigned __int8 *)this + 6));
  *((_BYTE *)a2 + 712) = 0x80;
  *((_DWORD *)a2 + 174) = *((_DWORD *)this + 6);
  *((_DWORD *)a2 + 175) = *((_DWORD *)this + 7);
  result = a2;
  *((_BYTE *)a2 + 713) = -64;
  return result;
}


// address=[0x144bd50]
// Decompiled from CEffect *__thiscall CEffect::VisualizeTopFireball(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeTopFireball(struct SGfxObjectInfo &,int) {
  
  CEffect *result; // eax

  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1244, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1245, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  if ( *((unsigned __int8 *)this + 1) >= 0x56u
    && (*((unsigned __int8 *)this + 1) <= 0x64u || *((unsigned __int8 *)this + 1) >= 0x74u)
    && BBSupportDbgReport(
         2,
         "Logic\\Effects.cpp",
         1247,
         "(m_uEffect < EFFECT_MAX) || ( (m_uEffect > EFFECT_2_NO_EFFECT) && (m_uEffect < EFFECT_2_MAX) )") == 1 )
  {
    __debugbreak();
  }
  CEffect::GetEffectGfxInfo(
    a2,
    *((unsigned __int8 *)this + 1),
    *((unsigned __int8 *)this + 5),
    a3 % (unsigned int)*((unsigned __int8 *)this + 6));
  *((_BYTE *)a2 + 712) = 64;
  *((float *)a2 + 174) = (float)(*((float *)this + 8) * (float)a3) + *((float *)this + 6);
  result = this;
  *((float *)a2 + 175) = (float)((float)(*((float *)this + 9) * (float)a3) + *((float *)this + 7))
                       + (float)((float)((float)a3 * (float)a3) * *((float *)this + 12));
  *((_BYTE *)a2 + 713) = -64;
  return result;
}


// address=[0x144beb0]
// Decompiled from CEffect *__thiscall CEffect::VisualizeAttachedEffect(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeAttachedEffect(struct SGfxObjectInfo &,int) {
  
  CEffect *result; // eax
  int v4; // [esp+0h] [ebp-10h]
  unsigned int v5; // [esp+4h] [ebp-Ch]
  unsigned int v6; // [esp+8h] [ebp-8h]

  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1349, "m_uFramesMax > 0") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 1350, "_iTimeIndex >= 0") == 1 )
    __debugbreak();
  v4 = *((unsigned __int8 *)this + 1);
  v5 = *((unsigned __int8 *)this + 5);
  v6 = a3 % (unsigned int)*((unsigned __int8 *)this + 6);
  *((_BYTE *)this + 24) = 1;
  CEffect::GetEffectGfxInfo(a2, v4, v5, v6);
  *((_BYTE *)a2 + 712) = 0x80;
  *((float *)a2 + 174) = *((float *)a2 + 174) + *((float *)this + 8);
  result = this;
  *((float *)a2 + 175) = *((float *)a2 + 175) + *((float *)this + 9);
  *((_BYTE *)a2 + 713) = -64;
  return result;
}


// address=[0x144f270]
// Decompiled from void __thiscall CEffect::VisualizeNOP(CEffect *this, struct SGfxObjectInfo *a2, int a3)
void  CEffect::VisualizeNOP(struct SGfxObjectInfo &,int) {
  
  ;
}


// address=[0x144f500]
// Decompiled from void __cdecl CEffect::GetEffectGfxInfo(struct SGfxObjectInfo *a1, unsigned int a2, unsigned int a3, unsigned int a4)
static void __cdecl CEffect::GetEffectGfxInfo(struct SGfxObjectInfo &,int,unsigned int,unsigned int) {
  
  CGfxManager::GetEffectGfxInfo((CGfxManager *)g_pGfxManager, a1, a2, a3, a4);
}


// address=[0x144f530]
// Decompiled from int __cdecl CEffect::GetEffectNumberOfFrames(unsigned int a1)
static unsigned int __cdecl CEffect::GetEffectNumberOfFrames(int) {
  
  unsigned int EffectFrameCount; // [esp+4h] [ebp-4h]

  EffectFrameCount = CGfxManager::GetEffectFrameCount((CGfxManager *)g_pGfxManager, a1);
  if ( EffectFrameCount >= 0x100 && BBSupportDbgReport(2, "Logic\\Effects.cpp", 661, "uNumberOfFrames < 256") == 1 )
    __debugbreak();
  return ((_BYTE)EffectFrameCount == 0) + (unsigned __int8)EffectFrameCount;
}


// address=[0x144f5c0]
// Decompiled from int __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, int *a3, int *a4)
static void __cdecl CEffect::GetWorldScreenCoordinates(int,int,int &,int &) {
  
  int result; // eax
  float v5; // [esp+0h] [ebp-8h] BYREF
  float v6; // [esp+4h] [ebp-4h] BYREF

  v6 = 0.0;
  v5 = 0.0;
  IGfxEngine::ConvertMapPositionToWorldScreenOffsets((IGfxEngine *)g_pGfxEngine, a1, a2, &v6, &v5);
  *a3 = (int)v6;
  result = (int)v5;
  *a4 = (int)v5;
  return result;
}


// address=[0x144f620]
// Decompiled from void __cdecl CEffect::GetWorldScreenCoordinates(int a1, int a2, float *a3, float *a4)
static void __cdecl CEffect::GetWorldScreenCoordinates(int,int,float &,float &) {
  
  IGfxEngine::ConvertMapPositionToWorldScreenOffsets((IGfxEngine *)g_pGfxEngine, a1, a2, a3, a4);
}


// address=[0x144f690]
// Decompiled from BOOL __thiscall CEffect::IsOutOfDate(CEffect *this, int a2)
int  CEffect::IsOutOfDate(int)const {
  
  return a2 >= *((_DWORD *)this + 3);
}


// address=[0x144f700]
// Decompiled from _DWORD *__thiscall CEffect::SetVisualizeFunc(_DWORD *this, int a2)
void  CEffect::SetVisualizeFunc(enum T_VISUALIZE_FUNC) {
  
  _DWORD *result; // eax

  if ( a2 > 11 )
  {
    if ( BBSupportDbgReport(1, "Logic\\Effects.cpp", 633, "CEffect::VisualizeFunc(): Invalid visualize function!") == 1 )
      __debugbreak();
    a2 = 1;
  }
  *(_BYTE *)this = a2;
  result = this;
  this[13] = off_3D894F0[a2];
  return result;
}


// address=[0x144f770]
// Decompiled from int __thiscall CEffect::SquareRow(CEffect *this)
int  CEffect::SquareRow(void)const {
  
  return *((_DWORD *)this + 5) & 0xF;
}


// address=[0x144f790]
// Decompiled from int __thiscall CEffect::TimeIndex(CEffect *this, unsigned int a2)
int  CEffect::TimeIndex(unsigned int)const {
  
  return a2 - *((_DWORD *)this + 2);
}


// address=[0x144f7b0]
// Decompiled from int __thiscall CEffect::Visualize(  int (__thiscall **this)(CEffect *, struct SGfxObjectInfo *, int),  struct SGfxObjectInfo *a2,  int a3)
void  CEffect::Visualize(struct SGfxObjectInfo &,int) {
  
  return this[13]((CEffect *)this, a2, a3);
}


// address=[0x144f7e0]
// Decompiled from int __thiscall CEffect::VisualizeFunc(unsigned __int8 *this)
enum T_VISUALIZE_FUNC  CEffect::VisualizeFunc(void)const {
  
  return *this;
}


