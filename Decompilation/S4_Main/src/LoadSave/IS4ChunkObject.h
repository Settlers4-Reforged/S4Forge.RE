#ifndef IS4CHUNKOBJECT_H
#define IS4CHUNKOBJECT_H

#include "defines.h"

class IS4ChunkObject {
public:
    // address=[0x1310290]
    IS4ChunkObject(void) = default;

    // address=[0x14600c0]
    IS4ChunkObject(class IS4ChunkObject const & a2) = default;

    // address=[0x1486c50]
    class IS4ChunkObject &  operator=(class IS4ChunkObject const & a2) = default;

    virtual void Load(class IS4Chunk &) = 0;
    virtual void Save(class IS4Chunk &) = 0;
};


#endif // IS4CHUNKOBJECT_H
