#include "CCachePageManager.h"

// Definitions for class CCachePageManager

// address=[0x2f5f420]
// Decompiled from void __thiscall CCachePageManager::SetCurrentZoomFactor(CCachePageManager *this, int a2)

void  CCachePageManager::SetCurrentZoomFactor(float) {
  
  CCachePageManager::sm_fZoomFactor = a2;
}


// address=[0x2f69960]
// Decompiled from char __thiscall CCachePageManager::IsSourceSurfaceLocked(CCachePageManager *this)

bool  CCachePageManager::IsSourceSurfaceLocked(void) {
  
  return *((_BYTE *)this + 2072);
}


// address=[0x2f69980]
// Decompiled from char __thiscall CCachePageManager::IsVideoSurfaceLocked(CCachePageManager *this)

bool  CCachePageManager::IsVideoSurfaceLocked(void) {
  
  return *((_BYTE *)this + 2073);
}


// address=[0x2f87760]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::CCachePageManager(
        CCachePageManager *this,
        struct IDirectDrawSurface7 *a2,
        struct IDirectDrawSurface7 *a3,
        struct IDirect3DDevice7 *a4)

 CCachePageManager::CCachePageManager(struct IDirectDrawSurface7 *,struct IDirectDrawSurface7 *,struct IDirect3DDevice7 *) {
  
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+4h] [ebp-8h]

  *((_DWORD *)this + 1) = a2;
  *(_DWORD *)this = a3;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 511) = 0;
  *((_BYTE *)this + 2073) = 0;
  *((_BYTE *)this + 2072) = 0;
  *((_DWORD *)this + 519) = 0;
  *((_DWORD *)this + 520) = 0;
  *((_DWORD *)this + 515) = 0;
  *((_DWORD *)this + 514) = 0;
  *((_DWORD *)this + 516) = 511;
  *((_DWORD *)this + 517) = 511;
  *((_DWORD *)this + 512) = 0;
  *((_DWORD *)this + 513) = 0;
  for ( i = 0; i < 576; ++i )
  {
    dword_46C1F20[8 * i] = (int)&dword_F29144[220078] + 3;
    dword_46C1F18[8 * i] = LODWORD(FLOAT_0_5);
    dword_46C1F1C[8 * i] = LODWORD(FLOAT_0_5);
  }
  for ( j = 0; j < 512; ++j )
    CCachePageManager::sm_fTextureCoordTable[j] = (float)((float)j / 512.0) + 0.0009765625;
  return this;
}


// address=[0x2f878f0]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::~CCachePageManager(CCachePageManager *this)

 CCachePageManager::~CCachePageManager(void) {
  
  CCachePageManager *result; // eax

  result = this;
  if ( !*((_BYTE *)this + 2072) )
    return (CCachePageManager *)CCachePageManager::UnlockSourceSurface(this);
  return result;
}


// address=[0x2f87940]
// Decompiled from char __thiscall CCachePageManager::GetPictureArea(
        CCachePageManager *this,
        float a2,
        float a3,
        int a4,
        int a5,
        int a6,
        char a7,
        int *a8,
        int *a9)

bool  CCachePageManager::GetPictureArea(float,float,int,int,int,int,int &,int &) {
  
  int v10; // [esp+0h] [ebp-Ch]
  int v11; // [esp+4h] [ebp-8h]

  if ( *((int *)this + 511) >= 96 )
    return 0;
  if ( a5 + *((_DWORD *)this + 4) >= 512 )
    return 0;
  if ( a4 + *((_DWORD *)this + 3) < 512 )
    goto LABEL_10;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = *((_DWORD *)this + 6);
  if ( a5 + *((_DWORD *)this + 4) >= 512 )
    return 0;
  if ( a4 + *((_DWORD *)this + 3) >= 512 )
    return 0;
LABEL_10:
  *a8 = *((_DWORD *)this + 3);
  *a9 = *((_DWORD *)this + 4);
  *((_DWORD *)this + 3) += a4;
  if ( *((_DWORD *)this + 5) <= *((_DWORD *)this + 3) )
    v11 = *((_DWORD *)this + 3);
  else
    v11 = *((_DWORD *)this + 5);
  *((_DWORD *)this + 5) = v11;
  if ( *((_DWORD *)this + 6) <= a5 + *((_DWORD *)this + 4) )
    v10 = a5 + *((_DWORD *)this + 4);
  else
    v10 = *((_DWORD *)this + 6);
  *((_DWORD *)this + 6) = v10;
  *((_WORD *)this + 4 * *((_DWORD *)this + 511) + 14) = *(_WORD *)a8;
  *((_WORD *)this + 4 * *((_DWORD *)this + 511) + 15) = *(_WORD *)a9;
  *((_WORD *)this + 4 * *((_DWORD *)this + 511) + 16) = a4 + *a8;
  *((_WORD *)this + 4 * *((_DWORD *)this + 511) + 17) = a5 + *a9;
  *((float *)this + 2 * *((_DWORD *)this + 511) + 199) = a2;
  *((float *)this + 2 * *((_DWORD *)this + 511) + 200) = a3;
  *((_DWORD *)this + *((_DWORD *)this + 511) + 391) = a6;
  *((_BYTE *)this + (*((_DWORD *)this + 511))++ + 1948) = a7;
  return 1;
}


