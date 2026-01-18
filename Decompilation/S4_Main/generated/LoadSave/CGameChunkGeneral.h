#ifndef CGAMECHUNKGENERAL_H
#define CGAMECHUNKGENERAL_H

#include "defines.h"

class CGameChunkGeneral : public IS4ChunkObject {
public:
    // address=[0x13eb8a0]
     CGameChunkGeneral(void);

    // address=[0x13eb9f0]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x13ec060]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x13ec470]
    void  GenerateCRC(void);

};


#endif // CGAMECHUNKGENERAL_H
