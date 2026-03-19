#ifndef IS4CHUNK_H
#define IS4CHUNK_H

#include "defines.h"

class IS4Chunk {
public:
    // address=[0x13ed720]
    IS4Chunk(void) = default;

    virtual void Load(void *_pTarget, unsigned int _uSize) = 0;

    virtual unsigned int LoadUnsigned32(void) = 0;

    virtual unsigned int LoadUnsigned32(unsigned int _uMin, unsigned int _uMax) = 0;

    virtual void LoadSignature(unsigned int _uSignature) = 0;

    virtual void Save(void const *_pData, unsigned int a3) = 0;

    virtual void SaveUnsigned32(unsigned int _uValue) = 0;

    virtual void SaveSignature(unsigned int _uSignature) = 0;
};

#endif // IS4CHUNK_H
