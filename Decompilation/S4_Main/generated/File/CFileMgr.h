#ifndef CFILEMGR_H
#define CFILEMGR_H

#include "defines.h"

class CFileMgr {
public:
    // address=[0x2f28a80]
     CFileMgr(void);

    // address=[0x2f28be0]
    static struct _iobuf * __cdecl Open(wchar_t const * FileName, wchar_t const * Mode, char * Str, int a4);

    // address=[0x2f28cd0]
    static void __cdecl RemoveFromList(struct SFileDesc * a1);

    // address=[0x2f28d40]
    static struct SFileDesc * __cdecl CheckValidFilePtr(struct _iobuf * a1, char * a2, char * a3, int a4);

    // address=[0x2f28da0]
    static void __cdecl ReportOpenFiles(void);

private:
    // address=[0x2f28f30]
    static void __cdecl CheckOpenMode(int a1, int a2, char * a3, wchar_t const * a4, wchar_t const * String2, int * a6);

    // address=[0x2f290d0]
    static struct SFileDesc * __cdecl AddNewFileDesc(struct _iobuf * a1, int a2, int a3, char const * Str, wchar_t const * String, wchar_t const * a6, int a7);

    // address=[0x2f291c0]
    static void __cdecl DisposeNode(struct SFileDesc * a1);

    // address=[0x2f29240]
    static struct SFileDesc * __cdecl IsFileOpen(wchar_t const * String2);

    // address=[0x2f29290]
    static struct SFileDesc * __cdecl LookupFilePtr(struct _iobuf * a1);

    // address=[0x3e2d2b0]
    static char * * fnames;

    // address=[0x3e2d2c4]
    static int m_iOpenFiles;

    // address=[0x3e2d2c8]
    static struct SModes * CFileMgr::m_sModes;

    // address=[0x46857b0]
    static struct SFileDesc * m_vFileDesc;

};


#endif // CFILEMGR_H
