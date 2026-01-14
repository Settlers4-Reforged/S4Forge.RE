#ifndef CBLITFX_H
#define CBLITFX_H

class CBlitFX {
public:
    // address=[0x2f69900]
    struct _DDBLTFX *  GetBlitStructPtr(void);

    // address=[0x2f86400]
     CBlitFX(void);

    // address=[0x2f86430]
    void  SetFillColor(int,int,int,bool);

    // address=[0x2f864e0]
    void  SetFillColorAlpha(int,int,int,int);

};


#endif // CBLITFX_H
