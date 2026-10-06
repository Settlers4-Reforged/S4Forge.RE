#if FALSE
#include "CCachePageManager.h"

// Definitions for class CCachePageManager

// address=[0x2f5f420]
// Decompiled from void __thiscall CCachePageManager::SetCurrentZoomFactor(CCachePageManager *this, float a2)
void  CCachePageManager::SetCurrentZoomFactor(float a2) {
  
  CCachePageManager::sm_fZoomFactor = a2;
}


// address=[0x2f69960]
// Decompiled from unsigned __int8 __thiscall CCachePageManager::IsSourceSurfaceLocked(CCachePageManager *this)
bool  CCachePageManager::IsSourceSurfaceLocked(void) {
  
  return this->m_bSoureSurfaceIsLocked;
}


// address=[0x2f69980]
// Decompiled from unsigned __int8 __thiscall CCachePageManager::IsVideoSurfaceLocked(CCachePageManager *this)
bool  CCachePageManager::IsVideoSurfaceLocked(void) {
  
  return this->m_bVideoSurfaceIsLocked;
}


// address=[0x2f87760]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::CCachePageManager(CCachePageManager *this, struct IDirectDrawSurface7 *a2, struct IDirectDrawSurface7 *a3, struct IDirect3DDevice7 *a4)
 CCachePageManager::CCachePageManager(struct IDirectDrawSurface7 * a2, struct IDirectDrawSurface7 * a3, struct IDirect3DDevice7 * a4) {
  
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+4h] [ebp-8h]

  this->m_pVideoTexture = a2;
  this->m_pSystemTexture = a3;
  this->m_pRenderDevice = a4;
  this->m_iCurrentY = 0;
  this->m_iCurrentX = 0;
  this->m_iUploadHeight = 0;
  this->m_iUploadWidth = 0;
  this->m_iNumberOfObjects = 0;
  this->m_bVideoSurfaceIsLocked = 0;
  this->m_bSoureSurfaceIsLocked = 0;
  this->m_pRenderAdress = nullptr;
  this->m_iPitch = 0;
  this->m_sUploadRectangle.top = 0;
  this->m_sUploadRectangle.left = 0;
  this->m_sUploadRectangle.right = 511;
  this->m_sUploadRectangle.bottom = 511;
  this->m_sDestinationPoint.x = 0;
  this->m_sDestinationPoint.y = 0;
  for ( i = 0;
        i < 576;
        ++i )
  {
    *(&CCachePageManager::sm_sVertexList[0].color + 8 * i) = 0xFFFFFF;
    *((_DWORD *)&CCachePageManager::sm_sVertexList[0].sz + 8 * i) = 0x3F000000;// 0.5f
    *((_DWORD *)&CCachePageManager::sm_sVertexList[0].rhw + 8 * i) = 0x3F000000;// 0.5f
  }
  for ( j = 0;
        j < 512;
        ++j )
  {
    CCachePageManager::sm_fTextureCoordTable[j] = (float)((float)j / 512.0) + 0.0009765625;
  }
  return this;
}


// address=[0x2f878f0]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::~CCachePageManager(CCachePageManager *this)
 CCachePageManager::~CCachePageManager(void) {
  
  CCachePageManager *result; // eax

  result = this;
  if ( this->m_bSoureSurfaceIsLocked == 0 )
  {
    return (CCachePageManager *)CCachePageManager::UnlockSourceSurface(this);
  }
  return result;
}


