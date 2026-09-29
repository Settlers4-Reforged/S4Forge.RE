#include "CUploadCachePageManager.h"

// Definitions for class CUploadCachePageManager

// address=[0x2f69830]
// Decompiled from CUploadCachePageManager *__thiscall CUploadCachePageManager::CUploadCachePageManager(CUploadCachePageManager *this, IDirectDrawSurface7 *a2, IDirectDrawSurface7 *a3, IDirect3DDevice7 *a4)
CUploadCachePageManager::CUploadCachePageManager(struct IDirectDrawSurface7 *a2, struct IDirectDrawSurface7 *a3, struct IDirect3DDevice7 *a4) : CCachePageManager(a2, a3, a4), m_iGfxIds{} {
}

// address=[0x2f69860]
// Decompiled from CCachePageManager *__thiscall CUploadCachePageManager::~CUploadCachePageManager(CCachePageManager *this)
CUploadCachePageManager::~CUploadCachePageManager(void) = default;

// address=[0x2f89550]
// Decompiled from int __thiscall CUploadCachePageManager::IsAlreadyStored(CUploadCachePageManager *this, int a2)
int CUploadCachePageManager::IsAlreadyStored(int _iGfxId) {
    if(_iGfxId == -1) {
        return -1;
    }

    for(int i = 0; i < this->m_iNumberOfObjects; ++i) {
        if(this->m_iGfxIds[i] == _iGfxId)
            return i;
    }
    return -1;
}

// address=[0x2f99850]
// Decompiled from void __thiscall CUploadCachePageManager::StoreGfxId(CUploadCachePageManager *this, int a2, int a3)
void CUploadCachePageManager::StoreGfxId(int _iPage, int _iGfxId) {
    this->m_iGfxIds[_iPage] = _iGfxId;
}
