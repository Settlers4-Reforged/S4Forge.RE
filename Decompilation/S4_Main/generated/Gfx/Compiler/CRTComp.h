#ifndef CRTCOMP_H
#define CRTCOMP_H

class CRTComp : public IRTComp {
public:
    // address=[0x2fcd4a0]
     CRTComp(void);

    // address=[0x2fcd4e0]
     ~CRTComp(void);

    // address=[0x2fcd540]
    virtual enum RTCOMP_ERROR  SetWorkPath(wchar_t *);

    // address=[0x2fcd650]
    virtual enum RTCOMP_ERROR  SetPlayerColors(struct SCOLOR * const);

    // address=[0x2fcd6a0]
    virtual enum RTCOMP_ERROR  Compile(int);

    // address=[0x2fceeb0]
    virtual wchar_t *  GetErrorFileName(void);

    // address=[0x2fceed0]
    virtual bool  GetPictureInfos(wchar_t *,int &,int &,int &);

private:
    // address=[0x2fcefd0]
    wchar_t *  CreateCurFilename(int);

    // address=[0x2fcf010]
    void  DeleteCurFilename(wchar_t *);

    // address=[0x2fcf040]
    void  SetErrorFilename(wchar_t *);

    // address=[0x2fcf0d0]
    enum RTCOMP_ERROR  LoadPng(wchar_t *,struct SM_S_BF_BITMAP_DATA *);

    // address=[0x2fcf5a0]
    void  Decompose24(struct SM_S_BF_BITMAP_DATA *,unsigned char *);

    // address=[0x2fcf660]
    void  Decompose8(struct SM_S_BF_BITMAP_DATA *,unsigned char *,char *);

    // address=[0x2fcf730]
    void  DestroyContent(struct SM_S_BF_BITMAP_DATA *);

    // address=[0x2fcf780]
    void  CreateBoundingBox(struct SM_S_BF_BITMAP_DATA *);

    // address=[0x2fcf8e0]
    void  CreateColorField(unsigned char * * const,int);

    // address=[0x2fcf940]
    void  DestroyColorField(unsigned char * * const);

    // address=[0x2fcf990]
    void  ConvertTo555(unsigned char * * const,int);

    // address=[0x2fcfad0]
    void  PutBitmapColorKeyToFront(unsigned char *,unsigned int,unsigned char);

    // address=[0x2fcfb70]
    int  PutColorMapColorKeyToFront(unsigned char * * const);

    // address=[0x2fcfe70]
    void  FreeColormapShadowColor(unsigned char * * const);

    // address=[0x2fcffb0]
    void  FreeBitmapShadowColor(unsigned char *,unsigned int);

    // address=[0x2fd0000]
    void  FreeColormapPlayerColor(unsigned char * * const);

    // address=[0x2fd0140]
    void  FreeBitmapPlayerColor(unsigned char *,unsigned int);

    // address=[0x2fd01a0]
    void  CenterBitmap(struct SM_S_BF_BITMAP_DATA *);

    // address=[0x2fd0300]
    void  CreateMagBorder(struct SM_S_BF_BITMAP_DATA *);

    // address=[0x2fd03d0]
    void  AddPlayerColor(struct SM_S_BF_BITMAP_DATA *);

    // address=[0x2fd06d0]
    unsigned char *  MakePanel(struct SM_S_BF_BITMAP_DATA *,bool);

    // address=[0x2fd0870]
    void  HalfColorMap(unsigned char * * const);

    // address=[0x2fd08f0]
    int  EncodeImage(unsigned char *,unsigned char *,int,int);

    // address=[0x2fd0b30]
    void  Save8Bitmap(unsigned int,unsigned int,unsigned char *,unsigned char * * const);

};


#endif // CRTCOMP_H
