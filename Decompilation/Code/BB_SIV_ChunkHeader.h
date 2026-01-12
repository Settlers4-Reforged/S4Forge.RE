#ifndef BB_SIV_CHUNKHEADER_H
#define BB_SIV_CHUNKHEADER_H

class BB_SIV_ChunkHeader {
public:
    // address=[0x2fd2960]
     BB_SIV_ChunkHeader(void);

    // address=[0x2fd2980]
    bool  Load(struct _iobuf *);

    // address=[0x2fd29c0]
    bool  Save(struct _iobuf *);

};


#endif // BB_SIV_CHUNKHEADER_H
