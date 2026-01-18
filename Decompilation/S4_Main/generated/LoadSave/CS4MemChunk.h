#ifndef CS4MEMCHUNK_H
#define CS4MEMCHUNK_H

#include "defines.h"

class CS4MemChunk : public IS4Chunk {
public:
    // address=[0x13e6540]
    void const *  Data(void)const;

    // address=[0x13e6890]
    unsigned int  Size(void)const;

    // address=[0x13eca00]
     CS4MemChunk(void);

    // address=[0x13eca60]
     ~CS4MemChunk(void);

    // address=[0x13ecab0]
    void  InitLoadData(void const * chunkData, unsigned int chunkSize);

    // address=[0x13ecb70]
    void  InitSaveCalcSize(void);

    // address=[0x13ecbe0]
    void  InitSaveData(bool a2);

    // address=[0x13ecc80]
    void  Done(void);

    // address=[0x13ecd00]
    virtual void  Load(void * a2, unsigned int Size);

    // address=[0x13ece20]
    virtual unsigned int  LoadUnsigned32(void);

    // address=[0x13ece40]
    virtual unsigned int  LoadUnsigned32(unsigned int a2, unsigned int a3);

    // address=[0x13ecee0]
    virtual void  LoadSignature(unsigned int a2);

    // address=[0x13ecf40]
    virtual void  Save(void const * a2, unsigned int a3);

    // address=[0x13ecf60]
    virtual void  SaveUnsigned32(unsigned int a2);

    // address=[0x13ecf80]
    virtual void  SaveSignature(unsigned int a2);

    // address=[0x13ecfa0]
    unsigned int  Adler32(unsigned int a2);

    // address=[0x13ecfd0]
    static void __cdecl ObjectLoad(class IS4ChunkObject & a1, void const * a2, unsigned int a3);

    // address=[0x13ed050]
    static void __cdecl ObjectSave(class IS4ChunkObject & a1, void * * a2, unsigned int * a3);

protected:
    // address=[0x13ed0f0]
    void __fastcall SaveFuncNOP(void const * a1, unsigned int a2);

    // address=[0x13ed130]
    void __fastcall SaveFuncCalcSize(void const * a2, unsigned int a3);

    // address=[0x13ed1d0]
    void __fastcall SaveFuncSaveData(void const * a1, unsigned int a2);

    // address=[0x13ed310]
    void __fastcall SaveUnsigned32NOP(unsigned int);

    // address=[0x13ed340]
    void __fastcall SaveUnsigned32CalcSize(unsigned int);

    // address=[0x13ed390]
    void __fastcall SaveUnsigned32SaveData(unsigned int a2);

    // address=[0x13ed740]
    unsigned int  LoadUnsigned32Inline(void);

};


#endif // CS4MEMCHUNK_H
