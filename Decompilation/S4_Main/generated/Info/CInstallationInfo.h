#ifndef CINSTALLATIONINFO_H
#define CINSTALLATIONINFO_H

#include "defines.h"

class CInstallationInfo : public IInstallationInfo {
public:
    // address=[0x1494e20]
    virtual unsigned int  GetConfigChecksum(void);

    // address=[0x1494e80]
    virtual unsigned int  GetScriptChecksum(void);

    // address=[0x1494eb0]
    virtual unsigned int  GetGfxChecksum(void);

    // address=[0x1494f40]
    virtual bool  CheckInstallation(int a2);

    // address=[0x1494ff0]
    virtual bool  IsOptionalGameConfigFile(wchar_t const * String2);

    // address=[0x1496860]
     CInstallationInfo(void);

    // address=[0x14968b0]
    virtual  ~CInstallationInfo(void);

protected:
    // address=[0x1495090]
    static bool __cdecl GetFileProperties(wchar_t const * String, struct SFileProperties & a2);

    // address=[0x14951f0]
    static unsigned int __cdecl GetFileCRC(wchar_t const * FileName, unsigned int a2);

    // address=[0x14953d0]
    static unsigned int __cdecl GetConfigFileCRC(wchar_t const * String, unsigned int a2);

    // address=[0x1495480]
    static unsigned int __cdecl GetGfxFileCRC(int a1, unsigned int a2);

    // address=[0x1495620]
    static bool __cdecl CheckFile(wchar_t const * a1, int a2);

    // address=[0x1495730]
    static bool __cdecl CheckConfigFile(wchar_t const * String, int a2);

    // address=[0x14957c0]
    static bool __cdecl CheckGfxFile(int a1, int a2);

    // address=[0x1495870]
    static bool __cdecl CheckConfigFiles(int a1);

    // address=[0x14958d0]
    static bool __cdecl CheckGfxFiles(int a1);

    // address=[0x1495930]
    void  CheckTrojanVehicleGfx(void);

    // address=[0x1495e70]
    static bool __cdecl CheckWithLuaScript(int a1);

    // address=[0x1495fd0]
    static void __cdecl LuaCheckFile(void);

    // address=[0x1496110]
    static void __cdecl LuaCheckFiles(void);

    // address=[0x1496980]
    static int __cdecl LuaGetInteger(unsigned int a1);

    // address=[0x14969d0]
    static int __cdecl LuaGetIntegerZeroIfNoObject(unsigned int a1);

    // address=[0x1496a10]
    static char const * __cdecl LuaGetString(unsigned int a1);

    // address=[0x3f456d8]
    static int m_iLuaCheckFlags;

    // address=[0x3f456dc]
    static bool m_bLuaCheckOk;

};


#endif // CINSTALLATIONINFO_H
