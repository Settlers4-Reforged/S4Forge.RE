#ifndef LZHLCOMPRESSOR_H
#define LZHLCOMPRESSOR_H

#include "defines.h"

class LZHLCompressor {
public:
    // address=[0x2f02850]
    static unsigned int __cdecl calcMaxBuf(unsigned int a1);

    // address=[0x2f29650]
     LZHLCompressor(void);

    // address=[0x2f29710]
     ~LZHLCompressor(void);

    // address=[0x2f29750]
    unsigned int  compress(unsigned char * a2, unsigned char const * Src, unsigned int a4);

private:
    // address=[0x2f2a790]
    unsigned long  _updateTable(unsigned long a2, unsigned char const * a3, unsigned long a4, int a5);

};


#endif // LZHLCOMPRESSOR_H
