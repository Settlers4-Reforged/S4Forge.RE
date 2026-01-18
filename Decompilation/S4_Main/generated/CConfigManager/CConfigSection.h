#ifndef CCONFIGSECTION_H
#define CCONFIGSECTION_H

#include "defines.h"

class CConfigSection {
public:
    // address=[0x2eef260]
     CConfigSection(std::string const & a2);

    // address=[0x2eef2d0]
     ~CConfigSection(void);

    // address=[0x2eef3f0]
    bool  VarExists(std::string const & a2);

    // address=[0x2eef490]
    void  AddVar(std::string const & a2, int const * Src, int a4);

    // address=[0x2eef600]
    void  AddVar(std::string const & a2, int a3);

    // address=[0x2eef6d0]
    void  AddVar(std::string const & a2, float a3);

    // address=[0x2eef7b0]
    void  AddVar(std::string const & a2, std::string const & a3);

    // address=[0x2eef880]
    void  AddStaticConfigVar(std::string const & a2, class CConfigVar & a3);

    // address=[0x2eef8e0]
    bool  Save(wchar_t const * FileName);

    // address=[0x2efa130]
    class CConfigVar *  GetVar(std::string const & a2);

    // address=[0x2efa250]
    std::string const &  Name(void);

    // address=[0x2efa270]
    int  NumberOfEntries(void);

};


#endif // CCONFIGSECTION_H