// address=[0x2f87b30]
// Decompiled from int __thiscall CCachePageManager::EraseExtensionAreas(
        CCachePageManager *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        bool a7)

long  CCachePageManager::EraseExtensionAreas(int,int,int,int,int,bool) {
  
  CBlitFX *BlitStructPtr; // [esp+0h] [ebp-20h]
  int v9; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+Ch] [ebp-14h] BYREF
  int v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch]
  int v14; // [esp+18h] [ebp-8h]

  v9 = 0;
  if ( a7 )
    BlitStructPtr = CBlitFX::GetBlitStructPtr((CBlitFX *)&s_cBlitFxAlphaDebug);
  else
    BlitStructPtr = CBlitFX::GetBlitStructPtr((CBlitFX *)&s_cBlitFxAlpha);
  if ( a2 >= *((_DWORD *)this + 511) )
    return v9;
  if ( a5 )
  {
    v12 = *((unsigned __int16 *)this + 4 * a2 + 15);
    v14 = *((unsigned __int16 *)this + 4 * a2 + 17);
    v11 = *((unsigned __int16 *)this + 4 * a2 + 14);
    v13 = a5 + v11;
    do
    {
      do
        v9 = (*(int (__stdcall **)(_DWORD, int *, _DWORD, _DWORD, int, CBlitFX *))(**(_DWORD **)this + 20))(
               *(_DWORD *)this,
               &v11,
               0,
               0,
               1536,
               BlitStructPtr);
      while ( v9 == -2005532132 );
    }
    while ( v9 == -2005532242 );
  }
  if ( a6 && !v9 )
  {
    v12 = *((unsigned __int16 *)this + 4 * a2 + 15);
    v14 = *((unsigned __int16 *)this + 4 * a2 + 17);
    v11 = *((unsigned __int16 *)this + 4 * a2 + 14);
    v13 = *((unsigned __int16 *)this + 4 * a2 + 16);
    v11 = v13 - a6;
    do
    {
      do
        v9 = (*(int (__stdcall **)(_DWORD, int *, _DWORD, _DWORD, int, CBlitFX *))(**(_DWORD **)this + 20))(
               *(_DWORD *)this,
               &v11,
               0,
               0,
               1536,
               BlitStructPtr);
      while ( v9 == -2005532132 );
    }
    while ( v9 == -2005532242 );
  }
  if ( a3 && !v9 )
  {
    v12 = *((unsigned __int16 *)this + 4 * a2 + 15);
    v14 = *((unsigned __int16 *)this + 4 * a2 + 17);
    v11 = *((unsigned __int16 *)this + 4 * a2 + 14);
    v13 = *((unsigned __int16 *)this + 4 * a2 + 16);
    v14 = a3 + v12;
    do
    {
      do
        v9 = (*(int (__stdcall **)(_DWORD, int *, _DWORD, _DWORD, int, CBlitFX *))(**(_DWORD **)this + 20))(
               *(_DWORD *)this,
               &v11,
               0,
               0,
               1536,
               BlitStructPtr);
      while ( v9 == -2005532132 );
    }
    while ( v9 == -2005532242 );
  }
  if ( !a4 || v9 )
    return v9;
  v12 = *((unsigned __int16 *)this + 4 * a2 + 15);
  v14 = *((unsigned __int16 *)this + 4 * a2 + 17);
  v11 = *((unsigned __int16 *)this + 4 * a2 + 14);
  v13 = *((unsigned __int16 *)this + 4 * a2 + 16);
  v12 = v14 - a4;
  do
  {
    do
      v9 = (*(int (__stdcall **)(_DWORD, int *, _DWORD, _DWORD, int, CBlitFX *))(**(_DWORD **)this + 20))(
             *(_DWORD *)this,
             &v11,
             0,
             0,
             1536,
             BlitStructPtr);
    while ( v9 == -2005532132 );
  }
  while ( v9 == -2005532242 );
  return v9;
}


