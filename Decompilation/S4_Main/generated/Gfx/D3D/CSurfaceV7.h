#ifndef CSURFACEV7_H
#define CSURFACEV7_H

#include "defines.h"

class CSurfaceV7 : public CSurface {
public:
    // address=[0x2f86620]
     CSurfaceV7(void);

    // address=[0x2f86660]
    virtual void  Release(void);

    // address=[0x2f86690]
    virtual long  Restore(void);

    // address=[0x2f866b0]
    virtual long  IsLost(void);

    // address=[0x2f866d0]
    virtual long  ClearSurface(class CBlitFX * a2);

    // address=[0x2f86770]
    virtual long  ClearSurface(struct tagRECT a2, class CBlitFX * a3);

    // address=[0x2f86810]
    virtual long  Blt(struct tagRECT * a2, class CSurface * a3, struct tagRECT * a4, unsigned long a5, struct _DDBLTFX * a6);

    // address=[0x2f86870]
    virtual long  Flip(void);

    // address=[0x2f868a0]
    virtual long  Lock(unsigned int & a2, void * & a3, bool a4);

    // address=[0x2f86920]
    virtual long  Unlock(void);

    // address=[0x2f86950]
    virtual long  GetDC(struct HDC__ * * a2);

    // address=[0x2f86990]
    virtual long  ReleaseDC(struct HDC__ * a2);

    // address=[0x2f869c0]
    virtual long  CreateSurface(void * a2, int a3, int a4, bool a5, bool a6, bool a7, int a8, bool a9, bool a10, bool a11);

    // address=[0x2f86bf0]
    virtual long  SetColorKey(unsigned long a2, struct _DDCOLORKEY * a3);

    // address=[0x2f86c20]
    virtual long  GetPixelFormat(bool & a2);

    // address=[0x2f86cc0]
    virtual long  GetBitDepth(int & a2);

    // address=[0x2f86d20]
    virtual long  GetSurfaceSize(int & a2, int & a3);

    // address=[0x2f86d70]
    virtual long  SetClipper(struct IDirectDrawClipper * a2);

    // address=[0x2f86da0]
    virtual void *  GetSurfacePtr(void);

    // address=[0x2f86dc0]
    virtual void  SetSurfacePtr(void * a2);

    // address=[0x2f86de0]
    virtual void *  GetAttachedSurfacePtr(void);

    // address=[0x2f86e50]
    virtual bool  IsBackBufferReference(void);

    // address=[0x2f86e70]
    virtual long  SetAsRenderTarget(struct IDirect3DDevice7 * a2);

    // address=[0x2f8a340]
    virtual  ~CSurfaceV7(void);

    // Type information members
private:
    LPDIRECTDRAWSURFACE7 innerSurface;
    int field_8;
    char field_C;

};


#endif // CSURFACEV7_H
