#ifndef IS4CHUNK_H
#define IS4CHUNK_H

#include "defines.h"

class IS4Chunk
{
public:
    // address=[0x13ed720]
    IS4Chunk(void) = default;

    virtual void Load(void *a2, unsigned int Size) = 0;
    virtual unsigned int LoadUnsigned32(void) = 0;
    virtual unsigned int LoadUnsigned32(unsigned int a2, unsigned int a3) = 0;
    virtual void LoadSignature(unsigned int a2) = 0;
    virtual void Save(void const *a2, unsigned int a3) = 0;
    virtual void SaveUnsigned32(unsigned int a2) = 0;
    virtual void SaveSignature(unsigned int a2) = 0;
};

#endif // IS4CHUNK_H
