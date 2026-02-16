#ifndef CFILE_H
#define CFILE_H

#include "defines.h"
#include "windows.h"

#include "IFSNode.h"

// Empty macro for CFile last two arguments. In the default output, they write about the CFile function and line number. This is just logging and also adds a lot of noise - skipping for now...
#define CFileLog (char *)"", 0
#define CFileLogAttributes char *XXX, int YYY
#define CFileLogFwd XXX, YYY

class CFile : public IFSNode
{
public:
    // address=[0x135ca40]
    CFile(void);

    // address=[0x135d3a0]
    virtual ~CFile(void);

    // address=[0x135df00]
    virtual void Accept(class IFSVisitor &a2);

    // address=[0x135dff0]
    virtual std::string const &GetName(void);

    // address=[0x2f01020]
    CFile(std::wstring const &a2, unsigned int a3);

    // address=[0x2f010d0]
    CFile(wchar_t const *FileName, unsigned int a3);

    // address=[0x2f011c0]
    void Open(std::wstring const &a2, unsigned int a3, char *Str, int a5);

    // address=[0x2f011f0]
    void Open(wchar_t const *FileName, unsigned int a3, char *Str, int a5);

    // address=[0x2f012d0]
    unsigned int Read(void *Buffer, int ElementSize, int ElementCount, char *a5, int a6);

    // address=[0x2f01300]
    unsigned int Write(void const *a1, int a2, int a3, char *a4, int a5);

    // address=[0x2f01330]
    int Seek(int Offset, int Origin, char *a4, int a5);

    // address=[0x2f01380]
    virtual int Size(void) const;

    // address=[0x2f013e0]
    int Tell(char *a2, int a3) const;

    // address=[0x2f01400]
    int Eof(void);

    // address=[0x2f01420]
    int Error(void);

    // address=[0x2f01440]
    int Close(char *a2, int a3);

    // address=[0x2f016b0]
    class CFile &operator=(class CFile &a2);

    // address=[0x2f016f0]
    FILE *GetFile(void);

protected:
    // address=[0x2f014c0]
    void OpenMaskToCWStr(unsigned int a2, std::wstring &_spFileMode);

    // Type information members
public:
    std::string m_spName;
    BOOL m_bTextMode;
    std::string m_spU24;
    int m_uU40;
    FILE *m_hFile;

    enum Mode : char
    {
        CFile_TEXT = 0x1,
        CFile_BINARY = 0x2,
        CFile_READ = 0x4,
        CFile_WRITE = 0x8,
        CFile_SPECIAL = 0x10,
        CFile_APPEND = 0x20,
    };
};

#endif // CFILE_H
