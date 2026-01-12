#ifndef CGUIWRAPPER_H
#define CGUIWRAPPER_H

class CGUIWrapper {
public:
    // address=[0x13d8780]
    static class CGUIWrapper * __cdecl GetInstance(void);

    // address=[0x13d8810]
    void  ReleaseGUIGFXFile(void);

    // address=[0x13d8830]
    bool  RebuildGuiEngineWithGfxFile(unsigned int,void *,int,bool (__cdecl*)(int,int,int));

    // address=[0x13d8a20]
    unsigned int  GetActiveGUIGFXFile(void);

private:
    // address=[0x13d8a50]
     CGUIWrapper(void);

};


#endif // CGUIWRAPPER_H
