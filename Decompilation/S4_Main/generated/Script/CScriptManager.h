#ifndef CSCRIPTMANAGER_H
#define CSCRIPTMANAGER_H

#include "defines.h"

class CScriptManager {
public:
    // address=[0x1601e00]
    void  AllowRegisterFunction(bool a2);

    // address=[0x1601e50]
    void  Call(int a2);

    // address=[0x1601ec0]
    void  Call(int a2, int a3);

    // address=[0x1601f40]
    void  Call(int a2, int a3, int a4);

    // address=[0x1601fe0]
    void  Call(int a2, int a3, int a4, int a5);

    // address=[0x1602090]
    void  Call(int a2, int a3, int a4, int a5, int a6);

    // address=[0x160deb0]
     CScriptManager(class CLua & a2);

    // address=[0x160df40]
    virtual  ~CScriptManager(void);

    // address=[0x160df60]
    int  FindFunc(unsigned int a2);

private:
    // address=[0x160dff0]
    void  RegisterFunction(void);

    // address=[0x160e140]
    static void __cdecl LuaRegisterFunction(void);

    // address=[0x462b870]
    static class CScriptManager * m_pScriptManager;

};


#endif // CSCRIPTMANAGER_H
