#ifndef COMPRESSION_LZHL_H
#define COMPRESSION_LZHL_H

#include "defines.h"
#include "LZHLCompressor.h"
#include "LZHLDecompressor.h"

LZHLDecompressor *LZHLCreateDecompressor();

int LZHLDecompress(LZHLDecompressor *a1, uint8_t *_pDst, size_t *_uDstSize, const uint8_t *_pSrc, size_t *_uSrcSize);

int LZHLDestroyDecompressor(LZHLDecompressor *a1);


unsigned int __cdecl LZHLCompressorCalcMaxBuf(unsigned int a1);

LZHLCompressor *LZHLCreateCompressor();

int __cdecl LZHLCompress(int a1, int a2, void *Src, int a4);

LZHLCompressor *__cdecl LZHLDestroyCompressor(LZHLCompressor *a1);

#endif
