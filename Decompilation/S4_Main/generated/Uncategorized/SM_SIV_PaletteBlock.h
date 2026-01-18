#ifndef SM_SIV_PALETTEBLOCK_H
#define SM_SIV_PALETTEBLOCK_H

#include "defines.h"

class SM_SIV_PaletteBlock {
public:
    // address=[0x2fd2a20]
     SM_SIV_PaletteBlock(int a2, bool a3);

    // address=[0x2fd2a60]
     ~SM_SIV_PaletteBlock(void);

    // address=[0x2fd2a70]
    int  FillPalette(enum SM_SIV_PALETTETYPE a2, unsigned char * * const a3, unsigned char a4, unsigned short a5);

    // address=[0x2fd30f0]
    unsigned int  Save(struct _iobuf * a2, struct _iobuf * Stream, unsigned int Buffer, bool a5, bool a6);

    // address=[0x2fd33c0]
    static unsigned short __cdecl Convert4444(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, float a5);

    // address=[0x2fd34a0]
    static unsigned short __cdecl Convert555(unsigned int a1, unsigned int a2, unsigned int a3, float a4);

    // address=[0x2fd3570]
    static unsigned short __cdecl Convert565(unsigned int a1, unsigned int a2, unsigned int a3, float a4);

};


#endif // SM_SIV_PALETTEBLOCK_H