// address=[0x2f87940]
// Decompiled from unsigned __int8 __thiscall CCachePageManager::GetPictureArea(CCachePageManager *this, float fBlitX, float fBlitY, int iWidth, int iHeight, int iShading, unsigned __int8 iShifting, int *iPosX, int *iPosY)
bool  CCachePageManager::GetPictureArea(float fBlitX, float fBlitY, int iWidth, int iHeight, int iShading, int iShifting, int & iPosX, int & iPosY) {
  
  int m_iUploadHeight; // [esp+0h] [ebp-Ch]
  int m_iCurrentX; // [esp+4h] [ebp-8h]

  if ( this->m_iNumberOfObjects >= 96 )
  {
    return 0;
  }
  if ( iHeight + this->m_iCurrentY >= 512 )
  {
    return 0;
  }
  if ( iWidth + this->m_iCurrentX >= 512 )
  {
    this->m_iCurrentX = 0;
    this->m_iCurrentY = this->m_iUploadHeight;
    if ( iHeight + this->m_iCurrentY >= 512 )
    {
      return 0;
    }
    if ( iWidth + this->m_iCurrentX >= 512 )
    {
      return 0;
    }
  }
  *iPosX = this->m_iCurrentX;
  *iPosY = this->m_iCurrentY;
  this->m_iCurrentX += iWidth;
  if ( this->m_iUploadWidth <= this->m_iCurrentX )
  {
    m_iCurrentX = this->m_iCurrentX;
  }
  else
  {
    m_iCurrentX = this->m_iUploadWidth;
  }
  this->m_iUploadWidth = m_iCurrentX;
  if ( this->m_iUploadHeight <= iHeight + this->m_iCurrentY )
  {
    m_iUploadHeight = iHeight + this->m_iCurrentY;
  }
  else
  {
    m_iUploadHeight = this->m_iUploadHeight;
  }
  this->m_iUploadHeight = m_iUploadHeight;
  this->m_sRectangleList[this->m_iNumberOfObjects].left = *(_WORD *)iPosX;
  this->m_sRectangleList[this->m_iNumberOfObjects].top = *(_WORD *)iPosY;
  this->m_sRectangleList[this->m_iNumberOfObjects].right = iWidth + *iPosX;
  this->m_sRectangleList[this->m_iNumberOfObjects].bottom = iHeight + *iPosY;
  this->m_sBlitPosition[this->m_iNumberOfObjects].x = fBlitX;
  this->m_sBlitPosition[this->m_iNumberOfObjects].y = fBlitY;
  this->m_iShading[this->m_iNumberOfObjects] = iShading;
  this->m_uShifting[this->m_iNumberOfObjects++] = iShifting;
  return 1;
}


