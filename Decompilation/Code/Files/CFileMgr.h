#ifndef CFILEMGR_H
#define CFILEMGR_H

class CFileMgr {
public:
    // address=[0x2f28a80]
     CFileMgr(void);

    // address=[0x2f28be0]
    static struct _iobuf * __cdecl Open(wchar_t const *,wchar_t const *,char *,int);

    // address=[0x2f28cd0]
    static void __cdecl RemoveFromList(struct SFileDesc *);

    // address=[0x2f28d40]
    static struct SFileDesc * __cdecl CheckValidFilePtr(struct _iobuf *,char *,char *,int);

    // address=[0x2f28da0]
    static void __cdecl ReportOpenFiles(void);

private:
    // address=[0x2f28f30]
    static void __cdecl CheckOpenMode(int,int,char *,wchar_t const *,wchar_t const *,int *);

    // address=[0x2f290d0]
    static struct SFileDesc * __cdecl AddNewFileDesc(struct _iobuf *,int,int,char const *,wchar_t const *,wchar_t const *,int);

    // address=[0x2f291c0]
    static void __cdecl DisposeNode(struct SFileDesc *);

    // address=[0x2f29240]
    static struct SFileDesc * __cdecl IsFileOpen(wchar_t const *);

    // address=[0x2f29290]
    static struct SFileDesc * __cdecl LookupFilePtr(struct _iobuf *);

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
