#ifndef LZHLCOMPRESSOR_H
#define LZHLCOMPRESSOR_H

class LZHLCompressor {
public:
    // address=[0x2f02850]
    static unsigned int __cdecl calcMaxBuf(unsigned int);

    // address=[0x2f29650]
     LZHLCompressor(void);

    // address=[0x2f29710]
     ~LZHLCompressor(void);

    // address=[0x2f29750]
    unsigned int  compress(unsigned char *,unsigned char const *,unsigned int);

private:
    // address=[0x2f2a790]
    unsigned long  _updateTable(unsigned long,unsigned char const *,unsigned long,int);

};


#endif // LZHLCOMPRESSOR_H
