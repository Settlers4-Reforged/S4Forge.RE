#ifndef SM_SIV_PALETTEBLOCK_H
#define SM_SIV_PALETTEBLOCK_H

class SM_SIV_PaletteBlock {
public:
    // address=[0x2fd2a20]
     SM_SIV_PaletteBlock(int,bool);

    // address=[0x2fd2a60]
     ~SM_SIV_PaletteBlock(void);

    // address=[0x2fd2a70]
    int  FillPalette(enum SM_SIV_PALETTETYPE,unsigned char * * const,unsigned char,unsigned short);

    // address=[0x2fd30f0]
    unsigned int  Save(struct _iobuf *,struct _iobuf *,unsigned int,bool,bool);

    // address=[0x2fd33c0]
    static unsigned short __cdecl Convert4444(unsigned int,unsigned int,unsigned int,unsigned int,float);

    // address=[0x2fd34a0]
    static unsigned short __cdecl Convert555(unsigned int,unsigned int,unsigned int,float);

    // address=[0x2fd3570]
    static unsigned short __cdecl Convert565(unsigned int,unsigned int,unsigned int,float);

};


#endif // SM_SIV_PALETTEBLOCK_H
