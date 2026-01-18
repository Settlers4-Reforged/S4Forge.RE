#ifndef BB_SIV_CHUNKHEADER_H
#define BB_SIV_CHUNKHEADER_H

#include "defines.h"

class BB_SIV_ChunkHeader {
public:
    // address=[0x2fd2960]
     BB_SIV_ChunkHeader(void);

    // address=[0x2fd2980]
    bool  Load(struct _iobuf * Stream);

    // address=[0x2fd29c0]
    bool  Save(struct _iobuf * Stream);

};


#endif // BB_SIV_CHUNKHEADER_H
