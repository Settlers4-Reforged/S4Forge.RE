#include "CUploadCachePageManager.h"

// Definitions for class CUploadCachePageManager

// address=[0x2f69830]
// Decompiled from CUploadCachePageManager *__thiscall CUploadCachePageManager::CUploadCachePageManager(  CUploadCachePageManager *this,  struct IDirectDrawSurface7 *a2,  struct IDirectDrawSurface7 *a3,  struct IDirect3DDevice7 *a4)
 CUploadCachePageManager::CUploadCachePageManager(struct IDirectDrawSurface7 *,struct IDirectDrawSurface7 *,struct IDirect3DDevice7 *) {
  
  CCachePageManager::CCachePageManager(this, a2, a3, a4);
  return this;
}


// address=[0x2f69860]
// Decompiled from CCachePageManager *__thiscall CUploadCachePageManager::~CUploadCachePageManager(CUploadCachePageManager *this)
 CUploadCachePageManager::~CUploadCachePageManager(void) {
  
  return CCachePageManager::~CCachePageManager(this);
}


// address=[0x2f89550]
// Decompiled from int __thiscall CUploadCachePageManager::IsAlreadyStored(CUploadCachePageManager *this, int a2)
int  CUploadCachePageManager::IsAlreadyStored(int a2) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( a2 == -1 )
    return -1;
  for ( i = 0; i < *((_DWORD *)this + 511); ++i )
  {
    if ( *((_DWORD *)this + i + 521) == a2 )
      return i;
  }
  return -1;
}


// address=[0x2f99850]
// Decompiled from int __thiscall CUploadCachePageManager::StoreGfxId(CUploadCachePageManager *this, int a2, int a3)
void  CUploadCachePageManager::StoreGfxId(int a2, int a3) {
  
  int result; // eax

  result = a2;
  *((_DWORD *)this + a2 + 521) = a3;
  return result;
}


