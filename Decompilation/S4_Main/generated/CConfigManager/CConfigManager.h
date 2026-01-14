#ifndef CCONFIGMANAGER_H
#define CCONFIGMANAGER_H

class CConfigManager : public IConfigManager {
public:
    // address=[0x2ef1280]
    virtual  ~CConfigManager(void);

    // address=[0x2ef1390]
    virtual bool  AddConfigFile(wchar_t const *);

    // address=[0x2ef13b0]
    virtual bool  AddConfigFileEx(wchar_t const *,char const *);

    // address=[0x2ef1470]
    virtual bool  AddCommandLine(char const *,int,char * * const);

    // address=[0x2ef15c0]
    virtual int  GetIntValue(char const *,char const *,int);

    // address=[0x2ef16d0]
    virtual int  GetIntValueNoAdd(char const *,char const *,int);

    // address=[0x2ef17a0]
    virtual float  GetFloatValue(char const *,char const *,float);

    // address=[0x2ef18b0]
    virtual float  GetFloatValueNoAdd(char const *,char const *,float);

    // address=[0x2ef1990]
    virtual std::string  GetStringValue(char const *,char const *,std::string const &);

    // address=[0x2ef1ae0]
    virtual std::string  GetStringValueNoAdd(char const *,char const *,std::string const &);

    // address=[0x2ef1c00]
    virtual class CConfigVar *  GetConfigVar(char const *,char const *);

    // address=[0x2ef1cc0]
    virtual void  AddDefines(struct SConfigTypeString const *,int);

    // address=[0x2ef1d70]
    virtual int  GetDefineValue(char const *);

    // address=[0x2ef1eb0]
    virtual void  AddStaticConfigVar(char const *,char const *,class CConfigVar &);

    // address=[0x2ef1f70]
    virtual bool  SaveSection(char const *,wchar_t const *);

    // address=[0x2ef2020]
    virtual int  GetSectionEntryCount(char const *);

    // address=[0x2ef20b0]
    virtual bool  DoesExist(char const *,char const *);

    // address=[0x2ef8610]
     CConfigManager(void);

protected:
    // address=[0x2eefee0]
    bool  ParseData(char *,int);

    // address=[0x2eeffe0]
    bool  Parse(class CConfigFile *,char const *);

    // address=[0x2ef0120]
    std::string  ParseFindSection(char *,int &,int const &);

    // address=[0x2ef0270]
    void  ParseAddSectionVars(class CConfigSection *,char *,int &,int const &);

    // address=[0x2ef07d0]
    std::string  ParseGetLine(char *,int &,int const &);

    // address=[0x2ef0960]
    enum T_CFGVAR_TYPE  ParseGetVar(std::string &,std::string &,std::string &);

    // address=[0x2ef0ea0]
    void  ParseGetArrayVars(std::string &,int *,int &,int &);

    // address=[0x2ef1010]
    int  ParseGetDefineVar(std::string &);

    // address=[0x2ef1090]
    void  AddDefineVar(std::string const &,int);

    // address=[0x2ef10c0]
    class CConfigSection *  GetSection(std::string const &,bool);

};


#endif // CCONFIGMANAGER_H
