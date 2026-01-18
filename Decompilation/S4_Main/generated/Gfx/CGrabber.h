#ifndef CGRABBER_H
#define CGRABBER_H

#include "defines.h"

class CGrabber {
public:
    // address=[0x14944f0]
    static void __cdecl DoGrab(std::wstring a1);

    // address=[0x14947b0]
    static void * __cdecl GetScreenBits(void * lpvBits, void * a2, int * a3, int * a4, int a5, bool a6);

};


#endif // CGRABBER_H