// address=[0x2f87db0]
// Decompiled from bool __thiscall CCachePageManager::UploadData(CCachePageManager *this, int *a2)

bool  CCachePageManager::UploadData(long &) {
  
  if ( CCachePageManager::IsData(this) )
  {
    if ( *((_BYTE *)this + 2072) && (*a2 = CCachePageManager::UnlockSourceSurface(this)) != 0 )
    {
      return 0;
    }
    else
    {
      *((_DWORD *)this + 516) = *((_DWORD *)this + 5);
      *((_DWORD *)this + 517) = *((_DWORD *)this + 6);
      *a2 = (*(int (__stdcall **)(_DWORD, _DWORD, char *, _DWORD, char *, _DWORD))(**((_DWORD **)this + 2) + 172))(
              *((_DWORD *)this + 2),
              *((_DWORD *)this + 1),
              (char *)this + 2048,
              *(_DWORD *)this,
              (char *)this + 2056,
              0);
      if ( *a2 == -2005532222 )
      {
        (*(void (__stdcall **)(_DWORD))(**((_DWORD **)this + 1) + 108))(*((_DWORD *)this + 1));
        CCachePageManager::ReleaseData(this);
        return 0;
      }
      else
      {
        return *a2 == 0;
      }
    }
  }
  else
  {
    *a2 = 0;
    return 0;
  }
}


// address=[0x2f87ea0]
// Decompiled from // public: bool __thiscall CCachePageManager::UploadDataAndRender(long &)
char __thiscall CCachePageManager::UploadDataAndRender(int this, _DWORD *a2)

