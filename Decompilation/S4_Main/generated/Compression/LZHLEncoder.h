#ifndef LZHLENCODER_H
#define LZHLENCODER_H

#include "defines.h"

class LZHLEncoder {
public:
    // address=[0x2f02870]
    static unsigned int __cdecl calcMaxBuf(unsigned int);

    // address=[0x2f2a390]
     LZHLEncoder(class LZHLEncoderStat *,unsigned char *);

    // address=[0x2f2a430]
     ~LZHLEncoder(void);

    // address=[0x2f2b0d0]
    unsigned int  flush(void);

    // address=[0x2f2b140]
    void  putRaw(unsigned char const * a2, unsigned int a3);

    // address=[0x2f2b180]
    void  putMatch(unsigned char const * a2, unsigned int a3, unsigned int a4, unsigned int a5);

private:
    // address=[0x2f2b3a0]
    void  _callStat(void);

    // address=[0x2f2c620]
    void  _put(unsigned short a2);

    // address=[0x2f2c730]
    void  _put(unsigned short a2, int a3, unsigned long a4);

    // address=[0x2f2c880]
    void  _putBits(int a2, unsigned long a3);

};


#endif // LZHLENCODER_H
