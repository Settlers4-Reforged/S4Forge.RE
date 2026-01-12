#ifndef S4_CMAPFILE_H
#define S4_CMAPFILE_H

namespace S4 {

class CMapFile {
public:
    // address=[0x13da7f0]
     CMapFile(bool);

    // address=[0x13da8d0]
    virtual  ~CMapFile(void);

    // address=[0x13da960]
    void  Open(std::wstring const &,int,bool);

    // address=[0x13dab20]
    void  Close(void);

    // address=[0x13dace0]
    void  Virtualize(void);

    // address=[0x13dad20]
    unsigned int  GetChecksum(void)const;

    // address=[0x13dad40]
    void const *  LoadChunk(unsigned int,unsigned int);

    // address=[0x13dad70]
    void const *  LoadChunk(unsigned short,unsigned short,int &,int *);

    // address=[0x13db3e0]
    void  CloseChunk(unsigned short,unsigned short);

    // address=[0x13db650]
    void  UploadBuffer(unsigned int,unsigned int,void const *,unsigned int,int);

    // address=[0x13db820]
    void  SaveChunk(unsigned short,unsigned short,unsigned int,void const *,bool);

    // address=[0x13db990]
    bool  LoadChunkObject(unsigned short,unsigned short,class IS4ChunkObject &,enum T_S4_MAP_CHUNK_STATUS);

    // address=[0x13dbaa0]
    void  SaveChunkObject(unsigned short,unsigned short,class IS4ChunkObject &,bool);

    // address=[0x13dbb60]
    void  SaveDbgInfoChunk(char const *);

private:
    // address=[0x13dbc20]
    void  Cryption(void *,unsigned int);

    // address=[0x13dbd00]
    unsigned int  Crc(void *,unsigned int);

    // address=[0x13dbd60]
    unsigned int  FileCRC(int,int);

};

} // namespace S4

#endif // S4_CMAPFILE_H