bool  CCachePageManager::UploadDataAndRender(long &) {
  
  int v3; // [esp+0h] [ebp-2Ch]
  int v4; // [esp+4h] [ebp-28h]
  int v5; // [esp+8h] [ebp-24h]
  int v6; // [esp+Ch] [ebp-20h]
  int v7; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-18h]
  int v9; // [esp+18h] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-4h]

  if ( CCachePageManager::IsData((CCachePageManager *)this) )
  {
    *a2 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 8) + 140))(
            *(_DWORD *)(this + 8),
            0,
            *(_DWORD *)(this + 4));
    if ( *a2 )
    {
      return 0;
    }
    else if ( *(_BYTE *)(this + 2072) && (*a2 = CCachePageManager::UnlockSourceSurface((CCachePageManager *)this)) != 0 )
    {
      return 0;
    }
    else
    {
      *(_DWORD *)(this + 2064) = *(_DWORD *)(this + 20);
      *(_DWORD *)(this + 2068) = *(_DWORD *)(this + 24);
      *a2 = (*(int (__stdcall **)(_DWORD, _DWORD, int, _DWORD, int, _DWORD))(**(_DWORD **)(this + 8) + 172))(
              *(_DWORD *)(this + 8),
              *(_DWORD *)(this + 4),
              this + 2048,
              *(_DWORD *)this,
              this + 2056,
              0);
      if ( *a2 == -2005532222 )
      {
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(this + 4) + 108))(*(_DWORD *)(this + 4));
        CCachePageManager::ReleaseData((CCachePageManager *)this);
        return 0;
      }
      else if ( *a2 )
      {
        return 0;
      }
      else
      {
        for ( i = 0; i < *(_DWORD *)(this + 2044); ++i )
        {
          v13 = 6 * i;
          v8 = *(unsigned __int16 *)(this + 8 * i + 28) + 1;
          v7 = *(unsigned __int16 *)(this + 8 * i + 30) + 1;
          v6 = *(unsigned __int16 *)(this + 8 * i + 32) - v8 - 1;
          v5 = *(unsigned __int16 *)(this + 8 * i + 34) - v7 - 1;
          v4 = (int)(float)((float)v6 * *(float *)&CCachePageManager::sm_fZoomFactor) >> *(_BYTE *)(i + this + 1948);
          v3 = (int)(float)((float)v5 * *(float *)&CCachePageManager::sm_fZoomFactor) >> *(_BYTE *)(i + this + 1948);
          *(float *)&v10 = (float)s_iObjectOffsetX
                         + (float)(*(float *)(this + 8 * i + 796) + *(float *)&CCachePageManager::sm_fZoomFactor);
          *(float *)&v9 = (float)s_iObjectOffsetY
                        + (float)(*(float *)(this + 8 * i + 800) + *(float *)&CCachePageManager::sm_fZoomFactor);
          CCachePageManager::sm_sVertexList[48 * i] = v10;
          dword_46C1F14[8 * v13] = v9;
          dword_46C1F28[8 * v13] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v8]);
          dword_46C1F2C[8 * v13] = CCachePageManager::sm_fTextureCoordTable[v7];
          *(float *)&CCachePageManager::sm_sVertexList[8 * v13 + 8] = (float)v4 + *(float *)&v10;
          *(float *)&dword_46C1F14[8 * v13 + 8] = (float)v3 + *(float *)&v9;
          dword_46C1F28[8 * v13 + 8] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v6 + v8]);
          dword_46C1F2C[8 * v13 + 8] = CCachePageManager::sm_fTextureCoordTable[v5 + v7];
          CCachePageManager::sm_sVertexList[8 * v13 + 16] = v10;
          *(float *)&dword_46C1F14[8 * v13 + 16] = (float)v3 + *(float *)&v9;
          dword_46C1F28[8 * v13 + 16] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v8]);
          dword_46C1F2C[8 * v13 + 16] = CCachePageManager::sm_fTextureCoordTable[v5 + v7];
          CCachePageManager::sm_sVertexList[8 * v13 + 24] = v10;
          dword_46C1F14[8 * v13 + 24] = v9;
          dword_46C1F28[8 * v13 + 24] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v8]);
          dword_46C1F2C[8 * v13 + 24] = CCachePageManager::sm_fTextureCoordTable[v7];
          *(float *)&CCachePageManager::sm_sVertexList[8 * v13 + 32] = (float)v4 + *(float *)&v10;
          dword_46C1F14[8 * v13 + 32] = v9;
          dword_46C1F28[8 * v13 + 32] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v6 + v8]);
          dword_46C1F2C[8 * v13 + 32] = CCachePageManager::sm_fTextureCoordTable[v7];
          *(float *)&CCachePageManager::sm_sVertexList[8 * v13 + 40] = (float)v4 + *(float *)&v10;
          *(float *)&dword_46C1F14[8 * v13 + 40] = (float)v3 + *(float *)&v9;
          dword_46C1F28[8 * v13 + 40] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v6 + v8]);
          dword_46C1F2C[8 * v13 + 40] = CCachePageManager::sm_fTextureCoordTable[v5 + v7];
          dword_46C1F20[8 * v13 + 40] = *(_DWORD *)(this + 4 * i + 1564);
          dword_46C1F20[8 * v13 + 32] = dword_46C1F20[8 * v13 + 40];
          dword_46C1F20[8 * v13 + 24] = dword_46C1F20[8 * v13 + 32];
          dword_46C1F20[8 * v13 + 16] = dword_46C1F20[8 * v13 + 24];
          dword_46C1F20[8 * v13 + 8] = dword_46C1F20[8 * v13 + 16];
          dword_46C1F20[8 * v13] = dword_46C1F20[48 * i + 8];
        }
        *a2 = (*(int (__stdcall **)(_DWORD, int, int, int *, int, _DWORD))(**(_DWORD **)(this + 8) + 100))(
                *(_DWORD *)(this + 8),
                4,
                452,
                CCachePageManager::sm_sVertexList,
                6 * *(_DWORD *)(this + 2044),
                0);
        if ( *a2 )
        {
          return 0;
        }
        else
        {
          CCachePageManager::ReleaseData((CCachePageManager *)this);
          return 1;
        }
      }
    }
  }
  else
  {
    *a2 = 0;
    return 0;
  }
}


// address=[0x2f88440]
// Decompiled from bool __thiscall CCachePageManager::ShowPageContent(CCachePageManager *this, int *a2)

bool  CCachePageManager::ShowPageContent(long &) {
  
  CBlitFX *BlitStructPtr; // eax
  int v4; // [esp+0h] [ebp-28h]

  *a2 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)this + 2) + 140))(
          *((_DWORD *)this + 2),
          0,
          *((_DWORD *)this + 1));
  if ( *a2 )
    return 0;
  if ( *((_BYTE *)this + 2072) )
  {
    *a2 = CCachePageManager::UnlockSourceSurface(this);
    if ( *a2 )
      return 0;
  }
  *((_DWORD *)this + 516) = 511;
  *((_DWORD *)this + 517) = 511;
  if ( !*(_DWORD *)this )
    goto LABEL_11;
  *a2 = (*(int (__stdcall **)(_DWORD, _DWORD, char *, _DWORD, char *, _DWORD))(**((_DWORD **)this + 2) + 172))(
          *((_DWORD *)this + 2),
          *((_DWORD *)this + 1),
          (char *)this + 2048,
          *(_DWORD *)this,
          (char *)this + 2056,
          0);
  if ( *a2 == -2005532222 )
  {
    (*(void (__stdcall **)(_DWORD))(**((_DWORD **)this + 1) + 108))(*((_DWORD *)this + 1));
    CCachePageManager::ReleaseData(this);
    return 0;
  }
  if ( *a2 )
    return 0;
