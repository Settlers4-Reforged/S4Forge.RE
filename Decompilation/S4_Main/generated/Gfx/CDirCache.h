#ifndef CDIRCACHE_H
#define CDIRCACHE_H

#include "defines.h"

class CDirCache {
public:
    // address=[0x15d6690]
    void  Init(void);

    // address=[0x15d69a0]
    void  PushBack(int a2);

    // address=[0x15faff0]
    int  operator[](int a2);

    // address=[0x15fb1a0]
    int  Back(void)const;

    // address=[0x15fb1c0]
    int  Count(void)const;

    // address=[0x15fb520]
    void  PopBack(void);

private:
    // address=[0x15d6600]
    static unsigned char __cdecl IncWrap(unsigned char a1);

    // address=[0x15fb1e0]
    static unsigned char __cdecl DecWrap(unsigned char a1);

};


#endif // CDIRCACHE_H
