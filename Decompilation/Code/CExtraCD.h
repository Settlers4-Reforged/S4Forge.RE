#ifndef CEXTRACD_H
#define CEXTRACD_H

class CExtraCD : public IExtraCD {
public:
    // address=[0x1481700]
     CExtraCD(void);

    // address=[0x1481740]
    virtual  ~CExtraCD(void);

    // address=[0x14817a0]
    virtual bool  IsExtraInstalled(void);

    // address=[0x14817e0]
    virtual void  EnsureMainGUI(int,bool (__cdecl*)(int,int,int));

protected:
    // address=[0x1481810]
    void  EnsureGuiEngineHasGfxFileLoaded(unsigned int,void *,int,bool (__cdecl*)(int,int,int),bool);

    // address=[0x14818e0]
    static bool __cdecl ExistsFile(wchar_t const *);

    // address=[0x14819b0]
    static bool __cdecl ExistsFiles(wchar_t const * *);

    // address=[0x1481a00]
    void  LoadMenuData(wchar_t const *);

};


#endif // CEXTRACD_H