LABEL_11:
  *(float *)&CCachePageManager::sm_sVertexList = (float)300;
  *(float *)&dword_46C1F14 = (float)100;
  dword_46C1F28 = LODWORD(CCachePageManager::sm_fTextureCoordTable[0]);
  dword_46C1F2C[0] = CCachePageManager::sm_fTextureCoordTable[0];
  *((float *)&CCachePageManager::sm_sVertexList + 8) = (float)812;
  *((float *)&dword_46C1F14 + 8) = (float)612;
  *(&dword_46C1F28 + 8) = LODWORD(CCachePageManager::sm_fTextureCoordTable[511]);
  dword_46C1F2C[8] = CCachePageManager::sm_fTextureCoordTable[511];
  *((float *)&CCachePageManager::sm_sVertexList + 16) = (float)300;
  *((float *)&dword_46C1F14 + 16) = (float)612;
  *(&dword_46C1F28 + 16) = LODWORD(CCachePageManager::sm_fTextureCoordTable[0]);
  dword_46C1F2C[16] = CCachePageManager::sm_fTextureCoordTable[511];
  *((float *)&CCachePageManager::sm_sVertexList + 24) = (float)300;
  *((float *)&dword_46C1F14 + 24) = (float)100;
  *(&dword_46C1F28 + 24) = LODWORD(CCachePageManager::sm_fTextureCoordTable[0]);
  dword_46C1F2C[24] = CCachePageManager::sm_fTextureCoordTable[0];
  *((float *)&CCachePageManager::sm_sVertexList + 32) = (float)812;
  *((float *)&dword_46C1F14 + 32) = (float)100;
  *(&dword_46C1F28 + 32) = LODWORD(CCachePageManager::sm_fTextureCoordTable[511]);
  dword_46C1F2C[32] = CCachePageManager::sm_fTextureCoordTable[0];
  *((float *)&CCachePageManager::sm_sVertexList + 40) = (float)812;
  *((float *)&dword_46C1F14 + 40) = (float)612;
  *(&dword_46C1F28 + 40) = LODWORD(CCachePageManager::sm_fTextureCoordTable[511]);
  dword_46C1F2C[40] = CCachePageManager::sm_fTextureCoordTable[511];
  dword_46C1F20[40] = (int)&dword_F29144[220078] + 3;
  dword_46C1F20[32] = (int)&dword_F29144[220078] + 3;
  dword_46C1F20[24] = (int)&dword_F29144[220078] + 3;
  dword_46C1F20[16] = (int)&dword_F29144[220078] + 3;
  dword_46C1F20[8] = (int)&dword_F29144[220078] + 3;
  dword_46C1F20[0] = (int)&dword_F29144[220078] + 3;
  *a2 = (*(int (__stdcall **)(_DWORD, int, int, int *, int, _DWORD))(**((_DWORD **)this + 2) + 100))(
          *((_DWORD *)this + 2),
          4,
          452,
          &CCachePageManager::sm_sVertexList,
          6,
          0);
  if ( *(_DWORD *)this )
  {
    do
    {
      do
      {
        BlitStructPtr = CBlitFX::GetBlitStructPtr((CBlitFX *)&s_cBlitFx);
        v4 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, int, CBlitFX *))(**(_DWORD **)this + 20))(
               *(_DWORD *)this,
               0,
               0,
               0,
               1536,
               BlitStructPtr);
      }
      while ( v4 == -2005532132 );
    }
    while ( v4 == -2005532242 );
  }
  return *a2 == 0;
}


// address=[0x2f888b0]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::ReleaseData(CCachePageManager *this)

void  CCachePageManager::ReleaseData(void) {
  
  CCachePageManager *result; // eax

  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 4) = 0;
  result = this;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 511) = 0;
  return result;
}


// address=[0x2f888f0]
// Decompiled from int __thiscall CCachePageManager::RenderCacheObject(
        CCachePageManager *this,
        int a2,
        float a3,
        float a4,
        int a5,
        char a6,
        int a7,
        bool a8)

