#ifndef CEXTRACD_H
#define CEXTRACD_H

#include "defines.h"

class CExtraCD : public IExtraCD {
public:
    // address=[0x1481700]
     CExtraCD(void);

    // address=[0x1481740]
    virtual  ~CExtraCD(void);

    // address=[0x14817a0]
    virtual bool  IsExtraInstalled(void);

    // address=[0x14817e0]
    virtual void  EnsureMainGUI(int a2, bool (__cdecl*)(int,int,int) a3);

protected:
    // address=[0x1481810]
    void  EnsureGuiEngineHasGfxFileLoaded(unsigned int a2, void * a3, int a4, bool (__cdecl*)(int,int,int) a5, bool a6);

    // address=[0x14818e0]
    static bool __cdecl ExistsFile(wchar_t const * FileName);

    // address=[0x14819b0]
    static bool __cdecl ExistsFiles(wchar_t const * * a1);

    // address=[0x1481a00]
    void  LoadMenuData(wchar_t const * FileName);

};


#endif // CEXTRACD_H
