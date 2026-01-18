#ifndef CDEBUGFKT_H
#define CDEBUGFKT_H

#include "defines.h"

class CDebugFkt {
public:
    // address=[0x134f2a0]
    static bool __cdecl SetDebugFuncKey(char const * String2, char a2);

    // address=[0x134f330]
    static int (__cdecl*__cdecl SelectDebugFunc(char))(int a1, int a2);

    // address=[0x134f540]
    static char * __cdecl DebugString(void);

    // address=[0x134f550]
    static void __cdecl SetDebugString(class String const & a1);

    // address=[0x134f570]
    static void __cdecl SetFrameCounter(float a1, float a2, float a3, float a4, float a5, float a6, float a7, unsigned int a8);

private:
    // address=[0x3f4558c]
    static class String m_sInfoText;

    // address=[0x3f455a8]
    static class String m_sFrame;

    // address=[0x3f455c4]
    static class String m_sInfo;

};


#endif // CDEBUGFKT_H