long  CCachePageManager::RenderCacheObject(int,float,float,int,int,int,bool) {
  
  float v9; // [esp+30h] [ebp-48h]
  int v10; // [esp+34h] [ebp-44h]
  float v11; // [esp+38h] [ebp-40h]
  float v12; // [esp+3Ch] [ebp-3Ch]
  int v13; // [esp+40h] [ebp-38h]
  int v14; // [esp+44h] [ebp-34h]
  int v15; // [esp+48h] [ebp-30h]
  int v16; // [esp+4Ch] [ebp-2Ch]
  int v17; // [esp+4Ch] [ebp-2Ch]
  int v18; // [esp+50h] [ebp-28h]
  float v19; // [esp+54h] [ebp-24h]
  int v20; // [esp+58h] [ebp-20h]
  float v21; // [esp+5Ch] [ebp-1Ch]
  int v23; // [esp+64h] [ebp-14h]
  int v24; // [esp+68h] [ebp-10h]
  int v25; // [esp+6Ch] [ebp-Ch]
  float v26; // [esp+70h] [ebp-8h]
  int v27; // [esp+70h] [ebp-8h]
  int v28; // [esp+74h] [ebp-4h]

  if ( !CCachePageManager::IsData(this) )
    return 0;
  v16 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)this + 2) + 140))(
          *((_DWORD *)this + 2),
          0,
          *((_DWORD *)this + 1));
  if ( v16 )
    return v16;
  if ( *((_BYTE *)this + 2073) )
  {
    v17 = CCachePageManager::UnlockVideoSurface(this);
    if ( v17 )
      return v17;
  }
  v24 = *((unsigned __int16 *)this + 4 * a2 + 14) + 1;
  v25 = *((unsigned __int16 *)this + 4 * a2 + 15) + 1;
  v18 = *((unsigned __int16 *)this + 4 * a2 + 16) - v24 - 1;
  v20 = *((unsigned __int16 *)this + 4 * a2 + 17) - v25 - 1;
  if ( a8 )
  {
    v19 = (float)v18 - 1.0;
    v21 = (float)v20 - 1.0;
    v18 = *((unsigned __int16 *)this + 4 * a2 + 16) - v24 - 2;
    v20 = *((unsigned __int16 *)this + 4 * a2 + 17) - v25 - 2;
  }
  else
  {
    v19 = (float)v18 * *(float *)&CCachePageManager::sm_fZoomFactor;
    v21 = (float)v20 * *(float *)&CCachePageManager::sm_fZoomFactor;
  }
  if ( (a6 & 7) != 0 )
  {
    v19 = v19 * 0.5;
    v21 = v21 * 0.5;
  }
  v26 = a4;
  if ( a7 )
  {
    if ( a7 == 255 )
      return 0;
    v15 = a7 * v20 / 256;
    v12 = (float)v15 * *(float *)&CCachePageManager::sm_fZoomFactor;
    v25 += v15;
    v20 -= v15;
    v26 = a4 + v12;
    v21 = v21 - v12;
  }
  *(float *)&v23 = (float)s_iObjectOffsetX + a3;
  *(float *)&v27 = (float)s_iObjectOffsetY + v26;
  CCachePageManager::sm_sVertexList[0] = v23;
  dword_46C1F14[0] = v27;
  *(float *)dword_46C1F28 = CCachePageManager::sm_fTextureCoordTable[v24];
  dword_46C1F2C[0] = CCachePageManager::sm_fTextureCoordTable[v25];
  *(float *)&CCachePageManager::sm_sVertexList[8] = *(float *)&v23 + v19;
  *(float *)&dword_46C1F14[8] = *(float *)&v27 + v21;
  dword_46C1F28[8] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v18 + v24]);
  dword_46C1F2C[8] = CCachePageManager::sm_fTextureCoordTable[v20 + v25];
  CCachePageManager::sm_sVertexList[16] = v23;
  *(float *)&dword_46C1F14[16] = *(float *)&v27 + v21;
  dword_46C1F28[16] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v24]);
  dword_46C1F2C[16] = CCachePageManager::sm_fTextureCoordTable[v20 + v25];
  CCachePageManager::sm_sVertexList[24] = v23;
  dword_46C1F14[24] = v27;
  dword_46C1F28[24] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v24]);
  dword_46C1F2C[24] = CCachePageManager::sm_fTextureCoordTable[v25];
  *(float *)&CCachePageManager::sm_sVertexList[32] = *(float *)&v23 + v19;
  dword_46C1F14[32] = v27;
  dword_46C1F28[32] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v18 + v24]);
  dword_46C1F2C[32] = CCachePageManager::sm_fTextureCoordTable[v25];
  *(float *)&CCachePageManager::sm_sVertexList[40] = *(float *)&v23 + v19;
  *(float *)&dword_46C1F14[40] = *(float *)&v27 + v21;
  dword_46C1F28[40] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v18 + v24]);
  dword_46C1F2C[40] = CCachePageManager::sm_fTextureCoordTable[v20 + v25];
  dword_46C1F20[40] = a5;
  dword_46C1F20[32] = a5;
  dword_46C1F20[24] = a5;
  dword_46C1F20[16] = a5;
  dword_46C1F20[8] = a5;
  dword_46C1F20[0] = a5;
  v10 = 0;
  if ( (a6 & 0x20) != 0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: ObjectTrace: %d ----------------------", a2);
    BBSupportTracePrintF(0, "GFX ENGINE: X: %d Y: %d", v24, v25);
    BBSupportTracePrintF(0, "GFX ENGINE: Width: %d Height: %d ScaledWidth: %f ScaledHeight: %f", v18, v20, v19, v21);
    BBSupportTracePrintF(
      0,
      "GFX ENGINE: Vertex 0 : %f, %f, %f, %f",
      *(float *)CCachePageManager::sm_sVertexList,
      *(float *)dword_46C1F14,
      *(float *)dword_46C1F28,
      dword_46C1F2C[0]);
    BBSupportTracePrintF(
      0,
      "GFX ENGINE: Vertex 1 : %f, %f, %f, %f",
      *(float *)&CCachePageManager::sm_sVertexList[8],
      *(float *)&dword_46C1F14[8],
      *(float *)&dword_46C1F28[8],
      dword_46C1F2C[8]);
    BBSupportTracePrintF(
      0,
      "GFX ENGINE: Vertex 2 : %f, %f, %f, %f",
      *(float *)&CCachePageManager::sm_sVertexList[16],
      *(float *)&dword_46C1F14[16],
      *(float *)&dword_46C1F28[16],
      dword_46C1F2C[16]);
    BBSupportTracePrintF(
      0,
      "GFX ENGINE: Vertex 3 : %f, %f, %f, %f",
      *(float *)&CCachePageManager::sm_sVertexList[24],
      *(float *)&dword_46C1F14[24],
      *(float *)&dword_46C1F28[24],
      dword_46C1F2C[24]);
    BBSupportTracePrintF(
      0,
      "GFX ENGINE: Vertex 4 : %f, %f, %f, %f",
      *(float *)&CCachePageManager::sm_sVertexList[32],
      *(float *)&dword_46C1F14[32],
      *(float *)&dword_46C1F28[32],
      dword_46C1F2C[32]);
    BBSupportTracePrintF(
      0,
      "GFX ENGINE: Vertex 5 : %f, %f, %f, %f",
      *(float *)&CCachePageManager::sm_sVertexList[40],
      *(float *)&dword_46C1F14[40],
      *(float *)&dword_46C1F28[40],
      dword_46C1F2C[40]);
  }
  if ( !a7 )
    return (*(int (__stdcall **)(_DWORD, int, int, int *, int, _DWORD))(**((_DWORD **)this + 2) + 100))(
             *((_DWORD *)this + 2),
             4,
             452,
             CCachePageManager::sm_sVertexList,
             v10 + 6,
             0);
  v14 = v18 / 12;
  v28 = 6;
  v13 = 6;
  if ( v15 < 6 )
    v13 = v15;
  v9 = (float)v13 * *(float *)&CCachePageManager::sm_fZoomFactor;
  v10 = 3 * v14;
  v11 = 12.0 * *(float *)&CCachePageManager::sm_fZoomFactor;
  while ( --v14 >= 0 )
  {
    CCachePageManager::sm_sVertexList[8 * v28] = v23;
    dword_46C1F14[8 * v28] = v27;
    dword_46C1F28[8 * v28] = LODWORD(CCachePageManager::sm_fTextureCoordTable[v24]);
    dword_46C1F2C[8 * v28] = CCachePageManager::sm_fTextureCoordTable[v25];
    *(float *)&CCachePageManager::sm_sVertexList[8 * v28 + 8] = (float)(v11 * 0.5) + *(float *)&v23;
    *(float *)&dword_46C1F14[8 * v28 + 8] = *(float *)&v27 - v9;
    dword_46C1F28[8 * v28 + 8] = dword_46C16B8[v24];
    dword_46C1F2C[8 * v28 + 8] = CCachePageManager::sm_fTextureCoordTable[v25 - v13];
    *(float *)&CCachePageManager::sm_sVertexList[8 * v28 + 16] = *(float *)&v23 + v11;
    dword_46C1F14[8 * v28 + 16] = v27;
    dword_46C1F28[8 * v28 + 16] = dword_46C16D0[v24];
    dword_46C1F2C[8 * v28 + 16] = CCachePageManager::sm_fTextureCoordTable[v25];
    dword_46C1F20[8 * v28 + 16] = a5;
    dword_46C1F20[8 * v28 + 8] = a5;
    dword_46C1F20[8 * v28] = a5;
    v24 += 12;
    *(float *)&v23 = (float)(12.0 * *(float *)&CCachePageManager::sm_fZoomFactor) + *(float *)&v23;
    v28 += 3;
  }
  return (*(int (__stdcall **)(_DWORD, int, int, int *, int, _DWORD))(**((_DWORD **)this + 2) + 100))(
           *((_DWORD *)this + 2),
           4,
           452,
           CCachePageManager::sm_sVertexList,
           v10 + 6,
           0);
}


