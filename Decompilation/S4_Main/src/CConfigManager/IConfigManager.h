#ifndef ICONFIGMANAGER_H
#define ICONFIGMANAGER_H

#include "defines.h"
#include "Var/CConfigVar.h"

class IConfigManager {
public:
    // address=[0x2eef090]
    static class IConfigManager * __cdecl CreateConfigManger(void);

    // address=[0x2ef8840]
     IConfigManager(void);

    // address=[0x2ef8cd0]
    virtual  ~IConfigManager(void);

    // address=[0x2ef1390]
    virtual bool AddConfigFile(wchar_t const *a2) = 0;

    // address=[0x2ef13b0]
    virtual bool AddConfigFileEx(wchar_t const *FileName, char const *String2) = 0;

    // address=[0x2ef1470]
    virtual bool AddCommandLine(char const *groupName, int argc, char **const argv) = 0;

    // address=[0x2ef15c0]
    virtual int GetIntValue(char const *Str, char const *a3, int a4) = 0;

    // address=[0x2ef16d0]
    virtual int GetIntValueNoAdd(char const *Str, char const *a3, int a4) = 0;

    // address=[0x2ef17a0]
    virtual float GetFloatValue(char const *Str, char const *a3, float a4) = 0;

    // address=[0x2ef18b0]
    virtual float GetFloatValueNoAdd(char const *Str, char const *a3, float a4) = 0;

    // address=[0x2ef1990]
    virtual std::string GetStringValue(char const *arg0, char const *Str, std::string const &a4) = 0;

    // address=[0x2ef1ae0]
    virtual std::string GetStringValueNoAdd(char const *a2, char const *Str, std::string const &a4) = 0;

    // address=[0x2ef1c00]
    virtual CConfigVar *GetConfigVar(char const *Str, char const *a3) = 0;

    // address=[0x2ef1cc0]
    virtual void AddDefines(struct SConfigTypeString const *a2, int a3) = 0;

    // address=[0x2ef1d70]
    virtual int GetDefineValue(char const *_spDefineName) = 0;

    // address=[0x2ef1eb0]
    virtual void AddStaticConfigVar(char const *Str, char const *a3, CConfigVar &a4) = 0;

    // address=[0x2ef1f70]
    virtual bool SaveSection(char const *Str, wchar_t const *FileName) = 0;

    // address=[0x2ef2020]
    virtual int GetSectionEntryCount(char const *Str) = 0;

    // address=[0x2ef20b0]
    virtual bool DoesExist(char const *Str, char const *a3) = 0;

};


#endif // ICONFIGMANAGER_H
