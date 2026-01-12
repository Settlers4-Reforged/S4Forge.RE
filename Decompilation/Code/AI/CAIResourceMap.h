#ifndef CAIRESOURCEMAP_H
#define CAIRESOURCEMAP_H

class CAIResourceMap {
public:
    // address=[0x131a8e0]
    static bool __cdecl IsOfLandtype(enum T_RESOURCE_LANDTYPE,int,int);

    // address=[0x131abe0]
    static int __cdecl GetNumberOfSquaresWithDarkLand(int);

    // address=[0x131ca20]
    static class CAIResourceData const & __cdecl ResourceDataVW(int,int);

    // address=[0x1321c10]
    static class CAIResourceData const & __cdecl ResourceDataXY(int,int);

protected:
    // address=[0x131acf0]
    static void __cdecl Init(void);

    // address=[0x131af30]
    static void __cdecl Done(void);

    // address=[0x131af40]
    static void __cdecl Update(void);

    // address=[0x131b070]
    static void __cdecl NotifyChange(int,int);

    // address=[0x131b190]
    static void __cdecl NotifyResourceChange(int,int,int,int);

    // address=[0x131b420]
    static void __cdecl NotifyDarkLandChange(int,int,bool);

private:
    // address=[0x3e97784]
    static int s_iInitialized;

    // address=[0x3e97788]
    static class CAIResourceData (* m_cData)[64];

};


#endif // CAIRESOURCEMAP_H
