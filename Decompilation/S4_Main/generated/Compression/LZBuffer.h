#ifndef LZBUFFER_H
#define LZBUFFER_H

#include "defines.h"

class LZBuffer {
protected:
    // address=[0x2f2a330]
     LZBuffer(void);

    // address=[0x2f2a400]
     ~LZBuffer(void);

    // address=[0x2f2a4a0]
    static int __cdecl _distance(int a1);

    // address=[0x2f2a4b0]
    int  _nMatch(int a2, unsigned char const * a3, int a4);

    // address=[0x2f2a640]
    void  _toBuf(unsigned char a2);

    // address=[0x2f2a690]
    void  _toBuf(unsigned char const * Src, unsigned int a3);

    // address=[0x2f2a920]
    static int __cdecl _wrap(unsigned long a1);

    // address=[0x2f2c400]
    void  _bufCpy(unsigned char * a2, int a3, unsigned int a4);

};


#endif // LZBUFFER_H
