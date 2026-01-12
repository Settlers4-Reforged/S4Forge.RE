#ifndef CSURFACEV3_H
#define CSURFACEV3_H

class CSurfaceV3 : public CSurface {
public:
    // address=[0x2f86ec0]
     CSurfaceV3(void);

    // address=[0x2f86f00]
    virtual void  Release(void);

    // address=[0x2f86f30]
    virtual long  Restore(void);

    // address=[0x2f86f50]
    virtual long  IsLost(void);

    // address=[0x2f86f70]
    virtual long  ClearSurface(class CBlitFX *);

    // address=[0x2f87010]
    virtual long  ClearSurface(struct tagRECT,class CBlitFX *);

    // address=[0x2f870b0]
    virtual long  Blt(struct tagRECT *,class CSurface *,struct tagRECT *,unsigned long,struct _DDBLTFX *);

    // address=[0x2f87110]
    virtual long  Flip(void);

    // address=[0x2f87140]
    virtual long  Lock(unsigned int &,void * &,bool);

    // address=[0x2f871b0]
    virtual long  Unlock(void);

    // address=[0x2f871e0]
    virtual long  GetDC(struct HDC__ * *);

    // address=[0x2f87220]
    virtual long  ReleaseDC(struct HDC__ *);

    // address=[0x2f87250]
    virtual long  CreateSurface(void *,int,int,bool,bool,bool,int,bool,bool,bool);

    // address=[0x2f87470]
    virtual long  SetColorKey(unsigned long,struct _DDCOLORKEY *);

    // address=[0x2f874a0]
    virtual long  GetPixelFormat(bool &);

    // address=[0x2f87560]
    virtual long  GetBitDepth(int &);

    // address=[0x2f875c0]
    virtual long  GetSurfaceSize(int &,int &);

    // address=[0x2f87610]
    virtual long  SetClipper(struct IDirectDrawClipper *);

    // address=[0x2f87640]
    virtual void *  GetSurfacePtr(void);

    // address=[0x2f87660]
    virtual void  SetSurfacePtr(void *);

    // address=[0x2f87680]
    virtual void *  GetAttachedSurfacePtr(void);

    // address=[0x2f876c0]
    virtual bool  IsBackBufferReference(void);

    // address=[0x2f876e0]
    virtual long  SetAsRenderTarget(struct IDirect3DDevice7 *);

    // address=[0x2f8a320]
    virtual  ~CSurfaceV3(void);

};


#endif // CSURFACEV3_H
