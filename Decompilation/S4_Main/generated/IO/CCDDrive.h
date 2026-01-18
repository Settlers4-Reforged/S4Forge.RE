#ifndef CCDDRIVE_H
#define CCDDRIVE_H

#include "defines.h"

class CCDDrive : public ICDDrive {
public:
    // address=[0x147e9f0]
     CCDDrive(void);

    // address=[0x147eb30]
    virtual enum T_S4_CDROM_TYPE  GetCDType(char a2);

    // address=[0x147ec40]
    virtual char  GetCDDrive(enum T_S4_CDROM_TYPE a2);

    // address=[0x147ed00]
    virtual bool  GetCDPath(std::wstring & a2, wchar_t const * lpFileName, int a4);

protected:
    // address=[0x147ea30]
    static bool __cdecl FindFile(wchar_t const * lpFileName);

    // address=[0x147eab0]
    unsigned int  GetDriveTypeA(char a2);

    // address=[0x147f1f0]
    static bool __cdecl AreCDTypesMatching(enum T_S4_CDROM_TYPE a1, enum T_S4_CDROM_TYPE a2);

private:
    // address=[0x147eb20]
    int  DriveTypeExCheck(void);

};


#endif // CCDDRIVE_H