// address=[0x2f87b30]
// Decompiled from HRESULT __thiscall CCachePageManager::EraseExtensionAreas(CCachePageManager *this, int _iIndex, int a3, int a4, int a5, int a6, bool a7)
long  CCachePageManager::EraseExtensionAreas(int _iIndex, int a3, int a4, int a5, int a6, bool a7) {
  
  int right; // edx
  CBlitFX *BlitStructPtr; // [esp+0h] [ebp-20h]
  HRESULT v10; // [esp+4h] [ebp-1Ch]
  tagRECT sRect; // [esp+Ch] [ebp-14h] BYREF

  v10 = 0;
  if ( a7 )
  {
    BlitStructPtr = CBlitFX::GetBlitStructPtr(&s_cBlitFxAlphaDebug);
  }
  else
  {
    BlitStructPtr = CBlitFX::GetBlitStructPtr(&s_cBlitFxAlpha);
  }
  if ( _iIndex >= this->m_iNumberOfObjects )
  {
    return v10;
  }
  if ( a5 != 0 )
  {
    sRect.top = this->m_sRectangleList[_iIndex].top;
    sRect.bottom = this->m_sRectangleList[_iIndex].bottom;
    sRect.left = this->m_sRectangleList[_iIndex].left;
    right = this->m_sRectangleList[_iIndex].right;
    sRect.right = a5 + sRect.left;
    do
    {
      do
      {
        v10 = this->m_pSystemTexture->lpVtbl->Blt(this->m_pSystemTexture, &sRect, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
      }
      while ( v10 == DDERR_WASSTILLDRAWING );
    }
    while ( v10 == DDERR_SURFACEBUSY );
  }
  if ( a6 != 0 && v10 == 0 )
  {
    sRect.top = this->m_sRectangleList[_iIndex].top;
    sRect.bottom = this->m_sRectangleList[_iIndex].bottom;
    sRect.left = this->m_sRectangleList[_iIndex].left;
    sRect.right = this->m_sRectangleList[_iIndex].right;
    sRect.left = sRect.right - a6;
    do
    {
      do
      {
        v10 = this->m_pSystemTexture->lpVtbl->Blt(this->m_pSystemTexture, &sRect, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
      }
      while ( v10 == DDERR_WASSTILLDRAWING );
    }
    while ( v10 == DDERR_SURFACEBUSY );
  }
  if ( a3 != 0 && v10 == 0 )
  {
    sRect.top = this->m_sRectangleList[_iIndex].top;
    sRect.bottom = this->m_sRectangleList[_iIndex].bottom;
    sRect.left = this->m_sRectangleList[_iIndex].left;
    sRect.right = this->m_sRectangleList[_iIndex].right;
    sRect.bottom = a3 + sRect.top;
    do
    {
      do
      {
        v10 = this->m_pSystemTexture->lpVtbl->Blt(this->m_pSystemTexture, &sRect, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
      }
      while ( v10 == DDERR_WASSTILLDRAWING );
    }
    while ( v10 == DDERR_SURFACEBUSY );
  }
  if ( a4 == 0 || v10 != 0 )
  {
    return v10;
  }
  sRect.top = this->m_sRectangleList[_iIndex].top;
  sRect.bottom = this->m_sRectangleList[_iIndex].bottom;
  sRect.left = this->m_sRectangleList[_iIndex].left;
  sRect.right = this->m_sRectangleList[_iIndex].right;
  sRect.top = sRect.bottom - a4;
  do
  {
    do
    {
      v10 = this->m_pSystemTexture->lpVtbl->Blt(this->m_pSystemTexture, &sRect, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
    }
    while ( v10 == DDERR_WASSTILLDRAWING );
  }
  while ( v10 == DDERR_SURFACEBUSY );
  return v10;
}


// address=[0x2f87db0]
// Decompiled from bool __thiscall CCachePageManager::UploadData(CCachePageManager *this, int *hResult)
bool  CCachePageManager::UploadData(long & hResult) {
  
  if ( CCachePageManager::IsData(this) )
  {
    if ( this->m_bSoureSurfaceIsLocked != 0 && (*hResult = CCachePageManager::UnlockSourceSurface(this), *hResult != 0) )
    {
      return false;
    }
    else
    {
      this->m_sUploadRectangle.right = this->m_iUploadWidth;
      this->m_sUploadRectangle.bottom = this->m_iUploadHeight;
      *hResult = this->m_pRenderDevice->Load(this->m_pRenderDevice, this->m_pVideoTexture, &this->m_sDestinationPoint, this->m_pSystemTexture, &this->m_sUploadRectangle, 0);
      if ( *hResult == DDERR_SURFACELOST )
      {
        this->m_pVideoTexture->lpVtbl->Restore(this->m_pVideoTexture);
        CCachePageManager::ReleaseData(this);
        return false;
      }
      else
      {
        return *hResult == 0;
      }
    }
  }
  else
  {
    *hResult = 0;
    return false;
  }
}


// address=[0x2f87ea0]
// Decompiled from char __thiscall CCachePageManager::UploadDataAndRender(CCachePageManager *this, int *a2)
bool  CCachePageManager::UploadDataAndRender(long & a2) {
  
  int v3; // [esp+0h] [ebp-2Ch]
  int v4; // [esp+4h] [ebp-28h]
  int v5; // [esp+8h] [ebp-24h]
  int v6; // [esp+Ch] [ebp-20h]
  int v7; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-18h]
  D3DVALUE v9; // [esp+18h] [ebp-14h]
  D3DVALUE v10; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-4h]

  if ( CCachePageManager::IsData(this) )
  {
    *a2 = this->m_pRenderDevice->SetTexture(this->m_pRenderDevice, 0, this->m_pVideoTexture);
    if ( *a2 != 0 )
    {
      return 0;
    }
    else if ( this->m_bSoureSurfaceIsLocked != 0 && (*a2 = CCachePageManager::UnlockSourceSurface(this), *a2 != 0) )
    {
      return 0;
    }
    else
    {
      this->m_sUploadRectangle.right = this->m_iUploadWidth;
      this->m_sUploadRectangle.bottom = this->m_iUploadHeight;
      *a2 = this->m_pRenderDevice->Load(this->m_pRenderDevice, this->m_pVideoTexture, &this->m_sDestinationPoint, this->m_pSystemTexture, &this->m_sUploadRectangle, 0);
      if ( *a2 == DDERR_SURFACELOST )
      {
        this->m_pVideoTexture->lpVtbl->Restore(this->m_pVideoTexture);
        CCachePageManager::ReleaseData(this);
        return 0;
      }
      else if ( *a2 != 0 )
      {
        return 0;
      }
      else
      {
        for ( i = 0;
              i < this->m_iNumberOfObjects;
              ++i )
        {
          v13 = 6 * i;
          v8 = this->m_sRectangleList[i].left + 1;
          v7 = this->m_sRectangleList[i].top + 1;
          v6 = this->m_sRectangleList[i].right - v8 - 1;
          v5 = this->m_sRectangleList[i].bottom - v7 - 1;
          v4 = (int)(float)((float)v6 * CCachePageManager::sm_fZoomFactor) >> this->m_uShifting[i];
          v3 = (int)(float)((float)v5 * CCachePageManager::sm_fZoomFactor) >> this->m_uShifting[i];
          v10 = (float)s_iObjectOffsetX + (float)(*(float *)&this->m_sBlitPosition[i].x + CCachePageManager::sm_fZoomFactor);
          v9 = (float)s_iObjectOffsetY + (float)(*(float *)&this->m_sBlitPosition[i].y + CCachePageManager::sm_fZoomFactor);
          CCachePageManager::sm_sVertexList[6 * i].sx = v10;
          *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v13) = v9;
          *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v13) = CCachePageManager::sm_fTextureCoordTable[v8];
          *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v13) = CCachePageManager::sm_fTextureCoordTable[v7];
          CCachePageManager::sm_sVertexList[v13 + 1].sx = (float)v4 + v10;
          *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v13 + 8) = (float)v3 + v9;
          *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v13 + 8) = CCachePageManager::sm_fTextureCoordTable[v6 + v8];
          *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v13 + 8) = CCachePageManager::sm_fTextureCoordTable[v5 + v7];
          CCachePageManager::sm_sVertexList[v13 + 2].sx = v10;
          *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v13 + 16) = (float)v3 + v9;
          *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v13 + 16) = CCachePageManager::sm_fTextureCoordTable[v8];
          *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v13 + 16) = CCachePageManager::sm_fTextureCoordTable[v5 + v7];
          CCachePageManager::sm_sVertexList[v13 + 3].sx = v10;
          *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v13 + 24) = v9;
          *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v13 + 24) = CCachePageManager::sm_fTextureCoordTable[v8];
          *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v13 + 24) = CCachePageManager::sm_fTextureCoordTable[v7];
          CCachePageManager::sm_sVertexList[v13 + 4].sx = (float)v4 + v10;
          *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v13 + 32) = v9;
          *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v13 + 32) = CCachePageManager::sm_fTextureCoordTable[v6 + v8];
          *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v13 + 32) = CCachePageManager::sm_fTextureCoordTable[v7];
          CCachePageManager::sm_sVertexList[v13 + 5].sx = (float)v4 + v10;
          *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v13 + 40) = (float)v3 + v9;
          *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v13 + 40) = CCachePageManager::sm_fTextureCoordTable[v6 + v8];
          *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v13 + 40) = CCachePageManager::sm_fTextureCoordTable[v5 + v7];
          *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 40) = this->m_iShading[i];
          *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 32) = *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 40);
          *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 24) = *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 32);
          *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 16) = *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 24);
          *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 8) = *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13 + 16);
          *(&CCachePageManager::sm_sVertexList[0].color + 8 * v13) = *(&CCachePageManager::sm_sVertexList[0].color + 48 * i + 8);
        }
        *a2 = this->m_pRenderDevice->DrawPrimitive(this->m_pRenderDevice, D3DPT_TRIANGLELIST, 452, CCachePageManager::sm_sVertexList, 6 * this->m_iNumberOfObjects, 0);
        if ( *a2 != 0 )
        {
          return 0;
        }
        else
        {
          CCachePageManager::ReleaseData(this);
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
bool  CCachePageManager::ShowPageContent(long & a2) {
  
  CBlitFX *BlitStructPtr; // eax
  HRESULT v4; // [esp+0h] [ebp-28h]

  *a2 = this->m_pRenderDevice->SetTexture(this->m_pRenderDevice, 0, this->m_pVideoTexture);
  if ( *a2 != 0 )
  {
    return false;
  }
  if ( this->m_bSoureSurfaceIsLocked != 0 )
  {
    *a2 = CCachePageManager::UnlockSourceSurface(this);
    if ( *a2 != 0 )
    {
      return false;
    }
  }
  this->m_sUploadRectangle.right = 511;
  this->m_sUploadRectangle.bottom = 511;
  if ( this->m_pSystemTexture != nullptr )
  {
    *a2 = this->m_pRenderDevice->Load(this->m_pRenderDevice, this->m_pVideoTexture, &this->m_sDestinationPoint, this->m_pSystemTexture, &this->m_sUploadRectangle, 0);
    if ( *a2 == DDERR_SURFACELOST )
    {
      this->m_pVideoTexture->lpVtbl->Restore(this->m_pVideoTexture);
      CCachePageManager::ReleaseData(this);
      return false;
    }
    if ( *a2 != 0 )
    {
      return false;
    }
  }
  CCachePageManager::sm_sVertexList[0].sx = (float)300;
  CCachePageManager::sm_sVertexList[0].sy = (float)100;
  CCachePageManager::sm_sVertexList[0].tu = CCachePageManager::sm_fTextureCoordTable[0];
  CCachePageManager::sm_sVertexList[0].tv = CCachePageManager::sm_fTextureCoordTable[0];
  CCachePageManager::sm_sVertexList[1].sx = (float)812;
  *(&CCachePageManager::sm_sVertexList[0].sy + 8) = (float)612;
  *(&CCachePageManager::sm_sVertexList[0].tu + 8) = CCachePageManager::sm_fTextureCoordTable[511];
  *(&CCachePageManager::sm_sVertexList[0].tv + 8) = CCachePageManager::sm_fTextureCoordTable[511];
  CCachePageManager::sm_sVertexList[2].sx = (float)300;
  *(&CCachePageManager::sm_sVertexList[0].sy + 16) = (float)612;
  *(&CCachePageManager::sm_sVertexList[0].tu + 16) = CCachePageManager::sm_fTextureCoordTable[0];
  *(&CCachePageManager::sm_sVertexList[0].tv + 16) = CCachePageManager::sm_fTextureCoordTable[511];
  CCachePageManager::sm_sVertexList[3].sx = (float)300;
  *(&CCachePageManager::sm_sVertexList[0].sy + 24) = (float)100;
  *(&CCachePageManager::sm_sVertexList[0].tu + 24) = CCachePageManager::sm_fTextureCoordTable[0];
  *(&CCachePageManager::sm_sVertexList[0].tv + 24) = CCachePageManager::sm_fTextureCoordTable[0];
  CCachePageManager::sm_sVertexList[4].sx = (float)812;
  *(&CCachePageManager::sm_sVertexList[0].sy + 32) = (float)100;
  *(&CCachePageManager::sm_sVertexList[0].tu + 32) = CCachePageManager::sm_fTextureCoordTable[511];
  *(&CCachePageManager::sm_sVertexList[0].tv + 32) = CCachePageManager::sm_fTextureCoordTable[0];
  CCachePageManager::sm_sVertexList[5].sx = (float)812;
  *(&CCachePageManager::sm_sVertexList[0].sy + 40) = (float)612;
  *(&CCachePageManager::sm_sVertexList[0].tu + 40) = CCachePageManager::sm_fTextureCoordTable[511];
  *(&CCachePageManager::sm_sVertexList[0].tv + 40) = CCachePageManager::sm_fTextureCoordTable[511];
  *(&CCachePageManager::sm_sVertexList[0].color + 40) = 0xFFFFFF;
  *(&CCachePageManager::sm_sVertexList[0].color + 32) = 0xFFFFFF;
  *(&CCachePageManager::sm_sVertexList[0].color + 24) = 0xFFFFFF;
  *(&CCachePageManager::sm_sVertexList[0].color + 16) = 0xFFFFFF;
  *(&CCachePageManager::sm_sVertexList[0].color + 8) = 0xFFFFFF;
  CCachePageManager::sm_sVertexList[0].color = 0xFFFFFF;
  *a2 = this->m_pRenderDevice->DrawPrimitive(this->m_pRenderDevice, D3DPT_TRIANGLELIST, 452, CCachePageManager::sm_sVertexList, 6, 0);
  if ( this->m_pSystemTexture != nullptr )
  {
    do
    {
      do
      {
        BlitStructPtr = CBlitFX::GetBlitStructPtr(&s_cBlitFx);
        v4 = this->m_pSystemTexture->lpVtbl->Blt(this->m_pSystemTexture, nullptr, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
      }
      while ( v4 == DDERR_WASSTILLDRAWING );
    }
    while ( v4 == DDERR_SURFACEBUSY );
  }
  return *a2 == 0;
}


// address=[0x2f888b0]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::ReleaseData(CCachePageManager *this)
void  CCachePageManager::ReleaseData(void) {
  
  this->m_iUploadWidth = 0;
  this->m_iUploadHeight = 0;
  this->m_iCurrentY = 0;
  this->m_iCurrentX = 0;
  this->m_iNumberOfObjects = 0;
  return this;
}


// address=[0x2f888f0]
// Decompiled from HRESULT __thiscall CCachePageManager::RenderCacheObject(CCachePageManager *this, int _iIndex, float _fX, float _fY, int _iShading, int _iFlags, int _iShift, bool a8)
long  CCachePageManager::RenderCacheObject(int _iIndex, float _fX, float _fY, int _iShading, int _iFlags, int _iShift, bool a8) {
  
  float v9; // [esp+30h] [ebp-48h]
  int v10; // [esp+34h] [ebp-44h]
  float v11; // [esp+38h] [ebp-40h]
  float v12; // [esp+3Ch] [ebp-3Ch]
  int v13; // [esp+40h] [ebp-38h]
  int v14; // [esp+44h] [ebp-34h]
  int v15; // [esp+48h] [ebp-30h]
  HRESULT v16; // [esp+4Ch] [ebp-2Ch]
  HRESULT v17; // [esp+4Ch] [ebp-2Ch]
  int iWidth; // [esp+50h] [ebp-28h]
  float iScaledWidth; // [esp+54h] [ebp-24h]
  int iHeight; // [esp+58h] [ebp-20h]
  float iScaledHeight; // [esp+5Ch] [ebp-1Ch]
  float v23; // [esp+64h] [ebp-14h]
  int iX; // [esp+68h] [ebp-10h]
  int iY; // [esp+6Ch] [ebp-Ch]
  float v26; // [esp+70h] [ebp-8h]
  float v27; // [esp+70h] [ebp-8h]
  int v28; // [esp+74h] [ebp-4h]

  if ( !CCachePageManager::IsData(this) )
  {
    return 0;
  }
  v16 = this->m_pRenderDevice->SetTexture(this->m_pRenderDevice, 0, this->m_pVideoTexture);
  if ( v16 != 0 )
  {
    return v16;
  }
  if ( this->m_bVideoSurfaceIsLocked != 0 )
  {
    v17 = CCachePageManager::UnlockVideoSurface(this);
    if ( v17 != 0 )
    {
      return v17;
    }
  }
  iX = this->m_sRectangleList[_iIndex].left + 1;
  iY = this->m_sRectangleList[_iIndex].top + 1;
  iWidth = this->m_sRectangleList[_iIndex].right - iX - 1;
  iHeight = this->m_sRectangleList[_iIndex].bottom - iY - 1;
  if ( a8 )
  {
    iScaledWidth = (float)iWidth - 1.0;
    iScaledHeight = (float)iHeight - 1.0;
    iWidth = this->m_sRectangleList[_iIndex].right - iX - 2;
    iHeight = this->m_sRectangleList[_iIndex].bottom - iY - 2;
  }
  else
  {
    iScaledWidth = (float)iWidth * CCachePageManager::sm_fZoomFactor;
    iScaledHeight = (float)iHeight * CCachePageManager::sm_fZoomFactor;
  }
  if ( (_iFlags & 7) != 0 )
  {
    iScaledWidth = iScaledWidth * 0.5;
    iScaledHeight = iScaledHeight * 0.5;
  }
  v26 = _fY;
  if ( _iShift != 0 )
  {
    if ( _iShift == 255 )
    {
      return 0;
    }
    v15 = _iShift * iHeight / 256;
    v12 = (float)v15 * CCachePageManager::sm_fZoomFactor;
    iY += v15;
    iHeight -= v15;
    v26 = _fY + v12;
    iScaledHeight = iScaledHeight - v12;
  }
  v23 = (float)s_iObjectOffsetX + _fX;
  v27 = (float)s_iObjectOffsetY + v26;
  CCachePageManager::sm_sVertexList[0].sx = v23;
  CCachePageManager::sm_sVertexList[0].sy = v27;
  CCachePageManager::sm_sVertexList[0].tu = CCachePageManager::sm_fTextureCoordTable[iX];
  CCachePageManager::sm_sVertexList[0].tv = CCachePageManager::sm_fTextureCoordTable[iY];
  CCachePageManager::sm_sVertexList[1].sx = v23 + iScaledWidth;
  *(&CCachePageManager::sm_sVertexList[0].sy + 8) = v27 + iScaledHeight;
  *(&CCachePageManager::sm_sVertexList[0].tu + 8) = CCachePageManager::sm_fTextureCoordTable[iWidth + iX];
  *(&CCachePageManager::sm_sVertexList[0].tv + 8) = CCachePageManager::sm_fTextureCoordTable[iHeight + iY];
  CCachePageManager::sm_sVertexList[2].sx = v23;
  *(&CCachePageManager::sm_sVertexList[0].sy + 16) = v27 + iScaledHeight;
  *(&CCachePageManager::sm_sVertexList[0].tu + 16) = CCachePageManager::sm_fTextureCoordTable[iX];
  *(&CCachePageManager::sm_sVertexList[0].tv + 16) = CCachePageManager::sm_fTextureCoordTable[iHeight + iY];
  CCachePageManager::sm_sVertexList[3].sx = v23;
  *(&CCachePageManager::sm_sVertexList[0].sy + 24) = v27;
  *(&CCachePageManager::sm_sVertexList[0].tu + 24) = CCachePageManager::sm_fTextureCoordTable[iX];
  *(&CCachePageManager::sm_sVertexList[0].tv + 24) = CCachePageManager::sm_fTextureCoordTable[iY];
  CCachePageManager::sm_sVertexList[4].sx = v23 + iScaledWidth;
  *(&CCachePageManager::sm_sVertexList[0].sy + 32) = v27;
  *(&CCachePageManager::sm_sVertexList[0].tu + 32) = CCachePageManager::sm_fTextureCoordTable[iWidth + iX];
  *(&CCachePageManager::sm_sVertexList[0].tv + 32) = CCachePageManager::sm_fTextureCoordTable[iY];
  CCachePageManager::sm_sVertexList[5].sx = v23 + iScaledWidth;
  *(&CCachePageManager::sm_sVertexList[0].sy + 40) = v27 + iScaledHeight;
  *(&CCachePageManager::sm_sVertexList[0].tu + 40) = CCachePageManager::sm_fTextureCoordTable[iWidth + iX];
  *(&CCachePageManager::sm_sVertexList[0].tv + 40) = CCachePageManager::sm_fTextureCoordTable[iHeight + iY];
  *(&CCachePageManager::sm_sVertexList[0].color + 40) = _iShading;
  *(&CCachePageManager::sm_sVertexList[0].color + 32) = _iShading;
  *(&CCachePageManager::sm_sVertexList[0].color + 24) = _iShading;
  *(&CCachePageManager::sm_sVertexList[0].color + 16) = _iShading;
  *(&CCachePageManager::sm_sVertexList[0].color + 8) = _iShading;
  CCachePageManager::sm_sVertexList[0].color = _iShading;
  v10 = 0;
  if ( (_iFlags & 32) != 0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: ObjectTrace: %d ----------------------", _iIndex);
    BBSupportTracePrintF(0, "GFX ENGINE: X: %d Y: %d", iX, iY);
    BBSupportTracePrintF(0, "GFX ENGINE: Width: %d Height: %d ScaledWidth: %f ScaledHeight: %f", iWidth, iHeight, iScaledWidth, iScaledHeight);
    BBSupportTracePrintF(0, "GFX ENGINE: Vertex 0 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[0].sx, CCachePageManager::sm_sVertexList[0].sy, CCachePageManager::sm_sVertexList[0].tu, CCachePageManager::sm_sVertexList[0].tv);
    BBSupportTracePrintF(0, "GFX ENGINE: Vertex 1 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[1].sx, *(&CCachePageManager::sm_sVertexList[0].sy + 8), *(&CCachePageManager::sm_sVertexList[0].tu + 8), *(&CCachePageManager::sm_sVertexList[0].tv + 8));
    BBSupportTracePrintF(0, "GFX ENGINE: Vertex 2 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[2].sx, *(&CCachePageManager::sm_sVertexList[0].sy + 16), *(&CCachePageManager::sm_sVertexList[0].tu + 16), *(&CCachePageManager::sm_sVertexList[0].tv + 16));
    BBSupportTracePrintF(0, "GFX ENGINE: Vertex 3 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[3].sx, *(&CCachePageManager::sm_sVertexList[0].sy + 24), *(&CCachePageManager::sm_sVertexList[0].tu + 24), *(&CCachePageManager::sm_sVertexList[0].tv + 24));
    BBSupportTracePrintF(0, "GFX ENGINE: Vertex 4 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[4].sx, *(&CCachePageManager::sm_sVertexList[0].sy + 32), *(&CCachePageManager::sm_sVertexList[0].tu + 32), *(&CCachePageManager::sm_sVertexList[0].tv + 32));
    BBSupportTracePrintF(0, "GFX ENGINE: Vertex 5 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[5].sx, *(&CCachePageManager::sm_sVertexList[0].sy + 40), *(&CCachePageManager::sm_sVertexList[0].tu + 40), *(&CCachePageManager::sm_sVertexList[0].tv + 40));
  }
  if ( _iShift == 0 )
  {
    return this->m_pRenderDevice->DrawPrimitive(this->m_pRenderDevice, D3DPT_TRIANGLELIST, 452, CCachePageManager::sm_sVertexList, v10 + 6, 0);
  }
  v14 = iWidth / 12;
  v28 = 6;
  v13 = 6;
  if ( v15 < 6 )
  {
    v13 = v15;
  }
  v9 = (float)v13 * CCachePageManager::sm_fZoomFactor;
  v10 = 3 * v14;
  v11 = 12.0 * CCachePageManager::sm_fZoomFactor;
  while ( --v14 >= 0 )
  {
    CCachePageManager::sm_sVertexList[v28].sx = v23;
    *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v28) = v27;
    *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v28) = CCachePageManager::sm_fTextureCoordTable[iX];
    *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v28) = CCachePageManager::sm_fTextureCoordTable[iY];
    CCachePageManager::sm_sVertexList[v28 + 1].sx = (float)(v11 * 0.5) + v23;
    *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v28 + 8) = v27 - v9;
    *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v28 + 8) = CCachePageManager::sm_fTextureCoordTable[iX + 6];
    *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v28 + 8) = CCachePageManager::sm_fTextureCoordTable[iY - v13];
    CCachePageManager::sm_sVertexList[v28 + 2].sx = v23 + v11;
    *(&CCachePageManager::sm_sVertexList[0].sy + 8 * v28 + 16) = v27;
    *(&CCachePageManager::sm_sVertexList[0].tu + 8 * v28 + 16) = CCachePageManager::sm_fTextureCoordTable[iX + 12];
    *(&CCachePageManager::sm_sVertexList[0].tv + 8 * v28 + 16) = CCachePageManager::sm_fTextureCoordTable[iY];
    *(&CCachePageManager::sm_sVertexList[0].color + 8 * v28 + 16) = _iShading;
    *(&CCachePageManager::sm_sVertexList[0].color + 8 * v28 + 8) = _iShading;
    *(&CCachePageManager::sm_sVertexList[0].color + 8 * v28) = _iShading;
    iX += 12;
    v23 = (float)(12.0 * CCachePageManager::sm_fZoomFactor) + v23;
    v28 += 3;
  }
  return this->m_pRenderDevice->DrawPrimitive(this->m_pRenderDevice, D3DPT_TRIANGLELIST, 452, CCachePageManager::sm_sVertexList, v10 + 6, 0);
}


// address=[0x2f89350]
// Decompiled from HRESULT __thiscall CCachePageManager::LockSourceSurface(CCachePageManager *this, int *_rPitch, ushort **_rRender)
long  CCachePageManager::LockSourceSurface(int & _rPitch, unsigned short * & _rRender) {
  
  HRESULT v4; // [esp+0h] [ebp-8h]

  if ( this->m_bSoureSurfaceIsLocked != 0 )
  {
    *_rPitch = this->m_iPitch;
    *_rRender = (ushort *)this->m_pRenderAdress;
    return 0;
  }
  else
  {
    v4 = this->m_pSystemTexture->lpVtbl->Lock(this->m_pSystemTexture, nullptr, (LPDDSURFACEDESC2)&s_cSurfaceDescription, 33, nullptr);
    if ( v4 != 0 )
    {
      return v4;
    }
    this->m_iPitch = s_cSurfaceDescription.m_sSurfaceDescription.lPitch;
    *_rPitch = s_cSurfaceDescription.m_sSurfaceDescription.lPitch;
    this->m_pRenderAdress = s_cSurfaceDescription.m_sSurfaceDescription.lpSurface;
    *_rRender = (ushort *)this->m_pRenderAdress;
    this->m_bSoureSurfaceIsLocked = 1;
    return v4;
  }
}


// address=[0x2f89400]
// Decompiled from HRESULT __thiscall CCachePageManager::LockVideoSurface(CCachePageManager *this, int *a2, unsigned __int16 **a3)
long  CCachePageManager::LockVideoSurface(int & a2, unsigned short * & a3) {
  
  HRESULT v4; // [esp+0h] [ebp-8h]

  if ( this->m_bVideoSurfaceIsLocked != 0 )
  {
    *a2 = this->m_iPitch;
    *a3 = (unsigned __int16 *)this->m_pRenderAdress;
    return 0;
  }
  else
  {
    v4 = this->m_pVideoTexture->lpVtbl->Lock(this->m_pVideoTexture, nullptr, (LPDDSURFACEDESC2)&s_cSurfaceDescription, 33, nullptr);
    if ( v4 != 0 )
    {
      return v4;
    }
    this->m_iPitch = s_cSurfaceDescription.m_sSurfaceDescription.lPitch;
    *a2 = s_cSurfaceDescription.m_sSurfaceDescription.lPitch;
    this->m_pRenderAdress = s_cSurfaceDescription.m_sSurfaceDescription.lpSurface;
    *a3 = (unsigned __int16 *)this->m_pRenderAdress;
    this->m_bVideoSurfaceIsLocked = 1;
    return v4;
  }
}


// address=[0x2f894b0]
// Decompiled from HRESULT __thiscall CCachePageManager::UnlockSourceSurface(CCachePageManager *this)
long  CCachePageManager::UnlockSourceSurface(void) {
  
  HRESULT result; // eax

  if ( this->m_bSoureSurfaceIsLocked == 0 )
  {
    return 0;
  }
  result = this->m_pSystemTexture->lpVtbl->Unlock(this->m_pSystemTexture, nullptr);
  this->m_bSoureSurfaceIsLocked = 0;
  return result;
}


// address=[0x2f89500]
// Decompiled from HRESULT __thiscall CCachePageManager::UnlockVideoSurface(CCachePageManager *this)
long  CCachePageManager::UnlockVideoSurface(void) {
  
  HRESULT result; // eax

  if ( this->m_bVideoSurfaceIsLocked == 0 )
  {
    return 0;
  }
  result = this->m_pVideoTexture->lpVtbl->Unlock(this->m_pVideoTexture, nullptr);
  this->m_bVideoSurfaceIsLocked = 0;
  return result;
}


// address=[0x2f8a420]
// Decompiled from bool __thiscall CCachePageManager::IsData(CCachePageManager *this)
bool  CCachePageManager::IsData(void) {
  
  return this->m_iNumberOfObjects > 0;
}


// address=[0x2f99770]
// Decompiled from int __thiscall CCachePageManager::GetLastCacheObjectNr(CCachePageManager *this)
int  CCachePageManager::GetLastCacheObjectNr(void) {
  
  return this->m_iNumberOfObjects - 1;
}


// address=[0x46c1698]
// [Decompilation failed for static float CCachePageManager::sm_fZoomFactor]

// address=[0x46c16a0]
// [Decompilation failed for static float * CCachePageManager::sm_fTextureCoordTable]

#endif // Already implemented
