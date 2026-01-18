#ifndef CFILEEX_H
#define CFILEEX_H

#include "defines.h"

class CFileEx : public CFile, public IFileEx {
public:
    // address=[0x135cb10]
     CFileEx(void a2);

    // address=[0x135d430]
    virtual  ~CFileEx(void);

    // address=[0x1496960]
    bool  InLibrary(void)const;

    // address=[0x2f01710]
     CFileEx(std::wstring const & a2, unsigned int a3, bool a4);

    // address=[0x2f017f0]
     CFileEx(wchar_t const * FileName, unsigned int a3, bool a4);

    // address=[0x2f01900]
    virtual void  Open(std::wstring const & a2, unsigned int a3, bool a4, char * a5, int a6);

    // address=[0x2f01950]
    virtual void  Open(wchar_t const * FileName, unsigned int a3, bool a4, char * Str, int a6);

    // address=[0x2f01ad0]
    virtual int  MapFile(wchar_t const * lpFileName, char * a3, int a4);

    // address=[0x2f01d30]
    virtual void *  GetMapFilePtr(void);

    // address=[0x2f01d50]
    virtual unsigned int  Read(void * Buffer, int ElementSize, int ElementCount, char * a5, int a6);

    // address=[0x2f01ef0]
    virtual unsigned int  Write(void const * Buffer, int ElementSize, int ElementCount, char * a5, int a6);

    // address=[0x2f01f40]
    virtual int  Seek(int Offset, int Origin, char * a4, int a5);

    // address=[0x2f02120]
    virtual int  Size(void)const;

    // address=[0x2f02160]
    virtual int  Close(char * a2, int a3);

    // address=[0x2f02220]
    virtual void  Release(void);

};


#endif // CFILEEX_H
