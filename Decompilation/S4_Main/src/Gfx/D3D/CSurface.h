#ifndef CSURFACE_H
#define CSURFACE_H

#include "defines.h"

class CSurface {
  public:
    // address=[0x2f86560]
    static class CSurface *__cdecl CreateSurfacePtr(bool _bUseV3);

    // address=[0x2f8a2f0]
    CSurface(void);

    virtual void Release(void) = 0;
    virtual long Restore(void) = 0;
    virtual long IsLost(void) = 0;
    virtual long ClearSurface(class CBlitFX *_pBlitFx) = 0;
    virtual long ClearSurface(struct tagRECT a2, class CBlitFX *_pBlitFx) = 0;
    virtual long Blt(struct tagRECT *a2, class CSurface *a3, struct tagRECT *a4, unsigned long a5, struct _DDBLTFX *a6) = 0;
    virtual long Flip(void) = 0;
    virtual long Lock(unsigned int &_rPitch, void *&_rSurface, bool a4) = 0;
    virtual long Unlock(void) = 0;
    virtual long GetDC(struct HDC__ **a2) = 0;
    virtual long ReleaseDC(struct HDC__ *a2) = 0;
    virtual long CreateSurface(void *pDDInterface, int iWidth, int iHeight, bool bVideoMem, bool bHwAccess, bool bIsTexture, int iSurfaceFormat, bool bPrimary, bool a9, bool a10) = 0;
    virtual long SetColorKey(unsigned long a2, struct _DDCOLORKEY *a3) = 0;
    virtual long GetPixelFormat(bool &_rIs555) = 0;
    virtual long GetBitDepth(int &_rBitDepth) = 0;
    virtual long GetSurfaceSize(int &_rWidth, int &_rHeight) = 0;
    virtual long SetClipper(struct IDirectDrawClipper *a2) = 0;
    virtual void *GetSurfacePtr(void) = 0;
    virtual void SetSurfacePtr(void *a2) = 0;
    virtual void *GetAttachedSurfacePtr(void) = 0;
    virtual bool IsBackBufferReference(void) = 0;
    virtual long SetAsRenderTarget(struct IDirect3DDevice7 *a2) = 0;

    // address=[0x2f8a310]
    virtual ~CSurface(void);

    // Type information members
  public:
    struct IDirectDrawSurface7 *m_pSurfaceV7;
    struct IDirectDrawSurface *m_pSurfaceV3;
    char m_bBackbuffer;
};

#endif // CSURFACE_H
