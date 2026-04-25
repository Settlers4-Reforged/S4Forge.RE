#include "SMapChunkHeader.h"
#include "Compression/LZHL.h"

bool __cdecl ReadChunk(void *Src, int _iSize, int _iCompressedSize) {
    uint8_t *pCompressionBuffer; // eax
    uint8_t *v5; // [esp+4h] [ebp-24h]
    uint8_t *v6; // [esp+8h] [ebp-20h]
    int      v7; // [esp+14h] [ebp-14h]

    char *v9; // [esp+24h] [ebp-4h]

    if(_iCompressedSize == -1)
        return 1;
    if(_iSize <= _iCompressedSize)
        pCompressionBuffer = new uint8_t[_iCompressedSize];
    else
        pCompressionBuffer = new uint8_t[_iSize];
 if(_iSize <= _iCompressedSize)
        memcpy(pCompressionBuffer, Src, _iCompressedSize);
    else
        memcpy(pCompressionBuffer, Src, _iSize);
    auto pCompressor = LZHLCreateDecompressor();
    v5 = &static_cast<uint8_t *>(Src)[_iCompressedSize];
    v6 = &pCompressionBuffer[_iSize];
    do {
        size_t iCompressedSize = _iCompressedSize;
        size_t iSize = _iSize;
        v7 = LZHLDecompress(pCompressor, &v5[-_iCompressedSize], &iCompressedSize, &v6[-_iSize], &iSize);
    } while(_iSize && v7);

    LZHLDestroyDecompressor(pCompressor);
    delete[] pCompressionBuffer;

    return v7 != 0;
}
