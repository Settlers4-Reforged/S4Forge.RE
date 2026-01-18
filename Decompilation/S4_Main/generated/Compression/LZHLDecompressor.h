#ifndef LZHLDECOMPRESSOR_H
#define LZHLDECOMPRESSOR_H

#include "defines.h"

class LZHLDecompressor {
public:
    // address=[0x2f2b540]
     LZHLDecompressor(void);

    // address=[0x2f2b5c0]
     ~LZHLDecompressor(void);

    // address=[0x2f2b5e0]
    int  decompress(unsigned char * Src, unsigned int * a3, unsigned char const * a4, unsigned int * a5);

private:
    // address=[0x2f2c4f0]
    int  _get(unsigned char const * & a2, unsigned char const * a3, int a4);

};


#endif // LZHLDECOMPRESSOR_H
