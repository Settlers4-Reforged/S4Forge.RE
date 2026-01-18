#ifndef CFILELIBRARY_H
#define CFILELIBRARY_H

#include "defines.h"

class CFileLibrary {
public:
    // address=[0x2f099d0]
    unsigned int  FileSize(wchar_t const * String);

    // address=[0x2f09ae0]
    unsigned int  FileSize(unsigned int a2);

    // address=[0x2f09b40]
    void  UnmapFile(void * a2);

    // address=[0x2f09c70]
    bool  DoesFileExistInLib(wchar_t const * String);

    // address=[0x2f09d30]
    void *  MapFile(unsigned int a2);

    // address=[0x2f09ef0]
    unsigned int  FileOpen(wchar_t const * String, int Size);

    // address=[0x2f0a220]
    void  FileClose(unsigned int a2);

    // address=[0x2f0a2e0]
    unsigned int  FileSeek(unsigned int a2, long a3, int a4);

    // address=[0x2f0a420]
    unsigned int  FileRead(unsigned int a2, void * lpBuffer, unsigned int Size);

    // address=[0x2f0a9d0]
    int  AddFileLibrary(wchar_t const * lpFileName, int a3);

    // address=[0x2f0b6c0]
    class std::vector<struct std::pair<std::wstring,std::wstring >,class std::allocator<struct std::pair<std::wstring,std::wstring > > >  ListFilesInLib(wchar_t const * a2);

    // address=[0x2f0b8c0]
    void  DumpFilesInLib(wchar_t const * a2, wchar_t const * String);

    // address=[0x2f0bd30]
    void  InitFileLibraries(void);

    // address=[0x2f0bd50]
    void  C_Init(void);

    // address=[0x2f0bd70]
    void  C_AddPath(wchar_t const * String, int a3, wchar_t const * Source, wchar_t const * a5);

    // address=[0x2f0bfc0]
    int  C_CreateFileLibrary(wchar_t const * lpFileName, char * a3, int a4, int nNumberOfBytesToRead);

    // address=[0x2f0d650]
     CFileLibrary(int a2);

    // address=[0x2f0d880]
     ~CFileLibrary(void);

private:
    // address=[0x2f08050]
    bool  pCutPathAndFilename(wchar_t const * String, wchar_t * Destination, wchar_t * a3);

    // address=[0x2f08230]
    void *  pGetFileLibraryHandle(int a2);

    // address=[0x2f08480]
    int  pC_CopyFile(wchar_t const * lpFileName, void * a2, int nNumberOfBytesToRead, struct FLCopyProgressStruct * a4);

    // address=[0x2f08690]
    int  pC_PackFile(void * a2, void * hFile, unsigned int * a4, bool a5);

    // address=[0x2f087f0]
    int  UnpackData(char * a2, int a3, char * a4, int a5, bool a6);

    // address=[0x2f08fb0]
    void  pFreeFLCreationData(void);

    // address=[0x2f090a0]
    void  pFreeFLData(void);

    // address=[0x2f09350]
    void  pOptimize(void);

    // address=[0x2f095f0]
    int  LoadEntireFile(unsigned int a2, void * a3, unsigned int a4, int a5);

    // address=[0x2f09890]
    static void __cdecl DataCryptor(void * a1, int a2);

    // address=[0x2f09950]
    unsigned int  CRC(void * a2, int a3);

};


#endif // CFILELIBRARY_H