// address=[0x2f89350]
// Decompiled from int __thiscall CCachePageManager::LockSourceSurface(CCachePageManager *this, int *a2, unsigned __int16 **a3)

long  CCachePageManager::LockSourceSurface(int &,unsigned short * &) {
  
  int v4; // [esp+0h] [ebp-8h]

  if ( *((_BYTE *)this + 2072) )
  {
    *a2 = *((_DWORD *)this + 520);
    *a3 = (unsigned __int16 *)*((_DWORD *)this + 519);
    return 0;
  }
  else
  {
    v4 = (*(int (__stdcall **)(_DWORD, _DWORD, DDSURFACEDESC2 *, int, _DWORD))(**(_DWORD **)this + 100))(
           *(_DWORD *)this,
           0,
           &s_cSurfaceDescription,
           33,
           0);
    if ( v4 )
      return v4;
    *((_DWORD *)this + 520) = s_cSurfaceDescription.lPitch;
    *a2 = s_cSurfaceDescription.lPitch;
    *((_DWORD *)this + 519) = s_cSurfaceDescription.lpSurface;
    *a3 = (unsigned __int16 *)*((_DWORD *)this + 519);
    *((_BYTE *)this + 2072) = 1;
    return v4;
  }
}


// address=[0x2f89400]
// Decompiled from int __thiscall CCachePageManager::LockVideoSurface(CCachePageManager *this, int *a2, unsigned __int16 **a3)

