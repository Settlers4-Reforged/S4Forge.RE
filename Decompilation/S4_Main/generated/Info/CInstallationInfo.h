#ifndef CINSTALLATIONINFO_H
#define CINSTALLATIONINFO_H

class CInstallationInfo : public IInstallationInfo {
public:
    // address=[0x1494e20]
    virtual unsigned int  GetConfigChecksum(void);

    // address=[0x1494e80]
    virtual unsigned int  GetScriptChecksum(void);

    // address=[0x1494eb0]
    virtual unsigned int  GetGfxChecksum(void);

    // address=[0x1494f40]
    virtual bool  CheckInstallation(int);

    // address=[0x1494ff0]
    virtual bool  IsOptionalGameConfigFile(wchar_t const *);

    // address=[0x1496860]
     CInstallationInfo(void);

    // address=[0x14968b0]
    virtual  ~CInstallationInfo(void);

protected:
    // address=[0x1495090]
    static bool __cdecl GetFileProperties(wchar_t const *,struct SFileProperties &);

    // address=[0x14951f0]
    static unsigned int __cdecl GetFileCRC(wchar_t const *,unsigned int);

    // address=[0x14953d0]
    static unsigned int __cdecl GetConfigFileCRC(wchar_t const *,unsigned int);

    // address=[0x1495480]
    static unsigned int __cdecl GetGfxFileCRC(int,unsigned int);

    // address=[0x1495620]
    static bool __cdecl CheckFile(wchar_t const *,int);

    // address=[0x1495730]
    static bool __cdecl CheckConfigFile(wchar_t const *,int);

    // address=[0x14957c0]
    static bool __cdecl CheckGfxFile(int,int);

    // address=[0x1495870]
    static bool __cdecl CheckConfigFiles(int);

    // address=[0x14958d0]
    static bool __cdecl CheckGfxFiles(int);

    // address=[0x1495930]
    void  CheckTrojanVehicleGfx(void);

    // address=[0x1495e70]
    static bool __cdecl CheckWithLuaScript(int);

    // address=[0x1495fd0]
    static void __cdecl LuaCheckFile(void);

    // address=[0x1496110]
    static void __cdecl LuaCheckFiles(void);

    // address=[0x1496980]
    static int __cdecl LuaGetInteger(unsigned int);

    // address=[0x14969d0]
    static int __cdecl LuaGetIntegerZeroIfNoObject(unsigned int);

    // address=[0x1496a10]
    static char const * __cdecl LuaGetString(unsigned int);

    // address=[0x3f456d8]
    static int m_iLuaCheckFlags;

    // address=[0x3f456dc]
    static bool m_bLuaCheckOk;

};


#endif // CINSTALLATIONINFO_H
