#ifndef BBSUPPORTLIB_CBBSUPPORTTRACEFILE_H
#define BBSUPPORTLIB_CBBSUPPORTTRACEFILE_H

#include "defines.h"

namespace BBSupportLib {

class CBBSupportTraceFile {
public:
    // address=[0x2f2ee90]
     CBBSupportTraceFile(void);

    // address=[0x2f2f020]
    virtual  ~CBBSupportTraceFile(void);

    // address=[0x2f2f090]
    virtual void __stdcall SetFilePath(wchar_t const * a2);

    // address=[0x2f2f0d0]
    virtual void __stdcall PrintTime(void);

    // address=[0x2f2f150]
    virtual void __stdcall Open(void);

    // address=[0x2f2f1e0]
    virtual void __stdcall Close(void);

};

} // namespace BBSupportLib

#endif // BBSUPPORTLIB_CBBSUPPORTTRACEFILE_H
