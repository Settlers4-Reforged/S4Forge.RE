#ifndef CUSERLOGOCHUNK_H
#define CUSERLOGOCHUNK_H

#include "defines.h"

class CUserLogoChunk : public IS4ChunkObject {
public:
    // address=[0x140a250]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x140a470]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1486a50]
     CUserLogoChunk(void);

};


#endif // CUSERLOGOCHUNK_H
