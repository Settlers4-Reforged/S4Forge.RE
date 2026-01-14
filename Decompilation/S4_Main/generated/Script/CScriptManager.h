#ifndef CSCRIPTMANAGER_H
#define CSCRIPTMANAGER_H

class CScriptManager {
public:
    // address=[0x1601e00]
    void  AllowRegisterFunction(bool);

    // address=[0x1601e50]
    void  Call(int);

    // address=[0x1601ec0]
    void  Call(int,int);

    // address=[0x1601f40]
    void  Call(int,int,int);

    // address=[0x1601fe0]
    void  Call(int,int,int,int);

    // address=[0x1602090]
    void  Call(int,int,int,int,int);

    // address=[0x160deb0]
     CScriptManager(class CLua &);

    // address=[0x160df40]
    virtual  ~CScriptManager(void);

    // address=[0x160df60]
    int  FindFunc(unsigned int);

private:
    // address=[0x160dff0]
    void  RegisterFunction(void);

    // address=[0x160e140]
    static void __cdecl LuaRegisterFunction(void);

    // address=[0x462b870]
    static class CScriptManager * m_pScriptManager;

};


#endif // CSCRIPTMANAGER_H
