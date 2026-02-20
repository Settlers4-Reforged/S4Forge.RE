#ifndef IFILEEX_H
#define IFILEEX_H

#include "defines.h"

class IFileEx
{ //: public IFile {
public:
    // address=[0x135cc20]
    IFileEx(void);

    virtual ~IFileEx(void) = 0;

    virtual void Open(std::wstring const &a2, unsigned int a3, bool a4, char *a5, int a6) = 0;

    virtual void Open(wchar_t const *FileName, unsigned int _uFileMask, bool a4, char *Str, int a6) = 0;
    
    virtual int MapFile(wchar_t const *lpFileName, char *a3, int a4) = 0;

    virtual void *GetMapFilePtr(void) = 0;

    virtual unsigned int Read(void *Buffer, int ElementSize, int ElementCount, char *a5, int a6) = 0;

    virtual unsigned int Write(void const *Buffer, int ElementSize, int ElementCount, char *a5, int a6) = 0;

    virtual int Seek(int Offset, int Origin, char *a4, int a5) = 0;

    virtual int Size(void) const = 0;

    virtual int Close(char *a2, int a3) = 0;

    virtual void Release(void) = 0;
};

#endif // IFILEEX_H
