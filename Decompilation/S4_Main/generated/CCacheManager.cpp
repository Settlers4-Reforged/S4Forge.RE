#include "all_headers.h"

// Definitions for class CCacheManager

// address=[0x2f895b0]
// Decompiled from CCacheManager *__thiscall CCacheManager::CCacheManager(CCacheManager *this)
 CCacheManager::CCacheManager(void) {
  
  CCacheManager::Reset(this);
  return this;
}


// address=[0x2f895d0]
// Decompiled from void *__thiscall CCacheManager::Reset(CCacheManager *this)
void  CCacheManager::Reset(void) {
  
  void *result; // eax

  result = memset(this, 0, 0x1FFFEu);
  *((_DWORD *)this + 0x8000) = 0;
  return result;
}


// address=[0x2f89600]
// Decompiled from char *__thiscall CCacheManager::SetCacheInfos(CCacheManager *this, int a2, char a3, char a4)
void  CCacheManager::SetCacheInfos(int,int,int) {
  
  char *result; // eax

  *((_BYTE *)this + 2 * a2) = a3;
  result = (char *)this + 2 * a2;
  result[1] = a4;
  return result;
}


// address=[0x2f99740]
// Decompiled from int __thiscall CCacheManager::GetEntryIdx(CCacheManager *this, int a2)
int  CCacheManager::GetEntryIdx(int) {
  
  return *((unsigned __int8 *)this + 2 * a2 + 1);
}


// address=[0x2f99790]
// Decompiled from int __thiscall CCacheManager::GetSurfaceIdx(CCacheManager *this, int a2)
int  CCacheManager::GetSurfaceIdx(int) {
  
  return *((unsigned __int8 *)this + 2 * a2);
}


// address=[0x2f997c0]
// Decompiled from int __thiscall CCacheManager::GetUsedCacheTextures(CCacheManager *this)
int  CCacheManager::GetUsedCacheTextures(void) {
  
  return *((_DWORD *)this + 0x8000);
}


// address=[0x2f997e0]
// Decompiled from bool __thiscall CCacheManager::IsGfxCached(CCacheManager *this, int a2)
bool  CCacheManager::IsGfxCached(int) {
  
  return *((_BYTE *)this + 2 * a2) != 0;
}


// address=[0x2f99830]
// Decompiled from CCacheManager *__thiscall CCacheManager::SetUsedCacheTextures(CCacheManager *this, int a2)
void  CCacheManager::SetUsedCacheTextures(int) {
  
  CCacheManager *result; // eax

  result = this;
  *((_DWORD *)this + 0x8000) = a2;
  return result;
}


