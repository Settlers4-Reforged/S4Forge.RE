#ifndef CFILELIBRARY_H
#define CFILELIBRARY_H

class CFileLibrary {
public:
    // address=[0x2f099d0]
    unsigned int  FileSize(wchar_t const *);

    // address=[0x2f09ae0]
    unsigned int  FileSize(unsigned int);

    // address=[0x2f09b40]
    void  UnmapFile(void *);

    // address=[0x2f09c70]
    bool  DoesFileExistInLib(wchar_t const *);

    // address=[0x2f09d30]
    void *  MapFile(unsigned int);

    // address=[0x2f09ef0]
    unsigned int  FileOpen(wchar_t const *,int);

    // address=[0x2f0a220]
    void  FileClose(unsigned int);

    // address=[0x2f0a2e0]
    unsigned int  FileSeek(unsigned int,long,int);

    // address=[0x2f0a420]
    unsigned int  FileRead(unsigned int,void *,unsigned int);

    // address=[0x2f0a9d0]
    int  AddFileLibrary(wchar_t const *,int);

    // address=[0x2f0b6c0]
    class std::vector<struct std::pair<std::wstring,std::wstring >,class std::allocator<struct std::pair<std::wstring,std::wstring > > >  ListFilesInLib(wchar_t const *);

    // address=[0x2f0b8c0]
    void  DumpFilesInLib(wchar_t const *,wchar_t const *);

    // address=[0x2f0bd30]
    void  InitFileLibraries(void);

    // address=[0x2f0bd50]
    void  C_Init(void);

    // address=[0x2f0bd70]
    void  C_AddPath(wchar_t const *,int,wchar_t const *,wchar_t const *);

    // address=[0x2f0bfc0]
    int  C_CreateFileLibrary(wchar_t const *,char *,int,int);

    // address=[0x2f0d650]
     CFileLibrary(int);

    // address=[0x2f0d880]
     ~CFileLibrary(void);

private:
    // address=[0x2f08050]
    bool  pCutPathAndFilename(wchar_t const *,wchar_t *,wchar_t *);

    // address=[0x2f08230]
    void *  pGetFileLibraryHandle(int);

    // address=[0x2f08480]
    int  pC_CopyFile(wchar_t const *,void *,int,struct FLCopyProgressStruct *);

    // address=[0x2f08690]
    int  pC_PackFile(void *,void *,unsigned int *,bool);

    // address=[0x2f087f0]
    int  UnpackData(char *,int,char *,int,bool);

    // address=[0x2f08fb0]
    void  pFreeFLCreationData(void);

    // address=[0x2f090a0]
    void  pFreeFLData(void);

    // address=[0x2f09350]
    void  pOptimize(void);

    // address=[0x2f095f0]
    int  LoadEntireFile(unsigned int,void *,unsigned int,int);

    // address=[0x2f09890]
    static void __cdecl DataCryptor(void *,int);

    // address=[0x2f09950]
    unsigned int  CRC(void *,int);

};


#endif // CFILELIBRARY_H
