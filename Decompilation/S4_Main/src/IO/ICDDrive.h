#ifndef ICDDRIVE_H
#define ICDDRIVE_H

#include "defines.h"

enum T_S4_CDROM_TYPE
{
    S4_CDROM_TYPE_UNKNOWN = 0,
    S4_CDROM_TYPE_UNKNOWN2 = 1,
    S4_CDROM_TYPE_CD1 = 2, // s4cd1.dat
    S4_CDROM_TYPE_X1_CD1 = 3, // s4x1cd1.dat
    S4_CDROM_TYPE_X2_CD1 = 4, // s4x2cd1.dat
    S4_CDROM_TYPE_GOLD_CD2 = 5, // s4gcd2.dat
    S4_CDROM_TYPE_X3_CD1 = 6, // s4x3cd1.dat
    S4_CDROM_TYPE_P_CD2 = 7, // s4pcd2.dat
    S4_CDROM_TYPE_X4_CD1 = 8, // s4x4cd1.dat
};

class ICDDrive {
public:
    // address=[0x147f1d0]
     ICDDrive(void);

    virtual enum T_S4_CDROM_TYPE  GetCDType(char a2) = 0;

    virtual char  GetCDDrive(enum T_S4_CDROM_TYPE a2) = 0;

    virtual bool  GetCDPath(std::wstring & a2, wchar_t const * lpFileName, int a4) = 0;
};

#endif // ICDDRIVE_H
