#ifndef CCONFIGMANAGER_H
#define CCONFIGMANAGER_H

#include "defines.h"

class CConfigManager : public IConfigManager {
public:
    // address=[0x2ef1280]
    virtual  ~CConfigManager(void);

    // address=[0x2ef1390]
    virtual bool  AddConfigFile(wchar_t const * a2);

    // address=[0x2ef13b0]
    virtual bool  AddConfigFileEx(wchar_t const * FileName, char const * String2);

    // address=[0x2ef1470]
    virtual bool  AddCommandLine(char const * groupName, int argc, char * * const argv);

    // address=[0x2ef15c0]
    virtual int  GetIntValue(char const * Str, char const * a3, int a4);

    // address=[0x2ef16d0]
    virtual int  GetIntValueNoAdd(char const * Str, char const * a3, int a4);

    // address=[0x2ef17a0]
    virtual float  GetFloatValue(char const * Str, char const * a3, float a4);

    // address=[0x2ef18b0]
    virtual float  GetFloatValueNoAdd(char const * Str, char const * a3, float a4);

    // address=[0x2ef1990]
    virtual std::string  GetStringValue(char const * a2, char const * Str, std::string const & a4);

    // address=[0x2ef1ae0]
    virtual std::string  GetStringValueNoAdd(char const * a2, char const * Str, std::string const & a4);

    // address=[0x2ef1c00]
    virtual class CConfigVar *  GetConfigVar(char const * Str, char const * a3);

    // address=[0x2ef1cc0]
    virtual void  AddDefines(struct SConfigTypeString const * a2, int a3);

    // address=[0x2ef1d70]
    virtual int  GetDefineValue(char const * Str);

    // address=[0x2ef1eb0]
    virtual void  AddStaticConfigVar(char const * Str, char const * a3, class CConfigVar & a4);

    // address=[0x2ef1f70]
    virtual bool  SaveSection(char const * Str, wchar_t const * FileName);

    // address=[0x2ef2020]
    virtual int  GetSectionEntryCount(char const * Str);

    // address=[0x2ef20b0]
    virtual bool  DoesExist(char const * Str, char const * a3);

    // address=[0x2ef8610]
     CConfigManager(void);

protected:
    // address=[0x2eefee0]
    bool  ParseData(char * a2, int a3);

    // address=[0x2eeffe0]
    bool  Parse(class CConfigFile * a2, char const * String2);

    // address=[0x2ef0120]
    std::string  ParseFindSection(char * a1, int & a2, int const & a3);

    // address=[0x2ef0270]
    void  ParseAddSectionVars(class CConfigSection * a2, char * a3, int & a4, int const & a5);

    // address=[0x2ef07d0]
    std::string  ParseGetLine(char * a1, int & a2, int const & a3);

    // address=[0x2ef0960]
    enum T_CFGVAR_TYPE  ParseGetVar(std::string & a1, std::string & a2, std::string & a3);

    // address=[0x2ef0ea0]
    void  ParseGetArrayVars(std::string & a2, int * a3, int & a4, int & a5);

    // address=[0x2ef1010]
    int  ParseGetDefineVar(std::string & a2);

    // address=[0x2ef1090]
    void  AddDefineVar(std::string const & a1, int a2);

    // address=[0x2ef10c0]
    class CConfigSection *  GetSection(std::string const & a2, bool a3);

};


#endif // CCONFIGMANAGER_H
