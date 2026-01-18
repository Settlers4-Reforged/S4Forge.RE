#ifndef CAIRESOURCEMAP_H
#define CAIRESOURCEMAP_H

#include "defines.h"

class CAIResourceMap {
public:
    // address=[0x131a8e0]
    static bool __cdecl IsOfLandtype(enum T_RESOURCE_LANDTYPE a1, int a2, int a3);

    // address=[0x131abe0]
    static int __cdecl GetNumberOfSquaresWithDarkLand(int a1);

    // address=[0x131ca20]
    static class CAIResourceData const & __cdecl ResourceDataVW(int a1, int a2);

    // address=[0x1321c10]
    static class CAIResourceData const & __cdecl ResourceDataXY(int a1, int a2);

protected:
    // address=[0x131acf0]
    static void __cdecl Init(void);

    // address=[0x131af30]
    static void __cdecl Done(void);

    // address=[0x131af40]
    static void __cdecl Update(void);

    // address=[0x131b070]
    static void __cdecl NotifyChange(int a1, int a2);

    // address=[0x131b190]
    static void __cdecl NotifyResourceChange(int a1, int a2, int a3, int a4);

    // address=[0x131b420]
    static void __cdecl NotifyDarkLandChange(int a1, int a2, bool a3);

private:
    // address=[0x3e97784]
    static int s_iInitialized;

    // address=[0x3e97788]
    static class CAIResourceData (* m_cData)[64];

};


#endif // CAIRESOURCEMAP_H
