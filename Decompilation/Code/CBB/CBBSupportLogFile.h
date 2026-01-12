#ifndef CBBSUPPORTLOGFILE_H
#define CBBSUPPORTLOGFILE_H

class CBBSupportLogFile {
public:
    // address=[0x2f2fa50]
    bool __stdcall IsOpen(void);

    // address=[0x2f33df0]
     CBBSupportLogFile(void);

    // address=[0x2f33e50]
    virtual  ~CBBSupportLogFile(void);

    // address=[0x2f33ea0]
    virtual void __stdcall SetFileMode(int);

    // address=[0x2f33ee0]
    virtual void __stdcall SetFilePath(wchar_t const *);

    // address=[0x2f33f50]
    virtual void __stdcall SetFileModePathAndCreateOrDeleteIfDesired(int,wchar_t const *);

    // address=[0x2f33fc0]
    virtual void __stdcall Write(void const *,unsigned int);

    // address=[0x2f34050]
    virtual void __stdcall Print(char const *);

    // address=[0x2f340a0]
    virtual void __cdecl PrintF(char const *,...);

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
    virtual bool __stdcall GetFilePath(wchar_t *,unsigned int);

    // address=[0x2f34670]
    bool __stdcall OpenIfNecessary(void);

};


#endif // CBBSUPPORTLOGFILE_H
