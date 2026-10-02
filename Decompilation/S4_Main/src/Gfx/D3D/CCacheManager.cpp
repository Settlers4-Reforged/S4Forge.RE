#include "CCacheManager.h"

// Definitions for class CCacheManager

// address=[0x46f32d0]
CCacheManager g_cCacheManager{};

// address=[0x2f895b0]
// Decompiled from CCacheManager *__thiscall CCacheManager::CCacheManager(CCacheManager *this)
CCacheManager::CCacheManager(void) {
    CCacheManager::Reset();
}

// address=[0x2f895d0]
// Decompiled from void __thiscall CCacheManager::Reset(CCacheManager *this)
void CCacheManager::Reset(void) {
    memset(this->m_uSurfaceIdx, 0, sizeof(this->m_uSurfaceIdx));
    this->m_iUsedCacheTextures = 0;
}

// address=[0x2f89600]
// Decompiled from void __thiscall CCacheManager::SetCacheInfos(CCacheManager *this, int _iIndex, int _iInSurfaceNr, int _iAsObjectNr)
void CCacheManager::SetCacheInfos(int _iIndex, int _iInSurfaceNr, int _iAsObjectNr) {

    this->m_uSurfaceIdx[_iIndex][0] = _iInSurfaceNr;
    this->m_uSurfaceIdx[_iIndex][1] = _iAsObjectNr;
}

// address=[0x2f99740]
// Decompiled from int __thiscall CCacheManager::GetEntryIdx(CCacheManager *this, int a2)
int CCacheManager::GetEntryIdx(int a2) {

    return this->m_uSurfaceIdx[a2][1];
}

// address=[0x2f99790]
// Decompiled from int __thiscall CCacheManager::GetSurfaceIdx(CCacheManager *this, int a2)
int CCacheManager::GetSurfaceIdx(int a2) {

    return this->m_uSurfaceIdx[a2][0];
}

// address=[0x2f997c0]
// Decompiled from int __thiscall CCacheManager::GetUsedCacheTextures(CCacheManager *this)
int CCacheManager::GetUsedCacheTextures(void) {

    return this->m_iUsedCacheTextures;
}

// address=[0x2f997e0]
// Decompiled from bool __thiscall CCacheManager::IsGfxCached(CCacheManager *this, int a2)
bool CCacheManager::IsGfxCached(int a2) {

    return this->m_uSurfaceIdx[a2][0] != 0;
}

// address=[0x2f99830]
// Decompiled from CCacheManager *__thiscall CCacheManager::SetUsedCacheTextures(CCacheManager *this, int a2)
void CCacheManager::SetUsedCacheTextures(int a2) {
    this->m_iUsedCacheTextures = a2;
}
