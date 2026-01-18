#ifndef CRTCOMP_H
#define CRTCOMP_H

#include "defines.h"

class CRTComp : public IRTComp {
public:
    // address=[0x2fcd4a0]
     CRTComp(void);

    // address=[0x2fcd4e0]
     ~CRTComp(void);

    // address=[0x2fcd540]
    virtual enum RTCOMP_ERROR  SetWorkPath(wchar_t * String);

    // address=[0x2fcd650]
    virtual enum RTCOMP_ERROR  SetPlayerColors(struct SCOLOR * const a2);

    // address=[0x2fcd6a0]
    virtual enum RTCOMP_ERROR  Compile(int a2);

    // address=[0x2fceeb0]
    virtual wchar_t *  GetErrorFileName(void);

    // address=[0x2fceed0]
    virtual bool  GetPictureInfos(wchar_t * FileName, int & a2, int & a3, int & a4);

private:
    // address=[0x2fcefd0]
    wchar_t *  CreateCurFilename(int a2);

    // address=[0x2fcf010]
    void  DeleteCurFilename(wchar_t * a2);

    // address=[0x2fcf040]
    void  SetErrorFilename(wchar_t * String);

    // address=[0x2fcf0d0]
    enum RTCOMP_ERROR  LoadPng(wchar_t * FileName, struct SM_S_BF_BITMAP_DATA * a3);

    // address=[0x2fcf5a0]
    void  Decompose24(struct SM_S_BF_BITMAP_DATA * a2, unsigned char * a3);

    // address=[0x2fcf660]
    void  Decompose8(struct SM_S_BF_BITMAP_DATA * a2, unsigned char * a3, char * a4);

    // address=[0x2fcf730]
    void  DestroyContent(struct SM_S_BF_BITMAP_DATA * a2);

    // address=[0x2fcf780]
    void  CreateBoundingBox(struct SM_S_BF_BITMAP_DATA * a2);

    // address=[0x2fcf8e0]
    void  CreateColorField(unsigned char * * const a1, int Size);

    // address=[0x2fcf940]
    void  DestroyColorField(unsigned char * * const a2);

    // address=[0x2fcf990]
    void  ConvertTo555(unsigned char * * const a2, int a3);

    // address=[0x2fcfad0]
    void  PutBitmapColorKeyToFront(unsigned char * a2, unsigned int a3, unsigned char a4);

    // address=[0x2fcfb70]
    int  PutColorMapColorKeyToFront(unsigned char * * const a2);

    // address=[0x2fcfe70]
    void  FreeColormapShadowColor(unsigned char * * const a2);

    // address=[0x2fcffb0]
    void  FreeBitmapShadowColor(unsigned char * a2, unsigned int a3);

    // address=[0x2fd0000]
    void  FreeColormapPlayerColor(unsigned char * * const a2);

    // address=[0x2fd0140]
    void  FreeBitmapPlayerColor(unsigned char * a2, unsigned int a3);

    // address=[0x2fd01a0]
    void  CenterBitmap(struct SM_S_BF_BITMAP_DATA * a2);

    // address=[0x2fd0300]
    void  CreateMagBorder(struct SM_S_BF_BITMAP_DATA * a2);

    // address=[0x2fd03d0]
    void  AddPlayerColor(struct SM_S_BF_BITMAP_DATA * a2);

    // address=[0x2fd06d0]
    unsigned char *  MakePanel(struct SM_S_BF_BITMAP_DATA * a1, bool a2);

    // address=[0x2fd0870]
    void  HalfColorMap(unsigned char * * const a1);

    // address=[0x2fd08f0]
    int  EncodeImage(unsigned char * a2, unsigned char * a3, int a4, int a5);

    // address=[0x2fd0b30]
    void  Save8Bitmap(unsigned int ElementCount, unsigned int a2, unsigned char * a3, unsigned char * * const a4);

};


#endif // CRTCOMP_H
