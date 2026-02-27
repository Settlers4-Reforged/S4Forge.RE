#ifndef IINSTALLATIONINFO_H
#define IINSTALLATIONINFO_H

#include "defines.h"

class IInstallationInfo {
public:
    // address=[0x1496890]
     IInstallationInfo(void);

    // address=[0x14968d0]
    virtual  ~IInstallationInfo(void);

    // address=[0x1494e20]
    virtual unsigned int  GetConfigChecksum(void) = 0;

    // address=[0x1494e80]
    virtual unsigned int  GetScriptChecksum(void) = 0;

    // address=[0x1494eb0]
    virtual unsigned int  GetGfxChecksum(void) = 0;

    // address=[0x1494f40]
    virtual bool  CheckInstallation(int a2) = 0;

    // address=[0x1494ff0]
    virtual bool  IsOptionalGameConfigFile(wchar_t const * String2) = 0;
};


#endif // IINSTALLATIONINFO_H
