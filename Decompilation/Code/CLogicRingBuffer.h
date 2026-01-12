#ifndef CLOGICRINGBUFFER_H
#define CLOGICRINGBUFFER_H

class CLogicRingBuffer : public ?$CRingBuffer@VCEvn_Logic@@, public IS4ChunkObject {
public:
    // address=[0x1486a00]
     CLogicRingBuffer(int);

    // address=[0x1486b10]
    virtual  ~CLogicRingBuffer(void);

    // address=[0x14870b0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x14872e0]
    virtual void  Save(class IS4Chunk &);

};


#endif // CLOGICRINGBUFFER_H
