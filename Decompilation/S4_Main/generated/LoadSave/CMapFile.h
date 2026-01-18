#ifndef S4_CMAPFILE_H
#define S4_CMAPFILE_H

#include "defines.h"

namespace S4 {

class CMapFile {
public:
    // address=[0x13da7f0]
     CMapFile(bool a2);

    // address=[0x13da8d0]
    virtual  ~CMapFile(void);

    // address=[0x13da960]
    void  Open(std::wstring const & a2, int a3, bool a4);

    // address=[0x13dab20]
    void  Close(void);

    // address=[0x13dace0]
    void  Virtualize(void);

    // address=[0x13dad20]
    unsigned int  GetChecksum(void)const;

    // address=[0x13dad40]
    void const *  LoadChunk(unsigned int a2, unsigned int a3);

    // address=[0x13dad70]
    void const *  LoadChunk(unsigned short a2, unsigned short a3, int & a4, int * a5);

    // address=[0x13db3e0]
    void  CloseChunk(unsigned short a2, unsigned short a3);

    // address=[0x13db650]
    void  UploadBuffer(unsigned int a2, unsigned int a3, void const * Src, unsigned int Size, int a6);

    // address=[0x13db820]
    void  SaveChunk(unsigned short a2, unsigned short a3, unsigned int Size, void const * Src, bool a6);

    // address=[0x13db990]
    bool  LoadChunkObject(unsigned short a2, unsigned short a3, class IS4ChunkObject & a4, enum T_S4_MAP_CHUNK_STATUS a5);

    // address=[0x13dbaa0]
    void  SaveChunkObject(unsigned short a2, unsigned short a3, class IS4ChunkObject & a4, bool a5);

    // address=[0x13dbb60]
    void  SaveDbgInfoChunk(char const * a2);

private:
    // address=[0x13dbc20]
    void  Cryption(void * a2, unsigned int a3);

    // address=[0x13dbd00]
    unsigned int  Crc(void *,unsigned int);

    // address=[0x13dbd60]
    unsigned int  FileCRC(int a2, int a3);

};

} // namespace S4

#endif // S4_CMAPFILE_H
