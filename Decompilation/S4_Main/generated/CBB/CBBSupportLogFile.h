#ifndef CBBSUPPORTLOGFILE_H
#define CBBSUPPORTLOGFILE_H

#include "defines.h"

class CBBSupportLogFile {
public:
    // address=[0x2f2fa50]
    bool __stdcall IsOpen(void);

    // address=[0x2f33df0]
     CBBSupportLogFile(void);

    // address=[0x2f33e50]
    virtual  ~CBBSupportLogFile(void);

    // address=[0x2f33ea0]
    virtual void __stdcall SetFileMode(int a2);

    // address=[0x2f33ee0]
    virtual void __stdcall SetFilePath(wchar_t const * a2);

    // address=[0x2f33f50]
    virtual void __stdcall SetFileModePathAndCreateOrDeleteIfDesired(int ecx0, wchar_t const * this);

    // address=[0x2f33fc0]
    virtual void __stdcall Write(void const * a1, unsigned int lpBuffer);

    // address=[0x2f34050]
    virtual void __stdcall Print(char const * a2);

    // address=[0x2f340a0]
    virtual void __cdecl PrintF(char const * a1, ... a2);

    // address=[0x2f34190]
    virtual void __cdecl PrintNewLine(void);

    // address=[0x2f341c0]
    virtual void __stdcall Flush(void);

    // address=[0x2f34200]
    virtual void __stdcall Open(void);

    // address=[0x2f34340]
    virtual void __stdcall Delete(void);

    // address=[0x2f34370]
    virtual void __stdcall Close(void);

    // address=[0x2f343e0]
    virtual bool __stdcall GetFilePath(wchar_t * a2, unsigned int a3);

    // address=[0x2f34670]
    bool __stdcall OpenIfNecessary(void);

};


#endif // CBBSUPPORTLOGFILE_H
