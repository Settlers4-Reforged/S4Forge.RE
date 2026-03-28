// modified by Luigi Auriemma
#include "LZHL.h"

LZHLDecompressor *LZHLCreateDecompressor() {
    return new LZHLDecompressor();
}

int LZHLDecompress(LZHLDecompressor *a1, uint8_t *_pDst, size_t *_uDstSize, const uint8_t *_pSrc, size_t *_uSrcSize) {
    a1->decompress(_pDst, _uDstSize, _pSrc, _uSrcSize);
}

int LZHLDestroyDecompressor(LZHLDecompressor *a1) {
    delete a1;
}

unsigned int __cdecl LZHLCompressorCalcMaxBuf(unsigned int a1) {
    return LZHLCompressor::calcMaxBuf(a1);
}

LZHLCompressor *LZHLCreateCompressor() {
    return new LZHLCompressor();
}

int __cdecl LZHLCompress(LZHLCompressor *a1, uint8_t *dst, const uint8_t *src, size_t srcSz) {
    return a1->compress(dst, src, srcSz);
}

LZHLCompressor * __cdecl LZHLDestroyCompressor(LZHLCompressor *a1) {
    delete a1;
}