long  CCachePageManager::LockVideoSurface(int &,unsigned short * &) {
  
  int v4; // [esp+0h] [ebp-8h]

  if ( *((_BYTE *)this + 2073) )
  {
    *a2 = *((_DWORD *)this + 520);
    *a3 = (unsigned __int16 *)*((_DWORD *)this + 519);
    return 0;
  }
  else
  {
    v4 = (*(int (__stdcall **)(_DWORD, _DWORD, DDSURFACEDESC2 *, int, _DWORD))(**((_DWORD **)this + 1) + 100))(
           *((_DWORD *)this + 1),
           0,
           &s_cSurfaceDescription,
           33,
           0);
    if ( v4 )
      return v4;
    *((_DWORD *)this + 520) = s_cSurfaceDescription.lPitch;
    *a2 = s_cSurfaceDescription.lPitch;
    *((_DWORD *)this + 519) = s_cSurfaceDescription.lpSurface;
    *a3 = (unsigned __int16 *)*((_DWORD *)this + 519);
    *((_BYTE *)this + 2073) = 1;
    return v4;
  }
}


// address=[0x2f894b0]
// Decompiled from int __thiscall CCachePageManager::UnlockSourceSurface(CCachePageManager *this)

long  CCachePageManager::UnlockSourceSurface(void) {
  
  int result; // eax

  if ( !*((_BYTE *)this + 2072) )
    return 0;
  result = (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)this + 128))(*(_DWORD *)this, 0);
  *((_BYTE *)this + 2072) = 0;
  return result;
}


// address=[0x2f89500]
// Decompiled from int __thiscall CCachePageManager::UnlockVideoSurface(CCachePageManager *this)

long  CCachePageManager::UnlockVideoSurface(void) {
  
  int result; // eax

  if ( !*((_BYTE *)this + 2073) )
    return 0;
  result = (*(int (__stdcall **)(_DWORD, _DWORD))(**((_DWORD **)this + 1) + 128))(*((_DWORD *)this + 1), 0);
  *((_BYTE *)this + 2073) = 0;
  return result;
}


// address=[0x2f8a420]
// Decompiled from bool __thiscall CCachePageManager::IsData(CCachePageManager *this)

bool  CCachePageManager::IsData(void) {
  
  return *((_DWORD *)this + 511) > 0;
}


// address=[0x2f99770]
// Decompiled from int __thiscall CCachePageManager::GetLastCacheObjectNr(CCachePageManager *this)

int  CCachePageManager::GetLastCacheObjectNr(void) {
  
  return *((_DWORD *)this + 511) - 1;
}


// address=[0x46c1698]
// [Decompilation failed for static float CCachePageManager::sm_fZoomFactor]

// address=[0x46c16a0]
// [Decompilation failed for static float * CCachePageManager::sm_fTextureCoordTable]

