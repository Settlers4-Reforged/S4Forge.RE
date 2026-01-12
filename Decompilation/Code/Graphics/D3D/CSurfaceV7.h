#ifndef CSURFACEV7_H
#define CSURFACEV7_H

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
    virtual long  ClearSurface(class CBlitFX *);

    // address=[0x2f86770]
    virtual long  ClearSurface(struct tagRECT,class CBlitFX *);

    // address=[0x2f86810]
    virtual long  Blt(struct tagRECT *,class CSurface *,struct tagRECT *,unsigned long,struct _DDBLTFX *);

    // address=[0x2f86870]
    virtual long  Flip(void);

    // address=[0x2f868a0]
    virtual long  Lock(unsigned int &,void * &,bool);

    // address=[0x2f86920]
    virtual long  Unlock(void);

    // address=[0x2f86950]
    virtual long  GetDC(struct HDC__ * *);

    // address=[0x2f86990]
    virtual long  ReleaseDC(struct HDC__ *);

    // address=[0x2f869c0]
    virtual long  CreateSurface(void *,int,int,bool,bool,bool,int,bool,bool,bool);

    // address=[0x2f86bf0]
    virtual long  SetColorKey(unsigned long,struct _DDCOLORKEY *);

    // address=[0x2f86c20]
    virtual long  GetPixelFormat(bool &);

    // address=[0x2f86cc0]
    virtual long  GetBitDepth(int &);

    // address=[0x2f86d20]
    virtual long  GetSurfaceSize(int &,int &);

    // address=[0x2f86d70]
    virtual long  SetClipper(struct IDirectDrawClipper *);

    // address=[0x2f86da0]
    virtual void *  GetSurfacePtr(void);

    // address=[0x2f86dc0]
    virtual void  SetSurfacePtr(void *);

    // address=[0x2f86de0]
    virtual void *  GetAttachedSurfacePtr(void);

    // address=[0x2f86e50]
    virtual bool  IsBackBufferReference(void);

    // address=[0x2f86e70]
    virtual long  SetAsRenderTarget(struct IDirect3DDevice7 *);

    // address=[0x2f8a340]
    virtual  ~CSurfaceV7(void);

};


#endif // CSURFACEV7_H
