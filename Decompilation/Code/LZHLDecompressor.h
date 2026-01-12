#ifndef LZHLDECOMPRESSOR_H
#define LZHLDECOMPRESSOR_H

class LZHLDecompressor {
public:
    // address=[0x2f2b540]
     LZHLDecompressor(void);

    // address=[0x2f2b5c0]
     ~LZHLDecompressor(void);

    // address=[0x2f2b5e0]
    int  decompress(unsigned char *,unsigned int *,unsigned char const *,unsigned int *);

private:
    // address=[0x2f2c4f0]
    int  _get(unsigned char const * &,unsigned char const *,int);

};


#endif // LZHLDECOMPRESSOR_H
