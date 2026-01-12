#ifndef LZHLENCODER_H
#define LZHLENCODER_H

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
    void  putRaw(unsigned char const *,unsigned int);

    // address=[0x2f2b180]
    void  putMatch(unsigned char const *,unsigned int,unsigned int,unsigned int);

private:
    // address=[0x2f2b3a0]
    void  _callStat(void);

    // address=[0x2f2c620]
    void  _put(unsigned short);

    // address=[0x2f2c730]
    void  _put(unsigned short,int,unsigned long);

    // address=[0x2f2c880]
    void  _putBits(int,unsigned long);

};


#endif // LZHLENCODER_H
